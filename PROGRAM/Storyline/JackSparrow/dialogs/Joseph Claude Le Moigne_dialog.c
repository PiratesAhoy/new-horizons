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
			if (CheckQuestAttribute("Firstcontact", "debut"))
			{
				dialog.text = DLG_TEXT[70];
				link.l1 = DLG_TEXT[71];
				link.l1.go = "gov_1";
			}
			link.l99 = DLG_TEXT[13];
			link.l99.go = "exit";
			
// Side quest Verginie - Salonikasurf
			if (CheckQuestAttribute("gambling_with_girl", "gambled") || CheckQuestAttribute("gambling_with_girl", "prisoned") || CheckQuestAttribute("gambling_with_girl", "to_hovernor_2"))
			{
				if (CheckQuestAttribute("gambling_with_girl", "to_hovernor_2") && GetNationRelation2MainCharacter(iNation) == RELATION_ENEMY)
				{
					//прощают
					dialog.text = DLG_TEXT[96];
					link.l1 = DLG_TEXT[97];
					link.l1.go = "forgive";
					AddQuestRecord("gambled_girl", 13);
					CloseQuestHeader("gambled_girl");
				}
				else
				{
					if (GetNationRelation2MainCharacter(iNation) == RELATION_ENEMY)
					{
						//позвол§ют уйти
						dialog.text = DLG_TEXT[98];
						link.l1 = DLG_TEXT[99] + GetCharacterFullName(DLG_TEXT[100]) + DLG_TEXT[101];
						link.l1.go = "ransom";
						AddQuestRecord("gambled_girl", 15);
						CloseQuestHeader("gambled_girl");
					}
					else
					{
						//обычный разговор
						dialog.text = DLG_TEXT[102];
						link.l1 = DLG_TEXT[103] + GetCharacterFullName(DLG_TEXT[104]) + DLG_TEXT[105];
						link.l1.go = "virginie";
						AddQuestRecord("gambled_girl", 14);
						CloseQuestHeader("gambled_girl");
					}
				}
			}			
		break;

		case "virginie":
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "ransom_2";
			link.l2 = DLG_TEXT[108];
			link.l2.go = "virginie_2";
		break;

		case "virginie_2":
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[111])]) + DLG_TEXT[112];
			link.l1.go = "virginie_3";
		break;

		case "virginie_3":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
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
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "ransom_2";
		break;

		case "ransom_2":
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "ransom_3";
		break;

		case "ransom_3":
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "ransom_4";
		break;

		case "ransom_4":
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[122];
			link.l1.go = "ransom_5";
		break;

		case "ransom_5":
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			link.l1.go = "ransom_6";
		break;

		case "ransom_6":
			dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[126];
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
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "forgive_2";
		break;

		case "forgive_2":
			dialog.text = DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "forgive_3";
		break;

		case "forgive_3":
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
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
		
// Side quest Verginie - Salonikasurf		

		case "gov_1":
			dialog.snd = "Voice\REGR\REGR008";
			if (GetAttribute(PChar, "Luc_Time") == "months")
			{
				dialog.text = DLG_TEXT[72];
			}
			else
			{
				dialog.text = DLG_TEXT[95];
			}
			link.l1 = DLG_TEXT[93];
			link.l1.go = "exit_Lucas";
		break;

		case "gov_2":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "gov_3";
		break;

		case "gov_3":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "gov_4";
		break;

		case "gov_4":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "gov_5";
			link.l2 = DLG_TEXT[78];
			link.l2.go = "gov_6";
		break;

		case "gov_5":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "exit";
			AddDialogExitQuest("Contact_start_search");
		break;

		case "gov_6":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "exit";
			PChar.quest.Firstcontact = "fin";
			DeleteEnterLocationQuest("Falaise_de_Fleur_townhall", "Contact_start_check");
			AddQuestRecord("Contact", 2);
		break;

		case "gov_7":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "gov_8";
		break;

		case "gov_8":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "exit";
			AddDialogExitQuest("goportcayman");
			SetEnterLocationQuest("Quest_Falaise_de_fleur_location_03", "davy_townfight1", 0); // PB
		break;

		case "gov_9":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "gov_10";
		break;

		case "gov_10":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "gov_11";
		break;

		case "gov_11":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "exit";
			AddDialogExitQuest("beaufinal");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Lucas":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Contact_Lucas");
		break;
	}
}
