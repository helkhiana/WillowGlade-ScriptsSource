modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        g_Game.SetWG_LS_Config(new WG_LS_Config);
    }
};