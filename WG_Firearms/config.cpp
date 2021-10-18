class CfgPatches
{
	class WG_Firearms
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Weapons_Ammunition"
		};
	};
};
class CfgMods
{
	class WG_Firearms
	{
		dir="WG_Firearms";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="WG_Firearms";
		credits="CashewSan";
		author="CashewSan";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Firearms/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Firearms/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Firearms/scripts/5_Mission"};
			};
		};
	};
};

class CfgMagazines
{
	class Ammo_12gaSlug;
	class Ammo_12gaPellets;
	class Ammo_12gaAPSlug: Ammo_12gaSlug
	{
		scope=2;
		displayName="12ga AP Rifled Slugs";
		descriptionShort="12ga AP shell with one rifled slug. Used in shotguns. Stronger than regular slugs.";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Firearms\ammunition\data\remington870_AP_ammo_co.paa"
		};
		count=20;
		ammo="Bullet_12GaugeAPSlug";
	};
	class Ammo_12gaAPPellets: Ammo_12gaPellets
	{
		scope=2;
		displayName="12ga AP Buckshot";
		descriptionShort="12ga AP buck shell with 8 pellets. Used in shotguns. Stronger than regular bucks shells.";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Firearms\ammunition\data\remington870_AP_ammo_co.paa"
		};
		count=20;
		ammo="Bullet_12GaugeAPPellets";
	};
	class Magazine_Base;
	class Mag_12gaSnaploader_2Rnd: Magazine_Base
	{
		ammoItems[]=
		{
			"Ammo_12gaPellets",
			"Ammo_12gaSlug",
			"Ammo_12gaRubberSlug",
			"Ammo_12gaAPSlug",
			"Ammo_12gaAPPellets"
		};
	};
	class Mag_Saiga_5Rnd: Magazine_Base
	{
		ammoItems[]=
		{
			"Ammo_12gaPellets",
			"Ammo_12gaSlug",
			"Ammo_12gaRubberSlug",
			"Ammo_12gaBeanbag",
			"Ammo_12gaAPSlug",
			"Ammo_12gaAPPellets"
		};
	};
	class Mag_Saiga_8Rnd: Magazine_Base
	{
		ammoItems[]=
		{
			"Ammo_12gaPellets",
			"Ammo_12gaSlug",
			"Ammo_12gaRubberSlug",
			"Ammo_12gaBeanbag",
			"Ammo_12gaAPSlug",
			"Ammo_12gaAPPellets"
		};
	};
	class Mag_Saiga_Drum20Rnd: Magazine_Base
	{
		ammoItems[]=
		{
			"Ammo_12gaPellets",
			"Ammo_12gaSlug",
			"Ammo_12gaRubberSlug",
			"Ammo_12gaBeanbag",
			"Ammo_12gaAPSlug",
			"Ammo_12gaAPPellets"
		};
	};
};

class Muzzle_Base;
class cfgWeapons
{
	class Shotgun_Base;
	class Izh43Shotgun_Base: Shotgun_Base
	{
		chamberableFrom[]=
		{
			"Ammo_12gaPellets",
			"Ammo_12gaSlug",
			"Ammo_12gaRubberSlug",
			"Ammo_12gaBeanbag",
			"Mag_12gaSnaploader_2Rnd",
			"Ammo_12gaAPSlug",
			"Ammo_12gaAPPellets"
		};
		class SecondMuzzle: Muzzle_Base
		{
			chamberableFrom[]=
			{
				"Ammo_12gaPellets",
				"Ammo_12gaSlug",
				"Ammo_12gaRubberSlug",
				"Mag_12gaSnaploader_2Rnd",
				"Ammo_12gaAPSlug",
				"Ammo_12gaAPPellets"
			};
		};
	};
	
