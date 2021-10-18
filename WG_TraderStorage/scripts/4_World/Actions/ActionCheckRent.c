class ActionCheckRent: ActionInteractBase
{
	void ActionCheckRent()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "Check rent expiry date";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.IsInherited(WG_TraderStorageView) && player)
		{
			if(player.GetWGPlayerId() == -1)
				return false;
			if(!player.GetItemInHands())
				return true;
		}

		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);

		WG_TraderStorageView lockerview = WG_TraderStorageView.Cast( targetObject );
		if(lockerview)
		{
			int id = player.GetWGPlayerId();
			ref array<Object> nearest_objects = new array<Object>;
			ref array<CargoBase> proxy_cargos = new array<CargoBase>;
			GetGame().GetObjectsAtPosition( lockerview.GetPosition(), 1, nearest_objects, proxy_cargos );
			foreach(Object obj : nearest_objects)
			{
				WG_TraderStorage_Base storage = WG_TraderStorage_Base.Cast(obj);
				if(storage && id == storage.GetWGPlayerId())
				{
					Param1<string> itemMessage = new Param1<string>("Your rent will run out at: " + storage.GetRentExpiryTimeString());
					GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, itemMessage, true, player.GetIdentity());
					return;
				}
			}	
			Param1<string> itemMessage2 = new Param1<string>("You don't own storage here.");
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, itemMessage2, true, player.GetIdentity());
		}
	}
};