class CfgPatches
{
	class WG_TraderFix
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "trader" };
	};
};

class CfgMods
{
    class WG_TraderFix
    {
        dir = "WG_TraderFix";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "Willow Glade";
        credits = "Helkhiana";
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
				files[] = {"WillowGlade/WG_TraderFix/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_TraderFix/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_TraderFix/scripts/5_Mission"};
			};
		};
    };
};