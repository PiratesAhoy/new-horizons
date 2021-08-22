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

//SAVING TOFF'S DAUGHTER
	case "to_ship_of_Bernardo_Gamboa":
		dialog.text = DLG_TEXT[40];
		link.l1 = DLG_TEXT[41];
		link.l1.go = "to_the_ship";
		link.l2 = DLG_TEXT[42];
		link.l2.go = "not_to_the_ship";
	break;

	case "Teneken_in_the_ship":
		dialog.text = DLG_TEXT[43];
		link.l1 = DLG_TEXT[44];
		link.l1.go = "exit";
		AddDialogExitQuest("Teneken_in_the_ship");
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
//SAVING TOFF'S DAUGHTER

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
		Link.l1.go = "Exit_sign";
	break;

	case "Exit_sign":
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
		AddDialogExitQuest("davywarning");
	break;

	case "deck_storm":
		Dialog.Text = DLG_TEXT[261];
		Link.l1 = DLG_TEXT[262];
		Link.l1.go = "exit";
		AddDialogExitQuest("voirdavy3");
	break;
//First Contact

//Jackpot
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

//Aguadilla Quest
	case "Find_map":
		Dialog.Text = DLG_TEXT[277];
		Link.l1 = DLG_TEXT[278];
		Link.l1.go = "Find_map2";
	break;

	case "Find_map2":
		Dialog.Text = DLG_TEXT[279];
		Link.l1 = DLG_TEXT[280];
		Link.l1.go = "exit";
		AddDialogExitQuest("heading_muerte");
	break;
	
	case "Find_ouro":
		Dialog.Text = DLG_TEXT[281];
		Link.l1 = DLG_TEXT[282];
		Link.l1.go = "exit";
		AddDialogExitQuest("load_ouro");
	break;	
//Aguadilla Quest

//Aztec treasure quest
	case "Wait_Agilo":
		Dialog.Text = DLG_TEXT[283];
		Link.l1 = DLG_TEXT[284];
		Link.l1.go = "exit";
		AddDialogExitQuest("see_agilo");
	break;

	case "Wait_elting":
		Dialog.Text = DLG_TEXT[285];
		Link.l1 = DLG_TEXT[286];
		Link.l1.go = "exit";
		AddDialogExitQuest("see_elting");
	break;

	case "Spaniards_Talk":
		Dialog.Text = DLG_TEXT[287];
		Link.l1 = DLG_TEXT[288];
		Link.l1.go = "exit";
		AddDialogExitQuest("ElMorro_assault7AB");
	break;		
//Aztec treasure quest

//Cartagena quest
	case "Assommer":
		Dialog.Text = DLG_TEXT[289];
		Link.l1 = DLG_TEXT[290];
		Link.l1.go = "exit";
		AddDialogExitQuest("assommer_bart");
	break;
	
	case "abandonar_bart":
		Dialog.Text = DLG_TEXT[291];
		Link.l1 = DLG_TEXT[292];
		Link.l1.go = "exit";
		AddDialogExitQuest("abandon_ilotbis2");
	break;

	case "abandonar_bart2":
		Dialog.Text = DLG_TEXT[293];
		Link.l1 = DLG_TEXT[294];
		Link.l1.go = "exit";
		AddDialogExitQuest("abandon_ilotbis3");
	break;

	case "abandonar_bart3":
		Dialog.Text = DLG_TEXT[295];
		Link.l1 = DLG_TEXT[296];
		Link.l1.go = "exit";
		AddDialogExitQuest("abandon_ilotbis4");
	break;

	case "abandonar_bart4":
		Dialog.Text = DLG_TEXT[297];
		Link.l1 = DLG_TEXT[298];
		Link.l1.go = "exit";
		AddDialogExitQuest("abandon_ilotbis5");
	break;

	case "abandonar_bart5":
		Dialog.Text = DLG_TEXT[299];
		Link.l1 = DLG_TEXT[300];
		Link.l1.go = "exit";
		AddDialogExitQuest("abandon_ilotbis61");
	break;

	case "abandonar_bart6":
		Dialog.Text = DLG_TEXT[301];
		Link.l1 = DLG_TEXT[302];
		Link.l1.go = "exit";
		AddDialogExitQuest("abandon_ilotbis71");
	break;

	case "abandonar_bart7":
		Dialog.Text = DLG_TEXT[303];
		Link.l1 = DLG_TEXT[304];
		Link.l1.go = "exit";
		AddDialogExitQuest("abandon_ilotbis9");
	break;

	case "ver_lucia":
		Dialog.Text = DLG_TEXT[305];
		Link.l1 = DLG_TEXT[306];
		Link.l1.go = "exit";
		AddDialogExitQuest("aller_residence8");
	break;

	case "ver_new_santiago":
		Dialog.Text = DLG_TEXT[307];
		Link.l1 = DLG_TEXT[308];
		Link.l1.go = "exit";
		AddDialogExitQuest("aller_residence12");
	break;

	case "lucia_garden":
		Dialog.Text = DLG_TEXT[309];
		Link.l1 = DLG_TEXT[310];
		Link.l1.go = "exit";
		AddDialogExitQuest("dispute_lucia2");
	break;

	case "details_operation":
		Dialog.Text = DLG_TEXT[311];
		Link.l1 = DLG_TEXT[312];
		Link.l1.go = "exit";
		AddDialogExitQuest("operation_emilio");
	break;

	case "details_operation_fin":
		Dialog.Text = DLG_TEXT[311];
		Link.l1 = DLG_TEXT[313];
		Link.l1.go = "exit";
		AddDialogExitQuest("swim_to_warship");
	break;

	case "order_to_crew":
		Dialog.Text = DLG_TEXT[314];
		Link.l1 = DLG_TEXT[315];
		Link.l1.go = "exit";
		AddDialogExitQuest("deck_san_martin8");
	break;

	case "check_dutch_troops":
		Dialog.Text = DLG_TEXT[318];
		Link.l1 = DLG_TEXT[319];
		Link.l1.go = "exit";
		AddDialogExitQuest("outside_fort6");
	break;		
//Cartagena quest

	case "mushroom_vision":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[316];
		Link.l1 = DLG_TEXT[317];
		Link.l1.go = "exit";
		AddDialogExitQuest("smoking_mushrooms9");
	break;

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

	case "fort_speech":
		Dialog.Text = "(A judge announces your execution) : " + GetMyFullName(PChar) ;
		Link.l1 = DLG_TEXT[270] + GetMySimpleName(PChar);
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
	break;

	case "calling_the_black_pearl":
		Dialog.Text = DLG_TEXT[274];
		Link.l1.go = "exit";
		AddDialogExitQuest("The_Black_Pearl_has_been_called");
	break;

