//#include "DIALOGS\Elizabeth Swann_dialog.h"

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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (CheckQuestAttribute("Jackpot", "search"))
			{
				dialog.snd = "Voice\CLLA\CLLA004";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "begin_1";	
			}
		break;

		case "begin_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_2";
		break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_3";
		break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("leavetortuga");
		break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("meetprisoner");
		break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("seesoldier");
		break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("leavedevilcreek2");
		break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("leaveswann");
		break;

		case "begin_8":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_9";
		break;

		case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "begin_10";
		break;

		case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA004";
//			dialog.text = DLG_TEXT[22] + GetMyFullName(PChar);	// GR: GetMyFullName includes rank if you have one, e.g. Captain Freebooter Jack Sparrow
			dialog.text = DLG_TEXT[22] + GetMySimpleName(PChar) + ".";
			link.l1 = DLG_TEXT[23];
			link.l1.go = "begin_11";
		break;

		case "begin_11":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "begin_11A";
		break;

		case "begin_11A":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			AddDialogExitQuest("voirdauntless");
		break;

		case "begin_12":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "begin_13";
		break;

		case "begin_13":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("justapresfight3");
		break;

		case "out_of_the_water":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "out_of_the_water2";
		break;

		case "out_of_the_water2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Exit";
		break;

		case "In_the_prison":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "In_the_prison2";
		break;

		case "In_the_prison2":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "prisonexit";
		break;
		
		case "Talk_at_Tortuga_Tavern_Eliza":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Talk_at_Tortuga_Tavern_Eliza_2";
		break;
		
		case "Talk_at_Tortuga_Tavern_Eliza_2":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("Elizabeth_tortuga_port_tp");
		break;
	
		//Port scenes
		case "Elizabeth_tortuga_port_talk":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Elizabeth_tortuga_port_talk_2";
		break;
		
		case "Elizabeth_tortuga_port_talk_2":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			AddDialogExitQuest("Norrington_tortuga_port_talk");
		break;
			
		//Port scenes after norrington
		case "Elizabeth_tortuga_port_talk_3":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Elizabeth_tortuga_port_talk_4";
		break;
		
		case "Elizabeth_tortuga_port_talk_4":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Elizabeth_tortuga_port_talk_5";
		break;
		
		case "Elizabeth_tortuga_port_talk_5":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "Elizabeth_tortuga_port_talk_6";
		break;
		
		case "Elizabeth_tortuga_port_talk_6":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Elizabeth_tortuga_port_talk_7";
		break;
		
		case "Elizabeth_tortuga_port_talk_7":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Elizabeth_tortuga_port_talk_8";
		break;
		
		case "Elizabeth_tortuga_port_talk_8":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Elizabeth_tortuga_port_talk_9";
		break;
		
		case "Elizabeth_tortuga_port_talk_9":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Elizabeth_tortuga_port_talk_10";
		break;
		
		case "Elizabeth_tortuga_port_talk_10":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "Exit";
			AddDialogExitQuest("Gibbs_talk_port_final");
		break;

		case "prisonexit":
			AddDialogExitQuest("ReturntoGovernoragain");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
	}
}
