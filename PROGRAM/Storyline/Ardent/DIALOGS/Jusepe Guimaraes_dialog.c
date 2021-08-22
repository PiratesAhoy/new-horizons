//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string rank;

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

			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
			if (CheckCharacterItem(PChar, "BattleOrders2"))
			{
				if (CheckAttribute(PChar, "quest.threat_governor_sent_me"))
				{
					link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[6];
				}
				else
				{
					link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[18];
				}
				link.l1.go = "show_battle_orders";
			}
			if (CheckAttribute(PChar, "quest.finale_governor_sent_me"))
			{
				link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[21];
				link.l1.go = "finale_no_defence";
			}
			link.l10 = DLG_TEXT[2] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[3];
			link.l10.go = "Exit";
		break;

		case "show_battle_orders":
			if (CheckAttribute(PChar, "quest.ardent_treachery_status")) DeleteQuestAttribute("ardent_treachery_status");
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			TakeItemFromCharacter(Pchar, "BattleOrders2");
			if (HasRank(PChar, SPAIN)) rank = GetRankName(PChar, SPAIN);
			else rank = XI_ConvertString("captain");
/*			if (CheckAttribute(PChar, "quest.threat_governor_sent_me"))
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneytoCharacter(PChar, 5000);
				dialog.text = DLG_TEXT[7] + DLG_TEXT[8] + DLG_TEXT[9];	// Ends with request to leave, temporary end until finale is written
				DeleteQuestAttribute("threat_governor_sent_me");
			}
			else
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneytoCharacter(PChar, 5000);
				dialog.text = DLG_TEXT[19] + rank + DLG_TEXT[20] + DLG_TEXT[8] + DLG_TEXT[9];
			}
			link.l1 = DLG_TEXT[10] + GetRankName(NPChar, sti(NPChar.nation)) + ".";
			link.l1.go = "exit"; */
			if (CheckAttribute(PChar, "quest.threat_governor_sent_me"))
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneytoCharacter(PChar, 5000);
				Preprocessor_Add("person", PChar.sex);
				dialog.text = DLG_TEXT[7] + DLG_TEXT[8] + DLG_TEXT[11];	// Leads to mission which will lead to finale
				DeleteQuestAttribute("threat_governor_sent_me");
			}
			else
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneytoCharacter(PChar, 5000);
				Preprocessor_Add("person", PChar.sex);
				dialog.text = DLG_TEXT[19] + rank + DLG_TEXT[20] + DLG_TEXT[8] + DLG_TEXT[11];
			}
			link.l1 = DLG_TEXT[12];
			link.l1.go = "propose_mission";
		break;

		case "propose_mission":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			if(CheckAttribute(PChar, "quest.finale_galleons") || GetCompanionQuantity(PChar) > COMPANION_MAX-2)
			{
				dialog.text = DLG_TEXT[13];
			}
			else
			{
				PChar.quest.finale_assign_galleons = "true";
				dialog.text = DLG_TEXT[13] + DLG_TEXT[14];
				AddDialogExitQuest("finale_assign_galleons");
				PChar.quest.finale_galleons_assigned_by = "Jusepe Guimaraes";
			}
			Diag.TempNode = "why_still_here";
			link.l1 = DLG_TEXT[15] + GetRankName(NPChar, sti(NPChar.nation)) + ".";
			link.l1.go = "exit_finale_accept_mission";
//			link.l2 = DLG_TEXT[16];
//			link.l2.go = "exit";
		break;

		case "finale_no_defence":
			DeleteQuestAttribute("finale_governor_sent_me");
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "finale_propose_mission";
		break;

		case "finale_propose_mission":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			if(CheckAttribute(PChar, "quest.finale_galleons") || GetCompanionQuantity(PChar) > COMPANION_MAX-2)
			{
				dialog.text = DLG_TEXT[24];
			}
			else
			{
//				PChar.quest.finale_assign_galleons = "true";
				dialog.text = DLG_TEXT[24] + DLG_TEXT[14];
				AddDialogExitQuest("finale_assign_galleons");
				PChar.quest.finale_galleons_assigned_by = "Jusepe Guimaraes";
			}
			Diag.TempNode = "why_still_here";
			link.l1 = DLG_TEXT[15] + GetRankName(NPChar, sti(NPChar.nation)) + ".";
			link.l1.go = "exit_finale_accept_mission";
		break;

		case "why_still_here":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[2] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[3];
			link.l1.go = "Exit";
		break;

		case "exit_threat_accept_mission":
			Preprocessor_AddQuestData("target", FindTownName("Santiago"));
			AddQuestRecord("Santiago Threat", 6);
			CloseQuestHeader("Santiago Threat");
			Preprocessor_Remove("target");
			AddDialogExitQuest("finale_santiago_evacuation_setup");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit_finale_accept_mission":
			if (CheckAttribute(PChar, "Santiago Threat")) CloseQuestHeader("Santiago Threat");
			if (!CheckAttribute(PChar, "QuestInfo.Battle Royale")) SetQuestHeader("Battle Royale");
			Preprocessor_AddQuestData("admiral", GetMyFullName(NPChar));
			Preprocessor_AddQuestData("target", FindTownName("Santiago"));
			AddQuestRecord("Battle Royale", 23);
			Preprocessor_Remove("target");
			Preprocessor_Remove("admiral");
			AddDialogExitQuest("finale_santiago_evacuation_setup");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}