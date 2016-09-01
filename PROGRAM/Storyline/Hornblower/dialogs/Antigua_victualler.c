// #include "DIALOGS\Enc_Tradepost.h"
void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	PChar.storekeeper.Idx = -1;//MAXIMUS
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	int iTest;
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	PChar = GetMainCharacter();
	PChar.storekeeper.Idx = -1;//MAXIMUS
	Npchar.nation = Characters[getCharacterIndex("St John's Commander")].nation;

//	int bribe = Makeint(GetCharacterShipHP(Pchar)*0.5);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(makeint(PChar.rank) <= 4)
			{
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1] + DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyShipNameShow(PChar) + DLG_TEXT[6];
			Link.l1.go = "questions";
			}
			if((makeint(PChar.rank) >= 5) && (makeint(PChar.rank) <=10))
			{
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1] + DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyShipNameShow(PChar) + DLG_TEXT[6];
			Link.l1.go = "questions";
			}
			if(makeint(PChar.rank) >= 11)
			{
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1] + DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyShipNameShow(PChar) + DLG_TEXT[6];
			Link.l1.go = "questions";
			}
		break;

		case "questions":
			d.Text = DLG_TEXT[7] + GetMyShipNameShow(PChar) + DLG_TEXT[8];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "market";
			Link.l2 = DLG_TEXT[10];
			Link.l2.go = "exit";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "market":
			dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[45];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			PChar.storekeeper.Idx = sti(NPChar.index);	//MAXIMUS
			LaunchStore(GetCurrentStore(NPChar.location));
		break;

		case "items":
			if (!CheckAttribute(npchar, "quest.item_date") || npchar.quest.item_date != lastspeak_date)
			// PB: Prevent error
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;
		case "exit_map":
			Diag.CurrentNode = "after_map";
			DialogExit();
			LaunchPelagoMap();
		break

		case "after_map":
			dialog.snd = "Voice\ALMI\ALMI012";
			dialog.text = XI_ConvertString("quest_talk")+" "+GetMyName(PChar)+"?";
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit_trade";
			link.l2 = XI_ConvertString("quest_map");
			link.l2.go = "exit_map";
			link.l3  = DLG_TEXT[61];
			link.l3.go = "exit";
		break;

		case "exit_trade":
			AddDialogExitQuest("trade_quest_open");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;


	}
}
