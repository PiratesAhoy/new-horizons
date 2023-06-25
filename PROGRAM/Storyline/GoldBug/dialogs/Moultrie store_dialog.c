//#include "DIALOGS\Peter Blowhorn_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	ref PChar;
	PChar = GetMainCharacter();
	if(!CheckAttribute(NPChar, "quest.item_date")) NPChar.quest.item_date = NPChar.quest.meeting;

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";			
		
			Dialog.snd = "voice\PEBL\PEBL001";
			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + npchar.name + " " + npchar.lastname + DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			link.l1.go = "node_1";
		
			NextDiag.TempNode = "Second time";	
		break;
	
		case "second time":
			Dialog.snd = pcharrepphrase("voice\PEBL\PEBL002", "voice\PEBL\PEBL003");
			dialog.text = pcharrepphrase(DLG_TEXT[5] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[6], DLG_TEXT[7]);
			Link.l1 = pcharrepphrase(DLG_TEXT[8] + npchar.name + DLG_TEXT[9], DLG_TEXT[10]); 
			link.l1.go = "node_1";
		break;

		case "node_1":
			Dialog.snd = "voice\PEBL\PEBL004";
			dialog.text = DLG_TEXT[11];

			if(CheckAttribute(Pchar,"quest.Jupiter_cognac_sold") && Pchar.quest.Jupiter_cognac_sold == "no")
			{
				link.l1 = DLG_TEXT[107];
				link.l1.go = "papers";
			}
			link.l2 = DLG_TEXT[12];
			link.l2.go = "trade";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "exit";
		break;

		case "trade":
			Dialog.snd = "voice\PEBL\PEBL005";
			dialog.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[17];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[18];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStore(PIRATES_STORE);
		break;

		case "items":
			if (!CheckAttribute(npchar, "quest.item_date") || npchar.quest.item_date != lastspeak_date)
			// PB: Prevent error
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;
	
		case "papers":
			dialog.text = DLG_TEXT[108];
			if(CheckCharacterItem(Pchar,"bladefish"))
			{
				if(!IsEquipCharacterByItem(Pchar, "bladefish"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladefish");
				}

				link.l1 = DLG_TEXT[105];
				link.l1.go = "fish";
			}
			else
			{
				if(CheckCharacterItem(Pchar,"bladebottle_CB2"))
				{
					if(!IsEquipCharacterByItem(Pchar, "bladebottle_CB2"))
					{
						RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
						EquipCharacterByItem(Pchar, "bladebottle_CB2");
					}

					link.l1 = DLG_TEXT[109];
					link.l1.go = "cognac";
				}
			}
			else
			{
				link.l1 = DLG_TEXT[14];
				link.l1.go = "exit";
			}
		break;

		case "fish":
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("liquor_info");
		break;

		case "cognac":
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "cognac2";
		break;

		case "cognac2":
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("cognac_sold");
		break;

		case "stop":
			PlaySound("OBJECTS\DUEL\man_attack5.wav");
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			AddDialogExitQuest("step_back_store");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}
