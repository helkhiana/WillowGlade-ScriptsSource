class ActionTreatBrokenLimbsTarget : ActionHealBase
{
	void ActionTreatBrokenLimbsTarget()
	{
		ActionHealBase();
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
		
	override string GetText()
	{
		return "Treat Broken Limbs";
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase target = PlayerBase.Cast(action_data.m_Target.GetObject());
		
		if(action_data.m_MainItem && target)
		{
			TreatLimb(WG_Surgicalkit_Base.Cast(action_data.m_MainItem), target);
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
	}
	
	override void SetAnimation( ItemBase item )
	{
		switch( item.Type() )
		{
			case WG_ITS_Surgicalkit:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGETARGET;
				break;
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SALINEBLOODBAG;
				break;
		}
	}
};
