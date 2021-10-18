modded class ActionFertilizeSlot: ActionContinuousBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		GardenBase garden_base;
		if ( Class.CastTo(garden_base, target.GetObject()))
		{
			Slot slot;
			
			array<string> selections = new array<string>;
			garden_base.GetActionComponentNameList(target.GetComponentIndex(), selections);
			string selection;

			for (int s = 0; s < selections.Count(); s++)
			{
				selection = selections[s];
				slot = garden_base.GetSlotBySelection( selection );
				if (slot)
					break;
			}
		
			if ( slot != NULL)
			{
				ItemBase seed = slot.GetSeed();
				if(!seed || seed.IsKindOf("CannabisSeeds")||seed.IsKindOf("CocaSeeds"))
					return false;
			}
			if ( garden_base.NeedsFertilization( selection ) )
			{
				if ( item.GetQuantity() > 0 )
				{
					return true;
				}
			}
		}
		return false;
	}
};