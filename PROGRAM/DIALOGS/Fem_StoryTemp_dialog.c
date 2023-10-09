//#include "DIALOGS\Fem_StoryTemp_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
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
			Dialog.snd = "dialogs\0\009";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "FirstOnQuebradas";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "exit";

		break;			

		case "FirstOnQuebradas":
			d.Text = DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "FirstOnQuebradas_1";
			Link.l2 = DLG_TEXT[5];
			Link.l2.go = "exit";
		break;			

		case "FirstOnQuebradas_1":
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "FirstOnQuebradas_2";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "exit";
		break;			

		case "FirstOnQuebradas_2":
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "FirstOnQuebradas_3";
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "exit";
		break;			

		case "FirstOnQuebradas_3":
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "FirstOnQuebradas_4";			
		break;			

		case "FirstOnQuebradas_4":
			d.Text = DLG_TEXT[14] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[15])]) + DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "FirstOnQuebradas_5";			
		break;			

		case "FirstOnQuebradas_5":
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19] + Characters[getCharacterIndex(DLG_TEXT[20])].lastname + DLG_TEXT[21];
			Link.l1.go = "FirstOnQuebradas_6";			
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "FirstOnQuebradas_7";			
		break;			

		case "FirstOnQuebradas_6":
			diag.Tempnode = "NothingTalk";
			d.Text = DLG_TEXT[23] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "Exit";						
		break;	
		
		case "FirstOnQuebradas_7":
			diag.Tempnode = "NothingTalk";
			d.Text = DLG_TEXT[26] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "Exit";						
		break;			

		case "NothingTalk":
			d.Text = DLG_TEXT[29];
			Link.l1 = DLG_TEXT[30];
			Link.l1.go = "Exit";						
		break;			

		case "GotRheimsInfo":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			d.Text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "GotRheimsInfo_1";						
		break;			

		case "GotRheimsInfo_1":
			d.Text = Characters[GetCharacterIndex(DLG_TEXT[33])].lastname + DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35];
			Link.l1.go = "GotRheimsInfo_2";						
		break;			

		case "GotRheimsInfo_2":
			Diag.tempNode = "onceAgain";
			SetAfterDialog_Task(PChar, ADA_ENDQUESTMOVIE, true);
			d.Text = DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Exit";						
		break;			

		case "OnceAgain":
			Diag.tempNode = "onceAgain";
			d.Text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "Exit";						
		break;			



	}
}