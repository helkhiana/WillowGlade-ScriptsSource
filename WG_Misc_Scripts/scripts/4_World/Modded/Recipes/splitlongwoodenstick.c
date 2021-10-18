modded class SplitLongWoodenStick extends RecipeBase
{	
	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)
	{
		Debug.Log("Recipe Do method called","recipes");
		int ingredient1Quant = ingredients[0].GetQuantity();
		if(ingredient1Quant == 1)
			return;
		int resultQuant = results[0].GetQuantity() * ingredient1Quant;
		results[0].SetQuantity(resultQuant);
	}
};