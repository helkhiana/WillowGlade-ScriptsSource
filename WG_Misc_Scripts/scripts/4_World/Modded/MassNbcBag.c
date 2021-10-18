modded class MassNBC_Bag extends Container_Base
{
	ref array<string> NBCCargo = {"NBCbootsBase", "NBCHoodBase", "NBCPantsBase", "NBCJacketBase","NBCGloves_ColorBase"};
	void MassNBC_Bag()
    {
        NBCCargo = {"NBCbootsBase", "NBCHoodBase", "NBCPantsBase", "NBCJacketBase","NBCGloves_ColorBase", "GasMask", "AirborneMask","GP5GasMask", "WG_Armored_GasMask_Base", };
    }
};