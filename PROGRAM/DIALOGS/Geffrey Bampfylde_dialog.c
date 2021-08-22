//#include "DIALOGS\Geffrey Bampfylde_dialog.h"
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

			dialog.snd = "Voice\GEBA\GEBA001";
			dialog.text = DLG_TEXT[0]+ Characters[GetCharacterIndex(DLG_TEXT[1])].name +DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "1";

		break;

		case "1":
			dialog.snd = "Voice\GEBA\GEBA002";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "2";
		break;

		case "2":
			dialog.snd = "Voice\GEBA\GEBA003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "3";
		break;

		case "3":
			dialog.snd = "Voice\GEBA\GEBA005";
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[8] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[9])]) + DLG_TEXT[10];
			link.l1 = Characters[GetCharacterIndex(DLG_TEXT[11])].name +DLG_TEXT[12];
			link.l1.go = "Exit_talk_to_Bucho";
		break;

		case "plea":
			dialog.snd = "Voice\GEBA\GEBA006";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit_kill";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "cash";
			if (FindCurrentStoryline() != FindStoryline("Assassin"))
			{
				link.l3 = DLG_TEXT[16];
				link.l3.go = "Exit_spare";
			}
		break;

		case "cash":

			ChangeCharacterReputation(pchar, -10);
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, 5000);
			dialog.snd = "Voice\GEBA\GEBA007";
			dialog.text = DLG_TEXT[17];
			if (FindCurrentStoryline() != FindStoryline("Assassin"))
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "Exit_spare_cash";
			}
			link.l2 = DLG_TEXT[19];
			link.l2.go = "Exit_kill_cash";

		break;

		case "Exit_talk_to_Bucho":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_talk_to_Bucho");

		break;

		case "Exit_kill":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterReputation(pchar, -10);

			AddDialogExitQuest("Hit_kill_Geffrey");

		break;

		case "Exit_kill_cash":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterReputation(pchar, -15);

			AddDialogExitQuest("Hit_kill_Geffrey");

		break;

		case "Exit_spare":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterReputation(pchar, 10);

			AddDialogExitQuest("Hit_spare_Geffrey");

		break;

		case "Exit_spare_cash":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterReputation(pchar, 5);

			AddDialogExitQuest("Hit_spare_Geffrey");

		break;

	}
}
