class WG_CraftingRecipe
{
    string ItemClassName;
    bool IsKitItem;
    string KitItemClassName;
    int ResultQuantity;
    bool ResultToInventory;
    string Category;
    int CraftingTime;
    ref array<ref WG_CraftingRequirementsCollection> RequirementsCollections;
    void InsertRequirement(int index, WG_CraftingRequirements ingredient)
	{
        ref WG_CraftingRequirementsCollection coll;
        if(!RequirementsCollections)
            RequirementsCollections = new array<ref WG_CraftingRequirementsCollection>;
        int maxIndex = RequirementsCollections.Count() - 1;
        if(index > maxIndex)
        {
            coll = new ref WG_CraftingRequirementsCollection;
            RequirementsCollections.Insert(coll);
        }
        else
        {
		    coll = RequirementsCollections[index];
        }
		coll.Insert(ingredient);
	}

    void PrintRequirements()
    {
        for(int i = 0; i < 10; i++)
		{
            Print(RequirementsCollections[i])
        }
    }

    bool CanCraft()
    {
		bool shouldCraft = false;
        foreach(WG_CraftingRequirementsCollection reqsColl : RequirementsCollections)
        {
            array<ref WG_CraftingRequirements> n_Reqs = reqsColl.Requirements;
            foreach(WG_CraftingRequirements reqs : n_Reqs)
            {
                if(reqs.IsSelected() && !reqs.HasEnoughQuantity())
                    return false;
                if(reqs.IsSelected() && reqs.HasEnoughQuantity())
                {
                    shouldCraft = true;
                    break;
                }

            }
        }
        return shouldCraft;
    }
};

class WG_CraftingRequirementsCollection
{
    ref array<ref WG_CraftingRequirements> Requirements;

    void Insert(WG_CraftingRequirements req)
    {
        if(!Requirements)
            Requirements = new array<ref WG_CraftingRequirements>;
        Requirements.Insert(req);
    }
};

class WG_CraftingRequirements
{
    string RequiredItemClassName;
    int RequiredQuantity;
    bool IsHealthQuantity;
    private bool m_HasEnoughQuantity = false;
    private bool m_IsSelected = false;

    bool HasEnoughQuantity()
    {
        return m_HasEnoughQuantity;
    }

    void SetEnoughQuantity(bool enoughQuant)
    {
        m_HasEnoughQuantity = enoughQuant;
    }
    
    bool IsSelected()
    {
        return m_IsSelected;
    }

    void SetIsSelected(bool value)
    {
        m_IsSelected = value;
    }
};