//#include "DIALOGS\Annamaria_dialog.h"

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

			Dialog.mood = "normal";

			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit";
		break;

		case "At_Tortuga_after_Loosing_Ship":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "ChatterOn_2";
		break;
		
		case "ChatterOn":
            dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "ChatterOn_2";
		break;

		case "ChatterOn_2":
			GiveItem2Character(Pchar,"aztec_compass");
			GiveShip2Character(pchar,"Tartane50","Jolly Mon",-1,PIRATE,true,true);
			AddDialogExitQuest("Tortuga_Meet_Annamaria_for_ship4");
			SetCharacterShipLocation(Pchar, "Tortuga_Port");
            dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "ChatterOn_3":
			GiveItem2Character(Pchar,"aztec_compass");
            dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			GiveShip2Character(pchar,"Tartane50","Jolly Mon",-1,PIRATE,true,true);
			AddQuestRecord("Hector Barbossa", 8);
			pchar.quest.And_the_Film_Starts.win_condition.l1 = "location";
			pchar.quest.And_the_Film_Starts.win_condition.l1.location = "Redmond";
			pchar.quest.And_the_Film_Starts.win_condition = "And_the_Film_Starts";
			link.l1.go = "exit";     
		break;

		case "holdfornow":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("gifleAnnamaria");
		break;

		case "begin_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
		break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("interceptorgift");
		break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";
		break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1.go = "exit";
			AddDialogExitQuest("partirtortuebis");
		break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "begin_6";
		break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("giflecrewb");
		break;
 
		case "Talk_Annamaria_Oxbay":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Talk_Annamaria_Oxbay2";
 			link.l2 = DLG_TEXT[22];
			link.l2.go = "exit_Oxbay_meet2";                     
		break;
 
		case "Talk_Annamaria_Oxbay2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit_Oxbay_meet";
		break;
  
 		case "We_have_a_treasure_map":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "We_have_a_treasure_map2";
		break;
 
 		case "We_have_a_treasure_map2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[27];
			if (!CheckCharacterItem(Pchar,"Map_Doc_3") && !CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
			link.l1 = DLG_TEXT[84];
			link.l1.go = "exit_one_piece";
			}
			if (CheckCharacterItem(Pchar,"Map_Doc_3") && !CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
			link.l1 = DLG_TEXT[28];
			link.l1.go = "We_have_a_treasure_map3";
			}
			if (CheckCharacterItem(Pchar,"Map_Doc_3") && CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
			link.l1 = DLG_TEXT[29];
			link.l1.go = "We_have_a_treasure_map3.5";
			}
		break;
 
		case "We_have_a_treasure_map3": //Two parts of map
			int tmpdiamond = GetCharacterItem(pChar, "jewelry2");
			dialog.snd = "Voice\CLLA\CLLA004";
			if (tmpdiamond >= 2)
			{			
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "We_have_a_treasure_map4";
			}
			if (tmpdiamond <= 1)
			{
			if(makeint(PChar.money)>=1000)
				{
				dialog.text = DLG_TEXT[30];
				link.l1 = DLG_TEXT[32];
				link.l1.go = "We_have_a_treasure_map5";
				}
			if(makeint(PChar.money)<=999)
				{
				dialog.text = DLG_TEXT[30];
				link.l1 = DLG_TEXT[33];
				link.l1.go = "exit";
				}
			}
		break;
 
		case "We_have_a_treasure_map3.5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "We_have_a_treasure_map6";
			AddQuestRecord("Aztec", 11);  // TALISMAN added
		break;

		case "We_have_a_treasure_map4":
			dialog.snd = "Voice\CLLA\CLLA004";
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "We_have_a_treasure_map6";
			AddQuestRecord("Aztec", 11);  // TALISMAN added
		break;

 		case "We_have_a_treasure_map5":
			dialog.snd = "Voice\CLLA\CLLA004";
			AddMoneyToCharacter(pchar, -1000);
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "We_have_a_treasure_map6";
			AddQuestRecord("Aztec", 11);  // TALISMAN added
		break;

		case "We_have_a_treasure_map6":
			dialog.snd = "Voice\CLLA\CLLA004";
			if(CheckCharacterItem(Pchar,"aztec_compass") && CheckCharacterItem(Pchar,"Map_Doc_1") && CheckCharacterItem(Pchar,"Map_Doc_3"))
			{
				dialog.text = DLG_TEXT[38];
				link.l1 = DLG_TEXT[39];
				link.l1.go = "We_have_a_treasure_map7";
			}
			if(!CheckCharacterItem(Pchar,"aztec_compass"))
			{
				if (CheckCharacterItem(Pchar,"Map_Doc_1") && CheckCharacterItem(Pchar,"Map_Doc_3"))
				{
					dialog.text = DLG_TEXT[55];
					link.l1 = DLG_TEXT[56];
					link.l1.go = "Need_to_get_compass";
				}
				else
				{
					dialog.text = DLG_TEXT[80];
					link.l1 = DLG_TEXT[81];
					link.l1.go = "Need_to_get_compass_and_map";
				}
			}
		break;

		case "We_have_a_treasure_map7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "We_have_a_treasure_map8";
		break;

		case "We_have_a_treasure_map8":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "We_have_a_treasure_map9";
		break;

		case "We_have_a_treasure_map9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "We_have_a_treasure_map10";
		break;

		case "We_have_a_treasure_map10":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Exit_treasure_map";
			link.l2 = DLG_TEXT[48];
			link.l2.go = "Exit";
		break;

		case "Need_to_get_compass":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "Exit_need_compass";
		break;

		case "Need_to_get_compass_and_map":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Exit_need_compass";
		break;

		case "This_smells_to_me":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "This_smells_to_me2";
		break;

		case "This_smells_to_me2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "This_smells_to_me3";
		break;

		case "This_smells_to_me3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Exit_This_smells_to_me";
		break;

		case "Got_the_compass_now":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "We_have_a_treasure_map6";
		break;

		case "Talk_on_French_Beach":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "Talk_on_French_Beach2";
		break;

		case "Talk_on_French_Beach2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "Exit_Talk_on_French_Beach";
		break;

		case "Looking_for_Nathan_Kell":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66] + getmyfullname(Pchar) + DLG_TEXT[67];
			link.l1.go = "Looking_for_Nathan_Kell2";
		break;

