modded class PlayerBase
{
    int m_WGPlayerId;

    void PlayerBase()
    {
        RegisterNetSyncVariableInt("m_WGPlayerId");
    }

    int GetWGPlayerId()
    {
        if (!m_WGPlayerId && GetGame().IsServer())
        {
            m_WGPlayerId = g_Game.Reload_PlayerStore().GetPlayerId(GetIdentity().GetId());
            SetSynchDirty();
        }
        else if (!m_WGPlayerId && GetGame().IsClient())
        {
            m_WGPlayerId = g_Game.Get_PlayerStore().GetPlayerId(GetIdentity().GetId());
        }
        return m_WGPlayerId;
    }

    void SetWGPlayerId(int id)
    {
        m_WGPlayerId = id;
        if (GetGame().IsServer())
            SetSynchDirty();
    }

    void SetUnconsciousState(bool state)
    {
        m_IsUnconscious = state;
    }

    string GetPlayerName()
    {
        auto identity = GetIdentity();
        if (!identity)
            return "John Doe";
        string name = GetIdentity().GetName();
        if (name == string.Empty)
            return "John Doe";
        return name;
    }

    override void SetActions(out TInputActionMap InputActionMap)
    {
        super.SetActions(InputActionMap);
        AddAction(ActionSearchForScraps, InputActionMap);
    }
};