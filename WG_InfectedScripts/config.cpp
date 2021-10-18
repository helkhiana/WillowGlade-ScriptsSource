class CfgPatches
{
	class WG_InfectedScripts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters_Zombies"};
	};
};

class CfgMods
{
	class WG_InfectedScripts
	{
		dir = "WG_InfectedScripts";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "";
		credits = "";
		author = "Helkhiana";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_InfectedScripts/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_InfectedScripts/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_InfectedScripts/scripts/5_Mission"};
			};
		};
	};
};


class CfgVehicles
{	
	class ZmbM_CitizenASkinny_Red;
	
	class AttackActions;
	class AttackLong;
	class AttackRun;
	class AttackShort;
	class AttackShortLow;
	class CrawlAttackMove;
	class CrawlAttackStill;
	class ZombieMaleBase;
	
	class ZmbF_PoliceWomanNormal_Base;
	class ZmbF_MilWoman: ZmbF_PoliceWomanNormal_Base
	{
		scope=2;
		hiddenSelectionsMaterials[]=
		{
			"WillowGlade\WG_InfectedScripts\data\milwoman_normal_f.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_InfectedScripts\data\milwoman_normal_f_co.paa"
		};
	};
	class WG_Infected_15X : ZmbM_CitizenASkinny_Red
	{
		scope=0;
		class AttackActions: AttackActions
		{
			class AttackLong: AttackLong
			{
				attackName="attackLong";
				ammoType="MeleeZombieBoss";
			};
			class AttackRun: AttackRun
			{
				attackName="attackRun";
				ammoType="MeleeZombieBoss";
			};
			class AttackShort: AttackShort
			{
				attackName="attackShort";
				ammoType="MeleeZombieBoss";
			};
			class AttackShortLow: AttackShortLow
			{
				attackName="attackShortLow";
				ammoType="MeleeZombieBoss";
			};
			class CrawlAttackMove: CrawlAttackMove
			{
				attackName="crawlAttackMove";
				ammoType="MeleeZombieBoss";
			};
			class CrawlAttackStill: CrawlAttackStill
			{
				attackName="crawlAttackStill";
				ammoType="MeleeZombieBoss";
			};
		};			
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=45;
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=150;
					};
				};
				class LeftArm
				{
					class Health
					{
						hitpoints=150;
					};
				};
				class RightArm
				{
					class Health
					{
						hitpoints=150;
					};
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=150;
					};
				};
				class RightLeg
				{
					class Health
					{
						hitpoints=150;
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=150;
					};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints=150;
					};
				};
			};
		};
	};
	class WG_Infected_2X : ZmbM_CitizenASkinny_Red
	{
		scope=0;		
		class AttackActions: AttackActions
		{
			class AttackLong: AttackLong
			{
				attackName="attackLong";
				ammoType="MeleeZombieSoldier";
			};
			class AttackRun: AttackRun
			{
				attackName="attackRun";
				ammoType="MeleeZombieSoldier";
			};
			class AttackShort: AttackShort
			{
				attackName="attackShort";
				ammoType="MeleeZombieSoldier";
			};
			class AttackShortLow: AttackShortLow
			{
				attackName="attackShortLow";
				ammoType="MeleeZombieSoldier";
			};
			class CrawlAttackMove: CrawlAttackMove
			{
				attackName="crawlAttackMove";
				ammoType="MeleeZombieSoldier";
			};
			class CrawlAttackStill: CrawlAttackStill
			{
				attackName="crawlAttackStill";
				ammoType="MeleeZombieSoldier";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=60;
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=200;
					};
				};
				class LeftArm
				{
					class Health
					{
						hitpoints=200;
					};
				};
				class RightArm
				{
					class Health
					{
						hitpoints=200;
					};
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=200;
					};
				};
				class RightLeg
				{
					class Health
					{
						hitpoints=200;
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=200;
					};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints=200;
					};
				};
			};
		};
	};
	class WG_Infected_4X : ZmbM_CitizenASkinny_Red
	{
		scope=0;	
		class AttackActions: AttackActions
		{
			class AttackLong: AttackLong
			{
				attackName="attackLong";
				ammoType="MeleeZombieHigh";
			};
			class AttackRun: AttackRun
			{
				attackName="attackRun";
				ammoType="MeleeZombieHigh";
			};
			class AttackShort: AttackShort
			{
				attackName="attackShort";
				ammoType="MeleeZombieHigh";
			};
			class AttackShortLow: AttackShortLow
			{
				attackName="attackShortLow";
				ammoType="MeleeZombieHigh";
			};
			class CrawlAttackMove: CrawlAttackMove
			{
				attackName="crawlAttackMove";
				ammoType="MeleeZombieHigh";
			};
			class CrawlAttackStill: CrawlAttackStill
			{
				attackName="crawlAttackStill";
				ammoType="MeleeZombieHigh";
			};
		};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=400;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=120;
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=400;
					};
				};
				class LeftArm
				{
					class Health
					{
						hitpoints=400;
					};
				};
				class RightArm
				{
					class Health
					{
						hitpoints=400;
					};
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=400;
					};
				};
				class RightLeg
				{
					class Health
					{
						hitpoints=400;
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=400;
					};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints=400;
					};
				};
			};
		};
	};
	class WG_Infected_6X : ZmbM_CitizenASkinny_Red
	{
		scope=0;
		class AttackActions: AttackActions
		{
			class AttackLong: AttackLong
			{
				attackName="attackLong";
				ammoType="MeleeZombieVeryHigh";
			};
			class AttackRun: AttackRun
			{
				attackName="attackRun";
				ammoType="MeleeZombieVeryHigh";
			};
			class AttackShort: AttackShort
			{
				attackName="attackShort";
				ammoType="MeleeZombieVeryHigh";
			};
			class AttackShortLow: AttackShortLow
			{
				attackName="attackShortLow";
				ammoType="MeleeZombieVeryHigh";
			};
			class CrawlAttackMove: CrawlAttackMove
			{
				attackName="crawlAttackMove";
				ammoType="MeleeZombieVeryHigh";
			};
			class CrawlAttackStill: CrawlAttackStill
			{
				attackName="crawlAttackStill";
				ammoType="MeleeZombieVeryHigh";
			};
		};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=600;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=180;
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class LeftArm
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class RightArm
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class RightLeg
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints=600;
					};
				};
			};
		};		
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=1;
				};
				class Walk2
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=2;
				};
				class Walk3
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=3;
				};
				class Walk4
				{
					soundLookupTable="walkErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=4;
				};
				class Run1
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=5;
				};
				class Run2
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=6;
				};
				class Run3
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=7;
				};
				class Run4
				{
					soundLookupTable="runErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=8;
				};
				class Sprint1
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=9;
				};
				class Sprint2
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=10;
				};
				class Sprint3
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=11;
				};
				class Sprint4
				{
					soundLookupTable="sprintErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=12;
				};
				class Scuff1
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=17;
				};
				class Scuff2
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=18;
				};
				class Sccuff3
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=19;
				};
				class Scuff4
				{
					soundLookupTable="scuffErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=20;
				};
				class landFeetErc
				{
					soundLookupTable="landFeetErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=21;
				};
				class landFootErc
				{
					soundLookupTable="landFootErc_Boots_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=22;
				};
				class Bodyfall
				{
					soundLookupTable="bodyfall_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=23;
				};
				class Bodyfall_Hand
				{
					soundLookupTable="bodyfall_hand_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=24;
				};
				class Bodyfall_Slide
				{
					soundLookupTable="bodyfall_slide_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=25;
				};
				class Prone_Walk_L
				{
					soundLookupTable="walkProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=27;
				};
				class Prone_Walk_R
				{
					soundLookupTable="walkProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=28;
				};
				class Prone_Run_L
				{
					soundLookupTable="runProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=29;
				};
				class Prone_Run_R
				{
					soundLookupTable="runProne_Zmb_LookupTable";
					noise="ZombieStepNoise";
					id=30;
				};
			};
			class Sounds
			{
				class Attack_Light1
				{
					soundSet="WG_Monster_Attack_SoundShader";
					id=1;
				};
				class Attack_Light2
				{
					soundSet="WG_Monster_Attack_SoundShader";
					id=2;
				};
				class Attack_Heavy1
				{
					soundSet="WG_Monster_Attack_SoundShader";
					id=3;
				};
				class Attack_Heavy2
				{
					soundSet="WG_Monster_Attack_SoundShader";
					id=4;
				};
				class TwoHands
				{
					soundSet="WG_Monster_Attack_SoundShader";
					id=5;
				};
			};
			class SoundVoice
			{
				class LightHit
				{
					soundSet="WG_Monster_Hit_Soundset";
					id=1;
				};
				class HeavyHit
				{
					soundSet="WG_Monster_Hit_Soundset";
					id=2;
				};
				class Attack
				{
					soundSet="WG_Monster_Attack_Soundset";
					id=5;
				};
				class Jump
				{
					soundSet="ZmbM_Skinny_Old_Jump_Soundset";
					id=10;
				};
				class Land
				{
					soundSet="ZmbM_Skinny_Old_Land_Soundset";
					id=11;
				};
				class CallToArmsShort
				{
					soundSet="WG_Monster_CallToArms_Soundset";
					id=20;
				};
			};
		};
	};
	class WG_Infected_Clown: WG_Infected_4X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\clown.p3d";	
	};
	
	class WG_Infected_ToxicMutant: WG_Infected_4X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\mutant.p3d";
	};
	
	class WG_Infected_Wendigo1: WG_Infected_4X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\wendigo1.p3d";
	};
	
	class WG_Infected_Wendigo2: WG_Infected_4X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\wendigo2.p3d";
	};

	class WG_Infected_Maniac: WG_Infected_2X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\maniac\maniac_simple.p3d";
	};
	class WG_Infected_ManiacMasked: WG_Infected_2X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\maniac\maniac_masked.p3d";
	};
	class WG_Infected_ManiacMonster: WG_Infected_4X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\maniac\maniac_monster.p3d";
	};
	class WG_Infected_Scarecrow: WG_Infected_4X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\maniac\maniac_scarecrow.p3d";
	};
	class WG_Infected_ToxicPumpkin: WG_Infected_6X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\maniac\maniac_toxicpumpkin.p3d";
	};
	class WG_Infected_EvilPumpkin: WG_Infected_6X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\maniac\maniac_evilpumpkin.p3d";
	};

	class WG_Infected_PumpkinBoss: WG_Infected_6X
	{
		scope = 2;
		model = "WillowGlade\WG_Infected\maniac\maniac_toxicpumpkin.p3d";
		class AttackActions: AttackActions
		{
			class AttackLong: AttackLong
			{
				attackName="attackLong";
				ammoType="MeleeZombieBoss";
			};
			class AttackRun: AttackRun
			{
				attackName="attackRun";
				ammoType="MeleeZombieBoss";
			};
			class AttackShort: AttackShort
			{
				attackName="attackShort";
				ammoType="MeleeZombieBoss";
			};
			class AttackShortLow: AttackShortLow
			{
				attackName="attackShortLow";
				ammoType="MeleeZombieBoss";
			};
			class CrawlAttackMove: CrawlAttackMove
			{
				attackName="crawlAttackMove";
				ammoType="MeleeZombieBoss";
			};
			class CrawlAttackStill: CrawlAttackStill
			{
				attackName="crawlAttackStill";
				ammoType="MeleeZombieBoss";
			};
		};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20000;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=9000;
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=20000;
					};
				};
				class LeftArm
				{
					class Health
					{
						hitpoints=20000;
					};
				};
				class RightArm
				{
					class Health
					{
						hitpoints=20000;
					};
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=20000;
					};
				};
				class RightLeg
				{
					class Health
					{
						hitpoints=20000;
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=20000;
					};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints=20000;
					};
				};
			};
		};		
		class AnimEvents
		{
			class Sounds
			{
				class Attack_Light1
				{
					soundSet="WG_MonsterBoss_Attack_SoundShader";
					id=1;
				};
				class Attack_Light2
				{
					soundSet="WG_MonsterBoss_Attack_SoundShader";
					id=2;
				};
				class Attack_Heavy1
				{
					soundSet="WG_MonsterBoss_Attack_SoundShader";
					id=3;
				};
				class Attack_Heavy2
				{
					soundSet="WG_MonsterBoss_Attack_SoundShader";
					id=4;
				};
				class TwoHands
				{
					soundSet="WG_MonsterBoss_Attack_SoundShader";
					id=5;
				};
			};
			class SoundVoice
			{
				class LightHit
				{
					soundSet="WG_MonsterBoss_Hit_Soundset";
					id=1;
				};
				class HeavyHit
				{
					soundSet="WG_MonsterBoss_Hit_Soundset";
					id=2;
				};
				class Attack
				{
					soundSet="WG_MonsterBoss_Attack_Soundset";
					id=5;
				};
				class Jump
				{
					soundSet="ZmbM_Skinny_Old_Jump_Soundset";
					id=10;
				};
				class Land
				{
					soundSet="ZmbM_Skinny_Old_Land_Soundset";
					id=11;
				};
				class CallToArmsShort
				{
					soundSet="WG_MonsterBoss_CallToArms_Soundset";
					id=20;
				};
			};
		};
	};
};


