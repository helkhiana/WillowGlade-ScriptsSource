modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);
        pType.AddItemInHandsProfileIK("WG_Ticket_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("WG_PipeBomb", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/explosives/grenade.anm");
        pType.AddItemInHandsProfileIK("WG_PipeBomb_Bundle", "dz/anims/workspaces/player/player_main/props/player_main_1h_binocular.asi", pBehavior, "dz/anims/anm/player/ik/gear/binoculars.anm");
        pType.AddItemInHandsProfileIK("WG_Gunpowder", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/cleaning_kit_wood.anm");
        pType.AddItemInHandsProfileIK("WG_WD40", "dz/anims/workspaces/player/player_main/props/player_main_1h_sodacan.asi", pBehavior, "dz/anims/anm/player/ik/gear/soda_can.anm");
        pType.AddItemInHandsProfileIK("WG_Gameboy","dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/book.anm");
        pType.AddItemInHandsProfileIK("WG_Tetris","dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/book.anm");
        pType.AddItemInHandsProfileIK("WG_Rocket_RPG", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/banana.anm");
        pType.AddItemInHandsProfileIK("WG_Rocket_LAW", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/banana.anm");
        pType.AddItemInHandsProfileIK("WG_Wallet", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("WG_Gameboy_Cartridge_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
    };

    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded(pType, pBehavior);
        pType.AddItemInHandsProfileIK("WG_AdventurerTent_Kit", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/leather_sack.anm");
        pType.AddItemInHandsProfileIK("WG_AircraftBattery", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm"); 
        pType.AddItemInHandsProfileIK("EngineOil", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm"); 
        pType.AddItemInHandsProfileIK("WG_AircraftOil_Turbine", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm"); 
        pType.AddItemInHandsProfileIK("WG_AircraftHydraulicFluid", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm"); 
    }
};