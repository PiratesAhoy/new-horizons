//#include "DIALOGS\Church crew_dialog.h"
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
			Dialog.snd = "voice\THDI\THDI001";
			
			if(CheckAttribute(Pchar,"abbess") && Pchar.abbess == "dont_disturb")
			{
				PlaySound("VOICE\ENGLISH\defoe_psst.wav");
				dialog.text = DLG_TEXT[32];
				link.l1 = DLG_TEXT[33];
				link.l1.go = "exit";
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "abbess1";
			}
			
			Diag.TempNode = "first time";
		break;

		case "abbess1":
			PlaySound("VOICE\ENGLISH\Fre_f_a_008.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "merchant";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "privateer";
			link.l3 = DLG_TEXT[5];
			link.l3.go = "painting";
			link.l4 = DLG_TEXT[6];
			link.l4.go = "pirate";
			link.l5 = DLG_TEXT[7];
			link.l5.go = "maroon";
		break;

		case "merchant":
			PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
			dialog.text = DLG_TEXT[8];
			link.l2 = DLG_TEXT[4];
			link.l2.go = "privateer";
			link.l3 = DLG_TEXT[5];
			link.l3.go = "painting";
			link.l4 = DLG_TEXT[6];
			link.l4.go = "pirate";
			link.l5 = DLG_TEXT[3];
			link.l5.go = "maroon";
		break;

		case "privateer":
			PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "merchant";
			link.l3 = DLG_TEXT[5];
			link.l3.go = "painting";
			link.l4 = DLG_TEXT[6];
			link.l4.go = "pirate";
			link.l5 = DLG_TEXT[3];
			link.l5.go = "maroon";
		break;

		case "painting":
			PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "merchant";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "privateer";
			link.l4 = DLG_TEXT[6];
			link.l4.go = "pirate";
			link.l5 = DLG_TEXT[3];
			link.l5.go = "maroon";
		break;

		case "pirate":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "pirate1";
		break;

		case "maroon":
			PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "merchant";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "privateer";
			link.l3 = DLG_TEXT[5];
			link.l3.go = "painting";
			link.l4 = DLG_TEXT[6];
			link.l4.go = "pirate";
		break;

		case "pirate1":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "pirate2";
		break;

		case "pirate2":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "pirate3";
		break;

		case "pirate3":
			PlaySound("VOICE\ENGLISH\Fre_f_a_008.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "pirate4";
		break;

		case "pirate4":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("abbess_quest_given");
		break;

	//--------------------------------------------------------------

		case "precious_items":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("precious_items_done");
		break;

		case "map":
			PlaySound("VOICE\ENGLISH\Fre_f_a_006.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "map1";
		break;

		case "map1":
			PlaySound("VOICE\ENGLISH\Fre_f_a_009.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("abbess_map_given");
		break;

		case "thank_you":
			PlaySound("VOICE\ENGLISH\Fre_f_a_008.wav");
			PlaySound("VOICE\ENGLISH\Fre_f_a_008.wav");
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "thank_you1";
		break;

		case "thank_you1":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "thank_you1";
			AddDialogExitQuest("Sister_Richards_leaves");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
