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
			if (CheckQuestAttribute("ardent_convoy", "Curacao"))
			{
				if (!LAi_IsDead(characterFromID(PChar.quest.romance)) && !CheckAttribute(PChar, "quest.spain_betrayal"))
				{
					dialog.text = DLG_TEXT[70];
					link.l1 = DLG_TEXT[71] + Characters[GetCharacterIndex("Convoy_Captain1")].Ship.Name + DLG_TEXT[72] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[73];
				}
				else
				{
					dialog.text = DLG_TEXT[15];
					link.l1 = DLG_TEXT[100] + Characters[GetCharacterIndex("Convoy_Captain1")].Ship.Name + DLG_TEXT[72] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[73];
				}
				link.l1.go = "ardent_convoy_need_proof";

				if(PChar.sex == "man" && PChar.model != "Ardent_S")
				{
					dialog.text = DLG_TEXT[97];
					link.l1 = DLG_TEXT[98];
					link.l1.go = "exit";
				}
				if(PChar.sex == "woman" && PChar.model != "Ardent_SF")
				{
					dialog.text = DLG_TEXT[97];
					link.l1 = DLG_TEXT[98];
					link.l1.go = "exit";
				}
			}
			if (CheckQuestAttribute("ardent_convoy", "trade_proposal"))
			{
				dialog.text = DLG_TEXT[89];
				link.l1 = DLG_TEXT[90];
				link.l1.go = "ardent_convoy_recognised";
			}
			link.l99 = DLG_TEXT[13];
			link.l99.go = "exit";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ardent_convoy_need_proof":
			PChar.quest.ardent_convoy = "seen_curacao_governor";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "ardent_convoy_governor_offended";
		break;

		case "ardent_convoy_governor_offended":
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			if (!LAi_IsDead(characterFromID(PChar.quest.romance)) && !CheckAttribute(PChar, "quest.spain_betrayal")) 
			{
				AddDialogExitQuest("convoy_partner_intervenes");
				link.l1.go = "ardent_convoy_exit_offended";
			}
			else
			{
				AddDialogExitQuest("convoy_prepare_to_depart_no_infiltrate");
				Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
				AddQuestRecord("Convoy Strike", 12);
				Preprocessor_Remove("romance");
				link.l1.go = "ardent_convoy_exit_offended";
			}
		break;

		case "ardent_convoy_exit_offended":
			NextDiag.CurrentNode = "ardent_convoy_still_offended";
			DialogExit();
		break;

		case "ardent_convoy_still_offended":
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "ardent_convoy_exit_offended";
		break;

		case "ardent_convoy_thats_different":
			dialog.text = DLG_TEXT[78];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "ardent_convoy_happy_to_comply":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "exit";
		break;

		case "ardent_convoy_successful":
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "ardent_convoy_where_companion";
		break;

		case "ardent_convoy_where_companion":
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "ardent_convoy_what_you_do";
		break;

		case "ardent_convoy_what_you_do":
			Preprocessor_Add("captive", GetMyFullName(characterFromID(PChar.quest.romance)))
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "ardent_convoy_give_regards";
		break;

		case "ardent_convoy_give_regards":
			if (PChar.sex == "man" && PChar.model != "Ardent_SF") Preprocessor_Add("relative", XI_ConvertString("daughter"));
			else Preprocessor_Add("relative", XI_ConvertString("son"));
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "exit";
		break;

		case "ardent_convoy_recognised":
			dialog.text = DLG_TEXT[91];
			link.l1 = "";
			AddDialogExitQuest("convoy_romance_interrupts_recognition");
			link.l1.go = "exit";
		break;

		case "ardent_convoy_receive_ship":
			dialog.text = DLG_TEXT[92];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "ardent_convoy_trade_accepted":
			dialog.text = DLG_TEXT[93] + GetMyFullName(characterFromID("Javier Balboa")) + DLG_TEXT[94];
			link.l1 = DLG_TEXT[95] + GetMyRespectfullyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[96];
			link.l1.go = "exit";
		break;

		case "ardent_convoy_fake_intro":
			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + XI_ConvertString("Mijnheer") + DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			Link.l1.go = "node_1";
			NextDiag.TempNode = "First time";
		break;
	}
}
