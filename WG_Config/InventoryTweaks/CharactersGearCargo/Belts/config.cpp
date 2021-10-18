class CfgPatches
{
	class InventoryTweaks_CharactersGearCargo_Belts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Characters_Backpacks","DZ_Characters_Belts","DZ_Characters_Glasses","DZ_Characters_Gloves","DZ_Characters_Headgear","DZ_Characters_Masks","DZ_Characters_Pants","DZ_Characters_Shoes","DZ_Characters_Tops","DZ_Characters_Vests"};
	};
};
class cfgVehicles
{
	class Clothing;
	class Clothing_Base;	
	class LeatherBelt_ColorBase: Clothing
	{
		itemSize[] = {2,1};
		itemsCargoSize[] = {8,4};
		weight = 10;
	};
	class CivilianBelt: Clothing
	{
		itemSize[] = {2,1};
		itemsCargoSize[] = {8,4};
		weight = 10;
	};
	class MilitaryBelt: Clothing
	{
		itemSize[] = {2,1};
		itemsCargoSize[] = {8,4};
		weight = 10;
	};	
};
