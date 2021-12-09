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
		// NK <--

		case "first_step":
			ChangeCharacterAddressGroup(CharacterFromID("John Coxon"), "none", "", "");	//Cayman_Pirate_house_01 used later by Captain Montbars
			Locations[FindLocation("Havana_town_01")].reload.l13.disable = 1; //Benavides' residence
			PostVideoAndQuest("Bartolomeu\Arrival",500,"first_step2");
			break;

		case "first_step2":
			SetQuestHeader("ArrivedatPOP");
			AddQuestRecord("ArrivedatPOP", "1");

			PChar.quest.firstwork = "rencontre";
			Pchar.quest.firstwork.win_condition.l1 = "location";
			Pchar.quest.firstwork.win_condition.l1.location = "PoPrince_town";
			PChar.quest.firstwork.win_condition = "meethector";
			Locations[FindLocation("PoPrince_town")].vcskip = true;

			break;

		case "meethector":
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 1;
			ChangeCharacterAddressGroup(CharacterFromID("Hector Barbossa"), "PoPrince_town", "officers", "reload2_1");
			LAi_SetImmortal(CharacterFromID("Hector Barbossa"), true); // KK
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "PoPrince_town", "goto", "goto3");
			LAi_SetImmortal(CharacterFromID("Pierre Delacroix"), true); // KK
			LAi_SetActorType(characterFromID("Hector Barbossa"));
			Characters[GetCharacterIndex("Hector Barbossa")].dialog.currentnode = "First time";
			LAi_ActorDialog(characterFromID("Hector Barbossa"), pchar, "", 2.0, 1.0);

			break;

		case "rencdela":
			LAi_SetActorType(CharacterFromID("PoPrince_soldier_05"));
			LAi_ActorGoToLocator(CharacterFromID("PoPrince_soldier_05"), "goto", "goto4", "", 20.0);
			LAi_ActorRunToLocation(characterFromID("Hector Barbossa"), "reload", "reload17", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Pierre Delacroix"));
			Characters[GetCharacterIndex("Pierre Delacroix")].dialog.currentnode = "First time";
			LAi_ActorDialog(characterFromID("Pierre Delacroix"), pchar, "", 2.0, 1.0);

			break;

		case "renceug":
			LAi_SetActorType(CharacterFromID("PoPrince_soldier_05"));
			LAi_ActorGoToLocator(CharacterFromID("PoPrince_soldier_05"), "goto", "goto21", "retourposte", 20.0);
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
			LAi_SetActorType(characterFromID("Pierre Delacroix"));
			LAi_ActorGoToLocation(characterFromID("Pierre Delacroix"), "reload", "reload19", "none", "", "", "", 0.0);
			AddQuestRecord("ArrivedatPOP", "2");
			characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
			LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			Characters[GetCharacterIndex("Eugene Martin")].dialog.currentnode = "begin1_1";
			locations[FindLocation("Buccaneers_Camp")].reload.l6.disable = 1;

			break;

		case "retourposte":
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
			setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");

			break;

		case "rencemil":
			GiveItem2Character(PChar, "map");
			LAi_SetImmortal(CharacterFromID("Hector Barbossa"), false); // KK
			LAi_SetImmortal(CharacterFromID("Pierre Delacroix"), false); // KK
			locations[FindLocation("Buccaneers_Camp")].reload.l6.disable = 0;
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "BC_tavern", "Sit", "Sit13");
			LAi_SetSitType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin1_1";
			AddQuestRecord("ArrivedatPOP", "3");

			break;

		case "rencluc":
			GiveShip2Character(pchar,"Barque3_50","La Chanceuse",-1,PIRATE,true,true);
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Buccaneers_Camp", "reload", "reload4");

			LAi_SetImmortal(CharacterFromID("Emilio Soares"), true);
			AddCharacterGoods(pchar, GOOD_SANDAL, 160);

			SetCharacterShipLocation(Pchar, "Hispaniola_shore_02");
			PlaceFleetNearShore("Hispaniola_shore_02"); // KK

			ChangeCharacterAddressGroup(CharacterFromID("Luc Merin"), "Smuggler_Residence", "goto", "goto1");
			Characters[GetCharacterIndex("Luc Merin")].dialog.currentnode = "begin1_1";

			LAi_Fade("retrait", ""); // KK

			break;

		case "retrait":
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Emilio Soares")); // KK LAi_SetOfficerType(characterFromID("Emilio Soares"));
			ChangeCharacterAddress(characterFromID("Emilio Soares"), "none", "");
			PlaceCharacter(characterFromID("Emilio Soares"), "goto");

			break;

		case "goctopus":
			SetCharacterShipLocation(Pchar, "Falaise_de_fleur_shore");
			DoQuestReloadToLocation("Falaise_de_fleur_shore", "goto", "locator8", "_");
			ChangeCharacterAddressGroup(CharacterFromID("Luc Merin"), "Falaise_de_fleur_shore", "goto", "locator22");
			LAi_SetActorType(characterFromID("Luc Merin"));
			Characters[GetCharacterIndex("Luc Merin")].dialog.currentnode = "begin_3";
			LAi_ActorDialog(characterFromID("Luc Merin"), pchar, "", 2.0, 1.0);

			break;

		case "revoireug":
			LAi_ActorRunToLocation(characterFromID("Luc Merin"), "reload", "reload2_back", "none", "", "", "", 0.0);
			Characters[GetCharacterIndex("Eugene Martin")].dialog.currentnode = "begin_11";
			RemoveCharacterGoods(pchar, GOOD_SANDAL, 160);
			AddCharacterGoods(pchar, GOOD_SILK, 160);

			break;

		case "rencelias":
			TakeNItems(PChar, "mapDouwesen", 1);
			AddQuestRecord("ArrivedatPOP", "4");
			AddCharacterGoods(pchar, GOOD_LINEN, 200);
			ChangeCharacterAddressGroup(characterFromID("Elias Bartels"), "Pirate_tavern", "Sit", "Sit4");
			LAi_SetSitType(characterFromID("Elias Bartels"));
			Characters[GetCharacterIndex("Elias Bartels")].dialog.currentnode = "begin1_1";


			break;

		case "gopalm":
			SetCharacterShipLocation(Pchar, "Douwesen_shore_01");
			DoQuestReloadToLocation("Douwesen_shore_01", "goto", "locator12", "_");
			ChangeCharacterAddressGroup(CharacterFromID("Elias Bartels"), "Douwesen_shore_01", "goto", "locator6");
			LAi_SetActorType(characterFromID("Elias Bartels"));
			Characters[GetCharacterIndex("Elias Bartels")].dialog.currentnode = "begin_3";
			LAi_ActorDialog(characterFromID("Elias Bartels"), pchar, "", 2.0, 1.0);

			break;

		case "goeug":
			LAi_ActorRunToLocation(characterFromID("Elias Bartels"), "reload", "reload2_back", "none", "", "", "", 0.0);
			Characters[GetCharacterIndex("Eugene Martin")].dialog.currentnode = "begin_15";
			RemoveCharacterGoods(pchar, GOOD_LINEN, 200);
			AddCharacterGoods(pchar, GOOD_ALE, 600);

			break;

		case "rencmag":
			AddQuestRecord("ArrivedatPOP", "5");
			AddCharacterGoods(pchar, GOOD_CINNAMON, 300);
			PChar.quest.firstwork = "cinnamon";

			// PB: Set this up as an actual trade quest --->
			// Otherwise the store owner won't talk to you
			pchar.quest.generate_trade_quest_progress = "begin";
			pchar.quest.generate_trade_quest_progress.iTradeGoods = GOOD_CINNAMON;
			pchar.quest.generate_trade_quest_progress.iQuantityGoods = 300;
			pchar.quest.generate_trade_quest_progress.iTradeColony = "Marigot";
			// PB: Set this up as an actual trade quest <---

			break;

		case "emiliosuit":
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Buccaneers_Camp", "goto", "goto36");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_5";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);

			break;

		case "voyage_fin_timer":
			Characters[GetCharacterIndex("Eugene Martin")].Location = "none";
			Characters[GetCharacterIndex("Emilio Soares")].Location = "none";
			PChar.quest.Bartolomeu = "end";
			PChar.quest.Bartolomeu.over = "yes";

			AddQuestRecord("ArrivedatPOP", "7");
			CloseQuestHeader("ArrivedatPOP");
			bSuppressResurrection = false;

			break;

		case "voyage_fin_timer2":
			Characters[GetCharacterIndex("Eugene Martin")].Location = "none";
			Characters[GetCharacterIndex("Emilio Soares")].Location = "none";
			PChar.quest.Bartolomeu = "end";
			PChar.quest.Bartolomeu.over = "yes";

			AddQuestRecord("ArrivedatPOP", "8");
			CloseQuestHeader("ArrivedatPOP");
			bSuppressResurrection = false;

			break;

		case "voyage_timer1":
			PChar.quest.voyage_timer1.win_condition.l1 = "Timer";
			PChar.quest.voyage_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 0, 60);
			PChar.quest.voyage_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 60);
			PChar.quest.voyage_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 0, 60);
			PChar.quest.voyage_timer1.win_condition = "voyage_fin_timer";
			break;

		case "voyage_timer3":
			PChar.quest.voyage_timer3.win_condition.l1 = "Timer";
			PChar.quest.voyage_timer3.win_condition.l1.date.day = GetAddingDataDay(0, 0, 60);
			PChar.quest.voyage_timer3.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 60);
			PChar.quest.voyage_timer3.win_condition.l1.date.year = GetAddingDataYear(0, 0, 60);
			PChar.quest.voyage_timer3.win_condition = "voyage_fin_timer";
			break;

		case "voyage_timer4":
			PChar.quest.voyage_timer4.win_condition.l1 = "Timer";
			PChar.quest.voyage_timer4.win_condition.l1.date.day = GetAddingDataDay(0, 0, 60);
			PChar.quest.voyage_timer4.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 60);
			PChar.quest.voyage_timer4.win_condition.l1.date.year = GetAddingDataYear(0, 0, 60);
			PChar.quest.voyage_timer4.win_condition = "voyage_fin_timer";
			break;

		case "voyage_timer2":
			PChar.quest.voyage_timer2.win_condition.l1 = "Timer";
			PChar.quest.voyage_timer2.win_condition.l1.date.day = GetAddingDataDay(0, 0, 10);
			PChar.quest.voyage_timer2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 10);
			PChar.quest.voyage_timer2.win_condition.l1.date.year = GetAddingDataYear(0, 0, 10);
			PChar.quest.voyage_timer2.win_condition = "voyage_fin_timer2";
			break;



			// First Expedition Quest

		case "rencrox":
			Change_MainThemeMusic_Chance(5);
			bSuppressResurrection = true;
			locations[FindLocation("BC_Tavern")].reload.l1.disable = 1;

			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "BC_Tavern", "goto", "goto4");
			ChangeCharacterAddressGroup(CharacterFromID("Pedro Rivera"), "BC_Tavern", "goto", "goto5");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_1";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);

			break;

		case "rencpedro":

			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorGoToLocation(characterFromID("Roxanne Lalliere"), "reload", "reload1", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Pedro Rivera"));
			Characters[GetCharacterIndex("Pedro Rivera")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Pedro Rivera"), pchar, "", 2.0, 1.0);

			break;

		case "directmaestra":
			locations[FindLocation("BC_Tavern")].reload.l1.disable = 0;
			Island_SetReloadEnableLocal("Cuba", "reload_8", true);
			Islands[FindIsland("Cuba")].reload.l7.goto_enable = true; // PB
			SetQuestHeader("Expedition");
			AddQuestRecord("Expedition", "1");

			LAi_SetActorType(characterFromID("Pedro Rivera"));
			LAi_SetImmortal(CharacterFromID("Pedro Rivera"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Pedro Rivera"), "", 60.0);
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Roxanne Lalliere"));
			SetCharacterRemovable(characterFromID("Roxanne Lalliere"), false);
			pchar.quest.versmaest.win_condition.l1 = "location";
			pchar.quest.versmaest.win_condition.l1.location = "Redmond_shore_02";
			pchar.quest.versmaest.win_condition = "surmaest";

			break;

		case "surmaest":

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat1", "goto", "goto5");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ROXANNE_PIRATES");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 10.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", "goto", "goto6");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ROXANNE_PIRATES");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 10.0);

			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Redmond_shore_02", "goto", "goto7");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_58";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);

			break;

		case "surmaest2":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorGoToLocation(characterFromID("Roxanne Lalliere"), "reload", "reload1", "none", "", "", "", 0.0);
			pchar.quest.versmaestra.win_condition.l1 = "location";
			pchar.quest.versmaestra.win_condition.l1.location = "Cuba_Shore_05";
			pchar.quest.versmaestra.win_condition = "surmaestra";

			break;

		case "surmaestra":
			SetCurrentTime(24, 0);
			locations[FindLocation("Santiago_outskirts")].vcskip = true;
			locations[FindLocation("Cuba_Jungle_04")].vcskip = true;

			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Cuba_Shore_05", "goto", "locator10");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_13";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);

			break;

		case "surplage":

			pchar.quest.versrock.win_condition.l1 = "location";
			pchar.quest.versrock.win_condition.l1.location = "Cuba_Jungle_04";
			pchar.quest.versrock.win_condition = "aurocher";

			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_SetImmortal(CharacterFromID("Roxanne Lalliere"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);

			break;

		case "aurocher":

			pchar.quest.versentre.win_condition.l1 = "location";
			pchar.quest.versentre.win_condition.l1.location = "Santiago_outskirts";
			pchar.quest.versentre.win_condition = "attack";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_14";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);

			break;

		case "attack":
			locations[FindLocation("Santiago_outskirts")].reload.l1.disable = 1;
			locations[FindLocation("Santiago_outskirts")].reload.l11.disable = 1;
			locations[FindLocation("Santiago_outskirts")].reload.l3.disable = 1;
			locations[FindLocation("Santiago_outskirts")].reload.l4.disable = 1;
			locations[FindLocation("Santiago_outskirts")].reload.l5.disable = 1;
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Santiago_outskirts", "officers", "reload1_1");
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Santiago_outskirts", "officers", "reload1_2");
			ChangeCharacterAddressGroup(CharacterFromID("Pedro Rivera"), "Santiago_outskirts", "officers", "reload1_2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREHOUSE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREHOUSE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto3");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREHOUSE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto4");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREHOUSE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_spa5_16", "reload", "reload3");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "Roxanne Lalliere_dialog.c";
			sld.dialog.currentnode = "begin_26";
			sld.id = "soldado";
			LAi_SetActorType(characterfromID("soldado"));
			LAi_ActorDialog(characterfromID("soldado"), PChar, "", 0.5, 10);

			break;

		case "debutbat":
			LAi_SetOfficerType(characterFromID("Pedro Rivera"));
			LAi_SetGuardianType(characterFromID("soldado"));
			LAi_group_MoveCharacter(characterFromID("soldado"), "WAREHOUSE_SOLDIERS");
			LAi_group_FightGroups("WAREHOUSE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("WAREHOUSE_SOLDIERS", "finbat");

			break;

		case "finbat":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_15";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);

			LAi_SetActorType(characterFromID("Pedro Rivera"));
			LAi_ActorFollowEverywhere(characterFromID("Pedro Rivera"), "", 60.0);

			break;

		case "finbat_2":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			pchar.quest.versentreun.win_condition.l1 = "location";
			pchar.quest.versentreun.win_condition.l1.location = "Santiago_warehouse_01";
			pchar.quest.versentreun.win_condition = "attack2";

			break;

		case "attack2":
			locations[FindLocation("Santiago_warehouse_01")].reload.l1.disable = 1;
			LAi_SetOfficerType(characterFromID("Pedro Rivera"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto7");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDIERS");
			LAi_group_FightGroups("WAREINSIDE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("WAREINSIDE_SOLDIERS", "entrepot_1");


			break;

		case "entrepot_1":
			locations[FindLocation("Santiago_warehouse_01")].reload.l1.disable = 0;
			locations[FindLocation("Santiago_outskirts")].reload.l5.disable = 0;
			pchar.quest.versentredeux.win_condition.l1 = "location";
			pchar.quest.versentredeux.win_condition.l1.location = "Santiago_warehouse_02";
			pchar.quest.versentredeux.win_condition = "attack3";
			LAi_SetActorType(characterFromID("Pedro Rivera"));
			LAi_ActorFollowEverywhere(characterFromID("Pedro Rivera"), "", 60.0);

			break;

		case "attack3":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Santiago_warehouse_02", "officers", "reload1_2");
			LAi_SetOfficerType(characterFromID("Pedro Rivera"));
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));

			locations[FindLocation("Santiago_warehouse_02")].reload.l1.disable = 1;
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto18");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDES_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto8");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDES_SOLDIERS");
			LAi_group_FightGroups("WAREINSIDES_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("WAREINSIDES_SOLDIERS", "entrepot_2");

			break;

		case "entrepot_2":
			locations[FindLocation("Santiago_warehouse_02")].reload.l1.disable = 0;
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);

			break;

		case "allezdehors":
			DoQuestReloadToLocation("Santiago_outskirts", "goto", "goto8", "_");
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Santiago_outskirts", "officers", "reload2_2");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_17";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorWaitDialog(CharacterFromID("Roxanne Lalliere"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Roxanne Lalliere"), "", 10.0, 1.0);

			break;

		case "chercherivera":
			LAi_ActorGoToLocator(PChar, "goto", "goto11", "riveraback", 10.0);

			break;
		case "riveraback":
			LAi_ActorTurnByLocator( pchar, "goto", "goto11");
			LAi_QuestDelay("riveraback_2", 1.0);

			break;

		case "riveraback_2":
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(CharacterFromID("Pedro Rivera"), "Santiago_outskirts", "reload", "reload2_back");

			LAi_SetActorType(characterFromID("Pedro Rivera"));
			Characters[GetCharacterIndex("Pedro Rivera")].dialog.currentnode = "begin_6";
			LAi_ActorDialog(characterFromID("Pedro Rivera"), pchar, "", 2.0, 1.0);

			break;

		case "fuirsoldats":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto10", "", 40.0);
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "goto", "goto10", "none", "", "", "", 0.0);
			LAi_ActorRunToLocation(characterFromID("Emilio Soares"), "goto", "goto10", "none", "", "", "", 0.0);
			LAi_SetOfficerType(characterFromID("Pedro Rivera"));
			LAi_QuestDelay("discusplage", 6.0);

			break;

		case "discusplage":
			locations[FindLocation("Santiago_outskirts")].reload.l3.disable = 0;
			locations[FindLocation("Cuba_Shore_05")].reload.l3.disable = 1;
			DoQuestReloadToLocation("Cuba_Shore_05", "goto", "locator9", "_");
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Cuba_Shore_05", "goto", "locator7");
			ChangeCharacterAddressGroup(CharacterFromID("Pedro Rivera"), "Cuba_Shore_05", "goto", "locator8");
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Cuba_Shore_05", "goto", "citizen09");
			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_18";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorWaitDialog(CharacterFromID("Roxanne Lalliere"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Roxanne Lalliere"), "", 10.0, 1.0);

			break;

		case "feterivera":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Pedro Rivera"));
			Characters[GetCharacterIndex("Pedro Rivera")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Pedro Rivera"), pchar, "", 2.0, 1.0);

			break;

		case "laissepedro":
			LAi_ActorRunToLocation(characterFromID("Pedro Rivera"), "reload", "reload2_back", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_19";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);

			break;

		case "directpop":
			AddQuestRecord("Expedition", "2");
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));
			pchar.quest.partloot.win_condition.l1 = "location";
			pchar.quest.partloot.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.partloot.win_condition = "shareloot";

			break;

		case "shareloot":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Redmond_town_01", "goto", "goto12");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_20";
			LAi_SetStayType(characterFromID("Roxanne Lalliere"));

			break;

		case "finexpedition":
			SetRMRelation(PChar, SPAIN, REL_WAR);
			Build_at("Santiago_port", "Sign", "", -45,17.056,-11.48, -1.075, "building");
			Locations[FindLocation("Santiago_Town_01")].dangerous = true;
			bSuppressResurrection = false;
			locations[FindLocation("Cuba_Shore_05")].reload.l3.disable = 0;
			locations[FindLocation("Santiago_outskirts")].reload.l1.disable = 0;
			locations[FindLocation("Santiago_outskirts")].reload.l11.disable = 0;
			//locations[FindLocation("Santiago_town_04")].reload.l1.disable = 0;
			LAi_SetActorType(CharacterFromID("Roxanne Lalliere"));
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "reload_2_3", "none", "", "", "", 10.0);
			RemoveCharacterCompanion(Pchar, characterFromID("Roxanne Lalliere"));
			setCharacterShipLocation(characterFromID("Roxanne Lalliere"), "none");
			AddQuestRecord("Expedition", "3");
			CloseQuestHeader("Expedition");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }

			pchar.quest.nouvoutfit.win_condition.l1 = "location";
			pchar.quest.nouvoutfit.win_condition.l1.location = "Conceicao_townhall";
			pchar.quest.nouvoutfit.win_condition = "chapeau";

			break;

		case "chapeau":
			GiveModel2Player("GypsyCaptn_3", true);

			break;


		case "viagem_fin_timer":
			Characters[GetCharacterIndex("Roxanne Lalliere")].Location = "none";
			Characters[GetCharacterIndex("Emilio Soares")].Location = "none";
			Characters[GetCharacterIndex("Pedro Rivera")].Location = "none";

			PChar.quest.Bartolomeu = "end";
			PChar.quest.Bartolomeu.over = "yes";
			RemoveCharacterCompanion(Pchar, characterFromID("Roxanne Lalliere"));
			setCharacterShipLocation(characterFromID("Roxanne Lalliere"), "none");

			AddQuestRecord("Expedition", "4");
			CloseQuestHeader("Expedition");
			bSuppressResurrection = false;

			break;

		case "viagem_timer1":
			PChar.quest.viagem_timer1.win_condition.l1 = "Timer";
			PChar.quest.viagem_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 0, 20);
			PChar.quest.viagem_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 20);
			PChar.quest.viagem_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 0, 20);
			PChar.quest.viagem_timer1.win_condition = "viagem_fin_timer";

			break;

			// BAD BLAZE

		case "debutquete":
			SetQuestHeader("Bad_Blaze");
			AddQuestRecord("Bad_Blaze", "1");
			Locations[FindLocation("Tortuga_town_exit")].vcskip = true;
			break;

		case "piegetortue":
			DoQuestReloadToLocation("Tortuga_town_exit", "goto", "citizen018", "piegetortue2");
			SetCurrentTime(23, 0);

			break;

		case "piegetortue2":
			ChangeCharacterAddressGroup(characterFromID("Christopher Backer"), "Tortuga_town_exit", "goto", "citizen012");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "50M5", "goto", "citizen017");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "TORTUE_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "ancient", "goto", "citizen06");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "TORTUE_PIRATES");
			Characters[GetCharacterIndex("Christopher Backer")].dialog.CurrentNode = "begin_9";
			LAi_SetActorType(characterFromID("Christopher Backer"));
			LAi_ActorDialog(characterFromID("Christopher Backer"), pchar, "", 3.0, 1.0);

			break;

		case "piegetortue3":
			LAi_SetImmortal(CharacterFromID("Christopher Backer"), 1);
			LAi_ActorAttack(CharacterFromID("Christopher Backer"), PChar, "");
			locations[FindLocation("Tortuga_town_exit")].reload.l1.disable = 1;
			locations[FindLocation("Tortuga_town_exit")].reload.l2.disable = 1;
			locations[FindLocation("Tortuga_town_exit")].reload.l4.disable = 1;

			LAi_group_FightGroups("TORTUE_PIRATES", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("TORTUE_PIRATES", "piegetortue4");

			break;

		case "piegetortue4":
			LAi_SetActorType(characterFromID("Christopher Backer"));
			Characters[GetCharacterIndex("Christopher Backer")].dialog.currentnode = "begin_15";
			LAi_ActorDialog(characterFromID("Christopher Backer"), pchar, "", 1.0, 1.0);

			break;

		case "piegetortue5":
			LAi_SetActorType(characterFromID("Christopher Backer"));
			LAi_ActorRunToLocation(characterFromID("Christopher Backer"), "reload", "reload1", "none", "", "", "", 0.0);
			locations[FindLocation("Tortuga_town_exit")].reload.l1.disable = 0;
			locations[FindLocation("Tortuga_town_exit")].reload.l2.disable = 0;
			locations[FindLocation("Tortuga_town_exit")].reload.l4.disable = 0;

			ChangeCharacterAddressGroup(characterFromID("Matthew Gilroy"), "Turks_townhall", "goto", "goto5");
			Characters[GetCharacterIndex("Matthew Gilroy")].dialog.currentnode = "begin_1";
			ChangeCharacterAddressGroup(characterFromID("Walter Foreman"), "Turks_townhall", "goto", "goto6");
			AddQuestRecord("Bad_Blaze", "4");

			break;

		case "informateur_tavern":
			DeleteAttribute(&Locations[FindLocation("Tortuga_town_exit")],"vcskip");
			Pchar.quest.informateur.win_condition.l1 = "location";
			Pchar.quest.informateur.win_condition.l1.location = "Turks_Tavern";
			PChar.quest.informateur.win_condition = "informateur2";
			AddQuestRecord("Bad_Blaze", "5");

			break;

		case "informateur2":
			LAi_QuestDelay("informateur29", 3.0);

			break;

		case "informateur29":
			LAi_Fade("informateur3", "informateur31");
			break;
		case "informateur3":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Turks_tavern", "sit", "sit4");
			break;

		case "informateur31":
			LAi_ActorWaitDialog(CharacterFromID("Walter Foreman"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Walter Foreman"),"", 10.0, 10.0);
			break;

		case "cherchargent":
			DoQuestReloadToLocation("Turks_port", "reload", "reload4_back", "_");		//JRH: new Turks, to tavern
			LAi_SetPlayerType(pchar);
			LAi_SetSitType(characterFromID("Walter Foreman"));
			break;

		case "natcharles":
			DoQuestReloadToLocation("Turks_port", "reload", "reload4_back", "natcharles2");	//JRH: new Turks, to tavern
			LAi_SetPlayerType(pchar);
			break;

		case "natcharles2":
			ChangeCharacterAddressGroup(CharacterFromID("Walter Foreman"), "none", "", "");
			AddQuestRecord("Bad_Blaze", "6");
			setCharacterShipLocation(characterFromID("Santiago"), "Charlestown_port");

			Pchar.quest.charles.win_condition.l1 = "location";
			Pchar.quest.charles.win_condition.l1.location = "Charlestown_port";
			PChar.quest.charles.win_condition = "natcharles3";

			break;

		case "natcharles3":
			PlaceCharacter(characterFromID("Emilio Soares"), "goto");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_33";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 5.0, 1.0);

			break;

		case "natcharles5":
			Change_MainThemeMusic_Chance(5);
			pchar.quest.BadBlaze = "voirhugh";
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorFollowEverywhere(characterFromID("Emilio Soares"), "", 60.0);

			break;

		case "natcharles6":
			Pchar.quest.emilio_charles.win_condition.l1 = "location";
			Pchar.quest.emilio_charles.win_condition.l1.location = "Charlestown_port";
			PChar.quest.emilio_charles.win_condition = "natcharles7";

			break;

		case "natcharles7":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_36";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);
			ChangeCharacterAddressGroup(characterFromID("Sarah Roebuck"), "Charlestown_church", "goto", "goto1");
			Characters[GetCharacterIndex("Sarah Roebuck")].dialog.currentnode = "begin_1";

			break;

		case "natcharles8":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorFollowEverywhere(characterFromID("Emilio Soares"), "", 60.0);

			break;

		case "natcharles9":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_39";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);

			break;

		case "natcharles10":
			LAi_SetActorType(characterFromID("Sarah Roebuck"));
			Characters[GetCharacterIndex("Sarah Roebuck")].dialog.currentnode = "begin_9";
			LAi_ActorDialog(characterFromID("Sarah Roebuck"), pchar, "", 2.0, 1.0);

			break;

		case "natcharles11":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_44";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);

			break;

		case "natcharles12":
			LAi_ActorRunToLocation(characterFromID("Emilio Soares"), "reload", "reload1", "none", "", "", "natcharles12b", 15.0);
			LAi_SetActorType(characterFromID("Sarah Roebuck"));
			Characters[GetCharacterIndex("Sarah Roebuck")].dialog.currentnode = "begin_10";
			LAi_ActorDialog(characterFromID("Sarah Roebuck"), pchar, "", 2.0, 1.0);

			break;

		case "natcharles12b":
			RemovePassenger(pchar, characterFromID("Emilio Soares"));
			RemoveCharacterCompanion(pchar, characterFromID("Emilio Soares"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Emilio Soares"));

			break;

		case "natcharles13":
			LAi_SetStayType(characterFromID("Sarah Roebuck"));
			locations[FindLocation("Charlestown_Port")].reload.l2.disable = 0;
			locations[FindLocation("Charlestown_House_01")].vcskip = true;
			ChangeCharacterAddressGroup(characterFromID("Nathaniel Hawk"), "Charlestown_House_01", "goto", "goto2");
			Characters[GetCharacterIndex("Nathaniel Hawk")].dialog.currentnode = "begin_1";
			break;

		case "natcharles14":
			setCharacterShipLocation(characterFromID("Santiago"), "Quest_Charlestown");
			bSuppressResurrection = true;
			DoQuestReloadToLocation("Quest_Charlestown", "officers", "gate_2", "natcharles15");

			break;

		case "natcharles15":
			ChangeCharacterAddressGroup(characterFromID("Nathaniel Hawk"), "Quest_Charlestown", "goto", "goto20");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor5", "goto", "goto12");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CHARLESTOWN_PIRATES");
			sld.id = "NatPir1";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor4", "goto", "goto14");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CHARLESTOWN_PIRATES");
			sld.id = "NatPir2";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor7", "goto", "goto26");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CHARLESTOWN_PIRATES");
			sld.id = "NatPir3";

			LAi_SetActorType(characterFromID("Nathaniel Hawk"));
			Characters[GetCharacterIndex("Nathaniel Hawk")].dialog.currentnode = "begin_4";
			LAi_ActorDialog(characterFromID("Nathaniel Hawk"), pchar, "", 3.0, 3.0);

			break;

		case "natcharles16":
			LAi_SetWarriorType(characterFromID("Nathaniel Hawk"));
			LAi_group_MoveCharacter(characterFromID("Nathaniel Hawk"), "DEVIL_BOSS");
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "DEVIL_BOSS", true);
			LAi_group_SetCheck("DEVIL_BOSS", "natcharles17");

			break;

		case "natcharles17":
			LAi_group_FightGroups("CHARLESTOWN_PIRATES", LAI_GROUP_PLAYER, true);
			LAi_QuestDelay("natcharles18", 3.0);

			break;

		case "natcharles18":
			CreateParticleSystemX("blast_inv", 74.87, 0.00, -149.98, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 74.87, 0.00, -149.98, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 79.87, 0.00, -149.98, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 74.87, 0.00, -144.98, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 74.87, 0.00, -154.98, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_QuestDelay("natcharles19", 1.0);

			break;

		case "natcharles19":
			LAi_SetActorType(characterFromID("NatPir3"));
			LAi_ActorRunToLocation(characterFromID("NatPir3"), "reload", "reload4_back", "none", "", "", "", 0.0);
			LAi_KillCharacter(characterFromID("NatPir2"));
			LAi_QuestDelay("natcharles20", 1.0);

			break;

		case "natcharles20":
			CreateParticleSystemX("blast_inv", 88.8, 0.00, -165.92, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 88.8, 0.00, -165.92, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 93.8, 0.00, -165.92, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 88.8, 0.00, -160.92, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 88.8, 0.00, -170.92, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_KillCharacter(characterFromID("NatPir1"));
			LAi_QuestDelay("natcharles21", 6.0);

			break;

		case "natcharles21":
			locations[FindLocation("QC_Jungle_03")].reload.l1.disable = 1;
			locations[FindLocation("QC_Jungle_03")].reload.l3.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Sarah Roebuck"), "none", "", "");
			DoQuestReloadToLocation("QC_Jungle_03", "reload", "reload1_back", "natcharles22");

			break;

		case "natcharles22":
			GiveItem2Character(CharacterFromId("Nathaniel Hawk"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Nathaniel Hawk"), "bladex4");
			GiveItem2Character(CharacterFromId("Nathaniel Hawk"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Nathaniel Hawk"), "pistolrock");
			ChangeCharacterAddressGroup(characterFromID("Nathaniel Hawk"), "QC_Jungle_03", "officers", "reload1_2");
			LAi_SetActorType(characterFromID("Nathaniel Hawk"));
			LAi_ActorAnimation(characterFromID("Nathaniel Hawk"), "Ground_StandUp", "natcharles23", 3.0);

			break;

		case "natcharles23":
			Characters[GetCharacterIndex("Nathaniel Hawk")].dialog.currentnode = "begin_5";
			LAi_ActorDialog(characterFromID("Nathaniel Hawk"), pchar, "", 2.0, 2.0);

			break;

		case "natcharles24":
			locations[FindLocation("QC_Port")].reload.l2.disable = 1;
			locations[FindLocation("QC_Port")].reload.l3.disable = 1;
			LAi_SetActorType(characterFromID("Nathaniel Hawk"));
			LAi_ActorFollowEverywhere(characterFromID("Nathaniel Hawk"), "", 60.0);
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "QC_Port", "reload", "reload1");
			LAi_SetStayType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_46";
			GiveShip2Character(pchar,"FastCaravel","Santiago",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "QC_Port");
			AddQuestRecord("Bad_Blaze", "7");

			break;

		case "natcharles25":
			LAi_SetActorType(characterFromID("Nathaniel Hawk"));
			Characters[GetCharacterIndex("Nathaniel Hawk")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Nathaniel Hawk"), pchar, "", 2.0, 2.0);

			break;

		case "natcharles26":
			ChangeCharacterAddressGroup(characterFromID("Nathaniel Hawk"), "none", "", "");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_49";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 2.0);

			break;

		case "natcharles27":
			locations[FindLocation("Conceicao_town_exit")].reload.l2.disable = 1;
			locations[FindLocation("QC_Jungle_03")].reload.l1.disable = 0;
			locations[FindLocation("QC_Jungle_03")].reload.l3.disable = 0;
			locations[FindLocation("QC_Port")].reload.l2.disable = 0;
			locations[FindLocation("QC_Port")].reload.l3.disable = 0;
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "none", "", "");
			Pchar.quest.back_governor.win_condition.l1 = "location";
			Pchar.quest.back_governor.win_condition.l1.location = "Conceicao_port";
			PChar.quest.back_governor.win_condition = "natconceicao";

			break;

		case "natconceicao":
			DisableFastTravel(true);
			DisableMenuLaunch(true);

			locations[FindLocation("Conceicao_Port")].reload.l4.disable = 1;
			locations[FindLocation("Conceicao_Port")].reload.l3.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "Conceicao_port", "officers", "reload2_3");
			ChangeCharacterAddressGroup(characterFromID("Nathaniel Hawk"), "Conceicao_port", "officers", "reload2_2");
			ChangeCharacterAddressGroup(characterFromID("Duarte Felgueiras"), "Conceicao_port", "goto", "goto11");
			ChangeCharacterAddressGroup(characterFromID("Portuguese_soldier_01"), "Conceicao_port", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Portuguese_soldier_02"), "Conceicao_port", "goto", "goto10");
			LAi_SetActorType(characterFromID("Portuguese_soldier_01"));
			LAi_ActorFollow(characterFromID("Portuguese_soldier_01"), characterFromID("Nathaniel Hawk"), "", 15.0);
			LAi_SetActorType(characterFromID("Portuguese_soldier_02"));
			LAi_ActorFollow(characterFromID("Portuguese_soldier_02"), characterFromID("Nathaniel Hawk"), "", 15.0);
			LAi_SetActorType(characterFromID("Nathaniel Hawk"));
			Characters[GetCharacterIndex("Nathaniel Hawk")].dialog.currentnode = "begin_13";
			LAi_ActorDialog(characterFromID("Nathaniel Hawk"), pchar, "", 2.0, 2.0);

			break;

		case "natconceicao1":
			locations[FindLocation("Conceicao_town_exit")].reload.l2.disable = 0;
			LAi_SetActorType(characterFromID("Duarte Felgueiras"));
			Characters[GetCharacterIndex("Duarte Felgueiras")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Duarte Felgueiras"), pchar, "", 5.0, 1.0);

			break;

		case "natconceicao2":
			locations[FindLocation("Conceicao_Port")].reload.l4.disable = 0;
			locations[FindLocation("Conceicao_Port")].reload.l3.disable = 0;
			ChangeCharacterAddressGroup(characterFromID("Jacinto Arcibaldo Barreto"), "Conceicao_townhall", "goto", "goto7");
			LAi_SetStayType(characterFromID("Jacinto Arcibaldo Barreto"));
			Characters[GetCharacterIndex("Jacinto Arcibaldo Barreto")].dialog.currentnode = "gov_17";
			LAi_SetStayType(characterFromID("Nathaniel Hawk"));
			DoQuestReloadToLocation("Conceicao_townhall", "goto", "goto8", "natconceicao3");

			break;

		case "natconceicao3":
			LAi_SetActorType(characterFromID("Jacinto Arcibaldo Barreto"));
			LAi_ActorDialog(characterFromID("Jacinto Arcibaldo Barreto"), pchar, "", 5.0, 1.0);
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Nathaniel Hawk"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Duarte Felgueiras"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Portuguese_soldier_01"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Portuguese_soldier_02"), "none", "", "");

			break;

		case "natconceicao4":
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "Conceicao_town", "goto", "goto24");
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_50";
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 10.0, 1.0);

			break;

		case "natconceicao5":
			Pchar.quest.back_BC.win_condition.l1 = "location";
			Pchar.quest.back_BC.win_condition.l1.location = "Hispaniola_shore_02";
			PChar.quest.back_BC.win_condition = "barthubon";
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorFollowEverywhere(characterFromID("Emilio Soares"), "", 60.0);
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			AddCharacterGoods(pchar, GOOD_CINNAMON, 150);
			AddCharacterGoods(pchar, GOOD_FRUITS, 200);
			AddCharacterGoods(pchar, GOOD_SUGAR, 250);
			LAi_SetHuberType(characterFromID("Jacinto Arcibaldo Barreto"));
			ChangeCharacterAddressGroup(characterFromID("Jacinto Arcibaldo Barreto"), "Conceicao_townhall", "sit", "sit1");
			AddQuestRecord("Bad_Blaze", "8");

			break;

		case "barthubon":
			GiveItem2Character(CharacterFromId("bart_pirate_06"), "blade10");
			EquipCharacterByItem(CharacterFromId("bart_pirate_06"), "blade10");
			GiveItem2Character(CharacterFromId("bart_pirate_06"), "pistol1a");
			EquipCharacterByItem(CharacterFromId("bart_pirate_06"), "pistol1a");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Hispaniola_shore_02", "goto", "locator12");
			LAi_SetActorType(characterFromID("bart_pirate_06"));
			Characters[GetCharacterIndex("bart_pirate_06")].dialog.currentnode = "begin_5";
			LAi_ActorDialog(characterFromID("bart_pirate_06"), pchar, "", 3.0, 1.0);

			break;

		case "BCstore":
			ChangeCharacterAddressGroup(CharacterFromID("Eugene Martin"), "BC_Store", "sit", "sit1");
			Characters[GetCharacterIndex("Eugene Martin")].dialog.currentnode = "begin_42";

			break;

		case "fighthubon":
			pchar.sailaway = true;
			LAi_SetActorType(characterFromID("bart_pirate_06"));
			Characters[GetCharacterIndex("bart_pirate_06")].dialog.currentnode = "begin_6";
			LAi_ActorDialog(characterFromID("bart_pirate_06"), pchar, "", 1.0, 1.0);

			break;

		case "fighthubon2":
			DoQuestReloadToLocation("Hispaniola_shore_02", "goto", "citizen03", "fighthubon3");
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			locations[FindLocation("Hispaniola_shore_02")].reload.l2.disable = 1;

			break;

		case "fighthubon3":
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Hispaniola_shore_02", "goto", "locator10");
			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Hispaniola_shore_02", "goto", "locator7");
			LAi_SetOfficerType(characterFromID("bart_pirate_06"));
			ChangeCharacterAddressGroup(CharacterFromID("Francisco Cruz"), "Hispaniola_shore_02", "goto", "locator4");
			LAi_group_MoveCharacter(CharacterFromID("Francisco Cruz"), "HUBONI_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "bocman3", "goto", "locator6");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "HUBON_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man1", "goto", "citizen02");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "HUBON_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "sailor7", "goto", "locator3");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "bartpirate_dialog.c";
			sld.id = "rivcrew";
			LAi_group_MoveCharacter(characterFromID("rivcrew"), "HUBONI_PIRATES");

			LAi_SetImmortal(characterFromID("Francisco Cruz"), true);
			LAi_SetImmortal(characterFromID("rivcrew"), true);
			LAi_SetImmortal(characterFromID("bart_pirate_06"), true);

			LAi_group_FightGroups("HUBON_PIRATES", LAI_GROUP_PLAYER, true);
			LAi_group_FightGroups("HUBONI_PIRATES", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("HUBON_PIRATES", "finbathub");

			break;

		case "finbathub":
			LAi_group_FightGroups("HUBONI_PIRATES", LAI_GROUP_PLAYER, false);
			LAi_SetActorType(characterFromID("Francisco Cruz"));
			LAi_ActorFollow(characterFromID("Francisco Cruz"), characterFromID("rivcrew"), "", 10.0);
			Characters[GetCharacterIndex("rivcrew")].dialog.currentnode = "begin_9";
			LAi_SetActorType(characterFromID("rivcrew"));
			LAi_ActorDialog(characterFromID("rivcrew"), pchar, "", 5.0, 1.0);

			break;

		case "finbathub2":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_54";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 3.0, 1.0);
			LAi_SetActorType(characterFromID("bart_pirate_06"));
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_06"), "", 60.0);
			Characters[GetCharacterIndex("Eugene Martin")].dialog.currentnode = "begin_50";
			LAi_SetActorType(characterFromID("rivcrew"));
			LAi_ActorRunToLocation(characterFromID("rivcrew"), "goto", "locator4", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Francisco Cruz"));
			LAi_ActorRunToLocation(characterFromID("Francisco Cruz"), "goto", "locator4", "none", "", "", "", 0.0);

			break;

		case "gocuba":
			DeleteAttribute(pchar, "sailaway");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			AddQuestRecord("Bad_Blaze", "9");
			CloseQuestHeader("Bad_Blaze");
			locations[FindLocation("Hispaniola_shore_02")].reload.l2.disable = 0;
			pchar.stolen.ship.type   = pchar.ship.type;
			pchar.stolen.ship.name   = pchar.ship.name;
			GiveShip2Character(pchar,"Ketch","l'Insouciante",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Hispaniola_shore_02");
			Pchar.quest.find_ketch.win_condition.l1 = "location";
			Pchar.quest.find_ketch.win_condition.l1.location = "Hispaniola_shore_02";
			PChar.quest.find_ketch.win_condition = "gocuba_1";

			break;

			// Anaconda's Capture

		case "gocuba_1":
			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			LAi_SetImmortal(characterFromID("Emilio Soares"), false);
			LAi_SetOfficerType(characterFromID("bart_pirate_06"));
			LAi_SetImmortal(characterFromID("bart_pirate_06"), false);
			ChangeCharacterAddress(characterFromID("Emilio Soares"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_06"), "none", "");
			DisableFastTravel(false);
			DisableMenuLaunch(false);

			Pchar.quest.find_Anaconda.win_condition.l1 = "location";
			Pchar.quest.find_Anaconda.win_condition.l1.location = "IslaMuelle";
			PChar.quest.find_Anaconda.win_condition = "gocuba_2";

			SetCharacterGoods(CharacterFromID("Florentino Murrieta"), GOOD_EBONY, 180);
			SetCharacterGoods(CharacterFromID("Florentino Murrieta"), GOOD_MAHOGANY, 120);
			SetCharacterGoods(CharacterFromID("Florentino Murrieta"), GOOD_GOLD, 100);
			SetCharacterGoods(CharacterFromID("Florentino Murrieta"), GOOD_SILVER, 150);

			break;

		case "gocuba_2":
			SetRMRelation(PChar, SPAIN, REL_WAR);
			ChangeCharacterAddress(characterFromID("Eugene Martin"), "none", "");
			SetCharacterRelationBoth(GetCharacterIndex("Florentino Murrieta"),GetMainCharacterIndex(),RELATION_ENEMY);

			Group_CreateGroup("Florentino Murrieta");
			Group_AddCharacter("Florentino Murrieta", "Florentino Murrieta");
			Group_SetGroupCommander("Florentino Murrieta", "Florentino Murrieta");
			Group_SetPursuitGroup("Florentino Murrieta", PLAYER_GROUP);
			Group_SetTaskAttack("Florentino Murrieta", PLAYER_GROUP, true);
			Group_LockTask("Florentino Murrieta");
			Group_SetAddress("Florentino Murrieta", Characters[GetMainCharacterIndex()].location, "", "");

			UpdateRelations();

			Pchar.quest.Meet_Anaconda.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Anaconda.win_condition.l1.character = "Florentino Murrieta";
			Pchar.quest.Meet_Anaconda.win_condition = "Story_Capture_Anaconda";

			break;

		case "Story_Capture_Anaconda":
			Pchar.quest.Meet_Anaconda.over = "yes";
			SetQuestHeader("Anaconda_Capture");
			AddQuestRecord("Anaconda_Capture","1");
			Pchar.quest.Meet_Alfonso.win_condition.l1 = "location";
			Pchar.quest.Meet_Alfonso.win_condition.l1.location = "Redmond";
			PChar.quest.Meet_Alfonso.win_condition = "meetalfonso";

			break;

		case "meetalfonso":
			SetCharacterRelationBoth(GetCharacterIndex("Alfonso Galindez"),GetMainCharacterIndex(),RELATION_FRIEND);

			Group_CreateGroup("Alfonso Galindez");
			Group_AddCharacter("Alfonso Galindez", "Alfonso Galindez");
			Group_SetGroupCommander("Alfonso Galindez", "Alfonso Galindez");
			Group_SetPursuitGroup("Alfonso Galindez", PLAYER_GROUP);
			Group_SetTaskAttack("Alfonso Galindez", PLAYER_GROUP, true);
			Group_LockTask("Alfonso Galindez");
			Group_SetAddress("Alfonso Galindez", Characters[GetMainCharacterIndex()].location, "", "");

			SetCharacterRelationBoth(GetCharacterIndex("Spanish Captain2"),GetMainCharacterIndex(),RELATION_FRIEND);

			Group_CreateGroup("Spanish Captain2");
			Group_AddCharacter("Spanish Captain2", "Spanish Captain2");
			Group_SetGroupCommander("Spanish Captain2", "Spanish Captain2");
			Group_SetPursuitGroup("Spanish Captain2", PLAYER_GROUP);
			Group_SetTaskAttack("Spanish Captain2", PLAYER_GROUP, true);
			Group_LockTask("Spanish Captain2");
			Group_SetAddress("Spanish Captain2", Characters[GetMainCharacterIndex()].location, "", "");


			SetCharacterRelationBoth(GetCharacterIndex("Spanish Captain3"),GetMainCharacterIndex(),RELATION_FRIEND);

			Group_CreateGroup("Spanish Captain3");
			Group_AddCharacter("Spanish Captain3", "Spanish Captain3");
			Group_SetGroupCommander("Spanish Captain3", "Spanish Captain3");
			Group_SetPursuitGroup("Spanish Captain3", PLAYER_GROUP);
			Group_SetTaskAttack("Spanish Captain3", PLAYER_GROUP, true);
			Group_LockTask("Spanish Captain3");
			Group_SetAddress("Spanish Captain3", Characters[GetMainCharacterIndex()].location, "", "");

			SetCharacterRelationBoth(GetCharacterIndex("Alfonso Galindez"),GetCharacterIndex("Spanish Captain3"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Alfonso Galindez"),GetCharacterIndex("Spanish Captain2"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Spanish Captain3"),GetCharacterIndex("Spanish Captain2"),RELATION_FRIEND);

			UpdateRelations();
			DoQuestCheckDelay("Alfonso_Deck", 10.0);

			break;

		case "Alfonso_Deck":
			DoQuestReloadToLocation("Quest_ShipDeck6", "reload", "boatr","_");
			ChangeCharacterAddressGroup(CharacterFromID("Alfonso Galindez"), "Quest_ShipDeck6", "goto", "goto11");

			ChangeCharacterAddressGroup(CharacterFromID("spanish_soldier_01"), "Quest_ShipDeck6", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("spanish_soldier_02"), "Quest_ShipDeck6", "goto", "goto3");
			LAi_SetActorType(characterFromID("spanish_soldier_01"));
			LAi_ActorFollow(characterFromID("spanish_soldier_01"), characterFromID("Alfonso Galindez"), "", 10.0);
			LAi_SetActorType(characterFromID("spanish_soldier_02"));
			LAi_ActorFollow(characterFromID("spanish_soldier_02"), characterFromID("Alfonso Galindez"), "", 10.0);

			LAi_SetActorType(characterFromID("Alfonso Galindez"));
			Characters[GetCharacterIndex("Alfonso Galindez")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Alfonso Galindez"), pchar, "", 3.0, 1.0);

			break;

		case "Anaconda_Cargo":
			SetCharacterShipLocation(Pchar, "Santo_Domingo_Port");
			DisableFastTravel(true);
			DisableMenuLaunch(true);

			DoQuestReloadToLocation("Quest_Hold1", "rld", "startloc","_");
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Quest_Hold1", "reload", "reload1");

			GiveItem2Character(CharacterFromId("Emilio Soares"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Emilio Soares"), "bladex4");
			GiveItem2Character(CharacterFromId("Emilio Soares"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Emilio Soares"), "pistolrock");

			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			EquipCharacterByItem(pchar, "bladeX4");
			Log_SetStringToLog(TranslateString("","A few days later") + ".");

			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_18";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 10.0, 1.0);

			break;

		case "safeonbeach":
			Change_MainThemeMusic_Chance(5);
			Group_SetAddressNone("Alfonso Galindez");
			Group_SetAddressNone("Spanish Captain2");
			Group_SetAddressNone("Spanish Captain3");

			DoQuestReloadToLocation("Hispaniola_shore_01", "goto", "goto8","_");
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Hispaniola_shore_01", "reload", "reload1");
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(pchar, GUN_ITEM_TYPE);
			EquipCharacterByItem(characterFromID("Emilio Soares"), "blade4");
			EquipCharacterByItem(characterFromID("Emilio Soares"), "pistol1a");

			locations[FindLocation("Santo_Domingo_town_exit_1")].reload.l1.disable = 1;
			Island_SetReloadEnableLocal("Hispaniola", "reload_3", false);

			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_22";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 10.0, 1.0);

			break;

		case "allervillage":
			AddQuestRecord("Anaconda_Capture","2");
			ChangeCharacterAddressGroup(CharacterFromID("Sean Sparrow"), "Hispaniola_village", "goto", "goto39");
			Characters[GetCharacterIndex("Sean Sparrow")].dialog.currentnode = "begin_4";
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorFollowEverywhere(characterFromID("Emilio Soares"), "", 60.0);

			break;

		case "renforce":
			AddQuestRecord("Anaconda_Capture","3");
			LAi_SetActorType(CharacterFromID("Sean Sparrow"));
			LAi_ActorRunToLocation(characterFromID("Sean Sparrow"), "reload", "reload3", "none", "", "", "", 0.0);
			Pchar.quest.sean_yuman.win_condition.l1 = "location";
			Pchar.quest.sean_yuman.win_condition.l1.location = "Hispaniola_shore_01";
			PChar.quest.sean_yuman.win_condition = "renforce_3";

			GiveShip2Character(pchar,"Tartane1","Perla Negra",-1,SPAIN,true,true);
			SetCharacterShipLocation(Pchar, "Hispaniola_shore_01");
			locations[FindLocation("Hispaniola_shore_01")].reload.l2.disable = 1;

			break;

		case "renforce_3":
			ChangeCharacterAddressGroup(CharacterFromID("Sean Sparrow"), "Hispaniola_shore_01", "reload", "reload1");
			LAi_SetStayType(CharacterFromID("Sean Sparrow"));
			Characters[GetCharacterIndex("Sean Sparrow")].dialog.currentnode = "begin_10";

			break;

		case "renforce_4":
			DisableFastTravel(false);
			DisableMenuLaunch(false);

			locations[FindLocation("Hispaniola_shore_01")].reload.l2.disable = 0;
			ChangeCharacterAddressGroup(CharacterFromID("Sean Sparrow"), "Hispaniola_shore_02", "goto", "locator12");
			Pchar.quest.sean_hubon.win_condition.l1 = "location";
			Pchar.quest.sean_hubon.win_condition.l1.location = "Hispaniola_shore_02";
			PChar.quest.sean_hubon.win_condition = "renforce_5";

			break;

		case "renforce_5":
			LAi_SetActorType(characterFromID("Sean Sparrow"));
			Characters[GetCharacterIndex("Sean Sparrow")].dialog.currentnode = "begin_11";
			LAi_ActorDialog(characterFromID("Sean Sparrow"), pchar, "", 3.0, 1.0);

			break;

		case "renforce_6":
			ChangeCharacterAddressGroup(characterFromID("Eugene Martin"), "BC_tavern", "Sit", "Sit13");
			LAi_SetSitType(characterFromID("Eugene Martin"));
			Characters[GetCharacterIndex("Eugene Martin")].dialog.currentnode = "begin_28";

			break;

		case "renforts":
			DoQuestReloadToLocation("Buccaneers_Camp", "goto", "goto42", "_");
			ChangeCharacterAddressGroup(characterFromID("Eugene Martin"), "Buccaneers_Camp", "goto", "goto39");
			ChangeCharacterAddressGroup(characterFromID("Benoit Belcour"), "Buccaneers_Camp", "officers", "reload5_3");
			ChangeCharacterAddressGroup(characterFromID("Adriance Blind"), "Buccaneers_Camp", "goto", "goto12");
			LAi_SetActorType(characterFromID("Benoit Belcour"));
			LAi_SetImmortal(CharacterFromID("Benoit Belcour"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Benoit Belcour"), "", 60.0);

			LAi_SetActorType(characterFromID("Adriance Blind"));
			LAi_SetImmortal(CharacterFromID("Adriance Blind"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Adriance Blind"), "", 60.0);

			LAi_SetActorType(characterFromID("Eugene Martin"));
			Characters[GetCharacterIndex("Eugene Martin")].dialog.currentnode = "begin_34";
			LAi_ActorDialog(characterFromID("Eugene Martin"), pchar, "", 3.0, 1.0);

			break;

		case "renforts_2":
			LAi_SetActorType(characterFromID("Benoit Belcour"));
			Characters[GetCharacterIndex("Benoit Belcour")].dialog.currentnode = "begin_35";
			LAi_ActorDialog(characterFromID("Benoit Belcour"), pchar, "", 3.0, 1.0);

			break;

		case "renforts_2bis":
			LAi_SetActorType(characterFromID("Adriance Blind"));
			Characters[GetCharacterIndex("Adriance Blind")].dialog.currentnode = "begin_41";
			LAi_ActorDialog(characterFromID("Adriance Blind"), pchar, "", 3.0, 1.0);

			break;

		case "renforts_3":
			LAi_SetActorType(characterFromID("Eugene Martin"));
			Characters[GetCharacterIndex("Eugene Martin")].dialog.currentnode = "begin_37";
			LAi_ActorDialog(characterFromID("Eugene Martin"), pchar, "", 3.0, 1.0);

			break;

		case "renforts_4":
			AddQuestRecord("Anaconda_Capture","4");
			LAi_SetActorType(CharacterFromID("Eugene Martin"));
			LAi_ActorRunToLocation(characterFromID("Eugene Martin"), "reload", "reload4", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Benoit Belcour"));
			LAi_ActorFollowEverywhere(characterFromID("Benoit Belcour"), "", 60.0);
			LAi_SetActorType(characterFromID("Adriance Blind"));
			LAi_ActorFollowEverywhere(characterFromID("Adriance Blind"), "", 60.0);

			Pchar.quest.sean_again.win_condition.l1 = "location";
			Pchar.quest.sean_again.win_condition.l1.location = "Hispaniola_shore_02";
			PChar.quest.sean_again.win_condition = "renforts_5";

			break;

		case "renforts_5":
			ChangeCharacterAddressGroup(characterFromID("Sean Sparrow"), "Hispaniola_shore_02", "goto", "locator7");
			LAi_SetActorType(characterFromID("Sean Sparrow"));
			Characters[GetCharacterIndex("Sean Sparrow")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Sean Sparrow"), pchar, "", 30.0, 1.0);

			break;

		case "retour_yuman":
			LAi_SetActorType(characterFromID("Sean Sparrow"));
			LAi_ActorFollowEverywhere(characterFromID("Sean Sparrow"), "", 60.0);

			Pchar.quest.sean_adios.win_condition.l1 = "location";
			Pchar.quest.sean_adios.win_condition.l1.location = "Hispaniola_shore_01";
			PChar.quest.sean_adios.win_condition = "voir_iguaran";

			break;

		case "voir_iguaran":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			locations[FindLocation("Hispaniola_shore_01")].reload.l2.disable = 1;
			LAi_SetActorType(characterFromID("Sean Sparrow"));
			Characters[GetCharacterIndex("Sean Sparrow")].dialog.currentnode = "begin_17";
			LAi_ActorDialog(characterFromID("Sean Sparrow"), pchar, "", 3.0, 1.0);

			break;

		case "voir_iguaran2":
			LAi_SetActorType(CharacterFromID("Sean Sparrow"));
			LAi_ActorRunToLocation(characterFromID("Sean Sparrow"), "reload", "reload1", "none", "", "", "", 0.0);
		//	ChangeCharacterAddressGroup(characterFromID("Padre Iguaran"), "village_church", "goto", "goto11");
			Characters[GetCharacterIndex("Padre Iguaran")].Dialog.Filename = "Spaniards_dialog.c";
			Characters[GetCharacterIndex("Padre Iguaran")].Dialog.CurrentNode = "begin_18";
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].Dialog.CurrentNode = "begin_25";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 3.0, 1.0);

			break;

		case "giflepretre":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Padre Iguaran"));
			LAi_ActorAnimation(pchar, "attack_fast_2", "habitmoine", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");

			break;

		case "habitmoine":
			SetCharacterTask_Dead(characterFromID("Padre Iguaran")); // PB: was LAi_KillCharacter
			LAi_QuestDelay("habitmoine2", 2.0);

			break;

		case "habitmoine2":
			LAi_Fade("habitmoine3", "habitmoine31");
			ChangeCharacterAddress(characterFromID("Padre Iguaran"), "none", "");
			break;

		case "habitmoine3":
			LAi_SetPlayerType(pchar);
			SetModelfromArray(&pchar, GetModelIndex("Animistse"));
			SetModelfromArray(characterFromID("Emilio Soares"), GetModelIndex("Animists2"));
			SetModelfromArray(characterFromID("Benoit Belcour"), GetModelIndex("Animists3"));
			SetModelfromArray(characterFromID("Adriance Blind"), GetModelIndex("Animists3"));

			GiveItem2Character(Pchar, "Barmansknife");
			EquipCharacterByItem(Pchar, "Barmansknife");
			GiveItem2Character(Pchar, "pistolrock");
			EquipCharacterByItem(Pchar, "pistolrock");

			GiveItem2Character(CharacterFromId("Adriance Blind"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Adriance Blind"), "bladex4");
			GiveItem2Character(CharacterFromId("Benoit Belcour"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Benoit Belcour"), "bladex4");
			GiveItem2Character(CharacterFromId("Emilio Soares"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Emilio Soares"), "bladex4");

			GiveItem2Character(CharacterFromId("Adriance Blind"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Adriance Blind"), "pistolrock");
			GiveItem2Character(CharacterFromId("Benoit Belcour"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Benoit Belcour"), "pistolrock");
			GiveItem2Character(CharacterFromId("Emilio Soares"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Emilio Soares"), "pistolrock");

			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_27";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 3.0, 1.0);

			break;

		case "habitmoine31":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_27";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 3.0, 1.0);
			break;

		case "domingsoldat":
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			AddQuestRecord("Anaconda_Capture","5");
			SetCurrentTime(23, 0);
			locations[FindLocation("Santo_Domingo_town_exit_1")].reload.l1.disable = 0;
			AddPassenger(Pchar, characterFromID("Emilio Soares"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Emilio Soares"));
			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			AddPassenger(Pchar, characterFromID("Adriance Blind"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Adriance Blind"));
			LAi_SetOfficerType(characterFromID("Adriance Blind"));
			AddPassenger(Pchar, characterFromID("Benoit Belcour"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Benoit Belcour"));
			LAi_SetOfficerType(characterFromID("Benoit Belcour"));
			LAi_SetImmortal(CharacterFromID("Emilio Soares"), true);

			Pchar.quest.meet_garde.win_condition.l1 = "location";
			Pchar.quest.meet_garde.win_condition.l1.location = "Santo_Domingo_town";
			PChar.quest.meet_garde.win_condition = "porte_garde";

			break;

		case "porte_garde":
			// PB: Return the Padre -->
			ChangeCharacterAddressGroup(characterFromID("Padre Iguaran"), "village_church", "goto", "goto11");
			Characters[GetCharacterIndex("Padre Iguaran")].Dialog.Filename = "Father Abbott_dialog.c";
			Characters[GetCharacterIndex("Padre Iguaran")].Dialog.Filename.group = "church.c";
			LAi_SetMerchantType(characterFromID("Padre Iguaran"));
			// PB: Return the Padre <--
			
			locations[FindLocation("Santo_Domingo_town")].reload.l3.disable = 1;
			locations[FindLocation("Hispaniola_shore_01")].reload.l2.disable = 0;
			ChangeCharacterAddressGroup(characterFromID("spanish_soldier_01"), "Santo_Domingo_town", "goto", "goto52");
			Characters[GetCharacterIndex("spanish_soldier_01")].dialog.filename = "Spaniards_dialog.c";
			Characters[GetCharacterIndex("spanish_soldier_01")].dialog.CurrentNode = "begin_22";
			LAi_SetActorType(characterFromID("spanish_soldier_01"));
			LAi_ActorDialog(characterFromID("spanish_soldier_01"), pchar, "", 2.0, 1.0);

			break;

		case "chegar_porto":
			LAi_SetGuardianType(characterFromID("spanish_soldier_01"));
			pchar.quest.epeeperdue.win_condition.l1 = "locator";
			pchar.quest.epeeperdue.win_condition.l1.location = "Santo_Domingo_town";
			pchar.quest.epeeperdue.win_condition.l1.locator_group = "reload";
			pchar.quest.epeeperdue.win_condition.l1.locator = "reload1";
			pchar.quest.epeeperdue.win_condition = "chegar_porto1";

			break;

		case "chegar_porto1":
			DoQuestReloadToLocation("Quest_Domingo_port", "reload", "reload4", "chegar_porto2");
			GiveShip2Character(pchar,"PO_Fleut50","Anaconda",-1,SPAIN,true,true);
			SetCharacterShipLocation(pchar, "Quest_Domingo_port");
			Island_SetReloadEnableLocal("Hispaniola", "reload_3", true);
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);

			break;

		case "chegar_porto2":
			locations[FindLocation("Santo_Domingo_town")].reload.l3.disable = 0;
			locations[FindLocation("Quest_Domingo_port")].reload.l1.disable = 1;
			locations[FindLocation("Quest_Domingo_port")].reload.l3.disable = 1;
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_spa4_16", "officers", "reload1_2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "Spaniards_dialog.c";
			sld.dialog.currentnode = "begin_24";
			sld.id = "soldat1";
			LAi_SetGuardianType(characterFromID("soldat1"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_spa5_16", "officers", "reload1_1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "Spaniards_dialog.c";
			sld.dialog.currentnode = "begin_24";
			sld.id = "soldat";
			LAi_SetGuardianType(characterFromID("soldat"));

			break;

		case "comecobat":
			GiveItem2Character(CharacterFromId("Emilio Soares"), "blade10");
			EquipCharacterByItem(characterFromID("Emilio Soares"), "blade10");
			EquipCharacterByItem(characterFromID("Emilio Soares"), "pistol1a");
			GiveItem2Character(CharacterFromId("Benoit Belcour"), "blade10");
			EquipCharacterByItem(characterFromID("Benoit Belcour"), "blade10");
			EquipCharacterByItem(characterFromID("Benoit Belcour"), "pistol1a");
			GiveItem2Character(CharacterFromId("Adriance Blind"), "blade10");
			EquipCharacterByItem(characterFromID("Adriance Blind"), "blade10");
			EquipCharacterByItem(characterFromID("Adriance Blind"), "pistol1a");

			LAi_group_MoveCharacter(characterFromID("soldat"), "PORTO_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("soldat1"), "PORTO_SOLDIERS");
			LAi_group_FightGroups("PORTO_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PORTO_SOLDIERS", "fimbatalha");

			break;

		case "fimbatalha":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_30";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 10.0, 1.0);

			break;

		case "dansoute":
			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			LAi_SetActorType(characterFromID("Adriance Blind"));
			Characters[GetCharacterIndex("Adriance Blind")].dialog.currentnode = "begin_38";
			LAi_ActorDialog(characterFromID("Adriance Blind"), pchar, "", 3.0, 1.0);

			break;


		case "dansoute_2":
			LAi_SetMerchantType(characterFromID("Adriance Blind"));
			LAi_SetMerchantType(characterFromID("Benoit Belcour"));
			DoQuestReloadToLocation("Quest_Hold1", "reload", "reload1", "fight_soute");

			break;

		case "fight_soute":
			GiveModel2Player("GypsyCaptn_3", true);
			SetModelfromArray(characterFromID("Emilio Soares"), GetModelIndex("Emilio1"));
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "Quest_Hold1", "rld", "startloc");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "rld", "prison4");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CARGO_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "reload", "reload2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CARGO_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "reload", "reload2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CARGO_SOLDIERS");

			LAi_group_FightGroups("CARGO_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("CARGO_SOLDIERS", "search_crew");

			break;

		case "search_crew":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_31";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 4.0, 4.0);

			break;

		case "find_crew":
			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			DoQuestReloadToLocation("Quest_Hold1", "reload", "reload1", "find_crew2");

			break;

		case "find_crew2":
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_01"), "Quest_Hold1", "rld", "prison4");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Quest_Hold1", "rld", "prison3");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Quest_Hold1", "rld", "prison5");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Quest_Hold1", "rld", "prison2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Quest_Hold1", "rld", "prison1");
			Characters[GetCharacterIndex("bart_pirate_05")].dialog.CurrentNode = "begin_4";
			LAi_SetActorType(characterFromID("bart_pirate_05"));
			LAi_ActorDialog(characterFromID("bart_pirate_05"), pchar, "", 3.0, 1.0);

			break;


		case "quitterport":
			DoQuestReloadToLocation("Quest_Domingo_port", "reload", "reload1", "quitterport2");

			break;

		case "quitterport2":
			SetModelfromArray(characterFromID("Benoit Belcour"), GetModelIndex("50evl2in"));
			SetModelfromArray(characterFromID("Adriance Blind"), GetModelIndex("Will_2"));
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "Quest_Domingo_port", "officers", "reload1_2");

			ChangeCharacterAddressGroup(characterFromID("Adriance Blind"), "Quest_Domingo_port", "officers", "reload1_1");

			ChangeCharacterAddressGroup(characterFromID("Benoit Belcour"), "Quest_Domingo_port", "goto", "goto21");

			LAi_SetActorType(characterFromID("Benoit Belcour"));
			Characters[GetCharacterIndex("Benoit Belcour")].dialog.currentnode = "begin_39";
			LAi_ActorDialog(characterFromID("Benoit Belcour"), pchar, "", 4.0, 2.0);

			break;

		case "quitterport3":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_32";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 4.0, 1.0);

			break;

		case "quitterport4":
			SetRMRelation(PChar, SPAIN, REL_AMNESTY);
			HoistFlag(SPAIN);
			SetCharacterRelationBoth(GetCharacterIndex("Santo Domingo Commander"), GetMainCharacterIndex(), RELATION_FRIEND);

			AddQuestRecord("Anaconda_Capture","6");
			CloseQuestHeader("Anaconda_Capture");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			bSuppressResurrection = false;
			LAi_QuestDelay("quitterport5", 0.0);
			locations[FindLocation("Quest_Domingo_port")].reload.l1.disable = 0;
			locations[FindLocation("Quest_Domingo_port")].reload.l3.disable = 0;
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			RemovePassenger(pchar, characterFromID("Emilio Soares"));
			RemoveCharacterCompanion(pchar, characterFromID("Emilio Soares"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Emilio Soares"));
			LAi_SetOfficerType(characterFromID("Benoit Belcour"));
			LAi_SetOfficerType(characterFromID("Adriance Blind"));
			LAi_SetImmortal(characterFromID("Benoit Belcour"), false);
			LAi_SetImmortal(characterFromID("Adriance Blind"), false);
			Characters[GetCharacterIndex("Benoit Belcour")].dialog.filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Benoit Belcour")].dialog.CurrentNode = "hired";			
			Characters[GetCharacterIndex("Adriance Blind")].dialog.filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Adriance Blind")].dialog.CurrentNode = "hired";
			break;

		case "quitterport5":
			LAi_SetActorType(CharacterFromID("Emilio Soares"));
			LAi_QuestDelay("gokhael", 0.0);

			Pchar.quest.find_problem.win_condition.l1 = "location";
			Pchar.quest.find_problem.win_condition.l1.location = "Santo_Domingo_Port";
			PChar.quest.find_problem.win_condition = "quitterport6";

			break;

		case "quitterport6":
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			SetCharacterRelationBoth(GetCharacterIndex("Santo Domingo Commander"), GetMainCharacterIndex(), RELATION_ENEMY);

			break;

			// Bad Luck

		case "gokhael":
			Pchar.quest.find_Battleship.win_condition.l1 = "location";
			Pchar.quest.find_Battleship.win_condition.l1.location = "KhaelRoa";
			PChar.quest.find_Battleship.win_condition = "gokhael_2";

			break;

		case "gokhael_2":
			Build_at("Santo_Domingo_port", "Sign", "", 0, 6.59, 18.85, 1.7, "building");
			Locations[FindLocation("Santo_Domingo_town")].dangerous = true;
			Locations[FindLocation("Santo_Domingo_port")].dangerous = true;
			ChangeRMRelation(pchar, SPAIN, -20.0);
			Pchar.quest.find_problem.over = "yes";
			pchar.ship.hp = 3000;
			SetCharacterRelationBoth(GetCharacterIndex("Spanish Captain"),GetMainCharacterIndex(),RELATION_ENEMY);

			Group_CreateGroup("Spanish Captain");
			Group_AddCharacter("Spanish Captain", "Spanish Captain");
			Group_SetGroupCommander("Spanish Captain", "Spanish Captain");
			Group_SetPursuitGroup("Spanish Captain", PLAYER_GROUP);
			Group_SetTaskAttack("Spanish Captain", PLAYER_GROUP, true);
			Group_SetAddress("Spanish Captain", "KhaelRoa", "Quest_ships", "Quest_ship_12");
			Group_LockTask("Spanish Captain");
			UpdateRelations();
			characters[GetCharacterIndex("Spanish Captain")].nosurrender = 2;
			Character_SetAbordageEnable(characterFromID("Spanish Captain"), false);
			SetQuestHeader("Bad_Luck");
			AddQuestRecord("Bad_Luck","1");

			Pchar.quest.tornado.win_condition.l1 = "location";
			Pchar.quest.tornado.win_condition.l1.location = "Cuba";
			PChar.quest.tornado.win_condition = "ouragan";

			break;

		case "ouragan":
			Group_SetAddressNone("Spanish Captain");
			SetNextWeather("Day storm");
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			iStormLockSeconds = 60;
			DoQuestCheckDelay("ouragan2", 5.0);
			break;

		case "ouragan2":
			PostVideoAndQuest("wreck",1, "echouer");

			break;

		case "echouer":
			DoQuestReloadToLocation("Cuba_shore_03", "goto", "locator10","_");
			SetModelfromArray(characterFromID("Emilio Soares"), GetModelIndex("Emilio2"));

			GiveItem2Character(CharacterFromId("bart_pirate_06"), "bladex4");
			EquipCharacterByItem(CharacterFromId("bart_pirate_06"), "bladex4");
			GiveItem2Character(CharacterFromId("bart_pirate_06"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("bart_pirate_06"), "pistolrock");
			LAi_NoRebirthDisable(characterFromID("bart_pirate_06"));

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_01"), "Cuba_shore_03", "reload", "reload2_back");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Cuba_shore_03", "reload", "reload2_back");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Cuba_shore_03", "reload", "reload2_back");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Cuba_shore_03", "reload", "reload2_back");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Cuba_shore_03", "reload", "reload2_back");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Cuba_shore_03", "reload", "reload2_back");
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Cuba_shore_03", "officers", "reload2_1");
			GiveItem2Character(CharacterFromId("Emilio Soares"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Emilio Soares"), "bladex4");
			GiveItem2Character(CharacterFromId("Emilio Soares"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Emilio Soares"), "pistolrock");

			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 20.0, 1.0);
			LAi_QuestDelay("retrouvcrew", 3.0);
			locations[FindLocation("Cuba_Jungle_02")].vcskip = true;
			PlayStereoSound("NATURE\wind_tornado.wav");

			break;

		case "retrouvcrew":

			LAi_SetActorType(characterFromID("bart_pirate_01"));
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_01"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_02"));
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_02"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_03"));
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_03"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_04"));
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_04"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_05"));
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_05"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_06"));
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_06"), "", 60.0);

			break;

		case "voirpatrol":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorFollowEverywhere(characterFromID("Emilio Soares"), "", 60.0);
			Pchar.quest.voirpat.win_condition.l1 = "location";
			Pchar.quest.voirpat.win_condition.l1.location = "Cuba_Jungle_02";
			PChar.quest.voirpat.win_condition = "voirpatrol2";

			break;

		case "voirpatrol2":
			bSuppressResurrection = true;
			locations[FindLocation("Cuba_Jungle_02")].reload.l5.disable = 1;
			locations[FindLocation("Cuba_Jungle_02")].reload.l6.disable = 1;
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Cuba_Jungle_02", "officers", "reload1_3");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);

			break;

		case "fuirpatrol":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDIERS");
			LAi_SetImmortal(sld, true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDIERS");
			LAi_SetImmortal(sld, true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDIERS");
			LAi_SetImmortal(sld, true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDIERS");
			LAi_SetImmortal(sld, true);


			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDIERS");
			LAi_SetImmortal(sld, true);
			LAi_group_FightGroups("CUBAN_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_SetStayType(characterFromID("bart_pirate_01"));
			LAi_SetStayType(characterFromID("bart_pirate_02"));
			LAi_SetStayType(characterFromID("bart_pirate_03"));
			LAi_SetStayType(characterFromID("bart_pirate_04"));
			LAi_SetStayType(characterFromID("bart_pirate_05"));
			LAi_SetStayType(characterFromID("bart_pirate_06"));

			Pchar.quest.fuirpatr.win_condition.l1 = "location";
			Pchar.quest.fuirpatr.win_condition.l1.location = "Cuba_Jungle_03";
			PChar.quest.fuirpatr.win_condition = "fuirpatrol2";

			break;

		case "fuirpatrol2":
			locations[FindLocation("Cuba_Jungle_02")].reload.l5.disable = 0;
			locations[FindLocation("Cuba_Jungle_02")].reload.l6.disable = 0;
			locations[FindLocation("Cuba_Jungle_03")].reload.l2.disable = 1;
			locations[FindLocation("Cuba_Jungle_03")].reload.l5.disable = 1;
			AddQuestRecord("Bad_Luck","2");
			AddGeometryToLocation("Cuba_shore_04", "smg");
			ChangeCharacterAddressGroup(CharacterFromID("Simon Chapman"), "Cuba_shore_04", "goto", "locator10");
			Characters[GetCharacterIndex("Simon Chapman")].dialog.currentnode = "begin_1";

			break;

		case "vaiscayman":
			DoQuestReloadToLocation("Cuba_shore_04", "goto", "locator24", "vaiscayman1");
			SetNextWeather("Blue Sky");
			RemoveGeometryFromLocation("Cuba_shore_04", "smg");
			GiveShip2Character(pchar,"Cutter1","The Fickle",-1,ENGLAND,true,true);
			SetCharacterShipLocation(Pchar, "Cuba_shore_04");
			locations[FindLocation("Cuba_Jungle_03")].reload.l2.disable = 0;
			locations[FindLocation("Cuba_Jungle_03")].reload.l5.disable = 0;

			break;

		case "vaiscayman1":
			ChangeCharacterAddressGroup(CharacterFromID("Simon Chapman"), "Cuba_shore_04", "goto", "locator8");
			LAi_SetActorType(characterFromID("Simon Chapman"));
			Characters[GetCharacterIndex("Simon Chapman")].dialog.currentnode = "begin_15";
			LAi_ActorDialog(characterFromID("Simon Chapman"), pchar, "", 3.0, 1.0);

			break;

		case "vaiscayman2":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_ActorRunToLocation(characterFromID("Simon Chapman"), "goto", "locator12", "none", "", "", "", 0.0);
			ChangeCharacterAddress(characterFromID("Emilio Soares"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_01"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_02"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_03"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_04"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_05"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_06"), "none", "");

			Pchar.quest.arrivcay.win_condition.l1 = "location";
			Pchar.quest.arrivcay.win_condition.l1.location = "Cayman_Port";
			PChar.quest.arrivcay.win_condition = "despsimon";

			break;

		case "despsimon":
			locations[FindLocation("Cayman_Port")].reload.l4.disable = 1;
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			ChangeCharacterAddressGroup(CharacterFromID("Simon Chapman"), "Cayman_Port", "officers", "Sea_1");
			LAi_SetActorType(characterFromID("Simon Chapman"));
			Characters[GetCharacterIndex("Simon Chapman")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Simon Chapman"), pchar, "", 2.0, 1.0);

			break;

		case "byesimon":
			GiveShip2Character(pchar,"Tartane1","Nothing",-1,PIRATE,true,true);
			LAi_SetCitizenType(characterFromID("Simon Chapman"));
			AddQuestRecord("Bad_Luck", "3");
			CloseQuestHeader("Bad_Luck");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			bSuppressResurrection = false;
			LAi_QuestDelay("Bartolomeu_start", 0.0);

			break;

			// Save the Crew

		case "Bartolomeu_start":
			ChangeCharacterAddressGroup(CharacterFromID("William Klein"), "Grand_Cayman_Tavern", "sit", "sit4");
			LAi_SetSitType(characterFromID("William Klein"));
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_1";

			break;

		case "Bartolomeu_search":
			PChar.quest.Bartolomeu = "search";

			locations[FindLocation("Cayman_Port")].reload.l4.disable = 0;
			Island_SetReloadEnableLocal("Cuba", "reload_3", false);
			Locations[FindLocation("Cuba_Jungle_01")].reload.l4.disable = true;
			Locations[FindLocation("Cuba_Jungle_02")].reload.l5.disable = true;
			bSuppressResurrection = true;
			SetQuestHeader("William_Klein");
			AddQuestRecord("William_Klein", "1");
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "William Klein";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Cuba_shore_01";
			PChar.quest.Bartolomeu.win_condition = "essai";
			GiveShip2Character(pchar,"LuggerVML","Fancy",-1,ENGLAND,true,true);
			LAi_Fade("William_follow2", "");
			break;

		case "William_follow2":
			PlaceCharacter(characterFromID("William Klein"), "goto");
			LAi_SetActorType(characterFromID("William Klein"));
			LAi_SetImmortal(CharacterFromID("William Klein"), 1);
			LAi_ActorFollowEverywhere(characterFromID("William Klein"), "", 60.0);
			ChangeCharacterAddress(characterFromID("Simon Chapman"), "none", "");
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			Change_MainThemeMusic_Chance(10);

			break;

		case "essai":
			SetCurrentTime(12, 0);
			LAi_SetActorType(characterFromID("William Klein"));
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("William Klein"), pchar, "", 0.0, 1.0);

			break;

		case "fight":
			locations[FindLocation("Cuba_shore_01")].reload.l1.disable = 1;
			locations[FindLocation("Cuba_shore_01")].reload.l2.disable = 1;
			locations[FindLocation("Cuba_shore_01")].reload.l3.disable = 1;
			LAi_SetOfficerType(characterFromID("William Klein"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "reload", "reload2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "reload", "reload2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "reload", "reload2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "reload", "reload2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "reload", "reload2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "reload", "reload2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			LAi_group_FightGroups("SHORE_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SHORE_SOLDIERS", "essai_2");
			break;

		case "essai_2":
			AddQuestRecord("William_Klein", "2");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1000);
			}
			else { AddPartyExp(pchar, 2500); }
			LAi_SetStayType(pchar);
			locations[FindLocation("Cuba_shore_01")].reload.l1.disable = 0;
			locations[FindLocation("Cuba_shore_01")].reload.l2.disable = 0;
			locations[FindLocation("Cuba_shore_01")].reload.l3.disable = 0;

			LAi_SetActorType(characterFromID("William Klein"));
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_9";
			LAi_ActorDialog(characterFromID("William Klein"), pchar, "", 2.0, 1.0);
			break;

		case "bartfollow":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("William Klein"));
			LAi_ActorFollowEverywhere(characterFromID("William Klein"), "", 60.0);

			PChar.quest.Bartolomeu = "crew";
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "William Klein";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Havana_town_05";
			PChar.quest.Bartolomeu.win_condition = "outhavana";
			break;

		case "outhavana":
			Locations[FindLocation("Havana_town_05")].reload.l3.disable = true;
			Locations[FindLocation("Havana_town_05")].reload.l21.disable = true;
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = true;
			Locations[FindLocation("Havana_town_05")].reload.l22.disable = true;

			LAi_SetPlayerType(pchar);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_spa_16", "goto", "goto_24");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "William Klein_dialog.c";
			sld.dialog.currentnode = "begin_10";
			sld.id = "soldat";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_spa2_16", "goto", "goto_43");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, pchar, "", 10);
			sld.id = "soldat1";
			LAi_group_MoveCharacter(sld, "GATE_SOLDIERS");
			LAi_SetActorType(characterfromID("soldat"));
			LAi_ActorDialog(characterfromID("soldat"), PChar, "", 0.5, 10);
			break;

		case "fight_2":
			LAi_SetWarriorType(characterfromID("soldat"));
			LAi_SetWarriorType(characterfromID("soldat1"));
			LAi_group_MoveCharacter(characterFromID("soldat"), "GATE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("soldat1"), "GATE_SOLDIERS");
			LAi_group_SetCheck("GATE_SOLDIERS", "hurry");
			LAi_group_FightGroups("GATE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_SetOfficerType(characterFromID("William Klein"));
			break;

		case "hurry":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("William Klein"));
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_15";
			LAi_ActorDialog(characterFromID("William Klein"), pchar, "", 1.0, 1.0);
			AddQuestRecord("William_Klein", "3");
			break;

		case "goverplace":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("William Klein"));
			LAi_ActorFollowEverywhere(characterFromID("William Klein"), "", 60.0);

			Locations[FindLocation("Havana_town_05")].reload.l3.disable = false;
			Locations[FindLocation("Havana_town_05")].reload.l21.disable = false;
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = false;
			Locations[FindLocation("Havana_town_05")].reload.l22.disable = false;
			Locations[FindLocation("Havana_town_02")].vcskip = true;

			PChar.quest.Bartolomeu = "hang";
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "William Klein";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Havana_town_02";
			PChar.quest.Bartolomeu.win_condition = "discours";
			break;

		case "discours":
			Locations[FindLocation("Havana_town_02")].reload.l1.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l2.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l3.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l4.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l5.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l7.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l8.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l10.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l11.disable = true;
			DeleteAttribute(&Locations[FindLocation("Havana_town_02")],"vcskip");

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_01"), "Havana_town_02", "goto", "goto30");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Havana_town_02", "goto", "goto31");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Havana_town_02", "goto", "goto32");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Havana_town_02", "goto", "goto33");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Havana_town_02", "goto", "goto34");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Havana_town_02", "goto", "goto35");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto36");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto37");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto38");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto39");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto40");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto41");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "animists2", "goto", "goto42");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld.dialog.filename = "William Klein_dialog.c";
			sld.dialog.currentnode = "begin_20";
			sld.id = "bourreau";
			// PB: Hangman should use axe -->
			TakeItemFromCharacter(sld, GetCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));	// Takes hangman's random blade away
			TakeItemFromCharacter(sld, GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE));	// Takes hangman's random gun away
			GiveItem2Character(sld,"bladeaxe1");										// Gives hangman an axe
			EquipCharacterByItem(sld,"bladeaxe1");										// Equips the axe
			// PB: Hangman should use axe <--

			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto44", "beforevent", 38.0);
			break;

		case "beforevent":
			//LAi_ActorTurnToCharacter(pchar, characterFromID("bourreau"));useless line now!!
			LAi_SetStayType(pchar);
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("William Klein"), pchar, "", 9.0, 1.0);
			break;

		case "commandant":
			LAi_SetActorType(characterFromID("William Klein"));
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto43", "talkhangman", 21.0)
			break ;

		case "talkhangman" :
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("bourreau"));
			LAi_ActorDialog(characterfromID("bourreau"), PChar, "", 1, 1.0);
			break;

		case "combat":
			LAi_ActorAttack(CharacterFromID("bourreau"), PChar, "");
			LAi_SetPlayerType(Pchar);
			LAi_QuestDelay("fight_4", 2.0);
			break;

		case "fight_4":
			LAi_SetActorType(characterFromID("William Klein"));
			LAi_SetOfficerType(characterFromID("William Klein"));
			LAi_group_FightGroups("SOLDATOS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SOLDATOS", "fuite");
			break;

		case "fuite":
			LAi_KillCharacter(characterFromID("bourreau"));
			LAi_SetActorType(characterFromID("William Klein"));
			LAi_ActorFollowEverywhere(characterFromID("William Klein"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_01"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_01"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_01"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_02"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_02"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_02"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_03"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_03"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_03"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_04"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_04"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_04"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_05"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_05"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_05"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_06"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_06"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_06"), "", 60.0);
			LAi_SetStayType(pchar);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1000);
			}
			else { AddPartyExp(pchar, 2500); }
			LAi_QuestDelay("rencontre", 4.0);
			break;

		case "rencontre":
			PChar.quest.Bartolomeu = "rencontrer";
			LAi_SetActorType(characterFromID("bart_pirate_06"));
			characters[GetCharacterIndex("bart_pirate_06")].dialog.currentnode = "First time";
			LAi_ActorDialog(characterfromID("bart_pirate_06"), PChar, "", 1.0, 1.0);
			break;

		case "rencontrebc":
			LAi_SetActorType(characterFromID("William Klein"));
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_22";
			LAi_ActorDialog(characterFromID("William Klein"), PChar, "", 1.0, 1.0);
			break;

		case "bartmoi":
			Locations[FindLocation("Havana_town_02")].reload.l1.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l2.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l3.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l4.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l5.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l7.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l8.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l10.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l11.disable = false;

			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_06"), "", 60.0);
			DoQuestReloadToLocation("Havana_Outskirts", "goto", "goto9", "_");
			Locations[FindLocation("Havana_Outskirts")].reload.l1.disable = true;
			ChangeCharacterAddressGroup(CharacterFromID("William Klein"), "Havana_Outskirts", "goto", "goto8");
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_24";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("William Klein"));
			LAi_ActorWaitDialog(CharacterFromID("William Klein"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("William Klein"), "", 10.0, 1.0);
			AddQuestRecord("William_Klein", "4");
			break;

		case "fight_5":
			LAi_SetPlayerType (Pchar);
			LAi_SetOfficerType(characterFromID("William Klein"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "reload", "reload1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "reload", "reload1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "reload", "reload1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "reload", "reload1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "reload", "reload1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "reload", "reload1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			LAi_group_FightGroups("SPANISHS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SPANISHS", "evasion_2");
			break;

		case "evasion_2":
			DeleteAttribute(&Locations[FindLocation("Havana_town_02")],"vcskip");
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("William Klein"));
			Locations[FindLocation("Havana_Outskirts")].reload.l1.disable = false;
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_26";
			LAi_ActorDialog(characterFromID("William Klein"), PChar, "", 0.0, 1.0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1000);
			}
			else { AddPartyExp(pchar, 2500); }
			break;

		case "evasion_3":
			AddQuestRecord("William_Klein", "5");
			PChar.quest.Bartolomeu = "evas";
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("William Klein"));
			LAi_ActorFollowEverywhere(characterFromID("William Klein"), "", 60.0);
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "William Klein";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Cuba_shore_01";
			PChar.quest.Bartolomeu.win_condition = "plage";
			break;

		case "plage":
			Locations[FindLocation("Cuba_shore_01")].reload.l3.disable = true;
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "locator26", "plage_1", 10.0)
			ChangeCharacterAddressGroup(CharacterFromID("William Klein"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_01"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Cuba_shore_01", "reload", "reload2");
			break;

		case "plage_1":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("bart_pirate_06"));
			Characters[GetCharacterIndex("bart_pirate_06")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("bart_pirate_06"), PChar, "", 4.0, 1.0);
			LAi_SetOfficerType(characterFromID("bart_pirate_01"));
			LAi_SetOfficerType(characterFromID("bart_pirate_02"));
			LAi_SetOfficerType(characterFromID("bart_pirate_03"));
			LAi_SetOfficerType(characterFromID("bart_pirate_04"));
			LAi_SetOfficerType(characterFromID("bart_pirate_05"));

			break;

		case "plage_2":
			LAi_SetOfficerType(characterFromID("bart_pirate_06"));
			LAi_SetActorType(characterFromID("William Klein"));
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_27";
			LAi_ActorDialog(characterFromID("William Klein"), PChar, "", 0.0, 1.0);

			break;

		case "embarquer":
			DoQuestReloadToLocation("Cuba_shore_01", "goto", "locator22", "embarquer2");

			break;

		case "embarquer2":
			ChangeCharacterAddressGroup(CharacterFromID("William Klein"), "Cuba_shore_01", "goto", "locator8");
			PChar.quest.Bartolomeu = "contact";
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("William Klein"));
			ChangeCharacterAddressGroup(CharacterFromID("Juan Hernandez"), "Santiago_port", "goto", "goto24");
			LAi_SetCitizenType(CharacterFromID("Juan Hernandez"));
			ChangeCharacterAddress(characterFromID("bart_pirate_01"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_02"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_03"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_04"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_05"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_06"), "none", "");
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_29";
			LAi_ActorDialog(characterFromID("William Klein"), PChar, "", 1.0, 1.0);
			AddQuestRecord("William_Klein", "6");
			break;

		case "walkcrew":
			PChar.quest.Bartolomeu = "blackcorsair";
			SetModelfromArray(characterFromID("Emilio Soares"), GetModelIndex("Emilio1"));
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Santiago_town_exit2", "goto", "locator9");
			LAi_SetCitizenType(CharacterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_8";
			AddQuestRecord("William_Klein", "7");
			break;

		case "quitcuba":
			Locations[FindLocation("Cuba_shore_01")].reload.l3.disable = false;
			LAi_SetOfficerType(characterFromID("Juan Hernandez"));
			ChangeCharacterAddress(characterFromID("Juan Hernandez"), "none", "");
			LAi_SetActorType(characterFromID("William Klein"));
			Characters[GetCharacterIndex("William Klein")].dialog.currentnode = "begin_30";
			LAi_ActorDialog(characterFromID("William Klein"), PChar, "", 0.0, 1.0);
			break;

		case "directredmond":
			AddQuestRecord("William_Klein", "8");
			LAi_SetActorType(characterFromID("William Klein"));
			LAi_ActorFollowEverywhere(characterFromID("William Klein"), "", 60.0);
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_SetImmortal(characterFromID("Emilio Soares"), true);
			LAi_ActorFollowEverywhere(characterFromID("Emilio Soares"), "", 60.0);
			PChar.quest.Bartolomeu = "dernier";
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "William Klein";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Redmond_Town_01";
			PChar.quest.Bartolomeu.win_condition = "mercenaires";
			break;

		case "mercenaires":
			Locations[FindLocation("Redmond_Town_01")].reload.l1.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l2.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l3.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l5.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l6.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l8.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l9.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l10.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l11.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l12.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l14.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l15.disable = true;

			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			LAi_SetOfficerType(characterFromID("William Klein"));
			ChangeCharacterAddressGroup(CharacterFromID("Jerico Contreras"), "Redmond_Town_01", "goto", "goto16");
			Characters[GetCharacterIndex("Jerico Contreras")].dialog.currentnode = "begin_33";
			LAi_SetImmortal(CharacterFromID("Jerico Contreras"), 1);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Pirat8", "goto", "goto17");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "mercenary");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Pirat9", "goto", "goto18");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "mercenary");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Pirat13", "goto", "goto19");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "mercenary");

			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto15", "dispute_2", 20.0);
			break;

		case "dispute_2":
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("Jerico Contreras"));
			LAi_ActorDialog(characterFromID("Jerico Contreras"), PChar, "", 0.0, 1.0);
			break;

		case "dispute_3":
			LAi_group_FightGroups("mercenary", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("mercenary", "findefin");
			break;

		case "findefin":

			LAi_KillCharacter(characterFromID("William Klein"));
			LAi_SetActorType(characterFromID("Jerico Contreras"));
			LAi_SetImmortal(CharacterFromID("Jerico Contreras"), 0);
			LAi_NoRebirthEnable(characterFromID("Jerico Contreras"));
			LAi_ActorAttack(CharacterFromID("Jerico Contreras"), Pchar, "");

			pchar.quest.chef_died.win_condition.l1 = "NPC_Death";
			pchar.quest.chef_died.win_condition.l1.character = "Jerico Contreras";
			pchar.quest.chef_died.win_condition = "findefin_2";

			break;

		case "findefin_2":
			Locations[FindLocation("Redmond_port")].vcskip = true;
			SetCharacterShipLocation(Pchar, "Redmond_port");
			Locations[FindLocation("Cuba_Jungle_01")].reload.l4.disable = false;
			Locations[FindLocation("Cuba_Jungle_02")].reload.l5.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l1.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l2.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l3.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l5.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l6.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l8.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l9.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l10.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l11.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l12.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l14.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l15.disable = false;
			Island_SetReloadEnableLocal("Cuba", "reload_3", true);

			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_10";
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorDialog(characterFromID("Emilio Soares"), PChar, "", 0.0, 1.0);

			break;

		case "newcaptain":
			LAi_SetOfficerType(characterFromID("William Klein"));
			ChangeCharacterAddress(characterFromID("William Klein"), "none", "");

			bSuppressResurrection = false;
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_SetImmortal(characterFromID("Emilio Soares"), false);
			AddPassenger(Pchar, characterFromID("Emilio Soares"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Emilio Soares"));
			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			DoQuestReloadToLocation("REDMOND_PORT", "goto", "goto_44", "_");

			Pchar.quest.seecrew.win_condition.l1 = "location";
			Pchar.quest.seecrew.win_condition.l1.location = "Redmond_Port";
			PChar.quest.seecrew.win_condition = "maccepter";

			break;

		case "maccepter":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Pirat1", "goto", "goto_45");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 60.0, 60.0);
			sld.dialog.filename = "William Klein_dialog.c";
			sld.dialog.currentnode = "begin_38";
			sld.id = "quartmaitre";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Pirat2", "Officers", "Sea_1_1");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 60.0, 60.0);
			sld.id = "sailor1";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Pirat3", "Officers", "Sea_1_2");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 60.0, 60.0);
			sld.id = "sailor2";
			LAi_SetActorType(characterFromID("quartmaitre"));
			LAi_ActorDialog(characterFromID("quartmaitre"), PChar, "", 0.0, 1.0);

			break;

		case "bartcaptain":
			DeleteAttribute(&Locations[FindLocation("Redmond_port")],"vcskip");
			Build_at("Cuba_port", "Sign", "", 76.75, 17.03, -115.38, 1.7, "building");
			Locations[FindLocation("Cuba_port")].dangerous = true;
			Locations[FindLocation("Santiago_port")].dangerous = true;
			ChangeRMRelation(pchar, SPAIN, -20.0);
			LAi_ActorRunToLocation(characterFromID("quartmaitre"), "reload", "Sea_1_back", "none", "", "", "", 4.0);
			LAi_SetActorType(characterFromID("sailor1"));
			LAi_ActorRunToLocation(characterFromID("sailor1"), "reload", "Sea_1_back", "none", "", "", "", 4.0);
			LAi_SetActorType(characterFromID("sailor2"));
			LAi_ActorRunToLocation(characterFromID("sailor2"), "reload", "Sea_1_back", "none", "", "", "", 4.0);
			AddQuestRecord("William_Klein", "9");
			CloseQuestHeader("William_Klein");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			SetCrewQuantity(pchar, makeint(GetCrewQuantity(pchar) + 7));

			Pchar.quest.gopointe.win_condition.l1 = "location";
			Pchar.quest.gopointe.win_condition.l1.location = "Guadeloupe_Port";
			PChar.quest.gopointe.win_condition = "MySantiago_start";

			break;

			//Santiago
		case "MySantiago_start":
			GiveModel2Player("GypsyCaptn_4", true);
			PlaceCharacter(characterFromID("Roxanne Lalliere"), "goto");
			ChangeCharacterAddressGroup(CharacterFromID("Francisco Cruz"), "Guadeloupe_Port", "rld", "aloc10");
			LAi_SetActorType(characterFromID("Francisco Cruz"));
			LAi_ActorRunToLocation(characterFromID("Francisco Cruz"), "reload", "reload6_back", "none", "", "", "", 20.0);
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Lai_ActorFollow(pchar, characterFromID("Roxanne Lalliere"), "", 10.0);
			Lai_ActorFollow(characterFromID("Roxanne Lalliere"), pchar, "Barto_store", 10.0);

			break;

		case "Barto_store":
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_27";
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), Pchar, "player_back", 1.0, 1.0);

			PChar.quest.santiago = "depart";
			Pchar.quest.Santiago.win_condition.l1 = "location";
			Pchar.quest.Santiago.win_condition.l1.location = "Pointe_a_pitre_store";
			PChar.quest.Santiago.win_condition = "Santiago_start_check_1";
			break;

		case "Santiago_start_check_1":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Pointe_a_pitre_store", "Officers", "reload1_2");
			ChangeCharacterAddressGroup(CharacterFromID("Francisco Cruz"), "Pointe_a_pitre_store", "goto", "goto5");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_30";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 0.0, 1.0);
			bSuppressResurrection = true;
			locations[FindLocation("Guadeloupe_Port")].reload.l11.disable = 1;
			locations[FindLocation("Guadeloupe_Jungle_03")].reload.l3.disable = 1;
			locations[FindLocation("Guadeloupe_Jungle_03")].reload.l5.disable = 1;
			locations[FindLocation("PaP_Guardhouse")].reload.l2.disable = 1;
			locations[FindLocation("Guadeloupe_Port")].reload.l1.disable = 1;
			pchar.location.from_sea = "Guadeloupe_Port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar");

			break;

		case "Santiago_start_check_2":
			DoQuestReloadToLocation("Guadeloupe_Port", "goto", "goto2", "_");
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Guadeloupe_Port", "reload", "reload6_back");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_37";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorWaitDialog(CharacterFromID("Roxanne Lalliere"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Roxanne Lalliere"), "", 5.0, 1.0);

			break;

		case "directbrothel":
			LAi_SetOfficerType(characterFromID("Francisco Cruz"));
			ChangeCharacterAddress(characterFromID("Francisco Cruz"), "none", "");
			AddQuestRecord("Santiago", "2");
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));
			LAi_SetImmortal(characterFromID("Roxanne Lalliere"), true);
			ChangeCharacterAddressGroup(CharacterFromID("Jean Dusac"), "Guadeloupe_Port", "officers", "houseS2_1");
			break;

		case "directstonehouse":
			AddQuestRecord("Santiago", "3");
			PChar.quest.santiago = "madame";
			ChangeCharacterAddressGroup(CharacterFromID("Cecile Bienbonne"), "StoneHouse", "reload", "reload2");
			Locations[FindLocation("StoneHouse")].vcskip = true;
			break;

		case "directjail":
			AddQuestRecord("Santiago", "4");
			PChar.quest.santiago = "jail";
			Pchar.quest.Santiago.win_condition.l1 = "location";
			Pchar.quest.Santiago.win_condition.l1.location = "Guadeloupe_Port";
			PChar.quest.Santiago.win_condition = "anyinfo";
			break;

		case "anyinfo":
			PChar.quest.santiago = "jail_2";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_43";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 0.0, 1.0);
			ChangeCharacterAddressGroup(CharacterFromID("Etienne Dupuis"), "PaP_Guardhouse", "reload", "reload1");
			break;

		case "txikimoi":
			ChangeCharacterAddressGroup(CharacterFromID("Etienne Dupuis"), "PaP_Prison", "goto", "goto19");
			ChangeCharacterAddressGroup(CharacterFromID("Txiki Pijuan"), "PaP_Prison", "goto", "goto9");
			break;

		case "plusinfo":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Guadeloupe_Port", "goto", "goto8");
			SetEnterLocationQuest("Guadeloupe_Port", "plusinfo_2", 0);
			break;

		case "plusinfo_2":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollow(characterFromID("Roxanne Lalliere"), PChar, "plusinfo_3", 1.5);
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_44";
			break;

		case "plusinfo_3":
			LAi_ActorWaitDialog(PChar, characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 0.0, 1.0);
			DeleteEnterLocationQuest("Guadeloupe_Port", "plusinfo_2");
			break;

		case "txikilibre":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_47";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 0.0, 1.0);
			break;

		case "txikilibre_2":
			ChangeCharacterAddressGroup(CharacterFromID("Txiki Pijuan"), "PAP_Arsenal", "reload", "reload2");
			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.currentnode = "begin_14";
			break;

		case "infobarto":
			Change_MainThemeMusic_Chance(5);
			AddQuestRecord("Santiago", "8");
			PChar.quest.santiago = "payertavernier";
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Txiki Pijuan"));
			LAi_ActorRunToLocation(characterFromID("Txiki Pijuan"), "reload", "reload1", "none", "", "", "", 0.0);
			break;

		case "directavernier":
			PChar.quest.santiago = "payerhum";
			SetCurrentTime(23, 0);
			DoQuestReloadToLocation("Guadeloupe_Port", "reload", "reload4_back", "_");
			characters[GetCharacterIndex("Cecile Bienbonne")].location = "none";
			characters[GetCharacterIndex("Jean Dusac")].location = "none";
			characters[GetCharacterIndex("Etienne Dupuis")].location = "none";
			LAi_QuestDelay("justeinfo", 0.5);
			break;

		case "justeinfo":
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_48";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorWaitDialog(CharacterFromID("Roxanne Lalliere"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Roxanne Lalliere"), "", 0.0, 1.0);
			break;

		case "newverif":
			LAi_type_actor_Reset(characterFromID("Txiki Pijuan"));
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto15", "", 7.0);
			LAi_QuestDelay("jelesvois", 7.0);
			break;

		case "jelesvois":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Guadeloupe_guard_2"));
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat1", "goto", "goto19");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "soulard1";
			LAi_SetActorType(characterFromID("soulard1"));
			LAi_ActorRunToLocation(characterFromID("soulard1"), "reload", "reload4_back", "none", "", "", "", 13.0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", "goto", "goto19");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "soulard2";
			LAi_SetActorType(characterFromID("soulard2"));
			LAi_ActorRunToLocation(characterFromID("soulard2"), "reload", "reload4_back", "none", "", "", "", 13.0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "goto19");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "soulard3";
			LAi_SetActorType(characterFromID("soulard3"));
			LAi_ActorRunToLocation(characterFromID("soulard3"), "reload", "reload4_back", "none", "", "", "", 13.0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "goto19");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "soulard4";
			LAi_SetActorType(characterFromID("soulard4"));
			LAi_ActorRunToLocation(characterFromID("soulard4"), "reload", "reload4_back", "none", "", "", "", 13.0);
			LAi_QuestDelay("rejointpijuan", 14.0);
			break;

		case "rejointpijuan":
			locations[FindLocation("Guadeloupe_Port")].reload.l6.disable = 1;
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_49";
			LAi_ActorWaitDialog(CharacterFromID("Roxanne Lalliere"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Roxanne Lalliere"), "", 0.0, 1.0);
			break;

		case "pijuanplantation":
			AddQuestRecord("Santiago", "9");
			LAi_SetCivilianGuardianType(characterFromID("Txiki Pijuan"));
			setCharacterShipLocation(characterFromID("Santiago"), "Guadeloupe_shore_01");
			ChangeCharacterAddressGroup(CharacterFromID("Txiki Pijuan"), "Guadeloupe_Jungle_03", "goto", "goto8");
			GiveItem2Character(characterFromID("Txiki Pijuan"),"blade6");
			EquipCharacterByItem(characterFromID("Txiki Pijuan"),"blade6");
			GiveItem2Character(CharacterFromId("Txiki Pijuan"),"pistol2");
			EquipCharacterByItem(CharacterFromId("Txiki Pijuan"), "pistol2");
			//JRH ammo mod -->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromId("Txiki Pijuan"), "gunpowder", 6);
				TakenItems(CharacterFromId("Txiki Pijuan"), "pistolbullets", 6);
			}
			//JRH ammo mod <--

			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.currentnode = "begin_17";
			PChar.quest.santiago = "rencgarda";
			Pchar.quest.Santiago.win_condition.l1 = "location";
			Pchar.quest.Santiago.win_condition.l1.location = "Guadeloupe_shore_01";
			PChar.quest.Santiago.win_condition = "ansegardes";
			break;

		case "ansegardes":
			locations[FindLocation("Guadeloupe_shore_01")].reload.l1.disable = 1;
			locations[FindLocation("Guadeloupe_shore_01")].reload.l3.disable = 1;
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat1", "goto", "locator10");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			sld.dialog.filename = "garda_dialog.c";
			sld.id = "garda1";
			LAi_SetGuardianType(characterFromID("garda1"));
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", "goto", "citizen07");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			sld.dialog.filename = "garda_dialog.c";
			sld.id = "garda2";
			LAi_SetGuardianType(characterFromID("garda2"));
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_GARDAS");
			break;

		case "directbarco":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_50";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);
			break;

		case "directbarco1":
			DoQuestReloadToLocation("Santiago_ship", "rld", "aloc6", "directbarco2");
			break;

		case "directbarco2":
			ChangeCharacterAddressGroup(characterFromID("Roxanne Lalliere"), "Santiago_ship", "rld", "aloc4");
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "rld", "loc6", "directbarco3", 14.0);
			break;

		case "directbarco3":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "rld", "aloc5");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			sld.dialog.filename = "garda_dialog.c";
			sld.id = "garda3";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("garda3"));
			Characters[GetCharacterIndex("garda3")].dialog.currentnode = "begin_3";
			LAi_ActorWaitDialog(CharacterFromID("garda3"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("garda3"), "", 0.0, 1.0);
			break;

		case "directbarco4":
			LAi_SetActorType(characterFromID("garda3"));
			LAi_ActorAttack(CharacterFromID("garda3"), PChar, "");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "rld", "aloc7");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat5", "rld", "aloc7");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat6", "rld", "aloc7");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat7", "rld", "aloc7");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat8", "rld", "aloc7");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat9", "rld", "aloc7");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");

			LAi_group_FightGroups("BARCO_GARDAS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("BARCO_GARDAS", "directbarco5");
			break;

		case "directbarco5":
			LAi_KillCharacter(characterFromID("garda3"));
			LAi_QuestDelay("directbarco6", 1.0);
			break;

		case "directbarco6":
			LAi_SetImmortal(CharacterFromID("Pedro Rivera"), 0);
			ChangeCharacterAddressGroup(CharacterFromID("Pedro Rivera"), "Santiago_ship", "rld", "aloc7");
			Characters[GetCharacterIndex("Pedro Rivera")].dialog.currentnode = "begin_13";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Pedro Rivera"));
			LAi_ActorWaitDialog(CharacterFromID("Pedro Rivera"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Pedro Rivera"), "", 0.0, 1.0);
			break;

		case "directbarco7":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_52";
			LAi_ActorWaitDialog(CharacterFromID("Roxanne Lalliere"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Roxanne Lalliere"), "", 0.0, 1.0);
			break;

		case "directbarco8":
			LAi_SetActorType(characterFromID("Pedro Rivera"));
			Characters[GetCharacterIndex("Pedro Rivera")].dialog.currentnode = "begin_17";
			LAi_ActorWaitDialog(CharacterFromID("Pedro Rivera"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Pedro Rivera"), "", 0.0, 1.0);
			break;

		case "directbarco9":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Pedro Rivera"));
			LAi_ActorAttack(CharacterFromID("Pedro Rivera"), Pchar, "");

			pchar.quest.rivera_died.win_condition.l1 = "NPC_Death";
			pchar.quest.rivera_died.win_condition.l1.character = "Pedro Rivera";
			pchar.quest.rivera_died.win_condition = "directbarco10";

			break;

		case "directbarco10":
			setCharacterShipLocation(characterFromID("Santiago"), "none");
			GiveShip2Character(pchar,pchar.stolen.ship.type,pchar.stolen.ship.name,-1,PIRATE,true,true); // PB
			DeleteAttribute(pchar,"stolen");
			SetCharacterShipLocation(Pchar, "Guadeloupe_shore_01");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_54";
			LAi_ActorWaitDialog(CharacterFromID("Roxanne Lalliere"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Roxanne Lalliere"), "", 0.0, 1.0);

			break;

		case "directbarco11":
			DoQuestReloadToLocation("Guadeloupe_shore_01", "goto", "citizen03", "Pijuanofficer");
			LAi_SetImmortal(characterFromID("Roxanne Lalliere"), false);

			break;

		case "Pijuanofficer":
			bSuppressResurrection = false;
			locations[FindLocation("Guadeloupe_Port")].reload.l6.disable = 0;
			locations[FindLocation("Guadeloupe_shore_01")].reload.l1.disable = 0;
			locations[FindLocation("Guadeloupe_shore_01")].reload.l3.disable = 0;
			locations[FindLocation("Guadeloupe_Port")].reload.l11.disable = 0;
			locations[FindLocation("PaP_Guardhouse")].reload.l2.disable = 0;
			locations[FindLocation("Guadeloupe_Port")].reload.l1.disable = 0;
			ChangeCharacterAddressGroup(CharacterFromID("Txiki Pijuan"), "Guadeloupe_shore_01", "goto", "locator11");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Txiki Pijuan"));
			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.currentnode = "begin_20";
			LAi_ActorWaitDialog(CharacterFromID("Txiki Pijuan"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Txiki Pijuan"), "", 0.0, 1.0);

			break;

		case "adieurox":
			AddPassenger(Pchar, characterFromID("Txiki Pijuan"), 0);
			SetOfficersIndex(Pchar, 9, getCharacterIndex("Txiki Pijuan"));
			LAi_SetOfficerType(characterFromID("Txiki Pijuan"));
			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.CurrentNode = "hired";

			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_55";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);

			break;

		case "adieurox_2":
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "locator3_back", "none", "", "", "Roxanne_guadeloupe_tavern", 10.0);

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 25000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 25000); }

			AddQuestRecord("Santiago", "11");
			CloseQuestHeader("Santiago");
			break;

		case "Roxanne_guadeloupe_tavern":
			ChangeCharacterAddressGroup(characterFromID("Roxanne Lalliere"), "Pointe_a_pitre_tavern", "goto", "goto4");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_133";
			LAi_SetStayType(characterFromID("Roxanne Lalliere"));
			break;

		case "Roxanne_Loop":
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_133";
			break;

		case "directmuellebis2":
			SetQuestHeader("Darien_Idol");
			AddQuestRecord("Darien_Idol", "1");
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Roxanne Lalliere"));
			SetCharacterRemovable(characterFromID("Roxanne Lalliere"), false);
			LAi_SetImmortal(characterFromID("Roxanne Lalliere"), true);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);

			pchar.quest.versmuel.win_condition.l1 = "location";
			pchar.quest.versmuel.win_condition.l1.location = "Muelle_port";
			pchar.quest.versmuel.win_condition = "surmuel";
			break;

		case "seezombie":
			SetRMRelation(PChar, PIRATE, REL_WAR);
			SetCharacterRelationBoth(GetCharacterIndex("Nathaniel Hawk"),GetMainCharacterIndex(),RELATION_ENEMY);
			Group_CreateGroup("Nathaniel Hawk");
			Group_AddCharacter("Nathaniel Hawk", "Nathaniel Hawk");
			Group_SetGroupCommander("Nathaniel Hawk", "Nathaniel Hawk");
			Group_SetPursuitGroup("Nathaniel Hawk", PLAYER_GROUP);
			Group_SetTaskAttack("Nathaniel Hawk", PLAYER_GROUP, true);
			Group_LockTask("Nathaniel Hawk");
			Group_SetAddress("Nathaniel Hawk", Characters[GetMainCharacterIndex()].location, "", "");

			UpdateRelations();

			Pchar.quest.Meet_CursedCaravel.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_CursedCaravel.win_condition.l1.character = "Nathaniel Hawk";
			Pchar.quest.Meet_CursedCaravel.win_condition = "endzombie";

			break;

		case "endzombie":
			Pchar.quest.Meet_CursedCaravel.over = "yes";
			SetQuestHeader("Zombie");
			AddQuestRecord("Zombie","1");
			CloseQuestHeader("Zombie");
			LAi_QuestDelay("Roche_at_QC", 0.0);

			break;

		case "directmuelle":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 25000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 25000); }

			AddQuestRecord("Santiago", "12");
			CloseQuestHeader("Santiago");
			LAi_Fade("directmuelle2", "directmuelle3");

			break;

		case "directmuelle2":
			SetQuestHeader("Darien_Idol");
			AddQuestRecord("Darien_Idol", "1");
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Roxanne Lalliere"));
			SetCharacterRemovable(characterFromID("Roxanne Lalliere"), false);

			break;

		case "directmuelle3":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_66";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 4.0, 1.0);

			break;

		case "directmuelle4":
			LAi_SetImmortal(characterFromID("Roxanne Lalliere"), true);
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "goto", "citizen02", "none", "", "", "", 10.0);
			pchar.quest.versmuel.win_condition.l1 = "location";
			pchar.quest.versmuel.win_condition.l1.location = "Muelle_port";
			pchar.quest.versmuel.win_condition = "surmuel";

			break;

		case "surmuel":
			PlaceCharacter(characterFromID("Roxanne Lalliere"), "goto");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_67";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 10.0, 1.0);

			break;

		case "taverninfo":
			PChar.quest.idolsearch = "Llano";
			ChangeCharacterAddressGroup(characterFromID("Facundo Llano"), "Muelle_Tavern", "sit", "sit7");
			LAi_SetSitType(characterFromID("Facundo Llano"));
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "reload2", "none", "", "", "", 0.0);
			break;

		case "juntarllano":
			LAi_Fade("falarllano", "comecollano");

			break;

		case "falarllano":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Muelle_tavern", "sit2", "sit3");
			Characters[GetCharacterIndex("Facundo Llano")].dialog.currentnode = "begin_2";

			break;

		case "comecollano":
			LAi_ActorWaitDialog(CharacterFromID("Facundo Llano"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Facundo Llano"),"", 7.0, 1.0);

			break;

		case "juntarrox":
			LAi_Fade("juntorox", "");

			break;

		case "juntorox":
			LAi_SetStayType(pchar);
			ChangeCharacterAddressGroup(pchar, "Muelle_tavern", "goto", "goto5");
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(characterFromID("Roxanne Lalliere"), "Muelle_town_01", "goto", "goto18");
			LAi_SetStayType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_67A";
			locations[FindLocation("Muelle_town_exit")].vcskip = true;
			locations[FindLocation("Major_house")].vcskip = true;

			break;

		case "directollonais":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			ChangeCharacterAddress(characterFromID("Facundo Llano"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("Francois L'Ollonais"), "Muelle_town_exit", "goto", "citizen01");
			DoQuestReloadToLocation("Muelle_town_exit", "goto", "locator9", "_");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_77";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			LAi_ActorWaitDialog(CharacterFromID("Francois L'Ollonais"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Francois L'Ollonais"), "", 3.0, 1.0);

			break;

		case "ollonaisbis":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_77";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);
			break;

		case "ollonaisbis2":
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			Characters[GetCharacterIndex("Francois L'Ollonais")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Francois L'Ollonais"), pchar, "", 2.0, 1.0);
			SetCurrentTime(23, 0);
			break;

		case "Beforepraca":
			StoreOfficers(pchar.id);
			DoQuestReloadToLocation("Muelle_town_exit", "reload", "reload2", "Beforepraca2");
			break;

		case "Beforepraca2":
			ChangeCharacterAddressGroup(CharacterFromID("Francois L'Ollonais"), "Muelle_town_exit", "goto", "locator5");
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Muelle_town_exit", "goto", "locator7");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "locator6");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "PIRATE_OLLONAIS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat5", "goto", "citizen03");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "PIRATE_OLLONAIS");
			Characters[GetCharacterIndex("Francois L'Ollonais")].dialog.currentnode = "begin_17";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			LAi_ActorWaitDialog(CharacterFromID("Francois L'Ollonais"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Francois L'Ollonais"), "", 3.0, 1.0);

			locations[FindLocation("Muelle_Town_Quest")].vcskip = true;
			pchar.quest.soldatplace.win_condition.l1 = "location";
			pchar.quest.soldatplace.win_condition.l1.location = "Muelle_Town_Quest";
			pchar.quest.soldatplace.win_condition = "Soldiers_Place";

			break;

		case "pracamuelle2":
			AddQuestRecord("Darien_Idol","2");
			ChangeCharacterAddressGroup(CharacterFromID("Luis Perdiguero"), "Major_bedroom", "goto", "goto5");
			DoQuestReloadToLocation("Muelle_Town_Quest", "goto", "goto41", "_");
			GiveModel2Player("GypsyCaptn_6", true);
			TakenItems(Pchar, "pistolpdart", 4);
			EquipCharacterbyItem(Pchar, "pistolpdart");
			LAi_SetActorType(pchar);
			LAi_ActorAnimation(pchar, "jump", "stop_the_animation", 1.8);
			LAi_QuestDelay("play_jumping_sound", 1.2);

			break;

		case "Soldiers_Place":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "reload", "reload9");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto17");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto8");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto40");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "goto", "goto25");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "goto", "goto37");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto26");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetPatrolType(sld);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto28");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetPatrolType(sld);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS");

			LAi_group_SetRelation("TOWNHALL_SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			Pchar.quest.meet_perdi.win_condition.l1 = "location";
			Pchar.quest.meet_perdi.win_condition.l1.location = "Major_bedroom";
			PChar.quest.meet_perdi.win_condition = "meetperdiguero";

			break;

		case "play_jumping_sound":
			PlaySound("PEOPLE\jump.wav");

			break;

		case "stop_the_animation":
			Lai_SetPlayerType(pchar);
			LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, true, "attacksoldatos");

			break;

		case "attacksoldatos":
			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
			LAi_group_FightGroups("TOWNHALL_SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_RemoveCheckMinHP(Pchar);
			Locations[FindLocation("Muelle_Town_Quest")].reload.l5.disable = 1;
			LAi_SetImmortal(Pchar, false);

			break;

		case "meetperdiguero":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Luis Perdiguero"));
			LAi_ActorWaitDialog(CharacterFromID("Luis Perdiguero"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Luis Perdiguero"), "", 3.0, 1.0);
			break;

		case "gifleperdiguero":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Luis Perdiguero"));
			LAi_ActorAnimation(pchar, "attack_fast_2", "sautfenetre", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
			break;

		case "sautfenetre":
			LAi_KillCharacter(characterFromID("Luis Perdiguero"));
			LAi_QuestDelay("sautfenetre2", 2.0);
			break;

		case "sautfenetre2":
			LAi_RemoveCheckMinHP(Pchar);
			LAi_SetImmortal(Pchar, false);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "reload", "reload1");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetStayType(sld);
			sld.dialog.filename = "Luis Perdiguero_dialog.c";
			sld.dialog.currentnode = "begin_14";
			sld.id = "chambre";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("chambre"));
			LAi_ActorWaitDialog(CharacterFromID("chambre"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("chambre"), "", 1.0, 1.0);
			break;

		case "sautfenetre3":
			Lai_SetPlayerType(pchar);
			LAi_ActorAttack(CharacterFromID("chambre"), Pchar, "");
			pchar.quest.bedroom_died.win_condition.l1 = "NPC_Death";
			pchar.quest.bedroom_died.win_condition.l1.character = "chambre";
			pchar.quest.bedroom_died.win_condition = "sautfenetre4";
			break;

		case "sautfenetre4":
			AddQuestRecord("Darien_Idol","3");
			pchar.quest.saut_janela.win_condition.l1 = "locator";
			pchar.quest.saut_janela.win_condition.l1.location = "Major_bedroom";
			pchar.quest.saut_janela.win_condition.l1.locator_group = "goto";
			pchar.quest.saut_janela.win_condition.l1.locator = "goto6";
			pchar.quest.saut_janela.win_condition = "sautfenetre5";
			break;

		case "sautfenetre5":
			DoQuestReloadToLocation("Muelle_Town_Quest", "goto", "goto42", "_");
			LAi_SetActorType(pchar);
			LAi_ActorAnimation(pchar, "jump", "stop_the_animation2", 1.8);
			LAi_QuestDelay("play_jumping_sound", 1.2);

			break;

		case "stop_the_animation2":
			Lai_SetPlayerType(pchar);
			Locations[FindLocation("Muelle_Town_Quest")].reload.l4.disable = 0;

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "reload", "reload3_back");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "TOWNHALL_SPAIN_SOLDIERS2");

			LAi_group_FightGroups("TOWNHALL_SPAIN_SOLDIERS2", LAI_GROUP_PLAYER, true);
			Pchar.quest.sairpraca.win_condition.l1 = "location";
			Pchar.quest.sairpraca.win_condition.l1.location = "Muelle_town_exit";
			PChar.quest.sairpraca.win_condition = "revoirollonais";

			break;

		case "revoirollonais":
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_4"));
			ChangeCharacterAddressGroup(CharacterFromID("Francois L'Ollonais"), "Muelle_town_exit", "goto", "locator5");
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Muelle_town_exit", "goto", "locator7");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);

			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			Characters[GetCharacterIndex("Francois L'Ollonais")].dialog.currentnode = "begin_18";
			LAi_ActorWaitDialog(CharacterFromID("Francois L'Ollonais"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Francois L'Ollonais"), "", 3.0, 1.0);

			break;

		case "verdouwesen":
			RestoreOfficers(pchar.id);
			AddQuestRecord("Darien_Idol","4");
			Lai_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			LAi_ActorFollowEverywhere(characterFromID("Francois L'Ollonais"), "", 60.0);
			DeleteAttribute(&Locations[FindLocation("Muelle_town_exit")],"vcskip"); // PB
			Locations[FindLocation("Muelle_town_exit")].reload.l2.disable = 1;
			SetCharacterShipLocation(Pchar, "Muelle_shore");
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Francois L'Ollonais"));
			SetCharacterRemovable(characterFromID("Francois L'Ollonais"), false);
			Pchar.quest.allerdwic.win_condition.l1 = "location";
			Pchar.quest.allerdwic.win_condition.l1.location = "Willemstad_port";
			PChar.quest.allerdwic.win_condition = "godwic";

			break;

		case "godwic":
			Build_at("Muelle_port", "Sign", "", 4.1, 3.8, 18.2, -1.4, "building");
			Locations[FindLocation("Muelle_Town_04")].dangerous = true;
			Locations[FindLocation("Muelle_port")].dangerous = true;
			ChangeRMRelation(pchar, SPAIN, -20.0);
			Locations[FindLocation("Muelle_town_exit")].reload.l2.disable = 0;
			GiveModel2Player("GypsyCaptn_5", true);
			PlaceCharacter(characterFromID("Francois L'Ollonais"), "goto");
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			Characters[GetCharacterIndex("Francois L'Ollonais")].dialog.currentnode = "begin_21";
			LAi_ActorDialog(characterFromID("Francois L'Ollonais"), pchar, "", 10.0, 1.0);

			break;

		case "voirgherarde":
			PChar.quest.idolsearch = "Gherarde";
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			LAi_ActorFollowEverywhere(characterFromID("Francois L'Ollonais"), "", 60.0);
			break;

		case "gouxmal":
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			Characters[GetCharacterIndex("Francois L'Ollonais")].dialog.currentnode = "begin_22";
			LAi_ActorDialog(characterFromID("Francois L'Ollonais"), pchar, "", 2.0, 1.0);
			break;

		case "gouxmal2":
			Change_MainThemeMusic_Chance(10);
			Island_SetReloadEnableLocal("Curacao", "reload_3", true);
			Islands[FindIsland("Curacao")].reload.l3.goto_enable = true; // PB
			AddQuestRecord("Darien_Idol","5");
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			LAi_ActorFollowEverywhere(characterFromID("Francois L'Ollonais"), "", 60.0);
			pchar.quest.soldatplace.win_condition.l1 = "location";
			pchar.quest.soldatplace.win_condition.l1.location = "Curacao_shore_02";
			pchar.quest.soldatplace.win_condition = "chegadauxmal";
			break;

		case "chegadauxmal":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_78";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 10.0, 1.0);
			break;

		case "gomixteca":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			locations[FindLocation("Curacao_Jungle_04")].vcskip = true;
			locations[FindLocation("Curacao_shore_04")].vcskip = true;
			locations[FindLocation("Curacao_shore_03")].vcskip = true;
			locations[FindLocation("Curacao_Jungle_05")].vcskip = true;
			locations[FindLocation("Curacao_Jungle_06")].vcskip = true;
			setCharacterShipLocation(characterFromID("Spanish Captain"), "Curacao_shore_03");
			ChangeCharacterAddress(characterFromID("spanish_soldier_01"), "Curacao_shore_03", "locator3");
			ChangeCharacterAddress(characterFromID("spanish_soldier_02"), "Curacao_shore_03", "locator5");
			LAi_SetActorType(characterFromID("spanish_soldier_02"));
			LAi_ActorSetLayMode(characterFromID("spanish_soldier_02"));
			LAi_SetActorType(characterFromID("spanish_soldier_01"));
			LAi_ActorSetLayMode(characterFromID("spanish_soldier_01"));
			pchar.quest.spanishnavio.win_condition.l1 = "location";
			pchar.quest.spanishnavio.win_condition.l1.location = "Curacao_shore_03";
			pchar.quest.spanishnavio.win_condition = "constatechoue";
			break;

		case "constatechoue":
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			Characters[GetCharacterIndex("Francois L'Ollonais")].dialog.currentnode = "begin_23";
			LAi_ActorDialog(characterFromID("Francois L'Ollonais"), pchar, "", 10.0, 1.0);
			break;

		case "constatechoue2":
			AddQuestRecord("Darien_Idol","6");
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			LAi_ActorFollowEverywhere(characterFromID("Francois L'Ollonais"), "", 60.0);
			pchar.quest.bridge_indians.win_condition.l1 = "locator";
			pchar.quest.bridge_indians.win_condition.l1.location = "Curacao_shore_04";
			pchar.quest.bridge_indians.win_condition.l1.locator_group = "goto";
			pchar.quest.bridge_indians.win_condition.l1.locator = "goto15";
			pchar.quest.bridge_indians.win_condition = "pontindians";
			break;

		case "pontindians":
			locations[FindLocation("Curacao_shore_04")].reload.l1.disable = 1;
			locations[FindLocation("Curacao_shore_04")].reload.l2.disable = 1;
			locations[FindLocation("Curacao_shore_04")].reload.l3.disable = 1;
			LAi_SetOfficerType(characterFromID("Francois L'Ollonais"));
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "reload", "reload1_back");
			LAi_group_MoveCharacter(sld, "DARIEN_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "reload", "reload1_back");
			LAi_group_MoveCharacter(sld, "DARIEN_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "reload", "reload1_back");
			LAi_group_MoveCharacter(sld, "DARIEN_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto7");
			LAi_group_MoveCharacter(sld, "DARIEN_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto7");
			LAi_group_MoveCharacter(sld, "DARIEN_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto7");
			LAi_group_MoveCharacter(sld, "DARIEN_INDIANS");

			LAi_group_FightGroups("DARIEN_INDIANS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("DARIEN_INDIANS", "Darientemple");
			break;

		case "Darientemple":
			locations[FindLocation("Curacao_shore_04")].reload.l1.disable = 0;
			locations[FindLocation("Curacao_shore_04")].reload.l2.disable = 0;
			locations[FindLocation("Curacao_shore_04")].reload.l3.disable = 0;
			locations[FindLocation("Curacao_Jungle_06")].reload.l4.disable = 1;
			locations[FindLocation("Curacao_Jungle_06")].reload.l2.disable = 1;
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			Characters[GetCharacterIndex("Francois L'Ollonais")].dialog.currentnode = "begin_25";
			LAi_ActorDialog(characterFromID("Francois L'Ollonais"), pchar, "", 5.0, 1.0);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			break;

		case "Darientemple2":
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			LAi_ActorFollowEverywhere(characterFromID("Francois L'Ollonais"), "", 60.0);
			pchar.quest.bridge_indians.win_condition.l1 = "locator";
			pchar.quest.bridge_indians.win_condition.l1.location = "Curacao_Jungle_06";
			pchar.quest.bridge_indians.win_condition.l1.locator_group = "reload";
			pchar.quest.bridge_indians.win_condition.l1.locator = "reload2";
			pchar.quest.bridge_indians.win_condition = "Darientemple3";
			break;

		case "Darientemple3":
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			Characters[GetCharacterIndex("Francois L'Ollonais")].dialog.currentnode = "begin_26";
			LAi_ActorDialog(characterFromID("Francois L'Ollonais"), pchar, "", 10.0, 1.0);
			break;

		case "Darientemple4":
			DoQuestReloadToLocation("Labirint_4", "reload", "reload30_back", "Darientemple4bis");
			pchar.quest.indian_trap.win_condition.l1 = "locator";
			pchar.quest.indian_trap.win_condition.l1.location = "Labirint_4";
			pchar.quest.indian_trap.win_condition.l1.locator_group = "reload";
			pchar.quest.indian_trap.win_condition.l1.locator = "reload13";
			pchar.quest.indian_trap.win_condition = "Darientemple5";
			break;

		case "Darientemple4bis":
			pchar.quest.idolback.win_condition.l1 = "location";
			pchar.quest.idolback.win_condition.l1.location = "Curacao_Jungle_06";
			pchar.quest.idolback.win_condition = "Darientemple6";
			break;

		case "Darientemple5":
			CreateParticleSystemX("blast_inv", -91.56, 6.89, -8.17, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -91.56, 6.89, -8.17, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -86.56, 6.89, -8.17, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -91.56, 6.89, -4.17, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -91.56, 6.89, -12.17, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_KillCharacter(Pchar);
			break;

		case "Darientemple6":
			if(CheckCharacterItem(Pchar,"darien_idol"))
			{
				Pchar.quest.indian_trap.over = "yes";
				ChangeCharacterAddressGroup(CharacterFromID("Francois L'Ollonais"), "Curacao_Jungle_06", "goto", "citizen04");

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "citizen07");
				GiveItem2Character(sld,"blade10");
				EquipCharacterByItem(sld,"blade10");
				LAi_SetHP(sld, 100.0, 100.0);
				LAi_SetStayType(sld);
				LAi_group_MoveCharacter(sld, "PIRATES_OLLONAIS");
				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat5", "goto", "citizen05");
				GiveItem2Character(sld,"blade10");
				EquipCharacterByItem(sld,"blade10");
				LAi_SetHP(sld, 100.0, 100.0);
				LAi_SetStayType(sld);
				LAi_group_MoveCharacter(sld, "PIRATES_OLLONAIS");
				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "citizen015");
				GiveItem2Character(sld,"blade10");
				EquipCharacterByItem(sld,"blade10");
				LAi_SetHP(sld, 100.0, 100.0);
				LAi_SetStayType(sld);
				LAi_group_MoveCharacter(sld, "PIRATES_OLLONAIS");
				sld.dialog.filename = "Francois Ollonais_dialog.c";
				sld.dialog.currentnode = "begin_36";
				sld.id = "batardo";
				Characters[GetCharacterIndex("Francois L'Ollonais")].dialog.currentnode = "begin_29";
				LAi_SetActorType(pchar);
				LAi_ActorGoToLocator(PChar, "goto", "citizen06", "Darientemple6b", 20.0);
			}
			break;

		case "Darientemple6b":
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			LAi_ActorWaitDialog(CharacterFromID("Francois L'Ollonais"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Francois L'Ollonais"), "", 4.0, 1.0);
			break;

		case "Darientemple7":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("batardo"));
			LAi_ActorDialog(characterFromID("batardo"), pchar, "", 5.0, 1.0);
			LAi_ActorRunToLocation(characterFromID("Francois L'Ollonais"), "reload", "reload1_back", "none", "", "", "", 20.0);
			RemoveCharacterCompanion(Pchar, characterFromID("Francois L'Ollonais"));
			setCharacterShipLocation(characterFromID("Francois L'Ollonais"), "none");
			break;

		case "Darientemple8":
			locations[FindLocation("Curacao_Jungle_06")].reload.l1.disable = 1;
			locations[FindLocation("Curacao_Jungle_06")].reload.l5.disable = 1;
			LAi_SetStayType(characterFromID("batardo"));
			LAi_group_MoveCharacter(characterFromID("batardo"), "PIRATES_OLLONAIS");
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));
			LAi_group_FightGroups("PIRATES_OLLONAIS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_OLLONAIS", "Darientemple9");

			break;

		case "Darientemple9":
			locations[FindLocation("Curacao_Jungle_06")].reload.l1.disable = 0;
			locations[FindLocation("Curacao_Jungle_06")].reload.l5.disable = 0;
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_79";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 20.0, 1.0);
			break;

		case "gomixteca2":
			AddQuestRecord("Darien_Idol","7");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			pchar.quest.idolback.win_condition.l1 = "location";
			pchar.quest.idolback.win_condition.l1.location = "Curacao_shore_03";
			pchar.quest.idolback.win_condition = "chegagiant";
			ChangeCharacterAddress(characterFromID("Francois L'Ollonais"), "Curacao_shore_03", "locator11");
			LAi_SetActorType(characterFromID("Francois L'Ollonais"));
			LAi_ActorSetLayMode(characterFromID("Francois L'Ollonais"));
			break;

		case "chegagiant":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_80";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 5.0, 1.0);
			break;

		case "chegagiant2":
			ChangeCharacterAddressGroup(characterFromID("Gigante"), "Curacao_shore_03", "goto","locator6");
			GiveItem2Character(CharacterFromId("Gigante"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Gigante"), "bladex4");
			LAi_group_MoveCharacter(characterFromID("Gigante"), "INDIAN_GIANT");
			LAi_group_FightGroups("INDIAN_GIANT", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("INDIAN_GIANT", "chegagiant3");
			break;

		case "chegagiant3":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_82";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 10.0, 1.0);
			break;

		case "chegauxmal":
			AddQuestRecord("Darien_Idol","8");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			pchar.quest.idolback.win_condition.l1 = "location";
			pchar.quest.idolback.win_condition.l1.location = "Curacao_shore_02";
			pchar.quest.idolback.win_condition = "chegauxmal2";
			break;

		case "chegauxmal2":
			ChangeCharacterAddressGroup(CharacterFromID("Gherarde de Jongh"), "Curacao_shore_02", "officers", "reload1_3");
			GiveItem2Character(characterFromID("Gherarde de Jongh"),"blade23");
			EquipCharacterByItem(characterFromID("Gherarde de Jongh"),"blade23");
			GiveItem2Character(CharacterFromId("Gherarde de Jongh"),"pistol2");
			EquipCharacterByItem(CharacterFromId("Gherarde de Jongh"), "pistol2");
			//JRH ammo mod -->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromId("Gherarde de Jongh"), "gunpowder", 6);
				TakenItems(CharacterFromId("Gherarde de Jongh"), "pistolbullets", 6);
			}
			//JRH ammo mod <--

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_hol_16", "goto", "locator12");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_GHERARDE");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_hol2_16", "goto", "locator5");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_GHERARDE");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_hol3_16", "goto", "locator3");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_GHERARDE");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_hol4_16", "goto", "locator4");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_GHERARDE");

			Characters[GetCharacterIndex("Gherarde de Jongh")].dialog.currentnode = "begin_8";
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "citizen03", "chegauxmal3", 20.0);
			break;

		case "chegauxmal3":
			LAi_SetActorType(characterFromID("Gherarde de Jongh"));
			LAi_ActorWaitDialog(CharacterFromID("Gherarde de Jongh"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Gherarde de Jongh"), "", 4.0, 1.0);
			break;

		case "uxmalfight":
			LAi_ActorRunToLocation(characterFromID("Gherarde de Jongh"), "officers", "reload1_1", "none", "", "", "", 15.0);
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));
			LAi_group_FightGroups("SOLDIER_GHERARDE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SOLDIER_GHERARDE", "uxmalfight2");

			break;

		case "uxmalfight2":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_85";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 10.0, 1.0);
			break;

		case "uxmalfight3":
			LAi_SetStayType(characterFromID("Gherarde de Jongh"));
			AddQuestRecord("Darien_Idol","9");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);

			Pchar.quest.find_Gherardeship.win_condition.l1 = "location";
			Pchar.quest.find_Gherardeship.win_condition.l1.location = "Curacao";
			PChar.quest.find_Gherardeship.win_condition = "godouwesen2";
			break;

		case "godouwesen2":
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Curacao", false);
			SetRMRelation(PChar, HOLLAND, REL_WAR);
			SetCharacterRelationBoth(GetCharacterIndex("Gherarde de Jongh"),GetMainCharacterIndex(),RELATION_ENEMY);

			Group_CreateGroup("Gherarde de Jongh");
			Group_AddCharacter("Gherarde de Jongh", "Gherarde de Jongh");
			Group_SetGroupCommander("Gherarde de Jongh", "Gherarde de Jongh");
			Group_SetPursuitGroup("Gherarde de Jongh", PLAYER_GROUP);
			Group_SetTaskAttack("Gherarde de Jongh", PLAYER_GROUP, true);
			Group_LockTask("Gherarde de Jongh");
			Group_SetAddress("Gherarde de Jongh", Characters[GetMainCharacterIndex()].location, "", "");
			UpdateRelations();
			characters[GetCharacterIndex("Gherarde de Jongh")].nosurrender = 2;

			Pchar.quest.Meet_Gherardeship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Gherardeship.win_condition.l1.character = "Gherarde de Jongh";
			Pchar.quest.Meet_Gherardeship.win_condition = "Capture_Gherardeship";

			break;

		case "Capture_Gherardeship":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Curacao", true);
			Pchar.quest.Meet_Gherardeship.over = "yes";
			AddQuestRecord("Darien_Idol","10");
			Pchar.quest.Laisse_Roxanne.win_condition.l1 = "location";
			Pchar.quest.Laisse_Roxanne.win_condition.l1.location = "Falaise_de_fleur_port_01";
			PChar.quest.Laisse_Roxanne.win_condition = "finalalliere";

			break;

		case "finalalliere":
			PlaceCharacter(characterFromID("Roxanne Lalliere"), "goto");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_86";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 10.0, 1.0);

			break;

		case "finalallierebis":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "reload", "sea_back", "finalalliere2", 0.0);
			break;

		case "finalalliere2":
			LAi_ActorAnimation(pchar, "attack_fast_2", "finalalliere3", 0.0);
			TakeItemFromCharacter(pchar, "darien_idol");
			PlayStereoSound("INTERFACE\took_item.wav");
			break;

		case "finalalliere3":
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_87";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorWaitDialog(CharacterFromID("Roxanne Lalliere"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Roxanne Lalliere"), "", 3.0, 1.0);

			break;

		case "finalalliere4":
			PChar.quest.Jackpot = "debuter";
			AddQuestRecord("Darien_Idol","11");
			CloseQuestHeader("Darien_Idol");
			LAi_SetPlayerType(pchar);
			RemoveCharacterCompanion(Pchar, characterFromID("Roxanne Lalliere"));
			setCharacterShipLocation(characterFromID("Roxanne Lalliere"), "none");
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "Falaise_de_fleur_location_01_02", "none", "", "", "", 10.0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }

			break;

		case "Roxanne_at_FalaisedeFleur":
			LAi_SetImmortal(CharacterFromID("Roxanne Lalliere"), 0);
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Falaise_De_Fleur_townhall", "goto", "goto5");
			LAi_SetCitizenType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.filename = "Roxanne at FalaisedeFleur_dialog.c";
			LAi_QuestDelay("story_davy", 1.0);
			break;

		case "Ver_Esteban":
			PlaceCharacter(CharacterFromID("Juan Esteban"), "goto");
			GiveItem2Character(CharacterFromID("Juan Esteban"), "goldarmor");
			EquipCharacterByItem(CharacterFromID("Juan Esteban"), "goldarmor");
			LAi_SetActorType(CharacterFromID("Juan Esteban"));
			Characters[GetCharacterIndex("Juan Esteban")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(CharacterFromID("Juan Esteban"), pchar, "", 10.0, 1.0);
			break;

		case "Esteban_fight":
			LAi_ActorAttack(CharacterFromID("Juan Esteban"), PChar, "");
			LAi_SetCheckMinHP(characterFromID("Juan Esteban"), 75.0, false, "Esteban_surrender");//higher level to be sure not to kill him with a powerful weapon
			break;

		case "Esteban_surrender":
			LAi_RemoveCheckMinHP(characterFromID("Juan Esteban"));
			LAi_type_actor_Reset(characterFromID("Juan Esteban"));
			LAi_SetActorType(characterFromID("Juan Esteban"));
			Characters[GetCharacterIndex("Juan Esteban")].dialog.currentnode = "begin_6";
			LAi_ActorDialog(characterFromID("Juan Esteban"), pchar, "", 10.0, 1.0);
			break;

		case "Esteban_officer":
			AddPassenger(Pchar, characterFromID("Juan Esteban"), 0);
			SetOfficersIndex(Pchar, 8, getCharacterIndex("Juan Esteban"));
			LAi_SetOfficerType(characterFromID("Juan Esteban"));
			Characters[GetCharacterIndex("Juan Esteban")].dialog.filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Juan Esteban")].dialog.CurrentNode = "hired";
			GiveShip2Character(characterFromID("Nathaniel Hawk"),"CursedCaravel","Victory",-1,PIRATE,true,true);
			EquipCharacterByItem(CharacterFromId("Nathaniel Hawk"), "blade31");
			EquipCharacterByItem(CharacterFromId("Nathaniel Hawk"), "pistol2");

			Pchar.quest.find_Zombie.win_condition.l1 = "location";
			Pchar.quest.find_Zombie.win_condition.l1.location = "Conceicao";
			PChar.quest.find_Zombie.win_condition = "seezombie";
			break;

		case "Esteban_leaves":
			LAi_SetActorType(characterFromID("Juan Esteban"));
			LAi_ActorRunToLocation(characterFromID("Juan Esteban"), "reload", "reload1_back", "none", "", "", "Esteban_Havana", 5.0);

			break;

		case "Esteban_Havana":
			ChangeCharacterAddressGroup(CharacterFromID("Juan Esteban"), "Havana_townhall", "goto", "goto2");
			LAi_SetCitizenType(characterFromID("Juan Esteban"));
			Characters[GetCharacterIndex("Juan Esteban")].dialog.currentnode = "begin_11";
			GiveShip2Character(characterFromID("Nathaniel Hawk"),"CursedCaravel","Victory",-1,PIRATE,true,true);
			EquipCharacterByItem(CharacterFromId("Nathaniel Hawk"), "blade31");
			EquipCharacterByItem(CharacterFromId("Nathaniel Hawk"), "pistol2");

			Pchar.quest.find_Zombie.win_condition.l1 = "location";
			Pchar.quest.find_Zombie.win_condition.l1.location = "Conceicao";
			PChar.quest.find_Zombie.win_condition = "seezombie";
			break;

			// Silver Train Quest

		case "Jackpot_start_search":
			PChar.quest.Jackpot = "search";
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Tortuga_Townhall", "goto", "goto6");
			ChangeCharacterAddressGroup(CharacterFromID("Edwaert Mansveldt"), "Tortuga_Townhall", "goto", "goto7");
			Pchar.quest.meetturner.win_condition.l1 = "location";
			Pchar.quest.meetturner.win_condition.l1.location = "Tortuga_Townhall";
			PChar.quest.meetturner.win_condition = "MeetTurner";

			break;

		case "MeetTurner":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorWaitDialog(CharacterFromID("Henry Morgan"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Henry Morgan"), "", 10.0, 1.0);

			break;

		case "talktoswann":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			LAi_ActorWaitDialog(CharacterFromID("Edwaert Mansveldt"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Edwaert Mansveldt"), "", 10.0, 1.0);

			break;

		case "leavetortuga":
			PChar.quest.Jackpot = "gobattlerocks";
			bSuppressResurrection = true;
			SetQuestHeader("Silver_Train");
			AddQuestRecord("Silver_Train", "1");
			LAi_SetPlayerType(pchar);
			LAi_SetCitizenType(characterFromID("Henry Morgan"));
			LAi_SetCitizenType(characterFromID("Edwaert Mansveldt"));
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Henry Morgan"));
			SetCharacterRemovable(characterFromID("Henry Morgan"), false);

			Island_SetReloadEnableLocal("Battle_Rocks", "reload_2", true);
			Islands[FindIsland("Battle_Rocks")].reload.l1.goto_enable = true; // PB

			locations[FindLocation("Battle_Rocks_Jungle_01")].vcskip = true;
			locations[FindLocation("Battle_Rocks_Jungle_02")].vcskip = true;
			locations[FindLocation("Spanish_Camp")].vcskip = true;
			locations[FindLocation("Battle_Rocks_Jungle_03")].vcskip = true;
			locations[FindLocation("Battle_Rocks_Jungle_04")].vcskip = true;
			locations[FindLocation("Battle_Rocks_Jungle_05")].vcskip = true;

			pchar.quest.todevilcreek.win_condition.l1 = "location";
			pchar.quest.todevilcreek.win_condition.l1.location = "Devil_Creek";
			pchar.quest.todevilcreek.win_condition = "to_Devil_Creek";
			break;

		case "jackpotrefused":
			PChar.quest.Jackpot = "fin";
			SetQuestHeader("Silver_Train");
			AddQuestRecord("Silver_Train", "2");
			CloseQuestHeader("Silver_Train");
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorGoToLocation(characterFromID("Henry Morgan"), "reload", "locator2", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			LAi_ActorGoToLocation(characterFromID("Edwaert Mansveldt"), "reload", "locator2", "none", "", "", "", 0.0);
			break;

		case "to_Devil_Creek":
			LAi_SetStayType(characterFromID("Henry Morgan"));
			LAi_SetStayType(characterFromID("Edwaert Mansveldt"));
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Devil_Creek", "goto", "locator10");
			ChangeCharacterAddressGroup(CharacterFromID("Edwaert Mansveldt"), "Devil_Creek", "goto", "citizen07");
			Characters[GetCharacterIndex("Henry Morgan")].dialog.CurrentNode = "begin_11";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorWaitDialog(CharacterFromID("Henry Morgan"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Henry Morgan"), "", 10.0, 1.0);

			break;

		case "meetindians":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_SetImmortal(CharacterFromID("Henry Morgan"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Henry Morgan"), "", 60.0);
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			LAi_SetImmortal(CharacterFromID("Edwaert Mansveldt"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Edwaert Mansveldt"), "", 60.0);
			pchar.quest.meet_indians.win_condition.l1 = "location";
			pchar.quest.meet_indians.win_condition.l1.location = "Battle_Rocks_Jungle_04";
			pchar.quest.meet_indians.win_condition = "fightindians";

			break;

		case "fightindians":
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l3.disable = 1;
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l4.disable = 1;
			LAi_SetOfficerType(characterFromID("Henry Morgan"));
			LAi_SetOfficerType(characterFromID("Edwaert Mansveldt"));

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			LAi_group_FightGroups("JUNGLE_INDIANS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("JUNGLE_INDIANS", "leaveindians");

			break;

		case "leaveindians":
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l3.disable = 0;
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			Characters[GetCharacterIndex("Edwaert Mansveldt")].dialog.currentnode = "begin_4";
			LAi_ActorDialog(characterFromID("Edwaert Mansveldt"), pchar, "", 50.0, 10.0);
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorFollowEverywhere(characterFromID("Henry Morgan"), "", 60.0);
			AddQuestRecord("Silver_Train", "3");

			break;

		case "meetprisoner":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			LAi_ActorFollowEverywhere(characterFromID("Edwaert Mansveldt"), "", 60.0);
			LAi_SetImmortal(characterFromID("Pirate kk"), true);
			ChangeCharacterAddress(CharacterFromID("Pirate kk"), "Battle_Rocks_Jungle_02", "goto8");
			LAi_SetPoorType(characterfromID("Pirate kk"));
			locations[FindLocation("Battle_Rocks_Jungle_02")].reload.l4.disable = 1;

			break;

		case "opinionturner":
			LAi_SetActorType(characterFromID("Henry Morgan"));
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 2.0, 1.0);

			break;

		case "gospanishcamp":
			LAi_SetActorType(characterFromID("Pirate kk"));
			Characters[GetCharacterIndex("Pirate kk")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Pirate kk"), pchar, "", 2.0, 1.0);

			break;

		case "gospanishcamp2":
			locations[FindLocation("Battle_Rocks_Jungle_02")].reload.l4.disable = 0;
			AddQuestRecord("Silver_Train", "4");
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorFollowEverywhere(characterFromID("Henry Morgan"), "", 60.0);
			LAi_SetActorType(characterFromID("Pirate kk"));
			LAi_ActorRunToLocation(characterFromID("Pirate kk"), "reload", "reload1", "none", "", "", "", 0.0);
			pchar.quest.meet_spaniards.win_condition.l1 = "location";
			pchar.quest.meet_spaniards.win_condition.l1.location = "spanish_camp";
			pchar.quest.meet_spaniards.win_condition = "fightspaniards";

			break;

		case "fightspaniards":
			locations[FindLocation("spanish_camp")].reload.l4.disable = 1;
			locations[FindLocation("spanish_camp")].reload.l5.disable = 1;
			locations[FindLocation("spanish_camp")].reload.l6.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Pirate kk"), "spanish_camp", "officers", "reload2_1");
			ChangeCharacterAddressGroup(characterFromID("Henry Morgan"), "spanish_camp", "officers", "reload2_2");
			ChangeCharacterAddressGroup(characterFromID("Edwaert Mansveldt"), "spanish_camp", "officers", "reload2_3");
			GiveItem2Character(characterFromID("Pirate kk"),"blade6");
			EquipCharacterByItem(characterFromID("Pirate kk"),"blade6");
			GiveItem2Character(CharacterFromId("Pirate kk"),"pistol2");
			EquipCharacterByItem(CharacterFromId("Pirate kk"), "pistol2");
			//JRH ammo mod -->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromId("Pirate kk"), "gunpowder", 6);
				TakenItems(CharacterFromId("Pirate kk"), "pistolbullets", 6);
			}
			//JRH ammo mod <--

			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Spaniardsattack";
			LAi_ActorSelfDialog(Pchar, "player_back");
			break;


		case "fightspaniards2":
			LAi_SetOfficerType(characterFromID("Henry Morgan"));
			LAi_SetOfficerType(characterFromID("Edwaert Mansveldt"));
			LAi_SetOfficerType(characterFromID("Pirate kk"));
			LAi_QuestDelay("fightspaniards3", 1.5);
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto5");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto5");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto5");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto5");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "goto", "goto5");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "goto", "goto5");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			LAi_group_FightGroups("CAMP_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("CAMP_SOLDIERS", "gomine");


			break;

		case "fightspaniards3":
			CreateParticleSystemX("blast_inv", -26.95, 0.00, 11.17, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -26.95, 0.00, 11.17, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -21.95, 0.00, 11.17, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -26.95, 0.00, 16.17, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -26.95, 0.00, 6.17, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");

			break;

		case "gomine":
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			LAi_ActorFollowEverywhere(characterFromID("Edwaert Mansveldt"), "", 60.0);
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorFollowEverywhere(characterFromID("Henry Morgan"), "", 60.0);
			LAi_SetActorType(characterFromID("Pirate kk"));
			Characters[GetCharacterIndex("Pirate kk")].dialog.currentnode = "begin_9";
			LAi_ActorDialog(characterFromID("Pirate kk"), pchar, "", 50.0, 10.0);

			break;

		case "gomine2":
			locations[FindLocation("spanish_camp")].reload.l5.disable = 0;
			locations[FindLocation("spanish_camp")].reload.l6.disable = 0;
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Pirate kk"));
			LAi_ActorRunToLocation(characterFromID("Pirate kk"), "reload", "reload3", "none", "", "", "", 0.0);
			pchar.quest.meet_friends.win_condition.l1 = "location";
			pchar.quest.meet_friends.win_condition.l1.location = "Battle_Rocks_Jungle_01";
			pchar.quest.meet_friends.win_condition = "minefight";

			break;

		case "minefight":
			ChangeCharacterAddressGroup(characterFromID("Pirate kk"), "Battle_Rocks_Jungle_01", "goto", "goto10");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_spa6_16", "officers", "reload1_2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_spa5_16", "officers", "reload1_3");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_SOLDATOS");
			sld.dialog.filename = "Pirate KK_dialog.c";
			sld.dialog.currentnode = "begin_11";
			sld.id = "futurmort";
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto7", "minefightbis", 20.0);

			break;

		case "minefightbis":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("futurmort"));
			LAi_ActorWaitDialog(CharacterFromID("futurmort"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("futurmort"), "", 10.0, 10.0);

			break;

		case "minefight2":
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Henry Morgan"));
			LAi_SetOfficerType(characterFromID("Edwaert Mansveldt"));
			LAi_SetOfficerType(characterFromID("Pirate kk"));
			LAi_group_MoveCharacter(characterFromID("futurmort"), "MINE_SOLDATOS");
			LAi_group_FightGroups("MINE_SOLDATOS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("MINE_SOLDATOS", "entrermine");

			break;

		case "entrermine":
			pchar.quest.meet_friend.win_condition.l1 = "location";
			pchar.quest.meet_friend.win_condition.l1.location = "Battle_Rocks_Mine";
			pchar.quest.meet_friend.win_condition = "talktofriends";
			LAi_SetActorType(characterFromID("Pirate kk"));
			LAi_ActorFollowEverywhere(characterFromID("Pirate kk"), "", 60.0);


			break;

		case "talktofriends":
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Brodyag1", "goto", "goto1");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_FRIENDS");
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "man4", "goto", "goto10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "mineami";
			sld.dialog.filename = "Pirate KK_dialog.c";
			sld.dialog.currentnode = "begin_12";
			LAi_SetStayType(characterFromID("mineami"));

			break;

		case "allerport":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Pirate kk"));
			Characters[GetCharacterIndex("Pirate kk")].dialog.currentnode = "begin_16";
			LAi_ActorWaitDialog(CharacterFromID("Pirate kk"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Pirate kk"), "", 10.0, 10.0);

			break;

		case "allerport2":
			AddQuestRecord("Silver_Train", "5");
			setCharacterShipLocation(characterFromID("Silver"), "Battle_Rocks_port");
			locations[FindLocation("spanish_camp")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_port")].reload.l3.disable = 1;
			LAi_SetPlayerType(pchar);
			DoReloadCharacterToLocation("Battle_Rocks_port", "goto", "locator10");
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorFollowEverywhere(characterFromID("Henry Morgan"), "", 60.0);
			LAi_SetActorType(characterFromID("Pirate kk"));
			LAi_ActorFollowEverywhere(characterFromID("Pirate kk"), "", 60.0);
			ChangeCharacterAddressGroup(characterFromID("Edwaert Mansveldt"), "Battle_Rocks_port", "goto", "citizen04");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			Characters[GetCharacterIndex("Edwaert Mansveldt")].dialog.currentnode = "begin_5";
			LAi_ActorWaitDialog(CharacterFromID("Edwaert Mansveldt"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Edwaert Mansveldt"), "", 10.0, 10.0);


			break;

		case "seesoldier":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_spa_16", "goto", "citizen01");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PRAIA_SOLDATOS");
			sld.id = "fuyard";
			LAi_ActorTurnToCharacter(pchar, characterFromID("fuyard"));
			LAi_SetActorType(characterFromID("fuyard"));
			LAi_ActorRunToLocation(characterFromID("fuyard"), "reload", "reload2", "none", "", "", "", 0.0);
			LAi_QuestDelay("attraperfuyard", 2.5);

			break;

		case "attraperfuyard":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "citizen07", "fuyardparti", 20.0);
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			LAi_ActorFollowEverywhere(characterFromID("Edwaert Mansveldt"), "", 60.0);
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorFollowEverywhere(characterFromID("Henry Morgan"), "", 60.0);

			break;

		case "fuyardparti":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Henry Morgan"));
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_13";
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 20.0, 10.0);

			break;

		case "gosilvertrain":
			locations[FindLocation("Battle_Rocks_port")].reload.l3.disable = 0;

			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorFollowEverywhere(characterFromID("Henry Morgan"), "", 60.0);
			pchar.quest.meet_friend.win_condition.l1 = "location";
			pchar.quest.meet_friend.win_condition.l1.location = "Battle_Rocks_Jungle_03";
			pchar.quest.meet_friend.win_condition = "joinsilvertrain";

			break;

		case "joinsilvertrain":
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l4.disable = 1;
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l5.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Pirate kk"), "Battle_Rocks_Jungle_03", "officers", "reload1_3");
			ChangeCharacterAddressGroup(characterFromID("Henry Morgan"), "Battle_Rocks_Jungle_03", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Edwaert Mansveldt"), "Battle_Rocks_Jungle_03", "officers", "reload1_2");

			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Chelovek", "goto", "goto7");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_SetPoorType(sld);
			LAi_group_MoveCharacter(sld, "CONVOY_FRIENDS");
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Fatman", "goto", "goto8");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetPoorType(sld);
			LAi_group_MoveCharacter(sld, "CONVOY_FRIENDS");
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Brodyag1", "goto", "goto4");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetPoorType(sld);
			LAi_group_MoveCharacter(sld, "CONVOY_FRIENDS");
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "man1", "goto", "goto3");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "convoyami";
			sld.dialog.filename = "Pirate KK_dialog.c";
			sld.dialog.currentnode = "begin_17";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_spa_16", "goto", "goto2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "fuyard";
			LAi_ActorTurnToCharacter(pchar, characterFromID("fuyard"));
			LAi_SetActorType(characterFromID("fuyard"));
			LAi_ActorRunToLocation(characterFromID("fuyard"), "goto", "goto5", "none", "", "", "joinsilvertrain2", 0.0);
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Spanishrunaway";
			LAi_ActorSelfDialog(Pchar, "player_back");

			break;

		case "joinsilvertrain2":
			LAi_SetOfficerType(characterFromID("Henry Morgan"));
			LAi_SetOfficerType(characterFromID("Edwaert Mansveldt"));
			LAi_SetOfficerType(characterFromID("Pirate kk"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			LAi_group_FightGroups("CONVOY_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("CONVOY_SOLDIERS", "joinsilvertrain3");

			break;

		case "joinsilvertrain3":
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			LAi_ActorFollowEverywhere(characterFromID("Edwaert Mansveldt"), "", 60.0);
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorFollowEverywhere(characterFromID("Henry Morgan"), "", 60.0);
			LAi_SetActorType(characterFromID("Pirate kk"));
			LAi_ActorFollowEverywhere(characterFromID("Pirate kk"), "", 60.0);
			LAi_SetStayType(characterFromID("convoyami"));

			break;

		case "leavebattle":
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l5.disable = 0;
			LAi_SetActorType(characterFromID("Henry Morgan"));
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_15";
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 10.0, 1.0);

			break;

		case "leavedevilcreek":
			LAi_SetStayType(characterFromID("Edwaert Mansveldt"));
			DoReloadCharacterToLocation("Devil_Creek", "goto", "locator10");
			ChangeCharacterAddressGroup(characterFromID("Edwaert Mansveldt"), "Devil_Creek", "goto", "citizen02");
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorFollowEverywhere(characterFromID("Henry Morgan"), "", 60.0);

			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			Characters[GetCharacterIndex("Edwaert Mansveldt")].dialog.currentnode = "begin_6";
			LAi_ActorWaitDialog(CharacterFromID("Edwaert Mansveldt"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Edwaert Mansveldt"), "", 10.0, 10.0);

			break;

		case "leavedevilcreek2":
			AddQuestRecord("Silver_Train", "6");
			pchar.quest.sail_tortuga.win_condition.l1 = "location";
			pchar.quest.sail_tortuga.win_condition.l1.location = "Tortuga_port";
			pchar.quest.sail_tortuga.win_condition = "meetshopkeeper";
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			LAi_ActorFollowEverywhere(characterFromID("Edwaert Mansveldt"), "", 60.0);
			setCharacterShipLocation(characterFromID("Silver"), "none");

			break;

		case "meetshopkeeper":
			LAi_SetActorType(characterFromID("Henry Morgan"));
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 20.0, 10.0);

			break;

		case "leaveturner":
			LAi_SetActorType(characterFromID("Pirate kk"));
			Characters[GetCharacterIndex("Pirate kk")].dialog.currentnode = "begin_18";
			LAi_ActorDialog(characterFromID("Pirate kk"), pchar, "", 20.0, 10.0);

			break;

		case "leavepiratekk":
			LAi_SetActorType(characterFromID("Edwaert Mansveldt"));
			Characters[GetCharacterIndex("Edwaert Mansveldt")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Edwaert Mansveldt"), pchar, "", 20.0, 10.0);

			break;

		case "leaveswann":
			pchar.quest.nouvoutfit.win_condition.l1 = "location";
			pchar.quest.nouvoutfit.win_condition.l1.location = "Oxbay_Port";
			pchar.quest.nouvoutfit.win_condition = "Envoy_OxbayPort";

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 25000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 25000); }

			bSuppressResurrection = false;
			AddMoneyToCharacter(pchar, 60000);
			AddQuestRecord("Silver_Train", "7");
			CloseQuestHeader("Silver_Train");
			LAi_ActorRunToLocation(characterFromID("Pirate kk"), "reload", "reload5_back", "none", "", "", "", 5.0);
			LAi_ActorRunToLocation(characterFromID("Edwaert Mansveldt"), "reload", "reload4_back", "none", "", "", "", 5.0);
			LAi_ActorRunToLocation(characterFromID("Henry Morgan"), "reload", "reload4_back", "none", "", "", "Morgan_at_Redmond", 5.0);
			RemoveCharacterCompanion(Pchar, characterFromID("Henry Morgan"));
			setCharacterShipLocation(characterFromID("Henry Morgan"), "none");

			break;

		case "Morgan_at_Redmond":
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_Residence", "goto", "goto5");
			LAi_SetCitizenType(characterFromID("Henry Morgan"));
			SetCharacterShipLocation(characterFromID("Henry Morgan"), "Redmond_port");
			break;

		case "Roche_at_QC":
			ChangeCharacterAddressGroup(CharacterFromID("Roche Brasiliano"), "QC_Tavern", "goto", "goto2");
			LAi_SetCitizenType(characterFromID("Roche Brasiliano"));

			break;

			// Hunter Quest

		case "Envoy_OxbayPort":
			CaptureTownForNation("Oranjestad", SPAIN); // in order to be logical with the Assassin storyline
			ChangeCharacterAddressGroup(CharacterFromID("Serafino Masarenhas"), "Oxbay_Port", "goto", "goto12");
			LAi_SetActorType(characterFromID("Serafino Masarenhas"));
			Characters[GetCharacterIndex("Serafino Masarenhas")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Serafino Masarenhas"), pchar, "", 20.0, 1.0);
			break;

		case "Envoy_Out":
			LAi_SetActorType(characterFromID("Serafino Masarenhas"));
			LAi_ActorRunToLocation(characterFromID("Serafino Masarenhas"), "reload", "reload2", "none", "", "", "", 30.0);
			break;

		case "Envoy_Agree":
			SetQuestHeader("Hunter");
			AddQuestRecord("Hunter", "1");
			LAi_SetActorType(characterFromID("Serafino Masarenhas"));
			LAi_ActorRunToLocation(characterFromID("Serafino Masarenhas"), "reload", "reload2", "none", "", "", "", 30.0);
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Serafino Masarenhas"));
			SetCharacterRemovable(characterFromID("Serafino Masarenhas"), false);
			pchar.quest.see_Serafino.win_condition.l1 = "location";
			pchar.quest.see_Serafino.win_condition.l1.location = "Conceicao_Port";
			pchar.quest.see_Serafino.win_condition = "Serafino_SaoJorge";
			break;

		case "Serafino_SaoJorge":
			ChangeCharacterAddressGroup(CharacterFromID("Serafino Masarenhas"), "Conceicao_Port", "goto", "goto11");
			LAi_SetActorType(characterFromID("Serafino Masarenhas"));
			Characters[GetCharacterIndex("Serafino Masarenhas")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Serafino Masarenhas"), pchar, "", 10.0, 1.0);
			break;

		case "Envoy_sees_Governor":
			pchar.quest.Hunter = "debut";
			LAi_SetActorType(characterFromID("Serafino Masarenhas"));
			LAi_ActorRunToLocation(characterFromID("Serafino Masarenhas"), "reload", "reload1", "none", "", "", "", 10.0);
			RemoveCharacterCompanion(Pchar, characterFromID("Serafino Masarenhas"));
			setCharacterShipLocation(characterFromID("Serafino Masarenhas"), "none");
			break;

		case "Meet_Queiroz":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Conceicao_town", "goto", "goto15");
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_1";
			break;

		case "Falar_Soares":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_55";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);
			break;

		case "Falar_Queiroz":
			pchar.roubado.ship.type   = pchar.ship.type;
			pchar.roubado.ship.name   = pchar.ship.name;
			LAi_SetStayType(characterFromID("Emilio Soares"));
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_4";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "Search_Campos":
			AddQuestRecord("Hunter", "2");
			RemovePassenger(pchar, characterFromID("Emilio Soares"));
			RemoveCharacterCompanion(pchar, characterFromID("Emilio Soares"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Emilio Soares"));
			GiveShip2Character(pchar,"PO_FastNavy","A Faisca",-1,PORTUGAL,true,true);
			SetCharacterShipLocation(Pchar, "Conceicao_Port");
			LAi_ActorFollowEverywhere(characterFromID("Augusto Queiroz"), "", 60.0);

			Group_CreateGroup("Osmundo Murrieta");
			Group_AddCharacter("Osmundo Murrieta", "Osmundo Murrieta");
			Group_SetGroupCommander("Osmundo Murrieta", "Osmundo Murrieta");
			Group_SetAddress("Osmundo Murrieta", "Turks", "Quest_Ships","Quest_Ship_14");

			Pchar.quest.Meet_Osmundo.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Osmundo.win_condition.l1.character = "Osmundo Murrieta";
			Pchar.quest.Meet_Osmundo.win_condition = "kill_Osmundo";
			break;

		case "kill_Osmundo":
			AddQuestRecord("Hunter", "3");
			pchar.quest.whitereefs.win_condition.l1 = "location";
			pchar.quest.whitereefs.win_condition.l1.location = "Turks_shore_01";
			pchar.quest.whitereefs.win_condition = "Land_on_White_Reefs";
			break;

		case "Land_on_White_Reefs":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Turks_shore_01", "goto", "goto4");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "Turks_shore_01", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "Turks_shore_01", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "Turks_shore_01", "goto", "goto5");
			LAi_SetActorType(characterFromID("Portuguese_soldier_01"));
			LAi_ActorFollowEverywhere(characterFromID("Portuguese_soldier_01"), "", 60.0);
			LAi_SetActorType(characterFromID("Portuguese_soldier_02"));
			LAi_ActorFollowEverywhere(characterFromID("Portuguese_soldier_02"), "", 60.0);
			LAi_SetActorType(characterFromID("Portuguese_soldier_03"));
			LAi_ActorFollowEverywhere(characterFromID("Portuguese_soldier_03"), "", 60.0);
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_5";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "Search_Campos_Jungle":
			Group_SetAddressNone("Osmundo Murrieta");
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Augusto Queiroz"));
			ChangeCharacterAddressGroup(CharacterFromID("Arturo Campos"), "Turks_shore_ship", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("spanish_soldier_01"), "Turks_shore_ship", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("spanish_soldier_02"), "Turks_shore_ship", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("spanish_soldier_03"), "Turks_shore_ship", "goto", "goto4");
			pchar.quest.see_Campos.win_condition.l1 = "location";
			pchar.quest.see_Campos.win_condition.l1.location = "Turks_shore_ship";
			pchar.quest.see_Campos.win_condition = "Campos_Shoreship";
			break;

		case "Campos_Shoreship":
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetImmortal(CharacterFromID("Portuguese_soldier_01"), false);
			LAi_SetImmortal(CharacterFromID("Portuguese_soldier_02"), false);
			LAi_SetImmortal(CharacterFromID("Portuguese_soldier_03"), false);
			LAi_SetActorType(characterFromID("Arturo Campos"));
			Characters[GetCharacterIndex("Arturo Campos")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Arturo Campos"), pchar, "", 5.0, 1.0);
			break;

		case "Fight_Campos":
			LAi_group_MoveCharacter(characterFromID("Arturo Campos"), "SPANISH_SOLDIERS");
			LAi_ActorAttack(CharacterFromID("Arturo Campos"), PChar, "");
			LAi_group_FightGroups("SPANISH_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPANISH_SOLDIERS", "Fin_Campos");
			break;

		case "Fin_Campos":
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "none", "", "");

			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "Campos_Morto":
			AddQuestRecord("Hunter", "4");
			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));
			pchar.quest.Tchao_Queiroz.win_condition.l1 = "location";
			pchar.quest.Tchao_Queiroz.win_condition.l1.location = "Conceicao_Port";
			pchar.quest.Tchao_Queiroz.win_condition = "Campos_Mortobis";
			break;

		case "Campos_Mortobis":
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_8";
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "Queiroz_Adeus":
			Characters[GetCharacterIndex("Jacinto Arcibaldo Barreto")].dialog.currentnode = "gov_34";
			RemovePassenger(pchar, characterFromID("Augusto Queiroz"));
			RemoveCharacterCompanion(pchar, characterFromID("Augusto Queiroz"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Augusto Queiroz"));
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "none", "", "");
			break;

		case "Meet_Corrales":
			AddQuestRecord("Hunter", "5");
			GiveShip2Character(pchar,pchar.roubado.ship.type,pchar.roubado.ship.name,-1,PIRATE,true,true);
			DeleteAttribute(pchar,"roubado");
			SetCharacterShipLocation(Pchar, "Conceicao_Port");
			Locations[FindLocation("Muelle_InsideHouseR2")].vcskip = true;
			ChangeCharacterAddressGroup(CharacterFromID("Leonardo Corrales"), "Muelle_InsideHouseR2", "goto", "locator1");
			Characters[GetCharacterIndex("Leonardo Corrales")].dialog.currentnode = "begin_1";
			break;

		case "ver_frenchgov":
			pchar.quest.Hunter = "Roxanne";
			AddQuestRecord("Hunter", "6");
			break;

		case "irpara_eleuthera":
			pchar.quest.Hunter = "eleuthera";
			AddQuestRecord("Hunter", "7");
			ChangeCharacterAddressGroup(CharacterFromID("Guibert Daudet"), "Alice_tavern", "goto", "goto8");
			Characters[GetCharacterIndex("Guibert Daudet")].dialog.currentnode = "begin_1";
			pchar.quest.ver_guibert.win_condition.l1 = "location";
			pchar.quest.ver_guibert.win_condition.l1.location = "Alice_tavern";
			pchar.quest.ver_guibert.win_condition = "falar_Daudet";
			break;

		case "falar_Daudet":
			LAi_SetActorType(characterFromID("Guibert Daudet"));
			LAi_ActorDialog(characterFromID("Guibert Daudet"), pchar, "", 4.0, 1.0);
			break;

		case "ir_PuertoCruz":
			StoreOfficers(pchar.id);
			SetCurrentTime(22, 0);
			LAi_SetStayType(characterFromID("Guibert Daudet"));
			DoQuestReloadToLocation("EleutheraPlantation", "goto", "goto18", "ir_PuertoCruzbis");
			break;

		case "ir_PuertoCruzbis":
			GiveModel2Player("GypsyCaptn_7",true);
			AddQuestRecord("Hunter", "8");
			ChangeCharacterAddressGroup(CharacterFromID("spanish_soldier_04"), "Eleuthera_Port", "goto", "goto11");
			pchar.quest.inspection.win_condition.l1 = "location";
			pchar.quest.inspection.win_condition.l1.location = "Eleuthera_Port";
			pchar.quest.inspection.win_condition = "check_entree";
			break;

		case "check_entree":
			Characters[GetCharacterIndex("spanish_soldier_04")].dialog.currentnode = "begin_26";
			LAi_SetActorType(characterFromID("spanish_soldier_04"));
			LAi_ActorDialog(characterFromID("spanish_soldier_04"), pchar, "", 4.0, 1.0);
			break;

		case "lancer_video":
			PostVideoAndQuest("Bartolomeu\residence",1, "danscamara");
			break;

		case "danscamara":
			ChangeCharacterAddressGroup(CharacterFromID("spanish_soldier_04"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Spanish Governor"), "Quest_Eleuthera_townhall", "goto", "goto7");
			DoQuestReloadToLocation("Quest_Eleuthera_townhall", "reload", "reload1", "danscamarabis");
			break;

		case "danscamarabis":
			LAi_QuestDelay("jumping_sound", 0.9);
			break;

		case "jumping_sound":
			PlaySound("PEOPLE\jump.wav");
			Characters[GetCharacterIndex("Spanish Governor")].dialog.currentnode = "gov_1";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Spanish Governor"));
			LAi_ActorWaitDialog(CharacterFromID("Spanish Governor"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Spanish Governor"), "", 9.0, 1.0);
			break;

		case "giflecole":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Spanish Governor"));
			LAi_ActorAnimation(pchar, "attack_fast_2", "Lancer_Video2", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
			break;

		case "Lancer_Video2":
			SetCurrentTime(23.00, 0);
			LAi_KillCharacter(characterFromID("Spanish Governor"));
			LAi_SetPlayerType(pchar);
			LAi_QuestDelay("Lancer_Video2bis", 2.0);
			break;

		case "Lancer_Video2bis":
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_6"));
			TakenItems(Pchar, "pistolpdart", 10);
			EquipCharacterbyItem(Pchar, "pistolpdart");
			PostVideoAndQuest("Bartolomeu\Rock",1, "dentro_forte");
			break;

		case "dentro_forte":
			LAi_group_SetRelation("FORTV_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_SetLookRadius("FORTV_SOLDIERS", LAI_GROUP_GRD_LOOK/2);
			LAi_group_SetHearRadius("FORTV_SOLDIERS", LAI_GROUP_GRD_HEAR/2);
			LAi_group_SetSayRadius("FORTV_SOLDIERS", LAI_GROUP_GRD_SAY);
			AddQuestRecord("Hunter", "9");
//			GiveItem2Character(CharacterFromId("Fort Captain"), "Fort_Keys");	// Stealing his keys may not work if he's under too many soldier corpses, or if corpse looting is disabled

			PChar.quest.fort_captain_dead.win_condition.l1 = "NPC_Death";		// Instead, give keys to player when Fort Captain dies
			PChar.quest.fort_captain_dead.win_condition.l1.character = "Fort Captain";
			PChar.quest.fort_captain_dead.win_condition = "fort_captain_dead";

			DoQuestReloadToLocation("Quest_FortVRight", "goto", "goto80", "_");
			LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, true, "atacasoldatos");

			// PB: More direct trigger code -->
			Pchar.quest.open_fortjailbis.win_condition.l1 = "item";
			Pchar.quest.open_fortjailbis.win_condition.l1.character = Pchar.id;
			Pchar.quest.open_fortjailbis.win_condition.l1.item = "Fort_Keys";
			Pchar.quest.open_fortjailbis.win_condition.l2 = "locator";
			pchar.quest.open_fortjailbis.win_condition.l2.location = "Quest_FortVRight";
			pchar.quest.open_fortjailbis.win_condition.l2.locator_group = "reload";
			pchar.quest.open_fortjailbis.win_condition.l2.locator = "reload2";
			Pchar.quest.open_fortjailbis.win_condition = "open_fortjailbis";
			// PB: More direct trigger code <--
			break;

		case "atacasoldatos":
			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
			LAi_group_FightGroups("FORTV_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_RemoveCheckMinHP(Pchar);
			LAi_SetImmortal(Pchar, false);
			break;

		case "fort_captain_dead":
			GiveItem2Character(PChar, "Fort_Keys");
		break;

		case "open_fortjailbis":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Quest_Fort_prison", "goto", "goto9");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_92";
			Locations[FindLocation("Quest_FortVRight")].reload.l3.disable = 0;

			GiveItem2Character(CharacterFromId("Roxanne Lalliere"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "bladex4");
			GiveItem2Character(CharacterFromId("Roxanne Lalliere"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "pistolrock");

			LAi_ActorWaitDialog(characterFromID("Roxanne Lalliere"), pchar); // Cap'n Cook

			// PB: Moved to before the location reload to prevent cowering of Roxanne:
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_5"));
			break;

		case "parler_elting":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Quest_Fort_prison", "goto", "goto13");
			LAi_RemoveCheckMinHP(Pchar);
			LAi_SetImmortal(Pchar, false);
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_1";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 1.5, 1.0);
			break;

		case "fight_elting":
			LAi_ActorAttack(CharacterFromID("Elting"), PChar, "");
			Pchar.quest.tuer_elting.win_condition.l1 = "NPC_Death";
			Pchar.quest.tuer_elting.win_condition.l1.character = "Elting";
			Pchar.quest.tuer_elting.win_condition = "fuir_avec_rox";
			break;

		case "fuir_avec_rox":
			LAi_Fade("fuir_avec_roxbis", "");
			break;

		case "fuir_avec_roxbis":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Quest_Fort_prison", "goto", "goto13");
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Roxanne Lalliere"));
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "pistol1a");
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "blade10");
			Locations[FindLocation("Quest_FortVRight")].reload.l1.disable = 0;
			Locations[FindLocation("Quest_FortVRight")].reload.l2.disable = 0;

			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_118";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 3.0, 1.0);
			break;

		case "sortir_prison_rox":
			Locations[FindLocation("Eleuthera_Jungle4")].vcskip = true;
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));
			DoQuestReloadToLocation("Eleuthera_Jungle4", "reload", "reload2", "meet_enrique_rox");
			break;

		case "meet_enrique_rox":
			EquipCharacterByItem(characterFromID("Roxanne Lalliere"), "blthag02");
			EquipCharacterByItem(characterFromID("Roxanne Lalliere"), "pistol1a");
			ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Eleuthera_Jungle4", "goto", "goto8");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto7");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PADILLA_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto4");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PADILLA_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto3");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PADILLA_SOLDIERS");

			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_6";
			LAi_SetActorType(characterFromID("Enrique Padilla"));
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 3.5, 1.0);
			break;

		case "fight_padilla_rox":
			LAi_ActorAttack(characterFromID("Enrique Padilla"), pchar, "");
			LAi_group_FightGroups("PADILLA_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PADILLA_SOLDIERS", "Padilla_morto_rox");
			break;

		case "Padilla_morto_rox":
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_120";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 4.0, 20.0);
			break;

		case "join_guibert_rox":
			AddQuestRecord("Hunter", "15");
			GiveShip2Character(CharacterFromID("Roxanne Lalliere"),"FR_LightPinnace","La Diablesse",-1,FRANCE,true,true);
			SetCharacterShipLocation(CharacterFromID("Roxanne Lalliere"), "Alice_Port");
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));
			ChangeCharacterAddressGroup(CharacterFromID("Guibert Daudet"), "Alice_Port", "goto", "goto21");
			LAi_SetStayType(characterFromID("Guibert Daudet"));
			Characters[GetCharacterIndex("Guibert Daudet")].dialog.currentnode = "begin_15";
			ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "none", "", "");
			break;

		case "infoemilio_rox":
			DeleteAttribute(&Locations[FindLocation("Eleuthera_Jungle4")],"vcskip");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_122";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);
			break;

		case "quitter_alice_rox":
			AddQuestRecord("Hunter", "11");
			RemovePassenger(pchar, characterFromID("Roxanne Lalliere"));
			RemoveCharacterCompanion(pchar, characterFromID("Roxanne Lalliere"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Roxanne Lalliere"));
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "reload61_back", "none", "", "", "quitter_alicebis_rox", 8.0);
			LAi_SetActorType(characterFromID("Guibert Daudet"));
			LAi_ActorRunToLocation(characterFromID("Guibert Daudet"), "reload", "reload61_back", "none", "", "", "", 9.0);
			break;

		case "quitter_alicebis_rox":
			RestoreOfficers(pchar.id);
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Roxanne Lalliere"));
			SetCharacterRemovable(characterFromID("Roxanne Lalliere"), false);

			pchar.quest.parabahia.win_condition.l1 = "location";
			pchar.quest.parabahia.win_condition.l1.location = "Cuba_shore_01";
			pchar.quest.parabahia.win_condition = "chegada_antonio_rox";
			break;

		case "chegada_antonio_rox":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Cuba_shore_01", "goto", "goto13");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_125";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);
			break;

		case "free_emilio_rox":
			Locations[FindLocation("Havana_town_05")].vcskip = true;
			SetCurrentTime(23.00, 0);
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = 1;
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_7"));
			DoQuestReloadToLocation("Havana_town_05", "goto", "goto_35", "free_emiliobis_rox");
			break;

		case "free_emiliobis_rox":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "soldier01");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "soldier02");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "soldier03");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			sld.dialog.filename = "Spaniards_dialog.c";
			sld.dialog.currentnode = "begin_33";
			sld.id = "soldadinho";
			LAi_SetStayType(characterfromID("soldadinho"));
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Havana_town_05", "goto", "goto_7");
			GiveItem2Character(CharacterFromId("Roxanne Lalliere"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "bladex4");
			GiveItem2Character(CharacterFromId("Roxanne Lalliere"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "pistolrock");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_126";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 4.0, 1.0);
			break;

		case "free_emiliobis2_rox":
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			break;

		case "entrar_havana_jail_rox":
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = 0;
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Havana_prison", "goto", "goto9");
			LAi_SetStayType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_63";
			break;

		case "tuerdansprison_rox":
			Locations[FindLocation("Havana_prison")].vcskip = true;
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "pistol1a");
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "blade10");
			DoQuestReloadToLocation("Havana_prison", "goto", "goto18", "tuerdansprisonbis_rox");
			break;

		case "tuerdansprisonbis_rox":
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Havana_prison", "goto", "goto19");
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Havana_prison", "goto", "goto17");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_128";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 5.0, 1.0);
			break;

		case "revient_roxanne":
			DeleteAttribute(&Locations[FindLocation("Havana_town_05")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Havana_prison")],"vcskip");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_129";
			DoQuestReloadToLocation("Cuba_shore_01", "reload", "reload1", "revenir_bahiabis_rox");
			break;

		case "revenir_bahiabis_rox":
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Cuba_shore_01", "goto", "goto13");
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Cuba_shore_01", "goto", "goto51");
			EquipCharacterByItem(characterFromID("Roxanne Lalliere"), "blthag02");
			EquipCharacterByItem(characterFromID("Roxanne Lalliere"), "pistol1a");
			Build_at("Eleuthera_Port", "Sign", "", -57.6, 2, 7.87, 0.24, "building");
			Locations[FindLocation("Eleuthera_Port")].dangerous = true;
			ChangeRMRelation(pchar, SPAIN, -20.0);
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_5"));
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 3.0, 1.0);
			break;

		case "partir_bahia_rox":
			AddQuestRecord("Hunter", "14");
			CloseQuestHeader("Hunter");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Emilio Soares"));
			RemoveCharacterCompanion(Pchar, characterFromID("Roxanne Lalliere"));
			LAi_SetActorType(CharacterFromID("Roxanne Lalliere"));
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "goto", "locator12", "none", "", "", "", 6.0);
			break;

		case "sortir_prison":
			Locations[FindLocation("Eleuthera_Jungle4")].vcskip = true;
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Elting"));
			SetOfficersIndex(PChar, 2, GetCharacterIndex("Roxanne Lalliere"));
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "pistol1a");
			GiveItem2Character(CharacterFromId("Roxanne Lalliere"), "blade10");
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "blade10");
			DoQuestReloadToLocation("Eleuthera_Jungle4", "reload", "reload2", "meet_enrique");
			break;

		case "meet_enrique":
			ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Eleuthera_Jungle4", "goto", "goto8");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto7");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PADILLA_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto4");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PADILLA_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto3");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PADILLA_SOLDIERS");

			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_1";
			LAi_SetActorType(characterFromID("Enrique Padilla"));
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 3.5, 1.0);
			break;

		case "info_elting":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_17";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "provoke_padilla":
			LAi_SetOfficerType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_2";
			LAi_SetActorType(characterFromID("Enrique Padilla"));
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 1.0, 1.0);
			break;

		case "fight_padilla":
			LAi_ActorAttack(characterFromID("Enrique Padilla"), pchar, "");
			LAi_group_FightGroups("PADILLA_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PADILLA_SOLDIERS", "Padilla_morto");
			break;

		case "Padilla_morto":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_18";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 4.0, 10.0);
			break;

		case "join_guibert":
			AddQuestRecord("Hunter", "10");
			GiveShip2Character(CharacterFromID("Roxanne Lalliere"),"FR_LightPinnace","La Diablesse",-1,FRANCE,true,true);
			SetCharacterShipLocation(CharacterFromID("Roxanne Lalliere"), "Alice_Port");
			LAi_SetOfficerType(characterFromID("Elting"));
			ChangeCharacterAddressGroup(CharacterFromID("Guibert Daudet"), "Alice_Port", "goto", "goto21");
			LAi_SetStayType(characterFromID("Guibert Daudet"));
			Characters[GetCharacterIndex("Guibert Daudet")].dialog.currentnode = "begin_12";
			ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "none", "", "");
			break;

		case "infoemilio":
			DeleteAttribute(&Locations[FindLocation("Eleuthera_Jungle4")],"vcskip");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_19";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "infoemiliobis":
			LAi_SetOfficerType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_94";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);
			break;

		case "quitter_alice":
			AddQuestRecord("Hunter", "11");
			RemovePassenger(pchar, characterFromID("Roxanne Lalliere"));
			RemoveCharacterCompanion(pchar, characterFromID("Roxanne Lalliere"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Roxanne Lalliere"));
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "reload61_back", "none", "", "", "quitter_alicebis", 10.0);
			LAi_SetActorType(characterFromID("Guibert Daudet"));
			LAi_ActorRunToLocation(characterFromID("Guibert Daudet"), "reload", "reload61_back", "none", "", "", "", 9.0);
			break;

		case "quitter_alicebis":
			RestoreOfficers(pchar.id);
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Roxanne Lalliere"));
			SetCharacterRemovable(characterFromID("Roxanne Lalliere"), false);

			pchar.quest.parabahia.win_condition.l1 = "location";
			pchar.quest.parabahia.win_condition.l1.location = "Cuba_shore_01";
			pchar.quest.parabahia.win_condition = "chegada_antonio";
			break;

		case "chegada_antonio":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Cuba_shore_01", "goto", "goto13");
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_96";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);
			break;

		case "chegada_antoniobis":
			LAi_SetStayType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_21";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "free_emilio":
			Locations[FindLocation("Havana_town_05")].vcskip = true;
			RemovePassenger(pchar, characterFromID("Elting"));
			RemoveCharacterCompanion(pchar, characterFromID("Elting"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Elting"));
			SetCurrentTime(23.00, 0);
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = 1;
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_7"));
			DoQuestReloadToLocation("Havana_town_05", "goto", "goto_35", "free_emiliobis");
			break;

		case "free_emiliobis":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "soldier01");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "soldier02");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "soldier03");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			sld.dialog.filename = "Spaniards_dialog.c";
			sld.dialog.currentnode = "begin_30";
			sld.id = "soldadinho";
			LAi_SetStayType(characterfromID("soldadinho"));
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Havana_town_05", "goto", "goto_7");
			GiveItem2Character(CharacterFromId("Elting"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Elting"), "bladex4");
			GiveItem2Character(CharacterFromId("Elting"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Elting"), "pistolrock");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_22";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 4.0, 1.0);
			break;

		case "free_emiliobis2":
			LAi_ActorFollowEverywhere(characterFromID("Elting"), "", 60.0);
			break;

		case "entrar_havana_jail":
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = 0;
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Havana_prison", "goto", "goto9");
			LAi_SetStayType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_59";
			break;

		case "tuerdansprison":
			Locations[FindLocation("Havana_prison")].vcskip = true;
			DoQuestReloadToLocation("Havana_prison", "goto", "goto18", "tuerdansprisonbis");
			break;

		case "tuerdansprisonbis":
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Havana_prison", "goto", "goto19");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Havana_prison", "goto", "goto17");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_24";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 5.0, 1.0);
			break;

		case "emilio_denovo":
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_61";
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);
			break;

		case "recusar_emilio":
			Locations[FindLocation("Quest_Havana_Town_01")].vcskip = true;
			SetCurrentTime(7.00, 0);
			DoQuestReloadToLocation("Quest_Havana_Town_01", "goto", "goto59", "revient_elting");
			break;

		case "revient_elting":
			DeleteAttribute(&Locations[FindLocation("Havana_town_05")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Havana_prison")],"vcskip");
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Cuba_shore_01", "goto", "goto13");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Quest_Havana_Town_01", "goto", "goto30");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_33";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 3.0, 1.0);
			break;

		case "Benavides_arrival":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(PChar, characterFromID("Quest_Havana_soldier_02"));
			ChangeCharacterAddressGroup(CharacterFromID("Salvadore Benavides"), "Quest_Havana_Town_01", "reload", "reload_2_3");
			ChangeCharacterAddressGroup(CharacterFromID("Quest_Havana_soldier_05"), "Quest_Havana_Town_01", "reload", "reload_2_3");
			ChangeCharacterAddressGroup(CharacterFromID("Quest_Havana_soldier_06"), "Quest_Havana_Town_01", "reload", "reload_2_3");
			LAi_SetActorType(characterFromID("Quest_Havana_soldier_05"));
			LAi_ActorFollow(characterFromID("Quest_Havana_soldier_05"), characterFromID("Salvadore Benavides"), "", 60.0);
			LAi_SetActorType(characterFromID("Quest_Havana_soldier_06"));
			LAi_ActorFollow(characterFromID("Quest_Havana_soldier_06"), characterFromID("Salvadore Benavides"), "", 60.0);
			LAi_SetActorType(CharacterFromID("Salvadore Benavides"));
			LAi_ActorGoToLocation(characterFromID("Salvadore Benavides"), "reload", "door_5", "none", "", "", "explose_mansion", 30.0);
			break;

		case "explose_mansion":
			CreateParticleSystemX("blast", -35.536, 0.00, 3.5, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -35.536, 1.00, 3.5, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast", -33.987, 0.00, -2.8622, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -33.987, 1.00, -2.8622, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast", -35.434, 0.00, 10.042, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -35.434, 1.00, 10.042, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_ActorSetLayMode(characterFromID("Salvadore Benavides"));
			LAi_KillCharacter(characterFromID("Quest_Havana_soldier_05"));
			LAi_KillCharacter(characterFromID("Quest_Havana_soldier_06"));
			LAi_KillCharacter(characterFromID("Quest_Havana_soldier_01"));
			LAi_KillCharacter(characterFromID("Quest_Havana_soldier_02"));
			ChangeCharacterAddressGroup(characterFromID("Salvadore Benavides"), "Quest_Havana_Town_01", "goto", "goto58");
			LAi_Stunned_StunCharacter(characterFromID("Quest_Havana_soldier_03"), 100, true, STUN_STARS, false);
			LAi_Stunned_StunCharacter(characterFromID("Quest_Havana_soldier_04"), 100, true, STUN_STARS, false);
			LAi_SetPlayerType(Pchar);
			LAi_QuestDelay("confirmar_morta", 10.0);
			break;

		case "confirmar_morta":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_ActorFollowEverywhere(characterFromID("Elting"), "", 60.0);
			DoQuestReloadToLocation("Cuba_shore_01", "reload", "reload1", "revenir_bahiabis");
			break;

		case "revenir_bahiabis":
			Build_at("Eleuthera_Port", "Sign", "", -57.6, 2, 7.87, 0.24, "building");
			Locations[FindLocation("Eleuthera_Port")].dangerous = true;
			ChangeRMRelation(pchar, SPAIN, -20.0);
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_5"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_98";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 3.0, 1.0);
			break;

		case "partir_bahia":
			AddQuestRecord("Hunter", "12");
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Emilio Soares"));
			LAi_SetActorType(CharacterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);

			pchar.quest.para_redmond.win_condition.l1 = "location";
			pchar.quest.para_redmond.win_condition.l1.location = "redmond_port";
			pchar.quest.para_redmond.win_condition = "Enfin_PortRoyal";
			break;

		case "Enfin_PortRoyal":
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_100";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 4.0, 1.0);
			break;

		case "Enfin_PortRoyal2":
			LAi_SetActorType(CharacterFromID("Roxanne Lalliere"));
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "sea_1", "none", "", "", "", 6.0);
			RemoveCharacterCompanion(Pchar, characterFromID("Roxanne Lalliere"));
			setCharacterShipLocation(characterFromID("Roxanne Lalliere"), "none");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_35";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 3.0, 1.0);
			break;

		case "debut_tortue":
			Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_1";
			SetCharacterShipLocation(characterFromID("Daniel Montbars"), "Tortuga_port");
			AddQuestRecord("Hunter", "13");
			CloseQuestHeader("Hunter");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			LAi_SetActorType(CharacterFromID("Elting"));
			LAi_ActorRunToLocation(characterFromID("Elting"), "reload", "reload_2_city", "none", "", "", "Elting_at_Douwesen", 8.0);
			break;

			// Battle of Aguadilla

		case "voir_Montbars_tortue":
			Locations[FindLocation("Tortuga_Port")].vcskip = true;
			DoQuestReloadToLocation("Tortuga_Port", "reload", "reload2" ,"voir_Montbars_tortue2");
			break;

		case "voir_Montbars_tortue2":
			ChangeCharacterAddressGroup(characterFromID("Daniel Montbars"), "Tortuga_Port", "goto", "goto20");
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 6.0, 1.0);
			break;

		case "paymaster_antigua":
			SetQuestHeader("Aguadilla");
			AddQuestRecord("Aguadilla", "1");
			Locations[FindLocation("Antigua_port")].reload.l1.disable = 1;
			Locations[FindLocation("Antigua_outskirts")].reload.l2.disable = 1;
			Island_SetReloadEnableLocal("Antigua", "reload_2", false);
			SetCharacterShipLocation(characterFromID("Daniel Montbars"), "none");
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorRunToLocation(characterFromID("Daniel Montbars"), "reload", "reload1_back", "none", "", "", "", 6.0);
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Daniel Montbars"));
			SetCharacterRemovable(characterFromID("Daniel Montbars"), false);

			Pchar.quest.chegar_antigua.win_condition.l1 = "location";
			Pchar.quest.chegar_antigua.win_condition.l1.location = "Antigua_shore";
			Pchar.quest.chegar_antigua.win_condition = "paymaster_antigua2";
			break;

		case "paymaster_antigua2":
			SetCurrentTime(21.00, 0);
			ChangeCharacterAddressGroup(characterFromID("Daniel Montbars"), "Antigua_shore", "goto", "goto24");
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_6";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 6.0, 1.0);
			break;

		case "paymaster_antigua3":
			Locations[FindLocation("Antigua_outskirts")].vcskip = true;
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorFollowEverywhere(characterFromID("Daniel Montbars"), "", 60.0);

			Pchar.quest.near_antigua.win_condition.l1 = "location";
			Pchar.quest.near_antigua.win_condition.l1.location = "Antigua_outskirts";
			Pchar.quest.near_antigua.win_condition = "paymaster_antigua4";
			break;

		case "paymaster_antigua4":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_11";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 2.0, 1.0);
			break;

		case "paymaster_antigua5":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorRunToLocation(characterFromID("Daniel Montbars"), "reload", "reload6", "Antigua_outskirts", "reload", "reload6", "paymaster_antigua6", 30.0);
			break;

		case "paymaster_antigua6":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 2.0, 1.0);
			break;

		case "paymaster_antigua7":
			LAi_Fade("paymaster_antigua8", "");
			break;

		case "paymaster_antigua8":
			Locations[FindLocation("Antigua_mansion_bedroom2")].vcskip = true;
			StoreOfficers(pchar.id);
			ChangeCharacterAddressGroup(characterFromID("Daniel Montbars"), "Antigua_outskirts", "goto", "goto53");
			ChangeCharacterAddressGroup(characterFromID("Antigua_soldado"), "Antigua_port", "goto", "goto32");
			ChangeCharacterAddressGroup(characterFromID("Martin de Urquiza"), "Antigua_mansion_bedroom2", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Ferro Carriles"), "Antigua_mansion_bedroom2", "goto", "goto5");

			Pchar.quest.inside_antigua.win_condition.l1 = "location";
			Pchar.quest.inside_antigua.win_condition.l1.location = "Antigua_port";
			Pchar.quest.inside_antigua.win_condition = "paymaster_antigua9";
			break;

		case "paymaster_antigua9":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, true, "attaquesoldiers");
			Locations[FindLocation("Antigua_port")].reload.l17.disable = 0;
			Characters[GetCharacterIndex("Martin de Urquiza")].dialog.currentnode = "begin_1";
			TakenItems(Pchar, "pistolpdart", 4);
			EquipCharacterbyItem(Pchar, "pistolpdart");
			break;

		case "paymaster_antigua11":
			LAi_SetActorType(characterFromID("Martin de Urquiza"));
			LAi_ActorFollowEverywhere(characterFromID("Martin de Urquiza"), "", 60.0);
			LAi_SetActorType(characterFromID("Ferro Carriles"));
			LAi_ActorFollowEverywhere(characterFromID("Ferro Carriles"), "", 60.0);

			Pchar.quest.port_antigua.win_condition.l1 = "location";
			Pchar.quest.port_antigua.win_condition.l1.location = "Antigua_port";
			Pchar.quest.port_antigua.win_condition = "paymaster_antigua11b";
			break;

		case "paymaster_antigua11b":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			Pchar.quest.outside_antigua.win_condition.l1 = "location";
			Pchar.quest.outside_antigua.win_condition.l1.location = "Antigua_outskirts";
			Pchar.quest.outside_antigua.win_condition = "paymaster_antigua12";
			break;

		case "paymaster_antigua12":
			LAi_RemoveCheckMinHP(Pchar);
			LAi_SetImmortal(Pchar, false);
			RestoreOfficers(pchar.id);
			ChangeCharacterAddressGroup(characterFromID("Martin de Urquiza"), "Antigua_outskirts", "goto", "goto53");
			LAi_SetStayType(characterFromID("Martin de Urquiza"));
			ChangeCharacterAddressGroup(characterFromID("Ferro Carriles"), "Antigua_outskirts", "goto", "goto9");
			LAi_SetStayType(characterFromID("Ferro Carriles"));
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 20.0, 1.0);
			break;

		case "attaquesoldiers":
			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_RemoveCheckMinHP(Pchar);
			Locations[FindLocation("Antigua_port")].reload.l6.disable = 1;
			Locations[FindLocation("Antigua_port")].reload.l17.disable = 1;
			LAi_SetImmortal(Pchar, false);
			break;

		case "paymaster_antigua13":
			LAi_SetOfficerType(characterFromID("Daniel Montbars"));
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[ENGLAND].fantomModel.m1, "reload", "reload1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "ANTIGUA_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[ENGLAND].fantomModel.m2, "reload", "reload1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "ANTIGUA_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[ENGLAND].fantomModel.m3, "reload", "reload1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "ANTIGUA_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[ENGLAND].fantomModel.m4, "reload", "reload1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "ANTIGUA_SOLDIERS");
			LAi_group_FightGroups("ANTIGUA_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANTIGUA_SOLDIERS", "paymaster_antigua14");
			break;

		case "paymaster_antigua14":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_17";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 20.0, 1.0);
			break;

		case "paymaster_antigua15":
			AddQuestRecord("Aguadilla", "2");
			DeleteAttribute(&Locations[FindLocation("Antigua_outskirts")],"vcskip");
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorFollowEverywhere(characterFromID("Daniel Montbars"), "", 60.0);
			LAi_SetActorType(characterFromID("Martin de Urquiza"));
			LAi_ActorFollowEverywhere(characterFromID("Martin de Urquiza"), "", 60.0);
			LAi_SetActorType(characterFromID("Ferro Carriles"));
			LAi_ActorFollowEverywhere(characterFromID("Ferro Carriles"), "", 60.0);

			Locations[FindLocation("Tortuga_Port")].vcskip = true;
			Pchar.quest.revenir_tortue.win_condition.l1 = "location";
			Pchar.quest.revenir_tortue.win_condition.l1.location = "Tortuga_Port";
			Pchar.quest.revenir_tortue.win_condition = "paymaster_tortuga";
			break;

		case "paymaster_tortuga":
			DeleteAttribute(&Locations[FindLocation("Tortuga_port")],"vcskip");
			ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "Tortuga_Port", "goto", "goto20");
			LAi_SetStayType(characterFromID("Bertrand Ogeron"));
			LAi_SetActorType(characterFromID("Martin de Urquiza"));
			Characters[GetCharacterIndex("Martin de Urquiza")].dialog.currentnode = "begin_6";
			LAi_ActorDialog(characterFromID("Martin de Urquiza"), pchar, "", 10.0, 1.0);
			break;

		case "paymaster_tortuga2":
			Locations[FindLocation("Antigua_port")].reload.l1.disable = 0;
			Locations[FindLocation("Antigua_outskirts")].reload.l2.disable = 0;
			Island_SetReloadEnableLocal("Antigua", "reload_2", true);
			LAi_SetActorType(characterFromID("Bertrand Ogeron"));
			Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_21";
			LAi_ActorDialog(characterFromID("Bertrand Ogeron"), pchar, "", 6.0, 0.5);
			break;

		case "paymaster_tortuga3":
			Locations[FindLocation("Tortuga_town_exit")].vcskip = true;
			DoQuestReloadToLocation("Tortuga_town_exit", "reload", "reload3", "paymaster_tortuga4");
			break;

		case "paymaster_tortuga4":
			GiveItem2Character(CharacterFromId("Daniel Montbars"), "bladeclub");
			EquipCharacterByItem(CharacterFromId("Daniel Montbars"), "bladeclub");
			LAi_SetStayType(characterFromID("Martin de Urquiza"));
			LAi_SetStayType(characterFromID("Ferro Carriles"));
			ChangeCharacterAddressGroup(characterFromID("Martin de Urquiza"), "Tortuga_town_exit", "goto", "citizen011");
			ChangeCharacterAddressGroup(characterFromID("Ferro Carriles"), "Tortuga_town_exit", "goto", "citizen020");
			ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "Tortuga_town_exit", "goto", "citizen08");
			LAi_SetActorType(characterFromID("Bertrand Ogeron"));
			Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_23";
			LAi_ActorDialog(characterFromID("Bertrand Ogeron"), pchar, "", 10.0, 1.0);
			break;

		case "paymaster_tortuga5":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_18";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 6.0, 1.0);
			break;

		case "paymaster_tortuga6":
			LAi_SetImmortal(CharacterFromID("Ferro Carriles"), false);
			LAi_ActorAttack(CharacterFromID("Daniel Montbars"), CharacterFromID("Ferro Carriles"), "");

			Pchar.quest.valet_died.win_condition.l1 = "NPC_Death";
			Pchar.quest.valet_died.win_condition.l1.character = "Ferro Carriles";
			Pchar.quest.valet_died.win_condition = "paymaster_tortuga7";
			break;

		case "paymaster_tortuga7":
			LAi_SetActorType(characterFromID("Martin de Urquiza"));
			Characters[GetCharacterIndex("Martin de Urquiza")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Martin de Urquiza"), pchar, "", 10.0, 1.0);
			break;

		case "paymaster_tortuga8":
			LAi_SetActorType(characterFromID("Bertrand Ogeron"));
			Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_24";
			LAi_ActorDialog(characterFromID("Bertrand Ogeron"), pchar, "", 4.0, 1.0);
			break;

		case "paymaster_tortuga9":
			DoQuestReloadToLocation("Tortuga_Townhall", "reload", "locator2", "paymaster_tortuga10");
			break;

		case "paymaster_tortuga10":
			ChangeCharacterAddress(characterFromID("Martin de Urquiza"), "none", "");
			ChangeCharacterAddress(characterFromID("Ferro Carriles"), "none", "");
			DeleteAttribute(&Locations[FindLocation("Tortuga_town_exit")],"vcskip");
			ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "Tortuga_townhall", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Daniel Montbars"), "Tortuga_townhall", "goto", "goto2");
			LAi_SetActorType(characterFromID("Bertrand Ogeron"));
			Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_25";
			LAi_ActorDialog(characterFromID("Bertrand Ogeron"), pchar, "", 1.0, 0.5);
			break;

		case "paymaster_tortuga11":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_20";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 1.0, 0.5);
			break;

		case "paymaster_tortuga12":
			LAi_SetActorType(characterFromID("Bertrand Ogeron"));
			Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_28";
			LAi_ActorDialog(characterFromID("Bertrand Ogeron"), pchar, "", 2.0, 1.0);
			break;

		case "fontaines_tortuga":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorFollowEverywhere(characterFromID("Daniel Montbars"), "", 60.0);
			ChangeCharacterAddressGroup(characterFromID("Arnaud Fontaines"), "Tortuga_port", "reload", "reload2");
			Characters[GetCharacterIndex("Arnaud Fontaines")].dialog.currentnode = "begin_1";
			SetCharacterShipLocation(characterFromID("Arnaud Fontaines"), "Tortuga_Port");
			break;

		case "Voir_Rox_Martinique":
			AddQuestRecord("Aguadilla", "3");
			SetCompanionIndex(Pchar, 2, GetCharacterIndex("Arnaud Fontaines"));
			SetCharacterRemovable(characterFromID("Arnaud Fontaines"), false);
			ChangeCharacterAddressGroup(CharacterFromID("Bertrand Ogeron"), "Tortuga_Townhall", "sit", "sit3");
			LAi_SetHuberType(CharacterFromID("Bertrand Ogeron"));
			LAi_SetActorType(characterFromID("Arnaud Fontaines"));
			LAi_ActorFollowEverywhere(characterFromID("Arnaud Fontaines"), "", 60.0);

			Pchar.quest.roxy_marti.win_condition.l1 = "location";
			Pchar.quest.roxy_marti.win_condition.l1.location = "Falaise_de_fleur_port_01";
			Pchar.quest.roxy_marti.win_condition = "Voir_Rox_Martiniqueb";
			break;

		case "Voir_Rox_Martiniqueb":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_21";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 3.0, 0.5);
			break;

		case "Voir_Rox_Martiniqueb1":
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_104";
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Falaise_de_fleur_tavern", "goto", "goto4");
			LAi_SetStayType(characterFromID("Roxanne Lalliere"));
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorFollowEverywhere(characterFromID("Daniel Montbars"), "", 60.0);
			break;

		case "Voir_Rox_Martiniquebis":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			SetCompanionIndex(Pchar, 3, GetCharacterIndex("Roxanne Lalliere"));
			SetCharacterRemovable(characterFromID("Roxanne Lalliere"), false);
			DoQuestReloadToLocation("Falaise_de_fleur_port_01", "reload", "sea", "Voir_Rox_Martiniquebis2");
			break;

		case "Voir_Rox_Martiniquebis2":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_108";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 3.0, 0.5);
			break;

		case "Voir_Rox_Martiniquebis3":
			AddQuestRecord("Aguadilla", "4");
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "sea", "none", "", "", "", 2.0);
			LAi_ActorRunToLocation(characterFromID("Daniel Montbars"), "reload", "sea", "none", "", "", "", 2.0);
			LAi_ActorRunToLocation(characterFromID("Arnaud Fontaines"), "reload", "sea", "none", "", "", "", 2.0);
			Pchar.quest.Aguadilla_forte.win_condition.l1 = "location";
			Pchar.quest.Aguadilla_forte.win_condition.l1.location = "IslaMuelle";
			Pchar.quest.Aguadilla_forte.win_condition = "video_forte";
			break;

		case "video_forte":
			Locations[FindLocation("Muelle_shore_03")].townsack = "Isla Muelle";
			RemoveCharacterCompanion(Pchar, characterFromID("Daniel Montbars"));
			RemoveCharacterCompanion(Pchar, characterFromID("Roxanne Lalliere"));
			RemoveCharacterCompanion(Pchar, characterFromID("Arnaud Fontaines"));
			PostVideoAndQuest("Aguadilla",1, "reload_Aguadilla");
			break;

		case "reload_Aguadilla":
			LAi_SetImmortal(characterFromID("Roxanne Lalliere"), true);
			LAi_SetImmortal(characterFromID("Daniel Montbars"), true);
			SetNextWeather("Blue Sky");
			SetCurrentTime(20.00, 0);
			SetCharacterShipLocation(Pchar, "Muelle_shore_03");
			SetCharacterShipLocation(characterFromID("Daniel Montbars"), "Muelle_shore_03");
			SetCharacterShipLocation(characterFromID("Roxanne Lalliere"), "Muelle_shore_03");
			SetCharacterShipLocation(characterFromID("Arnaud Fontaines"), "Muelle_shore_03");
			DoReloadFromSeaToLocation("Muelle_shore_03","goto", "locator25");

			Pchar.quest.Aguadilla_fortebis.win_condition.l1 = "location";
			Pchar.quest.Aguadilla_fortebis.win_condition.l1.location = "Muelle_shore_03";
			Pchar.quest.Aguadilla_fortebis.win_condition = "reload_Aguadillabis";
			break;

		case "reload_Aguadillabis":
			WriteLocatorGlobal("Muelle_shore_03", "fire", "fire1", "", -1, 120.36, 21, 42.865, false);
			WriteLocatorGlobal("Muelle_shore_03", "fire", "fire2", "", -1, 107, 21, 100, false);
			WriteLocatorGlobal("Muelle_shore_03", "fire", "fire3", "", -1, 140, 13, 49, false);
			Locations[FindLocation("Muelle_shore_03")].models.night.lights.fire = "heater";
			Locations[FindLocation("Muelle_shore_03")].locators_radius.fire = 4.0;
			CreateParticleSystemX("fireball", 120.36, 21, 42.865, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fireball", 107, 21, 100, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fireball", 140, 13, 49, -1.57, 0.0, 0.0,0);
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			ChangeCharacterAddressGroup(CharacterFromID("Daniel Montbars"), "Muelle_shore_03", "goto", "goto75");
			GiveItem2Character(CharacterFromID("Daniel Montbars"), "bladeaxe2");
			EquipCharacterByItem(CharacterFromID("Daniel Montbars"), "bladeaxe2");
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Muelle_shore_03", "goto", "goto76");
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto73", "premiere_salve", 20.0);
			break;

		case "premiere_salve":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnByLocator( pchar, "goto", "goto71");
			LAi_QuestDelay("premiere_salvebis", 3.0);
			break;

		case "premiere_salvebis":
			LAi_SetPlayerType(Pchar);
			CreateParticleSystemX("cancloud", -144, 4, 470, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -134, 4, 470, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -124, 4, 470, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -114, 4, 470, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("premiere_salvetouche", 1.5);
			break;

		case "premiere_salvetouche":
			CreateParticleSystemX("blast", 140, 25, 70, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", 140, 25, 70, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			LAi_QuestDelay("deuxieme_salve", 3.0);
			break;

		case "deuxieme_salve":
			CreateParticleSystemX("cancloud", 90, 4, 450, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 100, 4, 450, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 110, 4, 450, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 120, 4, 450, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("deuxieme_salvetouche", 1.5);
			break;

		case "deuxieme_salvetouche":
			CreateParticleSystemX("blast", 120, 14, 70, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", 120, 14, 70, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			CreateParticleSystem("ball_impact", 100, 14, 70, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", 100, 14, 70, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", 100, 14, 70, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("flyers", 100, 14, 70, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("flyers2", 100, 14, 70, 0.0, 0.0, 0.0, 0);
			LAi_KillCharacter(characterFromID("aguadilla_soldier_02"));
			LAi_QuestDelay("troisieme_salve", 3.0);
			break;

		case "troisieme_salve":
			CreateParticleSystemX("cancloud", 300, 4, 425, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 310, 4, 425, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 320, 4, 425, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 330, 4, 425, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("troisieme_salvetouche", 1.5);
			break;

		case "troisieme_salvetouche":
			CreateParticleSystemX("blast", 165, 21, 53, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", 165, 21, 53, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			ChangeCharacterAddressGroup(CharacterFromID("aguadilla_soldier_01"), "Muelle_shore_03", "goto", "goto13");
			LAi_SetActorType(characterFromID("aguadilla_soldier_01"));
			LAi_ActorSetLayMode(characterFromID("aguadilla_soldier_01"));
			LAi_QuestDelay("quatrieme_salve", 3.0);
			break;

		case "quatrieme_salve":
			CreateParticleSystemX("cancloud", -144, 4, 470, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -134, 4, 470, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -124, 4, 470, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -114, 4, 470, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("quatrieme_salvetouche", 1.5);
			break;

		case "quatrieme_salvetouche":
			CreateParticleSystemX("blast", 120.36, 22, 42.865, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", 120.36, 22, 42.865, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			CreateParticleSystem("ball_impact", 120, 22, 42, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", 120, 22, 42, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", 120, 22, 42, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("flyers", 120, 22, 42, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("flyers2", 120, 22, 42, 0.0, 0.0, 0.0, 0);
			LAi_QuestDelay("cinquieme_salve", 3.0);
			break;

		case "cinquieme_salve":
			CreateParticleSystemX("cancloud", 90, 4, 450, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 100, 4, 450, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 110, 4, 450, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 120, 4, 450, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("cinquieme_salvetouche", 1.5);
			break;

		case "cinquieme_salvetouche":
			CreateParticleSystemX("blast", 107, 22, 100, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", 107, 22, 100, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			CreateParticleSystem("ball_impact", 106, 22, 100, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", 106, 22, 100, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", 106, 22, 100, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("flyers", 106, 22, 100, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("flyers2", 106, 22, 100, 0.0, 0.0, 0.0, 0);
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");
			LAi_QuestDelay("fin_salves", 1.0);
			break;

		case "fin_salves":
			ref aguadilla;
			aguadilla = &Locations[FindLocation("Muelle_shore_03")];
			DeleteAttribute(aguadilla,"building");
			ChangeCharacterAddress(characterFromID("aguadilla_soldier_02"), "none", "");
			ChangeCharacterAddress(characterFromID("aguadilla_soldier_01"), "none", "");
			LAi_QuestDelay("fin_salvesbis", 2.0);
			break;

		case "fin_salvesbis":
			Build_at("Muelle_shore_03", "tower", "", 217.13, 2.07, 55.58, -2.33, "");
			Build_at("Muelle_shore_03", "townwalls", "", 216.7, 2, 56.148, -1.976, "");
			Build_at("Muelle_shore_03", "jungle2", "", 4.659, 3.7, -1.562, 0, "");
			Build_at("Muelle_shore_03", "jungle2", "", 116.57, 3.3, -7.47, -0.448, "");
			Build_at("Muelle_shore_03", "jungle2", "", 60.918, 3.515, -19.491, 0.351, "");
			Build_at("Muelle_shore_03", "jungle2", "", 87.027, 3.2, -17.1, -0.14, "");
			Build_at("Muelle_shore_03", "Field_Cannon_1", "", 196.43, 2.249, 45.673, -0.25, "");
			DoQuestReloadToLocation("Muelle_shore_03", "goto", "goto73", "parler_montbars");
			break;

		case "parler_montbars":
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat1"), "Muelle_shore_03", "goto", "goto46");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat2"), "Muelle_shore_03", "goto", "goto47");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat3"), "Muelle_shore_03", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat4"), "Muelle_shore_03", "goto", "goto49");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat5"), "Muelle_shore_03", "goto", "goto50");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat6"), "Muelle_shore_03", "goto", "goto51");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat7"), "Muelle_shore_03", "goto", "goto52");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat8"), "Muelle_shore_03", "goto", "goto53");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat9"), "Muelle_shore_03", "goto", "goto54");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat10"), "Muelle_shore_03", "goto", "goto56");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat11"), "Muelle_shore_03", "goto", "goto57");

			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate1"), "Muelle_shore_03", "goto", "goto62");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate2"), "Muelle_shore_03", "goto", "goto63");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate3"), "Muelle_shore_03", "goto", "goto64");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate4"), "Muelle_shore_03", "goto", "goto65");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate5"), "Muelle_shore_03", "goto", "goto66");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate6"), "Muelle_shore_03", "goto", "goto67");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate7"), "Muelle_shore_03", "goto", "goto68");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate8"), "Muelle_shore_03", "goto", "goto69");

			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_22";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 2.0, 0.5);
			break;

		case "begin_battle":
			LAi_group_MoveCharacter(Pchar, "Aguadilla_Pirates");
			LAi_group_MoveCharacter(characterFromID("Roxanne Lalliere"), "Aguadilla_Pirates");
			LAi_group_MoveCharacter(characterFromID("Daniel Montbars"), "Aguadilla_Pirates");
			LAi_group_FightGroups("AGUADILLA_SOLDIERS", "Aguadilla_Pirates", true);
			PlayStereoSound("OBJECTS\ABORDAGE\abordageLong.wav");
			LAi_QuestDelay("spanish_cannon", 18.0);
			break;

		case "spanish_cannon":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_group_SetCheck("AGUADILLA_SOLDIERS", "end_battle");
			CreateParticleSystemX("blast_inv", 116, 3.5, 3, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 116, 3.5, 3, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_QuestDelay("spanish_cannon2", 7.0);
			break;

		case "spanish_cannon2":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("blast_inv", 118, 2.5, 9.5, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 118, 2.5, 9.5, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_QuestDelay("destruction_cannon", 12.0);
			break;

		case "destruction_cannon":
			CreateParticleSystemX("cancloud", 100, 4, 450, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("destruction_cannonbis", 1.5);
			break;

		case "destruction_cannonbis":
			CreateParticleSystemX("blast_inv", 196, 3, 46, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 196, 3, 46, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			LAi_KillCharacter(characterFromID("Aguadilla_Soldat10"));
			LAi_KillCharacter(characterFromID("Aguadilla_Soldat11"));
			break;

		case "end_battle":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorFollowEverywhere(characterFromID("Daniel Montbars"), "", 60.0);
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_110";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 30.0, 0.5);
			break;

		case "end_battlebis":
			Locations[FindLocation("Aguadilla_fakefort2")].vcskip = true;
			Locations[FindLocation("Aguadilla_fakefort3")].vcskip = true;
			locations[FindLocation("Muelle_shore_03")].reload.l4.disable = 0;
			locations[FindLocation("Muelle_shore_03")].reload.l5.disable = 0;
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);

			LAi_SetActorType(characterFromID("Aguadilla_Pirate1"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate1"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate2"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate2"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate3"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate3"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate4"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate4"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate5"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate5"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate6"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate6"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate7"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate7"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate8"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate8"), "", 60.0);

			pchar.quest.paraforte.win_condition.l1 = "location";
			pchar.quest.paraforte.win_condition.l1.location = "Aguadilla_fakefort3";
			pchar.quest.paraforte.win_condition = "combate_forte";
			break;

		case "combate_forte":
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));
			LAi_SetOfficerType(characterFromID("Daniel Montbars"));

			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate1"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate2"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate3"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate4"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate5"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate6"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate7"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate8"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m1, "reload", "reloadc1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m2, "reload", "reloadc1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m3, "reload", "reloadc1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m4, "reload", "reloadc1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m5, "reload", "reloadc1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m6, "reload", "reloadc1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDIERS");
			LAi_group_FightGroups("FORTE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FORTE_SOLDIERS", "battle_forte");
			break;

		case "battle_forte":
			locations[FindLocation("Aguadilla_fakefort3")].reload.l1.disable = 0;
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorFollowEverywhere(characterFromID("Daniel Montbars"), "", 60.0);

			LAi_SetActorType(characterFromID("Aguadilla_Pirate1"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate1"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate2"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate2"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate3"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate3"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate4"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate4"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate5"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate5"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate6"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate6"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate7"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate7"), "", 60.0);
			LAi_SetActorType(characterFromID("Aguadilla_Pirate8"));
			LAi_ActorFollowEverywhere(characterFromID("Aguadilla_Pirate8"), "", 60.0);

			pchar.quest.parainside.win_condition.l1 = "location";
			pchar.quest.parainside.win_condition.l1.location = "Aguadilla_fakefort2";
			pchar.quest.parainside.win_condition = "combate_forte2";
			break;

		case "combate_forte2":
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));
			LAi_SetOfficerType(characterFromID("Daniel Montbars"));

			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate1"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate2"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate3"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate4"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate5"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate6"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate7"));
			LAi_SetOfficerType(characterFromID("Aguadilla_Pirate8"));

			// PB: Doesn't work - Meant to prevent issues when you accidentally hit them -->
			LAi_group_MoveCharacter(characterFromID("Daniel Montbars"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Roxanne Lalliere"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Aguadilla_Pirate1"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Aguadilla_Pirate2"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Aguadilla_Pirate3"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Aguadilla_Pirate4"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Aguadilla_Pirate5"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Aguadilla_Pirate6"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Aguadilla_Pirate7"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Aguadilla_Pirate8"), LAI_GROUP_PLAYER);
			// PB: Doesn't work - Meant to prevent issues when you accidentally hit them <--

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m1, "rld", "aloc4");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTES_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m2, "rld", "loc4");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTES_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m3, "rld", "loc2");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTES_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m4, "rld", "loc1");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTES_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[SPAIN].fantomModel.m5, "rld", "aloc2");
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			LAi_group_MoveCharacter(sld, "FORTES_SOLDIERS");

			LAi_group_FightGroups("FORTES_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FORTES_SOLDIERS", "battle_forte2");
			break;

		case "battle_forte2":
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_25";
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 2.0, 1.0);
			break;

		case "battle_forte3":
			ChangeCharacterAddressGroup(CharacterFromID("Aspidius Vallalpando"), "Aguadilla_fakefort2", "reload", "reload1");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorFollowEverywhere(characterFromID("Daniel Montbars"), "", 60.0);
			LAi_SetImmortal(characterFromID("Roxanne Lalliere"), false);
			LAi_SetImmortal(characterFromID("Daniel Montbars"), false);
			break;

		case "battle_forte4":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			CreateParticleSystemX("blast_inv", 11.2, 13.3, 3.2, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", 11.2, 13.3, 3.2, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_QuestDelay("battle_forte5", 1.0);
			break;

		case "battle_forte5":
			LAi_KillCharacter(characterFromID("Aspidius Vallalpando"));
			LAi_SetActorType(Pchar);
			LAi_ActorAnimation(Pchar, "death_1", "battle_forte6", 4.0);
			LAi_Stunned_StunCharacter(characterFromID("Roxanne Lalliere"), 100, true, STUN_STARS, false);
			break;

		case "battle_forte6":
			ref forte;
			forte = &Locations[FindLocation("Aguadilla_fakefort2")];
			DeleteAttribute(forte,"building");
			LAi_SetOfficerType(characterFromID("Daniel Montbars"));
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate3"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate4"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate5"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate6"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate7"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Pirate8"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Daniel Montbars"), "none", "", "");
			DoQuestReloadToLocation("Aguadilla_fakefort2", "reload", "reload1", "battle_forte8");
			break;

		case "battle_forte8":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Aguadilla_fakefort2", "rld", "aloc1");
			LAi_ActorAnimation(Pchar, "Ground_StandUp", "battle_forte9", 3.0);
			break;

		case "battle_forte9":
			LAi_SetPlayerType(Pchar);
			setCharacterShipLocation(characterFromID("Daniel Montbars"), "none");
			LAi_QuestDelay("battle_forte9b", 2.0);
			break;

		case "battle_forte9b":
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat3"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat4"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat5"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat6"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat7"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat8"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat9"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat10"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Aguadilla_Soldat11"), "none", "", "");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_112";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 10.0, 1.0);
			break;

		case "battle_forte10":
			Locations[FindLocation("Aguadilla_fakefort2")].reload.l2.disable = 0;
			Locations[FindLocation("Aguadilla_fakefort3")].reload.l4.disable = 0;
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			ChangeCharacterAddressGroup(CharacterFromID("Arnaud Fontaines"), "Muelle_shore_03", "goto", "goto13");
			LAi_SetActorType(characterFromID("Arnaud Fontaines"));
			LAi_ActorSetLayMode(characterFromID("Arnaud Fontaines"));
			Characters[GetCharacterIndex("Arnaud Fontaines")].dialog.currentnode = "begin_6";
			LAi_ActorWaitDialog(characterFromID("Arnaud Fontaines"), pchar);
			LAi_ActorDialog(pchar, characterFromID("Arnaud Fontaines"), "", 4.0, 1.0);
			break;

		case "battle_forte11":
			LAi_Fade("battle_forte12", "");
			break;

		case "battle_forte12":
			LAi_SetStayType(characterFromID("Arnaud Fontaines"));
			Characters[GetCharacterIndex("Arnaud Fontaines")].dialog.currentnode = "begin_7";
			LAi_SetActorType(characterFromID("Arnaud Fontaines"));
			LAi_ActorDialog(characterFromID("Arnaud Fontaines"), pchar, "", 2.0, 1.0);
			break;

		case "inform_ogeron":
			AddQuestRecord("Aguadilla", "5");
			LAi_SetActorType(characterFromID("Arnaud Fontaines"));
			LAi_ActorFollowEverywhere(characterFromID("Arnaud Fontaines"), "", 60.0);
			Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_32";
			SetCompanionIndex(Pchar, 1, GetCharacterIndex("Arnaud Fontaines"));
			SetCharacterRemovable(characterFromID("Arnaud Fontaines"), false);
			SetCompanionIndex(Pchar, 2, GetCharacterIndex("Roxanne Lalliere"));
			SetCharacterRemovable(characterFromID("Roxanne Lalliere"), false);
			QuestToSeaLogin_PrepareLoc("IslaMuelle", "reload", "reload_3", true);
			QuestToSeaLogin_Launch();
			break;

		case "searching_montbars":
			AddQuestRecord("Aguadilla", "6");
			RemoveCharacterCompanion(Pchar, characterFromID("Roxanne Lalliere"));
			RemoveCharacterCompanion(Pchar, characterFromID("Arnaud Fontaines"));
			LAi_SetStayType(characterFromID("Arnaud Fontaines"));
			LAi_SetStayType(characterFromID("Roxanne Lalliere"));
			ChangeCharacterAddressGroup(CharacterFromID("Daniel Montbars"), "Cayman_Pirate_house_01_inside", "goto", "goto1");
			Characters[GetCharacterIndex("Daniel Montbars")].dialog.currentnode = "begin_26";
			EquipCharacterByItem(CharacterFromId("Daniel Montbars"), "blade31");

			pchar.quest.paracayman.win_condition.l1 = "location";
			pchar.quest.paracayman.win_condition.l1.location = "Cayman_Pirate_house_01_inside";
			pchar.quest.paracayman.win_condition = "montbars_found";
			break;

		case "montbars_found":
			LAi_SetActorType(characterFromID("Daniel Montbars"));
			LAi_ActorDialog(characterFromID("Daniel Montbars"), pchar, "", 4.0, 1.0);
			break;

		case "montbars_duel":
			LAi_ActorAttack(CharacterFromID("Daniel Montbars"), PChar, "");
			Pchar.quest.tuer_montbars.win_condition.l1 = "NPC_Death";
			Pchar.quest.tuer_montbars.win_condition.l1.character = "Daniel Montbars";
			Pchar.quest.tuer_montbars.win_condition = "search_map";
			break;

		case "search_map":
			AddQuestRecord("Aguadilla", "7");
			pchar.quest.map_muerte.win_condition.l1 = "locator";
			pchar.quest.map_muerte.win_condition.l1.location = "Cayman_Pirate_house_01";
			pchar.quest.map_muerte.win_condition.l1.locator_group = "goto";
			pchar.quest.map_muerte.win_condition.l1.locator = "locator6";
			pchar.quest.map_muerte.win_condition = "muerte_map";
			break;

		case "muerte_map":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Find_map";
			LAi_ActorSelfDialog(Pchar, "player_back");
			break;

		case "heading_muerte":
			GiveItem2Character(pchar, "muerte_map");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 5000); }

			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arnaud Fontaines"), "none", "", "");
			LAi_QuestDelay("heading_muertebis", 2.0);
			break;

		case "heading_muertebis":
			locations[FindLocation("IslaDeMuerte_shore_01")].reload.l2.disable = 0;
			Build_at("Grotto", "box", "", 33.72, 4.26, -60.35, 0.24, "building");
			Build_at("Grotto", "box", "", 30.37, 4.27, -59.88, 0.24, "building");
			Build_at("Grotto", "box", "", 36.11, 4.27, -56.58, 1.56, "building");
			Build_at("Grotto", "box", "", 41.88, 4.22, -51.17, -1.44, "building");
			Build_at("Grotto", "box", "", 36.98, 4.24, -45.56, 0.37, "building");
			Build_at("Grotto", "box", "", 25.05, 4.26, -52.47, -1.44, "building");
			Build_at("Grotto", "box", "", 27.19, 4.29, -56.27, 0.37, "building");
			Build_at("Grotto", "box", "", 20.66, 4.29, -50.43, -1.44, "building");

			Locations[FindLocation("Grotto")].locators_radius.goto.goto3 = 6.0;

			pchar.quest.find_ouro.win_condition.l1 = "locator";
			pchar.quest.find_ouro.win_condition.l1.location = "Grotto";
			pchar.quest.find_ouro.win_condition.l1.locator_group = "goto";
			pchar.quest.find_ouro.win_condition.l1.locator = "goto3";
			pchar.quest.find_ouro.win_condition = "encontra_ouro";
			break;

		case "encontra_ouro":
			LAi_SetActorType(Pchar);
			LAi_ActorRunToLocation(Pchar, "goto", "goto9", "grotto", "goto", "goto9", "encontra_ourobis", 15.0);
			break;

		case "encontra_ourobis":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Find_ouro";
			LAi_ActorSelfDialog(Pchar, "player_back");
			break;

		case "load_ouro":
			LAi_SetPlayerType(Pchar);
			DoQuestReloadToLocation("IslaDeMuerte_shore_01", "reload", "reload2", "load_ourobis");
			break;

		case "load_ourobis":
			ref ouro;
			ouro = &Locations[FindLocation("Grotto")];
			DeleteAttribute(ouro,"building");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_62";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);
			break;

		case "voltar_tortue":
			AddQuestRecord("Aguadilla", "8");
			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Emilio Soares")].dialog.CurrentNode = "hired";
			Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_38";
			break;

		case "partager_gold":
			DoQuestReloadToLocation("Tortuga_Port", "reload", "reload2" ,"partager_goldbis");
			break;

		case "partager_goldbis":
			ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "Tortuga_Port", "goto", "goto20");
			LAi_SetStayType(characterFromID("Bertrand Ogeron"));
			ChangeCharacterAddressGroup(characterFromID("Roxanne Lalliere"), "Tortuga_Port", "goto", "goto19");
			ChangeCharacterAddressGroup(characterFromID("Arnaud Fontaines"), "Tortuga_Port", "goto", "goto16");
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			LAi_SetActorType(characterFromID("Arnaud Fontaines"));
			LAi_ActorFollowEverywhere(characterFromID("Arnaud Fontaines"), "", 60.0);
			LAi_SetActorType(characterFromID("Bertrand Ogeron"));
			Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_44"; // Talisman
			LAi_ActorDialog(characterFromID("Bertrand Ogeron"), pchar, "", 10.0, 1.0);
			break;

		case "partager_goldbis2":
			Characters[GetCharacterIndex("Arnaud Fontaines")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Arnaud Fontaines"), pchar, "", 3.0, 1.0);
			break;

		case "partager_goldbis3":
			DeleteAttribute(&Locations[FindLocation("Tortuga_port")],"vcskip");
			LAi_ActorRunToLocation(characterFromID("Bertrand Ogeron"), "reload", "reload3_back", "none", "", "", "", 10.0);
			LAi_ActorRunToLocation(characterFromID("Arnaud Fontaines"), "reload", "reload3_back", "none", "", "", "", 10.0);
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_116";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 3.0, 1.0);
			break;

		case "partager_goldbis4":
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_18";
			ChangeRMRelation(pchar, SPAIN, -20.0);
			AddQuestRecord("Aguadilla", "9");
			CloseQuestHeader("Aguadilla");
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "reload2_back", "none", "", "", "Roxanne_at_FalaisedeFleur", 4.0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			break;

		case "story_davy":
			GiveShip2Character(characterFromID("Nathaniel Hawk"),"CursedCaravel","Victory",-1,PIRATE,true,true);
			EquipCharacterByItem(CharacterFromId("Nathaniel Hawk"), "blade31");
			EquipCharacterByItem(CharacterFromId("Nathaniel Hawk"), "pistol2");
			ChangeCharacterAddressGroup(CharacterFromID("John Coxon"), "Cayman_Pirate_house_01_inside", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("Gaetan Andrieux"), "Falaise_de_fleur_tavern", "sit", "sit13");
			Characters[GetCharacterIndex("Gaetan Andrieux")].dialog.currentnode = "begin_1";
			break;

		case "davy_video":
			Characters[GetCharacterIndex("Gaetan Andrieux")].dialog.currentnode = "begin_8";
			PostVideoAndQuest("davy",1, "");
			break;

		case "remove_andrieux":
			PChar.quest.remove_andrieux.win_condition.l1 = "Timer";
			PChar.quest.remove_andrieux.win_condition.l1.date.day = GetAddingDataDay(0, 0, 2);
			PChar.quest.remove_andrieux.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2);
			PChar.quest.remove_andrieux.win_condition.l1.date.year = GetAddingDataYear(0, 0, 2);
			PChar.quest.remove_andrieux.win_condition = "remove_andrieux_fim";
			break;

		case "remove_andrieux_fim":
			ChangeCharacterAddressGroup(CharacterFromID("Gaetan Andrieux"), "none", "", "");

			pchar.quest.voir_esteban.win_condition.l1 = "location";
			pchar.quest.voir_esteban.win_condition.l1.location = "Antigua_outskirts";
			pchar.quest.voir_esteban.win_condition = "Ver_Esteban";
			break;

		case "Elting_at_Douwesen":
			GiveShip2Character(CharacterFromID("Elting"),"XebecAS","El Diablo",-1,SPAIN,true,true);
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Douwesen_Tavern", "goto", "goto2");
			LAi_SetCitizenType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.filename = "Elting at Douwesen_dialog.c";
			break;

			// The Aztec treasure

		case "aboard_Morgan_ship":
			Locations[FindLocation("Vera_Cruz_01")].reload.l12.disable = 1;
			DoQuestReloadToLocation("Quest_Cabin2", "reload", "reload1", "aboard_Morgan_shipbis");
			break;

		case "aboard_Morgan_shipbis":
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Cabin2", "rld", "aloc2");
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_27";
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 2.0, 1.0);
			break;

		case "Laisser_Morgan":
			DoQuestReloadToLocation("Redmond_port", "reload", "sea_1_back", "_");

			Pchar.quest.para_vera.win_condition.l1 = "location";
			Pchar.quest.para_vera.win_condition.l1.location = "KhaelRoa";
			PChar.quest.para_vera.win_condition = "arrival_nearveracruz";

			SetQuestHeader("Aztec_Treasure");
			AddQuestRecord("Aztec_Treasure", "1");
			break;

		case "arrival_nearveracruz":
			SetCurrentTime(10, 0);
			SetCharacterShipLocation(Pchar, "Vera_Cruz_Beach");
			DisableFastTravel(true);
			DisableMenuLaunch(true);

			RemovePassenger(pchar, characterFromID("Emilio Soares"));
			RemoveCharacterCompanion(pchar, characterFromID("Emilio Soares"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.filename = "Emilio Soares_dialog.c";

			DoQuestCheckDelay("arrival_nearveracruzbis", 3.0);
			break;

		case "arrival_nearveracruzbis":
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "Vera_Cruz_Beach", "goto", "citizen02");
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_65";
			GiveModel2Player("GypsyCaptn_8",true);
			DoReloadFromSeaToLocation("Vera_Cruz_Beach", "goto", "citizen07");
			LAi_QuestDelay("arrival_nearveracruzbis2", 3.0);
			break;

		case "arrival_nearveracruzbis2":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);
			break;

		case "Bart_VeraCruz":
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Emilio Soares"));
			DoQuestReloadToLocation("Vera_Cruz_Port", "reload", "werf_back","_");
			Characters[GetCharacterIndex("Chago Castaneda")].dialog.currentnode = "begin_36";
			AddQuestRecord("Aztec_Treasure", "2");
			break;

		case "Bart_VeraCruzbis":
			Locations[FindLocation("Vera_Cruz_01")].reload.l12.disable = 0;
			ChangeCharacterAddressGroup(characterFromID("Agilo Casamayor"), "Vera_Cruz_House_1", "goto", "goto1");
			Characters[GetCharacterIndex("Agilo Casamayor")].dialog.currentnode = "begin_1";
			break;

		case "barto_tavern":
			DoQuestReloadToLocation("Vera_Cruz_Tavern", "candles", "sit3","barto_tavernbis");
			break;

		case "barto_tavernbis":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			WaitDate("", 0,0,3,0,0);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Wait_Agilo";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "see_agilo":
			Characters[GetCharacterIndex("Agilo Casamayor")].dialog.currentnode = "begin_14";
			DoQuestReloadToLocation("Vera_Cruz_House_1", "reload", "reload1","_");
			LAi_SetPlayerType(pchar);
			break;

		case "wait_for_agilo":
			pchar.quest.agilo = "paye";
			Characters[GetCharacterIndex("Agilo Casamayor")].dialog.currentnode = "begin_23";
			WaitDate("", 0,0,2,0,0);
			DoQuestReloadToLocation("Vera_Cruz_Tavern", "goto", "goto6","wait_for_agilobis");
			break;

		case "wait_for_agilobis":
			ChangeCharacterAddressGroup(characterFromID("Agilo Casamayor"), "Vera_Cruz_Tavern", "goto", "goto17");
			LAi_SetActorType(characterFromID("Agilo Casamayor"));
			LAi_ActorDialog(characterFromID("Agilo Casamayor"), pchar, "", 2.0, 1.0);
			break;

		case "info_from_agilo":
			Characters[GetCharacterIndex("Agilo Casamayor")].dialog.currentnode = "begin_24";
			DoQuestReloadToLocation("Vera_Cruz_01", "goto", "goto66","info_from_agilobis");
			break;

		case "info_from_agilobis":
			ChangeCharacterAddressGroup(characterFromID("Agilo Casamayor"), "Vera_Cruz_01", "goto", "goto68");
			LAi_SetActorType(characterFromID("Agilo Casamayor"));
			LAi_ActorDialog(characterFromID("Agilo Casamayor"), pchar, "", 3.0, 1.0);
			break;

		case "fleet_emilio":
			pchar.quest.agilo = "payeagain";
			RemovePassenger(pchar, characterFromID("Emilio Soares"));
			RemoveCharacterCompanion(pchar, characterFromID("Emilio Soares"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_68";
			WaitDate("", 0,0,1,0,0);
			DoQuestReloadToLocation("Vera_Cruz_Tavern", "goto", "goto6","fleet_emiliobis");
			break;

		case "fleet_emiliobis":
			SetCharacterShipLocation(CharacterFromID("Spanish Captain2"), "Vera_Cruz_Port");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain3"), "Vera_Cruz_Port");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain1"), "Vera_Cruz_Port");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain4"), "Vera_Cruz_Port");

			ChangeCharacterAddressGroup(characterFromID("Agilo Casamayor"), "Vera_Cruz_House_1", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "Vera_Cruz_Tavern", "goto", "goto17");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);
			break;

		case "fleet_port":
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_69";
			DoQuestReloadToLocation("Vera_Cruz_port", "goto", "goto7","fleet_portbis");
			break;

		case "fleet_portbis":
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "Vera_Cruz_port", "goto", "goto8");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 4.0, 1.0);
			break;

		case "fleet_portbis2":
			WaitDate("", 0,0,1,0,0);
			DoQuestReloadToLocation("Santiago_ship", "rld", "loc6","fleet_portbis3");
			break;

		case "fleet_portbis3":
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_71";
			ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "Santiago_ship", "rld", "aloc4");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 3.0, 1.0);
			break;

		case "confirm_agilo":
			DoQuestReloadToLocation("Vera_Cruz_House_1", "reload", "reload1","confirm_agilobis");
			break;

		case "confirm_agilobis":
			LAi_SetStayType(characterFromID("Agilo Casamayor"));
			Characters[GetCharacterIndex("Agilo Casamayor")].dialog.currentnode = "begin_30";
			break;

		case "barto_tavern_again":
			pchar.quest.agilo = "payeagainbis";
			Locations[FindLocation("Vera_Cruz_Tavern")].vcskip = true;
			DoQuestReloadToLocation("Vera_Cruz_Tavern", "candles", "sit3","barto_tavern_againbis");
			break;

		case "barto_tavern_againbis":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Wait_elting";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "see_elting":
			LAi_Fade("see_elting2", "see_elting21");
			break;

		case "see_elting2":
			Characters[GetCharacterIndex("Elting")].dialog.filename = "Johan Elting_dialog.c";
			SetModelfromArray(characterFromID("Elting"), GetModelIndex("Johan_Elting"));
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorSetSitMode(characterFromID("Elting"));
			ChangeCharacterAddressGroup(characterFromID("Elting"), "Vera_Cruz_Tavern", "sit", "sit4");
			EquipCharacterByItem(characterFromID("Elting"), "Blade_ProudOfAnvil");
			EquipCharacterByItem(characterFromID("Elting"), "pistol2");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_39";
			break;

		case "see_elting21":
			WaitDate("", 0,0,1,0,0);
			SetCurrentTime(5, 0);

			LAi_ActorWaitDialog(CharacterFromID("Elting"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Elting"),"", 10.0, 10.0);
			DeleteAttribute(&Locations[FindLocation("Vera_Cruz_Tavern")],"vcskip");
			break;

		case "enter_forte":
			Locations[FindLocation("Vera Cruz Fort")].reload.l2.disable = 1;
			Locations[FindLocation("VeraCruz_armory")].vcskip = true;
			Locations[FindLocation("Vera Cruz Fort")].vcskip = true;
			Build_at("Vera Cruz Fort", "box", "", 9.4902, 0.4, 5.4684, 0, "Building");
			PostVideoAndQuest("Bartolomeu\Vera Cruz",1, "Vera_fort_enter");
			break;

		case "Vera_fort_enter":
			LAi_SetPlayerType(pchar);
			StoreOfficers(pchar.id);
			DoQuestReloadToLocation("Vera Cruz Fort", "reload", "reloadc5", "Vera_fort_enterbis");
			break;

		case "Vera_fort_enterbis":
			LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, true, "attacarsoldatos");
			TakenItems(Pchar, "pistolpdart", 4);
			EquipCharacterbyItem(Pchar, "pistolpdart");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto7");
			sld.id = "vcfsoldat1";
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetGuardianType(characterFromID("vcfsoldat1"));
			LAi_group_MoveCharacter(sld, "VCFORTE_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto8");
			sld.id = "vcfsoldat2";
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetGuardianType(characterFromID("vcfsoldat2"));
			LAi_group_MoveCharacter(sld, "VCFORTE_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto9");
			sld.id = "vcfsoldat3";
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "rld", "loc9");
			sld.id = "vcfsoldat4";
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetPatrolType(characterFromID("vcfsoldat4"));
			LAi_group_MoveCharacter(sld, "VCFORTE_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "rld", "aloc2");
			sld.id = "vcfsoldat5";
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetPatrolType(characterFromID("vcfsoldat5"));
			LAi_group_MoveCharacter(sld, "VCFORTE_SOLDATS");

			LAi_group_SetRelation("VCFORTE_SOLDATS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			pchar.quest.trouvertrone.win_condition.l1 = "locator";
			pchar.quest.trouvertrone.win_condition.l1.location = "Vera Cruz Fort";
			pchar.quest.trouvertrone.win_condition.l1.locator_group = "rld";
			pchar.quest.trouvertrone.win_condition.l1.locator = "aloc5";
			pchar.quest.trouvertrone.win_condition = "trouvertronebis";
			break;

		case "trouvertronebis":
			pchar.quest.detected_guard.win_condition.l1 = "locator";
			pchar.quest.detected_guard.win_condition.l1.location = "VeraCruz_armory";
			pchar.quest.detected_guard.win_condition.l1.locator_group = "reload";
			pchar.quest.detected_guard.win_condition.l1.locator = "reload2";
			pchar.quest.detected_guard.win_condition = "vera_detection";

			Locations[FindLocation("Vera Cruz Fort")].reload.l2.disable = 0;
			LAi_RemoveCheckMinHP(Pchar);
			LAi_SetImmortal(Pchar, false);
			AddQuestRecord("Aztec_Treasure", "3");
			break;

		case "vera_detection":
			SetCurrentTime(5, 0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto4");
			sld.id = "vcfsoldat6";
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			sld.dialog.filename = "Spaniards_dialog.c";
			sld.dialog.currentnode = "begin_41";
			LAi_SetActorType(characterFromID("vcfsoldat6"));
			LAi_ActorDialog(characterFromID("vcfsoldat6"), pchar, "", 5.0, 1.0);
			break;

		case "attacarsoldatos":
			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
			LAi_group_FightGroups("VCFORTE_SOLDATS", LAI_GROUP_PLAYER, true);
			LAi_RemoveCheckMinHP(Pchar);
			Locations[FindLocation("Vera Cruz Fort")].reload.l2.disable = 1;
			LAi_SetImmortal(Pchar, false);
			LAi_QuestDelay("fuir_vc", 8.0);
			break;

		case "fuir_vc":
			QuestToSeaLogin_PrepareLoc("KhaelRoa", "reload", "reload_1", true);
			QuestToSeaLogin_Launch();
			AddQuestRecord("Aztec_Treasure", "10");
			CloseQuestHeader("Aztec_Treasure");
			break;

		case "plaza_jump":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Vera_Cruz_01", "goto", "goto92");
			LAi_SetImmortal(CharacterFromID("Elting"), true);			
			DoQuestReloadToLocation("Vera_Cruz_01", "goto", "goto107","plaza_jump10");
			break;

		case "plaza_jump10":
			LAi_QuestDelay("plaza_jump2", 4.0);
			break;

		case "plaza_jump2":
			ChangeCharacterAddressGroup(Pchar, "Vera_Cruz_01", "goto", "goto106");
			LAi_SetActorType(Pchar);
			LAi_QuestDelay("plaza_jump2B", 0.5);
			break;

		case "plaza_jump2B":
			ChangeCharacterAddressGroup(Pchar, "Vera_Cruz_01", "goto", "goto105");
			LAi_ActorAnimation(Pchar, "jump", "stop_the_animation3", 1.1);
			break;

		case "stop_the_animation3":
			PlaySound("PEOPLE\jump.wav");
			ChangeCharacterAddressGroup(Pchar, "Vera_Cruz_01", "goto", "goto108");
			LAi_ActorSetLayMode(Pchar);
			LAi_QuestDelay("relever_bart", 1.0);
			break;

		case "relever_bart":
			LAi_ActorAnimation(Pchar, "Ground_StandUp", "relever_bart2", 3.0);
			break;

		case "relever_bart2":
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(CharacterFromID("Elting"));

			LAi_group_FightGroups("VERA_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("VERA_SOLDIERS", "relever_bart3");
			break;

		case "relever_bart3":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_57";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 5.0, 1.0);
			break;

		case "outside_vera":
			LAi_SetImmortal(CharacterFromID("Elting"), false);		
			SetCharacterShipLocation(characterFromID("Elting"), "Vera_Cruz_Beach");
			DoQuestReloadToLocation("Vera_Cruz_Beach", "goto", "locator10","outside_verabis");
			break;

		case "outside_verabis":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Vera_Cruz_Beach", "goto", "citizen07");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_58";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 5.0, 1.0);
			break;

		case "leave_vera":
			GiveShip2Character(characterFromID("Elting"),"XebecAS","El Diablo",-1,SPAIN,true,true);
			PostVideoAndQuest("Assassin\pursuit",1, "chegar_cozumel");
			break;

		case "chegar_cozumel":
			SetCharacterShipLocation(Pchar, "KhaelRoa_port");
			SetCharacterShipLocation(characterFromID("Elting"), "KhaelRoa_port");
			RestoreOfficers(pchar.id);
			DoQuestReloadToLocation("KhaelRoa_port", "goto", "goto3","chegar_cozumelbis");
			break;

		case "chegar_cozumelbis":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "KhaelRoa_port", "goto", "goto2");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_67";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 5.0, 1.0);
			break;

		case "fleet_havana":
			Pchar.quest.flota_havana.win_condition.l1 = "location";
			Pchar.quest.flota_havana.win_condition.l1.location = "Cuba";
			PChar.quest.flota_havana.win_condition = "fleet_havanabis";

			SetCompanionIndex(Pchar, 1, GetCharacterIndex("Elting"));
			SetCharacterRemovable(characterFromID("Elting"), false);
			LAi_ActorFollowEverywhere(characterFromID("Elting"), "", 60.0);

			AddQuestRecord("Aztec_Treasure", "4");
			break;

		case "fleet_havanabis":
			PostVideoAndQuest("Assassin\fleet",1, "news_to_morgan");
			break;

		case "news_to_morgan":
			AddQuestRecord("Aztec_Treasure", "5");
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_residence", "goto", "goto2");
			LAi_SetStayType(characterFromID("Henry Morgan"));
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_34";
			break;

		case "morgan_to_havana":
			Pchar.quest.morgan_havana.win_condition.l1 = "location";
			Pchar.quest.morgan_havana.win_condition.l1.location = "Cuba";
			PChar.quest.morgan_havana.win_condition = "morgan_to_havanabis";

			SetCompanionIndex(Pchar, 2, GetCharacterIndex("Henry Morgan"));
			SetCharacterRemovable(characterFromID("Henry Morgan"), false);
			SetCharacterShipLocation(characterFromID("Henry Morgan"), "redmond_port");

			LAi_SetActorType(characterfromID("Henry Morgan"));
			LAi_ActorRunToLocation(characterfromID("Henry Morgan"), "reload", "reload1", "none", "", "", "", 6.0);
			LAi_ActorFollowEverywhere(characterFromID("Elting"), "", 60.0);

			AddQuestRecord("Aztec_Treasure", "6");
			break;

		case "morgan_to_havanabis":
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Cabin2", "rld", "aloc2");
			LAi_SetStayType(characterFromID("Henry Morgan"));
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_38";
			SetCharacterShipLocation(Pchar, "Cuba_shore_04");
			SetCharacterShipLocation(characterFromID("Elting"), "Cuba_shore_04");
			SetCharacterShipLocation(characterFromID("Henry Morgan"), "Cuba_shore_04");
			DoReloadFromSeaToLocation("Quest_Cabin2", "reload", "reload1");
			break;

		case "Priest_Clothes":
			DoQuestReloadToLocation("Cabin_small", "goto", "goto2", "Priest_Clothesbis");
			break;

		case "Priest_Clothesbis":
			SetCurrentTime(21, 0);
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cabin_small", "goto", "goto3");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_69";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 1.0, 1.0);
			break;

		case "Priest_Clothesbis2":
			StoreOfficers(pchar.id);
			DoQuestReloadToLocation("Cuba_shore_04", "goto", "citizen06", "Priest_Clothesbis3");
			break;

		case "Priest_Clothesbis3":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cuba_shore_04", "goto", "citizen08");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_73";

			SetModelfromArray(&pchar, GetModelIndex("Animistse"));
			SetModelfromArray(characterFromID("Elting"), GetModelIndex("Animists2"));

			GiveItem2Character(Pchar, "Barmansknife");
			EquipCharacterByItem(Pchar, "Barmansknife");
			GiveItem2Character(Pchar, "pistolrock");
			EquipCharacterByItem(Pchar, "pistolrock");
			GiveItem2Character(CharacterFromId("Elting"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Elting"), "bladex4");
			GiveItem2Character(CharacterFromId("Elting"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("Elting"), "pistolrock");

			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "Damski_Havana":
			AddQuestRecord("Aztec_Treasure", "7");
			LAi_ActorFollowEverywhere(characterFromID("Elting"), "", 60.0);
			ChangeCharacterAddressGroup(CharacterFromID("Captain Damski"), "Damski_House", "goto", "goto1");
			locations[FindLocation("Havana_Town_01")].reload.l14.disable = 0;
			Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "begin_13";
			break;

		case "Bart_suggestion":
			LAi_SetStayType(characterFromID("Captain Damski"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_77";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "Bart_suggestionbis":
			Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "begin_21";
			LAi_SetActorType(characterFromID("Captain Damski"));
			LAi_ActorDialog(characterFromID("Captain Damski"), pchar, "", 2.0, 1.0);
			break;

		case "Bart_suggestionbis2":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_79";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "Bart_suggestionbis3":
			SetCurrentTime(10, 0);
			Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "begin_24";
			LAi_SetActorType(characterFromID("Captain Damski"));
			LAi_ActorDialog(characterFromID("Captain Damski"), pchar, "", 2.0, 1.0);
			break;

		case "Villalobos_church":
			LAi_ActorFollowEverywhere(characterFromID("Elting"), "", 60.0);
			WaitDate("", 0,0,1,0,0);
			DoQuestReloadToLocation("Havana_town_02", "goto", "goto46", "Villalobos_churchbis");
			break;

		case "Villalobos_churchbis":
			ChangeCharacterAddressGroup(CharacterFromID("Captain Damski"), "Havana_town_02", "goto", "goto45");
			Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "begin_26";
			LAi_SetActorType(characterFromID("Captain Damski"));
			LAi_ActorDialog(characterFromID("Captain Damski"), pchar, "", 5.0, 1.0);
			break;

		case "Villalobos_churchbis2":
			LAi_SetActorType(characterfromID("Captain Damski"));
			LAi_ActorRunToLocation(characterfromID("Captain Damski"), "reload", "reload10_back", "none", "", "", "", 20.0);

			ChangeCharacterAddressGroup(CharacterFromID("Captain Villalobos"), "Havana_town_02", "goto", "goto47");
			ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat1"), "Havana_town_02", "goto", "goto47");
			ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat2"), "Havana_town_02", "goto", "goto47");

			LAi_SetActorType(CharacterFromID("Captain Villalobos"));
			LAi_ActorGoToLocation(CharacterFromID("Captain Villalobos"), "goto", "goto49", "", "", "", "Villalobos_churchbis3", 55.0);
			LAi_SetActorType(CharacterFromID("Elting"));
			LAi_ActorGoToLocator(CharacterFromID("Elting"), "goto", "goto48", "", 55.0);

			LAi_SetActorType(characterFromID("VillaSoldat1"));
			LAi_ActorFollow(characterFromID("VillaSoldat1"), characterFromID("Captain Villalobos"), "", 60.0);
			LAi_SetActorType(characterFromID("VillaSoldat2"));
			LAi_ActorFollow(characterFromID("VillaSoldat2"), characterFromID("Captain Villalobos"), "", 60.0);
			break;

		case "Villalobos_churchbis3":
			ChangeCharacterAddress(characterFromID("Pries_Havana"), "none", "");
			DoQuestReloadToLocation("Havana_church", "reload", "reload3", "Villalobos_churchbis4");
			break;

		case "Villalobos_churchbis4":
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_church")], false);

			ChangeCharacterAddressGroup(CharacterFromID("Captain Villalobos"), "Havana_church", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat1"), "Havana_church", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat2"), "Havana_church", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Havana_church", "goto", "goto11");

			LAi_SetActorType(characterFromID("Captain Villalobos"));
			LAi_ActorFollow(characterFromID("Captain Villalobos"), characterFromID("Elting"), "", 60.0);

			LAi_QuestDelay("Villalobos_churchbis5", 10.0);
			break;

		case "Villalobos_churchbis5":
			LAi_Fade("Villalobos_churchbis6", "");
			LAi_KillCharacter(characterFromID("Captain Villalobos"));
			ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat2"), "none", "", "");
			break;

		case "Villalobos_churchbis6":
			EquipCharacterByItem(CharacterFromID("Elting"), FindCharacterItemByGroup(CharacterFromID("Elting"), BLADE_ITEM_TYPE));
			EquipCharacterByItem(CharacterFromID("Elting"), FindCharacterItemByGroup(CharacterFromID("Elting"), GUN_ITEM_TYPE));
			EquipCharacterByItem(Pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(Pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));

			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_82";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorWaitDialog(CharacterFromID("Elting"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Elting"), "", 3.0, 1.0);
			break;

		case "villalobos_on_deck":
			LAi_SetPlayerType(pchar);
			LAi_ActorFollowEverywhere(characterFromID("Elting"), "", 60.0);
			DoQuestReloadToLocation("Morgan_ShipDeck", "reload", "boatl", "villalobos_on_deckbis");
			break;

		case "villalobos_on_deckbis":
			SetModelfromArray(characterFromID("Elting"), GetModelIndex("Johan_Elting"));
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_8"));

			ChangeCharacterAddressGroup(CharacterFromID("Captain Villalobos"), "Morgan_ShipDeck", "rld", "loc12");
			SetModelfromArray(characterFromID("Captain Villalobos"), GetModelIndex("Animists1"));
			LAi_SetActorType(characterFromID("Captain Villalobos"));
			LAi_ActorSetLayMode(characterFromID("Captain Villalobos"));
			GiveItem2Character(CharacterFromId("Captain Villalobos"), "bladex4");
			EquipCharacterByItem(CharacterFromId("Captain Villalobos"), "bladex4");

			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Morgan_ShipDeck", "rld", "loc10");
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Morgan_ShipDeck", "rld", "loc13");

			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_40";
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 2.0, 1.0);
			break;

		case "back_for_plan":
			DoQuestReloadToLocation("Quest_Cabin2", "reload", "reload1", "back_for_planbis");
			break;

		case "back_for_planbis":
			ChangeCharacterAddressGroup(CharacterFromID("Pries_Havana"), "Havana_church", "goto", "goto11");
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Cabin2", "rld", "aloc2");
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_43";
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 2.0, 1.0);
			break;

		case "back_for_planbis2":
			LAi_Fade("back_for_planbis3", "");
			break;

		case "back_for_planbis3":
			WaitDate("", 0,0,1,0,0);
			SetCurrentTime(13, 0);
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Cabin2", "rld", "aloc2");
//			ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Quest_Cabin2", "rld", "aloc1");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Quest_Cabin2", "rld", "aloc1");
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_48";
			LAi_SetStayType(CharacterFromID("Henry Morgan"));
			LAi_SetActorType(Pchar);
			LAi_ActorWaitDialog(CharacterFromID("Henry Morgan"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Henry Morgan"),"", 6.0, 1.0);
			break;

		case "ElMorro_video":
			SetNextWeather("Blue Sky");
			SetCurrentTime(1, 0);
			SetCharacterShipLocation(CharacterFromID("Sneak barque"), "Morro_Fort");

			PostVideoAndQuest("Assassin\El Morro",1, "ElMorro_assault");
			break;

		case "ElMorro_assault":
			DoQuestReloadToLocation("Morro_Fort", "goto", "goto31", "ElMorro_assault2");
			break;

		case "ElMorro_assault2":
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_03"), "Morro_Fort", "goto", "goto32");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Morro_Fort", "goto", "goto30");
			LAi_SetActorType(CharacterFromID("Elting"));
			LAi_ActorTurnToCharacter(CharacterFromID("Elting"), characterFromID("Quest_Morro_soldier_11"));
			LAi_QuestDelay("ElMorro_assault3", 3.0);
			break;

		case "ElMorro_assault3":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_02"), "Morro_Fort", "goto", "goto29");
			LAi_SetActorType(CharacterFromID("Elting"));
			LAi_ActorTurnToCharacter(CharacterFromID("Elting"), characterFromID("elting_pirate_02"));
			LAi_SetActorType(CharacterFromID("elting_pirate_02"));
			LAi_ActorRunToLocator(characterFromID("elting_pirate_02"), "goto", "goto47", "ElMorro_assault3b", 10.0);
			break;

		case "ElMorro_assault3b":
			LAi_SetActorType(CharacterFromID("elting_pirate_02"));
			LAi_ActorRunToLocator(characterFromID("elting_pirate_02"), "goto", "goto48", "ElMorro_assault3b2", 10.0);
			break;

		case "ElMorro_assault3b2":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(CharacterFromID("elting_pirate_02"));
			LAi_ActorRunToLocator(characterFromID("elting_pirate_02"), "goto", "goto49", "ElMorro_assault3b3", 10.0);
			break;

		case "ElMorro_assault3b3":
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_11"), "none", "");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_84";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 0.0, 0.0);
			break;

		case "ElMorro_assault6":
			LAi_Fade("ElMorro_assault7", "");
			break;

		case "ElMorro_assault7":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_02"), "Morro_Fort", "goto", "goto33");
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_04"), "Morro_Fort", "goto", "goto50");
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_05"), "Morro_Fort", "goto", "goto51");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_85";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 0.0, 0.0);
			break;

		case "ElMorro_assault7bis":
			DoQuestReloadToLocation("Morro_Fort", "goto", "goto80", "ElMorro_assault7A");
			break;

		case "ElMorro_assault7A":
			ref morrob;
			morrob = &Locations[FindLocation("Morro_Fort")];
			DeleteAttribute(morrob,"building");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto81");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto3");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");

			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Spaniards_Talk";
			LAi_ActorSelfDialog(Pchar, "player_back");
			break;

		case "ElMorro_assault7AB":
			DoQuestReloadToLocation("Morro_Fort", "goto", "goto49", "ElMorro_assault7bis2");
			break;

		case "ElMorro_assault7bis2":
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_03"), "none", "");
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_04"), "none", "");
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_05"), "none", "");
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_07"), "none", "");
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_09"), "none", "");
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_10"), "none", "");

			Build_at("Morro_Fort", "ladder", "", -15.065, 34.671, 32.661, 0.506, "");
			Build_at("Morro_Fort", "ladder", "", -9.33, 34.791, 23.014, 1.377, "");
			Build_at("Morro_Fort", "grapnel", "", -31.308, 34.215, -65.473, -1.595, "");

			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_87";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 1.0, 1.0);
			break;

		case "juntar_elting":
			DoQuestReloadToLocation("Morro_Fort", "goto", "goto57", "juntar_eltingb");
			break;

		case "juntar_eltingb":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_06"), "Morro_Fort", "goto", "goto58");
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_04"), "Morro_Fort", "goto", "goto59");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("elting_pirate_06"));
			LAi_QuestDelay("juntar_eltingb2", 5.0);
			break;

		case "juntar_eltingb2":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Morro_Fort", "goto", "goto56");
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_93";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 1.0, 0.0);
			break;

		case "juntar_eltingc":
			LAi_Fade("juntar_eltingc2", "");
			break;

		case "juntar_eltingc2":
			ChangeCharacterAddressGroup(pchar, "Morro_Fort", "goto", "goto38");
			ChangeCharacterAddressGroup(CharacterFromID("Quest_Morro_soldier_11"), "Morro_Fort", "goto", "goto60");
			LAi_SetActorType(characterFromID("Quest_Morro_soldier_11"));
			LAi_ActorSetLayMode(characterFromID("Quest_Morro_soldier_11"));
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01"), "Morro_Fort", "goto", "goto63");
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_02"), "Morro_Fort", "goto", "goto36");
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_03"), "Morro_Fort", "goto", "goto37");
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_05"), "Morro_Fort", "goto", "goto62");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Morro_Fort", "goto", "goto61");

			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_96";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 1.0, 0.0);
			break;

		case "trepar1":
			ChangeCharacterAddress(characterFromID("elting_pirate_01"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto65");
			LAi_SetActorType(CharacterFromID("elting_pirate_01c"));
			LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_1", "trepar2", 0.0);
			break;

		case "trepar2":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto66");
			LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_2", "trepar3", 0.0);
			break;

		case "trepar3":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto67");
			LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_1", "trepar4", 0.0);
			break;

		case "trepar4":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto68");
			LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_2", "trepar5", 0.0);
			break;

		case "trepar5":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto69");
			LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_1", "trepar6", 0.0);
			break;

		case "trepar6":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto70");
			LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_2", "treparfim", 0.0);
			break;

		case "treparfim":
			ChangeCharacterAddress(characterFromID("elting_pirate_01c"), "none", "");
			LAi_QuestDelay("treparfimb", 1.0);
			break;

		case "treparfimb":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01"), "Morro_Fort", "goto", "goto64");
			LAi_QuestDelay("neartower", 2.0);
			break;

		case "neartower":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto72");
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORT_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto74");
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORT_SOLDATS");

			LAi_Fade("neartowerb", "");
			break;

		case "neartowerb":
			ChangeCharacterAddressGroup(pchar, "Morro_Fort", "goto", "goto73");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Morro_Fort", "goto", "goto71");
			LAi_SetOfficerType(characterFromID("Elting"));
			PlayStereoSound("VOICE\ENGLISH\spa_m_a_008.wav");
			LAi_group_FightGroups("FORT_SOLDATS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FORT_SOLDATS", "neartowerc");
			break;

		case "neartowerc":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_97";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 1.0, 0.0);
			break;

		case "morro_top":
			Locations[FindLocation("Quest_Morro_fort2")].locators_radius.reload.reload1 = 2.0;
			Locations[FindLocation("Quest_Morro_fort2")].locators_radius.reload.reload2 = 2.5;
			Locations[FindLocation("Quest_Morro_fort2")].locators_radius.reload.reload3 = 5.0;

			DoQuestReloadToLocation("Quest_Morro_fort2", "goto", "goto23", "morro_topb");
			break;

		case "morro_topb":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Quest_Morro_fort2", "goto", "goto2");

			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_06"), "Quest_Morro_fort2", "goto", "goto3");
			LAi_SetActorType(CharacterFromID("elting_pirate_06"));
			LAi_ActorAnimation(CharacterFromID("elting_pirate_06"), "afraid", "", 1.0);

			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_04"), "Quest_Morro_fort2", "goto", "goto4");
			LAi_SetActorType(CharacterFromID("elting_pirate_04"));
			LAi_ActorAnimation(CharacterFromID("elting_pirate_04"), "afraid", "", 1.0);

			GiveItem2Character(CharacterFromId("elting_pirate_04"), "bladex4");
			EquipCharacterByItem(CharacterFromId("elting_pirate_04"), "bladex4");
			GiveItem2Character(CharacterFromId("elting_pirate_04"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("elting_pirate_04"), "pistolrock");

			GiveItem2Character(CharacterFromId("elting_pirate_06"), "bladex4");
			EquipCharacterByItem(CharacterFromId("elting_pirate_06"), "bladex4");
			GiveItem2Character(CharacterFromId("elting_pirate_06"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("elting_pirate_06"), "pistolrock");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto10");
			sld.id = "soldatseul";
			LAi_SetHP(sld, 15.0, 15.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetGuardianType(sld);
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto6");
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto7");
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "goto", "goto8");
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "goto", "goto9");
			sld.id = "soldatforbart";
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto5");
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");

			LAi_QuestDelay("morro_topc", 4.0);
			break;

		case "morro_topc":
			LAi_Fade("morro_topc3", "morro_topc2");

			GiveItem2Character(Pchar, "blade5");
			EquipCharacterByItem(Pchar, "blade5");
			GiveItem2Character(Pchar, "pistolrock");
			EquipCharacterByItem(Pchar, "pistolrock");
			break;

		case "morro_topc3":
			ChangeCharacterAddressGroup(Pchar, "Quest_Morro_fort2", "goto", "goto15");
			break;

		case "morro_topc2":
			LAi_group_SetRelation("FORTI_SOLDATS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_99";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 0.0, 0.0);
			break;

		case "morro_topd":
			LAi_SetOfficerType(characterFromID("Elting"));

			pchar.quest.seul_died.win_condition.l1 = "NPC_Death";
			pchar.quest.seul_died.win_condition.l1.character = "soldatseul";
			pchar.quest.seul_died.win_condition = "morro_tope";
			break;

		case "morro_tope":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Quest_Morro_fort2", "reload", "reload1");
			LAi_QuestDelay("morro_topeb", 1.0);
			break;

		case "morro_topeb":
			pchar.quest.rescapesb.win_condition.l1 = "locator";
			pchar.quest.rescapesb.win_condition.l1.location = "Quest_Morro_fort2";
			pchar.quest.rescapesb.win_condition.l1.locator_group = "reload";
			pchar.quest.rescapesb.win_condition.l1.locator = "reload3";
			pchar.quest.rescapesb.win_condition = "morro_topi";

			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_104";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 0.0, 0.0);

			EquipCharacterByItem(Pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(Pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			break;

		case "morro_topg":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_105";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 10.0, 0.0);
			break;

		case "morro_topga":
			LAi_SetOfficerType(characterFromID("Elting"));
			break;

		case "morro_topi":
			PlayStereoSound("VOICE\ENGLISH\spa_m_b_057.wav");
			LAi_QuestDelay("morro_topj", 2.0);
			break;

		case "morro_topj":
			LAi_group_FightGroups("FORTI_SOLDATS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FORTI_SOLDATS", "morro_topk");
			break;

		case "morro_topk":
			LAi_SetActorType(CharacterFromID("elting_pirate_06"));
			LAi_SetStayType(CharacterFromID("elting_pirate_04"));

			Characters[GetCharacterIndex("elting_pirate_06")].dialog.currentnode = "begin_28";
			LAi_SetActorType(characterFromID("elting_pirate_06"));
			LAi_ActorDialog(characterFromID("elting_pirate_06"), pchar, "", 0.0, 0.0);
			break;

		case "morro_topl":
			PlayStereoSound("OBJECTS\ABORDAGE\abordage.wav");
			LAi_QuestDelay("morro_topm", 5.0);
			break;

		case "morro_topm":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_106";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 0.0, 0.0);
			break;

		case "morro_topn":
			DoQuestReloadToLocation("Quest_Morro_fort1", "goto", "goto6", "morro_down");
			break;

		case "morro_down":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Quest_Morro_fort1", "goto", "goto7");
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Morro_fort1", "rld", "aloc4");
			LAi_group_MoveCharacter(CharacterFromID("Henry Morgan"), "MORGAN_PIRATES");
			LAi_SetImmortal(CharacterFromID("Henry Morgan"), true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "rld", "aloc0");
			sld.id = "soldatspain1";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain1"), true);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "rld", "aloc5");
			sld.id = "soldatspain2";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain2"), true);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "rld", "loc4");
			sld.id = "soldatspain3";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain3"), true);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "rld", "loc9");
			sld.id = "soldatspain4";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain4"), true);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "rld", "aloc2");
			sld.id = "soldatspain5";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain5"), true);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat1", "rld", "aloc10");
			sld.id = "morganpirate1";
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("morganpirate1"), true);
			LAi_group_MoveCharacter(sld, "MORGAN_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", "rld", "loc10");
			sld.id = "morganpirate2";
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("morganpirate2"), true);
			LAi_group_MoveCharacter(sld, "MORGAN_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "rld", "loc3");
			sld.id = "morganpirate3";
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("morganpirate3"), true);
			LAi_group_MoveCharacter(sld, "MORGAN_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "rld", "aloc3");
			sld.id = "morganpirate4";
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("morganpirate4"), true);
			LAi_group_MoveCharacter(sld, "MORGAN_PIRATES");

			LAi_group_FightGroups("FORTE_SOLDATS", "MORGAN_PIRATES", true);

			LAi_QuestDelay("morro_down2", 5.0);
			break;

		case "morro_down2":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_107";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 0.0, 0.0);
			break;

		case "morro_down3":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Quest_Morro_fort1", "goto", "goto4");

			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorAnimation(characterFromID("Elting"), "jump", "stop_animationB", 1.8);
			LAi_QuestDelay("morro_down4", 1.2);
			break;

		case "morro_down4":
			PlaySound("PEOPLE\jump.wav");
			LAi_QuestDelay("morro_down5", 1.0);
			break;

		case "morro_down5":
			LAi_Fade("morro_down6", "");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "rld", "loc0");
			sld.id = "soldatspain6";
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTEB_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "rld", "aloc9");
			sld.id = "soldatspain7";
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTEB_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "rld", "aloc6");
			LAi_SetHP(sld, 80.0, 80.0);
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			break;

		case "morro_down6":
			ChangeCharacterAddressGroup(Pchar, "Quest_Morro_fort1", "goto", "goto1");
			LAi_SetActorType(Pchar);
			LAi_ActorAnimation(pchar, "jump", "stop_animation", 1.8);
			LAi_QuestDelay("morro_down7", 1.2);
			break;

		case "morro_down7":
			PlaySound("PEOPLE\jump.wav");
			break;

		case "stop_animation":
			Lai_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Elting"));
			LAi_group_FightGroups("FORTEB_SOLDATS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FORTEB_SOLDATS", "morro_down8");
			break;

		case "stop_animationB":
			Lai_SetStayType(characterFromID("Elting"));
			break;

		case "morro_down8":
			LAi_SetImmortal(CharacterFromID("morganpirate4"), false);
			LAi_SetImmortal(CharacterFromID("morganpirate3"), false);
			LAi_SetImmortal(CharacterFromID("morganpirate2"), false);
			LAi_SetImmortal(CharacterFromID("morganpirate1"), false);

			LAi_SetImmortal(CharacterFromID("soldatspain5"), false);
			LAi_SetImmortal(CharacterFromID("soldatspain4"), false);
			LAi_SetImmortal(CharacterFromID("soldatspain3"), false);
			LAi_SetImmortal(CharacterFromID("soldatspain2"), false);
			LAi_SetImmortal(CharacterFromID("soldatspain1"), false);

			LAi_group_SetCheck("FORTE_SOLDATS", "morro_down9");
			break;

		case "morro_down9":
			DoQuestReloadToLocation("Quest_Morro_fort1", "goto", "goto11", "morro_down10");
			break;

		case "morro_down10":
			ChangeCharacterAddressGroup(CharacterFromID("Capitan Caceres"), "Quest_Morro_fort1", "rld", "loc10");
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Morro_fort1", "goto", "goto8");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Quest_Morro_fort1", "rld", "aloc4");
			LAi_SetActorType(CharacterFromID("Elting"));
			LAi_ActorTurnToCharacter(CharacterFromID("Elting"), characterFromID("Capitan Caceres"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "goto9");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "goto10");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);

			Characters[GetCharacterIndex("Capitan Caceres")].dialog.currentnode = "begin_29";
			LAi_SetActorType(characterFromID("Capitan Caceres"));
			LAi_ActorDialog(characterFromID("Capitan Caceres"), pchar, "", 0.5, 0.0);
			break;

		case "morro_down11":
			LAi_SetWarriorType(characterfromID("Capitan Caceres"));
			LAi_SetWarriorType(characterFromID("Elting"));

			LAi_group_MoveCharacter(characterFromID("Capitan Caceres"), "ELTING_ENEMY");
			LAi_group_MoveCharacter(characterFromID("Elting"), LAI_GROUP_PLAYER);

			LAi_SetImmortal(CharacterFromID("Elting"), true);

			LAi_group_SetCheck("ELTING_ENEMY", "morro_down12");
			LAi_group_FightGroups("ELTING_ENEMY", LAI_GROUP_PLAYER, true);
			break;

		case "morro_down12":
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Morro_fort1", "rld", "aloc3");
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_53";
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 3.0, 0.0);
			break;

		case "morro_entrepot":
			Locations[FindLocation("Morro_warehouse")].locators_radius.goto.goto7 = 3.0;
			DoQuestReloadToLocation("Morro_warehouse", "reload", "reload1", "morro_entrepot2");
			break;

		case "morro_entrepot2":
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Morro_warehouse", "goto", "goto5");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Morro_warehouse", "goto", "goto9");
			LAi_SetOfficerType(characterFromID("Henry Morgan"));
			LAi_SetOfficerType(characterFromID("Elting"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto7");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto6");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto2");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto3");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto8");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");

			LAi_group_FightGroups("WAREINSIDE_SOLDADOS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("WAREINSIDE_SOLDADOS", "morro_entrepot3");
			break;

		case "morro_entrepot3":
			pchar.quest.ver_trone.win_condition.l1 = "locator";
			pchar.quest.ver_trone.win_condition.l1.location = "Morro_warehouse";
			pchar.quest.ver_trone.win_condition.l1.locator_group = "goto";
			pchar.quest.ver_trone.win_condition.l1.locator = "goto7";
			pchar.quest.ver_trone.win_condition = "morro_entrepot5";

			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_54";
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 0.0, 0.0);
			break;

		case "morro_entrepot4":
			LAi_SetOfficerType(characterFromID("Elting"));
			LAi_ActorGoToLocator(characterFromID("Henry Morgan"), "goto", "goto10", "_", 18.0);
			break;

		case "morro_entrepot5":
			Build_at("Morro_Fort", "box", "", -10.675, 1.9298, -419.53, 1.5, "Building");
			Build_at("Morro_Fort", "box", "", -15.121, 1.5015, -418.98, 1.5, "Building");
			Build_at("Morro_Fort", "box", "", -16.949, 1.5398, -426.9, 1.5, "Building");
			Build_at("Morro_Fort", "jungle", "", 92.747, 7.1396, -437.42, -1.2798, "Building");
			Build_at("Morro_Fort", "shipyard", "", -28.739, 1.0908, -446, -0.77, "Building");
			Build_at("Morro_Fort", "barracks", "", -10.054, 1.427, -396.47, -1.6468, "Building");

			SetCharacterShipLocation(CharacterFromID("Sneak barque"), "Morro_Fort");
			SetCharacterShipLocation(CharacterFromID("Sneak barque2"), "Morro_Fort");

			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_55";
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 0.0, 0.0);
			break;

		case "morro_beach":
			DoQuestReloadToLocation("Morro_Fort", "goto", "goto77", "morro_beach2");
			break;

		case "morro_beach2":
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Morro_Fort", "goto", "goto76");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Morro_Fort", "goto", "goto75");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "goto78");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "goto79");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");
			LAi_SetHP(sld, 80.0, 80.0);

			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_57";
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 0.0, 0.0);
			break;

		case "leave_morro":
			Pchar.quest.allerpr.win_condition.l1 = "location";
			Pchar.quest.allerpr.win_condition.l1.location = "Redmond";
			PChar.quest.allerpr.win_condition = "reach_PortRoyal";

			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_9", true);
			QuestToSeaLogin_Launch();
			LAi_SetImmortal(CharacterFromID("Elting"), false);
			AddQuestRecord("Aztec_Treasure", "8");
			break;

		case "reach_PortRoyal":
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.currentnode = "gov_1";
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_Residence", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Redmond_Residence", "goto", "goto10");
			DoReloadFromSeaToLocation("Redmond_Residence", "reload", "reload1");
			break;

		case "Morro_loot":
			DoQuestReloadToLocation("Redmond_store", "goto", "goto4", "Morro_loot2");
			break;

		case "Morro_loot2":
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_store", "goto", "goto5");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Redmond_store", "goto", "goto2");
			LAi_SetStayType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_58";
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 1.0, 0.0);
			break;

		case "Morro_loot3":
			DoQuestReloadToLocation("Redmond_Town_01", "goto", "goto18", "Morro_loot4");
			break;

		case "Morro_loot4":
			SetCharacterShipLocation(Pchar, "redmond_port");
			RestoreOfficers(pchar.id);
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_Town_01", "goto", "goto10");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Redmond_Town_01", "reload", "door_5");
			Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_65";
			LAi_SetOfficerType(characterFromID("Elting"));
			LAi_SetActorType(characterFromID("Henry Morgan"));
			LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 2.0, 0.0);
			break;

		case "Morro_loot5":
			LAi_SetActorType(characterfromID("Henry Morgan"));
			LAi_ActorRunToLocation(characterfromID("Henry Morgan"), "reload", "reload_1_3", "none", "", "", "", 10.0);
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_108";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 1.0, 0.0);
			break;

		case "Morro_loot6":
			Pchar.quest.emiliotortue.win_condition.l1 = "location";
			Pchar.quest.emiliotortue.win_condition.l1.location = "Tortuga_port";
			PChar.quest.emiliotortue.win_condition = "mutin";

			RemoveCharacterCompanion(Pchar, characterFromID("Henry Morgan"));
			setCharacterShipLocation(characterFromID("Henry Morgan"), "none");
			RemoveCharacterCompanion(Pchar, characterFromID("Elting"));
			setCharacterShipLocation(characterFromID("Elting"), "none");

			ChangeRMRelation(pchar, SPAIN, -20.0);
			AddQuestRecord("Aztec_Treasure", "9");
			CloseQuestHeader("Aztec_Treasure");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }

			AddPassenger(Pchar, characterFromID("Emilio Soares"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Emilio Soares"));
			LAi_SetActorType(characterfromID("Elting"));
			LAi_ActorRunToLocation(characterfromID("Elting"), "reload", "reload_2_4", "none", "", "", "", 15.0);
			break;

			// Cartagena Quest

		case "mutin":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_73";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);
			break;

		case "voir_gauthier":
			ChangeCharacterAddressGroup(CharacterFromID("Gauthier Thomassin"), "Cabin_medium", "rld", "aloc0");
			DoQuestReloadToLocation("Cabin_medium", "goto", "goto2", "voir_gauthierbis");
			break;

		case "voir_gauthierbis":
			RemovePassenger(pchar, characterFromID("Emilio Soares"));
			RemoveCharacterCompanion(pchar, characterFromID("Emilio Soares"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Emilio Soares"));
			SetCurrentTime(23, 0);

			LAi_SetActorType(characterFromID("Gauthier Thomassin"));
			Characters[GetCharacterIndex("Gauthier Thomassin")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Gauthier Thomassin"), pchar, "", 2.0, 1.0);
			break;

		case "voir_gauthierbis2":
			DoQuestReloadToLocation("Cabin_medium", "sit", "sit4", "voir_gauthierbis3");
			break;

		case "voir_gauthierbis3":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(CharacterFromID("Gauthier Thomassin"), "Cabin_medium", "goto", "goto2");
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Assommer";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "assommer_bart":
			bSuppressResurrection = true;
			LAi_SetActorType(characterFromID("Gauthier Thomassin"));
			LAi_ActorAnimation(characterFromID("Gauthier Thomassin"), "attack_fast_2", "assommer_bart2", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
			break;

		case "assommer_bart2":
			SetCurrentTime(11, 0);
			Lai_KillCharacter(pchar);
			LAi_QuestDelay("assommer_bart3", 2.0);
			break;

		case "assommer_bart3":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			WaitDate("", 0,0,1,0,0);
			EquipCharacterByItem(pchar, "bladeX4");

			DoQuestReloadToLocation("Santiago_ship", "rld", "aloc6", "assommer_bart4");
			break;

		case "assommer_bart4":
			PostVideoAndQuest("Bartolomeu\Ilot",1, "assommer_bart41");
			break;

		case "assommer_bart41":
			SetCharacterShipLocation(Pchar, "Ilot");
			pchar.sailaway = true;
			LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(CharacterFromID("Gauthier Thomassin"), "Santiago_ship", "rld", "loc6");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor5", "goto", "goto3");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor4", "rld", "loc0");
			GiveItem2Character(sld,"blade10");
			EquipCharacterByItem(sld,"blade10");

			LAi_SetActorType(characterFromID("Gauthier Thomassin"));
			Characters[GetCharacterIndex("Gauthier Thomassin")].dialog.currentnode = "begin_8";
			LAi_ActorDialog(characterFromID("Gauthier Thomassin"), pchar, "", 2.0, 1.0);
			break;

		case "abandon_ilot":
			DisableFastTravel(true);
			DisableMenuLaunch(true);

			DoQuestReloadToLocation("Ilot", "goto", "citizen01", "abandon_ilotbis");
			break;

		case "abandon_ilotbis":
			SetNextWeather("Blue Sky");
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "abandonar_bart";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "abandon_ilotbis2":
			LAi_SetPlayerType(pchar);
			LAi_QuestDelay("abandon_ilotbis2A", 3.0);
			break;

		case "abandon_ilotbis2A":
			SetCharacterShipLocation(Pchar, "none");
			WaitDate("", 0,0,1,0,0);
			DoQuestReloadToLocation("Ilot", "goto", "citizen04", "abandon_ilotbis21");
			break;

		case "abandon_ilotbis21":
			DeleteAttribute(pchar, "sailaway");
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "abandonar_bart2";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "abandon_ilotbis3":
			pchar.vole.ship.type   = pchar.ship.type;
			pchar.vole.ship.name   = pchar.ship.name;
			LAi_Fade("abandon_ilotbis31", "abandon_ilotbis32");
			break;

		case "abandon_ilotbis31":
			ChangeCharacterAddressGroup(Pchar, "Ilot", "goto", "citizen06");
			break;

		case "abandon_ilotbis32":
			SetNextWeather("Day storm");
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "abandonar_bart3";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "abandon_ilotbis4":
			DoQuestReloadToLocation("Ilot", "goto", "citizen03", "abandon_ilotbis41");
			break;

		case "abandon_ilotbis41":
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "abandonar_bart4";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "abandon_ilotbis5":
			SetNextWeather("Blue Sky");
			WaitDate("", 0,0,3,0,0);
			DoQuestReloadToLocation("Ilot", "goto", "citizen09", "abandon_ilotbis51");
			break;

		case "abandon_ilotbis51":
			Log_SetStringToLog(TranslateString("","A few days later") + ".");
			GiveModel2Player("GypsyCaptn_9", true);
			LAi_ActorAnimation(Pchar, "Ground_StandUp", "abandon_ilotbis6", 3.0);
			break;

		case "abandon_ilotbis6":
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "abandonar_bart5";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "abandon_ilotbis61":
			LAi_SetPlayerType(pchar);

			pchar.quest.daggerperdue.win_condition.l1 = "locator";
			pchar.quest.daggerperdue.win_condition.l1.location = "Ilot";
			pchar.quest.daggerperdue.win_condition.l1.locator_group = "goto";
			pchar.quest.daggerperdue.win_condition.l1.locator = "citizen08";
			pchar.quest.daggerperdue.win_condition = "abandon_ilotbis7";
			break;

		case "abandon_ilotbis7":
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "abandonar_bart6";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "abandon_ilotbis71":
			SetCharacterShipLocation(CharacterFromID("Lorenzo Escartin"), "Ilot");
			LAi_SetPlayerType(pchar);
			GiveItem2Character(Pchar, "Merchantsdagger");
			LAi_QuestDelay("abandon_ilotbis8", 3.0);
			break;

		case "abandon_ilotbis8":
			DoQuestReloadToLocation("Ilot", "goto", "citizen012", "abandon_ilotbis81");
			break;

		case "abandon_ilotbis81":
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "abandonar_bart7";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "abandon_ilotbis9":
			DoQuestReloadToLocation("Ilot", "goto", "citizen011", "abandon_ilotbis91");
			break;

		case "abandon_ilotbis91":
			LAi_SetPlayerType(pchar);
			EquipCharacterByItem(Pchar,"Merchantsdagger");
			ChangeCharacterAddressGroup(CharacterFromID("Lorenzo Escartin"), "Ilot", "goto", "citizen09");
			ChangeCharacterAddressGroup(CharacterFromID("Guillermo Flores"), "Ilot", "goto", "citizen07");
			ChangeCharacterAddressGroup(CharacterFromID("Raimundo Huertas"), "Ilot", "goto", "citizen010");
			Characters[GetCharacterIndex("Lorenzo Escartin")].dialog.currentnode = "begin_1";
			LAi_SetActorType(characterFromID("Lorenzo Escartin"));
			LAi_ActorDialog(characterFromID("Lorenzo Escartin"), pchar, "", 2.0, 1.0);
			break;

		case "abandon_ilotbis92":
			ChangeCharacterAddressGroup(CharacterFromID("Lorenzo Escartin"), "none", "", "");
			LAi_group_FightGroups("CONTREBANDE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("CONTREBANDE", "abandon_ilotbis93");
			break;

		case "abandon_ilotbis93":
			GiveShip2Character(pchar,"BarqueHeavy","Santa Maria",-1,SPAIN,true,true);
			LAi_QuestDelay("abandon_ilotbis94", 3.0);
			break;

		case "abandon_ilotbis94":
			GiveShip2Character(CharacterFromID("Gauthier Thomassin"),pchar.vole.ship.type,pchar.vole.ship.name,-1,PIRATE,true,true);
			DeleteAttribute(pchar,"vole");
			bSuppressResurrection = false;
			DoQuestReloadToLocation("Ilot", "goto", "citizen02", "abandon_ilotbis95");
			break;

		case "abandon_ilotbis95":
			SetNextWeather("Blue Sky");
			SetCharacterShipLocation(Pchar, "Turks_shore_01");
			ChangeCharacterAddressGroup(CharacterFromID("Guillermo Flores"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Raimundo Huertas"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Lorenzo Escartin"), "Ilot", "goto", "citizen05");
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_8"));
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			Characters[GetCharacterIndex("Lorenzo Escartin")].dialog.currentnode = "begin_9";
			LAi_SetActorType(characterFromID("Lorenzo Escartin"));
			LAi_ActorDialog(characterFromID("Lorenzo Escartin"), pchar, "", 1.0, 1.0);
			break;

		case "abandon_ilotbis96":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			DoQuestReloadToLocation("Turks_shore_01", "goto", "goto8", "abandon_ilotbis97");
			break;

		case "abandon_ilotbis97":
			ChangeCharacterAddressGroup(CharacterFromID("Lorenzo Escartin"), "Turks_shore_01", "goto", "goto7");
			Characters[GetCharacterIndex("Lorenzo Escartin")].dialog.currentnode = "begin_11";
			LAi_SetActorType(characterFromID("Lorenzo Escartin"));
			LAi_ActorDialog(characterFromID("Lorenzo Escartin"), pchar, "", 1.0, 1.0);
			break;

		case "abandon_ilotbis98":
			SetQuestHeader("Firework");
			AddQuestRecord("Firework", "1");
			ChangeCharacterAddressGroup(CharacterFromID("Lorenzo Escartin"), "none", "", "");

			Pchar.quest.find_santiago.win_condition.l1 = "location";
			Pchar.quest.find_santiago.win_condition.l1.location = "Redmond";
			PChar.quest.find_santiago.win_condition = "retrouve_thomassin";

			break;

		case "retrouve_thomassin":
			Group_CreateGroup("treasure_ship");
			Group_AddCharacter("treasure_ship", "Capitaine_Anglais");
			Group_SetGroupCommander("treasure_ship", "Capitaine_Anglais");
			Group_SetPursuitGroup("treasure_ship", PLAYER_GROUP);
			Group_SetTaskAttack("treasure_ship", "Gauthier Thomassin", true);
			Group_LockTask("treasure_ship");
			characters[GetCharacterIndex("Capitaine_Anglais")].nosurrender = 2;
			Group_SetAddress("treasure_ship", "Redmond", "Quest_ships","quest_ship_8");

			Group_CreateGroup("Thomassin_Ship");
			Group_AddCharacter("Thomassin_Ship", "Gauthier Thomassin");
			Group_SetGroupCommander("Thomassin_Ship", "Gauthier Thomassin");
			Group_SetPursuitGroup("Thomassin_Ship", PLAYER_GROUP);
			Group_SetTaskAttack("Thomassin_Ship", "Capitaine_Anglais", true);
			Group_LockTask("Thomassin_Ship");
			characters[GetCharacterIndex("Gauthier Thomassin")].nosurrender = 2;
			Group_SetAddress("Thomassin_Ship", "Redmond", "Quest_ships","quest_ship_8");
			UpdateRelations();

			DoQuestCheckDelay("findusantiago", 3.0);
			break;

		case "findusantiago":
			Ship_Detonate(characterFromID("Gauthier Thomassin"), true, true);
			Pchar.quest.seeemilio.win_condition.l1 = "location";
			Pchar.quest.seeemilio.win_condition.l1.location = "Redmond_Port";
			PChar.quest.seeemilio.win_condition = "retrouve_emilio";
			break;

		case "retrouve_emilio":
			Group_SetAddressNone("treasure_ship");
			PlaceCharacter(characterFromID("Emilio Soares"), "goto");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_79";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 5.0, 1.0);
			break;

		case "voir_jacinto":
			AddQuestRecord("Firework", "2");
			SetNationRelationBoth(HOLLAND, PORTUGAL, RELATION_FRIEND);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Emilio Soares"));
			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Jacinto Arcibaldo Barreto")].dialog.currentnode = "gov_47";
			break;

		case "recevoir_lettre":
			ChangeCharacterAddressGroup(characterFromID("Duarte Felgueiras"), "Conceicao_port", "goto", "goto11");
			DoQuestReloadToLocation("Conceicao_port", "reload", "reload2", "recevoir_lettrebis");
			break;

		case "recevoir_lettrebis":
			Characters[GetCharacterIndex("Duarte Felgueiras")].dialog.currentnode = "begin_4";
			LAi_SetActorType(characterFromID("Duarte Felgueiras"));
			LAi_ActorDialog(characterFromID("Duarte Felgueiras"), pchar, "", 3.0, 1.0);
			break;

		case "recevoir_lettrebis2":
			GiveItem2Character(Pchar, "Letter_Governor");
			LAi_ActorRunToLocation(characterfromID("Duarte Felgueiras"), "reload", "reload1", "none", "", "", "", 5.0);

			Pchar.quest.seeelting.win_condition.l1 = "location";
			Pchar.quest.seeelting.win_condition.l1.location = "Douwesen_Port";
			PChar.quest.seeelting.win_condition = "retrouve_elting";

			AddQuestRecord("Firework", "3");
			break;

		case "retrouve_elting":
			PlaceCharacter(characterFromID("Elting"), "goto");
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_111";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 6.0, 1.0);
			break;

		case "Elting_Townhall":
			DoQuestReloadToLocation("Douwesen_townhall", "reload", "reload1", "Elting_Townhallbis");
			break;

		case "Elting_Townhallbis":
			ChangeCharacterAddressGroup(characterFromID("Elting"), "Douwesen_townhall", "goto", "goto8");
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_115";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 3.0, 1.0);
			SetRMRelation(PChar, HOLLAND, REL_AMNESTY);
			break;

		case "Elting_Townhallbis2":
			Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.currentnode = "gov_1";
			break;

		case "dehors_townhall":
			DoQuestReloadToLocation("Douwesen_town", "reload", "reload15", "Elting_OutsideTownhall");
			break;

		case "Elting_OutsideTownhall":
			ChangeCharacterAddressGroup(characterFromID("Elting"), "Douwesen_town", "goto", "goto30");
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_116";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 3.0, 1.0);
			break;

		case "retour_grenade":
			AddQuestRecord("Firework", "4");
			Characters[GetCharacterIndex("Jacinto Arcibaldo Barreto")].dialog.currentnode = "gov_58";
			LAi_ActorFollowEverywhere(characterFromID("Elting"), "", 60.0);
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Elting"));
			SetCharacterRemovable(characterFromID("Elting"), false);
			break;

		case "retrouve_queiroz":
			GiveShip2Character(pchar,"Galeon50","Reina Isabella",-1,SPAIN,true,true);
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Conceicao_Port", "reload", "reload2");
			LAi_SetStayType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_10";
			SetCharacterShipLocation(Pchar, "Conceicao_Port");
			DeleteAttribute(pchar, "sailaway");
			break;

		case "aller_cartagena":
			AddQuestRecord("Firework", "5");
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "none", "", "");
			GiveShip2Character(CharacterFromID("Spanish Captain1"),"SP_Derfflinger","Sirena",-1,SPAIN,true,true);
			GiveShip2Character(CharacterFromID("Spanish Captain2"),"SP_BattleGalleon","San Martin",-1,SPAIN,true,true);
			GiveShip2Character(CharacterFromID("Spanish Captain3"),"SP_Pinnace50","Galicia",-1,SPAIN,true,true);

			SetCharacterShipLocation(CharacterFromID("Spanish Captain1"), "Cartagena_Port");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain2"), "Cartagena_Port");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain3"), "Cartagena_Port");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain4"), "Cartagena_Port");

			Pchar.quest.arriver_cartagenaport.win_condition.l1 = "location";
			Pchar.quest.arriver_cartagenaport.win_condition.l1.location = "Cartagena_Port";
			PChar.quest.arriver_cartagenaport.win_condition = "aller_cartagenaport";
			break;

		case "aller_cartagenaport":
			StoreOfficers(pchar.id);
			GiveModel2Player("GypsyCaptn_10", true);
			ChangeCharacterAddressGroup(CharacterFromID("Gregorio Montavez"), "Cartagena_Port", "goto", "character4");
			LAi_SetActorType(characterFromID("Gregorio Montavez"));
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Gregorio Montavez"), pchar, "", 10.0, 1.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "goto", "goto10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "Governor_soldado";
			LAi_SetActorType(characterFromID("Governor_soldado"));
			LAi_ActorFollow(characterFromID("Governor_soldado"), characterFromID("Gregorio Montavez"), "", 15.0);
			break;

		case "aller_cartagenaportbis":
			DoQuestReloadToLocation("Cabin2", "reload", "reload1" ,"aller_bateau");
			break;

		case "aller_bateau":
			ChangeCharacterAddressGroup(CharacterFromID("Gregorio Montavez"), "Cartagena_Townhall", "goto", "goto8");
			LAi_SetHuberStayType(characterFromID("Gregorio Montavez"));
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cabin2", "rld", "loc6");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cabin2", "rld", "aloc3");
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_15";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 3.0, 1.0);
			break;

		case "aller_bateau2":
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_120";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 3.0, 1.0);
			break;

		case "aller_residence":
			ChangeCharacterAddressGroup(CharacterFromID("Lucia Montavez"), "Cartagena_townhall", "goto", "goto10");
			DoQuestReloadToLocation("Cartagena_townhall", "reload", "reload1" ,"aller_residence2");
			break;

		case "aller_residence2":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "monk", "goto", "goto9");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "bartpirate_dialog.c";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "hub_spa3", "goto", "goto7");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "bartpirate_dialog.c";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "hub_spa4", "goto", "goto2");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "bartpirate_dialog.c";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Huber_Spa2_17", "goto", "goto6");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "bartpirate_dialog.c";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Huber_Spa4_17", "goto", "goto1");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "bartpirate_dialog.c";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man10", "goto", "goto4");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "bartpirate_dialog.c";

			LAi_SetActorType(characterFromID("Gregorio Montavez"));
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_9";
			LAi_ActorDialog(characterFromID("Gregorio Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "aller_residence3":
			LAi_SetHuberStayType(characterFromID("Gregorio Montavez"));
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_10";
			break;

		case "aller_residence4":
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_11";
			LAi_Fade("aller_residence5", "aller_residence6");
			break;

		case "aller_residence5":
			LAi_SetActorType(characterFromID("Gregorio Montavez"));
			break;

		case "aller_residence6":
			LAi_ActorDialog(characterFromID("Gregorio Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "aller_residence7":
			LAi_SetHuberStayType(characterFromID("Gregorio Montavez"));
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Lucia Montavez"));
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "ver_lucia";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "aller_residence8":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Lucia Montavez")].dialog.currentnode = "begin_1";
			break;

		case "aller_residence9":
			LAi_Fade("aller_residence10", "aller_residence11");
			break;

		case "aller_residence10":
			LAi_SetActorType(characterFromID("Lucia Montavez"));
			Characters[GetCharacterIndex("Lucia Montavez")].dialog.currentnode = "begin_6";
			break;

		case "aller_residence11":
			LAi_ActorDialog(characterFromID("Lucia Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "visit_cartagena":
			DoQuestReloadToLocation("Cartagena_townhall", "reload", "reload2" ,"visit_cartagena2");
			ChangeCharacterAddressGroup(CharacterFromID("Gregorio Montavez"), "Cartagena_townhall", "goto", "goto5");
			break;

		case "visit_cartagena2":
			WaitDate("", 0,0,1,0,0);
			SetCurrentTime(9, 0);
			LAi_SetActorType(characterFromID("Gregorio Montavez"));
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_13";
			LAi_ActorDialog(characterFromID("Gregorio Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "aller_fort":
			SetNextWeather("Blue Sky");
			SetCurrentTime(10, 0);
			DoQuestReloadToLocation("Cartagena_fort", "goto", "goto1" ,"aller_fort12");
			break;

		case "aller_fort12":
			ChangeCharacterAddressGroup(CharacterFromID("Gregorio Montavez"), "Cartagena_fort", "goto", "goto2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto22");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto23");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);

			LAi_SetActorType(Pchar);
			LAi_ActorTurnByLocator( pchar, "goto", "goto18");
			LAi_QuestDelay("aller_fort2", 2.0);
			break;

		case "aller_fort2":
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterFromID("Gregorio Montavez"));
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Gregorio Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "aller_top":
			DoQuestReloadToLocation("Cartagena_fort", "goto", "goto21" ,"aller_top2");
			break;

		case "aller_top2":
			ChangeCharacterAddressGroup(CharacterFromID("Gregorio Montavez"), "Cartagena_fort", "goto", "goto4");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto24");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto25");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);

			LAi_QuestDelay("aller_top3", 2.0);
			break;

		case "aller_top3":
			LAi_SetActorType(characterFromID("Gregorio Montavez"));
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_26";
			LAi_ActorDialog(characterFromID("Gregorio Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "aller_top4":
			LAi_ActorGoToLocator(characterFromID("Gregorio Montavez"), "goto", "goto20", "aller_top5", 8.0);
			break;

		case "aller_top5":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto19", "aller_top6", 8.0);
			break;

		case "aller_top6":
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterFromID("Gregorio Montavez"));
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_28";
			LAi_ActorDialog(characterFromID("Gregorio Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "rejoin_elting":
			DoQuestReloadToLocation("Cabin2", "reload", "reload1" ,"rejoin_elting2");
			break;

		case "rejoin_elting2":
			ChangeCharacterAddressGroup(CharacterFromID("Gregorio Montavez"), "Cartagena_Townhall", "goto", "goto8");
			LAi_SetHuberStayType(characterFromID("Gregorio Montavez"));
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cabin2", "rld", "loc6");
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cabin2", "rld", "aloc3");
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_121";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 3.0, 1.0);
			break;

		case "aller_portcart":
			LAi_Fade("aller_portcart11", "aller_portcart12");
			break;

		case "aller_portcart11":
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_122";
			break;

		case "aller_portcart12":
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 1.0, 1.0);
			break;

		case "aller_portcart2":
			DoQuestReloadToLocation("Cartagena_port", "goto", "goto14" ,"aller_portcart3");
			break;

		case "aller_portcart3":
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "ver_new_santiago";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "aller_residence12":
			AddQuestRecord("Firework", "6");
			LAi_SetPlayerType(pchar);
			Locations[FindLocation("Residence_Cartagena")].locators_radius.rld.aloc6 = 3.0;
			ChangeCharacterAddressGroup(CharacterFromID("Lucia Montavez"), "Residence_Cartagena", "goto", "goto30");
			ChangeCharacterAddressGroup(CharacterFromID("Sebastian Ortega"), "Residence_Cartagena", "goto", "goto31");

			pchar.quest.dispute.win_condition.l1 = "locator";
			pchar.quest.dispute.win_condition.l1.location = "Residence_Cartagena";
			pchar.quest.dispute.win_condition.l1.locator_group = "rld";
			pchar.quest.dispute.win_condition.l1.locator = "aloc6";
			pchar.quest.dispute.win_condition = "dispute_lucia";
			break;

		case "dispute_lucia":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Lucia Montavez"));
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "lucia_garden";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "dispute_lucia2":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Lucia Montavez")].dialog.currentnode = "begin_9";
			LAi_SetStayType(characterFromID("Lucia Montavez"));
			break;

		case "dispute_lucia3":
			LAi_SetActorType(characterFromID("Sebastian Ortega"));
			Characters[GetCharacterIndex("Sebastian Ortega")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Sebastian Ortega"), pchar, "", 1.0, 1.0);
			break;

		case "dispute_lucia4":
			LAi_SetActorType(characterFromID("Lucia Montavez"));
			Characters[GetCharacterIndex("Lucia Montavez")].dialog.currentnode = "begin_10";
			LAi_ActorDialog(characterFromID("Lucia Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "dispute_lucia5":
			LAi_SetActorType(characterFromID("Sebastian Ortega"));
			Characters[GetCharacterIndex("Sebastian Ortega")].dialog.currentnode = "begin_2";
			LAi_ActorDialog(characterFromID("Sebastian Ortega"), pchar, "", 1.0, 1.0);
			break;

		case "dispute_lucia6":
			LAi_ActorGoToLocation(characterFromID("Sebastian Ortega"), "reload", "gate", "none", "", "", "", 8.0);
			LAi_SetActorType(characterFromID("Lucia Montavez"));
			Characters[GetCharacterIndex("Lucia Montavez")].dialog.currentnode = "begin_11";
			LAi_ActorDialog(characterFromID("Lucia Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "fin_dispute_lucia":
			LAi_SetStayType(characterFromID("Lucia Montavez"));
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_32";
			break;

		case "rejoindre_elting":
			DoQuestReloadToLocation("Cabin2", "reload", "reload1" ,"rejoindre_elting2");
			break;

		case "rejoindre_elting2":
			ChangeCharacterAddress(characterFromID("Gregorio Montavez"), "none", "");
			ChangeCharacterAddress(characterFromID("Lorenzo Delgado"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cabin2", "rld", "loc6");
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cabin2", "rld", "aloc3");
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_126";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 3.0, 1.0);
			break;

		case "rejoindre_lucia_palace":
			AddQuestRecord("Firework", "7");
			ChangeCharacterAddressGroup(CharacterFromID("Lucia Montavez"), "Governor_Daughter_House", "goto", "goto8");
			LAi_SetStayType(characterFromID("Lucia Montavez"));
			Characters[GetCharacterIndex("Lucia Montavez")].dialog.currentnode = "begin_21";
			WaitDate("", 0,0,1,0,0);
			SetCurrentTime(9, 0);
			DoQuestReloadToLocation("Cartagena_port", "reload", "reload3" ,"_");
			break;

		case "square_fight":
			ChangeCharacterAddress(characterFromID("Elting"), "none", "");
			ChangeCharacterAddress(characterFromID("Augusto Queiroz"), "none", "");

			LAi_SetActorType(characterFromID("Lucia Montavez"));
			LAi_ActorGoToLocation(characterFromID("Lucia Montavez"), "reload", "reload2", "none", "", "", "", 4.0);

			ChangeCharacterAddressGroup(CharacterFromID("Rademiro Elizondo"), "Palace", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("Mayrelli Cadena"), "Palace", "goto", "goto16");
			ChangeCharacterAddressGroup(CharacterFromID("Zacarias Amendola"), "Palace", "goto", "goto11");

			Pchar.quest.fight_square.win_condition.l1 = "location";
			Pchar.quest.fight_square.win_condition.l1.location = "Palace";
			PChar.quest.fight_square.win_condition = "square_fight2";
			break;

		case "square_fight2":
			locations[FindLocation("Palace")].reload.l4.disable = 1;
			LAi_SetActorType(characterFromID("Zacarias Amendola"));
			Characters[GetCharacterIndex("Zacarias Amendola")].dialog.currentnode = "begin_36";
			LAi_ActorDialog(characterFromID("Zacarias Amendola"), pchar, "", 3.0, 1.0);
			break;

		case "square_fight3":
			LAi_ActorAttack(CharacterFromID("Zacarias Amendola"), Pchar, "");

			pchar.quest.chefe_died.win_condition.l1 = "NPC_Death";
			pchar.quest.chefe_died.win_condition.l1.character = "Zacarias Amendola";
			pchar.quest.chefe_died.win_condition = "square_fight4";
			break;

		case "square_fight4":
			LAi_group_FightGroups("FIGHTER_SQUARE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FIGHTER_SQUARE", "square_fight_end");
			break;

		case "square_fight_end":
			Characters[GetCharacterIndex("Cartagena_soldier_8")].dialog.filename = "Divers_dialog.c";
			Characters[GetCharacterIndex("Cartagena_soldier_8")].dialog.CurrentNode = "begin_38";
			LAi_SetActorType(characterFromID("Cartagena_soldier_8"));
			LAi_ActorDialog(characterFromID("Cartagena_soldier_8"), pchar, "", 20.0, 1.0);
			LAi_SetActorType(characterFromID("Cartagena_soldier_7"));
			LAi_ActorFollow(characterFromID("Cartagena_soldier_7"), characterFromID("Cartagena_soldier_8"), "", 20.0);
			break;

		case "square_fight_lucia":
			ChangeCharacterAddressGroup(CharacterFromID("Lucia Montavez"), "Palace", "reload", "reload4");
			LAi_SetActorType(characterFromID("Lucia Montavez"));
			Characters[GetCharacterIndex("Lucia Montavez")].dialog.currentnode = "begin_26";
			LAi_ActorDialog(characterFromID("Lucia Montavez"), pchar, "", 20.0, 1.0);
			break;

		case "stroll_lucia":
			ChangeCharacterAddress(characterFromID("Zacarias Amendola"), "none", "");// To be sure it won't appear again later in the square		
			DoQuestReloadToLocation("Residence_Cartagena", "goto", "goto32" ,"stroll_lucia2");
			break;

		case "stroll_lucia2":
			ChangeCharacterAddressGroup(CharacterFromID("Lucia Montavez"), "Residence_Cartagena", "goto", "goto33");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto17");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);

			ChangeCharacterAddressGroup(CharacterFromID("Cartagena_soldier_7"), "Palace", "goto", "goto14");
			ChangeCharacterAddressGroup(CharacterFromID("Cartagena_soldier_8"), "Palace", "goto", "goto15");
			LAi_SetGuardianType(CharacterFromID("Cartagena_soldier_7"));
			LAi_SetGuardianType(CharacterFromID("Cartagena_soldier_8"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_soldier_7"), "SPAIN_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_soldier_8"), "SPAIN_SOLDIERS");

			LAi_SetActorType(characterFromID("Lucia Montavez"));
			Characters[GetCharacterIndex("Lucia Montavez")].dialog.currentnode = "begin_29";
			LAi_ActorDialog(characterFromID("Lucia Montavez"), pchar, "", 2.0, 1.0);
			break;

		case "stroll_lucia3":
			DoQuestReloadToLocation("Cartagena_Townhall", "reload", "reload2" ,"see_admiral_guard");
			break;

		case "see_admiral_guard":
			AddQuestRecord("Firework", "8");
			ChangeCharacterAddress(characterFromID("Lucia Montavez"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("Admiral_guard"), "Admiral_Office", "goto", "goto1");
			Characters[GetCharacterIndex("Admiral_guard")].dialog.currentnode = "begin_31";
			break;

		case "see_ortega_valet":
			AddQuestRecord("Firework", "9");
			ChangeCharacterAddressGroup(CharacterFromID("Vicente Espejo"), "Cartagena_Center", "reload", "reload9");
			Characters[GetCharacterIndex("Vicente Espejo")].dialog.currentnode = "begin_41";
			break;

		case "join_ortega_garden":
			ChangeCharacterAddressGroup(CharacterFromID("Sebastian Ortega"), "Residence_Cartagena", "goto", "goto34");
			LAi_SetStayType(characterFromID("Sebastian Ortega"));
			Characters[GetCharacterIndex("Sebastian Ortega")].dialog.currentnode = "begin_3";
			ChangeCharacterAddressGroup(CharacterFromID("Federico Carabali"), "Residence_Cartagena", "goto", "goto35");
			break;

		case "ortega_duel":
			LAi_SetActorType(characterFromID("Sebastian Ortega"));
			LAi_ActorAttack(CharacterFromID("Sebastian Ortega"), Pchar, "");

			pchar.quest.ortega_wounded.win_condition.l1 = "NPC_Death";
			pchar.quest.ortega_wounded.win_condition.l1.character = "Sebastian Ortega";
			pchar.quest.ortega_wounded.win_condition = "ortega_duel_end";
			break;

		case "ortega_duel_end":
			LAi_SetActorType(characterFromID("Federico Carabali"));
			Characters[GetCharacterIndex("Federico Carabali")].dialog.currentnode = "begin_44";
			LAi_ActorDialog(characterFromID("Federico Carabali"), pchar, "", 20.0, 1.0);
			break;

		case "queiroz_ship":
			DoQuestReloadToLocation("Cabin2", "rld", "loc6" ,"queiroz_ship2");
			break;

		case "queiroz_ship2":
			WaitDate("", 0,0,6,0,0);
			SetCurrentTime(9, 0);
			ChangeCharacterAddressGroup(CharacterFromID("Gregorio Montavez"), "Cartagena_Townhall", "goto", "goto8");
			LAi_SetHuberStayType(characterFromID("Gregorio Montavez"));
			ChangeCharacterAddress(characterFromID("Sebastian Ortega"), "none", "");
			ChangeCharacterAddress(characterFromID("Federico Carabali"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cabin2", "rld", "aloc3");
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_17";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "return_montavez":
			DoQuestReloadToLocation("Cartagena_Townhall", "reload", "reload1" ,"return_montavez2");
			break;

		case "return_montavez2":
			AddQuestRecord("Firework", "10");
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_37";
			break;

		case "see_admiral":
			AddQuestRecord("Firework", "11");
			ChangeCharacterAddress(characterFromID("Admiral_guard"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("Lorenzo Delgado"), "Admiral_Office", "goto", "goto1");
			Characters[GetCharacterIndex("Lorenzo Delgado")].dialog.currentnode = "begin_1";
			break;

		case "elting_come_back":
			AddQuestRecord("Firework", "12");

			pchar.quest.elting_back.win_condition.l1 = "locator";
			pchar.quest.elting_back.win_condition.l1.location = "Cartagena_port";
			pchar.quest.elting_back.win_condition.l1.locator_group = "reload";
			pchar.quest.elting_back.win_condition.l1.locator = "reload3_back";
			pchar.quest.elting_back.win_condition = "elting_come_back2";
			break;

		case "elting_come_back2":
			ChangeCharacterAddress(characterFromID("Augusto Queiroz"), "none", "");
			DoQuestReloadToLocation("Cabin2", "reload", "reload1" ,"elting_come_back3");
			break;

		case "elting_come_back3":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cabin2", "rld", "loc6");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cabin2", "rld", "aloc3");
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_130";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 3.0, 1.0);
			break;

		case "dierman_info":
			WaitDate("", 0,0,1,0,0);
			SetCurrentTime(9, 0);
			DoQuestReloadToLocation("Cabin2", "rld", "loc6" ,"dierman_info2");
			break;

		case "dierman_info2":
			ChangeCharacterAddress(characterFromID("Elting"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cabin2", "reload", "reload1");
			LAi_SetActorType(characterFromID("Arie Dierman"));
			Characters[GetCharacterIndex("Arie Dierman")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Arie Dierman"), pchar, "", 2.0, 1.0);
			break;

		case "see_square_place":
			DoQuestReloadToLocation("Cartagena_port", "reload", "reload3" ,"see_square_place2");
			break;

		case "see_square_place2":
			AddQuestRecord("Firework", "13");
			Characters[GetCharacterIndex("Cartagena_soldier_8")].dialog.CurrentNode = "begin_45";
			break;

		case "elting_info_arrest":
			AddQuestRecord("Firework", "14");
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.CurrentNode = "begin_48";
			break;

		case "elting_info_arrest2":
			DoQuestReloadToLocation("Cabin2", "reload", "reload1" ,"elting_info_arrest3");
			break;

		case "elting_info_arrest3":
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cabin2", "rld", "aloc3");
			LAi_SetActorType(characterFromID("Arie Dierman"));
			Characters[GetCharacterIndex("Arie Dierman")].dialog.currentnode = "begin_4";
			LAi_ActorDialog(characterFromID("Arie Dierman"), pchar, "", 3.0, 1.0);
			break;

		case "free_elting":
			SetCurrentTime(22.01, 0);
			GiveModel2Player("Animistse",true);
			SetModel(characterFromID("Elting"), "Johan_Elting", "man", "man", 1.8, true);

			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(pchar, "bladeX4");
			TakeNItems(pchar, "medical1", -2);
			TakeNItems(pchar, "pistolpdart", 2);
			GiveItem2Character(pchar,"pistol203");
			EquipCharacterByItem(pchar, "pistol203");

			DoQuestReloadToLocation("Cartagena_blacksmith", "reload", "reload1" ,"cartagena_church_start");

			break;

			//JRH Cartagena -->
			//-----------------------------------------------------------------------------------------------------------
			//Cartagena church
			//pär
		case "pchar_playertype":
			LAi_SetPlayerType(Pchar);
			break;

		case "cartagena_church_start":
			AddQuestRecord("Firework", "15");

			Locations[FindLocation("Cartagena_center")].models.always.locators = "cartTown_l_BOP";
			Locations[FindLocation("Cartagena_center")].locators_radius.box.box1 = 1.5;
			Locations[FindLocation("Cartagena_center")].items.randitem1 = "derrick";
			Locations[FindLocation("Cartagena_center")].items.randitem2 = "derrick";

			Locations[FindLocation("Cartagena_church")].models.always.locators = "church3_l_BOP_closed";
			Locations[FindLocation("Cartagena_church")].locators_radius.reload.reload1 = 0.0001;
			Locations[FindLocation("Cartagena_church")].locators_radius.box.box2 = 1.0;


			DeleteAttribute(characterFromID("Elting"), "items");
			GiveItem2Character(characterFromID("Elting"),"bladeX4");
			ChangeCharacterAddressGroup(characterFromID("Elting"), "Cartagena_church_cave", "quest", "prison8");

			pchar.quest.cartagena_church_start.win_condition.l1 = "locator";
			pchar.quest.cartagena_church_start.win_condition.l1.location = "Cartagena_Center";
			pchar.quest.cartagena_church_start.win_condition.l1.locator_group = "reload";
			pchar.quest.cartagena_church_start.win_condition.l1.locator = "reload2";
			pchar.quest.cartagena_church_start.win_condition = "cartagena_church_start1";
			break;

		case "cartagena_church_start1":
			if(CheckAttribute(Pchar,"quest.cartagena_derrick_hint") && Pchar.quest.cartagena_derrick_hint == "done")
			{
				return;
			}
			else
			{
				Logit(TranslateString("","Hmm, I have to find another way into the Church."));
				PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			}
			break;

		case "climb_derrick":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_center", "goto", "box2");
			PlaySound("PEOPLE\creak2.wav");

			LAi_QuestDelay("climb_derrick1", 0.5);
			break;

		case "climb_derrick1":
			LAi_SetPlayerType(Pchar);
			Pchar.quest.church_burglar = "1";
			break;

		case "shot_at_church_window":
			if(CheckAttribute(Pchar,"quest.church_burglar") && Pchar.quest.church_burglar == "5")
			{
				PlaySound("VOICE\ENGLISH\alarm1.wav");

				LAi_QuestDelay("shot_at_church_window2", 2.0);
				LAi_QuestDelay("shot_at_church_window1", 2.0);
				LAi_QuestDelay("shot_at_church_window1", 2.5);
			}
			break;

		case "shot_at_church_window1":
			PlaySound("OBJECTS\DUEL\pistol_bbus.wav");
			break;

		case "shot_at_church_window2":
			Lai_KillCharacter(pchar);

			LAi_QuestDelay("church_cave_no_reinc", 0.1);
			break;

		case "enter_church_via_window":
			DoQuestReloadToLocation("Cartagena_church", "goto", "box1", "enter_church_via_window1");
			break;

		case "enter_church_via_window1":
			PlaySound("PEOPLE\counter_close.wav");
			ChangeCharacterAddressGroup(characterFromID("Cartagena_church_soldier"), "Cartagena_Center", "box", "box1");
			break;

		case "cartagena_church_jump":
			LAi_SetActorType(Pchar);

			LAi_QuestDelay("cartagena_church_jump1", 1.0);
			break;

		case "cartagena_church_jump1":
			LAi_ActorTurnToLocator(Pchar, "goto", "window2");

			LAi_QuestDelay("cartagena_church_jump2", 1.0);
			break;

		case "cartagena_church_jump2":
			PlaySound("PEOPLE\step_echo2.wav");
			ChangeCharacterAddressGroup(Pchar, "Cartagena_church", "goto", "window2");
			LAi_SetPlayerType(Pchar);

			LAi_QuestDelay("blue_cloth_check", 0.1);

			pchar.quest.Elting_prison.win_condition.l2 = "locator";
			pchar.quest.Elting_prison.win_condition.l2.location = "Cartagena_church_cave";
			pchar.quest.Elting_prison.win_condition.l2.locator_group = "goto";
			pchar.quest.Elting_prison.win_condition.l2.locator = "box6";
			pchar.quest.Elting_prison.win_condition = "Elting_prison";

			pchar.quest.cartagena_snoring_starts.win_condition.l3 = "locator";
			pchar.quest.cartagena_snoring_starts.win_condition.l3.location = "Cartagena_church_cave";
			pchar.quest.cartagena_snoring_starts.win_condition.l3.locator_group = "goto";
			pchar.quest.cartagena_snoring_starts.win_condition.l3.locator = "snoring";
			pchar.quest.cartagena_snoring_starts.win_condition = "cartagena_snoring_starts";
			break;

		case "blue_cloth_check":
			if(CheckCharacterItem(Pchar,"Animist_cloth"))
			{
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box5", 0.5);
				Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box5 = 0.5;
				locations[FindLocation(Pchar.location)].box5.items.bladeacid = 1;
				locations[FindLocation(Pchar.location)].box5.items.jewelry9 = 1;

				LAi_QuestDelay("bladeacid_check", 0.1);
			}
			else
			{
				LAi_QuestDelay("blue_cloth_check", 0.5);//loop check
			}
			break;

		case "bladeacid_check":
			if(CheckCharacterItem(Pchar,"bladeacid"))
			{
				Logit(TranslateString("","Yes, I'll try this on the Cell door!"));
				PlaySound("VOICE\ENGLISH\blaze_puh.wav");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE );
				EquipCharacterByItem(Pchar, "bladeacid");
			}
			else
			{
				LAi_QuestDelay("bladeacid_check", 0.5);//loop check
			}
			break;

		case "Elting_prison":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "Elting_prison";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialogNow(characterFromID("Elting"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Elting"));
			break;

		case "Elting_prison_done":
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box6", 0.5);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box6 = 0.5;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box12", 1.0);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box12 = 1.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box13", 1.0);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box13 = 1.0;

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box14", 0.7);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box14 = 0.7;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box15", 0.7);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box15 = 0.7;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box16", 0.7);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box16 = 0.7;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box17", 0.7);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box17 = 0.7;
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "First time";
			break;
			//pär
		case "cartagena_snoring_starts":
			if(CheckAttribute(Pchar,"quest.priest_wakes_up") && Pchar.quest.priest_wakes_up == "yes") return;

			if(CheckAttribute(pchar,"quest.inquisition_monk"))
			{
				if(Pchar.quest.inquisition_monk == "monk1_hit" || Pchar.quest.inquisition_monk == "monk2_hit"
						|| Pchar.quest.inquisition_monk == "monk3_hit" || Pchar.quest.inquisition_monk == "monk4_hit") return;
			}

			Pchar.quest.cartagena_snoring = "started";

			LAi_QuestDelay("cartagena_snoring", 0.1);
			LAi_QuestDelay("cartagena_snoring2", 2.0);

			pchar.quest.cartagena_silence1.win_condition.l1 = "locator";
			pchar.quest.cartagena_silence1.win_condition.l1.location = "Cartagena_church_cave";
			pchar.quest.cartagena_silence1.win_condition.l1.locator_group = "goto";
			pchar.quest.cartagena_silence1.win_condition.l1.locator = "silence1";
			pchar.quest.cartagena_silence1.win_condition = "cartagena_stop_snoring";

			pchar.quest.cartagena_guard1.win_condition.l1 = "locator";
			pchar.quest.cartagena_guard1.win_condition.l1.location = "Cartagena_church_cave";
			pchar.quest.cartagena_guard1.win_condition.l1.locator_group = "goto";
			pchar.quest.cartagena_guard1.win_condition.l1.locator = "guard1";
			pchar.quest.cartagena_guard1.win_condition = "cartagena_stop_snoring";
			break;

		case "cartagena_stop_snoring":
			Pchar.quest.cartagena_snoring = "stopped";

			pchar.quest.cartagena_snoring_starts.win_condition.l1 = "locator";
			pchar.quest.cartagena_snoring_starts.win_condition.l1.location = "Cartagena_church_cave";
			pchar.quest.cartagena_snoring_starts.win_condition.l1.locator_group = "goto";
			pchar.quest.cartagena_snoring_starts.win_condition.l1.locator = "snoring";
			pchar.quest.cartagena_snoring_starts.win_condition = "cartagena_snoring_starts";
			break;

		case "cartagena_snoring":
			if(CheckAttribute(Pchar,"quest.cartagena_snoring") && Pchar.quest.cartagena_snoring == "stopped")
			{
				//no snoring please
			}
			else
			{
				int sleepingsound = rand(11);

				switch (sleepingsound)
				{
				case 0: PlaySound("AMBIENT\TAVERN\man2.wav"); break;
				case 1: PlaySound("AMBIENT\JAIL\sigh.wav"); PlaySound("AMBIENT\JAIL\sigh.wav"); break;
				case 2: PlaySound("AMBIENT\JAIL\sigh.wav"); PlaySound("AMBIENT\JAIL\sigh.wav"); break;
				case 3: PlaySound("PEOPLE\snoring.wav"); break;
				case 4: PlaySound("PEOPLE\snoring.wav"); break;
				case 5: PlaySound("PEOPLE\snoring.wav"); break;
				case 6: PlaySound("PEOPLE\snoring.wav"); break;
				case 7: PlaySound("PEOPLE\snoring.wav"); break;
				case 8: PlaySound("PEOPLE\snoring.wav"); break;
				case 9: PlaySound("PEOPLE\snoring.wav"); break;
				case 10: PlaySound("PEOPLE\snoring.wav"); break;
				case 11: PlaySound("PEOPLE\snoring.wav"); break;
				}

				LAi_QuestDelay("cartagena_snoring", 3.5);
			}
			break;

		case "cartagena_snoring2":
			if(CheckAttribute(Pchar,"quest.cartagena_snoring") && Pchar.quest.cartagena_snoring == "stopped")
			{
				//no snoring please
			}
			else
			{
				sleepingsound = rand(11);

				switch (sleepingsound)
				{
				case 0: PlaySound("PEOPLE\fart1.wav"); break;
				case 1: PlaySound("AMBIENT\JAIL\sigh2.wav"); PlaySound("AMBIENT\JAIL\sigh2.wav"); break;
				case 2: PlaySound("AMBIENT\JAIL\sigh2.wav"); PlaySound("AMBIENT\JAIL\sigh2.wav"); break;
				case 3: PlaySound("PEOPLE\snoring2.wav"); break;
				case 4: PlaySound("PEOPLE\snoring2.wav"); break;
				case 5: PlaySound("PEOPLE\snoring2.wav"); break;
				case 6: PlaySound("PEOPLE\snoring2.wav"); break;
				case 7: PlaySound("PEOPLE\snoring2.wav"); break;
				case 8: PlaySound("PEOPLE\snoring2.wav"); break;
				case 9: PlaySound("PEOPLE\snoring2.wav"); break;
				case 10: PlaySound("PEOPLE\snoring2.wav"); break;
				case 11: PlaySound("PEOPLE\snoring2.wav"); break;
				}

				LAi_QuestDelay("cartagena_snoring2", 4.0);
			}
			break;

		case "cartagena_church_lever_down":
			Locations[FindLocation("cartagena_church")].image = "";
			DoQuestReloadToLocation("cartagena_church", "reload", "reload3", "cartagena_church_lever_down1");
			break;

		case "cartagena_church_lever_down1":
			Locations[FindLocation("cartagena_church")].image = "Inside_Church_3.tga";
			PlaySound("INTERFACE\shelf_open.wav");
			break;

		case "cartagena_church_lever_up":
			Locations[FindLocation("cartagena_church")].image = "";
			DoQuestReloadToLocation("cartagena_church", "reload", "reload3", "cartagena_church_lever_up1");
			break;

		case "cartagena_church_lever_up1":
			Locations[FindLocation("cartagena_church")].image = "Inside_Church_3.tga";
			PlaySound("INTERFACE\shelf_close.wav");
			break;

		case "cartagena_chest_noise":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Logit(TranslateString("","I shouldn't have done that. Hope no one heard it."));
			break;

		case "hide_behind_barrel":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Logit(TranslateString("","No, there's nothing here."));

			LAi_QuestDelay("hide_behind_barrel1", 1.0);
			break;

		case "hide_behind_barrel1":
			Pchar.quest.hide_behind_barrel = "no";
			break;

		case "hide_at_monks_chest":
			Logit(TranslateString("","I shouldn't have done that. Hope no one heard it."));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look1");

			LAi_QuestDelay("hide_at_monks_chest1", 1.0);
			break;

		case "hide_at_monks_chest1":
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("hide_at_monks_chest2", 3.0);
			break;

		case "hide_at_monks_chest2":
			PlaySound("PEOPLE\yawn.wav");

			Pchar.quest.cartagena_snoring = "started";

			LAi_QuestDelay("cartagena_snoring", 1.5);
			LAi_QuestDelay("cartagena_snoring2", 3.5);
			LAi_QuestDelay("hide_at_monks_chest3", 3.5);
			break;

		case "hide_at_monks_chest3":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			Logit(TranslateString("","They went to sleep again. Let's go!"));

			LAi_SetPlayerType(Pchar);
			break;

		case "priest_wakes_up":
			GiveItem2Character(CharacterFromID("inquisition_priest"), "blade14");
			EquipCharacterByItem(CharacterFromID("inquisition_priest"), "blade14");

			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "bed1");
			PlaySound("VOICE\ENGLISH\spa_m_b_063.wav");
			Pchar.quest.priest_wakes_up = "yes";

			LAi_QuestDelay("priest_wakes_up1", 2.0);
			break;

		case "priest_wakes_up1":
			PlaySound("AMBIENT\TOWN\Alarm.wav");

			LAi_QuestDelay("priest_wakes_up2", 2.0);
			break;

		case "priest_wakes_up2":
			PlaySound("PEOPLE\run_stone.wav");
			LAi_SetActorType(characterFromID("inquisition_monk1"));
			LAi_SetActorType(characterFromID("inquisition_monk3"));
			ChangeCharacterAddressGroup(characterFromID("inquisition_monk1"), "Cartagena_church_cave", "goto", "guard1");
			ChangeCharacterAddressGroup(characterFromID("inquisition_monk3"), "Cartagena_church_cave", "goto", "guard3");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto22");

			LAi_QuestDelay("priest_wakes_up3", 2.0);
			break;

		case "priest_wakes_up3":
			PlaySound("PEOPLE\run_stone.wav");
			LAi_SetActorType(characterFromID("inquisition_monk2"));
			ChangeCharacterAddressGroup(characterFromID("inquisition_monk2"), "Cartagena_church_cave", "goto", "guard2");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "guard4");

			LAi_QuestDelay("priest_wakes_up4", 2.0);
			break;

		case "priest_wakes_up4":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "wake_up1");

			LAi_QuestDelay("priest_wakes_up5", 1.0);
			break;

		case "priest_wakes_up5":
			LAi_SetPlayerType(Pchar);
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], false);
			LAi_ActorAttack(CharacterFromID("inquisition_priest"), PChar, "");
			LAi_ActorAttack(CharacterFromID("inquisition_monk1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("inquisition_monk2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("inquisition_monk3"), PChar, "");

			LAi_SetActorType(characterFromID("inquisition_monk4"));
			ChangeCharacterAddressGroup(characterFromID("inquisition_monk4"), "Cartagena_church_cave", "goto", "goto20");
			locations[FindLocation("Cartagena_church_cave")].reload.l1.disable = 1;

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "goto20", 3.0);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.goto.goto20 = 3.0;

			LAi_QuestDelay("church_cave_no_reinc", 0.1);

			pchar.quest.priest_wakes_up6.win_condition.l1 = "locator";
			pchar.quest.priest_wakes_up6.win_condition.l1.location = "Cartagena_church_cave";
			pchar.quest.priest_wakes_up6.win_condition.l1.locator_group = "goto";
			pchar.quest.priest_wakes_up6.win_condition.l1.locator = "goto20";
			pchar.quest.priest_wakes_up6.win_condition = "priest_wakes_up6";
			break;

		case "priest_wakes_up6":
			LAi_ActorAttack(CharacterFromID("inquisition_monk4"), PChar, "");
			break;

		case "cartagena_priest_stunned_left":
			LAi_SetActorType(characterFromID("inquisition_priest"));
			LAi_ActorSetLayMode(characterFromID("inquisition_priest"));
			CreateParticleSystem("stars" , -6.1, 0.9, 17.0, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
			Pchar.quest.inquisition_priest = "stunned";
			LAi_SetFightMode(Pchar, false);
			ChangeCharacterAddressGroup(Pchar, "Cartagena_church_cave", "goto", "back12");
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], true);

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box12", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box12 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box13", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box13 = 0.001;

			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE );
			TakeItemFromCharacter(Pchar, "bladepclub203");
			EquipCharacterByItem(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "pistol203");
			EquipCharacterByItem(Pchar, "pistol203");
			break;

		case "cartagena_priest_stunned_right":
			LAi_SetActorType(characterFromID("inquisition_priest"));
			LAi_ActorSetLayMode(characterFromID("inquisition_priest"));
			CreateParticleSystem("stars" , -6.1, 0.9, 17.0, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
			Pchar.quest.inquisition_priest = "stunned";
			LAi_SetFightMode(Pchar, false);
			ChangeCharacterAddressGroup(Pchar, "Cartagena_church_cave", "goto", "back13");
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], true);

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box12", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box12 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box13", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box13 = 0.001;

			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE );
			TakeItemFromCharacter(Pchar, "bladepclub203");
			EquipCharacterByItem(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "pistol203");
			EquipCharacterByItem(Pchar, "pistol203");
			break;

		case "cartagena_monks_hit":
			Pchar.quest.cartagena_snoring = "stopped";
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			LAi_SetFightMode(Pchar, false);

			ChangeCharacterAddressGroup(characterFromID("inquisition_priest"), "Cartagena_church_cave", "reload", "reload1");
			LAi_SetActorType(characterFromID("inquisition_priest"));
			locations[FindLocation("Cartagena_church_cave")].reload.l1.disable = 1;

			if(CheckAttribute(pchar,"quest.inquisition_monk"))
			{
				if(pchar.quest.inquisition_monk == "monk1_hit")
				{
					LAi_SetActorType(characterFromID("inquisition_monk1"));
					LAi_ActorSetLayMode(characterFromID("inquisition_monk1"));
					CreateParticleSystem("stars_short" , 4.8, 1.3, 19.7, 0.0, 0.0, 0.0, sti(20) );
					ChangeCharacterAddressGroup(Pchar, "Cartagena_church_cave", "goto", "back14");
				}
				else
				{
					ChangeCharacterAddressGroup(characterFromID("inquisition_monk1"), "Cartagena_church_cave", "goto", "wake_up2");
					LAi_SetActorType(characterFromID("inquisition_monk1"));

				}

				if(pchar.quest.inquisition_monk == "monk2_hit")
				{
					LAi_SetActorType(characterFromID("inquisition_monk2"));
					LAi_ActorSetLayMode(characterFromID("inquisition_monk2"));
					CreateParticleSystem("stars_short" , 8.4, 1.3, 18.6, 0.0, 0.0, 0.0, sti(20) );
					ChangeCharacterAddressGroup(Pchar, "Cartagena_church_cave", "goto", "back15");
				}
				else
				{
					ChangeCharacterAddressGroup(characterFromID("inquisition_monk2"), "Cartagena_church_cave", "goto", "wake_up3");
					LAi_SetActorType(characterFromID("inquisition_monk2"));

				}

				if(pchar.quest.inquisition_monk == "monk3_hit")
				{
					LAi_SetActorType(characterFromID("inquisition_monk3"));
					LAi_ActorSetLayMode(characterFromID("inquisition_monk3"));
					CreateParticleSystem("stars_short" , 9.8, 1.3, 14.2, 0.0, 0.0, 0.0, sti(20) );
					ChangeCharacterAddressGroup(Pchar, "Cartagena_church_cave", "goto", "back16");
				}
				else
				{
					ChangeCharacterAddressGroup(characterFromID("inquisition_monk3"), "Cartagena_church_cave", "goto", "wake_up4");
					LAi_SetActorType(characterFromID("inquisition_monk3"));
				}

				if(pchar.quest.inquisition_monk == "monk4_hit")
				{
					LAi_SetActorType(characterFromID("inquisition_monk4"));
					LAi_ActorSetLayMode(characterFromID("inquisition_monk4"));
					CreateParticleSystem("stars_short" , 9.4, 1.3, 10.0, 0.0, 0.0, 0.0, sti(20) );
					ChangeCharacterAddressGroup(Pchar, "Cartagena_church_cave", "goto", "back17");
				}
				else
				{
					ChangeCharacterAddressGroup(characterFromID("inquisition_monk4"), "Cartagena_church_cave", "goto", "wake_up5");
					LAi_SetActorType(characterFromID("inquisition_monk4"));

				}
			}

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box14", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box14 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box15", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box15 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box16", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box16 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box17", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box17 = 0.001;

			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE );
			TakeItemFromCharacter(Pchar, "bladepclub203");
			EquipCharacterByItem(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "pistolpdart");
			EquipCharacterByItem(Pchar, "pistolpdart");

			LAi_QuestDelay("cartagena_cave_alarm", 1.0);
			break;

		case "cartagena_cave_alarm":
			PlaySound("VOICE\ENGLISH\spa_m_a_050.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look1");

			LAi_QuestDelay("cartagena_cave_alarm1", 2.0);
			break;

		case "cartagena_cave_alarm1":
			PlaySound("AMBIENT\TOWN\Alarm.wav");
			LAi_SetPlayerType(Pchar);

			GiveItem2Character(CharacterFromID("inquisition_priest"), "blade14");
			EquipCharacterByItem(CharacterFromID("inquisition_priest"), "blade14");

			if(CheckAttribute(pchar,"quest.inquisition_monk"))
			{
				if(pchar.quest.inquisition_monk == "monk1_hit")
				{
					//stay in bed
				}
				else LAi_ActorAttack(CharacterFromID("inquisition_monk1"), PChar, "");

				if(pchar.quest.inquisition_monk == "monk2_hit")
				{
					//stay in bed
				}
				else LAi_ActorAttack(CharacterFromID("inquisition_monk2"), PChar, "");

				if(pchar.quest.inquisition_monk == "monk3_hit")
				{
					//stay in bed
				}
				else LAi_ActorAttack(CharacterFromID("inquisition_monk3"), PChar, "");

				if(pchar.quest.inquisition_monk == "monk4_hit")
				{
					//stay in bed
				}
				else LAi_ActorAttack(CharacterFromID("inquisition_monk4"), PChar, "");
			}

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "goto20", 3.0);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.goto.goto20 = 3.0;

			LAi_QuestDelay("church_cave_no_reinc", 0.1);

			pchar.quest.cartagena_cave_alarm2.win_condition.l1 = "locator";
			pchar.quest.cartagena_cave_alarm2.win_condition.l1.location = "Cartagena_church_cave";
			pchar.quest.cartagena_cave_alarm2.win_condition.l1.locator_group = "goto";
			pchar.quest.cartagena_cave_alarm2.win_condition.l1.locator = "goto20";
			pchar.quest.cartagena_cave_alarm2.win_condition = "cartagena_cave_alarm2";
			break;

		case "cartagena_cave_alarm2":
			LAi_ActorAttack(CharacterFromID("inquisition_priest"), PChar, "");
			break;

		case "acid_Eltings_cell":
			if(LAi_IsFightMode(Pchar))
			{
				LAi_SetFightMode(Pchar, false);
			}
			PlaySound("INTERFACE\fire_off.wav");
			CreateParticleSystem("smoke_short" , 6.5, 0.6, -19.6, 4.5, 1.5, 0.0, sti(20) );
			ChangeCharacterAddressGroup(Pchar, "Cartagena_church_cave", "goto", "acid");
			LAi_SetStayType(Pchar);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladeacid");
			EquipCharacterbyItem(Pchar, "bladeX4");
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_church_cave")], true);

			LAi_QuestDelay("acid_Eltings_cell1", 5.0);
			break;

		case "acid_Eltings_cell1":
			PlaySound("PEOPLE\lock_open.wav");
			Pchar.quest.Eltings_cell = "open";

			LAi_QuestDelay("acid_Eltings_cell2", 2.0);
			break;

		case "acid_Eltings_cell2":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");

			LAi_QuestDelay("acid_Eltings_cell3", 1.0);
			break;

		case "acid_Eltings_cell3":
			PlaySound("VOICE\ENGLISH\dut_m_a_017.wav");
			LAi_SetOfficerType(CharacterFromID("Elting"));

			LAi_QuestDelay("acid_Eltings_cell4", 2.0);
			break;

		case "acid_Eltings_cell4":
			PlaySound("INTERFACE\rusty.wav");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cartagena_church_cave", "goto", "box6");

			LAi_QuestDelay("acid_Eltings_cell5", 2.0);
			break;

		case "acid_Eltings_cell5":
			RemovePassenger(Pchar, characterFromID("Elting"));
			AddPassenger(Pchar, characterFromID("Elting"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Elting"));

			LAi_QuestDelay("Elting_prison_outfit", 1.0);
			break;

		case "Elting_prison_outfit":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "Elting_prison_outfit";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialogNow(characterFromID("Elting"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Elting"));
			break;

		case "Elting_prison_outfit_done":
			SetModel(characterFromID("Elting"), "Animist_Elting", "man", "man", 1.8, true);
			PlaySound("PEOPLE\clothes1.wav");
			TakeItemFromCharacter(pchar, "Animist_cloth");

			LAi_QuestDelay("Elting_prison_knife", 2.0);
			break;

		case "Elting_prison_knife":
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "Elting_prison_knife";
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorDialogNow(characterFromID("Elting"), pchar, "", 0.1);
			LAi_ActorWaitDialog(Pchar, characterFromID("Elting"));
			break;

		case "Elting_prison_knife_done":
			PlaySound("INTERFACE\button3.wav");

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(pchar, "pistol203");
			GiveItem2Character(Pchar, "bladepclub203");
			EquipCharacterByItem(Pchar, "bladepclub203");
			EquipCharacterByItem(Pchar, "pistolpdart");

			AddMoneyToCharacter(characterFromID("Elting"), -100);
			RemoveCharacterEquip(characterFromID("Elting"), GUN_ITEM_TYPE);
			RemoveCharacterEquip(characterFromID("Elting"), BLADE_ITEM_TYPE);
			GiveItem2Character(characterFromID("Elting"), "pistolpdart");
			EquipCharacterByItem(characterFromID("Elting"), "bladeX4");
			EquipCharacterByItem(characterFromID("Elting"), "pistolpdart");
			TakeItemFromCharacter(pchar, "pistolpdart");
			LAi_SetPlayerType(Pchar);
			LAi_SetOfficerType(CharacterFromID("Elting"));

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box14", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box14 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box15", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box15 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box16", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box16 = 0.001;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box17", 0.001);
			Locations[FindLocation("Cartagena_church_cave")].locators_radius.box.box17 = 0.001;

			LAi_SetHP(characterFromID("Cartagena_soldier_5"), 20.0, 20.0);
			LAi_SetHP(characterFromID("Cartagena_soldier_6"), 20.0, 20.0);
			ChangeCharacterAddressGroup(CharacterFromID("Cartagena_church_soldier"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Cartagena_patrol_08"), "Cartagena_Center", "goto", "goto64");
			ChangeCharacterAddressGroup(CharacterFromID("Cartagena_patrol_07"), "Cartagena_Center", "goto", "goto65");
			ChangeCharacterAddressGroup(CharacterFromID("Cartagena_patrol_06"), "Cartagena_Center", "goto", "goto66");
			LAi_SetGuardianType(CharacterFromID("Cartagena_patrol_06"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_patrol_06"), "SPAIN_SOLDIERS");
			LAi_SetGuardianType(CharacterFromID("Cartagena_patrol_07"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_patrol_07"), "SPAIN_SOLDIERS");
			LAi_SetGuardianType(CharacterFromID("Cartagena_patrol_08"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_patrol_08"), "SPAIN_SOLDIERS");
			locations[FindLocation("Cartagena_center")].reload.l1.disable = 1;
			Locations[FindLocation("Cartagena_Center")].locators_radius.goto.goto5 = 8.0;
			Locations[FindLocation("Cartagena_Center")].locators_radius.goto.goto8 = 8.0;

			Pchar.quest.cartagena_church_end.win_condition.l1 = "location";
			Pchar.quest.cartagena_church_end.win_condition.l1.location = "Cartagena_Center";
			Pchar.quest.cartagena_church_end.win_condition = "cartagena_church_end";
			break;

		case "church_cave_no_reinc":
			if(LAi_IsDead(Pchar))
			{
				LAi_QuestDelay("delay_no_reinc", 3.0);
			}
			else LAi_QuestDelay("church_cave_no_reinc", 1.0);
			break;

		case "delay_no_reinc":
			GameOverOrg("land");
			break;

			//<-- JRH Cartagena

		case "cartagena_church_end":
			pchar.quest.cart_soldados.win_condition.l1 = "locator";
			pchar.quest.cart_soldados.win_condition.l1.location = "Cartagena_Center";
			pchar.quest.cart_soldados.win_condition.l1.locator_group = "goto";
			pchar.quest.cart_soldados.win_condition.l1.locator = "goto5";
			pchar.quest.cart_soldados.win_condition = "go_cartagena_center_soldiers";

			DisableFastTravel(true);
			DisableMenuLaunch(true);

			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_142";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "go_cartagena_center_soldiers":
			LAi_SetStayType(characterFromID("Elting"));
			LAi_SetOfficerType(characterFromID("Elting"));
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);

			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
			LAi_RemoveCheckMinHP(Pchar);
			break;


		case "go_blacksmith_cartagena":
			TakeNItems(pchar, "pistolpdart", 2);
			EquipCharacterByItem(Pchar, "pistolpdart");
			LAi_SetOfficerType(CharacterFromID("Elting"));
			AddQuestRecord("Firework", "16");

			PChar.quest.blacksmith_cartagena.win_condition.l1 = "locator";
			PChar.quest.blacksmith_cartagena.win_condition.l1.location = "Cartagena_Center";
			PChar.quest.blacksmith_cartagena.win_condition.l1.locator_group = "goto";
			PChar.quest.blacksmith_cartagena.win_condition.l1.locator = "goto8";
			PChar.quest.blacksmith_cartagena.win_condition = "go_blacksmith_cartagena2";
			break;

		case "go_blacksmith_cartagena2":
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_143";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "go_blacksmith_cartagena3":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(Pchar, "goto", "goto10", "", 25.0);
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorRunToLocator(characterFromID("Elting"), "goto", "goto60", "go_blacksmith_cartagena4", 25.0);
			break;

		case "go_blacksmith_cartagena4":
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorGoToLocator(characterFromID("Elting"), "goto", "goto61", "go_blacksmith_cartagena5", 15.0);
			break;

		case "go_blacksmith_cartagena5":
			LAi_SetActorType(characterFromID("Elting"));
			LAi_ActorGoToLocator(characterFromID("Elting"), "goto", "goto62", "talk_guard_cartagena_center", 15.0);
			break;

		case "talk_guard_cartagena_center":
			LAi_SetActorType(characterFromID("Cartagena_soldier_6"));
			LAi_ActorFollow(characterFromID("Cartagena_soldier_6"), characterFromID("Elting"), "", 3.0);
			LAi_QuestDelay("talk_guard_cartagena_center2", 4.0);
			break;

		case "talk_guard_cartagena_center2":
			LAi_SetActorType(characterFromID("Cartagena_soldier_5"));
			LAi_ActorFollow(characterFromID("Cartagena_soldier_5"), characterFromID("Elting"), "talk_guard_cartagena_center3", 8.0);
			break;

		case "talk_guard_cartagena_center3":
			LAi_SetPlayerType(Pchar);
			AddQuestRecord("Firework", "17");
			LAi_SetWarriorType(characterFromID("Cartagena_soldier_5"));
			LAi_warrior_SetStay(CharacterFromID("Cartagena_soldier_5"), 1);
			LAi_SetWarriorType(characterFromID("Cartagena_soldier_6"));
			LAi_warrior_SetStay(CharacterFromID("Cartagena_soldier_6"), 1);
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_soldier_5"), "CENTRE_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_soldier_6"), "CENTRE_SOLDIERS");
			LAi_group_SetRelation("CENTRE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			Pchar.quest.Kill_Cartagena_Guards.win_condition.l1 = "NPC_Death";
			Pchar.quest.Kill_Cartagena_Guards.win_condition.l1.character = "Cartagena_soldier_5";
			Pchar.quest.Kill_Cartagena_Guards.win_condition.l2 = "NPC_Death";
			Pchar.quest.Kill_Cartagena_Guards.win_condition.l2.character = "Cartagena_soldier_6";
			PChar.quest.Kill_Cartagena_Guards.win_condition = "elting_back_ship";

			LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, true, "go_cartagena_center_soldiers");
			break;

		case "elting_back_ship":
			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_146";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "elting_back_ship2":
			DoQuestReloadToLocation("Cabin2", "rld", "loc2" ,"elting_back_ship3");
			break;

		case "elting_back_ship3":
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_10"));
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE); // remove poisoned daggers
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE); // remove	club

			pchar.quest.cart_soldados.over = "yes";
			locations[FindLocation("Cartagena_center")].reload.l1.disable = 0;
			Locations[FindLocation("Cartagena_Center")].locators_radius.goto.goto5 = 1.0;
			Locations[FindLocation("Cartagena_Center")].locators_radius.goto.goto8 = 1.0;

			Locations[FindLocation("Cartagena_center")].models.always.locators = "cartTown_l";
			Locations[FindLocation("Cartagena_church")].models.always.locators = "church3_l_BOP_neutral";
			Locations[FindLocation("Cartagena_center")].reload.l2.close_for_night = 1;		//church

			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cabin2", "rld", "loc1");
			SetModelfromArray(characterFromID("Elting"), GetModelIndex("Johan_Elting_c"));
			EquipCharacterByItem(characterFromID("Elting"), "Blade_ProudOfAnvil");
			EquipCharacterByItem(characterFromID("Elting"), "pistol2");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cabin2", "rld", "loc5");
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cabin2", "rld", "aloc5");

			LAi_SetActorType(characterFromID("Arie Dierman"));
			Characters[GetCharacterIndex("Arie Dierman")].dialog.currentnode = "begin_11";
			LAi_ActorDialog(characterFromID("Arie Dierman"), pchar, "", 2.0, 1.0);
			break;

		case "elting_back_ship4":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_19";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "last_meet_with_governor":
			SetCurrentTime(10.00, 0);

			DoQuestReloadToLocation("Cartagena_Townhall", "reload", "reload1" ,"last_meet_with_governor2");
			break;

		case "last_meet_with_governor2":
			AddQuestRecord("Firework", "18");
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_61";
			break;

		case "cartagena_report":
			LAi_Fade("cartagena_report1", "cartagena_report2");
			break;

		case "cartagena_report1":
			LAi_SetActorType(characterFromID("Gregorio Montavez"));
			Characters[GetCharacterIndex("Gregorio Montavez")].dialog.currentnode = "begin_66";
			break;

		case "cartagena_report2":
			SetCurrentTime(14.00, 0);
			LAi_ActorDialog(characterFromID("Gregorio Montavez"), pchar, "", 1.0, 1.0);
			break;

		case "end_report":
			DoQuestReloadToLocation("Cabin2", "rld", "loc6" ,"prepare_operation_fort");
			break;

		case "prepare_operation_fort":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cabin2", "rld", "aloc2");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cabin2", "rld", "aloc5");
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cabin2", "rld", "aloc1");
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Cabin2", "rld", "startloc");

			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "details_operation";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "operation_emilio":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_84";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 2.0, 1.0);
			break;

		case "operation_queiroz":
			LAi_ActorGoToLocation(characterFromID("Emilio Soares"), "reload", "reload1", "none", "", "", "", 4.0);
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_21";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "operation_dierman":
			LAi_SetActorType(characterFromID("Arie Dierman"));
			Characters[GetCharacterIndex("Arie Dierman")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Arie Dierman"), pchar, "", 2.0, 1.0);
			break;

		case "prepare_operation_end":
			SetCurrentTime(23.00, 0);
			SetNextWeather("Blue Sky");
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "details_operation_fin";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "swim_to_warship":
			LAi_SetPlayerType(pchar);
			GiveShip2Character(CharacterFromID("Spanish Captain1"),"SP_Derfflinger","Sirena",-1,SPAIN,true,true);
			GiveShip2Character(CharacterFromID("Spanish Captain2"),"SP_BattleGalleon","San Martin",-1,SPAIN,true,true);
			GiveShip2Character(CharacterFromID("Spanish Captain3"),"SP_Pinnace50","Galicia",-1,SPAIN,true,true);
			SetCharacterShipLocation(Pchar, "Cartagena_PortB");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain1"), "Cartagena_PortB");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain2"), "Cartagena_PortB");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain3"), "Cartagena_PortB");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain4"), "Cartagena_PortB");
			LAi_SetHP(characterFromID("Cartagena_soldier_5"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Cartagena_soldier_6"), 80.0, 80.0);
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_soldier_5"), "SPAIN_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_soldier_6"), "SPAIN_SOLDIERS");
			ChangeCharacterAddressGroup(CharacterFromID("Cartagena_patrol_08"), "Cartagena_Center", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Cartagena_patrol_07"), "Cartagena_Center", "goto", "goto37");
			ChangeCharacterAddressGroup(CharacterFromID("Cartagena_patrol_06"), "Cartagena_Center", "goto", "goto28");
			LAi_SetPatrolType(CharacterFromID("Cartagena_patrol_06"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_patrol_06"), "SPAIN_SOLDIERS");
			LAi_SetPatrolType(CharacterFromID("Cartagena_patrol_07"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_patrol_07"), "SPAIN_SOLDIERS");
			LAi_SetPatrolType(CharacterFromID("Cartagena_patrol_08"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_patrol_08"), "SPAIN_SOLDIERS");

			PChar.quest.swimming_warship.win_condition.l1 = "locator";
			PChar.quest.swimming_warship.win_condition.l1.location = "Cartagena_PortB";
			PChar.quest.swimming_warship.win_condition.l1.locator_group = "goto";
			PChar.quest.swimming_warship.win_condition.l1.locator = "goto1";
			PChar.quest.swimming_warship.win_condition = "start3";

			Locations[FindLocation("Cartagena_PortB")].locators_radius.goto.goto1 = 4.0;

			DoQuestReloadToLocation("Cartagena_PortB", "reload", "reload1" ,"swim_to_warship2");
			break;

		case "swim_to_warship2":
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_6"));
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Cartagena_PortB", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Cartagena_PortB", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Cartagena_PortB", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Cartagena_PortB", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Cartagena_PortB", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Cartagena_PortB", "goto", "goto17");
			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("bart_pirate_02"));
			LAi_SetOfficerType(characterFromID("bart_pirate_03"));
			LAi_SetOfficerType(characterFromID("bart_pirate_04"));
			LAi_SetOfficerType(characterFromID("bart_pirate_05"));
			LAi_SetOfficerType(characterFromID("bart_pirate_06"));
			AddQuestRecord("Firework", "19");
			break;

		case "start3":
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_11"));
			LAi_SetActorType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto2");
			LAi_ActorAnimation(Pchar, "Lay_1", "start4", 1.2);
			break;

		case "start4":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto3");
			LAi_ActorAnimation(Pchar, "Lay_2", "start5", 1.2);
			break;

		case "start5":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto4");
			LAi_ActorAnimation(Pchar, "Lay_1", "start6", 1.2);
			break;

		case "start6":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto5");
			LAi_ActorAnimation(Pchar, "Lay_2", "start7", 1.2);
			break;

		case "start7":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto6");
			LAi_ActorAnimation(Pchar, "Lay_1", "start8", 1.2);
			break;

		case "start8":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto7");
			LAi_ActorAnimation(Pchar, "Lay_2", "start9", 1.2);
			break;

		case "start9":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto8");
			LAi_ActorAnimation(Pchar, "Lay_1", "start10", 1.2);
			break;

		case "start10":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto9");
			LAi_ActorAnimation(Pchar, "Lay_2", "start11", 1.2);
			break;

		case "start11":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto10");
			LAi_ActorAnimation(Pchar, "Lay_1", "start12", 1.2);
			break;

		case "start12":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto11");
			LAi_ActorAnimation(Pchar, "Lay_2", "start13", 1.2);
			break;

		case "start13":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto12");
			LAi_ActorAnimation(Pchar, "Lay_1", "start14", 1.2);
			break;

		case "start14":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto13");
			LAi_ActorAnimation(Pchar, "Lay_2", "start15", 1.2);
			break;

		case "start15":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto14");
			LAi_ActorAnimation(Pchar, "Lay_1", "start16", 1.2);
			break;

		case "start16":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto15");
			LAi_ActorAnimation(Pchar, "Lay_2", "start17", 1.2);
			break;

		case "start17":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_PortB", "goto", "goto16");
			LAi_ActorAnimation(Pchar, "Lay_1", "deck_san_martin", 1.2);
			break;

		case "deck_san_martin":
			ChangeCharacterAddress(characterFromID("Alfonso Galindez"), "none", "");//Location Quest_ShipDeck6 also used by the Anaconda quest - character removed to be sure it will not appear there again
			//-> Remove Elting to be sure it won't be with me before starting the fight in the fort
			RemoveCharacterCompanion(pchar, characterFromID("Elting"));		
			RemoveOfficersIndex(pchar, GetCharacterIndex("Elting"));
			//<- Remove Elting to be sure it won't be with me before starting the fight in the fort			
			DoQuestReloadToLocation("Quest_ShipDeck6", "goto", "goto16" ,"deck_san_martin2");
			break;

		case "deck_san_martin2":
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_6"));
			LAi_SetPlayerType(pchar);

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Quest_ShipDeck6", "goto", "goto7");
			LAi_SetImmortal(CharacterFromID("bart_pirate_07"), true);

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Quest_ShipDeck6", "goto", "goto17");
			GiveItem2Character(characterFromID("bart_pirate_02"), "blade50");
			EquipCharacterByItem(characterFromID("bart_pirate_02"), "blade50");
			LAi_SetImmortal(CharacterFromID("bart_pirate_02"), true);

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Quest_ShipDeck6", "goto", "goto18");
			GiveItem2Character(characterFromID("bart_pirate_03"), "blade50");
			EquipCharacterByItem(characterFromID("bart_pirate_03"), "blade50");
			LAi_SetImmortal(CharacterFromID("bart_pirate_03"), true);

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Quest_ShipDeck6", "goto", "goto14");
			GiveItem2Character(characterFromID("bart_pirate_04"), "blade50");
			EquipCharacterByItem(characterFromID("bart_pirate_04"), "blade50");
			LAi_SetImmortal(CharacterFromID("bart_pirate_04"), true);

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Quest_ShipDeck6", "goto", "goto8");
			GiveItem2Character(characterFromID("bart_pirate_05"), "blade50");
			EquipCharacterByItem(characterFromID("bart_pirate_05"), "blade50");
			LAi_SetImmortal(CharacterFromID("bart_pirate_05"), true);

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Quest_ShipDeck6", "goto", "goto15");
			GiveItem2Character(characterFromID("bart_pirate_06"), "blade50");
			EquipCharacterByItem(characterFromID("bart_pirate_06"), "blade50");
			LAi_SetImmortal(CharacterFromID("bart_pirate_06"), true);


			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto10");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto6");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto28");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto33");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto32");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN");

			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("bart_pirate_02"));
			LAi_SetOfficerType(characterFromID("bart_pirate_03"));
			LAi_SetOfficerType(characterFromID("bart_pirate_04"));
			LAi_SetOfficerType(characterFromID("bart_pirate_05"));
			LAi_SetOfficerType(characterFromID("bart_pirate_06"));


			LAi_group_FightGroups("SOLDATOS_MARTIN", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SOLDATOS_MARTIN", "deck_san_martin3");
			break;

		case "deck_san_martin3":
			LAi_SetActorType(Pchar);
			PlaySound("OBJECTS\SHIPCHARGE\hurrah.wav");
			LAi_QuestDelay("deck_san_martin4", 1.5);
			break;

		case "deck_san_martin4":
			DoQuestReloadToLocation("Quest_ShipDeck6", "goto", "goto34" ,"deck_san_martin5");
			break;

		case "deck_san_martin5":
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Quest_ShipDeck6", "goto", "goto35");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Quest_ShipDeck6", "goto", "goto36");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Quest_ShipDeck6", "goto", "goto37");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Quest_ShipDeck6", "goto", "goto38");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Quest_ShipDeck6", "goto", "goto39");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Quest_ShipDeck6", "goto", "goto22");
			LAi_SetActorType(characterFromID("bart_pirate_02"));
			LAi_SetActorType(characterFromID("bart_pirate_03"));
			LAi_SetActorType(characterFromID("bart_pirate_04"));
			LAi_SetActorType(characterFromID("bart_pirate_05"));
			LAi_SetActorType(characterFromID("bart_pirate_06"));

			ChangeCharacterAddressGroup(CharacterFromID("Sebastian Ortega"), "Quest_ShipDeck6", "goto", "goto28");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto29");
			LAi_SetImmortal(sld, true);
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto30");
			LAi_SetImmortal(sld, true);
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto31");
			LAi_SetImmortal(sld, true);
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto32");
			LAi_SetImmortal(sld, true);
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN2");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto33");
			LAi_SetImmortal(sld, true);
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTIN2");

			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("bart_pirate_07"));
			Characters[GetCharacterIndex("bart_pirate_07")].dialog.currentnode = "begin_50";
			LAi_ActorDialog(characterFromID("bart_pirate_07"), pchar, "", 0.5, 1.0);
			break;

		case "deck_san_martin6":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(PChar, characterFromID("Sebastian Ortega"));
			LAi_QuestDelay("deck_san_martin7", 1.0);
			break;

		case "deck_san_martin7":
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "order_to_crew";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "deck_san_martin8":
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("bart_pirate_02"));
			LAi_SetOfficerType(characterFromID("bart_pirate_03"));
			LAi_SetOfficerType(characterFromID("bart_pirate_04"));
			LAi_SetOfficerType(characterFromID("bart_pirate_05"));
			LAi_SetOfficerType(characterFromID("bart_pirate_06"));

			LAi_group_FightGroups("SOLDATOS_MARTIN2", LAI_GROUP_PLAYER, true);

			PChar.quest.going_yardarm.win_condition.l1 = "locator";
			PChar.quest.going_yardarm.win_condition.l1.location = "Quest_ShipDeck6";
			PChar.quest.going_yardarm.win_condition.l1.locator_group = "goto";
			PChar.quest.going_yardarm.win_condition.l1.locator = "goto40";
			PChar.quest.going_yardarm.win_condition = "fight_yardarm";

			LAi_SetActorType(CharacterFromID("Sebastian Ortega"));
			LAi_ActorRunToLocator(characterFromID("Sebastian Ortega"), "goto", "goto40", "deck_san_martin9", 10.0);
			break;

		case "deck_san_martin9":
			ChangeCharacterAddress(characterFromID("Sebastian Ortega"), "none", "");
			AddQuestRecord("Firework", "20");
			break;

		case "fight_yardarm":
			DoQuestReloadToLocation("Quest_ShipDeck6Bis", "goto", "goto1" ,"fight_yardarm2");
			break;

		case "fight_yardarm2":
			ChangeCharacterAddressGroup(CharacterFromID("Sebastian Ortega"), "Quest_ShipDeck6Bis", "goto", "goto2");

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Quest_ShipDeck6Bis", "goto", "goto3");
			LAi_group_MoveCharacter(CharacterFromID("bart_pirate_07"), "BARTOLOMEU_PIRATES");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Quest_ShipDeck6Bis", "goto", "goto5");
			LAi_group_MoveCharacter(CharacterFromID("bart_pirate_02"), "BARTOLOMEU_PIRATES");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Quest_ShipDeck6Bis", "goto", "goto19");
			LAi_group_MoveCharacter(CharacterFromID("bart_pirate_03"), "BARTOLOMEU_PIRATES");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Quest_ShipDeck6Bis", "goto", "goto24");
			LAi_group_MoveCharacter(CharacterFromID("bart_pirate_04"), "BARTOLOMEU_PIRATES");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Quest_ShipDeck6Bis", "goto", "goto26");
			LAi_group_MoveCharacter(CharacterFromID("bart_pirate_05"), "BARTOLOMEU_PIRATES");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Quest_ShipDeck6Bis", "goto", "goto22");
			LAi_group_MoveCharacter(CharacterFromID("bart_pirate_06"), "BARTOLOMEU_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto4");
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTINC");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto6");
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTINC");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto23");
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTINC");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto10");
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTINC");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto25");
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTINC");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto20");
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "SOLDATOS_MARTINC");

			LAi_group_FightGroups("SOLDATOS_MARTINC", "BARTOLOMEU_PIRATES", true);

			LAi_SetActorType(characterFromID("Sebastian Ortega"));
			Characters[GetCharacterIndex("Sebastian Ortega")].dialog.currentnode = "begin_8";
			LAi_ActorDialog(characterFromID("Sebastian Ortega"), pchar, "", 2.0, 1.0);
			break;

		case "fight_yardarm2_1":
			Pchar.quest.kill_Ortega.win_condition.l1 = "NPC_Death";
			Pchar.quest.kill_Ortega.win_condition.l1.character = "Sebastian Ortega";
			Pchar.quest.kill_Ortega.win_condition = "fight_yardarm3";

			LAi_SetWarriorType(characterFromID("Sebastian Ortega"));
			LAi_warrior_SetStay(characterFromID("Sebastian Ortega"), true);

			break;

		case "fight_yardarm3":
			LAi_SetActorType(pchar);
			LAi_QuestDelay("fight_yardarm4", 3.5);
			break;

		case "fight_yardarm4":
			DoQuestReloadToLocation("Quest_ShipDeck6", "goto", "goto40" ,"fight_yardarm5");
			break;

		case "fight_yardarm5":
			LAi_group_FightGroups("SOLDATOS_MARTINC", "BARTOLOMEU_PIRATES", false);
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Quest_ShipDeck6", "goto", "goto6");
			PlaySound("OBJECTS\SHIPCHARGE\hurrah.wav");
			Characters[GetCharacterIndex("bart_pirate_02")].dialog.filename = "Divers_dialog.c";

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Quest_ShipDeck6", "goto", "goto5");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Quest_ShipDeck6", "goto", "goto30");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Quest_ShipDeck6", "goto", "goto30");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Quest_ShipDeck6", "goto", "goto30");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Quest_ShipDeck6", "goto", "goto30");
			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("bart_pirate_03"));
			LAi_SetOfficerType(characterFromID("bart_pirate_04"));
			LAi_SetOfficerType(characterFromID("bart_pirate_05"));
			LAi_SetOfficerType(characterFromID("bart_pirate_06"));

			Characters[GetCharacterIndex("bart_pirate_02")].dialog.currentnode = "begin_52";
			LAi_SetStayType(CharacterFromID("bart_pirate_02"));
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(CharacterFromID("bart_pirate_02"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("bart_pirate_02"),"", 5.0, 1.0);
			break;

		case "fight_yardarm6":
			LAi_SetActorType(CharacterFromID("Cartagena_patrol_05"));
			LAi_ActorSetLayMode(CharacterFromID("Cartagena_patrol_05"));
			LAi_SetActorType(CharacterFromID("Cartagena_patrol_04"));
			LAi_ActorSetLayMode(CharacterFromID("Cartagena_patrol_04"));
			LAi_SetActorType(CharacterFromID("Cartagena_soldier_7"));
			LAi_ActorSetLayMode(CharacterFromID("Cartagena_soldier_7"));
			LAi_SetActorType(CharacterFromID("Cartagena_soldier_8"));
			LAi_ActorSetLayMode(CharacterFromID("Cartagena_soldier_8"));

			Locations[FindLocation("Palace")].vcskip = true;

			LAi_SetOfficerType(characterFromID("bart_pirate_02"));
			LAi_SetOfficerType(characterFromID("bart_pirate_03"));
			LAi_SetOfficerType(characterFromID("bart_pirate_04"));
			LAi_SetOfficerType(characterFromID("bart_pirate_05"));
			LAi_SetOfficerType(characterFromID("bart_pirate_06"));
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("bart_pirate_07"));
			Characters[GetCharacterIndex("bart_pirate_07")].dialog.currentnode = "begin_53";
			LAi_ActorDialog(characterFromID("bart_pirate_07"), pchar, "", 2.0, 1.0);
			break;

		case "fight_yardarm_end":
			DoQuestReloadToLocation("Palace", "goto", "goto19" ,"before_cartagena_puzzle");
			break;

		case "before_cartagena_puzzle":
			SetModelfromArray(&pchar, GetModelIndex("GypsyCaptn_2"));
			GiveItem2Character(Pchar,"goldarmor");
			EquipCharacterByItem(Pchar,"goldarmor");

			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Palace", "goto", "goto18");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Palace", "goto", "goto23");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "Palace", "goto", "goto22");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "Palace", "goto", "goto20");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "Palace", "goto", "goto21");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "Palace", "goto", "goto4");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "Palace", "goto", "goto24");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "Palace", "goto", "goto12");
			ChangeCharacterAddressGroup(CharacterFromID("Lorenzo Delgado"), "none", "", "");
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_22";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "before_cartagena_puzzle2":
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Palace", "goto", "goto3");
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(PChar, characterFromID("Emilio Soares"));
			LAi_QuestDelay("before_cartagena_puzzle2_1", 1.0);
			break;

		case "before_cartagena_puzzle2_1":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_85";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 20.0, 1.0);
			break;

		case "before_cartagena_puzzle3":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_24";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "before_cartagena_puzzle4":
			DoQuestReloadToLocation("Admiral_Office", "goto", "goto3" ,"before_cartagena_puzzle5");
			break;

		case "before_cartagena_puzzle5":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Admiral_Office", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Admiral_Office", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "Admiral_Office", "goto", "goto6");
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "none", "", "");
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_25";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "before_cartagena_puzzle6":
			DoQuestReloadToLocation("Admiral_Office", "goto", "goto1" ,"before_cartagena_puzzle7");
			break;

		case "before_cartagena_puzzle7":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Admiral_Office", "goto", "goto3");
			Locations[FindLocation("Tunel")].locators_radius.randitem.randitem2 = 10.0;

			Pchar.quest.tunnel_entrance.win_condition.l1 = "location";
			Pchar.quest.tunnel_entrance.win_condition.l1.location = "Tunel";
			Pchar.quest.tunnel_entrance.win_condition = "tunnel_to_fort00";

			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_27";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "before_cartagena_puzzle7A":
			LAi_SetStayType(characterFromID("Augusto Queiroz"));					//JRH
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "First time";
			break;

			//JRH Cartagena -->
			//-----------------------------------------------------------------------------------------------------------
		case "cartagena_puzzle_start":
			Pchar.quest.cartagena_puzzle_start1.win_condition.l1 = "location";
			Pchar.quest.cartagena_puzzle_start1.win_condition.l1.location = "Palace";
			PChar.quest.cartagena_puzzle_start1.win_condition = "cartagena_puzzle_start1";

			AddQuestRecord("Firework", "21");
			break;

		case "cartagena_puzzle_start1":
			PlaySound("INTERFACE\key_lock.wav");

			locations[FindLocation("Palace")].reload.l1.disable = 1;			//back to town
			locations[FindLocation("Palace")].reload.l4.disable = 0;			//Lucia Montavez House
			locations[FindLocation("Palace")].reload.l2.disable = 0;			//to Residence
			Locations[FindLocation("Governor_Daughter_House")].reload.l2.disable = 0;	//to Bedroom

			pchar.quest.cartagena_pillow_check.win_condition.l1 = "locator";
			pchar.quest.cartagena_pillow_check.win_condition.l1.location = "Palace_Residence";
			pchar.quest.cartagena_pillow_check.win_condition.l1.locator_group = "randitem";
			pchar.quest.cartagena_pillow_check.win_condition.l1.locator = "randitem2";
			pchar.quest.cartagena_pillow_check.win_condition = "cartagena_pillow_check";

			pchar.quest.cartagena_fire_irons_check.win_condition.l1 = "locator";
			pchar.quest.cartagena_fire_irons_check.win_condition.l1.location = "Woman_Palace_bedroom";
			pchar.quest.cartagena_fire_irons_check.win_condition.l1.locator_group = "randitem";
			pchar.quest.cartagena_fire_irons_check.win_condition.l1.locator = "randitem1";
			pchar.quest.cartagena_fire_irons_check.win_condition = "cartagena_fire_irons_check";
			break;
			//-----------------------------------------------------------------------------------------------------------
		case "cartagena_pillow_check":
			//from cartagena_puzzle_start1

			if(CheckCharacterItem(Pchar,"pillow"))
			{
				PlaySound("PEOPLE\clothes1.wav");
				TakeItemFromCharacter(pchar, "pillow");
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem2", 0.0001);
				Locations[FindLocation("Palace_Residence")].locators_radius.randitem.randitem2 = 0.0001;

				SetLocatorRadius(locations[FindLocation(Pchar.location)], "randitem", "randitem1", 0.8);
				Locations[FindLocation("Palace_Residence")].locators_radius.randitem.randitem1 = 0.8;

				LAi_QuestDelay("cartagena_lever_check", 0.1);
			}
			else
			{
				LAi_QuestDelay("cartagena_pillow_check", 0.5);//loop check
			}
			break;

		case "cartagena_lever_check":
			//from pillow_check

			if(CheckCharacterItem(Pchar,"lever_item"))					//JRH
			{
				TakeItemFromCharacter(pchar, "lever_item");
				GiveItem2Character(Pchar, "bladelever");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladelever");
				pchar.quest.bladelever = "found";					//JRH

				LAi_QuestDelay("bladelever_and_bladeclockkey_check", 0.1); 		//JRH
			}
			else
			{
				LAi_QuestDelay("cartagena_lever_check", 0.5);//loop check
			}
			break;

		case "cartagena_cannonball_check":
			//from admiral_lever_down2

			if(CheckCharacterItem(Pchar,"cannonball2"))
			{
				TakeItemFromCharacter(pchar, "cannonball2");
				GiveItem2Character(Pchar, "bladecannon_ball");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladecannon_ball");
			}
			else
			{
				LAi_QuestDelay("cartagena_cannonball_check", 0.5);//loop check
			}
			break;
			//-----------------------------------------------------------------------------------------------------------
		case "cartagena_fire_irons_check":
			//from cartagena_puzzle_start1

			if(CheckCharacterItem(Pchar,"fire_irons_item"))
			{
				TakeItemFromCharacter(pchar, "fire_irons_item");
				GiveItem2Character(Pchar, "bladefire_irons");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladefire_irons");

				LAi_QuestDelay("cartagena_clockkey_check", 0.5);
			}
			else
			{
				LAi_QuestDelay("cartagena_fire_irons_check", 0.5);//loop check
			}
			break;

		case "cartagena_clockkey_check":
			//from fire_irons_check

			if(CheckCharacterItem(Pchar,"clockkey"))
			{
				TakeItemFromCharacter(pchar, "clockkey");
				GiveItem2Character(Pchar, "bladeclockkey");
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(Pchar, "bladeclockkey");
				TakeItemFromCharacter(pchar, "bladefire_irons");
				pchar.quest.bladeclockkey = "found";					//JRH

				LAi_QuestDelay("bladelever_and_bladeclockkey_check", 0.1);  		//JRH
			}
			else
			{
				LAi_QuestDelay("cartagena_clockkey_check", 0.5);//loop check
			}
			break;

			//JRH
		case "bladelever_and_bladeclockkey_check":
			if(CheckAttribute(Pchar,"quest.bladeclockkey") && Pchar.quest.bladeclockkey == "found")
			{
				if(CheckAttribute(Pchar,"quest.bladelever") && Pchar.quest.bladelever == "found")
				{
					//ChangeCharacterAddressGroup(CharacterFromID("Lorenzo Delgado"), "Admiral_Office", "goto", "goto2"); //line useless because already removed before
					LAi_QuestDelay("before_cartagena_puzzle6", 1.5);
				}
			}
			break;
			//-----------------------------------------------------------------------------------------------------------
		case "place_admiral_lever":
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "bladeX4");

			TakeItemFromCharacter(pchar, "bladelever");

			PlaySound("INTERFACE\lever_placed.wav");
			Pchar.quest.admiral_lever = "up";
			Locations[FindLocation("Admiral_Office")].models.always.l2 = "Adm_lever_up";

			LAi_QuestDelay("place_admiral_lever2", 0.5);
			break;

		case "place_admiral_lever2":
			Locations[FindLocation("Admiral_Office")].image = "";
			DoQuestReloadToLocation("Admiral_Office", "goto", "lever", "place_admiral_lever3");
			break;

		case "place_admiral_lever3":
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Admiral_Office")].image = "Town_Havana_Townhall.tga";
			break;

		case "admiral_lever_down":
			PlaySound("PEOPLE\creak2.wav");

			LAi_QuestDelay("admiral_lever_down1", 1.0);
			break;

		case "admiral_lever_down1":
			Locations[FindLocation("Admiral_Office")].image = "";
			DoQuestReloadToLocation("Admiral_Office", "goto", "lever", "admiral_lever_down2");
			break;

		case "admiral_lever_down2":
			PlaySound("PEOPLE\wood3.wav");
			CreateParticleSystem("blast_dirt", -1.30, -0.3, -2.2, 0.0, 0.0, 0.0, sti(20) );
			Locations[FindLocation("Admiral_Office")].image = "Town_Havana_Townhall.tga";

			LAi_QuestDelay("cartagena_cannonball_check", 0.1);
			LAi_QuestDelay("admiral_lever_down3", 1.0);
			break;

		case "admiral_lever_down3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto4");

			LAi_QuestDelay("admiral_lever_down4", 0.5);
			break;

		case "admiral_lever_down4":
			LAi_SetPlayerType(Pchar);
			break;

		case "enter_admiral_steplock":
			LAi_SetSitType(Pchar);
			PlaySound("INTERFACE\step_path.wav");
			Locations[FindLocation("Admiral_Office")].models.always.l1 = "bars_up";

			LAi_QuestDelay("enter_admiral_steplock2", 0.3);
			break;

		case "enter_admiral_steplock2":
			Locations[FindLocation("Admiral_Office")].image = "";
			DoQuestReloadToLocation("Admiral_Office", "goto", "sit1", "enter_admiral_steplock3");
			break;

		case "enter_admiral_steplock3":
			PlaySound("INTERFACE\rusty.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
			Locations[FindLocation("Admiral_Office")].image = "Town_Havana_Townhall.tga";

			LAi_QuestDelay("enter_admiral_steplock4", 0.5);
			break;

		case "enter_admiral_steplock4":
			LAi_SetSitType(Pchar);
			Pchar.quest.admiral_steplock = "way_out";

			LAi_QuestDelay("enter_admiral_steplock5", 0.5);
			break;

		case "enter_admiral_steplock5":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			break;

		case "leave_admiral_steplock":
			Locations[FindLocation("Admiral_Office")].image = "";
			DoQuestReloadToLocation("Admiral_Office", "goto", "sit1", "leave_admiral_steplock1");
			break;

		case "leave_admiral_steplock1":
			PlaySound("INTERFACE\elevator_gate.wav");
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "Admiral_Office", "goto", "goto7");
			Pchar.quest.admiral_steplock = "way_in";
			Locations[FindLocation("Admiral_Office")].image = "Town_Havana_Townhall.tga";

			LAi_QuestDelay("leave_admiral_steplock2", 1.5);
			break;

		case "leave_admiral_steplock2":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			break;

		case "place_admiral_cannonball":
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "bladeX4");

			TakeItemFromCharacter(pchar, "bladecannon_ball");

			PlaySound("INTERFACE\step_path.wav");
			Pchar.quest.admiral_cannonball = "placed";
			Locations[FindLocation("Admiral_Office")].models.always.l3 = "cannonball";
			Locations[FindLocation("Admiral_Office")].models.always.l1 = "bars_up";

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload1", 0.8);
			Locations[FindLocation("Admiral_Office")].locators_radius.reload.reload1 = 0.8;

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box5", 0.0001);
			Locations[FindLocation("Admiral_Office")].locators_radius.box.box5 = 0.0001;

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box1", 0.0001);
			Locations[FindLocation("Admiral_Office")].locators_radius.box.box1 = 0.0001;

			LAi_QuestDelay("place_admiral_cannonball2", 0.5);
			break;

		case "place_admiral_cannonball2":
			Locations[FindLocation("Admiral_Office")].image = "";
			DoQuestReloadToLocation("Admiral_Office", "goto", "goto8", "place_admiral_cannonball3");
			break;

		case "place_admiral_cannonball3":
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Admiral_Office")].image = "Town_Havana_Townhall.tga";
			PlaySound("INTERFACE\rusty.wav");

			LAi_QuestDelay("place_admiral_cannonball4", 1.0);
			break;

		case "place_admiral_cannonball4":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");

			LAi_QuestDelay("place_admiral_cannonball5", 1.0);
			break;

		case "place_admiral_cannonball5":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			LAi_SetPlayerType(Pchar);
			break;
			//-----------------------------------------------------------------------------------------------------
		case "use_fire_irons":
			PlaySound("PEOPLE\ram.wav");
			Pchar.quest.daughter_fireplace = "key_on_floor";
			Locations[FindLocation(Pchar.location)].models.always.locators = "Res03_l_BoP2";

			LAi_QuestDelay("use_fire_irons2", 1.5);
			break;

		case "use_fire_irons2":
			Locations[FindLocation("Governor_Daughter_House")].image = "";
			DoQuestReloadToLocation("Governor_Daughter_House", "goto", "fireplace", "use_fire_irons3");
			break;

		case "use_fire_irons3":
			PlaySound("INTERFACE\took_item.wav");
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Governor_Daughter_House")].image = "Inside_Residence3.tga";
			break;

		case "place_admiral_clockkey":
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "bladeX4");

			TakeItemFromCharacter(pchar, "bladeclockkey");

			PlaySound("INTERFACE\key_lock.wav");
			Pchar.quest.admiral_clock = "off";
			Locations[FindLocation("Admiral_Office")].models.always.l4 = "clockkey";

			LAi_QuestDelay("place_admiral_clockkey2", 0.5);
			break;

		case "place_admiral_clockkey2":
			Locations[FindLocation("Admiral_Office")].image = "";
			DoQuestReloadToLocation("Admiral_Office", "goto", "clock", "place_admiral_clockkey3");
			break;

		case "place_admiral_clockkey3":
			LAi_SetFightMode(Pchar, false);
			Locations[FindLocation("Admiral_Office")].image = "Town_Havana_Townhall.tga";
			break;


		case "admiral_wind_up_clock":
			PlaySound("INTERFACE\clock_wind_up.wav");

			LAi_QuestDelay("admiral_clock_ticking", 2.2);
			break;

		case "admiral_clock_ticking":
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("Admiral_Office")].reload.l1.disable = 0;

			PlaySound("INTERFACE\clock_ticking.wav");

			LAi_QuestDelay("admiral_clock_striking", 4.5); // adding 1 second to the previous value
			break;

		case "admiral_clock_striking":
			PlaySound("INTERFACE\clock.wav");

			LAi_QuestDelay("admiral_lock_door", 2.0);
			break;

		case "admiral_lock_door":
			Locations[FindLocation("Admiral_Office")].reload.l1.disable = 1;
			Pchar.quest.admiral_clock = "off";
			PlaySound("INTERFACE\key_lock.wav");
			break;
			//JRH Cartagena <--
			//-----------------------------------------------------------------------------------------------------------

		case "tunnel_to_fort00":
			LAi_SetPatrolType(CharacterFromID("Cartagena_patrol_05"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_patrol_05"), "SPAIN_SOLDIERS");
			LAi_SetPatrolType(CharacterFromID("Cartagena_patrol_04"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_patrol_04"), "SPAIN_SOLDIERS");
			LAi_SetGuardianType(CharacterFromID("Cartagena_soldier_8"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_soldier_8"), "SPAIN_SOLDIERS");
			LAi_SetGuardianType(CharacterFromID("Cartagena_soldier_7"));
			LAi_group_MoveCharacter(CharacterFromID("Cartagena_soldier_7"), "SPAIN_SOLDIERS");

			Locations[FindLocation("Palace")].vcskip = false;

			LAi_Fade("tunnel_to_fort01", "tunnel_to_fort02");
			break;

		case "tunnel_to_fort01":
			ChangeCharacterAddressGroup(Pchar, "Tunel", "goto", "goto11");
			break;

		case "tunnel_to_fort02":

			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Tunel", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Tunel", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "Tunel", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "Tunel", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "Tunel", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "Tunel", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "Tunel", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "Tunel", "goto", "goto3");
			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_04"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_05"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_06"));

			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_30";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 6.0, 1.0);
			break;

		case "tunnel_to_fort2":
			AddQuestRecord("Firework", "22");
			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "monsters", "monster30");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "TUNNEL_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "monsters", "monster33");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "TUNNEL_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "monsters", "monster32");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "TUNNEL_SOLDIERS");

			pchar.quest.tunnel_soldados.win_condition.l1 = "locator";
			pchar.quest.tunnel_soldados.win_condition.l1.location = "Tunel";
			pchar.quest.tunnel_soldados.win_condition.l1.locator_group = "randitem";
			pchar.quest.tunnel_soldados.win_condition.l1.locator = "randitem2";
			pchar.quest.tunnel_soldados.win_condition = "tunnel_to_fort3";
			break;

		case "tunnel_to_fort3":
			LAi_group_FightGroups("TUNNEL_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("TUNNEL_SOLDIERS", "tunnel_to_fort4");
			break;

		case "tunnel_to_fort4":
			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_04"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_05"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_06"));

			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_32";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 3.0, 1.0);
			break;

		case "tunnel_to_fort5":
			Locations[FindLocation("inside_Cartagena_Fort")].locators_radius.goto.goto17 = 5.0;
			Locations[FindLocation("inside_Cartagena_Fort")].locators_radius.goto.goto22 = 5.0;
			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));

			Pchar.quest.fort_entrance.win_condition.l1 = "location";
			Pchar.quest.fort_entrance.win_condition.l1.location = "inside_Cartagena_Fort";
			Pchar.quest.fort_entrance.win_condition = "inside_fort";
			break;

		case "inside_fort":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "inside_Cartagena_Fort", "goto", "goto44");

			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_33";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "inside_fort2":
			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "inside_Cartagena_Fort", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "inside_Cartagena_Fort", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "inside_Cartagena_Fort", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "inside_Cartagena_Fort", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "inside_Cartagena_Fort", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "inside_Cartagena_Fort", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "inside_Cartagena_Fort", "goto", "goto9");

			pchar.quest.fort_door.win_condition.l1 = "locator";
			pchar.quest.fort_door.win_condition.l1.location = "inside_Cartagena_Fort";
			pchar.quest.fort_door.win_condition.l1.locator_group = "goto";
			pchar.quest.fort_door.win_condition.l1.locator = "goto43";
			pchar.quest.fort_door.win_condition = "inside_fort3";
			break;

		case "inside_fort3":
			PlaySound("INTERFACE\door_locked.wav");

			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_34";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 3.0, 1.0);
			break;

		case "inside_fort4":
			AddQuestRecord("Firework", "23");
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_01"));
			LAi_ActorRunToLocator(characterFromID("Portuguese_soldier_01"), "goto", "goto47", "_", 15.0);
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_02"));
			LAi_ActorRunToLocator(characterFromID("Portuguese_soldier_02"), "goto", "goto48", "_", 15.0);
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_03"));
			LAi_ActorRunToLocator(characterFromID("Portuguese_soldier_03"), "goto", "goto24", "_", 15.0);
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_04"));
			LAi_ActorRunToLocator(characterFromID("Portuguese_soldier_04"), "goto", "goto26", "_", 15.0);
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_05"));
			LAi_ActorRunToLocator(characterFromID("Portuguese_soldier_05"), "goto", "goto13", "_", 15.0);
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_06"));
			LAi_ActorRunToLocator(characterFromID("Portuguese_soldier_06"), "goto", "goto25", "_", 15.0);

			locations[FindLocation("inside_Cartagena_Fort")].box3.items.key4 = 1;
			locations[FindLocation("inside_Cartagena_Fort")].box5.items.key3 = 1;
			LAi_QuestDelay("inside_fort5", 0.5);
			break;

		case "inside_fort5":
			if(CheckCharacterItem(Pchar,"key4"))
			{
				pchar.quest.cellule_door.win_condition.l1 = "locator";
				pchar.quest.cellule_door.win_condition.l1.location = "inside_Cartagena_Fort";
				pchar.quest.cellule_door.win_condition.l1.locator_group = "goto";
				pchar.quest.cellule_door.win_condition.l1.locator = "goto41";
				pchar.quest.cellule_door.win_condition = "inside_fort6";
			}
			else
			{
				LAi_QuestDelay("inside_fort5", 0.5);//loop check
			}
			break;

		case "inside_fort6":
			pchar.quest.cellule_door.over = "yes";
			PlaySound("INTERFACE\small_door.wav");
			ChangeCharacterAddressGroup(Pchar, "inside_Cartagena_Fort", "goto", "goto42");
			LAi_QuestDelay("inside_fort7", 0.5);
			TakeItemFromCharacter(pchar, "key4");
			break;

		case "inside_fort7":
			if(CheckCharacterItem(Pchar,"key3"))
			{
				PlaySound("INTERFACE\small_door.wav");
				ChangeCharacterAddressGroup(Pchar, "inside_Cartagena_Fort", "goto", "goto41");

				pchar.quest.big_door.win_condition.l1 = "locator";
				pchar.quest.big_door.win_condition.l1.location = "inside_Cartagena_Fort";
				pchar.quest.big_door.win_condition.l1.locator_group = "goto";
				pchar.quest.big_door.win_condition.l1.locator = "goto43";
				pchar.quest.big_door.win_condition = "inside_fort8";
			}
			else
			{
				LAi_QuestDelay("inside_fort7", 0.5);//loop check
			}
			break;

		case "inside_fort8":
			pchar.quest.big_door.over = "yes";

			PlaySound("INTERFACE\key_unlock.wav");
			Locations[FindLocation("inside_Cartagena_Fort")].models.always.porta = "bars_up";
			locations[FindLocation("inside_Cartagena_Fort")].models.day.charactersPatch = "DungeonVault1_patch";
			locations[FindLocation("inside_Cartagena_Fort")].models.night.charactersPatch = "DungeonVault1_patch";
			DoQuestReloadToLocation("inside_Cartagena_Fort", "goto", "goto43", "inside_fort9");
			TakeItemFromCharacter(pchar, "key3");
			break;

		case "inside_fort9":
			PlaySound("INTERFACE\elevator_gate.wav");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto45");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "INSIDE_FORT_SOLDIER");
			sld.id = "sentinel";

			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "inside_Cartagena_Fort", "goto", "goto46");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "inside_Cartagena_Fort", "goto", "goto47");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "inside_Cartagena_Fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "inside_Cartagena_Fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "inside_Cartagena_Fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "inside_Cartagena_Fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "inside_Cartagena_Fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "inside_Cartagena_Fort", "goto", "goto48");

			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_38";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 3.0, 1.0);
			break;

		case "inside_fort10":
			pchar.quest.detect_soldier.win_condition.l1 = "locator";
			pchar.quest.detect_soldier.win_condition.l1.location = "inside_Cartagena_Fort";
			pchar.quest.detect_soldier.win_condition.l1.locator_group = "goto";
			pchar.quest.detect_soldier.win_condition.l1.locator = "goto17";
			pchar.quest.detect_soldier.win_condition = "inside_fort11";

			pchar.quest.detected_soldier.win_condition.l1 = "locator";
			pchar.quest.detected_soldier.win_condition.l1.location = "inside_Cartagena_Fort";
			pchar.quest.detected_soldier.win_condition.l1.locator_group = "goto";
			pchar.quest.detected_soldier.win_condition.l1.locator = "goto22";
			pchar.quest.detected_soldier.win_condition = "inside_fort12";

			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));
			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_04"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_05"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_06"));
			break;

		case "inside_fort11":
			pchar.quest.detected_soldier.over = "yes";
			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
			LAi_SetActorType(characterFromID("sentinel"));
			LAi_ActorRunToLocation(characterFromID("sentinel"), "reload", "reload1", "none", "", "", "inside_fort11b", 10.0);
			break;

		case "inside_fort11b":
			PlaySound("INTERFACE\closed_door.wav");
			GameOverOrg("surrender");
			break;

		case "inside_fort12":
			pchar.quest.detect_soldier.over = "yes";
			LAi_group_FightGroups("INSIDE_FORT_SOLDIER", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("INSIDE_FORT_SOLDIER", "inside_fort13");
			break;

		case "inside_fort13":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_39";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 3.0, 1.0);
			break;

		case "inside_fort14":
			AddQuestRecord("Firework", "24");

			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));
			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_04"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_05"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_06"));

			Locations[FindLocation("Cartagena_fort")].models.always.mortier1 = "mortar";
			Locations[FindLocation("Cartagena_fort")].models.always.mortier1.locator.group = "goto";
			Locations[FindLocation("Cartagena_fort")].models.always.mortier1.locator.name = "goto26";

			Locations[FindLocation("Cartagena_fort")].models.always.mortier2 = "mortar";
			Locations[FindLocation("Cartagena_fort")].models.always.mortier2.locator.group = "goto";
			Locations[FindLocation("Cartagena_fort")].models.always.mortier2.locator.name = "goto27";

			Locations[FindLocation("Cartagena_fort")].models.always.echelle = "ladder";
			Locations[FindLocation("Cartagena_fort")].models.always.echelle.locator.group = "goto";
			Locations[FindLocation("Cartagena_fort")].models.always.echelle.locator.name = "goto15";

			DoQuickSave();															// PB: Might prevent some frustration
			Pchar.NoSave.Custom = "while you are in the Cartagena Fort location";	// PB: Disable saving

			Pchar.quest.san_felipe.win_condition.l1 = "location";
			Pchar.quest.san_felipe.win_condition.l1.location = "Cartagena_fort";
			Pchar.quest.san_felipe.win_condition = "outside_fort";
			break;

		case "outside_fort":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cartagena_fort", "goto", "goto29");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Cartagena_fort", "goto", "goto33");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "Cartagena_fort", "goto", "goto30");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "Cartagena_fort", "goto", "goto39");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "Cartagena_fort", "goto", "goto38");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "Cartagena_fort", "goto", "goto31");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "Cartagena_fort", "goto", "goto32");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "Cartagena_fort", "goto", "goto37");

			LAi_SetStayType(characterFromID("bart_pirate_07"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_01"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_02"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_03"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_04"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_05"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_06"));

			LAi_QuestDelay("outside_fort2", 2.0);
			break;

		case "outside_fort2":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_40";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "outside_fort3":
			LAi_SetActorType(characterFromID("bart_pirate_07"));
			Characters[GetCharacterIndex("bart_pirate_07")].dialog.currentnode = "begin_54";
			LAi_ActorDialog(characterFromID("bart_pirate_07"), pchar, "", 1.0, 1.0);
			break;

		case "outside_fort4":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_41";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 1.0, 1.0);
			break;

		case "outside_fort5":
			AddQuestRecord("Firework", "25");

			TakeNItems(pchar, "pistolpdart", 2);
			EquipCharacterByItem(Pchar, "pistolpdart");

			LAi_SetHP(CharacterFromID("Fort_Cartagena_soldier2"), 20.0, 20.0);
			LAi_SetHP(CharacterFromID("Fort_Cartagena_soldier1"), 20.0, 20.0);
			LAi_SetActorType(characterFromID("Fort_Cartagena_soldier1"));
			LAi_SetActorType(characterFromID("Fort_Cartagena_soldier2"));

			LAi_SetWarriorType(characterFromID("Fort_Cartagena_soldier1"));
			LAi_warrior_SetStay(CharacterFromID("Fort_Cartagena_soldier1"), 1);
			LAi_SetWarriorType(characterFromID("Fort_Cartagena_soldier2"));
			LAi_warrior_SetStay(CharacterFromID("Fort_Cartagena_soldier2"), 1);

			LAi_group_MoveCharacter(CharacterFromID("Fort_Cartagena_soldier2"), "OUTSIDE_FORT_SOLDIER");
			LAi_group_MoveCharacter(CharacterFromID("Fort_Cartagena_soldier1"), "OUTSIDE_FORT_SOLDIER");
			LAi_group_SetRelation("OUTSIDE_FORT_SOLDIER", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			Pchar.quest.Kill_Fort_Guards.win_condition.l1 = "NPC_Death";
			Pchar.quest.Kill_Fort_Guards.win_condition.l1.character = "Fort_Cartagena_soldier1";
			Pchar.quest.Kill_Fort_Guards.win_condition.l2 = "NPC_Death";
			Pchar.quest.Kill_Fort_Guards.win_condition.l2.character = "Fort_Cartagena_soldier2";
			PChar.quest.Kill_Fort_Guards.win_condition = "check_elting_troops";

			LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, true, "mission_aborted");
			break;

		case "mission_aborted":
			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER", LAI_GROUP_PLAYER, true);

			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
			LAi_RemoveCheckMinHP(Pchar);
			LAi_QuestDelay("mission_aborted2", 4.0);
			break;

		case "mission_aborted2":
			GameOverOrg("surrender");
			break;

		case "check_elting_troops":
			LAi_RemoveCheckMinHP(Pchar);
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cartagena_fort", "goto", "goto44");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cartagena_fort", "goto", "goto16");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_01"), "Cartagena_fort", "goto", "goto45");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_02"), "Cartagena_fort", "goto", "goto46");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_03"), "Cartagena_fort", "goto", "goto47");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_04"), "Cartagena_fort", "goto", "goto17");

			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto40", "check_elting_troops2", 15.0);
			break;

		case "check_elting_troops2":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_fort", "goto", "goto41");
			LAi_ActorTurnToLocator(Pchar, "goto", "goto15");
			LAi_QuestDelay("check_elting_troops3", 2.0);
			break;

		case "check_elting_troops3":
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "check_dutch_troops";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "outside_fort6":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_fort", "goto", "goto40");
			LAi_QuestDelay("outside_fort7", 1.0);
			break;

		case "outside_fort7":
			ChangeCharacterAddressGroup(CharacterFromID("Fort_Cartagena_soldier3"), "Cartagena_fort", "goto", "goto43");
			Characters[GetCharacterIndex("Fort_Cartagena_soldier3")].dialog.currentnode = "begin_55";
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto42", "outside_fort8", 10.0);
			break;

		case "outside_fort8":
			LAi_SetPlayerType(pchar);
			LAi_QuestDelay("outside_fort9", 0.5);
			break;

		case "outside_fort9":
			PlaySound("VOICE\ENGLISH\alarm1.wav");
			LAi_SetActorType(characterFromID("Fort_Cartagena_soldier3"));
			LAi_ActorDialog(characterFromID("Fort_Cartagena_soldier3"), pchar, "", 1.0, 1.0);
			break;

		case "outside_fort10":
			LAi_SetGuardianType(CharacterFromID("Fort_Cartagena_soldier3"));
			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");

			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));
			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_04"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_05"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_06"));

			LAi_group_MoveCharacter(CharacterFromID("Fort_Cartagena_soldier3"), "OUTSIDE_FORT_SOLDIER2");

			LAi_QuestDelay("outside_fort10_1", 1.0);
			break;

		case "outside_fort10_1":
			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER2", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("OUTSIDE_FORT_SOLDIER2", "outside_fort11");
			break;

		case "outside_fort11":
			CreateParticleSystemX("cancloud", -158.53, 28, -77.046, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("outside_fort12", 1.5);
			break;

		case "outside_fort12":
			CreateParticleSystemX("blast", -77.094, 21.876, -176.74, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -77.094, 21.876, -176.74, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast_inv", -77.094, 21.876, -176.74, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -77.094, 21.876, -176.74, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", -77.094, 21.876, -176.74, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", -77.094, 21.876, -176.74, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			LAi_QuestDelay("outside_fort13", 1.0);
			break;

		case "outside_fort13":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto35");
			LAi_QuestDelay("outside_fort14", 1.0);
			break;

		case "outside_fort14":
			LAi_SetActorType(CharacterFromID("bart_pirate_07"));
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_01"));
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_02"));
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_03"));
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_04"));
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_05"));
			LAi_SetActorType(CharacterFromID("Portuguese_soldier_06"));

			LAi_SetPlayerType(Pchar);
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_43";
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 1.0, 1.0);
			break;

		case "outside_fort15":
			LAi_SetActorType(CharacterFromID("Augusto Queiroz"));
			LAi_ActorRunToLocator(CharacterFromID("Augusto Queiroz"), "goto", "goto29", "_", 20.0);

			LAi_ActorRunToLocator(CharacterFromID("bart_pirate_07"), "goto", "goto33", "_", 20.0);
			LAi_ActorRunToLocator(CharacterFromID("Portuguese_soldier_01"), "goto", "goto30", "_", 20.0);
			LAi_ActorRunToLocator(CharacterFromID("Portuguese_soldier_02"), "goto", "goto39", "_", 20.0);
			LAi_ActorRunToLocator(CharacterFromID("Portuguese_soldier_03"), "goto", "goto38", "_", 20.0);
			LAi_ActorRunToLocator(CharacterFromID("Portuguese_soldier_04"), "goto", "goto31", "_", 20.0);
			LAi_ActorRunToLocator(CharacterFromID("Portuguese_soldier_05"), "goto", "goto32", "_", 20.0);
			LAi_ActorRunToLocator(CharacterFromID("Portuguese_soldier_06"), "goto", "goto37", "_", 20.0);

			LAi_QuestDelay("outside_fort16_0", 8.0);
			break;

		case "outside_fort16_0":
			ChangeCharacterAddressGroup(CharacterFromID("Fort_Cartagena_soldier1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Fort_Cartagena_soldier2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Fort_Cartagena_soldier3"), "none", "", "");

			DoQuestReloadToLocation("Cartagena_fort", "reload", "reload1", "outside_fort16_01");
			break;

		case "outside_fort16_01":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cartagena_fort", "goto", "goto29");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Cartagena_fort", "goto", "goto33");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "Cartagena_fort", "goto", "goto30");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "Cartagena_fort", "goto", "goto39");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "Cartagena_fort", "goto", "goto38");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "Cartagena_fort", "goto", "goto31");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "Cartagena_fort", "goto", "goto32");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "Cartagena_fort", "goto", "goto37");

			LAi_SetStayType(characterFromID("bart_pirate_07"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_01"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_02"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_03"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_04"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_05"));
			LAi_SetStayType(characterFromID("Portuguese_soldier_06"));

			LAi_QuestDelay("outside_fort16", 2.0);
			break;

		case "outside_fort16":
			CreateParticleSystemX("cancloud", -158.53, 28, -77.046, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("outside_fort17", 1.5);
			break;

		case "outside_fort17":
			CreateParticleSystemX("blast", -72.536, 21.691, -181.15, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -72.536, 21.691, -181.15, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast_inv", -72.536, 21.691, -181.15, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -72.536, 21.691, -181.15, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", -72.536, 21.691, -181.15, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", -72.536, 21.691, -181.15, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			LAi_QuestDelay("outside_fort18", 2.0);
			break;

		case "outside_fort18":
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_44";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "outside_fort19":
			LAi_Fade("outside_fort20", "outside_fort21");
			break;

		case "outside_fort20":
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Cartagena_fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "Cartagena_fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "Cartagena_fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "Cartagena_fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "Cartagena_fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "Cartagena_fort", "goto", "goto48");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "Cartagena_fort", "goto", "goto48");
			break;

		case "outside_fort21":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto36");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER");

			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_04"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_05"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_06"));
			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));

			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER", LAI_GROUP_PLAYER, true);

			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto49", "outside_fort22", 10.0);
			LAi_ActorFollowEverywhere(characterFromID("Augusto Queiroz"), "", 60.0);
			break;

		case "outside_fort22":
			LAi_ActorGoToLocator(PChar, "goto", "goto48", "outside_fort22_1", 10.0);
			break;

		case "outside_fort22_1":
			LAi_ActorTurnToLocator(Pchar, "goto", "goto43");
			LAi_QuestDelay("outside_fort23", 1.0);
			break;

		case "outside_fort23":
			CreateParticleSystemX("cancloud", -158.53, 28, -77.046, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("outside_fort24", 1.5);
			break;

		case "outside_fort24":
			CreateParticleSystemX("blast", -61.79,19.503,-181.46, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -61.79,19.503,-181.46, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast_inv", -61.79,19.503,-181.46, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -61.79,19.503,-181.46, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", -61.79,19.503,-181.46, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", -61.79,19.503,-181.46, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			LAi_QuestDelay("outside_fort25", 0.5);
			break;

		case "outside_fort25":
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_01"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_02"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_03"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_04"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "none", "", "");
			PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorAnimation(Pchar, "death_1", "outside_fort26", 4.0);
			break;

		case "outside_fort26":
			PostVideoAndQuest("Bartolomeu\stunned",1, "outside_fort27");
			break;

		case "outside_fort27":
			DoQuestReloadToLocation("Cartagena_fort", "goto", "goto48", "outside_fort28");
			break;

		case "outside_fort28":
			LAi_SetActorType(Pchar);
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cartagena_fort", "goto", "goto50");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Cartagena_fort", "goto", "goto51");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "Cartagena_fort", "goto", "goto52");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "Cartagena_fort", "goto", "goto53");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "Cartagena_fort", "goto", "goto54");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "Cartagena_fort", "goto", "goto55");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "Cartagena_fort", "goto", "goto56");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "Cartagena_fort", "goto", "goto35");
			GiveItem2Character(CharacterFromID("Portuguese_soldier_01"), "pistolrocket");
			EquipCharacterByItem(CharacterFromID("Portuguese_soldier_01"), "pistolrocket");
			GiveItem2Character(CharacterFromID("Portuguese_soldier_02"), "pistolrocket");
			EquipCharacterByItem(CharacterFromID("Portuguese_soldier_02"), "pistolrocket");

			LAi_ActorAnimation(Pchar, "Ground_StandUp", "outside_fort29", 3.0);
			break;

		case "outside_fort29":
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_49";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 1.0, 1.0);
			break;

		case "outside_fort30":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto36");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER3");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto36");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER3");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto36");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER3");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto36");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER3");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto36");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER3");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto36");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER3");

			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_04"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_05"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_06"));
			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));

			CreateParticleSystemX("cancloud", -158.53, 28, -77.046, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("outside_fort31", 1.5);
			break;

		case "outside_fort31":
			CreateParticleSystemX("blast", -64.481,19.653,-174.97, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -64.481,19.653,-174.97, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast_inv", -64.481,19.653,-174.97, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -64.481,19.653,-174.97, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", -64.481,19.653,-174.97, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", -64.481,19.653,-174.97, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");

			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER3", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("OUTSIDE_FORT_SOLDIER3", "outside_fort32");

			break;

		case "outside_fort32":
			PlaySound("OBJECTS\SHIPCHARGE\hurrah.wav");
			Locations[FindLocation("Cartagena_fort")].locators_radius.goto.goto75 = 2.0;
			Locations[FindLocation("Cartagena_fort")].locators_radius.goto.goto79 = 2.0;
			LAi_SetPlayerType(Pchar);
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_52";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 1.0, 1.0);
			break;

		case "outside_fort33":
			DoQuestReloadToLocation("Cartagena_fort", "goto", "goto64", "outside_fort34");
			break;

		case "outside_fort34":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cartagena_fort", "goto", "goto59");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Cartagena_fort", "goto", "goto58");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "Cartagena_fort", "goto", "goto5");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "Cartagena_fort", "goto", "goto60");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "Cartagena_fort", "goto", "goto63");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "Cartagena_fort", "goto", "goto62");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "Cartagena_fort", "goto", "goto61");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "Cartagena_fort", "goto", "goto68");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto57");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER4");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto57");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER4");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto57");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER4");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto65");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER4");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto65");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER4");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto65");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER4");

			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_04"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_05"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_06"));
			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));

			CreateParticleSystemX("cancloud", -158.53, 28, -77.046, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("outside_fort35", 1.5);
			break;

		case "outside_fort35":
			CreateParticleSystemX("blast", -96.189,23.939,-113.89, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -96.189,23.939,-113.89, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast_inv", -96.189,23.939,-113.89, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -96.189,23.939,-113.89, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", -96.189,23.939,-113.89, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", -96.189,23.939,-113.89, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");

			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER4", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("OUTSIDE_FORT_SOLDIER4", "outside_fort36");
			break;

		case "outside_fort36":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cartagena_fort", "goto", "goto71");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cartagena_fort", "goto", "goto73");
			LAi_SetImmortal(CharacterFromID("Arie Dierman"), 1);
			LAi_group_MoveCharacter(CharacterFromID("Elting"), "DUTCH_TROOPS");
			LAi_group_MoveCharacter(CharacterFromID("Arie Dierman"), "DUTCH_TROOPS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto72");
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER5");
			sld.id = "sentinel2";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto74");
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER5");
			sld.id = "sentinel3";

			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER5", "DUTCH_TROOPS", true);

			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto68", "outside_fort37", 15.0);
			break;

		case "outside_fort37":
			LAi_ActorTurnToLocator(Pchar, "goto", "goto71");
			LAi_QuestDelay("outside_fort38", 1.0);
			break;

		case "outside_fort38":
			LAi_SetPlayerType(pchar);
			CreateParticleSystemX("cancloud", -161.36, 28, -75.82, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("outside_fort39", 1.5);
			break;

		case "outside_fort39":
			CreateParticleSystemX("blast", -168.62,10.349,-166.01, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -168.62,10.349,-166.01, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast_inv", -168.62,10.349,-166.01, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -168.62,10.349,-166.01, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", -168.62,10.349,-166.01, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", -168.62,10.349,-166.01, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");

			LAi_QuestDelay("outside_fort40", 1.5);
			break;

		case "outside_fort40":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_53";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 1.0, 1.0);
			break;

		case "outside_fort41":
			AddQuestRecord("Firework", "26");

			pchar.quest.new_assault.win_condition.l1 = "locator";
			pchar.quest.new_assault.win_condition.l1.location = "Cartagena_fort";
			pchar.quest.new_assault.win_condition.l1.character = PChar.id;
			pchar.quest.new_assault.win_condition.l1.locator_group = "goto";
			pchar.quest.new_assault.win_condition.l1.locator = "goto75";
			pchar.quest.new_assault.win_condition = "outside_fort43";

			LAi_SetOfficerType(characterFromID("bart_pirate_07"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_01"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_02"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_03"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_04"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_05"));
			LAi_SetOfficerType(characterFromID("Portuguese_soldier_06"));
			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));

			CreateParticleSystemX("cancloud", -158.53, 28, -77.046, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("outside_fort42", 1.2);
			break;

		case "outside_fort42":
			CreateParticleSystemX("blast", -113.28,21.837,-109.51, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("fort_fire", -113.28,21.837,-109.51, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast_inv", -113.28,21.837,-109.51, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -113.28,21.837,-109.51, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", -113.28,21.837,-109.51, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters3", -113.28,21.837,-109.51, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			break;

		case "outside_fort43":
			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER5", "DUTCH_TROOPS", false);
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("sentinel2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("sentinel3"), "none", "", "");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto67");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER6");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto67");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER6");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto67");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER6");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto23");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER6");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto23");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER6");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto23");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER6");

			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER6", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("OUTSIDE_FORT_SOLDIER6", "outside_fort44");
			break;

		case "outside_fort44":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_SetActorType(characterFromID("bart_pirate_07"));
			LAi_ActorRunToLocator(characterFromID("bart_pirate_07"), "goto", "goto76", "outside_fort45", 30.0);
			break;

		case "outside_fort45":
			Characters[GetCharacterIndex("bart_pirate_07")].dialog.currentnode = "begin_56";
			LAi_ActorDialog(characterFromID("bart_pirate_07"), pchar, "", 1.0, 1.0);
			break;

		case "outside_fort46":
			LAi_Fade("outside_fort47", "outside_fort48");
			break;

		case "outside_fort47":
			ChangeCharacterAddressGroup(Pchar, "Cartagena_fort", "goto", "goto78");
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cartagena_fort", "goto", "goto77");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_07"), "Cartagena_fort", "goto", "goto80");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_02"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_03"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_04"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_05"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_06"), "none", "", "");
			break;

		case "outside_fort48":
			AddQuestRecord("Firework", "27");
			LAi_SetActorType(characterFromID("bart_pirate_07"));
			LAi_ActorSetLayMode(characterFromID("bart_pirate_07"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto81");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER7");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto82");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER7");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto83");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER7");

			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");

			pchar.quest.find_crewmember.win_condition.l1 = "locator";
			pchar.quest.find_crewmember.win_condition.l1.location = "Cartagena_fort";
			pchar.quest.find_crewmember.win_condition.l1.locator_group = "goto";
			pchar.quest.find_crewmember.win_condition.l1.locator = "goto79";
			pchar.quest.find_crewmember.win_condition = "outside_fort49";
			break;

		case "outside_fort49":
			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER7", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("OUTSIDE_FORT_SOLDIER7", "outside_fort50");
			break;

		case "outside_fort50":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto84", "outside_fort51", 15.0);
			break;

		case "outside_fort51":
			LAi_SetPlayerType(Pchar);

			Characters[GetCharacterIndex("bart_pirate_07")].dialog.currentnode = "begin_57";
			LAi_ActorWaitDialog(characterFromID("bart_pirate_07"), pchar);
			LAi_ActorDialog(pchar, characterFromID("bart_pirate_07"), "", 4.0, 1.0);
			break;

		case "outside_fort52":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_54";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 1.0, 1.0);
			break;

		case "outside_fort53":
			LAi_Fade("outside_fort54", "outside_fort55");
			break;

		case "outside_fort54":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cartagena_fort", "goto", "goto86");
			ChangeCharacterAddressGroup(Pchar, "Cartagena_fort", "goto", "goto85");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto4");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER8");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto21");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER8");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto19");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER8");
			break;

		case "outside_fort55":
			LAi_SetOfficerType(characterFromID("Augusto Queiroz"));

			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER8", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("OUTSIDE_FORT_SOLDIER8", "outside_fort56_0");
			break;

		case "outside_fort56_0":
			LAi_QuestDelay("outside_fort56", 3.0);
			break;

		case "outside_fort56":
			LAi_Fade("outside_fort57", "outside_fort58");
			break;

		case "outside_fort57":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cartagena_fort", "goto", "goto4");
			ChangeCharacterAddressGroup(Pchar, "Cartagena_fort", "goto", "goto85");
			break;

		case "outside_fort58":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_55";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 2.0, 1.0);
			break;

		case "outside_fort59":
			DoQuestReloadToLocation("Cartagena_fort", "goto", "goto89", "outside_fort60");
			break;

		case "outside_fort60":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cartagena_fort", "goto", "goto69");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cartagena_fort", "goto", "goto87");
			LAi_SetImmortal(CharacterFromID("Elting"), true);
			LAi_SetImmortal(CharacterFromID("Arie Dierman"), true);
			LAi_group_MoveCharacter(CharacterFromID("Elting"), "DUTCH_TROOPS");
			LAi_group_MoveCharacter(CharacterFromID("Arie Dierman"), "DUTCH_TROOPS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto90");
			LAi_SetHP(sld, 200.0, 200.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto91");
			LAi_SetHP(sld, 200.0, 200.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto88");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto88");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto70");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto70");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto92");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto92");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto92");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto93");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto93");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto93");
			LAi_SetHP(sld, 160.0, 160.0);
			sld.perks.list.BasicDefence = true;
			sld.perks.list.AdvancedDefence = true;
			sld.perks.list.SwordplayProfessional = true;
			LAi_group_MoveCharacter(sld, "OUTSIDE_FORT_SOLDIER9");

			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "bladeX4");
			GiveItem2Character(pchar, "LongRifle_BT");
			EquipCharacterByItem(pchar, "LongRifle_BT");
			TakeItemFromCharacter(CharacterFromID("Elting"), "bladeX4");
			if (!CheckCharacterItem(CharacterFromID("Elting"), "Blade_ProudOfAnvil")) GiveItem2Character(CharacterFromID("Elting"), "Blade_ProudOfAnvil");
			EquipCharacterByItem(CharacterFromID("Elting"), "Blade_ProudOfAnvil");

			LAi_group_FightGroups("OUTSIDE_FORT_SOLDIER9", "DUTCH_TROOPS", true);
			LAi_group_SetCheck("OUTSIDE_FORT_SOLDIER9", "outside_fort61");
			break;

		case "outside_fort61":
			LAi_QuestDelay("outside_fort62", 3.0);
			break;

		case "outside_fort62":
			DoQuestReloadToLocation("Cartagena_fort", "goto", "goto24", "outside_fort63");
			break;

		case "outside_fort63":
			EquipCharacterByItem(Pchar, BLADE_ITEM_TYPE);
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cartagena_fort", "goto", "goto4");
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cartagena_fort", "goto", "goto85");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cartagena_fort", "goto", "goto86");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_01"), "Cartagena_fort", "goto", "goto21");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_02"), "Cartagena_fort", "goto", "goto25");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "Cartagena_fort", "goto", "goto19");
			LAi_SetActorType(characterFromID("Arie Dierman"));
			LAi_SetActorType(characterFromID("Dutch_soldier_01"));
			LAi_SetActorType(characterFromID("Dutch_soldier_02"));
			LAi_SetActorType(characterFromID("Portuguese_soldier_01"));

			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_147";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "outside_fort64":
			RemoveCharacterCompanion(Pchar, characterFromID("Elting"));
			setCharacterShipLocation(characterFromID("Elting"), "none");
			LAi_SetActorType(characterFromID("Arie Dierman"));
			Characters[GetCharacterIndex("Arie Dierman")].dialog.currentnode = "begin_13";
			LAi_ActorDialog(characterFromID("Arie Dierman"), pchar, "", 2.0, 1.0);
			break;

		case "outside_fort65":
			DoQuestReloadToLocation("Cartagena_fort", "goto", "goto73", "outside_fort66");
			break;

		case "outside_fort66":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cartagena_fort", "goto", "goto74");
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "none", "", "");

			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_148";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 2.0, 1.0);
			break;

		case "outside_fort67":
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_01"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_soldier_02"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Portuguese_soldier_01"), "none", "", "");
			LAi_ActorTurnToLocator(characterFromID("Elting"), "goto", "goto86");
			LAi_QuestDelay("outside_fort68", 2.0);
			break;

		case "outside_fort68":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(pchar, "goto", "goto86");
			LAi_QuestDelay("outside_fort69", 3.0);
			break;

		case "outside_fort69":
			CreateParticleSystemX("blast", -151.02,33.5,-71.914, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("blast_inv", -151.02,33.5,-71.914, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -151.02,33.5,-71.914, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			LAi_QuestDelay("outside_fort70", 1.5);
			break;

		case "outside_fort70":
			CreateParticleSystemX("blast", -158.51,33.0,-81.302, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("blast_inv", -158.51,33.0,-81.302, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -158.51,33.0,-81.302, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			LAi_QuestDelay("outside_fort71", 1.5);
			break;

		case "outside_fort71":
			CreateParticleSystemX("blast", -151.02,33.5,-71.914, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("blast_inv", -151.02,33.5,-71.914, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -151.02,33.5,-71.914, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			LAi_QuestDelay("outside_fort71_1", 1.5);
			break;

		case "outside_fort71_1":
			CreateParticleSystemX("blast", -158.51,36.0,-81.302, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("blast_inv", -158.51,36.0,-81.302, -1.57, 0.0, 0.0,0);
			CreateParticleSystem("ball_impact", -158.51,36.0,-81.302, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_003.wav");
			LAi_QuestDelay("outside_fort72", 3.0);
			break;

		case "outside_fort72":
			DeleteAttribute(pchar, "NoSave.Custom"); // PB: Re-enable saving
			DoQuestReloadToLocation("Cabin2", "rld", "aloc2" ,"back_grenade");
			break;

		case "back_grenade":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "Cabin2", "rld", "loc6");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "Cabin2", "rld", "aloc3");

			LAi_SetActorType(characterFromID("Elting"));
			Characters[GetCharacterIndex("Elting")].dialog.currentnode = "begin_149";
			LAi_ActorDialog(characterFromID("Elting"), pchar, "", 4.0, 1.0);
			break;

		case "back_grenade2":
			LAi_Fade("back_grenade3", "back_grenade4");
			break;

		case "back_grenade3":
			ChangeCharacterAddressGroup(CharacterFromID("Elting"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arie Dierman"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Cabin2", "rld", "loc0");
			break;

		case "back_grenade4":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_59";
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 5.0, 1.0);
			break;

		case "back_grenade5":
			LAi_Fade("back_grenade6", "back_grenade7");
			break;

		case "back_grenade6":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Cabin2", "rld", "loc0");
			break;

		case "back_grenade7":
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_90";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 5.0, 1.0);
			break;

		case "back_grenade8":
			LAi_Fade("back_grenade9", "back_grenade10");
			break;

		case "back_grenade9":
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Lucia Montavez"), "Cabin2", "rld", "loc0");
			break;

		case "back_grenade10":
			LAi_SetActorType(characterFromID("Lucia Montavez"));
			Characters[GetCharacterIndex("Lucia Montavez")].dialog.currentnode = "begin_31";
			LAi_ActorDialog(characterFromID("Lucia Montavez"), pchar, "", 5.0, 1.0);
			break;

		case "back_grenade11":
			SetRMRelation(PChar, SPAIN, REL_AMNESTY);
			SetCharacterRelationBoth(GetCharacterIndex("Cartagena Commander"), GetMainCharacterIndex(), RELATION_FRIEND);
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			SetCharacterShipLocation(Pchar, "Cartagena_Port");
			GiveShip2Character(Pchar,"SP_BattleGalleon","San Martin",-1,SPAIN,true,true);
			GiveShip2Character(CharacterFromID("Augusto Queiroz"),"Galeon50","Reina Isabella",-1,SPAIN,true,true);
			SetCompanionIndex(Pchar, 1, GetCharacterIndex("Augusto Queiroz"));
			SetCharacterRemovable(characterFromID("Augusto Queiroz"), false);

			Island_SetReloadEnableLocal("Colombia", "reload_1", false);
			Islands[FindIsland("Colombia")].reload.l1.goto_enable = false;
			LAi_QuestDelay("back_grenade12", 1.0);
			break;

		case "back_grenade12":
			AddQuestRecord("Firework", "28");
			QuestToSeaLogin_PrepareLoc("Colombia", "reload", "reload_1", true);
			QuestToSeaLogin_Launch();

			Pchar.quest.finish_cartagena.win_condition.l1 = "location";
			Pchar.quest.finish_cartagena.win_condition.l1.location = "Conceicao_port";
			Pchar.quest.finish_cartagena.win_condition = "back_grenade13";
			break;

		case "back_grenade13":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "Conceicao_port", "goto", "goto11");
			Characters[GetCharacterIndex("Augusto Queiroz")].dialog.currentnode = "begin_60";
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			LAi_ActorDialog(characterFromID("Augusto Queiroz"), pchar, "", 5.0, 1.0);
			break;

		case "back_grenade14":
			LAi_SetActorType(characterFromID("Augusto Queiroz"));
			LAi_ActorRunToLocation(characterFromID("Augusto Queiroz"), "reload", "reload1", "none", "", "", "back_grenade15", 5.0);
			break;

		case "back_grenade15":
			RemoveCharacterCompanion(Pchar, characterFromID("Augusto Queiroz"));
			setCharacterShipLocation(characterFromID("Augusto Queiroz"), "none");
			Characters[GetCharacterIndex("Jacinto Arcibaldo Barreto")].dialog.currentnode = "gov_64";
			break;

		case "back_grenade16":
			ChangeCharacterAddressGroup(CharacterFromID("Augusto Queiroz"), "none", "", "");
			AddLandToCharacter(&Pchar, "Conceicao", PORTUGAL, 50);
			GiveShip2Character(Pchar,"PiratBattleGalleon","New Santiago",-1,PORTUGAL,true,true);
			setCharacterShipLocation(Pchar, "Conceicao_port");
			Island_SetReloadEnableLocal("Colombia", "reload_1", true);
			Islands[FindIsland("Colombia")].reload.l1.goto_enable = true;
			SetRMRelation(PChar, SPAIN, REL_WAR);
			SetCharacterRelationBoth(GetCharacterIndex("Cartagena Commander"), GetMainCharacterIndex(), RELATION_ENEMY);
			Locations[FindLocation("Cartagena_port")].dangerous = true;
			AddQuestRecord("Firework", "29");
			CloseQuestHeader("Firework");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			break;

			//-----------------------------------------------------------------------------------------------------
			//boulder chase	experiment

		case "boulder_start":
			//START IN LOOP

			LAi_SetStayType(pchar);			//a little break is needed for the new animation to get activated
			SetModel(Pchar, pchar.model, "fast_man", "man", 1.8, true);

			PlaySound("OBJECTS\boulder_start.wav");
			//PlaySound("OBJECTS\boulder_start.wav"); // PB: Why twice?
			LAi_SetOfficerType(CharacterFromID("boulder"));
			float x1, y1, z1;
			float x2, y2, z2;
			float dist;

			CreateParticleSystem("splinters", 5.2, 1.3, 7.9, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", 5.2, 1.3, 7.9, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters", 5.2, 0.7, 7.9, 0.0, 0.0, 0.0, 0);
			CreateParticleSystem("splinters2", 5.2, 0.7, 7.9, 0.0, 0.0, 0.0, 0);

			LAi_QuestDelay("reset_playertype", 0.1);
			LAi_QuestDelay("boulder_distance", 0.1);
			LAi_QuestDelay("boulder_sounds", 0.1);
			LAi_QuestDelay("boulder_particles", 0.1);

			//test only
			pchar.quest.reset_run_speed.win_condition.l1 = "locator";
			pchar.quest.reset_run_speed.win_condition.l1.location = "boulder_tunnel";
			pchar.quest.reset_run_speed.win_condition.l1.locator_group = "goto";
			pchar.quest.reset_run_speed.win_condition.l1.locator = "skel27";
			pchar.quest.reset_run_speed.win_condition = "reset_run_speed";
			break;

		case "reset_playertype":
			LAi_SetPlayerType(pchar);
			break;

		case "reset_run_speed":
			LAi_SetStayType(pchar);
			SetModel(Pchar, pchar.model, "man", "man", 1.8, true);

			LAi_QuestDelay("reset_playertype", 0.1);
			break;

		case "boulder_distance":
			GetCharacterPos(Pchar, &x1, &y1, &z1);
			GetCharacterPos(CharacterFromID("boulder"), &x2, &y2, &z2);
			dist = GetDistance2D(x2, z2, x1, z1);

			if(dist < 2.0)
			{
				PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
				Lai_KillCharacter(pchar);

				LAi_QuestDelay("church_cave_no_reinc", 0.1);

				//LAi_QuestDelay("boulder_distance", 1.0);
			}
			else LAi_QuestDelay("boulder_distance", 1.0);
			break;

		case "boulder_sounds":
			PlaySound("OBJECTS\boulder_roll.wav");
			PlaySound("OBJECTS\boulder_rumble.wav");

			LAi_QuestDelay("boulder_sounds", 8.0);
			break;

		case "boulder_particles":
			GetCharacterPos(CharacterFromID("boulder"), &x2, &y2, &z2);
			CreateParticleSystemX("blast_dirt", x2, y2, z2, x2, y2, z2,10);
			CreateParticleSystemX("blast_dirt", x2, y2, z2, x2, y2, z2,10);

			LAi_QuestDelay("boulder_particles", 1.0);
			break;

		case "maquahuitl_test":
			LAi_ActorAttack(CharacterFromID("maquahuitl_enemy1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("maquahuitl_enemy2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("maquahuitl_enemy3"), PChar, "");
			LAi_ActorAttack(CharacterFromID("rocket_enemy1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("rocket_enemy2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("rocket_enemy3"), PChar, "");
			break;

		case "skull_ring_hp":
			if(CheckAttribute(Pchar,"skull_ring") && Pchar.skull_ring == "on")
			{
				LAi_ApplyCharacterDamage(Pchar, 1);

				LAi_QuestDelay("skull_ring_hp", 1.0);
			}
			break;

		case "skull_ring_release":
			if(!IsEquipCharacterByItem(Pchar, "skull_ring"))
			{
				PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			}
			break;

		case "skull_ring_equip":
			if(IsEquipCharacterByItem(Pchar, "skull_ring"))
			{
				PlaySound("OBJECTS\VOICES\DEAD\male\dead4.wav");
				Logit(TranslateString("","This Ring is eating all my Power!"));
			}
			break;

		case "moccasins_equip":
			if(IsEquipCharacterByItem(Pchar, "moccasins"))
			{
				PlaySound("VOICE\ENGLISH\Por_m_b_046.wav");
			}
			break;

		case "filled_pipe_equip":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Logit(TranslateString("","Now I only need Fire."));
			break;

		case "smoking_mushrooms0":
			PauseAllSounds();//stops music
			break;

		case "smoking_mushrooms4":
			PlaySound("MUSIC\Claire_theme_short.wav");
			break;

		case "smoking_mushrooms1":
			GetCharacterPos(Pchar, &x1, &y1, &z1);
			CreateParticleSystem("gunfire" , x1, y1+1.0, z1, 5.1, 4.0, 0.0, sti(20) );
			PlaySound("AMBIENT\JAIL\sigh.wav");

			LAi_QuestDelay("smoking_mushrooms2", 5.0);
			LAi_QuestDelay("smoking_mushrooms6", 4.0);
			break;

		case "smoking_mushrooms6":
			PlaySound("PEOPLE\yawn.wav");
			break;

		case "smoking_mushrooms2":
			GetCharacterPos(Pchar, &x1, &y1, &z1);
			CreateParticleSystem("gunfire" , x1, y1+1.0, z1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , x1, y1+1.0, z1, 5.1, 4.0, 0.0, sti(20) );

			LAi_QuestDelay("smoking_mushrooms3", 3.0);
			LAi_QuestDelay("smoking_mushrooms5", 3.0);
			break;

		case "smoking_mushrooms5":
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			PlaySound("PEOPLE\recoil.wav");
			LAi_SetPoorType(Pchar);
			break;

		case "smoking_mushrooms3":
			GetCharacterPos(Pchar, &x1, &y1, &z1);
			CreateParticleSystem("gunfire" , x1, y1+0.5, z1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , x1, y1+0.5, z1, 5.1, 4.0, 0.0, sti(20) );

			LAi_QuestDelay("smoking_mushrooms3A", 2.5);
			LAi_QuestDelay("smoking_mushrooms3A", 5.0);
			LAi_QuestDelay("smoking_mushrooms3B", 7.5);
			LAi_QuestDelay("smoking_mushrooms3A", 10.0);
			LAi_QuestDelay("smoking_mushrooms3B", 11.7);
			LAi_QuestDelay("smoking_mushrooms3C", 13.4);
			LAi_QuestDelay("smoking_mushrooms3A", 15.0);
			LAi_QuestDelay("smoking_mushrooms3B", 16.25);
			LAi_QuestDelay("smoking_mushrooms3C", 17.5);
			LAi_QuestDelay("smoking_mushrooms3B", 18.75);

			LAi_QuestDelay("smoking_mushrooms8", 24.0);
			break;

		case "smoking_mushrooms3A":
			GetCharacterPos(Pchar, &x1, &y1, &z1);
			CreateParticleSystem("gunfire" , x1, y1+0.5, z1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , x1, y1+0.5, z1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , x1, y1+0.5, z1, 5.1, 4.0, 0.0, sti(20) );
			break;

		case "smoking_mushrooms3B":
			GetCharacterPos(Pchar, &x1, &y1, &z1);
			CreateParticleSystem("gunfire" , x1+0.5, y1+0.5, z1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , x1, y1+0.5, z1+0.5, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , x1-0.5, y1+0.5, z1-0.5, 5.1, 4.0, 0.0, sti(20) );
			break;

		case "smoking_mushrooms3C":
			GetCharacterPos(Pchar, &x1, &y1, &z1);
			CreateParticleSystem("gunfire" , x1-0.5, y1+0.5, z1, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , x1, y1+0.5, z1-0.5, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("gunfire" , x1+0.5, y1+0.5, z1+0.5, 5.1, 4.0, 0.0, sti(20) );
			break;

		case "smoking_mushrooms8":
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "mushroom_vision";
			LAi_ActorSelfDialog(pchar, "");
			break;

		case "smoking_mushrooms9":
			//ev. add questbook info here

			LAi_SetPlayerType(Pchar);
			PostEvent("LoadSceneSound", 0);
			break;

		case "antidote_test":
			Pchar.chr_ai.poison =  300;
			break;

		//-----------------------------------------------------------------------------------------------------
		PChar.questnotfound = true; // PB: Testing
	}
}
