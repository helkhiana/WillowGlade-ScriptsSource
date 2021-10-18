modded class PlayerBase
{
	protected ref LocalParticleVFX m_LocalParticleVFX;
	protected ref UndergroundVFX m_UndergroundVFX;

	override void Init()
	{	
		super.Init();

		if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() )
		{
			m_LocalParticleVFX = new LocalParticleVFX( this );
			string worldName = "empty";
			GetGame().GetWorldName( worldName );
			worldName.ToLower();
			if ( worldName == "namalsk" )
			{
				m_UndergroundVFX = new UndergroundVFX( this );
			}
			if ( worldName == "chernarusplus" )
			{
				//Print("ChernarusPlus no tunnel");
			}
		}
	}

	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();

		if ( m_Hud && IsControlledPlayer() )
		{
			PPEffects.SetEyeAccUnderground( 1.0 );
		}
	}

	override void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)	
	{	
		super.CommandHandler( pDt, pCurrentCommandID, pCurrentCommandFinished );
	
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT || !GetGame().IsMultiplayer() )
		{
			if ( m_LocalParticleVFX )
			{
				m_LocalParticleVFX.ParticleTimeUpdate( pDt );
			}
			if ( m_UndergroundVFX )
			{
				m_UndergroundVFX.UndergroundTimeUpdate( pDt );
			}
		}
	}

	override void UpdateColdResistance( float coldresist )
	{
		if(g_Game.GetWorldName() == "chernarusplus")
            coldresist = coldresist / 4;
		GetStatColdResistance().Add( coldresist );
		m_ColdResistance = (int) ( GetStatColdResistance().Get() * 10000 );
		SetSynchDirty();
	}
};