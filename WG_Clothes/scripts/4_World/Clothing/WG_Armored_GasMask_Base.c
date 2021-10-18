class WG_Armored_GasMask_Base extends ClothingBase
{	
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		bool headgear_present = false;
		
		if ( parent.FindAttachmentBySlotName( "Headgear" ) )
		{
			headgear_present = parent.FindAttachmentBySlotName( "Headgear" ).ConfigGetBool( "noMask" );
		}
		
		if ( ( GetNumberOfItems() == 0 || !parent || parent.IsMan() ) && !headgear_present )
		{
			return true;
		}
		return false;
	}
	
	override bool IsObstructingVoice()
	{
		return false;
	}
};

class WG_Armored_GasMask : WG_Armored_GasMask_Base {};
class WG_Armored_GasMask_Graffiti : WG_Armored_GasMask_Base {};