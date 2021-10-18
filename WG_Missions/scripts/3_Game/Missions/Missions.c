class WG_Mission : Managed
{
    int uid;
    int missionType;
    int missionPhase;
    int vehicleType;
    ref array<ref WG_MissionRequirement> requirements;


    void WG_Mission(int in_missionType)
    {
        uid = Math.RandomIntInclusive(1, int.MAX - 1);
        missionType = in_missionType;
        missionPhase = WG_Mission_Phase.NotStarted;
        requirements = new ref array<ref WG_MissionRequirement>;
    }
    
    void Set_VehicleType(int id) { vehicleType = id; }
    int Get_VehicleType() { return vehicleType; }
    int Get_MissionType() { return missionType; }

    void Set_MissionPhase(int id) { missionPhase = id; }
    int Get_MissionPhase() { return missionPhase; }
    
    void Set_TextChoice() {}
    void Set_TextPhase() {}

    void ChoosePhase() { }

    void Accept()
    {
        Set_MissionPhase(WG_Mission_Phase.Accepted);
        g_Game.Get_ClientMissionsProgress().UpdateMissions(this);
        GetRPCManager().SendRPC("WG_Events", "SaveServerMissionsProgress", new Param1<ref WG_Mission>( this ), true, null);
    }

    void GoToNextPhase() { }
    void GiveInPhase() { }
    
    void Complete() 
    {
        Set_MissionPhase(WG_Mission_Phase.Completed);
        g_Game.Get_ClientMissionsProgress().UpdateMissions(this);
        GetRPCManager().SendRPC("WG_Events", "SaveServerMissionsProgress", new Param1<ref WG_Mission>( this ), true, null);
    }

    bool MissionIsCompleted()
    {
        return missionPhase == WG_Mission_Phase.Completed;
    }

    void AddRequirement(string className, string displayName, int quantity, bool fullfilled) 
    { 
        WG_MissionRequirement req = new WG_MissionRequirement;
        req.className = className;
        req.displayName = displayName;
        req.quantity = quantity;
        req.fullfilled = fullfilled;
        requirements.Insert(req);
    }
};