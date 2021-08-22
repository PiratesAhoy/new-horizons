// ccc jul05 corpse
// This pseudo dialog only opens the itemexchange interface for looting corpses
// one could also add dialogchoices for reawakening or burial

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	string questname = "";
	string patroltime = GetPatrolTimeText(Islands[GetCharacterCurrentIsland(Pchar)], GetBestSmugglingtime(Islands[GetCharacterCurrentIsland(Pchar)],PChar));
																																				   
	if(CheckAttribute(Pchar,"amount_smuggleruns")) questname = "smuggle&number="+Pchar.amount_smuggleruns; //Set a questname
	if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
	{
		ref smugisland = GetIslandByIndex(sti(Pchar.quest.Contraband.islandindex));
		
		string PatrolState = "";
		// DeathDaisy: 3d6 persuasion system based on leadership and luck so far
		int PersuadeInt;
		int ThreeDice;
		int pLeadership = CalcCharacterSkill(PChar,SKILL_LEADERSHIP);
		int pLuck = CalcCharacterSkill(PChar,SKILL_SNEAK);
		int PersuasionChance = 3+round(rand(pLuck*10)/10)+pLeadership-(getSmugglingState(smugisland)-1);
		if(CheckCharacterPerk(PChar,"Trustworthy")) PersuasionChance = PersuasionChance+1;
		if(CheckCharacterPerk(PChar,"IronWill")) PersuasionChance = PersuasionChance+1;
		//if(CheckCharacterPerk(PChar,"Charisma")) PersuasionChance = PersuasionChance+2;
		//if(CheckCharacterPerk(PChar,"WitCharm")) PersuasionChance = PersuasionChance+3;
		//if(sti(Pchar.model.nation) == sti(NPChar.nation) && PChar.model.playertype == PLAYER_TYPE_MARINE) PersuasionChance = PersuasionChance+3;
		PersuasionChance = iClamp(4,16,PersuasionChance);
		//trace(PersuasionChance);
	}
	
	string PersuasionSuccess = "";
	string PersuasionFailure = "";
	if(PERSUASION_TAGS){ 
		PersuasionSuccess = XI_ConvertString("Persuasion_Success") + " ";
		PersuasionFailure = XI_ConvertString("Persuasion_Failure") + " ";
	}
	
	int loc_id = FindLocation(PChar.location);
	int price = makeint(sqrt(sti(pchar.rank)))*250;
	string sNation = "";

	bool bHostileDetected = false;

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "first time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";

			// PB: You are a KNOWN enemy because you're flying a hostile flag
			if (GetFlagRMRelation(sti(Npchar.nation)) == RELATION_ENEMY)
			{
				sNation = " " + GetNationDescByType(GetCurrentFlag());
				if (GetCurrentFlag() == PERSONAL_NATION) sNation = "n "; // PB: Grammar "an enemy"
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
				Dialog.Text = DLG_TEXT[7] + GetMySimpleName(PChar) + DLG_TEXT[8] + sNation + DLG_TEXT[32];
				Link.l1 = DLG_TEXT[9];
				Link.l1.go = "exit_soldiers";
				bHostileDetected = true;
			}
			else
			{
				// ccc Dec 05 You are recognized for your pirating actions
				if(GetServedNation() == PIRATE && GetCurrentLocationNation() != PIRATE)	// MT: If serving the pirates and in a non-pirate location, then:
				{
					if(frnd()<makefloat(GetRank(pchar, sti(NPChar.nation)))/12.0) //MT: Meant to make you easier to detect as a pirate as you go up in pirate rank
					{
						Dialog.Text = DLG_TEXT[7] + GetMySimpleName(PChar) + DLG_TEXT[11];
						Link.l1 = DLG_TEXT[9];
						Link.l1.go = "exit_soldiers";
						bHostileDetected = true;
					}
					else
					{
						Dialog.Text = DLG_TEXT[0] + GetMySimpleName(PChar) + DLG_TEXT[1];
						Link.l1 = DLG_TEXT[2];
						Link.l1.go = "exit";
					}
				}
				else
				{
					//MT: If at war with the nation the guard belongs to, there is a chance to be detected (false flags should only occur when at war):
					if (GetNationRelation(PERSONAL_NATION, sti(Npchar.nation)) == RELATION_ENEMY && frnd() < GetChanceDetectFalseFlag())
					{
						sNation = " " + GetNationDescByType(GetServedNation());
						if (GetServedNation() == PERSONAL_NATION) sNation = ""; // PB: Grammar "a spy"
						Dialog.Text = DLG_TEXT[7] + GetMySimpleName(PChar) + DLG_TEXT[8] + sNation + DLG_TEXT[10];
						Link.l1 = DLG_TEXT[9];
						Link.l1.go = "exit_soldiers";
						bHostileDetected = true;
					}
					else
					{
						Dialog.Text = DLG_TEXT[18];
						Link.l1 = DLG_TEXT[19];
						Link.l1.go = "exit";
					}
					
				}
			}
			//Levis smuggling addon -->
			if(CheckAttribute(Pchar,"quest.Contraband.scout"))
			{
				if(!CheckAttribute(Pchar,"quest.Contraband.Talked") || !CheckAttribute(Pchar,"quest.Contraband.Cardwon"))
				{
					Link.l2 = DLG_TEXT[3];
					Link.l2.go = "patrolquestion";
				}
			}
			//Levis smuggling addon <--

			//GR: "Kapitein of Kralendijk" sidequest
			if (sti(NPchar.nation) == HOLLAND && PChar.money >= 150 && CheckQuestAttribute("kapitein", "start"))
			{
				if (bHostileDetected) link.l3 = DLG_TEXT[34];
				else link.l3 = DLG_TEXT[33];
				link.l3.go = "kapitein_Dutch_soldier_accepts_drink";
			}

			if (sti(NPchar.nation) == HOLLAND && CheckQuestAttribute("kapitein", "got_uniform") && PChar.model == Nations[HOLLAND].fantomModel.m0)
			{
				if (bHostileDetected)
				{
					link.l3 = DLG_TEXT[38];
					link.l3.go = "kapitein_try_bluff_hostile";
				}
				else
				{
					link.l3 = DLG_TEXT[37];
					link.l3.go = "kapitein_try_bluff";
				}
			}
			Diag.TempNode = "first time";
		break;

		case "exit_soldiers":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);
			Random_Raid("Soldiers", 2, sti(NPchar.nation), LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
		break;
		
		//Levis smuggling dialog options
		case "patrolquestion":
			
			//DeathDaisy: Ugly workaround because LinkRandPhrase can't take more than 3 vars!
			string PersuadeDialog;
			switch(rand(4)){
				case 0:
					PersuadeDialog = DLG_TEXT[5];
					PersuadeInt = 0;
				break;
				
				case 1:
					PersuadeDialog = DLG_TEXT[48];
					PersuadeInt = 1;
				break;
				
				case 2:
					PersuadeDialog = DLG_TEXT[49];
					PersuadeInt = 2;
				break;
				
				case 3:
					PersuadeDialog = DLG_TEXT[50];
					PersuadeInt = 3;
				break;
				
				case 4:
					PersuadeDialog = DLG_TEXT[51];
					PersuadeInt = 4;
				break;
			}
			if(CheckOfficiantHadSex(GetCurrentTownID())==TRUE){
				PersuadeDialog = DLG_TEXT[5];
				PersuadeInt = 0;
			}
			trace(PersuadeDialog);
			trace("PersuadeInt = "+PersuadeInt);
			
			Preprocessor_Add("npcsir",FirstLetterUp(GetCharacterAddressForm(NPChar,ADDR_POLITE,false,false)));
			
			Dialog.Text = DLG_TEXT[4];
			if(!CheckAttribute(Pchar,"quest.Contraband.Talked"))
			{
				Link.l1 = PersuadeDialog;
				if(PersuadeInt == 0)	Link.l1.go = "seasidepicknick";
				else Link.l1.go = "persuadeguard"+PersuadeInt;
			}
			if(!CheckAttribute(Pchar,"quest.Contraband.Cardwon"))
			{
				if(CheckCharacterPerk(PChar,"HighStakes"))
				{
					Link.l3 = DLG_TEXT[28];
					Link.l3.go = "playgame";
				}
			}
			//if(ProfessionalNavyNation() == NPChar.nation){ //DeathDaisy: TODO: if you happen to be in the navy, outrank the soldier and they are of your nation, order them to give you the time
		break;
		
		case "persuadeguard1":			
			if(getSmugglingState(smugisland) == 1) PatrolState = DLG_TEXT[44];
			if(getSmugglingState(smugisland) == 2) PatrolState = DLG_TEXT[45];
			if(getSmugglingState(smugisland) == 3) PatrolState = DLG_TEXT[46];
			if(getSmugglingState(smugisland) == 4) PatrolState = DLG_TEXT[56];
				
			// DeathDaisy: Roll 3 six-sided dice to determine success for a nice bell curve
			ThreeDice = round(((rand(50)+10)+(rand(50)+10)+(rand(50)+10))/10);
			if(ThreeDice <= PersuasionChance){
				trace("PersuasionChance: "+PersuasionChance+ "Dice: "+ ThreeDice + ". Persuasion Success!");
				Preprocessor_AddQuestData("time",patroltime);
				AddQuestRecord(questname, 3);
				Preprocessor_Remove("time");
				Preprocessor_Add("npcsir",FirstLetterUp(GetCharacterAddressForm(NPChar,ADDR_POLITE,false,false)));
				Preprocessor_Add("patroltime",patroltime);
				Preprocessor_Add("lad", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false));
				Dialog.Text = PersuasionSuccess + DLG_TEXT[52]+PatrolState;
				Link.l1 = DLG_TEXT[59];
				Link.l1.go = "exit";
				Pchar.quest.Contraband.Talked = true;
				AddPartyExpChar(pchar, SKILL_SNEAK, 200);
			}
			else
			{
				trace("PersuasionChance: "+PersuasionChance+ " Dice: "+ ThreeDice + ". Persuasion Failed!");
				if(pchar.money > price)
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[63];
					Link.l1 = DLG_TEXT[15];
					Link.l1.go = "buyinfo";
				}
				else
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[18];
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "exit_smuggling";
				}
			}
		break;
		
		case "persuadeguard2":
			if(getSmugglingState(smugisland) == 1) PatrolState = DLG_TEXT[44];
			if(getSmugglingState(smugisland) == 2) PatrolState = DLG_TEXT[45];
			if(getSmugglingState(smugisland) == 3) PatrolState = DLG_TEXT[46];
			if(getSmugglingState(smugisland) == 4) PatrolState = DLG_TEXT[47];
				
			// DeathDaisy: Roll 3 six-sided dice to determine success for a nice bell curve
			ThreeDice = round(((rand(50)+10)+(rand(50)+10)+(rand(50)+10))/10);
			if(ThreeDice <= PersuasionChance){
				Preprocessor_AddQuestData("time",patroltime);
				AddQuestRecord(questname, 3);
				Preprocessor_Remove("time");
				Preprocessor_Add("patroltime",patroltime);
				trace("PersuasionChance: "+PersuasionChance+ " Dice: "+ ThreeDice + ". Persuasion Success!");
				Dialog.Text = PersuasionSuccess + DLG_TEXT[53] + PatrolState;
				Link.l1 = DLG_TEXT[60];
				Link.l1.go = "exit";
				Pchar.quest.Contraband.Talked = true;
				AddPartyExpChar(pchar, SKILL_SNEAK, 200);
			}
			else
			{
				trace("PersuasionChance: "+PersuasionChance+ "Dice: "+ ThreeDice + ". Persuasion Failed!");
				if(pchar.money > price)
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[64];
					Link.l1 = DLG_TEXT[15];
					Link.l1.go = "buyinfo";
				}
				else
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[18];
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "exit_smuggling";
				}
			}
		break;
		
		case "persuadeguard3":			
			if(getSmugglingState(smugisland) == 1) PatrolState = DLG_TEXT[44];
			if(getSmugglingState(smugisland) == 2) PatrolState = DLG_TEXT[45];
			if(getSmugglingState(smugisland) == 3) PatrolState = DLG_TEXT[58];
			if(getSmugglingState(smugisland) == 4) PatrolState = DLG_TEXT[57];
				
			// DeathDaisy: Roll 3 six-sided dice to determine success for a nice bell curve
			ThreeDice = round(((rand(50)+10)+(rand(50)+10)+(rand(50)+10))/10);
			if(ThreeDice <= PersuasionChance){
				Preprocessor_AddQuestData("time",patroltime);
				AddQuestRecord(questname, 3);
				Preprocessor_Remove("time");
				Preprocessor_Add("patroltime",patroltime);
				trace("PersuasionChance: "+PersuasionChance+ " Dice: "+ ThreeDice + ". Persuasion Success!");
				Dialog.Text = PersuasionSuccess + DLG_TEXT[54] + PatrolState;
				Link.l1 = DLG_TEXT[61];
				Link.l1.go = "exit";
				Pchar.quest.Contraband.Talked = true;
				AddPartyExpChar(pchar, SKILL_SNEAK, 200);
			}
			else
			{
				trace("PersuasionChance: "+PersuasionChance+ "Dice: "+ ThreeDice + ". Persuasion Failed!");
				if(pchar.money > price)
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[65];
					Link.l1 = DLG_TEXT[15];
					Link.l1.go = "buyinfo";
				}
				else
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[18];
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "exit_smuggling";
				}
			}
		break;
		
		case "persuadeguard4":
			if(getSmugglingState(smugisland) == 1) PatrolState = DLG_TEXT[44];
			if(getSmugglingState(smugisland) == 2) PatrolState = DLG_TEXT[45];
			if(getSmugglingState(smugisland) == 3) PatrolState = DLG_TEXT[46];
			if(getSmugglingState(smugisland) == 4) PatrolState = DLG_TEXT[56];
				
			// DeathDaisy: Roll 3 six-sided dice to determine success for a nice bell curve
			ThreeDice = round(((rand(50)+10)+(rand(50)+10)+(rand(50)+10))/10);
			if(ThreeDice <= PersuasionChance){
				Preprocessor_AddQuestData("time",patroltime);
				AddQuestRecord(questname, 3);
				Preprocessor_Remove("time");
				Preprocessor_Add("patroltime",patroltime);
				trace("PersuasionChance: "+PersuasionChance+ " Dice: "+ ThreeDice + ". Persuasion Success!");
				Dialog.Text = PersuasionSuccess + DLG_TEXT[55] + PatrolState;
				Link.l1 = DLG_TEXT[62];
				Link.l1.go = "exit";
				Pchar.quest.Contraband.Talked = true;
				AddPartyExpChar(pchar, SKILL_SNEAK, 200);
			}
			else
			{
				trace("PersuasionChance: "+PersuasionChance+ "Dice: "+ ThreeDice + ". Persuasion Failed!");
				if(pchar.money > price)
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[66];
					Link.l1 = DLG_TEXT[15];
					Link.l1.go = "buyinfo";
				}
				else
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[18];
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "exit_smuggling";
				}
			}
		break;
		
		case "seasidepicknick":
			ThreeDice = round(((rand(50)+10)+(rand(50)+10)+(rand(50)+10))/10);
			if(CheckOfficiantHadSex(GetCurrentTownID())==TRUE || ThreeDice <= PersuasionChance)
			{
				trace("PersuasionChance: "+PersuasionChance+ " Dice: "+ ThreeDice + ". Persuasion Success!");
				Preprocessor_AddQuestData("time",patroltime);
				AddQuestRecord(questname, 3);
				Preprocessor_Remove("time");
				Preprocessor_Add("lad", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false)); // DeathDaisy
				string GoodLuck = DLG_TEXT[6];
				if(PChar.sex == "woman"){ GoodLuck = DLG_TEXT[43]; }
				
				if(getSmugglingState(smugisland) == 1) PatrolState = DLG_TEXT[44];
				if(getSmugglingState(smugisland) == 2) PatrolState = DLG_TEXT[45];
				if(getSmugglingState(smugisland) == 3) PatrolState = DLG_TEXT[46];
				if(getSmugglingState(smugisland) == 4) PatrolState = DLG_TEXT[47];
				
				Dialog.Text = PersuasionSuccess+GoodLuck +patroltime+DLG_TEXT[12]+PatrolState;
				Link.l1 = DLG_TEXT[13];
				Link.l1.go = "exit";
				Pchar.quest.Contraband.Talked = true;
				AddPartyExpChar(pchar, SKILL_SNEAK, 200);
			}
			else
			{
				trace("PersuasionChance: "+PersuasionChance+ "Dice: "+ ThreeDice + ". Persuasion Failed!");
				if(pchar.money > price)
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[14];
					Link.l1 = DLG_TEXT[15];
					Link.l1.go = "buyinfo";
				}
				else
				{
					Dialog.Text = PersuasionFailure+DLG_TEXT[18];
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "exit_smuggling";
				}
			}
		break;
		
		case "buyinfo":
			Dialog.Text = DLG_TEXT[20]+price+DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "acceptprice";
			Link.l2 = DLG_TEXT[23];
			Link.l2.go = "declineprice";
		break;
		
		case "acceptprice":
			if(getSmugglingState(smugisland) == 1) PatrolState = DLG_TEXT[44];
			if(getSmugglingState(smugisland) == 2) PatrolState = DLG_TEXT[45];
			if(getSmugglingState(smugisland) == 3) PatrolState = DLG_TEXT[46];
			if(getSmugglingState(smugisland) == 4) PatrolState = DLG_TEXT[47];
			//TraceAndLog(getSmugglingState(smugisland));
			//TraceAndLog(PatrolState);
			AddMoneyToCharacter(pchar, -1 * price);
			Dialog.Text = PatrolState+DLG_TEXT[25]+patroltime+DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit_smuggling";
			Preprocessor_AddQuestData("time",patroltime);
			AddQuestRecord(questname, 2);
			Preprocessor_Remove("time");
			Pchar.quest.Contraband.Talked = true;
		break;
		
		case "declineprice":
			AddMoneyToCharacter(pchar, -10);
			Dialog.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "exit_smuggling";
		break;
		
		case "playgame":
			Pchar.quest.Contraband.CardsBet = (getSmugglingState(Islands[GetCharacterCurrentIsland(PChar)])+1)*1000;
			Dialog.Text = DLG_TEXT[29] + Pchar.quest.Contraband.CardsBet + ".";
			if(sti(PChar.money) >= sti(Pchar.quest.Contraband.CardsBet))
			{
				Link.l1 = DLG_TEXT[30];
				Link.l1.go = "playgame2";
			}
			Link.l2 = DLG_TEXT[31];
			Link.l2.go = "exit_smuggling";
		break;
		
		case "playgame2":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			Pchar.quest.Contraband.Cards = 1;
			LaunchGambling(NPChar, "Poker");
		break;
		
		case "wongame":
			//AddMoneyToCharacter(pchar, -1 * price);
			Dialog.Text = DLG_TEXT[25]+patroltime+DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
			Preprocessor_AddQuestData("time",patroltime);
			AddQuestRecord(questname, 12);
			Preprocessor_Remove("time");
			LAi_SetCivilianPatrolType(NPChar);
			Pchar.quest.Contraband.Cardwon = true;
		break;
		
		case "smuggling_already_asked":
			if(PChar.sex == "woman")Preprocessor_Add("diminutive",XI_ConvertString("girl"));
			else Preprocessor_Add("diminutive",XI_ConvertString("boy"));
			Dialog.Text = DLG_TEXT[67];
			Link.l1 = "...";
			Link.l1.go = "exit_smuggling";
		break;
		
		case "exit_smuggling":
			Diag.CurrentNode = "smuggling_already_asked";
			DialogExit();
		break;
		//End smuggling dialog options

		//GR: "Kapitein of Kralendijk" sidequest
		case "kapitein_Dutch_soldier_accepts_drink":
			PChar.quest.kapitein.soldier_name = GetMyName(NPChar);
			PChar.quest.kapitein.soldier_last_name = GetMyLastName(NPChar);
			PChar.quest.kapitein.soldier_model = NPChar.model;
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			AddDialogExitQuest("Kapitein_with_soldier_to_room");
			link.l1.go = "exit";
		break;

		case "kapitein_try_bluff":
			PChar.quest.kapitein.soldier_name2 = GetMyName(NPChar);
			PChar.quest.kapitein.soldier_last_name2 = GetMyLastName(NPChar);
			PChar.quest.kapitein.soldier_model2 = NPChar.model;
			PChar.quest.kapitein.soldier_id2 = NPChar.id;
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[42];
			AddDialogExitQuest("kapitein_leave_tavern_with_soldier");
			link.l1.go = "exit";
		break;

		case "kapitein_try_bluff_hostile":
			if (CalcCharacterSkill(PChar, SKILL_LEADERSHIP) >= 6)
			{
				PChar.quest.kapitein.soldier_name2 = GetMyName(NPChar);
				PChar.quest.kapitein.soldier_last_name2 = GetMyLastName(NPChar);
				PChar.quest.kapitein.soldier_model2 = NPChar.model;
				PChar.quest.kapitein.soldier_id2 = NPChar.id;
				dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[42];
				AddDialogExitQuest("kapitein_leave_tavern_with_soldier");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[40];
				link.l1 = DLG_TEXT[41];
				link.l1.go = "exit_soldiers";
			}
		break;
		// End of "Kapitein of Kralendijk"

	}
}
