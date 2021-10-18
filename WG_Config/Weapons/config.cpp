class CfgPatches
{
	class WG_Tweaked_MSP_Weapons
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"MSP_Weapons_Data"
		};
	};
};
class CfgVehicles
{
	class BaseballBat;
	class Msp_BeanBasher: BaseballBat
	{
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeWGBeanBasher";
				range=1.5;
			};
			class Heavy
			{
				ammo="MeleeWGBeanBasher_Heavy";
				range=1.5;
			};
			class Sprint
			{
				ammo="MeleeWGBeanBasher_Heavy";
				range=3.8;
			};
		};
	};

	class Msp_PipeAxe: Msp_BeanBasher
	{
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeWGBeanBasher";
				range=1.5;
			};
			class Heavy
			{
				ammo="MeleeWGBeanBasher_Heavy";
				range=1.5;
			};
			class Sprint
			{
				ammo="MeleeWGBeanBasher_Heavy";
				range=3.8;
			};
		};
	};

	class Msp_PlainBat: Msp_BeanBasher
	{
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeWGBat";
				range=1.5;
			};
			class Heavy
			{
				ammo="MeleeWGBat_Heavy";
				range=1.5;
			};
			class Sprint
			{
				ammo="MeleeWGBat_Heavy";
				range=3.8;
			};
		};
	};

	class Msp_GoodNightBat: BaseballBat
	{
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeWGBat";
				range=1.5;
			};
			class Heavy
			{
				ammo="MeleeWGBat_Heavy";
				range=1.5;
			};
			class Sprint
			{
				ammo="MeleeWGBat_Heavy";
				range=3.8;
			};
		};
	};
	
	class Msp_BlunderBat: BaseballBat
 	{
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeWGBlunderBat";
				range=1.5;
			};
			class Heavy
			{
				ammo="MeleeWGBlunderBat_Heavy";
				range=1.5;
			};
			class Sprint
			{
				ammo="MeleeWGBlunderBat_Heavy";
				range=3.8;
			};
		};
	};
	
	class Msp_BassAxe: Msp_BlunderBat
	{
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeWGBlunderBat";
				range=1.5;
			};
			class Heavy
			{
				ammo="MeleeWGBlunderBat_Heavy";
				range=1.5;
			};
			class Sprint
			{
				ammo="MeleeWGBlunderBat_Heavy";
				range=3.8;
			};
		};
	};

};

class CfgAmmo
{
	class MeleeHatchet;
	class MeleeHatchet_Heavy;
	class MeleeBat;
	class MeleeBat_Heavy;
	class MeleeWGBeanBasher: MeleeHatchet
	{
		affectSkeleton=0.2;
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=200;
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
	class MeleeWGBeanBasher_Heavy: MeleeHatchet_Heavy
	{
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=250;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=15;
			};
		};
		hitAnimation=1;
	};

	class MeleeWGBlunderBat: MeleeHatchet
	{
		affectSkeleton=0.2;
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=300;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=15;
			};
		};
	};
	class MeleeWGBlunderBat_Heavy: MeleeHatchet_Heavy
	{
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=350;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=15;
			};
		};
		hitAnimation=1;
	};
	class MeleeWGBat: MeleeBat
	{
		affectSkeleton=0.2;
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=100;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=15;
			};
		};
	};
	class MeleeWGBat_Heavy: MeleeBat_Heavy
	{
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=150;
			};
			class Blood
			{
				damage=100;
			};
			class Shock
			{
				damage=15;
			};
		};
		hitAnimation=1;
	};
};