// VVVVVVVVVV - TALISMAN changed to check if player already has Map_Doc_2 from Petros - so it is not given twice VVVV
		
		case "Looking_for_Nathan_Kell2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[68];
			if (CheckCharacterItem(Pchar,"Map_Doc_2"))
			{
			link.l1 = DLG_TEXT[69];
			link.l1.go = "Looking_for_Nathan_Kell2A";
			}
			else
			{
			link.l1 = DLG_TEXT[69];
			link.l1.go = "Looking_for_Nathan_Kell3";
			}
		break;
		
		case "Looking_for_Nathan_Kell2A":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "Looking_for_Nathan_Kell4";
		break;
		
		case "Looking_for_Nathan_Kell3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "Looking_for_Nathan_Kell4";

//			AddQuestRecord("Aztec", 3); TALISMAN - wrong QB text
			AddQuestRecord("Aztec", 12);
			GiveItem2Character(Pchar,"Map_Doc_2");
		break;
		
// ^^^^^^^^^^^^^^^^^TALISMAN - ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

		case "Looking_for_Nathan_Kell4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "Exit_Looking_for_Nathan_Kell";
		break;

		case "standard_story_setup":
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "standard_story_setup2";
		break;

		case "standard_story_setup2":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "Exit_standard_story_setup";
		break;

		case "Exit_standard_story_setup":
			if (GetAttribute(pchar, "Aztec") != "1")
			{
				SetQuestHeader("Aztec");
				pchar.aztec = "1";
			}
			AddQuestRecord("Aztec", 7);
			GiveItem2Character(Pchar,"Map_Doc_2");
			AddDialogExitQuest("Annamaria_standard_story2");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Talk_on_French_Beach":
			DialogExit();
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annamaria"));
			RemovePassenger(pchar, characterFromID("Annamaria"));
			LAi_SetActorType(characterFromID("Annamaria"));
			LAi_ActorRunToLocator(characterFromID("Annamaria"), "goto", "locator26", "", 30.0);
			AddDialogExitQuest("Back_to_Lighthouse_yet_again");
		break;

		case "Exit_Talk_on_French_BeachTwo":
            AddDialogExitQuest("Back_to_Lighthouse_yet_again");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_need_compass":
            AddDialogExitQuest("Looking for Compass");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Exit_This_smells_to_me":
            AddDialogExitQuest("Information_on_Barbossa2");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Exit_treasure_map":
			AddDialogExitQuest("Hunt_the_Volcano");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "exit_Oxbay_meet":
			pchar.Annamaria = "Lighthouse";
			AddQuestRecord("Aztec", 3);
            AddDialogExitQuest("Annamaria_leaves_Oxbay");
			GiveItem2Character(Pchar,"Map_Doc_2");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "exit_Oxbay_meet2":
            AddDialogExitQuest("Annamaria_leaves_Oxbay");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Looking_for_Nathan_Kell":
			AddDialogExitQuest("Nathan_Kell_in_Oxbay");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
        case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_one_piece":
			DialogExit();
			NextDiag.CurrentNode = "We_have_a_treasure_map";
			LAi_SetStayType(characterfromID("Annamaria"));
		break;

        case "exit_now_slap_me":
			AddDialogExitQuest("gifleannamaria");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
