class WG_RedDragon_Katana: Sword
{	
    override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
    {
        super.EEItemLocationChanged(oldLoc, newLoc);
        InventoryLocationType type = newLoc.GetType();
        SetAnimationPhase( "hands" , 0 );
        SetAnimationPhase( "proxy" , 1 );
        switch( type )
        {
            case InventoryLocationType.CARGO:
            {
                SetAnimationPhase( "sheath" , 0 );
			    break;
            }
            case InventoryLocationType.ATTACHMENT:
            {
                SetAnimationPhase( "sheath" , 0 );
                if(newLoc.GetSlot() == -2147146993)
                {
                    SetAnimationPhase( "sheath" , 1 );
                    SetAnimationPhase( "hands" , 1 );
                    SetAnimationPhase( "proxy" , 0 );
                }                
			    break;
            }
            case InventoryLocationType.HANDS:
            {
                SetAnimationPhase( "sheath" , 1 );
			    break;
            }
            case InventoryLocationType.GROUND:
            {
                SetAnimationPhase( "sheath" , 0 );
			    break;
            }
            case InventoryLocationType.PROXYCARGO:
            {
                SetAnimationPhase( "sheath" , 0 );
			    break;
            }
            default:
            {
                SetAnimationPhase( "sheath" , 0 );
            }
        }
    }
};