modded class MissionGameplay 
{
    private ref CraftingMasterUI m_craftingMenu;

    
	void MissionGameplay()
	{
		GetRPCManager().AddRPC("CraftingMaster", "ClientStoreCraftingMasterConfig", this, SingeplayerExecutionType.Client);
		GetRPCManager().SendRPC("CraftingMaster", "GetServerCraftingMasterConfig", null, true, null);
	}

	void ClientStoreCraftingMasterConfig(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param1<CraftingMasterConfig> data;
        if (type == CallType.Client)
		{
			if (!ctx.Read(data)) return;

			g_Game.SetCraftingMasterConfig( data.param1 );
			Print("[CraftingMaster] MissionGameplay --> Got instance of cfg: " + data.param1);
		}
    }

    override void OnUpdate(float timeslice) {
        super.OnUpdate(timeslice);
        
		PlayerBase playerPB = PlayerBase.Cast( GetGame().GetPlayer() );
        if(playerPB && !playerPB.IsAlive() && m_craftingMenu)
        {
            m_craftingMenu.SetMenuOpen(false);
            GetGame().GetUIManager().HideScriptedMenu(m_craftingMenu);
            delete m_craftingMenu;
            m_craftingMenu = NULL;
            return;
        }

        Input input = GetGame().GetInput();
        if (input.LocalPress("UAUIBack", false)) 
        {
            if (m_craftingMenu != NULL && GetGame().GetUIManager().GetMenu() == m_craftingMenu) {
                m_craftingMenu.SetMenuOpen(false);
                GetGame().GetUIManager().HideScriptedMenu(m_craftingMenu);
                UnlockControls();
            }
        }

        if ( input.LocalPress("UAOpenCraftingMenu", false) ) 
        {
            if ( m_craftingMenu ) {
                if (m_craftingMenu.IsMenuOpen()) {
                    //Hide Menu
                    m_craftingMenu.SetMenuOpen(false);
                    GetGame().GetUIManager().HideScriptedMenu(m_craftingMenu);
                    UnlockControls();
                } else if (GetGame().GetUIManager().GetMenu() == NULL) {
                    //Show Menu
                    GetGame().GetUIManager().ShowScriptedMenu(m_craftingMenu, NULL);
                    m_craftingMenu.SetMenuOpen(true);
                    LockControls();
                }
            } else if (GetGame().GetUIManager().GetMenu() == NULL && m_craftingMenu == null) {
                //Create Menu
                LockControls();
                m_craftingMenu = CraftingMasterUI.Cast(GetUIManager().EnterScriptedMenu(CRAFTING_UI_MENU, null));
                m_craftingMenu.SetMenuOpen(true);
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