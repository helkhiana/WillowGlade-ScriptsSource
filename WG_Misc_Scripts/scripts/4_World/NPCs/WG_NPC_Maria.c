class WG_NPC_Maria : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("ZmijovkaCap_Blue");
        GetInventory().CreateInInventory("TelnyashkaShirt");
        GetInventory().CreateInInventory("Breeches_Green");
        GetInventory().CreateInInventory("Wellies_Green");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_LOOKATME);
    }

    override string GetPlayerName()
    {
        return "Maria";
    };
};