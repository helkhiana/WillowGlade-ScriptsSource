modded class PluginManager
{
    override void Init()
    {
        super.Init();
        
        string worldName = "empty";
        GetGame().GetWorldName(worldName);
        worldName.ToLower();
        if (worldName != "chernarusplus")
            return;
        RegisterPlugin("WG_LS_Manager", false, true);
    }
};

