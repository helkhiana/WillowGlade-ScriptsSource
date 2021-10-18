modded class MissionBase
{
    override UIScriptedMenu CreateScriptedMenu(int id)
    {
        UIScriptedMenu menu = NULL;
        menu = super.CreateScriptedMenu(id);
        if (!menu)
        {
            switch (id)
            {
            case CRAFTING_UI_MENU:
                menu = new CraftingMasterUI;
                break;
            }
            if (menu)
            {
                menu.SetID(id);
            }
        }
        return menu;
    }
};