//#include "DIALOGS\Edgar Attwood_dialog.h"

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
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\EDAT\EDAT001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			if (npchar.quest.to_hire == "hired")
			{
				dialog.snd = "Voice\EDAT\EDAT002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}

			if (pchar.quest.main_line == "prison")
			{
				dialog.snd = "Voice\EDAT\EDAT003";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "talk_in_prison";
			}
			if (pchar.quest.main_line == "escape_from_redmond_prison")
			{
				AddQuestRecord("Blaze_in_prison", 5);
				dialog.snd = "Voice\EDAT\EDAT004";
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[8];
				link.l2.go = "fight_in_prison";
			}
			if (npchar.quest.to_hire == "possible_to_hire_edgard")
			{
				dialog.snd = "Voice\EDAT\EDAT005";
				dialog.text = DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go  = "to_hire_1";
			}
			if (npchar.quest.to_hire == "wait_for_hire" && pchar.location == "Redmond_port")
			{
				dialog.snd = "Voice\EDAT\EDAT006";
				dialog.text = DLG_TEXT[11];
				link.l1 = DLG_TEXT[12];
				link.l1.go = "to_hire_2";
				link.l2 = DLG_TEXT[13];
				link.l2.go = "not_hire_exit";
			}
			NextDiag.TempNode = "first time";

//NK re-enable Attwood quests -->
			if(!CheckAttribute(Pchar,"quest.Attwood")) //Added check so quest is only started once
			{
				Pchar.quest.Attwood.win_condition.l1 = "location";
				Pchar.quest.Attwood.win_condition.l1.character = "Edgar Attwood";  
				Pchar.quest.Attwood.win_condition.l1.location = "Greenford_port";
				PChar.quest.Attwood.win_condition = "Attwood_Adventure";
			}
// NK second section transferred
//NK <--

		break;

		case "to_hire_1":
			dialog.snd = "Voice\EDAT\EDAT007";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "to_hire_2";
		break;

		case "to_hire_2":
			dialog.snd = "Voice\EDAT\EDAT008";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[16];
			if (makeint(pchar.money) >= 2000)
			{
				link.l1 = DLG_TEXT[17];
				link.l1.go = "exit_to_hire";
			}
			link.l2 = DLG_TEXT[18];
			link.l2.go = "exit";
		break;

		case "talk_in_prison":
			dialog.snd = "Voice\EDAT\EDAT009";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "talk_in_prison_2";
		break;

		case "talk_in_prison_2":
			dialog.snd = "Voice\EDAT\EDAT010";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "talk_in_prison_3";
		break;

		case "talk_in_prison_3":
			dialog.snd = "Voice\EDAT\EDAT011";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "talk_in_prison_4";
		break;

		case "talk_in_prison_4":
			dialog.snd = "Voice\EDAT\EDAT012";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "talk_in_prison_right";
		break;

		case "talk_in_prison_right":
			dialog.snd = "Voice\EDAT\EDAT013";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "talk_in_prison_right_2";
		break;

		case "talk_in_prison_right_2":
			dialog.snd = "Voice\EDAT\EDAT014";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "talk_in_prison_right_3";
		break;

		case "talk_in_prison_right_3":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 4)
			{
				dialog.snd = "Voice\EDAT\EDAT015";
				dialog.text = PersuasionSuccess + DLG_TEXT[31];
				link.l1 = DLG_TEXT[32] + GetMyShipNameShow(PChar) + DLG_TEXT[33];
				link.l1.go = "talk_in_prison_right_4";
				AddQuestRecord("Blaze_in_prison", "2");
			}
			else
			{
				dialog.snd = "Voice\EDAT\EDAT016";
				dialog.text = PersuasionFailure + DLG_TEXT[34];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "exit";
				AddQuestRecord("Blaze_in_prison", 3);
				AddDialogExitQuest("edgar_attwood_exit_from_blaze");
			}
		break;

		case "talk_in_prison_right_4":
			dialog.snd = "Voice\EDAT\EDAT017";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit_from_cam";
		break;

		case "exit_to_hire":
//			SetOfficersIndex(PChar, -1, sti(NPChar.index));
			if (SetOfficersIndex(PChar, -1, sti(NPChar.index)) == sti(NPChar.index))
			{
				AddPassenger(PChar, NPChar, 0); // GR: if unable to assign to free officer slot, make him passenger instead
				Characters[sti(NPChar.index)].location = "none";
			}
			LAi_SetOfficerType(NPChar);
			//ChangeCharacterAddress(npchar, "none", "none");
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(pchar, -1500);
			npchar.quest.to_hire = "hired";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_from_cam":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			//выводим игрока из камеры
			pchar.gun = "gun";
			pchar.blade = "saber";
			npchar.quest.to_hire = "wait_for_hire";
			
			AddDialogExitQuest("prepare_exit_from_cam");
		break;

		case "fight_in_prison":
			AddDialogExitQuest("kill_edgard_in_prison_complete");
			//pchar.quest.kill_edgar_in_prison.win_conddition = "kill_edgard_in_prison_complete";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Setup1":
			dialog.Text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "continue";
		break;

		case "continue":
			dialog.snd = "Voice\EDAT\EDAT018";
			dialog.Text = DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "continue1";	
		break;

		case "continue1":
			dialog.snd = "Voice\EDAT\EDAT019";
			dialog.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "continue2";
			Link.l2 = DLG_TEXT[44];
			Link.l2.go = "continue3";
		break;

		case "continue2":
			dialog.snd = "Voice\EDAT\EDAT020";
			ChangeCharacterReputation(pchar, -2);
			characters[GetCharacterIndex("Edgar Attwood")].loyality = makeint(characters[GetCharacterIndex("Edgar Attwood")].loyality) - 1;
			// NK -->
			SetOfficersIndex(PChar, -1, sti(NPChar.index));
			LAi_SetOfficerType(NPChar);
			LAi_SetPlayerType(PChar);
			// NK <--
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			dialog.Text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[46];
			Link.l1.go = "exit";
		break;

		case "continue3":
			LAi_QuestDelay("Attwood_fight1", 0.01);
// NK -->
			Pchar.quest.Attwood1.win_condition.l1 = "location";
			Pchar.quest.Attwood1.win_condition.l1.character = "Edgar Attwood";
			Pchar.quest.Attwood1.win_condition.l1.location = "Redmond_port";
			Pchar.quest.Attwood1.win_condition = "redmond_Attwood";
// NK <--
			DialogExit();
		break;

		case "setup2":
//			Log_SetStringToLog("Сделать историю с девкой (может быть)");
			LAi_QuestDelay("redmond_Attwood", 4.0);
		break;
		
		case "not_hire_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("edgar_go_on_the_port");
		break;
	}
}
