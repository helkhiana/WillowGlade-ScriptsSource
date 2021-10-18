class CfgPatches
{
	class Fawkes_Server_Mod_Sounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Sounds_Effects"};
	};
};
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class powerGeneratorTurnOn_Soundshader: baseCharacter_SoundShader
	{
		range = 5;
		volume = 0.1;
	};
	class powerGeneratorTurnOff_Soundshader: baseCharacter_SoundShader
	{
		range = 5;
		volume = 0.1;
	};
	class powerGeneratorLoop_Soundshader: baseCharacter_SoundShader
	{
		range = 5;
		volume = 0.1;
	};
};
