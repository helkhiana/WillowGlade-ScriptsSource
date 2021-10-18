class BuildingWithScrapChance : BuildingSuper
{
    private int roll = 0;
    private bool m_CanSearch = false;
    private bool m_IsSearched = false;
	int m_SpawnedUnixTime = -1;		
	int m_TimeBetweenSearches = 180;
    
    void BuildingWithScrapChance()
    {        
		RegisterNetSyncVariableBool("m_IsSearched");
		RegisterNetSyncVariableBool("m_CanSearch");
        if(GetGame().IsServer())
            SetScrapChance(35);
    }


    override void EEInit()
	{
		super.EEInit();		
		if(GetGame().IsServer())
			m_SpawnedUnixTime = JMDate.Now(false).GetTimestamp();
	}

	void SetScrapChance(int chance = 0)
	{
		m_CanSearch  = Math.RandomInt(0, 100) > chance;
        SetSynchDirty();
	}

    bool CanScrap()
    {
        return m_CanSearch && !m_IsSearched;
    }
    
    void ResetSearch()
    {
		m_SpawnedUnixTime = JMDate.Now(false).GetTimestamp();
        m_IsSearched = true;
        SetSynchDirty();
    }

    
	override void OnCEUpdate()
	{
		super.OnCEUpdate();
		if(m_SpawnedUnixTime == -1)
			m_SpawnedUnixTime = JMDate.Now(false).GetTimestamp();

		int deltaInteraction = JMDate.Now(false).GetTimestamp() - m_SpawnedUnixTime;
		if(deltaInteraction > m_TimeBetweenSearches && m_IsSearched)
		{	
            m_IsSearched = false;
            SetScrapChance(35);
        }
	}
};

//mmo
class MMO_Bike_Ruined : BuildingWithScrapChance {};
class MMO_Debris_TrashBag_Set1 : BuildingWithScrapChance {};
class MMO_Debris_TrashBag_Set2 : BuildingWithScrapChance {};
class MMO_Debris_TrashBag_Set3 : BuildingWithScrapChance {};
class MMO_Debris_Trash_Set1 : BuildingWithScrapChance {};
class MMO_Debris_Trash_Set2 : BuildingWithScrapChance {};
class MMO_Debris_Trash_Set3 : BuildingWithScrapChance {};
class MMO_Debris_Trash_Set4 : BuildingWithScrapChance {};
class MMO_Debris_Trash_Set5 : BuildingWithScrapChance {};
class MMO_Debris_Trash_Set6 : BuildingWithScrapChance {};
class MMO_Debris_Trash_Set7 : BuildingWithScrapChance {};
//bldr
class bldr_Garbage_Pile1 : BuildingWithScrapChance {};
class bldr_Garbage_Pile2 : BuildingWithScrapChance {};
class bldr_Garbage_Pile3 : BuildingWithScrapChance {};
class bldr_Garbage_Pile4 : BuildingWithScrapChance {};
class bldr_Garbage_Pile5 : BuildingWithScrapChance {};
class bldr_Garbage_Pile6 : BuildingWithScrapChance {};
class bldr_Garbage_Pile7 : BuildingWithScrapChance {};
class bldr_Garbage_Pile8 : BuildingWithScrapChance {};
class bldr_Garbage_Bin : BuildingWithScrapChance {};
class bldr_Garbage_Bin2 : BuildingWithScrapChance {};
class bldr_Garbage_Container : BuildingWithScrapChance {};
class bldr_Garbage_Container_Glass : BuildingWithScrapChance {};
class bldr_Garbage_Container_Paper : BuildingWithScrapChance {};
class bldr_Garbage_Container_Plastic : BuildingWithScrapChance {};
class bldr_Garbage_Container2_Open : BuildingWithScrapChance {};
class bldr_Garbage_Container2_Closed : BuildingWithScrapChance {};
//static bldr
class Static_Garbage_Pile1 : BuildingWithScrapChance {};
class Static_Garbage_Pile2 : BuildingWithScrapChance {};
class Static_Garbage_Pile3 : BuildingWithScrapChance {};
class Static_Garbage_Pile4 : BuildingWithScrapChance {};
class Static_Garbage_Pile5 : BuildingWithScrapChance {};
class Static_Garbage_Pile6 : BuildingWithScrapChance {};
class Static_Garbage_Pile7 : BuildingWithScrapChance {};
class Static_Garbage_Pile8 : BuildingWithScrapChance {};
class Static_Garbage_Bin : BuildingWithScrapChance {};
class Static_Garbage_Bin2 : BuildingWithScrapChance {};
class Static_Garbage_Container : BuildingWithScrapChance {};
class Static_Garbage_Container_Glass : BuildingWithScrapChance {};
class Static_Garbage_Container_Paper : BuildingWithScrapChance {};
class Static_Garbage_Container_Plastic : BuildingWithScrapChance {};
class Static_Garbage_Container2_Open : BuildingWithScrapChance {};
class Static_Garbage_Container2_Closed : BuildingWithScrapChance {};