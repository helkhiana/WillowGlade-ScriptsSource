class CfgPatches
{
	class InventoryTweaks_CharactersGearCargo_Vests
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
	class PlateCarrierVest: Clothing
	{
		weight = 6000;
		itemsCargoSize[] = {8,4};
		itemSize[] = {4,4};
	};
	class SmershVest: Clothing
	{
		weight = 110;
		itemsCargoSize[] = {8,4};
		itemSize[] = {3,3};
	};
	class PressVest_ColorBase: Clothing
	{
		weight = 3500;
		itemsCargoSize[] = {8,4};
		itemSize[] = {3,2};
	};
	class UKAssVest_ColorBase: Clothing
	{
		weight = 950;
		itemsCargoSize[] = {8,4};
		itemSize[] = {3,3};
	};
	class PoliceVest: Clothing
	{
		weight = 1750;
		itemsCargoSize[] = {8,4};
		itemSize[] = {3,2};
	};
	class PlateCarrierHolster: Clothing
	{
		weight = 55;
		itemSize[] = {3,2};
	};
	class ChestHolster: Clothing
	{
		weight = 155;
		itemsCargoSize[] = {8,4};
		itemSize[] = {3,2};
	};
	class HighCapacityVest_ColorBase: Clothing
	{
		weight = 1200;
		itemsCargoSize[] = {8,4};
		itemSize[] = {4,4};
	};
	class LeatherStorageVest_ColorBase: Clothing
	{
		weight = 1400;
		itemsCargoSize[] = {8,4};
		itemSize[] = {4,4};
	};
	class HuntingVest: Clothing
	{
		weight = 175;
		itemsCargoSize[] = {8,4};
		itemSize[] = {3,2};
	};
	class ReflexVest: Clothing
	{
		weight = 100;
		itemsCargoSize[] = {8,4};
		itemSize[] = {3,2};
	};
};
