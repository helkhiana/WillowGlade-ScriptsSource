class ToxicSmoke extends House
{
	Particle m_Particle;
	
	void ToxicSmoke()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_Particle = Particle.PlayOnObject(ParticleList.TOXIC_GREENSMOKE, this);
		}
	}
	
	void ~ToxicSmoke()
	{
		if (m_Particle)
			m_Particle.Stop();
	}
};

class WhiteFog extends House
{
	Particle m_Particle;
	
	void WhiteFog()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_Particle = Particle.PlayOnObject(ParticleList.WHITE_FOG, this);
		}
	}
	
	void ~WhiteFog()
	{
		if (m_Particle)
			m_Particle.Stop();
	}
};

class ToxicCloud_Square extends House
{
	Particle m_Particle;
	
	void ToxicCloud_Square()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_Particle = Particle.PlayOnObject(ParticleList.TOXIC_GREENSMOKESQURE, this);
		}
	}
	
	void ~ToxicCloud_Square()
	{
		if (m_Particle)
			m_Particle.Stop();
	}
};

class ToxicCloud_Sphere extends House
{
	Particle m_Particle;
	
	void ToxicCloud_Sphere()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_Particle = Particle.PlayOnObject(ParticleList.TOXIC_GREENSMOKE, this);
		}
	}
	
	void ~ToxicCloud_Sphere()
	{
		if (m_Particle)
			m_Particle.Stop();
	}
};