modded class ZombieBase extends DayZInfected
{
/* 	void ZombieBase()
	{
        if ( GetGame().IsServer() )
        {
            //GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( SpawnHelmet, 500 );
        }
	}

	void SpawnHelmet()
	{
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(SpawnHelmet);
		if(IsKindOf("ZmbM_HunterOld_Elf"))
		{
			ItemBase item = ItemBase.Cast(GetInventory().CreateAttachment("MerryZ_ElfHat"));
			item.SetHealth(60);
			return;
		}
		if(IsKindOf("ZmbM_HunterOld_Santa"))
		{
			ItemBase item2 = ItemBase.Cast(GetInventory().CreateAttachment("SantasHat"));
			item2.SetHealth(50);
			return;
		}
		if(!IsKindOfVeryHighMeleeZombie() && !IsKindOfHighMeleeZombie() && !IsKindOfMediumMeleeZombie())
		{			
			if(Math.RandomFloat01() < 0.8)
				GetInventory().CreateAttachment("SantasHat");
		}
	} */

	override bool CanBeSkinned()
	{
		return true;
	}
};