modded class InspectMenuNew
{
	override static void UpdateItemInfoLiquidType(Widget root_widget, EntityAI item)
	{
		if ( item.IsInherited( ZombieBase ) || item.IsInherited( Car ) ) return;
		
		ItemBase item_base = ItemBase.Cast( item );
		
		if( item_base && item_base.GetQuantity() > 0 && item_base.IsBloodContainer() )
		{
			BloodContainerBase blood_container = BloodContainerBase.Cast( item_base );
			
			if( blood_container.GetBloodTypeVisible() )
			{
				string type;
				bool positive;
				string blood_type_name = BloodTypes.GetBloodTypeName(blood_container.GetLiquidType(), type, positive);
				WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_blood: " + blood_type_name, Colors.COLOR_LIQUID);
			}
			else
			{
				WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_blood", Colors.COLOR_LIQUID);
			}
		}
		else if( item_base && item_base.GetQuantity() > 0 && item_base.IsLiquidContainer() )
		{
			int liquid_type = item_base.GetLiquidType();
			
			switch(liquid_type)
			{
				#ifdef NAMALSK_SURVIVAL					
				case LIQUID_WATER:
				{
					if (item_base.GetWet() < 1)
						WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#nam_inv_ins_water", Colors.COLOR_LIQUID);
					else if ((item_base.GetWet() >=1) && (item_base.GetWet() < 2))
						WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#nam_inv_ins_cwater", Colors.COLOR_LIQUID);
					else
						WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#nam_inv_ins_ice", Colors.COLOR_LIQUID);
					break;
				}
					
				case LIQUID_RIVERWATER:
				{
					if (item_base.GetWet() < 1)
						WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#nam_inv_ins_water", Colors.COLOR_LIQUID);
					else if ((item_base.GetWet() >=1) && (item_base.GetWet() < 2))
						WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#nam_inv_ins_cwater", Colors.COLOR_LIQUID);
					else
						WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#nam_inv_ins_ice", Colors.COLOR_LIQUID);
					break;
				}
				#endif

				case LIQUID_WATER:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_water", Colors.COLOR_LIQUID);
					break;
				}
					
				case LIQUID_RIVERWATER:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_river_water", Colors.COLOR_LIQUID);
					break;
				}
					
				case LIQUID_VODKA:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_vodka", Colors.GRAY);
					break;
				}
				
				case LIQUID_BEER:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_beer", Colors.BROWN);
					break;
				}
				
				case LIQUID_GASOLINE:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_gasoline", Colors.COLOR_LIQUID);
					break;
				}
				
				case LIQUID_DIESEL:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_diesel", Colors.COLOR_LIQUID);
					break;
				}
				
				case LIQUID_DISINFECTANT:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_disinfectant", Colors.COLOR_LIQUID);
					break;
				}
	
				case LIQUID_SALINE:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "#inv_inspect_saline", Colors.COLOR_LIQUID);
					break;
				}
	
				case LIQUID_MILK:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "MILK", Colors.WHITE);
					break;
				}
				
				case LIQUID_WINE:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "WINE", Colors.WINE);
					break;
				}

				case LIQUID_BEERT:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "BEER", Colors.BROWN);
					break;
				}

				case LIQUID_WHISKEY:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "WHISKEY", Colors.WHISKEY);
					break;
				}

				case LIQUID_MOONSHINE:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "WHISKEY", Colors.WHISKEY);
					break;
				}
				
				default:
				{
					WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "ERROR", Colors.COLOR_LIQUID);
					break;
				}
			}
		}
		else
		{
			WidgetTrySetText(root_widget, "ItemLiquidTypeWidget", "");
		}
	}
};