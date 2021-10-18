class WG_NPC_BoatTransport : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("NailedBaseballBat");
        GetInventory().CreateInInventory("HighCapacityVest_Black");
        GetInventory().CreateInInventory("BaseballCap_Olive");
        GetInventory().CreateInInventory("GorkaEJacket_Summer");
        GetInventory().CreateInInventory("GorkaPants_Summer");
        GetInventory().CreateInInventory("HikingBootsLow_Black");
        GetInventory().CreateInInventory("TacticalGloves_Black");
    }

    override string GetPlayerName()
    {
        return "Taiki";
    };
};

class WG_NPC_FishingBoatTransport : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("Paper");
        GetInventory().CreateInInventory("Zeroy_fishing_Boonie_Camo0");
        GetInventory().CreateInInventory("Raincoat_Black");
        GetInventory().CreateInInventory("Wellies_Black");
        GetInventory().CreateInInventory("CargoPants_Blue");
        GetInventory().CreateInInventory("ImprovisedFishingRod");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_VIEWNOTE);
    }

    override string GetPlayerName()
    {
        return "Jim";
    };
};


class WG_NPC_FBoatTransport : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("Paper");
        GetInventory().CreateInInventory("Zeroy_fishing_Boonie_Camo0");
        GetInventory().CreateInInventory("Raincoat_Black");
        GetInventory().CreateInInventory("Wellies_Black");
        GetInventory().CreateInInventory("CargoPants_Blue");
        GetInventory().CreateInInventory("ImprovisedFishingRod");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_VIEWNOTE);
    }

    override string GetPlayerName()
    {
        return "Frida";
    };
};

class WG_NPC_HeliTransport : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("ASVAL");
        GetInventory().CreateInInventory("M65Jacket_Olive");
        GetInventory().CreateInInventory("GorkaPants_Flat");
        GetInventory().CreateInInventory("CombatBoots_Black");
        GetInventory().CreateInInventory("TacticalGloves_Black");
        GetInventory().CreateInInventory("PlateCarrierVest");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_SALUTE);
    }

    override string GetPlayerName()
    {
        return "Rolf";
    };
};

class WG_NPC_FHeliTransport : WG_NPC_Base
{ 
    override void Loadout()
    {
        GetInventory().CreateInInventory("ASVAL");
        GetInventory().CreateInInventory("Mag_VAL_20Rnd");
        GetInventory().CreateInInventory("M65Jacket_Olive");
        GetInventory().CreateInInventory("GorkaPants_Flat");
        GetInventory().CreateInInventory("CombatBoots_Black");
        GetInventory().CreateInInventory("TacticalGloves_Black");
        GetInventory().CreateInInventory("PlateCarrierVest");
    }

    override string GetPlayerName()
    {
        return "Maria";
    };
};