modded class DayZGame
{    
    private ref CraftingMasterConfig m_CraftingMasterConfig;

    array<ref WG_CraftingRecipe> GetCraftingRecipes()
    {
        if (!m_CraftingMasterConfig)
        {
            SetCraftingMasterConfig(new CraftingMasterConfig);
        }
        
	    return m_CraftingMasterConfig.Get_CraftingRecipesList();
    }

    void SetCraftingMasterConfig(CraftingMasterConfig craftingMasterConfig)
	{
		m_CraftingMasterConfig = craftingMasterConfig;
	}
};