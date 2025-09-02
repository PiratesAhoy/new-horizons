void QuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld;
	PChar = GetMainCharacter();

	switch(sQuestName)
	{
		////////////////////////////////////////////////////////////////////////
		//  Êâåñò ïðî ïðîêëÿòûå ìîíåòêè
		////////////////////////////////////////////////////////////////////////
	
		case "Start":
			NPChar = characterFromID("Mystery Messenger");
			ChangeCharacterAddressGroup(NPChar, "Redmond_port", "officers", "sea_1_1");
			LAi_SetActorType(PChar);
			LAi_SetActorType(NPChar);
			LAi_ActorWaitDialog(PChar, NPChar);
			LAi_ActorFollow(NPChar, PChar, "Start_1", -1);
			SetNextWeather("Blue Sky"); 

			Locations[FindLocation("Devlin_tavern_outside")].reload.l2.disable = true;

                        DeleteAttribute(PChar, "shiplog");
                        WriteNewLogEntry(GetTranslatedLog("New captain's log"), GetTranslatedLog("My mother always said I had the devil’s own luck but that I should learn not to push it too far. My last adventure up the Amazon charting the river for the Portuguese crown has driven that point home. Half the expedition dead of malaria and the rest roasted on spits by savage cannibals. On the bright side, His Majesty’s representative was impressed by my tale and paid me the full expedition’s wages as I was the sole survivor. I have bought my own ship and will see what I can make of myself as a captain here in the new world. This is where my father disappeared... And I think my rascal brother should also be somewhere in these waters."),"Personal",true);
		break;

		case "Start_1":
			NPChar = characterFromID("Mystery Messenger");
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, NPChar);
			LAi_ActorDialog(NPChar, PChar, "", -1, 0.0);
		break;

		case "ReceivedLetter":
			trace("ReceivedLetter both_reaction");
			SetQuestHeader("Mystery Messenger and a letter");
			AddQuestRecord("Mystery Messenger and a letter", 1);
			GiveItem2Character(PChar, "a_letter");    
			NPChar = characterFromID("Mystery Messenger");
			LAi_ActorRunToLocator(characterFromID("Mystery Messenger"), "goto", "goto_41", "ReceivedLetter2", 10.0);
			LAi_SetPlayerType(PChar);

			pchar.quest.Bonnie_talk = "meeting_her_father";
			ChangeCharacterAddress(characterfromID("Laurence Wellman"),"none", "");
			ChangeCharacterAddressGroup(characterfromID("Emmanuel Devlin"),"Redmond_Head_port_house", "goto", "locator1");
		break;

		case "ReceivedLetter2":
			LAi_ActorRunToLocator(characterFromID("Mystery Messenger"), "reload", "Door_4", "ReceivedLetter3", 20.0);
		break;

		case "ReceivedLetter3":
//			pchar.quest.Bonnie_talk = "meeting_her_father";
			ChangeCharacterAddress(characterfromID("Mystery Messenger"),"none", "");
		break;

		case "Look_for_my_sister":
			ChangeCharacterAddressGroup(characterfromID("Bonnie Devlin"),"Redmond_port", "goto", "goto_2");
			ChangeCharacterAddressGroup(characterfromID("William Blaker"),"None", "", "");
			ChangeCharacterAddressGroup(characterfromID("Rico Diaz"),"QC_Tavern", "sit", "sit1");
			LAi_QuestDelay("Found_my_sister", 0.0);
		break;

		case "Found_my_sister":
			pchar.quest.Bonnie_talk = "Our_first_meeting";
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			LAi_ActorWaitDialog(pchar, characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].dialog.currentnode = "First time";
			Lai_ActorFollow(characterFromID("Bonnie Devlin"), pchar, "Start_treasure_search", 0.0);
			//Characters[GetCharacterIndex("Emmanuel Devlin")].dialog.filename = "Laurence Wellman_dialog.c";
			//Characters[GetCharacterIndex("Emmanuel Devlin")].dialog.currentnode = "First time";
			//Characters[GetCharacterIndex("Emmanuel Devlin")].quest.meeting = 1;
		break;

		case "Start_treasure_search":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

		case "And_on_to_Turks":
			CloseQuestHeader("Mystery Messenger and a letter");
			AddQuestRecord("Such Devoted Sisters",2);
			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);

			ChangeCharacterAddress(characterfromID("Devlin Jumpstart"),"none", "");
			ChangeCharacterAddress(characterFromID("Emmanuel Devlin"), "None", "");
			ChangeCharacterAddressGroup(characterfromID("Laurence Wellman"),"Redmond_Head_port_house", "goto", "locator1");

			Pchar.quest.to_find_Short_Jack_Gold.win_condition.l1 = "location";
			PChar.quest.to_find_Short_Jack_Gold.win_condition.l1.character = Pchar.id;
			Pchar.quest.to_find_Short_Jack_Gold.win_condition.l1.location = "Turks_port";
			Pchar.quest.to_find_Short_Jack_Gold.win_condition = "to_find_Short_Jack_Gold";
		break;

		case "to_find_Short_Jack_Gold":
			ChangeCharacterAddressGroup(characterfromID("Crewmember Devlin"),"Turks_port", "goto", "P_goto4");
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(pchar, characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].dialog.currentnode = "Arrived_in_Turks";
			Lai_ActorFollow(characterFromID("Bonnie Devlin"), pchar, "to_find_Short_Jack_Gold1", 0.0);
		break;

		case "to_find_Short_Jack_Gold1":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Arrived_in_Turks";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

                case "crewmember_Turks":
			LAi_SetOfficerType(CharacterFromID("Bonnie Devlin"));
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Crewmember Devlin"));
			LAi_SetActorType(CharacterFromID("Crewmember Devlin"));
			LAi_ActorWaitDialog(PChar, CharacterFromID("Crewmember Devlin"));
			Lai_ActorFollow(CharacterFromID("Crewmember Devlin"), PChar, "crewmember_Turks2", 10.0);
		break;

                case "crewmember_Turks2":
			LAi_SetPlayerType(PChar);
			LAi_ActorDialog(CharacterFromID("Crewmember Devlin"), Pchar, "", 5.0, 5.0);
		break;

		case "to_find_Short_Jack_Gold2":
			Characters[GetCharacterIndex("Short Jack Gold")].dialog.filename = "Short Jack Gold_dialog.c";
			Locations[FindLocation("Turks_townhall")].reload.l1.disable = 1;
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(characterfromID("Bonnie Devlin"),"Turks_townhall", "goto", "goto7");
			LAi_ActorRunToLocator(characterFromID("Crewmember Devlin"), "reload", "reload1", "crewmember_leaves_Turk", 3.0);
		break;

                case "crewmember_leaves_Turk":
			ChangeCharacterAddressGroup(characterfromID("Crewmember Devlin"),"None", "", "");
                break;

		case "Got_info_from_SJG":
			pchar.quest.Bonnie_talk = "Needing_family_help";
            LAi_SetActorType(characterFromID("Bonnie Devlin"));
            Lai_ActorFollow(characterFromID("Bonnie Devlin"), pchar, "Moving_right_along2", 3.0);
        break;

		case "Moving_right_along2":
			characters[GetCharacterIndex("Bonnie Devlin")].Dialog.Filename = "Bonnie Devlin_dialog.c";
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			LAi_ActorDialog(characterFromID("Bonnie Devlin"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Bonnie Devlin")].dialog.currentnode = "getting_warmer";
			Characters[GetCharacterIndex("Short Jack Gold")].dialog.filename = "Nathan Kell (GOV)_dialog.c";
		break;

		case "And_on_to_Nevis":
			SetNextWeather("Blue Sky");
			pchar.quest.Bonnie_talk = "Sailing_for_Nevis";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].dialog.currentnode = "First time";
			LAi_QuestDelay("For_Nevis_new", 0.0);
		break;

                case "For_Nevis_new":
			Pchar.quest.For_Nevis_new2.win_condition.l1 = "location";
			PChar.quest.For_Nevis_new2.win_condition.l1.character = Pchar.id;
			Pchar.quest.For_Nevis_new2.win_condition.l1.location = "QC_port";
			Pchar.quest.For_Nevis_new2.win_condition = "For_Nevis_new2";
		break;

                case "For_Nevis_new2":
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			LAi_ActorWaitDialog(pchar, characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].dialog.currentnode = "Asking_around_QC";
			Lai_ActorFollow(characterFromID("Bonnie Devlin"), pchar, "For_Nevis_new3", 0.0);
		break;

		case "For_Nevis_new3":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Asking_around_QC";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

		case "For_Nevis_new4":
			Characters[GetCharacterIndex("Sixto Costa")].dialog.currentnode = "Where_Blaze_at";
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Standard";
		break;

		case "For_Nevis_new5":
			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			pchar.quest.OPERA = "ask_Ines_for_Merchant";
		break;

		case "For_Nevis_new6":
			AddQuestRecord("My Brother, Ladies and Gentlemen", 2);
			Characters[GetCharacterIndex("Rico Diaz")].dialog.currentnode = "smarttalk";
			pchar.quest.OPERA = "asked_Ines_for_Merchant";
		break;

		case "For_Nevis_newfin":
			AddQuestRecord("My Brother, Ladies and Gentlemen", 3);
			Pchar.quest.meet_Blaze_Guad.win_condition.l1 = "location";
			//PChar.quest.meet_Blaze_Guad.win_condition.l1.character = Pchar.id;
			Pchar.quest.meet_Blaze_Guad.win_condition.l1.location = "Guadeloupe";
			Pchar.quest.meet_Blaze_Guad.win_condition = "meet_Blaze_Guad";
		break;

// Nevis finished -> Go to Guadeloupe

		case "meet_Blaze_Guad":
			DoReloadFromSeaToLocation("Family_deck", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Crewmember Devlin"),"Family_deck", "goto", "goto16");
			ChangeCharacterAddressGroup(characterfromID("Bonnie Devlin"),"Family_deck", "goto", "goto17");
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			LAi_SetActorType(characterFromID("Crewmember Devlin"));
			LAi_ActorWaitDialog(pchar, characterFromID("Crewmember Devlin"));
			Characters[GetCharacterIndex("Crewmember Devlin")].dialog.currentnode = "Sailho_Blaze";
			Lai_ActorFollow(characterFromID("Crewmember Devlin"), pchar, "meet_Blaze_Guad2", 0.0);
			//LAi_QuestDelay("meet_Blaze_Guad2", 2.0);
		break;

		case "meet_Blaze_Guad2":
			Characters[GetCharacterIndex("Crewmember Devlin")].Dialog.CurrentNode = "Sailho_Blaze";
			LAi_ActorDialog(characterFromID("Crewmember Devlin"), Pchar, "", 2.0, 0);
		break;

		case "meet_Blaze_Guad3":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Sailho_Blaze2";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
			LAi_SetCitizenType(characterFromID("Crewmember Devlin"));
		break;

		case "meet_Blaze_Guad4":
                        DoQuestReloadToLocation("Merchant_deck", "goto", "goto4", "meet_Blaze_Guad5")
			ChangeCharacterAddressGroup(characterfromID("Bonnie Devlin"),"Merchant_deck", "goto", "goto5");
		break;

		case "meet_Blaze_Guad5":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Sailho_Blaze3";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

		case "meet_Blaze_Guad6":
                        DoQuestReloadToLocation("Merchant_cabin", "goto", "goto0", "meet_Blaze_below")
			ChangeCharacterAddressGroup(characterfromID("Bonnie Devlin"),"Merchant_cabin", "goto", "goto5");
			ChangeCharacterAddressGroup(characterfromID("Blaze Devlin"),"Merchant_cabin", "goto", "goto7");
		break;

		case "meet_Blaze_below":
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "Meeting1";
			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
		break;

		case "meet_Blaze_below2":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Meeting_blaze";
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

		case "meet_Blaze_below3":
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "Meeting5";
			LAi_SetActorType(characterFromID("Blaze Devlin"));
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 2.0, 0);
		break;

		case "YoHoRum":
			//ReloadToSea("Guadeloupe", "Guadeloupe");
	                //ReloadToSea(FindIsland(island), chrWaitReloadRef);
			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
                        QuestToSeaLogin_PrepareLoc("Guadeloupe", "reload", "reload_1", true);
                        QuestToSeaLogin_Launch();
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

	                if (ENABLE_AMMOMOD)
	                {
		             TakeNItems(characterFromID("Blaze Devlin"), "gunpowder", 6);
		             TakeNItems(characterFromID("Blaze Devlin"), "pistolbullets", 6);
	                }

			Pchar.quest.Martinica_start.win_condition.l1 = "location";
			PChar.quest.Martinica_start.win_condition.l1.character = Pchar.id;
			Pchar.quest.Martinica_start.win_condition.l1.location = "Falaise_de_fleur_port_01";
			Pchar.quest.Martinica_start.win_condition = "Martinica_start";

			Pchar.quest.Martinica_start_shore.win_condition.l1 = "location";
			PChar.quest.Martinica_start_shore.win_condition.l1.character = Pchar.id;
			Pchar.quest.Martinica_start_shore.win_condition.l1.location = "Falaise_de_fleur_shore";
			Pchar.quest.Martinica_start_shore.win_condition = "Martinica_start";
		break;


//=========================== MARTINICA RUM QUEST ==========================================//

		case "Martinica_start":
			Pchar.quest.Martinica_start.over = "yes";
			Pchar.quest.Martinica_start_shore.over = "yes";
			DeleteQuestHeader("Mystery Messenger and a letter");
			DeleteQuestHeader("Such Devoted Sisters");
			DeleteQuestHeader("My Brother, Ladies and Gentlemen");

			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));	// Force Bonnie and Blaze back to being officers
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));	// in case player hired new officers on the way here
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Falaise_de_fleur_shore", "officers", "reload1_1");
				ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Falaise_de_fleur_shore", "officers", "reload1_2");
			}
			else
			{
				ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Falaise_de_fleur_port_01", "officers", "sea_1");
				ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Falaise_de_fleur_port_01", "officers", "sea_2");
			}
			LAi_SetActorType(characterFromID("Blaze Devlin"));
			LAi_ActorWaitDialog(pchar, characterFromID("Blaze Devlin"));
			Characters[GetCharacterIndex("Blaze Devlin")].dialog.currentnode = "Martinica_arrival";
			Lai_ActorFollow(characterFromID("Blaze Devlin"), pchar, "Martinica_start2", 0.0);
		break;

		case "Martinica_start2":
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "Martinica_arrival";
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 0.1, 0);
		break;

// BONNIE on Martinica

		case "Bonnie_Martinica_start":
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				DoQuestReloadToLocation("Falaise_de_fleur_shore", "reload", "reload1" ,"Bonnie_Martinica_start2");
			}
			else
			{
				DoQuestReloadToLocation("Falaise_de_fleur_port_01", "reload", "sea" ,"Bonnie_Martinica_start2");
			}
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 2);
                        bQuestDisableSeaEnter = true;
		break;

		case "Bonnie_Martinica_start2":
			ChangeCharacterAddressGroup(characterFromID("Toni Haraldo"), "Falaise_de_fleur_townhall", "sit", "sit2");
			Characters[GetCharacterIndex("Toni Haraldo")].Dialog.CurrentNode = "Bonnie";
		break;

		case "Party_begins":
			DoQuestReloadToLocation("Wedding_Ballroom", "reload", "reload3" ,"Party_begins2");
			ChangeCharacterAddressGroup(characterFromID("Toni Haraldo"), "Wedding_Ballroom", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Isabel Marino"), "Wedding_Ballroom", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Grey Roger"), "Wedding_Ballroom", "goto", "goto10");
			ChangeCharacterAddressGroup(characterFromID("Pepe Grande"), "Wedding_Ballroom", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Kofi Macchiato"), "Wedding_Ballroom", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Doma Perignone"), "Wedding_Ballroom", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Puerta Velador"), "Wedding_Ballroom", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Franz Gynster"), "Wedding_Ballroom", "goto", "goto7");
			Locations[FindLocation("Wedding_Ballroom")].reload.l1.disable = 1;
		break;

		case "Party_begins2":
			LAi_SetActorType(pchar)
			Pchar.dialog.CurrentNode = "Bonnieparty1";
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Party_begins3":
			LAi_SetPlayerType(PChar);
			pchar.quest.Dont_leave.win_condition.l1 = "locator";
			pchar.quest.Dont_leave.win_condition.l1.location = "Wedding_Ballroom";
			pchar.quest.Dont_leave.win_condition.l1.locator_group = "reload";
			pchar.quest.Dont_leave.win_condition.l1.locator = "reload1";
			pchar.quest.Dont_leave.win_condition = "Dont_leave";
		break;

		case "Dont_leave":
                        PlaySound("INTERFACE\knock2.wav");
                        LAi_QuestDelay("Dont_leave2", 1.0);
			Characters[GetCharacterIndex("Puerta Velador")].Dialog.CurrentNode = "First time";
		break;

		case "Dont_leave2":
			Characters[GetCharacterIndex("Puerta Velador")].Dialog.CurrentNode = "First time";
			LAi_SetActorType(characterFromID("Puerta Velador"));
			LAi_ActorDialog(characterFromID("Puerta Velador"), Pchar, "", 2.0, 0);
		break;

		case "Puerta_returns":
			Characters[GetCharacterIndex("Puerta Velador")].Dialog.CurrentNode = "First time";
			LAi_SetStayType(characterFromID("Puerta Velador"));

			pchar.quest.vase_smash.win_condition.l1 = "locator";
			pchar.quest.vase_smash.win_condition.l1.location = "Wedding_Ballroom";
			pchar.quest.vase_smash.win_condition.l1.locator_group = "box";
			pchar.quest.vase_smash.win_condition.l1.locator = "box1";
			pchar.quest.vase_smash.win_condition = "vase_smash";
		break;

		case "vase_smash":
			PlaySound("INTERFACE\glass_explosion.wav");
			LAi_QuestDelay("vase_smash2", 2.5);
		break;

		case "vase_smash2":
			LAi_SetActorType(pchar)
			Pchar.dialog.CurrentNode = "Ooops";
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "vase_key":
			LAi_SetPlayerType(PChar);
			GiveItem2Character(PChar, "key_haraldo");
			PlaySound("INTERFACE\took_item.flac");

			pchar.quest.Dont_leave.win_condition.l1 = "locator";
			pchar.quest.Dont_leave.win_condition.l1.location = "Wedding_Ballroom";
			pchar.quest.Dont_leave.win_condition.l1.locator_group = "reload";
			pchar.quest.Dont_leave.win_condition.l1.locator = "reload2";
			pchar.quest.Dont_leave.win_condition = "open_bedroom";
		break;

		case "open_bedroom":
			LAi_SetActorType(pchar)
			PlaySound("INTERFACE\key_unlock.wav");
                        TakeItemFromCharacter(PChar, "key_haraldo");
			LAi_QuestDelay("open_bedroom2", 2.0);
		break;

		case "open_bedroom2":
			DoQuestReloadToLocation("Haraldo_Bedroom", "reload", "reload1" ,"open_bedroom3");
			ChangeCharacterAddressGroup(characterFromID("Ernesto Haraldo"), "Haraldo_Bedroom", "sit", "sit1");
		break;

		case "open_bedroom3":
			Locations[FindLocation("Haraldo_Bedroom")].reload.l1.disable = 1;
			LAi_SetPlayerType(PChar);
		break;

		case "drink_with_Ernesto":
			LAi_Fade("have_a_seat", "drink_with_Ernesto2");
		break;

		case "have_a_seat":
			LAi_SetActorType(pchar);
			ChangeCharacterAddressGroup(pchar, "Haraldo_Bedroom", "goto", "goto5");
		break;

		case "drink_with_Ernesto2":
			Characters[GetCharacterIndex("Ernesto Haraldo")].dialog.currentnode = "wineglass";
			LAi_ActorDialogNow(Pchar, characterFromID("Ernesto Haraldo"), "", -1);
		break;

		case "caught":
			LAi_SetPlayerType(PChar);
			LAi_QuestDelay("caught2", 0.5);
		break;

		case "caught2":
			ChangeCharacterAddressGroup(characterFromID("Isabel Marino"), "Haraldo_Bedroom", "reload", "reload1");
			PlaySound("INTERFACE\key_unlock.wav")
			LAi_QuestDelay("caught3", 2.0);
		break;

		case "caught3":
                        PlaySound("VOICE\ENGLISH\Fre_f_a_009.wav");
			LAi_QuestDelay("caught4", 1.5);
		break;

		case "caught4":
			LAi_SetActorType(characterFromID("Isabel Marino"));
			Characters[GetCharacterIndex("Isabel Marino")].dialog.currentnode = "flagranti";
			LAi_ActorDialog(characterFromID("Isabel Marino"), Pchar, "", 0.5, 0);
		break;

		case "rugbeater":
			LAi_LocationFightDisable(&Locations[FindLocation("Haraldo_Bedroom")], 0);
			LAi_SetPlayerType(pchar);
			GiveItem2Character(characterFromID("Isabel Marino"), "blade37");
			EquipCharacterByItem(characterFromID("Isabel Marino"), "blade37");
			LAi_SetImmortal(characterFromID("Ernesto Haraldo"), true);
			LAi_SetImmortal(characterFromID("Isabel Marino"), true);
			LAi_SetActorType(characterFromID("Isabel Marino"));
                        LAi_ActorAttack(CharacterFromID("Isabel Marino"), PChar, "");
			LAi_QuestDelay("Windowjump", 0.5);
			PlaySound("INTERFACE\glass_explosion.wav");
		break;

		case "Windowjump":
			DoQuestReloadToLocation("Falaise_de_fleur_location_03", "goto", "locator21" ,"Windowjump2");
			SetCurrentTime(22.00, 0);
			ChangeCharacterAddressGroup(characterFromID("Falaise De Fleur patrol 07"), "none", "", "");
		break;

		case "Windowjump2":
			PlaySound("INTERFACE\falling_down.wav")
			LAi_QuestDelay("Windowjump3", 1.0);
		break;

		case "Windowjump3":
			LAi_SetActorType(pchar)
			Pchar.dialog.CurrentNode = "Fallen";
			LAi_ActorSelfDialog(PChar, "");
		break;

                case "Bonnie_returns_Martinica_fallen":
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				DoQuestReloadToLocation("Falaise_de_fleur_shore", "goto", "goto23" ,"Meet_after_Martinica");
			}
			else
			{
				DoQuestReloadToLocation("Falaise_de_fleur_port_01", "goto", "goto13" ,"Meet_after_Martinica");
			}
			AddMoneyToCharacter(pchar, 20000);
			LAi_SetPlayerType(Pchar);
                        bQuestDisableSeaEnter = false;
