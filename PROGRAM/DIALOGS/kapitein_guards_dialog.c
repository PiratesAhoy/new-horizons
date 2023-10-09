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

		case "arrest_willem":
			dialog.text = DLG_TEXT[2] + GetMySimpleName(characterFromID("Willem Voigt")) + DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
//			AddDialogExitQuest("Kapitein_willem_confirms_story");
			link.l1.go = "exit";
		break;

		case "know_about_scam":
			dialog.text = DLG_TEXT[5] + GetMyLastName(characterFromID("Willem Voigt")) + DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + GetCharacterAddressForm(characterFromID("Willem Voigt"), ADDR_CIVIL, false, true) + DLG_TEXT[8];
			if (PChar.location == "Philipsburg_exit") link.l1.go = "landward_gate";
			else link.l1.go = "you_are_lucky";
		break;

		case "you_are_lucky":
			dialog.text = DLG_TEXT[9] + GetMySimpleName(characterFromID("Willem Voigt")) + DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
		break;

		case "landward_gate":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13] + GetCharacterAddressForm(characterFromID("Willem Voigt"), ADDR_CIVIL, false, true) + DLG_TEXT[14];
			link.l1.go = "bribery";
		break;

		case "bribery":
			PlayStereoSound("INTERFACE\took_item.wav");				
			if (makeint(PChar.money) >= 500) AddMoneytoCharacter(PChar, -500);
			else PChar.money = 0;
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16] + GetCharacterAddressForm(characterFromID("Willem Voigt"), ADDR_CIVIL, false, true) + DLG_TEXT[17];
			link.l1.go = "evidence";
		break;

		case "evidence":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
		break;

		case "follow_me":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit_follow";
		break;

		case "to_the_townhall":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "to_the_townhall2";
		break;

		case "to_the_townhall2":
			dialog.text = DLG_TEXT[24] + GetMySimpleName(NPChar) + DLG_TEXT[25];
			link.l1 = DLG_TEXT[26] + GetMyLastName(NPChar) + ".";
			link.l1.go = "to_the_townhall3";
		break;

		case "to_the_townhall3":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "to_the_townhall4";
		break;

		case "to_the_townhall4":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "to_the_townhall5";
		break;

		case "to_the_townhall5":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "exit";
		break;

		case "youre_witness":
			dialog.text = "";
			link.l1 = DLG_TEXT[33];
			link.l1.go = "i_am_witness";
		break;

		case "i_am_witness":
			dialog.text = DLG_TEXT[34];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "keep_them_here":
			dialog.text = "";
			link.l1 = DLG_TEXT[35];
			link.l1.go = "keep_them_here2";
		break;

		case "keep_them_here2":
			dialog.text = DLG_TEXT[36];
			link.l1 = "";
			link.l1.go = "exit_guard_townhall";
		break;

		case "on_guard_in_townhall":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit_guard_townhall";
		break;

		case "youre_nicked":
			dialog.text = DLG_TEXT[39] + GetMyFullName(PChar) + DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "youre_nicked2";
		break;

		case "youre_nicked2":
			dialog.text = DLG_TEXT[42] + GetMySimpleName(NPChar) + DLg_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit_arrested";
			link.l2 = DLG_TEXT[45];
			link.l2.go = "exit_resist_arrest";
		break;

		case "trial_witness1":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar)));
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
		break;

		case "trial_witness2":
			dialog.text= DLG_TEXT[48];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "kapitein_goto_governor":
			dialog.text = DLG_TEXT[49] + GetMyFullName(CharacterFromID("Reynard Grueneveldt")) + DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "kapitein_goto_governor2";
			link.l2 = DLG_TEXT[53];
			link.l2.go = "exit";
		break;

		case "kapitein_goto_governor2":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "exit";
		break;

		case "exit_follow":
			Diag.CurrentNode = "follow_me";
			DialogExit();
		break;

		case "exit_guard_townhall":
			Diag.CurrentNode = "on_guard_in_townhall";
			DialogExit();
		break;

		case "exit_arrested":
			AddDialogExitQuest("kapitein_trial");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit_resist_arrest":
			AddDialogExitQuest("kapitein_resist_arrest");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}