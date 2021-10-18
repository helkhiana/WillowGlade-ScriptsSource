/* modded class PlayerBase
{
    float m_UiUpdateTimer = 0;
	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);

        if (m_UiUpdateTimer >= 1)
		{   
            Print(">>>>>>>>>>>>>>>>>>>>>>");
            Print("RightLeg " + GetHealth("RightLeg","Health"));
            Print("RightFoot " + GetHealth("RightFoot","Health"));
            Print("LeftLeg " + GetHealth("LeftLeg","Health"));
            Print("LeftFoot " + GetHealth("LeftFoot","Health"));
            Print("RightArm " + GetHealth("RightArm","Health"));
            Print("RightHand " + GetHealth("RightHand","Health"));
            Print("LeftArm " + GetHealth("LeftArm","Health"));
            Print("LeftHand " + GetHealth("LeftHand","Health"));
            Print("Torso " + GetHealth("Torso","Health"));
            Print("----------------------");
			m_UiUpdateTimer = 0;
		}
		else
		{
			m_UiUpdateTimer += deltaTime;
		}
	}
}; */