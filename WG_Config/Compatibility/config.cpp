class CfgPatches
{
	class Compatibility_Mass
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"Mass_Guns"
		};
	};
};

class cfgWeapons
{
	class FAL;
	class CZ527;
	class gevar_base: FAL
	{
		chamberableFrom[] = {"Ammo_338", "TTC_Ammo_338"};
	};
	class Massm24_Base: CZ527
	{
		chamberableFrom[] = {"Ammo_338", "TTC_Ammo_338"};
	};
};

class CfgMagazines
{
	class Magazine_Base;
	class kivaarimag: Magazine_Base
	{
		ammoItems[] = {"Ammo_338", "TTC_Ammo_338"};
	};
	class Mass338M24Mag: Magazine_Base
	{
		ammoItems[] = {"Ammo_338", "TTC_Ammo_338"};
	};
};
