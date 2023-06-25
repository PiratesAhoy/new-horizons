//#include "DIALOGS\Isenbrandt Jurcksen_dialog.h"

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
	
	Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
	Preprocessor_Add("lad", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false)); // DeathDaisy

	
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- -иалог первый - первая вс=реча
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

			NextDiag.TempNode = "first time";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			// NK -->
			if(GetNationRelation2MainCharacter(PIRATE) != RELATION_ENEMY && HaveLetterOfMarque(PIRATE)) // PB: Added LoM check
			{
				dialog.text = DLG_TEXT[42];
			}
			// NK <--
			if (GetNationRelation2MainCharacter(PIRATE) != RELATION_ENEMY && !HaveLetterOfMarque(PIRATE)) // PB
			{
				if (makeint(GetLetterOfMarqueQuantity()) == 0 || GetCurrentPeriod() < PERIOD_GOLDEN_AGE_OF_PIRACY) // PB + GR
				{
					dialog.text = DLG_TEXT[34];
					link.l1 = DLG_TEXT[35];
					link.l1.go = "piratefun";
					link.l2 = DLG_TEXT[36];
					link.l2.go = "exit";
				}
			}

			if ( CheckQuestAttribute("story_FindRheims_IsenbrandtTask","pirate_arrest") )
			{
				AddDialogExitQuest("Herald_from_Redmond_comming_to_Isenbrandt");
				dialog.text = DLG_TEXT[2] + Characters[getCharacterIndex(DLG_TEXT[3])].lastname + DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "AskingAboutRheims";
				PChar.quest.story_FindRheims_IsenbrandtTask = "neutral";
			}
			if ( CheckQuestAttribute("story_FindRheims_IsenbrandtTask","enemy") )
			{
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "exit";
				AddDialogExitQuest("Herald_already_prevent_Isenbrandt");
			}


			if (pchar.quest.main_line == "letter_to_Isenbrandt")
			{
				if (makeint(pchar.reputation) > 60 || makeint(pchar.reputation) < 30)
				{
					Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
					dialog.text = pcharrepphrase(DLG_TEXT[8] + GetMyName(Pchar) + DLG_TEXT[9], DLG_TEXT[10] + GetMyName(Pchar) + DLG_TEXT[11]);
					link.l1 = pcharrepphrase(DLG_TEXT[12], DLG_TEXT[13]);
					link.l1.go = "node_2";
				}
				else
				{			
					dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15] + GetMyFullName(PChar) + DLG_TEXT[16];
					link.l1.go = "node_2";
				}
			}
		break;

		case "node_2":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "node_3";
		break;

		case "node_3":
			if(PChar.sex == "woman") Preprocessor_Add("child", XI_ConvertString("girl"));
			else Preprocessor_Add("child", XI_ConvertString("boy"));
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20] + characters[GetCharacterIndex(DLG_TEXT[21])].lastname + DLG_TEXT[22];
			link.l1.go = "node_4";
		break;

		case "node_4":
			dialog.text = characters[GetCharacterIndex(DLG_TEXT[23])].lastname + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "letter_to_Isenbrandt_complete_node";
			pchar.quest.main_line = "letter_to_Isenbrandt_complete";
			AddQuestRecord("blaze_to_Isenbrandt", 2);
		break;

		case "AskingAboutRheims":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "AskingAboutRheims_1";		
		break;

		case "AskingAboutRheims_1":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "AskingAboutRheims_2";		
		break;

		case "AskingAboutRheims_2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "AskingAboutRheims_3";		
		break;

		case "AskingAboutRheims_3":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";		
		break;

		case "piratefun": //<<------------------this node was added, love verruckt
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "piratefun2";
			link.l2 = DLG_TEXT[39];
			link.l2.go = "exit";
			//AddDialogExitQuest("piratefun");
		break;

		case "piratefun2": //<<------------------this node was added, love verruckt
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("piratefun");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
