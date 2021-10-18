class CfgPatches
{
	class WG_Deagle
	{
		units[]=
		{
			"WG_Deagle"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Pistols_DE"
		};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class FNX45;
	class Deagle;
	class Pistol_Base;
	class WG_Deagle_Base: FNX45
	{
		scope=0;
		weight=2050;
		absorbency=0;
		repairableWithKits[]={5,1};
		repairCosts[]={30,25};
		PPDOFProperties[]={1,0.5,10,250,4,10};
		ironsightsExcludingOptics[]=
		{
			"FNP45_MRDSOptic"
		};
		WeaponLength=0.634148;
		chamberSize=1;
		chamberedRound="";
		magazines[]=
		{			
			"Mag_Deagle_9rnd",
			"WG_Mag_Deagle_9Rnd",
			"WG_Mag_Deagle_13rnd"
		};
		chamberableFrom[]=
		{
			"Ammo_357"
		};
		ejectType=1;
		recoilModifier[]={1.5,1.5,1.5};
		swayModifier[]={1.2,1.2,1};
		drySound[]=
		{
			"dz\sounds\weapons\firearms\FNX45\FNX45_dry",
			0.5,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"dz\sounds\weapons\firearms\FNX45\FNX45_reload",
			0.80000001,
			1,
			20
		};
		modes[]=
		{
			"SemiAuto"
		};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"Magnum_Shot_SoundSet",
				"Magnum_Tail_SoundSet",
				"Magnum_InteriorTail_SoundSet"
			};
			reloadTime=0.3;
			recoil="recoil_fnx";
			recoilProne="recoil_fnx_prone";
			dispersion=0.0060000001;
			magazineSlot="magazine";
		};
		class OpticsInfo: OpticsInfoPistol
		{
			memoryPointCamera="eye";
			discreteDistance[]={25};
			discreteDistanceInitIndex=0;
			modelOptics="-";
			distanceZoomMin=100;
			distanceZoomMax=100;
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlashForward
				{
					ignoreIfSuppressed=1;
					illuminateWorld=1;
					overrideParticle="weapon_shot_fnx_01";
				};
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke_small";
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating=1;
				maxOverheatingValue=7;
				overheatingDecayInterval=1;
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen=1;
					overrideParticle="smoking_barrel_small";
					overridePoint="Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle="weapon_shot_chamber_smoke_raise";
					overridePoint="Nabojnicestart";
				};
			};
		};
	};
	
	class Deagle_Base: Pistol_Base
	{
		magazines[]=
		{
			"Mag_Deagle_9rnd",
			"WG_Mag_Deagle_9Rnd",
			"WG_Mag_Deagle_13rnd"
		};
	};
	class WG_Deagle: Deagle
	{
		scope=2;
		model="WillowGlade\WG_Firearms\Deagle\Deagle.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=220;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"dz\weapons\pistols\DE\data\deagle.rvmat",
								"dz\weapons\pistols\DE\data\deagle_plastic.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"dz\weapons\pistols\DE\data\deagle.rvmat",
								"dz\weapons\pistols\DE\data\deagle_plastic.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"dz\weapons\pistols\DE\data\deagle_damage.rvmat",
								"dz\weapons\pistols\DE\data\deagle_plastic_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"dz\weapons\pistols\DE\data\deagle_damage.rvmat",
								"dz\weapons\pistols\DE\data\deagle_plastic_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"dz\weapons\pistols\DE\data\deagle_destruct.rvmat",
								"dz\weapons\pistols\DE\data\deagle_plastic_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};
class CfgMagazines
{
	class Magazine_Base;
	class WG_Mag_Deagle_9rnd: Magazine_Base
	{
		scope=2;
		displayName="9rnd Desert Eagle Magazine";
		descriptionShort="9 round Magazine for the Deagle, loaded with .357 rounds.";
		model="WillowGlade\WG_Firearms\Deagle\mag_Deagle_9rnd.p3d";
		weight=150;
		itemSize[]={1,2};
		count=9;
		ammo="Bullet_357";
        ammoItems[]=
		{
			"Ammo_357"
		};
		tracersEvery=0;
		mass=10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"DZ\weapons\attachments\data\cz75_mag.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\attachments\data\cz75_mag.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\attachments\data\cz75_mag_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\attachments\data\cz75_mag_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"DZ\weapons\attachments\data\cz75_mag_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	};
	class WG_Mag_Deagle_13rnd: WG_Mag_Deagle_9rnd
	{
		scope=2;
		displayName="13rnd Desert Eagle Magazine";
		descriptionShort="13 round Magazine for the Deagle, loaded with .357 rounds.";
		model="WillowGlade\WG_Firearms\Deagle\mag_Deagle_13rnd.p3d";
		weight=150;
		itemSize[]={1,3};
		count=13;
	};
};
