//#include "DIALOGS\Sabine Matton_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

	ref PChar;
	PChar = GetMainCharacter();


	switch(Dialog.CurrentNode)
	{
		//----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";			

			if (npchar.quest.meeting == "0")
			{
				Dialog.snd = "voice\SAMA\SAMA001";
				Dialog.Text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + npchar.nickname + DLG_TEXT[2];
				Link.l1 = pcharrepphrase(DLG_TEXT[3] + GetMyName(NPChar) + DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5], DLG_TEXT[6] + GetMyFullName(PChar) + DLG_TEXT[7] + GetMyName(Pchar) + DLG_TEXT[8]);
				Link.l1.go = "exit"; 
				link.l2 = pcharrepphrase(DLG_TEXT[9], DLG_TEXT[10]);
				link.l2.go = "first_time_01";
				npchar.quest.meeting = "1";
				NextDiag.TempNode = "First time";
//--->>> TALISMAN - change code to get Sabine Run Away - with player if Player is Female  - code working - no reputation check since Sabine desperate to run away
//				if (pchar.id == "Blaze")	npchar.quest.hire = "blaze_begin";
//				else						npchar.quest.hire = "danielle_begin";
				if (PChar.sex == "man")		npchar.quest.hire = "blaze_begin";
				else						npchar.quest.hire = "danielle_begin";
//<<<----- TALISMAN
			}
			else
			{
				Dialog.snd = "voice\SAMA\SAMA002";
				Dialog.Text = DLG_TEXT[11] + GetMyName(Pchar) + DLG_TEXT[12];
				if (makeint(pchar.rank) > 3)
				{
					Dialog.snd = "voice\SAMA\SAMA003";
					Dialog.text = Dialog.text + DLG_TEXT[13];
				}
				Link.l1 = pcharrepphrase(DLG_TEXT[14], DLG_TEXT[15]);
				Link.l1.go = "exit"; 
				NextDiag.TempNode = "Second time";
			}
		break;

		case "Second Time":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			if (npchar.quest.hire == "blaze_on_ship")
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "exit";
			}
			if (npchar.quest.hire == "captured_by_blaze")
			{
				link.l1 = DLG_TEXT[19];
				link.l1.go = "exit";
			}
			if (npchar.quest.love == "1")
			{
				link.l1 = DLG_TEXT[20];
				link.l1.go = "exit";
			}
			if (npchar.quest.hire == "danielle_begin")
			{
				Dialog.snd = "voice\SAMA\SAMA004";
				dialog.text = DLG_TEXT[21] + GetMyName(Pchar) + DLG_TEXT[22];
				link.l1 = pcharrepphrase(DLG_TEXT[23], DLG_TEXT[24] + GetMyName(PChar) + DLG_TEXT[25]);
				link.l1.go = "danielle_1";
			}
			if (npchar.quest.hire == "request")
			{
				Dialog.snd = "voice\SAMA\SAMA005";
				dialog.text = DLG_TEXT[26];
				link.l1 = pcharrepphrase(DLG_TEXT[27], DLG_TEXT[28] + GetMyName(PChar) + DLG_TEXT[29]);
				link.l1.go = "danielle_1";
			}
		break;

		case "danielle_1":
			Dialog.snd = "voice\SAMA\SAMA006";
			dialog.text = DLG_TEXT[30] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[31];
			link.l1 = pcharrepphrase(DLG_TEXT[32], DLG_TEXT[33]);
			link.l1.go = "danielle_2";
		break;

		case "danielle_2":
			Dialog.snd = "voice\SAMA\SAMA007";
			dialog.text = DLG_TEXT[34];
			link.l1 = pcharrepphrase(DLG_TEXT[35], DLG_TEXT[36]);
			link.l1.go = "danielle_3";
			link.l2 = pcharrepphrase(DLG_TEXT[37], DLG_TEXT[38]);
			link.l2.go = "exit";
		break;

		case "danielle_3":
			Dialog.snd = "voice\SAMA\SAMA008";
			dialog.text = DLG_TEXT[39];
			link.l1 = pcharrepphrase(DLG_TEXT[40], DLG_TEXT[41]);
			link.l1.go = "danielle_4";
			link.l2 = pcharrepphrase(DLG_TEXT[42], DLG_TEXT[43]);
			link.l2.go = "danielle_5";
		break;

		case "danielle_4":
			Dialog.snd = "voice\SAMA\SAMA009";
			dialog.text = DLG_TEXT[44];
			link.l1 = pcharrepphrase(DLG_TEXT[45], DLG_TEXT[46]);
			link.l1.go = "danielle_5";
		break;

		case "danielle_5":
			Dialog.snd = "voice\SAMA\SAMA010";
			dialog.text = DLG_TEXT[47];
			link.l1 = pcharrepphrase(DLG_TEXT[48], DLG_TEXT[49]);
			link.l1.go = "danielle_6";
			link.l2 = pcharrepphrase(DLG_TEXT[50], DLG_TEXT[51]);
			link.l2.go = "exit";
			npchar.quest.hire = "request";
		break;

		case "danielle_6":
			Dialog.snd = "voice\SAMA\SAMA011";
			dialog.text = DLG_TEXT[52];
			link.l1 = pcharrepphrase(DLG_TEXT[53], DLG_TEXT[54]);
			link.l1.go = "danielle_7";
			link.l2 = pcharrepphrase(DLG_TEXT[55], DLG_TEXT[56]);
			link.l2.go = pcharrepphrase("danielle_end_1", "danielle_end_2");
		break;

		case "danielle_7":
			Dialog.snd = "voice\SAMA\SAMA012";
			dialog.text = DLG_TEXT[57];
			link.l1 = pcharrepphrase(DLG_TEXT[58], DLG_TEXT[59]);
			link.l1.go = "danielle_8";
			link.l2 = pcharrepphrase(DLG_TEXT[60], DLG_TEXT[61]);
			link.l2.go = "danielle_end_1";
		break;

		case "danielle_8":
			Dialog.snd = "voice\SAMA\SAMA013";
			dialog.text = DLG_TEXT[62] + GetMyName(Pchar) + DLG_TEXT[63];
			link.l1 = pcharrepphrase(DLG_TEXT[64], DLG_TEXT[65]);
			link.l1.go = "exit";
			npchar.quest.hire = "danielle_on_ship";
			AddPassenger(pchar, npchar, 0);
			SetCharacterRemovable(characterFromID("Sabine Matton"), false);// PW locked as passenger until quest complete
			AddDialogExitQuest("danielle_end_exit");
			//ChangeCharacterAddress(npchar, "none", "none");// PW replaced by "danielle_end_exit" case to action leave
		break;

		case "danielle_end_1":
			Dialog.snd = "voice\SAMA\SAMA014";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "exit";
			npchar.quest.hire = "done";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 500);
				AddPartyExpChar(pchar, "Sneak", 5);
			}
			else { AddPartyExp(pchar, 500); }
		break;

		case "danielle_end_2":
			Dialog.snd = "voice\SAMA\SAMA015";
			dialog.text = DLG_TEXT[68] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			npchar.quest.hire = "escape";// PW looks like future extension point
			AddDialogExitQuest("danielle_end_exit");

		//	npchar.location = "none"; // PW replaced by "danielle_end_exit" case to action leave
			//именно так. Исчезает при следующем входе в локацию.
		break;

		case "first_time_01":
			Dialog.snd = "voice\SAMA\SAMA016";
			dialog.text = DLG_TEXT[71];
			link.l1 = pcharrepphrase(DLG_TEXT[72], DLG_TEXT[73]);
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
