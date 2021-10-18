/* modded class ZombieMaleBase extends ZombieBase
{    
	protected Particle 			m_ParInitialFire;
	
	void ZombieMaleBase()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//m_Light = WG_Infected_PumpkinLight.Cast( ScriptedLightBase.CreateLight( WG_Infected_PumpkinLight, "0 0 0" ) );
			//m_Light.AttachOnMemoryPoint( this, "light" );   
			m_ParInitialFire = Particle.PlayInWorld( ParticleList.INFECTED_SPARKS_BLUE, "0 0 0");
			int headIndex = GetBoneIndexByName("Head");  
        	AddChild(m_ParInitialFire, headIndex);
		}
	}
};

modded class ZmbF_CitizenANormal_Base extends ZombieFemaleBase
{    
	protected Particle 			m_ParInitialFire;
	
	void ZmbF_CitizenANormal_Base()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{ 
			m_ParInitialFire = Particle.PlayInWorld( ParticleList.INFECTED_SPARKS_RED, "0 0 0");
			int headIndex = GetBoneIndexByName("Head");
        	AddChild(m_ParInitialFire, headIndex);
		}
	}
}; */