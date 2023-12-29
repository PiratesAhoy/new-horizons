//#include "DIALOGS\Fake Bea_Dialog.h"
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

			PlaySound("VOICE\ENGLISH\Beatrice01.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "go_hide2";
		break;

		case "go_hide2":
			dialog.text = DLG_TEXT[2];
                        if (GetRMRelation(PChar, SPAIN) <= REL_WAR)
                        {
			link.l1 = DLG_TEXT[3];
			link.l1.go = "warspain";
                        }
                        else
                        {
			link.l1 = DLG_TEXT[3];
			link.l1.go = "go_hide3";
                        }
		break;

		case "go_hide3":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "go_hide4";
		break;

		case "go_hide4":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Fake_Bea_removes");
		break;

		case "warspain":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "warspain2";
		break;

		case "warspain2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "warspain3";
		break;

		case "warspain3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Fake_Bea_removes");
		break;

//=========================================

		case "wrapitup":
			PlaySound("VOICE\ENGLISH\Beatrice01.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "wrapitup2";
		break;

		case "wrapitup2":
			PlaySound("INTERFACE\drink.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "wrapitup3";
		break;

		case "wrapitup3":
			if (PChar.location.from_sea == "Cayman_port")
			{
			dialog.text = DLG_TEXT[12];
			}
                        else
			{
			dialog.text = DLG_TEXT[23];
			}
			link.l1 = DLG_TEXT[13];
			link.l1.go = "wrapitup4";
		break;

		case "wrapitup4":
			dialog.text = DLG_TEXT[14];
                        if (CheckQuestAttribute("ANNIE", "hired"))
                        {
			link.l1 = DLG_TEXT[15];
			link.l1.go = "wrapitup5";
                        }
                        else
                        {
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
                        }
			AddDialogExitQuest("Cayman_finish");
			AddDialogExitQuest("Switch_to_Beatrice");
		break;

		case "wrapitup5":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "wrapitup6";
		break;

		case "wrapitup6":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
		//	AddDialogExitQuest("Cayman_finish");
		//	AddDialogExitQuest("Switch_to_Beatrice");
		break;

//========================== Battle

		case "borrowship":
			PlaySound("VOICE\ENGLISH\Beatrice01.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "borrowship2";
		break;

		case "borrowship2":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "borrowship3";
		break;

		case "borrowship3":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "borrowship4";
		break;

		case "borrowship4":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("Cayman_sea_battle_begins");
		break;

		case "congrats":
			PlaySound("VOICE\ENGLISH\Beatrice01.wav");
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "congrats2";
		break;

		case "congrats2":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "congrats3";
		break;

		case "congrats3":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "congrats4";
		break;

		case "congrats4":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("Bea_congrats_over");
		break;

	}
}