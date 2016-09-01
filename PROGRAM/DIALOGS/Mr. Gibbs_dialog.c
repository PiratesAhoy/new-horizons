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

			dialog.text = "How're you doing, captain?";
			link.l1 = "Fine, thank you. Is there anything I can do for you?";
			link.l1.go = "Node1";
		break;

		case "Node1":
			dialog.text = "Perhaps. But there IS something I can do for you. Here. Take this. Perhaps you can find some use for it.";
			link.l1 = "Thanks. Now what could I do for you?";
			link.l1.go = "Node2";
		break;

		case "Node2":
			GiveItem2Character(pchar,"aztec_compass");
			dialog.text = "I have been without a ship for too long. Would you please allow me to be your boatswain?";
			link.l1 = "Yes, please. But you'd better be good.";
			link.l1.go = "Node3";
			link.l2 = "No, thanks.";
			link.l2.go = "Exit";
		break;

		case "Node3":
			dialog.text = "Don't worry about that. I'm just about as experienced as you are.";
			link.l1 = "That sounds quite good. I'm looking forward to seeing you in action.";
			link.l1.go = "Exit_hire";
		break;

		case "drinking":
			dialog.text = "Take what you can!";
			link.l1 = "Give nothing back!";
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
