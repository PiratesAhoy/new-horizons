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
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			addDialogExitQuest("back_to_the_port");
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			if (pchar.location == "Gamboa_ship")
			{
				Dialog.snd = "voice\TAOR\TAOR001";
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "what_about";
			}

		break;

		case "what_about":
			Dialog.snd = "voice\TAOR\TAOR002";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			if (characters[getcharacterindex("Sumbhajee Aid1")].quest.Sumbhajee == "bad_complete")
			{
				characters[getcharacterindex("Sumbhajee Aid1")].quest.Sumbhajee = "bad_2_complete";
			}
			else
			{
				characters[getcharacterindex("Sumbhajee Aid1")].quest.Sumbhajee = "good_2_complete";
			}
		break;

	}
}