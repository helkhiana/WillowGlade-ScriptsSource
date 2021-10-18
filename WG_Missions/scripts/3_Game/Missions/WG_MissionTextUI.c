class WG_MissionTextUI extends UIScriptedMenu
{
    private bool                    m_Initialized;
    private bool                    m_IsMenuOpen;
    private ButtonWidget            m_BtnCloseMenu;
	private Widget                  m_ButtonNext;
	private Widget                  m_BtnAccept;
	private Widget                  m_BtnComplete;
	private Widget                  m_BtnGiveIn;
	private Widget                  m_BtnNotYet;
	private TextListboxWidget       m_MissionTextWidget;
	private TextWidget              m_IntroductionTextWidget;
	private TextListboxWidget       m_MissionListWidget;
    private bool                    m_MissionInitiliazed = false;
    private string                  m_CarType;
    private ref WG_Mission          m_Mission;

    void ~WG_MissionTextUI() 
    {
        PPEffects.SetBlurMenu( 0 );
        GetGame().GetUIManager().Back();
        g_Game.GetUIManager().ShowCursor(true);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetMission().GetHud().Show( true );

        if ( layoutRoot )
        	layoutRoot.Unlink();
    }

    override void OnShow()
    {
        super.OnShow();
        PPEffects.SetBlurMenu( 0.2 );
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		GetGame().GetUIManager().ShowCursor(true);
		GetGame().GetMission().GetHud().Show(false);
    }

    override void OnHide()
    {
        super.OnHide();
        PPEffects.SetBlurMenu( 0 );
        g_Game.GetUIManager().ShowCursor(true);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetMission().GetHud().Show( true );
    }

    override Widget Init()
    {
        if (!m_Initialized)
        {
            layoutRoot = GetGame().GetWorkspace().CreateWidgets( "WillowGlade/WG_Events/data/missions/gui/missionlayout.layout" );            	
            m_BtnCloseMenu    = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_UIClose" ) );	
            m_ButtonNext = layoutRoot.FindAnyWidget("NextButton");
            m_BtnAccept = layoutRoot.FindAnyWidget("AcceptButton");
            m_BtnComplete = layoutRoot.FindAnyWidget("CompleteButton");
            m_BtnGiveIn = layoutRoot.FindAnyWidget("GiveInButton");
            m_BtnNotYet = layoutRoot.FindAnyWidget("NotYetButton");
            m_MissionTextWidget = TextListboxWidget.Cast( layoutRoot.FindAnyWidget( "TextBox" ) );
            m_MissionListWidget = TextListboxWidget.Cast( layoutRoot.FindAnyWidget( "ListOfMissions" ) );
            m_IntroductionTextWidget = TextWidget.Cast( layoutRoot.FindAnyWidget( "IntroductionText" ) );
            m_Initialized = true;
        }
        return layoutRoot;
    }

    void SetMission(WG_Mission mission)
    {
        m_Mission = WG_Mission.Cast(mission);        
        m_Mission.ChoosePhase();
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
    	switch(w)
    	{
    		case m_BtnCloseMenu:
                Close();
                break;
    		case m_BtnAccept:
                m_Mission.Accept();
                Close();
                break;
    		case m_BtnComplete:
                m_Mission.Complete();
                Close();
                break;
    		case m_ButtonNext:
                m_Mission.ChoosePhase();
    		    break;
    		case m_BtnGiveIn:
                m_Mission.GiveInPhase();
    		    break;
    		case m_BtnNotYet:
                Close();
    		    break;
    	}
        return super.OnClick(w, x, y, button);
    }

    TextListboxWidget GetMissionListWidget() { return m_MissionListWidget; }
    void MissionListClearItems() { m_MissionListWidget.ClearItems(); }
    void MissionListAddItem(string text, Class userData, int column) { m_MissionListWidget.AddItem(text, userData, column); }
    void MissionListSelectRow(int index) { m_MissionListWidget.SelectRow(index); }
    TextListboxWidget GetMissionTextWidget() { return m_MissionTextWidget; }
    void MissionTextClearItems() { m_MissionTextWidget.ClearItems(); }
    void MissionTextAddItem(string text, Class userData, int column) { m_MissionTextWidget.AddItem(text, userData, column); }
    void MissionTextSelectRow(int index) { m_MissionTextWidget.SelectRow(index); }
    TextWidget GetIntroductionTextWidget() { return m_IntroductionTextWidget; }
    Widget GetAcceptBtn() { return m_BtnAccept; }
    Widget GetCompleteBtn() { return m_BtnComplete; }
    Widget GetNextBtn() { return m_ButtonNext; }
    Widget GetGiveInBtn() { return m_BtnGiveIn; }
    Widget GetNotYetBtn() { return m_BtnNotYet; }

    bool IsMenuOpen() 
    {
        return m_IsMenuOpen;
    }

    void SetMenuOpen(bool isMenuOpen) 
    {
        m_IsMenuOpen = isMenuOpen;
        if (m_IsMenuOpen)
            PPEffects.SetBlurMenu( 0.2 );
        else
            PPEffects.SetBlurMenu( 0 );
    }
};