class CfgAmmo
{
	class MeleeZombie;
	
	class MeleeZombieSoldier: MeleeZombie
	{
		class DamageApplied
		{
			type="Infected";
			bleedThreshold=0.30000001;
			class Health
			{
				damage=10;
				armorDamage=0.80000001;
			};
			class Blood
			{
				damage=15;
			};
			class Shock
			{
				damage=15;
			};
		};
	};
	class MeleeZombieMedium: MeleeZombie
	{
		class DamageApplied
		{
			type="Infected";
			bleedThreshold=0.27000001;
			additionAnimalMeleeMultiplier=1;
			class Health
			{
				damage=11;
				armorDamage=1;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=15;
			};
		};
	};
	class MeleeZombieHigh: MeleeZombie
	{
		class DamageApplied
		{
			type="Infected";
			bleedThreshold=0.27000001;
			additionAnimalMeleeMultiplier=1;
			class Health
			{
				damage=18;
				armorDamage=1;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=20;
			};
		};
	};
	class MeleeZombieVeryHigh: MeleeZombie
	{
		class DamageApplied
		{
			type="Infected";
			bleedThreshold=0.37000001;
			additionAnimalMeleeMultiplier=1;
			class Health
			{
				damage=25;
				armorDamage=1;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=20;
			};
		};
	};	
	class MeleeZombieBoss: MeleeZombie
	{
		class DamageApplied
		{
			type="Infected";
			bleedThreshold=0.37000001;
			additionAnimalMeleeMultiplier=1;
			class Health
			{
				damage=50;
				armorDamage=1;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=20;
			};
		};
	};	
};

