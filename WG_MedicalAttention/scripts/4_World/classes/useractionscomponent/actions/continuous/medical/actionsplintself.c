modded class ActionSplintSelf: ActionContinuousBase	
{
	override void OnFinishProgressServer( ActionData action_data )
	{	
		if(action_data.m_Player.m_BrokenArms)
		{			
			action_data.m_MainItem.TransferModifiers(action_data.m_Player);
			action_data.m_Player.ApplySplint();
			action_data.m_MainItem.Delete();
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
		else
		{
			super.OnFinishProgressServer(action_data);
		}
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.m_BrokenArms && !player.GetModifiersManager().IsModifierActive(eModifiers.MDF_BONE_REGEN))
		{
			return true;
		}
		return super.ActionCondition(player, target, item);	
	}
};