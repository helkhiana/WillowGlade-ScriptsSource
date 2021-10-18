modded class LogoutMenu extends UIScriptedMenu
{
	override Widget Init()
	{
		layoutRoot = super.Init();		
		m_bLogoutNow = ButtonWidget.Cast( layoutRoot.FindAnyWidget("bLogoutNow") );
		m_bLogoutNow.Show( false );		
		return layoutRoot;
	}
};