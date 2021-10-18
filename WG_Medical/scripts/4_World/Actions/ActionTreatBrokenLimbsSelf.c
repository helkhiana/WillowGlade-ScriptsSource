class ActionTreatBrokenLimbsSelf : ActionHealBase
{	
	void ActionTreatBrokenLimbsSelf()
	{
		ActionHealBase();
	}

	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{
		return "Treat Broken Limbs";
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		if(action_data.m_MainItem && target)
		{
			TreatLimb(WG_Surgicalkit_Base.Cast(action_data.m_MainItem), target);
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
	}
};
