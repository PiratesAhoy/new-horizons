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

		Dialog.Text = DLG_TEXT[0] + GetMyName(Pchar) + DLG_TEXT[1];
		Link.l1 = DLG_TEXT[2] + GetMyName(NPChar) + DLG_TEXT[3];
		Link.l1.go = "talk_in_tavern";

		if(CheckQuestAttribute("RheimsBook","17"))//For Mosh34.1
		{
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5] + GetMyName(NPChar) + DLG_TEXT[6];
			Link.l1.go = "talk_with_blaze_in_light_house_after_prison";
		}
		if(CheckQuestAttribute("RheimsBook", "vincent_say_about_rheims"))
		{
			dialog.text = DLG_TEXT[7] + GetMyName(Pchar) +DLG_TEXT[8];
			link.l1 = DLG_TEXT[9] + GetMyName(NPChar) + DLG_TEXT[10];
			link.l1.go = "talk_with_blaze_in_light_house_after_prison_7";
		}
		if(CheckQuestAttribute("RheimsBook","waiting_for_returning_blaze_in_lighhouse"))//For Mosh38
		{
			Dialog.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[13])]) + DLG_TEXT[14];
			Link.l1.go = "exit";
			//Pchar.quest.RheimsBook = "26";//For MoshD39
			//SetAfterDialog_Task_Character(NPChar,ADA_DIALOG,"Vincent Bethune",true);
			Pchar.quest.RheimsBook = "ask_for_douwesen";//For MoshD39
			SetAfterDialog_Task_Character(NPChar,ADA_DIALOG,"Vincent Bethune",true);
			//SetCharacterActivity_FollowMe("Blaze",true,2.5);
			AddQuestRecord("Story_Find_Rheims", 125);
			SetCompanionIndex(pchar, -1, GetCharacterIndex(npchar.id));
		}
		if(CheckQuestAttribute("RheimsBook","away_go_away"))//For 41
		{
			Dialog.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "exit";
			AddDialogExitQuest("DanielleWishRheimsRunaway");
			Pchar.quest.RheimsBook = "31";
			AddQuestRecord("Story_Find_Rheims", 127);
		}
		if ( CheckQuestAttribute("story_FindRheims","KillerDead") )
		{
			Dialog.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[19])]) + DLG_TEXT[20] + characters[GetCharacterIndex(DLG_TEXT[21])].lastname + DLG_TEXT[22];
			Link.l1.go = "danielle_dagger";
		}
		if ( CheckQuestAttribute("FindMysteriousTablet","ToPiratesIsland") )
		{
			Dialog.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "BlazeJoinDanielle_1";
		}
		if ( CheckQuestAttribute("FindMysteriousTablet","DoGovernorExamination") )
		{
			if ( PChar.location == "Redmond_shore_01" )
			{
				if ( GetDayTime()==DAY_TIME_NIGHT )
				{
					Dialog.Text = DLG_TEXT[25];
					Link.l1 = DLG_TEXT[26];
					Link.l1.go = "exit";
					AddDialogExitQuest("after_wait_for_night_in_shore_2");
				}
				else
				{
					Dialog.Text = DLG_TEXT[27];
					Link.l1 = DLG_TEXT[28];
					Link.l1.go = "exit";
					AddDialogExitQuest("wait_for_night_in_shore");
				}
			}
			else
			{
				Dialog.Text = DLG_TEXT[29];
				Link.l1 = DLG_TEXT[30];
				Link.l1.go = "exit";
			}
		}
		if ( CheckQuestAttribute("FindMysteriousTablet","GovernorExaminationFinish") )
		{
			Dialog.Text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "exit";
		}
		if ( CheckQuestAttribute("FindMysteriousTablet","DanielleBlazeDivision") )
		{
			Dialog.Text = DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "exit";
			AddDialogExitQuest("DanielleBlazeDivision_finish");
		}
		if (CheckQuestAttribute("Find_Blaze", "Muelle_Find_Blaze"))
		{
			dialog.text = GetMyName(PChar) + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Muelle_Find_Blaze_2";
		}
		if (CheckQuestAttribute("RheimsBook", "goto_douwesen_tavern2"))
		{
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "goto_douwesen_tavern2_1";
		}
		if(CheckQuestAttribute("main_line", "blaze_found_book_in_rheims_house"))
		{
			dialog.text = DLG_TEXT[39];
			link.l1 = " ";
			link.l1.go = "exit";
			AddDialogExitQuest("blaze_fight_in_rheims_house_complete");
		}
		//Hitman
		if (CheckQuestAttribute("Hitman", "mark_pepin"))
		{
			dialog.text = DLG_TEXT[50] + characters[GetCharacterIndex(DLG_TEXT[51])].lastname + DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Hit_QC_exit";
		}
		//Hitman
	break;

	case "to_ship_of_Bernardo_Gamboa":
		dialog.text = DLG_TEXT[40];
		link.l1 = DLG_TEXT[41];
		link.l1.go = "to_the_ship";
		link.l2 = DLG_TEXT[42];
		link.l2.go = "not_to_the_ship";
	break;

	case "Pusasn_in_the_ship":
		dialog.text = DLG_TEXT[43];
		link.l1 = DLG_TEXT[44];
		link.l1.go = "exit";
		AddDialogExitQuest("Pusasn_in_the_ship");
	break;

	case "letter_to_father_bernard":
		dialog.text = DLG_TEXT[45];
		link.l1 = DLG_TEXT[46];
		link.l1.go = "exit";
		AddDialogExitQuest("to_the_muelle_church_with_letter2");
	break;

	case "Animists_killed":
		dialog.text = DLG_TEXT[251];
		link.l1 = DLG_TEXT[252];
		link.l1.go = "exit";
	break;

