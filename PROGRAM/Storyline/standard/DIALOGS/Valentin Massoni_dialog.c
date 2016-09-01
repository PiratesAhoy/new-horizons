//#include "DIALOGS\Valentin Massoni_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------ƒË‡ÎÓ„ ÔÂ‚˚È - ÔÂ‚‡ˇ ‚ÒÚÂ˜‡

		case "Exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "Massoni_spared":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Massoni_spared");
		break;
	
		case "Massoni_doomed":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Massoni_doomed");
		break;
	
		case "Exit_GiveRum":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_SitAndDrinkWithMassoni");
		break;

		case "First time":
			Dialog.defAni = "Sit_Right_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Right_Dialog_2";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIÃ¿\VIÃ¿001";
			
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "First time_1";	
		break;

		case "First time_1":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿002";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "exit";	
		break;

		case "Story_first talk":
			Dialog.defAni = "Sit_Right_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Right_Dialog_1";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIÃ¿\VIÃ¿003";
			
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6];
			Link.l1.go = "Node_2";	
		break;

		case "Node_2":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿004";
			d.Text = RandSwear() + DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "Node_3";
		break;

		case "Node_3":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿005";
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Node_4";
		break;

		case "Node_4":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿006";
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "Node_5";
		break;

		case "Node_5":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿007";
			Diag.TempNode = "SitAndDrink";
			d.Text = DLG_TEXT[13]; 
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Exit_GiveRum";
		break;

		case "SitAndDrink":
			Dialog.defAni = "Sit_Look_Around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "Sit_Look_Around";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Look_Around";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIÃ¿\VIÃ¿008";
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "Node_7";
		break;

		case "Node_7":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿009";
			d.Text = DLG_TEXT[17] + NPChar.ship.name + DLG_TEXT[18] ;
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "node_8";
		break;
	
		case "Node_8":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿010";
			d.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Node_9";
		break;
	
		case "Node_9":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿011";
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Node_10";
		break;

		case "Node_10":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿012";
			d.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "Node_11";
		break;

		case "Node_11":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿013";
			d.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "Node_12";
		break;

		case "Node_12":
			Diag.TempNode = "Second_talk";
			Dialog.snd = "voice\VIÃ¿\VIÃ¿014";
			d.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_Massony_Reload_to_Town");
		break;

		case "Talk_to_Soldiers":
			Diag.TempNode = "Final_talk";
			Dialog.snd = "voice\VIÃ¿\VIÃ¿015";
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "exit";
		break;

		case "What_are_you_waiting_for":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_stay2";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIÃ¿\VIÃ¿016";
			Dialog.tempNode = "What_are_you_waiting_for";

			d.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "exit";
			AddDialogExitQuest("Massony_run_to_last_locator");
		break;

		case "Final_talk":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIÃ¿\VIÃ¿017";

			d.Text = DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35];
			Link.l1.go = "Final_talk_1";
		break;

		case "Final_talk_1":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿018";
			d.Text = DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Final_talk_2";
		break;

		case "Final_talk_2":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿019";
			d.Text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "Final_talk_3";
		break;

		case "Final_talk_3":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿020";
			d.Text = DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "Final_talk_4";
		break;

		case "Final_talk_4":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿021";
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "Final_talk_5";
		break;

		case "Final_talk_5":
			Dialog.snd = "voice\VIÃ¿\VIÃ¿022";
			d.Text = DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Final_talk_6";
		break;

		case "Final_talk_6":
			AddQuestRecord("Story_1stTaskReceived", 4);
			Pchar.quest.Story_1stTaskComplete = "1";
			Dialog.snd = "voice\VIÃ¿\VIÃ¿023";
			d.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Massoni_spared";
			Link.l2 = DLG_TEXT[48];
			Link.l2.go = "Massoni_doomed";
		break;


		}
}

