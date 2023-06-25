//#include "DIALOGS\Redmond Soldier_dialog.h"
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
			Dialog.snd = "dialogs\0\009";

			int iPhrase = rand(10);
			
			switch (iPhrase)
			{
				case 0:
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				break;
				
				case 1:
					dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
				break;
				
				case 2:
					dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
				break;
				
				case 3:
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "exit";
				break;
				
				case 4:
					dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "exit";
				break;
				
				case 5:
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit";
				break;
				
				case 6:
					dialog.text = DLG_TEXT[12];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
				break;
				
				case 7:
					dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "exit";
				break;
				
				case 8:
					dialog.text = DLG_TEXT[16];
					link.l1 = DLG_TEXT[17];
					link.l1.go = "exit";
				break;
				
				case 9:
					dialog.text = DLG_TEXT[18];
					link.l1 = DLG_TEXT[19];
					link.l1.go = "exit";
				break;
				
				case 10:
					dialog.text = DLG_TEXT[20];
					link.l1 = DLG_TEXT[21];
					link.l1.go = "exit";
				break;
			}
		break;

		case "who_you_blaze":
			Dialog.defAni = "dialog_stay1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "who_you_blaze_2";
		break;

		case "who_you_blaze_2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "who_you_blaze_3";
		break;

		case "who_you_blaze_3":
			if(makeint(Environment.time) >= 22.0 || makeint(Environment.time) < 6.0)
			{
				dialog.text = DLG_TEXT[26];
				link.l1 = DLG_TEXT[27];
			}
			else
			{
				dialog.text = DLG_TEXT[28];
				link.l1 = DLG_TEXT[29];
			}
			link.l1.go = "exit";
			Diag.TempNode = "first time";			
			locations[FindLocation("Redmond_town_01")].reload.l6.disable = 0;
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
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "drink_2";
		break;

		case "drink_2":
			dialog.text = DLG_TEXT[32] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "drink_exit";
			link.l2 = DLG_TEXT[35];
			link.l2.go = "fight_exit";
			pchar.friend_in_tavern = "ENG_SOLDIERS";
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
		
		case "do_not_go":
			Diag.TempNode = "first time";
	
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";

			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "do_not_go_2";
		break;

		case "do_not_go_2":
			dialog.text = DLG_TEXT[38] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "do_not_go_3";
		break;

		case "do_not_go_3":
			if (GetOfficersQuantity(pchar) >0)
			{
				dialog.text = DLG_TEXT[41];
				link.l1 = DLG_TEXT[42];
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[43];
				link.l1 = DLG_TEXT[44];
				link.l1.go  = "do_not_go_4";
			}
			StorePassengers("Blaze");
		break;

		case "do_not_go_4":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
		break;

	}
}
