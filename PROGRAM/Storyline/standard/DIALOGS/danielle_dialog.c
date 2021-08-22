void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	
	// RM -->
	if(strcut(Dialog.CurrentNode, 0, 3) == "flag") // KK
	{
// KK -->
		string ssel = GetSymbol(Dialog.CurrentNode, 4) + GetSymbol(Dialog.CurrentNode, 5);
		int cc;
		int sel_nation = sti(ssel);
		string tstr = XI_ConvertString(GetNationDescByType(sel_nation));
		HoistFlag(sel_nation);
		if (sel_nation == PERSONAL_NATION) tstr = "your";
		Dialog.Text = DLG_TEXT[461] + tstr + DLG_TEXT[462];
// <-- KK
		Link.l1 = DLG_TEXT[463];
		Link.l1.go = "exit";
		return;
	}
	// RM <--
	// NK -->
	if(strlen(Dialog.CurrentNode) > 6)
	{
		if(strcut(Dialog.CurrentNode, 0, 6) == "chmodel")
		{
			int idx = sti(GetSymbol(Dialog.CurrentNode,7));
			idx = GetOfficersIndex(&PChar, idx);
			if(idx != -1)
			{
				string ani = "man";
				string sex = "man";
				float height = 1.8;
				string model = "";
				ref chr = GetCharacter(idx);
				switch(GetSymbol(Dialog.CurrentNode,8))
				{
					case "M":
						ani = "man";
						sex = "man";
						height = 1.8;
						break;
					case "W":
						ani = "woman";
						sex = "woman";
						height = 1.75;
						break;
					case "T":
						ani = "towngirl";
						sex = "woman";
						height = 1.75;
						break;
					case "S":
						ani = "skeleton";
						sex = "skeleton";
						height = 1.8;
						break;
				}
				for(int sm = 9; sm < strlen(Dialog.CurrentNode); sm++) { model += GetSymbol(Dialog.CurrentNode,sm); }
				dialog.text = DLG_TEXT[464];
				Link.l1 = DLG_TEXT[465];
				Link.l1.go = "Exit";
				if(DEBUGINFO) dialog.text = "OK, new model " + model + ", ani " + ani + ", sex " + sex + ", height " + height + ".";
				SetModel(&chr, model, ani, sex, height, true);
			}
			else
			{
				dialog.text = DLG_TEXT[466];
				Link.l1 = DLG_TEXT[467];
				Link.l1.go = "exit";
			}
			return;
		}
	}

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			// NK 04-10-01 move wait_for_remove_comp to bottom to take precedence
			// разговор в квестовой таверне Редмонда
			if (pchar.quest.main_line == "talk_in_tavern_begin")
			{
				if(PChar.sex == "woman")
				{
					Dialog.Text = DLG_TEXT[558] + GetMyName(PChar) + DLG_TEXT[559];
					Link.l1 = DLG_TEXT[560] + GetMyName(NPChar) + DLG_TEXT[561];
				}
				else
				{
					dialog.text = DLG_TEXT[5] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[6])]) + DLG_TEXT[7];
					Link.l1 = DLG_TEXT[8];
				}
				Link.l1.go = "talk_in_tavern";
			}
			if(pchar.quest.main_line == "fawn_death")
			{
				dialog.text = GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[9])]) + DLG_TEXT[10];
				link.l1 = DLG_TEXT[11] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[12])]) + DLG_TEXT[13];
				link.l1.go = "talk_in_tavern_1";
			}
			//разговор на маяке
			if (pchar.quest.main_line == "meet_danielle_in_lighthouse")
			{
				dialog.text = GetMyName(PChar) + DLG_TEXT[14];
				link.l1 = GetMyName(NPChar) + DLG_TEXT[15];
				link.l1.go = "meet_danielle_in_lighthouse_2";
			}
			if (pchar.quest.main_line == "speak_danielle_in_lighthouse_prepare_to_search_rheims")
			{
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17] + characters[GetCharacterIndex(DLG_TEXT[18])].lastname + DLG_TEXT[19];
				link.l1.go = "speak_danielle_in_lighthouse_prepare_to_search_rheims_2";
			}
			if (pchar.quest.main_line == "blaze_search_rheims_with_danielle")
			{
				dialog.text = DLG_TEXT[20] + GetMyName(Pchar) + DLG_TEXT[21];
				link.l1 = DLG_TEXT[22];
				link.l1.go = "blaze_search_rheims_with_danielle_2";
			}
			if (pchar.quest.main_line == "blaze_goto_douwesen_with_danielle_2")
			{
				dialog.text = pchar.name + DLG_TEXT[23] + characters[getcharacterindex(DLG_TEXT[24])].name + DLG_TEXT[25];
				link.l1 = DLG_TEXT[26];
				link.l1.go = "blaze_goto_douwesen_with_danielle";
			}
			if (pchar.quest.main_line == "vincent_away_from_douwesen_tavern")
			{
				dialog.text = DLG_TEXT[27] + characters[GetCharacterIndex(DLG_TEXT[28])].name + DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "vincent_away_from_douwesen_tavern";
			}
			if (pchar.quest.main_line == "from_tavern_to_rheims_house")
			{
				dialog.text = GetMyName(PChar) + DLG_TEXT[31];
				link.l1 = DLG_TEXT[32] + characters[GetCharacterIndex(DLG_TEXT[33])].lastname + DLG_TEXT[34];
				link.l1.go = "runaway";
			}
			if (pchar.quest.main_line == "to_rheims_house")
			{
				dialog.text = DLG_TEXT[35];
				link.l1 = DLG_TEXT[36] + characters[GetCharacterIndex(DLG_TEXT[37])].lastname + DLG_TEXT[38];
				link.l1.go = "prepare_to_dagger";
			}
			if (pchar.quest.main_line == "resque_danielle")
			{
				dialog.text = GetMyName(PChar) + DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "resque_danielle";
			}
			if (pchar.quest.main_line == "to_secret_redmond_shore")
			{
				if (makeint(environment.time) >22.0 || makeint(environment.time) <5.0)
				{
					pchar.quest.main_line = "after_wait_for_night_in_shore";
				}
				else
				{
					dialog.text = DLG_TEXT[41];
					link.l1 = DLG_TEXT[42];
					link.l1.go = "wait_for_night_in_shore";
				}
			}
			if (pchar.quest.main_line == "after_wait_for_night_in_shore")
			{
				dialog.text = DLG_TEXT[43];
				link.l1 = DLG_TEXT[44];
				link.l1.go = "after_wait_for_night_in_shore";
			}
			if (pchar.quest.main_line == "both_escape_from_redmond" && pchar.location == "Redmond_shore_01")
			{
				dialog.text = DLG_TEXT[45];
				link.l1 = DLG_TEXT[46];
				link.l1.go = "both_escape_from_redmond_complete_2";
			}
			// разговор в квестовой таверне Редмонда
			if( CheckQuestAttribute("FindMysteriousTablet","EnterDenied") )
			{
				dialog.text = RandSwear() + DLG_TEXT[47];
				link.l1 = DLG_TEXT[48];
				link.l1.go = "exit";
				AddDialogExitQuest("DanielleTalkAboutAssault_enter");
				//addDialogExitQuest("before_talk_with_command");
			}
			if( CheckQuestAttribute("FindMysteriousTablet","PerorateAboutAssault") )
			{
				dialog.text = DLG_TEXT[49];
				link.l1 = DLG_TEXT[50];
				link.l1.go = "exit";
			}
			if( CheckQuestAttribute("Find_Blaze","Muelle_Ship_Stolen") )
			{
				dialog.text = DLG_TEXT[51];
				Link.l1 = DLG_TEXT[52];
				Link.l1.go = "exit";
				AddDialogExitQuest("danielle_muelle_bartender_talk");
			}
			if(CheckQuestAttribute("story_FindRheims","complete") && pchar.location == "Douwesen_town_exit")
			{
				dialog.text = DLG_TEXT[53];
				Link.l1 = " ";
				Link.l1.go = "exit";
				pchar.quest.story_FindRheims = "complete2";
			}
			if (CheckQuestAttribute("Find_Blaze", "Muelle_Ship_Stolen"))
			{
				dialog.text = DLG_TEXT[54] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[55])]) + DLG_TEXT[56];
				link.l1 = DLG_TEXT[57];
				link.l1.go = "exit";
			}
			// NK 04-10-01 move this here to take precedence
			if (pchar.quest.main_line == "danielle_wait_for_remove_companion")
			{
				dialog.text = DLG_TEXT[2] + GetMyName(Pchar) + DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "blaze_search_rheims_with_danielle_6"; 
			}
			// NK <--
			NextDiag.TempNode = "first time";
		break;

		case "to_the_ship":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("to_the_ship");
		break;

		case "not_to_the_ship":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("not_to_the_ship");
		break;

		case "escape_from_Isenbrandt_house":
			dialog.text = RandSwear() + DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "exit";
			NextDiag.TempNode = "first time";
		break;

		case "both_escape_from_redmond_complete_2":
			dialog.text = DLG_TEXT[67] + characters[GetCharacterIndex(DLG_TEXT[68])].lastname + DLG_TEXT[69] + characters[GetCharacterIndex(DLG_TEXT[70])].name + " " + characters[GetCharacterIndex(DLG_TEXT[71])].lastname + DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "both_escape_from_redmond_complete_3";
		break;

		case "both_escape_from_redmond_complete_3":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "both_escape_from_redmond_complete_4";
		break;

		case "both_escape_from_redmond_complete_4":
			dialog.text = DLG_TEXT[76] + GetMyName(Pchar) + DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit_both_escape_from_redmond_complete";
			AddQuestRecord("search_danielle", 4);
		break;

		case "exit_both_escape_from_redmond_complete":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			RemovePassenger(pchar, &characters[GetCharacterIndex("Danielle")]);
			ReStorePassengers("Blaze");
			RemoveCharacterCompanion(pchar, npchar);
			pchar.quest.main_line = "return_idol_from_greenford_soldier";
			pchar.quest.to_idol.win_condition.l1 = "location"; 
			pchar.quest.to_idol.win_condition.l1.location = "redmond"; 
			pchar.quest.to_idol.win_condition = "to_idol_complete"; 
		break;

		case "after_wait_for_night_in_shore":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "after_wait_for_night_in_shore_exit";
			AddQuestRecord("search_danielle", 2);
		break;

		case "after_wait_for_night_in_shore_exit":
			pchar.quest.main_line = "both_to_redmond_residence";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("both_to_residence_complete");
		break;

		case "wait_for_night_in_shore":
			pchar.quest.main_line = "after_wait_for_night_in_shore";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			//Выставляем ночь
			AddDialogExitQuest("wait_for_night_in_shore");
		break;

		case "resque_danielle":
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "resque_danielle_2";
		break;

		case "resque_danielle_2":
			dialog.text = DLG_TEXT[83] + GetMyName(Pchar) + DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "resque_danielle_3";
		break;

		case "resque_danielle_3":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87] + npchar.name + DLG_TEXT[88] + characters[getCharacterIndex(DLG_TEXT[89])].lastname + DLG_TEXT[90];
			link.l1.go = "resque_danielle_4";
		break;

		case "resque_danielle_4":
			dialog.text = DLG_TEXT[91] + GetMyName(Pchar) + DLG_TEXT[92];
			link.l1 = DLG_TEXT[93] + GetMyName(NPChar) + DLG_TEXT[94];
			link.l1.go = "resque_danielle_5";
		break;

		case "resque_danielle_5":
			Preprocessor_Add("gender", GetCharacterAddressForm(PChar, ADDR_GENDER, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "resque_danielle_6";
		break;

		case "resque_danielle_6":
			// DeathDaisy -->
			if(PChar.sex == "woman"){
				Preprocessor_Add("gender", "Women like you"); 
			}
			else{
				Preprocessor_Add("gender", FirstLetterUp(XI_ConvertString("Men")));
			}
			// DeathDaisy <--
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "resque_danielle_7";
		break;
		
		case "resque_danielle_7":
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100] + npchar.name + DLG_TEXT[101] + characters[GetCharacterIndex(DLG_TEXT[102])].lastname + DLG_TEXT[103];
			link.l1.go = "resque_danielle_8";
		break;

		case "resque_danielle_8":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "resque_danielle_9";
		break;
		
		case "resque_danielle_9":
			Preprocessor_Add("gender", GetCharacterAddressForm(PChar, ADDR_GENDER, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "resque_danielle_10";
		break;

		case "resque_danielle_10":
			dialog.text = GetMyName(PChar) + DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "resque_danielle_11";
		break;

		case "resque_danielle_11":
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "resque_danielle_12";
		break;

		case "resque_danielle_12":
			dialog.text = DLG_TEXT[112] + GetMyName(Pchar) + DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "resque_danielle_13";
		break;

		case "resque_danielle_13":
			dialog.text = DLG_TEXT[115] + GetMyName(Pchar) + DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "resque_danielle_14";
		break;

		case "resque_danielle_14":
			dialog.text = DLG_TEXT[118] + characters[GetCharacterIndex(DLG_TEXT[119])].lastname + DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "resque_danielle_15";
		break;

		case "resque_danielle_15":
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "resque_danielle_16";
		break;

		case "resque_danielle_16":
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "resque_danielle_17";
		break;

		case "resque_danielle_17":
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "resque_danielle_18";
		break;

		case "resque_danielle_18":
			dialog.text = DLG_TEXT[128] + GetMyName(Pchar) + DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "officer_exit";
			pchar.quest.main_line = "to_secret_redmond_shore";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("search_danielle", 23);
			CloseQuestHeader("search_danielle");
			Preprocessor_Remove("Danielle");
			SetQuestHeader("revenge_for_silehard");
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("Pronoun_upper", FirstLetterUp(XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle")))));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
			AddQuestRecord("revenge_for_silehard", 1);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("Pronoun_upper");
			Preprocessor_Remove("Danielle");
		break;

		case "officer_exit":
			SetCompanionIndex(pchar, -1, GetCharacterIndex(npchar.id));
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("resque_danielle");
		break;

		case "prepare_to_dagger":
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "DAGGER";
		break;

		case "DAGGER":
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestrecord("again_find_rheims", "6");
			Preprocessor_Remove("Danielle");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("dagger");
		break;

		case "runaway":			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			
			AddDialogExitQuest("prepare_danielle_with_rheims_runaway_complete");
		break;

		case "vincent_away_from_douwesen_tavern":
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "vincent_away_from_douwesen_tavern_2";
		break;

		case "vincent_away_from_douwesen_tavern_2":
			dialog.text = DLG_TEXT[135] + GetMyName(Pchar) + DLG_TEXT[136];
			link.l1 = DLG_TEXT[137] + GetMyName(NPChar) + DLG_TEXT[138];
			link.l1.go = "vincent_away_from_douwesen_tavern_3";
		break;

		case "vincent_away_from_douwesen_tavern_3":
			dialog.text = DLG_TEXT[139] + characters[GetCharacterIndex(DLG_TEXT[140])].lastname + DLG_TEXT[141];
			link.l1 = DLG_TEXT[142];
			link.l1.go = "exit";
			pchar.quest.main_line = "talk_with_rheims_in_douwesen_tavern";
		break;

		case "blaze_goto_douwesen_with_danielle":
			dialog.text = DLG_TEXT[143] + GetMyName(Pchar) + DLG_TEXT[144] + characters[GetCharacterIndex(DLG_TEXT[145])].lastname + DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "exit";
		break;

		case "blaze_search_rheims_with_danielle_2":
			dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[150])]) + DLG_TEXT[151];
			link.l1.go = "blaze_search_rheims_with_danielle_3";
		break;

		case "blaze_search_rheims_with_danielle_3":
			dialog.text = DLG_TEXT[152];
			link.l1 = DLG_TEXT[153] + characters[getCharacterIndex(DLG_TEXT[154])].name + DLG_TEXT[155];
			link.l1.go = "blaze_search_rheims_with_danielle_4";
		break;

		case "blaze_search_rheims_with_danielle_4":
			dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "blaze_search_rheims_with_danielle_5";
		break;

		case "blaze_search_rheims_with_danielle_5":
			dialog.text = DLG_TEXT[158] + characters[getCharacterIndex(DLG_TEXT[159])].name + DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			link.l1.go = "blaze_search_rheims_with_danielle_6";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("Pronoun", FirstLetterUp(XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle")))));
			AddQuestrecord("again_find_rheims", "3");
			Preprocessor_Remove("Pronoun");
			Preprocessor_Remove("Danielle");
		break;

		case "blaze_search_rheims_with_danielle_6":
			if (SetCompanionIndex(pchar, -1, GetCharacterIndex(npchar.id)) == GetCharacterIndex(npchar.id) && FindFellowtravellers(PChar, NPChar) == FELLOWTRAVEL_NO) // NK 04-10-01
			{
				dialog.text = DLG_TEXT[162];
				link.l1 = DLG_TEXT[163];
				link.l1.go = "exit";
				pchar.quest.main_line = "danielle_wait_for_remove_companion";
				LAi_SetStayType(characterFromID("danielle"));
			}
			else
			{
				dialog.text = DLG_TEXT[164];
				link.l1 = DLG_TEXT[165];
				link.l1.go = "exit";
				AddDialogExitQuest("danielle_join_to_us_when_we_are_swimm_to_douwesen_fo_search_rheims");
			}
		break;

		case "speak_danielle_in_lighthouse_prepare_to_search_rheims_2":
			dialog.text = DLG_TEXT[166] + GetMyName(Pchar) + DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "speak_danielle_in_lighthouse_prepare_to_search_rheims_3";
		break;

		case "speak_danielle_in_lighthouse_prepare_to_search_rheims_3":
			dialog.text = DLG_TEXT[169];
			link.l1  = DLG_TEXT[170];
			link.l1.go = "first_exit_from_lighthouse";
			pchar.quest.main_line = "blaze_again_find_rheims";
			Preprocessor_AddQuestData("Danielle", GetMyName(NPChar));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(NPChar)));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(NPChar)));
			if (NPChar.sex == "woman") Preprocessor_AddQuestData("pronoun3", XI_ConvertString("her"));
			else Preprocessor_AddQuestData("pronoun3", XI_ConvertString("his"));
			SetQuestHeader("again_find_rheims");
			AddQuestRecord("again_find_rheims", "1");
			Preprocessor_Remove("pronoun3");
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("Danielle");
		break;

		case "first_exit_from_lighthouse":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			locations[FindLocation("Oxbay_Lighthouse")].reload.l1.disable = 0;
		break;

		case "meet_danielle_in_lighthouse_2":
			dialog.text = DLG_TEXT[171] + GetMyName(Pchar) + DLG_TEXT[172];
			link.l1 = DLG_TEXT[173];
			link.l1.go = "meet_danielle_in_lighthouse_3";
		break;

		case "meet_danielle_in_lighthouse_3":
			dialog.text = DLG_TEXT[174] + pchar.name + DLG_TEXT[175] + characters[GetCharacterIndex(DLG_TEXT[176])].name + DLG_TEXT[177] + characters[GetCharacterIndex(DLG_TEXT[178])].name + " " + characters[GetCharacterIndex(DLG_TEXT[179])].lastname + DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "meet_danielle_in_lighthouse_4";
		break;

		case "meet_danielle_in_lighthouse_4":
			dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[183];
			link.l1.go = "meet_danielle_in_lighthouse_5";
		break;

		case "meet_danielle_in_lighthouse_5":
			dialog.text = DLG_TEXT[184] + pchar.lastname + DLG_TEXT[185];
			link.l1 = DLG_TEXT[186] + GetMyName(NPChar) + DLG_TEXT[187] + characters[GetCharacterIndex(DLG_TEXT[188])].lastname + DLG_TEXT[189];
			link.l1.go = "meet_danielle_in_lighthouse_6";
		break;

		case "meet_danielle_in_lighthouse_6":
			dialog.text = DLG_TEXT[190] + characters[GetCharacterIndex(DLG_TEXT[191])].name + DLG_TEXT[192];
			link.l1 = DLG_TEXT[193];
			link.l1.go = "meet_danielle_in_lighthouse_7";
		break;

		case "meet_danielle_in_lighthouse_7":
			dialog.text = DLG_TEXT[194] + pchar.name + DLG_TEXT[195];
			link.l1 = DLG_TEXT[196] + npchar.name + DLG_TEXT[197] + characters[GetCharacterIndex(DLG_TEXT[198])].name + DLG_TEXT[199] + characters[GetCharacterIndex(DLG_TEXT[200])].lastname + DLG_TEXT[201];
			link.l1.go = "meet_danielle_in_lighthouse_8";
		break;

		case "meet_danielle_in_lighthouse_8":
			dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[203];
			link.l1.go = "exit";
			pchar.quest.main_line = "meet_Vincent_in_lighthouse";
		break;

		case "talk_in_tavern":
			if(PChar.sex == "woman")
			{
				Dialog.Text = DLG_TEXT[562];
				Link.l1 = DLG_TEXT[563] + GetMyName(NPChar) + DLG_TEXT[564];
			}
			else
			{
				Dialog.Text = DLG_TEXT[204] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[205])]) + DLG_TEXT[206];
				Link.l1 = DLG_TEXT[207];
			}
			Link.l1.go = "exit";
			AddDialogExitQuest("prepare_to_battle_in_quest_redmond_tavern");
		break;

		case "talk_in_tavern_1":
			Dialog.Text = DLG_TEXT[208] + GetMyName(Pchar) + DLG_TEXT[209];
			link.l1 = DLG_TEXT[210];
			link.l1.go = "talk_in_tavern_2";
		break;

		case "talk_in_tavern_2":
			dialog.text = DLG_TEXT[211];
			link.l1 = DLG_TEXT[212];
			link.l1.go = "exit";
			AddDialogExitQuest("danielle_exit_from_tavern_danielle");
		break;

		case "MetBlazeOnIslaMuelle":
			Dialog.defAni = "";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
						
			NextDiag.TempNode = "first time";

			dialog.text = GetMyName(PChar) + DLG_TEXT[213];
			Link.l1 = GetMyName(NPChar) + DLG_TEXT[214];
			Link.l1.go = "MetBlazeOnIslaMuelle_1";
		break;

		case "MetBlazeOnIslaMuelle_1":
			Dialog.Text = DLG_TEXT[215];
			Link.l1 = DLG_TEXT[216];
			Link.l1.go = "MetBlazeOnIslaMuelle_2";
		break;

		case "MetBlazeOnIslaMuelle_2":
			Dialog.Text = DLG_TEXT[217];
			Link.l1 = DLG_TEXT[218];
			Link.l1.go = "MetBlazeOnIslaMuelle_3";
		break;

		case "MetBlazeOnIslaMuelle_3":
			Dialog.Text = DLG_TEXT[219];
			Link.l1 = DLG_TEXT[220];
			Link.l1.go = "MetBlazeOnIslaMuelle_4";
		break;

		case "MetBlazeOnIslaMuelle_4":
			Dialog.Text = DLG_TEXT[221];
			Link.l1 = DLG_TEXT[222] + GetMyName(NPChar) + DLG_TEXT[223];
			Link.l1.go = "MetBlazeOnIslaMuelle_5";
		break;

		case "MetBlazeOnIslaMuelle_5":
			Dialog.Text = DLG_TEXT[224];
			Link.l1 = DLG_TEXT[225];
			Link.l1.go = "MetBlazeOnIslaMuelle_6";
		break;

		case "MetBlazeOnIslaMuelle_6":
			Dialog.Text = DLG_TEXT[226];
			Link.l1 = DLG_TEXT[227];
			Link.l1.go = "MetBlazeOnIslaMuelle_7";
		break;

		case "MetBlazeOnIslaMuelle_7":
			Dialog.Text = DLG_TEXT[228];
			Link.l1 = DLG_TEXT[229];
			Link.l1.go = "MetBlazeOnIslaMuelle_Exit";
		break;


		case "Talk_upstairs":
			Dialog.Text = DLG_TEXT[230];
			Link.l1 = DLG_TEXT[231] + GetMyName(NPChar) + DLG_TEXT[232];
			Link.l1.go = "Talk_upstairs_1";
		break;

		case "Talk_upstairs_1":
			Dialog.Text = DLG_TEXT[233] + GetMyName(Pchar) + DLG_TEXT[234];
			Link.l1 = DLG_TEXT[235];
			Link.l1.go = "Talk_upstairs_2";
		break;

		case "Talk_upstairs_2":
			Preprocessor_Add("the Governor", characters[GetCharacterIndex("Robert Christopher Silehard")].lastname); // KK
			Dialog.Text = DLG_TEXT[236];
			Link.l1 = DLG_TEXT[237];
			Link.l1.go = "Talk_upstairs_3";
		break;

		case "Talk_upstairs_3":
			Dialog.Text = DLG_TEXT[238];
			Link.l1 = DLG_TEXT[239] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[240])]) + DLG_TEXT[241];
			Link.l1.go = "Talk_upstairs_4";
		break;

		case "Talk_upstairs_4":
			Dialog.Text = DLG_TEXT[242];
			Link.l1 = DLG_TEXT[243];
			Link.l1.go = "Talk_upstairs_Exit";
		break;

		case "MetInMuellePort":
			Dialog.Text = DLG_TEXT[244];
			Link.l1 = DLG_TEXT[245];
			Link.l1.go = "MetInMuellePort_1";
		break;

		case "MetInMuellePort_1":
			Dialog.Text = DLG_TEXT[246];
			Link.l1 = DLG_TEXT[247];
			Link.l1.go = "MetInMuellePort_Exit";
		break;

		case "MetInMuellePort_1":
			Dialog.Text = DLG_TEXT[248];
			Link.l1 = DLG_TEXT[249];
			Link.l1.go = "MetInMuellePort_Exit";
		break;

		case "CaptureGreenford":
			if(PChar.sex == "woman")
			{
				Preprocessor_Add("Governor", Characters[GetCharacterIndex("Robert Christopher Silehard")].lastname); // KK
				Preprocessor_Add("Researcher", GetMyLastName(CharacterFromID(DLG_TEXT[341])));
				dialog.text = DLG_TEXT[565];
				link.l1 = DLG_TEXT[566];
				link.l1.go = "CaptureGreenford_2_danielle";
			}
			else
			{
				Dialog.Text = DLG_TEXT[250] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[251])]) + DLG_TEXT[252];
				Link.l1 = DLG_TEXT[253];
				Link.l1.go = "CaptureGreenford_1";
			}
		break;

		case "CaptureGreenford_1":
			Dialog.Text = DLG_TEXT[254];
			Link.l1 = DLG_TEXT[255];
			Link.l1.go = "CaptureGreenford_2";
		break;

		case "CaptureGreenford_2":
			Dialog.Text = DLG_TEXT[256];
			Link.l1 = DLG_TEXT[257];
			Link.l1.go = "CaptureGreenford_3";
		break;

		case "CaptureGreenford_3":
			Dialog.Text = DLG_TEXT[258];
			Link.l1 = DLG_TEXT[259];
			Link.l1.go = "CaptureGreenford_4";
		break;

		case "CaptureGreenford_2_danielle":
			dialog.text = DLG_TEXT[567];
			link.l1 = DLG_TEXT[568];
			link.l1.go = "CaptureGreenford_3_danielle";
		break;

		case "CaptureGreenford_3_danielle":
			dialog.text = DLG_TEXT[569] + GetMyName(PChar) + DLG_TEXT[570];
			Link.l1 = DLG_TEXT[571];
			Link.l1.go = "CaptureGreenford_5";
		break;

		case "CaptureGreenford_4":
			Dialog.Text = DLG_TEXT[260];
			Link.l1 = DLG_TEXT[261];
			Link.l1.go = "CaptureGreenford_5";
		break;

		case "CaptureGreenford_5":
			NextDiag.TempNode = "GoToShip";
			if(PChar.sex == "woman") Dialog.Text = DLG_TEXT[572];
			else Dialog.Text = DLG_TEXT[262];
			Link.l1 = DLG_TEXT[263];
			Link.l1.go = "CaptureGreenford_exit";
			Link.l2 = DLG_TEXT[264];
			Link.l2.go = "We_Are_ready_exit";
		break;

		case "CaptureGreenford_6":
			NextDiag.TempNode = "KickTheAss";
			Dialog.Text = DLG_TEXT[265];
			Link.l1 = DLG_TEXT[266];
			Link.l1.go = "We_Are_ready_exit";
			Link.l2 = DLG_TEXT[267];
			Link.l2.go = "CaptureGreenford_exit";
		break;

		case "KickTheAss":
			NextDiag.TempNode = "KickTheAss";
			Dialog.Text = DLG_TEXT[268];
			Link.l1 = DLG_TEXT[269];
			Link.l1.go = "Exit";
		break;

		case "GoToShip":
			Dialog.Text = DLG_TEXT[270] + GetMyName(Pchar) + DLG_TEXT[271];
			Link.l1 = DLG_TEXT[272];
			Link.l1.go = "Exit";
		break;
		
		case "WaitUntilReady":
			Dialog.Text = DLG_TEXT[273];
			Link.l1 = DLG_TEXT[274];
			Link.l1.go = "Exit";
		break;

		case "Are_we_ready":
			Dialog.Text = DLG_TEXT[275];
			Link.l1 = DLG_TEXT[276];
			Link.l1.go = "Are_we_ready_3";
			Link.l2 = DLG_TEXT[277];
			Link.l2.go = "Are_we_ready_2";
		break;

		case "Are_we_ready_2":
			Dialog.Text = DLG_TEXT[278] + GetMyName(Pchar) + DLG_TEXT[279];
			Link.l1 = DLG_TEXT[280];
			Link.l1.go = "We_Are_not_ready_exit";
		break;

		case "Are_we_ready_3":
			Dialog.Text = DLG_TEXT[281];
			Link.l1 = DLG_TEXT[282];
			Link.l1.go = "Are_we_ready_4";
		break;

		case "Are_we_ready_4":
			Dialog.Text = DLG_TEXT[283] + GetMyName(Pchar) + DLG_TEXT[284];
			Link.l1 = DLG_TEXT[285] + GetMyName(NPChar) + DLG_TEXT[286];
			Link.l1.go = "We_Are_Ready_Exit";
		break;

		case "Greenford_captured":
			Dialog.Text = DLG_TEXT[287];
			Link.l1 = DLG_TEXT[288];
			Link.l1.go = "Greenford_captured_1";
		break;

		case "Greenford_captured_1":
			NextDiag.TempNode = "MovingToPrison";
			Dialog.Text = DLG_TEXT[289];
			Link.l1 = DLG_TEXT[290] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[291])]) + DLG_TEXT[292];
			Link.l1.go = "Greenford_captured_exit";
		break;

		case "MovingToPrison":
			NextDiag.TempNode = "MovingToPrison";
			Dialog.Text = GetMyName(PChar) + DLG_TEXT[293];
			Link.l1 = DLG_TEXT[294];
			Link.l1.go = "Exit";
		break;

