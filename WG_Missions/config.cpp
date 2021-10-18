class CfgPatches
{
	class WG_Events
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"WG_Misc_Scripts"};
	};
};
class CfgMods
{
	class WG_Events
	{
		dir = "WG_Events";
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
				files[] = {"WillowGlade/WG_Events/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Events/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Events/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class SurvivorF_Gabi;
	class WG_NPC_Valya: SurvivorF_Gabi
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal="dz\characters\heads\data\f_gabi_2\hhl_f_gabi_body.rvmat";
			mat_blood="dz\characters\heads\data\f_gabi_2\hhl_f_gabi_body_bloodyhands.rvmat";
		};
	};
};
