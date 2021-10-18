class CfgPatches
{
	class InventoryTweaks_CharactersGear_Size
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
	class GhillieBushrag_ColorBase: Clothing
	{
		itemSize[] = {3,3};
		weight = 350;
	};
	class GhillieTop_ColorBase: Clothing
	{
		itemSize[] = {3,3};
		weight = 400;
	};
	class GhillieSuit_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"Back",
			"Hips"
		};
		itemSize[] = {3,3};
		weight = 1600;
	};
	class SportGlasses_ColorBase: Clothing
	{
		itemSize[] = {2,1};
		weight = 10;
	};
	class AviatorGlasses: Clothing
	{
		itemSize[] = {2,1};
		weight = 10;
	};
	class DesignerGlasses: Clothing
	{
		itemSize[] = {2,1};
		weight = 10;
	};
	class ThickFramesGlasses: Clothing
	{
		itemSize[] = {2,1};
		weight = 10;
	};
	class ThinFramesGlasses: Clothing
	{
		itemSize[] = {2,1};
		weight = 10;
	};
	class TacticalGoggles: Clothing
	{
		itemSize[] = {2,1};
		weight = 10;
	};
	class NVGHeadstrap: Clothing
	{
		itemSize[] = {2,1};
		weight = 10;
	};
	class WorkingGloves_ColorBase: Clothing
	{
		weight = 65;
		itemSize[] = {2,2};
	};
	class TacticalGloves_ColorBase: Clothing
	{
		weight = 65;
		itemSize[] = {2,2};
	};
	class NBCGloves_ColorBase: Clothing
	{
		weight = 65;
		itemSize[] = {2,2};
	};
	class SurgicalGloves_ColorBase: Clothing
	{
		weight = 65;
		itemSize[] = {2,2};
	};
	class LeatherGloves_ColorBase: Clothing
	{
		weight = 65;
		itemSize[] = {2,2};
	};
	class OMNOGloves_ColorBase: Clothing
	{
		weight = 65;
		itemSize[] = {2,2};
	};
	class BallisticHelmet_ColorBase: Clothing
	{
		weight = 500;
		itemSize[] = {3,2};
	};
	class BaseballCap_ColorBase: Clothing
	{
		weight = 55;
		itemSize[] = {2,2};
	};
	class ZSh3PilotHelmet: Clothing
	{
		weight = 725;
		itemSize[] = {3,3};
	};
	class ConstructionHelmet_ColorBase: Clothing
	{
		weight = 235;
		itemSize[] = {3,2};
	};
	class BurlapSackCover: Clothing
	{
		weight = 255;
		itemSize[] = {2,2};
	};
	class BeanieHat_ColorBase: Clothing
	{
		weight = 45;
		itemSize[] = {2,1};
	};
	class Ushanka_ColorBase: Clothing
	{
		weight = 160;
		itemSize[] = {2,1};
	};
	class PumpkinHelmet: Clothing
	{
		weight = 250;
		itemSize[] = {2,2};
	};
	class MotoHelmet_ColorBase: Clothing
	{
		weight = 605;
		itemSize[] = {3,3};
	};
	class DarkMotoHelmet_ColorBase: Clothing
	{
		weight = 605;
		itemSize[] = {3,3};
	};
	class BandanaHead_ColorBase: Clothing
	{
		weight = 60;
		itemSize[] = {2,1};
	};
	class RadarCap_ColorBase: Clothing
	{
		weight = 80;
		itemSize[] = {2,1};
	};
	class MilitaryBeret_ColorBase: Clothing
	{
		weight = 115;
		itemSize[] = {2,1};
	};
	class FlatCap_ColorBase: Clothing
	{
		weight = 120;
		itemSize[] = {2,1};
	};
	class ZmijovkaCap_ColorBase: Clothing
	{
		weight = 110;
		itemSize[] = {2,1};
	};
	class CowboyHat_ColorBase: Clothing
	{
		weight = 185;
		itemSize[] = {2,1};
	};
	class BoonieHat_ColorBase: Clothing
	{
		weight = 85;
		itemSize[] = {2,1};
	};
	class OfficerHat: Clothing
	{
		weight = 170;
		itemSize[] = {2,1};
	};
	class PoliceCap: Clothing
	{
		weight = 160;
		itemSize[] = {2,1};
	};
	class PilotkaCap: Clothing
	{
		weight = 70;
		itemSize[] = {2,1};
	};
	class TankerHelmet: Clothing
	{
		weight = 490;
		itemSize[] = {3,2};
	};
	class GorkaHelmet: Clothing
	{
		weight = 550;
		itemSize[] = {2,2};
	};
	class FirefightersHelmet_ColorBase: Clothing
	{
		weight = 435;
		itemSize[] = {3,2};
	};
	class SkateHelmet_ColorBase: Clothing
	{
		weight = 230;
		itemSize[] = {3,2};
	};
	class WeldingMask: Clothing
	{
		weight = 1100;
		itemSize[] = {2,3};
	};
	class PrisonerCap: Clothing
	{
		weight = 40;
		itemSize[] = {2,1};
	};
	class GhillieHood_ColorBase: Clothing
	{
		weight = 205;
		itemSize[] = {3,2};
	};
	class LeatherHat_ColorBase: Clothing
	{
		weight = 160;
		itemSize[] = {3,2};
	};
	class MedicalScrubsHat_ColorBase: Clothing
	{
		weight = 230;
		itemSize[] = {2,1};
	};
	class GreatHelm: Clothing
	{
		weight = 1000;
		itemSize[] = {2,2};
	};
	class Ssh68Helmet: Clothing
	{
		weight = 750;
		itemSize[] = {3,2};
	};
	class DirtBikeHelmet_ColorBase: Clothing
	{
		weight = 800;
		itemSize[] = {3,2};
	};
	class DirtBikeHelmet_Visor: Clothing
	{
		itemSize[] = {1,1};
	};
	class DirtBikeHelmet_Mouthguard: Clothing
	{
		itemSize[] = {1,1};
	};
	class NBCHoodBase: Clothing
	{
		weight = 230;
		itemSize[] = {2,1};
	};
	class HockeyHelmet_ColorBase: Clothing
	{
		weight = 305;
		itemSize[] = {2,2};
	};
	class SantasHat: Clothing
	{
		weight = 225;
		itemSize[] = {2,2};
	};
	class Mich201Helmet: Clothing
	{
		weight = 600;
		itemSize[] = {2,2};
	};
	class Universal_Bandana_Redpattern: Clothing_Base
	{
		weight = 59;
		itemSize[] = {1,1};
	};
	class GasMask: Clothing
	{
		weight = 365;
		itemSize[] = {2,2};
	};
	class AirborneMask: Clothing
	{
		weight = 365;
		itemSize[] = {2,2};
	};
	class BandanaMask_ColorBase: Clothing
	{
		weight = 255;
		itemSize[] = {1,1};
	};
	class NioshFaceMask: Clothing
	{
		weight = 170;
		itemSize[] = {2,2};
	};
	class BalaclavaMask_ColorBase: Clothing
	{
		weight = 65;
		itemSize[] = {2,1};
	};
	class GP5GasMask: Clothing
	{
		weight = 545;
		itemSize[] = {2,2};
	};
	class Balaclava3Holes_ColorBase: Clothing
	{
		weight = 305;
		itemSize[] = {2,2};
	};
	class SantasBeard: Clothing
	{
		weight = 110;
		itemSize[] = {2,1};
	};
	class MouthRag: Clothing
	{
		weight = 75;
		itemSize[] = {1,2};
	};
	class SurgicalMask: Clothing
	{
		weight = 170;
		itemSize[] = {2,1};
	};
	class HockeyMask: Clothing
	{
		weight = 275;
		itemSize[] = {2,2};
	};
	class AthleticShoes_ColorBase: Clothing
	{
		weight = 165;
		itemSize[] = {2,2};
	};
	class HikingBoots_ColorBase: Clothing
	{
		weight = 200;
		itemSize[] = {2,2};
	};
	class HikingBootsLow_ColorBase: Clothing
	{
		weight = 135;
		itemSize[] = {2,2};
	};
	class Wellies_ColorBase: Clothing
	{
		weight = 350;
		itemSize[] = {2,2};
	};
	class WorkingBoots_ColorBase: Clothing
	{
		weight = 550;
		itemSize[] = {2,2};
	};
	class JungleBoots_ColorBase: Clothing
	{
		weight = 615;
		itemSize[] = {2,2};
	};
	class DressShoes_ColorBase: Clothing
	{
		weight = 390;
		itemSize[] = {2,2};
	};
	class MilitaryBoots_ColorBase: Clothing
	{
		weight = 550;
		itemSize[] = {2,2};
	};
	class CombatBoots_ColorBase: Clothing
	{
		weight = 675;
		itemSize[] = {2,2};
	};
	class JoggingShoes_ColorBase: Clothing
	{
		weight = 150;
		itemSize[] = {2,2};
	};
	class LeatherShoes_ColorBase: Clothing
	{
		weight = 190;
		itemSize[] = {2,2};
	};
	class Sneakers_ColorBase: Clothing
	{
		weight = 390;
		itemSize[] = {2,2};
	};
	class NBCBootsBase: Clothing
	{
		weight = 150;
		itemSize[] = {2,2};
	};
	class Ballerinas_ColorBase: Clothing
	{
		weight = 260;
		itemSize[] = {2,2};
	};
	class TTSKOBoots: Clothing
	{
		weight = 600;
		itemSize[] = {2,2};
	};
	class Armband_ColorBase: Clothing
	{
		weight = 40;
		itemSize[] = {1,2};
	};
};
