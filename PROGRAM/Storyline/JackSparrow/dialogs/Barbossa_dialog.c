//#include "DIALOGS\Barbossa_dialog.h"

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
		case "First_meeting":
			Dialog.defAni = "dialog_stay1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.snd = "voice\RARH\RARH001";
			if (CheckCharacterItem(Pchar,"EITC_Passport"))
			{
				dialog.text = DLG_TEXT[85];
			}
			else
			{
				dialog.text = DLG_TEXT[0] + PChar.lastname + DLG_TEXT[1];
			}
			link.l1 = DLG_TEXT[86];
			link.l1.go = "exit";

		//	AddDialogExitQuest("Barbossa_away_from_residence"); // PB: This doesn't exist???
			NextDiag.TempNode = "first time";
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_stay1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIBE\VIBE001";

			Dialog.mood = "normal";

			dialog.text = DLG_TEXT[0] + DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "exit";
		
			if(CheckQuestAttribute("Jacks_early_days", "Now_Find_CCC"))
			{
				Dialog.snd = "voice\VIBE\VIBE002";
				Dialog.Text = DLG_TEXT[0] + GetMyName(Pchar) + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2];
				Link.l1.go = "meet_Vincent_in_lighthouse_2";
			}
			if (CheckQuestAttribute("main_line", "blaze_goto_douwesen_with_danielle_3"))
			{
				Dialog.snd = "voice\VIBE\VIBE003";
				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11] + characters[GetCharacterIndex(DLG_TEXT[12])].lastname + DLG_TEXT[13];
				link.l1.go = "blaze_goto_douwesen_with_danielle";
			}
			if(CheckQuestAttribute("Beckett", "Decide_to_join_Barbossa") && CheckCharacterItem(Pchar,"aztec_compass"))
			{
				Dialog.snd = "voice\VIBE\VIBE002";
				Dialog.Text = DLG_TEXT[0] + GetMyFullName(Pchar) + DLG_TEXT[58];
				Link.l1 = DLG_TEXT[59];
				Link.l1.go = "meet_Barbossa_at_lighthouse_2";
			}
			if(CheckQuestAttribute("Beckett", "Decide_to_join_Barbossa") && !CheckCharacterItem(Pchar,"aztec_compass"))
			{			
				Dialog.snd = "voice\VIBE\VIBE002";
				Dialog.Text = DLG_TEXT[0] + GetMyFullName(Pchar) + DLG_TEXT[58];
				Link.l1 = DLG_TEXT[59];
				Link.l1.go = "go_get_compass3";
			}
			if (CheckQuestAttribute("Muerte", "just_landed_for_treasure"))
			{
				Dialog.snd = "voice\VIBE\VIBE002";
				Dialog.Text = DLG_TEXT[123];
				Link.l1 = DLG_TEXT[124];
				//Link.l1.go = "Optional_visit_exit";
				Link.l1.go = "exit";
			}
			if (CheckQuestAttribute("Muerte", "just_landed_for_treasure1"))
			{
				Dialog.snd = "voice\VIBE\VIBE002";
				Dialog.Text = DLG_TEXT[20];
				Link.l1 = DLG_TEXT[21];
				//Link.l1.go = "Optional_visit_exit";
				Link.l1.go = "exit";
			}
			if (CheckQuestAttribute("Muerte", "found_the_treasure"))
			{
				Dialog.snd = "voice\VIBE\VIBE002";
				Dialog.Text = DLG_TEXT[125];
				Link.l1 = DLG_TEXT[126];
				Link.l1.go = "found_the_treasure2";
			}
			if (CheckQuestAttribute("Beckett", "Barbossa_enacts_Mutiny"))
			{
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[0] + GetMyName(Pchar) + DLG_TEXT[76] + DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "Mutiny_talk_3";
			}
			NextDiag.TempNode = "first time";
		break;

		case "Talk_Barbossa_French_Beach":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[0] + GetMyFullName(Pchar) + DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "Talk_Barbossa_French_Beach2";				
		break;

		case "Talk_Barbossa_French_Beach2":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[140];
			link.l1.go = "Talk_Barbossa_French_Beach3";				
		break;

		case "Talk_Barbossa_French_Beach3":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[141];
			link.l1 = DLG_TEXT[142];
			link.l1.go = "Talk_Barbossa_French_Beach4";				
		break;

		case "Talk_Barbossa_French_Beach4":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "Exit_French_Beach";				
		break;

		case "Exit_French_Beach":
			AddDialogexitQuest("Annamaria_on_French_Beach");		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "before_vincent_say_about_rheims_2":
			Dialog.snd = "voice\VIBE\VIBE004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15] + characters[GetCharacterIndex(DLG_TEXT[16])].lastname + DLG_TEXT[17];
			link.l1.go = "before_vincent_say_about_rheims_3";
		break;

		case "before_vincent_say_about_rheims_3":
			Dialog.snd = "voice\VIBE\VIBE005";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "before_vincent_say_about_rheims_4";
		break;

		case "before_vincent_say_about_rheims_4":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			pchar.quest.RheimsBook = "vincent_say_about_rheims";
			//SetAfterDialog_Task_Character(NPChar,ADA_DIALOG,"Blaze",true);
		break;

		case "blaze_goto_douwesen_with_danielle":
			Dialog.snd = "voice\VIBE\VIBE007";
			dialog.text = DLG_TEXT[22] + characters[GetCharacterIndex(DLG_TEXT[23])].lastname + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogexitQuest("vincent_exit_from_tavern");
		break;

		case "meet_Vincent_in_lighthouse_2":
			Dialog.snd = "voice\VIBE\VIBE008";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "meet_Vincent_in_lighthouse_3";
		break;

		case "meet_Vincent_in_lighthouse_3":
			Dialog.snd = "voice\VIBE\VIBE009";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "Exit_Barbossa_on_Muelle";
		break;

		case "meet_Vincent_in_lighthouse_4":
			Dialog.snd = "voice\VIBE\VIBE010";
			dialog.text = DLG_TEXT[34] + pchar.name + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "meet_Vincent_in_lighthouse_5";
		break;

		case "meet_Vincent_in_lighthouse_5":
			Dialog.snd = "voice\VIBE\VIBE011";
			dialog.text = characters[GetCharacterIndex(DLG_TEXT[37])].name + DLG_TEXT[38];
			link.l1 = DLG_TEXT[39] + characters[GetCharacterIndex(DLG_TEXT[40])].name + DLG_TEXT[41] + characters[GetCharacterIndex(DLG_TEXT[42])].name + DLG_TEXT[43];
			link.l1.go = "meet_Vincent_in_lighthouse_6";
		break;

		case "meet_Vincent_in_lighthouse_6":
			Dialog.snd = "voice\VIBE\VIBE012";
			dialog.text = DLG_TEXT[44] + characters[GetCharacterIndex(DLG_TEXT[45])].lastname + DLG_TEXT[46] + characters[GetCharacterIndex(DLG_TEXT[47])].name + DLG_TEXT[48];
			link.l1 = DLG_TEXT[49] + characters[GetCharacterIndex(DLG_TEXT[50])].lastname + DLG_TEXT[51];
			link.l1.go = "meet_Vincent_in_lighthouse_7";
		break;

		case "meet_Vincent_in_lighthouse_7":
			Dialog.snd = "voice\VIBE\VIBE013";
			dialog.text = DLG_TEXT[52] + characters[GetCharacterIndex(DLG_TEXT[53])].name + DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "lighthouse_chat_1_exit";
			pchar.quest.main_line = "speak_danielle_in_lighthouse_prepare_to_search_rheims";
		break;

		case "meet_Barbossa_at_lighthouse_2":
