void ProcessDialogEvent()
{
	ref NPChar;
	ref PChar = GetMainCharacter();
	aref Link, NextDiag;
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

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
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
			if (!CheckCharacterItem(PChar, "EITC_Passport") && !CheckCharacterItem(PChar, "Trade_Passport"))
			{
				Link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3];
				Link.l1.go = "node_1";
			}
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "exit";
			npchar.quest.meeting = "1";
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "node_2";
			link.l2 = DLG_TEXT[11];
			link.l2.go = "exit";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "node_3";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "exit";
		break;

		case "node_3":
			dialog.text = DLG_TEXT[9];
			if (GetCharacterMoney(PChar) >= 1000000)
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "node_4";
			}
			link.l2 = DLG_TEXT[13];
			link.l2.go = "exit";
		break;

		case "node_4":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddMoneyToCharacter(PChar, -1000000);
			GiveItem2Character(PChar, "Trade_Passport");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
