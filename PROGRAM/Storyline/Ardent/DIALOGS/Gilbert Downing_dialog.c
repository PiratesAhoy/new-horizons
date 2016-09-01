//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string gov_kid, merch_kid;
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	if (PChar.sex == "man")
	{
		gov_kid = "daughter";
		merch_kid = "son";
	}
	else
	{
		gov_kid = "son";
		merch_kid = "daughter";
	}

	DeleteQuestAttribute("ardent_kidnap.find_merchant");
	
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

			dialog.text = DLG_TEXT[0] + GetMyLastName(characterFromID(PChar.quest.villain)) + DLG_TEXT[1];
			if(CheckAttribute(PChar,"quest.ardent_kidnap"))
			{
				link.l1 = DLG_TEXT[3];
				link.l1.go = "ask_kid";
			}
			link.l2 = DLG_TEXT[2];
			link.l2.go = "exit";
		break;

		case "ask_kid":
			dialog.text = DLG_TEXT[4] + merch_kid + ", " + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
		break;
	}
}