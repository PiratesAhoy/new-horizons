//#include "DIALOGS\barwench_dialog.h"

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

			int iPhrase = rand(3);

			switch (iPhrase)
			{
				case 0:
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "shop";
					link.l2 = DLG_TEXT[2];
					link.l2.go = "exit";
				break;

				case 1:
					dialog.text = DLG_TEXT[3];
					link.l1 = DLG_TEXT[4];
					link.l1.go = "shop";
					link.l2 = DLG_TEXT[5];
					link.l2.go = "exit";
				break;

				case 2:
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "shop";
					link.l2 = DLG_TEXT[8];
					link.l2.go = "exit";
				break;

				case 3:
					dialog.text = DLG_TEXT[9];
					link.l1 = DLG_TEXT[10];
					link.l1.go = "shop";
					link.l2 = DLG_TEXT[11];
					link.l2.go = "exit";
				break;

			}
			Diag.TempNode = "first time";
		break;

// ccc jan 06, reenabled buying process which was messed up by new tradingfunctions

/* this would open the usual itemtrading interface...

		case "shop":
			NPChar.itemtrade.quality = 1;	// ccc jan 06
			NPChar.itemtrade.tradetype = IT_TYPE_STALL;	// ccc jan 06
			GiveItemToTrader(npchar);	// ccc jan 06

			TakeNItems(Npchar,"potionrum", Rand(10)+1);
			TakeNItems(Npchar,"potionwine", Rand(3)+1);

			Diag.CurrentNode = Diag.TempNode;
			DialogExit();

			LaunchItemsTrade(NPChar);
		break;

...but that's not what verruckt wanted. Instead only rum and wine (created by verruckt) shall be sold:
*/


		case "shop":
			dialog.text = DLG_TEXT[12];

			if(sti(pchar.money)>1000)
			{
			link.l1 = DLG_TEXT[13];
			link.l1.go = "rum";
			link.l2 = DLG_TEXT[14];
			link.l2.go = "wine";
			}

			link.l3 = RandSwear() + DLG_TEXT[15];
			link.l3.go = "exit";

		break;

		case "rum":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -1000);
			GiveItem2Character(PChar, "potionrum");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "wine":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -1000);
			GiveItem2Character(PChar, "potionwine");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

	}
}