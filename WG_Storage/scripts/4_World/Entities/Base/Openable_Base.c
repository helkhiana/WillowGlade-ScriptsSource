class WG_Openable_Base : Container_Base
{
	protected ref OpenableBehaviour m_Openable;
	
	void WG_Openable_Base()
	{
		m_Openable = new OpenableBehaviour(false);
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	
	override void EEInit()
	{
		super.EEInit();		
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);  
	}

	override void Open()
	{
		m_Openable.Open();
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override void Close()
	{
		m_Openable.Close();
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}

	void UpdateVisualState()
    {
        if ( IsOpen() )
        {
            SetAnimationPhase("Doors1",1);
        }
        else
        {
            SetAnimationPhase("Doors1",0);
        }
    }

    override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }
    override bool CanPutIntoHands( EntityAI parent )
    {
        return false;
    }
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return IsOpen();
	}
	
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}

	override bool CanDisplayAttachmentSlot(string slot_name)
	{		
		return true;
	}

	override void SetActions()
	{
		super.SetActions();
        AddAction(ActionCustomOpen);
        AddAction(ActionCustomClose);
	}
};

class WG_Openable_Placeable_Base: WG_Openable_Base 
{   
	override bool CanPutInCargo( EntityAI parent )
    {
        return IsInvEmpty() && !IsOpen();
    }
    
     override bool CanPutIntoHands(EntityAI parent)
	{
		return IsInvEmpty() && !IsOpen();
    }

    override bool IsDeployable() 
    {
        return true;
    } 
    
    override void OnInventoryEnter(Man player)
    {
        super.OnInventoryEnter(player);
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);        
    }
    
    override void OnInventoryExit(Man player)
    {
        super.OnInventoryExit(player);
        if(IsOpen())
            GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);        
    }

    override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};