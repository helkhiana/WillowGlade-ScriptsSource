modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        g_Game.SetPF_Config(new PF_Config);
    }
};