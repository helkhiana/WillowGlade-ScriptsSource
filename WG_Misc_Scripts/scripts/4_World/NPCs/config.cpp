////////////////////////////////////////////////////////////////////
//DeRap: WG_Misc_Scripts\scripts\4_World\NPCs\config.bin
//Produced from mikero's Dos Tools Dll version 7.68
//https://mikero.bytex.digital/Downloads
//'now' is Sun May 31 13:10:04 2020 : 'file' last modified on Sat May 30 19:42:52 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class WG_NPCs
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class SurvivorM_Mirek;
	class SurvivorF_Irena;
	class SurvivorM_Seth;
	class SurvivorF_Frida;
	class SurvivorM_Taiki;
	class SurvivorM_Jose;
	class SurvivorM_Niki;
	class SurvivorF_Maria;
	class SurvivorM_Francis;
	class SurvivorM_Rolf;
	class SurvivorM_Peter;
	class SurvivorF_Linda;
	class SurvivorM_Oliver;
	class WG_NPC_Mirek: SurvivorM_Mirek
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_adam\hhl_m_adam_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_adam\hhl_m_adam_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Irena: SurvivorF_Irena
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_irena_2\hhl_f_irena_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_irena_2\hhl_f_irena_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Frida: SurvivorF_Frida
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_frida_2\hhl_f_frida_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_frida_2\hhl_f_frida_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Seth: SurvivorM_Seth
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_seth\hhl_m_seth_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_seth\hhl_m_seth_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Taiki: SurvivorM_Taiki
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_taiki\hhl_m_taiki_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_taiki\hhl_m_taiki_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Jose: SurvivorM_Jose
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_kaito\hhl_m_kaito_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_kaito\hhl_m_kaito_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Niki: SurvivorM_Niki
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_niki_2\hhl_m_niki_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_niki_2\hhl_m_niki_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Francis: SurvivorM_Francis
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_francis\hhl_m_francis_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_francis\hhl_m_francis_body_bloodyhands.rvmat";
		};
	};
	
	class WG_NPC_Test_Francis: SurvivorM_Francis
	{
		scope = 2;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_francis\hhl_m_francis_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_francis\hhl_m_francis_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Rolf: SurvivorM_Rolf
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_rolf\hhl_m_rolf_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_rolf\hhl_m_rolf_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Peter: SurvivorM_Peter
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_peter\hhl_m_peter_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_peter\hhl_m_peter_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Maria: SurvivorF_Maria
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_maria_2\hhl_f_maria_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_maria_2\hhl_f_maria_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Linda: SurvivorF_Linda
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_linda_2\hhl_f_linda_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_linda_2\hhl_f_linda_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_Oliver: SurvivorM_Oliver
	{
		scope = 1;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal="dz\characters\heads\data\m_oliver\hhl_m_oliver_body_shaved.rvmat";
			mat_blood="dz\characters\heads\data\m_oliver\hhl_m_oliver_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_FishingBoatTransport: SurvivorM_Peter
	{
		scope = 2;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_peter\hhl_m_peter_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_peter\hhl_m_peter_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_BoatTransport: SurvivorM_Taiki
	{
		scope = 2;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_taiki\hhl_m_taiki_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_taiki\hhl_m_taiki_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_FBoatTransport: SurvivorF_Frida
	{
		scope = 2;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_frida_2\hhl_f_frida_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_frida_2\hhl_f_frida_body_bloodyhands.rvmat";
		};
	};
	class WG_NPC_HeliTransport: SurvivorM_Rolf
	{
		scope = 2;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_rolf\hhl_m_rolf_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_rolf\hhl_m_rolf_body_bloodyhands.rvmat";
		};
	};

	class WG_NPC_FHeliTransport: SurvivorF_Maria
	{
		scope = 2;
		storageCategory = 7;
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_maria_2\hhl_f_maria_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_maria_2\hhl_f_maria_body_bloodyhands.rvmat";
		};
	};
};
