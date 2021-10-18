modded class GesturesMenu
{
    override void GetGestureItems(out ref array<ref GestureMenuItem> gesture_items, GestureCategories category)
    {
        super.GetGestureItems(gesture_items, category);
        if ( category == GestureCategories.CATEGORIES )
		{
			gesture_items.Insert( new GestureMenuItem( GestureCategories.CATEGORY_5,"Custom",GestureCategories.CATEGORIES ) );
		}

        switch (category)
        {
            case GestureCategories.CATEGORY_5:
            {
                gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_DABBING, "Dab", GestureCategories.CATEGORY_5));
                gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_GIVER, "Put right hand out", GestureCategories.CATEGORY_5));
                gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_GIVEL, "Put left hand out", GestureCategories.CATEGORY_5));
               // gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_SHIVER, "Shiver", GestureCategories.CATEGORY_5));
                //gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_HOT, "Wipe Sweat", GestureCategories.CATEGORY_5));
               // gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_SNEEZE, "Sneeze", GestureCategories.CATEGORY_5));
               // gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_LAUGHTER, "Laugh", GestureCategories.CATEGORY_5));
                //gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_COUGH, "Cough", GestureCategories.CATEGORY_5));
                break;
            }
        }
    }
    
    override void OnMenuRelease()
    {
        super.OnMenuRelease();
    }
};