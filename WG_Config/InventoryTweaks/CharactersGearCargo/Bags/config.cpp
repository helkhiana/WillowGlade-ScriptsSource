class CfgPatches
{
	class InventoryTweaks_CharactersGearCargo_Bags
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
	class SmershBag: Clothing
	{
		weight = 300;
		itemSize[] = {4,4};
		itemsCargoSize[] = {8,4};
	};
	class CourierBag: Clothing
	{
		weight = 450;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,6};
	};
	class FurCourierBag: Clothing
	{
		weight = 600;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,6};
	};
	class TaloonBag_ColorBase: Clothing
	{
		weight = 650;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,8};
	};
	class ImprovisedBag: Clothing
	{
		weight = 1200;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,8};
	};
	class FurImprovisedBag: Clothing
	{
		weight = 1200;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,8};
	};
	class ChildBag_ColorBase: Clothing
	{
		weight = 925;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,8};
	};	
	class LeatherSack_ColorBase: Clothing
	{
		weight = 650;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,8};
	};
	class AssaultBag_ColorBase: Clothing
	{
		weight = 450;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,10};
	};
	class TortillaBag: Clothing
	{
		weight = 1300;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,10};
	};
	class DryBag_ColorBase: Clothing
	{
		weight = 300;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,10};
	};
	class HuntingBag: Clothing
	{
		weight = 700;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,10};
	};
	class MountainBag_ColorBase: Clothing
	{
		weight = 1150;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,10};
	};
	class CoyoteBag_ColorBase: Clothing
	{
		weight = 1300;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,10};
	};
	class AliceBag_ColorBase: Clothing
	{
		weight = 800;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,10};
	};	
};
