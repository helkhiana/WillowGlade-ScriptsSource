class RequiredItems
{
    ItemBase                    m_ItemBasePreview;
    Widget                      m_Panel;
    ItemPreviewWidget           m_PreviewWidget;
    TextWidget                  m_NameWidget;
    TextWidget                  m_QuantityWidget;
    XComboBoxWidget             m_ReqItemsComboWidget;
    int                         m_CurrentReqItemIndex;
};

class CraftingMasterUI extends UIScriptedMenu
{
	private int                 m_characterScaleDelta;
    private bool                m_Initialized;
    private bool                m_IsMenuOpen;
	private int                 m_LastRowIndex = -1;
	private int                 m_LastCategoryCurrentIndex = -1;
	private float               m_UiUpdateTimer = 0;
    private string              m_SearchFilter = "";
    private string              m_OldSearchFilter = "";
    private int                 m_PreviewWidgetRotationX;
	private int                 m_PreviewWidgetRotationY;
	private vector              m_PreviewWidgetOrientation;
    private PlayerBase  	    m_Player;
    private bool                m_CanCraft;

    private ButtonWidget        m_BtnCloseMenu;
    private ButtonWidget		m_BtnCraft;
    private EditBoxWidget		m_SearchBox; 
    
    private ItemBase            m_RecipePreview0;
	private ItemPreviewWidget   m_RecipePreviewWidget;
	private Widget              m_RecipePreviewPanel;
    private TextListboxWidget	m_RecipeListWidget;

	MultilineTextWidget         m_ItemDescription;
	TextWidget                  m_ItemResultQuantity;
    
	ref array<ref WG_CraftingRecipe> m_RecipesList;
	ref array<ref RequiredItems> m_RequiredItemsList;
	ref array<ref WG_CraftingRecipe> m_FilteredRecipesLists;
    
    void CraftingMasterUI() 
    {
        m_Player = PlayerBase.Cast(GetGame().GetPlayer());
    }

    void ~CraftingMasterUI() 
    {
        ResetMenu();

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
        RefreshScreen(true);
        PPEffects.SetBlurMenu( 0.2 );
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
            layoutRoot = GetGame().GetWorkspace().CreateWidgets( "WillowGlade/WG_Crafting/gui/Layouts/CraftingUI.layout" );
            
			m_BtnCloseMenu    = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_UIClose" ) );
			m_BtnCraft    = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_Craft" ) );
			m_SearchBox    = EditBoxWidget.Cast( layoutRoot.FindAnyWidget( "SearchBox" ) );
            m_RecipeListWidget = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("RecipesList"));
            m_ItemDescription = MultilineTextWidget.Cast( layoutRoot.FindAnyWidget( "PreviewDescription" ) );
            m_ItemResultQuantity = TextWidget.Cast( layoutRoot.FindAnyWidget( "ResultQuantity" ) );
            m_RecipePreviewPanel = layoutRoot.FindAnyWidget("PreviewBody");
            m_RequiredItemsList = new array<ref RequiredItems>;
            RequiredItems req;
            for(int i = 0; i < 9; i++)
            {
                req = new RequiredItems;
                req.m_Panel = layoutRoot.FindAnyWidget("reqFrame" + i);
                req.m_QuantityWidget = TextWidget.Cast(layoutRoot.FindAnyWidget("reqQuant" + i));
                req.m_ReqItemsComboWidget = XComboBoxWidget.Cast(layoutRoot.FindAnyWidget("reqCombo" + i));
                m_RequiredItemsList.Insert(req);
            }

            CreatePreviewWidgets();
            
            m_BtnCraft.Enable(false);
            m_Initialized = true;
            m_RecipesList = g_Game.GetCraftingRecipes();

            m_FilteredRecipesLists = new array<ref WG_CraftingRecipe>;     

