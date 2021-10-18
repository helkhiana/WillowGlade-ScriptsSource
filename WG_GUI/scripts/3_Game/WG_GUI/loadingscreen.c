ref TStringArray LoadingScreenArray = 
{
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_bearhunting.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_cherno.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_deer.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_guitarart.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_slums.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_sniper.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_trader1.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_trader2.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_ferriswheel.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_party1.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_party2.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_party3.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_party4.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_party5.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_party6.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_party7.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_party8.paa",
    "WillowGlade\\WG_GUI\\imagesets\\loadingscreens\\loadingscreen_party9.paa"
};

ref TStringArray ChernoLoadingScreenArray = 
{
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_1.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_2.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_3.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_4.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_5.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_6.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_7.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_8.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_9.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_cherno_10.paa"
};
ref TStringArray NamalskLoadinScreenArray = 
{
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_1.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_2.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_3.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_4.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_5.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_6.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_7.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_8.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_9.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_namalsk_10.paa"
};
ref TStringArray LivoniaLoadinScreenArray = 
{
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_1.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_2.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_3.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_4.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_5.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_6.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_7.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_8.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_9.paa",
    "WillowGlade\\WG_GUI\\imagesets\\newloadingscreens\\loading_livonia_10.paa"
};

modded class LoadingScreen
{
	float m_UiUpdateTimer = 0;
    void LoadingScreen(DayZGame game)
	{
        if(m_WidgetRoot)
            m_WidgetRoot.Unlink();
        
        m_DayZGame = game;
		m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets("WillowGlade/WG_GUI/gui/layouts/loading_layout.layout");
        
		Class.CastTo(m_ImageLogoMid, m_WidgetRoot.FindAnyWidget("ImageLogoMid"));
		Class.CastTo(m_ImageLogoCorner, m_WidgetRoot.FindAnyWidget("ImageLogoCorner"));
		
		Class.CastTo(m_TextWidgetTitle, m_WidgetRoot.FindAnyWidget("TextWidget"));
		Class.CastTo(m_TextWidgetStatus, m_WidgetRoot.FindAnyWidget("StatusText"));
		Class.CastTo(m_ImageWidgetBackground, m_WidgetRoot.FindAnyWidget("ImageBackground"));
		Class.CastTo(m_ImageLoadingIcon, m_WidgetRoot.FindAnyWidget("ImageLoadingIcon"));
		Class.CastTo(m_ModdedWarning, m_WidgetRoot.FindAnyWidget("ModdedWarning"));
		
		m_ImageBackground = ImageWidget.Cast( m_WidgetRoot.FindAnyWidget("ImageBackground") );
		m_ProgressLoading = ProgressBarWidget.Cast( m_WidgetRoot.FindAnyWidget("LoadingBar") );
		
		string tmp;
		m_ProgressText = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("ProgressText"));
		if (GetGame())
		{
			m_ProgressText.Show( GetGame().CommandlineGetParam("loadingTest", tmp) );
		}
		
		
		m_ModdedWarning.Show(false);
		m_ImageLogoMid.Show(false);
		m_ImageLogoCorner.Show(false);
		
		m_ImageWidgetBackground.Show( true );		
		m_Counter = 0;
				
		game.GetBacklit().LoadingAnim();
		
		ProgressAsync.SetProgressData(m_ProgressLoading);
		ProgressAsync.SetUserData(m_ImageBackground);
	}

    override void Show()
	{				
		string screen;
		string port;
        GetCLIParam("port", port);
		switch (port)
		{
			case "2602":
				screen = ChernoLoadingScreenArray.GetRandomElement();
				break;
			case "2502":
				screen = NamalskLoadinScreenArray.GetRandomElement();
				break;
			case "2702":
				screen = LivoniaLoadinScreenArray.GetRandomElement();
				break;
			
			default:
				screen = ChernoLoadingScreenArray.GetRandomElement();
				break;
		}
		m_ImageWidgetBackground.LoadMaskTexture("WillowGlade/WG_GUI/imagesets/loadingscreens/loadingscreen_mask.paa");
		m_ImageWidgetBackground.LoadImageFile(0, screen); 	
        m_ImageLogoCorner.LoadImageFile(0, "WillowGlade/WG_GUI/imagesets/willowglade_logo.edds");
        m_ImageLogoMid.LoadImageFile(0, "WillowGlade/WG_GUI/imagesets/willowglade_logo.edds");
		m_ModdedWarning.Show(false);
	}
};


