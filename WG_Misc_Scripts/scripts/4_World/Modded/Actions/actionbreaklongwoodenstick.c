modded class ActionBreakLongWoodenStick: ActionContinuousBase
{	
	override void OnFinishProgressServer( ActionData action_data )
	{
		ItemBase ingredient = ItemBase.Cast(action_data.m_MainItem);
		int count = ingredient.GetQuantity() * 3;
		BreakLongWoodenStick lambda = new BreakLongWoodenStick(action_data.m_MainItem, "WoodenStick", action_data.m_Player, count);
		action_data.m_Player.ServerReplaceItemInHandsWithNew(lambda);
	}
};