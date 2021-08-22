//#include "DIALOGS\Caminero_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = "empty";
			DialogExit();
		break;
	
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			dialog.snd = "Voice\CADI\CADI003";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "continue"; 
		break;

		case "continue":
			dialog.snd = "Voice\CADI\CADI004";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3]; 
			Link.l1.go = "continue1";
		break;

		case "continue1":
			dialog.snd = "Voice\CADI\CADI005";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "continue2";
		break;

		case "continue2":
			dialog.snd = "Voice\CADI\CADI006";
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "continue3";
		break;

		case "continue3":
			dialog.snd = "Voice\CADI\CADI007";
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			link.l1.go = "continue4";
		break;
		
		case "continue4":
			if(PChar.sex == "woman")
			{
				Preprocessor_Add("pronoun1", FirstLetterUp(XI_ConvertString("her")));
				Preprocessor_Add("pronoun2", XI_ConvertString("her"));
			}
			else
			{
				Preprocessor_Add("pronoun1", FirstLetterUp(XI_ConvertString("his")));
				Preprocessor_Add("pronoun2", XI_ConvertString("his"));
			}
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "continue5";
		break;
		
		case "continue5":
			dialog.text = pcharrepphrase(DLG_TEXT[12], DLG_TEXT[13]);
			link.l1 = pcharrepphrase(DLG_TEXT[14], DLG_TEXT[15]);
			link.l1.go = pcharrepphrase("continue6", "continue7");
		break;
		
		case "continue6":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "continue7";
		break;
		
		case "continue7":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "continue8";
		break;
		
		case "continue8":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("change_Maxwell_adress");
		break;
		
		case "empty":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit"
		break;
	}
}