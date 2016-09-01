//#include "DIALOGS\Gregor Samsa_Dialog.h" //<-Change Here
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
	if(!CheckAttribute(NPChar, "quest.item_date")) NPChar.quest.item_date = NPChar.quest.meeting;

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

			int iPhrase = rand(8); // NK

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
					link.l2 = DLG_TEXT[13];
					link.l2.go = "exit";
				break;

				case 2:
					dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "mullet";
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
					dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "shop";
					link.l2 = DLG_TEXT[16];
					link.l2.go = "exit";
				break;
// NK -->
				//default:
					dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "shop";
					link.l2 = DLG_TEXT[16];
					link.l2.go = "exit";
// NK <--


			}
			Diag.TempNode = "first time";
		break;

		case "mullet":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[11];
			link.l2.go = "exit";
		break;

		case "shop":
			// NK -->
			string bladeid = NPChar.equip.blade;
			// NK itemtrade 05-04-09
			// TIH --> moved up here so its always set for this special character
				// TIH --> rpg_style change of behavior
				if ( IT_RPG_STYLE ) {
					NPChar.itemtrade.quality = 12; 					// TIH high quality items
					NPChar.itemtrade.tradetype = IT_TYPE_SNEAKY; 	// TIH properly set the trader type
				} else {
					NPChar.itemtrade.quality = 10;
					NPChar.itemtrade.tradetype = IT_TYPE_STORE;
				}
				// TIH <--
			// TIH <--
			if(!CheckAttribute(NPChar,"itemtrade") || GetCharacterItemTypes(&NPChar) < 2) // temp bugfix 05-06-28
			{
				//DeleteAttribute(&NPChar, "items");
				//DeleteAttribute(&NPChar, "itemtrade");
				DeleteAttribute(&NPChar,"items");
				GiveItemToTrader(&NPChar);
				GiveItem2Character(&NPChar, bladeid);
				GiveItem2Character(&NPChar, "spyglass4");// TIH by request of LDH
			}
			// NK <--
			if(DEBUG)
			{
				DeleteAttribute(&NPChar, "items");
				GiveItem2Character(&NPChar, bladeid);
				ref itm;
				int n = 0;
				for(n=0; n<ITEMS_QUANTITY; n++) //loop for all items. 05-07-25 set alwaysshowitems
				{
					makeref(itm, Items[n]);
					string iid = itm.id;
					if(checkattribute(itm,"skiptrade"))
					{ 
						if(sti(itm.skiptrade))
						{
							DeleteAttribute(&NPChar, "alwaysshowitems."+iid);
							continue;
						}
					}
					TakeNItems(NPChar, iid, 20);
					NPChar.alwaysshowitems.(iid) = true;
				}
			}
			// NK <--
			else
			{
				if (!CheckAttribute(npchar, "quest.item_date") || npchar.quest.item_date != lastspeak_date)
				// PB: Prevent error
				{
					GiveItemToTrader(&NPChar);
					npchar.quest.item_date = lastspeak_date;
				}
			}
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();

			LaunchItemsTrade(NPChar);
		break;
	}
}