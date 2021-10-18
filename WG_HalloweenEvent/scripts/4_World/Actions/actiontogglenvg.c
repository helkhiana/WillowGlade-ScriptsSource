modded class ActionToggleNVG: ActionBase
{	
    vector rewardChestLocation = "2392.989014 360.071045 7721.791016";
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		NVGoggles goggles;
		Clothing NVmount;
		NVmount = Clothing.Cast(target.GetObject());
		if ( !NVmount )
			return false;
		goggles = NVGoggles.Cast(NVmount.FindAttachmentBySlotName("NVG"));
		float distance_to_player = vector.Distance(rewardChestLocation, player.GetPosition());
		if(distance_to_player < 200)
			return false;
		if ( goggles )
			return true;
		
		return false;
	}
};
