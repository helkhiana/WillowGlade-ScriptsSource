modded class MissionGameplay {	
	protected int m_AutoRunJogMode = 0;
	protected int m_AutoRunJogState = 0;

	static bool SHIFT()
	{
		return( ( KeyState( KeyCode.KC_LSHIFT ) > 0 ) || ( KeyState( KeyCode.KC_RSHIFT ) > 0 ) );
	}

	static bool CTRL()
	{
		return( ( KeyState( KeyCode.KC_LCONTROL ) > 0 ) || ( KeyState( KeyCode.KC_RCONTROL ) > 0 ) );
	}
	
	static bool BreakOff()
	{
		return( ( KeyState( KeyCode.KC_W ) > 0 ) || ( KeyState( KeyCode.KC_A ) > 0 ) || ( KeyState( KeyCode.KC_S ) > 0 ) || ( KeyState( KeyCode.KC_D ) > 0 ));
	}

	void SwitchAutoRunJogMode(PlayerBase playerPB)
    {
        if( m_AutoRunJogMode && !SHIFT() && !CTRL() )
        {
            m_AutoRunJogMode = 0;
        }
        else
        {
            if( SHIFT() )
            {
                m_AutoRunJogMode = 3;
            }
            else if( CTRL() )
            {
                m_AutoRunJogMode = 1;
            }
            else
            {
                m_AutoRunJogMode = 2;
            }

			if(playerPB.GetInputController().LimitsIsSprintDisabled())
			{				
                m_AutoRunJogMode = 2;
			}
        }
		
		m_AutoRunJogState = m_AutoRunJogMode;
    }

    void UpdateAutoRunJogRun(PlayerBase playerPB, bool active = false)
    {
		if(m_AutoRunJogMode == 0 || !active)
		{			
			SetAutoRunJogState( playerPB, false, m_AutoRunJogMode, 0 );
		}
		else
		{
			SetAutoRunJogState( playerPB, true, m_AutoRunJogMode, 1 );
		}
    }

	bool UpdateState(PlayerBase playerPB)
	{
		if ( playerPB.IsUnconscious() || playerPB.IsDamageDestroyed()) 
		{
			m_AutoRunJogMode = 0;
			return true;
		}

		//if anything happens like running out of stamina (put 5 threshold because of vanilla bug) it will go into jog
		if ( playerPB.GetInputController().LimitsIsSprintDisabled() || !playerPB.CanSprint() && m_AutoRunJogMode > 2 || playerPB.GetStaminaHandler().GetStamina() < 5) 
		{
			m_AutoRunJogMode = 2;
			return true;
		}
		
		//when stamina is back or player can sprint again, restore to sprint state if we were in sprint state before
		if ( !playerPB.GetInputController().LimitsIsSprintDisabled() && playerPB.CanSprint() && playerPB.GetStaminaHandler().GetStamina() > playerPB.GetStaminaHandler().GetStaminaCap()/3) 
		{
			m_AutoRunJogMode = m_AutoRunJogState;
			return true;
		}

		return false;
	}

	bool IsChatMenuOpen()
	{
		return GetGame().GetUIManager().IsMenuOpen( MENU_CHAT_INPUT );
	}

	void SetAutoRunJogState( PlayerBase playerPB, bool state, float speed = 0, float angle = 0 ) 
	{
		playerPB.GetInputController().OverrideMovementSpeed( state, speed );
		playerPB.GetInputController().OverrideMovementAngle( state, angle );
		GetRPCManager().SendRPC( "WG_AutoRunJog", "SwitchAutoRunJogMode", new Param4< Man, bool, float, float > ( playerPB, state, speed, angle ) ); 
	}	

	override void OnUpdate( float timeslice ) 
	{
		super.OnUpdate( timeslice );
		PlayerBase playerPB = PlayerBase.Cast(GetGame().GetPlayer());
		Input input = GetGame().GetInput();

		if (playerPB) {
			if ( input.LocalPress( "ToggleAutoRunJog" ) && !IsChatMenuOpen()) 
			{
				SwitchAutoRunJogMode(playerPB);
				UpdateAutoRunJogRun(playerPB, true);
				m_AutoRunJogState = m_AutoRunJogMode;
			}
			if(m_AutoRunJogState > 0)
			{
				if(UpdateState(playerPB))
				{
					UpdateAutoRunJogRun(playerPB, true);
				}
				if(BreakOff() && !IsChatMenuOpen() && m_AutoRunJogState > 0 || !playerPB.IsAlive() || playerPB.IsUnconscious())
				{
					UpdateAutoRunJogRun(playerPB,false);
					m_AutoRunJogState = 0;
				}
			}
		}
	}
};