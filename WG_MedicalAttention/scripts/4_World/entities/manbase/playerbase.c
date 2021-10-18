modded class PlayerBase
{
	private ref Param1<string> m_TirednessReportParam;
	private int m_TirednessRCountdown = 0;

	bool m_TirednessEnabled = true;
	bool m_SleepingBagAttached = false;
	bool m_WasSleeping = false;
	bool m_IsSleeping = false;

	private int m_Tiredness = 0;
	private int m_EnergizingDrinkAllowedRest = 0;
	private int m_EnergizingDrinkAllowedRestMax = 0;

	static const int MAX_TIREDNESS = 1000;
	static const float REST_GAIN_MIN = 1;
	static const float REST_GAIN_PER_SEC = 0.023;

	private float m_PlayerRestTick = 1;
	private float m_AccumulatedRest = 1;//REST_GAIN_MIN

	private int m_HeatSource = 0;
	static const int HEAT_SOURCE_COUNTDOWN = 5;

	private int m_LastYawn = 0;
	private int m_CurrentYawn = 0;
	private float m_YawnTime = 0;

	static const float YAWN_TIME_1 = 5;
	static const float YAWN_TIME_2 = 6;
	static const float YAWN_TIME_3 = 6.3;

	bool m_BrokenArms = false;
	bool m_TirednessShown = false;

	void PlayerBase()
	{
		m_TirednessReportParam = new Param1<string>("");
		m_EnergizingDrinkAllowedRestMax = MAX_TIREDNESS * ((float)MAGlobals.Get().g_EnergizingDrinkGain / 100);
		m_EnergizingDrinkAllowedRest = m_EnergizingDrinkAllowedRestMax;
	}

	bool IsPlayerSleeping()
	{
		bool isSleeping = true;
		if (!m_EmoteManager || !m_EmoteManager.m_bEmoteIsPlaying || !m_EmoteManager.m_Callback || m_EmoteManager.m_Callback.m_callbackID != DayZPlayerConstants.CMD_GESTUREFB_LYINGDOWN)
		{
			isSleeping = false;
		}

		if (MAGlobals.Get().g_SleepingDOF)
		{
			m_IsSleeping = isSleeping;
		}

		return isSleeping;
	}

	bool IsPlayerNearbySleepingBag()
	{
		if (MAGlobals.Get().g_SleepingBagClasses.Count() == 0)
		{
			return false;
		}

		array<Object> nearest_objects = new array<Object>;
		array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition(GetPosition(), 0.5, nearest_objects, proxy_cargos);

		for (int i = 0; i < nearest_objects.Count(); i++)
		{
			Object nearest_object = nearest_objects.Get(i);

			if (nearest_object != this && nearest_object.IsInherited(ItemBase) && nearest_object.GetParent() == null ) // not in player possession
			{
				string configClass = nearest_object.GetType();

				if (MAGlobals.Get().g_SleepingBagClasses.Find(configClass) >= 0)
				{
					return true;
				}
			}
		}
		
		return false;
	}

	void Yawn()
	{
		m_CurrentYawn++;
		if (m_CurrentYawn > MAX_TIREDNESS)
		{
			m_CurrentYawn = 0;
		}
	}

	private void PlayerYawnCheck()
	{
		if (m_CurrentYawn != m_LastYawn)
		{
			m_LastYawn = m_CurrentYawn;
			if (m_YawnTime == 0)
			{
				m_YawnTime = 0.01;

				EffectSound yawnSound;
				PlaySoundSet(yawnSound, "yawn_SoundSet", 0, 0 );
			}
		}
	}

	private void SendMessageToClient(Object reciever, string message)
	{
		PlayerBase man;
		if (GetGame().IsServer() && Class.CastTo(man, reciever) && m_TirednessReportParam && reciever.IsAlive() && message != "")
		{
			m_TirednessReportParam.param1 = message;
			GetGame().RPCSingleParam(man, ERPCs.RPC_USER_ACTION_MESSAGE, m_TirednessReportParam, true, man.GetIdentity());
		}
	}

	private void PlayerRestCheck(float deltaTime)
	{
		static const float PLAYER_REST_TICK = 3;

		m_PlayerRestTick += deltaTime;

		if (m_PlayerRestTick < PLAYER_REST_TICK)
		{
			return;
		}

		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			m_Tiredness = GetSingleAgentCount(MedicalAttentionAgents.TIREDNESS);

			if (!IsPlayerSleeping())
			{
				m_PlayerRestTick = 0;
				m_AccumulatedRest = REST_GAIN_MIN;
				m_TirednessRCountdown = 0;
				return;
			}

			SetSynchDirty();

			if (MAGlobals.Get().g_TirednessReport)
			{
				m_TirednessRCountdown--;
				if (m_TirednessRCountdown <= 0)
				{
					m_TirednessRCountdown = 5;
					int percent = 100 - (float)m_Tiredness / MAX_TIREDNESS * 100;
					SendMessageToClient(this, "Your rest level is " + percent.ToString() + "%");
				}
			}

			bool heatSource = m_HeatSource > 0 || m_SleepingBagAttached || IsPlayerNearbySleepingBag();

			if (m_HeatSource > 0)
			{
				m_HeatSource--;
			}

			if (m_AccumulatedRest > REST_GAIN_MIN + REST_GAIN_PER_SEC * 120) // if player is sleeping for 2 mins
			{
				m_EnergizingDrinkAllowedRest = m_EnergizingDrinkAllowedRestMax;

				if (!heatSource) // and no heat source then influenza
				{
					InsertAgent(eAgents.INFLUENZA, 1);
				}
			}

			if (m_Tiredness < (MAX_TIREDNESS / 2) && !heatSource) // if no heat source then cap resting at 50%
			{
				m_PlayerRestTick = 0;
				return;
			}

			// old way from Environment.CollectAndSetEnvironmentData()
			/*
			m_DayOrNight = (-1 * Math.AbsFloat( ( 1 - ( g_Game.GetDayTime() / GameConstants.ENVIRO_HIGH_NOON ) ) ) ) + 1;
			if (m_Tiredness < (MAX_TIREDNESS / 4) && m_DayOrNight >= 0.5)
			*/

			if (m_Tiredness < (MAX_TIREDNESS / 4) && !GetGame().GetWorld().IsNight()) // if heat source, but not night then cap resting at 75%
			{
				m_PlayerRestTick = 0;
				return;
			}

			m_AccumulatedRest += (REST_GAIN_PER_SEC * m_PlayerRestTick);
			int rest = m_AccumulatedRest * m_PlayerRestTick;

			if (rest > m_Tiredness)
			{
				rest = m_Tiredness;
			}

			InsertAgent(MedicalAttentionAgents.TIREDNESS, rest * -1);

			m_Tiredness -= rest;
		}
		else //if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			if (m_ModulePlayerStatus)
			{
				m_ModulePlayerStatus.SetTiredness(MAX_TIREDNESS - m_Tiredness, MAX_TIREDNESS);
			}

			if (m_IsSleeping != m_WasSleeping)
			{
				m_WasSleeping = m_IsSleeping;

				if (m_IsSleeping)
				{
					//PPEffects.OverrideDOF(true, 4, 700, 20, 10, 1);
					PPEffects.EnableBurlapSackBlindness();
				}
				else
				{
					//PPEffects.ResetDOFOverride();
					PPEffects.DisableBurlapSackBlindness();
				}
			}

			PlayerYawnCheck();
		}

		m_PlayerRestTick = 0;
	}

	override void Init()
	{
		super.Init();

		RegisterNetSyncVariableInt("m_Tiredness", 0, MAX_TIREDNESS);
		RegisterNetSyncVariableBool("m_TirednessEnabled");
		RegisterNetSyncVariableInt("m_CurrentYawn", 0, MAX_TIREDNESS);
		RegisterNetSyncVariableBool("m_IsSleeping");
		RegisterNetSyncVariableBool("m_BrokenArms");
	}

	override void OnConnect()
	{
		super.OnConnect();
		m_TirednessEnabled = MAGlobals.Get().g_TirednessEnabled;		
	}

	override void AddToEnvironmentTemperature(float pTemperature)
	{
		super.AddToEnvironmentTemperature(pTemperature);
		
		m_HeatSource = HEAT_SOURCE_COUNTDOWN;
	}

	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);

		if (!m_TirednessEnabled)
		{
			return;
		}
		if(m_ModulePlayerStatus && !m_TirednessShown)
		{
			m_TirednessShown = true;
			m_ModulePlayerStatus.ShowTiredness(m_TirednessEnabled);
		}
			
		PlayerRestCheck(deltaTime);
	}

	void HandleEnergizingDrink(ItemBase source, float amount)
	{
		if (!MAGlobals.Get().g_TirednessEnabled)
		{
			return;
		}

		string configClass = source.GetType();
		if (MAGlobals.Get().g_EnergizingDrinkClasses.Find(configClass) < 0)
		{
			return;
		}

		//Print("[MedicalAttention] HandleEnergizingDrink " + configClass);

		m_Tiredness = GetSingleAgentCount(MedicalAttentionAgents.TIREDNESS);

		int rest = 0;
		if (source.GetQuantityMax() > 0)
		{
			rest = 1 + amount * ((float)m_EnergizingDrinkAllowedRestMax / source.GetQuantityMax());
		}

		if (rest == 0 || m_EnergizingDrinkAllowedRest <= 0)
		{
			return;
		}

		if (rest > m_EnergizingDrinkAllowedRest)
		{
			rest = m_EnergizingDrinkAllowedRest;
		}

		m_EnergizingDrinkAllowedRest -= rest;

		if (rest > m_Tiredness)
		{
			rest = m_Tiredness;
		}

		InsertAgent(MedicalAttentionAgents.TIREDNESS, rest * -1);

		m_Tiredness -= rest;
	}

	void HandleAlcoholicDrink(ItemBase source, float amount)
	{
		string configClass = source.GetType();
		MAAlcoholicDrink drink = NULL;
		if (!MAGlobals.Get().g_AlcoholicDrinkClasses.Find(configClass, drink))
			return;
        int liquid = source.GetLiquidType();
		if(liquid != 0 && liquid != LIQUID_WINE && source.GetLiquidType() != LIQUID_BEERT && source.GetLiquidType() != LIQUID_VODKA && source.GetLiquidType() != LIQUID_WHISKEY && source.GetLiquidType() != LIQUID_MOONSHINE)
            return;

		int drunkenness = GetSingleAgentCount(MedicalAttentionAgents.DRUNKENNESS);
		int drunkennessMax = PluginTransmissionAgents.GetAgentMaxCount(MedicalAttentionAgents.DRUNKENNESS);

		amount *= drink.multiplier;

		if (drunkenness + amount > drunkennessMax)
			amount = drunkennessMax - drunkenness;

		InsertAgent(MedicalAttentionAgents.DRUNKENNESS, amount);
	}
    
    void HandleCoolingDrink(ItemBase source, float amount)
	{
        if(source.GetLiquidType() != LIQUID_MILK || source.GetLiquidType() != LIQUID_WATER)
            return;

        int drunkenness = GetSingleAgentCount(MedicalAttentionAgents.DRUNKENNESS);
        if(drunkenness < 1)  
            return;

        if(source.GetLiquidType() == LIQUID_MILK)
            amount *= 0.5;
        else
            amount *= 0.1;

        if ( amount > drunkenness)
        {
            amount = drunkenness;
        }

        amount -= amount*2;

		InsertAgent(MedicalAttentionAgents.DRUNKENNESS, amount);
	}

	override bool Consume(ItemBase source, float amount, EConsumeType consume_type)
	{
		if (source)
		{
			HandleEnergizingDrink(source, amount);
			HandleAlcoholicDrink(source, amount);
			HandleCoolingDrink(source, amount);
		}

		return super.Consume(source, amount, consume_type);
	}

	void BreakTheArms()
	{
		if (GetModifiersManager().IsModifierActive(eModifiers.MDF_BROKEN_ARMS))
		{
			GetModifiersManager().DeactivateModifier(eModifiers.MDF_BROKEN_ARMS);
		}
		GetModifiersManager().ActivateModifier(eModifiers.MDF_BROKEN_ARMS);
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		
		if (!damageResult && Math.RandomFloat01() < (float)MAGlobals.Get().g_ZombieArmFractureChance / 100)
		{
			BreakTheArms();
		}
		else if (damageResult)
		{
			float dmg = damageResult.GetHighestDamage("Health");
			
			if ((dmgZone == "LeftHand" || dmgZone == "RightHand" || dmgZone == "LeftArm" || dmgZone == "RightArm"))
			{
				if (source && source.IsMeleeWeapon() && dmg >= 30)
				{
					// melee
					BreakTheArms();
				}
				else if (dmg >= 50)
				{
					// anything else
					BreakTheArms();
				}
			}
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (!GetGame().IsServer() || !GetGame().IsMultiplayer() || !item)
		{
			return;
		}

		string configClass = item.GetType();

		if (m_TirednessEnabled)
		{
			if (MAGlobals.Get().g_SleepingBagClasses.Find(configClass) >= 0)
			{
				m_SleepingBagAttached = true;
			}
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		if (!GetGame().IsServer() || !GetGame().IsMultiplayer() || !item)
		{
			return;
		}

		string configClass = item.GetType();

		if (m_TirednessEnabled)
		{
			if (MAGlobals.Get().g_SleepingBagClasses.Find(configClass) >= 0)
			{
				m_SleepingBagAttached = false;
				//Print("[MedicalAttention] EEItemDetached " + configClass);
			}
		}
	}

	override bool CanClimb(int climbType, SHumanCommandClimbResult climbRes)
	{
		if (m_BrokenArms)
		{
			return false;
		}

		return super.CanClimb(climbType, climbRes);
	}

	override int GetShakeLevel()
	{
		if (m_BrokenArms)
		{
			return 7;
		}
		else
		{
			return super.GetShakeLevel();
		}
	}

	override void ApplySplint()
	{
		super.ApplySplint();
		if (GetModifiersManager().IsModifierActive(eModifiers.MDF_BONE_REGEN)) //effectively resets the timer
		{
			GetModifiersManager().DeactivateModifier(eModifiers.MDF_BONE_REGEN);
		}
		GetModifiersManager().ActivateModifier(eModifiers.MDF_BONE_REGEN);
	}
}
