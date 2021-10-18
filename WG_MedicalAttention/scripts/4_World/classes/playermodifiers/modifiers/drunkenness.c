class DrunkennessMdfr: ModifierBase
{
	static const int AGENT_THRESHOLD_ACTIVATE = 100;
	static const int AGENT_THRESHOLD_DEACTIVATE = 20;
	static const int WATER_DRAIN_FROM_VOMIT = 70;
	static const int ENERGY_DRAIN_FROM_VOMIT = 55;
	static const float STOMACH_MIN_VOLUME = 200;
	override void Init()
	{
		m_TrackActivatedTime	= false;
		m_ID 					= MedicalAttentionModifiers.MDF_DRUNKENNESS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_INACTIVE;
	}

	override protected bool ActivateCondition(PlayerBase player)
	{
		return player.GetSingleAgentCount(MedicalAttentionAgents.DRUNKENNESS) > AGENT_THRESHOLD_ACTIVATE;
	}

	override protected void OnActivate(PlayerBase player)
	{
		//player.IncreaseDiseaseCount();
		if (player.GetNotifiersManager()) player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);
		// copy from PainKillersMdfr
		m_Player.m_InjuryHandler.m_ForceInjuryAnimMask = m_Player.m_InjuryHandler.m_ForceInjuryAnimMask | eInjuryOverrides.PAIN_KILLERS_LVL0;
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		//player.DecreaseDiseaseCount();
		if (player.GetNotifiersManager()) player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
		m_Player.m_InjuryHandler.m_ForceInjuryAnimMask = m_Player.m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.PAIN_KILLERS_LVL0;
		m_Player.m_InjuryHandler.m_ForceInjuryAnimMask = m_Player.m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.PAIN_KILLERS_LVL1;
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		return player.GetSingleAgentCount(MedicalAttentionAgents.DRUNKENNESS) < AGENT_THRESHOLD_DEACTIVATE;
	}

	override protected void OnTick(PlayerBase player, float deltaT)
	{
		float drunkenness = player.GetSingleAgentCount(MedicalAttentionAgents.DRUNKENNESS);

		if (player.IsUnconscious())
		{
			return;
		}

		if (drunkenness >= 250)
		{
			if (Math.RandomFloat01() < 1 / 15)
			{
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_LAUGHTER);
			}
		}

		if (drunkenness < 566 || player.IsInVehicle())
		{
			return;
		}

		bool fallUnconscious = drunkenness >= 850 && Math.RandomFloat01() < 1 / 25;

		if (!fallUnconscious && Math.RandomFloat01() < 1 / 25)
		{
			float stomach_volume = player.m_PlayerStomach.GetStomachVolume();
			if ( stomach_volume >= STOMACH_MIN_VOLUME || Math.RandomFloat01() < 0.5 )
			{
				SymptomBase symptom = player.GetSymptomManager().QueueUpPrimarySymptom( SymptomIDs.SYMPTOM_VOMIT );

				if ( symptom )
				{ 
					symptom.SetDuration( Math.RandomIntInclusive( 4, 8 ) );

					if (m_Player.GetStatWater().Get() > (WATER_DRAIN_FROM_VOMIT))
						m_Player.GetStatWater().Add(-1 * WATER_DRAIN_FROM_VOMIT);
					if (m_Player.GetStatEnergy().Get() > (ENERGY_DRAIN_FROM_VOMIT))
						m_Player.GetStatEnergy().Add(-1 * ENERGY_DRAIN_FROM_VOMIT);
				}
			}
		}

		if (fallUnconscious)
		{
			player.SetHealth("", "Shock", 0);
		}
	}
}