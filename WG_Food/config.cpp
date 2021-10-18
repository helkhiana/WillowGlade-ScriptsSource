class CfgPatches
{
	class WG_Food
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
    class WG_Food
    {
        dir = "WG_Food";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "WG_Food";
        credits = "";
        author = "Helkhiana";
        authorID = "0"; 
        version = "1.0"; 
        extra = 0;
        type = "mod";        
        dependencies[] = {"Game", "World", "Mission"};        
        class defs
        {
			class gameScriptModule
            {
                value = "";
                files[] = {"WillowGlade/WG_Food/scripts/3_Game"};
			};

            class worldScriptModule
            {
                value = "";
                files[] = {"WillowGlade/WG_Food/scripts/4_World"};
			};

			class missionScriptModule
            {
                value = "";
                files[] = {"WillowGlade/WG_Food/scripts/5_Mission"};
			};
		};
    };
};

class BaseFoodStageTransitions;
class NotCookable;
class MeatStageTransitions: BaseFoodStageTransitions{};
class FruitStageTransitions: BaseFoodStageTransitions{};
class AnimalCorpsesStageTransitions: BaseFoodStageTransitions{};
class MushroomsStageTransitions: BaseFoodStageTransitions{};
class FoodAnimationSources;
class NutritionModifiers;

