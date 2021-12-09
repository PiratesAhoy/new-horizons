void QuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld;
	PChar = GetMainCharacter();

	switch(sQuestName)
	{
		////////////////////////////////////////////////////////////////////////
		//   вест про прокл€тые монетки
		////////////////////////////////////////////////////////////////////////
	
		case "Start":
			NPChar = characterFromID("Mystery Messenger");
			ChangeCharacterAddressGroup(NPChar, "Redmond_port", "officers", "sea_1_1");
			LAi_SetActorType(PChar);
			LAi_SetActorType(NPChar);
			LAi_ActorWaitDialog(PChar, NPChar);
			LAi_ActorFollow(NPChar, PChar, "Start_1", -1);
			SetNextWeather("Blue Sky"); 
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
		break;

		case "ReceivedLetter2":
			LAi_ActorRunToLocator(characterFromID("Mystery Messenger"), "reload", "Door_4", "ReceivedLetter3", 20.0);
		break;

		case "ReceivedLetter3":
			pchar.quest.Bonnie_talk = "meeting_her_father";
			ChangeCharacterAddress(characterfromID("Mystery Messenger"),"none", "");
			Pchar.quest.meet_habourmaster.win_condition.l1 = "location";
			PChar.quest.meet_habourmaster.win_condition.l1.character = Pchar.id;
			Pchar.quest.meet_habourmaster.win_condition.l1.location = "Redmond_Head_port_house";
			Pchar.quest.meet_habourmaster.win_condition = "meet_habourmaster";
		break;

		case "meet_habourmaster":
			pchar.quest.Bonnie_talk = "meeting_her_father";
			ChangeCharacterAddress(characterfromID("Laurence Wellman"),"none", "");
			ChangeCharacterAddressGroup(characterfromID("Emmanuel Devlin"),"Redmond_Head_port_house", "goto", "locator1");
			ChangeCharacterReputation(pchar, 10);
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
			LAi_ActorWaitDialog(pchar, characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].dialog.currentnode = "Arrived_in_Turks";
			Lai_ActorFollow(characterFromID("Bonnie Devlin"), pchar, "to_find_Short_Jack_Gold1", 0.0);
		break;

		case "to_find_Short_Jack_Gold1":
			Characters[GetCharacterIndex("Bonnie Devlin")].Dialog.CurrentNode = "Arrived_in_Turks";
			LAi_ActorDialog(characterFromID("Bonnie Devlin"), Pchar, "", 2.0, 0);
		break;

                case "crewmember_Turks":
			LAi_SetActorType(characterFromID("Crewmember Devlin"));
			LAi_ActorWaitDialog(pchar, characterFromID("Crewmember Devlin"));
			Lai_ActorFollow(characterFromID("Crewmember Devlin"), pchar, "crewmember_Turks2", 0.0);
		break;

                case "crewmember_Turks2":
			LAi_ActorDialog(characterFromID("Crewmember Devlin"), Pchar, "", 2.0, 0);
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
			LAi_ActorDialog(characterFromID("Blaze Devlin"), Pchar, "", 2.0, 0);
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
                        bQuestDisableSeaEnter = true
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
			LAi_SetPlayerType(pchar)
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
			LAi_SetPlayerType(pchar)
			GiveItem2Character(PChar, "key_haraldo");
			PlaySound("INTERFACE\took_item.wav");

			pchar.quest.Dont_leave.win_condition.l1 = "locator";
			pchar.quest.Dont_leave.win_condition.l1.location = "Wedding_Ballroom";
			pchar.quest.Dont_leave.win_condition.l1.locator_group = "reload";
			pchar.quest.Dont_leave.win_condition.l1.locator = "reload2";
			pchar.quest.Dont_leave.win_condition = "open_bedroom";
		break;

		case "open_bedroom":
			LAi_SetActorType(pchar)
			PlaySound("INTERFACE\key_unlock.wav");
                        TakeItemFromCharacter(PChar, "key_haraldo")
			LAi_QuestDelay("open_bedroom2", 2.0);
		break;

		case "open_bedroom2":
			DoQuestReloadToLocation("Haraldo_Bedroom", "reload", "reload1" ,"open_bedroom3");
			ChangeCharacterAddressGroup(characterFromID("Ernesto Haraldo"), "Haraldo_Bedroom", "sit", "sit1");
		break;

		case "open_bedroom3":
			Locations[FindLocation("Haraldo_Bedroom")].reload.l1.disable = 1;
			LAi_SetPlayerType(pchar)
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
			LAi_SetPlayerType(pchar);
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
                        bQuestDisableSeaEnter = false
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
                        bQuestDisableSeaEnter = false
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
                        bQuestDisableSeaEnter = true
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
		break;

		case "Blaze_lost_first_fight":
                        LAi_RemoveCheckMinHP(CharacterFromID("Dirty Cesar"));

			LAi_type_actor_Reset(CharacterFromID("Dirty Cesar"));

                        //LAi_SetPoorType(Pchar);
                        LAi_SetStunnedTypeNoGroup(Pchar);
			PlaySound("AMBIENT\cheer2.wav")

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
                        LAi_RemoveCheckMinHP(PChar);

			LAi_type_actor_Reset(CharacterFromID("Dirty Cesar"));
                        LAi_SetStunnedTypeNoGroup(characterFromID("Dirty Cesar"));

			PlaySound("AMBIENT\UnHappy-002.wav")

//			LAi_SetActorType(PChar);
			LAi_SetFightMode(PChar, false);
//			LAi_type_actor_Reset(Pchar);
//                        LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("Blaze_won_first_fight2", 5.0);
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
		break;

		case "Blaze_lost_second_fight":
			LAi_type_actor_Reset(CharacterFromID("Chico Malo"));
                        LAi_RemoveCheckMinHP(CharacterFromID("Chico Malo"));

                        //LAi_SetPoorType(Pchar);
                        LAi_SetStunnedTypeNoGroup(Pchar);
			PlaySound("AMBIENT\cheer2.wav")
			LAi_SetFightMode(PChar, false);

			LAi_QuestDelay("Blaze_lost_second_fight2", 5.0);
		break;

		case "Blaze_won_second_fight":
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
			EquipCharacterByItem(Pchar, "blade21");
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

			LAi_SetHP(PChar, LAI_DEFAULT_HP, LAI_DEFAULT_HP);
			EquipCharacterByItem(Pchar, "blade21");

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
                        bQuestDisableSeaEnter = false
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
                        bQuestDisableSeaEnter = false
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
                        bQuestDisableSeaEnter = true
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
			PlaySound("INTERFACE\took_item.wav");

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
                        bQuestDisableSeaEnter = false
//			SetCharacterShipLocation(Pchar, "Falaise_de_fleur_port_01");

/*
			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);
*/

                        TakeItemFromCharacter(Pchar, "jauri_note")
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
/*	Disable debriefing triggers for now as "Martinica_Debriefing" leads to dead end
				Pchar.quest.Martinica_Debriefing.win_condition.l1 = "locator";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.location = "Falaise_de_fleur_shore";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.locator_group = "reload";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.locator = "boat";
				Pchar.quest.Martinica_Debriefing.win_condition = "Martinica_Debriefing";
*/
			}
			else
			{
/*
				ChangeCharacterAddressGroup(characterFromID("Bonnie Devlin"), "Falaise_de_fleur_port_01", "officers", "sea_1");
				ChangeCharacterAddressGroup(characterFromID("Blaze Devlin"), "Falaise_de_fleur_port_01", "officers", "sea_2");
				Pchar.quest.Martinica_Debriefing.win_condition.l1 = "locator";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.location = "Falaise_de_fleur_port_01";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.locator_group = "reload";
				Pchar.quest.Martinica_Debriefing.win_condition.l1.locator = "sea_back";
				Pchar.quest.Martinica_Debriefing.win_condition = "Martinica_Debriefing";
*/
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

//=========================== CHARACTER SWITCHES ===========================================//

		case "Switch_to_Bonnie":
			SetModel(PChar, "BeatriceA", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
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
			SetModel(PChar, "Devlin", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
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
			SetModel(PChar, "Beatrice", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			PChar.sex = "woman";
                        PChar.model.animation = "Beatrice";
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
			GiveItem2Character(pchar, "spyglass4");
			EquipCharacterByItem(pchar, "spyglass4");
			GiveItem2Character(pchar, "blade13+1");
			EquipCharacterByItem(pchar, "blade13+1");
			GiveItem2Character(Pchar, "pistol5+2");
			EquipCharacterByItem(pchar, "pistol5+2");
			GiveItem2Character(PChar, "first_part_map");

			AddPassenger(Pchar, characterFromID("Bonnie Devlin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bonnie Devlin"));
			LAi_SetImmortal(characterFromID("Bonnie Devlin"), true);
			AddPassenger(Pchar, characterFromID("Blaze Devlin"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Blaze Devlin"));
			LAi_SetImmortal(characterFromID("Blaze Devlin"), true);

			SetCharacterShipLocation(Pchar, "Falaise_de_fleur_port_01");

			DoQuestReloadToLocation("Falaise_de_fleur_port_01", "reload", "sea" ,"Martinica_start");

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
