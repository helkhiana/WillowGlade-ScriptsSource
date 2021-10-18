class MMO_CemeteryFence_DoubleGate_Event : Building
{
    void StartEventRegister(int doorIndex)
    {        
    }
};

class MMO_CemeteryFence_DoubleGate_RegisterArea : MMO_CemeteryFence_DoubleGate_Event
{
    override void StartEventRegister(int doorIndex)
    {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(StartEventRegister);
        g_Game.RegisterHalloweenEvent(this, doorIndex);
    }
};

class MMO_CemeteryFence_DoubleGate_EventStart : MMO_CemeteryFence_DoubleGate {};

class MMO_CemeteryFence_DoubleGate: Building 
{
    void RegularClose(int doorIndex)
    {        
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(RegularClose);
        CloseDoor(doorIndex);
    }
};