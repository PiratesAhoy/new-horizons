void InitCharactersTables()
{
	InitReputationTable();
	InitMoraleTable();
}

void InitReputationTable()
{
    ReputationTable[REPUTATIONT_HORROR]   = "Horror of the High Seas";
    ReputationTable[REPUTATIONT_BASTARD]  = "Bloody Terror";
    ReputationTable[REPUTATIONT_SWINDLER] = "Swindler";
    ReputationTable[REPUTATIONT_RASCAL]   = "Rascal";
    ReputationTable[REPUTATIONT_NEUTRAL]  = "Neutral";
    ReputationTable[REPUTATIONT_PLAIN]    = "Bloke";
    ReputationTable[REPUTATIONT_GOOD]     = "Matey";
    ReputationTable[REPUTATIONT_VERYGOOD] = "Dashing";
    ReputationTable[REPUTATIONT_HERO]     = "Hero";
}

void InitMoraleTable()
{
	MoraleTable[MORALET_TREACHEROUS]	= "Treacherous";
	MoraleTable[MORALET_AWFUL]			= "Awful";
	MoraleTable[MORALET_LOW]			= "Low";
	MoraleTable[MORALET_POOR]			= "Poor";
	MoraleTable[MORALET_NORMAL]			= "Normal";
	MoraleTable[MORALET_ELATED]			= "Elated";
	MoraleTable[MORALET_GOOD]			= "Good";
	MoraleTable[MORALET_HIGH]			= "High";
	MoraleTable[MORALET_EXCELLENT]		= "Excellent";
	MoraleTable[MORALET_HEROIC]			= "Heroic";
}
