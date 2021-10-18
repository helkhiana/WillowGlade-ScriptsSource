class CfgPatches
{
	class WG_HalloweenEvent
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
/* class CfgMods
{
	class WG_HalloweenEvent
	{
		dir = "WG_HalloweenEvent";
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
				files[] = {"WillowGlade/WG_HalloweenEvent/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_HalloweenEvent/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_HalloweenEvent/scripts/5_Mission"};
			};
		};
	};
}; */

class CfgVehicles
{
	class Inventory_Base;
    class WG_RewardChestView : Inventory_Base
	{
		scope=2;
		displayName="Reward Chest";
		descriptionShort="A chest containing rewards for the completion of the halloween chest. It is instanced to each player.";
		model="\WillowGlade\WG_HalloweenEvent\data\rewardchest\rewardchest.p3d";
		physLayer="item_large";
	};
	class WG_RewardChest_Base : Inventory_Base {};
    class WG_RewardChest_Instanced : WG_RewardChest_Base
	{
		scope=2;
		displayName="Reward Chest";
		descriptionShort="A chest containing rewards for the completion of the halloween chest. It is instanced to each player.";
		model="\WillowGlade\WG_HalloweenEvent\data\rewardchest\rewardchest_instanced.p3d";
		itemsCargoSize[]={10,10};
	};
};