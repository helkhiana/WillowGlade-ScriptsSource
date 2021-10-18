modded class VicinityItemManager
{
    override void AddVicinityItems( Object object )
	{
		EntityAI inventory_item = EntityAI.Cast( object );
        if(!ShouldAddToVicinity(object))
            return;
		if ( inventory_item )
		{
			if ( m_VicinityItems.Find( inventory_item ) == INDEX_NOT_FOUND && GameInventory.CheckManipulatedObjectsDistances( inventory_item, GetGame().GetPlayer(), VICINITY_CONE_REACH_DISTANCE + 1.0 ) )
			{
				m_VicinityItems.Insert( inventory_item );
			}
		}
	}

    bool ShouldAddToVicinity(Object filtered_object)
    {
        //show if not of right type
        //don't show if right type but error with ids
        //show if right type with right owner
        //don't show if right type without right owner
        if (filtered_object.IsInherited(WG_TraderStorage_Base))
        {
            WG_TraderStorage_Base locker = WG_TraderStorage_Base.Cast(filtered_object);
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if(player.GetWGPlayerId() == -1 || locker.GetWGPlayerId() == -1 )
                return false;
            if(player.GetWGPlayerId() == locker.GetWGPlayerId())
                return true;
            else
                return false;
        }
        return true;
    }
}; 