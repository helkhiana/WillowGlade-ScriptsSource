modded class SmallProtectorCase: Container_Base 
{
	ref array<string> m_NotAllowedCargo = {"Bear_ColorBase","FirstAidKit","SmallProtectorCase"};
	override bool CanReceiveItemIntoCargo (EntityAI item)
	{
		foreach( string notAllowed : m_NotAllowedCargo )
		{
			if(item.IsKindOf(notAllowed))
				return false;
		}
		
		return super.CanReceiveItemIntoCargo(item);
	}
	
	override bool CanSwapItemInCargo (EntityAI child_entity, EntityAI new_entity)
	{
		foreach( string notAllowed : m_NotAllowedCargo )
		{		
			if(child_entity.IsKindOf(notAllowed) || new_entity.IsKindOf(notAllowed))
				return false;
		}		
		return super.CanSwapItemInCargo(child_entity, new_entity);		
	}

    override vector Get_ItemPlacingPos()
	{
		return "0 0.15 0";
	}

    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};

modded class AmmoBox: Container_Base 
{
    override vector Get_ItemPlacingPos()
	{
		return "0 0.15 0";
	}

    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};

modded class GiftBox_Base: Container_Base
{
    override void SetActions()
    {
        super.SetActions();        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};

modded class Bear_ColorBase extends Container_Base
{
	ref array<string> m_NotAllowedCargo = {"Bear_ColorBase","FirstAidKit","SmallProtectorCase"};
	override bool CanReceiveItemIntoCargo (EntityAI item)
	{
		foreach( string notAllowed : m_NotAllowedCargo )
		{
			if(item.IsKindOf(notAllowed))
				return false;
		}
		
		return super.CanReceiveItemIntoCargo(item);
	}
	
	override bool CanSwapItemInCargo (EntityAI child_entity, EntityAI new_entity)
	{
		foreach( string notAllowed : m_NotAllowedCargo )
		{		
			if(child_entity.IsKindOf(notAllowed) || new_entity.IsKindOf(notAllowed))
				return false;
		}		
		return super.CanSwapItemInCargo(child_entity, new_entity);		
	}

	override vector Get_ItemPlacingPos()
	{
		return "0 0.1 0";
	}

	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};

modded class FirstAidKit : Container_Base 
{
	ref array<string> m_NotAllowedCargo = {"Bear_ColorBase","FirstAidKit","SmallProtectorCase"};
	override bool CanReceiveItemIntoCargo (EntityAI item)
	{
		foreach( string notAllowed : m_NotAllowedCargo )
		{
			if(item.IsKindOf(notAllowed))
				return false;
		}
		
		return super.CanReceiveItemIntoCargo(item);
	}
	
	override bool CanSwapItemInCargo (EntityAI child_entity, EntityAI new_entity)
	{
		foreach( string notAllowed : m_NotAllowedCargo )
		{		
			if(child_entity.IsKindOf(notAllowed) || new_entity.IsKindOf(notAllowed))
				return false;
		}		
		return super.CanSwapItemInCargo(child_entity, new_entity);		
	}
    
	override vector Get_ItemPlacingPos()
	{
		return "0 0.1 0";
	}

	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};


modded class PumpkinHelmet : Clothing
{
	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};

modded class PortableGasLamp extends ItemBase
{
	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};

modded class PortableGasStove extends ItemBase
{
	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};


class HumanSkull extends ItemBase
{
	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};