// KK -->
		case "WaitInGreenford":
			Dialog.Text = DLG_TEXT[544];
			if (GetCompanionQuantity(PChar) == 1)
				Link.l1 = DLG_TEXT[545] + " " + DLG_TEXT[546] + DLG_TEXT[548];
			else
				Link.l1 = DLG_TEXT[545] + " " + DLG_TEXT[547] + DLG_TEXT[548];
			Link.l1.go = "WaitInGreenford_Exit";
		break;

		case "WaitInGreenford_Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Story_WaitInGreenford");
		break;
// <-- KK

		case "BeforeEnglishSiege":
			NextDiag.TempNode = "RepelTheSiege";
			Dialog.Text = DLG_TEXT[295];
			Link.l1 = GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[296])]) + DLG_TEXT[297];
			Link.l1.go = "BeforeEnglishSiege_1";
		break;

		case "BeforeEnglishSiege_1":
			Dialog.Text = DLG_TEXT[298];
			Link.l1 = DLG_TEXT[299];
			Link.l1.go = "BeforeEnglishSiege_2";
		break;

		case "BeforeEnglishSiege_2":
			Dialog.Text = DLG_TEXT[300];
			Link.l1 = DLG_TEXT[301];
			Link.l1.go = "BeforeEnglishSiege_3";
		break;

		case "BeforeEnglishSiege_3":
			Dialog.Text = DLG_TEXT[302] + GetMyName(Pchar) + DLG_TEXT[303];
			Link.l1 = DLG_TEXT[304];
			Link.l1.go = "BeforeEnglishSiege_4";
		break;

		case "BeforeEnglishSiege_4":
			Dialog.Text = DLG_TEXT[305];
			Link.l1 = DLG_TEXT[306];
			Link.l1.go = "BeforeEnglishSiege_5";
		break;

		case "BeforeEnglishSiege_5":
			Dialog.Text = DLG_TEXT[307];
			Link.l1 = DLG_TEXT[308];
			Link.l1.go = "BeforeEnglishSiege_exit";
		break;

		case "RepelEnglishAssault":
			Dialog.defAni = "dialog_stay1";
			//Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			//Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			//Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			Dialog.Text = DLG_TEXT[309];
			Link.l1 = DLG_TEXT[310];
			Link.l1.go = "RepelEnglishAssault_1";
		break;

		case "RepelEnglishAssault_1":
			NextDiag.TempNode = "Must_Hurry_to_Fort";			
			Dialog.Text = DLG_TEXT[311];
			Link.l1 = DLG_TEXT[312];
			Link.l1.go = "RepelEnglishAssault_exit";
		break;

		case "AfterGreenfordSiege":
			Dialog.Text = DLG_TEXT[313];
			Link.l1 = DLG_TEXT[314] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[315])]) + DLG_TEXT[316];
			Link.l1.go = "AfterGreenfordSiege_1";
		break;

		case "AfterGreenfordSiege_1":
			NextDiag.TempNode = "PayVisitToResearcher";
			if (NPChar.sex == "woman") Dialog.Text = DLG_TEXT[317] + GetMyName(Pchar) + DLG_TEXT[318];
			else Dialog.Text = DLG_TEXT[317] + GetMyName(Pchar) + DLG_TEXT[549];
			Link.l1 = DLG_TEXT[319];
			Link.l1.go = "AfterGreenfordSiege_exit";
		break;

		case "PayVisitToResearcher":
			Dialog.Text = DLG_TEXT[320];
			Link.l1 = DLG_TEXT[321];
			Link.l1.go = "Exit";
		break;

		case "Temple":
			NextDiag.TempNode = "GoGoGo";
			Dialog.Text = GetMyName(PChar) + DLG_TEXT[322];
			Link.l1 = DLG_TEXT[323];
			Link.l1.go = "GoGoGo";
		break;

		case "GoGoGo":
			NextDiag.TempNode = "Gogogo_1";
			Dialog.Text = DLG_TEXT[324];
			Link.l1 = DLG_TEXT[325];
			Link.l1.go = "Gogogo_1";
		break;

		case "Gogogo_1":
			Dialog.Text = DLG_TEXT[326];
			Link.l1 = DLG_TEXT[327];
			Link.l1.go = "Temple_exit";
		break;

		case "Split":
			Dialog.Text = DLG_TEXT[328];
			Link.l1 = DLG_TEXT[329] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[330])]) + DLG_TEXT[331];
			Link.l1.go = "Split_exit";
		break;

		case "I'm going on left":
			Dialog.Text = DLG_TEXT[332];
			Link.l1 = DLG_TEXT[333];
			Link.l1.go = "I'm going on left_exit";
		break;

		case "ReadyForKhaelRoa":
			Dialog.TempNode = "ReadyForKhaelRoa";
			Dialog.Text = DLG_TEXT[334];
			Link.l1 = DLG_TEXT[335];
			Link.l1.go = "exit";
		break;

		case "ITakeTheStone":
			Dialog.Text = DLG_TEXT[336];
			Link.l1 = DLG_TEXT[337];
			Link.l1.go = "ITakeTheStone_1";
		break;

		case "ITakeTheStone_1":
			Dialog.Text = DLG_TEXT[338];
			Link.l1 = DLG_TEXT[339];
			Link.l1.go = "ITakeTheStone_exit";
		break;

		case "ITakeTheStone_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;	
			AddDialogExitQuest("Story_ITakeTheStone");
		break;

		case "Treasure_room":
			Dialog.TempNode = "ReadyForKhaelRoa";
			Dialog.Text = DLG_TEXT[340] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[341])]) + DLG_TEXT[342];
			Link.l1 = DLG_TEXT[343];
			Link.l1.go = "Treasure_room_exit";
		break;

		case "Must_Hurry_to_Fort":
			Dialog.TempNode = "Must_Hurry_to_Fort";
			Dialog.Text = DLG_TEXT[344] + GetMyName(Pchar) + DLG_TEXT[345];
			Link.l1 = DLG_TEXT[346];
			Link.l1.go = "Must_Hurry_to_Fort_1";
		break;

		case "Must_Hurry_to_Fort_1":
			Dialog.Text = DLG_TEXT[347] + GetMyName(Pchar) + DLG_TEXT[348];
			Link.l1 = DLG_TEXT[349];
			Link.l1.go = "RepelEnglishAssault_again_exit";
		break;

		case "WhatWasThat":
			Dialog.TempNode = "OMyTreasure";
			Dialog.Text = DLG_TEXT[350];
			Link.l1 = DLG_TEXT[351];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_ResearcherExplainsInTemple");
		break;

		case "OMyTreasure":
			Dialog.TempNode = "OMyTreasure";
			Dialog.Text = DLG_TEXT[352] + GetMyName(Pchar) + DLG_TEXT[353];
			Link.l1 = DLG_TEXT[354];
			Link.l1.go = "OMyTreasure_1";			
		break;

		case "OMyTreasure_1":
			Dialog.Text = DLG_TEXT[355];
			Link.l1 = DLG_TEXT[356];
			Link.l1.go = "exit";			
		break;

		case "TooDangerous":
			Dialog.Text = DLG_TEXT[357];
			Link.l1 = " ";
			Link.l1.go = "exit";			
		break;

		case "ThinkingAboutQuebradas":
			AddDialogExitQuest("Fem_ReadyToleaveRedmondForQuebradas");
			Dialog.Text = DLG_TEXT[358] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[359])]) + DLG_TEXT[360] + Characters[getCharacterIndex(DLG_TEXT[361])].lastname + DLG_TEXT[362] + Characters[getCharacterIndex(DLG_TEXT[363])].lastname + DLG_TEXT[364] + Characters[getCharacterIndex(DLG_TEXT[365])].lastname + DLG_TEXT[366] + Characters[getCharacterIndex(DLG_TEXT[367])].lastname + DLG_TEXT[368];
			Link.l1 = " ";
			Link.l1.go = "exit";			
		break;

		case "RheimsLogBook":			
			Dialog.Text = DLG_TEXT[369] + Characters[GetCharacterIndex(DLG_TEXT[370])].lastname + DLG_TEXT[371] + Characters[GetCharacterIndex(DLG_TEXT[372])].lastname + DLG_TEXT[373] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[374])]) + DLG_TEXT[375] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[376])]) + DLG_TEXT[377];
			Link.l1 = DLG_TEXT[378];
			Link.l1.go = "RheimsLogBook_2";			
			Link.l2 = DLG_TEXT[379];
			Link.l2.go = "RheimsLogBook_1";			
		break;

		case "RheimsLogBook_1":			
			Dialog.Text = DLG_TEXT[380];
			Link.l1 = " ";
			Link.l1.go = "exit";			
		break;

		case "RheimsLogBook_2":			
			Dialog.Text = DLG_TEXT[381] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[382])]) + DLG_TEXT[383];
			Link.l1 = " ";
			Link.l1.go = "exit";			
		break;

		
		case "Treasure_room_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;	
			AddDialogExitQuest("Story_ResearcherTalkInAlcove");
		break;

		case "I'm going on left_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
			AddDialogExitQuest("Story_DanielleWentIntoLeftPassage");
		break;

		case "Split_exit":
			DialogExit();
			NextDiag.TempNode = "Clement_home";
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Danielle_split_exit");
		break;

		case "Temple_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
