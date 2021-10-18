class WG_Journal : ItemBook 
{	
	ref array<string> m_AllowedCargo = {"Paper","WrittenNote","Pen_ColorBase","dzn_athena_planning","dzn_athena_action1","dzn_athena_action2","dzn_netanyas_log","dzn_athena3_october","dzn_athena3_exp2","dzn_athena3_exp1","dzn_athena3_august"};
	override bool CanReceiveItemIntoCargo (EntityAI item)
	{
		foreach( string allowedCargo : m_AllowedCargo )
		{
			if(item.IsKindOf(allowedCargo))
				return true;
		}
		
		return false;
	}
	
	override bool CanSwapItemInCargo (EntityAI child_entity, EntityAI new_entity)
	{
		foreach( string allowedCargo : m_AllowedCargo )
		{		
			if(child_entity.IsKindOf(allowedCargo) && new_entity.IsKindOf(allowedCargo))
				return true;
		}		
		return false;		
	}
};