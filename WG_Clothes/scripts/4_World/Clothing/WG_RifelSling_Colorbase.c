class WG_RifleSling_Colorbase extends Clothing
{
    override void EEInit()
	{
		super.EEInit();
		ToggleSelection("deployed",0);
		ToggleSelection("rolled",1);
	}

	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		InventoryLocation src_item = new InventoryLocation;
		if (GetInventory().GetCurrentInventoryLocation(src_item))
		{
			InventoryLocationType type = src_item.GetType();
			switch( type )
			{
				case InventoryLocationType.CARGO:
				{
					return false;
				}
				case InventoryLocationType.HANDS:
				{
					return false;
					break;
				}
				case InventoryLocationType.GROUND:
				{
					return false;
					break;
				}
				case InventoryLocationType.PROXYCARGO:
				{
					return false;
					break;
				}
			}
		}
		if (attachment.IsKindOf("RifleCore"))
		{
			return true;
		}
		return false;
	}

	override void EEItemAttached( EntityAI item, string slot_name )
	{
		super.EEItemAttached(item, slot_name);
		ToggleSelection("deployed",1);
		ToggleSelection("rolled",0);
	}

	override void EEItemDetached( EntityAI item, string slot_name )
	{
		super.EEItemDetached(item, slot_name);
		ToggleSelection("rolled",1);
		ToggleSelection("deployed",0);
	}

	override void ToggleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;        
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    }

	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		if(GetInventory().AttachmentCount() > 0)
			return false;
		return true;
	}
	
	override bool CanPutIntoHands (EntityAI parent)
	{
		if( !super.CanPutIntoHands(parent) ) {return false;}
		if(GetInventory().AttachmentCount() > 0)
			return false;
		return true;
	}
};