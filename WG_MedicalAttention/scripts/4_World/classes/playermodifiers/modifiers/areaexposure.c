modded class AreaExposureMdfr: ModifierBase
{	
	override void OnActivate(PlayerBase player)
	{
		super.OnActivate(player);
		if (player.GetNotifiersManager()) player.GetNotifiersManager().ActivateByType(MedicalAttentionNotifiers.NTF_POISONED);
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		if (player.GetNotifiersManager()) player.GetNotifiersManager().DeactivateByType(MedicalAttentionNotifiers.NTF_POISONED);
	}	
};