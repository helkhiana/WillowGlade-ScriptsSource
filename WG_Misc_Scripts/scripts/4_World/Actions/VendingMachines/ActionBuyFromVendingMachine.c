class ActionBuyFromVendingMachine: ActionInteractBase
{
	void ActionBuyFromVendingMachine()
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
		return "Insert Token";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.IsInherited(WG_VendingMachine_Base) && player)
		{
			ItemBase myItem = player.GetItemInHands();
			if(myItem && myItem.IsInherited(WG_Coin_Base))
			{
				string selection = targetObject.GetActionComponentName(target.GetComponentIndex());
				if (selection && selection == "selection")			
					return true;
			}
		}

		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);

		WG_VendingMachine_Base baseMachine = WG_VendingMachine_Base.Cast( targetObject );
		vector drop_positionMS = baseMachine.GetSelectionPositionMS( "drop" );
		vector drop_position = baseMachine.ModelToWorld(drop_positionMS);
		
		WG_VendingMachine_Cans cansMachine = WG_VendingMachine_Cans.Cast( targetObject );
		if(cansMachine)
		{
			ExecuteMachineResult(FoodCansMachineResultArray.GetRandomElement(),player, drop_position);
			return;
		}

		WG_VendingMachine_Drinks drinksMachine = WG_VendingMachine_Drinks.Cast( targetObject );
		if(drinksMachine)
		{
			ExecuteMachineResult(DrinksMachineResultArray.GetRandomElement(),player, drop_position);
			return;
		}

		WG_VendingMachine_Snacks snacksMachine = WG_VendingMachine_Snacks.Cast( targetObject );
		if(snacksMachine)
		{
			ExecuteMachineResult(SnacksMachineResultArray.GetRandomElement(),player, drop_position);
			return;
		}
	}

	void ExecuteMachineResult(string result, PlayerBase player, vector pos)
	{
		if(HasChance(70))
		{
			ItemBase item = ItemBase.Cast(GetGame().CreateObject(result, pos));
			item.SetPosition(pos);
			item.SetOrientation("0 -90 90");
			Param1<string> itemMessage = new Param1<string>("You got a " + item.GetDisplayName());
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, itemMessage, true, player.GetIdentity());
		}
		else
		{
			Param1<string> itemMessage2 = new Param1<string>("Sorry, the machine is a bit rusty. It ate your token.");
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, itemMessage2, true, player.GetIdentity());
		}
		ItemBase inHands = ItemBase.Cast(player.GetItemInHands());
		inHands.Delete();
	}
};