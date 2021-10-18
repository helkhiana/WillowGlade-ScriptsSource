class ActionHealBaseCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float effectivity = m_ActionData.m_MainItem.GetBandagingEffectivity();
		float adjusted_time_spent;
		if (effectivity > 0)
			adjusted_time_spent = UATimeSpent.BANDAGE / effectivity;
		m_ActionData.m_ActionComponent = new CAContinuousTime(adjusted_time_spent);
	}
};

class ActionHealBase: ActionContinuousBase
{	
	float m_MaxHealth = 0.0;
	void ActionHealBase()
	{
		m_CallbackClass = ActionHealBaseCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID = 0;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if(target)
		{
			PlayerBase target_player = PlayerBase.Cast(target.GetObject());
			if(target_player && target_player.IsAlive())
				return true;
		}
		if(player && player.IsAlive())
			return true;

		return false;		
	}
	

	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{	
		if( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			SetAnimation( item );
			
			return true;
		}
		
		return false;
	}
	
	void SetAnimation( ItemBase item )
	{
		switch( item.Type() )
		{
			case WG_AI2_Medkit:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SALINEBLOODBAG;
				break;
			case WG_ITS_Medkit:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGE;
				break;
			case WG_ITS_Surgicalkit:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGE;
				break;
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SALINEBLOODBAG;
				break;
		}
	}
	
	void ApplyMedkit(WG_Medkit_Base item, PlayerBase player )
	{	
		if (player)
		{
			m_MaxHealth = player.GetMaxHealth("GlobalHealth", "Health");	
			float m_CurrentHealth = player.GetHealth("GlobalHealth", "Health");		
			if (m_CurrentHealth < m_MaxHealth)
			{
				float healCost = item.GetKitHealCost();
				float itemQuant = item.GetQuantity();
				if (item.HasQuantity())
				{
					if(m_MaxHealth - m_CurrentHealth < healCost)
						healCost = m_MaxHealth - m_CurrentHealth;

					if(itemQuant < healCost)
						item.SetQuantity(0);
					else
						item.AddQuantity(-healCost);
				}
				else
				{
					item.Delete();
				}

				if(itemQuant < healCost)
					healCost = itemQuant;
				player.AddHealth("GlobalHealth", "Health", healCost );
				PluginTransmissionAgents m_mta = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
				m_mta.TransmitAgents(item, player, AGT_ITEM_TO_FLESH);
			}
		}
	}

	void TreatRadiation(WG_Medkit_Base item, PlayerBase player )
	{	
		if (player)
		{
			float healCost = item.GetKitHealCost();
			float itemQuant = item.GetQuantity();
			if (item.HasQuantity())
			{
				int count = player.GetSingleAgentCount(MedicalAttentionAgents.UNKNOWN_TOXINE) / 10;				
				if(count < healCost)
					healCost = count;

				if(itemQuant < healCost)
					item.SetQuantity(0);
				else
					item.AddQuantity(-healCost);
			}
			else
			{
				item.Delete();
			}

			if(itemQuant < healCost)
				healCost = itemQuant;
			healCost = healCost * 10;
			player.InsertAgent(MedicalAttentionAgents.UNKNOWN_TOXINE, -healCost);
		}
	}
	
	void TreatLimb(WG_Surgicalkit_Base item, PlayerBase player )
	{	
		if (player)
		{
			if (player.GetModifiersManager().IsModifierActive(eModifiers.MDF_BROKEN_LEGS))
			{			
				//player.GetModifiersManager().DeactivateModifier(eModifiers.MDF_BROKEN_ARMS);
				player.SetHealth("RightLeg","Health", 100);
				player.SetHealth("LeftLeg","Health", 100);
				item.AddQuantity(-1);
				return;
			}
			
			if (player.GetModifiersManager().IsModifierActive(eModifiers.MDF_BROKEN_ARMS))
			{
				player.GetModifiersManager().DeactivateModifier(eModifiers.MDF_BROKEN_ARMS);
				player.SetHealth("RightArm","Health",player.GetMaxHealth("RightArm","Health"));
				player.SetHealth("RightHand","Health",player.GetMaxHealth("RightHand","Health"));
				player.SetHealth("LeftArm","Health",player.GetMaxHealth("LeftArm","Health"));
				player.SetHealth("LeftHand","Health",player.GetMaxHealth("LeftHand","Health"));
				item.AddQuantity(-1);
				return;
			}		
		}
	}
};