//Isla de Muerte I

//La Croix
	case "logbook":
		Dialog.Text = DLG_TEXT[320];
		Link.l1.go = "exit";
		AddDialogExitQuest("Birdsearch2");
	break;
//La Croix

//Hornblower
	case "wakeaftersleep":
		Dialog.Text = DLG_TEXT[321];
		Link.l1.go = "exit";
		AddDialogExitQuest("Go_find_Hunter3");
	break;

	case "Before_Guadelope":
		Dialog.Text = DLG_TEXT[322];
		Link.l1.go = "exit";
		AddDialogExitQuest("Go_find_BushX2");
	break;
//Hornblower

// Ardent
	case "nothing_in_Santiago":
		Dialog.Text = DLG_TEXT[323];
		Link.l1.go = "exit";
	break;

	case "attack_brig":
		Dialog.Text = DLG_TEXT[324];
		Link.l1.go = "exit";
	break;

	case "find_papers":
		Dialog.Text = DLG_TEXT[325];
		Link.l1.go = "exit";
	break;

	case "rob_store":
		if (IsDay()) Dialog.Text = DLG_TEXT[326];
		else Dialog.text = DLG_TEXT[327];
		Link.l1.go = "exit";
	break;

	case "arrow_through_window":
		Dialog.Text = DLG_TEXT[328];
		Link.l1.go = "exit";
	break;

	case "stop_peeking":
		Dialog.Text = DLG_TEXT[329];
		Link.l1.go = "exit";
	break;
// Ardent

