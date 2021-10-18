class WG_NPC_Missions : WG_NPC_Base
{ 
    int GetMissionType()
    {
        return -1;
    }
};

class WG_NPC_Valya : WG_NPC_Missions
{ 
    private int emoteTimer = 0;
    override void Loadout()
    {
        GetInventory().CreateInInventory("Medium_Sleeves_Shirt_Mechanic");
        GetInventory().CreateInInventory("Kneepads_Jeans_Base");
        GetInventory().CreateInInventory("Ragged_Eyepatch");
        GetInventory().CreateInInventory("Fingerless_Gloves");
        GetInventory().CreateInInventory("Sneakers_Black");
        GetInventory().CreateInInventory("WG_DuffleBag_Green");
        GetEmoteManager().PlayEmote(EmoteConstants.ID_EMOTE_WATCHING);
    }

    override void SetActionsRemoteTarget( out TInputActionMap InputActionMap)
	{
        super.SetActionsRemoteTarget(InputActionMap);
		AddAction(ActionInteractMissionNPC, InputActionMap);
    }

//not working
 /* override void OnScheduledTick(float deltaTime)
	{
        super.OnScheduledTick(deltaTime);
        emoteTimer += deltaTime;
        if(emoteTimer > 30)
        {
            if(GetEmoteManager().IsEmotePlaying())
                GetEmoteManager().CancelEmote();
            int rndInt = Math.RandomIntInclusive(1,16);
            GetEmoteManager().PlayEmote(rndInt);
            emoteTimer = 0;
        }
    }*/
    
    override int GetMissionType()
    {
        return WG_Mission_Type.Vehicle;
    }

    override string GetPlayerName()
    {
        return "Valya";
    };
};