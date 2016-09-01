//#include "DIALOGS\Two Dogs_dialog.h"
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
			link.l1.go = "exit";
		break;

		case "meet_two_dogs":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Deal";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "exit";
		break;

		case "Deal":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "release_me";
		break;

		case "release_me":
			AddDialogExitQuest("release_two_dogs_2");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "introduction":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8] + GetMyFullName(PChar) + DLG_TEXT[9];
			link.l1.go = "knife";
		break;

		case "knife":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "new_offer";
		break;

		case "new_offer":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "new_deal";
			link.l2 = DLG_TEXT[14];
			link.l2.go = "no_deal";
		break;

		case "new_deal":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "new_deal2";
		break;

		case "new_deal2":
			AddDialogExitQuest("new_deal_with_Two_Dogs");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "no_deal":
			AddDialogExitQuest("get_lost_Two_Dogs");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "job_done":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "agree_to_take_home";
			if (checkquestattribute("alignment", "evil"))
			{
				link.l2 = DLG_TEXT[20];
				link.l2.go = "unwanted";
			}
		break;

		case "agree_to_take_home":
			dialog.text = DLG_TEXT[19];
			link.l1.go = "agree_to_take_home2";
		break;

		case "agree_to_take_home2":
			AddDialogExitQuest("take_Two_Dogs_home");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "unwanted":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "unwanted2";
		break;

		case "unwanted2":
			AddDialogExitQuest("two_dogs_betrayed");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "embarrassing_name":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
		break;

		case "rejoin":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "rejoin_accepted";
			link.l2 = DLG_TEXT[27];
			link.l2.go = "rejoin_denied";
		break;

		case "rejoin_accepted":
			AddDialogExitQuest("two_dogs_rejoins");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "rejoin_denied":
			AddDialogExitQuest("two_dogs_no_rejoin");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "bass_joke":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
		break;
	}
}