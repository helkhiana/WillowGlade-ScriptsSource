class CfgPatches
{
	class WG_Storage
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Gear_Consumables", "DZ_Gear_Cooking", "DZ_Gear_Crafting"};
	};
};

class CfgMods
{
	class WG_Storage
	{
		dir = "WG_Storage";
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
				files[] = {"WillowGlade/WG_Storage/scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{	
	class Inventory_Base;
	class FireplaceBase;
	class WG_Item;
	class WG_Kit;
	class Fireplace: FireplaceBase
	{
		attachments[]=
		{
			"Firewood",
			"Firewood_Log",
			"WoodenStick",
			"CookingEquipment",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Bark",
			"CookingTripod",
			"Stones",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name="$STR_attachment_Fuel0";
				description="";
				attachmentSlots[]=
				{
					"Firewood",
					"Firewood_Log",
					"WoodenStick"
				};
				icon="cat_fp_fuel";
			};
		};
	};
	class FireplaceIndoor: FireplaceBase
	{
		attachments[]=
		{
			"Firewood",
			"Firewood_Log",
			"WoodenStick",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Bark",
			"DirectCookingA",
			"DirectCookingB",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name="$STR_attachment_Fuel0";
				description="";
				attachmentSlots[]=
				{
					"Firewood",
					"Firewood_Log",
					"WoodenStick"
				};
				icon="cat_fp_fuel";
			};
		};
	};
	class OvenIndoor: FireplaceBase
	{		
		attachments[]=
		{
			"Firewood",
			"Firewood_Log",
			"WoodenStick",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Bark",
			"DirectCookingA",
			"SmokingA",
			"SmokingB"
		};
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name="$STR_attachment_Fuel0";
				description="";
				attachmentSlots[]=
				{
					"Firewood",
					"Firewood_Log",
					"WoodenStick"
				};
				icon="cat_fp_fuel";
			};
		};
	};
	class Firewood: Inventory_Base
	{
		scope=2;
		displayName="Firewood Branch";
		descriptionShort="$STR_CfgVehicles_Firewood1";
		model="\WillowGlade\WG_Storage\firewoodholder\firewood_branches.p3d";
		inventorySlot[]=
		{
			"Firewood",
			"Firewood2",
			"Firewood3",
			"Firewood4",
			"Firewood5"
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
								"WillowGlade\WG_Storage\firewoodholder\data\firewood.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Storage\firewoodholder\data\firewood.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Storage\firewoodholder\data\firewood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Storage\firewoodholder\data\firewood_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Storage\firewoodholder\data\firewood_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};	
	class Firewood_Log: Firewood
	{
		scope=2;
		displayName="Firewood Log";
		descriptionShort="Strong firewood which produces a lot of heat when fed to a fireplace.";
		model="\WillowGlade\WG_Storage\firewoodholder\firewood_log.p3d";
		varStackMax=20;
		weight=1000;
		inventorySlot[]=
		{
			"Firewood_Log",
			"Firewood_Log2",
			"Firewood_Log3",
			"Firewood_Log4",
			"Firewood_Log5"
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
								"WillowGlade\WG_Storage\firewoodholder\data\firewood.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Storage\firewoodholder\data\firewood.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Storage\firewoodholder\data\firewood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Storage\firewoodholder\data\firewood_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Storage\firewoodholder\data\firewood_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	
	class WG_FirewoodHolder_Kit: WG_Kit
	{	
		scope=2;	
		displayName="Firewood Holder Kit";
		descriptionShort="This can be dismantled with pliers, hammer or screwdriver. This holds 5 stacks of Firewood Branches, 5 stacks of Firewood Logs, 1 stack of Wooden Sticks, 1 stack of Long Wooden Sticks and all the kindlings. Has a bit of space for matches too.";
		model="\WillowGlade\WG_Storage\firewoodholder\firewoodholder_kit.p3d";
		rotationFlags=17;		
		itemSize[] = {2,6};
	};
	class WG_FirewoodHolder: WG_Item
	{
		scope=2;
		displayName="Firewood Holder";
		descriptionShort="This can be dismantled with pliers, hammer or screwdriver. This holds 5 stacks of Firewood Branches, 5 stacks of Firewood Logs, 1 stack of Wooden Sticks, 1 stack of Long Wooden Sticks and all the kindlings. Has a bit of space for matches too.";
		model="\WillowGlade\WG_Storage\firewoodholder\firewoodholder.p3d";
		itemsCargoSize[]={8,1};
		class AnimationSources
		{
			class Logs
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Branches
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
		attachments[]=
		{
			"Firewood",
			"Firewood2",
			"Firewood3",
			"Firewood4",
			"Firewood5",
			"Firewood_Log",
			"Firewood_Log2",
			"Firewood_Log3",
			"Firewood_Log4",
			"Firewood_Log5",
			"Material_Shelter_Sticks",
			"Material_Shelter_FrameSticks",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Book",			
			"OakBark",
			"BirchBark"
		};
		class GUIInventoryAttachmentsProps
		{
			class Firewood
			{
				name="Firewood Branches";
				description="";
				attachmentSlots[]=
				{
					"Firewood",
					"Firewood2",
					"Firewood3",
					"Firewood4",
					"Firewood5"
				};
				icon="firewood";
			};
			class Firewood_Log
			{
				name="Firewood Logs";
				description="";
				attachmentSlots[]=
				{
					"Firewood_Log",
					"Firewood_Log2",
					"Firewood_Log3",
					"Firewood_Log4",
					"Firewood_Log5"
				};
				icon="cat_fp_fuel";
			};
			class Sticks
			{
				name="Sticks";
				description="";
				attachmentSlots[]=
				{
					"Material_Shelter_Sticks",
					"Material_Shelter_FrameSticks"
				};
				icon="woodenstick";
			};
			class Kindling
			{
				name="$STR_attachment_Kindling0";
				description="";
				attachmentSlots[]=
				{
					"Rags",
					"MedicalBandage",
					"Paper",
					"Book",
					"OakBark",
					"BirchBark"
				};
				icon="cat_fp_kindling";
				view_index=3;
			};
		};		
	};

	class HouseNoDestruct;
	class WG_VendingMachine_Base : HouseNoDestruct
	{
		scope=0;
		model="\WillowGlade\WG_Storage\vendingmachines\vendingmachine.p3d";
		hiddenSelections[]=
		{
			"buttons",
			"vendingmachine"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\vendingmachines\data\buttons_cans_co.paa",
			"WillowGlade\WG_Storage\vendingmachines\data\vendingmachine_cans_co.paa"
		};
	};
	class WG_VendingMachine_Cans : WG_VendingMachine_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\vendingmachines\data\buttons_cans_co.paa",
			"WillowGlade\WG_Storage\vendingmachines\data\vendingmachine_cans_co.paa"
		};
	};
	class WG_VendingMachine_Drinks : WG_VendingMachine_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\vendingmachines\data\buttons_drinks_co.paa",
			"WillowGlade\WG_Storage\vendingmachines\data\vendingmachine_drinks_co.paa"
		};
	};
	class WG_VendingMachine_Snacks : WG_VendingMachine_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\vendingmachines\data\buttons_snacks_co.paa",
			"WillowGlade\WG_Storage\vendingmachines\data\vendingmachine_snacks_co.paa"
		};
	};

	
	class Container_Base;
	class FirstAidKit: Container_Base
	{
		inventorySlot[] = {"FirstAid","FirstAidKit1","FirstAidKit2","FirstAidKit3","FirstAidKit4"};
	};
	class WG_TacticalPouch_ColourBase: FirstAidKit
	{
		scope=0;
		displayName="Tactical Pouch";
		descriptionShort="Pouch suitable for small sorts of stuff. Attaches to some backpacks, belts or vests.";
		model="\WillowGlade\WG_Storage\tacticalpouch\tacticalpouch.p3d";
		rotationFlags=17;
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_green_co.paa"
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
							1.0,
							
							{
								"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_destruct.rvmat"
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

	class WG_TacticalPouch_Green: WG_TacticalPouch_ColourBase
	{
		scope=2;
		displayName="Tactical Pouch - Green";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_green_co.paa"
		};
	};
	class WG_TacticalPouch_Black: WG_TacticalPouch_ColourBase
	{
		scope=2;
		displayName="Tactical Pouch - Black";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_black_co.paa"
		};
	};
	class WG_TacticalPouch_Brown: WG_TacticalPouch_ColourBase
	{
		scope=2;
		displayName="Tactical Pouch - Brown";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_brown_co.paa"
		};
	};
	class WG_TacticalPouch_CamoGreen: WG_TacticalPouch_ColourBase
	{
		scope=2;
		displayName="Tactical Pouch - Green Camo";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_camogreen_co.paa"
		};
	};
	class WG_TacticalPouch_CamoUcp: WG_TacticalPouch_ColourBase
	{
		scope=2;
		displayName="Tactical Pouch - UCP Camo";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_camoucp_co.paa"
		};
	};
	class WG_TacticalPouch_WhiteUcp: WG_TacticalPouch_ColourBase
	{
		scope=2;
		displayName="Tactical Pouch - White UCP";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\tacticalpouch\data\tacticalpouch_whiteucp_co.paa"
		};
	};
	
	class WG_MedicalCabinet_Kit: WG_Kit
	{
		scope=2;
		displayName="Medical Cabinet Kit";
	};
    class WG_MedicalCabinet: WG_Item
	{
		scope=2;
		displayName="Medical Cabinet";
		descriptionShort="A tall medical cabinet that can store medical items. Attachments 4x of each: First Aid Kit, Personal Medkit, ITS Medkit, ITS Surgical Kit, Emergency Bandage";
		model="\WillowGlade\WG_Storage\medicalCabinet\medicalcabinet.p3d";
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Storage\medicalCabinet\medicalcabinet_co.paa"
		};
		attachments[]=
		{
			"FirstAidKit1","FirstAidKit2","FirstAidKit3","FirstAidKit4",
			"PersonalMedKit1","PersonalMedKit2","PersonalMedKit3","PersonalMedKit4",
			"ITSMedKit1","ITSMedKit2","ITSMedKit3","ITSMedKit4",
			"SurgicalKit1","SurgicalKit2","SurgicalKit3","SurgicalKit4",
			"EmergencyBandage1","EmergencyBandage2","EmergencyBandage3","EmergencyBandage4"
		};	
		class GUIInventoryAttachmentsProps
		{
			class FirstAidKits
			{
				name="First Aid Kits";
				description="";
				attachmentSlots[]=
				{
					"FirstAidKit1","FirstAidKit2","FirstAidKit3","FirstAidKit4"
				};
				icon="medicalbandage";
			};
			class PersonalMedkits
			{
				name="Personal Medkits";
				description="";
				attachmentSlots[]=
				{
					"PersonalMedKit1","PersonalMedKit2","PersonalMedKit3","PersonalMedKit4"
				};
				icon="medicalbandage";
			};
			class ITSMedkits
			{
				name="ITS Medkits";
				description="";
				attachmentSlots[]=
				{
					"ITSMedKit1","ITSMedKit2","ITSMedKit3","ITSMedKit4"
				};
				icon="medicalbandage";
			};
			class SurgicalKits
			{
				name="Surgical Kits";
				description="";
				attachmentSlots[]=
				{
					"SurgicalKit1","SurgicalKit2","SurgicalKit3","SurgicalKit4"
				};
				icon="medicalbandage";
			};
			class EmergencyBandages
			{
				name="Emergency Bandages";
				description="";
				attachmentSlots[]=
				{
					"EmergencyBandage1","EmergencyBandage2","EmergencyBandage3","EmergencyBandage4"
				};
				icon="medicalbandage";
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,20};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyRags: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Rags"
		};
		model="\dz\gear\consumables\Rags.p3d";
	};
	class Proxyoak_bark: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"OakBark"
		};
		model="\dz\gear\consumables\oak_bark.p3d";
	};
	class Proxybirch_bark: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"BirchBark"
		};
		model="\dz\gear\consumables\birch_bark.p3d";
	};
	class ProxyWooden_stick: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Material_Shelter_FrameSticks"
		};
		model="\dz\gear\crafting\Wooden_stick.p3d";
	};
	
	class ProxyFirstAidKit1: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"FirstAidKit1"};
		model = "\WillowGlade\WG_Storage\proxies\FirstAidKit1.p3d";
	};
	class ProxyFirstAidKit2: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"FirstAidKit2"};
		model = "\WillowGlade\WG_Storage\proxies\FirstAidKit2.p3d";
	};
	class ProxyFirstAidKit3: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"FirstAidKit3"};
		model = "\WillowGlade\WG_Storage\proxies\FirstAidKit3.p3d";
	};
	class ProxyFirstAidKit4: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"FirstAidKit4"};
		model = "\WillowGlade\WG_Storage\proxies\FirstAidKit4.p3d";
	};

	class ProxyITSMedKit1: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"ITSMedKit1"};
		model = "\WillowGlade\WG_Storage\proxies\ITSMedKit1.p3d";
	};
	class ProxyITSMedKit2: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"ITSMedKit2"};
		model = "\WillowGlade\WG_Storage\proxies\ITSMedKit2.p3d";
	};
	class ProxyITSMedKit3: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"ITSMedKit3"};
		model = "\WillowGlade\WG_Storage\proxies\ITSMedKit3.p3d";
	};
	class ProxyITSMedKit4: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"ITSMedKit4"};
		model = "\WillowGlade\WG_Storage\proxies\ITSMedKit4.p3d";
	};

	class ProxyPersonalMedKit1: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"PersonalMedKit1"};
		model = "\WillowGlade\WG_Storage\proxies\PersonalMedKit1.p3d";
	};
	class ProxyPersonalMedKit2: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"PersonalMedKit2"};
		model = "\WillowGlade\WG_Storage\proxies\PersonalMedKit2.p3d";
	};
	class ProxyPersonalMedKit3: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"PersonalMedKit3"};
		model = "\WillowGlade\WG_Storage\proxies\PersonalMedKit3.p3d";
	};
	class ProxyPersonalMedKit4: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"PersonalMedKit4"};
		model = "\WillowGlade\WG_Storage\proxies\PersonalMedKit4.p3d";
	};

	class ProxySurgicalKit1: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"SurgicalKit1"};
		model = "\WillowGlade\WG_Storage\proxies\SurgicalKit1.p3d";
	};
	class ProxySurgicalKit2: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"SurgicalKit2"};
		model = "\WillowGlade\WG_Storage\proxies\SurgicalKit2.p3d";
	};
	class ProxySurgicalKit3: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"SurgicalKit3"};
		model = "\WillowGlade\WG_Storage\proxies\SurgicalKit3.p3d";
	};
	class ProxySurgicalKit4: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"SurgicalKit4"};
		model = "\WillowGlade\WG_Storage\proxies\SurgicalKit4.p3d";
	};

	class ProxyEmergencyBandage1: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"EmergencyBandage1"};
		model = "\WillowGlade\WG_Storage\proxies\EmergencyBandage1.p3d";
	};
	class ProxyEmergencyBandage2: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"EmergencyBandage2"};
		model = "\WillowGlade\WG_Storage\proxies\EmergencyBandage2.p3d";
	};
	class ProxyEmergencyBandage3: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"EmergencyBandage3"};
		model = "\WillowGlade\WG_Storage\proxies\EmergencyBandage3.p3d";
	};
	class ProxyEmergencyBandage4: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"EmergencyBandage4"};
		model = "\WillowGlade\WG_Storage\proxies\EmergencyBandage4.p3d";
	};
};

