modded class MissionServer
{
    Building SpawnObjectHE( string type, vector position, vector orientation )
    {
        Building obj = Building.Cast(GetGame().CreateObject( type, position ));
        if(!obj)
        {
            Print("ERROR: " + type + " at pos " + position + " couldn't be created");
            return obj;
        }
        obj.SetPosition( position );
        obj.SetOrientation( orientation );
        obj.SetOrientation( obj.GetOrientation() ); //Collision fix
        obj.Update();
        obj.SetAffectPathgraph( true, false );
        if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
        return obj;
    };

    float he_timeslice = 0;
    float hedead_timeslice = 0;
	override void OnUpdate(float timeslice)
	{
        super.OnUpdate(timeslice);
        //timeslice is in seconds?
        if (he_timeslice >= 10)
		{
            he_timeslice = 0;
            if(g_Game.GetShouldCheckHE())
            {
                if(g_Game.GetHalloweenEvent().OnUpdate())
                {
                    Print("[WG_DEBUG][Halloween] - Ending Halloween event");
                    g_Game.StopHalloweenEvent();
                }
            }
		}
		else
		{
			he_timeslice += timeslice;
		}
        if (hedead_timeslice >= 30)
		{
            hedead_timeslice = 0;
            if(g_Game.GetShouldCheckHEDeadBodies())
            {
                g_Game.BringPlayersBackAfterEventDueToDeath();
            }
		}
		else
		{
			hedead_timeslice += timeslice;
		}
	}
/* 
	override void OnInit()
	{
		super.OnInit();
        SpawnObjectHE("MMO_CemeteryFence_DoubleGate_RegisterArea", "2242.853027 348.463348 7835.941895", "-72.000031 0.000000 -1.000000");

    } */
};