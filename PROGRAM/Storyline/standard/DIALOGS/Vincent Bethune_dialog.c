//#include "DIALOGS\Vincent Bethune_dialog.h"

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

	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_stay1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIBE\VIBE001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		

			if (pchar.quest.main_line == "meet_Vincent_in_lighthouse")
			{
				Dialog.snd = "voice\VIBE\VIBE002";
				Dialog.Text = DLG_TEXT[2] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[3])]) + DLG_TEXT[4];
				Link.l1 = DLG_TEXT[5] + GetMyName(NPChar) + DLG_TEXT[6] + GetMyFullName(PChar) + DLG_TEXT[7] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[8])]) + DLG_TEXT[9];
				Link.l1.go = "meet_Vincent_in_lighthouse_2";
			}
			if (pchar.quest.main_line == "blaze_goto_douwesen_with_danielle_3")
			{
				Dialog.snd = "voice\VIBE\VIBE003";
				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11] + characters[GetCharacterIndex(DLG_TEXT[12])].lastname + DLG_TEXT[13];
				link.l1.go = "blaze_goto_douwesen_with_danielle";
			}
			NextDiag.TempNode = "first time";
		break;

		case "before_vincent_say_about_rheims_2":
			Dialog.snd = "voice\VIBE\VIBE004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15] + characters[GetCharacterIndex(DLG_TEXT[16])].lastname + DLG_TEXT[17];
			link.l1.go = "before_vincent_say_about_rheims_3";
		break;

		case "before_vincent_say_about_rheims_3":
			Dialog.snd = "voice\VIBE\VIBE005";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "before_vincent_say_about_rheims_4";
		break;

		case "before_vincent_say_about_rheims_4":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			pchar.quest.RheimsBook = "vincent_say_about_rheims";
			//SetAfterDialog_Task_Character(NPChar,ADA_DIALOG,"Blaze",true);
		break;

		case "blaze_goto_douwesen_with_danielle":
			Dialog.snd = "voice\VIBE\VIBE007";
			dialog.text = DLG_TEXT[22] + characters[GetCharacterIndex(DLG_TEXT[23])].lastname + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogexitQuest("vincent_exit_from_tavern");
		break;

		case "meet_Vincent_in_lighthouse_2":
			Dialog.snd = "voice\VIBE\VIBE008";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[28])]) + DLG_TEXT[29];
			link.l1.go = "meet_Vincent_in_lighthouse_3";
		break;

		case "meet_Vincent_in_lighthouse_3":
			Dialog.snd = "voice\VIBE\VIBE009";
			dialog.text = DLG_TEXT[30] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[31])]) + DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "meet_Vincent_in_lighthouse_4";
		break;

		case "meet_Vincent_in_lighthouse_4":
			Dialog.snd = "voice\VIBE\VIBE010";
			dialog.text = DLG_TEXT[34] + GetMyName(Pchar) + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "meet_Vincent_in_lighthouse_5";
		break;

		case "meet_Vincent_in_lighthouse_5":
			Dialog.snd = "voice\VIBE\VIBE011";
			dialog.text = GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[37])]) + DLG_TEXT[38];
			link.l1 = DLG_TEXT[39] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[40])]) + DLG_TEXT[41] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[42])]) + DLG_TEXT[43];
			link.l1.go = "meet_Vincent_in_lighthouse_6";
		break;

		case "meet_Vincent_in_lighthouse_6":
			Dialog.snd = "voice\VIBE\VIBE012";
			dialog.text = DLG_TEXT[44] + characters[GetCharacterIndex(DLG_TEXT[45])].lastname + DLG_TEXT[46] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[47])]) + DLG_TEXT[48];
			link.l1 = DLG_TEXT[49] + characters[GetCharacterIndex(DLG_TEXT[50])].lastname + DLG_TEXT[51];
			link.l1.go = "meet_Vincent_in_lighthouse_7";
		break;

		case "meet_Vincent_in_lighthouse_7":
			Dialog.snd = "voice\VIBE\VIBE013";
			dialog.text = DLG_TEXT[52] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[53])]) + DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
			pchar.quest.main_line = "speak_danielle_in_lighthouse_prepare_to_search_rheims";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
