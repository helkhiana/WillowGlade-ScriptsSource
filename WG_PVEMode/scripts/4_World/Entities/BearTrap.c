modded class BearTrap extends TrapBase
{	
	override void OnSteppedOn(EntityAI victim)
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			if (victim.IsInherited(DayZCreatureAI))
				PlaySoundBiteLeg();
			else
				PlaySoundBiteEmpty();
		}
	}
};