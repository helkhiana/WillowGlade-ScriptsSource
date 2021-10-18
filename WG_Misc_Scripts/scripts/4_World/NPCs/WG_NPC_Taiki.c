class WG_NPC_Taiki : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
        GetInventory().CreateInInventory("NailedBaseballBat");
        GetInventory().CreateInInventory("MP5K");
        GetInventory().CreateInInventory("MP5_RailHndgrd");
        GetInventory().CreateInInventory("Universallight");
        GetInventory().CreateInInventory("MP5k_StockBttstck");
        GetInventory().CreateInInventory("MP5_Compensator");
        GetInventory().CreateInInventory("HighCapacityVest_Black");
        GetInventory().CreateInInventory("BaseballCap_Olive");
        GetInventory().CreateInInventory("GorkaEJacket_Flat");
        GetInventory().CreateInInventory("CargoPants_Beige");
        GetInventory().CreateInInventory("HikingBootsLow_Black");
        GetInventory().CreateInInventory("TacticalGloves_Black");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_SEARCHINVENTORY);
    }

    override string GetPlayerName()
    {
        return "Taiki";
    };
};