class CfgSlots
{	
	class Slot_Firewood2
	{
		name="Firewood2";
		displayName="Firewood2";
		ghostIcon="firewood";
		stackMax=20;
	};
	class Slot_Firewood3
	{
		name="Firewood3";
		displayName="Firewood3";
		ghostIcon="firewood";
		stackMax=20;
	};
	class Slot_Firewood4
	{
		name="Firewood4";
		displayName="Firewood4";
		ghostIcon="firewood";
		stackMax=20;
	};
	class Slot_Firewood5
	{
		name="Firewood5";
		displayName="Firewood5";
		ghostIcon="firewood";
		stackMax=20;
	};
	class Slot_Firewood_Log
	{
		name="Firewood_Log";
		displayName="Firewood_Log";
		ghostIcon="cat_fp_fuel";
		stackMax=20;
	};
	class Slot_Firewood_Log2
	{
		name="Firewood_Log2";
		displayName="Firewood_Log2";
		ghostIcon="cat_fp_fuel";
		stackMax=20;
	};
	class Slot_Firewood_Log3
	{
		name="Firewood_Log3";
		displayName="Firewood_Log3";
		ghostIcon="cat_fp_fuel";
		stackMax=20;
	};
	class Slot_Firewood_Log4
	{
		name="Firewood_Log4";
		displayName="Firewood_Log4";
		ghostIcon="cat_fp_fuel";
		stackMax=20;
	};
	class Slot_Firewood_Log5
	{
		name="Firewood_Log5";
		displayName="Firewood_Log5";
		ghostIcon="cat_fp_fuel";
		stackMax=20;
	};
	class Slot_FirstAidKit1
	{
		name = "FirstAidKit1";
		displayName = "FirstAidKit1";
		ghostIcon = "medicalbandage";
	};
	class Slot_FirstAidKit2
	{
		name = "FirstAidKit2";
		displayName = "FirstAidKit2";
		ghostIcon = "medicalbandage";
	};
	class Slot_FirstAidKit3
	{
		name = "FirstAidKit3";
		displayName = "FirstAidKit3";
		ghostIcon = "medicalbandage";
	};
	class Slot_FirstAidKit4
	{
		name = "FirstAidKit4";
		displayName = "FirstAidKit4";
		ghostIcon = "medicalbandage";
	};
	class Slot_ITSMedKit1
	{
		name = "ITSMedKit1";
		displayName = "ITSMedKit1";
		ghostIcon = "medicalbandage";
	};
	class Slot_ITSMedKit2
	{
		name = "ITSMedKit2";
		displayName = "ITSMedKit2";
		ghostIcon = "medicalbandage";
	};
	class Slot_ITSMedKit3
	{
		name = "ITSMedKit3";
		displayName = "ITSMedKit3";
		ghostIcon = "medicalbandage";
	};
	class Slot_ITSMedKit4
	{
		name = "ITSMedKit4";
		displayName = "ITSMedKit4";
		ghostIcon = "medicalbandage";
	};
	
