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

		case "exit_chicken":
			Diag.TempNode = "try_again";
			Diag.CurrentNode = "try_again";
			DialogExit();
		break;

		case "exit_reject_quest":
			Diag.TempNode = "First time";
			Diag.CurrentNode = "First time";
			NPChar.location = "none";
			DeleteEnterLocationQuest("Smugglers_Tavern", "colombian_silver_start_check");
			DeleteQuestAttribute("colombian_silver.byrom_price");
			DialogExit();
		break;

		case "exit_rehire":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("colombian_silver_rehire_byrom");
			DialogExit();
		break;

		case "exit_leave":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("colombian_silver_byrom_leaves");
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

		case "intro":
			Preprocessor_Add("ladlass", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false));
			dialog.text = DLG_TEXT[2] + GetMyFullName(NPChar) + DLG_TEXT[3];
			link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5];
			link.l1.go = "proposition1";
		break;

		case "proposition1":
			dialog.text = DLG_TEXT[6] + GetMyName(PChar) + DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "proposition2";
		break;

		case "proposition2":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "proposition3";
			link.l2 = DLG_TEXT[11];
			link.l2.go = "exit_chicken";
		break;

		case "try_again":
			dialog.text = DLG_TEXT[12] + GetMyName(PChar) + DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "proposition3";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "exit";
		break;

		case "proposition3":
			dialog.text = DLG_TEXT[16];
			if(GetRMRelation(PChar, SPAIN) >= REL_AMNESTY)
			{
				link.l1 = DLG_TEXT[18];
				if(IsInServiceOf(SPAIN))	// Shouldn't happen as you're only meant to meet this guy if you have no LoM, but just in case...
				{
					link.l1 = DLG_TEXT[19] + TranslateString(GetRankName(PChar, SPAIN),"") + DLG_TEXT[20];
				}
				link.l1.go = "exit_reject_quest";
			}
			link.l2 = DLG_TEXT[21];
			link.l2.go = "haggle1";
			link.l3 = DLG_TEXT[17];
			link.l3.go = "exit_reject_quest";
		break;

		case "haggle1":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "haggle2";
		break;

		case "haggle2":
			dialog.text = DLG_TEXT[24];
			if (CalcCharacterSkill(PChar,SKILL_COMMERCE) <= 2)
			{
				dialog.text = dialog.text + DLG_TEXT[25] + DLG_TEXT[27];
				link.l1 = DLG_TEXT[28] + DLG_TEXT[40];
				link.l1.go = "agreed";
				PChar.quest.colombian_silver.byrom_price = 50;
			}
			else
			{
				dialog.text = dialog.text + DLG_TEXT[26] + DLG_TEXT[27];
				if (CalcCharacterSkill(PChar,SKILL_COMMERCE) <= 5) link.l1 = DLG_TEXT[29] + DLG_TEXT[30] + DLG_TEXT[32];
				else link.l1 = DLG_TEXT[29] + DLG_TEXT[31] + DLG_TEXT[32];
				link.l1.go = "haggle3";
			}
			link.l2 = DLG_TEXT[38];
			link.l2.go = "exit_reject_quest";
		break;

		case "haggle3":
			if (CalcCharacterSkill(PChar,SKILL_COMMERCE) <= 5)
			{
				dialog.text = DLG_TEXT[33] + DLG_TEXT[34];
				PChar.quest.colombian_silver.byrom_price = 35;
			}
			if (CalcCharacterSkill(PChar,SKILL_COMMERCE) > 5 && CalcCharacterSkill(PChar,SKILL_COMMERCE) <= 8)
			{
				dialog.text = DLG_TEXT[33] + DLG_TEXT[35];
				PChar.quest.colombian_silver.byrom_price = 30;
			}
			if (CalcCharacterSkill(PChar,SKILL_COMMERCE) > 8)
			{
				dialog.text = DLG_TEXT[33] + DLG_TEXT[36];
				PChar.quest.colombian_silver.byrom_price = 25;
			}
			dialog.text = dialog.text + DLG_TEXT[37];
			link.l1 = DLG_TEXT[39] + DLG_TEXT[40];
			link.l1.go = "agreed";
			link.l2 = DLG_TEXT[38];
			link.l2.go = "exit_reject_quest";
		break;

		case "agreed":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "agreed2";
		break;

		case "agreed2":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			AddDialogExitQuest("colombian_silver_hire_byrom");
			Diag.TempNode = "why_are_we_waiting";
			Diag.CurrentNode = "why_are_we_waiting";
			link.l1.go = "exit";
		break;

		case "why_are_we_waiting":
			if (!HasSubStr(PChar.location,"Colombia"))
			{
				dialog.text = DLG_TEXT[45];
				link.l1 = DLG_TEXT[46];
			}
			else
			{
				dialog.text = DLG_TEXT[47];
				link.l1 = DLG_TEXT[48];
			}
			if(CheckQuestAttribute("colombian_silver.got_silver", "true"))
			{
				dialog.text = DLG_TEXT[67];
				link.l1 = DLG_TEXT[68];
			}
			link.l1.go = "exit";
		break;

		case "you_goofed":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "betrayed";
		break;

		case "betrayed":
			OfficersReaction("bad");
			ChangeCharacterReputation(PChar, -1);
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			AddDialogExitQuest("colombian_silver_fight_byrom");
			link.l1.go = "exit";
		break;

		case "join_after_indians":
			dialog.text = GetMyName(PChar) + DLG_TEXT[53];
			link.l1 = pcharrepphrase(DLG_TEXT[54], DLG_TEXT[55]);
			AddDialogExitQuest("colombian_silver_byrom_follows");
			link.l1.go = "exit";
		break;

		case "want_share":
			dialog.text = DLG_TEXT[56] + PChar.quest.colombian_silver.byrom_price + DLG_TEXT[57];
			link.l1 = DLG_TEXT[58] + GetGoodWeightByType(GOOD_SILVER, 300) + DLG_TEXT[59] + GetGoodWeightByType(GOOD_SILVER, makeint(300.0 * (sti(PChar.quest.colombian_silver.byrom_price)/100.0))) + DLG_TEXT[60];
			link.l1.go = "take_share";
			link.l2 = DLG_TEXT[61] + GetMyName(NPChar) + DLG_TEXT[62];
			link.l2.go = "betrayed";
		break;

		case "take_share":
			OfficersReaction("good");
			ChangeCharacterReputation(PChar, 1);
			AddCharacterGoods(PChar, GOOD_SILVER, makeint(-300.0 * (sti(PChar.quest.colombian_silver.byrom_price)/100.0)));
			dialog.text = DLG_TEXT[63] + GetMyName(PChar) + DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit_rehire";
			link.l2 = DLG_TEXT[66];
			link.l2.go = "exit_leave";
		break;
	}
}