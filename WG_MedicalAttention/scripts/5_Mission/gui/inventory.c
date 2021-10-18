modded class Inventory
{
	void Inventory( LayoutHolder parent )
	{
		float m_SpecializationPanelX;
		float m_SpecializationPanelY;
		m_SpecializationPanel.GetPos(m_SpecializationPanelX,m_SpecializationPanelY);
		m_SpecializationPanel.SetPos(m_SpecializationPanelX, m_SpecializationPanelY + 40);
		#ifdef NAMALSK_SURVIVAL
			if(m_ColdResistPanel)
			{				
				float m_ColdResistancePanelX;
				float m_ColdResistancePanelY;
				m_ColdResistPanel.GetPos(m_ColdResistancePanelX, m_ColdResistancePanelY);
				m_ColdResistPanel.SetPos(m_ColdResistancePanelX, m_ColdResistancePanelY + 45);
			}
		#endif
	}

	override void UpdateSpecialtyMeter()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player && player.GetSoftSkillsManager() )
		{
			float x = player.GetSoftSkillsManager().GetSpecialtyLevel() / 2;
			float y = -0.75;
			m_SpecializationIcon.SetPos( x, y, true );	
		}		
	}
};