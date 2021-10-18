class CfgPatches
{
	class WG_GUI
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class WG_GUI
	{
		dir = "WG_GUI";
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
			class imageSets
			{
				files[] = {"WillowGlade/WG_GUI/imagesets/willowglade_gui.imageset"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_GUI/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_GUI/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_GUI/scripts/5_Mission"};
			};
		};
	};
};