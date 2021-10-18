#ifdef TRADERPLUS
modded class ActionPackVehicle : ActionContinuousBase
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		if (action_data.m_MainItem && action_data.m_MainItem.GetHierarchyRootPlayer() == action_data.m_Player)
		{
			CarScript vehicle = CarScript.Cast(action_data.m_Target.GetObject());			
			string type = vehicle.GetType();
			bool state = TraderPlusHelper.CreateInInventoryWithState(action_data.m_Player, type, action_data.m_Target.GetObject().GetHealthLevel(), 1);
			if (!state)
				return;
			GetGame().ObjectDelete(vehicle);
			action_data.m_MainItem.SetHealth(0);
		}
	}
};
#endif