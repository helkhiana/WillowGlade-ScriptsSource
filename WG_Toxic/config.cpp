class CfgPatches
{
	class WG_Toxic
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class WG_Toxic
	{
		dir = "WG_Toxic";
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
				files[] = {"WillowGlade/WG_Toxic/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Toxic/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_Toxic/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
    class HouseNoDestruct;
    class ToxicSmoke: HouseNoDestruct
	{
		scope=1;
		model="\WillowGlade\WG_Toxic\toxic.p3d";
		physLayer="item_small";
		bounding="boundingmax";
	};
    class ToxicCloud_Square: HouseNoDestruct
	{
		scope=1;
		model="\WillowGlade\WG_Toxic\toxic.p3d";
		physLayer="item_small";
		bounding="boundingmax";
	};
    class ToxicCloud_Sphere: HouseNoDestruct
	{
		scope=1;
		model="\WillowGlade\WG_Toxic\toxic.p3d";
		physLayer="item_small";
		bounding="boundingmax";
	};
    class WhiteFog: HouseNoDestruct
	{
		scope=1;
		physLayer="item_small";
	};
};