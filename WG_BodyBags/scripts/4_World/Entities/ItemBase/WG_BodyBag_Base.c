class WG_BodyBag_Base extends Inventory_Base
{
	protected bool m_ReceivedAttachments;
	protected string m_DisplayName = "Wrapped Body";
    protected int m_FliesIndex = -1;

	protected ref EffectParticle m_FliesEffect;
	protected ref EffectSound m_SoundFliesEffect;

    void WG_BodyBag_Base()
	{
		RegisterNetSyncVariableBool("m_ReceivedAttachments");
	}

    override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if (!m_ReceivedAttachments)
			return;

		if (!m_FliesEffect)
			m_FliesEffect = new EffSwarmingFlies();

		if (m_FliesEffect && !SEffectManager.IsEffectExist(m_FliesIndex))
		{
			m_FliesEffect.SetDecalOwner(this);
			m_FliesIndex = SEffectManager.PlayOnObject(m_FliesEffect, this, "0 0.25 0");

			Particle part = m_FliesEffect.GetParticle();
			AddChild(part, -1);

			if (!m_SoundFliesEffect)
				PlaySoundSetLoop(m_SoundFliesEffect, "Flies_SoundSet", 1.0, 1.0);
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if (m_FliesEffect)
			m_FliesEffect.Stop();

		if (m_SoundFliesEffect)
			StopSoundSet(m_SoundFliesEffect);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;

		if (!ctx.Read(m_ReceivedAttachments))
			return false;
		if (!ctx.Read(m_DisplayName))
			return false;

		return true;
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);

		ctx.Write(m_ReceivedAttachments);
		ctx.Write(m_DisplayName);
	}

    override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

    override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	void MoveAttachmentsFromEntity(EntityAI entity)
	{
		for (int i = 0; i < entity.GetInventory().GetAttachmentSlotsCount(); i++)
		{
			int slot = entity.GetInventory().GetAttachmentSlotId(i);
			EntityAI item = entity.GetInventory().FindAttachment(slot);

			if (item)
			{
				float health;

				if (GetGame().IsServer())
				{
					health = item.GetHealth();
					item.SetHealth(item.GetMaxHealth());
				}

				if (GetInventory().CanAddAttachment(item))
				{
					if (GetGame().IsMultiplayer())
						entity.ServerTakeEntityToTargetInventory(this, FindInventoryLocationType.ATTACHMENT, item);
					else
						entity.LocalTakeEntityToTargetInventory(this, FindInventoryLocationType.ATTACHMENT, item);
				}
				else
				{
					if (GetGame().IsMultiplayer())
						entity.GetInventory().DropEntity(InventoryMode.SERVER, entity, item);
					else
						entity.GetInventory().DropEntity(InventoryMode.LOCAL, entity, item);
				}

				if (GetGame().IsServer())
					item.SetHealth(health);
			}
		}

		m_ReceivedAttachments = true;
		SetSynchDirty();
	}

	void SetDisplayName(string name)
	{
		m_DisplayName = name + "'s Wrapped Body";
	}

	override string GetDisplayName()
	{
		return m_DisplayName;
	}
};

class WG_WrappedBody : WG_BodyBag_Base {};