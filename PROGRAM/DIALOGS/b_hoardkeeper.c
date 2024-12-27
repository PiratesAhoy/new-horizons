// ccc Buildingset, new file

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
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			NextDiag.TempNode = "first time";
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "help_2";
			link.l4 = DLG_TEXT[4];
			link.l4.go = "help_3";
			link.l2 = DLG_TEXT[5];
			link.l2.go = "items";
			link.l3 = DLG_TEXT[6];
			link.l3.go = "items1";
		break;

		case "help_2":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "items";
		break;

		case "help_3":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "items";
		break;

		case "items":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Sneak", 100 ); }
			else { AddPartyExp(PChar, 100 ); }
			WaitDate("", 0, 0, 0, 2, 0);
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "items1";
		break;

		case "items1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LaunchCharacterItemChange(NPChar);

			ChangeCharacterAddress(NPChar, "none", "");
			Logit(TranslateString("","The Keeper disappears without word or sound, as if the ancient walls had swallowed him..."))
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterAddress(NPChar, "none", "");
			Logit(TranslateString("","The Keeper disappears without word or sound, as if the ancient walls had swallowed him..."))
		break;
	}
}