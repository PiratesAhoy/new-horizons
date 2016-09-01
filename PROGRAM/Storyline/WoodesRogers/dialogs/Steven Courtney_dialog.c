//#include "DIALOGS\Steven Courtney_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	int iNation;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			Dialog.snd = "voice\PADI\PADI001";
			
			PlaySound("VOICE\ENGLISH\por_m_b_006.wav");

			if (pchar.location == "wr_chapel")
			{
				Dialog.text = DLG_TEXT[13];
				link.l1 = DLG_TEXT[14];
				link.l1.go = "exit";
			}
			else
			{
				if (pchar.location == "wr_animists")
				{
					Dialog.text = DLG_TEXT[15];
					link.l1 = DLG_TEXT[16];
					link.l1.go = "exit";
				}
			}
			else
			{
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			
			Diag.TempNode = "first time";
		break;

		case "sorry":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;
	
		case "lieutenant":
			PlaySound("VOICE\ENGLISH\por_m_b_006.wav");
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "lieutenant2";
		break;
	
		case "lieutenant2":
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			PlaySound("INTERFACE\notebook.wav");
		//	AddLandToCharacter(Pchar, "Jamaica", "England", 50);
		
			iNation = sti(NPChar.nation);
			NPChar.templand = GetCharacterLand(PChar);
			AddLandToCharacter(&Pchar, "Redmond", iNation, 50);

			Dialog.text = DLG_TEXT[9];

			DeleteAttribute(NPChar,"templand");

			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			AddDialogExitQuest("land_added");
		break;
		
		case "Courtney_Johnson":
			PlaySound("VOICE\ENGLISH\por_m_b_006.wav");
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			AddDialogExitQuest("no_comments");
		break;
	
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
