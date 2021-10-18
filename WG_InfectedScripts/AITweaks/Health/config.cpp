class CfgPatches
{
	class DZ_Characters_Zombies
	{
		units[]=
		{
			"Hermit_NewAI"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters",
			"DZ_AI"
		};
	};
};

class CfgVehicles
{
	class ZombieMaleBase;
	class DayZInfected;
	class ZombieFemaleBase;
    class ZombieBase: DayZInfected
	{
		attachments[]=
		{
			"Shoulder",
			"Melee",
			"Vest",
			"Hips",
			"Back",
			"Headgear",
			"Mask",
			"Gloves",
			"Armband"
		};
		class InventoryEquipment
		{
			playerSlots[]=
			{
				"Slot_Shoulder",
				"Slot_Melee",
				"Slot_Vest",
				"Slot_Hips",
				"Slot_Back",
				"Slot_Headgear",
				"Slot_Mask",
				"Slot_Gloves",
				"Slot_Armband"
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,8};
			allowOwnedCargoManipulation=1;
			openable=0;
		};		
		class Skinning
		{
			class ObtainedBones
			{
				item="Bone";
				count=1;
				quantityMinMaxCoef[]={0.1,0.4};
				transferToolDamageCoef=1;
			};
		};		
	};
	class ZmbM_HunterOld_Base: ZombieMaleBase
	{		
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
    class ZmbM_PolicemanFat_Base: ZombieMaleBase
	{				
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
    class ZmbF_PoliceWomanNormal_Base: ZombieFemaleBase
	{			
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
	class ZmbM_PolicemanSpecForce_Base: ZombieMaleBase
	{	
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
	class ZmbM_SoldierNormal_Base: ZombieMaleBase
	{		
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
    class ZmbM_usSoldier_normal_Base: ZombieMaleBase
	{		
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
    class ZmbM_PatrolNormal_Base: ZombieMaleBase
	{	
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
    class ZmbM_DoctorFat_Base: ZombieMaleBase
	{		
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
	class ZmbM_priestPopSkinny_Base: ZombieMaleBase
	{		
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
	
	class ZmbF_usSoldier_Officer_Desert: ZmbF_PoliceWomanNormal_Base
	{
		scope=2;
		aiAgentTemplate="InfectedSoldier_Officer";
		hiddenSelectionsMaterials[]=
		{
			"WillowGlade\WG_InfectedScripts\data\milwoman_normal_f.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_InfectedScripts\data\milwoman_normal_f_co.paa"
		};
		class AnimEvents
		{
			class SoundVoice
			{
				class LightHit
				{
					soundSet="ZmbF_Normal_LightHit_Soundset";
					id=1;
				};
				class HeavyHit
				{
					soundSet="ZmbF_Normal_HeavyHit_Soundset";
					id=2;
				};
				class Attack
				{
					soundSet="ZmbF_Normal_Attack_Soundset";
					id=5;
				};
				class Jump
				{
					soundSet="ZmbF_Normal_Jump_Soundset";
					id=10;
				};
				class Land
				{
					soundSet="ZmbF_Normal_Land_Soundset";
					id=11;
				};
				class CallToArmsShort
				{
					soundSet="ZmbF_Skinny_CallToArmsShort_Soundset";
					id=20;
				};
			};
		};
	};	
};