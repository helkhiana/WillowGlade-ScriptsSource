class WG_Medkit_Base : ItemBase
{
	float GetKitHealCost()
	{
		ref array<float> heal_costs = new array<float>;			
		ConfigGetFloatArray( "healCosts", heal_costs );
		return Math.RandomInt(heal_costs.Get(0), heal_costs.Get(1));
	}
    
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionHealTarget);
		AddAction(ActionHealSelf);
	}
};

class WG_AI2_Medkit : WG_Medkit_Base 
{
	override float GetBandagingEffectivity()
	{
		return 1.0;
	};
};


class WG_ITS_Medkit : WG_Medkit_Base 
{
	override float GetBandagingEffectivity()
	{
		return 2.0;
	};
};