modded class MissionBase {
    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = NULL;
        menu = super.CreateScriptedMenu(id);
        if (!menu) {
            switch (id) {
            case NOTICE_UI:
                menu = new NoticeUI;
                break;
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }
};