//			SetCharacterShipLocation(Pchar, "Falaise_de_fleur_port_01");
		break;

                case "Bonnie_returns_Martinica_talked":
			DoQuestReloadToLocation("Falaise_de_fleur_location_03", "goto", "locator21" ,"Bonnie_returns_Martinica_talked2");
			SetCurrentTime(22.00, 0);
			ChangeCharacterAddressGroup(characterFromID("Falaise De Fleur patrol 07"), "none", "", "");
		break;

                case "Bonnie_returns_Martinica_talked2":
			LAi_SetActorType(pchar)
			Pchar.dialog.CurrentNode = "TalkedEH";
			LAi_ActorSelfDialog(PChar, "");
		break;

                case "Bonnie_returns_Martinica_talkedfin":
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				DoQuestReloadToLocation("Falaise_de_fleur_shore", "goto", "goto23" ,"Meet_after_Martinica");
			}
			else
			{
				DoQuestReloadToLocation("Falaise_de_fleur_port_01", "goto", "goto13" ,"Meet_after_Martinica");
			}
			AddMoneyToCharacter(pchar, 20000);
			LAi_SetPlayerType(Pchar);
			ChangeCharacterReputation(pchar, 10);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 7000);
				AddPartyExpChar(pchar, "Sneak", 3000);
			}
			else { AddPartyExp(pchar, 10000); }
                        bQuestDisableSeaEnter = false;
//			SetCharacterShipLocation(Pchar, "Falaise_de_fleur_port_01");
		break;


// BLAZE on Martinica

		case "Blaze_Martinica_start":
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				DoQuestReloadToLocation("Falaise_de_fleur_shore", "reload", "reload1" ,"Blaze_Martinica_start2");
			}
			else
			{
				DoQuestReloadToLocation("Falaise_de_fleur_port_01", "reload", "sea" ,"Blaze_Martinica_start2");
			}
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 2);
                        bQuestDisableSeaEnter = true;
		break;

		case "Blaze_Martinica_start2":
			ChangeCharacterAddressGroup(characterFromID("Toni Haraldo"), "Falaise_de_fleur_townhall", "sit", "sit2");
			Characters[GetCharacterIndex("Toni Haraldo")].Dialog.CurrentNode = "Blaze";
		break;

		case "Boxing_begins":
			LAi_SetStayType(characterFromID("Toni Haraldo"));
			DoQuestReloadToLocation("Falaise_de_fleur_shore", "goto", "goto16" ,"Boxing_begins2");

			ChangeCharacterAddressGroup(characterFromID("Toni Haraldo"), "Falaise_de_fleur_shore", "goto", "goto19");
			ChangeCharacterAddressGroup(characterFromID("Dirty Cesar"), "Falaise_de_fleur_shore", "goto", "goto15");
			ChangeCharacterAddressGroup(characterFromID("Chico Malo"), "Falaise_de_fleur_shore", "goto", "goto14");
			ChangeCharacterAddressGroup(characterFromID("Audience1"), "Falaise_de_fleur_shore", "goto", "goto32");
			ChangeCharacterAddressGroup(characterFromID("Audience2"), "Falaise_de_fleur_shore", "goto", "goto33");
			ChangeCharacterAddressGroup(characterFromID("Audience3"), "Falaise_de_fleur_shore", "goto", "goto34");
			ChangeCharacterAddressGroup(characterFromID("Audience4"), "Falaise_de_fleur_shore", "goto", "goto35");
			ChangeCharacterAddressGroup(characterFromID("Audience5"), "Falaise_de_fleur_shore", "goto", "goto36");
			ChangeCharacterAddressGroup(characterFromID("Audience6"), "Falaise_de_fleur_shore", "goto", "goto40");
			ChangeCharacterAddressGroup(characterFromID("Audience7"), "Falaise_de_fleur_shore", "goto", "goto41");
			ChangeCharacterAddressGroup(characterFromID("Audience8"), "Falaise_de_fleur_shore", "goto", "goto42");

                        //LAi_group_MoveCharacter(CharacterFromID("Dirty Cesar"), LAI_GROUP_MONSTERS);
                        //LAi_group_MoveCharacter(CharacterFromID("Chico Malo"), LAI_GROUP_MONSTERS);


			LAi_SetActorType(characterFromID("Toni Haraldo"));
			Characters[GetCharacterIndex("Toni Haraldo")].dialog.currentnode = "fighttime";
                        Lai_ActorFollow(characterFromID("Toni Haraldo"), pchar, "Boxing_begins2", 3.0);
		break;

		case "Boxing_begins2":
			LAi_ActorDialog(characterFromID("Toni Haraldo"), Pchar, "", 3.0, 0);
		break;

		case "First_fight":
			LAi_ActorGoToLocator(characterFromID("Toni Haraldo"), "goto", "goto19", "",3);
			LAi_SetActorTypeNoGroup(characterFromID("Dirty Cesar"));
			LAi_ActorDialog(characterFromID("Dirty Cesar"), Pchar, "", 0.5, 0);
		break;

		case "First_fight2":
			LAi_SetHP(CharacterFromID("Dirty Cesar"), 140.0, 140.0);
			EquipCharacterByItem(Pchar, "bladeX4");
			bDisableFastReload = 1;
			LAi_ActorAttack(CharacterFromID("Dirty Cesar"), PChar, "");

                        LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-15.0, false, "Blaze_lost_first_fight");
			//Lai_SetCheckMinHP(Pchar, 40.0, false, "Blaze_lost_first_fight");
			//Lai_SetCheckMinHP(CharacterFromID("Dirty Cesar"), 110.0, true, "Blaze_won_first_fight");
                        LAi_SetCheckMinHP(characterFromID("Dirty Cesar"), LAi_GetCharacterHP(characterFromID("Dirty Cesar"))-10.0, false, "Blaze_won_first_fight");

			PChar.quest.Blaze_won_first_fight_stun.win_condition.l1 = "NPC_Stunned";
			PChar.quest.Blaze_won_first_fight_stun.win_condition.l1.character = "Dirty Cesar";
			PChar.quest.Blaze_won_first_fight_stun.win_condition = "Blaze_won_first_fight";
		break;

		case "Blaze_lost_first_fight":
			PChar.quest.Blaze_won_first_fight_stun.over = "yes";
                        LAi_RemoveCheckMinHP(CharacterFromID("Dirty Cesar"));

			LAi_type_actor_Reset(CharacterFromID("Dirty Cesar"));

                        //LAi_SetPoorType(Pchar);
                        LAi_SetStunnedTypeNoGroup(Pchar);
			PlaySound("AMBIENT\cheer2.wav");

			LAi_SetFightMode(PChar, false);

			LAi_QuestDelay("Blaze_lost_first_fight2", 5.0);
		break;

		case "Blaze_lost_first_fight2":
			LAi_SetActorType(PChar);
			LAi_SetFightMode(PChar, false);
			LAi_type_actor_Reset(Pchar);
                        LAi_SetPlayerType(Pchar);
			Characters[GetCharacterIndex("Toni Haraldo")].dialog.currentnode = "lost_first_fight";
                        Lai_ActorFollow(characterFromID("Toni Haraldo"), pchar, "Blaze_lost_first_fight3", 3.0);
		break;

		case "Blaze_lost_first_fight3":
			LAi_ActorDialog(characterFromID("Toni Haraldo"), Pchar, "", 3.0, 0);
		break;

		case "Blaze_won_first_fight":
			PChar.quest.Blaze_won_first_fight_stun.over = "yes";
                        LAi_RemoveCheckMinHP(PChar);

			LAi_type_actor_Reset(CharacterFromID("Dirty Cesar"));
                        LAi_SetStunnedTypeNoGroup(characterFromID("Dirty Cesar"));

			PlaySound("AMBIENT\UnHappy-002.wav");

//			LAi_SetActorType(PChar);
			LAi_SetFightMode(PChar, false);
//			LAi_type_actor_Reset(Pchar);
//                        LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("Blaze_won_first_fight2", 3.0);
		break;

		case "Blaze_won_first_fight2":
			Characters[GetCharacterIndex("Toni Haraldo")].dialog.currentnode = "won_first_fight";
                        Lai_ActorFollow(characterFromID("Toni Haraldo"), pchar, "Blaze_won_first_fight3", 3.0);
		break;

		case "Blaze_won_first_fight3":
			LAi_ActorDialog(characterFromID("Toni Haraldo"), Pchar, "", 3.0, 0);
		break;

		case "Second_fight":
			LAi_SetHP(characterfromID("Dirty Cesar"), LAI_DEFAULT_HP, LAI_DEFAULT_HP);

			LAi_ActorGoToLocator(characterFromID("Toni Haraldo"), "goto", "goto19", "",3);
			LAi_SetActorType(characterFromID("Dirty Cesar"));
			LAi_ActorRunToLocator(characterFromID("Dirty Cesar"), "reload", "reload2", "Cesar_disappears", 25.0);

			LAi_SetActorTypeNoGroup(characterFromID("Chico Malo"));
			LAi_ActorDialog(characterFromID("Chico Malo"), Pchar, "", 0.5, 0);
		break;

		case "Cesar_disappears":
			ChangeCharacterAddress(characterfromID("Dirty Cesar"),"none", "");
		break;

		case "Second_fight2":
//			LAi_SetHP(PChar, LAI_DEFAULT_HP, LAI_DEFAULT_HP);
			LAi_SetHP(CharacterFromID("Chico Malo"), 150.0, 150.0);
			LAi_ActorAttack(CharacterFromID("Chico Malo"), PChar, "");

                        LAi_SetCheckMinHP(PChar, LAi_GetCharacterHP(PChar)-15.0, false, "Blaze_lost_second_fight");
			//Lai_SetCheckMinHP(Pchar, 40.0, false, "Blaze_lost_second_fight");
			//Lai_SetCheckMinHP(CharacterFromID("Chico Malo"), 115.0, true, "Blaze_won_second_fight");
                        LAi_SetCheckMinHP(characterFromID("Chico Malo"), LAi_GetCharacterHP(characterFromID("Chico Malo"))-10.0, false, "Blaze_won_second_fight");

			PChar.quest.Blaze_won_second_fight_stun.win_condition.l1 = "NPC_Stunned";
			PChar.quest.Blaze_won_second_fight_stun.win_condition.l1.character = "Chico Malo";
			PChar.quest.Blaze_won_second_fight_stun.win_condition = "Blaze_won_second_fight";
		break;

		case "Blaze_lost_second_fight":
			PChar.quest.Blaze_won_second_fight_stun.over = "yes";
			LAi_type_actor_Reset(CharacterFromID("Chico Malo"));
                        LAi_RemoveCheckMinHP(CharacterFromID("Chico Malo"));

                        //LAi_SetPoorType(Pchar);
                        LAi_SetStunnedTypeNoGroup(Pchar);
			PlaySound("AMBIENT\cheer2.wav")
			LAi_SetFightMode(PChar, false);

			LAi_QuestDelay("Blaze_lost_second_fight2", 5.0);
		break;

		case "Blaze_won_second_fight":
			PChar.quest.Blaze_won_second_fight_stun.over = "yes";
                        LAi_RemoveCheckMinHP(PChar);

			LAi_type_actor_Reset(CharacterFromID("Chico Malo"));
                        LAi_SetStunnedTypeNoGroup(characterFromID("Chico Malo"));

			PlaySound("AMBIENT\UnHappy-002.wav")

//			LAi_SetActorType(PChar);
			LAi_SetFightMode(PChar, false);
//			LAi_type_actor_Reset(Pchar);
//                        LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("Blaze_won_second_fight2", 5.0);
		break;

		case "Blaze_won_second_fight2":
			Characters[GetCharacterIndex("Toni Haraldo")].dialog.currentnode = "won_second_fight";
                        Lai_ActorFollow(characterFromID("Toni Haraldo"), pchar, "Blaze_won_second_fight3", 3.0);
		break;

		case "Blaze_won_second_fight3":
			LAi_ActorDialog(characterFromID("Toni Haraldo"), Pchar, "", 3.0, 0);
		break;

		case "Audience_attacks":
			LAi_SetActorType(characterFromID("Chico Malo"));
			LAi_ActorRunToLocator(characterFromID("Chico Malo"), "reload", "reload2", "Chico_disappears", 25.0);

//			LAi_SetHP(PChar, LAI_DEFAULT_HP, LAI_DEFAULT_HP);
			NPChar = characterFromID("Blaze Devlin");
			if(GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE) != "")
			{
				EquipCharacterByItem(Pchar, GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE));
			}
			else
			{
				EquipCharacterByItem(Pchar, "blade21");
			}
//			EquipCharacterByItem(Pchar, "blade21");
			LAi_ActorRunToLocator(characterFromID("Toni Haraldo"), "goto", "goto19", "",3);

			LAi_SetHP(CharacterFromID("Audience1"), 10.0, 10.0);
			LAi_SetHP(CharacterFromID("Audience2"), 10.0, 10.0);
			LAi_SetHP(CharacterFromID("Audience3"), 10.0, 10.0);
			LAi_SetHP(CharacterFromID("Audience4"), 10.0, 10.0);
			LAi_SetHP(CharacterFromID("Audience5"), 10.0, 10.0);
			LAi_SetHP(CharacterFromID("Audience6"), 10.0, 10.0);
			LAi_SetHP(CharacterFromID("Audience7"), 10.0, 10.0);
			LAi_SetHP(CharacterFromID("Audience8"), 10.0, 10.0);


			LAi_SetWarriorType(CharacterFromID("Audience1"));
			LAi_SetWarriorType(CharacterFromID("Audience2"));
			LAi_SetWarriorType(CharacterFromID("Audience3"));
			LAi_SetWarriorType(CharacterFromID("Audience4"));
			LAi_SetWarriorType(CharacterFromID("Audience5"));
			LAi_SetWarriorType(CharacterFromID("Audience6"));
			LAi_SetWarriorType(CharacterFromID("Audience7"));
			LAi_SetWarriorType(CharacterFromID("Audience8"));

			LAi_group_MoveCharacter(CharacterFromID("Audience1"), "Furious_Audience");
			LAi_group_MoveCharacter(CharacterFromID("Audience2"), "Furious_Audience");
			LAi_group_MoveCharacter(CharacterFromID("Audience3"), "Furious_Audience");
			LAi_group_MoveCharacter(CharacterFromID("Audience4"), "Furious_Audience");
			LAi_group_MoveCharacter(CharacterFromID("Audience5"), "Furious_Audience");
			LAi_group_MoveCharacter(CharacterFromID("Audience6"), "Furious_Audience");
			LAi_group_MoveCharacter(CharacterFromID("Audience7"), "Furious_Audience");
			LAi_group_MoveCharacter(CharacterFromID("Audience8"), "Furious_Audience");

			LAi_group_FightGroups("Furious_Audience", LAI_GROUP_PLAYER, 1);

			LAi_group_SetCheck("Furious_Audience", "Killed_Audience");
		break;

		case "Chico_disappears":
			ChangeCharacterAddress(characterfromID("Chico Malo"),"none", "");
		break;

		case "Killed_Audience":
			LAi_SetFightMode(PChar, false);
			Characters[GetCharacterIndex("Toni Haraldo")].dialog.currentnode = "RIP_Audience1";
                        Lai_ActorFollow(characterFromID("Toni Haraldo"), pchar, "Killed_Audience2", 5.0);
		break;

		case "Killed_Audience2":
			LAi_SetFightMode(PChar, false);
			LAi_ActorDialog(characterFromID("Toni Haraldo"), Pchar, "", 5.0, 0);
		break;

		case "Blaze_lost_second_fight2":
			DoQuestReloadToLocation("Recovery_House", "goto", "goto3" ,"Blaze_Recovered");

//			LAi_SetHP(PChar, LAI_DEFAULT_HP, LAI_DEFAULT_HP);
			NPChar = characterFromID("Blaze Devlin");
			if(GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE) != "")
			{
				EquipCharacterByItem(Pchar, GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE));
			}
			else
			{
				EquipCharacterByItem(Pchar, "blade21");
			}

			ChangeCharacterAddressGroup(characterFromID("Toni Haraldo"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Chico Malo"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience4"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience5"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience6"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience7"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience8"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Isabel Marino"), "Recovery_House", "goto", "goto4");

			LAi_SetActorType(PChar);
                        LAi_SetPlayerType(Pchar);

                        WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(07.00, 0);
		break;

		case "Blaze_Recovered":
			Characters[GetCharacterIndex("Isabel Marino")].dialog.currentnode = "Recovery";
			LAi_SetActorType(characterFromID("Isabel Marino"));
			LAi_ActorDialog(characterFromID("Isabel Marino"), Pchar, "", 2.0, 0);

			Pchar.quest.Chico_Showdown.win_condition.l1 = "location";
			PChar.quest.Chico_Showdown.win_condition.l1.character = Pchar.id;
			Pchar.quest.Chico_Showdown.win_condition.l1.location = "Falaise_de_fleur_location_03";
			Pchar.quest.Chico_Showdown.win_condition = "Chico_Showdown";
		break;

		case "Chico_Showdown":
			ChangeCharacterAddressGroup(characterFromID("Chico Malo"), "Falaise_de_fleur_location_03", "goto", "sitizen06");

			LAi_SetActorType(characterFromID("Chico Malo"));
			Characters[GetCharacterIndex("Chico Malo")].dialog.currentnode = "Challenge";
                        Lai_ActorFollow(characterFromID("Chico Malo"), pchar, "Chico_Showdown2", 3.0);
		break;

		case "Chico_Showdown2":
			LAi_ActorDialog(characterFromID("Chico Malo"), Pchar, "", 3.0, 0);
		break;

		case "Chico_Showdown_starts":
			LAi_SetHP(CharacterFromID("Chico Malo"), 200.0, 200.0);
			GiveItem2Character(characterFromID("Chico Malo"), "blade33");
			EquipCharacterByItem(characterFromID("Chico Malo"), "blade33");

			LAi_ActorAttack(CharacterFromID("Chico Malo"), PChar, "");

			LAi_SetCheckMinHP(CharacterFromID("Chico Malo"), 0.0, 0, "Showdown_ends");
		break;

		case "Showdown_ends":
			LAi_SetActorType(pchar)
			Pchar.dialog.CurrentNode = "Chico_ded";
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Blaze_returns_Martinica_bad":
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				DoQuestReloadToLocation("Falaise_de_fleur_shore", "goto", "goto23" ,"Meet_after_Martinica");
			}
			else
			{
				DoQuestReloadToLocation("Falaise_de_fleur_port_01", "goto", "goto13" ,"Meet_after_Martinica");
			}
			AddMoneyToCharacter(pchar, 25000);
			ChangeCharacterReputation(pchar, -10);
			LAi_SetPlayerType(Pchar);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Fencing", 7000);
				AddPartyExpChar(pchar, "Defence", 3000);
			}
			else { AddPartyExp(pchar, 10000); }
                        bQuestDisableSeaEnter = false;
			bDisableFastReload = 0;
//			SetCharacterShipLocation(Pchar, "Falaise_de_fleur_port_01");

			ChangeCharacterAddressGroup(characterFromID("Toni Haraldo"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Chico Malo"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience4"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience5"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience6"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience7"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Audience8"), "none", "", "");
		break;

		case "Blaze_returns_Martinica_duel":
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				DoQuestReloadToLocation("Falaise_de_fleur_shore", "goto", "goto23" ,"Meet_after_Martinica");
			}
			else
			{
				DoQuestReloadToLocation("Falaise_de_fleur_port_01", "goto", "goto13" ,"Meet_after_Martinica");
			}
			AddMoneyToCharacter(pchar, 21000);
			LAi_SetPlayerType(Pchar);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Fencing", 7000);
				AddPartyExpChar(pchar, "Defence", 3000);
			}
			else { AddPartyExp(pchar, 10000); }
                        bQuestDisableSeaEnter = false;
			bDisableFastReload = 0;
//			SetCharacterShipLocation(Pchar, "Falaise_de_fleur_port_01");
		break;


