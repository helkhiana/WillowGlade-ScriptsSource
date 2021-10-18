enum TreeTypes
{
	NOFRUIT_TREE,
	APPLE_TREE,
	PEAR_TREE,
	PLUM_TREE,
	CANINA_BUSH,
	SAMBUCUS_BUSH
}

modded class WoodBase
{ 
	int GetTreeType()
	{
		if (this.GetType()=="TreeSoft_t_malusDomestica_1s" || this.GetType()=="TreeSoft_t_malusDomestica_2s" || this.GetType()=="TreeSoft_t_malusDomestica_3s")
		{
			return TreeTypes.APPLE_TREE;
		}
		if (this.GetType()=="TreeHard_t_pyrusCommunis_3sb" || this.GetType()=="TreeSoft_t_pyrusCommunis_2s" || this.GetType()=="TreeHard_t_pyrusCommunis_3s")
		{
			return TreeTypes.PEAR_TREE;
		}
		if (this.GetType()=="TreeHard_t_prunusDomestica_2s")
		{
			return TreeTypes.PLUM_TREE;
		}
		if (this.GetType()=="BushSoft_b_rosaCanina_1s" || this.GetType()=="BushSoft_b_rosaCanina_2s")
		{
			return TreeTypes.CANINA_BUSH;
		}
		if (this.GetType()=="BushSoft_b_sambucusNigra_1s" || this.GetType()=="BushHard_b_sambucusNigra_2s")
		{
			return TreeTypes.SAMBUCUS_BUSH;
		}
		return TreeTypes.NOFRUIT_TREE;
	}
	
	string GetFruitType()
	{
		int treeType = GetTreeType();
		string fruit;
		switch(treeType)
		{
			case TreeTypes.APPLE_TREE:
				fruit = "Apple";
				break;
			case TreeTypes.PEAR_TREE:
				fruit = "Pear";
				break;
			case TreeTypes.PLUM_TREE:
				fruit = "Plum";
				break;
			case TreeTypes.CANINA_BUSH:
				fruit = "CaninaBerry";
				break;
			case TreeTypes.SAMBUCUS_BUSH:
				fruit = "SambucusBerry";
				break;
		}
		return fruit;
	}
};