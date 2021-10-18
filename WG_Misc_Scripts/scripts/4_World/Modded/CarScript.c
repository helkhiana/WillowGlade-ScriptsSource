modded class CarScript
{
	override void OnContact( string zoneName, vector localPos, IEntity other, Contact data )
	{
		if ( zoneName == "" )
		{
			Print("CarScript >> ERROR >> OnContact dmg zone not defined!");
			return;
		}
		
		if ( GetGame().IsServer() && zoneName != "")
		{
			float dmgMin = 150.0;	
			float dmgThreshold = 750.0;
			float dmgKillCrew = 3000.0;
			float dmg = data.Impulse * m_dmgContactCoef / 3;

			if ( dmg < dmgThreshold )
			{					
				if ( dmg > dmgMin )
				{					
					AddHealth( zoneName, "Health", -dmg);
					SynchCrashLightSound( true );
				}
			}
			else
			{				
				for( int i =0; i < CrewSize(); i++ )
				{
					Human crew = CrewMember( i );
					if ( !crew )
						continue;

					PlayerBase player;
					if ( Class.CastTo(player, crew ) )
					{
						if ( dmg > dmgKillCrew )
						{
							player.SetHealth("","Shock",0);
						}
						else
						{
							//deal shock to player
							float shockTemp = Math.InverseLerp(dmgThreshold, dmgKillCrew, dmg);
							float shock = Math.Lerp( 50, 100, shockTemp );
							player.AddHealth("", "Shock", -shock );
						}
					}
				}
				SynchCrashHeavySound( true );
				ProcessDirectDamage( DT_CUSTOM, null, zoneName, "EnviroDmg", "0 0 0", dmg );
			}
		}
		UpdateHeadlightState();
		UpdateLights();
	}
};