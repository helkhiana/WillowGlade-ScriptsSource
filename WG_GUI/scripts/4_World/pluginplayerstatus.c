modded class PluginPlayerStatus
{
	void SetClockTime(string time)
	{
		Mission mission = GetGame().GetMission();
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.SetClockTime(time);
		}
	}

	void ToggleClockLayout(bool show)
	{
		Mission mission = GetGame().GetMission();
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.ToggleClockLayout(show);
		}
	}	
};