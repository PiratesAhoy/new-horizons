
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

			PlaySound("VOICE\ENGLISH\Herrick1.wav");
			LAi_SetActorType(characterFromID("Herrick"));
			LAi_ActorTurnToCharacter(characterFromID("Herrick"), characterFromID("Bolitho"));
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("byebye_Bolitho");
		break;

		case "leave_hold":
			PlaySound("VOICE\ENGLISH\Herrick2.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
			AddDialogExitQuest("leave_manowar_hold");
		break;

		case "escort":
			PlaySound("VOICE\ENGLISH\Herrick1.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "escort1";

		//	link.l1.go = "Exit_repeat";
		//	NextDiag.CurrentNode = "escort";
		break;

		case "escort1":
			PlaySound("VOICE\ENGLISH\Herrick2.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit_repeat";
			NextDiag.CurrentNode = "escort";
		break;

		case "escort_leaves":
			PlaySound("VOICE\ENGLISH\Herrick2.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "escort_leaves1";
		break;

		case "escort_leaves1":
			PlaySound("VOICE\ENGLISH\Herrick1.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("Escort_returns_to_ship");
		break;

		case "Exit_repeat":
			DialogExit();

			if(Pchar.location == "Manowar_hold")
			{
				LAi_SetStayType(characterFromID("Herrick"));
			}
			else
			{	
				LAi_SetOfficerType(characterFromID("Herrick"));
			}
			NextDiag.CurrentNode = "escort";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;
	}
}
