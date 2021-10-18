modded class ActionConstructor 
{

    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.RemoveItem(ActionDestroyPart);
        actions.Insert(ActionSearchForScraps);
        actions.Insert(ActionBuyFromVendingMachine);
    }
};