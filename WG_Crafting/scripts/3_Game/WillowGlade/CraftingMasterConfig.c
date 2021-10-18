class CraftingMasterConfig
{	
	static const string MODCONFIG_ROOT_FOLDER = "$profile:WillowGlade/";
    static const string CONFIG_PATH = MODCONFIG_ROOT_FOLDER + "CraftingRecipeList.json";

	private ref array<ref WG_CraftingRecipe> craftingRecipesList;

	void CraftingMasterConfig()
	{
		if (!GetGame().IsServer()) return;

		if (!FileExist(MODCONFIG_ROOT_FOLDER))
        {
            Print("[CraftingMasterConfig] '" + MODCONFIG_ROOT_FOLDER + "' does NOT exist, creating directory!");
            bool created = MakeDirectory(MODCONFIG_ROOT_FOLDER);
            if(!created)
                Print("[CraftingMasterConfig] WARNING '" + MODCONFIG_ROOT_FOLDER + "' was not created. Please double check path!");
        }

        if (!FileExist(CONFIG_PATH))
        {
            Print("[CraftingMasterConfig] '" + CONFIG_PATH + "' does NOT exist, creating default config!");
            Default();
            return;
        }

        Load();
    }

	bool Load()
    {
        if (FileExist(CONFIG_PATH))
        {
            Print("[CraftingMasterConfig] '" + CONFIG_PATH + "' found, loading existing config!");
            JsonFileLoader<CraftingMasterConfig>.JsonLoadFile(CONFIG_PATH, this);
            return true;
        }
        return false;
    }

	protected void Save()
    {
        JsonFileLoader<CraftingMasterConfig>.JsonSaveFile(CONFIG_PATH, this);
    }

	protected void Default()
    {
        craftingRecipesList = new array<ref WG_CraftingRecipe>;
        WG_CraftingRecipe recipe = new WG_CraftingRecipe;
        recipe.ItemClassName = "StoneKnife";
        recipe.ResultQuantity = 1;
        recipe.KitItemClassName = "";
        recipe.IsKitItem = 0;
        recipe.ResultToInventory = 1;
        recipe.Category = "Melee";
        recipe.CraftingTime = 10;
        
        WG_CraftingRequirements requirements = new WG_CraftingRequirements;
        requirements.RequiredItemClassName = "SmallStone";
        requirements.RequiredQuantity = 2;
        requirements.IsHealthQuantity = 0;
        recipe.InsertRequirement(0,requirements);

        craftingRecipesList.Insert(recipe);
        
        WG_CraftingRecipe recipe2 = new WG_CraftingRecipe;
        recipe2.ItemClassName = "WG_FirewoodHolder_Kit";
        recipe2.ResultQuantity = 1;
        recipe2.KitItemClassName = "WG_FirewoodHolder";
        recipe2.IsKitItem = 1;
        recipe2.ResultToInventory = 1;
        recipe2.Category = "Melee";
        recipe2.CraftingTime = 10;
        
        WG_CraftingRequirements requirements01 = new WG_CraftingRequirements;
        requirements01.RequiredItemClassName = "KitchenKnife";
        requirements01.RequiredQuantity = 50;
        requirements01.IsHealthQuantity = 1;
        WG_CraftingRequirements requirements011 = new WG_CraftingRequirements;
        requirements011.RequiredItemClassName = "CombatKnife";
        requirements011.RequiredQuantity = 50;
        requirements011.IsHealthQuantity = 1;
        WG_CraftingRequirements requirements02 = new WG_CraftingRequirements;
        requirements02.RequiredItemClassName = "Whetstone";
        requirements02.RequiredQuantity = 100;
        requirements02.IsHealthQuantity = 0;
        WG_CraftingRequirements requirements022 = new WG_CraftingRequirements;
        requirements022.RequiredItemClassName = "RepairKit";
        requirements022.RequiredQuantity = 100;
        requirements022.IsHealthQuantity = 0;

        recipe2.InsertRequirement(0,requirements01);
        recipe2.InsertRequirement(0,requirements011);
        recipe2.InsertRequirement(1,requirements02);
        recipe2.InsertRequirement(1,requirements022);
        craftingRecipesList.Insert(recipe2);
		Save();
	}

	array<ref WG_CraftingRecipe> Get_CraftingRecipesList()
	{
		return craftingRecipesList;
	}
};