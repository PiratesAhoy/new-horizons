// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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

	Diag.TempNode = "first time";
	
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

// KK -->
			if (CheckAttribute(lcn, "abbey") == true && sti(lcn.abbey) == true) {		
				Dialog.text = LinkRandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2]);
				link.l1 = DLG_TEXT[3];
				link.l1.go = "maltese1";
			} else {
				Dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
			}
// <-- KK
		break;

		case "maltese1":
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "";
			link.l2 = DLG_TEXT[8];
			link.l2.go = "";
		break;

		case "":
			Dialog.text = LinkRandPhrase(DLG_TEXT[4], DLG_TEXT[4], DLG_TEXT[4]);
			link.l1 = DLG_TEXT[8];
			link.l1.go = "";
		break;

		case "fight":
			Dialog.text = LinkRandPhrase(DLG_TEXT[4], DLG_TEXT[4], DLG_TEXT[4]);
			link.l1 = RandSwear() + " " + DLG_TEXT[9];
			link.l1.go = "exit_fight";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_fight":
		// PB: To prevent the fight from starting before the dialog is closed
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_039.wav");
			LAi_group_SetRelation(NPchar.chr_ai.group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			int hp = sti(PChar.rank)*10 + rand(100) + 50;
			LAi_SetHP(NPchar, hp, hp);	// for more variation and challenge

			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
