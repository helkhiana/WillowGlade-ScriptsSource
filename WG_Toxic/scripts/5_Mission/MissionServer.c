modded class MissionServer
{
    ref array<ref vector> m_ToxicParticlesChernarus = 
    {
		Vector(1660.05, 451.753174, 14362.29),
		Vector(1811.86, 449.522156, 14249.54),
		Vector(1558.28, 452.769989, 14066.50),
		Vector(1721.75, 445.441315, 13882.53),
		Vector(1340.24, 463.932831, 14049.60),
		Vector(1058.68, 470.137817, 13907.31),
		Vector(878.769043, 454.951660, 14739.072266),
		Vector(1018.268860, 454.017700, 14613.446289),
		Vector(1334.71, 458.099701, 14480.69),
		Vector(1870.52, 432.152893, 13778.73),
		Vector(1510.25, 439.791687, 13603.59),
        Vector(1688.11, 451.73, 14141.38),
		Vector(1764.74, 450.321228, 14057.13),
		Vector(13429.492188, 71.237122, 3343.250000),
		Vector(13641.367188, 44.518913, 2955.639893),
		Vector(13936.163086, 28.333252, 2952.457275),
		Vector(13978.049805, 10.060272, 2747.935303),
		Vector(14082.056641, 19.467220, 2838.911865),
		Vector(13611.362305, 31.558960, 2836.078125),
		Vector(13392.367188, 0.269660, 2952.312988),
		Vector(13437.052734, 0.729430, 2968.862305),
		Vector(14134.108398, 4.221999, 2661.209229),
		Vector(13072.851563, 19.659235, 3212.335449),
		Vector(13341.083984, 38.153645, 3138.496338),
		Vector(13881.676758, 0.539658, 3277.900635),
		Vector(13604.361328, 11.611671, 3402.837891),
		Vector(2713.637695, 1.288130, 1473.307739),
		Vector(2842.103271, 0.668265, 1121.446533),
		Vector(2682.881104, 0.247844, 1310.377441),
		Vector(2614.211182, 51.447468, 1270.527954),
		Vector(2815.347412, 17.248125, 1258.902832),
		Vector(2739.290039, 14.523502, 1175.379639),
		Vector(2537.348633, 0.568138, 1405.158691)
    };
	
    ref array<ref vector> m_ToxicParticlesNamalsk = 
    {
		Vector(12010.904297, 4.133188, 11681.297852),
		Vector(11929.911133, 4.133188, 11762.264648),
		Vector(11975.961914, 41.238708, 11718.291016),
		Vector(11360.629883, 4.133188, 12217.510742),
		Vector(11361.981445, 3.419156, 12315.397461),
		Vector(11358.608398, 31.039398, 12280.176758),
		Vector(4988.829590, 21.298729, 6614.174805)
    };

	override void OnInit()
	{
		super.OnInit();
        SpawnParticles();
    }
    
    void SpawnParticles()
	{	
		if ( g_Game.GetWorldName() == "chernarus")
		{
			foreach(vector area : m_ToxicParticlesChernarus)
			{
				GetGame().CreateObjectEx("ToxicSmoke", area, ECE_PLACE_ON_SURFACE);
			}
		}
		else if ( g_Game.GetWorldName() == "namalsk")
		{
			foreach(vector namalskArea : m_ToxicParticlesNamalsk)
			{
				GetGame().CreateObjectEx("ToxicCloud_Square", namalskArea, ECE_PLACE_ON_SURFACE);
			}
		}
	}
};