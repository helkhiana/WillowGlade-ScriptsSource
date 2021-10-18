class WG_NPC_Peter : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("HikingJacket_Red");
        GetInventory().CreateInInventory("HunterPants_Brown");
        GetInventory().CreateInInventory("FlatCap_Red");
        GetInventory().CreateInInventory("HikingBootsLow_Black");
        GetInventory().CreateInInventory("WG_DuffleBag_Red");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_THUMB);
    }

    override string GetPlayerName()
    {
        return "Peter";
    };
};

