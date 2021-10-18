class WG_NPC_Oliver : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("Zeroy_fishing_Boonie_Camo0");
        GetInventory().CreateInInventory("Zeroy_fishing_Raincoat_Camo");
        GetInventory().CreateInInventory("Zeroy_fishing_Wellies_Camo0");
        GetInventory().CreateInInventory("Zeroy_fishing_Pants_Camo");
        GetInventory().CreateInInventory("zeroy_fishing_backpack_grey");
        GetInventory().CreateInInventory("ImprovisedFishingRod");
        GetInventory().CreateInInventory("ImprovisedFishingRod");
        ImprovisedFishingRod item = ImprovisedFishingRod.Cast(GetInventory().CreateInInventory("ImprovisedFishingRod"));       
        if(item)
            item.AnimateFishingRod(true);
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_FISHING);
    }

    override string GetPlayerName()
    {
        return "Alain";
    };
};
