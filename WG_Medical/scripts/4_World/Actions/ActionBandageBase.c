modded class ActionBandageBase: ActionContinuousBase
{
	override void ApplyBandage( ItemBase item, PlayerBase player )
	{	
		if (item.IsKindOf("WG_EmergencyBandage") && player.GetBleedingManagerServer() )
		{
			player.GetBleedingManagerServer().RemoveAllSourcesEx(item);	
			PluginTransmissionAgents m_mta = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
			m_mta.TransmitAgents(item, player, AGT_ITEM_TO_FLESH);
			
			if (item.HasQuantity())
			{
				item.AddQuantity(-1,true);
			}
			else
			{
				item.Delete();
			}
			return;
		}
		super.ApplyBandage(item, player);
	}
};

modded class BleedingSourcesManagerServer
{
	void RemoveAllSourcesEx(ItemBase item)
	{
		SetItem(item);
		RemoveAllSources();
	}
};