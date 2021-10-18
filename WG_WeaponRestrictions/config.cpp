class CfgPatches
{
	class WG_WeaponRestrictions
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class WG_WeaponRestrictions
	{
		dir = "WG_WeaponRestrictions";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "WG_WeaponRestrictions";
		credits = "";
		author = "";
		authorID = "0";
		version = "1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_WeaponRestrictions/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_WeaponRestrictions/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_WeaponRestrictions/scripts/5_Mission"};
			};
		};
	};
};