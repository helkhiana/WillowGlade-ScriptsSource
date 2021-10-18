class PF_Config
{	
	static const string CONFIG_ROOT = "$profile:WillowGlade/";
    static const string FULLPATH = "$profile:WillowGlade/PerishableFood.json";

	int version;
	float FridgeConservationMultiplier;
	ref array<string> FridgeClasses = NULL;

	void PF_Config()
	{
		if (!GetGame().IsServer()) return;
		
		if (!FileExist(CONFIG_ROOT))
        {
            Print("[PF_Config] '" + CONFIG_ROOT + "' does NOT exist, creating directory!");
            MakeDirectory(CONFIG_ROOT);
        }

        if (!FileExist(FULLPATH))
        {
            Print("[PF_Config] '" + FULLPATH + "' does NOT exist, creating default config!");
            Default();
            return; 
        }

        Load();
    }

	void Load()
    {
		Print("[PF_Config] '" + FULLPATH + "' found, loading existing config!");
		JsonFileLoader<PF_Config>.JsonLoadFile(FULLPATH, this);
		VersionChecker();
    }

	void VersionChecker()
	{
		if(!version)
		{
			version = 1;
			FridgeConservationMultiplier = 3;
			FridgeClasses = new array<string>;
			FridgeClasses.Insert("Msp_Fridge_Base");
			Save();
		}
	}

	protected void Save()
    {
        JsonFileLoader<PF_Config>.JsonSaveFile(FULLPATH, this);
    }

	protected void Default()
    {
		version = 1;
		FridgeConservationMultiplier = 3;
		FridgeClasses = new array<string>;
		FridgeClasses.Insert("Msp_Fridge_Base");
		Save();
	}

	float Get_FridgeConservationMultiplier()
	{
		return FridgeConservationMultiplier;
	}

	array<string> Get_FridgeClasses()
	{
		return FridgeClasses;
	}
};