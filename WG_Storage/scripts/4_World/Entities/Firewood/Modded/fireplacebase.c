 modded class FireplaceBase extends ItemBase
{
	//Attachment types
	typename ATTACHMENT_FIREWOOD_LOG = Firewood_Log;
	protected void FireplaceBase()
	{
		//STATIC: define kindling types
		if ( !m_FireConsumableTypes )
		{
			m_FireConsumableTypes = new ref map<typename, ref FireConsumableType>;
			m_FireConsumableTypes.Insert( ATTACHMENT_RAGS, 			new FireConsumableType( ATTACHMENT_RAGS, 		14, 	true,	"Rags" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_BANDAGE, 		new FireConsumableType( ATTACHMENT_BANDAGE, 	14, 	true,	"MedicalBandage" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_BOOK, 			new FireConsumableType( ATTACHMENT_BOOK, 		36, 	true,	"Book" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_BARK_OAK, 		new FireConsumableType( ATTACHMENT_BARK_OAK, 	20, 	true,	"OakBark" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_BARK_BIRCH, 	new FireConsumableType( ATTACHMENT_BARK_BIRCH, 	14, 	true,	"BirchBark" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_PAPER, 		new FireConsumableType( ATTACHMENT_PAPER, 		10, 	true,	"Paper" ) );
			
			//define fuel types
			m_FireConsumableTypes.Insert( ATTACHMENT_STICKS, 		new FireConsumableType( ATTACHMENT_STICKS, 		40, 	false,	"WoodenStick" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_FIREWOOD, 		new FireConsumableType( ATTACHMENT_FIREWOOD, 	100, 	false,	"Firewood" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_FIREWOOD_LOG, 		new FireConsumableType( ATTACHMENT_FIREWOOD_LOG, 	200, 	false,	"Firewood_Log" ) );
		}
		else
		{
			m_FireConsumableTypes.Insert( ATTACHMENT_FIREWOOD_LOG, 		new FireConsumableType( ATTACHMENT_FIREWOOD_LOG, 	200, 	false,	"Firewood_Log" ) );
		}		

		//calculate total energy
		CalcAndSetTotalEnergy();
	}
/*
	override void RefreshFireplaceVisuals()
	{		
		if ( IsHologram() )
		{
			return;
		}
		
		// Light
		if ( IsBurning() ) 
		{
			//turn light on
			if ( !GetLightEntity()  &&  ( GetGame().IsClient() || !GetGame().IsMultiplayer() ) )
			{
				SetLightEntity( FireplaceLight.Cast( ScriptedLightBase.CreateLight(FireplaceLight, GetPosition(), 20) ) );
				GetLightEntity().AttachOnMemoryPoint(this, "light");
			}
			
			if (GetLightEntity())
			{
				// The following solves an issue with the light point clipping through narrow geometry
				
				if ( IsItemTypeAttached ( ATTACHMENT_STONES )  ||  IsBarrelWithHoles()  ||  IsFireplaceIndoor() )
				{
					GetLightEntity().SetInteriorMode();
				}
				else
				{
					GetLightEntity().SetExteriorMode();
				}
			}
		}
		else
		{
			//turn light off
			if (GetLightEntity())
			{
				GetLightEntity().FadeOut();
			}
		}
		
		//set default burn parameters based on fireplace type
		if ( IsBarrelWithHoles() || IsFireplaceIndoor() )
		{
			SetFuelBurnRateMP( FUEL_BURN_RATE_OVEN );
			SetTemperatureLossMP( TEMPERATURE_LOSS_MP_OVEN );
		}
		else
		{
			SetFuelBurnRateMP( FUEL_BURN_RATE_DEFAULT );
			SetTemperatureLossMP( TEMPERATURE_LOSS_MP_DEFAULT );			
		}
		
		//VISUAL STATES
		//Fuel state
		if ( IsItemTypeAttached( ATTACHMENT_STICKS ) )
		{
			SetAnimationPhase( ANIMATION_STICKS, 0 );
		}
		else
		{
			SetAnimationPhase( ANIMATION_STICKS, 1 );
		}
		
		//Firewood state
		if ( IsItemTypeAttached( ATTACHMENT_FIREWOOD ) || IsItemTypeAttached( ATTACHMENT_FIREWOOD_LOG ))
		{
			if ( IsInAnimPhase( ANIMATION_BURNT_WOOD ) )
			{
				SetAnimationPhase( ANIMATION_WOOD, 1 );
			}
			else
			{
				SetAnimationPhase( ANIMATION_WOOD, 0 );
			}
		}
		else
		{
			SetAnimationPhase( ANIMATION_WOOD, 1 );
			SetAnimationPhase( ANIMATION_BURNT_WOOD, 1 );		
		}	
			
		//Kindling state
		if ( GetKindlingCount() == 0 )
		{
			SetAnimationPhase( ANIMATION_KINDLING, 1 );
		}
		else
		{
			SetAnimationPhase( ANIMATION_KINDLING, 0 );
		}

		//Ashes state
		if ( HasAshes() )
		{
			SetAnimationPhase( ANIMATION_ASHES, 0 );
		}
		else
		{
			SetAnimationPhase( ANIMATION_ASHES, 1 );
		}
		
		//Oven state (+set burn parameters)
		if ( IsOven() )
		{
			SetAnimationPhase( ANIMATION_OVEN, 0 );
			
			//set burn parameters
			SetFuelBurnRateMP( FUEL_BURN_RATE_OVEN );
			SetTemperatureLossMP( TEMPERATURE_LOSS_MP_OVEN );
		}
		else
		{
			SetAnimationPhase( ANIMATION_OVEN, 1 );
		}
		
		//Stones state (+set burn parameters)
		if ( IsItemTypeAttached ( ATTACHMENT_STONES ) )
		{
			ItemBase attached_item = ItemBase.Cast( GetAttachmentByType( ATTACHMENT_STONES ) );
			float item_quantity = attached_item.GetQuantity();
		
			//show stones
			if ( item_quantity >= 8 && !IsOven() )
			{
				SetAnimationPhase( ANIMATION_STONES, 0 );
				
				//set burn parameters
				SetFuelBurnRateMP( FUEL_BURN_RATE_STONES );
				SetTemperatureLossMP( TEMPERATURE_LOSS_MP_STONES );				
			}
			else
			{
				SetAnimationPhase( ANIMATION_STONES, 1 );
			}
		}
		else
		{
			SetAnimationPhase( ANIMATION_STONES, 1 );
		}
		
		//Tripod state
		if ( IsItemTypeAttached( ATTACHMENT_TRIPOD ) )
		{
			SetAnimationPhase( ANIMATION_TRIPOD, 0 );
		}
		else
		{
			SetAnimationPhase( ANIMATION_TRIPOD, 1 );
		}
		
		//refresh physics (with delay)
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( RefreshFireplacePhysics );
	}
	*/
};