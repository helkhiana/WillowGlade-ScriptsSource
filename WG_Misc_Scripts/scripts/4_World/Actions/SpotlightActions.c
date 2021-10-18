modded class ActionTurnOnSpotlight: ActionInteractBase
{
    override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}
};

modded class ActionTurnOffSpotlight: ActionInteractBase
{
    override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}
};