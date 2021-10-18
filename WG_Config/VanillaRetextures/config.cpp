class CfgPatches
{
	class VanillaRetextures
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Camping",
			"DZ_Gear_Consumables",
			"DZ_Gear_Cooking",
			"DZ_Gear_Tools",
			"DZ_Vehicles_Parts",
			"DZ_Scripts",
			"DZ_Characters_Tops",
			"DZ_Characters_Vests",
			"DZ_Characters_Shoes"
		};
	};
};

class CfgVehicles
{
	class Armband_Red;
	class TShirt_Black;
	class Sneakers_ColorBase;
	class WaterproofBag_ColorBase;
	class Bear_ColorBase;
	class Clothing;

	class WG_ADM_Armband : Armband_Red
	{
		displayName="Super Admin Armband";
		descriptionShort="Admin only armband";
		itemsCargoSize[]={10,30};
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa",
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa",
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa",
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa",
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa"
		};
	};
	
	class WG_ADM_Armband2 : Armband_Red
	{
		scope=2;
		displayName="Super Admin Armband";
		descriptionShort="Admin only armband";
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa",
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa",
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa",
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa",
			"\WillowGlade\WG_Config\data\armbends_admin_co.paa"
		};
	};

	class WG_Sneakers_Pink: Sneakers_ColorBase
	{
		scope=2;
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\sneakers_pink_co.paa",
			"\WillowGlade\WG_Config\data\sneakers_pink_co.paa",
			"\WillowGlade\WG_Config\data\sneakers_pink_co.paa"
		};
	};
	
	class WG_WaterproofBag_Black: WaterproofBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\waterproofbag_black_co.paa"
		};
	};
	class WG_WaterproofBag_Blue: WaterproofBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\waterproofbag_blue_co.paa"
		};
	};
	
	class WG_Bear_Blue: Bear_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\teddybear_blue_co.paa"
		};
	};
	class WG_Bear_Black: Bear_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\teddybear_black_co.paa"
		};
	};
	
    class Compass;
	class WG_JuansCompass: Compass
	{
		scope=2;
		displayName="Juans Compass";
		descriptionShort="Open and throw into your inventory to have Juan lead the way";
        hiddenSelections[]=
        {
            "zbytek"
        };
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\compass_co.paa"
		};
    };

	class ParamedicPants_ColorBase;
	class ParamedicJacket_ColorBase;
	class SurgicalMask;
	class SurgicalGloves_ColorBase;
	class WG_ParamedicPants_Black: ParamedicPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\paramedic_pants_black_co.paa",
			"WillowGlade\WG_Config\data\paramedic_pants_black_co.paa",
			"WillowGlade\WG_Config\data\paramedic_pants_black_co.paa"
		};
	};
	class WG_ParamedicJacket_Black: ParamedicJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\paramedic_jacket_black_co.paa",
			"WillowGlade\WG_Config\data\paramedic_jacket_black_co.paa",
			"WillowGlade\WG_Config\data\paramedic_jacket_black_co.paa"
		};
	};
	class WG_SurgicalMask_Black: SurgicalMask
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\surgical_mask_ground_black_co.paa",
			"WillowGlade\WG_Config\data\surgical_mask_black_co.paa",
			"WillowGlade\WG_Config\data\surgical_mask_black_co.paa"
		};
	};
	class WG_SurgicalGloves_Black: SurgicalGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\surgical_gloves_light_black_co.paa",
			"WillowGlade\WG_Config\data\surgical_gloves_light_black_co.paa",
			"WillowGlade\WG_Config\data\surgical_gloves_light_black_co.paa"
		};
	};
	class ZmbM_HunterOld_Base;
	class ZmbM_HunterOld_Santa: ZmbM_HunterOld_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\santaclaus_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"WillowGlade\WG_Config\data\hunter_old_m.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=600;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=180;
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class LeftArm
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class RightArm
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class RightLeg
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=600;
					};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints=600;
					};
				};
			};
		};
	};
	class ZmbM_HunterOld_Elf: ZmbM_HunterOld_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_Config\data\santaclaus_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"WillowGlade\WG_Config\data\hunter_old_m.rvmat"
		};
	};
	class SantasHat: Clothing
	{
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\santashat_ret_co.paa",
			"\WillowGlade\WG_Config\data\santashat_ret_co.paa",
			"\WillowGlade\WG_Config\data\santashat_ret_co.paa"
		};
	};

	class Sweater_ColorBase; 
	class WG_XmasSweater_Penguin : Sweater_ColorBase
	{
		scope=2;
		descriptionShort="A xmas sweater. It is very warm, very absorbent, and itchy as hell. By 3ntr0pia";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\xmassweater\sweater_1_g.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_1.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_1.paa"	
		};
	};	
	class WG_XmasSweater_WhiteReindeer : Sweater_ColorBase
	{
		scope=2;
		descriptionShort="A xmas sweater. It is very warm, very absorbent, and itchy as hell. By 3ntr0pia";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\xmassweater\sweater_2_g.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_2.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_2.paa"	
		};
	};
	class WG_XmasSweater_GreenReindeer : Sweater_ColorBase
	{
		scope=2;
		descriptionShort="A xmas sweater. It is very warm, very absorbent, and itchy as hell. By 3ntr0pia";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\xmassweater\sweater_3_g.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_3.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_3.paa"	
		};
	};
	class WG_XmasSweater_RedReindeer : Sweater_ColorBase
	{
		scope=2;
		descriptionShort="A xmas sweater. It is very warm, very absorbent, and itchy as hell. By 3ntr0pia";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\xmassweater\sweater_4_g.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_4.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_4.paa"	
		};
	};
	class WG_XmasSweater_BlackReindeer : Sweater_ColorBase
	{
		scope=2;
		descriptionShort="A xmas sweater. It is very warm, very absorbent, and itchy as hell. By 3ntr0pia";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\xmassweater\sweater_5_g.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_5.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_5.paa"	
		};
	};
	class WG_XmasSweater_PurpleReindeer : Sweater_ColorBase
	{
		scope=2;
		descriptionShort="A xmas sweater. It is very warm, very absorbent, and itchy as hell. By 3ntr0pia";
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\xmassweater\sweater_6_g.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_6.paa",
            "\WillowGlade\WG_Config\data\xmassweater\sweater_6.paa"	
		};
	};
	class FirstAidKit;
	class WG_GameboyCase: FirstAidKit
	{
		scope=2;
		displayName="Gameboy Case";
		descriptionShort="A case to store a gameboy and the various cartridges found around.";
		itemSize[]={3,3};
		itemsCargoSize[]={5,3};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\WillowGlade\WG_Config\data\gameboycase_co.paa"
		};
	};
};