modded class VicinityItemManager
{
    bool IsObstructed (Object filtered_object)
    {
        if (filtered_object.IsInherited(WG_RewardChest_Base))
        {
            WG_RewardChest_Base chest = WG_RewardChest_Base.Cast(filtered_object);
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if(player.GetWGPlayerId() == chest.GetWGPlayerId())
                return false;
            else
                return true;
        }
        return super.IsObstructed(filtered_object);
    }
};