class WG_FirewoodHolder_Kit : WG_Kit 
{
    override string Get_ItemName()
	{
		return "WG_FirewoodHolder";
	}
};
class WG_FirewoodHolder : WG_Item 
{	
	bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		}
		
		return false;
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		RefreshVisuals();
	}

	void RefreshVisuals()
	{
		if ( IsItemTypeAttached( Firewood_Log ) )
		{
			SetAnimationPhase( "logs" , 0 );
		}
		else
		{
			SetAnimationPhase( "logs", 1 );
		}	
		if ( IsItemTypeAttached( Firewood ) )
		{
			SetAnimationPhase( "branches" , 0 );
		}
		else
		{
			SetAnimationPhase( "branches", 1 );
		}
	}

	override void EEItemAttached( EntityAI item, string slot_name ) 
	{
		super.EEItemAttached( item, slot_name );

		RefreshVisuals();
	}

	override void EEItemDetached( EntityAI item, string slot_name ) 
	{
		super.EEItemDetached( item, slot_name );

		RefreshVisuals();
	}
};