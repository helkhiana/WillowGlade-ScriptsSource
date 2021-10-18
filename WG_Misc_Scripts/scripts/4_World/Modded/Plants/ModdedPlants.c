modded class ActionPlantSeed: ActionSingleUseBase
{
	override void Process( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if ( targetObject != NULL && targetObject.IsInherited(GardenBase) )
		{
			ItemBase seed_IB = ItemBase.Cast( action_data.m_MainItem );
			int seedCount = seed_IB.GetQuantity();
			super.Process(action_data);
			if(seedCount == seed_IB.GetQuantity()) {
				seedCount--;
				seed_IB.SetQuantity(seedCount);
			}
		}
		else{
			super.Process(action_data);
		}
	}
};

modded class Plant_Cannabis : PlantBase
{
	void Plant_Cannabis()
	{
		m_FullMaturityTime = 7200;
	}
};
modded class Cannabis : Edible_Base
{	
	override void SetActions()
	{
		super.SetActions();		
		RemoveAction(ActionForceFeed);
	}
};