//WoodesRogers
	case "6_malta_books":
		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[330];
		Link.l1 = DLG_TEXT[331];
		Link.l1.go = "exit";
		AddDialogExitQuest("Deliver_6_malta_books");
	break;

	case "NS_up_shutter":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
		Dialog.Text = DLG_TEXT[332];
		Link.l1 = DLG_TEXT[333];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "NS_up_beam":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[334];
		Link.l1 = DLG_TEXT[335];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "locked_shipyard":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[336];
		Link.l1 = DLG_TEXT[337];
		Link.l1.go = "exit";
		AddQuestRecord("KR_flagchest","2");
		AddDialogExitQuest("pchar_playertype");
	break;

	case "salute":
		PlaySound("VOICE\ENGLISH\blaze_heard_something.wav");
		Dialog.Text = DLG_TEXT[338];
		Link.l1 = DLG_TEXT[339];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "BB_tower_found":
		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[340];
		if(CheckAttribute(Pchar, "BB_door") && Pchar.BB_door == "found")
		{
			Link.l1 = DLG_TEXT[342];
			Link.l1.go = "exit";
			AddDialogExitQuest("BB_tower_info3");
		}
		else 
		{
			Link.l2 = DLG_TEXT[341];
			Link.l2.go = "exit";
			Pchar.BB_tower = "info2";
			AddDialogExitQuest("BB_tower_info2");
		}
		AddDialogExitQuest("pchar_playertype");
	break;

	case "see_oriel":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[343];
		Link.l1 = DLG_TEXT[344];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "cavalry":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[345];
		Link.l1 = DLG_TEXT[346];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "single_silverbar_first":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[347];
		Link.l1 = DLG_TEXT[348];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "after_single_goldbar":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[349];
		Link.l1 = DLG_TEXT[350];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
		AddDialogExitQuest("pchar_lets_go");
	break;

	case "after_many_goldbars":
		PlaySound("OBJECTS\SHIPCHARGE\gunner_fire.wav");
		Dialog.Text = DLG_TEXT[351];
		Link.l1 = DLG_TEXT[352];
		Link.l1.go = "exit";
		AddDialogExitQuest("captain_around");
	break;

	case "stop_Caesar":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
		Dialog.Text = DLG_TEXT[353];
		Link.l1 = DLG_TEXT[354];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "gate_locked":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
		Dialog.Text = DLG_TEXT[355];
		Link.l1 = DLG_TEXT[356];
		Link.l1.go = "gate_locked1";
	break;

	case "gate_locked1":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[357];
		Link.l1 = DLG_TEXT[358];
		Link.l1.go = "exit";
		AddDialogExitQuest("Turks_gate_locked1");
	break;

	case "gate_runaway":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
		Dialog.Text = DLG_TEXT[359];
		Link.l1 = DLG_TEXT[360];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "gp_dry":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[361];
		Link.l1 = DLG_TEXT[362];
		Link.l1.go = "gp_dry1";
	break;

	case "gp_dry1":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[363];
		Link.l1 = DLG_TEXT[364];

		if(CheckCharacterItem(Pchar,"bladebottle_CB2"))
		{
			Link.l1.go = "exit";
			AddDialogExitQuest("pchar_playertype");
			AddDialogExitQuest("pchar_lets_go");
			AddDialogExitQuest("dialog_gp_dry_done");
		}
		else
		{
			Link.l1.go = "gp_dry2";
		}
	break;

	case "gp_dry2":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[632];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
		AddDialogExitQuest("pchar_lets_go");
		AddDialogExitQuest("dialog_gp_dry_done");
	break;

	case "wait_for_Richards":
		PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
		Dialog.Text = DLG_TEXT[365];
		Link.l1 = DLG_TEXT[366];
		Link.l1.go = "exit";
		AddDialogExitQuest("wait_for_Richards_done");
	break;

	case "Richards_pistol":
		PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
		Dialog.Text = DLG_TEXT[367];
		Link.l1 = DLG_TEXT[368];
		Link.l1.go = "exit";
		AddDialogExitQuest("Richards_back17");
	break;

	case "all_abbess_items":
		PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
		Dialog.Text = DLG_TEXT[369];
		Link.l1 = DLG_TEXT[370];
		Link.l1.go = "exit";
		AddDialogExitQuest("all_abbess_items_done");
	break;

	case "door_where":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[371];
		Link.l1 = DLG_TEXT[372];
		Link.l1.go = "exit";
		AddDialogExitQuest("Hands_door_where1");
	break;

	case "Caesars_map":
		LAi_SetActorType(Pchar);
		LAi_ActorTurnToCharacter(Pchar, characterFromID("Caesar"));
		PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
		Dialog.Text = DLG_TEXT[373];
		Link.l1 = DLG_TEXT[374];
		Link.l1.go = "exit";
		AddDialogExitQuest("Caesars_map1");
	break;

	case "are_you_hands":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[375];
		Link.l1 = DLG_TEXT[376];
		Link.l1.go = "are_you_hands1";
	break;

	case "are_you_hands1":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[377];
		Link.l1 = DLG_TEXT[378];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
		AddDialogExitQuest("pchar_sigh");
	break;

	case "are_you_hands_yes":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[375];
		Link.l1 = DLG_TEXT[376];
		Link.l1.go = "are_you_hands_yes1";
	break;

	case "are_you_hands_yes1":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[377];
		Link.l1 = DLG_TEXT[379];
		Link.l1.go = "exit";
		AddDialogExitQuest("beggar_is_Hands_prepare");
	break;

	case "whats_the meaning":
		LAi_SetPoorType(Pchar);
		PlaySound("VOICE\ENGLISH\Odel_who_you_are.wav");
		Dialog.Text = DLG_TEXT[380];
		Link.l1 = DLG_TEXT[381];
		Link.l1.go = "exit";
		AddDialogExitQuest("Hands_shot_scene36");
	break;

	case "Teach_saved_you":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[382];
		Link.l1 = DLG_TEXT[383];
		Link.l1.go = "exit";
		AddDialogExitQuest("back_to_Wstad2");
	break;

	case "Pell_exit":
		PlaySound("VOICE\ENGLISH\blaze_no_escape.wav");
		Dialog.Text = DLG_TEXT[384];
		Link.l1 = DLG_TEXT[385];
		Link.l1.go = "Pell_exit1";
	break;

	case "Pell_exit1":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[386];
		Link.l1 = DLG_TEXT[387];
		Link.l1.go = "Pell_exit2";
	break;

	case "Pell_exit2":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[388];
		Link.l1 = DLG_TEXT[389];
		if(CheckAttribute(Pchar, "P2_sewer") && Pchar.P2_sewer == "checked")
		{
			Link.l1.go = "Pell_exit4";
		}
		else Link.l1.go = "Pell_exit3";
	break;

	case "Pell_exit3":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[390];
		Link.l1 = DLG_TEXT[391];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pell_exit_done");
	break;

	case "Pell_exit4":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[393];
		Link.l1 = DLG_TEXT[394];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pell_exit_done");
	break;

	case "need_tools":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[392];
		Link.l1.go = "exit";
		AddDialogExitQuest("need_tools");
	break;

	case "need_weapons":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
		Dialog.Text = DLG_TEXT[395];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "maroons_weapons":
		PlaySound("VOICE\ENGLISH\defoe_psst.wav");
		Dialog.Text = DLG_TEXT[396];
		Link.l1 = DLG_TEXT[397];
		Link.l1.go = "exit";
		AddDialogExitQuest("maroons_weapons_done");
	break;

	case "guard_2_doors":
		PlaySound("VOICE\ENGLISH\defoe_psst.wav");
		Dialog.Text = DLG_TEXT[398];
		Link.l1 = DLG_TEXT[399];
		Link.l1.go = "exit";
		AddDialogExitQuest("guard_2_doors_done");
	break;

	case "plan_ambush":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[400];
		Link.l1 = DLG_TEXT[401];
		Link.l1.go = "plan_ambush1";
	break;

	case "plan_ambush1":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[402];
		Link.l1 = DLG_TEXT[403];
		Link.l1.go = "exit";
		AddDialogExitQuest("plan_ambush_done");
	break;

	case "ambush_trick":
		PlaySound("VOICE\ENGLISH\blaze_help.wav");
		Dialog.Text = DLG_TEXT[404];
		Link.l1 = DLG_TEXT[405];
		Link.l1.go = "exit";
		AddDialogExitQuest("Took_finds_out");
	break;

	case "hide_corpses":
		PlaySound("VOICE\ENGLISH\blaze_puh.wav");
		Dialog.Text = DLG_TEXT[406];
		Link.l1 = DLG_TEXT[407];
		Link.l1.go = "hide_corpses1";
	break;

	case "hide_corpses1":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[408];
		Link.l1 = DLG_TEXT[399];
		Link.l1.go = "exit";
		AddDialogExitQuest("hide_corpses_done");
	break;

	case "Took_to_cell":
		PlaySound("OBJECTS\SHIPCHARGE\gunner_fire.wav");
		Dialog.Text = DLG_TEXT[409];
		Link.l1 = DLG_TEXT[399];
		Link.l1.go = "exit";
		AddDialogExitQuest("Took_returns2");
	break;

	case "thats_my_flag":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[410];
		Link.l1 = DLG_TEXT[411];
		Link.l1.go = "thats_my_flag1";
	break;

	case "thats_my_flag1":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[412];
		Link.l1 = DLG_TEXT[413];
		Link.l1.go = "thats_my_flag2";
	break;

	case "thats_my_flag2":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
		Dialog.Text = DLG_TEXT[414];
		Link.l1 = DLG_TEXT[415];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
		AddDialogExitQuest("rum_check1");
	break;

	case "Pyle_dead":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[416];
		Link.l1 = DLG_TEXT[417];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_dead_delay");
		AddDialogExitQuest("pchar_ooh");
	break;

	case "Pyle_dark":
		PlaySound("VOICE\ENGLISH\blaze_heard_something.wav");
		Dialog.Text = DLG_TEXT[418];
		Link.l1 = DLG_TEXT[419];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_dark_delay");
		AddDialogExitQuest("pchar_huh");
	break;

	case "bc_ladder_stuck":
		PlaySound("OBJECTS\DUEL\man_attack5.wav");
		Dialog.Text = DLG_TEXT[420];
		Link.l1 = DLG_TEXT[421];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "bc_cage_too_high":
		PlaySound("OBJECTS\DUEL\man_hit6.wav");
		PlaySound("OBJECTS\DUEL\man_hit6.wav");
		Dialog.Text = DLG_TEXT[422];
		Link.l1 = DLG_TEXT[423];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "bc_cage_too_high_wrong":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
		Dialog.Text = DLG_TEXT[424];
		Link.l1 = DLG_TEXT[425];
		Link.l1.go = "exit";
		AddDialogExitQuest("bc_down_from_wrong_ladder");
		AddDialogExitQuest("pchar_playertype");
	break;

	case "tower_too_high":
		PlaySound("VOICE\ENGLISH\blaze_puh.wav");
		Dialog.Text = DLG_TEXT[426];
		Link.l1 = DLG_TEXT[427];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
		AddDialogExitQuest("Spriggs_flag5");
	break;

	case "send_boat":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[428];
		Link.l1 = DLG_TEXT[429];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
		AddDialogExitQuest("hoist_spanish_flag6");
	break;

	case "compasses_and_map":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[430];
		Link.l1 = DLG_TEXT[431];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
		AddDialogExitQuest("compasses_and_map_done");
	break;

	case "hidden_items":
		PlaySound("VOICE\ENGLISH\blaze_pay_for_this.wav");
		Dialog.Text = DLG_TEXT[432];
		Link.l1 = DLG_TEXT[433];
		Link.l1.go = "hidden_items1";
	break;

	case "hidden_items1":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[434];
		Link.l1 = DLG_TEXT[435];
		Link.l1.go = "exit";
		AddDialogExitQuest("farm_ready_for_part2");
	break;

	case "I_skeleton":
		PlaySound("VOICE\ENGLISH\blaze_no_escape.wav");
		Dialog.Text = DLG_TEXT[436];
		Link.l1 = DLG_TEXT[437];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
		AddDialogExitQuest("Pyle_transformation1");
	break;

	case "I_body_again":
		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[438];
		Link.l1 = DLG_TEXT[439];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_transformation13");
	break;

	case "I_found_the_treasure":
		PlaySound("OBJECTS\SHIPCHARGE\gunner_fire.wav");
		Dialog.Text = DLG_TEXT[440];
		Link.l1 = DLG_TEXT[441];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_transformation21");
	break;

	case "who_can_swim":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[442];
		Link.l1 = DLG_TEXT[443];
		Link.l1.go = "exit";
		AddDialogExitQuest("careen_shore_fight_end5");
	break;

	case "red_uniforms":
		PlaySound("OBJECTS\DUEL\man_attack5.wav");
		Dialog.Text = DLG_TEXT[444];
		Link.l1 = DLG_TEXT[445];
		Link.l1.go = "exit";
		AddDialogExitQuest("careen_shore_fight_end17");
	break;

	case "mut_swimmers_to shore":
		PlaySound("VOICE\ENGLISH\blaze_lead_way_out.wav");
		Dialog.Text = DLG_TEXT[446];
		Link.l1 = DLG_TEXT[447];
		Link.l1.go = "exit";
		AddDialogExitQuest("mut_swimmers_to shore1");
	break;

	case "officers_outfits":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[448];
		Link.l1 = DLG_TEXT[449];
		Link.l1.go = "exit";
		AddDialogExitQuest("mut_officers_outfits1");
	break;

	case "command_the_boats":
		PlaySound("VOICE\ENGLISH\blaze_3.wav");
		Dialog.Text = DLG_TEXT[450];
		Link.l1 = DLG_TEXT[451];
		Link.l1.go = "exit";
		AddDialogExitQuest("careen_shore_fight_end19");
	break;

	case "explore_corvette2":
		PlaySound("VOICE\ENGLISH\defoe_psst.wav");
		Dialog.Text = DLG_TEXT[452];
		Link.l1 = DLG_TEXT[453];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette3");
	break;

	case "explore_corvette4":
		PlaySound("VOICE\ENGLISH\blaze_puh.wav");
		Dialog.Text = DLG_TEXT[454];
		Link.l1 = DLG_TEXT[455];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette5");
	break;

	case "explore_corvette7":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[456];
		Link.l1 = DLG_TEXT[457];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette8");
	break;

	case "explore_corvette9_B":
		PlaySound("VOICE\ENGLISH\defoe_psst.wav");
		Dialog.Text = DLG_TEXT[458];
		Link.l1 = DLG_TEXT[459];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette9_B");
	break;

	case "explore_corvette13":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[460];
		Link.l1 = DLG_TEXT[461];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette13_A");
	break;

	case "explore_corvette15":
		PlaySound("VOICE\ENGLISH\defoe_psst.wav");
		Dialog.Text = DLG_TEXT[462];
		Link.l1 = DLG_TEXT[463];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette15_B");
	break;

	case "explore_corvette20_B":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
		Dialog.Text = DLG_TEXT[464];
		Link.l1 = DLG_TEXT[465];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette20_C");
	break;

	case "explore_corvette23":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[466];
		Link.l1 = DLG_TEXT[467];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette23_A");
	break;

	case "explore_corvette22_K":
		PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
		Dialog.Text = DLG_TEXT[468];
		Link.l1 = DLG_TEXT[469];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette22_L");
	break;

	case "explore_corvette32_C":
		PlaySound("VOICE\ENGLISH\grandma_yell2.wav");
		Dialog.Text = DLG_TEXT[470];
		Link.l1 = DLG_TEXT[471];
		Link.l1.go = "explore_corvette32_D";
	break;

	case "explore_corvette32_D":
		PlaySound("OBJECTS\DUEL\man_attack5.wav");
		Dialog.Text = DLG_TEXT[472];
		Link.l1 = DLG_TEXT[473];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette33");
	break;

	case "explore_corvette33_B":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[474];
		Link.l1 = DLG_TEXT[475];
		Link.l1.go = "explore_corvette33_C";
	break;

	case "explore_corvette33_C":
		PlaySound("VOICE\ENGLISH\blaze_6.wav");
		Dialog.Text = DLG_TEXT[476];
		Link.l1 = DLG_TEXT[477];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette33_D");
	break;

	case "explore_corvette34":
		PlaySound("VOICE\ENGLISH\blaze_2.wav");
		Dialog.Text = DLG_TEXT[478];
		Link.l1 = DLG_TEXT[479];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette34_A");
	break;

	case "explore_corvette33_G":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[480];
		Link.l1 = DLG_TEXT[481];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette33_H");
	break;

	case "explore_corvette35":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[482];
		Link.l1 = DLG_TEXT[483];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette35_A");
	break;

	case "explore_corvette36_A":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[484];
		Link.l1 = DLG_TEXT[485];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette36_B");
	break;

	case "explore_corvette37":
		PlaySound("OBJECTS\DUEL\man_hit6.wav");
		Dialog.Text = DLG_TEXT[486];
		Link.l1 = DLG_TEXT[487];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette37_A");
	break;

	case "explore_corvette38":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[488];
		Link.l1 = DLG_TEXT[489];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette38_A");
	break;

	case "explore_corvette38_B":
		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[490];
		Link.l1 = DLG_TEXT[491];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette38_C");
	break;

	case "explore_corvette39":
		PlaySound("OBJECTS\DUEL\man_attack5.wav");
		Dialog.Text = DLG_TEXT[492];
		Link.l1 = DLG_TEXT[493];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette39_A");
	break;

	case "explore_corvette40_F":
		PlaySound("VOICE\ENGLISH\blaze_scream.wav");
		Dialog.Text = DLG_TEXT[494];
		Link.l1 = DLG_TEXT[495];
		Link.l1.go = "exit";
		AddDialogExitQuest("explore_corvette40_G");
	break;

	case "wait_until_dark":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[496];
		Link.l1 = DLG_TEXT[497];
		Link.l1.go = "exit";
		AddDialogExitQuest("careen_shore_fight_end28");
	break;
	
	case "Pyle_to_wdeck9":
		PlaySound("OBJECTS\SHIPCHARGE\gunner_fire.wav");
		Dialog.Text = DLG_TEXT[500];
		Link.l1 = DLG_TEXT[501];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_wdeck10");
	break;

	case "Pyle_to_wdeck12":
		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[498];
		Link.l1 = DLG_TEXT[499];
		Link.l1.go = "Pyle_to_wdeck12_A";
	break;

	case "Pyle_to_wdeck12_A":
		PlaySound("VOICE\ENGLISH\blaze_2.wav");
		Dialog.Text = DLG_TEXT[502];
		Link.l1 = DLG_TEXT[503];
		Link.l1.go = "Pyle_to_wdeck12_B";
	break;

	case "Pyle_to_wdeck12_B":
		LAi_SetOfficerType(characterFromID("mutineer_23"));
		LAi_SetOfficerType(characterFromID("mutineer_19"));
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[504];
		Link.l1 = DLG_TEXT[505];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_wdeck13");
	break;

	case "Pyle_to_wdeck19":
		PlaySound("OBJECTS\DUEL\man_attack5.wav");
		Dialog.Text = DLG_TEXT[513];
		Link.l1 = DLG_TEXT[514];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_wdeck20");
	break;

	case "Pyle_to_wdeck24":
		PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
		Dialog.Text = DLG_TEXT[510];
		Link.l1 = DLG_TEXT[511];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_wdeck25");
	break;

	case "Pyle_to_wdeck28":
		PlaySound("OBJECTS\DUEL\man_attack5.wav");
		Dialog.Text = DLG_TEXT[512];
		Link.l1 = DLG_TEXT[515];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_wdeck29");
	break;

	case "swedish_uniform":
		PlaySound("VOICE\ENGLISH\blaze_1.wav");
		Dialog.Text = DLG_TEXT[525];
		Link.l1 = DLG_TEXT[459];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_wdeck36");
	break;

	case "violin_free":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[516];
		Link.l1 = DLG_TEXT[517];
		Link.l1.go = "violin_free1";
	break;

	case "violin_free1":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
		Dialog.Text = DLG_TEXT[518];
		Link.l1 = DLG_TEXT[497];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_Mona12");
	break;

	case "hey_gunnar":
		PlaySound("OBJECTS\SHIPCHARGE\gunner_warning.wav");
		Dialog.Text = DLG_TEXT[519];
		Link.l1 = DLG_TEXT[520];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_Mona31");
	break;

	case "took_the_ship":
		LAi_SetActorType(Pchar);
		LAi_ActorTurnToLocator(Pchar, "officers", "reload3_2");

		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[521];
		Link.l1 = DLG_TEXT[522];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_Mona39_C");
	break;

	case "agree_LOM":
		LAi_SetActorType(Pchar);
		LAi_ActorTurnToLocator(Pchar, "officers", "reload3_2");

		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[523];
		Link.l1 = DLG_TEXT[524];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_Mona60");
	break;

	case "puh_and_puh_again":
		PlaySound("VOICE\ENGLISH\blaze_puh.wav");
		PlaySound("VOICE\ENGLISH\blaze_puh.wav");
		Dialog.Text = DLG_TEXT[526];
		Link.l1 = DLG_TEXT[527];
		Link.l1.go = "puh_and_puh_again1";
	break;

	case "puh_and_puh_again1":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
		Dialog.Text = DLG_TEXT[528];
		Link.l1 = DLG_TEXT[529];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_Mona76_A");
	break;

	case "sail_home":
		PlaySound("VOICE\ENGLISH\blaze_lead_way_out.wav");
		Dialog.Text = DLG_TEXT[506];
		Link.l1 = DLG_TEXT[507];
		Link.l1.go = "sail_home1";
	break;

	case "sail_home1":
		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[508];
		Link.l1 = DLG_TEXT[509];
		Link.l1.go = "exit";
		AddDialogExitQuest("Pyle_to_Mona78");
	break;

	case "search_Took_room":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[530];
		Link.l1 = DLG_TEXT[531];
		Link.l1.go = "exit";
		AddDialogExitQuest("Took_in_cell4");
	break;

	case "how_did_you_know":
		LAi_SetSitType(Pchar);

		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[532];
		Link.l1 = DLG_TEXT[533];
		Link.l1.go = "how_did_you_know1";
	break;

	case "how_did_you_know1":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[534];
		Link.l1 = DLG_TEXT[535];
		Link.l1.go = "exit";
		AddDialogExitQuest("defoe_map1");
	break;

	case "Lilliput":
		PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
		Dialog.Text = DLG_TEXT[536];
		Link.l1 = DLG_TEXT[537];
		Link.l1.go = "exit";
		AddDialogExitQuest("defoe_map7");
	break;

	case "Defoe_Johnson":
		LAi_SetSitType(Pchar);
		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[538];
		Link.l1 = DLG_TEXT[539];
		Link.l1.go = "exit";
		AddDialogExitQuest("return_to_defoe1");
	break;

	case "repair_Richards_map":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[540];
		Link.l1 = DLG_TEXT[541];
		Link.l1.go = "exit";
		AddDialogExitQuest("repair_Richards_map");
	break;

	case "search_for_glue":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[542];
		Link.l1 = DLG_TEXT[541];
		Link.l1.go = "exit";
		AddDialogExitQuest("search_for_glue");
	break;

	case "which_island":
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			LAi_SetSitType(Pchar);
		}

		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[543];
		Link.l1.go = "exit";
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			 AddDialogExitQuest("pchar_sittype");
		}
		else AddDialogExitQuest("pchar_playertype");
	break;

	case "I_know_which_island":
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			LAi_SetSitType(Pchar);
		}

		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[544];
		Link.l1 = DLG_TEXT[545];
		Link.l1.go = "wrong_island";
		Link.l2 = DLG_TEXT[546];
		Link.l2.go = "wrong_island";
		Link.l3 = DLG_TEXT[547];
		Link.l3.go = "wrong_island";
		Link.l4 = DLG_TEXT[548];
		Link.l4.go = "wrong_island";
		Link.l5 = DLG_TEXT[549];
		Link.l5.go = "wrong_island";
		Link.l6 = DLG_TEXT[550];
		Link.l6.go = "wrong_island";
		Link.l7 = DLG_TEXT[551];
		Link.l7.go = "wrong_island";

		Link.l8 = DLG_TEXT[552];
		if(GetAttribute(pchar, "Defoe_map") == "on2")
		{
			Link.l8.go = "Curacao_right_island";
		}
		else Link.l8.go = "wrong_island";

		Link.l9 = DLG_TEXT[553];
		Link.l9.go = "wrong_island";
		Link.l10 = DLG_TEXT[554];
		Link.l10.go = "wrong_island";
		Link.l11 = DLG_TEXT[555];
		Link.l11.go = "wrong_island";
		Link.l12 = DLG_TEXT[556];
		Link.l12.go = "wrong_island";
		Link.l13 = DLG_TEXT[557];
		Link.l13.go = "wrong_island";
		Link.l14 = DLG_TEXT[558];
		Link.l14.go = "wrong_island";
		Link.l15 = DLG_TEXT[559];
		Link.l15.go = "wrong_island";
		Link.l16 = DLG_TEXT[560];
		Link.l16.go = "wrong_island";
		Link.l17 = DLG_TEXT[561];
		Link.l17.go = "wrong_island";
		Link.l18 = DLG_TEXT[562];
		Link.l18.go = "wrong_island";
		Link.l19 = DLG_TEXT[563];
		Link.l19.go = "wrong_island";
		Link.l20 = DLG_TEXT[564];
		Link.l20.go = "wrong_island";
		Link.l21 = DLG_TEXT[565];
		Link.l21.go = "wrong_island";

		Link.l22 = DLG_TEXT[566];
		if(GetAttribute(pchar, "Eden_map") == "on2")
		{
			Link.l22.go = "Turks_right_island";
		}
		else Link.l22.go = "wrong_island";
	break;

	case "wrong_island":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[567];
		Link.l1.go = "exit";
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			 AddDialogExitQuest("pchar_sittype");
		}
		else AddDialogExitQuest("pchar_playertype");
	break;

	case "Turks_right_island":
		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		TakeItemFromCharacter(Pchar, "mapBB3" );
		GiveItem2Character(Pchar, "mapBB3T");
		DeleteQuestHeader("Charles_Eden");
		AddQuestRecord("Charles_Eden", "11");
		AddQuestRecord("Charles_Eden", "12");
		CloseQuestHeader("Charles_Eden");
		Pchar.Eden_map = "off";
		Pchar.mapBB3 = "info";
		Dialog.Text = DLG_TEXT[568];
		Link.l1.go = "exit";
		AddDialogExitQuest("delay_Caesars_map");
	break;

	case "Curacao_right_island":
		LAi_SetActorType(Pchar);
		LAi_ActorTurnToLocator(Pchar, "quest", "pyle_look");
		LAi_SetSitType(Pchar);

		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		TakeItemFromCharacter(Pchar, "mapBB6" );
		GiveItem2Character(Pchar, "mapBB6T");
		DeleteQuestHeader("Johnson");

		AddQuestRecord("Johnson", "3");
		AddQuestRecord("Johnson", "4");
		AddQuestRecord("Johnson", "5");
		AddQuestRecord("Johnson", "6");
		CloseQuestHeader("Johnson");
		Pchar.Defoe_map = "off";
		Pchar.mapBB6 = "info";
		Dialog.Text = DLG_TEXT[595];
		Link.l1.go = "Curacao_right_island1";
	break;

	case "Curacao_right_island1":
		LAi_SetActorType(Pchar);
		LAi_ActorTurnToLocator(Pchar, "quest", "pyle_look");
		LAi_SetSitType(Pchar);

		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[596];
		Link.l1 = DLG_TEXT[597];
		Link.l1.go = "exit";
		AddDialogExitQuest("return_to_defoe5");
	break;

	case "U2":
		LAi_SetActorType(pchar);
		LAi_ActorTurnToLocator(Pchar, "reload", "reload15");

		PlaySound("VOICE\ENGLISH\Odel_no.wav");
		Dialog.Text = DLG_TEXT[593];
		Link.l1.go = "exit";
		AddDialogExitQuest("U2_loop");
	break;

	case "U2_monastary":
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			LAi_SetSitType(Pchar);
		}

		PlaySound("VOICE\ENGLISH\Odel_no.wav");
		Dialog.Text = DLG_TEXT[593];
		Link.l1.go = "exit";
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			 AddDialogExitQuest("pchar_sittype");
		}
		else AddDialogExitQuest("pchar_playertype");
	break;

	case "closer_look":
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			LAi_SetSitType(Pchar);
		}

		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[594];
		Link.l1.go = "exit";
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			 AddDialogExitQuest("pchar_sittype");
		}
		else AddDialogExitQuest("pchar_playertype");
	break;

