//#include "DIALOGS\Antoine Chamfort_dialog.h"

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

	Preprocessor_Add("AntoineChamfort", GetMySimpleName(CharacterFromID("Antoine Chamfort")));
	Preprocessor_Add("Chamfort", GetMyLastName(CharacterFromID("Antoine Chamfort")));
	Preprocessor_Add("addr", GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, false));
	
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
			
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[0];
			        link.l1 = DLG_TEXT[1];
				link.l1.go = "begin";
		break;

                case "begin":

			dialog.snd = "Voice\CLLA\CLLA003";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
		break;

		case "begin_2":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_3";

		break;

		case "begin_3":

			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";
			
		break;
              
                case "begin_4":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("antoinefort");
		break;

              
	}
}
