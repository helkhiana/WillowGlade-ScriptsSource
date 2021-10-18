modded class MissionServer
{
	 private ref CraftingMasterConfig m_CraftingMasterConfig;

    void MissionServer()
    {
        GetRPCManager().AddRPC("CraftingMaster", "GetServerCraftingMasterConfig", this, SingeplayerExecutionType.Server);
        GetRPCManager().AddRPC("CraftingMaster", "CraftItemServer", this, SingeplayerExecutionType.Server);
    }

    override void OnInit()
    {
        super.OnInit();
        
        Print("[CraftingMaster] Server Cfg loading...");              
        m_CraftingMasterConfig = new CraftingMasterConfig; 
		g_Game.SetCraftingMasterConfig(m_CraftingMasterConfig);
    }

    void GetServerCraftingMasterConfig(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Server && sender != null)
        {
            Print("[CraftingMaster] MissionServer --> Sending instance of cfg to client: " + sender.GetName());
            GetRPCManager().SendRPC("CraftingMaster", "ClientStoreCraftingMasterConfig", new Param1<CraftingMasterConfig>( m_CraftingMasterConfig ), true, sender);
        }
    }

    void CraftItemServer(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param2<WG_CraftingRecipe, Man> data;
        if (type == CallType.Server && sender != null)
        {
            if (!ctx.Read(data)) return;
            WG_CraftingRecipe recipe = WG_CraftingRecipe.Cast(data.param1);
            PlayerBase player = PlayerBase.Cast(data.param2);
            if ( player.GetIdentity().GetId() == sender.GetId() ) 
                CraftItem(data.param1, player);
        }
    }

    void CraftItem(WG_CraftingRecipe recipe, PlayerBase player)
    {        
        int countItemsRemoved = 0;
        foreach(WG_CraftingRequirementsCollection l_ReqColl : recipe.RequirementsCollections)
        {
			foreach(WG_CraftingRequirements l_reqs : l_ReqColl.Requirements)
			{
	            if(l_reqs.IsSelected())
				{
	                countItemsRemoved += RemoveItem(player, l_reqs.RequiredItemClassName, l_reqs.RequiredQuantity, l_reqs.IsHealthQuantity);
					break;
				}
			}
        }
        if(countItemsRemoved == 0)
            return;
        
		EntityAI object = NULL;
        if(recipe.ResultToInventory)
        	object = player.GetInventory().CreateInInventory(recipe.ItemClassName); //CreateEntityInCargo

        if( !object )
        {
			vector posOfPlayer = player.GetPosition();
            object = EntityAI.Cast(GetGame().CreateObjectEx(recipe.ItemClassName, posOfPlayer, ECE_PLACE_ON_SURFACE));
            if(!object)
            {
                Error("failed to spawn entity "+recipe.ItemClassName+" , make sure the classname exists and item can be spawned");
                return;
            }
        }

        if(recipe.ResultQuantity > 1)
        {
            Ammunition_Base ammo = Ammunition_Base.Cast(object);
            if(ammo)
            {
                ammo.ServerSetAmmoCount(recipe.ResultQuantity);
                return;
            }
            ItemBase item = ItemBase.Cast(object);
            if(item && item.IsQuantityType())
            {    
                item.SetQuantity(recipe.ResultQuantity);
                return;
            }
        }
        for(int i = 0; i < recipe.ResultQuantity - 1; i++) 
        {
            object = null;
            if(recipe.ResultToInventory)
            object = player.GetInventory().CreateInInventory(recipe.ItemClassName); //CreateEntityInCargo

            if( !object )
            {
                object = EntityAI.Cast(GetGame().CreateObjectEx(recipe.ItemClassName, player.GetPosition(), ECE_PLACE_ON_SURFACE));
                if(!object)
                {
                    Error("failed to spawn entity "+recipe.ItemClassName+" , make sure the classname exists and item can be spawned");
                    break;
                }
            }
        }
    };
    
    int RemoveItem(PlayerBase player, string searched_item, int quant = 1, bool removeHealth = false)
	{
		array<EntityAI> itemsArray = new array<EntityAI>;		
		player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
        
        int countItemsRemoved = 0;
        int i = 0;
        string itemPlayerClassname;
        int currentItemQuant;
        if(searched_item.Contains("Ammo"))
		{
            for (i = 0; i < itemsArray.Count(); i++)
            {
                Ammunition_Base ammo;
                Class.CastTo(ammo, itemsArray.Get(i));

                if (!ammo)
                    continue;

                if (ammo.IsRuined())
                    continue;

                itemPlayerClassname = ammo.GetType();
                itemPlayerClassname.ToLower();
                searched_item.ToLower();

                if(itemPlayerClassname == searched_item)
                {                   
                    currentItemQuant = ammo.GetAmmoCount();
                    if(currentItemQuant > quant)
                    {
                        ammo.ServerSetAmmoCount(currentItemQuant - quant);
                        countItemsRemoved++;
                        return countItemsRemoved;
                    }
                    else if(currentItemQuant == quant)
                    {
                        ammo.Delete();
                        countItemsRemoved++;
                        return countItemsRemoved;
                    }
                    else if(currentItemQuant < quant)
                    {
                        ammo.Delete();
                        quant -= currentItemQuant;
                        countItemsRemoved++;
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < itemsArray.Count(); i++)
            {
                ItemBase item;
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
                    if(removeHealth)
                    {
                        item.AddHealth(-quant);
                        countItemsRemoved++;
                        break;
                    }
                    if(item.HasQuantity() && quant >= 1)
                    {                    
                        currentItemQuant = item.GetQuantity();
                        if(currentItemQuant > quant)
                        {
                            item.SetQuantity(currentItemQuant - quant);
                            countItemsRemoved++;
                            return countItemsRemoved;
                        }
                        else if(currentItemQuant == quant)
                        {
                            item.Delete();
                            countItemsRemoved++;
                            return countItemsRemoved;
                        }
                        else if(currentItemQuant < quant)
                        {
                            item.Delete();
                            quant -= currentItemQuant;
                            countItemsRemoved++;
                        }
                    }
					else if(quant > 1)
					{
                        item.Delete();
                        quant -= 1;
                        countItemsRemoved++;
					}
                    else
                    {
                        item.Delete();
                        countItemsRemoved++;
                        break;
                    }
                }
            }
        }
        
        return countItemsRemoved;
	}
};