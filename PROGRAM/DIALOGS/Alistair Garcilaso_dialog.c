//#include "DIALOGS\Alistair Garcilaso_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	// DeathDaisy: Persuasion tags for the skill checks, if enabled
	string PersuasionSuccess = "";
	string PersuasionFailure = "";
	if(PERSUASION_TAGS){ 
		PersuasionSuccess = XI_ConvertString("Persuasion_Success") + " ";
		PersuasionFailure = XI_ConvertString("Persuasion_Failure") + " ";
	}

	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "Sit_Look_Around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Look_Around";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\ALGA\ALGA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_5" || pchar.quest.main_line == "blaze_to_incas_collection_begin")
			{
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
				dialog.snd = "Voice\ALGA\ALGA002";
				Dialog.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "blaze_node_2";
			}
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_4")
			{
				dialog.snd = "Voice\ALGA\ALGA003";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "bad_bad";
			}
			if (CheckQuestAttribute("ANIMISTS","to_greenford"))
			{
				dialog.snd = "Voice\ALGA\ALGA004";
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "ANIMISTS_1_1";
			}
			if (CheckQuestAttribute("ANIMISTS","to_greenford_2"))
			{
				dialog.snd = "Voice\ALGA\ALGA005";
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "ANIMISTS";
			}
			NextDiag.TempNode = "first time";
		break;

		case "ANIMISTS":
			dialog.snd = "Voice\ALGA\ALGA006";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "ANIMISTS_2";
		break;

		case "ANIMISTS_2":
			dialog.snd = "Voice\ALGA\ALGA007";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "ANIMISTS_3";
		break;

		case "ANIMISTS_3":
			dialog.snd = "Voice\ALGA\ALGA008";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "ANIMISTS_4";
		break;

		case "ANIMISTS_4":
			dialog.snd = "Voice\ALGA\ALGA009";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];  // --> Cat
			link.l1.go = "ANIMISTS_5";
		break;
		
		case "ANIMISTS_5":
			dialog.snd = "Voice\ALGA\ALGA013";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "ANIMISTS_exit";
		break;  // <-- Cat

		case "ANIMISTS_1_1":
			dialog.snd = "Voice\ALGA\ALGA010";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "ANIMISTS_2_1";
		break;

		case "ANIMISTS_2_1":
			dialog.snd = "Voice\ALGA\ALGA011";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "ANIMISTS_3_1";
		break;

		case "ANIMISTS_3_1":
			dialog.snd = "Voice\ALGA\ALGA012";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "ANIMISTS_4_1";
		break;

		case "ANIMISTS_4_1":
			dialog.snd = "Voice\ALGA\ALGA013";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];  // --> Cat
			link.l1.go = "ANIMISTS_5_1";
		break;

		case "ANIMISTS_5_1":
			dialog.snd = "Voice\ALGA\ALGA009";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "ANIMISTS_exit";
		break;  // <-- Cat

		case "ANIMISTS_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddQuestRecord("ANIMISTS", 5);
			pchar.quest.ANIMISTS = "after_pirates";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 4000);
				AddPartyExpChar(pchar, "Sneak", 40);
			}
			else { AddPartyExp(pchar, 4000); }
		break;

		case "blaze_node_2":
			dialog.snd = "Voice\ALGA\ALGA014";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "blaze_node_3";
			link.l2 = DLG_TEXT[28];
			link.l2.go = "blaze_node_4";
		break;

		case "blaze_node_3":
			dialog.snd = "Voice\ALGA\ALGA015";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "blaze_node_4";
		break;

		case "blaze_node_4":
			if (characters[GetCharacterIndex("danielle_sailor")].quest.kill_pirate_06 == "done")
			{
				dialog.snd = "Voice\ALGA\ALGA016";
				Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
				dialog.text = DLG_TEXT[31];
				link.l1 = DLG_TEXT[32];
				link.l1.go = "exit";
				pchar.quest.main_line = "kill_pirate_06";
			}
			else
			{
				dialog.snd = "Voice\ALGA\ALGA017";
				dialog.text = DLG_TEXT[33];
				link.l1 = DLG_TEXT[34];
				link.l1.go = "blaze_node_5";
				link.l2 = DLG_TEXT[35];
				link.l2.go = "bad";
			}
		break;

		case "blaze_node_5":
			dialog.snd = "Voice\ALGA\ALGA018";
			dialog.text = DLG_TEXT[36];
			if (makeint(pchar.money) >= 10000)
			{
				link.l1 = DLG_TEXT[37];
				link.l1.go = "exit2";
			}
			link.l2 = DLG_TEXT[38];
			link.l2.go = "trade";
			link.l3 = DLG_TEXT[39];
			link.l3.go = "bad";
		break;

		case "trade":
			if (CalcCharacterSkill(pchar, SKILL_COMMERCE) > 4)
			{
				dialog.snd = "Voice\ALGA\ALGA019";
				dialog.text = PersuasionSuccess + DLG_TEXT[40];
				if (makeint(pchar.money) >= 8000)
				{
					link.l1 = DLG_TEXT[41];
					link.l1.go = "exit3";
				}
			}
			else
			{
				dialog.snd = "Voice\ALGA\ALGA020";
				dialog.text = PersuasionFailure + DLG_TEXT[42];
				if(makeint(pchar.money) >= 10000)
				{
					link.l1 = DLG_TEXT[43];
					link.l1.go = "exit4";
				}
			}
			link.l2 = DLG_TEXT[44];
			link.l2.go = "bad";
		break;


		case "bad":
			dialog.snd = "Voice\ALGA\ALGA021";
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "blaze_node_5";
			link.l2 = DLG_TEXT[47];
			link.l2.go = "bad_2";
		break;
		
		case "bad_2":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 7)
			{
				dialog.snd = "Voice\ALGA\ALGA022";
				dialog.text = PersuasionSuccess + DLG_TEXT[48];
				link.l1 = DLG_TEXT[49];
				link.l1.go = "exit";
				AddDialogExitQuest("alistar_garcilaso_idols");
			}
			else
			{
				if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 3)
				{
					dialog.snd = "Voice\ALGA\ALGA023";
					dialog.text = PersuasionFailure + DLG_TEXT[50];
					link.l1 = DLG_TEXT[51];
					link.l1.go = "fight";
					link.l2 = DLG_TEXT[52];
					link.l2.go = "lie_exit";
				}
				else
				{
					dialog.snd = "Voice\ALGA\ALGA024";
					dialog.text = PersuasionFailure + DLG_TEXT[53];
					link.l1 = DLG_TEXT[54];
					link.l1.go = "fight_2";
					link.l2 = DLG_TEXT[55];
					link.l2.go = "lie_exit_2";
				}
			}
		break;

		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("garcilaso_fight_1");
		break;

		case "fight_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("garcilaso_fight_2");
		break;

		case "lie_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.main_line = "blaze_to_incas_collection_begin_6";
			AddQuestRecord("blaze_to_incas_collection", 7);
		break;

		case "lie_exit_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.main_line = "blaze_to_incas_collection_begin_6";
			AddQuestRecord("blaze_to_incas_collection", 16);
		break;

		case "bad_bad":
			dialog.snd = "Voice\ALGA\ALGA025";
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "bad_bad_2";
		break;

		case "bad_bad_2":
			dialog.snd = "Voice\ALGA\ALGA026";
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "idols_2";
			link.l2 = DLG_TEXT[60];
			link.l2.go = "idols_bad";
		break;

		case "idols_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("alistar_garcilaso_idols_2");
		break;

		case "idols_bad":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("garcilaso_fight_3");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "exit2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("alistar_garcilaso_money");
		break;

		case "exit3":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("alistar_garcilaso_money_2");
		break;

		case "exit4":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("alistar_garcilaso_money");
		break;
	}
}
