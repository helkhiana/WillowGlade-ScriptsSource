class CfgPatches
{
	class WG_TraderStorage
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class WG_TraderStorage
	{
		dir = "WG_TraderStorage";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "WG_TraderStorage";
		credits = "";
		author = "";
		authorID = "0";
		version = "1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_TraderStorage/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_TraderStorage/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_TraderStorage/scripts/5_Mission"};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
    class WG_TraderStorageView : Inventory_Base
	{
		scope=0;
		displayName="Storage";
		descriptionShort="A storage that can be rented with tokens from trader.";
		physLayer="item_large";
	};
    class WG_TraderStorageView_PlasticCrate : WG_TraderStorageView
	{
		scope=2;
		displayName="Tier 1 Storage";
		descriptionShort="A tier 1 storage with 100 slots that can be rented with tokens from trader.";
		model="\MuchStuffPack\MSP_Storage_crates\plasticcrate\plasticcrate.p3d";
	};
    class WG_TraderStorageView_KitchenUnit : WG_TraderStorageView
	{
		scope=2;
		displayName="Tier 2 Storage";
		descriptionShort="A tier 2 storage with 250 slots that can be rented wth tokens from trader.";
		model="\DZ\structures\furniture\Various\kitchen_unit_a_DZ.p3d";
	};
    class WG_TraderStorageView_SoloLocker : WG_TraderStorageView
	{
		scope=2;
		displayName="Tier 2 Storage";
		descriptionShort="A tier 2 storage with 250 slots that can be rented wth tokens from trader.";
		model="\MuchStuffPack\MSP_Storage_lockers\sololocker\sololocker.p3d";
	};
    class WG_TraderStorageView_MilitaryLocker : WG_TraderStorageView
	{
		scope=2;
		displayName="Tier 3 Storage";
		descriptionShort="A tier 3 storage with 500 slots that can be rented with tokens from trader.";
		model="\MuchStuffPack\MSP_Storage_lockers\militarylocker\militarylocker.p3d";
	};
    class WG_TraderStorageView_StorageBox : WG_TraderStorageView
	{
		scope=2;
		displayName="Tier 4 Storage";
		descriptionShort="A tier 4 storage with 1000 slots that can be rented with tokens from trader.";
		model="\MuchStuffPack\MSP_Storage_boxes\storagebox\storagebox.p3d";
	};
    class WG_TraderStorageView_Locker : WG_TraderStorageView
	{
		scope=2;
		displayName="Tier 5 Storage";
		descriptionShort="A tier 5 storage with 1000 slots that can be rented with tokens from trader.";
		model="\MuchStuffPack\MSP_Storage_lockers\threelocker\locker.p3d";
	};
	class WG_TraderStorage_Base : Inventory_Base 
	{
		displayName="Storage";
		descriptionShort="A storage that can be rented with tokens from trader.";
		model="\WillowGlade\WG_TraderStorage\data\instanced.p3d";
	};
    class WG_TraderStorage_Instanced_Tier1 : WG_TraderStorage_Base
	{
		scope=2;
		displayName="Storage Tier 1";
		descriptionShort="A tier 1 storage with 100 slots which has been rented with tokens from trader. You can extend the rent by using more tokens.";
		itemsCargoSize[]={10,10};
	};
    class WG_TraderStorage_Instanced_Tier2 : WG_TraderStorage_Base
	{
		scope=2;
		displayName="Storage Tier 2";
		descriptionShort="A tier 2 storage with 250 slots which has been rented with tokens from trader. You can extend the rent by using more tokens.";
		itemsCargoSize[]={10,25};
	};
    class WG_TraderStorage_Instanced_Tier3 : WG_TraderStorage_Base
	{
		scope=2;
		displayName="Storage Tier 3";
		descriptionShort="A tier 3 storage with 500 slots which has been rented with tokens from trader. You can extend the rent by using more tokens.";
		itemsCargoSize[]={10,50};
	};
    class WG_TraderStorage_Instanced_Tier4 : WG_TraderStorage_Base
	{
		scope=2;
		displayName="Storage Tier 4";
		descriptionShort="A tier 4 storage with 750 slots which has been rented with tokens from trader. You can extend the rent by using more tokens.";
		itemsCargoSize[]={10,75};
	};
    class WG_TraderStorage_Instanced_Tier5 : WG_TraderStorage_Base
	{
		scope=2;
		displayName="Storage Tier 5";
		descriptionShort="A tier 5 storage with 1000 slots which has been rented with tokens from trader. You can extend the rent by using more tokens.";
		itemsCargoSize[]={10,100};
	};
};