//#include "DIALOGS\Item Trader_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	if(!CheckAttribute(NPChar, "quest.item_date")) NPChar.quest.item_date = NPChar.quest.meeting;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "Items":
			// NK 05-03-26 fix this behavior. Now we give normally, and do not regive!; just add spyglass afterwards. -->
			if(CheckAttribute(Pchar, "quest.tutorial.Spyglass") && !CheckAttribute(NPChar,"items"))
			{
				GiveItemToTrader(NPChar);
				/*TakeNItems(Npchar,"blade1", Rand(4)+1);
				TakeNItems(Npchar,"blade2", Rand(4)+1);
				TakeNItems(Npchar,"blade3", Rand(4)+1);
				TakeNItems(Npchar,"blade4", Rand(4)+1);
				TakeNItems(Npchar,"blade5", Rand(4)+1);*/

				TakeNItems(Npchar,"spyglass2", 1);
				/*TakeNItems(Npchar,"potion1", Rand(10)+1);
				TakeNItems(Npchar,"potion2", Rand(3)+1);
				
				TakeNItems(Npchar,"jewelry1", Rand(4)+1);
				TakeNItems(Npchar,"jewelry2", Rand(4)+1);
				TakeNItems(Npchar,"jewelry4", Rand(4)+1);
				TakeNItems(Npchar,"indian4", Rand(4)+1);
				TakeNItems(Npchar,"indian13", Rand(4)+1);*/
				// NK <--
				
			//	DeleteAttribute(Pchar, "quest.tutorial.Spyglass");
			}
			else
			{
				if (!CheckAttribute(npchar, "quest.item_date") || npchar.quest.item_date != lastspeak_date)
				// PB: Prevent error
				{
					GiveItemToTrader(npchar);
					npchar.quest.item_date = lastspeak_date;
				}
			}
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();

			LaunchItemsTrade(NPChar);
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Items";						
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "exit";						

		break;
	}
}