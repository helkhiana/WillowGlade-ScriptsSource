modded class MissionGameplay 
{
	void MissionGameplay()
	{
		GetRPCManager().AddRPC("WG_Events", "SetClientMissionsProgress", this, SingeplayerExecutionType.Client);
		GetRPCManager().SendRPC("WG_Events", "GetServerMissionsProgress", null, true, null);
	}

	void SetClientMissionsProgress(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        ref Param1<ref WG_MissionsData> data;
        if (type == CallType.Client)
		{
			if (!ctx.Read(data)) return;

			g_Game.Set_ClientMissionsProgress(data.param1);
			Print("[WG_Events] MissionGameplay --> Got instance of player missions progress: " + data.param1);
		}
    }
};