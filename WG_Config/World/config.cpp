class CfgPatches
{
	class WG_Worlds_ChernarusPlus
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Worlds_Chernarusplus_World"};
		worlds[] = {};
	};
};
class CfgWorlds
{
	class CAWorld;
	class Weather;
	class ChernarusPlus: CAWorld
	{	
		oceanMaterial = "WillowGlade/WG_Config/World/data/wg_material_ocean.emat";
		oceanNiceMaterial = "WillowGlade/WG_Config/World/data/wg_material_ocean_Nice.emat";
		oceanStormMaterial = "WillowGlade/WG_Config/World/data/wg_material_ocean_Storm.emat";
	};
};