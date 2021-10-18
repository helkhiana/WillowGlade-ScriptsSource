class CfgPatches
{
	class InventoryTweaks_Windstride
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"Windstrideclothing",
			"Canvas_Backpack",
			"Layered_Shirt",
			"Leggings",
			"Military_Sweater",
			"Winter_Parka",
			"Medium_Sleeves_Shirt"
		};
	};
};

class CfgVehicles
{
	class Clothing;
	class TaloonBag_ColorBase;
	class Layered_Shirt_Base: Clothing
	{
		itemsCargoSize[] = {8,6};
	};
	class Leggings_ColorBase: Clothing
	{
		itemsCargoSize[] = {8,4};
	};
	class Military_Sweater: Clothing
	{
		itemsCargoSize[] = {8,6};
	};
	class Canvas_Backpack_Base: TaloonBag_ColorBase
	{
		descriptionShort = "A sun-bleached canvas bag with a suede leather bottom, it has a few pockets and compression straps on the sides. Attachments: 3x Pins, Chemlight, Radio, Water Bottle, specific melees: Machete, Crowbar, Baseball Bat, Nailed Baseball Bat, Hammer, Hatchet";
		itemsCargoSize[] = {10,10};
	};
	class Medium_Sleeves_Shirt: Clothing
	{
		itemsCargoSize[] = {8,6};
	};
	class Winter_Parka_Base: Clothing
	{
		itemSize[] = {3,2};
		itemsCargoSize[] = {8,6};
	};
	class Winter_Parka_Green: Clothing
	{
		itemSize[] = {3,2};
		itemsCargoSize[] = {8,6};
	};
	class Skinny_Jeans_ColorBase: Clothing
	{
		itemsCargoSize[] = {8,4};
		itemSize[] = {2,2};
	};
};