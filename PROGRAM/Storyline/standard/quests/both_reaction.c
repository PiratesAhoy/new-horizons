void BothQuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld;
	PChar = GetMainCharacter();
	int lngSeaGoodsFileID = LanguageOpenFile("ShipEatGood.txt");
// KK -->
	int i;
	int iNation = 0;
	string QDeck = "";

	string loadPort = "";
	string loadTown = "";
	string loadTavern = "";
	string loadStore = "";
	string loadShipyard = "";
	string questRecord = "_";
	string rldLocator = "";
	string gotoLocator = "";
	string sitLocator = "";
	string gotoGroup = "";
	string goLocator = "";
// <-- KK

// PB -->
	ref TutDeck = &Locations[FindLocation("Tutorial_Deck")];
	string playerBlade = "";
	string playerGun = "";
// PB <--

	//trace ("ПРОВЕРЯЕТСЯ КВЕСТ " + sQuestName);
	switch(sQuestName)
	{

		////////////////////////////////////////////////////////////////////////
		//  Квест про проклятые монетки
		////////////////////////////////////////////////////////////////////////

		case "Story_CursedCoinsStarted":
			GiveItem2Character(PChar,"Chest");

			Locations[FindLocation("Redmond_town_01")].locators_radius.goto.goto17 = 5.0;

			ChangeCharacterAddressGroup(CharacterFromID("Cursed_Pirate_01"), "Redmond_town_01", "goto", "goto54");
			ChangeCharacterAddressGroup(CharacterFromID("Cursed_Pirate_02"), "Redmond_town_01", "goto", "goto55");
			
			PChar.quest.Story_CursedCoinsEncounter.win_condition.l1 = "locator";
			PChar.quest.Story_CursedCoinsEncounter.win_condition.l1.location = "Redmond_town_01";
			PChar.quest.Story_CursedCoinsEncounter.win_condition.l1.locator_group = "goto";
			PChar.quest.Story_CursedCoinsEncounter.win_condition.l1.locator = "goto17";
			PChar.quest.Story_CursedCoinsEncounter.win_condition = "Story_CursedCoinsEncounter";
		break;

		case "Story_CursedCoinsEncounter":
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_01"));
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_02"));
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Cursed_Pirate_01"));
			LAi_ActorWaitDialog(PChar, CharacterFromID("Cursed_Pirate_01"));
			LAi_ActorDialog(CharacterFromID("Cursed_Pirate_01"), PChar, "", 20.0, 1.0);
			LAi_ActorFollow(CharacterFromID("Cursed_Pirate_02"), PChar, "", 30.0);
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_01"), "CURSED_PIRATES");
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_02"), "CURSED_PIRATES");

			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
		break;

		case "Story_CursedCoinsGiveOutChest":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_01"));
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_02"));
			Characters[GetCharacterIndex("Cursed_Pirate_01")].location = "None";
			Characters[GetCharacterIndex("Cursed_Pirate_02")].location = "None";
			LAi_ActorRunToLocation(CharacterFromID("Cursed_Pirate_01"), "Reload", "Reload_2_4_back", "None", "", "", "", 120);
			LAi_ActorRunToLocation(CharacterFromID("Cursed_Pirate_02"), "Reload", "Reload_2_4_back", "None", "", "", "", 120);

			LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		break;

		case "Story_CursedCoinsFirstFightWithPirates":
			LAi_SetPlayerType(PChar);
			LAi_QuestDelay("Story_CursedCoinsImmortalPirates", 7.0);
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_01"), "CURSED_PIRATES");
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_02"), "CURSED_PIRATES");
			LAi_group_FightGroups("CURSED_PIRATES", LAI_GROUP_PLAYER, true);
		break;

		case "Story_CursedCoinsImmortalPirates":
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_01"));
			LAi_SetActorType(CharacterFromID("Cursed_Pirate_02"));

			LAi_type_actor_Reset(CharacterFromID("Cursed_Pirate_01"));
			LAi_type_actor_Reset(CharacterFromID("Cursed_Pirate_02"));

			Characters[GetCharacterIndex("Cursed_Pirate_01")].Dialog.CurrentNode = "We_are_immortal";
			LAi_ActorWaitDialog(PChar, CharacterFromID("Cursed_Pirate_01"));
			LAi_ActorDialog(CharacterFromID("Cursed_Pirate_01"), PChar, "Story_CursedCoinsCloseQuestMovie", 20.0, 1.0);
		break;

		case "Story_CursedCoinsCloseQuestMovie":
			EndQuestMovie();TrackQuestMovie("end","Story_CursedCoinsCloseQuestMovie");
		break;

		case "Story_CursedCoinsFightPiratesAgain":
			StartQuestMovie(true, true, false);TrackQuestMovie("start","Story_CursedCoinsFightPiratesAgain");
			LAi_SetPlayerType(PChar);
			PChar.quest.disable_rebirth = true; // PB
			Characters[getCharacterIndex("Cursed_Pirate_01")].skill.fencing = 10;
			Characters[getCharacterIndex("Cursed_Pirate_02")].skill.fencing = 10;
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_01"), "CURSED_PIRATES");
			LAi_group_MoveCharacter(CharacterFromID("Cursed_Pirate_02"), "CURSED_PIRATES");
			LAi_group_FightGroups("CURSED_PIRATES", LAI_GROUP_PLAYER, true);
		break;

		case "Seen_Black_Pearl":
			Log_SetStringToLog(QUEST_MESSAGE7);

			Group_CreateGroup("Big Boss");
			Group_AddCharacter("Big Boss", "Barbossa");
			Group_SetGroupCommander("Big Boss", "Barbossa");
			Group_SetPursuitGroup("Big Boss", PLAYER_GROUP);
			Group_SetAddress("Big Boss", "FalaiseDeFleur", "", "");
			Group_SetTaskMove("Big Boss", 10000, 10000);
			Group_LockTask("Big Boss");

			SetCharacterRelationBoth(GetCharacterIndex("Barbossa"),GetMainCharacterIndex(),RELATION_FRIEND);
// KK -->
			// prevent companions from attacking Black Pearl (for now)
			for(i = 0; i < COMPANION_MAX; i++) {
				if (GetCompanionIndex(PChar, i) >= 0 && GetRemovable(GetCharacter(GetCompanionIndex(PChar, i))))
				{
					SetCharacterRelationBoth(GetCharacterIndex("Barbossa"),GetCompanionIndex(PChar, i),RELATION_FRIEND);
				}
			}
// <-- KK

// KK -->
			PChar.previous_relation = GetRMRelation(PChar, PIRATE);
			PChar.previous_flag = GetCurrentFlag();
			SetRMRelation(PChar, PIRATE, REL_NEUTRAL);
			HoistFlag(PERSONAL_NATION); // PB: Otherwise the below doesn't work

			iForceDetectionFalseFlag = -1;
// <-- KK

			// PB: Disabled because this triggers TOO EARLY when using DirectSail -->
		//	PChar.quest.seen_black_pearl_away1.win_condition.l1 = "MapEnter";
		//	PChar.quest.seen_black_pearl_away1.win_condition = "seen_black_pearl_away";
			// PB: Disabled because this triggers TOO EARLY when using DirectSail <--

			PChar.quest.seen_black_pearl_away2.win_condition.l1 = "location";
			PChar.quest.seen_black_pearl_away2.win_condition.l1.location = "Falaise_De_Fleur_port_01";
			PChar.quest.seen_black_pearl_away2.win_condition = "seen_black_pearl_away";

			PChar.quest.seen_black_pearl_away3.win_condition.l1 = "location";
			PChar.quest.seen_black_pearl_away3.win_condition.l1.location = "Falaise_de_fleur_shore";
			PChar.quest.seen_black_pearl_away3.win_condition = "seen_black_pearl_away";
		break;

		case "seen_black_pearl_away":
// KK -->
			HoistFlag(sti(PChar.previous_flag));
			SetRMRelation(PChar, PIRATE, stf(PChar.previous_relation));
			iForceDetectionFalseFlag = 0;
			DeleteAttribute(PChar, "previous_relation");
			DeleteAttribute(PChar, "previous_flag");
// <-- KK
			PChar.quest.seen_black_pearl_away2.over = "yes";
			PChar.quest.seen_black_pearl_away3.over = "yes";
			Group_SetAddress("Big Boss", "none", "", "");
			PChar.quest.seen_black_pearl_away1.over = "yes";
			PChar.quest.seen_black_pearl_away2.over = "yes";
			PChar.quest.seen_black_pearl_away3.over = "yes";
		break;

		case "about_ruby":
			PChar.quest.Carpenter.over = "yes";
			PChar.quest.Carpenter1.over = "yes";

			SetCharacterToNearLocatorFromMe("Gordon Carpenter", 10);
			LAi_SetActorType(CharacterFromID("Gordon Carpenter"));
			LAi_ActorDialog(CharacterFromID("Gordon Carpenter"), PChar, "", 1.0, 1.0);
		break;

		case "talk_about_ruby":
			LAi_Fade("talk_about_ruby1", "talk_about_ruby2");
		break;

		case "talk_about_ruby1":
			DoQuestReloadToLocation("Falaise_De_Fleur_tavern", "sit", "sit4", "_");
			ChangeCharacterAddressGroup(CharacterFromID("Gordon Carpenter"), "Falaise_De_Fleur_tavern", "sit", "sit8");
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(PChar);
			LAi_SetActorType(CharacterFromID("Gordon Carpenter"));
			LAi_ActorSetSitMode(CharacterFromID("Gordon Carpenter"));
		break;

		case "talk_about_ruby2":
			Lai_ActorWaitDialog(PChar, CharacterFromID("Gordon Carpenter"));
			LAi_ActorDialog(CharacterFromID("Gordon Carpenter"), PChar, "", 1.0, 1.0);
		break;

		case "Story_CursedCoinsFinished":
			LAI_SetPlayerType(PChar);
			DoReloadCharacterToLocation("Falaise_De_Fleur_tavern", "goto", "goto3");
			Characters[GetCharacterIndex("Gordon Carpenter")].location = "None";

			SafePortLeave(GetCurrentLocationNation(), false); // KK

			CloseQuestHeader("chest");
		break;

		case "Story_CursedCoinsShit":
			Lai_SetActorType(CharacterFromID("Henry Peat"));
			LAi_ActorSetSitMode(CharacterFromID("Henry Peat"));
		break;

		case "Story_CursedCoinsPeatSilent":
			AddQuestRecord("Chest", 6);
			LAi_CharacterDisableDialog(CharacterFromID("Henry Peat"));
		break;

		// NK 05-07-14 to disable model selection while in tut -->
		case "EnableModelSelect":
			DeleteAttribute(&PChar, "DisableModelSelect");
			break;

// KK ----- Start Adventure -->

		case "StartAdventure":
			if(CheckQuestAttribute("Tut_start", "complete")) break;
			if(PChar.location=="Tutorial_Deck") break;

			PChar.Quest.Tut_Start.over = "yes";
			PChar.quest.Tut_start = "complete";
			PostVideoAndQuest("Invasion",1,"After_French_Invasion_Of_Oxbay");
		break;

		case "After_French_Invasion_Of_Oxbay":
			characters[GetCharacterIndex("John Clifford Brin")].Dialog.Filename = "Robert Christopher Silehard_dialog.c";
			ChangeCharacterAddressGroup(CharacterFromID("John Clifford Brin"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Robert Christopher Silehard"), "Redmond_Residence", "goto", "goto8");
			Towns[GetTownIndex("Redmond")].gov = "Robert Christopher Silehard";
			characters[GetCharacterIndex("Robert Christopher Silehard")].Dialog.CurrentNode = "AtRedmondAfterInvasion";

   //JRH ammo mod --->
			if(ENABLE_AMMOMOD)
			{	// LDH change
				TutDeck.WeaponsLocker.items.gunpowder = 6;
				TutDeck.WeaponsLocker.items.pistolbullets = 6;

				if(CheckCharacterItem(PChar, "gunpowder") > 0) TakeNItems(PChar, "gunpowder", -12);
				else TakeNItems(PChar, "gunpowder", 6);
				if(CheckCharacterItem(PChar, "pistolbullets") > 0) TakeNItems(PChar, "pistolbullets", -12);
				else TakeNItems(PChar, "pistolbullets", 6);
			}
   //JRH ammo mod <---

			Locations[FindLocation("Redmond_port")].locators_radius.goto.goto18 = 3.0;

			PChar.quest.StartAdventure = "begin";

			LAi_QuestDelay("Tut_start", 0.0);
			LAi_QuestDelay("begining", 0.0);

			SetQuestHeader("EscapedFromOxbay");
			AddQuestRecord("EscapedFromOxbay", 1);
			CloseQuestHeader("EscapedFromOxbay");

			LAi_SetPlayerType(PChar);

			trace("Started without tutorial.");
		break;
// <-- KK

//Tutorial

		case "Tut_start":
			if(CheckAttribute(PChar,"quest.Tut_start") && PChar.quest.Tut_start=="complete") break;//MAXIMUS
// KK -->
			PChar.quest.Tut_start.over = "yes";
			PChar.quest.Tut_start = "complete";
			PChar.quest.StartAdventure = "complete";

			if(characters[GetCharacterIndex("Malcolm Hatcher")].location!="none" && PChar.location=="Tutorial_deck") break;//MAXIMUS
// <-- KK

			PChar.quest.tutorial.Spyglass = 1;
			PChar.alwaysshowitems.SpyGlass2 = true; // fix for quest items like spyglass2. 05-04-21

			//StartQuestMovie(true, false, false);
// KK -->
			int questRec = 2;
			if(PChar.location=="Tutorial_deck")//MAXIMUS
			{
				questRec = 1;
				characters[GetCharacterIndex("John Clifford Brin")].Dialog.Filename = "Robert Christopher Silehard_dialog.c";
				ChangeCharacterAddressGroup(CharacterFromID("John Clifford Brin"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("Robert Christopher Silehard"), "Redmond_Residence", "goto", "goto8");
				Towns[GetTownIndex("Redmond")].gov = "Robert Christopher Silehard";

				PChar.DisableModelSelect = true;
				PChar.quest.EnableModelSelect.win_condition.l1 = "ExitFromLocation";
				PChar.quest.EnableModelSelect.win_condition.l1.location = PChar.location;
				PChar.quest.EnableModelSelect.win_condition = "EnableModelSelect";
				// NK <--
//				SetNextWeather("Blue Sky"); //JRH //MAXIMUS: we came to this port with storm, right?
				SetNextWeather("Heavy Rain");	// LDH for new weather system, ignored by old system - 26Feb09

				locDisableUpdateTime = true;

				playerBlade = PChar.start_weapon.blade;
				RemoveCharacterEquip(PChar, BLADE_ITEM_TYPE );
				switch (GetCharacterShipCabin(PChar))
				{
					case "Cabin_none":
						ChangeCharacterAddressGroup(CharacterFromID("Malcolm Hatcher"), "Tutorial_Deck", "goto", "goto2");
						if(playerBlade != "") TutDeck.box1.items.(playerBlade) = 1;
					break;
					case "Tutorial_Deck":
						ChangeCharacterAddressGroup(CharacterFromID("Malcolm Hatcher"), "Tutorial_Deck", "goto", "goto2");
					break;
					// default
					ChangeCharacterAddressGroup(CharacterFromID("Malcolm Hatcher"), "Tutorial_Deck", "reload", "reload1");
					if(playerBlade != "") TutDeck.box1.items.(playerBlade) = 1;
				}
				TutDeck.reload.l1.disable = true;
// <-- KK

				LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
				LAi_group_MoveCharacter(CharacterFromID("Malcolm Hatcher"), "tutorial");
				LAi_group_SetAlarmReaction("tutorial", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY);
				LAi_SetImmortal(CharacterFromID("Malcolm Hatcher"), false);
// KK -->
				if (GetCharacterShipCabin(PChar) == "Cabin_none")
					Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "OnMalcolmShip";
				else
					Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "start";
// <-- KK
				RemoveCharacterEquip(PChar, GUN_ITEM_TYPE );
				playerGun   = PChar.start_weapon.gun;
				if(playerGun != "")
					locations[FindLocation(PChar.location)].box1.items.(playerGun) = 1;
				locations[FindLocation(PChar.location)].box1.items.spyglass1 = 1;

				TutDeck.box1.items.medical1 = 2; // PB
				TutDeck.box1.money = 1000;
				TutDeck.box1.items.relationbook = 1; // PB
				if(ENABLE_AMMOMOD)
				{
					TutDeck.WeaponsLocker.items.gunpowder = 6;
					TutDeck.WeaponsLocker.items.pistolbullets = 6;

					if(CheckCharacterItem(PChar, "gunpowder") > 0) TakeNItems(PChar, "gunpowder", -12);
					if(CheckCharacterItem(PChar, "pistolbullets") > 0) TakeNItems(PChar, "pistolbullets", -12);
					locations[FindLocation(PChar.location)].box1.items.gunpowder = 6;
					locations[FindLocation(PChar.location)].box1.items.pistolbullets = 6;
				}

				DeleteAttribute(TutDeck, "box2.items"); // JRH

				PChar.quest.Tut_KillTutor.win_condition.l1 = "NPC_Death";
				PChar.quest.Tut_KillTutor.win_condition.l1.character = "Malcolm Hatcher";
				PChar.quest.Tut_KillTutor.win_condition = "Tut_KillTutor";
			}

			TutDeck.box1 = Items_MakeTime(0, 0, 1, 2003);

// added by MAXIMUS [choose character mod] -->
// KK -->
			loadPort = "Oxbay_port";
			loadTown = "Oxbay_town";
			loadTavern = "Oxbay_tavern";
			loadStore = "Oxbay_store";
			loadShipyard = "Oxbay_shipyard";
			questRecord = "Tutorial_AppearedOnIsland";
			rldLocator = "reload2";
			gotoLocator = "goto18";
			sitLocator = "sit5";
// <-- KK
			switch(GetCurrentFlag())
			{
				case ENGLAND: 
					loadPort = "Oxbay_port";
					gotoLocator = "goto18";
					Preprocessor_AddQuestData("island", FindTownName("Oxbay")); // KK
				break;
				case FRANCE: 
					loadPort = "Falaise_de_fleur_port_01";
					gotoLocator = "goto18";
					Preprocessor_AddQuestData("island", FindTownName("Falaise de Fleur")); // KK
				break;
				case SPAIN: 
					loadPort = "Muelle_port";
					gotoLocator = "goto6";
					Preprocessor_AddQuestData("island", FindTownName("Isla Muelle")); // KK
				break;
				case PIRATE: 
					loadPort = "QC_port";
					gotoLocator = "goto18";
					Preprocessor_AddQuestData("island", FindTownName("Quebradas Costillas")); // KK
					TakeNItems(CharacterFromID("Kate Blowhorn"), "spyglass2", 1); // Etharos remove Peter to replace by Kate
				break;
				case HOLLAND: 
					loadPort = "Douwesen_port";
					gotoLocator = "goto15";
					Preprocessor_AddQuestData("island", FindTownName("Douwesen")); // KK
				break;
				case PORTUGAL: 
					loadPort = "Conceicao_port";
					gotoLocator = "goto13";
					Preprocessor_AddQuestData("island", FindTownName("Conceicao")); // KK
				break;
				case AMERICA: 
					loadPort = "Eleuthera_Port";
					gotoLocator = "goto10";
					Preprocessor_AddQuestData("island", FindTownName("Eleuthera")); // KK
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					loadPort = "Oxbay_port";
					gotoLocator = "goto18";
					Preprocessor_AddQuestData("island", FindTownName("Oxbay")); // KK
				// TIH <--
			}
			Locations[FindLocation(loadPort)].locators_radius.goto.(gotoLocator) = 3.0;
			SetQuestHeader(questRecord);
			AddQuestRecord(questRecord, 1);
			//Preprocessor_Remove("island"); // KK
// added by MAXIMUS [choose character mod] <--

			PChar.quest.Tut_KillTutor.win_condition.l1 = "NPC_Death";
			PChar.quest.Tut_KillTutor.win_condition.l1.character = "Malcolm Hatcher";
			PChar.quest.Tut_KillTutor.win_condition = "Tut_KillTutor";

// KK -->
			if(PChar.location=="Tutorial_deck")//MAXIMUS
			{
				trace("Started with tutorial.");

				LAi_SetActorType(PChar);
				LAi_SetActorType(CharacterFromID("Malcolm Hatcher"));
				if (GetCharacterShipCabin(PChar) == "Cabin_none")
					LAi_ActorFollow(PChar, CharacterFromID("Malcolm Hatcher"), "", -1);
				else
					LAi_ActorWaitDialog(PChar, CharacterFromID("Malcolm Hatcher"));
				LAi_ActorFollow(CharacterFromID("Malcolm Hatcher"), PChar, "DialogWithMalcolmStart", -1);
			}
			else
			{
				LAi_QuestDelay("TavernSitWaiting", 0.0);
				
				AddMoneyToCharacter(PChar, 1000);
				TakeNItems(PChar, "spyglass2", 1);
				TakeNItems(PChar, "medical1", 2); // PB
				TakeNItems(PChar, PChar.start_weapon.blade, 1);
				TakeNItems(PChar, PChar.start_weapon.gun, 1);
				DeleteAttribute(PChar, "start_weapon");

				EquiPCharacterbyItem(PChar, FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE));
				EquiPCharacterbyItem(PChar, FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE));
				EquiPCharacterbyItem(PChar, "Spyglass2");

				SetCharacterGoods(PChar, CharGood1, 0);
				SetCharacterGoods(PChar, CharGood2, 0);
				CloseQuestHeader("Tutorial_AppearedOnIsland");
			}
// <-- KK
		break;

// KK -->
		case "DialogWithMalcolmStart":
			if(GetCharacterShipCabin(PChar) != "Cabin_none") {
				LAi_type_actor_Reset(PChar);
				LAi_ActorWaitDialog(PChar, CharacterFromID("Malcolm Hatcher"));
			}
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", -1, 0.0);
			LAi_SetPlayerType(PChar);
		break;
// <-- KK

		// 05-04-06 now do while still loading so we get nice reloadprogress update stuff...case "do_reinit": SD_Reinit(); break; // NK

		case "Tut_KillTutor":
			Log_SetStringToLog(QUEST_MESSAGE8);
			Log_SetStringToLog(QUEST_MESSAGE9);
			ChangeCharacterReputation(PChar, -10);

			PChar.quest.Tut_RewardForKillingTutor.win_condition.l1 = "rank";
			PChar.quest.Tut_RewardForKillingTutor.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_RewardForKillingTutor.win_condition.l1.value = 6;
			PChar.quest.Tut_RewardForKillingTutor.win_condition.l1.operation = ">=";
			PChar.quest.Tut_RewardForKillingTutor.win_condition.l2 = "location";
			PChar.quest.Tut_RewardForKillingTutor.win_condition.l2.location = "QC_Pirate_house";
			PChar.quest.Tut_RewardForKillingTutor.win_condition = "Tut_RewardForKillingTutor";

			if(PChar.location == "Tutorial_Deck")
			{
				Lai_QuestDelay("Tut_SkipTutorialOnShip", 2.0);
			}
	
// added by MAXIMUS [choose character mod] -->
			loadPort = "Oxbay_port";
			loadTavern = "Oxbay_tavern";
			loadStore = "Oxbay_store";
			loadShipyard = "Oxbay_shipyard";
			questRecord = "Tutorial_AppearedOnIsland";
			switch(GetCurrentFlag())
			{
				case ENGLAND: 
					loadPort = "Oxbay_port";
					loadTavern = "Oxbay_tavern";
					loadStore = "Oxbay_store";
					loadShipyard = "Oxbay_shipyard";
					Preprocessor_AddQuestData("island", FindTownName("Oxbay")); // KK
				break;
				case FRANCE: 
					loadPort = "Falaise_de_fleur_port_01";
					loadTavern = "Falaise_de_fleur_tavern";
					loadStore = "Falaise_de_Fleur_store";
					loadShipyard = "Falaise_de_fleur_shipyard";
					Preprocessor_AddQuestData("island", FindTownName("Falaise de Fleur")); // KK
				break;
				case SPAIN: 
					loadPort = "Muelle_port";
					loadTavern = "Muelle_Tavern";
					loadStore = "Muelle_Store";
					loadShipyard = "Muelle_Shipyard";
					Preprocessor_AddQuestData("island", FindTownName("Isla Muelle")); // KK
				break;
				case PIRATE: 
					loadPort = "QC_port";
					loadTavern = "QC_Tavern";
					loadStore = "QC_store";
					loadShipyard = "QC_Shipyard";
					Preprocessor_AddQuestData("island", FindTownName("Quebradas Costillas")); // KK
				break;
				case HOLLAND: 
					loadPort = "Douwesen_port";
					loadTavern = "Douwesen_tavern";
					loadStore = "Douwesen_Store";
					loadShipyard = "Douwesen_shipyard";
					Preprocessor_AddQuestData("island", FindTownName("Douwesen")); // KK
				break;
				case PORTUGAL: 
					loadPort = "Conceicao_port";
					loadTavern = "Conceicao_Tavern";
					loadStore = "Conceicao_Store";
					loadShipyard = "Conceicao_Shipyard";
					Preprocessor_AddQuestData("island", FindTownName("Conceicao")); // KK
				break;
				case AMERICA: 
					loadPort = "Eleuthera_Port";
					loadTavern = "Eleuthera_tavern";
					loadStore = "Eleuthera_store";
					loadShipyard = "Eleuthera_shipyard";
					Preprocessor_AddQuestData("island", FindTownName("Eleuthera")); // KK
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					loadPort = "Oxbay_port";
					loadTavern = "Oxbay_tavern";
					loadStore = "Oxbay_store";
					loadShipyard = "Oxbay_shipyard";
					Preprocessor_AddQuestData("island", FindTownName("Oxbay")); // KK
				// TIH <--
			}
// added by MAXIMUS [choose character mod] <--

			if(PChar.location == loadPort)
			{
				Lai_QuestDelay("Tut_SkipTutorialInPort", 2.0);
			}
			if(PChar.location == loadPort || PChar.location == loadTavern || PChar.location == loadStore || PChar.location == loadShipyard)
			{
				Lai_QuestDelay("Tut_SkipTutorialInTown", 2.0);
			}
		break;

		case "Tut_RewardForKillingTutor":
			Log_SetStringToLog(QUEST_MESSAGE10); 
			Log_SetStringToLog(QUEST_MESSAGE11);

			TakeNItems(PChar,"bladeMH", 1);		// GR: originally blade23 ("Windmill Slayer"), then blade6 (Schiavona)
		break;
	
		case "Tut_TakeStuff":
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_warrior_SetStay(CharacterFromID("Malcolm Hatcher"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Malcolm Hatcher"), true);
			LAi_SetPlayerType(pchar);
			Lai_SetCheckMinHP(CharacterFromID("Malcolm Hatcher"), LAi_GetCharacterHP(characterFromID("Malcolm Hatcher"))-1.0, false, "Tut_HatcherAttacksAndKills"); // PB
		break;

		case "Tut_HatcherAttacksAndKills":
			LAi_SetActorType(CharacterFromID("Malcolm Hatcher"));
			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorAttack(CharacterFromID("Malcolm Hatcher"), PChar, "");
		break;

		case "Tut_WalkToSwordplayPlace":
			LAi_SetFightMode(PChar, false);
			LAi_LockFightMode(PChar, true);

// KK -->
			if (GetCharacterShipCabin(PChar) != "Cabin_none")
				QDeck = GetCharacterShipQDeck(PChar);
			else
				QDeck = GetCharacterShipQDeck(CharacterFromID("Malcolm Hatcher"));

			TutDeck.reload.l1.disable = 0;
			Locations[FindLocation(QDeck)].reload.l6.go = "";
			Locations[FindLocation(QDeck)].reload.l6.label = "";
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "reload", "reload1", QDeck, "goto", "goto1", "", 60);

			PChar.quest.Tut_ToTheDeck.win_condition.l1 = "location";
			PChar.quest.Tut_ToTheDeck.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_ToTheDeck.win_condition.l1.location = QDeck;
			PChar.quest.Tut_ToTheDeck.win_condition.l2 = "location";
			PChar.quest.Tut_ToTheDeck.win_condition.l2.character = "Malcolm Hatcher";
			PChar.quest.Tut_ToTheDeck.win_condition.l2.location = QDeck;
			PChar.quest.Tut_ToTheDeck.win_condition = "Tut_ToTheDeck";
// <-- KK
		break;

// KK -->
		case "Tut_ToTheDeck":
			LAi_SetActorTypeNoGroup(PChar);
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorGoToLocator(PChar, "goto", "goto2", "Tut_ToTheDeckAndTalk", 10);
		break;

		case "Tut_ToTheDeckAndTalk":
			LAi_ActorFollow(PChar, CharacterFromID("Malcolm Hatcher"), "DialogWithMalcolmStart", 1.5);
		break;
// <-- KK

		case "Tut_StartFirstSwordplay":
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "NowHitMe";
			Lai_SetPlayerType(PChar);
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 5.0, 1.0);
		break;

		case "Tut_FirstMeleeFight":
			LAi_LockFightMode(PChar, false);
			LAi_ActorWaitDialog(CharacterFromID("Malcolm Hatcher"), PChar);
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 400.0, 400.0);
			Lai_SetCheckMinHP(CharacterFromID("Malcolm Hatcher"), 0.75*LAi_GetCharacterHP(characterFromID("Malcolm Hatcher")), true, "Tut_NowFightWithMight"); // KK
		break;

		case "Tut_NowFightWithMight":
			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));
			LAi_SetActorType(PChar);
			LAi_SetFightMode(PChar, false);
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Malcolm Hatcher"));
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "HurtEnough";			
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 1.0, 1.0);		
		//	Lai_QuestDelay("player_back", 2.0);
		break;

		case "Tut_StartSeriousFight":
			Lai_SetImmortal(CharacterFromID("Malcolm Hatcher"), false);
			//Characters[GetCharacterIndex("Malcolm Hatcher")].skill.Fencing = 1;		
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 400.0, 400.0);
			LAi_SetHP(PChar, 400.0, 400.0);
			LAi_SetFightMode(PChar, true);
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorAttack(CharacterFromID("Malcolm Hatcher"), PChar, "");

			Lai_SetCheckMinHP(PChar, 0.5*LAi_GetCharacterHP(PChar), false, "SeriousFightFinished"); // KK
			Lai_SetCheckMinHP(CharacterFromID("Malcolm Hatcher"), 0.5*LAi_GetCharacterHP(characterFromID("Malcolm Hatcher")), true, "SeriousFightFinished"); // KK
		break;

		case "SeriousFightFinished":
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(PChar);

			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));

			LAi_SetActorTypeNoGroup(PChar);
			Lai_ActorWaitDialog(PChar, CharacterFromID("Malcolm Hatcher"));
			LAi_SetFightMode(PChar, false);

			Lai_QuestDelay("player_back", 1.5);
			
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "SeriousStopped";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 1.0, 1.0);

			LAi_group_SetRelation(LAI_GROUP_PLAYER, "tutorial", LAI_GROUP_FRIEND);
		break;

		case "Tut_StartSeriousFightAgain":
			Lai_SetImmortal(CharacterFromID("Malcolm Hatcher"), false);
			//Characters[GetCharacterIndex("Malcolm Hatcher")].skill.Fencing = 1;		
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 400.0, 400.0);
			LAi_SetHP(PChar, 400.0, 400.0);
			LAi_SetFightMode(PChar, true);
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorAttack(CharacterFromID("Malcolm Hatcher"), PChar, "");

			Lai_SetCheckMinHP(PChar, 0.5*LAi_GetCharacterHP(PChar), false, "SeriousFightFinishedAgain"); // KK
			Lai_SetCheckMinHP(CharacterFromID("Malcolm Hatcher"), 0.5*LAi_GetCharacterHP(characterFromID("Malcolm Hatcher")), true, "SeriousFightFinishedAgain"); // KK

		break;

		case "SeriousFightFinishedAgain":
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(PChar);

			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));

			LAi_SetActorTypeNoGroup(PChar);
			Lai_ActorWaitDialog(PChar, CharacterFromID("Malcolm Hatcher"));
			LAi_SetFightMode(PChar, false);

			Lai_QuestDelay("player_back", 1.5);

			LAi_group_SetRelation(LAI_GROUP_PLAYER, "tutorial", LAI_GROUP_FRIEND);
			
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "SeriousStoppedAgain";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 1.0, 1.0);
		break;

		case "Tut_PlayerDistributeSkills":
