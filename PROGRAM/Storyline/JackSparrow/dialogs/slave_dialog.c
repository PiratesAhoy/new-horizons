//#include "DIALOGS\anacleto_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\ANAC\ANAC001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "node_2";
		break;
		
		case "node_2":
			dialog.snd = "Voice\ANAC\ANAC002";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
		break;
		
		case "ask_about_artois":
			dialog.snd = "Voice\ANAC\ANAC003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("Blaze_cop_dialog");
		break;
		
		case "artois_lay":
			dialog.snd = "Voice\ANAC\ANAC004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "artois_lay_2";
		break;
		
		case "artois_lay_2":
			dialog.snd = "Voice\ANAC\ANAC005";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "artois_lay_2";
		break;
		
		case "artois_lay_3":
			dialog.snd = "Voice\ANAC\ANAC006";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("fight_for_artois_with_child_of_giens");
		break;
		
		case "doctor_2":
			dialog.snd = "Voice\ANAC\ANAC007";
			dialog.text = DLG_TEXT[12];
			if (makeint(pchar.money)>=2000)
			{
				link.l1 = DLG_TEXT[13];
				link.l1.go = "doctor_3";
			}
			link.l2 = DLG_TEXT[14];
			link.l2.go = "exit_doctor_bad";
		break;
		
		case "doctor_3":
			dialog.snd = "Voice\ANAC\ANAC008";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit_doctor_good";
			link.l2 = DLG_TEXT[17];
			link.l2.go = "exit_doctor_bad";
		break;
		
		case "exit_doctor_good":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("exit_doctor_good");
		break;
		
		case "remove":
			if (npchar.alignment == "good")
			{
				dialog.snd = "Voice\ANAC\ANAC009";
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
			}
			else
			{
				dialog.snd = "Voice\ANAC\ANAC010";
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];
			}
			link.l1.go = "exit";
			pchar.removed_officer = GetCharacterIndex(npchar.id);
			AddDialogExitQuest("removed_officer_runaway");
			npchar.location = npchar.homelocation;
			npchar.location.group = npchar.homelocation.group;
			npchar.location.locator = npchar.homelocation.locator;
		break;
		
		case "hired_again":
			dialog.snd = "Voice\ANAC\ANAC011";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "hired_again_2";
		break;
		
		case "hired_again_2":
			dialog.snd = "Voice\ANAC\ANAC012";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddPassenger(Pchar, npchar, 0);
			npchar.loyality = 1;
			npchar.dialog.filename = npchar.selfdialog.filename;
			npchar.dialog.currentnode = npchar.selfdialog.currentnode;
		break;
		
		case "steal":
			dialog.text = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("Dauntless_Deck_NORR3");
		break;

		case "disable":
			dialog.text = DLG_TEXT[40];
			link.l1.go = "exit";
			AddDialogExitQuest("Dauntless_Deck_NORR6");
		break;

		case "best_pirate":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("Dauntless_Deck_NORR8");
		break;

		case "exit_doctor_bad":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("exit_doctor_bad");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