	class Slot_PersonalMedKit1
	{
		name = "PersonalMedKit1";
		displayName = "PersonalMedKit1";
		ghostIcon = "medicalbandage";
	};
	class Slot_PersonalMedKit2
	{
		name = "PersonalMedKit2";
		displayName = "PersonalMedKit2";
		ghostIcon = "medicalbandage";
	};
	class Slot_PersonalMedKit3
	{
		name = "PersonalMedKit3";
		displayName = "PersonalMedKit3";
		ghostIcon = "medicalbandage";
	};
	class Slot_PersonalMedKit4
	{
		name = "PersonalMedKit4";
		displayName = "PersonalMedKit4";
		ghostIcon = "medicalbandage";
	};
	class Slot_SurgicalKit1
	{
		name = "SurgicalKit1";
		displayName = "SurgicalKit1";
		ghostIcon = "medicalbandage";
	};
	class Slot_SurgicalKit2
	{
		name = "SurgicalKit2";
		displayName = "SurgicalKit2";
		ghostIcon = "medicalbandage";
	};
	class Slot_SurgicalKit3
	{
		name = "SurgicalKit3";
		displayName = "SurgicalKit3";
		ghostIcon = "medicalbandage";
	};
	class Slot_SurgicalKit4
	{
		name = "SurgicalKit4";
		displayName = "SurgicalKit4";
		ghostIcon = "medicalbandage";
	};
	class Slot_EmergencyBandage1
	{
		name = "EmergencyBandage1";
		displayName = "EmergencyBandage1";
		ghostIcon = "medicalbandage";
	};
	class Slot_EmergencyBandage2
	{
		name = "EmergencyBandage2";
		displayName = "EmergencyBandage2";
		ghostIcon = "medicalbandage";
	};
	class Slot_EmergencyBandage3
	{
		name = "EmergencyBandage3";
		displayName = "EmergencyBandage3";
		ghostIcon = "medicalbandage";
	};
	class Slot_EmergencyBandage4
	{
		name = "EmergencyBandage4";
		displayName = "EmergencyBandage4";
		ghostIcon = "medicalbandage";
	};
};