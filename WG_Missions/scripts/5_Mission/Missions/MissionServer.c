modded class MissionServer
{
    private ref MissionStorageHandler m_MissionStorage;

    void MissionServer()
    {
        GetRPCManager().AddRPC("WG_Events", "GetServerMissionsProgress", this, SingeplayerExecutionType.Server);
        GetRPCManager().AddRPC("WG_Events", "SaveServerMissionsProgress", this, SingeplayerExecutionType.Server);
        GetRPCManager().AddRPC("WG_Events", "SaveServerVehicleMissionsProgress", this, SingeplayerExecutionType.Server);
    }

    override void OnInit()
    {
        super.OnInit();
        m_MissionStorage = new MissionStorageHandler;
        g_Game.Set_MissionStorageHandler(m_MissionStorage);
    }
    
    void GetServerMissionsProgress(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type == CallType.Server && sender != null)
        {
            Print("[WG_Events] " + sender.GetName() + " connected");
            WG_MissionsData missionProgress;
            if(!m_MissionStorage.GetPlayerMissionProgress(sender.GetPlainId(), missionProgress))
            {
                Print("[WG_Events] couldn't find mission progress. Trying to make new");
                missionProgress = new WG_MissionsData(sender.GetId().Hash(), sender.GetPlainId(), sender.GetName());
                m_MissionStorage.Save(missionProgress);
            }
            Print("[WG_Events] got missionProgress: " + missionProgress);
            
            GetRPCManager().SendRPC("WG_Events", "SetClientMissionsProgress", new Param1<ref WG_MissionsData>( missionProgress ), true, sender);
        }
    }

	void SaveServerMissionsProgress(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        ref Param1<ref WG_Mission> data;
        if (type == CallType.Server)
		{
			if (!ctx.Read(data)) return;
            Print("[WG_Events] Saving mission progress: " + sender.GetName());
			m_MissionStorage.Update(data.param1, sender.GetPlainId());
		}
    }
  
	void SaveServerVehicleMissionsProgress(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        ref Param1<ref WG_VehicleMission> data;
        if (type == CallType.Server)
		{
			if (!ctx.Read(data)) return;
            Print("[WG_Events] Saving mission progress: " + sender.GetName());
			m_MissionStorage.UpdateVehicleMissionsData(data.param1, sender.GetPlainId());
		}
    }
};