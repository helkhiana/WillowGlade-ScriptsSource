modded class ActionOpenDoors: ActionInteractBase
{
 	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;

		MMO_CemeteryFence_DoubleGate_Event building;
		if( Class.CastTo(building, target.GetObject()))
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				if(building.IsKindOf("MMO_CemeteryFence_DoubleGate_RegisterArea") && !g_Game.GetHalloweenRegisterEventGateOpenable()) return false;
				if(building.IsKindOf("MMO_CemeteryFence_DoubleGate_EventStart") && !g_Game.GetHalloweenWave1EventGateOpenable()) return false;
				return ( !building.IsDoorOpen(doorIndex) && !building.IsDoorLocked(doorIndex) );
			}
		}
		return super.ActionCondition(player, target, item);
	}

	override void OnStartServer( ActionData action_data )
	{
		Building dooredBuilding = Building.Cast(action_data.m_Target.GetObject());
		int doorIndex = dooredBuilding.GetDoorIndex(action_data.m_Target.GetComponentIndex());
		if( doorIndex == -1 )
			return;
			
		MMO_CemeteryFence_DoubleGate_Event building;
		if( Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			building.OpenDoor(doorIndex);
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( building.StartEventRegister, 10000, false, doorIndex );
			return;
		}
		MMO_CemeteryFence_DoubleGate genericDoor;
		if( Class.CastTo(genericDoor, action_data.m_Target.GetObject()) )
		{
			genericDoor.OpenDoor(doorIndex);
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( genericDoor.RegularClose, 300000, false, doorIndex );
			return;
		}
		super.OnStartServer(action_data);
	}
};