//------------------------------------------------------------------------------
	case "clean_up_map":
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			LAi_SetSitType(Pchar);
		}

		PlaySound("AMBIENT\SHOP\sigh1.wav");
		PlaySound("AMBIENT\SHOP\sigh1.wav");

		if(GetAttribute(Pchar, "blow_map") == "tried")
		{
			Dialog.Text = DLG_TEXT[592];
		}
		else Dialog.Text = DLG_TEXT[569];

		Link.l1 = DLG_TEXT[570];			//cognac
		Link.l1.go = "wrong_LIQ_temp";

		Link.l2 = DLG_TEXT[571];			//water
		if(GetAttribute(Pchar, "Hands_map") == "cleaning")
		{
			Link.l2.go = "right_LIQ_temp";				//Hands right path
		}
		else Link.l2.go = "wrong_LIQ_temp";

		if(CheckCharacterItem(Pchar,"potion3"))
		{
			Link.l3 = DLG_TEXT[572];		//antidote
			Link.l3.go = "wrong_LIQ_temp";
		}

		Link.l4 = DLG_TEXT[586];			//none of these
		if(GetAttribute(Pchar, "Caesar_map") == "cleaning")
		{
			Link.l4.go = "right_dry";					//Caesar right path
		}
		else Link.l4.go = "wrong_dry";
	break;
