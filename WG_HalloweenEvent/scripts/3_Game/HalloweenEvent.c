class HalloweenEventZombieWave
{
    ref array<ref DayZInfected> zombies = new array<ref DayZInfected>;
    bool waveEnded = false;
    bool waveStarted = false;
    int waveNo = -1;
}
class HalloweenEvent
{
    ref HalloweenEventZombieWave zombieWave1 = new HalloweenEventZombieWave;
    ref HalloweenEventZombieWave zombieWave2 = new HalloweenEventZombieWave;
    ref HalloweenEventZombieWave zombieWave3 = new HalloweenEventZombieWave;
    ref map<string, ref Man> registeredPlayers = new map<string, ref Man>;
    ref map<string, vector> registeredPlayersThatDied = new map<string, vector>;
    bool allRegistered = false;
    bool started = false;
    Building m_RegisterGate;
    int m_RegisterDoorIndex = -1;
    int m_MaxPlayerCount = 5;
    int m_MaxEventTimeInSeconds = 1800;
    int m_EventRegTimeInSeconds = 120;
    int m_DeadBringTimeInMiliSeconds = 30000;
    EntityAI rewardChest;
    ref array<vector> wave1Locations = 
    {
        "2306.740967 355.838379 7810.274414", 
        "2317.296143 356.522064 7817.378418", 
        "2308.229492 355.812317 7828.876953", 
        "2319.443359 356.449951 7832.117188", 
        "2327.300537 357.256622 7831.537109", 
        "2324.312988 356.904755 7818.157227", 
        "2323.781250 356.954407 7809.692383", 
        "2322.952148 356.935242 7805.161621", 
        "2311.197021 357.285248 7798.256836", 
        "2310.151855 356.149506 7791.720215", 
        "2313.201172 356.347992 7784.986816", 
        "2310.555420 356.118561 7777.391602", 
        "2305.356689 355.881287 7787.336426", 
        "2299.447266 355.217194 7804.392578"
    };

    ref array<vector> wave2Locations = 
    {
        "2364.283936 358.580566 7812.650391",
        "2361.830566 358.393311 7823.298340",
        "2353.064209 358.122345 7820.211914",
        "2343.352539 357.383301 7839.513184",
        "2346.923828 357.704498 7831.530762",
        "2334.303467 357.386749 7818.565430",
        "2348.172119 357.991180 7816.100098",
        "2342.785889 357.814026 7812.200195",
        "2353.095947 358.256439 7805.280273",
        "2360.993652 358.576996 7797.445313",
        "2337.524658 358.389130 7792.072754",
        "2333.982178 358.389130 7796.583984",
        "2330.658691 358.389130 7784.423340",
        "2318.825195 356.704956 7780.788574",
        "2325.959473 357.134430 7795.778320",
        "2326.527100 357.057068 7765.421875",
        "2325.833496 356.957642 7758.176758",
        "2327.264648 356.993164 7752.888672",
        "2344.714600 357.882721 7748.666504",
        "2340.815918 357.736755 7756.796875",
        "2348.147949 358.100983 7767.757324",
        "2336.054688 357.583710 7804.932129",
        "2344.698730 357.977356 7800.119629",
        "2341.087402 357.848907 7782.128906",
        "2353.740967 358.361511 7784.372070"
    };

    ref array<vector> wave3Locations = 
    {
        "2378.652344 359.030884 7816.156738",
        "2382.769531 359.242950 7809.002930",
        "2388.537842 359.823639 7787.362793",
        "2378.084961 359.389313 7777.661621",
        "2366.594727 358.855988 7785.472656",
        "2399.853516 360.677246 7775.712891",
        "2385.023193 359.794617 7772.197266",
        "2373.551270 359.198181 7768.949219",
        "2364.087646 358.750885 7759.946289",
        "2371.127197 359.080292 7758.502441",
        "2361.207520 358.611694 7746.265137",
        "2373.457520 359.189850 7743.339844",
        "2395.251709 360.532562 7757.104004",
        "2393.900879 360.440247 7749.699707",
        "2384.820313 359.850037 7753.536133",
        "2369.793457 358.956757 7730.741699",
        "2379.124268 359.461823 7737.423828",
        "2373.093506 358.971039 7719.748535",
        "2365.858643 358.393127 7699.801270",
        "2361.658691 358.392853 7711.558105",
        "2349.689209 357.979980 7724.228516",
        "2343.059814 357.500275 7714.664551",
        "2354.088867 358.028961 7710.383301",
        "2360.066162 358.451324 7722.324219",
        "2356.813965 357.996338 7702.091309",
        "2339.270264 357.555359 7739.406738",
        "2346.415771 357.873749 7731.241699",
        "2358.642334 358.474274 7734.746582",
        "2340.039307 357.177277 7707.670898",
        "2365.446045 358.713501 7724.568848"
    };