//NK -->
			LAi_SetImmortal(CharacterFromID("Malcolm Hatcher"), false);
// NK <-- 
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_warrior_SetStay(CharacterFromID("Malcolm Hatcher"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Malcolm Hatcher"), true);			
		break;

		case "Tut_ReloadToOxbayPort":
			EquipCharacterbyItem(PChar, "Spyglass1"); // NK
			ResetHP(&PChar); // NK 05-07-03 - LAi_SetHP(PChar, LAI_DEFAULT_HP + sti(PChar.rank) * 5, LAI_DEFAULT_HP+ sti(PChar.rank) * 5); //NK
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 120.0, 120.0);
			LAi_group_SetAlarm("tutorial", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetRelation("tutorial", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);

			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));//ccc

			SetQuestHeader("Tutorial_SpyGlass");
			AddQuestRecord("Tutorial_SpyGlass", 1);

			PChar.quest.Tut_BuySpyGlass.win_condition.l1 = "item";
			PChar.quest.Tut_BuySpyGlass.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_BuySpyGlass.win_condition.l1.item = "SpyGlass2";
			PChar.quest.Tut_BuySpyGlass.win_condition = "Tut_BuySpyGlass";
			PChar.quest.Tut_BuySpyGlass.fail_condition = "Tut_BuySpyGlass";

			// TIH --> alternative win conditions Spe3'06
			PChar.quest.Tut_BuySpyGlass3.win_condition.l1 = "item";
			PChar.quest.Tut_BuySpyGlass3.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_BuySpyGlass3.win_condition.l1.item = "SpyGlass3";
			PChar.quest.Tut_BuySpyGlass3.win_condition = "Tut_BuySpyGlass";
			PChar.quest.Tut_BuySpyGlass4.win_condition.l1 = "item";
			PChar.quest.Tut_BuySpyGlass4.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_BuySpyGlass4.win_condition.l1.item = "SpyGlass4";
			PChar.quest.Tut_BuySpyGlass4.win_condition = "Tut_BuySpyGlass";
			// TIH <--

