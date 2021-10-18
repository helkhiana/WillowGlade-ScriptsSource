class CfgPatches
{
	class WG_Clothes
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class WG_Clothes
	{
		dir = "WG_Clothes";
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
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Clothes/scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{	
	class Clothing;
	class Container_Base;
	
	class WaterproofBag_ColorBase: Container_Base
	{
		inventorySlot[] = {"waterproofbag"};
	};
	class Bear_ColorBase: Container_Base
	{
		inventorySlot[] = {"teddy"};
	};

	class GasMask;
	class WG_Armored_GasMask_Base: GasMask
	{
		scope=0;
		displayName="Armored GasMask";
		model="\WillowGlade\WG_Clothes\gasmask\armored_gasmask_g.p3d";
		noEyewear=0;
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\gasmask\data\armored_gasmask_co.paa"
		};
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
								"WillowGlade\WG_Clothes\gasmask\data\armored_gasmask.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Clothes\gasmask\data\armored_gasmask.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Clothes\gasmask\data\armored_gasmask_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Clothes\gasmask\data\armored_gasmask_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Clothes\gasmask\data\armored_gasmask_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\gasmask\armored_gasmask_m.p3d";
			female="\WillowGlade\WG_Clothes\gasmask\armored_gasmask_f.p3d";
		};
	};

	class WG_Armored_GasMask: WG_Armored_GasMask_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\gasmask\data\armored_gasmask_co.paa"
		};
	};

	class WG_Armored_GasMask_Graffiti: WG_Armored_GasMask_Base
	{
		scope=2;
		displayName="Armored GasMask - Graffiti";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\gasmask\data\armored_gasmask_graffiti_co.paa"
		};
	};
	
	class WG_SchoolBag_ColorBase: Clothing
	{
		scope=0;
		displayName="School Bag";
		descriptionShort="Lightweight school bag used for all day trips. Comfortably supports any load that fits in.";
		model="\WillowGlade\WG_Clothes\baggybear\schoolbag_g.p3d";
		inventorySlot[]=
		{
			"Back"
		};
		rotationFlags=16;
		weight=1300;
		itemSize[]={4,4};
		itemsCargoSize[]={10,10};
		absorbency=0.30000001;
		heatIsolation=0.1;
		repairableWithKits[]={2};
		repairCosts[]={30,25};
		soundAttType="Outdoor";
		randomQuantity=3;
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie",
			"teddy"
		};
		hiddenSelections[]=
		{
			"all"
		};
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\baggybear\schoolbag.p3d";
			female="\WillowGlade\WG_Clothes\baggybear\schoolbag.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"WillowGlade\WG_Clothes\baggybear\data\baggybear.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Clothes\baggybear\data\baggybear.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Clothes\baggybear\data\baggybear_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Clothes\baggybear\data\baggybear_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Clothes\baggybear\data\baggybear_destruct.rvmat"
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
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	
	class WG_SchoolBag : WG_SchoolBag_ColorBase
	{
		scope=2;		
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Clothes\baggybear\data\baggybear_co.paa"
		};
	};
	
	class WG_DustyBear : Bear_ColorBase 
	{
		scope=2;
		displayName="Dusty Bear";
		descriptionShort="This toy looks like it has been sitting there for a while.";
		model="\WillowGlade\WG_Clothes\baggybear\bear.p3d";
	};
	
	class WG_Summer_Sneakers_ColorBase: Clothing
	{
		scope=2;
		displayName="$STR_CfgVehicles_HikingBoots_ColorBase0";
		descriptionShort="$STR_CfgVehicles_HikingBoots_ColorBase1";
		model="\WillowGlade\WG_Clothes\shoes\summer_sneakers\sneakers_g.p3d";
		inventorySlot[]=
		{
			"Feet"
		};
		itemInfo[]=
		{
			"Clothing",
			"Feet"
		};
		itemSize[]={4,4};
		weight=400;
		durability=0.5;
		absorbency=0.1;
		heatIsolation=0.5;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		soundAttType="Sneakers";
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\shoes\summer_sneakers\sneakers.p3d";
			female="\WillowGlade\WG_Clothes\shoes\summer_sneakers\sneakers.p3d";
		};
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
							1,
							
							{
								"DZ\characters\shoes\Data\hikingBoots.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\shoes\Data\hikingBoots.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\shoes\Data\hikingBoots_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\shoes\Data\hikingBoots_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\shoes\Data\hikingBoots_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage=0.89999998;
					};
					class Blood
					{
						damage=0.89999998;
					};
					class Shock
					{
						damage=0.89999998;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.89999998;
					};
					class Blood
					{
						damage=0.89999998;
					};
					class Shock
					{
						damage=0.89999998;
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="AthleticShoes_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="AthleticShoes_drop_SoundSet";
					id=898;
				};
			};
		};
	};

	
	class WG_Mask_Base: Clothing
	{
		scope=0;
		displayName="Carnival Mask";
		descriptionShort="A carnival mask popular among the children of Chernarus. Most commonly worn during the end of harvest festivities.";
		inventorySlot[]=
		{
			"Mask"
		};
		rotationFlags=1;
		weight=730;
		itemSize[]={3,4};
		heatIsolation=0.5;
		visibilityModifier=0.89999998;
		noHelmet=0;
		headSelectionsToHide[]=
		{
			"Clipping_Gasmask"
		};
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\masks\data\masks_01_co.paa"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="DarkMotoHelmet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="DarkMotoHelmet_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class WG_Mask_Style01: WG_Mask_Base
	{
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\masks\data\masks_01_co.paa"
		};
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
								"WillowGlade\WG_Clothes\masks\data\masks_01.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_01.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_01_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_01_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_01_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class WG_Mask_Style02: WG_Mask_Base
	{
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\masks\data\masks_02_co.paa"
		};
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
								"WillowGlade\WG_Clothes\masks\data\masks_02.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_02.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_02_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_02_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_02_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class WG_Mask_Style03: WG_Mask_Base
	{
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\masks\data\masks_03_co.paa"
		};
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
								"WillowGlade\WG_Clothes\masks\data\masks_03.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_03.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_03_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_03_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_03_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class WG_Mask_Style04: WG_Mask_Base
	{
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\masks\data\masks_04_co.paa"
		};
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
								"WillowGlade\WG_Clothes\masks\data\masks_04.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_04.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_04_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_04_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Clothes\masks\data\masks_04_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class WG_Mask_StylizedWood: WG_Mask_Style03
	{
		scope=2;
		displayName="Carnival Mask - Stylized Wood";
		model="\WillowGlade\WG_Clothes\masks\mask1_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask1_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask1_f.p3d";
		};
	};
	class WG_Mask_Knight: WG_Mask_Style03
	{
		scope=2;
		displayName="Carnival Mask - Knight";
		model="\WillowGlade\WG_Clothes\masks\mask2_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask2_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask2_f.p3d";
		};
	};
	class WG_Mask_StylizedAshWood: WG_Mask_Style03
	{
		scope=2;
		displayName="Carnival Mask - Stylized Ash Wood";
		model="\WillowGlade\WG_Clothes\masks\mask3_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask3_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask3_f.p3d";
		};
	};
	class WG_Mask_ChineseDemon: WG_Mask_Style01
	{
		scope=2;
		displayName="Carnival Mask - Chinese Demon";
		model="\WillowGlade\WG_Clothes\masks\mask4_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask4_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask4_f.p3d";
		};
	};
	class WG_Mask_Pagan: WG_Mask_Style01
	{
		scope=2;
		displayName="Carnival Mask - Pagan";
		model="\WillowGlade\WG_Clothes\masks\mask5_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask5_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask5_f.p3d";
		};
	};
	class WG_Mask_PlagueDoctor: WG_Mask_Style01
	{
		scope=2;
		displayName="Carnival Mask - Plague Doctor";
		model="\WillowGlade\WG_Clothes\masks\mask6_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask6_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask6_f.p3d";
		};
	};
	class WG_Mask_Clown: WG_Mask_Style02
	{
		scope=2;
		displayName="Carnival Mask - Clown";
		model="\WillowGlade\WG_Clothes\masks\mask8_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask8_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask8_f.p3d";
		};
	};
	class WG_Mask_Ghoul: WG_Mask_Style04
	{
		scope=2;
		displayName="Carnival Mask - Ghoul";
		model="\WillowGlade\WG_Clothes\masks\mask11_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask11_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask11_f.p3d";
		};
	};
	class WG_Mask_Mummy: WG_Mask_Style04
	{
		scope=2;
		displayName="Carnival Mask - Mummy";
		model="\WillowGlade\WG_Clothes\masks\mask12_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask12_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask12_f.p3d";
		};
	};
	
	class WG_Mask_JapaneseDemon: WG_Mask_Base
	{
		scope=0;
		displayName="Carnival Mask - Japanese Demon";
		model="\WillowGlade\WG_Clothes\masks\mask_demon_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\masks\mask_demon_f.p3d";
			female="\WillowGlade\WG_Clothes\masks\mask_demon_f.p3d";
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\masks\data\mask_demon_co.paa"
		};
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
								"WillowGlade\WG_Clothes\masks\data\mask_demon.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Clothes\masks\data\mask_demon.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Clothes\masks\data\mask_demon_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Clothes\masks\data\mask_demon_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Clothes\masks\data\mask_demon_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	
	class WG_PumpkinHelmet_Base: Clothing
	{
		scope=0;
		displayName="$STR_cfgvehicles_pumpkinhelmet0";
		descriptionShort="$STR_cfgvehicles_pumpkinhelmet1";
		model="\WillowGlade\WG_Clothes\helmets\evilpumpkinhelmet_g.p3d";
		inventorySlot[]=
		{
			"Headgear"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Headgear"
		};
		weight=500;
		itemSize[]={2,2};
		absorbency=0;
		heatIsolation=1;
		noMask=1;
		noEyewear=1;
		headSelectionsToHide[]=
		{
			"Clipping_PumpkinHelmet"
		};
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\helmets\evilpumpkinhelmet_f.p3d";
			female="\WillowGlade\WG_Clothes\helmets\evilpumpkinhelmet_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"DZ\characters\headgear\data\HelmetMich.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\headgear\data\HelmetMich.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\headgear\data\HelmetMich_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\headgear\data\HelmetMich_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"DZ\characters\headgear\data\HelmetMich_destruct.rvmat"
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
				class pickUpItem
				{
					soundSet="DarkMotoHelmet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="DarkMotoHelmet_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class WG_PumpkinHelmet_Evil: WG_PumpkinHelmet_Base
	{
		scope=2;
		model="\WillowGlade\WG_Clothes\helmets\evilpumpkinhelmet_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\helmets\evilpumpkinhelmet_f.p3d";
			female="\WillowGlade\WG_Clothes\helmets\evilpumpkinhelmet_f.p3d";
		};
	};
	class WG_PumpkinHelmet_Toxic: WG_PumpkinHelmet_Base
	{
		scope=2;
		model="\WillowGlade\WG_Clothes\helmets\toxicpumpkinhelmet_g.p3d";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\helmets\toxicpumpkinhelmet_f.p3d";
			female="\WillowGlade\WG_Clothes\helmets\toxicpumpkinhelmet_f.p3d";
		};
	};

	
	class WG_LeatherBracelet: Clothing
	{
		scope=2;
		displayName="Leather Bracelets - Brown";
		descriptionShort="An old leather bracelets. Goes on both arms.";
		model="\WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_g.p3d";
		inventorySlot[]=
		{
			"Armband"
		};
		rotationFlags=34;
		weight=80;
		itemSize[]={1,1};
		ragQuantity=1;
		heatIsolation=0.1;
		absorbency=0.80000001;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_co.paa"
		};
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
								"DZ\characters\tops\Data\armbend_g.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\tops\Data\armbend_g.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\tops\Data\armbend_g_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\tops\Data\armbend_g_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"DZ\characters\tops\Data\armbend_g_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_f.p3d";
			female="\WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class WG_LeatherBracelet_Black: WG_LeatherBracelet
	{
		displayName="Leather Bracelet - Black";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_black_co.paa"
		};
	};
	class WG_LeatherBracelet_Left: WG_LeatherBracelet
	{
		displayName="Leather Bracelet - Brown";
		descriptionShort="An old leather bracelets. Goes on left arm.";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_leftarm_f.p3d";
			female="\WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_leftarm_f.p3d";
		};
	};
	class WG_LeatherBracelet_Left_Black: WG_LeatherBracelet_Left
	{
		displayName="Leather Bracelet - Black";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_black_co.paa"
		};
	};
	class WG_LeatherBracelet_Right: WG_LeatherBracelet
	{
		displayName="Leather Bracelet - Brown";
		descriptionShort="An old leather bracelets. Goes on right arm.";
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_rightarm_f.p3d";
			female="\WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_rightarm_f.p3d";
		};
	};
	class WG_LeatherBracelet_Right_Black: WG_LeatherBracelet_Right
	{
		displayName="Leather Bracelet - Black";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\accessories\leatherbracelet\leatherbracelet_black_co.paa"
		};
	};

	
	class WG_WristWatch_ColorBase: Clothing
	{
		scope=0;
		displayName="Army Wristwatch";
		descriptionShort="Army Wristwatch";
		model="\WillowGlade\WG_Clothes\accessories\wristwatch\wristwatch_g.p3d";
		inventorySlot[]=
		{
			"Armband"
		};
		simulation="clothing";
		itemSize[]={1,3};
		weight=470;
		absorbency=0;
		repairableWithKits[]={7};
		repairCosts[]={30,25};
		quickBarBonus=1;
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
								"WillowGlade\WG_Clothes\accessories\wristwatch\wristwatch.rvmat"
							}
						},						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Clothes\accessories\wristwatch\wristwatch.rvmat"
							}
						},						
						{
							0.5,
							
							{
								"WillowGlade\WG_Clothes\accessories\wristwatch\wristwatch_damage.rvmat"
							}
						},						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Clothes\accessories\wristwatch\wristwatch_damage.rvmat"
							}
						},						
						{
							0.0,
							
							{
								"WillowGlade\WG_Clothes\accessories\wristwatch\wristwatch_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\accessories\wristwatch\wristwatch_f.p3d";
			female="\WillowGlade\WG_Clothes\accessories\wristwatch\wristwatch_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="sewingkit_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="sewingkit_drop_SoundSet";
					id=898;
				};
			};
		};
	};

	class WG_WristWatch: WG_WristWatch_ColorBase
	{
		scope=2;
	};
	
	class Wellies_ColorBase;
	class Frog_Wellies_ColorBase: Wellies_ColorBase
	{
		displayName="$STR_CfgVehicles_Wellies_ColorBase0";
		descriptionShort="$STR_CfgVehicles_Wellies_ColorBase1";
		model="\WillowGlade\WG_Clothes\shoes\frog_wellies\frog_wellies_MFv1.p3d";
		soundAttType="Boots";
		heatIsolation=0.7;
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\shoes\frog_wellies\frog_wellies_MFv1.p3d";
			female="\WillowGlade\WG_Clothes\shoes\frog_wellies\frog_wellies_MFv1.p3d";
		};
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
								"WillowGlade\WG_Clothes\shoes\frog_wellies\data\frog_wellies.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Clothes\shoes\frog_wellies\data\frog_wellies.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Clothes\shoes\frog_wellies\data\frog_wellies_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Clothes\shoes\frog_wellies\data\frog_wellies_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Clothes\shoes\frog_wellies\data\frog_wellies_destruct.rvmat"
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
				class pickUpItem
				{
					soundSet="AthleticShoes_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="AthleticShoes_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Frog_Wellies: Frog_Wellies_ColorBase
	{
		scope=2;
		visibilityModifier=0.89999998;
	};

	
	class WG_RifleSling_Colorbase: Clothing
	{
		displayName="Rifle Sling";
		descriptionShort="Rifle Sling which can be attached on your shoulder. It will be shown only when you have weapon attached. You cannot carry this inventory/hands or put in any cargo if it has weapon atached.";
		model="\WillowGlade\WG_Clothes\riflesling\riflesling_g.p3d";
		simulation="clothing";
		vehicleClass="Clothing";
		inventorySlot[]=
		{
			"Shoulder"
		};
		rotationFlags=0;
		itemSize[]={3,2};
		itemsCargoSize[]={0,0};
		weight=500;
		absorbency=0.2;
		heatIsolation=0.13;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		soundAttType="Outdoor";
		attachments[]=
		{
			"shoulder1"
		};
		simpleHiddenSelections[]=
		{	
			"all",
			"rolled",
			"deployed"
		};
		hiddenSelections[]=
		{
			"all",
			"rolled",
			"deployed"
		};
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\riflesling\riflesling_m.p3d";
			female="\WillowGlade\WG_Clothes\riflesling\riflesling_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[] = {
						{1.0,{"WillowGlade\WG_Clothes\riflesling\data\riflesling.rvmat"}},
						{0.7,{"WillowGlade\WG_Clothes\riflesling\data\riflesling.rvmat"}},
						{0.5,{"WillowGlade\WG_Clothes\riflesling\data\riflesling_damage.rvmat"}},
						{0.3,{"WillowGlade\WG_Clothes\riflesling\data\riflesling_damage.rvmat"}},
						{0.0,{"WillowGlade\WG_Clothes\riflesling\data\riflesling_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class WG_RifleSling_Brown: WG_RifleSling_Colorbase
	{
		scope=2;
		displayName="Rifle Sling Brown";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_co.paa"
		};
	};
	class WG_RifleSling_Black: WG_RifleSling_Colorbase
	{
		scope=2;
		displayName="Rifle Sling Black";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_black_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_black_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_black_co.paa"
		};
	};
	class WG_RifleSling_Camo: WG_RifleSling_Colorbase
	{
		scope=2;
		displayName="Rifle Sling Camo";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_camo_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_camo_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_camo_co.paa"
		};
	};
	class WG_RifleSling_CamoUPC: WG_RifleSling_Colorbase
	{
		scope=2;
		displayName="Rifle Sling Camo UPC";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_camoupc_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_camoupc_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_camoupc_co.paa"
		};
	};
	class WG_RifleSling_Pink: WG_RifleSling_Colorbase
	{
		scope=2;
		displayName="Rifle Sling Pink";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_pink_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_pink_co.paa",
			"WillowGlade\WG_Clothes\riflesling\data\riflesling_pink_co.paa"
		};
	};

	class Wolf_Headdress: Clothing
	{
		scope=2;
		displayName="Wolf Headdress";
		descriptionShort="A Headdress made out of wolf pelt";
		model="\WillowGlade\WG_Clothes\headdress\Wolf_Headdress\wolf_headdress_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Headgear"
		};
		weight=1000;
		itemSize[]={3,3};
		absorbency=0.1;
		heatIsolation=0.95;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
        hiddenSelections[]=
        {
			"zbytek",
			"fur_brighter",
			"fur1",
			"fur2",
			"fur3"
        };
		simpleHiddenSelections[]=
        {
			"tight",
			"bulky"
        };
		headSelectionsToHide[]=
		{
			"Clipping_BeanieHat"
		};
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\headdress\Wolf_Headdress\wolf_headdress_m.p3d";
			female="\WillowGlade\WG_Clothes\headdress\Wolf_Headdress\wolf_headdress_f.p3d";
		};
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_headdress_co.paa","WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_fur_white_ca.paa","WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_fur_ca.paa","WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_fur2_ca.paa","WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_fur3_ca.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;
				};
			};
		};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 20;
                    healthLevels[] = 
                    {
                        {1.0,{"WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_headdress.rvmat"}},
                        {0.7,{"WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_headdress.rvmat"}},
                        {0.5,{"WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_headdress_damaged.rvmat"}},
                        {0.3,{"WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_headdress_badlydamaged.rvmat"}},
                        {0.0,{"WillowGlade\WG_Clothes\headdress\Wolf_Headdress\data\wolf_headdress_ruined.rvmat"}}
					};
                };
            };
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0.4;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.4;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.4;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.4;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.4;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.4;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.4;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.4;
					};
				};
			};
        };	
    };
	
	class Bear_Headdress: Clothing
	{
		scope=2;
		displayName="Bear Headdress";
		descriptionShort="A Headdress made out of bear pelt";
		model="\WillowGlade\WG_Clothes\headdress\bear_headdress\bear_headdress_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Headgear"
		};
		weight=1000;
		itemSize[]={3,3};
		absorbency=0.1;
		heatIsolation=0.95;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
        hiddenSelections[]=
        {
			"zbytek",
			"fur_static",
            "fur_wind"
        };
		headSelectionsToHide[]=
		{
			"Clipping_BeanieHat"
		};
		class ClothingTypes
		{
			male="\WillowGlade\WG_Clothes\headdress\bear_headdress\bear_headdress_m.p3d";
			female="\WillowGlade\WG_Clothes\headdress\bear_headdress\bear_headdress_f.p3d";
		};
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_co.paa","WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur_ca.paa","WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur_ca.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;
				};
			};
		};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 25;
                    healthLevels[] = 
                    {
                        {1.0,{"WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur_hairshader.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur.rvmat"}},
                        {0.7,{"WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur_hairshader.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur.rvmat"}},
                        {0.5,{"WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_damaged.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur_hairshader.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur.rvmat"}},
                        {0.3,{"WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_badlydamaged.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur_hairshader.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur.rvmat"}},
                        {0.0,{"WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_ruined.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur_hairshader.rvmat", "WillowGlade\WG_Clothes\headdress\bear_headdress\data\bear_headdress_fur.rvmat"}}
					};
                };
            };
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0.4;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.4;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.4;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.4;
					};
				};
				class Infected
				{
					class Health
					{
						damage=0.4;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.4;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.4;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0.4;
					};
				};
			};
        };	
    };	
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyWaterproofBag: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"waterproofbag"};
		model = "\dz\gear\containers\WaterproofBag.p3d";
	};
	class Proxyteddybear: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"teddy"};
		model = "\dz\gear\containers\teddybear.p3d";
	};
};

class CfgSlots
{
	class Slot_waterproofbag
	{
		name = "waterproofbag";
		displayName = "waterproofbag";
		ghostIcon = "pouches";
	};
	class Slot_teddy
	{
		name = "teddy";
		displayName = "teddy";
		ghostIcon = "pouches";
	};
};