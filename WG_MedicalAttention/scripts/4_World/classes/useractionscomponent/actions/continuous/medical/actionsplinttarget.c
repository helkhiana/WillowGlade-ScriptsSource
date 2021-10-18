modded class ActionSplintTarget: ActionContinuousBase
{
	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase mtarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		if(mtarget.m_BrokenArms)
		{			
			action_data.m_MainItem.TransferModifiers(mtarget);
			mtarget.ApplySplint();
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
		PlayerBase ntarget = PlayerBase.Cast( target.GetObject() );
		if (ntarget.m_BrokenArms && !ntarget.GetModifiersManager().IsModifierActive(eModifiers.MDF_BONE_REGEN))
		{
			return true;
		}
		return super.ActionCondition(player, target, item);
	
	}
};