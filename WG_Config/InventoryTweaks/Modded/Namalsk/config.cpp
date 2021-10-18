class CfgPatches
{
	class InventoryTweaks_Namalsk
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"ns_dayz_gear_tops",
			"ns_dayz_gear_head"
		};
	};
};

class CfgVehicles
{
	class Clothing;
	class Container_Base;
	class BubbleGoose_ColorBase: Clothing
	{
		itemsCargoSize[] = {8,6};
		itemSize[] = {3,3};
	};
	class dzn_apsi: Clothing
	{
		itemSize[] = {2,2};
	};
};
