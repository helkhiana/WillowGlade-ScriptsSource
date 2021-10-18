modded class ActionUnlockDoors: ActionContinuousBase
{	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;
		
		Building building;
		if( Class.CastTo(building, target.GetObject()) && building.IsKindOf("MMO_CemeteryFence_DoubleGate_RegisterArea"))
			return false;
		return super.ActionCondition(player, target, item);
	}
};