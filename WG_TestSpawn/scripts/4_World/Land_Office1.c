static void SpawnObjectF( string type, vector position, vector orientation )
{
    auto obj = GetGame().CreateObject( type, position );
    if(!obj)
    {
        Print("ERROR: " + type + " at pos " + position + " couldn't be created");
        return;
    }
    obj.SetPosition( position );
    obj.SetOrientation( orientation );
    obj.SetOrientation( obj.GetOrientation() ); //Collision fix
    obj.Update();
    obj.SetAffectPathgraph( true, false );
    if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
};
/*
class Land_Office1 : Building
{
    ref TStringVectorMap buildingOffset = new TStringVectorMap;
    void Land_Office1()
    {        
        buildingOffset.Insert("-1.173136 0.342586 4.749771", "0.000000 0.000000 0.000000");
        buildingOffset.Insert("2.566906 -2.213092 2.888520", "-178.998901 0.000000 0.000000");
        buildingOffset.Insert("-8.258841 -2.160818 5.150159", "-84.999710 0.000000 0.000000");
        buildingOffset.Insert("10.878991 -2.163091 -2.942304", "90.000000 0.000000 0.000000");
        buildingOffset.Insert("-15.969541 -4.650625 -2.520280", "-90.000000 0.000000 0.000000");
        buildingOffset.Insert("9.283063 -4.656859 2.887208", "-179.999893 0.000000 0.000000");
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater(GetEventObjectPositions, 1000, false);
    }

    void GetEventObjectPositions()
    {
        Print("Land_Office1");
        foreach(auto posOffset, auto relativeOrientation : buildingOffset)
        {
            auto worldPos = ModelToWorld(posOffset.ToVector());
            auto worldYaw = GetDirection().Normalized().VectorToAngles()[0] + relativeOrientation[0];

            if(worldYaw > 360) worldYaw -= 360;
            if(worldYaw < 0) worldYaw += 360;

            vector relativeOffsetOri1 = GetOrientation() + relativeOrientation;
            if(relativeOffsetOri1[0] > 360) relativeOffsetOri1[0] = relativeOffsetOri1[0] - 360;
            if(relativeOffsetOri1[0] < 0) relativeOffsetOri1[0] = relativeOffsetOri1[0] + 360;            
            Print("\"" + worldPos[0] + " " + worldPos[1] + " " + worldPos[2] + "|" + relativeOffsetOri1[0] + " 0 0\",");
        }
    }
};


class Land_Office2 : Building
{
    ref TStringVectorMap buildingOffset = new TStringVectorMap;
    void Land_Office2()
    {        
        buildingOffset.Insert("7.001063 -8.28 -1.776474", "89.999626 0.000000 0.000000");
        buildingOffset.Insert("15.682755 -8.28 3.856124", "-179.999893 0.000000 0.000000");
        buildingOffset.Insert("-2.867975 -2.89 -2.064133", "92.999664 0.000000 0.000000");
        buildingOffset.Insert("5.166742 -2.89 4.807774", "-176.999680 0.000000 0.000000");
        buildingOffset.Insert("0.911041 -0.17 4.071782", "0.999997 0.000000 0.000000");
        buildingOffset.Insert("17.527613 -0.17 0.952965", "-179.999893 0.000000 0.000000");
        buildingOffset.Insert("-15.878058 5.29 2.185567", "90.000000 0.000000 0.000000");
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater(GetEventObjectPositions, 1000, false);
    }

    void GetEventObjectPositions()
    {
        Print("Land_Office2");
        foreach(auto posOffset, auto relativeOrientation : buildingOffset)
        {
            auto worldPos = ModelToWorld(posOffset.ToVector());
            auto worldYaw = GetDirection().Normalized().VectorToAngles()[0] + relativeOrientation[0];

            if(worldYaw > 360) worldYaw -= 360;
            if(worldYaw < 0) worldYaw += 360;

            vector relativeOffsetOri1 = GetOrientation() + relativeOrientation;
            if(relativeOffsetOri1[0] > 360) relativeOffsetOri1[0] = relativeOffsetOri1[0] - 360;
            if(relativeOffsetOri1[0] < 0) relativeOffsetOri1[0] = relativeOffsetOri1[0] + 360;            
            Print("\"" + worldPos[0] + " " + worldPos[1] + " " + worldPos[2] + "|" + relativeOffsetOri1[0] + " 0 0\",");
        }
    }
};


class Land_City_School : Building
{
    ref TStringVectorMap buildingOffset = new TStringVectorMap;
    void Land_City_School()
    {        
        buildingOffset.Insert("-12.593456 -4.956 4.456938", "0.000000 0.000000 0.000000");
        buildingOffset.Insert("-11.859852 -4.956 12.933338", "90.000000 0.000000 0.000000");
        buildingOffset.Insert("-18.410006 1.295786 5.413284", "-177.999908 0.000000 0.000000");
        buildingOffset.Insert("-0.502555 1.295786 -15.923458", "90.000000 0.000000 0.000000");
        buildingOffset.Insert("7.859360 1.295786 -18.560780", "90.000000 0.000000 0.000000");
        buildingOffset.Insert("16.524349 1.295786 -16.967760", "-90.000000 0.000000 0.000000");
        buildingOffset.Insert("-8.817369 1.295786 -14.367993", "90.000000 0.000000 0.000000");
        buildingOffset.Insert("-13.216402 1.295786 -2.911696", "-179.999893 0.000000 0.000000");
        buildingOffset.Insert("-17.385092 1.295786 20.820652", "0.000000 0.000000 0.000000");
        buildingOffset.Insert("16.542744 -1.804214 -14.498000", "-90.000000 0.000000 0.000000");
        buildingOffset.Insert("7.888240 -1.804214 -11.071084", "90.000000 0.000000 0.000000");
        buildingOffset.Insert("-7.949560 -1.804214 -13.933361", "-90.000000 0.000000 0.000000");
        buildingOffset.Insert("-10.290223 -1.804214 -19.845955", "-179.999893 0.000000 0.000000");
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater(GetEventObjectPositions, 1000, false);
    }

    void GetEventObjectPositions()
    {
        Print("Land_City_School");
        foreach(auto posOffset, auto relativeOrientation : buildingOffset)
        {
            auto worldPos = ModelToWorld(posOffset.ToVector());
            auto worldYaw = GetDirection().Normalized().VectorToAngles()[0] + relativeOrientation[0];

            if(worldYaw > 360) worldYaw -= 360;
            if(worldYaw < 0) worldYaw += 360;

            vector relativeOffsetOri1 = GetOrientation() + relativeOrientation;
            if(relativeOffsetOri1[0] > 360) relativeOffsetOri1[0] = relativeOffsetOri1[0] - 360;
            if(relativeOffsetOri1[0] < 0) relativeOffsetOri1[0] = relativeOffsetOri1[0] + 360;            
            Print("\"" + worldPos[0] + " " + worldPos[1] + " " + worldPos[2] + "|" + relativeOffsetOri1[0] + " 0 0\",");
        }
    }
};

*/


