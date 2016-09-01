//#include "DIALOGS\Inquisitor_dialog.h"
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

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "start":
			dialog.text = DLG_TEXT[0];			
			link.l1 = DLG_TEXT[1];
			link.l1.go = "unexpected1";
		break;

		case "unexpected1":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "charles";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "helen";
		break;

		case "charles":
			SetModelfromArray(PChar, GetModelIndex("Ardent"));
			PChar.sex = "man";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "adventure";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "gold";
		break;

		case "helen":
			GiveModel2Player("Ardent_F", true);
			PChar.sex = "woman";
			PChar.old.name = "Helen";
			PChar.name = TranslateString("","Helen");
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "adventure";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "gold";
		break;

		case "adventure":
			PChar.quest.alignment = "good";
			ChangeCharacterReputation(pchar, 5);
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "pirate";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "personal";
		break;

		case "gold":
			PChar.quest.alignment = "evil";
			ChangeCharacterReputation(pchar, -5);
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "pirate";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "personal";
		break;

		case "pirate":
			SetServedNation(PIRATE);
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "personal":
			SetServedNation(PERSONAL_NATION);
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

	}
}