//------------------------------------------------------------------------------
	case "right_LIQ_temp":
		PlaySound("AMBIENT\SHOP\sigh2.wav");
		PlaySound("AMBIENT\SHOP\sigh2.wav");
		Dialog.Text = DLG_TEXT[573];

		Link.l1 = DLG_TEXT[576];			//warm
		Link.l1.go = "wrong_temp_LIQ_amount";
		Link.l2 = DLG_TEXT[575];			//tepid
		Link.l2.go = "wrong_temp_LIQ_amount";

		Link.l3 = DLG_TEXT[574];			//cold
		if(GetAttribute(Pchar, "Hands_map") == "cleaning")
		{
			Link.l3.go = "right_temp_LIQ_amount";			//Hands right path		
		}
		else Link.l3.go = "wrong_temp_LIQ_amount";
	break;

	case "wrong_LIQ_temp":
		PlaySound("AMBIENT\SHOP\sigh2.wav");
		PlaySound("AMBIENT\SHOP\sigh2.wav");
		Dialog.Text = DLG_TEXT[573];

		Link.l1 = DLG_TEXT[576];			//warm
		Link.l1.go = "wrong_temp_LIQ_amount";
		Link.l2 = DLG_TEXT[575];			//tepid
		Link.l2.go = "wrong_temp_LIQ_amount";
		Link.l3 = DLG_TEXT[574];			//cold
		Link.l3.go = "wrong_temp_LIQ_amount";
	break;