//			NextDiag.TempNode = "Clement_home";
			NextDiag.TempNode = "Why_are_we_waiting";

			DoQuestCheckDelay("Story_ResearcherSpeaksonKhaelRoaBeach", 1);
		break;

		case "Why_are_we_waiting":
			Dialog.text = DLG_TEXT[554] + GetMyName(PChar) + DLG_TEXT[555];
			Link.l1 = DLG_TEXT[556] + GetMyName(NPChar) + DLG_TEXT[557];
			Link.l1.go = "Exit";
		break;

		case "AfterGreenfordSiege_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_AfterGreenfordSiege_exit");
		break;

		case "RepelEnglishAssault_again_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_RepelEnglishAssault_again_exit");
		break;

		
		case "RepelEnglishAssault_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_RepelEnglishAssault_exit");
		break;


		case "BeforeEnglishSiege_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("danielle_BeforeEnglishSiege_exit");
		break;

		case "Greenford_captured_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("danielle_Greenford_captured_exit");
		break;

		case "We_Are_not_ready_exit":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "WaitUntilReady";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition.l1 = "location";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition.l1.location = "Oxbay";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition = "Story_PrepareToSiegeGreenford";
			Pchar.quest.Story_PrepareToSiegeGreenford.fail_condition = "Story_PrepareToSiegeGreenford";

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "We_Are_ready_exit":
			EndQuestMovie();TrackQuestMovie("end","danielle_dialog.c -> We_Are_ready_exit");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			SetQuestHeader("Capture_greenford");
			AddQuestRecord("Capture_greenford", 2);
			Preprocessor_Remove("Danielle");

			AddDialogExitQuest("Story_GreenfordAssaultStarted");
		break;

		case "CaptureGreenford_exit":
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			SetQuestHeader("Capture_greenford");
			AddQuestRecord("Capture_greenford", 1);
			Preprocessor_Remove("Danielle");

			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition.l1 = "location";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition.l1.location = "Oxbay";
			Pchar.quest.Story_PrepareToSiegeGreenford.win_condition = "Story_PrepareToSiegeGreenford";
			Pchar.quest.Story_PrepareToSiegeGreenford.fail_condition = "Story_PrepareToSiegeGreenford";

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "MetBlazeOnIslaMuelle_Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_MetBlazeOnIslaMuelle_Exit");
		break;

		case "MetInMuellePort_Exit":			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_MetInMuellePort_Exit");
			/*Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1 = "locator";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1.character = "Danielle";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1.location = "Muelle_port";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1.locator_group = "Reload";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition.l1.locator = "Reload3";
			Pchar.quest.Story_DanielleGoesToBlazeShip.win_condition = "Story_DanielleGoesToBlazeShip";
			Pchar.quest.Story_DanielleGoesToBlazeShip.fail_condition = "Story_DanielleGoesToBlazeShip";
			//ActGotoLocator(NPChar, "Reload", "reload3",1);*/
		break;


		case "Talk_upstairs_Exit":
			AddDialogExitQuest("danielle_Talk_upstairs_Exit");
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// --> CatalinaThePirate Fix for Danielle after final


		case "Clement_home":
			Dialog.Text = DLG_TEXT[456] + GetMyName(Pchar) + DLG_TEXT[457];
			if(checkquestattribute("Silehard_defeat", "prison") || checkquestattribute("Silehard_defeat", "dead"))
			{
				Link.l1 = DLG_TEXT[550];
				Link.l1.go = "What_to_do_next";		
			}
			else
			{
				Link.l1 = DLG_TEXT[458];
				Link.l1.go = "Clement_home2";	
			}
		break;
		
		case "Clement_home2":
			Dialog.Text = DLG_TEXT[459];
			Link.l1 = DLG_TEXT[460];
			AddDialogExitQuest("Story_Danielle_back_to_officer");
			Link.l1.go = "exit";
			NextDiag.TempNode = "Remind_about_Redmond";
