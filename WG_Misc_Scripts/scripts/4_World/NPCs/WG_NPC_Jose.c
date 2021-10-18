class WG_NPC_Jose : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("LugWrench");
        GetInventory().CreateInInventory("WorkingGloves_Black");
        GetInventory().CreateInInventory("ReflexVest");
        GetInventory().CreateInInventory("JumpsuitJacket_Blue");
        GetInventory().CreateInInventory("JumpsuitPants_Blue");
        GetInventory().CreateInInventory("HikingBootsLow_Blue");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_CRAFTING);
    }

    override string GetPlayerName()
    {
        return "Jose";
    };
};