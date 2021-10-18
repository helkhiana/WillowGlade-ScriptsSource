class EmoteViewNote extends EmoteBase
{
	void EmoteViewNote()
	{
		m_ID = EmoteConstants.ID_EMOTE_VIEWNOTE;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
		m_StanceMaskFullbody = 0;
		m_AdditiveCallbackUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}
};
class EmoteGiveR extends EmoteBase
{
	void EmoteGiveR()
	{
		m_ID = EmoteConstants.ID_EMOTE_GIVER;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = 0;
		m_AdditiveCallbackUID = DayZPlayerConstants.CMD_ACTIONFB_GIVER;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}
};
class EmoteGiveL extends EmoteBase
{
	void EmoteGiveL()
	{
		m_ID = EmoteConstants.ID_EMOTE_GIVEL;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = 0;
		m_AdditiveCallbackUID = DayZPlayerConstants.CMD_ACTIONFB_GIVEL;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}
};
class EmoteSearchInventory extends EmoteBase
{
	void EmoteSearchInventory()
	{
		m_ID = EmoteConstants.ID_EMOTE_SEARCHINVENTORY;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = 0;
		m_AdditiveCallbackUID = DayZPlayerConstants.CMD_ACTIONMOD_SEARCHINVENTORY;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}
};
class EmoteCrafting extends EmoteBase
{
	void EmoteCrafting()
	{
		m_ID = EmoteConstants.ID_EMOTE_CRAFTING;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_AdditiveCallbackUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullbodyCallbackUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_HideItemInHands = false;
	}
};
class EmoteFishing extends EmoteBase
{
	void EmoteFishing()
	{
		m_ID = EmoteConstants.ID_EMOTE_FISHING;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_AdditiveCallbackUID = DayZPlayerConstants.CMD_ACTIONFB_FISHING;
		m_FullbodyCallbackUID = DayZPlayerConstants.CMD_ACTIONFB_FISHING;
		m_HideItemInHands = false;
	}
};

modded class EmoteConstructor
{
	void RegisterEmotes(TTypenameArray emotes)
	{
		super.RegisterEmotes(emotes);
		emotes.Insert(EmoteGiveR);
		emotes.Insert(EmoteGiveL);
		emotes.Insert(EmoteSearchInventory);
		emotes.Insert(EmoteCrafting);
		emotes.Insert(EmoteFishing);
		emotes.Insert(EmoteViewNote);
	}
};

modded class EmoteManager
{
	override bool PlayEmote(int id)
	{
		if (!CanPlayEmote(id))
		{
			m_Player.SetInventorySoftLock(false);
			return false;
		}

		actionDebugPrint("[emote] " + Object.GetDebugName(m_Player) + " play emote id=" + id + " IH=" + Object.GetDebugName(m_Player.GetItemInHands()));

		m_PreviousGestureID = m_CurrentGestureID;
		m_CurrentGestureID = id;
		ref SymptomBase symptomCustom;
		switch (id)
		{
			case EmoteConstants.ID_EMOTE_SHIVER:
				if (m_Player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer())
				{
					symptomCustom = m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_FREEZE);
					if (symptomCustom)
						symptomCustom.SetDuration(Math.RandomIntInclusive(4, 8));
				}
				break;

			case EmoteConstants.ID_EMOTE_HOT:
				if (m_Player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer())
				{
					symptomCustom = m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_HOT);
					if (symptomCustom)
						symptomCustom.SetDuration(Math.RandomIntInclusive(4, 8));
				}
				break;

			case EmoteConstants.ID_EMOTE_COUGH:
				if (m_Player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer())
				{
					symptomCustom = m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
					if (symptomCustom)
						symptomCustom.SetDuration(Math.RandomIntInclusive(4, 8));
				}
				break;

			case EmoteConstants.ID_EMOTE_SNEEZE:
				if (m_Player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer())
				{
					symptomCustom = m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_SNEEZE);
					if (symptomCustom)
						symptomCustom.SetDuration(Math.RandomIntInclusive(4, 8));
				}
				break;

			case EmoteConstants.ID_EMOTE_UNCONSCIOUS:
				if (m_Player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer())
				{
					symptomCustom = m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_UNCONSCIOUS);
					if (symptomCustom)
						symptomCustom.SetDuration(Math.RandomIntInclusive(4, 8));
				}
				break;

			case EmoteConstants.ID_EMOTE_LAUGHTER:
				if (m_Player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer())
				{
					symptomCustom = m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_LAUGHTER);
					if (symptomCustom)
						symptomCustom.SetDuration(Math.RandomIntInclusive(4, 8));
				}
				break;
		}

		if (m_bEmoteIsPlaying)
		{
			m_Player.SetInventorySoftLock(true);
			if (m_Callback.m_IsFullbody)
				SetEmoteLockState(true);
		}
		if (symptomCustom)
			return true;
		else
			return super.PlayEmote(id);

		return false;
	}
};