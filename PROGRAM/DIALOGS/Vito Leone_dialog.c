//#include "DIALOGS\Vito Leone_dialog.h"
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
			Dialog.snd = "voice\VILE\VILE001";

			dialog.text = DLG_TEXT[0]+ Characters[GetCharacterIndex(DLG_TEXT[1])].lastname +DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";

			if(PChar.quest.Hitman == "mark_vito")
			{
				Dialog.snd = "voice\VILE\VILE002";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5]+ Characters[GetCharacterIndex(DLG_TEXT[6])].name +" "+ Characters[GetCharacterIndex(DLG_TEXT[7])].lastname +DLG_TEXT[8];
				link.l1.go = "1";

			}

			if(PChar.quest.Hitman == "hit_mateus")
			{
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, 10000);
			Dialog.snd = "voice\VILE\VILE003";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit_complete";

			}

		break;

		case "1":
			Dialog.snd = "voice\VILE\VILE004";
			dialog.text = DLG_TEXT[11] +GetMyRespectfullyName(PChar)+ DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "2";

		break;

		case "2":
			Dialog.snd = "voice\VILE\VILE005";
			dialog.text = DLG_TEXT[14]+ Characters[GetCharacterIndex(DLG_TEXT[15])].lastname +DLG_TEXT[16];
			link.l1 = DLG_TEXT[17]+ Characters[GetCharacterIndex(DLG_TEXT[18])].lastname +DLG_TEXT[19];
			link.l1.go = "3";

		break;

		case "3":
			Dialog.snd = "voice\VILE\VILE008";
			dialog.text = DLG_TEXT[20]+ Characters[GetCharacterIndex(DLG_TEXT[21])].lastname +DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "4";

		break;

		case "4":
			Dialog.snd = "voice\VILE\VILE009";
			dialog.text = DLG_TEXT[24]+ Characters[GetCharacterIndex(DLG_TEXT[25])].lastname +DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "5";

		break;

		case "5":
			Dialog.snd = "voice\VILE\VILE012";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "6";

		break;

		case "6":
			Dialog.snd = "voice\VILE\VILE013";
			dialog.text = DLG_TEXT[30]+ Characters[GetCharacterIndex(DLG_TEXT[31])].lastname +DLG_TEXT[32];
			link.l1 = DLG_TEXT[33]+ Characters[GetCharacterIndex(DLG_TEXT[34])].lastname +DLG_TEXT[35];
			link.l1.go = "7";

		break;

		case "7":
			Dialog.snd = "voice\VILE\VILE014";
			dialog.text = DLG_TEXT[36]+ Characters[GetCharacterIndex(DLG_TEXT[37])].lastname +DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "8";

		break;

		case "8":
			Dialog.snd = "voice\VILE\VILE015";
			dialog.text = DLG_TEXT[40]+ Characters[GetCharacterIndex(DLG_TEXT[41])].lastname +DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "9";
			if (FindCurrentStoryline() != FindStoryline("Assassin"))
			{
				link.l2 = DLG_TEXT[44];
				link.l2.go = "Exit_kill";
			}
		break;

		case "9":
			Dialog.snd = "voice\VILE\VILE016";
			dialog.text = DLG_TEXT[45]+ Characters[GetCharacterIndex(DLG_TEXT[46])].lastname +DLG_TEXT[47];
			link.l1 = DLG_TEXT[48]+ Characters[GetCharacterIndex(DLG_TEXT[49])].lastname +DLG_TEXT[50];
			link.l1.go = "10";
			if (FindCurrentStoryline() != FindStoryline("Assassin"))
			{
				link.l2 = DLG_TEXT[51]+ Characters[GetCharacterIndex(DLG_TEXT[52])].lastname +DLG_TEXT[53];
				link.l2.go = "Exit_spare";
				link.l3 = DLG_TEXT[54];
				link.l3.go = "Exit_kill";
			}
		break;

		case "10":
			Dialog.snd = "voice\VILE\VILE017";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Exit_hit";
			if (FindCurrentStoryline() != FindStoryline("Assassin"))
			{
				link.l2 = DLG_TEXT[57]+ Characters[GetCharacterIndex(DLG_TEXT[58])].lastname +DLG_TEXT[59];
				link.l2.go = "Exit_spare";
				link.l3 = DLG_TEXT[60];
				link.l3.go = "Exit_kill";
			}

		break;

		case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;

		case "Exit_kill":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterReputation(pchar, -10);

			AddDialogExitQuest("Hit_kill_Vito");

		break;

		case "Exit_spare":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_spare_Vito");

		break;

		case "Exit_hit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_mark_Mateus");

		break;

		case "Exit_complete":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_complete");

		break;

	}
}
