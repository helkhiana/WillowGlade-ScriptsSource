modded class ActionSkinning extends ActionContinuousBase
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);

        if (action_data.m_Target) 
        {
            EntityAI body;
            Class.CastTo(body, action_data.m_Target.GetObject());
            
            ItemBase headdress;
            vector pos_rnd = body.GetPosition() + Vector(Math.RandomFloat01() - 0.5, 0, Math.RandomFloat01() - 0.5);
            if (body.IsKindOf("Animal_CanisLupus") && Math.RandomIntInclusive(0, 100) < 30)
            {
                Class.CastTo(headdress, GetGame().CreateObject("Wolf_Headdress", pos_rnd, false));
                headdress.PlaceOnSurface();
                return;
            }
            if (body.IsKindOf("Animal_UrsusArctos") && Math.RandomIntInclusive(0, 100) < 50)
            {
                Class.CastTo(headdress, GetGame().CreateObject("Bear_Headdress", pos_rnd, false));
                headdress.PlaceOnSurface();
                return;
            }
        }
    }
};