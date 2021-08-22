//#include "DIALOGS\Agent_soldier_dialog.h"
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

		case "challenge":
			dialog.text = DLG_TEXT[2];
			if (PChar.sex == "woman")
			{
				link.l1 = DLG_TEXT[8] + GetMyLastName(CharacterFromID("TQ_Captain1")) + DLG_TEXT[9];
				link.l1.go = "go_ahead";
			}
			else
			{
				link.l1 = DLG_TEXT[3] + GetMyLastName(CharacterFromID("TQ_Captain1")) + DLG_TEXT[4] + GetMySimpleName(CharacterFromID("TQ_Char1")) + DLG_TEXT[5];
				link.l1.go = "always_shirking";
			}
		break;

		case "always_shirking":
			dialog.text = DLG_TEXT[6] + GetMySimpleName(CharacterFromID("TQ_Char1")) + DLG_TEXT[7];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "go_ahead":
			dialog.text = DLG_TEXT[10] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "discovered":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "you_spy";
		break;

		case "you_spy":
			if (PChar.sex == "woman") dialog.text = DLG_TEXT[15] + DLG_TEXT[17] + DLG_TEXT[18];
			else dialog.text = DLG_TEXT[15] + DLG_TEXT[16] + DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
		break;

		case "second_challenge":
			dialog.text = DLG_TEXT[20];
			if (PChar.sex == "woman")
			{
				link.l1 = DLG_TEXT[27];
				link.l1.go = "visitor_denied";
			}
			else
			{
				if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
				{
					link.l1 = DLG_TEXT[24];
					link.l1.go = "lazy_sods";
				}
				else
				{
					link.l1 = DLG_TEXT[21];
					link.l1.go = "papers";
				}
			}
		break;

		case "papers":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			AddDialogExitQuest("AgentQuest_deck_fight");
			link.l1.go = "exit";
		break;

		case "lazy_sods":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			AddDialogExitQuest("AgentQuest_leave_ship");
			link.l1.go = "exit";
		break;

		case "visitor_denied":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29] + GetMyLastName(CharacterFromID("TQ_Captain1")) + DLG_TEXT[30];
			link.l1.go = "make_amends";
		break;

		case "make_amends":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			AddDialogExitQuest("AgentQuest_leave_ship");
			link.l1.go = "exit";
		break;

		case "pirate_guard":
			Diag.TempNode = "pirate_guard";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
		break;

		case "Q_arrives":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Q_intro";
		break;

		case "Q_intro":
			dialog.text = DLG_TEXT[37] + GetMyFullName(NPChar) + DLG_TEXT[38] + GetMyFullName(PChar) + DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Q_equipment";
		break;

		case "Q_equipment":
			TakeNItems(PChar, "pistolpdart", 6);
			GiveItem2Character(PChar, "lockpick");
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[42];
			link.l2.go = "Q_dont_waste_it";
		break;

		case "Q_dont_waste_it":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
		break;
	}
}