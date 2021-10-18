class MABloodTestReport
{
	static void DisplayReport(PlayerBase player, PlayerBase target)
	{
		EStatLevels immunityLevel = target.GetImmunityLevel();
		string immunityLevelStr;
		switch (immunityLevel)
		{
			case EStatLevels.GREAT: immunityLevelStr = "GREAT"; break;
			case EStatLevels.HIGH: immunityLevelStr = "HIGH"; break;
			case EStatLevels.MEDIUM: immunityLevelStr = "MEDIUM"; break;
			case EStatLevels.LOW: immunityLevelStr = "LOW"; break;
			case EStatLevels.CRITICAL: immunityLevelStr = "CRITICAL"; break;
		}
		SendMessageToClient(player, "Medical Report:");
		SendMessageToClient(player, "Immunity Level: " + immunityLevelStr);
		SendMessageToClient(player, "Alcohol: " + target.GetSingleAgentCount(MedicalAttentionAgents.DRUNKENNESS).ToString());
		SendMessageToClient(player, "Cholera: " + target.GetSingleAgentCount(eAgents.CHOLERA).ToString());
		SendMessageToClient(player, "Salmonella: " + target.GetSingleAgentCount(eAgents.SALMONELLA).ToString());
		SendMessageToClient(player, "Influenza: " + target.GetSingleAgentCount(eAgents.INFLUENZA).ToString());
		SendMessageToClient(player, "Food Poison: " + target.GetSingleAgentCount(eAgents.FOOD_POISON).ToString());
		SendMessageToClient(player, "Wound Infection: " + target.GetSingleAgentCount(eAgents.WOUND_AGENT).ToString());
		SendMessageToClient(player, "Chemical Exposure: " + target.GetSingleAgentCount(eAgents.CHEMICAL_POISON).ToString());
	}

	
	private static void SendMessageToClient(Object reciever, string message)
	{
		PlayerBase man;
		if (GetGame().IsServer() && Class.CastTo(man, reciever) && reciever.IsAlive() && message != "")
		{
			Param1<string> m_TirednessReportParam = new Param1<string>("");
			m_TirednessReportParam.param1 = message;
			GetGame().RPCSingleParam(man, ERPCs.RPC_USER_ACTION_MESSAGE, m_TirednessReportParam, true, man.GetIdentity());
		}
	}
}

modded class ActionTestBloodSelf
{
	override void OnFinishProgressServer(ActionData action_data)
	{	
		super.OnFinishProgressServer(action_data);

		if (MAGlobals.Get().g_TestBloodSelf)
		{
			MABloodTestReport.DisplayReport(action_data.m_Player, action_data.m_Player);
		}
	}
}