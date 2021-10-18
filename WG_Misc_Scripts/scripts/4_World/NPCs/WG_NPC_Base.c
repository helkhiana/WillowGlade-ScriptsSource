class WG_NPC_Base : PlayerBase
{    
    void WG_NPC_Base()
    {
        if ( GetGame().IsServer() )
        {
            SetAllowDamage(false);
            GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Loadout, 500 );
        }
    }
    
/* 	override void InitializeActions()
	{
        m_InputActionMapAsTarget = new TInputActionMap;
		m_InputActionMapControled = new TInputActionMap;
		SetActions(m_InputActionMapControled);
		SetActionsRemoteTarget(m_InputActionMapAsTarget);
	} */

	override bool CanBeRestrained()
	{
		return false;
	}

    void Loadout()
    {
    }

	override bool IsInventoryVisible()
	{
		return false;
	}

	override bool CanDisplayCargo()
	{
		return false;
	}
    
	override bool CanBeTargetedByAI( EntityAI ai )
	{
		return false;
	}
};

class WG_NPC_Test_Francis : WG_NPC_Base
{ 
    ItemBase pants;
    override void Loadout()
    {
		
		SetAllowDamage(true);
        pants = ItemBase.Cast(GetInventory().CreateInInventory("Kneepads_Jeans_Base"));
        pants.SetHealth("","Health", 30);
        GetInventory().CreateInInventory("Shemagh_Scarf_Blue");
        GetInventory().CreateInInventory("Sweater_Green");
        GetInventory().CreateInInventory("Sneakers_Black");
        GetInventory().CreateInInventory("Canvas_Backpack_Blue");
        //GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( DropPants, 30000 );
    }
    
    void DropPants()
    {
        Print(pants);
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove(DropPants);
        DropItem(pants);
    }

	override bool IsInventoryVisible()
	{
		return true;
	}

    override string GetPlayerName()
    {
        return "Francis";
    };
};