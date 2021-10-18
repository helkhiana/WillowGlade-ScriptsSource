class WG_TraderStorageView : ItemBase
{   
	ref array<int> renters = new ref array<int>;
	int m_LastRefreshUnixTime = -1;
	int m_MaxLifetime = 603800;

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	bool HasBeenRentedAlready(int id)
	{
		return renters.Find(id) != -1;
	}

	void AddToRenters(int id)
	{
		renters.Insert(id);
	}
	
	void RemoveFromRenters(int id)
	{
		if(!renters)
			return;
		if(renters.Find(id) == -1)
			return;
		renters.Remove(renters.Find(id));
	}

	string GetInstancedType()
	{
		return "";
	}

	string GetTokenTierType()
	{
		return "";
	}
	
    override bool DisableVicinityIcon()
	{
		return true;
	}

    override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{   
		if ( !super.OnStoreLoad(ctx, version) )
			return false;
		
		if (!ctx.Read(renters))
        {
			renters = new ref array<int>;
			return false;
        }
		if (!ctx.Read(m_LastRefreshUnixTime))
        {
			m_LastRefreshUnixTime = JMDate.Now(false).GetTimestamp();
			return false;
        }
				
		return true;
	}
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);		
		ctx.Write(renters);			
		ctx.Write(m_LastRefreshUnixTime);		
	}
	
	override void OnCEUpdate()
	{
		super.OnCEUpdate();
		if(m_LastRefreshUnixTime == -1)
		{
			m_LastRefreshUnixTime = JMDate.Now(false).GetTimestamp();
		}

		int deltaInSeconds = JMDate.Now(false).GetTimestamp() - m_LastRefreshUnixTime;
		if(deltaInSeconds > m_MaxLifetime)
		{
			GetCEApi().RadiusLifetimeReset(GetPosition(),1);
			m_LastRefreshUnixTime = JMDate.Now(false).GetTimestamp();
		}
	}

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionRentStorage);
        AddAction(ActionExtendRent);
        AddAction(ActionCheckRent);
    }
};

class WG_TraderStorageView_PlasticCrate : WG_TraderStorageView
{
	override string GetInstancedType()
	{
		return "WG_TraderStorage_Instanced_Tier1";
	}
	override string GetTokenTierType()
	{
		return "WG_Token_Storages_Tier1";
	}
};
class WG_TraderStorageView_KitchenUnit : WG_TraderStorageView 
{
	override string GetInstancedType()
	{
		return "WG_TraderStorage_Instanced_Tier2";
	}
	override string GetTokenTierType()
	{
		return "WG_Token_Storages_Tier2";
	}
};
class WG_TraderStorageView_SoloLocker : WG_TraderStorageView 
{
	override string GetInstancedType()
	{
		return "WG_TraderStorage_Instanced_Tier2";
	}
	override string GetTokenTierType()
	{
		return "WG_Token_Storages_Tier2";
	}
};
class WG_TraderStorageView_MilitaryLocker : WG_TraderStorageView
{
	override string GetInstancedType()
	{
		return "WG_TraderStorage_Instanced_Tier3";
	}
	override string GetTokenTierType()
	{
		return "WG_Token_Storages_Tier3";
	}
};
class WG_TraderStorageView_StorageBox : WG_TraderStorageView 
{
	override string GetInstancedType()
	{
		return "WG_TraderStorage_Instanced_Tier4";
	}
	override string GetTokenTierType()
	{
		return "WG_Token_Storages_Tier4";
	}
};
class WG_TraderStorageView_Locker : WG_TraderStorageView 
{
	override string GetInstancedType()
	{
		return "WG_TraderStorage_Instanced_Tier5";
	}
	override string GetTokenTierType()
	{
		return "WG_Token_Storages_Tier5";
	}
};