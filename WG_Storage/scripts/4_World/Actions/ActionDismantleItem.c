class ActionDismantleItemWGCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_DECONSTRUCT / 2 );
	}
};

class ActionDismantleItemWG: ActionContinuousBase
{
	void ActionDismantleItemWG()
	{
		m_CallbackClass = ActionDismantleItemWGCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player )
		{
			return "Dismantle";
		}
		
		return "";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject )
		{				
			ItemBase myItem = ItemBase.Cast( targetObject );
			if(myItem){
				if(!myItem.IsInvEmpty()) return false;				
				if (myItem.IsInherited(WG_Item) || myItem.IsInherited(WG_Openable_Base) && !myItem.IsInherited(WG_Openable_Placeable_Base) && !myItem.IsKindOf("WG_BB"))								
					return true;
			}
		}
		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		vector pos = action_data.m_Player.GetPosition();
		string name = "";
		ItemBase myItem = ItemBase.Cast( action_data.m_Target.GetObject() );
		if(myItem)
		{
			name = myItem.Get_KitName();
			myItem.Delete();
		}

		//add damage to tool
		action_data.m_MainItem.DecreaseHealth( 5, false );
		
		//return materials			
		ItemBase.Cast( GetGame().CreateObject(name, pos) );
		return;	
	}
	
}