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

//------------------------------------------------------------------------------


		case "map_lost":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "map_lost2";
		break;

		case "map_lost2":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "map_lost3";
		break;

		case "map_lost3":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "map_lost4";
		break;

		case "map_lost4":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "map_lost5";
		break;

		case "map_lost5":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "map_lost6";
		break;

		case "map_lost6":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("optimism");
		break;

		case "optimism_cont":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "optimism_cont2";
		break;

		case "optimism_cont2":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "optimism_cont3";
		break;

		case "optimism_cont3":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "optimism_cont4";
		break;

		case "optimism_cont4":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "optimism_cont5";
		break;

		case "optimism_cont5":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
			AddDialogExitQuest("Martinica_to_Greenford");
		break;

		case "Cuban_history":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Cuban_history2";
		break;

		case "Cuban_history2":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Cuban_history3";
		break;

		case "Cuban_history3":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Cuban_history4";
		break;

		case "Cuban_history4":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Cuban_history5";
		break;

		case "Cuban_history5":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Cuban_history6";
		break;

		case "Cuban_history6":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "Cuban_history7";
		break;

		case "Cuban_history7":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Cuban_history8";
		break;

		case "Cuban_history8":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Cuban_history9";
		break;

		case "Cuban_history9":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
			AddDialogExitQuest("Cuban_history_over");
		break;

		case "Malaga_Ahoy":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
			AddDialogExitQuest("Santiago_storytime");
		break;

		case "Santiago_choose":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "Santiago_choose2";
		break;

		case "Santiago_choose2":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "exit_Beatrice_Santiago";
			link.l2 = DLG_TEXT[65];
			link.l2.go = "exit_Blaze_Santiago";
			link.l3 = DLG_TEXT[66];
			link.l3.go = "exit_Bonnie_Santiago";
		break;

		case "exit_Beatrice_Santiago":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Beatrice_Santiago_start");
		break;

		case "exit_Blaze_Santiago":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Switch_to_Blaze");
			AddDialogExitQuest("Blaze_Santiago_start");
		break;

		case "exit_Bonnie_Santiago":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Switch_to_Bonnie");
			AddDialogExitQuest("Bonnie_Santiago_start");
		break;

//-----------------------------------

		case "celebrating":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "celebrating2";
		break;

		case "celebrating2":
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			AddDialogExitQuest("glue_map");
		break;

//-------------------------------------------------

		case "Gambling_SD":
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "Gambling_SD2";
		break;

		case "Gambling_SD2":
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "exit";
			AddDialogExitQuest("two_idiots");
		break;

		case "afteridiots":
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "afteridiots2";
		break;

		case "afteridiots2":
			AddMoneyToCharacter(pchar, 10000);
			PlaySound("INTERFACE\coins8.wav");
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit";
			AddDialogExitQuest("Domingo_Debriefing");
		break;

		case "Blaze_SD_Deb":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "Blaze_SD_Deb2";
		break;

		case "Blaze_SD_Deb2":
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "Blaze_SD_Deb3";
		break;

		case "Blaze_SD_Deb3":
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "exit";
			AddDialogExitQuest("Domingo_Debriefing5");
		break;

//-------------------------------------------------

		case "mensjob":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "exit";
			AddDialogExitQuest("Switch_to_Blaze");
			AddDialogExitQuest("Blaze_Cayman_start");
		break;


	}
}