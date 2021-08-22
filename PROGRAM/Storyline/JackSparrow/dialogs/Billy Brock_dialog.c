//#include "DIALOGS\Billy Brock_dialog.h"
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
			Dialog.defAni = "Sit_Look_Around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Look_Around";
			Dialog.cam = "1";

			Dialog.mood = "normal";
			PlaySound("VOICE\ENGLISH\Eng_m_a_017.wav");
			dialog.snd = "Voice\BIBR\BIBR001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if(checkquestattribute("Jacks_early_days", "first_meeting"))		
			{
				dialog.snd1 = "Voice\HENR\HENR020";
				dialog.snd2 = "Voice\HENR\HENR021";
				dialog.snd3 = "Voice\HENR\HENR022";
				
				dialog.Text = DLG_TEXT[15];
				Link.l1 = DLG_TEXT[16];
				Link.l1.go = "Shortcut_exit1";
				Link.l2 = DLG_TEXT[17];
				Link.l2.go = "Shortcut_exit3";
				Link.l3 = DLG_TEXT[18];
				Link.l3.go = "TheQuestLine";
				Link.l4 = DLG_TEXT[19];
				Link.l4.go = "exit";
			}
			if(checkquestattribute("Jacks_early_days", "narrow_squeak_over"))
			{
				dialog.snd = "Voice\BIBR\BIBR002";
				Dialog.Text = DLG_TEXT[42];
				Link.l1 = DLG_TEXT[43];
				Link.l1.go = "Explanation";
			}
			if(checkquestattribute("henry_talk", "for_game_shortcuts"))
			{
				dialog.snd1 = "Voice\HENR\HENR020";
				dialog.snd2 = "Voice\HENR\HENR021";
				dialog.snd3 = "Voice\HENR\HENR022";

				dialog.Text = DLG_TEXT[15];
				Link.l1 = DLG_TEXT[16];
				Link.l1.go = "Shortcut_exit1";
				Link.l2 = DLG_TEXT[17];
				Link.l2.go = "Shortcut_exit3";
				Link.l3 = DLG_TEXT[48];
				Link.l3.go = "ShortCuttoQuestOptions";
				Link.l4 = DLG_TEXT[19];
				Link.l4.go = "exit";
			}
			if(checkquestattribute("henry_talk", "nothing"))
			{
				dialog.snd1 = "Voice\HENR\HENR020";
				dialog.snd2 = "Voice\HENR\HENR021";
				dialog.snd3 = "Voice\HENR\HENR022";
				dialog.text = DLG_TEXT[20];
				Link.l1 = DLG_TEXT[21];
				Link.l1.go = "Shortcut_exit1";
			}
		break;

		case "Talk_in_Tavern":
			dialog.snd = "Voice\BIBR\BIBR003";
			Dialog.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Exit";
		break;

		case "Greenford_Tavern_Meeting":
				dialog.snd = "Voice\BIBR\BIBR002";
				Dialog.Text = DLG_TEXT[42];
				Link.l1 = DLG_TEXT[43];
				Link.l1.go = "Explanation";
		break;

		case "Explanation":
//			AddQuestRecord("My Early Days",1);
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Exit_to_upstairs";
		break;		

		case "Exit_to_upstairs":
