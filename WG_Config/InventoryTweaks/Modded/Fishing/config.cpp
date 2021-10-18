class CfgPatches
{
	class InventoryTweaks_Fishing
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"zeroy_fishing"
		};
	};
};

class CfgVehicles
{
	class Clothing;
	class Container_Base;
	class zeroy_fishing_backpack_ColorBase: Clothing
	{
		itemsCargoSize[] = {10,8};
	};
};
