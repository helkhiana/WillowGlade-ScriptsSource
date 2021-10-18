class CfgPatches
{
	class WG_Tools
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "WG_Melee"};
	};
};
class CfgMods
{
	class WG_Tools
	{
		dir = "WG_Tools";
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
				files[] = {"WillowGlade/WG_Tools/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Tools/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Tools/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Flashlight;
	class WG_Flint: Inventory_Base
	{
		scope=2;
		displayName="Flint";
		descriptionShort="Flint found around some rocks. Can be used in crafting.";
		model="\WillowGlade\WG_Tools\craftingmaterials\flint.p3d";
		rotationFlags=17;
		weight=280;
		itemSize[]={1,2};
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
	
	class WG_CordRope: Inventory_Base
	{
		scope=2;
		displayName="Cord Rope";
		descriptionShort="Can be used to craft certain items.";
		model="\WillowGlade\WG_Tools\craftingmaterials\cordrope.p3d";
		rotationFlags=17;
		itemSize[]={1,3};
		weight=280;
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
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\crafting\data\bp_rope_destruct.rvmat"
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
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	
	class WG_LeatherStrap: Inventory_Base
	{
		scope=2;
		displayName="Leather Strap";
		descriptionShort="Can be used to craft certain items.";
		model="\WillowGlade\WG_Tools\craftingmaterials\leatherstrap.p3d";
		rotationFlags=17;
		itemSize[]={2,3};
		weight=280;
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
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\crafting\data\bp_rope_destruct.rvmat"
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
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	class WG_LongMetalScrap: Inventory_Base
	{
		scope=2;
		displayName="Long Metal Scrap";
		descriptionShort="Can be used to craft certain items.";
		model="\WillowGlade\WG_Tools\craftingmaterials\longmetalscrap.p3d";
		rotationFlags=17;
		itemSize[]={1,4};
		weight=280;
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
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\crafting\data\bp_rope_destruct.rvmat"
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
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	class WG_RubberTube: Inventory_Base
	{
		scope=2;
		displayName="Rubber Tube";
		descriptionShort="Can be used to craft certain items.";
		model="\WillowGlade\WG_Tools\craftingmaterials\rubbertube.p3d";
		rotationFlags=17;
		itemSize[]={2,3};
		weight=280;
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
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\crafting\data\bp_rope_destruct.rvmat"
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
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	class WG_ShivMetal: Inventory_Base
	{
		scope=2;
		displayName="Shiv Metal";
		descriptionShort="Can be used to craft certain items.";
		model="\WillowGlade\WG_Tools\craftingmaterials\shivmetal.p3d";
		rotationFlags=17;
		itemSize[]={1,2};
		weight=280;
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
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\crafting\data\bp_rope_destruct.rvmat"
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
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	class WG_TirePlastic: Inventory_Base
	{
		scope=2;
		displayName="Bike Tire";
		descriptionShort="Can be used to craft certain items.";
		model="\WillowGlade\WG_Tools\craftingmaterials\tireplastic.p3d";
		rotationFlags=17;
		stackedUnit="percentage";
		quantityBar=1;
		varQuantityInit=300;
		varQuantityMin=0;
		varQuantityMax=300;
		itemSize[]={3,4};
		weight=280;
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
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\crafting\data\bp_rope.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\crafting\data\bp_rope_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\crafting\data\bp_rope_destruct.rvmat"
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
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};

	class WG_Tape: Inventory_Base
	{
		scope=2;
		displayName="Tape";
		descriptionShort="$STR_CfgVehicles_DuctTape1";
		model="\WillowGlade\WG_Tools\craftingmaterials\tape.p3d";
		isMeleeWeapon=1;
		weight=500;
		absorbency=0.30000001;
		itemSize[]={2,2};
		rotationFlags=17;
		stackedUnit="percentage";
		quantityBar=1;
		varQuantityInit=250;
		varQuantityMin=0;
		varQuantityMax=250;
		repairKitType=5;
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
								"DZ\gear\consumables\data\duct_tape.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\consumables\data\duct_tape.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\duct_tape_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\consumables\data\duct_tape_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\duct_tape_destruct.rvmat"
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
				class rope_untie
				{
					soundSet="rope_untie_SoundSet";
					id=202;
				};
				class rope_struggle
				{
					soundSet="rope_struggle_SoundSet";
					id=203;
				};
				class ducttape_tieup
				{
					soundSet="ducttape_tieup_SoundSet";
					id=13338;
				};
				class rope_tieup_end
				{
					soundSet="rope_tieup_end_SoundSet";
					id=13339;
				};
				class rope_tieup_back
				{
					soundSet="rope_tieup_back_SoundSet";
					id=13340;
				};
			};
		};
	};

	class WG_Torchlight: Flashlight
	{
		scope=2;
		displayName="Torchlight";
		descriptionShort="An angled torchlight that can be attached to backpacks instead of chemlights.";
		model="\WillowGlade\WG_Tools\torchlight\torchlight.p3d";
		rotationFlags=4;
		itemSize[]={1,3};
		inventorySlot[]= {"Chemlight"};
		hiddenSelections[]=		
		{
			"zbytek",
			"reflector",
			"glass"
		};;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Tools\torchlight\data\torchlight_co.paa",
			"WillowGlade\WG_Tools\torchlight\data\torchlight_co.paa",
			"DZ\gear\tools\data\flashlight_glass.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"WillowGlade\WG_Tools\torchlight\data\torchlight.rvmat",
			"WillowGlade\WG_Tools\torchlight\data\torchlight.rvmat",
			"DZ\gear\tools\data\flashlight_glass.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"WillowGlade\WG_Tools\torchlight\data\torchlight.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Tools\torchlight\data\torchlight.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Tools\torchlight\data\torchlight_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Tools\torchlight\data\torchlight_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Tools\torchlight\data\torchlight_destruct.rvmat"
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
				ammo="MeleeLightBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.8;
			};
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOffWhenInCargo=1;
			energyUsagePerSecond=0.0099999998;
			plugType=1;
			attachmentAction=1;
			updateInterval=30;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Attack_flashlight_Light1
				{
					soundSet="Char_Attack_pipemetal_light1_SoundSet";
					id=806;
				};
				class Attack_flashlight_Light2
				{
					soundSet="Char_Attack_pipemetal_light2_SoundSet";
					id=807;
				};
				class Attack_flashlight_Heavy1
				{
					soundSet="Char_Attack_pipemetal_heavy1_SoundSet";
					id=808;
				};
				class Attack_flashlight_Heavy2
				{
					soundSet="Char_Attack_pipemetal_heavy2_SoundSet";
					id=809;
				};
			};
		};		
		class AnimationSources
		{
			class Hands
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Inventory
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
		};
	};
	class Hatchet;
	class WG_StoneHatchet: Hatchet
	{
		scope=2;
		displayName="$STR_CfgVehicles_Hatchet0";
		descriptionShort="A more primitive stone hatchet. Crafted with stones, wood and rope.";
		model="\WillowGlade\WG_Tools\primitive\hatchet\stonehatchet.p3d";
		build_action_type=10;
		dismantle_action_type=74;
		rotationFlags=17;
		weight=1133;
		itemSize[]={2,4};
		fragility=0.0099999998;
		inventorySlot[]=
		{
			"MassTool",
			"Hatchet",
			"Hatchet1",
			"Hatchet2",
			"Hatchet3",
			"Hatchet4"
		};
		openItemSpillRange[]={40,80};
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
								"WillowGlade\WG_Tools\primitive\hatchet\stonehatchet.rvmat"
							}
						},						
						{
							0.69999999,							
							{
								"WillowGlade\WG_Tools\primitive\hatchet\stonehatchet.rvmat"
							}
						},						
						{
							0.5,							
							{
								"WillowGlade\WG_Tools\primitive\hatchet\stonehatchet_damage.rvmat"
							}
						},						
						{
							0.30000001,							
							{
								"WillowGlade\WG_Tools\primitive\hatchet\stonehatchet_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"WillowGlade\WG_Tools\primitive\hatchet\stonehatchet_destruct.rvmat"
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
				ammo="MeleeHatchet";
				range=1.4;
			};
			class Heavy
			{
				ammo="MeleeHatchet_Heavy";
				range=1.4;
			};
			class Sprint
			{
				ammo="MeleeHatchet_Heavy";
				range=3.3;
			};
		};
		isMeleeWeapon=1;
		suicideAnim="woodaxe";
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet="hatchet_pickup_light_SoundSet";
					id=796;
				};
				class pickup
				{
					soundSet="hatchet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet="FirefighterAxe_loop_SoundSet";
					id=1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet="FirefighterAxe_end_SoundSet";
					id=1122;
				};
				class ShoulderR_Hide
				{
					soundset="ShoulderR_Hide_SoundSet";
					id=1210;
				};
				class ShoulderR_Show
				{
					soundset="ShoulderR_Show_SoundSet";
					id=1211;
				};
				class WoodHammer_SoundSet
				{
					soundSet="WoodHammer_SoundSet";
					id=11161;
				};
				class animalSkinning_in
				{
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning
				{
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out
				{
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
			};
		};
	};
	class Pickaxe;
	class WG_StonePickaxe: Pickaxe
	{
		scope=2;
		displayName="$STR_CfgVehicles_Pickaxe0";
		descriptionShort="A more primitive stone pickaxe. Crafted with stones, wood and rope.";
		model="\WillowGlade\WG_Tools\primitive\pickaxe\stonepickaxe.p3d";
		inventorySlot[]=
		{
			"MassTool",
			"Hatchet",
			"Hatchet1",
			"Hatchet2",
			"Hatchet3",
			"Hatchet4"
		};
		rotationFlags=17;
		build_action_type=36;
		dismantle_action_type=46;
		itemSize[]={3,5};
		weight=1133;
		openItemSpillRange[]={40,70};
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
								"WillowGlade\WG_Tools\primitive\pickaxe\stonepickaxe.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Tools\primitive\pickaxe\stonepickaxe.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Tools\primitive\pickaxe\stonepickaxe_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Tools\primitive\pickaxe\stonepickaxe_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Tools\primitive\pickaxe\stonepickaxe_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		isMeleeWeapon=1;
		suicideAnim="fireaxe";
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeHatchet";
				range=1.4;
			};
			class Heavy
			{
				ammo="MeleeHatchet_Heavy";
				range=1.4;
			};
			class Sprint
			{
				ammo="MeleeHatchet_Heavy";
				range=3.3;
			};
		};
		class Horticulture
		{
			ToolAnim="CHOPPINGWOOD";
			DiggingTimeToComplete=4.5;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet="hatchet_pickup_light_SoundSet";
					id=796;
				};
				class pickup
				{
					soundSet="hatchet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet="FirefighterAxe_loop_SoundSet";
					id=1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet="FirefighterAxe_end_SoundSet";
					id=1122;
				};
				class ShoulderR_Hide
				{
					soundset="ShoulderR_Hide_SoundSet";
					id=1210;
				};
				class ShoulderR_Show
				{
					soundset="ShoulderR_Show_SoundSet";
					id=1211;
				};
				class WoodHammer_SoundSet
				{
					soundSet="WoodHammer_SoundSet";
					id=11161;
				};
				class animalSkinning_in
				{
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning
				{
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out
				{
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
			};
		};
	};
};