//			AddDialogExitQuest("end_game2");	// Now follows on from quest case "end_game"			
		break;

		case "Remind_about_Redmond":
			Dialog.Text = DLG_TEXT[573];
			Link.l1 = DLG_TEXT[574] + GetMyName(NPChar) + DLG_TEXT[575];
			Link.l1.go = "exit";			
		break;
		
		case "After_Final2":
			Preprocessor_Add("Danielle", GetMyName(NPChar));
			Dialog.Text = DLG_TEXT[384] + GetMyName(Pchar) + DLG_TEXT[385];
			Link.l1 = DLG_TEXT[386];
			Link.l1.go = "After_Final3";			
		break;			
		
		case "After_Final3":
			Dialog.Text = DLG_TEXT[387];
			Link.l1 = DLG_TEXT[388];
			Link.l1.go = "After_Final4";			
		break;
		
		case "After_Final4":
			Dialog.Text = DLG_TEXT[389];
			Link.l1 = DLG_TEXT[390];
			Link.l1.go = "After_Final5";
		break;
		
		case "After_Final5":
			Dialog.Text = DLG_TEXT[391];
			Link.l1 = DLG_TEXT[392];
			Link.l1.go = "After_Final6";
			Link.l2 = DLG_TEXT[393];
			Link.l2.go = "After_Final11";
		break;
		
		case "After_Final6":
			Dialog.Text = DLG_TEXT[394] + GetMyName(Pchar) + DLG_TEXT[395];
			Link.l1 = DLG_TEXT[396];
			Link.l1.go = "After_Final7";
		break;
		
		case "After_Final7":
			Preprocessor_Add("Danielle", GetMyName(NPChar));
			Dialog.Text = DLG_TEXT[397];
			Link.l1 = DLG_TEXT[398];
			Link.l1.go = "After_Final8";
		break;
		
		case "After_Final8":
			Dialog.Text = DLG_TEXT[399];
			Link.l1 = DLG_TEXT[400];
			Link.l1.go = "After_Final9";
		break;
		
		case "After_Final9":
			Dialog.Text = DLG_TEXT[401];
			Link.l1 = DLG_TEXT[402];
			Link.l1.go = "After_Final10";
		break;
		
		case "After_Final10":
			Dialog.Text = DLG_TEXT[403];
			Link.l1 = DLG_TEXT[404];
			Link.l1.go = "After_Final_Exit";
		break;
		
		case "After_Final11":
			Dialog.Text = DLG_TEXT[405];
			Link.l1 = DLG_TEXT[406];
			Link.l1.go = "After_Final12";
		break;
		
		case "After_Final12":
			if (NPChar.sex == "woman") Preprocessor_Add("kid", XI_ConvertString("girl"));
			else Preprocessor_Add("kid", XI_ConvertString("lad"));
			Preprocessor_Add("Danielle", GetMyName(NPChar));
			Dialog.Text = DLG_TEXT[407];
			Link.l1 = DLG_TEXT[408];
			Link.l1.go = "After_Final13";
		break;
		
		case "After_Final13":
			Dialog.Text = DLG_TEXT[409];
			Link.l1 = DLG_TEXT[410];
			Link.l1.go = "After_Final14";
		break;
		
		case "After_Final14":
			Preprocessor_Add("Danielle", GetMyName(NPChar));
			Preprocessor_Add("pronoun2", GetMyPronounObj(PChar)); // DeathDaisy
			Dialog.Text = DLG_TEXT[411] + GetMyName(Pchar) + DLG_TEXT[412];
			Link.l1 = DLG_TEXT[413];
			Link.l1.go = "After_Final15";
		break;
		
		case "After_Final15":
			if(PChar.sex == "woman"){
				Preprocessor_Add("genders", XI_ConvertString("women"));
			}
			else{
				Preprocessor_Add("genders", XI_ConvertString("men"));
			}
			Dialog.Text = DLG_TEXT[414];
			Link.l1 = DLG_TEXT[415];
			Link.l1.go = "After_Final16";
		break;
		
		case "After_Final16":
			Dialog.Text = DLG_TEXT[416];
			Link.l1 = DLG_TEXT[417];
			Link.l1.go = "After_Final10";
		break;
		
		case "After_Final_Exit":
			LAi_SetOfficerType(characterFromID("Danielle"));
			NextDiag.TempNode = "Reward_for_Silehard";
		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "What_to_do_next":
			NextDiag.TempNode = "Hired";
			Dialog.Text = DLG_TEXT[551] + GetMyName(PChar) + "?";
			Link.l1 = DLG_TEXT[552] + GetMyName(NPChar) + DLG_TEXT[553];
			AddDialogExitQuest("Story_Danielle_back_to_officer");
			Link.l1.go = "exit";
		break;
		
		case "Reward_for_Silehard":
			if (checkquestattribute("danielle_asks", "true"))
			{
				Dialog.Text = DLG_TEXT[418] + GetMyName(Pchar) + DLG_TEXT[419];
				Link.l1 = DLG_TEXT[420];
				Link.l1.go = "Reward_for_Silehard2";
			}
			else
			{
				Dialog.Text = DLG_TEXT[453] + GetMyName(Pchar) + DLG_TEXT[454];
				Link.l1 = DLG_TEXT[455];
				Link.l1.go = "After_Final_Exit";
			}
		break;
		
		case "Reward_for_Silehard2":
			Dialog.Text = DLG_TEXT[421];
			Link.l1 = DLG_TEXT[422];
			Link.l1.go = "Reward_for_Silehard3";
		break;
		
		case "Reward_for_Silehard3":
			Dialog.Text = DLG_TEXT[423];
			Link.l1 = DLG_TEXT[424];
			Link.l1.go = "Reward_for_Silehard4";
		break;

		case "Reward_for_Silehard4":
			Dialog.Text = DLG_TEXT[425];
			Link.l1 = DLG_TEXT[426];
			Link.l1.go = "Danielle_departs";
			Link.l2 = DLG_TEXT[427];
			Link.l2.go = "Danielle_stays2";
		break;
		
		case "Danielle_departs":
			Dialog.Text = DLG_TEXT[428];
			Link.l1 = DLG_TEXT[429];
			Link.l1.go = "Danielle_departs2";
		break;
		
		case "Danielle_departs2":
			Dialog.Text = DLG_TEXT[430];
			Link.l1 = DLG_TEXT[431];
			Link.l1.go = "Danielle_departs3";
			Link.l2 = DLG_TEXT[432];
			Link.l2.go = "Danielle_stays2";
		break;	
		
		case "Danielle_departs3":
			Dialog.Text = DLG_TEXT[433];
			Link.l1 = DLG_TEXT[434];
			Link.l1.go = "Danielle_departs4";
			if (checkquestattribute("Silehard_defeat", "prison"))
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -200000);
			}
			if (checkquestattribute("Silehard_defeat", "dead"))
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -100000);
			}
		break;	
		
		case "Danielle_departs4":
			Dialog.Text = DLG_TEXT[435] + GetMyName(Pchar) + DLG_TEXT[436];
			Link.l1 = DLG_TEXT[437];
			Link.l1.go = "Danielle_departs5";
		break;
		
		case "Danielle_departs5":
			Preprocessor_Add("Danielle", GetMyName(NPChar));
			Dialog.Text = DLG_TEXT[438];
			Link.l1 = DLG_TEXT[439];
			Link.l1.go = "Danielle_departs_exit";
		break;
		
		case "Danielle_stays2":
			Dialog.Text = DLG_TEXT[440];
			Link.l1 = DLG_TEXT[441];
			Link.l1.go = "Danielle_stays3";
		break;
		
		case "Danielle_stays3":
			Dialog.Text = DLG_TEXT[442];
			Link.l1 = DLG_TEXT[443];
			Link.l1.go = "Danielle_stays4";
		break;
		
		case "Danielle_stays4":
			Dialog.Text = DLG_TEXT[444];
			Link.l1 = DLG_TEXT[445];
			Link.l1.go = "Danielle_stays5";
		break;
		
		case "Danielle_stays5":
			Dialog.Text = DLG_TEXT[446];
			Link.l1 = DLG_TEXT[447];
			Link.l1.go = "Danielle_stays6";
		break;
		
		case "Danielle_stays6":
			Dialog.Text = DLG_TEXT[448];
			Link.l1 = DLG_TEXT[449];
			Link.l1.go = "Danielle_stays";
		break;
		
		case "Danielle_stays":
			Preprocessor_Add("Danielle", GetMyName(NPChar));
			NextDiag.TempNode = "Hired";
			Dialog.Text = GetMyName(PChar) + DLG_TEXT[450];
			Link.l1 = DLG_TEXT[451];
			Link.l1.go = "Danielle_mortal";
			Link.l2 = DLG_TEXT[452];
			Link.l2.go = "Danielle_immortal";
			LAi_SetOfficerType(characterFromID("Danielle"));
		break;

		case "Danielle_immortal":
			Preprocessor_AddQuestData("Danielle", GetMyName(NPChar));
			if (NPChar.sex == "woman") Preprocessor_AddQuestData("pronoun3", XI_ConvertString("her"));
			else Preprocessor_AddQuestData("pronoun3", XI_ConvertString("his"));
			AddQuestRecord("After_Final", 2);
			CloseQuestHeader("After_Final");
			Preprocessor_Remove("pronoun3");
			Preprocessor_Remove("Danielle");				
			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Danielle_mortal":
			LAi_SetImmortal(characterFromID("Danielle"), false);
			Preprocessor_AddQuestData("Danielle", GetMyName(NPChar));
			if (NPChar.sex == "woman") Preprocessor_AddQuestData("pronoun3", XI_ConvertString("her"));
			else Preprocessor_AddQuestData("pronoun3", XI_ConvertString("his"));
			AddQuestRecord("After_Final", 4);
			CloseQuestHeader("After_Final");
			Preprocessor_Remove("pronoun3");
			Preprocessor_Remove("Danielle");				

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Danielle_departs_exit":
			Preprocessor_AddQuestData("Danielle", GetMyName(NPChar));
			Preprocessor_AddQuestData("Danielle Greene", GetMySimpleName(NPChar));
			AddQuestRecord("After_Final", 3);
			CloseQuestHeader("After_Final");
			Preprocessor_Remove("Danielle Greene");
			Preprocessor_Remove("Danielle");
			AddDialogExitQuest("Story_Danielle_Departs_Exit");

			Dialog.CurrentNode = Dialog.TempNode;
			DialogExit();
		break;
		
		case "Danielle_fired_exit":
			AddDialogExitQuest("Story_Danielle_Departs_Exit3");
			
			Dialog.CurrentNode = Dialog.TempNode;
			DialogExit();
		break;
