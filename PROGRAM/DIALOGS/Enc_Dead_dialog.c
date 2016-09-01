//#include "DIALOGS\Enc_Dead_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, Item;	
	int money;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit_fight":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_RunFight":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "Node_1":
			if(NPChar.quest.meeting == "1")
			{
				d.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "exit";
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[2], DLG_TEXT[3], DLG_TEXT[4], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "Search";
				Link.l2 = DLG_TEXT[6];
				Link.l2.go = "Exit";
			}
			
		break;

		case "Search":
			money = getDeadManMoney();
			item = returnRandomDeadItem();
			GiveItem2Character(Pchar, item);
			d.Text = DLG_TEXT[7] + money + DLG_TEXT[8] + item + DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "exit";			
		break;



	}
}