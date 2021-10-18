modded class DayZPlayerImplement extends ManBase 
{	
	override void RegisterTransportHit(Transport transport)
	{
		if( !m_TransportHitRegistered )
		{	
			m_TransportHitRegistered = true; 
			m_TransportHitVelocity = GetVelocity(transport);

			if (IsDamageDestroyed() && m_TransportHitVelocity.Length() > 0.5)
			{
				vector impulse = 40 * m_TransportHitVelocity;
				impulse[1] = 40 * 1.5;
				dBodyApplyImpulse(this, impulse);
                return;
			}

            m_TransportHitRegistered = false;
		}
	}
};