modded class LoginTimeBase extends UIScriptedMenu
{
    override Widget Init()
	{	
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("WillowGlade/WG_GUI/gui/layouts/dialog_login_time_layout.layout");
        m_txtDescription = TextWidget.Cast( layoutRoot.FindAnyWidget("txtDescription") );
		m_txtLabel = TextWidget.Cast( layoutRoot.FindAnyWidget("txtLabel") );
		m_btnLeave = ButtonWidget.Cast( layoutRoot.FindAnyWidget("btnLeave") );
		#ifdef PLATFORM_CONSOLE
		m_btnLeave.Show(false);
		layoutRoot.FindAnyWidget("toolbar_bg").Show(true);
		#ifdef PLATFORM_PS4
			string back = "circle";
			if( GetGame().GetInput().GetEnterButton() == GamepadButton.A )
			{
				back = "circle";
			}
			else
			{
				back = "cross";
			}
			ImageWidget toolbar_b = layoutRoot.FindAnyWidget( "BackIcon" );
			toolbar_b.LoadImageFile( 0, "set:playstation_buttons image:" + back );
		#endif
		#endif
		SetBackgroundImage();
		return layoutRoot;    
    }
	
    override void Show()
    {
        super.Show();        
		SetBackgroundImage();
    }

	void SetBackgroundImage()
	{
		if (layoutRoot)
        {
			string screen;
			string port;
			GetCLIParam("port", port);
			switch (port)
			{
				case "2602":
					screen = ChernoLoadingScreenArray.GetRandomElement();
					break;
				case "2502":
					screen = NamalskLoadinScreenArray.GetRandomElement();
					break;
				case "2702":
					screen = LivoniaLoadinScreenArray.GetRandomElement();
					break;
				
				default:
					screen = ChernoLoadingScreenArray.GetRandomElement();
					break;
			}
            ImageWidget background = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background"));
            background.LoadImageFile(0, screen);  
        }
	}
};

modded class LoginQueueBase extends UIScriptedMenu
{
	float m_UiUpdateTimer = 0;
    override Widget Init()
	{	
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("WillowGlade/WG_GUI/gui/layouts/dialog_queue_position_layout.layout");
		
		m_txtPosition = TextWidget.Cast( layoutRoot.FindAnyWidget("txtPosition") );
		m_txtNote = TextWidget.Cast( layoutRoot.FindAnyWidget("txtNote") );
		m_btnLeave = ButtonWidget.Cast( layoutRoot.FindAnyWidget("btnLeave") );
		#ifdef PLATFORM_CONSOLE
		m_btnLeave.Show(false);
		layoutRoot.FindAnyWidget("toolbar_bg").Show(true);
		#ifdef PLATFORM_PS4
			string back = "circle";
			if( GetGame().GetInput().GetEnterButton() == GamepadButton.A )
			{
				back = "circle";
			}
			else
			{
				back = "cross";
			}
			ImageWidget toolbar_b = layoutRoot.FindAnyWidget( "BackIcon" );
			toolbar_b.LoadImageFile( 0, "set:playstation_buttons image:" + back );
		#endif
		#endif
		SetBackgroundImage();
		return layoutRoot;
	}
	
    override void Show()
    {
        super.Show();        
		SetBackgroundImage();
    }

	void SetBackgroundImage()
	{
		if (layoutRoot)
        {
			string screen;
			string port;
			GetCLIParam("port", port);
			switch (port)
			{
				case "2602":
					screen = ChernoLoadingScreenArray.GetRandomElement();
					break;
				case "2502":
					screen = NamalskLoadinScreenArray.GetRandomElement();
					break;
				case "2702":
					screen = LivoniaLoadinScreenArray.GetRandomElement();
					break;
				
				default:
					screen = ChernoLoadingScreenArray.GetRandomElement();
					break;
			}
            ImageWidget background = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background"));
            background.LoadImageFile(0, screen);  
        }
	}
};