//Lucas
	case "Lucas":
		dialog.text = DLG_TEXT[47];
		link.l1 = DLG_TEXT[48];
		link.l1.go = "Exit_sign";
		link.l2 = DLG_TEXT[49];
		link.l2.go = "Exit_eavesdrop";
	break;
//Lucas

//Sumbhajee
	case "Spain1":
		dialog.text = DLG_TEXT[283];
		link.l1 = " ";
		link.l1.go = "exit";
		addDialogExitQuest("talk_to_soldier_alone");
	break;

	case "Spain2":
		dialog.text = DLG_TEXT[284];
		link.l1 = " ";
		link.l1.go = "exit";
		pchar.spain = "1";
		LAi_setPlayerType(pchar);
	break;
//Sumbhajee

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

	case "goto_douwesen_tavern2_1":
		dialog.text = DLG_TEXT[54] + characters[GetCharacterIndex(DLG_TEXT[55])].lastname + DLG_TEXT[56];
		link.l1 = DLG_TEXT[57] + GetMyName(NPChar) + DLG_TEXT[58];
		link.l1.go = "exit";
		AddDialogExitQuest("meet_Blaze_in_douwesen");
	break;

	case "BeforeEnglishSiege":
		NextDiag.TempNode = "RepelEnglishAssault";
		Dialog.Text = DLG_TEXT[59];
		Link.l1 = GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[60])]) + DLG_TEXT[61];
		Link.l1.go = "BeforeEnglishSiege_1";
	break;

	case "BeforeEnglishSiege_1":
		Dialog.Text = DLG_TEXT[62];
		Link.l1 = DLG_TEXT[63];
		Link.l1.go = "BeforeEnglishSiege_2";
	break;

	case "BeforeEnglishSiege_2":
		Dialog.Text = DLG_TEXT[64];
		Link.l1 = DLG_TEXT[65];
		Link.l1.go = "BeforeEnglishSiege_3";
	break;

	case "BeforeEnglishSiege_3":
		Dialog.Text = DLG_TEXT[66] + GetMyName(Pchar) + DLG_TEXT[67];
		Link.l1 = DLG_TEXT[68];
		Link.l1.go = "BeforeEnglishSiege_4";
	break;

	case "BeforeEnglishSiege_4":
		Dialog.Text = DLG_TEXT[69];
		Link.l1 = DLG_TEXT[70];
		Link.l1.go = "BeforeEnglishSiege_5";
	break;

	case "BeforeEnglishSiege_5":
		Dialog.Text = DLG_TEXT[71];
		Link.l1 = DLG_TEXT[72];
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

		//ActMoveToLocation(&Characters[GetCharacterIndex("Blaze_Crewmember_01")], "None", "reload1", 0, "reload");
		Dialog.Text = DLG_TEXT[73];
		Link.l1 = DLG_TEXT[74];
		Link.l1.go = "RepelEnglishAssault_1";
	break;

	case "RepelEnglishAssault_1":
		NextDiag.tempNode = "Must_Hurry_to_Fort";
		Dialog.Text = DLG_TEXT[75];
		Link.l1 = DLG_TEXT[76];
		Link.l1.go = "RepelEnglishAssault_exit";
	break;

	case "AfterGreenfordSiege":
		Dialog.Text = DLG_TEXT[77];
		Link.l1 = DLG_TEXT[78] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[79])]) + DLG_TEXT[80];
		Link.l1.go = "AfterGreenfordSiege_1";
	break;

	case "AfterGreenfordSiege_1":
		NextDiag.tempNode = "PayVisitToResearcher";
		Dialog.Text = DLG_TEXT[81] + GetMyName(Pchar) + DLG_TEXT[82];
		Link.l1 = DLG_TEXT[83];
		Link.l1.go = "AfterGreenfordSiege_exit";
	break;

	case "PayVisitToResearcher":
		Dialog.Text = DLG_TEXT[84];
		Link.l1 = DLG_TEXT[85];
		Link.l1.go = "Exit";
	break;

	case "Temple":
		NextDiag.TempNode = "GoGoGo";
		Dialog.Text = GetMyName(PChar) + DLG_TEXT[86];
		Link.l1 = DLG_TEXT[87];
		Link.l1.go = "Temple_exit";
	break;

	case "Gogogo":
		NextDiag.TempNode = "GoGoGo";
		Dialog.Text = DLG_TEXT[88];
		Link.l1 = DLG_TEXT[89];
		Link.l1.go = "Gogogo_1";
	break;

	case "Gogogo_1":
		Dialog.Text = DLG_TEXT[90];
		Link.l1 = DLG_TEXT[91];
		Link.l1.go = "Exit";
	break;

	case "Split":
		Dialog.Text = DLG_TEXT[92];
		Link.l1 = DLG_TEXT[93] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[94])]) + DLG_TEXT[95];
		Link.l1.go = "Split_exit";
	break;

	case "I'm going on left":
		Dialog.Text = DLG_TEXT[96];
		Link.l1 = DLG_TEXT[97];
		Link.l1.go = "I'm going on left_exit";
	break;

	case "ReadyForKhaelRoa":
		Dialog.TempNode = "ReadyForKhaelRoa";
		Dialog.Text = DLG_TEXT[98];
		Link.l1 = DLG_TEXT[99];
		Link.l1.go = "exit";
	break;

	case "ITakeTheStone":
		Dialog.Text = DLG_TEXT[100];
		Link.l1 = DLG_TEXT[101];
		Link.l1.go = "ITakeTheStone_1";
	break;

	case "ITakeTheStone_1":
		Dialog.Text = DLG_TEXT[102];
		Link.l1 = DLG_TEXT[103];
		Link.l1.go = "ITakeTheStone_exit";
	break;

	case "ITakeTheStone_exit":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("Story_ITakeTheStone");
	break;

	case "Treasure_room":
		Dialog.TempNode = "ReadyForKhaelRoa";
		Dialog.Text = DLG_TEXT[104] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[105])]) + DLG_TEXT[106];
		Link.l1 = DLG_TEXT[107];
		Link.l1.go = "Treasure_room_exit";
	break;

	case "Must_Hurry_to_Fort":
		Dialog.TempNode = "Must_Hurry_to_Fort";
		Dialog.Text = DLG_TEXT[108] + GetMyName(Pchar) + DLG_TEXT[109];
		Link.l1 = DLG_TEXT[110];
		Link.l1.go = "Must_Hurry_to_Fort_1";
	break;

	case "Must_Hurry_to_Fort_1":
		Dialog.Text = DLG_TEXT[111] + GetMyName(Pchar) + DLG_TEXT[112];
		Link.l1 = DLG_TEXT[113];
		Link.l1.go = "RepelEnglishAssault_again_exit";
	break;

	case "WhatWasThat":
		Dialog.TempNode = "OMyTreasure";
		Dialog.Text = DLG_TEXT[114];
		Link.l1 = DLG_TEXT[115];
		Link.l1.go = "exit";
		AddDialogExitQuest("Story_ResearcherExplainsInTemple");
	break;

	case "OMyTreasure":
		Dialog.TempNode = "OMyTreasure";
		Dialog.Text = DLG_TEXT[116] + GetMyName(Pchar) + DLG_TEXT[117];
		Link.l1 = DLG_TEXT[118];
		Link.l1.go = "OMyTreasure_1";
	break;

	case "OMyTreasure_1":
		Dialog.Text = DLG_TEXT[119];
		Link.l1 = DLG_TEXT[120];
		Link.l1.go = "exit";
	break;

	case "TooDangerous":
		Dialog.Text = DLG_TEXT[121];
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
		SetCharacterRemovable(&Characters[GetCharacterIndex("Danielle")], true);
		RemovePassenger(Pchar, &Characters[GetCharacterIndex("Danielle")]);
		//ActMoveToLocation(&Characters[GetCharacterIndex("Danielle")], "None", "goto3", 1, "goto");
		AddDialogExitQuest("Story_DanielleWentIntoLeftPassage");
	break;

	case "Split_exit":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Split";
		//ActDialog(&Characters[GetCharacterIndex("Researcher")], PChar, "", -1);
	break;

	case "Temple_exit":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;

		DoQuestCheckDelay("Story_ResearcherSpeaksonKhaelRoaBeach", 1);
	break;

	case "AfterGreenfordSiege_exit":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		SetOfficersIndex(Pchar, 1, getCharacterIndex("Danielle"));
		SetCharacterRemovable(&Characters[GetCharacterindex("Danielle")], false);
		EndQuestMovie();TrackQuestMovie("end","blaze_dialog.c -> AfterGreenfordSiege_exit");
		ChangeCharacterAddressGroup(&Characters[GetCharacterIndex("researcher")],"Oxbay_lighthouse","goto", "goto30");
		Characters[GetCharacterIndex("researcher")].dialog.CurrentNode = "AlreadyTranslated";
	break;

	case "RepelEnglishAssault_again_exit":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		//ActGotoLocator(&Characters[GetCharacterIndex("Danielle")], "reload", "reload1",1);
	break;


	case "RepelEnglishAssault_exit":
		Pchar.quest.Story_DanielleGoesToGreenfordFort.win_condition.l1 = "location";
		//Pchar.quest.Story_DanielleGoesToGreenfordFort.win_condition.l1.character = "Danielle";
		Pchar.quest.Story_DanielleGoesToGreenfordFort.win_condition.l1.location = "Greenford_port";
		Pchar.quest.Story_DanielleGoesToGreenfordFort.win_condition = "Story_DanielleGoesToGreenfordFort";
		//Pchar.quest.Story_DanielleGoesToGreenfordFort.fail_condition = "Story_DanielleGoesToGreenfordFort";
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		//ActGotoLocator(&Characters[GetCharacterIndex("Danielle")], "reload", "reload1",1);
		//EndQuestMovie();TrackQuestMovie("end","blaze_dialog.c -> RepelEnglishAssault_exit");
	break;


	case "BeforeEnglishSiege_exit":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		//StartQuestMovie(true, true, true);
		//ActChangeCharacterType(&Characters[GetCharacterIndex("Blaze_Crewmember_01")], "Merchant");
		ChangeCharacterAddressGroup(&Characters[GetCharacterIndex("Blaze_Crewmember_01")], "Greenford_tavern", "reload", "reload1");
		Characters[GetCharacterIndex("Blaze_Crewmember_01")].Dialog.Filename = "EnglishAttack_dialog.c";
		Characters[GetCharacterIndex("Blaze_Crewmember_01")].Dialog.CurrentNode = "First time";
		//CharacterTurnByChr(Pchar, &Characters[GetCharacterIndex("Blaze_Crewmember_01")]);
		//ActDialog(&Characters[GetCharacterIndex("Blaze_Crewmember_01")], PChar, "", 0);
	break;

	case "Greenford_captured":
		Dialog.Text = DLG_TEXT[122];
		Link.l1 = DLG_TEXT[123];
		Link.l1.go = "Greenford_captured_1";
	break;

	case "Greenford_captured_1":
		NextDiag.TempNode = "MovingToPrison";
		Dialog.Text = DLG_TEXT[124];
		Link.l1 = DLG_TEXT[125] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[126])]) + DLG_TEXT[127];
		Link.l1.go = "Greenford_captured_exit";
	break;

	case "Greenford_captured_exit":
		//ActChangeCharacterType(&Characters[GetCharacterIndex("blaze")], "officer");
		//ActReset(&characters[GetCharacterIndex("Blaze")]);
		ChangeCharacterAddressGroup(&Characters[GetCharacterIndex("Researcher")], "Fake_Greenford_prison", "goto", "goto9");
		Pchar.quest.Story_AppearedInGreenfordPrison.win_condition.l1 = "location";
		Pchar.quest.Story_AppearedInGreenfordPrison.win_condition.l1.character = PChar.id;
		Pchar.quest.Story_AppearedInGreenfordPrison.win_condition.l1.location = "Fake_Greenford_prison";
		Pchar.quest.Story_AppearedInGreenfordPrison.win_condition = "Story_AppearedInGreenfordPrison";
		Pchar.quest.Story_AppearedInGreenfordPrison.fail_condition = "Story_AppearedInGreenfordPrison";

		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		//ActGotoLocator(&characters[GetCharacterIndex("Danielle")], "reload", "reload27",1);
	break;

	case "MovingToPrison":
		NextDiag.TempNode = "MovingToPrison";
		Dialog.Text = GetMyName(PChar) + DLG_TEXT[128];
		Link.l1 = DLG_TEXT[129];
		Link.l1.go = "Exit";
	break;

	case "CaptureGreenford":
		Preprocessor_Add("Governor", characters[GetCharacterIndex("Robert Christopher Silehard")].lastname); // KK
		dialog.text = DLG_TEXT[130];
		link.l1 = DLG_TEXT[131];
		link.l1.go = "CaptureGreenford_2";
	break;

	case "CaptureGreenford_2":
		dialog.text = DLG_TEXT[132];
		link.l1 = DLG_TEXT[133];
		link.l1.go = "CaptureGreenford_3";
	break;

	case "CaptureGreenford_3":
		dialog.text = DLG_TEXT[134];
		link.l1 = GetMyName(NPChar) + DLG_TEXT[135];
		link.l1.go = "exit";
	break;

	case "Muelle_Find_Blaze_2":
		dialog.text = DLG_TEXT[136];
		link.l1 = DLG_TEXT[137];
		link.l1.go = "Muelle_Find_Blaze_3";
	break;

	case "Muelle_Find_Blaze_3":
		dialog.text = DLG_TEXT[138];
		link.l1 = DLG_TEXT[139];
		link.l1.go = "Muelle_Find_Blaze_4";
	break;

	case "Muelle_Find_Blaze_4":
		dialog.text = DLG_TEXT[140];
		link.l1 = DLG_TEXT[141];
		link.l1.go = "Muelle_Find_Blaze_5";
	break;

	case "Muelle_Find_Blaze_5":
		dialog.text = DLG_TEXT[142];
		link.l1 = DLG_TEXT[143];
		link.l1.go = "Muelle_Find_Blaze_6";
	break;

	case "Muelle_Find_Blaze_6":
		dialog.text = GetMyName(PChar) + DLG_TEXT[144];
		link.l1 = DLG_TEXT[145];
		link.l1.go = "Muelle_Find_Blaze_7";
	break;

	case "Muelle_Find_Blaze_7":
		Preprocessor_Add("Governor", characters[GetCharacterIndex("Robert Christopher Silehard")].lastname); // KK
		dialog.text = DLG_TEXT[146];
		link.l1 = DLG_TEXT[147];
		link.l1.go = "Muelle_Find_Blaze_8";
	break;

	case "Muelle_Find_Blaze_8":
		dialog.text = DLG_TEXT[148];
		link.l1 = DLG_TEXT[149];
		link.l1.go = "Muelle_Find_Blaze_9";
	break;

	case "Muelle_Find_Blaze_9":
		dialog.text = DLG_TEXT[150];
		link.l1 = DLG_TEXT[151];
		link.l1.go = "Muelle_Find_Blaze_10";
	break;

	case "Muelle_Find_Blaze_10":
		dialog.text = DLG_TEXT[152];
		link.l1 = GetMyName(NPChar) + DLG_TEXT[153];
		link.l1.go = "exit";
	break;

	case "danielle_dagger":
		dialog.text = DLG_TEXT[154];
		link.l1 = DLG_TEXT[155];
		link.l1.go = "danielle_dagger_2";
	break;

	case "danielle_dagger_2":
		dialog.text = DLG_TEXT[156];
		link.l1 = DLG_TEXT[157];
		link.l1.go = "exit";
		PChar.quest.story_FindRheims = "BlazeWounded";
	break;

	case "talk_in_tavern":
		Dialog.Text = DLG_TEXT[158];
		Link.l1 = DLG_TEXT[159] + GetMyName(NPChar) + DLG_TEXT[160];
		Link.l1.go = "exit";
	break;

	case "talk_with_blaze_in_light_house_after_prison":
		dialog.text = DLG_TEXT[161];
		link.l1 = DLG_TEXT[162];
		link.l1.go = "talk_with_blaze_in_light_house_after_prison_2";
	break;

	case "talk_with_blaze_in_light_house_after_prison_2":
		dialog.text = DLG_TEXT[163];
		link.l1 = DLG_TEXT[164];
		link.l1.go = "talk_with_blaze_in_light_house_after_prison_3";
	break;

	case "talk_with_blaze_in_light_house_after_prison_3":
		Dialog.Text = DLG_TEXT[165] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[166])]) + DLG_TEXT[168];
		link.l1 = DLG_TEXT[169];
		link.l1.go = "talk_with_blaze_in_light_house_after_prison_4";
	break;

	case "talk_with_blaze_in_light_house_after_prison_4":
		dialog.text = DLG_TEXT[170];
		link.l1 = DLG_TEXT[171];
		link.l1.go = "talk_with_blaze_in_light_house_after_prison_5";
	break;

	case "talk_with_blaze_in_light_house_after_prison_5":
		dialog.text = DLG_TEXT[172];
		link.l1 = DLG_TEXT[173];
		link.l1.go = "exit";
		PChar.quest.RheimsBook = "before_vincent_say_about_rheims";
		SetAfterDialog_Task_Character(NPChar,ADA_DIALOG,"Vincent Bethune",true);
		//AddDialogExitQuest("blaze_go_away_from_lighthouse");
	break;

	case "talk_with_blaze_in_light_house_after_prison_7":
		dialog.text = DLG_TEXT[174];
		link.l1 = DLG_TEXT[175];
		link.l1.go = "talk_with_blaze_in_light_house_after_prison_8";
	break;

	case "talk_with_blaze_in_light_house_after_prison_8":
		dialog.text = DLG_TEXT[176];
		Link.l1 = DLG_TEXT[177];
		link.l1.go = "talk_with_blaze_in_light_house_after_prison_9";
	break;

	case "talk_with_blaze_in_light_house_after_prison_9":
		dialog.text = DLG_TEXT[178];
		link.l1 = DLG_TEXT[179];
		Link.l1.go = "exit";
		PChar.quest.RheimsBook = "18";
		SetAfterDialog_Task_Character(NPChar,ADA_DIALOG,"Vincent Bethune",true);
		AddDialogExitQuest("blaze_go_away_from_lighthouse");
	break;

	case "BlazeJoinDanielle_1":
		Dialog.Text = DLG_TEXT[180];
		Link.l1 = DLG_TEXT[181] + GetMyName(Pchar) + DLG_TEXT[182];
		Link.l1.go = "BlazeJoinDanielle_2";
	break;

	case "BlazeJoinDanielle_2":
		Dialog.Text = DLG_TEXT[183];
		Link.l1 = DLG_TEXT[184];
		link.l1.go = "resque_danielle_3";
	break;

	case "resque_danielle_3":
		dialog.text = DLG_TEXT[185] + GetMyName(NPChar) + DLG_TEXT[186] + characters[getCharacterIndex(DLG_TEXT[187])].lastname + DLG_TEXT[188];
		link.l1 = DLG_TEXT[189] + GetMyName(Pchar) + DLG_TEXT[190];
		link.l1.go = "resque_danielle_4";
	break;

	case "resque_danielle_4":
		dialog.text = DLG_TEXT[191] + GetMyName(NPChar) + DLG_TEXT[192];
		link.l1 = DLG_TEXT[193];
		link.l1.go = "resque_danielle_5";
	break;

	case "resque_danielle_5":
		dialog.text = DLG_TEXT[194];
		link.l1 = DLG_TEXT[195];
		link.l1.go = "resque_danielle_6";
	break;

	case "resque_danielle_6":
		dialog.text = DLG_TEXT[196];
		link.l1 = DLG_TEXT[197];
		link.l1.go = "resque_danielle_7";
	break;

	case "resque_danielle_7":
		dialog.text = DLG_TEXT[198] + GetMyName(NPChar) + DLG_TEXT[199] + characters[GetCharacterIndex(DLG_TEXT[200])].lastname + DLG_TEXT[201];
		link.l1 = DLG_TEXT[202];
		link.l1.go = "resque_danielle_8";
	break;

	case "resque_danielle_8":
		dialog.text = DLG_TEXT[203];
		link.l1 = DLG_TEXT[204];
		link.l1.go = "resque_danielle_9";
	break;

	case "resque_danielle_9":
		dialog.text = DLG_TEXT[205];
		link.l1 = GetMyName(PChar) + DLG_TEXT[206];
		link.l1.go = "resque_danielle_10";
	break;

	case "resque_danielle_10":
		dialog.text = DLG_TEXT[207];
		link.l1 = DLG_TEXT[208];
		link.l1.go = "resque_danielle_11";
	break;

	case "resque_danielle_11":
		dialog.text = DLG_TEXT[209];
		link.l1 = DLG_TEXT[210] + GetMyName(Pchar) + DLG_TEXT[211];
		link.l1.go = "resque_danielle_12";
	break;

	case "resque_danielle_12":
		dialog.text = DLG_TEXT[212];
		link.l1 = DLG_TEXT[213] + GetMyName(Pchar) + DLG_TEXT[214];
		link.l1.go = "resque_danielle_13";
	break;

	case "resque_danielle_13":
		dialog.text = DLG_TEXT[215];
		link.l1 = DLG_TEXT[216] + characters[GetCharacterIndex(DLG_TEXT[217])].lastname + DLG_TEXT[218];
		link.l1.go = "resque_danielle_14";
	break;

	case "resque_danielle_14":
		dialog.text = DLG_TEXT[219];
		link.l1 = DLG_TEXT[220];
		link.l1.go = "resque_danielle_15";
	break;

	case "resque_danielle_15":
		dialog.text = DLG_TEXT[221];
		link.l1 = DLG_TEXT[222];
		link.l1.go = "resque_danielle_16";
	break;

	case "resque_danielle_16":
		dialog.text = DLG_TEXT[223];
		link.l1 = DLG_TEXT[224];
		link.l1.go = "resque_danielle_17";
	break;

	case "resque_danielle_17":
		dialog.text = DLG_TEXT[225];
		link.l1 = DLG_TEXT[226] + GetMyName(Pchar) + DLG_TEXT[227];
		link.l1.go = "exit";
		EndQuestMovie();TrackQuestMovie("end","blaze_dialog.c -> resque_danielle_17");
		AdddialogExitQuest("BlazeJoinToDanielle");
		//SetAfterDialog_Task(pchar, ADA_ENDQUESTMOVIE, true);
	break;

	case "WhatsUp":
		Dialog.Text = DLG_TEXT[228];
		Link.l1 = DLG_TEXT[229] + GetMyName(NPChar) + DLG_TEXT[230];
		Link.l1.go = "exit";
	break;

	case "Story_FindBerangereDocuments":
		Dialog.Text = DLG_TEXT[231];
		Link.l1 = DLG_TEXT[232];
		Link.l1.go = "exit_Find";
	break;

	case "Exit_find":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("Story_BlazeStartLookingForGramota");
	break;

	case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	break;

	case "trick":
		Dialog.Text = DLG_TEXT[233];
		Link.l1 = DLG_TEXT[234];
		Link.l1.go = "scream_about_pirates";
	break;

	case "scream_about_pirates":
		AddDialogExitQuest("Blaze_doin_trick");
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
	break;

	case "nigel_lost":
		Dialog.Text = DLG_TEXT[235];
		Link.l1 = DLG_TEXT[236];
		Link.l1.go = "exit";
	break;

	case "Artois_lost":
		Dialog.Text = DLG_TEXT[237];
		Link.l1 = DLG_TEXT[238];
		Link.l1.go = "exit";
	break;

	case "Artois_lost1":
		Dialog.Text = DLG_TEXT[286];
		Link.l1 = DLG_TEXT[287];
		Link.l1.go = "exit";
	break;

	case "Attwood_lost":
		Dialog.Text = DLG_TEXT[239];
		Link.l1 = DLG_TEXT[240];
		Link.l1.go = "exit";
	break;

	case "artois_shooted":
		Dialog.Text = DLG_TEXT[241];
		Link.l1 = DLG_TEXT[242];
		Link.l1.go = "exit";
		AddDialogExitQuest("to_tavern_with_almost_dead_artois");
	break;

