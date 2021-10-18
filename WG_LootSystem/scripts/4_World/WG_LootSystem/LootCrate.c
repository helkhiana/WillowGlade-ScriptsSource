class WG_LootCrate_Base : ItemBase 
{    
	int m_SpawnedUnixTime = -1;		
	int m_TimeBetweenActions = 30;
	bool m_IsSearched = false;
	int m_MaxLifetime = 180;
	int m_MaxLifetimeInteraction = 120;
    
	void WG_LootCrate_Base()
	{
		RegisterNetSyncVariableBool("m_IsSearched");
	}

    override void EEInit()
	{
		super.EEInit();		
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
		if(GetGame().IsServer())
		{
			m_SpawnedUnixTime = JMDate.Now(false).GetTimestamp();
			m_MaxLifetime = g_Game.GetWG_LS_Config().Get_MaxLifetimeForCrateType(GetType());
			m_MaxLifetimeInteraction = g_Game.GetWG_LS_Config().Get_MaxLifetimeInteractionForCrateType(GetType());
		}
	}
	
	override void EEDelete(EntityAI parent)
	{
		WG_LS_Manager plugin = WG_LS_Manager.Cast(GetPlugin(WG_LS_Manager));
		plugin.RemoveEntity(this);
		super.EEDelete(parent);
	}

    //Server call only
	void ResetInteraction()
	{
		m_SpawnedUnixTime = JMDate.Now(false).GetTimestamp();
		m_IsSearched = true;
        SetSynchDirty();
	}

    //Client call as well
    bool CanSearch()
    {
        return !m_IsSearched;
    }
	
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );		
		ctx.Write( m_IsSearched );	
		ctx.Write( m_SpawnedUnixTime );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		if (!ctx.Read( m_IsSearched ) )
			m_IsSearched = false;
		if (!ctx.Read(m_SpawnedUnixTime))
			m_SpawnedUnixTime = JMDate.Now(false).GetTimestamp();

		return true;
	}

	override void OnCEUpdate()
	{
		super.OnCEUpdate();
		if(m_SpawnedUnixTime == -1)
			m_SpawnedUnixTime = JMDate.Now(false).GetTimestamp();

		int deltaInSeconds = JMDate.Now(false).GetTimestamp() - m_SpawnedUnixTime;
		if(deltaInSeconds > m_MaxLifetimeInteraction && m_IsSearched)
			Delete();
		if(deltaInSeconds > m_MaxLifetime && !m_IsSearched)
			Delete();
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionWGSearchForLoot);
    }
};