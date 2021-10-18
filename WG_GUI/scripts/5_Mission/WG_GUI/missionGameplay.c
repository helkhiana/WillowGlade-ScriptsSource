modded class MissionGameplay 
{
    private ref NoticeUI m_NoticeUI;

    void ~MissionGameplay()
    {
        delete m_NoticeUI;
    }

    override void OnMissionStart()
    {
        super.OnMissionStart();
        g_Game.LoadWillowGladeClientData();
        if (!g_Game.HasAcceptedTerms())
            GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(CreateNoticeMenu, 500, true);
    }

    void CreateNoticeMenu() 
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && player.IsPlayerLoaded())
        {
            if (GetGame().GetUIManager().GetMenu() == NULL && m_NoticeUI == null) 
            {
                LockControls();
                m_NoticeUI = NoticeUI.Cast(GetUIManager().EnterScriptedMenu(NOTICE_UI, null));
                GetGame().GetUIManager().ShowScriptedMenu(m_NoticeUI, NULL);
                m_NoticeUI.SetMenuOpen(true);
                GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(CreateNoticeMenu);
            }
        }
    }

    private void LockControls()
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowUICursor( true );
        GetGame().GetMission().GetHud().Show( false );
    }

    private void UnlockControls()
    {
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetUIManager().ShowUICursor( false );
        GetGame().GetMission().GetHud().Show( true );
    }
};