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
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			//Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			//Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			//Dialog.snd = "voice\TOOR\TOOR001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";

			if (!GetAttribute(characterFromID("Sumbhajee Aid1"), "quest.sumbhajee"))
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "sum2";
			}
			break;

		case "sum2":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "exit";
			characters[getcharacterindex("Sumbhajee Aid1")].quest.Sumbhajee = "";
			AddDialogExitQuest("talkforSumbhajee");
		break;	

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
