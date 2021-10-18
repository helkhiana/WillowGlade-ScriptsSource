class CfgPatches
{
	class Perishable_Food
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class CfgMods
{
	class PerishableFood
	{
		dir = "PerishableFood";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "PerishableFood";
		credits = "Lucian, Creep";
		author = "Lucian, Creep";
		authorID = "0";
		version = "5";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_PerishableFood/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_PerishableFood/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_PerishableFood/scripts/5_Mission"};
			};
		};
	};
};