class WG_LS_LootGroups
{
	int minLoot;
	int maxLoot;
	bool allowDuplicates;
	int chanceOfLoot;
    ref array<string> loot;
};

class WG_LS_Position
{
	vector position;
	vector orientation;

	void WG_LS_Position(vector pos, vector ori)
	{
		position = pos;
		orientation = ori;
	}
};

class WG_LS_LootCrate
{
	bool isActive;
	string classname;
	int nominal;
	int min;
	int playersaferadius;
	int distanceradius;
	int chanceOfLoot;
	int MaxLifetime;
	int MaxLifetimeInteraction;
    ref array<ref WG_LS_LootGroups> lootGroups;
	ref array<ref WG_LS_Position> lootLocations;
	private ref array<string> lootLocationsString;

	void TransformLocations()
	{
		foreach(string loc : lootLocationsString)
		{
			TStringArray locArray = new TStringArray;
			loc.Split( "|", locArray );
			string position = locArray.Get(0);
			string orientation = locArray.Get(1);
			WG_LS_Position pos = new WG_LS_Position(position.ToVector(), orientation.ToVector());
			lootLocations.Insert(pos);
		}
	}
};

class WG_LS_Config
{	
	static const string CONFIG_ROOT = "$profile:WillowGlade/LootCrates";
    static const string FULLPATH = "$profile:WillowGlade/LootCrates_Config.json";

	private int version;
	private int restockInterval;
    private ref array<ref WG_LS_LootCrate> lootCrates;
    private ref array<string> lootCratesList;

	void WG_LS_Config()
	{
		if (!GetGame().IsServer()) return;
		
		if (!FileExist(CONFIG_ROOT))
        {
            Print("[WG_LS_Config] '" + CONFIG_ROOT + "' does NOT exist, creating directory!");
            MakeDirectory(CONFIG_ROOT);
        }

        if (!FileExist(FULLPATH))
        {
            Print("[WG_LS_Config] '" + FULLPATH + "' does NOT exist, creating default config!");
            Default();
            return; 
        }

        Load();
    }

	void Load()
    {
		JsonFileLoader<WG_LS_Config>.JsonLoadFile(FULLPATH, this);
		foreach(string fileName : lootCratesList)
		{
			ref WG_LS_LootCrate lC = new ref WG_LS_LootCrate;
			string pathToFile = CONFIG_ROOT + "/" + fileName + ".json";
			JsonFileLoader<WG_LS_LootCrate>.JsonLoadFile(pathToFile, lC);
			if(!lootCrates)
				lootCrates = new array<ref WG_LS_LootCrate>;
			lC.TransformLocations();
			lootCrates.Insert(lC);
		}
    }

	protected void Save()
    {
        JsonFileLoader<WG_LS_Config>.JsonSaveFile(FULLPATH, this);
    }

	protected void Default()
    {
		version = 1;
		restockInterval = 1800;
		lootCrates = new ref array<ref WG_LS_LootCrate>;
		Save();
	}

	ref array<ref WG_LS_LootCrate> Get_LootArray()
	{		
		return lootCrates;
	}

	ref WG_LS_LootCrate Get_LootCrate(string name)
	{
		foreach(ref WG_LS_LootCrate lootcrateI : lootCrates)
		{
			if(lootcrateI.classname == name)
				return lootcrateI;
		}
		return null;
	}

	void PrintConfig()
	{
		Print("lootCrates " + lootCrates);
		Print("lootCrates.Count() " + lootCrates.Count());
		foreach(WG_LS_LootCrate lootcrateI : lootCrates)
		{
			Print("lootcrateI " + lootcrateI);
			Print("lootcrateI.classname " + lootcrateI.classname);
			Print("lootcrateI.chanceOfLoot " + lootcrateI.chanceOfLoot);
			Print("lootcrateI.lootGroups " + lootcrateI.lootGroups);			
		}
	}

	int Get_MaxLifetimeForCrateType(string name)
	{
		return Get_LootCrate(name).MaxLifetime;
	}
	int Get_MaxLifetimeInteractionForCrateType(string name)
	{
		return Get_LootCrate(name).MaxLifetimeInteraction;
	}

	int GetRestockInterval()
	{
		return restockInterval;
	}
};