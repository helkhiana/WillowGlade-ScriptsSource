modded class ActionDismantlePart : ActionContinuousBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		ItemBase theTarget;
		if (super.ActionCondition(player, target, item))
		{
			if (GetGame().IsServer())
			{
				return true;
			}
			if (Class.CastTo(theTarget, target.GetObject()) || Class.CastTo(theTarget, target.GetParent()))
			{
				PlayerBase thePlayer = PlayerBase.Cast(player);
				if (theTarget && thePlayer)
				{
					int curTime = GetGame().GetTime();
					if (vector.Distance(m_LastCheckLocation, theTarget.GetPosition()) > 0.1 || curTime > m_LastCheckLocationNextTime)
					{
						string theGUID = "";
						if (thePlayer.GetIdentity())
						{
							theGUID = thePlayer.GetIdentity().GetId();
						}
						return CanIDismantleHere(theTarget.GetPosition(), theGUID);
					}
					else
					{
						return m_CanDismantleHere;
					}
				}
			}
			return true;
		}
		return false;
	}	
};