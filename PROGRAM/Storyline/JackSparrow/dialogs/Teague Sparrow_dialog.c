//#include "DIALOGS\Teague Sparrow_dialog.h"
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

			Dialog.mood = "angry";


			ref lcn = &Locations[FindLocation(pchar.location)]
			if(lcn.id == "Grand_Cayman_townhall")
//			if(CheckAttribute(locations[FindLocation(Pchar.location)],"Grand_Cayman_townhall"))
			{
				dialog.snd = "Voice\ARGU\ARGU001";
				PlaySound("VOICE\ENGLISH\Eng_m_c_008.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "The_shame_of_it";
			}
			else
			{
				dialog.snd = "Voice\ARGU\ARGU001";
				PlaySound("VOICE\ENGLISH\Eng_m_c_008.wav");
				dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "Exit";
			}
		break;
		
		case "The_shame_of_it":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "The_shame_of_it2";
		break;	

		case "The_shame_of_it2":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "The_shame_of_it3";
		break;

		case "The_shame_of_it3":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "The_shame_of_it4";
		break;

		case "The_shame_of_it4":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "The_shame_of_it5";
		break;
		
		case "The_shame_of_it5":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "The_shame_of_it6";
		break;

		case "The_shame_of_it6":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "The_shame_of_it7";
		break;

		case "The_shame_of_it7":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "The_shame_of_it8";
		break;

		case "The_shame_of_it8":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "The_shame_of_it9";
		break;
		
		case "The_shame_of_it9":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exit_from_my_life";
		break;

		case "Time_to_leave":
			PlaySound("VOICE\ENGLISH\Larry.wav");
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Time_to_leave2";
		break;

		case "Time_to_leave2":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Time_to_leave3";
		break;

		case "Time_to_leave3":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Time_to_leave4";
		break;

		case "Time_to_leave4":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_Time_to_leave";
		break;

		case "Father_on_IslaDemuerte":
		dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Father_on_IslaDemuerte2";
		break;

		case "Father_on_IslaDemuerte2":
		dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Father_on_IslaDemuerte3";
		break;

		case "Father_on_IslaDemuerte3":
		dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Father_on_IslaDemuerte4";
		break;

		case "Father_on_IslaDemuerte4":
		dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Father_on_IslaDemuerte5";
		break;

		case "Father_on_IslaDemuerte5":
		dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Father_on_IslaDemuerte6";
		break;

		case "Father_on_IslaDemuerte6":
		dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Father_on_IslaDemuerte7";
		break;

		case "Father_on_IslaDemuerte7":
		dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Exit_Father_on_IslaDemuerte";
		break;

		case "Piece of 8":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Piece of 8-2";
		break;

		case "Piece of 8-2":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Piece of 8-3";
		break;

		case "Piece of 8-3":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			AddDialogExitQuest("Teague_gives_Piece_of_8_1");
			pchar.Jack = "Pirate_Lord";
			PChar.quest.pirate_lord = "true";
		break;

		case "Exit_from_my_life":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Now_a_word_from_the_governor");
		break;

		case "Exit_Father_on_IslaDemuerte":
			DialogExit();
			NextDiag.CurrentNode = "First time"; //NextDiag.TempNode;
			AddDialogExitQuest("Put_the_coins_back");
		break;

		case "Exit_Time_to_leave":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("More_dialogue_from_Teague2");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}
