modded class ActionCheckPulse: ActionInteractBase
{
	string m_PlayerName = "Person";
	
	override string GetText()
	{
		return "Check " + m_PlayerName + "'s Pulse";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PlayerBase ntarget = PlayerBase.Cast(  target.GetObject() );
		if( ntarget && ntarget.IsAlive() && !ntarget.GetType().Contains("NPC"))
		{
			m_PlayerName = ntarget.GetPlayerName();
			return true;
		}
		return false;
	}
};