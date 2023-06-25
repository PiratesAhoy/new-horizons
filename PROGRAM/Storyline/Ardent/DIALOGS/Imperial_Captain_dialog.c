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

			dialog.text = dialog.text = DLG_TEXT[0] + GetAddressForm(ADDR_CIVIL, SPAIN, chrsex(PChar)) + ".";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "Meeting_in_San_Juan":
			dialog.text = DLG_TEXT[0] + GetAddressForm(ADDR_CIVIL, SPAIN, chrsex(PChar)) + ".";
			link.l1 = DLG_TEXT[2] + GetMyFullName(NPChar) + "?";
			link.l1.go = "Meeting_in_San_Juan2";
		break;

		case "Meeting_in_San_Juan2":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[6];
			link.l1.go = "Meeting_in_San_Juan3";
		break;

		case "Meeting_in_San_Juan3":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8] + XI_ConvertString(GetRankName(CharacterFromID("Jusepe Guimaraes"), SPAIN)) + DLG_TEXT[9];
			link.l1.go = "Meeting_in_San_Juan4";
		break;

		case "Meeting_in_San_Juan4":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			AddDialogExitQuest("imperial_escort_meeting_in_cabin");
			link.l1.go = "exit";
		break;

		case "introduce_envoy":
			dialog.text = DLG_TEXT[12] + NPChar.Ship.Name + DLG_TEXT[13] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[14];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "not_just_lady":
			dialog.text = DLG_TEXT[15] + GetMyLastName(PChar) + DLG_TEXT[16];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "mission_significance":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "rolling_heads";
		break;

		case "rolling_heads":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			if(IsDay()) link.l1.go = "escort_to_san_juan_residence";
			else link.l1.go = "wait_till_tomorrow";
		break;

		case "wait_till_tomorrow":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			AddDialogExitQuest("imperial_escort_wait_till_morning_San_Juan");
			link.l1.go = "exit";
		break;

		case "escort_to_san_juan_residence":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			AddDialogExitQuest("imperial_escort_to_San_Juan_residence");
			link.l1.go = "exit";
		break;

		case "san_juan_residence_arrived":
			dialog.text = DLG_TEXT[25] + GetMyLastName(PChar) + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
		break;

		case "sail_to_santo_domingo":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			if(GetCompanionQuantity(PChar) < COMPANION_MAX)
			{
				link.l1.go = "sail_to_santo_domingo_ready";
			}
			else
			{
				link.l1.go = "too_many_ships";
			}
		break;

		case "sail_to_santo_domingo_ready":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "when_we_reach_santo_domingo";
		break;

		case "when_we_reach_santo_domingo":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			AddDialogExitQuest("imperial_escort_sail_to_santo_domingo");
			link.l1.go = "exit";
		break;

		case "envoy_taken":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "envoy_taken2";
		break;

		case "envoy_taken2":
			Preprocessor_AddQuestData("captain", GetMyFullName(CharacterFromID("Imperial_Captain")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			AddQuestRecord("Imperial Escort", 6);
			Preprocessor_Remove("admiral");
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("captain");
			dialog.text = DLG_TEXT[36] + GetMyFullName(CharacterfromID("Jusepe Guimaraes")) + ".";
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
		break;

		case "envoy_safe":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "envoy_safe2";
		break;

		case "envoy_safe2":
			dialog.text = DLG_TEXT[40];
			link.l1 = DlG_TEXT[41];
			AddDialogExitQuest("imperial_escort_Santo_Domingo_residence_approach");
			link.l1.go = "exit";
		break;

		case "Santo_Domingo_residence_arrived":
			dialog.text = DLG_TEXT[42];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "Santo_Domingo_residence_arrived2":
			dialog.text = DLG_TEXT[43] + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[44] + GetMyLastName(CharacterFromID("Imperial_Captain")) + DLG_TEXT[45];
			link.l1.go = "exit";
		break;

		case "too_many_ships":
			dialog.text = DLG_TEXT[46]  + NPChar.Ship.Name + DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			Diag.TempNode = "sail_to_santo_domingo";
			link.l1.go = "exit";
		break;
	}
}