//#include "DIALOGS\Job Anderson_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

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
			
			if(CheckAttribute(Pchar,"monastary")) 
			{
				switch(Pchar.monastary)
				{
					case "sister_Richards":
						PlaySound("VOICE\ENGLISH\Dut_f_a_001.wav");
						dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];		
						link.l1.go = "Sister_Richards1";
					break;

					case "repeat_sister_Richards":
						PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");
						Dialog.text = DLG_TEXT[10];
						link.l1 = DLG_TEXT[11];
						link.l1.go = "exit";
					break;

					case "repeat_abbess":
						if(NPchar.id == "bb_nun1")
						{
							PlaySound("VOICE\ENGLISH\Eng_f_c_001.wav");
						}
						else PlaySound("VOICE\ENGLISH\Dut_f_a_003.wav");
						Dialog.text = DLG_TEXT[12];
						link.l1 = DLG_TEXT[13];
						link.l1.go = "exit";
					break;	

					case "repeat_abbess_quest":
						if(NPchar.id == "bb_nun1")
						{
							PlaySound("VOICE\ENGLISH\Eng_f_c_005.wav");
						}
						else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");
						Dialog.text = DLG_TEXT[14];
						link.l1 = DLG_TEXT[15];
						link.l1.go = "exit";
					break;

					case "repeat_abbess_quest_window_hint":
						if(NPchar.id == "bb_nun1")
						{
							PlaySound("VOICE\ENGLISH\Eng_f_c_005.wav");
						}
						else PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");
						Dialog.text = DLG_TEXT[14];
						link.l1 = DLG_TEXT[18];
						link.l1.go = "repeat_abbess_quest_window_hint1";
					break;

					case "dont_disturb":
						PlaySound("VOICE\ENGLISH\defoe_psst.wav");
						Dialog.text = DLG_TEXT[16];
						link.l1 = DLG_TEXT[17];
						link.l1.go = "exit";
					break;		
				}
				return;
			}

			Diag.TempNode = "first time";
		break;

		case "Sister_Richards1":
			PlaySound("VOICE\ENGLISH\Dut_f_a_005.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Sister_Richards2";
		break;

		case "Sister_Richards2":
			PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Sister_Richards3";
		break;

		case "Sister_Richards3":
			PlaySound("VOICE\ENGLISH\gr_wench3_oh.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Sister_Richards4";
		break;

		case "Sister_Richards4":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Sister_Richards5";
		break;

		case "Sister_Richards5":
			PlaySound("VOICE\ENGLISH\Dut_f_a_004.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("Sister_Richards_in_bell_tower");
		break;

		case "repeat_abbess_quest_window_hint1":
			PlaySound("VOICE\ENGLISH\Dut_f_a_002.wav");
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