// KK -->
			if (GetCargoGoods(PChar, CharGood1) > 0 || GetCargoGoods(PChar, CharGood2) > 0) {
				SetQuestHeader("Tutorial_Store");
				loadStore = "";
				if (GetCargoGoods(PChar, CharGood1) > 0) loadStore = strlower(LanguageConvertString(lngSeaGoodsFileID,"seg_"+Goods[CharGood1].name));
				if (CharGood1 != CharGood2) {
					if (GetCargoGoods(PChar, CharGood1) > 0 && GetCargoGoods(PChar, CharGood2) > 0) loadStore += " " + XI_ConvertString("and");
					if (GetCargoGoods(PChar, CharGood2) > 0) loadStore += " " + strlower(LanguageConvertString(lngSeaGoodsFileID,"seg_"+Goods[CharGood2].name));
				}
				Preprocessor_AddQuestData("goods",  loadStore);
				AddQuestRecord("Tutorial_Store", 1);
				//Preprocessor_Remove("goods");

				if (GetCargoGoods(PChar, CharGood1) > 0) {
					PChar.quest.Tut_SellGoods.win_condition.l1 = "goods";
					PChar.quest.Tut_SellGoods.win_condition.l1.character = PChar.id;
					PChar.quest.Tut_SellGoods.win_condition.l1.goods = CharGood1;
					PChar.quest.Tut_SellGoods.win_condition.l1.quantity = "0";
					PChar.quest.Tut_SellGoods.win_condition.l1.operation = "=";
					PChar.quest.Tut_SellGoods.win_condition = "Tut_SellGoods";
					PChar.quest.Tut_SellGoods.fail_condition = "Tut_SellGoods";
				}
				if (GetCargoGoods(PChar, CharGood2) > 0) {
					PChar.quest.Tut_SellGoods.win_condition.l2 = "goods";
					PChar.quest.Tut_SellGoods.win_condition.l2.character = PChar.id;
					PChar.quest.Tut_SellGoods.win_condition.l2.goods = CharGood2;
					PChar.quest.Tut_SellGoods.win_condition.l2.quantity = "0";
					PChar.quest.Tut_SellGoods.win_condition.l2.operation = "=";
					PChar.quest.Tut_SellGoods.win_condition = "Tut_SellGoods";
					PChar.quest.Tut_SellGoods.fail_condition = "Tut_SellGoods";
				}
			}
// <-- KK

			PChar.quest.Tut_SellGoods.win_condition.l1 = "goods";
			PChar.quest.Tut_SellGoods.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_SellGoods.win_condition.l1.goods = CharGood1;//GOOD_CHOCOLATE;
			PChar.quest.Tut_SellGoods.win_condition.l1.quantity = "0";
			PChar.quest.Tut_SellGoods.win_condition.l1.operation = "=";
			PChar.quest.Tut_SellGoods.win_condition.l2 = "goods";
			PChar.quest.Tut_SellGoods.win_condition.l2.character = PChar.id;
			PChar.quest.Tut_SellGoods.win_condition.l2.goods = CharGood2;//GOOD_LEATHER;
			PChar.quest.Tut_SellGoods.win_condition.l2.quantity = "0";
			PChar.quest.Tut_SellGoods.win_condition.l2.operation = "=";
			PChar.quest.Tut_SellGoods.win_condition = "Tut_SellGoods";
			PChar.quest.Tut_SellGoods.fail_condition = "Tut_SellGoods";

			SetQuestHeader("Tutorial_Shipyard");
			AddQuestRecord("Tutorial_Shipyard", 1);

			PChar.quest.Tut_RepairShip.win_condition.l1 = "Ship_HP";
			PChar.quest.Tut_RepairShip.win_condition.l1.character = PChar.id;
//NK -->
			PChar.quest.Tut_RepairShip.win_condition.l1.quantity = GetCharacterShipHP(PChar);
// NK <-- 
			PChar.quest.Tut_RepairShip.win_condition.l1.operation = ">=";
			PChar.quest.Tut_RepairShip.win_condition = "Tut_RepairShip";
			PChar.quest.Tut_RepairShip.fail_condition = "Tut_RepairShip";

			SetQuestHeader("Tutorial_Tavern");
			AddQuestRecord("Tutorial_Tavern", 1);

			PChar.quest.Tut_HireCrew.win_condition.l1 = "Crew_Space";
			PChar.quest.Tut_HireCrew.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_HireCrew.win_condition.l1.quantity = "0";
			PChar.quest.Tut_HireCrew.win_condition.l1.operation = "=";
			PChar.quest.Tut_HireCrew.win_condition = "Tut_HireCrew";
			PChar.quest.Tut_HireCrew.fail_condition = "Tut_HireCrew";
	
// added by MAXIMUS [choose character mod] -->
			loadPort = "Oxbay_port";
			rldLocator = "reload2";

			switch(GetCurrentFlag())
			{
				case ENGLAND: 
					loadPort = "Oxbay_port";
					rldLocator = "reload2";
					Locations[FindLocation(loadPort)].reload.l2.disable = 1;
				break;
				case FRANCE: 
					loadPort = "Falaise_de_fleur_port_01";
					rldLocator = "sea";
					Locations[FindLocation(loadPort)].reload.l2.disable = 1;
					Locations[FindLocation(loadPort)].reload.l5.disable = 1;
					Locations[FindLocation(loadPort)].reload.l6.disable = 1;
				break;
				case SPAIN: 
					loadPort = "Muelle_port";
					rldLocator = "reload3"; // KK
					Locations[FindLocation(loadPort)].reload.l2.disable = 1;
					Locations[FindLocation(loadPort)].reload.l5.disable = 1;
				break;
				case PIRATE: 
					loadPort = "QC_port";
					rldLocator = "reload1";
					Locations[FindLocation(loadPort)].reload.l2.disable = 1;
				break;
				case HOLLAND: 
					loadPort = "Douwesen_port";
					rldLocator = "reload2";
					Locations[FindLocation(loadPort)].reload.l2.disable = 1;
					Locations[FindLocation(loadPort)].reload.l5.disable = 1;
				break;
				case PORTUGAL: 
					loadPort = "Conceicao_port";
					rldLocator = "reload2";
				break;
				case AMERICA: 
					loadPort = "Eleuthera_Port";
					rldLocator = "reload1"; // on jetty
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					loadPort = "Oxbay_port";
					rldLocator = "reload2";
					Locations[FindLocation(loadPort)].reload.l2.disable = 1;
				// TIH <--
			}

			Locations[FindLocation(loadPort)].reload.l1.disable = 1;
			Locations[FindLocation(loadPort)].reload.l3.disable = 1;
			Locations[FindLocation(loadPort)].reload.l4.disable = 1;

			bDisableFastReload = 1;
// KK -->
			PlaceFleetNearShore(loadPort);

			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher")); //JA 4DEC06 need to set him back to actor before he can walk off.
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "reload", "boatr", loadPort, "officers", rldLocator + "_1", "Tut_RowToPort", 60);

			PChar.quest.Tut_StartTalkInPort.win_condition.l1 = "location";
			PChar.quest.Tut_StartTalkInPort.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_StartTalkInPort.win_condition.l1.location = loadPort;
			PChar.quest.Tut_StartTalkInPort.win_condition.l2 = "location";
			PChar.quest.Tut_StartTalkInPort.win_condition.l2.character = "Malcolm Hatcher";
			PChar.quest.Tut_StartTalkInPort.win_condition.l2.location = loadPort;
			PChar.quest.Tut_StartTalkInPort.win_condition = "Tut_StartTalkInPort";
// <-- KK
// added by MAXIMUS [choose character mod] <--
		break;

// KK -->
		case "Tut_WalkThroughQDeck":
			if (GetCharacterShipCabin(PChar) != "Cabin_none")
				QDeck = GetCharacterShipQDeck(PChar);
			else
				QDeck = GetCharacterShipQDeck(CharacterFromID("Malcolm Hatcher"));

			TutDeck.reload.l1.disable = 0;
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "reload", "reload1", QDeck, "goto", "goto3", "", 60);
			PChar.quest.Tut_WalkOnQDeck.win_condition.l1 = "location";
			PChar.quest.Tut_WalkOnQDeck.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_WalkOnQDeck.win_condition.l1.location = QDeck;
			PChar.quest.Tut_WalkOnQDeck.win_condition = "Tut_WalkOnQDeck";
		break;

		case "Tut_WalkOnQDeck":
			LAi_QuestDelay("Tut_ReloadToOxbayPort", 0.0);
		break;

		case "Tut_RowToPort":
			Locations[FindLoadedLocation()].reload.l4.disable = 0;
			Locations[FindLoadedLocation()].reload.l5.disable = 0;
		break;
// <-- KK

		case "Tut_BuySpyGlass":
			// TIH --> alternative methods for completion finished Sep3'06
			PChar.quest.Tut_BuySpyGlass.over = "yes";
			PChar.quest.Tut_BuySpyGlass3.over = "yes";
			PChar.quest.Tut_BuySpyGlass4.over = "yes";
			// TIH <--
			DeleteAttribute(PChar, "quest.tutorial.Spyglass");
			DeleteAttribute(PChar,"alwaysshowitems.SpyGlass2"); // fix for quest items like spyglass2. 05-04-21
			AddQuestRecord("Tutorial_SpyGlass", 2);
			CloseQuestHeader("Tutorial_SpyGlass");
		break;

		case "Tut_SellGoods":
			AddQuestRecord("Tutorial_Store", 2);
			CloseQuestHeader("Tutorial_Store");
		break;

		case "Tut_RepairShip":
			AddQuestRecord("Tutorial_Shipyard", 2);
			CloseQuestHeader("Tutorial_Shipyard");
		break;

		case "Tut_HireCrew":
			AddQuestRecord("Tutorial_Tavern", 2);
			CloseQuestHeader("Tutorial_Tavern");
		break;

		case "Tut_StartTalkInPort":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Tut_StartTalkInPort");

// added by MAXIMUS [choose character mod] -->
			loadPort = "Oxbay_port";
			gotoLocator = "goto18";
			gotoGroup = "goto"; // KK
			switch(GetCurrentFlag())
			{
				case ENGLAND: gotoLocator = "goto18"; loadPort = "Oxbay_port"; break;
				case FRANCE: gotoLocator = "goto1"; loadPort = "Falaise_de_fleur_port_01"; break; // KK
				case SPAIN: gotoLocator = "goto6"; loadPort = "Muelle_port"; break;
				case PIRATE: gotoGroup = "reload"; gotoLocator = "goto4"; loadPort = "QC_port"; break;
				case HOLLAND: gotoLocator = "goto15"; loadPort = "Douwesen_port"; break;
				case PORTUGAL: gotoLocator = "goto13"; loadPort = "Conceicao_port"; break;
				case AMERICA: gotoLocator = "goto10"; loadPort = "Eleuthera_Port"; break;
				case PERSONAL_NATION: gotoLocator = "goto18"; loadPort = "Oxbay_port"; break; // KK
			}

			Locations[FindLocation(loadPort)].locators_radius.(gotoGroup).(gotoLocator) = 2.0;
// added by MAXIMUS [choose character mod] <--

			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
// KK -->
			switch (GetCurrentFlag()) {
				case FRANCE:
					Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "ToFdFCenter";
				break;
				case PIRATE:
					Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "ToQCTown";
				break;
				// default:
					Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "NowLetsBuyASpyglass";
			}
// <-- KK
			LAi_SetFightMode(PChar, false);
			LAi_LockFightMode(PChar, true);
			LAi_SetActorType(PChar);
			LAi_ActorFollow(CharacterFromID("Malcolm Hatcher"), PChar, "DialogWithMalcolmStart", 2.0); // KK
			// KK LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 6.0, 1.0);
		break;

		case "Tut_GuideToSpyglass":

// added by MAXIMUS [choose character mod] -->
			loadPort = "Oxbay_port";
			gotoLocator = "goto18";
			gotoGroup = "goto";
			switch(GetCurrentFlag())
			{
				case ENGLAND: gotoLocator = "goto18"; loadPort = "Oxbay_port"; break;
				case FRANCE: gotoGroup = "reload"; gotoLocator = "Falaise_de_fleur_location_01_02"; loadPort = "Falaise_de_fleur_port_01"; break; // KK
				case SPAIN: gotoLocator = "goto6"; loadPort = "Muelle_port"; break;
				case PIRATE: gotoGroup = "reload"; gotoLocator = "reload3_back"; loadPort = "QC_port"; break;
				case HOLLAND: gotoLocator = "goto15"; loadPort = "Douwesen_port"; break;
				case PORTUGAL: gotoLocator = "goto13"; loadPort = "Conceicao_port"; break;
				case AMERICA: gotoLocator = "goto10"; loadPort = "Eleuthera_Port"; break;
				case PERSONAL_NATION: gotoLocator = "goto18"; loadPort = "Oxbay_port"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--

// KK -->
			switch (GetCurrentFlag())
			{
				case FRANCE:
					LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), gotoGroup, gotoLocator, "Falaise_de_fleur_location_02", "officers", "Falaise_de_fleur_location_02_01_1", "Tut_OpenFdFEntrance", 1000);
					PChar.quest.Tut_ToFdFSuburb.win_condition.l1 = "location";
					PChar.quest.Tut_ToFdFSuburb.win_condition.l1.character = PChar.id;
					PChar.quest.Tut_ToFdFSuburb.win_condition.l1.location = "Falaise_de_fleur_location_02";
					PChar.quest.Tut_ToFdFSuburb.win_condition = "Tut_ToFdFSuburb";

					characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "NowLetsBuyASpyglass";
				break;
				case PIRATE:
					LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), gotoGroup, gotoLocator, "QC_town_exit", "goto", "goto12", "Tut_OpenQCJungle", 100);
					PChar.quest.Tut_ToQCJungle.win_condition.l1 = "location";
					PChar.quest.Tut_ToQCJungle.win_condition.l1.character = PChar.id;
					PChar.quest.Tut_ToQCJungle.win_condition.l1.location = "QC_town_exit";
					PChar.quest.Tut_ToQCJungle.win_condition = "Tut_ToQCJungle";

					characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "NoStallsOnQC";
				break; 
				// default:
					LAi_ActorgoToLocator(CharacterFromID("Malcolm Hatcher"), gotoGroup, gotoLocator, "TurnToPlayer", 0);

					PChar.quest.Tut_ToTheTown.win_condition.l1 = "locator";
					PChar.quest.Tut_ToTheTown.win_condition.l1.character = PChar.id;
					PChar.quest.Tut_ToTheTown.win_condition.l1.location = loadPort;
					PChar.quest.Tut_ToTheTown.win_condition.l1.locator_group = gotoGroup;
					PChar.quest.Tut_ToTheTown.win_condition.l1.locator = gotoLocator;
					PChar.quest.Tut_ToTheTown.win_condition.l2 = "locator";
					PChar.quest.Tut_ToTheTown.win_condition.l2.character = "Malcolm Hatcher";
					PChar.quest.Tut_ToTheTown.win_condition.l2.location = loadPort;
					PChar.quest.Tut_ToTheTown.win_condition.l2.locator_group = gotoGroup;
					PChar.quest.Tut_ToTheTown.win_condition.l2.locator = gotoLocator;
					PChar.quest.Tut_ToTheTown.win_condition = "Tut_ToTheTown";
			}
// <-- KK
		break;

		case "TurnToPlayer":
			LAi_ActorTurnToCharacter(CharacterFromID("Malcolm Hatcher"), PChar);
		break;

		case "Tut_ToTheTown":
			switch(GetCurrentFlag())
			{
				case FRANCE:
					LAi_ActorGoToLocator(CharacterFromID("Malcolm Hatcher"), "goto", "locator11", "Tut_FollowTheSpyglass", 50.); // KK
				break;
				case PIRATE:
					LAi_QuestDelay("Tut_MalcolmShowsTheStore", 0.0); // KK
				break;
				PChar.quest.Tut_FollowTheSpyglass.win_condition = "Tut_FollowTheSpyglass";
			}
		break;