// BEATRICE on Martinica

		case "Beatrice_Martinica_start":
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "none", "", "");	//just to be sure
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "none", "", "");	//just to be sure
			RemovePassenger(Pchar, characterFromID("Bonnie Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));
			RemovePassenger(Pchar, characterFromID("Blaze Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				DoQuestReloadToLocation("Falaise_de_fleur_shore", "reload", "reload1" ,"Beatrice_Martinica_start2");
			}
			else
			{
				DoQuestReloadToLocation("Falaise_de_fleur_port_01", "reload", "sea" ,"Beatrice_Martinica_start2");
			}
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 2);
                        bQuestDisableSeaEnter = true;
		break;

		case "Beatrice_Martinica_start2":
			ChangeCharacterAddressGroup(characterFromID("Toni Haraldo"), "Falaise_de_fleur_townhall", "sit", "sit2");
			Characters[GetCharacterIndex("Toni Haraldo")].Dialog.CurrentNode = "Beatrice";
		break;

		case "Scavenger_hunt_1":
			Characters[GetCharacterIndex("Toni Haraldo")].dialog.currentnode = "in_progress";
			Characters[GetCharacterIndex("Hardouin Aufort")].dialog.currentnode = "poems_1";
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 3);
		break;

		case "Scavenger_hunt_to_Guzman":
			ChangeCharacterAddressGroup(CharacterFromID("Falaise De Fleur Soldier 04"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Guzman"), "Falaise_de_fleur_location_02", "goto", "locator33");
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 4);
		break;

		case "Scavenger_hunt_to_Frenchman":
			Characters[GetCharacterIndex("Guzman")].dialog.currentnode = "Guzmanprog";
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 5);

			pchar.quest.Frenchman_note.win_condition.l1 = "locator";
			pchar.quest.Frenchman_note.win_condition.l1.location = "Falaise_de_fleur_location_05";
			pchar.quest.Frenchman_note.win_condition.l1.locator_group = "reload";
			pchar.quest.Frenchman_note.win_condition.l1.locator = "locator9";
			pchar.quest.Frenchman_note.win_condition = "Frenchman_note";
		break;

		case "Frenchman_note":
			GiveItem2Character(PChar, "jauri_note");
			PlaySound("INTERFACE\took_item.flac");

			ChangeCharacterAddressGroup(CharacterFromID("Martin Jauri"), "Falaise_de_Fleur_store", "goto", "goto5");
			ChangeCharacterAddressGroup(CharacterFromID("Guzman"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Falaise De Fleur Soldier 04"), "Falaise_de_fleur_location_02", "goto", "locator33");
		break;

		case "Scavenger_hunt_to_Carpenter":
			Characters[GetCharacterIndex("Martin Jauri")].dialog.currentnode = "Jauriprog";
			ChangeCharacterAddressGroup(CharacterFromID("Lil Carlos"), "Falaise_de_fleur_port_02", "goto", "carpenter");
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 6);
		break;

		case "Scavenger_hunt_to_Bonto":
			Characters[GetCharacterIndex("Lil Carlos")].dialog.currentnode = "Lilprog";
			ChangeCharacterAddressGroup(CharacterFromID("Martin Jauri"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Bonto"), "HouseInsideR20", "sit", "sit1");
			locations[FindLocation("HouseInsideR20")].vcskip = true;
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 7);
		break;

		case "Scavenger_hunt_to_Church":
			Characters[GetCharacterIndex("Bonto")].dialog.currentnode = "Bontoprog";
			ChangeCharacterAddressGroup(CharacterFromID("Lil Carlos"), "none", "", "");

			Characters[GetCharacterIndex("pater Jourdain")].dialog.currentnode = "poetry1";

			AddQuestRecord("Yo Ho Ho and a shipment of rum", 8);
		break;

		case "Scavenger_hunt_to_Widow":
			ChangeCharacterAddressGroup(CharacterFromID("Bonto"), "none", "", "");
			locations[FindLocation("HouseInsideR20")].vcskip = false;

			ChangeCharacterAddressGroup(CharacterFromID("Rosa"), "Falaise_de_fleur_location_04", "goto", "locator9");

			AddQuestRecord("Yo Ho Ho and a shipment of rum", 9);
		break;

		case "Scavenger_hunt_to_Beach":
			Characters[GetCharacterIndex("Rosa")].dialog.currentnode = "Rosaprog";

			ChangeCharacterAddressGroup(CharacterFromID("Triton Barbos"), "Falaise_de_fleur_shore", "goto", "locator8");

			AddQuestRecord("Yo Ho Ho and a shipment of rum", 10);
		break;

		case "Scavenger_hunt_to_Haraldo_again":
			ChangeCharacterAddressGroup(CharacterFromID("Rosa"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Triton Barbos"), "none", "", "");
			PlaySound("NATURE\water_in.wav");
			Characters[GetCharacterIndex("Toni Haraldo")].dialog.currentnode = "poems_found";
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 11);
		break;

		case "Silvia_comes_in":
			ChangeCharacterAddressGroup(characterFromID("Silvia Haraldo"), "Falaise_de_fleur_townhall", "reload", "reload1");
			PlaySound("INTERFACE\key_unlock.wav")
			LAi_QuestDelay("Silvia_comes_in2", 2.0);
		break;

		case "Silvia_comes_in2":
                        PlaySound("VOICE\ENGLISH\Fre_f_a_006.wav");
			LAi_QuestDelay("Silvia_comes_in3", 1.5);
		break;

		case "Silvia_comes_in3":
			LAi_SetActorType(characterFromID("Silvia Haraldo"));
                        Lai_ActorFollow(characterFromID("Silvia Haraldo"), pchar, "Silvia_comes_in4", 2.0);
		break;

		case "Silvia_comes_in4":
			LAi_ActorDialog(characterFromID("Silvia Haraldo"), Pchar, "", 2.0, 0);
		break;

		case "Haraldo_switch1":
			Characters[GetCharacterIndex("Toni Haraldo")].dialog.currentnode = "Silvia_T1";
			LAi_SetActorType(characterFromID("Toni Haraldo"));
			LAi_ActorSetSitMode(characterFromID("Toni Haraldo"));
			LAi_ActorDialog(characterFromID("Toni Haraldo"), Pchar, "", 0.3, 0);
		break;

		case "Haraldo_switch2":
			Characters[GetCharacterIndex("Silvia Haraldo")].dialog.currentnode = "Silvia_S1";
			LAi_ActorDialog(characterFromID("Silvia Haraldo"), Pchar, "", 0.3, 0);
		break;

		case "Haraldo_switch3":
			Characters[GetCharacterIndex("Toni Haraldo")].dialog.currentnode = "Silvia_T2";
			LAi_ActorDialog(characterFromID("Toni Haraldo"), Pchar, "", 0.3, 0);
		break;

                case "Beatrice_returns_Martinica":
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				DoQuestReloadToLocation("Falaise_de_fleur_shore", "goto", "goto23" ,"Meet_after_Martinica");
			}
			else
			{
				DoQuestReloadToLocation("Falaise_de_fleur_port_01", "goto", "goto13" ,"Meet_after_Martinica");
			}
			AddMoneyToCharacter(pchar, 20000);
			LAi_SetPlayerType(Pchar);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 3000);
				AddPartyExpChar(pchar, "Sailing", 5000);
				AddPartyExpChar(pchar, "Repair", 2000);
			}
			else { AddPartyExp(pchar, 10000); }
                        bQuestDisableSeaEnter = false;
//			SetCharacterShipLocation(Pchar, "Falaise_de_fleur_port_01");

/*
			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);
*/

                        TakeItemFromCharacter(Pchar, "jauri_note");
			ChangeCharacterAddressGroup(characterFromID("Silvia Haraldo"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Toni Haraldo"), "none", "", "");
		break;

//=========================== FROM MARTINICA TO SANTIAGO ===========================================//

		case "Meet_after_Martinica":
			DeleteQuestHeader("Yo Ho Ho and a shipment of rum");

			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));	// If they're officers, they may not show up
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));
			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
				ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Falaise_de_fleur_shore", "goto", "goto22");
				ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Falaise_de_fleur_shore", "goto", "goto24");
				Pchar.quest.Martinica_Debriefing.win_condition.l1 = "locator";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.location = "Falaise_de_fleur_shore";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.locator_group = "reload";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.locator = "boat";
				Pchar.quest.Martinica_Debriefing.win_condition = "Martinica_Debriefing";

			}
			else
			{
				ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Falaise_de_fleur_port_01", "officers", "sea_1");
				ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Falaise_de_fleur_port_01", "officers", "sea_2");
				Pchar.quest.Martinica_Debriefing.win_condition.l1 = "locator";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.location = "Falaise_de_fleur_port_01";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.locator_group = "reload";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.locator = "sea_back";
				Pchar.quest.Martinica_Debriefing.win_condition = "Martinica_Debriefing";

			}
			LAi_QuestDelay("Meet_after_Martinica2", 0.0);
		break;

		case "Meet_after_Martinica2":
			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
//			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
//			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);
		break;

		case "Martinica_Debriefing":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));
			ChangeCharacterAddressGroup(characterfromID("Blaze Devlin"),"Cabin2SJG", "rld", "aloc0");
			ChangeCharacterAddressGroup(characterfromID("Bonnie Devlin"),"Cabin2SJG", "rld", "aloc3");
			DoQuestReloadToLocation("Cabin2SJG", "rld", "aloc4", "Martinica_Debriefing2");
//			DoReloadFromSeaToLocation("Cabin2SJG", "rld", "aloc4");
		break;

		case "Martinica_Debriefing2":
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Bonnie_Debriefing";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

		case "srsly_Blaze":
			LAi_SetActorType(characterFromID("Blaze Devlin"));
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "map_lost";
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 1.0, 0);
		break;

		case "optimism":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "optimism";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 1.0, 0);
		break;

		case "map_search":
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "optimism_cont";
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 1.0, 0);
		break;

		case "Martinica_to_Greenford":
			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));

			LAi_SetOfficerType(characterFromID("Blaze Devlin"));
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));

			DeleteQuestHeader("Yo Ho Ho and a shipment of rum");
			SetQuestHeader("El Navegante");
			AddQuestRecord("El Navegante", 1);

			if (PChar.location.from_sea == "Falaise_de_fleur_shore")
			{
                                QuestToSeaLogin_PrepareLoc("FalaiseDeFleur", "reload", "reload_2", false);
                                QuestToSeaLogin_Launch();
			}
			else
			{
                                QuestToSeaLogin_PrepareLoc("FalaiseDeFleur", "reload", "reload_1", false);
                                QuestToSeaLogin_Launch();
			}

			pchar.quest.OPERA = "ask_Simon_for_Malaga";
		break;

		case "Messenger_Greenford":
			AddQuestRecord("El Navegante", 2);

			ChangeCharacterAddressGroup(characterFromID("Mystery Messenger"), "Greenford_tavern", "reload", "reload1");

			LAi_SetActorType(characterFromID("Mystery Messenger"));
			LAi_ActorWaitDialog(pchar, characterFromID("Mystery Messenger"));
			Characters[GetCharacterIndex("Mystery Messenger")].dialog.currentnode = "Malaga";
			Lai_ActorFollow(characterFromID("Mystery Messenger"), pchar, "Messenger_Greenford2", 3.0);
		break;

		case "Messenger_Greenford2":
			LAi_ActorDialog(characterFromID("Mystery Messenger"), Pchar, "", 3.0, 0);
		break;

		case "Greenford2Santiago":
			LAi_ActorRunToLocator(characterFromID("Mystery Messenger"), "reload", "reload1", "Byebye_MM", 2.0);

			AddQuestRecord("El Navegante", 3);

			Pchar.quest.Cuban_history.win_condition.l1 = "location";
			Pchar.quest.Cuban_history.win_condition.l1.location = "Cuba";
			Pchar.quest.Cuban_history.win_condition = "Cuban_history";
		break;

		case "Byebye_MM":
			ChangeCharacterAddress(characterfromID("Mystery Messenger"),"none", "");
		break;

		case "Cuban_history":
			DoReloadFromSeaToLocation("Family_deck", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Blaze Devlin"),"Family_deck", "goto", "goto16");
			LAi_SetActorType(characterFromID("Blaze Devlin"));
			LAi_ActorWaitDialog(pchar, characterFromID("Blaze Devlin"));
			Characters[GetCharacterIndex("Blaze Devlin")].dialog.currentnode = "Cuban_history";
			Lai_ActorFollow(characterFromID("Blaze Devlin"), pchar, "Cuban_history2", 0.0);
		break;

		case "Cuban_history2":
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 2.0, 0);
		break;

		case "Cuban_history_over":
                        QuestToSeaLogin_PrepareLoc("Cuba", "Reload", "Reload_1", false);
                        QuestToSeaLogin_Launch();
			AddQuestRecord("El Navegante", 4);
			LAi_SetOfficerType(characterFromID("Blaze Devlin"));

			HoistFlag(SPAIN);
                        iForceDetectionFalseFlag = -1;

			Pchar.quest.Santiago_start.win_condition.l1 = "location";
			PChar.quest.Santiago_start.win_condition.l1.character = Pchar.id;
			Pchar.quest.Santiago_start.win_condition.l1.location = "Santiago_port";
			Pchar.quest.Santiago_start.win_condition = "Santiago_start";
		break;

//=========================== SANTIAGO ===========================================//

		case "Santiago_start":

			if (PChar.location.from_sea == "Santiago_port")
			{
			        Pchar.quest.Santiago_start.over = "yes";

			        SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));	// Force Bonnie and Blaze back to being officers
			        SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));	// in case player hired new officers on the way here

				ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Santiago_port", "officers", "reload2_1");
				ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Santiago_port", "officers", "reload2_2");

				ChangeCharacterAddressGroup(characterFromID("Crewmember Devlin"), "Santiago_port", "goto", "goto20");
			        LAi_SetActorType(characterFromID("Crewmember Devlin"));

			        LAi_SetActorType(characterFromID("Bonnie Devlin"));
	//			LAi_SetActorType(PChar);
	//			LAi_ActorWaitDialog(pchar, characterFromID("Bonnie Devlin"));
			        Lai_ActorFollow(characterFromID("Bonnie Devlin"), pchar, "Santiago_start2", 2.0);
			}
			Locations[FindLocation("Santiago_port")].reload.l2.disable = true;
			Locations[FindLocation("Santiago_port")].reload.l3.disable = true;
		break;

		case "Santiago_start2":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Santiago_arrival";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0.5);
		break;

		case "Santiago_switch_to_Blaze":
			LAi_SetActorType(characterFromID("Blaze Devlin"));
	//		LAi_SetActorType(PChar);
	//		LAi_ActorWaitDialog(pchar, characterFromID("Blaze Devlin"));
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "Malaga_ahoy";
			Lai_ActorFollow(characterFromID("Blaze Devlin"), pchar, "Santiago_switch_to_Blaze2", 0.1);
		break;

		case "Santiago_switch_to_Blaze2":
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 0.5, 0.5);
		break;

		case "Santiago_storytime":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Santiago_story";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 0.5, 0.5);
		break;

		case "Santiago_crewmember":
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(pchar, characterFromID("Crewmember Devlin"));
			Characters[GetCharacterIndex("Crewmember Devlin")].Dialog.CurrentNode = "Found_Navigator";
			Lai_ActorFollow(characterFromID("Crewmember Devlin"), pchar, "Santiago_crewmember2", 30.0);
		break;

		case "Santiago_crewmember2":
			LAi_ActorDialog(characterFromID("Crewmember Devlin"), Pchar, "", 20.0, 0.5);
		break;

		case "Santiago_split":
			LAi_SetPlayerType(PChar);
			LAi_ActorRunToLocator(characterFromID("Crewmember Devlin"), "reload", "reload2_back", "Byebye_CM", 5.0);

			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "Santiago_choose";
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 0.1, 0.5);
		break;

		case "Byebye_CM":
			ChangeCharacterAddress(characterfromID("Crewmember Devlin"),"none", "");
		break;

