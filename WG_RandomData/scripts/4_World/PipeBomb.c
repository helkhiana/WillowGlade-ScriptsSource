class WG_PipeBomb_Base extends Grenade_Base
{
	const string SOUND_LOOP = "roadflareLoop_SoundSet";
	Particle m_Particle;
	EffectSound m_Sound;
	void WG_PipeBomb_Base()
	{
		SetFuseDelay(10);
		SetParticleExplosion(ParticleList.RGD5);
		SetParticlePosition("0 0.1 0");
	}

	void PlayParticleEffect()
	{
		m_Particle = Particle.PlayOnObject(ParticleList.WG_PIPEBOMB_SPARKLES, this, GetMemoryPointPos("light"), vector.Zero, true);
		m_Particle.SetWiggle(7, 0.3);
	}

	void StartEffects()
	{
		PlaySoundSetLoop(m_Sound, SOUND_LOOP, 0.3, 1.0);
		PlayParticleEffect();
	}
	override void OnUnpin()
	{
		m_Pinned = false;		
		if ( GetGame().IsServer() )
		{
			SetSynchDirty();
		}
		Activate();
	}

	override void OnActivateFinished()
	{
		if (GetGame().IsServer())
		{
			SetHealth("", "", 0.0);
			SetTakeable(false);
		}
	}
	
	override void OnExplosionEffects(Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, float energyFactor, float explosionFactor, bool isWater, string ammoType)
	{
		super.OnExplosionEffects(source, directHit, componentIndex, surface, pos, surfNormal, energyFactor, explosionFactor, isWater, ammoType);		
		StopSoundSet(m_Sound);
		m_Particle.Stop();
		GetGame().ObjectDelete(m_Particle);
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionLightPipeBomb);
		RemoveAction(ActionUnpin);
		RemoveAction(ActionPin);
	}
};

class WG_PipeBomb extends WG_PipeBomb_Base
{	
	void WG_PipeBomb()
	{
		SetAmmoType("PipeBomb_Ammo");
	}
};

class WG_PipeBomb_Bundle extends WG_PipeBomb_Base
{	
	void WG_PipeBomb_Bundle()
	{
		SetAmmoType("PipeBombBundle_Ammo");
	}
};