//			Locations[FindLocation("Oxbay_lighthouse")].reload.l4.disable = 1;
//			Locations[FindLocation("Oxbay_lighthouse")].reload.l3.disable = 1;		
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "meet_Barbossa_at_lighthouse_3";
		break;

		case "meet_Barbossa_at_lighthouse_3":
			if (CheckQuestAttribute("Mings_quest_KK","Barbossa_alternate_text"))
			{
				Dialog.snd = "voice\VIBE\VIBE006";
				dialog.text = DLG_TEXT[62];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "meet_Barbossa_at_lighthouse_7";
			}
			else
			{
				Dialog.snd = "voice\VIBE\VIBE006";
				dialog.text = DLG_TEXT[62];
				link.l1 = DLG_TEXT[63];
				link.l1.go = "meet_Barbossa_at_lighthouse_4";
			}
		break;

		case "meet_Barbossa_at_lighthouse_4":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "meet_Barbossa_at_lighthouse_5";
		break;

		case "meet_Barbossa_at_lighthouse_5":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "meet_Barbossa_at_lighthouse_6";
		break;

		case "meet_Barbossa_at_lighthouse_6":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "meet_Barbossa_at_lighthouse_7";
		break;

		case "meet_Barbossa_at_lighthouse_7":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "meet_Barbossa_at_lighthouse_7.1";
		break;

		case "meet_Barbossa_at_lighthouse_7.1":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "meet_Barbossa_at_lighthouse_7.2";
		break;

		case "meet_Barbossa_at_lighthouse_7.2":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "meet_Barbossa_at_lighthouse_7.3";
		break;

		case "meet_Barbossa_at_lighthouse_7.3":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "meet_Barbossa_at_lighthouse_8";		
		break;		
		
		case "meet_Barbossa_at_lighthouse_8":
			//PChar.quest.Beckett = "closed";
			//GiveItem2character(PChar, "Map_Doc_4");
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "To Isle de Muerte2";
		break;

		case "go_get_compass3":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "Barbossa_exit";
		break;

		case "Mutiny_talk_2":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "Mutiny_talk_3";
		break;

		case "Mutiny_talk_3":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "Mutiny_talk_4";
		break;

		case "Mutiny_talk_4":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "Mutiny_talk_5";
			GiveItem2Character(Pchar,"Pistol2");