class CfgVehicles
{
	class Edible_Base;
    class Bottle_Base;
    class WG_Marshmallow: Edible_Base
    {
        scope = 2;
        displayName = "Marshmallow";
        descriptionShort = "A type of confectionery which is typically made from sugar, water and gelatin whipped to a squishy consistency. Nice roasted on the fire :)";
        model = "\WillowGlade\WG_Food\Marshmallow\marshmallow.p3d";
        rotationFlags = 17;
        weight = 50;
        quantityBar = 1;
		varTemperatureMax = 100;
        varQuantityInit = 50.0;
        varQuantityMin = 0.0;
        varQuantityMax = 50.0;
        inventorySlot = "Ingredient";
        isMeleeWeapon = 1;
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeFist";
                range = 1.0;
            };
            class Heavy
            {
                ammo = "MeleeFist_Heavy";
                range = 1.0;
            };
            class Sprint
            {
                ammo = "MeleeFist_Heavy";
                range = 2.8;
            };
        };
        hiddenSelections[] = {"cs_raw"};
        hiddenSelectionsTextures[] = 
		{
			"\WillowGlade\WG_Food\Marshmallow\data\marshmallow_texture_co.paa",
			"\WillowGlade\WG_Food\Marshmallow\data\marshmallow_baked_co.paa",
			"\WillowGlade\WG_Food\Marshmallow\data\marshmallow_boiled_co.paa",
			"\WillowGlade\WG_Food\Marshmallow\data\marshmallow_boiled_co.paa",
			"\WillowGlade\WG_Food\Marshmallow\data\marshmallow_burned_co.paa"
		};
        class AnimationSources: FoodAnimationSources{};
        class Food
        {
            class FoodStages
            {
                class Raw
                {
                    visual_properties[] = {0,0,0};
                    nutrition_properties[] = {2.5,50,80,1,0};
                    cooking_properties[] = {0,0};
                };
                class Rotten
                {
                    visual_properties[] = {-1,-1,5};
                    nutrition_properties[] = {2,37.5,40,1,0};
                    cooking_properties[] = {0,0};
                };
                class Baked
                {
                    visual_properties[] = {1,1,1};
                    nutrition_properties[] = {1.75,87.5,60,1,0};
                    cooking_properties[] = {70,35};
                };
                class Boiled
                {
                    visual_properties[] = {1,2,2};
                    nutrition_properties[] = {1.5,62.5,80,1,0};
                    cooking_properties[] = {70,45};
                };
                class Dried
                {
                    visual_properties[] = {2,3,3};
                    nutrition_properties[] = {0.75,50,8,1,0};
                    cooking_properties[] = {70,30,80};
                };
                class Burned
                {
                    visual_properties[] = {1,4,4};
                    nutrition_properties[] = {2,37.5,20,1,0};
                    cooking_properties[] = {100,20};
                };
            };
            class FoodStageTransitions: MeatStageTransitions{};
        };
        class NoiseImpact
        {
            strength = 600.0;
            type = "sound";
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class openTunaCan
                {
                    soundSet = "openTunaCan_SoundSet";
                    id = 204;
                };
                class Eating_TakeFood
                {
                    soundSet = "Eating_TakeFood_Soundset";
                    id = 889;
                };
                class Eating_BoxOpen
                {
                    soundSet = "Eating_BoxOpen_Soundset";
                    id = 893;
                };
                class Eating_BoxShake
                {
                    soundSet = "Eating_BoxShake_Soundset";
                    id = 894;
                };
                class Eating_BoxEnd
                {
                    soundSet = "Eating_BoxEnd_Soundset";
                    id = 895;
                };
            };
        };
    };
    
	class WG_WineBottle_Base: Bottle_Base
	{
		scope=0;
		weight=450;
		itemSize[]={1,3};
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		varLiquidTypeInit=131072;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536 + 131072 + 262144 - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=800;
		varQuantityMin=0;
		varQuantityMax=800;
        hiddenSelections[]=
        {
            "all"
        };
        hiddenSelectionsTextures[]=
        {
            "WillowGlade\WG_Food\winebottles\winebottles_co.paa"
        };
        hiddenSelectionsMaterials[]=
        {
            "WillowGlade\WG_Food\winebottles\winebottles.rvmat"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"WillowGlade\WG_Food\winebottles\winebottles.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_Food\winebottles\winebottles.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_Food\winebottles\winebottles_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_Food\winebottles\winebottles_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_Food\winebottles\winebottles_destruct.rvmat"
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
				class GlassBottle_in_B
				{
					soundSet="GlassBottle_in_B_SoundSet";
					id=202;
				};
				class GlassBottle_in_C
				{
					soundSet="GlassBottle_in_C_SoundSet";
					id=203;
				};
				class WaterBottle_in_C1
				{
					soundSet="WaterBottle_in_C1_SoundSet";
					id=204;
				};
				class GlassBottle_out_A
				{
					soundSet="GlassBottle_out_A_SoundSet";
					id=205;
				};
				class GlassBottle_out_B
				{
					soundSet="GlassBottle_out_B_SoundSet";
					id=206;
				};
				class WellPond_loop
				{
					soundSet="WellPond_loop_SoundSet";
					id=209;
				};
				class WellBottle_loop
				{
					soundSet="WellBottle_loop_SoundSet";
					id=210;
				};
			};
		};
	};
    class WG_WineBottle_01: WG_WineBottle_Base
	{
		scope=2;
		displayName="Dekogrove";
		descriptionShort="A pinot noir from the signature collection made in Dekogon Vinyards.";
		model="WillowGlade\WG_Food\winebottles\winebottle_01.p3d";
    };
    class WG_WineBottle_02: WG_WineBottle_Base
	{
		scope=2;
		displayName="Chateau Bourgeois";
		descriptionShort="A 25 year old cabernet sauvignon with soft flavours of plum and mulberry. PERFECT!";
		model="WillowGlade\WG_Food\winebottles\winebottle_02.p3d";
    };
    class WG_WineBottle_03: WG_WineBottle_Base
	{
		scope=2;
		displayName="Three Peaks";
		descriptionShort="A fresh and modern take on traditional sensibilities, Three peaks presents its Cabernet Sauvignon, a compelling and approachable red.";
		model="WillowGlade\WG_Food\winebottles\winebottle_03.p3d";
    };
    class WG_WineBottle_04: WG_WineBottle_Base
	{
		scope=2;
		displayName="Kollaborate";
		descriptionShort="Modern wine making technique has been used to maximize the aromatic quality of the popular Pinot Grigio Grape. This fresh crisp sparkling wine is ideal to drink on it's own.";
		model="WillowGlade\WG_Food\winebottles\winebottle_04.p3d";
    };
};