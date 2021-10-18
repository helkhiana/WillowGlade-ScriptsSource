class CfgPatches
{
	class InventoryTweaks_Mass
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"Mass_Textures"
		};
	};
};

class CfgVehicles
{
	class Clothing;
	class MassPlateCarrier_ColorBase;
	class Container_Base;
	class LeatherSack_ColorBase;
	class Mass_WW2Vest: Clothing
	{
		itemsCargoSize[] = {8,4};
	};
	class MassRatnik: Clothing
	{
		itemsCargoSize[] = {8,4};
	};
	
	class PlateCarrierPouches;
	class MassLargePlateCarrierPouches: PlateCarrierPouches
	{
		itemSize[]={8,4};
		itemsCargoSize[] = {8,4};
	};	
	class MassImprovArmor: MassPlateCarrier_ColorBase
	{
		itemsCargoSize[] = {8,4};
	};
	class MountainBag_ColorBase;
	class MassSlingBag: MountainBag_ColorBase
	{
		itemsCargoSize[] = {10,10};
	};
	class MassSurvivorBag: Clothing
	{
		itemsCargoSize[] = {10,10};
	};

	class MassMolleBagBlack: MountainBag_ColorBase
	{
		descriptionShort = "US Military Tactical Assault Backpack. Modelwork and Textures By ComatoseBadger. Port work by Mass. Attaches two Tactical Bags, a ChemLight and a NBC bag";
		itemsCargoSize[] = {10,10};
	};
	class Massbag: MountainBag_ColorBase
	{
		descriptionShort = "Mass's Large Canvas Bag. Attachments: Canteen, Weapon/melee, Chemlight, NBC/Clothes Bag";
		itemsCargoSize[] = {10,10};
	};	
	class MassCanvasBag: LeatherSack_ColorBase
	{
		itemsCargoSize[] = {10,10};
	};	
	class Massmedbag: MountainBag_ColorBase
	{
		descriptionShort = "Mass's Emergency Medical Backpack. textures by asorrycanadian. Attachments: Advanced MedKit, First Aid Kit, Chemlight, NBC/Clothes Bag.";
		itemsCargoSize[] = {10,8};
	};	
	class TaloonBag_ColorBase;
	class MasscamoTaloon: TaloonBag_ColorBase
	{
		itemsCargoSize[] = {10,8};
	};
	class MasscamoTaloon1: TaloonBag_ColorBase
	{
		itemsCargoSize[] = {10,8};
	};
	
	class SmershBag;
	class MassLargeSmersh: SmershBag
	{
		itemsCargoSize[] = {8,4};
	};	
	class MassImprovisedBag_Colorbase: clothing
	{
		itemsCargoSize[] = {10,8};
	};	
	class MassRainCoatcourier_ColorBase: clothing
	{
		itemsCargoSize[] = {8,6};
	};
	class LeatherBelt_ColorBase;
	class MassToolbelt: LeatherBelt_ColorBase
	{
		itemsCargoSize[] = {8,4};
	};
	class MassMolleBelt: Clothing
	{
		itemsCargoSize[] = {8,4};
	};
	class MassNBC_Bag: Container_Base
	{
		itemsize[] = {2,4};
		itemsCargoSize[] = {6,6};
	};
	class MassClothing_Bag: Container_Base
	{
		itemsize[] = {2,4};
		itemsCargoSize[] = {6,6};
	};		
};