// KK -->
		case "Tut_ToFdFSuburb":
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "reload", "Falaise_de_fleur_location_02_03", "Falaise_de_fleur_location_03", "officers", "Falaise_de_fleur_location_03_02_1", "Tut_OpenFdFSuburbsGate", 1000);
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l1.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l2.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l3.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l4.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l5.disable = 1;
			PChar.quest.Tut_ToFdFCenter.win_condition.l1 = "location";
			PChar.quest.Tut_ToFdFCenter.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_ToFdFCenter.win_condition.l1.location = "Falaise_de_fleur_location_03";
			PChar.quest.Tut_ToFdFCenter.win_condition = "Tut_ToFdFCenter";
		break;

		case "Tut_OpenFdFEntrance":
			EndQuestMovie();TrackQuestMovie("end","Tut_OpenFdFEntrance");
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l1.disable = 0;
		break;

		case "Tut_OpenFdFSuburbsGate":
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l1.disable = 0;
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l2.disable = 0;
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l3.disable = 0;
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l4.disable = 0;
			Locations[FindLocation("Falaise_de_fleur_location_02")].reload.l5.disable = 0;
		break;

		case "Tut_ToFdFCenter":
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l1.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l3.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l2.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l4.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l5.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l6.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l7.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l8.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l9.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l10.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l11.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_location_03")].reload.l12.disable = 1;

			characters[GetCharacterIndex("Patric Cardone")].Dialog.Filename = "Item Trader_dialog.c";

			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorFollow(PChar, CharacterFromID("Malcolm Hatcher"), "", 1.5);
			LAi_ActorFollow(CharacterFromID("Malcolm Hatcher"), PChar, "DialogWithMalcolmStart", 1.5);
		break;

		case "Tut_OpenQCJungle":
			EndQuestMovie();TrackQuestMovie("end","Tut_OpenQCJungle");
			Locations[FindLocation("QC_port")].reload.l1.disable = 0;
			Locations[FindLocation("QC_port")].reload.l4.disable = 0;
		break;

		case "Tut_ToQCJungle":
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "reload", "Reload1", "QC_town", "officers", "reload1_1", "Tut_OpenQCGate", 1000);
			Locations[FindLocation("QC_town_exit")].reload.l1.disable = 1;
			Locations[FindLocation("QC_town_exit")].reload.l2.disable = 1;
			Locations[FindLocation("QC_town_exit")].reload.l3.disable = 1;
			Locations[FindLocation("QC_town_exit")].reload.l4.disable = 1;
			Locations[FindLocation("QC_town_exit")].reload.l5.disable = 1;
			Locations[FindLocation("QC_town_exit")].reload.l6.disable = 1;
			PChar.quest.Tut_ToQCTown.win_condition.l1 = "location";
			PChar.quest.Tut_ToQCTown.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_ToQCTown.win_condition.l1.location = "QC_town";
			PChar.quest.Tut_ToQCTown.win_condition = "Tut_ToQCTown";
		break;

		case "Tut_OpenQCGate":
			Locations[FindLocation("QC_town_exit")].reload.l1.disable = 0;
			Locations[FindLocation("QC_town_exit")].reload.l2.disable = 0;
			Locations[FindLocation("QC_town_exit")].reload.l3.disable = 0;
			Locations[FindLocation("QC_town_exit")].reload.l4.disable = 0;
			Locations[FindLocation("QC_town_exit")].reload.l5.disable = 0;
			Locations[FindLocation("QC_town_exit")].reload.l6.disable = 0;
		break;

		case "Tut_ToQCTown":
			Locations[FindLocation("QC_town")].reload.l1.disable = 1;
			Locations[FindLocation("QC_town")].reload.l2.disable = 1;
			Locations[FindLocation("QC_town")].reload.l3.disable = 1;
			Locations[FindLocation("QC_town")].reload.l4.disable = 1;
			Locations[FindLocation("QC_town")].reload.l5.disable = 1;
			Locations[FindLocation("QC_town")].reload.l6.disable = 1;
			Locations[FindLocation("QC_town")].reload.l7.disable = 1;

			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorFollow(PChar, CharacterFromID("Malcolm Hatcher"), "", 1.5);
			LAi_ActorFollow(CharacterFromID("Malcolm Hatcher"), PChar, "DialogWithMalcolmStart", 1.5);
		break;
// <-- KK

		case "FuckTheSpyGlass": 
			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));
			Lai_SetActorTypeNoGroup(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Malcolm Hatcher"));
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "ContinueWithoutSpyglass";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_FollowTheSpyglass":
			LAi_type_actor_Reset(CharacterFromID("Malcolm Hatcher"));
			Lai_SetActorTypeNoGroup(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Malcolm Hatcher"));
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "HereAretheTraders";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_SoBuyTheFuckingGlass":
			Lai_SetPlayerType(PChar);
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			LAi_warrior_SetStay(CharacterFromID("Malcolm Hatcher"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Malcolm Hatcher"), true);
			if (GetCurrentFlag() == FRANCE) LAi_ActorGoToLocator(CharacterFromID("Malcolm Hatcher"), "goto", "locator11", "", 1000); // KK
		break;

		case "Tut_ReloadToOxbay":
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));

// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			rldLocator = "Reload1";
			gotoLocator = "Goto38";
			gotoGroup = "goto";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadTown = "Oxbay_town"; 
					rldLocator = "Reload1"; 
					gotoLocator = "goto38"; 
				break;
				case FRANCE:
					loadTown = "Falaise_de_fleur_location_04"; 
					rldLocator = "Falaise_de_fleur_location_03_04"; 
					gotoLocator = "locator8";
				break;
				case SPAIN:
					loadTown = "Muelle_town_01"; 
					rldLocator = "reload2"; 
					gotoLocator = "goto30"; 
				break;
// KK -->
				/*case PIRATE:
					loadTown = "QC_town"; 
					rldLocator = "reload1"; 
					gotoLocator = "goto3"; 
					PChar.quest.Tut_ReloadToOxbayTown = "tutorial_delay";
					Lai_SetPlayerType(PChar);
				break;*/
// <-- KK
				case HOLLAND:
					loadTown = "Douwesen_town"; 
					rldLocator = "reload3"; 
					gotoLocator = "goto3"; 
				break;
				case PORTUGAL:
					loadTown = "Conceicao_town"; 
					rldLocator = "reload1"; 
					gotoLocator = "goto4"; 
				break;
				case AMERICA:
					loadTown = "Eleuthera_Port";
					rldLocator = "reload6_back";
					gotoLocator = "reload6_1";
					gotoGroup = "officer";
				break;
// KK -->
				case PERSONAL_NATION:
					loadTown = "Oxbay_town"; 
					rldLocator = "Reload1"; 
					gotoLocator = "goto38"; 
				break;
// <-- KK
			}
// added by MAXIMUS [choose character mod] <--

			LAi_ActorgoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", rldLocator, loadTown, gotoGroup, gotoLocator, "Tut_TownOpened", 0);
			EndQuestMovie();TrackQuestMovie("end","Tut_ReloadToOxbay");

			PChar.quest.Tut_ReloadToOxbayTown.win_condition.l1 = "location";
			PChar.quest.Tut_ReloadToOxbayTown.win_condition.l1.location = loadTown;
			PChar.quest.Tut_ReloadToOxbayTown.win_condition = "Tut_ReloadPlayerToOxbayTown";
		break;

		case "Tut_TownOpened":
// added by MAXIMUS [choose character mod] -->
			loadPort = "Oxbay_port";
			rldLocator = "Reload1";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "Reload1"; loadPort = "Oxbay_port"; break;
				case FRANCE: rldLocator = "Falaise_de_fleur_location_03_04"; loadPort = "Falaise_de_fleur_location_03"; break;
				case SPAIN: rldLocator = "Reload2"; loadPort = "Muelle_port"; break;
				case PIRATE: rldLocator = "Reload1"; loadPort = "QC_town_exit"; break;
				case HOLLAND: rldLocator = "Reload3"; loadPort = "Douwesen_port"; break;
				case PORTUGAL: rldLocator = "Reload1"; loadPort = "Conceicao_port"; break;
				case AMERICA: rldLocator = "Reload6_back"; loadPort = "Eleuthera_Port"; break;
				case PERSONAL_NATION: rldLocator = "Reload1"; loadPort = "Oxbay_port"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			chrEnableReloadLocator(loadPort, rldLocator, true);
		break;

		case "Tut_ReloadPlayerToOxbayTown":
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "NowGoTotheStore";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
// added by MAXIMUS [choose character mod] -->
			loadPort = "Oxbay_port";
			switch(GetCurrentFlag())
			{
				case ENGLAND: loadPort = "Oxbay_port"; Locations[FindLocation(loadPort)].reload.l2.disable = 0; break;
				case FRANCE: 
					loadPort = "Falaise_de_fleur_port_01"; 

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;
					Locations[FindLocation(loadPort)].reload.l6.disable = 0;
				break;
				case SPAIN: 
					loadPort = "Muelle_port"; 

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;
				break;
				case PIRATE: loadPort = "QC_port"; Locations[FindLocation(loadPort)].reload.l2.disable = 0;	break;
				case HOLLAND: 
					loadPort = "Douwesen_port";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0; 
				break;
				case PORTUGAL: loadPort = "Conceicao_port"; break;
				case AMERICA:
					loadPort = "Eleuthera_Port";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;
					Locations[FindLocation(loadPort)].reload.l6.disable = 0;
				break;
				case PERSONAL_NATION: loadPort = "Oxbay_port"; Locations[FindLocation(loadPort)].reload.l2.disable = 0; break; // KK
			}

			Locations[FindLocation(loadPort)].reload.l1.disable = 0;
			Locations[FindLocation(loadPort)].reload.l3.disable = 0;
			Locations[FindLocation(loadPort)].reload.l4.disable = 0;
// added by MAXIMUS [choose character mod] <--
		break;
	
		case "Tut_MalcolmShowsTheStore":
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			loadStore = "Oxbay_store";
			rldLocator = "Reload15";
			gotoLocator = "locator6";
			gotoGroup = "goto";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadTown = "Oxbay_town";
					loadStore = "Oxbay_store";
					rldLocator = "Reload15";
					gotoLocator = "locator6";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
					Locations[FindLocation(loadTown)].reload.l13.disable = 1;
					Locations[FindLocation(loadTown)].reload.l14.disable = 1;
				break;
				case FRANCE:
					loadTown = "Falaise_de_fleur_location_04"; 
					loadStore = "Falaise_de_Fleur_store"; 
					rldLocator = "Falaise_de_fleur_store"; 
					gotoLocator = "goto3"; 
				break;
				case SPAIN:
					loadTown = "Muelle_town_01"; 
					loadStore = "Muelle_Store";
					rldLocator = "reload8"; // KK
					gotoLocator = "locator5"; 

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
					Locations[FindLocation(loadTown)].reload.l13.disable = 1;
					Locations[FindLocation(loadTown)].reload.l14.disable = 1;
					Locations[FindLocation(loadTown)].reload.l15.disable = 1;
					Locations[FindLocation(loadTown)].reload.l16.disable = 1;
					Locations[FindLocation(loadTown)].reload.l17.disable = 1;
					Locations[FindLocation(loadTown)].reload.l18.disable = 1;
					Locations[FindLocation(loadTown)].reload.l19.disable = 1;
				break;
				case PIRATE:
					loadTown = "QC_town";
					loadStore = "QC_store";
					rldLocator = "reload5";
					gotoLocator = "locator7";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
				break;
				case HOLLAND: 
					loadTown = "Douwesen_town";
					loadStore = "Douwesen_Store";
					rldLocator = "reload4";
					gotoLocator = "goto5";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
				break;
				case PORTUGAL:
					loadTown = "Conceicao_town";
					loadStore = "Conceicao_Store";
					rldLocator = "reload18";
					gotoLocator = "goto6";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
				break;
				case AMERICA:
					//PW: for AMERICA jump to here -->
					EndQuestMovie();TrackQuestMovie("end","Tut_ReloadToOxbay");
					LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
					//PW: for AMERICA jump to here <--
					loadTown = "Eleuthera_Port";
					loadStore =  "Eleuthera_store";
					rldLocator = "reload6_back";
					gotoGroup = "reload";
					gotoLocator = "reload1_back";
					chrEnableReloadLocator(loadTown, rldLocator, true);
					Locations[FindLocation(loadStore)].locators_radius.(gotoGroup).(gotoLocator) = 2.0;
					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
					Locations[FindLocation(loadTown)].reload.l13.disable = 1;
					Locations[FindLocation(loadTown)].reload.l14.disable = 1;
				// TIH <--
			}

			Locations[FindLocation(loadTown)].reload.l1.disable = 1;
			Locations[FindLocation(loadTown)].reload.l2.disable = 1;
			Locations[FindLocation(loadTown)].reload.l3.disable = 1;
			Locations[FindLocation(loadTown)].reload.l4.disable = 1;

			LAi_ActorgoToLocation(CharacterFromID("Malcolm Hatcher"), "reload", rldLocator, loadStore, gotoGroup, gotoLocator, "tut_StoreOpened", 0);

			PChar.quest.Tut_PlayerEntersTheStore.win_condition.l1 = "location";
			PChar.quest.Tut_PlayerEntersTheStore.win_condition.l1.location = loadStore;
// added by MAXIMUS [choose character mod] <--
			PChar.quest.Tut_PlayerEntersTheStore.win_condition = "Tut_PlayerEntersTheStore";
			PChar.skipstoretime = true; // NK 04-11-15
		break;

		case "tut_StoreOpened":
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			rldLocator = "reload15";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "reload15"; loadTown = "Oxbay_town"; break;
				case FRANCE: rldLocator = "Falaise_de_fleur_store"; loadTown = "Falaise_de_fleur_location_04"; break;
				case SPAIN: rldLocator = "reload8"; loadTown = "Muelle_town_01"; break;
				case PIRATE: rldLocator = "reload5"; loadTown = "QC_town"; break;
				case HOLLAND: rldLocator = "reload4"; loadTown = "Douwesen_town"; break;
				case PORTUGAL: rldLocator = "reload18"; loadTown = "Conceicao_town"; break;
				case AMERICA: rldLocator = "reload6_back"; loadTown = "Eleuthera_Port"; break;
				case PERSONAL_NATION: rldLocator = "reload15"; loadTown = "Oxbay_town"; break; // KK
			}

			chrEnableReloadLocator(loadTown, rldLocator, true);
// added by MAXIMUS [choose character mod] <--
		break;

		case "Tut_PlayerEntersTheStore":
// added by MAXIMUS [choose character mod] -->
			loadStore = "Oxbay_store";
			rldLocator = "locator2";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "locator2"; loadStore = "Oxbay_store"; break;
				case FRANCE: rldLocator = "reload1"; loadStore = "Falaise_de_Fleur_store"; break;
				case SPAIN: rldLocator = "locator2"; loadStore = "Muelle_Store"; break;
				case PIRATE: rldLocator = "locator2"; loadStore = "QC_store"; break;
				case HOLLAND: rldLocator = "reload1"; loadStore = "Douwesen_Store"; break;
				case PORTUGAL: rldLocator = "reload1"; loadStore = "Conceicao_Store"; break;
				case AMERICA: rldLocator = "reload1_back"; loadStore = "Eleuthera_store"; break;
				case PERSONAL_NATION: rldLocator = "locator2"; loadStore = "Oxbay_store"; break; // KK
			}
			chrEnableReloadLocator(loadStore, rldLocator, false);
// added by MAXIMUS [choose character mod] <--

			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "MoreDetailsOnTrade";
			LAi_ActorTurnToCharacter(CharacterFromID("Malcolm Hatcher"), PChar);
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_StartTrading":
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			rldLocator = "locator2";
			gotoLocator = "goto26";
			gotoGroup = "goto";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "locator2"; loadTown = "Oxbay_town"; gotoLocator = "goto26"; break;
				case FRANCE: rldLocator = "reload1"; loadTown = "Falaise_de_fleur_location_04"; gotoLocator = "locator12"; break;
				case SPAIN: rldLocator = "locator2"; loadTown = "Muelle_town_01"; gotoLocator = "goto52"; break;
				case PIRATE: rldLocator = "locator2"; loadTown = "QC_town"; gotoLocator = "goto7"; break;
				case HOLLAND: rldLocator = "reload1"; loadTown = "Douwesen_town"; gotoLocator = "goto35"; break;
				case PORTUGAL: rldLocator = "reload1"; loadTown = "Conceicao_town"; gotoLocator = "goto4"; break;
				case AMERICA: rldLocator = "reload1_back"; loadTown = "Eleuthera_Port"; gotoGroup = "officers"; gotoLocator = "reload6_1"; break;
				case PERSONAL_NATION: rldLocator = "locator2"; loadTown = "Oxbay_town"; gotoLocator = "goto26"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", rldLocator, loadTown, gotoGroup, gotoLocator, "Tut_FreeFromStore", 0);
			
			PChar.quest.Tut_ToOxbayAfterTrading.win_condition.l1 = "location";
			PChar.quest.Tut_ToOxbayAfterTrading.win_condition.l1.location = loadTown;
			PChar.quest.Tut_ToOxbayAfterTrading.win_condition = "Tut_ToOxbayAfterTrading";
		break;

		case "Tut_FreeFromStore":
