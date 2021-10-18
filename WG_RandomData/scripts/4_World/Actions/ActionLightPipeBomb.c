class ActionLightPipeBomb extends ActionSingleUseBase
{
	void ActionLightPipeBomb()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_LIGHTFLARE;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "Light fuse";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		WG_PipeBomb_Base grenade = WG_PipeBomb_Base.Cast(item);
		if( grenade && grenade.IsPinned() )
			return true;

		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
	}
	
	override void OnStartClient( ActionData action_data )
	{
	}

	override void OnEndClient( ActionData action_data )
	{
		WG_PipeBomb_Base grenade = WG_PipeBomb_Base.Cast(action_data.m_MainItem);
		if( grenade )
			grenade.StartEffects();
	}
	
	override void OnEndServer( ActionData action_data )
	{
		WG_PipeBomb_Base grenade = WG_PipeBomb_Base.Cast(action_data.m_MainItem);
		if( grenade )
			grenade.Unpin();
	}
}