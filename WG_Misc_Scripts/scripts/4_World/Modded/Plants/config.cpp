class CfgPatches
{
	class WG_Planting
	{
		units[] = {"PotatoSeeds","PotatoSeedsPack","Potato"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Consumables","DZ_Gear_Camping","DZ_Gear_Crafting","DZ_Gear_Food","DZ_Gear_Tools","DZ_Gear_Cooking","DZ_Vehicles_Parts","DZ_Structures"};
	};
};
class CfgVehicles
{
	class Edible_Base;
	class SeedBase;
	class PlantBase;
	class Inventory_Base;
	class FoodAnimationSources;
	class FruitStageTransitions;
	class Plant_Tomato: PlantBase
	{
		class Horticulture
		{
			GrowthStagesCount = 6;
			CropsCount = 3;
			CropsType = "Tomato";
		};
	};
	class Plant_Pepper: PlantBase
	{
		class Horticulture
		{
			GrowthStagesCount = 6;
			CropsCount = 2;
			CropsType = "GreenBellPepper";
		};
	};
	class Plant_Pumpkin: PlantBase
	{
		class Horticulture
		{
			GrowthStagesCount = 7;
			CropsCount = 1;
			CropsType = "Pumpkin";
		};
	};
	class Plant_Zucchini: PlantBase
	{
		class Horticulture
		{
			GrowthStagesCount = 7;
			CropsCount = 1;
			CropsType = "Zucchini";
		};
	};
	class Plant_Cannabis: PlantBase
	{
		class Horticulture
		{
			GrowthStagesCount = 6;
			CropsCount = 4;
			CropsType = "Cannabis";
		};
	};
	class CannabisSeedsPack: Inventory_Base
	{
		displayName = "Cannabis Seeds Pack";
		descriptionShort = "A pack of cannabis seeds.";
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault = "Empty the pack";
				displayName = "Empty the pack";
				position = "action";
				onlyForPlayer = 1;
				radius = 2;
				condition = "true";
				statement = "this callMethod ['EmptySeedPack', _person];";
			};
		};
	};
	class CannabisSeeds: SeedBase
	{
		displayName = "Cannabis Seeds";
		descriptionShort = "Cannabis seeds, ready to be planted to grow cannabis plant.";
	};
	class Cannabis: Edible_Base
	{
		displayName = "Cannabis";
		descriptionShort = "A cannabis bud.";
	};
};
