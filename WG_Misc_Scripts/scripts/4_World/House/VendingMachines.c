class WG_VendingMachine_Base : BuildingSuper 
{    
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionBuyFromVendingMachine);
    }
};
class WG_VendingMachine_Cans : WG_VendingMachine_Base {};
class WG_VendingMachine_Drinks : WG_VendingMachine_Base {};
class WG_VendingMachine_Snacks : WG_VendingMachine_Base {};