modded class ItemBase extends InventoryItem 
{
	PlayerBase owner;
	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner) 
	{
		super.OnItemLocationChanged(old_owner, new_owner);
		if (new_owner) 
		{
			if (new_owner.IsMan())
				owner = PlayerBase.Cast(new_owner);
			else
				owner = PlayerBase.Cast(new_owner.GetHierarchyRootPlayer());
		}
		else
		{
			owner = null;
		}		
	}

	override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		if (owner) 
		{
			if (IsClothing() || IsContainer()) 
			{
				if (owner && PVE_PlayerInitiation.IsPlayerInitiatedDamage(source))
					return false;
			}
		}
		return super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}
};