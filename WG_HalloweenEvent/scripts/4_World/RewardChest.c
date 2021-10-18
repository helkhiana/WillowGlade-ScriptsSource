class WG_RewardChestView : ItemBase
{
    void WG_RewardChestView()
    {        
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Delete, 300000, false);
    }
    
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
};

class WG_RewardChest_Instanced : WG_RewardChest_Base
{

    ref array<string> rewardGunsList = 
    {
        "MSFC_Barret50BMG_Beige",
        "MSFC_Barret50BMG_Green",
        "MSFC_Barret50BMG_Desert",
        "MSFC_Barret50BMG_Black",
        "MSFC_OSV96",
        "MSFC_L96A1_Green",
        "MassKivaari",
        "Massm300_camo",
        "Massm300",
        "AWMreal",
        "TTC_SCARH",
        "TTCSR25_OD",
        "TTCSR25_Snow",
        "TTCSR25_Desert",
        "TTCSR25",
        "TTC_R700",
        "TTC_Winchester1873",
        "TTC_kar98k",
        "TTC_MAS36"
    };
    ref array<string> rewardAmmoList = 
    {
        "MSFC_Ammo_50BMG",
        "MSFC_Ammo_127x108",
        "Ammo_408Chey",
        "Ammo_338",
        "TTC_Ammo_8mm",
        "Ammo_308WinTracer",
        "Ammo_308Win",
        "Ammo_308Win",
        "Ammo_308Win",
        "Ammo_308Win"
    };

    override void SetWGPlayerId(Man man, int wgPlayerId)
    {
        super.SetWGPlayerId(man, wgPlayerId);        
        PlayerBase player = PlayerBase.Cast(man);
        player.SetWGPlayerId(wgPlayerId);
    }

    override void SpawnRewards()
    {
        ItemBase token1 = ItemBase.Cast(this.GetInventory().CreateInInventory("WG_Token_Halloween"));
        token1.SetQuantity(10);
        ItemBase token2 = ItemBase.Cast(this.GetInventory().CreateInInventory("WG_Token_Halloween"));
        token2.SetQuantity(10);
        this.GetInventory().CreateInInventory(rewardGunsList.GetRandomElement());
        this.GetInventory().CreateInInventory(rewardAmmoList.GetRandomElement());
        this.GetInventory().CreateInInventory(rewardAmmoList.GetRandomElement());
        this.GetInventory().CreateInInventory(rewardAmmoList.GetRandomElement());
        this.GetInventory().CreateInInventory(rewardAmmoList.GetRandomElement());
    }
};