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
			link.l1.go = "exit";
		break;

		case "hunt_what_is_it":
			Preprocessor_Add("ship", Characters[GetCharacterIndex(PChar.quest.villain)].Ship.Name);
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "hunt_what_if_i_am";
		break;

		case "hunt_what_if_i_am":
			Preprocessor_Add("villain", GetMySimpleName(characterfromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounObj(CharacterFromId(PChar.quest.villain))));
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "hunt_in_town";
		break;

		case "hunt_in_town":
			Preprocessor_Add("villain", GetMySimpleName(characterfromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounObj(CharacterFromId(PChar.quest.villain))));
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
		break;
	}
}