// <-- CatalinaThePirate Fix for Danielle after final
// --> CatalinaThePirate Fix Danielle Officer

		case "rations":
			if(!CheckAttribute(pchar,"Crewstatus.foodrations")) pchar.Crewstatus.foodrations = 1;
			if(!CheckAttribute(pchar,"Crewstatus.rumrations")) pchar.Crewstatus.rumrations = 2;
			if(sti(pchar.Crewstatus.foodrations) == 1) pchar.tempfr = "rfull";
			else pchar.tempfr = "rhalf";
			if(sti(pchar.Crewstatus.rumrations) == 1) pchar.temprr = "rdouble";
			else pchar.temprr = "rnormal";
// added by MAXIMUS [CheckAttribute only] -->
			int ourFood = 0;
			int ourRum = 0;
			if(CheckAttribute(pchar.Crewstatus,"foodused")) ourFood = stf(pchar.Crewstatus.foodused);
			if(CheckAttribute(pchar.Crewstatus,"rumused")) ourRum = stf(pchar.Crewstatus.rumused);
// added by MAXIMUS [CheckAttribute only] <--
			Dialog.text = DLG_TEXT[468] + XI_ConvertString(pchar.tempfr) + DLG_TEXT[469] + XI_ConvertString(pchar.temprr) + DLG_TEXT[470] + makeint((makefloat(GetSquadronGoods(pchar, GOOD_WHEAT)) - ourFood) / (makefloat(GetSquadronCrewQuantity(pchar)) * FOOD_PER_CREW / makefloat(sti(pchar.Crewstatus.foodrations)))) + DLG_TEXT[471] + makeint((makefloat(GetSquadronGoods(pchar, GOOD_RUM)) - ourRum) / (makefloat(GetSquadronCrewQuantity(pchar)) * FOOD_PER_CREW / makefloat(sti(pchar.Crewstatus.rumrations)))) + DLG_TEXT[472];
			//Link.l1 = "No.";
			//Link.l1.go = "Exit";
			//if(pchar.tempfr != "full" && pchar.temprr != "normal")
			{
				Link.l2 = DLG_TEXT[473];
				Link.l2.go = "R12";
			}
			//if(pchar.tempfr != "half" && pchar.temprr != "normal")
			{
				Link.l3 = DLG_TEXT[474];
				Link.l3.go = "R22";
			}
			//if(pchar.tempfr != "full" && pchar.temprr != "double")
			{
				Link.l4 = DLG_TEXT[475];
				Link.l4.go = "R11";
			}
			//if(pchar.tempfr != "half" && pchar.temprr != "double")
			{
				Link.l5 = DLG_TEXT[476];
				Link.l5.go = "R21";
			}
			DeleteAttribute(pchar,"tempfr");
			DeleteAttribute(pchar,"temprr");
		break;

		case "R12":
			pchar.Crewstatus.foodrations = 1;
			pchar.Crewstatus.rumrations = 2;

			Dialog.text = DLG_TEXT[477];
			Link.l1 = DLG_TEXT[464];
			Link.l1.go = "Exit";
		break;

		case "R22":
			pchar.Crewstatus.foodrations = 2;
			pchar.Crewstatus.rumrations = 2;

			Dialog.text = DLG_TEXT[478];
			Link.l1 = DLG_TEXT[464];
			Link.l1.go = "Exit";
		break;

		case "R11":
			pchar.Crewstatus.foodrations = 1;
			pchar.Crewstatus.rumrations = 1;

			Dialog.text = DLG_TEXT[479];
			Link.l1 = DLG_TEXT[464];
			Link.l1.go = "Exit";
		break;

		case "R21":
			pchar.Crewstatus.foodrations = 2;
			pchar.Crewstatus.rumrations = 1;

			Dialog.text = DLG_TEXT[480];
			Link.l1 = DLG_TEXT[464];
			Link.l1.go = "Exit";
		break;

		case "SalaryC":
			Dialog.text = DLG_TEXT[481] + PChar.name + ".";
			Link.l1 = DLG_TEXT[482];
			Link.l1.go = "Exit";
			if(sti(PChar.CrewStatus.explength) == 0)
			{
				Dialog.text = DLG_TEXT[483] + GetMyName(Pchar) + DLG_TEXT[484];
				Link.l2 = DLG_TEXT[485];
				Link.l2.go = "Salary";
			}
		break;

		case "ArticlesC":
			Dialog.text = DLG_TEXT[486] + GetMyName(Pchar) + DLG_TEXT[484];
			Link.l1 = DLG_TEXT[482];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[487];
			Link.l2.go = "Articles";
		break;

		case "Salary":
			Dialog.text = DLG_TEXT[488];
			Link.l1 = DLG_TEXT[463];
			Link.l1.go = "Exit";
			SetSquadronCrewQuantityRatio(PChar, 0.2 * (1 + makefloat(CalcCharacterSkill(PChar, SKILL_LEADERSHIP))/3.0));
			ResetAllLengths(PChar);
			PChar.articles = false;
		break;

		case "Articles":
			Dialog.text = DLG_TEXT[489];
			Link.l1 = DLG_TEXT[463];
			Link.l1.go = "Exit";
			SetSquadronCrewQuantityRatio(PChar, 0.2 * (1 + makefloat(CalcCharacterSkill(PChar, SKILL_LEADERSHIP))/3.0));
			ResetAllLengths(PChar);
			PChar.articles = true;
		break;