class CfgSoundTables
{
	class CfgStepSoundTables
	{
	};
};
class CfgSoundShaders
{
	class WG_Monster_Attack_SoundShader
	{
		samples[]=
		{
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Attack_01",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Attack_02",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Attack_03",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Attack_04",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Attack_05",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Attack_06",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Attack_07",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Attack_08",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Attack_09",
				0.125
			}
		};
		volume=0.5;
		range=75;
	};

	class WG_MonsterBoss_Attack_SoundShader : WG_Monster_Attack_SoundShader
	{
		volume=0.8;
		frequency=0.5;
	};
	
	class WG_Monster_Hit_SoundShader
	{
		samples[]=
		{
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Threaten_01",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Threaten_02",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Threaten_03",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Threaten_07",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Threaten_08",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Threaten_09",
				0.125
			}
		};
		volume=1;
		range=60;
	};
	class WG_MonsterBoss_Hit_SoundShader : WG_Monster_Hit_SoundShader
	{
		frequency=0.5;
	};
	class WG_Monster_CallToArms_SoundShader
	{
		samples[]=
		{
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Threaten_Aggressive_01",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Threaten_Aggressive_02",
				0.125
			},
			
			{
				"WillowGlade\WG_InfectedScripts\sounds\monster_beast01\WAV_UI_BEAST_01_Threaten_Aggressive_03",
				0.125
			}
		};
		volume=1;
		range=60;
	};
	class WG_MonsterBoss_CallToArms_SoundShader : WG_Monster_CallToArms_SoundShader
	{
		volume=3.0;
		frequency=0.5;
	};
};

