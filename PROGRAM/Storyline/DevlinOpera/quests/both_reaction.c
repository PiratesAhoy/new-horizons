void BothQuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld;
	PChar = GetMainCharacter();

	switch(sQuestName)
	{
//============================== OFFICERS =================================
//==============================================================================

		case "Lorena_hire":
			Characters[GetCharacterIndex("Lorena Lopez")].dialog.Filename = "Enc_Officer_dialog.c"; // PB
			Characters[GetCharacterIndex("Lorena Lopez")].dialog.CurrentNode = "hired";

			AddPassenger(Pchar, characterFromID("Lorena Lopez"), 0);
			LAi_SetOfficerType(CharacterFromID("Lorena Lopez"));
		break;

//============================== TAVERN PUZZLE =================================
//==============================================================================

		case "Puzzle_start":
			Pchar.quest.Puzzle_start.over = "yes";
			PlaySound("INTERFACE\key_lock.wav")
			Locations[FindLocation("Puzzle_tavern")].reload.l1.disable = true;

			pchar.quest.JOHNNYJACKSON = "thirsty";
			pchar.quest.JACKIEJOHNSON = "thirsty";
			pchar.quest.JUNGLEJULIA = "thirsty";
			pchar.quest.MARGRITEUGSTER = "thirsty";
			pchar.quest.FINSTOCK = "thirsty";
			pchar.quest.ANNESHIRLEY = "thirsty";
			pchar.quest.PRIVATEPYLE = "thirsty";
			pchar.quest.KURTKRAUTWURM = "thirsty";
			pchar.quest.MONSIEURMONDO = "thirsty";
			pchar.quest.CHIEFCUNNINGFROG = "thirsty";
			pchar.quest.GEORGGEHEIM = "thirsty";
			pchar.quest.TORSTENSTORENFRIED = "thirsty";
			pchar.quest.CONTESSACALZONE = "thirsty";
			pchar.quest.DONKEYKONG = "thirsty";
			pchar.quest.CHEYENNE = "thirsty";
			pchar.quest.SALLYSLOOP = "thirsty";
			pchar.quest.BORGENFECK = "thirsty";
			pchar.quest.BIONICLEBILL = "thirsty";
			pchar.quest.LIESELOTTE = "thirsty";
			pchar.quest.BORNHOWLER = "thirsty";
			pchar.quest.FATHERFERDINAND = "thirsty";
		break;

		case "Tavern_death":
			PauseAllSounds();
			LAi_KillCharacter(Pchar);
		break;

//---------------------------------

		case "JohnnyJackson_solved":
			pchar.quest.JOHNNYJACKSON = "drunk";

                        if (CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "JackieJohnson_solved":
			pchar.quest.JACKIEJOHNSON = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "JungleJulia_solved":
			pchar.quest.JUNGLEJULIA = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "MargritEugster_solved":
			pchar.quest.MARGRITEUGSTER = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "Finstock_solved":
			pchar.quest.FINSTOCK = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "AnneShirley_solved":
			pchar.quest.ANNESHIRLEY = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "PrivatePyle_solved":
			pchar.quest.PRIVATEPYLE = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "KurtKrautwurm_solved":
			pchar.quest.KURTKRAUTWURM = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "MonsieurMondo_solved":
			pchar.quest.MONSIEURMONDO = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "ChiefCunningFrog_solved":
			pchar.quest.CHIEFCUNNINGFROG = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "GeorgGeheim_solved":
			pchar.quest.GEORGGEHEIM = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "TorstenStorenfried_solved":
			pchar.quest.TORSTENSTORENFRIED = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "ContessaCalzone_solved":
			pchar.quest.CONTESSACALZONE = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "DonkeyKong_solved":
			pchar.quest.DONKEYKONG = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "Cheyenne_solved":
			pchar.quest.CHEYENNE = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "SallySloop_solved":
			pchar.quest.SALLYSLOOP = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "BorgenFeck_solved":
			pchar.quest.BORGENFECK = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "BionicleBill_solved":
			pchar.quest.BIONICLEBILL = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "Lieselotte_solved":
			pchar.quest.LIESELOTTE = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "Bornhowler_solved":
			pchar.quest.BORNHOWLER = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk") && CheckQuestAttribute("FATHERFERDINAND", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "FatherFerdinand_solved":
			pchar.quest.FATHERFERDINAND = "drunk";

                        if (CheckQuestAttribute("JOHNNYJACKSON", "drunk") && CheckQuestAttribute("JACKIEJOHNSON", "drunk") && CheckQuestAttribute("MARGRITEUGSTER", "drunk") && CheckQuestAttribute("FINSTOCK", "drunk") && CheckQuestAttribute("ANNESHIRLEY", "drunk") && CheckQuestAttribute("PRIVATEPYLE", "drunk") && CheckQuestAttribute("KURTKRAUTWURM", "drunk") && CheckQuestAttribute("MONSIEURMONDO", "drunk") && CheckQuestAttribute("CHIEFCUNNINGFROG", "drunk") && CheckQuestAttribute("GEORGGEHEIM", "drunk") && CheckQuestAttribute("TORSTENSTORENFRIED", "drunk") && CheckQuestAttribute("CONTESSACALZONE", "drunk") && CheckQuestAttribute("DONKEYKONG", "drunk") && CheckQuestAttribute("CHEYENNE", "drunk") && CheckQuestAttribute("SALLYSLOOP", "drunk") && CheckQuestAttribute("BORGENFECK", "drunk") && CheckQuestAttribute("BIONICLEBILL", "drunk") && CheckQuestAttribute("LIESELOTTE", "drunk") && CheckQuestAttribute("BORNHOWLER", "drunk") && CheckQuestAttribute("JUNGLEJULIA", "drunk"))
                        {
			         LAi_QuestDelay("Tavern_Puzzle_finish", 0.5);
                        }
		break;

//---------------------------------

		case "Tavern_Puzzle_finish":
			LAi_SetActorType(PChar);
			PauseAllSounds();
			PlaySound("OBJECTS\SHIPCHARGE\hurrah.wav");
			LAi_SetStayType(characterFromID("Johnny Jackson"));
			LAi_SetStayType(characterFromID("Chief Cunning Frog"));
			LAi_SetStayType(characterFromID("Private Pyle"));
			LAi_SetStayType(characterFromID("Sally Sloop"));
			LAi_SetStayType(characterFromID("Borgen Feck"));
			LAi_SetStayType(characterFromID("Bionicle Bill"));
			LAi_SetStayType(characterFromID("Cheyenne"));
			LAi_SetStayType(characterFromID("Torsten Storenfried"));
			LAi_SetStayType(characterFromID("Humana Osseus"));
			LAi_SetStayType(characterFromID("Contessa Calzone"));
			LAi_SetStayType(characterFromID("Finstock"));
			LAi_SetStayType(characterFromID("Lt Bornhowler"));
			LAi_SetStayType(characterFromID("Lieselotte"));
			LAi_SetStayType(characterFromID("Anne Shirley"));
			LAi_SetStayType(characterFromID("Jackie Johnson"));
			LAi_SetStayType(characterFromID("Kurt Krautwurm"));
			LAi_SetStayType(characterFromID("Jungle Julia"));
			LAi_SetStayType(characterFromID("Monsieur Mondo"));
			LAi_SetStayType(characterFromID("Georg Geheim"));
			LAi_SetStayType(characterFromID("Margrit Eugster"));
			LAi_SetStayType(characterFromID("Donkey Kong"));
			LAi_SetStayType(characterFromID("Father Ferdinand"));
                        LAi_QuestDelay("Tavern_Puzzle_finish2", 1.5);
		break;

		case "Tavern_Puzzle_finish2":
			PlaySound("PEOPLE\creak.wav");
			ChangeCharacterAddress(characterfromID("Chief Cunning Frog"),"none", "");
			ChangeCharacterAddress(characterfromID("Anne Shirley"),"none", "");
			ChangeCharacterAddress(characterfromID("Borgen Feck"),"none", "");
			ChangeCharacterAddress(characterfromID("Torsten Storenfried"),"none", "");
			ChangeCharacterAddress(characterfromID("Finstock"),"none", "");
			ChangeCharacterAddress(characterfromID("Father Ferdinand"),"none", "");
			ChangeCharacterAddress(characterfromID("Margrit Eugster"),"none", "");
                        LAi_QuestDelay("Tavern_Puzzle_finish3", 1.0);
		break;

		case "Tavern_Puzzle_finish3":
			PlaySound("PEOPLE\creak.wav");
			ChangeCharacterAddress(characterfromID("Johnny Jackson"),"none", "");
			ChangeCharacterAddress(characterfromID("Lt Bornhowler"),"none", "");
			ChangeCharacterAddress(characterfromID("Bionicle Bill"),"none", "");
			ChangeCharacterAddress(characterfromID("Sally Sloop"),"none", "");
			ChangeCharacterAddress(characterfromID("Contessa Calzone"),"none", "");
			ChangeCharacterAddress(characterfromID("Monsieur Mondo"),"none", "");
			ChangeCharacterAddress(characterfromID("Georg Geheim"),"none", "");
                        LAi_QuestDelay("Tavern_Puzzle_finish4", 1.0);
		break;

		case "Tavern_Puzzle_finish4":
			PlaySound("PEOPLE\creak.wav");
			ChangeCharacterAddress(characterfromID("Private Pyle"),"none", "");
			ChangeCharacterAddress(characterfromID("Jackie Johnson"),"none", "");
			ChangeCharacterAddress(characterfromID("Lieselotte"),"none", "");
			ChangeCharacterAddress(characterfromID("Cheyenne"),"none", "");
			ChangeCharacterAddress(characterfromID("Humana Osseus"),"none", "");
			ChangeCharacterAddress(characterfromID("Kurt Krautwurm"),"none", "");
			ChangeCharacterAddress(characterfromID("Donkey Kong"),"none", "");
			ChangeCharacterAddress(characterfromID("Jungle Julia"),"none", "");
                        LAi_QuestDelay("Tavern_Puzzle_finish_downstairs", 1.0);
		break;

		case "Tavern_Puzzle_finish_downstairs":
			LAi_SetPlayerType(PChar);
			LAi_Fade("Tavern_Puzzle_arrive_downstairs", "");
		break;

		case "Tavern_Puzzle_arrive_downstairs":
			ChangeCharacterAddress(pchar, "Puzzle_tavern", "goto3");
			LAi_SetActorType(characterFromID("Marcel Jauri"));
			Characters[GetCharacterIndex("Marcel Jauri")].dialog.currentnode = "Thanks4Help";
			LAi_ActorDialog(characterFromID("Marcel Jauri"), Pchar, "", 0.5, 0);
		break;


		PChar.questnotfound = true; // PB: Testing
	}
}
