class WG_Infected_PumpkinLight extends PointLightBase
{
	void WG_Infected_PumpkinLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo( 5 );
		SetBrightnessTo(2);
		SetCastShadow(false);
		SetFadeOutTime(5);
		SetDiffuseColor(0.0, 0.5, 0.0);
		SetAmbientColor(0.0, 0.5, 0.0);
		SetFlareVisible(false);
		SetFlickerAmplitude(0.3);
		SetFlickerSpeed(0.0001);
		SetDancingShadowsMovementSpeed(0.00001);
		SetDancingShadowsAmplitude(0.00001);
	}
};

class WG_PumpkinLight extends SpotLightBase
{
    void WG_PumpkinLight()
	{
        SetVisibleDuringDaylight(true);
		SetRadiusTo(60);
		SetSpotLightAngle(90);
		SetCastShadow(true);
		SetBrightnessTo(2.0);
		SetFadeOutTime(0.3);
		FadeIn(0.2);
		SetDiffuseColor(1.0, 0.42, 0);
		SetAmbientColor(1.0, 0.42, 0);
    }
};

class WG_Infected_ToxicPumpkin extends ZombieMaleBase
{
    
	WG_Infected_PumpkinLight m_Light;
	
	void WG_Infected_ToxicPumpkin()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			m_Light = WG_Infected_PumpkinLight.Cast( ScriptedLightBase.CreateLight( WG_Infected_PumpkinLight, "0 0 0" ) );
			m_Light.AttachOnMemoryPoint( this, "light" );   
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if (m_Light)
				m_Light.Destroy();
		}
	}
};

class WG_Infected_EvilPumpkin extends ZombieMaleBase
{
	WG_Infected_PumpkinLight m_Light;	
	
	void WG_Infected_EvilPumpkin()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			m_Light = WG_Infected_PumpkinLight.Cast( ScriptedLightBase.CreateLight( WG_Infected_PumpkinLight, "0 0 0" ) );
			m_Light.AttachOnMemoryPoint( this, "light" );  
            m_Light.SetDiffuseColor(1.0, 0.45, 0.25);
		    m_Light.SetAmbientColor(1.0, 0.45, 0.25);          
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if (m_Light)
				m_Light.Destroy();
		}
	}
};

/*
class WG_Infected_PumpkinBoss : ZombieMaleBase
{
    protected float m_Scale = 0.5;
    
    void WG_Infected_PumpkinBoss()
    {
        SetEventMask(EntityEvent.POSTFRAME);
        RegisterNetSyncVariableFloat("m_Scale");
    }

    override void EOnFrame(IEntity other, float timeSlice) // | EntityEvent.FRAME
    {
        vector rotation = GetYawPitchRoll();
        SetYawPitchRoll(Vector(rotation[0], 0, 0));
    }
        
    override void EOnPostFrame(IEntity other, int extra) // | EntityEvent.POSTFRAME
    {
        vector mat[4];
        GetTransform(mat);

        mat[0] = mat[0].Normalized() * m_Scale;
        mat[1] = mat[1].Normalized() * m_Scale;
        mat[2] = mat[2].Normalized() * m_Scale;

        SetTransform(mat);
    }
};


modded class Animal_UrsusArctos
{
    protected float m_Scale = 0.5;
    
    void Animal_UrsusArctos()
    {
        SetEventMask(EntityEvent.POSTFRAME);
        RegisterNetSyncVariableFloat("m_Scale");
		//auto obj = GetGame().CreateObjectEx("BarbedWire", "0 0 0", ECE_PLACE_ON_SURFACE);
		//int headIndex = GetBoneIndexByName("Head");
		//AddChild(obj, headIndex);
    }

    override void EOnFrame(IEntity other, float timeSlice) // | EntityEvent.FRAME
    {
        vector rotation = GetYawPitchRoll();
        SetYawPitchRoll(Vector(rotation[0], 0, 0));
    }
        
    override void EOnPostFrame(IEntity other, int extra) // | EntityEvent.POSTFRAME
    {
        vector mat[4];
        GetTransform(mat);

        mat[0] = mat[0].Normalized() * m_Scale;
        mat[1] = mat[1].Normalized() * m_Scale;
        mat[2] = mat[2].Normalized() * m_Scale;

        SetTransform(mat);
    }
};*/