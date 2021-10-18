modded class PlayerBase
{
    int m_wgPlayerId;

    void PlayerBase()
    {
        RegisterNetSyncVariableInt("m_wgPlayerId");
    }

    int GetWGPlayerId()
    {
        return m_wgPlayerId;
    }

    void SetWGPlayerId(int wgPlayerId)
    {
        m_wgPlayerId = wgPlayerId;
        SetSynchDirty();
    }

    override void EEKilled(Object killer)
    {
        super.EEKilled(killer);
        if(g_Game.GetHalloweenEvent())
            g_Game.GetHalloweenEvent().RemovePlayer(this);
    }

    vector rewardChestLocation = "2392.989014 360.071045 7721.791016";
    void OnScheduledTick(float deltaTime)
    {
        super.OnScheduledTick(deltaTime);
        NVGoggles nvg;
        if (FindAttachmentBySlotName("Eyewear"))
        {
            nvg = NVGoggles.Cast(FindAttachmentBySlotName("Eyewear").FindAttachmentBySlotName("NVG"));
        }
        else if (FindAttachmentBySlotName("Headgear"))
        {
            nvg = NVGoggles.Cast(FindAttachmentBySlotName("Headgear").FindAttachmentBySlotName("NVG"));
        }
        if (nvg)
        {
            float distance_to_player = vector.Distance(rewardChestLocation, GetPosition());
            if (distance_to_player < 200 && nvg.m_IsLowered)
                nvg.RotateGoggles(nvg.m_IsLowered);
        }
    }
};