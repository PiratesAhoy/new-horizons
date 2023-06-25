//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDialog;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDialog, NPChar.Dialog);

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
			Dialog.snd = "dialogs\0\009";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "First_meet_Thomas_the_Terror":
			PlaySound("VOICE\ENGLISH\Eng_m_c_054.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Chatter_on_Thomas2";
		break;

		case "Chatter_on_Thomas2":
			dialog.text = DLG_TEXT[4] + Pchar.lastname + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6] + GetMyFullName(PChar) + DLG_TEXT[7];
			link.l1.go = "Chatter_on_Thomas3";
		break;		

		case "Chatter_on_Thomas3":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Chatter_on_Thomas4";
		break;
		
		case "Chatter_on_Thomas4":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Chatter_on_Thomas5";
		break;

		case "Chatter_on_Thomas5":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Chatter_on_Thomas6";
		break;

		case "Chatter_on_Thomas6":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Chatter_on_Thomas7";
		break;		

		case "Chatter_on_Thomas7":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Chatter_on_Thomas8";
		break;

		case "Chatter_on_Thomas8":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Chatter_on_Thomas9";
		break;

		case "Chatter_on_Thomas9":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Chatter_on_Thomas10";
		break;

		case "Chatter_on_Thomas10":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Chatter_on_Thomas11";
		break;

		case "Chatter_on_Thomas11":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Chatter_on_Thomas12";
		break;

		case "Chatter_on_Thomas12":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Chatter_on_Thomas13";
		break;

		case "Chatter_on_Thomas13":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Chatter_on_Thomas14";
		break;

		case "Chatter_on_Thomas14":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Chatter_on_Thomas15";
		break;

		case "Chatter_on_Thomas15":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_Chatter_on_Thomas";
		break;

		case "Muelle_meet_Thomas_the_Terror":
			PlaySound("VOICE\ENGLISH\Eng_m_c_054.wav");
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Muelle_meet_Thomas_the_Terror2";
		break;

		case "Muelle_meet_Thomas_the_Terror2":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Muelle_meet_Thomas_the_Terror3";
		break;

		case "Muelle_meet_Thomas_the_Terror3":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Muelle_meet_Thomas_the_Terror4";
		break;

		case "Muelle_meet_Thomas_the_Terror4":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Muelle_meet_Thomas_the_Terror5";
			link.l2 = DLG_TEXT[46];
			link.l2.go = "Muelle_meet_Thomas_the_Terror_Quest";
		break;

		case "Muelle_meet_Thomas_the_Terror5":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_Muelle_meet_Thomas";
		break;

		case "Exit_Muelle_meet_Thomas":
			AddQuestRecord("Beckett",17);
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Ransom_for_Prisoner");
		break;

		case "Muelle_meet_Thomas_the_Terror_Quest":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_Muelle_meet_Thomas_Quest";
		break;

		case "Muelle_begin_search":
			PlaySound("VOICE\ENGLISH\Eng_m_c_054.wav");
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Muelle_begin_search2";
		break;

		case "Muelle_begin_search2":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "Exit_Muelle_begin_search";
		break;

		case "Muelle_back_for_ship":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Exit_back_for_ship";
		break;

		case "Oyster_Bay_for_officer":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Exit_Bay_for_officer";
		break;

		case "Exit_Bay_for_officer":
//			AddQuestRecord("Beckett",18);
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Collect_the_officer");
		break;

		case "Exit_back_for_ship":
//			AddQuestRecord("Beckett",18);
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Return_Muelle_for_ship");
		break;

		case "Exit_Muelle_begin_search":
//			AddQuestRecord("Beckett",18);
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Search_with_Thomas_in_jungle");
		break;

		case "Exit_Muelle_meet_Thomas_Quest":
			AddQuestRecord("Beckett",18);
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Search_with_Thomas_for_Prisoner");
		break;

		case "Exit_Chatter_on_Thomas":
			AddQuestRecord("My Early Days",12);
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Sailing for Oxbay with Thomas");
		break;

		case "Goodbye_at_Oxbay":
			PlaySound("VOICE\ENGLISH\Eng_m_c_054.wav");
			dialog.text = DLG_TEXT[34] + Pchar.name + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Goodbye_at_Oxbay2";
		break;

		case "Goodbye_at_Oxbay2":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_Goodbye_to_Thomas";
		break;

		case "Exit_Goodbye_to_Thomas":
			AddQuestRecord("My Early Days",13);
			GiveItem2Character(Pchar,"compass2");
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Thomas leaves at Oxbay");
		break;

		case "Exit": 
			Dialog.CurrentNode = Dialog.TempNode;
			DialogExit();
		break;

	
			}
}