//--------------------------- BEATRICE SANTIAGO

		case "Beatrice_Santiago_start":
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "none", "", "");	//just to be sure
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "none", "", "");	//just to be sure
			RemovePassenger(Pchar, characterFromID("Bonnie Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));
			RemovePassenger(Pchar, characterFromID("Blaze Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));

			DoQuestReloadToLocation("Santiago_port", "reload", "reload2_back" ,"Beatrice_Santiago_start2");
			
			AddQuestRecord("El Navegante", 5);
                        bQuestDisableSeaEnter = true;

			SetCurrentTime(16.00, 0);
		break;

		case "Beatrice_Santiago_start2":
			SetNextWeather("Blue Sky");
                        Locations[FindLocation("Santiago_Tavern")].vcskip = true;

			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "Santiago_Tavern", "sit", "sit1");
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Beatrice";
		break;

		case "Sailor_search_start":
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "workinprogress";

			SetCurrentTime(22.00, 0);

			ChangeCharacterAddressGroup(characterFromID("Santiago_soldier_09"), "none", "", "");            // Remove Guards
			ChangeCharacterAddressGroup(characterFromID("Santiago_soldier_10"), "none", "", "");            // Remove Guards

			ChangeCharacterAddressGroup(characterFromID("Chorizo"), "Santiago_town_01", "goto", "goto44");

			ChangeCharacterAddressGroup(characterFromID("Juan"), "Santiago_town_01", "goto", "goto38");
			ChangeCharacterAddressGroup(characterFromID("Jorge"), "Santiago_church", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Paolo"), "Santiago_port", "goto", "goto41");

			Locations[FindLocation("Santiago_town_01")].reload.l5.close_for_night = 0;                      // Open Church
			Locations[FindLocation("Santiago_town_01")].reload.l2.close_for_night = 1;                      // Close Jungle Gate in town
			Locations[FindLocation("Santiago_port")].reload.l5.close_for_night = 1;                         // Close Jungle Gate in port

                        bQuestDisableSeaEnter = true;
			DisableFastTravel(true);

			pchar.quest.Ricardo_gate.win_condition.l1 = "locator";
			pchar.quest.Ricardo_gate.win_condition.l1.location = "Santiago_port";
			pchar.quest.Ricardo_gate.win_condition.l1.locator_group = "reload";
			pchar.quest.Ricardo_gate.win_condition.l1.locator = "reload4";
			pchar.quest.Ricardo_gate.win_condition = "Ricardo_gate";

			pchar.quest.JUAN = "loose";
			pchar.quest.PAOLO = "loose";
			pchar.quest.JORGE = "loose";
			pchar.quest.RICARDO = "loose";
			pchar.quest.PEDRO = "loose";
			pchar.quest.DEVLINTAVERN = "blocked";
		break;

//----------------------- JUAN

		case "Juan_search_bucket":
			AddQuestRecord("El Navegante", 8);

			pchar.quest.Juan_found_bucket.win_condition.l1 = "locator";
			pchar.quest.Juan_found_bucket.win_condition.l1.location = "Santiago_town_01";
			pchar.quest.Juan_found_bucket.win_condition.l1.locator_group = "merchant";
			pchar.quest.Juan_found_bucket.win_condition.l1.locator = "merchant5";
			pchar.quest.Juan_found_bucket.win_condition = "Juan_found_bucket";
		break;

		case "Juan_found_bucket":
			GiveItem2Character(PChar, "juan_bucket_emp");
			PlaySound("INTERFACE\took_item.flac");

			Pchar.quest.Juan_found_bucket.over = "yes";

			pchar.quest.Juan_filled_bucket.win_condition.l1 = "locator";
			pchar.quest.Juan_filled_bucket.win_condition.l1.location = "Santiago_port";
			pchar.quest.Juan_filled_bucket.win_condition.l1.locator_group = "reload";
			pchar.quest.Juan_filled_bucket.win_condition.l1.locator = "reload2_back";
			pchar.quest.Juan_filled_bucket.win_condition = "Juan_filled_bucket";
		break;

		case "Juan_filled_bucket":
			GiveItem2Character(PChar, "juan_bucket_ful");
                        TakeItemFromCharacter(PChar, "juan_bucket_emp");
			PlaySound("NATURE\water_in.wav");
			Pchar.quest.Juan_filled_bucket.over = "yes";
			Characters[GetCharacterIndex("Juan")].Dialog.CurrentNode = "Awaiting_water";
		break;

		case "Juan_showertime":
			LAi_SetActorType(pchar);
			PlaySound("NATURE\water_in.wav");
			LAi_QuestDelay("Juan_showertime2", 3.0);
		break;

		case "Juan_showertime2":
			LAi_SetPoorType(characterFromID("Juan"));
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_03.wav");
			LAi_QuestDelay("Juan_showertime3", 2.0);
		break;

		case "Juan_showertime3":
			LAi_SetStayType(characterFromID("Juan"));
			LAi_SetActorType(characterFromID("Juan"));
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Juan")].Dialog.CurrentNode = "Finally_awake";
			LAi_ActorDialog(characterFromID("Juan"), Pchar, "", 0.5, 0);
                        TakeItemFromCharacter(PChar, "juan_bucket_ful");
		break;

		case "Juan_returns":
			LAi_ActorRunToLocator(characterFromID("Juan"), "reload", "reload1", "byebye_Juan", 30.0);

			pchar.quest.JUAN = "found";

			AddQuestRecord("El Navegante", 9);

                        if (CheckQuestAttribute("PAOLO", "found") && CheckQuestAttribute("JORGE", "found") && CheckQuestAttribute("RICARDO", "found") && CheckQuestAttribute("PEDRO", "found"))
                        {
			         LAi_QuestDelay("Found_five_sailors", 1.0);
                        }
		break;

		case "byebye_Juan":
			ChangeCharacterAddressGroup(characterFromID("Juan"), "none", "", "");
		break;

//----------------------- PAOLO

		case "Paolo_go_to_Store":
			Characters[GetCharacterIndex("Paolo")].Dialog.CurrentNode = "No_paper_yet";

			AddQuestRecord("El Navegante", 10);

			pchar.quest.Paolo_knock_Store.win_condition.l1 = "locator";
			pchar.quest.Paolo_knock_Store.win_condition.l1.location = "Santiago_town_01";
			pchar.quest.Paolo_knock_Store.win_condition.l1.locator_group = "reload";
			pchar.quest.Paolo_knock_Store.win_condition.l1.locator = "reload6";
			pchar.quest.Paolo_knock_Store.win_condition = "Paolo_knock_Store";
		break;

		case "Paolo_knock_Store":
			Pchar.quest.Paolo_knock_Store.over = "yes";
			LAi_SetActorType(pchar);
			PlaySound("INTERFACE\knock.wav");
			LAi_QuestDelay("Paolo_knock_Store2", 2.0);
		break;

		case "Paolo_knock_Store2":
			PlaySound("INTERFACE\key_lock.wav");
			ChangeCharacterAddressGroup(characterfromID("Fake Storeman"),"Santiago_town_01", "reload", "reload6");
			LAi_QuestDelay("Paolo_knock_Store3", 2.0);
		break;

		case "Paolo_knock_Store3":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Fake Storeman"));
			//Characters[GetCharacterIndex("Fake Storeman")].Dialog.CurrentNode = "Fake1";
			LAi_ActorDialog(characterFromID("Fake Storeman"), Pchar, "", 0.5, 0);
		break;

		case "Paolo_Fake_runs_Home":
			LAi_ActorRunToLocator(characterFromID("Fake Storeman"), "reload", "reload8", "Paolo_Fake_Home", 25.0);
		break;

		case "Paolo_Fake_Home":
			LAi_SetActorType(pchar);
			ChangeCharacterAddressGroup(characterfromID("Fake Storeman"),"none", "", "");
			PlaySound("INTERFACE\creak.wav");
			LAi_QuestDelay("Paolo_Fake_Home2", 3.0);
		break;

		case "Paolo_Fake_Home2":
			LAi_SetPlayerType(pchar);
			PlaySound("INTERFACE\creak.wav");
			ChangeCharacterAddressGroup(characterfromID("Fake Storeman"),"Santiago_town_01", "reload", "reload8");
			Characters[GetCharacterIndex("Fake Storeman")].Dialog.CurrentNode = "Paper";
			LAi_ActorDialog(characterFromID("Fake Storeman"), Pchar, "", 0.5, 0);
		break;

		case "Paolo_got_Paper":
			GiveItem2Character(PChar, "sketch_paper");
			LAi_SetActorType(pchar);
			LAi_QuestDelay("Paolo_infidelity", 1.5);
		break;

		case "Paolo_infidelity":
			PlaySound("VOICE\ENGLISH\do_gigglekiss.wav");
			LAi_QuestDelay("Paolo_infidelity2", 1.5);
		break;

		case "Paolo_infidelity2":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Fake Storeman")].Dialog.CurrentNode = "Infidelity";
			LAi_ActorDialog(characterFromID("Fake Storeman"), Pchar, "", 0.5, 0);
		break;

		case "Paolo_infidelity3":
			LAi_SetActorType(pchar);
			ChangeCharacterAddressGroup(characterfromID("Fake Storeman"),"none", "", "");
			PlaySound("INTERFACE\creak.wav");
			LAi_QuestDelay("Paolo_infidelity4", 2.5);
		break;

		case "Paolo_infidelity4":
			LAi_SetPlayerType(pchar);
			PlaySound("INTERFACE\creak.wav");
			ChangeCharacterAddressGroup(characterfromID("Pedro"),"Santiago_town_01", "reload", "reload8");
			LAi_SetActorType(characterFromID("Pedro"));
			LAi_ActorRunToLocator(characterFromID("Pedro"), "merchant", "merchant1", "Pedro_smithy", 60.0);
			Characters[GetCharacterIndex("Paolo")].Dialog.CurrentNode = "YourPaper";
		break;

		case "Paolo_sketching":
                        TakeItemFromCharacter(PChar, "sketch_paper");
			LAi_SetActorType(pchar);
			PlaySound("INTERFACE\writing.wav");
			LAi_QuestDelay("Paolo_sketchfin", 1.0);
		break;

		case "Paolo_sketchfin":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Paolo")].Dialog.CurrentNode = "YourPaper2";
			LAi_SetActorType(characterFromID("Paolo"));
			LAi_ActorDialog(characterFromID("Paolo"), Pchar, "", 0.5, 0);
		break;

		case "Paolo_returns":
			LAi_ActorRunToLocator(characterFromID("Paolo"), "reload", "reload2_back", "byebye_Paolo", 40.0);

			pchar.quest.PAOLO = "found";

			AddQuestRecord("El Navegante", 11);

                        if (CheckQuestAttribute("JUAN", "found") && CheckQuestAttribute("JORGE", "found") && CheckQuestAttribute("RICARDO", "found") && CheckQuestAttribute("PEDRO", "found"))
                        {
			         LAi_QuestDelay("Found_five_sailors", 1.0);
                        }
		break;

		case "byebye_Paolo":
			ChangeCharacterAddressGroup(characterFromID("Paolo"), "none", "", "");
		break;

//----------------------- JORGE

		case "Jorge_search_bible":
			Characters[GetCharacterIndex("Jorge")].Dialog.CurrentNode = "bibleprog";

			AddQuestRecord("El Navegante", 13);

			pchar.quest.JORGE = "search_bible";
		break;


		case "Jorge_found_bible":
			pchar.quest.JORGE = "found_bible";

			GiveItem2Character(PChar, "jorge_bible");

			Characters[GetCharacterIndex("Jorge")].Dialog.CurrentNode = "Hallelujah";
		break;

		case "Jorge_returns":
                        TakeItemFromCharacter(PChar, "jorge_bible");

			LAi_SetStayType(characterFromID("Jorge"));
			LAi_SetActorType(characterFromID("Jorge"));

			ChangeCharacterAddressGroup(characterfromID("Jorge"),"Santiago_church", "reload", "reload1");

			pchar.quest.JORGE = "found";

			AddQuestRecord("El Navegante", 14);

                        if (CheckQuestAttribute("PAOLO", "found") && CheckQuestAttribute("JUAN", "found") && CheckQuestAttribute("RICARDO", "found") && CheckQuestAttribute("PEDRO", "found"))
                        {
			         LAi_QuestDelay("Found_five_sailors", 1.0);
                        }

			LAi_QuestDelay("byebye_Jorge", 2.0);
		break;

		case "byebye_Jorge":
			ChangeCharacterAddressGroup(characterFromID("Jorge"), "none", "", "");
		break;

//----------------------- RICARDO

		case "Ricardo_gate":
			Pchar.quest.Ricardo_gate.over = "yes";
			LAi_SetActorType(pchar);
			PlaySound("INTERFACE\knock.wav");
			Pchar.dialog.CurrentNode = "Ricardo";
			LAi_QuestDelay("Ricardo_gate2", 1.0);
		break;

		case "Ricardo_gate2":
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Ricardo_search_Officer":
			LAi_SetPlayerType(pchar);
			AddQuestRecord("El Navegante", 15);
			pchar.quest.RICARDO = "search_key";
		break;

		case "Ricardo_have_key":
			pchar.quest.RICARDO = "have_key";
			GiveItem2Character(PChar, "santiago_key");

			pchar.quest.Ricardo_open.win_condition.l1 = "locator";
			pchar.quest.Ricardo_open.win_condition.l1.location = "Santiago_port";
			pchar.quest.Ricardo_open.win_condition.l1.locator_group = "reload";
			pchar.quest.Ricardo_open.win_condition.l1.locator = "reload4";
			pchar.quest.Ricardo_open.win_condition = "Ricardo_open";
		break;

		case "Ricardo_open":
			Pchar.quest.Ricardo_open.over = "yes";
			LAi_SetActorType(pchar);
			PlaySound("INTERFACE\key_unlock.wav");
			LAi_QuestDelay("Ricardo_open2", 1.0);
		break;

		case "Ricardo_open2":
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(characterFromID("Ricardo"), "Santiago_port", "reload", "reload4");
			LAi_SetActorType(characterFromID("Ricardo"));
			LAi_QuestDelay("Ricardo_open3", 1.0);
		break;

		case "Ricardo_open3":
			LAi_ActorDialog(characterFromID("Ricardo"), Pchar, "", 0.5, 0);
		break;

		case "Ricardo_returns":
			Locations[FindLocation("Santiago_port")].reload.l5.close_for_night = 0;                         // Open Jungle Gate in port again

			LAi_ActorRunToLocator(characterFromID("Ricardo"), "reload", "reload2_back", "byebye_Ricardo", 60.0);

			pchar.quest.RICARDO = "return_key";

			AddQuestRecord("El Navegante", 16);
		break;

		case "byebye_Ricardo":
			ChangeCharacterAddressGroup(characterFromID("Ricardo"), "none", "", "");
		break;

		case "Ricardo_finished":
			pchar.quest.RICARDO = "found";

                        TakeItemFromCharacter(PChar, "santiago_key");

                        if (CheckQuestAttribute("JUAN", "found") && CheckQuestAttribute("JORGE", "found") && CheckQuestAttribute("PEDRO", "found") && CheckQuestAttribute("PAOLO", "found"))
                        {
			         LAi_QuestDelay("Found_five_sailors", 1.0);
                        }
		break;


//----------------------- PEDRO

		case "Pedro_smithy":
			LAi_SetStayType(characterFromID("Pedro"));
		break;

		case "Pedro_returns":
			LAi_SetActorType(characterFromID("Pedro"));
			LAi_ActorRunToLocator(characterFromID("Pedro"), "reload", "reload1", "byebye_Pedro", 60.0);

			pchar.quest.PEDRO = "found";

			AddQuestRecord("El Navegante", 12);

                        if (CheckQuestAttribute("JUAN", "found") && CheckQuestAttribute("JORGE", "found") && CheckQuestAttribute("RICARDO", "found") && CheckQuestAttribute("PAOLO", "found"))
                        {
			         LAi_QuestDelay("Found_five_sailors", 1.0);
                        }
		break;

		case "byebye_Pedro":
			ChangeCharacterAddressGroup(characterFromID("Pedro"), "none", "", "");
		break;

//-----------------------------------------------------

		case "Found_five_sailors":
			AddQuestRecord("El Navegante", 17);
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Beatrice_found_Sailors";
		break;

		case "Beatrice_returns_Santiago":
			DoQuestReloadToLocation("Santiago_port", "reload", "reload1" ,"Meet_after_Santiago");

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 8000);
				AddPartyExpChar(pchar, "Sailing", 5000);
				AddPartyExpChar(pchar, "Repair", 5000);
			}
			else { AddPartyExp(pchar, 16000); }

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			LAi_SetOfficerType(characterFromID("Blaze Devlin"));

			ChangeCharacterAddressGroup(characterFromID("Santiago_soldier_09"), "Santiago_port", "goto", "goto30");            // Return Guards
			ChangeCharacterAddressGroup(characterFromID("Santiago_soldier_10"), "Santiago_port", "goto", "goto31");            // Return Guards

			ChangeCharacterAddressGroup(characterFromID("Chorizo"), "none", "", "");

			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "none", "", "");

			Locations[FindLocation("Santiago_town_01")].reload.l5.close_for_night = 1;                      // 
			Locations[FindLocation("Santiago_town_01")].reload.l2.close_for_night = 0;                      //

			DeleteQuestAttribute("DEVLINTAVERN");
//			pchar.quest.DEVLINTAVERN = "unblocked"; 

                        Locations[FindLocation("Santiago_Tavern")].vcskip = false;
		break;

//------------------------- BONNIE SANTIAGO

		case "Bonnie_Santiago_start":
			DoQuestReloadToLocation("Santiago_port", "reload", "reload2_back" ,"Bonnie_Santiago_start2");
			
			AddQuestRecord("El Navegante", 5);
                        bQuestDisableSeaEnter = true

			SetCurrentTime(16.00, 0);
		break;


		case "Bonnie_Santiago_start2":
			SetNextWeather("Blue Sky");
                        Locations[FindLocation("Santiago_Tavern")].vcskip = true;

			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "Santiago_Tavern", "sit", "sit7");
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Bonnie";

			AddMoneyToCharacter(PChar, 100);				// Give Bonnie some money, she may need it
			PChar.quest.orig_money = sti(Pchar.quest.orig_money) - 100;	// Take it from what you'll get back, you're not getting free money!
		break;

		case "Bonnie_joins_Balboa_table":
			LAi_Fade("Bonnie_joins_Balboa_table_2", "Bonnie_joins_Balboa_table_3");
		break;

		case "Bonnie_joins_Balboa_table_2":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Santiago_tavern", "sit", "sit6");
		break;

		case "Bonnie_joins_Balboa_table_3":
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "notyet_drunk";
			LAi_ActorDialogNow(Pchar, characterFromID("Rocoso Balboa"), "", -1);
		break;

		case "Bonnie_joins_Balboa_table_4":
			LAi_Fade("Bonnie_joins_Balboa_table_2", "Bonnie_joins_Balboa_table_5");
			SetCurrentTime(19.00, 0);
		break;

		case "Bonnie_joins_Balboa_table_5":
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "slightly_drunk";
			LAi_ActorDialogNow(Pchar, characterFromID("Rocoso Balboa"), "", -1);
		break;

		case "Bonnie_joins_Balboa_table_6":
			LAi_Fade("Bonnie_joins_Balboa_table_2", "Bonnie_joins_Balboa_table_7");
			SetCurrentTime(22.00, 0);
		break;

		case "Bonnie_joins_Balboa_table_7":
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "clearly_drunk";
			LAi_ActorDialogNow(Pchar, characterFromID("Rocoso Balboa"), "", -1);
		break;

		case "Bonnie_and_Balboa_on_the_town":
                        bQuestDisableSeaEnter = true
			DisableFastTravel(true);

                        DoQuestReloadToLocation("Santiago_port", "goto", "goto46", "Bonnie_and_Balboa_on_the_town2")
			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "Santiago_port", "officers", "reload3_2");

			ChangeCharacterAddressGroup(characterFromID("Don Evaristo Torres"), "Santiago_port", "goto", "goto27");

			LAi_SetActorType(characterFromID("Rocoso Balboa"));
			LAi_ActorSetStayMode(characterFromID("Rocoso Balboa"));
			LAi_ActorSetStayMode(pchar);
		break;

		case "Bonnie_and_Balboa_on_the_town2":
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "extrem_drunk";
			LAi_ActorDialog(characterFromID("Rocoso Balboa"), Pchar, "", 1.0, 0);
			LAi_SetPlayerType(pchar);
		break;

		case "Balboa_caught":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Don Evaristo Torres"));
			LAi_ActorWaitDialog(pchar, characterFromID("Don Evaristo Torres"));
			Characters[GetCharacterIndex("Don Evaristo Torres")].Dialog.CurrentNode = "Balboa_still_here";
			Lai_ActorFollow(characterFromID("Don Evaristo Torres"), pchar, "Balboa_caught2", 8.0);
		break;

		case "Balboa_caught2":
			LAi_ActorDialog(characterFromID("Don Evaristo Torres"), Pchar, "", 8.0, 0);
		break;

		case "Balboa_and_Torres_to_ship":
			DoQuestReloadToLocation("Cabin2SJG", "rld", "aloc4", "Balboa_and_Torres_to_ship2");
			ChangeCharacterAddressGroup(characterfromID("Don Evaristo Torres"),"Cabin2SJG", "rld", "aloc3");

			LAi_ActorWaitDialog(pchar, characterFromID("Don Evaristo Torres"));
			Characters[GetCharacterIndex("Don Evaristo Torres")].Dialog.CurrentNode = "Punishment";
		break;

		case "Balboa_and_Torres_to_ship2":
			LAi_ActorDialog(characterFromID("Don Evaristo Torres"), Pchar, "", 0.5, 0);
		break;

		case "Balboa_will_survive":
			DoQuestReloadToLocation("Cabin4", "rld", "loc6", "Balboa_and_Torres_to_ship2");
			ChangeCharacterAddressGroup(characterfromID("Rocoso Balboa"),"Cabin4", "rld", "aloc2");
			LAi_SetStayType(characterFromID("Rocoso Balboa"));
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "survived";
		break;

                case "Bonnie_returns_Santiago_saved":
			DoQuestReloadToLocation("Santiago_port", "reload", "reload1" ,"Meet_after_Santiago");

			ChangeCharacterReputation(pchar, 30);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 7000);
				AddPartyExpChar(pchar, "Commerce", 5000);
			}
			else { AddPartyExp(pchar, 12000); }

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			LAi_SetOfficerType(characterFromID("Blaze Devlin"));

			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Don Evaristo Torres"), "none", "", "");

                        Locations[FindLocation("Santiago_Tavern")].vcskip = false;

			CloseQuestHeader("El Navegante");
		break;

//---------------- Bonnie path 2 send men away


		case "Balboa_hides":
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(characterFromID("Rocoso Balboa"), "reload", "reload3", "Balboa_enters_shipyard", 1.0);
		break;

		case "Balboa_enters_shipyard":
			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "Santiago_shipyard", "goto", "goto6");
                        PlaySound("PEOPLE\creak.wav");

			LAi_SetActorType(characterFromID("Don Evaristo Torres"));
			LAi_ActorWaitDialog(pchar, characterFromID("Don Evaristo Torres"));
			Characters[GetCharacterIndex("Don Evaristo Torres")].Dialog.CurrentNode = "Balboa_now_hidden";
			Lai_ActorFollow(characterFromID("Don Evaristo Torres"), pchar, "Balboa_hides2", 8.0);
		break;

		case "Balboa_hides2":
			LAi_ActorDialog(characterFromID("Don Evaristo Torres"), Pchar, "", 8.0, 0);
		break;

		case "Torres_has_spoken":
			Locations[FindLocation("Santiago_port")].reload.l4.close_for_night = 0;                      // Open Shipyard
			LAi_SetPlayerType(pchar);

			LAi_ActorRunToLocator(characterFromID("Don Evaristo Torres"), "goto", "goto27", "byebye_DonEvaristo", 8.0);
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Balboa_is_inside_shipyard";
			LAi_SetStayType(characterFromID("Rocoso Balboa"));
		break;

		case "byebye_DonEvaristo":
			ChangeCharacterAddressGroup(characterFromID("Don Evaristo Torres"), "none", "", "");
		break;

		case "Bonnie_look_if_safe":
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "crying";
			ChangeCharacterAddressGroup(characterFromID("Dragan van Mourik"), "Santiago_port", "goto", "goto27");

			ChangeCharacterAddressGroup(characterFromID("Juan"), "Santiago_port", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Pedro"), "Santiago_port", "goto", "goto25");

			LAi_SetActorType(characterFromID("Juan"));
			Characters[GetCharacterIndex("Pedro")].Dialog.CurrentNode = "Pedro_watching";
		break;

		case "Pedro_and_Juan_gone":
			LAi_SetActorType(characterFromID("Pedro"));

			AddQuestRecord("El Navegante", 19);

			LAi_ActorRunToLocator(characterFromID("Juan"), "reload", "reload1", "byebye_JuanandPedro", 30.0);
			LAi_ActorRunToLocator(characterFromID("Pedro"), "reload", "reload1", "byebye_JuanandPedro", 30.0);

			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Coast_clear";
			ChangeCharacterAddressGroup(characterFromID("Dragan van Mourik"), "none", "", "");
		break;

		case "byebye_JuanandPedro":
			ChangeCharacterAddressGroup(characterFromID("Juan"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Pedro"), "none", "", "");
		break;

                case "Bonnie_returns_Santiago_sneaked":
			DoQuestReloadToLocation("Santiago_port", "reload", "reload1" ,"Meet_after_Santiago");

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 7000);
				AddPartyExpChar(pchar, "Sneak", 5000);
			}
			else { AddPartyExp(pchar, 12000); }

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			LAi_SetOfficerType(characterFromID("Blaze Devlin"));

			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "none", "", "");

                        Locations[FindLocation("Santiago_Tavern")].vcskip = false;
			Locations[FindLocation("Santiago_port")].reload.l4.close_for_night = 1;                      // Close Shipyard

			CloseQuestHeader("El Navegante");
		break;

