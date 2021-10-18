modded class DayZGame
{
    private bool m_AcceptedTerms;
    protected ref FileSerializer m_WillowGladeData;

    private const string _WillowGladeSavePath = "$profile:WillowGlade.bin";


    void LoadWillowGladeClientData()
    {
        m_WillowGladeData = new FileSerializer();
        if (!FileExist(_WillowGladeSavePath))
        {
            m_AcceptedTerms = false;
            SaveWillowGladeClientData();
        }

        if (m_WillowGladeData.Open(_WillowGladeSavePath, FileMode.READ))
        {
            m_WillowGladeData.Read(m_AcceptedTerms);
            m_WillowGladeData.Close();
        }
    }

    void SaveWillowGladeClientData()
    {
        if (m_WillowGladeData.Open(_WillowGladeSavePath, FileMode.WRITE))
        {
            m_WillowGladeData.Write(m_AcceptedTerms);
            m_WillowGladeData.Close();
        }
    }

    bool HasAcceptedTerms()
    {
        return m_AcceptedTerms;
    }
    
    void AcceptTerms()
    {
        m_AcceptedTerms = true;
        SaveWillowGladeClientData();
    }
};