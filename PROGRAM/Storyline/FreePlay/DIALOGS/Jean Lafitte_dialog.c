//#include "DIALOGS\Jean Lafitte_dialog.h"

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

			dialog.snd = "Voice\CLLA\CLLA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			break;

		case "begin_1":
			TakeItemFromCharacter(pchar, "Letter_Lafitte");		
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
			break;

		case "begin_2":
           Locations[FindLocation("Tortuga_tavern")].vcskip = true;		
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_3";
			break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";
			AddDialogExitQuest("lafitte_tavern");					
			break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "begin_5";			
			break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "begin_6";
			break;
			
		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "begin_7";
			break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "begin_8";
			break;

		case "begin_8":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "begin_9";
			break;
			
		case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "begin_10";
			break;

		case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "begin_11";
			break;
			
		case "begin_11":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "begin_12";
			break;

		case "begin_12":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "begin_13";
			break;
			
		case "begin_13":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "begin_14";
			break;

		case "begin_14":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "begin_15";
			break;
			
		case "begin_15":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
            AddDialogExitQuest("lafitte_tortuga_port");				
			break;

		case "begin_16":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "begin_17";
			break;
			
		case "begin_17":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "exit";
			AddDialogExitQuest("leave_tortuga2");				
			break;

		case "begin_18":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "begin_19";
			break;
			
		case "begin_19":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("go_turks");				
			break;

		case "begin_20":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("go_port_turks");			
			break;
			
		case "begin_21":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "begin_22";
			break;

		case "begin_22":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";
			AddDialogExitQuest("Talks_in_Turks_Tavern");					
			break;
			
		case "begin_23":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "begin_24";				
			break;

		case "begin_24":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "begin_25";		
			break;

		case "begin_25":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "begin_26";
			break;

		case "begin_26":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "begin_27";			
			break;
						
		case "begin_27":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "begin_28";		
			break;
			
		case "begin_28":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "begin_29";
			break;

		case "begin_29":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";
			AddDialogExitQuest("Talks_Turks_Barman");			
			break;

		case "begin_30":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
			AddDialogExitQuest("seeing_Laura_Cotton");			
			break;

		case "begin_32":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
			AddDialogExitQuest("Laura_Cotton_House3");			
			break;

		case "begin_33":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
			AddDialogExitQuest("Laura_Cotton_House5");			
			break;

		case "begin_34":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "begin_35";
			break;

		case "begin_35":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "begin_36";
            TakenItems(Pchar, "time_bomb", 1);			
			break;
			
		case "begin_36":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "begin_37";
			break;

		case "begin_37":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "begin_37B";
			break;
			
		case "begin_37B":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "exit";
			AddDialogExitQuest("boarding_warship");			
			break;			

		case "begin_38":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "exit";
			AddDialogExitQuest("back_to_lighthouse");			
			break;

		case "begin_39":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "begin_40";
			break;

		case "begin_40":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit";
			AddDialogExitQuest("goodbye_lafitte");			
			break;			
			
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
	}
}
