//#include "DIALOGS\Faust Gasquet_dialog.h"
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
			dialog.snd = "Voice\FAGA\FAGA001";
			
			Diag.TempNode = "Second time";
			d.Text = GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Node_1";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "Node_2";
			PChar.quest.Story_AskAboutBerangere = "3";
		break;

		case "Node_1":
			dialog.snd = "Voice\FAGA\FAGA002";
			d.Text = DLG_TEXT[3] + GetMyFullName(NPChar) + DLG_TEXT[4] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "Node_3";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "Exit";
		break;

		case "Node_2":
			dialog.snd = "Voice\FAGA\FAGA003";
			d.Text = DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "exit";
		break;

		case "Node_3":
			dialog.snd = "Voice\FAGA\FAGA004";
			d.Text = DLG_TEXT[12]; 
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Node_4";
		break;

		case "Node_4":
			dialog.snd = "Voice\FAGA\FAGA005";
			d.Text = DLG_TEXT[14] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[15];
			if(makeint(Pchar.money) >= 5)
			{
				Link.l1 = DLG_TEXT[16];
				Link.l1.go = "Node_5";
			}
			else
			{
				Link.l1 = DLG_TEXT[17];
				Link.l1.go = "Node_6";
			}
			Link.l2 = DLG_TEXT[18];
			Link.l2.go = "Node_2";
		break;

		case "Node_5":
			AddMoneyToCharacter(PChar, -5);
		    PlayStereoSound("INTERFACE\took_item.wav");
			dialog.snd = "Voice\FAGA\FAGA006";
			d.Text = DLG_TEXT[19] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "node_7";
		break;
	
		case "Node_6":
			dialog.snd = "Voice\FAGA\FAGA007";
			d.Text = DLG_TEXT[22] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "exit";
		break;
	
		case "Node_7":
			dialog.snd = "Voice\FAGA\FAGA008";
			d.Text = DLG_TEXT[25] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "Node_8";
			Link.l2 = DLG_TEXT[28];
			Link.l2.go = "Node_9";
		break;

		case "Node_8":
			dialog.snd = "Voice\FAGA\FAGA009";
			d.Text = DLG_TEXT[29] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Node_10";
			Link.l2 = DLG_TEXT[32];
			Link.l2.go = "Node_11";
			Link.l3 = DLG_TEXT[33];
			Link.l3.go = "exit";
		break;

		case "Node_9":
			dialog.snd = "Voice\FAGA\FAGA010";
			d.Text = DLG_TEXT[34] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "Node_8";
			Link.l2 = DLG_TEXT[37];
			Link.l2.go = "exit";
		break;

		case "Node_10":
			dialog.snd = "Voice\FAGA\FAGA011";
			d.Text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "Node_11";
			Link.l2 = DLG_TEXT[40];
			Link.l2.go = "exit";
		break;

		case "Node_11":
			dialog.snd = "Voice\FAGA\FAGA012";
			PChar.quest.Story_AskAboutBerangere = "1";
			d.Text = DLG_TEXT[41] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "node_12";
		break;

		case "Node_12":
			dialog.snd = "Voice\FAGA\FAGA013";
			d.Text = GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[44])]) + DLG_TEXT[46] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48] + GetMyName(NPChar) + DLG_TEXT[49];
			Link.l1.go = "Exit";
		break;

		case "Second Time":
			if(CheckQuestAttribute("Story_AskAboutBerangere", "1"))
			{
				dialog.snd = "Voice\FAGA\FAGA014";
				d.Text = DLG_TEXT[50] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[51];
			}
			else
			{
				dialog.snd = "Voice\FAGA\FAGA015";
				d.Text = DLG_TEXT[52] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[53];
			}
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "Node_3";
			Link.l2 = DLG_TEXT[55];
			Link.l2.go = "exit";
		break;
	}
}

