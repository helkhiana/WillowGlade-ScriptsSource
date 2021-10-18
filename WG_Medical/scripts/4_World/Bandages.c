class WG_EmergencyBandage : ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBandageTarget);
		AddAction(ActionBandageSelf);
	}
	
	override float GetBandagingEffectivity()
	{
		return 2.0;
	}	
	
	override bool CanBeDisinfected()
	{
		return true;
	}

	override float GetInfectionChance(int system = 0, Param param = null)
	{
		return 0;
	}
};