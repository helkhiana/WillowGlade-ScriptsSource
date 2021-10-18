class WG_NPC_Seth : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("M4A1_Green");
        GetInventory().CreateInInventory("MSP_BeanBasher");
        GetInventory().CreateInInventory("FAL");
        GetInventory().CreateInInventory("Fal_OeBttstck");
        GetInventory().CreateInInventory("BDUJacket");
        GetInventory().CreateInInventory("BDUPants");
        GetInventory().CreateInInventory("BallisticHelmet_Black");
        GetInventory().CreateInInventory("MilitaryBoots_Black");
        GetInventory().CreateInInventory("TacticalGloves_Black");
        GetInventory().CreateInInventory("AssaultBag_Ttsko");
    }

    override string GetPlayerName()
    {
        return "Seth";
    };
};

class WG_NPC_Rolf : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("MSFC_AS_VAL");
        GetInventory().CreateInInventory("MSFC_RPK16");
        GetInventory().CreateInInventory("MSFCM65MulticamBlack");
        GetInventory().CreateInInventory("MSFCPantsMulticamBlack");
        GetInventory().CreateInInventory("MSFCBootsMulticamBlack");
        GetInventory().CreateInInventory("MSFCGlovesMulticamBlack");
        GetInventory().CreateInInventory("MSFC_TacticalBelt_MulticamBlack");
        GetInventory().CreateInInventory("MSFCPlateCarrierVestMulticamBlack");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_LISTENING);
    }

    override string GetPlayerName()
    {
        return "Rolf";
    };
};

