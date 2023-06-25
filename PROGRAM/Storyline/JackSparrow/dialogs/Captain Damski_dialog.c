//#include "DIALOGS\Captain Damski_dialog.h"
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

			Dialog.mood = "normal";

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

		break;
		
		case "First_meet_in_Church":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];			
			link.l1.go = "First_meet_in_Church2";
		break;	

		case "First_meet_in_Church2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];			
			link.l1.go = "First_meet_in_Church3";
		break;
		
		case "First_meet_in_Church3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + GetMyFullName(Pchar) + DLG_TEXT[8];			
			link.l1.go = "First_meet_in_Church4";
		break;

		case "First_meet_in_Church4":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];			
			link.l1.go = "First_meet_in_Church5";
		break;
		
		case "First_meet_in_Church5":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];			
			link.l1.go = "First_meet_in_Church6";
		break;		

		case "First_meet_in_Church6":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];			
			link.l1.go = "Exit_First_meet_in_Church";
		break;		
		
		case "Exit_First_meet_in_Church":			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Moving_along_In_search_for_Nathan_Kell");
		break;

		case "meet_in_Apothecary":
			dialog.text = DLG_TEXT[15] + getmyname(Pchar) + DLG_TEXT[16] + getmyname(Pchar) + DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];			
			link.l1.go = "Exit_meet_in_Apothecary";
		break;		

		case "meet_in_Turks":
			if (GetAttribute(pchar, "Turks") == "Drow");
			{
				dialog.text = DLG_TEXT[28];
			}
			else
			{
				dialog.text = DLG_TEXT[19];
			}
			link.l1 = DLG_TEXT[20];
			link.l1.go = "meet_in_Turks2";
		break;

		case "meet_in_Turks2":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "meet_in_Turks3";
		break;

		case "meet_in_Turks3":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit_meet_in_Turks";
		break;

		case "Exit_meet_in_Apothecary":			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Now_make_other_plans");
		break;

		case "Exit_meet_in_Turks":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Back_to_Lighthouse_from_Turks");
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar, "WickedWench", "Wicked Wench",-1,ENGLAND,true,true);
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}
