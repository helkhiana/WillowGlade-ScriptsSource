class WG_NPC_Frida : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("Shemagh_Scarf_Blue");
        GetInventory().CreateInInventory("Sweater_Green");
        GetInventory().CreateInInventory("Kneepads_Jeans_Base");
        GetInventory().CreateInInventory("Sneakers_Black");
        GetInventory().CreateInInventory("Canvas_Backpack_Blue");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_WATCHING);
    }

    override string GetPlayerName()
    {
        return "Frida";
    };
};