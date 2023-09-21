//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	int i, cidx;
	ref PChar, sld;
	PChar = GetMainCharacter();
	int FdeFNation = GetTownNation("Falaise de Fleur");
	string FdeFnationDesc = GetNationDescByType(FdeFNation);
	string reward, reward2;
	
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

		case "introductions":
			dialog.text = DLG_TEXT[2] + GetMyFullName(NPChar) + DLG_TEXT[3];
			link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + ".";
			link.l1.go = "why_here";
		break;

		case "why_here":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "no_fool1";
			link.l2 = DLG_TEXT[9];
			link.l2.go = "history";
		break;

		case "no_fool1":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "no_fool2";
			link.l2 = DLG_TEXT[9];
			link.l2.go = "history";
		break;

		case "no_fool2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "history";
		break;

		case "history":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "where_is_madinina";
		break;

		case "where_is_madinina":
			dialog.text = DLG_TEXT[13];
//			if (GetServedNation() == FdeFNation)
//			{
				link.l1 = DLG_TEXT[14];
				link.l1.go = "proposal1a";
//			}
//			else
//			{
//				Preprocessor_Add("nationdesc", FdeFnationDesc);
//				link.l1 = DLG_TEXT[14] + DLG_TEXT[15];
//				link.l1.go = "not_same";
//			}
		break;

		case "not_same":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "not_same2";
		break;

		case "not_same2":
			Preprocessor_Add("nationdesc", FdeFnationDesc);
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "proposal1b";
		break;

		case "proposal1a":
			PChar.quest.crysskull.ultimatum = "poison";
			dialog.text = DLG_TEXT[21] + GetMyFullName(CharacterFromID("Carib_Warrior")) + DLG_TEXT[22] + DLG_TEXT[24] + DLG_TEXT[25];
			for(i = 1; i<OFFICER_MAX; i++)
			{
				cidx = GetOfficersIndex(PChar, i);
				if (cidx >0)
				{
					sld = GetCharacter(cidx);
					if (!LAi_IsImmortal(sld) && GetRemovable(sld))
					{
						PChar.quest.crysskull.hostage = GetOfficersIndex(PChar, i);
						PChar.quest.crysskull.hostage.slot = i;
						PChar.quest.crysskull.ultimatum = "hostage";
						dialog.text = DLG_TEXT[21] + GetMyFullName(CharacterFromID("Carib_Warrior")) + DLG_TEXT[22] + DLG_TEXT[23] + DLG_TEXT[25];
					}
				}
			}
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
		break;

		case "proposal1b":
			PChar.quest.crysskull.ultimatum = "poison";
			dialog.text = DLG_TEXT[20] + DLG_TEXT[21] + GetMyFullName(CharacterFromID("Carib_Warrior")) + DLG_TEXT[22] + DLG_TEXT[24] + DLG_TEXT[25];
			for(i = 1; i<OFFICER_MAX; i++)
			{
				cidx = GetOfficersIndex(PChar, i);
				if (cidx >0)
				{
					sld = GetCharacter(cidx);
					if (!LAi_IsImmortal(sld) && GetRemovable(sld))
					{
						PChar.quest.crysskull.hostage = GetOfficersIndex(PChar, i);
						PChar.quest.crysskull.hostage.slot = i;
						PChar.quest.crysskull.ultimatum = "hostage";
						dialog.text = DLG_TEXT[20] + DLG_TEXT[21] + GetMyFullName(CharacterFromID("Carib_Warrior")) + DLG_TEXT[22] + DLG_TEXT[23] + DLG_TEXT[25];
					}
				}
			}
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
		break;

		case "return_with_skull":
			if (LAi_isDead(characterFromID("Carib_Warrior")))
			{
				dialog.text = GetMyFullName(characterFromID("Carib_Warrior")) + DLG_TEXT[27];
				link.l1 = GetMyFullName(characterFromID("Carib_Warrior")) + DLG_TEXT[28];
				link.l1.go = "warrior_tried_to_steal";
				link.l2 = GetMyFullName(characterFromID("Carib_Warrior")) + DLG_TEXT[29];
				link.l2.go = "warrior_is_hero";
			}
			else
			{
				dialog.text = DLG_TEXT[50] + GetMyFullName(characterFromID("Carib_Warrior")) + DLG_TEXT[51];
				link.l1 = "...",
				AddDialogExitQuest("crysskull_Carib_Warrior_reports");
				link.l1.go = "exit";
			}
		break;

		case "warrior_tried_to_steal":
			if (PChar.quest.crysskull.ultimatum == "hostage") reward = DLG_TEXT[33];
			else reward = DLG_TEXT[34];
			dialog.text = DLG_TEXT[30] + GetMyFullName(characterFromID("Carib_Warrior")) + DLG_TEXT[31];
			link.l1 = DLG_TEXT[32] + reward + DLG_TEXT[35];
			AddDialogExitQuest("crysskull_final_fight_Caribs");
			link.l1.go = "exit";
		break;

		case "warrior_is_hero":	
			if (PChar.quest.crysskull.ultimatum == "hostage")
			{
				reward = DLG_TEXT[38];
				reward2 = DLG_TEXT[33];
			}
			else
			{
				reward = DLG_TEXT[39];
				reward2 = DLG_TEXT[34];
			}
			dialog.text = DLG_TEXT[36] + GetMyFullName(characterFromID("Carib_Warrior")) + DLG_TEXT[37] + reward;
			link.l1 = DLG_TEXT[40];
			link.l1.go = "you_are_honest";
			link.l2 = DLG_TEXT[41] + reward2 + DLG_TEXT[42];
			link.l2.go = "you_are_worm";
		break;

		case "warrior_likes_you":	
			if (PChar.quest.crysskull.ultimatum == "hostage")
			{
				reward = DLG_TEXT[38];
				reward2 = DLG_TEXT[33];
			}
			else
			{
				reward = DLG_TEXT[39];
				reward2 = DLG_TEXT[34];
			}
			dialog.text = GetMyFullName(characterFromID("Carib_Warrior")) + DLG_TEXT[52] + reward;
			link.l1 = DLG_TEXT[40];
			link.l1.go = "you_are_honest";
			link.l2 = DLG_TEXT[41] + reward2 + DLG_TEXT[42];
			link.l2.go = "you_are_worm";
		break;

		case "you_are_honest":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			if (PChar.quest.crysskull.ultimatum == "hostage") reward = DLG_TEXT[44];
			else reward = DLG_TEXT[34];
			dialog.text = DLG_TEXT[43] + reward + ".";
			link.l1 = DLG_TEXT[45] + GetMyFullName(NPChar) + ".";
			link.l1.go = "now_for_reward";
		break;

		case "now_for_reward":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			AddDialogExitQuest("crysskull_Carib_trade");
			link.l1.go = "exit";
		break;

		case "here_is_reward":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "here_is_reward2";
		break;

		case "here_is_reward2":
			Preprocessor_AddQuestData("chief", GetMyFullName(CharacterFromID("Carib_Chief")));
			Preprocessor_AddQuestData("researcher", GetMyFullName(CharacterFromID("Skull_Researcher")));
			AddQuestRecord("crystal_skull", 12);
			Preprocessor_Remove("researcher");
			Preprocessor_Remove("chief");
			GiveItem2Character(PChar, "tomahawk_chief");
			PlayStereoSound("INTERFACE\important_item.flac");
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";
		break;

		case "you_are_worm":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			AddDialogExitQuest("crysskull_final_fight_Caribs");
			link.l1.go = "exit";
		break;
	}
}