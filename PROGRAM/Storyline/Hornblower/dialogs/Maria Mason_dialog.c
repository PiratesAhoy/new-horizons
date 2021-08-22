//#include "DIALOGS\Bartholomew Roberts_dialog.h"
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
			
			dialog.snd = "Voice\ARSI\ARSI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "My_name_is_Maria":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "My_name_is_Maria2";
		break;

		case "My_name_is_Maria2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "My_name_is_Maria3";
		break;

		case "My_name_is_Maria3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_My_name_is_Maria";
		break;

		case "Exit_My_name_is_Maria":
			AddDialogExitQuest("Two_months_later");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_penny_for_your_thoughts":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "A_penny_for_your_thoughts2";
		break;

		case "A_penny_for_your_thoughts2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "A_penny_for_your_thoughts3";
		break;

		case "A_penny_for_your_thoughts3":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "A_penny_for_your_thoughts4";
		break;

		case "A_penny_for_your_thoughts4":
			GiveItem2Character((Pchar), "blade4");
			EquipCharacterByItem((Pchar), "blade4");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "A_penny_for_your_thoughts5";
		break;

		case "A_penny_for_your_thoughts5":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "A_penny_for_your_thoughts6";
		break;

		case "A_penny_for_your_thoughts6":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_A_penny_for_your_thoughts";
		break;

		case "Exit_A_penny_for_your_thoughts":
			AddDialogExitQuest("Riflemen_in_the_Tavern");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Maria's_Halfcrown":
			PlaySound("VOICE\ENGLISH\MariaMason01.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit_Maria's_Halfcrown";
		break;

		case "Exit_Maria's_Halfcrown":
			AddDialogExitQuest("Mother_is_annoyed");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Maria_sympthay":
			PlaySound("VOICE\ENGLISH\MariaMason02.wav");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Maria_sympthay2";
		break;

		case "Maria_sympthay2":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit_Maria_sympthay";
		break;

		case "Exit_Maria_sympthay":
			AddDialogExitQuest("Fade_to_Town");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Youre_leaving_us":
			PlaySound("VOICE\ENGLISH\MariaMason03.wav");
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Youre_leaving_us2";
		break;

		case "Youre_leaving_us2":
			PlaySound("VOICE\ENGLISH\MariaMason04.wav");
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Youre_leaving_us3";
		break;

		case "Youre_leaving_us3":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Youre_leaving_us";
		break;

		case "Exit_Youre_leaving_us":
			LAi_SetActorType(characterFromID("Maria Mason"));
			AddDialogExitQuest("Port_and_Departure");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Got_us_out":
			PlaySound("VOICE\ENGLISH\MariaMason05.wav");
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Got_us_out2";
		break;

		case "Got_us_out2":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Got_us_out3";
		break;

		case "Got_us_out3":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_Got_us_out";
		break;

		case "Exit_Got_us_out":
			AddDialogExitQuest("Bush_Wolfe_Battle");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Saw_the_Hotspur":
			PlaySound("VOICE\ENGLISH\MariaMason06.wav");
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Saw_the_Hotspur2";
		break;

		case "Saw_the_Hotspur2":
			PlaySound("VOICE\ENGLISH\MariaMason07.wav");
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Saw_the_Hotspur3";
		break;

		case "Saw_the_Hotspur3":
			PlaySound("VOICE\ENGLISH\MariaMason08.wav");
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Saw_the_Hotspur4";
		break;

		case "Saw_the_Hotspur4":
			PlaySound("VOICE\ENGLISH\MariaMason09.wav");
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Saw_the_Hotspur5";
		break;

		case "Saw_the_Hotspur5":
			PlaySound("VOICE\ENGLISH\MariaMason10.wav");
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Exit_Saw_the_Hotspur";
		break;

		case "Exit_Saw_the_Hotspur":
			AddDialogExitQuest("Mother_tells");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Marry_me":
			PlaySound("VOICE\ENGLISH\MariaMason11.wav");
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Marry_me2";
		break;

		case "Marry_me2":
			PlaySound("VOICE\ENGLISH\MariaMason12.wav");
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Marry_me3";
		break;

		case "Marry_me3":
			PlaySound("VOICE\ENGLISH\MariaMason13.wav");
			dialog.text = DLG_TEXT[51];
//			link.l1 = DLG_TEXT[48];
			link.l1.go = "Exit_Marry_me";
		break;

		case "Exit_Marry_me":
//			AddDialogExitQuest("Church_marriage_scene");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Back_home":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Exit";
		break;
	}
}

