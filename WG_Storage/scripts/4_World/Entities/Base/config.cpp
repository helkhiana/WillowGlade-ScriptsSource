class CfgPatches
{
	class WG_Storage_Base
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgVehicles
{
	class Container_Base;
	class WG_Item: Container_Base
	{
		scope=0;
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		descriptionShort="This can be dismantled with a screwdriver, pliers or hammer.";
		quantityBar=1;
		carveNavmesh=1;
		bounding="BSphere";
		overrideDrawArea="3.0";
		visibilityModifier=0.94999999;
		canBeDigged=0;
		alignHologramToTerain=1;
		heavyItem=1;
		weight=10;
		itemSize[]={10,10};
		itemBehaviour=1;
		physLayer="item_large";
		simulation="inventoryItem";
		hiddenSelections[]=
		{
			"all"
		};
		class GUIInventoryAttachmentsProps
		{	
		};	
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

	class WG_Kit: Container_Base
	{
		scope=0;
		displayName="Box Kit";
		descriptionShort="A cardboard box used to transport small items. Place to deploy item inside. The items can be dismantled with a screwdriver, pliers or hammer after deployment.";
		model="\MuchStuffPack\MSP_Storage_boxes\kitbox\kitbox.p3d";
		itemsCargoSize[]={0,0};
		itemSize[]={6,4};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		rotationFlags=2;
		heavyItem=1;
		weight=3000;
		itemBehaviour=2;
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"MuchStuffPack\MSP_Storage_boxes\kitbox\kitbox_co.paa"
		};		
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

	class WG_Storage_Base: Container_Base
	{
		scope=0;      
		itemSize[]={10,15};
		overrideDrawArea="8.0";
		forceFarBubble="true";
		physLayer="item_small";
		carveNavmesh=0;
		canBeDigged=0;
		weight=1000;
		itemBehaviour=1;
		itemsCargoSize[]={0,0};
		hiddenSelections[]=
		{
			"all"
		};
		class GUIInventoryAttachmentsProps
		{	
		};		
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

	class WG_Openable_Base: WG_Item 
	{				
		class AnimationSources
		{
			class Doors1
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
			class Doors2
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
			class Doors3
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
			class Doors4
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
	};

	class WG_Openable_Placeable_Base: WG_Storage_Base
	{
		class AnimationSources
		{
			class Doors1
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
			class Doors2
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
			class Doors3
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
			class Doors4
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
	};

	class WG_Fridge_Base : WG_Item
	{		
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.03;
			cordTextureFile="DZ\gear\camping\Data\plug_black_CO.paa";
			cordLength=5;
			plugType=2;
			updateInterval=5;
		};
	};
};