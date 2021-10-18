/*modded class MissionBaseWorld
{
    override bool IsAtLantia(vector pos)
    {
        string worldName = "empty";
        GetGame().GetWorldName(worldName);
        worldName.ToLower();
        if (worldName != "namalsk")
            return false;
        return super.IsAtLantia(pos);
    }
};

modded class vfx_lantia_fog
{
    void vfx_lantia_fog()
    {
        string worldName = "empty";
        GetGame().GetWorldName(worldName);
        worldName.ToLower();
        if (worldName != "namalsk")
		    m_particleID = -2;
    }
};

modded class vfx_lantia_portal_atm
{
    void vfx_lantia_portal_atm()
    {
        string worldName = "empty";
        GetGame().GetWorldName(worldName);
        worldName.ToLower();
        if (worldName != "namalsk")
		    m_particleID = -2;
    }
};

modded class PlayerBase
{
    override bool IsAtLantia()
    {
        string worldName = "empty";
        GetGame().GetWorldName(worldName);
        worldName.ToLower();
        if (worldName != "namalsk")
            return false;
        return super.IsAtLantia();
    }

    override void LantiaKillSwitch(float delta)
    {
        string worldName = "empty";
        GetGame().GetWorldName(worldName);
        worldName.ToLower();
        if (worldName != "namalsk")
            return;
        super.LantiaKillSwitch(delta);
    }
}; */