class WG_GameboyCase : ItemBase 
{	
	ref array<string> m_AllowedCargo = {
		"WG_Gameboy_Cartridge_Base",
		"WG_Gameboy"
	};
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