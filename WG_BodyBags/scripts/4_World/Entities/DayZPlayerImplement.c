modded class PlayerBase
{	
    string GetPlayerName()
    {
        auto identity = GetIdentity();
        if (!identity)
            return "John Doe";
        string name = GetIdentity().GetName();
        if (name == string.Empty)
            return "John Doe";
        return name;
    }

    override void EEKilled(Object killer)
    {
        super.EEKilled(killer);
        if (MapLinkShoudDelete()) //MapLink is going to handle deleting the body
             return;
        if (!IsPlayerDisconnected())
        {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CreateBodyBag, 2400);
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Delete, 3500);
        }
    }

	void CreateBodyBag()
	{		
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(CreateBodyBag);
		WG_BodyBag_Base bodybag = WG_BodyBag_Base.Cast(GetGame().CreateObjectEx("WG_WrappedBody", GetPosition(), ECE_PLACE_ON_SURFACE));
		bodybag.MoveAttachmentsFromEntity(this);
		bodybag.SetOrientation(GetOrientation());
		bodybag.SetLifetime(3600);
		bodybag.SetDisplayName(GetPlayerName());
	}
};