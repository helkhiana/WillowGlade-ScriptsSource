modded class PlayerContainer
{	
	override bool CheckSlotOfInterest( PlayerBase player, int slotID )
	{
        if(g_Game.GetWorldName() == "chernarusplus") //returning true means it wont colour blue the slots due to being cold
            return true;
        bool returnVal = super.CheckSlotOfInterest(player, slotID);
        return returnVal;
	}
};