class CfgPatches
{
	class Surfaces
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Surfaces",
			"DZ_Surfaces_Bliss",
			"namalsk_terrain"
		};
	};
};

class CfgVehicleSurfaces
{
	class Asphalt
	{
		frictionOffroad=0.89999998;
		frictionSlick=1;
		rollResistance=1;
		rollDrag=0.1;
	};
	class Dirt
	{
		noiseSteer=0.0089999996;
		noiseFrequency=0.31;
		roughness=0.02;
		frictionSlick=1;
		rollResistance=1;
		rollDrag=30;
	};
	class Grass
	{
		noiseSteer=0.02;
		noiseFrequency=0.64999998;
		roughness=0.029999999;
		frictionSlick=1;
		rollResistance=1;
		rollDrag=50;
	};
	class Forest
	{
		noiseSteer=0.039999999;
		noiseFrequency=1.65;
		roughness=0.090000004;
		frictionSlick=1;
		rollResistance=1;
		rollDrag=75;
	};
	class Gravel
	{
		noiseSteer=0.07;
		noiseFrequency=2;
		roughness=0.039999999;
		frictionSlick=1;
		rollResistance=1;
		rollDrag=70;
	};
};

class CfgSurfaces
{
	class DZ_SurfacesInt;
	class DZ_SurfacesExt;
    class cp_concrete1: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_concrete2: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_dirt: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_broadleaf_dense1: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_broadleaf_dense2: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_broadleaf_sparse1: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_broadleaf_sparse2: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_conifer_common1: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_grass: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_grass_tall: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_rock: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class cp_gravel: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class en_grass1: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class en_grass2: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class en_flowers1: en_grass2
	{
		vpSurface="Asphalt";
	};
	class en_flowers2: en_grass2
	{
		vpSurface="Asphalt";
	};
	class en_flowers3: en_grass2
	{
		vpSurface="Asphalt";
	};
	class en_forestcon: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class en_forestdec: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class en_soil: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class en_tarmac: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class en_tarmacold: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class en_stubble: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class en_stones: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class gravel_large_ext: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class gravel_large_int: DZ_SurfacesInt
	{
		vpSurface="Asphalt";
	};
	class gravel_small_ext: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class gravel_small_int: DZ_SurfacesInt
	{
		vpSurface="Asphalt";
	};
	class sand_ext: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class sand_int: DZ_SurfacesInt
	{
		vpSurface="Asphalt";
	};
	class dirt_ext: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class dirt_int: DZ_SurfacesInt
	{
		vpSurface="Asphalt";
	};
	class grass_dry_ext: DZ_SurfacesExt
	{
		vpSurface="Asphalt";
	};
	class grass_dry_int: DZ_SurfacesInt
	{
		vpSurface="Asphalt";
	};
	//namalsk
	class nam_grass: DZ_SurfacesExt
	{
		vpSurface = "Asphalt";
	};
	class nam_grassd: DZ_SurfacesExt
	{
		vpSurface = "Asphalt";
	};
	class nam_forest: DZ_SurfacesExt
	{
		vpSurface = "Asphalt";
	};
	class nam_snow: DZ_SurfacesExt
	{
		vpSurface = "Asphalt";
	};
	class nam_seaice: DZ_SurfacesExt
	{
		vpSurface = "Asphalt";
	};
	class nam_snowgrass: DZ_SurfacesExt
	{
		vpSurface = "Asphalt";
	};
	class nam_clay: DZ_SurfacesExt
	{
		vpSurface = "Asphalt";
	};
	class nam_asphalt: DZ_SurfacesExt
	{
		vpSurface = "Asphalt";
	};
	class nam_beton: DZ_SurfacesExt
	{
		vpSurface = "Asphalt";
	};
	class nam_lakewater_ext: DZ_SurfacesExt
	{
		vpSurface = "Gravel";
	};
	class nam_lakeice_ext: DZ_SurfacesExt
	{
		vpSurface = "Gravel";
	};
};
