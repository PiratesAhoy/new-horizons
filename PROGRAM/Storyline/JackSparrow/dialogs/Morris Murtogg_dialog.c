//#include "DIALOGS\Morris Murtogg_dialog.h"
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
			Dialog.snd = "voice\THDI\THDI001";

			d.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "speak1";
		break;

		case "speak1":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "speak2";
		break;

		case "speak2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "speak3";
		break;

		case "speak3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exitMurtogg1";
		break;

		case "speak4":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "speak5";
		break;

		case "speak5":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exitMurtogg2";
		break;

		case "speak6":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "speak7";
		break;

		case "speak7":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exitMurtogg3";
//			PlaySound("OBJECTS\voices\dead\female\dead_wom1.wav");
			PlaySound("OBJECTS\voices\dead\female\dead_wom1.wav");
			PlaySound("OBJECTS\shipcharge\ship_bow");
		break;

		case "speak8":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			link.l1.go = "exitMurtogg4";
		break;

		case "speak10":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "speak11";
		break;

		case "speak11":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exitfirst";
		break;

		case "exitfirst":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_3"), PChar, "");
			AddDialogExitQuest("go_to_fight_Slave_Traders");
			DialogExit();
			Diag.CurrentNode = "speaktoTiaagain";
		break;

		case "speaktoTiaagain":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\THDI\THDI001";

			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "speakagain";
		break;

		case "speakagain":
			dialog.text = DLG_TEXT[26] + pchar.lastname + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "speakagain2";
		break;

		case "speakagain2":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "speakagain3";
		break;

		case "speakagain3":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "speakagain4";
		break;

		case "speakagain4":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "speakagain5";
		break;

		case "speakagain5":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "speakagain6";
		break;

		case "speakagain6":
			AddMoneyToCharacter(pchar, -500);
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "speakagain7";
		break;

		case "speakagain7":
			GiveItem2Character(Pchar,"Compass3");
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "speakagain8";
		break;

		case "speakagain8":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit2";
			AddQuestRecord("And_now_Beckett_and_Beckett", "6");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = "First time";

		break;

		case "exitMurtogg1":
			AddDialogExitQuest("I_know_that_ship");
			DialogExit();
			Diag.CurrentNode = "First time";

		break;

		case "exitMurtogg2":
			AddDialogExitQuest("Hes_not_lying");
			DialogExit();
			Diag.CurrentNode = "First time";

		break;

		case "exitMurtogg3":
			PlaySound("OBJECTS\shipcharge\ball_splash1.wav");
			PlaySound("OBJECTS\shipcharge\ship_bow");
			AddDialogExitQuest("can_you_swim");
			DialogExit();
			Diag.CurrentNode = "First time";
		break;

		case "exitMurtogg4":
			AddDialogExitQuest("Dives_in_water_for_Elizabeth");
			DialogExit();
			Diag.CurrentNode = "First time";

		break;

	}
}