//			EnableEquip(pchar, GUN_ITEM_TYPE, true);
		break;

		case "Mutiny_talk_5":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "Mutiny_exit";
		break;

		case "found_the_treasure":
				Dialog.snd = "voice\VIBE\VIBE002";
				Dialog.Text = DLG_TEXT[125];
				Link.l1 = DLG_TEXT[126];
				Link.l1.go = "found_the_treasure2";
		break;
		
		case "found_the_treasure2":
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "found_the_treasure3";
		break;		

		case "found_the_treasure3":
			dialog.text = DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "found_the_treasure4";
		break;

		case "found_the_treasure4":
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "found_the_treasure5";
		break;

		case "found_the_treasure5":
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "exit_for_Cayman";
		break;

		case "Go_to_find_treasure":
				Dialog.snd = "voice\VIBE\VIBE002";
				Dialog.Text = DLG_TEXT[135];
				Link.l1 = DLG_TEXT[136];
				Link.l1.go = "exit";		
		break;
		
		case "exit_for_Cayman":
			//AddQuestRecord("Hector Barbossa", 7);
			AddQuestRecord("Aztec", 6);
			PChar.quest.Muerte = "closed"
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Barbossa_and_me_back_to_Beach");
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "lighthouse_chat_1_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("second_talk_with_Danielle_at_lighthouse");
		break;
	
		case "Exit_Barbossa_on_Muelle":
			//AddQuestRecord("Hector Barbossa", 9);
			AddQuestRecord("The Brotherhood", 18);
			pchar.quest.Jacks_early_days = "FindCCC_on_shore";		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
//			AddDialogExitQuest("Me_and_Barbossa_In_the_Grotto");
		break;		
		
		case "To Isle de Muerte2":
			PChar.quest.Muerte = "closed"		
			//PChar.quest.Beckett = "closed";
			GiveItem2character(PChar, "Map_Doc_4");		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Barbossa_to_Isle_de_Muerte");
		break;		

		case "Optional_visit_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Me_and_Barbossa_In_the_Grotto");
		break;
		
		case "Mutiny_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Barbossa_leaves_for_now");
		break;

		case "Begin_1":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[87];