class CfgSoundSets
{
	class Zmb_VoiceFX_Base_SoundSet;
	class WG_Monster_Attack_Soundset
	{
		soundShaders[]=
		{
			"WG_Monster_Attack_SoundShader"
		};
		sound3DProcessingType="infected3DProcessingType";
		volumeCurve="infectedAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class WG_Monster_Hit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[]=
		{
			"WG_Monster_Hit_SoundShader"
		};
		frequencyFactor=0.92000002;
	};
	class WG_Monster_CallToArms_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[]=
		{
			"WG_Monster_CallToArms_SoundShader"
		};
		frequencyFactor=0.92000002;
	};

	
	class WG_MonsterBoss_Attack_Soundset
	{
		soundShaders[]=
		{
			"WG_MonsterBoss_Attack_SoundShader"
		};
		sound3DProcessingType="infected3DProcessingType";
		volumeCurve="infectedAttenuationCurve";
		spatial=1;
		frequencyRandomizer = 6;
		frequencyFactor = 1;
		doppler=0;
		loop=0;
	};
	class WG_MonsterBoss_Hit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[]=
		{
			"WG_MonsterBoss_Hit_SoundShader"
		};
		frequencyRandomizer = 6;
		frequencyFactor = 1;
	};
	class WG_MonsterBoss_CallToArms_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[]=
		{
			"WG_MonsterBoss_CallToArms_SoundShader"
		};
		frequencyRandomizer = 6;
		frequencyFactor = 1;
	};
};