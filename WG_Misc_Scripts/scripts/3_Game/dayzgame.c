modded class DayZGame
{
    private ref WG_PlayerStore m_PlayerStore;

    ref WG_PlayerStore Get_PlayerStore()
    {
        if (!m_PlayerStore)
        {
            Set_PlayerStore(new WG_PlayerStore);
        }
	    return m_PlayerStore;
    }

    ref WG_PlayerStore Reload_PlayerStore()
    {
        if (!m_PlayerStore)
        {
            Set_PlayerStore(new WG_PlayerStore);
        }
        m_PlayerStore.Load();
	    return m_PlayerStore;
    }

    void Set_PlayerStore(WG_PlayerStore config)
	{
		m_PlayerStore = config;
	}
};