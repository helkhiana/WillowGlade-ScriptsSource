class ActionHealSelf : ActionHealBase
{	
	void ActionHealSelf()
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
		return "#treat_wound";
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		if(action_data.m_MainItem && target)
		{
			ApplyMedkit(WG_Medkit_Base.Cast(action_data.m_MainItem), target );
			if(action_data.m_MainItem.IsKindOf("WG_AI2_Medkit"))
				TreatRadiation(WG_Medkit_Base.Cast(action_data.m_MainItem), target);
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
	}
};
