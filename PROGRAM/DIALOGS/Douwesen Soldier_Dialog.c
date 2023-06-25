//#include "DIALOGS\Douwesen Soldier_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
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
			NPChar.greeting = "";

			int iPhrase = rand(10);
			
			switch (iPhrase)
			{
				case 0:
					Diag.TempNode = "node_2";
					NPChar.greeting = "Gr_Douwesen_soldiers_03";
					Change_Mood("angry");
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				break;

				case 1:
					Diag.TempNode = "node_3";
					NPChar.greeting = "Gr_Douwesen_soldiers_01";
					Change_Mood("normal");
					dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
				break;

				case 2:
					Diag.TempNode = "node_4";
					NPChar.greeting = "Gr_Douwesen_soldiers_05";
					Change_Mood("normal");
					dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
				break;

				case 3:
					Diag.TempNode = "node_5";
					NPChar.greeting = "Gr_Douwesen_soldiers_04";
					Change_Mood("afraid");
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "exit";
				break;

				case 4:
					Diag.TempNode = "node_2";
					NPChar.greeting = "Gr_Douwesen_soldiers_03";
					Change_Mood("angry");
					dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "exit";
				break;

				case 5:
					Diag.TempNode = "node_7";
					NPChar.greeting = "Gr_Douwesen_soldiers_02";
					Change_Mood("smile");
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit";
				break;

				case 6:
					Diag.TempNode = "node_2";
					NPChar.greeting = "Gr_Douwesen_soldiers_03";
					Change_Mood("angry");
					dialog.text = DLG_TEXT[12];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
				break;

				case 7:
					Diag.TempNode = "node_2";
					NPChar.greeting = "Gr_Douwesen_soldiers_02";
					Change_Mood("smile");
					dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "exit";
				break;

				case 8:
					Diag.TempNode = "node_2";
					NPChar.greeting = "Gr_Douwesen_soldiers_03";
					Change_Mood("angry");
					dialog.text = DLG_TEXT[16];
					link.l1 = DLG_TEXT[17];
					link.l1.go = "exit";
				break;

				case 9:
					Diag.TempNode = "node_8";
					NPChar.greeting = "Gr_Douwesen_soldiers_01";
					Change_Mood("normal");
					dialog.text = DLG_TEXT[18];
					link.l1 = DLG_TEXT[19];
					link.l1.go = "exit";
				break;

				case 10:
					Diag.TempNode = "node_6";
					NPChar.greeting = "Gr_Douwesen_soldiers_04";
					Change_Mood("afraid");
					dialog.text = DLG_TEXT[20];
					link.l1 = DLG_TEXT[21];
					link.l1.go = "exit";
				break;
			}
		break;


		case "drink":
			Diag.TempNode = "first time";
	
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";

			Change_Mood("angry");
			dialog.snd = "Voice\DOSO\DOSO044";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "drink_2";
		break;

		case "drink_2":
			Change_Mood("smile");
			dialog.snd = "Voice\DOSO\DOSO045";
			dialog.greeting = "VOICE\" + LanguageGetLanguage() + "\Dut_m_a_047.wav";
			dialog.text = DLG_TEXT[23] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "drink_exit";
			link.l2 = DLG_TEXT[26];
			link.l2.go = "fight_exit";
		break;

		case "drink_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			npchar.location = "none";
		break;

		case "fight_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("fight_with_soldier_for_drink");
		break;

		case "node_2":
			Diag.TempNode = "node_2";
			NPChar.greeting = "Gr_Douwesen_soldiers_03";
			Change_Mood("angry");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
		break;

		case "node_3":
			Diag.TempNode = "node_2";
			NPChar.greeting = "Gr_Douwesen_soldiers_03";
			Change_Mood("angry");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "node_4":
			Diag.TempNode = "node_3";
			NPChar.greeting = "Gr_Douwesen_soldiers_01";
			Change_Mood("normal");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
		break;

		case "node_5":
			Diag.TempNode = "node_6";
			NPChar.greeting = "Gr_Douwesen_soldiers_04";
			Change_Mood("afraid");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
		break;

		case "node_6":
			Diag.TempNode = "node_5";
			NPChar.greeting = "Gr_Douwesen_soldiers_04";
			Change_Mood("afraid");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
		break;

		case "node_7":
			Diag.TempNode = "node_4";
			NPChar.greeting = "Gr_Douwesen_soldiers_05";
			Change_Mood("normal");
			if(rand(3) > 1)
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
			}
		break;

		case "node_8":
			Diag.TempNode = "node_7";
			NPChar.greeting = "Gr_Douwesen_soldiers_01";
			Change_Mood("normal");
			if(rand(3) > 1)
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "exit";
			}
		break;
	}
}
