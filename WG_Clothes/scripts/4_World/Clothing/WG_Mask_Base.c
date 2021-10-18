class WG_Mask_Base extends ClothingBase
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

class WG_Mask_StylizedWood : WG_Mask_Base {};
class WG_Mask_Knight : WG_Mask_Base {};
class WG_Mask_StylizedAshWood : WG_Mask_Base {};
class WG_Mask_ChineseDemon : WG_Mask_Base {};
class WG_Mask_Pagan : WG_Mask_Base {};
class WG_Mask_PlagueDoctor : WG_Mask_Base {};
class WG_Mask_Clown : WG_Mask_Base {};
class WG_Mask_Ghoul : WG_Mask_Base {};
class WG_Mask_Mummy : WG_Mask_Base {};
class WG_Mask_JapaneseDemon : WG_Mask_Base {};