// added by MAXIMUS [choose character mod] -->
			loadStore = "Oxbay_store";
			rldLocator = "locator2";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "locator2"; loadStore = "Oxbay_store"; break;
				case FRANCE: rldLocator = "reload1"; loadStore = "Falaise_de_Fleur_store"; break;
				case SPAIN: rldLocator = "locator2"; loadStore = "Muelle_Store"; break;
				case PIRATE: rldLocator = "locator2"; loadStore = "QC_store"; break;
				case HOLLAND: rldLocator = "reload1"; loadStore = "Douwesen_Store"; break;
				case PORTUGAL: rldLocator = "reload1"; loadStore = "Conceicao_Store"; break;
				case AMERICA: rldLocator = "reload1_back"; loadStore = "Eleuthera_store"; break;
				case PERSONAL_NATION: rldLocator = "locator2"; loadStore = "Oxbay_store"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			chrEnableReloadLocator(loadStore, rldLocator, true);
		break;
			
		case "Tut_ToOxbayAfterTrading":
			DeleteAttribute(PChar,"skipstoretime"); // NK 04-11-15
			LAi_SetFightMode(PChar, false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "GoodsSoldInStore";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadTown = "Oxbay_town";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
					Locations[FindLocation(loadTown)].reload.l13.disable = 1;
					Locations[FindLocation(loadTown)].reload.l14.disable = 1;
				break;

				case FRANCE:
					loadTown = "Falaise_de_fleur_location_04";
				break;

				case SPAIN:
					loadTown = "Muelle_town_01";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
					Locations[FindLocation(loadTown)].reload.l13.disable = 1;
					Locations[FindLocation(loadTown)].reload.l14.disable = 1;
					Locations[FindLocation(loadTown)].reload.l15.disable = 1;
					Locations[FindLocation(loadTown)].reload.l16.disable = 1;
					Locations[FindLocation(loadTown)].reload.l17.disable = 1;
					Locations[FindLocation(loadTown)].reload.l18.disable = 1;
					Locations[FindLocation(loadTown)].reload.l19.disable = 1;
				break;

				case PIRATE:
					loadTown = "QC_town";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
				break;

				case HOLLAND:
					loadTown = "Douwesen_town";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
				break;

				case PORTUGAL:
					loadTown = "Conceicao_town";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
				break;
				case AMERICA:
					loadTown = "Eleuthera_Port";

					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
					Locations[FindLocation(loadTown)].reload.l13.disable = 1;
					Locations[FindLocation(loadTown)].reload.l14.disable = 1;
				// TIH <--
			}

			Locations[FindLocation(loadTown)].reload.l1.disable = 1;
			Locations[FindLocation(loadTown)].reload.l2.disable = 1;
			Locations[FindLocation(loadTown)].reload.l3.disable = 1;
			Locations[FindLocation(loadTown)].reload.l4.disable = 1;
// added by MAXIMUS [choose character mod] <--
		break;

		case "BackToTown":
			switch(GetCurrentFlag())
			{
				case FRANCE:
// KK -->
					LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "reload", "Falaise_de_fleur_location_04_03", "Falaise_de_fleur_location_03", "officers", "Falaise_de_fleur_location_03_04_1", "OpenFdFCenterGates", 1000);
					PChar.quest.GoToFdFTavern.win_condition.l1 = "location";
					PChar.quest.GoToFdFTavern.win_condition.l1.character = PChar.id;
					PChar.quest.GoToFdFTavern.win_condition.l1.location = "Falaise_de_fleur_location_03";
					PChar.quest.GoToFdFTavern.win_condition = "GoToFdFTavern";
// <-- KK
				break;
				PChar.quest.GoToTavern.win_condition = "GoToTavern";
			}
		break;

// KK -->
		case "OpenFdFCenterGates":
			Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l1.disable = 0;
		break;

		case "GoToFdFTavern":
			characters[GetCharacterIndex("Patric Cardone")].Dialog.Filename = "patric cardone_dialog.c";
			LAi_QuestDelay("GoToTavern", 0.0);// "0." is bad, use something legit
		break;
// <-- KK

		case "GoToTavern":
			loadTown = "Oxbay_town";
			loadTavern = "Oxbay_tavern";
			rldLocator = "Reload13"; 
			gotoLocator = "goto20";
			switch(GetCurrentFlag())
			{
				case ENGLAND: loadTown = "Oxbay_town"; rldLocator = "Reload13"; loadTavern = "Oxbay_tavern"; gotoLocator = "goto20"; break;
				case FRANCE: 
					loadTown = "Falaise_de_fleur_location_03"; 
					rldLocator = "Falaise_de_fleur_tavern"; 
					loadTavern = "Falaise_de_fleur_tavern"; 
					gotoLocator = "goto4"; 

					Locations[FindLocation(loadTown)].reload.l1.disable = 1;
					Locations[FindLocation(loadTown)].reload.l2.disable = 1;
					Locations[FindLocation(loadTown)].reload.l3.disable = 1;
					Locations[FindLocation(loadTown)].reload.l4.disable = 1;
					Locations[FindLocation(loadTown)].reload.l5.disable = 1;
					Locations[FindLocation(loadTown)].reload.l6.disable = 1;
					Locations[FindLocation(loadTown)].reload.l7.disable = 1;
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
				break;
				case SPAIN: loadTown = "Muelle_town_01"; rldLocator = "reload14"; loadTavern = "Muelle_Tavern"; gotoLocator = "goto6"; break;
				case PIRATE: loadTown = "QC_town"; rldLocator = "reload2"; loadTavern = "QC_Tavern"; gotoLocator = "goto6"; break;
				case HOLLAND: loadTown = "Douwesen_town"; rldLocator = "reload3"; loadTavern = "Douwesen_tavern"; gotoLocator = "goto4"; break;
				case PORTUGAL: loadTown = "Conceicao_town"; rldLocator = "reload4"; loadTavern = "Conceicao_Tavern"; gotoLocator = "goto6"; break;
				case AMERICA: loadTown = "Eleuthera_Port"; rldLocator = "reload4_back"; loadTavern = "Eleuthera_tavern"; gotoLocator = "goto10"; break;
				case PERSONAL_NATION: loadTown = "Oxbay_town"; rldLocator = "Reload13"; loadTavern = "Oxbay_tavern"; gotoLocator = "goto20"; break; // KK
			}

			LAi_ActorgoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", rldLocator, loadTavern, "goto", gotoLocator, "Tut_TavernOpened", 0);

			PChar.quest.Tut_ToTavernForCrew.win_condition.l1 = "location";
			PChar.quest.Tut_ToTavernForCrew.win_condition.l1.location = loadTavern;
			PChar.quest.Tut_ToTavernForCrew.win_condition = "Tut_ToTavernForCrew";
		break;

		case "Tut_MalcolmLeadsToTavern":
			PChar.quest.BackToTown.win_condition = "BackToTown";
		break;

		case "Tut_TavernOpened":
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			rldLocator = "reload13";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "reload13"; loadTown = "Oxbay_town"; break;
				case FRANCE: rldLocator = "Falaise_de_fleur_tavern"; loadTown = "Falaise_de_fleur_location_03"; break;
				case SPAIN: rldLocator = "reload14"; loadTown = "Muelle_town_01"; break;
				case PIRATE: rldLocator = "reload2"; loadTown = "QC_town"; break;
				case HOLLAND: rldLocator = "reload3"; loadTown = "Douwesen_town"; break;
				case PORTUGAL: rldLocator = "reload4"; loadTown = "Conceicao_town"; break;
				case AMERICA: rldLocator = "reload4_back"; loadTown = "Eleuthera_Port"; break;
				case PERSONAL_NATION: rldLocator = "reload13"; loadTown = "Oxbay_town"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			chrEnableReloadLocator(loadTown, rldLocator, true);
		break;

		case "Tut_ToTavernForCrew":
// added by MAXIMUS [choose character mod] -->
			loadTavern = "Oxbay_tavern";
			rldLocator = "reload1";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "reload1"; loadTavern = "Oxbay_tavern"; break;
				case FRANCE: rldLocator = "reload1"; loadTavern = "Falaise_de_fleur_tavern"; break;
				case SPAIN: rldLocator = "reload1"; loadTavern = "Muelle_Tavern"; break;
				case PIRATE: rldLocator = "reload1"; loadTavern = "QC_Tavern"; break;
				case HOLLAND: rldLocator = "reload1"; loadTavern = "Douwesen_tavern"; break;
				case PORTUGAL: rldLocator = "reload1"; loadTavern = "Conceicao_Tavern"; break;
				case AMERICA: rldLocator = "reload2_back"; loadTavern = "Eleuthera_tavern"; break;
				case PERSONAL_NATION: rldLocator = "reload1"; loadTavern = "Oxbay_tavern"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			chrEnableReloadLocator(loadTavern, rldLocator, false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "CrewHiringInTavern";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_MalcolmLeavesTavern":
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			rldLocator = "Reload1";
			gotoLocator = "goto41";
			gotoGroup = "goto";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "Reload1"; loadTown = "Oxbay_town"; gotoLocator = "goto41"; break;
				case FRANCE: rldLocator = "Reload1"; loadTown = "Falaise_de_fleur_location_03"; gotoLocator = "locator9"; break;
				case SPAIN: rldLocator = "Reload1"; loadTown = "Muelle_town_01"; gotoLocator = "goto93"; break;
				case PIRATE: rldLocator = "Reload1"; loadTown = "QC_town"; gotoLocator = "goto12"; break;
				case HOLLAND: rldLocator = "Reload1"; loadTown = "Douwesen_town"; gotoLocator = "goto33"; break;
				case PORTUGAL: rldLocator = "Reload1"; loadTown = "Conceicao_town"; gotoLocator = "goto4"; break;
				case AMERICA: rldLocator = "Reload2_back"; loadTown = "Eleuthera_port"; gotoGroup = "officers"; gotoLocator = "reload4_1"; break;
				case PERSONAL_NATION: rldLocator = "Reload1"; loadTown = "Oxbay_town"; gotoLocator = "goto41"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", rldLocator, loadTown, gotoGroup, gotoLocator, "Tut_FreeFromTavern", 0);
			
			PChar.quest.Tut_ToOxbayAfterHiring.win_condition.l1 = "location";
			PChar.quest.Tut_ToOxbayAfterHiring.win_condition.l1.location = loadTown;
			PChar.quest.Tut_ToOxbayAfterHiring.win_condition = "Tut_ToOxbayAfterHiring";
		break;

		case "Tut_FreeFromTavern":
// added by MAXIMUS [choose character mod] -->
			loadTavern = "Oxbay_tavern";
			rldLocator = "Reload1";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "Reload1"; loadTavern = "Oxbay_tavern"; break;
				case FRANCE: rldLocator = "Reload1"; loadTavern = "Falaise_de_fleur_tavern"; break;
				case SPAIN: rldLocator = "Reload1"; loadTavern = "Muelle_Tavern"; break;
				case PIRATE: rldLocator = "Reload1"; loadTavern = "QC_Tavern"; break;
				case HOLLAND: rldLocator = "Reload1"; loadTavern = "Douwesen_tavern"; break;
				case PORTUGAL: rldLocator = "Reload1"; loadTavern = "Conceicao_Tavern"; break;
				case AMERICA: rldLocator = "Reload2_back"; loadTavern = "Eleuthera_tavern"; break;
				case PERSONAL_NATION: rldLocator = "Reload1"; loadTavern = "Oxbay_tavern"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			chrEnableReloadLocator(loadTavern, rldLocator, true);
		break;

		case "Tut_ToOxbayAfterHiring":
			LAi_SetFightMode(PChar, false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "CrewHiredintavern";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 0, 1.0);
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadTown = "Oxbay_town";

					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
					Locations[FindLocation(loadTown)].reload.l13.disable = 1;
					Locations[FindLocation(loadTown)].reload.l14.disable = 1;
				break;
				case FRANCE:
					loadTown = "Falaise_de_fleur_location_03";

					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
				break;
				case SPAIN:
					loadTown = "Muelle_town_01";

					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
					Locations[FindLocation(loadTown)].reload.l13.disable = 1;
					Locations[FindLocation(loadTown)].reload.l14.disable = 1;
					Locations[FindLocation(loadTown)].reload.l15.disable = 1;
					Locations[FindLocation(loadTown)].reload.l16.disable = 1;
					Locations[FindLocation(loadTown)].reload.l17.disable = 1;
					Locations[FindLocation(loadTown)].reload.l18.disable = 1;
					Locations[FindLocation(loadTown)].reload.l19.disable = 1;
				break;
				case PIRATE:
					loadTown = "QC_town";
				break;
				case HOLLAND:
					loadTown = "Douwesen_town";

					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
				break;
				case PORTUGAL:
					loadTown = "Conceicao_town";

					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
				break;
				case AMERICA:
					loadTown = "Eleuthera_Port";

					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					Locations[FindLocation(loadTown)].reload.l8.disable = 1;
					Locations[FindLocation(loadTown)].reload.l9.disable = 1;
					Locations[FindLocation(loadTown)].reload.l10.disable = 1;
					Locations[FindLocation(loadTown)].reload.l11.disable = 1;
					Locations[FindLocation(loadTown)].reload.l12.disable = 1;
					Locations[FindLocation(loadTown)].reload.l13.disable = 1;
					Locations[FindLocation(loadTown)].reload.l14.disable = 1;
				// TIH <--
			}

			Locations[FindLocation(loadTown)].reload.l1.disable = 1;
			Locations[FindLocation(loadTown)].reload.l2.disable = 1;
			Locations[FindLocation(loadTown)].reload.l3.disable = 1;
			Locations[FindLocation(loadTown)].reload.l4.disable = 1;
			Locations[FindLocation(loadTown)].reload.l5.disable = 1;
			Locations[FindLocation(loadTown)].reload.l6.disable = 1;
			Locations[FindLocation(loadTown)].reload.l7.disable = 1;
// added by MAXIMUS [choose character mod] <--
		break;


		case "Tut_BooGoForShipyard":
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town"; 
			loadShipyard = "Oxbay_shipyard";
			rldLocator = "Reload3";
			gotoLocator = "goto1";
			gotoGroup ="goto";
			switch(GetCurrentFlag())
			{
				case ENGLAND: loadTown = "Oxbay_town"; rldLocator = "Reload3"; loadShipyard = "Oxbay_shipyard"; gotoLocator = "goto1"; break;
				case FRANCE: loadTown = "Falaise_de_fleur_location_03"; rldLocator = "Falaise_de_fleur_shipyard"; loadShipyard = "Falaise_de_fleur_shipyard"; gotoLocator = "goto7"; break;
				case SPAIN: loadTown = "Muelle_town_01"; rldLocator = "reload17"; loadShipyard = "Muelle_Shipyard"; gotoLocator = "goto7"; break;
				case PIRATE: loadTown = "QC_town"; rldLocator = "Reload4"; loadShipyard = "QC_Shipyard"; gotoLocator = "goto7"; break;
				case HOLLAND: loadTown = "Douwesen_town"; rldLocator = "reload11"; loadShipyard = "Douwesen_shipyard"; gotoLocator = "goto1"; break;
				case PORTUGAL: loadTown = "Conceicao_town"; rldLocator = "reload13"; loadShipyard = "Conceicao_Shipyard"; gotoLocator = "goto4"; break;
				case AMERICA: loadTown = "Eleuthera_Port"; rldLocator = "reload5_back"; loadShipyard = "Eleuthera_shipyard"; gotoGroup = "reload"; gotoLocator = "reload1_back"; break;
				case PERSONAL_NATION: loadTown = "Oxbay_town"; rldLocator = "Reload3"; loadShipyard = "Oxbay_shipyard"; gotoLocator = "goto1"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			LAi_ActorgoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", rldLocator, loadShipyard, gotoGroup, gotoLocator, "Tut_ShipyardOpened", 0);
			
			PChar.quest.Tut_ToShipyardForRepairs.win_condition.l1 = "location";
			PChar.quest.Tut_ToShipyardForRepairs.win_condition.l1.location = loadShipyard;
			PChar.quest.Tut_ToShipyardForRepairs.win_condition = "Tut_ToShipyardForRepairs";
		break;

		case "Tut_ShipyardOpened":
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			rldLocator = "Reload3";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "Reload3"; loadTown = "Oxbay_town"; break;
				case FRANCE: rldLocator = "Falaise_de_fleur_shipyard"; loadTown = "Falaise_de_fleur_location_03"; break;
				case SPAIN: rldLocator = "reload17"; loadTown = "Muelle_town_01"; break;
				case PIRATE: rldLocator = "Reload4"; loadTown = "QC_town"; break;
				case HOLLAND: rldLocator = "reload11"; loadTown = "Douwesen_town"; break;
				case PORTUGAL: rldLocator = "reload13"; loadTown = "Conceicao_town"; break;
				case AMERICA: rldLocator = "reload5_back"; loadTown = "Eleuthera_Port"; break;
				case PERSONAL_NATION: rldLocator = "Reload3"; loadTown = "Oxbay_town"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			//Locations[FindLocation("Oxbay_town")].reload.l7.disable = 0;
			chrEnableReloadLocator(loadTown, rldLocator, true);
		break;

		case "Tut_ToShipyardForRepairs":
// added by MAXIMUS [choose character mod] -->
			loadShipyard = "Oxbay_shipyard";
			rldLocator = "reload1";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "reload1"; loadShipyard = "Oxbay_shipyard"; break;
				case FRANCE: rldLocator = "locator2"; loadShipyard = "Falaise_de_fleur_shipyard"; break;
				case SPAIN: rldLocator = "locator2"; loadShipyard = "Muelle_Shipyard"; break;
				case PIRATE: rldLocator = "locator2"; loadShipyard = "QC_Shipyard"; break;
				case HOLLAND: rldLocator = "reload1"; loadShipyard = "Douwesen_shipyard"; break;
				case PORTUGAL: rldLocator = "reload1"; loadShipyard = "Conceicao_Shipyard"; break;
				case AMERICA: rldLocator = "reload1_back"; loadShipyard = "Eleuthera_shipyard";
					Locations[FindLocation(loadShipyard)].locators_radius.(gotoGroup).(gotoLocator) = 2.0;
				break;
				case PERSONAL_NATION: rldLocator = "reload1"; loadShipyard = "Oxbay_shipyard"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			chrEnableReloadLocator(loadShipyard, rldLocator, false);
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "ShipRepairing";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "", 3.0, 1.0);
		break;

		case "Tut_MalcolmLeavesShipyard":
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			rldLocator = "reload1";
			gotoLocator = "goto23";
			gotoGroup ="goto";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "reload1"; loadTown = "Oxbay_town"; gotoLocator = "goto23"; break;
				case FRANCE: rldLocator = "locator2"; loadTown = "Falaise_de_fleur_location_03"; gotoLocator = "locator7"; break;
				case SPAIN: rldLocator = "locator2"; loadTown = "Muelle_town_01"; gotoLocator = "goto89"; break;
				case PIRATE: rldLocator = "locator2"; loadTown = "QC_town"; gotoLocator = "goto5"; break;
				case HOLLAND: rldLocator = "reload1"; loadTown = "Douwesen_town"; gotoLocator = "goto5"; break;
				case PORTUGAL: rldLocator = "reload1"; loadTown = "Conceicao_town"; gotoLocator = "goto11"; break;
				case AMERICA: rldLocator = "reload5_back"; loadTown = "Eleuthera_Port"; gotoGroup = "officers"; gotoLocator = "reload5_1"; break;
				case PERSONAL_NATION: rldLocator = "reload1"; loadTown = "Oxbay_town"; gotoLocator = "goto23"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "Reload", rldLocator, loadTown, gotoGroup, gotoLocator, "Tut_FreeFromShipyard", 0);
			SetNextWeather("Blue Sky"); // KK

			PChar.quest.Tut_ToOxbayAfterFixing.win_condition.l1 = "location";
			PChar.quest.Tut_ToOxbayAfterFixing.win_condition.l1.location = loadTown;
			PChar.quest.Tut_ToOxbayAfterFixing.win_condition = "Tut_ToOxbayAfterFixing";
		break;

		case "Tut_FreeFromShipyard":
