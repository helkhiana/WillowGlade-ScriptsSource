modded class PluginPlayerStatus
{
	void SetTiredness(int value , int range)
	{
		Mission mission = GetGame().GetMission();
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
			{
				hud.SetTiredness(Math.Clamp(value, 0, range), range);
			}
		}
	}

	void ShowTiredness(bool value)
	{
		Mission mission = GetGame().GetMission();
		if (mission)
		{
			Hud hud = mission.GetHud();
			if (hud)
				hud.ShowTiredness(value);
		}
	}
}