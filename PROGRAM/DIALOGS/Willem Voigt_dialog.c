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

			if (ProfessionalNavyNation() != UNKNOWN_NATION)
			{
				Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounPossessive(PChar)));
			//	if (PChar.sex == "woman") Preprocessor_Add("pronoun", "her");
			//	else Preprocessor_Add("pronoun", "his");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";	// was "exit_permanent_refusal", but that means you can't try again if you lose your naval commission
			}
			else
			{
				Preprocessor_Add("person", PChar.sex);
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "interested";
				link.l2 = DLG_TEXT[4];
				link.l2.go = "exit";
			}
		break;

		case "interested":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			AddDialogExitQuest("Kapitein_follow_proposer_upstairs");
			link.l1.go = "exit";
		break;

		case "propose_job":
			SetQuestHeader("fleece");
			AddQuestRecord("fleece", 1);
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "propose_job2";
			link.l2 = DLG_TEXT[9];
			link.l2.go = "exit_offer_still_open";
		break;

		case "propose_job2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "propose_job3";
		break;

		case "propose_job3":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "job_accepted";
			link.l2 = DLG_TEXT[14];
			link.l2.go = "exit_permanent_refusal";
		break;

		case "job_accepted":
			AddQuestRecord("fleece", 3);
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			AddDialogExitQuest("Kapitein_job_accepted");
			link.l1.go = "exit";
		break;

		case "goodbye":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
		break;

		case "confirm_story":
			Preprocessor_Add("person", PChar.sex);
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounObj(PChar)));
			dialog.text = DLG_TEXT[19];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "not_going_in":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "parting_of_ways";
		break;

		case "parting_of_ways":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
		break;

		case "they_got_you_too":
			dialog.text = DLG_TEXT[24] + GetMyName(PChar) + DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "his_crime1";
		break;

		case "his_crime1":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "his_crime2";
		break;

		case "his_crime2":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "why_you_caught";
		break;

		case "why_you_caught":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "write_book";
		break;

		case "write_book":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
		break;

		case "exit_offer_still_open":
			Diag.TempNode = "propose_job";
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Kapitein_setup_proposer_leaves");
			DialogExit();
		break;

		case "exit_permanent_refusal":
			AddDialogExitQuest("Kapitein_setup_proposer_leaves");
			Diag.TempNode = "goodbye";
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}