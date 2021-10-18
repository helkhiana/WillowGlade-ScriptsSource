class WG_NPC_Mirek : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("WorkingGloves_Yellow");
        GetInventory().CreateInInventory("ConstructionHelmet_Yellow");
        GetInventory().CreateInInventory("Shirt_RedCheck");
        GetInventory().CreateInInventory("CanvasPants_Beige");
        GetInventory().CreateInInventory("WorkingBoots_Yellow");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_HOLD);
    }

    override string GetPlayerName()
    {
        return "Mirek";
    };
};