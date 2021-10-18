modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(ActionHealTarget);
        actions.Insert(ActionHealSelf);
        actions.Insert(ActionTreatBrokenLimbsTarget);
        actions.Insert(ActionTreatBrokenLimbsSelf);
    }
};