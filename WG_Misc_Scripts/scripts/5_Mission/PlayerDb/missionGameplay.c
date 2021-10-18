modded class MissionGameplay 
{
    private ref WG_PlayerStore m_TerritoryConfig;

	void MissionGameplay()
	{
		GetRPCManager().AddRPC("WG_Misc", "ClientSynchPlayerStore", this, SingeplayerExecutionType.Client);
		GetRPCManager().SendRPC("WG_Misc", "GetServerPlayerStore", null, true, null);
	}

	void ClientSynchPlayerStore(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        ref Param1<ref WG_PlayerStore> data;
        if (type == CallType.Client)
		{
			if (!ctx.Read(data)) return;

			g_Game.Set_PlayerStore(data.param1);
			Print("[WG_Misc] MissionGameplay --> Got instance of playerDB: " + data.param1);
		}
    }
};