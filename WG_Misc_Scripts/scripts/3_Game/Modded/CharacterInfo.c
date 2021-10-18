modded class DayZGame extends CGame
{	
	void DayZGame()
	{
		CreateCharactersList();		
	}

	void CreateCharactersList()
	{
		string path = "cfgVehicles";
		string child_name = "";
		int count = ConfigGetChildrenCount ( path );
		if(m_CharClassNames != null || m_CharClassNames.Count() > 0)
			m_CharClassNames.Clear();
		
		for (int p = 0; p < count; p++)
		{
			ConfigGetChildName ( path, p, child_name );
			
			if(ConfigGetInt(path + " " + child_name + " scope") == 2 && IsKindOf(child_name,"SurvivorBase") && !child_name.Contains("WG"))
			{
				m_CharClassNames.Insert(child_name);
			}
		}
	}
};