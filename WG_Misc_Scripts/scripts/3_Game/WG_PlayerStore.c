class WG_Player
{
    string playerName;
    string playerHashId;
    string playerSteamId;
	int playerId;

    void WG_Player(int in_playerId, string in_playerHashId, string in_playerSteamId, string in_playerName)
    {
        playerId = in_playerId;
        playerHashId = in_playerHashId;
        playerSteamId = in_playerSteamId;
        playerName = in_playerName;
    }
};

class WG_PlayerStore
{	
	static const string MODCONFIG_ROOT_FOLDER = "$profile:WillowGlade/PlayerDB/";
    static const string CONFIG_PATH = MODCONFIG_ROOT_FOLDER + "PlayerDB.json";
	
    private ref array<ref WG_Player> players = new ref array<ref WG_Player>;

    void Add(WG_Player player)
    {
        int listIndex = FindIndex(player.playerHashId); 
        if(listIndex == -1)
            players.Insert(player);
        else
            Update(player);

        Save();
    }    

    void Set(ref array<ref WG_Player> players)
    {
        players = players;
        Save();
    }

    void Remove(string id)
    {
        if(!players) return;

        int listIndex = FindIndex(id);
        players.Remove(listIndex);
        Save();
    }
    
    void Update(WG_Player player)
    {
        if(!players) return;

        int listIndex = FindIndex(player.playerHashId);
        players.Remove(listIndex);
        players.Insert(player);        
        Save();
    }

    private int FindIndex(string id)
    {
        foreach(ref WG_Player player : players)
        {
            if(player.playerHashId == id)
                return players.Find(player);
        }
        return -1;
    }

    ref array<ref WG_Player> GetAllPlayers()
    {
        return players;
    }

    ref WG_Player GetPlayer(string id)
    {
        int listIndex = FindIndex(id);
        return players.Get(listIndex);
    }

    int GetPlayerId(string id)
    {
        int listIndex = FindIndex(id);
        return players.Get(listIndex).playerId;
    }

	void WG_PlayerStore()
	{
		if (!GetGame().IsServer()) return;

		if (!FileExist(MODCONFIG_ROOT_FOLDER))
        {
            Print("[MBTerritoryStore] '" + MODCONFIG_ROOT_FOLDER + "' does NOT exist, creating directory!");
            MakeDirectory(MODCONFIG_ROOT_FOLDER);
        }

        if (!FileExist(CONFIG_PATH))
        {
            Print("[MBTerritoryStore] '" + CONFIG_PATH + "' does NOT exist, creating default config!");
            Default();
            return; 
        }

        Load();
    }

	bool Load()
    {
        if (FileExist(CONFIG_PATH))
        {            
            JsonFileLoader<WG_PlayerStore>.JsonLoadFile(CONFIG_PATH, this);
            return true;
        }
        return false;
    }

	protected void Save()
    {        
        JsonFileLoader<WG_PlayerStore>.JsonSaveFile(CONFIG_PATH, this);
    }

	protected void Default()
    {
		Save();
	}
};