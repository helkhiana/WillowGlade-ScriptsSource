modded class PluginRecipesManager 
{
 	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		
		RegisterRecipe(new CraftMetalSheetFromCarsDoors);
		RegisterRecipe(new CraftSmallSnowmanDZN);
		UnregisterRecipe("CraftStoneKnife");
		UnregisterRecipe("CraftSpear");
		UnregisterRecipe("CraftRagRope");
		UnregisterRecipe("CraftLongTorch");
		UnregisterRecipe("CraftTorch");
		UnregisterRecipe("CraftSuppressor");
		UnregisterRecipe("CraftGhillieAttachment");
		UnregisterRecipe("CraftGhillieBushrag");
		UnregisterRecipe("CraftGhillieHood");
		UnregisterRecipe("CraftGhillieSuit");
		UnregisterRecipe("CraftGhillieTop");
		UnregisterRecipe("CraftArmbandRag");
		UnregisterRecipe("CraftCourierBag");
		UnregisterRecipe("CraftImprovisedBag");
		UnregisterRecipe("CraftBait");
		UnregisterRecipe("CraftBoneBait");
		UnregisterRecipe("CraftWoodenCrate");
		UnregisterRecipe("CraftFenceKit");
		UnregisterRecipe("CraftWatchtowerKit");
		UnregisterRecipe("CraftGunwallMetalMung");
		UnregisterRecipe("CraftGunwallMung");
		UnregisterRecipe("CraftMakeshiftshelter2mung");
		UnregisterRecipe("CraftMakeshiftsheltermung");
		UnregisterRecipe("CraftHandDrillKit");
		UnregisterRecipe("CraftFishingRod");
		UnregisterRecipe("CraftTerritoryFlagKit");
		UnregisterRecipe("CraftBaseBallBatNailed");
	}			
};