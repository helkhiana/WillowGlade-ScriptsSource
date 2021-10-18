class CfgPatches
{
    class WG_CharacterTweaks
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1;
        requiredAddons[] = {"DZ_Characters"};
    };
};

class CfgVehicles
{
	class Man;
	class SurvivorBase: Man
	{
		class Skinning
		{
			class Steaks
			{
				item="HumanSteakMeat";
				count=0;
				quantityMinMaxCoef[]={0.5,1};
			};
			class Guts
			{
				item="Guts";
				count=0;
				quantityMinMaxCoef[]={0.5,1};
			};
			class Lard
			{
				item="Lard";
				count=0;
				quantityMinMaxCoef[]={0.5,1};
			};
			class Bones
			{
				item="Bone";
				count=0;
				quantityMinMaxCoef[]={0.75,1};
			};
		};		
	};
};