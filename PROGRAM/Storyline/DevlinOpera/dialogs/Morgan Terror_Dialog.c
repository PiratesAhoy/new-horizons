//#include "DIALOGS\Morgan Terror_Dialog.h"
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
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			if(checkquestattribute("Bonnie_talk", "Needing_some_help"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "Chatter_on_Morgan";
			}
			if(CheckQuestAttribute("Morgan_talk", "First_for_Nevis"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "Chatter_on_Morgan";
			}
			if(CheckQuestAttribute("Morgan_talk", "Approach_Residence"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "Chatter_on_Morgan";
			}
			if(CheckQuestAttribute("Bonnie_talk", "Blaze_in_Jamaica"))
			{
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "Morgan_talks_again";
			}
		break;

		case "Chatter_on_Morgan":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Chatter_on_Morgan2";
		break;

		case "Chatter_on_Morgan2":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Chatter_on_Morgan3";
		break;

		case "Chatter_on_Morgan3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit";
		break;

		case "Morgan_talks_again":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Morgan_talks_again2";
		break;

		case "Morgan_talks_again2":
			if(makeint(pchar.money)>=100)
			{
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "PayUp_Exit";
				link.l2 = DLG_TEXT[14];
				link.l2.go = "Exit";
			}
			else
			{
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Exit";
			}
		break;

		case "PayUp_Exit":
			ChangeCharacterAddressGroup(characterfromID("Blaze Devlin"),"Redmond_tavern", "goto", "goto2");
			AddMoneyToCharacter(pchar, -100);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Swannexit":
			AddDialogExitQuest("Swann_starts_talking");
			DialogExit();
		break;

		case "Swannexitagain":
			AddDialogExitQuest("Off_to_shipyard_now");
			DialogExit();
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
