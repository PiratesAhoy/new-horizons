void QuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld;
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
		case "Start":
			PauseAllSounds();
			locations[FindLocation("Antigua_port")].type = "Hornblower_port";
//			PostEvent("LoadSceneSound", 2750);
			AlwaysRunToggle = false;
			DisableFastTravel(true);
			pchar.quest.Players_Rank = "Midshipman";
			pchar.quest.Soldier_Company = "Foot";
			SetQuestHeader("My First Ship");
			AddQuestRecord("My First Ship", 13);
			Locations[FindLocation("Antigua_Residence")].vcskip = true;
			Locations[FindLocation("Quest_FireShipDeck")].vcskip = true;
			Locations[FindLocation("Quest_ShipDeck6")].vcskip = true;
			Locations[FindLocation("Treasure_Alcove")].vcskip = true;
			Locations[FindLocation("Labirint_1")].vcskip = true;
			Locations[FindLocation("Labirint_2")].vcskip = true;
			Locations[FindLocation("Labirint_3")].vcskip = true;

			Locations[FindLocation("Prison_Shore")].vcskip = true;
			Locations[FindLocation("Antigua_port")].reload.l7.disable = 1;
			Locations[FindLocation("Antigua_port")].reload.l8.disable = 1;
			Locations[FindLocation("Antigua_port")].reload.l27.disable = 1;
			Locations[FindLocation("Antigua_port")].reload.l3.disable = 1;
			Locations[FindLocation("Antigua_port")].reload.l5.disable = 1;
			Locations[FindLocation("Antigua_Residence")].reload.l2.disable = 1;
			Locations[FindLocation("Antigua_Residence")].reload.l3.disable = 1;

			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Antigua_Residence", "goto", "goto9");
			ChangeCharacterAddress(characterFromID("Antigua_Regulating"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Major Dunnitt"), "Antigua_Port", "goto", "goto5");
			LAi_SetGuardianType(characterFromID("Major Dunnitt"));

			LAi_ActorGoToLocator(characterfromID("Rifleman Cooper"), "merchant", "merchant2", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Haggman"), "merchant", "merchant2", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Harris"), "merchant", "merchant2", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Higgins"), "merchant", "merchant2", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Tongue"), "merchant", "merchant2", "", 0.0);

			LAi_SetCitizenType(characterFromID("Able Seaman Wilks"));
			LAi_SetCitizenType(characterFromID("Able Seaman Tompkins"));
			LAi_SetCitizenType(characterFromID("Able Seaman Stanley"));
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Antigua_Port", "goto", "goto5");
			LAi_SetCitizenType(characterFromID("Thomas Wolfe"));

			Pchar.quest.Join_the_ship_crew.win_condition.l1 = "location";
			PChar.quest.Join_the_ship_crew.win_condition.l1.character = Pchar.id;
			Pchar.quest.Join_the_ship_crew.win_condition.l1.location = "Antigua_academy";
			Pchar.quest.Join_the_ship_crew.win_condition = "Join_the_ship_crew";

			if(ENABLE_CHEATMODE) ChangeCharacterAddressGroup(CharacterFromID("C.S. Forester"),"Antigua_Port", "reload", "houseH2"); // PB: For testing
		break;

		case "change_uniforms": // for testing only via C.S. Forester
			Locations[FindLocation("Antigua_port")].reload.l5.disable = 0;
			pchar.quest.Players_Rank = "Lieutenant";
			SetRank(pchar, ENGLAND, 2); // PB: 3rd Lieutenant
			GiveModel2Player("brtlut1_18", true);
			pchar.quest.Soldier_Company = "Sergeant";
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Antigua_port", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Antigua_port", "goto", "goto27");
			SetModelfromArray(characterFromID("Richard Sharpe"), GetModelIndex("SharpeS_Rif8_18"));
			Characters[GetCharacterIndex("Richard Sharpe")].headmodel = "h_SharpeS_Rif8_18";
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_outskirts", "goto", "goto15");
			Characters[GetCharacterIndex("Patrick Harper")].model = "Rifleman_Harper";
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Rifleman_Harper";
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_outskirts", "goto", "goto15");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Antigua_outskirts", "goto", "goto14");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_outskirts", "goto", "goto14");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Antigua_outskirts", "goto", "goto15");
			Characters[GetCharacterIndex("Rifleman Haggman")].model = "Rifleman95B4_18";
			Characters[GetCharacterIndex("Rifleman Haggman")].headmodel = "h_Rifleman95B4_18";
			Characters[GetCharacterIndex("Rifleman Higgins")].model = "Rifleman95D3_18";
			Characters[GetCharacterIndex("Rifleman Higgins")].headmodel = "h_Rifleman95D3_18";
			Characters[GetCharacterIndex("Rifleman Tongue")].model = "Rifleman95F3_18";
			Characters[GetCharacterIndex("Rifleman Tongue")].headmodel = "h_Rifleman95F3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].model = "Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].headmodel = "h_Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Harris")].model = "Rifleman95B3_18";
			Characters[GetCharacterIndex("Rifleman Harris")].headmodel = "h_Rifleman95B3_18";
			Characters[GetCharacterIndex("Rifleman Mansfield")].model = "Rifleman95A3_18";
			Characters[GetCharacterIndex("Rifleman Mansfield")].headmodel = "h_Rifleman95A3_18";

			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. Uriah Quelp"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Matthews"));
			LAi_SetActorType(characterFromID("Oldroyd"));
			LAi_SetActorType(characterFromID("Styles"));

			LAi_QuestDelay("Antigua_for_battle", 0.0);
		break; // end testing

		case "Join_the_ship_crew":
			locations[FindLocation("Antigua_port")].type = "port";
			ChangeCharacterAddress(characterFromID("Major Dunnitt"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Harris"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			ChangeCharacterAddressGroup(CharacterFromID("C.S. Forester"), "none", "", ""); // PB

			ChangeCharacterAddressGroup(characterFromID("Captain Keene"), "Antigua_academy", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Captain James Sawyer"), "Antigua_academy", "sit", "sit1");
			LAi_ActorSetSitMode(characterFromID("Captain James Sawyer"));
			ChangeCharacterAddressGroup(characterFromID("Jack Simpson"), "Antigua_Academy", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Antigua_Academy", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Clayton"), "Antigua_Academy", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Antigua_Academy", "officers", "reload1_2");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_Academy", "reload", "reload2");
			ChangeCharacterAddressGroup(characterFromID("William Chumley"), "Antigua_Academy", "goto", "goto5");
			LAi_SetActorType(characterFromID("William Chumley"));
			LAi_SetActorType(characterFromID("Jack Simpson"));
			LAi_SetSitType(characterfromID("Captain James Sawyer"));
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Continue_with_Justinian";
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto1", "arrived_from_England", 10);
		break;

		case "arrived_from_England":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_ActorSetSitMode(characterFromID("Captain James Sawyer"));
			LAi_ActorDialog(characterfromID("Captain James Sawyer"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Continue_with_Justinian";
			Characters[GetCharacterIndex("Captain Keene")].dialog.currentnode = "Board_at_Charlestown";
		break;

		case "Keene_has_his_say":
			characters[GetCharacterIndex("Captain Keene")].Dialog.Filename = "Captain Keene_dialog.c";
			LAi_SetActorType(characterFromID("Captain Keene"));
			LAi_ActorDialogNow(characterFromID("Captain Keene"),PChar,"",1.0);
			Characters[GetCharacterIndex("Captain Keene")].dialog.currentnode = "Board_at_Charlestown";
		break;

		case "Agent_supply_run":
			AddQuestRecord("My First Ship", 8);
			AddQuestRecord("My First Ship", 9);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Archie Kennedy"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Clayton"));
			SetCharacterRemovable(characterFromID("Archie Kennedy"), false);
			SetCharacterRemovable(characterFromID("Clayton"), false);

			Pchar.quest.more_of_the_same.win_condition.l1 = "location";
			PChar.quest.more_of_the_same.win_condition.l1.character = Pchar.id;
			Pchar.quest.more_of_the_same.win_condition.l1.location = "Antigua_port";
			Pchar.quest.more_of_the_same.win_condition = "more_of_the_same";
		break;

		case "more_of_the_same":
			ChangeCharacterAddress(characterFromID("Captain Keene"), "None", "");
			ChangeCharacterAddress(characterFromID("Captain James Sawyer"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("William Chumley"), "None", "");

			Locations[FindLocation("Antigua_port")].reload.l16.disable = 1;
			Locations[FindLocation("Antigua_port")].reload.l7.disable = 0;
			Locations[FindLocation("Antigua_port")].reload.l27.disable = 0;
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto19", "", 20);
			Characters[GetCharacterIndex("Clayton")].dialog.currentnode = "Start_at_Charlestown";
			LAi_QuestDelay("more_of_the_same2", 5.0);
		break;

		case "more_of_the_same2":
			LAi_SetPlayerType(pchar);
			PlaySound("VOICE\ENGLISH\Clayton01.wav");
			LAi_SetActorType(characterFromID("Clayton"));
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialog(characterfromID("Clayton"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "Archie_at_Charlestown";
		break;

		case "Archie_chips_in":
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Antigua_port", "reload", "houseS4");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_port", "reload", "houseS4");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Antigua_port", "reload", "houseS4");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Antigua_port", "reload", "houseS4");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_port", "reload", "houseS4");

			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));

			LAi_ActorDialog(characterfromID("Archie Kennedy"), pchar, "", 1.0, 1.0);
		break;

		case "Get_on_with_it_Gentlemen":
			LAi_SetOfficerType(characterFromID("Clayton"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "First time";

			LAi_ActorGoToLocator(characterfromID("Rifleman Cooper"), "goto", "goto3", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Haggman"), "goto", "goto3", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Harris"), "goto", "goto3", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Higgins"), "goto", "goto3", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Tongue"), "goto", "goto3", "", 0.0);

			Pchar.quest.First_Briefing.win_condition.l1 = "location";
			PChar.quest.First_Briefing.win_condition.l1.character = Pchar.id;
			Pchar.quest.First_Briefing.win_condition.l1.location = "Antigua_Residence";
			Pchar.quest.First_Briefing.win_condition = "First_Briefing";
		break;

		case "First_Briefing":
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Antigua_Residence", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Sir Hew Dalrymple"), "Antigua_Residence", "goto", "goto8");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Antigua_Residence", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Clayton"), "Antigua_Residence", "goto", "goto6");
			LAi_QuestDelay("First Briefing2", 0.0);
		break;

		case "First Briefing2":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Clayton"));
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			LAi_ActorGoToLocator(characterFromID("Clayton"), "goto", "goto1", "",10);
			LAi_ActorGoToLocator(characterFromID("Archie Kennedy"), "goto", "goto2", "",10);
			LAi_ActorGoToLocator((Pchar), "goto", "goto3", "First Briefing3", 10);
			LAi_ActorTurnToCharacter(characterFromID("Sir Edward Pellew"), Pchar);
		break;

		case "First Briefing3":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Sir Hew Dalrymple"));
			LAi_ActorDialog(characterfromID("Sir Hew Dalrymple"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Sir Hew Dalrymple")].dialog.currentnode = "Why_we_are_here";
		break;

		case "To_the_Shipyard_Antigua":
			AddQuestRecord("My First Ship", 14);
			LAi_SetOfficerType(characterFromID("Clayton"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			LAi_ActorGoToLocator(characterFromID("Sir Hew Dalrymple"), "reload", "reload3", "",5);
			LAi_ActorGoToLocator(characterFromID("Sir Edward Pellew"), "reload", "reload3", "",5);
			LAi_QuestDelay("To_the_Shipyard_Antigua2", 3.0);
		break;

		case "To_the_Shipyard_Antigua2":
			AddQuestRecord("My First Ship", 14);
			ChangeCharacterAddress(characterFromID("Sir Edward Pellew"), "None", "");
			ChangeCharacterAddress(characterFromID("Sir Hew Dalrymple"), "None", "");

			ChangeCharacterAddressGroup(characterFromID("Jack Simpson"), "Antigua_port", "goto", "goto5");
			LAi_SetActorType(characterFromID("Jack Simpson"));
			Characters[GetCharacterIndex("Jack Simpson")].dialog.currentnode = "Fight_at_Charlestown";

			Pchar.quest.Simpson_shows_up.win_condition.l1 = "location";
			PChar.quest.Simpson_shows_up.win_condition.l1.character = Pchar.id;
			Pchar.quest.Simpson_shows_up.win_condition.l1.location = "Antigua_port";
			Pchar.quest.Simpson_shows_up.win_condition = "Simpson_shows_up";
		break;

		case "Simpson_shows_up":
			LAi_SetImmortal(Pchar, true);
			ChangeCharacterAddress(characterFromID("Able Seaman Wilks"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Tompkins"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Stanley"), "None", "");
			ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");
			LAi_QuestDelay("Simpson_shows_up2", 2.0);
		break;

		case "Simpson_shows_up2":
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));
			LAi_SetActorType(characterFromID("Thomas Wolfe"));

			LAi_SetActorType(characterFromID("Clayton"));
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"),characterFromID("Jack Simpson"));
			LAi_ActorDialog(characterfromID("Jack Simpson"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Jack Simpson")].dialog.currentnode = "Fight_at_Charlestown";
		break;

		case "Get_back_to_the_ship":
			LAi_ActorAnimation(characterFromID("Jack Simpson"), "attack_2", "Simpson_runs_off", -1);
			PlaySound("OBJECTS\duel\punch1.wav");
			Characters[GetCharacterIndex("Clayton")].dialog.currentnode = "Charlestown_fight";
		break;

		case "Simpson_runs_off":
			LAi_SetImmortal(Pchar, false);
			PlaySound("VOICE\ENGLISH\Clayton01.wav");
			LAi_ActorRunToLocator(characterFromID("Jack Simpson"), "goto", "goto9", "",10);
			LAi_ActorDialog(characterfromID("Clayton"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Clayton")].dialog.currentnode = "Charlestown_fight";
		break;

		case "Simpson_gone_for_now":
			AddQuestRecord("My First Ship", 10);
			Locations[FindLocation("Antigua_Residence")].reload.l2.disable = 0;
			Locations[FindLocation("Antigua_Residence")].reload.l3.disable = 0;
			Locations[FindLocation("Antigua_port")].reload.l8.disable = 0;
			ChangeCharacterAddress(characterFromID("Jack Simpson"), "None", "");
			LAi_SetOfficerType(characterFromID("Clayton"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));

			LAi_ActorGoToLocator(characterfromID("Rifleman Cooper"), "reload", "houseS4", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Haggman"), "reload", "houseS4", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Harris"), "reload", "houseS4", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Higgins"), "reload", "houseS4", "", 0.0);
			LAi_ActorGoToLocator(characterfromID("Rifleman Tongue"), "reload", "houseS4", "", 0.0);

			Pchar.quest.Get_bigger_guns = "Antigua_Dockyard"; // PB
		break;

		case "Now_Join_The_Justinian":
			Locations[FindLocation("Antigua_port")].reload.l3.disable = 0;
			Locations[FindLocation("Antigua_port")].reload.l5.disable = 0;
			LAi_Fade("", "");
			DoQuestReloadToLocation("Quest_ShipDeck6", "goto", "goto13", "Another_run_in_with_Simson");

			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			Locations[FindLocation("Quest_ShipDeck6")].vcskip = true;
			LAi_SetActorType(characterFromID("Clayton"));
			LAi_SetActorType(characterFromID("Jack Simpson"));
			LAi_SetActorType(characterFromID("Captain Keene"));
			LAi_SetActorType(characterFromID ("Lt. Percy Buckland"));
			LAi_SetActorType(characterFromID("Archie Kennedy"));
		break;

		case "Another_run_in_with_Simson":
			Locations[FindLocation("Quest_ShipDeck6")].vcskip = true;
			ChangeCharacterAddressGroup(characterFromID("Captain Keene"), "Quest_ShipDeck6", "goto", "goto5"); //"reload", "boatr");
			ChangeCharacterAddressGroup(characterFromID("Clayton"), "Quest_ShipDeck6", "goto", "goto11");
			ChangeCharacterAddressGroup(characterFromID("Jack Simpson"), "Quest_ShipDeck6", "reload", "boatl");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Quest_ShipDeck6", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Lt. Eccleston"), "Quest_ShipDeck6", "goto", "marine2");
			ChangeCharacterAddressGroup(characterFromID("Ebenezer Bracegirdle"), "Quest_ShipDeck6", "goto", "goto27");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "marine1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "marine5");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG2B";

			LAi_ActorTurnToCharacter(characterFromID("Clayton"), pchar);
			LAi_ActorTurnToCharacter(characterFromID("Jack Simpson"), pchar);
			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"), pchar);
			characters[GetCharacterIndex("Jack Simpson")].Dialog.Filename = "Jack Simpson_dialog.c";
			LAi_SetActorType(characterFromID("Jack Simpson"));
			Characters[GetCharacterIndex("Jack Simpson")].dialog.CurrentNode = "Run_in_number_two";
			LAi_ActorDialog(characterFromID("Jack Simpson"), pchar, "", 5.0, 5.0);
		break;

		case "Keene_interupts_Simpson":
			LAi_SetActorType(characterFromID("Ebenezer Bracegirdle"));

			characters[GetCharacterIndex("Ebenezer Bracegirdle")].Dialog.Filename = "Lieutenant Bracegirdle_dialog.c";
			LAi_SetActorType(characterFromID("Ebenezer Bracegirdle"));
			Characters[GetCharacterIndex("Ebenezer Bracegirdle")].dialog.CurrentNode = "Report_gentlemen";
			LAi_ActorDialog(characterFromID("Ebenezer Bracegirdle"), pchar, "", 0.0, 0.0);
		break;

		case "Into_ship_one_position":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto26", "Keene_interupts_Simpson2", 20.0);
			LAi_ActorGoToLocator(characterFromID("Ebenezer Bracegirdle"), "goto", "marine4", "",20.0);
			LAi_ActorRunToLocator(characterFromID("Archie Kennedy"), "goto", "goto24", "",15.0);
			LAi_ActorRunToLocator(characterFromID("Clayton"), "goto", "goto25", "",15.0);
			LAi_ActorRunToLocator(characterFromID("Captain Keene"), "reload", "boatr", "",15.0);
		break;

		case "Keene_interupts_Simpson2":
			PlaySound("OBJECTS\shipcharge\Eng_the_side.wav");
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Ebenezer Bracegirdle"));
			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"), characterFromID("Lt. Eccleston"));
			LAi_ActorTurnToCharacter(characterFromID("Clayton"), characterFromID("Lt. Eccleston"));
			Characters[GetCharacterIndex("Captain Keene")].dialog.CurrentNode = "issue_sailing_orders";
			LAi_ActorGoToLocator(characterFromID("Captain Keene"), "goto", "marine3", "Keene_interupts_Simpson3",20.0);
		break;

		case "Keene_interupts_Simpson3":
			LAi_SetPlayerType(pchar);
			LAi_ActorTurnToCharacter(characterFromID("Captain Keene"), pchar);
			LAi_ActorTurnToCharacter(characterFromID("Lt. Eccleston"), characterFromID("Captain Keene"));
			LAi_ActorTurnToCharacter(characterFromID("Ebenezer Bracegirdle"), characterFromID("Captain Keene"));
			characters[GetCharacterIndex("Captain Keene")].Dialog.Filename = "Captain Keene_dialog.c";
			LAi_SetActorType(characterFromID("Captain Keene"));	
			Characters[GetCharacterIndex("Captain Keene")].dialog.CurrentNode = "issue_sailing_orders";
			LAi_ActorDialog(characterFromID("Captain Keene"), pchar, "", 10.0, 10.0);
		break;

		case "Sail_for_Guadeloupe":
//			DisableFastTravel(false); // PB: This could allow players to break their game
			LAi_ActorRunToLocator(characterFromID("Jack Simpson"), "goto", "goto5", "",5.0);
			LAi_ActorRunToLocator(characterFromID("Archie Kennedy"), "goto", "goto4", "",5.0);
			LAi_ActorRunToLocator(characterFromID("Clayton"), "goto", "goto3", "",5.0);
			LAi_QuestDelay("Sail_for_Guadeloupe2", 0.0);
		break;

		case "Sail_for_Guadeloupe2":
			LAi_SetGuardianType(characterFromID("Helmsman"));
			characters[GetCharacterIndex("Helmsman")].Dialog.Filename = "Helmsman_dialog.c";
			Characters[GetCharacterIndex("Helmsman")].dialog.CurrentNode = "First_sailing_orders";
			LAi_ActorDialog(characterFromID("Helmsman"), pchar, "", 10.0, 10.0);
		break;

		case "Sail_for_Guadeloupe3":
			LAi_QuestDelay("Sail_for_Guadeloupe4", 3.0);
		break;

		case "Sail_for_Guadeloupe4":
			DisableFastTravel(false); //PB: Moved here instead
			QuestToSeaLogin_PrepareLoc("Antigua", "reload", "Sea_2_back", false);
			QuestToSeaLogin_Launch();

			LAi_SetActorType(characterFromID("Helmsman"));
			Characters[GetCharacterIndex("Helmsman")].dialog.CurrentNode = "First time";
			SetCharacterRemovable(characterFromID("Archie Kennedy"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Archie Kennedy"));
			RemovePassenger(pchar, characterFromID("Archie Kennedy"));
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jack Simpson"));
			SetCharacterRemovable(characterFromID("Jack Simpson"), false);
			LAi_SetOfficerType(characterFromID("Clayton"));

			pchar.quest.To_Guadeloupe_shore_01.win_condition.l1 = "location";
			pchar.quest.To_Guadeloupe_shore_01.win_condition.l1.location = "Guadeloupe_shore_01";
			pchar.quest.To_Guadeloupe_shore_01.win_condition = "To_Guadeloupe_shore_01";
		break;

		case "To_Guadeloupe_shore_01":
			Locations[FindLocation("Quest_ShipDeck6")].vcskip = false;
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			ChangeCharacterAddressGroup(characterFromID("Lt. Percy Buckland"), "Guadeloupe_shore_01", "goto", "citizen04");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Guadeloupe_shore_01", "goto", "locator14");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Guadeloupe_shore_01", "goto", "seaman1");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Guadeloupe_shore_01", "goto", "seaman2");
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Matthews"));
			LAi_SetActorType(characterFromID("Styles"));

			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_SetCivilianGuardianType(characterFromID("Lt. Percy Buckland"));
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "why_were_you_late";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"), pchar, "", 5.0, 5.0);
		break;

		case "Showdown_with_Simpson":
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			LAi_ActorGoToLocator(characterFromID("Lt. Percy Buckland"), "goto", "locator11", "",2);
			LAi_ActorRunToLocator(characterFromID("Archie Kennedy"), "goto", "citizen02", "Showdown_with_Simpson2",2);
			LAi_ActorRunToLocator(characterFromID("Matthews"), "goto", "citizen03", "",2);
			LAi_ActorRunToLocator(characterFromID("Styles"), "goto", "locator12", "",2);
		break;

		case "Showdown_with_Simpson2":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Jack Simpson"));
			LAi_ActorGoToLocator(characterFromID("Jack Simpson"), "goto", "citizen04", "Showdown_with_Simpson3",5);
		break;

		case "Showdown_with_Simpson3":
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("Jack Simpson")].Dialog.Filename = "Jack Simpson_dialog.c";
			LAi_SetActorType(characterFromID("Jack Simpson"));
			Characters[GetCharacterIndex("Jack Simpson")].dialog.CurrentNode = "Run_in_on_the_beach";
			LAi_ActorDialog(characterFromID("Jack Simpson"), pchar, "", 10.0, 10.0);
		break;

		case "Clayton_interupts_Simpson":
			characters[GetCharacterIndex("Clayton")].Dialog.Filename = "Clayton_dialog.c";
			LAi_SetActorType(characterFromID("Clayton"));
			Characters[GetCharacterIndex("Clayton")].dialog.CurrentNode = "Clayton_on_the_beach";
			LAi_ActorDialog(characterFromID("Clayton"), pchar, "", 10.0, 10.0);
		break;

		case "The Lieutenant Arrives Back":
			LAi_Fade("The Lieutenant Arrives Back2", "The Lieutenant Arrives Back3");
			LAi_ActorAnimation(characterFromID("Clayton"), "attack_2", "The Lieutenant Arrives Back2", -1);
			PlaySound("OBJECTS\duel\punch1.wav");
		break;

		case "The Lieutenant Arrives Back2":
			LAi_SetActorType(pchar);
			ChangeCharacterAddressGroup(Pchar, "Guadeloupe_shore_01", "goto", "locator13");
			SetCharacterRemovable(characterFromID("Clayton"), true);
			Lai_KillCharacter(characterFromID("Clayton"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Clayton"));
			LAi_ActorAnimation((Pchar), "Ground_sitting", "", "");
		break;

		case "The Lieutenant Arrives Back3":
			LAi_SetOfficerType(characterFromID("Lt. Percy Buckland"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_QuestDelay("The Lieutenant Arrives Back4", 5.0);
		break;

		case "The Lieutenant Arrives Back4":
			LAi_ActorAnimation((Pchar), "Ground_StandUp", "The Lieutenant Arrives Back5", 1.0);
		break;

		case "The Lieutenant Arrives Back5":
			LAi_SetPlayerType(pchar);

			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "Claytons_body";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"), pchar, "", 10.0, 10.0);
		break;

		case "A_Grim_Situation":
			characters[GetCharacterIndex("Jack Simpson")].Dialog.Filename = "Jack Simpson_dialog.c";
			LAi_SetActorType(characterFromID("Jack Simpson"));
			Characters[GetCharacterIndex("Jack Simpson")].dialog.CurrentNode = "lies_and_more_lies";
			LAi_ActorDialog(characterFromID("Jack Simpson"), pchar, "", 10.0, 10.0);
		break;

		case "Bush_back_to_the_ship":
			AddQuestRecord("My First Ship", 12);
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "Let_the_Captain_decide";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"), pchar, "", 1.0, 1.0);
		break;

		case "Off_to_Redmond_Clayton_dead":
			LAi_SetOfficerType(characterFromID("Lt. Percy Buckland"));
			LAi_SetOfficerType(characterFromID("Jack Simpson"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));

			pchar.quest.My_new_Orders.win_condition.l1 = "location";
			pchar.quest.My_new_Orders.win_condition.l1.location = "Redmond_port";
			pchar.quest.My_new_Orders.win_condition = "My_new_Orders";
		break;

		case "My_new_orders":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"HMS_Indefatigable","Indefatigable",-1,ENGLAND,true,true);
			pchar.quest.My_First_ship = "meet the captain";
			SetCharacterRemovable(characterFromID("Jack Simpson"), true);
			SetCharacterRemovable(characterFromID("Archie Kennedy"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Jack Simpson"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Archie Kennedy"));
			ChangeCharacterAddress(characterFromID("Matthews"), "None", "");
			ChangeCharacterAddress(characterFromID("Styles"), "None", "");

			ChangeCharacterAddressGroup(characterFromID("Captain Keene"), "Redmond_port", "officers", "sea_1_1");
			LAi_SetActorType(characterFromID("Captain Keene"));
			LAi_ActorTurnToCharacter(characterFromID("Captain Keene"), pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Captain Keene"));
			Lai_ActorFollow(characterFromID("Captain Keene"), pchar, "My_new_Orders2", 3.0);
		break;

		case "My_new_Orders2":
			characters[GetCharacterIndex("Captain Keene")].Dialog.Filename = "Captain Keene_dialog.c";
			LAi_SetActorType(characterFromID("Captain Keene"));
			LAi_ActorDialogNow(characterFromID("Captain Keene"),PChar,"",1.0);
			Characters[GetCharacterIndex("Captain Keene")].dialog.currentnode = "First time";
		break;

		case "Leave_the_ship_Justinian":
			AddQuestRecord("My First Ship",1);
			LAi_ActorGoToLocator(characterFromID("Captain Keene"), "goto", "goto_41", "Board_the_ship_Indefatigable", 5.0);
		break;

		case "Board_the_ship_Indefatigable":
			LAi_Fade("", "");
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddress(characterFromID("Captain Keene"), "None", "");
			ChangeCharacterAddress(characterFromID("Ebenezer Bracegirdle"), "None", "");
			DoQuestReloadToLocation("Quest_ShipDeck6", "goto", "goto13", "talk_before_swordfight");
			LAi_SetActorType(characterFromID("Jack Simpson"));
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			LAi_SetActorType(characterFromID("Archie Kennedy"));
		break;

		case "talk_before_swordfight":
			Locations[FindLocation("Quest_ShipDeck6")].vcskip = true;
			ChangeCharacterAddressGroup(characterFromID("Lt. Percy Buckland"), "Quest_ShipDeck6", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Quest_ShipDeck6", "reload", "boatr");
			ChangeCharacterAddressGroup(characterFromID("Jack Simpson"), "Quest_ShipDeck6", "reload", "boatl");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Quest_ShipDeck6", "goto", "goto11");
			LAi_ActorTurnToCharacter(characterFromID("Jack Simpson"), pchar);
			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"), pchar);
			characters[GetCharacterIndex("Jack Simpson")].Dialog.Filename = "Jack Simpson_dialog.c";
			LAi_SetActorType(characterFromID("Jack Simpson"));
			Characters[GetCharacterIndex("Jack Simpson")].dialog.CurrentNode = "First_orders";
			LAi_ActorDialog(characterFromID("Jack Simpson"), pchar, "", 10.0, 10.0);
		break;

		case "Simpson_Swordfight":
			LAi_SetFightMode(PChar, true);
			LAi_SetImmortal(Pchar, true);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetImmortal(characterFromID("Jack Simpson"), true);

			LAi_ActorAttack(characterfromID("Jack Simpson"), pchar, "");
			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"), pchar);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "First_orders";
			LAi_ActorDialogNow(characterFromID("Archie Kennedy"), pchar, "Simpson_Swordfight2", -1);
			LAi_QuestDelay("Simpson_Swordfight2", 6.0);
		break;

		case "Simpson_Swordfight2":
			LAi_SetActorType(characterFromID("Jack Simpson"));
			LAi_SetFightMode(characterFromID("Jack Simpson"), false);
			LAi_QuestDelay("Simpson_Swordfight3", 0.0);
			PlaySound("OBJECTS\shipcharge\Eng_the_side.wav");
		break;

		case "Simpson_Swordfight3":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			LAi_SetFightMode(characterFromID("Jack Simpson"), false);
			LAi_SetFightMode(PChar, false);
			SetCharacterRelationBoth(GetCharacterIndex("Jack Simpson"), GetMainCharacterIndex(), RELATION_FRIEND);
			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"), pchar);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "First_orders";
			LAi_ActorDialogNow(characterFromID("Archie Kennedy"), pchar, "", -1);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "interupt fight";
		break;

		case "The Captain Arrives":
			LAi_ActorTurnToCharacter(characterFromID("Sir Edward Pellew"), pchar);
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));	
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "interupt fight";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 10.0, 10.0);
		break;

		case "Our First venture":
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			AddPassenger(Pchar, characterFromID("Sir Edward Pellew"), 0);
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), false);
			LAi_SetImmortal(characterFromID("Jack Simpson"), false);
			LAi_SetImmortal(Pchar, false);
			LAi_QuestDelay("take over the ship", 0.0);
		break;

		case "take over the ship":
			LAi_ActorGoToLocator(characterFromID("Lt. Percy Buckland"), "goto", "goto2", "", 10.0);
			LAi_SetActorType(characterFromID("Jack Simpson"));
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));

			LAi_QuestDelay("take over the ship2", 0.0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
		break;

		case "take over the ship2":
			LAi_ActorGoToLocator(characterFromID("Sir Edward Pellew"), "goto", "goto3", "", 5.0);
			LAi_ActorGoToLocator(characterFromID("Jack Simpson"), "goto", "goto3", "take over the ship3", 5.0);
			setCharacterShipLocation(pchar, "Redmond_port");
		break;

		case "take over the ship3":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Sir Edward Pellew"));
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), false);
			ChangeCharacterAddress(characterFromID("Sir Edward Pellew"), "None", "");
			ChangeCharacterAddress(characterFromID("Jack Simpson"), "None", "");

			LAi_ActorTurnToCharacter(characterFromID("Lt. Percy Buckland"), pchar);
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "Course Settings";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"), pchar, "", 10.0, 10.0);
		break;

		case "Meet_Archie_Kennedy":
			LAi_SetPlayerType(PChar);
			LAi_ActorGoToLocator(characterFromID("Lt. Percy Buckland"), "goto", "goto3", "", 5.0);
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "Jamaica Port";
			LAi_ActorDialog(characterFromID("Archie Kennedy"), pchar, "", 10.0, 10.0);
		break;

		case "take over the ship4":
			Locations[FindLocation("Quest_ShipDeck6")].vcskip = false;
			AddQuestRecord("My First Ship", 2);
			ChangeCharacterAddress(characterFromID("Lt. Percy Buckland"), "None", "");
			ChangeCharacterAddress(characterFromID("Archie Kennedy"), "None", "");
			QuestToSeaLogin_PrepareLoc("Redmond", "reload", "reload_2", false);
			QuestToSeaLogin_Launch();

			SetCharacterRemovable(characterFromID("Jack Simpson"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Jack Simpson"));
			RemovePassenger(pchar, characterFromID("Jack Simpson"));

			Pchar.quest.arrive_Charlestown.win_condition.l1 = "location";
			PChar.quest.arrive_Charlestown.win_condition.l1.character = Pchar.id;
			Pchar.quest.arrive_Charlestown.win_condition.l1.location = "Charlestown_port";
			Pchar.quest.arrive_Charlestown.win_condition = "arrive_Charlestown";

			Pchar.quest.done_a_runner.win_condition.l1 = "location";
			PChar.quest.done_a_runner.win_condition.l1.character = Pchar.id;
			Pchar.quest.done_a_runner.win_condition.l1.location = "Redmond_port";
			Pchar.quest.done_a_runner.win_condition = "done_a_runner";
		break;
// If player deserts ship at this point:
		case "done_a_runner":
			DisableFastTravel(true);
			Pchar.Quest.arrive_Charlestown.over = "yes";
			pchar.quest.My_First_ship = "done a runner";
			LAi_ActorTurnToCharacter(characterFromID("Sir Edward Pellew"), pchar);
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));	
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "youre_a_deserter";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 10.0, 10.0);
		break;

		case "Deserters Jail":
			DoQuestReloadToLocation("Redmond_prison", "goto", "goto9", "_");
		break;

		case "hung at dawn":
			pchar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "mutiny");
		break;
// End of desertion scene - and also end of game.
		case "arrive_Charlestown":
			Locations[FindLocation("Charlestown_port")].reload.l15.disable = 1;
			Pchar.Quest.done_a_runner.over = "yes";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			Locations[FindLocation("Charlestown_port")].vcskip = true;
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Sir Edward Pellew"));
			RemovePassenger(pchar, characterFromID("Sir Edward Pellew"));
			LAi_SetActorType(PChar);
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Charlestown_port", "officers", "houseS3_2");
			LAi_ActorGoToLocator((Pchar), "officers", "reload1_2", "arrive_Charlestown2", 10);
		break;

		case "arrive_Charlestown2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "got_to_Charlestown";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 10.0, 10.0);
		break;

		case "reprovision_Charlestown":
			DisableFastTravel(false);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.currentnode = "First time";
			LAi_ActorGoToLocator(characterFromID("Sir Edward Pellew"), "reload", "reload10_1", "", 0.0); //"reprovision_Charlestown2", 0.0);
			AddQuestRecord("My First Ship", 3);

			Pchar.quest.reprovision_Charlestown2.win_condition.l1 = "location";
			PChar.quest.reprovision_Charlestown2.win_condition.l1.character = Pchar.id;
			Pchar.quest.reprovision_Charlestown2.win_condition.l1.location = "Charlestown_store";
			Pchar.quest.reprovision_Charlestown2.win_condition = "reprovision_Charlestown2";
		break;

		case "reprovision_Charlestown2":
			ChangeCharacterAddress(characterFromID("Sir Edward Pellew"), "None", "");
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Sir Edward Pellew"));
			ChangeCharacterAddressGroup(characterFromID("Lt. Percy Buckland"), "Charlestown_port", "goto", "goto18");
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			Pchar.quest.Train_up_the_crew.win_condition.l1 = "location";
			PChar.quest.Train_up_the_crew.win_condition.l1.character = Pchar.id;
			Pchar.quest.Train_up_the_crew.win_condition.l1.location = "Charlestown_port";
			Pchar.quest.Train_up_the_crew.win_condition = "Train_up_the_crew";
		break;

		case "Train_up_the_crew":
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "Sail_round_the_island";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"), pchar, "", 10.0, 10.0);
		break;

		case "Bush_and_me_to_sea":
			Locations[FindLocation("Charlestown_port")].vcskip = false;
			AddQuestRecord("My First Ship", 7);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. Percy Buckland"));
			SetCharacterRemovable(characterFromID("Lt. Percy Buckland"), false);
			Locations[FindLocation("Greenford_town")].reload.l20.disable = 1;

			Pchar.quest.go_back_for_Pellew.win_condition.l1 = "location";
			PChar.quest.go_back_for_Pellew.win_condition.l1.character = Pchar.id;
			Pchar.quest.go_back_for_Pellew.win_condition.l1.location = "Greenford_port";
			Pchar.quest.go_back_for_Pellew.win_condition = "Collect_new_officers";
		break;

		case "Collect_new_officers":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}

			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "Find_the_Naval_Station";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"), pchar, "", 10.0, 10.0);
		break;

		case "Collect_new_officers2":
			LAi_ActorGoToLocator(characterFromID("Lt. Percy Buckland"), "reload", "reload1_back", "Continue_for_officers", 1.0);
		break;

		case "Continue_for_officers":
			ChangeCharacterAddress(characterFromID("Lt. Percy Buckland"), "None", "");
			SetCharacterRemovable(characterFromID("Lt. Percy Buckland"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. Percy Buckland"));
			RemovePassenger(pchar, characterFromID("Lt. Percy Buckland"));

			Pchar.quest.Collect_new_officers3.win_condition.l1 = "location";
			PChar.quest.Collect_new_officers3.win_condition.l1.character = Pchar.id;
			Pchar.quest.Collect_new_officers3.win_condition.l1.location = "Greenford Naval HQ";
			Pchar.quest.Collect_new_officers3.win_condition = "Collect_new_officers3";
		break;

		case "Collect_new_officers3":
			ChangeCharacterAddressGroup(characterFromID("Lt. Chadd"), "Greenford Naval HQ", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Ebenezer Bracegirdle"), "Greenford Naval HQ", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Greenford Naval HQ", "goto", "goto4");
			LAi_QuestDelay("Go_on_in", 3.0);
		break;

		case "Go_on_in":
			characters[GetCharacterIndex("Lt. Chadd")].Dialog.Filename = "Lt. Chadd_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Chadd"));
			Characters[GetCharacterIndex("Lt. Chadd")].dialog.CurrentNode = "First_meeting_Greenford";
			LAi_ActorDialog(characterFromID("Lt. Chadd"), pchar, "", 10.0, 10.0);
		break;

		case "Collect_new_officers4":
			LAi_QuestDelay("Collect_new_officers5", 3.0);
		break;

		case "Collect_new_officers5":
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "First_meeting_Greenford";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"), pchar, "", 10.0, 10.0);
		break;

		case "And_now_meet_Bracegirdle":
			LAi_SetActorType(characterFromID("Ebenezer Bracegirdle"));

			characters[GetCharacterIndex("Ebenezer Bracegirdle")].Dialog.Filename = "Lieutenant Bracegirdle_dialog.c";
			LAi_SetActorType(characterFromID("Ebenezer Bracegirdle"));
			Characters[GetCharacterIndex("Ebenezer Bracegirdle")].dialog.CurrentNode = "First_meeting_Greenford";
			LAi_ActorDialog(characterFromID("Ebenezer Bracegirdle"), pchar, "", 10.0, 10.0);
		break;

		case "go_back_for_Pellew":
			AddCharacterGoods(pchar, GOOD_RUM, 44);
			AddCharacterGoods(pchar, GOOD_WHEAT, 86);
			Characters[GetCharacterIndex("Ebenezer Bracegirdle")].dialog.CurrentNode = "First time";
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Lt. Uriah Quelp"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Ebenezer Bracegirdle"));
			SetCharacterRemovable(characterFromID("Lt. Uriah Quelp"), false);
			SetCharacterRemovable(characterFromID("Ebenezer Bracegirdle"), false);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}

			ChangeCharacterAddress(characterFromID("Lt. Percy Buckland"), "None", "");
			AddQuestRecord("My First Ship", 11);

			Pchar.quest.Broken_Quest.win_condition.l1 = "NPC_death";
			Pchar.quest.Broken_Quest.win_condition.l1.character = "Ebenezer Bracegirdle";
			Pchar.quest.Broken_Quest.win_condition = "Broken_Quest";

			Pchar.quest.Broken_QuestA.win_condition.l1 = "NPC_death";
			Pchar.quest.Broken_QuestA.win_condition.l1.character = "Lt. Uriah Quelp";
			Pchar.quest.Broken_QuestA.win_condition = "Broken_Quest";

			Pchar.quest.War_with_France.win_condition.l1 = "location";
			PChar.quest.War_with_France.win_condition.l1.character = Pchar.id;
			Pchar.quest.War_with_France.win_condition.l1.location = "Charlestown_port";
			Pchar.quest.War_with_France.win_condition = "War_with_France";
		break;
// if Hornblower gets either of the officers killed - quest over
		case "Broken_Quest":
			Pchar.Quest.War_with_France.over = "yes";
			//Pchar.Quest.Broken_QuestA.over = "yes"; // PB: Does not exist
			Pchar.quest.Sawyer_in_Greenford.over = "yes"; 
			Locations[FindLocation("Greenford_port")].reload.l1.disable = 1;
			Locations[FindLocation("Greenford_port")].reload.l3.disable = 1;

			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"Tartane50","Happy Times", -1,ENGLAND,true,true);
			SetCrewQuantity(pchar, 3);
			AddCharacterGoods(pchar, GOOD_RUM, 2);
			AddCharacterGoods(pchar, GOOD_WHEAT, 4);
			setCharacterShipLocation(Pchar, "Greenford_port");

			ChangeCharacterAddressGroup(characterFromID("Dreadnought Foster"), "Greenford_town", "goto", "goto25");
			LAi_SetOfficerType(characterFromID("Dreadnought Foster"));

			Pchar.quest.Out_of_the_Navy.win_condition.l1 = "location";
			PChar.quest.Out_of_the_Navy.win_condition.l1.character = Pchar.id;
			Pchar.quest.Out_of_the_Navy.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Out_of_the_Navy.win_condition = "Out_of_the_Navy";
		break;

		case "Out_of_the_Navy":
			characters[GetCharacterIndex("Dreadnought Foster")].Dialog.Filename = "Dreadnought Foster_dialog.c";
			LAi_SetActorType(characterFromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Cashiered";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 10.0, 10.0);
		break;

		case "No_Longer_in_the_Navy":
			pchar.quest.Players_Rank = "Civilian";
			SetRank(pchar, ENGLAND, 1);
			GiveModel2Player("CivilianHB", true);
			LeaveService(PChar, ENGLAND, false);
		break;
// end quest over
		case "War_with_France":
			SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_ENEMY);
			SetNationRelationBoth(PORTUGAL, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(PORTUGAL, SPAIN, RELATION_ENEMY);
			SetNationRelationBoth(PORTUGAL, HOLLAND, RELATION_ENEMY);
			SetNationRelationBoth(AMERICA, FRANCE, RELATION_ENEMY);
			SetRMRelation(PChar, FRANCE, REL_WAR);
			SetRMRelation(PChar, SPAIN, REL_WAR);
			SetRMRelation(PChar, HOLLAND, REL_WAR);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. Uriah Quelp"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Ebenezer Bracegirdle"));

			Pchar.Quest.Broken_Quest.over = "yes"; // GR: Bracegirdle is now safe so cancel check for his death
			Pchar.Quest.Broken_QuestA.over = "yes"; // GR: Cancel check on Quelp too

			LAi_SetActorType(PChar);
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Charlestown_port", "goto", "goto25");
			LAi_ActorGoToLocator((Pchar), "officers", "reload1_2", "War_with_France2", 10);
		break;

		case "War_with_France2":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "message of war";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 10.0, 10.0);
		break;

		case "At_War_with_France_Again":
			AddQuestRecord("My First Ship", 4);
			AddPassenger(Pchar, characterFromID("Sir Edward Pellew"), 0);
			LAi_SetOfficerType(characterFromID("Sir Edward Pellew"));
			LAi_SetImmortal(characterFromID("Sir Edward Pellew"), true);
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), false);

			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Captain Keene"));
			SetCharacterRemovable(characterFromID("Captain Keene"), false);

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			Locations[FindLocation("Charlestown_port")].reload.l1.disable = 0;

			Pchar.quest.French_Battle_Setup.win_condition.l1 = "location";
			Pchar.quest.French_Battle_Setup.win_condition.l1.location = "FalaiseDeFleur";
			Pchar.quest.French_Battle_Setup.win_condition = "French_Battle_Setup";

			Pchar.quest.Rally_the_crew.win_condition.l1 = "location";
			Pchar.quest.Rally_the_crew.win_condition.l1.location = "QuebradasCostillas";
			Pchar.quest.Rally_the_crew.win_condition = "Rally_the_crew";
		break;

		case "Rally_the_crew":
			PostVideoAndQuest("Hornblower\Declaration of War",100, "");
		break;

		case "French_Battle_Setup":
			SetCurrentTime(10.00, 0);
			SetNextWeather("Blue Sky");
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");

			Group_CreateGroup("French_Squadron");
			Group_AddCharacter("French_Squadron", "Quest_frigate_captain");
			Group_SetGroupCommander("French_Squadron", "Quest_frigate_captain");
			Group_SetPursuitGroup("French Squadron", PLAYER_GROUP);
			Group_SetTaskAttack("French_Squadron",  PLAYER_GROUP, true);
			Group_LockTask("French_Squadron");
			Group_SetAddress("French_Squadron", "FalaiseDeFleur", "Quest_ships", "Quest_Ship_12"); 
			Sea_LoginGroupNow("French_Squadron");
			characters[GetCharacterIndex("Quest_frigate_captain")].nosurrender = 2;
			SetCharacterRelationBoth(GetCharacterIndex("Quest_frigate_captain"),GetMainCharacterIndex(),RELATION_ENEMY);
			if(GetRMRelation(Pchar, PIRATE) > REL_WAR) SetRMRelation(Pchar, PIRATE, REL_WAR);
			Character_SetAbordageEnable(characterFromID("Quest_frigate_captain"), false);

			if(GetRMRelation(Pchar, FRANCE) > REL_WAR) SetRMRelation(Pchar, FRANCE, REL_WAR);
			UpdateRelations();

			Pchar.quest.FrenchShipDestroyed.win_condition.l1 = "NPC_death";
			Pchar.quest.FrenchShipDestroyed.win_condition.l1.character = "Quest_frigate_captain";
			Pchar.quest.FrenchShipDestroyed.win_condition = "FrenchShipDestroyed";
		break;

		case "FrenchShipDestroyed":
			CloseQuestHeader("My First Ship");
			SetQuestHeader("Battle Bloodied");
			AddQuestRecord("Battle Bloodied", 1);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 3000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 3000);}

			SetCharacterRemovable(characterFromID("Captain Keene"), true);
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));

			Pchar.quest.Arrival_at_Charletown_after_battle.win_condition.l1 = "location";
			PChar.quest.Arrival_at_Charletown_after_battle.win_condition.l1.character = Pchar.id;
			Pchar.quest.Arrival_at_Charletown_after_battle.win_condition.l1.location = "Charlestown_port";
			Pchar.quest.Arrival_at_Charletown_after_battle.win_condition = "Arrival_at_Charletown_after_battle";
		break;

		case "Arrival_at_Charletown_after_battle":
			SetCharacterRemovable(characterFromID("Lt. Uriah Quelp"), true);
			SetCharacterRemovable(characterFromID("Ebenezer Bracegirdle"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. Uriah Quelp"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Ebenezer Bracegirdle"));
			RemovePassenger(pchar, characterFromID("Lt. Uriah Quelp"));
			RemovePassenger(pchar, characterFromID("Ebenezer Bracegirdle"));

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			LAi_SetActorType(PChar);
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Charlestown_port", "goto", "goto25");
			LAi_ActorGoToLocator((Pchar), "officers", "reload1_2", "After_first_battle", 10);
		break;

		case "After_first_battle":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Go_to_the_Naval_Academy";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 10.0, 10.0);
		break;

		case "Off_to_the_Academy_meeting":
			SetCharacterRemovable(characterFromID("Jack Simpson"), true);
			RemoveCharacterCompanion(Pchar, characterFromID("Jack Simpson"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Jack Simpson"));
			LAi_ActorGoToLocator(characterFromID("Sir Edward Pellew"), "reload", "reload10_1", "Inside_for_debrief", 35.0);
		break;

		case "Inside_for_debrief":
			ChangeCharacterAddress(characterFromID("Sir Edward Pellew"), "None", "");

			Pchar.quest.Inside_for_debrief2.win_condition.l1 = "location";
			PChar.quest.Inside_for_debrief2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Inside_for_debrief2.win_condition.l1.location = "Charlestown_Academy";
			Pchar.quest.Inside_for_debrief2.win_condition = "Inside_for_debrief2";
		break;

		case "Inside_for_debrief2":
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), true);
			RemoveCharacterCompanion(Pchar, characterFromID("Sir Edward Pellew"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Sir Edward Pellew"));
			SetCharacterRemovable(characterFromID("Ebenezer Bracegirdle"), true);
			RemoveCharacterCompanion(Pchar, characterFromID("Ebenezer Bracegirdle"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Ebenezer Bracegirdle"));

			ChangeCharacterAddressGroup(characterFromID("Jack Simpson"), "Charlestown_Academy", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Captain James Sawyer"), "Charlestown_Academy", "sit", "sit1");
			LAi_ActorSetSitMode(characterFromID("Captain James Sawyer"));
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Charlestown_Academy", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Ebenezer Bracegirdle"), "Charlestown_Academy", "goto", "goto3");
			LAi_QuestDelay("Fight_in_private_room", 0.0);
		break;

		case "Fight_in_private_room":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto1", "Fight_in_private_room2", 8);

			DisableFastTravel(true);
			LAi_SetCivilianGuardianType(characterFromID("Sir Edward Pellew"));
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_SetActorType(characterFromID("Jack Simpson"));
			LAi_SetActorType(characterFromID("Ebenezer Bracegirdle"));
		break;

		case "Fight_in_private_room2":
			LAi_SetPlayerType(PChar);
			LAi_ActorTurnToCharacter(characterFromID("Sir Edward Pellew"), characterFromID("Captain James Sawyer"));
			LAi_ActorTurnToCharacter(characterFromID("Ebenezer Bracegirdle"), characterFromID("Captain James Sawyer"));
			LAi_ActorTurnToCharacter(characterFromID("Jack Simpson"), pchar);
			LAi_QuestDelay("Fight_in_private_room3", 0.0);
		break;

		case "Fight_in_private_room3":
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.CurrentNode = "got_to_Oxbay_for_refit";
			LAi_ActorDialog(characterFromID("Captain James Sawyer"), pchar, "", 1.0, 1.0);
		break;

		case "Pellew buts in":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));

			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "report on the attack";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;

		case "discussion continues":
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.CurrentNode = "Simpson_rummor";
			LAi_ActorDialog(characterFromID("Captain James Sawyer"), pchar, "", 1.0, 1.0);
		break;

		case "Pellew_upstairs_Again":
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "first_promotion";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;

		case "ready_the_fight":
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.CurrentNode = "Simpson_challenged";
			LAi_ActorDialog(characterFromID("Captain James Sawyer"), pchar, "", 1.0, 1.0);
		break;

		case "the_fight_starts":
			LAi_SetActorType(characterFromID("Jack Simpson"));
			Characters[GetCharacterIndex("Jack Simpson")].dialog.CurrentNode = "Attack_Hornblower";
			LAi_ActorDialog(characterFromID("Jack Simpson"), pchar, "", 1.0, 1.0);
		break;

		case "Upstairs_room_fight":
			LAi_SetImmortal(characterFromID("Jack Simpson"), false);
			LAi_SetFightMode(PChar, true);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_ActorAttack(characterfromID("Jack Simpson"), pchar, "");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";

			Pchar.quest.Upstairs_fight_over.win_condition.l1 = "NPC_death";
			Pchar.quest.Upstairs_fight_over.win_condition.l1.character = "Jack Simpson";
			Pchar.quest.Upstairs_fight_over.win_condition = "Upstairs_fight_over";
		break;

		case "Upstairs_fight_over":
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.CurrentNode = "Simpson_dead";
			LAi_ActorDialog(characterFromID("Captain James Sawyer"), pchar, "", 1.0, 1.0);
		break;

		case "the_future_begins":
			LAi_SetActorType(characterFromID("Ebenezer Bracegirdle"));
			Characters[GetCharacterIndex("Ebenezer Bracegirdle")].dialog.CurrentNode = "dispose_of_the_body";
			LAi_ActorDialog(characterFromID("Ebenezer Bracegirdle"), pchar, "", 0.0, 0.0);
		break;

		case "Bush_Leaves_Upstairs":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(characterFromID("Ebenezer Bracegirdle"), "reload", "reload1", "", 0.0); //"Bush_Leaves_Upstairs2", 0.0);
			LAi_QuestDelay("Bush_Leaves_Upstairs2", 3.0);
		break;

		case "Bush_Leaves_Upstairs2":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddress(characterFromID("Ebenezer Bracegirdle"), "None", "");
			LAi_QuestDelay("Promotion_and_a_ship", 0.0);
		break;

		case "Promotion_and_a_ship":
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.CurrentNode = "Simpson_death_explained";
			LAi_ActorDialog(characterFromID("Captain James Sawyer"), pchar, "", 1.0, 1.0);
		break;

		case "Promotion_and_a_ship2":
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "explanation";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;

		case "prepare_for_French_siege":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			AddQuestRecord("Battle Bloodied", 2);
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Charlestown_port", "goto", "goto7");

			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Sir Edward Pellew"));
			RemovePassenger(pchar, characterFromID("Sir Edward Pellew"));
			SetCharacterRemovable(characterFromID("Ebenezer Bracegirdle"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Ebenezer Bracegirdle"));
			RemovePassenger(pchar, characterFromID("Ebenezer Bracegirdle"));

			Pchar.quest.Upstairs_meeting_over.win_condition.l1 = "location";
			Pchar.quest.Upstairs_meeting_over.win_condition.l1.character = Pchar.id;
			Pchar.quest.Upstairs_meeting_over.win_condition.l1.location = "Charlestown_port";
			Pchar.quest.Upstairs_meeting_over.win_condition = "Upstairs_meeting_over";
		break;

		case "Upstairs_meeting_over":
			DisableFastTravel(false);
			pchar.quest.Players_Rank = "Lieutenant";
			SetRank(pchar, ENGLAND, 2); // PB: 3rd Lieutenant
			GiveModel2Player("brtH3rdLt_18", true);
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"Tartane50","Jolly Boat",-1,ENGLAND,true,true);
			SetCrewQuantity(pchar, 3);
			AddCharacterGoods(pchar, GOOD_RUM, 2);
			AddCharacterGoods(pchar, GOOD_WHEAT, 4);

			setCharacterShipLocation(characterFromID("Sir Edward Pellew"), "Antigua_port");
			setCharacterShipLocation(characterFromID("Captain James Sawyer"), "Antigua_port");
			SetCharacterShipLocation(Pchar, "Charlestown_port");
			ChangeCharacterAddress(characterFromID("Sir Edward Pellew"), "None", "");
			ChangeCharacterAddress(characterFromID("Jack Simpson"), "None", "");
			ChangeCharacterAddress(characterFromID("Captain James Sawyer"), "None", "");

			RemoveCharacterCompanion(Pchar, characterFromID("Sir Edward Pellew"));
			RemovePassenger(pchar, characterFromID("Sir Edward Pellew"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Sir Edward Pellew"));
			RemoveCharacterCompanion(Pchar, characterFromID("Ebenezer Bracegirdle"));
			RemovePassenger(pchar, characterFromID("Ebenezer Bracegirdle"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Ebenezer Bracegirdle"));

			SetOfficersIndex(Pchar, 2, getCharacterIndex("Archie Kennedy"));
			SetCharacterRemovable(characterFromID("Archie Kennedy"), false);
			LAi_SetActorType(characterFromID("Archie Kennedy"));

			LAi_QuestDelay("Goodbye_Archie_Charlestown", 0.0);
		break;

		case "Goodbye_Archie_Charlestown":
			DisableFastTravel(true);
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialogNow(Pchar, characterFromID("Archie Kennedy"), "", -1);
			LAi_ActorDialog(characterFromID("Archie Kennedy"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "Greenford Port";
		break;

		case "Go_find_Hunter":
			LAi_Fade("", "");

			SetCharacterRemovable(characterFromID("Archie Kennedy"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Archie Kennedy"));
			RemoveCharacterCompanion(pchar, characterFromID("Archie Kennedy"));
			RemovePassenger(pchar, characterFromID("Archie Kennedy"));

			DoQuestReloadToLocation("Charlestown_tavern_upstairs", "goto", "goto4", "Go_find_Hunter2");
		break;
// CAPTURE OF LE REVE
		case "Go_find_Hunter2":
			LAi_SetActorType(pchar);
			Pchar.dialog.currentnode = "wakeaftersleep";
			LAi_QuestDelay("Go_find_Hunter2X", 0.0);
		break;

		case "Go_find_Hunter2X":
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "wakeaftersleep";
			LAi_ActorSelfDialog(Pchar, "Go_find_Hunter3");
			LAi_SetPlayerType(pchar);
		break;

		case "Go_find_Hunter3":
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.CurrentNode = "our_first_meeting";
			ChangeCharacterAddress(characterFromID("Archie Kennedy"), "None", "");

			Pchar.quest.Hunter_found.win_condition.l1 = "location";
			Pchar.quest.Hunter_found.win_condition.l1.character = Pchar.id;
			Pchar.quest.Hunter_found.win_condition.l1.location = "Charlestown_tavern";
			Pchar.quest.Hunter_found.win_condition = "Hunter_found";
		break;

		case "Hunter_found":
			ChangeCharacterAddressGroup(characterFromID("Midshipman Hunter"), "Charlestown_tavern", "goto", "goto2");
			LAi_SetCivilianGuardianType(characterFromID("Midshipman Hunter"));
			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_ActorDialog(characterFromID("Midshipman Hunter"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.CurrentNode = "our_first_meeting";
		break;

		case "Off_to_the_Mystery_House":
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Midshipman Hunter"));
			SetCharacterRemovable(characterFromID("Midshipman Hunter"), false);
			LAi_SetOfficerType(characterFromID("Midshipman Hunter"));

			Pchar.quest.Off_to_the_Mystery_House2.win_condition.l1 = "location";
			Pchar.quest.Off_to_the_Mystery_House2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Off_to_the_Mystery_House2.win_condition.l1.location = "Charlestown_port";
			Pchar.quest.Off_to_the_Mystery_House2.win_condition = "Off_to_the_Mystery_House2";
		break;

		case "Off_to_the_Mystery_House2":
			LAi_QuestDelay("Off_to_the_Mystery_House2A", 1.0);
		break;

		case "Off_to_the_Mystery_House2A":
			CreateParticleSystemX("blast_inv", 116.4, 1.5766, -141.82, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 116.4, 1.5766, -141.82, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 116.4, 1.5766, -141.82, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("Off_to_the_Mystery_House3", 0.0);
		break;

		case "Off_to_the_Mystery_House3":
			WriteLocatorGlobal("Charlestown_port", "fire", "fire1", "", -1, 116.21, 1.5753, -140.46, false);
			Locations[FindLocation("Charlestown_port")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Charlestown_port")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 116.21, 1.5753, -140.46, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("Off_to_the_Mystery_House4", 2.0);
		break;

		case "Off_to_the_Mystery_House4":
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_ActorDialog(characterFromID("Midshipman Hunter"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.CurrentNode = "the_French_shell";
		break;

		case "Off_to_the_Mystery_House5":
			LAi_SetOfficerType(characterFromID("Midshipman Hunter"));
			CloseQuestHeader("Battle Bloodied");
			SetQuestHeader("Tunnel of Trouble");
			AddQuestRecord("Tunnel of Trouble", 1);
			Locations[FindLocation("Charlestown_port")].reload.l15.disable = 0;

			pchar.quest.Killed_at_Charlestown.win_condition.l1 = "locator";
			pchar.quest.Killed_at_Charlestown.win_condition.l1.location = "Charlestown_port";
			pchar.quest.Killed_at_Charlestown.win_condition.l1.locator_group = "goto";
			pchar.quest.Killed_at_Charlestown.win_condition.l1.locator = "goto30";
			pchar.quest.Killed_at_Charlestown.win_condition = "Killed_at_Charlestown";

			Pchar.quest.The_Mystery_House.win_condition.l1 = "location";
			Pchar.quest.The_Mystery_House.win_condition.l1.character = Pchar.id;
			Pchar.quest.The_Mystery_House.win_condition.l1.location = "Mystery_House";
			Pchar.quest.The_Mystery_House.win_condition = "The_Mystery_House";
		break;
//TRAP for going wrong way to Mystery House
		case "Killed_at_Charlestown":
			Pchar.Quest.The_Mystery_House.over = "yes";
			LAi_SetActorType(pchar);
			WriteLocatorGlobal("Charlestown_port", "fire", "fire2", "", -1, 90.519, 1.5425, -153.6, false);
			Locations[FindLocation("Charlestown_port")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Charlestown_port")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 90.519, 1.5425, -153.6, -1.57, 0.0, 0.0,0);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("Killed_at_Charlestown2", 1.0);
		break;

		case "Killed_at_Charlestown2":
			CreateParticleSystemX("blast_inv", 90.519, 1.5425, -153.6, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 90.519, 1.5425, -153.6, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 90.519, 1.5425, -153.6, -1.57, 0.0, 0.0,20);

			WriteLocatorGlobal("Charlestown_port", "fire", "fire3", "", -1, 97.805, 1.5984, -152.8, false);
			Locations[FindLocation("Charlestown_port")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Charlestown_port")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 97.805, 1.5984, -152.8, -1.57, 0.0, 0.0,0);

			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("Killed_at_Charlestown3", 1.0);
		break;

		case "Killed_at_Charlestown3":
			CreateParticleSystemX("blast_inv", 97.805, 1.5984, -152.8, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 97.805, 1.5984, -152.8, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 97.805, 1.5984, -152.8, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("Killed_at_Charlestown4", 1.0);
		break;

		case "Killed_at_Charlestown4":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("blast_inv", 111.08, 1.582, -150.31, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 111.08, 1.582, -150.31, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 111.08, 1.582, -150.31, -1.57, 0.0, 0.0,20);
			Lai_KillCharacter(Pchar);
			Lai_KillCharacter(characterFromID("Midshipman Hunter"));
			LAi_QuestDelay("KilledFighting", 5.0);
		break;
// GAME OVER - Player Killed ^^^
		case "The_Mystery_House":
			Pchar.Quest.Killed_at_Charlestown.over = "yes";
			SetCharacterShipLocation(Pchar, "QC_Shore1");

			Locations[FindLocation("Mystery_House")].vcskip = true;
			ChangeCharacterAddressGroup(characterFromID("Smug Larr"), "Mystery_House", "sit", "sit1");
			LAi_SetSitType(characterFromID("Smug Larr"));
			ChangeCharacterAddressGroup(characterFromID("Big Bryan"), "Mystery_House", "reload", "reload3");
			Characters[GetCharacterIndex("Smug Larr")].dialog.CurrentNode = "our_first_meeting";
		break;

		case "Beach_for_French_ship":
			LAi_SetActorType(characterFromID("Big Bryan"));
			LAi_ActorGoToLocator(characterFromID("Big Bryan"), "goto", "guard", "", 0.0);
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"FR_Sloop","Le Rève",-1,FRANCE,true,true);
			SetCrewQuantity(pchar, 150);
			AddCharacterGoods(pchar, GOOD_BALLS, 500);
			AddCharacterGoods(pchar, GOOD_GRAPES, 300);
			AddCharacterGoods(pchar, GOOD_KNIPPELS, 200);
			AddCharacterGoods(pchar, GOOD_RUM, 10);
			AddCharacterGoods(pchar, GOOD_WHEAT, 20);

			Pchar.quest.Beach_for_French_ship2.win_condition.l1 = "location";
			Pchar.quest.Beach_for_French_ship2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beach_for_French_ship2.win_condition.l1.location = "QC_Shore1";
			Pchar.quest.Beach_for_French_ship2.win_condition = "Beach_for_French_ship2";
		break;

		case "Beach_for_French_ship2":
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "QC_Shore1", "officers", "reload2_1");
			LAi_QuestDelay("Beach_for_French_ship2A", 0.0);
		break;

		case "Beach_for_French_ship2A":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "shipview", "Beach_for_French_ship3", 3);
		break;

		case "Beach_for_French_ship3":
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_ActorDialog(characterFromID("Midshipman Hunter"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.CurrentNode = "See_the_French_ship";
		break;

		case "Spot_the_soldier":
			LAi_QuestDelay("Spot_the_soldier2", 3.0);
		break;

		case "Spot_the_soldier2":
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_ActorDialog(characterFromID("Midshipman Hunter"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.CurrentNode = "I_see_a_soldier";
		break;

		case "Talk_to_the_soldier":
			LAi_SetOfficerType(characterFromID("Midshipman Hunter"));

			LAi_SetCivilianGuardianType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "our_first_meeting";
		break;

		case "Capture_some_Frenchmen":
			Locations[FindLocation("QC_jungle_01")].vcskip = true;
			LAi_SetActorType(PChar);
			ChangeCharacterAddress(characterFromID("Midshipman Hunter"), "None", "");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "reload", "reload2_back", "Capture_some_Frenchmen1A", 5.0);

			ChangeCharacterAddressGroup(characterFromID("Treas_Pirate_3"), "QC_jungle_01", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Treas_Pirate_4"), "QC_jungle_01", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Treas_Pirate_1"), "QC_jungle_01", "goto", "goto8");
			ChangeCharacterAddressGroup(characterFromID("Treas_Pirate_2"), "QC_jungle_01", "officers", "reload2_3");

			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "QC_jungle_01", "goto", "goto17");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "QC_jungle_01", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "QC_jungle_01", "goto", "goto11");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "QC_jungle_01", "officers", "reload2_1");
		break;

		case "Capture_some_Frenchmen1A":
			DoQuestReloadToLocation("QC_jungle_01", "goto", "goto2", "Capture_some_Frenchmen2");
		break;

		case "Capture_some_Frenchmen2":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "QC_jungle_01", "goto", "goto1");

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "the_french_are_here";

		break;

		case "Capture_some_Frenchmen3":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "goto5", "Capture_some_Frenchmen4", 25.0);
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "goto", "mound1", "", 20.0);

			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Treas_Pirate_3"));
			LAi_SetActorType(characterFromID("Treas_Pirate_4"));
			LAi_SetActorType(characterFromID("Treas_Pirate_1"));
			LAi_SetActorType(characterFromID("Treas_Pirate_2"));
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_3"), "goto", "goto12", "", 8.0);
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_4"), "goto", "goto13", "", 8.0);
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_1"), "goto", "goto14", "", 8.0);
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_2"), "goto", "goto18", "", 8.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "goto", "goto7", "", 8.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "goto4", "", 8.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Cooper"), "goto", "goto15", "", 8.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Haggman"), "goto", "goto19", "", 8.0);
		break;

		case "Capture_some_Frenchmen4":
			LAi_QuestDelay("Capture_some_Frenchmen5", 3.0);
		break;

		case "Capture_some_Frenchmen5":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "a_quiet_catch";
		break;

		case "Now_take_the_ship":
			AddQuestRecord("Tunnel of Trouble", 2);
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Treas_Pirate_3"));
			LAi_SetActorType(characterFromID("Treas_Pirate_4"));
			LAi_SetActorType(characterFromID("Treas_Pirate_1"));
			LAi_SetActorType(characterFromID("Treas_Pirate_2"));
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_3"), "goto", "goto9", "", 20.0);
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_4"), "goto", "goto9", "", 20.0);
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_1"), "goto", "goto9", "", 20.0);
			LAi_ActorGoToLocator(characterFromID("Treas_Pirate_2"), "goto", "goto9", "", 20.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "goto", "goto10", "", 20.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "goto16", "", 20.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Cooper"), "goto", "goto3", "", 20.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Haggman"), "goto", "goto11", "", 20.0);

			Pchar.quest.Beach_for_French_ship2.win_condition.l1 = "location";
			Pchar.quest.Beach_for_French_ship2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beach_for_French_ship2.win_condition.l1.location = "QC_Shore1";
			Pchar.quest.Beach_for_French_ship2.win_condition = "Beach_for_French_ship_capture";
		break;

		case "Beach_for_French_ship_capture":
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			ChangeCharacterAddress(characterFromID("Treas_Pirate_3"), "None", "");
			ChangeCharacterAddress(characterFromID("Treas_Pirate_4"), "None", "");
			ChangeCharacterAddress(characterFromID("Treas_Pirate_1"), "None", "");
			ChangeCharacterAddress(characterFromID("Treas_Pirate_2"), "None", "");
			ChangeCharacterAddress(characterFromID("Richard Sharpe"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Midshipman Hunter"), "QC_Shore1", "goto", "citizen01");
			LAi_SetOfficerType(characterFromID("Midshipman Hunter"));
			LAi_QuestDelay("Beach_for_French_ship_capture2", 0.0);
		break;

		case "Beach_for_French_ship_capture2":
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_ActorDialog(characterFromID("Midshipman Hunter"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.CurrentNode = "Back_with_the_crew";
		break;

		case "Now_take_the_ship2":
			LAi_Fade("Now_take_the_ship3", "");
			setCharacterShipLocation(characterFromID("Sir Edward Pellew"), "QC_Shore1");
		break;

		case "Now_take_the_ship3":
			PostVideoAndQuest("Hornblower\Capture Le Reve", 100, "Back_to_the_Indy");
			bMainMenuLaunchAfterVideo = true;
		break;

		case "Back_to_the_Indy":
			PostEvent("DoInfoShower",100,"s","");

			DoQuestReloadToLocation("QC_Shore1", "goto", "shipview", "Explain_the_Capture");
		break;

		case "Explain_the_Capture":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "QC_Shore1", "goto", "locator27");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "QC_Shore1", "goto", "locator3");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "QC_Shore1", "goto", "locator5");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "QC_Shore1", "goto", "locator4");
			LAi_SetOfficerType(characterFromID("Rifleman Higgins"));
			LAi_SetOfficerType(characterFromID("Sir Edward Pellew"));
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			LAi_QuestDelay("Explain_the_Capture2", 0.0);
		break;

		case "Explain_the_Capture2":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Le_Reve_is_captured";
		break;
// TUNNEL STORY
		case "Quelp_cuts_in":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "We_should_attack";
		break;

		case "Pellew_stands_firm":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Waiting_for_wellesley";
		break;

		case "Soldier_speaks_up_on_tunnel":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			LAi_ActorGoToLocator(characterFromID("Lt. William Bush"), "goto", "locator10", "", 20.0);

			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			characters[GetCharacterIndex("Rifleman Higgins")].Dialog.Filename = "Rifleman Higgins_dialog.c";
			LAi_ActorDialog(characterFromID("Rifleman Higgins"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Rifleman Higgins")].dialog.CurrentNode = "Talk_of_Sharpe_and_Tunnel";
		break;

		case "Pellew_talks_tunnel":
			ChangeCharacterAddress(characterFromID("Lt. William Bush"), "None", "");
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "reload", "reload3", "", 20.0);
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "QC_Shore1", "goto", "locator10");
			ChangeCharacterAddressGroup(characterFromID("Lady Barbara Wellesley"), "QC_Shore1", "goto", "locator10");
			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));
			LAi_SetOfficerType(characterFromID("Lady Barbara Wellesley"));

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Pellew_and_Tunnel";
		break;

		case "Wellesley_cuts_in":
			Locations[FindLocation("QC_jungle_01")].vcskip = false;
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");

			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Pellew_Sharpe_and_Tunnel";
		break;

		case "Off_to_see_Larrs":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Wellesley_and_Tunnel";
		break;

		case "Wellesley_Pellew_Quelp_to_town":
			SetCharacterRemovable(characterFromID("Midshipman Hunter"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Midshipman Hunter"));
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Sir Edward Pellew"));
			LAi_SetOfficerType(characterFromID("Sir Edward Pellew"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Arthur Wellesley"));
			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Lt. Uriah Quelp"));
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), false);
			SetCharacterRemovable(characterFromID("Arthur Wellesley"), false);
			SetCharacterRemovable(characterFromID("Lt. Uriah Quelp"), false);

			LAi_SetOfficerType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorFollowEverywhere(CharacterFromID("Lady Barbara Wellesley"), "", 1.0);

			Pchar.quest.Return_Mystery_House.win_condition.l1 = "location";
			Pchar.quest.Return_Mystery_House.win_condition.l1.character = Pchar.id;
			Pchar.quest.Return_Mystery_House.win_condition.l1.location = "Mystery_House";
			Pchar.quest.Return_Mystery_House.win_condition = "Return_Mystery_House";
		break;

		case "Return_Mystery_House":
			LAi_SetActorType(characterFromID("Smug Larr"));
			LAi_type_actor_Reset(characterFromID("Smug Larr"));
			RemoveCharacterEquip(characterFromID("Smug Larr"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Smug Larr"), GUN_ITEM_TYPE);
			EnableEquip(characterFromID("Smug Larr"), BLADE_ITEM_TYPE, false);
			EnableEquip(characterFromID("Smug Larr"), GUN_ITEM_TYPE, false);
			RemoveCharacterEquip(characterFromID("Big Bryan"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Big Bryan"), GUN_ITEM_TYPE);
			EnableEquip(characterFromID("Big Bryan"), BLADE_ITEM_TYPE, false);
			EnableEquip(characterFromID("Big Bryan"), GUN_ITEM_TYPE, false);
			ChangeCharacterAddressGroup(characterFromID("Big Bryan"), "Mystery_House", "goto", "guard");
			LAi_ActorAnimation(characterFromID("Big Bryan"), "Lay_1", "", -1);
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Mystery_House", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Smug Larr"), "Mystery_House", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Mystery_House", "goto", "desk");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Mystery_House", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Lady Barbara Wellesley"), "Mystery_House", "officers", "reload1_3");
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"), Pchar);

			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			LAi_ActorRunToLocator(characterFromID("Lt. Uriah Quelp"), "goto", "goto5", "Return_Mystery_House2", 10.0);
		break;

		case "Return_Mystery_House2":
			LAi_ActorAnimation(characterFromID("Lt. Uriah Quelp"), "attack_2", "", 0.0);
			Lai_KillCharacter(characterFromID("Smug Larr"));
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "goto", "goto1", "", 3.0);
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			LAi_ActorGoToLocator(characterFromID("Sir Edward Pellew"), "goto", "goto4", "Return_Mystery_House3", 0.0);
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			LAi_ActorGoToLocator(characterFromID("Arthur Wellesley"), "officers", "reload1_1", "", 0.0);
		break;

		case "Return_Mystery_House3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "reason_for_killing";
		break;

		case "Sharpe_makes_statement":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Larr_no_knife";
		break;

		case "Pellew_takes_Charge":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Wellesley_to_Tavern";
		break;

		case "Wellesley_Quelp_to_Tavern":
			LAi_ActorGoToLocator(characterFromID("Lt. Uriah Quelp"), "reload", "reload1", "Wellesley_Quelp_to_Tavern2", 2.0);
		break;

		case "Wellesley_Quelp_to_Tavern2":
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			ChangeCharacterAddress(characterFromID("Arthur Wellesley"), "None", "");
			ChangeCharacterAddress(characterFromID("Lady Barbara Wellesley"), "None", "");

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Wellesley_gone_for_now";
		break;

		case "Harper_adds_his_part":
			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "Bryan's_tale";
		
		break;

		case "Go_explore_the_Tunnels":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Orders_for_Higgins";
		break;

		case "Pellew_makes_suggestion":
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "goto", "desk", "", 0.0);

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Pellews_suggestion";
		break;

		case "Down_the_rabbit_hole":
			LAi_ActorGoToLocator(characterFromID("Sir Edward Pellew"), "reload", "reload1", "Down_the_rabbit_hole2", 2.0);
		break;

		case "Down_the_rabbit_hole2":
			AddQuestRecord("Tunnel of Trouble", 3);
			ChangeCharacterAddress(characterFromID("Sir Edward Pellew"), "None", "");

			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Sir Edward Pellew"));
			RemoveCharacterCompanion(pchar, characterFromID("Sir Edward Pellew"));
			RemovePassenger(pchar, characterFromID("Sir Edward Pellew"));
			SetCharacterRemovable(characterFromID("Lt. Uriah Quelp"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. Uriah Quelp"));
			RemoveCharacterCompanion(pchar, characterFromID("Lt. Uriah Quelp"));
			RemovePassenger(pchar, characterFromID("Lt. Uriah Quelp"));
			SetCharacterRemovable(characterFromID("Arthur Wellesley"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Arthur Wellesley"));
			RemoveCharacterCompanion(pchar, characterFromID("Arthur Wellesley"));
			RemovePassenger(pchar, characterFromID("Arthur Wellesley"));

			LAi_QuestDelay("Down_the_rabbit_hole3", 0.0);
		break;

		case "Down_the_rabbit_hole3":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			SetCharacterRemovable(characterFromID("Patrick Harper"), false);

			LAi_QuestDelay("Down_the_rabbit_hole4", 0.0);
		break;

		case "Down_the_rabbit_hole4":
			Pchar.quest.Down_the_rabbit_hole5.win_condition.l1 = "location";
			Pchar.quest.Down_the_rabbit_hole5.win_condition.l1.character = Pchar.id;
			Pchar.quest.Down_the_rabbit_hole5.win_condition.l1.location = "Back_Room";
			Pchar.quest.Down_the_rabbit_hole5.win_condition = "Down_the_rabbit_hole5";
		break;

		case "Down_the_rabbit_hole5":
			Locations[FindLocation("Town_Tunnel")].vcskip = true;
			ChangeCharacterAddress(characterFromID("Smug Larr"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Big Bryan"), "None", "");

			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "Directions_for_Tunnel";
		break;

		case "Down_the_rabbit_hole6":
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			Pchar.quest.Found_Pirate_Encampment.win_condition.l1 = "location";
			Pchar.quest.Found_Pirate_Encampment.win_condition.l1.character = Pchar.id;
			Pchar.quest.Found_Pirate_Encampment.win_condition.l1.location = "Pirate_Entrance";
			Pchar.quest.Found_Pirate_Encampment.win_condition = "Found_Pirate_Encampment";

			pchar.quest.Found_the_Academy_first.win_condition.l1 = "locator";
			pchar.quest.Found_the_Academy_first.win_condition.l1.location = "Town_Tunnel";
			pchar.quest.Found_the_Academy_first.win_condition.l1.locator_group = "goto";
			pchar.quest.Found_the_Academy_first.win_condition.l1.locator = "goto1";
			pchar.quest.Found_the_Academy_first.win_condition = "Found_the_Academy_first";
		break;

		case "Found_the_Academy_first":
			Pchar.Quest.Found_Pirate_Encampment.over = "yes";
			Locations[FindLocation("Town_Tunnel")].reload.l2.disable = 1;

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Academy_task_complete";
		break;

		case "Now_find_pirate_camp":
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			Pchar.quest.Found_Pirate_Encampment_TWO.win_condition.l1 = "location";
			Pchar.quest.Found_Pirate_Encampment_TWO.win_condition.l1.character = Pchar.id;
			Pchar.quest.Found_Pirate_Encampment_TWO.win_condition.l1.location = "Pirate_Entrance";
			Pchar.quest.Found_Pirate_Encampment_TWO.win_condition = "Found_Pirate_Encampment_TWO";
		break;

		case "Found_Pirate_Encampment_TWO":
			pchar.quest.Find_Pirate_Camp = "After_the_Academy";
			LAi_QuestDelay("Found_Pirate_Encampment", 0.0);
		break;

		case "Found_Pirate_Encampment":
			Pchar.Quest.Found_the_Academy_first.over = "yes";
			LAi_SetActorType(PChar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto1", "Found_Pirate_Encampment2", 8.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "officers", "reload3_2", "", 2.0);
		break;

		case "Found_Pirate_Encampment2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "A_Room_with_a_view";
		break;

		case "Sharpe_and_Ships_plans":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Looking_at_Ships";
		break;

		case "Into_the_Fake_Pirate_House":
			Locations[FindLocation("Special_House")].vcskip = true;

			Pchar.quest.Found_Special_House.win_condition.l1 = "location";
			Pchar.quest.Found_Special_House.win_condition.l1.character = Pchar.id;
			Pchar.quest.Found_Special_House.win_condition.l1.location = "Special_House";
			Pchar.quest.Found_Special_House.win_condition = "Found_Special_House";
		break;

		case "Found_Special_House":
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Special_House", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Special_House", "goto", "goto1");
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_QuestDelay("Found_Special_House2", 0.0);
		break;

		case "Found_Special_House2":
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "goto3", "Found_Special_House3", 3.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "Another_Room_with_a_view";
		break;

		case "Found_Special_House3":
			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialogNow(characterFromID("Patrick Harper"),PChar,"",1.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "Another_Room_with_a_view";
		break;

		case "Sharpe_more_plans":
			Pchar.quest.Back_to_Pirate_Room.win_condition.l1 = "location";
			Pchar.quest.Back_to_Pirate_Room.win_condition.l1.character = Pchar.id;
			Pchar.quest.Back_to_Pirate_Room.win_condition.l1.location = "Pirate_Entrance";
			Pchar.quest.Back_to_Pirate_Room.win_condition = "Back_to_Pirate_Room";

			Pchar.quest.Into_Pirate_Encampment.win_condition.l1 = "location";
			Pchar.quest.Into_Pirate_Encampment.win_condition.l1.character = Pchar.id;
			Pchar.quest.Into_Pirate_Encampment.win_condition.l1.location = "QC_town";
			Pchar.quest.Into_Pirate_Encampment.win_condition = "Into_Pirate_Encampment";
		break;
//TRAP
		case "Into_Pirate_Encampment":
			Pchar.Quest.Back_to_Pirate_Room.over = "yes";
			Locations[FindLocation("QC_town")].reload.l8.disable = 1;
			SetRMRelation(PChar, PIRATE, REL_WAR);
			LAi_group_SetRelation("QC_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_SetRelation("QC_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		break;

		case "Back_to_Pirate_Room":
			Pchar.Quest.Into_Pirate_Encampment.over = "yes";
			Locations[FindLocation("Pirate_Entrance")].reload.l2.disable = 1;
			Locations[FindLocation("Special_House")].vcskip = false;

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto1", "Back_to_Pirate_Room2", 8.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "officers", "reload3_2", "", 8.0);
		break;

		case "Back_to_Pirate_Room2":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Options_available";
		break;

		case "Return_to_the_Tunnel":
			Locations[FindLocation("Pirate_Entrance")].reload.l2.disable = 0;
			Locations[FindLocation("Pirate_Entrance")].reload.l1.disable = 1;
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			pchar.quest.Found_the_Academy_second.win_condition.l1 = "locator";
			pchar.quest.Found_the_Academy_second.win_condition.l1.location = "Town_Tunnel";
			pchar.quest.Found_the_Academy_second.win_condition.l1.locator_group = "goto";
			pchar.quest.Found_the_Academy_second.win_condition.l1.locator = "goto1";
			pchar.quest.Found_the_Academy_second.win_condition = "Found_the_Academy_second";

			Pchar.quest.Straight_to_back_room.win_condition.l1 = "location";
			Pchar.quest.Straight_to_back_room.win_condition.l1.character = Pchar.id;
			Pchar.quest.Straight_to_back_room.win_condition.l1.location = "Back_Room";
			Pchar.quest.Straight_to_back_room.win_condition = "Straight_to_back_room";
		break;

		case "Return_to_the_Tunnel_after_Academy": // Academy found first - just used this for ease - go through tunnel not town
			Locations[FindLocation("Pirate_Entrance")].reload.l2.disable = 0;
			Locations[FindLocation("Pirate_Entrance")].reload.l1.disable = 1;
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			Pchar.quest.Town_route_to_back_room.win_condition.l1 = "location";
			Pchar.quest.Town_route_to_back_room.win_condition.l1.character = Pchar.id;
			Pchar.quest.Town_route_to_back_room.win_condition.l1.location = "Back_Room";
			Pchar.quest.Town_route_to_back_room.win_condition = "Town_route_to_back_room";
		break;

		case "Found_the_Academy_second":
			Pchar.Quest.Straight_to_back_room.over = "yes";

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Tunnel_tasks_complete";
		break;

		case "Into_the_Academy_job_done":
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "reload", "reload1_back", "", 20.0);
			Pchar.quest.Now_to_back_room_Mystery_House.win_condition.l1 = "location";
			PChar.quest.Now_to_back_room_Mystery_House.win_condition.l1.character = Pchar.id;
			Pchar.quest.Now_to_back_room_Mystery_House.win_condition.l1.location = "Charlestown_Academy";
			Pchar.quest.Now_to_back_room_Mystery_House.win_condition = "Now_to_back_room_Mystery_House";

			Pchar.quest.Tunnel_to_back_room.win_condition.l1 = "location";
			Pchar.quest.Tunnel_to_back_room.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tunnel_to_back_room.win_condition.l1.location = "Back_Room";
			Pchar.quest.Tunnel_to_back_room.win_condition = "Tunnel_to_back_room";
		break;

		case "Tunnel_to_back_room":
			Pchar.Quest.Now_to_back_room_Mystery_House.over = "yes";
		break;

		case "Now_to_back_room_Mystery_House":
			AddQuestRecord("Tunnel of Trouble", 4);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			Pchar.Quest.Tunnel_to_back_room.over = "yes";
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			Pchar.quest.Town_route_to_back_room.win_condition.l1 = "location";
			Pchar.quest.Town_route_to_back_room.win_condition.l1.character = Pchar.id;
			Pchar.quest.Town_route_to_back_room.win_condition.l1.location = "Back_Room";
			Pchar.quest.Town_route_to_back_room.win_condition = "Town_route_to_back_room";
		break;

		case "Town_route_to_back_room":
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Back_Room", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Back_Room", "goto", "goto6");

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Pellew_in_Back_Room";
		break;

		case "Wellesley_and_Sharpe_to_Leave":
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "We_will_go_to_jail";
		break;

		case "Wellesley_Sharpe_Harper_Go":
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));

			LAi_ActorGoToLocator(characterFromID("Arthur Wellesley"), "reload", "locator2", "Wellesley_Sharpe_Harper_Go2", 2.0);
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "reload", "locator2", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "reload", "locator2", "", 0.0);
		break;

		case "Wellesley_Sharpe_Harper_Go2":
			ChangeCharacterAddress(characterFromID("Arthur Wellesley"), "None", "");
			ChangeCharacterAddress(characterFromID("Richard Sharpe"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");

			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemovePassenger(pchar, characterFromID("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("Patrick Harper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Patrick Harper"));
			RemovePassenger(pchar, characterFromID("Patrick Harper"));

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "More_Pellew_in_Back_Room";
		break;

		case "Academy_for_Quelp":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Sir Edward Pellew"));
			LAi_SetOfficerType(characterFromID("Sir Edward Pellew"));
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), false);

			Pchar.quest.Inside_for_Quelp.win_condition.l1 = "location";
			PChar.quest.Inside_for_Quelp.win_condition.l1.character = Pchar.id;
			Pchar.quest.Inside_for_Quelp.win_condition.l1.location = "Charlestown_Academy";
			Pchar.quest.Inside_for_Quelp.win_condition = "Inside_for_Quelp";
		break;

		case "Inside_for_Quelp":
			ChangeCharacterAddressGroup(characterFromID("Lt. Percy Buckland"), "Charlestown_Academy", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Charlestown_Academy", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Charlestown_Academy", "officers", "reload1_2");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Charlestown_Academy", "reload", "reload2");

			LAi_SetStayType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetStayType(characterFromID("Lt. Percy Buckland"));
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			LAi_ActorGoToLocator(characterFromID("Sir Edward Pellew"), "goto", "goto1", "Set_up_Quelp_Begins", 10.0);
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto2", "", 10);
		break;

		case "Set_up_Quelp_Begins":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Talk_to_Quelp_and_Buckland";
		break;

		case "Quelp_and_Soldier_to_Leave":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "Quelp_and_Pellew";
		break;

		case "Quelp_and_soldier_to_house":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Rifleman Cooper"));
			LAi_ActorGoToLocator(characterFromID("Lt. Uriah Quelp"), "reload", "reload1", "Quelp_and_soldier_to_house2", 10.0);
		break;

		case "Quelp_and_soldier_to_house2":
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "reload", "reload1", "Quelp_and_soldier_to_house3", 5.0);
		break;

		case "Quelp_and_soldier_to_house3":
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Charlestown_Academy", "reload", "reload2");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Charlestown_Academy", "reload", "reload2");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Charlestown_Academy", "reload", "reload2");

			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));

			LAi_QuestDelay("Wellesley_asks_for_plan", 7.0);
		break;

		case "Wellesley_asks_for_plan":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Plan_for_Smugglers_House";
		break;

		case "Pellew_confirms_plan":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Confirm_the_Quelp_plan";
		break;

		case "Hornblower_and_Soldier_Leave":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "reload", "reload1", "Sharpe_and_Harper_leave", 8.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "reload", "reload1", "", 8.0);
		break;

		case "Sharpe_and_Harper_leave":
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			ChangeCharacterAddress(characterFromID("Richard Sharpe"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "reload", "reload1", "Hornblower_and_Wellesley_leave", 1.0);
		break;

		case "Hornblower_and_Wellesley_leave":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Final_French_Quelp_plan";
		break;

		case "Hornblower_and_Wellesley_To_House":
			AddQuestRecord("Tunnel of Trouble", 5);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Arthur Wellesley"));
			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));
			SetCharacterRemovable(characterFromID("Arthur Wellesley"), false);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Sir Edward Pellew"));
			RemovePassenger(pchar, characterFromID("Sir Edward Pellew"));
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), true);
			LAi_SetStayType(characterFromID("Sir Edward Pellew"));

			Pchar.quest.Mystery_House_Troops.win_condition.l1 = "location";
			Pchar.quest.Mystery_House_Troops.win_condition.l1.character = Pchar.id;
			Pchar.quest.Mystery_House_Troops.win_condition.l1.location = "Mystery_House";
			Pchar.quest.Mystery_House_Troops.win_condition = "Mystery_House_Troops";
		break;

		case "Mystery_House_Troops":
			ChangeCharacterAddress(characterFromID("Big Bryan"), "None", "");
			ChangeCharacterAddress(characterFromID("Smug Larr"), "None", "");

			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Mystery_House", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Mystery_House", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Mystery_House", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Mystery_House", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Mystery_House", "goto", "goto5");

			LAi_SetImmortal(characterFromID("Richard Sharpe"), true);
			LAi_SetImmortal(characterFromID("Arthur Wellesley"), true);
			LAi_SetImmortal(characterFromID("Patrick Harper"), true);
//			LAi_SetImmortal(characterFromID("Rifleman Higgins"), true);
//			LAi_SetImmortal(characterFromID("Rifleman Cooper"), true);

			LAi_group_MoveCharacter(characterFromID("Richard Sharpe"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Cooper"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Patrick Harper"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Higgins"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Haggman"), LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto7");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto8");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "guard");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "goto", "guard");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4";

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);

			Pchar.quest.Now_Get_To_Ship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Now_Get_To_Ship.win_condition.l1.character = "soldier1";
			Pchar.quest.Now_Get_To_Ship.win_condition.l2 = "NPC_Death";
			Pchar.quest.Now_Get_To_Ship.win_condition.l2.character = "soldier2";
			Pchar.quest.Now_Get_To_Ship.win_condition.l3 = "NPC_Death";
			Pchar.quest.Now_Get_To_Ship.win_condition.l3.character = "soldier3";
			Pchar.quest.Now_Get_To_Ship.win_condition.l4 = "NPC_Death";
			Pchar.quest.Now_Get_To_Ship.win_condition.l4.character = "soldier4";
			PChar.quest.Now_Get_To_Ship.win_condition = "Now_Get_To_Ship";
		break;

		case "Now_Get_To_Ship":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Time_to_get_to_the_ship";
		break;

		case "In_ship_for_Jamaica_with_Wellesley":
			AddQuestRecord("Tunnel of Trouble", 6);
			DisableFastTravel(false);
			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));
			setCharacterShipLocation(characterFromID("Dreadnought Foster"), "REDMOND_PORT");

			Pchar.quest.Beach_to_meet_Foster.win_condition.l1 = "location";
			Pchar.quest.Beach_to_meet_Foster.win_condition.l1.character = Pchar.id;
			Pchar.quest.Beach_to_meet_Foster.win_condition.l1.location = "QC_Shore1";
			Pchar.quest.Beach_to_meet_Foster.win_condition = "Beach_to_meet_Foster";
		break;

		case "Straight_to_back_room":
			Pchar.Quest.Found_the_Academy_second.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Back_Room", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Back_Room", "goto", "goto6");

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "No_Academy_Back_Room";
		break;

		case "Find_the_Academy_Entrance":
			Pchar.quest.Find_the_Academy_Entrance2.win_condition.l1 = "location";
			Pchar.quest.Find_the_Academy_Entrance2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Find_the_Academy_Entrance2.win_condition.l1.location = "Town_Tunnel";
			Pchar.quest.Find_the_Academy_Entrance2.win_condition = "Find_the_Academy_Entrance2";
		break;

		case "Find_the_Academy_Entrance2":
			Locations[FindLocation("Town_Tunnel")].reload.l1.disable = 1;
			ChangeCharacterAddress(characterFromID("Arthur Wellesley"), "None", "");
			ChangeCharacterAddress(characterFromID("Sir Edward Pellew"), "None", "");

			pchar.quest.Found_the_Academy_THIRD.win_condition.l1 = "locator";
			pchar.quest.Found_the_Academy_THIRD.win_condition.l1.location = "Town_Tunnel";
			pchar.quest.Found_the_Academy_THIRD.win_condition.l1.locator_group = "goto";
			pchar.quest.Found_the_Academy_THIRD.win_condition.l1.locator = "goto1";
			pchar.quest.Found_the_Academy_THIRD.win_condition = "Found_the_Academy_THIRD";
		break;

		case "Found_the_Academy_THIRD":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Tunnel_tasks_complete_THIRD";
		break;

		case "Into_the_Academy_job_done_THIRD":
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "reload", "reload1_back", "Into_the_Academy_job_done_THIRD2", 20.0);
		break;

		case "Into_the_Academy_job_done_THIRD2":
			Pchar.quest.Now_to_back_room_Mystery_House_THIRD.win_condition.l1 = "location";
			PChar.quest.Now_to_back_room_Mystery_House_THIRD.win_condition.l1.character = Pchar.id;
			Pchar.quest.Now_to_back_room_Mystery_House_THIRD.win_condition.l1.location = "Charlestown_Academy";
			Pchar.quest.Now_to_back_room_Mystery_House_THIRD.win_condition = "Now_to_back_room_Mystery_House_THIRD";

			Pchar.quest.Tunnel_to_back_room_THIRD.win_condition.l1 = "location";
			Pchar.quest.Tunnel_to_back_room_THIRD.win_condition.l1.character = Pchar.id;
			Pchar.quest.Tunnel_to_back_room_THIRD.win_condition.l1.location = "Back_Room";
			Pchar.quest.Tunnel_to_back_room_THIRD.win_condition = "Tunnel_to_back_room_THIRD";
		break;

		case "Tunnel_to_back_room_THIRD":
			Pchar.Quest.Now_to_back_room_Mystery_House_THIRD.over = "yes";
		break;

		case "Now_to_back_room_Mystery_House_THIRD":
			Pchar.Quest.Tunnel_to_back_room_THIRD.over = "yes";
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			Pchar.quest.Town_route_to_back_room_THIRD.win_condition.l1 = "location";
			Pchar.quest.Town_route_to_back_room_THIRD.win_condition.l1.character = Pchar.id;
			Pchar.quest.Town_route_to_back_room_THIRD.win_condition.l1.location = "Back_Room";
			Pchar.quest.Town_route_to_back_room_THIRD.win_condition = "Town_route_to_back_room_THIRD";
		break;

		case "Town_route_to_back_room_THIRD":
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Back_Room", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Back_Room", "goto", "goto6");

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Pellew_in_Back_Room_THIRD";
		break;

		case "Beach_to_meet_Foster":
			ChangeCharacterAddressGroup(characterFromID("Dreadnought Foster"), "QC_Shore1", "goto", "locator3");
			LAi_SetOfficerType(characterFromID("Dreadnought Foster"));
			LAi_QuestDelay("First_Meeting_Foster", 0.0);
		break;

		case "First_Meeting_Foster":
			LAi_SetActorType(characterFromID("Dreadnought Foster"));
			Lai_ActorFollow(characterFromID("Dreadnought Foster"), pchar, "More_new_Orders", 5.0);
		break;

		case "More_new_Orders":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			LAi_ActorDialogNow(Pchar, characterFromID("Dreadnought Foster"), "", -1);
			LAi_ActorDialog(characterFromID("Dreadnought Foster"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.currentnode = "Again_More_new_Orders";
		break;

		case "Sir_Peter_Parker":
			Locations[FindLocation("Town_Tunnel")].vcskip = false;
			LAi_SetOfficerType(characterFromID("Dreadnought Foster"));
			DisableFastTravel(false);
			SetRMRelation(PChar, FRANCE, REL_WAR);

			CloseQuestHeader("Tunnel of Trouble");
			SetQuestHeader("Examination for Lieutenant");
			AddQuestRecord("Examination for Lieutenant", 1);

			Pchar.quest.With_Foster_to_Jamaica.win_condition.l1 = "location";
			Pchar.quest.With_Foster_to_Jamaica.win_condition.l1.character = Pchar.id;
			Pchar.quest.With_Foster_to_Jamaica.win_condition.l1.location = "REDMOND_PORT";
			Pchar.quest.With_Foster_to_Jamaica.win_condition = "With_Foster_to_Jamaica";
		break;

		case "With_Foster_to_Jamaica":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			ChangeCharacterAddressGroup(characterFromID("Dreadnought Foster"), "REDMOND_PORT", "goto", "goto_45");
			LAi_SetOfficerType(characterFromID("Dreadnought Foster"));
			LAi_QuestDelay("Things to do first", 0.0);
		break;

		case "Things to do first":
			DisableFastTravel(true);
			characters[GetCharacterIndex("Dreadnought Foster")].Dialog.Filename = "Dreadnought Foster_dialog.c";
			LAi_SetActorType(characterFromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Before_meeting_parker";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Things_to_do_first2":
			LAi_SetActorType(characterFromID("Dreadnought Foster"));
			LAi_ActorGoToLocator(characterFromID("Dreadnought Foster"), "officers", "sea_1_3", "Things_to_do_first3", 5.0);

			SetCharacterRemovable(characterFromID("Arthur Wellesley"), true);
			RemovePassenger(pchar, characterFromID("Arthur Wellesley"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Arthur Wellesley"));
		break;

		case "Things_to_do_first3":
			AddQuestRecord("Examination for Lieutenant", 2);
			ChangeCharacterAddress(characterFromID("Arthur Wellesley"), "None", "");
			ChangeCharacterAddress(characterFromID("Dreadnought Foster"), "None", "");

			Pchar.quest.Meet_again_Pellew.win_condition.l1 = "location";
			Pchar.quest.Meet_again_Pellew.win_condition.l1.character = Pchar.id;
			Pchar.quest.Meet_again_Pellew.win_condition.l1.location = "Redmond_town_01";
			Pchar.quest.Meet_again_Pellew.win_condition = "Meet_again_Pellew";
		break;

		case "Meet_again_Pellew":
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Redmond_town_01", "goto", "goto10");
			LAi_QuestDelay("Meet_again_Pellew2", 2.0);
		break;

		case "Meet_again_Pellew2":
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_SetStayType(characterFromID("Sir Edward Pellew"));
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "outside_the_gates";
		break;

		case "Meet_again_Pellew3":
			AddQuestRecord("Examination for Lieutenant", 3);
			Locations[FindLocation("Redmond_town_01")].reload.l16.disable = false;
			Locations[FindLocation("Redmond Naval HQ")].vcskip = true;

			Pchar.quest.The_Lieutenants_exam.win_condition.l1 = "location";
			Pchar.quest.The_Lieutenants_exam.win_condition.l1.character = Pchar.id;
			Pchar.quest.The_Lieutenants_exam.win_condition.l1.location = "Redmond Naval HQ";
			Pchar.quest.The_Lieutenants_exam.win_condition = "The_Lieutenants_exam";
		break;
// THE EXAMINATION FOR LIEUTENANT - FIRESHIPS
		case "The_Lieutenants_exam":
			ChangeCharacterAddress(characterFromID("Sir Edward Pellew"), "None", "");
			Locations[FindLocation("Redmond Naval HQ")].vcskip = true;
			ChangeCharacterAddressGroup(characterFromID("Lt. Chadd"), "Redmond Naval HQ", "sit", "sit1");

			LAi_SetActorType(Pchar);
			LAi_SetActorType(characterFromID("Lt. Chadd"));
			characters[GetCharacterIndex("Lt. Chadd")].Dialog.Filename = "Lt. Chadd_dialog.c";
			Characters[GetCharacterIndex("Lt. Chadd")].Dialog.CurrentNode = "First_meeting";
			LAi_ActorFollow(pchar, characterFromID("Lt. Chadd"), "", 1.0);
			LAi_ActorFollow(characterFromID("Lt. Chadd"), pchar, "The_Lieutenants_exam2", 1.0);
		break;

		case "The_Lieutenants_exam2":
			LAi_ActorWaitDialog(Pchar, characterFromID("Lt. Chadd"));
			LAi_ActorDialog(characterFromID("Lt. Chadd"), Pchar, "", 5.0, 0);
		break;

		case "go_upstairs":
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("Head_of_Jamaica_Station")].vcskip = true;

			Pchar.quest.Head_of_Jamaica_Station.win_condition.l1 = "location";
			Pchar.quest.Head_of_Jamaica_Station.win_condition.l1.character = Pchar.id;
			Pchar.quest.Head_of_Jamaica_Station.win_condition.l1.location = "Head_of_Jamaica_Station";
			Pchar.quest.Head_of_Jamaica_Station.win_condition = "Head_of_Jamaica_Station";
		break;

		case "Head_of_Jamaica_Station":
			ChangeCharacterAddressGroup(characterFromID("Captain Harvey"), "Head_of_Jamaica_Station", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "Head_of_Jamaica_Station", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Dreadnought Foster"), "Head_of_Jamaica_Station", "goto", "goto5");
			LAi_SetSitType(characterfromID("Captain Harvey"));


			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Dreadnought Foster"));
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Sir Edward Pellew"));
			setCharacterShipLocation(characterfromID("Dreadnought Foster"), "REDMOND_PORT");
			setCharacterShipLocation(characterfromID("Sir Edward Pellew"), "REDMOND_PORT");
			SetCharacterRemovable(characterFromID("Dreadnought Foster"), false);
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), false);

			LAi_QuestDelay("Head_of_Jamaica_Station2", 0.0);
		break;

		case "Head_of_Jamaica_Station2":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto8", "The_exam_begins", 10);
			LAi_SetActorType(characterFromID("Dreadnought Foster"));
			setCharacterShipLocation(Pchar, "REDMOND_PORT");
		break;

		case "The_exam_begins":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Lt. Chadd"), "Head_of_Jamaica_Station", "reload", "reload1");
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Foster_exam_one";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Hammond_starts":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Hammond_exam_one";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"), pchar, "", 1.0, 1.0);
		break;

		case "Now_Foster_two":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Foster_exam_two";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Hammond_again":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Hammond_exam_two";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"), pchar, "", 1.0, 1.0);
		break;

		case "General_Alarm":
			PlaySound("OBJECTS\SHIPCHARGE\cannon_fire_03.wav");
			LAi_SetActorType(characterfromID("Lt. Chadd"));
			Characters[GetCharacterIndex("Lt. Chadd")].dialog.CurrentNode = "Fire_ship_sighted";
			LAi_ActorDialog(characterFromID("Lt. Chadd"), pchar, "", 1.0, 1.0);
		break;

		case "Get_to_port_fire_ship":
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"RN_Corvette","Fire Ship", -1, ENGLAND,true,true);
			LAi_ActorRunToLocator(characterFromID("Black Charlie Hammond"), "reload", "reload1", "Get_to_port_fire_ship2",2);
			LAi_ActorRunToLocator(characterFromID("Dreadnought Foster"), "reload", "reload1", "",2);
			LAi_ActorRunToLocator(characterFromID("Lt. Chadd"), "reload", "reload1", "",2);
		break;

		case "Get_to_port_fire_ship2":
			AddQuestRecord("Examination for Lieutenant", 4);
			ChangeCharacterAddress(characterFromID("Black Charlie Hammond"), "None", "");
			ChangeCharacterAddress(characterFromID("Dreadnought Foster"), "None", "");
			ChangeCharacterAddress(characterFromID("Captain Harvey"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. Chadd"), "None", "");
			LAi_QuestDelay("Get_to_port_fire_ship3", 0.0);
		break;

		case "Get_to_port_fire_ship3":
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "REDMOND_PORT", "goto", "Goto_44");
			ChangeCharacterAddressGroup(characterFromID("Dreadnought Foster"), "REDMOND_PORT", "goto", "Goto_45");

			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Redmond_town_01", "reload", "Door_5");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Redmond_town_01", "reload", "Door_5");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Redmond_town_01", "reload", "Door_5");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Redmond_town_01", "reload", "Door_5");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Redmond_town_01", "reload", "Door_5");

			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));

			pchar.quest.all_to_port_fire_ship.win_condition.l1 = "location";
			PChar.quest.all_to_port_fire_ship.win_condition.l1.character = Pchar.id;
			pchar.quest.all_to_port_fire_ship.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.all_to_port_fire_ship.win_condition = "all_to_port_fire_ship";
		break;

		case "all_to_port_fire_ship":
			SetCurrentTime(21.00, 0);
			PlaySound("OBJECTS\ABORDAGE\abordageLong.wav");
			LAi_ActorRunToLocator(characterfromID("Rifleman Cooper"), "reload", "reload_from_port", "", 20);
			LAi_ActorRunToLocator(characterfromID("Rifleman Haggman"), "reload", "reload_from_port", "", 20);
			LAi_ActorRunToLocator(characterfromID("Rifleman Harris"), "reload", "reload_from_port", "", 20);
			LAi_ActorRunToLocator(characterfromID("Rifleman Higgins"), "reload", "reload_from_port", "", 20);
			LAi_ActorRunToLocator(characterfromID("Rifleman Tongue"), "reload", "reload_from_port", "all_to_port_fire_ship2", 20);
			Pchar.quest.all_to_port_fire_ship2.win_condition.l1 = "locator";
			Pchar.quest.all_to_port_fire_ship2.win_condition.l1.character = Pchar.id;
			Pchar.quest.all_to_port_fire_ship2.win_condition.l1.location = "Redmond_town_01";
			Pchar.quest.all_to_port_fire_ship2.win_condition.l1.locator_group = "reload";
			Pchar.quest.all_to_port_fire_ship2.win_condition.l1.locator = "reload_from_port";
			Pchar.quest.all_to_port_fire_ship2.win_condition = "all_to_port_fire_ship2";

		break;

		case "all_to_port_fire_ship2":
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Harris"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			LAi_QuestDelay("all_to_port_fire_ship3", 0.0);
		break;

		case "all_to_port_fire_ship3":
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "REDMOND_PORT", "reload", "Door_1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "REDMOND_PORT", "reload", "Door_1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "REDMOND_PORT", "reload", "Door_1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "REDMOND_PORT", "reload", "Door_1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "REDMOND_PORT", "reload", "Door_1");

			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));

			pchar.quest.fire_ship_in_port.win_condition.l1 = "location";
			pchar.quest.fire_ship_in_port.win_condition.l1.location = "REDMOND_PORT";
			pchar.quest.fire_ship_in_port.win_condition = "fire_ship_in_port";
		break;

		case "fire_ship_in_port":
			PlaySound("OBJECTS\ABORDAGE\abordageLong.wav");
			LAi_ActorRunToLocator(characterfromID("Rifleman Cooper"), "goto", "goto_47", "", 30);
			LAi_ActorRunToLocator(characterfromID("Rifleman Haggman"), "goto", "goto_46", "", 30);
			LAi_ActorRunToLocator(characterfromID("Rifleman Harris"), "goto", "goto_41", "", 30);
			LAi_ActorRunToLocator(characterfromID("Rifleman Higgins"), "goto", "goto_40", "", 30);
			LAi_ActorRunToLocator(characterfromID("Rifleman Tongue"), "goto", "goto_39", "", 30);

			Ship_Detonate(pchar, true, false);
			Ship_Detonate(pchar, true, false);
			Ship_Detonate(pchar, true, false);
			Ship_Detonate(pchar, true, false);

			pchar.quest.fire_ship_in_port2.win_condition.l1 = "locator";
			pchar.quest.fire_ship_in_port2.win_condition.l1.location = "REDMOND_PORT";
			pchar.quest.fire_ship_in_port2.win_condition.l1.locator_group = "goto";
			pchar.quest.fire_ship_in_port2.win_condition.l1.locator = "goto_60";
			pchar.quest.fire_ship_in_port2.win_condition = "fire_ship_in_port2";
		break;

		case "fire_ship_in_port2":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Got_to_get_aboard";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);

			DisableFastTravel(false);
		break;

		case "Swim_to_fire_ship":
			LAi_SetActorType(Pchar);
			LAi_ActorRunToLocator((Pchar), "reload", "Sea_1_back", "Swim_to_fire_ship2", 2);
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			LAi_ActorRunToLocator(characterfromID("Dreadnought Foster"), "reload", "Sea_1_back", "", 2);
		break;

		case "Swim_to_fire_ship2":
			LAi_Fade("", "");
			SetCurrentTime(22, 0);
			DoQuestReloadToLocation("Quest_FireShipDeck", "rld", "aloc4", "Fire_ship_main_deck");
		break;

		case "Fire_ship_main_deck":
			PlaySound("OBJECTS\ABORDAGE\long_fire_sound.wav");
			LAi_SetPlayerType(Pchar);

			ChangeCharacterAddressGroup(characterFromID("Dreadnought Foster"), "Quest_FireShipDeck", "rld", "aloc6");
			LAi_QuestDelay("Fire_ship_main_deck2", 0.0);
		break;

		case "Fire_ship_main_deck2":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			LAi_ActorAnimation(characterfromID("Dreadnought Foster"), "afraid","", 10);
			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire1", "", -1, 2.3644, 1.2625, -3.3012, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 14.0; 
			CreateParticleSystemX("fireball", 2.3644, 1.2625, -3.3012, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire2", "", -1, 3.883, 1.2621, -2.4903, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 12.0; 
			CreateParticleSystemX("fireball", 3.883, 1.2621, -2.4903, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire3", "", -1, 2.9455, 1.2825, -2.3531, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 2.9455, 1.2825, -2.3531, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire4", "", -1, 2.9433, 1.9979, -3.0595, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 2.9433, 1.9979, -3.0595, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire5", "", -1, 3.462, 1.2632, -5.2719, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 3.462, 1.2632, -5.2719, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire6", "", -1, 3.1343, 2.57, -4.3232, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 3.1343, 2.57, -4.3232, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire7", "", -1, 2.9436, 4.0647, 15.705, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", 2.9436, 4.0647, -18.79, 15.705, 0.0, 0.0,0);
			
			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire8", "", -1, 1.9071, 4.0407, 15.968, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 1.9071, 4.0407, 15.968, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire9", "", -1, 0.79502, 4.0407, 15.659, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", 0.79502, 4.0407, 15.659, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire10", "", -1, -0.45385, 3.9986, 14.222, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -0.45385, 3.9986, 14.222, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire11", "", -1, -3.8888, 3.8873, 10.637, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -3.8888, 3.8873, 10.637, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire12", "", -1, 0.99486, 1.3999, 13.563, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", 0.99486, 1.3999, 13.563, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire13", "", -1, -0.036598, 1.3999, 9.2421, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -0.036598, 1.3999, 9.2421, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire14", "", -1, -0.41291, 1.2632, -5.2352, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -0.41291, 1.2632, -5.2352, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire15", "", -1, -1.6877, 1.2632, -5.7083, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -1.6877, 1.2632, -2.6928, -5.7083, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire16", "", -1, -2.5388, 4.2031, -10.719, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -2.5388, 3.2031, -10.719, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire17", "", -1, -1.1732, 4.2031, -10.844, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -1.1732, 4.2031, -10.844, -1.57, 0.0, 0.0,0);

			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Go_to_the_wheel";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Fire_ship_main_deck3":
			LAi_SetOfficerType(characterfromID("Dreadnought Foster"));

			pchar.quest.Fire_ship_main_deck4.win_condition.l1 = "locator";
			Pchar.quest.Fire_ship_main_deck4.win_condition.l1.character = Pchar.id;
			pchar.quest.Fire_ship_main_deck4.win_condition.l1.location = "Quest_FireShipDeck";
			pchar.quest.Fire_ship_main_deck4.win_condition.l1.locator_group = "rld";
			pchar.quest.Fire_ship_main_deck4.win_condition.l1.locator = "aloc1";
			pchar.quest.Fire_ship_main_deck4.win_condition = "Fire_ship_main_deck4";
		break;

		case "Fire_ship_main_deck4":
			PlaySound("OBJECTS\ABORDAGE\long_fire_sound.wav");
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Steering_instructions";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Fire_ship_main_deck5":
			PlaySound("OBJECTS\ABORDAGE\long_fire_sound.wav");
			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire18", "", -1, -0.93506, 4.0546, -5.8339, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -0.93506, 4.0546, -5.8339, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire19", "", -1, -3.878, 1.2607, 6.356, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -3.878, 1.2607, 6.356, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire20", "", -1, -2.357, 4.1373, -8.8529, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -2.357, 4.1373, -8.8529, -1.57, 0.0, 0.0,0);

			LAi_QuestDelay("Fire_ship_main_deck6", 3.0);
		break;

		case "Fire_ship_main_deck6":
			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire21", "", -1, -0.27019, 4.2062, -6.7042, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -0.27019, 4.2062, -6.7042, -1.57, 0.0, 0.0,0);

			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Hold_her_steady";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Fire_ship_main_deck7":
			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire22", "", -1, -0.62579, 1.2609, 0.1415, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -0.62579, 1.2609, 0.1415, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire23", "", -1, 2.2474, 3.8861, 10.467, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -2.2474, 3.8861, 10.467, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire24", "", -1, 2.8259, 3.918, -4.9551, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", 2.8259, 3.918, -4.9551, -1.57, 0.0, 0.0,0);

			LAi_QuestDelay("Fire_ship_main_deck8", 3.0);
		break;

		case "Fire_ship_main_deck8":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Hard_a_lea";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire25", "", -1, 2.7801, 4.0797, -6.7173, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", 2.7801, 4.0797, -6.7173, -1.57, 0.0, 0.0,0);
		break;

		case "Fire_ship_main_deck9":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			LAi_ActorRunToLocator(characterfromID("Dreadnought Foster"), "rld", "aloc6", "Fire_ship_main_deck10", 10);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire26", "", -1, 1.9447, 1.2603, 2.6549, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", 1.9447, 1.2603, 2.6549, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire27", "", -1, 0.98859, 1.3993, 2.6636, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", 0.98859, 1.3993, 2.6636, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire28", "", -1, 0.085868, 1.3993, 2.4401, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", 0.085868, 1.3993, 2.4401, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire29", "", -1, -0.83161, 1.3993, 2.8752, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -0.83161, 1.3993, 2.8752, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire30", "", -1, -1.9815, 1.2604, 4.2799, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -1.9815, 1.2604, 4.2799, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire31", "", -1, -0.76749, 1.2617, -1.3553, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -0.76749, 1.2617, -1.3553, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Quest_FireShipDeck", "fire", "fire32", "", -1, -0.64864, 1.2619, -1.9218, false);
			Locations[FindLocation("Quest_FireShipDeck")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Quest_FireShipDeck")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -0.64864, 1.2619, -1.9218, -1.57, 0.0, 0.0,0);
		break;

		case "Fire_ship_main_deck10":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_06.wav");
			LAi_SetStunnedTypeNoGroup(characterFromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Save_yourself_Hornblower";

			pchar.quest.Killed_in_fire.win_condition.l1 = "locator";
			Pchar.quest.Killed_in_fire.win_condition.l1.character = Pchar.id;
			pchar.quest.Killed_in_fire.win_condition.l1.location = "Quest_FireShipDeck";
			pchar.quest.Killed_in_fire.win_condition.l1.locator_group = "goto";
			pchar.quest.Killed_in_fire.win_condition.l1.locator = "goto1";
			pchar.quest.Killed_in_fire.win_condition = "Killed_in_fire";

			pchar.quest.Killed_in_fireA.win_condition.l1 = "locator";
			Pchar.quest.Killed_in_fireA.win_condition.l1.character = Pchar.id;
			pchar.quest.Killed_in_fireA.win_condition.l1.location = "Quest_FireShipDeck";
			pchar.quest.Killed_in_fireA.win_condition.l1.locator_group = "goto";
			pchar.quest.Killed_in_fireA.win_condition.l1.locator = "goto2";
			pchar.quest.Killed_in_fireA.win_condition = "Killed_in_fire";

			pchar.quest.Killed_in_fireB.win_condition.l1 = "locator";
			Pchar.quest.Killed_in_fireB.win_condition.l1.character = Pchar.id;
			pchar.quest.Killed_in_fireB.win_condition.l1.location = "Quest_FireShipDeck";
			pchar.quest.Killed_in_fireB.win_condition.l1.locator_group = "goto";
			pchar.quest.Killed_in_fireB.win_condition.l1.locator = "goto3";
			pchar.quest.Killed_in_fireB.win_condition = "Killed_in_fire";

			pchar.quest.Killed_in_fireC.win_condition.l1 = "locator";
			Pchar.quest.Killed_in_fireC.win_condition.l1.character = Pchar.id;
			pchar.quest.Killed_in_fireC.win_condition.l1.location = "Quest_FireShipDeck";
			pchar.quest.Killed_in_fireC.win_condition.l1.locator_group = "goto";
			pchar.quest.Killed_in_fireC.win_condition.l1.locator = "goto4";
			pchar.quest.Killed_in_fireC.win_condition = "Killed_in_fire";
		break;

		case "Killed_in_fire":
			Lai_KillCharacter(Pchar);
			LAi_QuestDelay("KilledFighting", 3.0);
		break;

		case "Fire_ship_main_deck11":
			Pchar.Quest.Killed_in_fire.over = "yes";
			Pchar.Quest.Killed_in_fireA.over = "yes";
			Pchar.Quest.Killed_in_fireB.over = "yes";
			Pchar.Quest.Killed_in_fireC.over = "yes";
			LAi_SetActorType(Pchar);
			LAi_ActorRunToLocator((Pchar), "rld", "aloc6", "Jump_into_the_water", 10);
			LAi_SetOfficerType(characterfromID("Dreadnought Foster"));
		break;

		case "Jump_into_the_water":
			LAi_Fade("", "");
			SetCurrentTime(6, 0);
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"FR_Sloop","Le Rève",-1,FRANCE,true,true);
			SetCrewQuantity(pchar, 150);
			AddCharacterGoods(pchar, GOOD_BALLS, 500);
			AddCharacterGoods(pchar, GOOD_GRAPES, 300);
			AddCharacterGoods(pchar, GOOD_KNIPPELS, 200);
			AddCharacterGoods(pchar, GOOD_RUM, 10);
			AddCharacterGoods(pchar, GOOD_WHEAT, 20);
			setCharacterShipLocation(Pchar, "REDMOND_PORT");

			SetCharacterRemovable(characterFromID("Dreadnought Foster"), true);
			SetCharacterRemovable(characterFromID("Sir Edward Pellew"), true);
			RemoveCharacterCompanion(Pchar, characterFromID("Dreadnought Foster"));
			RemoveCharacterCompanion(Pchar, characterFromID("Sir Edward Pellew"));

			DoQuestReloadToLocation("REDMOND_PORT", "reload", "Sea_1_back", "An_argument_between_Captains");
		break;

		case "An_argument_between_Captains":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			LAi_SetOfficerType(characterfromID("Black Charlie Hammond"));
			LAi_ActorGoToLocator((Pchar), "goto", "goto_45", "An_argument_between_Captains2", 5.0);
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "REDMOND_PORT", "officers", "Sea_1_3");
			ChangeCharacterAddressGroup(characterFromID("Dreadnought Foster"), "REDMOND_PORT", "goto", "Goto_44");
		break;

		case "An_argument_between_Captains2":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Where_were_you";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Implying_what";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue2":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "read implications";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue3":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Offensive_remark";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue4":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "perspicacity";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue5":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "appology";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue6":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "no_appology";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue7":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "continue_further";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue8":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "your_appology";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue9":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "recompense";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue10":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "most_welcome";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue11":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "send_second";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue12":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "Look_forward";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
		break;

		case "Captains_argue13":
			LAi_SetActorType(characterfromID("Black Charlie Hammond"));
			LAi_ActorGoToLocator(characterfromID("Black Charlie Hammond"), "goto", "goto_17", "", 20);

			LAi_QuestDelay("Captains_argue13A", 3.0);
		break;

		case "Captains_argue13A":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "staring_at";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "REDMOND_PORT", "goto", "goto_58");
		break;

		case "Captains_argue14":
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			Characters[GetCharacterIndex("Dreadnought Foster")].dialog.CurrentNode = "owe_life";
			LAi_ActorDialog(characterFromID("Dreadnought Foster"), pchar, "", 1.0, 1.0);
			LAi_SetOfficerType(characterFromID("Sir Edward Pellew"));
		break;

		case "Captains_leave":
			ChangeCharacterAddress(characterFromID("Black Charlie Hammond"), "None", "");
			LAi_SetActorType(characterfromID("Dreadnought Foster"));
			LAi_ActorGoToLocator(characterfromID("Dreadnought Foster"), "goto", "goto_17", "", 20);

			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Your_wet_Back_to_Ship";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 10.0, 10.0);
		break;

		case "Congrats_on_Indy":
			LAi_Fade("", "");
			SetCurrentTime(10, 0);

			DoQuestReloadToLocation("Cabin2SJG", "rld", "loc6", "Captain_Pellews_Cabin");

			ChangeCharacterAddress(characterFromID("Dreadnought Foster"), "None", "");
		break;

		case "Captain_Pellews_Cabin":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Cabin2SJG", "officers", "officer1");
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));	
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Acts_of_heroism";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 10.0, 10.0);
		break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////// INSERT DINNER SCENE WHEN LOCATION WITH TABLES HAS BEEN ESTABLISHED //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "Get_ready_for_the_Duchess":
			LAi_Fade("", "");
			SetCurrentTime(10, 0);
			DoQuestReloadToLocation("Head_of_Jamaica_Station", "reload", "reload1", "Head_of_Jamaica_StationXXX");
		break;

// THE DUCHESS AND THE DEVIL
		case "Head_of_Jamaica_StationXXX":
			ChangeCharacterAddressGroup(characterFromID("Sir Hew Dalrymple"), "Head_of_Jamaica_Station", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Head_of_Jamaica_Station", "goto", "goto5");

			LAi_QuestDelay("Head_of_Jamaica_StationXXX2", 0.0);
		break;

		case "Head_of_Jamaica_StationXXX2":
			LAi_SetActorType(Pchar);
			
			LAi_ActorGoToLocator((Pchar), "goto", "goto8", "Discuss_the_MissionAAA", 10);
			LAi_SetActorType(characterFromID("Sir Hew Dalrymple"));
		break;

		case "Discuss_the_MissionAAA":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Head_of_Jamaica_Station", "goto", "goto1");

			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));	
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "An_excellent_dinner";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 10.0, 10.0);
		break;

		case "Discuss_the_MissionBBB":
			LAi_SetActorType(characterfromID("Sir Hew Dalrymple"));
			Characters[GetCharacterIndex("Sir Hew Dalrymple")].dialog.CurrentNode = "Start_of_the_conversation";
			LAi_ActorDialog(characterFromID("Sir Hew Dalrymple"), pchar, "", 1.0, 1.0);
		break;

		case "Pellew_Chimes_In":
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Head_of_Jamaica_Station", "goto", "goto1");

			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));	
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Here_are_the_documents";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 10.0, 10.0);
		break;

		case "And_now_the_Duchess":
			LAi_SetOfficerType(characterFromID("The Duchess of Wharfedale"));
			SetOfficersIndex(Pchar, 1, getCharacterIndex("The Duchess of Wharfedale"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Midshipman Hunter"));
			SetCharacterRemovable(characterFromID("The Duchess of Wharfedale"), false);
			SetCharacterRemovable(characterFromID("Midshipman Hunter"), false);
			LAi_QuestDelay("And_now_the_Duchess2", 0.0);
		break;

		case "And_now_the_Duchess2":
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));	
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "our_first_meeting";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 10.0, 10.0);
		break;

		case "Sailing_with_the_Duchess":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator((Pchar), "reload", "reload1", "Sailing_with_the_Duchess2", 10);
		break;

		case "Sailing_with_the_Duchess2":
			DoQuestReloadToLocation("Redmond Naval HQ", "reload", "reload2", "Sailing_with_the_Duchess3");
		break;

		case "Sailing_with_the_Duchess3":
			CloseQuestHeader("Examination for Lieutenant");
			SetQuestHeader("The Duchess and the Devil");
			AddQuestRecord("The Duchess and the Devil", 1);
			LAi_SetPlayerType(Pchar);

			Pchar.quest.Sailing_with_the_Duchess4.win_condition.l1 = "location";
			Pchar.quest.Sailing_with_the_Duchess4.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sailing_with_the_Duchess4.win_condition.l1.location = "Redmond_town_01";
			Pchar.quest.Sailing_with_the_Duchess4.win_condition = "Sailing_with_the_Duchess4";
		break;

		case "Sailing_with_the_Duchess4":
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Redmond_town_01", "officers", "Door_56_2");
			ChangeCharacterAddressGroup(characterFromID("Midshipman Hunter"), "Redmond_town_01", "officers", "Door_56_1");
			LAi_SetOfficerType(characterFromID("The Duchess of Wharfedale"));
			DisableFastTravel(false);
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(characterFromID("Midshipman Hunter"));
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.CurrentNode = "get_ready_for_capture";
			LAi_QuestDelay("initial_set_up_for_capture", 0.0);
		break;

		case "initial_set_up_for_capture":
			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			LAi_ActorDialogNow(characterFromID("Midshipman Hunter"),PChar,"",1.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "get_ready_for_capture";
		break;

		case "Le_Reve_Capture_at_sea":
			LAi_SetOfficerType(characterFromID("Midshipman Hunter"));
			DisableFastTravel(false);
			Pchar.quest.Le_Reve_Capture_at_sea2.win_condition.l1 = "MapEnter";
			Pchar.quest.Le_Reve_Capture_at_sea2.win_condition = "Le_Reve_Capture_at_sea2";
			SetCurrentTime(10, 0);
			SetNextWeather("Blue Sky");
		break;

		case "Le_Reve_Capture_at_sea2":
			CI_CreateAndSetControls( "WorldMapControls", "WMapCancel", -1, 0, true );// TIH worldmap cancel screwup prevention Sep3'06
			StorePassengers("Blaze");
			PostVideoAndQuest("Hornblower\Le Reve Capture",100, "Go_to_Beach_for_Prison");
			bMainMenuLaunchAfterVideo = true;
			SetNextWeather("Blue Sky");
		break;

		case "Go_to_Beach_for_Prison":
			PostEvent("DoInfoShower",100,"s","");

// Grey Roger: remove ship
			DeleteAttribute(pchar, "Ship");
			pchar.Ship.Type = SHIP_NOTUSED_TYPE_NAME;
			pchar.Ship.Name = "";

			SetCurrentTime(10.00, 0);
			SetCharacterRemovable(characterFromID("The Duchess of Wharfedale"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("The Duchess of Wharfedale"));
			RemoveCharacterCompanion(Pchar, characterFromID("The Duchess of Wharfedale"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("The Duchess of Wharfedale"));

			SetNextWeather("Blue Sky");
			Characters[GetCharacterIndex("Don Masseredo")].dialog.currentnode = "beach_capture";

			DoQuestReloadToLocation("Cuba_Shore_04", "Reload", "Reload1", "To_the_Spanish_Beach");
		break;

		case "To_the_Spanish_Beach":
			SetCurrentTime(10, 0);
			Locations[FindLocation("Havana_fakefort4")].vcskip = true;
			ChangeCharacterAddressGroup(characterFromID("Don Masseredo"), "Cuba_Shore_04", "goto", "locator8");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Cuba_Shore_04", "goto", "citizen03");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Cuba_Shore_04", "goto", "locator9");
			ChangeCharacterAddressGroup(characterFromID("Helmsman"), "Cuba_Shore_04", "goto", "locator24");

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Midshipman Hunter"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Midshipman Hunter"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Matthews"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Matthews"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Helmsman"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Helmsman"), GUN_ITEM_TYPE);

			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			LAi_SetActorType(characterFromID("Don Masseredo"));
			LAi_ActorDialogNow(characterFromID("Don Masseredo"),PChar,"",1.0);
			Characters[GetCharacterIndex("Don Masseredo")].dialog.currentnode = "beach_capture";
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "In_the_Spanish_Fort";
		break;

		case "To_the_Spanish_Prison":
			LAi_Fade("", "");
			DoQuestReloadToLocation("Havana_fakefort4", "rld", "loc2", "To_the_Spanish_Prison2");
		break;

		case "To_the_Spanish_Prison2":
			AddQuestRecord("The Duchess and the Devil", 2);
			Locations[FindLocation("Havana_fakefort4")].reload.l1.disable = 1;
			Locations[FindLocation("Havana_fakefort4")].reload.l2.disable = 1;
			Locations[FindLocation("Prison_Shore")].reload.l1.disable = 1;

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "rld", "character_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reloadc3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reloadc5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier4SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reloadc2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier5SP";

			ChangeCharacterAddressGroup(characterFromID("Styles"), "Havana_fakefort4", "rld", "loc4");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Havana_fakefort4", "rld", "loc6");
			ChangeCharacterAddressGroup(characterFromID("Helmsman"), "Havana_fakefort4", "rld", "loc5");
			ChangeCharacterAddressGroup(characterFromID("Perrin"), "Havana_fakefort4", "rld", "aloc6");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Havana_fakefort4", "rld", "loc7");
			ChangeCharacterAddressGroup(characterFromID("Marsh"), "Havana_fakefort4", "rld", "aloc8");
			ChangeCharacterAddressGroup(characterFromID("Midshipman Hunter"), "Havana_fakefort4", "rld", "loc3");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Havana_fakefort4", "goto", "goto1");

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Midshipman Hunter"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Midshipman Hunter"), GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Matthews"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Matthews"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Helmsman"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Helmsman"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Perrin"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Perrin"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Oldroyd"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Oldroyd"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Marsh"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Marsh"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Archie Kennedy"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Archie Kennedy"), GUN_ITEM_TYPE);

			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			LAi_ActorDialogNow(characterFromID("Midshipman Hunter"),PChar,"",1.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "In_the_Spanish_Fort";

			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "fort_capture";
		break;

		case "Find_Kennedy_in_Prison":
			Locations[FindLocation("Prison_Shore")].vcskip = true;
			LAi_SetActorType(characterFromID("Matthews"));
			LAi_SetActorType(characterFromID("Styles"));
			LAi_SetActorType(characterFromID("Helmsman"));
			LAi_SetOfficerType(characterFromID("Midshipman Hunter"));

			LAi_ActorGoToLocator(characterFromID("Matthews"), "rld", "loc8", "", 10.0);
			LAi_ActorGoToLocator(characterFromID("Styles"), "rld", "aloc8", "", 10.0);
			LAi_ActorGoToLocator(characterFromID("Helmsman"), "rld", "aloc7", "", 10.0);

			LAi_SetCivilianGuardianType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "fort_capture";
			LAi_ActorDialog(characterFromID("Archie Kennedy"), pchar, "", 10.0, 10.0);

			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "Talk_about_Archie";
		break;

		case "Talking_in_prison":
			LAi_SetStunnedTypeNoGroup(characterFromID("Archie Kennedy"));
			LAi_QuestDelay("Talking_in_prison2", 2.0);
		break;

		case "Talking_in_prison2":
			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"), pchar);

			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			LAi_ActorDialogNow(characterFromID("Midshipman Hunter"),PChar,"",1.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "Talk_about_Archie";
		break;

		case "More_days_in_Prison":
			AddQuestRecord("The Duchess and the Devil", 3);
			WaitDate("", 0, 0, 8, 0, 0);
			LAi_Fade("More_days_in_Prison2", "More_days_in_Prison3");
		break;

		case "More_days_in_Prison2":
			ChangeCharacterAddressGroup(Pchar, "Havana_fakefort4", "rld", "aloc2");
			ChangeCharacterAddressGroup(characterFromID("Midshipman Hunter"), "Havana_fakefort4", "rld", "aloc3");
		break;

		case "More_days_in_Prison3":
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Havana_fakefort4", "rld", "aloc1");

			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			LAi_ActorDialogNow(characterFromID("Midshipman Hunter"),PChar,"",1.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "Talk_about_Escape";
		break;

		case "Here_comes_the_Duchess":
			LAi_SetOfficerType(characterFromID("Midshipman Hunter"));
			LAi_SetStayType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "Feeling_ill";
			LAi_ActorDialog(characterFromID("Archie Kennedy"), pchar, "", 10.0, 10.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "Archie_still_sick";
		break;

		case "Hunter_complains":
			LAi_SetStunnedTypeNoGroup(characterFromID("Archie Kennedy"));

			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			LAi_ActorDialogNow(characterFromID("Midshipman Hunter"),PChar,"",1.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "Archie_still_sick";
		break;

		case "The_Duchess_is_back":
			ChangeCharacterAddressGroup(characterFromID("Don Masseredo"), "Havana_fakefort4", "rld", "loc6");
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Havana_fakefort4", "rld", "loc10");

			LAi_SetOfficerType(characterFromID("The Duchess of Wharfedale"));
			LAi_QuestDelay("The_Duchess_speaks", 2.0);
		break;

		case "The_Duchess_speaks":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Meet_in_Spanish_prison";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 10.0, 10.0);
		break;

		case "Meet_with_the_Don":
			LAi_ActorGoToLocator(characterFromID("The Duchess of Wharfedale"), "rld", "loc10", "The_Don_offers_parole", 20.0);
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
		break;

		case "The_Don_offers_parole":
			Locations[FindLocation("Prison_Shore")].reload.l2.disable = 1;

			LAi_SetActorType(characterFromID("Don Masseredo"));
			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "Offer_of_Parole";
			LAi_ActorDialog(characterFromID("Don Masseredo"), pchar, "", 1.0, 1.0);
		break;

		case "Go_explore_the_Beach":
			AddQuestRecord("The Duchess and the Devil", 4);
			LAi_ActorGoToLocator(characterFromID("Don Masseredo"), "reload", "reloadc1", "", 10.0);
			LAi_ActorGoToLocator(characterFromID("The Duchess of Wharfedale"), "reload", "reloadc4", "Go_explore_the_Beach2", 20.0);
		break;

		case "Go_explore_the_Beach2":
			Locations[FindLocation("Havana_fakefort4")].reload.l1.disable = 0;
			ChangeCharacterAddress(characterFromID("Don Masseredo"), "None", "");
			ChangeCharacterAddress(characterFromID("The Duchess of Wharfedale"), "None", "");
			SetOfficersIndex(Pchar, 1, getCharacterIndex("The Duchess of Wharfedale"));
			SetCharacterRemovable(characterFromID("The Duchess of Wharfedale"), false);
			Locations[FindLocation("Prison_Shore")].vcskip = true;
			SetCharacterRemovable(characterFromID("Midshipman Hunter"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Midshipman Hunter"));

			Pchar.quest.Go_explore_the_Beach3.win_condition.l1 = "location";
			Pchar.quest.Go_explore_the_Beach3.win_condition.l1.character = Pchar.id;
			Pchar.quest.Go_explore_the_Beach3.win_condition.l1.location = "Prison_Shore";
			Pchar.quest.Go_explore_the_Beach3.win_condition = "Go_explore_the_Beach3";
		break;

		case "Go_explore_the_Beach3":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier6SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto1");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier7SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier8SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier9SP";

			pchar.quest.A_talk_on_the_Beach.win_condition.l1 = "locator";
			pchar.quest.A_talk_on_the_Beach.win_condition.l1.location = "Prison_Shore";
			pchar.quest.A_talk_on_the_Beach.win_condition.l1.locator_group = "goto";
			pchar.quest.A_talk_on_the_Beach.win_condition.l1.locator = "goto16";
			pchar.quest.A_talk_on_the_Beach.win_condition = "A_talk_on_the_Beach";
		break;

		case "A_talk_on_the_Beach":
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.currentnode = "Duchess_on_the_Beach";
			LAi_QuestDelay("A_talk_on_the_Beach2", 0.0);
		break;

		case "A_talk_on_the_Beach2":
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			LAi_ActorDialogNow(characterFromID("The Duchess of Wharfedale"),PChar,"",1.0);
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.currentnode = "Duchess_on_the_Beach";
		break;

		case "With_duchess_to_prison":
			LAi_ActorGoToLocator(characterFromID("The Duchess of Wharfedale"), "reload", "reload1_back", "With_duchess_to_prison2", 90.0);
		break;

		case "With_duchess_to_prison2":
			Locations[FindLocation("Prison_Shore")].reload.l2.disable = 0;
			ChangeCharacterAddress(characterFromID("The Duchess of Wharfedale"), "None", "");

			Pchar.quest.Hunter_gets_nasty.win_condition.l1 = "location";
			Pchar.quest.Hunter_gets_nasty.win_condition.l1.character = Pchar.id;
			Pchar.quest.Hunter_gets_nasty.win_condition.l1.location = "Havana_fakefort4";
			Pchar.quest.Hunter_gets_nasty.win_condition = "Hunter_gets_nasty";
		break;

		case "Hunter_gets_nasty":
			Locations[FindLocation("Havana_fakefort4")].reload.l1.disable = 1;

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "rld", "character_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reloadc3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "rld", "aloc7");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier4SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reloadc2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier5SP";

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Midshipman Hunter"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Midshipman Hunter"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Matthews"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Matthews"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Helmsman"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Helmsman"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Perrin"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Perrin"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Oldroyd"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Oldroyd"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Marsh"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Marsh"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Archie Kennedy"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Archie Kennedy"), GUN_ITEM_TYPE);

			ChangeCharacterAddressGroup(characterFromID("Midshipman Hunter"), "Havana_fakefort4", "rld", "aloc1");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Havana_fakefort4", "rld", "loc3");
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "Did_you_have_a_nice_walk";
			LAi_QuestDelay("Hunter_gets_nasty2", 5.0);
		break;

		case "Hunter_gets_nasty2":
			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			LAi_ActorDialogNow(characterFromID("Midshipman Hunter"),PChar,"",1.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "Did_you_have_a_nice_walk";
		break;

		case "Go_see_Kennedy_again":
			LAi_ActorGoToLocator(characterFromID("Midshipman Hunter"), "rld", "loc9", "Go_see_Kennedy_again2", 10.0);
		break;

		case "Go_see_Kennedy_again2":
			LAi_SetCivilianGuardianType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "feeling better";
			LAi_ActorDialog(characterFromID("Archie Kennedy"), pchar, "", 10.0, 10.0);
		break;

		case "The_Duchess_once_more":
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Havana_fakefort4", "rld", "loc10");

			LAi_SetOfficerType(characterFromID("The Duchess of Wharfedale"));
			LAi_QuestDelay("The_Duchess_speaks_again", 2.0);
		break;

		case "The_Duchess_speaks_again":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "How_is_Mr_Kennedy";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 10.0, 10.0);
		break;

		case "Archie_speaks_out":
			LAi_SetActorType(Pchar);
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorTurnToCharacter(pchar, characterFromID("Archie Kennedy"));
			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"), pchar);

			LAi_ActorGoToLocator(characterFromID("The Duchess of Wharfedale"), "rld", "loc10", "Archie_speaks_out2", 5.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "shes_an_actress";
		break;

		case "Archie_speaks_out2":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddress(characterFromID("The Duchess of Wharfedale"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Don Masseredo"), "Havana_fakefort4", "rld", "aloc0");

			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialogNow(characterFromID("Archie Kennedy"),PChar,"",1.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "shes_an_actress";
		break;

		case "invite_to_dinner":
			Locations[FindLocation("Havana_fakefort4")].reload.l2.disable = 0;
			SetCharacterRemovable(characterFromID("The Duchess of Wharfedale"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("The Duchess of Wharfedale"));

			LAi_SetActorType(characterFromID("Don Masseredo"));
			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "Come_to_dinner";
			LAi_ActorDialog(characterFromID("Don Masseredo"), pchar, "", 1.0, 1.0);
		break;

		case "Go_to_dining_room":
			AddQuestRecord("The Duchess and the Devil", 5);
			LAi_ActorGoToLocator(characterFromID("Don Masseredo"), "reload", "reloadc5", "Go_to_dining_room2", 20.0);
		break;

		case "Go_to_dining_room2":
			ChangeCharacterAddress(characterFromID("Don Masseredo"), "None", "");
			LAi_QuestDelay("Go_to_dining_room3", 0.0);
		break;

		case "Go_to_dining_room3":
			ChangeCharacterAddressGroup(characterFromID("Don Masseredo"), "Dining_Room", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Etienne de Vergasse"), "Dining_Room", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Dining_Room", "goto", "goto1");
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			LAi_SetActorType(characterFromID("Don Masseredo"));
			LAi_SetActorType(characterFromID("Etienne de Vergasse"));

			pchar.quest.A_talk_at_Dinner.win_condition.l1 = "location";
			pchar.quest.A_talk_at_Dinner.win_condition.l1.character = Pchar.id;
			pchar.quest.A_talk_at_Dinner.win_condition.l1.location = "Dining_Room";
			pchar.quest.A_talk_at_Dinner.win_condition = "A_talk_at_Dinner";
		break;

		case "A_talk_at_Dinner":
			SetCurrentTime(22.00, 0);
			pchar.quest.A_talk_at_Dinner2.win_condition.l1 = "locator";
			pchar.quest.A_talk_at_Dinner2.win_condition.l1.location = "Dining_Room";
			pchar.quest.A_talk_at_Dinner2.win_condition.l1.locator_group = "reload";
			pchar.quest.A_talk_at_Dinner2.win_condition.l1.locator = "reload1";
			pchar.quest.A_talk_at_Dinner2.win_condition = "A_talk_at_Dinner2";
		break;

		case "A_talk_at_Dinner2":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto7", "A_talk_at_Dinner3", 10.0);
		break;

		case "A_talk_at_Dinner3":
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterFromID("Don Masseredo"));
			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "Introductions_at_dinner";
			LAi_ActorDialog(characterFromID("Don Masseredo"), pchar, "", 1.0, 1.0);
		break;

		case "The_Frenchman_Speaks":
		 	LAi_SetActorType(characterFromID("Etienne de Vergasse"));
			characters[GetCharacterIndex("Etienne de Vergasse")].Dialog.Filename = "Etienne de Vergasse_dialog.c";
			Characters[GetCharacterIndex("Etienne de Vergasse")].dialog.CurrentNode = "First_words_at_dinner";
			LAi_ActorDialog(characterFromID("Etienne de Vergasse"), pchar, "", 1.0, 1.0);
		break;

		case "Duchess_one":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "First_words_Duchess";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 1.0, 1.0);
		break;

		case "Masseredo_speaks_out":
			LAi_SetActorType(characterFromID("Don Masseredo"));
			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "Masseredo_one";
			LAi_ActorDialog(characterFromID("Don Masseredo"), pchar, "", 1.0, 1.0);
		break;

		case "The_Frenchman_two":
		 	LAi_SetActorType(characterFromID("Etienne de Vergasse"));
			characters[GetCharacterIndex("Etienne de Vergasse")].Dialog.Filename = "Etienne de Vergasse_dialog.c";
			Characters[GetCharacterIndex("Etienne de Vergasse")].dialog.CurrentNode = "Second_words_at_dinner";
			LAi_ActorDialog(characterFromID("Etienne de Vergasse"), pchar, "", 1.0, 1.0);
		break;

		case "Duchess_two":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Second_words_Duchess";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 1.0, 1.0);
		break;

		case "The_Frenchman_three":
		 	LAi_SetActorType(characterFromID("Etienne de Vergasse"));
			characters[GetCharacterIndex("Etienne de Vergasse")].Dialog.Filename = "Etienne de Vergasse_dialog.c";
			Characters[GetCharacterIndex("Etienne de Vergasse")].dialog.CurrentNode = "Third_words_at_dinner";
			LAi_ActorDialog(characterFromID("Etienne de Vergasse"), pchar, "", 1.0, 1.0);
		break;

		case "Duchess_three":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Third_words_Duchess";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 1.0, 1.0);
		break;

		case "Masseredo_interjection":
			LAi_SetActorType(characterFromID("Don Masseredo"));
			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "A_Battle_Sir";
			LAi_ActorDialog(characterFromID("Don Masseredo"), pchar, "", 1.0, 1.0);
		break;

		case "The_Frenchman_four":
		 	LAi_SetActorType(characterFromID("Etienne de Vergasse"));
			characters[GetCharacterIndex("Etienne de Vergasse")].Dialog.Filename = "Etienne de Vergasse_dialog.c";
			Characters[GetCharacterIndex("Etienne de Vergasse")].dialog.CurrentNode = "Fourth_words_at_dinner";
			LAi_ActorDialog(characterFromID("Etienne de Vergasse"), pchar, "", 1.0, 1.0);
		break;

		case "Duchess_four":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Fourth_words_Duchess";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 1.0, 1.0);
		break;

		case "Frenchman_last":
			LAi_SetActorType(characterFromID("Etienne de Vergasse"));
			characters[GetCharacterIndex("Etienne de Vergasse")].Dialog.Filename = "Etienne de Vergasse_dialog.c";
			Characters[GetCharacterIndex("Etienne de Vergasse")].dialog.CurrentNode = "Fifth_words_at_dinner";
			LAi_ActorDialog(characterFromID("Etienne de Vergasse"), pchar, "", 1.0, 1.0);
		break;

		case "Leave_the_Dinner":
			LAi_Fade("", "");

			ChangeCharacterAddress(characterFromID("The Duchess of Wharfedale"), "None", "");
			ChangeCharacterAddress(characterFromID("Styles"), "None", "");
			ChangeCharacterAddress(characterFromID("Matthews"), "None", "");
			ChangeCharacterAddress(characterFromID("Helmsman"), "None", "");
			ChangeCharacterAddress(characterFromID("Perrin"), "None", "");
			ChangeCharacterAddress(characterFromID("Oldroyd"), "None", "");
			ChangeCharacterAddress(characterFromID("Marsh"), "None", "");
			ChangeCharacterAddress(characterFromID("Midshipman Hunter"), "None", "");
			
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Havana_fakefort4", "rld", "loc5");
			ChangeCharacterAddressGroup(characterFromID("Etienne de Vergasse"), "Havana_fakefort4", "rld", "loc1");
			DoQuestReloadToLocation("Havana_fakefort4", "rld", "loc2", "Leave_the_Dinner2");
		break;

		case "Leave_the_Dinner2":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "rld", "character_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reloadc3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reloadc5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier4SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reloadc2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier5SP";

			Locations[FindLocation("Havana_fakefort4")].reload.l2.disable = 1;
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "After_Dinner_Talk";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 1.0, 1.0);
		break;

		case "The_Frenchman_Interupts":
			LAi_SetActorType(characterFromID("Etienne de Vergasse"));
			characters[GetCharacterIndex("Etienne de Vergasse")].Dialog.Filename = "Etienne de Vergasse_dialog.c";
			Characters[GetCharacterIndex("Etienne de Vergasse")].dialog.CurrentNode = "words_after_dinner";
			LAi_ActorDialog(characterFromID("Etienne de Vergasse"), pchar, "", 1.0, 1.0);
		break;

		case "The_Duchess_and_Officer":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "After_Dinner_Talk_Frenchman";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 1.0, 1.0);
		break;

		case "Duchess_and_Frenchman_leave":
			LAi_ActorGoToLocator(characterFromID("The Duchess of Wharfedale"), "reload", "reloadc1", "", 10.0);
			LAi_ActorGoToLocator(characterFromID("Etienne de Vergasse"), "reload", "reloadc1", "Duchess_and_Frenchman_leave2", 10.0);
			
		break;

		case "Duchess_and_Frenchman_leave2":
			ChangeCharacterAddress(characterFromID("The Duchess of Wharfedale"), "None", "");
			ChangeCharacterAddress(characterFromID("Etienne de Vergasse"), "None", "");
			LAi_QuestDelay("Duchess_and_Frenchman_leave3", 1.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "A_Nice_Dinner_Sir";
		break;

		case "Duchess_and_Frenchman_leave3":
			LAi_Fade("", "");
			SetCurrentTime(10.00, 0);
			DoQuestReloadToLocation("Havana_fakefort4", "rld", "loc2", "Next_day_in_Prison");
		break;

		case "Next_day_in_Prison":
			WaitDate("", 0, 0, 1, 0, 0);
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Havana_fakefort4", "rld", "aloc9");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Havana_fakefort4", "rld", "loc0");
			ChangeCharacterAddressGroup(characterFromID("Helmsman"), "Havana_fakefort4", "rld", "aloc2");
			ChangeCharacterAddressGroup(characterFromID("Perrin"), "Havana_fakefort4", "rld", "aloc3");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Havana_fakefort4", "rld", "loc6");
			ChangeCharacterAddressGroup(characterFromID("Marsh"), "Havana_fakefort4", "rld", "loc4");
			ChangeCharacterAddressGroup(characterFromID("Midshipman Hunter"), "Havana_fakefort4", "rld", "loc3");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Havana_fakefort4", "goto", "goto1");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "rld", "character_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reloadc3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reloadc5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier4SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reloadc2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier5SP";

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Midshipman Hunter"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Midshipman Hunter"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Matthews"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Matthews"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Helmsman"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Helmsman"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Perrin"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Perrin"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Oldroyd"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Oldroyd"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Marsh"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Marsh"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Archie Kennedy"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Archie Kennedy"), GUN_ITEM_TYPE);

			characters[GetCharacterIndex("Midshipman Hunter")].Dialog.Filename = "Midshipman Hunter_dialog.c";
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			LAi_ActorDialogNow(characterFromID("Midshipman Hunter"),PChar,"",1.0);
			Characters[GetCharacterIndex("Midshipman Hunter")].dialog.currentnode = "A_Nice_Dinner_Sir";
		break;

		case "The_Duchess_explains":
			LAi_ActorGoToLocator(characterFromID("Midshipman Hunter"), "rld", "loc10", "The_Duchess_explains2", 10.0);
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Havana_fakefort4", "reload", "reloadc5");
			LAi_SetOfficerType(characterFromID("The Duchess of Wharfedale"));
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "The_next_day_Talk";
		break;

		case "The_Duchess_explains2":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "The_next_day_Talk";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"), pchar, "", 1.0, 1.0);
		break;

		case "The_Last_of_the_Duchess":
			LAi_ActorGoToLocator(characterFromID("The Duchess of Wharfedale"), "reload", "reloadc1", "The_Last_of_the_Duchess2", 10.0);
		break;

		case "The_Last_of_the_Duchess2":
			LAi_Fade("", "");
			SetCurrentTime(21.00, 0);
			ChangeCharacterAddress(characterFromID("The Duchess of Wharfedale"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Don Masseredo"), "Havana_fakefort4", "reload", "reloadc5");
			DoQuestReloadToLocation("Havana_fakefort4", "rld", "loc1", "No_Duchess_in_Prison");
		break;

		case "No_Duchess_in_Prison":
			Locations[FindLocation("Havana_fakefort4")].reload.l1.disable = 0;
			Locations[FindLocation("Prison_Shore")].reload.l1.disable = 0;

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "rld", "character_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reloadc3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reloadc5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier4SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reloadc2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier5SP";

			SetCharacterRemovable(characterFromID("The Duchess of Wharfedale"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("The Duchess of Wharfedale"));
			RemoveCharacterCompanion(Pchar, characterFromID("The Duchess of Wharfedale"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("The Duchess of Wharfedale"));

			LAi_SetOfficerType(characterFromID("Don Masseredo"));
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "Masseredo_Duchess_gone";
			LAi_QuestDelay("No_Duchess_in_Prison2", 2.0);
		break;

		case "No_Duchess_in_Prison2":
			LAi_SetActorType(characterFromID("Don Masseredo"));
			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "Masseredo_Duchess_gone";
			LAi_ActorDialog(characterFromID("Don Masseredo"), pchar, "", 1.0, 1.0);
		break;

		case "The_Beach_scene_before_the_Wreck":
			AddQuestRecord("The Duchess and the Devil", 6);
			LAi_Fade("", "");
			SetCurrentTime(22.00, 0);
			SetNextWeather("Black Pearl Fight");
			ChangeCharacterAddress(characterFromID("Don Masseredo"), "None", "");
			DoQuestReloadToLocation("Prison_Shore", "goto", "goto11", "On_the_wreck_beach");
		break;

		case "On_the_wreck_beach":
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"Tartane50","Rescue",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Cuba_Shore_04");

			ChangeCharacterAddressGroup(characterFromID("Don Masseredo"), "Prison_Shore", "goto", "goto16");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Prison_Shore", "officers", "reload2_3");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Prison_Shore", "officers", "reload2_2");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Prison_Shore", "officers", "reload2_1");
			ChangeCharacterAddressGroup(characterFromID("Perrin"), "Prison_Shore", "goto", "goto12");

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);
			EnableEquip(characterFromID("Styles"), BLADE_ITEM_TYPE, false);
			EnableEquip(characterFromID("Styles"), GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Matthews"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Matthews"), GUN_ITEM_TYPE);
			EnableEquip(characterFromID("Matthews"), BLADE_ITEM_TYPE, false);
			EnableEquip(characterFromID("Matthews"), GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Perrin"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Perrin"), GUN_ITEM_TYPE);
			EnableEquip(characterFromID("Perrin"), BLADE_ITEM_TYPE, false);
			EnableEquip(characterFromID("Perrin"), GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Oldroyd"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Oldroyd"), GUN_ITEM_TYPE);
			EnableEquip(characterFromID("Oldroyd"), BLADE_ITEM_TYPE, false);
			EnableEquip(characterFromID("Oldroyd"), GUN_ITEM_TYPE, false);

			LAi_SetOfficerType(characterFromID("Styles"));
			LAi_SetOfficerType(characterFromID("Oldroyd"));
			LAi_SetOfficerType(characterFromID("Perrin"));
			LAi_SetOfficerType(characterFromID("Matthews"));
			LAi_QuestDelay("On_the_wreck_beach2", 5.0);
		break;

		case "On_the_wreck_beach2":
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "Ships_are_fighting";
			LAi_ActorDialog(characterFromID("Matthews"), pchar, "", 1.0, 1.0);
		break;

		case "The_Don_Arrives":
			SetNextWeather("Black Pearl Fight");

			LAi_SetActorType(characterFromID("Don Masseredo"));
			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "Masseredo_Battle_Scene";
			LAi_ActorDialog(characterFromID("Don Masseredo"), pchar, "", 1.0, 1.0);
		break;

		case "rescue_the_shipwrecked":
			SetNextWeather("Black Pearl Fight");

			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "What_do_we_do_Now";

			pchar.quest.Get_the_crew_together.win_condition.l1 = "location";
			pchar.quest.Get_the_crew_together.win_condition.l1.character = Pchar.id;
			pchar.quest.Get_the_crew_together.win_condition.l1.location = "Cuba_Shore_04";
			pchar.quest.Get_the_crew_together.win_condition = "Get_the_crew_together";
		break;

		case "Get_the_crew_together":
			SetNextWeather("Black Pearl Fight");

			ChangeCharacterAddressGroup(characterFromID("Midshipman Hunter"), "Cuba_Shore_04", "goto", "locator8");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Cuba_Shore_04", "goto", "locator22");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Cuba_Shore_04", "officers", "reload1_2");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Cuba_Shore_04", "goto", "locator7");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Cuba_Shore_04", "goto", "locator9");
			ChangeCharacterAddressGroup(characterFromID("Perrin"), "Cuba_Shore_04", "goto", "locator24");
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_SetOfficerType(characterFromID("Midshipman Hunter"));
			LAi_SetOfficerType(characterFromID("Matthews"));
			LAi_QuestDelay("Get_the_crew_together2", 5.0);
		break;

		case "Get_the_crew_together2":
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialogNow(characterFromID("Archie Kennedy"),PChar,"",1.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "What_do_we_do_Now";
		break;

		case "rescue_boat_to_sea":
			LAi_Fade("rescue_boat_to_sea2", "");
		break;

		case "rescue_boat_to_sea2":
			PostVideoAndQuest("Hornblower\SHIPWRECK_0001", 100, "Again_Back_to_the_Indy");
			bMainMenuLaunchAfterVideo = true;
		break;

		case "Again_Back_to_the_Indy":
			PostEvent("DoInfoShower",100,"s","");
//			RestorePassengers("Blaze");
			StorePassengers("Blaze");
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Indy_after_escape";
			DoQuestReloadToLocation("Quest_ShipDeck6", "goto", "goto9", "Get_out_of_wet_clothes");
		break;

		case "Get_out_of_wet_clothes":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Quest_ShipDeck6", "goto", "goto10");
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Quest_ShipDeck6", "rld", "startloc");
			LAi_ActorTurnToCharacter(characterFromID("Sir Edward Pellew"), pchar);
			LAi_SetOfficerType(characterFromID("The Duchess of Wharfedale"));
			LAi_SetActorType(characterFromID("Arthur Wellesley"));

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Indy_after_escape";
		break;

		case "Duchess_Promotion_and_return":
			LAi_Fade("", "");
			SetCurrentTime(10.00, 0);
			SetNextWeather("Blue Sky");
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"HMS_Indefatigable","Indefatigable",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Cuba_Shore_04");
			LAi_SetActorType(characterFromID("Arthur Wellesley"));

			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Duchess_rested";
			DoQuestReloadToLocation("Cabin2", "officers", "reload1_2", "Will_return_to_Prison");
		break;

		case "Will_return_to_Prison":
			ChangeCharacterAddress(characterFromID("Midshipman Hunter"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Cabin2", "rld", "loc6");
			ChangeCharacterAddressGroup(characterFromID("The Duchess of Wharfedale"), "Cabin2", "rld", "loc4");
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Cabin2", "officers", "officer1");

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Duchess_rested";

			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Duchess_is_rested";
		break;

		case "Duchess_parrot_cage":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Duchess_is_rested";

			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Duchess_going_to_Jamaica";
		break;

		case "Pellew_for_Jamaica_and_documents":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Duchess_going_to_Jamaica";

			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Duchess_gives_documents_back";
		break;

		case "Burdened_her_Grace":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Duchess_gives_documents_back";

			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Document_return_shout";
		break;

		case "Promtion_and_return":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Document_return_shout";

			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Duchess_defends_Horatio";
		break;

		case "Duchess_and_promotion":
			LAi_SetActorType(characterFromID("The Duchess of Wharfedale"));
			characters[GetCharacterIndex("The Duchess of Wharfedale")].Dialog.Filename = "The Duchess of Wharfedale_dialog.c";
			LAi_ActorDialog(characterFromID("The Duchess of Wharfedale"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("The Duchess of Wharfedale")].dialog.CurrentNode = "Duchess_defends_Horatio";

			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Promotion_for_Horatio";
		break;

		case "Pellew_and_promotion":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Promotion_for_Horatio";
		break;

		case "Go_to_see_the_crew":
			SetRank(pchar, ENGLAND, 3);
			AddQuestRecord("The Duchess and the Devil", 7);
			SetCharacterRemovable(characterFromID("The Duchess of Wharfedale"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("The Duchess of Wharfedale"));
			RemovePassenger(pchar, characterFromID("The Duchess of Wharfedale"));
			Locations[FindLocation("Quest_ShipDeck6")].vcskip = true;
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "First time";
			DoQuestReloadToLocation("Quest_ShipDeck6", "goto", "goto4", "Crew_asked_about_prison");
		break;

		case "Crew_asked_about_prison":
			Lai_SetActorType(pchar);
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Quest_ShipDeck6", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Quest_ShipDeck6", "goto", "goto11");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Quest_ShipDeck6", "reload", "boatl");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Quest_ShipDeck6", "goto", "goto13");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Quest_ShipDeck6", "goto", "goto2");

			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"),characterFromID("Sir Edward Pellew"));
			LAi_ActorTurnToCharacter(characterFromID("Sir Edward Pellew"), characterFromID("Archie Kennedy"));
			LAi_ActorTurnToCharacter(characterFromID("Matthews"), characterFromID("Sir Edward Pellew"));
			LAi_ActorTurnToCharacter(characterFromID("Styles"), characterFromID("Sir Edward Pellew"));
			LAi_ActorTurnToCharacter(characterFromID("Oldroyd"), characterFromID("Sir Edward Pellew"));
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Sir Edward Pellew"));

			LAi_SetCivilianGuardianType(characterFromID("Sir Edward Pellew"));
			LAi_SetStayType(characterFromID("Archie Kennedy"));
			LAi_SetStayType(characterFromID("Matthews"));
			LAi_SetStayType(characterFromID("Styles"));
			LAi_SetStayType(characterFromID("Oldroyd"));
			LAi_SetStayType(characterFromID("Perrin"));
			LAi_QuestDelay("Crew_asked_about_prison2", 1.0);
		break;

		case "Crew_asked_about_prison2":
			Lai_SetPlayerType(pchar);
			
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Address_the_ships_crew";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;

		case "Archie_agrees_prison":
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "Answer_for_the_ships_crew";
			LAi_ActorDialog(characterFromID("Archie Kennedy"), pchar, "", 1.0, 1.0);
		break;

		case "From_Indy_to_Prison":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Return_the_ships_crew";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;

		case "From_Indy_to_Prison2":
			LAi_Fade("From_Indy_to_Prison3", "");
		break;

		case "From_Indy_to_Prison3":
			Characters[GetCharacterIndex("Don Masseredo")].dialog.currentnode = "A_man_of_honour";
			DoQuestReloadToLocation("Havana_fakefort4", "rld", "loc2", "Back_in_Prison_from_Indy");
		break;

		case "Back_in_Prison_from_Indy":
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Havana_fakefort4", "rld", "aloc9");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Havana_fakefort4", "rld", "loc0");
			ChangeCharacterAddressGroup(characterFromID("Helmsman"), "Havana_fakefort4", "rld", "aloc2");
			ChangeCharacterAddressGroup(characterFromID("Perrin"), "Havana_fakefort4", "rld", "aloc3");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Havana_fakefort4", "rld", "loc6");
			ChangeCharacterAddressGroup(characterFromID("Marsh"), "Havana_fakefort4", "rld", "loc4");
			ChangeCharacterAddressGroup(characterFromID("Don Masseredo"), "Havana_fakefort4", "rld", "loc3");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Havana_fakefort4", "goto", "goto1");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "reload", "character_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reloadc3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reloadc5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier4SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reloadc2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier5SP";

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Matthews"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Matthews"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Helmsman"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Helmsman"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Perrin"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Perrin"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Oldroyd"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Oldroyd"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Marsh"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Marsh"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Archie Kennedy"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Archie Kennedy"), GUN_ITEM_TYPE);

			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			LAi_SetActorType(characterFromID("Don Masseredo"));
			LAi_ActorDialogNow(characterFromID("Don Masseredo"),PChar,"",1.0);
			Characters[GetCharacterIndex("Don Masseredo")].dialog.currentnode = "A_man_of_honour";
		break;

		case "Waste_time_with_Archie":
			LAi_ActorGoToLocator(characterFromID("Don Masseredo"), "reload", "reloadc1", "Waste_time_with_Archie2", 10.0);
		break;

		case "Waste_time_with_Archie2":
			LAi_Fade("", "");
			WaitDate("", 0, 0, 12, 0, 0);
			SetCurrentTime(10.00, 0);
			ChangeCharacterAddress(characterFromID("Don Masseredo"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Havana_fakefort4", "rld", "loc8");
			DoQuestReloadToLocation("Havana_fakefort4", "rld", "loc1", "Waste_time_in_Prison");
		break;

		case "Waste_time_in_Prison":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Matthews"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Matthews"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Helmsman"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Helmsman"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Perrin"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Perrin"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Oldroyd"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Oldroyd"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Marsh"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Marsh"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Archie Kennedy"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Archie Kennedy"), GUN_ITEM_TYPE);

			LAi_SetOfficerType(characterFromID("Archie Kennedy"));

			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "Just_like_old_times";
			LAi_QuestDelay("Waste_time_in_Prison2", 2.0);
		break;

		case "Waste_time_in_Prison2":
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "Just_like_old_times";
			LAi_ActorDialog(characterFromID("Archie Kennedy"), pchar, "", 1.0, 1.0);
		break;

		case "FREE_from_the_prison":
			LAi_Fade("", "");
			WaitDate("", 0, 0, 10, 0, 0);
			SetCurrentTime(10.00, 0);
			ChangeCharacterAddressGroup(characterFromID("Don Masseredo"), "Havana_fakefort4", "rld", "aloc7");
			DoQuestReloadToLocation("Havana_fakefort4", "rld", "loc1", "FREE_from_the_prison2");
			SetRank(CharacterFromID("Sir Edward Pellew"), ENGLAND, 7); // GR: Meanwhile Pellew has been promoted
		break;

		case "FREE_from_the_prison2":
			Locations[FindLocation("Havana_fakefort4")].reload.l1.disable = 0;
			Locations[FindLocation("Havana_fakefort4")].reload.l2.disable = 0;

			LAi_SetOfficerType(characterFromID("Don Masseredo"));
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "Masseredo_you_are_free";
			LAi_QuestDelay("FREE_from_the_prison3", 2.0);
		break;

		case "FREE_from_the_prison3":
			LAi_SetActorType(characterFromID("Don Masseredo"));
			characters[GetCharacterIndex("Don Masseredo")].Dialog.Filename = "Don Masseredo_dialog.c";
			Characters[GetCharacterIndex("Don Masseredo")].dialog.CurrentNode = "Masseredo_you_are_free";
			LAi_ActorDialog(characterFromID("Don Masseredo"), pchar, "", 1.0, 1.0);
		break;

		case "FREE_back_to_the_Indy":
			AddQuestRecord("The Duchess and the Devil", 8);
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"HMS_Indefatigable","Indefatigable",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Cuba_Shore_04");

			LAi_SetActorType(characterFromID("Styles"));
			LAi_SetActorType(characterFromID("Matthews"));
			LAi_SetActorType(characterFromID("Helmsman"));
			LAi_SetActorType(characterFromID("Perrin"));
			LAi_SetActorType(characterFromID("Oldroyd"));
			LAi_SetActorType(characterFromID("Marsh"));
			LAi_SetActorType(characterFromID("Archie Kennedy"));

			LAi_ActorRunToLocator(characterFromID("Styles"), "reload", "reloadc4", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Matthews"), "reload", "reloadc4", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Helmsman"), "reload", "reloadc4", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Perrin"), "reload", "reloadc4", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Oldroyd"), "reload", "reloadc4", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Marsh"), "reload", "reloadc4", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Archie Kennedy"), "reload", "reloadc4", "",0.0);

			LAi_QuestDelay("FREE_back_to_the_Indy2", 6.0);
		break;

		case "FREE_back_to_the_Indy2":
			ChangeCharacterAddress(characterFromID("Don Masseredo"), "None", "");
			ChangeCharacterAddress(characterFromID("Styles"), "None", "");
			ChangeCharacterAddress(characterFromID("Matthews"), "None", "");
			ChangeCharacterAddress(characterFromID("Helmsman"), "None", "");
			ChangeCharacterAddress(characterFromID("Perrin"), "None", "");
			ChangeCharacterAddress(characterFromID("Oldroyd"), "None", "");
			ChangeCharacterAddress(characterFromID("Marsh"), "None", "");
			ChangeCharacterAddress(characterFromID("Archie Kennedy"), "None", "");

			Pchar.quest.Finally_Pellew_and_Wellesley.win_condition.l1 = "location";
			Pchar.quest.Finally_Pellew_and_Wellesley.win_condition.l1.character = Pchar.id;
			Pchar.quest.Finally_Pellew_and_Wellesley.win_condition.l1.location = "Prison_Shore";
			Pchar.quest.Finally_Pellew_and_Wellesley.win_condition = "Finally_Pellew_and_Wellesley";
		break;

		case "Finally_Pellew_and_Wellesley":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier6SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto1");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier7SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier8SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier9SP";

			pchar.quest.Finally_Pellew_and_Wellesley2.win_condition.l1 = "location";
			pchar.quest.Finally_Pellew_and_Wellesley2.win_condition.l1.character = Pchar.id;
			pchar.quest.Finally_Pellew_and_Wellesley2.win_condition.l1.location = "Cuba_Shore_04";
			pchar.quest.Finally_Pellew_and_Wellesley2.win_condition = "Finally_Pellew_and_Wellesley2";
		break;

		case "Finally_Pellew_and_Wellesley2":
			DisableFastTravel(false);
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Cuba_Shore_04", "goto", "locator10");
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Cuba_Shore_04", "goto", "locator8");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Cuba_Shore_04", "officers", "reload1_2");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Cuba_Shore_04", "goto", "locator24");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Cuba_Shore_04", "goto", "locator9");
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			LAi_SetActorType(characterFromID("Arthur Wellesley"));

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Remember_the_crack_troops";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;

		case "Repair_to_Jamaica":
			Locations[FindLocation("Prison_Shore")].vcskip = false;
			Locations[FindLocation("Quest_ShipDeck6")].vcskip = false;
			CloseQuestHeader("The Duchess and the Devil");
			RestorePassengers("Blaze");
			SetCharacterRemovable(characterFromID("Midshipman Hunter"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Midshipman Hunter"));
			RemovePassenger(pchar, characterFromID("Midshipman Hunter"));
			SetCharacterRemovable(characterFromID("The Duchess of Wharfedale"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("The Duchess of Wharfedale"));
			RemovePassenger(pchar, characterFromID("The Duchess of Wharfedale"));
			SetQuestHeader("Land Battle");
			AddQuestRecord("Land Battle", 1);

			pchar.quest.Repair_to_Jamaica2.win_condition.l1 = "location";
			pchar.quest.Repair_to_Jamaica2.win_condition.l1.character = Pchar.id;
			pchar.quest.Repair_to_Jamaica2.win_condition.l1.location = "Redmond";
			pchar.quest.Repair_to_Jamaica2.win_condition = "Repair_to_Jamaica2";
		break;

		case "Repair_to_Jamaica2":
			Pchar.quest.Repair_to_Redmond_port.win_condition.l1 = "location";
			PChar.quest.Repair_to_Redmond_port.win_condition.l1.character = Pchar.id;
			Pchar.quest.Repair_to_Redmond_port.win_condition.l1.location = "Redmond Naval HQ";
			Pchar.quest.Repair_to_Redmond_port.win_condition = "Repair_to_Redmond_port";
		break;
// BATTLE
		case "Repair_to_Redmond_port":
			ChangeCharacterAddress(characterFromID("Styles"), "None", "");
			ChangeCharacterAddress(characterFromID("Matthews"), "None", "");
			ChangeCharacterAddress(characterFromID("Oldroyd"), "None", "");

			LAi_type_actor_Reset(characterFromID("William Chumley"));
			ChangeCharacterAddressGroup(characterFromID("William Chumley"), "Redmond Naval HQ", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Redmond Naval HQ", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Redmond Naval HQ", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Redmond Naval HQ", "goto", "goto2");
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto4", "Joining Forces", 10);
		break;

		case "Joining Forces":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Plan_for_crack_troops";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;

		case "Wellesley_joins_Troops":
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Defeat_crack_troops";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"), pchar, "", 1.0, 1.0);
		break;

		case "Pellew_gives_Ship":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Go_attack_crack_troops";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;

		case "Redmond_Sharpe_Chumley":
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"SchoonerWar","Magicienne",-1,FRANCE,true,true);
			DeleteAttribute(PChar, "isnotcaptain");
			SetCrewQuantity(pchar, 150);
			AddCharacterGoods(pchar, GOOD_BALLS, 500);
			AddCharacterGoods(pchar, GOOD_GRAPES, 300);
			AddCharacterGoods(pchar, GOOD_KNIPPELS, 200);
			AddCharacterGoods(pchar, GOOD_RUM, 10);
			AddCharacterGoods(pchar, GOOD_WHEAT, 20);

			LAi_SetActorType(pchar);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("William Chumley"));
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("William Chumley"), false);
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			LAi_ActorGoToLocator((Pchar), "reload", "reload1", "Redmond_Sharpe_Chumley2", 10);
		break;

		case "Redmond_Sharpe_Chumley2":
			LAi_SetPlayerType(Pchar);
			DoQuestReloadToLocation("Redmond_town_01", "reload", "door56", "Redmond_Sharpe_Chumley3");
		break;

		case "Redmond_Sharpe_Chumley3":
			AddQuestRecord("Land Battle", 2);
			Pchar.quest.Join_the_battle_company.win_condition.l1 = "location";
			PChar.quest.Join_the_battle_company.win_condition.l1.character = Pchar.id;
			Pchar.quest.Join_the_battle_company.win_condition.l1.location = "Falaise_de_fleur_shore";
			Pchar.quest.Join_the_battle_company.win_condition = "Join_the_battle_company";
		break;

		case "Join_the_battle_company":
			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemoveCharacterCompanion(Pchar, characterFromID("Richard Sharpe"));
			LAi_SetActorType(PChar);
		/*	GiveItem2Character(characterFromID("Richard Sharpe"), "pistol2");
			EquipCharacterByItem(characterFromID("Richard Sharpe"), "pistol2");
			GiveItem2Character(characterFromID("Rifleman Cooper"), "pistol2");
			EquipCharacterByItem(characterFromID("Rifleman Cooper"), "pistol2");
			GiveItem2Character(characterFromID("Rifleman Higgins"), "pistol2");
			EquipCharacterByItem(characterFromID("Rifleman Higgins"), "pistol2");
			GiveItem2Character(characterFromID("Rifleman Haggman"), "pistol2");
			EquipCharacterByItem(characterFromID("Rifleman Haggman"), "pistol2");
			GiveItem2Character(characterFromID("Rifleman Harris"), "pistol2");
			EquipCharacterByItem(characterFromID("Rifleman Harris"), "pistol2");
			GiveItem2Character(characterFromID("Rifleman Tongue"), "pistol2");
			EquipCharacterByItem(characterFromID("Rifleman Tongue"), "pistol2");
			GiveItem2Character(characterFromID("Patrick Harper"), "pistol5+2");
			EquipCharacterByItem(characterFromID("Patrick Harper"), "pistol5+2");*/

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "citizen06");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "citizen06");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG2B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "citizen06");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG3B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "citizen06");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG4B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "goto", "citizen06");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG5B";

			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Falaise_de_fleur_shore", "goto", "citizen06");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Falaise_de_fleur_shore", "goto", "citizen06");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Falaise_de_fleur_shore", "goto", "citizen06");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Falaise_de_fleur_shore", "goto", "citizen06");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Falaise_de_fleur_shore", "goto", "citizen06");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Falaise_de_fleur_shore", "goto", "citizen06");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Falaise_de_fleur_shore", "goto", "citizen06");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "reload2_2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier7X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "reload2_2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier8X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "reload2_2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier9X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "reload2_2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier10X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "reload2_2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier11X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "reload2_2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier12X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "reload2_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "reload2_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "reload2_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "reload2_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "reload2_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "reload2_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier6X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "reload2_1");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier13X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "reload2_1");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier14X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "reload2_1");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier15X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "reload2_1");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier16X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "reload2_1");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier17X";

			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("soldierG1B"));
			LAi_SetActorType(characterFromID("soldierG2B"));
			LAi_SetActorType(characterFromID("soldierG3B"));
			LAi_SetActorType(characterFromID("soldierG4B"));
			LAi_SetActorType(characterFromID("soldierG5B"));

			LAi_SetActorType(characterFromID("Soldier1X"));
			LAi_SetActorType(characterFromID("Soldier2X"));
			LAi_SetActorType(characterFromID("Soldier3X"));
			LAi_SetActorType(characterFromID("Soldier4X"));
			LAi_SetActorType(characterFromID("Soldier5X"));
			LAi_SetActorType(characterFromID("Soldier6X"));
			LAi_SetActorType(characterFromID("Soldier7X"));
			LAi_SetActorType(characterFromID("Soldier8X"));
			LAi_SetActorType(characterFromID("Soldier9X"));
			LAi_SetActorType(characterFromID("Soldier10X"));
			LAi_SetActorType(characterFromID("Soldier11X"));
			LAi_SetActorType(characterFromID("Soldier12X"));

			LAi_SetActorType(characterFromID("Soldier13X"));
			LAi_SetActorType(characterFromID("Soldier14X"));
			LAi_SetActorType(characterFromID("Soldier15X"));
			LAi_SetActorType(characterFromID("Soldier16X"));
			LAi_SetActorType(characterFromID("Soldier17X"));


			LAi_QuestDelay("Into_position_on_beach", 0.0);
		break;

		case "into_position_on_beach":
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Richard Sharpe"));
			LAi_ActorTurnToCharacter(characterFromID("William Chumley"), characterFromID("Richard Sharpe"));

			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "goto", "goto2", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "goto", "goto4", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "goto", "goto5", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "goto12", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto8", "",25.0);

			LAi_QuestDelay("Into_position_on_beach2", 5.0);
		break;

		case "into_position_on_beach2":
			LAi_ActorGoToLocator(characterFromID("soldierG1B"), "goto", "goto6", "",25.0);
			LAi_ActorGoToLocator(characterFromID("soldierG3B"), "goto", "goto3", "",25.0);
			LAi_ActorGoToLocator(characterFromID("soldierG5B"), "goto", "goto10", "",25.0);
			LAi_ActorGoToLocator(characterFromID("soldierG2B"), "goto", "goto9", "into_position_beach3",25.0);
			LAi_ActorGoToLocator(characterFromID("soldierG4B"), "goto", "goto7", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Harris"), "goto", "goto1", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "goto", "goto11", "",25.0);
		break;

		case "into_position_beach3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("William Chumley"));
			characters[GetCharacterIndex("William Chumley")].Dialog.Filename = "William Chumley_dialog.c";
			LAi_ActorDialog(characterFromID("William Chumley"), Pchar,"",5.0,5.0);
			Characters[GetCharacterIndex("William Chumley")].dialog.CurrentNode = "landed_at_French_Beach";
		break;

		case "Now_the_French":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "reload", "reload1_1", "Now_the_French2", 3.0);
		break;

		case "Now_the_French2":
			PlaySound("OBJECTS\DUEL\French_DrumsA.wav");
			LAi_ActorTurnToCharacter(characterFromID("William Chumley"), characterFromID("Rifleman Higgins"));
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Rifleman Harris"));

			LAi_ActorGoToLocator(characterFromID("Soldier7X"), "goto", "goto28", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier8X"), "goto", "goto29", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier9X"), "goto", "goto30", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier10X"), "goto", "goto31", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier11X"), "goto", "goto32", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier12X"), "goto", "goto33", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier1X"), "goto", "goto34", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier2X"), "goto", "goto35", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier3X"), "goto", "goto36", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier4X"), "goto", "goto25", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier5X"), "goto", "goto26", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier6X"), "goto", "goto27", "",0.0);

			LAi_ActorGoToLocator(characterFromID("Soldier13X"), "goto", "goto37", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier14X"), "goto", "goto38", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier15X"), "goto", "goto39", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier16X"), "goto", "goto40", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier17X"), "goto", "goto41", "",0.0);

			LAi_QuestDelay("French_are_coming", 30.0);
		break;

		case "French_are_coming":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("William Chumley"));
			characters[GetCharacterIndex("William Chumley")].Dialog.Filename = "William Chumley_dialog.c";
			LAi_ActorDialog(characterFromID("William Chumley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("William Chumley")].dialog.CurrentNode = "Prepare_for_Battle";
		break;

		case "Face_Off":
			LAi_SetActorType(PChar);

			LAi_ActorTurnToCharacter(characterFromID("Rifleman Cooper"), characterFromID("Soldier1X"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Haggman"), characterFromID("Soldier2X"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Harris"), characterFromID("Soldier3X"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Higgins"), characterFromID("Soldier4X"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Tongue"), characterFromID("Soldier5X"));
			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"), characterFromID("Soldier3X"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG1B"), characterFromID("Soldier11X"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG2B"), characterFromID("Soldier11X"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG3B"), characterFromID("Soldier11X"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG4B"), characterFromID("Soldier11X"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG5B"), characterFromID("Soldier11X"));
			LAi_ActorTurnToCharacter(characterFromID("Patrick Harper"), characterFromID("Soldier7X"));

			LAi_QuestDelay("Face_Off2", 0.0);
		break;

		case "Face_Off2":
			LAi_ActorTurnToCharacter(characterFromID("Soldier3X"), characterFromID("Rifleman Cooper"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier2X"), characterFromID("Rifleman Haggman"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier1X"), characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier4X"), characterFromID("Rifleman Higgins"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier5X"), characterFromID("Rifleman Tongue"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier6X"), characterFromID("Richard Sharpe"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier12X"), characterFromID("Rifleman Cooper"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier11X"), characterFromID("Rifleman Haggman"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier10X"), characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier9X"), characterFromID("Rifleman Higgins"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier8X"), characterFromID("Rifleman Tongue"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier7X"), characterFromID("Richard Sharpe"));

			LAi_ActorTurnToCharacter(characterFromID("Soldier13X"), characterFromID("Rifleman Cooper"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier14X"), characterFromID("Rifleman Haggman"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier15X"), characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier16X"), characterFromID("Rifleman Cooper"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier17X"), characterFromID("Rifleman Haggman"));

			LAi_QuestDelay("Skirmishers Out", 1.0);
		break;

		case "Skirmishers Out":
			LAi_SetImmortal(characterFromID("Richard Sharpe"), true);
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "locator13", "Skirmishers Out2",5.0);
			LAi_ActorRunToLocator(characterFromID("Patrick Harper"), "goto", "goto22", "",5.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Tongue"), "goto", "goto23", "",5.0);
		break;

		case "Skirmishers Out2":
			LAi_ActorGoToLocator((Pchar), "goto", "goto17", "", 5.0);
			LAi_ActorGoToLocator(characterFromID("William Chumley"), "goto", "goto12", "", 5.0);

			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"), characterFromID("Soldier6X"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Cooper"), characterFromID("Soldier1X"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Haggman"), characterFromID("Soldier2X"));
			LAi_ActorTurnToCharacter(characterFromID("Patrick Harper"), characterFromID("Soldier6X"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Tongue"), characterFromID("Soldier6X"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Higgins"), characterFromID("Soldier6X"));

			LAi_QuestDelay("Skirmishers Out3", 5.0);
		break;

		case "Skirmishers Out3":
			LAi_ActorTurnToCharacter(characterFromID("William Chumley"), characterFromID("Soldier11X"));
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Soldier11X"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG5B"), characterFromID("Soldier11X"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG2B"), characterFromID("Soldier11X"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG1B"), characterFromID("Soldier11X"));

			LAi_QuestDelay("Close for Battle", 5.0);
		break;

		case "Close for Battle":
			LAi_SetPlayerType(PChar);

			LAi_ActorAnimation(characterFromID("Soldier7X"), "shot", "Close for Battle2", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier7X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier8X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier8X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier9X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier9X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Close for Battle2":
			Lai_KillCharacter(characterFromID("SoldierG3B"));

			LAi_SetActorType(characterFromID("Soldier7X"));
			LAi_SetActorType(characterFromID("Soldier8X"));
			LAi_SetActorType(characterFromID("Soldier9X"));

			LAi_ActorAnimation(characterFromID("Soldier10X"), "shot", "Close for Battle3", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier10X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier11X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier11X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier12X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier12X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Close for Battle3":
			LAi_SetActorType(characterFromID("Soldier10X"));
			LAi_SetActorType(characterFromID("Soldier11X"));
			LAi_SetActorType(characterFromID("Soldier12X"));

			LAi_ActorAnimation(characterFromID("Soldier1X"), "shot", "Close for Battle4", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier1X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier2X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier2X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier3X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier3X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Close for Battle4":
			LAi_SetActorType(characterFromID("Soldier1X"));
			LAi_SetActorType(characterFromID("Soldier2X"));
			LAi_SetActorType(characterFromID("Soldier3X"));

			LAi_ActorAnimation(characterFromID("Soldier7X"), "shot", "Close for Battle5", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier7X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier8X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier8X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier9X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier9X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier4X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier4X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier5X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier5X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier6X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier6X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Close for Battle5":
			LAi_SetActorType(characterFromID("Soldier7X"));
			LAi_SetActorType(characterFromID("Soldier8X"));
			LAi_SetActorType(characterFromID("Soldier9X"));
			LAi_SetActorType(characterFromID("Soldier4X"));
			LAi_SetActorType(characterFromID("Soldier5X"));
			LAi_SetActorType(characterFromID("Soldier6X"));

			LAi_ActorAnimation(characterFromID("Soldier10X"), "shot", "Close for Battle6", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier10X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier11X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier11X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier12X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier12X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("SoldierG2B"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("SoldierG2B"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("SoldierG1B"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("SoldierG1B"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Higgins"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Higgins"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Haggman"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Haggman"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("William Chumley"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("William Chumley"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Patrick Harper"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Patrick Harper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Close for Battle6":
			LAi_SetActorType(characterFromID("Soldier10X"));
			LAi_SetActorType(characterFromID("Soldier11X"));
			LAi_SetActorType(characterFromID("Soldier12X"));
			LAi_SetActorType(characterFromID("SoldierG1B"));
			LAi_SetActorType(characterFromID("SoldierG2B"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("William Chumley"));
			LAi_SetActorType(characterFromID("Rifleman Higgins"));

			LAi_ActorAnimation(characterFromID("Soldier1X"), "shot", "Close for Battle7", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier1X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier2X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier2X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier3X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier3X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Close for Battle7":
			Lai_KillCharacter(characterFromID("Soldier13X"));
			Lai_KillCharacter(characterFromID("Soldier17X"));

			LAi_SetActorType(characterFromID("Soldier1X"));
			LAi_SetActorType(characterFromID("Soldier2X"));
			LAi_SetActorType(characterFromID("Soldier3X"));

			LAi_ActorAnimation(characterFromID("Richard Sharpe"), "shot", "Close for Battle8", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Richard Sharpe"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Tongue"), "shot", "", 2.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Tongue"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_SetActorType(PChar);
			EquipCharacterByItem(Pchar, "pistol1");
			LAi_ActorAnimation(Pchar, "shot", "", 2.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(Pchar, &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Cooper"), "shot", "", 2.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Cooper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Harris"), "shot", "", 2.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Harris"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier9X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier9X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier8X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier8X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier7X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier7X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			
			LAi_ActorAnimation(characterFromID("SoldierG4B"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("SoldierG4B"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("SoldierG5B"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("SoldierG5B"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Close for Battle8":
			LAi_SetActorType(PChar);
			LAi_SetActorType(characterFromID("Soldier9X"));
			LAi_SetActorType(characterFromID("Soldier8X"));
			LAi_SetActorType(characterFromID("Soldier7X"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));
			LAi_SetActorType(characterFromID("SoldierG5B"));
			LAi_SetActorType(characterFromID("SoldierG4B"));

			LAi_ActorAnimation(characterFromID("Soldier4X"), "shot", "Close for Battle9", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier4X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier5X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier5X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier6X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier6X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Close for Battle9":
			LAi_SetActorType(characterFromID("Soldier4X"));
			LAi_SetActorType(characterFromID("Soldier5X"));
			LAi_SetActorType(characterFromID("Soldier6X"));

			LAi_ActorAnimation(characterFromID("Soldier12X"), "shot", "Close for Battle10", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier12X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier11X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier11X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier10X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier10X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("SoldierG1B"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("SoldierG1B"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Higgins"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Higgins"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Haggman"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Haggman"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("William Chumley"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("William Chumley"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("SoldierG2B"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("SoldierG2B"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Patrick Harper"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Patrick Harper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Close for Battle10":
			Lai_KillCharacter(characterFromID("SoldierG5B"));

			LAi_SetActorType(characterFromID("Soldier12X"));
			LAi_SetActorType(characterFromID("Soldier11X"));
			LAi_SetActorType(characterFromID("Soldier10X"));
			LAi_SetActorType(characterFromID("SoldierG1B"));
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("William Chumley"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("SoldierG2B"));
			LAi_SetActorType(characterFromID("SoldierG1B"));

			LAi_ActorGoToLocator(characterFromID("Soldier4X"), "goto", "goto51", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier5X"), "goto", "goto52", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier6X"), "goto", "goto53", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier3X"), "goto", "goto45", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier7X"), "goto", "goto54", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier1X"), "goto", "citizen08", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier2X"), "goto", "goto45", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier8X"), "goto", "goto44", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier9X"), "goto", "goto44", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier11X"), "goto", "goto45", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier10X"), "goto", "goto46", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier12X"), "goto", "goto51", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier14X"), "goto", "goto44", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier15X"), "goto", "citizen08", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier16X"), "goto", "goto15", "",0.0);

			LAi_QuestDelay("deaths occur", 3.0);
		break;

		case "deaths occur":
			Lai_KillCharacter(characterFromID("Soldier16X"));
			Lai_KillCharacter(characterFromID("Soldier14X"));
			Lai_KillCharacter(characterFromID("Soldier10X"));

			LAi_ActorAnimation(characterFromID("Richard Sharpe"), "shot", "gunsounds", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Richard Sharpe"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Tongue"), "shot", "", 2.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Tongue"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_SetActorType(PChar);
			EquipCharacterByItem(Pchar, "pistol1");
			LAi_ActorAnimation(Pchar, "shot", "", 2.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(Pchar, &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Cooper"), "shot", "", 2.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Cooper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Harris"), "shot", "", 2.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Harris"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "gunsounds":
			LAi_SetActorType(PChar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));

			LAi_ActorAnimation(characterFromID("Patrick Harper"), "shot", "gunsounds2", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Patrick Harper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "gunsounds2":
			Lai_KillCharacter(characterFromID("Soldier9X"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_QuestDelay("gunsounds3", 0.0);
		break;

		case "gunsounds3":
			Lai_KillCharacter(characterFromID("Soldier15X"));
			LAi_ActorAnimation(characterFromID("SoldierG4B"), "Lay_1", "", -1);

			LAi_ActorAnimation(characterFromID("SoldierG1B"), "shot", "gunsounds4", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("SoldierG1B"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Haggman"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Haggman"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("William Chumley"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("William Chumley"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Rifleman Cooper"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Cooper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Patrick Harper"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Patrick Harper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "gunsounds4":
			Lai_KillCharacter(characterFromID("Soldier3X"));

			LAi_SetActorType(characterFromID("SoldierG1B"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("William Chumley"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));

			LAi_ActorAnimation(characterFromID("Rifleman Tongue"), "shot", "gunsounds5", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Tongue"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "gunsounds5":
			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"), characterFromID("Patrick Harper"));
			LAi_ActorTurnToCharacter(characterFromID("Patrick Harper"), characterFromID("Richard Sharpe"));
			LAi_SetStunnedTypeNoGroup(characterFromID("SoldierG2B"));

			LAi_SetActorType(characterFromID("Rifleman Tongue"));

			LAi_ActorAnimation(characterFromID("Patrick Harper"), "shot", "deaths occur3", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Patrick Harper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Richard Sharpe"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Richard Sharpe"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier1X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier1X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier11X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier11X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier2X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier2X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier5X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier5X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier7X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier7X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier8X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier8X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("William Chumley"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("William Chumley"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "deaths occur3":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("William Chumley"));
			LAi_SetActorType(characterFromID("Soldier1X"));
			LAi_SetActorType(characterFromID("Soldier11X"));
			LAi_SetActorType(characterFromID("Soldier2X"));
			LAi_SetActorType(characterFromID("Soldier5X"));
			LAi_SetActorType(characterFromID("Soldier7X"));
			LAi_SetActorType(characterFromID("Soldier8X"));

			Lai_KillCharacter(characterFromID("SoldierG1B"));

			LAi_QuestDelay("First_Volley", 0.0);
		break;

		case "First_Volley":
			LAi_SetPlayerType(PChar);
			LAi_SetImmortal(characterFromID("William Chumley"), true);
//			LAi_SetImmortal(characterFromID("Rifleman Tongue"), true);
			LAi_SetImmortal(characterFromID("Rifleman Cooper"), true);

			LAi_group_MoveCharacter(characterFromID("Richard Sharpe"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Cooper"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Patrick Harper"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Higgins"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Haggman"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Tongue"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("William Chumley"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Harris"), LAI_GROUP_PLAYER);

			LAi_group_MoveCharacter(characterFromID("Soldier1X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier1X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier2X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier4X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier4X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier5X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier5X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier6X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier6X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier7X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier7X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier8X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier8X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier11X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier11X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier12X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier12X"), "FRANCE_SOLDIERS");

			LAi_QuestDelay("attack", 2.0);
		break;

		case "attack":
			LAi_SetActorType(characterFromID("Soldier6X"));
			LAi_ActorAttack(characterFromID("Soldier6X"),(Pchar), "");

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "battleover");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "KilledFighting": // GAME OVER
			pchar.quest.disable_rebirth = true
			PostEvent("LAi_event_GameOver", 0, "s", "land");
		break;

		case "battleover":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_SetOfficerType(characterFromID("William Chumley"));

			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));

			LAi_QuestDelay("battle over2", 2.0);
		break;

		case "battle over2":
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto8", "battle over3",5.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "goto", "goto7", "",5.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "goto", "goto6", "",5.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "goto5", "",5.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "goto", "goto4", "",5.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "goto", "goto3", "",5.0);
		break;

		case "battle over3":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			LAi_SetActorType(characterFromID("William Chumley"));
			characters[GetCharacterIndex("William Chumley")].Dialog.Filename = "William Chumley_dialog.c";
			LAi_ActorDialog(characterFromID("William Chumley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("William Chumley")].dialog.CurrentNode = "French_Battle_over";
		break

		case "Battle_over_now_Redmond":
			LAi_ActorGoToLocator(characterFromID("William Chumley"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "goto", "citizen06", "",25.0);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "You_lost_a_friend";
		break;

		case "Back_to_ship_and_Oxbay":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			AddQuestRecord("Land Battle", 3);
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");

			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("William Chumley"));

			Pchar.quest.wounded_to_Oxbay.win_condition.l1 = "location";
			PChar.quest.wounded_to_Oxbay.win_condition.l1.character = Pchar.id;
			Pchar.quest.wounded_to_Oxbay.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.wounded_to_Oxbay.win_condition = "wounded_to_Oxbay";
		break;

		case "wounded_to_Oxbay":
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Oxbay_port", "goto", "goto28");

			LAi_SetOfficerType(characterFromID("Sir Edward Pellew"));

			LAi_SetActorType(characterFromID("William Chumley"));
			characters[GetCharacterIndex("William Chumley")].Dialog.Filename = "William Chumley_dialog.c";
			LAi_ActorDialog(characterFromID("William Chumley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("William Chumley")].dialog.CurrentNode = "Battle_over_now_Oxbay";
		break;

		case "Pellew_sends_you_to_Greenford":
			LAi_ActorGoToLocator(characterFromID("William Chumley"), "reload", "reload1", "",25.0);

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Transferred_to_Sawyer";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;
// MUTINY
		case "Find_Kennedy_in_Tavern":
			CloseQuestHeader("Land Battle");
			SetQuestHeader("Mutiny");
			AddQuestRecord("Mutiny", 1);
			PChar.isnotcaptain = true;
			ChangeCharacterAddress(characterFromID("William Chumley"), "None", "");
			LAi_ActorGoToLocator(characterFromID("Sir Edward Pellew"), "reload", "reload1", "",25.0);
			SetCharacterRemovable(characterFromID("William Chumley"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("William Chumley"));
			RemoveCharacterCompanion(Pchar, characterFromID("William Chumley"));
			RemovePassenger(pchar, characterFromID("William Chumley"));

			Characters[GetCharacterIndex("Archie Kennedy")].model = "Kennedy_Lt";
			Characters[GetCharacterIndex("Archie Kennedy")].headmodel = "h_Kennedy_Lt";

			Pchar.quest.Kennedy_in_Oxbay.win_condition.l1 = "location";
			PChar.quest.Kennedy_in_Oxbay.win_condition.l1.character = Pchar.id;
			Pchar.quest.Kennedy_in_Oxbay.win_condition.l1.location = "Oxbay_tavern";
			Pchar.quest.Kennedy_in_Oxbay.win_condition = "Kennedy_in_Oxbay";
		break;

		case "Kennedy_in_Oxbay":
			ChangeCharacterAddressGroup(characterfromID("Archie Kennedy"), "Oxbay_tavern", "goto", "goto21");
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "Oxbay_meet_after_Battle";
		break;

		case "Go_to_Greenford_town":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Archie Kennedy"));
			SetCharacterRemovable(characterFromID("Archie Kennedy"), false);
			pchar.quest.Soldier_Company = "Sergeant";
			SetModelfromArray(characterFromID("Richard Sharpe"), GetModelIndex("SharpeS_Rif8_18"));
			Characters[GetCharacterIndex("Richard Sharpe")].headmodel = "h_SharpeS_Rif8_18";

			Pchar.quest.Broken_Quest.win_condition.l1 = "NPC_death";
			Pchar.quest.Broken_Quest.win_condition.l1.character = "Archie Kennedy";
			Pchar.quest.Broken_Quest.win_condition = "Broken_Quest";

			Pchar.quest.Sawyer_in_Greenford.win_condition.l1 = "location";
			PChar.quest.Sawyer_in_Greenford.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sawyer_in_Greenford.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Sawyer_in_Greenford.win_condition = "Sawyer_in_Greenford";
		break;

		case "Sawyer_in_Greenford":
			LAi_type_actor_Reset(characterFromID("Captain James Sawyer"));
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"RN_Superbe","Renown",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Greenford_port");

			ChangeCharacterAddressGroup(characterFromID("Henry Wellard"), "Greenford_town", "reload", "reload21");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Greenford_town", "goto", "goto30");
			LAi_SetOfficerType(characterFromID("Henry Wellard"));

			LAi_QuestDelay("First_meet_Wellard", 0.0);
		break;

		case "First_meet_Wellard":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto37", "", 30);
			characters[GetCharacterIndex("Henry Wellard")].Dialog.Filename = "Henry Wellard_dialog.c";
			LAi_SetActorType(characterFromID("Henry Wellard"));
			LAi_ActorDialog(characterFromID("Henry Wellard"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Henry Wellard")].dialog.currentnode = "Can_you_help";
		break;

		case "Wellard_in_tow": // Triggered by dialog with Henry Wellard
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Henry Wellard")].dialog.currentnode = "First time";
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Henry Wellard"));
			SetCharacterRemovable(characterFromID("Henry Wellard"), false);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "A_new_detachment";
		break;

		case "Wellard_in_tow2":
			AddQuestRecord("Mutiny", 2);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorGoToLocation(characterFromID("Richard Sharpe"), "reload", "reload19", "none", "", "", "", 0.0);
			SetModelfromArray(characterFromID("Captain James Sawyer"), GetModelIndex("Sawyer2_18"));
			Characters[GetCharacterIndex("Captain James Sawyer")].headmodel = "h_Sawyer2_18";

			Pchar.quest.Sawyer_in_Greenford2.win_condition.l1 = "location";
			PChar.quest.Sawyer_in_Greenford2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sawyer_in_Greenford2.win_condition.l1.location = "Greenford Naval HQ";
			Pchar.quest.Sawyer_in_Greenford2.win_condition = "Sawyer_in_Greenford2";
		break;

		case "Sawyer_in_Greenford2":
			ChangeCharacterAddressGroup(characterFromID("Captain James Sawyer"), "Greenford Naval HQ", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Doctor Clive"), "Greenford Naval HQ", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Greenford Naval HQ", "goto", "desk");
			ChangeCharacterAddressGroup(characterFromID("Henry Wellard"), "Greenford Naval HQ", "goto", "goto5");
			LAi_SetOfficerType(characterFromID("Henry Wellard"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto4", "Join_Sawyer_Renown", 10);
		break;

		case "Join_Sawyer_Renown":
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Hornblower_Greenford";
		break;

		case "Prepare_to_board_the_Renown":
			Pchar.quest.After_Sawyer_in_Greenford.win_condition.l1 = "location";
			PChar.quest.After_Sawyer_in_Greenford.win_condition.l1.character = Pchar.id;
			Pchar.quest.After_Sawyer_in_Greenford.win_condition.l1.location = "Greenford_town";
			Pchar.quest.After_Sawyer_in_Greenford.win_condition = "After_Sawyer_in_Greenford";
		break;

		case "After_Sawyer_in_Greenford":
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "Greenford_after_Sawyer";
		break;

		case "Board_the_Renown":
			AddQuestRecord("Mutiny", 4);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "First time";
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			pchar.quest.Board_the_Renown2.win_condition.l1 = "locator";
			pchar.quest.Board_the_Renown2.win_condition.l1.location = "Greenford_port";
			pchar.quest.Board_the_Renown2.win_condition.l1.locator_group = "reload";
			pchar.quest.Board_the_Renown2.win_condition.l1.locator = "reload1_back";
			pchar.quest.Board_the_Renown2.win_condition = "Board_the_Renown2";
		break;

		case "Board_the_Renown2":
			SetCharacterRemovable(characterFromID("Archie Kennedy"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Archie Kennedy"));
			RemoveCharacterCompanion(Pchar, characterFromID("Archie Kennedy"));
			SetCharacterRemovable(characterFromID("Henry Wellard"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Henry Wellard"));
			RemoveCharacterCompanion(Pchar, characterFromID("Henry Wellard"));
			DoQuestReloadToLocation("Quest_ShipDeck6XX", "reload", "boatl", "On_board_the_Renown");

			Pchar.Quest.Broken_Quest.over = "yes"; // GR: Cancel check for Kennedy's death
		break;

		case "On_board_the_Renown":
			ChangeCharacterAddressGroup(characterfromID("Archie Kennedy"), "Quest_ShipDeck6XX", "goto", "goto11");
			ChangeCharacterAddressGroup(characterfromID("Henry Wellard"), "Quest_ShipDeck6XX", "goto", "goto4");
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_SetOfficerType(characterFromID("Henry Wellard"));
			ChangeCharacterAddressGroup(characterfromID("Matthews"), "Quest_ShipDeck6XX", "goto", "goto13");
			ChangeCharacterAddressGroup(characterfromID("Oldroyd"), "Quest_ShipDeck6XX", "goto", "goto2");
			ChangeCharacterAddressGroup(characterfromID("Marsh"), "Quest_ShipDeck6XX", "goto", "goto12");
			ChangeCharacterAddressGroup(characterfromID("Perrin"), "Quest_ShipDeck6XX", "goto", "goto5");
			ChangeCharacterAddressGroup(characterfromID("Helmsman"), "Quest_ShipDeck6XX", "rld", "wheel");
			ChangeCharacterAddressGroup(characterfromID("Rifleman Haggman"), "Quest_ShipDeck6XX", "goto", "marine1");
			ChangeCharacterAddressGroup(characterfromID("Rifleman Tongue"), "Quest_ShipDeck6XX", "goto", "marine5");
			ChangeCharacterAddressGroup(characterfromID("Rifleman Cooper"), "Quest_ShipDeck6XX", "goto", "goto16");
			ChangeCharacterAddressGroup(characterfromID("Rifleman Higgins"), "Quest_ShipDeck6XX", "reload", "reload1");
			ChangeCharacterAddressGroup(characterfromID("Patrick Harper"), "Quest_ShipDeck6XX", "reload", "reload3");
			ChangeCharacterAddressGroup(characterfromID("Lt. Percy Buckland"), "Quest_ShipDeck6XX", "goto", "goto3");

			characters[GetCharacterIndex("Henry Wellard")].Dialog.Filename = "Henry Wellard_dialog.c";
			LAi_SetActorType(characterFromID("Henry Wellard"));
			LAi_ActorDialog(characterFromID("Henry Wellard"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Henry Wellard")].dialog.currentnode = "Any_orders";
		break;

		case "Boat_coming_alongside":
			LAi_ActorGoToLocator(characterFromID("Henry Wellard"), "goto", "goto6", "", 0.0);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto19", "Boat_coming_alongside2", 5.0);
		break;

		case "Boat_coming_alongside2":
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(characterfromID("Lt. William Bush"), "Quest_ShipDeck6XX", "reload", "boatl");

			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "Boat_alongside";
		break;

		case "Lt_Bush_Arrives":
			LAi_ActorGoToLocation(characterFromID("Archie Kennedy"), "reload", "reload2", "none", "", "", "", 0.0);

			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "First_meeting_Greenford";
		break;

		case "captain_Sawyer_arrives_Greenford":
			AddQuestRecord("Mutiny", 5);
			LAi_ActorGoToLocation(characterFromID("Lt. William Bush"), "reload", "reload2", "none", "", "", "",0.0);
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));

			Pchar.quest.Day_one_the_Renown.win_condition.l1 = "locator";
			Pchar.quest.Day_one_the_Renown.win_condition.l1.character = Pchar.id;
			Pchar.quest.Day_one_the_Renown.win_condition.l1.location = "Quest_ShipDeck6XX";
			Pchar.quest.Day_one_the_Renown.win_condition.l1.locator_group = "goto";
			Pchar.quest.Day_one_the_Renown.win_condition.l1.locator = "goto15";
			Pchar.quest.Day_one_the_Renown.win_condition = "Day_one_the_Renown";
		break;

		case "Day_one_the_Renown":
			PlaySound("OBJECTS\shipcharge\Eng_the_side.wav");
			LAi_ActorRunToLocator(characterFromID("Rifleman Cooper"), "goto", "marine2", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Higgins"), "goto", "marine3", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Patrick Harper"), "goto", "marine4", "Day_one_the_Renown2", 0.0);
			LAi_ActorRunToLocator(characterFromID("Lt. Percy Buckland"), "goto", "goto19", "", 0.0);
			ChangeCharacterAddressGroup(characterfromID("Lt. William Bush"), "Quest_ShipDeck6XX", "goto", "goto20");
			ChangeCharacterAddressGroup(characterfromID("Archie Kennedy"), "Quest_ShipDeck6XX", "goto", "goto22");
			ChangeCharacterAddressGroup(characterFromID("Captain James Sawyer"), "Quest_ShipDeck6XX", "goto", "goto4");
			LAi_QuestDelay("Day_one_the_Renown2", 0.0);
		break;

		case "Day_one_the_Renown2":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(characterFromID("Captain James Sawyer"), "reload", "boatl", "", 0.0);
			LAi_ActorRunToLocator((Pchar), "goto", "goto21", "Day_one_the_Renown3", 15.0);
			LAi_QuestDelay("Day_one_the_Renown3", 15.0);
		break;

		case "Day_one_the_Renown3":
			LAi_ActorTurnToCharacter(characterFromID("Lt. William Bush"), characterFromID("Captain James Sawyer"));
			LAi_ActorTurnToCharacter(characterFromID("Lt. Percy Buckland"), characterFromID("Captain James Sawyer"));
			LAi_ActorTurnToCharacter(characterFromID("Archie Kennedy"), characterFromID("Captain James Sawyer"));
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Captain James Sawyer"));
			LAi_QuestDelay("Day_one_the_Renown4", 2.0);
		break;

		case "Day_one_the_Renown4":
			LAi_SetPlayerType(pchar);
			LAi_ActorGoToLocator(characterFromID("Captain James Sawyer"), "goto", "goto23", "Sawyer_sees_Bush", 2.0);
		break;

		case "Sawyer_sees_Bush":
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Bush_on_board";
		break;

		case "Bush_reply1":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Bush_Sawyer_Reply1";
		break;

		case "Sawyer_answer2":
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Bush_reported";
		break;

		case "Sawyer_Buckland_question":
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "Sawyer_to_Buckland";
		break;

		case "Sawyer_again_Bush":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Bush_Sawyer_Reply2";
		break;

		case "Sawyer_answer3":
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Get_the_ship_underway";
		break;

		case "Ship_makes_sail":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "marine4", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Archie Kennedy"), "goto", "marine4", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Captain James Sawyer"), "goto", "marine3", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Lt. Percy Buckland"), "goto", "marine2", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Lt. William Bush"), "goto", "marine1", "", 0.0);
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "goto", "goto9", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "goto", "goto10", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "goto", "goto18", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "goto", "goto16", "", 0.0);
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Matthews"));
			LAi_SetActorType(characterFromID("Oldroyd"));
			LAi_SetActorType(characterFromID("Marsh"));
			LAi_SetActorType(characterFromID("Perrin"));
			LAi_ActorGoToLocator(characterFromID("Matthews"), "goto", "goto23", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Oldroyd"), "goto", "goto20", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Marsh"), "goto", "goto19", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Perrin"), "goto", "goto22", "", 0.0);
			LAi_QuestDelay("Ship_makes_sail2", 20.0);
		break;

		case "Ship_makes_sail2":
			LAi_SetPlayerType(pchar);

			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Hoist_the_mainsail";
		break;

		case "Off_to_sea_Sawyer":
			LAi_Fade("","");
			SetNextWeather("Stormy");
			DoQuestReloadToLocation("Quest_ShipDeck6XX", "goto", "marine1", "Off_to_sea_Sawyer2");
		break;

		case "Off_to_sea_Sawyer2":
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			ChangeCharacterAddressGroup(characterfromID("Matthews"), "Quest_ShipDeck6XX", "goto", "goto23");
			ChangeCharacterAddressGroup(characterfromID("Oldroyd"), "Quest_ShipDeck6XX", "goto", "goto20");
			ChangeCharacterAddressGroup(characterfromID("Marsh"), "Quest_ShipDeck6XX", "goto", "goto19");
			ChangeCharacterAddressGroup(characterfromID("Perrin"), "Quest_ShipDeck6XX", "goto", "goto22");

			SetCurrentTime(10.00, 0);
			ChangeCharacterAddress(characterFromID("Captain James Sawyer"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. Percy Buckland"), "None", "");
			ChangeCharacterAddressGroup(characterfromID("Lt. William Bush"), "Quest_ShipDeck6XX", "reload", "reload1");
			ChangeCharacterAddressGroup(characterfromID("Archie Kennedy"), "Quest_ShipDeck6XX", "goto", "marine2");


			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "The_captain_is_odd";
		break;

		case "Bush_comes_over":
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));

			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "What_are_you_talking_about";
		break;

		case "we_will_see_in_the_morning":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "marine5", "", 0.0);
			
			LAi_QuestDelay("we_will_see_in_the_morning2", 5.0);
		break;

		case "we_will_see_in_the_morning2":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "More_than_a_breeze";
		break;

		case "Go_get_Captain_Sawyer":
			LAi_ActorGoToLocator(characterFromID("Archie Kennedy"), "reload", "reload1", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Lt. William Bush"), "goto", "marine4", "", 0.0);
			ChangeCharacterAddressGroup(characterfromID("Henry Wellard"), "Quest_ShipDeck6XX", "rig", "rigging1");
			ChangeCharacterAddressGroup(characterfromID("Captain James Sawyer"), "Quest_ShipDeck6XX", "reload", "reload1");
			LAi_QuestDelay("Go_get_Captain_Sawyer2", 2.0);
		break;

		case "Go_get_Captain_Sawyer2":
			LAi_ActorGoToLocator(characterFromID("Archie Kennedy"), "goto", "marine2", "", 2.0);
			LAi_ActorGoToLocator(characterFromID("Captain James Sawyer"), "goto", "marine3", "", 2.0);

			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "So_you_want_to_get_sail_off";
		break;

		case "Wellard_stops_the_hoist":
			characters[GetCharacterIndex("Henry Wellard")].Dialog.Filename = "Henry Wellard_dialog.c";
			LAi_SetActorType(characterFromID("Henry Wellard"));
			LAi_ActorDialog(characterFromID("Henry Wellard"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Henry Wellard")].dialog.currentnode = "Stop_the_hoist";
		break;

		case "Sawyer_reacts":
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Who_countermands_my_orders";
		break;

		case "Wellard_in_trouble":
			characters[GetCharacterIndex("Henry Wellard")].Dialog.Filename = "Henry Wellard_dialog.c";
			LAi_SetActorType(characterFromID("Henry Wellard"));
			Characters[GetCharacterIndex("Henry Wellard")].dialog.currentnode = "It_is_me_sir";
			LAi_ActorDialogNow(characterFromID("Henry Wellard"),PChar,"",1.0);
		break;

		case "Sawyer_reacts2":
			SetNextWeather("Clear");
			Locations[FindLocation("Seadogs")].vcskip = true;
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_SetActorType(characterFromID("Captain James Sawyer"));
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Wellard_is_it";
		break;

		case "The_beating_of_Wellard":
			DoQuestReloadToLocation("Seadogs", "goto", "goto3", "The_beating_of_Wellard2");
		break;

		case "The_beating_of_Wellard2":
			SetNextWeather("Blue Sky");
			AddQuestRecord("Mutiny", 3);
			SetCurrentTime(14.00, 0);
			ChangeCharacterAddressGroup(characterfromID("Doctor Clive"), "Seadogs", "goto", "goto2");

			characters[GetCharacterIndex("Doctor Clive")].Dialog.Filename = "Doctor Clive_dialog.c";
			LAi_SetActorType(characterFromID("Doctor Clive"));
			LAi_ActorDialog(characterFromID("Doctor Clive"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Doctor Clive")].dialog.currentnode = "Wellard_is_fine";
		break;

		case "Discuss_the_Captain_again":
			setCharacterShipLocation(Pchar, "Cuba_Shore_04");
			DoQuestReloadToLocation("Quest_ShipDeck6XX", "goto", "marine2", "Discuss_the_Captain_again2");
		break;

		case "Discuss_the_Captain_again2":
			ChangeCharacterAddress(characterFromID("Henry Wellard"), "None", "");
			ChangeCharacterAddressGroup(characterfromID("Archie Kennedy"), "Quest_ShipDeck6XX", "goto", "goto10");
			ChangeCharacterAddressGroup(characterfromID("Lt. William Bush"), "Quest_ShipDeck6XX", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Patrick Harper"), "Quest_ShipDeck6XX", "reload", "reload3");

			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "How_is_Wellard";
		break;

		case "Bush_calls_to_Meeting":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Captains_meeting";
		break;

		case "Go_to_Captains_Meeting":
			ChangeCharacterAddressGroup(characterfromID("Lt. Percy Buckland"), "Cabin4", "officers", "officer7");
			ChangeCharacterAddressGroup(characterfromID("Captain James Sawyer"), "Cabin4", "officers", "officer5");
			ChangeCharacterAddressGroup(characterfromID("Doctor Clive"), "Cabin4", "officers", "officer3");

			Pchar.quest.Go_to_Captains_Meeting2.win_condition.l1 = "location";
			PChar.quest.Go_to_Captains_Meeting2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Go_to_Captains_Meeting2.win_condition.l1.location = "Cabin4";
			Pchar.quest.Go_to_Captains_Meeting2.win_condition = "Go_to_Captains_Meeting2";
		break;

		case "Go_to_Captains_Meeting2":
			SetCurrentTime(23.00, 0);
			ChangeCharacterAddressGroup(characterfromID("Archie Kennedy"), "Cabin4", "officers", "reload1_3");
			ChangeCharacterAddressGroup(characterfromID("Lt. William Bush"), "Cabin4", "officers", "officer4");
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "officers", "reload1_1", "Go_to_Captains_Meeting3", 15.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Sail_to_Cuba";
		break;

		case "Go_to_Captains_Meeting3":
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_ActorDialogNow(characterFromID("Captain James Sawyer"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Sail_to_Cuba";

			Characters[GetCharacterIndex("Lt. William Bush")].dialog.currentnode = "About_Sail_to_Cuba";
		break;

		case "Bush_chimes_in":
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. William Bush"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.currentnode = "About_Sail_to_Cuba";

			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Plotting";
		break;

		case "The_Doctor_Speaks":
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_ActorDialogNow(characterFromID("Captain James Sawyer"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "Plotting";

			Characters[GetCharacterIndex("Doctor Clive")].dialog.currentnode = "Please_leave";
		break;

		case "The_Doctor_Speaks2":
			characters[GetCharacterIndex("Doctor Clive")].Dialog.Filename = "Doctor Clive_dialog.c";
			LAi_ActorDialogNow(characterFromID("Doctor Clive"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Doctor Clive"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Doctor Clive")].dialog.currentnode = "Please_leave";
		break;

		case "Leaving_the_captain":
			LAi_Fade("", "");
			DoQuestReloadToLocation("Quest_ShipDeck6XX", "goto", "goto10", "Talk_with_officers");
		break;

		case "Talk_with_officers":
			ChangeCharacterAddressGroup(characterfromID("Archie Kennedy"), "Quest_ShipDeck6XX", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Lt. William Bush"), "Quest_ShipDeck6XX", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Lt. Percy Buckland"), "Quest_ShipDeck6XX", "goto", "goto9");
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetOfficerType(characterFromID("Lt. Percy Buckland"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));

			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "The_captain_is_worse";
			break;

		case "Talk_with_officers2":
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "Buckland_says_Laudanum";
		break;

		case "Talk_with_officers3":
			ChangeCharacterAddressGroup(characterfromID("Henry Wellard"), "Quest_ShipDeck6XX", "goto", "goto3");
			ChangeCharacterAddressGroup(characterfromID("Captain James Sawyer"), "Quest_ShipDeck6XX", "reload", "reload1");
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Mutiny_meeting";
		break;

		case "Just_me_and_Archie":
			ChangeCharacterAddress(characterFromID("Matthews"), "None", "");
			ChangeCharacterAddress(characterFromID("Oldroyd"), "None", "");
			ChangeCharacterAddress(characterFromID("Marsh"), "None", "");
			ChangeCharacterAddress(characterFromID("Perrin"), "None", "");

			LAi_SetOfficerType(characterFromID("Henry Wellard"));
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			LAi_ActorGoToLocator(characterFromID("Lt. William Bush"), "goto", "goto18", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Lt. Percy Buckland"), "goto", "goto8", "", 0.0);

			LAi_SetActorType(characterFromID("Henry Wellard"));
			characters[GetCharacterIndex("Henry Wellard")].Dialog.Filename = "Henry Wellard_dialog.c";
			LAi_ActorDialog(characterFromID("Henry Wellard"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Henry Wellard")].dialog.CurrentNode = "Mutiny_meeting_wellard";
		break;

		case "Move_down_to_deck":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "reload", "boatl", "Move_down_to_deck2", 15.0);
			LAi_ActorGoToLocator(characterFromID("Archie Kennedy"), "goto", "goto19", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Henry Wellard"), "goto", "goto11", "", 0.0);
		break;

		case "Move_down_to_deck2":
			LAi_SetPlayerType(pchar);
			LAi_ActorGoToLocator(characterFromID("Captain James Sawyer"), "goto", "goto22", "Move_down_to_deck3", 20.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "I_Know_youre_here";
		break;

		case "Move_down_to_deck3":
			characters[GetCharacterIndex("Captain James Sawyer")].Dialog.Filename = "Captain James Sawyer_dialog.c";
			LAi_ActorDialogNow(characterFromID("Captain James Sawyer"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Captain James Sawyer"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain James Sawyer")].dialog.currentnode = "I_Know_youre_here";
		break;

		case "Captain_falls_in_the_Hold":
			SetCurrentTime(10.00, 0);
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_06.wav");
			Lai_KillCharacter(characterFromID("Captain James Sawyer"));
			LAi_QuestDelay("Captain_falls_in_the_Hold2", 2.0);
		break;

		case "Captain_falls_in_the_Hold2":
			LAi_Fade("", "");
			DoQuestReloadToLocation("Quest_ShipDeck6XX", "goto", "marine1", "After_the_Fall");
		break;

		case "After_the_Fall":
			ChangeCharacterAddressGroup(characterfromID("Matthews"), "Quest_ShipDeck6XX", "goto", "goto23");
			ChangeCharacterAddressGroup(characterfromID("Oldroyd"), "Quest_ShipDeck6XX", "goto", "goto20");
			ChangeCharacterAddressGroup(characterfromID("Marsh"), "Quest_ShipDeck6XX", "goto", "goto19");
			ChangeCharacterAddressGroup(characterfromID("Perrin"), "Quest_ShipDeck6XX", "goto", "goto22");
			ChangeCharacterAddress(characterFromID("Captain James Sawyer"), "None", "");
			ChangeCharacterAddress(characterFromID("Henry Wellard"), "None", "");
			ChangeCharacterAddressGroup(characterfromID("Lt. Percy Buckland"), "Quest_ShipDeck6XX", "goto", "marine2");
			ChangeCharacterAddressGroup(characterfromID("Lt. William Bush"), "Quest_ShipDeck6XX", "goto", "marine3");
			ChangeCharacterAddressGroup(characterfromID("Archie Kennedy"), "Quest_ShipDeck6XX", "goto", "marine4");
			ChangeCharacterAddressGroup(characterfromID("Doctor Clive"), "Quest_ShipDeck6XX", "reload", "reload1");
			LAi_ActorTurnToCharacter(characterFromID("Lt. Percy Buckland"), characterFromID("Doctor Clive"));
			LAi_ActorTurnToCharacter(characterFromID("Lt. William Bush"), characterFromID("Doctor Clive"));
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Doctor Clive"));

			LAi_SetActorType(characterFromID("Doctor Clive"));
			characters[GetCharacterIndex("Doctor Clive")].Dialog.Filename = "Doctor Clive_dialog.c";
			LAi_ActorDialog(characterFromID("Doctor Clive"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Doctor Clive")].dialog.CurrentNode = "The_Captain_Lives";
		break;

		case "Buckland_in_Command":
			AddQuestRecord("Mutiny", 6);
			LAi_ActorGoToLocation(characterFromID("Doctor Clive"), "reload", "reload1", "none", "", "", "",0.0);

			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "Now_I'm_Captain";
		break;

		case "Land_at_Cuban_Beach":
			for (cc = 1; cc <= 3; cc++)
			{
				RemoveOfficersIndex(pchar, GetOfficersIndex(PChar,cc));
			}

			SetOfficersIndex(Pchar, 1, getCharacterIndex("Archie Kennedy"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Richard Sharpe"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Lt. William Bush"));
			SetCharacterRemovable(characterFromID("Archie Kennedy"), false);
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			SetCharacterRemovable(characterFromID("Lt. William Bush"), false);

			ChangeCharacterAddressGroup(characterfromID("Rifleman Haggman"), "Cuba_Shore_04", "goto", "locator10");
			SetModelfromArray(characterFromID("Rifleman Haggman"), GetModelIndex("Rifleman95B4_18"));
			Characters[GetCharacterIndex("Rifleman Haggman")].headmodel = "h_Rifleman95B4_18";
			ChangeCharacterAddressGroup(characterfromID("Rifleman Higgins"), "Cuba_Shore_04", "goto", "citizen03");
			SetModelfromArray(characterFromID("Rifleman Higgins"), GetModelIndex("Rifleman95D3_18"));
			Characters[GetCharacterIndex("Rifleman Higgins")].headmodel = "h_Rifleman95D3_18";
			ChangeCharacterAddressGroup(characterfromID("Rifleman Tongue"), "Cuba_Shore_04", "goto", "citizen04");
			SetModelfromArray(characterFromID("Rifleman Tongue"), GetModelIndex("Rifleman95F3_18"));
			Characters[GetCharacterIndex("Rifleman Tongue")].headmodel = "h_Rifleman95F3_18";
			ChangeCharacterAddressGroup(characterfromID("Rifleman Cooper"), "Cuba_Shore_04", "goto", "citizen06");
			SetModelfromArray(characterFromID("Rifleman Cooper"), GetModelIndex("Rifleman95E3_18"));
			Characters[GetCharacterIndex("Rifleman Cooper")].headmodel = "h_Rifleman95E3_18";
			SetModelfromArray(characterFromID("Rifleman Harris"), GetModelIndex("Rifleman95B3_18"));
			Characters[GetCharacterIndex("Rifleman Harris")].headmodel = "h_Rifleman95B3_18";
			SetModelfromArray(characterFromID("Rifleman Mansfield"), GetModelIndex("Rifleman95A3_18"));
			Characters[GetCharacterIndex("Rifleman Mansfield")].headmodel = "h_Rifleman95A3_18";
			SetModelfromArray(characterFromID("Patrick Harper"), GetModelIndex("Rifleman_Harper"));
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Rifleman_Harper";

			DoQuestReloadToLocation("Cuba_Shore_04", "reload", "reload1", "Arrival_at_Playa_de_Sabana");
		break;

		case "Arrival_at_Playa_de_Sabana":
			DisableFastTravel(true);
			Locations[FindLocation("Cuba_Shore_04")].reload.l1.disable = 1;
			Locations[FindLocation("Cuba_Shore_04")].reload.l2.disable = 1;
			Locations[FindLocation("Cuba_Shore_04")].reload.l3.disable = 1;
			ChangeCharacterAddressGroup(characterfromID("Matthews"), "Cuba_Shore_04", "goto", "locator24");
			LAi_SetOfficerType(characterFromID("Matthews"));
			ChangeCharacterAddressGroup(characterfromID("Patrick Harper"), "Cuba_Shore_04", "goto", "locator8");
			SetModelfromArray(characterFromID("Patrick Harper"), GetModelIndex("Rifleman_Harper"));
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Rifleman_Harper";
			ChangeCharacterAddressGroup(characterfromID("Styles"), "Cuba_Shore_04", "goto", "locator23");
			ChangeCharacterAddressGroup(characterfromID("Oldroyd"), "Cuba_Shore_04", "goto", "locator9");
			ChangeCharacterAddressGroup(characterfromID("Rifleman Haggman"), "Cuba_Shore_04", "goto", "locator10");

			Build_at("Prison_Shore", "cannonl", "", -9.1471, 11.871, 15.691, 1.6165, "");

			LAi_QuestDelay("Arrival_at_Playa_de_Sabana2", 1.0);
		break;

		case "Arrival_at_Playa_de_Sabana2":
			Locations[FindLocation("Prison_Shore")].vcskip = true;
			AddQuestRecord("Mutiny", 7);
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "the_Spanish_beach";
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
		break;

		case "move_up_the_beach":
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "goto", "locator13", "The_fort_opens_fire",5.0);
		break;

		case "The_fort_opens_fire":
			LAi_SetPlayerType(PChar);
			CreateParticleSystemX("blast_inv", -0.12996, 2.7257, -10.364, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -0.12996, 2.7257, -10.364, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -0.12996, 2.7257, -10.364, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_QuestDelay("The_fort_opens_fire2", 1.0);
		break;

		case "The_fort_opens_fire2":
			WriteLocatorGlobal("Cuba_Shore_04", "fire", "fire1", "", -1, -0.12996, 2.7257, -10.364, false);
			Locations[FindLocation("Cuba_Shore_04")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Cuba_Shore_04")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", -0.12996, 2.7257, -10.364, -1.57, 0.0, 0.0,0);

			CreateParticleSystemX("blast_inv", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_QuestDelay("The_fort_opens_fire3", 1.0);
		break;

		case "The_fort_opens_fire3":
			WriteLocatorGlobal("Cuba_Shore_04", "fire", "fire2", "", -1, -1.3729, 2.76, -11.064, false);
			Locations[FindLocation("Cuba_Shore_04")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Cuba_Shore_04")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,0);

			CreateParticleSystemX("blast_inv", -3.2834, 2.7341, -11.181, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -3.2834, 2.7341, -11.181, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -3.2834, 2.7341, -11.181, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_QuestDelay("The_fort_opens_fire4", 1.0);
		break;

		case "The_fort_opens_fire4":
			WriteLocatorGlobal("Cuba_Shore_04", "fire", "fire3", "", -1, -3.2834, 2.7341, -11.181, false);
			Locations[FindLocation("Cuba_Shore_04")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Cuba_Shore_04")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", -3.2834, 2.7341, -11.181, -1.57, 0.0, 0.0,0);

			LAi_SetActorType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "after_the_shelling";
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
		break;

		case "Sharpe_asks_a_question":
			CreateParticleSystemX("blast_inv", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "What_rope_bridge";
		break;

		case "decide_to_try_the_bridge":
			CreateParticleSystemX("blast_inv", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -1.3729, 2.76, -11.064, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_SetOfficerType(characterFromID("Matthews"));

			Pchar.quest.Go_look_at_the_bridge.win_condition.l1 = "location";
			PChar.quest.Go_look_at_the_bridge.win_condition.l1.character = Pchar.id;
			Pchar.quest.Go_look_at_the_bridge.win_condition.l1.location = "Prison_Shore";
			Pchar.quest.Go_look_at_the_bridge.win_condition = "Go_look_at_the_bridge";

			pchar.quest.Killed_at_Cuba.win_condition.l1 = "locator";
			pchar.quest.Killed_at_Cuba.win_condition.l1.location = "Cuba_Shore_04";
			pchar.quest.Killed_at_Cuba.win_condition.l1.locator_group = "goto";
			pchar.quest.Killed_at_Cuba.win_condition.l1.locator = "death";
			pchar.quest.Killed_at_Cuba.win_condition = "Killed_at_Cuba";
		break;

		case "Killed_at_Cuba":
			Pchar.Quest.Go_look_at_the_bridge.over = "yes";
			Lai_KillCharacter(Pchar);
			Lai_KillCharacter(characterFromID("Richard Sharpe"));
			Lai_KillCharacter(characterFromID("Archie Kennedy"));
			LAi_QuestDelay("KilledFighting", 5.0);
		break;

		case "Go_look_at_the_bridge":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			LAi_SetActorType(characterFromID("Matthews"));

			Pchar.Quest.Killed_at_Cuba.over = "yes";
			ChangeCharacterAddressGroup(characterfromID("Rifleman Haggman"), "Prison_Shore", "officers", "reload2_1");
			ChangeCharacterAddressGroup(characterfromID("Rifleman Higgins"), "Prison_Shore", "officers", "reload2_2");
			ChangeCharacterAddressGroup(characterfromID("Rifleman Tongue"), "Prison_Shore", "officers", "reload2_3");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier6SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto1");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier7SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier8SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier9SP";

			pchar.quest.Bad_Set_up_the_attack.win_condition.l1 = "locator";
			PChar.quest.Bad_Set_up_the_attack.win_condition.l1.character = Pchar.id;
			pchar.quest.Bad_Set_up_the_attack.win_condition.l1.location = "Prison_Shore";
			pchar.quest.Bad_Set_up_the_attack.win_condition.l1.locator_group = "goto";
			pchar.quest.Bad_Set_up_the_attack.win_condition.l1.locator = "goto17";
			pchar.quest.Bad_Set_up_the_attack.win_condition = "Bad_Set_up_the_attack";

			pchar.quest.Set_up_the_attack.win_condition.l1 = "locator";
			PChar.quest.Set_up_the_attack.win_condition.l1.character = Pchar.id;
			pchar.quest.Set_up_the_attack.win_condition.l1.location = "Prison_Shore";
			pchar.quest.Set_up_the_attack.win_condition.l1.locator_group = "goto";
			pchar.quest.Set_up_the_attack.win_condition.l1.locator = "goto16";
			pchar.quest.Set_up_the_attack.win_condition = "Set_up_the_attack";

			pchar.quest.Dont_be_too_quick.win_condition.l1 = "locator";
			PChar.quest.Dont_be_too_quick.win_condition.l1.character = Pchar.id;
			pchar.quest.Dont_be_too_quick.win_condition.l1.location = "Prison_Shore";
			pchar.quest.Dont_be_too_quick.win_condition.l1.locator_group = "goto";
			pchar.quest.Dont_be_too_quick.win_condition.l1.locator = "goto23";
			pchar.quest.Dont_be_too_quick.win_condition = "Dont_be_too_quick";
		break;
// TRAP
		case "Bad_Set_up_the_attack":
			Pchar.Quest.Set_up_the_attack.over = "yes";
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_SetActorType(characterFromID("soldier9SP"));
			LAi_ActorTurnToCharacter(characterFromID("soldier9SP"), characterFromID("soldier6SP"));
			LAi_SetActorType(characterFromID("soldier8SP"));
			LAi_ActorTurnToCharacter(characterFromID("soldier8SP"), characterFromID("soldier6SP"));

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Rifleman Haggman"));
			LAi_SetOfficerType(characterFromID("Rifleman Tongue"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Bad_just_the_two_of_us";
		break;

		case "Bad_Looking_at_bridge":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "goto22", "", 0.0);

			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_ActorRunToLocator(characterFromID("Rifleman Haggman"), "goto", "goto20", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Tongue"), "goto", "goto21", "", 0.0);
			LAi_QuestDelay("Bad_call_up_the_riflemen", 20.0);
		break;

		case "Bad_call_up_the_riflemen":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "damit_they've_seen_us";
		break;

		case "Bad_Set_up_the_attack2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetGuardianType(characterFromID("soldier6SP"));
			LAi_SetGuardianType(characterFromID("soldier7SP"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("soldier8SP"));
			LAi_SetActorType(characterFromID("soldier9SP"));

			LAi_group_MoveCharacter(characterFromID("Soldier8SP"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier8SP"), "SPAIN_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier9SP"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier9SP"), "SPAIN_SOLDIERS");

			LAi_QuestDelay("Bad_Set_up_the_attack3", 0.0);
		break;

		case "Bad_Set_up_the_attack3":
			LAi_group_MoveCharacter(characterFromID("Richard Sharpe"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Haggman"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Tongue"), LAI_GROUP_PLAYER);
			
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "Bad_bridgebattleover");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Bad_bridgebattleover":
			CreateParticleSystemX("blast_inv", -8.9532, 12.8, 13.448, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -8.9532, 12.8, 13.448, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -8.9532, 12.8, 13.448, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("Bad_Set_up_the_attack5", 2.0);
		break;

		case "Bad_Set_up_the_attack5":
			CreateParticleSystemX("blast_inv", -8.5683, 11.659, -17.734, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -8.5683, 11.659, -17.734, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -8.5683, 11.659, -17.734, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			LAi_QuestDelay("Bad_Set_up_the_attack6", 1.0);
		break;

		case "Bad_Set_up_the_attack6":
			Lai_KillCharacter(Pchar);
			Lai_KillCharacter(characterFromID("Rifleman Haggman"));
			Lai_KillCharacter(characterFromID("Rifleman Tongue"));
			Lai_KillCharacter(characterFromID("Richard Sharpe"));
			LAi_QuestDelay("Bad_Set_up_the_attack7", 5.0);
		break;

		case "Bad_Set_up_the_attack7":
			LAi_QuestDelay("KilledFighting", 5.0);
		break;
// TRAP OVER
		case "Set_up_the_attack":
			Pchar.Quest.Bad_Set_up_the_attack.over = "yes";
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_SetActorType(characterFromID("soldier9SP"));
			LAi_ActorTurnToCharacter(characterFromID("soldier9SP"), characterFromID("soldier6SP"));
			LAi_SetActorType(characterFromID("soldier8SP"));
			LAi_ActorTurnToCharacter(characterFromID("soldier8SP"), characterFromID("soldier6SP"));

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Rifleman Haggman"));
			LAi_SetOfficerType(characterFromID("Rifleman Tongue"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "just_the_two_of_us";
		break;

		case "Looking_at_bridge":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "goto22", "", 0.0);

			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_ActorRunToLocator(characterFromID("Rifleman Haggman"), "goto", "goto20", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Tongue"), "goto", "goto21", "", 0.0);
			LAi_QuestDelay("call_up_the_riflemen", 20.0);
		break;

		case "call_up_the_riflemen":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "get_into_bridge_position";
		break;

		case "now_start_shooting":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto20", "",10.0);
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "goto", "goto18", "",8.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "goto", "goto19", "",8.0);
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto7", "",5.0);
			LAi_QuestDelay("Kill_far_side_guards", 5.0);
		break;

		case "Kill_far_side_guards":
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Tongue"), characterFromID("soldier6SP"));
			LAi_ActorTurnToCharacter((Pchar), characterFromID("soldier6SP"));
			LAi_QuestDelay("Remaining_guards_attack", 1.0);
		break;

		case "Remaining_guards_attack":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_ActorAnimation(characterFromID("Rifleman Tongue"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Tongue"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_QuestDelay("Remaining_guards_attack2", 1.0);
		break;

		case "Remaining_guards_attack2":
			Lai_KillCharacter(characterFromID("soldier6SP"));
			LAi_ActorAnimation(characterFromID("Rifleman Haggman"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Haggman"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_QuestDelay("Remaining_guards_attack3", 0.0);
		break;

		case "Remaining_guards_attack3":
			LAi_SetPlayerType(PChar);
			Lai_KillCharacter(characterFromID("soldier7SP"));

			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("soldier8SP"));
			LAi_SetActorType(characterFromID("soldier9SP"));

			LAi_group_MoveCharacter(characterFromID("Soldier8SP"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier8SP"), "SPAIN_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Soldier9SP"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier9SP"), "SPAIN_SOLDIERS");

			LAi_QuestDelay("Remaining_guards_attack4", 0.0);
		break;

		case "Remaining_guards_attack4":
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_SetOfficerType(characterFromID("Matthews"));
			LAi_group_MoveCharacter(characterFromID("Richard Sharpe"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Haggman"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Rifleman Tongue"), LAI_GROUP_PLAYER);

			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "bridgebattleover");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "bridgebattleover":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto19", "bridgebattleover2",5.0);
			LAi_ActorGoToLocator((Pchar), "goto", "goto18", "",5.0);
		break;

		case "bridgebattleover2":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(characterfromID("Rifleman Higgins"), "Prison_Shore", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Rifleman Cooper"), "Prison_Shore", "goto", "goto7");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "we_have_the_bridge";
		break;
// TRAP
		case "Dont_be_too_quick":
			ChangeCharacterAddressGroup(characterfromID("Francisco Manuel Ortega"), "Prison_Shore", "reload", "reload1_back");
			
			LAi_ActorAnimation(characterFromID("Francisco Manuel Ortega"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Francisco Manuel Ortega"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_QuestDelay("Got_shot_on_the_bridge", 0.0);
		break;

		case "Got_shot_on_the_bridge":
			Lai_KillCharacter(Pchar);
			LAi_QuestDelay("KilledFighting", 5.0);
		break;
// END TRAP - Game over
		case "bring_up_the_rest":
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Styles"));
			LAi_SetActorType(characterFromID("Oldroyd"));
			LAi_ActorRunToLocator(characterFromID("Rifleman Haggman"), "goto", "goto1", "",35.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Tongue"), "goto", "goto3", "",35.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Cooper"), "goto", "goto1", "",35.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Higgins"), "goto", "goto2", "",35.0);

			ChangeCharacterAddressGroup(characterfromID("Lt. William Bush"), "Prison_Shore", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Archie Kennedy"), "Prison_Shore", "goto", "goto20");
			ChangeCharacterAddressGroup(characterfromID("Patrick Harper"), "Prison_Shore", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Styles"), "Prison_Shore", "goto", "goto7");
			ChangeCharacterAddressGroup(characterfromID("Oldroyd"), "Prison_Shore", "goto", "goto7");

			LAi_QuestDelay("bring_up_the_rest2", 0.0);
		break;

		case "bring_up_the_rest2":
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_QuestDelay("bring_up_the_rest3", 0.0);
		break;

		case "bring_up_the_rest3":
			ChangeCharacterAddressGroup(characterfromID("Francisco Manuel Ortega"), "Prison_Shore", "reload", "reload1_back");

			LAi_SetActorType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "and_the_fort_plan_is";
		break;

		case "Set_up_blowing_the_door":
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "First time";

			Locations[FindLocation("Prison_Shore")].reload.l2.disable = 1;
			LAi_ActorGoToLocator(characterFromID("Francisco Manuel Ortega"), "officers", "reload1_2", "",2.0);
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "looks_like_surrender";
		break;

		case "Go_accept_surrender":
			Pchar.Quest.Dont_be_too_quick.over = "yes";
			LAi_ActorRunToLocator(characterFromID("Patrick Harper"), "goto", "goto4", "",10.0);
			LAi_ActorRunToLocator(characterFromID("Styles"), "goto", "goto19", "",10.0);
			LAi_ActorRunToLocator(characterFromID("Oldroyd"), "goto", "goto5", "",10.0);

			LAi_SetCivilianGuardianType(characterFromID("Francisco Manuel Ortega"));
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Matthews"));
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));

			LAi_SetCivilianGuardianType(characterFromID("Francisco Manuel Ortega"));
			characters[GetCharacterIndex("Francisco Manuel Ortega")].Dialog.Filename = "Francisco Manuel Ortega_dialog.c";
			LAi_ActorDialog(characterFromID("Francisco Manuel Ortega"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Francisco Manuel Ortega")].dialog.CurrentNode = "giving_my_surrender";
		break;

		case "into_surrendered_fort":
			LAi_Fade("", "");
			DoQuestReloadToLocation("Havana_fakefort4", "rld", "aloc1", "into_surrendered_fort2");
		break;

		case "into_surrendered_fort2":
			ChangeCharacterAddressGroup(characterfromID("Francisco Manuel Ortega"), "Havana_fakefort4", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Havana_fakefort4", "reload", "reloadc4");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Havana_fakefort4", "reload", "reloadc4");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Havana_fakefort4", "rld", "loc9");
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetOfficerType(characterFromID("Matthews"));
			LAi_SetOfficerType(characterFromID("Francisco Manuel Ortega"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "rld", "loc4");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "rld", "loc2");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "rld", "loc6");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "rld", "loc3");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier4SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "rld", "loc1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier5SP";

			LAi_QuestDelay("In_the_surrendered_fort", 3.0);
		break;

		case "In_the_surrendered_fort":
			LAi_SetActorType(characterFromID("Francisco Manuel Ortega"));
			characters[GetCharacterIndex("Francisco Manuel Ortega")].Dialog.Filename = "Francisco Manuel Ortega_dialog.c";
			LAi_ActorDialog(characterFromID("Francisco Manuel Ortega"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Francisco Manuel Ortega")].dialog.CurrentNode = "here_are_my_troops";
		break;

		case "go_join_spanish_troops":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Lt. Uriah Quelp"));
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetActorType(characterFromID("Francisco Manuel Ortega"));
			LAi_ActorGoToLocator(characterFromID("Francisco Manuel Ortega"), "rld", "loc5", "go_join_spanish_troops2",10.0);
		break;

		case "go_join_spanish_troops2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "released_from_prison";
		break;

		case "go_join_spanish_troops3":
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "somethings_not_right";
		break;

		case "Buckland_arrives_at_Fort":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Francisco Manuel Ortega"));

			LAi_ActorGoToLocator(characterFromID("Lt. William Bush"), "rld", "aloc4", "Buckland_arrives_at_Fort2",20.0);
			LAi_ActorGoToLocator(characterFromID("Archie Kennedy"), "rld", "aloc4", "",20.0);
		break;

		case "Buckland_arrives_at_Fort2":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Havana_fakefort4", "reload", "reloadc4");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Havana_fakefort4", "reload", "reloadc4");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Havana_fakefort4", "reload", "reloadc4");
			ChangeCharacterAddressGroup(characterFromID("Lt. Percy Buckland"), "Havana_fakefort4", "reload", "reloadc4");
			LAi_SetOfficerType(characterFromID("Rifleman Cooper"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Lt. Percy Buckland"));
			LAi_QuestDelay("Buckland_takes_over", 2.0);
		break;

		case "Buckland_takes_over":
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "the_fort_is_ours";
		break;

		case "Buckland_and_Ortega":
			LAi_SetOfficerType(characterFromID("Francisco Manuel Ortega"));
			LAi_QuestDelay("Buckland_and_Ortega2", 3.0);
		break;

		case "Buckland_and_Ortega2":
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "take_the_surrender";
		break;

		case "Send_prisoners_to_ship":
			LAi_SetActorType(characterFromID("Francisco Manuel Ortega"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetActorType(characterFromID("soldier1SP"));
			LAi_SetActorType(characterFromID("soldier2SP"));
			LAi_SetActorType(characterFromID("soldier3SP"));
			LAi_SetActorType(characterFromID("soldier4SP"));
			LAi_SetActorType(characterFromID("soldier5SP"));
			LAi_QuestDelay("Send_prisoners_to_ship2", 0.0);
		break;

		case "Send_prisoners_to_ship2":
			LAi_ActorGoToLocation(characterFromID("Francisco Manuel Ortega"), "reload", "reloadc4", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("Rifleman Cooper"), "reload", "reloadc4", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("Patrick Harper"), "reload", "reloadc4", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("Lt. Uriah Quelp"), "reload", "reloadc4", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("soldier1SP"), "reload", "reloadc4", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("soldier2SP"), "reload", "reloadc4", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("soldier3SP"), "reload", "reloadc4", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("soldier4SP"), "reload", "reloadc4", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("soldier5SP"), "reload", "reloadc4", "none", "", "", "",0.0);
			LAi_QuestDelay("Send_prisoners_to_ship4", 15.0);
		break;

		case "Send_prisoners_to_ship3":
			ChangeCharacterAddress(characterFromID("Francisco Manuel Ortega"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			ChangeCharacterAddress(characterFromID("soldier1SP"), "None", "");
			ChangeCharacterAddress(characterFromID("soldier2SP"), "None", "");
			ChangeCharacterAddress(characterFromID("soldier3SP"), "None", "");
			ChangeCharacterAddress(characterFromID("soldier4SP"), "None", "");
			ChangeCharacterAddress(characterFromID("soldier5SP"), "None", "");
			LAi_QuestDelay("Send_prisoners_to_ship4", 0.0);
		break;

		case "Send_prisoners_to_ship4":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "reload", "reloadc4", "",0.0);
			LAi_QuestDelay("Send_prisoners_to_ship5", 3.0);
		break;

		case "Send_prisoners_to_ship5":
			ChangeCharacterAddress(characterFromID("Richard Sharpe"), "None", "");

			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "blow_up_fort";
		break;

		case "Buckland_leaves_fort":
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			LAi_ActorGoToLocator(characterFromID("Lt. Percy Buckland"), "reload", "reloadc4", "",0.0);
			LAi_QuestDelay("Buckland_leaves_fort2", 3.0);
		break;

		case "Buckland_leaves_fort2":
			ChangeCharacterAddress(characterFromID("Lt. Percy Buckland"), "None", "");

			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));

			LAi_SetActorType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "Buckland_has_gone";
		break;

		case "set_the_charges":
			LAi_SetActorType(PChar);
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "First time";
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "First time";

			SetCharacterRemovable(characterFromID("Matthews"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Matthews"));
			RemoveCharacterCompanion(Pchar, characterFromID("Matthews"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemoveCharacterCompanion(Pchar, characterFromID("Richard Sharpe"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Lt. William Bush"));
			SetCharacterRemovable(characterFromID("Lt. William Bush"), false);

			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("Styles"), "None", "");
			ChangeCharacterAddress(characterFromID("Oldroyd"), "None", "");

			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Lt. William Bush"));

			LAi_ActorRunToLocator(characterFromID("Lt. William Bush"), "goto", "goto3", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Archie Kennedy"), "goto", "goto4", "", 0.0);
			LAi_QuestDelay("set_the_charges2", 10.0);
		break;

		case "set_the_charges2":
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_ActorGoToLocator((Pchar), "goto", "goto5", "", 0.0);
			LAi_QuestDelay("set_the_charges3", 10.0);
		break;

		case "set_the_charges3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "are_we_all_ready";
		break;

		case "set_the_charges4":
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Lt. William Bush"));

			Pchar.quest.The_charges_are_set.win_condition.l1 = "location";
			PChar.quest.The_charges_are_set.win_condition.l1.character = Pchar.id;
			Pchar.quest.The_charges_are_set.win_condition.l1.location = "Prison_Shore";
			Pchar.quest.The_charges_are_set.win_condition = "The_charges_are_set";
		break;

		case "The_charges_are_set":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "black_corsair", "goto", "goto20");
			LAi_group_MoveCharacter(sld, "HUBON_PIRATES");
			sld.id = "Rebel1";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "blackman", "goto", "goto20");
			LAi_group_MoveCharacter(sld, "HUBON_PIRATES");
			sld.id = "Rebel2";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair1_3", "goto", "goto20");
			LAi_group_MoveCharacter(sld, "HUBON_PIRATES");
			sld.id = "Rebel3";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "rabblack", "goto", "goto21");
			LAi_group_MoveCharacter(sld, "HUBON_PIRATES");
			sld.id = "Rebel4";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "rabblack_1", "goto", "goto21");
			LAi_group_MoveCharacter(sld, "HUBON_PIRATES");
			sld.id = "Rebel5";

			LAi_SetActorType(characterFromID("Rebel1"));
			LAi_SetActorType(characterFromID("Rebel2"));
			LAi_SetActorType(characterFromID("Rebel3"));
			LAi_SetActorType(characterFromID("Rebel4"));
			LAi_SetActorType(characterFromID("Rebel5"));

			LAi_QuestDelay("Rebel_Army_Blocks_the_way", 0.0);
		break;

		case "Rebel_Army_Blocks_the_way":
			LAi_ActorRunToLocator(characterFromID("Rebel1"), "goto", "goto6", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Rebel2"), "goto", "goto5", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Rebel3"), "goto", "goto4", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Rebel4"), "goto", "goto18", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Rebel5"), "goto", "goto19", "", 0.0);

			LAi_QuestDelay("Rebel_Army_Blocks_the_way2", 5.0);
		break;

		case "Rebel_Army_Blocks_the_way2":
			LAi_ActorTurnToCharacter(characterFromID("Rebel1"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Rebel2"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Rebel3"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Rebel4"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Rebel5"),(Pchar));

			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "We_are_not_alone";
		break;

		case "Prepare_to_fire":
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			LAi_ActorGoToLocator(characterFromID("Archie Kennedy"), "goto", "goto2", "", 0.0);

			LAi_QuestDelay("Fire_at_rebel_Army", 3.0);
		break;

		case "Fire_at_rebel_Army":
			CreateParticleSystemX("blast_inv", -8.9532, 12.8, 13.448, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -8.9532, 12.8, 13.448, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -8.9532, 12.8, 13.448, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("Fire_at_rebel_Army2", 2.0);
		break;

		case "Fire_at_rebel_Army2":
			CreateParticleSystemX("blast_inv", -8.5683, 11.659, -17.734, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -8.5683, 11.659, -17.734, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -8.5683, 11.659, -17.734, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			LAi_QuestDelay("Dead_rebel_Army", 1.0);
		break;

		case "Dead_rebel_Army":
			Lai_KillCharacter(characterFromID("Rebel1"));
			Lai_KillCharacter(characterFromID("Rebel2"));
			Lai_KillCharacter(characterFromID("Rebel3"));
			Lai_KillCharacter(characterFromID("Rebel4"));
			Lai_KillCharacter(characterFromID("Rebel5"));

			LAi_QuestDelay("Not_a_Problem", 5.0);
		break;

		case "Not_a_Problem":
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "light_the_fuse";
		break;

		case "Get_across_the_bridge":
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "goto", "goto5", "Get_ready_for_the_bang",12.0);
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
		break;

		case "Get_ready_for_the_bang":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "ready_for_the_bang";
		break;

		case "the_fort_goes_up":
			CreateParticleSystemX("blast_inv", -5.6791, 12.234, 20.157, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -5.6791, 12.234, 20.157, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -5.6791, 12.234, 20.157, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire1", "", -1, -5.6791, 12.234, 20.157, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -5.6791, 12.234, 20.157, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("the_fort_goes_up2", 2.0);
		break;

		case "the_fort_goes_up2":
			CreateParticleSystemX("blast_inv", -4.702, 12.164, 18.35, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -4.702, 12.164, 18.35, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -4.702, 12.164, 18.35, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire2", "", -1, -4.702, 12.164, 18.35, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 6.0; 
			CreateParticleSystemX("fireball", -4.702, 12.164, 18.35, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("the_fort_goes_up3", 1.0);
		break;

		case "the_fort_goes_up3":
			CreateParticleSystemX("blast_inv", -6.5704, 12.176, 18.313, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -6.5704, 12.176, 18.313, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -6.5704, 12.176, 18.313, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire3", "", -1, -6.5704, 12.176, 18.313, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", -6.5704, 12.176, 18.313, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("the_fort_goes_up4", 1.0);
		break;

		case "the_fort_goes_up4":
			CreateParticleSystemX("blast_inv", -8.3331, 12.111, 18.56, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -8.3331, 12.111, 18.56, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -8.3331, 12.111, 18.56, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire4", "", -1, -8.3331, 12.111, 18.56, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -8.3331, 12.111, 18.56, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Prison_Shore", "fire", "fire5", "", -1, -6.3263, 11.632, 11.541, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -6.3263, 11.632, 11.541, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("the_fort_goes_up5", 1.0);
		break;

		case "the_fort_goes_up5":
			CreateParticleSystemX("blast_inv", -2.6377, 12.089, 18.329, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -2.6377, 12.089, 18.329, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -2.6377, 12.089, 18.329, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire6", "", -1, -2.6377, 12.089, 18.329, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", -2.6377, 12.089, 18.329, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("the_fort_goes_up6", 1.0);
		break;

		case "the_fort_goes_up6":
			CreateParticleSystemX("blast_inv", -10.825, 11.576, 18.945, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -10.825, 11.576, 18.945, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -10.825, 11.576, 18.945, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire7", "", -1, -10.825, 11.576, 18.945, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -10.825, 11.576, 18.945, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("the_fort_goes_up7", 1.0);
		break;

		case "the_fort_goes_up7":
			CreateParticleSystemX("blast_inv", -5.6791, 12.234, 20.157, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -5.6791, 12.234, 20.157, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -5.6791, 12.234, 20.157, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire8", "", -1, -8.9954, 11.82, 14.951, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -8.9954, 11.82, 14.951, -1.57, 0.0, 0.0,0);

			WriteLocatorGlobal("Prison_Shore", "fire", "fire1", "", -1, -5.6791, 12.234, 20.157, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -5.6791, 12.234, 20.157, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("The_Fort_is_blown", 2.0);
		break;

		case "The_Fort_is_blown":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "mission_accomplished";
		break;

		case "The_ship_has_been_captured":
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			pchar.quest.Killed_at_Prison.win_condition.l1 = "locator";
			pchar.quest.Killed_at_Prison.win_condition.l1.location = "Prison_Shore";
			pchar.quest.Killed_at_Prison.win_condition.l1.locator_group = "goto";
			pchar.quest.Killed_at_Prison.win_condition.l1.locator = "goto23";
			pchar.quest.Killed_at_Prison.win_condition = "Killed_at_Prison";

			Pchar.quest.Return_to_Renown_after_fort.win_condition.l1 = "location";
			Pchar.quest.Return_to_Renown_after_fort.win_condition.l1.character = Pchar.id;
			Pchar.quest.Return_to_Renown_after_fort.win_condition.l1.location = "Cuba_Shore_04";
			Pchar.quest.Return_to_Renown_after_fort.win_condition = "Return_to_Renown_after_fort";

			pchar.quest.teleport_cuba_shore_04.win_condition.l1 = "locator";
			pchar.quest.teleport_cuba_shore_04.win_condition.l1.location = "Prison_Shore";
			pchar.quest.teleport_cuba_shore_04.win_condition.l1.locator_group = "reload";
			pchar.quest.teleport_cuba_shore_04.win_condition.l1.locator = "reload4";
			pchar.quest.teleport_cuba_shore_04.win_condition = "teleport_cuba_shore_04";
		break;

		case "teleport_cuba_shore_04": // GR: shouldn't be needed but normal teleport doesn't work from a savegame on Prison_Shore
			DoQuestReloadToLocation("Cuba_Shore_04", "reload", "reload3", "Return_to_Renown_after_fort");
		break;

		case "Killed_at_Prison":
			Pchar.Quest.Return_to_Renown_after_fort.over = "yes";
			Lai_KillCharacter(Pchar);
			Lai_KillCharacter(characterFromID("Lt. William Bush"));
			Lai_KillCharacter(characterFromID("Archie Kennedy"));
			LAi_QuestDelay("Killed_at_Prison2", 5.0);
		break;

		case "Killed_at_Prison2":
			LAi_QuestDelay("KilledFighting", 5.0);
		break;

		case "Return_to_Renown_after_fort":
			Locations[FindLocation("Cuba_Shore_04")].reload.l2.disable = 0;
			ChangeCharacterAddressGroup(characterfromID("Matthews"), "Cuba_Shore_04", "goto", "locator10");
			ChangeCharacterAddressGroup(characterfromID("Perrin"), "Cuba_Shore_04", "goto", "locator23");
			ChangeCharacterAddressGroup(characterfromID("Marsh"), "Cuba_Shore_04", "goto", "locator9");

			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "the_Spanish_have_the_ship";
		break;

		case "Recapture_the_Renown":
			AddQuestRecord("Mutiny", 8);
			Pchar.quest.Recapture_the_Renown2.win_condition.l1 = "locator";
			Pchar.quest.Recapture_the_Renown2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Recapture_the_Renown2.win_condition.l1.location = "Cuba_Shore_04";
			Pchar.quest.Recapture_the_Renown2.win_condition.l1.locator_group = "reload";
			Pchar.quest.Recapture_the_Renown2.win_condition.l1.locator = "boat";
			Pchar.quest.Recapture_the_Renown2.win_condition = "Recapture_the_Renown2";
		break;

		case "Recapture_the_Renown2":
			DoQuestReloadToLocation("Quest_ShipDeck6XX", "reload", "boatr", "Battle_on_deck");
		break;

		case "Battle_on_deck":
			LAi_SetImmortal(characterFromID("Archie Kennedy"), true);
			LAi_SetImmortal(characterFromID("Lt. William Bush"), true);

			ChangeCharacterAddressGroup(characterfromID("Matthews"), "Quest_ShipDeck6XX", "goto", "goto4");
			ChangeCharacterAddressGroup(characterfromID("Perrin"), "Quest_ShipDeck6XX", "goto", "goto11");
			ChangeCharacterAddressGroup(characterfromID("Marsh"), "Quest_ShipDeck6XX", "reload", "boatl");
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Quest_ShipDeck6XX", "goto", "goto13");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Quest_ShipDeck6XX", "goto", "goto2");

			PlaySound("OBJECTS\duel\pistol_bbus.wav");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier6SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier7SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto6");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier8SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto6");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier9SP";

			LAi_group_MoveCharacter(characterFromID("Archie Kennedy"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Lt. William Bush"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Matthews"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Perrin"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Marsh"), LAI_GROUP_PLAYER);

			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "maindeck_clear");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "maindeck_clear":
			PlaySound("OBJECTS\duel\pistol_bbus.wav");

			ChangeCharacterAddressGroup(characterfromID("Captain James Sawyer"), "Cabin4", "officers", "officer5");
			ChangeCharacterAddressGroup(characterfromID("Henry Wellard"), "Cabin4", "officers", "officer6");
			LAi_ActorAnimation(characterFromID("Captain James Sawyer"), "Lay_1", "", -1);
			LAi_ActorAnimation(characterFromID("Henry Wellard"), "Lay_1", "", -1);

			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "get_to_the_wheel";
		break;

		case "maindeck_clear2":
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "I'm_wounded";
			Characters[GetCharacterIndex("Archie Kennedy")].dialog.CurrentNode = "Been_shot";
			ChangeCharacterAddressGroup(characterfromID("Francisco Manuel Ortega"), "Quest_ShipDeck6XX", "goto", "goto14");
			LAi_ActorAnimation(characterFromID("Francisco Manuel Ortega"), "Lay_1", "", -1);
			ChangeCharacterAddressGroup(characterfromID("Richard Sharpe"), "Quest_ShipDeck6XX", "goto", "goto7");
			LAi_SetActorType(characterFromID("Richard Sharpe"));

			PlaySound("OBJECTS\duel\pistol_bbus.wav");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto7");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto14");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto14");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier4SP";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto14");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier5SP";

			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "Ship_retaken_clear");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Ship_retaken_clear":
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			LAi_SetStunnedTypeNoGroup(characterFromID("Lt. William Bush"));
			LAi_SetStunnedTypeNoGroup(characterFromID("Archie Kennedy"));

			Pchar.quest.Recapture_the_Renown3.win_condition.l1 = "locator";
			Pchar.quest.Recapture_the_Renown3.win_condition.l1.character = Pchar.id;
			Pchar.quest.Recapture_the_Renown3.win_condition.l1.location = "Quest_ShipDeck6XX";
			Pchar.quest.Recapture_the_Renown3.win_condition.l1.locator_group = "goto";
			Pchar.quest.Recapture_the_Renown3.win_condition.l1.locator = "goto15";
			Pchar.quest.Recapture_the_Renown3.win_condition = "Recapture_the_Renown3";

			Pchar.quest.Recapture_the_Renown3A.win_condition.l1 = "locator";
			Pchar.quest.Recapture_the_Renown3A.win_condition.l1.character = Pchar.id;
			Pchar.quest.Recapture_the_Renown3A.win_condition.l1.location = "Quest_ShipDeck6XX";
			Pchar.quest.Recapture_the_Renown3A.win_condition.l1.locator_group = "goto";
			Pchar.quest.Recapture_the_Renown3A.win_condition.l1.locator = "goto16";
			Pchar.quest.Recapture_the_Renown3A.win_condition = "Recapture_the_Renown3";
		break;

		case "Recapture_the_Renown3":
			Pchar.Quest.Recapture_the_Renown3.over = "yes";
			Pchar.Quest.Recapture_the_Renown3A.over = "yes";
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto17", "Sharpe_in_danger", 10.0);
		break;

		case "Sharpe_in_danger":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Quest_ShipDeck6XX", "goto", "goto15");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto15");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1SP";
			LAi_SetActorType(characterFromID("soldier1SP"));
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "The_ship_retaken";
		break;

		case "Sharpe_in_danger2":
			LAi_ActorRunToLocator(characterFromID("soldier1SP"), "goto", "goto18", "Try_kill_Sharpe", 0.0);
		break;

		case "Try_kill_Sharpe":
			LAi_ActorAnimation(characterFromID("Lt. Uriah Quelp"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Lt. Uriah Quelp"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_QuestDelay("Try_kill_Sharpe2", 0.0);
		break;

		case "Try_kill_Sharpe2":
			Lai_KillCharacter(characterFromID("Soldier1SP"));
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			LAi_QuestDelay("Try_kill_Sharpe3", 0.0);
		break;

		case "Try_kill_Sharpe3":
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "What_happened_there";
		break;

		case "Quelp_saved_Sharpe":
			ChangeCharacterAddressGroup(characterFromID("Lt. Percy Buckland"), "Quest_ShipDeck6XX", "goto", "goto10");
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "situation_report";
		break;

		case "Buckland_on_deck":
			SetCharacterRemovable(characterFromID("Archie Kennedy"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Archie Kennedy"));
			RemoveCharacterCompanion(Pchar, characterFromID("Archie Kennedy"));
			SetCharacterRemovable(characterFromID("Lt. William Bush"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. William Bush"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. William Bush"));
			SetCharacterRemovable(characterFromID("Henry Wellard"), true);
			RemovePassenger(pchar, characterFromID("Henry Wellard"));
			LAi_SetOfficerType(characterFromID("Lt. Percy Buckland"));
			LAi_QuestDelay("Buckland_on_deck2", 0.0);
		break;

		case "Buckland_on_deck2":
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.CurrentNode = "the_ship_recovered";
		break;

		case "senior_man_now":
			LAi_ActorGoToLocation(characterFromID("Lt. Percy Buckland"), "goto", "goto10", "none", "", "", "",0.0);

			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "not_in_a_Good_Mood";
		break;

		case "Sharpe_makes_an_observation":
			LAi_ActorGoToLocation(characterFromID("Lt. Uriah Quelp"), "goto", "goto10", "none", "", "", "",0.0);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "an_observation";
		break;

		case "the_burial_party":
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"RN_Superbe","Renown",-1,ENGLAND,true,true);
			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemoveCharacterCompanion(Pchar, characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			DoQuestReloadToLocation("Cuba_Shore_04", "reload", "reload1", "The_burials_are_done");
		break;

		case "The_burials_are_done":
			LAi_Fade("", "");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Cuba_Shore_04", "goto", "locator25");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Cuba_Shore_04", "goto", "citizen07");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Cuba_Shore_04", "goto", "citizen09");
			ChangeCharacterAddressGroup(characterFromID("Marsh"), "Cuba_Shore_04", "goto", "citizen09");

			LAi_SetActorType(characterFromID("Matthews"));
			LAi_SetActorType(characterFromID("Oldroyd"));
			LAi_SetActorType(characterFromID("Marsh"));

			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "burial_completed";
		break;

		case "Burials_over_now_Redmond":
			AddQuestRecord("Mutiny", 9);
			DisableFastTravel(false);
			LAi_ActorGoToLocation(characterFromID("Lt. Uriah Quelp"), "reload", "boat", "none", "", "", "",5.0);
			LAi_ActorGoToLocation(characterFromID("Matthews"), "reload", "boat", "none", "", "", "",5.0);
			LAi_ActorGoToLocation(characterFromID("Oldroyd"), "reload", "boat", "none", "", "", "",5.0);
			LAi_ActorGoToLocation(characterFromID("Marsh"), "reload", "boat", "none", "", "", "",5.0);

			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. Percy Buckland"));
			SetCharacterRemovable(characterFromID("Lt. Percy Buckland"), false);

			pchar.quest.Arrested_at_Redmond.win_condition.l1 = "location";
			Pchar.quest.Arrested_at_Redmond.win_condition.l1.character = Pchar.id;
			pchar.quest.Arrested_at_Redmond.win_condition.l1.location = "Redmond_port";
			pchar.quest.Arrested_at_Redmond.win_condition = "Arrested_at_Redmond";
		break;

		case "Arrested_at_Redmond":
			Locations[FindLocation("Prison_Shore")].vcskip = false;
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			ChangeCharacterAddressGroup(characterFromID("William Chumley"), "REDMOND_PORT", "goto", "Goto_44");

			LAi_SetActorType(characterFromID("William Chumley"));
			characters[GetCharacterIndex("William Chumley")].Dialog.Filename = "William Chumley_dialog.c";
			LAi_ActorDialog(characterFromID("William Chumley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("William Chumley")].dialog.CurrentNode = "I_have_to_arrest_you";
		break;

		case "The_Court_Martial_Begins":
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "Head_of_Jamaica_Station", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Head_of_Jamaica_Station", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Captain Harvey"), "Head_of_Jamaica_Station", "sit", "sit1");
			LAi_ActorSetSitMode(characterFromID("Captain Harvey"));
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Head_of_Jamaica_Station", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("William Chumley"), "Head_of_Jamaica_Station", "goto", "goto4");
			LAi_Fade("", "");
			DoQuestReloadToLocation("Head_of_Jamaica_Station", "reload", "reload1", "The_Court_Martial_Begins2");
			
		break;

		case "The_Court_Martial_Begins2":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto8", "The_Court_Martial_Begins3", 10);
			ChangeCharacterAddressGroup(characterFromID("Lt. Percy Buckland"), "Head_of_Jamaica_Station", "goto", "goto7");

			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.currentnode = "Court_Martial_one";
		break;

		case "The_Court_Martial_Begins3":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));

			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialogNow(characterFromID("Sir Edward Pellew"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);

			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.currentnode = "Court_Martial_two";
		break;

		case "The_Court_Martial_Begins4":
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Black Charlie Hammond"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"),PChar,"",5.0,5.0);

			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.currentnode = "Court_Martial_three";
		break;

		case "The_Court_Martial_Begins5":
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialogNow(characterFromID("Sir Edward Pellew"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);

			Characters[GetCharacterIndex("Lt. Percy Buckland")].dialog.currentnode = "Court_Martial_four";
		break;

		case "The_Court_Martial_Begins6":
			ChangeCharacterAddressGroup(characterFromID("Archie Kennedy"), "Head_of_Jamaica_Station", "goto", "goto1");
			LAi_SetActorType(characterFromID("Lt. Percy Buckland"));
			characters[GetCharacterIndex("Lt. Percy Buckland")].Dialog.Filename = "Lt. Percy Buckland_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. Percy Buckland"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Lt. Percy Buckland"),PChar,"",5.0,5.0);

			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.currentnode = "Court_Martial_five";
		break;

		case "The_Court_Martial_Begins7":
			LAi_SetOfficerType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialogNow(characterFromID("Sir Edward Pellew"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);

			Characters[GetCharacterIndex("Archie Kennedy")].dialog.currentnode = "I_pushed_the_Captain";
		break;

		case "Court_Martial_Over":
			Locations[FindLocation("Redmond Naval HQ")].vcskip = true;
			LAi_SetActorType(characterFromID("Archie Kennedy"));
			characters[GetCharacterIndex("Archie Kennedy")].Dialog.Filename = "Archie Kennedy_dialog.c";
			LAi_ActorDialogNow(characterFromID("Archie Kennedy"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Archie Kennedy"),PChar,"",5.0,5.0);
		break;

		case "Retribution_and_Promotion":
			LAi_Fade("", "");
			ChangeCharacterAddress(characterFromID("Captain Harvey"), "None", "");
			ChangeCharacterAddress(characterFromID("Black Charlie Hammond"), "None", "");
			ChangeCharacterAddress(characterFromID("Archie Kennedy"), "None", "");
			ChangeCharacterAddress(characterFromID("William Chumley"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Lt. Chadd"), "Redmond Naval HQ", "goto", "desk");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Redmond Naval HQ", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Redmond Naval HQ", "reload", "reload2");
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Redmond Naval HQ", "reload", "reload2");
			DoQuestReloadToLocation("Redmond Naval HQ", "goto", "goto4", "Retribution_and_Promotion2");
		break;

		case "Retribution_and_Promotion2":
			SetCharacterRemovable(characterFromID("Lt. Percy Buckland"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. Percy Buckland"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));
			RemovePassenger(pchar, characterFromID("Lt. Percy Buckland"));
			SetCharacterRemovable(characterFromID("Archie Kennedy"), true);
			RemovePassenger(pchar, characterFromID("Archie Kennedy"));

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "You_have_been_cleared";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"), pchar, "", 1.0, 1.0);
		break;

		case "A_new_Quest_Line":
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"HMS_Sophie","Retribution",-1,ENGLAND,true,true);
			DeleteAttribute(PChar, "isnotcaptain");
			setCharacterShipLocation(Pchar, "Redmond_port");
			pchar.quest.Players_Rank = "Commander";
			SetRank(pchar, ENGLAND, 5); // PB: Commander
////			GiveModel2Player("brtHComdr_18", true); // hold till move
			pchar.quest.story_path = "neutral";
			LAi_ActorGoToLocation(characterFromID("Sir Edward Pellew"), "reload", "reload1", "none", "", "", "",10.0);
			LAi_QuestDelay("A_new_Quest_Line2", 0.0);
		break;

		case "A_new_Quest_Line2":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));
			LAi_QuestDelay("Wellesley_needs_help", 10.0);
		break;

		case "Wellesley_needs_help":
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Work_with_Sharpe";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"), pchar, "", 1.0, 1.0);
		break;

		case "Sharpe_and_the_traitor":
			LAi_ActorGoToLocation(characterFromID("Arthur Wellesley"), "reload", "reload1", "none", "", "", "",10.0);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Need_information";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Chadd_knows_all":
			LAi_SetOfficerType(characterFromID("Lt. Chadd"));
			LAi_QuestDelay("Chadd_knows_all2", 5.0);
		break;

		case "Chadd_knows_all2":
			LAi_SetActorType(characterFromID("Lt. Chadd"));
			characters[GetCharacterIndex("Lt. Chadd")].Dialog.Filename = "Lt. Chadd_dialog.c";
			Characters[GetCharacterIndex("Lt. Chadd")].dialog.CurrentNode = "Where_is_Quelp";
			LAi_ActorDialog(characterFromID("Lt. Chadd"), pchar, "", 1.0, 1.0);
		break;

		case "Get_ready_for_Cayman":
			LAi_ActorGoToLocation(characterFromID("Lt. Chadd"), "reload", "reload2", "none", "", "", "",10.0);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "To_Cayman_it_is";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "On_route_to_Cayman_or_Charlestown":
			LAi_Fade("", "");
			GiveModel2Player("brtHComdr_18", true);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Redmond_Town_01", "officers", "Door_56_2");
			DoQuestReloadToLocation("Redmond_Town_01", "officers", "Door_56_1", "On_route_to_Cayman_or_Charlestown2");
		break;

		case "On_route_to_Cayman_or_Charlestown2":
			CloseQuestHeader("Mutiny");
			SetQuestHeader("Retribution");
			AddQuestRecord("Retribution", 1);
			pchar.quest.Looking_in_Cayman.win_condition.l1 = "location";
			Pchar.quest.Looking_in_Cayman.win_condition.l1.character = Pchar.id;
			pchar.quest.Looking_in_Cayman.win_condition.l1.location = "Cayman_Port";
			pchar.quest.Looking_in_Cayman.win_condition = "Looking_in_Cayman";
		break;

		case "Looking_in_Cayman":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			setCharacterShipLocation(characterfromID("Captain Harvey"), "Cayman_Port");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Cayman_Port", "goto", "goto5");
			LAi_QuestDelay("Looking_in_Cayman1", 2.0);
		break;

		case "Looking_in_Cayman1":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Cayman_start_where";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Looking_in_Cayman2":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			pchar.quest.Looking_in_Cayman3.win_condition.l1 = "location";
			Pchar.quest.Looking_in_Cayman3.win_condition.l1.character = Pchar.id;
			pchar.quest.Looking_in_Cayman3.win_condition.l1.location = "Grand_Cayman_Tavern";
			pchar.quest.Looking_in_Cayman3.win_condition = "Looking_in_Cayman3";
		break;

		case "Looking_in_Cayman3":
			ChangeCharacterAddressGroup(characterFromID("Midshipman Hunter"), "Grand_Cayman_Tavern", "goto", "goto6");
			LAi_SetActorType(characterFromID("Midshipman Hunter"));
			LAi_ActorRunToLocation(characterFromID("Midshipman Hunter"), "reload", "reload3", "none", "", "", "",3.0);
			LAi_QuestDelay("Looking_in_Cayman4", 3.0);
		break;

		case "Looking_in_Cayman4":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Who_was_that";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Continue_search_for_Quelp":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			pchar.quest.Looking_in_Cayman_Quelp.win_condition.l1 = "location";
			Pchar.quest.Looking_in_Cayman_Quelp.win_condition.l1.character = Pchar.id;
			pchar.quest.Looking_in_Cayman_Quelp.win_condition.l1.location = "Grand_Cayman_town";
			pchar.quest.Looking_in_Cayman_Quelp.win_condition = "Looking_in_Cayman_Quelp";
		break;

		case "Looking_in_Cayman_Quelp":
			ChangeCharacterAddressGroup(characterFromID("Captain Harvey"), "Grand_Cayman_town", "goto", "goto25");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Grand_Cayman_town", "goto", "goto25");
			LAi_SetOfficerType(characterFromID("Captain Harvey"));
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			LAi_QuestDelay("Looking_in_Cayman_Quelp2", 3.0);
		break;

		case "Looking_in_Cayman_Quelp2":
			LAi_SetActorType(characterFromID("Captain Harvey"));
			characters[GetCharacterIndex("Captain Harvey")].Dialog.Filename = "Captain Harvey_dialog.c";
			Characters[GetCharacterIndex("Captain Harvey")].dialog.CurrentNode = "Harvey_meeting_Cayman";
			LAi_ActorDialog(characterFromID("Captain Harvey"), pchar, "", 1.0, 1.0);
		break;

		case "Harvey_changes_plans":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. Uriah Quelp"));
			SetCharacterRemovable(characterFromID("Lt. Uriah Quelp"), false);
			LAi_ActorGoToLocation(characterFromID("Captain Harvey"), "reload", "reload9", "none", "", "", "",0.0);

			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "Get_things_sorted";
		break;

		case "Put_Sharpe_at_ease":
			LAi_ActorGoToLocation(characterFromID("Lt. Uriah Quelp"), "reload", "reload9", "none", "", "", "",0.0);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Still_not_happy";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Sharpe_Quelp_Antigua":
			AddQuestRecord("Retribution", 2);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			pchar.quest.Antigua_for_battle.win_condition.l1 = "location";
			Pchar.quest.Antigua_for_battle.win_condition.l1.character = Pchar.id;
			pchar.quest.Antigua_for_battle.win_condition.l1.location = "Antigua_port";
			pchar.quest.Antigua_for_battle.win_condition = "Antigua_for_battle";
		break;

		case "Guadeloupe_shore_Battle":
		// TEMPLE TEMPLE TEMPLE TEMPLE
		break;

		case "Antigua_for_battle":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Antigua_port", "officers", "reload6_3");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Antigua_port", "officers", "reload6_2");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Antigua_port", "officers", "reload6_1");
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Antigua_port", "goto", "goto19");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Antigua_port", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Antigua_port", "goto", "goto27");
			ChangeCharacterAddressGroup(Pchar, "Antigua_port", "goto", "goto24");
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Just_in_time";
			LAi_QuestDelay("Meet_with_Wellesley_talk_battle", 1.0);
		break;

		case "Meet_with_Wellesley_talk_battle":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			Locations[FindLocation("Antigua_outskirts")].vcskip = true;
			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));

			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Just_in_time";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"), pchar, "", 1.0, 1.0);
		break;

		case "Antigua_Land_Battle":
			LAi_ActorGoToLocation(characterFromID("Arthur Wellesley"), "reload", "reload3", "none", "", "", "",0.0);
			ChangeCharacterAddress(characterFromID("Matthews"), "None", "");
			ChangeCharacterAddress(characterFromID("Oldroyd"), "None", "");
			ChangeCharacterAddress(characterFromID("Styles"), "None", "");
			port = &Locations[FindLocation("Antigua_outskirts")];
			if(CheckAttribute(port,"building")) DeleteAttribute(port,"building");
			LAi_QuestDelay("Antigua_Land_Battle2", 1.0);
		break;

		case "Antigua_Land_Battle2":
			Build_at("Antigua_outskirts", "Field_Cannon_1", "", 23.90, -0.54488, 107.03, -1.1043, "");
			Build_at("Antigua_outskirts", "Field_Cannon_1", "", 13.133, -0.91791, 109.39, -1.3042, ""); 
			Build_at("Antigua_outskirts", "Field_Cannon_1", "", 4.225, -0.1075, 110.22, -1.240, "");

			Build_at("Antigua_Jungle_01", "Field_Cannon_1", "", -36.161, 0.031665, -8.8419, 1.000, "");

			Build_at("Antigua_outskirts", "cannonl", "", -12.881, 1.8755, 45.963, -1.0805, "");

			CloseQuestHeader("Retribution");
			SetQuestHeader("Attack on Antigua");
			AddQuestRecord("Attack on Antigua", 1);
			pchar.quest.Antigua_Land_Battle2.win_condition.l1 = "location";
			Pchar.quest.Antigua_Land_Battle2.win_condition.l1.character = Pchar.id;
			pchar.quest.Antigua_Land_Battle2.win_condition.l1.location = "Antigua_outskirts";
			pchar.quest.Antigua_Land_Battle2.win_condition = "Antigua_Land_Battle2Add";
		break;

		case "Antigua_Land_Battle2Add":
			ChangeCharacterAddress(characterFromID("Arthur Wellesley"), "None", "");
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Antigua_outskirts", "goto", "goto4");
			LAi_SetActorType(characterFromID("Matthews"));
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_outskirts", "goto", "goto15");
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_outskirts", "goto", "goto15");
			LAi_SetOfficerType(characterFromID("Rifleman Tongue"));
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Antigua_outskirts", "goto", "goto14");
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_outskirts", "goto", "goto14");
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Antigua_outskirts", "goto", "goto15");
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Antigua_outskirts", "goto", "goto31");
			LAi_SetActorType(characterFromID("Oldroyd"));
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Antigua_outskirts", "goto", "goto32");
			LAi_SetActorType(characterFromID("Styles"));
// Brits
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto59");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto1");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG2B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "goto12");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG3B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto55");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG4B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "goto", "goto56");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG5B";
// End Brits
// French
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto38");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto39");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto40");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto41");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto42");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto43");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier6X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto44");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier7X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto45");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier8X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto46");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier9X";

			LAi_SetActorType(characterFromID("soldierG2B"));
			LAi_ActorAnimation(characterFromID("soldierG2B"), "Lay_1", "", -1);
			LAi_SetActorType(characterFromID("soldierG3B"));
			LAi_ActorAnimation(characterFromID("soldierG3B"), "Lay_1", "", -1);
			LAi_SetActorType(characterFromID("soldierG4B"));
			LAi_SetStunnedTypeNoGroup(characterFromID("soldierG4B"));
			LAi_SetActorType(characterFromID("soldierG5B"));
			LAi_SetStunnedTypeNoGroup(characterFromID("soldierG5B"));

			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));
			LAi_SetActorType(characterFromID("soldier4X"));
			LAi_SetActorType(characterFromID("soldier5X"));
			LAi_SetActorType(characterFromID("soldier6X"));
			LAi_SetActorType(characterFromID("soldier7X"));
			LAi_SetActorType(characterFromID("soldier8X"));
			
			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire1", "", -1, -18.5, 1.5, 14.289, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -18.5, 1.5, 14.289, -2.6805, 0.0, 0.0,0);

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire1", "", -1, -5.4461, 2.5, 6.8121, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -5.4461, 2.5, 6.8121, -1.317, 0.0, 0.0,0);

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire1", "", -1, -5.6766, 3.0, 6.8121, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -5.6766, 3.0, 6.8121, -1.317, 0.0, 0.0,0);

			LAi_ActorRunToLocator(characterFromID("Rifleman Higgins"), "goto", "goto34", "", 15.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Cooper"), "goto", "goto33", "", 15.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Haggman"), "goto", "goto26", "", 15.0);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "In_the_outskirts";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Go_to_Mr_Matthews":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_QuestDelay("Go_to_Mr_Matthews2", 1.0);
		break;

		case "Go_to_Mr_Matthews2":
			LAi_ActorRunToLocator(characterFromID("Matthews"), "goto", "goto57", "Antigua_Land_battle3", 6.0);
			LAi_ActorRunToLocator(characterFromID("Oldroyd"), "goto", "goto58", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Styles"), "goto", "goto29", "", 0.0);
		break;

		case "Antigua_Land_battle3":
			LAi_SetStayType(characterFromID("Matthews"));
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("Antigua_Land_battle3_1", 1.0);
		break;

		case "Antigua_Land_battle3_1":
			CreateParticleSystemX("blast_inv", -22.122, -0.62642, 23.738, 1.7537, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -22.122, -0.62642, 23.738, 1.7537, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -22.122, -0.62642, 23.738, 1.7537, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire1", "", -1, -22.122, -0.62642, 23.738, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -22.122, -0.62642, 23.738, 1.7537, 0.0, 0.0,0);

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire2", "", -1, -22.122, 0.62642, 23.738, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -22.122, 0.62642, 23.738, 1.7537, 0.0, 0.0,0);

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire3", "", -1, -22.0, 1.0, 23.738, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -22.0, 1.0, 23.738, 1.7537, 0.0, 0.0,0);

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire4", "", -1, -23.575, 1.0, 26.57, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -23.575, 1.0, 26.57, -1.9035, 0.0, 0.0,0);

			LAi_QuestDelay("Antigua_Land_battle3AAA", 0.0);
		break;

		case "Antigua_Land_battle3AAA":
			Lai_KillCharacter(characterFromID("soldierG1B"));

			Pchar.quest.gets_blown_up.win_condition.l1 = "locator";
			Pchar.quest.gets_blown_up.win_condition.l1.character = Pchar.id;
			Pchar.quest.gets_blown_up.win_condition.l1.location = "Antigua_outskirts";
			Pchar.quest.gets_blown_up.win_condition.l1.locator_group = "goto";
			Pchar.quest.gets_blown_up.win_condition.l1.locator = "goto25";
			Pchar.quest.gets_blown_up.win_condition = "gets_blown_up";

			Pchar.quest.Antigua_Land_battle4.win_condition.l1 = "locator";
			Pchar.quest.Antigua_Land_battle4.win_condition.l1.character = Pchar.id;
			Pchar.quest.Antigua_Land_battle4.win_condition.l1.location = "Antigua_outskirts";
			Pchar.quest.Antigua_Land_battle4.win_condition.l1.locator_group = "goto";
			Pchar.quest.Antigua_Land_battle4.win_condition.l1.locator = "goto51";
			Pchar.quest.Antigua_Land_battle4.win_condition = "Antigua_Land_battle4";

			Pchar.quest.Shot_by_the_French.win_condition.l1 = "locator";
			Pchar.quest.Shot_by_the_French.win_condition.l1.character = Pchar.id;
			Pchar.quest.Shot_by_the_French.win_condition.l1.location = "Antigua_outskirts";
			Pchar.quest.Shot_by_the_French.win_condition.l1.locator_group = "goto";
			Pchar.quest.Shot_by_the_French.win_condition.l1.locator = "goto72";
			Pchar.quest.Shot_by_the_French.win_condition = "Shot_by_the_French";

			Pchar.quest.French_shoot_player.win_condition.l1 = "locator";
			Pchar.quest.French_shoot_player.win_condition.l1.character = Pchar.id;
			Pchar.quest.French_shoot_player.win_condition.l1.location = "Antigua_outskirts";
			Pchar.quest.French_shoot_player.win_condition.l1.locator_group = "goto";
			Pchar.quest.French_shoot_player.win_condition.l1.locator = "goto73";
			Pchar.quest.French_shoot_player.win_condition = "French_shoot_player";
		break;

		case "gets_blown_up":
			Pchar.Quest.Antigua_French_Valley.over = "yes";
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("gets_blown_up1", 1.0);
		break;

		case "gets_blown_up1":
			CreateParticleSystemX("blast_inv", -10.749, 0.39496, 22.555, -0.52835, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -10.749, 0.39496, 22.555, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -10.749, 0.39496, 22.555, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Player_gets_blown_up2", 0.0);
		break;

		case "Player_gets_blown_up2":
			Lai_KillCharacter(Pchar);
			LAi_QuestDelay("Player_gets_blown_up3", 2.0);
		break;

		case "Player_gets_blown_up3":
			LAi_QuestDelay("KilledFighting", 0.0);
		break;

		case "Shot_by_the_French":
			CreateParticleSystemX("blast_inv", 3.8167, 0.97968, 108.32, -2.9496, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 3.8167, 0.97968, 108.32, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 3.8167, 0.97968, 108.32, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");

			LAi_QuestDelay("Cannon_explosion", 1.0);
		break;

		case "Cannon_explosion":
			CreateParticleSystemX("blast_inv", -8.0892, 2.1621, 55.201, 1.0, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -8.0892, 2.1621, 55.201, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -8.0892, 2.1621, 55.201, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Player_gets_blown_up2", 1.0);
		break;

		case "French_shoot_player":
			CreateParticleSystemX("blast_inv", 3.8167, 0.97968, 108.32, -2.9496, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 3.8167, 0.97968, 108.32, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 3.8167, 0.97968, 108.32, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");

			LAi_QuestDelay("Cannon_explosionA2", 1.0);
		break;

		case "Cannon_explosionA2":
			CreateParticleSystemX("blast_inv", -5.5041, 1.7323, 49.54, 0.99246, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -5.5041, 1.7323, 49.54, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -5.5041, 1.7323, 49.54, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Player_gets_blown_up2", 1.0);
		break;
// End TRAPS
		case "Antigua_Land_battle4":
			Pchar.Quest.gets_blown_up.over = "yes";
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "we_must_knock_out_their_cannon";
		break;

		case "Sharpe_sends_out_Patrick":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Send_out_snipers";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Matthews_firing_instructions":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_ActorRunToLocation(characterFromID("Rifleman Tongue"), "goto", "goto28", "none", "", "", "",10.0);
			LAi_ActorRunToLocation(characterFromID("Patrick Harper"), "goto", "goto28", "none", "", "", "",10.0);
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "firing_instructions";
		break;

		case "Ready_to_fire_cannon":
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator((Pchar), "goto", "goto37", "Going_to_fire_cannon", 6.0);
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_outskirts", "goto", "goto35");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_outskirts", "goto", "goto36");
		break;

		case "Going_to_fire_cannon":
			LAi_ActorGoToLocator(characterFromID("soldier1X"), "goto", "goto16", "Watch_the_French", 5.0);
			LAi_ActorGoToLocator(characterFromID("soldier2X"), "goto", "goto17", "", 5.0);
			LAi_ActorGoToLocator(characterFromID("soldier3X"), "goto", "goto18", "", 5.0);
			LAi_ActorGoToLocator(characterFromID("soldier4X"), "goto", "goto19", "", 5.0);
			LAi_ActorGoToLocator(characterFromID("soldier5X"), "goto", "goto20", "", 5.0);
			LAi_ActorGoToLocator(characterFromID("soldier6X"), "goto", "goto21", "", 5.0);
			
			LAi_ActorTurnToCharacter((Pchar), characterFromID("soldier3X"));
		break;

		case "Watch_the_French":
			LAi_SetPlayerType(pchar);
			LAi_QuestDelay("Fire_cannon1", 1.0);
		break;
// cannon 1
		case "Fire_cannon1":
			CreateParticleSystemX("blast_inv", 3.8167, 0.97968, 108.32, -2.9496, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 3.8167, 0.97968, 108.32, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 3.8167, 0.97968, 108.32, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Cannon_bang_OneXXX", 0.0);
		break;

		case "Cannon_bang_OneXXX":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("Cannon_bang_One", 1.0);
		break;

		case "Cannon_bang_One":
			CreateParticleSystemX("blast_inv", -5.5041, 1.7323, 49.54, 0.99246, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -5.5041, 1.7323, 49.54, 0.99246, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -5.5041, 1.7323, 49.54, 0.99246, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Fire_cannon2", 1.0);
		break;
// cannon 2
		case "Fire_cannon2":
			CreateParticleSystemX("blast_inv", 12.879, 0.14554, 107.56, -3.0157, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 12.879, 0.14554, 107.56, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 12.879, 0.14554, 107.56, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Cannon_bang_TwoXXX", 0.0);
		break;

		case "Cannon_bang_TwoXXX":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("Cannon_bang_Two", 1.0);
		break;

		case "Cannon_bang_Two":
			CreateParticleSystemX("blast_inv", -9.5927, 0.19974, 9.6287, 0.041649, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -9.5927, 0.19974, 9.6287, 0.041649, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -9.5927, 0.19974, 9.6287, 0.041649, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire5", "", -1, -23.575, 2.0, 26.57, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -23.575, 2.0, 26.57, -1.9035, 0.0, 0.0,0);

			LAi_QuestDelay("Fire_cannon3", 1.0);
		break;
// cannon 3
		case "Fire_cannon3":
			CreateParticleSystemX("blast_inv", 23.234, 0.64429, 105.12, -2.8216, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 23.234, 0.64429, 105.12, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 23.234, 0.64429, 105.12, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Cannon_bang_ThreeXXX", 0.0);
		break;

		case "Cannon_bang_ThreeXXX":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("Cannon_bang_Three", 1.0);
		break;

		case "Cannon_bang_Three":
			CreateParticleSystemX("blast_inv", -12.354, 0.25733, 23.062, 0.15646, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -12.354, 0.25733, 23.062, 0.15646, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -12.354, 0.25733, 23.062, 0.15646, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire6", "", -1, -9.5927, 0.2, 9.6287, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", -9.5927, 0.2, 9.6287, 0.041649, 0.0, 0.0,0);

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire7", "", -1, -9.5927, 2.0, 9.6287, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 12.0; 
			CreateParticleSystemX("fireball", -9.5927, 2.0, 9.6287, 0.041649, 0.0, 0.0,0);

			LAi_QuestDelay("Fire_British_one", 1.0);
		break;
// Brit cannon
		case "Fire_British_one":
			CreateParticleSystemX("blast_inv", -12.115, 2.8464, 48.167, -1.404, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -12.115, 2.8464, 48.167, 0.0, 0.0, 0.0,20); // ay = -1.404 
			CreateParticleSystemX("cancloud", -12.115, 2.8464, 48.167, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("British_Bang_OneXXX", 0.0);
		break;

		case "British_Bang_OneXXX":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("British_Bang_One", 1.0);
		break;

		case "British_Bang_One":
			CreateParticleSystemX("blast_inv", 9.9351, -0.9602, 105.36, 0.65145, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 9.9351, -0.9602, 105.36, 0.65145, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 9.9351, -0.9602, 105.36, 0.65145, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("the_Cannon_fired", 1.0);
		break;

		case "the_Cannon_fired":
			LAi_SetActorType(characterFromID("Matthews"));
			LAi_ActorRunToLocator(characterFromID("Matthews"), "goto", "goto4", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Oldroyd"), "goto", "goto31", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Styles"), "goto", "goto32", "the_Cannon_fired2", 9.0);

			LAi_ActorRunToLocator(characterFromID("soldier1X"), "goto", "goto38", "", 5.0);
			LAi_ActorRunToLocator(characterFromID("soldier2X"), "goto", "goto39", "", 5.0);
			LAi_ActorRunToLocator(characterFromID("soldier3X"), "goto", "goto40", "", 5.0);
			LAi_ActorRunToLocator(characterFromID("soldier4X"), "goto", "goto41", "", 5.0);
			LAi_ActorRunToLocator(characterFromID("soldier5X"), "goto", "goto42", "", 5.0);
			LAi_ActorRunToLocator(characterFromID("soldier6X"), "goto", "goto43", "", 5.0);

			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "second_cannon_shot";
		break;

		case "the_Cannon_fired2":
			LAi_ActorTurnToCharacter(characterFromID("Styles"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Oldroyd"),characterFromID("Styles"));
			LAi_QuestDelay("the_Cannon_fired3", 1.0);
		break;

		case "the_Cannon_fired3":
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialogNow(characterFromID("Matthews"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
		break;

		case "Clear_for_firing":
			LAi_ActorRunToLocator(characterFromID("Oldroyd"), "goto", "goto57", "take_out_a_cannon", 0.0);
			LAi_ActorRunToLocator(characterFromID("Styles"), "goto", "goto50", "", 0.0);
		break;

		case "take_out_a_cannon":
			CreateParticleSystemX("blast_inv", -12.115, 2.8464, 48.167, -1.404, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -12.115, 2.8464, 48.167, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -12.115, 2.8464, 48.167, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");

			LAi_QuestDelay("British_Bang_TwoXXX", 0.0);
		break;

		case "British_Bang_TwoXXX":
			LAi_ActorGoToLocator(characterFromID("Matthews"), "goto", "goto52", "British_Bang_Two", 3.0);
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_outskirts", "goto", "goto35");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_outskirts", "goto", "goto35");
		break;

		case "British_Bang_Two":
			CreateParticleSystemX("blast_inv", 13.924, -0.83922, 108.78, -1.1836, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 13.924, -0.83922, 108.78, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 13.924, -0.83922, 108.78, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire7", "", -1, 13.924, -0.83922, 109.39, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 20.0; 
			CreateParticleSystemX("fireball", 13.924, -0.83922, 109.39, -1.1836, 0.0, 0.0,0);
			
			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire7", "", -1, 13.924, 0.63922, 109.39, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 20.0; 
			CreateParticleSystemX("fireball", 13.924, 0.63922, 109.39, -1.1836, 0.0, 0.0,0);

			Lai_KillCharacter(characterFromID("soldier3X"));
			Lai_KillCharacter(characterFromID("soldier4X"));
			Lai_KillCharacter(characterFromID("soldier9X"));

			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "A_hit_sir_A_hit";
			LAi_QuestDelay("A_Hit_A_Hit", 1.0);
		break;

		case "A_Hit_A_Hit":
			LAi_SetPlayerType(pchar);

			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialogNow(characterFromID("Matthews"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
		break;

		case "The_French_back_off":
			LAi_ActorRunToLocator(characterFromID("Rifleman Tongue"), "goto", "goto53", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Patrick Harper"), "goto", "goto54", "",0.0);

			LAi_ActorRunToLocator(characterFromID("Oldroyd"), "goto", "goto31", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Styles"), "goto", "goto32", "", 0.0);

			LAi_ActorRunToLocator(characterFromID("Soldier1X"), "goto", "goto22", "", 8.0);
			LAi_ActorRunToLocator(characterFromID("Soldier2X"), "goto", "goto23", "", 8.0);
			LAi_ActorRunToLocator(characterFromID("Soldier5X"), "goto", "goto24", "", 8.0);
			LAi_ActorRunToLocator(characterFromID("Soldier6X"), "goto", "goto7", "", 8.0);
			LAi_ActorRunToLocator(characterFromID("Soldier7X"), "goto", "goto13", "", 8.0);
			LAi_ActorRunToLocator(characterFromID("Soldier8X"), "goto", "goto22", "", 8.0);
			LAi_QuestDelay("Watch_the_French_for_a_minute", 10.0);
		break;

		case "Watch_the_French_for_a_minute":
			LAi_ActorRunToLocator(characterFromID("soldier1X"), "goto", "goto16", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("soldier2X"), "goto", "goto17", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("soldier7X"), "goto", "goto47", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("soldier8X"), "goto", "goto45", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("soldier5X"), "goto", "goto20", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("soldier6X"), "goto", "goto21", "", 0.0);

			LAi_ActorTurnToCharacter(characterFromID("Oldroyd"),characterFromID("Styles"));
			LAi_ActorTurnToCharacter(characterFromID("Matthews"),characterFromID("Patrick Harper"));
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "The_riflemen_in_position";
			LAi_QuestDelay("Some_gunners_return", 1.0);
		break;

		case "Some_gunners_return":
			LAi_ActorRunToLocator(characterFromID("Oldroyd"), "goto", "goto37", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Styles"), "goto", "goto50", "", 0.0);

			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialogNow(characterFromID("Matthews"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
		break;

		case "Some_gunners_die":
			LAi_ActorTurnToCharacter(characterFromID("Matthews"),characterFromID("Patrick Harper"));
			LAi_QuestDelay("Some_gunners_dieXXX", 8.0);
		break;

		case "Some_gunners_dieXXX":
			LAi_ActorTurnToCharacter(characterFromID("Matthews"),characterFromID("Patrick Harper"));
			ChangeCharacterAddressGroup(characterFromID("soldier2X"), "Antigua_outskirts", "goto", "goto17");
			LAi_QuestDelay("Some_gunners_die111X", 0.0);
		break;

		case "Some_gunners_die111X":
			LAi_ActorAnimation(characterFromID("Patrick Harper"), "shot", "Some_gunners_die2", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Patrick Harper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Some_gunners_die2":
			LAi_SetActorType(characterFromID("Patrick Harper"));
			Lai_KillCharacter(characterFromID("soldier2X"));

			LAi_ActorAnimation(characterFromID("Rifleman Tongue"), "shot", "Some_gunners_die3", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Tongue"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "a_second_retreat";
		break;

		case "Some_gunners_die3":
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			Lai_KillCharacter(characterFromID("soldier5X"));

			LAi_ActorRunToLocator(characterFromID("Soldier1X"), "goto", "goto22", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Soldier6X"), "goto", "goto7", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Soldier7X"), "goto", "goto13", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Soldier8X"), "goto", "goto22", "", 0.0);

			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Antigua_outskirts", "goto", "goto51");
			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));

			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialogNow(characterFromID("Matthews"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
		break;

		case "Where_are_the_reinforcements":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Arthur Wellesley"));

			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("Richard Sharpe"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier1X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier6X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier7X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier8X"), "None", "");

			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.currentnode = "The_reinforcements";
			LAi_QuestDelay("Reinforcements_Sir2X", 1.0);
		break;

		case "Reinforcements_Sir2X":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialogNow(characterFromID("Arthur Wellesley"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Arthur Wellesley"),PChar,"",5.0,5.0);

			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "Change_orders";
		break;

		case "Hold_the_line":
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(characterFromID("Arthur Wellesley"), "reload", "reload2", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Styles"), "goto", "goto27", "", 0.0);

			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Antigua_outskirts", "goto", "goto44");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Antigua_outskirts", "goto", "goto46");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_outskirts", "goto", "goto16");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_outskirts", "goto", "goto47");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_outskirts", "goto", "goto20");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Antigua_outskirts", "goto", "goto48");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Antigua_outskirts", "goto", "goto49");
			LAi_QuestDelay("Hold_the_line2", 3.0);
		break;

		case "Hold_the_line2":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialogNow(characterFromID("Matthews"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
		break;

		case "Go_to_the_guns":
			Pchar.Quest.Shot_by_the_French.over = "yes";
			Pchar.Quest.French_shoot_player.over = "yes";
			ChangeCharacterAddress(characterFromID("Arthur Wellesley"), "None", "");
			LAi_ActorGoToLocator(characterFromID("Matthews"), "goto", "goto4", "", 0.0);
/*			Locations[FindLocation("Antigua_outskirts")].locators_radius.goto.goto60 = 5.0;

			Pchar.quest.Quelp_has_some_information.win_condition.l1 = "locator";
			Pchar.quest.Quelp_has_some_information.win_condition.l1.character = Pchar.id;
			Pchar.quest.Quelp_has_some_information.win_condition.l1.location = "Antigua_outskirts";
			Pchar.quest.Quelp_has_some_information.win_condition.l1.locator_group = "goto";
			Pchar.quest.Quelp_has_some_information.win_condition.l1.locator = "goto60";
			Pchar.quest.Quelp_has_some_information.win_condition = "Quelp_has_some_information";
		break;

		case "Quelp_has_some_information":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp")); */
			LAi_SetGuardianType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
//			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "An_interesting_find";
		break;

		case "Sharpe_asks_questiions":
			Locations[FindLocation("Antigua_Jungle_02")].vcskip = true;
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Midshipman_again";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Follow_the_French":
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Rifleman Tongue"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Rifleman Haggman"));
			LAi_SetOfficerType(characterFromID("Rifleman Mansfield"));
			LAi_SetOfficerType(characterFromID("Rifleman Harris"));
			GiveItem2Character(characterFromID("Richard Sharpe"), "pistol8"); // GR: Sharpe will need a brace of pistols later

			ChangeCharacterAddressGroup(characterFromID("Rifleman Archer"), "Antigua_Jungle_02", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Evans"), "Antigua_Jungle_02", "goto", "goto2");
			LAi_ActorAnimation(characterFromID("Rifleman Archer"), "Lay_1", "", -1);
			LAi_ActorAnimation(characterFromID("Rifleman Evans"), "Lay_1", "", -1);

			pchar.quest.a_gruesome_find.win_condition.l1 = "location";
			Pchar.quest.a_gruesome_find.win_condition.l1.character = Pchar.id;
			pchar.quest.a_gruesome_find.win_condition.l1.location = "Antigua_Jungle_02";
			pchar.quest.a_gruesome_find.win_condition = "a_gruesome_find";
		break;

		case "a_gruesome_find":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);

			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_Jungle_02", "officers", "reload3_1");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_Jungle_02", "officers", "reload3_1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_Jungle_02", "officers", "reload3_1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Antigua_Jungle_02", "officers", "reload3_2");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Antigua_Jungle_02", "officers", "reload3_2");
			ChangeCharacterAddressGroup(characterfromID("Lt. Uriah Quelp"), "Antigua_Jungle_02", "officers", "reload3_3");
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Mansfield"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Protective_Ring";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Riflemen_executed":
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator((Pchar), "goto", "goto3", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Tongue"), "goto", "goto6", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Patrick Harper"), "goto", "goto8", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Haggman"), "goto", "goto7", "",0.0);

			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "goto5", "What_happened_here",25.0);
			LAi_ActorGoToLocator(characterFromID("Lt. Uriah Quelp"), "goto", "goto4", "",0.0);
		break;

		case "What_happened_here":
			LAi_QuestDelay("What_happened_here2", 2.0);
		break;

		case "What_happened_here2":
			LAi_SetPlayerType(pchar);
			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"),(Pchar));
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "goto3", "",0.0);
			LAi_QuestDelay("What_happened_here3", 2.0);
		break;

		case "What_happened_here3":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Shot_in_the_back";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Quelp_moves_them_along":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "We_should_move_on";
		break;

		case "Harper_and_the_miner":
			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "Spoke_with_miner";
		break;

		case "Sharpe_and_the_burial":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Bury_the_men";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Quelp_leads_to_the_beach":
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "goto7", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Lt. Uriah Quelp"), "goto", "citizen02", "",0.0);
			LAi_QuestDelay("Sharpe_isn't_sure", 4.0);
		break;
// CHOICES made here:
		case "Sharpe_isn't_sure":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Choice_of_action";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;
// CHOICE 1 & 2
		case "Where_are_the_French":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			pchar.quest.an_empty_beach.win_condition.l1 = "location";
			Pchar.quest.an_empty_beach.win_condition.l1.character = Pchar.id;
			pchar.quest.an_empty_beach.win_condition.l1.location = "Antigua_shore";
			pchar.quest.an_empty_beach.win_condition = "an_empty_beach";
		break;

		case "an_empty_beach":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			LAi_ActorRunToLocator(characterFromID("Lt. Uriah Quelp"), "goto", "locator27", "",0.0);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_QuestDelay("an_empty_beach2", 3.0);
		break;

		case "an_empty_beach2":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Somethings_wrong";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Quelp_returns_from_beach":
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_QuestDelay("Quelp_returns_from_beach2", 2.0);
		break;

		case "Quelp_returns_from_beach2":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "There's_nothing_here";
		break;

		case "a_group_discussion":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "The_bodies";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "a_group_discussion2":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "The_trick_exposed";
		break;

		case "a_group_discussion3":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Prepare_counter_attack";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Back_to_the_Valley":
			Build_at("Antigua_Jungle_02", "Field_Cannon_1", "", 7.314, 0.0108, 16.746, 3.300, "");
			Locations[FindLocation("Antigua_Jungle_02")].vcskip = true;
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			pchar.quest.Other_French_Valley_Trap.win_condition.l1 = "location";
			Pchar.quest.Other_French_Valley_Trap.win_condition.l1.character = Pchar.id;
			pchar.quest.Other_French_Valley_Trap.win_condition.l1.location = "Antigua_Jungle_02";
			pchar.quest.Other_French_Valley_Trap.win_condition = "Other_French_Valley_Trap";
		break;

		case "Other_French_Valley_Trap":
			LAi_SetActorType(pchar);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto32");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto33");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto34");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));
			LAi_QuestDelay("Other_French_Valley_Trap2", 2.0);
		break;

		case "Other_French_Valley_Trap2":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Some_rear_guard";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "turn_to_French_gun":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter((Pchar), characterFromID("soldier3X"));
			LAi_QuestDelay("Other_French_Valley_Trap2AA", 3.0);
		break;

		case "Other_French_Valley_Trap2AA":
			LAi_SetActorType(PChar);
			CreateParticleSystemX("blast_inv", 9.2328, 0.815108, 16.672, 1.5466, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 9.2328, 0.815108, 16.672, 1.5466, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 9.2328, 0.815108, 16.672, 1.5466, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Other_French_Valley_Trap3", 1.0);
		break;

		case "Other_French_Valley_Trap3":
			CreateParticleSystemX("blast_inv", 32.631, -0.065334, 16.931, 1.0, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 32.631, -0.065334, 16.931, 1.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 32.631, -0.065334, 16.931, 1.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Player_gets_blown_up2", 0.0);
		break;

		case "We all get killed":
			Lai_KillCharacter(Pchar);
			Lai_KillCharacter(characterFromID("Lt. Uriah Quelp"));
			Lai_KillCharacter(characterFromID("Richard Sharpe"));
			LAi_QuestDelay("We all get killed2", 5.0);
		break;

		case "We all get killed2":
			LAi_QuestDelay("KilledFighting", 0.0);
		break;

		case "Prison_with_Sharpe":
			Locations[FindLocation("PaP_prison")].vcskip = true;
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto32", "", 0.0);
			LAi_QuestDelay("Prison_with_Sharpe2", 3.0);
		break;

		case "Prison_with_Sharpe2":
			LAi_Fade("", "");
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "In_the_French_prison";
			DoQuestReloadToLocation("PaP_prison", "goto", "goto24", "Prison_with_Sharpe3");
		break;

		case "Prison_with_Sharpe3":
			LAi_SetPlayerType(pchar);
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "PaP_prison", "goto", "goto9");
			LAi_QuestDelay("Prison_with_Sharpe4", 0.0);
		break;

		case "Prison_with_Sharpe4":
			RemoveCharacterEquip(characterFromID("Richard Sharpe"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Richard Sharpe"), GUN_ITEM_TYPE);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialogNow(characterFromID("Richard Sharpe"),PChar,"",1.0);
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
		break;
// CHOICE 3
		case "We_will_go_another_way":
			LAi_SetActorType(PChar);
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			LAi_QuestDelay("We_will_go_another_way2", 5.0);
		break;

		case "We_will_go_another_way2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "A_different_plan";
		break;

		case "Sharpe_has_a_ruse":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Catch_the_French_out";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Our_ruse_begins":
			AddQuestRecord("Attack on Antigua", 2);
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Rifleman Haggman"));
			LAi_SetOfficerType(characterFromID("Rifleman Tongue"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));

			pchar.quest.Wait_for_Mansfield.win_condition.l1 = "location";
			Pchar.quest.Wait_for_Mansfield.win_condition.l1.character = Pchar.id;
			pchar.quest.Wait_for_Mansfield.win_condition.l1.location = "Antigua_shore";
			pchar.quest.Wait_for_Mansfield.win_condition = "Wait_for_Mansfield";

			pchar.quest.French_Valley_Trap.win_condition.l1 = "location";
			Pchar.quest.French_Valley_Trap.win_condition.l1.character = Pchar.id;
			pchar.quest.French_Valley_Trap.win_condition.l1.location = "Antigua_Jungle_01";
			pchar.quest.French_Valley_Trap.win_condition = "French_Valley_Trap";
		break;
// TRAP
		case "French_Valley_Trap":
			Pchar.Quest.Wait_for_Mansfield.over = "yes";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_QuestDelay("Antigua_French_Valley_Trap2", 0.0);
		break;

		case "Antigua_French_Valley_Trap2":
			LAi_SetActorType(pchar);
			LAi_QuestDelay("Antigua_French_Valley_Trap3", 3.0);
		break;

		case "Antigua_French_Valley_Trap3":
			CreateParticleSystemX("blast_inv", -37.548, 0.831665, -7.1746, -0.69242, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -37.548, 0.831665, -7.1746, -0.69242, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -37.548, 0.831665, -7.1746, -0.69242, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Antigua_French_Valley_Trap4", 1.0);
		break;

		case "Antigua_French_Valley_Trap4":
			CreateParticleSystemX("blast_inv", -51.974, 0.031665, 12.411, 1.0, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -51.974, 0.031665, 12.411, 1.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -51.974, 0.031665, 12.411, 1.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			LAi_QuestDelay("Player_gets_blown_up2", 0.0);
		break;
// END TRAP
		case "Wait_for_Mansfield":
			Pchar.Quest.French_Valley_Trap.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_shore", "reload", "reload2_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_shore", "reload", "reload2_back");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_shore", "reload", "reload2_back");
			LAi_QuestDelay("Wait_for_Mansfield2", 2.0);
		break;

		case "Wait_for_Mansfield2":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "It_won't_be_long";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Mansfield_arrives":
			ChangeCharacterAddress(characterFromID("Rifleman Archer"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Evans"), "None", "");
			Locations[FindLocation("Antigua_Jungle_02")].vcskip = true;
			LAi_QuestDelay("Mansfield_arrives2", 5.0);
		break;

		case "Mansfield_arrives2":
			LAi_SetActorType(characterFromID("Rifleman Mansfield"));
			characters[GetCharacterIndex("Rifleman Mansfield")].Dialog.Filename = "Rifleman Mansfield_dialog.c";
			Characters[GetCharacterIndex("Rifleman Mansfield")].dialog.CurrentNode = "Job_done_Sir";
			LAi_ActorDialog(characterFromID("Rifleman Mansfield"), pchar, "", 1.0, 1.0);
		break;

		case "Our_ruse_continues":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			Locations[FindLocation("Antigua_Jungle_02")].vcskip = true;
			Locations[FindLocation("Antigua_Jungle_01")].vcskip = true;

			pchar.quest.Ready_for_the_Valley.win_condition.l1 = "location";
			Pchar.quest.Ready_for_the_Valley.win_condition.l1.character = Pchar.id;
			pchar.quest.Ready_for_the_Valley.win_condition.l1.location = "Antigua_Jungle_02";
			pchar.quest.Ready_for_the_Valley.win_condition = "Ready_for_the_Valley";
		break;

		case "Ready_for_the_Valley":
			pchar.quest.French_Valley_Trap.win_condition.l1 = "location";
			Pchar.quest.French_Valley_Trap.win_condition.l1.character = Pchar.id;
			pchar.quest.French_Valley_Trap.win_condition.l1.location = "Antigua_Jungle_01";
			pchar.quest.French_Valley_Trap.win_condition = "French_Valley_Trap";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto26");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto23");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "soldierG2B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "goto20");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "soldierG3B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "goto17");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "soldierG4B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "goto", "goto14");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "soldierG5B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto15");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "soldierG6B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto18");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "soldierG7B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto21");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "soldierG8B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto24");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "soldierG9B";

			LAi_SetImmortal(characterFromID("Arthur Wellesley"), true);
			ChangeCharacterAddressGroup(characterFromID("The Earl of Edrington"), "Antigua_Jungle_02", "goto", "goto11");
			ChangeCharacterAddressGroup(characterFromID("William Chumley"), "Antigua_Jungle_02", "goto", "goto10");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Antigua_Jungle_02", "goto", "goto25");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_Jungle_02", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_Jungle_02", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_Jungle_02", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Antigua_Jungle_02", "reload", "reload1_back");
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "citizen02", "Ready_for_the_Valley2", 0.0);
		break;

		case "Ready_for_the_Valley2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "citizen08");
			sld.id = "soldier1X";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "citizen08");
			sld.id = "soldier3X";

			LAi_SetActorType(characterFromID("soldier1X"));
//			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));

			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Antigua_Jungle_02", "officers", "reload2_1");
			GiveItem2Character(characterFromID("Arthur Wellesley"), "blade4");
			EquipCharacterByItem(characterFromID("Arthur Wellesley"), "blade4");
			LAi_SetStayType(characterFromID("Arthur Wellesley"));

			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Rifleman Mansfield"));
			LAi_SetPlayerType(pchar);

			LAi_SetActorType(characterFromID("The Earl of Edrington"));
			characters[GetCharacterIndex("The Earl of Edrington")].Dialog.Filename = "The Earl of Edrington_dialog.c";
			LAi_ActorDialog(characterFromID("The Earl of Edrington"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("The Earl of Edrington")].dialog.CurrentNode = "Who's_in_charge";
		break;

		case "On_to_the_Valley_for_battle":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetStayType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Arthur Wellesley"));
			LAi_QuestDelay("On_to_the_Valley_for_battle2", 2.0);
		break;

		case "On_to_the_Valley_for_battle2":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "goto8", "On_to_the_Valley_for_battle3",10.0);
			LAi_ActorRunToLocator(characterFromID("Soldier1X"), "goto", "goto29", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Soldier3X"), "goto", "goto31", "",0.0);
		break;

		case "On_to_the_Valley_for_battle3":
			LAi_ActorAnimation(characterFromID("Richard Sharpe"), "shot", "Wellesley_Fight3", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Richard Sharpe"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Wellesley_Fight3":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Lai_KillCharacter(characterFromID("soldier3X"));
			LAi_QuestDelay("Wellesley_Fight4", 1.0);
		break;

		case "Wellesley_Fight4":
			LAi_SetPlayerType(pchar);
			LAi_ActorAnimation(characterFromID("Richard Sharpe"), "shot", "Wellesley_Fight5", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Richard Sharpe"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Wellesley_Fight5":
			Lai_KillCharacter(characterFromID("soldier1X"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));
			LAi_QuestDelay("Wellesley_Fight_over", 5.0);
		break;

		case "Wellesley_Fight_over":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Safe_only_just";
		break;

		case "Wellesley_Fight_over2":
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Safe_and_Promotion";
		break;

		case "Sharpe_Promoted":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Answer_with_Name";
			LAi_ActorDialog(characterFromID("Richard Sharpe"), pchar, "", 1.0, 1.0);
		break;

		case "Promotion_confirmed":
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Promotion_Confirmed";
		break;

		case "Battle_Preparations_Antigua":
			pchar.quest.Soldier_Company = "Lieutenant";
			SetModelfromArray(characterFromID("Richard Sharpe"), GetModelIndex("SharpeL_Rif7_18"));
			Characters[GetCharacterIndex("Richard Sharpe")].headmodel = "h_SharpeL_Rif7_18";
			SetModelfromArray(characterFromID("Patrick Harper"), GetModelIndex("Harper_Sergeant"));
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Harper_Sergeant";
			LAi_ActorGoToLocator(characterFromID("Arthur Wellesley"), "reload", "reload3_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Harris"), "goto", "goto1", "",0.0);

			LAi_SetActorType(characterFromID("The Earl of Edrington"));
			characters[GetCharacterIndex("The Earl of Edrington")].Dialog.Filename = "The Earl of Edrington_dialog.c";
			LAi_ActorDialog(characterFromID("The Earl of Edrington"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("The Earl of Edrington")].dialog.CurrentNode = "Awoke_the_French";
		break;

		case "The_final_stand":
			ChangeCharacterAddress(characterFromID("Arthur Wellesley"), "None", "");

			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetActorType(characterFromID("William Chumley"));
			LAi_SetActorType(characterFromID("soldierG1B"));
			LAi_SetActorType(characterFromID("soldierG2B"));
			LAi_SetActorType(characterFromID("soldierG3B"));
			LAi_SetActorType(characterFromID("soldierG4B"));
			LAi_SetActorType(characterFromID("soldierG5B"));

			LAi_ActorGoToLocator(characterFromID("Lt. Uriah Quelp"), "reload", "reload1_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("William Chumley"), "reload", "reload1_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("soldierG1B"), "reload", "reload1_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("soldierG2B"), "reload", "reload1_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("soldierG3B"), "reload", "reload1_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("soldierG4B"), "reload", "reload1_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("soldierG5B"), "reload", "reload1_back", "",0.0);
			LAi_QuestDelay("The_final_stand2", 5.0);
		break;

		case "The_final_stand2":
			LAi_SetActorType(characterFromID("The Earl of Edrington"));
			characters[GetCharacterIndex("The Earl of Edrington")].Dialog.Filename = "The Earl of Edrington_dialog.c";
			LAi_ActorDialog(characterFromID("The Earl of Edrington"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("The Earl of Edrington")].dialog.CurrentNode = "About_face";
		break;

		case "The_final_stand3":
			Characters[GetCharacterIndex("The Earl of Edrington")].dialog.CurrentNode = "First time";
			LAi_SetActorType(characterFromID("soldierG6B"));
			LAi_SetActorType(characterFromID("soldierG7B"));
			LAi_SetActorType(characterFromID("soldierG8B"));
			LAi_SetActorType(characterFromID("soldierG9B"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG6B"),characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG7B"),characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG8B"),characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG9B"),characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("Patrick Harper"),characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Tongue"),characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Mansfield"),characterFromID("Rifleman Harris"));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Haggman"),characterFromID("Rifleman Harris"));
			LAi_QuestDelay("The_final_stand4", 2.0);
		break;

		case "The_final_stand4":
			LAi_ActorGoToLocator(characterFromID("soldierG6B"), "reload", "reload3_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("soldierG7B"), "reload", "reload3_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("soldierG8B"), "reload", "reload3_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("soldierG9B"), "reload", "reload3_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "reload", "reload3_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "reload", "reload3_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Mansfield"), "reload", "reload3_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "reload", "reload3_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Harris"), "reload", "reload3_back", "",0.0);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("The Earl of Edrington"));
			LAi_QuestDelay("The_final_stand5", 2.0);
		break;

		case "The_final_stand5":
			AddQuestRecord("Attack on Antigua", 3);
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			ChangeCharacterAddress(characterFromID("William Chumley"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG5B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG4B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG3B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG2B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG1B"), "None", "");

			port = &Locations[FindLocation("Antigua_outskirts")];
			If(CheckAttribute(port,"building")) DeleteAttribute(port,"building");
			LAi_QuestDelay("Defending_the_outskirts", 1.0);
		break;

		case "Defending_the_outskirts":
			Locations[FindLocation("Antigua_outskirts")].vcskip = true;
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. Uriah Quelp"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Uriah Quelp"));

			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemoveCharacterCompanion(Pchar, characterFromID("Richard Sharpe"));

			Build_at("Antigua_outskirts", "Field_Cannon_broken", "", 13.133, -0.91791, 109.39, -1.3042, "");

			Build_at("Antigua_outskirts", "cannonl", "", -12.881, 1.8755, 45.963, -1.0805, "");
			Build_at("Antigua_outskirts", "Field_Cannon_1", "", 4.800, 0.7026, 54.066, 1.6935, "");
			Build_at("Antigua_outskirts", "Field_Cannon_1", "", 12.800, -0.072085, 55.76, 1.5522, "");
// FRENCH CANNON
			Build_at("Antigua_outskirts", "Field_Cannon_1", "", 30.54, 0.6625, 171.62, -1.1963, "");
			Build_at("Antigua_outskirts", "Field_Cannon_1", "", 34.566, 0.30839, 169.1, -1.2158, "");
			LAi_QuestDelay("Defending_the_outskirts2", 0.0);
		break;

		case "Defending_the_outskirts2":
			pchar.quest.Take_up_positions.win_condition.l1 = "location";
			Pchar.quest.Take_up_positions.win_condition.l1.character = Pchar.id;
			pchar.quest.Take_up_positions.win_condition.l1.location = "Antigua_outskirts";
			pchar.quest.Take_up_positions.win_condition = "Take_up_positions";
		break;

		case "Take_up_positions":
			Pchar.Quest.French_Valley_Trap.over = "yes";
			LAi_SetActorType(pchar);
			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire7", "", -1, 13.484, -0.88979, 109.63, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 20.0; 
			CreateParticleSystemX("fireball", 13.484, -0.88979, 109.63, 0.67745, 0.0, 0.0,0);

			ChangeCharacterAddressGroup(characterFromID("The Earl of Edrington"), "Antigua_outskirts", "goto", "goto70");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_outskirts", "goto", "goto22");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Antigua_outskirts", "goto", "goto61");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_outskirts", "goto", "goto24");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Antigua_outskirts", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Antigua_outskirts", "goto", "goto23");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto62");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG6B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto63");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG7B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "officers", "reload1_3");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG8B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "officers", "reload1_2");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG9B";

			LAi_QuestDelay("Defensive_positions", 2.0);
		break;

		case "Defensive_positions":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "We_did_what_we_could";
		break;

		case "Defensive_positions2":
			LAi_SetActorType(characterFromID("The Earl of Edrington"));
			characters[GetCharacterIndex("The Earl of Edrington")].Dialog.Filename = "The Earl of Edrington_dialog.c";
			LAi_ActorDialog(characterFromID("The Earl of Edrington"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("The Earl of Edrington")].dialog.CurrentNode = "set_up_the_troops";
		break;

		case "Manned_and_ready":
			LAi_SetActorType(characterFromID("soldierG6B"));
			LAi_SetActorType(characterFromID("soldierG7B"));
			LAi_SetActorType(characterFromID("soldierG8B"));
			LAi_SetActorType(characterFromID("soldierG9B"));
			LAi_SetActorType(characterFromID("Oldroyd"));
			LAi_SetActorType(characterFromID("Styles"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorRunToLocator(characterFromID("The Earl of Edrington"), "goto", "goto8", "",40.0);
			LAi_ActorGoToLocator(characterFromID("Oldroyd"), "goto", "goto67", "",40.0);
			LAi_ActorGoToLocator(characterFromID("Styles"), "goto", "goto37", "",40.0);
			LAi_ActorRunToLocator(characterFromID("Matthews"), "goto", "goto31", "",40.0);
			LAi_ActorRunToLocator(characterFromID("soldierG6B"), "goto", "goto54", "",40.0);
			LAi_ActorRunToLocator(characterFromID("soldierG7B"), "goto", "goto68", "",40.0);
			LAi_ActorRunToLocator(characterFromID("soldierG8B"), "goto", "goto66", "",40.0);
			LAi_ActorRunToLocator(characterFromID("soldierG9B"), "goto", "goto65", "",40.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Tongue"), "goto", "goto53", "",40.0);
			LAi_ActorRunToLocator(characterFromID("Patrick Harper"), "goto", "goto69", "",40.0);
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "goto60", "",40.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Mansfield"), "goto", "goto64", "soldiers_in_position",40.0);

			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(Pchar, "goto", "goto44", "Manned_and_ready3", 40.0);
		break;

		case "Manned_and_ready2":
			LAi_QuestDelay("Manned_and_ready3", 2.0);
		break;

		case "soldiers_in_position":
			LAi_ActorTurnToLocator(characterFromID("soldierG6B"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("soldierG7B"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("soldierG8B"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("soldierG9B"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("Patrick Harper"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("Rifleman Tongue"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("Rifleman Mansfield"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("Oldroyd"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("Styles"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("Matthews"),"officers", "reload1_1");
			LAi_ActorTurnToLocator(characterFromID("The Earl of Edrington"),"officers", "reload1_1");
		break;

		case "Manned_and_ready3":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Doesn't_look_like_much";
		break;

		case "The_French_assualt":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "reload1_1");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "reload1_2");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "reload1_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto22");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto61");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto24");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier6X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto62");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier7X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto63");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier8X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto23");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier9X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto13");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier10X";

			LAi_QuestDelay("The_French_assualt2", 1.0);
		break;

		case "The_French_assualt2":
			PlaySound("OBJECTS\DUEL\French_DrumsA.wav");
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "goto36", "",0.0);
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator((Pchar), "goto", "goto71", "The_French_assualt3", 25.0);
		break;

		case "The_French_assualt3":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",25.0,5.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "They_have_cannon";
		break;

		case "The_French_assualt3XXX":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Rifleman Tongue"));
			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"), characterFromID("soldier5X"));
			LAi_ActorTurnToCharacter(characterFromID("Matthews"), characterFromID("soldier5X"));
			LAi_QuestDelay("The_French_assualt4", 2.0);
		break;

		case "The_French_assualt4":
			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));
			LAi_SetActorType(characterFromID("soldier4X"));
			LAi_SetActorType(characterFromID("soldier5X"));
			LAi_SetActorType(characterFromID("soldier6X"));
			LAi_SetActorType(characterFromID("soldier7X"));
			LAi_SetActorType(characterFromID("soldier8X"));
			LAi_SetActorType(characterFromID("soldier9X"));
			LAi_SetActorType(characterFromID("soldier10X"));
			LAi_ActorRunToLocator(characterFromID("soldier1X"), "goto", "goto49", "The_French_assualt5",20.0);
			LAi_ActorRunToLocator(characterFromID("soldier2X"), "goto", "goto16", "",0.0);
			LAi_ActorRunToLocator(characterFromID("soldier3X"), "goto", "goto48", "",0.0);
			LAi_ActorRunToLocator(characterFromID("soldier4X"), "goto", "goto17", "",0.0);
			LAi_ActorRunToLocator(characterFromID("soldier5X"), "goto", "goto46", "",0.0);
			LAi_ActorRunToLocator(characterFromID("soldier6X"), "goto", "goto45", "",0.0);
			LAi_ActorRunToLocator(characterFromID("soldier7X"), "goto", "goto18", "",0.0);
			LAi_ActorRunToLocator(characterFromID("soldier8X"), "goto", "goto19", "",0.0);
			LAi_ActorRunToLocator(characterFromID("soldier9X"), "goto", "goto44", "",0.0);
			LAi_ActorRunToLocator(characterFromID("soldier10X"), "goto", "goto47", "",0.0);
		break;

		case "The_French_assualt5": // French 1 fires
			CreateParticleSystemX("blast_inv", 33.962, 1.31601, 166.22, 1.6885, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 33.962, 1.31601, 166.22, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 33.962, 1.31601, 166.22, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("The_French_assualt5A", 1.0);
		break;

		case "The_French_assualt5A": // French 2 fires
			CreateParticleSystemX("blast_inv", 29.668, 1.61576, 169.26, 1.7125, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 29.668, 1.61576, 169.26, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 29.668, 1.61576, 169.26, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("The_French_assualt5B", 1.0);
		break;

		case "The_French_assualt5B": // French 1 blast
			CreateParticleSystemX("blast_inv", -2.9419, 1.545, 60.121, 0.57372, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -2.9419, 1.545, 60.121, 0.57372, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -2.9419, 1.545, 60.121, 0.57372, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_SetStunnedTypeNoGroup(characterFromID("The Earl of Edrington"));
			LAi_QuestDelay("The_French_assualt5C", 1.0);
		break;

		case "The_French_assualt5C": // French 2 blast
			CreateParticleSystemX("blast_inv", 16.77, -0.39693, 65.962, -0.094352, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 16.77, -0.39693, 65.962, -0.094352, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 16.77, -0.39693, 65.962, -0.094352, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("Return_French_fire1", 5.0);
		break;

		case "Return_French_fire1": // Gun 3 fires
			CreateParticleSystemX("blast_inv", 13.104, 0.91, 57.777, -1.5555, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 13.104, 0.91, 57.777, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 13.104, 0.91, 57.777, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("Return_French_fire2", 3.0); // 1.0
		break;

		case "Return_French_fire2": // Gun 2 fires
			CreateParticleSystemX("blast_inv", 4.7827, 1.85934, 55.878, -1.5253, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 4.7827, 1.85934, 55.878, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 4.7827, 1.85934, 55.878, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("Return_French_fire3", 1.0);
		break;

		case "Return_French_fire3": // Blast 3 here
			CreateParticleSystemX("blast_inv", 21.314, 1.4649, 152.13, 0.29548, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 21.314, 1.4649, 152.13, 0.29548, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 21.314, 1.4649, 152.13, 0.29548, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("Return_French_fire3Z", 0.5);
		break;

		case "Return_French_fire3Z": // Gun 1 fires
			CreateParticleSystemX("blast_inv", -12.115, 2.8464, 48.167, -1.404, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -12.115, 2.8464, 48.167, -1.404, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -12.115, 2.8464, 48.167, -1.404, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("French_second_volley1", 1.0);
		break;

		case "French_second_volley1": // Blast 2 here
			CreateParticleSystemX("blast_inv", 26.705, 1.0901, 155.58, 0.61948, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 26.705, 1.0901, 155.58, 0.61948, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 26.705, 1.0901, 155.58, 0.61948, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("French_second_volley2", 1.0);
		break;

		case "French_second_volley2": // Blast 1 here - kill French gun
			CreateParticleSystemX("blast_inv", 34.503, 0.31109, 169.04, 2.1042, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 34.503, 0.31109, 169.04, 2.1042, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 34.503, 0.31109, 169.04, 2.1042, 0.0, 0.0,20);

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire1", "", -1, 34.503, 0.31109, 169.04, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 20.0; 
			CreateParticleSystemX("fireball", 34.503, 0.31109, 169.04, 2.1042, 0.0, 0.0,0);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("What_an_awful_mess", 10.0);
		break;

		case "What_an_awful_mess":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "First_volley_over";
		break;

		case "French_second_volley1Z": // French 1 2nd shot
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Rifleman Tongue"));
			LAi_ActorTurnToCharacter(characterFromID("Matthews"), characterFromID("soldier5X"));
			LAi_QuestDelay("French_Blast_two", 3.0);
		break;

		case "French_Blast_two": // French 2 2nd shot
			CreateParticleSystemX("blast_inv", 29.668, 1.61576, 169.26, 1.7125, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 29.668, 1.61576, 169.26, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 29.668, 1.61576, 169.26, 0.0, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
////////////			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("French_Blast_vol2_1", 2.0);
		break;

		case "French_Blast_vol2_1": // French 1 blast kills our gun
			CreateParticleSystemX("blast_inv", 5.2852, 0.69082, 54.312, -1.594, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 5.2852, 0.69082, 54.312, -1.594, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 5.2852, 0.69082, 54.312, -1.594, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Antigua_outskirts", "fire", "fire2", "", -1, 5.1668, 0.6619, 54.985, false);
			Locations[FindLocation("Antigua_outskirts")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Antigua_outskirts")].locators_radius.fire = 20.0; 
			CreateParticleSystemX("fireball", 5.1668, 0.6619, 54.985, -30857, 0.0, 0.0,0);
			LAi_QuestDelay("French_Blast_vol2_2", 1.0);
		break;

		case "French_Blast_vol2_2": // French 2 blast
			LAi_SetStunnedTypeNoGroup(characterFromID("Rifleman Mansfield"));
			Lai_KillCharacter(characterFromID("soldierG8B"));
			Lai_KillCharacter(characterFromID("soldierG9B"));
			LAi_QuestDelay("What_an_awful_mess2X", 5.0);
		break;

		case "What_an_awful_mess2X":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialog(characterFromID("Matthews"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "Their_cannon_are_done";
		break;

		case "The_French_assualt5XXX":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Rifleman Tongue"));
			LAi_ActorTurnToCharacter(characterFromID("Matthews"), characterFromID("soldier5X"));
			LAi_ActorTurnToCharacter(characterFromID("soldier3X"), characterFromID("Rifleman Tongue"));
			LAi_ActorTurnToCharacter(characterFromID("soldier1X"), characterFromID("Rifleman Tongue"));
			LAi_QuestDelay("The_Fire_Fight", 2.0);
		break;

		case "The_Fire_Fight":
			LAi_ActorAnimation(characterFromID("Soldier1X"), "shot", "The_Fire_Fight2", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier1X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier3X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier3X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier8X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier8X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "The_Fire_Fight2":
			PlayStereoSound("OBJECTS\DUEL\bullet_miss1.wav");
			LAi_SetStunnedTypeNoGroup(characterFromID("Rifleman Tongue"));

			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier8X"));
			LAi_SetActorType(characterFromID("soldier3X"));

			LAi_ActorAnimation(characterFromID("Soldier5X"), "shot", "The_Fire_Fight3", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier5X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier9X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier9X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier2X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier2X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier4X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier4X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier6X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier6X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier7X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier7X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier10X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier10X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break

		case "The_Fire_Fight3":
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier4X"));
			LAi_SetActorType(characterFromID("soldier5X"));
			LAi_SetActorType(characterFromID("soldier6X"));
			LAi_SetActorType(characterFromID("soldier7X"));
			LAi_SetActorType(characterFromID("soldier9X"));
			LAi_SetActorType(characterFromID("soldier10X"));

			CreateParticleSystemX("blast_inv", -12.115, 2.8464, 48.167, -1.404, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -12.115, 2.8464, 48.167, -1.404, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -12.115, 2.8464, 48.167, -1.404, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("The_Fire_Fight6", 1.0);
		break;

		case "The_Fire_Fight6": // gun 3 
			CreateParticleSystemX("blast_inv", 13.198, 0.91, 58.747, -1.5555, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 13.198, 0.91, 58.747, -1.5555, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 13.198, 0.91, 58.747, -1.5555, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("The_Fire_Fight7", 1.0);
		break;

		case "The_Fire_Fight7": // blast 1
			LAi_ActorTurnToCharacter((Pchar), characterFromID("soldier5X"));
			CreateParticleSystemX("blast_inv", 13.484, -0.88979, 109.63, 0.67745, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 13.484, -0.88979, 109.63, 0.67745, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 13.484, -0.88979, 109.63, 0.67745, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");

			Lai_KillCharacter(characterFromID("soldier7X"));
			Lai_KillCharacter(characterFromID("soldier8X"));
			LAi_QuestDelay("The_Fire_Fight9", 1.0);
		break;

		case "The_Fire_Fight9": // blast 2
			CreateParticleSystemX("blast_inv", 9.9351, -0.9602, 105.36, 0.65145, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 9.9351, -0.9602, 105.36, 0.65145, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 9.9351, -0.9602, 105.36, 0.65145, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("The_Fire_Fight10", 1.0);
		break;

		case "The_Fire_Fight10":
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			LAi_group_MoveCharacter(characterFromID("Richard Sharpe"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Patrick Harper"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Matthews"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Oldroyd"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Styles"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("SoldierG6B"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("SoldierG7B"), LAI_GROUP_PLAYER);

			LAi_group_MoveCharacter(characterFromID("Soldier1X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier1X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier3X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier3X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier4X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier4X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier5X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier5X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier6X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier6X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier9X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier9X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier10X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier10X"), "FRANCE_SOLDIERS");
			LAi_QuestDelay("The_final_attack", 2.0);
		break;

		case "The_final_attack":
			LAi_SetImmortal(characterFromID("Richard Sharpe"), true);
			LAi_SetImmortal(characterFromID("Patrick Harper"), true);
			LAi_SetImmortal(characterFromID("Matthews"), true);
			LAi_SetImmortal(characterFromID("Oldroyd"), true);
			LAi_SetImmortal(characterFromID("Styles"), true);
			LAi_SetActorType(characterFromID("Soldier6X"));
			LAi_ActorAttack(characterFromID("Soldier6X"),(Pchar), "");

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "The_threat_is_over");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "The_threat_is_over":
			ChangeCharacterAddress(characterFromID("The Earl of Edrington"), "None", "");
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Matthews"));

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "The_battle_is_won";
		break;

		case "Report_to_the Colonel":
			AddQuestRecord("Attack on Antigua", 4);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Matthews"));

			Pchar.quest.Meet_with_Wellesley.win_condition.l1 = "location";
			PChar.quest.Meet_with_Wellesley.win_condition.l1.character = Pchar.id;
			Pchar.quest.Meet_with_Wellesley.win_condition.l1.location = "Antigua_port";
			Pchar.quest.Meet_with_Wellesley.win_condition = "Meet_with_Wellesley";
		break;

		case "Meet_with_Wellesley":
			DisableFastTravel(false);
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Antigua_port", "officers", "reload_2_city_3");
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Antigua_port", "goto", "goto17");
			LAi_SetOfficerType(characterFromID("Arthur Wellesley"));

			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialog(characterFromID("Arthur Wellesley"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "A_damn_fine_job";
		break;

		case "Midshipman_Sharpe":
		//	LAi_ActorGoToLocation(characterFromID("Arthur Wellesley"), "reload", "reload3_back", "none", "", "", "",0.0);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "The_parting_of_the_ways";
		break;

		case "Off_to_Greenford_with_Documents":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			AddQuestRecord("Attack on Antigua", 5);
			LAi_ActorGoToLocation(characterFromID("Richard Sharpe"), "reload", "reload_2_city", "none", "", "", "",0.0);
			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemovePassenger(pchar, characterFromID("Richard Sharpe"));

			Pchar.quest.Coming_to_the_end.win_condition.l1 = "location";
			PChar.quest.Coming_to_the_end.win_condition.l1.character = Pchar.id;
			Pchar.quest.Coming_to_the_end.win_condition.l1.location = "Greenford Naval HQ";
			Pchar.quest.Coming_to_the_end.win_condition = "Coming_to_the_end";
			Locations[FindLocation("Antigua_outskirts")].vcskip = false;
			Locations[FindLocation("Antigua_Jungle_01")].vcskip = false;
			Locations[FindLocation("Antigua_Jungle_02")].vcskip = false;
		break;

		case "Coming_to_the_end":
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "Greenford Naval HQ", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Lt. Eccleston"), "Greenford Naval HQ", "sit", "sit1");
			LAi_QuestDelay("Deliver_the_documents", 2.0);
		break;

		case "Deliver_the_documents":
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"Tartane50","Happy Times", -1,ENGLAND,true,true);
			SetCrewQuantity(pchar, 3);
			AddCharacterGoods(pchar, GOOD_RUM, 2);
			AddCharacterGoods(pchar, GOOD_WHEAT, 4);
			setCharacterShipLocation(Pchar, "Greenford_port");
			SetNationRelationBoth(ENGLAND, FRANCE, RELATION_NEUTRAL); // PB: Make this happen for real
// Grey Roger: when France makes peace, so do its allies
// But Portugal remains at war with France so Teresa Moreno has something to fight for
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_NEUTRAL);
			SetNationRelationBoth(ENGLAND, HOLLAND, RELATION_NEUTRAL);
//			SetNationRelationBoth(PORTUGAL, FRANCE, RELATION_NEUTRAL);
			SetNationRelationBoth(PORTUGAL, SPAIN, RELATION_NEUTRAL);
			SetNationRelationBoth(PORTUGAL, HOLLAND, RELATION_NEUTRAL);
			SetNationRelationBoth(AMERICA, FRANCE, RELATION_NEUTRAL);
			SetRMRelation(PChar, FRANCE, REL_AFTERATTACK);
			SetRMRelation(PChar, SPAIN, REL_AFTERATTACK);
			SetRMRelation(PChar, HOLLAND, REL_AFTERATTACK);

			characters[GetCharacterIndex("Lt. Eccleston")].Dialog.Filename = "Lt. Eccleston_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Eccleston"));
			Characters[GetCharacterIndex("Lt. Eccleston")].dialog.CurrentNode = "Deliver_documents_Eccleston";
			LAi_ActorDialog(characterFromID("Lt. Eccleston"), pchar, "Decommissioned", 10.0, 10.0);
		break;

		case "Decommissioned":
			LAi_QuestDelay("Decommissioned2", 5.0);
		break;

		case "Decommissioned2":
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "You're_decommissioned";
		break;

		case "Find_lodgings":
			PChar.isnotcaptain = true;
			SetCharacterRemovable(characterFromID("Lt. William Bush"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. William Bush"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. William Bush"));
			RemovePassenger(pchar, characterFromID("Lt. William Bush"));
			SetCharacterRemovable(characterFromID("Lt. Uriah Quelp"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. Uriah Quelp"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Uriah Quelp"));
			RemovePassenger(pchar, characterFromID("Lt. Uriah Quelp"));
			pchar.money = 100;
			Pchar.quest.Coming_to_the_end.win_condition.l1 = "location";
			PChar.quest.Coming_to_the_end.win_condition.l1.character = Pchar.id;
			Pchar.quest.Coming_to_the_end.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Coming_to_the_end.win_condition = "Meet_Mrs._Mason";
		break;

		case "Meet_Mrs._Mason":
			Locations[FindLocation("Greenford_town")].reload.l20.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l19.disable = 1;
			pchar.quest.Players_Rank = "Lieutenant";
			SetRank(pchar, ENGLAND, 4);
			GiveModel2Player("brtH3rdLt_18", true);
			Locations[FindLocation("Mrs. Mason's House")].vcskip = true;
			ChangeCharacterAddressGroup(characterFromID("Mrs. Mason"), "Greenford_town", "officers", "reload11_1"); //"goto", "goto16");

			LAi_SetActorType(characterFromID("Mrs. Mason"));
			characters[GetCharacterIndex("Mrs. Mason")].Dialog.Filename = "Mrs. Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Mrs. Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "a_place_to_stay";
		break;

		case "Meet_Maria":
			AddQuestRecord("Attack on Antigua", 6);
			LAi_ActorGoToLocation(characterFromID("Mrs. Mason"), "reload", "reload21", "none", "", "", "",0.0);

			Pchar.quest.Meet_Maria_at_last.win_condition.l1 = "location";
			PChar.quest.Meet_Maria_at_last.win_condition.l1.character = Pchar.id;
			Pchar.quest.Meet_Maria_at_last.win_condition.l1.location = "Mrs. Mason's House";
			Pchar.quest.Meet_Maria_at_last.win_condition = "Meet_Maria_at_last";
		break;

		case "Meet_Maria_at_last":
			ChangeCharacterAddressGroup(characterFromID("Mrs. Mason"), "Mrs. Mason's House", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Maria Mason"), "Mrs. Mason's House", "goto", "goto1");

			LAi_SetActorType(characterFromID("Mrs. Mason"));
			characters[GetCharacterIndex("Mrs. Mason")].Dialog.Filename = "Mrs. Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Mrs. Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "Maria_introduced";
		break;

		case "Maria_speaks":
			LAi_ActorGoToLocation(characterFromID("Mrs. Mason"), "reload", "reload2", "none", "", "", "",0.0);

			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Maria Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "My_name_is_Maria";
		break;

		case "Two_months_later":
			WaitDate("", 0, 2, 0, 0, 0);
			LAi_Fade("", "");
			LAi_SetActorType(pchar);
			DoQuestReloadToLocation("Greenford_port", "reload", "reload4", "Looking_for_a_ship");
			SetRank(CharacterFromID("Sir Edward Pellew"), ENGLAND, 8); // GR: Pellew becomes Admiral
			Characters[GetCharacterIndex("Sir Edward Pellew")].model = "PellewA_18";
			Characters[GetCharacterIndex("Sir Edward Pellew")].headmodel = "h_PellewA_18";
		break;

		case "Looking_for_a_ship":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			LAi_ActorGoToLocator((Pchar), "goto", "goto3", "Looking_for_a_ship2", 5.0);
		break;

		case "Looking_for_a_ship2":
			ChangeCharacterAddressGroup(characterFromID("Maria Mason"), "Greenford_port", "reload", "reload4");
			LAi_QuestDelay("Looking_for_a_ship3", 1.0);
		break;

		case "Looking_for_a_ship3":
			LAi_SetPlayerType(pchar);

			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Maria Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "A_penny_for_your_thoughts";
		break;

		case "Riflemen_in_the_Tavern":
			AddQuestRecord("Attack on Antigua", 7);
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Greenford_tavern", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Greenford_tavern", "goto", "goto6");
			GiveItem2Character(characterFromID("Richard Sharpe"), "blade24+3");
			EquipCharacterByItem(characterFromID("Richard Sharpe"), "blade24");
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_type_actor_Reset(characterFromID("Rifleman Tongue"));

			Pchar.quest.Riflemen_in_the_Tavern2.win_condition.l1 = "location";
			PChar.quest.Riflemen_in_the_Tavern2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Riflemen_in_the_Tavern2.win_condition.l1.location = "Greenford_tavern";
			Pchar.quest.Riflemen_in_the_Tavern2.win_condition = "Riflemen_in_the_Tavern2";
		break;

		case "Riflemen_in_the_Tavern2":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "With_Sharpe_to_Oxbay";
		break;

		case "Sharpe_Harper_to_Oxbay":
			AddQuestRecord("Attack on Antigua", 8);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Richard Sharpe"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Patrick Harper"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			SetCharacterRemovable(characterFromID("Patrick Harper"), false);
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Greenford_town", "goto", "goto9");

			Pchar.quest.Riflemen_Tongue_Greenford.win_condition.l1 = "location";
			PChar.quest.Riflemen_Tongue_Greenford.win_condition.l1.character = Pchar.id;
			Pchar.quest.Riflemen_Tongue_Greenford.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Riflemen_Tongue_Greenford.win_condition = "Riflemen_Tongue_Greenford";
		break;

		case "Riflemen_Tongue_Greenford":
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			characters[GetCharacterIndex("Rifleman Tongue")].Dialog.Filename = "Rifleman Tongue_dialog.c";
			LAi_ActorDialog(characterFromID("Rifleman Tongue"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Rifleman Tongue")].dialog.CurrentNode = "With_Sharpe_to_Lighthouse";
		break;

		case "A_choice_of_ways":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Which_way_to_Lighthouse";
		break;

		case "Sharpe_Oxbay_lighthouse":
			DisableFastTravel(false);
			ChangeCharacterAddressGroup(characterFromID("Mrs. Mason"), "Mrs. Mason's House", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Maria Mason"), "Mrs. Mason's House", "goto", "goto1");
			LAi_SetActorType(characterFromID("Mrs. Mason"));
			LAi_SetActorType(characterFromID("Maria Mason"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Rifleman Tongue"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			Pchar.quest.Quelp_at_lighthouse.win_condition.l1 = "location";
			PChar.quest.Quelp_at_lighthouse.win_condition.l1.character = Pchar.id;
			Pchar.quest.Quelp_at_lighthouse.win_condition.l1.location = "Oxbay_Lighthouse";
			Pchar.quest.Quelp_at_lighthouse.win_condition = "Quelp_at_lighthouse";
		break;

		case "Quelp_at_lighthouse":
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Oxbay_Lighthouse", "goto", "goto3"); //"goto2");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "reload2_1");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "reload2_2");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "reload2_3");
			sld.id = "soldier3X";
			LAi_QuestDelay("Quelp_at_lighthouse2", 1.0);
		break;

		case "Quelp_at_lighthouse2":
			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));
			Lai_KillCharacter(characterFromID("soldier1X"));
			Lai_KillCharacter(characterFromID("soldier2X"));
			Lai_KillCharacter(characterFromID("soldier3X"));

			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "The_Final_Explanation";
		break;

		case "Attack_the_Midshipman":
			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));

			Locations[FindLocation("Oxbay_Lighthouse")].locators_radius.goto.goto25 = 5.0;
			Pchar.quest.Attack_the_Midshipman2.win_condition.l1 = "locator";
			Pchar.quest.Attack_the_Midshipman2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Attack_the_Midshipman2.win_condition.l1.location = "Oxbay_Lighthouse";
			Pchar.quest.Attack_the_Midshipman2.win_condition.l1.locator_group = "goto";
			Pchar.quest.Attack_the_Midshipman2.win_condition.l1.locator = "goto25";
			Pchar.quest.Attack_the_Midshipman2.win_condition = "Attack_the_Midshipman2";
		break;

		case "Attack_the_Midshipman2":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Lighthouse_dead";
		break;

		case "The_French_Dead_Lighthouse":
			SetCharacterRemovable(characterFromID("Patrick Harper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Patrick Harper"));
			RemoveCharacterCompanion(Pchar, characterFromID("Patrick Harper"));
			SetCharacterRemovable(characterFromID("Rifleman Tongue"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rifleman Tongue"));
			RemoveCharacterCompanion(Pchar, characterFromID("Rifleman Tongue"));

			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "It_was_Hunter";
		break;

		case "The_French_Dead_Lighthouse2":
			LAi_ActorGoToLocation(characterFromID("Lt. Uriah Quelp"), "reload", "reload1_back", "none", "", "", "",5.0);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Unsolved_problem";
		break;

		case "Back_to_Maria_at_Greenford": // link for program extension in BETA
			AddQuestRecord("Attack on Antigua", 9);
			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemoveCharacterCompanion(Pchar, characterFromID("Richard Sharpe"));
			RemovePassenger(pchar, characterFromID("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("Rifleman Tongue"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rifleman Tongue"));
			RemoveCharacterCompanion(Pchar, characterFromID("Rifleman Tongue"));
			RemovePassenger(pchar, characterFromID("Rifleman Tongue"));
			SetCharacterRemovable(characterFromID("Patrick Harper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Patrick Harper"));
			RemoveCharacterCompanion(Pchar, characterFromID("Patrick Harper"));
			RemovePassenger(pchar, characterFromID("Patrick Harper"));
			SetCharacterRemovable(characterFromID("Lt. Uriah Quelp"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. Uriah Quelp"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Uriah Quelp"));
			RemovePassenger(pchar, characterFromID("Lt. Uriah Quelp"));
			LAi_QuestDelay("Back_to_Maria2", 0.0);
		break;

		case "Back_to_Maria2":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));

			LAi_ActorGoToLocation(characterFromID("Richard Sharpe"), "reload", "reload1_back", "none", "", "", "",5.0);
			LAi_ActorGoToLocation(characterFromID("Rifleman Tongue"), "reload", "reload1_back", "none", "", "", "",5.0);
			LAi_ActorGoToLocation(characterFromID("Patrick Harper"), "reload", "reload1_back", "none", "", "", "",5.0);

// The Game continues from here - added after Beta release
			Pchar.quest.An_unexpected_visitor.win_condition.l1 = "location";
			PChar.quest.An_unexpected_visitor.win_condition.l1.character = Pchar.id;
			Pchar.quest.An_unexpected_visitor.win_condition.l1.location = "Greenford_town";
			Pchar.quest.An_unexpected_visitor.win_condition = "An_unexpected_meeting";
		break;
// CHOICE 4
		case "Confront_Quelp_on_beach":
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			pchar.quest.Both_Confront_Quelp.win_condition.l1 = "location";
			Pchar.quest.Both_Confront_Quelp.win_condition.l1.character = Pchar.id;
			pchar.quest.Both_Confront_Quelp.win_condition.l1.location = "Antigua_shore";
			pchar.quest.Both_Confront_Quelp.win_condition = "Both_Confront_Quelp";
		break;

		case "Both_Confront_Quelp":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "Exposed_and_death";
		break;

		case "Sharpe_is_killed":
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_shore", "reload", "reload2_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Antigua_shore", "reload", "reload2_back");
			ChangeCharacterAddressGroup(characterFromID("The Earl of Edrington"), "Antigua_shore", "reload", "reload2_back");
			LAi_ActorTurnToCharacter(characterFromID("Lt. Uriah Quelp"),characterFromID("Richard Sharpe"));
			LAi_QuestDelay("Sharpe_is_killed2", 0.0);
		break;

		case "Sharpe_is_killed2":
			LAi_ActorAnimation(characterFromID("Lt. Uriah Quelp"), "shot", "Sharpe_is_killed3", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Lt. Uriah Quelp"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Sharpe_is_killed3":
			Lai_KillCharacter(characterFromID("Richard Sharpe"));

			LAi_SetActorType(PChar);
			EquipCharacterByItem(Pchar, "pistol1");
			LAi_ActorAnimation(Pchar, "shot", "Sharpe_is_killed4", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(Pchar, &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
		break;

		case "Sharpe_is_killed4":
			Lai_KillCharacter(characterFromID("Lt. Uriah Quelp"));

			LAi_QuestDelay("Arrested_for_Treason", 3.0);
		break;

		case "Arrested_for_Treason":
			LAi_SetPlayerType(PChar);
			LAi_SetOfficerType(characterFromID("The Earl of Edrington"));
			LAi_SetOfficerType(characterFromID("Rifleman Harris"));
			LAi_SetOfficerType(characterFromID("Rifleman Haggman"));

			LAi_QuestDelay("Arrested_for_Treason2", 3.0);
		break;

		case "Arrested_for_Treason2":
			LAi_SetActorType(characterFromID("The Earl of Edrington"));
			characters[GetCharacterIndex("The Earl of Edrington")].Dialog.Filename = "The Earl of Edrington_dialog.c";
			LAi_ActorDialog(characterFromID("The Earl of Edrington"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("The Earl of Edrington")].dialog.CurrentNode = "You_are_under_arrest";
		break;

		case "A_Trial_for_treason":
			LAi_Fade("", "");
			DoQuestReloadToLocation("Antigua_academy", "goto", "goto1", "Death_in_the_morning");
		break;

		case "Death_in_the_morning":
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Antigua_Academy", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_Academy", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Antigua_academy", "sit", "sit1");
			ChangeCharacterAddressGroup(characterFromID("Captain Keene"), "Antigua_academy", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("William Chumley"), "Antigua_Academy", "goto", "goto5");

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "You_are_to_be_shot";
		break;
// END CHOICE 4

// LOYALTY
		case "An_unexpected_meeting":
			CloseQuestHeader("Attack on Antigua");

			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemoveCharacterCompanion(Pchar, characterFromID("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("Patrick Harper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Patrick Harper"));
			RemoveCharacterCompanion(Pchar, characterFromID("Patrick Harper"));

			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Greenford_town", "goto", "goto5");
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));

			LAi_QuestDelay("An_unexpected_meeting2", 3.0);
		break;

		case "An_unexpected_meeting2":
			ChangeCharacterAddress(characterFromID("Richard Sharpe"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");

			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Meet_at_Greenford";
		break;

		case "Bush_to_Mrs_Mason's":
			SetQuestHeader("Old friends - New Enemies");
			AddQuestRecord("Old Friends - New Enemies", 1);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. William Bush"));
			SetCharacterRemovable(characterFromID("Lt. William Bush"), false);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "First time";

			Pchar.quest.Bush_moves_in.win_condition.l1 = "location";
			PChar.quest.Bush_moves_in.win_condition.l1.character = Pchar.id;
			Pchar.quest.Bush_moves_in.win_condition.l1.location = "Mrs. Mason's House";
			Pchar.quest.Bush_moves_in.win_condition = "Bush_moves_in";
		break;

		case "Bush_moves_in":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto5", "Bush_moves_in2", 10);
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Mrs. Mason's House", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Mrs. Mason"), "Mrs. Mason's House", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Maria Mason"), "Mrs. Mason's House", "goto", "goto4");
		break;

		case "Bush_moves_in2":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Mrs. Mason"));
			characters[GetCharacterIndex("Mrs. Mason")].Dialog.Filename = "Mrs. Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Mrs. Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "Bush_will_stay";
		break;

		case "Bush_Pays_up":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Pay_in_advance";
		break;

		case "Mrs_Mason_reckons_up":
			LAi_SetActorType(characterFromID("Mrs. Mason"));
			characters[GetCharacterIndex("Mrs. Mason")].Dialog.Filename = "Mrs. Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Mrs. Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "owes_fifteen";
		break;

		case "Maria_chimes_in":
			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Maria Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "Maria's_Halfcrown";
		break;

		case "Mother_is_annoyed":
			LAi_SetActorType(characterFromID("Mrs. Mason"));
			characters[GetCharacterIndex("Mrs. Mason")].Dialog.Filename = "Mrs. Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Mrs. Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "Time_daydreaming";
		break;

		case "Bush_to_bed":
			LAi_ActorGoToLocator(characterFromID("Mrs. Mason"), "reload", "reload2", "",0.0);
			LAi_QuestDelay("Bush_to_bed2", 3.0);
		break;

		case "Bush_to_bed2":
			LAi_ActorGoToLocator(characterFromID("Lt. William Bush"), "reload", "reload2", "",0.0);
			LAi_QuestDelay("Bush_to_bed3", 2.0);
		break;

		case "Bush_to_bed3":
			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Maria Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "Maria_sympthay";
		break;

		case "Fade_to_Town":
			SetCurrentTime(22.00, 0);
			Locations[FindLocation("Greenford_town")].reload.l20.disable = 1;
			ChangeCharacterAddress(characterFromID("Mrs. Mason"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. William Bush"), "None", "");
			LAi_QuestDelay("Fade_to_Town2", 1.0);
		break;

		case "Fade_to_Town2":
			Pchar.quest.Go_to_play_cards.win_condition.l1 = "location";
			PChar.quest.Go_to_play_cards.win_condition.l1.character = Pchar.id;
			Pchar.quest.Go_to_play_cards.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Go_to_play_cards.win_condition = "Go_to_play_cards";
		break;

		case "Go_to_play_cards":
			Characters[GetCharacterIndex("Sir Edward Pellew")].model = "PellewA_18";
			Characters[GetCharacterIndex("Sir Edward Pellew")].headmodel = "h_PellewA_18";

			ChangeCharacterAddress(characterFromID("Maria Mason"), "None", "");

			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Maria_likes_you";
			Locations[FindLocation("Greenford_town")].reload.l18.close_for_night = 0;
		break;

		case "Out_for_the_night":
			AddQuestRecord("Old Friends - New Enemies", 2);
			Locations[FindLocation("Greenford_town")].reload.l20.disable = 0;
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "First time";

			Pchar.quest.Card_night_out.win_condition.l1 = "location";
			PChar.quest.Card_night_out.win_condition.l1.character = Pchar.id;
			Pchar.quest.Card_night_out.win_condition.l1.location = "apothecary";
			Pchar.quest.Card_night_out.win_condition = "Card_night_out";
		break;

		case "Card_night_out":
			LAi_SetActorType(pchar);
			ChangeCharacterAddress(characterFromID("Apothecary"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "apothecary", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "apothecary", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "apothecary", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Jack Hammond"), "apothecary", "goto", "goto5");

			LAi_ActorTurnToCharacter(characterFromID("Black Charlie Hammond"), characterFromID("Jack Hammond"));

			LAi_SetOfficerType(characterFromID("Sir Edward Pellew"));
			LAi_QuestDelay("Card_night_out2", 0.0);
		break;

		case "Card_night_out2":
			LAi_ActorGoToLocator((Pchar), "goto", "goto8", "Card_night_out3", 10);
		break;

		case "Card_night_out3":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Card_Night";
		break;

		case "Hammond_and_Nephew":
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Hammond_and_Nephew";
		break;
		
		case "Which_Captain_would_you_join":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "With_whom_would_you_serve";
		break;

		case "I_choose_Hornblower":
			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialog(characterFromID("Jack Hammond"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "Hornblower_for_me";
		break;

		case "Pellews_Deal":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Lets_play_cards";
		break;

		case "After_the_game":
			LAi_Fade("After_the_game2", "After_the_game3");
		break;

		case "After_the_game2":
			ChangeCharacterAddress(characterFromID("Jack Hammond"), "None", "");
			ChangeCharacterAddress(characterFromID("Black Charlie Hammond"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "apothecary", "goto", "goto2");
			ChangeCharacterAddressGroup((Pchar), "apothecary", "goto", "goto5");
		break;

		case "After_the_game3":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Card_Payout";
		break;

		case "On_board_the_Flagship":
			LAi_ActorGoToLocation(characterFromID("Sir Edward Pellew"), "reload", "reload1", "none", "", "", "",0.0);
			LAi_QuestDelay("Pellew_goes_off", 2.0);
		break;

		case "Pellew_goes_off":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "What_does_he_want";
		break;

		case "On_board_the_Flagship2":
			SetCurrentTime(09.00, 0);
			LAi_Fade("", "");
			LAi_SetActorType(pchar);
			DoQuestReloadToLocation("Cabin2SJG", "reload", "reload1", "Orders_and_Ship");
			ChangeCharacterAddressGroup(characterFromID("Apothecary"), "apothecary", "sit", "sit1");
			Locations[FindLocation("Greenford_town")].reload.l18.close_for_night = 1;
		break;

		case "Orders_and_Ship":
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "First time";
			ChangeCharacterAddress(characterFromID("Lt. William Bush"), "None", "");
			Characters[GetCharacterIndex("Arthur Wellesley")].model = "WellesleyG_18";
			Characters[GetCharacterIndex("Arthur Wellesley")].headmodel = "h_WellesleyG_18";
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Cabin2SJG", "rld", "aloc2");
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Hows_your_head";
			LAi_ActorGoToLocator((Pchar), "rld", "aloc6", "Orders_and_Ship2", 10);
		break;

		case "Orders_and_Ship2":
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(characterFromID("Arthur Wellesley"), "Cabin2SJG", "reload", "reload1");
			SetCharacterRemovable(characterFromID("Lt. William Bush"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. William Bush"));
			RemovePassenger(pchar, characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Ship_introduction";

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialogNow(characterFromID("Sir Edward Pellew"),PChar,"",1.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Hows_your_head";
		break;

		case "Wellesley_and_Pellew_on_ship":
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Hows_your_headXXX";

			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialogNow(characterFromID("Arthur Wellesley"),PChar,"",1.0);
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Ship_introduction";
		break;

		case "Got_to_find_Sharpe":
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Where_to_find_Sharpe";

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialogNow(characterFromID("Sir Edward Pellew"),PChar,"",1.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Hows_your_headXXX";
		break;

		case "Wellesley_in_detail":
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Hows_your_head8";

			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			characters[GetCharacterIndex("Arthur Wellesley")].Dialog.Filename = "Arthur Wellesley_dialog.c";
			LAi_ActorDialogNow(characterFromID("Arthur Wellesley"),PChar,"",1.0);
			Characters[GetCharacterIndex("Arthur Wellesley")].dialog.CurrentNode = "Where_to_find_Sharpe";
		break;

		case "Wind_up_scene":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialogNow(characterFromID("Sir Edward Pellew"),PChar,"",1.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Hows_your_head8";
		break;

		case "Orders_and_Ship3":
			LAi_Fade("Set_up_the_quest1", "Set_up_the_quest2");
		break;

		case "Set_up_the_quest1":
			ChangeCharacterAddress(characterFromID("Sir Edward Pellew"), "None", "");
			ChangeCharacterAddress(characterFromID("Arthur Wellesley"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Greenford_port", "goto", "goto21");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Greenford_port", "goto", "goto3");
			Locations[FindLocation("Greenford_port")].vcskip = true;
			Locations[FindLocation("Greenford_tavern")].vcskip = true;

			pchar.quest.Players_Rank = "Commander";
			SetRank(pchar, ENGLAND, 5);
			DeleteAttribute(PChar, "isnotcaptain");								// GR: Return to normal play
			pchar.quest.story_path = "neutral";
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"RN_Volage","Hotspur",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Greenford_port");
			GiveModel2Player("brtHComdr_18", true);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			DoQuestReloadToLocation("Greenford_port", "reload", "reload1", "_");
		break;

		case "Set_up_the_quest2":
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Greenford_port", "goto", "goto3");
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. William Bush"));
			SetCharacterRemovable(characterFromID("Lt. William Bush"), false);

			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "Quelp_on_the_dock";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"), pchar, "", 10.0, 10.0);
		break;

		case "Bush_First_Lieutenant":
			LAi_ActorGoToLocation(characterFromID("Lt. Uriah Quelp"), "reload", "reload4", "none", "", "", "",10.0);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "First time";
//			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "What_did_he_want";
			LAi_QuestDelay("Bush_Joins_the_Hotspur", 2.0);
		break;

		case "Bush_being_nosey":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "What_did_he_want";
		break;

		case "Bush_Joins_the_Hotspur":
			AddQuestRecord("Old Friends - New Enemies", 3);
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Greenford_tavern", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Greenford_tavern", "goto", "goto7");
			LAi_SetOfficerType(characterFromID("Matthews"));
			LAi_SetOfficerType(characterFromID("Styles"));

			pchar.quest.Matthews_and_crew.win_condition.l1 = "location";
			PChar.quest.Matthews_and_crew.win_condition.l1.character = Pchar.id;
			pchar.quest.Matthews_and_crew.win_condition.l1.location = "Greenford_tavern";
			pchar.quest.Matthews_and_crew.win_condition = "Matthews_and_crew";
		break;

		case "Matthews_and_crew":
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Greenford_tavern", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Greenford_tavern", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Greenford_tavern", "reload", "reload3");

			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_SetActorType(characterFromID("Matthews"));
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "Hired_for_Hotspur";
			LAi_ActorDialog(characterFromID("Matthews"), pchar, "", 10.0, 10.0);
		break;

		case "Styles_needs_a_job":
			LAi_ActorGoToLocation(characterFromID("Matthews"), "reload", "reload1", "none", "", "", "",0.0);
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Styles_needs_a_job";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), pchar, "", 10.0, 10.0);
		break;

		case "And_now_Wolf":
			LAi_ActorGoToLocation(characterFromID("Styles"), "reload", "reload1", "none", "", "", "",0.0);

			characters[GetCharacterIndex("Thomas Wolfe")].Dialog.Filename = "Thomas Wolfe_dialog.c";
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			Characters[GetCharacterIndex("Thomas Wolfe")].dialog.CurrentNode = "Hired_at_Greenford";
			LAi_ActorDialog(characterFromID("Thomas Wolfe"), pchar, "", 10.0, 10.0);
		break;

		case "Wolfe's_Experience":
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Experience";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), pchar, "", 10.0, 10.0);
		break;

		case "And_now_Wolf2":
			characters[GetCharacterIndex("Thomas Wolfe")].Dialog.Filename = "Thomas Wolfe_dialog.c";
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			Characters[GetCharacterIndex("Thomas Wolfe")].dialog.CurrentNode = "Sailed_the_Convoys";
			LAi_ActorDialog(characterFromID("Thomas Wolfe"), pchar, "", 10.0, 10.0);
		break;

		case "Wolfe's_Excuse":
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Why_here";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), pchar, "", 10.0, 10.0);
		break;

		case "And_now_Wolf3":
			characters[GetCharacterIndex("Thomas Wolfe")].Dialog.Filename = "Thomas Wolfe_dialog.c";
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			Characters[GetCharacterIndex("Thomas Wolfe")].dialog.CurrentNode = "Pregnant_girl";
			LAi_ActorDialog(characterFromID("Thomas Wolfe"), pchar, "", 10.0, 10.0);
		break;

		case "Sign_here_Wolfe":
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Sign_here_coxswain";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), pchar, "", 10.0, 10.0);
		break;

		case "Goodbye_to_Maria":
			LAi_ActorGoToLocation(characterFromID("Thomas Wolfe"), "reload", "reload1", "none", "", "", "",0.0);

			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Mrs Mason's_to Pack";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), pchar, "", 10.0, 10.0);
		break;

		case "Goodbye_to_Maria2":
			LAi_Fade("Maria_in_tears", "Maria_in_tears2");
		break;

		case "Maria_in_tears":
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Mrs. Mason's House", "reload", "reload2");
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Going_to_sleep_onboard";
			
			Locations[FindLocation("Mrs. Mason's House")].vcskip = true;
			DoQuestReloadToLocation("Mrs. Mason's House", "goto", "goto5", "Maria_in_tears3");
		break;

		case "Maria_in_tears2":
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Mrs. Mason's House", "reload", "reload2");
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
		break;

		case "Maria_in_tears3":
			ChangeCharacterAddressGroup(characterFromID("Maria Mason"), "Mrs. Mason's House", "reload", "reload2");

			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Going_to_sleep_onboard";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), pchar, "", 10.0, 10.0);
		break;

		case "Maria_I_have_a_ship":
			LAi_ActorGoToLocation(characterFromID("Lt. William Bush"), "reload", "reload1", "none", "", "", "",0.0);

			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Maria Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "Youre_leaving_us";
		break;

		case "Port_and_Departure":
			LAi_ActorGoToLocation(characterFromID("Maria Mason"), "reload", "reload2", "none", "", "", "",0.0);
			LAi_QuestDelay("a_new_dawn_a_new_ship", 3.0);
		break;

		case "a_new_dawn_a_new_ship":
			AddQuestRecord("Old Friends - New Enemies", 4);
			SetCurrentTime(09.00, 0);
			LAi_Fade("", "");
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Lt. Uriah Quelp"));
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Lt. Uriah Quelp"));
			setCharacterShipLocation(characterFromID("Lt. Uriah Quelp"), "Greenford_Port");
			SetCharacterRemovable(characterFromID("Lt. Uriah Quelp"), false);

			DoQuestReloadToLocation("Greenford_port", "goto", "goto20", "Ready_for_Cayman");
		break;

		case "Ready_for_Cayman":
			AddCharacterGoods(pchar, GOOD_RUM, 44);
			AddCharacterGoods(pchar, GOOD_WHEAT, 86);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "First time";
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");

			Pchar.quest.Reached_Cayman_with_Quelp.win_condition.l1 = "location";
			PChar.quest.Reached_Cayman_with_Quelp.win_condition.l1.character = Pchar.id;
			Pchar.quest.Reached_Cayman_with_Quelp.win_condition.l1.location = "Cayman_Port";
			Pchar.quest.Reached_Cayman_with_Quelp.win_condition = "Reached_Cayman_with_Quelp";
		break;

		case "Reached_Cayman_with_Quelp":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			LAi_SetActorType(pchar);
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Cayman_Port", "officers", "sea2");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Cayman_Port", "goto", "goto8");
			LAi_QuestDelay("Reached_Cayman_with_Quelp2", 0.0);
		break;

		case "Reached_Cayman_with_Quelp2":
			LAi_ActorGoToLocator((Pchar), "officers", "sea2", "Reached_Cayman_with_Quelp3", 10);
		break;
			
		case "Reached_Cayman_with_Quelp3":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "Quelp_will_leave_now";

			LAi_SetOfficerType(characterFromID("Lt. Uriah Quelp"));
			LAi_QuestDelay("Reached_Cayman_with_Quelp4", 0.0);
		break;
		
		case "Reached_Cayman_with_Quelp4":
			characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.Filename = "Lt. Uriah Quelp_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].dialog.CurrentNode = "Quelp_will_leave_now";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"), pchar, "", 10.0, 10.0);
		break;

		case "Bush_gets_suspicious":
			LAi_ActorGoToLocation(characterFromID("Lt. Uriah Quelp"), "reload", "sea", "none", "", "", "",0.0);
			SetCharacterRemovable(characterFromID("Lt. Uriah Quelp"), true);
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Uriah Quelp"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. Uriah Quelp"));
			RemovePassenger(pchar, characterFromID("Lt. Uriah Quelp"));
			LAi_QuestDelay("Bush_gets_suspicious2", 2.0);
		break;

		case "Bush_gets_suspicious2":
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");

			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "What_was_that_all_about";
		break;

		case "find_the_95th":
			AddQuestRecord("Old Friends - New Enemies", 5);
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "First time";


			Pchar.quest.find_the_95th2.win_condition.l1 = "location";
			PChar.quest.find_the_95th2.win_condition.l1.character = Pchar.id;
			Pchar.quest.find_the_95th2.win_condition.l1.location = "Grand_Cayman_town";
			Pchar.quest.find_the_95th2.win_condition = "find_the_95th2";
			Locations[FindLocation("Greenford_port")].vcskip = false;
			Locations[FindLocation("Greenford_tavern")].vcskip = false;
		break;

		case "find_the_95th2":
			Locations[FindLocation("Grand_Cayman_town")].reload.l8.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Grand_Cayman_town", "goto", "goto27");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Grand_Cayman_Tavern", "goto", "goto6");
			LAi_SetCitizenType(characterFromID("Able Seaman Stanley")); // PB: Allow dialog with this character
			Characters[GetCharacterIndex("Able Seaman Stanley")].dialog.CurrentNode = "Rifleman";
			LAi_SetGuardianType(characterFromID("Rifleman Mansfield"));
			Characters[GetCharacterIndex("Rifleman Mansfield")].dialog.CurrentNode = "Take_you_to_camp";
		break;

		case "Lead_off_to_Rifles":
			ChangeCharacterAddress(characterFromID("Able Seaman Stanley"), "None", "");
			Locations[FindLocation("Grand_Cayman_town")].reload.l8.disable = 0;
			Locations[FindLocation("Cayman_Jungle_02")].vcskip = true;
			LAi_SetActorType(characterFromID("Rifleman Mansfield"));
			LAi_ActorGoToLocation(characterFromID("Rifleman Mansfield"), "reload", "reload19", "none", "", "", "Lead_off_to_Rifles2",0.0);
		break;

		case "Lead_off_to_Rifles2":
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Cayman_Jungle_02", "goto", "locator5");
			ChangeCharacterAddressGroup(characterFromID("Captain Murray"), "Cayman_Jungle_02", "goto", "locator7");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Brown"), "Cayman_Jungle_02", "goto", "locator9");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Norton"), "Cayman_Jungle_02", "goto", "locator6");

			LAi_SetActorType(characterFromID("Rifleman Mansfield"));
			characters[GetCharacterIndex("Rifleman Mansfield")].Dialog.Filename = "Rifleman Mansfield_dialog.c";
			LAi_ActorDialogNow(characterFromID("Rifleman Mansfield"),PChar,"",1.0);
			Characters[GetCharacterIndex("Rifleman Mansfield")].dialog.CurrentNode = "Officer_over_there";
		break;

		case "Talk_to_Murray":
			LAi_SetActorType(characterFromID("Rifleman Mansfield"));
			LAi_SetGuardianType(characterFromID("Captain Murray"));
			Characters[GetCharacterIndex("Captain Murray")].dialog.CurrentNode = "Looking_for_who";
		break;

		case "Dunnitt_for_transfer":
			Locations[FindLocation("Outskirts_House")].vcskip = true;
			LAi_SetActorType(characterFromID("Captain Murray"));
			LAi_ActorGoToLocation(characterFromID("Captain Murray"), "reload", "reload3", "none", "", "", "Dunnitt_explodes",0.0);
		break;

		case "Dunnitt_explodes":
			LAi_SetActorType(characterFromID("Captain Murray"));
			ChangeCharacterAddressGroup(characterFromID("Captain Murray"), "Outskirts_House", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Major Dunnitt"), "Outskirts_House", "goto", "goto1");
			Characters[GetCharacterIndex("Captain Murray")].dialog.CurrentNode = "First time";
			Characters[GetCharacterIndex("Major Dunnitt")].dialog.CurrentNode = "Transfer Sharpe";
		break;

		case "Papers_in_order":
			LAi_SetActorType(characterFromID("Captain Murray"));
			characters[GetCharacterIndex("Captain Murray")].Dialog.Filename = "Captain Murray_dialog.c";
			LAi_ActorDialog(characterFromID("Captain Murray"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Murray")].dialog.CurrentNode = "Papers_in_order";
		break;

		case "Dunnitt_reams_Sharpe":
			LAi_SetActorType(characterFromID("Major Dunnitt"));
			characters[GetCharacterIndex("Major Dunnitt")].Dialog.Filename = "Major Dunnitt_dialog.c";
			LAi_ActorDialog(characterFromID("Major Dunnitt"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Major Dunnitt")].dialog.CurrentNode = "Take_the_man";
		break;

		case "Sharpe_find_Hogan":
			Pchar.quest.Sharpe_find_Hogan2.win_condition.l1 = "location";
			PChar.quest.Sharpe_find_Hogan2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sharpe_find_Hogan2.win_condition.l1.location = "Cayman_Jungle_02";
			Pchar.quest.Sharpe_find_Hogan2.win_condition = "Sharpe_find_Hogan2";
		break;

		case "Sharpe_find_Hogan2":
			ChangeCharacterAddress(characterFromID("Major Dunnitt"), "None", "");
			ChangeCharacterAddress(characterFromID("Captain Murray"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Cayman_Jungle_02", "goto", "locator8");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Cayman_Jungle_02", "goto", "citizen02");
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Where_is_Hogan";
			LAi_QuestDelay("Hogan_talk_with_Sharpe", 0.0);
		break;

		case "Hogan_talk_with_Sharpe":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Where_is_Hogan";
		break;

		case "Sea_for_Charlestown_and Friends":
			AddQuestRecord("Old Friends - New Enemies", 6);
			AddCharacterGoods(pchar, GOOD_RUM, 44);
			AddCharacterGoods(pchar, GOOD_WHEAT, 86);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Richard Sharpe"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Patrick Harper"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			SetCharacterRemovable(characterFromID("Patrick Harper"), false);

			Pchar.quest.Hogan_Hunt_Charlestown.win_condition.l1 = "location";
			PChar.quest.Hogan_Hunt_Charlestown.win_condition.l1.character = Pchar.id;
			Pchar.quest.Hogan_Hunt_Charlestown.win_condition.l1.location = "Charlestown_port";
			Pchar.quest.Hogan_Hunt_Charlestown.win_condition = "Hogan_Hunt_Charlestown";
			Locations[FindLocation("Cayman_Jungle_02")].vcskip = false;
			Locations[FindLocation("Outskirts_House")].vcskip = false;
		break;

		case "Hogan_Hunt_Charlestown":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			Locations[FindLocation("Charlestown_port")].vcskip = true;
			ChangeCharacterAddress(characterFromID("Rifleman Norton"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Brown"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Mansfield"), "None", "");
			LAi_SetActorType(PChar);
			SetCharacterRemovable(characterFromID("Patrick Harper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Patrick Harper"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("Lt. William Bush"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. William Bush"));
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Charlestown_port", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Charlestown_port", "officers", "reload1_3");
			LAi_ActorGoToLocator((Pchar), "officers", "reload1_2", "Hogan_Hunt_Charlestown2", 10);
		break;

		case "Hogan_Hunt_Charlestown2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Off_to_meet_Teresa";
		break;

		case "To_see_Teresa":
			Locations[FindLocation("Mystery_House")].vcskip = true;
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. William Bush"));
			SetCharacterRemovable(characterFromID("Lt. William Bush"), false);
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "reload", "houseH1", "Sharpe_went_ahead",0.0);
			ChangeCharacterAddressGroup(characterFromID("Teresa Moreno"), "Mystery_House", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Guerilla One"), "Mystery_House", "reload", "reload2");
			ChangeCharacterAddressGroup(characterFromID("Guerilla Two"), "Mystery_House", "reload", "reload3");
			ChangeCharacterAddressGroup(characterFromID("Guerilla Three"), "Mystery_House", "goto", "goto8");
		break;

		case "Sharpe_went_ahead":
			ChangeCharacterAddress(characterFromID("Richard Sharpe"), "None", "");
			Pchar.quest.To_see_Teresa2.win_condition.l1 = "location";
			PChar.quest.To_see_Teresa2.win_condition.l1.character = Pchar.id;
			Pchar.quest.To_see_Teresa2.win_condition.l1.location = "Mystery_House";
			Pchar.quest.To_see_Teresa2.win_condition = "To_see_Teresa2";
		break;

		case "To_see_Teresa2":
			LAi_SetActorType(pchar);
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Mystery_House", "goto", "goto1");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetGuardianType(characterFromID("Lt. William Bush"));
			LAi_QuestDelay("To_see_Teresa3", 0.0);
		break;

		case "To_see_Teresa3":
			LAi_ActorGoToLocator((Pchar), "goto", "goto6", "To_see_Teresa4", 10);
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto1", "",0.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Introduce_Teresa";
		break;

		case "To_see_Teresa4":
			LAi_SetPlayerType(pchar);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialogNow(characterFromID("Richard Sharpe"),PChar,"",2.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Introduce_Teresa";
		break;

		case "Teresa_speaks_up":
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "This_is_my_plan";
		break;

		case "Hogan_and_Relict":
			SetCurrentTime(23.00, 0);
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));

			Pchar.quest.Bush_found_in_Tavern.win_condition.l1 = "location";
			Pchar.quest.Bush_found_in_Tavern.win_condition.l1.character = Pchar.id;
			Pchar.quest.Bush_found_in_Tavern.win_condition.l1.location = "Charlestown_Tavern";
			Pchar.quest.Bush_found_in_Tavern.win_condition = "Bush_found_in_Tavern";
		break;

		case "Bush_found_in_Tavern":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Is_this_wise_sir";
		break;

		case "Bush_and_me_get_some_sleep":
			Pchar.quest.Sleep_in_Tavern_done.win_condition.l1 = "location";
			Pchar.quest.Sleep_in_Tavern_done.win_condition.l1.character = Pchar.id;
			Pchar.quest.Sleep_in_Tavern_done.win_condition.l1.location = "Charlestown_tavern_upstairs";
			Pchar.quest.Sleep_in_Tavern_done.win_condition = "Sleep_in_Tavern_done";
		break;

		case "Sleep_in_Tavern_done":
			Pchar.quest.Morning_in_Tavern_Bush.win_condition.l1 = "location";
			Pchar.quest.Morning_in_Tavern_Bush.win_condition.l1.character = Pchar.id;
			Pchar.quest.Morning_in_Tavern_Bush.win_condition.l1.location = "Charlestown_Tavern";
			Pchar.quest.Morning_in_Tavern_Bush.win_condition = "Morning_in_Tavern_Bush";
		break;

		case "Morning_in_Tavern_Bush":
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Charlestown_Tavern", "goto", "goto5");
			LAi_QuestDelay("Morning_in_Tavern_Bush2", 10.0);
		break;

		case "Morning_in_Tavern_Bush2":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "The_Hogan_ship_is_ready";
		break;

		case "Meet_Teresa_on_dock":
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));

			Pchar.quest.Morning_on_dock_Teresa.win_condition.l1 = "location";
			Pchar.quest.Morning_on_dock_Teresa.win_condition.l1.character = Pchar.id;
			Pchar.quest.Morning_on_dock_Teresa.win_condition.l1.location = "Charlestown_port";
			Pchar.quest.Morning_on_dock_Teresa.win_condition = "Morning_on_dock_Teresa";
		break;

		case "Morning_on_dock_Teresa":
			AddQuestRecord("Old Friends - New Enemies", 7);
			ChangeCharacterAddressGroup(characterFromID("Teresa Moreno"), "Charlestown_port", "goto", "goto15");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Charlestown_port", "officers", "houseS3_2");
			LAi_SetActorType(characterFromID("Richard Sharpe"));

			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "Hogan_on_Guadeloupe";
		break;

		case "Land_Guedeloupe_for_Hogan":
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));
			pchar.quest.To_Guadeloupe_shore_Hogan.win_condition.l1 = "location";
			Pchar.quest.To_Guadeloupe_shore_Hogan.win_condition.l1.character = Pchar.id;
			pchar.quest.To_Guadeloupe_shore_Hogan.win_condition.l1.location = "Guadeloupe_shore_01";
			pchar.quest.To_Guadeloupe_shore_Hogan.win_condition = "To_Guadeloupe_shore_Hogan";
			DeleteAttribute(&Locations[FindLocation("Charlestown_port")],"vcskip");
		break;

		case "To_Guadeloupe_shore_Hogan":
			DisableFastTravel(true);
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			ChangeCharacterAddressGroup(characterFromID("Teresa Moreno"), "Guadeloupe_shore_01", "goto", "citizen02");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_shore_01", "goto", "locator11");
			ChangeCharacterAddressGroup(characterFromID("Guerilla One"), "Guadeloupe_shore_01", "goto", "seaman1");
			ChangeCharacterAddressGroup(characterFromID("Guerilla Two"), "Guadeloupe_shore_01", "goto", "seaman2");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Guadeloupe_shore_01", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Guadeloupe_shore_01", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Guadeloupe_shore_01", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Guadeloupe_shore_01", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Guadeloupe_shore_01", "goto", "citizen03");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_shore_01", "goto", "locator13");

			GiveItem2Character(characterFromID("Teresa Moreno"), "blade4");
			EquipCharacterByItem(characterFromID("Teresa Moreno"), "blade4");
			GiveItem2Character(characterFromID("Teresa Moreno"), "pistol1");
			EquipCharacterByItem(characterFromID("Teresa Moreno"), "pistol1");

			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "locator10", "To_Guadeloupe_shore_Hogan2", 10);
		break;

		case "To_Guadeloupe_shore_Hogan2":
			Locations[FindLocation("Guadeloupe_shore_01")].reload.l2.disable = 1;
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Beach_orders_Hogan";
		break;

		case "Hogan_Step_one":
			LAi_ActorGoToLocation(characterFromID("Lt. William Bush"), "reload", "see", "none", "", "", "Hogan_Step_two",0.0);
		break;

		case "Hogan_Step_two":
			LAi_SetOfficerType(characterFromID("Guerilla One"));
			LAi_SetOfficerType(characterFromID("Guerilla Two"));
			SetCharacterRemovable(characterFromID("Lt. William Bush"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. William Bush"));

			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "Hogan_Quest_Chatter";
		break;

		case "Hogan_Step_three":
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "First time";

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Hogan_Quest_Chatter_Sharpe";
		break;

		case "Hogan_Step_four":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Richard Sharpe"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Teresa Moreno"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			SetCharacterRemovable(characterFromID("Teresa Moreno"), false);
			LAi_SetActorType(characterFromID("Guerilla One"));
			LAi_SetActorType(characterFromID("Guerilla Two"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Rifleman Mansfield"));

			LAi_ActorRunToLocation(characterFromID("Patrick Harper"), "reload", "locator3_back", "none", "", "", "Hogan_Step_five",0.0);
			LAi_ActorRunToLocation(characterFromID("Guerilla One"), "reload", "locator3_back", "none", "", "", "",0.0);
			LAi_ActorRunToLocation(characterFromID("Guerilla Two"), "reload", "locator3_back", "none", "", "", "",0.0);
			LAi_ActorRunToLocation(characterFromID("Rifleman Cooper"), "reload", "locator3_back", "none", "", "", "",0.0);
			LAi_ActorRunToLocation(characterFromID("Rifleman Haggman"), "reload", "locator3_back", "none", "", "", "",0.0);
			LAi_ActorRunToLocation(characterFromID("Rifleman Harris"), "reload", "locator3_back", "none", "", "", "",0.0);
			LAi_ActorRunToLocation(characterFromID("Rifleman Tongue"), "reload", "locator3_back", "none", "", "", "",0.0);
			LAi_ActorRunToLocation(characterFromID("Rifleman Mansfield"), "reload", "locator3_back", "none", "", "", "",0.0);
		break;

		case "Hogan_Step_five":
			ChangeCharacterAddress(characterFromID("Guerilla One"), "None", "");
			ChangeCharacterAddress(characterFromID("Guerilla Two"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Harris"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Mansfield"), "None", "");
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"FR_Sloop","Le Rève",-1,FRANCE,true,true); // Teresa's ship
			SetCrewQuantity(pchar, 100);
			AddCharacterGoods(pchar, GOOD_RUM, 40);
			AddCharacterGoods(pchar, GOOD_WHEAT, 40);
			setCharacterShipLocation(Pchar, "Guadeloupe_Port");

			Locations[FindLocation("Guadeloupe_Jungle_03")].vcskip = true;

			pchar.quest.Hogan_Step_six.win_condition.l1 = "location";
			Pchar.quest.Hogan_Step_six.win_condition.l1.character = Pchar.id;
			pchar.quest.Hogan_Step_six.win_condition.l1.location = "Guadeloupe_Jungle_03";
			pchar.quest.Hogan_Step_six.win_condition = "Hogan_Step_six";
		break;

		case "Hogan_Step_six":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Run_to_bushes";
		break;

		case "Hogan_Step_sixAAA":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			pchar.quest.French_Company = "one";
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "goto", "goto14", "Hogan_Step_seven", 10);
		break;

		case "Hogan_Step_seven":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "reload", "reload1"); // was reload2_back
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier6X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier7X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier8X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier9X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier10X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier11X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier12X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier13X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier14X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier15X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier16X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier17X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier18X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier19X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier20X";

			LAi_SetActorType(characterFromID("Soldier1X"));
			LAi_SetActorType(characterFromID("Soldier2X"));
			LAi_SetActorType(characterFromID("Soldier3X"));
			LAi_SetActorType(characterFromID("Soldier4X"));
			LAi_SetActorType(characterFromID("Soldier5X"));
			LAi_SetActorType(characterFromID("Soldier6X"));
			LAi_SetActorType(characterFromID("Soldier7X"));
			LAi_SetActorType(characterFromID("Soldier8X"));
			LAi_SetActorType(characterFromID("Soldier9X"));
			LAi_SetActorType(characterFromID("Soldier10X"));
			LAi_SetActorType(characterFromID("Soldier11X"));
			LAi_SetActorType(characterFromID("Soldier12X"));
			LAi_SetActorType(characterFromID("Soldier13X"));
			LAi_SetActorType(characterFromID("Soldier14X"));
			LAi_SetActorType(characterFromID("Soldier15X"));
			LAi_SetActorType(characterFromID("Soldier16X"));
			LAi_SetActorType(characterFromID("Soldier17X"));
			LAi_SetActorType(characterFromID("Soldier18X"));
			LAi_SetActorType(characterFromID("Soldier19X"));
			LAi_SetActorType(characterFromID("Soldier20X"));
			LAi_QuestDelay("Hogan_Step_eight", 0.0);
		break;

		case "Hogan_Step_eight":
			PlaySound("OBJECTS\DUEL\French_DrumsA.wav");
			LAi_ActorGoToLocator(characterFromID("Soldier1X"), "reload", "reload2_back", "",0.0); // was reload1
			LAi_ActorGoToLocator(characterFromID("Soldier2X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier3X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier4X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier5X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier6X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier7X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier8X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier9X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier10X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier11X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier12X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier13X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier14X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier16X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier17X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier18X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier19X"), "reload", "reload2_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier20X"), "reload", "reload2_back", "",0.0);

			LAi_QuestDelay("Hogan_Step_Nine", 30.0);
		break;

		case "Hogan_Step_nine":
			ChangeCharacterAddress(characterFromID("Soldier1X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier2X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier3X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier4X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier5X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier6X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier7X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier8X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier9X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier10X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier11X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier12X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier13X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier14X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier15X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier16X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier17X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier18X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier19X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier20X"), "None", "");

			LAi_QuestDelay("Hogan_Step_NineAAA", 0.0);
		break;

		case "Hogan_Step_NineAAA":
//			if(CheckQuestAttribute("French_Company", "two"))
//			{
			LAi_QuestDelay("Hogan_Step_eleven", 0.0);
//			}
//			if(CheckQuestAttribute("French_Company", "one"))
//			{
//			LAi_QuestDelay("Hogan_Step_ten", 0.0);
//			}
		break;

		case "Hogan_Step_ten":
			pchar.quest.French_Company = "two";
			LAi_QuestDelay("Hogan_Step_seven", 0.0);
		break;

		case "Hogan_Step_eleven":
			ChangeCharacterAddress(characterFromID("Soldier1X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier2X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier3X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier4X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier5X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier6X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier7X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier8X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier9X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier10X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier11X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier12X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier13X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier14X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier15X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier16X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier17X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier18X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier19X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier20X"), "None", "");

			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "I_heard_them";
		break;

		case "Hogan_Step_twelve":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "First time";
			Locations[FindLocation("Guadeloupe_Jungle_01")].vcskip = true;

			pchar.quest.Hogan_Next_Valley.win_condition.l1 = "location";
			Pchar.quest.Hogan_Next_Valley.win_condition.l1.character = Pchar.id;
			pchar.quest.Hogan_Next_Valley.win_condition.l1.location = "Guadeloupe_Jungle_01";
			pchar.quest.Hogan_Next_Valley.win_condition = "Hogan_Next_Valley";
		break;

		case "Hogan_Next_Valley":
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "Fork_then_Left";
		break;

		case "Which_path_to_take":
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));
			Locations[FindLocation("Guadeloupe_Plantation")].vcskip = true;
			Locations[FindLocation("Guadeloupe_Jungle_03")].vcskip = true;
			Locations[FindLocation("Guadeloupe_Jungle_02")].vcskip = true;

			pchar.quest.Shouldnt_go_back.win_condition.l1 = "location";
			Pchar.quest.Shouldnt_go_back.win_condition.l1.character = Pchar.id;
			pchar.quest.Shouldnt_go_back.win_condition.l1.location = "Guadeloupe_Jungle_03";
			pchar.quest.Shouldnt_go_back.win_condition = "Shouldnt_go_back";

			pchar.quest.Fight_the_French_Hogan.win_condition.l1 = "location";
			Pchar.quest.Fight_the_French_Hogan.win_condition.l1.character = Pchar.id;
			pchar.quest.Fight_the_French_Hogan.win_condition.l1.location = "Guadeloupe_Jungle_02";
			pchar.quest.Fight_the_French_Hogan.win_condition = "Fight_the_French_Hogan";
			
			pchar.quest.Hogan_Next_Right.win_condition.l1 = "location";
			Pchar.quest.Hogan_Next_Right.win_condition.l1.character = Pchar.id;
			pchar.quest.Hogan_Next_Right.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Hogan_Next_Right.win_condition = "Hogan_Next_Right";
		break;
//TRAPS
		case "Shouldnt_go_back":
		
		break;

		case "Fight_the_French_Hogan":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";
			LAi_group_MoveCharacter(characterFromID("Soldier1X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier1X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier3X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier3X"), "FRANCE_SOLDIERS");
			LAi_QuestDelay("Fight_the_French_Hogan2", 2.0);
		break;

		case "Fight_the_French_Hogan2":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
//			LAi_group_SetCheck("FRANCE_SOLDIERS", "Three_French_Soldiers3");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;
//END TRAPS
		case "Hogan_Next_Right":
			ChangeCharacterAddressGroup(characterFromID("Guerilla One"), "Guadeloupe_Plantation", "goto", "goto28");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "blackman", "goto", "goto11");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			LAi_SetActorType(sld);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "rabblack_1", "officers", "houseS2_3");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			LAi_SetActorType(sld);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "33_Ronald", "goto", "goto15");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			LAi_SetActorType(sld);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "rabblack", "goto", "goto6");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			LAi_SetActorType(sld);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "rabblack_2", "goto", "goto8");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			LAi_SetActorType(sld);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "reload", "reload2_back"); // was reaload1
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload2_back");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			LAi_SetActorType(characterFromID("Soldier1X"));
			LAi_SetActorType(characterFromID("Soldier2X"));
			LAi_SetActorType(characterFromID("Soldier3X"));
			LAi_SetActorType(characterFromID("Soldier4X"));
			LAi_SetActorType(characterFromID("Soldier5X"));

			LAi_SetActorType(characterFromID("Teresa Moreno"));
			LAi_ActorRunToLocator(characterFromID("Teresa Moreno"), "goto", "goto26", "Hogan_Next_Right2",0.0);
		break;

		case "Hogan_Next_Right2":
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "Keep_to_the_right";
		break;

		case "Plantation_at_last":
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "First time";

			pchar.quest.Even_more_French_troops.win_condition.l1 = "locator";
			pchar.quest.Even_more_French_troops.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Even_more_French_troops.win_condition.l1.locator_group = "goto";
			pchar.quest.Even_more_French_troops.win_condition.l1.locator = "goto25";
			pchar.quest.Even_more_French_troops.win_condition = "Even_more_French_troops";
		break;

		case "Even_more_French_troops":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Even_more_Troops";
		break;

		case "This_is_really_strange":
			LAi_SetActorType(PChar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "First time";
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto27", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Teresa Moreno"), "goto", "goto27", "",0.0);
			PlaySound("OBJECTS\DUEL\French_DrumsA.wav");
			LAi_ActorGoToLocator(characterFromID("Soldier1X"), "reload", "reload1", "",0.0); // was reload2_back
			LAi_ActorGoToLocator(characterFromID("Soldier2X"), "reload", "reload1", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier3X"), "reload", "reload1", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier4X"), "reload", "reload1", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Soldier5X"), "reload", "reload1", "",0.0);
			
			LAi_QuestDelay("This_is_really_strange2", 40.0);
		break;

		case "This_is_really_strange2":
			LAi_SetPlayerType(PChar);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			ChangeCharacterAddress(characterFromID("Soldier1X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier2X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier3X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier4X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier5X"), "None", "");

			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "Go_to_Hogans_house";
		break;

		case "walk_through_plantation":
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));
			Locations[FindLocation("Guadeloupe_Plantation_inside")].vcskip = true;
			LAi_SetActorType(characterFromID("Guerilla One"));
			LAi_ActorGoToLocator(characterFromID("Guerilla One"), "goto", "goto15", "",0.0);

			pchar.quest.Hogan_Discussion.win_condition.l1 = "location";
			Pchar.quest.Hogan_Discussion.win_condition.l1.character = Pchar.id;
			pchar.quest.Hogan_Discussion.win_condition.l1.location = "Guadeloupe_Plantation_inside";
			pchar.quest.Hogan_Discussion.win_condition = "Hogan_Discussion";
		break;

		case "Hogan_Discussion":
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			ChangeCharacterAddress(characterFromID("François de Vigny"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Major Hogan"), "Guadeloupe_Plantation_inside", "goto", "goto8");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_Plantation_inside", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Teresa Moreno"), "Guadeloupe_Plantation_inside", "goto", "goto2");
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto7", "Hogan_Discussion2", 10);
		break;

		case "Hogan_Discussion2":
			LAi_SetPlayerType(PChar);
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto6", "Hogan_Discussion3",0.0);
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));
		break;

		case "Hogan_Discussion3":
			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"),(Pchar));
			LAi_SetActorType(characterFromID("Major Hogan"));
			characters[GetCharacterIndex("Major Hogan")].Dialog.Filename = "Major Hogan_dialog.c";
			LAi_ActorDialog(characterFromID("Major Hogan"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Major Hogan")].dialog.CurrentNode = "First_conversation";
		break;

		case "Teresa's_Bargain":
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "My_Mission";
		break;

		case "Hogan_Discussion4":
			LAi_SetActorType(characterFromID("Major Hogan"));
			characters[GetCharacterIndex("Major Hogan")].Dialog.Filename = "Major Hogan_dialog.c";
			LAi_ActorDialog(characterFromID("Major Hogan"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Major Hogan")].dialog.CurrentNode = "Second_conversation";
		break;

		case "Change_my_clothes":
			AddQuestRecord("Old Friends - New Enemies", 8);
			Locations[FindLocation("Guadeloupe_Plantation_inside")].reload.l1.disable = 1;

			pchar.quest.My_new_Clothes.win_condition.l1 = "location";
			Pchar.quest.My_new_Clothes.win_condition.l1.character = Pchar.id;
			pchar.quest.My_new_Clothes.win_condition.l1.location = "Guadeloupe_Plantation_bedroom";
			pchar.quest.My_new_Clothes.win_condition = "My_new_Clothes";
		break;

		case "My_new_Clothes":
			Locations[FindLocation("Guadeloupe_Plantation_inside")].reload.l1.disable = 0;
			GiveModel2Player("CivilianHB", true);
			Characters[GetCharacterIndex("Major Hogan")].dialog.CurrentNode = "Third_conversation";

			pchar.quest.All_dressed_up.win_condition.l1 = "location";
			Pchar.quest.All_dressed_up.win_condition.l1.character = Pchar.id;
			pchar.quest.All_dressed_up.win_condition.l1.location = "Guadeloupe_Plantation_inside";
			pchar.quest.All_dressed_up.win_condition = "All_dressed_up";
		break;

		case "All_dressed_up":
			ChangeCharacterAddressGroup(characterFromID("Major Hogan"), "Guadeloupe_Plantation_inside", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_Plantation_inside", "goto", "goto1");
			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"),(Pchar));
			ChangeCharacterAddressGroup(characterFromID("Teresa Moreno"), "Guadeloupe_Plantation_inside", "goto", "goto2");

			LAi_SetActorType(characterFromID("Major Hogan"));
			characters[GetCharacterIndex("Major Hogan")].Dialog.Filename = "Major Hogan_dialog.c";
			LAi_ActorDialog(characterFromID("Major Hogan"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Major Hogan")].dialog.CurrentNode = "Third_conversation";
		break;

		case "Dunnitt_sends Sharpe_off":
			Characters[GetCharacterIndex("Major Hogan")].dialog.CurrentNode = "First time";
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			LAi_type_actor_Reset(characterFromID("Rifleman Tongue"));
			LAi_type_actor_Reset(characterFromID("Rifleman Haggman"));
			LAi_type_actor_Reset(characterFromID("Rifleman Harris"));
			LAi_type_actor_Reset(characterFromID("Rifleman Higgins"));
			LAi_type_actor_Reset(characterFromID("Rifleman Cooper"));

			pchar.quest.Begin_Relic_Quest.win_condition.l1 = "location";
			Pchar.quest.Begin_Relic_Quest.win_condition.l1.character = Pchar.id;
			pchar.quest.Begin_Relic_Quest.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Begin_Relic_Quest.win_condition = "Begin_Relic_Quest";
		break;

		case "Begin_Relic_Quest":
			ChangeCharacterAddressGroup(characterFromID("Major Dunnitt"), "Guadeloupe_Plantation", "officers", "houseS1_2");
			ChangeCharacterAddressGroup(characterFromID("Captain Murray"), "Guadeloupe_Plantation", "goto", "goto30");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Perkins"), "Guadeloupe_Plantation", "goto", "goto31");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Brown"), "Guadeloupe_Plantation", "goto", "goto32");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Norton"), "Guadeloupe_Plantation", "goto", "goto33");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Williams"), "Guadeloupe_Plantation", "goto", "goto34");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Fisher"), "Guadeloupe_Plantation", "goto", "goto35");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Baker"), "Guadeloupe_Plantation", "goto", "goto36");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Guadeloupe_Plantation", "goto", "goto38");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Guadeloupe_Plantation", "goto", "goto39");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Guadeloupe_Plantation", "goto", "goto40");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Guadeloupe_Plantation", "goto", "goto41");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Guadeloupe_Plantation", "goto", "goto42");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Plantation", "goto", "goto43");

			Characters[GetCharacterIndex("Major Dunnitt")].dialog.CurrentNode = "Not_you_Sharpe";

			pchar.quest.Split_troops.win_condition.l1 = "locator";
			pchar.quest.Split_troops.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Split_troops.win_condition.l1.locator_group = "goto";
			pchar.quest.Split_troops.win_condition.l1.locator = "goto29";
			pchar.quest.Split_troops.win_condition = "Split_troops";
		break;

		case "Split_troops":
			LAi_SetActorType(characterFromID("Major Dunnitt"));
			characters[GetCharacterIndex("Major Dunnitt")].Dialog.Filename = "Major Dunnitt_dialog.c";
			LAi_ActorDialogNow(characterFromID("Major Dunnitt"),PChar,"",2.0);
			Characters[GetCharacterIndex("Major Dunnitt")].dialog.CurrentNode = "Not_you_Sharpe";
		break;

		case "Get_Harper_Cooper":
			LAi_SetActorType(PChar);
			LAi_SetActorType(characterFromID("Rifleman Perkins"));
			LAi_ActorGoToLocation(characterFromID("Captain Murray"), "reload", "houseS1", "none", "", "", "Get_Harper_Cooper2",0.0);
			LAi_ActorGoToLocation(characterFromID("Major Dunnitt"), "reload", "houseS1", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("Rifleman Perkins"), "goto", "goto45", "none", "", "", "",0.0);
		break;

		case "Get_Harper_Cooper2":
			LAi_ActorGoToLocation(characterFromID("Rifleman Williams"), "goto", "goto45", "none", "", "", "Get_Harper_Cooper3",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Brown"), "goto", "goto45", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Fisher"), "goto", "goto45", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Norton"), "goto", "goto45", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Baker"), "goto", "goto45", "",0.0);
		break;

		case "Get_Harper_Cooper3":
			ChangeCharacterAddress(characterFromID("Rifleman Brown"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Fisher"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Norton"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Baker"), "None", "");
			ChangeCharacterAddress(characterFromID("Guerilla One"), "None", "");
			LAi_QuestDelay("Get_Harper_Cooper4", 1.0);
		break;

		case "Get_Harper_Cooper4":
			LAi_ActorGoToLocator((Pchar), "goto", "goto37", "Get_Harper_Cooper5", 10);
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			LAi_ActorGoToLocator(characterFromID("Teresa Moreno"), "goto", "goto35", "",0.0);
		break;

		case "Get_Harper_Cooper5":
			LAi_SetPlayerType(PChar);
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "We'll_fight_from_hill";
		break;

		case "Collect_Harper_Cooper":
			Characters[GetCharacterIndex("Patrick Harper")].model = "HarperCivl";
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_HarperCivl";
			Characters[GetCharacterIndex("Rifleman Cooper")].model = "CooperCV";
			Characters[GetCharacterIndex("Rifleman Cooper")].headmodel = "h_CooperCV";

			pchar.quest.Have_Harper_Cooper.win_condition.l1 = "location";
			Pchar.quest.Have_Harper_Cooper.win_condition.l1.character = Pchar.id;
			pchar.quest.Have_Harper_Cooper.win_condition.l1.location = "Guadeloupe_Plantation_inside";
			pchar.quest.Have_Harper_Cooper.win_condition = "Have_Harper_Cooper";
		break;

		case "Have_Harper_Cooper":
			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			ChangeCharacterAddressGroup(characterFromID("Major Hogan"), "Guadeloupe_Plantation_inside", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Plantation_inside", "goto", "goto8");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Guadeloupe_Plantation_inside", "goto", "goto4");

			LAi_SetActorType(characterFromID("Major Hogan"));
			characters[GetCharacterIndex("Major Hogan")].Dialog.Filename = "Major Hogan_dialog.c";
			LAi_ActorDialog(characterFromID("Major Hogan"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Major Hogan")].dialog.CurrentNode = "Fourth_conversation";
		break;

		case "To_town_with_Teresa":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Patrick Harper"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Rifleman Cooper"));
			SetCharacterRemovable(characterFromID("Patrick Harper"), false);
			SetCharacterRemovable(characterFromID("Rifleman Cooper"), false);
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Harris"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");

			pchar.quest.Town_Relic_Quest.win_condition.l1 = "location";
			Pchar.quest.Town_Relic_Quest.win_condition.l1.character = Pchar.id;
			pchar.quest.Town_Relic_Quest.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Town_Relic_Quest.win_condition = "Town_Relic_Quest";
		break;

		case "Town_Relic_Quest":
			ChangeCharacterAddress(characterFromID("Major Hogan"), "None", "");

			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "Richard_has_Gone";
		break;

		case "Next_stop_Church":
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));
			pchar.quest.Soldier_Company = "Rifles";

			Locations[FindLocation("Guadeloupe_Port")].reload.l9.disable = 1;
			ChangeCharacterAddress(characterFromID("Pater Dominic"), "None", ""); // GR

			pchar.quest.Harper_keeps_watch.win_condition.l1 = "locator";
			pchar.quest.Harper_keeps_watch.win_condition.l1.location = "Guadeloupe_Port";
			pchar.quest.Harper_keeps_watch.win_condition.l1.locator_group = "reload";
			pchar.quest.Harper_keeps_watch.win_condition.l1.locator = "reload7_back";
			pchar.quest.Harper_keeps_watch.win_condition = "Harper_keeps_watch";
		break;

		case "Harper_keeps_watch":
			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "I'll_look_around";
		break;

		case "Teresa_Cooper_Church":
			Locations[FindLocation("Guadeloupe_Port")].reload.l9.disable = 0;

			pchar.quest.Pick_Lock_Cooper.win_condition.l1 = "location";
			Pchar.quest.Pick_Lock_Cooper.win_condition.l1.character = Pchar.id;
			pchar.quest.Pick_Lock_Cooper.win_condition.l1.location = "PaP_church";
			pchar.quest.Pick_Lock_Cooper.win_condition = "Pick_Lock_Cooper";
		break;

		case "Pick_Lock_Cooper":
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "PaP_church", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Teresa Moreno"), "PaP_church", "goto", "goto5");

			pchar.quest.Wrong_Church_Door.win_condition.l1 = "locator";
			pchar.quest.Wrong_Church_Door.win_condition.l1.location = "PaP_church";
			pchar.quest.Wrong_Church_Door.win_condition.l1.locator_group = "goto";
			pchar.quest.Wrong_Church_Door.win_condition.l1.locator = "goto7";
			pchar.quest.Wrong_Church_Door.win_condition = "Wrong_Church_Door";

			pchar.quest.Church_Door_Locked.win_condition.l1 = "locator";
			pchar.quest.Church_Door_Locked.win_condition.l1.location = "PaP_church";
			pchar.quest.Church_Door_Locked.win_condition.l1.locator_group = "goto";
			pchar.quest.Church_Door_Locked.win_condition.l1.locator = "goto2";
			pchar.quest.Church_Door_Locked.win_condition = "Church_Door_Locked";
		break;
// TRAP
		case "Wrong_Church_Door":
			Pchar.Quest.Church_Door_Locked.over = "yes";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto5");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			LAi_SetOfficerType(characterFromID("soldier1X"));
			LAi_SetOfficerType(characterFromID("soldier2X"));
			LAi_SetOfficerType(characterFromID("soldier3X"));
			LAi_QuestDelay("Wrong_Church_Door2", 0.0);
		break;

		case "Wrong_Church_Door2":
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			characters[GetCharacterIndex("Rifleman Cooper")].Dialog.Filename = "Rifleman Cooper_dialog.c";
			LAi_ActorDialog(characterFromID("Rifleman Cooper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Rifleman Cooper")].dialog.CurrentNode = "Dont_know_much_French";
		break;

		case "A_French_Prison_waits":
			LAi_Fade("", "");
			LAi_QuestDelay("Deserters Jail", 0.0);
		break;
// END TRAP - GAME OVER
		case "Church_Door_Locked":
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			characters[GetCharacterIndex("Rifleman Cooper")].Dialog.Filename = "Rifleman Cooper_dialog.c";
			LAi_ActorDialog(characterFromID("Rifleman Cooper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Rifleman Cooper")].dialog.CurrentNode = "Pick_Lock_Chat";
		break;

		case "Church_Lock_Open":
			GiveItem2Character(Pchar, "lockpick");
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "goto", "goto1", "",0.0);
			LAi_QuestDelay("Church_Lock_Open2", 0.0);
		break;

		case "Church_Lock_Open2":
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "I_will_get_Relic";
		break;

		case "Gone_to_back_room":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto6", "", 10);
			LAi_SetOfficerType(characterFromID("Rifleman Cooper"));
			LAi_ActorGoToLocator(characterFromID("Teresa Moreno"), "goto", "goto2", "",0.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "The_Relic_I_have";
			LAi_QuestDelay("Gone_to_back_room2", 10.0);
		break;

		case "Gone_to_back_room2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "The_Relic_I_have";
		break;

		case "Options_outside_church":
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));
//			LAi_SetOfficerType(characterFromID("Rifleman Cooper"));

			pchar.quest.Ship_or_Battle.win_condition.l1 = "location";
			Pchar.quest.Ship_or_Battle.win_condition.l1.character = Pchar.id;
			pchar.quest.Ship_or_Battle.win_condition.l1.location = "Guadeloupe_Port";
			pchar.quest.Ship_or_Battle.win_condition = "Ship_or_Battle";
		break;

		case "Ship_or_Battle":
			Pchar.Quest.Wrong_Church_Door.over = "yes";

			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "Relic_to_Ship";
		break;

		case "Harper_on_Relic":
			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "Loyalty_forward";
		break;

		case "Chose_Teresa":
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "Reload", "gate", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "Reload", "gate", "",0.0);

			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "Take_Relic_to_Ship";
		break;

		case "Chose_Teresa2":
			LAi_SetOfficerType(characterFromID("Teresa Moreno"));
			pchar.quest.Fight_the_French_Hogan.over = "yes";

			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			LAi_QuestDelay("Chose_Teresa3", 1.0);
		break;

		case "Chose_Teresa3":
			LAi_type_actor_Reset(characterFromID("Richard Sharpe"));
			LAi_type_actor_Reset(characterFromID("Patrick Harper"));
			LAi_type_actor_Reset(characterFromID("Rifleman Cooper"));
			LAi_type_actor_Reset(characterFromID("Rifleman Haggman"));
			AddQuestRecord("Old Friends - New Enemies", 9);
			SetCharacterRemovable(characterFromID("Patrick Harper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Patrick Harper"));
			SetCharacterRemovable(characterFromID("Rifleman Cooper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rifleman Cooper"));
			HoistFlag(FRANCE);
			LAi_QuestDelay("Chose_Teresa4", 0.0);
		break;

		case "Chose_Teresa4":
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_shore_01", "goto", "goto19");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Guadeloupe_shore_01", "goto", "goto18");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_shore_01", "goto", "goto17");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Guadeloupe_shore_01", "goto", "goto16");
			Characters[GetCharacterIndex("Rifleman Cooper")].model = "Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].headmodel = "h_Rifleman95E3_18";
			Characters[GetCharacterIndex("Patrick Harper")].model = "Harper_Sergeant";
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Harper_Sergeant";

			pchar.quest.Reunite_with_Hotspur.win_condition.l1 = "location";
			Pchar.quest.Reunite_with_Hotspur.win_condition.l1.character = Pchar.id;
			pchar.quest.Reunite_with_Hotspur.win_condition.l1.location = "Guadeloupe_shore_01";
			pchar.quest.Reunite_with_Hotspur.win_condition = "Reunite_with_Hotspur";
		break;

		case "Reunite_with_Hotspur":
			DisableFastTravel(true);
			HoistFlag(ENGLAND);
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));

			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "locator10", "Reunite_with_Hotspur2", 10); //"citizen02",
		break;

		case "Reunite_with_Hotspur2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "Leave_you_with_Sharpe";
		break;

		case "Hotspur_behind_us":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Richard Sharpe"));
			LAi_QuestDelay("Come_out_Come_out", 3.0);
		break;

		case "Come_out_Come_out":
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Rifleman Cooper"));
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Rifleman Haggman"));
			LAi_QuestDelay("Come_out_Come_out2", 3.0);
		break;

		case "Come_out_Come_out2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Good_eye";
		break;

		case "Other_way_to_Lighthouse":
			LAi_SetGuardianType(characterFromID("Teresa Moreno"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
//			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "reload", "locator3_back", "", 40);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "reload", "locator3_back", "Other_way_to_Lighthouse2", 40);
		break;

		case "Other_way_to_Lighthouse2":
			SetCharacterRemovable(characterFromID("Teresa Moreno"), true);
			RemoveCharacterCompanion(Pchar, characterFromID("Teresa Moreno"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Teresa Moreno"));
			RemovePassenger(pchar, characterFromID("Teresa Moreno"));

			SetCharacterRemovable(characterFromID("Rifleman Cooper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rifleman Cooper"));
			RemovePassenger(pchar, characterFromID("Rifleman Cooper"));

			pchar.quest.Other_way_to_Lighthouse3.win_condition.l1 = "location";
			Pchar.quest.Other_way_to_Lighthouse3.win_condition.l1.character = Pchar.id;
			pchar.quest.Other_way_to_Lighthouse3.win_condition.l1.location = "Guadeloupe_Jungle_03";
			pchar.quest.Other_way_to_Lighthouse3.win_condition = "Other_way_to_Lighthouse3";
		break;

		case "Other_way_to_Lighthouse3":
			GiveModel2Player("brtHComdr_18", true);
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_Jungle_03", "officers", "reload3_1");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Jungle_03", "officers", "reload3_2");
			LAi_QuestDelay("Other_way_to_Lighthouse4", 0.0);
		break;

		case "Other_way_to_Lighthouse4":
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "officers", "reload2_2", "", 40);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "officers", "reload2_3", "", 40);

			pchar.quest.Other_way_to_Lighthouse5.win_condition.l1 = "location";
			Pchar.quest.Other_way_to_Lighthouse5.win_condition.l1.character = Pchar.id;
			pchar.quest.Other_way_to_Lighthouse5.win_condition.l1.location = "Guadeloupe_Jungle_01";
			pchar.quest.Other_way_to_Lighthouse5.win_condition = "Other_way_to_Lighthouse5";
		break;

		case "Other_way_to_Lighthouse5":
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_Jungle_01", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Jungle_01", "officers", "reload1_2");
			LAi_QuestDelay("Other_way_to_Lighthouse6", 0.0);
		break;

		case "Other_way_to_Lighthouse6":
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "officers", "reload3_2", "", 40);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "officers", "reload3_3", "", 40);

			pchar.quest.Other_way_to_Lighthouse7.win_condition.l1 = "location";
			Pchar.quest.Other_way_to_Lighthouse7.win_condition.l1.character = Pchar.id;
			pchar.quest.Other_way_to_Lighthouse7.win_condition.l1.location = "Guadeloupe_Jungle_02";
			pchar.quest.Other_way_to_Lighthouse7.win_condition = "Other_way_to_Lighthouse7";
		break;

		case "Other_way_to_Lighthouse7":
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_Jungle_02", "officers", "reload1_2");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Jungle_02", "officers", "reload1_3");
			LAi_QuestDelay("Other_way_to_Lighthouse8", 0.0);
		break;

		case "Other_way_to_Lighthouse8":
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "officers", "reload2_2", "", 40);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "officers", "reload2_1", "", 40);

			pchar.quest.Other_way_to_Lighthouse9.win_condition.l1 = "location";
			Pchar.quest.Other_way_to_Lighthouse9.win_condition.l1.character = Pchar.id;
			pchar.quest.Other_way_to_Lighthouse9.win_condition.l1.location = "Guadeloupe_Lighthouse";
			pchar.quest.Other_way_to_Lighthouse9.win_condition = "Other_way_to_Lighthouse9";
		break;

		case "Other_way_to_Lighthouse9":
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_Lighthouse", "officers", "reload1_2");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Lighthouse", "goto", "goto29");
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Seen_this_before";
		break;

		case "Chose_Riflemen":
			LAi_SetOfficerType(characterFromID("Patrick Harper"));

			LAi_SetActorType(characterFromID("Teresa Moreno"));
			characters[GetCharacterIndex("Teresa Moreno")].Dialog.Filename = "Teresa Moreno_dialog.c";
			LAi_ActorDialog(characterFromID("Teresa Moreno"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "We_Part_Company";
		break;

		case "Back_to_the_war":
			AddQuestRecord("Old Friends - New Enemies", 10);
			SetCharacterRemovable(characterFromID("Teresa Moreno"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Teresa Moreno"));
			RemovePassenger(pchar, characterFromID("Teresa Moreno"));
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "First time";

			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "We_need_to_find_Sharpe";
		break;

		case "Plantation_Battle":
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			Characters[GetCharacterIndex("Captain Murray")].model = "Cmurray_Wound18";
			Characters[GetCharacterIndex("Captain Murray")].headmodel = "h_Cmurray_Wound18";
			Characters[GetCharacterIndex("Major Dunnitt")].model = "Dunnitt_Wound18";
			Characters[GetCharacterIndex("Major Dunnitt")].headmodel = "h_Dunnitt_Wound18";

			LAi_type_actor_Reset(characterFromID("Richard Sharpe"));
			LAi_type_actor_Reset(characterFromID("Rifleman Norton"));

			pchar.quest.Battle_Positioning.win_condition.l1 = "location";
			Pchar.quest.Battle_Positioning.win_condition.l1.character = Pchar.id;
			pchar.quest.Battle_Positioning.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Battle_Positioning.win_condition = "Battle_Positioning";
		break;

		case "Battle_Positioning":
			LAi_SetActorType(characterFromID("Rifleman Cooper")); // Locking town gates
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			PlaySound("VOICE\ENGLISH\distant_guns.wav");

			ChangeCharacterAddressGroup(characterFromID("Captain Murray"), "Guadeloupe_Plantation", "goto", "goto47");
			LAi_SetActorType(characterFromID("Captain Murray"));
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_Plantation", "goto", "goto56");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			ChangeCharacterAddressGroup(characterFromID("Major Dunnitt"), "Guadeloupe_Plantation", "goto", "goto18");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Brown"), "Guadeloupe_Plantation", "goto", "goto52");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Norton"), "Guadeloupe_Plantation", "goto", "goto57");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Guadeloupe_Plantation", "goto", "goto46");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Fisher"), "Guadeloupe_Plantation", "goto", "goto16");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Perkins"), "Guadeloupe_Plantation", "goto", "goto61");
			Lai_KillCharacter(characterFromID("Rifleman Fisher"));
			ChangeCharacterAddressGroup(characterFromID("Rifleman Baker"), "Guadeloupe_Plantation", "goto", "goto10");
			Lai_KillCharacter(characterFromID("Rifleman Baker"));
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto49");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto50");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto51");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto53");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto54");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto60");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier6X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto11");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier7X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto59");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier8X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto9");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier9X";

			LAi_SetActorType(characterFromID("Soldier1X"));
			LAi_SetActorType(characterFromID("Soldier2X"));
			LAi_SetActorType(characterFromID("Soldier3X"));
			LAi_SetActorType(characterFromID("Soldier4X"));
			LAi_SetActorType(characterFromID("Soldier5X"));
			LAi_SetActorType(characterFromID("Soldier6X"));
			LAi_SetActorType(characterFromID("Soldier7X"));

			Lai_KillCharacter(characterFromID("Soldier7X"));

			LAi_SetActorType(characterFromID("Soldier8X"));

			Lai_KillCharacter(characterFromID("Soldier9X"));

			LAi_ActorTurnToCharacter(characterFromID("Soldier1X"), characterFromID("Richard Sharpe"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier2X"), characterFromID("Richard Sharpe"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier3X"), characterFromID("Richard Sharpe"));
			
			LAi_ActorTurnToCharacter(characterFromID("Soldier5X"), characterFromID("Richard Sharpe"));
			LAi_ActorTurnToCharacter(characterFromID("Soldier6X"), characterFromID("Richard Sharpe"));

			LAi_ActorTurnToCharacter(characterFromID("Soldier8X"), characterFromID("Richard Sharpe"));

			PlaySound("VOICE\ENGLISH\distant_guns.wav");

			pchar.quest.Make_immortal_for_battle.win_condition.l1 = "locator";
			pchar.quest.Make_immortal_for_battle.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Make_immortal_for_battle.win_condition.l1.locator_group = "goto";
			pchar.quest.Make_immortal_for_battle.win_condition.l1.locator = "goto63";
			pchar.quest.Make_immortal_for_battle.win_condition = "Make_immortal_for_battle";

			pchar.quest.Closer_view_fight.win_condition.l1 = "locator";
			pchar.quest.Closer_view_fight.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Closer_view_fight.win_condition.l1.locator_group = "goto";
			pchar.quest.Closer_view_fight.win_condition.l1.locator = "goto25";
			pchar.quest.Closer_view_fight.win_condition = "Closer_view_fight";
		break;

		case "Make_immortal_for_battle":
			LAi_SetImmortal(Pchar, true);
		break;

		case "Closer_view_fight":
			LAi_SetOfficerType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "goto", "goto55", "One_fight", 10);

			LAi_ActorAnimation(characterFromID("Soldier1X"), "shot", "", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier1X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier2X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier2X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier3X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier3X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier5X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier5X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_SetHP(characterFromID("Soldier6X"), 30.0, 30.0);
			LAi_SetHP(characterFromID("Major Dunnitt"), 50.0, 50.0);
			LAi_SetActorType(CharacterFromID("Soldier6X"));
			LAi_SetActorType(CharacterFromID("Major Dunnitt"));
			LAi_group_MoveCharacter(CharacterFromID("Soldier6X"), "Soldier6X");
			LAi_group_MoveCharacter(CharacterFromID("Major Dunnitt"), "Major Dunnitt");
			LAi_SetImmortal(CharacterFromID("Soldier6X"), true);
			LAi_SetImmortal(CharacterFromID("Major Dunnitt"), true);
			LAi_ActorAttack(characterFromID("Major Dunnitt"), characterFromID("Soldier6X"), "");
			LAi_ActorAttack(characterFromID("Soldier6X"), characterFromID("Major Dunnitt"), "");
		break;

		case "One_fight":
			LAi_SetActorType(characterFromID("Soldier1X"));
			LAi_SetActorType(characterFromID("Soldier2X"));
			LAi_SetActorType(characterFromID("Soldier3X"));
			LAi_SetActorType(characterFromID("Soldier5X"));

			LAi_ActorAnimation(characterFromID("Richard Sharpe"), "shot", "Two_fight", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Richard Sharpe"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier5X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier5X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier8X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav"); //PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier5X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_SetPlayerType(PChar);
			LAi_SetHP(characterFromID("Soldier4X"), 30.0, 30.0);
			LAi_SetHP(characterFromID("Rifleman Brown"), 50.0, 50.0);
			LAi_SetActorType(CharacterFromID("Soldier4X"));
			LAi_SetActorType(CharacterFromID("Rifleman Brown"));
			LAi_group_MoveCharacter(CharacterFromID("Soldier4X"), "Soldier4X");
			LAi_group_MoveCharacter(CharacterFromID("Rifleman Brown"), "Rifleman Brown");
			LAi_SetImmortal(CharacterFromID("Rifleman Brown"), true);
			LAi_SetImmortal(CharacterFromID("Soldier4X"), true);
			LAi_ActorAttack(characterFromID("Rifleman Brown"), characterFromID("Soldier4X"), "");
			LAi_ActorAttack(characterFromID("Soldier4X"), characterFromID("Rifleman Brown"), "");
		break;

		case "Two_fight":
			LAi_SetActorType(CharacterFromID("Soldier5X"));
			LAi_SetActorType(CharacterFromID("Soldier8X"));
			Lai_KillCharacter(characterFromID("Soldier3X"));

			PlaySound("OBJECTS\duel\pistol_shoot3.wav"); //PlaySound("OBJECTS\duel\pistol_bbus.wav");
			LAi_ActorAnimation(characterFromID("Rifleman Tongue"), "shot", "", 1.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav"); //PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Tongue"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Glad_you're_here";
		break;

		case "Harper_explains_Cooper":
			PlaySound("OBJECTS\duel\pistol_shoot3.wav"); //PlaySound("OBJECTS\duel\pistol_bbus.wav");
			LAi_SetActorType(characterFromID("Rifleman Tongue"));

			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "Cooper_doing_gates";
		break;

		case "French_pull_back":
			LAi_ActorAnimation(characterFromID("Soldier1X"), "shot", "French_pull_back2", 1.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav"); //PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier1X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Soldier2X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav"); //PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Soldier2X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_SetHP(characterFromID("Soldier5X"), 20.0, 20.0);
			LAi_SetHP(characterFromID("Rifleman Tongue"), 50.0, 50.0);
			LAi_SetActorType(CharacterFromID("Soldier5X"));
			LAi_SetActorType(CharacterFromID("Rifleman Tongue"));
			LAi_group_MoveCharacter(CharacterFromID("Soldier5X"), "Soldier5X");
			LAi_group_MoveCharacter(CharacterFromID("Rifleman Tongue"), "Rifleman Tongue");
			LAi_SetImmortal(CharacterFromID("Rifleman Tongue"), true);
			LAi_ActorAttack(characterFromID("Rifleman Tongue"), characterFromID("Soldier5X"), "");
			LAi_ActorAttack(characterFromID("Soldier5X"), characterFromID("Rifleman Tongue"), "");
		break;

		case "French_pull_back2":
			Lai_KillCharacter(characterFromID("Rifleman Norton"));

			LAi_SetActorType(CharacterFromID("Soldier1X"));
			LAi_SetActorType(CharacterFromID("Soldier2X"));

			LAi_ActorRunToLocator(characterFromID("Soldier1X"), "goto", "goto62", "",0.0);
			LAi_SetActorType(CharacterFromID("Rifleman Perkins"));
			LAi_ActorRunToLocator(characterFromID("Rifleman Perkins"), "goto", "goto62", "",0.0);

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Mop_up_time";
		break;

		case "The_local_battle_ends":
			Lai_KillCharacter(characterFromID("Soldier2X"));

			LAi_SetHP(characterFromID("Soldier1X"), 50.0, 50.0);
			LAi_SetHP(characterFromID("Rifleman Perkins"), 50.0, 50.0);
			LAi_SetActorType(CharacterFromID("Soldier1X"));
			LAi_SetActorType(CharacterFromID("Rifleman Perkins"));
			LAi_group_MoveCharacter(CharacterFromID("Soldier1X"), "Soldier1X");
			LAi_group_MoveCharacter(CharacterFromID("Rifleman Perkins"), "Rifleman Perkins");
			LAi_SetImmortal(CharacterFromID("Rifleman Perkins"), true);
			LAi_ActorAttack(characterFromID("Rifleman Perkins"), characterFromID("Soldier1X"), "");
			LAi_ActorAttack(characterFromID("Soldier1X"), characterFromID("Rifleman Perkins"), "");

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "goto15", "",0.0);
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_ActorRunToLocator(characterFromID("Patrick Harper"), "goto", "goto16", "",0.0);
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_ActorRunToLocator(characterFromID("Rifleman Cooper"), "goto", "goto11", "",0.0);
			LAi_SetActorType(characterFromID("Soldier8X"));

			pchar.quest.Murray_wounded.win_condition.l1 = "locator";
			pchar.quest.Murray_wounded.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Murray_wounded.win_condition.l1.locator_group = "goto";
			pchar.quest.Murray_wounded.win_condition.l1.locator = "goto28";
			pchar.quest.Murray_wounded.win_condition = "Murray_wounded";
		break;

		case "Murray_wounded":
			LAi_SetActorType(CharacterFromID("Rifleman Tongue"));
			LAi_ActorRunToLocator(characterFromID("Rifleman Tongue"), "goto", "goto58", "",0.0);
			LAi_SetImmortal(CharacterFromID("Rifleman Brown"), false);
			LAi_SetImmortal(CharacterFromID("Soldier4X"), false);
			Lai_KillCharacter(characterFromID("Soldier4X"));
			Lai_KillCharacter(characterFromID("Rifleman Brown"));
			LAi_QuestDelay("FIGHT PLAYER", 0.0);
		break;

		case "FIGHT PLAYER":
			LAi_SetHP(characterFromID("Soldier8X"), 20.0, 20.0);
			LAi_SetActorType(characterFromID("Soldier8X"));
			LAi_ActorAttack(characterFromID("Soldier8X"),(Pchar), "");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";

			PChar.quest.Murray_wounded333.win_condition.l1 = "NPC_Death";
			PChar.quest.Murray_wounded333.win_condition.l1.character = "Soldier8X";
			PChar.quest.Murray_wounded333.win_condition = "Murray_wounded333";
		break;

		case "Murray_wounded333":
			LAi_SetImmortal(CharacterFromID("Soldier6X"), false);
			LAi_SetImmortal(CharacterFromID("Major Dunnitt"), false);
			Lai_KillCharacter(characterFromID("Major Dunnitt"));
			Lai_KillCharacter(characterFromID("Soldier6X"));

			LAi_SetImmortal(CharacterFromID("Soldier1X"), false);
			Lai_KillCharacter(characterFromID("Soldier1X"));

			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto64", "Murray_wounded4", 10);
		break;

		case "Murray_wounded4":
			LAi_SetPlayerType(PChar);
			LAi_SetImmortal(Pchar, false);

			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			characters[GetCharacterIndex("Rifleman Tongue")].Dialog.Filename = "Rifleman Tongue_dialog.c";
			LAi_ActorDialog(characterFromID("Rifleman Tongue"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Rifleman Tongue")].dialog.CurrentNode = "Wounded_Murray";
		break;

		case "Murray_slumps":
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Rifleman Cooper"));

			RemoveCharacterEquip(characterFromID("Captain Murray"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Captain Murray"), GUN_ITEM_TYPE);

			LAi_SetActorType(characterFromID("Captain Murray"));
			characters[GetCharacterIndex("Captain Murray")].Dialog.Filename = "Captain Murray_dialog.c";
			LAi_ActorDialog(characterFromID("Captain Murray"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Captain Murray")].dialog.CurrentNode = "Not_going_to_make_it";
		break;

		case "Murray_slumps2":
			LAi_SetStunnedTypeNoGroup(characterFromID("Captain Murray"));
			Characters[GetCharacterIndex("Captain Murray")].dialog.CurrentNode = "Cough_cough";
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "See_Captain_Murray";

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Bury_Captain_Murray";
		break;

		case "Back_into_uniform":
			pchar.quest.All_dressed_down.win_condition.l1 = "location";
			Pchar.quest.All_dressed_down.win_condition.l1.character = Pchar.id;
			pchar.quest.All_dressed_down.win_condition.l1.location = "Guadeloupe_Plantation_inside";
			pchar.quest.All_dressed_down.win_condition = "All_dressed_down";
		break;

		case "All_dressed_down":
			ChangeCharacterAddress(characterFromID("Major Hogan"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Plantation_inside", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Guadeloupe_Plantation_inside", "goto", "goto2");

			pchar.quest.My_own_Uniform.win_condition.l1 = "location";
			Pchar.quest.My_own_Uniform.win_condition.l1.character = Pchar.id;
			pchar.quest.My_own_Uniform.win_condition.l1.location = "Guadeloupe_Plantation_bedroom";
			pchar.quest.My_own_Uniform.win_condition = "My_own_Uniform";
		break;

		case "My_own_Uniform":
			Locations[FindLocation("Guadeloupe_Plantation_inside")].reload.l1.disable = 0;
			GiveModel2Player("brtHComdr_18", true);
			Characters[GetCharacterIndex("Rifleman Cooper")].model = "Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].headmodel = "h_Rifleman95E3_18";
			Characters[GetCharacterIndex("Patrick Harper")].model = "Harper_Sergeant";
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Harper_Sergeant";

			ChangeCharacterAddress(characterFromID("Rifleman Norton"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Brown"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Fisher"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Baker"), "None", "");
			ChangeCharacterAddress(characterFromID("Major Dunnitt"), "None", "");

			pchar.quest.Official_again.win_condition.l1 = "location";
			Pchar.quest.Official_again.win_condition.l1.character = Pchar.id;
			pchar.quest.Official_again.win_condition.l1.location = "Guadeloupe_Plantation_inside";
			pchar.quest.Official_again.win_condition = "Official_again";
		break;

		case "Official_again":
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Plantation_inside", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Guadeloupe_Plantation_inside", "goto", "goto2");

			pchar.quest.Return_to_Sharpe_and_Bodies.win_condition.l1 = "location";
			Pchar.quest.Return_to_Sharpe_and_Bodies.win_condition.l1.character = Pchar.id;
			pchar.quest.Return_to_Sharpe_and_Bodies.win_condition.l1.location = "Guadeloupe_Plantation";
			pchar.quest.Return_to_Sharpe_and_Bodies.win_condition = "Return_to_Sharpe_and_Bodies";
		break;

		case "Return_to_Sharpe_and_Bodies":
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Guadeloupe_Plantation", "goto", "goto52");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Guadeloupe_Plantation", "goto", "goto60");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Guadeloupe_Plantation", "goto", "goto48");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Guadeloupe_Plantation", "goto", "goto58");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Perkins"), "Guadeloupe_Plantation", "goto", "goto53");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Guadeloupe_Plantation", "goto", "goto54");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Guadeloupe_Plantation", "goto", "goto18");

			LAi_SetGuardianType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Back_to_Hotspur_wounded";

			Characters[GetCharacterIndex("Rifleman Harris")].dialog.CurrentNode = "Murray_has_Passed";
		break;

		case "Back_into_more_trouble":
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			Lai_KillCharacter(characterFromID("Captain Murray"));
			LAi_SetActorType(characterFromID("Richard Sharpe"));

			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "First time";

			LAi_SetActorType(characterFromID("Rifleman Harris"));
			characters[GetCharacterIndex("Rifleman Harris")].Dialog.Filename = "Rifleman Harris_dialog.c";
			LAi_ActorDialog(characterFromID("Rifleman Harris"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Rifleman Harris")].dialog.CurrentNode = "Murray_has_Passed";
		break;

		case "Stay_Harris_Haggman":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Do_what_you_can";
		break;

		case "To_the_woods":
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Perkins"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));

			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "reload", "reload2", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "reload", "reload2", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Perkins"), "reload", "reload2", "",0.0);
			LAi_QuestDelay("To_the_woods2", 3.0);
		break;

		case "To_the_woods2":
			LAi_SetActorType(characterFromID("Rifleman Mansfield"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Patrick Harper"));

			LAi_ActorGoToLocator(characterFromID("Rifleman Mansfield"), "reload", "reload2", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "reload", "reload2", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "reload", "reload2", "",0.0);
			LAi_QuestDelay("To_the_woods3", 3.0);
		break;

		case "To_the_woods3":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Plan_to_get_home";
		break;

		case "Jungles_then_beach":
			LAi_SetImmortal(Pchar, false);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Perkins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Mansfield"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");

			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "Escaping_to_ship";
			Characters[GetCharacterIndex("Rifleman Cooper")].dialog.CurrentNode = "Escaping_to_ship";
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Escaping_to_ship";

			pchar.quest.Hogan_Signal_Tower.win_condition.l1 = "location";
			Pchar.quest.Hogan_Signal_Tower.win_condition.l1.character = Pchar.id;
			pchar.quest.Hogan_Signal_Tower.win_condition.l1.location = "Guadeloupe_Jungle_01";
			pchar.quest.Hogan_Signal_Tower.win_condition = "Hogan_Signal_Tower";
		break;

		case "Hogan_Signal_Tower":
			ChangeCharacterAddress(characterFromID("Captain Murray"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Harris"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");

			SetCharacterRemovable(characterFromID("Patrick Harper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Patrick Harper"));
			SetCharacterRemovable(characterFromID("Rifleman Cooper"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rifleman Cooper"));
			RemovePassenger(pchar, characterFromID("Rifleman Cooper"));

			LAi_QuestDelay("Hogan_Signal_TowerAAA", 0.0);
		break;

		case "Hogan_Signal_TowerAAA":
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Jungle_01", "goto", "goto1");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			LAi_QuestDelay("Hogan_Signal_Tower2", 3.0);
		break;

		case "Hogan_Signal_Tower2":
			LAi_SetActorType(characterFromID("Patrick Harper"));
			characters[GetCharacterIndex("Patrick Harper")].Dialog.Filename = "Patrick Harper_dialog.c";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "You_must_see_this";
		break;

		case "Follow_Harper_Signal_Tower":
			pchar.quest.Fight_the_French_Hogan.over = "yes";
			Characters[GetCharacterIndex("Patrick Harper")].dialog.CurrentNode = "Escaping_to_ship";

			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "reload", "reload3_back", "",0.0);

			pchar.quest.Near_Signal_Tower.win_condition.l1 = "location";
			Pchar.quest.Near_Signal_Tower.win_condition.l1.character = Pchar.id;
			pchar.quest.Near_Signal_Tower.win_condition.l1.location = "Guadeloupe_Jungle_02";
			pchar.quest.Near_Signal_Tower.win_condition = "Near_Signal_Tower";
		break;

		case "Near_Signal_Tower":
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Jungle_02", "goto", "goto1");

			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "reload", "reload2_back", "",0.0);

			pchar.quest.At_Signal_Tower.win_condition.l1 = "location";
			Pchar.quest.At_Signal_Tower.win_condition.l1.character = Pchar.id;
			pchar.quest.At_Signal_Tower.win_condition.l1.location = "Guadeloupe_Lighthouse";
			pchar.quest.At_Signal_Tower.win_condition = "At_Signal_Tower";
		break;

		case "At_Signal_Tower":
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Guadeloupe_Lighthouse", "goto", "goto29");

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Seen_this_before";
		break;

		case "Finally_go_home":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			ChangeCharacterAddressGroup(characterFromID("Pater Dominic"), "PaP_church", "barmen", "bar1"); // GR

			pchar.quest.Hogan_Quest_Done.win_condition.l1 = "location";
			Pchar.quest.Hogan_Quest_Done.win_condition.l1.character = Pchar.id;
			pchar.quest.Hogan_Quest_Done.win_condition.l1.location = "Guadeloupe_Jungle_01";
			pchar.quest.Hogan_Quest_Done.win_condition = "Hogan_Quest_Done";
		break;

		case "Hogan_Quest_Done":
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"RN_Volage","Hotspur",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Guadeloupe_shore_01");

			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Guadeloupe_shore_01", "goto", "locator10");

			pchar.quest.Hogan_Quest_Done_More.win_condition.l1 = "location";
			Pchar.quest.Hogan_Quest_Done_More.win_condition.l1.character = Pchar.id;
			pchar.quest.Hogan_Quest_Done_More.win_condition.l1.location = "Guadeloupe_shore_01";
			pchar.quest.Hogan_Quest_Done_More.win_condition = "Hogan_Quest_Done_More";
		break;

		case "Hogan_Quest_Done_More":
			DisableFastTravel(false);
			Locations[FindLocation("Guadeloupe_shore_01")].reload.l2.disable = 0; // Grey Roger: unlock boat
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. William Bush"));
			SetCharacterRemovable(characterFromID("Lt. William Bush"), false);

			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Thank_God_you're_back";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), pchar, "", 10.0, 10.0);
			Locations[FindLocation("Guadeloupe_Plantation")].vcskip = false;
			Locations[FindLocation("Guadeloupe_Jungle_03")].vcskip = false;
			Locations[FindLocation("Guadeloupe_Jungle_02")].vcskip = false;
			Locations[FindLocation("Guadeloupe_Jungle_01")].vcskip = false;
		break;

		case "Pellew_at_Greenford_Two":
			AddQuestRecord("Old Friends - New Enemies", 11);
			ChangeCharacterAddressGroup(characterFromID("Jack Hammond"), "Greenford_port", "goto", "goto13");

			Pchar.quest.Report_on_Invasion.win_condition.l1 = "location";
			PChar.quest.Report_on_Invasion.win_condition.l1.character = Pchar.id;
			Pchar.quest.Report_on_Invasion.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Report_on_Invasion.win_condition = "Report_on_Invasion";
		break;

		case "Report_on_Invasion":
			SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_ENEMY);
			SetRMRelation(PChar, FRANCE, REL_WAR);
			SetRMRelation(PChar, SPAIN, REL_WAR);

			LAi_SetOfficerType(characterFromID("Jack Hammond"));

			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Greenford_port", "reload", "reload1_back");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_dialog.c";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Richard Sharpe")].dialog.CurrentNode = "Back_to_barracks";
		break;

		case "Signal_from_flagship":
			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemovePassenger(pchar, characterFromID("Richard Sharpe"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Patrick Harper"));
			RemovePassenger(pchar, characterFromID("Patrick Harper"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rifleman Tongue"));
			RemovePassenger(pchar, characterFromID("Rifleman Tongue"));

			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialog(characterFromID("Jack Hammond"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "Signal_from_flagship";
		break;

		case "meeting_on_flagship":
			LAi_ActorGoToLocator(characterFromID("Jack Hammond"), "goto", "goto13", "",0.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].model = "PellewA_18";
			Characters[GetCharacterIndex("Sir Edward Pellew")].headmodel = "h_PellewA_18";
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Cabin2SJG", "officers", "officer1");
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "Cabin2SJG", "rld", "aloc6");

			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Not_more_whist";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), pchar, "", 10.0, 10.0);
		break;

		case "Pellew_Hammond_Plan":
			SetCharacterRemovable(characterFromID("Lt. William Bush"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. William Bush"));

			DoQuestReloadToLocation("Cabin2SJG", "reload", "reload1", "Pellew_Hammond_Plan2");
		break;

		case "Pellew_Hammond_Plan2":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "rld", "loc6", "Pellew_Hammond_Plan3", 10);
		break;

		case "Pellew_Hammond_Plan3":
			LAi_SetPlayerType(PChar);

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "I_have_read_your_report";
		break;

		case "Hammond_chips_in":
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Put_Down";
		break;

		case "Pellew_buts_in":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Indeed_continue";
		break;

		case "Hammond_gets_gritty":
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "I_must_insist";
		break;

		case "Pellew_puts_down":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Hammond_Hornblower_Plan";
		break;

		case "Jack_goes_too":
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Include_Jack";
		break;

		case "Hammond_dismissed":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Hogan_and_Spies";
		break;

		case "Shut_the_Door":
			LAi_ActorGoToLocation(characterFromID("Black Charlie Hammond"), "reload", "reload1", "none", "", "", "Shut_the_Door2",0.0);
		break;

		case "Shut_the_Door2":
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Spies_somewhere";
		break;

		case "Maria_in_Jail":
			ChangeCharacterAddress(characterFromID("Jack Hammond"), "None", "");
			Locations[FindLocation("Greenford_town")].reload.l20.disable = 1;
			DoQuestReloadToLocation("Greenford_port", "reload", "reload1", "Go_to_Find_Maria");
		break;

		case "Go_to_Find_Maria":
			AddQuestRecord("Old Friends - New Enemies", 12);
			ChangeCharacterAddressGroup(characterFromID("Bernard Gosling"), "Greenford_town", "reload", "reload21");
			LAi_SetGuardianType(characterFromID("Bernard Gosling"));

			Pchar.quest.Go_to_Find_Maria2.win_condition.l1 = "location";
			PChar.quest.Go_to_Find_Maria2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Go_to_Find_Maria2.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Go_to_Find_Maria2.win_condition = "Go_to_Find_Maria2";
		break;

		case "Go_to_Find_Maria2":
			LAi_SetGuardianType(characterFromID("Bernard Gosling"));
			characters[GetCharacterIndex("Bernard Gosling")].Dialog.Filename = "RN_Sailor_dialog.c";
			LAi_ActorDialog(characterFromID("Bernard Gosling"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Bernard Gosling")].dialog.CurrentNode = "Nail_up_house";
		break;

		case "Maria_at_Greenford_Prison":
			AddQuestRecord("Old Friends - New Enemies", 13);
			LAi_type_actor_Reset(characterFromID("Maria Mason"));
			LAi_type_actor_Reset(characterFromID("Mrs. Mason"));
			Locations[FindLocation("Greenford_prison")].vcskip = true;
			LAi_SetActorType(characterFromID("Bernard Gosling"));
			LAi_ActorGoToLocator(characterFromID("Bernard Gosling"), "goto", "goto34", "",0.0);
			ChangeCharacterAddressGroup(characterFromID("Maria Mason"), "Greenford_prison", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Mrs. Mason"), "Greenford_prison", "goto", "goto24");
			ChangeCharacterAddressGroup(characterFromID("Mine_soldier_03"), "Greenford_prison", "merchant", "reload13");
			Characters[GetCharacterIndex("Mine_soldier_03")].dialog.CurrentNode = "Debtors_Prison_soldier";

			Pchar.quest.Maria_in_cell.win_condition.l1 = "location";
			PChar.quest.Maria_in_cell.win_condition.l1.character = Pchar.id;
			Pchar.quest.Maria_in_cell.win_condition.l1.location = "Greenford_prison";
			Pchar.quest.Maria_in_cell.win_condition = "Maria_in_cell";
		break;

		case "Maria_in_cell":
			LAi_SetCitizenType(characterFromID("Bernard Gosling"));
			characters[GetCharacterIndex("Bernard Gosling")].Dialog.Filename = "Greenford Citizen_dialog.c";
			Characters[GetCharacterIndex("Bernard Gosling")].dialog.CurrentNode = "First time";

			characters[GetCharacterIndex("Mine_soldier_03")].Dialog.Filename = "RN_Sailor_dialog.c";
			LAi_ActorDialog(characterFromID("Mine_soldier_03"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Mine_soldier_03")].dialog.CurrentNode = "Debtors_Prison_soldier";

			characters[GetCharacterIndex("Greenford Prison Commendant")].Dialog.Filename = "RN_Sailor_dialog.c";
			LAi_ActorDialog(characterFromID("Greenford Prison Commendant"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Greenford Prison Commendant")].dialog.CurrentNode = "Debtors_Prison";
		break;

		case "Maria_debts_paid":
			ChangeCharacterAddress(characterFromID("Mine_soldier_03"), "None", "");
			characters[GetCharacterIndex("Mine_soldier_03")].Dialog.Filename = "Mine soldier_dialog.c";
			characters[GetCharacterIndex("Greenford Prison Commendant")].Dialog.Filename = "Greenford Commander_dialog.c";
			Characters[GetCharacterIndex("Greenford Prison Commendant")].dialog.CurrentNode = "First time";
			AddMoneyToCharacter(Pchar, -60);
			PlayStereoSound("INTERFACE\took_item.wav");
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "Come_to_gloat";

			pchar.quest.Mason_in_jail_speak.win_condition.l1 = "locator";
			pchar.quest.Mason_in_jail_speak.win_condition.l1.location = "Greenford_prison";
			pchar.quest.Mason_in_jail_speak.win_condition.l1.locator_group = "reload";
			pchar.quest.Mason_in_jail_speak.win_condition.l1.locator = "reload12";
			pchar.quest.Mason_in_jail_speak.win_condition = "Mason_in_jail_speak";
		break;

		case "Mason_in_jail_speak":
			DisableFastTravel(true);

			LAi_SetActorType(characterFromID("Mrs. Mason"));
			characters[GetCharacterIndex("Mrs. Mason")].Dialog.Filename = "Mrs. Mason_dialog.c";
			LAi_ActorDialogNow(characterFromID("Mrs. Mason"),PChar,"",2.0);
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "Come_to_gloat";
		break;

		case "Maria_behind_bars":
			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Maria Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "Got_us_out";
			ChangeCharacterAddressGroup(characterFromID("Bernard Gosling"), "Greenford_town", "goto", "goto5");
		break;

		case "Bush_Wolfe_Battle":
			AddCharacterGoods(pchar, GOOD_RUM, 44);
			AddCharacterGoods(pchar, GOOD_WHEAT, 86);
			LAi_type_actor_Reset(characterFromID("Lt. William Bush"));
			LAi_type_actor_Reset(characterFromID("Thomas Wolfe"));
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Greenford_town", "goto", "goto23");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Greenford_town", "goto", "goto54");
			LAi_QuestDelay("Bush_Wolfe_Battle2", 1.0);
		break;

		case "Bush_Wolfe_Battle2":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Wolfe_is_back_sir";
		break;

		case "Sail_to_blow_Semaphore":
			AddQuestRecord("Old Friends - New Enemies", 14);
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");
			Locations[FindLocation("Greenford_prison")].vcskip = false;

			Pchar.quest.Hammond_and_Quelp.win_condition.l1 = "location";
			PChar.quest.Hammond_and_Quelp.win_condition.l1.character = Pchar.id;
			Pchar.quest.Hammond_and_Quelp.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Hammond_and_Quelp.win_condition = "Hammond_and_Quelp";
		break;

		case "Hammond_and_Quelp":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Greenford_port", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Greenford_port", "goto", "goto21");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Greenford_port", "officers", "reload1_3");
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "Greenford_port", "officers", "reload1_2");
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Maybe_share_a_boat";

			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "officers", "reload4_3", "Hammond_and_Quelp2", 10);
		break;

		case "Hammond_and_Quelp2":
			LAi_SetPlayerType(PChar);

			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. William Bush"),PChar,"",2.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Maybe_share_a_boat";
		break;

		case "Missed_them_Hammond_Quelp":
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "First time";
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			LAi_QuestDelay("Next_for_Deck_Scene", 4.0);
		break;

		case "Next_for_Deck_Scene":
			DisableFastTravel(false);
			ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			ChangeCharacterAddress(characterFromID("Black Charlie Hammond"), "None", "");

			pchar.quest.Guadeloupe_shore_party.win_condition.l1 = "location";
			pchar.quest.Guadeloupe_shore_party.win_condition.l1.location = "Guadeloupe";
			pchar.quest.Guadeloupe_shore_party.win_condition = "Guadeloupe_shore_party";
		break;

		case "Guadeloupe_shore_party":
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Quest_ShipDeck1", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Quest_ShipDeck1", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "Quest_ShipDeck1", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Quest_ShipDeck1", "reload", "reload3");
			ChangeCharacterAddressGroup(characterFromID("Lt. Chadd"), "Quest_ShipDeck1", "rld", "startloc");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Quest_ShipDeck1", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Quest_ShipDeck1", "goto", "goto10");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Quest_ShipDeck1", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Jack Hammond"), "Quest_ShipDeck1", "rld", "loc2");
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			LAi_SetActorType(characterFromID("Jack Hammond"));
			LAi_SetActorType(characterFromID("Matthews"));
			LAi_ActorTurnToCharacter(characterFromID("Matthews"), (Pchar));

			DoReloadFromSeaToLocation("Quest_ShipDeck1", "goto", "goto7");
			LAi_QuestDelay("Guadeloupe_shore_party2", 0.0);
		break;

		case "Guadeloupe_shore_party2":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "reload", "boatl");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG2B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "reload", "boatr");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG3B";
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "rld", "loc3", "Guadeloupe_shore_party3", 10);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "Landing_party";
		break;

		case "Guadeloupe_shore_party3":
			LAi_SetPlayerType(PChar);

			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialogNow(characterFromID("Matthews"),PChar,"",2.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "Landing_party";

			Characters[GetCharacterIndex("Thomas Wolfe")].dialog.CurrentNode = "I'll_volunteer";
		break;

		case "Wolfe_volunteers":
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			characters[GetCharacterIndex("Thomas Wolfe")].Dialog.Filename = "Thomas Wolfe_dialog.c";
			LAi_ActorDialogNow(characterFromID("Thomas Wolfe"),PChar,"",2.0);
			Characters[GetCharacterIndex("Thomas Wolfe")].dialog.CurrentNode = "I'll_volunteer";

			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "Reporting_sir";
		break;

		case "Hammond_volunteers":
			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Jack Hammond"),PChar,"",2.0);
			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "Reporting_sir";
		break;

		case "The_first_landing":
			LAi_Fade("", "");
			setCharacterShipLocation(Pchar, "Guadeloupe_shore_01");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Guadeloupe_shore_01", "goto", "citizen02");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Guadeloupe_shore_01", "goto", "locator10");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "Guadeloupe_shore_01", "goto", "locator14");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Guadeloupe_shore_01", "goto", "citizen04");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Guadeloupe_shore_01", "goto", "seaman2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Guadeloupe_shore_01", "goto", "seaman1");
			ChangeCharacterAddressGroup(characterFromID("Jack Hammond"), "Guadeloupe_shore_01", "goto", "citizen03");

			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "We_will_wait_here";

			DoQuestReloadToLocation("Guadeloupe_shore_01", "goto", "locator11", "To_the_shore_Demolition");
			Locations[FindLocation("Guadeloupe_shore_01")].reload.l2.disable = 1; // Grey Roger: lock the boat
		break;

		case "To_the_shore_Demolition":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "citizen07");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "citizen01");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG2B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "citizen05");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG3B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "citizen06");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG4B";

			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialogNow(characterFromID("Matthews"),PChar,"",2.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "We_will_wait_here";
		break;

		case "Lead_off":
			LAi_SetOfficerType(characterFromID("Thomas Wolfe"));
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Styles"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Jack Hammond"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Able Seaman Wilks"));
			SetCharacterRemovable(characterFromID("Styles"), false);
			SetCharacterRemovable(characterFromID("Jack Hammond"), false);
			SetCharacterRemovable(characterFromID("Able Seaman Wilks"), false);
			LAi_SetOfficerType(characterFromID("Able Seaman Stanley"));
			LAi_SetOfficerType(characterFromID("Able Seaman Tompkins"));

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "It's_very_quiet";
			Locations[FindLocation("Guadeloupe_Jungle_03")].vcskip = true;

			pchar.quest.Lighthouse_step_one.win_condition.l1 = "location";
			Pchar.quest.Lighthouse_step_one.win_condition.l1.character = Pchar.id;
			pchar.quest.Lighthouse_step_one.win_condition.l1.location = "Guadeloupe_Jungle_03";
			pchar.quest.Lighthouse_step_one.win_condition = "Lighthouse_step_one";
		break;

		case "Lighthouse_step_one":
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Guadeloupe_Jungle_03", "goto", "goto14");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Guadeloupe_Jungle_03", "reload", "reload3_back");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Guadeloupe_Jungle_03", "reload", "reload3_back");

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "It's_very_quiet";
		break;

		case "Lighthouse_step_two":
			LAi_SetOfficerType(characterFromID("Styles"));
			Locations[FindLocation("Guadeloupe_Jungle_02")].vcskip = true;
			Locations[FindLocation("Guadeloupe_Jungle_01")].vcskip = true;
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Which_way_now";

			pchar.quest.Lighthouse_step_three.win_condition.l1 = "location";
			Pchar.quest.Lighthouse_step_three.win_condition.l1.character = Pchar.id;
			pchar.quest.Lighthouse_step_three.win_condition.l1.location = "Guadeloupe_Jungle_01";
			pchar.quest.Lighthouse_step_three.win_condition = "Lighthouse_step_three";
		break;

		case "Lighthouse_step_three":
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Guadeloupe_Jungle_01", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Guadeloupe_Jungle_01", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Guadeloupe_Jungle_01", "reload", "reload1_back");

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Which_way_now";
		break;

		case "Lighthouse_step_four":
			LAi_SetOfficerType(characterFromID("Styles"));
//TRAP
			pchar.quest.Two_French_Soldiers.win_condition.l1 = "locator";
			pchar.quest.Two_French_Soldiers.win_condition.l1.location = "Guadeloupe_Jungle_01";
			pchar.quest.Two_French_Soldiers.win_condition.l1.locator_group = "goto";
			pchar.quest.Two_French_Soldiers.win_condition.l1.locator = "goto1";
			pchar.quest.Two_French_Soldiers.win_condition = "Two_French_Soldiers";

			pchar.quest.Two_French_SoldiersA.win_condition.l1 = "locator";
			pchar.quest.Two_French_SoldiersA.win_condition.l1.location = "Guadeloupe_Jungle_01";
			pchar.quest.Two_French_SoldiersA.win_condition.l1.locator_group = "goto";
			pchar.quest.Two_French_SoldiersA.win_condition.l1.locator = "citizen02";
			pchar.quest.Two_French_SoldiersA.win_condition = "Two_French_Soldiers";

			pchar.quest.Lighthouse_step_five.win_condition.l1 = "location";
			Pchar.quest.Lighthouse_step_five.win_condition.l1.character = Pchar.id;
			pchar.quest.Lighthouse_step_five.win_condition.l1.location = "Guadeloupe_Jungle_02";
			pchar.quest.Lighthouse_step_five.win_condition = "Lighthouse_step_five";
		break;

		case "Two_French_Soldiers":
			Pchar.Quest.Lighthouse_step_five.over = "yes";
			Pchar.Quest.Two_French_Soldiers.over = "yes";
			Pchar.Quest.Two_French_SoldiersA.over = "yes";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "citizen05");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "citizen06");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			LAi_group_MoveCharacter(characterFromID("Soldier1X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier1X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), "FRANCE_SOLDIERS");
			LAi_QuestDelay("Two_French_Soldiers2", 2.0);
		break;

		case "Two_French_Soldiers2":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Two_French_Soldiers3");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Two_French_Soldiers3":
			Pchar.Quest.KilledFighting.over = "yes";
			pchar.quest.Lighthouse_step_five.win_condition.l1 = "location";
			Pchar.quest.Lighthouse_step_five.win_condition.l1.character = Pchar.id;
			pchar.quest.Lighthouse_step_five.win_condition.l1.location = "Guadeloupe_Jungle_02";
			pchar.quest.Lighthouse_step_five.win_condition = "Lighthouse_step_five";
		break;
//END TRAP
		case "Lighthouse_step_five":
			Pchar.Quest.Two_French_Soldiers.over = "yes";
			Pchar.Quest.Two_French_SoldiersA.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Guadeloupe_Jungle_02", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Guadeloupe_Jungle_02", "reload", "reload1_back");
			//ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");
			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "Semaphore_operator";
//TRAP
			pchar.quest.Three_French_Soldiers.win_condition.l1 = "locator";
			pchar.quest.Three_French_Soldiers.win_condition.l1.location = "Guadeloupe_Jungle_02";
			pchar.quest.Three_French_Soldiers.win_condition.l1.locator_group = "goto";
			pchar.quest.Three_French_Soldiers.win_condition.l1.locator = "goto7";
			pchar.quest.Three_French_Soldiers.win_condition = "Three_French_Soldiers";

			pchar.quest.Lighthouse_step_six.win_condition.l1 = "location";
			Pchar.quest.Lighthouse_step_six.win_condition.l1.character = Pchar.id;
			pchar.quest.Lighthouse_step_six.win_condition.l1.location = "Guadeloupe_Lighthouse";
			pchar.quest.Lighthouse_step_six.win_condition = "Lighthouse_step_six";
		break;

		case "Three_French_Soldiers":
			Pchar.Quest.Lighthouse_step_six.over = "yes";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto4");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";
			LAi_group_MoveCharacter(characterFromID("Soldier1X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier1X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier3X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier3X"), "FRANCE_SOLDIERS");
			LAi_QuestDelay("Three_French_Soldiers2", 2.0);
		break;

		case "Three_French_Soldiers2":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Three_French_Soldiers3");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Three_French_Soldiers3":
			Pchar.Quest.KilledFighting.over = "yes";
			pchar.quest.Lighthouse_step_five.win_condition.l1 = "location";
			Pchar.quest.Lighthouse_step_five.win_condition.l1.character = Pchar.id;
			pchar.quest.Lighthouse_step_five.win_condition.l1.location = "Guadeloupe_Lighthouse";
			pchar.quest.Lighthouse_step_five.win_condition = "Lighthouse_step_six";
		break;
//END TRAP
		case "Lighthouse_step_six":
			Pchar.Quest.Three_French_Soldiers.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Guadeloupe_Lighthouse", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Guadeloupe_Lighthouse", "reload", "reload1_back");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "reload2_3");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Jack Hammond"),PChar,"",2.0);
		break;

		case "What_a_knockout":
			LAi_SetOfficerType(characterFromID("Jack Hammond"));
			LAi_SetActorType(characterFromID("Styles"));
			LAi_ActorRunToLocator(characterFromID("Styles"), "goto", "goto24", "Deal_with_him2",0.0);
		break;

		case "Deal_with_him2":
			LAi_SetHP(characterFromID("Soldier1X"), 20.0, 20.0);
			LAi_SetHP(characterFromID("Styles"), 80.0, 80.0);
			LAi_SetActorType(CharacterFromID("Soldier1X"));
			LAi_SetActorType(CharacterFromID("Styles"));
			LAi_group_MoveCharacter(CharacterFromID("Soldier1X"), "Soldier1X");
			LAi_group_MoveCharacter(CharacterFromID("Styles"), "Styles");
			LAi_SetImmortal(CharacterFromID("Styles"), true);
			LAi_ActorAttack(characterFromID("Styles"), characterFromID("Soldier1X"), "");
			LAi_ActorAttack(characterFromID("Soldier1X"), characterFromID("Styles"), "");

			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "We_need_to_be_quick";

			PChar.quest.Job_done_Sir.win_condition.l1 = "NPC_Death";
			PChar.quest.Job_done_Sir.win_condition.l1.character = "Soldier1X";
			PChar.quest.Job_done_Sir.win_condition = "Job_done_Sir";
		break;

		case "Job_done_Sir":
			LAi_QuestDelay("Job_done_Sir2", 2.0);
		break;

		case "Job_done_Sir2":
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Wolfe_not_here";

			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Jack Hammond"),PChar,"",2.0);
		break;

		case "Who_has_the_fuses":
// ACTORS RUN
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			LAi_ActorGoToLocation(characterFromID("Able Seaman Tompkins"), "reload", "reload5", "none", "", "", "",0.0);
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));
			LAi_ActorGoToLocation(characterFromID("Able Seaman Stanley"), "reload", "reload5", "none", "", "", "",0.0);
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));
			LAi_ActorGoToLocation(characterFromID("Able Seaman Wilks"), "reload", "reload5", "none", "", "", "",0.0);
			LAi_ActorGoToLocation(characterFromID("Styles"), "reload", "reload5", "none", "", "", "",0.0);
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto24", "", 0.0);
			LAi_QuestDelay("Who_has_the_fuses2", 15.0);
		break;

		case "Who_has_the_fuses2":
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Guadeloupe_Lighthouse", "reload", "reload5");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Guadeloupe_Lighthouse", "reload", "reload5");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "Guadeloupe_Lighthouse", "reload", "reload5");
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Guadeloupe_Lighthouse", "reload", "reload5");
			LAi_QuestDelay("Who_has_the_fuses2A", 0.0);
		break;

		case "Who_has_the_fuses2A":
			LAi_SetOfficerType(CharacterFromID("Styles"));
			LAi_SetOfficerType(CharacterFromID("Jack Hammond"));
			LAi_SetOfficerType(CharacterFromID("Able Seaman Stanley"));
			LAi_SetOfficerType(CharacterFromID("Able Seaman Wilks"));
			LAi_SetOfficerType(CharacterFromID("Able Seaman Tompkins"));
			LAi_QuestDelay("Who_has_the_fuses3", 4.0);
		break;

		case "Who_has_the_fuses3":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "It_will_take_too_long";

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Wolfe_not_here";
		break;

		case "Where_is_Wolfe":
//		styles run off
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			LAi_ActorRunToLocator(characterFromID("Able Seaman Tompkins"), "officers", "reload3_3", "",0.0);
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));
			LAi_ActorRunToLocator(characterFromID("Able Seaman Stanley"), "officers", "reload3_3", "",0.0);
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));
			LAi_ActorRunToLocator(characterFromID("Able Seaman Wilks"), "officers", "reload3_3", "",0.0);

			LAi_ActorGoToLocation(characterFromID("Styles"), "reload", "reload5", "none", "", "", "Hammond_cries",0.0);
//			LAi_ActorGoToLocator(characterFromID("Styles"), "reload", "reload5", "",0.0);
		break;

		case "Hammond_cries":
			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Jack Hammond"),PChar,"",2.0);
			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "It_will_take_too_long";
		break;

		case "Send_Hammond_back":
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Guadeloupe_Lighthouse", "reload", "reload5");
			LAi_ActorRunToLocator(characterFromID("Jack Hammond"), "goto", "goto18", "",0.0);
			LAi_SetOfficerType(CharacterFromID("Styles"));

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "How_far_fuse";

			LAi_QuestDelay("Send_Hammond_back2", 4.0);
		break;

		case "Send_Hammond_back2":

			LAi_QuestDelay("Send_Hammond_back2A", 0.0);
		break;

		case "Send_Hammond_back2A":
			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
//			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "How_far_fuse";
		break;

		case "Move_to_detonate":
			ChangeCharacterAddress(characterFromID("Jack Hammond"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Tompkins"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Stanley"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Wilks"), "None", "");

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "This_is_it";

			LAi_SetOfficerType(characterFromID("Styles"));
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "officers", "reload4_3", "This_will_do", 40);
		break;

		case "This_will_do":
			LAi_SetPlayerType(PChar);

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Lighthouse_Bangs_Now":
			CreateParticleSystemX("blast_inv", 1.7085, 16.89, -10.585, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 1.7085, 16.89, -10.585, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 1.7085, 16.89, -10.585, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire1", "", -1, 1.7085, 16.89, -10.585, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 8.0; 
			CreateParticleSystemX("fireball", 1.7085, 16.89, -10.585, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("Lighthouse_Bangs_Now2", 0.0);
		break;

		case "Lighthouse_Bangs_Now2":
			CreateParticleSystemX("blast_inv", 2.1397, 16.89, -10.585, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 2.1397, 16.89, -10.585, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 2.1397, 16.89, -10.585, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire1", "", -1, 2.1397, 16.89, -10.585, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 9.0; 
			CreateParticleSystemX("fireball", 2.1397, 16.89, -10.585, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("Lighthouse_Bangs_Now3", 0.0);
		break;

		case "Lighthouse_Bangs_Now3":
			CreateParticleSystemX("blast_inv", 11.049, 16.864, -4.8695, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 11.049, 16.864, -4.8695, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 11.049, 16.864, -4.8695, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire1", "", -1, 11.049, 16.864, -4.8695, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 10.0; 
			CreateParticleSystemX("fireball", 11.049, 16.864, -4.8695, -1.57, 0.0, 0.0,0);
			LAi_QuestDelay("Lighthouse_Bangs_Now4", 0.0);
		break;

		case "Lighthouse_Bangs_Now4":
			CreateParticleSystemX("blast_inv", 6.0759, 16.869, -8.4767, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 6.0759, 16.869, -8.4767, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 6.0759, 16.869, -8.4767, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			WriteLocatorGlobal("Prison_Shore", "fire", "fire1", "", -1, 6.0759, 16.869, -8.4767, false);
			Locations[FindLocation("Prison_Shore")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Prison_Shore")].locators_radius.fire = 10.0; 
			CreateParticleSystemX("fireball", 6.0759, 16.869, -8.4767, -1.57, 0.0, 0.0,0);

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "That_should_do_it";
			LAi_QuestDelay("Lighthouse_Bangs_Now5", 6.0);
		break;

		case "Lighthouse_Bangs_Now5":
			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Hammond_the_wimp":
			SetModelfromArray(PChar, GetModelIndex("Wellard_18"));
			PChar.name = "Jack";
			PChar.lastname = "Hammond";
			
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Guadeloupe_shore_01", "goto", "seaman2"); //"citizen04");
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "Were's_Captain_Hornblower";
			DoQuestReloadToLocation("Guadeloupe_shore_01", "officers", "locator3_3", "Hammond_the_wimp_two");
		break;

		case "Hammond_the_wimp_two":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto10");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto11");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG2B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "locator13");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG3B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto07");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG4B";

			LAi_SetActorType(characterFromID("soldierG1B"));
			LAi_SetActorType(characterFromID("soldierG2B"));
			LAi_SetActorType(characterFromID("soldierG3B"));
			LAi_SetActorType(characterFromID("soldierG4B"));

			LAi_ActorTurnToCharacter(characterFromID("soldierG1B"), characterFromID("Matthews"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG2B"), characterFromID("Matthews"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG3B"), characterFromID("Matthews"));
			LAi_ActorTurnToCharacter(characterFromID("soldierG4B"), characterFromID("Matthews"));
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "goto", "locator14", "Hammond_the_wimp_twoA", 5);
		break;

		case "Hammond_the_wimp_twoA":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Matthews"));
			characters[GetCharacterIndex("Matthews")].Dialog.Filename = "Matthews_dialog.c";
			LAi_ActorDialogNow(characterFromID("Matthews"),PChar,"",2.0);
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "Were's_Captain_Hornblower";
		break;

		case "Hammond_the_wimp_three":
			LAi_Fade("","");
			SetCharacterRemovable(characterFromID("Jack Hammond"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Jack Hammond"));
			ChangeCharacterAddress(characterFromID("Lt. Chadd"), "None", "");
			ChangeCharacterAddress(characterFromID("Matthews"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. William Bush"), "None", "");
			LAi_QuestDelay("Hammond_the_wimp_threeXXX", 1.0);
		break;

		case "Hammond_the_wimp_threeXXX":
			SetModelfromArray(PChar, GetModelIndex("BushLtn_18"));
			PChar.name = "Lt. William";
			PChar.lastname = "Bush";

			ChangeCharacterAddressGroup(characterFromID("Jack Hammond"), "Quest_ShipDeck1", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Quest_ShipDeck1", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Lt. Chadd"), "Quest_ShipDeck1", "rld", "startloc");
			ChangeCharacterAddressGroup(characterFromID("Helmsman"), "Quest_ShipDeck1", "goto", "goto14");

			LAi_SetActorType(characterFromID("Jack Hammond"));
			LAi_SetOfficerType(characterFromID("Lt.Chadd"));

			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "He_told_us_to_go";
			DoQuestReloadToLocation("Quest_ShipDeck1", "goto", "goto7", "Hammond_the_wimp_four");
		break;

		case "Hammond_the_wimp_four":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto2");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto1");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG2B";
			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Jack Hammond"),PChar,"",2.0);
			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "He_told_us_to_go";
			
			Characters[GetCharacterIndex("Lt. Chadd")].dialog.CurrentNode = "Your_orders_Sir";

			SetCharacterRemovable(characterFromID("Styles"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Styles"));
			SetCharacterRemovable(characterFromID("Able Seaman Wilks"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Able Seaman Wilks"));
			ChangeCharacterAddress(characterFromID("Able Seaman Tompkins"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Stanley"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Wilks"), "None", "");
		break;

		case "Chadd_wants_orders":
			LAi_ActorGoToLocator(characterFromID("Matthews"), "goto", "goto3", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Jack Hammond"), "goto", "goto9", "",0.0);
			LAi_SetActorType(characterFromID("Lt. Chadd"));
			characters[GetCharacterIndex("Lt. Chadd")].Dialog.Filename = "Lt. Chadd_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. Chadd"),PChar,"",2.0);
		break;

		case "Hornblower_taken":
			SetModelfromArray(PChar, GetModelIndex("brtHComdr_18"));
			PChar.name = "Horatio";
			PChar.lastname = "Hornblower";

//			GiveModel2Player("brtHComdr_18", true);
			pchar.quest.story_path = "neutral";
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"RN_Volage","Hotspur",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Greenford_port");

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Almost there";
			DoQuestReloadToLocation("Guadeloupe_Jungle_03", "officers", "reload3_2", "Captured_by_Wolfe");
		break;

		case "Captured_by_Wolfe":
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Guadeloupe_Jungle_03", "officers", "reload3_1");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Guadeloupe_Jungle_03", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Guadeloupe_Jungle_03", "reload", "reload3_3");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "Guadeloupe_Jungle_03", "goto", "goto14");

			SetModelfromArray(characterFromID("Thomas Wolfe"), GetModelIndex("WolfFrench"));
			Characters[GetCharacterIndex("Thomas Wolfe")].headmodel = "h_WolfFrench";

			LAi_SetOfficerType(characterFromID("Styles"));
			LAi_SetOfficerType(characterFromID("Able Seaman Tompkins"));
			LAi_SetOfficerType(characterFromID("Able Seaman Stanley"));
			LAi_SetOfficerType(characterFromID("Able Seaman Wilks"));

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Captured_by_Wolfe2":
			pchar.quest.Captured_by_Wolfe_three.win_condition.l1 = "location";
			Pchar.quest.Captured_by_Wolfe_three.win_condition.l1.character = Pchar.id;
			pchar.quest.Captured_by_Wolfe_three.win_condition.l1.location = "Guadeloupe_shore_01";
			pchar.quest.Captured_by_Wolfe_three.win_condition = "Captured_by_Wolfe_three";
		break;

		case "Captured_by_Wolfe_three":
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Guadeloupe_shore_01", "goto", "citizen04");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Guadeloupe_shore_01", "officers", "locator3_1");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Guadeloupe_shore_01", "officers", "locator3_2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "Guadeloupe_shore_01", "officers", "locator3_3");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Guadeloupe_shore_01", "goto", "locator12");

			LAi_SetActorType(characterFromID("Thomas Wolfe"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "citizen03");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "citizen03");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "citizen03");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "citizen03");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "citizen03");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "citizen03");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier6X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "citizen03");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier7X";

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Where_marines";
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "goto", "locator13", "Captured_by_Wolfe_four", 40);
		break;

		case "Captured_by_Wolfe_four":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Captured_by_Wolfe_five":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter((Pchar), characterFromID("soldier1X"));

			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));
			LAi_SetActorType(characterFromID("soldier4X"));
			LAi_SetActorType(characterFromID("soldier5X"));
			LAi_SetActorType(characterFromID("soldier6X"));
			LAi_SetActorType(characterFromID("soldier7X"));
			LAi_SetActorType(characterFromID("Thomas Wolfe"));

			LAi_ActorRunToLocator(characterFromID("soldier2X"), "goto", "goto02", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier3X"), "goto", "goto03", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier4X"), "goto", "goto04", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier5X"), "goto", "goto05", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier6X"), "goto", "goto06", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier7X"), "goto", "goto08", "", 40);

			Characters[GetCharacterIndex("Thomas Wolfe")].dialog.CurrentNode = "Gotcha";
			LAi_ActorGoToLocator(characterFromID("Thomas Wolfe"), "goto", "goto01", "Captured_by_Wolfe_six", 40);
		break;

		case "Captured_by_Wolfe_six":
			LAi_ActorTurnToCharacter(characterFromID("soldier2X"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldier3X"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldier4X"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldier5X"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldier6X"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldier7X"), Pchar);

			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			characters[GetCharacterIndex("Thomas Wolfe")].Dialog.Filename = "Thomas Wolfe_dialog.c";
			LAi_ActorDialogNow(characterFromID("Thomas Wolfe"),PChar,"",2.0);
		break;

		case "Bush_sees_Pellew":
			Lai_Fade("Bush_sees_PellewA", "Bush_sees_PellewB");
		break;

		case "Bush_sees_PellewA":
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Cabin2SJG", "officers", "officer1");
		break;

		case "Bush_sees_PellewB":
			ChangeCharacterAddress(characterFromID("Soldier1X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier2X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier3X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier4X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier5X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier6X"), "None", "");
			ChangeCharacterAddress(characterFromID("Soldier7X"), "None", "");
			SetModelfromArray(PChar, GetModelIndex("BushLtn_18"));
			PChar.name = "Lt. William";
			PChar.lastname = "Bush";

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			DoQuestReloadToLocation("Cabin2SJG", "reload", "reload1", "Bush_sees_Pellew2");
		break;

		case "Bush_sees_Pellew2":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "rld", "loc6", "Bush_sees_Pellew3", 10);
		break;

		case "Bush_sees_Pellew3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));

			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Can_we_Help_Hornblower";
		break;

		case "Crew_Wolfe_Prison":
			SetModelfromArray(PChar, GetModelIndex("brtHComdr_18"));
			PChar.name = "Horatio";
			PChar.lastname = "Hornblower";
			Locations[FindLocation("PaP_Guardhouse")].reload.l1.disable = 1;
			Locations[FindLocation("PaP_Guardhouse")].reload.l2.disable = 1;
			LAi_ActorSetSitMode(characterFromID("Able Seaman Wilks"));
			LAi_ActorSetSitMode(characterFromID("Able Seaman Tompkins"));

			DoQuestReloadToLocation("PaP_Guardhouse", "goto", "goto4", "Crew_Wolfe_Prison2");
		break;

		case "Crew_Wolfe_Prison2":
			ChangeCharacterAddressGroup(characterFromID("Styles"), "PaP_Guardhouse", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "PaP_Guardhouse", "sit", "sit2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "PaP_Guardhouse", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "PaP_Guardhouse", "sit", "sit1");

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Able Seaman Tompkins"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Able Seaman Tompkins"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Able Seaman Stanley"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Able Seaman Stanley"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Able Seaman Wilks"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Able Seaman Wilks"), GUN_ITEM_TYPE);

			LAi_SetActorType(PChar);
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Bloody_Storeroom";
			LAi_ActorGoToLocator((Pchar), "goto", "goto3", "Crew_Wolfe_Prison4", 10);
		break;

		case "Crew_Wolfe_Prison4":
			LAi_SetPlayerType(PChar);

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Crew_Wolfe_Prison5":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto4", "Crew_Wolfe_Prison6XXX", 10);
		break;

		case "Crew_Wolfe_Prison6XXX":
			LAi_QuestDelay("Crew_Wolfe_Prison6YYY", 1.0);
		break;

		case "Crew_Wolfe_Prison6YYY":
			LAi_ActorGoToLocator((Pchar), "goto", "goto3", "Crew_Wolfe_Prison6ZZZ", 10);
		break;

		case "Crew_Wolfe_Prison6ZZZ":
			LAi_QuestDelay("Crew_Wolfe_Prison6WWW", 1.0);
		break;

		case "Crew_Wolfe_Prison6WWW":
			LAi_ActorGoToLocator((Pchar), "goto", "goto4", "Crew_Wolfe_Prison6VVV", 10);
		break;

		case "Crew_Wolfe_Prison6VVV":
			LAi_QuestDelay("Crew_Wolfe_Prison6", 1.0);
		break;

		case "Crew_Wolfe_Prison6":
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Bloody_Storeroom_two";
			LAi_ActorGoToLocator((Pchar), "goto", "goto3", "Crew_Wolfe_Prison7", 10);
		break;

		case "Crew_Wolfe_Prison7":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;
///////////////////////////////////
//FOOD SCENE WHEN WE GET TABLES
///////////////////////////////////
		case "Crew_Wolfe_Prison8":
			LAi_SetActorType(PChar);
			Characters[GetCharacterIndex("Thomas Wolfe")].dialog.CurrentNode = "Capture_Soldiers";
			LAi_ActorGoToLocator((Pchar), "goto", "goto4", "Soldiers_Wolfe_Beach", 10);
		break;

		case "Soldiers_Wolfe_Beach":
			PlaySound("AMBIENT\JAIL\Door_002.wav");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "PaP_Guardhouse", "reload", "reload2");
			LAi_ActorTurnToCharacter((Pchar), characterFromID("Thomas Wolfe"));
			LAi_QuestDelay("Soldiers_Wolfe_BeachVVV", 2.0);
		break;

		case "Soldiers_Wolfe_BeachVVV":
			LAi_ActorGoToLocator(characterFromID("Thomas Wolfe"), "goto", "goto3", "Soldiers_Wolfe_BeachWWW", 10);
		break;

		case "Soldiers_Wolfe_BeachWWW":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			characters[GetCharacterIndex("Thomas Wolfe")].Dialog.Filename = "Thomas Wolfe_dialog.c";
			LAi_ActorDialogNow(characterFromID("Thomas Wolfe"),PChar,"",2.0);
		break;

		case "Soldiers_Wolfe_BeachXXX":
			LAi_Fade("Soldiers_Wolfe_BeachYYY","Soldiers_Wolfe_BeachZZZ");
		break;

		case "Soldiers_Wolfe_BeachYYY":
			SetModelfromArray(PChar, GetModelIndex("WolfFrench"));
			PChar.name = "Thomas";
			PChar.lastname = "Wolfe";
		break;

		case "Soldiers_Wolfe_BeachZZZ":
			DoQuestReloadToLocation("Guadeloupe_shore_01", "goto", "citizen04", "Soldiers_Wolfe_Beach2");
		break;

		case "Soldiers_Wolfe_Beach2":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "citizen03");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "citizen03");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG2B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "citizen03");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG3B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "citizen03");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG4B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "citizen03");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG5B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "citizen03");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG6B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "citizen03");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG7B";

			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "Guadeloupe_shore_01", "goto", "locator12");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "locator3_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "locator3_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "locator3_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "locator3_3");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "locator3_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "locator3_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier6X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "locator3_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier7X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "locator3_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier8X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "locator3_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier9X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "locator3_3");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier10X";

			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			LAi_QuestDelay("Soldiers_Wolfe_Beach3", 0.0);
		break;

		case "Soldiers_Wolfe_Beach3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("soldierG1B"));
			LAi_SetActorType(characterFromID("soldierG2B"));
			LAi_SetActorType(characterFromID("soldierG3B"));
			LAi_SetActorType(characterFromID("soldierG4B"));
			LAi_SetActorType(characterFromID("soldierG5B"));
			LAi_SetActorType(characterFromID("soldierG6B"));
			LAi_SetActorType(characterFromID("soldierG7B"));

			LAi_ActorGoToLocator(characterFromID("soldierG1B"), "goto", "goto02", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG2B"), "goto", "goto03", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG3B"), "goto", "goto04", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG4B"), "goto", "goto05", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG5B"), "goto", "goto06", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG6B"), "goto", "goto08", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG7B"), "goto", "goto07", "", 40);

			LAi_ActorGoToLocator(characterFromID("Black Charlie Hammond"), "goto", "goto01", "Soldiers_Wolfe_Beach4", 40);
		break;

		case "Soldiers_Wolfe_Beach4":
			LAi_ActorTurnToCharacter(characterFromID("soldierG1B"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldierG2B"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldierG3B"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldierG4B"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldierG5B"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldierG6B"), Pchar);
			LAi_ActorTurnToCharacter(characterFromID("soldierG7B"), Pchar);

			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));
			LAi_SetActorType(characterFromID("soldier4X"));
			LAi_SetActorType(characterFromID("soldier5X"));
			LAi_SetActorType(characterFromID("soldier6X"));
			LAi_SetActorType(characterFromID("soldier7X"));
			LAi_SetActorType(characterFromID("soldier8X"));
			LAi_SetActorType(characterFromID("soldier9X"));
			LAi_SetActorType(characterFromID("soldier10X"));

			LAi_ActorRunToLocator(characterFromID("soldier1X"), "goto", "goto09", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier2X"), "goto", "goto10", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier3X"), "goto", "goto11", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier4X"), "goto", "goto12", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier5X"), "goto", "goto13", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier6X"), "goto", "goto14", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier7X"), "goto", "goto15", "Soldiers_Wolfe_Beach5", 40);
			LAi_ActorRunToLocator(characterFromID("soldier8X"), "goto", "seaman2", "",40); //"citizen04", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier9X"), "goto", "locator14", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier10X"), "goto", "seaman1", "", 40);
		break;

		case "Soldiers_Wolfe_Beach5":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "locator13", "Soldiers_Wolfe_Beach6", 10);
//			Check soldiers in place
			LAi_ActorGoToLocator(characterFromID("soldierG1B"), "goto", "goto02", "", 1.0);
			LAi_ActorGoToLocator(characterFromID("soldierG2B"), "goto", "goto03", "", 1.0);
			LAi_ActorGoToLocator(characterFromID("soldierG3B"), "goto", "goto04", "", 1.0);
			LAi_ActorGoToLocator(characterFromID("soldierG4B"), "goto", "goto05", "", 1.0);
			LAi_ActorGoToLocator(characterFromID("soldierG5B"), "goto", "goto06", "", 1.0);
			LAi_ActorGoToLocator(characterFromID("soldierG6B"), "goto", "goto08", "", 1.0);
			LAi_ActorGoToLocator(characterFromID("soldierG7B"), "goto", "goto07", "", 1.0);
		break;

		case "Soldiers_Wolfe_Beach6":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Surrender_time";
		break;

		case "Hammond_Wolfe_join":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("soldier8X"));
			RemoveCharacterEquip(characterFromID("soldierG1B"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("soldierG1B"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("soldierG2B"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("soldierG2B"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("soldierG3B"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("soldierG3B"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("soldierG4B"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("soldierG4B"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("soldierG5B"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("soldierG5B"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("soldierG6B"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("soldierG6B"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("soldierG7B"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("soldierG7B"), GUN_ITEM_TYPE);

			LAi_ActorGoToLocator(characterFromID("soldierG1B"), "officers", "locator3_1", "Hammond_Wolfe_join2", 20);
			LAi_ActorGoToLocator(characterFromID("soldierG2B"), "officers", "locator3_3", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG3B"), "officers", "locator3_3", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG4B"), "officers", "locator3_3", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG5B"), "officers", "locator3_3", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG6B"), "officers", "locator3_3", "", 40);
			LAi_ActorGoToLocator(characterFromID("soldierG7B"), "officers", "locator3_3", "", 40);
		break;

		case "Hammond_Wolfe_join2":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddress(characterFromID("soldierG7B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG6B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG5B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG4B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG3B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG2B"), "None", "");
			ChangeCharacterAddress(characterFromID("soldierG1B"), "None", "");

			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialog(characterFromID("Black Charlie Hammond"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Surrender_easy";
		break;

		case "Hornblower_and_picklock":
			LAi_Fade("Hornblower_and_picklockA","Interupt_for_Hotspur");
		break;

		case "Hornblower_and_picklockA":
			ChangeCharacterAddress(characterFromID("Matthews"), "None", "");
			ChangeCharacterAddress(characterFromID("Black Charlie Hammond"), "None", "");
			ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");
//			LAi_QuestDelay("Interupt_for_Hotspur", 0.0);
		break;

		case "Interupt_for_Hotspur":
			SetModelfromArray(PChar, GetModelIndex("MatthewsHB"));
			PChar.name = "Matthews";
			PChar.lastname = "";

			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Quest_ShipDeck1", "reload", "boatl");
			ChangeCharacterAddressGroup(characterFromID("Jack Hammond"), "Quest_ShipDeck1", "goto", "goto10");
			ChangeCharacterAddressGroup(characterFromID("Perrin"), "Quest_ShipDeck1", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Marsh"), "Quest_ShipDeck1", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Quest_ShipDeck1", "goto", "goto11");
			ChangeCharacterAddressGroup(characterFromID("Lt. Chadd"), "Quest_ShipDeck1", "rld", "startloc");
			ChangeCharacterAddressGroup(characterFromID("Helmsman"), "Quest_ShipDeck1", "goto", "goto14");
			LAi_SetActorType(characterFromID("Jack Hammond"));
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			LAi_SetOfficerType(characterFromID("Lt.Chadd"));

			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Standby_for_action";
			DoQuestReloadToLocation("Quest_ShipDeck1", "goto", "goto1", "Interupt_for_Hotspur2");
		break;

		case "Interupt_for_Hotspur2":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "rld", "loc3");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG1B";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "rld", "loc2");
			LAi_group_MoveCharacter(sld, "LAI_GROUP_PLAYER");
			sld.id = "soldierG2B";
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. William Bush"),PChar,"",2.0);
		break;

		case "Interupt_for_Hotspur3":
			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "Dont_like_attitude";
			LAi_ActorGoToLocator(characterFromID("Lt. William Bush"), "goto", "goto7", "", 40);
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto9", "Interupt_for_Hotspur4", 10);
		break;

		case "Interupt_for_Hotspur4":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Jack Hammond"),PChar,"",2.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Line_astern";
		break;

		case "Interupt_for_Hotspur5":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. William Bush"),PChar,"",2.0);
		break;

		case "Interupt_for_Hotspur6":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto6", "Interupt_for_Hotspur7", 10);
			LAi_ActorGoToLocator(characterFromID("Jack Hammond"), "goto", "goto4", "", 40);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Dont_like_look";
		break;

		case "Interupt_for_Hotspur7":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. William Bush"),PChar,"",2.0);

			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "Your_Uncle";
		break;

		case "Interupt_for_Hotspur8":
			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Jack Hammond"),PChar,"",2.0);
		break;

		case "Hornblower_and_picklock2":
			SetModelfromArray(PChar, GetModelIndex("brtHComdr_18"));
			PChar.name = "Horatio";
			PChar.lastname = "Hornblower";
			Locations[FindLocation("PaP_Guardhouse")].reload.l1.disable = 1;
			Locations[FindLocation("PaP_Guardhouse")].reload.l2.disable = 1;
			LAi_ActorSetSitMode(characterFromID("Able Seaman Wilks"));
			LAi_ActorSetSitMode(characterFromID("Able Seaman Tompkins"));
			DoQuestReloadToLocation("PaP_Guardhouse", "goto", "goto4", "Hornblower_and_picklock3");
		break;

		case "Hornblower_and_picklock3":
			ChangeCharacterAddressGroup(characterFromID("Styles"), "PaP_Guardhouse", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "PaP_Guardhouse", "sit", "sit2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "PaP_Guardhouse", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "PaP_Guardhouse", "sit", "sit1");

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Able Seaman Tompkins"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Able Seaman Tompkins"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Able Seaman Stanley"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Able Seaman Stanley"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Able Seaman Wilks"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Able Seaman Wilks"), GUN_ITEM_TYPE);

			PlaySound("AMBIENT\CHURCH\Town_alarm.wav");
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Church_Bells";
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto3", "Hornblower_and_picklock4", 10);
		break;

		case "Hornblower_and_picklock4":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Hornblower_and_picklock5":
			AddQuestRecord("Old Friends - New Enemies", 15);
			pchar.quest.Take_the_battery.win_condition.l1 = "locator";
			pchar.quest.Take_the_battery.win_condition.l1.location = "PaP_Guardhouse";
			pchar.quest.Take_the_battery.win_condition.l1.locator_group = "reload";
			pchar.quest.Take_the_battery.win_condition.l1.locator = "reload2";
			pchar.quest.Take_the_battery.win_condition = "Take_the_battery";

			pchar.quest.Death_in_the_Battery.win_condition.l1 = "locator";
			pchar.quest.Death_in_the_Battery.win_condition.l1.location = "PaP_Guardhouse";
			pchar.quest.Death_in_the_Battery.win_condition.l1.locator_group = "reload";
			pchar.quest.Death_in_the_Battery.win_condition.l1.locator = "reload1";
			pchar.quest.Death_in_the_Battery.win_condition = "Death_in_the_Battery";
		break;

		case "Death_in_the_Battery":
			Pchar.Quest.Take_the_battery.over = "yes";
			Locations[FindLocation("PaP_Guardhouse")].reload.l2.disable = 0;
			Locations[FindLocation("PaP_Guardhouse")].reload.l1.disable = 1;

			pchar.quest.Death_in_the_Battery1.win_condition.l1 = "location";
			Pchar.quest.Death_in_the_Battery1.win_condition.l1.character = Pchar.id;
			pchar.quest.Death_in_the_Battery1.win_condition.l1.location = "PaP_prison";
			pchar.quest.Death_in_the_Battery1.win_condition = "Death_in_the_Battery1";
		break;

		case "Death_in_the_Battery1":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);

			Locations[FindLocation("PaP_prison")].reload.l1.disable = 1;
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto18");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto19");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto20");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterByItem(sld, "pistol1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";
			PlaySound("AMBIENT\JAIL\Door_003.wav");		// GR: was Door_004.wav, which doesn't exist
			LAi_QuestDelay("Death_in_the_Battery2", 0.0);
		break;

		case "Death_in_the_Battery2":
			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Trapped_in_prison");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Trapped_in_prison":
			//GAME OVER
		break;

		case "Take_the_battery":
			Pchar.Quest.Death_in_the_Battery.over = "yes";
			PlaySound("AMBIENT\JAIL\Door_004.wav");
			ChangeCharacterAddress(characterFromID("Able Seaman Tompkins"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Wilks"), "None", "");
			Pchar.Quest.Death_in_the_Battery.over = "yes";
			Locations[FindLocation("PaP_Guardhouse")].reload.l1.disable = 0;
			Locations[FindLocation("PaP_Guardhouse")].reload.l2.disable = 1;
			LAi_QuestDelay("Take_the_battery2", 0.0);
		break;

		case "Take_the_battery2":
			LAi_ActorAnimation(characterFromID("Able Seaman Tompkins"), "StandUp", "", 1.0);
			LAi_type_actor_Reset(characterFromID("Able Seaman Tompkins"));
			LAi_ActorAnimation(characterFromID("Able Seaman Wilks"), "StandUp", "", 1.0);
			LAi_type_actor_Reset(characterFromID("Able Seaman Wilks"));
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));
			LAi_QuestDelay("Take_the_battery3", 0.0);
		break;

		case "Take_the_battery3":
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "PaP_Arsenal", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "PaP_Arsenal", "reload", "reload1");

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Found_Weapons";
			pchar.quest.Got_some_weapons.win_condition.l1 = "location";
			Pchar.quest.Got_some_weapons.win_condition.l1.character = Pchar.id;
			pchar.quest.Got_some_weapons.win_condition.l1.location = "PaP_Arsenal";
			pchar.quest.Got_some_weapons.win_condition = "Got_some_weapons";
		break;

		case "Got_some_weapons":
			PlaySound("OBJECTS\duel\Fort_guns.wav");
			LAi_type_actor_Reset(characterFromID("Able Seaman Tompkins"));
			LAi_type_actor_Reset(characterFromID("Able Seaman Wilks"));
			LAi_QuestDelay("Got_some_weapons2", 0.0);
		break;

		case "Got_some_weapons2":
			ChangeCharacterAddressGroup(characterFromID("Styles"), "PaP_Arsenal", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "PaP_Arsenal", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "PaP_Arsenal", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "PaP_Arsenal", "reload", "reload1");

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			RemoveCharacterEquip(characterFromID("Able Seaman Tompkins"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Able Seaman Tompkins"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Styles"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Styles"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Able Seaman Stanley"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Able Seaman Stanley"), GUN_ITEM_TYPE);

			RemoveCharacterEquip(characterFromID("Able Seaman Wilks"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Able Seaman Wilks"), GUN_ITEM_TYPE);

			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto4", "Got_some_weapons3", 4);
		break;

		case "Got_some_weapons3":
			LAi_SetPlayerType(PChar);

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);

			Characters[GetCharacterIndex("Able Seaman Wilks")].dialog.CurrentNode = "Found_the_battery";
		break;

		case "Attack_the_Battery_Guns":
			PlaySound("OBJECTS\duel\Fort_guns.wav");
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));
			characters[GetCharacterIndex("Able Seaman Wilks")].Dialog.Filename = "RN_Sailor_dialog.c";
			LAi_ActorDialogNow(characterFromID("Able Seaman Wilks"),PChar,"",2.0);
		break;

		case "Hotspur_underfire":
			LAi_Fade("Hotspur_underfire2","Hotspur_underfire3");
		break;

		case "Hotspur_underfire2":
			ChangeCharacterAddress(characterFromID("Lt. Chadd"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Quest_ShipDeck1", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Jack Hammond"), "Quest_ShipDeck1", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Perrin"), "Quest_ShipDeck1", "goto", "goto10"); //"goto1");
			ChangeCharacterAddressGroup(characterFromID("Marsh"), "Quest_ShipDeck1", "goto", "goto3"); //"goto5");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Quest_ShipDeck1", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Quest_ShipDeck1", "goto", "goto8");
			ChangeCharacterAddressGroup(characterFromID("Helmsman"), "Quest_ShipDeck1", "goto", "goto14");
			LAi_SetActorType(characterFromID("Jack Hammond"));
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Able Seaman Wilks")].Dialog.CurrentNode = "First time"; // PB: Prevent main quest loop
		break;

		case "Hotspur_underfire3":
			SetModelfromArray(PChar, GetModelIndex("EcclestonH"));
			PChar.name = "Lt.";
			PChar.lastname = "Chadd";

			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Bring_her_inshore";
			DoQuestReloadToLocation("Quest_ShipDeck1", "goto", "goto4", "Hotspur_underfire4");
		break;

		case "Hotspur_underfire4":
			LAi_SetPlayerType(Pchar);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("Hotspur_underfire4A", 2.0);
		break;

		case "Hotspur_underfire4A":
			LAi_SetActorType(characterFromID("Marsh"));
			LAi_ActorRunToLocator(characterFromID("Marsh"), "goto", "goto5", "", 0.0);
			CreateParticleSystemX("blast_inv", -2.0988, 2.712, 8.4879, 1.7537, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -2.0988, 2.712, 8.4879, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -2.0988, 2.712, 8.4879, 0.0, 0.0, 0.0,20);
			LAi_QuestDelay("Hotspur_underfire5", 2.0);
		break;

		case "Hotspur_underfire5":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("Hotspur_underfire5A", 2.0);
		break;

		case "Hotspur_underfire5A":
			LAi_SetActorType(characterFromID("Perrin"));
			LAi_ActorRunToLocator(characterFromID("Perrin"), "goto", "goto1", "", 0.0);
			CreateParticleSystemX("blast_inv", 1.5383, 2.6384, 3.1322, 1.7537, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 1.5383, 2.6384, 3.1322, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 1.5383, 2.6384, 3.1322, 0.0, 0.0, 0.0,20);
			LAi_QuestDelay("Hotspur_underfire6", 2.0);
		break;

		case "Hotspur_underfire6":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			LAi_QuestDelay("Hotspur_underfire6A", 2.0);
		break;

		case "Hotspur_underfire6A":
			CreateParticleSystemX("blast_inv", 0.39356, 2.7365, -3.1684, 1.7537, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 0.39356, 2.7365, -3.1684, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 0.39356, 2.7365, -3.1684, 0.0, 0.0, 0.0,20);
			LAi_QuestDelay("Hotspur_underfire7", 0.0);
		break;

		case "Hotspur_underfire7":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_HB.wav");
			Lai_KillCharacter(characterFromID("Marsh"));
			Lai_KillCharacter(characterFromID("Perrin"));
			LAi_QuestDelay("Hotspur_underfire8", 2.0);
		break;

		case "Hotspur_underfire8":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. William Bush"),PChar,"",2.0);
		break;

		case "Hotspur_underfire9":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("blast_inv", -0.64847, 4.9474, -17.581, 1.7537, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -0.64847, 4.9474, -17.581, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -0.64847, 4.9474, -17.581, 0.0, 0.0, 0.0,20);
			LAi_ActorAnimation(CharacterFromID("Lt. William Bush"), "afraid","", 10);
			LAi_ActorAnimation(CharacterFromID("Jack Hammond"), "afraid","", 10);
			LAi_QuestDelay("Hotspur_underfire10", 2.0);
		break;

		case "Hotspur_underfire10":
			LAi_Fade("Battery_Plan_One","Battery_Plan_Two");
		break;

		case "Battery_Plan_One":
			ChangeCharacterAddressGroup(characterFromID("Styles"), "PaP_Arsenal", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "PaP_Arsenal", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "PaP_Arsenal", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "PaP_Arsenal", "goto", "goto4");

			GiveItem2Character(characterFromID("Styles"), "pistol1");
			EquipCharacterByItem(characterFromID("Styles"), "pistol1");
			GiveItem2Character(characterFromID("Able Seaman Tompkins"), "pistol1");
			EquipCharacterByItem(characterFromID("Able Seaman Tompkins"), "pistol1");
			GiveItem2Character(characterFromID("Able Seaman Stanley"), "pistol1");
			EquipCharacterByItem(characterFromID("Able Seaman Stanley"), "pistol1");
			GiveItem2Character(characterFromID("Able Seaman Wilks"), "pistol1");
			EquipCharacterByItem(characterFromID("Able Seaman Wilks"), "pistol1");
		break;
		
		case "Battery_Plan_Two":
			SetModelfromArray(PChar, GetModelIndex("brtHComdr_18"));
			PChar.name = "Horatio";
			PChar.lastname = "Hornblower";

			DoQuestReloadToLocation("PaP_Arsenal", "goto", "goto5", "Battery_Plan_Three");
		break;

		case "Battery_Plan_Three":
			PlaySound("OBJECTS\duel\Fort_guns.wav");
			LAi_SetOfficerType(characterFromID("Styles"));
			LAi_SetOfficerType(characterFromID("Able Seaman Tompkins"));
			LAi_SetOfficerType(characterFromID("Able Seaman Stanley"));
			LAi_SetOfficerType(characterFromID("Able Seaman Wilks"));

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Plan_for_battery";
			LAi_QuestDelay("Plan_for_battery_attack", 2.0);
		break;

		case "Plan_for_battery_attack":
			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Orders_for_attack_battery":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			pchar.quest.Destroy_the_Battery.win_condition.l1 = "locator";
			pchar.quest.Destroy_the_Battery.win_condition.l1.location = "PaP_Arsenal";
			pchar.quest.Destroy_the_Battery.win_condition.l1.locator_group = "reload";
			pchar.quest.Destroy_the_Battery.win_condition.l1.locator = "reload1";
			pchar.quest.Destroy_the_Battery.win_condition = "Destroy_the_Battery";
		break;

		case "Destroy_the_Battery":
			DoQuestReloadToLocation("Fake_Guadeloupe_fort", "reload", "reloadc2", "set_the_guns_and_crew");
		break;

		case "set_the_guns_and_crew":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("cancloud", 16.105, 7.9408, -6.0718, -1.00, 0.0, 0.0,5);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto1");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto2");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto3");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto4");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto5");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto6");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier6X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "rld", "loc5");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier7X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "rld", "loc6"); //"goto", "goto4"); //"rld", "loc6");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier8X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "rld", "loc7");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier9X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "rld", "loc8");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier10X";

			ChangeCharacterAddressGroup(characterFromID("Styles"), "Fake_Guadeloupe_fort", "rld", "loc10");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Fake_Guadeloupe_fort", "rld", "loc10");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Fake_Guadeloupe_fort", "rld", "loc10");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "Fake_Guadeloupe_fort", "rld", "loc10");

			LAi_QuestDelay("set_the_guns_and_crew2", 1.0);
		break;

		case "set_the_guns_and_crew2":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("cancloud", -7.0532, 7.9408, 2.21, -1.00, 0.0, 0.0,10);

			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));
			LAi_SetActorType(characterFromID("soldier4X"));
			LAi_SetActorType(characterFromID("soldier5X"));
			LAi_SetActorType(characterFromID("soldier6X"));
			LAi_SetActorType(characterFromID("soldier7X"));
			LAi_SetActorType(characterFromID("soldier8X"));
			LAi_SetActorType(characterFromID("soldier9X"));
			LAi_SetActorType(characterFromID("soldier10X"));

			LAi_SetActorType(characterFromID("Styles"));
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));

			LAi_ActorRunToLocator(characterFromID("soldier8X"), "rld", "loc4", "", 40); //"Destroy_the_Battery3", 40);

			LAi_QuestDelay("Destroy_the_Battery2", 0.0);
		break;

		case "Destroy_the_Battery2":
			LAi_group_MoveCharacter(characterFromID("Soldier7X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier7X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier8X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier8X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier9X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier9X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier10X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier10X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Styles"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Able Seaman Tompkins"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Able Seaman Stanley"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Able Seaman Wilks"), LAI_GROUP_PLAYER);
			LAi_SetImmortal(CharacterFromID("Styles"), true);
			LAi_SetImmortal(CharacterFromID("Able Seaman Tompkins"), true);
			LAi_SetImmortal(CharacterFromID("Able Seaman Stanley"), true);
			LAi_SetImmortal(CharacterFromID("Able Seaman Wilks"), true);
			LAi_QuestDelay("Destroy_the_Battery3", 1.0);
		break;

		case "Destroy_the_Battery3":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("cancloud", 16.06, 7.9408, -11.026, -1.0, 0.0, 0.0,10);

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Now_stop_the_gunsP");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";

			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("cancloud", 16.105, 7.9408, -6.0718, -1.00, 0.0, 0.0,5);
		break;

		case "Now_stop_the_gunsP":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("cancloud", -7.0532, 7.9408, 2.21, -1.00, 0.0, 0.0,10); //-7.2353

			LAi_SetActorType(characterFromID("Styles"));
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));

			LAi_SetActorType(characterFromID("Soldier2X"));
			LAi_SetActorType(characterFromID("Soldier3X"));
			LAi_SetActorType(characterFromID("Soldier4X"));

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Shoot the gunners";
			LAi_QuestDelay("Destroy_the_Battery4", 1.0);
		break;

		case "Destroy_the_Battery4":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(Pchar, "rld", "loc13", "Now_stop_the_gunsP2",4);
		break;

		case "Now_stop_the_gunsP2":
			LAi_SetPlayerType(PChar);

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("cancloud", 16.105, 7.9408, -6.0718, -1.00, 0.0, 0.0,5);
		break;

		case "Four_gunners_dead":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("cancloud", 16.06, 7.9408, -11.026, -1.0, 0.0, 0.0,10);

			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("soldier3X"));

			ChangeCharacterAddressGroup(characterFromID("Soldier5X"), "Fake_Guadeloupe_fort", "rld", "loc10");
			ChangeCharacterAddressGroup(characterFromID("Soldier6X"), "Fake_Guadeloupe_fort", "reload", "reloadc2");

			LAi_ActorRunToLocator(characterFromID("Styles"), "rld", "loc4", "", 5);
			LAi_ActorRunToLocator(characterFromID("Able Seaman Wilks"), "rld", "loc3", "", 5);
			LAi_ActorRunToLocator(characterFromID("Able Seaman Tompkins"), "rld", "loc5", "", 5);
			LAi_ActorRunToLocator(characterFromID("Able Seaman Stanley"), "rld", "loc1", "Four_gunners_dead2", 5);
		break;

		case "Four_gunners_dead2":
			LAi_ActorTurnToCharacter(characterFromID("Styles"), characterFromID("soldier1X"));
			LAi_ActorTurnToCharacter(characterFromID("Able Seaman Wilks"), characterFromID("soldier2X"));
			LAi_ActorTurnToCharacter(characterFromID("Able Seaman Tompkins"), characterFromID("soldier3X"));
			LAi_ActorTurnToCharacter(characterFromID("Able Seaman Stanley"), characterFromID("soldier4X"));
			LAi_QuestDelay("Four_gunners_dead3", 0.0);
		break;
		
		case "Four_gunners_dead3":
			LAi_ActorAnimation(characterFromID("Styles"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav");
			GetCharacterPos(characterFromID("Styles"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorTurnToCharacter(characterFromID("soldier2X"),characterFromID("Able Seaman Wilks"));
			LAi_ActorTurnToCharacter(characterFromID("soldier3X"),characterFromID("Able Seaman Tompkins"));
			LAi_ActorTurnToCharacter(characterFromID("soldier4X"),characterFromID("Able Seaman Stanley"));
			LAi_QuestDelay("Four_gunners_dead4", 1.0);
		break;

		case "Four_gunners_dead4":
			LAi_SetActorType(characterFromID("Styles"));
			Lai_KillCharacter(characterFromID("soldier1X"));

			LAi_ActorAnimation(characterFromID("soldier2X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav");
			GetCharacterPos(characterFromID("soldier2X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Able Seaman Tompkins"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav");
			GetCharacterPos(characterFromID("Able Seaman Tompkins"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_QuestDelay("Four_gunners_dead5", 1.0);
		break;

		case "Four_gunners_dead5":
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			Lai_KillCharacter(characterFromID("soldier2X"));

			LAi_ActorAnimation(characterFromID("soldier3X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav");
			GetCharacterPos(characterFromID("soldier3X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Able Seaman Wilks"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav");
			GetCharacterPos(characterFromID("Able Seaman Wilks"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_QuestDelay("Four_gunners_dead6", 1.0);
		break;

		case "Four_gunners_dead6":
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));
			Lai_KillCharacter(characterFromID("soldier3X"));

			LAi_ActorAnimation(characterFromID("soldier4X"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav");
			GetCharacterPos(characterFromID("soldier4X"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);

			LAi_ActorAnimation(characterFromID("Able Seaman Stanley"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav");
			GetCharacterPos(characterFromID("Able Seaman Stanley"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_QuestDelay("Four_gunners_dead7", 1.0);

			LAi_group_MoveCharacter(characterFromID("Soldier5X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier5X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier6X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier6X"), "FRANCE_SOLDIERS");
		break;

		case "Four_gunners_dead7":
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));
			Lai_KillCharacter(characterFromID("soldier4X"));
			LAi_SetPlayerType(PChar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("soldier5X"));
			LAi_QuestDelay("Last_two_gunners_fight", 0.0);
		break;

		case "Last_two_gunners_fight":
			LAi_SetOfficerType(characterFromID("Styles"));
			LAi_SetOfficerType(characterFromID("Able Seaman Tompkins"));
			LAi_SetOfficerType(characterFromID("Able Seaman Stanley"));
			LAi_SetOfficerType(characterFromID("Able Seaman Wilks"));

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Last_two_gunners_dead");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Spike_the_guns";
		break;

		case "Last_two_gunners_dead":
			LAi_SetPlayerType(PChar);

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Set_the_Charges_Guns":
			LAi_SetActorType(characterFromID("Able Seaman Tompkins"));
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));
			LAi_SetActorType(characterFromID("Able Seaman Wilks"));

			LAi_ActorRunToLocator(characterFromID("Styles"), "rld", "loc13", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Able Seaman Wilks"), "reload", "reload1", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Able Seaman Tompkins"), "rld", "loc5", "", 0.0);
			LAi_ActorRunToLocator(characterFromID("Able Seaman Stanley"), "reload", "reload2", "", 0.0);

			Characters[GetCharacterIndex("Able Seaman Stanley")].dialog.CurrentNode = "A_rope";

			pchar.quest.Set_the_Charges_Guns2.win_condition.l1 = "locator";
			pchar.quest.Set_the_Charges_Guns2.win_condition.l1.location = "Fake_Guadeloupe_fort";
			pchar.quest.Set_the_Charges_Guns2.win_condition.l1.locator_group = "box";
			pchar.quest.Set_the_Charges_Guns2.win_condition.l1.locator = "box2";
			pchar.quest.Set_the_Charges_Guns2.win_condition = "Set_the_Charges_Guns2";
		break;

		case "Set_the_Charges_Guns2":
			LAi_SetActorType(characterFromID("Able Seaman Stanley"));
			characters[GetCharacterIndex("Able Seaman Stanley")].Dialog.Filename = "RN_Sailor_dialog.c";
			LAi_ActorDialogNow(characterFromID("Able Seaman Stanley"),PChar,"",2.0);
		break;

		case "Another_Hotspur_visit":
			LAi_Fade("Another_Hotspur_visit2","Check_that_signal");
		break;

		case "Another_Hotspur_visit2":
			ChangeCharacterAddress(characterFromID("Lt. William Bush"), "None", "");
			ChangeCharacterAddressGroup(characterFromID("Lt. Chadd"), "Quest_ShipDeck1", "goto", "goto14"); //"rld", "startloc");
			ChangeCharacterAddressGroup(characterFromID("Jack Hammond"), "Quest_ShipDeck1", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Perrin"), "Quest_ShipDeck1", "goto", "goto10");
			ChangeCharacterAddressGroup(characterFromID("Marsh"), "Quest_ShipDeck1", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Oldroyd"), "Quest_ShipDeck1", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Quest_ShipDeck1", "goto", "goto8");
			ChangeCharacterAddressGroup(characterFromID("Helmsman"), "Quest_ShipDeck1", "rld", "startloc"); //"goto", "goto14");
			LAi_SetActorType(characterFromID("Jack Hammond"));
			LAi_SetActorType(characterFromID("Lt. William Bush"));
		break;

		case "Check_that_signal":
			SetModelfromArray(PChar, GetModelIndex("BushLtn_18"));
			PChar.name = "Lt. William";
			PChar.lastname = "Bush";

			Characters[GetCharacterIndex("Jack Hammond")].dialog.CurrentNode = "Withdraw_Signal_from_flagship";
			DoQuestReloadToLocation("Quest_ShipDeck1", "goto", "goto4", "Check_that_signal2");
		break;

		case "Check_that_signal2":
			LAi_ActorGoToLocator(characterFromID("Marsh"), "goto", "goto5", "", 0.0);
			LAi_ActorGoToLocator(characterFromID("Perrin"), "goto", "goto1", "", 0.0);
			LAi_QuestDelay("Check_that_signal3", 3.0);
		break;

		case "Check_that_signal3":
			LAi_SetActorType(characterFromID("Jack Hammond"));
			characters[GetCharacterIndex("Jack Hammond")].Dialog.Filename = "Jack Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Jack Hammond"),PChar,"",2.0);

			Characters[GetCharacterIndex("Lt. Chadd")].dialog.CurrentNode = "Signal_is_Correct";
		break;

		case "Chadd_Knows_Signal":
			LAi_ActorGoToLocator(characterFromID("Jack Hammond"), "goto", "goto6", "", 0.0);
			LAi_SetActorType(characterFromID("Lt. Chadd"));
			characters[GetCharacterIndex("Lt. Chadd")].Dialog.Filename = "Lt. Chadd_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. Chadd"),PChar,"",2.0);
		break;

		case "Back_to_Fort_Bomb":
//Grey Roger: return you to Horatio Hornblower
			SetModelfromArray(PChar, GetModelIndex("brtHComdr_18"));
			PChar.name = "Horatio";
			Pchar.lastname = "Hornblower";
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Fake_Guadeloupe_fort", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Fake_Guadeloupe_fort", "reload", "reload2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Fake_Guadeloupe_fort", "reload", "reload2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "Fake_Guadeloupe_fort", "reload", "reload2");

			DoQuestReloadToLocation("Fake_Guadeloupe_fort", "reload", "reload1", "Fort_fuse_escape");
		break;

		case "Fort_fuse_escape":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Fort_Fuse_Lit";
			LAi_QuestDelay("Fort_fuse_escape2", 1.0);
		break;

		case "Fort_fuse_escape2":
			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Men_over_wall":
			LAi_ActorRunToLocator(characterFromID("Styles"), "reload", "reload2", "Just_me_and_the_bang", 0.0);
			ChangeCharacterAddress(characterFromID("Able Seaman Tompkins"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Stanley"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Wilks"), "None", "");
		break;

		case "Just_me_and_the_bang":
			ChangeCharacterAddress(characterFromID("Styles"), "None", "");

			WriteLocatorGlobal("Fake_Guadeloupe_fort", "fire", "fire1", "", -1, 4.4705, 2.7257, -4.9335, false);
			Locations[FindLocation("Fake_Guadeloupe_fort")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Fake_Guadeloupe_fort")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 4.4705, 2.7257, -4.9335, -1.57, 0.0, 0.0,0);

			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire3.wav");
			CreateParticleSystemX("blast_inv", 4.4705, 2.7257, -4.9335, 1.7537, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 4.4705, 2.7257, -4.9335, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 4.4705, 2.7257, -4.9335, 0.0, 0.0, 0.0,20);
			LAi_QuestDelay("Just_me_and_the_bang2", 1.0);
		break;

		case "Just_me_and_the_bang2":
			WriteLocatorGlobal("Fake_Guadeloupe_fort", "fire", "fire1", "", -1, 4.4705, 2.7257, -4.9335, false);
			Locations[FindLocation("Fake_Guadeloupe_fort")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Fake_Guadeloupe_fort")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", 4.4705, 2.7257, -4.9335, -1.57, 0.0, 0.0,0);

			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire3.wav");
			CreateParticleSystemX("blast_inv", 4.4705, 2.7257, -4.9335, 1.7537, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 4.4705, 2.7257, -4.9335, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 4.4705, 2.7257, -4.9335, 0.0, 0.0, 0.0,20);
			LAi_QuestDelay("Just_me_and_the_bang2A", 2.0);
		break;

		case "Just_me_and_the_bang2A":
			WriteLocatorGlobal("Fake_Guadeloupe_fort", "fire", "fire1", "", -1, -7.0333, 2.7295, -8.0215, false);
			Locations[FindLocation("Fake_Guadeloupe_fort")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Fake_Guadeloupe_fort")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", -7.0333, 2.7295, -8.0215, -1.57, 0.0, 0.0,0);

			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire3.wav");
			CreateParticleSystemX("blast_inv", -7.0333, 2.7295, -8.0215, 1.7537, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -7.0333, 2.7295, -8.0215, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -7.0333, 2.7295, -8.0215, 0.0, 0.0, 0.0,20);
			LAi_QuestDelay("Just_me_and_the_bang3", 2.0);
		break;

		case "Just_me_and_the_bang3":
			WriteLocatorGlobal("Fake_Guadeloupe_fort", "fire", "fire1", "", -1, -1.1921, 7.6318, -1.1495, false);
			Locations[FindLocation("Fake_Guadeloupe_fort")].models.night.lights.fire = "heater"; 
			Locations[FindLocation("Fake_Guadeloupe_fort")].locators_radius.fire = 4.0; 
			CreateParticleSystemX("fireball", -1.1921, 7.6318, -1.1495, -1.57, 0.0, 0.0,0);

			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire3.wav");
			CreateParticleSystemX("blast_inv", -1.1921, 7.6318, -1.1495, 1.7537, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -1.1921, 7.6318, -1.1495, 0.0, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -1.1921, 7.6318, -1.1495, 0.0, 0.0, 0.0,20);
			LAi_QuestDelay("Me_over_the_wall", 1.0);
		break;

		case "Me_over_the_wall":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire3.wav");
			LAi_type_actor_Reset(characterFromID("Marsh"));
			LAi_type_actor_Reset(characterFromID("Perrin"));
			ChangeCharacterAddressGroup(characterFromID("Styles"), "Guadeloupe_shore_01", "reload", "locator3_back");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Tompkins"), "Guadeloupe_shore_01", "officers", "locator3_1");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Stanley"), "Guadeloupe_shore_01", "officers", "locator3_2");
			ChangeCharacterAddressGroup(characterFromID("Able Seaman Wilks"), "Guadeloupe_shore_01", "officers", "locator3_3");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Guadeloupe_shore_01", "goto", "citizen02");
			ChangeCharacterAddressGroup(characterFromID("Marsh"), "Guadeloupe_shore_01", "goto", "locator11");
			ChangeCharacterAddressGroup(characterFromID("Perrin"), "Guadeloupe_shore_01", "goto", "citizen03");
			ChangeCharacterAddressGroup(characterFromID("Matthews"), "Guadeloupe_shore_01", "goto", "locator12");
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Guadeloupe_shore_01", "goto", "locator10");
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "Guadeloupe_shore_01", "goto", "locator10");
			ChangeCharacterAddressGroup(characterFromID("Jack Hammond"), "Guadeloupe_shore_01", "goto", "goto06");
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator(Pchar, "reload", "reload2", "AND_onto_The_BEACH", 4.0);
		break;

		case "AND_onto_The_BEACH":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire3.wav");
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"RN_Volage","Hotspur",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Guadeloupe_shore_01");
			Locations[FindLocation("Guadeloupe_Jungle_03")].vcskip = false;
			Locations[FindLocation("Guadeloupe_Jungle_02")].vcskip = false;
			Locations[FindLocation("Guadeloupe_Jungle_01")].vcskip = false;
			DoQuestReloadToLocation("Guadeloupe_shore_01", "reload", "locator3", "Final_beach_scene_Hammond");
		break;

		case "Final_beach_scene_Hammond":
			LAi_SetPlayerType(PChar);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "see_1");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier1X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "see_2");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier2X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "see_3");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier3X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "see_1");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier4X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "see_2");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier5X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "see_3");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier6X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "officers", "see_1");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier7X";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "officers", "see_2");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "soldier8X";

			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "Almost_Home_Hotspur";
			LAi_QuestDelay("Form_up_French_Hotspur", 1.0);
		break;

		case "Form_up_French_Hotspur":
			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_SetActorType(characterFromID("soldier2X"));
			LAi_SetActorType(characterFromID("soldier3X"));
			LAi_SetActorType(characterFromID("soldier4X"));
			LAi_SetActorType(characterFromID("soldier5X"));
			LAi_SetActorType(characterFromID("soldier6X"));
			LAi_SetActorType(characterFromID("soldier7X"));
			LAi_SetActorType(characterFromID("soldier8X"));
			Characters[GetCharacterIndex("Matthews")].dialog.CurrentNode = "First time";

			LAi_SetActorType(characterFromID("Styles"));
			characters[GetCharacterIndex("Styles")].Dialog.Filename = "Styles_dialog.c";
			LAi_ActorDialogNow(characterFromID("Styles"),PChar,"",2.0);
		break;

		case "Hammond_Wolfe_Bush":
			LAi_SetOfficerType(characterFromID("Styles"));
			LAi_SetOfficerType(characterFromID("Able Seaman Tompkins"));
			LAi_SetOfficerType(characterFromID("Able Seaman Stanley"));
			LAi_SetOfficerType(characterFromID("Able Seaman Wilks"));

			LAi_ActorRunToLocator(characterFromID("soldier1X"), "goto", "goto09", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier2X"), "goto", "goto10", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier3X"), "goto", "goto11", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier4X"), "goto", "goto12", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier5X"), "goto", "goto13", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier6X"), "goto", "goto14", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier7X"), "goto", "goto15", "", 40);
			LAi_ActorRunToLocator(characterFromID("soldier8X"), "goto", "goto02", "", 40);

			LAi_SetImmortal(CharacterFromID("Black Charlie Hammond"), true);
			LAi_SetImmortal(CharacterFromID("Thomas Wolfe"), true);
			LAi_SetImmortal(CharacterFromID("Lt. William Bush"), true);
			LAi_SetImmortal(CharacterFromID("Matthews"), true);

			LAi_ActorGoToLocator(characterFromID("Black Charlie Hammond"), "goto", "locator13", "", 40);
			LAi_ActorGoToLocator(characterFromID("Thomas Wolfe"), "goto", "citizen04", "", 40);

			Characters[GetCharacterIndex("Thomas Wolfe")].dialog.CurrentNode = "Hung_you";

			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(Pchar, "goto", "seaman2", "Meet_Wolfe_with_Hammond", 40.0);
		break;

		case "Meet_Wolfe_with_Hammond":
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Deal_with_them";
			LAi_ActorGoToLocator(characterFromID("Black Charlie Hammond"), "goto", "citizen04", "", 40);

			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			characters[GetCharacterIndex("Thomas Wolfe")].Dialog.Filename = "Thomas Wolfe_dialog.c";
			LAi_ActorDialogNow(characterFromID("Thomas Wolfe"),PChar,"",2.0);
		break;

		case "Hammond_Confesses":
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Black Charlie Hammond"),PChar,"",2.0);
		break;

		case "Hotspur_crew_arrives":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_group_MoveCharacter(characterFromID("Soldier1X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier1X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier2X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier3X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier3X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier4X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier4X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier5X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier5X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier6X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier6X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier7X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier7X"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Soldier8X"), LAI_GROUP_ENEMY);
			LAi_group_MoveCharacter(characterFromID("Soldier8X"), "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Styles"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Able Seaman Tompkins"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Able Seaman Stanley"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Able Seaman Wilks"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Lt. William Bush"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Matthews"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Marsh"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Perrin"), LAI_GROUP_PLAYER);
			LAi_QuestDelay("Hotspur_crew_arrives2", 0.0);
		break;

		case "Hotspur_crew_arrives2":
			Lai_KillCharacter(characterFromID("Jack Hammond"));
			SetCharacterRemovable(characterFromID("Jack Hammond"), true);
			RemovePassenger(pchar, characterFromID("Jack Hammond"));
			LAi_ActorRunToLocator(characterFromID("Thomas Wolfe"), "reload", "locator3_back", "", 40);
			LAi_ActorRunToLocator(characterFromID("Black Charlie Hammond"), "goto", "goto03", "", 40);

			PlaySound("VOICE\ENGLISH\Bush21.wav");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Hammond Suicide");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "Hammond Suicide":
			ChangeCharacterAddress(characterFromID("Styles"), "None", "");
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "What_have_I_done";
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator(Pchar, "goto", "goto07", "Hammond Suicide2", 10.0);
		break;

		case "Hammond Suicide2":
			ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Black Charlie Hammond"),PChar,"",2.0);
		break;

		case "Walk_to_death":
			Characters[GetCharacterIndex("Styles")].dialog.CurrentNode = "First time";
			Characters[GetCharacterIndex("Black Charlie Hammond")].dialog.CurrentNode = "Stop_Sir";
			LAi_ActorGoToLocator(characterFromID("Black Charlie Hammond"), "goto", "locator11", "Stop_Captain_Hammond", 10);
		break;

		case "Stop_Captain_Hammond":
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "We_did_our_bit";
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			characters[GetCharacterIndex("Black Charlie Hammond")].Dialog.Filename = "Black Charlie Hammond_dialog.c";
			LAi_ActorDialogNow(characterFromID("Black Charlie Hammond"),PChar,"",2.0);
		break;

		case "Hammond Suicide4":
//			LAi_ActorAnimation(characterFromID("Black Charlie Hammond"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_shoot3.wav");
			GetCharacterPos(characterFromID("Black Charlie Hammond"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_QuestDelay("Hammond Suicide5", 1.0);
		break;

		case "Hammond Suicide5":
			LAi_SetActorType(characterFromID("Black Charlie Hammond"));
			Lai_KillCharacter(characterFromID("Black Charlie Hammond"));
			LAi_QuestDelay("Hotspur_Finished_the_Job", 4.0);
			Locations[FindLocation("Guadeloupe_shore_01")].reload.l2.disable = 0; // Grey Roger: unlock the boat
		break;

		case "Hotspur_Finished_the_Job":
			PlaySound("OBJECTS\duel\Long_Fort_guns.wav");
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialogNow(characterFromID("Lt. William Bush"),PChar,"",2.0);
		break;

		case "After_the_fort_and_Hammond":
			AddQuestRecord("Old Friends - New Enemies", 16);
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetOfficerType(characterFromID("Styles"));
			LAi_SetOfficerType(characterFromID("Able Seaman Tompkins"));
			LAi_SetOfficerType(characterFromID("Able Seaman Stanley"));
			LAi_SetOfficerType(characterFromID("Able Seaman Wilks"));
			LAi_SetOfficerType(characterFromID("Matthews"));
			ChangeCharacterAddressGroup(characterFromID("Lt. Eccleston"), "Greenford_port", "goto", "goto13");

			SetCharacterRemovable(characterFromID("Styles"), false); // GR: Styles and Wilks remain in your crew but should not be assignable
			SetCharacterRemovable(characterFromID("Able Seaman Wilks"), false);

			Pchar.quest.Almost_end_of_Loyalty.win_condition.l1 = "location";
			PChar.quest.Almost_end_of_Loyalty.win_condition.l1.character = Pchar.id;
			Pchar.quest.Almost_end_of_Loyalty.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Almost_end_of_Loyalty.win_condition = "Almost_end_of_Loyalty";
		break;

		case "Almost_end_of_Loyalty":
			LAi_SetOfficerType(characterFromID("Lt. Eccleston"));

			ChangeCharacterAddress(characterFromID("Styles"), "None", "");
			ChangeCharacterAddress(characterFromID("Matthews"), "None", "");
			ChangeCharacterAddress(characterFromID("Black Charlie Hammond"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. William Bush"), "None", "");
			ChangeCharacterAddress(characterFromID("Marsh"), "None", "");
			ChangeCharacterAddress(characterFromID("Perrin"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Tompkins"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Stanley"), "None", "");
			ChangeCharacterAddress(characterFromID("Able Seaman Wilks"), "None", "");
			ChangeCharacterAddress(characterFromID("Jack Hammond"), "None", "");
			LAi_QuestDelay("Flagship_behind_you", 0.0);
		break;

		case "Flagship_behind_you":
			LAi_SetActorType(characterFromID("Lt. Eccleston"));
			characters[GetCharacterIndex("Lt. Eccleston")].Dialog.Filename = "Lt. Eccleston_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Eccleston"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Eccleston")].dialog.CurrentNode = "Pellew_from_flagship";
		break;

		case "Make_Guadeloupe_Report":
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Cabin2SJG", "rld", "aloc2");
			SetCurrentTime(09.00, 0);
			LAi_Fade("", "");
			LAi_SetActorType(pchar);
			DoQuestReloadToLocation("Cabin2SJG", "reload", "reload1", "Flagship_Greenford_Guadeloupe");
		break;

		case "Flagship_Greenford_Guadeloupe":
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "In_Your_Report";
			LAi_ActorGoToLocator((Pchar), "rld", "aloc6", "After_Guadeloupe_Battle", 10);
		break;

		case "After_Guadeloupe_Battle":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			LAi_ActorDialogNow(characterFromID("Sir Edward Pellew"),PChar,"",1.0);
		break;

		case "Propose_to_Maria":
			LAi_Fade("", "");
			ChangeCharacterAddressGroup(characterFromID("Mrs. Mason"), "Mrs. Mason's House", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Maria Mason"), "Mrs. Mason's House", "goto", "goto3");
			DoQuestReloadToLocation("Greenford_port", "reload", "reload1", "Propose_to_Maria2");
		break;

		case "Propose_to_Maria2":
			AddQuestRecord("Old Friends - New Enemies", 17);
			Locations[FindLocation("Mrs. Mason's House")].vcskip = true;
			Locations[FindLocation("Greenford_town")].reload.l20.disable = 0;
			Pchar.quest.Propose_to_Maria3.win_condition.l1 = "location";
			PChar.quest.Propose_to_Maria3.win_condition.l1.character = Pchar.id;
			Pchar.quest.Propose_to_Maria3.win_condition.l1.location = "Mrs. Mason's House";
			Pchar.quest.Propose_to_Maria3.win_condition = "Propose_to_Maria3";
		break;

		case "Propose_to_Maria3":
			Locations[FindLocation("Mrs. Mason's House")].reload.l1.disable = 1;
			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Maria Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "Saw_the_Hotspur";
		break;

		case "Mother_tells":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator((Pchar), "goto", "goto1", "Mother_tells2", 4.0);
		break;

		case "Mother_tells2":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Mrs. Mason"));
			characters[GetCharacterIndex("Mrs. Mason")].Dialog.Filename = "Mrs. Mason_dialog.c";
			LAi_ActorDialog(characterFromID("Mrs. Mason"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "She_wept";
		break;

		case "Gone_and_done_it":
			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Maria Mason_dialog.c";
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "Marry_me";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"Prepare_for_wedding",5.0,5.0);
			Locations[FindLocation("Mrs. Mason's House")].reload.l1.disable = 0;
			NPChar = characterFromID("Maria Mason");
			NPChar.married = MR_SINGLE;
			Locations[FindLocation("Greenford_town")].reload.l1.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l2.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l3.disable = 1;
			DisableFastTravel(true);
		break;

		case "Prepare_for_wedding":
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "Prepare_for_wedding";
			LAi_ActorDialog(characterFromID("Mrs. Mason"),PChar,"Church_marriage_scene",5.0,5.0);
		break;

		case "Church_marriage_scene":
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10.00, 0);
			LAi_Fade("", "");
			ChangeCharacterAddress(characterFromID("Maria Mason"), "None", "");
			AddQuestRecord("Old Friends - New Enemies", 18);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Lt. William Bush"));
			SetCharacterRemovable(characterFromID("Lt. William Bush"), false);
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Greenford_church", "sit", "sit14");
			LAi_ActorSetSitMode(characterFromID("Lt. William Bush"));

			LAi_SetActorType(characterFromID("Mrs. Mason"));
			ChangeCharacterAddressGroup(characterFromID("Mrs. Mason"), "Greenford_church", "sit", "sit1");

			Locations[FindLocation("Greenford_church")].locators_radius.goto.goto11 = 2.0;
			Pchar.quest.Wedding_ceremony.win_condition.l1 = "locator";
//			PChar.quest.Wedding_ceremony.win_condition.l1.character = Pchar.id;
			Pchar.quest.Wedding_ceremony.win_condition.l1.location = "Greenford_church";
			Pchar.quest.Wedding_ceremony.win_condition.l1.locator_group = "goto";
			Pchar.quest.Wedding_ceremony.win_condition.l1.locator = "goto11";
			Pchar.quest.Wedding_ceremony.win_condition = "Wedding_ceremony";
		break;

		case "Wedding_ceremony":
			PauseAllSounds();
			PlayStereoOGG("wedding");
			LAi_SetActorType(PChar);
			LAi_SetActorType(characterFromID("Maria Mason"));
			ChangeCharacterAddressGroup(characterFromID("Maria Mason"), "Greenford_church", "reload", "reload1");
			LAi_ActorTurnToCharacter(PChar, characterFromID("Maria Mason"));
			LAi_SetOfficerType(characterFromID("Maria Mason"));
			LAi_QuestDelay("Wedding_ceremony2", 5.0);
		break;

		case "Wedding_ceremony2":
			LAi_SetPlayerType(PChar);
//			LAi_SetOfficerType(characterFromID("Maria Mason"));
			LAi_ActorFollowEverywhere(CharacterFromID("Maria Mason"), "", 1.0);
			PChar.quest.bride = GetMyFullName(characterFromID("Maria Mason"));
			LAi_SetActorType(characterFromID("Father Jerald"));
			characters[GetCharacterIndex("Father Jerald")].Dialog.Filename = "Father Jerald_dialog.c";
			Characters[GetCharacterIndex("Father Jerald")].dialog.CurrentNode = "wedding";
			LAi_ActorDialog(characterFromID("Father Jerald"),PChar,"Wedding_ceremony3",5.0,5.0);
		break;

		case "Wedding_ceremony3":
			LAi_SetActorType(characterFromID("Mrs. Mason"));
			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Gov MR_dialog.c";
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "her_answer";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"leave_church",5.0,5.0);
		break;

		case "leave_church":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Greenford_church", "goto", "goto7");
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			ChangeCharacterAddressGroup(characterFromID("Mrs. Mason"), "Greenford_church", "goto", "goto6");
			LAi_ActorFollowEverywhere(CharacterFromID("Maria Mason"), "", 1.0);
			LAi_ActorFollowEverywhere(CharacterFromID("Mrs. Mason"), "", 1.0);
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "marriage_congrats";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"Married",1.0,1.0);
		break;

		case "Married":
			characters[GetCharacterIndex("Maria Mason")].married = MR_MARRIED;
			characters[GetCharacterIndex("Maria Mason")].quest.meeting = "1"
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Gov MR_dialog.c";
			characters[GetCharacterIndex("Maria Mason")].Dialog.CurrentNode = "First time";
			characters[GetCharacterIndex("Maria Mason")].talkpoints = 0;
			characters[GetCharacterIndex("Maria Mason")].marpoints = 1;
			characters[GetCharacterIndex("Maria Mason")].pcounter = 0;
			characters[GetCharacterIndex("Maria Mason")].lastname = TranslateString("","Hornblower");
//			LAi_SetStayType(characterFromID("Maria Mason"));
			PChar.married = MR_MARRIED;
			PChar.married.id = "Maria Mason";

			Pchar.quest.take_women_home.win_condition.l1 = "location";
			PChar.quest.take_women_home.win_condition.l1.character = Pchar.id;
			Pchar.quest.take_women_home.win_condition.l1.location = "Greenford_town";
			Pchar.quest.take_women_home.win_condition = "take_women_home";
		break;

		case "take_women_home":
			LAi_SetActorType(characterFromID("Mrs. Mason"));
			characters[GetCharacterIndex("Mrs. Mason")].Dialog.Filename = "Mrs. Mason_dialog.c";
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "go_home";
			LAi_ActorDialog(characterFromID("Mrs. Mason"),PChar,"take_women_home2",5.0,5.0);
		break;

		case "take_women_home2":
			characters[GetCharacterIndex("Mrs. Mason")].name = TranslateString("","Ellen");
			ChangeCharacterAddress(characterFromID("Lt. William Bush"), "None", "");
			LAi_SetPriestType(characterFromID("Father Jerald"));
			LAi_SetOfficerType(CharacterFromID("Mrs. Mason"));
			LAi_ActorFollowEverywhere(CharacterFromID("Mrs. Mason"), "", 1.0);
			Pchar.quest.firstnight.win_condition.l1 = "location";
			PChar.quest.firstnight.win_condition.l1.character = Pchar.id;
			Pchar.quest.firstnight.win_condition.l1.location = "Mrs. Mason's House";
			Pchar.quest.firstnight.win_condition = "firstnight";
		break;

		case "firstnight":
			Locations[FindLocation("Mrs. Mason's House")].reload.l1.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Mrs. Mason"), "Mrs. Mason's House", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Maria Mason"), "Mrs. Mason's House", "goto", "goto3");
			LAi_SetActorType(characterFromID("Mrs. Mason"));
			characters[GetCharacterIndex("Mrs. Mason")].Dialog.Filename = "Mrs. Mason_dialog.c";
			Characters[GetCharacterIndex("Mrs. Mason")].dialog.CurrentNode = "leave_them_alone";
			LAi_ActorDialog(characterFromID("Mrs. Mason"),PChar,"leave_them_alone",5.0,5.0);
			LAi_SetStayType(characterFromID("Maria Mason"));
		break;

		case "leave_them_alone":
			LAi_Fade("", "");
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10.00, 0);
			Locations[FindLocation("Greenford_town")].reload.l1.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l2.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l3.disable = 0;
			DisableFastTravel(false);
			LAi_QuestDelay("next_morning", 2.0);
		break;

		case "next_morning":
			SetCharacterRemovable(characterFromID("Lt. William Bush"), true);
			Locations[FindLocation("Mrs. Mason's House")].reload.l1.disable = 0;
			Pchar.quest.Assigned_to_atropos.win_condition.l1 = "location";
			PChar.quest.Assigned_to_atropos.win_condition.l1.character = Pchar.id;
			Pchar.quest.Assigned_to_atropos.win_condition.l1.location = "Greenford_town";
			Pchar.quest.Assigned_to_atropos.win_condition = "Assigned_to_atropos";
		break;

		case "Assigned_to_atropos":
			Locations[FindLocation("Greenford_town")].reload.l19.disable = 0;
			ChangeCharacterAddressGroup(characterFromID("Lt. Chadd"), "Greenford_town", "goto", "goto31");
			LAi_SetOfficerType(characterFromID("Lt. Chadd"));
			LAi_SetActorType(characterFromID("Lt. Chadd"));
			characters[GetCharacterIndex("Lt. Chadd")].Dialog.Filename = "Lt. Chadd_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. Chadd"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. Chadd")].dialog.CurrentNode = "Report_to_HQ";
		break;

		case "assigned_to_atropos2":
			LAi_ActorGotoLocator(characterFromID("Lt. Chadd"),"officers", "reload10_2", "", 30.0);
	
			PChar.quest.Assigned_to_atropos.win_condition.l1 = "location";
			PChar.quest.Assigned_to_atropos.win_condition.l1.character = PChar.id;
			Pchar.quest.Assigned_to_atropos.win_condition.l1.location = "Greenford Naval HQ";
			Pchar.quest.Assigned_to_atropos.win_condition = "assigned_to_atropos3";
		break;

		case "assigned_to_atropos3":
			ChangeCharacterAddressGroup(characterFromID("Lt. Eccleston"), "Greenford Naval HQ", "sit", "sit1");
			LAi_ActorSetSitMode(characterFromID("Lt. Eccleston"));
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Greenford Naval HQ", "goto", "goto4");
			ChangeCharacterAddress(characterFromID("Lt. Chadd"), "None", "");
			LAi_QuestDelay("Waiting_for_you", 2.0);
		break;

		case "Waiting_for_you":
			characters[GetCharacterIndex("Lt. Eccleston")].Dialog.Filename = "Lt. Eccleston_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Eccleston"));
			Characters[GetCharacterIndex("Lt. Eccleston")].dialog.CurrentNode = "Hes_waiting";
			LAi_ActorDialog(characterFromID("Lt. Eccleston"), pchar, "assigned_to_atropos4", 10.0, 10.0);
		break;

		case "assigned_to_atropos4":
			LAi_ActorSetSitMode(characterFromID("Lt. Eccleston"));
			LAi_SetGuardianType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
//			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "Give_atropos";
		break;

		case "assigned_to_atropos5":
			ReceiveLetterOfMarque(ENGLAND);							// PB: Enable regular governor dialogs
//			DeleteAttribute(PChar, "isnotcaptain");						// PB: Return to normal play
			AddStorylineVar(FindCurrentStoryline(), "CHANGING_RELATIONS", "1");		// PB: Enable changing nation relations
			GiveShip2Character(pchar, "HMS_Greyhound", "Atropos", -1, ENGLAND, true, true); // 6th Rate Frigate
			AddQuestRecord("Old Friends - New Enemies", 19);
			LAi_QuestDelay("End_of_story", 0.1);
		break;

		case "End_of_story":
			CloseQuestHeader("Old Friends - New Enemies");
			LAi_QuestDelay("wolfes_ship", 0.1);

			Locations[FindLocation("Santo_Domingo_town")].reload.l25.disable = 0;		// "Crystal Skull" sidequest now available

//			ChangeCharacterAddressGroup(characterFromID("Sir Rodney Leighton"), "Redmond Naval HQ", "goto", "goto3");
//			setCharacterShipLocation(characterFromID("Sir Rodney Leighton"), "Redmond_port");
		break;

		case "wolfes_ship":
			pchar.quest.know_about_Wolfe = "None";
			GiveShip2Character(characterFromID("Teresa Moreno"),"FR_Sloop","Le Rève",-1,FRANCE,true,true);
			setCharacterShipLocation(characterFromID("Teresa Moreno"), "Charlestown_port");
			ChangeCharacterAddressGroup(characterFromID("Teresa Moreno"), "Mystery_House", "goto", "goto5");
			LAi_SetGuardianType(characterFromID("Teresa Moreno"));
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "looking_for_Wolfe";
			ChangeCharacterAddressGroup(characterFromID("Major Hogan"), "Guadeloupe_Plantation_inside", "goto", "goto8");
			LAi_SetGuardianType(characterFromID("Major Hogan"));
			Characters[GetCharacterIndex("Major Hogan")].dialog.CurrentNode = "looking_for_Wolfe";

			LAi_SetImmortal(characterFromID("Thomas Wolfe"), false);
			characters[GetCharacterIndex("Thomas Wolfe")].nation = FRANCE
			SetRMRelation(characterFromID("Thomas Wolfe"), ENGLAND, REL_WAR);
			GiveShip2Character(characterFromID("Thomas Wolfe"), "FR_Sloop", "Loup-Garou", -1, FRANCE, true, true);

			Group_CreateGroup("wolfes_Ship"); 
			Group_AddCharacter("wolfes_Ship", "Thomas Wolfe");
			Group_SetGroupCommander("wolfes_Ship", "Thomas Wolfe");
//			Group_SetPursuitGroup("wolfes_Ship", PLAYER_GROUP);
			Group_SetTaskAttack("wolfes_Ship",  PLAYER_GROUP, true);
			Group_LockTask("wolfes_Ship");
			Group_SetAddress("wolfes_Ship", "FalaiseDeFleur", "Quest_Ships","Quest_Ship_9"); 
			Sea_LoginGroupNow("wolfes_Ship");
			characters[GetCharacterIndex("Thomas Wolfe")].nosurrender = 2;
			SetCharacterRelationBoth(GetCharacterIndex("Thomas Wolfe"),GetMainCharacterIndex(),RELATION_ENEMY);

			Pchar.quest.Meet_Wolfeship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Wolfeship.win_condition.l1.character = "Thomas Wolfe";
			Pchar.quest.Meet_Wolfeship.win_condition = "capture_wolfe";
		break;

		case "capture_wolfe":
			if(CheckQuestAttribute("know_about_Wolfe", "None")) SetQuestHeader("Hunt the Traitors");
			AddQuestRecord("Hunt the Traitors", 2);
			pchar.quest.know_about_Wolfe = "got_him";
			Characters[GetCharacterIndex("Teresa Moreno")].dialog.CurrentNode = "First time";
			Characters[GetCharacterIndex("Major Hogan")].dialog.CurrentNode = "First time";
			Pchar.quest.imprison_wolfe.win_condition.l1 = "location";
			PChar.quest.imprison_wolfe.win_condition.l1.character = Pchar.id;
			Pchar.quest.imprison_wolfe.win_condition.l1.location = "Greenford_port";
			Pchar.quest.imprison_wolfe.win_condition = "bush_locks_up_wolfe"
		break;

		case "bush_locks_up_wolfe":
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Greenford_prison", "goto", "goto9");
			RemoveCharacterEquip(characterFromID("Thomas Wolfe"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Thomas Wolfe"), GUN_ITEM_TYPE);
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Greenford_port", "goto", "goto13");
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_QuestDelay("bush_reports", 0.0);
		break;

		case "bush_reports":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			characters[GetCharacterIndex("Lt. William Bush")].Dialog.Filename = "Lt. William Bush_dialog.c";
			LAi_ActorDialog(characterFromID("Lt. William Bush"),PChar,"",5.0,5.0);
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "wolfe_prison";
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Greenford_prison", "officers", "reload1_1");
		break;

		case "wolfe_locked_up":
			AddQuestRecord("Hunt the Traitors", 3);
			Pchar.quest.interrogate_wolfe.win_condition.l1 = "location";
			PChar.quest.interrogate_wolfe.win_condition.l1.character = Pchar.id;
			Pchar.quest.interrogate_wolfe.win_condition.l1.location = "Greenford_prison";
			Pchar.quest.interrogate_wolfe.win_condition = "interrogation_wolfe_start";
		break;

		case "interrogation_wolfe_start":
			characters[GetCharacterIndex("Thomas Wolfe")].name = TranslateString("","Thomas");
			characters[GetCharacterIndex("Thomas Wolfe")].lastname = TranslateString("","Wolfe");
			ChangeCharacterAddress(characterFromID("Lt. William Bush"), "None", "");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.Filename = "Richard Sharpe_Dialog.c";
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "lets_talk_to_wolfe";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
		break;

		case "interrogate_wolfe1":
			LAi_ActorGotoLocator(characterFromID("Richard Sharpe"),"goto", "goto23", "", 30.0);
			pchar.quest.wolfe_in_jail1.win_condition.l1 = "locator";
			pchar.quest.wolfe_in_jail1.win_condition.l1.location = "Greenford_prison";
			pchar.quest.wolfe_in_jail1.win_condition.l1.locator_group = "reload";
			pchar.quest.wolfe_in_jail1.win_condition.l1.locator = "reload12";
			pchar.quest.wolfe_in_jail1.win_condition = "interrogate_wolfe1a";
		break;

		case "interrogate_wolfe1a":
			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"), pchar);
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			Characters[GetCharacterIndex("Thomas Wolfe")].Dialog.Filename = "Thomas Wolfe_Dialog.c";
			Characters[GetCharacterIndex("Thomas Wolfe")].Dialog.CurrentNode = "turnabout";
			LAi_ActorDialogNow(characterFromID("Thomas Wolfe"),PChar,"",2.0);
		break;

		case "interrogate_wolfe2":
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "bad_cop";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
		break;

		case "interrogate_wolfe3":
			Characters[GetCharacterIndex("Thomas Wolfe")].Dialog.CurrentNode = "good_cop";
			LAi_ActorDialogNow(characterFromID("Thomas Wolfe"),PChar,"",2.0);
		break;

		case "release_wolfe":
			AddQuestRecord("Hunt the Traitors", 4);
			Characters[GetCharacterIndex("Greenford Prison Commendant")].Dialog.CurrentNode = "release_wolfe";
		break;

		case "take_wolfe":
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Greenford_prison", "goto", "goto23");
			LAi_ActorGotoLocator(characterFromID("Thomas Wolfe"),"officers", "reload1_2", "", 30.0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Richard Sharpe"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			Pchar.quest.wolfe_out_of_jail.win_condition.l1 = "location";
			PChar.quest.wolfe_out_of_jail.win_condition.l1.character = Pchar.id;
			Pchar.quest.wolfe_out_of_jail.win_condition.l1.location = "Greenford_town";
			Pchar.quest.wolfe_out_of_jail.win_condition = "wolfe_out_of_jail";
		break;

		case "wolfe_out_of_jail":
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Greenford_town", "officers", "reload27_2");
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			LAi_ActorFollowEverywhere(CharacterFromID("Thomas Wolfe"), "", 0.0);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "bad_cop2";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			AddQuestRecord("Hunt the Traitors", 5);
		break;

		case "off_to_meet_quelp":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			AddPassenger(Pchar, characterFromID("Patrick Harper"), 0);
			AddPassenger(Pchar, characterFromID("Rifleman Haggman"), 0);
			SetCharacterRemovable(characterFromID("Patrick Harper"), false);
			SetCharacterRemovable(characterFromID("Rifleman Haggman"), false);
			pchar.quest.To_Hispaniola_shore_Quelp.win_condition.l1 = "location";
			Pchar.quest.To_Hispaniola_shore_Quelp.win_condition.l1.character = Pchar.id;
			pchar.quest.To_Hispaniola_shore_Quelp.win_condition.l1.location = "Hispaniola_shore_01";
			pchar.quest.To_Hispaniola_shore_Quelp.win_condition = "Hispaniola_shore_for_Quelp";
		break;

		case "Hispaniola_shore_for_Quelp":
			DisableFastTravel(true);
			Locations[FindLocation("Hispaniola_shore_01")].reload.l2.disable = 1;
			characters[GetCharacterIndex("Rifleman Haggman")].lastname = TranslateString("","Haggman");
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Hispaniola_shore_01", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Hispaniola_shore_01", "officers", "reload1_2");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Hispaniola_shore_01", "officers", "reload1_3");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			LAi_ActorFollowEverywhere(CharacterFromID("Thomas Wolfe"), "", 0.0);
			GiveItem2Character(characterFromID("Patrick Harper"), "bladeC35+2"); // GR: I don't know where Harper got a Hibernian.
			EquipCharacterByItem(characterFromID("Patrick Harper"), "bladeC35"); // Neither does Sharpe, and he probably doesn't want to!
			if (!CheckCharacterItem(characterFromID("Richard Sharpe"), "blade24")) GiveItem2Character(pchar, "blade24+3");
			EquipCharacterByItem(characterFromID("Richard Sharpe"), "blade24");
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Patrick Harper"));
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Rifleman Haggman"));
			SetCharacterRemovable(characterFromID("Richard Sharpe"), false);
			SetCharacterRemovable(characterFromID("Patrick Harper"), false);
			SetCharacterRemovable(characterFromID("Rifleman Haggman"), false);
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "bring_Harper_Haggman";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0); // Dialog exits to "proceed_to_jungle"
		break;

		case "proceed_to_jungle":
			Characters[GetCharacterIndex("Thomas Wolfe")].Dialog.Filename = "Thomas Wolfe_Dialog.c";
			Characters[GetCharacterIndex("Thomas Wolfe")].Dialog.CurrentNode = "where_now";
			LAi_ActorDialogNow(characterFromID("Thomas Wolfe"),PChar,"proceed_to_jungle2",2.0);
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Hispaniola_Jungle_08", "goto", "goto4");
			NPChar = characterFromID("Lt. Uriah Quelp");
			NPChar.perks.list.BasicDefence = true;
			NPChar.perks.list.AdvancedDefence = true;
			NPChar.perks.list.SwordplayProfessional = true;
			NPChar.perks.list.CriticalHit = true;
			NPChar.Perks.list.Toughness = true;
			GiveItem2Character(characterFromID("Lt. Uriah Quelp"), "blade9");
			EquipCharacterByItem(characterFromID("Lt. Uriah Quelp"), "blade9");
			GiveItem2Character(characterFromID("Lt. Uriah Quelp"), "pistol2");
			EquipCharacterByItem(characterFromID("Lt. Uriah Quelp"), "pistol2");
			GiveItem2Character(characterFromID("Lt. Uriah Quelp"), "commonarmor");
		break;

		case "proceed_to_jungle2":
			Locations[FindLocation("Hispaniola_Jungle_08")].vcskip = true;
			AddQuestRecord("Hunt the Traitors", 6);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Rifleman Haggman"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_ActorFollowEverywhere(CharacterFromID("Thomas Wolfe"), "", 0.0);
			LAi_SetOfficerType(characterFromID("Thomas Wolfe"));
			LAi_QuestDelay("proceed_to_jungle3", 0.0);
		break;

		case "proceed_to_jungle3":
			pchar.quest.To_Hispaniola_jungle_Quelp.win_condition.l1 = "location";
			Pchar.quest.To_Hispaniola_jungle_Quelp.win_condition.l1.character = Pchar.id;
			pchar.quest.To_Hispaniola_jungle_Quelp.win_condition.l1.location = "Hispaniola_Jungle_08";
			pchar.quest.To_Hispaniola_jungle_Quelp.win_condition = "quelp_at_windmill";			
		break;

		case "quelp_at_windmill":
			ChangeCharacterAddressGroup(characterFromID("Thomas Wolfe"), "Hispaniola_Jungle_08", "reload", "reload2_back");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "Harper_Haggman_cover";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
			Locations[FindLocation("Hispaniola_Jungle_08")].reload.l4.disable = 1; // Close exits so player can't leave
			Locations[FindLocation("Hispaniola_Jungle_08")].reload.l5.disable = 1; // the area and break the sequence
			Locations[FindLocation("Hispaniola_Jungle_08")].reload.l6.disable = 1;	
		break;

		case "quelp_at_windmill2":
			LAi_SetActorType(PChar);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_ActorRuntoLocator(characterFromID("Rifleman Haggman"), "monsters", "monster2", "", 30.0);
			LAi_ActorRuntoLocator(characterFromID("Patrick Harper"), "monsters", "monster3", "", 30.0);
			LAi_ActorGoToLocator(Pchar, "goto", "goto5", "quelp_at_windmill3", 30.0);		
		break;

		case "quelp_at_windmill3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.CurrentNode = "showdown1";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
		break;

		case "kill_wolfe":
			LAi_ActorAnimation(characterFromID("Lt. Uriah Quelp"), "shot", "", 0.0);
			PlaySound("OBJECTS\duel\pistol_medium2.wav");
			GetCharacterPos(characterFromID("Lt. Uriah Quelp"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_QuestDelay("kill_wolfe2", 0.0);
		break;

		case "kill_wolfe2":
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			Lai_KillCharacter(characterFromID("Thomas Wolfe"));
			LAi_QuestDelay("wolfe_dead", 0.0);
		break;

		case "wolfe_dead":
			LAi_QuestDelay("Voltigeurs_arrive", 1.0);
		break;

		case "voltigeurs_arrive":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "officers", "reload1_1");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
//			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur1";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "officers", "reload1_2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
//			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur2";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "officers", "reload1_3");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
//			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur3";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "goto2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
//			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur4";
			LAi_QuestDelay("see_the_voltigeurs", 0.0);
		break;

		case "see_the_voltigeurs":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, characterFromID("voltigeur1"));
			LAi_QuestDelay("Quelp_explains", 1.0);
		break;

		case "Quelp_explains":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Lt. Uriah Quelp")].Dialog.CurrentNode = "Quelps_plot";
			LAi_ActorDialog(characterFromID("Lt. Uriah Quelp"),PChar,"",5.0,5.0);
		break;

		case "Sharpe_knows_theyre_French":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "theyre_not_British";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"",5.0,5.0);
		break;

		case "Harper_Haggman_fire":
			LAi_ActorAnimation(characterFromID("Patrick Harper"), "shot", "", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Patrick Harper"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			Lai_KillCharacter(characterFromID("voltigeur2"));
			LAi_ActorAnimation(characterFromID("Rifleman Haggman"), "shot", "voltigeurs_fire", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("Rifleman Haggman"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			Lai_KillCharacter(characterFromID("voltigeur3"));
			LAi_ActorRunToLocator(characterFromID("Richard Sharpe"), "goto", "goto3", "", 40);
		break;

		case "voltigeurs_fire":
			LAi_SetActorType(characterFromID("voltigeur1"));
			LAi_SetActorType(characterFromID("voltigeur4"));
			LAi_ActorAnimation(characterFromID("voltigeur1"), "shot", "", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("voltigeur1"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
			LAi_ActorAnimation(characterFromID("voltigeur4"), "shot", "chosen_vs_voltigeurs1", 1.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
			GetCharacterPos(characterFromID("voltigeur4"), &locx, &locy, &locz);
			CreateParticleSystemX("gunfire", locx, (locy + 1), locz, locx, (locy + 1), locz,5);
//			SetCharacterRemovable(characterFromID("Rifleman Haggman"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rifleman Haggman"));
			LAi_SetStunnedTypeNoGroup(characterFromID("Rifleman Haggman"));
		break;

		case "chosen_vs_voltigeurs1":
			LAi_SetWarriorType(characterFromID("Richard Sharpe"));
			LAi_SetWarriorType(characterFromID("Patrick Harper"));

			LAi_group_MoveCharacter(characterFromID("voltigeur1"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("voltigeur4"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Richard Sharpe"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Patrick Harper"), LAI_GROUP_PLAYER);
			LAi_SetImmortal(characterFromID("Patrick Harper"), false); 
			LAi_QuestDelay("fight_Quelp", 0.0);
		break;

		case "fight_Quelp":
			LAi_SetFightMode(PChar, true);

			LAi_ActorAttack(characterfromID("Lt. Uriah Quelp"), PChar, "");

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
//			LAi_group_SetCheck("FRANCE_SOLDIERS", "end_of_skirmish1");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";

			PChar.quest.end_of_skirmish1.win_condition.l1 = "NPC_Death";
			PChar.quest.end_of_skirmish1.win_condition.l1.character = "Lt. Uriah Quelp";
			PChar.quest.end_of_skirmish1.win_condition.l2 = "NPC_Death";
			PChar.quest.end_of_skirmish1.win_condition.l2.character = "voltigeur1";
			PChar.quest.end_of_skirmish1.win_condition.l3 = "NPC_Death";
			PChar.quest.end_of_skirmish1.win_condition.l3.character = "voltigeur2";
			PChar.quest.end_of_skirmish1.win_condition.l4 = "NPC_Death";
			PChar.quest.end_of_skirmish1.win_condition.l4.character = "voltigeur3";
			PChar.quest.end_of_skirmish1.win_condition.l5 = "NPC_Death";
			PChar.quest.end_of_skirmish1.win_condition.l5.character = "voltigeur4";
			PChar.quest.end_of_skirmish1.win_condition = "end_of_skirmish1";	
		break;

		case "end_of_skirmish1":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetFightMode(PChar, false);
			Characters[GetCharacterIndex("Rifleman Haggman")].Dialog.CurrentNode = "are_you_alright";
			LAi_ActorDialog(characterFromID("Rifleman Haggman"),PChar,"end_of_skirmish2",5.0,5.0);
		break;

		case "end_of_skirmish2":
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "reload", "reload2_back", "", 30.0);
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "no_officer";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"end_of_skirmish3",5.0,5.0);
		break;

		case "end_of_skirmish3":
			AddQuestRecord("Hunt the Traitors", 7);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			Locations[FindLocation("Hispaniola_Jungle_08")].reload.l4.disable = 0; // re-open exits
			Locations[FindLocation("Hispaniola_Jungle_08")].reload.l5.disable = 0;
			Locations[FindLocation("Hispaniola_Jungle_08")].reload.l6.disable = 0;
			Locations[FindLocation("Santo_Domingo_town_exit_1")].vcskip = true;
			pchar.quest.wrong_way_voltigeurs.win_condition.l1 = "location";
			Pchar.quest.wrong_way_voltigeurs.win_condition.l1.character = Pchar.id;
			pchar.quest.wrong_way_voltigeurs.win_condition.l1.location = "Hispaniola_village_Exit";
			pchar.quest.wrong_way_voltigeurs.win_condition = "wrong_way_to_voltigeurs";
			pchar.quest.right_way_voltigeurs.win_condition.l1 = "location";
			Pchar.quest.right_way_voltigeurs.win_condition.l1.character = Pchar.id;
			pchar.quest.right_way_voltigeurs.win_condition.l1.location = "Santo_Domingo_town_exit_1";
			pchar.quest.right_way_voltigeurs.win_condition = "right_way_to_voltigeurs";
		break;

		case "wrong_way_to_voltigeurs":
			Pchar.quest.right_way_voltigeurs.over = "yes";
			ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "wrong_way";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"wrong_way_to_voltigeurs2",5.0,5.0);
		break;

		case "wrong_way_to_voltigeurs2":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_QuestDelay("move_reinforcements", 0.0);
		break;

		case "right_way_to_voltigeurs":
			Pchar.Quest.wrong_way_voltigeurs.over = "yes";
			Locations[FindLocation("Santo_Domingo_town_exit_1")].reload.l3.disable = 1;
			ChangeCharacterAddress(characterFromID("Thomas Wolfe"), "None", "");
			ChangeCharacterAddress(characterFromID("Lt. Uriah Quelp"), "None", "");

			LAi_SetActorType(characterFromID("Patrick Harper"));
			Characters[GetCharacterIndex("Patrick Harper")].Dialog.CurrentNode = "right_way";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"Harper_goes_scouting",5.0,5.0);
		break;

		case "Harper_goes_scouting":
			LAi_ActorRuntoLocator(characterFromID("Patrick Harper"), "monsters", "monster3", "Harper_returns", 30.0);
		break;

		case "Harper_returns":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Patrick Harper"));
			Characters[GetCharacterIndex("Patrick Harper")].Dialog.CurrentNode = "back_from_scouting";
			LAi_ActorDialog(characterFromID("Patrick Harper"),PChar,"right_way_to_voltigeurs2",30.0,5.0);
		break;

		case "right_way_to_voltigeurs2":
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			Locations[FindLocation("Santo_Domingo_town_exit_1")].reload.l3.disable = 0;
			LAi_QuestDelay("move_reinforcements", 0.0);
		break;

		case "move_reinforcements":
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Hispaniola_Jungle_08", "officers", "reload2_1");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Hispaniola_Jungle_08", "officers", "reload2_2");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Hispaniola_Jungle_08", "officers", "reload2_3");
			pchar.quest.meet_reinforcements.win_condition.l1 = "location";
			Pchar.quest.meet_reinforcements.win_condition.l1.character = Pchar.id;
			pchar.quest.meet_reinforcements.win_condition.l1.location = "Hispaniola_Jungle_08";
			pchar.quest.meet_reinforcements.win_condition = "meet_reinforcements";
		break;

		case "meet_reinforcements":
			LAi_SetOfficerType(characterFromID("Rifleman Higgins"));
			LAi_SetOfficerType(characterFromID("Rifleman Tongue"));
			Locations[FindLocation("Hispaniola_Jungle_08")].reload.l6.disable = 1;
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "here_come_reinforcements";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"meet_reinforcements2",5.0,5.0);
		break;

		case "meet_reinforcements2":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Rifleman Cooper")].Dialog.CurrentNode = "Here_to_help";
			LAi_ActorDialog(characterFromID("Rifleman Cooper"),PChar,"meet_reinforcements3",30.0,5.0);
		break;

		case "meet_reinforcements3":
			Locations[FindLocation("Hispaniola_Jungle_08")].reload.l6.disable = 0;
			LAi_SetOfficerType(characterFromID("Rifleman Cooper"));
			LAi_SetImmortal(characterFromID("Rifleman Higgins"), false);
			LAi_SetImmortal(characterFromID("Rifleman Tongue"), false); 
			pchar.quest.fight_more_voltigeurs.win_condition.l1 = "location";
			Pchar.quest.fight_more_voltigeurs.win_condition.l1.character = Pchar.id;
			pchar.quest.fight_more_voltigeurs.win_condition.l1.location = "Santo_Domingo_town_exit_1";
			pchar.quest.fight_more_voltigeurs.win_condition = "fight_more_voltigeurs";
		break;

		case "fight_more_voltigeurs":
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Santo_Domingo_town_exit_1", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Higgins"), "Santo_Domingo_town_exit_1", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Cooper"), "Santo_Domingo_town_exit_1", "reload", "reload1_back");

			Locations[FindLocation("Santo_Domingo_town_exit_1")].reload.l1.disable = 1;
			Locations[FindLocation("Santo_Domingo_town_exit_1")].reload.l3.disable = 1;

			LAi_SetActorType(characterFromID("Donatien Thibaud"));
			ChangeCharacterAddressGroup(characterFromID("Donatien Thibaud"), "Santo_Domingo_town_exit_1", "goto", "goto3");
			Characters[GetCharacterIndex("Donatien Thibaud")].Dialog.Filename = "Donatien Thibaud_dialog.c";
			GiveItem2Character(characterFromID("Donatien Thibaud"), "blade51");
			EquipCharacterByItem(characterFromID("Donatien Thibaud"), "blade51");

			sld = LAi_CreateFantomCharacter(false, -10, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur5";
			sld = LAi_CreateFantomCharacter(false, -10, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto3");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur6";
			sld = LAi_CreateFantomCharacter(false, -10, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto1");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur7";
			sld = LAi_CreateFantomCharacter(false, -10, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "goto2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur8";
			sld = LAi_CreateFantomCharacter(false, -10, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "goto", "goto3");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur9";
			sld = LAi_CreateFantomCharacter(false, -10, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto1");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
			GiveItem2Character(sld, "LongRifle_H");
			EquipCharacterByItem(sld, "LongRifle_H");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "voltigeur10";

			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "attack_voltigeurs";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"fight_more_voltigeurs2",5.0,5.0);
		break;

		case "fight_more_voltigeurs2":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_ActorGoToLocator(characterFromID("Donatien Thibaud"), "goto", "goto2", "", 30.0);

			LAi_SetFightMode(PChar, true);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "heres_the_officer");

			PChar.quest.KilledFighting.win_condition.l1 = "NPC_Death";
			PChar.quest.KilledFighting.win_condition.l1.character = PChar.id;
			PChar.quest.KilledFighting.win_condition = "KilledFighting";
		break;

		case "heres_the_officer":
			LAi_SetOfficerType(characterFromID("Rifleman Cooper"));
			LAi_SetOfficerType(characterFromID("Rifleman Higgins"));
			LAi_SetOfficerType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(Pchar, "monsters", "monster4", "heres_the_officer2", 30.0);		
		break;

		case "heres_the_officer2":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Donatien Thibaud")].Dialog.CurrentNode = "hello_quelp";
			LAi_ActorDialog(characterFromID("Donatien Thibaud"),PChar,"Thibaud_surrenders",30.0,5.0);
		break;

		case "Thibaud_surrenders":
			LAi_SetOfficerType(characterFromID("Donatien Thibaud"));
			AddPassenger(Pchar, characterFromID("Donatien Thibaud"), 0);
			SetCharacterRemovable(characterFromID("Donatien Thibaud"), false);
			RemoveCharacterEquip(characterFromID("Donatien Thibaud"), BLADE_ITEM_TYPE);
			GiveItem2Character(PChar, "blade51");
			PlayStereoSound("INTERFACE\took_item.wav");
			LogIt("Donatien Thibaud has surrendered his sword to you.");
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "meant_to_ask_you";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"Thibaud_surrenders2",5.0,5.0);
		break;

		case "Thibaud_surrenders2":
			Locations[FindLocation("Santo_Domingo_town_exit_1")].reload.l1.disable = 0;
			Locations[FindLocation("Santo_Domingo_town_exit_1")].reload.l3.disable = 0;

			LAi_SetActorType(characterFromID("Rifleman Cooper"));
			LAi_SetActorType(characterFromID("Rifleman Higgins"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Donatien Thibaud"));
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "officers", "reload1_1", "", 30.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "officers", "reload1_2", "", 30.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "officers", "reload1_3", "", 30.0);
			LAi_ActorGoToLocator(characterFromID("Donatien Thibaud"), "reload", "reload1_back", "riflemen_leave", 30.0);
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			AddQuestRecord("Hunt the Traitors", 8);
			Locations[FindLocation("Hispaniola_Jungle_08")].vcskip = false;
			Locations[FindLocation("Santo_Domingo_town_exit_1")].vcskip = false;
			Locations[FindLocation("Hispaniola_shore_01")].reload.l2.disable = 0;
			DisableFastTravel(false);
			Pchar.quest.French_patrol_setup.win_condition.l1 = "location";
			Pchar.quest.French_patrol_setup.win_condition.l1.location = "Hispaniola";
			Pchar.quest.French_patrol_setup.win_condition = "French_patrol_setup";
			Pchar.quest.back_to_Bridgetown.win_condition.l1 = "location";
			PChar.quest.back_to_Bridgetown.win_condition.l1.character = Pchar.id;
			Pchar.quest.back_to_Bridgetown.win_condition.l1.location = "Greenford_port";
			Pchar.quest.back_to_Bridgetown.win_condition = "back_to_Bridgetown"
			pchar.quest.riflemen_leave.win_condition.l1 = "location";
			Pchar.quest.riflemen_leave.win_condition.l1.character = Pchar.id;
			pchar.quest.riflemen_leave.win_condition.l1.location = "Hispaniola_Jungle_08";
			pchar.quest.riflemen_leave.win_condition = "riflemen_leave";
		break;

		case "riflemen_leave":
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");
			ChangeCharacterAddress(characterFromID("Donatien Thibaud"), "None", "");
		break;

		case "French_patrol_setup":
			Group_CreateGroup("French_patrol");
			Group_AddCharacter("French_patrol", "French_patrol_captain");
			Group_SetGroupCommander("French_patrol", "French_patrol_captain");

			Group_SetPursuitGroup("French_patrol", PLAYER_GROUP);
			Group_SetTaskAttack("French_patrol",  PLAYER_GROUP, true);
			Group_LockTask("French_patrol");
			Group_SetAddress("French_patrol", "Hispaniola", "ships_other", "ship_2");
			Sea_LoginGroupNow("French_patrol");
			characters[GetCharacterIndex("French_patrol_captain")].nosurrender = 2;
			SetCharacterRelationBoth(GetCharacterIndex("French_patrol"),GetMainCharacterIndex(),RELATION_ENEMY);

			Pchar.quest.patrol_defeated.win_condition.l1 = "NPC_death";
			Pchar.quest.patrol_defeated.win_condition.l1.character = "French_patrol_captain";
			Pchar.quest.patrol_defeated.win_condition = "frigate_down";
		break;

		case "frigate_down":
			AddQuestRecord("Hunt the Traitors", 10);
		break;

		case "back_to_Bridgetown":
			Pchar.quest.farewell_to_Sharpe.win_condition.l1 = "location";
			PChar.quest.farewell_to_Sharpe.win_condition.l1.character = Pchar.id;
			Pchar.quest.farewell_to_Sharpe.win_condition.l1.location = "Greenford_port";
			Pchar.quest.farewell_to_Sharpe.win_condition = "farewell_to_Sharpe";
		break;

		case "farewell_to_Sharpe":
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Greenford_port", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Greenford_port", "reload", "reload1_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Greenford_port", "reload", "reload1_back");
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Rifleman Haggman"));
			LAi_QuestDelay("farewell_to_Sharpe2", 0.0);
		break;

		case "farewell_to_Sharpe2":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			Characters[GetCharacterIndex("Richard Sharpe")].Dialog.CurrentNode = "leaving_for_Europe";
			LAi_ActorDialog(characterFromID("Richard Sharpe"),PChar,"farewell_to_Sharpe3",5.0,5.0);
		break;

		case "farewell_to_Sharpe3":
			SetCharacterRemovable(characterFromID("Richard Sharpe"), true);
			SetCharacterRemovable(characterFromID("Patrick Harper"), true);
			SetCharacterRemovable(characterFromID("Rifleman Haggman"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Richard Sharpe"));
			RemovePassenger(pchar, characterFromID("Richard Sharpe"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Patrick Harper"));
			RemovePassenger(pchar, characterFromID("Patrick Harper"));
			RemoveOfficersIndex(Pchar, characterFromID("Rifleman Haggman"));
			RemovePassenger(Pchar, characterFromID("Rifleman Haggman"));
			AddQuestRecord("Hunt the Traitors", 9);
			PauseAllSounds();
			LAi_QuestDelay("Take_it_away_Haggman", 0.0);
		break;

		case "Take_it_away_Haggman":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
//			locations[FindLocation("Greenford_port")].type = "Haggman_sings";
//			PostEvent("LoadSceneSound", 200);
			PlayStereoOGG("Sharpe_verse8");
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "reload", "reload4", "", 44.5);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "goto2", "", 44.7);
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "reload", "reload4", "Haggman_leaves", 45.0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 2000);}
			Pchar.quest.restore_sound.win_condition.l1 = "location";
			PChar.quest.restore_sound.win_condition.l1.character = Pchar.id;
			Pchar.quest.restore_sound.win_condition.l1.location = "Greenford_town";
			Pchar.quest.restore_sound.win_condition = "restore_sound";
		break;

		case "Haggman_leaves":
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "", "None", "None");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
		break;

		case "restore_sound":
//			locations[FindLocation("Greenford_port")].type = "port";
			ChangeCharacterAddress(characterFromID("Richard Sharpe"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			PChar.quest.report_traitors_done.win_condition.l1 = "location";
			PChar.quest.report_traitors_done.win_condition.l1.character = PChar.id;
			Pchar.quest.report_traitors_done.win_condition.l1.location = "Greenford Naval HQ";
			Pchar.quest.report_traitors_done.win_condition = "report_traitors_done";
			PChar.quest.back_home.win_condition.l1 = "location";
			PChar.quest.back_home.win_condition.l1.character = PChar.id;
			Pchar.quest.back_home.win_condition.l1.location = "Mrs. Mason's House";
			Pchar.quest.back_home.win_condition = "back_home";			
		break;

		case "report_traitors_done":
			ChangeCharacterAddressGroup(characterFromID("Lt. Eccleston"), "Greenford Naval HQ", "sit", "sit1");
			LAi_ActorSetSitMode(characterFromID("Lt. Eccleston"));
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Greenford Naval HQ", "goto", "goto3");
			LAi_QuestDelay("report_traitors_done2", 2.0);
		break;

		case "report_traitors_done2":
			characters[GetCharacterIndex("Lt. Eccleston")].Dialog.Filename = "Lt. Eccleston_dialog.c";
			LAi_SetActorType(characterFromID("Lt. Eccleston"));
			Characters[GetCharacterIndex("Lt. Eccleston")].dialog.CurrentNode = "what_can_I_do";
			LAi_ActorDialog(characterFromID("Lt. Eccleston"), pchar, "report_traitors_done3", 10.0, 10.0);
		break;

		case "report_traitors_done3":
			PauseAllSounds();
			PlayStereoOGG("Hornblower_end");
			LAi_ActorSetSitMode(characterFromID("Lt. Eccleston"));
			LAi_SetActorType(characterFromID("Sir Edward Pellew"));
			characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "traitors_done";
			LAi_ActorDialog(characterFromID("Sir Edward Pellew"),PChar,"end_of_traitors",5.0,5.0);
		break;

		case "end_of_traitors":
			SetCharacterRemovable(characterFromID("Donatien Thibaud"), true);
			RemovePassenger(pchar, characterFromID("Donatien Thibaud"));
			CloseQuestHeader("Hunt the Traitors");
			Characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_freeplay_dialog.c"; // Set up Pellew for "Natividad" quest
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "First time";
			LAi_SetStayType(characterFromID("Sir Edward Pellew"));
		break;

		case "back_home":
			LAi_SetActorType(characterFromID("Maria Mason"));
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Maria Mason_dialog.c";
			Characters[GetCharacterIndex("Maria Mason")].dialog.CurrentNode = "Back_home";
			LAi_ActorDialog(characterFromID("Maria Mason"),PChar,"back_home2",5.0,5.0);
		break;

		case "back_home2":
			characters[GetCharacterIndex("Maria Mason")].Dialog.Filename = "Gov MR_dialog.c";
			characters[GetCharacterIndex("Maria Mason")].Dialog.CurrentNode = "First time";
			LAi_SetStayType(characterFromID("Maria Mason"));
			LAi_Fade("", "");
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10.30, 0);
		break;

		PChar.questnotfound = true; // PB: Testing
	}
}
