modded class Edible_Base
{	
	void GetConservationMultiplier(EntityAI parent, out int multiplier)
	{
		InventoryLocation invLocation = new InventoryLocation;
		parent.GetInventory().GetCurrentInventoryLocation(invLocation);
		EntityAI parentOfParentAI = invLocation.GetParent();
		bool isFridge = false;
		EntityAI fridge = NULL;

		foreach (string FridgeClassName : g_Game.GetPF_Config().Get_FridgeClasses())
		{
			if (parent.IsKindOf(FridgeClassName))
			{
				isFridge = true;
				fridge = parent;
				break;
			}
			if (parentOfParentAI && parentOfParentAI.IsKindOf(FridgeClassName))
			{
				isFridge = true;
				fridge = parentOfParentAI;
				break;
			}
		}
		if(isFridge && (!fridge.HasEnergyManager() || fridge.GetCompEM().IsWorking()))
			multiplier = g_Game.GetPF_Config().Get_FridgeConservationMultiplier();
	}

	override void ProcessDecay( float delta, bool hasRootAsPlayer )
	{
		InventoryLocation invLocation = new InventoryLocation;
		GetInventory().GetCurrentInventoryLocation(invLocation);
		EntityAI parent = invLocation.GetParent();
		float m_ConservationMultiplier = 1.0;
		if (parent && invLocation.GetType() == InventoryLocationType.CARGO)
			GetConservationMultiplier(parent, m_ConservationMultiplier);
		delta = delta / m_ConservationMultiplier;
		super.ProcessDecay(delta,hasRootAsPlayer);
	}
};