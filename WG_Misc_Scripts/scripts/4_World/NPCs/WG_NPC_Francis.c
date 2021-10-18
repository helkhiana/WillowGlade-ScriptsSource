class WG_NPC_Francis : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("MSFCTStarsTShirt");
        GetInventory().CreateInInventory("MSFCTStarsPants");
        GetInventory().CreateInInventory("MSFC_TacticalCap_Green");
        GetInventory().CreateInInventory("MSFC_HelmetPatch_MAMA_IM_SPEC");
        GetInventory().CreateInInventory("MSFCLowaZephyrBootsGreen");
        GetInventory().CreateInInventory("MSFCTraderGloves");
        GetInventory().CreateInInventory("MSFCSmershBagGreen");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_SALUTE);
    }

    override string GetPlayerName()
    {
        return "Francis";
    };
};