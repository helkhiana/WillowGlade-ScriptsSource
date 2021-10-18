modded class Environment
{
	protected float m_PlayerColdResist;

	override void Init(PlayerBase pPlayer)
	{
		super.Init(pPlayer);

		m_PlayerColdResist = 0.0;
	}

	override protected void CollectAndSetPlayerData()
	{
		super.CollectAndSetPlayerData();

		// cold resistance stuff
		m_PlayerColdResist = m_Player.GetStatColdResistance().Get();

		// lets use this spot to control coldresistance soft skill (ENVIRO_TICK_RATE == 2)
		if ( ( m_HeatComfort < 0 ) && ( m_Player.GetStatColdResistance().Get() < 1.0 ) )
		{
			// heatcomfort is below zero and cold resistance has not yet been maxed
			m_Player.UpdateColdResistance( Math.AbsFloat( m_HeatComfort ) * 0.00015 );
			//m_Player.UpdateColdResistance(0.01);
		}

		// frostbite heatcomfort sync to client (ui)
		m_Player.UpdateExactHeatComfort();
	}

	override void CollectAndSetEnvironmentData()
	{
		super.CollectAndSetEnvironmentData();
		string worldname;
		GetGame().GetWorldName(worldname);
		worldname.ToLower(); //to be safe 
		// wetness event value
		Weather weather = g_Game.GetWeather();
		m_DayOrNight = g_Game.GetWorld().GetSunOrMoon();
		m_Fog = weather.GetFog().GetActual();
		m_Clouds =	weather.GetOvercast().GetActual();
		m_Wind = weather.GetWindSpeed() / weather.GetWindMaximumSpeed();
		SetEnvironmentTemperature();
		if ( worldname == "namlask" )
		{
			m_Rain = g_Game.GetMission().GetWorldData().GetWetnessEvent();
		}
		else if ( worldname == "chernarusplus" )
		{
			m_Rain = weather.GetRain().GetActual();
		}
	}

	override float EnvTempToCoef(float pTemp)
	{
		if ( pTemp >= GameConstants.ENVIRO_HIGH_TEMP_LIMIT )
			return 1;
		
		if ( pTemp <= GameConstants.ENVIRO_LOW_TEMP_LIMIT )
			return -1;
		
		float result = ( pTemp - GameConstants.ENVIRO_PLAYER_COMFORT_TEMP ) / 75.0;
		
		return result;
	}
	
	override void ProcessItemsHeat()
	{
		float hcHead, hcBody, hcFeet;	//! Heat Comfort
		float hHead, hBody, hFeet;		//! Heat (from items);
		
		float heatComfortAvg;
		float heatAvg;

		BodyPartHeatProperties( m_HeadParts, GameConstants.ENVIRO_HEATCOMFORT_HEADPARTS_WEIGHT, hcHead, hHead );
		BodyPartHeatProperties( m_BodyParts, GameConstants.ENVIRO_HEATCOMFORT_BODYPARTS_WEIGHT, hcBody, hBody );
		BodyPartHeatProperties( m_FeetParts, GameConstants.ENVIRO_HEATCOMFORT_FEETPARTS_WEIGHT, hcFeet, hFeet );

		heatComfortAvg = ( hcHead + hcBody + hcFeet ) / 3;
		heatAvg = ( hHead + hBody + hFeet ) / 3;
		
		heatAvg = heatAvg * GameConstants.ENVIRO_ITEM_HEAT_TRANSFER_COEF;
		
		// heat buffer
		float applicableHB = 0.0;
		if ( m_HeatSourceTemp == 0 )
		{
			applicableHB = ( m_Player.GetStatHeatBuffer().Get() / 30.0 );
			if ( applicableHB > 0.0 )
			{
				if ( IsWaterContact() )
					m_HeatBufferTimer = 1.1;

				if ( m_HeatBufferTimer > 1.0 )
					m_Player.GetStatHeatBuffer().Add( Math.Min( EnvTempToCoef( m_EnvironmentTemperature ), -0.1 ) * GameConstants.ENVIRO_PLAYER_HEATBUFFER_DECREASE );
				else
					m_HeatBufferTimer += GameConstants.ENVIRO_PLAYER_HEATBUFFER_TICK;
			}
			else
			{
				m_HeatBufferTimer = 0.0;
			}			
		}
		else
		{
			if ( m_HeatComfort > PlayerConstants.THRESHOLD_HEAT_COMFORT_MINUS_WARNING )
			{
				m_Player.GetStatHeatBuffer().Add( GameConstants.ENVIRO_PLAYER_HEATBUFFER_INCREASE );
				m_HeatBufferTimer = 0.0;
			}
			else
			{
				m_HeatBufferTimer = 0.0;
			}
		}
		
		float overridenHeatComfort = 0.0;
		if ( OverridenHeatComfort( overridenHeatComfort ) )
		{
			m_HeatComfort = overridenHeatComfort;
		}
		else
		{
			m_HeatComfort = ( heatComfortAvg + heatAvg + ( GetPlayerHeat() / 100 ) ) + EnvTempToCoef( m_EnvironmentTemperature );
			if ( ( m_HeatComfort + applicableHB ) < ( PlayerConstants.THRESHOLD_HEAT_COMFORT_PLUS_WARNING - 0.01 ) )
			{
				if ( !IsWaterContact() )
					m_HeatComfort += applicableHB;
			}
			else
			{
				if ( !IsWaterContact() )
				{
					if ( m_HeatComfort <= ( PlayerConstants.THRESHOLD_HEAT_COMFORT_PLUS_WARNING - 0.01 ) )
					{
						m_HeatComfort = ( PlayerConstants.THRESHOLD_HEAT_COMFORT_PLUS_WARNING - 0.01 );
					}
				}
			}
			m_HeatComfort = Math.Clamp( m_HeatComfort, m_Player.GetStatHeatComfort().GetMin(), m_Player.GetStatHeatComfort().GetMax() );
		}
		
		// fixed heat comfort bonus from cold resistance soft skill
		m_HeatComfort += ( 0.25 ) * m_Player.GetStatColdResistance().Get();
		m_Player.GetStatHeatComfort().Set( m_HeatComfort );
	}
	

	bool IsSafeFromEVR()
	{
		return (IsInsideBuilding() || IsInsideVehicle());
	}
};