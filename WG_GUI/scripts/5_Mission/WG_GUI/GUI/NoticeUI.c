class NoticeUI extends UIScriptedMenu
{
    private ref array<ref Widget> m_CustomChildrenHighIQ;

    private bool                    m_Initialized;
    private bool                    m_IsMenuOpen;
    private PlayerBase  	        m_Player;
    private ButtonWidget            m_AgreeBtn;
    private ButtonWidget            m_DiscordBtn;
	private TextListboxWidget     m_AgreementTextWidget;
    private string                  m_Link1 = "https://discord.gg/willowglade";

    void ~NoticeUI() 
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
        PPEffects.SetBlurMenu( 1 );
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
            layoutRoot = GetGame().GetWorkspace().CreateWidgets( "WillowGlade/WG_GUI/gui/layouts/notice.layout" );
            
			m_AgreeBtn    = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_Agree" ) );			
			m_DiscordBtn   = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_Discord" ) );			
            m_AgreementTextWidget = TextListboxWidget.Cast( layoutRoot.FindAnyWidget( "AgreementText" ) );
            
            SetAgreementText();
            m_Initialized = true;
        }
        return layoutRoot;
    }

	void SetAgreementText()
	{	
        m_AgreementTextWidget.AddItem("Hello there! Welcome to our server. We are glad you chose to try Willow Glade out.", NULL,  0);
        m_AgreementTextWidget.AddItem("A friendly reminder that this is a FULL PVE NO KOS server.", NULL,  0);
        m_AgreementTextWidget.AddItem("This also means you're not allowed to raid, harrass, bully or interfere with another player.", NULL,  0);
        m_AgreementTextWidget.AddItem("We are all here to make friends and enjoy the game.", NULL,  0);
        m_AgreementTextWidget.AddItem("", NULL,  0);
        m_AgreementTextWidget.AddItem("Please join us on Discord by clicking the button below. We post updates about the server there.", NULL,  0);
        m_AgreementTextWidget.AddItem("Please also read the rules by pressing the PAUSE/BREAK button.", NULL,  0);        
        m_AgreementTextWidget.AddItem("", NULL,  0);
        m_AgreementTextWidget.AddItem("This server is a bit different than others. We have a lot of custom areas, custom loot and items.", NULL,  0);
        m_AgreementTextWidget.AddItem("So you might wanna check out areas you don't usually go to.", NULL,  0);
        m_AgreementTextWidget.AddItem("", NULL,  0);
        m_AgreementTextWidget.AddItem("After clicking 'I understand' button, confirming you understand that this is FULL PVE NO KOS,", NULL,  0);
        m_AgreementTextWidget.AddItem("press left shift + C on your keyboard. This will open a crafting menu for you", NULL,  0);
        m_AgreementTextWidget.AddItem("to get you started with a knife or a shiv.", NULL,  0);
        m_AgreementTextWidget.SelectRow(0);
	}    
    
    override bool OnClick(Widget w, int x, int y, int button)
    {
    	switch(w)
    	{
    		case m_AgreeBtn:
                Close();
                g_Game.AcceptTerms();
    		break;
    		case m_DiscordBtn:
                GetGame().OpenURL( m_Link1 );            
    		break;
    	}
        return super.OnClick(w, x, y, button);
    }

    bool IsMenuOpen() 
    {
        return m_IsMenuOpen;
    }

    void SetMenuOpen(bool isMenuOpen) 
    {
        m_IsMenuOpen = isMenuOpen;
        if (m_IsMenuOpen)
            PPEffects.SetBlurMenu( 1 );
        else
            PPEffects.SetBlurMenu( 0 );
    }

};