    ref array<vector> wave4Locations = 
    {
        "2401.066162 360.380188 7709.386230",
        "2396.728516 359.745667 7694.314941",
        "2393.928711 359.625885 7697.286133",
        "2401.682861 360.248383 7703.479492",
        "2398.747803 360.031830 7701.218750",
        "2397.374756 360.130920 7709.229980",
        "2380.753418 359.153961 7706.323730",
        "2381.378418 359.266602 7710.116699",
        "2388.689941 359.533142 7703.688477",
        "2389.232178 359.633575 7707.100586"
    };

    vector resetLocation = "2223.108398 347.124420 7842.403809";
    vector registerLocation = "2266.24 355.703 7828.07";
    vector rewardChestLocation = "2452.714600 364.040009 7684.798340";
    
    void HalloweenEvent()
    {
        Init();
    }
    
    void AssignBuilding(Building gateToUnlock, int doorIndex)
    {
        m_RegisterGate = gateToUnlock;
        m_RegisterDoorIndex = doorIndex;
    }

    void Init()
    {        
        g_Game.SetHalloweenWave1EventGateOpenable(false);
        RegisterPlayers();
    }

    void EventStart()
    {
        Print("[WG_DEBUG][Halloween] - Starting event");
        LockRegisterDoors();
        started = true;        
        g_Game.SetHalloweenWave1EventGateOpenable(true);
    }

    bool HasStarted()
    {
        return started;
    }

