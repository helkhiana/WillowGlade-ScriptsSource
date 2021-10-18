class CfgPatches
{
	class CarTweaks
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Vehicles_Wheeled",
			"DZ_Vehicles_Parts",
			"DZ_Gear_Camping",
			"Spur_TrolleyKart",
			"Spur_Trolley_E_Kart"
		};
	};
};

class CfgSlots
{	
	class Slot_CanisterGasoline
	{
		name = "CanisterGasoline";
		displayName = "CanisterGasoline";
		selection = "CanisterGasoline";
		ghostIcon = "gascanister";
	};
	class Slot_sea_chest
	{
		name = "sea_chest";
		displayName = "sea_chest";
		selection = "sea_chest";
		ghostIcon = "cat_common_cargo";
	};
};
class CfgVehicles
{
	class Bottle_Base;
	class CanisterGasoline: Bottle_Base
	{
		inventorySlot[] = {"CanisterGasoline"};
	};
	class Container_Base;
	class SeaChest: Container_Base
	{
		inventorySlot[] = {"sea_chest"};
	};

	class CarScript;
	class OffroadHatchback: CarScript
	{		
		displayName="Ada 4x4 Green";
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"NivaDriverDoors",
			"NivaCoDriverDoors",
			"NivaHood",
			"NivaTrunk",
			"NivaWheel_1_1",
			"NivaWheel_1_2",
			"NivaWheel_2_1",
			"NivaWheel_2_2",
			"NivaWheel_Spare_1",
			"CanisterGasoline",
			"sea_chest"
		};
		class Cargo
		{
			itemsCargoSize[]={10,50};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class GUIInventoryAttachmentsProps
		{
            class Other
            {
                name="Other";
				description="";
				icon="";
				attachmentSlots[]=
				{
					"CanisterGasoline",
                    "sea_chest"
				};
            };
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
				};
			};
			class DamageZones
			{
				class Engine
				{
					class Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};
	class OffroadHatchback_Blue: OffroadHatchback
	{
		displayName="Ada 4x4 Blue";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints=5000;					
				};
			};
			class DamageZones: DamageZones
			{
				class Engine: Engine
				{
					class Health: Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};
	class OffroadHatchback_White: OffroadHatchback
	{
		displayName="Ada 4x4 White";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints=5000;					
				};
			};
			class DamageZones: DamageZones
			{
				class Engine: Engine
				{
					class Health: Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};

