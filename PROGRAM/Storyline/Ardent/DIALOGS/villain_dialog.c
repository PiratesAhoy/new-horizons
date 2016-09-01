//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string gov_kid, gov_kid_pronoun1, gov_kid_pronoun2;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	if (PChar.sex == "man")
	{
		gov_kid = "daughter";
		gov_kid_pronoun1 = "she";
		gov_kid_pronoun2 = "her";
	}
	else
	{
		gov_kid = "son";
		gov_kid_pronoun1 = "he";
		gov_kid_pronoun2 = "his";
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

			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + "?";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "first_letter":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6];
			link.l1.go = "first_letter2";
		break;

		case "first_letter2":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "first_letter3";
		break;

		case "first_letter3":
			dialog.text = DLG_TEXT[9] + GetMyFullName(characterFromID(PChar.quest.romance)) + ", " + gov_kid + DLG_TEXT[10];
			link.l1 = DLG_TEXT[11] + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[12];
			AddDialogExitQuest("deliver_first_CourtingLetter");
			link.l1.go = "exit";
		break;

		case "CourtingLetter_not_yet":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "CourtingLetter_not_yet_exit";
		break;

		case "CourtingLetter_not_yet_exit":
			Diag.CurrentNode = "CourtingLetter_not_yet";
			DialogExit();
		break;

		case "first_letter_delivered":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[15] + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[16];
			link.l1.go = "lie_happy";
			if (checkquestattribute("ardent_kidnap.wedding", "sad"))
			{
				link.l2 = DLG_TEXT[18] + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[19];
				link.l2.go = "lie_unhappy";
			}
			link.l3 = DLG_TEXT[17];
			link.l3.go = "truth";
		break;

		case "lie_happy":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "disgrace_exit";
			Preprocessor_AddQuestData("villain", GetMySimpleName(PChar.quest.villain));
			AddQuestRecord("Kidnap", 22);
			Preprocessor_Remove("villain");
		break;

		case "lie_unhappy":
			dialog.text = DLG_TEXT[22] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[23];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "disgrace_exit";
			Preprocessor_AddQuestData("villain", GetMySimpleName(PChar.quest.villain));
			AddQuestRecord("Kidnap", 22);
			Preprocessor_Remove("villain");
		break;

		case "truth":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, 200);
			dialog.text = DLG_TEXT[24] + GetMySimpleName(characterFromID("Grigorio Formoselle")) + DLG_TEXT[25] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[26] + GetMyName(characterFromID("Grigorio Formoselle")) + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			AddDialogExitQuest("deliver_second_CourtingLetter");
			link.l1.go = "exit";
		break;

		case "disgrace":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "disgrace_exit";
		break;

		case "disgrace_exit":
			Diag.CurrentNode = "disgrace";
			DialogExit();
		break;

		case "second_letter_delivered":
			dialog.text = DLG_TEXT[29] + GetMyLastName(PChar) + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[32];
			link.l1.go = "second_letter_delivered2";
		break;

		case "second_letter_delivered2":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, 2000);
			TakeItemFromCharacter(Pchar, "SignetRing");
			dialog.text = DLG_TEXT[33]+ GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[34] + gov_kid_pronoun2 + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			AddQuestRecord("Kidnap", 25);
			CloseQuestHeader("Kidnap");
			Preprocessor_Remove("villain");
		break;
	}
}