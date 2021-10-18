class WG_MissionsData
{
    int playerId;
    string playerSteamId;
    string playerName;
    ref array<ref WG_Mission> missions;
    ref array<ref WG_VehicleMission> vehicleMissions;

    void WG_MissionsData(int in_playerId, string in_playerSteamId, string in_playerName)
    {
        playerId = in_playerId;
        playerSteamId = in_playerSteamId;
        playerName = in_playerName;
        missions = new ref array<ref WG_Mission>;
    }

    //regular missions?
    ref WG_Mission FindMissionByType(int missionType)
    {
        foreach(auto m : missions)
        {            
            if(m.Get_MissionType() == missionType && !m.MissionIsCompleted())
                return m;
        }

        return null;
    }

    int FindMissionIndexById(int id)
    {
        foreach(ref WG_Mission m : missions)
        {            
            if(m.uid == id)
                return missions.Find(m);
        }
        return -1;
    }

    void UpdateMissions(WG_Mission mission)
    {
        if(!missions) return;

        int listIndex = FindMissionIndexById(mission.uid);
        if(listIndex != -1)
            missions.Remove(listIndex);
        missions.Insert(mission);
    }
    
    //vehicle missions  
    ref WG_VehicleMission FindUncompletedVehicleMission()
    {
        foreach(auto m : vehicleMissions)
        {            
            if(!m.MissionIsCompleted())
                return m;
        }

        return null;
    }

    int FindVehicleMissionIndexById(int id)
    {
        foreach(ref WG_VehicleMission m : vehicleMissions)
        {            
            if(m.uid == id)
                return vehicleMissions.Find(m);
        }
        return -1;
    }

    void UpdateVehicleMissions(WG_VehicleMission mission)
    {
        if(!vehicleMissions) return;

        int listIndex = FindVehicleMissionIndexById(mission.uid);     
        if(listIndex != -1)
            vehicleMissions.Remove(listIndex);
        vehicleMissions.Insert(mission);
    }
};

class MissionStorageHandler
{
    static const string ROOT_FOLDER = "$profile:WillowGlade/PlayerDB/Missions/";

	void MissionStorageHandler()
	{
		if (!GetGame().IsServer()) return;

		if (!FileExist(ROOT_FOLDER))
        {
            Print("[MBTerritoryStore] '" + ROOT_FOLDER + "' does NOT exist, creating directory!");
            MakeDirectory(ROOT_FOLDER);
        }
    }

	void Save(WG_MissionsData playerMissionData)
    {        
        string filepath = ROOT_FOLDER + playerMissionData.playerSteamId + ".json";
        Print("[WG_Events] Saving Filepath for playermissionprogress: " + filepath);
        JsonFileLoader<WG_MissionsData>.JsonSaveFile(filepath, playerMissionData);
    }
    

    void Update(WG_Mission mission, string id)
    {
        WG_MissionsData missionProgress;
        GetPlayerMissionProgress(id, missionProgress);
        missionProgress.UpdateMissions(mission);
        Save(missionProgress);
    }
    
    void UpdateVehicleMissionsData(WG_VehicleMission mission, string id)
    {
        WG_MissionsData missionProgress;
        GetPlayerMissionProgress(id, missionProgress);
        missionProgress.UpdateVehicleMissions(mission);
        Save(missionProgress);
    }

    bool GetPlayerMissionProgress(string id, out WG_MissionsData missionProgress)
    {
        string filepath = ROOT_FOLDER + id + ".json";
        //Print("[WG_Events] Filepath for playermissionprogress: " + filepath);
        if (FileExist(filepath))
        {
            //Print("[WG_Events] found mission file: " + filepath);
            JsonFileLoader<WG_MissionsData>.JsonLoadFile(filepath, missionProgress);
            return true;
        }
        return false;
    }
};