// NK <--


		// RM -->
		case "flgchoice": // KK
			Dialog.text = DLG_TEXT[490] + PChar.name + "?";
// KK -->
			if (GetCurrentFlag() != PERSONAL_NATION) {
				Link.l1 = DLG_TEXT[491] + GetNationDescByType(GetCurrentFlag()) + DLG_TEXT[462];
				Link.l1.go = "flag0" + PChar.nation;
			} else {
				Link.l1 = DLG_TEXT[492];
				Link.l1.go = "flag" + PERSONAL_NATION;
			}
			if (GetCurrentFlag() != PIRATE) {
				Link.l2 = DLG_TEXT[493];
				Link.l2.go = "flag0" + PIRATE;
			}
// <-- KK
			string tempstr;
			for(int q = 0; q < NATIONS_QUANTITY; q++)
			{
				if (q==PIRATE) continue;

// KK -->
				if (GetCurrentFlag() == q) continue;
				if (GetRMRelation(PChar, q) >= REL_AMNESTY)
				{
					tempstr = "l" + (q+3);
					Link.(tempstr) = DLG_TEXT[494] + XI_ConvertString("4"+GetNationDescByType(q)) + DLG_TEXT[462];
					Link.(tempstr).go = "flag0"+q;
				}
			}
			if (GetCurrentFlag() != PERSONAL_NATION)
			{
				tempstr = "l" + (PERSONAL_NATION+3);
				Link.(tempstr) = DLG_TEXT[495];
				Link.(tempstr).go = "flag"+PERSONAL_NATION;
			}
