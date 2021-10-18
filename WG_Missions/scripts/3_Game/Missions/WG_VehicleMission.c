class WG_VehicleMission : WG_Mission
{
    string m_CarType;
    //need to cater for the different types of missions in storage. might want to store all variables in base class. then
    //just override the texts and phases logic in child.

    string Get_VehicleClassName(int type) 
    { 
        switch (type)
        {
            case WG_CarMission_Type.WG_ATV:
                m_CarType = "ATV";
                return "WG_ATV"; 
                break;
            case WG_CarMission_Type.WG_Truck:
                m_CarType = "Truck";
                return "Truck_01_Covered"; 
                break;
            case WG_CarMission_Type.WG_Olga:
                m_CarType = "Olga";
                return "CivilianSedan"; 
                break;
            case WG_CarMission_Type.WG_ADA:
                m_CarType = "ADA";
                return "OffroadHatchback"; 
                break;
            case WG_CarMission_Type.WG_Gunter:
                m_CarType = "Gunter";
                return "Hatchback_02"; 
                break;
            case WG_CarMission_Type.WG_Sarka:
                m_CarType = "Sarka";
                return "Sedan_02"; 
                break;
            case WG_CarMission_Type.WG_ETrolley:
                m_CarType = "E-Trolley";
                return "Spur_Trolley_E_Kart"; 
                break;     
            case WG_CarMission_Type.WG_Trolley:
                m_CarType = "Trolley";
                return "Spur_TrolleyKart"; 
                break;           
            default:
                break;
        }
        return ""; 
    }

    
    string Get_VehicleName(int type) 
    { 
        switch (type)
        {
            case WG_CarMission_Type.WG_ATV:
                return "ATV"; 
                break;
            case WG_CarMission_Type.WG_Truck:
                return "Truck"; 
                break;
            case WG_CarMission_Type.WG_Olga:
                return "Olga"; 
                break;
            case WG_CarMission_Type.WG_ADA:
                return "ADA"; 
                break;
            case WG_CarMission_Type.WG_Gunter:
                return "Gunter"; 
                break;
            case WG_CarMission_Type.WG_Sarka:
                return "Sarka"; 
                break;
            case WG_CarMission_Type.WG_ETrolley:
                return "E-Trolley"; 
                break;     
            case WG_CarMission_Type.WG_Trolley:
                return "Trolley"; 
                break;           
            default:
                break;
        }
        return ""; 
    }

    override void ChoosePhase()
    {
        switch (missionPhase)
        {
            case WG_Mission_Phase.NotStarted:
                InitialPhase();
                break;
            case WG_Mission_Phase.Accepted:
                AcceptedPhase();
                break;
            case WG_Mission_Phase.P1:
                AcceptancePhase();
                break;
        }
    }

    void InitialPhase()
    {
        WG_MissionTextUI menu = WG_MissionTextUI.Cast(GetGame().GetUIManager().GetMenu());
        menu.GetMissionListWidget().Show(true);
        menu.GetIntroductionTextWidget().Show(true);
        menu.GetMissionTextWidget().Show(false);
        menu.GetAcceptBtn().Show(false);
        menu.GetNextBtn().Show(true);
        menu.MissionListClearItems();
        //maybe add columns with ID for easier removal/addition?
        menu.MissionListAddItem(string.Format("I would like an %1.", Get_VehicleName(WG_CarMission_Type.WG_ATV)), NULL,  0);
        menu.MissionListAddItem(string.Format("What can I trade you for an %1?", Get_VehicleName(WG_CarMission_Type.WG_Truck)), NULL,  0);
        menu.MissionListAddItem(string.Format("I want to trade for a %1.", Get_VehicleName(WG_CarMission_Type.WG_Olga)), NULL,  0);
        menu.MissionListAddItem(string.Format("I need a %1.", Get_VehicleName(WG_CarMission_Type.WG_ADA)), NULL,  0);
        menu.MissionListAddItem(string.Format("Do you have a %1 around?", Get_VehicleName(WG_CarMission_Type.WG_Gunter)), NULL,  0);
        menu.MissionListAddItem(string.Format("Tell me what you need for a %1.", Get_VehicleName(WG_CarMission_Type.WG_Sarka)), NULL,  0);
        menu.MissionListAddItem(string.Format("I have some junk, can you make me a %1?", Get_VehicleName(WG_CarMission_Type.WG_ETrolley)), NULL,  0);
        menu.MissionListAddItem(string.Format("Can you make me a %1?", Get_VehicleName(WG_CarMission_Type.WG_Trolley)), NULL,  0);
        menu.MissionListSelectRow(0);
        Set_MissionPhase(WG_Mission_Phase.P1);
    }

    void AcceptedPhase()
    {
        WG_MissionTextUI menu = WG_MissionTextUI.Cast(GetGame().GetUIManager().GetMenu());
        menu.GetMissionListWidget().Show(false);
        menu.GetIntroductionTextWidget().Show(false);
        menu.GetMissionTextWidget().Show(true);
        menu.GetAcceptBtn().Show(false);
        menu.GetNextBtn().Show(false);
        menu.GetGiveInBtn().Show(true);
        menu.GetNotYetBtn().Show(true);
        menu.MissionTextClearItems();
        Get_VehicleClassName(vehicleType);
        menu.MissionTextAddItem(string.Format("Welcome back. Do you have 4 %1 Wheels I asked for? If not, come back when you have them.", m_CarType), NULL,  0);        
        menu.MissionTextSelectRow(0);
    }

    void AcceptancePhase()
    {
        WG_MissionTextUI menu = WG_MissionTextUI.Cast(GetGame().GetUIManager().GetMenu());
        int row_index = menu.GetMissionListWidget().GetSelectedRow();
        Set_VehicleType(row_index + 1);        
        Get_VehicleClassName(vehicleType);
        menu.GetMissionListWidget().Show(false);
        menu.GetIntroductionTextWidget().Show(false);
        menu.GetMissionTextWidget().Show(true);
        menu.GetAcceptBtn().Show(true);
        menu.GetNextBtn().Show(false);        
        menu.MissionTextClearItems();
        menu.MissionTextAddItem(string.Format("Right. I see you would like to get an %1.", m_CarType), NULL,  0);
        menu.MissionTextAddItem("For that I'll need you to do some stuff for me as I don't have all items laying around as people think.", NULL,  0);
        menu.MissionTextAddItem("", NULL,  0);
        menu.MissionTextAddItem(string.Format("If you can bring me 4 %1 Wheels, we'll discuss further.", m_CarType), NULL,  0);
        menu.MissionTextSelectRow(0);
    }

    override void GiveInPhase()
    {
        super.GiveInPhase();
        //check if a next phase is needed, take items etc.
        //GetRPCManager().SendRPC("WG_Events", "SaveServerMissionsProgress", new Param1<ref WG_Mission>( this ), true, null);
    }
    
    override void Complete() 
    {
        Set_MissionPhase(WG_Mission_Phase.Completed);
        g_Game.Get_ClientMissionsProgress().UpdateVehicleMissions(this);
        GetRPCManager().SendRPC("WG_Events", "SaveServerVehicleMissionsProgress", new Param1<ref WG_VehicleMission>( this ), true, null);
    }
    
    override void Accept() 
    {        
        Set_MissionPhase(WG_Mission_Phase.Accepted);
        g_Game.Get_ClientMissionsProgress().UpdateVehicleMissions(this);
        GetRPCManager().SendRPC("WG_Events", "SaveServerVehicleMissionsProgress", new Param1<ref WG_VehicleMission>( this ), true, null);
    }
};