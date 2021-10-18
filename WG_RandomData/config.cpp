class CfgPatches
{
	class WG_RandomData
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class WG_RandomData
	{
		dir = "WG_RandomData";
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
				files[] = {"WillowGlade/WG_RandomData/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_RandomData/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"WillowGlade/WG_RandomData/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class WG_NoBuildZoneSign : HouseNoDestruct
	{
		scope=1;
		model = "\WillowGlade\WG_RandomData\nobuildzonesign\signs.p3d";
	};
	class WG_Surfboard : HouseNoDestruct
	{
		scope=1;
		model = "\WillowGlade\WG_RandomData\tikibar\surfboard.p3d";
	};
	class WG_TikiBar : HouseNoDestruct
	{
		scope=1;
		model = "\WillowGlade\WG_RandomData\tikibar\tikibar.p3d";
        class Doors
		{
			class Doors1
			{
				displayName="door 1";
				component="Doors1";
				soundPos="doors1_action";
				animPeriod=1;
				initPhase=0;
				initOpened=0.40000001;
				soundOpen="doorWoodFrontOpen";
				soundClose="doorWoodFrontClose";
				soundLocked="doorWoodFrontRattle";
				soundOpenABit="doorWoodFrontOpenABit";
			};
			class Doors2
			{
				displayName="door 2";
				component="Doors2";
				soundPos="doors2_action";
				animPeriod=1;
				initPhase=0;
				initOpened=0.40000001;
				soundOpen="doorWoodFrontOpen";
				soundClose="doorWoodFrontClose";
				soundLocked="doorWoodFrontRattle";
				soundOpenABit="doorWoodFrontOpenABit";
			};
        };
	};

	class WG_OldKeg : HouseNoDestruct
	{
		scope=1;
		model = "\WillowGlade\WG_RandomData\oldkeg\oldkeg.p3d";
	};

	class WG_Invisible_Keg : HouseNoDestruct
	{
		scope=1;
		model = "\WillowGlade\WG_RandomData\oldkeg\invisible_keg.p3d";
	};

	class WG_BeerTap : HouseNoDestruct
	{
		scope=1;
		model = "\WillowGlade\WG_RandomData\oldkeg\beertap.p3d";
	};

	class Inventory_Base;
	class WG_Coin_Base: Inventory_Base
	{
		scope = 0;
		model = "\WillowGlade\WG_RandomData\coins\coin_gold.p3d";
		isMeleeWeapon = 1;
		weight = 4;
		absorbency = 0;
		itemSize[] = {1,1};
		rotationFlags = 16;
	};

	class WG_Token_Silver: WG_Coin_Base
	{
		scope = 2;
		displayName = "Silver Token";
		descriptionShort = "An old token. It appears to be plated in silver.";
		model = "\WillowGlade\WG_RandomData\coins\coin_silver.p3d";
	};
	class WG_Token_Gold: WG_Coin_Base
	{
		scope = 2;
		displayName = "Gold Token";
		descriptionShort = "An old token. It appears to be plated in gold.";
		model = "\WillowGlade\WG_RandomData\coins\coin_gold.p3d";
	};
	class WG_Token_Halloween: WG_Coin_Base
	{
		scope = 2;
		displayName = "Halloween Token";
		descriptionShort = "An token used at carnivals. You can trade it for halloween themed items.";
		model = "\WillowGlade\WG_RandomData\coins\coin_gold.p3d";
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\coins\data\coin_halloween_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"WillowGlade\WG_RandomData\coins\data\coin_halloween.rvmat"
		};
	};

	
	class WG_Token_Storages: WG_Coin_Base
	{
		scope = 0;
		displayName = "Storage Token";
		descriptionShort = "An token used to rent Storages.";
		model = "\WillowGlade\WG_RandomData\coins\coin_silver.p3d";
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\coins\data\coin_silversimple_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"WillowGlade\WG_RandomData\coins\data\coin_silversimple.rvmat"
		};
	};

	class WG_Token_Storages_Tier1: WG_Token_Storages
	{
		scope = 2;
		displayName = "Tier 1 Storage Token";
		descriptionShort = "An token used to rent a tier 1 Storage.";
	};
	class WG_Token_Storages_Tier2: WG_Token_Storages
	{
		scope = 2;
		displayName = "Tier 2 Storage Token";
		descriptionShort = "An token used to rent a tier 2 Storage.";
	};
	class WG_Token_Storages_Tier3: WG_Token_Storages
	{
		scope = 2;
		displayName = "Tier 3 Storage Token";
		descriptionShort = "An token used to rent a tier 3 Storage.";
	};
	class WG_Token_Storages_Tier4: WG_Token_Storages
	{
		scope = 2;
		displayName = "Tier 4 Storage Token";
		descriptionShort = "An token used to rent a tier 4 Storage.";
	};
	class WG_Token_Storages_Tier5: WG_Token_Storages
	{
		scope = 2;
		displayName = "Tier 5 Storage Token";
		descriptionShort = "An token used to rent a tier 5 Storage.";
	};

	class WG_ATM_Base: HouseNoDestruct
	{
		scope = 0;
		model = "\WillowGlade\WG_RandomData\bankomat\bankomat.p3d";
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\bankomat\data\bankomat_red_co.paa"
		};
	};
	class WG_ATM_Red: WG_ATM_Base
	{
		scope = 1;
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\bankomat\data\bankomat_red_co.paa"
		};
	};
	class WG_ATM_Blue: WG_ATM_Base
	{
		scope = 1;
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\bankomat\data\bankomat_blue_co.paa"
		};
	};
	class WG_ATM_Gold: WG_ATM_Base
	{
		scope = 1;
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\bankomat\data\bankomat_gold_co.paa"
		};
	};	
	class WG_ATM_Place: HouseNoDestruct
	{
		scope = 1;
		model = "\WillowGlade\WG_RandomData\bankomat\bankomat.p3d";
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\bankomat\data\bankomat_red_co.paa"
		};
	};
	class Compass;
	class Clothing;
	class WG_PocketWatch: Compass	
	{
		scope=2;
		displayName="Pocketwatch";
		descriptionShort="A valuable pocketwatch that shows in game time.";
		model="\WillowGlade\WG_RandomData\pocketwatch\pocketwatch.p3d";
		weight=550;
		simulation="inventoryItem";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{						
						{
							1.0,							
							{
								"WillowGlade\WG_RandomData\pocketwatch\pocketwatch.rvmat"
							}
						},						
						{
							0.69999999,							
							{
								"WillowGlade\WG_RandomData\pocketwatch\pocketwatch.rvmat"
							}
						},						
						{
							0.5,							
							{
								"WillowGlade\WG_RandomData\pocketwatch\pocketwatch_damage.rvmat"
							}
						},						
						{
							0.30000001,							
							{
								"WillowGlade\WG_RandomData\pocketwatch\pocketwatch_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"WillowGlade\WG_RandomData\pocketwatch\pocketwatch_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class ItemBook;
	class WG_Journal: ItemBook
	{
		scope=2;
		displayName="Journal";
		descriptionShort="A journal where you can store paper, written notes and pens.";
		model="\WillowGlade\WG_RandomData\journal\journal.p3d";
		rotationFlags=1;
		itemsCargoSize[]={10,3};
		allowOwnedCargoManipulation=1;
	};
	class WG_ScrapCrate : Inventory_Base
	{
		scope=2;
		displayName="Scrap";
		descriptionShort="A crate with some scrap. Used for crafting.";
		model="\WillowGlade\WG_RandomData\scrapcrate\scrapcrate.p3d";
		weight=100;
		itemSize[]={3,2};
		varWetMax=0.0;
		rotationFlags=2;
		stackedUnit="pc.";
		quantityBar=0;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		canBeSplit=1;
		varQuantityDestroyOnMin=1;	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};

	class WG_Kit;
	class WG_AdventurerTent_Kit: WG_Kit
	{	
		scope=2;	
		displayName="Adventurer Tent Kit";
		descriptionShort="This can be dismantled with pliers, hammer or screwdriver.";
		model="\WillowGlade\WG_RandomData\adventurertent\adventurertent_kit.p3d";
		rotationFlags=17;		
		itemSize[] = {2,5};
	};
	class WG_Item;
	class WG_AdventurerTent: WG_Item
	{
		scope=2;
		displayName="Adventurer Tent";
		descriptionShort="This can be dismantled with pliers, hammer or screwdriver. It must be empty before dismantling.";
		model="\WillowGlade\WG_RandomData\adventurertent\adventurertent.p3d";
		itemsCargoSize[]={8,10};
	};

	class Grenade_Base;
	class WG_PipeBomb_Base: Grenade_Base
	{
		scope=0;
		displayName="Improvised Pipe Bomb";
		descriptionShort="An improvised pipe bomb made out of scrap, nails and rope. Tape 3 of these together for bigger bang!";
		model="\WillowGlade\WG_RandomData\pipebomb\pipebomb.p3d";
		weight=350;
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"WillowGlade\WG_RandomData\pipebomb\pipebomb_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"WillowGlade\WG_RandomData\pipebomb\pipebomb.rvmat"
		};
		class EnergyManager
		{
			energyAtSpawn=90;
			energyUsagePerSecond=1;
			wetnessExposure=0.1;
			updateInterval=5;
		};
		class NoiseRoadFlare
		{
			strength=30;
			type="shot";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"WillowGlade\WG_RandomData\pipebomb\pipebomb.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_RandomData\pipebomb\pipebomb.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_RandomData\pipebomb\pipebomb_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_RandomData\pipebomb\pipebomb_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_RandomData\pipebomb\pipebomb_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Flare_strike
				{
					soundSet="Flare_strike_SoundSet";
					id=201;
				};
				class Flare_open
				{
					soundSet="Flare_open_SoundSet";
					id=202;
				};
			};
		};
	};
	class WG_PipeBomb: WG_PipeBomb_Base
	{
		scope=2;
		displayName="Improvised Pipe Bomb";
		descriptionShort="An improvised pipe bomb made out of scrap, nails and gunpowder. Tape 3 of these together for bigger bang!";
		model="\WillowGlade\WG_RandomData\pipebomb\pipebomb.p3d";
	};
	class WG_PipeBomb_Bundle: WG_PipeBomb_Base
	{
		scope=2;
		displayName="Improvised Pipe Bomb Bundle";
		descriptionShort="An improvised pipe bomb bundle made out of 3 pipe bombs and some duct tape.";
		model="\WillowGlade\WG_RandomData\pipebomb\pipebomb_bundle.p3d";	
		itemSize[] = {2,2};
	};
	class WG_Ticket_Base: Inventory_Base
	{
		scope = 0;
		model = "\WillowGlade\WG_RandomData\ticket\travelticket.p3d";
		isMeleeWeapon = 1;
		weight = 4;
		absorbency = 0;
		itemSize[] = {1,2};
		rotationFlags = 16;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
	};
	class WG_Ticket_Generic: WG_Ticket_Base
	{
		scope = 2;
		displayName = "Ticket";
		descriptionShort = "This ticket can be used to travel to another region.";
	};
	class WG_Gunpowder: Inventory_Base
	{
		scope=2;
		displayName="Gunpowder";
		descriptionShort="A tin of 1kg of extra coarse grain gun powder. Can be used in making explosives or bullets.";
		model="\WillowGlade\WG_RandomData\gunpowder\gunpowder.p3d";
		weight=250;
		itemSize[]={2,3};
		absorbency=0;
		rotationFlags=2;
		stackedUnit="g";
		quantityBar=1;
		varQuantityInit=1000;
		varQuantityMin=0;
		varQuantityMax=1000;
		varQuantityDestroyOnMin=1;
		destroyOnEmpty=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"WillowGlade\WG_RandomData\gunpowder\gunpowder.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"WillowGlade\WG_RandomData\gunpowder\gunpowder.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"WillowGlade\WG_RandomData\gunpowder\gunpowder_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"WillowGlade\WG_RandomData\gunpowder\gunpowder_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"WillowGlade\WG_RandomData\gunpowder\gunpowder_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="BakedBeansCan_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="BakedBeansCan_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class WG_WD40: Inventory_Base
	{
		scope = 2;
		displayName="WD-40";
		descriptionShort="The original multi-purpose lubricant, WD-40 protects metal from rust and corrosion, penetrates stuck or jammed parts, displaces moisture and lubricates just about anything. WD-40 is also great when it comes to cleaning grease, grime and other marks from most surfaces.";
		model = "\WillowGlade\WG_RandomData\wd40\wd40.p3d";
		isMeleeWeapon = 1;
		weight = 400;
		absorbency = 0;
		itemSize[] = {1,3};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{						
						{
							1.0,							
							{
								"WillowGlade\WG_RandomData\wd40\wd40.rvmat"
							}
						},						
						{
							0.69999999,							
							{
								"WillowGlade\WG_RandomData\wd40\wd40.rvmat"
							}
						},						
						{
							0.5,							
							{
								"WillowGlade\WG_RandomData\wd40\wd40_damage.rvmat"
							}
						},						
						{
							0.30000001,							
							{
								"WillowGlade\WG_RandomData\wd40\wd40_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"WillowGlade\WG_RandomData\wd40\wd40_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="BakedBeansCan_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="BakedBeansCan_drop_SoundSet";
					id=898;
				};
			};
		};
	};	
	class WG_AircraftBattery: Inventory_Base
	{
		scope=2;
		displayName="Aircraft Battery";
		descriptionShort="This battery seems drained. Maybe it can be used for something else or barter.";
		model="\dz\vehicles\parts\aircraft_battery.p3d";
		weight=10000;
		itemSize[]={3,3};
		absorbency=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"DZ\vehicles\parts\data\aircraft_battery.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\vehicles\parts\data\aircraft_battery.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\vehicles\parts\data\aircraft_battery_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\vehicles\parts\data\aircraft_battery_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"DZ\vehicles\parts\data\aircraft_battery_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundset="carbattery_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class WG_Gameboy: Inventory_Base
	{
		scope = 2;
		displayName="Gameboy";
		descriptionShort="The Game Boy is an 8-bit handheld video game console developed and manufactured by Nintendo. It was released in Japan on April 21, 1989, in North America in August 1989, and in Europe in 1990.";
		model = "\WillowGlade\WG_RandomData\gameboy\gameboy.p3d";
		isMeleeWeapon = 1;
		weight = 400;
		absorbency = 0;
		itemSize[] = {2,2};
		rotationFlags = 16;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{						
						{
							1.0,							
							{
								"WillowGlade\WG_RandomData\gameboy\gameboy.rvmat"
							}
						},						
						{
							0.69999999,							
							{
								"WillowGlade\WG_RandomData\gameboy\gameboy.rvmat"
							}
						},						
						{
							0.5,							
							{
								"WillowGlade\WG_RandomData\gameboy\gameboy_damage.rvmat"
							}
						},						
						{
							0.30000001,							
							{
								"WillowGlade\WG_RandomData\gameboy\gameboy_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"WillowGlade\WG_RandomData\gameboy\gameboy_destruct.rvmat"
							}
						}
					};
				};
			};
		};		
	};
	class WG_Gameboy_Cartridge_Base: Inventory_Base
	{
		scope = 0;
		displayName="Gameboy Game";
		descriptionShort="This is a game for the game boy. The Game Boy is an 8-bit handheld video game console developed and manufactured by Nintendo. It was released in Japan on April 21, 1989, in North America in August 1989, and in Europe in 1990.";
		model = "\WillowGlade\WG_RandomData\gameboy\cartridges\cartridge.p3d";
		isMeleeWeapon = 1;
		weight = 200;
		absorbency = 0;
		itemSize[] = {1,1};
		rotationFlags = 16;
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_donkeykong_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{						
						{
							1.0,							
							{
								"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge.rvmat"
							}
						},						
						{
							0.69999999,							
							{
								"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge.rvmat"
							}
						},						
						{
							0.5,							
							{
								"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_damage.rvmat"
							}
						},						
						{
							0.30000001,							
							{
								"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_destruct.rvmat"
							}
						}
					};
				};
			};
		};		
	};
	class WG_Crtg_DonkeyKong: WG_Gameboy_Cartridge_Base
	{
		scope = 2;
		displayName="Donkey Kong";
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_donkeykong_co.paa"
		};
	};
	class WG_Crtg_Medarot: WG_Gameboy_Cartridge_Base
	{
		scope = 2;
		displayName="Medarot";
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_MEDAROT_co.paa"
		};
	};
	class WG_Crtg_Pokemon_Red: WG_Gameboy_Cartridge_Base
	{
		scope = 2;
		displayName="Pokemon Charizard";
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_POKEMON_RED_co.paa"
		};
	};
	class WG_Crtg_Pokemon_Yellow: WG_Gameboy_Cartridge_Base
	{
		scope = 2;
		displayName="Pokemon Pikachu";
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_POKEMON_YELLOW_co.paa"
		};
	};
	class WG_Crtg_SneakySnakes: WG_Gameboy_Cartridge_Base
	{
		scope = 2;
		displayName="Sneaky Snakes";
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_SNEAKY_SNAKES_co.paa"
		};
	};
	class WG_Crtg_SuperMario: WG_Gameboy_Cartridge_Base
	{
		scope = 2;
		displayName="Super Mario";
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_SUPER_MARIO_LAND_co.paa"
		};
	};
	class WG_Crtg_Tetris: WG_Gameboy_Cartridge_Base
	{
		scope = 2;
		displayName="Tetris";
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_TETRIS_co.paa"
		};
	};
	class WG_Crtg_Yoshi: WG_Gameboy_Cartridge_Base
	{
		scope = 2;
		displayName="Yoshi";
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_YOSHI_co.paa"
		};
	};
	class WG_Crtg_Zelda: WG_Gameboy_Cartridge_Base
	{
		scope = 2;
		displayName="Zelda";
		hiddenSelectionsTextures[] = 
		{
			"WillowGlade\WG_RandomData\gameboy\cartridges\cartridge_ZELDA_co.paa"
		};
	};
	class WG_Tetris: Inventory_Base
	{
		scope = 2;
		displayName="Tetris";
		descriptionShort="Tetris, video game created by Russian designer Alexey Pajitnov in 1985 that allows players to rotate falling blocks strategically to clear levels. The goal of the game is to prevent the blocks from stacking up to the top of the screen for as long as possible.";
		model = "\WillowGlade\WG_RandomData\tetris\tetris.p3d";
		isMeleeWeapon = 1;
		weight = 400;
		absorbency = 0;
		itemSize[] = {2,3};
		rotationFlags = 16;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{						
						{
							1.0,							
							{
								"WillowGlade\WG_RandomData\tetris\tetris.rvmat"
							}
						},						
						{
							0.69999999,							
							{
								"WillowGlade\WG_RandomData\tetris\tetris.rvmat"
							}
						},						
						{
							0.5,							
							{
								"WillowGlade\WG_RandomData\tetris\tetris_damage.rvmat"
							}
						},						
						{
							0.30000001,							
							{
								"WillowGlade\WG_RandomData\tetris\tetris_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"WillowGlade\WG_RandomData\tetris\tetris_destruct.rvmat"
							}
						}
					};
				};
			};
		};		
	};	
	class WG_AircraftOil_Turbine: Inventory_Base
	{
		scope=2;
		displayName="Aircraft Turbine Oil";
		descriptionShort="Synthetic lubricating oil for aircraft turbine engines and helicopter transmissions.";
		model = "\DZ\vehicles\parts\air_oil_bottle.p3d";
		weight=5000;
		itemSize[]={3,3};
		absorbency=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1.0,							
							{
								"DZ\vehicles\parts\data\air_oil_bottle_turbine.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\vehicles\parts\data\air_oil_bottle_turbine.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\vehicles\parts\data\air_oil_bottle_turbine_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\vehicles\parts\data\air_oil_bottle_turbine_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"DZ\vehicles\parts\data\air_oil_bottle_turbine_destruct.rvmat"
							}
						}
					};
				};
			};
		};		
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpCanisterGasoline_Light
				{
					soundSet="pickUpCanisterGasolineLight_SoundSet";
					id=796;
				};
				class pickUpCanisterGasoline
				{
					soundSet="pickUpCanisterGasoline_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="canistergasoline_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class WG_AircraftHydraulicFluid: Inventory_Base
	{
		scope=2;
		displayName="Aircraft Hydraulic Fluid";
		descriptionShort="Mineral hydraulic fluid for aircrafts.";
		model = "\DZ\vehicles\parts\hydraulic_fluid_bottle.p3d";
		weight=5000;
		itemSize[]={3,3};
		absorbency=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{						
						{
							1.0,							
							{
								"DZ\vehicles\parts\data\hydraulic_fluid_bottle.rvmat"
							}
						},						
						{
							0.69999999,							
							{
								"DZ\vehicles\parts\data\hydraulic_fluid_bottle.rvmat"
							}
						},						
						{
							0.5,							
							{
								"DZ\vehicles\parts\data\hydraulic_fluid_bottle_damage.rvmat"
							}
						},						
						{
							0.30000001,							
							{
								"DZ\vehicles\parts\data\hydraulic_fluid_bottle_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"DZ\vehicles\parts\data\hydraulic_fluid_bottle_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpCanisterGasoline_Light
				{
					soundSet="pickUpCanisterGasolineLight_SoundSet";
					id=796;
				};
				class pickUpCanisterGasoline
				{
					soundSet="pickUpCanisterGasoline_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="canistergasoline_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class WG_Rocket_RPG: Inventory_Base
	{
		scope=2;	
		displayName="PG-7V Warhead";
		descriptionShort="Modernized HEAT warhead effective against most vehicles and fortified targets. Used as barter item nowadays.";
		model="\WillowGlade\WG_RandomData\rockets\rocket_rpg.p3d";
		weight=2000;
		itemSize[]={4,1};
		absorbency=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{						
						{
							1.0,							
							{
								"DZ\weapons\ammunition\data\rocket_rpg7.rvmat"
							}
						},						
						{
							0.69999999,							
							{
								"DZ\weapons\ammunition\data\rocket_rpg7.rvmat"
							}
						},						
						{
							0.5,							
							{
								"DZ\weapons\ammunition\data\rocket_rpg7_damage.rvmat"
							}
						},						
						{
							0.30000001,							
							{
								"DZ\weapons\ammunition\data\rocket_rpg7_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"DZ\weapons\ammunition\data\rocket_rpg7_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class WG_Rocket_LAW: Inventory_Base
	{
		scope=2;	
		displayName="M72 LAW Warhead";
		descriptionShort="A 66-mm HEAT warhead which practically should be attached to the inside of the M72 LAW launcher by the igniter. Used as barter item nowadays.";
		model="\WillowGlade\WG_RandomData\rockets\rocket_law.p3d";
		weight=2000;
		itemSize[]={4,1};
		absorbency=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{						
						{
							1.0,							
							{
								"DZ\weapons\launchers\law\data\law_rocket.rvmat"
							}
						},						
						{
							0.69999999,							
							{
								"DZ\weapons\launchers\law\data\law_rocket.rvmat"
							}
						},						
						{
							0.5,							
							{
								"DZ\weapons\launchers\law\data\law_rocket_damage.rvmat"
							}
						},						
						{
							0.30000001,							
							{
								"DZ\weapons\launchers\law\data\law_rocket_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"DZ\weapons\launchers\law\data\law_rocket_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class WG_Wallet: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_Wallet";
		descriptionShort = "$STR_Wallet_des";
		model = "\WillowGlade\WG_RandomData\wallet\wallet.p3d";
		weight = 130;
		itemSize[] = {3,2};
		itemsCargoSize[] = {6,4};
		canBeDigged = 0;
		allowOwnedCargoManipulation = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						{
							1.0,
							{
								"WillowGlade\WG_RandomData\wallet\wallet.rvmat"
							}
						},						
						{
							0.69999999,
							{
								"WillowGlade\WG_RandomData\wallet\wallet.rvmat"
							}
						},						
						{
							0.5,							
							{
								"WillowGlade\WG_RandomData\wallet\wallet_damage.rvmat"
							}
						},						
						{
							0.30000001,
							{
								"WillowGlade\WG_RandomData\wallet\wallet_damage.rvmat"
							}
						},						
						{
							0.0,							
							{
								"WillowGlade\WG_RandomData\wallet\wallet_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};
class CfgAmmo
{
	class DefaultAmmo;
	class PipeBomb_Ammo: DefaultAmmo
	{
		indirectHit=1;
		indirectHitRange=3;
		explosive=1;
		typicalSpeed=3;
		initSpeed=3;
		simulation="shotShell";
		simulationStep=0.050000001;
		soundSetExplosion[]=
		{
			"Grenade_explosion_SoundSet",
			"Grenade_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			bleedThreshold=0.40000001;
			class Health
			{
				damage=50;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=0;
			};
		};
		class NoiseExplosion
		{
			strength=100;
			type="shot";
		};
	};
	class PipeBombBundle_Ammo: DefaultAmmo
	{
		indirectHit=1;
		indirectHitRange=6;
		explosive=1;
		typicalSpeed=3;
		initSpeed=3;
		simulation="shotShell";
		simulationStep=0.050000001;
		soundSetExplosion[]=
		{
			"Grenade_explosion_SoundSet",
			"Grenade_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			bleedThreshold=0.40000001;
			class Health
			{
				damage=150;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=0;
			};
		};
		class NoiseExplosion
		{
			strength=100;
			type="shot";
		};
	};
};