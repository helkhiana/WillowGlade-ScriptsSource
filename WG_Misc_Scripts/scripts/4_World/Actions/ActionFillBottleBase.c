modded class ActionFillBottleBase : ActionContinuousBase
{
	override int GetLiquidType(PlayerBase player, ActionTarget target, ItemBase item)
	{
		m_TargetWet = 0.0;
		if (target.GetObject() && (target.GetObject().IsWell()))
		{
			if (target.GetObject() && target.GetObject().IsInherited(WG_OldKeg))
			{
				if (Liquid.CanFillContainer(item, LIQUID_BEERT))
					return LIQUID_BEERT;
				return -1;
			}
			if (Liquid.CanFillContainer(item, LIQUID_WATER))
				return LIQUID_WATER;
		}
		if (target.GetObject() && target.GetObject().IsFuelStation())
			return LIQUID_GASOLINE;

		vector pos_cursor = target.GetCursorHitPos();
		string surface_type = "";
		GetGame().SurfaceGetType(pos_cursor[0], pos_cursor[2], surface_type);
		switch (surface_type)
		{
			case "nam_seaice":
			case "nam_lakeice_ext":
			case "nam_snow":
			{
				m_TargetWet = 3.0;
				return LIQUID_WATER;
				break;
			}
			case "nam_lakewater_ext":
			{
				m_TargetWet = 2.0;
				return LIQUID_WATER;
				break;
			}
		}
		return GetLiquidTypeOriginal(player, target, item);
	}	

	int GetLiquidTypeOriginal( PlayerBase player, ActionTarget target, ItemBase item )
	{
		vector pos_cursor = target.GetCursorHitPos();		
		CCTWaterSurface waterCheck = new CCTWaterSurface(UAMaxDistances.DEFAULT, UAWaterType.FRESH);
		
		if ( ( waterCheck.Can(player, target) || (target.GetObject() && target.GetObject().IsWell()) ) && Liquid.CanFillContainer(item, LIQUID_WATER ) )
			return LIQUID_WATER;
		else if ( target.GetObject() && target.GetObject().IsFuelStation() && Liquid.CanFillContainer(item, LIQUID_GASOLINE ) )
			return LIQUID_GASOLINE;
		
		return -1;
	}

};