class WG_Surgicalkit_Base : ItemBase
{    
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTreatBrokenLimbsTarget);
		AddAction(ActionTreatBrokenLimbsSelf);
	}
};

class WG_ITS_Surgicalkit : WG_Surgicalkit_Base 
{
	override float GetBandagingEffectivity()
	{
		return 1.0;
	};
};