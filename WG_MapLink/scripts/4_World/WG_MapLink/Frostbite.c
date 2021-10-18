modded class Frostbite extends ModifierBase
{
	override bool ActivateCondition( PlayerBase player )
	{
		return g_Game.GetWorldName() == "namalsk";
	}
};