    class CivilianSedan: CarScript
	{
		displayName="Olga 24 White";
        attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"CivSedanDriverDoors",
			"CivSedanCoDriverDoors",
			"CivSedanCargo1Doors",
			"CivSedanCargo2Doors",
			"CivSedanHood",
			"CivSedanTrunk",
			"CivSedanWheel_1_1",
			"CivSedanWheel_1_2",
			"CivSedanWheel_2_1",
			"CivSedanWheel_2_2",
			"CanisterGasoline",
			"sea_chest"
		};
        class Cargo
		{
			itemsCargoSize[]={10,50};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
        class GUIInventoryAttachmentsProps
		{
            class Other
            {
                name="Other";
				description="";
				icon="";
				attachmentSlots[]=
				{
					"CanisterGasoline",
                    "sea_chest"
				};
            };
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
				};
			};
			class DamageZones
			{
				class Engine
				{
					class Health
					{
						hitpoints=5000;
					};
				};
			};
		};
    };
	class CivilianSedan_Wine: CivilianSedan
	{
		displayName="Olga 24 Wine";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints=5000;					
				};
			};
			class DamageZones: DamageZones
			{
				class Engine: Engine
				{
					class Health: Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};
	class CivilianSedan_Black: CivilianSedan
	{
		displayName="Olga 24 Black";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints=5000;					
				};
			};
			class DamageZones: DamageZones
			{
				class Engine: Engine
				{
					class Health: Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};

    class Hatchback_02: CarScript
	{
		displayName="Gunter 2 Red";
        attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"Hatchback_02_Door_1_1",
			"Hatchback_02_Door_1_2",
			"Hatchback_02_Door_2_1",
			"Hatchback_02_Door_2_2",
			"Hatchback_02_Trunk",
			"Hatchback_02_Hood",
			"Hatchback_02_Wheel_1_1",
			"Hatchback_02_Wheel_1_2",
			"Hatchback_02_Wheel_2_1",
			"Hatchback_02_Wheel_2_2",
			"CanisterGasoline",
			"sea_chest"
		};
        class Cargo
		{
			itemsCargoSize[]={10,50};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
        class GUIInventoryAttachmentsProps
		{
            class Other
            {
                name="Other";
				description="";
				icon="";
				attachmentSlots[]=
				{
					"CanisterGasoline",
                    "sea_chest"
				};
            };
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
				};
			};
			class DamageZones
			{
				class Engine
				{
					class Health
					{
						hitpoints=5000;
					};
				};
			};
		};
    };
	class Hatchback_02_Black: Hatchback_02
	{
		displayName="Gunter 2 Black";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints=5000;					
				};
			};
			class DamageZones: DamageZones
			{
				class Engine: Engine
				{
					class Health: Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};
	class Hatchback_02_Blue: Hatchback_02
	{
		displayName="Gunter 2 Blue";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints=5000;					
				};
			};
			class DamageZones: DamageZones
			{
				class Engine: Engine
				{
					class Health: Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};

    class Sedan_02: CarScript
	{
		displayName="Sarka 120 Yellow";
        attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"EngineBelt",
			"SparkPlug",
			"Sedan_02_Hood",
			"Sedan_02_Trunk",
			"Sedan_02_Door_1_1",
			"Sedan_02_Door_2_1",
			"Sedan_02_Door_1_2",
			"Sedan_02_Door_2_2",
			"Sedan_02_Wheel_1_1",
			"Sedan_02_Wheel_1_2",
			"Sedan_02_Wheel_2_1",
			"Sedan_02_Wheel_2_2",
			"CanisterGasoline",
			"sea_chest"
		};
        class Cargo
		{
			itemsCargoSize[]={10,50};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
        class GUIInventoryAttachmentsProps
		{
            class Other
            {
                name="Other";
				description="";
				icon="";
				attachmentSlots[]=
				{   
					"CanisterGasoline",
                    "sea_chest"
				};
            };
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
				};
			};
			class DamageZones
			{
				class Engine
				{
					class Health
					{
						hitpoints=5000;
					};
				};
			};
		};
    };
	class Sedan_02_Red: Sedan_02
	{
		displayName="Sarka 120 Red";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints=5000;					
				};
			};
			class DamageZones: DamageZones
			{
				class Engine: Engine
				{
					class Health: Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};
	class Sedan_02_Grey: Sedan_02
	{
		displayName="Sarka 120 Grey";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					hitpoints=5000;					
				};
			};
			class DamageZones: DamageZones
			{
				class Engine: Engine
				{
					class Health: Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};

	class Truck_01_Base : CarScript
	{
		displayName="Truck Covered";
		class Cargo
		{
			itemsCargoSize[]={10,80};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;					
				};
			};
			class DamageZones
			{
				class Engine
				{
					class Health
					{
						hitpoints=5000;
					};
				};
			};
		};
	};
	class Truck_01_Covered: Truck_01_Base
	{
		scope=2;
		displayName="Truck Covered Green";
		class Cargo
		{
			itemsCargoSize[]={10,80};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Truck_01_Covered_Blue: Truck_01_Covered
	{
		scope=2;
		displayName="Truck Covered Blue";
		class Cargo
		{
			itemsCargoSize[]={10,80};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Truck_01_Covered_Orange: Truck_01_Covered
	{
		scope=2;
		displayName="Truck Covered Orange";
		class Cargo
		{
			itemsCargoSize[]={10,80};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};

	//Trolley
	class Spur_TrolleyKart_base: CarScript
	{
        class Cargo
		{
			itemsCargoSize[]={10,30};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;					
				};
			};
		};
	};
	
	class Spur_Trolley_E_Kart_base: CarScript
	{
        class Cargo
		{
			itemsCargoSize[]={10,30};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;					
				};
			};
		};
	};
};
