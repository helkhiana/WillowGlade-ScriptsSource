class WG_LS_Manager : PluginBase
{
	protected ref Timer m_UpdateTimer;
	private ref WG_LS_Config m_WGLSConfig;
	private ref array<ref WG_LootCrate_Base> spawnedCrates = new array<ref WG_LootCrate_Base>;
	private float currentDelta = 0;
	private float TICK_INTERVAL = 1800.0;
	private bool initialCheckBool = true;
	private bool initialSpawn = true;

    override void OnInit()
    {
        m_WGLSConfig = g_Game.GetWG_LS_Config();
        TICK_INTERVAL = m_WGLSConfig.GetRestockInterval();
    }

    override void OnUpdate(float delta_time)
    {
        InitialCheck();
        currentDelta += delta_time;
        if (currentDelta >= TICK_INTERVAL || initialSpawn)
        {
            array<ref WG_LS_LootCrate> lootCrates = m_WGLSConfig.Get_LootArray();
            foreach (WG_LS_LootCrate crate : lootCrates)
            {
                CheckSpawnsAndRespawn(crate);
            }
            currentDelta = 0.0;
            initialSpawn = false;
        }
    }

    void CheckSpawnsAndRespawn(WG_LS_LootCrate crate)
    {
        if (!crate.isActive)
            return;

        //check if we have spawned some already
        ref array<ref WG_LootCrate_Base> foundCrates = new array<ref WG_LootCrate_Base>;
        foreach (ref WG_LootCrate_Base baseSpawned : spawnedCrates)
        {
            if (baseSpawned.GetType() == crate.classname)
                foundCrates.Insert(baseSpawned);
        }

        if (foundCrates.Count() >= crate.nominal)
        {
            //Print("We are over nominal for crates: " + crate.classname);
            return;
        }
        int foundCratesCount = foundCrates.Count();
        int newlySpawnedCratesCount = 0;
        int nominalCrateToSpawn = Math.RandomInt(crate.min, crate.nominal);
        int leftToSpawn = nominalCrateToSpawn - foundCratesCount;
        //Print("Requiring to spawn max of " + nominalCrateToSpawn + " of type " + crate.classname);
        //Print("Remaining to spawn " + leftToSpawn + " of type " + crate.classname);
        while (foundCratesCount < nominalCrateToSpawn)
        {
			//taking a copy of the array so we can remove the locations
            array<ref WG_LS_Position> t_lootLoc = crate.lootLocations;
            array<ref WG_LS_Position> lootLocations = new array<ref WG_LS_Position>;
            foreach (auto l_loc : t_lootLoc)
            {
                lootLocations.Insert(l_loc);
            }
            //remove locations which are already spawned or within distanceradius
            foreach (WG_LootCrate_Base foundCrate : foundCrates)
            {
                FilterLocationsArray(crate.distanceradius, foundCrate.GetPosition(), lootLocations);
            }

            //check for player distance
            ref array<Man> players = new array<Man>;
            g_Game.GetWorld().GetPlayerList(players);
            foreach (Man f_player : players)
            {
                FilterLocationsArray(crate.playersaferadius, f_player.GetPosition(), lootLocations);
            }

            if (lootLocations.Count() < 1)
                break;
            auto posType = lootLocations.GetRandomElement();
            if (!posType)
                continue;
            auto crateSpawn = SpawnObject(crate.classname, posType.position, posType.orientation); 
            spawnedCrates.Insert(crateSpawn);
            foundCrates.Insert(crateSpawn);
            newlySpawnedCratesCount++;
            foundCratesCount = foundCrates.Count();
        }
        //Print("Spawned " + newlySpawnedCratesCount + " of type " + crate.classname);
    }

    void FilterLocationsArray(float radius, vector posOfDestination, out array<ref WG_LS_Position> lootLocations)
    {
        array<ref WG_LS_Position> l_lootLocations = new array<ref WG_LS_Position>;
        foreach (WG_LS_Position f_loc : lootLocations)
        {
            l_lootLocations.Insert(f_loc);
        }
        foreach (WG_LS_Position f_LSPosition : lootLocations)
        {
            float p_distance = vector.Distance(f_LSPosition.position, posOfDestination);
            if (p_distance <= radius)
            {
                int l_indexOfCrate = l_lootLocations.Find(f_LSPosition);
                if (l_lootLocations.Count() > 0 && l_indexOfCrate > -1)
                    l_lootLocations.Remove(l_indexOfCrate);
            }
        }

        if (lootLocations.Count() != l_lootLocations.Count())
        {
            lootLocations.Clear();
            foreach (WG_LS_Position ff_loc : l_lootLocations)
            {
                lootLocations.Insert(ff_loc);
            }
        }
    }

    void InitialCheck()
    {
		if(!initialCheckBool)
			return;
        array<ref WG_LS_LootCrate> lootCrates = m_WGLSConfig.Get_LootArray();
        foreach (ref WG_LS_LootCrate crate : lootCrates)
        {
            array<ref WG_LS_Position> lootLocations = crate.lootLocations;
            int locationCount = 0;
            foreach (ref WG_LS_Position location : lootLocations)
            {
                ref array<Object> nearest_objects = new array<Object>;
                ref array<CargoBase> proxy_cargos = new array<CargoBase>;
                GetGame().GetObjectsAtPosition(location.position, 1, nearest_objects, proxy_cargos);
                foreach (Object obj : nearest_objects)
                {
                    WG_LootCrate_Base cratebase;
                    if (Class.CastTo(cratebase, obj))
                    {
                        spawnedCrates.Insert(cratebase);
                        locationCount++;
                    }
                }
            }
            //Print("Found " + locationCount + " crates of type " + crate.classname);
        }
		initialCheckBool = false;
    }

    Object SpawnObject(string type, vector position, vector orientation)
    {
        auto obj = GetGame().CreateObject(type, position);
        if (!obj)
        {
            Print("WG_LS_Manager ERROR: " + type + " at pos " + position + " couldn't be created");
            return null;
        }
        obj.SetPosition(position);
        obj.SetOrientation(orientation);
        return obj;
    }

    void RemoveEntity(WG_LootCrate_Base crate)
    {
        int index = spawnedCrates.Find(crate);
        spawnedCrates.Remove(index);
    }
};