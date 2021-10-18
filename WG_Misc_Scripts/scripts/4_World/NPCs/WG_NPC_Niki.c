class WG_NPC_Niki : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("BaseballCap_Olive");
        GetInventory().CreateInInventory("WorkingGloves_Yellow");
        GetInventory().CreateInInventory("Shirt_RedCheck");
        GetInventory().CreateInInventory("CanvasPants_Beige");
        GetInventory().CreateInInventory("WorkingBoots_Yellow");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_SITA);
    }

    override string GetPlayerName()
    {
        return "Niki";
    };
};