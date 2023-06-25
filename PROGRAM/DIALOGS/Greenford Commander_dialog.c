//#include "DIALOGS\Greenford Commander_dialog.h"

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
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\GRCO\GRCO001";
			dialog.text = DLG_TEXT[0];
			if (pchar.quest.main_line == "to_oxbay_by_prisoner")
			{
				Link.l1 = DLG_TEXT[1] + characters[GetCharacterIndex(DLG_TEXT[2])].name + " " + characters[GetCharacterIndex(DLG_TEXT[3])].lastname + DLG_TEXT[4];
				Link.l1.go = "to_oxbay_by_prisoner_2";
			}
			if (pchar.quest.main_line == "return_idol_from_greenford")
			{
				link.l2 = DLG_TEXT[5] + characters[GetCharacterIndex(DLG_TEXT[6])].lastname + DLG_TEXT[7];
				link.l2.go = "return_idol_from_greenford_2";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher_3"))
			{
				//приказ об освобождении
				link.l2 = DLG_TEXT[8];
				link.l2.go = "freedom_letter";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher"))
			{
				link.l2 = DLG_TEXT[9];
				link.l2.go = "dopros";
			}
			if (CheckQuestAttribute("ANIMISTS", "raskainye"))
			{
				dialog.snd = "Voice\GRCO\GRCO002";
				dialog.text = DLG_TEXT[10];
				link.l2 = DLG_TEXT[11];
				link.l2.go = "exit";
				pchar.quest.ANIMISTS = "dopros";
			}
			//Added by Levis for apothecary quest -->
			if(!CheckAttribute(PChar,"quest.mysterious_plants.reported_crime"))
			{
				if(!CheckAttribute(PChar,"quest.mysterious_plants.crewmember_killed.expired"))
				{
					if(CheckAttribute(PChar,"quest.mysterious_plants.crewmember.killed")) 
					{
						if (GetAttribute(PChar,"quest.mysterious_plants.crewmember.killed")== true)
						{
							link.l3 = DLG_TEXT[53];
							link.l3.go = "Report Indians";
						}
						else
						{
						//if(GetAttribute(PChar,"quest.mysterious_plants.crewmember.killed")== false)
						//{
							link.l3 = DLG_TEXT[56];
							link.l3.go = "Report Indians";
						//}
						}
					}
				}
			}
			else
			{
				if((CheckAttribute(Pchar,"quest.Apothecary_Enter_Warehouse")) && (CheckAttribute(Pchar,"quest.apothecary_no_follow_indian")))
				{
					//PW didn't follow indian to warehouse so nothing to report before/until you sneak round back 
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.Apothecary_Enter_Warehouse")) 
					{
						link.l2 = DLG_TEXT[57];
						link.l2.go = "Report Indians in Warehouse";
					}
					else
					{
						if(CheckAttribute(Pchar,"quest.mysterious_plants.indians.overheard"))
						{
							link.l3 = DLG_TEXT[60];
							link.l3.go = "Report Indians Illegal Trade";
						}				
					}
				}
			}
			//apothecary quest <--
			link.l99 = DLG_TEXT[12];
			link.l99.go = "exit";
			NextDiag.TempNode = "first time";
		break;

		//Added by Levis for apothecary quest -->
		
		case "Report Indians":
			if((CheckAttribute(Pchar,"quest.Apothecary_Enter_Warehouse")) && (!CheckAttribute(Pchar,"quest.apothecary_no_follow_indian")))
			{
				dialog.text = DLG_TEXT[54];
				link.l1 = DLG_TEXT[57];
				link.l1.go = "Report Indians in Warehouse";
				AddQuestRecord("plants", 15);
			}
			else
			{
				AddDialogExitQuest("Reported Indians to guards");
				dialog.text = DLG_TEXT[54];
				link.l1 = DLG_TEXT[55];
				link.l1.go = "exit";
			}
		break;
		
		case "Report Indians in Warehouse":
			AddDialogExitQuest("Reported Indians in Warehouse");
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
		break;
		
		case "Report Indians Illegal Trade":
			dialog.text = DLG_TEXT[61];
			if(CheckCharacterItem(PChar,"vegetal"))
			{
				link.l2 = DLG_TEXT[64];
				link.l2.go = "Report Indians with proof";//PW was exit and vegetal above was opium
			}
			else
			{
			link.l2 = DLG_TEXT[62];
			link.l2.go = "Report Indians without proof";//PW was exit
			}			
			link.l3 = DLG_TEXT[66];
			link.l3.go = "exit";
		break;
		
		case "Report Indians without proof":
			AddDialogExitQuest("Reported Indians without Proof");
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
		break;
		
		case "Report Indians with proof":
			AddDialogExitQuest("Reported Indians with Proof");
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
		break;
		
		//apothecary quest <--

		case "dopros":
			dialog.snd = "Voice\GRCO\GRCO003";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "dopros_2";
		break;

		case "dopros_2":
			dialog.snd = "Voice\GRCO\GRCO004";
			dialog.text = DLG_TEXT[15];
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 3)
			{
				link.l1 = DLG_TEXT[16];
				link.l1.go = "dopros_3";
			}
			link.l2 = DLG_TEXT[17];
			link.l2.go = "dopros_bad";
		break;

		case "dopros_3":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 5)
			{
				dialog.snd = "Voice\GRCO\GRCO005";
				dialog.text = PersuasionSuccess + DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "dopros";
				AddDialogExitQuest("mystery_man_to_prison");
				AddQuestRecord("ANIMISTS", 31);
			}
			else
			{
				dialog.snd = "Voice\GRCO\GRCO006";
				dialog.text = PersuasionFailure + DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];
				link.l1.go = "dopros_4";
			}
		break;

		case "dopros_4":
			dialog.snd = "Voice\GRCO\GRCO007";
			dialog.text = DLG_TEXT[22];
			if (makeint(pchar.money >= 5000))
			{
				link.l1 = DLG_TEXT[23];
				link.l1.go = "money_good";
			}
			link.l2 = DLG_TEXT[24];
			link.l2.go = "dopros_bad";
		break;

		case "dopros_bad":
			dialog.snd = "Voice\GRCO\GRCO008";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "dopros_bad_2";
			link.l2 = DLG_TEXT[27];
			link.l2.go = "exit";
			AddQuestRecord("ANIMISTS", 28);
		break;

		case "dopros_bad_2":
			dialog.snd = "Voice\GRCO\GRCO009";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "dopros_bad_3";
			Preprocessor_AddQuestData("nation", GetNationNameByType(GetTownNation("Greenford")));
			AddQuestRecord("ANIMISTS", 29);
			Preprocessor_Remove("nation");
		break;

		case "dopros_bad_3":
			dialog.snd = "Voice\GRCO\GRCO010";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("prison_commander_captured");
		break;

		case "money_good":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5000);
			dialog.snd = "Voice\GRCO\GRCO011";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "dopros";
			AddDialogExitQuest("mystery_man_to_prison");
			AddQuestRecord("ANIMISTS", 30);
		break;

		case "freedom_letter":
			dialog.snd = "Voice\GRCO\GRCO012";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "freedom_letter";
			TakeItemFromCharacter(PChar,"letter_prison");	// GR: you gave the letter to the commandant
			AddDialogExitQuest("mystery_man_to_prison");
		break;

		case "return_idol_from_greenford_2":
			dialog.snd = "Voice\GRCO\GRCO013";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "return_idol_from_greenford_3";
		break;

		case "return_idol_from_greenford_3":
			dialog.snd = "Voice\GRCO\GRCO014";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("Greenford_commander_fight_exit");
		break;

		case "to_oxbay_by_prisoner_2":
			dialog.snd = "Voice\GRCO\GRCO015";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "to_oxbay_by_prisoner_3";
		break;

		case "to_oxbay_by_prisoner_3":
			dialog.snd = "Voice\GRCO\GRCO016";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
			AddDialogExitQuest("prepare_for_first_meeting_with_researcher");
		break;

// KK -->
		case "capture_of_Greenford":
			dialog.text = DLG_TEXT[44] + " " + GetNationRoyalByType(sti(NPChar.nation)) + " " + DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Exit_capture_of_Greenford";
			AddDialogExitQuest("Story_GreenfordCapturedByBlazeAndDanielle");
		break;

		case "Exit_capture_of_Greenford":
			DialogExit();
			NextDiag.CurrentNode = "First time";
		break;
// <-- KK

		case "release_wolfe":
			dialog.snd = "Voice\GRCO\GRCO001";
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "release_wolfe2";
		break;

		case "release_wolfe2":
			dialog.snd = "Voice\GRCO\GRCO003";
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "release_wolfe3";
		break;

		case "release_wolfe3":
			PlayStereoSound("INTERFACE\writing.wav");
			dialog.snd = "Voice\GRCO\GRCO005";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";
			AddDialogExitQuest("take_wolfe");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
