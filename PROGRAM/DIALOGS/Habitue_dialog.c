//#include "DIALOGS\Habitue_dialog.h"
void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
    ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize,line; //PW added line for variable text in poker room
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	int iEnemyDice, iPCDice;
	int gameBet = 100;
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	int GAMBLER_CHANCE = 50;					// Even chance that character will be gambler or drinker
	if (CharPlayerType == PLAYER_TYPE_GAMBLER) GAMBLER_CHANCE = 75;	// Higher chance of gambler if you're a gambler
	if (PChar.location == "Cartagena Casino") GAMBLER_CHANCE = 100;	// Guaranteed gambler in Cartagena Gaming House

	if (npchar.quest.Meeting != lastspeak_date)
	{
		npchar.quest.last_theme = 0;
		if (makeint(Rand(99)) < GAMBLER_CHANCE) npchar.quest.last_theme = "1";
		npchar.quest.Meeting = lastspeak_date;
		npchar.money = rand(10)*100;
		if(CheckPerkForGroup(PChar,"HighStakes")) npchar.money = sti(npchar.money) * 5; //Added by Levis
		//Log_SetStringToLog("Money of character " + npchar.id + " is " + npchar.money + "!!!");
	}

	if(!CheckAttribute(NPChar,"HPupdated")) { ResetHP(NPChar); NPChar.HPupdated = true; }//MAXIMUS
	
	// TIH --> these taverns only allow the sub quests in this dialog
	bool allowSubQuests = false;
	if (PChar.location == "Redmond_tavern") allowSubQuests = true;
	if (PChar.location == "Oxbay_tavern") allowSubQuests = true;
	if (PChar.location == "Greenford_tavern") allowSubQuests = true;
	if (PChar.location == "Falaise_De_Fleur_tavern") allowSubQuests = true;
	if (PChar.location == "Muelle_tavern") allowSubQuests = true;
	if (PChar.location == "Douwesen_tavern") allowSubQuests = true;
	if (PChar.location == "Pirate_tavern") allowSubQuests = true;
	if (PChar.location == "Smugglers_tavern") allowSubQuests = true;
	if (PChar.location == "Conceicao_tavern") allowSubQuests = true; // PB: was "Douwesen_tavern" again!
	if (PChar.location == "QC_tavern" || PChar.location == "QC_brothel") allowSubQuests = true;
	if (PChar.location == "PoPrince_Tavern") allowSubQuests = true;
	if (PChar.location == "Havana_Tavern") allowSubQuests = true;
	if (PChar.location == "Santiago_Tavern") allowSubQuests = true;
	// TIH <--
