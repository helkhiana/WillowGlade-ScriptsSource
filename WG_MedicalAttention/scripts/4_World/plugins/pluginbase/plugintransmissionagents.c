modded class PluginTransmissionAgents
{
	void PluginTransmissionAgents()
	{
		RegisterAgent(new TirednessAgent);
		RegisterAgent(new AlcoholAgent);
	}
}