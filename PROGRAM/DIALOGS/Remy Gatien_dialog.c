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
			if (CheckQuestAttribute("Santiago", "payergov"))
			{
				dialog.snd = "Voice\REGR\REGR007";
				dialog.Text = DLG_TEXT[70];
				link.l1 = DLG_TEXT[71];
				link.l1.go = "gov_1";
			}
			if (CheckQuestAttribute("Santiago", "paspaye") && makeint(pchar.money) >= 10000)
			{
				link.l2 = DLG_TEXT[85];
				link.l2.go = "gov_5";
			}
			if (CheckQuestAttribute("abduction_status", "rescue_pirate") && !CheckCharacterItem(PChar, "PrisonPass"))
			{
				dialog.snd = "Voice\REGR\REGR007";
				dialog.Text = DLG_TEXT[70];
				link.l1 = DLG_TEXT[86] + GetMySimpleName(characterFromID("Wilfred Roscoe")) + ".";
				link.l1.go = "ardent_abduction_prison_pass";
			}
			link.l99 = DLG_TEXT[13];
			link.l99.go = "exit";
		break;

		case "gov_1":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "gov_1_1";
		break;

		case "gov_1_1":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "gov_2";
		break;

		case "gov_2":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "gov_3";
		break;

		case "gov_3":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "gov_4";
		break;

		case "gov_4":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[78];
			if (makeint(pchar.money >= 10000))
			{
				link.l1 = DLG_TEXT[79];
				link.l1.go = "gov_5";
			}
			link.l2 = DLG_TEXT[80];
			link.l2.go = "exit";
			pchar.quest.santiago = "paspaye";
		break;

		case "gov_5":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -10000);
			dialog.snd = "Voice\CLLA\CLLA006";
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "exit";
			pchar.quest.santiago = "preparation";
			AddDialogExitQuest("txikilibre");
			AddQuestRecord("Santiago", 6);
		break;

// "Ardent" storyline ---->
		case "ardent_abduction_prison_pass":
			Preprocessor_Add("crime", PChar.quest.background);
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "ardent_abduction_prison_pass2";
		break;

		case "ardent_abduction_prison_pass2":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "ardent_abduction_prison_pass3";
		break;

		case "ardent_abduction_prison_pass3":
			dialog.text = DLG_TEXT[91];
			if (makeint(pchar.money >= 10000))
			{
				link.l1 = DLG_TEXT[92];
				link.l1.go = "ardent_abduction_prison_pass4";
			}
			link.l2 = DLG_TEXT[93];
			link.l2.go = "Exit";
		break;

		case "ardent_abduction_prison_pass4":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -10000);
			GiveItem2Character(PChar, "PrisonPass");
			AddQuestRecord("Abduction", 10);
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "Exit";
		break;

		case "ardent_abduction_return":
			if (PChar.sex == "man") Preprocessor_Add("person", XI_ConvertString("man"));
			else Preprocessor_Add("person", XI_ConvertString("woman"));
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "Exit";
			AddDialogExitQuest("abduction_governor_arrest");
		break;

		case "ardent_hunt_brought_in":
			Dialog.snd = "dialogs\0\009";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false)); 
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "ardent_hunt_not_you";
		break;

		case "ardent_hunt_not_you":
			if (characters[getCharacterIndex(PChar.quest.villain)].sex == "man")
			{
				Preprocessor_Add("title", "Monsieur");
			}
			else
			{
				if (CheckAttribute(characterFromID(PChar.quest.villain), "married")) Preprocessor_Add("title", "Madame");
				else Preprocessor_Add("title", "Madamoiselle");
			}
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			dialog.text = DLG_TEXT[98] + GetMyLastName(characterFromID(PChar.quest.villain)) + DLG_TEXT[99];
			link.l1 = "";
			link.l1.go = "Exit";
		break;

		case "ardent_hunt_due_to_hang":
			Preprocessor_Add("crime", PChar.quest.background);
			dialog.text = DLG_TEXT[100] + GetMyFullName(PChar) + DLG_TEXT[101];
			link.l1 = "";
			link.l1.go = "Exit";
			if (CheckQuestAttribute("background", "pirate"))
			{
				if (HaveLetterOfMarque(ENGLAND) || HaveLetterOfMarque(SPAIN) || HaveLetterOfMarque(HOLLAND))
				{
					link.l1 = DLG_TEXT[102];
					link.l1.go = "ardent_hunt_crimes_before_lom";
				}
			}
		break;

		case "ardent_hunt_crimes_before_lom":
			Preprocessor_Add("crime", PChar.quest.background);
			dialog.text = DLG_TEXT[103];
			link.l1 = "";
			link.l1.go = "Exit";
		break;

		case "ardent_hunt_like_idea":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounObj(PChar)));
			dialog.text = DLG_TEXT[104] + GetMyRespectfullyName(PChar) + DLG_TEXT[105];
			link.l1 = DLG_TEXT[106] + GetMySimpleName(characterFromID(PChar.quest.villain)) + "!";
			link.l1.go = "Exit";
		break;
// <--- "Ardent" storyline

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
