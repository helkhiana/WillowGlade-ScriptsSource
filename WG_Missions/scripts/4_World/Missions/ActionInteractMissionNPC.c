class ActionInteractMissionNPC: ActionInteractBase
{
	void ActionInteractMissionNPC()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "Talk to Valya";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.IsInherited(WG_NPC_Valya) && player)
		{	
			return true;
		}

		return false;
	}

	override void OnExecuteClient(ActionData action_data) 
	{ 
        PlayerBase player = action_data.m_Player;        
        WG_NPC_Valya npc = WG_NPC_Valya.Cast(action_data.m_Target.GetObject());
        if (npc) 
		{
			GetGame().GetUIManager().EnterScriptedMenu(MISSIONTEXT_UI, null);
			WG_MissionTextUI menu = WG_MissionTextUI.Cast(GetGame().GetUIManager().GetMenu());
			
			if(npc.GetMissionType() == WG_Mission_Type.Vehicle)
			{
				ref WG_VehicleMission vehicleMission = WG_VehicleMission.Cast(g_Game.Get_ClientMissionsProgress().FindUncompletedVehicleMission());
				if(!vehicleMission)
            		vehicleMission = new ref WG_VehicleMission(npc.GetMissionType());
				menu.SetMission(vehicleMission);
			}
			else
			{
				ref WG_Mission mission = WG_Mission.Cast(g_Game.Get_ClientMissionsProgress().FindMissionByType(npc.GetMissionType()));
				if(!mission)
            		mission = new ref WG_Mission(npc.GetMissionType());
				menu.SetMission(mission);
			}
        }
    }
};