void QuestComplete(string sQuestName)
{
	ref PChar, sld;
	int iPassenger;
	PChar = GetMainCharacter();
	float locx;
	float locy;
	float locz;
	int iColony;
	int iTradeGoods, iQuantityGoods, iTradeNation;
	string homelocation, homegroup, homelocator, tavernfriend;
// KK -->
	int cc;
	int canQty = 0;
	int crewQty = 0;
	ref port;
// <-- KK
	float x, y, z;// MAXIMUS
	string nearloc;// MAXIMUS
	aref arship; // PB

	switch(sQuestName)
	{
		case "opening":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, pchar.model, "reload", "reload1");
			sld.name = pchar.name;
			sld.lastname = pchar.lastname;
			sld.id = "Original Model";
			Pchar.originalmodel = pchar.model;
			ChangeCharacterAddressGroup(CharacterFromID("Original Model"), "none", "", "");
			ChangeCharacterAddress(characterFromID("Carpenter"), "none", "");
			ChangeCharacterAddress(characterFromID("Crew_member_01"), "none", "");
			ChangeCharacterAddress(characterFromID("Crew_member_02"), "none", "");
			ChangeCharacterAddress(characterFromID("Crew_member_03"), "none", "");
			ChangeCharacterAddress(characterFromID("Crew_member_04"), "none", "");
			ChangeCharacterAddress(characterFromID("Crew_member_05"), "none", "");
			ChangeCharacterAddress(characterFromID("Crew_member_06"), "none", "");
			ChangeCharacterAddress(characterFromID("Crew_member_07"), "none", "");
			ChangeCharacterAddress(characterFromID("Crew_member_08"), "none", "");
			ChangeCharacterAddress(characterFromID("Horacio de la Vega"), "none", "");
			Locations[FindLocation("Tortuga_port")].reload.l2.disable = 1;

			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			LAi_SetActorType(pchar);
			Pchar.dialog.filename = "Storyteller_dialog.c";
			Pchar.dialog.currentnode = "First time";
			LAi_ActorSelfDialog(Pchar, "player_back");

			pchar.Turks = "0";

			if(ENABLE_CHEATMODE)
			{
				ChangeCharacterAddressGroup(CharacterFromID("Random Drunk"),"Tortuga_tavern", "sit", "sit9");
				pchar.quest.henry_talk = "for_game_shortcuts";
			}
		break;

		case "opening_1":
			LAi_QuestDelay("opening_2", 1.0);
		break;

		case "opening_2":
			LAi_SetActorType(pchar);
			Pchar.dialog.filename = "Storyteller_dialog.c";
			Pchar.dialog.currentnode = "Tavern_stuck";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "opening_3":
			LAi_SetActorType(characterFromID("Storyteller"));
			LAi_ActorSetSitMode(characterFromID("Storyteller"));
			LAi_QuestDelay("opening_4", 1.0);
		break;

		case "opening_4":
			LAi_ActorDialogNow(characterFromID("Storyteller"), pchar, "", -1);
		break;

		case "Take_a_seat_BB":
			DeleteAttribute(pchar,"quest.henry_talk");
			LAi_SetActorType(characterFromID("Storyteller"));
			LAi_ActorSetSitMode(characterFromID("Storyteller"));
			LAi_fade("Take_a_seat_BB2", "Take_a_seat_BB3");
		break;

		case "Take_a_seat_BB2":
			LAi_SetSitType(pchar);
			ChangeCharacterAddressGroup(pchar, "Tortuga_tavern", "candles", "sit4");
		break;

		case "Take_a_seat_BB3":
			Characters[GetCharacterIndex("Storyteller")].dialog.currentnode = "Tavern_Story2";
			LAi_ActorDialog(characterFromID("Storyteller"), pchar, "", 0.0, 0.0);
		break;

		case "TotBB_HtC3":
			// Set up actual beginning
			// MAXIMUS 05.09.2018 ==>
			PChar.old.name = "Jack";
			PChar.old.lastname = "Sparrow";
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			// MAXIMUS 05.09.2018 <==
			GiveModel2Player("47YoungJack",true);
			GiveModel2Player("depp",false);			// PB: For those players who REALLY can't wait
			GiveShip2Character(pchar,"Cutter2","Spreading Freedom",-1,ENGLAND,true,true);
			SetCharacterShipLocation(Pchar, "Cayman_port");
			SetCurrentTime(14.00, 0);
			pchar.jack = "Early_days";
			SetRelationsAsNation(ENGLAND); // PB: Set nations as per selected flag
			PChar.Flags.Pirate = 6; // PB: Jack Sparrow Pirate Flag
			PChar.Flags.Pirate.texture = 0;

			// Restore stuff
			LAi_SetPlayerType(pchar);
			DeleteAttribute(&Locations[FindLocation("Tortuga_Port")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Tortuga_Tavern")],"vcskip");
			Pchar.dialog.filename = "blaze_dialog.c";
			ChangeCharacterAddressGroup(CharacterFromID("Storyteller"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Random Drunk"), "none", "", "");
			DisableFastTravel(false);
			Locations[FindLocation("Tortuga_port")].reload.l2.disable = 0;
			bQuestDisableSeaEnter = false;

			DoQuestReloadToLocation("Cayman_Port", "reload", "sea", "_");
		break;

		case "Sparrow_load":
			DisableFastTravel(true);
			LAi_SetActorType(characterFromID("Grand Cayman soldier 02"));
			Characters[GetCharacterIndex("Grand Cayman soldier 02")].Dialog.Filename = "Port Guard_Dialog.c";
			Characters[GetCharacterIndex("Grand Cayman soldier 02")].Dialog.CurrentNode = "opening_scene";
			LAi_ActorDialog(characterFromID("Grand Cayman soldier 02"), Pchar, "", 0.0, 0);
		break;

		case "Sparrow_reload":
			DeleteAttribute(&Locations[FindLocation("Cayman_Port")],"vcskip"); // PB
			Characters[GetCharacterIndex("Grand Cayman soldier 02")].Dialog.Filename = "Greenford soldier_dialog.c";
			Characters[GetCharacterIndex("Grand Cayman soldier 02")].Dialog.CurrentNode = "First time";
			LAi_SetCivilianGuardianType(characterFromID("Grand Cayman soldier 02"));
			DoQuestReloadToLocation("Grand_Cayman_townhall", "reload", "reload1" ,"Sparrow_start");
		break;

		case "Sparrow_start":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			AlwaysRunToggle = false;
			ChangeCharacterAddressGroup(characterFromID("Teague Sparrow"), "Grand_Cayman_townhall", "sit", "sit1");
			LAi_SetSitType(characterfromID("Teague Sparrow"));
			ChangeCharacterAddressGroup(characterFromID("Tia Dalma"), "Grand_Cayman_townhall", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Matthew Shaw"), "Grand_Cayman_townhall", "goto", "goto10");
			ChangeCharacterAddressGroup(characterFromID("Port Guard"), "Grand_Cayman_townhall", "goto", "goto12");
			LAi_ActorTurnToCharacter(characterFromID("Matthew Shaw"), characterFromID("Tia Dalma"));
			ChangeCharacterAddress(characterfromID("Edmund Christobel Shaw"),"none", "");
			LAi_SetActorType(characterFromID("Tia Dalma"));
			LAi_SetActorType(characterFromID("Port Guard"));
			PChar.rank = 1;
			AddMoneyToCharacter(pchar, +1000);
			pchar.quest.Jacks_early_days = "meet_father_Teague";
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "goto11", "into_position_Cayman", 10);
			Characters[GetCharacterIndex("Port Guard")].dialog.currentnode = "under arrest";
		break;

		case "into_position_Cayman":
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("Port Guard")].Dialog.Filename = "Port Guard_dialog.c";
			LAi_SetActorType(characterFromID("Port Guard"));
			LAi_ActorDialogNow(characterFromID("Port Guard"),PChar,"",1.0);
			Characters[GetCharacterIndex("Port Guard")].dialog.currentnode = "under arrest";
		break;

		case "into_position_Cayman2":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Tia Dalma"));
			LAi_QuestDelay("Girl_runs_out", 2.0);
		break;

		case "Girl_runs_out":
			LAi_SetActorType(characterFromID("Teague Sparrow"));
			LAi_ActorAnimation(characterFromID("Teague Sparrow"), "StandUp", "", 1.0);
			LAi_ActorGoToLocator(characterFromID("Tia Dalma"), "reload", "reload1", "Girl_runs_out2",10); // PB: Running seems out-of-character for Tia Dalma to me
		break;

		case "Girl_runs_out2":
			LAi_ActorGoToLocator(characterFromID("Teague Sparrow"), "goto", "goto8", "tempone", 1.0);
			ChangeCharacterAddress(characterfromID("Tia Dalma"),"none", "");
		break;

		case "tempone":
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("Matthew Shaw")].Dialog.Filename = "Matthew Shaw_dialog.c";
			LAi_SetActorType(characterFromID("Matthew Shaw"));
			Characters[GetCharacterIndex("Matthew Shaw")].Dialog.CurrentNode = "Arrest at Cayman";
			LAi_ActorDialogNow(characterFromID("Matthew Shaw"), Pchar, "", -1);
		break;

		case "present myself":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "goto7", "torn_off_a_strip", 5);
		break;

		case "torn_off_a_strip":
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddress(characterfromID("Port Guard"),"none", "");

			characters[GetCharacterIndex("Teague Sparrow")].Dialog.Filename = "Teague Sparrow_dialog.c";
			LAi_SetActorType(characterFromID("Teague Sparrow"));
			LAi_ActorDialog(characterFromID("Teague Sparrow"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teague Sparrow")].dialog.currentnode = "First time";
		break;

		case "Now_a_word_from_the_governor":
			characters[GetCharacterIndex("Matthew Shaw")].Dialog.Filename = "Matthew Shaw_dialog.c";
			LAi_SetActorType(characterFromID("Matthew Shaw"));
			LAi_ActorDialog(characterFromID("Matthew Shaw"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Matthew Shaw")].dialog.currentnode = "First time";
		break;

		case "More_dialogue_from_Teague":
			characters[GetCharacterIndex("Teague Sparrow")].Dialog.Filename = "Teague Sparrow_dialog.c";
			LAi_SetActorType(characterFromID("Teague Sparrow"));
			LAi_ActorDialog(characterFromID("Teague Sparrow"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teague Sparrow")].dialog.currentnode = "Time_to_leave";
		break;

		case "More_dialogue_from_Teague2":
			LAi_ActorRunToLocator(characterFromID("Teague Sparrow"), "reload", "reload1", "Now_a_word_from_the_governor2", 10);	
		break;

		case "Now_a_word_from_the_governor2":
			ChangeCharacterAddress(characterfromID("Teague Sparrow"),"none", "");
			characters[GetCharacterIndex("Matthew Shaw")].Dialog.Filename = "Matthew Shaw_dialog.c";
			LAi_SetActorType(characterFromID("Matthew Shaw"));
			LAi_ActorDialog(characterFromID("Matthew Shaw"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Matthew Shaw")].dialog.currentnode = "A_background_discussion";
		break;

		case "Matthew_the_governor_leaves":
			SetQuestHeader("Pirate Lord");
			AddQuestRecord("Pirate Lord", 1);

			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "First time Cayman";
			ChangeCharacterAddressGroup(CharacterFromID("Thomas Tipman"),"Grand_Cayman_town", "goto", "goto30");
			LAi_ActorRunToLocator(characterFromID("Matthew Shaw"), "reload", "reload1", "Matthew_the_governor_leaves2", 10);
		break;

		case "Matthew_the_governor_leaves2":
			SetQuestHeader("My Early Days");
			AddQuestRecord("My Early Days",11);
			ChangeCharacterAddress(characterfromID("Matthew Shaw"),"none", "");
			LAi_ActorTurnToCharacter(characterFromID("Thomas Tipman"), PChar);

			characters[GetCharacterIndex("Thomas Tipman")].Dialog.Filename = "Thomas Tipman_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("Thomas Tipman"));
			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "First time Cayman";

			DisableFastTravel(false);
			EndQuestMovie();

			Pchar.quest.More_information_Cayman.win_condition.l1 = "location";
			PChar.quest.More_information_Cayman.win_condition.l1.character = Pchar.id;
			Pchar.quest.More_information_Cayman.win_condition.l1.location = "Grand_Cayman_Tavern";
			Pchar.quest.More_information_Cayman.win_condition = "More_information_Cayman";

			Pchar.quest.Now_in_Oxbay_from_Cayman.win_condition.l1 = "location";
			PChar.quest.Now_in_Oxbay_from_Cayman.win_condition.l1.character = Pchar.id;
			Pchar.quest.Now_in_Oxbay_from_Cayman.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.Now_in_Oxbay_from_Cayman.win_condition = "Now_in_Oxbay_from_Cayman";
		break;

		case "More_information_Cayman":
			ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "sit", "sit2"); // PB
			ChangeCharacterAddress(characterfromID("Thomas Tipman"),"none", "");
			Locations[FindLocation("Grand_Cayman_Tavern")].vcskip = true;

			ChangeCharacterAddressGroup(CharacterFromID("Thomas the Terror"),"Grand_Cayman_Tavern", "goto", "goto6");
			LAi_SetCivilianGuardianType(characterFromID("Thomas the Terror"));

			characters[GetCharacterIndex("Thomas the Terror")].Dialog.Filename = "Thomas the Terror_dialog.c";
			Characters[GetCharacterIndex("Thomas the Terror")].dialog.currentnode = "First_meet_Thomas_the_Terror";
		break;

		case "Sailing for Oxbay with Thomas":
			Pchar.Quest.Now_in_Oxbay_from_Cayman.over = "yes";

			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Thomas the Terror"));
			SetCharacterRemovable(characterFromID("Thomas the Terror"), false); // PB
			setCharacterShipLocation(characterFromID("Thomas the Terror"), "Cayman_Port");
			LAi_SetOfficerType(characterfromID("Thomas the Terror"));

			Pchar.quest.Now_in_Oxbay_from_Cayman_Thomas.win_condition.l1 = "location";
			PChar.quest.Now_in_Oxbay_from_Cayman_Thomas.win_condition.l1.character = Pchar.id;
			Pchar.quest.Now_in_Oxbay_from_Cayman_Thomas.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.Now_in_Oxbay_from_Cayman_Thomas.win_condition = "Now_in_Oxbay_from_Cayman_Thomas";

			DeleteAttribute(&Locations[FindLocation("Grand_Cayman_Tavern")],"vcskip"); // PB
		break;

		case "Now_in_Oxbay_from_Cayman_Thomas":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			Pchar.Quest.More_information_Cayman.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Lieutenant Bligh"), "Oxbay_port", "goto", "goto28");
			ChangeCharacterAddressGroup(CharacterFromID("Thomas the Terror"),"Oxbay_port", "goto", "goto3");

			LAi_SetActorType(characterfromID("Thomas the Terror"));
			LAi_ActorDialogNow(Pchar, characterFromID("Thomas the Terror"), "", -1);
			LAi_ActorDialog(characterFromID("Thomas the Terror"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Thomas the Terror")].dialog.currentnode = "Goodbye_at_Oxbay";
		break;

		case "Now_in_Oxbay_from_Cayman":
			ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "sit", "sit2"); // PB
			AddQuestRecord("My Early Days",13);
			Pchar.Quest.Now_in_Oxbay_from_Cayman_Thomas.over = "yes";
			ChangeCharacterAddress(characterfromID("Thomas the Terror"),"none", "");
			ChangeCharacterAddressGroup(characterFromID("Lieutenant Bligh"), "Oxbay_port", "goto", "goto28");

			characters[GetCharacterIndex("Lieutenant Bligh")].Dialog.Filename = "Lieutenant Bligh_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("Lieutenant Bligh"));
			Characters[GetCharacterIndex("Lieutenant Bligh")].dialog.currentnode = "First_meet_Bligh";

			ChangeCharacterAddressGroup(CharacterFromID("Maykin Blundas"),"Oxbay_tavern", "goto", "goto16");

			Locations[FindLocation("Oxbay_tavern")].vcskip = true;	// GR: See what happens if we vcskip the tavern *before* we get there!
			Pchar.quest.Blundas_in_the_Tavern.win_condition.l1 = "location";
			PChar.quest.Blundas_in_the_Tavern.win_condition.l1.character = Pchar.id;
			Pchar.quest.Blundas_in_the_Tavern.win_condition.l1.location = "Oxbay_tavern";
			Pchar.quest.Blundas_in_the_Tavern.win_condition = "Blundas_in_the_Tavern";
		break;

		case "Thomas leaves at Oxbay":
			LAi_SetActorType(characterFromID("Thomas the Terror"));
			LAi_ActorGoToLocator(characterFromID("Thomas the Terror"), "goto", "goto7", "", 35);

			RemoveCharacterCompanion(pchar, characterFromID("Thomas the Terror"));

			characters[GetCharacterIndex("Lieutenant Bligh")].Dialog.Filename = "Lieutenant Bligh_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("Lieutenant Bligh"));
			Characters[GetCharacterIndex("Lieutenant Bligh")].dialog.currentnode = "First_meet_Bligh";

			ChangeCharacterAddressGroup(CharacterFromID("Maykin Blundas"),"Oxbay_tavern", "goto", "goto16");

			Locations[FindLocation("Oxbay_tavern")].vcskip = true;	// GR: See what happens if we vcskip the tavern *before* we get there!
			Pchar.quest.Blundas_in_the_Tavern.win_condition.l1 = "location";
			PChar.quest.Blundas_in_the_Tavern.win_condition.l1.character = Pchar.id;
			Pchar.quest.Blundas_in_the_Tavern.win_condition.l1.location = "Oxbay_tavern";
			Pchar.quest.Blundas_in_the_Tavern.win_condition = "Blundas_in_the_Tavern";
		break;

		case "Blundas_in_the_Tavern":
//			Locations[FindLocation("Oxbay_tavern")].vcskip = true;	// GR: you're in the tavern, too late to vcskip

			characters[GetCharacterIndex("Maykin Blundas")].Dialog.Filename = "Maykin Blundas_dialog.c";
			Characters[GetCharacterIndex("Maykin Blundas")].dialog.currentnode = "First_meet_Blundas";
			LAi_QuestDelay("having_met_Blundas", 20.0);

			pchar.quest.Jacks_early_days = "first_meeting";
			ChangeCharacterAddressGroup(CharacterFromID("Billy Brock"),"Oxbay_tavern", "goto", "goto21");
			LAi_SetPoorType(CharacterFromID("Billy Brock"));
		break;

		case "having_met_Blundas":
			if(!CheckAttribute(Pchar,"talkingblundas")) // PB
			{
				LAi_SetActorType(characterFromID("Maykin Blundas"));
				LAi_ActorGoToLocation(characterFromID("Maykin Blundas"), "reload", "reload1", "none", "", "", "", 0.0);
			}
		break;

		case "will_join_Blundas":
			ChangeCharacterAddress(characterfromID("Lieutenant Bligh"),"none", "");

			LAi_SetActorType(characterFromID("Maykin Blundas"));
			LAi_ActorGoToLocator(characterFromID("Maykin Blundas"), "reload", "reload1", "having_met_Blundas3", 10);
		break;

		case "having_met_Blundas3":
			ChangeCharacterAddress(characterfromID("Maykin Blundas"),"none", "");

			Pchar.quest.Blundas_in_Port.win_condition.l1 = "location";
			PChar.quest.Blundas_in_Port.win_condition.l1.character = Pchar.id;
			Pchar.quest.Blundas_in_Port.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.Blundas_in_Port.win_condition = "Blundas_in_Port";
		break;

		case "Blundas_in_Port": // Temp fix to end quest until alternate quest written
//			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Maykin Blundas"));
//			SetCharacterRemovable(characterFromID("Maykin Blundas"), false);
//			setCharacterShipLocation(characterFromID("Maykin Blundas"), "Oxbay_port");
//			LAi_SetOfficerType(characterfromID("Maykin Blundas"));

			ChangeCharacterAddressGroup(CharacterFromID("Maykin Blundas"),"Oxbay_port", "goto", "goto3");
			characters[GetCharacterIndex("Maykin Blundas")].Dialog.Filename = "Maykin Blundas_dialog.c";
			LAi_SetStayType(characterFromID("Maykin Blundas"));
			LAi_ActorDialog(characterFromID("Maykin Blundas"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Maykin Blundas")].dialog.currentnode = "Blundas_for_Skulls";
		break;

		case "TEMP_Blundas_Finish":
			LAi_SetImmortal(CharacterFromID("Maykin Blundas"), true);
			LAi_SetImmortal(pchar, false);

			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);

			LAi_ActorAttack(characterfromID("Maykin Blundas"), pchar, "");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;
// QUEST DEAD END - Player made incorrect choice - should have spoken to Lieutenant Bligh first

		case "having_met_Bligh":
			pchar.quest.Blundas_in_the_Tavern.over="yes";

			pchar.quest.Jacks_early_days = "first_meeting";
			LAi_SetActorType(characterFromID("Lieutenant Bligh"));
			LAi_ActorGoToLocation(characterFromID("Lieutenant Bligh"), "reload", "reload1", "none", "", "", "", 0.0);

			ChangeCharacterAddress(characterfromID("Maykin Blundas"),"none", "");
			ChangeCharacterAddress(characterfromID("Thomas the Terror"),"none", "");

			Pchar.quest.On_to_the_Tavern.win_condition.l1 = "location";
			PChar.quest.On_to_the_Tavern.win_condition.l1.character = Pchar.id;
			Pchar.quest.On_to_the_Tavern.win_condition.l1.location = "Oxbay_tavern";
			Pchar.quest.On_to_the_Tavern.win_condition = "On_to_the_Tavern";
		break;

		case "On_to_the_Tavern":
//			Locations[FindLocation("Oxbay_tavern")].vcskip = true;	// GR: you're in the tavern, too late to vcskip
			ChangeCharacterAddressGroup(CharacterFromID("Billy Brock"),"Oxbay_tavern", "goto", "goto21");
			ChangeCharacterAddressGroup(characterFromID("Sir Christopher Mings"), "Oxbay_tavern", "sit", "sit5");
			LAi_SetSitType(characterfromID("Sir Christopher Mings"));
			LAi_SetPoorType(CharacterFromID("Billy Brock"));
		break;

		case "On_to_the_Tailors":
			AddQuestRecord("My Early Days",2);
			ChangeCharacterAddress(characterfromID("Lieutenant Bligh"),"none", "");

			Pchar.quest.On_to_the_Tailors2.win_condition.l1 = "location";
			PChar.quest.On_to_the_Tailors2.win_condition.l1.character = Pchar.id;
			Pchar.quest.On_to_the_Tailors2.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.On_to_the_Tailors2.win_condition = "On_to_the_Tailors2";
		break;

		case "On_to_the_Tailors2":
			ChangeCharacterAddressGroup(CharacterFromID("Annabella Brinkley"),"Oxbay_town", "goto", "goto10");
			LAi_SetActorType(characterFromID("Annabella Brinkley"));
			LAi_SetOfficerType(characterFromID("Annabella Brinkley"));
			LAi_QuestDelay("On_to_the_Tailors3", 10.0);
		break;

		case "On_to_the_Tailors3":
			LAi_ActorWaitDialog(PChar,characterFromID("Annabella Brinkley"));
			LAi_ActorDialog(characterFromID("Annabella Brinkley"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Annabella Brinkley")].dialog.currentnode = "First time";
			ChangeCharacterAddress(characterfromID("Billy Brock"),"none", "");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
		break;

		case "Sit_with_Sir_Christopher":
			LAi_Fade("Sit_with_Sir_Christopher_2", "StartTalkingInTavern");
		break;

		case "Sit_with_Sir_Christopher_2":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Oxbay_tavern", "sit", "sit4");
		break

		case "StartTalkingInTavern":
			SetCurrentTime(10, 0);
//			LAi_ActorDialogNow(Pchar, characterFromID("Sir Christopher Mings"), "", -1);
//			LAi_ActorDialog(characterFromID("Sir Christopher Mings"),PChar,"",1.0,1.0);
			LAi_ActorDialogNow(Pchar, characterFromID("Sir Christopher Mings"), "Start_Again_in_Tavern", 1.0);
			Characters[GetCharacterIndex("Sir Christopher Mings")].dialog.currentnode = "Introduction2";
		break;

		case "Start_Again_in_Tavern":
			LAi_Fade("Start_Again_in_Tavern2", "");
		break;

		case "Start_Again_in_Tavern2":
			LAi_SetPlayerType(pchar);
			DoQuestReloadToLocation("Oxbay_tavern", "goto", "goto2", "_");
			DeleteAttribute(&Locations[FindLocation("Oxbay_tavern")],"vcskip"); // PB
		break;

		case "Mings_step_two":
			LAi_SetActorType(characterFromID("Sir Christopher Mings"));
			LAi_ActorAnimation(characterFromID("Sir Christopher Mings"), "StandUp", "Mings_step_two2", 1.0);
		break;

		case "Mings_step_two2":
			LAi_ActorGoToLocator(characterFromID("Sir Christopher Mings"), "goto", "goto4", "Mings_step_two3", 5.0);
		break;

		case "Mings_step_two3":
			LAi_ActorGoToLocator(characterFromID("Sir Christopher Mings"), "reload", "reload1", "Mings_step_two4", 10.0);
		break;

		case "Mings_step_two4":
			ChangeCharacterAddress(characterfromID("Lieutenant Bligh"),"none", "");
			ChangeCharacterAddress(characterFromID("Sir Christopher Mings"), "None", "");
			LAi_SetPlayerType(pchar);
			DoQuestReloadToLocation("Oxbay_tavern", "goto", "goto2", "_");

			SetQuestHeader("The Brotherhood");

			/*pchar.quest.The_Brotherhood_begins.win_condition.l1 = "locator";
			pchar.quest.The_Brotherhood_begins.win_condition.l1.location = "Oxbay_town";
			pchar.quest.The_Brotherhood_begins.win_condition.l1.locator_group = "reload";
			pchar.quest.The_Brotherhood_begins.win_condition.l1.locator = "reload4";
			pchar.quest.The_Brotherhood_begins.win_condition = "The_Brotherhood_begins";*/
			pchar.quest.The_Brotherhood_begins.win_condition.l1 = "location";
			pchar.quest.The_Brotherhood_begins.win_condition.l1.location = "Mings_townhall";
			pchar.quest.The_Brotherhood_begins.win_condition = "The_Brotherhood_begins";

			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 0;
		break;

		case "now_find_a_sister":
			ChangeCharacterAddress(characterFromID("Sir Christopher Mings"), "None", "");

			Pchar.quest.to_find_a_sister.win_condition.l1 = "location";
			PChar.quest.to_find_a_sister.win_condition.l1.character = Pchar.id;
			Pchar.quest.to_find_a_sister.win_condition.l1.location = "Greenford_port";
			Pchar.quest.to_find_a_sister.win_condition = "to_find_a_sister";

			Pchar.quest.to_find_a_sisterA.win_condition.l1 = "location";
			PChar.quest.to_find_a_sisterA.win_condition.l1.character = Pchar.id;
			Pchar.quest.to_find_a_sisterA.win_condition.l1.location = "Greenford_suburb";
			Pchar.quest.to_find_a_sisterA.win_condition = "to_find_a_sister";
		break;

		case "to_find_a_sister":
			Pchar.Quest.to_find_a_sister.over = "yes";
			Pchar.Quest.to_find_a_sisterA.over = "yes";
			pchar.quest.Jacks_early_days = "find_sister_one";
			LAi_SetActorType(characterFromID("Annabella Brinkley"));
			Lai_ActorFollow(characterFromID("Annabella Brinkley"), pchar, "to_find_a_sister_next", 3.0);
		break;

		case "to_find_a_sister_next":
			characters[GetCharacterIndex("Annabella Brinkley")].Dialog.Filename = "Annabella Brin_dialog.c";
			LAi_SetActorType(characterFromID("Annabella Brinkley"));
			LAi_ActorDialogNow(characterFromID("Annabella Brinkley"),PChar,"",1.0);
			Characters[GetCharacterIndex("Annabella Brinkley")].dialog.currentnode = "First time";
		break;

		case "to_find_a_sister_capture":
			Locations[FindLocation("Greenford_tavern")].vcskip = true;
			ChangeCharacterAddressGroup(CharacterFromID("Eng_soldier_39"),"Greenford_tavern", "goto", "goto6");
			ChangeCharacterAddressGroup(CharacterFromID("Eng_soldier_38"),"Greenford_tavern", "goto", "goto5");
			ChangeCharacterAddressGroup(CharacterFromID("Billy Brock"),"Greenford_tavern", "goto", "goto8");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
		break;

		case "Get_arrested_in_Greenford":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Eng_soldier_39"));
			LAi_SetActorType(characterFromID("Eng_soldier_38"));
			Lai_ActorFollow(characterFromID("Eng_soldier_39"), pchar, "Get_arrested_in_Greenford2", 0.0);
		break;

		case "Get_arrested_in_Greenford2":
			characters[GetCharacterIndex("Eng_soldier_39")].Dialog.Filename = "Soldier_dialog.c";
			pchar.quest.Jacks_early_days = "about_to_go_down";
			LAi_ActorWaitDialog(PChar,characterFromID("Eng_soldier_39"));
			LAi_ActorDialog(characterFromID("Eng_soldier_39"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Eng_soldier_39")].dialog.currentnode = "First time";
		break;

		case "Almost_arrested":
			LAi_ActorTurnToCharacter(characterFromID("Eng_soldier_38"), PChar);
			characters[GetCharacterIndex("Eng_soldier_38")].Dialog.Filename = "Soldier_dialog.c";
			pchar.quest.Jacks_early_days = "some_fast_talking";
			LAi_ActorWaitDialog(PChar,characterFromID("Eng_soldier_38"));
			LAi_ActorDialog(characterFromID("Eng_soldier_38"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Eng_soldier_38")].dialog.currentnode = "First time";
		break;

		case "Almost_arrested_again":
			LAi_ActorTurnToCharacter(characterFromID("Eng_soldier_38"), PChar);
			characters[GetCharacterIndex("Eng_soldier_38")].Dialog.Filename = "Soldier_dialog.c";
			pchar.quest.Jacks_early_days = "continue_fast_talking";
			LAi_ActorWaitDialog(PChar,characterFromID("Eng_soldier_38"));
			LAi_ActorDialog(characterFromID("Eng_soldier_38"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Eng_soldier_38")].dialog.currentnode = "First time";
		break;

		case "Almost_arrested2":
			LAi_ActorTurnToCharacter(characterFromID("Eng_soldier_39"), PChar);
			characters[GetCharacterIndex("Eng_soldier_39")].Dialog.Filename = "Soldier_dialog.c";
			pchar.quest.Jacks_early_days = "narrow_squeak";
			LAi_ActorWaitDialog(PChar,characterFromID("Eng_soldier_39"));
			LAi_ActorDialog(characterFromID("Eng_soldier_39"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Eng_soldier_39")].dialog.currentnode = "First time";
		break;

		case "And_the_soldiers_leave":
			LAi_SetActorType(characterFromID("Billy Brock"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eng_soldier_39"));
			LAi_ActorGoToLocator(characterFromID("Billy Brock"), "goto", "goto6", "", 15);
			LAi_ActorGoToLocator(characterFromID("Eng_soldier_38"), "reload", "reload1", "", 5);
			LAi_ActorGoToLocator(characterFromID("Eng_soldier_39"), "reload", "reload1", "And_the_soldiers_leave2", 5);
		break;

		case "And_the_soldiers_leave2":
			ChangeCharacterAddress(characterFromID("Eng_soldier_38"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_soldier_39"), "None", "");
			LAi_ActorTurnToCharacter(characterFromID("Billy Brock"), PChar);
			LAi_ActorFollow(characterFromID("Billy Brock"),Pchar,"Billy_in_Greenford",0.0);
		break;

		case "Billy_in_Greenford":
			LAi_ActorTurnToCharacter(characterFromID("Billy Brock"), PChar);
			characters[GetCharacterIndex("Billy Brock")].Dialog.Filename = "Billy Brock_dialog.c";
			pchar.quest.Jacks_early_days = "narrow_squeak_over";
			LAi_ActorWaitDialog(PChar,characterFromID("Billy Brock"));
			LAi_ActorDialog(characterFromID("Billy Brock"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Billy Brock")].dialog.currentnode = "Greenford_Tavern_Meeting";
			ChangeCharacterAddressGroup(characterfromID("Annabella Brinkley"), "Greenford_tavern_upstairs", "goto", "goto3");
		break;

		case "Talk_upstairs":
			DoQuestReloadToLocation("Greenford_tavern_upstairs", "goto", "goto2", "Talk_with_Billy_in_Tavern");
			ChangeCharacterAddressGroup(characterfromID("Billy Brock"), "Greenford_tavern_upstairs", "goto", "goto7");
			LAi_SetActorType(characterFromID("Billy Brock"));
			LAi_SetActorType(characterFromID("Annabella Brinkley"));
			LAi_ActorTurnToCharacter(characterFromID("Annabella Brinkley"), Pchar);
		break;

		case "Talk_with_Billy_in_Tavern":
			LAi_ActorWaitDialog(pchar, characterFromID("Annabella Brinkley"));
			Characters[GetCharacterIndex("Annabella Brinkley")].Dialog.CurrentNode = "Talk_in_Tavern";
			LAi_ActorDialog(characterFromID("Annabella Brinkley"), Pchar, "", 2.0, 0);
		break;

		case "Upstairs_Fight":
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetImmortal(characterFromID("Billy Brock"), true);
			LAi_ActorAttack(characterfromID("Billy Brock"), pchar, "");
			LAi_QuestDelay("Upstairs_Fight2", 2.0);
		break;

		case "Upstairs_Fight2":
			Lai_KillCharacter(pchar);
			LAi_QuestDelay("Upstairs_Fight3", 4.9);
		break;

		case "Upstairs_Fight3":
			pchar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "land");
		break;

		case "Rescue_Exit":
			ChangeCharacterAddress(characterFromID("Billy Brock"), "None", "");
			ChangeCharacterAddress(characterFromID("Annabella Brinkley"), "None", "");
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brinkley"));
			RemovePassenger(pchar, characterFromID("Annabella Brinkley"));
			LAi_SetPlayerType(pchar);
			LAi_QuestDelay("Off_to_QC", 1.0);
		break;

		case "Off_to_QC":
			DisableFastTravel(true);
			pchar.quest.A_Possible_Side_Track.win_condition.l1 = "locator";
			pchar.quest.A_Possible_Side_Track.win_condition.l1.location = "Greenford_tavern";
			pchar.quest.A_Possible_Side_Track.win_condition.l1.locator_group = "goto";
			pchar.quest.A_Possible_Side_Track.win_condition.l1.locator = "goto8";
			pchar.quest.A_Possible_Side_Track.win_condition = "A_Possible_Side_Track";
		break;

		case "A_Possible_Side_Track":
			pchar.quest.Jacks_early_days = "A_spot_of_bother";
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "Greenford_tavern", "goto", "goto5");
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			LAi_QuestDelay("A_Possible_Side_Track2", 10.0);
		break;

		case "A_Possible_Side_Track2":
			LAi_ActorWaitDialog(PChar,characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "First time";
		break;

		case "Is_this_a_sidetrack":
			LAi_ActorRunToLocator(characterFromID("Susan Shaypen"), "reload", "reload1", "Is_this_a_sidetrack2", 1);
			SetQuestHeader("Mystery Woman");
			AddQuestRecord("Mystery Woman",1);
		break;

		case "Is_this_a_sidetrack2":
			DisableFastTravel(false);
			ChangeCharacterAddress(characterFromID("Susan Shaypen"), "none", "");
			AddQuestRecord("My Early Days",6);

			Pchar.quest.Sidetrack3.win_condition.l1 = "location";
			PChar.quest.Sidetrack3.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sidetrack3.win_condition.l1.location = "Oxbay_shore_02";
			Pchar.quest.Sidetrack3.win_condition = "Sidetrack3";

			Pchar.quest.Looking_for_sisters.win_condition.l1 = "location";
			PChar.quest.Looking_for_sisters.win_condition.l1.character = Pchar.id;
			Pchar.quest.Looking_for_sisters.win_condition.l1.location = "QC_port";
			Pchar.quest.Looking_for_sisters.win_condition = "Looking_for_sisters";
		break;

		case "Sidetrack3":
			DisableFastTravel(true);
            DeleteAttribute(pchar,"Looking_for_sisters");
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "Oxbay_shore_02", "goto", "locator8");
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			LAi_QuestDelay("SideTrack4", 1.0);
		break;

		case "Sidetrack4":
			LAi_ActorWaitDialog(PChar,characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Susan_on_Beach";
		break;

		case "Not_going_to_help_Susan":
			LAi_ActorRunToLocator(characterFromID("Susan Shaypen"), "goto", "locator12", "Not_going_to_help_Susan2", 15);
			ChangeCharacterAddressGroup(CharacterFromID("Eng_soldier_39"),"Oxbay_shore_02", "goto", "locator26");
			ChangeCharacterAddressGroup(CharacterFromID("Eng_soldier_38"),"Oxbay_shore_02", "goto", "locator13");
			LAi_ActorTurnToCharacter(characterFromID("Eng_soldier_39"), pchar);
			LAi_ActorTurnToCharacter(characterFromID("Eng_soldier_38"), pchar);
			Locations[FindLocation("Oxbay_shore_02")].reload.l2.disable = 1;
		break;

		case "Not_going_to_help_Susan2":
			ChangeCharacterAddress(characterFromID("Susan Shaypen"), "none", "");
			LAi_SetActorType(characterFromID("Eng_soldier_39"));
			LAi_SetActorType(characterFromID("Eng_soldier_38"));
			Lai_ActorFollow(characterFromID("Eng_soldier_39"), pchar, "Not_going_to_help_Susan3", 10.0);
			Lai_ActorFollow(characterFromID("Eng_soldier_38"), pchar, "", 10.0);

		break;

		case "Not_going_to_help_Susan3":
			LAi_ActorTurnToCharacter(pchar, characterFromID("Eng_soldier_39"));
			characters[GetCharacterIndex("Eng_soldier_39")].Dialog.Filename = "Soldier_dialog.c";
			pchar.quest.Jacks_early_days = "deeper_in_trouble";
			LAi_ActorWaitDialog(PChar,characterFromID("Eng_soldier_39"));
			LAi_ActorDialog(characterFromID("Eng_soldier_39"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Eng_soldier_39")].dialog.currentnode = "First time";
		break;

		case "Arrested_this_time":
			GiveShip2Character(pchar,"Tartane50","Flying Fish",-1,ENGLAND,true,true);
			SetCharacterShipLocation(Pchar, "Greenford_port");
			ChangeCharacterAddress(characterFromID("Eng_soldier_39"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("Eng_soldier_38"),"greenford_prison", "officers", "reload1_2");
			ChangeCharacterAddressGroup(CharacterFromID("Greenford Prison Commendant"),"greenford_prison", "officers", "reload1_1");
			DoQuestReloadToLocation("greenford_prison", "goto", "goto16", "_");
			LAi_QuestDelay("In_Greenford_Prison", 1.0);
		break;

		case "In_Greenford_Prison":
			LAi_SetActorType(Pchar);
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			LAi_ActorTurnToCharacter(PChar, characterFromID("Eng_soldier_38"));
			LAi_SetActorType(characterFromID("Greenford Prison Commendant"));
			characters[GetCharacterIndex("Greenford Prison Commendant")].Dialog.Filename = "Greenford Commander_dialog.c";
			pchar.quest.Jacks_early_days = "now_in_prison";
			LAi_ActorWaitDialog(PChar,characterFromID("Greenford Prison Commendant"));
			LAi_ActorDialog(characterFromID("Greenford Prison Commendant"),PChar,"",1.0,1.0);
		break;

		case "soldier_speaks_up":
			LAi_SetActorType(characterFromID("Eng_soldier_38"));
			characters[GetCharacterIndex("Eng_soldier_38")].Dialog.Filename = "Soldier_dialog.c";
			LAi_ActorWaitDialog(PChar,characterFromID("Eng_soldier_38"));
			LAi_ActorDialog(characterFromID("Eng_soldier_38"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Eng_soldier_38")].dialog.currentnode = "First time";
		break;

		case "Back_to_the_Commander":
			pchar.quest.Jacks_early_days = "second_narrow_squeak";
			LAi_ActorWaitDialog(PChar,characterFromID("Greenford Prison Commendant"));
			LAi_ActorDialog(characterFromID("Greenford Prison Commendant"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Greenford Prison Commendant")].dialog.currentnode = "First time";
		break;

		case "free_again_in_Greenford":
			DisableFastTravel(false);
			LAi_SetPlayerType(pchar);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			pchar.quest.Susan_Shaypen_Quests = "Shaypen_with_Boat";

			Locations[FindLocation("Oxbay_port")].reload.l1.disable = 0; //added for rouge "gates locked" condition

			Pchar.quest.Looking_for_sisters.win_condition.l1 = "location";
			PChar.quest.Looking_for_sisters.win_condition.l1.character = Pchar.id;
			Pchar.quest.Looking_for_sisters.win_condition.l1.location = "QC_port";
			Pchar.quest.Looking_for_sisters.win_condition = "Looking_for_sisters";
// ABOVE JOINS BACK TO BRIN QUEST	^^^^^^^^^^
			Pchar.quest.Jack_Sparrow_Quest.win_condition.l1 = "location";
			PChar.quest.Jack_Sparrow_Quest.win_condition.l1.character = Pchar.id;
			Pchar.quest.Jack_Sparrow_Quest.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Jack_Sparrow_Quest.win_condition = "Jack_Sparrow_Quest";
// ABOVE JOINS ORIGINAL JACK SPARROW QUEST	^^^^^^^^^^
			AddQuestRecord("Mystery Woman",3);

			Pchar.quest.Reset_Prison_comm.win_condition.l1 = "location";
			PChar.quest.Reset_Prison_comm.win_condition.l1.character = Pchar.id;
			Pchar.quest.Reset_Prison_comm.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Reset_Prison_comm.win_condition = "Reset_Prison_comm";
		break;

		case "Reset_Prison_comm":
			ChangeCharacterAddressGroup(characterFromID("Greenford Prison Commendant"), "greenford_prison", "sit", "sit1");
			LAi_SetSitType(characterfromID("Greenford Prison Commendant"));
			Characters[GetCharacterIndex("Greenford Prison Commendant")].dialog.currentnode = "First time";
		break;

		case "Working_with_Susan":
			LAi_SetOfficerType(characterFromID("Susan Shaypen"));
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "First time";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }

			Pchar.quest.Working_with_Susan2.win_condition.l1 = "location";
			PChar.quest.Working_with_Susan2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Working_with_Susan2.win_condition.l1.location = "Tortuga_port";
			Pchar.quest.Working_with_Susan2.win_condition = "Working_with_Susan2";
			
			Pchar.quest.Wrong_harbour_with_Susan.win_condition.l1 = "location";
			PChar.quest.Wrong_harbour_with_Susan.win_condition.l1.character = Pchar.id;
			Pchar.quest.Wrong_harbour_with_Susan.win_condition.l1.location = "QC_port";
			Pchar.quest.Wrong_harbour_with_Susan.win_condition = "Wrong_harbour_with_Susan";
			AddQuestRecord("Mystery Woman",2);
		break;

		case "Wrong_harbour_with_Susan":
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Wrong_arrival_at_QC";
		break;

		case "Working_with_Susan2":
			Pchar.quest.Wrong_harbour_with_Susan.over = "yes";
			ChangeCharacterAddressGroup(CharacterFromID("Bootstrap Bill Turner"),"Tortuga_tavern", "goto", "goto7");
			pchar.quest.Jacks_early_days = "arrival_at_Tortuga";
            LAi_SetActorType(characterFromID("Susan Shaypen"));
            Lai_ActorFollow(characterFromID("Susan Shaypen"), pchar, "Working_with_Susan3", 0.0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 3000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 3000); }
		break;

		case "Working_with_Susan3":
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "arrival_at_Tortuga";
		break;

		case "Looking_for_Brinkley":
			LAi_SetOfficerType(characterFromID("Susan Shaypen"));
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "First time";
            DeleteAttribute(pchar,"A_Possible_Side_Track");
		break;

		case "Brinkley_left_Tortuga":
			Pchar.quest.On_the_trail.win_condition.l1 = "location";
			PChar.quest.On_the_trail.win_condition.l1.character = Pchar.id;
			Pchar.quest.On_the_trail.win_condition.l1.location = "Tortuga_port";
			Pchar.quest.On_the_trail.win_condition = "On_the_trail";
		break;

		case "On_the_trail":
			Pchar.quest.Looking_for_sisters.over = "yes";
			ChangeCharacterAddressGroup(CharacterFromID("Bootstrap Bill Turner"),"Tortuga_port", "goto", "goto16");
			pchar.quest.Jacks_early_days = "information_at_Tortuga";
            LAi_SetActorType(characterFromID("Susan Shaypen"));
            Lai_ActorFollow(characterFromID("Susan Shaypen"), pchar, "On_the_trail2", 0.0);
		break;

		case "On_the_trail2":
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "discussion_at_Tortuga";
		break;

		case "Meet_Bootstrap_Bill":
			LAi_SetOfficerType(characterFromID("Susan Shaypen"));
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "First time";
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			Lai_ActorFollow(characterFromID("Bootstrap Bill Turner"), pchar, "Meet_Bootstrap_Bill2", 0.0);
		break;

		case "Meet_Bootstrap_Bill2":
			characters[GetCharacterIndex("Bootstrap Bill Turner")].Dialog.Filename = "Bootstrap Bill Turner_dialog.c";
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			LAi_ActorDialog(characterFromID("Bootstrap Bill Turner"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Bootstrap Bill Turner")].dialog.currentnode = "First_Meeting_With_Bootstrap_Tortuga";
		break;

		case "Bootstrapjoinscrew":
			AddPassenger(Pchar, characterFromID("Bootstrap Bill Turner"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Bootstrap Bill Turner"));
			LAi_SetOfficerType(characterFromID("Bootstrap Bill Turner"));

			Pchar.quest.Look_for_sistersBBT.win_condition.l1 = "location";
			PChar.quest.Look_for_sistersBBT.win_condition.l1.character = Pchar.id;
			Pchar.quest.Look_for_sistersBBT.win_condition.l1.location = "QC_port";
			Pchar.quest.Look_for_sistersBBT.win_condition = "Look_for_sistersBBT";
		break;

		case "Look_for_sistersBBT":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			pchar.quest.Jacks_early_days = "xxx";
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			characters[GetCharacterIndex("Bootstrap Bill Turner")].Dialog.Filename = "Bootstrap Bill Turner_dialog.c";
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			LAi_ActorDialog(characterFromID("Bootstrap Bill Turner"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Bootstrap Bill Turner")].dialog.currentnode = "Split_up_for_now";
		break;

		case "Split_up_for_search":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Susan Shaypen"));
			RemovePassenger(pchar, characterFromID("Susan Shaypen"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bootstrap Bill Turner"));
			RemovePassenger(pchar, characterFromID("Bootstrap Bill Turner"));
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			LAi_ActorRunToLocator(characterFromID("Susan Shaypen"), "goto", "goto16", "", 10.0);
			LAi_ActorGoToLocator(characterFromID("Bootstrap Bill Turner"), "goto", "goto15", "Meet_up_againBBT", 10.0);
		break;

		case "Meet_up_againBBT":
			ChangeCharacterAddress(characterFromID("Susan Shaypen"), "None", "");
			ChangeCharacterAddress(characterFromID("Bootstrap Bill Turner"), "None", "");
			LAi_QuestDelay("BBT_in_Tavern", 1.0);
		break;

		case "BBT_in_Tavern":
			ChangeCharacterAddressGroup(CharacterFromID("Susan Shaypen"),"QC_Tavern", "goto", "goto4");
			ChangeCharacterAddressGroup(CharacterFromID("Bootstrap Bill Turner"),"QC_Tavern", "goto", "goto6");
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			characters[GetCharacterIndex("Bootstrap Bill Turner")].Dialog.Filename = "Bootstrap Bill Turner_dialog.c";
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			LAi_ActorDialog(characterFromID("Bootstrap Bill Turner"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Bootstrap Bill Turner")].dialog.currentnode = "The_diamond_trade";
		break;

		case "Look_for_Eastwood":
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Bootstrap Bill Turner"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Susan Shaypen"));
			ChangeCharacterAddressGroup(CharacterFromID("Annabella Brinkley"),"QC_Pirate_house_inside", "goto", "goto2");
			LAi_ActorAnimation(characterFromID("Annabella Brinkley"), "Lay_1", "", -1);

			ChangeCharacterAddressGroup(CharacterFromID("Clint Eastwood"),"QC_Pirate_house", "goto", "citizen02");	// GR: Just in case you already killed Clint before starting this quest
			LAi_SetCivilianPatrolType(CharacterFromID("Clint Eastwood"));

			Pchar.quest.Found_dead_body.win_condition.l1 = "location";
			PChar.quest.Found_dead_body.win_condition.l1.character = Pchar.id;
			Pchar.quest.Found_dead_body.win_condition.l1.location = "QC_Pirate_house_inside";
			Pchar.quest.Found_dead_body.win_condition = "Found_dead_body";

			DeleteAttribute(pchar, "quest.clint_eastwood"); // PB: Temporary disable Shotgun Easter Egg
		break;

		case "Found_dead_body":
			characters[GetCharacterIndex("Bootstrap Bill Turner")].Dialog.Filename = "Bootstrap Bill Turner_dialog.c";
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			LAi_ActorDialog(characterFromID("Bootstrap Bill Turner"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Bootstrap Bill Turner")].dialog.currentnode = "Looking_at_dead_body";
		break;

		case "Look_for_Eastwood_again":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Susan Shaypen"));
			RemovePassenger(pchar, characterFromID("Susan Shaypen"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bootstrap Bill Turner"));
			RemovePassenger(pchar, characterFromID("Bootstrap Bill Turner"));
			LAi_QuestDelay("Look_for_Eastwood_again2", 0.0);
		break;

		case "Look_for_Eastwood_again2":
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Bootstrap Bill Turner"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Susan Shaypen"));
			ChangeCharacterAddressGroup(CharacterFromID("Barbossa"),"QC_Pirate_house", "goto", "citizen01");
		break;

		case "Finished_with_Eastwood":
			LAi_SetActorType(characterFromID("Barbossa"));
			LAi_ActorGoToLocator(characterFromID("Barbossa"), "goto", "locator11", "", 5.0);
			characters[GetCharacterIndex("Bootstrap Bill Turner")].Dialog.Filename = "Bootstrap Bill Turner_dialog.c";
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			LAi_ActorDialog(characterFromID("Bootstrap Bill Turner"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Bootstrap Bill Turner")].dialog.currentnode = "Join_with_Barbossa";

		// PB: Shotgun Easter Egg -->
			Pchar.quest.Eastwood_Restore.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Eastwood_Restore.win_condition.l1.location = "QC_Pirate_house";
			Pchar.quest.Eastwood_Restore.win_condition = "Eastwood_Restore";
		break;

		case "Eastwood_Restore":
			PChar.quest.clint_eastwood.win_condition.l1 = "location";
			PChar.quest.clint_eastwood.win_condition.l1.location = "QC_Pirate_house";
			PChar.quest.clint_eastwood.win_condition = "clint_eastwood";
		break;
		// PB: Shotgun Easter Egg <--

		case "Bootstrap_leaves_ship":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bootstrap Bill Turner"));
			RemovePassenger(pchar, characterFromID("Bootstrap Bill Turner"));
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
			LAi_ActorGoToLocator(characterFromID("Bootstrap Bill Turner"), "goto", "locator11", "Go_and_find_Brock", 3.0);
		break;

		case "Go_and_find_Brock":
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "The_Brock_Saga";
		break;

		case "Continue_for_Brock":
			DisableFastTravel(false);
			LAi_SetOfficerType(characterFromID("Susan Shaypen"));
			Pchar.quest.sisters_and_Brock_search.win_condition.l1 = "location";
			PChar.quest.sisters_and_Brock_search.win_condition.l1.character = Pchar.id;
			Pchar.quest.sisters_and_Brock_search.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.sisters_and_Brock_search.win_condition = "sisters_and_Brock_search";
		break;

		case "sisters_and_Brock_search":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "The_Brock_hunt_Oxbay";
		break;

		case "Brock_found_in_Oxbay":
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorRunToLocation(characterFromID("Susan Shaypen"), "reload", "reload1", "none", "", "", "Brock_found_in_Oxbay2", 25.0);
		break;

		case "Brock_found_in_Oxbay2":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Susan Shaypen"));
			RemovePassenger(pchar, characterFromID("Susan Shaypen"));

			/*pchar.quest.The_sisters_found.win_condition.l1 = "locator";
			pchar.quest.The_sisters_found.win_condition.l1.location = "Oxbay_town";
			pchar.quest.The_sisters_found.win_condition.l1.locator_group = "reload";
			pchar.quest.The_sisters_found.win_condition.l1.locator = "reload4";
			pchar.quest.The_sisters_found.win_condition = "The_sisters_found";*/
			pchar.quest.The_sisters_found.win_condition.l1 = "location";
			pchar.quest.The_sisters_found.win_condition.l1.location = "Mings_townhall";
			pchar.quest.The_sisters_found.win_condition = "The_sisters_found";

			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 0;

			Pchar.quest.Barbossa_and_Brock_search.win_condition.l1 = "location";
			PChar.quest.Barbossa_and_Brock_search.win_condition.l1.character = Pchar.id;
			Pchar.quest.Barbossa_and_Brock_search.win_condition.l1.location = "Oxbay_shipyard";
			Pchar.quest.Barbossa_and_Brock_search.win_condition = "Barbossa_and_Brock_search";
		break;

		case "Barbossa_and_Brock_search":
			Pchar.quest.The_sisters_found.over = "yes";
			ChangeCharacterAddressGroup(CharacterFromID("Susan Shaypen"),"Oxbay_shipyard", "goto", "goto2");
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Dead_end_Quest_Oxbay";
		break;

		case "Dead_end_Quest_Oxbay_onward": // now the long way round but gets player back to quest
			AddPassenger(Pchar, characterFromID("Susan Shaypen"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Susan Shaypen"));
			LAi_SetOfficerType(characterFromID("Susan Shaypen"));

			pchar.quest.Turks_with_Shaypen.win_condition.l1 = "location";
			pchar.quest.Turks_with_Shaypen.win_condition.l1.location = "Turks_port";
			pchar.quest.Turks_with_Shaypen.win_condition = "Turks_with_Shaypen";
		break;

		case "Turks_with_Shaypen":
			pchar.quest.Find_out_the_Error.win_condition.l1 = "location";
			pchar.quest.Find_out_the_Error.win_condition.l1.location = "Turks_Tavern";
			pchar.quest.Find_out_the_Error.win_condition = "Find_out_the_Error";

			ChangeCharacterAddressGroup(CharacterFromID("Thomas Tipman"), "Turks_Tavern", "reload", "reload3");
			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "First time Turks";
		break;

		case "Find_out_the_Error":
			characters[GetCharacterIndex("Thomas Tipman")].Dialog.Filename = "Thomas Tipman_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("Thomas Tipman"));
			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "First time Turks";
		break;

		case "Do_Brock_search_again":
			Pchar.quest.Brock_search_again_myself.win_condition.l1 = "location";
			PChar.quest.Brock_search_again_myself.win_condition.l1.character = Pchar.id;
			Pchar.quest.Brock_search_again_myself.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.Brock_search_again_myself.win_condition = "Brock_search_again_myself";
		break;

		case "Brock_search_again_myself":
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "The_Brock_hunt_Oxbay";
			pchar.brock_hunt = "1";

			pchar.quest.The_sisters_found2.win_condition.l1 = "location";
			pchar.quest.The_sisters_found2.win_condition.l1.location = "Mings_townhall";
			pchar.quest.The_sisters_found2.win_condition = "The_sisters_found";
		break;

// Brotherhood Quest Begins
		case "The_Brotherhood_begins":
			CloseQuestHeader("My Early Days");
			ChangeCharacterAddress(characterfromID("Billy Brock"),"none", "");
			//ChangeCharacterAddress(characterFromID("Jacinto Arcibaldo Barreto"), "None", "");
			//ChangeCharacterAddressGroup(characterFromID("Sir Christopher Mings"), "Conceicao_townhall", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Sir Christopher Mings"), "Mings_townhall", "sit", "sit1");
			LAi_SetSitType(characterfromID("Sir Christopher Mings"));
			pchar.quest.Jacks_early_days = "Mings_upstairs_meeting";
			//DoQuestReloadToLocation("Conceicao_townhall", "Reload", "Reload1", "The_Brotherhood_begins2");
			LAi_QuestDelay("The_Brotherhood_begins2", 0.0);
			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 1;
		break;

		case "The_Brotherhood_begins2":
			ChangeCharacterReputation(pchar, +2);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
		break;

		case "Beckett_for_Mings":
			//DoQuestReloadToLocation("Oxbay_town", "reload", "Reload4", "_");

			Pchar.quest.Beckett_run_for_Mings.win_condition.l1 = "location";
			PChar.quest.Beckett_run_for_Mings.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_run_for_Mings.win_condition.l1.location = "Oxbay_tavern";
			Pchar.quest.Beckett_run_for_Mings.win_condition = "Beckett_run_for_Mings";
		break;

		case "Beckett_run_for_Mings":
			Locations[FindLocation("Oxbay_tavern")].reload.l1.disable = 1;
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"), "Oxbay_tavern", "goto", "goto21");
			characters[GetCharacterIndex("Cutler Beckett")].Dialog.Filename = "Cutler Beckett_dialog.c";
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorDialog(characterFromID("Cutler Beckett"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "Oxbay_meet_after_Mings";
		break;

		case "First_run_Jamaica_with_Beckett":
		//	LAi_ActorGoToLocator(characterFromID("Cutler Beckett"), "reload", "reload1", "First_run_Jamaica_with_Beckett2", 10.0);
			LAi_ActorGoToLocation(characterFromID("Cutler Beckett"), "reload", "reload1", "none", "", "", "First_run_Jamaica_with_Beckett2", 10.0); // CTM
		break;

		case "First_run_Jamaica_with_Beckett2":
			//pchar.quest.Jacks_early_days = "Jacks_first_run_Beckett";
			ChangeCharacterAddress(characterFromID("Cutler Beckett"), "None", "");
			LAi_QuestDelay("Beckett_escort_to_Redmond", 0.0);
		break;

		case "Beckett_escort_to_Redmond":
			Locations[FindLocation("Oxbay_tavern")].reload.l1.disable = false;

			Pchar.quest.Beckett_escort_complete.win_condition.l1 = "ExitFromLocation";
			PChar.quest.Beckett_escort_complete.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_escort_complete.win_condition.l1.location = "Redmond";
			Pchar.quest.Beckett_escort_complete.win_condition = "Beckett_escort_complete";

			Pchar.quest.Beckett_run_for_Mings2.win_condition.l1 = "location";
			PChar.quest.Beckett_run_for_Mings2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_run_for_Mings2.win_condition.l1.location = "Redmond_port";
			Pchar.quest.Beckett_run_for_Mings2.win_condition = "Beckett_run_for_Mings2";
		break;

		case "Beckett_escort_complete":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }

//			RemoveCharacterCompanion(pchar, characterFromID("Cutler Beckett")); //TALISMAN - to have Becketts ship sail with you to P Royale when escort
			SetCharacterShipLocation(characterFromID("Cutler Beckett"), "Redmond_Port");
			//LAi_SetOfficerType(characterFromID("Cutler Beckett"));
			//LAi_QuestDelay("Beckett_run_for_Mings2", 0.2);
		break;

		case "Beckett_run_for_Mings2":
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"), "Redmond_port", "goto", "goto_45");
			characters[GetCharacterIndex("Cutler Beckett")].Dialog.Filename = "Cutler Beckett_dialog.c";
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorDialog(characterFromID("Cutler Beckett"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "Redmond_meet_after_Mings";
		break;

		case "arrived_base_story":
			AddQuestRecord("Beckett",4);
			LAi_QuestDelay("Beckett_to_make_payment2", 0.0);
		break;

		case "Beckett_to_make_payment":
			AddQuestRecord("Beckett",7);
			LAi_ActorGoToLocator(characterFromID("Cutler Beckett"), "goto", "goto_45", "Beckett_to_make_payment2", 10.0);
		break;

		case "Beckett_to_make_payment2":
			ChangeCharacterAddress(characterFromID("Cutler Beckett"), "None", "");

			Pchar.quest.Find_the_EITC_office.win_condition.l1 = "location";
			PChar.quest.Find_the_EITC_office.win_condition.l1.character = Pchar.id;
			Pchar.quest.Find_the_EITC_office.win_condition.l1.location = "Redmond_town_01";
			Pchar.quest.Find_the_EITC_office.win_condition = "Find_the_EITC_office";
		break;

		case "Find_the_EITC_office":
			ChangeCharacterAddressGroup(characterfromID("Thomas Tipman"), "Redmond_tavern", "goto", "goto7");
			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "first time Redmond";

			Pchar.quest.Beckett_back_in_EITC_office.win_condition.l1 = "location";
			PChar.quest.Beckett_back_in_EITC_office.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_back_in_EITC_office.win_condition.l1.location = "Redmond_tavern";
			Pchar.quest.Beckett_back_in_EITC_office.win_condition = "Beckett_back_in_EITC_office";

			/*pchar.quest.Beckett_to_make_payment3.win_condition.l1 = "locator";
			pchar.quest.Beckett_to_make_payment3.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.Beckett_to_make_payment3.win_condition.l1.locator_group = "reload";
			pchar.quest.Beckett_to_make_payment3.win_condition.l1.locator = "Door_2";
			pchar.quest.Beckett_to_make_payment3.win_condition = "Beckett_to_make_payment3";*/
			pchar.quest.Beckett_to_make_payment3.win_condition.l1 = "location";
			pchar.quest.Beckett_to_make_payment3.win_condition.l1.location = "EITC_Office";
			pchar.quest.Beckett_to_make_payment3.win_condition = "Beckett_to_make_payment3";
			Locations[FindLocation("Redmond_Town_01")].reload.l17.disable = 0;
		break;

		case "Beckett_to_make_payment3":
			Pchar.Quest.Beckett_back_in_EITC_office.over = "yes";
			//Locations[FindLocation("Muelle04_HouseInsideR6")].vcskip = true;
			//Locations[FindLocation("EITC_Office")].vcskip = true;
			//ChangeCharacterAddressGroup(characterfromID("Silas Simpkins"), "Muelle04_HouseInsideR6", "sit", "sit1");
			ChangeCharacterAddressGroup(characterfromID("Silas Simpkins"), "EITC_Office", "sit", "sit1");
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			//ChangeCharacterAddressGroup(characterfromID("Stephen Walsh"), "Muelle04_HouseInsideR6", "goto", "goto7");
			//ChangeCharacterAddressGroup(characterfromID("Arthur Straightly"), "Muelle04_HouseInsideR6", "goto", "goto6");
			//ChangeCharacterAddressGroup(characterfromID("William Wanderman"), "Muelle04_HouseInsideR6", "goto", "goto5");
			ChangeCharacterAddressGroup(characterfromID("Stephen Walsh"), "EITC_Office", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Arthur Straightly"), "EITC_Office", "goto", "goto6");
			ChangeCharacterAddressGroup(characterfromID("William Wanderman"), "EITC_Office", "goto", "goto5");
			ChangeCharacterAddress(characterFromID("Thomas Tipman"), "None", "");
			//DoQuestReloadToLocation("Muelle04_HouseInsideR6", "Reload", "Reload1", "First talk with Silas");
			LAi_QuestDelay("First talk with Silas", 0.0);
		break;

		case "First talk with Silas":
			DisableFastTravel(true);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "desk", "into_position_EITC", 10);
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "First time Redmond";
		break;

		case "into_position_EITC":
			LAi_SetPlayerType(pchar);

			LAi_SetActorType(characterFromID("Silas Simpkins")); // sjg
			LAi_ActorSetSitMode(characterFromID("Silas Simpkins")); // sjg
			LAi_ActorDialog(characterfromID("Silas Simpkins"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "First time Redmond";
		break;

		case "Go_out_before_fight":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "reload", "reload1", "Have_to_get_out", 1);
		break;

		case "Have_to_get_out":
			LAi_SetPlayerType(pchar);
			Locations[FindLocation("Redmond_Town_01")].reload.l17.disable = 1;
			//DoQuestReloadToLocation("Redmond_town_01", "officers", "Door_2_3", "Have_to_wait_for_Beckett2");
			LAi_QuestDelay("Have_to_wait_for_Beckett", 0.0);
		break;

		case "Have_to_wait_for_Beckett":
			LAi_SetPlayerType(pchar);

			/*pchar.quest.Have_to_wait_for_Beckett2.win_condition.l1 = "locator";
			pchar.quest.Have_to_wait_for_Beckett2.win_condition.l1.location = "Muelle04_HouseInsideR6";
			pchar.quest.Have_to_wait_for_Beckett2.win_condition.l1.locator_group = "reload";
			pchar.quest.Have_to_wait_for_Beckett2.win_condition.l1.locator = "reload1";
			pchar.quest.Have_to_wait_for_Beckett2.win_condition = "Have_to_wait_for_Beckett2";*/
			pchar.quest.Have_to_wait_for_Beckett2.win_condition.l1 = "location";
			pchar.quest.Have_to_wait_for_Beckett2.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.Have_to_wait_for_Beckett2.win_condition = "Have_to_wait_for_Beckett2";

			Locations[FindLocation("Redmond_Town_01")].reload.l17.disable = 1;

			pchar.quest.Fight_in_EITC_Office.win_condition.l1 = "locator";
			pchar.quest.Fight_in_EITC_Office.win_condition.l1.location = "EITC_Office";
			pchar.quest.Fight_in_EITC_Office.win_condition.l1.locator_group = "goto";
			pchar.quest.Fight_in_EITC_Office.win_condition.l1.locator = "goto8";
			pchar.quest.Fight_in_EITC_Office.win_condition = "Fight_in_EITC_Office";
		break;

		case "Have_to_wait_for_Beckett2":
			Pchar.Quest.Fight_in_EITC_office.over = "yes";
			DisableFastTravel(false);

			//DoQuestReloadToLocation("Redmond_town_01", "officers", "Door_2_3", "_");

			Pchar.quest.Beckett_back_in_EITC_office.win_condition.l1 = "location";
			PChar.quest.Beckett_back_in_EITC_office.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_back_in_EITC_office.win_condition.l1.location = "Redmond_tavern";
			Pchar.quest.Beckett_back_in_EITC_office.win_condition = "Beckett_back_in_EITC_office";
		break;

		case "Beckett_back_in_EITC_office":
			Pchar.Quest.Beckett_to_make_payment3.over = "yes";

			ChangeCharacterAddressGroup(characterfromID("Thomas Tipman"), "Redmond_tavern", "goto", "goto7");

			DisableFastTravel(true);
			Locations[FindLocation("Redmond_tavern")].reload.l1.disable = 1;

			characters[GetCharacterIndex("Thomas Tipman")].Dialog.Filename = "Thomas Tipman_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("Thomas Tipman"));
			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "First time Redmond";
		break;

		case "Beckett_back_in_EITC_office2":
			DisableFastTravel(false);
			Locations[FindLocation("Redmond_tavern")].reload.l1.disable = 0;

			Pchar.quest.Beckett_back_in_EITC_office3.win_condition.l1 = "location";
			PChar.quest.Beckett_back_in_EITC_office3.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_back_in_EITC_office3.win_condition.l1.location = "Redmond_town_01";
			Pchar.quest.Beckett_back_in_EITC_office3.win_condition = "Beckett_back_in_EITC_office3";
		break;

		case "Beckett_back_in_EITC_office3":
			ChangeCharacterAddress(characterFromID("Thomas Tipman"), "None", "");

			/*pchar.quest.Beckett_pays_up.win_condition.l1 = "locator";
			pchar.quest.Beckett_pays_up.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.Beckett_pays_up.win_condition.l1.locator_group = "reload";
			pchar.quest.Beckett_pays_up.win_condition.l1.locator = "Door_2";
			pchar.quest.Beckett_pays_up.win_condition = "Beckett_pays_up";*/
			pchar.quest.Beckett_pays_up.win_condition.l1 = "location";
			pchar.quest.Beckett_pays_up.win_condition.l1.location = "EITC_Office";
			pchar.quest.Beckett_pays_up.win_condition = "Beckett_pays_up";

			Locations[FindLocation("Redmond_Town_01")].reload.l17.disable = 0;
		break;

		case "Beckett_pays_up":
			Pchar.Quest.Beckett_back_in_EITC_office.over = "yes";
			//Locations[FindLocation("Muelle04_HouseInsideR6")].vcskip = true;
			//Locations[FindLocation("Muelle04_HouseInsideR6")].vcskip = true;
			//ChangeCharacterAddressGroup(characterfromID("Silas Simpkins"), "Muelle04_HouseInsideR6", "sit", "sit1");
			ChangeCharacterAddressGroup(characterfromID("Silas Simpkins"), "EITC_Office", "sit", "sit1");
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			//ChangeCharacterAddressGroup(characterfromID("Stephen Walsh"), "Muelle04_HouseInsideR6", "goto", "goto7");
			//ChangeCharacterAddressGroup(characterfromID("Arthur Straightly"), "Muelle04_HouseInsideR6", "goto", "goto6");
			ChangeCharacterAddressGroup(characterfromID("Stephen Walsh"), "EITC_Office", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Arthur Straightly"), "EITC_Office", "goto", "goto6");
			ChangeCharacterAddress(characterFromID("William Wanderman"), "None", "");
			//ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"), "Muelle04_HouseInsideR6", "sit", "sit2");
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"), "EITC_Office", "sit", "sit2");
			LAi_SetSitType(characterfromID("Cutler Beckett"));
			//DoQuestReloadToLocation("Muelle04_HouseInsideR6", "Reload", "Reload1", "Beckett_pays_up2");
			LAi_QuestDelay("Beckett_pays_up2", 0.0);
		break;

		case "Beckett_pays_up2":
			DisableFastTravel(true);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "desk", "Beckett_pays_up3", 10);
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "Beckett in office";
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "First time";
		break;

		case "Beckett_pays_up3":
			LAi_SetPlayerType(pchar);

			LAi_SetActorType(characterFromID("Silas Simpkins"));
			LAi_ActorSetSitMode(characterFromID("Silas Simpkins"));
			LAi_ActorDialog(characterfromID("Silas Simpkins"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "Beckett in office";
		break;

		case "An_offer_from_Beckett":
			pchar.quest.Beckett = "Payment_for_Escort";
			LAi_SetSitType(characterfromID("Silas Simpkins"));
		break;

		case "Doing_the_First_Mission":
			/*pchar.quest.Doing_the_First_Mission2.win_condition.l1 = "locator";
			pchar.quest.Doing_the_First_Mission2.win_condition.l1.location = "Muelle04_HouseInsideR6";
			pchar.quest.Doing_the_First_Mission2.win_condition.l1.locator_group = "reload";
			pchar.quest.Doing_the_First_Mission2.win_condition.l1.locator = "reload1";
			pchar.quest.Doing_the_First_Mission2.win_condition = "Doing_the_First_Mission2";*/
			pchar.quest.Doing_the_First_Mission2.win_condition.l1 = "location";
			pchar.quest.Doing_the_First_Mission2.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.Doing_the_First_Mission2.win_condition = "Doing_the_First_Mission2";

			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "On_your_way"; // PB

			Locations[FindLocation("Redmond_Town_01")].reload.l17.disable = 1;
		break;

		case "Doing_the_First_Mission2":
			//DoQuestReloadToLocation("Redmond_town_01", "officers", "Door_2_3", "_");
			DisableFastTravel(false);

			Pchar.quest.Beckett_First_Mission_complete.win_condition.l1 = "ExitFromLocation";
			PChar.quest.Beckett_First_Mission_complete.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_First_Mission_complete.win_condition.l1.location = "Redmond_town_01";
			Pchar.quest.Beckett_First_Mission_complete.win_condition = "Beckett_First_Mission_complete";
		break;

		case "On_my_own_no_EITC":
			/*pchar.quest.On_my_own_no_EITC2.win_condition.l1 = "locator";
			pchar.quest.On_my_own_no_EITC2.win_condition.l1.location = "Muelle04_HouseInsideR6";
			pchar.quest.On_my_own_no_EITC2.win_condition.l1.locator_group = "reload";
			pchar.quest.On_my_own_no_EITC2.win_condition.l1.locator = "reload1";
			pchar.quest.On_my_own_no_EITC2.win_condition = "On_my_own_no_EITC2";*/
			pchar.quest.On_my_own_no_EITC2.win_condition.l1 = "location";
			pchar.quest.On_my_own_no_EITC2.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.On_my_own_no_EITC2.win_condition = "On_my_own_no_EITC2";
		break;

		case "On_my_own_no_EITC2":
			//DoQuestReloadToLocation("Redmond_town_01", "officers", "Door_2_3", "_");
			DisableFastTravel(false);
		break;

		case "Beckett_First_Mission_complete":
			Pchar.quest.Beckett_mission_reckoning.win_condition.l1 = "location";
			PChar.quest.Beckett_mission_reckoning.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_mission_reckoning.win_condition.l1.location = "Redmond_town_01";
			Pchar.quest.Beckett_mission_reckoning.win_condition = "Beckett_mission_reckoning";
		break;

		case "Beckett_mission_reckoning":
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "First time"; // PB
			pchar.quest.Beckett = "First_mission_reckoning";

			/*pchar.quest.First_mission_reckoning.win_condition.l1 = "locator";
			pchar.quest.First_mission_reckoning.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.First_mission_reckoning.win_condition.l1.locator_group = "reload";
			pchar.quest.First_mission_reckoning.win_condition.l1.locator = "Door_2";
			pchar.quest.First_mission_reckoning.win_condition = "First_mission_reckoning";*/
			pchar.quest.First_mission_reckoning.win_condition.l1 = "location";
			pchar.quest.First_mission_reckoning.win_condition.l1.location = "EITC_Office";
			pchar.quest.First_mission_reckoning.win_condition = "First_mission_reckoning";

			Locations[FindLocation("Redmond_Town_01")].reload.l17.disable = 0;
		break;

		case "First_mission_reckoning":
			/*Locations[FindLocation("Muelle04_HouseInsideR6")].vcskip = true;
			ChangeCharacterAddressGroup(characterfromID("Silas Simpkins"), "Muelle04_HouseInsideR6", "sit", "sit1");
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"), "Muelle04_HouseInsideR6", "sit", "sit2");
			ChangeCharacterAddressGroup(characterfromID("Stephen Walsh"), "Muelle04_HouseInsideR6", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Arthur Straightly"), "Muelle04_HouseInsideR6", "goto", "goto6");
			ChangeCharacterAddress(characterFromID("William Wanderman"), "None", "");
			LAi_SetSitType(characterfromID("Cutler Beckett"));
			DoQuestReloadToLocation("Muelle04_HouseInsideR6", "Reload", "Reload1", "First_mission_reckoning2");*/
			ChangeCharacterAddressGroup(characterfromID("Silas Simpkins"), "EITC_Office", "sit", "sit1");
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"), "EITC_Office", "sit", "sit2");
			ChangeCharacterAddressGroup(characterfromID("Stephen Walsh"), "EITC_Office", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Arthur Straightly"), "EITC_Office", "goto", "goto6");
			ChangeCharacterAddress(characterFromID("William Wanderman"), "None", "");
			LAi_SetSitType(characterfromID("Cutler Beckett"));
			LAi_QuestDelay("First_mission_reckoning2", 0.0);
		break;

		case "First_mission_reckoning2":
			DisableFastTravel(true);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "desk", "First_mission_reckoning3", 10);
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "In for the reckoning";
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "First time";
		break;

		case "First_mission_reckoning3":
			LAi_SetPlayerType(pchar);

			LAi_SetActorType(characterFromID("Silas Simpkins"));
			LAi_ActorSetSitMode(characterFromID("Silas Simpkins"));
			LAi_ActorDialog(characterfromID("Silas Simpkins"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "In for the reckoning";
		break;

		case "First_mission_reckoning4":
			pchar.quest.Beckett = "First_mission_reckoning";
		break;

		case "Fight_in_EITC_Office":
			Pchar.Quest.Have_to_wait_for_Beckett2.over = "yes";
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "Silas warns of fight";
			LAi_QuestDelay("Fight_in_EITC_Office2", 0.0);
		break;

		case "Fight_in_EITC_Office2":
			characters[GetCharacterIndex("Silas Simpkins")].Dialog.Filename = "Silas Simpkins_dialog.c";
			LAi_SetActorType(characterFromID("Silas Simpkins"));
			LAi_ActorDialogNow(characterFromID("Silas Simpkins"),PChar,"",1.0);
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "Silas warns of fight";
			LAi_SetActorType(characterFromID("Arthur Straightly"));
			LAi_SetActorType(characterFromID("Stephen Walsh"));
			LAi_SetActorType(characterFromID("William Wanderman"));

			LAi_SetImmortal(characterFromID("Arthur Straightly"), true);
			LAi_SetImmortal(characterFromID("Stephen Walsh"), true);
		break;

		case "Fight_in_EITC_Office3":
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(Pchar, true);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_ActorAttack(characterfromID("Arthur Straightly"), pchar, "");
			LAi_ActorAttack(characterfromID("Stephen Walsh"), pchar, "");
			LAi_QuestDelay("Fight_in_EITC_Office4", 10.0);
		break;

		case "Fight_in_EITC_Office4":
			LAi_SetImmortal(Pchar, false);

			PChar.quest.KilledFightingEITC.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFightingEITC.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFightingEITC.win_condition = "KilledFightingEITC";
		break;

		case "KilledFightingEITC":
			pchar.quest.disable_rebirth = true
			PostEvent("LAi_event_GameOver", 0, "s", "land");
		break;

		case "Failed_the_Mission":
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "On_your_way"; // PB
			AddQuestRecord("Beckett",9);
			DisableFastTravel(false);
			//DoQuestReloadToLocation("Redmond_town_01", "officers", "Door_2_3", "_");
		break;

		case "prepare_for_Antigua_run":
			/*pchar.quest.prepare_for_Antigua_run2.win_condition.l1 = "locator";
			pchar.quest.prepare_for_Antigua_run2.win_condition.l1.location = "Muelle04_HouseInsideR6";
			pchar.quest.prepare_for_Antigua_run2.win_condition.l1.locator_group = "reload";
			pchar.quest.prepare_for_Antigua_run2.win_condition.l1.locator = "reload1";
			pchar.quest.prepare_for_Antigua_run2.win_condition = "prepare_for_Antigua_run2";*/
			pchar.quest.prepare_for_Antigua_run2.win_condition.l1 = "location";
			pchar.quest.prepare_for_Antigua_run2.win_condition.l1.location = "Redmond_Town_01";
			pchar.quest.prepare_for_Antigua_run2.win_condition = "prepare_for_Antigua_run2";

			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "On_your_way"; // CTM

			Locations[FindLocation("Redmond_Town_01")].reload.l17.disable = 1;
		break;

		case "prepare_for_Antigua_run2":
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "First time"; // CTM
			GiveModel2Player("47_Sparrow_Eitc_lt", true);
			PChar.Flags.Personal = 3; // PB: EITC Flag
			PChar.Flags.Personal.texture = 3;
			AddQuestRecord("Beckett",11);
			DisableFastTravel(false);
			SetShipRemovable(pchar, true);
			if (!HasThisShip("Black Pearl"))
			{
				GiveShip2Character(pchar,"WickedWench","Wicked Wench",-1,ENGLAND,true,true);
				PChar.quest.wench_given_by = "Beckett";
				SetCharacterShipLocation(Pchar, "Redmond_Port");
			}
			//DoQuestReloadToLocation("Redmond_town_01", "officers", "Door_2_3", "Save_the_Slaves2");
			LAi_QuestDelay("Save_the_slaves2", 0.0);
		break;

		case "Doing_the_Rescue_Mission":
			/*pchar.quest.prepare_for_Rescue_Mission.win_condition.l1 = "locator";
			pchar.quest.prepare_for_Rescue_Mission.win_condition.l1.location = "Muelle04_HouseInsideR6";
			pchar.quest.prepare_for_Rescue_Mission.win_condition.l1.locator_group = "reload";
			pchar.quest.prepare_for_Rescue_Mission.win_condition.l1.locator = "reload1";
			pchar.quest.prepare_for_Rescue_Mission.win_condition = "prepare_for_Rescue_Mission";*/
			pchar.quest.EITC_Rescue_Mission.win_condition.l1 = "location";
			pchar.quest.EITC_Rescue_Mission.win_condition.l1.location = "Redmond_Town_01";
			pchar.quest.EITC_Rescue_Mission.win_condition = "EITC_Rescue_Mission";

			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "On_your_way"; // CTM

			Locations[FindLocation("Redmond_Town_01")].reload.l17.disable = 1;
		break;

		case "prepare_for_Rescue_Mission":
			DisableFastTravel(false);
			DoQuestReloadToLocation("Redmond_town_01", "officers", "Door_2_3", "EITC_Rescue_Mission");
		break;

		case "EITC_Rescue_Mission":
			DisableFastTravel(false);
			Pchar.quest.Look_for_Tipman.win_condition.l1 = "location";
			PChar.quest.Look_for_Tipman.win_condition.l1.character = Pchar.id;
			Pchar.quest.Look_for_Tipman.win_condition.l1.location = "Redmond_tavern";
			Pchar.quest.Look_for_tipman.win_condition = "Look_for_Tipman";
		break;

		case "Look_for_Tipman":
			ChangeCharacterAddressGroup(characterfromID("Thomas Tipman"), "Redmond_tavern", "goto", "goto7");

			characters[GetCharacterIndex("Thomas Tipman")].Dialog.Filename = "Thomas Tipman_dialog.c";
			LAi_SetCitizenType(characterFromID("Thomas Tipman"));
			LAi_ActorDialog(characterFromID("Thomas Tipman"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "Join_for_Isla_Muelle";
		break;

		case "Now_go_to_Isla_Muelle":
			LAi_Fade("Now_go_to_Isla_Muelle2","");
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Thomas Tipman"));
		break;

		case "Now_go_to_Isla_Muelle2":
			GiveModel2Player("depp", true);

			Pchar.quest.Arrived_at_Isla_Muelle.win_condition.l1 = "location";
			PChar.quest.Arrived_at_Isla_Muelle.win_condition.l1.character = Pchar.id;
			Pchar.quest.Arrived_at_Isla_Muelle.win_condition.l1.location = "Muelle_port";
			Pchar.quest.Arrived_at_Isla_Muelle.win_condition = "Arrived_at_Isla_Muelle";
		break;

		case "Arrived_at_Isla_Muelle":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "Arrived_Isla Muelle";
			LAi_QuestDelay("Arrived_at_Isla_Muelle2", 0.0);
		break;

		case "Arrived_at_Isla_Muelle2":
			characters[GetCharacterIndex("Thomas Tipman")].Dialog.Filename = "Thomas Tipman_dialog.c";
			LAi_SetActorType(characterFromID("Thomas Tipman"));
			LAi_ActorDialogNow(characterFromID("Thomas Tipman"),PChar,"",1.0);
			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "Arrived_Isla Muelle";
		break;

		case "Search_in_Muelle":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Thomas Tipman"));
			ChangeCharacterAddressGroup(CharacterFromID("Thomas the Terror"),"Muelle_Town_01", "goto", "goto1");

			characters[GetCharacterIndex("Thomas the Terror")].Dialog.Filename = "Thomas the Terror_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("Thomas the Terror"));
			Characters[GetCharacterIndex("Thomas the Terror")].dialog.currentnode = "Muelle_meet_Thomas_the_Terror";
		break;

		case "Ransom_for_Prisoner":
			LAi_SetActorType(characterFromID("Thomas the Terror"));
			LAi_ActorGoToLocator(characterFromID("Thomas the Terror"), "reload", "reload1", "", 10.0);

			LAi_QuestDelay("Muelle_plan_of_action", 5.0);
		break;

		case "Muelle_plan_of_action": // TRAP QUEST
			ChangeCharacterAddress(characterfromID("Thomas the Terror"),"none", "");
			ChangeCharacterAddressGroup(characterfromID("IslaMuelle Commander"), "Muelle_Residence", "goto", "goto3");
			GiveItem2Character(CharacterFromId("IslaMuelle Commander"), "blade4");
			equipCharacterByItem(CharacterFromId("IslaMuelle Commander"), "blade4");

			Pchar.quest.Muelle_plan_of_action2.win_condition.l1 = "location";
			PChar.quest.Muelle_plan_of_action2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Muelle_plan_of_action2.win_condition.l1.location = "Muelle_Residence";
			Pchar.quest.Muelle_plan_of_action2.win_condition = "Muelle_plan_of_action2";
		break;

		case "Muelle_plan_of_action2":
			characters[GetCharacterIndex("IslaMuelle Commander")].Dialog.Filename = "Port Guard_dialog.c";
			LAi_SetActorType(characterFromID("IslaMuelle Commander"));
			LAi_ActorDialog(characterFromID("IslaMuelle Commander"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("IslaMuelle Commander")].dialog.currentnode = "Kill_the_EITC_Sparrow";
		break;

		case "Muelle_plan_of_action3": // Player dead - GAME OVER
			LAi_SetImmortal(CharacterFromID("IslaMuelle Commander"), true);
			LAi_SetImmortal(pchar, false);

			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);

			LAi_ActorAttack(characterfromID("IslaMuelle Commander"), pchar, "");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Search_with_Thomas_for_Prisoner":
			LAi_SetActorType(characterFromID("Thomas the Terror"));
			LAi_ActorGoToLocator(characterFromID("Thomas the Terror"), "reload", "reload1", "", 10.0);
			LAi_QuestDelay("Search_with_Thomas_for_Prisoner2", 5.0);
		break;

		case "Search_with_Thomas_for_Prisoner2":
			ChangeCharacterAddress(characterfromID("Thomas the Terror"),"none", "");

			Pchar.quest.with_Thomas_for_Prisoner.win_condition.l1 = "location";
			PChar.quest.with_Thomas_for_Prisoner.win_condition.l1.character = Pchar.id;
			Pchar.quest.with_Thomas_for_Prisoner.win_condition.l1.location = "Muelle_town_03";
			Pchar.quest.with_Thomas_for_Prisoner.win_condition = "with_Thomas_for_Prisoner";
		break;

		case "with_Thomas_for_Prisoner":
			ChangeCharacterAddressGroup(characterfromID("William Wanderman"), "Muelle_shore", "goto", "goto10");
			ChangeCharacterAddressGroup(CharacterFromID("Thomas the Terror"),"Muelle_Town_03", "goto", "character1");
			LAi_SetImmortal(CharacterFromID("Thomas the Terror"), true);
//			LAi_SetImmortal(pchar, true);
			characters[GetCharacterIndex("Thomas the Terror")].Dialog.Filename = "Thomas the Terror_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("Thomas the Terror"));
			Characters[GetCharacterIndex("Thomas the Terror")].dialog.currentnode = "Muelle_begin_search";
		break;

		case "Search_with_Thomas_in_jungle":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Thomas the Terror"));
			LAi_SetOfficerType(characterFromID("Thomas the Terror"));

			characters[GetCharacterIndex("William Wanderman")].Dialog.Filename = "William Wanderman_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("William Wanderman"));
			Characters[GetCharacterIndex("William Wanderman")].dialog.currentnode = "Rescue_at_Muelle";
		break;

		case "Go_back_for_ship":
			characters[GetCharacterIndex("Thomas the Terror")].Dialog.Filename = "Thomas the Terror_dialog.c";
			LAi_SetActorType(characterFromID("Thomas the Terror"));
			LAi_ActorDialog(characterFromID("Thomas the Terror"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Thomas the Terror")].dialog.currentnode = "Muelle_back_for_ship";
		break;

		case "Return_Muelle_for_ship":
			LAi_SetOfficerType(characterFromID("Thomas the Terror"));

			Pchar.quest.Returned_to_Isla_Muelle.win_condition.l1 = "location";
			PChar.quest.Returned_to_Isla_Muelle.win_condition.l1.character = Pchar.id;
			Pchar.quest.Returned_to_Isla_Muelle.win_condition.l1.location = "Muelle_port";
			Pchar.quest.Returned_to_Isla_Muelle.win_condition = "Returned_to_Isla_Muelle";
		break;

		case "Returned_to_Isla_Muelle":
			characters[GetCharacterIndex("Thomas the Terror")].Dialog.Filename = "Thomas the Terror_dialog.c";
			LAi_SetActorType(characterFromID("Thomas the Terror"));
			LAi_ActorDialog(characterFromID("Thomas the Terror"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Thomas the Terror")].dialog.currentnode = "Oyster_Bay_for_officer";
		break;

		case "Collect_the_officer":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Thomas the Terror"));
			RemovePassenger(pchar, characterFromID("Thomas the Terror"));

			Pchar.quest.Rescued_Isla_Muelle.win_condition.l1 = "location";
			PChar.quest.Rescued_Isla_Muelle.win_condition.l1.character = Pchar.id;
			Pchar.quest.Rescued_Isla_Muelle.win_condition.l1.location = "Muelle_shore";
			Pchar.quest.Rescued_Isla_Muelle.win_condition = "Rescued_Isla_Muelle";
		break;

		case "Rescued_Isla_Muelle":
			ChangeCharacterAddress(characterfromID("Thomas the Terror"),"none", "");

			characters[GetCharacterIndex("William Wanderman")].Dialog.Filename = "William Wanderman_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("William Wanderman"));
			Characters[GetCharacterIndex("William Wanderman")].dialog.currentnode = "Picked_up_at_Muelle";
		break;

		case "Homeward_bound_Redmond":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("William Wanderman"));
			LAi_SetOfficerType(characterFromID("William Wanderman"));

			Pchar.quest.Beckett_from_Isla_Muelle.win_condition.l1 = "location";
			PChar.quest.Beckett_from_Isla_Muelle.win_condition.l1.character = Pchar.id;
			//Pchar.quest.Beckett_from_Isla_Muelle.win_condition.l1.location = "Redmond_town_01";
			Pchar.quest.Beckett_from_Isla_Muelle.win_condition.l1.location = "EITC_Office";
			//Pchar.quest.Beckett_from_Isla_Muelle.win_condition = "Beckett_from_Isla_Muelle";
			Pchar.quest.Beckett_from_Isla_Muelle.win_condition = "Muelle_Rescue_Mission_complete";

			Locations[FindLocation("Redmond_Town_01")].reload.l17.disable = 0;
		break;

		case "Beckett_from_Isla_Muelle":
			pchar.quest.Muelle_Rescue_Mission_complete.win_condition.l1 = "locator";
			pchar.quest.Muelle_Rescue_Mission_complete.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.Muelle_Rescue_Mission_complete.win_condition.l1.locator_group = "reload";
			pchar.quest.Muelle_Rescue_Mission_complete.win_condition.l1.locator = "Door_2";
			pchar.quest.Muelle_Rescue_Mission_complete.win_condition = "Muelle_Rescue_Mission_complete";
		break;

		case "Muelle_Rescue_Mission_complete":
			/*Locations[FindLocation("Muelle04_HouseInsideR6")].vcskip = true;
			ChangeCharacterAddressGroup(characterfromID("Silas Simpkins"), "Muelle04_HouseInsideR6", "sit", "sit1");
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"), "Muelle04_HouseInsideR6", "sit", "sit2");
			ChangeCharacterAddressGroup(characterfromID("Stephen Walsh"), "Muelle04_HouseInsideR6", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Arthur Straightly"), "Muelle04_HouseInsideR6", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("William Wanderman"), "Muelle04_HouseInsideR6", "goto", "goto8");
			LAi_SetSitType(characterfromID("Cutler Beckett"));
			DoQuestReloadToLocation("Muelle04_HouseInsideR6", "Reload", "Reload1", "Muelle_Rescue_mission_reckoning");*/
			ChangeCharacterAddressGroup(characterfromID("Silas Simpkins"), "EITC_Office", "sit", "sit1");
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"), "EITC_Office", "sit", "sit2");
			ChangeCharacterAddressGroup(characterfromID("Stephen Walsh"), "EITC_Office", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Arthur Straightly"), "EITC_Office", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("William Wanderman"), "EITC_Office", "goto", "goto8");
			LAi_SetSitType(characterfromID("Cutler Beckett"));
			LAi_QuestDelay("Muelle_Rescue_mission_reckoning", 0.0);
		break;

		case "Muelle_Rescue_mission_reckoning":
			DisableFastTravel(true);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "desk", "Muelle_Rescue_mission_reckoning2", 10);
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "the Muelle reckoning";
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "Muelle Reckoning and ship";
		break;

		case "Muelle_Rescue_mission_reckoning2":
			LAi_SetPlayerType(pchar);

			LAi_SetActorType(characterFromID("Silas Simpkins"));
			LAi_ActorSetSitMode(characterFromID("Silas Simpkins"));
			LAi_ActorDialog(characterfromID("Silas Simpkins"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Silas Simpkins")].dialog.currentnode = "the Muelle reckoning";
		break;

		case "the_Muelle_reckoning3":
			RemoveOfficersIndex(pchar, GetCharacterIndex("William Wanderman"));
			RemovePassenger(pchar, characterFromID("William Wanderman"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Thomas Tipman"));
			RemovePassenger(pchar, characterFromID("Thomas Tipman"));
		break;

		case "Back to Mings from Antigua":
			PChar.Flags.Personal = 1; // TALISMAN: Change Personal Flag from EITC
			PChar.Flags.Personal.texture = 3;
			DisableFastTravel(false);

			/*pchar.quest.Now_Join_The_Brotherhood.win_condition.l1 = "locator";
			pchar.quest.Now_Join_The_Brotherhood.win_condition.l1.location = "Oxbay_town";
			pchar.quest.Now_Join_The_Brotherhood.win_condition.l1.locator_group = "reload";
			pchar.quest.Now_Join_The_Brotherhood.win_condition.l1.locator = "reload4";
			pchar.quest.Now_Join_The_Brotherhood.win_condition = "Now_Join_The_Brotherhood";*/
			pchar.quest.Now_Join_The_Brotherhood.win_condition.l1 = "location";
			pchar.quest.Now_Join_The_Brotherhood.win_condition.l1.location = "Mings_townhall";
			pchar.quest.Now_Join_The_Brotherhood.win_condition = "Now_Join_The_Brotherhood";

			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 0;
		break;

		case "Now_Join_The_Brotherhood":
			pchar.quest.Jacks_early_days = "Got_the_Magic_Compass";
			ChangeCharacterReputation(pchar, +2);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 3000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 3000); }
			ChangeCharacterAddress(characterfromID("Tia Dalma"),"none", "");
			CloseQuestHeader("Beckett");
			//ChangeCharacterAddress(characterFromID("Jacinto Arcibaldo Barreto"), "None", "");
			//ChangeCharacterAddressGroup(characterFromID("Sir Christopher Mings"), "Conceicao_townhall", "sit", "sit1");
			//ChangeCharacterAddressGroup(characterFromID("Peter Willemoes"), "Conceicao_townhall", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Sir Christopher Mings"), "Mings_townhall", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Peter Willemoes"), "Mings_townhall", "goto", "goto2");
			LAi_SetSitType(characterfromID("Sir Christopher Mings"));
			pchar.quest.Jacks_early_days = "Mings_compass_meeting";
			//DoQuestReloadToLocation("Conceicao_townhall", "Reload", "Reload1", "_");

			PChar.Turks = "1";
			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 1;
		break;

		case "Off_with_Gibbs_to_Guadeloupe":
			pchar.quest.Jacks_early_days = "Get_ready_for_Guadeloupe";
			ChangeCharacterAddressGroup(characterFromID("Peter Willemoes"), "Oxbay_town", "officers", "reload3_3");
			ChangeCharacterAddressGroup(characterFromID("Mr. Gibbs"),"Oxbay_town", "officers", "reload4_3");

			DoQuestReloadToLocation("Oxbay_town", "Officers", "Reload3_1", "Off_with_Gibbs_to_Guadeloupe2");
		break;
//cccccccccccccccccccccccccccccccccccccccccccccGAME FREEZEScccccccccccccccccccccccccccccccccccccccccccccccccc
		case "Off_with_Gibbs_to_Guadeloupe2":
			ChangeCharacterAddressGroup(characterFromID("Peter Willemoes"), "Oxbay_town", "officers", "reload3_3");
			ChangeCharacterAddressGroup(characterFromID("Mr. Gibbs"),"Oxbay_town", "officers", "reload4_3");

//			SetOfficersIndex(Pchar, 2, getCharacterIndex("Mr. Gibbs")); // Mod - Taken out this dialog to remove freeze condition
//			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Peter Willemoes"));
//			SetCharacterRemovable(characterFromID("Peter Willemoes"), false);
//			setCharacterShipLocation(characterFromID("Peter Willemoes"), "Oxbay_port");
//			LAi_SetOfficerType(characterfromID("Peter Willemoes"));

			LAi_SetActorType(characterFromID("Mr. Gibbs"));
			LAi_ActorDialog(characterFromID("Mr. Gibbs"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Mr. Gibbs")].dialog.currentnode = "First time";
		break;
//ccccccccccccccccccccccccccccccccccccccccccccGAME FREEZEScccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
		case "Gibbs_to_sort_ship":
			LAi_ActorGoToLocator(characterFromID("Mr. Gibbs"), "goto", "goto20", "", 10.0);
			LAi_QuestDelay("Gibbs_to_sort_ship2", 12.0);
		break;

		case "Gibbs_to_sort_ship2":
			pchar.quest.Jacks_early_days = "Arrival_at_Guadeloupe";
			ChangeCharacterAddress(characterFromID("Mr. Gibbs"), "None", "");
			LAi_SetActorType(characterFromID("Peter Willemoes"));
			LAi_ActorDialog(characterFromID("Peter Willemoes"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Peter Willemoes")].dialog.currentnode = "First time";

			Pchar.quest.Meet_more_Brotherhood.win_condition.l1 = "location";
			PChar.quest.Meet_more_Brotherhood.win_condition.l1.character = Pchar.id;
			Pchar.quest.Meet_more_Brotherhood.win_condition.l1.location = "Guadeloupe_Port";
			Pchar.quest.Meet_more_Brotherhood.win_condition = "Meet_more_Brotherhood";
		break;

		case "Meet_more_Brotherhood":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 500); }
			ChangeCharacterAddressGroup(characterFromID("Peter Willemoes"), "Guadeloupe_port", "officers", "reload1_1");
			LAi_SetOfficerType(characterfromID("Peter Willemoes"));
			ChangeCharacterAddressGroup(characterFromID("Mr. Gibbs"),"Guadeloupe_port", "officers", "reload1_2");

			pchar.quest.Jacks_early_days = "Now_at_Guadeloupe";
			ChangeCharacterAddressGroup(characterFromID("Cap'n Drow"),"Pointe_a_pitre_Tavern", "sit", "sit10");
			LAi_SetSitType(characterfromID("Cap'n Drow"));
			ChangeCharacterAddressGroup(characterFromID("Jack Rackham"),"Pointe_a_pitre_Tavern", "sit", "sit9");
			LAi_SetSitType(characterfromID("Jack Rackham"));
			ChangeCharacterAddressGroup(characterFromID("Anne Bonny"),"Pointe_a_pitre_Tavern", "goto", "goto17");

			LAi_SetActorType(characterFromID("Mr. Gibbs"));
			LAi_ActorDialog(characterFromID("Mr. Gibbs"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Mr. Gibbs")].dialog.currentnode = "Playing_Vanguard";
		break;

		case "Gibbs_to_Tavern":
			AddQuestRecord("The Brotherhood",14);
			LAi_SetActorType(characterFromID("Mr. Gibbs"));
			LAi_ActorGoToLocator(characterFromID("Mr. Gibbs"), "reload", "reload4_back", "Gibbs_to_Tavern2", 30.0);
		break;

		case "Gibbs_to_Tavern2":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Mr. Gibbs"));
			RemovePassenger(pchar, characterFromID("Mr. Gibbs"));
			ChangeCharacterAddress(characterFromID("Mr. Gibbs"), "None", "");
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Peter Willemoes"));
			LAi_QuestDelay("Gibbs_to_Tavern3", 1.0);
		break;

		case "Gibbs_to_Tavern3":
			ChangeCharacterAddressGroup(characterFromID("Mr. Gibbs"),"Pointe_a_pitre_Tavern", "sit", "sit3");
			LAi_SetSitType(characterfromID("Mr. Gibbs"));

			characters[GetCharacterIndex("Anne Bonny")].Dialog.Filename = "Anne Bonny_dialog.c";
			LAi_SetActorType(characterFromID("Anne Bonny"));
			LAi_ActorDialog(characterFromID("Anne Bonny"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Anne Bonny")].dialog.currentnode = "First time";
		break;

		case "Drow_starts_to_talk":
			SetCurrentTime(10, 0);

			characters[GetCharacterIndex("Cap'n Drow")].Dialog.Filename = "Cap'n Drow_dialog.c";
			LAi_SetActorType(characterFromID("Cap'n Drow"));
			LAi_ActorDialog(characterFromID("Cap'n Drow"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Cap'n Drow")].dialog.currentnode = "Island_stuff";
		break;

		case "Back_to_Rackham":
			characters[GetCharacterIndex("Jack Rackham")].Dialog.Filename = "Jack Rackham_dialog.c";
			LAi_SetActorType(characterFromID("Jack Rackham"));
			LAi_ActorDialog(characterFromID("Jack Rackham"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Jack Rackham")].dialog.currentnode = "Show_me_where_to_go";
		break;

		case "Refit_and_sleep":
			LAi_Fade("Refit_and_sleep_2", "Next_day_at_Guadeloupe");
		break;

		case "Refit_and_sleep_2":
			ChangeCharacterAddress(characterFromID("Anne Bonny"), "None", "");
			ChangeCharacterAddress(characterFromID("Cap'n Drow"), "None", "");
			ChangeCharacterAddress(characterFromID("Jack Rackham"), "None", "");
		break

		case "Next_day_at_Guadeloupe":
			DoQuestReloadToLocation("Pointe_a_pitre_store", "officers", "reload1_2", "Second_meeting_Drow_Rackham");
		break;

		case "Second_meeting_Drow_Rackham":
			pchar.quest.Jacks_early_days = "Travel_to_Petros";			
			ChangeCharacterAddressGroup(characterFromID("Cap'n Drow"),"Pointe_a_pitre_Tavern", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Jack Rackham"),"Pointe_a_pitre_Tavern", "goto", "goto17");
			ChangeCharacterAddressGroup(characterFromID("Anne Bonny"),"Pointe_a_pitre_Tavern", "goto", "goto9");
			LAi_QuestDelay("Second_meeting_Drow_Rackham2", 1.0);
		break;

		case "Second_meeting_Drow_Rackham2":
			characters[GetCharacterIndex("Jack Rackham")].Dialog.Filename = "Jack Rackham_dialog.c";
			LAi_SetActorType(characterFromID("Jack Rackham"));
			LAi_ActorDialog(characterFromID("Jack Rackham"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Jack Rackham")].dialog.currentnode = "First time";
		break;

		case "To_Anse_Casse_Bois":
			AddQuestRecord("The Brotherhood",15);

			pchar.quest.To_Anse_Casse_Bois2.win_condition.l1 = "location";
			pchar.quest.To_Anse_Casse_Bois2.win_condition.l1.location = "Guadeloupe_port";
			pchar.quest.To_Anse_Casse_Bois2.win_condition = "To_Anse_Casse_Bois2";
		break;

		case "To_Anse_Casse_Bois2":
			ChangeCharacterAddressGroup(characterFromID("Cap'n Drow"),"Pointe_a_pitre_Tavern", "sit", "sit10");
			LAi_SetSitType(characterfromID("Cap'n Drow"));
			ChangeCharacterAddressGroup(characterFromID("Jack Rackham"),"Pointe_a_pitre_Tavern", "sit", "sit9");
			LAi_SetSitType(characterfromID("Jack Rackham"));
			ChangeCharacterAddressGroup(characterFromID("Anne Bonny"),"Pointe_a_pitre_Tavern", "goto", "goto17");
			LAi_SetActorType(characterFromID("Anne Bonny"));
			pchar.quest.Jacks_early_days = "Decision_for_Capture";

			pchar.quest.To_Guadeloupe_shore_01.win_condition.l1 = "location";
			pchar.quest.To_Guadeloupe_shore_01.win_condition.l1.location = "Guadeloupe_shore_01";
			pchar.quest.To_Guadeloupe_shore_01.win_condition = "To_Guadeloupe_shore_01";
		break;

		case "To_Guadeloupe_shore_01":
			ChangeCharacterAddressGroup(characterFromID("Mr. Gibbs"),"Guadeloupe_shore_01", "goto", "locator10"); // PB: Start from bigger distance to avoid errors
			LAi_SetActorType(characterFromID("Mr. Gibbs"));
			LAi_ActorDialog(characterFromID("Mr. Gibbs"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Mr. Gibbs")].dialog.currentnode = "Stay_or_Accompany";
		break;

		case "Continue_with_Gibbs_and_Willemoes":
			LAi_ActorFollowEverywhere(characterFromID("Mr. Gibbs"), "", 60.0); // TALISMAN added to make Gibbs walk follow to Petros Plant 
			pchar.quest.Now_get_to_see_Petros.win_condition.l1 = "location";
			pchar.quest.Now_get_to_see_Petros.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Now_get_to_see_Petros.win_condition = "Now_get_to_see_Petros_house";
		break;

		case "Goodbye_Gibbs_and_Willemoes":
			LAi_SetActorType(characterFromID("Mr. Gibbs"));
			LAi_ActorGoToLocator(characterFromID("Mr. Gibbs"), "goto", "goto2", "", 5.0);

			Locations[FindLocation("Guadeloupe_Jungle_03")].reload.l2.disable = 1;
			Locations[FindLocation("Guadeloupe_Jungle_03")].reload.l4.disable = 1;

			pchar.quest.Captured_on_Guadeloupe.win_condition.l1 = "locator";
			pchar.quest.Captured_on_Guadeloupe.win_condition.l1.location = "Guadeloupe_Jungle_03";
			pchar.quest.Captured_on_Guadeloupe.win_condition.l1.locator_group = "reload";
//			pchar.quest.Captured_on_Guadeloupe.win_condition.l1.locator = "reload5";	// This is the small house in the clearing by the fort - why would you go there?
			pchar.quest.Captured_on_Guadeloupe.win_condition.l1.locator = "Reload2_back";	// This is the exit towards the plantation
			pchar.quest.Captured_on_Guadeloupe.win_condition = "Captured_on_Guadeloupe";
		break;

		case "Now_get_to_see_Petros_house":
			Pchar.Quest.Captured_on_Guadeloupe.over = "yes";
			ChangeCharacterAddress(characterFromID("FranÃ§ois de Vigny"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Konrad Kulczycki"),"Guadeloupe_Plantation_inside", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Petros"),"Guadeloupe_Plantation_inside", "sit", "sit1");
			LAi_SetSitType(characterfromID("Petros"));

			Pchar.quest.Get_to_meet_Petros.win_condition.l1 = "location";
			PChar.quest.Get_to_meet_Petros.win_condition.l1.character = Pchar.id;
			Pchar.quest.Get_to_meet_Petros.win_condition.l1.location = "Guadeloupe_Plantation_inside";
			Pchar.quest.Get_to_meet_Petros.win_condition = "Get_to_meet_Petros";
		break;

		case "Get_to_meet_Petros":
			pchar.quest.Jacks_early_days = "Petros_in_sight";
			Locations[FindLocation("Guadeloupe_Plantation_inside")].reload.l1.disable = 1;
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(characterfromID("Peter Willemoes"),"Guadeloupe_Plantation_inside", "goto", "goto1");

//DIALOG CHANGE FOR PETROS
			Characters[GetCharacterIndex("Petros")].dialog.currentnode = "First time";
		break;

		case "Get_to_meet_Petros2":
			LAi_SetActorType(characterfromID("Konrad Kulczycki"));
			LAi_ActorWaitDialog(pchar, characterFromID("Konrad Kulczycki"));
			Characters[GetCharacterIndex("Konrad Kulczycki")].Dialog.CurrentNode = "First time";
			LAi_ActorDialogNow(characterFromID("Konrad Kulczycki"), Pchar, "", -1);
		break;

		case "Petros_talk_two":
			characters[GetCharacterIndex("Petros")].Dialog.Filename = "Petros_dialog.c";
			LAi_SetActorType(characterFromID("Petros"));
			LAi_ActorDialog(characterFromID("Petros"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Petros")].dialog.currentnode = "tryout";
		break;

		case "Peter_joins_in":
			LAi_SetActorType(characterFromID("Peter Willemoes"));
			LAi_ActorWaitDialog(pchar, characterFromID("Peter Willemoes"));
			Characters[GetCharacterIndex("Peter Willemoes")].dialog.currentnode = "First time";
			LAi_ActorDialogNow(characterFromID("Peter Willemoes"), Pchar, "", -1);
		break;

		case "Stratergy_discussion":
			characters[GetCharacterIndex("Konrad Kulczycki")].Dialog.Filename = "Konrad Kulczycki_dialog.c";
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			LAi_ActorDialog(characterFromID("Konrad Kulczycki"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Konrad Kulczycki")].dialog.currentnode = "Stratergy_talk";
		break;

		case "KK_and_Willemous_leave":
			characters[GetCharacterIndex("Petros")].Dialog.Filename = "Petros_dialog.c";
			LAi_SetActorType(characterFromID("Petros"));
			LAi_ActorDialog(characterFromID("Petros"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Petros")].dialog.currentnode = "Ready_for_CCC_Quest";
		break;

		case "Leaving the room_Konrad2":
			ChangeCharacterAddress(characterFromID("Konrad Kulczycki"), "None", "");
			ChangeCharacterAddress(characterFromID("Peter Willemoes"), "None", "");
			characters[GetCharacterIndex("Petros")].Dialog.Filename = "Petros_dialog.c";
			LAi_SetActorType(characterFromID("Petros"));
			LAi_ActorDialog(characterFromID("Petros"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Petros")].dialog.currentnode = "Plan_for_CCC_Quest";
		break;
//CCC Quest Starts here
		case "Muelle_for_CCC":
			AddQuestRecord("The Brotherhood",16); // TALISMAN - was 17 <-wrong
			AddQuestRecord("Aztec",13);           // TALISMAN - added
			DisableFastTravel(false);
			pchar.quest.Jacks_early_days = "Looking_for_CCC";
			LAi_SetOfficerType(characterFromID("Mr. Gibbs"));
			RemoveCharacterCompanion(pchar, characterFromID("Peter Willemoes"));

			Pchar.quest.Looking_for_CCC.win_condition.l1 = "location";
			PChar.quest.Looking_for_CCC.win_condition.l1.character = Pchar.id;
			Pchar.quest.Looking_for_CCC.win_condition.l1.location = "Muelle_Tavern";
			Pchar.quest.Looking_for_CCC.win_condition = "Looking_for_CCC";
		break;

		case "Looking_for_CCC":
			pchar.quest.Jacks_early_days = "Rescue_CCC";
			ChangeCharacterAddressGroup(characterFromID("Barbossa"), "Muelle_Tavern", "sit", "sit5");
			ChangeCharacterAddressGroup(characterFromID("Couch Captain Charles"), "Muelle_ANIMISTS", "goto", "goto28");
			Island_SetReloadEnableLocal("IslaMuelle", "reload_2", true); // PB: Needs to be accessible
			LAi_SetSitType(characterfromID("Barbossa"));

			Pchar.quest.Found_CCC.win_condition.l1 = "location";
			PChar.quest.Found_CCC.win_condition.l1.character = Pchar.id;
			Pchar.quest.Found_CCC.win_condition.l1.location = "Muelle_ANIMISTS";
			Pchar.quest.Found_CCC.win_condition = "Found_CCC";
		break;

		case "Found_CCC":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			characters[GetCharacterIndex("Couch Captain Charles")].Dialog.Filename = "Couch Captain Charles_dialog.c";
			LAi_SetStayType(characterFromID("Couch Captain Charles"));
			LAi_ActorDialog(characterFromID("Couch Captain Charles"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Couch Captain Charles")].dialog.currentnode = "Get_me_out_of_here";
		break;

		case "Return_to_Petros_with_CCC":
			AddQuestRecord("The Brotherhood",19);

			SetOfficersIndex(Pchar, 1, getCharacterIndex("Couch Captain Charles"));
			LAi_SetOfficerType(characterFromID("Couch Captain Charles"));

			Pchar.quest.Second_meet_Petros.win_condition.l1 = "location";
			PChar.quest.Second_meet_Petros.win_condition.l1.character = Pchar.id;
			Pchar.quest.Second_meet_Petros.win_condition.l1.location = "Guadeloupe_Plantation_inside";
			Pchar.quest.Second_meet_Petros.win_condition = "Second_meet_Petros";
		break;

		case "Second_meet_Petros":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			CloseQuestHeader("CCC");

			ChangeCharacterAddressGroup(characterfromID("Peter Willemoes"),"Guadeloupe_Plantation_inside", "sit", "sit5");
			LAi_SetSitType(characterfromID("Peter Willemoes"));
			ChangeCharacterAddressGroup(characterfromID("Konrad Kulczycki"),"Guadeloupe_Plantation_inside", "goto", "goto4");
			LAi_SetStayType(characterFromID("Konrad Kulczycki"));
			ChangeCharacterAddressGroup(characterfromID("Petros"),"Guadeloupe_Plantation_inside", "goto", "goto8");
			ChangeCharacterAddressGroup(characterfromID("Couch Captain Charles"),"Guadeloupe_Plantation_inside", "goto", "goto7");

			characters[GetCharacterIndex("Petros")].Dialog.Filename = "Petros_dialog.c";
			LAi_SetActorType(characterFromID("Petros"));
			LAi_ActorDialog(characterFromID("Petros"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Petros")].dialog.currentnode = "Return_of_CCC";
		break;

		case "Go_to_meet_Annamaria_First":
			AddQuestRecord("The Brotherhood",20);
			DisableFastTravel(false);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Couch Captain Charles"));
			RemovePassenger(Pchar, characterFromID("Couch Captain Charles"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Mr. Gibbs"));
			RemovePassenger(Pchar, characterFromID("Mr. Gibbs"));

			Pchar.quest.Brotherhood_lighthouse_and_Annamaria.win_condition.l1 = "location";
			PChar.quest.Brotherhood_lighthouse_and_Annamaria.win_condition.l1.character = Pchar.id;
			Pchar.quest.Brotherhood_lighthouse_and_Annamaria.win_condition.l1.location = "Oxbay_Lighthouse";
			Pchar.quest.Brotherhood_lighthouse_and_Annamaria.win_condition = "Brotherhood_lighthouse_and_Annamaria";

			Pchar.quest.Straight_to_Beckett_Capture.win_condition.l1 = "location";
			PChar.quest.Straight_to_Beckett_Capture.win_condition.l1.character = Pchar.id;
			Pchar.quest.Straight_to_Beckett_Capture.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Straight_to_Beckett_Capture.win_condition = "Straight_to_Beckett_Capture";

			Pchar.quest.Oxbay_to_Beckett_Capture.win_condition.l1 = "location";
			PChar.quest.Oxbay_to_Beckett_Capture.win_condition.l1.character = Pchar.id;
			Pchar.quest.Oxbay_to_Beckett_Capture.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.Oxbay_to_Beckett_Capture.win_condition = "Oxbay_to_Beckett_Capture";
// End of CCC Quest
		break;

		case "Brotherhood_lighthouse_and_Annamaria":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			Pchar.Quest.Straight_to_Beckett_Capture.over = "yes";
			Pchar.Quest.Oxbay_to_Beckett_Capture.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Annamaria"), "Oxbay_lighthouse", "goto", "goto26");
			LAi_ActorWaitDialog(PChar,characterFromID("Annamaria"));

			characters[GetCharacterIndex("Annamaria")].Dialog.Filename = "Annamaria_dialog.c";
			LAi_SetStayType(characterFromID("Annamaria"));
			LAi_ActorDialog(characterFromID("Annamaria"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "Looking_for_Nathan_Kell";
		break;

		case "Nathan_Kell_in_Oxbay":
			AddQuestRecord("The Brotherhood",21);
			Pchar.quest.Meet_Nathan_Kell.win_condition.l1 = "location";
			Pchar.quest.Meet_Nathan_Kell.win_condition.l1.character = Pchar.id;
			Pchar.quest.Meet_Nathan_Kell.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Meet_Nathan_Kell.win_condition = "Meet_Nathan_Kell";
			
// Traps for not going through mine canyon vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
			Pchar.quest.Lazy_way_to_Beckett_Capture.win_condition.l1 = "location";
			PChar.quest.Lazy_way_to_Beckett_Capture.win_condition.l1.character = Pchar.id;
			Pchar.quest.Lazy_way_to_Beckett_Capture.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Lazy_way_to_Beckett_Capture.win_condition = "Lazy_way_to_Beckett_Capture";

			Pchar.quest.Oxbay_way_to_Beckett_Capture.win_condition.l1 = "location";
			PChar.quest.Oxbay_way_to_Beckett_Capture.win_condition.l1.character = Pchar.id;
			Pchar.quest.Oxbay_way_to_Beckett_Capture.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.Oxbay_way_to_Beckett_Capture.win_condition = "Oxbay_way_to_Beckett_Capture";
		break;

		case "Lazy_way_to_Beckett_Capture":
			SetNextWeather("Black Pearl Fight");
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			StorePassengers(PChar.id);
			DisableFastTravel(true);
			Locations[FindLocation("Greenford_port")].vcskip = true;
			Pchar.Quest.Meet_Nathan_Kell.over = "yes";
			Pchar.Quest.Oxbay_way_to_Beckett_Capture.over = "yes";
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"HMS_Bounty","Lindesfarne",ENGLAND,-1,true,true);

			ChangeCharacterAddressGroup(characterFromID("Cutler Beckett"), "Greenford_port", "goto", "goto21");
			ChangeCharacterAddressGroup(characterFromID("Eng_soldier_38"), "Greenford_port", "goto", "goto19");
			ChangeCharacterAddressGroup(characterFromID("Eng_soldier_39"), "Greenford_port", "goto", "goto20");

			characters[GetCharacterIndex("Cutler Beckett")].Dialog.Filename = "Cutler Beckett_dialog.c";
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorDialog(characterFromID("Cutler Beckett"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "Lazy_Captured_on_Oxbay";
		break;

		case "Oxbay_way_to_Beckett_Capture":
			SetNextWeather("Black Pearl Fight");
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			StorePassengers(PChar.id);
			DisableFastTravel(true);
			Locations[FindLocation("Oxbay_port")].vcskip = true;
			Pchar.Quest.Meet_Nathan_Kell.over = "yes";
			Pchar.Quest.Lazy_way_to_Beckett_Capture.over = "yes";
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"HMS_Bounty","Lindesfarne",ENGLAND,-1,true,true);

			ChangeCharacterAddressGroup(characterFromID("Cutler Beckett"), "Oxbay_port", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Eng_soldier_39"), "Oxbay_port", "officers", "reload2_1");

			characters[GetCharacterIndex("Cutler Beckett")].Dialog.Filename = "Cutler Beckett_dialog.c";
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorDialog(characterFromID("Cutler Beckett"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "Lazy_Captured_on_Oxbay";
		break;
// End Traps not going through canyon ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

		case "Meet_Nathan_Kell":
			Pchar.Quest.Lazy_way_to_Beckett_Capture.over = "yes";
			Pchar.Quest.Oxbay_way_to_Beckett_Capture.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Lieutenant Bligh"), "Greenford_town", "goto", "goto30");
			
			ChangeCharacterAddressGroup(characterFromID("Captain Damski"), "Greenford_church", "goto", "goto1");
			characters[GetCharacterIndex("Captain Damski")].Dialog.Filename = "Captain Damski_dialog.c";
			LAi_SetStayType(characterFromID("Captain Damski"));
			LAi_ActorDialog(characterFromID("Captain Damski"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "First_meet_in_Church";
		break;

		case "Moving_along_In_search_for_Nathan_Kell":
			DisableFastTravel(true);
			ChangeCharacterAddress(characterFromID("Apothecary"), "None", "");
			
			Pchar.quest.Found_Nathan_Kell.win_condition.l1 = "locator";
			PChar.quest.Found_Nathan_Kell.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Found_Nathan_Kell.win_condition.l1.locator_group = "reload";
			Pchar.quest.Found_Nathan_Kell.win_condition.l1.locator = "reload13";
			Pchar.quest.Found_Nathan_Kell.win_condition = "Found_Nathan_Kell";
		break;

		case "Found_Nathan_Kell":
			ChangeCharacterAddress(characterFromID("Captain Damski"), "None", "");

			Pchar.quest.Found_Nathan_Kells_room.win_condition.l1 = "locator";
			PChar.quest.Found_Nathan_Kells_room.win_condition.l1.location = "Apothecary";
			Pchar.quest.Found_Nathan_Kells_room.win_condition.l1.locator_group = "goto";
			Pchar.quest.Found_Nathan_Kells_room.win_condition.l1.locator = "goto1";
			Pchar.quest.Found_Nathan_Kells_room.win_condition = "Found_Nathan_Kells_room";
		break;

		case "Found_Nathan_Kells_room":
			ChangeCharacterAddressGroup(characterFromID("Nathan Kell"), "Guadeloupe_Plantation_bedroom", "goto", "goto5");
			DoQuestReloadToLocation("Guadeloupe_Plantation_bedroom", "Reload", "Reload1", "Found_Nathan_Kells_room2");
		break;

		case "Found_Nathan_Kells_room2":
			characters[GetCharacterIndex("Nathan Kell")].Dialog.Filename = "Nathan Kell_dialog.c";
			LAi_SetStayType(characterFromID("Nathan Kell"));
			LAi_ActorDialog(characterFromID("Nathan Kell"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Nathan Kell")].dialog.currentnode = "First_meet_in_Secret_Room";
		break;

		case "Moving_along_to_be_captured":
			ChangeCharacterAddressGroup(characterFromID("Captain Damski"), "Guadeloupe_Plantation_bedroom", "Reload", "Reload1");

			characters[GetCharacterIndex("Captain Damski")].Dialog.Filename = "Captain Damski_dialog.c";
			LAi_SetActorType(characterFromID("Captain Damski"));
			LAi_ActorDialog(characterFromID("Captain Damski"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "meet_in_Apothecary";
		break;

		case "Now_make_other_plans":
			characters[GetCharacterIndex("Nathan Kell")].Dialog.Filename = "Nathan Kell_dialog.c";
			LAi_SetActorType(characterFromID("Nathan Kell"));
			Characters[GetCharacterIndex("Nathan Kell")].Dialog.CurrentNode = "talk_about_other_plans";
			LAi_ActorDialogNow(characterFromID("Nathan Kell"), Pchar, "", -1);
		break;

		case "With_Kell_to_Oxbay":
			ChangeCharacterAddress(characterFromID("Captain Damski"), "None", "");
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Nathan Kell"));
			LAi_SetOfficerType(characterFromID("Nathan Kell"));	

			Pchar.quest.Exit_Nathan_Kells_room.win_condition.l1 = "locator";
			PChar.quest.Exit_Nathan_Kells_room.win_condition.l1.location = "Guadeloupe_Plantation_bedroom";
			Pchar.quest.Exit_Nathan_Kells_room.win_condition.l1.locator_group = "Reload";
			Pchar.quest.Exit_Nathan_Kells_room.win_condition.l1.locator = "Reload1";
			Pchar.quest.Exit_Nathan_Kells_room.win_condition = "Exit_Nathan_Kells_room";
		break;

		case "Exit_Nathan_Kells_room":
			DoQuestReloadToLocation("Apothecary", "goto", "goto1", "Moving_along_to_be_captured2");
		break;

		case "Moving_along_to_be_captured2":
			ChangeCharacterAddressGroup(characterFromID("Nathan Kell"), "Apothecary", "goto", "goto1");

			pchar.quest.With_Kell_see_Blyth.win_condition.l1 = "location";
			pchar.quest.With_Kell_see_Blyth.win_condition.l1.location = "Greenford_town";
			pchar.quest.With_Kell_see_Blyth.win_condition = "With_Kell_see_Blyth";
		break;

		case "With_Kell_see_Blyth":
			characters[GetCharacterIndex("Nathan Kell")].Dialog.Filename = "Nathan Kell_dialog.c";
			LAi_SetActorType(characterFromID("Nathan Kell"));
			Characters[GetCharacterIndex("Nathan Kell")].Dialog.CurrentNode = "The_Watchers_over_there";
			LAi_ActorDialogNow(characterFromID("Nathan Kell"), Pchar, "", -1);
		break;

		case "With_Kell_to_OxbayXXX":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Nathan Kell"));
			LAi_SetOfficerType(characterFromID("Nathan Kell"));

			pchar.quest.With_Kell_to_Mings.win_condition.l1 = "location";
			pchar.quest.With_Kell_to_Mings.win_condition.l1.location = "Oxbay_town";
			pchar.quest.With_Kell_to_Mings.win_condition = "With_Kell_to_Mings";
		break;

		case "With_Kell_to_Mings":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			ChangeCharacterAddressGroup(characterFromID("Lieutenant Bligh"), "Oxbay_town", "goto", "goto24");

			/*pchar.quest.With_Kell_to_Mings2.win_condition.l1 = "locator";
			pchar.quest.With_Kell_to_Mings2.win_condition.l1.location = "Oxbay_town";
			pchar.quest.With_Kell_to_Mings2.win_condition.l1.locator_group = "reload";
			pchar.quest.With_Kell_to_Mings2.win_condition.l1.locator = "reload4";
			pchar.quest.With_Kell_to_Mings2.win_condition = "With_Kell_to_Mings2";*/
			pchar.quest.With_Kell_to_Mings2.win_condition.l1 = "location";
			pchar.quest.With_Kell_to_Mings2.win_condition.l1.location = "Mings_townhall";
			pchar.quest.With_Kell_to_Mings2.win_condition = "With_Kell_to_Mings2";

			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 0;
		break;

		case "With_Kell_to_Mings2":
			RemoveOfficersIndex(Pchar, GetCharacterIndex("Nathan Kell"));
			RemovePassenger(Pchar, characterFromID("Nathan Kell"));
			LAi_type_actor_Reset(characterFromID("Peter Willemoes"));
			LAi_SetActorType(characterFromID("Peter Willemoes"));

			/*ChangeCharacterAddressGroup(characterFromID("Nathan Kell"),"Conceicao_townhall", "goto", "goto8");
			ChangeCharacterAddressGroup(characterFromID("Sir Christopher Mings"), "Conceicao_townhall", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Petros"), "Conceicao_townhall", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Konrad Kulczycki"),"Conceicao_townhall", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Peter Willemoes"),"Conceicao_townhall", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Captain Maximus"),"Conceicao_townhall", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Captain Philippe"),"Conceicao_townhall", "goto", "goto3");*/
			ChangeCharacterAddressGroup(characterFromID("Nathan Kell"),"Mings_townhall", "goto", "goto8");
			ChangeCharacterAddressGroup(characterFromID("Sir Christopher Mings"), "Mings_townhall", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Petros"), "Mings_townhall", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Konrad Kulczycki"),"Mings_townhall", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Peter Willemoes"),"Mings_townhall", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Captain Maximus"),"Mings_townhall", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Captain Philippe"),"Mings_townhall", "goto", "goto3");

			LAi_SetSitType(characterfromID("Sir Christopher Mings"));
			pchar.quest.Jacks_early_days = "Mings_and_Kell_meeting";
			//DoQuestReloadToLocation("Conceicao_townhall", "Reload", "Reload1", "With_Kell_to_Mings3");
			LAi_QuestDelay("With_Kell_to_Mings3", 0.0);
		break;

		case "With_Kell_to_Mings3":
			//Locations[FindLocation("Conceicao_townhall")].reload.l1.disable = 1;
			Locations[FindLocation("Mings_townhall")].reload.l1.disable = 1;
			characters[GetCharacterIndex("Nathan Kell")].Dialog.Filename = "Nathan Kell_dialog.c";
			LAi_SetActorType(characterFromID("Nathan Kell"));
			Characters[GetCharacterIndex("Nathan Kell")].Dialog.CurrentNode = "A_fine_mess_to_sort";
			LAi_ActorDialogNow(characterFromID("Nathan Kell"), Pchar, "", -1);
		break;

		case "Kell_talks_to_Mings_Oxbay":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(characterFromID("Nathan Kell"), "goto", "goto7", "", 3.0);
			LAi_ActorGoToLocator((Pchar), "goto", "goto8", "", 3.0);
			LAi_QuestDelay("Kell_talks_to_Mings_Oxbay2", 10.0);
		break;

		case "Kell_talks_to_Mings_Oxbay2":
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("Sir Christopher Mings")].Dialog.Filename = "Sir Christopher Mings_dialog.c";
			LAi_SetActorType(characterFromID("Sir Christopher Mings"));
			Characters[GetCharacterIndex("Sir Christopher Mings")].Dialog.CurrentNode = "Mings_A_fine_mess_to_sort";
			LAi_ActorDialogNow(characterFromID("Sir Christopher Mings"), Pchar, "", -1);
		break;

		case "Discussion_with_Mings_and_Kell":
			LAi_SetSitType(characterfromID("Sir Christopher Mings"));
			SetCurrentTime(10, 0);
			LAi_ActorDialogNow(Pchar, characterFromID("Sir Christopher Mings"), "", -1);
			LAi_ActorDialog(characterFromID("Sir Christopher Mings"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Sir Christopher Mings")].dialog.currentnode = "Solution_to_the_Mess";
		break;

		case "Discussion_with_Konrad_re_Wicked_Wench":
			characters[GetCharacterIndex("Konrad Kulczycki")].Dialog.Filename = "Konrad Kulczycki_dialog.c"
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			Characters[GetCharacterIndex("Konrad Kulczycki")].Dialog.CurrentNode = "Unfolding_the_Wicked_Wench_plan";
			LAi_ActorDialogNow(characterFromID("Konrad Kulczycki"), Pchar, "", -1);
		break;

		case "And_now_the_other_option":
			LAi_ActorDialogNow(Pchar, characterFromID("Peter Willemoes"), "", -1);
			LAi_ActorDialog(characterFromID("Peter Willemoes"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Peter Willemoes")].dialog.currentnode = "Option_Talk";
		break;

		case "Mings_sums_up":
			characters[GetCharacterIndex("Sir Christopher Mings")].Dialog.Filename = "Sir Christopher Mings_dialog.c";
			LAi_SetActorType(characterFromID("Sir Christopher Mings"));
			Characters[GetCharacterIndex("Sir Christopher Mings")].Dialog.CurrentNode = "Mings_summation";
			LAi_ActorDialogNow(characterFromID("Sir Christopher Mings"), Pchar, "", -1);
		break;

		case "Kell_and_me_to_Guadeloupe":
			//Locations[FindLocation("Conceicao_townhall")].reload.l1.disable = 0;
			Locations[FindLocation("Mings_townhall")].reload.l1.disable = 0;
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"Sloop2","Slick Rigging",-1,ENGLAND,true,true);
			SetCharacterShipLocation(Pchar, "Oxbay_Port");

			setCharacterShipLocation(characterFromID("Captain Philippe"), "Oxbay_port");
			LAi_SetOfficerType(characterfromID("Captain Philippe"));
			setCharacterShipLocation(characterFromID("Captain Maximus"), "Oxbay_port");
			LAi_SetOfficerType(characterfromID("Captain Maximus"));

			/*Pchar.quest.Exit_Sir_Christophers2_room.win_condition.l1 = "locator";
			PChar.quest.Exit_Sir_Christophers2_room.win_condition.l1.location = "Conceicao_townhall";
			Pchar.quest.Exit_Sir_Christophers2_room.win_condition.l1.locator_group = "Reload";
			Pchar.quest.Exit_Sir_Christophers2_room.win_condition.l1.locator = "Reload1";
			Pchar.quest.Exit_Sir_Christophers2_room.win_condition = "Exit_Sir_Christophers_room2";*/
			Pchar.quest.Maximus_and_Philippe.win_condition.l1 = "location";
			PChar.quest.Maximus_and_Philippe.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Maximus_and_Philippe.win_condition = "Maximus_and_Philippe";

			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 1;
		break;

		case "KK_Petros_Kell_fleet":
			//Locations[FindLocation("Conceicao_townhall")].reload.l1.disable = 0;
			Locations[FindLocation("Mings_townhall")].reload.l1.disable = 0;
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"Sloop2","Slick Rigging",-1,ENGLAND,true,true);
			SetCharacterShipLocation(Pchar, "Oxbay_Port");

			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Konrad Kulczycki"));
			SetCharacterRemovable(characterFromID("Konrad Kulczycki"), false);
			setCharacterShipLocation(characterFromID("Konrad Kulczycki"), "Oxbay_port");
			LAi_SetOfficerType(characterfromID("Konrad Kulczycki"));
			
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Nathan Kell"));
			SetCharacterRemovable(characterFromID("Nathan Kell"), false);
			setCharacterShipLocation(characterFromID("Nathan Kell"), "Oxbay_port");
			LAi_SetOfficerType(characterfromID("Nathan Kell"));
			
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Petros"));
			SetCharacterRemovable(characterFromID("Petros"), false);
			setCharacterShipLocation(characterFromID("Petros"), "Oxbay_port");
			LAi_SetOfficerType(characterfromID("Petros"));

			ChangeCharacterAddressGroup(characterFromID("Lieutenant Bligh"), "Oxbay_town", "officers", "reload17_1");

			/*Pchar.quest.Exit_Sir_Christophers_room.win_condition.l1 = "locator";
			PChar.quest.Exit_Sir_Christophers_room.win_condition.l1.location = "Conceicao_townhall";
			Pchar.quest.Exit_Sir_Christophers_room.win_condition.l1.locator_group = "Reload";
			Pchar.quest.Exit_Sir_Christophers_room.win_condition.l1.locator = "Reload1";
			Pchar.quest.Exit_Sir_Christophers_room.win_condition = "Exit_Sir_Christophers_room";*/
			Pchar.quest.set_off_with_KK_Turks.win_condition.l1 = "location";
			PChar.quest.set_off_with_KK_Turks.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.set_off_with_KK_Turks.win_condition = "set_off_with_KK_Turks";

			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 1;
		break;

		case "Exit_Sir_Christophers_room":
			DoQuestReloadToLocation("Oxbay_town", "reload", "Reload4", "set_off_with_KK_Turks");
		break;

		case "set_off_with_KK_Turks":
			DisableFastTravel(false);
			Group_CreateGroup("Lieutenant Bligh");
			Group_AddCharacter("Lieutenant Bligh", "Lieutenant Bligh");
//			Group_AddCharacter("Lieutenant Bligh", "Cutler Beckett");
			Group_SetGroupCommander("Lieutenant Bligh", "Lieutenant Bligh");
			Group_SetPursuitGroup("Lieutenant Bligh", PLAYER_GROUP);
			Group_SetTaskAttack("Lieutenant Bligh", PLAYER_GROUP, true);
			Group_LockTask("Lieutenant Bligh");
			Group_SetAddress("Lieutenant Bligh", "Oxbay", "Quest_Ships","Quest_Ship_7");

			SetCrewQuantity(characterFromID("Lieutenant Bligh"), 60.0);
			Sea_LoginGroupNow("Lieutenant Bligh");
			characters[GetCharacterIndex("Lieutenant Bligh")].nosurrender = 2;
			SetCharacterRelationBoth(GetCharacterIndex("Lieutenant Bligh"),GetMainCharacterIndex(),RELATION_ENEMY);
			Character_SetAbordageEnable(characterFromID("Lieutenant Bligh"), false);

			UpdateRelations();
			pchar.quest.Turks_with_KK.win_condition.l1 = "location";
			pchar.quest.Turks_with_KK.win_condition.l1.location = "Turks_port";
			pchar.quest.Turks_with_KK.win_condition = "Turks_with_KK";
		break;

		case "Turks_with_KK":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }

			ChangeCharacterAddressGroup(characterfromID("Konrad Kulczycki"), "Turks_port", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterfromID("Petros"), "Turks_port", "officers", "reload1_2");				//JRH was 1_3
			ChangeCharacterAddressGroup(characterfromID("Nathan Kell"), "Turks_port", "officers", "reload1_3");			//JRH was 1_2			
			ChangeCharacterAddressGroup(characterfromID("Captain Damski"), "Turks_port", "goto", "P_reload1_2");			//JRH: new Turks, was goto2

			LAi_SetOfficerType(characterFromID("Captain Damski"));
			LAi_SetCivilianGuardianType(characterFromID("Konrad Kulczycki"));
			LAi_SetCivilianGuardianType(characterFromID("Petros"));
			LAi_SetCivilianGuardianType(characterFromID("Nathan Kell"));
			if (GetAttribute(PChar, "Turks") == "Drow"){LAi_SetCivilianGuardianType(characterFromID("Cap'n Drow"));}

			LAi_QuestDelay("Turks_with_KK2", 2.0);										//JRH was 3.0
		break;

		case "Turks_with_KK2":
			characters[GetCharacterIndex("Captain Damski")].Dialog.Filename = "Captain Damski_dialog.c";
			LAi_SetActorType(characterFromID("Captain Damski"));
			LAi_ActorDialog(characterFromID("Captain Damski"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "meet_in_Turks";
		break;

		case "Back_to_Lighthouse_from_Turks":
			DisableFastTravel(false);
			EndQuestMovie();
			RemoveCharacterCompanion(pchar, characterFromID("Konrad Kulczycki"));
			RemoveCharacterCompanion(pchar, characterFromID("Petros"));
			RemoveCharacterCompanion(pchar, characterFromID("Nathan Kell"));
			if (GetAttribute(PChar, "Turks") == "Drow")
			{
				RemovePassenger(pchar, characterFromID("Cap'n Drow"));
				LAi_SetActorType(characterFromID("Cap'n Drow"));
				LAi_ActorGoToLocator(characterFromID("Cap'n Drow"), "reload", "reload3_back", "", 3.0);
			}

			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			LAi_SetActorType(characterFromID("Petros"));
			LAi_SetActorType(characterFromID("Nathan Kell"));

			LAi_ActorGoToLocator(characterFromID("Nathan Kell"), "goto", "P_goto11", "", 22.0);				//JRH new Turks
			LAi_ActorGoToLocator(characterFromID("Petros"), "goto", "P_goto11", "", 22.0);
			LAi_ActorGoToLocator(characterFromID("Konrad Kulczycki"), "goto", "P_goto11", "", 22.0);
//			LAi_ActorGoToLocator(characterFromID("Captain Damski"), "goto", "P_goto11", "Back_to_Lighthouse_from_Turks2", 22.0); // GR: Won't trigger if you go to sea before they've finished moving
			LAi_ActorGoToLocator(characterFromID("Captain Damski"), "goto", "P_goto11", "", 22.0);

			Pchar.quest.Back_to_Lighthouse_from_Turks2.win_condition.l1 = "location";
			Pchar.quest.Back_to_Lighthouse_from_Turks2.win_condition.l1.location = "Turks";					// GR: Trigger next bit when you go to sea instead.
			Pchar.quest.Back_to_Lighthouse_from_Turks2.win_condition = "Back_to_Lighthouse_from_Turks2";

			Pchar.quest.Turks_taken_by_brotherhood.win_condition.l1 = "location";
			Pchar.quest.Turks_taken_by_brotherhood.win_condition.l1.location = "Turks";
			Pchar.quest.Turks_taken_by_brotherhood.win_condition = "Turks_taken_by_brotherhood";
		break;

		case "Back_to_Lighthouse_from_Turks2":
			PChar.Turks = "Brotherhood";
//			LAi_QuestDelay("Turks_taken_by_brotherhood", 0.0);		

			pchar.quest.return_to_lighthouse_and_Annamaria.win_condition.l1 = "location";
			pchar.quest.return_to_lighthouse_and_Annamaria.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.return_to_lighthouse_and_Annamaria.win_condition = "return_to_lighthouse_and_Annamaria";
		break;

		case "Turks_taken_by_brotherhood":
			CloseQuestHeader("The Brotherhood");
			LAi_SetSitType(characterFromID("Captain Damski"));
			ChangeCharacterAddressGroup(characterFromID("Captain Damski"), "Turks_Townhall", "sit", "sit6");

			LAi_SetSitType(characterFromID("Konrad Kulczycki"));
			ChangeCharacterAddressGroup(characterFromID("Konrad Kulczycki"), "Turks_library", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Librarian_Turks"), "none", "", ""); // PB

			ChangeCharacterAddress(characterFromID("Petros"), "None", "");

			LAi_SetHuberType(characterFromID("Nathan Kell"));
			Towns[GetTownIndex("Grand Turk")].gov = "Nathan Kell";
			ChangeCharacterAddressGroup(characterFromID("Nathan Kell"), "Turks_Townhall", "sit", "sit1");
			Characters[GetCharacterIndex("Nathan Kell")].dialog.filename = "Nathan Kell (GOV)_dialog.c";
			ChangeCharacterAddressGroup(characterFromID("Dante Siciliano"), "none", "", ""); // PB

			LAi_SetStayType(characterFromID("Thomas the Terror"));
			ChangeCharacterAddressGroup(characterFromID("Thomas the Terror"), "Turks_TailorsShop", "sit", "sit1");
			Characters[GetCharacterIndex("Thomas the Terror")].dialog.filename = "tailor_dialog.c";
			Characters[GetCharacterIndex("Thomas the Terror")].dialog.currentnode = "First time"; // PB

			if (ENABLE_WEAPONSMOD)
			{
				LAi_SetStayType(characterFromID("Jack Rackham"));
				ChangeCharacterAddressGroup(characterFromID("Jack Rackham"), "Turks_blacksmith", "goto", "goto1");
				Characters[GetCharacterIndex("Jack Rackham")].dialog.filename = "Gunsmith_dialog.c";
			}

			LAi_SetStayType(characterFromID("Peter Willemoes"));
			ChangeCharacterAddressGroup(characterFromID("Peter Willemoes"), "Turks_Store", "goto", "goto1");
			Characters[GetCharacterIndex("Peter Willemoes")].dialog.filename = "Ricardo Sanchez_dialog.c";

			ChangeCharacterAddressGroup(characterFromID("Hylie Pistof"), "Turks_Tavern", "merchant", "goto3");
			Locations[FindLocation("Turks_Tavern")].models.always.l2 = "musketoon"; // JRH

			LAi_SetSitType(characterFromID("Cap'n Drow"));
			ChangeCharacterAddressGroup(characterFromID("Cap'n Drow"), "Turks_Fort_Office", "sit", "sit1");

			LAi_SetStayType(characterFromID("John Paul Jones"));
			ChangeCharacterAddressGroup(characterFromID("John Paul Jones"), "Turks_old_Fort", "goto", "goto62");

			//LAi_SetStayType(characterFromID("Pieter Boelen"));
			//ChangeCharacterAddressGroup(characterFromID("Pieter Boelen"), "Turks_old_Fort", "goto", "goto41");

			LAi_SetStayType(characterFromID("Bartolomeu o Portugues"));
			ChangeCharacterAddressGroup(characterFromID("Bartolomeu o Portugues"), "Turks_old_Fort", "goto", "goto51");

			//LAi_SetStayType(characterFromID("Captain Maggee"));
			//ChangeCharacterAddressGroup(characterFromID("Captain Maggee"), "Turks_old_Fort", "goto", "goto72");

			//LAi_SetStayType(characterFromID("Short Jack"));
			//ChangeCharacterAddressGroup(characterFromID("Short Jack"), "Turks_old_Fort", "goto", "goto52");

			LAi_SetStayType(characterFromID("Captain Seb'"));
			ChangeCharacterAddressGroup(characterFromID("Captain Seb'"), "Turks_old_Fort", "goto", "goto43");

			ChangeCharacterAddressGroup(characterFromID("Dante Siciliano"), "None", "", "");
			ChangeCharacterAddressGroup(characterFromID("Ricardo Sanchez"), "None", "", "");
			ChangeCharacterAddressGroup(characterFromID("Josephine Bonassieu"), "None", "", "");
			ChangeCharacterAddressGroup(characterFromID("Samuel Pugh"), "None", "", "");
			ChangeCharacterAddressGroup(characterFromID("Turks_gunsmith"), "None", "", "");
		break;
//////////////// The above quest now links back to the general quest with Beckett and Barbossa

		case "Exit_Sir_Christophers_room2":
			DoQuestReloadToLocation("Oxbay_town", "reload", "Reload4", "Maximus_and_Philippe");
		break;

		case "Maximus_and_Philippe":
			DisableFastTravel(false);
			ChangeCharacterAddressGroup(characterFromID("Captain Philippe"), "Oxbay_town", "officers", "reload3_3");
			ChangeCharacterAddressGroup(characterFromID("Captain Maximus"),"Oxbay_town", "officers", "reload4_3");
			ChangeCharacterAddressGroup(characterFromID("Lieutenant Bligh"), "Oxbay_town", "officers", "Reload17_1");

			LAi_QuestDelay("Maximus_and_Philippe2", 5.0);
		break;

		case "Maximus_and_Philippe2":
			characters[GetCharacterIndex("Captain Maximus")].Dialog.Filename = "Captain Maximus_dialog.c";
			LAi_SetActorType(characterFromID("Captain Maximus"));
			Characters[GetCharacterIndex("Captain Maximus")].Dialog.CurrentNode = "Warning_message";
			LAi_ActorDialogNow(characterFromID("Captain Maximus"), Pchar, "", -1);
		break;

		case "Maximus_and_Philippe3":
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Captain Maximus"));
			SetCharacterRemovable(characterFromID("Captain Maximus"), false);
			setCharacterShipLocation(characterFromID("Captain Maximus"), "Oxbay_port");
			LAi_SetOfficerType(characterfromID("Captain Maximus"));
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Captain Philippe"));
			SetCharacterRemovable(characterFromID("Captain Philippe"), false);
			setCharacterShipLocation(characterFromID("Captain Philippe"), "Oxbay_port");
			LAi_SetOfficerType(characterfromID("Captain Philippe"));

			Group_CreateGroup("Lieutenant Bligh");
			Group_AddCharacter("Lieutenant Bligh", "Lieutenant Bligh");
//			Group_AddCharacter("Lieutenant Bligh", "Cutler Beckett");
			Group_SetGroupCommander("Lieutenant Bligh", "Lieutenant Bligh");
			Group_SetPursuitGroup("Lieutenant Bligh", PLAYER_GROUP);
			Group_SetTaskAttack("Lieutenant Bligh", PLAYER_GROUP, true);
			Group_LockTask("Lieutenant Bligh");

			Group_SetAddress("Lieutenant Bligh", "Oxbay", "Quest_Ships","Quest_Ship_7");

			Pchar.quest.Meet_Drow_and_Rackham_Again.win_condition.l1 = "location";
			PChar.quest.Meet_Drow_and_Rackham_Again.win_condition.l1.character = Pchar.id;
			Pchar.quest.Meet_Drow_and_Rackham_Again.win_condition.l1.location = "Guadeloupe_Port";
			Pchar.quest.Meet_Drow_and_Rackham_Again.win_condition = "Meet_Drow_and_Rackham_Again";
		break;

		case "Meet_Drow_and_Rackham_Again":
			ChangeCharacterAddressGroup(characterFromID("Captain Philippe"), "Guadeloupe_port", "officers", "reload1_1");
			LAi_SetOfficerType(characterfromID("Captain Philippe"));
			ChangeCharacterAddressGroup(characterFromID("Captain Maximus"), "Guadeloupe_port", "officers", "reload1_2");

			characters[GetCharacterIndex("Captain Maximus")].Dialog.Filename = "Captain Maximus_dialog.c";
			LAi_SetActorType(characterFromID("Captain Maximus"));
			LAi_ActorDialog(characterFromID("Captain Maximus"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Maximus")].dialog.currentnode = "meet_Drow&Rackham_Again";
		break;

		case "On_to_the_Guadelope_Tavern":
			LAi_SetOfficerType(characterfromID("Captain Maximus"));

			Pchar.quest.On_to_the_Guadelope_Tavern2.win_condition.l1 = "location";
			PChar.quest.On_to_the_Guadelope_Tavern2.win_condition.l1.character = Pchar.id;
			Pchar.quest.On_to_the_Guadelope_Tavern2.win_condition.l1.location = "Pointe_a_pitre_Tavern";
			Pchar.quest.On_to_the_Guadelope_Tavern2.win_condition = "On_to_the_Guadelope_Tavern2";
		break;

		case "On_to_the_Guadelope_Tavern2":
			Locations[FindLocation("Pointe_a_pitre_Tavern")].vcskip = true;
			pchar.quest.Jacks_early_days = "For_Treasure_at_Guadeloupe";
			ChangeCharacterAddressGroup(characterFromID("Lieutenant Bligh"),"Pointe_a_pitre_Tavern", "goto", "goto8");
			LAi_SetActorType(characterfromID("Lieutenant Bligh"));
			
			ChangeCharacterAddressGroup(characterFromID("Cap'n Drow"),"Pointe_a_pitre_Tavern", "goto", "goto9");
			LAi_SetActorType(characterfromID("Cap'n Drow"));
			ChangeCharacterAddressGroup(characterFromID("Jack Rackham"),"Pointe_a_pitre_Tavern", "goto", "goto2");
			LAi_SetActorType(characterfromID("Jack Rackham"));
			ChangeCharacterAddressGroup(characterFromID("Anne Bonny"),"Pointe_a_pitre_Tavern", "goto", "goto17");
			LAi_SetActorType(characterFromID("Anne Bonny"));

			ChangeCharacterAddressGroup(characterFromID("Captain Philippe"), "Pointe_a_pitre_Tavern", "goto", "goto1");
			LAi_SetOfficerType(characterfromID("Captain Philippe"));
			ChangeCharacterAddressGroup(characterFromID("Captain Maximus"), "Pointe_a_pitre_Tavern", "goto", "goto6");
			LAi_SetOfficerType(characterfromID("Captain Maximus"));
			LAi_QuestDelay("On_to_the_Guadelope_Tavern3", 5.0);
		break;

		case "On_to_the_Guadelope_Tavern3":
			characters[GetCharacterIndex("Jack Rackham")].Dialog.Filename = "Jack Rackham_dialog.c";
			LAi_SetActorType(characterFromID("Jack Rackham"));
			LAi_ActorDialog(characterFromID("Jack Rackham"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Jack Rackham")].dialog.currentnode = "meet_Guadelope_Tavern_Again";
		break;

		case "Discuss_the_Treasure_Details":
			RemoveCharacterCompanion(pchar, characterFromID("Captain Maximus"));
			RemoveCharacterCompanion(pchar, characterFromID("Captain Philippe"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Captain Maximus"));
			RemovePassenger(pchar, characterFromID("Captain Maximus"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Captain Philippe"));
			RemovePassenger(pchar, characterFromID("Captain Philippe"));
			LAi_SetActorType(characterFromID("Captain Maximus"));
			LAi_SetActorType(characterFromID("Captain Philippe"));
			LAi_SetActorType(characterFromID("Jack Rackham"));
			LAi_SetActorType(characterFromID("Anne Bonny"));
			LAi_SetActorType(characterFromID("Cap'n Drow"));
			LAi_QuestDelay("Go_Upstairs_Guadeloupe_Tavern", 0.0);
		break;

		case "Go_Upstairs_Guadeloupe_Tavern":
			LAi_ActorGoToLocator(characterFromID("Cap'n Drow"), "reload", "reload2", "",15.0);
			LAi_ActorGoToLocator(characterFromID("Anne Bonny"), "reload", "reload2", "Go_Upstairs_Guadeloupe_Tavern2",15.0);
			LAi_ActorGoToLocator(characterFromID("Captain Philippe"), "reload", "reload2", "",15.0);
			LAi_ActorGoToLocator(characterFromID("Captain Maximus"), "reload", "reload2", "",15.0);
			LAi_ActorGoToLocator(characterFromID("Jack Rackham"), "reload", "reload2", "",15.0);
		break;

		case "Go_Upstairs_Guadeloupe_Tavern2":
			ChangeCharacterAddress(characterFromID("Cap'n Drow"), "None", "");
			ChangeCharacterAddress(characterFromID("Anne Bonny"), "None", "");
			ChangeCharacterAddress(characterFromID("Captain Philippe"), "None", "");
			ChangeCharacterAddress(characterFromID("Captain Maximus"), "None", "");
			ChangeCharacterAddress(characterFromID("Jack Rackham"), "None", "");

			Pchar.quest.Waiting_on_Decision.win_condition.l1 = "location";
			PChar.quest.Waiting_on_Decision.win_condition.l1.character = Pchar.id;
			Pchar.quest.Waiting_on_Decision.win_condition.l1.location = "Guadeloupe_Port";
			Pchar.quest.Waiting_on_Decision.win_condition = "Waiting_on_Decision";
		break;

		case "Waiting_on_Decision":
			DeleteAttribute(&Locations[FindLocation("Pointe_a_pitre_Tavern")],"vcskip"); // PB

			Pchar.quest.Trap_for_not_going_to_the_Store.win_condition.l1 = "location";
			PChar.quest.Trap_for_not_going_to_the_Store.win_condition.l1.character = Pchar.id;
			Pchar.quest.Trap_for_not_going_to_the_Store.win_condition.l1.location = "Pointe_a_pitre_Tavern";
			Pchar.quest.Trap_for_not_going_to_the_Store.win_condition = "Trap_for_not_going_to_the_Store";

			Pchar.quest.going_to_the_Store_Guadeloupe.win_condition.l1 = "location";
			PChar.quest.going_to_the_Store_Guadeloupe.win_condition.l1.character = Pchar.id;
			Pchar.quest.going_to_the_Store_Guadeloupe.win_condition.l1.location = "Pointe_a_pitre_store";
			Pchar.quest.going_to_the_Store_Guadeloupe.win_condition = "going_to_the_Store_Guadeloupe";
		break;

		case "Trap_for_not_going_to_the_Store":
			Pchar.Quest.going_to_the_Store_Guadeloupe.over = "yes";

			characters[GetCharacterIndex("Lieutenant Bligh")].Dialog.Filename = "Lieutenant Bligh_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("Lieutenant Bligh"));
			Characters[GetCharacterIndex("Lieutenant Bligh")].dialog.currentnode = "meet_Bligh_in_Guadeloupe";
		break;

		case "Goodbye_to_Lieutenant Bligh":
			LAi_SetActorType(characterFromID("Lieutenant Bligh"));
			LAi_ActorGoToLocator(characterFromID("Lieutenant Bligh"), "reload", "reload1", "Goodbye_to_Lieutenant Bligh2",5.0);
		break;

		case "Goodbye_to_Lieutenant Bligh2":
			ChangeCharacterAddress(characterFromID("Lieutenant Bligh"), "None", "");
		break;
// End of game for making the wrong choice - player is now on his own.

// If player makes correct choice the following ensues
		case "going_to_the_Store_Guadeloupe":
			Pchar.Trap_for_not_going_to_the_Store.over = "yes";
			ChangeCharacterAddress(characterFromID("Lieutenant Bligh"), "None", "");

			Pchar.quest.Back_to_Tavern3_to_discuss_Plan.win_condition.l1 = "location";
			PChar.quest.Back_to_Tavern3_to_discuss_Plan.win_condition.l1.character = Pchar.id;
			Pchar.quest.Back_to_Tavern3_to_discuss_Plan.win_condition.l1.location = "Pointe_a_pitre_Tavern";
			Pchar.quest.Back_to_Tavern3_to_discuss_Plan.win_condition = "Back_to_Tavern3_to_discuss_Plan";
		break;

		case "Back_to_Tavern3_to_discuss_Plan":
			ChangeCharacterAddressGroup(characterFromID("Barbossa"),"Pointe_a_pitre_Tavern", "goto", "goto8");
			LAi_SetActorType(characterfromID("Barbossa"));

			ChangeCharacterAddressGroup(characterFromID("Captain Philippe"), "Pointe_a_pitre_Tavern", "goto", "goto2");
			LAi_SetOfficerType(characterfromID("Captain Philippe"));
			ChangeCharacterAddressGroup(characterFromID("Captain Maximus"), "Pointe_a_pitre_Tavern", "goto", "goto9");
			LAi_SetOfficerType(characterfromID("Captain Maximus"));

			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Captain Maximus"));
			SetCharacterRemovable(characterFromID("Captain Maximus"), false);
			setCharacterShipLocation(characterFromID("Captain Maximus"), "Guadeloupe_port");
			LAi_SetOfficerType(characterfromID("Captain Maximus"));
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Captain Philippe"));
			SetCharacterRemovable(characterFromID("Captain Philippe"), false);
			setCharacterShipLocation(characterFromID("Captain Philippe"), "Guadeloupe_port");
			LAi_SetOfficerType(characterfromID("Captain Philippe"));
			LAi_QuestDelay("Back_to_Tavern3_to_discuss_Plan2", 0.0);
		break;

		case "Back_to_Tavern3_to_discuss_Plan2":
			characters[GetCharacterIndex("Captain Philippe")].Dialog.Filename = "Captain Philippe_dialog.c";
			LAi_SetActorType(characterFromID("Captain Philippe"));
			LAi_ActorDialog(characterFromID("Captain Philippe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Philippe")].dialog.currentnode = "Get_ready_for_Isla_de_Muerte";
		break;

		case "Maximus_Philippe_to_Isla_de_Meurte":
//			AddQuestRecord("Aztec", 9);  // TALISMAN replaced with new Quest record Aztec 17
			AddQuestRecord("Aztec",17);
			
			if (pchar.location == "Guadeloupe_Port")
			{
				ChangeCharacterAddressGroup(characterFromID("Captain Philippe"), "Guadeloupe_Port", "officers", "Reload4_2");
				ChangeCharacterAddressGroup(characterFromID("Captain Maximus"), "Guadeloupe_Port", "officers", "Reload4_3");
				LAi_SetOfficerType(characterfromID("Captain Philippe"));
				LAi_SetOfficerType(characterfromID("Captain Maximus"));
			}
			Pchar.quest.muerte_with_Maximus_and_Philippe.win_condition.l1 = "location";
			Pchar.quest.muerte_with_Maximus_and_Philippe.win_condition.l1.location = "IslaDemuerte_shore_01";
			PChar.quest.muerte_with_Maximus_and_Philippe.win_condition = "muerte_with_Maximus_and_Philippe";
		break;

		case "muerte_with_Maximus_and_Philippe":
			ChangeCharacterAddressGroup(characterFromID("Captain Philippe"), "IslaDemuerte_shore_01", "goto", "citizen05");
			LAi_SetOfficerType(characterfromID("Captain Philippe"));
			ChangeCharacterAddressGroup(characterFromID("Captain Maximus"), "IslaDemuerte_shore_01", "goto", "citizen06");
			LAi_SetOfficerType(characterfromID("Captain Maximus"));

			Locations[FindLocation("Grotto")].locators_radius.goto.goto4 = 3.0; // PB: Easier to trigger
			Pchar.quest.Maximus_and_Philippe_on_the_Beach.win_condition.l1 = "location";
			Pchar.quest.Maximus_and_Philippe_on_the_Beach.win_condition.l1.location = "Grotto";
			PChar.quest.Maximus_and_Philippe_on_the_Beach.win_condition = "Maximus_and_Philippe_on_the_Beach";
		break;

		case "Maximus_and_Philippe_on_the_Beach":
			ChangeCharacterAddressGroup(characterFromID("Captain Philippe"), "Grotto", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Captain Maximus"), "Grotto", "goto", "goto1");	

			pchar.quest.Maximus_and_Philippe_In_the_Grotto.win_condition.l1 = "locator";
			pchar.quest.Maximus_and_Philippe_In_the_Grotto.win_condition.l1.location = "Grotto";
			pchar.quest.Maximus_and_Philippe_In_the_Grotto.win_condition.l1.locator_group = "goto";
			pchar.quest.Maximus_and_Philippe_In_the_Grotto.win_condition.l1.locator = "goto4";
			pchar.quest.Maximus_and_Philippe_In_the_Grotto.win_condition = "Maximus_and_Philippe_In_the_Grotto";
		break;

		case "Maximus_and_Philippe_In_the_Grotto":
			characters[GetCharacterIndex("Captain Maximus")].Dialog.Filename = "Captain Maximus_dialog.c";
			LAi_SetActorType(characterFromID("Captain Maximus"));
			LAi_ActorDialog(characterFromID("Captain Maximus"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Maximus")].dialog.currentnode = "We_Found_the_Motherload";
		break;

		case "Move_the_Treasure":
			characters[GetCharacterIndex("Captain Philippe")].Dialog.Filename = "Captain Philippe_dialog.c";
			LAi_SetActorType(characterFromID("Captain Philippe"));
			LAi_ActorDialog(characterFromID("Captain Philippe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Philippe")].dialog.currentnode = "Move_the_Treasure_to_XXXXX";
		break;

		case "Maximus_Philippe_to_XXXXX":
			characters[GetCharacterIndex("Captain Maximus")].Dialog.Filename = "Captain Maximus_dialog.c";
			LAi_SetActorType(characterFromID("Captain Maximus"));
			LAi_ActorDialog(characterFromID("Captain Maximus"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Maximus")].dialog.currentnode = "Going_for_the_Doctor";
		break;

		case "Philippe_and_Maximus_get_Doctor":
			RemoveCharacterCompanion(pchar, characterFromID("Captain Maximus"));
			RemoveCharacterCompanion(pchar, characterFromID("Captain Philippe"));
			LAi_ActorRunToLocator(characterFromID("Captain Philippe"), "goto", "goto12", "", 9.0);
			LAi_ActorRunToLocator(characterFromID("Captain Maximus"), "goto", "goto12", "", 9.0);

			LAi_SetActorType(pchar);
			LAi_QuestDelay("jack_confused", 2.0);
		break;

		case "jack_confused": // JS: Added to avoid long wait
			LAi_ActorGoToLocator(Pchar, "goto", "goto10", "Isla_muerta_alone", 10.0);
		break;

		case "Isla_muerta_alone":
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Isla_muerta_alone";
			LAi_ActorSelfDialog(Pchar, "Another_local_option");
		break;

		case "Another_local_option":
			LAi_SetImmortal(Pchar, true);
//			AddQuestRecord("The Brotherhood",17); // Talisman was 16 <- wrong
			AddQuestRecord("Aztec",16);				// TALISMAN - moved entry to different header - makes more sense

			ChangeCharacterAddressGroup(characterFromID("Teague Sparrow"), "IslaDeMuerte_Cabin", "goto", "locator1");
		//	ChangeCharacterAddressGroup(characterFromID("Matthew Shaw"), "IslaDeMuerte_Cabin", "sit", "sit1"); // Talisman: That's Vanderdecken's seat!
		//	LAi_SetSitType(characterfromID("Matthew Shaw")); // Talisman: That's Vanderdecken's seat!
			ChangeCharacterAddress(characterFromID("Captain Philippe"), "None", "");
			ChangeCharacterAddress(characterFromID("Captain Maximus"), "None", "");
			LAi_Fade("player_back", "");

			pchar.quest.Fight_the_Muerte_Pirates.win_condition.l1 = "location";
			PChar.quest.Fight_the_Muerte_Pirates.win_condition.l1.character = Pchar.id;
			pchar.quest.Fight_the_Muerte_Pirates.win_condition.l1.location = "IslaDemuerte_shore_01";
			pchar.quest.Fight_the_Muerte_Pirates.win_condition = "Fight_the_Muerte_Pirates";
		break;

		case "Fight_the_Muerte_Pirates":
//			AddQuestRecord("The Brotherhood",16); // Talisman moved up a case so player gets entry at treasure telling them what to do
			// PB: Normal temporary characters -->

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "mummy", "goto", "citizen01");
			sld.name = "Heumac";
			sld.lastname = "";
			LAi_group_MoveCharacter(sld, "MUERTA_ENEMIES");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "mummy", "goto", "locator13");
			sld.name = "Tezcacoatl";
			sld.lastname = "";
			LAi_group_MoveCharacter(sld, "MUERTA_ENEMIES");

			LAi_group_FightGroups("MUERTA_ENEMIES", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("MUERTA_ENEMIES", "Killed_the_Muerte_Pirates");
			// PB: Normal temporary characters <--
		break;

		case "Killed_the_Muerte_Pirates":
			Pchar.quest.Father_in_beach_ship.win_condition.l1 = "location";
			PChar.quest.Father_in_beach_ship.win_condition.l1.character = Pchar.id;
			Pchar.quest.Father_in_beach_ship.win_condition.l1.location = "IslaDeMuerte_Cabin";
			Pchar.quest.Father_in_beach_ship.win_condition = "Father_in_beach_ship";
		break;

		case "Father_in_beach_ship":
			characters[GetCharacterIndex("Teague Sparrow")].Dialog.Filename = "Teague Sparrow_dialog.c";
			LAi_SetActorType(characterFromID("Teague Sparrow"));
			LAi_ActorDialog(characterFromID("Teague Sparrow"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teague Sparrow")].dialog.currentnode = "Father_on_IslaDemuerte";
		break;

		case "Put_the_coins_back":
			Locations[FindLocation("Grotto")].locators_radius.goto.goto4 = 1.0; // PB: Back to normal
			pchar.quest.Put_the_coins_back2.win_condition.l1 = "locator";
			pchar.quest.Put_the_coins_back2.win_condition.l1.location = "Grotto";
			pchar.quest.Put_the_coins_back2.win_condition.l1.locator_group = "goto";
			pchar.quest.Put_the_coins_back2.win_condition.l1.locator = "goto4";
			pchar.quest.Put_the_coins_back2.win_condition = "Put_the_coins_back2";
		break;

		case "Put_the_coins_back2":
			LAi_SetActorType(pchar);
			LAi_QuestDelay("Put_the_coins_back3", 0.0);
		break;

		case "Put_the_coins_back3":
			pchar.quest.henry_talk = "henry_decide_on_Interceptor";

			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "puttingthecoinsback";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "Back_to_normal":
			LAi_Fade("Back_to_normal2", "");
		break;

		case "Back_to_normal2":
			GiveModel2Player("depp", true);
			LAi_SetImmortal(Pchar, false); // PB: End of the curse

			pchar.quest.Cayman_for_Philippe_and_Maximus.win_condition.l1 = "location";
			pchar.quest.Cayman_for_Philippe_and_Maximus.win_condition.l1.location = "Cayman_Port";
			pchar.quest.Cayman_for_Philippe_and_Maximus.win_condition = "Cayman_for_Philippe_and_Maximus";
		break;

		case "Cayman_for_Philippe_and_Maximus":
			ChangeCharacterAddressGroup(characterFromID("Captain Philippe"), "Cayman_Port", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Captain Maximus"), "Cayman_Port", "goto", "goto3");
			LAi_SetOfficerType(characterfromID("Captain Philippe"));
			LAi_SetOfficerType(characterfromID("Captain Maximus"));
			LAi_QuestDelay("Philippe_talks_Cayman", 1.0);
		break;

		case "Philippe_talks_Cayman":
			characters[GetCharacterIndex("Captain Philippe")].Dialog.Filename = "Captain Philippe_dialog.c";
			LAi_SetActorType(characterFromID("Captain Philippe"));
			LAi_ActorDialog(characterFromID("Captain Philippe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Philippe")].dialog.currentnode = "Report_on_the_Doctor";
		break;

		case "Go_Find_my_Ship":
			LAi_SetActorType(characterFromID("Captain Maximus"));
			LAi_ActorGoToLocator(characterFromID("Captain Philippe"), "reload", "sea", "Go_Find_my_Ship2",3.0);
			LAi_ActorGoToLocator(characterFromID("Captain Maximus"), "reload", "sea", "",3.0);
		break;

		case "Go_Find_my_Ship2":
			pchar.quest.Mings_quest_KK = "Barbossa_alternate_text";

			ChangeCharacterAddress(characterFromID("Captain Philippe"), "None", "");
			ChangeCharacterAddress(characterFromID("Captain Maximus"), "None", "");

			pchar.quest.Philippe_and_Maximus_route = "trouble_with_the_ladies";

			pchar.quest.Turks_with_KK.win_condition.l1 = "location";
			pchar.quest.Turks_with_KK.win_condition.l1.location = "Turks_port";
			pchar.quest.Turks_with_KK.win_condition = "Turks_with_KK";
		break;
//Joins back to get captured by Beckett

//Traps for not going to lighthouse first.
		case "Straight_to_Beckett_Capture":
			CloseQuestHeader("The Brotherhood");
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"HMS_Bounty","Lindesfarne",ENGLAND,-1,true,true);
			Pchar.Quest.Oxbay_to_Beckett_Capture.over = "yes";
			Pchar.Quest.Brotherhood_lighthouse_and_Annamaria.over = "yes";
			Locations[FindLocation("Greenford_port")].vcskip = true;
			StorePassengers(PChar.id);
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(characterFromID("Cutler Beckett"), "Greenford_port", "goto", "goto21");
			ChangeCharacterAddressGroup(characterFromID("Eng_soldier_38"), "Greenford_port", "goto", "goto19");
			ChangeCharacterAddressGroup(characterFromID("Eng_soldier_39"), "Greenford_port", "goto", "goto20");

			characters[GetCharacterIndex("Cutler Beckett")].Dialog.Filename = "Cutler Beckett_dialog.c";
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorDialog(characterFromID("Cutler Beckett"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "Lazy_Captured_on_Oxbay";
		break;

		case "Oxbay_to_Beckett_Capture":
			CloseQuestHeader("The Brotherhood");
			Pchar.Quest.Straight_to_Beckett_Capture.over = "yes";
			Pchar.Quest.Brotherhood_lighthouse_and_Annamaria.over = "yes";
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"HMS_Bounty","Lindesfarne",ENGLAND,-1,true,true);
			Locations[FindLocation("Oxbay_port")].vcskip = true;
			StorePassengers(PChar.id);
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(characterFromID("Cutler Beckett"), "Oxbay_port", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Eng_soldier_39"), "Oxbay_port", "officers", "reload2_1");

			characters[GetCharacterIndex("Cutler Beckett")].Dialog.Filename = "Cutler Beckett_dialog.c";
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorDialog(characterFromID("Cutler Beckett"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "Lazy_Captured_on_Oxbay";
		break;

		case "Deserters Jail":
			DoQuestReloadToLocation("Redmond_prison", "goto", "goto9", "Deserters Jail2");
//			DoQuestReloadToLocation("Greenford_prison", "goto", "goto9", "_");
			ChangeCharacterAddressGroup(characterfromID("Eng_soldier_5"),"Redmond_prison", "goto", "goto23");
			Locations[FindLocation("Redmond_prison")].vcskip = true;
		break;

		case "Deserters Jail2":
			LAi_SetActorType(characterFromID("Eng_soldier_5"));
			characters[GetCharacterIndex("Eng_soldier_5")].Dialog.Filename = "Port Guard_dialog.c";
			characters[GetCharacterIndex("Eng_soldier_5")].dialog.currentnode = "the Hanging";
			LAi_ActorDialogNow(characterFromID("Eng_soldier_5"), pchar, "", -1);
		break;

		case "hung at dawn":
			pchar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "mutiny");
		break;
// End Traps for not going tp Lighthouse first

// Trap quest starts here vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
		case "Captured_on_Guadeloupe":
			Locations[FindLocation("Guadeloupe_Jungle_03")].reload.l2.disable = 0;
			Locations[FindLocation("Guadeloupe_Jungle_03")].reload.l4.disable = 0;
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			Pchar.Quest.Get_to_meet_Petros.over = "yes";
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			PostVideoAndQuest("KnockedOut", 25, "Into_French_Prison");
			bMainMenuLaunchAfterVideo = true;
		break;

		case "Into_French_prison":
			pchar.quest.Jacks_early_days = "In_Prison_on_Guadeloupe";
			PostEvent("DoInfoShower",100,"s","");
			Locations[FindLocation("PaP_prison")].vcskip = true;
			LAi_SetActorType(characterfromID("Cap'n Drow"));
			DoQuestReloadToLocation("PaP_prison", "goto", "goto9", "_");
			ChangeCharacterAddressGroup(characterfromID("Cap'n Drow"),"PaP_prison", "goto", "goto12");
			LAi_ActorAnimation(characterFromID("Cap'n Drow"), "Ground_StandUp", "Into_French_Prison2", 1.0);
		break;

		case "Into_French_Prison2":
			pchar.quest.Jacks_early_days = "In_Prison_on_Guadeloupe";
			LAi_ActorGoToLocator(characterFromID("Cap'n Drow"), "reload", "reload12", "",5.0);
			characters[GetCharacterIndex("Cap'n Drow")].Dialog.Filename = "Cap'n Drow_dialog.c";
			LAi_SetActorType(characterFromID("Cap'n Drow"));
			LAi_ActorDialog(characterFromID("Cap'n Drow"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Cap'n Drow")].dialog.currentnode = "First time";
		break;

		case "Get_off_Guadeloupe":
			LAi_Fade("Get_off_Guadeloupe_2", "Get_off_Guadeloupe_3");
		break;

		case "Get_off_Guadeloupe_2":
			GiveShip2Character(pchar,"FR_Boussole","Cutlass",-1,FRANCE,true,true);
			SetCharacterShipLocation(Pchar, "Guadeloupe_Port");
			EquipCharacterByItem(pchar, "bladeX4");
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Cap'n Drow"));
		break;

		case "Get_off_Guadeloupe_3":
			pchar.Turks = "Drow";
			LAi_SetOfficerType(characterFromID("Cap'n Drow"));
			ChangeCharacterAddressGroup(characterfromID("Cap'n Drow"),"PaP_prison", "goto", "goto23");
			ChangeCharacterAddressGroup(PChar,"PaP_prison", "goto", "goto12");
			
//TALISMAN - VVVVVVV - CHANGED so that after capture on Guadeloupe - go to search for Kell NOT capture by Beckett at Lighthouse VVVVVVVVVVV
//			pchar.quest.Turks_with_KK.win_condition.l1 = "location";
//			pchar.quest.Turks_with_KK.win_condition.l1.location = "Turks_port";
//			pchar.quest.Turks_with_KK.win_condition = "Turks_with_KK";

			ChangeCharacterAddressGroup(characterfromID("Stephen Walsh"), "Guadeloupe_port", "goto", "goto10");
			ChangeCharacterAddressGroup(characterfromID("Arthur Straightly"), "Guadeloupe_port", "goto", "goto11");
			ChangeCharacterAddressGroup(characterfromID("William Wanderman"), "Guadeloupe_port", "officers", "houseS1_2");
			LAi_QuestDelay("Fight_PaP_EITC_2", 10.0);

			pchar.quest.Turks_with_Drow.win_condition.l1 = "location";
			pchar.quest.Turks_with_Drow.win_condition.l1.location = "Turks_port";
			pchar.quest.Turks_with_Drow.win_condition = "Turks_with_Drow";
		break;
		
		case "Fight_PaP_EITC_2":		
			LAi_SetActorType(characterFromID("Arthur Straightly"));
			LAi_SetActorType(characterFromID("Stephen Walsh"));
			LAi_SetActorType(characterFromID("William Wanderman"));

			LAi_SetImmortal(characterFromID("Arthur Straightly"), true);
			LAi_SetImmortal(characterFromID("Stephen Walsh"), true);
			LAi_SetImmortal(characterFromID("William Wanderman"), true);
// 			LAi_ActorDialog(characterFromID("Stephen Walsh"), pchar, "", 6.0, 1.0); // Original numbers
			LAi_ActorDialog(characterFromID("Stephen Walsh"), pchar, "", 12.0, 1.0);
			characters[GetCharacterIndex("Stephen Walsh")].Dialog.Filename = "Stephen Walsh_dialog.c";
			Characters[GetCharacterIndex("Stephen Walsh")].dialog.currentnode = "EITC_on_Guadeloupe";
//			LAi_QuestDelay("Fight_PaP_EITC_3", 10.0);
		break;

		case "Fight_Pap_EITC_3":
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(Pchar, true);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_ActorAttack(characterfromID("Arthur Straightly"), pchar, "");
			LAi_ActorAttack(characterfromID("Stephen Walsh"), pchar, "");
			LAi_ActorAttack(characterFromID("William Wanderman"), pchar, "");
			LAi_QuestDelay("Fight_PaP_EITC_4", 10.0);
		break;

		case "Fight_PaP_EITC_4":
			LAi_SetImmortal(Pchar, false);

			PChar.quest.Killed_PaP_FightingEITC.win_condition.l1 = "NPC_Death";
			PChar.quest.Killed_PaP_FightingEITC.win_condition.l1.character = PChar.id;
			PChar.quest.Killed_PaP_FightingEITC.win_condition = "Killed_PaP_FightingEITC";
		break;

		case "Killed_PaP_FightingEITC":
			pchar.quest.disable_rebirth = true
			PostEvent("LAi_event_GameOver", 0, "s", "land");
		break;
		
		case "Turks_with_Drow":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			
			ChangeCharacterAddress(characterfromID("Arthur Straightly"),"none", "");
			ChangeCharacterAddress(characterfromID("Stephen Walsh"),"none", "");
			ChangeCharacterAddress(characterfromID("William Wanderman"),"none", "");

//			ChangeCharacterAddressGroup(characterfromID("Konrad Kulczycki"), "Turks_port", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterfromID("Petros"), "Turks_port", "officers", "reload1_3");
//			ChangeCharacterAddressGroup(characterfromID("Nathan Kell"), "Turks_port", "officers", "reload1_2");
//			ChangeCharacterAddressGroup(characterfromID("Captain Damski"), "Turks_port", "goto", "P_goto2");			//JRH: new Turks, was goto2

//			LAi_SetOfficerType(characterFromID("Captain Damski"));
			LAi_SetOfficerType(characterFromID("Petros"));
//			LAi_SetCivilianGuardianType(characterFromID("Konrad Kulczycki"));
//			LAi_SetCivilianGuardianType(characterFromID("Petros"));
//			LAi_SetCivilianGuardianType(characterFromID("Captain Damski"));
//			LAi_SetCivilianGuardianType(characterFromID("Nathan Kell"));
			if (GetAttribute(PChar, "Turks") == "Drow"){LAi_SetCivilianGuardianType(characterFromID("Cap'n Drow"));}

			LAi_QuestDelay("Turks_with_Drow2", 3.0);
		break;

		case "Turks_with_Drow2":
//			characters[GetCharacterIndex("Captain Damski")].Dialog.Filename = "Captain Damski_dialog.c";
//			LAi_SetActorType(characterFromID("Captain Damski"));
//			LAi_ActorDialog(characterFromID("Captain Damski"),PChar,"",5.0,5.0);
//			Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "meet_in_Turks";
			characters[GetCharacterIndex("Petros")].Dialog.Filename = "Petros_dialog.c";
			LAi_SetActorType(characterFromID("Petros"));
			LAi_ActorDialog(characterFromID("Petros"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Petros")].dialog.currentnode = "Turks_after_Guadeloupe_capture";
		break;
		
// TALISMAN - END OF CHANGES ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	
//Temp... Will be putting in sidequest to make it longer

//Re-Do Mings quest if player did not pick up map on first visit to Antigua vvvvvvvvvvvvvvvvvvv
		case "Back_to_Antigua_for_Map":
			//DoQuestReloadToLocation("Oxbay_town", "reload", "reload4", "Second_chance_with_Ming");
			LAi_QuestDelay("Second_chance_with_Ming", 0.0);
		break;

		case "Second_chance_with_Ming":
			Pchar.quest.Second_Mings_Map_quest.win_condition.l1 = "item";
			Pchar.quest.Second_Mings_Map_quest.win_condition.l1.item = "Map_Doc_1";
			Pchar.quest.Second_Mings_Map_quest.win_condition.l2 = "location";
			PChar.quest.Second_Mings_Map_quest.win_condition.l2.character = Pchar.id;
			Pchar.quest.Second_Mings_Map_quest.win_condition.l2.location = "Oxbay_town";
			Pchar.quest.Second_Mings_Map_quest.win_condition = "Second_Mings_Map_quest";
		break;

		case "Second_Mings_Map_quest":
			/*pchar.quest.ReJoin_The_Brotherhood.win_condition.l1 = "locator";
			pchar.quest.ReJoin_The_Brotherhood.win_condition.l1.location = "Oxbay_town";
			pchar.quest.ReJoin_The_Brotherhood.win_condition.l1.locator_group = "reload";
			pchar.quest.ReJoin_The_Brotherhood.win_condition.l1.locator = "reload4";
			pchar.quest.ReJoin_The_Brotherhood.win_condition = "ReJoin_The_Brotherhood";*/
			pchar.quest.ReJoin_The_Brotherhood.win_condition.l1 = "location";
			pchar.quest.ReJoin_The_Brotherhood.win_condition.l1.location = "Mings_townhall";
			pchar.quest.ReJoin_The_Brotherhood.win_condition = "ReJoin_The_Brotherhood";

			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 0;
		break;

		case "ReJoin_The_Brotherhood":
			pchar.quest.Jacks_early_days = "Got_the_Magic_Compass";
			ChangeCharacterReputation(pchar, +2);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			//ChangeCharacterAddress(characterFromID("Jacinto Arcibaldo Barreto"), "None", "");
			//ChangeCharacterAddressGroup(characterFromID("Sir Christopher Mings"), "Conceicao_townhall", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Sir Christopher Mings"), "Mings_townhall", "sit", "sit1");
			LAi_SetSitType(characterfromID("Sir Christopher Mings"));
			pchar.quest.Jacks_early_days = "Mings_second_compass_meeting";
			//DoQuestReloadToLocation("Conceicao_townhall", "Reload", "Reload1", "_");
		break;

		case "End_of_Mings_Quest":
			pchar.quest.Jacks_early_days = "trouble_with_the_ladies";
			ChangeCharacterAddress(characterFromID("Sir Christopher Mings"), "None", "");
			LAi_SetActorType(characterFromID("Annabella Brinkley"));
			LAi_SetOfficerType(characterFromID("Annabella Brinkley"));
			ChangeCharacterAddressGroup(CharacterFromID("Annabella Brinkley"),"Oxbay_town", "Officers", "Reload4_3");
			LAi_SetActorType(characterFromID("Annabella Brinkley"));
			//DoQuestReloadToLocation("Oxbay_town", "Officers", "Reload4_2", "On_to_the_Tailors3");
			Pchar.quest.On_to_the_Tailors3.win_condition.l1 = "location";
			Pchar.quest.On_to_the_Tailors3.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.On_to_the_Tailors3.win_condition = "On_to_the_Tailors3";

			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 1;
		break;

// Player can restart Brin Quest here as Brinkley finds player
		case "The_sisters_found":
			Pchar.quest.Barbossa_and_Brock_search.over = "yes";
			/*ChangeCharacterAddress(characterFromID("Jacinto Arcibaldo Barreto"), "None", "");
			ChangeCharacterAddressGroup(characterfromID("Annabella Brin"), "Conceicao_townhall", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Bella Brin"), "Conceicao_townhall", "goto", "goto1");
			ChangeCharacterAddressGroup(characterfromID("Billy Brock"), "Conceicao_townhall", "goto", "goto7");*/
			ChangeCharacterAddressGroup(characterfromID("Annabella Brin"), "Mings_townhall", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Bella Brin"), "Mings_townhall", "goto", "goto1");
			ChangeCharacterAddressGroup(characterfromID("Billy Brock"), "Mings_townhall", "goto", "goto7");
			LAi_SetActorType(characterFromID("Annabella Brin"));
			LAi_SetActorType(characterFromID("Billy Brock"));
			//DoQuestReloadToLocation("Conceicao_townhall", "Reload", "Reload1", "Fight_with_Billy_Brock");
			LAi_QuestDelay("Fight_with_Billy_Brock", 0.0);
		break;

		case "Fight_with_Billy_Brock":
			characters[GetCharacterIndex("Billy Brock")].Dialog.Filename = "Billy Brock_dialog.c";
			LAi_SetActorType(characterFromID("Billy Brock"));
			LAi_ActorDialog(characterFromID("Billy Brock"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Billy Brock")].dialog.currentnode = "The_Brock_fight_Oxbay";
		break;

		case "Brock_is_Killed":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetFightMode(PChar, true);
			LAi_SetActorType(characterFromID("Billy Brock"));
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(Pchar, false);
			LAi_ActorAttack(characterfromID("Billy Brock"), pchar, "");

			pchar.quest.Billy_Brock_died.win_condition.l1 = "NPC_Death";
			pchar.quest.Billy_Brock_died.win_condition.l1.character = "Billy Brock";
			pchar.quest.Billy_Brock_died.win_condition = "Billy_Brock_died";

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Billy_Brock_died":
			//ChangeCharacterAddressGroup(characterfromID("John Clifford Brin"), "Conceicao_townhall", "reload", "reload1");
			//ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "Conceicao_townhall", "goto", "goto5");
			ChangeCharacterAddressGroup(characterfromID("John Clifford Brin"), "Mings_townhall", "reload", "reload1");
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "Mings_townhall", "goto", "goto5");
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "I_found_the_Governor";
		break;

		case "Meet_Governor_Brin":
			LAi_SetActorType(characterFromID("John Clifford Brin"));
			LAi_ActorGoToLocator(characterFromID("John Clifford Brin"), "goto", "goto2", "Meet_Governor_Brin2", 5.0);
			AddPassenger(Pchar, characterFromID("Susan Shaypen"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Susan Shaypen"));
			LAi_SetOfficerType(characterFromID("Susan Shaypen"));
		break;

		case "Meet_Governor_Brin2":
			LAi_ActorGoToLocator(characterFromID("John Clifford Brin"), "sit", "sit1", "", 5.0);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "goto7", "", 5.0);
			LAi_QuestDelay("Meet_Governor_Brin3", 0.0);
		break;

		case "Meet_Governor_Brin3":
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("John Clifford Brin")].Dialog.Filename = "John Clifford Brin_dialog.c";
			LAi_SetActorType(characterFromID("John Clifford Brin"));
			LAi_ActorDialog(characterFromID("John Clifford Brin"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.currentnode = "Reward_for_daughters_Oxbay";
		break;

		case "Leave_Brin_Oxbay":
			CloseQuestHeader("My Early Days");
			RemoveOfficersIndex(pchar, GetCharacterIndex("Susan Shaypen"));
			RemovePassenger(pchar, characterFromID("Susan Shaypen"));
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "Oxbay_town", "Officers", "Reload4_3");
			PChar.Annamaria = "Oxbay";

			Pchar.Quest.On_to_the_Tailors2.over = "yes";
			Pchar.Quest.to_find_a_sister.over = "yes";
			Pchar.Quest.to_find_a_sisterA.over = "yes";
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brin"));
			RemovePassenger(pchar, characterFromID("Annabella Brin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brinkley"));
			RemovePassenger(pchar, characterFromID("Annabella Brinkley"));
			RemoveCharacterCompanion(pchar, characterFromID("Annabella Brinkley"));
			ChangeCharacterAddress(characterFromID("Annabella Brinkley"), "None", "");
			//DoQuestReloadToLocation("Oxbay_town", "Officers", "Reload4_2", "Get_map_and_diamonds");
			Pchar.quest.Get_map_and_diamonds.win_condition.l1 = "location";
			Pchar.quest.Get_map_and_diamonds.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Get_map_and_diamonds.win_condition = "Get_map_and_diamonds";

			Locations[FindLocation("Oxbay_town")].reload.l15.disable = 1;
		break;

		case "Get_map_and_diamonds":
			Pchar.Quest.On_to_the_Tailors2.over = "yes";
			Pchar.Quest.to_find_a_sister.over = "yes";
			Pchar.Quest.to_find_a_sisterA.over = "yes";
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brin"));
			RemovePassenger(pchar, characterFromID("Annabella Brin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brinkley"));
			RemovePassenger(pchar, characterFromID("Annabella Brinkley"));
			RemoveCharacterCompanion(pchar, characterFromID("Annabella Brinkley"));
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "Oxbay_town", "Officers", "Reload4_3");
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Joins_the_Governor";
		break;

		case "My_new_ship_Oxbay":
			LAi_ActorGoToLocator(characterFromID("Susan Shaypen"), "reload", "reload4", "My_new_ship_Oxbay2", 5.0);
		break;

		case "My_new_ship_Oxbay2":
			ChangeCharacterAddress(characterFromID("Susan Shaypen"), "None", "");

			if (GetAttribute(PChar, "Annamaria") != "Lighthouse")
			{
				ChangeCharacterAddressGroup(characterfromID("Annamaria"), "Oxbay_town", "goto", "goto9");

				if (GetAttribute(PChar, "Annamaria") != "Oxbay")
				{
					pchar.quest.Meet_Annamaria_Oxbay.win_condition.l1 = "location";
					pchar.quest.Meet_Annamaria_Oxbay.win_condition.l1.character = Pchar.id;
					pchar.quest.Meet_Annamaria_Oxbay.win_condition.l1.location = "Oxbay_town";
					pchar.quest.Meet_Annamaria_Oxbay.win_condition = "Meet_Annamaria_Oxbay";
				}
				else
				{
					LAi_QuestDelay("Meet_Annamaria_Oxbay", 0.0);
				}
			}
			if (GetAttribute(PChar, "Beckett") != "Working")
			{
				Pchar.quest.Slave_meet_with_Cutler_Beckett.win_condition.l1 = "location";
				PChar.quest.Slave_meet_with_Cutler_Beckett.win_condition.l1.character = Pchar.id;
				Pchar.quest.Slave_meet_with_Cutler_Beckett.win_condition.l1.location = "Oxbay_tavern";
				Pchar.quest.Slave_meet_with_Cutler_Beckett.win_condition = "Slave_meet_with_Cutler_Beckett";
			}
		break;

		case "Meet_Annamaria_Oxbay":
			AddQuestRecord("Mystery Woman", 9);
			CloseQuestHeader("Mystery Woman");
			characters[GetCharacterIndex("Annamaria")].Dialog.Filename = "Annamaria_dialog.c";
			LAi_SetActorType(characterFromID("Annamaria"));
			LAi_ActorDialog(characterFromID("Annamaria"),PChar,"",100.0,100.0);
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "Talk_Annamaria_Oxbay";
		break;

		case "Annamaria_leaves_Oxbay":
			LAi_SetActorType(characterFromID("Annamaria"));
			LAi_ActorRunToLocator(characterFromID("Annamaria"), "reload", "reload1", "Annamaria_leaves_Oxbay2", 3.0);
		break;

		case "Annamaria_leaves_Oxbay2":
			ChangeCharacterAddress(characterFromID("Annamaria"), "None", "");

			pchar.quest.straight_to_lighthouse_and_Annamaria.win_condition.l1 = "location";
			pchar.quest.straight_to_lighthouse_and_Annamaria.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.straight_to_lighthouse_and_Annamaria.win_condition = "straight_to_lighthouse_and_Annamaria";
		break;

		case "Slave_meet_with_Cutler_Beckett":
			Locations[FindLocation("Oxbay_tavern")].reload.l1.disable = 1;
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"), "Oxbay_tavern", "goto", "goto21");
			characters[GetCharacterIndex("Cutler Beckett")].Dialog.Filename = "Cutler Beckett_dialog.c";
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorDialog(characterFromID("Cutler Beckett"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "Oxbay_meet_after_Brin";
		break;

		case "Looking_for_sisters":
			DisableFastTravel(true);
            DeleteAttribute(pchar,"Sidetrack3");
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "QC_port", "goto", "goto4");
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			LAi_QuestDelay("Looking_for_sisters2", 3.0);
		break;

		case "Looking_for_sisters2":
			LAi_ActorWaitDialog(PChar,characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			if (checkquestattribute("Susan_Shaypen_Quests", "Shaypen_with_Boat"))
			{
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Found_Shaypen";
			}else{
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Susan_on_QC_Dock";
			}
		break;

		case "Swordfight_on_Dock":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetFightMode(PChar, true);
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(Pchar, false);
			LAi_ActorAttack(characterfromID("Susan Shaypen"), pchar, "");

			pchar.quest.Shaypen_died.win_condition.l1 = "NPC_Death";
			pchar.quest.Shaypen_died.win_condition.l1.character = "Susan Shaypen";
			pchar.quest.Shaypen_died.win_condition = "Shaypen_died";

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Shaypen_died":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
            DeleteAttribute(pchar,"KilledFighting");
			AddQuestRecord("Mystery Woman",4);
			pchar.quest.Jacks_early_days = "Ines_Diaz_Discussion";
			LAi_QuestDelay("Back_to_the_Brin_Search", 0.0);

			DisableFastTravel(false);
		break;

		case "KilledFighting":
            pchar.quest.disable_rebirth = true;
            PostEvent("LAi_event_GameOver", 0, "s", "land");
		break;

		case "Back_to_the_Brin_Search":
			/*pchar.quest.Back_to_the_Brin_Search2.win_condition.l1 = "locator";
			PChar.quest.Back_to_the_Brin_Search2.win_condition.l1.character = Pchar.id;
			pchar.quest.Back_to_the_Brin_Search2.win_condition.l1.location = "QC_port";
			pchar.quest.Back_to_the_Brin_Search2.win_condition.l1.locator_group = "reload";
			pchar.quest.Back_to_the_Brin_Search2.win_condition.l1.locator = "reload3_back";
			pchar.quest.Back_to_the_Brin_Search2.win_condition = "Back_to_the_Brin_Search2";*/
			pchar.quest.Back_to_the_Brin_Search2.win_condition.l1 = "location";
			PChar.quest.Back_to_the_Brin_Search2.win_condition.l1.character = Pchar.id;
			pchar.quest.Back_to_the_Brin_Search2.win_condition.l1.location = "QC_Tavern";
			pchar.quest.Back_to_the_Brin_Search2.win_condition = "Back_to_the_Brin_Search2";
		break;

		case "Back_to_the_Brin_Search2":
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "QC_tavern_upstairs", "goto", "goto3");
			ChangeCharacterAddressGroup(characterfromID("Bella Brin"), "QC_tavern_upstairs", "goto", "goto2");

			//Pchar.quest.On_the_trail.win_condition.l1 = "location";
			//PChar.quest.On_the_trail.win_condition.l1.character = Pchar.id;
			//Pchar.quest.On_the_trail.win_condition.l1.location = "QC_Tavern";
			//Pchar.quest.On_the_trail.win_condition = "On_the_trail";
		break;

		/*case "On_the_trail":
			ChangeCharacterAddressGroup(characterFromID("Susan Shaypen"), "QC_Tavern", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Susan Shaypen"), "none", "", "");

			RemovePassenger(Pchar, characterFromID("Susan Shaypen"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Susan Shaypen"));

			AddPassenger(Pchar, characterFromID("Susan Shaypen"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Susan Shaypen"));
			LAi_SetOfficerType(characterFromID("Susan Shaypen"));
		break;*/

		case "Susan_to_Skull":
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Who_is_the_Big_Man";
		break;

		case "Go_see_Skull":
			LAi_SetActorType(characterFromID("Ines Diaz"));
			LAi_ActorGoToLocation(characterFromID("Ines Diaz"), "merchant", "reload3", "none", "", "", "", 5.0);
			pchar.quest.Jacks_early_days = "Words_from_Skull";

			Pchar.quest.Go_see_Skull2.win_condition.l1 = "location";
			PChar.quest.Go_see_Skull2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Go_see_Skull2.win_condition.l1.location = "QC_Residence";
			Pchar.quest.Go_see_Skull2.win_condition = "Go_see_Skull2";
		break;

		case "Go_see_Skull2":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "goto2", "Go_see_Skull3", 10.0);
		break;

		case "Go_see_Skull3":
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "QC_Residence", "goto", "goto4");
			ChangeCharacterAddressGroup(characterfromID("Annabella Brinkley"), "QC_Residence", "goto", "goto3");
			ChangeCharacterAddressGroup(characterfromID("Ines Diaz"), "QC_Tavern", "merchant", "goto1");
			LAi_SetBarmanType(characterfromID("Ines Diaz"));
			characters[GetCharacterIndex("Annabella Brinkley")].Dialog.Filename = "Annabella Brin_dialog.c";
			LAi_SetActorType(characterFromID("Annabella Brinkley"));
			LAi_ActorDialog(characterFromID("Annabella Brinkley"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Annabella Brinkley")].dialog.currentnode = "Visit_the_Big_Man";
			pchar.quest.Susan_Shaypen_Quests = "Ines_Diaz_with_Susan_Finished";
		break;

		case "Skull_joins_in":
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Shock_at_being_left";
		break;

		case "Skull_joins_in2":
			characters[GetCharacterIndex("Isenbrandt Jurcksen")].Dialog.Filename = "Skull_dialog.c";
			LAi_SetActorType(characterFromID("Isenbrandt Jurcksen"));
			LAi_ActorDialog(characterFromID("Isenbrandt Jurcksen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Isenbrandt Jurcksen")].dialog.currentnode = "first time";
		break;

		case "Round_the_Room":
			LAi_ActorGoToLocator(characterFromID("Annabella Brinkley"), "reload", "reload1", "Brinkley_leaves", 10.0);
		break;

		case "Brinkley_leaves":
			ChangeCharacterAddress(characterFromID("Annabella Brinkley"), "None", "");
			pchar.quest.Jacks_early_days = "More_Words_from_Skull";
			characters[GetCharacterIndex("Isenbrandt Jurcksen")].Dialog.Filename = "Skull_dialog.c";
			LAi_SetActorType(characterFromID("Isenbrandt Jurcksen"));
			LAi_ActorDialog(characterFromID("Isenbrandt Jurcksen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Isenbrandt Jurcksen")].dialog.currentnode = "first time";
		break;

		case "Skull_not_Happy":
			LAi_ActorGoToLocator(characterFromID("Isenbrandt Jurcksen"), "reload", "reload1", "Skull_leaves", 10.0);
		break;

		case "Skull_leaves":
			ChangeCharacterAddress(characterFromID("Isenbrandt Jurcksen"), "None", "");
			LAi_QuestDelay("Skull_leaves2", 0.0);
		break;

		case "Skull_leaves2":
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "What_are_you_up_to";
		break;

		case "Skull_comes_back":
			ChangeCharacterAddressGroup(characterfromID("Isenbrandt Jurcksen"), "QC_Residence", "reload", "reload1");
			pchar.quest.Jacks_early_days = "Ready_for_sea";
			characters[GetCharacterIndex("Isenbrandt Jurcksen")].Dialog.Filename = "Skull_dialog.c";
			LAi_SetActorType(characterFromID("Isenbrandt Jurcksen"));
			LAi_ActorDialog(characterFromID("Isenbrandt Jurcksen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Isenbrandt Jurcksen")].dialog.currentnode = "first time";
		break;

		case "Now_to_ships":
			LAi_ActorGoToLocator(characterFromID("Isenbrandt Jurcksen"), "goto", "goto1", "", 10.0);
			// PB: Set him back to normal -->
			LAi_SetWarriorType(characterfromID("Isenbrandt Jurcksen"));
			LAi_warrior_DialogEnable(characterfromID("Isenbrandt Jurcksen"), true);
			LAi_warrior_SetStay(characterfromID("Isenbrandt Jurcksen"), true);
			// PB: Set him back to normal <--

			SetOfficersIndex(Pchar, 2, getCharacterIndex("Bella Brin"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Annabella Brin"));
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Annabella Brinkley"));
			SetCharacterRemovable(characterFromID("Bella Brin"), false);
			SetCharacterRemovable(characterFromID("Annabella Brin"), false);
			SetCharacterRemovable(characterFromID("Annabella Brinkley"), false);
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "QC_Town", "goto", "goto15");
			LAi_QuestDelay("Back_to_Bridgetown", 0.0);
		break;

		case "Back_to_Bridgetown":
			characters[GetCharacterIndex("Annabella Brinkley")].Dialog.Filename = "Annabella Brin_dialog.c";
			LAi_SetActorType(characterFromID("Annabella Brinkley"));
			LAi_ActorDialog(characterFromID("Annabella Brinkley"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Annabella Brinkley")].dialog.currentnode = "To_sea_to_sea";
		break;

		case "Saved_the_sisters":
			Pchar.quest.Saved_the_sisters2.win_condition.l1 = "location";
			PChar.quest.Saved_the_sisters2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Saved_the_sisters2.win_condition.l1.location = "QC_port";
			Pchar.quest.Saved_the_sisters2.win_condition = "Saved_the_sisters2";
		break;

		case "Saved_the_sisters2":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			SetCharacterRemovable(characterFromID("Annabella Brinkley"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brinkley"));
			RemovePassenger(pchar, characterFromID("Annabella Brinkley"));
			ChangeCharacterAddress(characterFromID("Annabella Brinkley"), "none", "");

			Pchar.quest.Go_see_Prison_Commander.win_condition.l1 = "location";
			PChar.quest.Go_see_Prison_Commander.win_condition.l1.character = Pchar.id;
			Pchar.quest.Go_see_Prison_Commander.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Go_see_Prison_Commander.win_condition = "Go_see_Prison_Commander";
		break;

		case "Go_see_Prison_Commander":
			DisableFastTravel(false);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "Greenford_port", "goto", "goto20");
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Part_company_for_now";
		break;

		case "Jamaica_bound":
			LAi_ActorGoToLocation(characterFromID("Susan Shaypen"), "reload", "reload2", "none", "", "", "", 20.0);
		//break;

		//case "Jamaica_bound2":
			//ChangeCharacterAddress(characterFromID("Susan Shaypen"), "none", "");
			RemoveOfficersIndex(pchar, GetCharacterIndex("Susan Shaypen"));
			RemovePassenger(pchar, characterFromID("Susan Shaypen"));

			Pchar.quest.Meet_Governor_Brin_Redmond.win_condition.l1 = "location";
			PChar.quest.Meet_Governor_Brin_Redmond.win_condition.l1.character = Pchar.id;
			Pchar.quest.Meet_Governor_Brin_Redmond.win_condition.l1.location = "Redmond_residence";
			Pchar.quest.Meet_Governor_Brin_Redmond.win_condition = "Meet_Governor_Brin_Redmond";
		break;

		case "Meet_Governor_Brin_Redmond":
			Pchar.Quest.Meet_Governor_Brin_Redmond.over = "yes";
			Pchar.Quest.Meet_Governor_Brin_RedmondA.over = "yes";
			CloseQuestHeader("My Early Days");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			SetCharacterRemovable(characterFromID("Bella Brin"), true);
			SetCharacterRemovable(characterFromID("Annabella Brin"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brin"));
			RemovePassenger(pchar, characterFromID("Annabella Brin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bella Brin"));
			RemovePassenger(pchar, characterFromID("Bella Brin"));
			LAi_SetActorType(characterFromID("Bella Brin"));
			LAi_SetActorType(characterFromID("Annabella Brin"));
//			ChangeCharacterAddressGroup(characterfromID("John Clifford Brin"), "Redmond_residence", "goto", "goto8");
			ChangeCharacterAddressGroup(characterfromID("Bella Brin"), "Redmond_residence", "goto", "goto4");
			ChangeCharacterAddressGroup(characterfromID("Annabella Brin"), "Redmond_residence", "goto", "goto6");
			LAi_QuestDelay("Meet_Governor_Brin2Red", 0.0);
		break;

		case "Meet_Governor_Brin2Red":
			LAi_ActorRunToLocator(characterFromID("Bella Brin"), "goto", "goto9", "", 5.0);
			LAi_ActorRunToLocator(characterFromID("Annabella Brin"), "goto", "goto2", "Meet_Governor_Brin3Red", 5.0);
		break;

		case "Meet_Governor_Brin3Red":
			LAi_ActorRunToLocator(characterFromID("Bella Brin"), "reload", "reload3", "", 3.0);
			LAi_ActorRunToLocator(characterFromID("Annabella Brin"), "reload", "reload3", "Meet_Governor_Brin4Red", 4.0);
		break;

		case "Meet_Governor_Brin4Red":
			ChangeCharacterAddress(characterFromID("Bella Brin"), "none", "");
			ChangeCharacterAddress(characterFromID("Annabella Brin"), "none", "");
			characters[GetCharacterIndex("John Clifford Brin")].Dialog.Filename = "John Clifford Brin_dialog.c";
			LAi_SetActorType(characterFromID("John Clifford Brin"));
			LAi_ActorDialog(characterFromID("John Clifford Brin"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.currentnode = "Reward_for_daughters";
		break;

		case "Brin_leaves":
			LAi_ActorGoToLocation(characterFromID("John Clifford Brin"), "reload", "reload3", "none", "", "", "", 10.0);
			Pchar.quest.Bye_Shaypen_Oxbay.win_condition.l1 = "location";
			PChar.quest.Bye_Shaypen_Oxbay.win_condition.l1.character = Pchar.id;
			Pchar.quest.Bye_Shaypen_Oxbay.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.Bye_Shaypen_Oxbay.win_condition = "Bye_Shaypen_Oxbay";
		break;

		case "Bye_Shaypen_Oxbay":
			Locations[FindLocation("Oxbay_port")].reload.l1.disable = 0;
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "Oxbay_port", "goto", "goto3");
			characters[GetCharacterIndex("Susan Shaypen")].Dialog.Filename = "Susan Shaypen_dialog.c";
			LAi_SetActorType(characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Part_company_at_Oxbay";
		break;

		case "On_my_own_to_Skull":
			LAi_SetActorType(characterFromID("Ines Diaz"));
			LAi_ActorGoToLocation(characterFromID("Ines Diaz"), "merchant", "reload3", "none", "", "", "Ines_leaves_I_go_Skull", 5.0);
		break;

		case "Ines_leaves_I_go_Skull":
			//ChangeCharacterAddress(characterFromID("Ines Diaz"), "none", "");
			pchar.quest.Jacks_early_days = "Try_to_join_Skull";

			Pchar.quest.On_my_own_see_Skull.win_condition.l1 = "location";
			PChar.quest.On_my_own_see_Skull.win_condition.l1.character = Pchar.id;
			Pchar.quest.On_my_own_see_Skull.win_condition.l1.location = "QC_Residence";
			Pchar.quest.On_my_own_see_Skull.win_condition = "On_my_own_see_Skull";
		break;

		case "On_my_own_see_Skull":
			LAi_SetMerchantType(characterFromID("Ines Diaz"));
			ChangeCharacterAddressGroup(characterfromID("Ines Diaz"), "QC_Tavern", "merchant", "goto1");
			characters[GetCharacterIndex("Isenbrandt Jurcksen")].Dialog.Filename = "Skull_dialog.c";
			LAi_SetActorType(characterFromID("Isenbrandt Jurcksen"));
			LAi_ActorDialog(characterFromID("Isenbrandt Jurcksen"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Isenbrandt Jurcksen")].dialog.currentnode = "first time";
		break;

		case "Now_find_Barbossa":
			DisableFastTravel(true);
			Pchar.quest.rescued_the_sisters.win_condition.l1 = "location";
			PChar.quest.rescued_the_sisters.win_condition.l1.character = Pchar.id;
			Pchar.quest.rescued_the_sisters.win_condition.l1.location = "QC_port";
			Pchar.quest.rescued_the_sisters.win_condition = "rescued_the_sisters";

			// PB: Set him back to normal -->
			LAi_SetWarriorType(characterfromID("Isenbrandt Jurcksen"));
			LAi_warrior_DialogEnable(characterfromID("Isenbrandt Jurcksen"), true);
			LAi_warrior_SetStay(characterfromID("Isenbrandt Jurcksen"), true);
			// PB: Set him back to normal <--
		break;

		case "rescued_the_sisters":
			ChangeCharacterAddressGroup(characterfromID("Susan Shaypen"), "QC_port", "goto", "goto4");
			ChangeCharacterAddressGroup(characterfromID("Annabella Brin"), "QC_port", "officers", "reload1_2");
			LAi_SetStayType(characterFromID("Annabella Brin"));
			ChangeCharacterAddressGroup(characterfromID("Bella Brin"), "QC_port", "officers", "reload1_3");

			pchar.quest.Split_from_Shaypen.win_condition.l1 = "locator";
			PChar.quest.Split_from_Shaypen.win_condition.l1.character = Pchar.id;
			pchar.quest.Split_from_Shaypen.win_condition.l1.location = "QC_port";
			pchar.quest.Split_from_Shaypen.win_condition.l1.locator_group = "goto";
			pchar.quest.Split_from_Shaypen.win_condition.l1.locator = "goto11";
			pchar.quest.Split_from_Shaypen.win_condition = "Split_from_Shaypen";
		break;

		case "Split_from_Shaypen":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "goto", "character7", "Split_from_Shaypen2", 5.0);
		break;

		case "Split_from_Shaypen2":
			LAi_ActorTurnToCharacter(PChar,characterFromID("Susan Shaypen"));
			LAi_ActorWaitDialog(PChar,characterFromID("Susan Shaypen"));
			LAi_ActorDialog(characterFromID("Susan Shaypen"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Susan Shaypen")].dialog.currentnode = "Different_Islands";
		break;

		case "What_to_do_next":
			LAi_SetPlayerType(pchar);
			LAi_ActorRunToLocation(characterFromID("Susan Shaypen"), "reload", "reload1", "none", "", "", "Get_sisters_home", 100.0);
		break;

		case "Get_sisters_home":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Susan Shaypen"));
			RemovePassenger(pchar, characterFromID("Susan Shaypen"));
			characters[GetCharacterIndex("Annabella Brin")].Dialog.Filename = "Annabella Brin_dialog.c";
			LAi_SetActorType(characterFromID("Annabella Brin"));
			LAi_ActorDialog(characterFromID("Annabella Brin"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Annabella Brin")].dialog.currentnode = "Sisters_to_sea";
		break;

		case "To_Jamaica_and_father":
			DisableFastTravel(false);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Bella Brin"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Annabella Brin"));
			SetCharacterRemovable(characterFromID("Bella Brin"), false);
			SetCharacterRemovable(characterFromID("Annabella Brin"), false);

			Pchar.quest.Meet_Governor_Brin_RedmondA.win_condition.l1 = "location";
			PChar.quest.Meet_Governor_Brin_RedmondA.win_condition.l1.character = Pchar.id;
			Pchar.quest.Meet_Governor_Brin_RedmondA.win_condition.l1.location = "Redmond_residence";
			Pchar.quest.Meet_Governor_Brin_RedmondA.win_condition = "Meet_Governor_Brin_Redmond";
		break;

		case "Fight_with_skull":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetFightMode(PChar, true);
			LAi_SetActorType(characterFromID("Isenbrandt Jurcksen"));
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(Pchar, false);
			LAi_ActorAttack(characterfromID("Isenbrandt Jurcksen"), pchar, "");

			pchar.quest.Skull_died.win_condition.l1 = "NPC_Death";
			pchar.quest.Skull_died.win_condition.l1.character = "Isenbrandt Jurcksen";
			pchar.quest.Skull_died.win_condition = "Skull_died";

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Skull_died":

		break;
// TO BE EXTENDED - PIRATE SETTLEMENT

// JACK SPARROW QUEST STARTS
		case "Jack_Sparrow_Quest":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			Locations[FindLocation("Oxbay_port")].reload.l1.disable = 0;
			DeleteAttribute(pchar,"Looking_for_sisters");
			GiveItem2Character(CharacterFromId("James Norrington"), "blade4");
			equipCharacterByItem(CharacterFromId("James Norrington"), "blade4");
			ChangeCharacterAddressGroup(CharacterFromID("James Norrington"),"Oxbay_town","goto","goto13");
			LAi_SetActorType(characterFromID("James Norrington"));
			LAi_ActorFollow(characterFromID("James Norrington"),Pchar,"Norrington_talk_1",2.5);
		break;

		case "Norrington_talk_1":
			Locations[FindLocation("Oxbay_town")].vcskip = true;
			LAi_ActorTurnToCharacter(characterFromID("James Norrington"), pchar);
			characters[GetCharacterIndex("James Norrington")].Dialog.Filename = "James Norrington_dialog.c";
			LAi_SetActorType(characterFromID("James Norrington"));	
			Characters[GetCharacterIndex("James Norrington")].dialog.CurrentNode = "first time";
			LAi_ActorDialog(characterFromID("James Norrington"), pchar, "", 10.0, 10.0);
		break;

		case "Norrington_walk_Cliffs":
			LAi_SetActorType(characterFromID("James Norrington")); // KK
			LAi_ActorGoToLocator(characterFromID("James Norrington"), "reload", "reload1", "Norrington_leaves", 10.0);
		break;

		case "Norrington_leaves":
			SetQuestHeader("Norrington"); //CTM (Noticed how Norrington quest file stuffs the quest book first time, fixes)
			AddQuestRecord("Norrington", 1);
			ChangeCharacterAddress(characterFromID("James Norrington"), "None", "");
			LAi_QuestDelay("Beckett_start_at_Oxbay", 0.0);
		break;

		case "Beckett_start_at_Oxbay":
			ChangeCharacterAddressGroup(CharacterFromID("Cutler Beckett"),"Oxbay_tavern", "goto", "goto21")
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "First time";

			//LAi_QuestDelay("Beckett_talk_1", 0.0);
			Pchar.quest.Beckett_missed_first_time.win_condition.l1 = "ExitFromLocation";
			PChar.quest.Beckett_missed_first_time.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_missed_first_time.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Beckett_missed_first_time.win_condition = "Beckett_missed_first_time";

			Pchar.quest.Beckett_talk_1.win_condition.l1 = "location";
			PChar.quest.Beckett_talk_1.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_talk_1.win_condition.l1.location = "Oxbay_tavern";
			Pchar.quest.Beckett_talk_1.win_condition = "Beckett_talk_1";
		break;

		case "Beckett_missed_first_time":
			if (pchar.location != "Oxbay_Tavern")
			{
				pchar.quest.Beckett_talk_1.over = "yes";
			}
		break;

		case "Beckett_talk_1":	
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }

			characters[GetCharacterIndex("Cutler Beckett")].Dialog.Filename = "Cutler Beckett_dialog.c";
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorDialog(characterFromID("Cutler Beckett"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "First time";

			Locations[FindLocation("Oxbay_tavern")].reload.l1.disable = 1;
//			SetQuestHeader("Beckett");
			LAi_SetImmortal(characterFromID("Cutler Beckett"), true);
			Locations[FindLocation("Oxbay_tavern")].vcskip = true;
		break;

		case "Beckett_Leaves_Oxbay":
			DisableFastTravel(true);
			LAi_SetActorType(characterFromID("Cutler Beckett")); // KK
			LAi_ActorGoToLocator(characterFromID("Cutler Beckett"), "reload", "reload1", "Beckett_fades", 10.0);
		break;

		case "Beckett_fades":
			PChar.Beckett = "Working";	//CTM (To stop loop)

			AddQuestRecord("Beckett",12);
			ChangeCharacterAddress(characterFromID("Cutler Beckett"), "None", "");
			LAi_SetPlayerType(pchar);
			Locations[FindLocation("Oxbay_tavern")].reload.l1.disable = false;

			SetCharacterShipLocation(characterFromID("Cutler Beckett"), "Redmond_Port");
			pchar.quest.Jacks_early_days = "Jacks_first_run_Beckett";

			if (GetAttribute(pchar, "Annamaria") != "Lighthouse")
			{
				ChangeCharacterAddressGroup(CharacterFromID("Annamaria"),"Oxbay_town","goto","goto41");
				LAi_SetActorType(characterFromID("Annamaria"));			
				Locations[FindLocation("Oxbay_town")].vcskip = true;

				Pchar.quest.Annamaria_standard_story.win_condition.l1 = "location";
				PChar.quest.Annamaria_standard_story.win_condition.l1.character = Pchar.id;
				Pchar.quest.Annamaria_standard_story.win_condition.l1.location = "Oxbay_town";
				Pchar.quest.Annamaria_standard_story.win_condition = "Annamaria_standard_story";
			}

			Pchar.quest.Sparrow_at_Redmond.win_condition.l1 = "location";
			PChar.quest.Sparrow_at_Redmond.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sparrow_at_Redmond.win_condition.l1.location = "Redmond_port";
			Pchar.quest.Sparrow_at_Redmond.win_condition = "Sparrow_at_Redmond";
		break;

		case "Beckett_Leaves_Oxbay_NOT_Joining":
			DisableFastTravel(true);
			LAi_SetActorType(characterFromID("Cutler Beckett")); // KK
			LAi_ActorGoToLocator(characterFromID("Cutler Beckett"), "reload", "reload1", "Beckett_fades_NOT_Joining", 10.0);
		break;

		case "Beckett_fades_NOT_Joining":
			PChar.Beckett = "Join_later";
			//AddQuestRecord("Beckett",1);
			ChangeCharacterAddress(characterFromID("Cutler Beckett"), "None", "");
			LAi_SetPlayerType(pchar);
			Locations[FindLocation("Oxbay_tavern")].reload.l1.disable = false;

			if (GetAttribute(pchar, "Annamaria") != "Lighthouse")
			{
				ChangeCharacterAddressGroup(CharacterFromID("Annamaria"),"Oxbay_town","goto","goto41");
				LAi_SetActorType(characterFromID("Annamaria"));			
				Locations[FindLocation("Oxbay_town")].vcskip = true;

				Pchar.quest.Annamaria_standard_story.win_condition.l1 = "location";
				PChar.quest.Annamaria_standard_story.win_condition.l1.character = Pchar.id;
				Pchar.quest.Annamaria_standard_story.win_condition.l1.location = "Oxbay_town";
				Pchar.quest.Annamaria_standard_story.win_condition = "Annamaria_standard_story";
			}
		break;
//kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk Check other quest links kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
		case "Annamaria_standard_story":
			LAi_ActorTurnToCharacter(characterFromID("Annamaria"), pchar);
			characters[GetCharacterIndex("Annamaria")].Dialog.Filename = "Annamaria_dialog.c";
			LAi_SetActorType(characterFromID("Annamaria"));
			Characters[GetCharacterIndex("Annamaria")].dialog.CurrentNode = "standard_story_setup";
			LAi_ActorDialog(characterFromID("Annamaria"), pchar, "", 10.0, 10.0);
		break;

		case "Annamaria_standard_story2":
			LAi_SetActorType(characterFromID("Annamaria"));
			LAi_ActorRunToLocator(characterFromID("Annamaria"), "reload", "reload1", "Annamaria_standard_story3", 3.0);
		break;

		case "Annamaria_standard_story3":
			pchar.Annamaria = "Lighthouse";	//CTM (To stop loop)

			DisableFastTravel(false);
			AddQuestRecord("Mystery Woman",9);
			ChangeCharacterAddress(characterFromID("Annamaria"), "None", "");
//			LAi_QuestDelay("Sparrow_at_Redmond", 0.0);

			pchar.quest.straight_to_lighthouse_and_Annamaria.win_condition.l1 = "location";
			pchar.quest.straight_to_lighthouse_and_Annamaria.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.straight_to_lighthouse_and_Annamaria.win_condition = "straight_to_lighthouse_and_Annamaria";
		break;

		case "Sparrow_at_Redmond":
//			Pchar.quest.Annamaria_standard_story.over = "yes";
			DeleteAttribute(&Locations[FindLocation("Oxbay_town")],"vcskip"); // PB
			DisableFastTravel(false);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			pchar.quest.Jacks_and_Beckett = "meeting_basic_quest";

			LAi_QuestDelay("arrived_base_story", 0.0);
		break;

		case "Save_the_Slaves2":
			ChangeCharacterAddress(characterFromID("Cutler Beckett"), "None", "");
			ChangeCharacterAddressGroup(CharacterFromID("Pirates_1"), "Antigua_shore", "goto", "locator26");
			ChangeCharacterAddressGroup(CharacterFromID("Pirates_2"), "Antigua_shore", "officers", "reload2_1");
			ChangeCharacterAddressGroup(CharacterFromID("Pirates_3"), "Antigua_shore", "officers", "reload2_2");
			ChangeCharacterAddressGroup(characterFromID("Tia Dalma"), "Antigua_shore", "goto", "citizen08");
			Pchar.quest.Beckett_Save_Slaves_Africa.win_condition.l1 = "location";
			PChar.quest.Beckett_Save_Slaves_Africa.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beckett_Save_Slaves_Africa.win_condition.l1.location = "Antigua_Shore";
			Pchar.quest.Beckett_Save_Slaves_Africa.win_condition = "Beckett_Save_Slaves_Africa";
		break;

		case "Beckett_Save_Slaves_Africa":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 500); }
			SetCurrentTime(10, 0);
			LAi_QuestDelay("Beckett_Save_Slaves_Africa_2", 0.0);
			SetCharacterShipLocation(CharacterFromID("Cutler Beckett"), "none");
		break;

		case "Beckett_Save_Slaves_Africa_2":
//			ChangeCharacterAddressGroup(characterFromID("Cutler Beckett"), "redmond_residence", "goto", "goto8");
			pchar.quest.Tia_Dalma = "start";
			ChangeCharacterAddress(CharacterFromID("Pirates_1"), "Antigua_shore", "locator26");
			ChangeCharacterAddress(CharacterFromID("Pirates_2"), "Antigua_shore", "reload2_1");
			ChangeCharacterAddress(CharacterFromID("Pirates_3"), "Antigua_shore", "reload2_2");
			LAi_SetActorType(characterFromID("Tia Dalma"));
			LAi_SetImmortal(characterFromID("Tia Dalma"), true);
			LAi_ActorWaitDialog(PChar,characterFromID("Tia Dalma"));
			LAi_ActorDialog(characterFromID("Tia Dalma"),PChar,"",10.0,1.0);
			ChangeCharacterAddress(characterFromID("Tia Dalma"), "Antigua_shore", "citizen08");
			characters[GetCharacterIndex("Tia Dalma")].Dialog.Filename = "Tia Dalma_dialog.c";
		break;

		case "go_to_fight_Slave_Traders":
			Pchar.quest.back_to_Tia_Dalma.win_condition.l1 = "NPC_Death";
			Pchar.quest.back_to_Tia_Dalma.win_condition.l1.character = "Pirates_1";
			Pchar.quest.back_to_Tia_Dalma.win_condition.l2 = "NPC_Death";
			Pchar.quest.back_to_Tia_Dalma.win_condition.l2.character = "Pirates_2";
			Pchar.quest.back_to_Tia_Dalma.win_condition.l3 = "NPC_Death";
			Pchar.quest.back_to_Tia_Dalma.win_condition.l3.character = "Pirates_3";
			PChar.quest.back_to_Tia_Dalma.win_condition = "back_to_Tia_Dalma";
			
			pchar.quest.back_to_Tia_Dalma_failed.win_condition.l1 = "NPC_Death";
			pchar.quest.back_to_Tia_Dalma_failed.win_condition.l1.character = PChar.id;
			pchar.quest.back_to_Tia_Dalma_failed.win_condition = "back_to_Tia_Dalma_failed";
		break;

		case "back_to_Tia_Dalma_failed":
			pchar.quest.back_to_Tia_Dalma.over = "yes";

			Pchar.quest.Player_Save_Slaves_failed2.win_condition.l1 = "location";
			PChar.quest.Player_Save_Slaves_failed2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Player_Save_Slaves_failed2.win_condition.l1.location = "Antigua_Tavern_upstairs";
			Pchar.quest.Player_Save_Slaves_failed2.win_condition = "Player_Save_Slaves_failed2";
		break;

		case "Player_Save_Slaves_failed2":
			ChangeCharacterAddress(characterFromID("Pirates_1"), "None", "");
			ChangeCharacterAddress(characterFromID("Pirates_2"), "None", "");
			ChangeCharacterAddress(characterFromID("Pirates_3"), "None", "");
			ChangeCharacterAddress(characterFromID("Tia Dalma"), "Antigua_shore", "citizen08");

			Pchar.quest.back_to_Tia_Dalma_failed3.win_condition.l1 = "location";
			PChar.quest.back_to_Tia_Dalma_failed3.win_condition.l1.character = Pchar.id;
			Pchar.quest.back_to_Tia_Dalma_failed3.win_condition.l1.location = "Antigua_Shore";
			Pchar.quest.back_to_Tia_Dalma_failed3.win_condition = "back_to_Tia_Dalma_failed3";
		break;

		case "back_to_Tia_Dalma_failed3":
			LAi_SetImmortal(characterFromID("Tia Dalma"), true);
			characters[GetCharacterIndex("Tia Dalma")].Dialog.Filename = "Tia Dalma_dialog.c";
			LAi_SetActorType(characterFromID("Tia Dalma"));
			LAi_ActorDialog(characterFromID("Tia Dalma"),PChar,"",10.0,10.0);
			ChangeCharacterAddress(characterFromID("Tia Dalma"), "Antigua_shore", "citizen08");
			Characters[GetCharacterIndex("Tia Dalma")].dialog.currentnode = "Failed task Mings";
		break;

		case "back_to_Tia_Dalma":
			pchar.quest.back_to_Tia_Dalma_failed.over = "yes";

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 5000); }

			LAi_ActorDialog(characterFromID("Tia Dalma"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Tia Dalma")].dialog.currentnode = "speaktoTiaagain";
		break;

		case "Goodbye Tia Dalma":
			LAi_ActorRunToLocator(characterFromID("Tia Dalma"), "officers", "reload2_2", "Goodbye Tia Dalma2", 20.0);
		break;

		case "Goodbye Tia Dalma2": 
			ChangeCharacterAddress(characterFromID("Tia Dalma"), "None", "");
			pchar.Jack = "Met_Tia";
			PChar.Flags.Personal = 1; // PB: Non-British Jack-flag
			PChar.Flags.Personal.texture = 3;
			if(GetRMRelation(PChar, ENGLAND) > REL_AFTERATTACK) SetRMRelation(PChar, ENGLAND, REL_AFTERATTACK); // PB: England no longer trusts you
			SetServedNation(PERSONAL_NATION); // PB: And you are no longer loyal to them
		break;

		case "return_to_lighthouse_and_Annamaria": // Before the storm
			CloseQuestHeader("Beckett");
			ChangeCharacterAddressGroup(characterFromID("Cutler Beckett"), "Oxbay_lighthouse", "officers", "reload3_1");
			ChangeCharacterAddressGroup(characterFromID("Eng_soldier_38"), "Oxbay_lighthouse", "officers", "reload3_2");
			ChangeCharacterAddressGroup(characterFromID("Eng_soldier_39"), "Oxbay_lighthouse", "officers", "reload3_3");
			SetCharacterRemovable(characterFromID("Annamaria"), true);
			ChangeCharacterAddress(characterFromID("Annamaria"), "None", "");
			LAi_QuestDelay("return_to_lighthouse_and_Annamaria2", 1.0);
			SetNextWeather("Black Pearl Fight");
		break;

		case "return_to_lighthouse_and_Annamaria2":
			StorePassengers(PChar.id);
			HoistFlag(ENGLAND);
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Cutler Beckett"));
			characters[GetCharacterIndex("Cutler Beckett")].Dialog.Filename = "Cutler Beckett_dialog.c";
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorDialog(characterFromID("Cutler Beckett"),PChar,"player_back",10.0,10.0);
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "Captured_on_Oxbay5";
		break;

		case "sunk_wench":
			GiveShip2Character(pchar,"HMS_Bounty","Lindesfarne",ENGLAND,-1,true,true);
			HoistFlag(PERSONAL_NATION);
			PChar.Flags.Personal = 3; // PB: EITC Flag
			PChar.Flags.Personal.texture = 3;
		break;

		case "before_storm":
			LAi_SetPlayerType(PChar);
			DisableFastTravel(false);
			Pchar.quest.before_storm4.win_condition.l1 = "MapEnter";
			Pchar.quest.before_storm4.win_condition = "before_storm4";
			SetNextWeather("Black Pearl Fight");
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			if(GetOfficersIndex(Pchar, 1) == -1)
			{
				Pchar.Temp.Officer.idx1 = GetCharacterIndex("Blaze_Crewmember_01");
			}
			else
			{
				Pchar.Temp.Officer.idx1 = getOfficersIndex(Pchar, 1);
				Pchar.Temp.Officer.idx1.Dialog = Characters[getOfficersIndex(Pchar, 1)].Dialog.Filename;
				Pchar.Temp.Officer.idx1.CurrentNode = Characters[getOfficersIndex(Pchar, 1)].Dialog.CurrentNode;
			}
			if(GetOfficersIndex(Pchar, 2) == -1)
			{
				Pchar.Temp.Officer.idx2 = GetCharacterIndex("Blaze_Crewmember_02");
			}
			else
			{
				Pchar.Temp.Officer.idx2 = getOfficersIndex(Pchar, 2);
				Pchar.Temp.Officer.idx2.Dialog = Characters[getOfficersIndex(Pchar, 2)].Dialog.Filename;
				Pchar.Temp.Officer.idx2.CurrentNode = Characters[getOfficersIndex(Pchar, 2)].Dialog.CurrentNode;
			}
			if(GetOfficersIndex(Pchar, 3) == -1)
			{
				Pchar.Temp.Officer.idx3 = GetCharacterIndex("Blaze_Crewmember_03");
			}
			else
			{
				Pchar.Temp.Officer.idx3 = getOfficersIndex(Pchar, 3);
				Pchar.Temp.Officer.idx3.Dialog = Characters[getOfficersIndex(Pchar, 3)].Dialog.Filename;
				Pchar.Temp.Officer.idx3.CurrentNode = Characters[getOfficersIndex(Pchar, 3)].Dialog.CurrentNode;
			}
			if (GetCompanionIndex(pchar,1) > 0)
			{
				Pchar.Temp.Companion.idx1 = GetCompanionIndex(pchar,1);
				iPassenger = GetCompanionIndex(pchar,1);
				RemoveCharacterCompanion(Pchar, &Characters[iPassenger]);
			}
			else
			{
				Pchar.Temp.Companion.idx1 = -1;
			}
			if (GetCompanionIndex(pchar,2) > 0)
			{
				Pchar.Temp.Companion.idx2 = GetCompanionIndex(pchar,2);
				iPassenger = GetCompanionIndex(pchar,2);
				RemoveCharacterCompanion(Pchar, &Characters[iPassenger]);
			}
			else
			{
				Pchar.Temp.Companion.idx2 = -1;
			}
			if (GetCompanionIndex(pchar,3) > 0)
			{
				Pchar.Temp.Companion.idx3 = GetCompanionIndex(pchar,3);
				iPassenger = GetCompanionIndex(pchar,3);
				RemoveCharacterCompanion(Pchar, &Characters[iPassenger]);
			}
			else
			{
				Pchar.Temp.Companion.idx3 = -1;
			}
			bQuestDisableMapEnter = false;
		break;

		case "before_storm4":
			CI_CreateAndSetControls( "WorldMapControls", "WMapCancel", -1, 0, true );// TIH worldmap cancel screwup prevention Sep3'06
			StorePassengers("Blaze");
			PostVideoAndQuest("storm",1, "storm_complete");
			bMainMenuLaunchAfterVideo = true;
			SetNextWeather("Black Pearl Fight");
		break;

		case "storm_complete":
			ControlsInit(GetTargetPlatform(), false);
			// Screwface
			SaveGlobalOptions();// TIH return the key settings to the user Sep3'06
			// Screwface : end

			PostEvent("DoInfoShower",100,"s","");

			RestorePassengers("Blaze");
			pchar.tempmoney = pchar.money;
			pchar.money = 0;
			pchar.quest.main_line = "speak_with_peasant";
			pchar.quest.Luc_start.over = "yes";
			pchar.jack = "pirate";
			if(GetRMRelation(PChar, ENGLAND) > REL_WAR)
			{
				SetRMRelation(PChar, ENGLAND, REL_WAR); 						// PB: Your actions have turned England hostile
				if (HaveLetterOfMarque(ENGLAND)) LeaveService(PChar, ENGLAND, true);			// GR: And if you had a LoM, you don't have it any more.
			}
			if(GetRMRelation(PChar, PIRATE)  < REL_NEUTRAL) SetRMRelation(PChar, PIRATE, REL_NEUTRAL);	// PB: But the pirates approve
			PChar.Flags.Personal = 1; // PB: Non-British Jack-flag
			PChar.Flags.Personal.texture = 3;
			LAi_QuestDelay("Reset_Prison_comm", 0.0);
			if(GetAttribute(pchar, "Turks") == "0")
			{
				LAi_QuestDelay("Turks_taken_by_brotherhood", 0.0);
			}
			if(GetAttribute(pchar, "Davy") == "helped")
			{
				Characters[GetCharacterIndex("Davy Jones")].model = "9JC";
				Characters[GetCharacterIndex("Davy Jones")].headmodel = "h_9JC";
			}
			else
			{
				SetNextWeather("Super Fog"); // PB
				Characters[GetCharacterIndex("Davy Jones")].headmodel = ""; // PB
			}
			ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Oxbay_shore_01", "goto", "locator10");
			DoQuestReloadToLocation("Oxbay_shore_01", "goto", "citizen02", "to_oxbay_shore_complete");

			// Thomas the Terror: Chevalle side quest available now
			ChangeCharacterAddressGroup(CharacterFromID("Captaine Chevalle"), "PoPrince_tavern", "goto", "goto2");
			// Captain Maggee: Villanueva set to Brothel
			if (IsBrothelEnabled()) 
			{
				ChangeCharacterAddressGroup(CharacterFromID("Eduardo Villanueva"), "Tortuga_Brothel_room", "goto", "locator3");
			}
			else
			{
				ChangeCharacterAddressGroup(CharacterFromID("Eduardo Villanueva"), "Tortuga_Townhall", "goto", "goto2");
			}
			// Captain Maggee: Sumbhajee side quest available now
			ChangeCharacterAddressGroup(CharacterFromID("Sumbhajee"), "Havana_Tavern", "sit", "sit12");
			ChangeCharacterAddressGroup(CharacterFromID("Sumbhajee Aid1"), "Havana_Tavern", "goto", "goto7");
			SetRumourState("Sao_Feng_start", true);		// GR: Replacement rumour for replacement sidequest
			// Captain Maggee: Sao Feng side quest available now
			pchar.quest.ANIMISTS = "1";
			// Captain Maggee: Jocard side quest available now
			PChar.quest.Story_Artois_Nigel.win_condition.l1 = "location";
			PChar.quest.Story_Artois_Nigel.win_condition.l1.character = PChar.id;
			PChar.quest.Story_Artois_Nigel.win_condition.l1.location = "Oranjestad_town";
			PChar.quest.Story_Artois_Nigel.win_condition = "Install_Voysey_And_Blythe";
		break;

		case "to_oxbay_shore_complete":
			pchar.quest.main_line = "speak_with_peasant";
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorFollow(characterFromID("Davy Jones"), pchar, "to_oxbay_shore_complete_2", 2.0);
		break;

		case "to_oxbay_shore_complete_2":
			characters[GetCharacterIndex("Davy Jones")].Dialog.Filename = "Davy Jones_dialog.c";
			LAi_SetActorType(characterFromID("Davy Jones"));	
			Characters[GetCharacterIndex("Davy Jones")].dialog.CurrentNode = "first time";
			LAi_ActorDialog(characterFromID("Davy Jones"), pchar, "", 10.0, 10.0);
		break;

		case "straight_to_lighthouse_and_Annamaria":
			ChangeCharacterAddressGroup(characterFromID("Annamaria"), "Oxbay_lighthouse", "officers", "reload3_3");
			LAi_SetActorType(characterFromID("Annamaria"));

			characters[GetCharacterIndex("Annamaria")].Dialog.Filename = "Annamaria_dialog.c";
			LAi_SetActorType(characterFromID("Annamaria"));
			LAi_ActorDialog(characterFromID("Annamaria"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "We_have_a_treasure_map";
		break;

		case "Looking for Compass":
			pchar.quest.Annamaria_hides.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Annamaria_hides.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.Annamaria_hides.win_condition = "Annamaria_hides";

			Pchar.quest.Now_have_Aztec_Compass.win_condition.l1 = "item";
			Pchar.quest.Now_have_Aztec_Compass.win_condition.l1.item = "aztec_compass";
			Pchar.quest.Now_have_Aztec_Compass.win_condition.l2 = "location";
			PChar.quest.Now_have_Aztec_Compass.win_condition.l2.character = Pchar.id;
			Pchar.quest.Now_have_Aztec_Compass.win_condition.l2.location = "Oxbay_lighthouse";
			Pchar.quest.Now_have_Aztec_Compass.win_condition.l3 = "item";
			Pchar.quest.Now_have_Aztec_Compass.win_condition.l3.item = "Map_Doc_1";
			Pchar.quest.Now_have_Aztec_Compass.win_condition.l4 = "item";
			Pchar.quest.Now_have_Aztec_Compass.win_condition.l4.item = "Map_Doc_2";
			Pchar.quest.Now_have_Aztec_Compass.win_condition.l5 = "item";
			Pchar.quest.Now_have_Aztec_Compass.win_condition.l5.item = "Map_Doc_3";
			Pchar.quest.Now_have_Aztec_Compass.win_condition = "Now_have_Aztec_Compass";
		break;

		case "Annamaria_hides":
			ChangeCharacterAddressGroup(characterFromID("Annamaria"), "none", "", "");
		break;

		case "Now_have_Aztec_Compass":
			ChangeCharacterAddressGroup(characterFromID("Annamaria"), "Oxbay_lighthouse", "officers", "reload3_3");
			LAi_SetActorType(characterFromID("Annamaria"));

			characters[GetCharacterIndex("Annamaria")].Dialog.Filename = "Annamaria_dialog.c";
			LAi_SetActorType(characterFromID("Annamaria"));
			LAi_ActorDialog(characterFromID("Annamaria"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "Got_the_compass_now";
		break;

		case "Open_the_Grotto":
			Locations[FindLocation("IslaDeMuerte_shore_01")].reload.l2.disable = 0;
		break;

		case "Hunt_the_Volcano":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Annamaria"));
			SetCharacterRemovable(characterFromID("Annamaria"), false);
			Pchar.Quest.Now_have_Aztec_Compass.over = "yes";
			LAi_SetImmortal(characterFromID("Annamaria"), true);

			Pchar.quest.Volcano_Battle_Setup.win_condition.l1 = "location";
			Pchar.quest.Volcano_Battle_Setup.win_condition.l1.location = "FalaiseDeFleur";
			Pchar.quest.Volcano_Battle_Setup.win_condition = "Volcano_Battle_Setup";
		break;

		case "Volcano_Battle_Setup":
			SetCurrentTime(10.00, 0);
			SetNextWeather("Blue Sky");
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");

			characters[GetCharacterIndex("Eng Captain Near FdF")].quest.english_war_ship = "1";  // Simon Blunden

			SetCharacterRelation(GetCharacterIndex("Eng Captain Near FdF"),GetMainCharacterIndex(),RELATION_ENEMY);
			SetCharacterRelation(GetCharacterIndex("FalaiseDeFleur Commander"),GetCharacterIndex("Eng Captain Near FdF"),RELATION_ENEMY);

			Group_CreateGroup("Eng Captain Near FdF");
			Group_AddCharacter("Eng Captain Near FdF", "Eng Captain Near FdF");
			Group_SetGroupCommander("Eng Captain Near FdF", "Eng Captain Near FdF");
			Group_SetAddress("Eng Captain Near FdF", "FalaisedeFleur", "Quest_Ships","Quest_Ship_12");

			UpdateRelations();

			Pchar.quest.Volcano_Destroyed.win_condition.l1 = "NPC_death";
			Pchar.quest.Volcano_Destroyed.win_condition.l1.character = "Eng Captain Near FdF";
			Pchar.quest.Volcano_Destroyed.win_condition = "Volcano_Destroyed";

			SetRMRelation(PChar, FRANCE, REL_WAR);
		break;

		case "Volcano_Destroyed":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 30000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 30000);}
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");

			ChangeCharacterAddressGroup(characterFromID("Barbossa"), "Falaise_de_fleur_shore", "goto", "locator5");

			Pchar.quest.Barbossa_In_French_Tavern.win_condition.l1 = "location";
			Pchar.quest.Barbossa_In_French_Tavern.win_condition.l1.location = "Falaise_de_fleur_port_01";
			Pchar.quest.Barbossa_In_French_Tavern.win_condition = "Barbossa_In_French_Tavern";

			Pchar.quest.Barbossa_on_French_Beach.win_condition.l1 = "location";
			Pchar.quest.Barbossa_on_French_Beach.win_condition.l1.location = "Falaise_de_fleur_port_02";
			Pchar.quest.Barbossa_on_French_Beach.win_condition = "Barbossa_on_French_Beach";

			Pchar.quest.Barbossa_on_French_BeachA.win_condition.l1 = "location";
			Pchar.quest.Barbossa_on_French_BeachA.win_condition.l1.location = "Falaise_de_fleur_shore";
			Pchar.quest.Barbossa_on_French_BeachA.win_condition = "Barbossa_on_French_Beach";
		break;

		case "Barbossa_In_French_Tavern":
			Pchar.Quest.Barbossa_on_French_Beach.over = "yes";
			Pchar.Quest.Barbossa_on_French_BeachA.over = "yes";
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");
			ChangeCharacterAddressGroup(characterFromID("Turpin Cabanel"), "Falaise_de_fleur_port_01", "goto", "goto13");
			LAi_QuestDelay("Now_find_Barbossa_Falaise", 0.0);
			characters[GetCharacterIndex("Turpin Cabanel")].Dialog.Filename = "Turpin Cabanel_dialog.c";
		break;

		case "Now_find_Barbossa_Falaise":
			ChangeCharacterReputation(pchar, 5);
			characters[GetCharacterIndex("Turpin Cabanel")].Dialog.Filename = "Turpin Cabanel_dialog.c";
			LAi_SetActorType(characterFromID("Turpin Cabanel"));
			LAi_ActorDialog(characterFromID("Turpin Cabanel"),PChar,"",2.0,2.0);
			Characters[GetCharacterIndex("Turpin Cabanel")].dialog.currentnode = "We_have_Killed_Blunden";
		break;

		case "Information_on_Barbossa":
			LAi_ActorGoToLocator(characterFromID("Turpin Cabanel"), "goto", "goto17", "", 10.0);

			characters[GetCharacterIndex("Annamaria")].Dialog.Filename = "Annamaria_dialog.c";
			LAi_SetActorType(characterFromID("Annamaria"));
			LAi_ActorDialog(characterFromID("Annamaria"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "This_smells_to_me";
		break;

		case "Information_on_Barbossa2":
			LAi_ActorGoToLocator(characterFromID("Turpin Cabanel"), "officers", "shipyard_2", "", 10.0);
			ChangeCharacterAddressGroup(characterFromID("Barbossa"), "Falaise_de_fleur_shore", "goto", "locator5");
			LAi_SetOfficerType(characterfromID("Annamaria"));

			Pchar.quest.Barbossa_on_French_Beach.win_condition.l1 = "location";
			Pchar.quest.Barbossa_on_French_Beach.win_condition.l1.location = "Falaise_de_fleur_shore";
			Pchar.quest.Barbossa_on_French_Beach.win_condition = "Barbossa_on_French_Beach";
		break;

		case "Barbossa_on_French_Beach":
			LAi_SetOfficerType(characterFromID("Annamaria"));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 1500); }
			Pchar.Quest.Barbossa_In_French_Tavern.over = "yes";
//			ChangeCharacterAddress(characterFromID("Turpin Cabanel"), "None", "");
			ChangeCharacterAddressGroup(CharacterFromID("Turpin Cabanel"), "Head_port_house", "goto", "locator1"); // GR: Put him back in his house so you can help him with smugglers or ask about the Blacque family
			LAi_SetStayType(CharacterFromID("Turpin Cabanel"));

			if(CheckAttribute(locations[FindLocation(Pchar.location)],"Falaise_de_fleur_port_02"))
			{
				Pchar.Quest.Barbossa_on_French_BeachA.over = "yes";
			}
			if(CheckAttribute(locations[FindLocation(Pchar.location)],"Falaise_de_fleur_shore"))
			{
				Pchar.Quest.Barbossa_on_French_Beach.over = "yes";
			}
			characters[GetCharacterIndex("Barbossa")].Dialog.Filename = "Barbossa_dialog.c";
			LAi_SetStayType(characterFromID("Barbossa"));
			LAi_ActorDialog(characterFromID("Barbossa"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Barbossa")].dialog.currentnode = "Talk_Barbossa_French_Beach";
		break;

		case "Annamaria_on_French_Beach":
			LAi_SetActorType(characterFromID("Annamaria"));
			characters[GetCharacterIndex("Annamaria")].Dialog.Filename = "Annamaria_dialog.c";
			LAi_ActorDialog(characterFromID("Annamaria"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "Talk_on_French_Beach";
		break;

		case "Back_to_Lighthouse_yet_again":
			pchar.quest.return_to_lighthouse_and_Annamaria.win_condition.l1 = "location";
			pchar.quest.return_to_lighthouse_and_Annamaria.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.return_to_lighthouse_and_Annamaria.win_condition = "return_to_lighthouse_and_Annamaria";
		break;

		case "Find_Barbossa_with_Black_Pearl":
			ChangeCharacterAddress(characterFromID("Annamaria"), "None", "");

			Pchar.quest.Join_with_Barbossa_for_Cortez_Treasure.win_condition.l1 = "location";
			Pchar.quest.Join_with_Barbossa_for_Cortez_Treasure.win_condition.l1.location = "Tortuga_tavern";	//CTM (Changed location to Tortuga from FDF)
			Pchar.quest.Join_with_Barbossa_for_Cortez_Treasure.win_condition = "Join_with_Barbossa_for_Cortez_Treasure";
		break;

		case "Find_Davy_for_Black_Pearl":
			ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Roa_Cabin", "sit", "sit1");
			characters[GetCharacterIndex("Davy Jones")].Dialog.currentnode = "ForDavyJones11";
			LAi_SetSitType(characterFromID("Davy Jones"));

			sld = CharacterFromID("KR_Crew1");
			SetModelfromArray(sld, GetModelIndex("davy1"));
			sld.name = "Angler";
			sld.lastname = "";
			sld.Dialog.Filename = "Davycrew_dialog.c";
			sld.Dialog.currentnode = "roa_lair";

			sld = CharacterFromID("KR_Crew2");
			SetModelfromArray(sld, GetModelIndex("davy2"));
			sld.name = "Ogilvey";
			sld.lastname = "";
			sld.Dialog.Filename = "Davycrew_dialog.c";
			sld.Dialog.currentnode = "roa_lair";

			sld = CharacterFromID("KR_Crew3");
			SetModelfromArray(sld, GetModelIndex("davy3"));
			sld.name = "Maccus";
			sld.lastname = "";
			sld.Dialog.Filename = "Davycrew_dialog.c";
			sld.Dialog.currentnode = "roa_lair";

			sld = CharacterFromID("KR_Crew4");
			SetModelfromArray(sld, GetModelIndex("davy4"));
			sld.name = "Clanker";
			sld.lastname = "";
			sld.Dialog.Filename = "Davycrew_dialog.c";
			sld.Dialog.currentnode = "roa_lair";
		break;

		case "Join_with_Barbossa_for_Cortez_Treasure":
			if(GetAttribute(pchar, "Davy") != "helped") Characters[GetCharacterIndex("Davy Jones")].headmodel = "h_DavyJones"; // PB

			ChangeCharacterAddress(characterFromID("Davy Jones"), "None", "");
			pchar.quest.Beckett = "Decide_to_join_Barbossa";
			ChangeCharacterAddressGroup(characterFromID("Barbossa"), "Tortuga_tavern", "goto", "goto9");	//CTM
			characters[GetCharacterIndex("Barbossa")].Dialog.Filename = "Barbossa_dialog.c";
			LAi_SetActorType(characterFromID("Barbossa"));
			LAi_ActorWaitDialog(characterFromID("Barbossa"), pchar);
			LAi_ActorDialog(characterFromID("Barbossa"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Barbossa")].dialog.currentnode = "First time";

		//-->CTM (adding Pintel and Ragetti)
			Pchar.quest.Find_Ragetti_and_Pintel.win_condition.l1 = "location";
			//Pchar.quest.Find_Ragetti_and_Pintel.win_condition.l1.location = "Tortuga_town_01";
			Pchar.quest.Find_Ragetti_and_Pintel.win_condition.l1.location = "Tortuga_port";			//JRH change
			Pchar.quest.Find_Ragetti_and_Pintel.win_condition = "Find_Ragetti_and_Pintel";
		break;
	//-----------------------------------------------------------------------------------------------------------------
	//JRH-->
		case "Pintel_stay_where_you_are_loop1":
			Pchar.quest.Pintel_stay_where_you_are_loop2.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Pintel_stay_where_you_are_loop2.win_condition.l1.location = "Tortuga_port";
			Pchar.quest.Pintel_stay_where_you_are_loop2.win_condition = "Pintel_stay_where_you_are_loop2";
		break;

		case "Pintel_stay_where_you_are_loop2":
			Pchar.quest.Pintel_stay_where_you_are_loop3.win_condition.l1 = "location";
			Pchar.quest.Pintel_stay_where_you_are_loop3.win_condition.l1.location = "Tortuga_port";
			Pchar.quest.Pintel_stay_where_you_are_loop3.win_condition = "Pintel_stay_where_you_are_loop3";
		break;

		case "Pintel_stay_where_you_are_loop3":
			if(CheckAttribute(Pchar,"quest.PandR") && Pchar.quest.PandR == "at_shipyard")
			{
				changeCharacterAddressGroup(characterFromID("Pintel"), "Tortuga_port", "goto", "goto27");

				LAi_QuestDelay("Pintel_stay_where_you_are_loop1", 0.1);	
				
			}
			else return;
		break;
	//<--JRH
	//-----------------------------------------------------------------------------------------------------------------
		case "Find_Ragetti_and_Pintel":
			LAi_QuestDelay("Pintel_stay_where_you_are_loop1", 0.1);							//JRH
	
			//changeCharacterAddressGroup(characterFromID("Ragetti"), "Tortuga_town_01", "goto", "goto22");
			//changeCharacterAddressGroup(characterFromID("Pintel"), "Tortuga_town_01", "officers", "reload19_3");
			changeCharacterAddressGroup(characterFromID("Ragetti"), "Tortuga_port", "goto", "goto26");		//JRH change
			changeCharacterAddressGroup(characterFromID("Pintel"), "Tortuga_port", "goto", "goto27");		//JRH change
			pchar.quest.Beckett = "Ragetti_Join";
			pchar.quest.PandR = "at_shipyard";									//JRH
			characters[GetCharacterIndex("Ragetti")].Dialog.Filename = "Ragetti_dialog.c";
			LAi_SetActorType(characterFromID("Ragetti"));
			LAi_ActorWaitDialog(characterFromID("Ragetti"), pchar);
			LAi_ActorDialog(characterFromID("Ragetti"),PChar,"",10.0,1.0);
		break;

		case "Find_Ragetti_and_Pintel2":
			pchar.quest.Beckett = "Pintel_Join";
			pchar.quest.PandR = "officers_now";									//JRH
			characters[GetCharacterIndex("Pintel")].Dialog.Filename = "Pintel_dialog.c";
			LAi_SetActorType(characterFromID("Pintel"));
			LAi_ActorDialog(characterFromID("Pintel"),PChar,"",10.0,1.0);
		break;

		case "Find_Ragetti_and_Pintel3":
			LAi_SetOfficerType(characterFromID("Ragetti")); // Levis
			LAi_SetImmortal(characterFromID("Ragetti"), true); // Levis
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Ragetti"));
		//	LAi_SetOfficerType(characterFromID("Pintel"));
		//	LAi_SetImmortal(characterFromID("Pintel"), true);
		//	SetOfficersIndex(Pchar, 3, getCharacterIndex("Pintel")); // Levis

			Characters[GetCharacterIndex("Pintel")].dialog.currentnode = "First time";
			Characters[GetCharacterIndex("Ragetti")].dialog.currentnode = "First time";
			Pchar.Rag = "1";
			PChar.quest.Muerte = "just_landed_for_treasure";
		break;
		//<--CTM

		case "Join_with_Barbossa_for_Cortez_Treasure":
			ChangeCharacterAddress(characterFromID("Davy Jones"), "None", "");
			pchar.quest.Beckett = "Decide_to_join_Barbossa";
			ChangeCharacterAddressGroup(characterFromID("Barbossa"), "Falaise_de_fleur_shore", "goto", "locator22");
			characters[GetCharacterIndex("Barbossa")].Dialog.Filename = "Barbossa_dialog.c";
			LAi_SetActorType(characterFromID("Barbossa"));
			LAi_ActorDialog(characterFromID("Barbossa"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Barbossa")].dialog.currentnode = "First time";
		break;

		case "Barbossa_for_Cortez_treasure":
			AddPassenger(Pchar, characterFromID("Barbossa"), 0);
			ChangeCharacterAddress(characterFromID("Davy Jones"), "none", "");
			SetNextWeather("Blue Sky");
			pchar.quest.before_first_marooning.win_condition.l1 = "MapEnter";
			pchar.quest.before_first_marooning.win_condition = "before_first_marooning";
		break;

		case "Barbossa_to_Isle_de_Muerte":
			Locations[FindLocation("Oxbay_lighthouse")].reload.l4.disable = false;
			Locations[FindLocation("Oxbay_lighthouse")].reload.l3.disable = false;
			if (GetAttribute(pchar,"Rag")!="1") PChar.quest.Muerte = "just_landed_for_treasure1";
			AddQuestRecord("Aztec", 5);
			AddPassenger(Pchar, characterFromID("Barbossa"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Barbossa"));
			Characters[GetCharacterIndex("Barbossa")].Dialog.CurrentNode = "first time";
			ChangeCharacterAddress(characterFromID("Davy Jones"), "none", "");
			SetNextWeather("Blue Sky");

			Pchar.quest.muerte_with_Barbossa_option.win_condition.l1 = "location";
			Pchar.quest.muerte_with_Barbossa_option.win_condition.l1.location = "IslaDemuerte_shore_01";
			PChar.quest.muerte_with_Barbossa_option.win_condition = "muerte_with_Barbossa_option";
		break;

		case "muerte_with_Barbossa_option":
			ChangeCharacterAddressGroup(CharacterFromID("Barbossa"),"IslaDemuerte_shore_01", "goto", "citizen05");

			Pchar.quest.Me_and_Barbossa_on_the_Beach.win_condition.l1 = "location";
			Pchar.quest.Me_and_Barbossa_on_the_Beach.win_condition.l1.location = "Grotto";
			PChar.quest.Me_and_Barbossa_on_the_Beach.win_condition = "Me_and_Barbossa_on_the_Beach";
			
			Locations[FindLocation("Grotto")].locators_radius.goto.goto4 = 3.0; // PB: Easier to trigger
		break;

		case "Me_and_Barbossa_on_the_Beach":
			LAi_QuestDelay("Me_and_Barbossa_in_Cave", 20.0);
			ChangeCharacterAddressGroup(characterFromID("Barbossa"), "Grotto", "goto", "goto2");
		break;

		case "Me_and_Barbossa_in_Cave":
			LAi_SetActorType(characterFromID("Barbossa"));
			characters[GetCharacterIndex("Barbossa")].Dialog.Filename = "Barbossa_dialog.c";
			LAi_SetActorType(characterFromID("Barbossa"));
			LAi_ActorDialog(characterFromID("Barbossa"),PChar,"Me_and_Barbossa_In_the_Grotto",10.0,1.0);
			Characters[GetCharacterIndex("Barbossa")].dialog.currentnode = "Go_to_find_treasure";
		break;

		case "Me_and_Barbossa_In_the_Grotto":
			LAi_SetPlayerType(pchar);
			LAi_ActorFollowEverywhere(characterFromID("Barbossa"), "", 60.0);
			pchar.quest.Barbossa_In_the_Grotto.win_condition.l1 = "locator";
			pchar.quest.Barbossa_In_the_Grotto.win_condition.l1.location = "Grotto";
			pchar.quest.Barbossa_In_the_Grotto.win_condition.l1.locator_group = "goto";
			pchar.quest.Barbossa_In_the_Grotto.win_condition.l1.locator = "goto4";
			pchar.quest.Barbossa_In_the_Grotto.win_condition = "Barbossa_In_the_Grotto";
		break;

		case "Barbossa_In_the_Grotto":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 5000);}
			LAi_SetActorType(characterFromID("Barbossa"));
			LAi_ActorFollowEverywhere(characterFromID("Barbossa"), "Barbossa_To_Cayman_Tavern2", 60.0);
			
			Locations[FindLocation("Grotto")].locators_radius.goto.goto4 = 1.0; // PB: Back to normal
		break;

		case "Barbossa_To_Cayman_Tavern2":
			Characters[GetCharacterIndex("Barbossa")].dialog.CurrentNode = "found_the_treasure";
			LAi_ActorDialog(characterFromID("Barbossa"), pchar, "", 10.0, 10.0);
		break;

		case "Barbossa_and_me_back_to_Beach":
			LAi_SetOfficerType(characterFromID("Barbossa"));
			LAi_SetPlayerType(pchar);
			SetNextWeather("Blue Sky");
			pchar.quest.before_first_marooning.win_condition.l1 = "MapEnter";
			pchar.quest.before_first_marooning.win_condition = "before_first_marooning";
		break;

		case "before_first_marooning":
			Locations[FindLocation("Oxbay_lighthouse")].reload.l4.disable = false;
			Locations[FindLocation("Oxbay_lighthouse")].reload.l3.disable = false;
			SetNextWeather("Blue Sky");
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			EquipCharacterByItem(pchar, "bladeX4");

			//--> CTM (Fix for Barbossa and Ragetti/Pintel turning up when landing on Isla with Interceptor)
			RemovePassenger(Pchar, characterFromID("Barbossa"));

			if (GetAttribute(pchar,"Rag")=="1"){
				RemovePassenger(Pchar, characterFromID("Ragetti"));
			}
			// CTM <--

			pchar.Bosun = "cursed";
			if(IsPassenger(characterFromID("Bos'un")) || IsOfficer(characterFromID("Bos'un")))
			{
				Characters[GetCharacterIndex("Bos'un")].name = TranslateString("","Nigel");
				Characters[GetCharacterIndex("Bos'un")].lastname = TranslateString("","the Slave");
				Characters[GetCharacterIndex("Bos'un")].model = "Ancient";
				Characters[GetCharacterIndex("Bos'un")].headmodel = "h_Ancient";
			}
			//StorePassengers("Blaze");
			StorePassengers(Pchar.id);
			pchar.tempmoney = pchar.money;
			pchar.money = 100;

			DoQuestReloadToLocation("ShipDeck7", "goto", "goto7", "talk_before_first_marooning");
		break;

		case "talk_before_first_marooning":
			if(GetOfficersIndex(Pchar, 3) != -1)
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "");
			}
			if(GetAttribute(pchar,"Rag")=="1")
			{
				ChangeCharacterAddressGroup(CharacterFromID("Ragetti"), "ShipDeck7", "rld", "wheel");
				ChangeCharacterAddressGroup(CharacterFromID("Pintel"), "ShipDeck7", "goto", "goto8");
				//-->CTM (adds Ragetti and Pintel on deck when Barbossa is being a B@$T@RD
				LAi_SetActorType(characterFromID("Ragetti"));
				LAi_ActorWaitDialog(pchar, characterFromID("Ragetti"));
				LAi_SetActorType(characterFromID("Pintel"));
				LAi_ActorWaitDialog(pchar, characterFromID("Pintel"));
				//<--CTM
			}
			ChangeCharacterAddressGroup(CharacterFromID("Barbossa"), "ShipDeck7", "goto", "goto14");
			pchar.quest.Beckett = "Barbossa_enacts_Mutiny";
			characters[GetCharacterIndex("Barbossa")].Dialog.Filename = "Barbossa_dialog.c";
			LAi_SetActorType(characterFromID("Barbossa"));
			Characters[GetCharacterIndex("Barbossa")].dialog.CurrentNode = "first time";
			LAi_ActorDialog(characterFromID("Barbossa"), pchar, "", 10.0, 10.0);
		break;

		case "Barbossa_leaves_for_now":
			if(GetOfficersIndex(Pchar, 1) > 0)
			{
				Pchar.Temp.Officer.idx1 = getOfficersIndex(Pchar, 1);
				Pchar.Temp.Officer.idx1.Dialog = Characters[getOfficersIndex(Pchar, 1)].Dialog.Filename;
				Pchar.Temp.Officer.idx1.CurrentNode = Characters[getOfficersIndex(Pchar, 1)].Dialog.CurrentNode;
			}
			else
			{
				Pchar.Temp.Officer.idx1 = -1;
			}
			if(GetOfficersIndex(Pchar, 2) > 0)
			{
				Pchar.Temp.Officer.idx2 = getOfficersIndex(Pchar, 2);
				Pchar.Temp.Officer.idx2.Dialog = Characters[getOfficersIndex(Pchar, 2)].Dialog.Filename;
				Pchar.Temp.Officer.idx2.CurrentNode = Characters[getOfficersIndex(Pchar, 2)].Dialog.CurrentNode;
			}
			else
			{
				Pchar.Temp.Officer.idx2 = -1;
			}
			if(GetOfficersIndex(Pchar, 3) > 0)
			{
				Pchar.Temp.Officer.idx3 = getOfficersIndex(Pchar, 3);
				Pchar.Temp.Officer.idx3.Dialog = Characters[getOfficersIndex(Pchar, 3)].Dialog.Filename;
				Pchar.Temp.Officer.idx3.CurrentNode = Characters[getOfficersIndex(Pchar, 3)].Dialog.CurrentNode;
			}
			else
			{
				Pchar.Temp.Officer.idx3 = -1;
			}
			if (GetCompanionIndex(pchar,1) > 0)
			{
				Pchar.Temp.Companion.idx1 = GetCompanionIndex(pchar,1);
				iPassenger = GetCompanionIndex(pchar,1);
				RemoveCharacterCompanion(Pchar, &Characters[iPassenger]);
			}
			else
			{
				Pchar.Temp.Companion.idx1 = -1;
			}
			if (GetCompanionIndex(pchar,2) > 0)
			{
				Pchar.Temp.Companion.idx2 = GetCompanionIndex(pchar,2);
				iPassenger = GetCompanionIndex(pchar,2);
				RemoveCharacterCompanion(Pchar, &Characters[iPassenger]);
			}
			else
			{
				Pchar.Temp.Companion.idx2 = -1;
			}
			if (GetCompanionIndex(pchar,3) > 0)
			{
				Pchar.Temp.Companion.idx3 = GetCompanionIndex(pchar,3);
				iPassenger = GetCompanionIndex(pchar,3);
				RemoveCharacterCompanion(Pchar, &Characters[iPassenger]);
			}
			else
			{
				Pchar.Temp.Companion.idx3 = -1;
			}
			TakeItemFromCharacter(Pchar,"aztec_compass");
			pchar.money = 100;
			//AddQuestRecord("Hector Barbossa",4);
			if (GetAttribute(pchar, "stolen") != "1")
			{
				SetQuestHeader("Stolen");
				pchar.stolen = "1";
			}
			AddQuestRecord("Stolen",2);
			SetCurrentTime(10, 0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 500); }
			// PB -->
			// KK -->
			if (PreprocessText("#scursed_ship#") == "Black Pearl")
				GiveShip2Character(CharacterFromID("Barbossa"),"UncursedPearl",TranslateString(PreprocessText("#scursed_ship#"), ""),-1,PIRATE,TRUE,TRUE);
			else
			{
				GiveShip2Character(CharacterFromID("Barbossa"),"CrimsonBlood", TranslateString(PreprocessText("#scursed_ship#"), ""),-1,PIRATE,TRUE,TRUE);
			// <-- KK
				characters[GetCharacterIndex("Barbossa")].Ship.EmblemedSails.normalTex = "sail_Petros_black_red.tga"; // PB
				characters[GetCharacterIndex("Barbossa")].Ship.EmblemedSails.nationFileName = "sail_Petros_black_red.tga"; // PB
			}
			characters[GetCharacterIndex("Barbossa")].Flags.Pirate = 0; // PB: Jack Rackham Pirate Flag
			characters[GetCharacterIndex("Barbossa")].Flags.Pirate.texture = 0;
			setCharacterShipLocation(characterFromID("Barbossa"), "Deserted_Island_shore_01");
			characters[GetCharacterIndex("Barbossa")].sailaway = true;

			DisableFastTravel(true);
			DeleteAttribute(pchar, "Ship");
			pchar.Ship.Type = SHIP_NOTUSED_TYPE_NAME;
			pchar.Ship.Name = "";
			// PB <--
			DoQuestReloadToLocation("Deserted_Island_shore_01", "officers", "reload1_3", "Barbossa_leaves_for_now2");
			LAi_SetPlayerType(pchar);
			locations[FindLocation("Deserted_island_Jungle_01")].vcskip = true;

			CloseQuestHeader("Aztec");
		break;

		case "Barbossa_leaves_for_now2":
			RestorePassengers(Pchar.id);
			//StorePassengers("Blaze");
			if(GetOfficersIndex(Pchar, 3) != -1)
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "");
			}
			DeleteAttribute(characterFromID("Barbossa"), "sailaway"); // PB: Reset - just in case

			Pchar.quest.get_the_Tartane.win_condition.l1 = "location";
			Pchar.quest.get_the_Tartane.win_condition.l1.location = "Deserted_Island_Jungle_01";
			PChar.quest.get_the_Tartane.win_condition = "get_a_ride_with_smugglers";
		break;

		case "get_a_ride_with_smugglers":
			GiveShip2Character(pchar,"Barque4_47","Free at Last",-1,PIRATE,true,true);
			PlaceFleetNearShore("Deserted_Island_shore_02");
			EquipCharacterByItem(pchar, "bladeX4");
			ChangeCharacterAddress(characterFromID("Barbossa"), "None", "");
			RemovePassenger(Pchar, characterFromID("Barbossa"));

			pchar.quest.gets_off_marooned_island2.win_condition.l1 = "location";
			pchar.quest.gets_off_marooned_island2.win_condition.l1.location = "Deserted_Island_Jungle_01";
			pchar.quest.gets_off_marooned_island2.win_condition = "gets_off_marooned_island2";
		break;

		case "gets_off_marooned_island2":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 5000); }
			ChangeCharacterAddressGroup(characterFromID("quest_smuggler_01"), "Deserted_Island_shore_02", "goto", "locator14");
			ChangeCharacterAddressGroup(characterFromID("Treas_Pirate_1"), "Deserted_Island_shore_02", "goto", "citizen04");
			LAi_SetActorType(characterFromID("quest_smuggler_01"));
			LAi_SetActorType(characterFromID("Treas_Pirate_1"));
			SetCrewQuantity(pchar, 3)
			SetCharacterGoods(pchar, GOOD_WHEAT, 2);
			SetCharacterGoods(pchar, GOOD_RUM, 40);
			HoistFlag(PIRATE);
			DisableFastTravel(false);

			pchar.quest.Chatter_to_smuggler.win_condition.l1 = "location";
			pchar.quest.Chatter_to_smuggler.win_condition.l1.location = "Deserted_Island_shore_02";
			pchar.quest.Chatter_to_smuggler.win_condition = "Chatter_to_smuggler";
		break;

		case "Chatter_to_smuggler":
			pchar.quest.Smuggler = "With_Smugglers_To_Tortuga";
			bQuestDisableMapEnter = false;
			LAi_ActorTurnToCharacter(characterFromID("Treas_Pirate_1"), pchar);
			
			LAi_QuestDelay("Chatter_to_smuggler2", 5.0);
		break;

		case "Chatter_to_smuggler2":
			pchar.quest.Smuggler = "With_Smugglers_To_Tortuga";
			LAi_SetActorType(characterFromID("quest_smuggler_01"));
			LAi_ActorDialog(characterFromID("quest_smuggler_01"),PChar,"",10.0,1.0);
			characters[GetCharacterIndex("quest_smuggler_01")].Dialog.Filename = "Port Guard_dialog.c";
			Characters[GetCharacterIndex("quest_smuggler_01")].dialog.currentnode = "Smuggler Talk";

			SetNextWeather("Blue Sky");
			PChar.quest.add_smuggler_passenger.win_condition.l1 = "ExitFromLocation";
			PChar.quest.add_smuggler_passenger.win_condition.l1.location = PChar.location;
			PChar.quest.add_smuggler_passenger.win_condition = "add_smuggler_passenger";
		break;

		case "add_smuggler_passenger":
			AddPassenger(Pchar, characterFromID("quest_smuggler_01"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("quest_smuggler_01"));
			SetCharacterRemovable(characterFromID("quest_smuggler_01"), false); // PB

			pchar.quest.Tortuga_Get_ready_for_Film.win_condition.l1 = "location";
			pchar.quest.Tortuga_Get_ready_for_Film.win_condition.l1.location = "Tortuga_port";
			pchar.quest.Tortuga_Get_ready_for_Film.win_condition = "Tortuga_Get_ready_for_Film";
		break;
// Meet Bootstrap on Tortuga Feb 08
		case "Tortuga_Get_ready_for_Film":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}

			if (IsPassenger(CharacterFromID("Captaine Chevalle")) || IsOfficer(CharacterFromID("Captaine Chevalle")))
			{
				pchar.Chevalle = "Mutiny";
				RemovePassenger(pchar, characterFromID("Captaine Chevalle"));
			}
			else
			{
				pchar.Chevalle = "0";

				pchar.quest.Tortuga_Get_ready_for_Film2.win_condition.l1 = "location";
				pchar.quest.Tortuga_Get_ready_for_Film2.win_condition.l1.location = "Tortuga_tavern";
				//pchar.quest.Tortuga_Get_ready_for_Film2.win_condition = "Tortuga_Get_ready_for_Film2";
				pchar.quest.Tortuga_Get_ready_for_Film2.win_condition = "Gibbs_in_Tavern2_1.5";
			}

			AddQuestRecord("Stolen",6);

			pchar.quest.Beckett = "Smugglers_Arrived_Tortuga";
			LAi_SetActorType(characterFromID("quest_smuggler_01"));
			LAi_ActorDialog(characterFromID("quest_smuggler_01"),PChar,"",10.0,1.0);
			characters[GetCharacterIndex("quest_smuggler_01")].Dialog.Filename = "Port Guard_dialog.c";
		break;

		case "Tortuga_Get_ready_for_Film1":
			LAi_QuestDelay("Self_CC_Tortuga", 3.0);
		break;

		case "Self_CC_Tortuga":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Where Chevalle";
			LAi_ActorSelfDialog(Pchar, "player_back");
			PChar.quest.Jackpot = "search";

			if (IsBrothelEnabled()) 
			{
				ChangeCharacterAddressGroup(CharacterFromID("Captaine Chevalle"), "Tortuga_Brothel_room", "goto", "locator2");
				Pchar.quest.MeetVillanueva.win_condition.l1 = "location";
				Pchar.quest.MeetVillanueva.win_condition.l1.location = "Tortuga_Brothel_room";
				PChar.quest.MeetVillanueva.win_condition = "MeetVillanueva";
			}
			else
			{
				ChangeCharacterAddressGroup(CharacterFromID("Captaine Chevalle"), "Tortuga_Townhall", "goto", "goto7");
				Pchar.quest.MeetVillanueva.win_condition.l1 = "location";
				Pchar.quest.MeetVillanueva.win_condition.l1.location = "Tortuga_Townhall";
				PChar.quest.MeetVillanueva.win_condition = "MeetVillanueva";
			}

			AddQuestRecord("Chevalle", 11);
		break;

		case "Gibbs_in_Tavern2_1":
			if (GetAttribute(pchar, "Chevalle") == "No_EV")
			{
				ChangeCharacterAddressGroup(characterFromID("Eduardo Villanueva"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Captaine Chevalle"), "none", "", "");
			}

			LAi_SetSitType(pchar);
			LAi_SetActorType(characterFromID("Storyteller"));
			LAi_ActorSetSitMode(characterFromID("Storyteller"));

			SetModelfromArray(PChar, GetModelIndex(pchar.originalmodel)); 

			ChangeCharacterAddressGroup(characterFromID("Storyteller"), "Tortuga_Tavern", "candles", "sit5");
			DoQuestReloadToLocation("Tortuga_tavern", "candles", "sit4", "Gibbs_in_Tavern2_4");
		break;

		case "Gibbs_in_Tavern2_1.5":
			LAi_fade("Gibbs_in_Tavern2_2", "Gibbs_in_Tavern2_3");
		break;

		case "Gibbs_in_Tavern2_2":
			LAi_SetSitType(pchar);
			LAi_SetActorType(characterFromID("Storyteller"));
			LAi_ActorSetSitMode(characterFromID("Storyteller"));

			SetModelfromArray(PChar, GetModelIndex(pchar.originalmodel)); 

			ChangeCharacterAddressGroup(characterFromID("Storyteller"), "Tortuga_Tavern", "candles", "sit5");
			ChangeCharacterAddressGroup(pchar, "Tortuga_Tavern", "candles", "sit4");
		break;

		case "Gibbs_in_Tavern2_3":
			LAi_QuestDelay("Gibbs_in_Tavern2_4", 1.0);
		break;

		case "Gibbs_in_Tavern2_4":
			Characters[GetCharacterIndex("Storyteller")].dialog.currentnode = "Tavern_Story8";
			LAi_ActorDialog(characterFromID("Storyteller"), pchar, "", 0.0, 0.0);
		break;

		case "10_years_tortuga":
			DoQuestReloadToLocation("Turks_port", "reload", "reload1", "_");
			// MAXIMUS 05.09.2018 ==>
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			// MAXIMUS 05.09.2018 <==
			GiveModel2Player("Jack",true);
			LAi_SetPlayerType(pchar);

			pchar.quest.Tortuga_10_Years.win_condition.l1 = "location";
			pchar.quest.Tortuga_10_Years.win_condition.l1.location = "Tortuga_port";
			pchar.quest.Tortuga_10_Years.win_condition = "Tortuga_Get_ready_for_Film1.5";
		break;

		case "Tortuga_Get_ready_for_Film1.5":
			AddQuestRecord("Stolen", 7);

			LAi_SetActorType(characterFromID("Storyteller"));
			LAi_ActorSetSitMode(characterFromID("Storyteller"));
			LAi_SetActorType(characterFromID("Annamaria"));
			ChangeCharacterAddressGroup(characterfromID("Annamaria"), "Tortuga_tavern", "goto", "goto2");

//			LAi_QuestDelay("Pre_Tortuga_Meet_Annamaria_for_ship", 0.2);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(PChar, "ships_other", "ship3");
			LAi_QuestDelay("Tortuga_Get_ready_for_Film1.5.2", 1.0);
		break;

		case "Tortuga_Get_ready_for_Film1.5.2":
			Pchar.dialog.currentnode = "ship_stolen_tortuga";
			LAi_ActorSelfDialog(Pchar, "Pre_Tortuga_Meet_Annamaria_for_ship");
		break;

		case "Tortuga_Get_ready_for_Film2":
			LAi_fade("Tortuga_Get_ready_for_Film3", "Tortuga_Meet_Annamaria_for_ship");
		break;

		case "Tortuga_Get_ready_for_Film3":
			PChar.name = "Jack";
			PChar.lastname = "Sparrow";
			GiveModel2Player("Jack",true);
			SetCurrentTime(14.00, 0);

			ChangeCharacterAddressGroup(characterFromID("Weatherby Swann"), "redmond_residence", "goto", "goto8");
			Towns[GetTownIndex("Redmond")].gov = "Weatherby Swann";
			ChangeCharacterAddressGroup(characterFromID("John Clifford Brin"), "none", "", "");
			LAi_SetActorType(characterFromID("Storyteller"));
			LAi_ActorSetSitMode(characterFromID("Storyteller"));
			LAi_SetActorType(characterFromID("Annamaria"));
			ChangeCharacterAddressGroup(characterfromID("Annamaria"), "Tortuga_tavern", "goto", "goto2");
		break;

		case "Bootstrapwandersoff":
			LAi_SetActorType(characterFromID("Annamaria"));
			ChangeCharacterAddressGroup(characterfromID("Annamaria"), "Tortuga_tavern", "reload", "reload2");
			LAi_ActorGoToLocator(characterFromID("Bootstrap Bill Turner"), "reload", "reload1", "Bootstrapgoesoff2", 5.0);
		break;

		case "Pre_Tortuga_Meet_Annamaria_for_ship":
			LAi_SetPlayerType(pchar);
			LAi_SetSitType(pchar);
			LAi_QuestDelay("Tortuga_Meet_Annamaria_for_ship", 1.0);
			DoQuestReloadToLocation("Tortuga_tavern", "candles", "sit4", "_");
		break;

		case "Tortuga_Meet_Annamaria_for_ship":
			AddDataToCurrent(10,0,0, false);	// GR: It's supposed to be 10 years later, so make it 10 years later
			logit("Ten years later...");
			Characters[GetCharacterIndex("Storyteller")].dialog.currentnode = "Tavern_Story11";
			LAi_ActorDialog(characterFromID("Storyteller"), pchar, "", 0.0, 0.0);
		break;

		case "Tortuga_Meet_Annamaria_for_ship2":
			LAi_ActorGoToLocator(characterFromID("Annamaria"), "goto", "goto8", "Tortuga_Meet_Annamaria_for_ship3", 15.0);
		break;

		case "Tortuga_Meet_Annamaria_for_ship3":
			LAi_SetImmortal(characterFromID("Annamaria"), true);
			//LAi_ActorDialog(characterFromID("Annamaria"), pchar, "", 50.0, 10.0);
			LAi_ActorDialog(characterFromID("Annamaria"), pchar, "", 0.0, 0.0);
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "At_Tortuga_after_Loosing_Ship";
		break;

		case "Tortuga_Meet_Annamaria_for_ship4":
			//ChangeCharacterAddressGroup(pchar, "Tortuga_Tavern", "goto", "goto8");
			LAi_ActorGoToLocation(characterFromID("Annamaria"), "reload", "reload2", "none", "", "", "", 15.0);

			LAi_QuestDelay("Tortuga_Meet_Annamaria_for_ship5", 3.0);
		break;

		case "Tortuga_Meet_Annamaria_for_ship5":
			LAi_fade("Tortuga_Meet_Annamaria_for_ship6", "Tortuga_Meet_Annamaria_for_ship7");
		break;

		case "Tortuga_Meet_Annamaria_for_ship6":
			StorePassengers("Blaze");
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(pchar, "Tortuga_tavern", "goto", "goto8");
		break;

		case "Tortuga_Meet_Annamaria_for_ship7":
			pchar.quest.Compass_Jolly.win_condition.l1 = "location";
			pchar.quest.Compass_Jolly.win_condition.l1.location = "Tortuga_Port";
			pchar.quest.Compass_Jolly.win_condition = "Compass_Jolly";
		break;

		case "Compass_Jolly":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Jolly Mon";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "And_the_sail_to_Film_starts":
			//AddQuestRecord("Hector Barbossa", 10);
			AddQuestRecord("Stolen", 5);
			ChangeCharacterAddressGroup(characterFromID("Storyteller"), "none", "", "");

			pchar.quest.And_the_Film_Starts.win_condition.l1 = "location";
			pchar.quest.And_the_Film_Starts.win_condition.l1.location = "Redmond";
			pchar.quest.And_the_Film_Starts.win_condition = "And_the_Film_Starts";
		break;

//FILM STARTS HERE///////////////////////////////////////////////////////////////
		case "And_the_Film_Starts":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			if(GetOfficersIndex(Pchar, 3) != -1)
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "");
			}
			GiveShip2Character(characterFromID("James Norrington"),"HMS_Dauntless","Dauntless",-1,ENGLAND,true,true);
			GiveShip2Character(characterFromID("Port Guard"),"HMS_Interceptor","Interceptor",-1,ENGLAND,true,true);
			GiveShip2Character(pchar,"HMS_Interceptor","Interceptor",-1,ENGLAND,true,true);
			SetCrewQuantity(pchar, 2);
			AddCharacterGoods(pchar, GOOD_BALLS, 500);
			AddCharacterGoods(pchar, GOOD_GUNPOWDER, 2000);
			HoistFlag(ENGLAND);
			PChar.Flags.Personal = 1;	// GR: return to non-British personal flag
			PChar.Flags.Personal.texture = 3;
			SetCharacterShipLocation(characterFromID("James Norrington"), "Redmond_port");
			SetCharacterShipLocation(characterFromID("Port Guard"), "Redmond_port");
			SetCharacterShipLocation(Pchar, "Redmond_shore_01");
			SetCurrentTime(10, 0);
			SetNextWeather("Blue Sky");
			//CloseQuestHeader("Hector Barbossa");
			//SetQuestHeader("Times_with_Turner");
			ChangeCharacterAddress(characterFromID("Annamaria"), "None", "");
			Locations[FindLocation("Redmond_port")].vcskip = true;
			ChangeCharacterAddressGroup(characterfromID("Laurence Wellman"),"Redmond_port", "goto", "goto_33");
			ChangeCharacterAddressGroup(characterfromID("Morris Murtogg"), "Redmond_port", "goto", "goto_44");
			ChangeCharacterAddressGroup(characterfromID("Malvert Mullroy"), "Redmond_port", "officers", "Sea_1_3");
			LAi_SetActorType(characterFromID("Weatherby Swann"));
			LAi_SetActorType(characterFromID("Morris Murtogg"));
			Lai_SetActorType(characterFromID("Malvert Mullroy"));
			Lai_SetActorType(characterFromID("Laurence Wellman"));

			pchar.quest.You_need_to_pay_mooring.win_condition.l1 = "location";
			pchar.quest.You_need_to_pay_mooring.win_condition.l1.location = "Redmond_port";
			pchar.quest.You_need_to_pay_mooring.win_condition = "Jack's_arrival_at_Redmond2";
			DoReloadFromSeaToLocation("Redmond_port", "reload", "Sea_2_back");
			SetFleetInTown(GetTownIDFromLocID("Redmond_shore_01"), "pchar");
			//DoQuestCheckDelay("Jack's_arrival_at_Redmond2", 0.2);
		break;

		case "Jack's_arrival_at_Redmond":
			DoReloadFromSeaToLocation("Redmond_port", "reload", "Sea_2_back");
			SetFleetInTown(GetTownIDFromLocID("Redmond_shore_01"), "pchar");

			pchar.quest.You_need_to_pay_mooring.win_condition.l1 = "location";
			pchar.quest.You_need_to_pay_mooring.win_condition.l1.location = "Redmond_port";
			pchar.quest.You_need_to_pay_mooring.win_condition = "Jack's_arrival_at_Redmond2";
		break;

		case "Jack's_arrival_at_Redmond2":
			PostVideoAndQuest("LegendJackSparrow\jack_entrance", 25, "You_need_to_pay_mooring");
			bMainMenuLaunchAfterVideo = true;
		break;

		case "You_need_to_pay_mooring":
			PostEvent("DoInfoShower",100,"s","");
			Locations[FindLocation("Redmond_port")].reload.l4.disable = 1;
			Locations[FindLocation("Redmond_port")].reload.l5.disable = 1;
			Lai_ActorFollow(characterFromID("Laurence Wellman"), pchar, "You_need_to_pay_mooring2", 10.0);
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(Pchar, "officers", "sea_2_3", "", 10);
		break;

		case "You_need_to_pay_mooring2":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Laurence Wellman")].dialog.currentnode = "Mooring_Boat";
			LAi_ActorDialog(characterFromID("Laurence Wellman"), pchar, "", 10.0, 10.0);
		break;

		case "And_the_Film_Continues":
			LAi_ActorRunToLocator(characterFromID("Laurence Wellman"), "goto", "goto_31", "And_the_Film_Continues2", 5.0);
			ChangeCharacterAddressGroup(characterfromID("Morris Murtogg"), "Redmond_port", "officers", "Sea_1_2");
			ChangeCharacterAddressGroup(characterfromID("Malvert Mullroy"), "Redmond_port", "officers", "Sea_1_3");
		break;

		case "And_the_Film_Continues2":
			ChangeCharacterAddressGroup(characterFromID("Laurence Wellman"),"Redmond_Head_port_house","goto","locator1"); // PB
			LAi_SetStayType(characterFromID("Laurence Wellman"));
			Characters[GetCharacterIndex("Laurence Wellman")].dialog.currentnode = "First time";
			LAi_QuestDelay("And_the_Film_Continues3", 0.0);
		break;

		case "And_the_Film_Continues3":
			LAi_ActorGoToLocator(characterfromID("Malvert Mullroy"), "officers", "Sea_1_3", "", 0.0);
			LAi_SetActorType(pchar);
			LAi_QuestDelay("And_the_Film_Continues4", 0.0);
		break;

		case "And_the_Film_Continues4":
			//SetQuestHeader("Search_for_the_Black_Pearl");
			//AddQuestRecord("Search_for_the_Black_Pearl", 1);
			AddQuestRecord("Stolen", 8);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Malvert Mullroy"));
			LAi_QuestDelay("And_the_Film_Continues5", 1.0);
			pchar.quest.henry_talk = "henry_decide_on_Interceptor";
		break;

		case "And_the_Film_Continues5":
			LAi_ActorGoToLocator(characterfromID("Morris Murtogg"), "goto", "goto_44", "", 0.0);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "lookingattheInterceptor";
			LAi_ActorSelfDialog(Pchar, "player_back");
			pchar.quest.You_cant_park_That_Here.win_condition.l1 = "locator";
			pchar.quest.You_cant_park_That_Here.win_condition.l1.location = "Redmond_port";
			pchar.quest.You_cant_park_That_Here.win_condition.l1.locator_group = "goto";
			pchar.quest.You_cant_park_That_Here.win_condition.l1.locator = "goto_60";
			pchar.quest.You_cant_park_That_Here.win_condition = "You_cant_park_That_Here";

			pchar.quest.henry_talk = "henry_decide_on_Interceptor";
			Locations[FindLocation("Redmond_Town_01")].reload.l1.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l2.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l3.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l6.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l8.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l9.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l10.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l11.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l12.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l14.disable = 1;
			Locations[FindLocation("Redmond_Town_01")].reload.l15.disable = 1;

			locations[FindLocation("Redmond_town_01")].reload.l5.disable = 1;
			locations[FindLocation("Redmond_port")].reload.l5.disable = 1;
			locations[FindLocation("Redmond_port")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_port")].reload.l3.disable = 1;
			locations[FindLocation("Redmond_Shore_01")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_Shore_02")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_Residence")].reload.l1.disable = false;
		break;

// SJG Optional Side quest with Norrington - after talk with Henry the beggar.
		case "Dump_Interceptor_Quest":
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = false;
//			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "None", "");	// GR: Silehard isn't even in this story!
//			ChangeCharacterAddress(characterFromID(GetTownGovernorID("Redmond")), "None", "");	// GR: Doesn't seem necessary as no other governor appears, but this would make any current governor disappear
			Characters[GetCharacterIndex("James Norrington")].model = "Cpnorrington";
			ChangeCharacterAddressGroup(characterfromID("James Norrington"),"redmond_residence", "goto", "goto2");
			ChangeCharacterAddressGroup(characterfromID("Weatherby Swann"),"redmond_residence", "goto", "goto8");
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"),"redmond_residence", "goto", "goto9");
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_SetActorType(characterFromID("James Norrington"));
			LAi_SetStayType(characterFromID("Cutler Beckett"));

            pchar.quest.The_Big_Three.win_condition.l1 = "location";
            pchar.quest.The_Big_Three.win_condition.l1.location = "Redmond_Residence";
            pchar.quest.The_Big_Three.win_condition = "The_Big_Three";
		break;

		case "The_Big_Three":
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "goto", "goto3", "Dump_Interceptor_Quest2", 10.0);
		break;

		case "Dump_Interceptor_Quest2":
			LAi_ActorTurnToCharacter(characterFromID("Cutler Beckett"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("James Norrington"), Pchar);
			ChangeCharacterAddress(characterFromID("Morris Murtogg"), "none", "");
			ChangeCharacterAddress(characterFromID("Malvert Mullroy"), "none", "");
			LAi_ActorWaitDialog(pchar, characterFromID("Weatherby Swann"));
			Characters[GetCharacterIndex("Weatherby Swann")].Dialog.CurrentNode = "An_unholy_alliance";
			LAi_ActorDialog(characterFromID("Weatherby Swann"), Pchar, "", 2.0, 0);
		break;

		case "Swann_Norrington_Beckett":
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_SetImmortal(characterFromID("Cutler Beckett"), true);
			LAi_ActorWaitDialog(pchar, characterFromID("Cutler Beckett"));
			Characters[GetCharacterIndex("Cutler Beckett")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterFromID("Cutler Beckett"), Pchar, "", 2.0, 0);
		break;

		case "Beckett_Norrington_fight":
// option to break Norrington side quest
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetFightMode(PChar, true);
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(Pchar, false);
			LAi_ActorAttack(characterfromID("James Norrington"), pchar, "");
			LAi_ActorAttack(characterfromID("Cutler Beckett"), pchar, "");
			AddQuestRecord("Norrington", 6);
			CloseQuestHeader("Norrington");
		break;
// side quest continues
		case "Norrington_splutters":
			LAi_ActorWaitDialog(pchar, characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "Ally_with_pirates";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "", 2.0, 0);
		break;

		case "Swann_Norrington_Player":
			pchar.quest.henry_talk = "Swann_and_French_attack_plan";
			LAi_ActorWaitDialog(pchar, characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "Fix_it_line";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "", 2.0, 0);
		break;

		case "Continue_with_French_attack_plan":
			LAi_ActorWaitDialog(pchar, characterFromID("Weatherby Swann"));
			Characters[GetCharacterIndex("Weatherby Swann")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterFromID("Weatherby Swann"), Pchar, "", 2.0, 0);
		break;

		case "Continue_with_French_attack_plan2":
			pchar.quest.henry_talk = "Norrington_to_be_pirate";
			LAi_ActorWaitDialog(pchar, characterFromID("Weatherby Swann"));
			Characters[GetCharacterIndex("Weatherby Swann")].Dialog.CurrentNode = "French_attack_plan_continues";
			LAi_ActorDialog(characterFromID("Weatherby Swann"), Pchar, "", 2.0, 0);
		break;

		case "Norrington_As_A_Pirate":
			Locations[FindLocation("Redmond_Town_01")].reload.l1.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l2.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l3.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l6.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l8.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l9.disable = false;

			Locations[FindLocation("Redmond_Town_01")].reload.l11.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l12.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l14.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l15.disable = false;
			locations[FindLocation("Redmond_town_01")].reload.l5.disable = false;
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			AddQuestRecord("Norrington", 4);
			pchar.quest.You_cant_park_That_Here.over = "yes";
			pchar.quest.Turks_and_the_French = "powers_of_persuation";
			LAi_SetPlayerType(pchar);
			GiveShip2Character(pchar,"HMS_Surprise","Surprise",-1,ENGLAND,true,true);
			PChar.location.from_sea = "Redmond_Port";				// GR: If your last visit to Jamaica was at a beach, game thinks you're still there
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "PChar");	// GR: Move to port which is where your new ship is supposed to be
			AddPassenger(Pchar, characterFromID("James Norrington"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "serving_as_a_pirate";

			pchar.quest.Meet_Pieter_Boelen.win_condition.l1 = "location";
			pchar.quest.Meet_Pieter_Boelen.win_condition.l1.location = "Turks_tavern";
			pchar.quest.Meet_Pieter_Boelen.win_condition = "Meet_Pieter_Boelen";
		break;

		case "Meet_Pieter_Boelen":
			ChangeCharacterAddressGroup(characterfromID("Pieter Boelen"),"Turks_tavern", "goto", "goto6");
		break;

		case "Discussion_with_Norrington":
			LAi_Fade("Talk_with_Norrington_in_Tavern","");
		break;

		case "Talk_with_Norrington_in_Tavern":
			ChangeCharacterAddress(characterfromID("Pieter Boelen"),"none", "");
			DoQuestReloadToLocation("Turks_tavern_upstairs", "goto", "goto2", "Talk_with_Norrington_in_Tavern2");
			ChangeCharacterAddressGroup(characterfromID("James Norrington"), "Turks_tavern_upstairs", "goto", "goto4");
			LAi_SetActorType(characterFromID("James Norrington"));
		break;

		case "Talk_with_Norrington_in_Tavern2":
			LAi_ActorWaitDialog(pchar, characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "Talk_in_Turks_Tavern";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "", 2.0, 0);
		break;

		case "Farewell_at_the_dock":
			locations[FindLocation("Turks_port")].reload.l2.disable = 1;
			LAi_SetActorType(pchar);
			DoQuestReloadToLocation("Turks_port", "goto", "P_character2", "Farewell_at_the_dock2");		//JRH: new Turks, was character2
			ChangeCharacterAddressGroup(characterfromID("James Norrington"), "Turks_port", "goto", "P_goto5");		//JRH: new Turks, was goto5
			LAi_SetActorType(characterFromID("James Norrington"));
		break;

		case "Farewell_at_the_dock2":
			LAi_ActorWaitDialog(pchar, characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "Talk_at_Turks_Dock";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "", 2.0, 0);
		break;

		case "Norrington_sails_away":
			LAi_ActorGoToLocator(characterFromID("James Norrington"), "reload", "reload1", "Norrington_sails_away2", -1);
			AddQuestRecord("Norrington", "5");
			CloseQuestHeader("Norrington");
			LAi_SetPlayerType(pchar);
		break;

		case "Norrington_sails_away2":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			locations[FindLocation("Turks_port")].reload.l2.disable = false;
			GiveShip2Character(pchar,"Tartane50","Everyone Wins",-1,PIRATE,true,true);
			ChangeCharacterAddress(characterfromID("James Norrington"),"none", "");

			pchar.quest.Bootstrap_on_Turks.win_condition.l1 = "locator";
			pchar.quest.Bootstrap_on_Turks.win_condition.l1.location = "Turks_tavern";
			pchar.quest.Bootstrap_on_Turks.win_condition.l1.locator_group = "goto";
			pchar.quest.Bootstrap_on_Turks.win_condition.l1.locator = "goto7";
			pchar.quest.Bootstrap_on_Turks.win_condition = "Bootstrap_on_Turks";
		break;

		case "Bootstrap_on_Turks":
			pchar.quest.Turks_and_the_French = "turks quest again";
			LAi_SetActorType(pchar);
			LAi_fade("", "Bootstrap_on_Turks2");
			ChangeCharacterAddressGroup(CharacterFromID("Bootstrap Bill Turner"), "Turks_Tavern", "reload", "reload3");
			LAi_SetActorType(characterFromID("Bootstrap Bill Turner"));
		break;

		case "Bootstrap_on_Turks2":
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Bootstrap Bill Turner"));
			LAi_ActorWaitDialog(pchar, characterFromID("Bootstrap Bill Turner"));
			Characters[GetCharacterIndex("Bootstrap Bill Turner")].dialog.currentnode = "Bootstrap_at_Turks";
			Lai_ActorDialog(characterFromID("Bootstrap Bill Turner"), pchar, "", 3.0, 0);
		break;

		case "BootstrapleavesTurks":
			LAi_ActorGoToLocation(characterFromID("Bootstrap Bill Turner"), "reload", "reload3", "none", "", "", "", 0.0);
			ChangeCharacterAddressGroup(CharacterFromID("Oswald Chappel"), "Turks_Tavern", "reload", "reload1");
			LAi_SetActorType(characterFromID("Oswald Chappel"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Oswald Chappel"));
			LAi_QuestDelay("Will_and_the_Interceptor_captured", 0.0);
		break;

		case "Will_and_the_Interceptor_captured":
			LAi_ActorWaitDialog(pchar, characterFromID("Oswald Chappel"));
			Characters[GetCharacterIndex("Oswald Chappel")].dialog.currentnode = "First time";
			Lai_ActorDialog(characterFromID("Oswald Chappel"), pchar, "", 3.0, 0);
			GiveShip2Character(pchar,"HMS_Interceptor","Interceptor",-1,ENGLAND,true,true);
			SetCrewQuantity(pchar, 3);
			SetCharacterShipLocation(Pchar, "Turks_port");
		break;

		case "Purchase_Interceptor":
			SetNextWeather("Blue Sky");
			LAi_SetPlayerType(pchar);
			DoQuestReloadToLocation("Turks_port", "goto", "P_goto3", "Purchase_Interceptor2");		//JRH: new Turks, was goto3
			ChangeCharacterAddressGroup(characterfromID("Will Turner"), "Turks_port", "goto", "P_reload1_2");		//JRH: new Turks, was officers reload1_2
			ChangeCharacterAddressGroup(characterfromID("Crew_member_07"), "Turks_port", "goto", "P_goto4");		//JRH: new Turks, was goto4
			ChangeCharacterAddressGroup(characterfromID("Oswald Chappel"), "Turks_port", "goto", "P_character1");		//JRH: new Turks, was character1
			LAi_SetActorType(characterFromID("Oswald Chappel"));
			LAi_SetCivilianGuardianType(characterFromID("Crew_member_07"));
		break;

		case "Purchase_Interceptor2":
			LAi_ActorTurnToCharacter(PChar, characterFromID("Oswald Chappel"));
			LAi_ActorWaitDialog(pchar, characterFromID("Oswald Chappel"));
			Characters[GetCharacterIndex("Oswald Chappel")].Dialog.CurrentNode = "Interceptor_at_Turks_Dock";
			LAi_ActorDialog(characterFromID("Oswald Chappel"), Pchar, "", 2.0, 0);
		break;

		case "Purchase_Interceptor_now_Turner":
			LAi_SetActorType(characterFromID("Crew_member_07"));
			LAi_ActorGoToLocation(characterFromID("Oswald Chappel"), "goto", "goto15", "none", "", "", "", 0.0);
			LAi_ActorGoToLocation(characterFromID("Crew_member_07"), "goto", "goto15", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorWaitDialog(PChar,characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "talking on turks";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 10.0, 10.0);
		break;

		case "Turner_and_me_back to film":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 5000);}
			iForceDetectionFalseFlag = -1;
			HoistFlag(PIRATE);
			Locations[FindLocation("Tortuga_Port")].vcskip = true;	// GR: Otherwise Mr. Gibbs may not show up
			pchar.quest.Tortuga_for_Annamaria_after_Redmond.win_condition.l1 = "location";
			pchar.quest.Tortuga_for_Annamaria_after_Redmond.win_condition.l1.location = "Tortuga_port";
			pchar.quest.Tortuga_for_Annamaria_after_Redmond.win_condition = "Tortuga_for_Annamaria_after_Redmond";
		break;
// SJG End of side quest with Norrington. Original Interceptor quest continues below.
		case "You_cant_park_That_Here":
			Locations[FindLocation("Redmond_port")].reload.l4.disable = 1;
			Locations[FindLocation("Redmond_port")].reload.l5.disable = 1;
			if (pchar.quest.henry_talk == "not_taking_Interceptor")
			{
			break;
			}
			else
			{
			pchar.quest.henry_talk = "no_comment";
			ChangeCharacterAddressGroup(characterfromID("Malvert Mullroy"), "Redmond_port", "officers", "Sea_1_3");
			LAi_ActorWaitDialog(pchar, characterFromID("Morris Murtogg"));
			Characters[GetCharacterIndex("Morris Murtogg")].dialog.currentnode = "First time";
			Lai_ActorFollow(characterFromID("Morris Murtogg"), pchar, "You_cant_park_That_Here2", 3.0);
			}
		break;

		case "You_cant_park_That_Here2":
			Characters[GetCharacterIndex("Morris Murtogg")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterFromID("Morris Murtogg"), Pchar, "", 2.0, 0);
		break;

		case "I_know_that_ship":
			LAi_ActorGoToLocator(characterFromID("Morris Murtogg"), "officers", "Sea_1_1", "", -1);
			LAi_ActorTurnToCharacter(characterFromID("Morris Murtogg"), PChar);
			LAi_ActorWaitDialog(pchar, characterFromID("Malvert Mullroy"));
			Characters[GetCharacterIndex("Malvert Mullroy")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterFromID("Malvert Mullroy"), Pchar, "", 2.0, 0);
		break;

		case "what_are_you_up_to":
			Characters[GetCharacterIndex("Morris Murtogg")].dialog.currentnode = "speak4";
			LAi_ActorDialog(characterFromID("Morris Murtogg"), pchar, "", 2.0, 2.0);
		break;

		case "Hes_not_lying":
			Characters[GetCharacterIndex("Malvert Mullroy")].dialog.currentnode = "speak3";
			LAi_ActorDialog(characterFromID("Malvert Mullroy"), pchar, "", 2.0, 2.0);
		break;

		case "get_ready_for_the_splash":
			Characters[GetCharacterIndex("Morris Murtogg")].dialog.currentnode = "speak6";
			LAi_ActorDialog(characterFromID("Morris Murtogg"), pchar, "", 2.0, 2.0);
		break;

		case "can_you_swim":
			Characters[GetCharacterIndex("Malvert Mullroy")].dialog.currentnode = "speak5";
			LAi_ActorDialog(characterFromID("Malvert Mullroy"), pchar, "", 2.0, 2.0);
		break;

		case "Dive_time_prep":
			Characters[GetCharacterIndex("Morris Murtogg")].dialog.currentnode = "speak8";
			LAi_ActorDialog(characterFromID("Morris Murtogg"), pchar, "", 2.0, 2.0);
		break;

		case "Dives_in_water_for_Elizabeth":
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(pchar, "officers", "Sea_1_1", "dive_for_elizabeth", 3.0);
		break;

		case "dive_for_elizabeth":
			LAi_Fade("go_swimming_for_Elizabeth","");
		break;

		case "go_swimming_for_Elizabeth":
			PostVideoAndQuest("LegendJackSparrow\elizabeth_falls", 25, "After_Elizabeth_Sea_rescue");
			bMainMenuLaunchAfterVideo = true;
		break;

		case "After_Elizabeth_Sea_rescue":
			PostEvent("DoInfoShower",100,"s","");
			Characters[GetCharacterIndex("Elizabeth Swann")].model = "Liz1";
			ChangeCharacterAddressGroup(characterfromID("Elizabeth Swann"),"Redmond_port", "goto", "goto_45");
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "calling_the_black_pearl";
			LAi_ActorSelfDialog(Pchar, "player_back");
			LAi_QuestDelay("The_Black_Pearl_has_been_called", 0.0);
		break;

		case "The_Black_Pearl_has_been_called":
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(characterfromID("Red_soldier_2"), "Redmond_port", "goto", "goto_16");
			LAi_SetActorType(characterFromID("Red_soldier_2"));
			ChangeCharacterAddressGroup(characterfromID("Red_soldier_1"), "Redmond_port", "goto", "goto_18");
			LAi_SetActorType(characterFromID("Red_soldier_1"));
			LAi_SetActorType(characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].model = "Conorrington";
			ChangeCharacterAddressGroup(characterfromID("James Norrington"),"Redmond_port", "goto", "goto_58");
			ChangeCharacterAddressGroup(characterfromID("Weatherby Swann"),"Redmond_port", "goto", "goto_57");
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorTurnToCharacter(characterFromID("Elizabeth Swann"), pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Elizabeth Swann"));
			LAi_SetImmortal(characterFromID("Elizabeth Swann"), true);
			LAi_QuestDelay("The_Governor_and_Norrington_arrive", 0.0);
		break;

		case "The_Governor_and_Norrington_arrive":
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			Characters[GetCharacterIndex("Elizabeth Swann")].dialog.currentnode = "out_of_the_water";
			LAi_ActorDialog(characterFromID("Elizabeth Swann"), pchar, "", 10.0, 10.0);
			LAi_ActorGoToLocator(characterFromID("Morris Murtogg"), "goto", "goto_43", "", -1);
			LAi_ActorGoToLocator(characterFromID("Malvert Mullroy"), "goto", "goto_60", "", -1);
			LAi_ActorRunToLocator(characterFromID("James Norrington"), "officers", "Sea_1_2", "", 25.0);
			LAi_ActorRunToLocator(characterFromID("Weatherby Swann"), "goto", "goto_45", "The_Governor_and_Norrington_arrive2", 10.0);
		break;

		case "The_Governor_and_Norrington_arrive2":
			LAi_ActorTurnToCharacter(characterFromID("Weatherby Swann"), characterFromID("Elizabeth Swann"));
			pchar.quest.Beckett = "The_Governor_and_Norrington";
			LAi_ActorTurnToCharacter(characterFromID("James Norrington"), PChar);
			LAi_ActorWaitDialog(pchar, characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "The_Governor_and_Norrington";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "", 2.0, 0);
		break;

		case "Swann_starts_talking":
			Lai_ActorGoToLocator(characterfromID("Red_soldier_2"), "goto", "goto_17", "", -1);
			LAi_ActorTurnToCharacter(characterFromID("Red_soldier_2"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("Red_soldier_1"), PChar);			
			LAi_ActorGoToLocator(characterFromID("Malvert Mullroy"), "goto", "goto_44", "", -1);
			LAi_ActorTurnToCharacter(characterFromID("Morris Murtogg"), PChar);	
			LAi_ActorTurnToCharacter(characterFromID("Malvert Mullroy"), PChar);
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Weatherby Swann"));
			Characters[GetCharacterIndex("Weatherby Swann")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterFromID("Weatherby Swann"), Pchar, "", 2.0, 0);
		break;

		case "Escape_to_Shipyard_at_Redmond":
			LAi_ActorAnimation(pchar, "attack_fast_2", "Norrington_puch_up", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
			Lai_KillCharacter(characterFromID("Weatherby Swann"));
		break;

		case "Norrington_puch_up":
			LAi_SetStunnedTypeNoGroup(characterFromID("Elizabeth Swann"));
			LAi_ActorTurnToCharacter(characterFromID("James Norrington"), PChar);
			LAi_ActorWaitDialog(pchar, characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "Governor_knocked_out";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "", 2.0, 0);
		break;

		case "Off_to_shipyard_now":
			PlaySound("OBJECTS\duel\punch1.wav");
			LAi_SetStunnedTypeNoGroup(characterFromID("James Norrington"));
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(pchar,"goto","goto_44","Off_to_shipyard_now2", 2.0);
		break;

		case "Off_to_shipyard_now2":
			LAi_ActorAnimation(pchar, "attack_fast_2", "Off_to_shipyard_now3", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
			Lai_KillCharacter(characterFromID("Malvert Mullroy"));
		break;

		case "Off_to_shipyard_now3":
			LAi_ActorRunToLocator(pchar,"goto","goto_43","Off_to_shipyard_now4", 2.0);
		break;

		case "Off_to_shipyard_now4":
			LAi_ActorAnimation(pchar, "attack_fast_2", "Off_to_shipyard_now5", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
			Lai_KillCharacter(characterFromID("Morris Murtogg"));
			GiveItem2Character(Pchar, "blade4");  
			EquipCharacterByItem(Pchar, "blade4");
		break;

		case "Off_to_shipyard_now5":
			LAi_ActorRunToLocator(pchar, "goto", "goto_42", "Fight_Port_soldiers", 0.0); 
		break;

		case "Fight_Port_soldiers":
			LAi_SetActorType(characterFromID("James Norrington"));
			LAi_ActorAnimation(characterFromID("James Norrington"), "Ground_StandUp", "", 1.0);
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(Pchar, false);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_ActorAttack(characterfromID("Red_soldier_2"), pchar, "");
			LAi_ActorAttack(characterfromID("Red_soldier_1"), pchar, "");

			Pchar.quest.Off_to_shipyard_now6.win_condition.l1 = "NPC_Death";
			Pchar.quest.Off_to_shipyard_now6.win_condition.l1.character = "Red_soldier_2";
			Pchar.quest.Off_to_shipyard_now6.win_condition = "Off_to_shipyard_now6";
		break;

		case "Off_to_shipyard_now6":
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(pchar, "goto", "goto_17", "Off_to_shipyard_now7", 2.0);
		break;

		case "Off_to_shipyard_now7":
			LAi_Fade("Fight_with_Turner_in_Shipyard","");
		break;

		case "Fight_with_Turner_in_Shipyard":
			ChangeCharacterAddressGroup(characterfromID("Port Guard"), "Redmond_shipyard", "officers", "reload1_3");
			RemoveCharacterEquip(characterFromID("Will Turner"), GUN_ITEM_TYPE);
			EnableEquip(characterFromID("Will Turner"), GUN_ITEM_TYPE, false);
			LAi_SetPlayerType(pchar);
			DoQuestReloadToLocation("Redmond_shipyard", "goto", "goto1", "_");
			ChangeCharacterAddress(characterfromID("Roger Murray"),"none", "");
			ChangeCharacterAddressGroup(characterfromID("Will Turner"),"Redmond_shipyard", "goto", "goto2");
			LAi_SetImmortal(characterFromID("Will Turner"), true);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorWaitDialog(PChar,characterFromID("Will Turner"));
			LAi_ActorDialog(characterFromID("Will Turner"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Will Turner")].Dialog.CurrentNode = "shipyardfirst";
		break;

		case "Turner_Swordfight":
			LAi_SetFightMode(PChar, true);
			LAi_SetImmortal(Pchar, true);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetImmortal(characterFromID("Will Turner"), true);
			LAi_QuestDelay("Captured_by_Turner", 15.0);	
			LAi_ActorAttack(characterfromID("Will Turner"), pchar, "");
		break;

		case "Captured_by_Turner":
			LAi_SetFightMode(PChar, false);
			LAi_QuestDelay("Captured_by_Turner2", 1.0);	
		break;

		case "Captured_by_Turner2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			SetCharacterRelationBoth(GetCharacterIndex("Will Turner"), GetMainCharacterIndex(), RELATION_FRIEND);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorWaitDialog(PChar,characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "shipyardagain";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 10.0, 10.0);
		break;

		case "In_the_Clink":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(PChar, characterFromID("Port Guard"));
			LAi_QuestDelay("In_the_Clink2", 1.0);
		break;

		case "In_the_Clink2":
			LAi_SetPlayerType(pchar);
			LAi_ActorAnimation(characterfromID("Port Guard"), "attack_fast_2", "", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
			LAi_QuestDelay("Swann_put_me_in_prison", 1.0);
		break;

		case "Swann_put_me_in_prison":
			LAi_SetStunnedTypeNoGroup(PChar);
			LAi_QuestDelay("Swann_put_me_in_prison2", 2.0);
			Locations[FindLocation("Redmond_shipyard")].vcskip = true;
		break;

		case "Swann_put_me_in_prison2":
			DoQuestReloadToLocation("Redmond_prison", "goto", "goto9", "prepare_Swann_prison_complete");
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			ChangeCharacterAddress(characterfromID("Edgar Attwood"),"none", "");
			ChangeCharacterAddressGroup(characterfromID("Will Turner"),"Redmond_prison", "goto", "goto22");
			ChangeCharacterAddressGroup(characterfromID("Eng_soldier_5"),"Redmond_prison", "goto", "goto23");
			LAi_SetActorType(characterFromID("Will Turner"));
			Locations[FindLocation("Redmond_prison")].vcskip = true;

			ChangeCharacterAddressGroup(characterfromID("Port Guard"), "none", "", "");
			ChangeCharacterAddressGroup(characterfromID("Roger Murray"),"Redmond_shipyard", "sit", "sit_1"); // Talisman
		break;

		case "prepare_Swann_prison_complete":
			locations[FindLocation("Redmond_port")].reload.l4.disable = false;
			locations[FindLocation("Redmond_port")].reload.l5.disable = 0;
			ChangeCharacterAddress(characterFromID("Laurence Wellman"), "none", "");
			ChangeCharacterAddress(characterFromID("Morris Murtogg"), "none", "");
			ChangeCharacterAddress(characterFromID("Malvert Mullroy"), "none", "");
			ChangeCharacterAddress(characterFromID("James Norrington"), "none", "");
			ChangeCharacterAddress(characterFromID("Weatherby Swann"), "none", "");
			ChangeCharacterAddress(characterFromID("Elizabeth Swann"), "none", "");
			LAi_SetActorType(characterFromID("Eng_soldier_5"));
			LAi_ActorGoToLocator(characterFromID("Eng_soldier_5"), "goto", "goto23", "Edgar_for_Black_Pearl_attack", -1);
			Locations[FindLocation("Redmond_prison")].vcskip = true;
		break;

		case "Edgar_for_Black_Pearl_attack":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			pchar.quest.Turner = "Another_night_in_Jail";
			LAi_SetActorType(characterFromID("Eng_soldier_5"));
			characters[GetCharacterIndex("Eng_soldier_5")].Dialog.Filename = "Port Guard_dialog.c";
			characters[GetCharacterIndex("Eng_soldier_5")].dialog.currentnode = "inprison_blackpearlattack";
			LAi_ActorDialogNow(characterFromID("Eng_soldier_5"), pchar, "", -1);
		break;

		case "waiting_for_Turner":
			SetNextWeather("Black Pearl Fight");
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("BlackPearl", 100, "Skeleton Crew Arrive");
		break;

		case "Skeleton Crew Arrive":
			PostEvent("DoInfoShower",100,"s","");
			Characters[GetCharacterIndex("Treas_Pirate_6")].model = "Skel1";
			ChangeCharacterAddressGroup(characterfromID("Treas_Pirate_6"),"Redmond_prison", "goto", "goto13");
			LAi_SetActorType(characterFromID("Treas_Pirate_6"));

			Characters[GetCharacterIndex("Treas_Pirate_4")].model = "Skel2";
			ChangeCharacterAddressGroup(characterfromID("Treas_Pirate_4"),"Redmond_prison", "goto", "goto22");
			LAi_SetActorType(characterFromID("Treas_Pirate_4"));
			LAi_QuestDelay("Skeletons_In_prison", 5.0);
		break;

		case "Skeletons_In_prison":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_6"), "goto", "goto23", "", 7.0);
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_4"), "reload", "reload12", "Skeletons_In_prison2", 7.0);
		break;

		case "Skeletons_In_prison2":
			LAi_ActorTurnToCharacter(characterFromID("Treas_Pirate_4"), Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "pirates_in_prison";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "the_pirates_leave":
			SetQuestHeader("Curse Of");
			AddQuestRecord("Curse Of", 2);

//			LAi_ActorAnimation(characterFromID("James Norrington"), "Ground_StandUp", "", 1.0);
			ChangeCharacterAddressGroup(characterFromID("Weatherby Swann"), "redmond_residence", "goto", "goto8");
			LAi_type_actor_Reset(characterFromID("James Norrington")); //CTM (Resets Norrington to stand up)
			LAi_type_actor_Reset(characterFromID("Elizabeth Swann"));
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_6"), "goto", "goto13", "", -1);
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_4"), "goto", "goto13", "", -1);
			LAi_QuestDelay("Skeletons_are_gone", 4.0);
		break;

		case "Skeletons_are_gone":
			ChangeCharacterAddress(characterFromID("Treas_Pirate_6"), "none", "");
			ChangeCharacterAddress(characterFromID("Treas_Pirate_4"), "none", "");
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorGoToLocator(characterFromID("Will Turner"), "reload", "reload12", "Swann_and_prison2", -1);
			DeleteAttribute(&Locations[FindLocation("Redmond_port")],"vcskip");
		break;

		case "Swann_and_prison2":
			SetCurrentTime(10, 0);
			locations[FindLocation("Redmond_port")].reload.l5.disable = 0;
			locations[FindLocation("Redmond_prison")].reload.l1.disable = 1;
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorWaitDialog(pchar, characterFromID("Will Turner"));
			LAi_ActorDialog(characterFromID("Will Turner"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Will Turner")].Dialog.CurrentNode = "afterSkeletons";
		break;

		case "Turner_and_me_take_ship":
			PChar.location.from_sea = "Redmond_Port";				// GR: If your last visit to Jamaica was at a beach, game thinks you're still there
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "PChar");	// GR: Move to port which is where your new ship is supposed to be
			SetCurrentTime(10, 0);
			SetNextWeather("Blue Sky");
			locations[FindLocation("Redmond_port")].reload.l5.disable = 0;
			setCharacterShipLocation(characterFromID("James Norrington"), "Redmond_port");
			SetCharacterShipLocation(characterFromID("Port Guard"), "Redmond_port");
			pchar.quest.Turner = "Straight_from_Jail";
			ChangeCharacterAddressGroup(characterfromID("Will Turner"),"Redmond_port", "goto", "goto_2");
			DoQuestReloadToLocation("Redmond_port", "officers", "reload_2_city_3", "Turner_and_me_take_ship2");
		break;

		case "Turner_and_me_take_ship2":
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "First time";
			Locations[FindLocation("Redmond_Town_01")].reload.l1.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l2.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l3.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l6.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l8.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l9.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l10.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l11.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l12.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l14.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l15.disable = false;
			locations[FindLocation("Redmond_town_01")].reload.l5.disable = false;
			SetCurrentTime(10, 0);
			SetNextWeather("Blue Sky");
			pchar.quest.Turner = "Straight_from_Jail";
			LAi_SetImmortal(characterFromID("Will Turner"), true);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorWaitDialog(PChar,characterFromID("Will Turner"));
			LAi_ActorDialog(characterFromID("Will Turner"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Will Turner")].Dialog.CurrentNode = "Turner_Jail_Break";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 5000);}
			LAi_SetPlayerType(pchar);
			//SetQuestHeader("Times_with_Turner"); //CTM (changed where it starts: getting rid of quest book mucking up)
			//AddQuestRecord("Times_with_Turner", 1);
			AddQuestRecord("Curse Of", 1);

			SetCharacterShipLocation(Pchar, "Redmond_port");

			pchar.quest.Dauntless_vs_Int.win_condition.l1 = "location";
			pchar.quest.Dauntless_vs_Int.win_condition.l1.location = "Redmond";
			pchar.quest.Dauntless_vs_Int.win_condition = "Dauntless_vs_Int";

			Locations[FindLocation("Tortuga_Port")].vcskip = true;	// GR: Otherwise Mr. Gibbs may not show up
			pchar.quest.Tortuga_for_Annamaria_after_Redmond.win_condition.l1 = "location";
			pchar.quest.Tortuga_for_Annamaria_after_Redmond.win_condition.l1.location = "Tortuga_port";
			pchar.quest.Tortuga_for_Annamaria_after_Redmond.win_condition = "Tortuga_for_Annamaria_after_Redmond";
		break;

		case "Dauntless_vs_Int":
			Group_CreateGroup("James Norrington");
			Group_AddCharacter("James Norrington", "James Norrington");
			Group_SetGroupCommander("James Norrington", "James Norrington");
			Group_SetPursuitGroup("James Norrington", PLAYER_GROUP);
			Group_SetTaskAttack("James Norrington", PLAYER_GROUP, true);
			Group_LockTask("James Norrington");
			Group_SetAddress("James Norrington", "Redmond", "", "");
			Sea_LoginGroupNow("James Norrington");
			//SetRMRelation(PChar, ENGLAND, REL_WAR);
			UpdateRelations();

			DoQuestCheckDelay("Dauntless_vs_Int2", 0.5);
		break;

		case "Dauntless_Deck_JACK":
			pchar.vcskip = true;
			characters[GetCharacterIndex("Port Guard")].sailaway = true;
			SetCharacterShipLocation(characterFromID("Port Guard"), "ShipDeck3");
			DoQuestReloadToLocation("ShipDeck3", "rld", "wheel", "Dauntless_Deck_JACK2");
		break;

		case "Dauntless_Deck_JACK2":
			ChangeCharacterAddressGroup(characterFromID("Will Turner"), "ShipDeck3", "rld", "startloc");
			LAi_SetActorType(characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "Here_they_come";
			LAi_ActorDialog(characterFromID("Will Turner"),PChar,"",1.0,1.0);
			LAi_QuestDelay("Dauntless_Deck_NORR", 12.0);
		break;

		case "Dauntless_Deck_NORR":
			SetModelfromArray(PChar, GetModelIndex("Conorrington"));
			PChar.name = "James";
			PChar.lastname = "Norrington";

			pchar.sailaway = true;
			SetCharacterShipLocation(characterFromID("Port Guard"), "none");
			SetCharacterShipLocation(pchar, "ShipDeck3");
			DoQuestReloadToLocation("ShipDeck3", "rld", "loc11", "Dauntless_Deck_NORR1");
		break;

		case "Dauntless_Deck_NORR1":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "brtlut2_18", "rld", "loc11");
			sld.name = "Lieutenant";
			sld.lastname = "Gillette";
			sld.dialog.filename = "slave_dialog.c";
			GiveItem2Character(sld, "pistol1");
			GiveItem2Character(sld, "Blade1");
			EquipCharacterByItem(sld, "pistol1");
			EquipCharacterByItem(sld, "Blade1");
			sld.id = "Gillette";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor2", "rld", "wheel");
			sld.name = "Helmsman";
			sld.lastname = "";
			sld.dialog.filename = "slave_dialog.c";
			GiveItem2Character(sld, "pistol1");
			GiveItem2Character(sld, "Blade1");
			EquipCharacterByItem(sld, "pistol1");
			EquipCharacterByItem(sld, "Blade1");
			sld.id = "Helmsman";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Jack", "ships", "ship_1");
			// MAXIMUS 05.09.2018 ==>
			sld.name = TranslateString("", "Jack");
			sld.lastname = TranslateString("", "Sparrow");
			// MAXIMUS 05.09.2018 <==
			sld.dialog.filename = "slave_dialog.c";
			sld.id = "Jack_Sparrow";

			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "rld", "loc1", "Dauntless_Deck_NORR2", 100.0);

			DeleteAttribute(pchar, "sailaway"); // PB: Reset
		break;

		case "Dauntless_Deck_NORR2":
			LAi_SetActorType(characterFromID("Gillette"));
			LAi_ActorGoToLocator(characterFromID("Gillette"), "rld", "loc12", "", 100.0);
			LAi_SetPlayerType(pchar);
			PlaySound("OBJECTS\SHIPCHARGE\coll_ship2ship1.wav");
			//LAi_ActorTurnToLocator(pchar, "rld", "loc11");
			LAi_SetActorType(characterFromID("Jack_Sparrow"));
			Characters[GetCharacterIndex("Jack_Sparrow")].dialog.currentnode = "steal";
			LAi_ActorDialogNow(characterFromID("Jack_Sparrow"),PChar,"",1.0);
		break;

		case "Dauntless_Deck_NORR3":
			ChangeCharacterAddressGroup(characterFromID("Jack_Sparrow"), "none", "", "");
			LAi_SetActorType(Pchar);
			LAi_QuestDelay("Dauntless_Deck_NORR4", 2.0);
			LAi_ActorRunToLocator(pchar, "rld", "startloc", "", 100.0);
		break;

		case "Dauntless_Deck_NORR4":
			LAi_SetActorType(Pchar);
			pchar.dialog.currentnode = "Sail_back";
			LAi_ActorSelfDialog(pchar, "player_back");
		break;

		case "Dauntless_Deck_NORR5":
			LAi_SetActorType(characterFromID("Helmsman"));
			Characters[GetCharacterIndex("Helmsman")].dialog.currentnode = "disable";
			LAi_ActorDialogNow(characterFromID("Helmsman"),PChar,"",0.0);
		break;

		case "Dauntless_Deck_NORR6":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToLocator(pchar, "rld", "loc3");
			LAi_QuestDelay("Dauntless_Deck_NORR7", 5.0);
		break;

		case "Dauntless_Deck_NORR7":
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterFromID("Gillette"));
			Characters[GetCharacterIndex("Gillette")].dialog.currentnode = "best_pirate";
			LAi_ActorDialog(characterFromID("Gillette"),PChar,"",100.0,100.0);
		break;

		case "Dauntless_Deck_NORR8":
			GiveModel2Player("Jack", true);
			// MAXIMUS 05.09.2018 ==>
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			// MAXIMUS 05.09.2018 <==

			QuestToSeaLogin_PrepareLoc("Redmond", "reload", "reload_fort1", true);
			QuestToSeaLogin_Launch();
		break;

		case "Dauntless_vs_Int2":
			Ship_SetTaskDrift(PRIMARY_TASK, GetCharacterIndex("James Norrington"));
			Ship_SetTaskDrift(SECONDARY_TASK, GetCharacterIndex("James Norrington"));

			Pchar.quest.Dauntless_vs_Int3.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Dauntless_vs_Int3.win_condition.l1.location = "Redmond";
			Pchar.quest.Dauntless_vs_Int3.win_condition = "Dauntless_vs_Int3";
		break;

		case "Dauntless_vs_Int3":
			HoistFlag(PIRATE);
		break;
// Bartolomeu o Portugues CotBP Starts Here
		case "Tortuga_for_Annamaria_after_Redmond":
			iForceDetectionFalseFlag = 0;
			LAi_SetActorType(characterFromID("Will Turner"));
			Lai_ActorFollow(characterFromID("Will Turner"), pchar, "Tortuga_for_Annamaria_after_Redmond_2", 3.0);
		break;

		case "Tortuga_for_Annamaria_after_Redmond_2":
			pchar.quest.Turner = "Change_over_to_Bartolomeu_Quest";
			characters[GetCharacterIndex("Will Turner")].Dialog.Filename = "Will Turner_dialog.c";
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorDialog(characterFromID("Will Turner"),PChar,"",10.0,1.0);
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "begin_28";
		break;

		case "voirgibbs":
			RemovePassenger(pchar, characterFromID("Will Turner"));
			RemoveCharacterCompanion(pchar, characterFromID("Will Turner"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Will Turner"));
			PChar.quest.Muerte = "search";
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 10.0);
			LAi_SetOfficerType(CharacterFromID("Will Turner"));
			ChangeCharacterAddressGroup(CharacterFromID("Mr. Gibbs"), "Tortuga_port", "goto", "goto26"); // furkan
			LAi_SetPoorType(CharacterFromID("Mr. Gibbs"));
		break;

		case "Goto Tortuga Tavern":
			Locations[FindLocation("Tortuga_Port")].vcskip = true;
			DoReloadCharacterToLocation("Tortuga_tavern", "candles", "sit4");
			bSuppressResurrection = true;
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_SetActorType(characterFromID("Mr. Gibbs"));
			LAi_ActorSetSitMode(characterFromID("Mr. Gibbs"));
			ChangeCharacterAddressGroup(CharacterFromID("Mr. Gibbs"), "Tortuga_tavern", "candles", "sit5");
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"), "Tortuga_port", "goto", "goto16");
			Characters[GetCharacterIndex("Mr. Gibbs")].dialog.currentnode = "begin_4";
			LAi_ActorWaitDialog(CharacterFromID("Mr. Gibbs"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Mr. Gibbs"),"", 10.0, 10.0);
		break;

		case "meetthecrew":
	//JRH remove temporary townpeople here
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_patrol_1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_patrol_2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("William Neal"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Peter Rodgers"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Claire Rodgers"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_3"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_4"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_5"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_6"), "none", "", "");

			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_carpenter1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_carpenter2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen3"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen4"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen5"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen6"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen7"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen8"), "none", "", "");

			DoReloadCharacterToLocation("Tortuga_port", "goto", "goto16");
			ChangeCharacterAddressGroup(CharacterFromID("Mr. Gibbs"), "Tortuga_port", "goto", "goto20");
 			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Mr. Gibbs"));
			Characters[GetCharacterIndex("Mr. Gibbs")].dialog.currentnode = "begin_11";
			LAi_ActorWaitDialog(CharacterFromID("Mr. Gibbs"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Mr. Gibbs"), "", 10.0, 5.0);
			LAi_SetOfficerType(CharacterFromID("Will Turner"));
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"), "Tortuga_port", "goto", "goto16");
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_SetImmortal(CharacterFromID("Will Turner"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);
			Pchar.quest.meetcrew.win_condition.l1 = "location";
			Pchar.quest.meetcrew.win_condition.l1.location = "Tortuga_port";
			PChar.quest.meetcrew.win_condition = "createcrew";
		break;

		case "createcrew":
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"), "Tortuga_port", "goto", "goto16");
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "black_corsair", "goto", "goto19");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.id = "crewman1";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "brodyaga", "goto", "goto19");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.id = "crewman2";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man4", "goto", "goto19");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.id = "crewman3";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "fatman1", "goto", "goto19");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.id = "crewman4";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "fawn", "goto", "goto19");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.id = "crewman5";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "chelovek", "goto", "goto19");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.id = "crewman";
			LAi_SetActorType(CharacterFromID("crewman"));
			LAi_ActorFollow(CharacterFromID("crewman"),pchar,"",2.0);
			reStorePassengers(pchar.id);
		break;

		case "voirAnnamaria":
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(Pchar, true);
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 10.0);
			ChangeCharacterAddressGroup(CharacterFromID("Annamaria"), "Tortuga_port", "rld", "aloc11");
			LAi_SetActorType(characterFromID("Annamaria"));
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "holdfornow";
			LAi_ActorDialog(characterFromID("Annamaria"), pchar, "", 50.0, 10.0);
		break;

		case "gifleAnnamaria":
			Lai_SetActorType(characterFromID("Annamaria"));
			LAi_ActorAnimation(characterFromID("Annamaria"), "attack_fast_2", "boatAnnamaria", -1);
			PlaySound("OBJECTS\duel\punch1.wav"); 
		break;

		case "boatAnnamaria":
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Annamaria"), pchar, "", 10.0, 10.0);
		break;

		case "Interceptorgift":
			LAi_SetActorType(characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "begin_18";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 10.0, 10.0);
		break;

		case "partirtortue":
			Characters[GetCharacterIndex("Annamaria")].dialog.currentnode = "begin_3";
			LAi_ActorDialog(characterFromID("Annamaria"), pchar, "", 10.0, 10.0);
		break;

		case "partirtortuebis":
			pchar.money = 1000;
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");
			LAi_SetActorType(characterFromID("Annamaria"));
			LAi_ActorRunToLocation(characterFromID("Annamaria"), "reload", "reload1", "none", "", "", "", 6.0);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);
			Characters[GetCharacterIndex("Mr. Gibbs")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Mr. Gibbs"), pchar, "", 10.0, 10.0);
			LAi_SetActorType(characterFromID("crewman1"));
			LAi_ActorRunToLocation(characterFromID("crewman1"), "reload", "reload1", "none", "", "", "", 6.0);
			LAi_SetActorType(characterFromID("crewman2"));
			LAi_ActorRunToLocation(characterFromID("crewman2"), "reload", "reload1", "none", "", "", "", 6.0);
			LAi_SetActorType(characterFromID("crewman3"));
			LAi_ActorRunToLocation(characterFromID("crewman3"), "reload", "reload2", "none", "", "", "", 6.0);
			LAi_SetActorType(characterFromID("crewman4"));
			LAi_ActorRunToLocation(characterFromID("crewman4"), "reload", "reload2", "none", "", "", "", 6.0);
			LAi_SetActorType(characterFromID("crewman5"));
			LAi_ActorRunToLocation(characterFromID("crewman5"), "reload", "reload2", "none", "", "", "", 6.0);
			LAi_SetActorType(characterFromID("crewman"));
			LAi_ActorRunToLocation(characterFromID("crewman"), "reload", "reload2", "none", "", "", "", 6.0);
			Characters[GetCharacterIndex("Mr. Gibbs")].dialog.currentnode = "begin_12";
			LAi_SetActorType(characterFromID("Mr. Gibbs"));
			LAi_ActorDialog(characterFromID("Mr. Gibbs"), pchar, "", 10.0, 10.0);
		break;

		case "directionislademuerta":
			DeleteAttribute(pchar,"vcskip"); // PB
			DeleteAttribute(Locations[FindLocation("Tortuga_Port")],"vcskip");

			LAi_SetImmortal(Pchar, false);
			//CloseQuestHeader("Times_with_Turner");
			//SetQuestHeader("IslaDeMuerteI");
			//AddQuestRecord("IslaDeMuerteI", 1);
			AddQuestRecord("Curse Of", 3);

			PChar.quest.Muerte = "allerislademuerte";
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Mr. Gibbs")); 
			LAi_SetOfficerType(CharacterFromID("Mr. Gibbs"));
			SetCrewQuantity(pchar, makeint(GetCrewQuantity(pchar) + 15));

	//JRH return townpeople here
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_1"), "Tortuga_port", "goto", "goto23");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_2"), "Tortuga_port", "goto", "goto21");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_patrol_1"), "Tortuga_port", "goto", "goto18");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_patrol_2"), "Tortuga_port", "goto", "goto12");
			ChangeCharacterAddressGroup(CharacterFromID("William Neal"), "Tortuga_port", "goto", "goto5");
			ChangeCharacterAddressGroup(CharacterFromID("Peter Rodgers"), "Tortuga_port", "patrol", "patrol2");
			ChangeCharacterAddressGroup(CharacterFromID("Claire Rodgers"), "Tortuga_port", "goto", "goto15");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_3"), "Tortuga_port", "soldiers", "soldier1");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_4"), "Tortuga_port", "soldiers", "soldier2");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_5"), "Tortuga_port", "soldiers", "soldier3");
			ChangeCharacterAddressGroup(CharacterFromID("Tor_soldier_6"), "Tortuga_port", "soldiers", "soldier4");

			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_carpenter1"), "Tortuga_port", "stay", "repair1");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_carpenter2"), "Tortuga_port", "stay", "repair2");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen1"), "Tortuga_port", "goto", "goto39");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen2"), "Tortuga_port", "goto", "goto30");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen3"), "Tortuga_port", "goto", "goto5");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen4"), "Tortuga_port", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen5"), "Tortuga_port", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen6"), "Tortuga_port", "goto", "goto34");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen7"), "Tortuga_port", "goto", "goto37");
			ChangeCharacterAddressGroup(CharacterFromID("Tortuga_citizen8"), "Tortuga_port", "goto", "goto28");

			Pchar.quest.muerte_with_Gibbs_and_Turner.win_condition.l1 = "location";
			Pchar.quest.muerte_with_Gibbs_and_Turner.win_condition.l1.location = "IslaDemuerte_shore_01";
			PChar.quest.muerte_with_Gibbs_and_Turner.win_condition = "muerte_with_Gibbs_and_Turner";
		break;

		case "muerte_with_Gibbs_and_Turner":
			characters[GetCharacterIndex("Will Turner")].Dialog.Filename = "Will Turner_dialog.c";
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorDialog(characterFromID("Will Turner"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "On_the_Beach_with_Gibbs";
//			LAi_QuestDelay("muerte_with_Gibbs_and_Turner2", 0.0);
		break;

		case "muerte_with_Gibbs_and_Turner2":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Mr. Gibbs"));
			LAi_SetOfficerType(characterFromID("Will Turner"));
			Pchar.quest.meetcrew.win_condition.l1 = "location";
			Pchar.quest.meetcrew.win_condition.l1.location = "Grotto";
			PChar.quest.meetcrew.win_condition = "allercavern";
		break;

		case "allercavern":
			LAi_QuestDelay("allercavern2", 2.0);
		break;

		case "allercavern2":
			DoQuestReloadToLocation("Grotto", "goto", "goto8", "crewbarbossa");
			ChangeCharacterAddressGroup(CharacterFromID("Barbossa"),"Grotto","goto","goto4");
			LAi_SetMerchantType(characterFromID("Barbossa"));
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"),"Grotto","goto","goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Elizabeth Swann"),"Grotto","goto","goto5");
			SetNextWeather("Moon Night");
		break;

		case "crewbarbossa":
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel1", "goto", "goto9");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel2", "goto", "goto6");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel3", "goto", "goto7");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel4", "goto", "goto10");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Bmunk", "goto", "goto14");
			LAi_SetHP(sld, 100.0, 100.0);
			RemovePassenger(pchar, characterFromID("Mr. Gibbs"));
			RemoveCharacterCompanion(pchar, characterFromID("Mr. Gibbs"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Mr. Gibbs"));

			PostVideoAndQuest("LegendJackSparrow\barbossa_speach", 25, "parlerwill");
			bMainMenuLaunchAfterVideo = true;
		break;

		case "parlerwill":
			PostEvent("DoInfoShower",100,"s","");
			Lai_SetActorType(characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "begin_20";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 10.0, 10.0);
		break;

		case "coupwill":
			Lai_SetActorType(characterFromID("Will Turner"));
			LAi_ActorAnimation(characterFromID("Will Turner"), "attack_fast_2", "revoirbarbossa", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
		break;

/* Original version: 'Lai_KillCharacter(pchar)' can really kill player character and end the game
		case "revoirbarbossa":
			Lai_KillCharacter(pchar);
			SetNextWeather("Blue Sky");
			ChangeCharacterAddress(characterFromID("Elizabeth Swann"), "none", "");
			LAi_QuestDelay("revoirbarbossa2", 3.0);
		break; */

		case "revoirbarbossa":
			SetNextWeather("Blue Sky");
			ChangeCharacterAddress(characterFromID("Elizabeth Swann"), "none", "");
			LAi_SetActorType(PChar);
			LAi_ActorAnimation(PChar, "death_3", "revoirbarbossa2", 2.0);
		break;

		case "revoirbarbossa2":
			SetNextWeather("Blue Sky");
			DoQuestReloadToLocation("Grotto", "goto", "goto5", "amisbarbossa");
		break;

		case "amisbarbossa":
			SetNextWeather("Blue Sky");
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel1", "goto", "goto9");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel2", "goto", "goto6");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel3", "goto", "goto7");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel4", "goto", "goto10");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Bmunk", "goto", "goto14");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_SetPlayerType(PChar);
			PChar.quest.old_pirate_flag = PChar.flags.pirate;
			PChar.quest.old_pirate_flag.texture = PChar.flags.pirate.texture;
			ChangeCharacterAddress(characterFromID("Will Turner"), "none", "");
			LAi_SetActorType(characterFromID("Barbossa"));
			Characters[GetCharacterIndex("Barbossa")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Barbossa"), pchar, "", 10.0, 10.0);
		break;
// -->SJG
		case "insertforchase":
			StorePassengers(Pchar.id);
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Pintel"));
			SetOfficersIndex(PChar, 2, GetCharacterIndex("Ragetti"));
			HoistFlag(PIRATE);
			GiveShip2Character(CharacterFromID("Mr. Gibbs"),"HMS_Interceptor","Interceptor",-1,ENGLAND,true,true);
			characters[GetCharacterIndex("Mr. Gibbs")].quest.old_group = GetAttribute(CharacterFromID("Mr. Gibbs"),"chr_ai.group");
			LAi_group_MoveCharacter(CharacterFromID("Mr. Gibbs"), "QC_SOLDIERS");
			DoQuestReloadToLocation("IslaDemuerte_shore_01", "goto", "citizen07", "insertforchase2");
			RemovePassenger(pchar, characterFromID("Barbossa"));
			RemoveCharacterCompanion(pchar, characterFromID("Barbossa"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Barbossa"));
			LAi_SetActorType(characterFromID("Barbossa"));
			ChangeCharacterAddress(characterFromID("Barbossa"), "none", "");					// GR: Make real Barbossa disappear so you aren't looking at yourself
		break;

		case "insertforchase2":
//			ChangeCharacterAddressGroup(CharacterFromID("Barbossa"),"IslaDemuerte_shore_01","goto","locator10");	// GR: Why? You're Barbossa now!
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel1", "goto", "locator08");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel2", "goto", "locator12");
			LAi_SetHP(sld, 100.0, 100.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel3", "goto", "locator25");
			LAi_SetHP(sld, 100.0, 100.0);
			Characters[GetCharacterIndex("Mr. Gibbs")].nation = ENGLAND;

			SetCurrentTime(10.00, 0);
			SetNextWeather("Blue Sky");
			Group_CreateGroup("Mr. Gibbs");
			Group_AddCharacter("Mr. Gibbs", "Mr. Gibbs");
			Group_SetGroupCommander("Mr. Gibbs", "Mr. Gibbs");
			Group_SetTaskRunAway("Mr. Gibbs");
			Group_LockTask("Mr. Gibbs");
			Group_SetAddress("Mr. Gibbs", "IsladeMuerte", "Quest_ships", "Quest_Ship_1");
			Sea_LoginGroupNow("Mr. Gibbs");
			characters[GetCharacterIndex("Mr. Gibbs")].nosurrender = 2;
			SetCharacterRelationBoth(GetCharacterIndex("Mr. Gibbs"),GetMainCharacterIndex(),RELATION_ENEMY);
//			if(GetRMRelation(PChar, PIRATE) > REL_WAR) SetRMRelation(PChar, PIRATE, REL_WAR);	// GR: Not needed, "Mr. Gibbs" will be hostile anyway, and you might have earned some rank with Pirates by now
			characters[GetCharacterIndex("Mr. Gibbs")].recognized = true;
			Character_SetAbordageEnable(characterFromID("Mr. Gibbs"), false);
			LAi_SetImmortal(characterFromID("Mr. Gibbs"), false); // PB: Just in case
			UpdateRelations();

			PChar.seamusic = "Black_Pearl";			// GR: normal music detection of battle isn't working so force it with custom music

			Pchar.quest.InterceptorDestroyed.win_condition.l1 = "Ship_HP";
			Pchar.quest.InterceptorDestroyed.win_condition.l1.character = "Mr. Gibbs";
			Pchar.quest.InterceptorDestroyed.win_condition.l1.quantity = 1500;
			Pchar.quest.InterceptorDestroyed.win_condition.l1.operation = "<";
			Pchar.quest.InterceptorDestroyed.win_condition = "InterceptorDestroyed";
		break;

		case "InterceptorDestroyed":
			DeleteAttribute(PChar, "seamusic");
			LAi_group_MoveCharacter(CharacterFromID("Mr. Gibbs"), characters[GetCharacterIndex("Mr. Gibbs")].quest.old_group);
			DeleteAttribute(CharacterFromID("Mr. Gibbs"), "quest.old_group");
			DeleteAttribute(CharacterFromID("Mr. Gibbs"), "recognized");
			SetNextWeather("Blue Sky");
			// PB: Back to Jack -->
			// MAXIMUS 05.09.2018 ==>
			PChar.name = TranslateString("", "Jack");
			PChar.lastname = TranslateString("", "Sparrow");
			// MAXIMUS 05.09.2018 <==
			GiveModel2Player("Jack",true);
//			PChar.Flags.Pirate = 6; // PB: Jack Sparrow Pirate Flag
//			PChar.Flags.Pirate.texture = 0;
			PChar.flags.pirate = PChar.quest.old_pirate_flag;	// GR: whatever pirate flag you were using before the battle
			PChar.flags.pirate.texture = PChar.quest.old_pirate_flag.texture;
			DeleteAttribute(PChar, "quest.old_pirate_flag");
			RemoveOfficersIndex(PChar, GetCharacterIndex("Pintel"));
			RemoveOfficersIndex(PChar, GetCharacterIndex("Ragetti"));
			RemovePassenger(PChar, CharacterFromID("Pintel"));
			RemovePassenger(PChar, CharacterFromID("Ragetti"));
			RestorePassengers(PChar.id);
			// PB: Back to Jack <--
			SetCharacterShipLocation(CharacterFromID("Mr. Gibbs"), "ShipDeck7"); // PB
//			DoQuestReloadToLocation("Black_Pearl", "rld", "loc1", "nowCapturedInterceptorCrew");
			DoQuestReloadToLocation("ShipDeck7", "goto", "goto7", "nowCapturedInterceptorCrew");
		break;
// <--SJG
		case "nowCapturedInterceptorCrew":
			// PB -->
			Ship_Detonate(CharacterFromID("Mr. Gibbs"), true, false);
			Ship_Detonate(CharacterFromID("Mr. Gibbs"), true, false);
			Ship_Detonate(CharacterFromID("Mr. Gibbs"), true, false);
			Ship_Detonate(CharacterFromID("Mr. Gibbs"), true, false);
			// PB <--
			ChangeCharacterAddressGroup(CharacterFromID("Elizabeth Swann"), "ShipDeck7", "reload", "reload13"); //"Black_Pearl","reload","reload2");
			ChangeCharacterAddressGroup(CharacterFromID("Barbossa"), "ShipDeck7", "goto", "goto14"); // "Black_Pearl", "rld", "aloc12");
			LAi_SetStayType(characterFromID("Barbossa"));

//			sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "Black_Corsair", "rld", "loc14");
//			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

//			sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "fawn", "rld", "loc2");
//			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

//			sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "chelovek", "rld", "loc0");
//			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
//			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
//			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);

//			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel1", "rld", "loc11");
//			sld.id = "crewmanb1";
//			LAi_SetImmortal(characterFromID("crewmanb1"), true);
//			LAi_group_MoveCharacter(sld, "CREW_BARBOSSA");
//			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel2", "goto", "goto1");
//			sld.id = "crewmanb2";
//			LAi_SetImmortal(characterFromID("crewmanb2"), true);
//			LAi_group_MoveCharacter(sld, "CREW_BARBOSSA");
//			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel4", "rld", "loc15");
//			sld.id = "crewmanb3";
//			LAi_SetImmortal(characterFromID("crewmanb3"), true);
//			LAi_group_MoveCharacter(sld, "CREW_BARBOSSA");
//			LAi_group_FightGroups("CREW_BARBOSSA", LAI_GROUP_PLAYER, true);	
//			LAi_QuestDelay("parlercrewbp", 4.0);
			Lai_QuestDelay("denouveaului", 4.0);
		break;
// work around till decks decided apon
/*		case "parlercrewbp":
			LAi_ActorAttack(characterfromID("Black_corsair"),"CREW_BARBOSSA", "nowCapturedInterceptorCrew");
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel3", "rld", "loc12");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.dialog.filename = "Annamaria_dialog.c";
			sld.id = "crewmanb";
			LAi_SetActorType(characterFromID("crewmanb"));
			Characters[GetCharacterIndex("crewmanb")].dialog.currentnode = "begin_5";
			LAi_ActorDialog(characterFromID("crewmanb"), pchar, "", 10.0, 10.0);
		break;

		case "giflecrewb":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("crewmanb"));
			LAi_ActorAnimation(pchar, "attack_fast_2", "giflecrewbis", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
		break;

		case "giflecrewbis":
			Lai_KillCharacter(characterFromID("crewmanb"));
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "joinmycrew";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "allerinterceptor":
			pchar.quest.denouveaului.win_condition.l1 = "locator";
			pchar.quest.denouveaului.win_condition.l1.location = "Black_Pearl";
			pchar.quest.denouveaului.win_condition.l1.locator_group = "rld";
			pchar.quest.denouveaului.win_condition.l1.locator = "aloc11";
			pchar.quest.denouveaului.win_condition = "denouveaului";
		break;
*/ //end work around
		case "denouveaului":
			SetNextWeather("Blue Sky");
//			LAi_group_FightGroups("CREW_BARBOSSA", LAI_GROUP_PLAYER, false);
			LAi_SetActorType(characterFromID("Barbossa"));
			Characters[GetCharacterIndex("Barbossa")].dialog.currentnode = "begin_4";
			LAi_ActorDialog(characterFromID("Barbossa"), pchar, "", 50.0, 10.0);
//			LAi_SetActorType(CharacterFromID("crewmanb1"));
//			LAi_ActorFollow(CharacterFromID("crewmanb1"),characterFromID("Barbossa"),"",3.0);
//			LAi_SetActorType(CharacterFromID("crewmanb2"));
//			LAi_ActorFollow(CharacterFromID("crewmanb2"),characterFromID("Barbossa"),"",3.0);
		break;

		case "Turner_Buts_In":
			LAi_ActorTurnToCharacter(characterFromID("Barbossa"), characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "It_Is_Me_You_Want";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 50.0, 10.0);
		break;

		case "Elizabeth_and_me_to_Island":
			Characters[GetCharacterIndex("Barbossa")].dialog.currentnode = "begin_4X";
			LAi_ActorDialog(characterFromID("Barbossa"), pchar, "", 50.0, 10.0);
		break;

		case "allersurilot":
			// PB -->
			GiveShip2Character(characterFromID("Barbossa"),SHIP_CURSED,TranslateString(PreprocessText("#scursed_ship#"), ""),-1,PIRATE,true,true);
			//setCharacterShipLocation(characterFromID("BP"), "Deserted_Island_shore_01");
			setCharacterShipLocation(characterFromID("Barbossa"), "Deserted_Island_shore_01");
			characters[GetCharacterIndex("Barbossa")].sailaway = true;
			// PB <--
			DoQuestReloadToLocation("Deserted_Island_shore_01", "officers", "reload1_3", "_");
			ChangeCharacterAddressGroup(CharacterFromID("Elizabeth Swann"),"Deserted_Island_shore_01", "goto", "locator10");
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			Characters[GetCharacterIndex("Elizabeth Swann")].dialog.currentnode = "begin_8";
			LAi_ActorDialog(characterFromID("Elizabeth Swann"), pchar, "", 20.0, 10.0);
			locations[FindLocation("Deserted_island_Jungle_01")].vcskip = true;
		break;

		case "voirdauntless":
			//AddQuestRecord("IslaDeMuerteI", "2");
			AddQuestRecord("Curse Of", 4);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Swann"), "", 60.0);
			Pchar.quest.joindredauntless.win_condition.l1 = "location";
			Pchar.quest.joindredauntless.win_condition.l1.location = "Deserted_Island_shore_02";
			PChar.quest.joindredauntless.win_condition = "engagerdauntless";
		break;

		case "engagerdauntless":
			LAi_type_actor_Reset(characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].model = "Conorrington";
			ChangeCharacterAddressGroup(CharacterFromID("James Norrington"),"Deserted_Island_shore_02","goto","locator14");
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Soldier_Eng4_18", "goto", "citizen04"); // TALISMAN model corrected
			sld.id = "crewmand1";
			LAi_group_MoveCharacter(sld, "CREW_DAUNTLESS");
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Soldier_Eng2_18", "goto", "locator13"); // TALISMAN model corrected
			sld.id = "crewmand2";
			LAi_group_MoveCharacter(sld, "CREW_DAUNTLESS");
			LAi_QuestDelay("talktoNorringtononIsland", 1.0);
		break;

		case "talktoNorringtononIsland":
			LAi_SetActorType(characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].Dialog.Filename = "James Norrington_Dialog.c";
			Characters[GetCharacterIndex("James Norrington")].dialog.currentnode = "begin_1_on_Island";
			LAi_ActorDialog(characterFromID("James Norrington"), pchar, "", 30.0, 10.0);
			LAi_SetActorType(CharacterFromID("crewmand1"));
			LAi_ActorFollow(CharacterFromID("crewmand1"),characterFromID("James Norrington"),"",6.0);
			LAi_SetActorType(CharacterFromID("crewmand2"));
			LAi_ActorFollow(CharacterFromID("crewmand2"),characterFromID("James Norrington"),"",6.0);
			SetNextWeather("Moon Night");
		break;

		case "abordauntless":
			DoQuestReloadToLocation("Black_Pearl", "rld", "aloc15", "equipage");
            ChangeCharacterAddressGroup(CharacterFromID("James Norrington"), "Black_Pearl", "rld", "aloc14");
			Characters[GetCharacterIndex("James Norrington")].dialog.CurrentNode = "begin_3";
			LAi_ActorDialog(characterFromID("James Norrington"), pchar, "", 10.0, 10.0);
		break;

		case "equipage":
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Soldier_Eng4_18", "goto", "goto1"); // TALISMAN model corrected
			LAi_SetCitizenType(sld);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Soldier_Eng2_18", "rld", "loc3"); // TALISMAN model corrected
			LAi_SetCitizenType(sld);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Soldier_Eng3_18", "rld", "loc11"); // TALISMAN model corrected
			LAi_SetCitizenType(sld);
		break;

		case "proposerabarbossa":
			DoQuestReloadToLocation("Grotto", "goto", "goto7", "equipebarbossa");
			ChangeCharacterAddressGroup(CharacterFromID("Barbossa"),"Grotto","goto","goto5");
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"),"Grotto","goto","goto4");
			Characters[GetCharacterIndex("Barbossa")].dialog.CurrentNode = "begin_5";
			LAi_ActorDialog(characterFromID("Barbossa"), pchar, "", 10.0, 10.0);
		break;

		case "equipebarbossa":
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel1", "goto", "goto9");
			sld.id = "crewmanbar1";
			LAi_SetImmortal(characterFromID("crewmanbar1"), true);
			LAi_SetActorType(CharacterFromID("crewmanbar1"));
			LAi_ActorFollow(CharacterFromID("crewmanbar1"),pchar,"",6.0);
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel2", "goto", "goto6");
			sld.id = "crewmanbar2";
			LAi_SetImmortal(characterFromID("crewmanbar2"), true);
			LAi_SetActorType(CharacterFromID("crewmanbar2"));
			LAi_ActorFollow(CharacterFromID("crewmanbar2"),pchar,"",6.0);
		break;

		case "combatbarbossa":
			DoQuestReloadToLocation("Grotto", "goto", "goto5", "equipebarbossa2");
		break;

		case "equipebarbossa2":
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel2", "goto", "goto6");
			sld.id = "crewmanbar4";
			LAi_SetImmortal(characterFromID("crewmanbar4"), true);
			LAi_group_MoveCharacter(sld, "CAVE_CREW");
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel3", "goto", "goto14");
			sld.id = "crewmanbar5";	
			LAi_SetImmortal(characterFromID("crewmanbar5"), true);
			LAi_group_MoveCharacter(sld, "CAVE_CREW");
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Skel4", "goto", "goto10");
			sld.id = "crewmanbar6";
			LAi_SetImmortal(characterFromID("crewmanbar6"), true);
			LAi_group_MoveCharacter(sld, "CAVE_CREW");
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"),"Grotto","goto","goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Barbossa"),"Grotto","goto","goto7");
			LAi_group_MoveCharacter(CharacterFromID("Barbossa"), "CAVE_CREW");
			Characters[GetCharacterIndex("Barbossa")].dialog.CurrentNode = "begin_11";
			LAi_ActorDialog(characterFromID("Barbossa"), pchar, "", 10.0, 10.0);
		break;

		case "combatbarbossa2":
			LAi_SetImmortal(Pchar, true);
			LAi_SetImmortal(characterFromID("Elizabeth Swann"), true);
			LAi_SetImmortal(characterFromID("Will Turner"), true);
			LAi_SetOfficerType(characterFromID("Will Turner"));
			ChangeCharacterAddressGroup(CharacterFromID("Elizabeth Swann"),"Grotto","reload","reload1_back");
			LAi_SetOfficerType(characterFromID("Elizabeth Swann"));
			LAi_group_FightGroups("CAVE_CREW", LAI_GROUP_PLAYER, true);
			LAi_QuestDelay("combatbarbossa3", 17.0);
		break;

		case "combatbarbossa3":
			LAi_SetImmortal(Pchar, false);
			LAi_SetImmortal(characterFromID("Barbossa"), false);
			LAi_SetHP(characterFromID("Barbossa"), 200.0, 200.0);
			LAi_SetImmortal(characterFromID("crewmanbar4"), false);
			LAi_SetHP(characterFromID("crewmanbar4"), 100.0, 100.0);
			LAi_SetImmortal(characterFromID("crewmanbar5"), false);
			LAi_SetHP(characterFromID("crewmanbar5"), 100.0, 100.0);
			LAi_SetImmortal(characterFromID("crewmanbar6"), false);
			LAi_SetHP(characterFromID("crewmanbar6"), 100.0, 100.0);
			LAi_group_SetCheck("CAVE_CREW", "justapresfight");
		break;

		case "justapresfight":
			LAi_SetActorType(characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "begin_23";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 30.0, 10.0);
		break;

		case "justapresfight2":
			Characters[GetCharacterIndex("James Norrington")].model = "Conorrington";
			ChangeCharacterAddressGroup(CharacterFromID("James Norrington"),"Grotto","goto","goto13");
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			Characters[GetCharacterIndex("Elizabeth Swann")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Elizabeth Swann"), pchar, "", 20.0, 10.0);
		break;

		case "justapresfight3":
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "begin_25";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 20.0, 10.0);
			SetNextWeather("Blue Sky");
		break;
//--> SJG
		case "arrestatGrotto":
			LAi_SetActorType(characterFromID("James Norrington"));
			Characters[GetCharacterIndex("James Norrington")].dialog.currentnode = "Grottoarrest";
			LAi_ActorDialog(characterFromID("James Norrington"), pchar, "allerfortredmond", 30.0, 10.0);
		break;
//<--SJG
		case "allerfortredmond":
			if(CheckQuestAttribute("Muerte", "noarmour"))
			{
				SetModelfromArray(&pchar, GetModelIndex("depp"));
			}

			if(CheckQuestAttribute("Muerte", "armourone"))
			{
				SetModelfromArray(&pchar, GetModelIndex("depp_A1"));
			}

			if(CheckQuestAttribute("Muerte", "armourtwo"))
			{
				SetModelfromArray(&pchar, GetModelIndex("depp_A2"));
			}

			if(CheckQuestAttribute("Muerte", "armourthree"))
			{
				SetModelfromArray(&pchar, GetModelIndex("depp_A3"));
			}

			Locations[FindLocation("Quest_Redmond_fort")].vcskip = true;
			DoQuestReloadToLocation("Quest_Redmond_fort", "rld", "aloc3", "_");
			Characters[GetCharacterIndex("James Norrington")].model = "Conorrington";
			ChangeCharacterAddressGroup(CharacterFromID("James Norrington"),"Quest_Redmond_fort", "rld", "loc1");
			ChangeCharacterAddressGroup(CharacterFromID("Weatherby Swann"),"Quest_Redmond_fort", "rld", "loc3");
			ChangeCharacterAddressGroup(CharacterFromID("Elizabeth Swann"),"Quest_Redmond_fort", "rld", "loc2");
			ChangeCharacterAddressGroup(CharacterFromID("Laurence Bannerman"),"Quest_Redmond_fort", "rld", "loc5");	
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"),"Quest_Redmond_fort", "rld", "loc4");
			ChangeCharacterAddressGroup(characterfromID("Red_soldier_1"), "Quest_Redmond_fort", "rld", "loc8");
			ChangeCharacterAddressGroup(characterfromID("Red_soldier_2"), "Quest_Redmond_fort", "rld", "loc7");
//			ChangeCharacterAddressGroup(characterfromID("Eng Soldier for residence 01"), "Quest_Redmond_fort", "rld", "loc6");
			ChangeCharacterAddressGroup(characterfromID("Eng_soldier_1"), "Quest_Redmond_fort", "rld", "loc11");
			ChangeCharacterAddressGroup(characterfromID("Eng_soldier_2"), "Quest_Redmond_fort", "rld", "loc12");
			ChangeCharacterAddressGroup(characterfromID("Eng_soldier_3"), "Quest_Redmond_fort", "rld", "loc13");

			LAi_SetActorType(characterFromID("James Norrington"));
			LAi_SetActorType(characterFromID("Weatherby Swann"));
			LAi_SetActorType(characterFromID("Laurence Bannerman"));
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_SetActorType(characterFromID("Red_soldier_1"));
			LAi_SetActorType(characterFromID("Red_soldier_2"));
//			LAi_SetActorType(characterFromID("Eng Soldier for residence 01"));
			LAi_SetActorType(characterFromID("Eng_soldier_1"));
			LAi_SetActorType(characterFromID("Eng_soldier_2"));
			LAi_SetActorType(characterFromID("Eng_soldier_3"));
			LAi_QuestDelay("Captured_and_sentence2", 2.0);
		break;

		case "Captured_and_sentence2":
// GR: "Eng Soldier for residence 01" does not seem to exist, or to be needed elsewhere, so use a fantom for him
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "rld", "loc6");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquipCharacterByItem(sld, "bladeC6");
			sld.nation = ENGLAND;
			SetRandomNameToCharacter(sld);
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			sld.id = "Eng Soldier for residence 01";
			LAi_SetActorType(characterFromID("Eng Soldier for residence 01"));

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(characterFromID("James Norrington"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("Weatherby Swann"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("Red_soldier_1"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("Red_soldier_2"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("Eng Soldier for residence 01"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("Eng_soldier_1"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("Eng_soldier_2"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("Eng_soldier_3"), PChar);
			LAi_ActorTurnToCharacter(characterFromID("Will Turner"), characterFromID("Elizabeth Swann"));
			LAi_ActorTurnToCharacter(characterFromID("Laurence Bannerman"), PChar);	
			LAi_ActorTurnToCharacter(pchar, characterFromID("Laurence Bannerman"));	
			LAi_QuestDelay("Captured_and_sentence3", 2.0);
		break;

		case "Captured_and_sentence3":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "fort_speech";
			LAi_ActorSelfDialog(Pchar, "player_back");
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			PlaySound("OBJECTS\SHIPCHARGE\_musketshot.wav");
		break;

		case "prepare_execution_escape":
			PlayStereoSound("OBJECTS\SHIPCHARGE\_726SNARE16.wav");
			pchar.quest.Turner = "rescue_Jack";
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorRunToLocator(characterFromID("Will Turner"), "rld", "loc9", "prepare_execution_escape2", -1);
		break;

		case "prepare_execution_escape2":
			LAi_ActorTurnToCharacter(characterFromID("Will Turner"), characterFromID("Laurence Bannerman"));
			LAi_QuestDelay("prepare_execution_escape3", 2.0);
		break;

		case "prepare_execution_escape3":
			Characters[GetCharacterIndex("Will Turner")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterFromID("Will Turner"), Pchar, "", 2.0, 0);
		break;

		case "Turner_and_me_in_trouble":
			LAi_ActorRunToLocator(characterFromID("Laurence Bannerman"), "rld", "loc0", "", -1);
			LAi_ActorGoToLocator(characterFromID("Elizabeth Swann"), "rld", "loc4", "Turner_and_me_in_trouble2", -1);
		break;

		case "Turner_and_me_in_trouble2":
			LAi_ActorTurnToCharacter(characterFromID("Will Turner"), characterFromID("James Norrington"));
			ChangeCharacterAddress(characterFromID("Laurence Bannerman"), "None", "");
			LAi_QuestDelay("Turner_and_me_in_trouble3", 2.0);
		break;

		case "Turner_and_me_in_trouble3":
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "In_the_fort";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "Turner_and_me_in_trouble4", 2.0, 0);
		break;

		case "Turner_and_me_in_trouble4":
			Characters[GetCharacterIndex("Weatherby Swann")].Dialog.CurrentNode = "the_prison_scene";
			LAi_ActorDialog(characterFromID("Weatherby Swann"), Pchar, "", 2.0, 0);
		break;

		case "Norrington_once_more":
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "the_prison_scene";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "", 2.0, 0);
		break;

		case "Governor_to_Elizabeth":
			LAi_ActorTurnToCharacter(characterFromID("Will Turner"), characterFromID("Elizabeth Swann"));
			Characters[GetCharacterIndex("Elizabeth Swann")].Dialog.CurrentNode = "In_the_prison";
			LAi_ActorDialog(characterFromID("Elizabeth Swann"), Pchar, "", 2.0, 0);
		break;

		case "ReturntoGovernoragain":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(characterFromID("Weatherby Swann"), characterFromID("Elizabeth Swann"));
			LAi_ActorRunToLocator(characterFromID("Will Turner"), "rld", "loc10", "", -1);
			LAi_ActorRunToLocator(characterFromID("Elizabeth Swann"), "reload", "reloadc2", "Governor_follows_Elizabeth", -1);
			LAi_ActorGoToLocator(Pchar, "rld", "loc4", "", -1);	
		break;

		case "Governor_follows_Elizabeth":
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddress(characterFromID("Will Turner"), "None", "");
			ChangeCharacterAddress(characterFromID("Elizabeth Swann"), "None", "");
			Characters[GetCharacterIndex("Weatherby Swann")].Dialog.CurrentNode = "Following_Elizabeth";
			LAi_ActorDialog(characterFromID("Weatherby Swann"), Pchar, "", 5.0, 0);	
		break;

		case "The_final_escape":
			LAi_ActorRunToLocator(characterFromID("Weatherby Swann"), "reload", "reloadc2", "", -1);
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "the_prison_fight_scene";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "", 2.0, 0);
		break;

		case "Over_the_wall":
			LAi_ActorAnimation(pchar, "attack_fast_2", "", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
			LAi_QuestDelay("Over_the_wall2", 1.0);
		break;

		case "Over_the_wall2":
			GiveItem2Character(Pchar, "blade4");
			EquipCharacterByItem(Pchar, "blade4");
			LAi_ActorAttack(characterfromID("Red_soldier_1"), pchar, "");
			LAi_ActorAttack(characterfromID("Red_soldier_2"), pchar, "");
			LAi_ActorAttack(characterfromID("Eng Soldier for residence 01"), pchar, "");
			LAi_ActorAttack(characterfromID("Eng_soldier_1"), pchar, "");
			LAi_ActorAttack(characterfromID("Eng_soldier_2"), pchar, "");
			LAi_ActorAttack(characterfromID("Eng_soldier_3"), pchar, "");
			// PB: Weatherby Swann returns for ordinary governor duties -->
			ChangeCharacterAddressGroup(characterFromID("Weatherby Swann"), "redmond_residence", "goto", "goto8");
			LAi_SetHuberStayType(characterFromID("Weatherby Swann"));
			Characters[GetCharacterIndex("Weatherby Swann")].Dialog.FileName = "John Clifford Brin_dialog.c";
			Characters[GetCharacterIndex("Weatherby Swann")].Dialog.CurrentNode = "First time";
			// PB: Weatherby Swann returns for ordinary governor duties <--
			LAi_ActorRunToLocator(Pchar, "rld", "aloc0", "up_the_steps", -1);
		break;

		case "up_the_steps":
			LAi_ActorRunToLocator(Pchar, "reload", "reload1", "up_the_steps2", 10.0);
		break;

		case "up_the_steps2":
			LAi_ActorRunToLocator(Pchar, "reload", "reload2", "up_the_steps3", 10.0);
		break;

		case "up_the_steps3":
			ChangeCharacterAddressGroup(characterFromID("James Norrington"), "Quest_Redmond_fort","rld", "loc14");
			LAi_ActorTurnToCharacter(characterFromID("James Norrington"), Pchar);
			LAi_SetStayType(characterFromID("James Norrington"));
			LAi_SetActorType(characterFromID("James Norrington"));
			LAi_ActorTurnToCharacter(pchar, characterFromID("James Norrington"));
			LAi_QuestDelay("up_the_steps4", 1.0);
		break;

		case "up_the_steps4":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("James Norrington")].Dialog.CurrentNode = "Goodbye_Commodore";
			LAi_ActorDialog(characterFromID("James Norrington"), Pchar, "and_over_the_wall", 10.0, 1.0);
		break;

		case "and_over_the_wall":
			LAi_SetActorType(Pchar);
			LAi_ActorRunToLocator(Pchar, "reload", "reload2", "houplaboom", 5.0);
			LAi_Fade("", "");
		break;

		case "houplaboom":
			LAi_type_actor_Reset(characterFromID("Mr. Gibbs"));
			LAi_SetPlayerType(pchar); // <--SJG
			// KK -->
			if (PreprocessText("#scursed_ship#") == "Black Pearl")
				GiveShip2Character(pchar,"BlackPearl",  TranslateString(PreprocessText("#scursed_ship#"), ""),-1,PIRATE,TRUE,TRUE);
			else
			{
				GiveShip2Character(pchar,"CrimsonBlood",TranslateString(PreprocessText("#scursed_ship#"), ""),-1,PIRATE,TRUE,TRUE);
				pchar.EmblemedSails.normalTex = "Ships\Sails\sail_Petros_black_red.tga"; // PB
				pchar.EmblemedSails.nationFileName = "Ships\Sails\sail_Petros_black_red.tga"; // PB
			}
			// <-- KK
			setCharacterShipLocation(pchar, "Redmond_shore_02"); 
			DoReloadCharacterToLocation("Redmond_shore_02", "Jack", "fall");
			//ChangeCharacterAddressGroup(CharacterFromID("Mr. Gibbs"),"Redmond_shore_02","officers","reload1_3");
			//LAi_QuestDelay("GotBlackPearlBackAgain", 1.0); 
			LAi_QuestDelay("findecotbp", 2.0);
		break;

		case "GotBlackPearlBackAgain":
			LAi_SetActorType(characterFromID("Mr. Gibbs"));
			Characters[GetCharacterIndex("Mr. Gibbs")].Dialog.Filename = "Mr. Gibbs_Dialog.c";
			Characters[GetCharacterIndex("Mr. Gibbs")].dialog.currentnode = "begin_13";
			LAi_ActorDialog(characterFromID("Mr. Gibbs"), pchar, "", 20.0, 10.0);
		break;

		case "findecotbp":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 25000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 25000); }

			bSuppressResurrection = false;
			//AddQuestRecord("IslaDeMuerteI", "3");
			//CloseQuestHeader("IslaDeMuerteI");
			ChangeCharacterAddress(characterFromID("Barbossa"), "none", "");
			ChangeCharacterAddress(characterFromID("Elizabeth Swann"), "none", "");
 			SetOfficersIndex(Pchar, 2, GetCharacterIndex("Annamaria"));	// GR: Anamaria appears on the Black Pearl in the "jack_exit_DMC" video, so make her an officer too
			LAi_SetOfficerType(CharacterFromID("Annamaria"));
			LAi_SetImmortal(CharacterFromID("Annamaria"), false);
 			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Mr. Gibbs"));
			LAi_SetOfficerType(CharacterFromID("Mr. Gibbs"));
			LAi_SetImmortal(CharacterFromID("Mr. Gibbs"), false);
			//setCharacterShipLocation(pchar, "Redmond_shore_02");

			ChangeCharacterAddressGroup(CharacterFromID("Laurence Bannerman"),"Grand_Cayman_store", "sit", "sit1");
			LAi_SetStayType(characterFromID("Laurence Bannerman"));

			//--> CTM
			if(GetAttribute(pchar, "Lucas") != "0")
			{
				//AddQuestRecord("IslaDeMuerteI", "3");
				//CloseQuestHeader("IslaDeMuerteI");
				AddQuestRecord("Curse Of", 5);
				CloseQuestHeader("Curse Of");

				LAi_QuestDelay("Sail_DMC_Jack", 0.0);
			}
			else
			{
				//AddQuestRecord("IslaDeMuerteI", "4");
				//CloseQuestHeader("IslaDeMuerteI");
				AddQuestRecord("Curse Of", 6);
				CloseQuestHeader("Curse Of");

				LAi_QuestDelay("Sail_free_Jack", 0.0);
			}
			//<-- CTM

			PChar.quest.cotbp_done = true;
			if(CheckQuestAttribute("animists", "completed")) CloseQuestHeader("Stolen");	// If "Animists" quest not complete, "Ship Stolen" questbook may be needed if Jaoquin de Masse steals your ship later
		break;
// Bartolomeu o Portugues COTBP Finishes Here
		case "Sail_DMC_Jack":
			//StorePassengers("Blaze");
			ResetSound();
			PostVideoAndQuest("LegendJackSparrow\jack_exit_DMC", 1, "DMC_prestart");
			bMainMenuLaunchAfterVideo = true;
		break;

		case "Sail_Free_Jack":
			ResetSound();
			//StorePassengers("Blaze");
			//PostVideoAndQuest("LegendJackSparrow\jack_exit", 1, "whatever_now");
			PostVideoAndQuest("COMMON\ENGLISH\credits", 1, "whatever_now");
			bMainMenuLaunchAfterVideo = true;
		break;

		case "whatever_now":
			//pchar.jack = "finished";
			PostEvent("DoInfoShower",100,"s","");

			QuestToSeaLogin_PrepareLoc("Redmond", "reload", "reload_3", false);
			QuestToSeaLogin_Launch();

			ResumeAllSounds();
		break;

// Captain Maggee's DMC Starts Here - Explaining Davy <--
		case "DMC_prestart":
			QuestToSeaLogin_PrepareLoc("Redmond", "reload", "reload_3", false);
			QuestToSeaLogin_Launch();
			PostEvent("DoInfoShower",100,"s","");

			ChangeCharacterAddressGroup(CharacterFromID("Thomas Tipman"), "Tortuga_Tavern", "goto", "goto9");
			Characters[GetCharacterIndex("Thomas Tipman")].dialog.currentnode = "Tortuga help";

			pchar.quest.DMC_Start.win_condition.l1 = "location";
			pchar.quest.DMC_Start.win_condition.l1.location = "Santo_Domingo_townhall";
			pchar.quest.DMC_Start.win_condition = "DMC_Start";

			ResumeAllSounds();
		break;

		case "DMC_Start":
			ChangeCharacterAddressGroup(CharacterFromID("Joaquin Da Saldanha"), "Santo_Domingo_townhall", "goto", "goto1");
			PChar.quest.lucas = "";
		break;

		case "Luc_start":
			SetEnterLocationQuest("Santo_Domingo_townhall", "Luc_start_check", 0);
		break;

		case "Luc_start_check":
			if(makeint(PChar.rank) >= 4)
			{
				ChangeCharacterAddressGroup(CharacterFromID("Joaquin Da Saldanha"), "Santo_Domingo_townhall", "goto", "goto1");
			}
		break;

		case "Lucas_search_refused":
			PChar.quest.Lucas = "refused";

			DeleteEnterLocationQuest("Santo_Domingo_townhall", "Luc_start_check");
		break;

		case "Lucas_search_start":
			PChar.quest.Lucas = "search";
			PChar.Lucas = "0";

			DeleteEnterLocationQuest("Santo_Domingo_townhall", "Luc_start_check");

			//JOURNAL
			SetQuestHeader("Lucas");
			AddQuestRecord("Lucas", 1);
		break;

		case "Lucas_search1":
			PChar.quest.Lucas = "search1";

			//ChangeCharacterAddressGroup(CharacterFromID("Arabella Silehard"), "Cayman_jungle_02", "goto", "citizen02");
			//ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 1"), "Cayman_jungle_02", "goto", "locator8");
			//ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 2"), "Cayman_jungle_02", "goto", "citizen03");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella Silehard"), "Falaise_de_fleur_jungle", "goto", "citizen01");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 1"), "Falaise_de_fleur_jungle", "goto", "locator10");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 2"), "Falaise_de_fleur_jungle", "goto", "locator10");

			//JOURNAL
			AddQuestRecord("Lucas", 2);

			pchar.quest.Lucas_search_Arab.win_condition.l1 = "location";
			pchar.quest.Lucas_search_Arab.win_condition.l1.location = "Falaise_de_fleur_jungle";
			pchar.quest.Lucas_search_Arab.win_condition = "Lucas_search_Arab";
		break;

		case "Lucas_search_Arab":
			LAi_SetActorType(CharacterFromID("Arabella Silehard"));
			LAi_SetWarriorType(CharacterFromID("Arabella's guard 1"));
			LAi_SetWarriorType(CharacterFromID("Arabella's guard 2"));
			LAi_warrior_DialogEnable(CharacterFromID("Arabella's guard 1"), true)
			LAi_warrior_DialogEnable(CharacterFromID("Arabella's guard 2"), true)
			LAi_warrior_SetCommander(characterFromID("Arabella's guard 1"), characterFromID("Arabella Silehard"));
			LAi_warrior_SetCommander(characterFromID("Arabella's guard 2"), characterFromID("Arabella Silehard"));
			LAi_group_MoveCharacter(CharacterFromID("Arabella Silehard"), "ARABELLA");
			LAi_group_MoveCharacter(CharacterFromID("Arabella's guard 1"), "ARABELLA");
			LAi_group_MoveCharacter(CharacterFromID("Arabella's guard 2"), "ARABELLA");
			LAi_SetImmortal(CharacterFromID("Arabella Silehard"), true);
			LAi_SetImmortal(CharacterFromID("Arabella's guard 1"), true);
			LAi_SetImmortal(CharacterFromID("Arabella's guard 2"), true);
			LAi_group_SetRelation("ARABELLA", "ARABELLA", LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("ARABELLA", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL, LAI_GROUP_NEUTRAL);
			LAi_ActorGoToLocator(characterFromID("Arabella Silehard"), "goto", "locator9", "Lucas_search1.5", 100.0);
		break;

		case "Lucas_search1.5":
			LAi_SetActorType(CharacterFromID("Arabella Silehard"));
			LAi_ActorWaitDialog(characterFromID("Arabella Silehard"), PChar);
		break;

		case "Lucas_search2":
			PChar.quest.Lucas = "search2";

			LAi_SetActorType(CharacterFromID("Arabella Silehard"));
			LAi_ActorGoToLocation(characterFromID("Arabella Silehard"), "reload", "reload2", "none", "", "", "Lucas_search2.5", 100.0);

			//JOURNAL
			AddQuestRecord("Lucas", 3);
		break;

		case "Lucas_search2.5":
			LAi_SetActorType(CharacterFromID("Arabella's guard 1"));
			LAi_SetActorType(CharacterFromID("Arabella's guard 2"));
			LAi_ActorGoToLocation(characterFromID("Arabella's guard 1"), "reload", "reload2", "none", "", "", "", 0.0);
			LAi_ActorGoToLocation(characterFromID("Arabella's guard 2"), "reload", "reload2", "none", "", "", "", 0.0);
		break;

		case "Lucas_ransom_refused":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_ransom_refused");
			bDisableFastReload = 1;

			LAi_SetActorType(CharacterFromID("Joaquin Da Saldanha"));
			LAi_CharacterDisableDialog(CharacterFromID("Joaquin Da Saldanha"));
			LAi_ActorGoToLocation(CharacterFromID("Joaquin Da Saldanha"), "reload", "reload1", "none", "", "", "Lucas_ransom_refused1", 3.0);

			//JOURNAL
			AddQuestRecord("Lucas", 4);
			CloseQuestHeader("Lucas");
		break;

		case "Lucas_ransom_refused1":
			EndQuestMovie();TrackQuestMovie("end","Lucas_ransom_refused1");
			bDisableFastReload = 0;
		break;

		case "Lucas_ransom_start":
			PChar.quest.Lucas = "ransom";

			AddMoneyToCharacter(PChar, 20000);

			ChangeCharacterAddressGroup(CharacterFromID("John Smith"), "Smugglers_tavern", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("Snorri Baldursson"), "Smugglers_tavern", "goto", "goto7");
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "Rheims_house_in_smugglers", "goto", "goto5");
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Rheims_house_in_smugglers", "sit", "sit2");
			LAi_SetSitType(CharacterFromID("Lucas Da Saldanha"));
			Locations[FindLocation("Smugglers_Lair")].reload.l5.close_for_night = 0;
			Locations[FindLocation("Rheims_house_in_smugglers")].id.label = "Kidnappers' Hideout";
			Locations[FindLocation("Smugglers_Tavern")].vcskip = true; // NK

			PChar.quest.Lucas_ransom_deadline.win_condition.l1 = "Timer";
			PChar.quest.Lucas_ransom_deadline.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.Lucas_ransom_deadline.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.Lucas_ransom_deadline.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.Lucas_ransom_deadline.win_condition = "Lucas_ransom_deadline";

			PChar.quest.Lucas_ransom_delivery.win_condition.l1 = "location";
			PChar.quest.Lucas_ransom_delivery.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_ransom_delivery.win_condition.l1.location = "Smugglers_tavern";
			PChar.quest.Lucas_ransom_delivery.win_condition = "Lucas_ransom_delivery";

			//JOURNAL
			AddQuestRecord("Lucas", 5);
		break;

		case "Lucas_ransom_deadline":
			PChar.quest.Lucas_ransom_delivery.over = "yes";

			DisableFastTravel(false);
			DisableMenuLaunch(false);
			// unneeded if(GetRMRelation(PChar, SPAIN) > REL_AFTERATTACK) SetRMRelation(PChar, SPAIN, REL_AFTERATTACK); // RM - SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY);
			LeaveService(PChar, SPAIN, false); // RM

			ChangeCharacterAddressGroup(CharacterFromID("Joaquin Da Saldanha"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella Silehard"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("John Smith"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Snorri Baldursson"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "none", "", "");

			//JOURNAL
			AddQuestRecord("Lucas", 14);
			CloseQuestHeader("Lucas");
		break;

		case "Lucas_ransom_delivery":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_ransom_delivery");
			bDisableFastReload = 1;

			LAi_SetActorType(CharacterFromID("John Smith"));
			LAi_SetActorType(CharacterFromID("Snorri Baldursson"));

			LAi_ActorTurnToCharacter(CharacterFromID("John Smith"), CharacterFromID("Snorri Baldursson"));
			LAi_ActorTurnToCharacter(CharacterFromID("Snorri Baldursson"), CharacterFromID("John Smith"));

			LAi_SetActorType(PChar);
			Pchar.dialog.CurrentNode = "Lucas";
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Lucas_ransom_delivery1":
		//dialog exit from self
			LAi_ActorGoToLocator(PChar, "goto", "goto6", "Lucas_ransom_delivery2", 10.0);
		break;

		case "Lucas_ransom_delivery2":
			Pchar.dialog.CurrentNode = "Eavesdrop1";
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Fabiao Dunga"));
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Lucas_sign":
			LAi_ActorGoToLocator(PChar, "goto", "goto5", "Lucas_sign1", 10.0);
		break;

		case "Lucas_sign1":
		//dialog exit from Self
			PChar.quest.Lucas = "sign";
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("John Smith"));
			LAi_ActorTurnToCharacter(CharacterFromID("John Smith"), PChar);
			LAi_ActorDialog(CharacterFromID("John Smith"), PChar, "player_back", 4.0, -1);
		break;

		case "Lucas_sign2":
		//dialog exit from Brock
			LAi_ActorGoToLocation(CharacterFromID("John Smith"), "reload", "reload1", "Smugglers_Lair", "goto", "goto18", "Lucas_sign3", 5.0);
		break;

		case "Lucas_sign3":
			EndQuestMovie();TrackQuestMovie("end","Lucas_sign3");
			PChar.quest.Lucas_sign4.win_condition.l1 = "location";
			PChar.quest.Lucas_sign4.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_sign4.win_condition.l1.location = "Smugglers_Lair";
			PChar.quest.Lucas_sign4.win_condition = "Lucas_sign4";
		break;

		case "Lucas_sign4":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_sign4");
			LAi_ActorGoToLocation(CharacterFromID("John Smith"), "reload", "reload10", "Rheims_house_in_smugglers", "goto", "goto3", "Lucas_sign5", 10.0);
			LAi_SetActorType(characterFromID("Macario Regalo"));
			LAi_SetActorType(characterFromID("Evaristo Filho"));
			LAi_ActorGoToLocation(CharacterFromID("Macario Regalo"), "reload", "reload1", "none", "", "", "", 100.0);
			LAi_ActorGoToLocation(CharacterFromID("Evaristo Filho"), "reload", "reload1", "none", "", "", "", 100.0);
		break;

		case "Lucas_sign5":
			EndQuestMovie();TrackQuestMovie("end","Lucas_sign5");
			Locations[FindLocation("Smugglers_Lair")].reload.l5.disable = "0";
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "Rheims_house_in_smugglers", "sit", "sit1");
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Rheims_house_in_smugglers", "sit", "sit2");
			LAi_SetSitType(CharacterFromID("Francis Snake"));
			LAi_SetSitType(CharacterFromID("Lucas Da Saldanha"));
			bDisableFastReload = 0;
			PChar.quest.Lucas_sign6.win_condition.l1 = "location";
			PChar.quest.Lucas_sign6.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_sign6.win_condition.l1.location = "Rheims_house_in_smugglers";
			PChar.quest.Lucas_sign6.win_condition = "Lucas_sign6";
			Locations[FindLocation("Rheims_house_in_smugglers")].vcskip = true; // NK
		break;

		case "Lucas_sign6":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_sign6");
			bDisableFastReload = 1;
			LAi_LocationFightDisable(&Locations[FindLocation("Rheims_house_in_smugglers")], 1);
			PChar.quest.Lucas = "sign1";
			LAi_ActorDialog(CharacterFromID("John Smith"), PChar, "", 4.0, -1);
		break;

		case "Lucas_sign7":
		//dialog exit from Brock
			PChar.quest.Lucas = "sign2";
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "goto4", "", 10.0);
			LAi_ActorGoToLocator(CharacterFromID("John Smith"), "goto", "goto1", "Lucas_sign8", 10.0);
		break;

		case "Lucas_sign8":
			LAi_QuestDelay("Lucas_sign9", 3.0);
			LAi_ActorTurnToCharacter(CharacterFromID("John Smith"), CharacterFromID("Francis Snake"));
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("John Smith"));
		break;

		case "Lucas_sign9":
			DeleteAttribute(&Locations[FindLocation("Smugglers_Tavern")],"vcskip"); // NK
			LAi_fade("Lucas_sign10", "Lucas_sign11");
		break;

		case "Lucas_sign10":
			LAi_SetActorType(CharacterFromID("Lucas Da Saldanha"));
			LAi_SetActorType(CharacterFromID("Francis Snake"));

			//ChangeCharacterAddressGroup(PChar, "Rheims_house_in_smugglers", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "Rheims_house_in_smugglers", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Rheims_house_in_smugglers", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("John Smith"), "Rheims_house_in_smugglers", "goto", "goto5");
		break;

		case "Lucas_sign11":
			LAi_ActorTurnToCharacter(CharacterFromID("Lucas Da Saldanha"), PChar);
			LAi_ActorTurnToCharacter(CharacterFromID("Francis Snake"), PChar);
			LAi_ActorTurnToCharacter(CharacterFromID("John Smith"), PChar);
			LAi_QuestDelay("Lucas_sign12", 0.0);
		break;

		case "Lucas_sign12":
			EndQuestMovie();TrackQuestMovie("end","Lucas_sign12");

			LAi_ActorDialog(CharacterFromID("John Smith"), PChar, "player_back", 100.0, 100.0);
			DeleteAttribute(&Locations[FindLocation("Rheims_house_in_smugglers")],"vcskip"); // NK
		break;

		case "Lucas_kill":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_kill");

			LAi_LocationFightDisable(&Locations[FindLocation("Rheims_house_in_smugglers")], 0);

			LAi_KillCharacter(CharacterFromID("Lucas Da Saldanha"));

			LAi_SetWarriorType(CharacterFromID("John Smith"));
			LAi_SetWarriorType(CharacterFromID("Francis Snake"));

			LAi_group_MoveCharacter(CharacterFromID("John Smith"), "kidnappers");
			LAi_group_MoveCharacter(CharacterFromID("Francis Snake"), "kidnappers");

			LAi_group_FightGroups("kidnappers", LAI_GROUP_PLAYER, 1);

			LAi_group_SetCheck("kidnappers", "Lucas_killed");
		break;

		case "Lucas_killed":
			EndQuestMovie();TrackQuestMovie("end","Lucas_killed");

			DisableFastTravel(true);
			DisableMenuLaunch(true);

			DoQuestCheckDelay("Lucas_ransom_deadline", 3.0);
		break;

		case "Lucas_sign13":
		//dialog exit from Brock
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_sign13");

			AddMoneyToCharacter(PChar, -20000);
			LAi_type_actor_Reset(CharacterFromID("John Smith"));
			LAi_type_actor_Reset(CharacterFromID("Francis Snake"));
			LAi_ActorGoToLocation(CharacterFromID("John Smith"), "reload", "reload1", "none", "", "", "", 10.0);
			LAi_ActorGoToLocation(CharacterFromID("Francis Snake"), "reload", "reload1", "none", "", "", "Lucas_talk1", 10.0);
			ChangeCharacterAddressGroup(CharacterFromID("Snorri Baldursson"), "none", "", "");
		break;

		case "Lucas_talk1":
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "free";
			LAi_type_actor_Reset(CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 3.0, -1);
		break;

		case "Lucas_talk1_1":
		//dialog exit from Lucas
			EndQuestMovie();TrackQuestMovie("end","Lucas_talk1_1");

			PChar.quest.Lucas = "return";

			GiveItem2Character(CharacterFromId("Lucas Da Saldanha"), "blade16");
			GiveItem2Character(CharacterFromId("Lucas Da Saldanha"),"pistol3");
			EquipCharacterByItem(CharacterFromId("Lucas Da Saldanha"), "blade16");
			EquipCharacterByItem(CharacterFromId("Lucas Da Saldanha"), "pistol3");

		     //JRH ammo mod -->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromId("Lucas Da Saldanha"), "gunpowder", 6);
				TakenItems(CharacterFromId("Lucas Da Saldanha"), "pistolgrapes", 6);
			}
		     //JRH ammo mod <--

			LAi_SetImmortal(CharacterFromID("Lucas Da Saldanha"), 1);

			//LAi_ActorFollowEverywhere(CharacterFromID("Lucas Da Saldanha"), "", 0.0);

			PChar.quest.Lucas_talk2.win_condition.l1 = "location";
			PChar.quest.Lucas_talk2.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_talk2.win_condition.l1.location = "Smugglers_Lair";
			PChar.quest.Lucas_talk2.win_condition = "Lucas_talk2";

			//JOURNAL
			AddQuestRecord("Lucas", 7);
		break;

		case "Lucas_talk2":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_talk2");

			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Smugglers_lair", "goto", "goto19");

			LAi_LocationFightDisable(&Locations[FindLocation("Rheims_house_in_smugglers")], 0);
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "free1";

			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 2.0, -1);
		break;

		case "Lucas_talk2_1":
			EndQuestMovie();TrackQuestMovie("end","Lucas_talk2_1");
			InterfaceStates.Buttons.Save.enable = 1;
			bDisableFastReload = 0;

			LAi_ActorFollowEverywhere(CharacterFromID("Lucas Da Saldanha"), "", 0.0);

			PChar.quest.Lucas_return.win_condition.l1 = "location";
			PChar.quest.Lucas_return.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_return.win_condition.l1.location = "Santo_Domingo_townhall";
			PChar.quest.Lucas_return.win_condition = "Lucas_return";

			PChar.quest.Lucas_ransom_deadline.over = "yes";
		break;

		case "Lucas_return":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_return");

			LAi_Type_Actor_Reset(CharacterFromID("Lucas Da Saldanha"));

			LAi_SetActorType(characterFromID("Joaquin Da Saldanha"));

			LAi_SetActorType(PChar);

			LAi_ActorGoToLocator(PChar, "goto", "goto8", "", 10.0);

			LAi_ActorGoToLocator(CharacterFromID("Lucas Da Saldanha"), "goto", "goto7", "Lucas_return_1", 10.0);

			LAi_SetImmortal(CharacterFromID("Lucas Da Saldanha"), 0);
		break;

		case "Lucas_return_1":
			LAi_ActorTurnToCharacter(CharacterFromID("Joaquin Da Saldanha"), CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorTurnToCharacter(CharacterFromID("Lucas Da Saldanha"), CharacterFromID("Joaquin Da Saldanha"));
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Joaquin Da Saldanha"));

			LAi_QuestDelay("Lucas_return1", 3.0);
		break;

		case "Lucas_return1":
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Joaquin Da Saldanha"));
			LAi_ActorTurnToCharacter(CharacterFromID("Lucas Da Saldanha"), PChar);

			LAi_QuestDelay("Lucas_return1_1", 1.0);
		break;

		case "Lucas_return1_1":
		//dialog exit from self
			LAi_SetPlayerType(PChar);

			LAi_ActorDialog(CharacterFromID("Joaquin Da Saldanha"), PChar, "", 10.0, 10.0);
		break;

		case "Lucas_end":

		//dialog exit from Joaquin
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			ChangeCharacterReputation(pchar, 20);

			if(GetRMRelation(PChar, SPAIN) < REL_AMNESTY) SetRMRelation(PChar, SPAIN, REL_AMNESTY); // RM

			AddMoneyToCharacter(PChar, +10000);

			LAi_CharacterDisableDialog(CharacterFromID("Joaquin Da Saldanha"));
			LAi_Type_Actor_Reset(CharacterFromID("Joaquin Da Saldanha"));
			LAi_ActorGoToLocation(CharacterFromID("Joaquin Da Saldanha"), "reload", "reload1", "none", "", "", "", 10.0);

			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "join";
			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 10.0, 10.0);

			//JOURNAL
			AddQuestRecord("Lucas", 9);
			//CloseQuestHeader("Lucas");
		break;

		case "Lucas_join":
		//dialog exit from Lucas

			EndQuestMovie();TrackQuestMovie("end","Lucas_join");

			LAi_Type_Actor_Reset(CharacterFromID("Lucas Da Saldanha"));
			SetOfficersIndex(PChar, 3, GetCharacterIndex("Lucas Da Saldanha")); // NK was -1

			//--> CTM
			PChar.quest.Lucas_Concern.win_condition.l1 = "Timer";
			PChar.quest.Lucas_Concern.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);
			PChar.quest.Lucas_Concern.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Lucas_Concern.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);
/*			PChar.quest.Lucas_Concern.win_condition.l2 = "Location";
			PChar.quest.Lucas_Concern.win_condition.l2.character = "Lucas Da Saldanha";
			PChar.quest.Lucas_Concern.win_condition.l2.location = PChar.location;*/
			PChar.quest.Lucas_Concern.win_condition = "Lucas_Concern";
		break;
			//<-- CTM
		case "Lucas_no_join":
		//dialog exit from Lucas
			LAi_ActorGoToLocator(CharacterFromID("Lucas Da Saldanha"), "goto", "goto2", "Lucas_no_join1", 10.0);
		break;

		case "Lucas_no_join1":
			EndQuestMovie();TrackQuestMovie("end","Lucas_no_join1");

			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Santo_Domingo_townhall", "goto", "goto2");

			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "join_loop";

			LAi_SetStayType(CharacterFromID("Lucas Da Saldanha"));

			//CloseQuestHeader("Lucas");
		break;

		//--> CTM
		case "Lucas_Concern":
			PChar.quest.Lucas_Concern2_tortuga.win_condition.l1 = "location"; // Check for arrival at Tortuga
			PChar.quest.Lucas_Concern2_tortuga.win_condition.l1.location = "Tortuga_port";
			PChar.quest.Lucas_Concern2_tortuga.win_condition = "Lucas_Concern2";

			PChar.quest.Lucas_Concern2_nevis.win_condition.l1 = "location"; // Check for arrival at Nevis Pirate
			PChar.quest.Lucas_Concern2_nevis.win_condition.l1.location = "QC_port";
			PChar.quest.Lucas_Concern2_nevis.win_condition = "Lucas_Concern2";

			PChar.quest.Lucas_Concern2_turks.win_condition.l1 = "location"; // Check for arrival at Turks Island
			PChar.quest.Lucas_Concern2_turks.win_condition.l1.location = "Turks_port";
			PChar.quest.Lucas_Concern2_turks.win_condition = "Lucas_Concern2";

			Locations[FindLocation("Tortuga_port")].vcskip = true;

		break;

		case "Lucas_Concern2":
			PChar.quest.Lucas_Concern2_tortuga.over = "yes";	// Cancel all location checks so you don't trigger this again by visiting another target
			PChar.quest.Lucas_Concern2_nevis.over = "yes";
			PChar.quest.Lucas_Concern2_turks.over = "yes";
			DeleteAttribute(&Locations[FindLocation("Tortuga_port")],"vcskip");

			if(FindFellowTravellers(PChar, CharacterFromId("Lucas Da Saldanha")) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, CharacterFromId("Lucas Da Saldanha")) == FELLOWTRAVEL_PASSENGER)
			{
				StartQuestMovie(true, true, false);
				DisableFastTravel(true);
				if (!isofficer(CharacterFromID("Lucas Da Saldanha"))) PlaceCharacter(characterFromID("Lucas Da Saldanha"), "goto");
				Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "concern";
				LAi_SetActorType(CharacterFromID("Lucas Da Saldanha"));
				LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 2.0, -1);
				pchar.Luc_Time = "months";
			//JOURNAL
			//AddQuestRecord("Lucas", 15);
			}
		break;

		case "meet_Maggee":
			if(IsOfficer(characterFromID("Lucas Da Saldanha")))
			{
				ChangeCharacterAddressGroup(CharacterFromID("Captain Maggee"), "Falaise_de_Fleur_port_01", "goto", "goto13");
				Characters[GetCharacterIndex("Captain Maggee")].dialog.CurrentNode = "story";
				LAi_SetActorType(CharacterFromID("Captain Maggee"));
				LAi_ActorDialog(CharacterFromID("Captain Maggee"), PChar, "", 100.0, 100.0);
			}
		break;

		case "after_Maggee":
			LAi_ActorGoToLocation(CharacterFromID("Captain Maggee"), "reload", "falaise_de_fleur_location_01_02", "none","","","", 100.0);

			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "governer";
			LAi_SetActorType(CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 2.0, -1);

			//JOURNAL
			AddQuestRecord("Lucas", 17);
		break;

		case "reset_Lucas":
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_Type_Actor_Reset(CharacterFromID("Lucas Da Saldanha"));
			SetOfficersIndex(PChar, 3, GetCharacterIndex("Lucas Da Saldanha"));
		break;

		case "Contact_start":
			SetEnterLocationQuest("Falaise_de_Fleur_townhall", "Contact_start_check", 0);
		break;

		case "Contact_start_check":
			if((makeint(PChar.rank) >= 6)&&(IsOfficer(CharacterFromID("Lucas Da Saldanha"))))
			{
				PChar.quest.Firstcontact = "debut";
				ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Falaise_de_Fleur_townhall", "goto", "goto2");
				LAi_SetActorType(CharacterFromID("Lucas Da Saldanha"));
				LAi_ActorTurnToCharacter(CharacterFromID("Lucas Da Saldanha"), CharacterFromID("Joseph Claude Le Moigne"));
			}
		break;

		//--> CTM
		case "Contact_Lucas":
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "Find_Shaw";
			LAi_SetActorType(CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 100.0, 100.0);
		break;

		case "Contact_Gov":
			Characters[GetCharacterIndex("Joseph Claude Le Moigne")].dialog.CurrentNode = "gov_2";
			LAi_SetActorType(characterfromID("Joseph Claude Le Moigne"));
			LAi_ActorDialog(CharacterFromID("Joseph Claude Le Moigne"), PChar, "", 2.0, -1);
			RemovePassenger(pchar, characterFromID("Lucas Da Saldanha"));
			LAi_SetActorType(CharacterFromID("Lucas Da Saldanha"));
		break;
		//<-- CTM

		case "Contact_start_search":
			//PChar.quest.Firstcontact = "search";
			PChar.quest.Lucas_Concern.over = "yes";

			DeleteEnterLocationQuest("Falaise_de_Fleur_townhall", "Contact_start_check");
			bSuppressResurrection = true;

		//--> CTM
			LAi_Type_Actor_Reset(CharacterFromID("Lucas Da Saldanha"));
			SetOfficersIndex(PChar, 3, GetCharacterIndex("Lucas Da Saldanha"));
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.Filename = "Enc_Officer_dialog.c"; // PB
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "hired";
			changeCharacterAddressGroup(CharacterFromID("Captain Maggee"), "Falaise_de_fleur_location_03", "goto", "locator21");
			LAi_SetStayType(characterfromID("Joseph Claude Le Moigne"));
			Characters[GetCharacterIndex("Joseph Claude Le Moigne")].dialog.CurrentNode = "First Time";

			PChar.quest.meet_Maggee_again.win_condition.l1 = "location";
			PChar.quest.meet_Maggee_again.win_condition.l1.character = PChar.id;
			PChar.quest.meet_Maggee_again.win_condition.l1.location = "Falaise_de_fleur_location_03";
			PChar.quest.meet_Maggee_again.win_condition = "meet_Maggee_again";
		//<-- CTM

			//JOURNAL
			AddQuestRecord("Lucas", 18); //CTM
			CloseQuestHeader("Lucas"); //CTM
			SetQuestHeader("Contact");
			AddQuestRecord("Contact", 1);
		break;

		case "meet_Maggee_again":
			Characters[GetCharacterIndex("Captain Maggee")].dialog.CurrentNode = "sail_Maggee1";
			LAi_SetActorType(characterfromID("Captain Maggee"));
			LAi_ActorDialog(CharacterFromID("Captain Maggee"), PChar, "", 100.0, 100.0);
		break;

		//--> CTM
		case "Sail_with_Maggee":
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Captain Maggee"));
			SetCharacterRemovable(characterFromID("Captain Maggee"), false);
			setCharacterShipLocation(characterFromID("Captain Maggee"), "Falaise_de_Fleur_port_01");
			LAi_SetOfficerType(characterfromID("Captain Maggee"));
			Locations[FindLocation("Cuba_port")].vcskip = true; // PB

			Pchar.quest.Now_in_Antigua_from_Cayman_Maggee.win_condition.l1 = "location";
			PChar.quest.Now_in_Antigua_from_Cayman_Maggee.win_condition.l1.character = Pchar.id;
			Pchar.quest.Now_in_Antigua_from_Cayman_Maggee.win_condition.l1.location = "Cuba_port";
			Pchar.quest.Now_in_Antigua_from_Cayman_Maggee.win_condition = "Now_in_Antigua_from_Cayman_Maggee";
		break;

		case "Now_in_Antigua_from_Cayman_Maggee":
			PChar.quest.Firstcontact = "searc";

			DeleteAttribute(&Locations[FindLocation("Cuba_port")], "vcskip"); // PB
			ChangeCharacterAddressGroup(CharacterFromID("Captain Maggee"),"Cuba_port", "goto", "goto_34");

			LAi_SetActorType(characterfromID("Captain Maggee"));
			LAi_ActorDialogNow(Pchar, characterFromID("Captain Maggee"), "", -1);
			LAi_ActorDialog(characterFromID("Captain Maggee"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Captain Maggee")].dialog.currentnode = "Goodbye_at_Antigua";
		break;

		case "Goodbye_Maggee":
			LAi_SetActorType(characterFromID("Captain Maggee"));
			LAi_ActorGoToLocation(CharacterFromID("Captain Maggee"), "reload", "sea_2_back", "none","","","", 100.0);
			RemoveCharacterCompanion(pchar, characterFromID("Captain Maggee"));
		break;
		//<-- CTM

		case "Contact_arendt":
			PChar.quest.Firstcontact = "searc2";
			AddQuestRecord("Contact", 9);
		break;

		case "searchdebris":
			PChar.quest.Firstcontact = "chest";
			AddQuestRecord("Contact", 5);

			Pchar.quest.find_dead.win_condition.l1 = "location";
			Pchar.quest.find_dead.win_condition.l1.location = "SaintMartin_shore_02";
			PChar.quest.find_dead.win_condition = "crewmemberdead";
		break;

		case "crewmemberdead":
			StartQuestMovie(true, false, false);
			DisableFastTravel(true);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "goto", "citizen07"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);
			sld.name = TranslateString("French", "Soldier");
			sld.lastname = "";
			sld.dialog.filename = "Octave Fabre_dialog.c";
			sld.dialog.currentnode = "Smallchest";
			LAi_ActorWaitDialog(sld, pchar);			//CTM
			LAi_ActorDialog(pchar, sld, "", 4.0, 1.0);	//CTM
		break;

		case "jela":
			DisableFastTravel(false);
			EndQuestMovie();
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 1500); }
			PChar.quest.Firstcontact = "oldadmiral";
			GiveItem2Character(pchar, "small_chestJS"); // PB: Custom item to allow different item description
			ChangeCharacterAddress(characterFromID("Reynoud Verheugen"), "none", "");
			Pchar.quest.jela2.win_condition.l1 = "location";
			Pchar.quest.jela2.win_condition.l1.location = "Turks_library";
			PChar.quest.jela2.win_condition = "jela2";
			AddQuestRecord("Contact", 6);
		break;

		case "jela2":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "In Library";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "jela3":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(pchar, "goto", "goto1", "jela4", 100.0);
		break;

		case "jela4":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Davybook";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "pap_storm":
			PChar.quest.Firstcontact = "warning";

			Pchar.quest.davycrew.win_condition.l1 = "location";
			Pchar.quest.davycrew.win_condition.l1.location = "Turks_port";		//JRH: new Turks, was Turks_town_02, exit from library
			PChar.quest.davycrew.win_condition = "pap_storm1";
			Locations[FindLocation("Turks_port")].locators_radius.goto.P_goto11 = 1.5; // PB: Make sure you cannot avoid it

			DisableFastTravel(true);
			DisableMenuLaunch(true);
		break;

		case "pap_storm1":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "pap_storm";
			LAi_ActorSelfDialog(Pchar, "player_back");
		/*
			Pchar.quest.davywarning.win_condition.l1 = "location";
			Pchar.quest.davywarning.win_condition.l1.location = "Turks_town_exit";
			PChar.quest.davywarning.win_condition = "davywarning";
		*/

			pchar.quest.davywarning.win_condition.l1 = "locator";			//JRH: new Turks, at the gate to the shore part
			pchar.quest.davywarning.win_condition.l1.location = "Turks_port";
			pchar.quest.davywarning.win_condition.l1.locator_group = "goto";
			pchar.quest.davywarning.win_condition.l1.locator = "P_goto11";
			pchar.quest.davywarning.win_condition = "davywarning";
		break;

		case "davywarning":
			//ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "Turks_town_exit", "goto", "citizen018");
			//ChangeCharacterAddressGroup(CharacterFromID("Davycrew_02"), "Turks_town_exit", "goto", "citizen017");
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "Turks_port", "goto", "TX_citizen018");	//JRH: new Turks, at the gate to the shore part
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_02"), "Turks_port", "goto", "TX_citizen017");	//JRH: new Turks, at the gate to the shore part
			LAi_SetActorType(CharacterFromID("Davycrew_02"));
			LAi_ActorFollow(CharacterFromID("Davycrew_02"), pchar, "", 10);
			LAi_SetActorType(characterfromID("davycrew_01"));
			LAi_ActorDialog(characterfromID("davycrew_01"), PChar, "", 0.0, 10);
		break;

		case "Contact_antigua":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_02"), "", "", "");
			Characters[GetCharacterIndex("havana_portadmiral")].dialog.CurrentNode = "contact_return1";
			AddQuestRecord("Contact", 10);
		break;

		case "Contact_NoLuck":
			Characters[GetCharacterIndex("havana_portadmiral")].dialog.CurrentNode = "First time";
			PChar.quest.Firstcontact = "prepare_davyencounter";
			AddQuestRecord("Contact", 11);

			Group_CreateGroup("FlyingDutchman");
			Group_AddCharacter("FlyingDutchman", "Davy Jones");
			Group_SetGroupCommander("FlyingDutchman", "Davy Jones");
			Group_SetPursuitGroup("FlyingDutchman", PLAYER_GROUP);
			//Group_SetTaskAttack("FlyingDutchman", PLAYER_GROUP, true);
			Group_SetAddress("FlyingDutchman", "FalaiseDeFleur", "", "");
			Group_LockTask("FlyingDutchman");
			UpdateRelations();
			characters[GetCharacterIndex("Davy Jones")].nosurrender = 2;
			Character_SetAbordageEnable(characterFromID("Davy Jones"), false);

			Pchar.quest.Contact_NoLuck2.win_condition.l1 = "location";
			Pchar.quest.Contact_NoLuck2.win_condition.l1.location = "Cuba";
			PChar.quest.Contact_NoLuck2.win_condition = "Contact_NoLuck2";

// KK -->
			PChar.quest.PrepareDavyEncounter.win_condition.l1 = "MapEnter";
			PChar.quest.PrepareDavyEncounter.win_condition = "PrepareDavyEncounter";
// <-- KK
		break;

// KK -->
		case "PrepareDavyEncounter":
			SetNextWeather("Day Storm");
			PChar.quest.StartDavyEncounter.win_condition.l1 = "SeaEnter";
			PChar.quest.StartDavyEncounter.win_condition = "StartDavyEncounter";
		break;

		case "StartDavyEncounter":
			PChar.quest.voirdavy.win_condition.l1 = "location";
			PChar.quest.voirdavy.win_condition.l1.location = GetCharacterShipQDeck(PChar);
			PChar.quest.voirdavy.win_condition = "voirdavy";

			bQuestDisableAllCommands = true;
			Sea_DeckStartNow(GetMainCharacterIndex(), GetCharacterShipQDeck(PChar));
		break;
// <-- KK

		case "Contact_NoLuck2":
			pchar.vcskip = true;
		break;

		case "voirdavy":
			//ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), PChar.location, "rld", "loc0");
			SetCharacterToNearLocatorFromMe("Davy Jones", 3);
			//SetCharacterToNearLocatorFromMe("Davycrew_01", 10);
			Characters[GetCharacterIndex("Davy Jones")].dialog.currentnode = "First time"; // PB

			LAi_type_actor_Reset(characterFromID("Davycrew_02"));
			//ChangeCharacterAddressGroup(CharacterFromID("Davy Jones"), PChar.location, "rld", "loc2");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorWaitDialog(CharacterFromID("Davy Jones"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Davy Jones"), "", 10.0, 1.0);
		break;

		case "davy_leave":
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Davy Jones"), "", "", "");
			LAi_QuestDelay("meetdaughter", 1.0);
		break;

		case "meetdaughter":
			PChar.quest.Firstcontact = "daughter";
			SetCharacterToNearLocatorFromMe("Elizabeth Shaw", 3);
			LAi_SetActorType(pchar); 
			LAi_SetActorType(characterFromID("Elizabeth Shaw"));
			LAi_ActorWaitDialog(CharacterFromID("Elizabeth Shaw"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Elizabeth Shaw"), "", 10.0, 1.0);

			PChar.quest.Kraken_attack_predmc.win_condition.l1 = "Timer";
			PChar.quest.Kraken_attack_predmc.win_condition.l1.date.day = GetAddingDataDay(0,1,0);
			PChar.quest.Kraken_attack_predmc.win_condition.l1.date.month = GetAddingDataMonth(0,1,0);
			PChar.quest.Kraken_attack_predmc.win_condition.l1.date.year = GetAddingDataYear(0,1,0);
			PChar.quest.Kraken_attack_predmc.win_condition = "Kraken_attack_predmc";

			DeleteAttribute(pchar,"vcskip");
		break;

		case "Kraken_attack_predmc":
			if (!bSeaActive)
			{
				DoQuestCheckDelay("Krak_loop", 1.0);
			}
			else
			{
				KrakenAttack(pchar, GetCharacterShipHP(pchar)/100); // PB: Enough tentacles to sink you twice
				bQuestDisableMapEnter = true;
				Island_SetReloadEnableGlobal("Cuba", false);
				Island_SetReloadEnableGlobal("Oxbay", false);
				Island_SetReloadEnableGlobal("Redmond", false);
				Island_SetReloadEnableGlobal("FalaiseDeFleur", false);
				Island_SetReloadEnableGlobal("IslaMuelle", false);
				Island_SetReloadEnableGlobal("Douwesen", false);
				Island_SetReloadEnableGlobal("Eleuthera", false);
				Island_SetReloadEnableGlobal("Aruba", false);
				Island_SetReloadEnableGlobal("BattleRocks", false);
				Island_SetReloadEnableGlobal("Curacao", false);
				Island_SetReloadEnableGlobal("Guadeloupe", false);
				Island_SetReloadEnableGlobal("KhaelRoa", false);
				Island_SetReloadEnableGlobal("SaintMartin", false);
				Island_SetReloadEnableGlobal("Hispaniola", false);
				Island_SetReloadEnableGlobal("Antigua", false);
				Island_SetReloadEnableGlobal("Cayman", false);

				Pchar.quest.Kraken_got_us_PREDMC.win_condition.l1 = "Ship_HP";
				Pchar.quest.Kraken_got_us_PREDMC.win_condition.l1.character = PChar.id;
				Pchar.quest.Kraken_got_us_PREDMC.win_condition.l1.quantity = 0;
				Pchar.quest.Kraken_got_us_PREDMC.win_condition.l1.operation = "=";
				Pchar.quest.Kraken_got_us_PREDMC.win_condition = "Kraken_got_us_PREDMC";

				DoQuestCheckDelay("Kraken_got_us_PREDMC1", 30.0);
			}
		break;

		case "Krak_loop":
			DoQuestCheckDelay("Kraken_attack_predmc", 1.0);
		break;

		case "Kraken_got_us_PREDMC":
			DoQuestCheckDelay("Kraken_got_us_PREDMC2", 14.0);
		break;

		case "Kraken_got_us_PREDMC1":
			pchar.ship.hp = 0;
			LAi_SetImmortal(PChar, false);
			DoQuestCheckDelay("Kraken_got_us_PREDMC2", 14.0);
		break;

		case "Kraken_got_us_PREDMC2":
			pchar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "kraken");
		break;

		case "sailtocayman":
			bQuestDisableAllCommands = false; // PB
			PChar.quest.Firstcontact = "gotocayman";
			AddQuestRecord("Contact", 7);
			//ChangeCharacterAddressGroup(CharacterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto6");
			//LAi_SetCivilianGuardianType(characterFromID("Edmund Christobel Shaw"));

			Characters[GetCharacterIndex("Joseph Claude Le Moigne")].dialog.CurrentNode = "gov_7";

			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Elizabeth Shaw"));
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Shaw"), "", 60.0);
			SetCharacterRelationBoth(GetCharacterIndex("Davy Jones"),GetMainCharacterIndex(),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Falaise De Fleur Commander"),GetCharacterIndex("Davy Jones"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Grand Cayman Commander"),GetMainCharacterIndex(),RELATION_FRIEND);
		break;

		case "goportcayman":
			LAi_SetPlayerType(pchar);
			LAi_type_actor_Reset(characterFromID("Elizabeth Shaw"));

			DisableFastTravel(true);
			DisableMenuLaunch(true);

			PChar.quest.Kraken_attack_predmc.over = "yes";

			Pchar.quest.find_davy.win_condition.l1 = "locator";
			Pchar.quest.find_davy.win_condition.l1.location = "Falaise_de_Fleur_townhall";
			pchar.quest.find_davy.win_condition.l1.locator_group = "reload";
			pchar.quest.find_davy.win_condition.l1.locator = "reload1";
			PChar.quest.find_davy.win_condition = "gotoseedavy";
		break;

		case "gotoseedavy":
			SetNextWeather("Black Pearl Fight");
			DoQuestReloadToLocation("Quest_Falaise_de_fleur_location_03", "reload", "Falaise_de_Fleur_townhall", "_");
			locations[FindLocation("Quest_Falaise_de_fleur_location_03")].reload.l1.disable = 1;
		break;

		case "davy_townfight1":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "soldier01"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "locator36"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "locator37"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "locator21"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "locator9"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "locator15"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			// -------------------

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy1", "goto", "sitizen06");
			sld.name = "Angler";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy2", "goto", "locator21");
			sld.name = "Ogilvey";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");
 
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy3", "goto", "sitizen07");
			sld.name = "Maccus";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy4", "goto", "locator10");
			sld.name = "Clanker";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy5", "goto", "soldier04");
			sld.name = "Hadras";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy1", "goto", "locator8");
			sld.name = "Urchin";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy2", "goto", "locator11");
			sld.name = "Wheelback";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy3", "goto", "locator13");
			sld.name = "Wyvern";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy4", "goto", "soldier03");
			sld.name = "Quittance";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy5", "goto", "padre");
			sld.name = "Penrod";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			LAi_group_FightGroups("DAVY_CREW", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("DAVY_CREW", "davy_townfight_run");
		break;

		case "davy_townfight_run":
			//ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Quest_Cayman_Port", "officers", "sea_3");
			//ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Quest_Cayman_Port", "officers", "sea_2");
			ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Quest_FalaiseDeFleur_Port2", "goto", "goto8");
			LAi_SetCivilianGuardianType(characterFromID("Davy Jones"));
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "Quest_Falaise_de_fleur_location_04", "goto", "citizen01");
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_02"), "Quest_Falaise_de_fleur_location_04", "goto", "citizen07");
			Characters[GetCharacterIndex("Davy Jones")].dialog.CurrentNode = "begin_14";

			locations[FindLocation("Quest_Falaise_de_fleur_location_03")].reload.l1.disable = 0;
			setCharacterShipLocation(characterFromID("Davy Jones"), "Quest_FalaiseDeFleur_Port2");
			Pchar.quest.davymeet.win_condition.l1 = "location";
			Pchar.quest.davymeet.win_condition.l1.location = "Quest_Falaise_de_fleur_location_04";
			PChar.quest.davymeet.win_condition = "davyonshore";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy1", "reload", "Falaise_de_fleur_location_03_02");
			sld.name = "Angler";
			sld.lastname = "";
			sld.id = "Angler";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy2", "officers", "Falaise_de_fleur_location_03_02_1");
			sld.name = "Ogilvey";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");
 
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy3", "officers", "Falaise_de_fleur_location_03_02_2");
			sld.name = "Maccus";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy4", "officers", "Falaise_de_fleur_location_03_02_3");
			sld.name = "Clanker";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy5", "goto", "locator22");
			sld.name = "Hadras";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy1", "goto", "locator8");
			sld.name = "Urchin";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy2", "goto", "sitizen05");
			sld.name = "Wheelback";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy3", "officers", "Falaise_de_fleur_shipyard_3");
			sld.name = "Wyvern";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy4", "officers", "Falaise_de_fleur_shipyard_1");
			sld.name = "Quittance";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy5", "officers", "Falaise_de_fleur_shipyard_2");
			sld.name = "Penrod";
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Angler"));
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Run_away";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "davy_townfight2":
			LAi_group_FightGroups("DAVY_CREW", LAI_GROUP_PLAYER, true);
		break;

		case "davyonshore":
			PChar.quest.Firstcontact = "davytalks";
			Characters[GetCharacterIndex("Davycrew_01")].dialog.CurrentNode = "begin_6";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "locator25"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "locator26"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetActorType(characterfromID("davycrew_01"));
			LAi_ActorDialog(characterfromID("davycrew_01"), PChar, "", 100.0, 100.0);
		break;

		case "davyonshore1":
			DoQuestReloadToLocation("Quest_FalaiseDeFleur_Port2", "reload", "Falaise_de_fleur_location_01_05", "davyonshore2");
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "Quest_FalaiseDeFleur_Port2", "goto", "soldier_01");
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_02"), "Quest_FalaiseDeFleur_Port2", "goto", "goto3");
		break;

		case "davyonshore2":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "locator28");
			LAi_SetHP(sld, 80.0, 80.0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto1"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "officers", "sea_1"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			Characters[GetCharacterIndex("Davycrew_01")].dialog.CurrentNode = "begin_7";
			LAi_SetActorType(characterfromID("davycrew_01"));
			LAi_ActorDialog(characterfromID("davycrew_01"), PChar, "", 100, 100);
		break;

		case "davyonshore3":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "officers", "sea_3", "davyonshore4", 10.0);
		break;

		case "davyonshore4":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorWaitDialog(CharacterFromID("Davy Jones"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Davy Jones"), "", 10.0, 1.0);
		break;

		case "pushdavy":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorAnimation(pchar, "attack_fast_2", "davywater", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
		break;

		case "davywater":
			//ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Quest_Cayman_Port", "reload", "sea");
			ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Quest_FalaiseDeFleur_Port2", "goto", "goto7");
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorAnimation(characterFromID("Davy Jones"), "Ground_StandUp", "davyinwater", 3.0);
		break;

		case "davyinwater":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			Characters[GetCharacterIndex("Davy Jones")].dialog.currentnode = "begin_16";
			LAi_ActorWaitDialog(CharacterFromID("Davy Jones"), Pchar);
			LAi_ActorDialog(PChar, characterFromID("Davy Jones"), "", 0.0, 1.0);
		break;

		case "davyshootsme":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorAttack(characterFromID("Davy Jones"), pchar, "");
			LAi_QuestDelay("davyhurtme", 2.7);
			//LAi_ActorAnimation(characterFromID("Davy Jones"), "shot", "davyhurtme", 1.0);
		break;

		case "davyhurtme":
			bSuppressResurrection = true;
			LAi_SetStayType(CharacterFromID("Davy Jones"));
			//LAi_CharacterFireExecute(characterfromid("Davy Jones"), pchar, 100, true);
			//GetCharacterPos(characterfromid("Davy Jones"), &locx, &locy, &locz);
			//CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			Lai_KillCharacter(pchar);
			LAi_QuestDelay("preroomcayman", 3.0);
			LAi_QuestDelay("goroomcayman", 6.0);
		break;

		case "preroomcayman":
			ChangeCharacterAddress(characterFromID("Davy Jones"), "none", "");
		break;

		case "goroomcayman":
			DoQuestReloadToLocation("Falaise_de_fleur_Tavern_upstairs", "goto", "goto4", "_");
			locations[FindLocation("Falaise_de_fleur_Tavern_upstairs")].reload.l1.disable = 1;
			LAi_SetPlayerType(pchar);
			LAi_SetCurHP(pchar, LAi_GetCharacterMaxHP(pchar)); // PB: To heal character
			ChangeCharacterAddressGroup(CharacterFromID("Elizabeth Shaw"), "Falaise_de_fleur_Tavern_upstairs", "goto", "goto7");
			Characters[GetCharacterIndex("Elizabeth Shaw")].dialog.CurrentNode = "begin_4";
			LAi_SetActorType(characterfromID("Elizabeth Shaw"));
			LAi_ActorDialog(characterfromID("Elizabeth Shaw"), PChar, "", 0.5, 10);
			bSuppressResurrection = false;
		break;

		case "goresidencecayman":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			SetNextWeather("Blue Sky");
			locations[FindLocation("Falaise_de_fleur_Tavern_upstairs")].reload.l1.disable = 0;
			LAi_SetActorType(characterFromID("Elizabeth Shaw"));
			LAi_ActorGoToLocation(characterFromID("Elizabeth Shaw"), "reload", "reload1", "none", "", "", "", 0.0);
			Characters[GetCharacterIndex("Joseph Claude Le Moigne")].dialog.CurrentNode = "gov_9";
			ChangeCharacterAddressGroup(CharacterFromID("Joseph Claude Le Moigne"), "Falaise_de_fleur_townhall", "sit", "sit2");
			LAi_SetHuberType(characterfromID("Joseph Claude Le Moigne"));
			Group_SetAddressNone("FlyingDutchman");
		break;

		case "beaufinal":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 25000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 25000); }

			bSuppressResurrection = false;
			AddMoneyToCharacter(pchar, 40000);
			AddQuestRecord("Contact", 8);
			ItemSetPrice("small_chestJS", 1);		// GR: can now dump chest into a chest
			//CloseQuestHeader("Contact");

			Pchar.quest.Tia_and_Maggee.win_condition.l1 = "location";
			Pchar.quest.Tia_and_Maggee.win_condition.l1.location = "Falaise_de_fleur_location_03";
			PChar.quest.Tia_and_Maggee.win_condition = "Tia_and_Maggee";

//			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "First Time";
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.Filename = "Enc_Officer_dialog.c"; // PB
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "hired";
		break;

		case "Tia_and_Maggee":
			changeCharacterAddressGroup(CharacterFromID("Captain Maggee"), "Falaise_de_fleur_location_03", "goto", "sitizen07");
			changeCharacterAddressGroup(CharacterFromID("Tia Dalma"), "Falaise_de_fleur_location_03", "goto", "sitizen07");

			LAi_SetActorType(characterfromID("Captain Maggee"));
			LAi_SetActorType(characterfromID("Tia Dalma"));
			LAi_ActorDialog(characterFromID("Captain Maggee"),PChar,"",100.0,100.0);
			LAi_ActorFollow(characterfromID("Tia Dalma"), characterfromID("Captain Maggee"), "", -1);
			Characters[GetCharacterIndex("Captain Maggee")].dialog.currentnode = "Meeting_Tia";
		break;

		case "Tia_and_Maggee2":
			LAi_ActorFollowEverywhere(characterFromID("Tia Dalma"), "", 60.0);
			LAi_ActorGoToLocation(characterFromID("Captain Maggee"), "reload", "Falaise_de_fleur_location_03_02", "none", "", "", "", 0.0);

			PChar.quest.Tia_to_Davy.win_condition.l1 = "MapEnter";
			PChar.quest.Tia_to_Davy.win_condition = "Tia_to_Davy";
		break;

		case "Tia_to_Davy":
			//Sea_DeckStartNow(GetMainCharacterIndex(), GetCharacterShipQDeck(pchar));
			string QDeck = GetCharacterShipQDeck(pchar);
//			DoQuestReloadToLocation(QDeck, "rld", "startloc", "Tia_to_Davy2");	// Doesn't work if you direct-sail to next island

			SetNextWeather("Day Storm");
			//LAi_QuestDelay("Tia_to_Davy2", 1.0);
			PChar.quest.Tia_to_Davy1_5.win_condition.l1 = "SeaEnter";
			PChar.quest.Tia_to_Davy1_5.win_condition = "Tia_to_Davy1.5";
		break;

		case "Tia_to_Davy1.5":
			DoReloadFromSeaToLocation(GetCharacterShipQDeck(PChar), "rld", "startloc");
			PChar.quest.Tia_to_Davy2.win_condition.l1 = "location";
			PChar.quest.Tia_to_Davy2.win_condition.l1.location = GetCharacterShipQDeck(PChar);
			PChar.quest.Tia_to_Davy2.win_condition = "Tia_to_Davy2";
		break;

		case "Tia_to_Davy2":
			SetCharacterToNearLocatorFromMe("Davy Jones", 3);
			SetCharacterToNearLocatorFromMe("Tia Dalma", 20);

			LAi_SetActorType(characterfromID("Davy Jones"));
			LAi_ActorDialog(characterFromID("Davy Jones"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Davy Jones")].dialog.currentnode = "Caught_up_after_Cayman";
		break;

		case "Tia_to_Davy_early":
			LAi_SetActorType(characterfromID("Davy Jones"));
			LAi_ActorTurnToCharacter(CharacterFromID("Davy Jones"), CharacterFromID("Tia Dalma"));

			LAi_SetActorType(characterfromID("Tia Dalma"));
			LAi_ActorDialog(characterFromID("Tia Dalma"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Tia Dalma")].dialog.currentnode = "Tia_Talk_to_Davy_early";
		break;

		case "Tia_to_Davy_early2":
			LAi_SetActorType(characterfromID("Davy Jones"));
			LAi_ActorDialog(characterFromID("Davy Jones"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Davy Jones")].dialog.currentnode = "Tia_Talk_to_Davy_early2";
		break;

		case "Tia_to_Davy_early3":
			LAi_QuestDelay("Tia_to_Davy_early4", 2.0);
		break;

		case "Tia_to_Davy_early4":
			changeCharacterAddressGroup(characterFromID("Davy Jones"), "none", "", "");
			changeCharacterAddressGroup(characterFromID("Tia Dalma"), "none", "", "");
			LAi_QuestDelay("reload_to_sea_after_davy", 2.0);

			AddQuestRecord("Contact", 12);
			CloseQuestHeader("Contact");
		break;

		case "Tia_to_Davy_DMC":
			LAi_SetActorType(characterfromID("Davy Jones"));
			LAi_ActorTurnToCharacter(CharacterFromID("Davy Jones"), CharacterFromID("Tia Dalma"));

			LAi_SetActorType(characterfromID("Tia Dalma"));
			LAi_ActorDialog(characterFromID("Tia Dalma"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Tia Dalma")].dialog.currentnode = "Tia_Talk_to_Davy_DMC";
		break;

		case "Tia_to_Davy_DMC2":
			LAi_SetActorType(characterfromID("Davy Jones"));
			LAi_ActorDialog(characterFromID("Davy Jones"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Davy Jones")].dialog.currentnode = "Tia_Talk_to_Davy_DMC2";
		break;

		case "Tia_to_Davy_DMC3":
			LAi_QuestDelay("Tia_to_Davy_DMC4", 2.0);
		break;

		case "Tia_to_Davy_DMC4":
			changeCharacterAddressGroup(characterFromID("Davy Jones"), "none", "", "");

			LAi_SetActorType(characterfromID("Tia Dalma"));
			LAi_ActorDialog(characterFromID("Tia Dalma"),PChar,"",100.0,100.0);
			Characters[GetCharacterIndex("Tia Dalma")].dialog.currentnode = "Take_Tia_to_shack";

			LAi_ActorFollowEverywhere(characterFromID("Tia Dalma"), "", 60.0);

//			AddQuestRecord("Contact", 13);
			AddQuestRecord("Contact", 15);	// GR: Line 13 is about Marigot governor.  Line 15 is about Tia Dalma.
			CloseQuestHeader("Contact");
		break;

		case "reload_to_sea_after_davy":
			QuestToSeaLogin_PrepareLoc("FalaiseDeFleur", "reload", "reload_2", false);
			QuestToSeaLogin_Launch();
		break;

		case "At_Shack_Warning":
			LAi_type_actor_Reset(characterFromID("Tia Dalma"));
			ChangeCharacterAddressGroup(characterFromID("Tia Dalma"), "Tia_shack", "sit", "sit1");
			LAi_ActorSetSitMode(characterFromID("Tia Dalma"));

			LAi_SetActorType(characterfromID("Tia Dalma"));
			LAi_ActorDialog(characterFromID("Tia Dalma"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Tia Dalma")].dialog.currentnode = "find_the_key";

			CloseQuestHeader("Contact");
		break;
		// CTM - Explaining Davy Jones over <--

		PChar.questnotfound = true; // PB: Testing
	}
}