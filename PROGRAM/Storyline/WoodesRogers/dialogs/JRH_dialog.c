	
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
			Dialog.snd = "dialogs\0\009";
		break;

		case "drawing_room":
			PlaySound("VOICE\ENGLISH\jrh_1.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "crewC2");			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];  
			link.l1.go = "drawing_room1";
		break;

		case "drawing_room1":
			PlaySound("VOICE\ENGLISH\jrh_2.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "crewC2");			
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];  
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map29"); 
		break;

		case "red_house":
			PlaySound("VOICE\ENGLISH\jrh_1.wav");			
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];  
			link.l1.go = "exit";

			NextDiag.TempNode = "red_house";
		break;

		case "bonus_chapter":
			PlaySound("VOICE\ENGLISH\jrh_4.wav");			
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];  
			link.l1.go = "bonus_chapter1";
		break;

		case "bonus_chapter1":
			PlaySound("VOICE\ENGLISH\jrh_8.wav");			
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];  
			link.l1.go = "bonus_chapter2";
		break;

		case "bonus_chapter2":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Claire Voyant"));
			LAi_SetActorType(Pchar));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Defoe"));
			PlaySound("VOICE\ENGLISH\jrh_7.wav");			
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];  
			link.l1.go = "exit";
			AddDialogExitQuest("bonus_chapter4");
		break;
					
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
