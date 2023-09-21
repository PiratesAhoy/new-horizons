//#include "DIALOGS\tavern fightingman_dialog.h"

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
			Dialog.snd = "voice\TAFI\TAFI001";
			
			// TIH bugfix can only have three vars in the LinkRandPhase function Jul11'06
			int randPick = rand(1);
			switch (randPick)
			{
				case 0:
					dialog.text = LinkRandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2]);
					break;
				case 1:
					dialog.text = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
					break;
			}
			// TIH <--
			Link.l1 = DLG_TEXT[9]; 
			Link.l1.go = "Buy";
			Link.l2 = LinkRandPhrase(DLG_TEXT[6], DLG_TEXT[7], DLG_TEXT[8]); 
			Link.l2.go = "Exit";
			
			NextDiag.TempNode = "first time";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Buy":
			NPChar.opiumprice = GetOpiumPrice();
			dialog.text = DLG_TEXT[10]+NPChar.opiumprice+ DLG_TEXT[11]; 
			Link.l1 = DLG_TEXT[15]
			Link.l1.go = "Exit";
			if(pchar.money > (sti(NPChar.opiumprice)*1))
			{
				Link.l2 = DLG_TEXT[12]
				Link.l2.go = "Buy1";
			}
			if(pchar.money > (sti(NPChar.opiumprice)*12))
			{
				Link.l3 = DLG_TEXT[13]
				Link.l3.go = "Buy12";
			}
			if(pchar.money > (sti(NPChar.opiumprice)*72))
			{
				Link.l4 = DLG_TEXT[14]
				Link.l4.go = "Buy72";
			}
		break;

		case "Buy1":
			TakeNItems(PChar, "opium", 1);
			AddDialogExitQuest("Opium_set_first_ambush");
			AddMoneyToCharacter(PChar, -1*sti(NPChar.opiumprice)*1);
			PlayStereoSound("INTERFACE\took_item.flac");
			dialog.text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17]
			Link.l1.go = "Exit";
		break;

		case "Buy12":
			TakeNItems(PChar, "opium", 12);
			AddDialogExitQuest("Opium_set_first_ambush");
			AddMoneyToCharacter(PChar, -1*sti(NPChar.opiumprice)*12);
			PlayStereoSound("INTERFACE\took_item.flac");
			dialog.text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17]
			Link.l1.go = "Exit";
		break;

		case "Buy72":
			TakeNItems(PChar, "opium", 72);
			AddDialogExitQuest("Opium_set_first_ambush");
			AddMoneyToCharacter(PChar, -1*sti(NPChar.opiumprice)*72);
			PlayStereoSound("INTERFACE\took_item.flac");
			dialog.text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17]
			Link.l1.go = "Exit";
		break;
	}
}
