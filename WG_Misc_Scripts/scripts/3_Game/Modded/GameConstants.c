modded class GameConstants
{
		// unit = currently percent (stamina max is 100)
	const int 	STAMINA_DRAIN_STANDING_SPRINT_PER_SEC = 2; //4
	const int 	STAMINA_DRAIN_CROUCHED_SPRINT_PER_SEC = 1; //1
	const int 	STAMINA_DRAIN_PRONE_SPRINT_PER_SEC = 1; //3
	const int	STAMINA_DRAIN_SWIM_FAST_PER_SEC = 3; //5
	const int	STAMINA_DRAIN_LADDER_FAST_PER_SEC = 5; //8
	
	const float	STAMINA_DRAIN_HOLD_BREATH = 0.1; //0.2
	const float	STAMINA_DRAIN_JUMP = 15;		// 25
	const float	STAMINA_DRAIN_VAULT = 10;		// 20
	const float	STAMINA_DRAIN_CLIMB = 20;		// 42
	const float	STAMINA_DRAIN_MELEE_LIGHT = 5; // 5
	const float	STAMINA_DRAIN_MELEE_HEAVY = 15; // 15
	const float	STAMINA_DRAIN_MELEE_EVADE = 8; // 8
		
	const int 	STAMINA_GAIN_JOG_PER_SEC = 4; //2
	const int 	STAMINA_GAIN_WALK_PER_SEC = 8; //4
	const int 	STAMINA_GAIN_IDLE_PER_SEC = 10; //5
	const int	STAMINA_GAIN_SWIM_PER_SEC = 3; //1
	const int	STAMINA_GAIN_LADDER_PER_SEC = 2; //1
	const float STAMINA_GAIN_BONUS_CAP = 3.0; //3
	
	const float STAMINA_KG_TO_STAMINAPERCENT_PENALTY = 0.4; //1.75
	const float STAMINA_MIN_CAP = 30; //5
	const float STAMINA_HOLD_BREATH_THRESHOLD = 10; // 10
	const float STAMINA_JUMP_THRESHOLD = 15; // 25
	const float STAMINA_VAULT_THRESHOLD = 10; // 20
	const float STAMINA_CLIMB_THRESHOLD = 20; // 42	
	const float STAMINA_REGEN_COOLDOWN_DEPLETION = 0.45; // in secs (how much time we will spend in cooldown before the stamina will starts with regeneration)
	const float STAMINA_REGEN_COOLDOWN_EXHAUSTION = 0.5;
	const float STAMINA_WEIGHT_LIMIT_THRESHOLD = 12000; //6000
	const float STAMINA_KG_TO_GRAMS = 1000; //for kg to g conversion
	const float STAMINA_SYNC_RATE = 1; //in secs
	const float STAMINA_MAX = 150;
};