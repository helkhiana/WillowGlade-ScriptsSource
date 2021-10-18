modded class ModItemRegisterCallbacks
{	
	override void RegisterPistol(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterPistol(pType, pBehavior);
		pType.AddItemInHandsProfileIK("EnergyPistol", "dz/anims/workspaces/player/player_main/weapons/player_main_fnp45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fnp45.anm");	
	}
};