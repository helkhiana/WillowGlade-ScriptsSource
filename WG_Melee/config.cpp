class CfgPatches
{
	class WG_Melee
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class WG_Melee
	{
		dir = "WG_Melee";
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
				files[] = {"WillowGlade/WG_Melee/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Melee/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Melee/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class SteakKnife;
	class StoneKnife;
	class Inventory_Base;
	class KitchenKnife;
	class Machete;
	class Sword;
	class WG_Improvised_Shiv: SteakKnife
	{
		scope=2;
		displayName="Improvised Shiv";
		descriptionShort="Improvised Shiv, low quality and it breaks easily";
		model="\WillowGlade\WG_Melee\improvisedmelee\shiv.p3d";
		repairableWithKits[]={4};
		itemSize[]={1,3};
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
							1.0,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class WG_Improvised_FlintKnife: StoneKnife
	{
		scope=2;
		displayName="Improvised Flint Knife";
		descriptionShort="Improvised flint knife, low quality and it breaks easily";
		model="\WillowGlade\WG_Melee\improvisedmelee\flintknife.p3d";
		repairableWithKits[]={4};
		itemSize[]={1,3};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class WG_Improvised_Knife: KitchenKnife
	{
		scope=2;
		displayName="Knife";
		descriptionShort="Improvised knife, low quality and it breaks easily";
		model="\WillowGlade\WG_Melee\improvisedmelee\knife.p3d";
		repairableWithKits[]={4};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=80;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class WG_Improvised_Machete: Machete
	{
		scope=2;
		displayName="Improvised Machete";
		descriptionShort="Improvised machete, low quality and it breaks easily";
		model="\WillowGlade\WG_Melee\improvisedmelee\machete.p3d";
		repairableWithKits[]={4};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=80;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class WG_Improvised_Spear_Base: Inventory_Base
	{
		scope=0;
		repairableWithKits[]={4};
		repairCosts[]={30,25};
		rotationFlags=17;
		weight=700;
		itemSize[]={1,9};
		inventorySlot[]=
		{
			"Shoulder",
			"Melee"
		};
		suicideAnim="spear";
		itemBehaviour=2;
		openItemSpillRange[]={20,40};
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
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Melee\improvisedmelee\data\impwp_piercing_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeSpear";
				range=1.8;
			};
			class Heavy
			{
				ammo="MeleeSpear_Heavy";
				range=1.8;
			};
			class Sprint
			{
				ammo="MeleeSpear_Heavy";
				range=3.7;
			};
		};
	};	
	class WG_Improvised_FlintSpear: WG_Improvised_Spear_Base
	{
		scope=2;
		displayName="Improvised Flint Spear";
		descriptionShort="Improvised spear from a flint, low quality and it breaks easily";
		model="\WillowGlade\WG_Melee\improvisedmelee\spear1.p3d";
	};
	class WG_Improvised_ShivSpear: WG_Improvised_Spear_Base
	{
		scope=2;
		displayName="Improvised Shiv Spear";
		descriptionShort="Improvised spear from a small piece of metal, low quality and it breaks easily";
		model="\WillowGlade\WG_Melee\improvisedmelee\spear2.p3d";
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeSpear";
				range=2.3;
			};
			class Heavy
			{
				ammo="MeleeSpear_Heavy";
				range=2.3;
			};
			class Sprint
			{
				ammo="MeleeSpear_Heavy";
				range=4.2;
			};
		};
	};
	class WG_Improvised_LongSpear: WG_Improvised_Spear_Base
	{
		scope=2;
		displayName="Improvised Long Spear";
		descriptionShort="Improvised spear from a long piece of metal, low quality and it breaks easily";
		model="\WillowGlade\WG_Melee\improvisedmelee\spear3.p3d";
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeSpear";
				range=2.3;
			};
			class Heavy
			{
				ammo="MeleeSpear_Heavy";
				range=2.3;
			};
			class Sprint
			{
				ammo="MeleeSpear_Heavy";
				range=4.2;
			};
		};
	};
	
	class WG_Improvised_Club: Inventory_Base
	{
		scope=2;
		displayName="Improvised Club";
		descriptionShort="Improvised club from a long piece of wood, low quality and it breaks easily";
		model="\WillowGlade\WG_Melee\improvisedmelee\club.p3d";
		rotationFlags=12;
		isMeleeWeapon=1;
		weight=3200;
		itemSize[]={1,6};
		fragility=0.001;
		itemBehaviour=1;
		inventorySlot[]=
		{
			"Shoulder",
			"Melee"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\tools\data\metal_pipe.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\metal_pipe.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\metal_pipe_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\metal_pipe_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\metal_pipe_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeWrench";
				range=1.7;
			};
			class Heavy
			{
				ammo="MeleeWrench_Heavy";
				range=1.7;
			};
			class Sprint
			{
				ammo="MeleeWrench_Heavy";
				range=4.0999999;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Attack_pipemetalhollow_Light1
				{
					soundSet="Char_Attack_pipemetalhollow_light1_SoundSet";
					id=811;
				};
				class Attack_pipemetalhollow_Light2
				{
					soundSet="Char_Attack_pipemetalhollow_light2_SoundSet";
					id=812;
				};
				class Attack_pipemetalhollow_Heavy1
				{
					soundSet="Char_Attack_pipemetalhollow_heavy1_SoundSet";
					id=813;
				};
				class Attack_pipemetalhollow_Heavy2
				{
					soundSet="Char_Attack_pipemetalhollow_heavy2_SoundSet";
					id=814;
				};
				class drop
				{
					soundset="crowbar_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	
	class WG_RedDragon_Katana: Sword
	{
		scope=2;
		displayName="Red Dragon Katana";
		descriptionShort="A mythical katana, very strong and durable blade.";
		model="\WillowGlade\WG_Melee\katana\reddragonkatana.p3d";
		repairableWithKits[]={4};
		hiddenSelections[]=
		{
			"sheath",
			"blade",
            "handle"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Melee\katana\data\katana_co.paa",
			"WillowGlade\WG_Melee\katana\data\katana_co.paa",
			"WillowGlade\WG_Melee\katana\data\katana_co.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"WillowGlade\WG_Melee\katana\data\katana.rvmat",
			"WillowGlade\WG_Melee\katana\data\katana_blade.rvmat",
			"WillowGlade\WG_Melee\katana\data\katana.rvmat",
		};
		inventorySlot[]=
		{
			"Shoulder",
			"Melee",
			"Belt_Back"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"WillowGlade\WG_Melee\katana\data\katana.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Melee\katana\data\katana.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Melee\katana\data\katana_damage.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana_damage.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Melee\katana\data\katana_damage.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana_damage.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Melee\katana\data\katana_destruct.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana_destruct.rvmat",
								"WillowGlade\WG_Melee\katana\data\katana_destruct.rvmat"
							}
						}
					};
				};
			};
		};			
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeRedDragonKatana";
				range=1.8;
			};
			class Heavy
			{
				ammo="MeleeRedDragonKatana_Heavy";
				range=1.8;
			};
			class Sprint
			{
				ammo="MeleeRedDragonKatana_Heavy";
				range=4.0;
			};
		};
		class AnimationSources
		{
			class Sheath
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class Proxy
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Hands
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
		};
	};
};

class CfgAmmo
{
	class MeleeMachete;
	class MeleeMachete_Heavy;
	class MeleeRedDragonKatana: MeleeMachete
	{
		affectSkeleton=0.2;
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
	};
	class MeleeRedDragonKatana_Heavy: MeleeMachete_Heavy
	{
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
		};
		hitAnimation=1;
	};
};