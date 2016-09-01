
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

		case "separate_way":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach1.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore3_A");
		break;
	
		case "keep_the_ship":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore6");
		break;

		case "gives_map":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach3.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore7_B");
		break;

		case "give_me_your_pistol":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore10");
		break;

		case "officers_over_here":
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("Hornigold"));

			PlaySound("VOICE\ENGLISH\gr_Teach2.wav");	//5 'ahh there you are' later
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("Hornigold_shore17");
		break;











	
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
