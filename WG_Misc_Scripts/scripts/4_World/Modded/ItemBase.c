modded class ItemBase
{
	vector Get_ItemPlacingPos()
	{
		if(ConfigIsExisting("itemPlacingPos"))
			return ConfigGetVector("itemPlacingPos");		
		return "0 0 0";
	}

	vector Get_ItemPlacingOrientation()
	{
		if(ConfigIsExisting("itemPlacingOri"))
			return ConfigGetVector("itemPlacingOri");		
		return "0 0 0";
	}
	
	string Get_ItemName()
	{
		if(ConfigIsExisting("kitItemName"))
			return ConfigGetString("kitItemName");
		return GetType().Substring(0,GetType().Length() - 4);
	}

	string Get_KitName()
	{
		if(ConfigIsExisting("kitName"))
			return ConfigGetString("kitName");
		return GetType() + "_Kit";
	}

	bool IsInvEmpty()
	{   
		if (GetNumberOfItems() < 1 &&  GetInventory().AttachmentCount() < 1)
		{
			return true;
		}
		return false;
	}
};