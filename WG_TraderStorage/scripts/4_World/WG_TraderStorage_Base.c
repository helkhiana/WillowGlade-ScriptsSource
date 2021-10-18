class WG_TraderStorage_Base : ItemBase
{
	//persistent
    int m_WGPlayerId;
	string m_OwnerName = "";
	int m_RentExpiryUnixTime = -1;
	//non-persistent
	int m_MaxLifetime = 604800;
	//int m_MaxLifetime = 160;

    void WG_TraderStorage_Base()
    {     
        RegisterNetSyncVariableInt("m_WGPlayerId");
    }

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

    int GetWGPlayerId()
    {
        if(!m_WGPlayerId)
            m_WGPlayerId = -1;
        return m_WGPlayerId;
    }

    void SetWGPlayerId(PlayerBase player, int id)
    {
        m_WGPlayerId = id;
		m_OwnerName = player.GetIdentity().GetName();
		m_RentExpiryUnixTime = JMDate.Now(false).GetTimestamp() + m_MaxLifetime;
		Print("Player " +  m_OwnerName + " (" + m_WGPlayerId + ") has rented storage (" + GetType() + ") with expiry time " + TimestampToString(m_RentExpiryUnixTime) + ".");
        SetSynchDirty();
    }
	
    void ExtendRent()
    {        
		m_RentExpiryUnixTime += m_MaxLifetime;
		Print("Player " +  m_OwnerName + " (" + m_WGPlayerId + ") has extended rent for storage (" + GetType() + ") with new expiry time " + TimestampToString(m_RentExpiryUnixTime) + ".");
    }
	
    string GetRentExpiryTimeString()
    {        
		return TimestampToString(m_RentExpiryUnixTime);
    }

    override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{   
		if ( !super.OnStoreLoad(ctx, version) )
			return false;
		if (!ctx.Read(m_WGPlayerId))
        {
            m_WGPlayerId = -1;
			return false;
        }
		if (!ctx.Read(m_OwnerName))
        {
            m_OwnerName = "";
			return false;
        }
		if (!ctx.Read(m_RentExpiryUnixTime))
        {
            m_RentExpiryUnixTime = -1;
			return false;
        }
		//Print("= - - - - - - - - - - - - - =");
		//Print("Trader Storage");
		//Print(Object.GetDebugName(this));
		//Print("ID: " + m_WGPlayerId + " Name: " + m_OwnerName);
		//Print("Expiry Time: " + GetRentExpiryTimeString());
		//Print("= - - - - - - - - - - - - - =");
		SetSynchDirty();
		return true;
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);		
		ctx.Write(m_WGPlayerId);		
		ctx.Write(m_OwnerName);
		ctx.Write(m_RentExpiryUnixTime);
	}

	override void OnCEUpdate()
	{
		super.OnCEUpdate();
		if(m_RentExpiryUnixTime == -1)
		{
			m_RentExpiryUnixTime = JMDate.Now(false).GetTimestamp();
		}

		int deltaInSeconds = m_RentExpiryUnixTime - JMDate.Now(false).GetTimestamp();
		if(deltaInSeconds < 0)
		{
			ref array<Object> nearest_objects = new array<Object>;
			ref array<CargoBase> proxy_cargos = new array<CargoBase>;
			GetGame().GetObjectsAtPosition( GetPosition(), 1, nearest_objects, proxy_cargos );
			foreach(Object obj : nearest_objects)
			{
				WG_TraderStorageView storage = WG_TraderStorageView.Cast(obj);
				if(storage && storage.HasBeenRentedAlready(m_WGPlayerId))
				{
					storage.RemoveFromRenters(m_WGPlayerId);
					break;
				}
			}	
			Print("Player's " +  m_OwnerName + " (" + m_WGPlayerId + ") storage (" + GetType() + ") has been deleted. Expiry time was " + TimestampToString(m_RentExpiryUnixTime) + ".");
			Delete();
		}
	}
};

class WG_TraderStorage_Instanced_PlasticCrate : WG_TraderStorage_Base {};
class WG_TraderStorage_Instanced_KitchenUnit : WG_TraderStorage_Base {};
class WG_TraderStorage_Instanced_Locker : WG_TraderStorage_Base {};
class WG_TraderStorage_Instanced_MilitaryLocker : WG_TraderStorage_Base {};
class WG_TraderStorage_Instanced_StorageBox : WG_TraderStorage_Base {};