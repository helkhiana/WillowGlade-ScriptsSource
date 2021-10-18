class CfgPatches 
{
	class WG_StaticMapItems 
	{
		units[] = { };
		weapons[] = { };
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data"
		};
	};
};


class CfgVehicles
{
	class Wreck_UH1Y;
	class WG_Wreck_Mi8: Wreck_UH1Y
	{
		model="\DZ\structures\Wrecks\Aircraft\Wreck_Mi8.p3d";
	};
};

class CfgNonAIVehicles 
{
	class StaticObject;
	class Static_Garbage_Pile1 : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Pile2 : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Pile3 : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Pile4 : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Pile5 : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Pile6 : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Pile7 : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Pile8 : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Bin : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Bin2 : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Container : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Container_Glass : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Container_Paper : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Container_Plastic : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Container2_Open : StaticObject {
		scope = 1;
	};
	class Static_Garbage_Container2_Closed : StaticObject {
		scope = 1;
	};
	class Static_Wreck_S120_Red : StaticObject {
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_S120_Red.p3d";
	};
};