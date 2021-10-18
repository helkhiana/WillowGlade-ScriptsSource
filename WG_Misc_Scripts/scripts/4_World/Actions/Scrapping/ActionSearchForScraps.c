class ActionSearchForScrapsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DECONSTRUCT);
	}
};

class ActionSearchForScraps: ActionContinuousBase
{
	private int chance = 40;
	void ActionSearchForScraps()
	{
		m_CallbackClass = ActionSearchForScrapsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNonRuined( 1.5 );
	}

	override string GetText()
	{
		return "Search for scrap";
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();

		if (targetObject)
		{
			BuildingWithScrapChance building = BuildingWithScrapChance.Cast(targetObject);
			if(building && building.CanScrap())
				return true;
		}

		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		PlayerBase player = action_data.m_Player;
		vector pos = player.GetPosition();
		bool currentChanceOfLoot = HasChance(chance);
		BuildingWithScrapChance building = BuildingWithScrapChance.Cast(action_data.m_Target.GetObject());
		building.ResetSearch();	
		if(currentChanceOfLoot)
		{
			int i  = Math.RandomInt(1, 6);
			ItemBase randomItem = ItemBase.Cast(GetGame().CreateObjectEx("WG_ScrapCrate", pos, ECE_PLACE_ON_SURFACE));
			randomItem.SetQuantity(i);
			Param1<string> randomItemMessage = new Param1<string>("You found a " + randomItem.GetDisplayName());
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, randomItemMessage, true, player.GetIdentity());
			return;
		}
		Param1<string> msgParam1 = new Param1<string>("No luck this time");
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, msgParam1, true, player.GetIdentity());
	}
};