//Lucas
	case "Eavesdrop1":
		Dialog.Text = DLG_TEXT[243];
		Link.l1 = DLG_TEXT[244];
		Link.l1.go = "Eavesdrop2";
	break;

	case "Eavesdrop2":
		Dialog.Text = DLG_TEXT[245];
		Link.l1 = DLG_TEXT[246];
		Link.l1.go = "Eavesdrop3";
	break;

	case "Eavesdrop3":
		Dialog.Text = DLG_TEXT[247];
		Link.l1 = DLG_TEXT[248];
		Link.l1.go = "Eavesdrop4";
	break;

	case "Eavesdrop4":
		Dialog.Text = DLG_TEXT[249];
		Link.l1 = DLG_TEXT[250];
		Link.l1.go = "Exit_sign2";
	break;

	case "Exit_sign":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("Lucas_sign");
	break;

	case "Exit_sign2":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("Lucas_sign1");
	break;

	case "Exit_eavesdrop":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("Lucas_ransom_delivery1");
	break;
//Lucas

//Hitman
	case "Hit_QC_exit":

		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("Hit_goto_QC_port1");

	break;
//Hitman

//Sao Feng
	case "Spain_Flag":
		Dialog.Text = DLG_TEXT[290];
		Link.l1 = DLG_TEXT[291];
		Link.l1.go = "exit_raise";
		Link.l2 = DLG_TEXT[292];
		Link.l2.go = "exit_battle";
	break;

	case "exit_raise":
		PChar.Colours = "1";
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("To_Do_or_Not_To_Do2");
	break;

	case "exit_battle":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuest("To_Do_or_Not_To_Do2");
	break;
