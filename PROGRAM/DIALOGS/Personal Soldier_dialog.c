void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	Dialog.defAni = "dialog_stay1";
	Dialog.defCam = "1";
	Dialog.defSnd = "dialogs\0\017";
	Dialog.defLinkAni = "dialog_1";
	Dialog.defLinkCam = "1";
	Dialog.defLinkSnd = "dialogs\woman\024";
	Dialog.ani = "dialog_stay2";
	Dialog.cam = "1";
	Dialog.snd = "dialogs\0\009";

	int iPhrase = rand(0);
	
	switch (iPhrase)
	{
		case 0:
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;
	}

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
