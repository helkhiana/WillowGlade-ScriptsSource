modded class PlayerBase
{
    protected float m_PlayerWatchTick = 1;
    override void EEItemAttached(EntityAI item, string slot_name)
	{
        super.EEItemAttached(item, slot_name);
        if(item.IsKindOf("WG_WristWatch_ColorBase"))//check for battery
            CheckAndSetWatch(true);
    }
    
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
        if(item.IsKindOf("WG_WristWatch_ColorBase"))//check for battery
            CheckAndSetWatch(false);
    }

	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);        
        m_PlayerWatchTick += deltaTime;
		if(m_PlayerWatchTick < 30)
			return;
        m_PlayerWatchTick = 0;
        DoubleCheckItHasWatch();		
	}

    void DoubleCheckItHasWatch()
    {
        EntityAI watch = FindAttachmentBySlotName("Armband");
        if(watch && watch.IsKindOf("WG_WristWatch_ColorBase"))
        {
            CheckAndSetWatch(true);
        }
        else
        {
            CheckAndSetWatch(false);
        }
    }

    void CheckAndSetWatch(bool show = true)
    {        
        if(GetGame().IsClient() && m_ModulePlayerStatus)
        {
            m_ModulePlayerStatus.ToggleClockLayout(show);
            if(!show)
                return;
            int year, month, day, hour, minute;
			GetGame().GetWorld().GetDate( year, month, day, hour, minute );
            string shour,sminute;
            if(hour < 10)
                shour = "0" + hour.ToString();
            else
                shour = hour.ToString();
            if(minute < 10)
                sminute = "0" + minute.ToString();
            else
                sminute = minute.ToString();
            m_ModulePlayerStatus.SetClockTime(shour + ":" + sminute);
        }
    }
}