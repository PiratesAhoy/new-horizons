
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			Dialog.snd = "voice\PADI\PADI001";
		break;

		ChangeCharacterAddressGroup(Pchar, "BB_Hornigold_shore", "goto", "bb4");
	
		case "La_Concorde":
			LAi_ActorTurnToCharacter(characterFromID("Hornigold"), characterFromID("Teach"));

			PlaySound("VOICE\ENGLISH\gr_Hgold1.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore3");
		break;
	
		case "talk_business":
			LAi_ActorTurnToCharacter(characterFromID("Hornigold"), characterFromID("Teach"));

			PlaySound("VOICE\ENGLISH\gr_Hgold2.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore5");
		break;

		case "getting_mad":
			LAi_ActorTurnToCharacter(characterFromID("Hornigold"), characterFromID("Teach"));

			PlaySound("VOICE\ENGLISH\gr_Hgold3.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore7");
		break;

		case "wow_a_map":
			LAi_ActorTurnToCharacter(characterFromID("Hornigold"), characterFromID("Teach"));

			PlaySound("VOICE\ENGLISH\gr_Hgold4.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore9");
		break;

		case "gives_pistol":
			LAi_ActorTurnToCharacter(characterFromID("Hornigold"), characterFromID("Teach"));

			PlaySound("VOICE\ENGLISH\gr_Hgold6.wav");	//5 'goodbye' later
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore11");
		break;
		
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