//------------------ Dragan van Mouriks robe

		case "Handing_over_robe":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Dragan van Mourik"));

                        PlaySound("PEOPLE\clothes1.wav");

			AddMoneyToCharacter(pchar, -25);

			SetModelfromID(CharacterFromID("Dragan van Mourik"), "man5_1");

			GiveItem2Character(PChar, "blue_robe");

                        LAi_QuestDelay("Handing_over_robe2", 1.5);
		break;

		case "Handing_over_robe2":
			Characters[GetCharacterIndex("Dragan van Mourik")].Dialog.CurrentNode = "Dragan_naked";
			LAi_ActorDialog(characterFromID("Dragan van Mourik"), Pchar, "", 0.5, 0);

			LAi_ActorWaitDialog(pchar, characterFromID("Dragan van Mourik"));
			Lai_ActorFollow(characterFromID("Dragan van Mourik"), pchar, "This_code_sucks3", 0.5);
		break;

		case "This_code_sucks3":
			LAi_ActorDialog(characterFromID("Dragan van Mourik"), Pchar, "", 0.5, 0);
		break;

		case "Bonnie_has_robe":
			LAi_ActorGoToLocator(characterFromID("Dragan van Mourik"), "goto", "goto27", "byebye_Dragan",6);
			AddQuestRecord("El Navegante", 20);

			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Pedro"));
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Ready_for_robe";
		break;

		case "Dragan_wont_sell":
			LAi_ActorGoToLocator(characterFromID("Dragan van Mourik"), "goto", "goto27", "byebye_Dragan",6);
		break;

		case "byebye_Dragan":
			ChangeCharacterAddressGroup(characterFromID("Dragan van Mourik"), "none", "", "");
		break;

		case "Balboa_is_changing":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Rocoso Balboa"));

                        PlaySound("PEOPLE\clothes1.wav");

			//SetModelfromID(CharacterFromID("Rocoso Balboa"), "AnimistEdmundo");
                        //SetModelfromArray(CharacterFromID("Rocoso Balboa"), GetModelIndex("AnimistEdmundo"));
                        SetModel(characterFromID("Rocoso Balboa"), "AnimistEdmundo", "man", "man", 1.8, false);

                        TakeItemFromCharacter(PChar, "blue_robe")

                        LAi_QuestDelay("Balboa_is_changing2", 1.5);
		break;

		case "Balboa_is_changing2":
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Balboa_now_changed";
			LAi_ActorDialog(characterFromID("Rocoso Balboa"), Pchar, "", 0.5, 0);

			LAi_ActorWaitDialog(pchar, characterFromID("Rocoso Balboa"));
			Lai_ActorFollow(characterFromID("Rocoso Balboa"), pchar, "Balboa_is_changing3", 0.5);
		break;

		case "Balboa_is_changing3":
			LAi_ActorDialog(characterFromID("Rocoso Balboa"), Pchar, "", 0.5, 0);
		break;

		case "Balboa_disguised":
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Rocoso Balboa"));
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Balboa_undercover";

			AddPassenger(Pchar, characterFromID("Rocoso Balboa"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Rocoso Balboa"));
			LAi_SetImmortal(characterFromID("Rocoso Balboa"), true);

                        Locations[FindLocation("Santiago_port")].locators_radius.goto.goto25 = 8.0;

                        pchar.quest.Pedro_stops_you.win_condition.l1 = "locator";
                        pchar.quest.Pedro_stops_you.win_condition.l1.location = "Santiago_port";
                        pchar.quest.Pedro_stops_you.win_condition.l1.locator_group = "goto";
                        pchar.quest.Pedro_stops_you.win_condition.l1.locator = "goto25";
                        pchar.quest.Pedro_stops_you.win_condition = "Pedro_stops_you";
		break;

		case "Pedro_stops_you":
			LAi_SetActorType(pchar);
			Characters[GetCharacterIndex("Pedro")].Dialog.CurrentNode = "why_you_robe";

			LAi_ActorWaitDialog(pchar, characterFromID("Pedro"));
			Lai_ActorFollow(characterFromID("Pedro"), pchar, "Pedro_stops_you2", 2.0);
		break;

		case "Pedro_stops_you2":
			LAi_ActorDialog(characterFromID("Pedro"), Pchar, "", 0.5, 0);
		break;

		case "Pedro_and_Juan_afraid":
			RemovePassenger(Pchar, characterFromID("Rocoso Balboa"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rocoso Balboa"));
			LAi_SetActorType(characterFromID("Rocoso Balboa"));
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Robie_saved";
			LAi_SetPlayerType(pchar);

			LAi_ActorRunToLocator(characterFromID("Juan"), "reload", "reload1", "byebye_JuanandPedro", 30.0);
			LAi_ActorRunToLocator(characterFromID("Pedro"), "reload", "reload1", "byebye_JuanandPedro", 30.0);

			LAi_ActorWaitDialog(pchar, characterFromID("Rocoso Balboa"));
			Lai_ActorFollow(characterFromID("Rocoso Balboa"), pchar, "Disguised_Balboa_save", 2.5);
		break;

		case "Disguised_Balboa_save":
                        Locations[FindLocation("Santiago_port")].locators_radius.goto.goto25 = 1.0;
			LAi_ActorDialog(characterFromID("Rocoso Balboa"), Pchar, "", 0.5, 0);
		break;



//--------------------------- BLAZE SANTIAGO

		case "Blaze_Santiago_start":
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "none", "", "");	//just to be sure
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "none", "", "");	//just to be sure
			RemovePassenger(Pchar, characterFromID("Bonnie Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));
			RemovePassenger(Pchar, characterFromID("Blaze Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));

			DoQuestReloadToLocation("Santiago_port", "reload", "reload2_back" ,"Blaze_Santiago_start2");
			
			AddQuestRecord("El Navegante", 5);
                        bQuestDisableSeaEnter = true

			SetCurrentTime(14.00, 0);
		break;

		case "Blaze_Santiago_start2":
			SetNextWeather("Blue Sky");
                        Locations[FindLocation("Santiago_Tavern")].vcskip = true;

			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "Santiago_Tavern", "sit", "sit1");
			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Blaze";
		break;

		case "Setting_up_Duel":
                        bQuestDisableSeaEnter = true
			DisableFastTravel(true);

			DoQuestReloadToLocation("Santiago_town_01", "goto", "goto51" ,"Setting_up_Duel2");
		break;

		case "Setting_up_Duel2":
			LAi_SetStayType(characterFromID("Rocoso Balboa"));
			LAi_SetActorType(characterFromID("Rocoso Balboa"));

			LAi_SetActorType(pchar);

			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Balboa_challenge";
			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "Santiago_town_01", "goto", "goto52");
			LAi_ActorWaitDialog(pchar, characterFromID("Rocoso Balboa"));
			Lai_ActorFollow(characterFromID("Rocoso Balboa"), pchar, "Setting_up_Duel3", 3.0);
		break;

		case "Setting_up_Duel3":
			LAi_ActorDialog(characterFromID("Rocoso Balboa"), Pchar, "", 0.0, 0);
		break;

		case "Duel_Blaze_Balboa":
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(characterFromID("Rocoso Balboa"), true);
			LAi_ActorAttack(characterfromID("Rocoso Balboa"), PChar, "");
                        LAi_QuestDelay("bigfatnope", 12.0);
		break;

		case "bigfatnope":
			LAi_SetFightMode(PChar, false);
                        Characters[GetCharacterIndex("Rocoso Balboa")].dialog.CurrentNode = "NOPE";
			SetCharacterRelationBoth(GetCharacterIndex("Rocoso Balboa"), GetMainCharacterIndex(), RELATION_FRIEND);
			LAi_SetActorType(characterFromID("Rocoso Balboa"));
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(PChar,characterFromID("Rocoso Balboa"));
                        LAi_ActorDialog(characterFromID("Rocoso Balboa"), PChar, "Balboa_flees_duel", 1.5, 1.5);
		break;

		case "Balboa_flees_duel":
			LAi_SetPlayerType(pchar);
			logit(TranslateString("","That coward is trying to escape! Go after him!"));
			LAi_SetActorType(characterFromID("Rocoso Balboa"));
			LAi_ActorRunToLocation(CharacterFromID("Rocoso Balboa"), "reload", "reload2", "Santiago_town_exit1", "officers", "reload2_2", "Balboa_flees_duel2", 35.0);
		break;

		case "Balboa_flees_duel2":
                        Locations[FindLocation("Santiago_town_exit1")].vcskip = true;
			Pchar.quest.Balboa_outskirts.win_condition.l1 = "location";
			PChar.quest.Balboa_outskirts.win_condition.l1.character = Pchar.id;
			Pchar.quest.Balboa_outskirts.win_condition.l1.location = "Santiago_town_exit1";
			Pchar.quest.Balboa_outskirts.win_condition = "Balboa_outskirts";
		break;

		case "Balboa_outskirts":
			ChangeCharacterAddressGroup(characterFromID("Kevin Poor"), "Santiago_town_exit1", "monsters", "monster2");
			ChangeCharacterAddressGroup(characterFromID("Grunk"), "Santiago_town_exit1", "monsters", "monster1");
			ChangeCharacterAddressGroup(characterFromID("Flobb"), "Santiago_town_exit1", "monsters", "monster4");
			LAi_SetActorType(characterFromID("Kevin Poor"));
			LAi_SetActorType(characterFromID("Grunk"));
			LAi_SetActorType(characterFromID("Flobb"));

			logit(TranslateString("","Keep going, he can't run from you forever!"));
			LAi_ActorRunToLocator(CharacterFromID("Rocoso Balboa"), "goto", "goto2", "Bandits_approach", 30.0);
		break;

		case "Bandits_approach":
			LAi_SetActorType(pchar);
			Lai_ActorFollow(characterFromID("Kevin Poor"), pchar, "Bandits_approach2", 3.0);
			LAi_ActorWaitDialog(pchar, characterFromID("Kevin Poor"));
			Lai_ActorFollow(characterFromID("Grunk"), pchar, "", 8.0);
		break;

		case "Bandits_approach2":
			LAi_ActorDialog(characterFromID("Kevin Poor"), Pchar, "", 1.0, 0);
		break;

		case "Kevin_attacks":
			LAi_SetPlayerType(pchar);
			LAi_SetWarriorType(CharacterFromID("Kevin Poor"));
			LAi_SetWarriorType(CharacterFromID("Grunk"));
			LAi_SetWarriorType(CharacterFromID("Flobb"));

			LAi_group_MoveCharacter(CharacterFromID("Kevin Poor"), "Kevin_Bandits");
			LAi_group_MoveCharacter(CharacterFromID("Grunk"), "Kevin_Bandits");
			LAi_group_MoveCharacter(CharacterFromID("Flobb"), "Kevin_Bandits");

			LAi_warrior_SetCommander(CharacterFromID("Grunk"), CharacterFromID("Kevin Poor"));
			LAi_warrior_SetCommander(CharacterFromID("Flobb"), CharacterFromID("Kevin Poor"));

			LAi_group_SetCheck("Kevin_Bandits", "Killed_Kevin");

			LAi_group_FightGroups("Kevin_Bandits", LAI_GROUP_PLAYER, 1);
		break;

		case "Killed_Kevin":
			LAi_SetFightMode(PChar, false);
                        Characters[GetCharacterIndex("Rocoso Balboa")].dialog.CurrentNode = "Bandits_ded_now";
                        LAi_ActorDialog(characterFromID("Rocoso Balboa"), PChar, "", 2.0, 2.0);
		break;

		case "Blaze_spared_Balboa":
			LAi_ActorRunToLocator(CharacterFromID("Rocoso Balboa"), "reload", "reload2", "Blaze_business_fin", 5.0);
		break;

		case "Blaze_business_fin":
                        LAi_QuestDelay("Blaze_returns_Santiago", 0.5);
                        LAi_QuestDelay("Switch_to_Beatrice", 0.5);
		break;

//------------------

		case "Blaze_killed_Balboa":
			LAi_SetFightMode(PChar, true);
			LAi_SetImmortal(characterFromID("Rocoso Balboa"), false);
			ChangeCharacterReputation(pchar, -30);
			LAi_SetCheckMinHP(CharacterFromID("Rocoso Balboa"), 0.0, 0, "Balboa_u_ded");
			LAi_SetStayType(characterFromID("Rocoso Balboa"));
		break;

		case "Balboa_u_ded":
			LAi_SetActorType(pchar);
			Pchar.dialog.CurrentNode = "Balboa_ded";
			LAi_ActorSelfDialog(PChar, "");
		break;

                case "Blaze_returns_Santiago":
			LAi_SetPlayerType(pchar);
			DoQuestReloadToLocation("Santiago_port", "reload", "reload1" ,"Meet_after_Santiago");

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Fencing", 8000);
				AddPartyExpChar(pchar, "Defence", 4000);
			}
			else { AddPartyExp(pchar, 12000); }

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			LAi_SetOfficerType(characterFromID("Blaze Devlin"));

			ChangeCharacterAddressGroup(characterFromID("Rocoso Balboa"), "none", "", "");

                        Locations[FindLocation("Santiago_Tavern")].vcskip = false;
                        Locations[FindLocation("Santiago_town_exit1")].vcskip = false;

			CloseQuestHeader("El Navegante");
		break;

//--------------------------- DEBRIEFING SANTIAGO

		case "Meet_after_Santiago":
			logit(TranslateString("","Let's get back to the ship!"));
			GiveItem2Character(PChar, "second_part_map");
			DeleteQuestHeader("El Navegante");

			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));	// If they're officers, they may not show up
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));

			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Santiago_port", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Santiago_port", "officers", "reload1_2");
			Pchar.quest.Santiago_Debriefing.win_condition.l1 = "locator";
			Pchar.quest.Santiago_Debriefing.win_condition.l1.location = "Santiago_port";
			Pchar.quest.Santiago_Debriefing.win_condition.l1.locator_group = "reload";
			Pchar.quest.Santiago_Debriefing.win_condition.l1.locator = "reload2_back";
			Pchar.quest.Santiago_Debriefing.win_condition = "Santiago_Debriefing";

			LAi_QuestDelay("Meet_after_Santiago2", 0.0);
		break;

		case "Meet_after_Santiago2":
			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
		break;

		case "Santiago_Debriefing":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			LAi_SetActorType(characterFromID("Blaze Devlin"));
			LAi_type_actor_Reset(CharacterFromID("Bonnie Devlin"));
			LAi_type_actor_Reset(CharacterFromID("Blaze Devlin"));
			ChangeCharacterAddressGroup(characterfromID("Blaze Devlin"),"Cabin2SJG", "rld", "aloc0");
			ChangeCharacterAddressGroup(characterfromID("Bonnie Devlin"),"Cabin2SJG", "rld", "aloc3");
			DoQuestReloadToLocation("Cabin2SJG", "rld", "aloc4", "Santiago_Debriefing2");
		break;

		case "Santiago_Debriefing2":
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Bonnie_Debriefing_Santiagofullmap";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

		case "celebrating_Blaze":
			LAi_SetActorType(characterFromID("Blaze Devlin"));
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "celebrating";
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 2.0, 0);
		break;

		case "glue_map":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "please_glue";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

		case "glue_map2":
			LAi_SetActorType(pchar);
			PlaySound("INTERFACE\paper.wav");
                        LAi_QuestDelay("glue_map3", 2.0);
		break;

		case "glue_map3":
                        TakeItemFromCharacter(PChar, "first_part_map");
                        TakeItemFromCharacter(PChar, "second_part_map");
			GiveItem2Character(PChar, "full_map");
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "map_now_glued";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

		case "To_first_X":
			LAi_SetOfficerType(characterFromID("Blaze Devlin"));
			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));

                        bQuestDisableSeaEnter = false;
			DisableFastTravel(false);
			Locations[FindLocation("Santiago_port")].reload.l2.disable = false;
			Locations[FindLocation("Santiago_port")].reload.l3.disable = false;

                        QuestToSeaLogin_PrepareLoc("Cuba", "Reload", "Reload_1", false);
                        QuestToSeaLogin_Launch();

			SetQuestHeader("The Road to El Dorado");
			AddQuestRecord("The Road to El Dorado", 1);
			DeleteQuestHeader("El Navegante");

			PChar.quest.restore_flag_detection.win_condition.l1 = "MapEnter";
			PChar.quest.restore_flag_detection.win_condition = "restore_flag_detection";

			Pchar.quest.Domingo_start.win_condition.l1 = "location";
			PChar.quest.Domingo_start.win_condition.l1.character = Pchar.id;
			Pchar.quest.Domingo_start.win_condition.l1.location = "Santo_Domingo_port";
			Pchar.quest.Domingo_start.win_condition = "Domingo_start";

			Pchar.quest.Domingo_start_town.win_condition.l1 = "location";
			PChar.quest.Domingo_start_town.win_condition.l1.character = Pchar.id;
			Pchar.quest.Domingo_start_town.win_condition.l1.location = "Santo_Domingo_town";
			Pchar.quest.Domingo_start_town.win_condition = "Domingo_start";
		break;

		case "restore_flag_detection":
			iForceDetectionFalseFlag = 0;
		break;