		    UpdateRecipeList();	
            m_RecipeListWidget.SelectRow(0);
        }
        return layoutRoot;
    }
    
    //create preview widgets within their panel as preparation
    void CreatePreviewWidgets()
    {        
        CreatePreviewWidget(m_RecipePreviewPanel, m_RecipePreviewWidget);
        foreach(RequiredItems reqItem : m_RequiredItemsList)
        {
            CreatePreviewWidget(reqItem.m_Panel, reqItem.m_PreviewWidget);
        }
    }
    
    void CreatePreviewWidget(Widget preview_frame, out ItemPreviewWidget previewWidget)
    {
        if ( preview_frame ) 
        {
            float width;
            float height;
            preview_frame.GetSize(width, height);

            previewWidget = ItemPreviewWidget.Cast( GetGame().GetWorkspace().CreateWidget(ItemPreviewWidgetTypeID, 0, 0, 1, 1, WidgetFlags.VISIBLE, ARGB(255, 255, 255, 255), 10, preview_frame) );
        }
    }
    
	void UpdateRecipeList()
	{	
		m_RecipeListWidget.ClearItems();
        m_FilteredRecipesLists.Clear();
        string displayName = "";
        foreach(WG_CraftingRecipe recipe : m_RecipesList)
        {
            if(m_SearchFilter && m_SearchFilter != string.Empty)
            {                
                displayName = getItemDisplayName(recipe.ItemClassName);
                string low_DisplayName = displayName;
                low_DisplayName.ToLower();
                string low_m_SearchFilter = m_SearchFilter;
                low_m_SearchFilter.ToLower();
                if(low_DisplayName.Contains(low_m_SearchFilter))
                {
                    m_FilteredRecipesLists.Insert(recipe);
                    m_RecipeListWidget.AddItem(displayName, NULL, 1 );			
                }
            }
            else
            {
                displayName = getItemDisplayName(recipe.ItemClassName);
                m_FilteredRecipesLists.Insert(recipe);
                m_RecipeListWidget.AddItem(displayName, NULL, 1 );
            }
        }

        m_OldSearchFilter = m_SearchFilter;
        if(m_FilteredRecipesLists.Count() > 0)
        {
            m_LastRowIndex = -1;
            m_RecipeListWidget.SelectRow(0);
        }
        
	}

    //Refactor
    string getItemDisplayName(string itemClassname)
	{
		TStringArray itemInfos = new TStringArray;
		
		string cfg = "CfgVehicles " + itemClassname + " displayName";
		string displayName;
		GetGame().ConfigGetText(cfg, displayName);
	
		if (displayName == "")
		{
			cfg = "CfgAmmo " + itemClassname + " displayName";
			GetGame().ConfigGetText(cfg, displayName);
		}
		
		if (displayName == "")
		{
			cfg = "CfgMagazines " + itemClassname + " displayName";
			GetGame().ConfigGetText(cfg, displayName);
		}
		
		if (displayName == "")
		{
			cfg = "cfgWeapons " + itemClassname + " displayName";
			GetGame().ConfigGetText(cfg, displayName);
		}
	
		if (displayName == "")
		{
			cfg = "CfgNonAIVehicles " + itemClassname + " displayName";
			GetGame().ConfigGetText(cfg, displayName);
		}
		
		
		if (displayName != "")
			return displayName;
		else
			return itemClassname;
	}

    override void Update(float timeslice)
    {
        if (m_UiUpdateTimer >= 0.1)
		{   
            RefreshScreen();
            
			m_UiUpdateTimer = 0;
		}
		else
		{
			m_UiUpdateTimer += timeslice;
		}
    }
    
    void RefreshScreen(bool refresh = false, bool resetCombo = true)
    {            
        m_SearchFilter = m_SearchBox.GetText();
        if(m_SearchFilter != m_OldSearchFilter)
            UpdateRecipeList();

        int row_index = m_RecipeListWidget.GetSelectedRow();
        if (m_LastRowIndex != row_index || refresh)
        {
            m_LastRowIndex = row_index;
            
            ResetMenu();
            auto l_currentRecipe = m_FilteredRecipesLists.Get(row_index);
            if(!l_currentRecipe)
            {
                m_UiUpdateTimer = 0;
                m_CanCraft = false;
                return;
            }
            string itemType = l_currentRecipe.ItemClassName;
            if(l_currentRecipe.IsKitItem)
                itemType = l_currentRecipe.KitItemClassName;
            //create recipe preview
            CreateItem(itemType, m_RecipePreview0);
            UpdateItemPreview(m_RecipePreview0, m_RecipePreviewWidget);
            UpdateRecipeItemStats(l_currentRecipe.ResultQuantity);
            //array<ref WG_CraftingRequirements> reqs = m_FilteredRecipesLists.Get(row_index).RequirementsCollections[0].Requirements;
            
            array<ref WG_CraftingRequirementsCollection> reqsCollections = l_currentRecipe.RequirementsCollections;

            int r_i = reqsCollections.Count() - 1; 
            WG_CraftingRequirements requirements = new WG_CraftingRequirements;
            requirements.RequiredItemClassName = "";
            requirements.RequiredQuantity = -1;
            requirements.IsHealthQuantity = 0;
            requirements.SetEnoughQuantity(true);
            int remainingReqs = 10 - reqsCollections.Count();
            if(remainingReqs > 0)
            {
                for(int j = 0; j < remainingReqs; j++)
                {                    
                    r_i++;
                    l_currentRecipe.InsertRequirement(r_i,requirements);
                }
            }

            string quantity;
            bool hasEnough;
            bool show;
            for(int x = 0; x < m_RequiredItemsList.Count(); x++)
            {
                RequiredItems reqItem = m_RequiredItemsList[x];
                array<ref WG_CraftingRequirements> reqs = reqsCollections[x].Requirements;
				if(resetCombo)
				{
					reqItem.m_ReqItemsComboWidget.ClearAll();
	                //Populate reqitem combo widget
	                foreach(WG_CraftingRequirements l_reqs : reqs)
	                {
	                    if(l_reqs.RequiredItemClassName == string.Empty)
	                        continue;
	                    reqItem.m_ReqItemsComboWidget.AddItem(getItemDisplayName(l_reqs.RequiredItemClassName));
	                }
	                if(reqItem.m_ReqItemsComboWidget.GetNumItems() == 0)
	                {   
	                    reqItem.m_Panel.Show(false);
	                    reqItem.m_ReqItemsComboWidget.Show(false);
	                    continue;
	                }
					reqItem.m_ReqItemsComboWidget.SetCurrentItem(0);
				}
                int f = reqItem.m_ReqItemsComboWidget.GetCurrentItem();
                if(reqItem.m_ReqItemsComboWidget.GetNumItems() == 1)
                    reqItem.m_ReqItemsComboWidget.Enable(false);
                else
                    reqItem.m_ReqItemsComboWidget.Enable(true);
                for(int z = 0; z < reqs.Count(); z++)
                {
                    if(z == f)
					{
                        reqs[z].SetIsSelected(true);
						continue;
					}
                    reqs[z].SetIsSelected(false);
                }
                if(reqs[f].RequiredItemClassName == string.Empty)
                    continue;                    
                CreateItem(reqs[f].RequiredItemClassName, reqItem.m_ItemBasePreview);
                UpdateItemPreview(reqItem.m_ItemBasePreview, reqItem.m_PreviewWidget);
                CheckRequirements(reqs[f], reqItem.m_ItemBasePreview, quantity, hasEnough);
                UpdateReqItem(hasEnough, quantity, reqItem.m_ItemBasePreview.GetDisplayName(), reqItem.m_Panel, reqItem.m_ReqItemsComboWidget, reqItem.m_QuantityWidget);
            }
            m_CanCraft = m_FilteredRecipesLists.Get(row_index).CanCraft();
            
            
            if(m_CanCraft)
            {
                m_BtnCraft.Enable(true);
            }
            else
            {
                m_BtnCraft.Enable(false);
            }
        }
    }

    void DeleteItem(ItemBase item)
    {
        if(item)
        {
            item.Delete();
        }
    }

    void ResetMenu()
    {        
        DeleteItem(m_RecipePreview0);
        string panelWidgetName = "";
        for(int i = 0; i < m_RequiredItemsList.Count(); i++)
        {
            RequiredItems reqItem = m_RequiredItemsList[i];
            if(reqItem.m_ItemBasePreview)
                reqItem.m_ItemBasePreview.Delete();
            reqItem.m_Panel.Show(false);
            reqItem.m_ReqItemsComboWidget.Show(false);
        }
        m_ItemDescription.SetText("");
        m_ItemResultQuantity.SetText("");
    }

    void CreateItem(string itemType, out ItemBase item)
    {
        item = ItemBase.Cast(GetGame().CreateObject( itemType, "0 0 0", true, false, true ));
    }

	void UpdateItemPreview(ItemBase previewItem, ItemPreviewWidget itemPreviewWidget)
	{
        itemPreviewWidget.SetItem( previewItem );
        if(previewItem.IsKindOf("WoodenLog"))
            itemPreviewWidget.SetModelPosition( Vector(1.0,1.0,1.5) );
        else
            itemPreviewWidget.SetModelPosition( Vector(1.0,1.0,0.8) );
        itemPreviewWidget.SetModelOrientation( Vector(0,0,0) );

        float itemx, itemy;		
        itemPreviewWidget.GetPos(itemx, itemy);
        itemPreviewWidget.SetSize( 1.0, 1.0 );
        itemPreviewWidget.SetPos( 0, 0 );
    }

    void UpdateRecipeItemStats(int resultQuant)
    {
        if (m_RecipePreview0)
        {
            //add rest of the stats like weight
            m_ItemDescription.SetText(m_RecipePreview0.GetTooltip());
            m_ItemResultQuantity.SetText(resultQuant.ToString());
        }
        else
        {
            m_ItemDescription.SetText("");
            m_ItemResultQuantity.SetText("");
        }
	}

    void CheckRequirements(WG_CraftingRequirements reqs, ItemBase itemBase, out string quantity, out bool hasEnoughQuant)
    {        
        quantity = reqs.RequiredQuantity.ToString();

        if(itemBase.HasQuantityBar() && reqs.RequiredQuantity > 1)
        {
            int quantity_ratio = Math.Round( ( reqs.RequiredQuantity / itemBase.GetQuantityMax() ) * 100 );
            quantity = quantity_ratio.ToString() + "%";
        }
        
        if(reqs.IsHealthQuantity)
        {
            quantity = quantity + " HP";
        }
        
        if(reqs.RequiredQuantity == -1)
        {
            quantity = "1";
        }

        m_Player = PlayerBase.Cast(GetGame().GetPlayer());
        hasEnoughQuant = m_Player && m_Player.HasCargoByBaseType(reqs.RequiredItemClassName, reqs.RequiredQuantity, reqs.IsHealthQuantity);
        if(hasEnoughQuant)
            reqs.SetEnoughQuantity(true);
        else
            reqs.SetEnoughQuantity(false);
    }

    void UpdateReqItem(bool enoughQuant, string quantity, string name, out Widget panelWidget, out XComboBoxWidget xcomboWidget, out TextWidget quantityWidget)
	{
        panelWidget.Show(true);
        xcomboWidget.Show(true);
        quantityWidget.SetText(quantity);
        if(enoughQuant)
        {            
            quantityWidget.SetColor(ARGBF(1, 1, 1, 1));
        }
        else
        {
            quantityWidget.SetColor(ARGBF(0.8, 1, 0, 0));
        }
    }

    void Craft()
    {        
        int row_index = m_RecipeListWidget.GetSelectedRow();
        WG_CraftingRecipe recipe = m_FilteredRecipesLists.Get(row_index);        
        if(m_CanCraft)
        {   
            m_Player = PlayerBase.Cast(GetGame().GetPlayer());
            GetRPCManager().SendRPC("CraftingMaster", "CraftItemServer", new Param2<WG_CraftingRecipe, Man>(recipe, m_Player), true, m_Player.GetIdentity());            
            m_CanCraft = false;
			m_BtnCraft.Enable(false);
            m_LastRowIndex = -1;
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RefreshScreen, 250, false, true, false);
        }
    }

    //Click event triggers when you click on a widget, this method wont get called if your widget has the "IgnorePointer" property toggled in your .layout
    override bool OnClick(Widget w, int x, int y, int button)
    {
    	switch(w)
    	{
    		case m_BtnCloseMenu:
                Close();
    		break;
    		case m_BtnCraft:
                Craft();              
    		break;            
    	}
        XComboBoxWidget combo;
        if(Class.CastTo(combo,w))
        {
            foreach(RequiredItems reqItem : m_RequiredItemsList)
            {
                if(combo == reqItem.m_ReqItemsComboWidget)
                {
                    reqItem.m_ReqItemsComboWidget.SetCurrentItem(combo.GetCurrentItem());                    
                    break;
                }
            }
            RefreshScreen(true,false);
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

	bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		super.OnMouseButtonDown(w, x, y, button);
		
		if (w == m_RecipePreviewWidget)
		{
			GetGame().GetDragQueue().Call(this, "UpdateRotation");
			g_Game.GetMousePos(m_PreviewWidgetRotationX, m_PreviewWidgetRotationY);
			return true;
		}
		return false;
	}

	void UpdateRotation(int mouse_x, int mouse_y, bool is_dragging)
	{
		vector o = m_PreviewWidgetOrientation;
		o[0] = o[0] + (m_PreviewWidgetRotationY - mouse_y);
		o[1] = o[1] - (m_PreviewWidgetRotationX - mouse_x);
		
		m_RecipePreviewWidget.SetModelOrientation( o );
		
		if (!is_dragging)
		{
			m_PreviewWidgetOrientation = o;
		}
	}
    

	//--------------------------------------------------------------------------
	override bool OnMouseWheel(Widget  w, int  x, int  y, int wheel)
	{
		super.OnMouseWheel(w, x, y, wheel);
		
		if ( w == m_RecipePreviewWidget )
		{
			m_characterScaleDelta = wheel;
			UpdateScale();
		}
		return false;
	}
	
	//--------------------------------------------------------------------------
	void UpdateScale()
	{
		float w, h, x, y;		
		m_RecipePreviewWidget.GetPos(x, y);
		m_RecipePreviewWidget.GetSize(w,h);
		w = w + ( m_characterScaleDelta / 4);
		h = h + ( m_characterScaleDelta / 4 );
		if ( w > 0.5 && w < 3 )
		{
			m_RecipePreviewWidget.SetSize( w, h );
	
			// align to center 
			int screen_w, screen_h;
			GetScreenSize(screen_w, screen_h);
			float new_x = x - ( m_characterScaleDelta / 8 );
			float new_y = y - ( m_characterScaleDelta / 8 );
			m_RecipePreviewWidget.SetPos( new_x, new_y );
		}
	}
};