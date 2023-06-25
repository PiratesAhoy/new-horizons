void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar = GetMainCharacter();
	int iTest;
	
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
			Dialog.snd = "voice\REGR\REGR001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "talk_1";

			NextDiag.TempNode = "second time";
		break;

		case "talk_1":
			Dialog.snd = "voice\REGR\REGR002";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4] + GetMyShipNameShow(PChar) + DLG_TEXT[5];
			link.l1.go = "talk_2";
		break;

		case "talk_2":
			Dialog.snd = "voice\REGR\REGR003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[8];
			link.l2.go = "talk_3";
		break;

		case "talk_3":
			Dialog.snd = "voice\REGR\REGR004";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		case "second time":
			Dialog.snd = "voice\REGR\REGR005";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "quests";
			link.l5 = DLG_TEXT[13];
			link.l5.go = "exit";
		break;

		case "quests":
			itest = 0;
			Dialog.snd = "voice\REGR\REGR006";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[14];
			link.l99  = DLG_TEXT[19];
			link.l99.go = "exit";
			Preprocessor_Remove("addr"); // KK
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
