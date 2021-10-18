modded class ChatCommandManager
{
    override void OnInit()
    {
        super.OnInit();
        AddChatCommand(new StartHalloweenAdminEventCmd("/starthalloweenevent", 1, "Chat:starthalloweenevent")); //ChatCommand constructor params: string command, int argsCount, string permission, bool playerArgs = false
        AddChatCommand(new EndHalloweenAdminEventCmd("/endhalloweenevent", 0, "Chat:endhalloweenevent")); //ChatCommand constructor params: string command, int argsCount, string permission, bool playerArgs = false
    }
};

class StartHalloweenAdminEventCmd: ChatCommand
{
    override void ExecuteCommand(PlayerBase caller, array<Man> targets, array<string> args)
    {
        if( caller )
        {
            g_Game.RegisterHalloweenEventAdmin();
        }
    }
};

class EndHalloweenAdminEventCmd: ChatCommand
{
    override void ExecuteCommand(PlayerBase caller, array<Man> targets, array<string> args)
    {
        if( caller )
        {
            g_Game.StopHalloweenEvent();
        }
    }
};

modded class PermissionManager
{
    void PermissionManager()
    {
        AddPermissionType({"Chat:starthalloweenevent"});
        AddPermissionType({"Chat:endhalloweenevent"});
    }
};