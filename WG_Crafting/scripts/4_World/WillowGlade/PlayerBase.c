modded class PlayerBase
{
    bool HasCargoByBaseType(string searched_item, int quant = 1, bool removeHealth = false)
	{        
		array<EntityAI> itemsArray = new array<EntityAI>;
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
        ItemBase item;
        Ammunition_Base magbase; //used for ammo too
        int quantCount = 0;
		int currentItemQuant = quant;
		int i = 0;
		string itemPlayerClassname;
		if(searched_item.Contains("Ammo"))
		{
			for ( i = 0; i < itemsArray.Count(); i++)
			{
				Class.CastTo(magbase, itemsArray.Get(i));

				if (!magbase)
					continue;

				if (magbase.IsRuined())
					continue;
				
				itemPlayerClassname = magbase.GetType();
				itemPlayerClassname.ToLower();
				searched_item.ToLower();

				if(itemPlayerClassname == searched_item)
				{
					if(magbase.GetAmmoCount() >= 1)
						quantCount += magbase.GetAmmoCount();
				}
			}
		}
		else
		{			
			for (i = 0; i < itemsArray.Count(); i++)
			{
				Class.CastTo(item, itemsArray.Get(i));

				if (!item)
					continue;

				if (item.IsRuined())
					continue;
								
				itemPlayerClassname = item.GetType();
				itemPlayerClassname.ToLower();
				searched_item.ToLower();

				if(itemPlayerClassname == searched_item)
				{
					if(item.HasQuantity() && currentItemQuant >= 1)
					{	
						quantCount += item.GetQuantity();
						currentItemQuant -= item.GetQuantity();
					}
					else if(currentItemQuant > 1)
					{
						if(removeHealth)
						{
							int currentHealthlevel = item.GetHealthLevel();
							float currentHealth = 0.0;
							switch(currentHealthlevel)
							{
								case 0: //pristine
								{
									currentHealth = 1.0;
									break;
								}									
								case 1: //worn
								{
									currentHealth = 0.7;
									break;
								}						
								case 2: //damaged
								{
									currentHealth = 0.5;
									break;
								}						
								case 3: //badly dmged
								{
									currentHealth = 0.3;
									break;
								}						
								case 4: //ruined
								{
									currentHealth = 0.0;
									break;
								}
							}
							
							float desiredHealth = currentItemQuant / 100;
							if(currentHealth >= desiredHealth)
							{	
								quantCount += quant;
								break;
							}
							continue;
						}
						currentItemQuant -= 1;
						quantCount += 1;
					}
					else
						return true;
				}
			}
		}

        if(quantCount > 0)
            return quantCount >= quant;
            
		return false;
	}
};