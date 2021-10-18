modded class ActionDeployObject
{
    void SetupAnimation( ItemBase item )
	{
		if ( item.IsHeavyBehaviour() )
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_HEAVY;
		}
		else if ( item.IsOneHandedBehaviour() )
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD; 
		}
		else if ( item.IsTwoHandedBehaviour() )
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
		}
		else
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_PLACING_1HD; 
		}		
	}
};