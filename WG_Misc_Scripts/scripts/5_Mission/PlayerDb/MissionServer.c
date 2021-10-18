modded class MissionServer
{
    private ref WG_PlayerStore m_PlayerStore;

    void MissionServer()
    {
        GetRPCManager().AddRPC("WG_Misc", "GetServerPlayerStore", this, SingeplayerExecutionType.Server);
    }

    override void OnInit()
    {
        super.OnInit();       
        m_PlayerStore = new WG_PlayerStore;
        g_Game.Set_PlayerStore(m_PlayerStore);
    }
    
    void GetServerPlayerStore(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type == CallType.Server && sender != null)
        {
            Print("[WG_Misc] MissionServer --> Sending instance of playerDB to client: " + sender.GetName());
            string senderID = sender.GetId();
            if(!m_PlayerStore.GetPlayer(senderID))
            {
                WG_Player newPlayer = new WG_Player(senderID.Hash(), senderID, sender.GetPlainId(), sender.GetName());
                m_PlayerStore.Add(newPlayer);
            }
            
            GetRPCManager().SendRPC("WG_Misc", "ClientSynchPlayerStore", new Param1<ref WG_PlayerStore>( m_PlayerStore ), true, sender);
        }
    }
};