// <-- KK
		break;
		// RM <--
			
		case "hired":
			Dialog.TempNode = "Hired";
			Dialog.text = DLG_TEXT[496] + GetMyName(Pchar) + DLG_TEXT[497];
			// NK -->
			Link.l1 = DLG_TEXT[498];
			Link.l1.go = "Exit";								
			Link.l2 = DLG_TEXT[499];
			Link.l2.go = "shipandcrew_status";
			Link.l3 = DLG_TEXT[500];
			Link.l3.go = "personal_status";
			Link.l4 = DLG_TEXT[501];
			Link.l4.go = "your_status";
		break;

		case "shipandcrew_status":
			Dialog.TempNode = "Hired";
			Dialog.text = DLG_TEXT[502];
			Link.l1 = DLG_TEXT[482];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[503];
			Link.l2.go = "rations";
			if(CheckAttribute(PChar, "articles") && sti(PChar.articles))
			{
				Link.l3 = DLG_TEXT[504];
				Link.l3.go = "SalaryC";
			}
			else
			{
				Link.l3 = DLG_TEXT[505];
				Link.l3.go = "ArticlesC";
			}
			Link.l4 = DLG_TEXT[506];
			Link.l4.go = "flgchoice"; // KK
			if(PChar.location != "Tutorial_Deck")
			{
				Link.l5 = DLG_TEXT[507];
				Link.l5.go = "layupships";
			}
		break;

		case "personal_status":
			Dialog.TempNode = "Hired";
			Dialog.text = DLG_TEXT[502];
			Link.l1 = DLG_TEXT[482];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[508];
			Link.l2.go = "Difficulty";
			Link.l3 = DLG_TEXT[509];
			Link.l3.go = "clothes";
		break;

		case "your_status":
			Dialog.TempNode = "Hired";
			Dialog.text = DLG_TEXT[502];
			Link.l1 = DLG_TEXT[482];
			Link.l1.go = "exit";

			// boal 05.09.03 offecer need to go to abordage -->
			Link.l3 = DLG_TEXT[510];
			Link.l3.go = "Boal_Abordage";								
			Link.l4 = DLG_TEXT[511];
			Link.l4.go = "Boal_safeAbordage";
			Link.l5 = DLG_TEXT[512];
			Link.l5.go = "Boal_Stay";
			Link.l6 = DLG_TEXT[513];
			Link.l6.go = "Boal_Follow";
			// boal 05.09.03 offecer need to go to abordage <--
			Link.l7 = DLG_TEXT[514];
			Link.l7.go = "clothesyou";
			Link.l2 = GetMyName(NPChar) + DLG_TEXT[515]; // SA
			Link.l2.go = "AsYouWish_G"; // SA
			Link.l9 = DLG_TEXT[516]; //fire officer meanly
			Link.l9.go = "AsYouWish";
		break;

		case "layupships":
			DialogExit();
			LaunchKAMShipBerthing();
		break;
			

		case "clothes":
			DialogExit();
			LaunchKAMSelectModel();
			// note 26 used above!
		break;

		case "clothesyou":
			DialogExit();
			LaunchKAMSelectOfficerModel(sti(NPChar.index)); // KK
		break;

		case "nochange":
			dialog.text = DLG_TEXT[464];
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;
// NK <--

		case "AsYouWish":
			//Dialog.TempNode = "Fired";
			Dialog.text = DLG_TEXT[517] + GetMyName(Pchar) + DLG_TEXT[518];
			Link.l1 = DLG_TEXT[519];
			Link.l1.go = "Exit";								
			Link.l2 = DLG_TEXT[520];
			Link.l2.go = "Danielle_fired_exit";  //  <-- Note this is where to add in a new quest after Danielle is fired	
		break;

		case "AsYouWish_G": // SA -->
			Dialog.text = DLG_TEXT[521] + GetMyName(Pchar) + DLG_TEXT[522];
			Link.l1 = DLG_TEXT[519];
			Link.l1.go = "Exit";						
			Link.l2 = DLG_TEXT[523];
			Link.l2.go = "Departed";
		break;

		case "Departed":
			Dialog.TempNode = "Departed";
			Dialog.text = DLG_TEXT[524] + PChar.name + "!";
			Link.l1 = DLG_TEXT[525] + GetMyName(NPChar) + ".";
			Link.l1.go = "Danielle_fired_exit";  //  <-- Note this is where to add in a new quest after Danielle is fired
		break;
		// SA <--

		case "Fired":
			Dialog.TempNode = "Fired";
			Dialog.text = DLG_TEXT[526] + GetMyName(Pchar) + DLG_TEXT[527];
			Link.l1 = DLG_TEXT[528];
			Link.l1.go = "Danielle_fired_exit";  //  <-- Note this is where to add in a new quest after Danielle is fired
		break;

		// NK -->
		case "Difficulty":
			Dialog.text = DLG_TEXT[529] + GetMyName(Pchar) + DLG_TEXT[530] + stringRet(GetSymbol(GetDifficultyName(GetDifficulty()),0) == "A" || GetSymbol(GetDifficultyName(GetDifficulty()),0) == DLG_TEXT[536], DLG_TEXT[539],DLG_TEXT[540]) + GetDifficultyName(GetDifficulty());
			if(GetShipCap()) { Dialog.text = Dialog.text + DLG_TEXT[531]; }
			else { Dialog.text = Dialog.text + DLG_TEXT[532]; }
			Link.l1 = stringRet(GetSymbol(GetDifficultyName(1),0) == "A" || GetSymbol(GetDifficultyName(1),0) == DLG_TEXT[536], DLG_TEXT[537], DLG_TEXT[538]) + GetDifficultyName(1) + ".";
			Link.l1.go = "diff1";
			Link.l2 = stringRet(GetSymbol(GetDifficultyName(2),0) == "A" || GetSymbol(GetDifficultyName(2),0) == DLG_TEXT[536], DLG_TEXT[537], DLG_TEXT[538]) + GetDifficultyName(2) + ".";
			Link.l2.go = "diff2";
			Link.l3 = stringRet(GetSymbol(GetDifficultyName(3),0) == "A" || GetSymbol(GetDifficultyName(3),0) == DLG_TEXT[536], DLG_TEXT[537], DLG_TEXT[538]) + GetDifficultyName(3) + ".";
			Link.l3.go = "diff3";
			Link.l4 = stringRet(GetSymbol(GetDifficultyName(4),0) == "A" || GetSymbol(GetDifficultyName(4),0) == DLG_TEXT[536], DLG_TEXT[537], DLG_TEXT[538]) + GetDifficultyName(4) + ".";
			Link.l4.go = "diff4";
			Link.l5 = DLG_TEXT[533];
			if(GetShipCap()) { Link.l5.go = "shipcapoff"; }
			else { Link.l5.go = "shipcapon"; }
		break;

		case "diff1":
			Dialog.text = DLG_TEXT[464];
			SetDifficulty(1);
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;

		case "diff2":
			Dialog.text = DLG_TEXT[464];
			SetDifficulty(2);
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;

		case "diff3":
			Dialog.text = DLG_TEXT[464];
			SetDifficulty(3);
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;

		case "diff4":
			Dialog.text = DLG_TEXT[464];
			SetDifficulty(4);
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;

		case "shipcapon":
			Dialog.text = DLG_TEXT[464] + DLG_TEXT[534];
			SetShipCap(true);
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;

		case "shipcapoff":
			Dialog.text = DLG_TEXT[464] + DLG_TEXT[535];
			SetShipCap(false);
			Link.l1 = "...";
			Link.l1.go = "Exit";
		break;
		// NK <--

        // boal 05.09.03 offecer need to go to abordage -->
		case "Boal_Abordage":
			NPChar.AbordageMode = makeint(1);
			Dialog.TempNode = "Hired";
			Dialog.text = DLG_TEXT[541];
			Link.l1 = DLG_TEXT[542];
			Link.l1.go = "Exit";
		break;

		case "Boal_safeAbordage":
			NPChar.AbordageMode = makeint(0);
			Dialog.TempNode = "Hired";
			Dialog.text = DLG_TEXT[543];
			Link.l1 = DLG_TEXT[542];
			Link.l1.go = "Exit";
		break;

		case "Boal_Stay":
			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(NPChar.id);
			AddDialogExitQuest("Boal_LandEnc_OfficerStay");
			Dialog.TempNode = "Hired";
			Dialog.text = DLG_TEXT[464];
			Link.l1 = DLG_TEXT[542];
			Link.l1.go = "Exit";
		break;

		case "Boal_Follow":
			SetCharacterTask_FollowCharacter(Characters[GetCharacterIndex(NPChar.id)], PChar); // it works!!!
			Dialog.TempNode = "Hired";
			Dialog.text = DLG_TEXT[464];
			Link.l1 = DLG_TEXT[542];
			Link.l1.go = "Exit";
		break;
        // boal 05.09.03 offecer need to go to abordage <--
// <-- CatalinaThePirate Fix Danielle Officer

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
