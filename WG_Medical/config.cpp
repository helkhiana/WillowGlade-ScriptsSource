class CfgPatches
{
	class WG_Medical
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class WG_Medical
	{
		dir = "WG_Medical";
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
				files[] = {"WillowGlade/WG_Medical/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Medical/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Medical/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class WG_Medkit_Base: Inventory_Base
	{
		scope=0;
		rotationFlags=17;
		weight=280;
		itemSize[]={2,2};
		healCosts[]={30,45};
		isMeleeWeapon=1;
		stackedUnit="percentage";
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		quantityBar=1;
		varQuantityDestroyOnMin=1;
	};

	class WG_AI2_Medkit: WG_Medkit_Base
	{
		scope=2;
		displayName="Personal Medkit";
		descriptionShort="First Aid Medkit which can be used to restore some health";
		model="\WillowGlade\WG_Medical\data\medkit\medkit.p3d";
		inventorySlot[] = {"PersonalMedKit1","PersonalMedKit2","PersonalMedKit3","PersonalMedKit4"};
		rotationFlags=17;
		weight=280;
		itemSize[]={2,2};
		healCosts[]={20,35};
		varQuantityInit=50;
		varQuantityMax=50;
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
								"WillowGlade\WG_Medical\data\medkit\data\medkit.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Medical\data\medkit\data\medkit.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Medical\data\medkit\data\medkit_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Medical\data\medkit\data\medkit_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Medical\data\medkit\data\medkit_destruct.rvmat"
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
				class Syringe_out
				{
					soundSet="Syringe_out_SoundSet";
					id=201;
				};
				class Syringe_spear
				{
					soundSet="Syringe_spear_SoundSet";
					id=202;
				};
				class Syringe_splash
				{
					soundSet="Syringe_splash_SoundSet";
					id=203;
				};
			};
		};
	};
	
	class WG_ITS_Medkit: WG_Medkit_Base
	{
		scope=2;
		displayName="ITS Survival Medkit";
		descriptionShort="ITS Survival Medkit can be used to restore health. It has more uses and it's more efficient than the personal medkit.";
		model="\WillowGlade\WG_Medical\data\medkit_its\medkit_its.p3d";
		inventorySlot[] = {"ITSMedKit1","ITSMedKit2","ITSMedKit3","ITSMedKit4"};
		rotationFlags=17;
		weight=1280;
		itemSize[]={3,3};
		healCosts[]={30,55};
		varQuantityInit=150;
		varQuantityMax=150;
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
								"WillowGlade\WG_Medical\data\medkit_its\data\medkit_its.rvmat"
							}
						},						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Medical\data\medkit_its\data\medkit_its.rvmat"
							}
						},						
						{
							0.5,
							
							{
								"WillowGlade\WG_Medical\data\medkit_its\data\medkit_its_damage.rvmat"
							}
						},						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Medical\data\medkit_its\data\medkit_its_damage.rvmat"
							}
						},						
						{
							0.0,
							
							{
								"WillowGlade\WG_Medical\data\medkit_its\data\medkit_its_destruct.rvmat"
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
				class Bandage_loop1
				{
					soundSet="Bandage_loop_SoundSet";
					id=201;
				};
				class Bandage_loop2
				{
					soundSet="Bandage_loop_SoundSet";
					id=202;
				};
				class Bandage_loop3
				{
					soundSet="Bandage_loop_SoundSet";
					id=203;
				};
				class Bandage_start
				{
					soundSet="Bandage_start_SoundSet";
					id=204;
				};
				class Bandage_end
				{
					soundSet="Bandage_end_SoundSet";
					id=205;
				};
			};
		};
	};

	class WG_EmergencyBandage: Inventory_Base
	{
		scope=2;
		displayName="Emergency Bandage";
		descriptionShort="Trauma wound bandage, heals all cuts";
		model="\WillowGlade\WG_Medical\data\emergencybandage\emergencybandage.p3d";
		inventorySlot[] = {"Medical1", "EmergencyBandage1","EmergencyBandage2","EmergencyBandage3","EmergencyBandage4"};
		isMeleeWeapon=1;
		varQuantityInit=2;
		varQuantityMin=0;
		varQuantityMax=2;
		quantityBar=1;
		varQuantityDestroyOnMin=1;
		rotationFlags=17;
		weight=115;
		absorbency=0.80000001;
		itemSize[]={3,2};
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{						
						{
							1,
							
							{
								"WillowGlade\WG_Medical\data\emergencybandage\data\emergencybandage.rvmat"
							}
						},						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Medical\data\emergencybandage\data\emergencybandage.rvmat"
							}
						},						
						{
							0.5,
							
							{
								"WillowGlade\WG_Medical\data\emergencybandage\data\emergencybandage_damage.rvmat"
							}
						},						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Medical\data\emergencybandage\data\emergencybandage_damage.rvmat"
							}
						},						
						{
							0,
							
							{
								"WillowGlade\WG_Medical\data\emergencybandage\data\emergencybandage_destruct.rvmat"
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
				class Bandage_loop1
				{
					soundSet="Bandage_loop_SoundSet";
					id=201;
				};
				class Bandage_loop2
				{
					soundSet="Bandage_loop_SoundSet";
					id=202;
				};
				class Bandage_loop3
				{
					soundSet="Bandage_loop_SoundSet";
					id=203;
				};
				class Bandage_start
				{
					soundSet="Bandage_start_SoundSet";
					id=204;
				};
				class Bandage_end
				{
					soundSet="Bandage_end_SoundSet";
					id=205;
				};
			};
		};
	};

	class WG_Surgicalkit_Base: Inventory_Base
	{
		scope=0;
		rotationFlags=1;
		weight=580;
		itemSize[]={3,2};
		isMeleeWeapon=1;
		varQuantityInit=5;
		varQuantityMin=0;
		varQuantityMax=5;
		quantityBar=0;
		varQuantityDestroyOnMin=1;
		class AnimEvents
		{
			class SoundWeapon
			{
				class Bandage_loop1
				{
					soundSet="Bandage_loop_SoundSet";
					id=201;
				};
				class Bandage_loop2
				{
					soundSet="Bandage_loop_SoundSet";
					id=202;
				};
				class Bandage_loop3
				{
					soundSet="Bandage_loop_SoundSet";
					id=203;
				};
				class Bandage_start
				{
					soundSet="Bandage_start_SoundSet";
					id=204;
				};
				class Bandage_end
				{
					soundSet="Bandage_end_SoundSet";
					id=205;
				};
			};
		};
	};

	class WG_ITS_Surgicalkit: WG_Surgicalkit_Base
	{
		scope=2;
		displayName="ITS Surgical Kit";
		descriptionShort="ITS Surgical Kit can be used to fix broken limbs.";
		model="\WillowGlade\WG_Medical\data\surgicalkit\surgicalkit.p3d";
		inventorySlot[] = {"SurgicalKit1","SurgicalKit2","SurgicalKit3","SurgicalKit4"};
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
								"WillowGlade\WG_Medical\data\surgicalkit\data\surgicalkit.rvmat"
							}
						},						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Medical\data\surgicalkit\data\surgicalkit.rvmat"
							}
						},						
						{
							0.5,
							
							{
								"WillowGlade\WG_Medical\data\surgicalkit\data\surgicalkit_damage.rvmat"
							}
						},						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Medical\data\surgicalkit\data\surgicalkit_damage.rvmat"
							}
						},						
						{
							0.0,
							
							{
								"WillowGlade\WG_Medical\data\surgicalkit\data\surgicalkit_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

/* 	class Man;
	class SurvivorBase: Man
	{
		class DamageSystem
		{
			class DamageZones
			{
				class RightLeg
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.33000001;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
				};
			};
		};	
	}; */
};