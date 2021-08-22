//#include "DIALOGS\Padre Valentim_dialog.h"
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
	
	//Set some variables if they aren't set yet
	if(!CheckAttribute(NPChar,"setmusic")) NPChar.setmusic = 0;
	if(!CheckAttribute(NPChar,"quest.offered_help")) NPChar.quest.offered_help = 0;

	if (PChar.sex == "man") Preprocessor_Add("child", XI_ConvertString("son"));
	else Preprocessor_Add("child", XI_ConvertString("child"));
	
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
			Dialog.snd = "voice\PAVA\PAVA001";

			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Meeting";
			NextDiag.TempNode = "Meeting";
		break;
		
		case "Meeting":
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Choose Story";
			Link.l3 = DLG_TEXT[19];
			Link.l3.go = "Exit";
		break;
		
		case "Choose Story":
			int price = 10;
			Dialog.Text = DLG_TEXT[4];
			if(sti(PChar.money) < price)
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "Exit";
			}
			else
			{
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "Death the Sweetheart";
				Link.l2 = DLG_TEXT[6];
				Link.l2.go = "Happy Boy";
				Link.l3 = DLG_TEXT[11];
				Link.l3.go = "Exit";
			}
		break;
		
		case "Death the Sweetheart":
			SetMusic("storyteller_sad");
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -10);
			NPChar.setmusic = 1;
			Dialog.Text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Death the Sweetheart 2";
		break;
		
		case "Death the Sweetheart 2":
			Dialog.Text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Death the Sweetheart 3";
		break;
		
		case "Death the Sweetheart 3":
			Dialog.Text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Death the Sweetheart 4";
		break;
		
		case "Death the Sweetheart 4":
			Dialog.Text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Death the Sweetheart 5";
		break;
		
		case "Death the Sweetheart 5":
			Dialog.Text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Death the Sweetheart 6";
		break;

		case "Death the Sweetheart 6":
			Dialog.Text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exit";
		break;
		
		case "Happy Boy":
			SetMusic("storyteller_fun");
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -10);
			NPChar.setmusic = 1;
			Dialog.Text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Happy Boy 2";
		break;
		
		case "Happy Boy 2":
			Dialog.Text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Happy Boy 3";
		break;
		
		case "Happy Boy 3":
			Dialog.Text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Happy Boy 4";
		break;
		
		case "Happy Boy 4":
			Dialog.Text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Happy Boy 5";
		break;
		
		case "Happy Boy 5":
			Dialog.Text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exit";
		break;

		case "Exit":
			if(sti(NPChar.setmusic) == 1)
			{
				//Reset the sound
				LoadSceneSound();
				NPChar.setmusic = 0;
			}
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
