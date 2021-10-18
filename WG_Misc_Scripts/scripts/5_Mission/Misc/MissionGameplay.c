modded class MissionGameplay extends MissionBase
{
    override void OnEvent(EventType eventTypeId, Param params)
    {
        if (eventTypeId == ChatMessageEventTypeID)
        {
            ChatMessageEventParams chat_params = ChatMessageEventParams.Cast(params);
            if (m_LifeState == EPlayerStates.ALIVE)
            {
                string message = chat_params.param3;
                if (message.Contains("BattlEye Client: DayZ performs global maintenance every Wednesday"))
                    return;

                message.Replace("BattlEye Client: (Global) Admin:", "");
                message.Replace("BattlEye Client: (Private) Admin:", "(Private)");
                message.Replace("Game):(Global) Admin:", "");
                message.Replace("Game):(Private) Admin:", "(Private)");
                message.Replace("(Global) Admin:", "");
                message.Replace("(Private) Admin:", "(Private)");

                chat_params.param3 = message;
                m_Chat.Add(chat_params);
                return;
            }
        }
        super.OnEvent(eventTypeId, params);
    }

    override void PlayerControlDisable(int mode)
    {
        super.PlayerControlDisable(mode);

        if (mode == INPUT_EXCLUDE_INVENTORY)
        {
            GetUApi().ActivateExclude("inventory");
            GetUApi().GetInputByName("UAWalkRunTemp").ForceEnable(false);
            GetUApi().UpdateControls();
        }
    }
};