//			AddQuestRecord("My Early Days",3);
			DialogExit();
			AddDialogExitQuest("Talk_upstairs");
		break;	

		case "Talk_in_Tavern":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Exit_Anna";
		break;

		case "Exit_Anna":
			AddQuestRecord("My Early Days",4);
			DialogExit();
			AddDialogExitQuest("Talk_Annabella_Upstairs");
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "TheQuestLine":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "TheQuestLine2";
			Link.l2 = DLG_TEXT[23];
			Link.l2.go = "Shortcut_exit1";
		break;	

		case "TheQuestLine2":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "Meet_the_lady";
		break;
	
		case "Meet_the_lady":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "Meet_the_lady2";
		break;

		case "Meet_the_lady2":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[29];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Meet_the_lady3";
			Link.l2 = DLG_TEXT[30];
			Link.l2.go = "Shortcut_exit1";
		break;

		case "Meet_the_lady3":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "Shortcut_exit2";
		break;	

		case "The_Brock_fight_Oxbay":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[64] + GetMyFullName(PChar) + DLG_TEXT[65];
			Link.l1 = DLG_TEXT[66];
			Link.l1.go = "The_Brock_fight2";
		break;

		case "The_Brock_fight2":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[67];
			Link.l1 = DLG_TEXT[68];
			Link.l1.go = "Exit_Brock_fight";
		break;

		case "Exit_Brock_fight":
			Pchar.Quest.On_to_the_Tailors2.over = "yes";
			Pchar.Quest.to_find_a_sister.over = "yes";
			Pchar.Quest.to_find_a_sisterA.over = "yes";
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brin"));
			RemovePassenger(pchar, characterFromID("Annabella Brin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brinkley"));
			RemovePassenger(pchar, characterFromID("Annabella Brinkley"));
			RemoveCharacterCompanion(pchar, characterFromID("Annabella Brinkley"));
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Brock_is_Killed");
		break;
		
		case "Shortcut_exit1":
			pchar.quest.Jacks_early_days = "nothing";
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Shortcut_exit2":
			pchar.quest.Jacks_early_days = "trouble_with_the_ladies";
			AddQuestRecord("My Early Days",2);
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("On_to_the_Tailors");
		break;		

		case "Shortcut_exit3":
			ChangeCharacterReputation(pchar, +1);
			pchar.quest.henry_talk = "nothing";
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "ShortCuttoQuestOptions":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[52];
			Link.l2.go = "Shortcut_Options";
		break;

		case "Shortcut_Options":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[69];
			Link.l2.go = "Wicked Wench";
			Link.l3 = DLG_TEXT[75];
			Link.l3.go = "Testing Storm";
			Link.l4 = DLG_TEXT[77];
			Link.l4.go = "Ragetti_Pintel";
			Link.l5 = DLG_TEXT[73];
			Link.l5.go = "Barbossa_Mutiny_Option";
			Link.l6 = DLG_TEXT[71];
			Link.l6.go = "Jacks_Grand_Entrance";
			Link.l7 = DLG_TEXT[70];
			Link.l7.go = "DMC";
			Link.l8 = DLG_TEXT[79];
			Link.l8.go = "Jungle_Church";
		break;

		case "Testing Storm":
			Dialog.Text = DLG_TEXT[76];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Testing Storm2";
		break;

		case "Testing Storm2":
			// Set up actual beginning
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			SetRelationsAsNation(ENGLAND); // PB: Set nations as per selected flag
			SetRMRelation(PChar, ENGLAND, REL_AFTERATTACK); // PB: England no longer trusts you
			SetServedNation(PERSONAL_NATION); // PB: And you are no longer loyal to them
			GiveModel2Player("47YoungJack",false);
			GiveModel2Player("depp",true);
			GiveShip2Character(pchar,"WickedWench","Wicked Wench",-1,ENGLAND,true,true);
			PChar.quest.wench_given_by = "Beckett";
			SetCharacterShipLocation(Pchar, "Oxbay_lighthouse");
			pchar.jack = "Meet_tia";
			PChar.Flags.Personal = 1; // PB: Non-British Jack-flag
			PChar.Flags.Personal.texture = 3;
			PChar.Flags.Pirate = 6; // PB: Jack Sparrow Pirate Flag
			PChar.Flags.Pirate.texture = 0;

			// Restore stuff
			DeleteAttribute(&Locations[FindLocation("Tortuga_Port")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Tortuga_Tavern")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cayman_Port")],"vcskip");
			Pchar.dialog.filename = "blaze_dialog.c";
			ChangeCharacterAddressGroup(CharacterFromID("Storyteller"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Random Drunk"), "none", "", "");
			DisableFastTravel(false);
			Locations[FindLocation("Tortuga_port")].reload.l2.disable = 0;

			GiveItem2Character(Pchar,"aztec_compass");
			GiveItem2Character(Pchar,"EITC_Passport");
			
			// TALISMAN - to give bits of map to open Muerte Treasure Cave  ( bit 4 with Barbossa not met him yet )-->
			GiveItem2Character(Pchar,"Map_Doc_1");
			GiveItem2Character(Pchar,"Map_Doc_2");
			GiveItem2Character(Pchar,"Map_Doc_3");
			// <--- TALISMAN
			
			PlayStereoSound("INTERFACE\took_item.wav");
			//pchar.davy = "helped";

			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Back_to_Lighthouse_from_Turks2");
			DoReloadCharacterToLocation("Oxbay_lighthouse", "reload", "reload3");
		break;

		case "Ragetti_Pintel":
			Dialog.Text = DLG_TEXT[78];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Ragetti_Pintel2";
		break;

		case "Ragetti_Pintel2":
			// Set up actual beginning
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			AddDialogExitQuest("piratefun"); // PB: You have joined the pirates
			GiveModel2Player("47YoungJack",false);
			GiveModel2Player("depp",false);
			GiveModel2Player("Jack",true);
			GiveShip2Character(pchar,"BlackPearl",TranslateString("Black Pearl",""),-1,PIRATE,true,true);
			PChar.quest.wench_given_by = "Beckett";
			pchar.Jack = "Pirate";
			PChar.Flags.Personal = 1; // PB: Non-British Jack-flag
			PChar.Flags.Personal.texture = 3;
			PChar.Flags.Pirate = 6; // PB: Jack Sparrow Pirate Flag
			PChar.Flags.Pirate.texture = 0;

			// Restore stuff
			DeleteAttribute(&Locations[FindLocation("Tortuga_Port")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Tortuga_Tavern")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cayman_Port")],"vcskip");
			Pchar.dialog.filename = "blaze_dialog.c";
			ChangeCharacterAddressGroup(CharacterFromID("Storyteller"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Random Drunk"), "none", "", "");
			DisableFastTravel(false);
			Locations[FindLocation("Tortuga_port")].reload.l2.disable = 0;

			GiveItem2Character(Pchar,"aztec_compass");
			GiveItem2Character(Pchar,"EITC_Passport");
			
			// TALISMAN - to give bits of map to open Muerte Treasure Cave  ( bit 4 with Barbossa not met him yet )-->
			GiveItem2Character(Pchar,"Map_Doc_1");
			GiveItem2Character(Pchar,"Map_Doc_2");
			GiveItem2Character(Pchar,"Map_Doc_3");
			// <--- TALISMAN
			
			PlayStereoSound("INTERFACE\took_item.wav");

			SetQuestHeader("Davy Jones");
			AddQuestRecord("Davy Jones",1);

			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Find_Barbossa_with_Black_Pearl");
		break;

		case "Barbossa_Mutiny_Option":
			Dialog.Text = DLG_TEXT[74];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Barbossa_Mutiny_Option2";
		break;

		case "Barbossa_Mutiny_Option2":
			// Set up actual beginning
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			AddDialogExitQuest("piratefun"); // PB: You have joined the pirates
			GiveModel2Player("47YoungJack",false);
			GiveModel2Player("depp",false);
			GiveModel2Player("Jack",true);
			GiveShip2Character(pchar,"BlackPearl",TranslateString("Black Pearl",""),-1,PIRATE,true,true);
			PChar.quest.wench_given_by = "Beckett";
			pchar.Jack = "Pirate";
			PChar.Flags.Personal = 1; // PB: Non-British Jack-flag
			PChar.Flags.Personal.texture = 3;
			PChar.Flags.Pirate = 6; // PB: Jack Sparrow Pirate Flag
			PChar.Flags.Pirate.texture = 0;

			// Restore stuff
			DeleteAttribute(&Locations[FindLocation("Tortuga_Port")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Tortuga_Tavern")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cayman_Port")],"vcskip");
			Pchar.dialog.filename = "blaze_dialog.c";
			ChangeCharacterAddressGroup(CharacterFromID("Storyteller"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Random Drunk"), "none", "", "");
			DisableFastTravel(false);
			Locations[FindLocation("Tortuga_port")].reload.l2.disable = 0;
			
			// TALISMAN - to give bits of map to open Muerte Treasure Cave -->
			GiveItem2Character(Pchar,"Map_Doc_1");
			GiveItem2Character(Pchar,"Map_Doc_2");
			GiveItem2Character(Pchar,"Map_Doc_3");
			GiveItem2Character(Pchar,"Map_Doc_4");
			// <--- TALISMAN

			// Enable sidequests
			PChar.Rag = "1";
			ChangeCharacterAddressGroup(CharacterFromID("Captaine Chevalle"), "PoPrince_tavern", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("Eduardo Villanueva"), "Tortuga_Brothel_room", "goto", "locator3");
			ChangeCharacterAddressGroup(CharacterFromID("Sumbhajee"), "Havana_Tavern", "sit", "sit19");
			ChangeCharacterAddressGroup(CharacterFromID("Sumbhajee Aid1"), "Havana_Tavern", "goto", "goto7");
			pchar.quest.ANIMISTS = "1";
			PChar.quest.Story_Artois_Nigel.win_condition.l1 = "location";
			PChar.quest.Story_Artois_Nigel.win_condition.l1.character = PChar.id;
			PChar.quest.Story_Artois_Nigel.win_condition.l1.location = "Oranjestad_town";
			PChar.quest.Story_Artois_Nigel.win_condition = "Install_Voysey_And_Blythe";

			Dialog.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("before_first_marooning");
		break;

		case "Wicked Wench":
			// Set up actual beginning
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			SetRelationsAsNation(ENGLAND); // PB: Set nations as per selected flag
			GiveModel2Player("47YoungJack",true);
			GiveModel2Player("depp",false);
			GiveShip2Character(pchar,"Cutter2","Spreading Freedom",-1,ENGLAND,true,true);
			SetCharacterShipLocation(Pchar, "Oxbay_Port");
			pchar.Jack = "early_days";
			HoistFlag(PERSONAL_NATION);
			PChar.Flags.Personal = 1; // PB: Non-British Jack-flag
			PChar.Flags.Personal.texture = 3;
			PChar.Flags.Pirate = 6; // PB: Jack Sparrow Pirate Flag
			PChar.Flags.Pirate.texture = 0;

			// Restore stuff
			DeleteAttribute(&Locations[FindLocation("Tortuga_Port")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Tortuga_Tavern")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cayman_Port")],"vcskip");
			Pchar.dialog.filename = "blaze_dialog.c";
			ChangeCharacterAddressGroup(CharacterFromID("Storyteller"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Random Drunk"), "none", "", "");
			DisableFastTravel(false);
			Locations[FindLocation("Tortuga_port")].reload.l2.disable = 0;

			GiveItem2Character(Pchar,"Map_Doc_3");  // TALISMAN - To give bit of map obtained from Eastwood - Skull - needed to open Muerte Treasure Cave.
			Pchar.Quest.to_find_a_sister.over = "yes";
			Pchar.Quest.to_find_a_sisterA.over = "yes";
			Dialog.CurrentNode = "First time";
			DialogExit();
			DoQuestReloadToLocation("Mings_townhall", "Reload", "Reload1", "The_sisters_found");
		break;

		case "DMC":
			// Set up actual beginning
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			AddDialogExitQuest("piratefun"); // PB: You have joined the pirates
			GiveModel2Player("47YoungJack",false);
			GiveModel2Player("depp",false);
			GiveModel2Player("Jack",true);
			GiveShip2Character(pchar,"BlackPearl",TranslateString("Black Pearl",""),-1,PIRATE,true,true);
			PChar.quest.wench_given_by = "Beckett";
			pchar.jack = "Met_Tia";
			PChar.Flags.Personal = 1; // PB: Non-British Jack-flag
			PChar.Flags.Personal.texture = 3;
			PChar.Flags.Pirate = 6; // PB: Jack Sparrow Pirate Flag
			PChar.Flags.Pirate.texture = 0;
			Towns[GetTownIndex("Redmond")].gov = "Weatherby Swann";
			ChangeCharacterAddressGroup(characterFromID("John Clifford Brin"), "none", "", "");

			// Restore stuff
			DeleteAttribute(&Locations[FindLocation("Tortuga_Port")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Tortuga_Tavern")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cayman_Port")],"vcskip");
			Pchar.dialog.filename = "blaze_dialog.c";
			ChangeCharacterAddressGroup(CharacterFromID("Storyteller"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Random Drunk"), "none", "", "");
			DisableFastTravel(false);
			Locations[FindLocation("Tortuga_port")].reload.l2.disable = 0;

			// Enable sidequests
			PChar.Rag = "1";
			ChangeCharacterAddressGroup(CharacterFromID("Captaine Chevalle"), "PoPrince_tavern", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("Eduardo Villanueva"), "Tortuga_Brothel_room", "goto", "locator3");
			ChangeCharacterAddressGroup(CharacterFromID("Sumbhajee"), "Havana_Tavern", "sit", "sit5");
			ChangeCharacterAddressGroup(CharacterFromID("Sumbhajee Aid1"), "Havana_Tavern", "goto", "goto4");
			pchar.quest.ANIMISTS = "1";
			PChar.quest.Story_Artois_Nigel.win_condition.l1 = "location";
			PChar.quest.Story_Artois_Nigel.win_condition.l1.character = PChar.id;
			PChar.quest.Story_Artois_Nigel.win_condition.l1.location = "Oranjestad_town";
			PChar.quest.Story_Artois_Nigel.win_condition = "Install_Voysey_And_Blythe";

			GiveItem2Character(Pchar,"aztec_compass");
			GiveItem2Character(Pchar,"EITC_Passport");
			
			// TALISMAN - to give bits of map to open Muerte Treasure Cave -->
			GiveItem2Character(Pchar,"Map_Doc_1");
			GiveItem2Character(Pchar,"Map_Doc_2");
			GiveItem2Character(Pchar,"Map_Doc_3");
			GiveItem2Character(Pchar,"Map_Doc_4");
			// <--- TALISMAN
			
			SetQuestHeader("IslaDeMuerteI");
			//AddQuestRecord("IslaDeMuerteI", "3");
			//CloseQuestHeader("IslaDeMuerteI");
			Dialog.CurrentNode = "First time";
			DialogExit();
			pchar.quest.rag = "1";
			//pchar.lucas = "0";
			PChar.quest.Luc_start.over = "yes";
			//AddDialogExitQuest("findecotbp");
			AddDialogExitQuest("houplaboom");
		break;

		case "Jacks_Grand_Entrance":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[72];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Jacks_Grand_Entrance2";
			Dialog.CurrentNode = "First time";
		break;

		case "Jacks_Grand_Entrance2":
			// Set up actual beginning
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			AddDialogExitQuest("piratefun"); // PB: You have joined the pirates
			GiveModel2Player("47YoungJack",false);
			GiveModel2Player("depp",false);
			GiveModel2Player("Jack",true);
			GiveShip2Character(pchar,"Tartane50","Jolly Mon",-1,PIRATE,true,true);
			pchar.jack = "Pirate";
			PChar.Flags.Personal = 1; // PB: Non-British Jack-flag
			PChar.Flags.Personal.texture = 3;
			PChar.Flags.Pirate = 6; // PB: Jack Sparrow Pirate Flag
			PChar.Flags.Pirate.texture = 0;
			Towns[GetTownIndex("Redmond")].gov = "Weatherby Swann";
			ChangeCharacterAddressGroup(characterFromID("John Clifford Brin"), "none", "", "");

			// Restore stuff
			DeleteAttribute(&Locations[FindLocation("Tortuga_Port")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Tortuga_Tavern")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cayman_Port")],"vcskip");
			Pchar.dialog.filename = "blaze_dialog.c";
			ChangeCharacterAddressGroup(CharacterFromID("Storyteller"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Random Drunk"), "none", "", "");
			DisableFastTravel(false);
			Locations[FindLocation("Tortuga_port")].reload.l2.disable = 0;
			
			// Enable sidequests
			PChar.Rag = "1";
			ChangeCharacterAddressGroup(CharacterFromID("Captaine Chevalle"), "PoPrince_tavern", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("Eduardo Villanueva"), "Tortuga_Brothel_room", "goto", "locator3");
			ChangeCharacterAddressGroup(CharacterFromID("Sumbhajee"), "Havana_Tavern", "sit", "sit5");
			ChangeCharacterAddressGroup(CharacterFromID("Sumbhajee Aid1"), "Havana_Tavern", "goto", "goto4");
			pchar.quest.ANIMISTS = "1";
			PChar.quest.Story_Artois_Nigel.win_condition.l1 = "location";
			PChar.quest.Story_Artois_Nigel.win_condition.l1.character = PChar.id;
			PChar.quest.Story_Artois_Nigel.win_condition.l1.location = "Oranjestad_town";
			PChar.quest.Story_Artois_Nigel.win_condition = "Install_Voysey_And_Blythe";

			GiveItem2Character(Pchar,"aztec_compass");
			
			// TALISMAN - to give bits of map to open Muerte Treasure Cave -->
			GiveItem2Character(Pchar,"Map_Doc_1");
			GiveItem2Character(Pchar,"Map_Doc_2");
			GiveItem2Character(Pchar,"Map_Doc_3");
			GiveItem2Character(Pchar,"Map_Doc_4");
			// <--- TALISMAN
			
			SetQuestHeader("Search_for_the_Black_Pearl");
			AddQuestRecord("Search_for_the_Black_Pearl", 5);

			pchar.quest.And_the_Film_Starts.win_condition.l1 = "location";
			pchar.quest.And_the_Film_Starts.win_condition.l1.location = "Redmond";
			pchar.quest.And_the_Film_Starts.win_condition = "And_the_Film_Starts";
			pchar.quest.henry_talk = "";
			QuestToSeaLogin_PrepareLoc("Redmond", "reload", "reload_2", false);
			QuestToSeaLogin_Launch();
			Dialog.CurrentNode = "First time";

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Jungle_Church":
			Characters[GetCharacterIndex("James Norrington")].model = "cnorrington";
			DoQuestReloadToLocation("Jungle_Church", "reload", "reload1" ,"_");
			ChangeCharacterAddressGroup(CharacterFromID("James Norrington"), "Jungle_Church", "goto", "goto10");
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"), "Jungle_Church", "goto", "goto5");
			LAi_SetImmortal(characterFromID("James Norrington"), true);
			LAi_SetImmortal(characterFromID("Will Turner"), true);
			LAi_SetImmortal(pchar, true);
			LAi_group_MoveCharacter(characterFromID("James Norrington"), "QUEST_ENEMIES");
			LAi_group_MoveCharacter(characterFromID("Will Turner"), "QUEST_ENEMIES");
			LAi_group_SetRelation("QUEST_ENEMIES", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("QUEST_ENEMIES", LAI_GROUP_PLAYER, true);
			LAi_SetFightMode(PChar, true);

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
