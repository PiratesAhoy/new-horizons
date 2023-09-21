void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
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

		dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];		// changed from .spa to .por by KAM
		Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
		Link.l1.go = "node_1";
		NextDiag.TempNode = "First time";
		break;

	case "node_1":
		dialog.text = DLG_TEXT[8];
		Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false)); // KK
		link.l1 = DLG_TEXT[9];
		link.l1.go = "quests";
		link.l2 = DLG_TEXT[10];
		link.l2.go = "node_2";
		break;

	case "node_2":
		dialog.text = DLG_TEXT[11];
		link.l1 = DLG_TEXT[12];
		link.l1.go = "exit";
		break;

	case "quests":
		if(CheckQuestAttribute("ardent_treachery_status", "planned"))
		{
			link.l10 = DLG_TEXT[76] + GetMyFullName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[77];
			link.l10.go = "ardent_treachery_warning";
		}
		link.l99 = DLG_TEXT[13];
		link.l99.go = "exit";
		break;

	case "Exit":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	case "gov_1":
		dialog.snd = "Voice\REGR\REGR008";
		dialog.text = DLG_TEXT[70];
		link.l1 = DLG_TEXT[71];
		link.l1.go = "gov_2";
		break;

	case "gov_2":
		dialog.snd = "Voice\REGR\REGR008";
		dialog.text = DLG_TEXT[72];
		link.l1 = DLG_TEXT[73];
		link.l1.go = "gov_3";
		break;

	case "gov_3":
		dialog.snd = "Voice\REGR\REGR008";
		dialog.text = DLG_TEXT[74];
		link.l1 = DLG_TEXT[75];
		link.l1.go = "exit";
		AddDialogExitQuest("Morro_loot");
		break;

	case "ardent_treachery_warning":
		if (GetRMRelation(PChar, ENGLAND) > REL_WAR)
		{
			dialog.text = DLG_TEXT[78] + GetMyLastName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[79] + DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			AddDialogExitQuest("treachery_setup_gate_battle");
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			Preprocessor_AddQuestData("governor", GetMySimpleName(characterFromID("John Clifford Brin")));
			if(PChar.sex == "woman") Preprocessor_AddQuestData("pronoun", "her");
			else Preprocessor_AddQuestData("pronoun", "his");
			AddQuestRecord("Treachery", 5);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("governor");
			Preprocessor_Remove("villain");
			PChar.quest.treachery_peace_england = "bought";
		}
		else
		{
			Preprocessor_Add("pronoun", GetMyPronounObj(PChar));
			dialog.text = DLG_TEXT[78] + GetMyLastName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[79] + DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			AddDialogExitQuest("treachery_arrest");
		}
		link.l1.go = "exit";
	break;

	case "ardent_treachery_pardon":
		dialog.text = DLG_TEXT[84] + GetMyLastName(PChar) + ".";
		link.l1 = DLG_TEXT[85];
		link.l1.go = "ardent_treachery_pardon2";
	break;

	case "ardent_treachery_pardon2":
		AddQuestRecord("Treachery", 7);
		CloseQuestHeader("Treachery");
		Preprocessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
		dialog.text = DLG_TEXT[86];
		link.l1 = DLG_TEXT[89];
		link.l1.go = "ardent_hunt_villain_wanted";
		if(GetRMRelation(PChar, ENGLAND) < REL_AMNESTY)
		{
			SetRMRelation(PChar, ENGLAND, REL_AMNESTY);
			PChar.quest.treachery_peace_england = "reward";
		}
		if (PChar.quest.alignment == "good") ChangeCharacterReputation(PChar, 5);
		else ChangeCharacterReputation(PChar, 3);
	break;

	case "ardent_treachery_reward":
		dialog.text = DLG_TEXT[87] + GetMyLastName(PChar) + DLG_TEXT[88];
		link.l1 = DLG_TEXT[89];
		link.l1.go = "ardent_hunt_villain_wanted";
		PlayStereoSound("INTERFACE\took_item.flac");
		AddMoneyToCharacter(pchar, 20000);
		if (PChar.quest.alignment == "good") ChangeCharacterReputation(PChar, 5);
		else ChangeCharacterReputation(PChar, 3);
		AddQuestRecord("Treachery", 8);
		CloseQuestHeader("Treachery");
		PChar.quest.treachery_peace_england = "bought";
	break;

	case "ardent_hunt_villain_wanted":
		Preprocessor_Add("pronoun", GetMyPronounObj(characterFromID(PChar.quest.villain)));
		dialog.text = DLG_TEXT[90] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[91];
		link.l1 = DLG_TEXT[92];
		AddDialogExitQuest("hunt_setup_Gilbert");
		link.l1.go = "exit";
	break;
	}
}
