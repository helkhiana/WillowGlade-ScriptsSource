modded class MissionGameplay
{
	override void PlayerControlDisable(int mode)
	{
		super.PlayerControlDisable(mode);
        
        if(mode == INPUT_EXCLUDE_INVENTORY)
        {
            GetUApi().ActivateExclude("inventory");
            GetUApi().GetInputByName("UAWalkRunTemp").ForceEnable(false);
		    GetUApi().UpdateControls();
        }
	}
};