//=========================== SANTO DOMINGO ===========================================//


		case "Domingo_start":
			Pchar.quest.Domingo_start.over = "yes";
			Pchar.quest.Domingo_start_town.over = "yes";
			SetCurrentTime(08.00, 0);
			SetNextWeather("Blue Sky"); 

		        SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));	// Force Bonnie and Blaze back to being officers
		        SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));	// in case player hired new officers on the way here

			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Domingo_arrival";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

		case "to_Domingo_tavern":
			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			pchar.quest.OPERA = "ask_Ramos_for_Jauri";
		break;

		case "enter_the_kid":
			pchar.quest.OPERA = "asked_Ramos_for_Jauri";
			ChangeCharacterAddressGroup(characterFromID("Guille the Kid"), "Santo_Domingo_tavern", "reload", "reload1");
			LAi_SetActorType(characterFromID("Guille the Kid"));
			LAi_ActorDialog(characterFromID("Guille the Kid"), Pchar, "", 3.0, 0);
		break;

		case "Guille_leave_tavern":
			LAi_ActorRunToLocator(characterFromID("Guille the Kid"), "reload", "reload1", "byebye_Guille", 3.0);
		break;

		case "Byebye_Guille":
			ChangeCharacterAddress(characterfromID("Guille the Kid"),"none", "");
                        bQuestDisableSeaEnter = true
			DisableFastTravel(true);

			Pchar.quest.meet_kid_outside.win_condition.l1 = "location";
			PChar.quest.meet_kid_outside.win_condition.l1.character = Pchar.id;
			Pchar.quest.meet_kid_outside.win_condition.l1.location = "Santo_Domingo_town";
			Pchar.quest.meet_kid_outside.win_condition = "meet_kid_outside";
		break;

		case "meet_kid_outside":
			ChangeCharacterAddressGroup(characterFromID("Guille the Kid"), "Santo_Domingo_town", "quest", "quest1");
			ChangeCharacterAddressGroup(characterFromID("Buffoon1"), "Santo_Domingo_town", "quest", "quest2");
			ChangeCharacterAddressGroup(characterFromID("Buffoon2"), "Santo_Domingo_town", "quest", "quest3");
			LAi_SetActorType(characterFromID("Buffoon1"));
			LAi_SetActorType(characterFromID("Buffoon2"));

			Characters[GetCharacterIndex("Guille the Kid")].Dialog.CurrentNode = "Kid_out";
			LAi_ActorDialog(characterFromID("Guille the Kid"), Pchar, "", 1.0, 0);
		break;

		case "Kid_run_to_trap":
			LAi_ActorRunToLocator(characterFromID("Guille the Kid"), "quest", "quest4", "Kid_run_to_trap2", 30.0);
			LAi_ActorRunToLocator(characterFromID("Buffoon1"), "quest", "quest5", "Kid_run_to_trap2", 30.0);
			LAi_ActorRunToLocator(characterFromID("Buffoon2"), "quest", "quest6", "Kid_run_to_trap2", 30.0);
		break;

		case "Kid_run_to_trap2":
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(pchar, "quest", "quest7", "Kid_run_to_trap3", 4.0);
		break;

		case "Kid_run_to_trap3":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Guille the Kid")].Dialog.CurrentNode = "AdmiralAckbar";
			LAi_ActorDialog(characterFromID("Guille the Kid"), Pchar, "", 1.0, 0);
		break;

		case "Lorena_appear":
			LAi_SetActorType(pchar);
			ChangeCharacterAddressGroup(characterFromID("Lorena Lopez"), "Santo_Domingo_town", "quest", "quest8");
			LAi_SetActorType(characterFromID("Lorena Lopez"));
			LAi_ActorWaitDialog(pchar, characterFromID("Lorena Lopez"));
			Lai_ActorFollow(characterFromID("Lorena Lopez"), pchar, "Lorena_appear2", 6.0);
		break;

		case "Lorena_appear2":
			LAi_ActorDialog(characterFromID("Lorena Lopez"), Pchar, "", 6.0, 0);
		break;

		case "Lorena_Guille_1":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Guille the Kid")].Dialog.CurrentNode = "Hag";
			LAi_ActorDialog(characterFromID("Guille the Kid"), Pchar, "", 0.5, 0);
		break;

		case "Lorena_Guille_2":
			Characters[GetCharacterIndex("Lorena Lopez")].Dialog.CurrentNode = "Hagback";
			LAi_ActorDialog(characterFromID("Lorena Lopez"), Pchar, "", 0.5, 0);
		break;

		case "Lorena_Guille_3":
			Characters[GetCharacterIndex("Guille the Kid")].Dialog.CurrentNode = "Hagway";
			LAi_ActorDialog(characterFromID("Guille the Kid"), Pchar, "", 0.5, 0);
		break;

		case "Lorena_Guille_4":
			LAi_ActorRunToLocator(characterFromID("Guille the Kid"), "reload", "reload26", "ByeBye_Guillefriends", 20.0);
			LAi_ActorRunToLocator(characterFromID("Buffoon1"), "reload", "reload26", "ByeBye_Guillefriends", 20.0);
			LAi_ActorRunToLocator(characterFromID("Buffoon2"), "reload", "reload26", "ByeBye_Guillefriends", 20.0);

			Characters[GetCharacterIndex("Lorena Lopez")].Dialog.CurrentNode = "Welcome";
			LAi_ActorDialog(characterFromID("Lorena Lopez"), Pchar, "", 0.5, 0);
		break;

		case "ByeBye_Guillefriends":
			ChangeCharacterAddressGroup(characterFromID("Guille the Kid"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Buffoon1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Buffoon2"), "none", "", "");
		break;

		case "Lorena_home":
			LAi_ActorRunToLocator(characterFromID("Lorena Lopez"), "reload", "reload10", "Lorena_go_inside", 40.0);
		break;

		case "Lorena_go_inside":
			ChangeCharacterAddressGroup(characterFromID("Lorena Lopez"), "lorena_shop", "sit", "sit1");
			LAi_SetHuberType(characterFromID("Lorena Lopez"));
			Characters[GetCharacterIndex("Lorena Lopez")].Dialog.CurrentNode = "Store";
		break;

		case "to_puzzle_tavern":
			pchar.quest.LORENA = "between";
			AddQuestRecord("The Road to El Dorado", 5);

			Pchar.quest.PT_entrance.win_condition.l1 = "location";
			PChar.quest.PT_entrance.win_condition.l1.character = Pchar.id;
			Pchar.quest.PT_entrance.win_condition.l1.location = "Devlin_tavern_outside";
			Pchar.quest.PT_entrance.win_condition = "PT_entrance";
		break;

		case "PT_entrance":
			Pchar.quest.PT_entrance.over = "yes";
			Locations[FindLocation("Devlin_tavern_outside")].reload.l1.disable = true;
			Locations[FindLocation("Devlin_tavern_outside")].reload.l3.disable = true;

		        SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));	// Force Bonnie and Blaze back to being officers
		        SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));	// in case player hired new officers on the way here

			ChangeCharacterAddressGroup(characterFromID("Mystery Messenger"), "Devlin_tavern_outside", "goto", "locator4");
			Characters[GetCharacterIndex("Mystery Messenger")].dialog.currentnode = "Outside_puzzle";
			LAi_ActorDialog(characterFromID("Mystery Messenger"), Pchar, "", 4.0, 0);
		break;

		case "Outside_puzzle_Bonnie":
			LAi_ActorRunToLocator(characterFromID("Mystery Messenger"), "reload", "reload1", "Byebye_MM", 4.0);

			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Good_luck";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 1.0, 0);
		break;

		case "in_Puzzle_tavern":
			LAi_SetActorType(characterFromID("Blaze Devlin"));
			Locations[FindLocation("Devlin_tavern_outside")].reload.l2.disable = false;
			RemovePassenger(Pchar, characterFromID("Bonnie Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));
			RemovePassenger(Pchar, characterFromID("Blaze Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));

			Pchar.quest.Puzzle_start.win_condition.l1 = "location";
			PChar.quest.Puzzle_start.win_condition.l1.character = Pchar.id;
			Pchar.quest.Puzzle_start.win_condition.l1.location = "Puzzle_tavern";
			Pchar.quest.Puzzle_start.win_condition = "Puzzle_start";
		break;

//-------------------------------- TAVERN PUZZLE IN BOTH REACTIONS

		case "Jauris_map":
			ResumeAllSounds();
			PlaySound("INTERFACE\key_unlock.wav")
			Locations[FindLocation("Puzzle_tavern")].reload.l1.disable = false;
			GiveItem2Character(PChar, "jauri_map");
			AddQuestRecord("The Road to El Dorado", 3);

			CloseQuestHeader("My Life as a Waitress");
			DeleteQuestHeader("My Life as a Waitress");

			Pchar.quest.where_are_siblings.win_condition.l1 = "location";
			PChar.quest.where_are_siblings.win_condition.l1.character = Pchar.id;
			Pchar.quest.where_are_siblings.win_condition.l1.location = "Devlin_tavern_outside";
			Pchar.quest.where_are_siblings.win_condition = "where_are_siblings";
		break;

		case "where_are_siblings":
			Pchar.quest.where_are_siblings.over = "yes";
			SetCurrentTime(15.00, 0);
			Locations[FindLocation("Devlin_tavern_outside")].reload.l2.disable = true;
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Crewmember Devlin"), "Devlin_tavern_outside", "goto", "locator12");
			LAi_SetStayType(characterFromID("Crewmember Devlin"));
			Characters[GetCharacterIndex("Crewmember Devlin")].Dialog.CurrentNode = "Siblings_gone";
		break;

		case "Find_BB_in_SD":
			LAi_SetActorType(characterFromID("Crewmember Devlin"));
			LAi_ActorRunToLocator(characterFromID("Crewmember Devlin"), "reload", "reload1", "Byebye_CM", 9.0);

			Locations[FindLocation("Devlin_tavern_outside")].reload.l1.disable = false;
			Locations[FindLocation("Devlin_tavern_outside")].reload.l3.disable = false;
			AddQuestRecord("The Road to El Dorado", 4);
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Santo_Domingo_town", "goto", "goto6");
			LAi_SetStayType(characterFromID("Bonnie Devlin"));
			SetModelfromID(CharacterFromID("Bonnie Devlin"), "BeatriceB");
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "New_look";
		break;

		case "Blaze_gambling_again":
			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
                        Locations[FindLocation("Santo_Domingo_Tavern")].vcskip = true;
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "Gambling_SD";

			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Santo_Domingo_tavern", "sit", "sit5");
			LAi_SetSitType(characterFromID("Blaze Devlin"));
			ChangeCharacterAddressGroup(characterFromID("Compulsive Gambler"), "Santo_Domingo_tavern", "sit", "sit4");
			ChangeCharacterAddressGroup(characterFromID("Village Idiot"), "Santo_Domingo_tavern", "sit", "sit14");
			LAi_SetActorType(characterFromID("Compulsive Gambler"));
			LAi_SetActorType(characterFromID("Village Idiot"));
			LAi_ActorSetSitMode(characterFromID("Compulsive Gambler"));
			LAi_ActorSetSitMode(characterFromID("Village Idiot"));
		break;

		case "two_idiots":
			Characters[GetCharacterIndex("Compulsive Gambler")].Dialog.CurrentNode = "Compulsive Gambler";
			LAi_ActorDialog(characterFromID("Compulsive Gambler"), Pchar, "", 0.5, 0);
		break;

		case "two_idiots2":
			Characters[GetCharacterIndex("Village Idiot")].Dialog.CurrentNode = "Village Idiot";
			LAi_ActorDialog(characterFromID("Village Idiot"), Pchar, "", 0.5, 0);
		break;

		case "after_idiots":
			LAi_SetActorType(characterFromID("Blaze Devlin"));
			LAi_ActorSetSitMode(characterFromID("Blaze Devlin"));
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "afteridiots";
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 0.5, 0);
		break;

		case "Domingo_Debriefing":
			LAi_Fade("Domingo_Debriefing2", "Domingo_Debriefing3");
			ChangeCharacterAddressGroup(characterFromID("Compulsive Gambler"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Village Idiot"), "none", "", "");
		break;

		case "Domingo_Debriefing2":
			AddMoneyToCharacter(pchar, -3);
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Santo_Domingo_tavern", "sit", "sit5");
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Santo_Domingo_tavern", "sit", "sit4");
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Santo_Domingo_tavern", "sit", "sit14");
			LAi_SetSitType(characterFromID("Bonnie Devlin"));
                        LAi_SetSitType(characterFromID("Blaze Devlin"));
		break;

		case "Domingo_Debriefing3":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Bonnie_SD_Deb";
			LAi_ActorDialogNow(Pchar, characterFromID("Bonnie Devlin"), "", 1.0);
		break;

		case "Domingo_Debriefing4":
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "Blaze_SD_Deb";
			LAi_ActorDialogNow(Pchar, characterFromID("Blaze Devlin"), "", 0.5);
		break;

		case "Domingo_Debriefing5":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Bonnie_SD_Deb2";
			LAi_ActorDialogNow(Pchar, characterFromID("Bonnie Devlin"), "", 0.5);
		break;

		case "Domingo_Debriefingfin":
			AddQuestRecord("The Road to El Dorado", 6);
			SetCurrentTime(19.00, 0);
			ChangeCharacterAddressGroup(pchar, "Santo_Domingo_tavern", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Santo_Domingo_tavern", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Santo_Domingo_tavern", "goto", "goto2");

			pchar.quest.LORENA = "hirable";

			LAi_SetPlayerType(pchar);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			LAi_SetOfficerType(characterFromID("Blaze Devlin"));
                        Locations[FindLocation("Santo_Domingo_Tavern")].vcskip = false;
                        bQuestDisableSeaEnter = false
			DisableFastTravel(false);

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 3000);
				AddPartyExpChar(pchar, "Sneak", 2000);
				AddPartyExpChar(pchar, "Sailing", 7000);
			}
			else { AddPartyExp(pchar, 12000); }

			Pchar.quest.Cayman_map.win_condition.l1 = "item";
			PChar.quest.Cayman_map.win_condition.l1.character = Pchar.id;
			Pchar.quest.Cayman_map.win_condition.l1.item = "mapCayman";
			Pchar.quest.Cayman_map.win_condition = "Cayman_map";

			Pchar.quest.Cayman_start.win_condition.l1 = "location";
			PChar.quest.Cayman_start.win_condition.l1.character = Pchar.id;
			Pchar.quest.Cayman_start.win_condition.l1.location = "Cayman_Shore_01";
			Pchar.quest.Cayman_start.win_condition = "Cayman_start";
		break;

		case "Cayman_map":
			AddQuestRecord("The Road to El Dorado", 7);
			Pchar.quest.Cayman_map.over = "yes";
		break;


//=========================== CAYMAN / LAS TORTUGAS ===========================================//


		case "Cayman_start":
			Pchar.quest.Cayman_start.over = "yes";
			SetCurrentTime(07.30, 0);
		        SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));	// Force Bonnie and Blaze back to being officers
		        SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));	// in case player hired new officers on the way here

			ChangeCharacterAddressGroup(characterFromID("Mystery Messenger"), "Cayman_Shore_01", "goto", "locator11");
			Characters[GetCharacterIndex("Mystery Messenger")].dialog.currentnode = "Welcome_Cayman";
			LAi_ActorDialog(characterFromID("Mystery Messenger"), Pchar, "", 5.0, 0);
		break;

		case "Snakes_Questionmark":
			LAi_ActorRunToLocator(characterFromID("Mystery Messenger"), "reload", "reload1", "Byebye_MM", 4.0);

			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Snakes";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 0.5, 0);
		break;

		case "Blaze_matters_hands":
			LAi_SetActorType(characterFromID("Blaze Devlin"));
			Characters[GetCharacterIndex("Blaze Devlin")].Dialog.CurrentNode = "mensjob";
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 0.5, 0);
		break;

		case "Blaze_Cayman_start":
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "none", "", "");	//just to be sure
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "none", "", "");	//just to be sure
			RemovePassenger(Pchar, characterFromID("Bonnie Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));
			RemovePassenger(Pchar, characterFromID("Blaze Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));

			DoQuestReloadToLocation("Cayman_Shore_01", "officers", "reload1_2" ,"Blaze_Cayman_start2");
			
			SetQuestHeader("Hermit and the Frogs");
			AddQuestRecord("Hermit and the Frogs", 1);
                        bQuestDisableSeaEnter = true
			DisableFastTravel(true);
		break;

		case "Blaze_Cayman_start2":
			SetNextWeather("Blue Sky");

                        Locations[FindLocation("Devlin_Cayman_01")].vcskip = true;
                        Locations[FindLocation("Devlin_Cayman_02")].vcskip = true;
                        Locations[FindLocation("Devlin_Cayman_03")].vcskip = true;
                        Locations[FindLocation("Byrne_outside")].vcskip = true;
                        Locations[FindLocation("Byrne_inside")].vcskip = true;

			ChangeCharacterAddressGroup(characterFromID("Killian O'Byrne"), "Byrne_inside", "sit", "sit2");
			Characters[GetCharacterIndex("Annie O'Byrne")].Dialog.CurrentNode = "startolino";
                break;

		case "welcome_Annie":
			ChangeCharacterAddressGroup(characterFromID("Annie O'Byrne"), "Byrne_inside", "reload", "reload1");
                        PlaySound("PEOPLE\creak.wav");
                        LAi_QuestDelay("welcome_Annie2", 1.0);
		break;

		case "welcome_Annie2":
			LAi_SetActorType(characterFromID("Annie O'Byrne"));
			LAi_ActorDialog(characterFromID("Annie O'Byrne"), Pchar, "", 1.0, 0);
		break;

		case "Father_introduces_daughter":
			LAi_SetActorType(characterFromID("Killian O'Byrne"));
			LAi_ActorSetSitMode(characterFromID("Killian O'Byrne"));
			Characters[GetCharacterIndex("Killian O'Byrne")].Dialog.CurrentNode = "introduces_Annie";
			LAi_ActorDialog(characterFromID("Killian O'Byrne"), Pchar, "", 0.5, 0);
		break;

		case "Annie_freaking":
			Characters[GetCharacterIndex("Annie O'Byrne")].Dialog.CurrentNode = "Annie_freaking";
			LAi_ActorDialog(characterFromID("Annie O'Byrne"), Pchar, "", 0.5, 0);
		break;

		case "Talking_about_frogs":
			Characters[GetCharacterIndex("Killian O'Byrne")].Dialog.CurrentNode = "Talking_about_frogs";
			LAi_ActorDialog(characterFromID("Killian O'Byrne"), Pchar, "", 0.5, 0);
		break;

		case "Annie_patrols":
			Characters[GetCharacterIndex("Annie O'Byrne")].Dialog.CurrentNode = "Annie_patrols";
			LAi_ActorDialog(characterFromID("Annie O'Byrne"), Pchar, "", 0.5, 0);
		break;

		case "to_Cayman_for_governor":
			AddQuestRecord("Hermit and the Frogs", 2);
			ChangeCharacterAddressGroup(characterFromID("Annie O'Byrne"), "none", "", "");
			pchar.quest.KILLIAN = "governor";
			LAi_SetSitType(characterFromID("Killian O'Byrne"));
			Characters[GetCharacterIndex("Edmund Christobel Shaw")].dialog.Filename = "Fake Shaw_dialog.c"; // Separate dialog file for the governor
		break;

		case "Back_from_Cayman_City":
			AddQuestRecord("Hermit and the Frogs", 3);
			pchar.quest.GOVERNOR = "angry";
			Characters[GetCharacterIndex("Killian O'Byrne")].Dialog.CurrentNode = "Return_from_Shaw";
		break;

		case "Annie_tells_scouts":
			ChangeCharacterAddressGroup(characterFromID("Annie O'Byrne"), "Byrne_inside", "reload", "reload1");
                        PlaySound("PEOPLE\creak.wav");
                        LAi_QuestDelay("Annie_tells_scouts2", 1.0);
		break;

		case "Annie_tells_scouts2":
			Characters[GetCharacterIndex("Annie O'Byrne")].Dialog.CurrentNode = "Scouts_landed";
			LAi_ActorDialog(characterFromID("Annie O'Byrne"), Pchar, "", 1.0, 0);
		break;

		case "Land_ruse_begins": // Annie stays behind
			AddQuestRecord("Hermit and the Frogs", 4);
			pchar.quest.KILLIAN = "running";
			pchar.quest.ANNIE = "staysback";
			ChangeCharacterAddressGroup(characterfromID("Fake Bea"),"Cayman_Shore_01", "goto", "citizen05");
		break;

		case "Land_ruse_begins_Annie": // Annie joins you
			AddQuestRecord("Hermit and the Frogs", 4);
			pchar.quest.KILLIAN = "running";
			pchar.quest.ANNIE = "comeswith";
			ChangeCharacterAddressGroup(characterfromID("Fake Bea"),"Cayman_Shore_01", "goto", "citizen05");

			LAi_SetOfficerType(characterFromID("Annie O'Byrne"));
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Annie O'Byrne"))
			LAi_SetImmortal(characterFromID("Annie O'Byrne"), true);
		break;

		case "Fake_Bea_removes":
			AddQuestRecord("Hermit and the Frogs", 5);
			DoQuestReloadToLocation("Cayman_Shore_01", "goto", "citizen05" ,"Fake_Bea_removes2");

                        if (GetRMRelation(PChar, SPAIN) <= REL_WAR)
                        {
			SetCharacterShipLocation(Pchar, "none");
                        }
                        else
                        {
			SetCharacterShipLocation(Pchar, "Cayman_port");
                        }

			ChangeCharacterAddress(characterfromID("Fake Bea"),"none", "");
                        SetCharacterShipLocation(characterFromID("Godefroi Bonamy"), "Devlin_Cayman_beach");
		break;

		case "Fake_Bea_removes2":
			ChangeCharacterAddressGroup(characterfromID("Scout01"),"Devlin_Fort_Camp", "goto", "goto39");
			ChangeCharacterAddressGroup(characterfromID("Scout02"),"Devlin_Fort_Camp", "goto", "goto42");
			ChangeCharacterAddressGroup(characterfromID("Scout03"),"Devlin_Fort_Camp", "goto", "goto9");

                        Locations[FindLocation("Devlin_Fort_Camp")].locators_radius.quest.quest1 = 3.0;

                        pchar.quest.Scouts_defend.win_condition.l1 = "locator";
                        pchar.quest.Scouts_defend.win_condition.l1.location = "Devlin_Fort_Camp";
                        pchar.quest.Scouts_defend.win_condition.l1.locator_group = "quest";
                        pchar.quest.Scouts_defend.win_condition.l1.locator = "quest1";
                        pchar.quest.Scouts_defend.win_condition = "Scouts_defend";
		break;

		case "Scouts_defend":
			LAi_group_MoveCharacter(CharacterFromID("Scout01"), "Bad_scouts");
			LAi_group_MoveCharacter(CharacterFromID("Scout02"), "Bad_scouts");
			LAi_group_MoveCharacter(CharacterFromID("Scout03"), "Bad_scouts");

			LAi_group_FightGroups("Bad_scouts", LAI_GROUP_PLAYER, 1);

			LAi_group_SetCheck("Bad_scouts", "Killed_Scouts");
		break;

		case "Killed_Scouts":
                        if (CheckQuestAttribute("ANNIE", "staysback"))
                        {
			     LAi_SetFightMode(PChar, false);
			     LAi_SetActorType(pchar)
			     Pchar.dialog.CurrentNode = "Waiting_for_Kay";
			     LAi_ActorSelfDialog(PChar, "");
                        }

                        if (CheckQuestAttribute("ANNIE", "comeswith"))
                        {
			     LAi_SetFightMode(PChar, false);
			     LAi_SetFightMode(characterFromID("Annie O'Byrne"), false);
			     LAi_SetActorType(characterFromID("Annie O'Byrne"));
			     Characters[GetCharacterIndex("Annie O'Byrne")].Dialog.CurrentNode = "Scouts_ded_with_Annie";
			     LAi_ActorDialog(characterFromID("Annie O'Byrne"), Pchar, "", 1.0, 0);
                        }
		break;

		case "Kay_picks_up":
			LAi_SetPlayerType(PChar);
			LAi_Fade("Kay_picks_up2", "");

			RemoveOfficersIndex(pchar, GetCharacterIndex("Annie O'Byrne"));
                        RemovePassenger(pchar, characterFromID("Annie O'Byrne"));
			LAi_SetActorType(characterFromID("Annie O'Byrne"));
			ChangeCharacterAddressGroup(characterFromID("Annie O'Byrne"), "Byrne_inside", "goto", "goto2");
		break;

		case "Kay_picks_up2":
			ChangeCharacterAddress(pchar, "Devlin_Fort_Camp", "goto39");
                        WaitDate("", 0, 0, 0, 1, 0);

			ChangeCharacterAddressGroup(characterfromID("Mad Kay Hubecher"),"Devlin_Fort_Camp", "reload", "reload1");
			ChangeCharacterAddressGroup(characterfromID("Kay01"),"Devlin_Fort_Camp", "reload", "reload1");
			ChangeCharacterAddressGroup(characterfromID("Kay02"),"Devlin_Fort_Camp", "reload", "reload1");
			ChangeCharacterAddressGroup(characterfromID("Kay03"),"Devlin_Fort_Camp", "reload", "reload1");

			LAi_SetActorType(characterFromID("Mad Kay Hubecher"));
			LAi_SetActorType(characterFromID("Kay01"));
			LAi_SetActorType(characterFromID("Kay02"));
			LAi_SetActorType(characterFromID("Kay03"));

			Characters[GetCharacterIndex("Mad Kay Hubecher")].Dialog.CurrentNode = "Kays_first_phrase";

			LAi_ActorDialog(characterFromID("Mad Kay Hubecher"), Pchar, "", 10.0, 0);
                        Lai_ActorFollow(characterFromID("Kay01"), pchar, "", 10.0);
                        Lai_ActorFollow(characterFromID("Kay02"), pchar, "", 10.0);
                        Lai_ActorFollow(characterFromID("Kay03"), pchar, "", 10.0);
		break;

		case "Blaze_meets_Bonamy":
			DoQuestReloadToLocation("Cabin4", "rld", "loc6", "Blaze_meets_Bonamy2");
			ChangeCharacterAddressGroup(characterfromID("Godefroi Bonamy"),"Cabin4", "rld", "aloc2");
			ChangeCharacterAddressGroup(characterfromID("Rocoso Balboa"),"none", "", "");             // in case he's still there
			LAi_SetActorType(characterFromID("Godefroi Bonamy"));
			LAi_SetPlayerType(pchar);
		break;

		case "Blaze_meets_Bonamy2":
			     LAi_ActorDialog(characterFromID("Godefroi Bonamy"), Pchar, "", 2.0, 0);
		break;

		case "Unite_to_Beach":
			DoQuestReloadToLocation("Devlin_Cayman_beach", "reload", "reload1", "Unite_to_Beach2");
		break;

		case "Unite_to_Beach2":
			ChangeCharacterAddressGroup(characterfromID("Mad Kay Hubecher"),"Devlin_Fort_Camp", "goto", "goto39");
			ChangeCharacterAddressGroup(characterfromID("Kay01"),"Devlin_Fort_Camp", "goto", "goto42");
			ChangeCharacterAddressGroup(characterfromID("Kay02"),"Devlin_Fort_Camp", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Kay03"),"Devlin_Fort_Camp", "goto", "goto43");

			LAi_SetStayType(characterFromID("Mad Kay Hubecher"));
			LAi_SetStayType(characterFromID("Kay01"));
			LAi_SetStayType(characterFromID("Kay02"));
			LAi_SetStayType(characterFromID("Kay03"));

			Characters[GetCharacterIndex("Mad Kay Hubecher")].Dialog.CurrentNode = "Ambush";

			AddQuestRecord("Hermit and the Frogs", 6);
		break;

		case "MKH_ambush":
			AddQuestRecord("Hermit and the Frogs", 7);
			pchar.quest.MKH = "ambush";

                        Locations[FindLocation("Devlin_Cayman_beach")].locators_radius.reload.boat = 9.0;

                        pchar.quest.melde_Bonamy.win_condition.l1 = "locator";
                        pchar.quest.melde_Bonamy.win_condition.l1.location = "Devlin_Cayman_beach";
                        pchar.quest.melde_Bonamy.win_condition.l1.locator_group = "reload";
                        pchar.quest.melde_Bonamy.win_condition.l1.locator = "boat";
                        pchar.quest.melde_Bonamy.win_condition = "melde_Bonamy";
		break;

		case "melde_Bonamy":
			DoQuestReloadToLocation("Family_deck", "goto", "goto7", "melde_Bonamy2");
			Pchar.quest.melde_Bonamy.over = "yes";
			ChangeCharacterAddressGroup(characterfromID("Godefroi Bonamy"),"Family_deck", "goto", "goto16");
			LAi_SetActorType(characterFromID("Godefroi Bonamy"));
			Characters[GetCharacterIndex("Godefroi Bonamy")].dialog.currentnode = "Le_Blaze_is_back";
		break;

		case "melde_Bonamy2":
			LAi_ActorDialog(characterFromID("Godefroi Bonamy"), Pchar, "", 2.0, 0);
		break;

		case "To_le_Hold":
			DoQuestReloadToLocation("Devlin_Hold1", "reload", "reload1", "To_le_Hold2");
		break;

		case "To_le_Hold2":
			ChangeCharacterAddressGroup(characterfromID("Godefroi Bonamy"),"Devlin_Hold1", "rld", "loc1");
			ChangeCharacterAddressGroup(characterfromID("Bonamy01"),"Devlin_Hold1", "rld", "prison1");
			ChangeCharacterAddressGroup(characterfromID("Bonamy02"),"Devlin_Hold1", "rld", "prison7");

			LAi_SetOfficerType(characterFromID("Godefroi Bonamy"));
			LAi_SetOfficerType(characterFromID("Bonamy01"));
			LAi_SetOfficerType(characterFromID("Bonamy02"));

			SetOfficersIndex(Pchar, 1, getCharacterIndex("Godefroi Bonamy"))
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Bonamy01"))
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Bonamy02"))

                        SetCharacterRemovable(CharacterFromID("Godefroi Bonamy"), false);
                        SetCharacterRemovable(CharacterFromID("Bonamy01"), false);
                        SetCharacterRemovable(CharacterFromID("Bonamy02"), false);

			LAi_SetImmortal(characterFromID("Godefroi Bonamy"), true);

			ChangeCharacterAddressGroup(characterfromID("Crazy Luc Helveur"),"Devlin_Hold1", "rld", "prison2");
			ChangeCharacterAddressGroup(characterfromID("Luc01"),"Devlin_Hold1", "rld", "prison3");
			ChangeCharacterAddressGroup(characterfromID("Luc02"),"Devlin_Hold1", "rld", "prison4");
			ChangeCharacterAddressGroup(characterfromID("Luc03"),"Devlin_Hold1", "rld", "prison5");

                        LAi_QuestDelay("To_le_Hold3", 0.5);
		break;

		case "To_le_Hold3":
			LAi_SetActorType(characterFromID("Crazy Luc Helveur"));
			LAi_ActorWaitDialog(pchar, characterFromID("Crazy Luc Helveur"));
			Lai_ActorFollow(characterFromID("Crazy Luc Helveur"), pchar, "Bonamy_Luc", 0.0);
		break;

		case "Bonamy_Luc":
			LAi_ActorDialog(characterFromID("Crazy Luc Helveur"), Pchar, "", 1.5, 0);
		break;

		case "Bonamy_Luc2":
			LAi_SetActorType(characterFromID("Godefroi Bonamy"));
			Characters[GetCharacterIndex("Godefroi Bonamy")].Dialog.CurrentNode = "Confronting_Luc";
			LAi_ActorDialog(characterFromID("Godefroi Bonamy"), Pchar, "", 0.5, 0);
		break;

		case "Bonamy_Luc3":
			Characters[GetCharacterIndex("Crazy Luc Helveur")].Dialog.CurrentNode = "U_Joking";
			LAi_ActorDialog(characterFromID("Crazy Luc Helveur"), Pchar, "", 0.5, 0);
		break;

		case "Bonamy_Luc4":
			Characters[GetCharacterIndex("Godefroi Bonamy")].Dialog.CurrentNode = "Confronting_Luc2";
			LAi_ActorDialog(characterFromID("Godefroi Bonamy"), Pchar, "", 0.5, 0);
		break;

		case "Bonamy_Luc5":
			Characters[GetCharacterIndex("Crazy Luc Helveur")].Dialog.CurrentNode = "Self_Defence";
			LAi_ActorDialog(characterFromID("Crazy Luc Helveur"), Pchar, "", 0.5, 0);
		break;

		case "Bonamy_Luc6":
			Characters[GetCharacterIndex("Godefroi Bonamy")].Dialog.CurrentNode = "Confronting_Luc3";
			LAi_ActorDialog(characterFromID("Godefroi Bonamy"), Pchar, "", 0.5, 0);
		break;

		case "Bonamy_vs_Luc":
			LAi_SetOfficerType(characterFromID("Godefroi Bonamy"));
			LAi_SetStayType(characterFromID("Crazy Luc Helveur"));

			LAi_group_MoveCharacter(CharacterFromID("Crazy Luc Helveur"), "Bad_Luc");
			LAi_group_MoveCharacter(CharacterFromID("Luc01"), "Bad_Luc");
			LAi_group_MoveCharacter(CharacterFromID("Luc02"), "Bad_Luc");
			LAi_group_MoveCharacter(CharacterFromID("Luc03"), "Bad_Luc");

			LAi_group_FightGroups("Bad_Luc", LAI_GROUP_PLAYER, 1);
			LAi_group_SetCheck("Bad_Luc", "Killed_Luc");
		break;

		case "Killed_Luc":
			LAi_SetFightMode(PChar, false);
			LAi_SetActorType(characterFromID("Godefroi Bonamy"));
			Characters[GetCharacterIndex("Godefroi Bonamy")].Dialog.CurrentNode = "Triumph";
			LAi_ActorDialog(characterFromID("Godefroi Bonamy"), Pchar, "", 0.5, 0);
		break;

		case "Lead_Bonamy_ashore":
			LAi_SetOfficerType(characterFromID("Godefroi Bonamy"));
			DoQuestReloadToLocation("Devlin_Cayman_beach", "reload", "reload1", "Lead_Bonamy_ashore2");
		break;

		case "Lead_Bonamy_ashore2":
			AddQuestRecord("Hermit and the Frogs", 8);
			pchar.quest.BONAMY = "leadme";

			Locations[FindLocation("Devlin_Cayman_02")].reload.l1.disable = true;
			Locations[FindLocation("Devlin_Cayman_02")].reload.l2.disable = true;
			Locations[FindLocation("Devlin_Cayman_03")].reload.l6.disable = true;
			Locations[FindLocation("Devlin_Cayman_03")].reload.l7.disable = true;

                        pchar.quest.Stop_town.win_condition.l1 = "locator";
                        pchar.quest.Stop_town.win_condition.l1.location = "Devlin_Cayman_03";
                        pchar.quest.Stop_town.win_condition.l1.locator_group = "reload";
                        pchar.quest.Stop_town.win_condition.l1.locator = "reload3_back";
                        pchar.quest.Stop_town.win_condition = "Stop_town";

                        pchar.quest.Stop_house.win_condition.l1 = "locator";
                        pchar.quest.Stop_house.win_condition.l1.location = "Devlin_Cayman_02";
                        pchar.quest.Stop_house.win_condition.l1.locator_group = "reload";
                        pchar.quest.Stop_house.win_condition.l1.locator = "reload3_back";
                        pchar.quest.Stop_house.win_condition = "Stop_house";

                        pchar.quest.Fort_ambush.win_condition.l1 = "locator";
                        pchar.quest.Fort_ambush.win_condition.l1.location = "Devlin_Fort_Camp";
                        pchar.quest.Fort_ambush.win_condition.l1.locator_group = "quest";
                        pchar.quest.Fort_ambush.win_condition.l1.locator = "quest1";
                        pchar.quest.Fort_ambush.win_condition = "Fort_ambush";
		break;

// -------- Precautions
		case "Stop_town":
			LAi_SetActorType(characterFromID("Godefroi Bonamy"));
			Characters[GetCharacterIndex("Godefroi Bonamy")].Dialog.CurrentNode = "Stop_town";
			LAi_ActorDialog(characterFromID("Godefroi Bonamy"), Pchar, "", 0.5, 0);
		break;

		case "Stop_town2":
			LAi_SetOfficerType(characterFromID("Godefroi Bonamy"));
		break;

		case "Stop_house":
			LAi_SetActorType(pchar)
			Pchar.dialog.CurrentNode = "Stop_house";
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Stop_house2":
			LAi_SetPlayerType(pchar)
		break;

// -------- Precautions over

		case "Fort_ambush":
			LAi_group_MoveCharacter(CharacterFromID("Mad Kay Hubecher"), "Bad_Kay");
			LAi_group_MoveCharacter(CharacterFromID("Kay01"), "Bad_Kay");
			LAi_group_MoveCharacter(CharacterFromID("Kay02"), "Bad_Kay");
			LAi_group_MoveCharacter(CharacterFromID("Kay03"), "Bad_Kay");

			LAi_group_FightGroups("Bad_Kay", LAI_GROUP_PLAYER, 1);

			LAi_group_SetCheck("Bad_Kay", "Killed_Kay");
		break;

		case "Killed_Kay":
			LAi_SetFightMode(PChar, false);
			LAi_SetFightMode(characterFromID("Godefroi Bonamy"), false);
			LAi_SetActorType(characterFromID("Godefroi Bonamy"));
			Characters[GetCharacterIndex("Godefroi Bonamy")].Dialog.CurrentNode = "Y_he_attacked";
			LAi_ActorWaitDialog(pchar, characterFromID("Godefroi Bonamy"));
			Lai_ActorFollow(characterFromID("Godefroi Bonamy"), pchar, "Killed_Kay2", 0.0);
		break;

		case "Killed_Kay2":
			LAi_ActorDialog(characterFromID("Godefroi Bonamy"), Pchar, "", 1.0, 0);
		break;

		case "Bonamys_Last_Duel":
			LAi_SetStayType(characterFromID("Godefroi Bonamy"));
			LAi_SetStayType(characterFromID("Bonamy01"));
			LAi_SetStayType(characterFromID("Bonamy02"));

			RemoveOfficersIndex(pchar, GetCharacterIndex("Godefroi Bonamy"));
			RemovePassenger(Pchar, characterFromID("Godefroi Bonamy"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonamy01"));
			RemovePassenger(Pchar, characterFromID("Bonamy01"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonamy02"));
			RemovePassenger(Pchar, characterFromID("Bonamy02"));

			LAi_group_MoveCharacter(CharacterFromID("Godefroi Bonamy"), "Bad_Bonamy");
			LAi_group_MoveCharacter(CharacterFromID("Bonamy01"), "Bad_Bonamy");
			LAi_group_MoveCharacter(CharacterFromID("Bonamy02"), "Bad_Bonamy");

			LAi_SetImmortal(characterFromID("Godefroi Bonamy"), false);

			LAi_group_FightGroups("Bad_Bonamy", LAI_GROUP_PLAYER, 1);
			LAi_group_SetCheck("Bad_Bonamy", "Killed_Bonamy");
		break;

		case "Killed_Bonamy":
			LAi_SetFightMode(PChar, false);
			LAi_SetActorType(pchar)
			Pchar.dialog.CurrentNode = "Blaze_killed_Bonamy";
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Camp_to_Hermit":
			LAi_SetPlayerType(pchar)
			Locations[FindLocation("Devlin_Cayman_02")].reload.l1.disable = false;
			Locations[FindLocation("Devlin_Cayman_02")].reload.l2.disable = false;
			Locations[FindLocation("Devlin_Cayman_03")].reload.l6.disable = false;
			Locations[FindLocation("Devlin_Cayman_03")].reload.l7.disable = false;

			Pchar.quest.Stop_town.over = "yes";
			Pchar.quest.Stop_house.over = "yes";
			Pchar.quest.Fort_ambush.over = "yes";

			Characters[GetCharacterIndex("Killian O'Byrne")].Dialog.CurrentNode = "wrapup";
			AddQuestRecord("Hermit and the Frogs", 9);
                        SetCharacterShipLocation(characterFromID("Godefroi Bonamy"), "none");
		break;

		case "Wait_Annie_one_more":
			Characters[GetCharacterIndex("Annie O'Byrne")].Dialog.CurrentNode = "Wants_Officer";
			LAi_ActorDialog(characterFromID("Annie O'Byrne"), Pchar, "", 0.5, 0);
		break;

		case "KOB_confirms":
			LAi_SetActorType(characterFromID("Killian O'Byrne"));
			LAi_ActorSetSitMode(characterFromID("Killian O'Byrne"));
			Characters[GetCharacterIndex("Killian O'Byrne")].Dialog.CurrentNode = "encourages_Annie";
			LAi_ActorDialog(characterFromID("Killian O'Byrne"), Pchar, "", 0.5, 0);
		break;

		case "Annie_decision":
			Characters[GetCharacterIndex("Annie O'Byrne")].Dialog.CurrentNode = "Decision";
			LAi_ActorDialog(characterFromID("Annie O'Byrne"), Pchar, "", 0.5, 0);
		break;

		case "Goodbye_Byrnes":
			if (PChar.location.from_sea == "Cayman_port")
			{
			AddQuestRecord("Hermit and the Frogs", 10);
			ChangeCharacterAddressGroup(characterfromID("Fake Bea"),"Cayman_Port", "goto", "goto5");
			}
			else
			{	
                        AddQuestRecord("Hermit and the Frogs", 11);
			ChangeCharacterAddressGroup(characterfromID("Fake Bea"),"Cayman_Shore_01", "goto", "citizen05");
			SetCharacterShipLocation(Pchar, "Cayman_Shore_01");
			}

			LAi_SetSitType(characterFromID("Killian O'Byrne"));
			pchar.quest.KILLIAN = "over";
			Characters[GetCharacterIndex("Fake Bea")].Dialog.CurrentNode = "wrapitup";
		break;

		case "Annie_hired":
			pchar.quest.ANNIE = "hired";

			LAi_SetOfficerType(characterFromID("Annie O'Byrne"));
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Annie O'Byrne"))
			LAi_SetImmortal(characterFromID("Annie O'Byrne"), false);
		break;

		case "Annie_available":
			pchar.quest.ANNIE = "available";
			AddQuestRecord("The Road to El Dorado", 8);
		break;

                case "Cayman_finish":
			if (PChar.location.from_sea == "Cayman_port")
			{
				DoQuestReloadToLocation("Cayman_port", "reload", "Falaise_de_fleur_location_01_05" ,"_");
			}
                        else
			{
				DoQuestReloadToLocation("Cayman_Shore_01", "reload", "reload1" ,"_");
			}

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Fencing", 6000);
				AddPartyExpChar(pchar, "Defence", 4000);
			}
			else { AddPartyExp(pchar, 10000); }

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			LAi_SetOfficerType(characterFromID("Bonnie Devlin"));
			LAi_SetOfficerType(characterFromID("Blaze Devlin"));

			GiveItem2Character(characterFromID("Blaze Devlin"), "blade25");
			EquipCharacterByItem(characterFromID("Blaze Devlin"), "blade25");

                        bQuestDisableSeaEnter = false
			DisableFastTravel(false);
			Characters[GetCharacterIndex("Edmund Christobel Shaw")].dialog.Filename = "Edmund Christobel Shaw_dialog.c";
			ChangeCharacterAddress(characterfromID("Fake Bea"),"none", "");
		break;

//========================== CAYMAN SEA BATTLE (ROUTE 2)

		case "Cayman_sea_battle_setup":
                        AddQuestRecord("Hermit and the Frogs", 12);
			pchar.quest.KILLIAN = "running";
			ChangeCharacterAddressGroup(characterfromID("Fake Bea"),"Cayman_Shore_01", "goto", "citizen05");
			Characters[GetCharacterIndex("Fake Bea")].Dialog.CurrentNode = "borrowship";
		break;

		case "Cayman_sea_battle_begins":
			DoQuestReloadToLocation("Cayman_Shore_01", "goto", "citizen05" ,"Cayman_sea_battle_begins2");
                        bQuestDisableSeaEnter = false
			ChangeCharacterAddress(characterfromID("Fake Bea"),"none", "");
		break;

		case "Cayman_sea_battle_begins2":
			Pchar.quest.Cayman_sea_battle_begins3.win_condition.l1 = "location";
			Pchar.quest.Cayman_sea_battle_begins3.win_condition.l1.location = "Cayman";
			Pchar.quest.Cayman_sea_battle_begins3.win_condition = "Cayman_sea_battle_begins3";
		break;

		case "Cayman_sea_battle_begins3":
			Pchar.quest.Cayman_sea_battle_begins3.over = "yes";
			bQuestDisableMapEnter = true;

			Group_CreateGroup("Bonamy_ship");
			Group_AddCharacter("Bonamy_ship", "Godefroi Bonamy");
			Group_SetGroupCommander("Bonamy_ship", "Godefroi Bonamy");
                        characters[GetCharacterIndex("Godefroi Bonamy")].Ship.Stopped = true;
			Group_SetAddress("Bonamy_ship", "Cayman", "Quest_ships", "quest_ship_4");
                        Group_SetTaskNone("Bonamy_ship");
                        Group_LockTask("Bonamy_ship");
			Sea_LoginGroupNow("Bonamy_ship");
			characters[GetCharacterIndex("Godefroi Bonamy")].nosurrender = 1;
			SetCharacterRelationBoth(GetCharacterIndex("Godefroi Bonamy"),GetMainCharacterIndex(),RELATION_ENEMY);
                        characters[GetCharacterIndex("Godefroi Bonamy")].recognized = true;
			Character_SetAbordageEnable(characterFromID("Godefroi Bonamy"), true);

			pchar.quest.Cayman_sea_battle_won.win_condition.l1 = "NPC_Death";
			pchar.quest.Cayman_sea_battle_won.win_condition.l1.character = "Godefroi Bonamy";
			pchar.quest.Cayman_sea_battle_won.win_condition = "Cayman_sea_battle_won";

                        pchar.quest.Cayman_sea_battle_won.win_condition.l2 = "SeaEnter";
		break;

		case "Cayman_sea_battle_won":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Cayman", true);
                        AddQuestRecord("Hermit and the Frogs", 13);

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 4000);
				AddPartyExpChar(pchar, "Defence", 4000);
			}
			else { AddPartyExp(pchar, 8000); }

			Pchar.quest.Bea_congrats.win_condition.l1 = "location";
			PChar.quest.Bea_congrats.win_condition.l1.character = Pchar.id;
			Pchar.quest.Bea_congrats.win_condition.l1.location = "Cayman_Shore_01";
			Pchar.quest.Bea_congrats.win_condition = "Bea_congrats";
		break;

		case "Bea_congrats":
			ChangeCharacterAddressGroup(characterFromID("Fake Bea"), "Cayman_Shore_01", "goto", "locator11");
			LAi_SetActorType(characterFromID("Fake Bea"));
			Characters[GetCharacterIndex("Fake Bea")].dialog.currentnode = "congrats";
			LAi_ActorDialog(characterFromID("Fake Bea"), Pchar, "", 5.0, 0);
		break;

		case "Bea_congrats_over":
			ChangeCharacterAddressGroup(characterFromID("Fake Bea"), "none", "", "");	//just to be sure
			LAi_SetStayType(characterFromID("Fake Bea"));

			DoQuestReloadToLocation("Cayman_Shore_01", "officers", "reload1_2" ,"KOB_kidnapped");
			
			SetQuestHeader("Hermit and the Frogs");
			AddQuestRecord("Hermit and the Frogs", 14);
                        bQuestDisableSeaEnter = true
		break;

		case "KOB_kidnapped":
			Pchar.quest.KOB_kidnapped2.win_condition.l1 = "location";
			PChar.quest.KOB_kidnapped2.win_condition.l1.character = Pchar.id;
			Pchar.quest.KOB_kidnapped2.win_condition.l1.location = "Byrne_outside";
			Pchar.quest.KOB_kidnapped2.win_condition = "KOB_kidnapped2";
		break;

		case "KOB_kidnapped2":
			Locations[FindLocation("Byrne_outside")].reload.l1.disable = true;
			Locations[FindLocation("Byrne_outside")].reload.l3.disable = true;

			ChangeCharacterAddressGroup(characterfromID("Scout01"),"Byrne_outside", "goto", "character11");
			ChangeCharacterAddressGroup(characterfromID("Scout02"),"Byrne_outside", "goto", "goto12");
			ChangeCharacterAddressGroup(characterfromID("Scout03"),"Byrne_outside", "goto", "goto17");
			ChangeCharacterAddressGroup(characterfromID("Annie O'Byrne"),"none", "", "");
			ChangeCharacterAddressGroup(characterfromID("Killian O'Byrne"),"Byrne_outside", "goto", "character7");
			LAi_SetPoorType(characterFromID("Killian O'Byrne"));

			LAi_SetActorType(PChar);
			Pchar.dialog.CurrentNode = "KOB_in_trouble";
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "KOB_kidnapped3":
			LAi_SetActorType(characterFromID("Scout01"));
			LAi_ActorWaitDialog(CharacterFromID("Scout01"), Pchar); 
			LAi_SetActorType(PChar);	                       
			LAi_ActorDialog(pchar, characterFromID("Scout01"), "", 10.0, 1.0);
		break;

		case "KOB_kidnapped4":
			PauseAllSounds();
			PlaySound("OBJECTS\DUEL\pistol_musket2.wav");
			LAi_QuestDelay("KOB_kidnapped5", 1.0);
		break;

		case "KOB_kidnapped5":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_01.wav");
			LAi_KillCharacter(characterfromID("Scout01"));
			LAi_QuestDelay("KOB_kidnapped6", 2.0);
		break;

		case "KOB_kidnapped6":
			PlaySound("OBJECTS\VOICES\body_fallen2.wav");
			LAi_QuestDelay("KOB_kidnapped_fight", 1.0);
		break;

		case "KOB_kidnapped_fight":
			ResumeAllSounds();
			LAi_SetPlayerType(pchar)

			LAi_group_MoveCharacter(CharacterFromID("Scout02"), "Bad_scouts");
			LAi_group_MoveCharacter(CharacterFromID("Scout03"), "Bad_scouts");
			LAi_group_FightGroups("Bad_scouts", LAI_GROUP_PLAYER, 1);
			LAi_group_SetCheck("Bad_scouts", "KOB_kidnapped_fight2");
		break;

		case "KOB_kidnapped_fight2":
			LAi_SetActorType(pchar)
			LAi_SetActorType(characterFromID("Killian O'Byrne"));
			LAi_ActorAnimation(characterFromID("Killian O'Byrne"), "Ground_StandUp", "KOB_kidnapped_over", 2.0);

			Locations[FindLocation("Byrne_outside")].reload.l1.disable = false;
			Locations[FindLocation("Byrne_outside")].reload.l3.disable = false;

			ChangeCharacterAddressGroup(characterfromID("Annie O'Byrne"),"Byrne_outside", "reload", "reload1");
                        Lai_ActorFollow(characterFromID("Annie O'Byrne"), pchar, "", 10.0);
		break;

		case "KOB_kidnapped_over":
			LAi_SetPlayerType(pchar)
			Characters[GetCharacterIndex("Killian O'Byrne")].Dialog.CurrentNode = "Saved_me";
			LAi_ActorDialog(characterFromID("Killian O'Byrne"), Pchar, "", 1.0, 0);
		break;

		case "Hermit_inside":
			DoQuestReloadToLocation("Byrne_inside", "goto", "goto3" ,"Hermit_inside2");
		break;

		case "Hermit_inside2":
			ChangeCharacterAddressGroup(characterFromID("Annie O'Byrne"), "Byrne_inside", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Killian O'Byrne"), "Byrne_inside", "sit", "sit2");
			LAi_ActorSetSitMode(characterFromID("Killian O'Byrne"));
			Characters[GetCharacterIndex("Killian O'Byrne")].Dialog.CurrentNode = "wrapup_inside";
			LAi_ActorDialog(characterFromID("Killian O'Byrne"), Pchar, "", 0.5, 0);
		break;



//=========================== CHARACTER SWITCHES ===========================================//

		case "Switch_to_Bonnie":
			SetModel(PChar, "BeatriceA", "woman_sit", PChar.sex, stf(PChar.model.height), true);
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "none", "", "");	//just to be sure
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "none", "", "");	//just to be sure
			RemovePassenger(Pchar, characterFromID("Bonnie Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));
			RemovePassenger(Pchar, characterFromID("Blaze Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));
			Pchar.name = TranslateString("", "Bonnie");
			Pchar.lastname = TranslateString("", "Devlin");
//			TakeItemFromCharacter(Pchar, "blade13+1")
//			TakeItemFromCharacter(Pchar, "pistol5+2")
			PChar.quest.old_blade = GetCharacterEquipByGroup(PChar, BLADE_ITEM_TYPE);	// Remember what you were carrying
			PChar.quest.old_gun = GetCharacterEquipByGroup(PChar, GUN_ITEM_TYPE);		// Presence of these attributes means items need to be restored
			TempRemoveItems(Pchar);
			NPChar = characterFromID("Bonnie Devlin");
			GiveItem2Character(Pchar, "bladeX4");
			if(GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE) != "")
			{
				GiveItem2Character(Pchar, GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE));
				EquipCharacterByItem(Pchar, GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE));
			}
			else
			{
				GiveItem2Character(Pchar, "blade4");
				EquipCharacterByItem(Pchar, "blade4");
			}
			if(GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE) != "")
			{
				GiveItem2Character(Pchar, GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE));
				EquipCharacterByItem(Pchar, GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE));
	                	if (ENABLE_AMMOMOD)
	                	{
		             		TakeNItems(Pchar, "gunpowder", 6);
		             		TakeNItems(Pchar, "pistolbullets", 6);
	                	}
			}
			Pchar.quest.orig_MaxHP = LAi_GetCharacterMaxHP(Pchar);
			Pchar.quest.orig_HP = LAi_GetCharacterHP(Pchar);
			Pchar.quest.orig_money = Pchar.money;
			Pchar.money = 0;								// So you can't buy equipment while you're Bonnie
			LAi_SetHP(Pchar, LAi_GetCharacterHP(NPChar), LAi_GetCharacterMaxHP(NPChar));
		break;

		case "Switch_to_Blaze":
			SetModel(PChar, "Devlin", "blaze", PChar.sex, stf(PChar.model.height), true);
			PChar.sex = "man";
                        PChar.model.animation = "blaze";
			ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "none", "", "");	//just to be sure
			ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "none", "", "");	//just to be sure
			RemovePassenger(Pchar, characterFromID("Bonnie Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bonnie Devlin"));
			RemovePassenger(Pchar, characterFromID("Blaze Devlin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Blaze Devlin"));
			Pchar.name = TranslateString("", "Blaze");
			Pchar.lastname = TranslateString("", "Devlin");
//			TakeItemFromCharacter(Pchar, "blade13+1")					// Player might not have these
//			TakeItemFromCharacter(Pchar, "pistol5+2")
			PChar.quest.old_blade = GetCharacterEquipByGroup(PChar, BLADE_ITEM_TYPE);	// Remember what you were carrying
			PChar.quest.old_gun = GetCharacterEquipByGroup(PChar, GUN_ITEM_TYPE);		// Presence of these attributes means items need to be restored
			TempRemoveItems(Pchar);
			GiveItem2Character(Pchar, "bladeX4");
			NPChar = characterFromID("Blaze Devlin");
			if(GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE) != "")
			{
				GiveItem2Character(Pchar, GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE));
				EquipCharacterByItem(Pchar, GetCharacterEquipByGroup(NPChar, BLADE_ITEM_TYPE));
			}
			else
			{
				GiveItem2Character(Pchar, "blade21");
				EquipCharacterByItem(Pchar, "blade21");
			}
			if(GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE) != "")
			{
				GiveItem2Character(Pchar, GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE));
				EquipCharacterByItem(Pchar, GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE));
			}
			else
			{
				GiveItem2Character(Pchar, "pistol27");
				EquipCharacterByItem(Pchar, "pistol27");
			}
	                if (ENABLE_AMMOMOD)
	                {
		             TakeNItems(Pchar, "gunpowder", 6);
		             TakeNItems(Pchar, "pistolbullets", 6);
	                }
			Pchar.quest.orig_MaxHP = LAi_GetCharacterMaxHP(Pchar);
			Pchar.quest.orig_HP = LAi_GetCharacterHP(Pchar);
			Pchar.quest.orig_money = Pchar.money;
			Pchar.money = 0;								// So you can't buy equipment while you're Blaze
			LAi_SetHP(Pchar, LAi_GetCharacterHP(NPChar), LAi_GetCharacterMaxHP(NPChar));
		break;

		case "Switch_to_Beatrice":
			SetModel(PChar, "Beatrice", "woman_sit", PChar.sex, stf(PChar.model.height), true);
			PChar.sex = "woman";
                        PChar.model.animation = "woman_sit";
			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);
			Pchar.name = "Beatrice";
			Pchar.lastname = "Devlin";
