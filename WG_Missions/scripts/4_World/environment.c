/* modded class Environment
{
	private bool m_AcidRainEventActive = false;
	private int m_AcidRainEventStartTime = -1;
	private float m_AcidRainEventPlayerDamage = 5.0;
	private float m_AcidRainEventClothesDamage = 5.0;
	private float m_AcidRainEventPlayerDamageFromRuinedClothesMdfr = 0.0;
	private int m_AcidRainEventFrequency = 10800; //seconds
	private int m_AcidRainEventTickRate = 3;
	private int m_AcidRainEventTickTimer = 0;
	// Calculates heatisolation of clothing, process its wetness, collects heat from heated items and calculates player's heat comfort
	override void Update(float pDelta)
	{
		if (m_Player)
		{
			m_RoofCheckTimer += pDelta;
			//! check if player is under roof (only if the Building check is false)
			if (m_RoofCheckTimer >= GameConstants.ENVIRO_TICK_ROOF_RC_CHECK && !IsInsideBuilding())
			{
				CheckUnderRoof();
				m_RoofCheckTimer = 0;
			}

			m_Time += pDelta;
			if ( m_Time >= GameConstants.ENVIRO_TICK_RATE )
			{
				m_Time = 0;
				m_WetDryTick++; // Sets whether it is time to add wetness to items and clothing
				
				//Print(IsInsideBuilding().ToString());

				//! Updates data
				CheckWaterContact(m_WaterLevel);
				CollectAndSetPlayerData();
				CollectAndSetEnvironmentData();
				
				//! Process temperature
				ProcessItemsHeat();

				//! Process item wetness/dryness
				if ( m_WetDryTick >= GameConstants.ENVIRO_TICKS_TO_WETNESS_CALCULATION )
				{
					//acid rain start
					//if( IsRaining() && !IsAcidRainActive() && IsAcidRain() && IsAcidRainAllowedToStartAgain())
					if( IsRaining() && !IsAcidRainActive() && IsAcidRain())
					{
						m_AcidRainEventStartTime = JMDate.Now(false).GetTimestamp();
						m_AcidRainEventActive = true;
					}

					if( !IsRaining() && IsAcidRainActive())
					{
						m_AcidRainEventActive = false;
					}

					if(IsAcidRainActive() && !IsInsideBuilding() && !IsUnderRoof() && !IsInsideVehicle())
					{
						m_AcidRainEventTickTimer++;
						if(m_AcidRainEventTickTimer > m_AcidRainEventTickRate)
						{
							ProcessItemsDamageFromAcidRain();
							ProcessPlayerDamageFromAcidRain();
							m_AcidRainEventTickTimer = 0;
						}
					}
					//acid rain end

					if( IsWaterContact() )
					{
						ProcessWetnessByWaterLevel(m_WaterLevel);
					}
					else if( IsRaining() && !IsInsideBuilding() && !IsUnderRoof() && !IsInsideVehicle() )
					{
						ProcessWetnessByRain();
					}
					else
					{
						ProcessItemsDryness();
					}

					//! setting of wetness/dryiness of player
					if ( ( m_ItemsWetnessMax < GameConstants.STATE_WET ) && ( m_Player.GetStatWet().Get() == 1 ) )
					{
						m_Player.GetStatWet().Set( 0 );
					}
					else if ( ( m_ItemsWetnessMax >= GameConstants.STATE_WET ) && ( m_Player.GetStatWet().Get() == 0 ) )
					{
						m_Player.GetStatWet().Set( 1 );
					}

					m_WetDryTick = 0;
					m_ItemsWetnessMax = 0; //! reset item wetness counter;
				}
				
				m_HeatSourceTemp = 0.0;
			}
		}
	}

	bool IsAcidRainActive()
	{
		return m_AcidRainEventActive;
	}

	bool IsAcidRainAllowedToStartAgain()
	{
		//must get/put this from somwehere else
		int deltaInSeconds = JMDate.Now(false).GetTimestamp() - m_AcidRainEventStartTime;		
		if(deltaInSeconds > m_AcidRainEventFrequency)
			return true;
		return false;
	}

	bool IsAcidRain()
	{
		//must get this from somwehere else
		return true;
	}


	protected void ProcessPlayerDamageFromAcidRain()
	{
		int dmg = -m_AcidRainEventPlayerDamage * m_AcidRainEventPlayerDamageFromRuinedClothesMdfr;
		Print("m_AcidRainEventPlayerDamageFromRuinedClothesMdfr " + m_AcidRainEventPlayerDamageFromRuinedClothesMdfr);
		Print("m_AcidRainEventPlayerDamage  " + dmg);
		m_Player.AddHealth("GlobalHealth", "Health", dmg);
	}

	protected void ProcessItemsDamageFromAcidRain()
	{
		auto slotIdsComplete 		= new array<int>;		
		slotIdsComplete 		= {
			InventorySlots.HEADGEAR,
			InventorySlots.GLOVES,
			InventorySlots.BODY,
			InventorySlots.LEGS,
			InventorySlots.FEET
		};
		// if item not present, +2x the dmg
		// if item is present but ruined +1x dmg	
		m_AcidRainEventPlayerDamageFromRuinedClothesMdfr = 1;	
		foreach(int slotID : slotIdsComplete)
		{
			EntityAI att = m_Player.GetInventory().FindAttachment( slotID );
			if ( att )
			{
				ItemBase item = ItemBase.Cast(att);
				if (item.GetHealth() <= 0 || item.IsRuined())
				{
					m_AcidRainEventPlayerDamageFromRuinedClothesMdfr++;
				}
			}
			else
			{
				m_AcidRainEventPlayerDamageFromRuinedClothesMdfr+= 2;
			}
		}
		//check for guns?
		//each item attached should take dmg	
		foreach (int slotIdComplete : m_SlotIdsComplete)
		{
			EntityAI attachment = EntityAI.Cast(m_Player.GetInventory().FindAttachment(slotIdComplete));
			if (attachment)				
				attachment.AddHealth( -m_AcidRainEventClothesDamage );
		}

		if (m_Player.GetItemInHands())
		{
			m_Player.GetItemInHands().AddHealth(-m_AcidRainEventClothesDamage);
		}
	}
}; */