//	allowSubQuests = true; //MAXIMUS    //ASVS : this looks suspicious, need to be checked
	//if (PChar.location == "Tortuga_tavern") PChar.habitue.locator = "sit7"; // habitue locators not used PW
	//if (PChar.location == "Pointe_a_pitre_Tavern") PChar.habitue.locator = "sit4"; //habitue locators not used PW

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			// SCREWFACE : RANDOM TAVERNBRAWL MOD
			if(TAVERNBRAWL_FROMDIALOG && PChar.location != "Cartagena Casino")
			{
				if(!CheckQuestAttribute("gambling_with_girl", "go_to_see_girl") && !CheckAttribute(pchar,"indialog.withgirl")  && !CheckAttribute(PChar,"quest.poker.started"))// added by MAXIMUS & PW to prevent from this while speaking in room or poker competition
				{
					PChar.TAVERNBRAWL = true;
					if(rand(10)==0){LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);Random_Raid("smugglers", 5, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, LanguageConvertString(tmpLangFileID,"TAVERNBRAWL") + "!!!");}
					DeleteAttribute(PChar,"TAVERNBRAWL");
				}
			}
		break;

		case "exit_habitue_leaves":
			pchar.quest.gambling_with_girl = "gambled";
			AddDialogExitQuest("habitue_exit_from_room");
			AddQuestRecord("gambled_girl", 2);
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "Sit_Lower_head";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "Sit_Lower_head";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Lower_head";
			Dialog.cam = "1";

			//PW <=======
			switch (npchar.quest.last_theme)
			{
				case "0": //drink
					dialog.snd = "Voice\HADI\HADI001";
					Preprocessor_Add("lad", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false)); // DeathDaisy
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
					if (makeint(pchar.money) >= 1)
					{
						link.l2 = DLG_TEXT[2];
						link.l2.go = "talk_with_alchogol";
					}
				break;

				case "1":   //dice
					if (!checkAttribute(pchar, "quest.gambling_with_girl"))
					{
						pchar.quest.gambling_with_girl = "";
					}
					if (allowSubQuests && CheckQuestAttribute("gambling_with_girl", "") && makeint(pchar.quest.gambling) >= 40 && makeint(pchar.money) >=100)
					{
						dialog.snd = "Voice\HADI\HADI002";
						dialog.text = DLG_TEXT[3];
						link.l1 = DLG_TEXT[4];
						link.l1.go = "gambling_with_girl_1";
					}
					else
					{
						dialog.snd = "Voice\HADI\HADI003";
						dialog.text = DLG_TEXT[5];
						link.l1 = DLG_TEXT[6];
						link.l1.go = "exit";
						if (makeint(pchar.quest.gambling) < 50 && makeint(npchar.money) >=100)
						{
							dialog.snd = pcharrepphrase("Voice\HADI\HADI006", "Voice\HADI\HADI007");
							dialog.text = pcharrepphrase(DLG_TEXT[12], DLG_TEXT[13] + GetMyName(Pchar) + DLG_TEXT[14]);
							if (makeint(pchar.money) >= 100)
							{
								link.l1 = DLG_TEXT[15];
								link.l1.go = "gambling";
							}
							link.l2 = DLG_TEXT[16];
							link.l2.go = "exit";
						}
						if (makeint(pchar.quest.gambling) >= 50 && makeint(npchar.money) >=100)
						{
							dialog.snd = "Voice\HADI\HADI005";
							Dialog.text = DLG_TEXT[9];
							if (makeint(pchar.money) >= 100)
							{
								link.l1 = DLG_TEXT[10];
								link.l1.go = "gambling";
							}
							link.l2 = DLG_TEXT[11];
							link.l2.go = "exit";
						}
						if (makeint(pchar.quest.gambling) >= 100 && makeint(npchar.money) <100)
						{
							dialog.snd = "Voice\HADI\HADI004";
							Dialog.text = DLG_TEXT[7];
							link.l1 = DLG_TEXT[8];
							link.l1.go = "exit";
						}
					}
				break;
			}
			Diag.TempNode = "First time";
		break;

		case "gambling_with_girl_1":
			pchar.quest.gambling_with_girl = npchar.id;
			dialog.snd = "Voice\HADI\HADI008";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "gambling_with_girl_2";
		break;

		case "gambling_with_girl_2":
			dialog.snd = "Voice\HADI\HADI009";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "gambling_with_girl_3";
		break;

		case "gambling_with_girl_3":
			dialog.snd = "Voice\HADI\HADI010";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[23];
			link.l2.go = "gambling_with_girl_4";
		break;

		case "gambling_with_girl_4":
			dialog.snd = "Voice\HADI\HADI011";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			pchar.quest.friend_in_tavern = npchar.id;
			npchar.quest.locator = npchar.location.locator;
