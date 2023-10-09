//#include "DIALOGS\Wilfred_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;
	
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
			Dialog.snd = "voice\WIDI\WIDI001";

			Diag.TempNode = "Second time";
			d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, true, true) + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "Node_1";
		break;

		case "Node_1":
			Dialog.snd = "voice\WIDI\WIDI002";
			d.Text = DLG_TEXT[3] + GetMyName(NPChar) + DLG_TEXT[4];
			if(LAi_IsDead(characterFromID("Ewan Glover")))
			{
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "Node_failed";
			}
			else
			{
				AddQuestRecord("Story_2ndTask",6);
				Diag.TempNode = "Second time";
				Link.l1 = DLG_TEXT[6];
				Link.l1.go = "Node_2";
			}
		break;


		case "Node_2":
			Preprocessor_Add("pronoun2", GetMyPronounObj(PChar));
			Dialog.snd = "voice\WIDI\WIDI003";
			d.Text = DLG_TEXT[7] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[8] + GetMyName(Pchar) + DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Node_3";
		break;

		case "Node_3":
			Dialog.snd = "voice\WIDI\WIDI004";
			d.Text = DLG_TEXT[11]; 
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "Node_4";
		break;

		case "node_4":
			Dialog.snd = "voice\WIDI\WIDI005";
			d.Text = DLG_TEXT[13] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Node_5";
		break;

		case "Node_5":
			Dialog.snd = "voice\WIDI\WIDI006";
			d.text = DLG_TEXT[16] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "node_6";
		break;

		case "Node_6":
			Dialog.snd = "voice\WIDI\WIDI007";
			d.Text = DLG_TEXT[19] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Node_7";
		break;

		case "Node_7":
			Dialog.snd = "voice\WIDI\WIDI008";
			d.Text =   DLG_TEXT[22] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24] + GetMyName(NPChar) + DLG_TEXT[25];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_Wilfred_go_to_shore_prepare");
		break;

		case "Node_failed":
			Dialog.snd = "voice\WIDI\WIDI009";
			d.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "Node_Failed_1";
		break;

		case "Node_Failed_1":
			Dialog.snd = "voice\WIDI\WIDI010";
			d.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "exit";
			AddDialogExitQuest("Wilfred_exit_failed");
		break;

		case "Second Time":
			Dialog.snd = "voice\WIDI\WIDI011";
			d.text = DLG_TEXT[30] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32] + GetMyName(NPChar) + DLG_TEXT[33];
			Link.l1.go = "exit";
			AddDialogExitQuest("Wilfred_exit_failed");
		break;

		case "Warning":
			Dialog.snd = "voice\WIDI\WIDI012";
			D.text = DLG_TEXT[34] + GetMyName(Pchar) + DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "Warning_1";
		break;
	
		case "Warning_1":
			Dialog.snd = "voice\WIDI\WIDI013";
			D.Text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38];
			Link.l1.go = "exit";
			AddDialogExitQuest("Wilfred_exit_fight");
		break;

		case "Victory":
			Dialog.snd = "voice\WIDI\WIDI014";
			d.text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "Victory_1";
		break;

		case "Victory_1":
			Dialog.snd = "voice\WIDI\WIDI015";
			d.Text =  DLG_TEXT[41];
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "Victory_2";
		break;

		case "Victory_2":
			Dialog.snd = "voice\WIDI\WIDI016";
			d.Text = DLG_TEXT[43] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Victory_3";
		break;

		case "Victory_3":
			Dialog.snd = "voice\WIDI\WIDI017";
			d.text = DLG_TEXT[46] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "Victory_4";
		break;

		case "Victory_4":
			Dialog.snd = "voice\WIDI\WIDI018";
			d.text = DLG_TEXT[49] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[50];
			Link.l1	= DLG_TEXT[51];
			Link.l1.go = "exit";
			AddDialogExitQuest("Wilfred_exit_complete");
		break;

		case "Failed_in_last_moment":
			Dialog.snd = "voice\WIDI\WIDI019";
			d.Text = DLG_TEXT[52];
			Link.l1 = DLG_TEXT[53];
			Link.l1.go = "Failed_in_last_moment_1";
		break;

		case "Failed_in_last_moment_1":
			Dialog.snd = "voice\WIDI\WIDI020";
			d.Text = DLG_TEXT[54];
			Link.l1 = DLG_TEXT[55];
			Link.l1.go =  "exit";
			AddDialogExitQuest("Wilfred_Exit_failed_in_last_moment");
		break;
		}
}