//			link.l1 = DLG_TEXT[88] + GetMyFullName(PChar);	// GR: GetMyFullName includes rank with Brotherhood if you have one, e.g. Captain Freebooter Jack Sparrow
			link.l1 = DLG_TEXT[88] + GetMySimpleName(PChar) + ".";
			link.l1.go = "Begin_2";
		break;

		case "Begin_2":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "Begin_3";
		break;

		case "Begin_3":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[107];			
			link.l1.go = "Begin_3A";
		break;

		case "Begin_3A":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];			
			link.l1.go = "Begin_3B";
		break;

		case "Begin_3B":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];			
			link.l1.go = "Begin_3C";
		break;

		case "Begin_3C":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[112] + Pchar.name + DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];			
			link.l1.go = "Begin_3D";
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");			
		break;		
		
		case "Begin_3D":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[115] + Pchar.name + DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];			
			link.l1.go = "exit";
			SetNextWeather("Blue Sky");
			// GR: Moved to "quests_reaction.c", case "insertforchase2", to prevent you from becoming Barbossa while talking to Barbossa
/*
			GiveShip2Character(pchar, SHIP_CURSED, PreprocessText("#scursed_ship#"),-1,PIRATE,true,true);
			AddCharacterGoods(pchar, GOOD_GUNPOWDER, 5000);
			// PB: Become Barbossa -->
			PChar.name = "Hector";
			PChar.lastname = "Barbossa";
			GiveModel2Player("Barbossa",true);
			PChar.Flags.Pirate = 0; // PB: Jack Rackham Pirate Flag (used by Barbossa)
			PChar.Flags.Pirate.texture = 0;
			// PB: Become Barbossa <--
*/
			// GR
			AddDialogExitQuest("insertforchase");
		break;
		
		case "Begin_4":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[92];
			link.l1 = "...";
			link.l1.go = "Begin_4A";
		break;

		case "Begin_4A":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = "...";
			link.l1 = DLG_TEXT[120];
			link.l1.go = "exit";
			AddDialogExitQuest("Turner_Buts_In");
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"), "ShipDeck7", "goto", "goto8"); //"Black_Pearl", "rld", "aloc1");
		break;

		case "Begin_4X":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];			
			link.l1.go = "exit";
			AddDialogExitQuest("allersurilot");			
		break;		
		
		case "Begin_5":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "Begin_6";
		break;

		case "Begin_6":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "Begin_7";
		break;

		case "Begin_7":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "Begin_8";
		break;

		case "Begin_8":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "Begin_9";
		break;

		case "Begin_9":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "Begin_10";
		break;

		case "Begin_10":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[103];
			link.l1.go = "exit";
			AddDialogExitQuest("combatbarbossa");
		break;

		case "Begin_11":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "Begin_12";
		break;

		case "Begin_12":
			Dialog.snd = "voice\VIBE\VIBE006";
			dialog.text = DLG_TEXT[106];
			link.l1.go = "exit";
			if(pchar.model == "depp")
			{
				PChar.quest.Muerte = "noarmour";
				SetModelfromArray(&pchar, GetModelIndex("47_Jack_Skel"));
			}

			if(pchar.model == "depp_A1")
			{
				PChar.quest.Muerte = "armourone";
				SetModelfromArray(&pchar, GetModelIndex("47_Jack_Skel"));
			}

			if(pchar.model == "depp_A2")
			{
				PChar.quest.Muerte = "armourtwo";
				SetModelfromArray(&pchar, GetModelIndex("47_Jack_Skel"));
			}

			if(pchar.model == "depp_A3")
			{
				PChar.quest.Muerte = "armourthree";
				SetModelfromArray(&pchar, GetModelIndex("47_Jack_Skel"));
			}

			AddDialogExitQuest("combatbarbossa2");
		break;
	}
}
