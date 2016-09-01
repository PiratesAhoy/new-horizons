
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

			PlaySound("VOICE\ENGLISH\Clayton01.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Start_at_Charlestown":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Start_at_Charlestown";
		break;

		case "Charlestown_fight":
		dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[8] + GetMyName(PChar) + DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit_Charlestown_fight";
		break;

		case "Clayton_on_the_beach":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Clayton_on_the_beach2";
		break;

		case "Clayton_on_the_beach2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit_Clayton_on_the_beach";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_Start_at_Charlestown":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Archie_chips_in");
		break;

		case "Exit_Charlestown_fight":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Simpson_gone_for_now");
		break;

		case "ExitWhichPort":
			AddDialogExitQuest("Make_sail_for_Greenford");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Clayton_on_the_beach":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("The Lieutenant Arrives Back");
		break;
	}
}