//			AddDialogExitQuest("to_the_room_for_see_girl");
			AddDialogExitQuest("go_to_see_girl");// added by MAXIMUS 18.11.2006 [for nice show of this process]
			pchar.quest.gambling_with_girl = "go_to_see_girl";// added by MAXIMUS 18.11.2006 to prevent from TAVERNBRAWL while we are speaking in room
			npchar.dialog.tempnode = "speak_in_room_while_see_girl";
			pchar.indialog.withgirl = true;//MAXIMUS: will be deleted in Virginie d'Espivant_dialog.c [prevents from TAVERNBRAWL while we are speaking in room]
		break;

		case "speak_in_room_while_see_girl":
			Diag.tempNode = "first time";

			Dialog.defAni = "Sit_Lower_head";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "Sit_Lower_head";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Lower_head";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\HADI\HADI012";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "speak_in_room_while_see_girl_2";
			SetQuestHeader("gambled_girl");
			AddQuestRecord("gambled_girl", 1);
		break;

		case "speak_in_room_while_see_girl_2":
			dialog.snd = "Voice\HADI\HADI013";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "speak_in_room_while_see_girl_3";
			link.l2 = DLG_TEXT[30];
			link.l2.go = "speak_in_room_while_see_girl_6";
		break;

		case "speak_in_room_while_see_girl_3":
			dialog.snd = "Voice\HADI\HADI014";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "speak_in_room_while_see_girl_4";
		break;

		case "speak_in_room_while_see_girl_4":
			dialog.snd = "Voice\HADI\HADI015";
			dialog.text = DLG_TEXT[33] + (rand(6)+3) + DLG_TEXT[34];
			link.l1 = DLG_TEXT[35] + (rand(10) + 10) + DLG_TEXT[36];
			if (CheckAttribute (Pchar,"quest.poker.allowed")) //PW check for freeplay gambler to allow trophy quest
			{
				link.l1.go = "speak_in_room_while_see_girl_5a";
			}
			else
			{
				link.l1.go = "speak_in_room_while_see_girl_5";
			}
		break;

		case "speak_in_room_while_see_girl_5":
			dialog.snd = "Voice\HADI\HADI016";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			pchar.quest.gambling_with_girl = "gambled";
			AddDialogExitQuest("habitue_exit_from_room");
			AddQuestRecord("gambled_girl", 2);
		break;

		case "speak_in_room_while_see_girl_5a":
			dialog.snd = "Voice\HADI\HADI016";
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			link.l1.go = "speak_in_room_while_see_girl_5a2";
			pchar.quest.gambling_with_girl = "gambled";
		break;

		case "speak_in_room_while_see_girl_5a2":
			dialog.snd = "Voice\HADI\HADI016";
			dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[126];
			link.l1.go = "speak_in_room_while_see_girl_5a3";
		break;
		
		case "speak_in_room_while_see_girl_5a3":
			dialog.snd = "Voice\HADI\HADI015";
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "speak_in_room_while_see_girl_5a4";
			link.l2 = DLG_TEXT[131];
			link.l2.go = "exit_habitue_leaves";
		break;
		
		case "speak_in_room_while_see_girl_5a4":
			dialog.snd = "Voice\HADI\HADI015";
			dialog.text = DLG_TEXT[129] + (rand(6)+3) + DLG_TEXT[34];
			link.l1 = DLG_TEXT[35] + (rand(10) + 10) + DLG_TEXT[130];
			link.l1.go = "speak_in_room_while_see_girl_5a5";
			GiveItem2Character(PChar, "poker_invite1");
			pchar.quest.poker.times = 0;
			SetQuestHeader("Poker_Tournament");
			AddQuestRecord("Poker_Tournament", 1);
		break;

		case "speak_in_room_while_see_girl_5a5":
			dialog.snd = "Voice\HADI\HADI016";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			AddDialogExitQuest("habitue_exit_from_room");
			AddQuestRecord("gambled_girl", 2);
		break;

		case "speak_in_room_while_see_girl_6":
			dialog.snd = "Voice\HADI\HADI017";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "speak_in_room_while_see_girl_7";
		break;

		case "speak_in_room_while_see_girl_7":
			dialog.snd = "Voice\HADI\HADI018";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("fight_in_upstairs_for_girl");
			AddQuestRecord("gambled_girl", 3);
		break;
		
		case "gambling":
			Diag.tempnode = "choose_game";//"gambling_node";//MAXIMUS: real games in tavern
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			pchar.quest.friend_in_tavern = npchar.id;
			//GetCharacterPos(pchar, &Land_posx[0], &Land_posy[0], &Land_posz[0]);	//ASVS commented out (now part of "alc" exit quest.)
			//GetCharacterAy(pchar, &Land_angle[0]);								//ASVS commented out
			AddDialogExitQuest("alc");
		break;

		case "gambling_node":
			//Log_SetStringToLog("Количество выигрышей " + gambling + "!");

			Diag.tempNode = "first time";

			Dialog.defAni = "Sit_Lower_head";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "Sit_Lower_head";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Lower_head";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\HADI\HADI019";
			Dialog.text = DLG_TEXT[43]+gameBet+" "+XI_ConvertString("betpiastres")+".";
			link.l1 = DLG_TEXT[44];
			link.l1.go = "gambling_opponent_strike";
	// TIH outcommented because this does not work, and even if it did, these guys rarely even have 1000 or 2000 gold on them! Nov15'06
	//		link.l2 = DLG_TEXT[98];
	//		link.l2.go = "change_bet";
			link.l3 = DLG_TEXT[45];
			link.l3.go = "exit_sit";
		break;

		//MAXIMUS: real games in tavern [testing] ==>
		case "choose_game":
			Diag.tempNode = "first time";
			dialog.snd = "Voice\HADI\HADI019";
			Dialog.text = DLG_TEXT[108];
			link.l1.go = "Vingt-Un";
			link.l1 = XI_ConvertString(link.l1.go);
			link.l2.go = "Poker";
			link.l2 = XI_ConvertString(link.l2.go);
			link.l3.go = "Dice";
			link.l3 = XI_ConvertString(link.l3.go);
