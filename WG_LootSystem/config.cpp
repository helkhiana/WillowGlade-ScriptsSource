class CfgPatches
{
	class WG_LootSystem
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class WG_LootSystem
	{
		dir = "WG_LootSystem";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "";
		credits = "";
		author = "Helkhiana";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_LootSystem/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_LootSystem/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_LootSystem/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Container_Base;	
	
	class WG_LootCrate_Base: Container_Base
	{
		scope=0;
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		quantityBar=1;
		carveNavmesh=1;
		bounding="BSphere";
		overrideDrawArea="3.0";
		visibilityModifier=0.94999999;
		canBeDigged=0;
		alignHologramToTerain=1;
		heavyItem=1;
		weight=10;
		itemSize[]={10,10};
		itemBehaviour=1;
		physLayer="item_large";
		simulation="inventoryItem";
		hiddenSelections[]=
		{
			"all"
		};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class WG_Loot_Cargo : WG_LootCrate_Base
	{
		scope=2;
		model = "\WillowGlade\WG_LootSystem\data\cargo\cargo.p3d";
		itemsCargoSize[]={10,30};
	};
	class WG_Loot_SeaChest : WG_LootCrate_Base
	{
		scope=2;
		model="\DZ\gear\camping\sea_chest.p3d";
		itemsCargoSize[]={10,30};
	};
	
	class WG_Loot_Bookcase : WG_LootCrate_Base
	{
		scope=2;
		model="\WillowGlade\WG_LootSystem\data\bookcase\bookcase.p3d";
		itemsCargoSize[]={10,10};
	};

	class WG_Loot_Medbag : WG_LootCrate_Base
	{
		scope=2;
		model="\WillowGlade\WG_LootSystem\data\medbag\medbag.p3d";
		itemsCargoSize[]={10,10};
	};
	class WG_Loot_Sportsbag : WG_LootCrate_Base
	{
		scope=2;
		model="\WillowGlade\WG_LootSystem\data\sportsbag\sportsbag.p3d";
		itemsCargoSize[]={10,10};
	};
	class WG_Loot_ClothesSuitcase : WG_LootCrate_Base
	{
		scope=2;
		model="\WillowGlade\WG_LootSystem\data\clothessuitcase\clothessuitcase.p3d";
		itemsCargoSize[]={10,10};
	};
	class WG_Loot_ClothesSuitcase_Windstride : WG_Loot_ClothesSuitcase 
	{
		scope=2;
	};
};