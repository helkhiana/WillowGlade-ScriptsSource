modded class SeaChest
{
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}	
		if (parent.IsKindOf( "SurvivorBase" ) || parent.IsKindOf( "Clothing_Base" ))
			return false;
		
		return true;
	}
};