modded class ActionPlaceFBFCampfireIndoor: ActionSingleUseBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target ) return false;
		if ( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;

		Object target_object = target.GetObject();
		string action_selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		BuildingWithFireplace building = BuildingWithFireplace.Cast( target_object );
		vector fire_point_pos_world, fire_point_rot_world;
		float rot_deg = 0.0;
		if ( target_object && building && action_selection.Contains( FBF_FireplaceIndoor.FIREPOINT_ACTION_SELECTION ) )
		{
			int fire_point_index = FBF_FireplaceIndoor.GetFirePointIndex( action_selection );
			if ( FBF_FireplaceIndoor.CanPlaceFireplaceInSelectedSpot( building, fire_point_index, fire_point_pos_world, fire_point_rot_world ) )
			{
				if ( building.HasSelection( FBF_FireplaceIndoor.FIREPOINT_PLACE_ROT + fire_point_index.ToString() ) )
				{
					vector diff = fire_point_rot_world - fire_point_pos_world;
					diff[1] = 0.0;
					diff.Normalize();
					float dotp = vector.Dot( "0 0 1" , diff );
					rot_deg = Math.Acos( dotp ) * Math.RAD2DEG;
					if ( ( diff[0] < 0 ) && ( diff[2] < 0 ) )
						rot_deg = 360.0 - rot_deg;
					else if ( ( diff[0] < 0 ) && ( diff[2] > 0 ) )
						rot_deg = 360.0 - rot_deg;

					//Debug.DrawArrow( fire_point_pos_world, fire_point_pos_world + diff );
				}
				
				float fire_point_dist = vector.Distance( fire_point_pos_world, player.GetPosition() );
				if ( fire_point_dist <= 2 )
				{
					player.SetLastFirePoint( fire_point_pos_world );
					player.SetLastFirePointIndex( fire_point_index );
					player.SetLastFirePointRot( rot_deg );
					return true;
				}
			}
		}	
		
		Msp_BuildingWithFireplace buildingwithfireplace = Msp_BuildingWithFireplace.Cast( target_object );
		if ( target_object && buildingwithfireplace && action_selection.Contains( FBF_FireplaceIndoor.FIREPOINT_ACTION_SELECTION ) )
		{
			int fire_point_index_msp = FBF_FireplaceIndoor.GetFirePointIndex( action_selection );
			if ( FBF_FireplaceIndoor.CanPlaceFireplaceInSelectedSpot( buildingwithfireplace, fire_point_index_msp, fire_point_pos_world, fire_point_rot_world ) )
			{
				if ( buildingwithfireplace.HasSelection( FBF_FireplaceIndoor.FIREPOINT_PLACE_ROT + fire_point_index_msp.ToString() ) )
				{
					vector diff_msp = fire_point_rot_world - fire_point_pos_world;
					diff_msp[1] = 0.0;
					diff_msp.Normalize();
					float dotp2 = vector.Dot( "0 0 1" , diff_msp );
					rot_deg = Math.Acos( dotp2 ) * Math.RAD2DEG;
					if ( ( diff_msp[0] < 0 ) && ( diff_msp[2] < 0 ) )
						rot_deg = 360.0 - rot_deg;
					else if ( ( diff_msp[0] < 0 ) && ( diff_msp[2] > 0 ) )
						rot_deg = 360.0 - rot_deg;
				}
				
				if ( vector.Distance( fire_point_pos_world, player.GetPosition() ) <= 2 )
				{
					player.SetLastFirePoint( fire_point_pos_world );
					player.SetLastFirePointIndex( fire_point_index );
					player.SetLastFirePointRot( rot_deg );
					return true;
				}
			}
		}


		
		return false;
	}
};