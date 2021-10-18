modded class MissionBase {
    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = NULL;
        menu = super.CreateScriptedMenu(id);
        if (!menu) {
            switch (id) {
            case MISSIONTEXT_UI:
                menu = new WG_MissionTextUI;
                break;
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }
    
    override void OnKeyPress(int key) {
        WG_MissionTextUI menu;
        
        if (key == KeyCode.KC_ESCAPE) {
            menu = WG_MissionTextUI.Cast(GetGame().GetUIManager().GetMenu());

            if (menu) {
                menu.Close();
                return;
            }
        }
        super.OnKeyPress(key);
    }
};