modded class IngameHud
{
	private TextWidget m_Clock = NULL;
	private Widget m_ClockIconPanel = NULL;
	private Widget m_ClockWidget = NULL;
	private bool m_ClockShow = false;

	override void Init(Widget hud_panel_widget)
	{
		super.Init(hud_panel_widget);
		Widget hudpanel = m_HudPanelWidget.FindAnyWidget("HudPanel");
		m_ClockWidget = GetGame().GetWorkspace().CreateWidgets("WillowGlade/WG_GUI/gui/layouts/clock.layout", hudpanel);
		Class.CastTo(m_Clock, m_ClockWidget.FindAnyWidget("ClockText"));
		m_ClockWidget.Show(false);
	}

	override void SetClockTime(string time)
	{
		if (m_Clock)
			m_Clock.SetText(time);		
	}

	override void ToggleClockLayout(bool show)
	{
		if (m_ClockWidget)
			m_ClockWidget.Show(((!m_HudHidePlayer && !m_HudHideUI && m_HudState ) || m_HudInventory) && show);
		
		m_ClockShow = show;
	}

	override void RefreshHudVisibility()
	{
		super.RefreshHudVisibility();
		m_ClockWidget.Show(((!m_HudHidePlayer && !m_HudHideUI && m_HudState ) || m_HudInventory) && m_ClockShow);
	}
};