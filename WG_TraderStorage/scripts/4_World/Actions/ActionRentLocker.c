class ActionRentStorage: ActionInteractBase
{
	void ActionRentStorage()
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
		return "Rent storage";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.IsInherited(WG_TraderStorageView) && player)
		{
			WG_TraderStorageView storageView = WG_TraderStorageView.Cast( targetObject );
			ItemBase myItem = player.GetItemInHands();
			if(myItem && myItem.IsKindOf(storageView.GetTokenTierType()))
			{	
				return true;
			}
		}

		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);

		WG_TraderStorageView storageView = WG_TraderStorageView.Cast( targetObject );
		if(storageView)
		{
			int id = player.GetWGPlayerId();
			if(storageView.HasBeenRentedAlready(id))
			{
				Param1<string> denied = new Param1<string>("You cannot rent another storage of this type.");
				GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, denied, true, player.GetIdentity());
				return;
			}
			WG_TraderStorage_Base instanced = WG_TraderStorage_Base.Cast(GetGame().CreateObject(storageView.GetInstancedType(), storageView.GetPosition()));			
			instanced.SetWGPlayerId(player, id);
			storageView.AddToRenters(id);	
			Param1<string> itemMessage = new Param1<string>("You rented a storage.");
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, itemMessage, true, player.GetIdentity());
			ItemBase inHands = ItemBase.Cast(player.GetItemInHands());
			inHands.Delete();
		}
	}
};