class CfgPatches
{
	class WG_Events
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
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