//------------------------------------------------------------------------------
	case "right_temp_LIQ_amount":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[577];

		Link.l1 = DLG_TEXT[578];			//few drops
		if(GetAttribute(Pchar, "Hands_map") == "cleaning")
		{
			Link.l1.go = "right_amount_LIQ_apply";			//Hands right path
		}
		else Link.l1.go = "wrong_amount_LIQ_apply";
		
		Link.l2 = DLG_TEXT[579];			//enough
		Link.l2.go = "wrong_amount_LIQ_apply";
		Link.l3 = DLG_TEXT[580];			//plenty
		Link.l3.go = "wrong_amount_LIQ_apply";
	break;

	case "wrong_temp_LIQ_amount":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[577];
		Link.l1 = DLG_TEXT[578];			//few drops
		Link.l1.go = "wrong_amount_LIQ_apply";
		Link.l2 = DLG_TEXT[579];			//enough
		Link.l2.go = "wrong_amount_LIQ_apply";
		Link.l3 = DLG_TEXT[580];			//plenty
		Link.l3.go = "wrong_amount_LIQ_apply";
	break;
//------------------------------------------------------------------------------
	case "right_amount_LIQ_apply":
		PlaySound("AMBIENT\SHOP\sigh1.wav");
		PlaySound("AMBIENT\SHOP\sigh1.wav");
		Dialog.Text = DLG_TEXT[581];

		Link.l1 = DLG_TEXT[582];			//no cloth
		Link.l1.go = "exit_spoiled_map";
		
		if(CheckCharacterItem(Pchar,"medical1"))
		{
			Link.l2 = DLG_TEXT[587];		//bandage	//Hands right path
			Link.l2.go = "exit_cleaned_map";
		}
		else
		{
			Link.l2 = DLG_TEXT[583];		//cloth		//Hands right path
			Link.l2.go = "exit_cleaned_map";
		}
	break;

	case "wrong_amount_LIQ_apply":
		PlaySound("AMBIENT\SHOP\sigh1.wav");
		PlaySound("AMBIENT\SHOP\sigh1.wav");
		Dialog.Text = DLG_TEXT[581];

		Link.l1 = DLG_TEXT[582];			//no cloth
		Link.l1.go = "exit_spoiled_map";

		if(CheckCharacterItem(Pchar,"medical1"))
		{
			Link.l2 = DLG_TEXT[587];		//bandage
			Link.l2.go = "exit_spoiled_map";
		}
		else
		{
			Link.l2 = DLG_TEXT[583];		//cloth
			Link.l2.go = "exit_spoiled_map";
		}
	break;
