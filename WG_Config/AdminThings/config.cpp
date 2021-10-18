class CfgPatches
{
	class WG_AdminThings
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Weapons_Firearms_AKM",
			"DZ_Weapons_Firearms_M4",
			"DZ_Weapons_Magazines",
			"DZ_Weapons_Ammunition",
			"DZ_Weapons_Projectiles"
		};
	};
};
class CfgVehicles
{
	class Msp_BeanBasher;

	class WG_ADM_BeanBasher: Msp_BeanBasher
	{
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeWGAdminBeanBasher";
				range=1.4;
			};
			class Heavy
			{
				ammo="MeleeWGAdminBeanBasher_Heavy";
				range=1.4;
			};
			class Sprint
			{
				ammo="MeleeWGAdminBeanBasher_Heavy";
				range=3.3;
			};
		};
	};
};
class CfgMagazines
{
	class Mag_AKM_30Rnd;
	class Mag_CMAG_30Rnd;

	class WG_ADM_Mag_AKM_900Rnd: Mag_AKM_30Rnd
	{
		scope=2;
		displayName="Admin AKM 900 Rnd";
		count=900;
		ammo="WG_ADM_Bullet_762x39";
		ammoItems[]=
		{
			"WG_ADM_Ammo_762x39",
			"Ammo_762x39",
			"Ammo_762x39Tracer"
		};
	};
	
	class Ammo_762x39;
	class WG_ADM_Ammo_762x39: Ammo_762x39
	{
		scope=2;
		displayName="Admin 7.62x39";
		count=900;
		ammo="WG_ADM_Bullet_762x39";
	};

	class WG_ADM_Mag_M4A1_900Rnd: Mag_CMAG_30Rnd
	{
		scope=2;
		displayName="Admin M4A1 900 Rnd";
		count=900;
		ammo="WG_ADM_Bullet_556x45";
		ammoItems[]=
		{
			"WG_ADM_Ammo_556x45",
			"Ammo_556x45",
			"Ammo_556x45Tracer"
		};
	};

	class Ammo_556x45;
	class WG_ADM_Ammo_556x45: Ammo_556x45
	{
		scope=2;
		displayName="Admin 556x45";
		count=900;
		ammo="WG_ADM_Bullet_556x45";
	};
};
class cfgWeapons
{
	class AKM;
	class M4A1;
	class WG_ADM_AKM: AKM
	{
		displayName="Admin AKM";
		chamberableFrom[]=
		{
			"WG_ADM_Ammo_762x39",
			"Ammo_762x39",
			"Ammo_762x39Tracer"
		};
		magazines[]=
		{
			"WG_ADM_Mag_AKM_900Rnd",
			"Mag_AKM_30Rnd",
			"Mag_AKM_Palm30Rnd",
			"Mag_AKM_Palm30Rnd_Black",
			"Mag_AKM_Palm30Rnd_Green",
			"Mag_AKM_Drum75Rnd",
			"Mag_AKM_Drum75Rnd_Green",
			"Mag_AKM_Drum75Rnd_Black",
			"Mag_AKM_Drum_TEST"
		};
	};
	class WG_ADM_M4A1: M4A1
	{
		displayName="Admin M4A1";
		chamberableFrom[]=
		{
			"WG_ADM_Ammo_556x45",
			"Ammo_556x45",
			"Ammo_556x45Tracer"
		};
		magazines[]=
		{
			"WG_ADM_Mag_M4A1_900Rnd",
			"Mag_STANAG_30Rnd",
			"Mag_STANAGCoupled_30Rnd",
			"Mag_CMAG_10Rnd",
			"Mag_CMAG_20Rnd",
			"Mag_CMAG_30Rnd",
			"Mag_CMAG_40Rnd",
			"Mag_CMAG_10Rnd_Green",
			"Mag_CMAG_20Rnd_Green",
			"Mag_CMAG_30Rnd_Green",
			"Mag_CMAG_40Rnd_Green",
			"Mag_CMAG_10Rnd_Black",
			"Mag_CMAG_20Rnd_Black",
			"Mag_CMAG_30Rnd_Black",
			"Mag_CMAG_40Rnd_Black"
		};
	};
};
class CfgAmmo
{
	class MeleeMachete;
	class MeleeMachete_Heavy;

	class MeleeWGAdminBeanBasher: MeleeMachete
	{
		affectSkeleton=0.2;
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=800;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=15;
			};
			additionAnimalMeleeMultiplier=3;
		};
	};
	class MeleeWGAdminBeanBasher_Heavy: MeleeMachete_Heavy
	{
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=2000;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=15;
			};
			additionAnimalMeleeMultiplier=3;
		};
		hitAnimation=1;
	};
	
	class Bullet_762x39;
	class WG_ADM_Bullet_762x39: Bullet_762x39
	{
		scope=2;
		casing="FxCartridge_762x39";
		round="FxRound_762x39";
		spawnPileType="WG_ADM_Ammo_762x39";
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
				damage=1000;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=66;
			};
		};
	};

	class Bullet_556x45;
	class WG_ADM_Bullet_556x45: Bullet_556x45
	{
		scope=2;
		spawnPileType="WG_ADM_Ammo_556x45";
		casing="FxCartridge_556";
		round="FxRound_556";
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
				damage=1000;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=66;
			};
		};
	};
};

class cfgAmmoTypes
{
	class AType_WG_ADM_Bullet_762x39
	{
		name="WG_ADM_Bullet_762x39";
	};

	class AType_WG_ADM_Bullet_556x45
	{
		name="WG_ADM_Bullet_556x45";
	};
};