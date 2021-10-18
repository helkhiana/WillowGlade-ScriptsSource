modded class DayZPlayerMeleeFightLogic_LightHeavy
{
	void EvaluateHit(InventoryItem weapon)
	{
		EntityAI target = m_MeleeCombat.GetTargetEntity();

		if( target )
		{
			if( target.IsInherited(DayZPlayer) && weapon)
			{
				PlayerBase playerSource;
				if(!Class.CastTo(playerSource, weapon.GetHierarchyRootPlayer()))
					EvaluateHit_Player(weapon, target);
			}
			else if( target.IsInherited(DayZInfected) )
			{
				EvaluateHit_Infected(weapon, target);
			}
			else if( target.GetMeleeTargetType() == EMeleeTargetType.NONALIGNABLE )
			{
				EvaluateHit_NonAlignableObjects(weapon, target);
			}
			else
			{
				EvaluateHit_Common(weapon, target);
			}
			
			m_MeleeCombat.CheckMeleeItem();
		}
	}
};