//#include "DIALOGS\Morgan Terror_Dialog.h"
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
	ref lcn = &Locations[FindLocation(PChar.location)];

	string voice_path = "VOICE\ENGLISH\";
	if (CheckDirectory("RESOURCE\Sounds\VOICE\"+LanguageGetLanguage()+"\","*") > 0) voice_path = "VOICE\" + LanguageGetLanguage() + "\";

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
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
			Dialog.snd = "dialogs\0\009";

			PlaySound(voice_path + "Wharf01.wav");	
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "our_first_meeting":
			PlaySound(voice_path + "Wharf03.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "our_first_meeting2";
		break;

		case "our_first_meeting2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "our_first_meeting3";
		break;		

		case "our_first_meeting3":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_first_meeting";
		break;

		case "Exit_first_meeting":
			AddDialogExitQuest("Sailing_with_the_Duchess");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Meet_in_Spanish_prison":
			PlaySound(voice_path + "Wharf02.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Meet_in_Spanish_prison";
		break;

		case "Exit_Meet_in_Spanish_prison":
			AddDialogExitQuest("Meet_with_the_Don");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Duchess_on_the_Beach":
			PlaySound(voice_path + "Wharf01.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Duchess_on_the_Beach2";
		break;

		case "Duchess_on_the_Beach2":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Duchess_on_the_Beach3";
		break;

		case "Duchess_on_the_Beach3":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Duchess_on_the_Beach4";
		break;

		case "Duchess_on_the_Beach4":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_Duchess_on_the_Beach";
		break;

		case "Exit_Duchess_on_the_Beach":
			AddDialogExitQuest("With_duchess_to_prison");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "How_is_Mr_Kennedy":
//			PlaySound("VOICE\ENGLISH\Keene02.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "How_is_Mr_Kennedy2";
		break;

		case "How_is_Mr_Kennedy2":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_How_is_Mr_Kennedy";
		break;

		case "Exit_How_is_Mr_Kennedy":
			AddDialogExitQuest("Archie_speaks_out");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "First_words_Duchess":
			PlaySound(voice_path + "Wharf04.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_First_words_Duchess";
		break;

		case "Exit_First_words_Duchess":
			AddDialogExitQuest("Masseredo_speaks_out");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Second_words_Duchess":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Second_words_Duchess";
		break;

		case "Exit_Second_words_Duchess":
			AddDialogExitQuest("The_Frenchman_three");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Third_words_Duchess":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Third_words_Duchess";
		break;

		case "Exit_Third_words_Duchess":
			AddDialogExitQuest("Frenchman_last");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Fourth_words_Duchess":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Fourth_words_Duchess";
		break;

		case "Exit_Fourth_words_Duchess":
			AddDialogExitQuest("Leave_the_Dinner");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "After_Dinner_Talk":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "After_Dinner_Talk2";
		break;

		case "After_Dinner_Talk2":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "After_Dinner_Talk3";
		break;

		case "After_Dinner_Talk3":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "After_Dinner_Talk4";
		break;

		case "After_Dinner_Talk4":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "After_Dinner_Talk5";
		break;

		case "After_Dinner_Talk5":
			PlaySound(voice_path + "Wharf01.wav");
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_After_Dinner_Talk";
		break;

		case "Exit_After_Dinner_Talk":
			AddDialogExitQuest("The_Frenchman_Interupts");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "After_Dinner_Talk_Frenchman":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "After_Dinner_Talk_Frenchman2";
		break;

		case "After_Dinner_Talk_Frenchman2":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "After_Dinner_Talk_Frenchman3";
		break;

		case "After_Dinner_Talk_Frenchman3":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_After_Dinner_Talk_Frenchman";
		break;

		case "Exit_After_Dinner_Talk_Frenchman":
			AddDialogExitQuest("Duchess_and_Frenchman_leave");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_next_day_Talk":
			PlaySound(voice_path + "Hornblwr02.wav");
			dialog.text = GetMyName(PChar);
			link.l1 = DLG_TEXT[40];
			link.l1.go = "The_next_day_Talk2";
		break;

		case "The_next_day_Talk2":
			PlaySound(voice_path + "Wharf05.wav");
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "The_next_day_Talk3";
		break;

		case "The_next_day_Talk3":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "The_next_day_Talk4";
		break;

		case "The_next_day_Talk4":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Exit_The_next_day_Talk";
		break;

		case "Exit_The_next_day_Talk":
			AddDialogExitQuest("The_Last_of_the_Duchess");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Duchess_is_rested":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Duchess_is_rested";
		break;

		case "Exit_Duchess_is_rested":
			AddDialogExitQuest("Pellew_for_Jamaica_and_documents");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Duchess_gives_documents_back":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Duchess_gives_documents_back";
		break;

		case "Exit_Duchess_gives_documents_back":
			AddDialogExitQuest("Promtion_and_return");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Duchess_defends_Horatio":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Duchess_defends_Horatio";
		break;

		case "Exit_Duchess_defends_Horatio":
			AddDialogExitQuest("Pellew_and_promotion");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

			}
}
