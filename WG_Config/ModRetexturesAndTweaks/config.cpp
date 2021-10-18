class CfgPatches
{
	class ModsTweaks
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"Mass_Textures",
			"Assets_Shemagh"
		};
	};
};

class CfgVehicles
{
	class Clothing;
	class MassCatEars;
	class WG_CatEarsHeadband: MassCatEars
	{
		scope=2;
		displayName="Cat Ears Headband";
		descriptionShort="Wear this to increaser your cuteness";
		inventorySlot="Headgear";
		vehicleClass="Clothing";
		simulation="clothing";
		itemInfo[]=
		{
			"Clothing",
			"Headgear"
		};
		weight=450;
		itemSize[]={3,2};
		absorbency=0.94999999;
		heatIsolation=0.2;
		visibilityModifier=1;
		rotationFlags=16;
		noMask=0;
		hiddenSelections[]=
		{
			"head"
		};
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\CatEarsHeadband\catearsheadband_co.paa",
			"\WillowGlade\WG_Config\data\headgear\CatEarsHeadband\catearsheadband_co.paa",
			"\WillowGlade\WG_Config\data\headgear\CatEarsHeadband\catearsheadband_co.paa"
		};
	};

	class WG_CatEarsHeadband_White: WG_CatEarsHeadband
	{
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\CatEarsHeadband\catearsheadband_white_co.paa",
			"\WillowGlade\WG_Config\data\headgear\CatEarsHeadband\catearsheadband_white_co.paa",
			"\WillowGlade\WG_Config\data\headgear\CatEarsHeadband\catearsheadband_white_co.paa"
		};
	};
	class WG_CatEarsHeadband_DarkBlue: WG_CatEarsHeadband
	{
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\CatEarsHeadband\catearsheadband_darkblue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\CatEarsHeadband\catearsheadband_darkblue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\CatEarsHeadband\catearsheadband_darkblue_co.paa"
		};
	};

	class Shemagh_ColorBase;
	class Shemagh_Black: Shemagh_ColorBase
	{
		scope=2;
		color="black";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_black_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_black_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_black_co.paa"
		};
	};
	class Shemagh_Bandit_ColorBase;
	class Shemagh_Bandit_Black: Shemagh_Bandit_ColorBase
	{
		scope=2;
		color="black";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_black_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_black_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_black_co.paa"
		};
	};
	class Shemagh_Facemask_ColorBase;
	class Shemagh_Facemask_Black: Shemagh_Facemask_ColorBase
	{
		scope=2;
		color="black";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_facemask_black_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_facemask_black_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_facemask_black_co.paa"
		};
	};
	class Shemagh_Scarf_ColorBase;
	class Shemagh_Scarf_Black: Shemagh_Scarf_ColorBase
	{
		scope=2;
		color="black";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_Scarf_black_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_Scarf_black_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_Scarf_black_co.paa"
		};
	};
	class Shemagh_Blue: Shemagh_ColorBase
	{
		scope=2;
		color="blue";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_blue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_blue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_blue_co.paa"
		};
	};
	class Shemagh_Bandit_Blue: Shemagh_Bandit_ColorBase
	{
		scope=2;
		color="blue";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_blue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_blue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_blue_co.paa"
		};
	};
	class Shemagh_Facemask_Blue: Shemagh_Facemask_ColorBase
	{
		scope=2;
		color="blue";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_blue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_blue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_blue_co.paa"
		};
	};
	class Shemagh_Scarf_Blue: Shemagh_Scarf_ColorBase
	{
		scope=2;
		color="blue";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_blue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_blue_co.paa",
			"\WillowGlade\WG_Config\data\headgear\Shemagh\shemagh_bandit_blue_co.paa"
		};
	};
	class Medium_Sleeves_Shirt;
	class Medium_Sleeves_Shirt_Mechanic: Medium_Sleeves_Shirt
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\WillowGlade\WG_Config\data\medium_sleeves_shirt_mechanic_co.paa","\WillowGlade\WG_Config\data\medium_sleeves_shirt_mechanic_co.paa","\WillowGlade\WG_Config\data\medium_sleeves_shirt_mechanic_co.paa"};
	};
};