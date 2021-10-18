class WG_RewardChest_Base : InventoryItem
{
    int m_wgPlayerId;

    void WG_RewardChest_Base()
    {
        RegisterNetSyncVariableInt("m_wgPlayerId");
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Delete, 300000, false);
    } 
    void SpawnRewards() {};

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

    override bool DisableVicinityIcon()
	{
		return true;
	}

    int GetWGPlayerId()
    {
        return m_wgPlayerId;
    }

    void SetWGPlayerId(Man man, int wgPlayerId)
    {
        m_wgPlayerId = wgPlayerId;
        SetSynchDirty();
    }
};