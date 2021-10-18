class CfgPatches
{
	class VanillaToolsAndWeapons
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
			"DZ_Vehicles_Parts"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Cassette: Inventory_Base
	{
		displayName="Cassette";
		descriptionShort="Old classic cassette used for recording of music or voice.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class FireExtinguisher: Inventory_Base
	{
		displayName="Fire Extinguisher";
		descriptionShort="Non-Functional Extinguishr. The instructions read: 1. Hold upright. Pull ring pin. 2. Start back 10 feet. Aim at base of fire. 3. Squeeze lever. 4. Sweep side to side. Dry chemical powder type.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class MeatTenderizer: Inventory_Base
	{
		displayName="Meat tenderizer";
		descriptionShort="A meat tenderizer is a hand-powered tool used to tenderize slabs of meat in preparation for cooking.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class Sickle: Inventory_Base
	{
		displayName="Sickle";
		descriptionShort="A hand-held agricultural tool with a curved blade typically used for harvesting grain crops or cutting succulent forage chiefly for feeding livestock (either freshly cut or dried as hay).";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class Mace: Inventory_Base
	{
		displayName="Flanged Mace";
		descriptionShort="A blunt weapon, a type of club or virge that uses a heavy head on the end of a handle to deliver powerful blows. Consists of a strong, heavy metal shaft, featuring a head made of steel. The head of a military mace is shaped with flanges or knobs to allow greater penetration of plate armour. This mace has most probably ceremonial purpose.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class Iceaxe: Inventory_Base
	{
		displayName="Ice axe";
		descriptionShort="An ice axe is a multi-purpose hiking and climbing tool used by mountaineers both in the ascent and descent of routes that involve frozen conditions with snow and/or ice. An ice axe can be held and employed in a number of different ways, depending on the terrain encountered.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class Broom: Inventory_Base
	{
		displayName="Broom";
		descriptionShort="A cleaning tool consisting of stiff fibbers attached to, and roughly parallel to, a cylindrical handle, the broomstick. Mostly used to clean floors, also useful for getting rid of spider webs and scaring away animals.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class Paddle: Inventory_Base
	{
		displayName="Canoe Paddle";
		descriptionShort="A tool used for pushing against liquids, either as a form of propulsion in a boat or as an implement for mixing. Paddles commonly used in canoes consist of a wooden rod (the shaft) with a handle on one end and a rigid sheet (the blade) on the other end. This old canoe paddle seems like it has been left to rot for some time.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class Sword: Inventory_Base
	{
		displayName="Sword";
		descriptionShort="Faithful replica of a medieval sword.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class Pitchfork: Inventory_Base
	{
		displayName="Pitchfork";
		descriptionShort="An agricultural tool with a long handle and long, thick, widely separated pointed tines (also called prongs) used to lift and pitch (throw) loose material, such as hay, straw or leaves. Also capable of stabbing through soft enough objects.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class Cleaver: Inventory_Base
	{
		displayName="Cleaver";
		descriptionShort="A big, heavy and sharp knife designed to slash through thick raw meat, can also crack bones easily. Mostly used by butchers.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class PoliceBaton: Inventory_Base
	{
		displayName="Police baton";
		descriptionShort="A short metal rod with rubber used as a weapon by a police officers.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class HockeyStick: Inventory_Base
	{
		displayName="Ice Hockey Stick";
		descriptionShort="Ice hockey stick, made of wood, used in the sport of ice hockey to navigate puck by players. Using the hockey stick as a weapon during a match is strictly forbidden.";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	class TelescopicBaton: Inventory_Base
	{
		displayName="Telescopic Baton";
		descriptionShort="Telescopic Baton";
		repairableWithKits[]={5};
		repairCosts[]={30,25};
	};
	
};
