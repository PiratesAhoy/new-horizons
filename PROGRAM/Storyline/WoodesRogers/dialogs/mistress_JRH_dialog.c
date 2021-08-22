//#include "DIALOGS\mistress_dialog.h"

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

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	

	switch(Dialog.CurrentNode)
	{
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

			PlaySound("VOICE\ENGLISH\gr_mistress.wav");
			dialog.text = DLG_TEXT[0] + NPChar.name + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "wench";
			link.l2 = DLG_TEXT[3];
			link.l2.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "about";

			Diag.TempNode = "first time";
		break;

		case "about":
			Dialog.Text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "wench";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "exit";
		break;

//JRH new block -->
		case "wench":
			Dialog.Text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "wench_night_&_day";
		break;

		case "wench_night_&_day":
			Dialog.text = DLG_TEXT[11];//talking cost
			if (makeint(pchar.money) >= 50)
			{
				link.l1 = DLG_TEXT[12];//agreeing
				AddMoneyToCharacter(pchar, -50);

				if(CheckAttribute(Pchar,"quest.wr_quest1") && Pchar.quest.wr_quest1 == "on")
				{
					link.l1.go = "choose_girl_quest";
				}
				else
				{
					link.l1.go = "choose_girl_no_quest";
				}
			}
			link.l2 = DLG_TEXT[13];//too much
			link.l2.go = "exit";
		break;

		case "choose_girl_quest":
 			PlayStereoSound("INTERFACE\took_item.wav");						
			Dialog.Text = DLG_TEXT[17];		//JRH substitute
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Natalia";
			link.l2 = DLG_TEXT[19];
			link.l2.go = "Celia";
			link.l3 = DLG_TEXT[20];
			link.l3.go = "Serena";
			link.l4 = DLG_TEXT[21];
			link.l4.go = "Caroline_K";
		break;

		case "choose_girl_no_quest":
			PlayStereoSound("INTERFACE\took_item.wav");  								
			Dialog.Text = DLG_TEXT[22];		
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Natalia";
			link.l2 = DLG_TEXT[19];
			link.l2.go = "Celia";
			link.l3 = DLG_TEXT[20];
			link.l3.go = "Serena";
		break;

		case "Natalia":
			ChangeCharacterReputation(pchar, -5);
			DialogExit();
			DoQuestReloadToLocation(pchar.location + "_upstairs", "goto", "goto2", "restore_hp");
			AddDialogExitQuest("Natalia");
		break;

		case "Serena":
			ChangeCharacterReputation(pchar, -5);
			DialogExit();
			AddDialogExitQuest("Serena");
			DoQuestReloadToLocation(pchar.location + "_upstairs", "goto", "goto3", "restore_hp");
		break;

		case "Celia":
			ChangeCharacterReputation(pchar, -5);
			DialogExit();
			AddDialogExitQuest("Celia");
			DoQuestReloadToLocation(pchar.location + "_upstairs", "goto", "goto4", "restore_hp");
		break;

		case "Caroline_K":
			ChangeCharacterReputation(pchar, 10);
			DialogExit();
			AddDialogExitQuest("Caroline_K");
			DoQuestReloadToLocation(pchar.location + "_upstairs", "goto", "goto5", "restore_hp");
		break;
// <-- JRH new block

		case "exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;//this is why the first thing is said
		break;


	}
}