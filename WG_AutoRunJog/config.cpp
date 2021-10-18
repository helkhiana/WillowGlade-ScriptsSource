class CfgPatches
{
	class WG_AutoRunJog
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class WG_AutoRunJog
	{
		dir = "WG_AutoRunJog";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Auto Run Jog";
		credits = "";
		author = "Helkhiana";
		authorID = "0";
		version = "1.0";
		inputs = "WillowGlade/WG_AutoRunJog/scripts/Inputs.xml";
		extra = 0;
		type = "mod";
		dependencies[] = {"Mission"};
		class defs
		{
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_AutoRunJog/scripts/5_Mission"};
			};
		};
	};
};
