modded class CutOutPepperSeeds extends RecipeBase
{
	override void Init()
	{
		super.Init();
		m_ResultSetQuantity[0] = 3;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		Edible_Base ingredient1 = Edible_Base.Cast(ingredients[0]);
		if(ingredient1 && !ingredient1.IsFoodRotten() && !ingredient1.IsFoodBurned())
			return true;
		return false;
	}
};

modded class CutOutPumpkinSeeds extends RecipeBase
{
	override void Init()
	{
		super.Init();
		m_ResultSetQuantity[0] = 3;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		Edible_Base ingredient1 = Edible_Base.Cast(ingredients[0]);
		if(ingredient1 && !ingredient1.IsFoodRotten() && !ingredient1.IsFoodBurned())
			return true;
		return false;
	}
};
modded class CutOutZucchiniSeeds extends RecipeBase
{
	override void Init()
	{
		super.Init();
		m_ResultSetQuantity[0] = 3;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		Edible_Base ingredient1 = Edible_Base.Cast(ingredients[0]);
		if(ingredient1 && !ingredient1.IsFoodRotten() && !ingredient1.IsFoodBurned())
			return true;
		return false;
	}
};


modded class CutOutTomatoSeeds extends RecipeBase
{
	override void Init()
	{
		super.Init();
		m_ResultSetQuantity[0] = 3;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		Edible_Base ingredient1 = Edible_Base.Cast(ingredients[0]);
		if(ingredient1 && !ingredient1.IsFoodRotten() && !ingredient1.IsFoodBurned())
			return true;
		return false;
	}
};