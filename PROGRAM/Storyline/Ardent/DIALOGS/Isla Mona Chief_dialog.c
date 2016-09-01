//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string NPC_Meeting;

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
			NPChar.quest.meeting = NPC_Meeting;
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

			if(NPChar.quest.meeting == "0")
			{
				NPC_Meeting = "1"; 
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + ".";
				link.l1.go = "meeting";
			}
			else
			{
				dialog.text = DLG_TEXT[2] + GetMyName(Pchar) + ".";
				link.l1 = DLG_TEXT[3];
				link.l1.go = "meeting";
			}
		break;

		case "meeting":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "history";
			link.l2 = DLG_TEXT[6];
			link.l2.go = "pirates";
			link.l3 = DLG_TEXT[7];
			link.l3.go = "exit";
		break;

		case "history":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "history2";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "exit";
		break;

		case "history2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "history3";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "exit";
		break;

		case "history3":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "history4";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "exit";
		break;

		case "history4":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "history5";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "exit";
		break;

		case "history5":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "pirates";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "exit";
		break;

		case "pirates":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "pirates2";
			link.l2 = DLG_TEXT[21];
			link.l2.go = "exit";
		break;

		case "pirates2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "pirates3";
			link.l2 = DLG_TEXT[24];
			link.l2.go = "exit";
		break;

		case "pirates3":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "pirates4";
			link.l2 = DLG_TEXT[24];
			link.l2.go = "exit";
		break;

		case "pirates4":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "pirates5";
			link.l2 = DLG_TEXT[29];
			link.l2.go = "exit";
		break;

		case "pirates5":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "history";
			link.l2 = DLG_TEXT[29];
			link.l2.go = "exit";
		break;

		case "two_dogs_home":
			NPC_Meeting = "1"; 
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33] + GetMyFullName(characterFromID("Two Dogs")) + DLG_TEXT[34];
			link.l1.go = "two_dogs_home2";
		break;

		case "two_dogs_home2":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "two_dogs_home3";
		break;

		case "two_dogs_home3":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "two_dogs_home4";
		break;

		case "two_dogs_home4":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
		break;

		case "temple_quest":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "temple_quest2";
		break;

		case "temple_quest2":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "temple_quest3";
		break;

		case "temple_quest3":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "temple_quest4";
		break;

		case "temple_quest4":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "temple_quest5";
		break;

		case "temple_quest5":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "temple_quest6";
		break;

		case "temple_quest6":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "temple_quest_accepted";
			link.l2 = DLG_TEXT[53];
			link.l2.go = "exit";
		break;

		case "temple_quest_accepted":
			AddDialogExitQuest("temple_quest_starts");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "is_this_it":
			dialog.text = DLG_TEXT[54] + GetMyName(Pchar) + DLG_TEXT[55];
			if (CheckCharacterItem(PChar, "TainoRug"))
			{
				link.l1 = DLG_TEXT[56];
				link.l1.go = "is_this_it2";
			}
			else
			{
				link.l1 = DLG_TEXT[65];
				link.l1.go = "nothing_found";
			}
		break;

		case "is_this_it2":
			TakeItemFromCharacter(Pchar, "TainoRug");
			AddDialogExitQuest("get_bow");
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "bows_and_akellani";
		break;

		case "bows_and_akellani":
			if (ENABLE_AMMOMOD)
			{
				dialog.text = DLG_TEXT[59];
				link.l1 = DLG_TEXT[60];
				link.l1.go = "bows_and_akellani2";
			}
			else
			{
				dialog.text = DLG_TEXT[67];
				link.l1 = DLG_TEXT[62];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[63];
				link.l2.go = "bows_and_akellani3";
			}
		break;

		case "bows_and_akellani2":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[63];
			link.l2.go = "bows_and_akellani3";
		break;

		case "bows_and_akellani3":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
		break;

		case "nothing_found":
			AddDialogExitQuest("no_rug");
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[63];
			link.l2.go = "bows_and_akellani3";
		break;
	}
}