modded class DayZGame
{
    private ref MissionStorageHandler m_MissionStorageHandler;
    private ref WG_MissionsData m_MissionData;

    ref MissionStorageHandler Get_MissionStorageHandler()
    {
        if (!m_MissionStorageHandler)
        {
            Set_MissionStorageHandler(new MissionStorageHandler);
        }
	    return m_MissionStorageHandler;
    }

    void Set_MissionStorageHandler(MissionStorageHandler config)
	{
		m_MissionStorageHandler = config;
	}

    //client only
    void Set_ClientMissionsProgress(WG_MissionsData mission)
    {
        if(!GetGame().IsClient())
        {
            Print("ERROR: Set_ClientMissionsProgress can only be called on client");
            return;
        }
        m_MissionData = mission;
    }
    
    ref WG_MissionsData Get_ClientMissionsProgress()
    {
        if(!GetGame().IsClient())
        {
            Print("ERROR: Get_ClientMissionsProgress can only be called on client");
            return null;
        }
        if(!m_MissionData)
            Print("[WG_Events] ERROR: m_MissionData is NULL");
	    return m_MissionData;
    }
};