//------------------------------------------------------------------------------
	case "right_dry":
		PlaySound("AMBIENT\SHOP\sigh2.wav");
		PlaySound("AMBIENT\SHOP\sigh2.wav");
		Dialog.Text = DLG_TEXT[590];

		Link.l1 = DLG_TEXT[591];			//blow the dust
		Link.l1.go = "exit_blow_map";

		if(CheckCharacterItem(Pchar,"medical1"))
		{
			Link.l2 = DLG_TEXT[587];		//bandage
			Link.l2.go = "exit_cleaned_map";
		}
		else
		{
			Link.l2 = DLG_TEXT[583];		//cloth
			Link.l2.go = "exit_cleaned_map";
		}

		if(CheckCharacterItem(Pchar,"gunpowder"))
		{
			Link.l3 = DLG_TEXT[584];		//gunpowder
			Link.l3.go = "exit_spoiled_map";
		}

		Link.l4 = DLG_TEXT[585];			//sand
		Link.l4.go = "exit_spoiled_map";

	break;

	case "wrong_dry":
		//Hands bloody map

		PlaySound("AMBIENT\SHOP\sigh2.wav");
		PlaySound("AMBIENT\SHOP\sigh2.wav");
		Dialog.Text = DLG_TEXT[590];

		if(CheckCharacterItem(Pchar,"medical1"))
		{
			Link.l1 = DLG_TEXT[587];		//bandage
			Link.l1.go = "exit_spoiled_map";
		}
		else
		{
			Link.l1 = DLG_TEXT[583];		//cloth
			Link.l1.go = "exit_spoiled_map";
		}

		if(CheckCharacterItem(Pchar,"gunpowder"))
		{
			Link.l2 = DLG_TEXT[584];		//gunpowder
			Link.l2.go = "exit_spoiled_map";
		}

		Link.l3 = DLG_TEXT[585];			//sand
		Link.l3.go = "exit_spoiled_map";
	break;
