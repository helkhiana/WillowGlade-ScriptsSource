modded class PowerGenerator extends ItemBase
{
	// Adds energy to the generator
	void SetFuel(float fuel_amount)
	{
		if (m_FuelTankCapacity > 0)
		{
			m_FuelToEnergyRatio = GetCompEM().GetEnergyMax() / m_FuelTankCapacity;
			GetCompEM().SetEnergy(fuel_amount * m_FuelToEnergyRatio);
			m_FuelPercentage = GetCompEM().GetEnergy0To100();
            SetQuantity(m_FuelPercentage);
			SetSynchDirty();
			UpdateFuelMeter();
		}
		else
		{
			string error = "ERROR! Item " + this.GetType() + " has fuel tank with 0 capacity! Add parameter 'fuelTankCapacity' to its config and set it to more than 0!";
			DPrint(error);
		}
	}
};