//#include "DIALOGS\Blaze Devlin_dialog.h"
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
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Meeting1":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Meeting2";
		break;

		case "Meeting2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Meeting3";
		break;

		case "Meeting3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Meeting4";
		break;

		case "Meeting4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit";
			AddDialogExitQuest("meet_Blaze_below2");
		break;

		case "Meeting5":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Meeting6";
		break;

		case "Meeting6":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Meeting7";
		break;

		case "Meeting7":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Meeting8";
		break;

		case "Meeting8":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Meeting9";
		break;

		case "Meeting9":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit";
			CloseQuestHeader("My Brother, Ladies and Gentlemen");
			SetQuestHeader("Yo Ho Ho and a shipment of rum");
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 1);
			AddDialogExitQuest("YoHoRum");
		break;

		case "Martinica_arrival":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Martinica_arrival_2";
		break;

		case "Martinica_arrival_2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit_Beatrice_Martinica";
			link.l2 = DLG_TEXT[24];
			link.l2.go = "exit_Blaze_Martinica";
			link.l3 = DLG_TEXT[25];
			link.l3.go = "exit_Bonnie_Martinica";
		break;

		case "exit_Beatrice_Martinica":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Beatrice_Martinica_start");
		break;

		case "exit_Blaze_Martinica":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Switch_to_Blaze");
			AddDialogExitQuest("Blaze_Martinica_start");
		break;

		case "exit_Bonnie_Martinica":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Switch_to_Bonnie");
			AddDialogExitQuest("Bonnie_Martinica_start");
		break;

	}
}