//Sao Feng

//Missing man
	case "Francis_sword":
		Dialog.Text = DLG_TEXT[253];
		Link.l1 = DLG_TEXT[254];
		Link.l1.go = "Francis_swordfin";
	break;

	case "Francis_swordfin":
		Dialog.Text = DLG_TEXT[255];
		Link.l1 = DLG_TEXT[256];
		Link.l1.go = "exit";
		AddDialogExitQuest("jelaifini");
	break;
//Missing man

//Santiago
	case "Bart_court":
		Dialog.Text = DLG_TEXT[257];
		Link.l1 = DLG_TEXT[258];
		Link.l1.go = "exit";
	break;
//Santiago

//First Contact
	case "pap_storm":
		Dialog.Text = DLG_TEXT[259];
		Link.l1 = DLG_TEXT[260];
		Link.l1.go = "exit";
	break;

	case "deck_storm":
		Dialog.Text = DLG_TEXT[261];
		Link.l1 = DLG_TEXT[262];
		Link.l1.go = "exit";
		AddDialogExitQuest("voirdavy3");
	break;

	case "In Library":
		Dialog.Text = DLG_TEXT[293];
		Link.l1 = DLG_TEXT[294];
		Link.l1.go = "exit";
		AddDialogExitQuest("jela3");
	break;

	case "DavyBook":
		Dialog.Text = DLG_TEXT[295];
		Link.l1.go = "DavyBook2";
	break;

	case "DavyBook2":
		Dialog.Text = DLG_TEXT[296];
		Link.l1.go = "DavyBook3";
	break;

	case "DavyBook3":
		Dialog.Text = DLG_TEXT[297];
		Link.l1.go = "DavyBook4";
	break;

	case "DavyBook4":
		Dialog.Text = DLG_TEXT[298];
		Link.l1.go = "DavyBook5";
	break;

	case "DavyBook5":
		Dialog.Text = DLG_TEXT[299];
		Link.l1.go = "DavyBook6";
	break;

	case "DavyBook6":
		Dialog.Text = DLG_TEXT[300];
		Link.l1.go = "DavyBook7";
	break;

	case "DavyBook7":
		Dialog.Text = DLG_TEXT[301];
		Link.l1.go = "exit";
		SetNextWeather("Day Storm");
		AddDialogExitQuest("pap_storm");
	break;

	case "Run_away":
		Dialog.Text = DLG_TEXT[302];
		Link.l1 = DLG_TEXT[303];
		Link.l1.go = "exit";
		AddDialogExitQuest("davy_townfight2");
	break;