//------------------------------------------------------------------------------
	case "exit_cleaned_map":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("cleaned_map");
	break;

	case "clean_up_map_done":
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			LAi_SetSitType(Pchar);
		}

		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[588];
		Link.l1.go = "exit";
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			 AddDialogExitQuest("pchar_sittype");
		}
		else AddDialogExitQuest("pchar_playertype");
	break;

	case "exit_spoiled_map":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("spoiled_map");
	break;

	case "spoiled_map_done":
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			LAi_SetSitType(Pchar);
		}

		PlaySound("VOICE\ENGLISH\Odel_no.wav");
		Dialog.Text = DLG_TEXT[625];
		Link.l1.go = "clean_up_map_restart";
	break;

	case "clean_up_map_restart":
		if(GetAttribute(pchar, "defoe_merge_maps") == "on")
		{
			LAi_SetSitType(Pchar);
		}

		PlaySound("AMBIENT\SHOP\sigh1.wav");
		PlaySound("AMBIENT\SHOP\sigh1.wav");

		if(GetAttribute(Pchar, "blow_map") == "tried")
		{
			Dialog.Text = DLG_TEXT[592];
		}
		else Dialog.Text = DLG_TEXT[626];

		Link.l1 = DLG_TEXT[570];			//cognac
		Link.l1.go = "wrong_LIQ_temp";

		Link.l2 = DLG_TEXT[571];			//water
		if(GetAttribute(Pchar, "Hands_map") == "cleaning")
		{
			Link.l2.go = "right_LIQ_temp";				//Hands right path
		}
		else Link.l2.go = "wrong_LIQ_temp";

		if(CheckCharacterItem(Pchar,"potion3"))
		{
			Link.l3 = DLG_TEXT[572];		//antidote
			Link.l3.go = "wrong_LIQ_temp";
		}

		Link.l4 = DLG_TEXT[586];			//none of these
		if(GetAttribute(Pchar, "Caesar_map") == "cleaning")
		{
			Link.l4.go = "right_dry";					//Caesar right path
		}
		else Link.l4.go = "wrong_dry";
	break;

	case "exit_blow_map":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("blow_map");
	break;
//------------------------------------------------------------------------------
	case "Saint_X":
		LAi_SetSitType(Pchar);

		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[598];
		Link.l1 = DLG_TEXT[599];
		Link.l1.go = "exit";
	break;

	case "Kristiania":
		LAi_SetSitType(Pchar);
		AddQuestRecord("Blackbeards_tower","9");

		PlaySound("VOICE\ENGLISH\blaze_puh.wav");
		Dialog.Text = DLG_TEXT[600];
		Link.l1 = DLG_TEXT[601];
		Link.l1.go = "Kristiania1";
	break;

	case "Kristiania1":
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");
		Dialog.Text = DLG_TEXT[602];
		Link.l1 = DLG_TEXT[603];
		Link.l1.go = "Kristiania2";
	break;

	case "Kristiania2":
		PlaySound("VOICE\ENGLISH\blaze_scream.wav");
		Dialog.Text = DLG_TEXT[604];
		Link.l1 = DLG_TEXT[605];
		Link.l1.go = "Kristiania3";
	break;

	case "Kristiania3":
		PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
		Dialog.Text = DLG_TEXT[606];
		Link.l1 = DLG_TEXT[607];
		Link.l1.go = "Kristiania4";
	break;

	case "Kristiania4":
		PlaySound("OBJECTS\DUEL\man_attack5.wav");
		Dialog.Text = DLG_TEXT[608];
		Link.l1 = DLG_TEXT[609];
		Link.l1.go = "Kristiania5";
	break;

	case "Kristiania5":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[610];
		Link.l1 = DLG_TEXT[611];
		Link.l1.go = "exit";
		AddDialogExitQuest("return_to_defoe13");
	break;

	case "draw_lines":
		LAi_SetSitType(Pchar);

		PlaySound("AMBIENT\SHOP\sigh2.wav");
		PlaySound("AMBIENT\SHOP\sigh2.wav");
		Dialog.Text = DLG_TEXT[612];
		Link.l1 = DLG_TEXT[613];
		Link.l1.go = "exit";
		AddDialogExitQuest("return_to_defoe17");
	break;

	case "wrong_lines1":
		LAi_SetSitType(Pchar);

		PlaySound("AMBIENT\SHOP\sigh1.wav");
		PlaySound("AMBIENT\SHOP\sigh1.wav");
		Dialog.Text = DLG_TEXT[614];
		Link.l1 = DLG_TEXT[615];
		Link.l1.go = "exit";
		AddDialogExitQuest("return_to_defoe21");
	break;

	case "wrong_lines2":
		LAi_SetSitType(Pchar);

		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[616];
		Link.l1 = DLG_TEXT[617];
		Link.l1.go = "exit";
		AddDialogExitQuest("return_to_defoe25");
	break;

	case "right_island":
		LAi_SetSitType(Pchar);
		AddQuestRecord("Blackbeards_tower","10");

		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[618];
		Link.l1 = DLG_TEXT[619];
		Link.l1.go = "exit";
		AddDialogExitQuest("return_to_defoe31");
	break;

	case "is_it_defoe":
		PlaySound("VOICE\ENGLISH\blaze_hah.wav");
		Dialog.Text = DLG_TEXT[620];
		Link.l1.go = "exit";
		AddDialogExitQuest("pchar_playertype");
	break;

	case "to_the_farm":
		PlaySound("VOICE\ENGLISH\blaze_lead_way_out.wav");
		Dialog.Text = DLG_TEXT[621];
		Link.l1 = DLG_TEXT[622];
		Link.l1.go = "to_the_farm1";
	break;

	case "to_the_farm1":
		PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
		Dialog.Text = DLG_TEXT[623];
		Link.l1 = DLG_TEXT[624];
		Link.l1.go = "exit";
		AddDialogExitQuest("to_the_farm2");
	break;

	case "to_the_weatherdeck":
		PlaySound("OBJECTS\DUEL\man_attack6.wav");
		Dialog.Text = DLG_TEXT[627];
		Link.l1 = DLG_TEXT[628];
		Link.l1.go = "exit";
		AddDialogExitQuest("careen_corvette_fight_end");
	break;

	case "JS_sail_home":
		PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
		Dialog.Text = DLG_TEXT[629];
		Link.l1 = DLG_TEXT[630];
		Link.l1.go = "exit";
		AddDialogExitQuest("JS38_4");
	break;

	case "HOP_is_read":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[631];
		Link.l1.go = "exit";
		AddDialogExitQuest("sloop6_A");
	break;

	case "return_to_wreck_hold":
		PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
		Dialog.Text = DLG_TEXT[633];
		Link.l1 = DLG_TEXT[634];
		Link.l1.go = "exit";
		AddDialogExitQuest("return_to_wreck_hold_done");
	break;

	case "corvette_painting":
		LAi_SetActorType(Pchar);
		LAi_ActorTurnToCharacter(Pchar, characterFromID("grandma"));
		PlaySound("VOICE\ENGLISH\blaze_1.wav");
		Dialog.Text = DLG_TEXT[635];
		Link.l1 = DLG_TEXT[636];
		Link.l1.go = "corvette_painting1";
	break;

	case "corvette_painting1":
		PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
		Dialog.Text = DLG_TEXT[637];
		Link.l1 = DLG_TEXT[638];
		Link.l1.go = "exit";
		AddDialogExitQuest("painting_sound");
	break;



	}
}