    void RegisterPlayers()
    {
        ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
			
		for ( int i = 0; i < players.Count(); i++ )
		{
			Man player;
			Class.CastTo(player, players.Get(i));
			if(player && player.IsAlive())
			{
				float distance_to_player = vector.Distance(registerLocation, player.GetPosition());
                if(distance_to_player < 15)
                {
                    string playerID = player.GetIdentity().GetId();
                    if(registeredPlayers.Get(playerID))
                        continue;
                    registeredPlayers.Insert(playerID,player);
                    Param1<string> registeredMessage = new Param1<string>("You have been registered for the halloween event. You have to wait 2 minutes until event can be started.");
			        GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, registeredMessage, true, player.GetIdentity());
                }
			}
		}
    }
    
    void CheckPlayersInArea()
    {
        ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
			
		for ( int i = 0; i < players.Count(); i++ )
		{
			Man player;
			Class.CastTo(player, players.Get(i));
			if(player && player.IsAlive())
			{
				float distance_to_player = vector.Distance(registerLocation, player.GetPosition());
                string playerID = player.GetIdentity().GetId();
                if(distance_to_player < 200)
                {
                    if(!registeredPlayers.Get(playerID))
                    {                    
                        Param1<string> registeredMessage = new Param1<string>("You have not registered for the halloween event. You have been teleported away.");
			            GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, registeredMessage, true, player.GetIdentity());
                        vector newPos = player.GetPosition();
                        newPos[2] = newPos[2] + 200;
                        newPos[1] = GetGame().SurfaceY(newPos[0],newPos[2]);
                        player.SetPosition(resetLocation);
                    }
                }
                
			}
		}
    }

    void RemovePlayer(Man player)
    {
        string playerID = player.GetIdentity().GetId();
        if(registeredPlayers.Get(playerID))
        {
            Print("[WG_DEBUG][Halloween] - removing player from registered players " + playerID);
            registeredPlayers.Remove(playerID);
            ref RegisteredPlayersThatDied deadPlayer = new ref RegisteredPlayersThatDied;
            deadPlayer.playerId = playerID;
            deadPlayer.positionOfBody = player.GetPosition();
            deadPlayer.teleported = false;
            deadPlayer.isAlive = false;
            g_Game.AddToRegisteredPlayersThatDied(deadPlayer);
        }
    }

    //returns true if ended so we can stop calling this
    bool OnUpdate()
    {
        if(zombieWave1.waveStarted && !zombieWave1.waveEnded)
            CheckZombieWave(zombieWave1);
        if(zombieWave2.waveStarted && !zombieWave2.waveEnded)
            CheckZombieWave(zombieWave2);
        if(zombieWave3.waveStarted && !zombieWave3.waveEnded)
            CheckZombieWave(zombieWave3);
        
        if(started && !zombieWave1.waveStarted)
            SpawnWave1();
        if(zombieWave1.waveEnded && !zombieWave2.waveStarted)
            SpawnWave2();
        if(zombieWave1.waveEnded && zombieWave2.waveEnded &&!zombieWave3.waveStarted)
            SpawnWave3();

        if(zombieWave1.waveEnded && zombieWave2.waveEnded && zombieWave3.waveEnded)
        {
            Cleanup();
            SpawnRewards();
            g_Game.SetHalloweenLastEventToNow();
            InformRegisteredPlayers("All waves have been defeated. Collect your rewards in your specific crate.");
            GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( g_Game.SetShouldCheckHEDeadBodies, m_DeadBringTimeInMiliSeconds, false, true);
            return true;
        }

        int deltaInSeconds = JMDate.Now(false).GetTimestamp() - g_Game.GetHalloweenRegisterEventTime();
        if(!started)
        {
            int remaining = m_EventRegTimeInSeconds - deltaInSeconds;
            InformRegisteredPlayers("Waiting for event to start. Time remaining: " + remaining);
        }
        if((!started &&  deltaInSeconds > m_EventRegTimeInSeconds && registeredPlayers.Count() > 0) || (!started && registeredPlayers.Count() == m_MaxPlayerCount))
        {
            EventStart();
            InformRegisteredPlayers("All players registered. Any players that didn't get message will be teleported away.");
            InformRegisteredPlayers("Proceed to next area for first wave. You have 30 minutes to finish the event.");
        }
        else if(started)
        {
            CheckPlayersInArea();
            if(registeredPlayers.Count() == 0 || deltaInSeconds > m_MaxEventTimeInSeconds)
            {
                Cleanup();
                GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( g_Game.SetShouldCheckHEDeadBodies, m_DeadBringTimeInMiliSeconds, false, true);
                return true;
            }
            if(deltaInSeconds > 1500)
            {
                InformRegisteredPlayers("You have less than 5 minutes to finish the event.");
            }
        }
        else
        {
            RegisterPlayers();
        }
            
        return false;
    }

    void Cleanup()
    {        
        DeleteZombiesFromWave(zombieWave1.zombies);
        DeleteZombiesFromWave(zombieWave2.zombies);
        DeleteZombiesFromWave(zombieWave3.zombies);
        UnlockAllDoors();
    }

    void InformRegisteredPlayers(string message)
    {
        foreach(string playerID, Man player : registeredPlayers)
        {
            if(player.IsAlive())
            {
                Param1<string> registeredMessage = new Param1<string>(message);
                GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, registeredMessage, true, player.GetIdentity());
            }
        }
    }

    void CheckZombieWave(HalloweenEventZombieWave wave)
    {
        foreach(DayZInfected zom : wave.zombies)
        {
            if(zom.IsAlive())
                return;
        }
        InformRegisteredPlayers("Wave has been defeated.");
        wave.waveEnded = true;
    }

    bool CheckAllPlayersAreDead()
    {
        foreach(string playerID, Man player : registeredPlayers)
        {
            if(player.IsAlive())
                return false;
        }
        return true;
    }
    
    void DeleteZombiesFromWave(array<ref DayZInfected> waveZombies)
    {
        foreach(DayZInfected zom : waveZombies)
        {
            if(zom)
                zom.Delete();
        }
    }

    void UnlockAllDoors()
    {
        g_Game.SetHalloweenRegisterEventGateOpenable(true);
        if(m_RegisterGate)
            m_RegisterGate.OpenDoor(m_RegisterDoorIndex);
        g_Game.SetHalloweenWave1EventGateOpenable(true);
    }

    void LockRegisterDoors()
    {
        g_Game.SetHalloweenRegisterEventGateOpenable(false);
        if(m_RegisterGate)
            m_RegisterGate.CloseDoor(m_RegisterDoorIndex);
    }

    void SpawnRewards()
    {
        rewardChest = EntityAI.Cast(GetGame().CreateObjectEx("WG_RewardChestView", rewardChestLocation, ECE_PLACE_ON_SURFACE));
        rewardChest.SetOrientation("-71.000000 -2.000000 0.000000");
        int index = 0;
        foreach(string playerId, Man player : registeredPlayers)
        {
            if(player.IsAlive())
            {
                WG_RewardChest_Base instanced = WG_RewardChest_Base.Cast(GetGame().CreateObjectEx("WG_RewardChest_Instanced", rewardChestLocation, ECE_PLACE_ON_SURFACE))
                int id = Math.RandomIntInclusive(1, int.MAX - 1);
                instanced.SetWGPlayerId(player, id);
                instanced.SpawnRewards();
                index++;
            }
        }
    }

    DayZInfected SpawnInfected(string type, vector pos)
    {
        vector newPos = pos;
        newPos[1] = GetGame().SurfaceY(newPos[0],newPos[2]);
        return DayZInfected.Cast(GetGame().CreateObject(type, newPos, false, true ));
    }
    //Wave Spawns
    void SpawnWave1()
    {
        zombieWave1.zombies.Clear();
        zombieWave1.waveStarted = true;
        zombieWave1.zombies.Insert(SpawnInfected("ZmbM_HunterOld_Autumn", wave1Locations.GetRandomElement()));
        zombieWave1.zombies.Insert(SpawnInfected("ZmbM_HunterOld_Spring", wave1Locations.GetRandomElement()));
        zombieWave1.zombies.Insert(SpawnInfected("ZmbF_SurvivorNormal_Blue", wave1Locations.GetRandomElement()));
        zombieWave1.zombies.Insert(SpawnInfected("ZmbM_HikerSkinny_Green", wave1Locations.GetRandomElement()));
        zombieWave1.zombies.Insert(SpawnInfected("ZmbF_JournalistNormal_Blue", wave1Locations.GetRandomElement()));
        zombieWave1.zombies.Insert(SpawnInfected("ZmbM_FishermanOld_Green", wave1Locations.GetRandomElement()));
        zombieWave1.zombies.Insert(SpawnInfected("ZmbF_CitizenBSkinny", wave1Locations.GetRandomElement()));
        zombieWave1.zombies.Insert(SpawnInfected("ZmbM_priestPopSkinny", wave1Locations.GetRandomElement()));
        zombieWave1.zombies.Insert(SpawnInfected("ZmbM_priestPopSkinny", wave1Locations.GetRandomElement()));
    }

    void SpawnWave2()
    {
        //Spawn 5 regular maniac zombies
        //Spawn 2 maniac monster zombies
        //Spawn 2 maniac scarecrow zombies
        zombieWave2.zombies.Clear();
        zombieWave2.waveStarted = true;   
        zombieWave2.zombies.Insert(SpawnInfected("ZmbM_HunterOld_Autumn", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("ZmbM_HunterOld_Spring", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("ZmbF_SurvivorNormal_Blue", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("ZmbM_HikerSkinny_Green", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("ZmbF_JournalistNormal_Blue", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("ZmbM_FishermanOld_Green", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("ZmbF_CitizenBSkinny", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("ZmbM_priestPopSkinny", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("ZmbM_priestPopSkinny", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("WG_Infected_Maniac", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("WG_Infected_Maniac", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("WG_Infected_ManiacMasked", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("WG_Infected_ManiacMasked", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("WG_Infected_ManiacMasked", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("WG_Infected_ManiacMonster", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("WG_Infected_ManiacMonster", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("WG_Infected_Scarecrow", wave2Locations.GetRandomElement()));
        zombieWave2.zombies.Insert(SpawnInfected("WG_Infected_Scarecrow", wave2Locations.GetRandomElement()));
    }

    void SpawnWave3()
    {
        //Spawn 1 + 2
        //Spawn 5 evil pumpkin zombies
        //Spawn 7 wolves
        //Spawn 1 boss        
        zombieWave3.zombies.Clear();    
        zombieWave3.waveStarted = true;
        zombieWave3.zombies.Insert(SpawnInfected("ZmbM_HunterOld_Autumn", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("ZmbM_HunterOld_Spring", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("ZmbF_SurvivorNormal_Blue", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("ZmbM_HikerSkinny_Green", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("ZmbF_JournalistNormal_Blue", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("ZmbM_FishermanOld_Green", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("ZmbF_CitizenBSkinny", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("ZmbM_priestPopSkinny", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("ZmbM_priestPopSkinny", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_Maniac", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_Maniac", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_ManiacMasked", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_ManiacMasked", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_ManiacMasked", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_ManiacMonster", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_ManiacMonster", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_Scarecrow", wave3Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_Scarecrow", wave3Locations.GetRandomElement()));

        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_EvilPumpkin", wave4Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_EvilPumpkin", wave4Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_EvilPumpkin", wave4Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_EvilPumpkin", wave4Locations.GetRandomElement()));
        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_EvilPumpkin", wave4Locations.GetRandomElement()));

        zombieWave3.zombies.Insert(SpawnInfected("WG_Infected_PumpkinBoss", "2407.497314 360.535278 7699.702148"));
    }
};