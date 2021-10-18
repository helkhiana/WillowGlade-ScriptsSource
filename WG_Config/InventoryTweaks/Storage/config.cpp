class CfgPatches
{
	class InventoryTweaks_Storage
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Gear_Camping","DZ_Gear_Consumables","DZ_Gear_Containers"};
	};
};
class CfgVehicles
{
	class Container_Base;
	class TentBase;
	class Barrel_ColorBase: Container_Base
	{
		itemSize[] = {8,8};
		weight = 5000;
		forceFarBubble="false";
		class Cargo
		{
			itemsCargoSize[] = {10,30};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class SeaChest: Container_Base
	{
		itemSize[] = {10,10};
		weight = 5000;
		forceFarBubble="false";
		class Cargo
		{
			itemsCargoSize[] = {10,20};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PartyTent: TentBase
	{
		itemSize[] = {6,2};
		itemsCargoSize[] = {10,40};
		forceFarBubble="false";
	};
	class MediumTent: TentBase
	{
		itemSize[] = {6,2};
		itemsCargoSize[] = {10,60};
	};
	class LargeTent: TentBase
	{
		itemSize[] = {6,3};
		itemsCargoSize[] = {10,80};
		forceFarBubble="false";
	};
	class CarTent: TentBase
	{
		itemSize[] = {6,3};
		itemsCargoSize[] = {10,100};
		forceFarBubble="false";
	};
	class PlateCarrierPouches: Container_Base
	{
		itemSize[]={8,4};
		itemsCargoSize[] = {8,4};
	};
	class GiftBox_Base: Container_Base
	{
		itemSize[]={4,4};
		itemsCargoSize[]={4,4};
	};
	class GiftBox_Medium: GiftBox_Base
	{
		itemSize[]={6,6};
		itemsCargoSize[]={6,6};
	};
	class GiftBox_Large: GiftBox_Base
	{
		itemSize[]={7,7};
		itemsCargoSize[]={7,7};
	};	
	class ShelterBase: TentBase
	{
		forceFarBubble="false";
	};
};
