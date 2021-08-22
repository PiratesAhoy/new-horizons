//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Second time":
			dialog.text = DLG_TEXT[30] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[31] + GetMyName(characterFromID("Wilfred Roscoe")) + ".";
			link.l1.go = "exit";
		break;

		case "abduction_visit":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
		break;

		case "abduction_out":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "abduction_out2";
		break;

		case "abduction_out2":
			dialog.text = GetMyName(characterfromID("Garfield Leighton")) + DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "abduction_out3";
		break;

		case "abduction_out3":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "abduction_stand_straight":
			dialog.text = DLG_TEXT[10];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "abduction_stay_at_posts":
			dialog.text = DLG_TEXT[11];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "abduction_stay_at_posts2":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
		break;

		case "mona_attack_meeting_in_port":
			if(CheckQuestAttribute("revenge_type","san_juan") || CheckQuestAttribute("revenge_type","officer"))
			{
				dialog.text = GetMySimpleName(PChar) + DLG_TEXT[14];
				link.l1 = DLG_TEXT[15] + GetMyName(characterfromID("Wilfred Roscoe")) + "?";
				link.l1.go = "mona_attack_tavern_invitation1";
			}
			else
			{
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19] + GetMyFullName(PChar) + ".";
				link.l1.go = "mona_attack_tavern_invitation2";
			}
		break;

		case "mona_attack_tavern_invitation1":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "mona_attack_tavern_invitation2":
			dialog.text = DLG_TEXT[20] + GetMyFullName(characterfromID("Wilfred Roscoe")) + DLG_TEXT[21];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "mona_attack_tavern1":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "mona_attack_tavern2";
		break;

		case "mona_attack_tavern2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "mona_attack_tavern3";
		break;

		case "mona_attack_tavern3":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "mona_attack_tavern4";
		break;

		case "mona_attack_tavern4":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			Diag.TempNode = "Second time";
			link.l1.go = "exit";
		break;
	}
}