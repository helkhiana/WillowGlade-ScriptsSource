modded class ZombieBase extends ManBase 
{	
	int dmgReduction = 6;
	override void RegisterTransportHit(Transport transport)
	{
		if ( !m_TransportHitRegistered )
		{	
			m_TransportHitRegistered = true; 
			m_TransportHitVelocity = GetVelocity(transport);
			Car car;
			float damage;
			vector impulse;			
			if ( car.CastTo(car, transport) )
			{
				if ( car.GetSpeedometer() > 2 )
				{
					damage = m_TransportHitVelocity.Length();
					ProcessDirectDamage( DT_CUSTOM, transport, "", "TransportHit", "0 0 0", damage / dmgReduction);
				}
				else
				{
					m_TransportHitRegistered = false;
				}
				if ( IsDamageDestroyed() && car.GetSpeedometer() > 3 )
				{
					impulse = 40 * m_TransportHitVelocity;
					impulse[1] = 40 * 1.5;
					dBodyApplyImpulse(this, impulse);
				}
			}			
			else
			{
				if ( m_TransportHitVelocity.Length() > 0.5 )
				{
					damage = m_TransportHitVelocity.Length();
					ProcessDirectDamage( DT_CUSTOM, transport, "", "TransportHit", "0 0 0", damage / dmgReduction);
				}
				else
				{
					m_TransportHitRegistered = false;
				}

				if ( IsDamageDestroyed() && m_TransportHitVelocity.Length() > 0.5 )
				{
					impulse = 40 * m_TransportHitVelocity;
					impulse[1] = 40 * 1.5;
					dBodyApplyImpulse(this, impulse);
				}
			}
		}
	}
};

modded class AnimalBase extends DayZAnimal
{
	int dmgReduction = 6;
	override void RegisterTransportHit(Transport transport)
	{
		if ( !m_TransportHitRegistered )
		{	
			m_TransportHitRegistered = true; 
			m_TransportHitVelocity = GetVelocity(transport);
			Car car;
			float damage;
			vector impulse;			
			if ( car.CastTo(car, transport) )
			{
				if ( car.GetSpeedometer() > 2 )
				{
					damage = m_TransportHitVelocity.Length();
					ProcessDirectDamage( DT_CUSTOM, transport, "", "TransportHit", "0 0 0", damage / dmgReduction);
				}
				else
				{
					m_TransportHitRegistered = false;
				}
				if ( IsDamageDestroyed() && car.GetSpeedometer() > 3 )
				{
					impulse = 40 * m_TransportHitVelocity;
					impulse[1] = 40 * 1.5;
					dBodyApplyImpulse(this, impulse);
				}
			}			
			else
			{
				if ( m_TransportHitVelocity.Length() > 0.5 )
				{
					damage = m_TransportHitVelocity.Length();
					ProcessDirectDamage( DT_CUSTOM, transport, "", "TransportHit", "0 0 0", damage / dmgReduction);
				}
				else
				{
					m_TransportHitRegistered = false;
				}

				if ( IsDamageDestroyed() && m_TransportHitVelocity.Length() > 0.5 )
				{
					impulse = 40 * m_TransportHitVelocity;
					impulse[1] = 40 * 1.5;
					dBodyApplyImpulse(this, impulse);
				}
			}
		}
	}
};