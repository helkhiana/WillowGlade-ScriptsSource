class RegisteredPlayersThatDied
{
    string playerId;
    vector positionOfBody;
    bool teleported;
    bool isAlive;
};

modded class DayZGame
{    
    private ref HalloweenEvent m_HalloweenEvent;
    private int m_HalloweenLastEvent = -1;
    private int m_HalloweenRegisterEventTime = -1;
    private bool m_HalloweenRegisterEventGateOpenable = true;
    private bool m_HalloweenWave1EventGateOpenable = true;
    private bool m_ShouldCheckHE = false;
    private bool m_ShouldCheckHEDeadBodies = false;
    private ref array<ref RegisteredPlayersThatDied> m_RegisteredPlayersThatDied = new array<ref RegisteredPlayersThatDied>;

    ref HalloweenEvent GetHalloweenEvent()
    {
        if (!m_HalloweenEvent)
        {
            Print("[WG_DEBUG][Halloween] - ERROR FINDING HALLOWEEN EVENT");
        }
        
	    return m_HalloweenEvent;
    }

    void RegisterHalloweenEvent(Building building, int doorIndex)
	{
        if(m_HalloweenEvent)
            return;
        if(HalloweenEventCanBeStarted())
		{
            Print("[WG_DEBUG][Halloween] - Registering event");
            m_HalloweenEvent = new ref HalloweenEvent();
            m_HalloweenEvent.AssignBuilding(building, doorIndex);
            m_ShouldCheckHE = true;
            m_HalloweenRegisterEventTime = JMDate.Now(false).GetTimestamp();
        }
	}
    
    void RegisterHalloweenEventAdmin()
	{
        if(m_HalloweenEvent)
            StopHalloweenEvent();
        Print("[WG_DEBUG][Halloween] - Admin Registering event");
        m_HalloweenEvent = new ref HalloweenEvent();
        m_ShouldCheckHE = true;
        m_HalloweenRegisterEventTime = JMDate.Now(false).GetTimestamp();
	}

    void StopHalloweenEvent()
	{
        Print("[WG_DEBUG][Halloween] - Stopping event");
        m_HalloweenEvent.Cleanup();
		m_HalloweenEvent = null;
        m_ShouldCheckHE = false;
	}

    bool HalloweenEventCanBeStarted()
    {
        bool rightTimeOfDay = GetDayTime() > 18 || GetDayTime() < 6;
        if(m_HalloweenLastEvent == -1 && rightTimeOfDay)
            return true;
        int delta = JMDate.Now(false).GetTimestamp() - m_HalloweenLastEvent;
        return delta >= 3600 && rightTimeOfDay;
    }

    bool GetShouldCheckHE() { return m_ShouldCheckHE; }
    bool GetShouldCheckHEDeadBodies() { return m_ShouldCheckHEDeadBodies; }
    void SetShouldCheckHEDeadBodies(bool state) { m_ShouldCheckHEDeadBodies = state; }

    bool GetHalloweenRegisterEventGateOpenable() { return m_HalloweenRegisterEventGateOpenable; }
    void SetHalloweenRegisterEventGateOpenable(bool state) { m_HalloweenRegisterEventGateOpenable = state; }

    bool GetHalloweenWave1EventGateOpenable() { return m_HalloweenWave1EventGateOpenable; }
    void SetHalloweenWave1EventGateOpenable(bool state) { m_HalloweenWave1EventGateOpenable = state; }

    void ResetHalloweenLastEvent() { m_HalloweenLastEvent = -1; }
    void SetHalloweenLastEventToNow() { m_HalloweenLastEvent = JMDate.Now(false).GetTimestamp(); }

    int GetHalloweenRegisterEventTime() { return m_HalloweenRegisterEventTime; }
    void ResetHalloweenRegisterEventTime() { m_HalloweenRegisterEventTime = -1; }    

    ref array<ref RegisteredPlayersThatDied> GetRegisteredPlayersThatDied() { return m_RegisteredPlayersThatDied; }
    void AddToRegisteredPlayersThatDied(RegisteredPlayersThatDied newplayer) { m_RegisteredPlayersThatDied.Insert(newplayer); }
    
    void BringPlayersBackAfterEventDueToDeath()
    {   
        if(!m_ShouldCheckHEDeadBodies)
            return;
        Print("[WG_DEBUG][Halloween] - Checking if we should teleport people back. Got these left: " + m_RegisteredPlayersThatDied.Count());
        ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		for ( int i = 0; i < players.Count(); i++ )
		{
            foreach (ref RegisteredPlayersThatDied deadPlayer : m_RegisteredPlayersThatDied)
		    {			
                Man player;
                Class.CastTo(player, players.Get(i));
                if(player && player.IsAlive() && player.GetIdentity().GetId() == deadPlayer.playerId && !deadPlayer.teleported)
                {
                    player.SetPosition(deadPlayer.positionOfBody);
                    deadPlayer.teleported = true;
                }
            }
		}
        
		int count = 0;
        foreach (ref RegisteredPlayersThatDied deadPlayer2 : m_RegisteredPlayersThatDied)
        {	
            if(deadPlayer2.teleported)
                count++;
        }

        if(count == m_RegisteredPlayersThatDied.Count())
        {
            m_RegisteredPlayersThatDied.Clear();
            m_ShouldCheckHEDeadBodies = false;
        }
    }
};