// added by MAXIMUS [choose character mod] -->
			loadShipyard = "Oxbay_shipyard";
			rldLocator = "reload1";
			switch(GetCurrentFlag())
			{
				case ENGLAND: rldLocator = "reload1"; loadShipyard = "Oxbay_shipyard"; break;
				case FRANCE: rldLocator = "locator2"; loadShipyard = "Falaise_de_fleur_shipyard"; break;
				case SPAIN: rldLocator = "locator2"; loadShipyard = "Muelle_Shipyard"; break;
				case PIRATE: rldLocator = "locator2"; loadShipyard = "QC_Shipyard"; break;
				case HOLLAND: rldLocator = "reload1"; loadShipyard = "Douwesen_shipyard"; break;
				case PORTUGAL: rldLocator = "reload1"; loadShipyard = "Conceicao_Shipyard"; break;
				case AMERICA: rldLocator = "reload1_back"; loadShipyard = "Eleuthera_shipyard"; break;
				case PERSONAL_NATION: rldLocator = "reload1"; loadShipyard = "Oxbay_shipyard"; break; // KK
			}
// added by MAXIMUS [choose character mod] <--
			chrEnableReloadLocator(loadShipyard, rldLocator, true);
		break;

		case "Tut_ToOxbayAfterFixing":
			PChar.quest.Tut_KillTutor.over = "yes";
			locDisableUpdateTime = false;
			Characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "FinalStage";
			LAi_ActorDialog(CharacterFromID("Malcolm Hatcher"), PChar, "player_back", 4.0, 1.0);
		break;

		case "Tut_SkipTutorialOnShip":
			DeleteAttribute(&PChar,"vcskip"); // NK 04-06

			locDisableUpdateTime = false;
			LAi_LockFightMode(PChar, false);
			EndQuestMovie();
			TrackQuestMovie("end","Tut_SkipTutorialOnShip");
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(PChar);

			ResetHP(PChar); // NK 05-07-03 - LAi_SetHP(PChar, LAI_DEFAULT_HP + sti(PChar.rank) * 5, LAI_DEFAULT_HP + sti(PChar.rank) * 5); //NK
			LAi_SetHP(CharacterFromID("Malcolm Hatcher"), 120.0, 120.0);
			LAi_group_SetAlarm("tutorial", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetRelation("tutorial", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			// boal 10.09.03 fix tutor bug -->
			LAi_SetActorTypeNoGroup(CharacterFromID("Malcolm Hatcher"));
			// boal <--
			LAi_SetPlayerType(PChar); // KK

// added by MAXIMUS [choose character mod] -->
			loadPort = "Oxbay_port";
			questRecord = "Tutorial_AppearedOnIsland";
			loadTown = "Oxbay_town";
			gotoGroup = "goto";
			gotoLocator = "goto18";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadPort = "Oxbay_port";
				break;

				case FRANCE:
					loadPort = "Falaise_de_fleur_port_01";
					gotoLocator = "goto12";
				break;

				case SPAIN:
					loadPort = "Muelle_port";
					gotoLocator = "goto6";
				break;

				case PIRATE:
					loadPort = "QC_port";
					gotoGroup = "reload"; 
					gotoLocator = "reload3_back";
				break;

				case HOLLAND:
					loadPort = "Douwesen_port";
					gotoLocator = "goto15";
				break;

				case PORTUGAL:
					loadPort = "Conceicao_port";
					gotoLocator = "goto13";
				break;
				case AMERICA:
					loadPort = "Eleuthera_Port";
					gotoLocator = "goto10";
				break;

// KK -->
				case PERSONAL_NATION:
					loadPort = "Oxbay_port";
				break;
// <-- KK
			}
			Locations[FindLocation(loadPort)].locators_radius.(gotoGroup).(gotoLocator) = 0.5;
			CloseQuestHeader(questRecord);
// added by MAXIMUS [choose character mod] <--

			if(makeint(PChar.money) == 1000) AddMoneyToCharacter(PChar, 1000);
			if(CheckCharacterItem(PChar, "Spyglass1") == 0) GiveItem2Character(PChar, "Spyglass1");
			if(CheckCharacterItem(PChar, "medical1") == 0) TakeNItems(PChar, "medical1", 2); // PB
			if(CheckCharacterItem(PChar, PChar.start_weapon.blade) == 0) GiveItem2Character(PChar, PChar.start_weapon.blade);
			if(CheckCharacterItem(PChar, PChar.start_weapon.gun) == 0) GiveItem2Character(PChar, PChar.start_weapon.gun);
			DeleteAttribute(PChar, "start_weapon");

			EquiPCharacterbyItem(PChar, FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE));
			EquiPCharacterbyItem(PChar, FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE));
			EquiPCharacterbyItem(PChar, FindCharacterItemByGroup(&PChar, SPYGLASS_ITEM_TYPE));

	
		     //JRH ammo mod --->
			if (ENABLE_AMMOMOD) {	// LDH change
				if(CheckCharacterItem(PChar, "gunpowder") > 0) TakeNItems(PChar, "gunpowder", -12);
				if(CheckCharacterItem(PChar, "gunpowder") == 0) TakeNItems(PChar, "gunpowder", 6);
				if(CheckCharacterItem(PChar, "pistolbullets") > 0) TakeNItems(PChar, "pistolbullets", -12);
				if(CheckCharacterItem(PChar, "pistolbullets") == 0) TakeNItems(PChar, "pistolbullets", 6);
			}
		     //JRH ammo mod <---

// KK -->
			AddMoneyToCharacter(PChar, 1000);

			TutDeck.box1.money = makeint(0);
			DeleteAttribute(TutDeck, "box1.items"); // PB
			DeleteAttribute(TutDeck, "box2.items"); // JRH

			QDeck = BOARDER_SPAREBLADE;
			if (CheckAttribute(TutDeck, "WeaponsLocker.items." + QDeck) == false || TutDeck.WeaponsLocker.items.(QDeck) < 12)
				TutDeck.WeaponsLocker.items.(QDeck) = 12;
// <-- KK

// added by MAXIMUS [choose character mod] -->
			loadPort = "Oxbay_port"; 
			rldLocator = "reload2"; 

			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadPort = "Oxbay_port"; 
					rldLocator = "reload2";
				break;

				case FRANCE:
					loadPort = "Falaise_de_fleur_port_01"; 
					loadTown = "Falaise_de_fleur_location_03";
					gotoLocator = "goto12";
					rldLocator = "sea"; 
				break;

				case SPAIN:
					loadPort = "Muelle_port"; 
					loadTown = "Muelle_town_01";
					gotoLocator = "goto6";
					rldLocator = "reload3"; 
				break;

				case PIRATE:
					loadPort = "QC_port";
					loadTown = "QC_town";
					gotoGroup = "reload"; 
					gotoLocator = "reload3_back";
					rldLocator = "reload1"; 
				break;

				case HOLLAND:
					loadPort = "Douwesen_port"; 
					loadTown = "Douwesen_town";
					gotoLocator = "goto15";
					rldLocator = "reload2"; 
				break;

				case PORTUGAL:
					loadPort = "Conceicao_port";
					loadTown = "Conceicao_town";
					gotoLocator = "goto13";
					rldLocator = "reload2"; 
				break;
				case AMERICA:
					loadPort = "Eleuthera_Port";
					loadTown = "Eleuthera_Port";
					gotoLocator = "goto10";
					rldlocator = "reload2";
				break;
				case PERSONAL_NATION: // KK
					loadPort = "Oxbay_port"; 
					rldLocator = "reload2";
				break;
			}

// KK -->
			PChar.quest.TavernSitWaiting.win_condition.l1 = "ExitFromLocation";
			PChar.quest.TavernSitWaiting.win_condition.l1.character = PChar.id;
			PChar.quest.TavernSitWaiting.win_condition.l1.location = PChar.location;
			PChar.quest.TavernSitWaiting.win_condition = "TavernSitWaiting";

			LAi_QuestDelay("begining", 0.0);// "0." is bad, use something legit
			PChar.quest.Begining.over = "yes";
			PlaceFleetNearShore(loadPort);

			if (GetCharacterShipCabin(PChar) != "Cabin_none") {
				QDeck = GetCharacterShipQDeck(PChar);
				if (PChar.location == QDeck)
					rldLocator = "boatr";
				else
					rldLocator = "reload1";
				characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.TempNode = "Exit";
				characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "Exit";
				characters[GetCharacterIndex("Malcolm Hatcher")].condition = "reload";//MAXIMUS
				LAi_SetActorType(CharacterFromID("Malcolm Hatcher"));
				LAi_ActorGoToLocation(CharacterFromID("Malcolm Hatcher"), "reload", rldLocator, "none", "", "", "", 50);
			} else {
				characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "SkipTutorialOnShip";
				LAi_SetStayType(CharacterFromID("Malcolm Hatcher"));
				QDeck = GetCharacterShipQDeck(CharacterFromID("Malcolm Hatcher"));
			}
			TutDeck.reload.l1.disable = 0;
			Locations[FindLocation(QDeck)].reload.l4.disable = 0;
			Locations[FindLocation(QDeck)].reload.l5.disable = 0;
			Locations[FindLocation(QDeck)].reload.l6.disable = 0;

			TutDeck.box1.money = makeint(0);
			DeleteAttribute(TutDeck, "box1.items"); // PB
			DeleteAttribute(TutDeck, "box2.items"); // JRH
// <-- KK

			SetQuestHeader("Tutorial_SpyGlass");
			AddQuestRecord("Tutorial_SpyGlass", 1);

			PChar.quest.Tut_BuySpyGlass.win_condition.l1 = "item";
			PChar.quest.Tut_BuySpyGlass.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_BuySpyGlass.win_condition.l1.item = "SpyGlass2";
			PChar.quest.Tut_BuySpyGlass.win_condition = "Tut_BuySpyGlass";
			PChar.quest.Tut_BuySpyGlass.fail_condition = "Tut_BuySpyGlass";

			// TIH --> alternative win conditions Spe3'06
			PChar.quest.Tut_BuySpyGlass3.win_condition.l1 = "item";
			PChar.quest.Tut_BuySpyGlass3.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_BuySpyGlass3.win_condition.l1.item = "SpyGlass3";
			PChar.quest.Tut_BuySpyGlass3.win_condition = "Tut_BuySpyGlass";
			PChar.quest.Tut_BuySpyGlass4.win_condition.l1 = "item";
			PChar.quest.Tut_BuySpyGlass4.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_BuySpyGlass4.win_condition.l1.item = "SpyGlass4";
			PChar.quest.Tut_BuySpyGlass4.win_condition = "Tut_BuySpyGlass";
			// TIH <--

// KK -->
			if (GetCargoGoods(PChar, CharGood1) > 0 || GetCargoGoods(PChar, CharGood2) > 0) {
				SetQuestHeader("Tutorial_Store");
				loadStore = "";
				if (GetCargoGoods(PChar, CharGood1) > 0) loadStore = strlower(LanguageConvertString(lngSeaGoodsFileID,"seg_"+Goods[CharGood1].name));
				if (CharGood1 != CharGood2) {
					if (GetCargoGoods(PChar, CharGood1) > 0 && GetCargoGoods(PChar, CharGood2) > 0) loadStore += " " + XI_ConvertString("and");
					if (GetCargoGoods(PChar, CharGood2) > 0) loadStore += " " + strlower(LanguageConvertString(lngSeaGoodsFileID,"seg_"+Goods[CharGood2].name));
				}
				Preprocessor_AddQuestData("goods",  loadStore);
				AddQuestRecord("Tutorial_Store", 1);
				//Preprocessor_Remove("goods");

				if (GetCargoGoods(PChar, CharGood1) > 0) {
					PChar.quest.Tut_SellGoods.win_condition.l1 = "goods";
					PChar.quest.Tut_SellGoods.win_condition.l1.character = PChar.id;
					PChar.quest.Tut_SellGoods.win_condition.l1.goods = CharGood1;
					PChar.quest.Tut_SellGoods.win_condition.l1.quantity = "0";
					PChar.quest.Tut_SellGoods.win_condition.l1.operation = "=";
					PChar.quest.Tut_SellGoods.win_condition = "Tut_SellGoods";
					PChar.quest.Tut_SellGoods.fail_condition = "Tut_SellGoods";
				}
				if (GetCargoGoods(PChar, CharGood2) > 0) {
					PChar.quest.Tut_SellGoods.win_condition.l2 = "goods";
					PChar.quest.Tut_SellGoods.win_condition.l2.character = PChar.id;
					PChar.quest.Tut_SellGoods.win_condition.l2.goods = CharGood2;
					PChar.quest.Tut_SellGoods.win_condition.l2.quantity = "0";
					PChar.quest.Tut_SellGoods.win_condition.l2.operation = "=";
					PChar.quest.Tut_SellGoods.win_condition = "Tut_SellGoods";
					PChar.quest.Tut_SellGoods.fail_condition = "Tut_SellGoods";
				}
			}
// <-- KK

			SetQuestHeader("Tutorial_Shipyard");
			AddQuestRecord("Tutorial_Shipyard", 1);

			PChar.quest.Tut_RepairShip.win_condition.l1 = "Ship_HP";
			PChar.quest.Tut_RepairShip.win_condition.l1.character = PChar.id;
//NK -->
			PChar.quest.Tut_RepairShip.win_condition.l1.quantity = GetCurrentShipHP(PChar);
// NK <-- 
			PChar.quest.Tut_RepairShip.win_condition.l1.operation = ">"; // TIH so when HP increases instead (if they bought a new ship)
		//	PChar.quest.Tut_RepairShip.win_condition.l1.operation = "=";
			PChar.quest.Tut_RepairShip.win_condition = "Tut_RepairShip";
			PChar.quest.Tut_RepairShip.fail_condition = "Tut_RepairShip";

			SetQuestHeader("Tutorial_Tavern");
			AddQuestRecord("Tutorial_Tavern", 1);

			PChar.quest.Tut_HireCrew.win_condition.l1 = "Crew_Space";
			PChar.quest.Tut_HireCrew.win_condition.l1.character = PChar.id;
			PChar.quest.Tut_HireCrew.win_condition.l1.quantity = "0";
			PChar.quest.Tut_HireCrew.win_condition.l1.operation = "=";
			PChar.quest.Tut_HireCrew.win_condition = "Tut_HireCrew";
			PChar.quest.Tut_HireCrew.fail_condition = "Tut_HireCrew";

			PChar.quest.Tut_KillTutor.over = "yes";
			// NK -->
// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			loadPort = "Oxbay_port";
			gotoGroup = "goto";
			gotoLocator = "goto18";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadTown = "Oxbay_town";
					loadPort = "Oxbay_port";
					gotoLocator = "goto18";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
				break;
				case FRANCE:
					loadTown = "Falaise_de_fleur_location_03";
					loadPort = "Falaise_de_fleur_port_01";
					gotoLocator = "goto12";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;
					Locations[FindLocation(loadPort)].reload.l6.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;

					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l1.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l2.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l3.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l4.disable = 0;
				break;
				case SPAIN:
					loadTown = "Muelle_town_01";
					loadPort = "Muelle_port";
					gotoLocator = "goto6";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
					Locations[FindLocation(loadTown)].reload.l15.disable = 0;
					Locations[FindLocation(loadTown)].reload.l16.disable = 0;
					Locations[FindLocation(loadTown)].reload.l17.disable = 0;
					Locations[FindLocation(loadTown)].reload.l18.disable = 0;
					Locations[FindLocation(loadTown)].reload.l19.disable = 0;
				break;
				case PIRATE:
					loadTown = "QC_town";
					loadPort = "QC_port";
					gotoGroup = "reload"; 
					gotoLocator = "reload3_back";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;

					Locations[FindLocation("QC_town_exit")].reload.l1.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l2.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l3.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l4.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l5.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l6.disable = 0;
				break;
				case HOLLAND:
					loadTown = "Douwesen_town";
					loadPort = "Douwesen_port";
					gotoLocator = "goto15";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
				break;
				case PORTUGAL:
					loadTown = "Conceicao_town";
					loadPort = "Conceicao_port";
					gotoLocator = "goto13";

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
				break;
				case AMERICA:
					loadTown = "Eleuthera_Port";
					loadPort = "Eleuthera_Port";
					gotoLocator = "goto10";

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
				// TIH <--
			}

			Locations[FindLocation(loadPort)].reload.l1.disable = 0;
			Locations[FindLocation(loadPort)].reload.l3.disable = 0;
			Locations[FindLocation(loadPort)].reload.l4.disable = 0;

			Locations[FindLocation(loadTown)].reload.l1.disable = 0;
			if(CheckAttribute(Locations[FindLocation(loadTown)].reload,"l2")) Locations[FindLocation(loadTown)].reload.l2.disable = 0;
			Locations[FindLocation(loadTown)].reload.l3.disable = 0;
			Locations[FindLocation(loadTown)].reload.l4.disable = 0;
			Locations[FindLocation(loadTown)].reload.l5.disable = 0;
			Locations[FindLocation(loadTown)].reload.l6.disable = 0;
			Locations[FindLocation(loadTown)].reload.l7.disable = 0;

			Locations[FindLocation(loadPort)].locators_radius.(gotoGroup).(gotoLocator) = 0.5;
// added by MAXIMUS [choose character mod] <--

			TutDeck.reload.l1.disable = 0; // KK
			if(CheckAttribute(PChar,"location.first")) DisableFastTravel(true);//MAXIMUS: disables fastreload on tutorial deck
			LAi_SetPlayerType(PChar);
		break;

// ccc Stormy Start mod 
// in Malcolm's dialog you can choose to skip the whole Oxbay tutorial. Instead the storm will drive you to some other coast where the game will start.

		case "stormystart":	// this case terminates and clears the original gamestart

			LAi_QuestDelay("begining", 0.0);	// the quest "begining" originally runs if you appear in Oxbay
			PChar.quest.Begining.over = "yes";	// Now we must run and close it from here

			// this section is the remainder of the case "Tut_SkipTutorialOnShip" which terminates the tutorial

			locDisableUpdateTime = false;
			LAi_LockFightMode(PChar, false);
			EndQuestMovie();TrackQuestMovie("end","stormystart");
			//LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(PChar);

			ResetHP(&PChar); // NK 05-07-03 - LAi_SetHP(PChar, LAI_DEFAULT_HP + sti(PChar.rank) * 5, LAI_DEFAULT_HP + sti(PChar.rank) * 5); //NK

			PChar.quest.Tut_KillTutor.over = "yes";

			// NK --> This section opens doors which were closed for tutorial

// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			loadPort = "Oxbay_port";
			questRecord = "Tutorial_AppearedOnIsland";
			gotoGroup = "goto";
			gotoLocator = "goto18";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadTown = "Oxbay_town";
					loadPort = "Oxbay_port";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
				break;
				case FRANCE:
					loadTown = "Falaise_de_fleur_location_03"; 
					loadPort = "Falaise_de_fleur_port_01";

					gotoLocator = "goto12";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;
					Locations[FindLocation(loadPort)].reload.l6.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l1.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l2.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l3.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l4.disable = 0;
				break;
				case SPAIN:
					loadTown = "Muelle_town_01"; 
					loadPort = "Muelle_port";
					gotoLocator = "goto6";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
					Locations[FindLocation(loadTown)].reload.l15.disable = 0;
					Locations[FindLocation(loadTown)].reload.l16.disable = 0;
					Locations[FindLocation(loadTown)].reload.l17.disable = 0;
					Locations[FindLocation(loadTown)].reload.l18.disable = 0;
					Locations[FindLocation(loadTown)].reload.l19.disable = 0;
				break;
				case PIRATE:
					loadTown = "QC_town"; 
					loadPort = "QC_port";
					gotoGroup = "reload"; 
					gotoLocator = "reload3_back";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;

					Locations[FindLocation("QC_town_exit")].reload.l1.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l2.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l3.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l4.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l5.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l6.disable = 0;
				break;
				case HOLLAND:
					loadTown = "Douwesen_town"; 
					loadPort = "Douwesen_port";
					gotoLocator = "goto15";

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
				break;
				case PORTUGAL:
					loadTown = "Conceicao_town";
					loadPort = "Conceicao_port";
					gotoLocator = "goto13";

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
				break;
				case AMERICA:
					loadTown = "Eleuthera_Port";
					loadPort = "Eleuthera_Port";
					gotoLocator = "goto10";

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
					Locations[FindLocation(loadTown)].reload.l15.disable = 0;
					Locations[FindLocation(loadTown)].reload.l16.disable = 0;
					Locations[FindLocation(loadTown)].reload.l17.disable = 0;
					Locations[FindLocation(loadTown)].reload.l18.disable = 0;
					Locations[FindLocation(loadTown)].reload.l19.disable = 0;
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
				// TIH <--
			}

			Locations[FindLocation(loadPort)].reload.l1.disable = 0;
			Locations[FindLocation(loadPort)].reload.l3.disable = 0;
			Locations[FindLocation(loadPort)].reload.l4.disable = 0;

			Locations[FindLocation(loadTown)].reload.l1.disable = 0;
			Locations[FindLocation(loadTown)].reload.l2.disable = 0;
			Locations[FindLocation(loadTown)].reload.l3.disable = 0;
			Locations[FindLocation(loadTown)].reload.l4.disable = 0;
			Locations[FindLocation(loadTown)].reload.l5.disable = 0;
			Locations[FindLocation(loadTown)].reload.l6.disable = 0;
			Locations[FindLocation(loadTown)].reload.l7.disable = 0;

			Locations[FindLocation(loadPort)].locators_radius.(gotoGroup).(gotoLocator) = 0.5;

			CloseQuestHeader(questRecord);
// added by MAXIMUS [choose character mod] <--

			LAi_QuestDelay("TavernSitWaiting", 0.0);		// lets Malcolm disappear
			LAi_QuestDelay("stormystart2", 1.0);			// starts the next case
			LAi_SetPlayerType(pchar);						// ensures you're free to move after the reload

		break;


		case "stormystart2":	// this case is only seperate to show the video uninterrupted
			bMainMenuLaunchAfterVideo = true; //TIH - makes black screen after movie, not cabin scene
			PostVideoAndQuest("storm",1, "stormystart3"); //TIH - time adjustment	// starts the next case
		break;

		case "stormystart3":	// casts you ashore at a random beach with random resources
			DeleteQuestHeader("Tutorial_AppearedOnIsland"); // PB: No need
			SetCharacterGoods(PChar, CharGood1, 0); // dumps your cargo // KK
			SetCharacterGoods(PChar, CharGood2, 0); // KK

			PChar.ship.hp =     GetCharacterShipHP(PChar) * (rand(6)+2)/10;		// PB Storm Damage: between 20% and 80% of previous number
			SetCrewQuantity(PChar, GetCrewQuantity(PChar) * (rand(6)+2)/10);	// PB Storm Damage: between 20% and 80% of previous number

			// next section gives you a random amount of money and equipment
			GiveItem2Character(PChar, "blade"+ (1+ rand(9)) );				// gives you blade1, blade2... or blade10
			EquipCharacterByItem(PChar, FindCharacterItemByGroup(PChar,BLADE_ITEM_TYPE));	// PB: equips your blade
			GiveItem2Character(PChar, "PISTOL"+ (1+ rand(1)) );				// PB: added to give you a default pistol too
			EquipCharacterByItem(PChar, FindCharacterItemByGroup(PChar,GUN_ITEM_TYPE));	// PB: equips your pistol
			GiveItem2Character(PChar, "Spyglass" + (1+rand(2)) );
			EquipCharacterByItem(PChar, FindCharacterItemByGroup(PChar,SPYGLASS_ITEM_TYPE));// PB: equips your spyglass
			AddMoneyToCharacter(PChar, rand(4000));
			GiveItem2Character(PChar, "Jewelry" + (1+rand(9)) );
			GiveItem2Character(PChar, "Mineral" + (1+rand(2)) );
			TakeNItems(PChar, "medical1", 1 + rand(2)); // PB

     		// ccc special weapons, SW assembly kit must be installed !
			TakeNItems(PChar, "pistolbbuss", rand(1));	
			TakeNItems(PChar, "bladeX1", rand(1));
			TakeNItems(PChar, "bladeX2", rand(1));
			TakeNItems(PChar, "bladeX3", 1);
			TakeNItems(PChar, "pistolpdart", rand(3));
			TakeNItems(PChar, "pistolgrenade", rand(3));
			TakeNItems(PChar, "pistolgas", rand(3));
			TakeNItems(PChar, "pistolrock", rand(3));
			TakeNItems(PChar, "pistolstink", rand(3));

		    //JRH ammo mod --->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakeNItems(PChar, "gunpowder", 3 + rand(3));
				if (CheckCharacterItem(PChar,"pistolbbuss")) {
					TakeNItems(PChar, "pistolgrapes", 3 + rand(3));	
					RemoveCharacterEquip(PChar, GUN_ITEM_TYPE );
					EquipCharacterByItem(PChar, "pistolbbuss");					
				} else {
					TakeNItems(PChar, "pistolbullets", 3 + rand(3));
				}
			}
		    //JRH ammo mod <---

			DeleteAttribute(PChar,"vcskip");	// NK 04-06
			SetNextWeather("Day Storm");		// Sets stormy weather

			if(STORMY_START_CHOICES > 19) i = 19;	// GR: don't allow Cozumel because it starts with
			else i = STORMY_START_CHOICES;		//     the inaccessible island model
			switch(rand(i) )			// ccc mar 06  New islands
			{
				case 0:
					loadPort = "Douwesen_shore_02"; // PB (separated from ship)
					loadTown = "Douwesen_shore_01";
					rldLocator = "reload1";
				break;

				case 1:
					loadPort = "Conceicao_shore_02"; // PB (separated from ship)
					loadTown = "Conceicao_shore_01";
					rldLocator = "reload1";
				break;

				case 2:
					loadPort = "Falaise_de_fleur_port_01"; // PB (separated from ship)
					loadTown = "Falaise_de_fleur_shore";
					rldLocator = "reload1";
				break;

				case 3:
					loadPort = "Muelle_port"; // PB (separated from ship)
					loadTown = "Muelle_shore";
					rldLocator = "reload3";
				break;

				case 4:
					loadPort = "QC_Shore1"; // PB (separated from ship)
					loadTown = "QC_port";
					rldLocator = "reload1";
				break;

				case 5:
					loadPort = "Redmond_shore_02"; // PB (separated from ship)
					loadTown = "Redmond_shore_01";
					rldLocator = "reload1";
				break;

				case 6:
					loadPort = "Redmond_shore_01";
					loadTown = "Redmond_shore_02"; // KK (separated from ship)
					rldLocator = "reload1";
				break;

				case 7:
					loadPort = "Douwesen_shore_01";
					loadTown = "Douwesen_shore_02"; // KK (separated from ship)
					rldLocator = "reload1";
				break;

				case 8:
					loadPort = "Conceicao_shore_01";
					loadTown = "Conceicao_shore_02"; // KK (separated from ship)
					rldLocator = "see";
				break;

				case 9:
					loadPort = "Antigua_port"; // KK (separated from ship)
					loadTown = "Antigua_shore";
					rldLocator = "reload1";
				break;

				case 10:
					loadPort = "Cayman_Shore_01";
					loadTown = "Cayman_Shore_02"; // GR (separated from ship)
					rldLocator = "see"; // ccc Nov06, was wrong,"reload2";
				break;

				case 11:
					loadPort = "Cayman_Shore_02";
					loadTown = "Cayman_Shore_01"; // KK (separated from ship)
					rldLocator = "reload1";
				break;

				case 12:
					loadPort = "Santo_Domingo_port";	// Ship to Santo Domingo
					loadTown = "Hispaniola_shore_01";	// Player to Boca de Yuman
					rldLocator = "reload1";
				break;

				case 13:
					loadPort = "PoPrince_Port";		// Ship to Port au Prince
					loadTown = "Hispaniola_shore_02";	// Player to Boca de Hubon
					rldLocator = "reload1";
				break;

				case 14:
					loadPort = "Cuba_Shore_04"; // PB (separated from ship)
					loadTown = "Cuba_shore_01";
					rldLocator = "reload1";
				break;

				case 15:
					loadPort = "Guadeloupe_Port"; // PB (separated from ship)
					loadTown = "Guadeloupe_shore_01";
					rldLocator = "see";
				break;

				case 16:
					loadPort = "SaintMartin_shore_02"; // PB (separated from ship)
					loadTown = "SaintMartin_shore_01";
					rldLocator = "reload1";
				break;

				case 17:
					loadPort = "SaintMartin_shore_01";
					loadTown = "SaintMartin_shore_02"; // KK (separated from ship)
					rldLocator = "see";
				break;

				case 18:
					loadPort = "Oxbay_shore_01";
					loadTown = "Oxbay_shore_02"; // KK (separated from ship)
					rldLocator = "reload1";
				break;

				case 19:
					loadPort = "Oxbay_shore_02"; // PB (separated from ship)
					loadTown = "Oxbay_shore_01";
					rldLocator = "see";
				break;

				// default:
				loadPort = "KhaelRoa_port";
				loadTown = "KhaelRoa_port";
				rldLocator = "reload1";
			}
			i = getRandomContrabandGood(GetIslandByID(FindIslandByLocation(loadTown)));
			if (i > 0) AddCharacterGoods(PChar, i, (2.0+rand(2))/10.0 * GetCharacterFreeSpace(PChar, i) ); // PB&Levis: Between 20%-40% contraband
			SetQuestHeader("StormyStart");
			AddQuestRecord("StormyStart", 1);
			AddQuestRecord("StormyStart", 2);
			CloseQuestHeader("StormyStart");

			DoQuestReloadToLocation(loadTown, "reload", rldLocator, "_");
			PlaceFleetNearShore(loadPort); // KK
			SafePortLeave(GetLocationNationFromID(loadPort), false);	// GR: use false flag if you end up at a hostile port

			PostEvent("DoInfoShower",500,"s","");	//TIH - clears black screen
		break;
// ccc end stormy start mod

