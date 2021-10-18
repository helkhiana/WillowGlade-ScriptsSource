class CfgMods
{
	class MedicalAttention
	{
		dir = "MedicalAttention";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "MedicalAttention";
		credits = "Lucian";
		author = "Lucian";
		authorID = "0";
		version = "32";
		extra = 0;
		type = "mod";

		dependencies[] = {"Game", "World", "Mission"};

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_MedicalAttention/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_MedicalAttention/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_MedicalAttention/scripts/5_Mission"};
			};
		};
	};
};

class CfgPatches
{
	class MedicalAttentionScipts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Gear_Drinks",
			"namalsk_survival"
		};
	};
};

class cfgLiquidDefinitions
{	
	class Milk
	{
		type = 524288;
		displayName = "Milk";
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 50;
			water = 100;
			nutritionalIndex = 1;
			toxicity = -5;
		};
	};
	class WINE
	{
		type=131072;
		displayName="WINE";
		class Nutrition
		{
			fullnessIndex=1.75;
			energy=50;
			water=100;
			nutritionalIndex=1;
			toxicity=0.05;
			digestibility=2;
		};
	};
	class BEERT
	{
		type=262144;
		displayName="BEER";
		class Nutrition
		{
			fullnessIndex=1;
			energy=43;
			water=100;
			nutritionalIndex=1;
			toxicity=0.0099999998;
			digestibility=2;
		};
	};
};

class CfgVehicles
{
	class Bottle_Base;	
	class WaterBottle: Bottle_Base
	{
		varWetMax = 3;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536 + 131072 + 262144 - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
	};	
	class Canteen: Bottle_Base
	{
		varWetMax = 3;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536 + 131072 + 262144 - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
	};
};
