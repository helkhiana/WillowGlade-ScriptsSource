modded class DayZGame
{
    private ref PF_Config m_PFConfig;

    PF_Config GetPF_Config()
    {
        if (!m_PFConfig)
        {
            SetPF_Config(new PF_Config);
        }
        
	    return m_PFConfig;
    }

    void SetPF_Config(PF_Config config)
	{
		m_PFConfig = config;
	}
};