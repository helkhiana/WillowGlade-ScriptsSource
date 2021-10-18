modded class ActionSkinning extends ActionContinuousBase
{
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);

        if (action_data.m_Target) 
        {
            EntityAI body;
            Class.CastTo(body, action_data.m_Target.GetObject());
            
            ItemBase added_item;
            vector pos_rnd = body.GetPosition() + Vector(Math.RandomFloat01() - 0.5, 0, Math.RandomFloat01() - 0.5);
            if (body.IsKindOf("WG_Infected_ToxicPumpkin") && Math.RandomIntInclusive(0, 100) < 50)
            {
                Class.CastTo(added_item, GetGame().CreateObject("WG_PumpkinHelmet_Toxic", pos_rnd, false));
                added_item.PlaceOnSurface();
                return;
            }
            if (body.IsKindOf("WG_Infected_EvilPumpkin") && Math.RandomIntInclusive(0, 100) < 50)
            {
                Class.CastTo(added_item, GetGame().CreateObject("WG_PumpkinHelmet_Evil", pos_rnd, false));
                added_item.PlaceOnSurface();
                return;
            }
            if (body.IsKindOf("ZombieBase") && Math.RandomIntInclusive(0, 100) > 70 && !body.IsKindOf("WG_Infected_ToxicPumpkin") && !body.IsKindOf("WG_Infected_EvilPumpkin"))
            {
                Class.CastTo(added_item, GetGame().CreateObject("HumanSkull", pos_rnd, false));
                added_item.PlaceOnSurface();
            }
        }
    }
};