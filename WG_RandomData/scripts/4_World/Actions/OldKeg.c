class WG_OldKeg : Well
{    	
	override void SetActions()
	{
		super.SetActions();		
		RemoveAction(ActionWashHandsWellOne);
		RemoveAction(ActionDrinkWellContinuous);
	}
};

class WG_Invisible_Keg : WG_OldKeg {};
class WG_BeerTap : WG_OldKeg {};