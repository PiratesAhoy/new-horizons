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
	ref villain = characterFromID(PChar.quest.villain);
	string villain_name;
	if (villain.sex == "woman")
	{
		if (CheckAttribute(villain, "married")) villain_name = "Madame " + GetMyLastName(villain);
		else villain_name = "Mademoiselle " + GetMyLastName(villain);
	}
	else villain_name = "Monsieur " + GetMyLastName(villain);
	
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

		case "spy_caught":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyFullName(CharacterFromID("French_Captain1")) + DLG_TEXT[4];
			link.l1.go = "spy_caught2";
		break;

		case "spy_caught2":
			if (PChar.sex == "man")
			{
				Preprocessor_Add("pronoun", XI_ConvertString("him"));
				dialog.text = DLG_TEXT[5] + GetMyFullName(CharacterFromID("French_Captain1")) + DLG_TEXT[6] + DLG_TEXT[9];
			}
			else
			{
				Preprocessor_Add("pronoun", XI_ConvertString("her"));
				dialog.text = DLG_TEXT[7] + GetMySimpleName(CharacterFromID("French_Captain1")) + DLG_TEXT[8] + DLG_TEXT[9];
			}
			link.l1 = DLG_TEXT[10];
//			AddDialogExitQuest("hung at dawn");
			link.l1.go = "exit";
		break;

		case "who_are_you":
			dialog.text = DLG_TEXT[11] + GetMyFullName(CharacterFromID("French_Contre-Amiral")) + DLG_TEXT[12];
			link.l1 = DLG_TEXT[3] + GetMyFullName(CharacterFromID("French_Captain1")) + DLG_TEXT[4];
			if (PChar.ship.type != "RN_RaaFrigate") link.l1.go = "wheres_your_ship";
			else link.l1.go = "introductions";
		break;

		case "wheres_your_ship":
			dialog.text = DLG_TEXT[13] + Characters[GetCharacterIndex("French_Lieutenant")].Ship.Name + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "standing_orders";
		break;

		case "standing_orders":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "introductions";
		break;

		case "introductions":
			dialog.text = DLG_TEXT[18] + GetMyFullName(CharacterFromID("French_Captain2")) + DLG_TEXT[19] + GetMyFullName(CharacterFromID("French_Captain3")) + DLG_TEXT[20] + GetMyFullName(villain) + ". "
			link.l1 = "...";
			if (checkquestattribute("signet_ring_known", "true"))
			{
				AddDialogExitQuest("mona_attack_villain_recognises");
				link.l1.go = "exit";
			}
			else link.l1.go = "on_to_business";
		break;

		case "on_to_business":
			dialog.text = DLG_TEXT[21];
			if (PChar.ship.type != "RN_RaaFrigate") link.l1 = DLG_TEXT[23] + DLG_TEXT[24];
			else link.l1 = DLG_TEXT[22] + DLG_TEXT[24];
			link.l1.go = "continue_report";
		break;

		case "continue_report":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "future_plans";
		break;

		case "future_plans":
			dialog.text = DLG_TEXT[27] + DLG_TEXT[28] + DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
//			link.l1.go = "dismissed"; // Basic diversion
			link.l1.go = "treachery"; // Treachery at Port Royale
		break;

		case "dismissed":
			AddQuestRecord("Isla Mona Attack", 10); // Basic diversion
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			AddDialogExitQuest("mona_attack_return_to_ship");
			link.l1.go = "exit";
		break;

		case "treachery":
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			AddQuestRecord("Isla Mona Attack", 9); // Treachery at Port Royale
			Preprocessor_Remove("villain");
			dialog.text = DLG_TEXT[33] + GetMyFullName(villain) + DLG_TEXT[34] + villain_name + DLG_TEXT[35] + villain_name + DLG_TEXT[36];
			link.l1 = DLG_TEXT[32];
			AddDialogExitQuest("mona_attack_return_to_ship");
			link.l1.go = "exit";
		break; 
	}
}