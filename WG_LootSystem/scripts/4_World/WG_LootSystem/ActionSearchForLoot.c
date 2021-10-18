class ActionWGSearchForLootCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
};

class ActionWGSearchForLoot: ActionContinuousBase
{
	void ActionWGSearchForLoot()
	{
		m_CallbackClass = ActionWGSearchForLootCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNonRuined( 3 );
	}

	override string GetText()
	{
		return "Search";
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.IsInherited(WG_LootCrate_Base) && player)
		{
			WG_LootCrate_Base lootcrate = WG_LootCrate_Base.Cast( targetObject );			
			return lootcrate.CanSearch();
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data ) 
	{
		Object targetObject = action_data.m_Target.GetObject();
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		WG_LootCrate_Base lootcrate = WG_LootCrate_Base.Cast( targetObject );
		lootcrate.ResetInteraction();
		lootcrate.GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);	
		auto lootCrateConfig = g_Game.GetWG_LS_Config().Get_LootCrate(lootcrate.GetType());
		auto lootGroups = lootCrateConfig.lootGroups;
		if(Math.RandomIntInclusive(0,100) > lootCrateConfig.chanceOfLoot)
		{
			Param1<string> msgParam1 = new Param1<string>("Nothing was found");
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, msgParam1, true, player.GetIdentity());
			return;
		}
		foreach(WG_LS_LootGroups detailed : lootGroups)
		{
			int rndAmount = Math.RandomIntInclusive(detailed.minLoot,detailed.maxLoot);				
			array<string> lootArray = new array<string>;
			lootArray.InsertAll(detailed.loot);
			
			if(Math.RandomIntInclusive(0,100) > detailed.chanceOfLoot)
				break;
			for(int i = 1; i <= rndAmount; i++)
			{
				string spawnItem = lootArray.GetRandomElement();
				if(!detailed.allowDuplicates)
				{
					int index = lootArray.Find(spawnItem);
					lootArray.Remove(index);
				}
				lootcrate.GetInventory().CreateInInventory(spawnItem);
			}
		}
	}
};