	class SawedoffIzh43Shotgun: Izh43Shotgun_Base
	{
		class SecondMuzzle: SecondMuzzle
		{
			chamberableFrom[]=
			{
				"Ammo_12gaPellets",
				"Ammo_12gaSlug",
				"Ammo_12gaRubberSlug",
				"Mag_12gaSnaploader_2Rnd",
				"Ammo_12gaAPSlug",
				"Ammo_12gaAPPellets"
			};
		};
	};
	class Mp133Shotgun_Base: Shotgun_Base
	{
		chamberableFrom[]=
		{
			"Ammo_12gaPellets",
			"Ammo_12gaSlug",
			"Ammo_12gaRubberSlug",
			"Ammo_12gaBeanbag",
			"Ammo_12gaAPSlug",
			"Ammo_12gaAPPellets"
		};
	};
	class Rifle_Base;
	class Saiga_Base: Rifle_Base
	{
		chamberableFrom[]=
		{
			"Ammo_12gaPellets",
			"Ammo_12gaSlug",
			"Ammo_12gaRubberSlug",
			"Ammo_12gaBeanbag",
			"Ammo_12gaAPSlug",
			"Ammo_12gaAPPellets"
		};
	};
};
class CfgVehicles
{
	class Box_Base;
	class AmmoBox_12gaSlug_10Rnd;
	class AmmoBox_00buck_10rnd;
	class AmmoBox_12gaAPSlug_20Rnd: AmmoBox_12gaSlug_10Rnd
	{
		scope=2;
		displayName="Boxed 12ga AP Rifled Slugs";
		descriptionShort="A box of 20x 12ga AP rifled slugs.";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Firearms\ammunition\data\12ga_rifledapslug_10roundbox_co.paa"
		};
		class Resources
		{
			class Ammo_12gaAPSlug
			{
				value=20;
				variable="quantity";
			};
		};
	};
	class AmmoBox_12gaAPBuckshot_20rnd: AmmoBox_00buck_10rnd
	{
		scope=2;
		displayName="Boxed 12ga AP Buckshots";
		descriptionShort="A box of 12ga AP buckshots.";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Firearms\ammunition\data\12ga_rifledapslug_10roundbox_co.paa"
		};
		class Resources
		{
			class Ammo_12gaAPPellets
			{
				value=20;
				variable="quantity";
			};
		};
	};

	class FxCartridge_12Pellet;
	class FxCartridge_12Slug;
	class FxRound_12Pellet;
	class FxRound_12Slug;
	class FxCartridge_12APPellet: FxCartridge_12Pellet
	{
		model="\WillowGlade\WG_Firearms\ammunition\shotgunshell_pelletsproxy.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Firearms\ammunition\data\remington870_AP_ammo_co.paa"
		};
	};
	class FxCartridge_12APSlug: FxCartridge_12Slug
	{
		model="\WillowGlade\WG_Firearms\ammunition\shotgunshell_slugsproxy.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Firearms\ammunition\data\remington870_AP_ammo_co.paa"
		};
	};
	class FxRound_12APPellet: FxRound_12Pellet
	{
		model="\WillowGlade\WG_Firearms\ammunition\shotgunshell_pelletsproxy.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Firearms\ammunition\data\remington870_AP_ammo_co.paa"
		};
	};
	class FxRound_12APSlug: FxRound_12Slug
	{
		model="\WillowGlade\WG_Firearms\ammunition\shotgunshell_slugsproxy.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Firearms\ammunition\data\remington870_AP_ammo_co.paa"
		};
	};

	class Inventory_Base;
	class EnergyPistol : Inventory_Base
	{
		scope=2;
		model="\WillowGlade\WG_Firearms\energypistol\energypistol.p3d";
	};
};


class cfgAmmoTypes
{
	class AType_Bullet_12GaugeAPSlug
	{
		name="Bullet_12GaugeAPSlug";
	};
	class AType_Bullet_12GaugeAPPellets
	{
		name="Bullet_12GaugeAPPellets";
	};
};

class CfgAmmo
{
	class Bullet_12GaugeSlug;
	class Bullet_12GaugeAPSlug: Bullet_12GaugeSlug
	{
		scope=2;
		proxyShape="\WillowGlade\WG_Firearms\ammunition\shotgunshell_slugsproxy.p3d";
		spawnPileType="Ammo_12gaAPSlug";
		casing="FxCartridge_12APSlug";
		round="FxRound_12APSlug";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Firearms\ammunition\data\remington870_AP_ammo_co.paa"
		};
		class DamageApplied
		{
			type="Projectile";
			dispersion=0;
			bleedThreshold=1;
			defaultDamageOverride[]=
			{
				{0.5,1}
			};
			class Health
			{
				damage=170;
				armorDamage=3;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=100;
			};
		};
	};
	class Bullet_12GaugePellets;
	class Bullet_12GaugeAPPellets: Bullet_12GaugePellets
	{
		scope=2;
		proxyShape="\WillowGlade\WG_Firearms\ammunition\shotgunshell_pelletsproxy.p3d";
		spawnPileType="Ammo_12gaAPPellets";
		casing="FxCartridge_12APPellet";
		round="FxRound_12APPellet";
		class DamageApplied
		{
			type="Projectile";
			dispersion=0;
			bleedThreshold=1;
			defaultDamageOverride[]=
			{
				{0.5,1}
			};
			class Health
			{
				damage=50;
				armorDamage=1;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=33;
			};
		};
	};
};