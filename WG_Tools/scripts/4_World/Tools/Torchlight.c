class WG_Torchlight: Flashlight
{
	string 	LIGHT_BEAM_START = "beamStart";
	string 	LIGHT_BEAM_END = "beamEnd";
	
	override void OnWorkStart()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			m_Light = FlashlightLight.Cast(  ScriptedLightBase.CreateLight(FlashlightLight, "0 0 0", 0.08)  ); // Position is zero because light is attached on parent immediately.
			m_Light.AttachOnMemoryPoint(this, LIGHT_BEAM_START, LIGHT_BEAM_END);
		}
		
		SetObjectMaterial(GLASS_ID, LIGHT_ON_GLASS);
		SetObjectMaterial(REFLECTOR_ID, LIGHT_ON_REFLECTOR);
	}

    override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
    {
        super.EEItemLocationChanged(oldLoc, newLoc);
        InventoryLocationType type = newLoc.GetType();

		if (newLoc.GetType() == InventoryLocationType.HANDS)
		{
			LIGHT_BEAM_START = "handsbeamstart";
			LIGHT_BEAM_END = "handsbeamend";
			if(m_Light)
				m_Light.AttachOnMemoryPoint(this, LIGHT_BEAM_START, LIGHT_BEAM_END);
			SetAnimationPhase( "hands" , 0 );
			SetAnimationPhase( "inventory" , 1 );
		}
		else
		{
			SetAnimationPhase( "hands" , 1 );
			SetAnimationPhase( "inventory" , 0 );		
			LIGHT_BEAM_START = "beamStart";
			LIGHT_BEAM_END = "beamEnd";
			if(m_Light)
				m_Light.AttachOnMemoryPoint(this, LIGHT_BEAM_START, LIGHT_BEAM_END);
		}
		
    }
};