/*
			TakeItemFromCharacter(Pchar, "blade21")
			TakeItemFromCharacter(Pchar, "pistol27")
			TakeItemFromCharacter(Pchar, "blade4")
			GiveItem2Character(pchar, "blade13+1");
			EquipCharacterByItem(pchar, "blade13+1");
			GiveItem2Character(Pchar, "pistol5+2");
			EquipCharacterByItem(pchar, "pistol5+2");
*/
			if (CheckAttribute(Pchar, "quest.orig_money"))
			{
				Pchar.money = sti(Pchar.money) + sti(Pchar.quest.orig_money);				// Restore original money plus any you picked up as alternate character
				DeleteQuestAttribute("orig_money");
			}
			if (CheckAttribute(PChar, "quest.orig_HP"))
			{
				LAi_SetHP(Pchar, stf(Pchar.quest.orig_HP), stf(Pchar.quest.orig_MaxHP));
				DeleteQuestAttribute("orig_MaxHP");
				DeleteQuestAttribute("orig_HP");
			}
			if (CheckAttribute(Pchar, "quest.old_blade") || CheckAttribute(Pchar, "quest.old_gun"))		// Attribute set by case "Switch_to_Blaze" when your items were removed
			{
				RestoreTempRemovedItems(Pchar);
				if (PChar.quest.old_blade != "") EquipCharacterByItem(PChar, PChar.quest.old_blade);
				if (PChar.quest.old_gun != "") EquipCharacterByItem(PChar, PChar.quest.old_gun);
				DeleteQuestAttribute("old_blade");
				DeleteQuestAttribute("old_gun");
			}
		break;

