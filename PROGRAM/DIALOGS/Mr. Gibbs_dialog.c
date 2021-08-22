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
	PChar.gibbs = 1;

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
			Dialog.snd = "voice\THDI\THDI001";

			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Node1";
		break;

		case "Node1":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Node2";
		break;

		case "Node2":
			GiveItem2Character(pchar,"aztec_compass");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Node3";
			link.l2 = DLG_TEXT[8];
			link.l2.go = "Exit";
		break;

		case "Node3":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit_hire";
		break;

		case "drinking":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Exit";
		break;

		case "Exit":
			DialogExit();
			NPChar.dialog.CurrentNode = "drinking";
		break;

		case "Exit_hire":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(NPChar.id);
			NPChar.quest.officerprice = "1000"; // PB
			AddDialogExitQuest("LandEnc_OfficerHired");
			NPChar.dialog.filename = "Enc_Officer_dialog.c";
			NPChar.dialog.CurrentNode = "hired";
			LAi_SetImmortal(NPChar, false);
		break;
	}
}