//			link.l4.go = "Dumb";
//			link.l4 = XI_ConvertString(link.l4.go);
			link.l5 = DLG_TEXT[45];
			link.l5.go = "exit_sit";
		break;

		case "Vingt-Un":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LaunchGambling(NPChar, "Vingt-Un");
		break;

		case "Poker":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LaunchGambling(NPChar, "Poker");
		break;

		case "Dice":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LaunchGambling(NPChar, "Dice");
		break;

		case "Dumb":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LaunchGambling(NPChar, "Dumb");
		break;

		case "gamble_money":
			Diag.tempNode = "first time";
			dialog.snd = "Voice\HADI\HADI019";
			Dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
		break;

		case "lose_money":
			Diag.tempNode = "first time";
			dialog.snd = "Voice\HADI\HADI019";
			Dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "exit";
		break;

		case "draw":
			Diag.tempNode = "first time";
			dialog.snd = "Voice\HADI\HADI019";
			Dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];
			link.l1.go = "exit";
		break;
		//MAXIMUS: real games in tavern [testing] <==
		case "change_bet":
			dialog.snd = "Voice\HADI\HADI019";
			Dialog.text = DLG_TEXT[99];
			link.l1 = "500"+" "+XI_ConvertString("betpiastres")+".";
			link.l1.go = "go_500";
			link.l2 = "1000"+" "+XI_ConvertString("betpiastres")+".";
			link.l2.go = "go_1000";
			link.l3 = "2000"+" "+XI_ConvertString("betpiastres")+".";
			link.l3.go = "go_2000";
			link.l4 = DLG_TEXT[100];
			link.l4.go = "gambling_node";
		break;

		case "go_500":
			gameBet = 500;
			dialog.snd = "Voice\HADI\HADI019";
			Dialog.text = DLG_TEXT[43]+gameBet+" "+XI_ConvertString("betpiastres")+".";
			link.l1 = DLG_TEXT[44];
			link.l1.go = "gambling_opponent_strike";
			link.l2 = DLG_TEXT[45];
			link.l2.go = "exit_sit";
		break;

		case "go_1000":
			gameBet = 1000;
			dialog.snd = "Voice\HADI\HADI019";
			Dialog.text = DLG_TEXT[43]+gameBet+" "+XI_ConvertString("betpiastres")+".";
			link.l1 = DLG_TEXT[44];
			link.l1.go = "gambling_opponent_strike";
			link.l2 = DLG_TEXT[45];
			link.l2.go = "exit_sit";
		break;

		case "go_2000":
			gameBet = 2000;
			dialog.snd = "Voice\HADI\HADI019";
			Dialog.text = DLG_TEXT[43]+gameBet+" "+XI_ConvertString("betpiastres")+".";
			link.l1 = DLG_TEXT[44];
			link.l1.go = "gambling_opponent_strike";
			link.l2 = DLG_TEXT[45];
			link.l2.go = "exit_sit";
		break;

		case "gambling_opponent_strike":
			if (makeint(npchar.money <= 0))
			{
				dialog.snd = "Voice\HADI\HADI020";
				dialog.text = DLG_TEXT[46];
				link.l1 = DLG_TEXT[47];
				link.l1.go = "exit_sit";
			}
			else
			{
				iEnemyDice = makeint(rand(6) + rand(6) + rand(6) + rand(6)) - CalcCharacterSkill(PChar,SKILL_SNEAK) + 1;
				if (iEnemyDice <4) {iEnemyDice = 4;}
				if (iEnemyDice >24) {iEnemyDice = 24;}
				if (iEnemyDice <=10)
				{
					dialog.snd = "Voice\HADI\HADI021";
					Dialog.text = iEnemyDice + DLG_TEXT[48];
				}
				if (iEnemyDice > 10 && iEnemyDice <=15)
				{
					dialog.snd = "Voice\HADI\HADI022";
					dialog.text = iEnemyDice + DLG_TEXT[49];
				}
				if (iEnemyDice > 15 && iEnemyDice <=20)
				{
					dialog.snd = "Voice\HADI\HADI023";
					dialog.text = iEnemyDice + DLG_TEXT[50];
				}
				if (iEnemyDice > 20)
				{
					dialog.snd = "Voice\HADI\HADI024";
					dialog.text = iEnemyDice + DLG_TEXT[51];
				}
				link.l1 = DLG_TEXT[52];
				link.l1.go = "gambling_pc_strike";
				pchar.iEnemyDice = iEnemyDice;
			}
		break;

		case "gambling_pc_strike":
			//Log_SetStringToLog("Money of character " + npchar.id + " is " + npchar.money + "!");
			iPCDice = makeint(rand(6) + rand(6) + rand(6) + rand(6));
			if (iPCDice <= (23 -  CalcCharacterSkill(PChar,SKILL_SNEAK)))
			{
				 iPCDice = iPCDice + CalcCharacterSkill(PChar,SKILL_SNEAK) - 1;
			}
			if (iPCDice <4) {iPCDice = 4;} // typo fix
			if (iPCDice >24) {iPCDice = 24;} // typo fix
			if (iPCDice < makeint(pchar.iEnemyDice))
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -gameBet);
				npchar.money = makeint(npchar.money) + gameBet;
				dialog.snd = "Voice\HADI\HADI025";
				string you_lost = DLG_TEXT[54];
				if(PChar.sex == "woman"){
					you_lost = DLG_TEXT[119];
				}
				Dialog.text = iPCDice + DLG_TEXT[53] + you_lost;
				if (makeint(pchar.money) >=gameBet)
				{
					link.l1 = DLG_TEXT[55];
					link.l1.go = "gambling_opponent_strike";
				}
				link.l2 = DLG_TEXT[56];
				link.l2.go = "exit_sit";
				pchar.quest.gambling = makeint(pchar.quest.gambling) - 1;
			}
			if (iPCDice > makeint(pchar.iEnemyDice))
			{
				dialog.snd = "Voice\HADI\HADI026";
				Dialog.text = iPCDice + DLG_TEXT[57] + DLG_TEXT[58];
				link.l1 = DLG_TEXT[59];
				link.l1.go = "gambling_opponent_strike";
				link.l2 = DLG_TEXT[60];
				link.l2.go = "exit_sit";
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, gameBet);
				npchar.money = makeint(npchar.money) - gameBet;
				pchar.quest.gambling = makeint(pchar.quest.gambling) + 1;
				/*//вызов от мужика с клевыми костями
				if (makeint(pchar.quest.gambling) == 60)
				{

					pchar.quest.exit_from_tavern.win_condition.l1 = "ExitFromLocation";
					pchar.quest.exit_from_tavern.win_condition.l1.location = pchar.location;
					pchar.quest.exit_from_tavern.win_condition = "exit_from_tavern";
				}
				//вызов от мужика играющего, как бог
				if (makeint(pchar.quest.gambling) == 100)
				{
					pchar.quest.exit_from_tavern.win_condition.l1 = "ExitFromLocation";
					pchar.quest.exit_from_tavern.win_condition.l1.location = pchar.location;
					pchar.quest.exit_from_tavern.win_condition = "exit_from_tavern";
				}*/
			}
			if (iPCDice == makeint(pchar.iEnemyDice))
			{
				dialog.snd = "Voice\HADI\HADI027";
				Dialog.text = DLG_TEXT[61];
				link.l1 = DLG_TEXT[62];
				link.l1.go = "gambling_opponent_strike";
				link.l2 = DLG_TEXT[63];
				link.l2.go = "exit_sit";
			}
			DeleteAttribute(pchar, "iEnemyDice");
		break;


		case "talk_with_alchogol":
			Diag.TempNode = "begin_sit";
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			pchar.quest.friend_in_tavern = npchar.id;
			AddDialogExitQuest("alc");
		break;

		case "begin_sit":
			Diag.TempNode = "first time";
			dialog.snd = "Voice\HADI\HADI028";
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "sit_2";
		break;

		case "sit_2":
			PlayStereoSound("INTERFACE\took_item.wav");
			PlayStereoSound("AMBIENT\TAVERN\tinkle1.wav"); //ASVS
			PlayStereoSound("AMBIENT\TAVERN\man6.wav");    //ASVS
			AddMoneyToCharacter(pchar, -1);
			dialog.snd1 = "Voice\HADI\HADI029";
			dialog.snd2 = "Voice\HADI\HADI030";
			dialog.snd3 = "Voice\HADI\HADI031";
			dialog.text = randphrase(DLG_TEXT[66], DLG_TEXT[67], DLG_TEXT[68], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit_sit";
			if (makeint(pchar.money) >=1)
			{
				link.l2 = DLG_TEXT[70];
				link.l2.go = "sit_3";
			}
		break;

		case "sit_3":
			if (allowSubQuests) {
				switch (rand(4))
				{
				case 0: //drink again
					dialog.snd = "Voice\HADI\HADI032";
					dialog.text = DLG_TEXT[71];
					link.l1 = DLG_TEXT[72];
					link.l1.go = "sit_2";
				break;

				case 1: //too much rum
					dialog.snd = "Voice\HADI\HADI033";
					dialog.text = DLG_TEXT[73];
					link.l1 = DLG_TEXT[74];
					link.l1.go = "sit_case_2_friend";
					link.l2 = DLG_TEXT[75];
					link.l2.go = "sit_case_2_enemy";
				break;

				case 2: //soldiers
					dialog.snd = "Voice\HADI\HADI034";
					Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
					dialog.text = DLG_TEXT[76];
					link.l1 = DLG_TEXT[77];
					link.l1.go = "exit_sit";
					link.l2 = DLG_TEXT[78];
					link.l2.go = "sit_case_3";
				break;

				case 3: //drunk
					dialog.snd = "Voice\HADI\HADI035";
					dialog.text = DLG_TEXT[79];
					link.l1 = DLG_TEXT[80];
					link.l1.go = "sit_case_4_exit";
				break;

				case 4: //random attack us
					dialog.snd = "Voice\HADI\HADI036";
					dialog.text = DLG_TEXT[81];
					link.l1 = DLG_TEXT[82];
					link.l1.go = "sit_case_5_exit";
				break;
				}
			} else {
				switch (rand(2))//MAXIMUS: was rand(1) - is this proper?
				{
				case 0:
					dialog.snd = "Voice\HADI\HADI032";
					dialog.text = DLG_TEXT[71];
					link.l1 = DLG_TEXT[72];
					link.l1.go = "sit_2";
				break;

				case 1:
					dialog.snd = "Voice\HADI\HADI033";
					dialog.text = DLG_TEXT[73];
					link.l1 = DLG_TEXT[74];
					link.l1.go = "sit_case_2_friend";
				break;

				case 2:
					dialog.snd = "Voice\HADI\HADI034";
					dialog.text = DLG_TEXT[76];
					link.l1 = DLG_TEXT[77];
					link.l1.go = "exit_sit";
					link.l2 = DLG_TEXT[78];
					link.l2.go = "sit_case_3";
				break;
				}
			}
		break;

		case "sit_case_5_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("fighting");
		break;

		case "sit_case_4_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			pchar.quest.friend_in_tavern = npchar.id;
			AddDialogExitQuest("without_memory");
		break;

		case "sit_case_3":
			dialog.snd = "Voice\HADI\HADI037";
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "exit_sit";
			if (allowSubQuests) {
				link.l2 = DLG_TEXT[85];
				link.l2.go = "sit_case_3_exit";
			}
		break;

		case "sit_case_3_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("drink_talk_with_soldier");
		break;

		case "sit_case_2_friend":
			dialog.snd = "Voice\HADI\HADI038";
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "exit_sit";
			if (allowSubQuests) {
				link.l2 = DLG_TEXT[88];
				link.l2.go = "sit_case_2_friend_2";
			}
		break;

		case "sit_case_2_friend_2":
			dialog.snd = "Voice\HADI\HADI039";
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "tavern_keeper";
		break;

		case "sit_case_2_enemy":
			dialog.snd = "Voice\HADI\HADI040";
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "tavern_keeper";
		break;

		case "exit_sit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;

		case "danielle_fight":
			dialog.snd = "Voice\HADI\HADI041";
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[95];
			link.l2.go = "danielle_fight_2";
		break;

		case "danielle_fight_2":
			dialog.snd = "Voice\HADI\HADI042";
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "tavern_keeper";
			pchar.quest.fight_in_tavern = "fight";
		break;

		case "tavern_keeper":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("tavern_keeper");
		break;

	}
	LanguageCloseFile(tmpLangFileID);
}