class Land_Village_PoliceStation : Building
{
    ref TStringVectorMap buildingOffset = new TStringVectorMap;
    void Land_Village_PoliceStation()
    {        
        buildingOffset.Insert("-1.556099 -6.08 7.041063", "0.000000 0.000000 0.000000" );
        buildingOffset.Insert("-6.367188 -6.08 4.110000", "-179.999893 0.000000 0.000000" );
        buildingOffset.Insert("-5.756833 -2.47 4.110000", "-179.999893 0.000000 0.000000" ); 
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater(GetEventObjectPositions, 1000, false);
    }

    void GetEventObjectPositions()
    {
        Print("Land_Village_PoliceStation");
        foreach(auto posOffset, auto relativeOrientation : buildingOffset)
        {
            auto worldPos = ModelToWorld(posOffset.ToVector());
            auto worldYaw = GetDirection().Normalized().VectorToAngles()[0] + relativeOrientation[0];

            if(worldYaw > 360) worldYaw -= 360;
            if(worldYaw < 0) worldYaw += 360;

            vector relativeOffsetOri1 = GetOrientation() + relativeOrientation;
            if(relativeOffsetOri1[0] > 360) relativeOffsetOri1[0] = relativeOffsetOri1[0] - 360;
            if(relativeOffsetOri1[0] < 0) relativeOffsetOri1[0] = relativeOffsetOri1[0] + 360;            
            Print("\"" + worldPos[0] + " " + worldPos[1] + " " + worldPos[2] + "|" + relativeOffsetOri1[0] + " 0 0\",");
        }
    }
};


class Land_Church2_1 : Building
{
    ref TStringVectorMap buildingOffset = new TStringVectorMap;
    void Land_Church2_1()
    {        
        buildingOffset.Insert("0.020638 -11.090872 7.413466", "0.000000 0.000000 0.000000" );
        buildingOffset.Insert("-0.587280 -11.090872 -5.280000", "-179.999893 0.000000 0.000000" );
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater(GetEventObjectPositions, 1000, false);
    }

    void GetEventObjectPositions()
    {
        Print("Land_Church2_1");
        foreach(auto posOffset, auto relativeOrientation : buildingOffset)
        {
            auto worldPos = ModelToWorld(posOffset.ToVector());
            auto worldYaw = GetDirection().Normalized().VectorToAngles()[0] + relativeOrientation[0];

            if(worldYaw > 360) worldYaw -= 360;
            if(worldYaw < 0) worldYaw += 360;

            vector relativeOffsetOri1 = GetOrientation() + relativeOrientation;
            if(relativeOffsetOri1[0] > 360) relativeOffsetOri1[0] = relativeOffsetOri1[0] - 360;
            if(relativeOffsetOri1[0] < 0) relativeOffsetOri1[0] = relativeOffsetOri1[0] + 360;            
            Print("\"" + worldPos[0] + " " + worldPos[1] + " " + worldPos[2] + "|" + relativeOffsetOri1[0] + " 0 0\",");
        }
    }
};


class Land_Church2_2 : Building
{
    ref TStringVectorMap buildingOffset = new TStringVectorMap;
    void Land_Church2_2()
    {        
        buildingOffset.Insert("0.020638 -11.587128 7.413466", "0.000000 0.000000 0.000000" );
        buildingOffset.Insert("-0.587280 -11.587128 -5.280000", "-179.999893 0.000000 0.000000" );
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater(GetEventObjectPositions, 1000, false);
    }

    void GetEventObjectPositions()
    {
        Print("Land_Church2_2");
        foreach(auto posOffset, auto relativeOrientation : buildingOffset)
        {
            auto worldPos = ModelToWorld(posOffset.ToVector());
            auto worldYaw = GetDirection().Normalized().VectorToAngles()[0] + relativeOrientation[0];

            if(worldYaw > 360) worldYaw -= 360;
            if(worldYaw < 0) worldYaw += 360;

            vector relativeOffsetOri1 = GetOrientation() + relativeOrientation;
            if(relativeOffsetOri1[0] > 360) relativeOffsetOri1[0] = relativeOffsetOri1[0] - 360;
            if(relativeOffsetOri1[0] < 0) relativeOffsetOri1[0] = relativeOffsetOri1[0] + 360;            
            Print("\"" + worldPos[0] + " " + worldPos[1] + " " + worldPos[2] + "|" + relativeOffsetOri1[0] + " 0 0\",");
        }
    }
};