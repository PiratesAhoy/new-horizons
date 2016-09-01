//#include "DIALOGS\ralph fawn_dialog.h"
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
			Dialog.snd = "voice\RAFA\RAFA001";
			
			dialog.text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "exit";
			trace ("pchar.quest.main_line >> " + pchar.quest.main_line);

			if ((pchar.quest.main_line == "talk_in_tavern_begin")&&(pchar.id == "Blaze"))
			{
				Dialog.snd = "voice\RAFA\RAFA002";
				dialog.text = DLG_TEXT[2] + GetMyName(Pchar) + DLG_TEXT[3];
				Link.l1 = DLG_TEXT[4] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[5])]) + DLG_TEXT[6];
				Link.l1.go = "main_line_blaze";
			}
			Diag.TempNode = "first time";
		break;

		case "main_line_blaze":
			Dialog.snd = "voice\RAFA\RAFA003";
			Dialog.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