//First Contact

//Sao Feng
	case "His_stealing_our_ship":
		Dialog.Text = DLG_TEXT[304];
		Link.l1.go = "exit";
	break;
//Sao Feng

//Jackpot
	case "Where Chevalle":
		Dialog.Text = DLG_TEXT[285];
		Link.l1 = " ";
		Link.l1.go = "exit";
//		AddDialogExitQuest("Jackpot_start_search");
		AddQuestRecord("Chevalle", 11);
	break;

	case "Spaniardsattack":
		Dialog.Text = DLG_TEXT[263];
		Link.l1 = DLG_TEXT[264];
		Link.l1.go = "exit";
		AddDialogExitQuest("fightspaniards2");
	break;

	case "Spanishrunaway":
		Dialog.Text = DLG_TEXT[265];
		Link.l1 = DLG_TEXT[266];
		Link.l1.go = "exit";
	break;
//Jackpot

//Tortuga
	case "Jolly Mon":
		Dialog.Text = DLG_TEXT[288];
		Link.l1 = DLG_TEXT[289];
		Link.l1.go = "exit";
		//AddQuestRecord("Hector Barbossa", 8);
		AddQuestRecord("Stolen", 4);
		pchar.quest.And_the_sail_to_Film_Starts.win_condition.l1 = "location";
		pchar.quest.And_the_sail_to_Film_Starts.win_condition.l1.location = "Hispaniola";
		pchar.quest.And_the_sail_to_Film_Starts.win_condition = "And_the_sail_to_Film_Starts";
	break;