// KK -->
		case "Tut_SkipTutorialInPort":
			rldLocator = "Reload1";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					rldLocator = "reload1";
				break;

				case FRANCE:
					rldLocator = "Falaise_de_fleur_location_01_02";
				break;

				case SPAIN:
					rldLocator = "reload2";
				break;

				case PIRATE:
					rldLocator = "Reload3";
				break;

				case HOLLAND:
					rldLocator = "Reload3"; 
				break;

				case PORTUGAL:
					rldLocator = "reload1";
				break;
				case AMERICA:
					rldLocator = "reload4_back";
				break;

				case PERSONAL_NATION: // KK 
					rldLocator = "reload1";
				break;
			}

			LAi_SetActorType(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorGoToLocator(CharacterFromID("Malcolm Hatcher"), "reload", rldLocator, "Tut_SkipTutorialInPort_AfterMalcolmGone", 0);
		break;
// <-- KK

		case "Tut_SkipTutorialInPort_AfterMalcolmGone": // KK
			DeleteAttribute(&PChar,"vcskip"); // NK 04-06

			LAi_LockFightMode(PChar, false);

// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			loadPort = "Oxbay_port";
			gotoGroup = "goto";
			gotoLocator = "goto18";
			rldLocator = "Reload1";
			questRecord = "Tutorial_AppearedOnIsland";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadTown = "Oxbay_town";
					loadPort = "Oxbay_port";
					rldLocator = "reload1";
					switch(PChar.location)
					{
						case "Oxbay_port": rldLocator = "reload1"; break;
						case "Oxbay_town": rldLocator = "reload13"; break;
					}

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
				break;
				
				case FRANCE:
					loadTown = "Falaise_de_fleur_location_03";
					loadPort = "Falaise_de_fleur_port_01";
					gotoLocator = "goto12";
					rldLocator = "Falaise_de_fleur_location_01_02";
					switch(PChar.location)
					{
						case "Falaise_de_fleur_port_01": rldLocator = "Falaise_de_fleur_location_01_02"; break;
						case "Falaise_de_fleur_location_03": rldLocator = "Falaise_de_fleur_tavern"; break;
						case "Falaise_de_fleur_location_04": rldLocator = "Falaise_de_fleur_location_04_03"; break;
					}

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;
					Locations[FindLocation(loadPort)].reload.l6.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l1.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l2.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l3.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l4.disable = 0;
					
					LAi_QuestDelay("begining", 0.0); 
					PChar.quest.Begining.over = "yes";
				break;

				case SPAIN:
					loadTown = "Muelle_town_01";
					loadPort = "Muelle_port";
					gotoLocator = "goto6";
					rldLocator = "reload2";
					switch(PChar.location)
					{
						case "Muelle_port": rldLocator = "reload2"; break;
						case "Muelle_town_01": rldLocator = "reload14"; break;
					}

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
					Locations[FindLocation(loadTown)].reload.l15.disable = 0;
					Locations[FindLocation(loadTown)].reload.l16.disable = 0;
					Locations[FindLocation(loadTown)].reload.l17.disable = 0;
					Locations[FindLocation(loadTown)].reload.l18.disable = 0;
					Locations[FindLocation(loadTown)].reload.l19.disable = 0;
					
					LAi_QuestDelay("begining", 0.0); 
					PChar.quest.Begining.over = "yes";
				break;
				
				case PIRATE:
					loadTown = "QC_town";
					loadPort = "QC_port";
					gotoGroup = "reload"; 
					gotoLocator = "reload3_back";
					rldLocator = "Reload3";
					switch(PChar.location)
					{
						case "QC_port": rldLocator = "reload3"; break;
						case "QC_town": rldLocator = "reload2"; break;
						case "QC_town_exit": rldLocator = "Reload1"; break;
					}

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;

					Locations[FindLocation("QC_town_exit")].reload.l1.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l2.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l3.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l4.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l5.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l6.disable = 0;
					
					LAi_QuestDelay("begining", 0.0); 
					PChar.quest.Begining.over = "yes";
				break;

				case HOLLAND:
					loadTown = "Douwesen_town";
					loadPort = "Douwesen_port"; 
					gotoLocator = "goto15"; 
					rldLocator = "Reload3"; 

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;

					LAi_QuestDelay("begining", 0.0); 
					PChar.quest.Begining.over = "yes";
				break;

				case PORTUGAL:
					loadTown = "Conceicao_town";
					loadPort = "Conceicao_port";
					gotoLocator = "goto13";
					rldLocator = "reload1";
					switch(PChar.location)
					{
						case "Conceicao_port": rldLocator = "reload1"; break;
						case "Conceicao_town": rldLocator = "reload4"; break;
					}

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;

					LAi_QuestDelay("begining", 0.0); 
					PChar.quest.Begining.over = "yes";
				break;
				case AMERICA:
					loadTown = "Eleuthera_Port";
					loadPort = "Eleuthera_Port";
					gotoLocator = "goto13";
					rldLocator = "reload1";
					switch(PChar.location)
					{
						case "Eleuthera_Port": rldLocator = "reload2"; break;
					}

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;

					LAi_QuestDelay("begining", 0.0); 
					PChar.quest.Begining.over = "yes";
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					switch(PChar.location)
					{
						case "Oxbay_port": rldLocator = "reload1"; break;
						case "Oxbay_town": rldLocator = "reload13"; break;
					}
					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
				// TIH <--
			}
			PlaceFleetNearShore(loadPort); // KK

			Locations[FindLocation(loadPort)].reload.l1.disable = 0;
			Locations[FindLocation(loadPort)].reload.l3.disable = 0;
			Locations[FindLocation(loadPort)].reload.l4.disable = 0;

			Locations[FindLocation(loadTown)].reload.l1.disable = 0;
			Locations[FindLocation(loadTown)].reload.l2.disable = 0;
			Locations[FindLocation(loadTown)].reload.l3.disable = 0;
			Locations[FindLocation(loadTown)].reload.l4.disable = 0;
			Locations[FindLocation(loadTown)].reload.l5.disable = 0;
			Locations[FindLocation(loadTown)].reload.l6.disable = 0;
			Locations[FindLocation(loadTown)].reload.l7.disable = 0;

			Locations[FindLocation(loadPort)].locators_radius.(gotoGroup).(gotoLocator) = 0.5;
// added by MAXIMUS [choose character mod] <--
			LAi_QuestDelay("TavernSitWaiting", 0); // KK

			EndQuestMovie();
			locDisableUpdateTime = false;
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(PChar);

			PChar.quest.Tut_FollowTheSpyglass.over = "yes";
			PChar.quest.Tut_ReloadToOxbayTown.over = "yes";

			CloseQuestHeader(questRecord);

			PChar.quest.Tut_KillTutor.over = "yes";
		break;

// added by MAXIMUS [choose character mod] -->
		case "TavernSitWaiting":
// KK -->
			loadTown = GetTownIDFromLocID(PChar.location);
			loadTavern = FindTownTavern(PChar.location);
			if (loadTown == "" || loadTavern == "") {
				loadTavern = "Oxbay_tavern";
				switch(GetCurrentFlag())
				{
					case ENGLAND: loadTown = "Oxbay"; loadTavern = "Oxbay_tavern"; break;
					case FRANCE: loadTown = "Falaise de Fleur"; loadTavern = "Falaise_de_fleur_tavern"; break;
					case SPAIN: loadTown = "Isla Muelle"; loadTavern = "Muelle_Tavern"; break;
					case PIRATE: loadTown = "Quebradas Costillas"; loadTavern = "QC_Tavern"; break;
					case HOLLAND: loadTown = "Douwesen"; loadTavern = "Douwesen_tavern"; break;
					case PORTUGAL: loadTown = "Conceicao"; loadTavern = "Conceicao_Tavern"; break;
					case AMERICA: loadTown = "Eleuthera"; loadTavern = "Eleuthera_tavern"; break;
					case PERSONAL_NATION: loadTown = "Oxbay"; loadTavern = "Oxbay_tavern"; break;
				}
			}
			if (GetCurrentFlag() == AMERICA)	ChangeCharacterAddressGroup(CharacterFromID("Malcolm Hatcher"), loadTavern, "sit", "sit5");
			else								ChangeCharacterAddressGroup(CharacterFromID("Malcolm Hatcher"), loadTavern, "sit", "sit13");
			LAi_SetSitType(CharacterFromID("Malcolm Hatcher"));
			characters[GetCharacterIndex("Malcolm Hatcher")].Dialog.CurrentNode = "Questions";
			LAi_group_MoveCharacter(CharacterFromID("Malcolm Hatcher"), GetTownCitizenGroup(loadTown));

			if (GetCurrentFlag() == PIRATE) {
				PChar.quest.Install_Voysey_And_Blythe.win_condition.l1 = "location";
				PChar.quest.Install_Voysey_And_Blythe.win_condition.l1.character = PChar.id;
				PChar.quest.Install_Voysey_And_Blythe.win_condition.l1.location = "QC_town_exit";
				PChar.quest.Install_Voysey_And_Blythe.win_condition = "Install_Voysey_And_Blythe";
			} else {
				LAi_QuestDelay("Install_Voysey_And_Blythe", 0.0);
			}

			bChangeNation = true;
// <-- KK
			bDisableFastReload = 0;
			TutDeck.reload.l1.disable = 0;	//PW remove locked cabin icon
// added by MAXIMUS [choose character mod] <--
		break;

// KK -->
		case "Tut_SkipTutorialInTown":
			rldLocator = "Reload1";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					rldLocator = "reload1";
					switch(PChar.location)
					{
						case "Oxbay_port": rldLocator = "reload1"; break;
						case "Oxbay_town": rldLocator = "reload13"; break;
					}
				break;

				case FRANCE:
					rldLocator = "Falaise_de_fleur_location_01_02";
					switch(PChar.location)
					{
						case "Falaise_de_fleur_port_01": rldLocator = "Falaise_de_fleur_location_01_02"; break;
						case "Falaise_de_fleur_location_03": rldLocator = "Falaise_de_fleur_tavern"; break;
						case "Falaise_de_fleur_location_04": rldLocator = "Falaise_de_fleur_location_04_03"; break;
					}
				break;

				case SPAIN:
					rldLocator = "reload2";
					switch(PChar.location)
					{
						case "Muelle_port": rldLocator = "reload2"; break;
						case "Muelle_town_01": rldLocator = "reload14"; break;
					}
				break;

				case PIRATE:
					rldLocator = "Reload3";
					switch(PChar.location)
					{
						case "QC_port": rldLocator = "reload3"; break;
						case "QC_town": rldLocator = "reload2"; break;
						case "QC_town_exit": rldLocator = "Reload1"; break;
					}
				break;

				case HOLLAND:
					rldLocator = "Reload3"; 
				break;

				case PORTUGAL:
					rldLocator = "reload1";
					switch(PChar.location)
					{
						case "Conceicao_port": rldLocator = "reload1"; break;
						case "Conceicao_town": rldLocator = "reload4"; break;
					}
				break;
				case AMERICA:
					rldLocator = "reload4_back";
					switch(PChar.location)
					{
						case "Eleuthera_Port": rldLocator = "reload4_back"; break;
					}
				break;

				case PERSONAL_NATION: // KK
					rldLocator = "reload1";
					switch(PChar.location)
					{
						case "Oxbay_port": rldLocator = "reload1"; break;
						case "Oxbay_town": rldLocator = "reload13"; break;
					}
				break;
			}

			LAi_SetActorType(CharacterFromID("Malcolm Hatcher"));
			LAi_ActorGoToLocator(CharacterFromID("Malcolm Hatcher"), "reload", rldLocator, "Tut_SkipTutorialInTown_AfterMalcolmGone", 0);
		break;
// <-- KK

		case "Tut_SkipTutorialInTown_AfterMalcolmGone":
			DeleteAttribute(&PChar,"vcskip"); // NK 04-06

			LAi_LockFightMode(PChar, false);

// added by MAXIMUS [choose character mod] -->
			loadTown = "Oxbay_town";
			loadPort = "Oxbay_port";
			gotoGroup = "goto";
			gotoLocator = "goto18";
			rldLocator = "Reload1";
			questRecord = "Tutorial_AppearedOnIsland";
			switch(GetCurrentFlag())
			{
				case ENGLAND:
					loadTown = "Oxbay_town";
					loadPort = "Oxbay_port";
					rldLocator = "reload1";
					switch(PChar.location)
					{
						case "Oxbay_port": rldLocator = "reload1"; break;
						case "Oxbay_town": rldLocator = "reload13"; break;
					}

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
				break;
				
				case FRANCE:
					loadTown = "Falaise_de_fleur_location_03";
					loadPort = "Falaise_de_fleur_port_01";
					gotoLocator = "goto12";
					rldLocator = "Falaise_de_fleur_location_01_02";
					switch(PChar.location)
					{
						case "Falaise_de_fleur_port_01": rldLocator = "Falaise_de_fleur_location_01_02"; break;
						case "Falaise_de_fleur_location_03": rldLocator = "Falaise_de_fleur_tavern"; break;
						case "Falaise_de_fleur_location_04": rldLocator = "Falaise_de_fleur_location_04_03"; break;
					}

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;
					Locations[FindLocation(loadPort)].reload.l6.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l1.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l2.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l3.disable = 0;
					Locations[FindLocation("Falaise_de_fleur_location_04")].reload.l4.disable = 0;
				break;

				case SPAIN:
					loadTown = "Muelle_town_01";
					loadPort = "Muelle_port";
					gotoLocator = "goto6";
					rldLocator = "reload2";
					switch(PChar.location)
					{
						case "Muelle_port": rldLocator = "reload2"; break;
						case "Muelle_town_01": rldLocator = "reload14"; break;
					}

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
					Locations[FindLocation(loadTown)].reload.l15.disable = 0;
					Locations[FindLocation(loadTown)].reload.l16.disable = 0;
					Locations[FindLocation(loadTown)].reload.l17.disable = 0;
					Locations[FindLocation(loadTown)].reload.l18.disable = 0;
					Locations[FindLocation(loadTown)].reload.l19.disable = 0;
				break;
				
				case PIRATE:
					loadTown = "QC_town";
					loadPort = "QC_port";
					gotoGroup = "reload"; 
					gotoLocator = "reload3_back";
					rldLocator = "Reload3";
					switch(PChar.location)
					{
						case "QC_port": rldLocator = "reload3"; break;
						case "QC_town": rldLocator = "reload2"; break;
						case "QC_town_exit": rldLocator = "Reload1"; break;
					}

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;

					Locations[FindLocation("QC_town_exit")].reload.l1.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l2.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l3.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l4.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l5.disable = 0;
					Locations[FindLocation("QC_town_exit")].reload.l6.disable = 0;
				break;

				case HOLLAND:
					loadTown = "Douwesen_town";
					loadPort = "Douwesen_port"; 
					gotoLocator = "goto15"; 
					rldLocator = "Reload3"; 

					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadPort)].reload.l5.disable = 0;

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
				break;

				case PORTUGAL:
					loadTown = "Conceicao_town";
					loadPort = "Conceicao_port";
					gotoLocator = "goto13";
					rldLocator = "reload1";
					switch(PChar.location)
					{
						case "Conceicao_port": rldLocator = "reload1"; break;
						case "Conceicao_town": rldLocator = "reload4"; break;
					}

					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
				break;
				case AMERICA:
					loadTown = "Eleuthera_Port";
					loadPort = "Eleuthera_Port";
					gotoLocator = "goto13";
					rldLocator = "reload2";
					switch(PChar.location)
					{
						case "Eleuthera_Port": rldLocator = "reload2"; break;
					}
					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
				break;
				// TIH --> defaults added (mimics ENGLAND) Aug27'06
				// default:
					switch(PChar.location)
					{
						case "Oxbay_port": rldLocator = "reload1"; break;
						case "Oxbay_town": rldLocator = "reload13"; break;
					}
					Locations[FindLocation(loadPort)].reload.l2.disable = 0;
					Locations[FindLocation(loadTown)].reload.l8.disable = 0;
					Locations[FindLocation(loadTown)].reload.l9.disable = 0;
					Locations[FindLocation(loadTown)].reload.l10.disable = 0;
					Locations[FindLocation(loadTown)].reload.l11.disable = 0;
					Locations[FindLocation(loadTown)].reload.l12.disable = 0;
					Locations[FindLocation(loadTown)].reload.l13.disable = 0;
					Locations[FindLocation(loadTown)].reload.l14.disable = 0;
				// TIH <--
			}

// KK -->
			LAi_QuestDelay("begining", 0.0);
			PChar.quest.Begining.over = "yes";
			SetFleetInTown(GetTownIDFromLocID(loadPort), "PChar");
// <-- KK

			Locations[FindLocation(loadPort)].reload.l1.disable = 0;
			Locations[FindLocation(loadPort)].reload.l3.disable = 0;
			Locations[FindLocation(loadPort)].reload.l4.disable = 0;

			Locations[FindLocation(loadTown)].reload.l1.disable = 0;
			Locations[FindLocation(loadTown)].reload.l2.disable = 0;
			Locations[FindLocation(loadTown)].reload.l3.disable = 0;
			Locations[FindLocation(loadTown)].reload.l4.disable = 0;
			Locations[FindLocation(loadTown)].reload.l5.disable = 0;
			Locations[FindLocation(loadTown)].reload.l6.disable = 0;
			Locations[FindLocation(loadTown)].reload.l7.disable = 0;

// KK -->
			if (GetCharacterShipCabin(PChar) != "Cabin_none")
				QDeck = GetCharacterShipQDeck(PChar);
			else
				QDeck = GetCharacterShipQDeck(CharacterFromID("Malcolm Hatcher"));
			Locations[FindLocation(QDeck)].reload.l6.go = "Sea";
			Locations[FindLocation(QDeck)].reload.l6.label = "Sea.";
// <-- KK

			Locations[FindLocation(loadPort)].locators_radius.(gotoGroup).(gotoLocator) = 0.5;
// added by MAXIMUS [choose character mod] <--
			LAi_QuestDelay("TavernSitWaiting", 0.0); // KK

			EndQuestMovie();
			locDisableUpdateTime = false;
			LAi_RemoveCheckMinHP(CharacterFromID("Malcolm Hatcher"));
			LAi_RemoveCheckMinHP(PChar);

			CloseQuestHeader(questRecord);
// added by MAXIMUS [choose character mod] <--

			PChar.quest.Tut_KillTutor.over = "yes";
		break;

		PChar.questnotfound = true; // PB: Testing
	}
	LanguageCloseFile(lngSeaGoodsFileID);
}
