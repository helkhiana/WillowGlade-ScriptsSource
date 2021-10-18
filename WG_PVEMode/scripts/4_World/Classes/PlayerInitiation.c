class PVE_PlayerInitiation
{	
	static bool IsPlayerInitiatedDamage(EntityAI source, PlayerBase currentPlayer = null) 
	{
		if(source.IsPlayer())
			return true;
		if (source.IsInherited(Grenade_Base)) 
		{
			Grenade_Base grenade = Grenade_Base.Cast(source);
			PlayerBase thrower = grenade.Thrower;
			if(thrower && thrower.IsPlayer())
			{
				if(currentPlayer && thrower == currentPlayer)
					return false;
				return true;
			}
		}
		if (source.IsWeapon() || source.IsMeleeWeapon()) 
		{
			return source.GetHierarchyRoot().IsPlayer();
		}
			
		return false;
	}
};