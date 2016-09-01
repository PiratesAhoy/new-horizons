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
			LAi_ActorRunToLocator(characterFromID("Mystery Messenger"), "goto", "goto_40", "ReceivedLetter3", 5.0);
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
			LAi_QuestDelay("Found_my_sister", 0.0);
		break;

		case "Found_my_sister":
			pchar.quest.Bonnie_talk = "Our_first_meeting";
			LAi_SetActorType(characterFromID("Bonnie Devlin"));
			LAi_ActorWaitDialog(pchar, characterFromID("Bonnie Devlin"));
			Characters[GetCharacterIndex("Bonnie Devlin")].dialog.currentnode = "First time";
			Lai_ActorFollow(characterFromID("Bonnie Devlin"), pchar, "Start_treasure_search", 0.0);
			Characters[GetCharacterIndex("Emmanuel Devlin")].dialog.filename = "Laurence Wellman_dialog.c";
			Characters[GetCharacterIndex("Emmanuel Devlin")].dialog.currentnode = "First time";
			Characters[GetCharacterIndex("Emmanuel Devlin")].quest.meeting = 1;
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

			Pchar.quest.to_find_Short_Jack_Gold.win_condition.l1 = "location";
			PChar.quest.to_find_Short_Jack_Gold.win_condition.l1.character = Pchar.id;
			Pchar.quest.to_find_Short_Jack_Gold.win_condition.l1.location = "Turks_port";
			Pchar.quest.to_find_Short_Jack_Gold.win_condition = "to_find_Short_Jack_Gold";
		break;

		case "to_find_Short_Jack_Gold":
			AddQuestRecord("Such Devoted Sisters",3);
		break;

		case "to_find_Short_Jack_Gold2":
			Characters[GetCharacterIndex("Short Jack Gold")].dialog.filename = "Short Jack Gold_dialog.c";
			Locations[FindLocation("Turks_townhall")].reload.l1.disable = 1;
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(characterfromID("Bonnie Devlin"),"Turks_townhall", "goto", "goto7");
		break;

		case "Moving_right_along":
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
			LAi_QuestDelay("And_on_to_Nevis2", 0.0);
		break;

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
