void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar = GetMainCharacter();
	int iNation = sti(NPChar.nation);

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------ƒиалог первый - перва€ встреча
		case "First time":
			Dialog.defAni = "Gov_dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Gov_dialog_1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3] + GetMyShipNameShow(PChar) + DLG_TEXT[4];
			Link.l1.go = "node_1";
			NextDiag.TempNode = "Second time";
		break;

		case "node_1":
			if (makeint(pchar.reputation) < 10)
			{
				Dialog.Text = DLG_TEXT[5] + GetMyFullName(NPChar) + DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "second time";
			}
			else
			{
				Dialog.text = DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go = "second time";
			}
		break;

		case "Second time":
			dialog.text = DLG_TEXT[11] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "quests";
			if (npchar.quest.english_war_ship == "1")
			{
				link.l1 = DLG_TEXT[14];
				link.l1.go = "english_war_ship_5";
			}
			NextDiag.TempNode = "Second time";
			Link.l99 = DLG_TEXT[15];
			Link.l99.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[16] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
		break;

		case "quests":
			dialog.text = DLG_TEXT[19] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			if (npchar.quest.english_war_ship == "0")
			{
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];
				link.l1.go = "english_war_ship";
			}
			if (npchar.quest.english_war_ship == "2")
			{
				dialog.text = DLG_TEXT[24] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[25];
				link.l1 = DLG_TEXT[26];
				link.l1.go = "english_war_ship_4";
			}
			if (CheckQuestAttribute("gambling_with_girl", "gambled") || CheckQuestAttribute("gambling_with_girl", "prisoned") || CheckQuestAttribute("gambling_with_girl", "to_hovernor_2"))
			{
				Preprocessor_AddQuestData("nation", GetNationDescByType(GetTownNation("Falaise de Fleur")));
				if (CheckQuestAttribute("gambling_with_girl", "to_hovernor_2") && GetNationRelation2MainCharacter(iNation) == RELATION_ENEMY)
				{
					//прощают
					dialog.text = DLG_TEXT[27];
					link.l1 = DLG_TEXT[28];
					link.l1.go = "forgive";
					AddQuestRecord("gambled_girl", 13);
					CloseQuestHeader("gambled_girl");
				}
				else
				{
					if (GetNationRelation2MainCharacter(iNation) == RELATION_ENEMY)
					{
						//позвол€ют уйти
						dialog.text = DLG_TEXT[29];
						link.l1 = DLG_TEXT[30] + GetCharacterFullName(DLG_TEXT[31]) + DLG_TEXT[32];
						link.l1.go = "ransom";
						AddQuestRecord("gambled_girl", 15);
						CloseQuestHeader("gambled_girl");
					}
					else
					{
						//обычный разговор
						dialog.text = DLG_TEXT[33];
						link.l1 = DLG_TEXT[34] + GetCharacterFullName(DLG_TEXT[35]) + DLG_TEXT[36];
						link.l1.go = "virginie";
						AddQuestRecord("gambled_girl", 14);
						CloseQuestHeader("gambled_girl");
					}
				}
				Preprocessor_Remove("nation");
			}
 			if (CheckQuestAttribute("Hunter", "Roxanne"))
			{
				dialog.Text = DLG_TEXT[170];
				link.l1 = DLG_TEXT[172];
				link.l1.go = "gov_1";
			}			
		break;

		case "virginie":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "ransom_2";
			link.l2 = DLG_TEXT[39];
			link.l2.go = "virginie_2";
		break;

		case "virginie_2":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[42])]) + DLG_TEXT[43];
			link.l1.go = "virginie_3";
		break;

		case "virginie_3":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			pchar.quest.gambling_with_girl = "done";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 4000);
			if(GetRMRelation(PChar, iNation) < REL_NEUTRAL) SetRMRelation(PChar, iNation, REL_NEUTRAL); // RM
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2800);
				AddPartyExpChar(pchar, "Sneak", 28);
			}
			else { AddPartyExp(pchar, 2800); }
			AddDialogExitQuest("remove_virginie_complete"); // PB
		break;

		case "ransom":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "ransom_2";
		break;

		case "ransom_2":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "ransom_3";
		break;

		case "ransom_3":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "ransom_4";
		break;

		case "ransom_4":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "ransom_5";
		break;

		case "ransom_5":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "ransom_6";
		break;

		case "ransom_6":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "exit";
			pchar.quest.gambling_with_girl = "done";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 7000);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1600);
				AddPartyExpChar(pchar, "Sneak", 16);
			}
			else { AddPartyExp(pchar, 1600); }
			pchar.quest.remove_virginie.win_condition.l1 = "location";
			pchar.quest.remove_virginie.win_condition.l1.location = "FalaiseDeFleur";
			pchar.quest.remove_virginie.win_condition = "remove_virginie_complete";
			ChangeCharacterAddress(characterFromID("Virginie d'Espivant"), "Falaise_de_fleur_location_03", "locator9");
			LAi_SetCitizenType(characterFromID("Virginie d'Espivant"));
			if(GetRMRelation(PChar, iNation) > REL_WAR) SetRMRelation(&PChar, iNation, REL_WAR); // RM
			LeaveService(&PChar, iNation, true);
		break;

		case "forgive":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "forgive_2";
		break;

		case "forgive_2":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "forgive_3";
		break;

		case "forgive_3":
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			pchar.quest.gambling_with_girl = "done";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 4000);
			if(GetRMRelation(PChar, iNation) < REL_AMNESTY) SetRMRelation(PChar, iNation, REL_AMNESTY); // RM
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 25);
			}
			else { AddPartyExp(pchar, 2500); }
			AddDialogExitQuest("remove_virginie_complete"); // PB
		break;

		case "english_war_ship":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "english_war_ship_1";
			link.l2 = DLG_TEXT[66];
			link.l2.go = "exit";
		break;

		case "english_war_ship_1":
			dialog.text = DLG_TEXT[67] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "english_war_ship_2";
			link.l2 = DLG_TEXT[70];
			link.l2.go = "english_war_ship_3";
		break;

		case "english_war_ship_2":
			dialog.text = DLG_TEXT[71] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "exit";
			SetRumourState("Ship_off_FDF", false); // NK
			AddDialogExitQuest("joseph_claude_le_mougne_english_war_ship");
		break;

		case "english_war_ship_3":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "english_war_ship_2";
			link.l2 = DLG_TEXT[76];
			link.l2.go = "exit";
			npchar.quest.english_war_ship = "done";
		break;

		case "english_war_ship_4":
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 30000);
			if(ENABLE_WEAPONSMOD)	GiveItem2Character(pchar, "blade25+3");
			else					GiveItem2Character(pchar, "blade25");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 15);
			}
			else { AddPartyExp(pchar, 1500); }
			npchar.quest.english_war_ship = "done";
			AddQuestRecord("Hire_by_france_for_defeat_england_corvette", 3);
			CloseQuestHeader("Hire_by_france_for_defeat_england_corvette");
		break;

		case "english_war_ship_5":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "english_war_ship_6";
			link.l2 = DLG_TEXT[81];
			link.l2.go = "exit";
		break;

		case "english_war_ship_6":
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "exit";
			npchar.quest.english_war_ship = "done_1";
			ChangeCharacterReputation(pchar, -1);

			Preprocessor_AddQuestData("Le Moigne", GetMyLastName(CharacterFromID("Joseph Claude Le Moigne")));
			Preprocessor_AddQuestData("heavy frigate", XI_ConvertString(GetShipTypeName(CharacterFromID("Eng Captain Near FdF"))));
			AddQuestRecord("Hire_by_france_for_defeat_england_corvette", 2);
			CloseQuestHeader("Hire_by_france_for_defeat_england_corvette");
			Preprocessor_Remove("heavy frigate");
			Preprocessor_Remove("Le Moigne");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "gov_1":
			dialog.snd = "Voice\REGR\REGR008";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "gov_2";
		break;

		case "gov_2":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[176];
			link.l1.go = "gov_3";
		break;

		case "gov_3":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[177];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "gov_4";
		break;

		case "gov_4":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[179];
			link.l1 = DLG_TEXT[180];
			link.l1.go = "gov_5";
		break;

		case "gov_5":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[181];
			link.l1 = DLG_TEXT[182];
			link.l1.go = "exit";
			AddDialogExitQuest("irpara_eleuthera");
		break;
	}
}
