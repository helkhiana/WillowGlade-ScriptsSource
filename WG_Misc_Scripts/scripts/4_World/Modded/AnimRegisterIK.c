modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);
        pType.AddItemInHandsProfileIK("WG_Improvised_FlintKnife", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_knife.asi", pBehavior, "dz/anims/anm/player/ik/gear/steak_knife.anm");          
        pType.AddItemInHandsProfileIK("WG_Improvised_Club", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_pipe.asi", pBehavior, "dz/anims/anm/player/ik/gear/metal_pipe.anm");
        pType.AddItemInHandsProfileIK("WG_Tape", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/duct_tape.anm");
        pType.AddItemInHandsProfileIK("WG_ShivMetal", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/banana.anm");
        pType.AddItemInHandsProfileIK("WG_LongMetalScrap", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/banana.anm");
        pType.AddItemInHandsProfileIK("WG_RubberTube", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/banana.anm");
        pType.AddItemInHandsProfileIK("WG_LeatherStrap", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/banana.anm");
        pType.AddItemInHandsProfileIK("WG_CordRope", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/banana.anm");
        pType.AddItemInHandsProfileIK("WG_Flint", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/banana.anm");
        pType.AddItemInHandsProfileIK("WG_Coin_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/ammunition/22_LooseRounds.anm");
        pType.AddItemInHandsProfileIK("WG_Torchlight", "dz/anims/workspaces/player/player_main/props/player_main_1h_torch.asi", pBehavior, "dz/anims/anm/player/ik/gear/chemlight.anm");
        pType.AddItemInHandsProfileIK("WG_FirewoodHolder_Kit", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/Cooking_Tripod.anm");
    };

    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded(pType, pBehavior); 
        pType.AddItemInHandsProfileIK("WG_Improvised_Spear_Base", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/advanced_spear.anm"); 
        pType.AddItemInHandsProfileIK("WG_ScrapCrate", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm"); 
    };

    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterHeavy(pType, pBehavior);
        pType.AddItemInHandsProfileIK("WG_Kit", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/tent_large.anm");
    };
};