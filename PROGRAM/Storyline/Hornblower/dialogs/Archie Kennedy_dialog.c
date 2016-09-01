
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
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

//			dialog.snd = "Voice\ARSI\ARSI001";
			PlaySound("VOICE\ENGLISH\Archie01.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "First_orders":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "First_orders2";
		break;

		case "First_orders2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Fight_Exit";
		break;

		case "Fight_Exit":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("The Captain Arrives");
		break;

		case "Jamaica Port":
//			dialog.snd = "Voice\ARSI\ARSI003";
			PlaySound("VOICE\ENGLISH\Archie01.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Jamaica Port2";
		break;

		case "Jamaica Port2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_Course_Redmond";
//			link.l1.go = "Course Settings3"
		break;

		case "Course Settings3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit_for_ship";////////////////////////////////////////////
		break;

		case "Exit_for_ship":
			AddDialogExitQuest("take over the ship4");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Greenford Port":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = GetMyName(PChar) + DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Greenford Port2";
		break;

		case "Greenford Port2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Greenford_Port";
		break;

		case "Archie_at_Charlestown":
//			dialog.snd = "Voice\ARSI\ARSI003";
			PlaySound("VOICE\ENGLISH\Archie01.wav");
			AddDialogExitQuest("Get_on_with_it_Gentlemen");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit";
		break;

		case "fort_capture":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = GetMyName(PChar) + DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "fort_capture2";
		break;

		case "fort_capture2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[18] + GetMyName(PChar) + DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "fort_capture3";
		break;

		case "fort_capture3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "fort_capture4";
		break;

		case "fort_capture4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit_fort_capture";
		break;

		case "Exit_fort_capture":
			AddDialogExitQuest("Talking_in_prison");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Feeling_ill":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Exit_Feeling_ill";
		break;

		case "Exit_Feeling_ill":
			AddDialogExitQuest("Hunter_complains");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "feeling better":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = GetMyName(PChar) + DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Exit_feeling_better";
		break;

		case "Exit_feeling_better":
			AddDialogExitQuest("The_Duchess_once_more");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "shes_an_actress":
			dialog.text = DLG_TEXT[29] + GetMyName(PChar) + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "shes_an_actress2";
		break;

		case "shes_an_actress2":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "shes_an_actress3";
		break;

		case "shes_an_actress3":
			dialog.text = DLG_TEXT[32] + GetMyName(PChar) + DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Exit_shes_an_actress";
		break;

		case "Exit_shes_an_actress":
			AddDialogExitQuest("invite_to_dinner");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "What_do_we_do_Now":
			dialog.text = DLG_TEXT[37] + GetMyName(PChar) + DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit_What_do_we_do_Now";
		break;

		case "Exit_What_do_we_do_Now":
			AddDialogExitQuest("rescue_boat_to_sea");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Answer_for_the_ships_crew":
			dialog.text = DLG_TEXT[40] + Pchar.lastname + DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Exit_Answer_for_the_ships_crew";
		break;

		case "Exit_Answer_for_the_ships_crew":
			AddDialogExitQuest("From_Indy_to_Prison");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Just_like_old_times":
			dialog.text = DLG_TEXT[43] + GetMyName(PChar) + DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Just_like_old_times2";
		break;

		case "Just_like_old_times2":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Exit_Just_like_old_times";
		break;

		case "Exit_Just_like_old_times":
			AddDialogExitQuest("FREE_from_the_prison");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Oxbay_meet_after_Battle":
			dialog.text = GetMyName(PChar) + DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Oxbay_meet_after_Battle2";
		break;

		case "Oxbay_meet_after_Battle2":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "Oxbay_meet_after_Battle3";
		break;

		case "Oxbay_meet_after_Battle3":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Exit_Oxbay_meet_after_Battle";
		break;

		case "Exit_Oxbay_meet_after_Battle":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("Go_to_Greenford_town");
		break;

		case "Greenford_after_Sawyer":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "Greenford_after_Sawyer2";
		break;

		case "Greenford_after_Sawyer2":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "Exit_Greenford_after_Sawyer";
		break;

		case "Exit_Greenford_after_Sawyer":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("Board_the_Renown");
		break;

		case "Boat_alongside":
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "Boat_alongside2";
		break;

		case "Boat_alongside2":
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "Exit_Boat_alongside";
		break;

		case "Exit_Boat_alongside":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("Lt_Bush_Arrives");
		break;

		case "The_captain_is_odd":
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "The_captain_is_odd2";
		break;

		case "The_captain_is_odd2":
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "Exit_The_captain_is_odd";
		break;

		case "Exit_The_captain_is_odd":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("Bush_comes_over");
		break;

		case "How_is_Wellard":
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "How_is_Wellard2";
		break;

		case "How_is_Wellard2":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "Exit_How_is_Wellard";
		break;

		case "Exit_How_is_Wellard":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("Bush_calls_to_Meeting");
		break;

		case "The_captain_is_worse":
			dialog.text = DLG_TEXT[81] + GetMyName(PChar) + DLG_TEXT[38];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "Exit_The_captain_is_worse";
		break;

		case "Exit_The_captain_is_worse":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("Talk_with_officers2");
		break;

		case "after_the_shelling":
			dialog.text = DLG_TEXT[54] + GetMyName(PChar) + DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Exit_after_the_shelling";
		break;

		case "Exit_after_the_shelling":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("Sharpe_asks_a_question");
		break;

		case "and_the_fort_plan_is":
			dialog.text = DLG_TEXT[57] + GetMyName(PChar) + "?";
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Exit_and_the_fort_plan_is";
		break;

		case "Exit_and_the_fort_plan_is":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("Set_up_blowing_the_door");
		break;

		case "Buckland_has_gone":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Buckland_has_gone2";
		break;

		case "Buckland_has_gone2":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "Exit_Buckland_has_gone";
		break;

		case "Exit_Buckland_has_gone":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("set_the_charges");
		break;

		case "Been_shot":
			dialog.text = DLG_TEXT[63] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[64];
			link.l1.go = "Exit_Been_shot";
		break;

		case "Exit_Been_shot":
			DialogExit();
			NextDiag.CurrentNode = "First time";
//			AddDialogExitQuest("set_the_charges");
		break;

		case "I_pushed_the_Captain":
			dialog.text = DLG_TEXT[83];
			link.l1.go = "Exit_I_pushed_the_Captain";
		break;

		case "Exit_I_pushed_the_Captain":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			AddDialogExitQuest("Retribution_and_Promotion");
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit_Course_Redmond":
			AddDialogExitQuest("take over the ship4");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Greenford_Port":
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			AddDialogExitQuest("Go_find_Hunter");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
	}
}