//Tortuga

//Isla de Muerte I
	case "Barbossa_speech":
		Dialog.Text = DLG_TEXT[267];
		Link.l1 = DLG_TEXT[268];
		Link.l1.go = "exit";
		AddDialogExitQuest("parlerwill");
	break;

	case "joinmycrew":
		Dialog.Text = DLG_TEXT[269];
		Link.l1.go = "exit";
		AddDialogExitQuest("allerinterceptor");
	break;

	case "pirates_in_prison":
		Dialog.Text = DLG_TEXT[277] + GetMyFullName(PChar) + DLG_TEXT[278] ;
		Link.l1 = DLG_TEXT[279];
		Link.l1.go = "pirates_in_prison2";
	break;	

	case "pirates_in_prison2":
		Dialog.Text = DLG_TEXT[280];
		Link.l1 = DLG_TEXT[281];
		Link.l1.go = "exit";
		AddDialogExitQuest("the_pirates_leave");		
	break;
	
	case "fort_speech":
//		Dialog.Text = "(A judge announces your execution) : " + GetMyFullName(PChar) ;	// GR: GetMyFullName includes your rank if you have one.  Also, move the text to "blaze_dialog.h" in case it needs to be translated.
//		Link.l1 = DLG_TEXT[270] + GetMyFullName(PChar) ;
		Dialog.Text = DLG_TEXT[308] + GetMySimpleName(PChar) + ".";
		Link.l1 = DLG_TEXT[270] + GetMySimpleName(PChar) + ".";
		Link.l1.go = "fort_speech2";
	break;

	case "fort_speech2":
		Dialog.Text = DLG_TEXT[271];
		Link.l1 = DLG_TEXT[275];
		Link.l1.go = "exit";
		AddDialogExitQuest("prepare_execution_escape");
	break;

	case "lookingattheInterceptor":
		Dialog.Text = DLG_TEXT[276];
		Link.l1 = DLG_TEXT[44];
		Link.l1.go = "exit";
		pchar.quest.henry_talk = "henry_decide_on_Interceptor";		
//		AddDialogExitQuest("In_the_deep_end");
	break;

	case "calling_the_black_pearl":
		Dialog.Text = DLG_TEXT[274];
		Link.l1.go = "exit";
		AddDialogExitQuest("The_Black_Pearl_has_been_called");
	break;

	case "puttingthecoinsback":
		Dialog.Text = DLG_TEXT[282];
		Link.l1.go = "exit";
		AddDialogExitQuest("Back_to_normal");
	break;

//Isla de Muerte I
	case "sail_back":
		Dialog.Text = DLG_TEXT[305];
		Link.l1.go = "exit";
		AddDialogExitQuest("Dauntless_Deck_NORR5");
	break;

	case "Isla_muerta_alone":
		Dialog.Text = DLG_TEXT[306];
		Link.l1= DLG_TEXT[307];
		Link.l1.go = "exit";
	break;

//Ship stolen at Tortuga
	case "ship_stolen_tortuga":
		dialog.text = DLG_TEXT[309];
		link.l1 = DLG_TEXT[310];
		link.l1.go = "exit";
	break;
	}
}
