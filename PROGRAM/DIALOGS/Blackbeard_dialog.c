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
			Dialog.snd = "voice\THDI\THDI001";

			Dialog.mood = "angry";

			dialog.snd = "Voice\CLLA\CLLA001";
			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Exit":
			LAi_SetWarriorType(NPChar);
			LAi_group_MoveCharacter(NPChar, "DEVIL_BOSS");
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "DEVIL_BOSS", true);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}