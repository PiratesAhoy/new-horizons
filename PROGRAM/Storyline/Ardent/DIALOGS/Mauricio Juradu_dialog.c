//#include "DIALOGS\Mauricio Juradu_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	int money;

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

		case "hire_guide":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "hire_guide2";
		break;

		case "hire_guide2":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "hire_guide3";
		break;

		case "hire_guide3":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "hire_guide4";
		break;

		case "hire_guide4":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "hire_guide5";
		break;

		case "hire_guide5":
			dialog.text = DLG_TEXT[9];
			if(CheckAttribute(PChar,"money")) money = makeint(PChar.money);
			else money = 0;
			if (money >= 500)
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "hired_guide";
			}
			link.l2 = DLG_TEXT[11];
			link.l2.go = "not_enough_money";
		break;

		case "hired_guide":
			AddDialogExitQuest("hired_guide");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "not_enough_money":
			Diag.CurrentNode = "back_with_money";
			DialogExit();
		break;

		case "back_with_money":
			dialog.text = DLG_TEXT[12];
			if(CheckAttribute(PChar,"money")) money = makeint(PChar.money);
			else money = 0;
			if (money >= 500)
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "hired_guide";
			}
			link.l2 = DLG_TEXT[11];
			link.l2.go = "not_enough_money";
		break;

		case "find_beach":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit";
		break;

		case "start_of_trail":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Exit";
		break;

		case "end_of_trail":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exit";
		break;

		case "recruiting":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounPossessive(PChar)));
		//	if (PChar.sex == "man") Preprocessor_Add("pronoun", XI_ConvertString("his"));
		//	else Preprocessor_Add("pronoun", XI_ConvertString("her"));
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "challenge";
		break;

		case "challenge":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Exit";
		break;
	}
}