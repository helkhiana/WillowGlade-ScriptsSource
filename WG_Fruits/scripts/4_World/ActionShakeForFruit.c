class ActionShakeForFruitCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_CRAFT);
	}
};

class ActionShakeForFruit: ActionContinuousBase
{	
	void ActionShakeForFruit()
	{
		m_CallbackClass = ActionShakeForFruitCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "Shake for fruit";
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (target)
		{
			WoodBase tree = WoodBase.Cast(target.GetObject());
			if (tree && tree.GetTreeType() > TreeTypes.NOFRUIT_TREE)
				return true;
		}	
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		WoodBase tree = WoodBase.Cast(action_data.m_Target.GetObject());
		if (tree)
		{
			string fruit = tree.GetFruitType();
			PlayerBase player = action_data.m_Player;
			Param1<string> itemMessage;			
			bool currentChanceOfLoot = HasChance(40);
			if(!currentChanceOfLoot)
			{
				itemMessage = new Param1<string>("No luck this time");				
				GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, itemMessage, true, player.GetIdentity());
				return;
			}
			int count = Math.RandomInt(1, 2);
			ItemBase item;
			for (int i = 0; i < count; i++)
			{
				float posX = Math.RandomFloat(-1.5,1.5);
				float posZ = Math.RandomFloat(-1.5,1.5);
				vector randPos = Vector(posX, 0, posZ);
				vector fruitPos = player.GetWorldPosition() + randPos;
				item = ItemBase.Cast(GetGame().CreateObjectEx(fruit, fruitPos, ECE_PLACE_ON_SURFACE));
			}
			if(count == 1)
				itemMessage = new Param1<string>("You found a " + item.GetDisplayName());
			else
				itemMessage = new Param1<string>("You found some " + item.GetDisplayName());			
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, itemMessage, true, player.GetIdentity());
		}
	}
};