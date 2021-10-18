class WG_NPC_Irena : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("BandageDressing");
        GetInventory().CreateInInventory("ParamedicJacket_Green");
        GetInventory().CreateInInventory("ParamedicPants_Green");
        GetInventory().CreateInInventory("MedicalScrubsHat_Green");
        GetInventory().CreateInInventory("WorkingBoots_Grey");
        GetInventory().CreateInInventory("SurgicalGloves_White");
        GetInventory().CreateInInventory("WG_MedicBag_Green");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_GIVER);
    }

    override string GetPlayerName()
    {
        return "Irena";
    };
};