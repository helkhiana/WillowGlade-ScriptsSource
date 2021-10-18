class CfgPatches
{
	class WG_BodyBags
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "MapLink"};
	};
};
class CfgMods
{
	class WG_BodyBags
	{
		dir = "WG_BodyBags";
		name = "WG_BodyBags";
		credits = "";
		author = "";
		version = "1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				files[] = {"WillowGlade/WG_BodyBags/scripts/3_Game"};
			};
			class worldScriptModule
			{
				files[] = {"WillowGlade/WG_BodyBags/scripts/4_World"};
			};
			class missionScriptModule
			{
				files[] = {"WillowGlade/WG_BodyBags/scripts/5_Mission"};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class WG_BodyBag_Base: Inventory_Base
	{
		scope = 0;
		displayName = "Wrapped body";
		descriptionShort = "Someone's body and items are inside this. If you find it, don't touch it.";
		forceFarBubble = "true";
		attachments[] = {"Shoulder","Melee","Headgear","Mask","Eyewear","Gloves","Armband","Vest","Body","Back","Hips","Legs","Feet"};		
		weight = 70000;
		itemBehaviour = 0;
		physLayer = "item_large";
		simulation = "inventoryItem";
		class AnimationSources
		{
			class Flat
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Curled
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class WG_WrappedBody: WG_BodyBag_Base
	{
		scope = 2;
		model = "WillowGlade\WG_BodyBags\data\bodybag\wrappedbody.p3d";
	};
};
