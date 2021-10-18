class WG_NPC_Linda : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("ConstructionHelmet_Red");
        GetInventory().CreateInInventory("TShirt_White");
        GetInventory().CreateInInventory("Kneepads_Jeans_Base");
        GetInventory().CreateInInventory("SlacksPants_Black");
        GetInventory().CreateInInventory("DressShoes_Black");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_POINTSELF);
    }

    override string GetPlayerName()
    {
        return "Linda";
    };
};