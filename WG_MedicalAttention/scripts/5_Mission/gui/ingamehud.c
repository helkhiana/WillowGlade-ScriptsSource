modded class IngameHud
{
	private ProgressBarWidget m_Tiredness = NULL;
	private Widget m_TirednessIconPanel = NULL;
	private Widget m_TirednessWidget = NULL;
	private bool m_TirednessToggle = false;

	override void Init(Widget hud_panel_widget)
	{
		super.Init(hud_panel_widget);
		Widget leftpanel = m_HudPanelWidget.FindAnyWidget("LeftHUDPanel");
		m_TirednessWidget = GetGame().GetWorkspace().CreateWidgets("WillowGlade/WG_MedicalAttention/layout/tiredness.layout", leftpanel);
		Class.CastTo(m_Tiredness, m_TirednessWidget.FindAnyWidget("TirednessBar"));
		m_TirednessWidget.Show(m_TirednessToggle);
	}

	override void SetTiredness(int value, int range)
	{
		if (m_Tiredness)
			m_Tiredness.SetCurrent((value / range) * 100);
	}

	override void ShowTiredness(bool value)
	{
		if (m_TirednessWidget)
		{
			m_TirednessWidget.Show(value);
			m_TirednessToggle = value;
		}
	}

	override void ShowVehicleInfo()
	{
		super.ShowVehicleInfo();
		if (m_TirednessWidget)
			m_TirednessWidget.Show(false);
	}

	override void HideVehicleInfo()
	{
		super.HideVehicleInfo();

		if (m_TirednessWidget)
			m_TirednessWidget.Show(m_TirednessToggle);
	}
};