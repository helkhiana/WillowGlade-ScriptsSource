modded class ActionBuryAshes: ActionContinuousBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		FireplaceBase fireplace_target = FireplaceBase.Cast( target.GetObject() );
		
		if ( fireplace_target )
		{
			if ( fireplace_target.HasAshes() && !fireplace_target.IsBurning() && fireplace_target.IsEmpty() )
			{
				return true;
			}
		}
		
		return false;
	}
};