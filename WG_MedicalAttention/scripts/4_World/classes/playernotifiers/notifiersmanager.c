enum MedicalAttentionNotifiers
{
	NTF_POISONED = 30,
	NTF_FRACTURE = 31
}

modded class NotifiersManager
{
	void NotifiersManager(PlayerBase player)
	{
		m_Notifiers.Insert(new PoisonedNotfr(this));
		m_Notifiers.Insert(new FractureNotfr(this));
	}
}