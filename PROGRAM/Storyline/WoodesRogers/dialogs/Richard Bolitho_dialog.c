
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
			dialog.snd = "Voice\ARGU\ARGU001";

			PlaySound("VOICE\ENGLISH\Bolitho1.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "continue";
		break;

		case "continue":
			PlaySound("VOICE\ENGLISH\Bolitho2.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "continue1";
		break;

		case "continue1":
			PlaySound("VOICE\ENGLISH\Bolitho3.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("meet_Herrick");
		break;

		case "byebye":
			LAi_SetActorType(characterFromID("Bolitho"));
			LAi_ActorTurnToCharacter(characterFromID("Bolitho"), characterFromID("Herrick"));
			PlaySound("VOICE\ENGLISH\Bolitho4.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Bolitho_leaves");
		break;

			


		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;
	}
}
