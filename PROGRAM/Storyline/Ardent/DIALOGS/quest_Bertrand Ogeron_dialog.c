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

			if(GetAttribute(NPChar, "quest.meeting") != "1")
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[2];
				link.l2 = DLG_TEXT[3];
			}
			else
			{
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l2 = DLG_TEXT[6];
			}
			link.l1.go = "imperial_escort_envoy_taken";
			link.l2.go = "exit";
		break;

		case "imperial_escort_envoy_taken":
			NPChar.quest.meeting = "1";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "imperial_escort_maybe_france";
		break;

		case "imperial_escort_maybe_france":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "imperial_escort_where_kidnapped";
		break;

		case "imperial_escort_where_kidnapped":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "imperial_escort_try_port_au_prince";
		break;

		case "imperial_escort_try_port_au_prince":
			dialog.text = DLG_TEXT[13] + GetMyFullName(GetTownGovernor("Port au Prince")) + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "imperial_escort_be_discreet";
		break;

		case "imperial_escort_be_discreet":
			if(GetRMRelation(PChar, FRANCE) > REL_WAR)
			{
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[18] + DLG_TEXT[19];
				AddDialogExitQuest("imperial_escort_visit_Port_au_Prince_governor");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[16] + DLG_TEXT[17];
				link.l1 = DLG_TEXT[18];
				link.l1.go = "imperial_escort_get_disguise";
			}
		break;

		case "imperial_escort_get_disguise":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21] + DLG_TEXT[19];
			AddDialogExitQuest("imperial_escort_visit_Port_au_Prince_governor");
			AddDialogExitQuest("imperial_escort_tortuga_tailor_setup");
			link.l1.go = "exit";
		break;	
	}
}