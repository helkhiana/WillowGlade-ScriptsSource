class CfgPatches
{
    class WG_Territory
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
			"DZ_Scripts",
            "DZ_Gear_Camping",
            "BasicTerritories",
			"BaseBuildingPlus"
        };
    };
};

class CfgMods
{
    class WG_Territory
    {
        dir="WG_Territory";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "WG_Territory";
        credits = "";
        author = "helkhiana";
        authorID = "0";
        version = "0.1";
        extra = 0;
        type = "mod";        
        dependencies[] = {"Game", "World", "Mission"};        
        class defs
        {
			class gameScriptModule
            {
                value = "";
                files[] = {"WillowGlade/WG_Territory/basicterritory/scripts/3_Game"};
			};

            class worldScriptModule
            {
                value = "";
                files[] = {"WillowGlade/WG_Territory/basicterritory/scripts/4_World"};
			};

			class missionScriptModule
            {
                value = "";
                files[] = {"WillowGlade/WG_Territory/basicterritory/scripts/5_Mission"};
			};
		};
        
    };
};

class CfgVehicles
{
	class Flag_Base;	
	class WG_Flag_WillowGlade: Flag_Base
	{
		scope = 2;
		displayName="Willow Glade Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_willowglade_co.paa"};
	};
	class WG_Flag_Mauritius: Flag_Base
	{
		scope = 2;
		displayName="Mauritius Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_mauritius_co.paa"};
	};
	class WG_Flag_Brazil: Flag_Base
	{
		scope = 2;
		displayName="Brazil Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_brazil_co.paa"};
	};
	class WG_Flag_France: Flag_Base
	{
		scope = 2;
		displayName="France Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_france_co.paa"};
	};
	class WG_Flag_Germany: Flag_Base
	{
		scope = 2;
		displayName="Germany Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_germany_co.paa"};
	};
	class WG_Flag_Italy: Flag_Base
	{
		scope = 2;
		displayName="Italy Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_italy_co.paa"};
	};
	class WG_Flag_Portugal: Flag_Base
	{
		scope = 2;
		displayName="Portugal Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_portugal_co.paa"};
	};
	class WG_Flag_Romania: Flag_Base
	{
		scope = 2;
		displayName="Romania Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_romania_co.paa"};
	};
	class WG_Flag_Spain: Flag_Base
	{
		scope = 2;
		displayName="Spain Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_spain_co.paa"};
	};
	class WG_Flag_Switzerland: Flag_Base
	{
		scope = 2;
		displayName="Switzerland Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_switzerland_co.paa"};
	};
	class WG_Flag_UK: Flag_Base
	{
		scope = 2;
		displayName="UK Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_uk_co.paa"};
	};
	class WG_Flag_USA: Flag_Base
	{
		scope = 2;
		displayName="USA Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_usa_co.paa"};
	};
	class WG_Flag_Ireland: Flag_Base
	{
		scope = 2;
		displayName="Ireland Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_ireland_co.paa"};
	};
	class WG_Flag_Sweden: Flag_Base
	{
		scope = 2;
		displayName="Sweden Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_sweden_co.paa"};
	};
	class WG_Flag_UN: Flag_Base
	{
		scope = 2;
		displayName="UN Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_un_co.paa"};
	};
	class WG_Flag_Austria: Flag_Base
	{
		scope = 2;
		displayName="Austria Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_austria_co.paa"};
	};
	class WG_Flag_Denmark: Flag_Base
	{
		scope = 2;
		displayName="Denmark Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_denmark_co.paa"};
	};
	class WG_Flag_Finland: Flag_Base
	{
		scope = 2;
		displayName="Finland Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_finland_co.paa"};
	};
	class WG_Flag_Russia: Flag_Base
	{
		scope = 2;
		displayName="Russia Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_russia_co.paa"};
	};
	class WG_Flag_Scotland: Flag_Base
	{
		scope = 2;
		displayName="Scotland Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_scotland_co.paa"};
	};
	class WG_Flag_Wales: Flag_Base
	{
		scope = 2;
		displayName="Wales Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_wales_co.paa"};
	};
	class WG_Flag_Poland: Flag_Base
	{
		scope = 2;
		displayName="Poland Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_poland_co.paa"};
	};
	class WG_Flag_Japan: Flag_Base
	{
		scope = 2;
		displayName="Japan Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_japan_co.paa"};
	};
	class WG_Flag_Norway: Flag_Base
	{
		scope = 2;
		displayName="Norway Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_norway_co.paa"};
	};
	class WG_Flag_Croatia: Flag_Base
	{
		scope = 2;
		displayName="Croatia Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_croatia_co.paa"};
	};
	class WG_Flag_Czechia: Flag_Base
	{
		scope = 2;
		displayName="Czechia Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_czechia_co.paa"};
	};
	class WG_Flag_Greece: Flag_Base
	{
		scope = 2;
		displayName="Greece Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_greece_co.paa"};
	};
	class WG_Flag_Bulgaria: Flag_Base
	{
		scope = 2;
		displayName="Bulgaria Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_bulgaria_co.paa"};
	};
	class WG_Flag_Belgium: Flag_Base
	{
		scope = 2;
		displayName="Belgium Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_belgium_co.paa"};
	};
	class WG_Flag_Turkey: Flag_Base
	{
		scope = 2;
		displayName="Turkey Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_turkey_co.paa"};
	};
	class WG_Flag_Ukraine: Flag_Base
	{
		scope = 2;
		displayName="Ukraine Flag";
		hiddenSelectionsTextures[] = {"WillowGlade\WG_Territory\flag\data\flag_of_ukraine_co.paa"};
	};

	//vanilla
	
	class Flag_Chernarus: Flag_Base
	{
		displayName="Chernarus Flag";
	};
	class Flag_Chedaki: Flag_Base
	{
		displayName="Chedaki Flag";
	};
	class Flag_NAPA: Flag_Base
	{
		displayName="NAPA Flag";
	};
	class Flag_CDF: Flag_Base
	{
		displayName="CDF Flag";
	};
	class Flag_Livonia: Flag_Base
	{
		displayName="Livonia Flag";
	};
	class Flag_Altis: Flag_Base
	{
		displayName="Altis Flag";
	};
	class Flag_SSahrani: Flag_Base
	{
		displayName="South Sahrani Flag";
	};
	class Flag_NSahrani: Flag_Base
	{
		displayName="North Sahrani Flag";
	};
	class Flag_DayZ: Flag_Base
	{
		displayName="DayZ Flag";
	};
	class Flag_LivoniaArmy: Flag_Base
	{
		displayName="Livonia Army Flag";
	};
	class Flag_White: Flag_Base
	{
		displayName="White Flag";
	};
	class Flag_Bohemia: Flag_Base
	{
		displayName="Bohemia Flag";
	};
	class Flag_APA: Flag_Base
	{
		displayName="APA Flag";
	};
	class Flag_UEC: Flag_Base
	{
		displayName="UEC Flag";
	};
	class Flag_Pirates: Flag_Base
	{
		displayName="Pirates Flag";
	};
	class Flag_Cannibals: Flag_Base
	{
		displayName="Cannibals Flag";
	};
	class Flag_Bear: Flag_Base
	{
		displayName="Bear Flag";
	};
	class Flag_Wolf: Flag_Base
	{
		displayName="Wolf Flag";
	};
	class Flag_BabyDeer: Flag_Base
	{
		displayName="Bambi Flag";
	};
	class Flag_Rooster: Flag_Base
	{
		displayName="Rooster Flag";
	};
	class Flag_LivoniaPolice: Flag_Base
	{
		displayName="Livonia Police Flag";
	};
	class Flag_CMC: Flag_Base
	{
		displayName="CMC Flag";
	};
	class Flag_TEC: Flag_Base
	{
		displayName="TEC Flag";
	};
	class Flag_CHEL: Flag_Base
	{
		displayName="CHEL Flag";
	};
	class Flag_Zenit: Flag_Base
	{
		displayName="Zenit Flag";
	};
	class Flag_HunterZ: Flag_Base
	{
		displayName="HunterZ Flag";
	};
	class Flag_BrainZ: Flag_Base
	{
		displayName="BrainZ Flag";
	};
};