//#include "DIALOGS\Teague Sparrow_dialog.h"
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

	string voice_path = "VOICE\ENGLISH\";
	if (CheckDirectory("RESOURCE\Sounds\VOICE\"+LanguageGetLanguage()+"\","*") > 0) voice_path = "VOICE\" + LanguageGetLanguage() + "\";

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

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

		break;

		case "Why_we_are_here":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Why_we_are_here2";
		break;

		case "Why_we_are_here2":
			dialog.text = DLG_TEXT[21] + GetMySimpleName(PChar) + DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Why_we_are_here3";
		break;

		case "Why_we_are_here3":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Why_we_are_here4";
		break;

		case "Why_we_are_here4":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Why_we_are_here5";
		break;

		case "Why_we_are_here5":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Why_we_are_here6";
		break;

		case "Why_we_are_here6":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Why_we_are_here7";
		break;

		case "Why_we_are_here7":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Why_we_are_here8";
		break;

		case "Why_we_are_here8":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Why_we_are_here";
		break;

		case "Start_of_the_conversation":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "conversation2";
		break;	

		case "conversation2":
			dialog.text = DLG_TEXT[5] + pchar.lastname + DLG_TEXT[6] + pchar.lastname + DLG_TEXT[7];
			link.l1 = DLG_TEXT[8]; 
			link.l1.go = "conversation3";
		break;

		case "conversation3":
			PlaySound(voice_path + "Hornblwr01.wav");
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit_Pellew_Chimes_in";
		break;

		case "conversation4":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "conversation5";
		break;

		case "conversation5":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "conversation6";
		break;

		case "conversation6":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "conversation7";
		break;

		case "conversation7":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exitconversation";
		break;

		case "Exit_Why_we_are_here":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("To_the_Shipyard_Antigua");
		break;

		case "Exitconversation":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Eleuthera_mission");
		break;

		case "Exit_Pellew_Chimes_in":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Pellew_Chimes_In");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}