//=========================== JUMPSTARTS ===================================================//

		case "Jump_Rum":
			SetQuestHeader("Yo Ho Ho and a shipment of rum");
			AddQuestRecord("Yo Ho Ho and a shipment of rum", 1);

			GiveItem2Character(PChar, "compass3");
			EquipCharacterByItem(pchar, "compass3");
			GiveItem2Character(pchar, "spyglass3");
			EquipCharacterByItem(pchar, "spyglass3");
                        if(ENABLE_WEAPONSMOD)
                        {
                        GiveItem2Character(pchar, "blade47+1");
                        EquipCharacterByItem(pchar, "blade47+1");
                        }
                        else
                        {
                        GiveItem2Character(pchar, "blade47");
                        EquipCharacterByItem(pchar, "blade47");
                        }

                        if(ENABLE_WEAPONSMOD)
                        {
                        GiveItem2Character(pchar, "pistol27+2");
                        EquipCharacterByItem(pchar, "pistol27+2");
                        }
                        else
                        {
                        GiveItem2Character(pchar, "pistol27");
                        EquipCharacterByItem(pchar, "pistol27");
                        }
			GiveItem2Character(PChar, "first_part_map");

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			SetCharacterShipLocation(Pchar, "Falaise_de_fleur_port_01");

			DoQuestReloadToLocation("Falaise_de_fleur_port_01", "reload", "sea" ,"Martinica_start");

			AddMoneyToCharacter(pchar, 10000);

		break;

		case "Jump_Santiago":
			SetQuestHeader("El Navegante");
			AddQuestRecord("El Navegante", 1);
			AddQuestRecord("El Navegante", 2);
			AddQuestRecord("El Navegante", 3);
			AddQuestRecord("El Navegante", 4);

			DeleteQuestHeader("Mystery Messenger and a letter");

			GiveItem2Character(PChar, "compass3");
			EquipCharacterByItem(pchar, "compass3");
			GiveItem2Character(pchar, "spyglass3");
			EquipCharacterByItem(pchar, "spyglass3");
                        if(ENABLE_WEAPONSMOD)
                        {
                        GiveItem2Character(pchar, "blade47+1");
                        EquipCharacterByItem(pchar, "blade47+1");
                        }
                        else
                        {
                        GiveItem2Character(pchar, "blade47");
                        EquipCharacterByItem(pchar, "blade47");
                        }

                        if(ENABLE_WEAPONSMOD)
                        {
                        GiveItem2Character(pchar, "pistol27+2");
                        EquipCharacterByItem(pchar, "pistol27+2");
                        }
                        else
                        {
                        GiveItem2Character(pchar, "pistol27");
                        EquipCharacterByItem(pchar, "pistol27");
                        }
			GiveItem2Character(PChar, "first_part_map");

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			SetCharacterShipLocation(Pchar, "Santiago_port");

			DoQuestReloadToLocation("Santiago_port", "reload", "reload2_back" ,"Santiago_start");

			AddMoneyToCharacter(pchar, 30000);

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 2000);
				AddPartyExpChar(pchar, "Fencing", 2000);
				AddPartyExpChar(pchar, "Defence", 2000);
				AddPartyExpChar(pchar, "Sailing", 2000);
			}
			else { AddPartyExp(pchar, 10000); }
		break;

		case "Jump_Domingo":
			SetQuestHeader("The Road to El Dorado");
			AddQuestRecord("The Road to El Dorado", 1);

			DeleteQuestHeader("Mystery Messenger and a letter");

			GiveItem2Character(PChar, "compass3");
			EquipCharacterByItem(pchar, "compass3");
			GiveItem2Character(pchar, "spyglass3");
			EquipCharacterByItem(pchar, "spyglass3");
                        if(ENABLE_WEAPONSMOD)
                        {
                        GiveItem2Character(pchar, "blade47+1");
                        EquipCharacterByItem(pchar, "blade47+1");
                        }
                        else
                        {
                        GiveItem2Character(pchar, "blade47");
                        EquipCharacterByItem(pchar, "blade47");
                        }

                        if(ENABLE_WEAPONSMOD)
                        {
                        GiveItem2Character(pchar, "pistol27+2");
                        EquipCharacterByItem(pchar, "pistol27+2");
                        }
                        else
                        {
                        GiveItem2Character(pchar, "pistol27");
                        EquipCharacterByItem(pchar, "pistol27");
                        }
			GiveItem2Character(PChar, "full_map");

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			SetCharacterShipLocation(Pchar, "Santo_Domingo_port");

			DoQuestReloadToLocation("Santo_Domingo_port", "reload", "reload1_back" ,"Domingo_start");

			AddMoneyToCharacter(pchar, 30000);

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 3000);
				AddPartyExpChar(pchar, "Sneak", 3000);
				AddPartyExpChar(pchar, "Fencing", 3000);
				AddPartyExpChar(pchar, "Defence", 3000);
				AddPartyExpChar(pchar, "Sailing", 3000);
			}
			else { AddPartyExp(pchar, 15000); }
		break;

		case "Jump_Cayman":
			SetQuestHeader("The Road to El Dorado");
			AddQuestRecord("The Road to El Dorado", 1);
			AddQuestRecord("The Road to El Dorado", 2);
			AddQuestRecord("The Road to El Dorado", 3);
			AddQuestRecord("The Road to El Dorado", 4);
			AddQuestRecord("The Road to El Dorado", 5);
			AddQuestRecord("The Road to El Dorado", 6);
			AddQuestRecord("The Road to El Dorado", 7);

			DeleteQuestHeader("Mystery Messenger and a letter");

			GiveItem2Character(PChar, "compass3");
			EquipCharacterByItem(pchar, "compass3");
			GiveItem2Character(pchar, "spyglass3");
			EquipCharacterByItem(pchar, "spyglass3");
                        if(ENABLE_WEAPONSMOD)
                        {
                        GiveItem2Character(pchar, "blade47+1");
                        EquipCharacterByItem(pchar, "blade47+1");
                        }
                        else
                        {
                        GiveItem2Character(pchar, "blade47");
                        EquipCharacterByItem(pchar, "blade47");
                        }

                        if(ENABLE_WEAPONSMOD)
                        {
                        GiveItem2Character(pchar, "pistol27+2");
                        EquipCharacterByItem(pchar, "pistol27+2");
                        }
                        else
                        {
                        GiveItem2Character(pchar, "pistol27");
                        EquipCharacterByItem(pchar, "pistol27");
                        }
			GiveItem2Character(PChar, "full_map");
			GiveItem2Character(PChar, "jauri_map");

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			SetModelfromID(CharacterFromID("Bonnie Devlin"), "BeatriceB");

			SetCharacterShipLocation(Pchar, "Cayman_Shore_01");

			DoQuestReloadToLocation("Cayman_Shore_01", "reload", "reload1" ,"Cayman_start");

			AddMoneyToCharacter(pchar, 50000);

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 4000);
				AddPartyExpChar(pchar, "Sneak", 4000);
				AddPartyExpChar(pchar, "Fencing", 4000);
				AddPartyExpChar(pchar, "Defence", 4000);
				AddPartyExpChar(pchar, "Sailing", 4000);
			}
			else { AddPartyExp(pchar, 20000); }
		break;

//=========================== OLD QUEST STUFF ==============================================//
		case "And_on_to_Nevis2":
			pchar.quest.Bonnie_talk = "Hunting_for_Blaze";
			if (checkquestattribute("Chosen_Quest", "Mings"))
			{
				setCharacterShipLocation(characterFromID("Sir Christopher Mings"), "Turks_port");
				Pchar.quest.And_on_to_Nevis3.win_condition.l1 = "location";
				PChar.quest.And_on_to_Nevis3.win_condition.l1.character = Pchar.id;
				Pchar.quest.And_on_to_Nevis3.win_condition.l1.location = "Turks_port";
				Pchar.quest.And_on_to_Nevis3.win_condition = "And_on_to_Nevis3";
			}
			if (checkquestattribute("Chosen_Quest", "CCC"))
			{
				LAi_type_actor_Reset(characterFromID("Couch Captain Charles"));

				setCharacterShipLocation(characterFromID("Couch Captain Charles"), "Turks_port");
				setCharacterShipLocation(characterFromID("Merciless Mark"), "Turks_port");
				setCharacterShipLocation(characterFromID("Thomas the Terror"), "Turks_port");

				Pchar.quest.And_off_to_Jamaica.win_condition.l1 = "location";
				PChar.quest.And_off_to_Jamaica.win_condition.l1.character = Pchar.id;
				Pchar.quest.And_off_to_Jamaica.win_condition.l1.location = "Turks_port";
				Pchar.quest.And_off_to_Jamaica.win_condition = "And_off_to_Jamaica";
			}
			if (checkquestattribute("Chosen_Quest", "Armada"))
			{
				Pchar.quest.Alone_to_Jamaica.win_condition.l1 = "location";
				PChar.quest.Alone_to_Jamaica.win_condition.l1.character = Pchar.id;
				Pchar.quest.Alone_to_Jamaica.win_condition.l1.location = "Redmond_port";
				Pchar.quest.Alone_to_Jamaica.win_condition = "Alone_to_Jamaica";
			}
			if (checkquestattribute("Chosen_Quest", "Catalina"))
			{
				AddPassenger(Pchar, characterFromID("Catalina the Pirate"), 0);
				SetOfficersIndex(Pchar, 3, getCharacterIndex("Catalina the Pirate"));

				Pchar.quest.With_Cat_to_Jamaica.win_condition.l1 = "location";
				PChar.quest.With_Cat_to_Jamaica.win_condition.l1.character = Pchar.id;
				Pchar.quest.With_Cat_to_Jamaica.win_condition.l1.location = "Redmond_port";
				Pchar.quest.With_Cat_to_Jamaica.win_condition = "With_Cat_to_Jamaica";
			}
			if (checkquestattribute("Chosen_Quest", "ThomasT"))
			{
				setCharacterShipLocation(characterFromID("Thomas the Terror"), "Turks_port");

				Pchar.quest.With_Thomas_to_Barbados.win_condition.l1 = "location";
				PChar.quest.With_Thomas_to_Barbados.win_condition.l1.character = Pchar.id;
				Pchar.quest.With_Thomas_to_Barbados.win_condition.l1.location = "Turks_port";
				Pchar.quest.With_Thomas_to_Barbados.win_condition = "With_Thomas_to_Barbados";
			}
			if (checkquestattribute("Chosen_Quest", "Merciless"))
			{
				LAi_type_actor_Reset(characterFromID("Merciless Mark"));
				LAi_type_actor_Reset(characterFromID("Maximus"));
				setCharacterShipLocation(characterFromID("Merciless Mark"), "Turks_port");
				setCharacterShipLocation(characterFromID("Petros"), "Turks_port");
				setCharacterShipLocation(characterFromID("Maximus"), "Turks_port");

				Pchar.quest.Merciless_and_Spain.win_condition.l1 = "location";
				PChar.quest.Merciless_and_Spain.win_condition.l1.character = Pchar.id;
				Pchar.quest.Merciless_and_Spain.win_condition.l1.location = "Turks_port";
				Pchar.quest.Merciless_and_Spain.win_condition = "Merciless_and_Spain";
			}
			if (checkquestattribute("Chosen_Quest", "Maximus"))
			{
				LAi_type_actor_Reset(characterFromID("Maximus"));
				setCharacterShipLocation(characterFromID("Maximus"), "Turks_port");

				Pchar.quest.Merciless_and_Spain.win_condition.l1 = "location";
				PChar.quest.Merciless_and_Spain.win_condition.l1.character = Pchar.id;
				Pchar.quest.Merciless_and_Spain.win_condition.l1.location = "Turks_port";
				Pchar.quest.Merciless_and_Spain.win_condition = "Maximus_to_Conceicao";
			}
// ADD OTHER MODDERS QUEST CONDITIONS HERE
		break;

		case "And_on_to_Nevis3":
			LAi_type_actor_Reset(characterFromID("Sir Christopher Mings"));
			ChangeCharacterAddressGroup(characterfromID("Sir Christopher Mings"),"Turks_port", "goto", "P_goto4");	//JRH: new Turks, was goto4
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Sir Christopher Mings"));
			SetCharacterRemovable(characterFromID("Sir Christopher Mings"), false);
			ChangeCharacterAddressGroup(characterfromID("Short Jack Gold"),"Turks_port", "goto", "P_goto6");	//JRH: new Turks, was goto6
			LAi_SetCivilianGuardianType(characterFromID("Short Jack Gold"));
			ChangeCharacterAddressGroup(characterfromID("Catalina the Pirate"),"Turks_port", "goto", "P_goto1");	//JRH: new Turks, was goto1
			pchar.quest.Morgan_talk = "First_for_Nevis";

			pchar.quest.Time_for_a_swim.win_condition.l1 = "locator";
			PChar.quest.Time_for_a_swim.win_condition.l1.character = Pchar.id;
			pchar.quest.Time_for_a_swim.win_condition.l1.location = "Turks_port";
			pchar.quest.Time_for_a_swim.win_condition.l1.locator_group = "goto";
			pchar.quest.Time_for_a_swim.win_condition.l1.locator = "P_goto11";					//JRH: new Turks, was goto11
			pchar.quest.Time_for_a_swim.win_condition = "Time_for_a_swim";
		break;

		case "Time_for_a_swim":
			LAi_SetActorType(characterFromID("Short Jack Gold"));
			LAi_SetActorType(characterFromID("Catalina the Pirate"));
			LAi_ActorGoToLocator(characterfromID("Catalina the Pirate"), "goto", "P_goto20", "", 0.0);		//JRH: new Turks, was goto20
			LAi_ActorGoToLocator(characterfromID("Short Jack Gold"), "goto", "P_goto20", "", 0.0);			//JRH: new Turks, was goto20

			Pchar.quest.Sir_Christopher_Quest.win_condition.l1 = "location";
			PChar.quest.Sir_Christopher_Quest.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sir_Christopher_Quest.win_condition.l1.location = "QC_port";
			Pchar.quest.Sir_Christopher_Quest.win_condition = "Sir_Christopher_Quest";
		break;

		case "Sir_Christopher_Quest":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			pchar.quest.Bonnie_talk = "Is_Blaze_in_QC";
			LAi_SetOfficerType(CharacterFromID("Sir Christopher Mings"));
			LAi_QuestDelay("Sir_Christopher_Quest2", 0.0);
		break;

		case "Sir_Christopher_Quest2":
			ChangeCharacterAddressGroup(characterfromID("Sir Christopher Mings"),"QC_port", "goto", "goto4");
			LAi_ActorWaitDialog(pchar, characterFromID("Sir Christopher Mings"));
			characters[GetCharacterIndex("Sir Christopher Mings")].Dialog.Filename = "Sir Christopher Mings_dialog.c";
			LAi_SetActorType(characterFromID("Sir Christopher Mings"));
			LAi_ActorDialog(characterFromID("Sir Christopher Mings"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Sir Christopher Mings")].dialog.currentnode = "Arrival_at_QC";
		break;

		case "Sir_Christopher_Quest3":
			Pchar.quest.Sir_Christopher_Quest4.win_condition.l1 = "location";
			PChar.quest.Sir_Christopher_Quest4.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sir_Christopher_Quest4.win_condition.l1.location = "QC_residence";
			Pchar.quest.Sir_Christopher_Quest4.win_condition = "Sir_Christopher_Quest4";
		break;

		case "Sir_Christopher_Quest4":
			ChangeCharacterAddressGroup(characterfromID("John Paul Jones"),"QC_residence", "sit", "sit1");
            LAi_SetSitType(characterfromID("John Paul Jones"));
			ChangeCharacterAddressGroup(characterfromID("Bonnie Devlin"),"QC_residence", "goto", "goto2");
			ChangeCharacterAddressGroup(characterfromID("Sir Christopher Mings"),"QC_residence", "goto", "goto5");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
		break;

		case "Mings_buts_in":
			pchar.quest.Bonnie_talk = "QC_discussion_with_JPJ";
			characters[GetCharacterIndex("Sir Christopher Mings")].Dialog.Filename = "Sir Christopher Mings_dialog.c";
			LAi_SetActorType(characterFromID("Sir Christopher Mings"));
			LAi_ActorDialog(characterFromID("Sir Christopher Mings"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Sir Christopher Mings")].dialog.currentnode = "Mings_buts_in_at_QC";
		break;

		case "Skull_speaks_up":
			LAi_SetActorType(characterFromID("Isenbrandt Jurcksen"));
			LAi_ActorDialog(characterFromID("Isenbrandt Jurcksen"),PChar,"",10.0,1.0);
		break;

		case "Round_the_Room":
			characters[GetCharacterIndex("Sir Christopher Mings")].Dialog.Filename = "Sir Christopher Mings_dialog.c";
			LAi_SetActorType(characterFromID("Sir Christopher Mings"));
			LAi_ActorDialog(characterFromID("Sir Christopher Mings"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Sir Christopher Mings")].dialog.currentnode = "around_the_room";
		break;

		case "Others_speak_up":
			characters[GetCharacterIndex("High Sea Lass")].Dialog.Filename = "High Sea Lass_dialog.c";
			LAi_SetActorType(characterFromID("High Sea Lass"));
			LAi_ActorDialog(characterFromID("High Sea Lass"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("High Sea Lass")].dialog.currentnode = "more_round_the_room";
		break;

		case "one_more_joins_the_fleet":
			characters[GetCharacterIndex("Bartholomew Roberts")].Dialog.Filename = "Bartholomew Roberts_dialog.c";
			LAi_SetActorType(characterFromID("Bartholomew Roberts"));
			LAi_ActorDialog(characterFromID("Bartholomew Roberts"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Bartholomew Roberts")].dialog.currentnode = "more_round_the_room";
		break;

		case "The_fleets_complete":
			characters[GetCharacterIndex("Sir Christopher Mings")].Dialog.Filename = "Sir Christopher Mings_dialog.c";
			LAi_SetActorType(characterFromID("Sir Christopher Mings"));
			LAi_ActorDialog(characterFromID("Sir Christopher Mings"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Sir Christopher Mings")].dialog.currentnode = "Jamaica_here_we_come";
		break;

		case "Off_with_Mings_to_Jamaica":
			LAi_SetStayType(characterFromID("Sir Christopher Mings"));
			Characters[GetCharacterIndex("Sir Christopher Mings")].dialog.currentnode = "First time";
			LAi_SetStayType(characterFromID("Isenbrandt Jurcksen"));
			Characters[GetCharacterIndex("Isenbrandt Jurcksen")].dialog.currentnode = "First time";
			LAi_SetStayType(characterFromID("High Sea Lass"));
			Characters[GetCharacterIndex("High Sea Lass")].dialog.currentnode = "First time";
			LAi_SetStayType(characterFromID("Bartholomew Roberts"));
			Characters[GetCharacterIndex("Bartholomew Roberts")].dialog.currentnode = "First time";
// QUEST END HERE FOR NOW Sir Christopher Mings
		break;

		case "And_off_to_Jamaica":
			ChangeCharacterAddressGroup(characterfromID("Couch Captain Charles"),"Turks_port", "goto", "P_goto4");	//JRH: new Turks, was goto4
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Couch Captain Charles"));
			SetCharacterRemovable(characterFromID("Couch Captain Charles"), false);
			LAi_SetCivilianGuardianType(characterFromID("Couch Captain Charles"));
			ChangeCharacterAddressGroup(characterfromID("Merciless Mark"),"Turks_port", "goto", "P_character1");	//JRH: new Turks, was character1
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Merciless Mark"));
			SetCharacterRemovable(characterFromID("Merciless Mark"), false);
			LAi_SetCivilianGuardianType(characterFromID("Merciless Mark"));
			ChangeCharacterAddressGroup(characterfromID("Thomas the Terror"),"Turks_port", "goto", "P_reload1_2");	//JRH: new Turks, was officers reload1_2
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Thomas the Terror"));
			SetCharacterRemovable(characterFromID("Thomas the Terror"), false);
			LAi_SetCivilianGuardianType(characterFromID("Thomas the Terror"));

			Pchar.quest.Couch_Captains_Quest.win_condition.l1 = "location";
			PChar.quest.Couch_Captains_Quest.win_condition.l1.character = Pchar.id;
			Pchar.quest.Couch_Captains_Quest.win_condition.l1.location = "Redmond_port";
			Pchar.quest.Couch_Captains_Quest.win_condition = "Couch_Captains_Quest";
		break;

		case "Couch_Captains_Quest":
			characters[GetCharacterIndex("Couch Captain Charles")].Dialog.Filename = "Couch Captain Charles_dialog.c";
			LAi_SetActorType(characterFromID("Couch Captain Charles"));
			LAi_ActorDialog(characterFromID("Couch Captain Charles"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Couch Captain Charles")].dialog.currentnode = "Arrival_at_Jamaica";
// QUEST END HERE FOR NOW Couch Captain Charles
		break;

		case "With_Thomas_to_Barbados":
// QUEST END HERE FOR NOW Thomas the Terror
		break;

		case "Alone_to_Jamaica":
// QUEST END HERE FOR NOW Armada
		break;

		case "With_Cat_to_Jamaica":
// QUEST END HERE FOR NOW Catalina
		break;

		case "Merciless_and_Spain":
			ChangeCharacterAddressGroup(characterfromID("Merciless Mark"),"Turks_port", "goto", "P_goto4");		//JRH: new Turks, was goto4
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Merciless Mark"));
			SetCharacterRemovable(characterFromID("Merciless Mark"), false);
			LAi_SetCivilianGuardianType(characterFromID("Merciless Mark"));
			ChangeCharacterAddressGroup(characterfromID("Petros"),"Turks_port", "goto", "P_character1");		//JRH: new Turks, was character1
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Petros"));
			SetCharacterRemovable(characterFromID("Petros"), false);
			LAi_SetCivilianGuardianType(characterFromID("Petros"));
			ChangeCharacterAddressGroup(characterfromID("Maximus"),"Turks_port", "goto", "P_reload1_2");		//JRH: new Turks, was officers reload1_2
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Maximus"));
			SetCharacterRemovable(characterFromID("Maximus"), false);
			LAi_SetCivilianGuardianType(characterFromID("Maximus"));

			pchar.quest.another_swim.win_condition.l1 = "locator";
			PChar.quest.another_swim.win_condition.l1.character = Pchar.id;
			pchar.quest.another_swim.win_condition.l1.location = "Turks_port";
			pchar.quest.another_swim.win_condition.l1.locator_group = "goto";
			pchar.quest.another_swim.win_condition.l1.locator = "P_goto11";						//JRH: new Turks, was goto11
			pchar.quest.another_swim.win_condition = "another_swim";
		break;

		case "another_swim":
			LAi_SetActorType(characterFromID("Short Jack Gold"));
			LAi_SetActorType(characterFromID("Catalina the Pirate"));
			LAi_ActorGoToLocator(characterfromID("Catalina the Pirate"), "goto", "P_goto20", "", 0.0);		//JRH: new Turks, was goto20
			LAi_ActorGoToLocator(characterfromID("Short Jack Gold"), "goto", "P_goto20", "", 0.0);			//JRH: new Turks, was goto20

			Pchar.quest.Sir_Christopher_Quest.win_condition.l1 = "location";
			PChar.quest.Sir_Christopher_Quest.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sir_Christopher_Quest.win_condition.l1.location = "QC_port";
			Pchar.quest.Sir_Christopher_Quest.win_condition = "Merciless_Mark_Quest";
		break;

		case "Merciless_Mark_Quest":
// QUEST END HERE FOR NOW Merciless Mark
		break;

		case "Maximus_to_Conceicao":
			ChangeCharacterAddressGroup(characterfromID("Maximus"),"Turks_port", "goto", "P_goto21");		//JRH: new Turks, was goto21
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Maximus"));
			SetCharacterRemovable(characterFromID("Maximus"), false);

			Pchar.quest.Couch_Captains_Quest.win_condition.l1 = "location";
			PChar.quest.Couch_Captains_Quest.win_condition.l1.character = Pchar.id;
			Pchar.quest.Couch_Captains_Quest.win_condition.l1.location = "Conceicao_port";
			Pchar.quest.Couch_Captains_Quest.win_condition = "Maximus_Quest";
		break;

		case "Maximus_Quest":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 3000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 3000); }
			LAi_SetOfficerType(CharacterFromID("Maximus"));
			LAi_QuestDelay("Maximus_Quest2", 0.0);
		break;

		case "Maximus_Quest2":
			ChangeCharacterAddressGroup(characterfromID("Maximus"),"Conceicao_port", "goto", "goto8");
			LAi_ActorWaitDialog(pchar, characterFromID("Maximus"));
			characters[GetCharacterIndex("Maximus")].Dialog.Filename = "Maximus_dialog.c";
			LAi_SetActorType(characterFromID("Maximus"));
			LAi_ActorDialog(characterFromID("Maximus"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Maximus")].dialog.currentnode = "Arrival_at_Conceicao";
		break;

		case "Maximus_Quest3":
			pchar.quest.Bonnie_talk = "Talk_to_the_chief";

			Pchar.quest.Maximus_Quest4.win_condition.l1 = "location";
			PChar.quest.Maximus_Quest4.win_condition.l1.character = Pchar.id;
			Pchar.quest.Maximus_Quest4.win_condition.l1.location = "Conceicao_townhall";
			Pchar.quest.Maximus_Quest4.win_condition = "Maximus_Quest4";
// QUEST END HERE FOR NOW Maximus
		break;

// TO BE CONTINUED

		PChar.questnotfound = true; // PB: Testing
	}
}
