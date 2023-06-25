//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	string voice_path = "VOICE\ENGLISH\";
	if (CheckDirectory("RESOURCE\Sounds\VOICE\"+LanguageGetLanguage()+"\","*") > 0) voice_path = "VOICE\" + LanguageGetLanguage() + "\";
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
//			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
//			Dialog.snd = "dialogs\0\009";

			PlaySound(voice_path + "Don03.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "beach_capture":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + Pchar.lastname + DLG_TEXT[4];
			link.l1.go = "beach_capture2";
		break;

		case "beach_capture2":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "beach_capture3";
		break;

		case "beach_capture3":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "beach_capture4";
		break;

		case "beach_capture4":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit_beach_capture";
		break;

		case "exit_beach_capture":
			AddDialogExitQuest("To_the_Spanish_Prison");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Offer_of_Parole":
			dialog.text = DLG_TEXT[11] + Pchar.lastname + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Offer_of_Parole2";
		break;

		case "Offer_of_Parole2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Offer_of_Parole3";
		break;

		case "Offer_of_Parole3":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Offer_of_Parole4";
		break;

		case "Offer_of_Parole4":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Offer_of_Parole5";
		break;

		case "Offer_of_Parole5":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_Offer_of_Parole";
		break;

		case "Exit_Offer_of_Parole":
			AddDialogExitQuest("Go_explore_the_Beach");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Come_to_dinner":
			PlaySound(voice_path + "Don02.wav");
			dialog.text = DLG_TEXT[11] + Pchar.lastname + DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Come_to_dinner";
		break;

		case "Exit_Come_to_dinner":
			AddDialogExitQuest("Go_to_dining_room");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Introductions_at_dinner":
			dialog.text = DLG_TEXT[11] + Pchar.lastname + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit_Introductions_at_dinner";
		break;

		case "Exit_Introductions_at_dinner":
			AddDialogExitQuest("The_Frenchman_Speaks");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Masseredo_one":
			PlaySound(voice_path + "Don01.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit_Masseredo_one";
		break;

		case "Exit_Masseredo_one":
			AddDialogExitQuest("The_Frenchman_two");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_Battle_Sir":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "A_Battle_Sir2";
		break;

		case "A_Battle_Sir2":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit_A_Battle_Sir";
		break;

		case "Exit_A_Battle_Sir":
			AddDialogExitQuest("The_Frenchman_four");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Masseredo_Duchess_gone":
			dialog.text = DLG_TEXT[29] + Pchar.lastname + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Masseredo_Duchess_gone2";
		break;

		case "Masseredo_Duchess_gone2":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_Masseredo_Duchess_gone";
		break;

		case "Exit_Masseredo_Duchess_gone":
			AddDialogExitQuest("The_Beach_scene_before_the_Wreck");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Masseredo_Battle_Scene":
			dialog.text = DLG_TEXT[11] + Pchar.lastname + DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Masseredo_Battle_Scene2";
		break;

		case "Masseredo_Battle_Scene2":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Masseredo_Battle_Scene3";
		break;

		case "Masseredo_Battle_Scene3":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Masseredo_Battle_Scene4";
		break;

		case "Masseredo_Battle_Scene4":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Masseredo_Battle_Scene5";
		break;

		case "Masseredo_Battle_Scene5":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Masseredo_Battle_Scene6";
		break;

		case "Masseredo_Battle_Scene6":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Masseredo_Battle_Scene7";
		break;

		case "Masseredo_Battle_Scene7":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Masseredo_Battle_Scene8";
		break;

		case "Masseredo_Battle_Scene8":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Masseredo_Battle_Scene9";
		break;

		case "Masseredo_Battle_Scene9":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "Masseredo_Battle_Scene10";
		break;

		case "Masseredo_Battle_Scene10":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Exit_Masseredo_Battle_Scene";
		break;

		case "Exit_Masseredo_Battle_Scene":
			AddDialogExitQuest("rescue_the_shipwrecked");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_man_of_honour":
			dialog.text = DLG_TEXT[54] + Pchar.lastname + DLG_TEXT[55];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_A_man_of_honour";
		break;

		case "Exit_A_man_of_honour":
			AddDialogExitQuest("Waste_time_with_Archie");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Masseredo_you_are_free":
			dialog.text = DLG_TEXT[11] + Pchar.lastname + DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "Masseredo_you_are_free2";
		break;

		case "Masseredo_you_are_free2":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "Masseredo_you_are_free3";
		break;

		case "Masseredo_you_are_free3":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "Masseredo_you_are_free4";
		break;

		case "Masseredo_you_are_free4":
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "Masseredo_you_are_free5";
		break;

		case "Masseredo_you_are_free5":
			dialog.text = DLG_TEXT[64] + Pchar.lastname + DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "Exit_Masseredo_you_are_free";
		break;

		case "Exit_Masseredo_you_are_free":
			AddDialogExitQuest("FREE_back_to_the_Indy");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;


			}
}
