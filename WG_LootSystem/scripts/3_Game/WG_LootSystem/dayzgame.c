modded class DayZGame
{
    private ref WG_LS_Config m_WGLSConfig;

    ref WG_LS_Config GetWG_LS_Config()
    {
        if (!m_WGLSConfig)
        {
            SetWG_LS_Config(new WG_LS_Config);
        }
        
	    return m_WGLSConfig;
    }

    void SetWG_LS_Config(WG_LS_Config config)
	{
		m_WGLSConfig = config;
	}
};