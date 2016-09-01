//#include "DIALOGS\quest_sailor_tmp.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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

			if( CheckQuestAttribute("CaptureFrenchOfficer","TakeToShip") )
			{
				dialog.text = GetMyFullName(PChar) + DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "take_HardouinBeauvallet_exit";
			}
			if (checkattribute(Pchar, "quest.Story_DominguesCompromat") && pchar.quest.Story_DominguesCompromat == "after_speak")
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}
		break;

		case "MissingBoatswain":
			dialog.text = DLG_TEXT[4] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "MissingBoatswain_1";			
		break;

		case "MissingBoatswain_1":
			dialog.text = DLG_TEXT[7] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[8])]) + DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "MissingBoatswain_2";			
		break;

		case "MissingBoatswain_2":
			AddDialogExitQuest("Fem_RemoveSailorFromRedmondPort");
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Exit";			
		break;

		case "ApplinDying":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "ApplinDying_1";			
		break;

		case "ApplinDying_1":
			AddDialogExitQuest("Fem_SailorLeavesCaptainsCabin");
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Exit";			
		break;


		case "take_HardouinBeauvallet_exit":
			DialogExit();
			ChangeCharacterAddress(NPChar, "none", "");
			WaitDate( "return_capture_HardouinBeauvallet", 0,0,0, 1,0 );
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
