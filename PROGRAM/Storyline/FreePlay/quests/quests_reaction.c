void QuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld;
// KK -->
	int iPassenger, cidx, iHP, cc, i, times;
	float locx, locy, locz;
	string homelocation, homegroup, homelocator, homeisland;
	int crewQty = 0;
	string attr, level;
// <-- KK
	aref arship; // PB

	PChar = GetMainCharacter();

	switch(sQuestName)
	{
		case "begining":
// GR: choose island based on character nationality, this island will be checked for cancelling the tutorial -->
			switch(GetCurrentFlag())
			{
				case ENGLAND: homeisland = "Oxbay"; break;
				case FRANCE: homeisland = "FalaiseDeFleur"; break;
				case SPAIN: homeisland = "IslaMuelle"; break;
				case PIRATE: homeisland = "QuebradasCostillas"; break;
				case HOLLAND: homeisland = "Douwesen"; break;
				case PORTUGAL: homeisland = "Conceicao"; break;
				case AMERICA: homeisland = "Eleuthera"; break;
				homeisland = "Oxbay";
			}
			if (!CheckQuestAttribute("StartAdventure", "begin")) {
				pchar.quest.cancel_tutorial.win_condition.l1 = "location";
				pchar.quest.cancel_tutorial.win_condition.l1.location = homeisland;
				pchar.quest.cancel_tutorial.win_condition = "cancel_tutorial";
			}
// <<-- GR
			else LAi_QuestDelay("cancel_tutorial", 0.0); // KK
		break;

		case "cancel_tutorial":
// KK -->
			if (!CheckQuestAttribute("StartAdventure", "begin")) {

				DeleteQuestHeader("Tutorial_SpyGlass");
				DeleteQuestHeader("Tutorial_Store");
				DeleteQuestHeader("Tutorial_Shipyard");
				DeleteQuestHeader("Tutorial_Tavern");

				Pchar.quest.Tut_SellGoods.over = "yes";
				Pchar.quest.Tut_RepairShip.over = "yes";
				Pchar.quest.Tut_HireCrew.over = "yes";
			// TIH --> alternative methods for completion finished Sep3'06
				Pchar.quest.Tut_BuySpyGlass.over = "yes";
				Pchar.quest.Tut_BuySpyGlass3.over = "yes";
				Pchar.quest.Tut_BuySpyGlass4.over = "yes";
			// TIH <--
				DeleteAttribute(Pchar, "quest.tutorial.Spyglass");
			}
// <-- KK
		break;

///////////////////////////////////////////////////////////////
///// TALES OF A CHEVALIER
///////////////////////////////////////////////////////////////

		case "embora":
			PChar.quest.disable_rebirth = true;
			SetNextWeather("Foggy");
			pchar.originalmodel = pchar.model;
			SetQuestHeader("Beginning_Rogue");
			if (CharPlayerType == PLAYER_TYPE_ROGUE)
			{
				if (PChar.sex == "woman") AddQuestRecord("Beginning_Rogue", 6);
				else AddQuestRecord("Beginning_Rogue", 1);
			}
			else AddQuestRecord("Beginning_Rogue", 9);
			PChar.quest.celestino = "encontro";
			Pchar.quest.celestino.win_condition.l1 = "location";
			Pchar.quest.celestino.win_condition.l1.location = "Cuba_shore_03";
			PChar.quest.celestino.win_condition = "meetcelestino";
		break;

		case "meetcelestino":
			DisableFastTravel(true);
            ChangeCharacterAddressGroup(CharacterFromID("Celestino Villalobos"), "Cuba_shore_03", "goto", "citizen01");
            LAi_SetActorType(characterFromID("Celestino Villalobos"));
			LAi_ActorDialog(characterFromID("Celestino Villalobos"), pchar, "", 10.0, 1.0);
		break;

		case "fightcelestino":
			LAi_SetWarriorType(characterFromID("Celestino Villalobos"));
			LAi_group_MoveCharacter(characterFromID("Celestino Villalobos"), "QUEST_ENEMIES");
			LAi_group_SetRelation("QUEST_ENEMIES", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("QUEST_ENEMIES", LAI_GROUP_PLAYER, true);
			LAi_SetFightMode(PChar, true);

			pchar.quest.salgada_died.win_condition.l1 = "NPC_Death";
			pchar.quest.salgada_died.win_condition.l1.character = "Celestino Villalobos";
			pchar.quest.salgada_died.win_condition = "vientsoldado";
		break;

		case "vientsoldado":
			LAi_SetFightMode(PChar, false);
			Locations[FindLocation("Cuba_shore_03")].reload.l1.disable = true;
			Locations[FindLocation("Cuba_shore_03")].reload.l2.disable = true;
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Cuba_shore_03", "reload", "reload2_back");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "reload", "reload2_back");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reload2_back");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reload2_back");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reload2_back");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "reload", "reload2_back");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);

			LAi_SetActorType(characterFromID("Enrique Padilla"));
			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 10.0, 1.0);
			SetCurrentTime(20, 0);
		break;

		case "LaCroix_jail":
			if(GetCurrentFlag() != FRANCE)
			{
				sld = CharacterFromID("Bart Renault");
				DeleteAttribute(sld, "questchar");
				sld.nation = GetCurrentFlag();	// Bart is supposed to be the same nation as you
				sld.nation.name = sld.nation;	// Necessary for "GetMyAddressForm" to work properly
				SetRandomNameToCharacter(sld);	// Rename him to match his nationality
			}

			pchar.vcskip = true; // PB: Avoid unwanted characters in jail
			DoQuestReloadToLocation("Havana_prison", "goto", "goto9","LaCroix_jail2");
			Locations[FindLocation("Cuba_shore_03")].reload.l1.disable = false;
			Locations[FindLocation("Cuba_shore_03")].reload.l2.disable = false;
			LAi_SetPlayerType(pchar);
			WaitDate("", 0,0,3,0,0);
			LAi_SetCurHPMax(pchar);
		break;

		case "LaCroix_jail2":
			ChangeCharacterAddress(characterFromID("Enrique Padilla"), "None", "");
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
            ChangeCharacterAddressGroup(CharacterFromID("Bart Renault"), "Havana_prison", "goto", "goto23");
			LAi_SetActorType(characterFromID("Bart Renault"));
			Characters[GetCharacterIndex("Bart Renault")].dialog.currentnode = "begin_3";
			LAi_ActorDialog(characterFromID("Bart Renault"), pchar, "", 2.0, 1.0);
			DeleteAttribute(&PChar,"vcskip"); // NK 04-06
		break;

		case "Breakout":
			PlayStereoSound("AMBIENT\JAIL\door_002.wav");
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			locCameraFollow();
			ChangeCharacterAddressGroup(pchar, "Havana_prison", "reload", "reload12");
			pchar.quest.main_line = "escape_from_havana_prison";
			ChangeCharacterAddress(characterFromID("Bart Renault"), "Havana_prison", "goto23");
			LAi_group_MoveCharacter(characterFromID("Bart Renault"), LAI_GROUP_PLAYER);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "kill_all_soldiers_in_prison_complete");
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_prison")], false);
			LAi_SetFightMode(PChar, true);
		break;

		case "kill_all_soldiers_in_prison_complete":
			LAi_SetFightMode(PChar, false);
			LAi_SetActorType(characterFromID("Bart Renault"));
			Characters[GetCharacterIndex("Bart Renault")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Bart Renault"), pchar, "", 2.0, 1.0);
		break;

		// PB -->
		case "bartinjail":
			ChangeCharacterAddress(characterFromID("Bart Renault"), "Havana_prison", "goto9");
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, characterFromID("Bart Renault"));
			postevent("resetpchar_event", 1000);
		break;
		// PB <--

		case "crewsavesme":
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean1"), "Havana_prison", "reload", "reload1");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean1"));
			LAi_SetImmortal(characterFromID("Crewmember_Jean1"), true);
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean2"), "Havana_prison", "reload", "reload1");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean2"));
			LAi_SetImmortal(characterFromID("Crewmember_Jean2"), true);
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean3"), "Havana_prison", "reload", "reload1");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean3"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto21");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.dialog.filename = "soldier_dialog.c";
			sld.dialog.currentnode = "First time";
	        LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto20");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.dialog.filename = "soldier_dialog.c";
			sld.dialog.currentnode = "First time";
            LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Havana"), "Havana_prison", "reload", "reload1");
			LAi_SetActorType(characterFromID("Crewmember_Havana"));
			LAi_SetImmortal(characterFromID("Crewmember_Havana"), true);
			LAi_ActorRunToLocator(characterFromID("Crewmember_Havana"), "goto", "goto23", "crewsavesme2",10);
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			pchar.quest.crewsavesme3.win_condition.l1 = "NPC_Death";
			pchar.quest.crewsavesme3.win_condition.l1.character = "Prison_Guard_Spa1";
			pchar.quest.crewsavesme3.win_condition.l2 = "NPC_Death";
			pchar.quest.crewsavesme3.win_condition.l2.character = "Prison_Guard_Spa2";
			pchar.quest.crewsavesme3.win_condition.l3 = "NPC_Death";
			pchar.quest.crewsavesme3.win_condition.l3.character = "Bart Renault";
			pchar.quest.crewsavesme3.win_condition = "crewsavesme3";
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_prison")], false);
		break;

		case "crewsavesme2":
			Characters[GetCharacterIndex("Crewmember_Havana")].dialog.CurrentNode = "saved_you";
			LAi_SetActorType(characterFromID("Crewmember_Havana"));
			LAi_ActorDialog(characterFromID("Crewmember_Havana"), pchar, "", 10.0, 1.0);
		break;

		case "crewsavesme3":
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		break;

		case "freeme":
			PlayStereoSound("AMBIENT\JAIL\door_002.wav");
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			locCameraFollow();
			ChangeCharacterAddressGroup(pchar, "Havana_prison", "reload", "reload12");
			SetCurrentTime(23, 0);
			LAi_SetImmortal(characterFromID("Bart Renault"), false);
			LAi_SetWarriorType(characterFromID("Bart Renault"));
			LAi_group_MoveCharacter(characterFromID("Bart Renault"), "QUEST_ENEMIES");
			LAi_group_SetRelation("QUEST_ENEMIES", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("QUEST_ENEMIES", LAI_GROUP_PLAYER, true);
			LAi_SetFightMode(PChar, true);
			pchar.quest.spanishattack.win_condition.l1 = "location";
			pchar.quest.spanishattack.win_condition.l1 = "location";
			pchar.quest.spanishattack.win_condition.l1.location = "Havana_Town_05";
			pchar.quest.spanishattack.win_condition = "spanishattack";
		break;

		case "spanishattack":
			Locations[FindLocation("Havana_Town_05")].reload.l3.disable = true;
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean1"), "Havana_Town_05", "goto", "goto_43");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean1"));
			LAi_SetImmortal(characterFromID("Crewmember_Jean1"), true);
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean2"), "Havana_Town_05", "goto", "goto_25");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean2"));
			LAi_SetImmortal(characterFromID("Crewmember_Jean2"), true);
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean3"), "Havana_Town_05", "goto", "soldier03");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean3"));
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Havana"), "Havana_Town_05", "goto", "soldier04");
			LAi_SetOfficerType(characterFromID("Crewmember_Havana"));
			LAi_SetImmortal(characterFromID("Crewmember_Havana"), true);
			ChangeCharacterAddressGroup(CharacterFromID("SpainCommander"), "Havana_Town_05", "goto", "cityzen07");
			Characters[GetCharacterIndex("SpainCommander")].dialog.CurrentNode = "brokenout";
			LAi_SetActorType(characterFromID("SpainCommander"));
			LAi_ActorDialog(characterFromID("SpainCommander"), pchar, "", 10.0, 1.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto_7");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.dialog.filename = "soldier_dialog.c";
			sld.dialog.currentnode = "First time";
	        LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto_10");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.dialog.filename = "soldier_dialog.c";
			sld.dialog.currentnode = "First time";
	        LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto_31");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.dialog.filename = "soldier_dialog.c";
			sld.dialog.currentnode = "First time";
	        LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto_29");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.dialog.filename = "soldier_dialog.c";
			sld.dialog.currentnode = "First time";
            LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
		break;

		case "spanishattack2":
			LAi_ActorAttack(CharacterFromID("SpainCommander"), Pchar, "");
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "tochurch");
		break;

		case "tochurch":
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			//Locations[FindLocation("Havana_town_02")].reload.l4.disable = false;
			Characters[GetCharacterIndex("Crewmember_Havana")].dialog.CurrentNode = "nowwhat";
			LAi_SetActorType(characterFromID("Crewmember_Havana"));
			LAi_ActorDialog(characterFromID("Crewmember_Havana"), pchar, "", 2.0, 1.0);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, false);
			pchar.quest.church.win_condition.l1 = "location";
			pchar.quest.church.win_condition.l1 = "location";
			pchar.quest.church.win_condition.l1.location = "Havana_church";
			pchar.quest.church.win_condition = "church";

			Pchar.quest.lecroix_remove_spaincommander.win_condition.l1 = "ExitFromLocation";
			PChar.quest.lecroix_remove_spaincommander.win_condition.l1.location = PChar.location;
			Pchar.quest.lecroix_remove_spaincommander.win_condition = "lecroix_remove_spaincommander";
		break;

		case "lecroix_remove_spaincommander":
			ChangeCharacterAddress(characterFromID("SpainCommander"), "None", "");
		break;

		case "church":
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean1"), "Havana_Church", "reload", "reload1");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean1"));
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean2"), "Havana_Church", "reload", "reload1");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean2"));
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean3"), "Havana_Church", "reload", "reload1");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean3"));
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Havana"), "Havana_Church", "reload", "reload1");
			LAi_SetOfficerType(characterFromID("Crewmember_Havana"));
			ChangeCharacterAddressGroup(CharacterFromID("PadreGerardo"), "Havana_church", "goto", "goto11");
			Characters[GetCharacterIndex("PadreGerardo")].dialog.CurrentNode = "whatthe";
			LAi_SetActorType(characterFromID("PadreGerardo"));
			LAi_ActorDialog(characterFromID("PadreGerardo"), pchar, "", 10.0, 1.0);
		break;

		case "gettingrobes":
			LAi_ActorRunToLocator(characterFromID("PadreGerardo"), "reload", "reload3", "gettingrobes3",10);
		break;

		case "gettingrobes3":
			ChangeCharacterAddressGroup(CharacterFromID("PadreGerardo"), "Havana_church", "reload", "reload3");
			Characters[GetCharacterIndex("PadreGerardo")].dialog.CurrentNode = "plan1";
			LAi_SetActorType(characterFromID("PadreGerardo"));
			LAi_ActorDialog(characterFromID("PadreGerardo"), pchar, "", 10.0, 1.0);
			GiveModel2Player("Priest", true);
			LAi_SetPlayerType(pchar);
            SetModelfromArray(characterFromID("Crewmember_Havana"), GetModelIndex("Priest"));
            SetModelfromArray(characterFromID("Crewmember_Jean3"), GetModelIndex("Priest"));
            SetModelfromArray(characterFromID("Crewmember_Jean2"), GetModelIndex("Priest"));
			SetModelfromArray(characterFromID("Crewmember_Jean1"), GetModelIndex("Priest"));
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		break;

		case "padreofficer":
			AddPassenger(Pchar, characterFromID("PadreGerardo"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("PadreGerardo"));
			LAi_SetOfficerType(characterFromID("PadreGerardo"));
			Characters[GetCharacterIndex("PadreGerardo")].dialog.Filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("PadreGerardo")].dialog.CurrentNode = "hired";
			Locations[FindLocation("Cuba_port")].vcskip = true;
			setCharacterShipLocation(characterFromID("Enrique Padilla"), "Cuba_port");
			pchar.quest.disguises.win_condition.l1 = "location";
			pchar.quest.disguises.win_condition.l1 = "location";
			pchar.quest.disguises.win_condition.l1.location = "Cuba_port";
			pchar.quest.disguises.win_condition = "disguises";
		break;

		case "disguises":
			ChangeCharacterAddressGroup(characterfromID("Shipguard1"), "Cuba_port", "goto", "goto_44");
			ChangeCharacterAddressGroup(characterfromID("Shipguard2"), "Cuba_port", "officers", "Sea_1_3");
			pchar.quest.In_you_go.win_condition.l1 = "locator";
			pchar.quest.In_you_go.win_condition.l1.location = "Cuba_port";
			pchar.quest.In_you_go.win_condition.l1.locator_group = "goto";
			pchar.quest.In_you_go.win_condition.l1.locator = "goto_60";
			pchar.quest.In_you_go.win_condition = "In_you_go";
		break;

		case "In_you_go":
			Characters[GetCharacterIndex("Shipguard1")].dialog.CurrentNode = "nightpadre";
			LAi_SetActorType(characterFromID("Shipguard1"));
			LAi_ActorDialog(characterFromID("Shipguard1"), pchar, "", 10.0, 1.0);
		break;

		case "believedus":
			DisableFastTravel(false);
			PChar.quest.disable_rebirth = false;
			HoistFlag(SPAIN);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 500);
				AddPartyExpChar(pchar, "Sneak", 500);
			}
			else {AddPartyExp(pchar, 2000);}

			if (GetRMRelation(PChar, SPAIN) > REL_WAR) SetRMRelation(PChar, SPAIN, REL_WAR);

			LAi_SetPlayerType(pchar);
			GiveModel2Player(pchar.originalmodel, true);
            		SetModelfromArray(characterFromID("Crewmember_Havana"), GetModelIndex("Sailor4"));
            		SetModelfromArray(characterFromID("Crewmember_Jean3"), GetModelIndex("Sailor6"));
            		SetModelfromArray(characterFromID("Crewmember_Jean2"), GetModelIndex("Sailor3"));
			SetModelfromArray(characterFromID("Crewmember_Jean1"), GetModelIndex("Sailor5"));
			Locations[FindLocation("Havana_town_05")].reload.l3.disable = false;
			if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS)
			{
				GiveShip2Character(PChar,"FastMerchantman2","Miguel de Cervantes",-1,SPAIN,true,true);
				AddQuestRecord("Beginning_Rogue", 11);
			}
			else
			{
				GiveShip2Character(PChar,"PO_Fleut50","Miguel de Cervantes",-1,SPAIN,true,true);
				AddQuestRecord("Beginning_Rogue", 5);
			}
			CloseQuestHeader("Beginning_Rogue");
			PlaceFleetNearShore("Cuba_port");

			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_3", false);
			QuestToSeaLogin_Launch();
			DeleteAttribute(&Locations[FindLocation("Cuba_port")],"vcskip");
			SetCharacterShipLocation(CharacterFromID("Enrique Padilla"), "None");
		break;

		case "seeyou":
			Preprocessor_AddQuestData("money", GetAttribute(CharacterFromID("Bart Renault"), "quest.money"));
			AddQuestRecord("Beginning_Rogue", 2);
			Preprocessor_Remove("money");
			if (pchar.quest.main_line == "escape_from_havana_prison")
			{
				LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
				//ChangeCharacterAddress(characterFromID("Havana prison commendant"), "none", "none");
			}
			pchar.quest.crewfoundyou.win_condition.l1 = "location";
			pchar.quest.crewfoundyou.win_condition.l1 = "location";
			pchar.quest.crewfoundyou.win_condition.l1.location = "Havana_Outskirts";
			pchar.quest.crewfoundyou.win_condition = "crewfoundyou";
		break;

		case "crewfoundyou":
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
           	ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Havana"), "Havana_Outskirts", "goto", "goto3");
			Characters[GetCharacterIndex("Crewmember_Havana")].dialog.CurrentNode = "hello_captain";
			LAi_SetActorType(characterFromID("Crewmember_Havana"));
			LAi_ActorDialog(characterFromID("Crewmember_Havana"), pchar, "", 10.0, 1.0);
		break;

		case "tosmuggler":
			LAi_ActorFollowEverywhere(characterFromID("Crewmember_Havana"), "", 200.0);
			setCharacterShipLocation(characterFromID("Smuggler"), "Cuba_shore_01");
			pchar.quest.crewtalk2.win_condition.l1 = "location";
			pchar.quest.crewtalk2.win_condition.l1 = "location";
			pchar.quest.crewtalk2.win_condition.l1.location = "Cuba_shore_01";
			pchar.quest.crewtalk2.win_condition = "commandeership";
			AddQuestRecord("Beginning_Rogue", 3);
		break;

		case "commandeership":
			Characters[GetCharacterIndex("Crewmember_Havana")].dialog.CurrentNode = "boarding";
			LAi_SetActorType(characterFromID("Crewmember_Havana"));
			LAi_ActorDialog(characterFromID("Crewmember_Havana"), pchar, "", 10.0, 1.0);
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean1"), "Cuba_Shore_01", "goto", "goto33");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean1"));
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean2"), "Cuba_Shore_01", "goto", "goto34");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean2"));
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean3"), "Cuba_Shore_01", "goto", "goto35");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean3"));
		break;

		case "waituntilnight":
			SetCurrentTime(24, 0);
			LAi_Fade("nightfall", "");
		break;

		case "nightfall":
			Characters[GetCharacterIndex("Crewmember_Havana")].dialog.currentnode = "night";
           	LAi_SetActorType(characterFromID("Crewmember_Havana"));
			LAi_ActorDialog(characterFromID("Crewmember_Havana"), pchar, "", 2.0, 1.0);
		break;

		case "attaque":
			DoQuestReloadToLocation("smuggler_ship", "goto", "goto1", "attaque1.5");
		break;

		case  "attaque1.5":
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean1"), "smuggler_ship", "rld", "loc2");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean1"));
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean2"), "smuggler_ship", "rld", "loc3");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean2"));
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean3"), "smuggler_ship", "goto", "goto2");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean3"));
            ChangeCharacterAddressGroup(CharacterFromID("Watch"), "smuggler_ship", "rld", "startloc");
			LAi_SetActorType(characterFromID("Watch"));
			Characters[GetCharacterIndex("Watch")].dialog.currentnode = "seeyou";
			LAi_ActorDialog(characterFromID("Watch"), pchar, "", 1.0, 1.0);
		break;

		case "attaque2":
			LAi_group_MoveCharacter(characterFromID("Watch"), "ENG_SMUGGLER");
			LAi_group_SetRelation("ENG_SMUGGLER", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("ENG_SMUGGLER", LAI_GROUP_PLAYER, true);
			pchar.quest.nextstep.win_condition.l1 = "NPC_Death";
			pchar.quest.nextstep.win_condition.l1.character = "Watch";
			pchar.quest.nextstep.win_condition = "nextstep";
		break;

		case "nextstep":
			Locations[FindLocation("smuggler_ship")].reload.l2.disable = false;
			pchar.quest.nextstep2.win_condition.l1 = "location";
			pchar.quest.nextstep2.win_condition.l1 = "location";
			pchar.quest.nextstep2.win_condition.l1.location = "Smuggler_Quarter";
			pchar.quest.nextstep2.win_condition = "nextstep2";
		break;

		case "nextstep2":
			Locations[FindLocation("Smuggler_Quarter")].vcskip = true;
			Locations[FindLocation("Smuggler_Quarter")].reload.l1.disable = true;
			Locations[FindLocation("Smuggler_Quarter")].reload.l2.disable = true;
			ChangeCharacterAddress(characterFromID("Smuggler1"), "Smuggler_Quarter", "goto1");
			ChangeCharacterAddress(characterFromID("Smuggler2"), "Smuggler_Quarter", "goto2");
			ChangeCharacterAddress(characterFromID("Smuggler3"), "Smuggler_Quarter", "goto6");
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Jean1"), "Smuggler_Quarter", "reload", "reload1");
			LAi_SetOfficerType(characterFromID("Crewmember_Jean1"));
			LAi_group_SetRelation("ENG_SMUGGLER", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("ENG_SMUGGLER", LAI_GROUP_PLAYER, true);
			pchar.quest.nextstep4.win_condition.l1 = "NPC_Death";
			pchar.quest.nextstep4.win_condition.l1.character = "Smuggler1";
			pchar.quest.nextstep4.win_condition.l2 = "NPC_Death";
			pchar.quest.nextstep4.win_condition.l2.character = "Smuggler2";
			pchar.quest.nextstep4.win_condition.l3 = "NPC_Death";
			pchar.quest.nextstep4.win_condition.l3.character = "Smuggler3";
			pchar.quest.nextstep4.win_condition = "nextstep4";
		break;

		case "nextstep4":
			Locations[FindLocation("Smuggler_Quarter")].reload.l2.disable = false;
			pchar.quest.nextstep5.win_condition.l1 = "location";
			pchar.quest.nextstep5.win_condition.l1 = "location";
			pchar.quest.nextstep5.win_condition.l1.location = "Smuggler_Cabin";
			pchar.quest.nextstep5.win_condition = "nextstep5";
		break;

		case "nextstep5":
			ChangeCharacterAddress(characterFromID("Crewmember_Jean1"), "None", "");
			ChangeCharacterAddress(characterFromID("Crewmember_Jean2"), "None", "");
			ChangeCharacterAddress(characterFromID("Crewmember_Jean3"), "None", "");
			Locations[FindLocation("Smuggler_Cabin")].reload.l1.disable = true;
            ChangeCharacterAddressGroup(CharacterFromID("Smuggler"), "Smuggler_Cabin", "sit", "sit0");
			LAi_SetActorType(characterFromID("Smuggler"));
			LAi_ActorSetSitMode(characterFromID("Smuggler"));
			Characters[GetCharacterIndex("Smuggler")].dialog.currentnode = "seeyou";
			LAi_ActorDialog(characterFromID("Smuggler"), pchar, "", 10.0, 1.0);
		break;

		case "killyou":
			ChangeCharacterAddressGroup(CharacterFromID("Smuggler"), "Smuggler_Cabin", "rld", "startloc");
			LAi_SetWarriorType(characterFromID("Smuggler"));
			LAi_group_MoveCharacter(characterFromID("Smuggler"), "ENG_SMUGGLER");
			LAi_group_SetRelation("ENG_SMUGGLER", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("ENG_SMUGGLER", LAI_GROUP_PLAYER, true);
			LAi_SetFightMode(PChar, true);
			pchar.quest.captured_smuggler_ship.win_condition.l1 = "NPC_Death";
			pchar.quest.captured_smuggler_ship.win_condition.l1.character = "Smuggler";
			pchar.quest.captured_smuggler_ship.win_condition = "captured_smuggler_ship";
		break;

		case "captured_smuggler_ship":
			LAi_group_SetRelation("ENG_SMUGGLER", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
           	ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Havana"), "Smuggler_Cabin", "reload", "reload1");
			Characters[GetCharacterIndex("Crewmember_Havana")].dialog.CurrentNode = "ship_is_ours";
			LAi_SetActorType(characterFromID("Crewmember_Havana"));
			LAi_ActorDialog(characterFromID("Crewmember_Havana"), pchar, "", 2.0, 2.0);
		break;

		case "captured_smuggler_ship2":
			DisableFastTravel(false);
			PChar.quest.disable_rebirth = false;
			AddQuestRecord("Beginning_Rogue", 4);
			CloseQuestHeader("Beginning_Rogue");
			Locations[FindLocation("smuggler_ship")].reload.l1.disable = false;
			GiveShip2Character(pchar,"LuggerVML","Sea Horse",-1,ENGLAND,true,true);
			PlaceFleetNearShore("Cuba_Shore_01");
			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_2", false);
			QuestToSeaLogin_Launch();
		break;

		case "no_duel":
			CloseQuestHeader("Tutorial_AppearedOnIsland");
			DeleteQuestHeader("Tutorial_AppearedOnIsland");

			SetQuestHeader("Beginning_Rogue");
			if (CharPlayerType == PLAYER_TYPE_ROGUE)
			{
				if (PChar.sex == "woman") AddQuestRecord("Beginning_Rogue", 8);
				else AddQuestRecord("Beginning_Rogue", 7);
			}
			else AddQuestRecord("Beginning_Rogue", 10);
			CloseQuestHeader("Beginning_Rogue");
			DeleteAttribute(&PChar,"vcskip");

			if(CheckCharacterItem(PChar, "Spyglass1") == 0)			GiveItem2Character(PChar, "Spyglass1");
			if(CheckCharacterItem(PChar, "medical1") == 0)			TakeNItems(PChar, "medical1", 2); // PB
			if(CheckCharacterItem(PChar, PChar.start_weapon.blade) == 0)	GiveItem2Character(PChar, PChar.start_weapon.blade);
			if(CheckCharacterItem(PChar, PChar.start_weapon.gun) == 0)	GiveItem2Character(PChar, PChar.start_weapon.gun);
			DeleteAttribute(PChar, "start_weapon");

			EquiPCharacterbyItem(PChar, FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE));
			EquiPCharacterbyItem(PChar, FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE));
			EquiPCharacterbyItem(PChar, FindCharacterItemByGroup(&PChar, SPYGLASS_ITEM_TYPE));

			//JRH ammo mod --->
			if (ENABLE_AMMOMOD) {	// LDH change
				if(CheckCharacterItem(PChar, "gunpowder") > 0)		TakeNItems(PChar, "gunpowder", -12);
				if(CheckCharacterItem(PChar, "gunpowder") == 0)		TakeNItems(PChar, "gunpowder", 6);
				if(CheckCharacterItem(PChar, "pistolbullets") > 0)	TakeNItems(PChar, "pistolbullets", -12);
				if(CheckCharacterItem(PChar, "pistolbullets") == 0)	TakeNItems(PChar, "pistolbullets", 6);
			}
			//JRH ammo mod <---

			SetCharacterGoods(PChar, CharGood1, 0); // dumps your cargo // KK
			SetCharacterGoods(PChar, CharGood2, 0);
			i = getRandomContrabandGood(GetIslandByID("Cuba"));
			if (i > 0) AddCharacterGoods(PChar, i, (2.0+rand(2))/10.0 * GetCharacterFreeSpace(PChar, i));
			SafePortLeave(SPAIN, false);

			//PW clear boat reloads ----->
			string ship_deck = GetCharacterShipQDeck(PChar);
			Locations[FindLocation(ship_deck)].reload.l4.disable = 0;
			Locations[FindLocation(ship_deck)].reload.l5.disable = 0;
			//PW clear boat reloads <-----
			//GR Clear cabin reload and remove tutorial officer ---->
			Locations[FindLocation("Tutorial_Deck")].reload.l1.disable = 0;
			ChangeCharacterAddressGroup(CharacterFromID("Malcolm Hatcher"), "none", "", "");
			//GR Clear cabin reload and remove tutorial officer <----

			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_7", false);
			QuestToSeaLogin_Launch();
		break;
		
///////////////////////////////////////////////////////////////
///// A FAMILY' STORY
///////////////////////////////////////////////////////////////

		case "madero_start":
			SetEnterLocationQuest("Eleuthera_townhall", "madero_start_check", 0);
		break;

		case "madero_start_check":
			if(makeint(PChar.rank) >= 10)
			{
				PlaceCharacter(characterFromID("Alonso Madero"), "goto");
				LAi_SetActorType(characterFromID("Alonso Madero"));
				Characters[GetCharacterIndex("Alonso Madero")].dialog.currentnode = "begin_1";
				LAi_ActorDialog(characterFromID("Alonso Madero"), pchar, "", 2.0, 1.0);	
			}
		break;

		case "recusar_oferta":
			DeleteEnterLocationQuest("Eleuthera_townhall", "madero_start_check");
			LAi_SetActorType(characterFromID("Alonso Madero"));
			LAi_ActorRunToLocation(characterFromID("Alonso Madero"), "reload", "reload1", "none", "", "", "", 0.0);	
			break;

		case "aceitar_oferta":
			DeleteEnterLocationQuest("Eleuthera_townhall", "madero_start_check");		
			ChangeCharacterAddressGroup(CharacterFromID("Elvira Suarez"), "Suarez_House", "goto", "goto8");
			LAi_SetActorType(characterFromID("Alonso Madero"));
			LAi_ActorRunToLocation(characterFromID("Alonso Madero"), "reload", "reload1", "none", "", "", "", 0.0);
			Characters[GetCharacterIndex("Elvira Suarez")].dialog.currentnode = "begin_1";			
			SetQuestHeader("Family_Story");
			AddQuestRecord("Family_Story", 1);			
			break;

		case "recusar_oferta_2":		
			AddQuestRecord("Family_Story", 2);
			CloseQuestHeader("Family_Story");
			break;

		case "aceitar_oferta_2":
			PChar.quest.kidnapping = "abel_barco";
			AddQuestRecord("Family_Story", 3);			
			break;			

		case "encontrar_abel":
			Locations[FindLocation("Tortuga_port")].reload.l11.disable = 1;		
			AddQuestRecord("Family_Story", 4);		
			PChar.quest.kidnapping.over = "yes";		

			PChar.quest.ver_abel.win_condition.l1 = "Timer";			
			PChar.quest.ver_abel.win_condition.l1 = "Timer";
			PChar.quest.ver_abel.win_condition.l1.date.day = GetAddingDataDay(0,0,1);
			PChar.quest.ver_abel.win_condition.l1.date.month = GetAddingDataMonth(0,0,1);
			PChar.quest.ver_abel.win_condition.l1.date.year = GetAddingDataYear(0,0,1);
			PChar.quest.ver_abel.win_condition = "encontrar_abel_2";
			break;
			
		case "encontrar_abel_2":
			AddQuestRecord("Family_Story", 5);		
			ChangeCharacterAddressGroup(CharacterFromID("Abel Barco"), "Santiago_town_exit2", "goto", "citizen03");
			Characters[GetCharacterIndex("Abel Barco")].dialog.currentnode = "begin_1";	
			break;

		case "combater_abel":
			LAi_SetImmortal(characterFromID("Abel Barco"), true);		
			LAi_SetActorType(characterFromID("Abel Barco"));
			LAi_ActorAttack(CharacterFromID("Abel Barco"), Pchar, "");
		
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "locator8");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PIRATES_ABEL");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "locator8");
			GiveItem2Character(sld,"blade2");
			EquipCharacterByItem(sld,"blade2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PIRATES_ABEL");

			LAi_group_FightGroups("PIRATES_ABEL", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("PIRATES_ABEL", "desistir_abel");
			break;

		case "desistir_abel":
			LAi_SetActorType(characterFromID("Abel Barco"));
			Characters[GetCharacterIndex("Abel Barco")].dialog.currentnode = "begin_5";
			LAi_ActorDialog(characterFromID("Abel Barco"), pchar, "", 2.0, 1.0);
			break;

		case "ir_tortuga":
			Locations[FindLocation("Tortuga_port")].models.day.locators = "Tortuga_lBOP_day";
			Locations[FindLocation("Tortuga_port")].models.night.locators = "Tortuga_lBOP_night";
			Locations[FindLocation("Tortuga_port")].locators_radius.goto.goto40 = 2.0;			
			ChangeCharacterAddressGroup(CharacterFromID("kidnapper_1"), "Tortuga_port", "reload", "brothel");	
			ChangeCharacterAddressGroup(CharacterFromID("kidnapper_2"), "Tortuga_port", "goto", "goto34");
			Characters[GetCharacterIndex("kidnapper_1")].dialog.currentnode = "begin_1";
			Characters[GetCharacterIndex("kidnapper_2")].dialog.currentnode = "begin_1";			
			AddQuestRecord("Family_Story", 6);	
			LAi_SetActorType(characterFromID("Abel Barco"));
			LAi_ActorRunToLocation(characterFromID("Abel Barco"), "reload", "reload2", "none", "", "", "", 4.0);
			break;	
			
		case "ir_janela":
			Characters[GetCharacterIndex("kidnapper_1")].dialog.currentnode = "First time";
			Characters[GetCharacterIndex("kidnapper_2")].dialog.currentnode = "First time";		
			AddQuestRecord("Family_Story", 7);

			pchar.quest.ate_janela.win_condition.l1 = "locator";			
			pchar.quest.ate_janela.win_condition.l1 = "locator";
			pchar.quest.ate_janela.win_condition.l1.location = "Tortuga_port";
			pchar.quest.ate_janela.win_condition.l1.locator_group = "goto";
			pchar.quest.ate_janela.win_condition.l1.locator = "goto40";
			pchar.quest.ate_janela.win_condition = "ir_suarez_quarto";
            break;

		case "ir_suarez_quarto":	
            DoQuestReloadToLocation("Tortuga_Pirate_House", "goto", "goto1" ,"falar_suarez");
            break;

		case "falar_suarez":
			ChangeCharacterAddressGroup(characterFromID("Fernando Suarez"), "Tortuga_Pirate_House", "reload", "reload1");
			Characters[GetCharacterIndex("Fernando Suarez")].dialog.currentnode = "begin_1";			
			LAi_SetActorType(characterFromID("Fernando Suarez"));
			LAi_ActorDialog(characterFromID("Fernando Suarez"), pchar, "", 5.0, 1.0);
            break;

		case "ir_santiago":
			HoistFlag(PIRATE);			
	        LAi_SetOfficerType(characterFromID("Fernando Suarez"));
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Fernando Suarez"));
			GiveItem2Character(CharacterFromId("Fernando Suarez"), "blade44");
			EquipCharacterByItem(CharacterFromId("Fernando Suarez"), "blade44");
			GiveItem2Character(CharacterFromId("Fernando Suarez"), "pistol1");
			EquipCharacterByItem(CharacterFromId("Fernando Suarez"), "pistol1");
			
			ChangeCharacterAddressGroup(CharacterFromID("kidnapper_1"), "none", "", "");	
			ChangeCharacterAddressGroup(CharacterFromID("kidnapper_2"), "none", "", "");	
			ChangeCharacterAddressGroup(CharacterFromID("kidnapper_3"), "none", "", "");
			
			QuestToSeaLogin_PrepareLoc("Hispaniola", "reload", "reload_7", true);
			QuestToSeaLogin_Launch();
			AddQuestRecord("Family_Story", 8);
			
			Pchar.quest.ate_santiago.win_condition.l1 = "location";
			Pchar.quest.ate_santiago.win_condition.l1 = "location";
			Pchar.quest.ate_santiago.win_condition.l1.location = "Santiago_port";
			PChar.quest.ate_santiago.win_condition = "explicar_suarez";
            break;

		case "explicar_suarez":
			Locations[FindLocation("Santiago_town_01")].models.always.add9 = "globe";	//JRH: showing the way to the cartographer
			Locations[FindLocation("Tortuga_port")].models.day.locators = "Tortuga_l_day";
			Locations[FindLocation("Tortuga_port")].models.night.locators = "Tortuga_l_night";		
            Locations[FindLocation("Santiago_Tavern")].vcskip = true;		
			Characters[GetCharacterIndex("Fernando Suarez")].dialog.currentnode = "begin_5";		
			LAi_SetActorType(characterFromID("Fernando Suarez"));
			LAi_ActorDialog(characterFromID("Fernando Suarez"), pchar, "", 5.0, 1.0);
            break;
			
		case "ir_taberna":
			RemovePassenger(pchar, characterFromID("Fernando Suarez"));
			RemoveCharacterCompanion(pchar, characterFromID("Fernando Suarez"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Fernando Suarez"));
            DoQuestReloadToLocation("Santiago_Tavern", "sit", "sit6" ,"ir_taberna2");
            break;					
			
		case "ir_taberna2":
			Locations[FindLocation("Santiago_town_01")].models.always.add9 = "globe";	//JRH: showing the way to the cartographer
			ChangeCharacterAddressGroup(characterFromID("Fernando Suarez"), "Santiago_Tavern", "sit", "sit7");
			LAi_SetActorType(characterFromID("Fernando Suarez"));
			LAi_SetSitType(characterFromID("Fernando Suarez"));			
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			Characters[GetCharacterIndex("Fernando Suarez")].dialog.currentnode = "begin_8";		
			LAi_ActorWaitDialog(CharacterFromID("Fernando Suarez"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Fernando Suarez"),"", 10.0, 10.0);
            break;
			
		case "meet_chaparro":
			Locations[FindLocation("Santiago_town_01")].models.always.add9 = "globe";	//JRH: showing the way to the cartographer
			DeleteAttribute(&Locations[FindLocation("Santiago_Tavern")],"vcskip");		
		    LAi_SetPlayerType(pchar);
			ChangeCharacterAddressGroup(CharacterFromID("Arnaldo Chaparro"), "Cartographer_House", "sit", "sit1");					
            DoQuestReloadToLocation("Santiago_Tavern", "goto", "goto6" ,"meet_chaparro2");		
            break;				

		case "meet_chaparro2":	
			ChangeCharacterAddressGroup(characterFromID("Fernando Suarez"), "Santiago_Tavern", "goto", "goto2");
	        LAi_SetOfficerType(characterFromID("Fernando Suarez"));
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Fernando Suarez"));			
			Characters[GetCharacterIndex("Arnaldo Chaparro")].dialog.currentnode = "begin_1";				
			AddQuestRecord("Family_Story", 9);				
            break;
			
		case "ir_ile_vache":
			Characters[GetCharacterIndex("Fernando Suarez")].dialog.currentnode = "begin_23";				
			LAi_SetActorType(characterFromID("Fernando Suarez"));
			LAi_ActorDialog(characterFromID("Fernando Suarez"), pchar, "", 5.0, 1.0);	
            break;					

		case "ir_ile_vache2":
			LAi_SetActorType(characterFromID("Fernando Suarez"));		
	        LAi_SetOfficerType(characterFromID("Fernando Suarez"));		
			AddQuestRecord("Family_Story", 10);

			Pchar.quest.ir_vache.win_condition.l1 = "location";			
			Pchar.quest.ir_vache.win_condition.l1 = "location";
			Pchar.quest.ir_vache.win_condition.l1.location = "Hispaniola_shore_04";
			PChar.quest.ir_vache.win_condition = "search_bart";			
            break;

		case "search_bart":
			Characters[GetCharacterIndex("Fernando Suarez")].dialog.currentnode = "begin_24";				
			LAi_SetActorType(characterFromID("Fernando Suarez"));
			LAi_ActorDialog(characterFromID("Fernando Suarez"), pchar, "", 5.0, 1.0);	
            break;

		case "search_bart2":
	        LAi_SetOfficerType(characterFromID("Fernando Suarez"));
			
			Pchar.quest.find_bart.win_condition.l1 = "location";			
			Pchar.quest.find_bart.win_condition.l1 = "location";
			Pchar.quest.find_bart.win_condition.l1.location = "Hispaniola_Grot";
			PChar.quest.find_bart.win_condition = "encontrar_corpo";				
            break;

		case "encontrar_corpo":
            LAi_SetStayType(characterFromID("Fernando Suarez"));		
			ChangeCharacterAddressGroup(characterFromID("Fernando Suarez"), "Hispaniola_Grot", "monsters", "monster2");
			sld = LAi_CreateFantomCharacter(false, 0, true, false, 0.25, "Skel3", "monsters", "monster4");
		    sld.name = "Bartolomeu";
			sld.lastname = "Portugues";			
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			sld = LAi_CreateFantomCharacter(false, 0, true, false, 0.25, "Skel1", "monsters", "monster3");
		    sld.name = "Guillaume";
			sld.lastname = "Auger";			
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);				
			Characters[GetCharacterIndex("Fernando Suarez")].dialog.currentnode = "begin_25";
            break;

		case "voltar_praia":
			RemovePassenger(pchar, characterFromID("Fernando Suarez"));
			RemoveCharacterCompanion(pchar, characterFromID("Fernando Suarez"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Fernando Suarez"));	
            DoQuestReloadToLocation("Hispaniola_shore_04", "goto", "citizen08" ,"embarquar");		
            break;

		case "embarquar":
			ChangeCharacterAddressGroup(characterFromID("Fernando Suarez"), "Hispaniola_shore_04", "goto", "locator12");			
			Characters[GetCharacterIndex("Fernando Suarez")].dialog.currentnode = "begin_27";				
			LAi_SetActorType(characterFromID("Fernando Suarez"));
			LAi_ActorDialog(characterFromID("Fernando Suarez"), pchar, "", 5.0, 1.0);	
            break;

		case "voltar_havana":
	        LAi_SetOfficerType(characterFromID("Fernando Suarez"));
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Fernando Suarez"));				
			Characters[GetCharacterIndex("Elvira Suarez")].dialog.currentnode = "begin_11";		
			AddQuestRecord("Family_Story", 11);
            break;

		case "adeus_fernando":		
			Characters[GetCharacterIndex("Fernando Suarez")].dialog.currentnode = "begin_28";				
			LAi_SetActorType(characterFromID("Fernando Suarez"));
			LAi_ActorDialog(characterFromID("Fernando Suarez"), pchar, "", 5.0, 1.0);	
            break;

		case "deixar_suarez":
			DisableFastTravel(true);
			DisableMenuLaunch(true);		
            LAi_SetCitizenType(characterFromID("Fernando Suarez"));		
			PlayStereoSound("INTERFACE\took_item.wav");
			GiveItem2Character(Pchar, "bladeBP");

			Pchar.quest.fight_acre.win_condition.l1 = "location";			
			Pchar.quest.fight_acre.win_condition.l1 = "location";
			Pchar.quest.fight_acre.win_condition.l1.location = "Havana_Town_02";
			PChar.quest.fight_acre.win_condition = "combat_acre";			
            break;

		case "combat_acre":
			ChangeCharacterAddressGroup(characterFromID("Robert Acre"), "Havana_Town_02", "goto", "goto16");
			
			LAi_SetActorType(characterFromID("Robert Acre"));
			LAi_NoRebirthEnable(characterFromID("Robert Acre"));
			LAi_ActorAttack(CharacterFromID("Robert Acre"), Pchar, "");

			pchar.quest.pirate_died.win_condition.l1 = "NPC_Death";
			pchar.quest.pirate_died.win_condition.l1.character = "Robert Acre";
			pchar.quest.pirate_died.win_condition = "final_estoria";
            break;

		case "final_estoria":
			DisableFastTravel(false);
			DisableMenuLaunch(false);		
			Locations[FindLocation("Tortuga_port")].reload.l11.disable = 0;		
			AddQuestRecord("Family_Story", 12);
			CloseQuestHeader("Family_Story");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }			
            break;
			
		case "deixar_suarezB":
			DisableFastTravel(true);
			DisableMenuLaunch(true);		
            LAi_SetCitizenType(characterFromID("Fernando Suarez"));		
			PlayStereoSound("INTERFACE\took_item.wav");
			GiveItem2Character(Pchar, "bladeBP");

			Pchar.quest.fight_acreB.win_condition.l1 = "location";			
			Pchar.quest.fight_acreB.win_condition.l1 = "location";
			Pchar.quest.fight_acreB.win_condition.l1.location = "Havana_Town_02";
			PChar.quest.fight_acreB.win_condition = "combat_acreB";			
            break;

		case "combat_acreB":
			ChangeCharacterAddressGroup(characterFromID("Robert Acre"), "Havana_Town_02", "goto", "goto16");
			
			LAi_SetActorType(characterFromID("Robert Acre"));
			LAi_NoRebirthEnable(characterFromID("Robert Acre"));
			LAi_ActorAttack(CharacterFromID("Robert Acre"), Pchar, "");

			pchar.quest.pirate_diedB.win_condition.l1 = "NPC_Death";
			pchar.quest.pirate_diedB.win_condition.l1.character = "Robert Acre";
			pchar.quest.pirate_diedB.win_condition = "Ir_Grenada";
            break;	
			
		case "Ir_Grenada":	
			DisableFastTravel(false);
			DisableMenuLaunch(false);		
			Locations[FindLocation("Tortuga_port")].reload.l11.disable = 0;
		    //-> open Grenada Shore
			Island_SetReloadEnableLocal("Conceicao", "reload_4", true);
			Islands[FindIsland("Conceicao")].reload.l5.goto_enable = true; // PB			
		    //<- open Grenada Shore
    		Locations[FindLocation("Bartolomeu_Mansion")].locators_radius.goto.citizen06 = 1.2;
    		Locations[FindLocation("Bartolomeu_Mansion")].locators_radius.goto.goto1 = 8.0;
			
			Pchar.quest.shore_patrol.win_condition.l1 = "location";			
			Pchar.quest.shore_patrol.win_condition.l1 = "location";
			pchar.quest.shore_patrol.win_condition.l1.location = "Conceicao_Shore_03";
			pchar.quest.shore_patrol.win_condition = "found_patrol";			
			
			AddQuestRecord("Family_Story", 13);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }			
            break;
			
		case "found_patrol":				
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Dead_Patrol";
			LAi_ActorSelfDialog(Pchar, "player_back");
            break;

		case "meet_french":
            LAi_group_SetRelation("NAPOLEONIC_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);		
			LAi_SetPlayerType(Pchar);
			
			Pchar.quest.meet_french_soldiers.win_condition.l1 = "location";			
			Pchar.quest.meet_french_soldiers.win_condition.l1 = "location";
			pchar.quest.meet_french_soldiers.win_condition.l1.location = "Bartolomeu_Mansion";
			pchar.quest.meet_french_soldiers.win_condition = "french_camp";			
            break;

		case "french_camp":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
	        if(makeint(environment.time)> 22.0 || makeint(environment.time)< 6.0 ){			
			Pchar.dialog.currentnode = "See_French_Camp";
	        }else{
			Pchar.dialog.currentnode = "See_French_Camp_Bis";				
			}	
			LAi_ActorSelfDialog(Pchar, "player_back");		
            break;
			
		case "voltar_mais_tarde":
			LAi_SetPlayerType(Pchar);		
            DoQuestReloadToLocation("Conceicao_Shore_03", "goto", "citizen01" ,"voltar_mais_tarde_bis");		
            break;
			
		case "voltar_mais_tarde_bis":
			AddQuestRecord("Family_Story", 14);		
			pchar.quest.explosao_canao.win_condition.l1 = "locator";
			pchar.quest.explosao_canao.win_condition.l1.location = "Bartolomeu_Mansion";
			pchar.quest.explosao_canao.win_condition.l1.locator_group = "goto";
			pchar.quest.explosao_canao.win_condition.l1.locator = "goto1";
			pchar.quest.explosao_canao.win_condition = "explosao";			
            break;			

		case "explosao":
			if(makeint(environment.time)< 22.0 && makeint(environment.time)> 6.0 ){
			CreateParticleSystemX("blast_inv", 1.337, 1, 18.652, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -3.337, 1, 18.652, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 5.337, 1, 18.652, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 1.337, 1, 22.652, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", 1.337, 1, 14.652, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_KillCharacter(Pchar);
            }else{
			pchar.quest.bart_chest.win_condition.l1 = "locator";
			pchar.quest.bart_chest.win_condition.l1.location = "Bartolomeu_Mansion";
			pchar.quest.bart_chest.win_condition.l1.locator_group = "goto";
			pchar.quest.bart_chest.win_condition.l1.locator = "citizen06";
			pchar.quest.bart_chest.win_condition = "dialogue_chest";					
			}			
            break;		

		case "find_chest":
			LAi_SetPlayerType(Pchar);		
			pchar.quest.bart_chest.win_condition.l1 = "locator";
			pchar.quest.bart_chest.win_condition.l1.location = "Bartolomeu_Mansion";
			pchar.quest.bart_chest.win_condition.l1.locator_group = "goto";
			pchar.quest.bart_chest.win_condition.l1.locator = "citizen06";
			pchar.quest.bart_chest.win_condition = "dialogue_chest";			
            break;

		case "dialogue_chest":
			Pchar.quest.explosao_canao.over = "yes";		
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Key_Chest";
			LAi_ActorSelfDialog(Pchar, "player_back");		
            break;

		case "search_rifle":
			PlayStereoSound("INTERFACE\took_item.wav");		
			LAi_SetPlayerType(Pchar);		
			pchar.quest.bart_chestB.win_condition.l1 = "locator";
			pchar.quest.bart_chestB.win_condition.l1.location = "Bartolomeu_Mansion";
			pchar.quest.bart_chestB.win_condition.l1.locator_group = "goto";
			pchar.quest.bart_chestB.win_condition.l1.locator = "citizen08";
			pchar.quest.bart_chestB.win_condition = "found_rifle";			
            break;

   		case "found_rifle":
			PlayStereoSound("INTERFACE\took_item.wav");
			GiveItem2Character(pchar, "LongRifle_BT");			
			AddQuestRecord("Family_Story", 15);

			Pchar.quest.french_patrol.win_condition.l1 = "location";			
			Pchar.quest.french_patrol.win_condition.l1 = "location";
			pchar.quest.french_patrol.win_condition.l1.location = "Conceicao_Shore_03";
			pchar.quest.french_patrol.win_condition = "french_patrol_beach";				
            break;

		case "french_patrol_beach":
		    DisableFastTravel(true);
			DisableMenuLaunch(true);
			locations[FindLocation("Conceicao_Shore_03")].reload.l3.disable = 1;
			locations[FindLocation("Conceicao_Shore_03")].reload.l2.disable = 1;
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m1, "goto", "citizen07");
			LAi_group_MoveCharacter(sld, "FRENCH_PATROL");
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m2, "goto", "citizen05");
			LAi_group_MoveCharacter(sld, "FRENCH_PATROL");
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m3, "goto", "citizen04");
			LAi_group_MoveCharacter(sld, "FRENCH_PATROL");
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m4, "goto", "citizen01");
			LAi_group_MoveCharacter(sld, "FRENCH_PATROL");
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			LAi_group_FightGroups("FRENCH_PATROL", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRENCH_PATROL", "Fight_Victorieuse");			
            break;		
			
		case "Fight_Victorieuse":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			locations[FindLocation("Conceicao_Shore_03")].reload.l3.disable = 0;
			locations[FindLocation("Conceicao_Shore_03")].reload.l2.disable = 0;
			
			Pchar.quest.combattre_victorieuse.win_condition.l1 = "location";		
			Pchar.quest.combattre_victorieuse.win_condition.l1 = "location";
			Pchar.quest.combattre_victorieuse.win_condition.l1.location = "Conceicao";
			PChar.quest.combattre_victorieuse.win_condition = "Fight_Victorieuse_Bis";
			break;

     	case "Fight_Victorieuse_Bis":
			HoistFlag(PERSONAL_NATION);		
			SetRMRelation(PChar, FRANCE, REL_WAR);		
			SetCharacterRelationBoth(GetCharacterIndex("Renouart Larrouse"),GetMainCharacterIndex(),RELATION_ENEMY);

			Group_CreateGroup("Renouart Larrouse");
			Group_AddCharacter("Renouart Larrouse", "Renouart Larrouse");
			Group_SetGroupCommander("Renouart Larrouse", "Renouart Larrouse");
			Group_SetPursuitGroup("Renouart Larrouse", PLAYER_GROUP);
			Group_SetTaskAttack("Renouart Larrouse", PLAYER_GROUP, true);
			Group_LockTask("Renouart Larrouse");
			Group_SetAddress("Renouart Larrouse", Characters[GetMainCharacterIndex()].location, "", "");

			UpdateRelations();

			Pchar.quest.gagne_victorieuse.win_condition.l1 = "NPC_Death";
			Pchar.quest.gagne_victorieuse.win_condition.l1.character = "Renouart Larrouse";
			Pchar.quest.gagne_victorieuse.win_condition = "won_victorieuse";
			break;

    	case "won_victorieuse":
			Pchar.quest.gagne_victorieuse.over = "yes";
			ChangeCharacterAddressGroup(CharacterFromID("Quest_French_Guard1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Quest_French_Guard2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Quest_French_Guard3"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Quest_French_Guard4"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Quest_French_Guard5"), "none", "", "");			
			ChangeCharacterAddressGroup(CharacterFromID("Quest_English_Patrol1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Quest_English_Patrol2"), "none", "", "");

			Characters[GetCharacterIndex("Cole Arkwright")].dialog.currentnode = "gov_15";			
			AddQuestRecord("Family_Story","16");
			break;

    	case "meet_lafitte":
			CloseQuestHeader("Family_Story");		
			SetQuestHeader("French_Companion");		
			AddQuestRecord("French_Companion","1");
			ChangeCharacterAddressGroup(characterFromID("Jean Lafitte"), "Tortuga_tavern", "goto", "goto8");
			SetCharacterShipLocation(CharacterFromID("Jean Lafitte"), "Tortuga_port");			
			LAi_SetCitizenType(characterFromID("Jean Lafitte"));
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_1";			
		break;
		
		case "abandon_quest":
			SetQuestHeader("French_Companion");		
			AddQuestRecord("French_Companion","6");
			CloseQuestHeader("French_Companion");
        break;			

		case "lafitte_tavern":
            DoQuestReloadToLocation("Tortuga_tavern", "sit", "sit2" ,"lafitte_tavern2");
        break;					
			
		case "lafitte_tavern2":
            Locations[FindLocation("Tortuga_port")].vcskip = true;		
			ChangeCharacterAddressGroup(characterFromID("Jean Lafitte"), "Tortuga_tavern", "sit", "sit8");
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_SetSitType(characterFromID("Jean Lafitte"));			
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_4";		
			LAi_ActorWaitDialog(CharacterFromID("Jean Lafitte"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Jean Lafitte"),"", 10.0, 10.0);
        break;

		case "lafitte_tortuga_port":
            Locations[FindLocation("Tortuga_tavern")].vcskip = false;			
		    LAi_SetPlayerType(pchar);				
            DoQuestReloadToLocation("Tortuga_port", "reload", "reload2_back" ,"leave_tortuga");		
        break;				

		case "leave_tortuga":	
			ChangeCharacterAddressGroup(CharacterFromID("Jean Lafitte"), "Tortuga_port", "goto", "goto31");
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_16";
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 3.0, 1.0);
        break;

		case "leave_tortuga2":
            Locations[FindLocation("Tortuga_port")].vcskip = false;		
			AddQuestRecord("French_Companion","2");			
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Jean Lafitte"));
			SetCharacterRemovable(characterFromID("Jean Lafitte"), false);
            ChangeCharacterAddressGroup(CharacterFromID("Jean Lafitte"), "none", "", "");			

			pchar.quest.go_turks.win_condition.l1 = "location";
			pchar.quest.go_turks.win_condition.l1.location = "Turks_Lighthouse";
			pchar.quest.go_turks.win_condition = "arrived_turks";
	    break;

		case "arrived_turks":
			Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_quest";					
			ChangeCharacterAddressGroup(CharacterFromID("Jean Lafitte"), "Turks_Lighthouse", "goto", "goto2");
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_18";
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 5.0, 1.0);
	    break;

		case "go_turks":
			SetCharacterShipLocation(CharacterFromID("Nigel Chandler"), "Turks_port");
			Locations[FindLocation("Turks_port")].locators_radius.goto.P_goto4 = 3.0;
            SetOfficersIndex(PChar, -1, GetCharacterIndex("Jean Lafitte"));				
			LAi_SetOfficerType(characterFromID("Jean Lafitte"));

			pchar.quest.go_town_turks.win_condition.l1 = "location";
			pchar.quest.go_town_turks.win_condition.l1.location = "Turks_port";
			pchar.quest.go_town_turks.win_condition = "arrived_town_turks";
		break;

		case "arrived_town_turks":
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_20";
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 2.0, 1.0);
		break;

		case "go_port_turks":		
			LAi_SetOfficerType(characterFromID("Jean Lafitte"));			

			pchar.quest.go_turks_port.win_condition.l1 = "locator";
			pchar.quest.go_turks_port.win_condition.l1.location = "Turks_port";
			pchar.quest.go_turks_port.win_condition.l1.locator_group = "goto";
			pchar.quest.go_turks_port.win_condition.l1.locator = "P_goto4";
			pchar.quest.go_turks_port.win_condition = "see_warship_moored";			
		break;

		case "see_warship_moored":
			RemovePassenger(pchar, characterFromID("Jean Lafitte"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Jean Lafitte"));			
			Locations[FindLocation("Turks_Tavern")].vcskip = true;					
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_21";
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 10.0, 1.0); 
		break;
			
		case "Talks_in_Turks_Tavern":	
			DoQuestReloadToLocation("Turks_Tavern", "candles", "sit3" ,"Talks_in_Turks_Tavern2");
		break;			

		case "Talks_in_Turks_Tavern2":
			ChangeCharacterAddressGroup(characterFromID("Jean Lafitte"), "Turks_Tavern", "sit", "sit4");
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_SetSitType(characterFromID("Jean Lafitte"));			
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_23";		
			LAi_ActorWaitDialog(CharacterFromID("Jean Lafitte"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Jean Lafitte"),"", 10.0, 10.0);
	    break;

		case "Talks_Turks_Barman":
			Locations[FindLocation("Turks_Tavern")].vcskip = false;			
			Characters[GetCharacterIndex("Josephine Bonassieu")].dialog.currentnode = "begin_1";				
			LAi_SetPlayerType(pchar);				
			DoQuestReloadToLocation("Turks_Tavern", "goto", "goto7" ,"Talks_Turks_Barman2");		
		break;				

		case "Talks_Turks_Barman2":	
			ChangeCharacterAddressGroup(CharacterFromID("Jean Lafitte"), "Turks_Tavern", "goto", "goto6");
			AddPassenger(Pchar, characterFromID("Jean Lafitte"), 0);
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Jean Lafitte"));
		break;

		case "Talks_Laura_Cotton":
			AddQuestRecord("French_Companion","3");
		
			pchar.quest.go_laura_house.win_condition.l1 = "locator";
			pchar.quest.go_laura_house.win_condition.l1.location = "Turks_port";
			pchar.quest.go_laura_house.win_condition.l1.locator_group = "Reload";
			pchar.quest.go_laura_house.win_condition.l1.locator = "houseH3";
			pchar.quest.go_laura_house.win_condition = "See_Laura_Cotton";			
        break;

		case "See_Laura_Cotton":
			ChangeCharacterAddressGroup(characterFromID("Laura Cotton"), "Turks_port", "Reload", "reload_jail");
	        Characters[GetCharacterIndex("Laura Cotton")].dialog.currentnode = "begin_1";		
            LAi_SetActorType(characterFromID("Laura Cotton"));
			LAi_ActorDialog(characterFromID("Laura Cotton"), pchar, "", 5.0, 1.0);				
        break;

		case "waiting_Laura_Cotton":
			RemovePassenger(pchar, characterFromID("Jean Lafitte"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Jean Lafitte"));		
			WaitDate("", 0,0,1,0,0);		
			SetCurrentTime(00.00, 0); 
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_30";			
            DoQuestReloadToLocation("Turks_port", "goto", "goto36" ,"waiting_Laura_Cotton2");			
        break;

		case "waiting_Laura_Cotton2":
			ChangeCharacterAddressGroup(characterFromID("Jean Lafitte"), "Turks_port", "goto", "goto37");
			ChangeCharacterAddressGroup(characterFromID("Laura Cotton"), "Turks_port", "goto", "goto38");
			ChangeCharacterAddressGroup(characterFromID("Killian Bencroft"), "Turks_port", "goto", "goto39");				
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 2.0, 1.0);			
        break;

		case "seeing_Laura_Cotton":
			LAi_SetActorType(CharacterFromID("Laura Cotton"));
			LAi_ActorGoToLocator(CharacterFromID("Laura Cotton"), "Reload", "houseH3", "", 30.0);
			LAi_SetActorType(characterfromID("Killian Bencroft"));
			LAi_ActorFollow(characterFromID("Killian Bencroft"), characterFromID("Laura Cotton"), "", 60.0);			
			LAi_SetActorType(pchar);
            LAi_ActorTurnToCharacter(pchar, characterFromID("Laura Cotton"));
			LAi_QuestDelay("Laura_Cotton_House", 8.0);			
        break;

		case "Laura_Cotton_House":
            LAi_SetPlayerType(Pchar);	
            DoQuestReloadToLocation("Laura_Cotton_House", "reload", "reload1" ,"Laura_Cotton_House2");	
        break;

		case "Laura_Cotton_House2":
			ChangeCharacterAddressGroup(characterFromID("Jean Lafitte"), "Laura_Cotton_House", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("Laura Cotton"), "Laura_Cotton_House", "goto", "goto4");
			ChangeCharacterAddressGroup(characterFromID("Killian Bencroft"), "Laura_Cotton_House", "goto", "goto5");
			LAi_SetActorType(characterFromID("Killian Bencroft"));
			LAi_ActorSetLayMode(characterFromID("Killian Bencroft"));

			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_32";
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 2.0, 1.0);						
        break;

		case "Laura_Cotton_House3":
	        Characters[GetCharacterIndex("Laura Cotton")].dialog.currentnode = "begin_15";		
            LAi_SetActorType(characterFromID("Laura Cotton"));
			LAi_ActorDialog(characterFromID("Laura Cotton"), pchar, "", 2.0, 1.0);				
        break;

		case "Laura_Cotton_House4":
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_33";
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 2.0, 1.0);
        break;

		case "Laura_Cotton_House5":
	        Characters[GetCharacterIndex("Laura Cotton")].dialog.currentnode = "begin_16";		
            LAi_SetActorType(characterFromID("Laura Cotton"));
			LAi_ActorDialog(characterFromID("Laura Cotton"), pchar, "", 2.0, 1.0);				
        break;

		case "before_operation":
           DoQuestReloadToLocation("Turks_port", "goto", "goto35" ,"before_operation2");			
        break;

		case "before_operation2":
			ChangeCharacterAddressGroup(characterFromID("Jean Lafitte"), "Turks_port", "goto", "goto34");
			SetModelfromArray(&pchar, GetModelIndex("47_Blaze_brtlt"));
            PChar.DisableModelSelect = true;
            StoreOfficers(pchar.id);			
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_34";
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 2.0, 1.0);			
        break;

		case "boarding_warship":
           Locations[FindLocation("Quest_Deck1")].vcskip = true;		
           Locations[FindLocation("Quest_Deck2")].vcskip = true;					
		   Locations[FindLocation("Quest_ShipDeck6")].reload.l3.disable = 1;
		   Locations[FindLocation("Quest_Deck2")].reload.l3.disable = 1;		   
		   ChangeCharacterAddressGroup(characterFromID("Henri Caesar"), "Quest_Hold1", "rld", "prison4");	
		   LAi_SetPoorType(characterfromID("Henri Caesar"));
		   Characters[GetCharacterIndex("Henri Caesar")].dialog.currentnode = "begin_1";		   
           DoQuestReloadToLocation("Quest_ShipDeck6", "goto", "goto11" ,"_");
		break;

		case "fight_navy_soldiers":
			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
			LAi_group_FightGroups("BRITISH_NAVY_SOLDIERS", LAI_GROUP_PLAYER, true);			
			LAi_SetImmortal(Pchar, false);
			LAi_group_SetCheck("BRITISH_NAVY_SOLDIERS", "fight_navy_soldiers_over");
		break;
		
		case "fight_navy_soldiers_2":
			PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
			LAi_group_FightGroups("BRITISH_NAVY_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_FightGroups("BRITISH_NAVY_SOLDIERS_2", LAI_GROUP_PLAYER, true);
			LAi_group_FightGroups("BRITISH_NAVY_SOLDIERS_3", LAI_GROUP_PLAYER, true);			
			LAi_SetImmortal(Pchar, false);
			LAi_group_SetCheck("BRITISH_NAVY_SOLDIERS_3", "fight_navy_soldiers_over_2");
		break;		

		case "fight_navy_soldiers_over":
			Locations[FindLocation("Quest_ShipDeck6")].reload.l3.disable = 0;
			LAi_group_FightGroups("BRITISH_NAVY_SOLDIERS_2", LAI_GROUP_PLAYER, true);
			LAi_group_FightGroups("BRITISH_NAVY_SOLDIERS_3", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("BRITISH_NAVY_SOLDIERS_3", "fight_navy_soldiers_over_2");			
			break;
			
		case "fight_navy_soldiers_over_2":
			Locations[FindLocation("Quest_Deck2")].reload.l3.disable = 0;	
		break;

		case "open_hold":
		    Locations[FindLocation("Quest_Deck2")].reload.l3.disable = 0;
			LAi_SetPatrolType(characterFromID("RN_soldier_6"));
		break;		

		case "plant_bomb":
		    Locations[FindLocation("Quest_ShipDeck6")].reload.l3.disable = 0;
			LAi_SetPatrolType(characterFromID("RN_soldier_1"));
		break;
		
		case "Caesar_stand_up":
			LAi_SetActorType(characterFromID("Henri Caesar"));		
			LAi_ActorAnimation(characterFromID("Henri Caesar"), "Ground_StandUp", "Caesar_stand_up2", 3.5);
		break;

		case "Caesar_stand_up2":
			LAi_SetActorType(characterFromID("Henri Caesar"));			
			Characters[GetCharacterIndex("Henri Caesar")].dialog.currentnode = "begin_6";
			LAi_ActorDialog(characterFromID("Henri Caesar"), pchar, "", 3.0, 1.0);	
		break;		
			
		case "endeavour_sinking_video":
			SetCharacterShipLocation(CharacterFromID("Nigel Chandler"), "none");
			
			GiveShip2Character(CharacterFromID("Laura Cotton"),"obj_soldier","Nothing",-1,ENGLAND,true,true);
			SetCharacterShipLocation(CharacterFromID("Laura Cotton"), "Turks_port");
			TakeItemFromCharacter(pchar, "time_bomb");					
			
			Locations[FindLocation("Turks_port")].models.always.general = "HMS_Endeavour";
			Locations[FindLocation("Turks_port")].models.always.general.locator.group = "ships_other";
			Locations[FindLocation("Turks_port")].models.always.general.locator.name = "ship1";			
			SetNextWeather("Clear");		
			PostVideoAndQuest("FreePlay\Endeavour",1, "seeing_endeavour_wreckage");		
		break;

		case "seeing_endeavour_wreckage":
			DoQuestReloadToLocation("Turks_port", "goto", "goto40" ,"seeing_endeavour_wreckage2");
		break;

		case "seeing_endeavour_wreckage2":
			ChangeCharacterAddressGroup(characterFromID("Jean Lafitte"), "Turks_port", "goto", "goto41");
			LAi_QuestDelay("seeing_endeavour_wreckage3", 6.0);				
		break;

		case "seeing_endeavour_wreckage3":
			RestoreOfficers(pchar.id);			
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_38";
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 2.0, 1.0);			
		break;

		case "back_to_lighthouse":	
			DoQuestReloadToLocation("Turks_Lighthouse", "goto", "goto1" ,"back_to_lighthouse2");	
		break;

		case "back_to_lighthouse2":
			DeleteAttribute(PChar, "DisableModelSelect");
			SetModelfromArray(&pchar, GetModelIndex("Almeida"));
			
			ChangeCharacterAddressGroup(characterFromID("Henri Caesar"), "Turks_Lighthouse", "goto", "goto5");		
			ChangeCharacterAddressGroup(characterFromID("Jean Lafitte"), "Turks_Lighthouse", "goto", "goto3");
			Characters[GetCharacterIndex("Henri Caesar")].dialog.currentnode = "begin_9";
			LAi_SetActorType(characterFromID("Henri Caesar"));
			LAi_ActorDialog(characterFromID("Henri Caesar"), pchar, "", 2.0, 1.0);		    
		break;

		case "return_to_eleuthera":
			SetCharacterShipLocation(CharacterFromID("Laura Cotton"), "none");
			ChangeRMRelation(pchar, ENGLAND, -20.0);			
			AddQuestRecord("French_Companion","4");		
			Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators";
			DeleteAttribute(&Locations[FindLocation("Turks_port")],"models.always.general");
			
			AddPassenger(Pchar, characterFromID("Jean Lafitte"), 0);
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Jean Lafitte"));			
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_SetOfficerType(characterFromID("Jean Lafitte"));
			
			LAi_SetActorType(characterFromID("Henri Caesar"));			
			LAi_ActorRunToLocation(characterFromID("Henri Caesar"), "goto", "goto2", "none", "", "", "", 8.0);				

			pchar.quest.goodbye_caesar.win_condition.l1 = "location";
			pchar.quest.goodbye_caesar.win_condition.l1.location = "Eleuthera_Port";
			pchar.quest.goodbye_caesar.win_condition = "return_to_eleuthera2";		
		break;

		case "return_to_eleuthera2":
			Characters[GetCharacterIndex("Cole Arkwright")].dialog.currentnode = "gov_27";				
			ChangeCharacterAddressGroup(characterFromID("Henri Caesar"), "Eleuthera_Port", "goto", "goto8");		
			Characters[GetCharacterIndex("Henri Caesar")].dialog.currentnode = "begin_12";
			LAi_SetActorType(characterFromID("Henri Caesar"));
			LAi_ActorDialog(characterFromID("Henri Caesar"), pchar, "", 3.0, 1.0);		    
		break;

		case "return_to_eleuthera3":
			LAi_SetActorType(characterFromID("Henri Caesar"));			
			LAi_ActorRunToLocation(characterFromID("Henri Caesar"), "goto", "goto7", "none", "", "", "", 5.0);	
		break;

		case "leave_governor_eleuthera":				
			DoQuestReloadToLocation("Eleuthera_Port", "goto", "goto3" ,"leave_governor_eleuthera2");				
		break;

		case "leave_governor_eleuthera2":				
			Characters[GetCharacterIndex("Jean Lafitte")].dialog.currentnode = "begin_39";			
			LAi_SetActorType(characterFromID("Jean Lafitte"));
			LAi_ActorDialog(characterFromID("Jean Lafitte"), pchar, "", 4.0, 1.0);					
		break;

		case "goodbye_lafitte":	
			AddQuestRecord("French_Companion","5");
			CloseQuestHeader("French_Companion");			
			LAi_SetActorType(characterFromID("Jean Lafitte"));			
			LAi_ActorRunToLocation(characterFromID("Jean Lafitte"), "reload", "reload3_back", "none", "", "", "", 5.0);	
		break;	

///////////////////////////////////////////////////////////////
///// FREEPLAY: ENGINEER JRH
///////////////////////////////////////////////////////////////

		case "monk_map_talk":
			PlaySound("PEOPLE\creak2.wav");	
			LAi_SetStayType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("NC_monk3"), "new_cloister_inside", "sit", "stay1");
			LAi_SetActorType(characterFromID("NC_monk3"));

			LAi_QuestDelay("monk_map_talk1", 0.5);
		break;

		case "monk_map_talk1":
			LAi_SetActorType(characterFromID("NC_monk3"));
			LAi_ActorDialog(characterFromID("NC_monk3"), pchar, "", 0.0, 0.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("NC_monk3"));
			Characters[GetCharacterIndex("NC_monk3")].dialog.CurrentNode  = "map";
		break;		

		case "library_bars1":
			if (Pchar.sex == "man") { PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav"); }
			else PlaySound("VOICE\ENGLISH\gr_wench3_oh.wav");

			if(GetAttribute(pchar, "sakharine_phase") == "0")
			{
				Pchar.sakharine_phase = 1;
				LogIt(TranslateString("","It's Sakharine - is he dead?"));
			}
			else
			{
				LogIt(TranslateString("","There's poor Sakharine again."));
			}	

			LAi_SetCitizenType(characterFromID("NC_monkL"));
		break;

		case "library_bars2":
			if (Pchar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_huh.wav"); }
			else PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");

			if(GetAttribute(pchar, "sakharine_phase") == "0")
			{
				Pchar.sakharine_phase = 1;
				LogIt(TranslateString("","It's Sakharine - is he dead?"));
			}
			else
			{
				LogIt(TranslateString("","There's poor Sakharine again."));
			}

			LAi_SetCitizenType(characterFromID("NC_monkL"));
		break;

		case "portugize_extra_sound":
			PlaySound("PEOPLE\beltkey.wav");
		break;

		case "check_portugize_parts":
			if(CheckCharacterItem(Pchar,"port_stock") || CheckCharacterItem(Pchar,"port_metal") || CheckCharacterItem(Pchar,"port_rest")
			|| CheckCharacterItem(Pchar,"port_magazine") || CheckCharacterItem(Pchar,"port_barrel") || CheckCharacterItem(Pchar,"port_mechanism"))
			{
				AddQuestRecord("Beginning_Engineer", "6");
			}

			if(CheckCharacterItem(Pchar,"port_stock") && CheckCharacterItem(Pchar,"port_metal") && CheckCharacterItem(Pchar,"port_rest")
			&& CheckCharacterItem(Pchar,"port_magazine") && CheckCharacterItem(Pchar,"port_barrel") && CheckCharacterItem(Pchar,"port_mechanism"))
			{
				if(CheckCharacterItem(Pchar,"port_tools"))
				{
					AddQuestRecord("Beginning_Engineer", "9");	
				}
				else AddQuestRecord("Beginning_Engineer", "7");

				if(GetAttribute(pchar, "portugize_phase") == "0")
				{
					Pchar.portugize_phase = 1;
				}	
			}
			else 
			{
				if(CheckCharacterItem(Pchar,"port_tools")) AddQuestRecord("Beginning_Engineer", "8");
			}
		break;

		case "portugize_equip":
			PlaySound("OBJECTS\DUEL\reload1.wav");

			string weaponID = GetCharacterEquipByGroup(Pchar,BLADE_ITEM_TYPE);
			aref weapon;
			Items_FindItem(weaponID, &weapon);

			if(CheckAttribute(weapon, "id") && weapon.id == "")
			{
				EquipCharacterByItem(Pchar, BLADE_ITEM_TYPE);	
			}

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			EquipCharacterByItem(pchar, "portugize");

			LAi_QuestDelay("portugize_yes", 1.0);
		break;

		case "portugize_yes":
			if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack6.wav"); }
			else PlaySound("VOICE\ENGLISH\gr_wench3_pos.wav");

			LAi_QuestDelay("engineer_mission_complete_check", 0.5);
		break;

		case "engineer_mission_complete_check":
			if(GetAttribute(pchar, "engineer_mission") == "done") return;

			int gp = GetCharacterItem(Pchar, "gunpowder");
			int pg = GetCharacterItem(Pchar, "pistolgrapes");

			if(gp >= 5 && pg >= 5 && CheckCharacterItem(Pchar,"portugize"))
			{
				//mission complete
				DeleteQuestHeader("Beginning_Engineer");
				SetQuestHeader("Beginning_Engineer");
				AddQuestRecord("Beginning_Engineer", "11");
				CloseQuestHeader("Beginning_Engineer");

				Pchar.engineer_mission = "done";
			}
			else
			{
				if(CheckCharacterItem(Pchar,"portugize"))
				{
					AddQuestRecord("Beginning_Engineer", "10");
				}
			}
		break;

		case "check_portugize_books":
			if(CheckCharacterItem(Pchar,"book21F") && CheckCharacterItem(Pchar,"book22F") && CheckCharacterItem(Pchar,"book23F")
			&& CheckCharacterItem(Pchar,"book24F") && CheckCharacterItem(Pchar,"book26F") && CheckCharacterItem(Pchar,"book27F")
			&& CheckCharacterItem(Pchar,"book28F") && CheckCharacterItem(Pchar,"book29F") && CheckCharacterItem(Pchar,"book31F")
			&& CheckCharacterItem(Pchar,"book33F") && CheckCharacterItem(Pchar,"book34F") && CheckCharacterItem(Pchar,"book35F")
			&& CheckCharacterItem(Pchar,"book36F")) 
			{
				LAi_QuestDelay("librarian_change", 0.5);
			}
			else
			{
				if(CheckCharacterItem(Pchar,"book21F") || CheckCharacterItem(Pchar,"book22F") || CheckCharacterItem(Pchar,"book23F")
				|| CheckCharacterItem(Pchar,"book24F") || CheckCharacterItem(Pchar,"book26F") || CheckCharacterItem(Pchar,"book27F")
				|| CheckCharacterItem(Pchar,"book28F") || CheckCharacterItem(Pchar,"book29F") || CheckCharacterItem(Pchar,"book31F")
				|| CheckCharacterItem(Pchar,"book33F") || CheckCharacterItem(Pchar,"book34F") || CheckCharacterItem(Pchar,"book35F")
				|| CheckCharacterItem(Pchar,"book36F")) 
				{
					LAi_QuestDelay("librarian_hostile", 0.5);
				}
				else
				{
					//no books stolen - no attack from librarian
					LAi_QuestDelay("librarian_neutral", 0.5);
				}
			}
		break;

		case "librarian_change":
			if(GetAttribute(pchar, "NC_librarian") == "gone") return;

			LAi_SetActorType(characterFromID("NC_monkL"));
			ChangeCharacterAddressGroup(characterFromID("NC_monkL"), "new_cloister_library", "quest", "end");
			
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box13", 1.0);
			Locations[FindLocation("new_cloister_library")].locators_radius.box.box13 = 1.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload1", 0.0001);
			Locations[FindLocation("new_cloister_library")].locators_radius.reload.reload1 = 0.0001;

			pchar.quest.librarian_change1.win_condition.l1 = "locator";
			pchar.quest.librarian_change1.win_condition.l1.location = "new_cloister_library";
			pchar.quest.librarian_change1.win_condition.l1.locator_group = "quest";
			pchar.quest.librarian_change1.win_condition.l1.locator = "end";
			pchar.quest.librarian_change1.win_condition = "librarian_change1";	
		break;

		case "librarian_change1":
			Pchar.NC_librarian = "gone";

			LAi_SetActorType(characterFromID("NC_monkL"));
			LAi_ActorDialog(characterFromID("NC_monkL"), pchar, "", 0.0, 0.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("NC_monkL"));
			Characters[GetCharacterIndex("NC_monkL")].dialog.CurrentNode  = "change";
		break;

		case "librarian_change7":
			//1 librarian diappears
			
			LAi_SetStayType(Pchar);
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			CreateParticleSystem("smoke_short" , -3.7, 3.7, -1.3, 0.0, 0.0, 0.0, sti(20) );
		//CreateParticleSystemX("blast_dirt", -17.2, 4.9, -24.4, -17.2, 4.9, -24.4, 10);
			ChangeCharacterAddressGroup(CharacterFromID("NC_monkL"), "none", "", "");

			LAi_QuestDelay("librarian_change8", 1.5);
		break;

		case "librarian_change8":
			//2 pchar new outfit

			PlaySound("PEOPLE\transform.wav");
			float u, v, w;
			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("stars_short" , u, v+1.4, w, 0.0, 0.0, 0.0, sti(20) );

			SetModel(PChar, "Animists3_empty", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			Pchar.old.name = "Librarian";
			Pchar.old.lastname = "";
			Pchar.name = TranslateString("", "Librarian");
			Pchar.lastname = "";

			LAi_QuestDelay("librarian_change9", 1.5);
		break;

		case "librarian_change9":
			LAi_SetPlayerType(Pchar);
			if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_scream.wav"); }
			else PlaySound("VOICES\DEAD\female\dead_wom1.wav");
		break;

		case "library_for_ever":
			LAi_SetActorType(pchar);	
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "library_for_ever";
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "library_for_ever1":
			LAi_SetPlayerType(pchar);
		break;

		case "librarian_hostile":
			if(GetAttribute(pchar, "NC_librarian") == "gone") return;

			PlaySound("VOICE\ENGLISH\c_brother21.wav");
			LAi_LocationFightDisable(&Locations[FindLocation("new_cloister_library")], false);
		
			LAi_SetActorType(characterFromID("NC_monkL"));
			LAi_ActorAttack(CharacterFromID("NC_monkL"), Pchar, "");
		break;

		case "librarian_neutral":
			if(GetAttribute(pchar, "NC_librarian") == "gone") return;

			LAi_LocationFightDisable(&Locations[FindLocation("new_cloister_library")], true);
			if(LAi_IsFightMode(characterFromID("NC_monkL")))
			{
				LAi_SetFightMode(characterFromID("NC_monkL"), false);
			}
			
			LAi_SetCitizenType(characterFromID("NC_monkL"));
		break;

		case "cartagena_cloister_open":
			PlaySound("PEOPLE\creak2.wav");			

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload5", 1.5);		//access to library
			Locations[FindLocation("new_cloister_inside")].locators_radius.reload.reload5 = 1.5;

			ChangeCharacterAddressGroup(characterFromID("NC_monk3"), "new_cloister_inside", "sit", "sit1");
			LAi_SetSitType(characterFromID("NC_monk3"));
			Characters[GetCharacterIndex("NC_monk3")].dialog.CurrentNode  = "First time";

			Pchar.cartagena_library = "open";
			LAi_SetPlayerType(Pchar);
		break;

///////////////////////////////////////////////////////////////
///// FREEPLAY: GAMBLER JRH & PW
///////////////////////////////////////////////////////////////

		
		case "Competition_Day_One_Start": //from bouncer_dialog
			PChar.quest.poker.started = "true";
			PChar.quest.poker.day = "1";
			PChar.quest.poker.result = "0";
			sld = &characters[GetCharacterIndex("Reg_L")];
			LAi_SetActorType(sld);
			LAi_SetActorType(Pchar);
			LAi_ActorWaitDialog(Pchar,sld);
			LAi_ActorDialog(sld, Pchar, "", 0, 0);
			LAi_SetPlayerType(Pchar);
			Locations[FindLocation("Turks_poker_room")].reload.l1.disable = true;
			DisableFastTravel(true);
			DeleteAttribute(PChar, "quest.Poker_next_tournament_Noreturn");
		break;
		
		
		case "Instructions":
		locations[FindLocation(Pchar.location)].image = "poker_entre.tga";
		sld = &characters[GetCharacterIndex("Reg_L")];
		if (!checkAttribute(PChar,"quest.poker.winner"))
			{
			Characters[GetCharacterIndex("Reg_L")].dialog.CurrentNode  = "Instructions1";
			}
			else
			{
			Characters[GetCharacterIndex("Reg_L")].dialog.CurrentNode  = "Onward 2";
			}
		LAi_SetActorType(sld);
		LAi_SetActorType(Pchar);
		LAi_ActorWaitDialog(Pchar,sld);
		LAi_ActorDialog(sld, Pchar, "", 1.0, 0);
		LAi_SetPlayerType(Pchar);
		break;
		
		case "Competition_Day_One_Start2": //from Poker Twins_dialog.c
			
			if (CheckAttribute(Pchar,"quest.poker.winner"))
			{
			RemoveCharacterEquip(characterFromID(Pchar.quest.poker.winner), BLADE_ITEM_TYPE);//
			if (CheckCharacterItem(characterFromID(Pchar.quest.poker.winner),"bladetrophy"))TakeItemFromCharacter(characterFromID(Pchar.quest.poker.winner), "bladetrophy");
			}
			EquipCharacterByItem(Pchar, Pchar.equip.blade);
			sld = &characters[GetCharacterIndex("Ron_L")];
			Characters[GetCharacterIndex("Ron_L")].dialog.CurrentNode  = "Ronnie speaks";
			times = sti(pchar.quest.poker.times) + 1;
			pchar.quest.poker.times = times;
		break;
		
		
		
		case "Competition_day_end":// from quests.commom.c
		switch (Pchar.quest.poker.day)
		{
			case "1":	
				Characters[GetCharacterIndex("Reg_L")].dialog.CurrentNode  = "Day one end";
				
			break;

			case "3":
			Characters[GetCharacterIndex("Reg_L")].dialog.CurrentNode  = "Day two end";
			
			break;
			
			case "5":
			//workout who won
				switch(Pchar.quest.poker.result)
				{
				case "9":Pchar.quest.poker.winner = "Blaze";break;
				case "8":Pchar.quest.poker.winner = "Gambler 1";break;
				case "6":Pchar.quest.poker.winner = "Gambler 2";break;
				case "5":Pchar.quest.poker.winner = "Gambler 2";break;
				case "4":Pchar.quest.poker.winner = "Gambler 3";break;
				case "3":Pchar.quest.poker.winner = "Gambler 3";break;
				case "1":Pchar.quest.poker.winner = "Gambler 3";break;
				case "0":Pchar.quest.poker.winner = "Gambler 1";break;
				}
			
				Characters[GetCharacterIndex("Reg_L")].dialog.CurrentNode  = "Day three end";
				LAi_SetActorType(Pchar);
				Lai_ActorRunToLocator(pchar, "goto", "goto18", "", 0);//pw was 17
			break;
		}		
				
		ChangeCharacterAddressGroup(characterFromID("Ron_L"), "Turks_poker_room", "goto", "goto14");
		ChangeCharacterAddressGroup(characterFromID("Reg_L"), "Turks_poker_room", "goto", "goto15");
				
		sld = &characters[GetCharacterIndex("Ron_L")];
		LAi_SetActorType(sld);
		sld = &characters[GetCharacterIndex("Reg_L")];
		LAi_SetActorType(sld);
		LAi_SetActorType(Pchar);
		LAi_ActorTurnToLocator(Pchar,"goto","goto15");
		LAi_ActorWaitDialog(Pchar, sld);
		LAi_ActorDialog(sld, Pchar, "", 1.0, 0);
		LAi_SetPlayerType(Pchar);
		DisableFastTravel(false);
		break;
		
		case "Competition_Day_One_Timer"://from Poker Twins_dialog.c
		PChar.quest.Day_Expired.win_condition.l1 = "Timer";
		PChar.quest.Day_Expired.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
		PChar.quest.Day_Expired.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
		PChar.quest.Day_Expired.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
		PChar.quest.Day_Expired.win_condition = "Competition_Day_Two_Start";
		
		PChar.quest.Day_Noreturn.win_condition.l1 = "Timer";
		PChar.quest.Day_Noreturn.win_condition.l1.date.day = GetAddingDataDay(0, 0, 2);
		PChar.quest.Day_Noreturn.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2);
		PChar.quest.Day_Noreturn.win_condition.l1.date.year = GetAddingDataYear(0, 0, 2);
		PChar.quest.Day_Noreturn.win_condition = "Competition_Lockout";
		break;
		
		
		case "Competition_Day_Two_Start"://timer set in this file
		ChangeCharacterAddressGroup(characterFromID("Gambler 1"), "Turks_poker_room", "sit", "sit6");
		ChangeCharacterAddressGroup(characterFromID("Gambler 2"), "Turks_poker_room", "sit", "sit3");
		ChangeCharacterAddressGroup(characterFromID("Gambler 3"), "Turks_poker_room", "sit", "sit2");
		ChangeCharacterAddressGroup(characterFromID("Ron_L"), "Turks_poker_room", "goto", "goto14");
		ChangeCharacterAddressGroup(characterFromID("Reg_L"), "Turks_poker_room", "goto", "goto5");
		Pchar.quest.poker.day = "3";
		Locations[FindLocation("Turks_poker_room")].reload.l1.disable = true;
		Locations[FindLocation("Turks_poker_entre")].reload.l3.disable = false;
		sld = &characters[GetCharacterIndex("Ron_L")];
		Characters[GetCharacterIndex("Ron_L")].dialog.CurrentNode  = "Day two";
		LAi_SetPlayerType(sld);	
		DisableFastTravel(true);
		
		break;
		
		case "Competition_Day_Two_Timer"://from Poker Twins_dialog.c
		PChar.quest.Day_Expired.win_condition.l1 = "Timer";
		PChar.quest.Day_Expired.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
		PChar.quest.Day_Expired.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
		PChar.quest.Day_Expired.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
		PChar.quest.Day_Expired.win_condition = "Competition_Day_Three_Start";
		
		PChar.quest.Day_Noreturn.win_condition.l1 = "Timer";
		PChar.quest.Day_Noreturn.win_condition.l1.date.day = GetAddingDataDay(0, 0, 2);
		PChar.quest.Day_Noreturn.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2);
		PChar.quest.Day_Noreturn.win_condition.l1.date.year = GetAddingDataYear(0, 0, 2);
		PChar.quest.Day_Noreturn.win_condition = "Competition_Lockout";
		break;
		
		case "Competition_Day_Three_Start"://timer set in this file
		ChangeCharacterAddressGroup(characterFromID("Gambler 1"), "Turks_poker_room", "sit", "sit6");
		ChangeCharacterAddressGroup(characterFromID("Gambler 2"), "Turks_poker_room", "sit", "sit4");
		ChangeCharacterAddressGroup(characterFromID("Gambler 3"), "Turks_poker_room", "sit", "sit3");
		ChangeCharacterAddressGroup(characterFromID("Ron_L"), "Turks_poker_room", "goto", "goto14");
		ChangeCharacterAddressGroup(characterFromID("Reg_L"), "Turks_poker_room", "goto", "goto7");
		PChar.quest.poker.day = "5";
		DisableFastTravel(true);
		Locations[FindLocation("Turks_poker_room")].reload.l1.disable = true;
		Locations[FindLocation("Turks_poker_entre")].reload.l3.disable = false;
		sld = &characters[GetCharacterIndex("Ron_L")];
		Characters[GetCharacterIndex("Ron_L")].dialog.CurrentNode  = "Day three";
		LAi_SetPlayerType(sld);	
		
		break;
		
			
		case "Competition_New_Comp_Timer": //from Poker Twins_dialog.c
		
		PChar.quest.Poker_near_next_tournament.win_condition.l1 = "Timer";
		PChar.quest.Poker_near_next_tournament.win_condition.l1.date.day = GetAddingDataDay(0, 5, 0);
		PChar.quest.Poker_near_next_tournament.win_condition.l1.date.month = GetAddingDataMonth(0, 5, 0);
		PChar.quest.Poker_near_next_tournament.win_condition.l1.date.year = GetAddingDataYear(0, 5, 0);
		PChar.quest.Poker_near_next_tournament.win_condition = "Nearly Next Competition";
		
		
		PChar.quest.Poker_next_tournament.win_condition.l1 = "Timer";
		PChar.quest.Poker_next_tournament.win_condition.l1.date.day = GetAddingDataDay(0, 6, 0);
		PChar.quest.Poker_next_tournament.win_condition.l1.date.month = GetAddingDataMonth(0, 6, 0);
		PChar.quest.Poker_next_tournament.win_condition.l1.date.year = GetAddingDataYear(0, 6, 0);
		PChar.quest.Poker_next_tournament.win_condition = "Competition_Reset_Stuff";
		
		PChar.quest.Poker_next_tournament_Noreturn.win_condition.l1 = "Timer";
		PChar.quest.Poker_next_tournament_Noreturn.win_condition.l1.date.day = GetAddingDataDay(0, 7, 0);
		PChar.quest.Poker_next_tournament_Noreturn.win_condition.l1.date.month = GetAddingDataMonth(0, 7, 0);
		PChar.quest.Poker_next_tournament_Noreturn.win_condition.l1.date.year = GetAddingDataYear(0, 7, 0);
		PChar.quest.Poker_next_tournament_Noreturn.win_condition = "Competition_Lockout3";
		break;
		
		
		case "Nearly Next Competition"://timer set in this file 5 months - 1 month before next one give warning/reminder
		AddQuestRecord("Poker_Tournament", 8);
		break;
		
		case "Competition Winner": //Trophy presentation to pchar//from Poker Twins_dialog.c
		LAi_SetActorType(&characters[GetCharacterIndex("Gambler 3")]);
		LAi_SetActorType(&characters[GetCharacterIndex("Gambler 1")]);
		LAi_SetActorType(&characters[GetCharacterIndex("Gambler 2")]);
		LAi_SetActorType(&characters[GetCharacterIndex("Reg_L")]);
		LAi_ActorTurnToLocator(characterFromID("Gambler 1"),"goto","goto19");

		//LAi_SetActorType(Pchar);	
		//Lai_ActorRunToLocator(pchar, "goto", "goto17", "", 0);
		ChangeCharacterAddressGroup(characterFromID("Gambler 1"), "Turks_poker_room", "goto", "goto17");//pw was 18
		ChangeCharacterAddressGroup(characterFromID("Gambler 2"), "Turks_poker_room", "goto", "goto19");
		ChangeCharacterAddressGroup(characterFromID("Gambler 3"), "Turks_poker_room", "goto", "goto20");
		Pchar.quest.poker.blade = Pchar.equip.blade;
			
			switch(Pchar.quest.poker.winner)
				{
					
				case "Blaze":
				LAi_SetActorType(Pchar);
				LAi_ActorTurnToCharacter(Pchar, characterFromID("Ron_L"));
				Lai_ActorRunToLocator(Pchar, "goto", "goto16", "presentation", 2);
				
				break;
				
				case "Gambler 1":
				ChangeCharacterAddressGroup(Pchar, "Turks_poker_room", "goto", "goto18");//pw was 17
				LAi_SetActorType(Pchar);
				LAi_ActorTurnToCharacter(Pchar, characterFromID("Ron_L"));
				LAi_ActorRunToLocator(characterFromID("Gambler 1"),"goto","goto16", "presentation", 3);
				break;
				
				case "Gambler 2":
				ChangeCharacterAddressGroup(Pchar, "Turks_poker_room", "goto", "goto18");//pw was 17
				LAi_SetActorType(Pchar);
				LAi_ActorTurnToCharacter(Pchar, characterFromID("Ron_L"));
				Lai_ActorRunToLocator(characterFromID("Gambler 2"), "goto", "goto16", "presentation", 3);
				break;
											
				case "Gambler 3":
				ChangeCharacterAddressGroup(Pchar, "Turks_poker_room", "goto", "goto18");//pw was 17
				LAi_SetActorType(Pchar);
				LAi_ActorTurnToCharacter(Pchar, characterFromID("Ron_L"));
				Lai_ActorRunToLocator(characterFromID("Gambler 3"), "goto", "goto16", "presentation", 3);
				break;
				
				}
		
		break;
		
		case "presentation":
		LAi_LocationFightDisable(&Locations[FindLocation("Turks_poker_room")], false);//unset room	
			switch(Pchar.quest.poker.winner)
				{
					
				case "Blaze":
				LAi_SetPlayerType(characterFromID("Ron_L"));
				LAi_SetFightMode(characterFromID("Ron_L"), true);
				EquipCharacterByItem(Pchar, "bladeX4");
				LAi_SetPlayerType(Pchar);
				LAi_SetFightMode(PChar, true);
				break;
				
				case "Gambler 1":
				LAi_ActorTurnToCharacter(characterFromID("Gambler 1"), characterFromID("Ron_L"));
				LAi_SetPlayerType(characterFromID("Ron_L"));
				LAi_SetFightMode(characterFromID("Ron_L"), true);
				RemoveCharacterEquip(characterFromID("Gambler 1"), BLADE_ITEM_TYPE);
				GiveItem2Character(characterFromID("Gambler 1"), "bladeX4");
				EquipCharacterByItem(characterFromID("Gambler 1"), "bladeX4");
				LAi_SetPlayerType(characterFromID("Gambler 1"));
				LAi_SetFightMode(characterFromID("Gambler 1"), true);
				break;
				
				case "Gambler 2":
				LAi_ActorTurnToCharacter(characterFromID("Gambler 2"), characterFromID("Ron_L"));
				LAi_SetPlayerType(characterFromID("Ron_L"));
				LAi_SetFightMode(characterFromID("Ron_L"), true);
				RemoveCharacterEquip(characterFromID("Gambler 2"), BLADE_ITEM_TYPE);
				GiveItem2Character(characterFromID("Gambler 2"), "bladeX4");
				EquipCharacterByItem(characterFromID("Gambler 2"), "bladeX4");
				LAi_SetPlayerType(characterFromID("Gambler 2"));
				LAi_SetFightMode(characterFromID("Gambler 2"), true);
				break;
											
				case "Gambler 3":
				LAi_ActorTurnToCharacter(characterFromID("Gambler 3"), characterFromID("Ron_L"));
				LAi_SetPlayerType(characterFromID("Ron_L"));
				LAi_SetFightMode(characterFromID("Ron_L"), true);
				RemoveCharacterEquip(characterFromID("Gambler 3"), BLADE_ITEM_TYPE);
				GiveItem2Character(characterFromID("Gambler 3"), "bladeX4");
				EquipCharacterByItem(characterFromID("Gambler 3"), "bladeX4");
				LAi_SetPlayerType(characterFromID("Gambler 3"));
				LAi_SetFightMode(characterFromID("Gambler 3"), true);
				break;
				
				}
				LAi_QuestDelay("presentation1", 2);
		break;
		
		case "presentation1": 
				RemoveCharacterEquip(characterFromID("Ron_L"), BLADE_ITEM_TYPE);
				GiveItem2Character(characterFromID("Ron_L"), "bladeX4");
				EquipCharacterByItem(characterFromID("Ron_L"), "bladeX4");
								
			switch(Pchar.quest.poker.winner)
				{
					
				case "Blaze":
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				GiveItem2Character(Pchar, "bladetrophy");//give trophy
				EquipCharacterByItem(Pchar, "bladetrophy");//show trophy  
				break;
				
				case "Gambler 1":
				RemoveCharacterEquip(characterFromID("Gambler 1"), BLADE_ITEM_TYPE);
				GiveItem2Character(characterFromID("Gambler 1"), "bladetrophy");//give trophy
				EquipCharacterByItem(characterFromID("Gambler 1"), "bladetrophy");//show trophy  
				break;
				
				case "Gambler 2":
				RemoveCharacterEquip(characterFromID("Gambler 2"), BLADE_ITEM_TYPE);
				GiveItem2Character(characterFromID("Gambler 2"), "bladetrophy");//give trophy
				EquipCharacterByItem(characterFromID("Gambler 2"), "bladetrophy");//show trophy  
				break;
											
				case "Gambler 3":
				RemoveCharacterEquip(characterFromID("Gambler 3"), BLADE_ITEM_TYPE);
				GiveItem2Character(characterFromID("Gambler 3"), "bladetrophy");//give trophy
				EquipCharacterByItem(characterFromID("Gambler 3"), "bladetrophy");//show trophy 
				break;
				
				}
				LAi_QuestDelay("presentation2", 1);
		break;
		
		case "presentation2": 
		
				if(LAi_IsFightMode(characterFromID("Ron_L"))) LAi_SetFightMode(characterFromID("Ron_L"), false);
				if(LAi_IsFightMode(Pchar)) LAi_SetFightMode(Pchar, false);
				if(LAi_IsFightMode(characterFromID("Gambler 1"))) LAi_SetFightMode(characterFromID("Gambler 1"), false);
				if(LAi_IsFightMode(characterFromID("Gambler 2"))) LAi_SetFightMode(characterFromID("Gambler 2"), false);
				if(LAi_IsFightMode(characterFromID("Gambler 3"))) LAi_SetFightMode(characterFromID("Gambler 3"), false);
				
				LAi_LocationFightDisable(&Locations[FindLocation("Turks_poker_room")], true);		
				
				
				LAi_QuestDelay("presentation3", 1.0);
				
		break;
		
		case "presentation3": 
	
		Switch (pchar.quest.poker.times)
{
		
		case "1":
		Preprocessor_AddQuestData("date1", GetHumanDate(GetAddingDataYear(0, 6, 0), GetAddingDataMonth(0, 6, 0), GetAddingDataDay(0, 6, 0)));
		if (Pchar.quest.poker.winner  == "Blaze")
				{
				PlaySound("INTERFACE\coins8.wav");
				AddMoneyToCharacter(Pchar, 60000);
				AddQuestRecord("Poker_Tournament", 10);
				LAi_SetPlayerType(Pchar);
				}
				else AddQuestRecord("Poker_Tournament", 11);
		Preprocessor_Remove("date1");
		break;

		case "2":
		Preprocessor_AddQuestData("date2", GetHumanDate(GetAddingDataYear(0, 6, 0), GetAddingDataMonth(0, 6, 0), GetAddingDataDay(0, 6, 0)));
		if (Pchar.quest.poker.winner  == "Blaze")
				{
				PlaySound("INTERFACE\coins8.wav");
				AddMoneyToCharacter(Pchar, 60000);
				AddQuestRecord("Poker_Tournament", 12);
				LAi_SetPlayerType(Pchar);
				}
				else AddQuestRecord("Poker_Tournament", 13);
		Preprocessor_Remove("date2");
		break;
		
		case "3":
		Preprocessor_AddQuestData("date3", GetHumanDate(GetAddingDataYear(0, 6, 0), GetAddingDataMonth(0, 6, 0), GetAddingDataDay(0, 6, 0)));
		if (Pchar.quest.poker.winner  == "Blaze")
				{
				PlaySound("INTERFACE\coins8.wav");
				AddMoneyToCharacter(Pchar, 60000);
				AddQuestRecord("Poker_Tournament", 14);
				LAi_SetPlayerType(Pchar);
				}
				else AddQuestRecord("Poker_Tournament", 15);
		Preprocessor_Remove("date3");
		break;
		
		case "4":
		Preprocessor_AddQuestData("date4", GetHumanDate(GetAddingDataYear(0, 6, 0), GetAddingDataMonth(0, 6, 0), GetAddingDataDay(0, 6, 0)));
		if (Pchar.quest.poker.winner  == "Blaze")
				{
				PlaySound("INTERFACE\coins8.wav");
				AddMoneyToCharacter(Pchar, 60000);
				AddQuestRecord("Poker_Tournament", 16);
				LAi_SetPlayerType(Pchar);
				}
				else AddQuestRecord("Poker_Tournament", 17);
			Preprocessor_Remove("date4");
		break;

				Preprocessor_AddQuestData("date", GetHumanDate(GetAddingDataYear(0, 6, 0), GetAddingDataMonth(0, 6, 0), GetAddingDataDay(0, 6, 0)));
		
				if (Pchar.quest.poker.winner  == "Blaze")
				{
				PlaySound("INTERFACE\coins8.wav");
				AddMoneyToCharacter(Pchar, 60000);
				AddQuestRecord("Poker_Tournament", 4);
				LAi_SetPlayerType(Pchar);
				}
				else AddQuestRecord("Poker_Tournament", 5);
		Preprocessor_Remove("date");
}	
		sld = &characters[GetCharacterIndex("Ron_L")];
		Characters[GetCharacterIndex("Ron_L")].dialog.CurrentNode  = "Day three presentation";
		LAi_SetActorType(sld);
		LAi_SetActorType(pchar);
		LAi_ActorTurnToLocator(Pchar,"goto","goto14");
		LAi_ActorDialog(sld, Pchar, "", 0, 0);
		GiveItem2Character(Pchar, "poker_invite2");//give poker_invite 
		LAi_SetPlayerType(Pchar);			
		LAi_SetPlayerType(characterFromID("Gambler 1"));
		LAi_SetPlayerType(characterFromID("Gambler 2"));
		LAi_SetPlayerType(characterFromID("Gambler 3"));
		RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
		EquipCharacterByItem(Pchar, Pchar.quest.poker.blade);//re equip sword
		DeleteAttribute(PChar,"quest.poker.started");//pw prevent wrong style game in tavern
		DeleteAttribute(PChar,"quest.poker.hands");
		DeleteAttribute(PChar,"quest.poker.blade");
		DisableFastTravel(false);
			
		
		break;
		
		
		case "Competition_Lockout"://timer set in this file
		Locations[FindLocation("Turks_poker_entre")].reload.l3.disable = true;
		DeleteAttribute(PChar,"quest.poker.started");//pw prevent wrong style game in tavern
		PChar.quest.poker.lockout = true;//set dialogue for bouncer
		AddQuestRecord("Poker_Tournament", 3);
		CloseQuestHeader("Poker_Tournament");
		DisableFastTravel(false);//make sure fast travel restored just in case it was blocked
		break;
		
		case "Competition_Lockout2"://from bouncer_dialog.c
		Locations[FindLocation("Turks_port")].reload.l19.disable = true;//final close entre after dialogue with bouncer
		
		break;
		
		case "Competition_Lockout3"://timer set in this file at 7 months from last tournament
		Locations[FindLocation("Turks_port")].reload.l19.disable = true;
		AddQuestRecord("Poker_Tournament", 7);
		CloseQuestHeader("Poker_Tournament");
		
		if (CheckCharacterItem(PChar,"poker_invite2"))TakeItemFromCharacter(pchar, "poker_invite2");
		if (CheckCharacterItem(PChar,"bladetrophy"))TakeItemFromCharacter(pchar, "bladetrophy");
		break;
		
		case "Competition_Reset_Stuff"://timer set in this file for next competition reset after 6 months
				
		
		DeleteAttribute(PChar,"quest.poker.day");
		DeleteAttribute(PChar,"quest.poker.result");
		DeleteAttribute(PChar,"quest.poker.hands");
		DeleteAttribute(PChar,"quest.poker.blade");
		
		ChangeCharacterAddressGroup(characterFromID("Reg_L"), "Turks_poker_entre", "goto", "goto8");
		Characters[GetCharacterIndex("Reg_L")].dialog.CurrentNode  = "First time";
		LAi_SetPlayerType(characterFromID("Reg_L"));
		
		if(PChar.sex == "man")
		{
		AddQuestRecord("Poker_Tournament", 6);
		}
		else
		{ 
		AddQuestRecord("Poker_Tournament", 9); 
		}	
		ChangeCharacterAddressGroup(characterFromID("Gambler 1"), "Turks_poker_room", "sit", "sit3");
		LAi_SetActorType(Characters[GetCharacterIndex("Gambler 1")]);
		LAi_SetSitType(characterFromID("Gambler 1"));
		LAi_SetPlayerType(Characters[GetCharacterIndex("Gambler 2")]);
		ChangeCharacterAddressGroup(characterFromID("Gambler 2"), "Turks_poker_room", "sit", "sit4");
		LAi_SetActorType(Characters[GetCharacterIndex("Gambler 2")]);
		LAi_SetSitType(characterFromID("Gambler 2"));
		LAi_SetPlayerType(Characters[GetCharacterIndex("Gambler 3")]);
		ChangeCharacterAddressGroup(characterFromID("Gambler 3"), "Turks_poker_room", "sit", "sit6");
		LAi_SetActorType(Characters[GetCharacterIndex("Gambler 3")]);
		LAi_SetSitType(characterFromID("Gambler 3"));
		LAi_SetPlayerType(Characters[GetCharacterIndex("Gambler 3")]);
		Characters[GetCharacterIndex("Ron_L")].dialog.CurrentNode  = "Ronnie speaks";
		LAi_SetPlayerType(characterFromID("Ron_L"));
					
		break;

///////////////////////////////////////////////////////////////
//    Agent: GR
///////////////////////////////////////////////////////////////

		case "AgentQuest_setup":	// Triggered by dialog with a governor
			sld = CharacterFromID("TQ_Captain1");
			sld.fantomtype = "war";
			sld.quest.officertype = OFFIC_TYPE_CAPNAVY;
			SetRandomNameToCharacter(sld);
			SetModelfromID(sld, Nations[sti(sld.nation)].fantomModel.m0);
			SetCharacterShipLocation(sld, PChar.quest.agentquest.port1);

			NPChar = CharacterFromID("TQ_Char1");
			SetModelfromID(NPChar, "Sailor15");
			NPChar.nation = PChar.quest.agentquest.enemy_nation;
			NPChar.Dialog.Filename = "Agent_docker_dialog.c";
			if (PChar.sex == "woman") NPChar.Dialog.CurrentNode = "help_you";
			else NPChar.Dialog.CurrentNode = "busy";
			SetRandomNameToCharacter(NPChar);
			LAi_SetStayType(NPChar);


			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, "9R_Carp", "reload", "reload1");
			sld.nation = GetServedNation();
			sld.Dialog.Filename = "Agent_soldier_dialog.c";
			sld.Dialog.CurrentNode = "Q_arrives";
			SetRandomNameToCharacter(sld);
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, PChar, "", 5.0, 5.0);

			switch(PChar.quest.agentquest.port1)
			{
				case "Tortuga_port":
           				Locations[FindLocation("Tortuga_port")].vcskip = true;
					PChar.quest.agentquest.docker_location.group = "officers";
					PChar.quest.agentquest.docker_location.locator = "reload1_1";
					PChar.quest.agentquest.docker_depart.locator = "reload4_back";
					PChar.quest.agentquest.ship.locator = "reload1_back";
					PChar.quest.agentquest.ship.reload_disable1 = "l1";
					PChar.quest.agentquest.ship.reload_disable2 = "l2";
				break;

				case "Cuba_port":
           				Locations[FindLocation("Cuba_port")].vcskip = true;
					PChar.quest.agentquest.docker_location.group = "goto";
					PChar.quest.agentquest.docker_location.locator = "goto_45";
					PChar.quest.agentquest.docker_depart.locator = "reload_2_city";
					PChar.quest.agentquest.ship.locator = "sea_1_back";
					PChar.quest.agentquest.ship.reload_disable1 = "l2";
					PChar.quest.agentquest.ship.reload_disable2 = "l3";
					PChar.quest.agentquest.ship.reload_disable3 = "l4";
					PChar.quest.agentquest.ship.reload_disable4 = "l5";
				break;

				case "Antigua_port":
					PChar.quest.agentquest.docker_location.group = "reload";
					PChar.quest.agentquest.docker_location.locator = "reload2_back";
					PChar.quest.agentquest.docker_depart.locator = "reload_2_city";
					PChar.quest.agentquest.ship.locator = "sea_2_back";
					PChar.quest.agentquest.ship.reload_disable1 = "l3";
					PChar.quest.agentquest.ship.reload_disable2 = "l5";
				break;

				case "Marigot_port":
					PChar.quest.agentquest.docker_location.group = "goto";
					PChar.quest.agentquest.docker_location.locator = "goto13";
					PChar.quest.agentquest.docker_depart.locator = "Falaise_de_fleur_location_01_02";
					PChar.quest.agentquest.ship.locator = "sea_back";
					PChar.quest.agentquest.ship.reload_disable1 = "l4";
					PChar.quest.agentquest.ship.reload_disable2 = "l5";
				break;

				case "Willemstad_port":
					PChar.quest.agentquest.docker_location.group = "goto";
					PChar.quest.agentquest.docker_location.locator = "goto13";
					PChar.quest.agentquest.docker_depart.locator = "Falaise_de_fleur_location_01_02";
					PChar.quest.agentquest.ship.locator = "sea_back";
					PChar.quest.agentquest.ship.reload_disable1 = "l3";
					PChar.quest.agentquest.ship.reload_disable2 = "l5";
				break;

				case "REDMOND_PORT":
					PChar.quest.agentquest.docker_location.group = "goto";
					PChar.quest.agentquest.docker_location.locator = "goto_33";
					PChar.quest.agentquest.docker_depart.locator = "reload_2_city";
					PChar.quest.agentquest.ship.locator = "sea_2_back";
					PChar.quest.agentquest.ship.reload_disable1 = "l2";
					PChar.quest.agentquest.ship.reload_disable2 = "l3";
					PChar.quest.agentquest.ship.reload_disable3 = "l4";
					PChar.quest.agentquest.ship.reload_disable4 = "l5";
				break;

				case "Eleuthera_Port":
					PChar.quest.agentquest.docker_location.group = "goto";
					PChar.quest.agentquest.docker_location.locator = "goto8";
					PChar.quest.agentquest.docker_depart.locator = "reload4_back";
					PChar.quest.agentquest.ship.locator = "reload1_back";
					PChar.quest.agentquest.ship.reload_disable1 = "l1";
					PChar.quest.agentquest.ship.reload_disable2 = "l2";
				break;

				case "QC_port":
					PChar.quest.agentquest.docker_location.group = "officers";
					PChar.quest.agentquest.docker_location.locator = "reload2_1";
					PChar.quest.agentquest.docker_depart.locator = "reload3_back";
					PChar.quest.agentquest.ship.locator = "reload2";
					PChar.quest.agentquest.ship.reload_disable1 = "l2";
					PChar.quest.agentquest.ship.reload_disable2 = "l3";
				break;

				case "Muelle_port":
					PChar.quest.agentquest.docker_location.group = "goto";
					PChar.quest.agentquest.docker_location.locator = "goto7";
					PChar.quest.agentquest.docker_depart.locator = "reload2";
					PChar.quest.agentquest.ship.locator = "reload1_back";
					PChar.quest.agentquest.ship.reload_disable1 = "l2";
					PChar.quest.agentquest.ship.reload_disable2 = "l3";
					PChar.quest.agentquest.ship.reload_disable3 = "l4";
					PChar.quest.agentquest.ship.reload_disable4 = "l5";
				break;
			}
			if (CheckAttribute(PChar, "quest.agentquest.docker_location.locator"))
			{
				ChangeCharacterAddressGroup(NPChar, PChar.quest.agentquest.port1, PChar.quest.agentquest.docker_location.group, PChar.quest.agentquest.docker_location.locator);
			}

			PChar.quest.AgentQuest_dismiss_ship.win_condition.l1 = "location";
			PChar.quest.AgentQuest_dismiss_ship.win_condition.l1.location = PChar.quest.agentquest.port1;
			PChar.quest.AgentQuest_dismiss_ship.win_condition = "AgentQuest_dismiss_ship";
			LAi_SetLoginTime(CharacterFromID("TQ_Char1"), 0.0, 24.0);
			LAi_SetLoginTime(CharacterFromID("TQ_Char2"), 0.0, 24.0);

			Preprocessor_AddQuestData("ship", PChar.quest.agentquest.enemy_ship.name);
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID(PChar.quest.agentquest.governor)));
			Preprocessor_AddQuestData("town", FindTownName(PChar.quest.agentquest.original_town));
			Preprocessor_AddQuestData("island", FindIslandName(GetIslandIDFromTown(PChar.quest.agentquest.original_town)));
			Preprocessor_AddQuestData("nation", XI_ConvertString(GetNationDescByType(sti(PChar.quest.agentquest.enemy_nation))));
			Preprocessor_AddQuestData("port1", FindTownName(PChar.quest.agentquest.town1));
			Preprocessor_AddQuestData("island1", FindIslandName(GetIslandIDFromTown(PChar.quest.agentquest.town1)));
			SetQuestHeader("Agent_Quest");
			AddQuestRecord("Agent_Quest", 1);
			Preprocessor_Remove("island1");
			Preprocessor_Remove("port1");
			Preprocessor_Remove("nation");
			Preprocessor_Remove("island");
			Preprocessor_Remove("town");
			Preprocessor_Remove("governor");
			Preprocessor_Remove("ship");
		break;

		case "AgentQuest_dismiss_ship":
			cidx = -1;
			for (i=OFFICER_MAX-1; i>0; i--)
			{
				if(GetOfficersIndex(PChar, i) != -1)
				{
					cidx = GetOfficersIndex(PChar, i);
				}
			}
			if (cidx == -1)
			{
				cidx = GetCharacterIndex("TQ_Char2");
				NPChar = GetCharacter(cidx);
				SetModelfromID(NPChar, "pirat2");
				NPChar.nation = GetServedNation();
				SetRandomNameToCharacter(NPChar);
				PlaceCharacter(NPChar, "officers");
			}
			else
			{
				NPChar = GetCharacter(cidx);
				StoreDialog(NPChar);
			}
			PChar.quest.agentquest.dismisser = NPChar.id;
			NPChar.Dialog.Filename = "Agent_crewman_dialog.c";
			NPChar.Dialog.CurrentNode = "dismiss_ship";
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(PChar, NPChar);
			LAi_SetActorType(NPChar);
			LAi_ActorDialog(NPChar, PChar, "AgentQuest_dismiss_ship2", 10.0, 10.0);
		break;

		case "AgentQuest_dismiss_ship2":
			NPChar = CharacterFromID(PChar.quest.agentquest.dismisser);
			if (PChar.quest.agentquest.dismisser != "TQ_Char2")
			{
				RestoreDialog(NPChar);
			}
			else NPChar.location = "none";
			LAi_SetOfficerType(NPChar);
			LAi_SetPlayerType(PChar);

			Preprocessor_AddQuestData("locationfromsea", FindTownName(PChar.quest.agentquest.original_town));
			Preprocessor_AddQuestData("ship", PChar.quest.agentquest.enemy_ship.name);
			AddQuestRecord("Agent_Quest", 2);
			Preprocessor_Remove("ship");
			Preprocessor_Remove("locationfromsea");
		break;

		case "AgentQuest_ready_to_board":	// Triggered by dialog with "TQ_Char1"
			NPChar = CharacterFromID("TQ_Char1");
			if (PChar.sex == "woman")
			{
				LAi_SetStayType(NPChar);
			}
			else
			{
				LAi_SetActorType(NPChar);
				LAi_ActorGoToLocation(NPChar, "reload", PChar.quest.agentquest.docker_depart.locator, "none", "", "", "", -1);
			}
			NPChar.location = "none";

			DisableFastTravel(true);
			bQuestDisableSeaEnter = true;
			for (i=1; i<=4; i++)
			{
				if (CheckAttribute(PChar, "quest.agentquest.ship.reload_disable"+i))
				{
					attr = GetAttribute(PChar, "quest.agentquest.ship.reload_disable"+i);
					Locations[FindLocation(PChar.location)].reload.(attr).disable = 1;
				}
			}
			if (PChar.location == "Tortuga_port" || PChar.location == "Cuba_port")
			{
				DeleteAttribute(&Locations[FindLocation(PChar.location)],"vcskip");
			}
			PChar.quest.AgentQuest_board_ship.win_condition.l1 = "locator";
			PChar.quest.AgentQuest_board_ship.win_condition.l1.location = PChar.location;
			PChar.quest.AgentQuest_board_ship.win_condition.l1.locator_group = "reload";
			PChar.quest.AgentQuest_board_ship.win_condition.l1.locator = PChar.quest.agentquest.ship.locator;
			PChar.quest.AgentQuest_board_ship.win_condition = "AgentQuest_board_ship";
		break;

		case "AgentQuest_board_ship":
			sld = CharacterFromID("TQ_Soldier1");
			sld.nation = PChar.quest.agentquest.enemy_nation;
			SetRandomNameToCharacter(sld);
			SetModelfromID(sld, Nations[sti(sld.nation)].fantomModel.m2);
			sld.Dialog.Filename = "Agent_soldier_dialog.c";
			sld = CharacterFromID("TQ_Soldier2");
			sld.nation = PChar.quest.agentquest.enemy_nation;
			SetRandomNameToCharacter(sld);
			SetModelfromID(sld, Nations[sti(sld.nation)].fantomModel.m4);
			sld.Dialog.Filename = "Agent_soldier_dialog.c";
			DoQuestReloadToLocation(GetCharacterShipQDeck(CharacterFromID("TQ_Captain1")), "goto", "goto4", "AgentQuest_board_ship2");
		break;

		case "AgentQuest_board_ship2":
			for (i=1; i<=4; i++)
			{
				if (CheckAttribute(PChar, "quest.agentquest.ship.reload_disable"+i))
				{
					attr = GetAttribute(PChar, "quest.agentquest.ship.reload_disable"+i);
					Locations[FindLocation(PChar.location)].reload.(attr).disable = 0;
				}
			}

			StorePassengers(PChar.id);
			for (i=1; i<COMPANION_MAX; i++)
			{
				cc = GetCompanionIndex(PChar,i);
				attr = "companion" + i;
				if (cc > 0)
				{
					PChar.quest.AgentQuest.(attr) = characters[cc].id;
					if (HasSubStr(PChar.quest.AgentQuest.(attr), "Enc_Officer")) LAi_StoreFantom(CharacterFromId(PChar.quest.AgentQuest.(attr))); // Prevent character from being overwritten by another "Enc_Officer"
					RemoveCharacterCompanion(PChar, Characters[cc]);
				}
				else PChar.quest.AgentQuest.(attr) = "*NULL*";
			}
			ExchangeCharacterShip(PChar, CharacterFromID("TQ_Char1"));	// Store player's ship by giving it to a generic quest character
			GiveShip2Character(PChar, PChar.quest.agentquest.enemy_ship.type, PChar.quest.agentquest.enemy_ship.name, -1, sti(PChar.quest.agentquest.enemy_nation), true, true);
			PChar.isnotcaptain = true;

			PlaceCharacter(CharacterFromID("TQ_Soldier1"), "goto");
			PlaceCharacter(CharacterFromID("TQ_Soldier2"), "goto");
			LAi_SetActorType(CharacterFromID("TQ_Soldier1"));
			LAi_SetActorType(CharacterFromID("TQ_Soldier2"));
			LAi_ActorTurnToCharacter(CharacterFromID("TQ_Soldier1"), PChar);
			LAi_ActorTurnToCharacter(CharacterFromID("TQ_Soldier2"), PChar);
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("TQ_Soldier1"));
			Characters[GetCharacterIndex("TQ_Soldier1")].dialog.currentnode = "challenge";
			LAi_ActorWaitDialog(PChar, CharacterFromID("TQ_Soldier1"));
			LAi_ActorDialog(CharacterFromID("TQ_Soldier1"), PChar, "AgentQuest_to_hold", 10.0, 10.0);
		break;

		case "AgentQuest_to_hold":
			LAi_SetPlayerType(PChar);
			Locations[FindLocation("Quest_Hold1")].reload.l1.disable = 1;				// Lock link from hold to deck
			Locations[FindLocation("Quest_Hold1")].models.always.locators = "hold_l_GR_agent";
			DoQuestReloadToLocation("Quest_Hold1", "reload", "reload1", "AgentQuest_to_hold2");
		break;

		case "AgentQuest_to_hold2":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "goto", "goto1");
			LAi_QuestDelay("AgentQuest_to_hold3", 0.5);
		break;

		case "AgentQuest_to_hold3":
			LAi_SetActorType(PChar);
			Pchar.dialog.CurrentNode = "Agent_hide_in_hold";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "AgentQuest_hide_in_hold":	// Triggered by self dialog
			Pchar.quest.AgentQuest_hide_in_hold2.win_condition.l1 = "locator";
			Pchar.quest.AgentQuest_hide_in_hold2.win_condition.l1.location = "Quest_Hold1";
			Pchar.quest.AgentQuest_hide_in_hold2.win_condition.l1.locator_group = "box";
			Pchar.quest.AgentQuest_hide_in_hold2.win_condition.l1.locator = "box1";
			Pchar.quest.AgentQuest_hide_in_hold2.win_condition = "AgentQuest_hide_in_hold2";
		break;

		case "AgentQuest_hide_in_hold2":
			DoQuestReloadToLocation("Quest_Hold1", "goto", "goto1", "AgentQuest_guard_searches_hold");
		break;

		case "AgentQuest_guard_searches_hold":
			Preprocessor_AddQuestData("ship", PChar.quest.agentquest.enemy_ship.name);
			AddQuestRecord("Agent_Quest", 3);
			Preprocessor_Remove("ship");
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(PChar);
			LAi_QuestDelay("AgentQuest_guard_searches_hold2", 2.0);
		break;

		case "AgentQuest_guard_searches_hold2":
			sld = CharacterFromID("TQ_Soldier1");
			ChangeCharacterAddressGroup(sld, "Quest_Hold1", "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "rld", "loc2", "AgentQuest_guard_searches_hold2a", 3.0);
		break;

		case "AgentQuest_guard_searches_hold2a":
			sld = CharacterFromID("TQ_Soldier1");
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto1");
			LAi_ActorAnimation(sld, "idle_6", "AgentQuest_guard_searches_hold_check", -1.0);
		break;

		case "AgentQuest_guard_searches_hold_check":
			sld = CharacterFromID("TQ_Soldier1");
			LAi_SetActorType(sld);
			if (CalcCharacterSkill(PChar, "sneak") >= (rand(5) + rand(5))) LAi_QuestDelay("AgentQuest_guard_searches_hold3", 0.0);
			else LAi_QuestDelay("AgentQuest_guard_sees_you", 0.0);
//LAi_QuestDelay("AgentQuest_guard_searches_hold3", 0.0);	// Unconditional continued search, for testing
//LAi_QuestDelay("AgentQuest_guard_sees_you", 0.0);	// Unconditional challenge, for testing
		break;

		case "AgentQuest_guard_searches_hold3":
			LAi_ActorGoToLocator(CharacterFromID("TQ_Soldier1"), "rld", "aloc2", "AgentQuest_guard_searches_hold3a", 3.0);
		break;

		case "AgentQuest_guard_searches_hold3a":
			sld = CharacterFromID("TQ_Soldier1");
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "box", "gunpowder_1");
			LAi_ActorAnimation(sld, "idle_4", "AgentQuest_guard_searches_hold4", -1.0);
		break;

		case "AgentQuest_guard_searches_hold4":
			LAi_ActorGoToLocator(CharacterFromID("TQ_Soldier1"), "rld", "loc1", "AgentQuest_guard_searches_hold4a", 3.0);
		break;

		case "AgentQuest_guard_searches_hold4a":
			sld = CharacterFromID("TQ_Soldier1");
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "reload", "reload2");
			LAi_ActorAnimation(sld, "idle_5", "AgentQuest_guard_leaves_hold", -1.0);
		break;

		case "AgentQuest_guard_leaves_hold":
			AddQuestRecord("Agent_Quest", 5);
			sld = CharacterFromID("TQ_Soldier1");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "",0.0);
			LAi_QuestDelay("AgentQuest_wait_till_arrived", 0.0);
		break;

		case "AgentQuest_guard_sees_you":
			sld = CharacterFromID("TQ_Soldier1");
			LAi_SetActorType(sld);
			sld.dialog.currentnode = "discovered";
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialog(sld, PChar, "AgentQuest_fight_in_hold", 10.0, 10.0);
		break;

		case "AgentQuest_fight_in_hold":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(PChar, "Quest_Hold1", "goto", "goto2");
			sld = CharacterFromID("TQ_Soldier1");
			LAi_group_MoveCharacter(sld, "HOLD_SOLDIERS");
			LAi_group_FightGroups("HOLD_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("HOLD_SOLDIERS", "AgentQuest_hold_fight_over");
		break;

		case "AgentQuest_hold_fight_over":
			LAi_SetActorType(PChar);
			Pchar.dialog.CurrentNode = "Agent_dispose_of_body";
			LAi_ActorSelfDialog(PChar, "player_back");
		break;

		case "AgentQuest_hide_body":		// Triggered by self dialog
			ChangeCharacterAddress(CharacterFromID("TQ_Soldier1"), "None", "");
			DoQuestReloadToLocation("Quest_Hold1", "goto", "goto2", "AgentQuest_body_hidden");
		break;

		case "AgentQuest_body_hidden":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "goto", "goto1");
			Pchar.dialog.CurrentNode = "Agent_body_hidden";
			LAi_ActorSelfDialog(PChar, "AgentQuest_back_to_hiding");
		break;

		case "AgentQuest_back_to_hiding":
			AddQuestRecord("Agent_Quest", 4);
			DoQuestReloadToLocation("Quest_Hold1", "goto", "goto1", "AgentQuest_back_to_hiding2");
		break;

		case "AgentQuest_back_to_hiding2":
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(PChar);
			LAi_QuestDelay("AgentQuest_wait_till_arrived", 0.0);
		break;

		case "AgentQuest_wait_till_arrived":
//			AddDataToCurrent(0, 0, 10 + rand(5), false);
			WaitDate("", 0, 0, 10 + rand(5), 0, 0);
			LAi_Fade("AgentQuest_ship_arrives", "AgentQuest_player_stands_up");
		break;

		case "AgentQuest_ship_arrives":
			SetCharacterShipLocation(CharacterFromID("TQ_Captain1"), PChar.quest.agentquest.port2);

			Pchar.quest.AgentQuest_back_to_deck.win_condition.l1 = "locator";
			Pchar.quest.AgentQuest_back_to_deck.win_condition.l1.location = "Quest_Hold1";
			Pchar.quest.AgentQuest_back_to_deck.win_condition.l1.locator_group = "reload";
			Pchar.quest.AgentQuest_back_to_deck.win_condition.l1.locator = "reload1";
			Pchar.quest.AgentQuest_back_to_deck.win_condition = "AgentQuest_back_to_deck";

			if (PChar.sex == "man") LAi_QuestDelay("AgentQuest_docker_in_hold", 10.0);
		break;

		case "AgentQuest_player_stands_up":
			AddQuestRecord("Agent_Quest", 6);
			LAi_SetPlayerType(PChar);
			DoQuestReloadToLocation("Quest_Hold1", "goto", "goto2", "_");
		break;

		case "AgentQuest_docker_in_hold":
			if (PChar.location == "Quest_Hold1")
			{
				PChar.quest.agentquest.leave_with_docker = true;
				NPChar = CharacterFromID("TQ_Char2");
				SetModelfromID(NPChar, "Sailor10");
				NPChar.nation = PChar.quest.agentquest.enemy_nation;
				SetRandomNameToCharacter(NPChar);
				ChangeCharacterAddressGroup(NPChar, "Quest_Hold1", "reload", "reload1");
				LAi_SetActorType(PChar);
				LAi_ActorWaitDialog(PChar, NPChar);
				LAi_SetActorType(NPChar);
				NPChar.Dialog.Filename = "Agent_docker_dialog.c";
				NPChar.Dialog.CurrentNode = "not_expecting_anyone";
				LAi_ActorDialog(NPChar, PChar, "AgentQuest_back_to_deck", 10.0, 10.0);
			}
		break;

		case "AgentQuest_back_to_deck":
			DoQuestReloadToLocation(GetCharacterShipQDeck(CharacterFromID("TQ_Captain1")), "reload", "reload3", "AgentQuest_back_to_deck2");
		break;

		case "AgentQuest_to_deck_with_docker":
			ChangeCharacterAddressGroup(CharacterFromID("TQ_Char2"), GetCharacterShipQDeck(CharacterFromID("TQ_Captain1")), "goto", "goto2");
			DoQuestReloadToLocation(GetCharacterShipQDeck(CharacterFromID("TQ_Captain1")), "reload", "reload3", "AgentQuest_back_to_deck2");
		break;

		case "AgentQuest_back_to_deck2":
			DeleteAttribute(PChar, "Ship");
			PChar.Ship.Type = SHIP_NOTUSED_TYPE_NAME;
			PChar.Ship.Name = "";

			if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
			{
				NPChar = CharacterFromID("TQ_Char2");
				ChangeCharacterAddressGroup(NPChar, GetCharacterShipQDeck(CharacterFromID("TQ_Captain1")), "goto", "goto2");
				LAi_SetActorType(NPChar);
				LAi_ActorFollowEverywhere(NPChar, "", 10.0);
			}
			Locations[FindLocation("Quest_Hold1")].reload.l1.disable = 0;				// Unlock link from hold to deck
			Locations[FindLocation("Quest_Hold1")].models.always.locators = "hold_ld";		// Hold locators back to normal
			StartQuestMovie(true, false, false);
			TrackQuestMovie("start","AgentQuest_back_to_deck2");
			ChangeCharacterAddressGroup(CharacterFromID("TQ_Soldier2"), GetCharacterShipQDeck(CharacterFromID("TQ_Captain1")), "goto", "goto4");
			PlaceCharacter(CharacterFromID("TQ_Soldier1"), "goto");
			LAi_SetActorType(CharacterFromID("TQ_Soldier1"));
			LAi_SetActorType(CharacterFromID("TQ_Soldier2"));
			LAi_ActorTurnToCharacter(CharacterFromID("TQ_Soldier1"), PChar);
			LAi_ActorTurnToCharacter(CharacterFromID("TQ_Soldier2"), PChar);
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("TQ_Soldier2"));
			Characters[GetCharacterIndex("TQ_Soldier2")].dialog.currentnode = "second_challenge";
			LAi_ActorWaitDialog(PChar, CharacterFromID("TQ_Soldier2"));
			LAi_ActorDialog(CharacterFromID("TQ_Soldier2"), PChar, "", 10.0, 10.0);			// Exits to "AgentQuest_deck_fight" or "AgentQuest_leave_ship"

			PChar.quest.AgentQuest_got_ship.win_condition.l1 = "ship_class";
			PChar.quest.AgentQuest_got_ship.win_condition.l1.operation = ">=";
			PChar.quest.AgentQuest_got_ship.win_condition.l1.class = "1";
			PChar.quest.AgentQuest_got_ship.win_condition = "AgentQuest_got_ship";
		break;

		case "AgentQuest_got_ship":
			if (!CheckQuestAttribute("agentquest", "smuggler_ship"))
			{
				bQuestDisableSeaEnter = false;
				SetCharacterShipLocation(PChar, PChar.quest.agentquest.port2);
				PChar.location.from_sea = PChar.quest.agentquest.port2;
				SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar");
				DeleteAttribute(PChar, "isnotcaptain");
			}
		break;

		case "AgentQuest_deck_fight":
			LAi_SetPlayerType(PChar);
			LAi_group_MoveCharacter(CharacterFromID("TQ_Soldier1"), "HOLD_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("TQ_Soldier2"), "HOLD_SOLDIERS");
			LAi_group_FightGroups("HOLD_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("HOLD_SOLDIERS", "AgentQuest_leave_ship");
		break;

		case "AgentQuest_leave_ship":
			EndQuestMovie();TrackQuestMovie("end","AgentQuest_leave_ship");
			LAi_SetPlayerType(PChar);
			switch(PChar.quest.agentquest.port2)
			{
				case "QC_port":
					PChar.quest.agentquest.docker_location.group = "officers";
					PChar.quest.agentquest.docker_location.locator = "reload1_1";
					PChar.quest.agentquest.docker_depart.locator = "reload3_back";
					PChar.quest.agentquest.ship.locator = "reload1";
					if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
					{
						Build_at("QC_port", "box", "", -2.2, 2.2, 6.7, 0.3, "HOLD_SOLDIERS")
					}
					PChar.quest.agentquest.soldier1.id = "TQ_Soldier3";
					PChar.quest.agentquest.soldier2.id = "TQ_Soldier4";
					PChar.quest.agentquest.soldier1.location = "QC_town";
					PChar.quest.agentquest.soldier1.group = "officers";
					PChar.quest.agentquest.soldier1.locator = "reload10_1";
					PChar.quest.agentquest.soldier2.location = "QC_town";
					PChar.quest.agentquest.soldier2.group = "officers";
					PChar.quest.agentquest.soldier2.locator = "reload10_2";
					for(i = 3; i<=4; i++)
					{
						sld = CharacterFromID("TQ_Soldier" + i);
						sld.nation = PIRATE;
						SetRandomNameToCharacter(sld);
						attr = "m" + (rand(5)+1);
						SetModelfromID(sld, Nations[PIRATE].fantomModel.(attr));
						sld.Dialog.Filename = "Agent_soldier_dialog.c";
						sld.Dialog.CurrentNode = "pirate_guard";
						GiveSoldierWeapon(sld, PIRATE);
						LAi_group_MoveCharacter(sld, "QC_SOLDIERS");
						ChangeCharacterAddressGroup(sld, "QC_town", "officers", "reload10_"+(i-2));
					}
					PChar.quest.agentquest.residence.district = "QC_town";
					PChar.quest.agentquest.residence.entrance = "reload10";
					PChar.quest.agentquest.residence.inside = "QC_Residence";
					PChar.quest.agentquest.target = "box1";
				break;

				case "Muelle_port":
					PChar.quest.agentquest.docker_location.group = "officers";
					PChar.quest.agentquest.docker_location.locator = "reload3_1";
					PChar.quest.agentquest.docker_depart.locator = "reload2";
					PChar.quest.agentquest.ship.locator = "reload3_back";
					if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
					{
						Build_at("Muelle_port", "box", "", -7.0, 3.5, -14.8, 0.3, "HOLD_SOLDIERS")
					}
					PChar.quest.agentquest.soldier1.id = "spain_soldier_07";
					PChar.quest.agentquest.soldier2.id = "spain_soldier_08";
					PChar.quest.agentquest.soldier1.location = "Muelle_town_04";
					PChar.quest.agentquest.soldier1.group = "goto";
					PChar.quest.agentquest.soldier1.locator = "goto1";
					PChar.quest.agentquest.soldier2.location = "Muelle_town_04";
					PChar.quest.agentquest.soldier2.group = "goto";
					PChar.quest.agentquest.soldier2.locator = "goto40";
					PChar.quest.agentquest.residence.district = "Muelle_town_04";
					PChar.quest.agentquest.residence.entrance = "reload5";
					PChar.quest.agentquest.residence.inside = "Muelle_Residence";
					PChar.quest.agentquest.target = "box1";
				break;

				case "REDMOND_PORT":
					PChar.quest.agentquest.docker_location.group = "officers";
					PChar.quest.agentquest.docker_location.locator = "sea_1_1";
					PChar.quest.agentquest.docker_depart.locator = "reload_2_city";
					PChar.quest.agentquest.ship.locator = "sea_1_back";
					if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
					{
						Build_at("REDMOND_PORT", "box", "", 65.46, 5.07, -56.47, 0.3, "HOLD_SOLDIERS")
					}
					PChar.quest.agentquest.soldier1.id = "Eng_Soldier_5";
					PChar.quest.agentquest.soldier2.id = "Eng_Soldier_6";
					PChar.quest.agentquest.soldier3.id = "Eng_soldier_31";
					PChar.quest.agentquest.soldier4.id = "Eng_soldier_32";
					PChar.quest.agentquest.soldier1.location = "Redmond_town_01";
					PChar.quest.agentquest.soldier1.group = "goto";
					PChar.quest.agentquest.soldier1.locator = "soldier1";
					PChar.quest.agentquest.soldier2.location = "Redmond_town_01";
					PChar.quest.agentquest.soldier2.group = "goto";
					PChar.quest.agentquest.soldier2.locator = "soldier2";
					PChar.quest.agentquest.soldier3.location = "Redmond_town_01";
					PChar.quest.agentquest.soldier3.group = "goto";
					PChar.quest.agentquest.soldier3.locator = "goto11";
					PChar.quest.agentquest.soldier4.location = "Redmond_town_01";
					PChar.quest.agentquest.soldier4.group = "goto";
					PChar.quest.agentquest.soldier4.locator = "goto25";
					PChar.quest.agentquest.residence.district = "Redmond_Town_01";
					PChar.quest.agentquest.residence.entrance = "door_5";
					PChar.quest.agentquest.residence.inside = "Redmond_residence";
					PChar.quest.agentquest.target = "box1";
				break;

				case "PoPrince_Port":
					PChar.quest.agentquest.docker_location.group = "officers";
					PChar.quest.agentquest.docker_location.locator = "reload2_1";
					PChar.quest.agentquest.docker_depart.locator = "reload1";
					PChar.quest.agentquest.ship.locator = "reload2_back";
					if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
					{
						Build_at("PoPrince_Port", "box", "", -7.85, 3.61, 76.46, 0.3, "HOLD_SOLDIERS")
					}
					PChar.quest.agentquest.soldier1.id = "PoPrince_soldier_06";
					PChar.quest.agentquest.soldier1.location = "PoPrince_town";
					PChar.quest.agentquest.soldier1.group = "goto";
					PChar.quest.agentquest.soldier1.locator = "goto22";
					PChar.quest.agentquest.residence.district = "PoPrince_town";
					PChar.quest.agentquest.residence.entrance = "reload14";
					PChar.quest.agentquest.residence.inside = "PoPrince_townhall";
					PChar.quest.agentquest.target = "box1";
				break;

				case "Douwesen_port":
					PChar.quest.agentquest.docker_location.group = "officers";
					PChar.quest.agentquest.docker_location.locator = "reload2_1";
					PChar.quest.agentquest.docker_depart.locator = "reload3";
					PChar.quest.agentquest.ship.locator = "reload2_back";
					if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
					{
						Build_at("Douwesen_port", "box", "", 33.68, 3.65, -71.3, 0.3, "HOLD_SOLDIERS")
					}
					PChar.quest.agentquest.soldier1.id = "Dou_soldier_5";
					PChar.quest.agentquest.soldier2.id = "Dou_soldier_6";
					PChar.quest.agentquest.soldier1.location = "Douwesen_town";
					PChar.quest.agentquest.soldier1.group = "goto";
					PChar.quest.agentquest.soldier1.locator = "goto28";
					PChar.quest.agentquest.soldier2.location = "Douwesen_town";
					PChar.quest.agentquest.soldier2.group = "goto";
					PChar.quest.agentquest.soldier2.locator = "goto29";
					PChar.quest.agentquest.residence.district = "Douwesen_town";
					PChar.quest.agentquest.residence.entrance = "reload15";
					PChar.quest.agentquest.residence.inside = "Douwesen_townhall";
					PChar.quest.agentquest.target = "box1";
				break;

				case "Conceicao_port":
					PChar.quest.agentquest.docker_location.group = "officers";
					PChar.quest.agentquest.docker_location.locator = "reload2_1";
					PChar.quest.agentquest.docker_depart.locator = "reload1";
					PChar.quest.agentquest.ship.locator = "reload2_back";
					if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
					{
						Build_at("Conceicao_port", "box", "", -7.85, 3.61, 76.46, 0.3, "HOLD_SOLDIERS")
					}
					PChar.quest.agentquest.soldier1.id = "Con_soldier_5";
					PChar.quest.agentquest.soldier2.id = "Con_soldier_6";
					PChar.quest.agentquest.soldier1.location = "Conceicao_town";
					PChar.quest.agentquest.soldier1.group = "goto";
					PChar.quest.agentquest.soldier1.locator = "goto21";
					PChar.quest.agentquest.soldier2.location = "Conceicao_town";
					PChar.quest.agentquest.soldier2.group = "goto";
					PChar.quest.agentquest.soldier2.locator = "goto22";
					PChar.quest.agentquest.residence.district = "Conceicao_town";
					PChar.quest.agentquest.residence.entrance = "reload14";
					PChar.quest.agentquest.residence.inside = "Conceicao_townhall";
					PChar.quest.agentquest.target = "box1";
				break;

				case "Alice_Port":
					PChar.quest.agentquest.docker_location.group = "officers";
					PChar.quest.agentquest.docker_location.locator = "reload61_1";
					PChar.quest.agentquest.docker_depart.locator = "reload4_back";
					PChar.quest.agentquest.ship.locator = "reload61";
					if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
					{
						Build_at("Alice_Port", "box", "", 1.5, 0.87, 25.5, 0.3, "HOLD_SOLDIERS")
					}
					PChar.quest.agentquest.soldier1.id = "Al_soldier_19";
					PChar.quest.agentquest.soldier2.id = "Al_soldier_443";
					PChar.quest.agentquest.soldier1.location = "Alice_Port";
					PChar.quest.agentquest.soldier1.group = "soldiers";
					PChar.quest.agentquest.soldier1.locator = "soldier1";
					PChar.quest.agentquest.soldier2.location = "Alice_Port";
					PChar.quest.agentquest.soldier2.group = "soldiers";
					PChar.quest.agentquest.soldier2.locator = "soldier2";
					PChar.quest.agentquest.residence.district = "Alice_Port";
					PChar.quest.agentquest.residence.entrance = "reload3_back";
					PChar.quest.agentquest.residence.inside = "Alice_townhall";
				break;
			}
			DoQuestReloadToLocation(PChar.quest.agentquest.port2, "reload", PChar.quest.agentquest.ship.locator, "AgentQuest_prepare_find_plans");
		break;

		case "AgentQuest_prepare_find_plans":
			Preprocessor_AddQuestData("ship", PChar.quest.agentquest.enemy_ship.name);
			Preprocessor_AddQuestData("town", FindTownName(GetCurrentTownID()));
			if (PChar.quest.agentquest.port2 == "QC_port") AddQuestRecord("Agent_Quest", 8);
			else AddQuestRecord("Agent_Quest", 7);
			Preprocessor_Remove("town");
			Preprocessor_Remove("ship");
			DisableFastTravel(false);
			if (CheckAttribute(PChar, "quest.agentquest.leave_with_docker"))
			{
				NPChar = CharacterFromID("TQ_Char2");
				ChangeCharacterAddressGroup(NPChar, PChar.quest.agentquest.port2, PChar.quest.agentquest.docker_location.group, PChar.quest.agentquest.docker_location.locator);
				LAi_SetActorType(NPChar);
				LAi_type_Actor_Reset(NPChar);
				NPChar.Dialog.CurrentNode = "job_done";
				LAi_ActorDialog(NPChar, PChar, "", 10.0, 10.0);
				cc = FindLocation(PChar.quest.agentquest.port2);
				for(i = 1; i<=MAXBUILDINGS; i++)
				{
					attr = "building."+i+".aigroup"
					if (CheckAttribute(Locations[cc],attr) && Locations[cc].(attr) == "HOLD_SOLDIERS")
					{
						DeleteAttribute(&Locations[cc], "building." + i);	// Function "Building_delete" fails to remove the crate
					}
				}
			}
			LAi_group_SetLookRadius(GetCurrentSoldierGroup(), LAI_GROUP_GRD_LOOK/2);
			LAi_group_SetHearRadius(GetCurrentSoldierGroup(), LAI_GROUP_GRD_HEAR/2);
			LAi_group_SetSayRadius(GetCurrentSoldierGroup(), LAI_GROUP_GRD_SAY);

			PChar.quest.AgentQuest_breakin.win_condition.l1 = "Time";			// To break into the residence requires:
			PChar.quest.AgentQuest_breakin.win_condition.l1.time = DAY_TIME_NIGHT;		// night-time,
			PChar.quest.AgentQuest_breakin.win_condition.l2 = "item";			// you have a lockpick,
			PChar.quest.AgentQuest_breakin.win_condition.l2.character = PChar.id;
			PChar.quest.AgentQuest_breakin.win_condition.l2.item = "lockpick";
			PChar.quest.AgentQuest_breakin.win_condition.l3 = "locator";			// and you're standing at the door.
			PChar.quest.AgentQuest_breakin.win_condition.l3.location = PChar.quest.agentquest.residence.district;
			PChar.quest.AgentQuest_breakin.win_condition.l3.locator_group = "reload";
			PChar.quest.AgentQuest_breakin.win_condition.l3.locator = PChar.quest.agentquest.residence.entrance;
			for(i=1; i<=4; i++)								// And any nearby guards must be dead.
			{
				if (CheckAttribute(PChar, "quest.agentquest.soldier" + i))
				{
					level = "l" + (i+3);
					attr = GetAttribute(PChar, "quest.agentquest.soldier" + i + ".id");
					PChar.quest.AgentQuest_breakin.win_condition.(level) = "NPC_Death";
					PChar.quest.AgentQuest_breakin.win_condition.(level).character = attr;
				}
			}
			PChar.quest.AgentQuest_breakin.win_condition = "AgentQuest_breakin";
		break;

		case "AgentQuest_docker2_leaves":
			PChar.quest.AgentQuest_back_to_deck.over = "yes";
			NPChar = CharacterFromID("TQ_Char2");
			LAi_SetActorType(NPChar);
			LAi_ActorGoToLocation(NPChar, "reload", PChar.quest.agentquest.docker_depart.locator, "none", "", "", "", -1);
			NPChar.location = "none";
		break;

		case "AgentQuest_breakin":
			PlaySound("PEOPLE\lockpick2.wav");
			LAi_QuestDelay("AgentQuest_breakin2", 2.0);
			NPChar = CharacterFromID(GetTownGovernorID(GetCurrentTownID()));
			NPChar.location = "none";
			if (PChar.quest.agentquest.residence.inside == "PoPrince_townhall") LAi_SetLoginTime(CharacterFromID("Contre-Amirale"), 6.0, 21.99);
			if (PChar.quest.agentquest.residence.inside == "Muelle_Residence") LAi_SetLoginTime(CharacterFromID("Joaquin Da Saldanha"), 6.0, 21.99);
		break;

		case "AgentQuest_breakin2":
			DoQuestReloadToLocation(PChar.quest.agentquest.residence.inside, "reload", "reload1", "AgentQuest_breakin3");
		break;

		case "AgentQuest_breakin3":
			StartQuestMovie(true, true, false);TrackQuestMovie("start","AgentQuest_breakin3");
			DisableFastTravel(true);
			PChar.quest.AgentQuest_foundit.win_condition.l1 = "locator";
			PChar.quest.AgentQuest_foundit.win_condition.l1.location = PChar.quest.agentquest.residence.inside;
			PChar.quest.AgentQuest_foundit.win_condition.l1.locator_group = "box";
			PChar.quest.AgentQuest_foundit.win_condition.l1.locator = "box1";
			PChar.quest.AgentQuest_foundit.win_condition = "AgentQuest_foundit";
		break;

		case "AgentQuest_foundit":
			LAi_SetActorType(PChar);
			LAi_QuestDelay("AgentQuest_foundit2", 2.0);
		break;

		case "AgentQuest_foundit2":
			EndQuestMovie();TrackQuestMovie("end","AgentQuest_foundit2");
			LAi_SetPlayerType(PChar);
			GiveItem2Character(PChar, "plans_copy");
			Characters[GetCharacterIndex(PChar.quest.agentquest.governor)].dialog.currentnode = "agent_quest_return";
			Preprocessor_AddQuestData("town", FindTownName(PChar.quest.agentquest.original_town));
			Preprocessor_AddQuestData("nation", XI_ConvertString(GetNationDescByType(sti(PChar.quest.agentquest.enemy_nation))));
			AddQuestRecord("Agent_Quest", 9);
			Preprocessor_Remove("nation");
			Preprocessor_Remove("town");

			for(i=1; i<=4; i++)								// And any nearby guards must be dead.
			{
				if (CheckAttribute(PChar, "quest.agentquest.soldier" + i))
				{
					sld = CharacterFromID(GetAttribute(PChar, "quest.agentquest.soldier" + i + ".id"));
					ChangeCharacterAddress(sld, "None", "");
				}
			}
			PChar.quest.AgentQuest_breakout.win_condition.l1 = "location";
			PChar.quest.AgentQuest_breakout.win_condition.l1.location = PChar.quest.agentquest.residence.district;
			PChar.quest.AgentQuest_breakout.win_condition = "AgentQuest_breakout";
		break;

		case "AgentQuest_breakout":
			LAi_group_SetLookRadius(GetCurrentSoldierGroup(), LAI_GROUP_GRD_LOOK/2);
			LAi_group_SetHearRadius(GetCurrentSoldierGroup(), LAI_GROUP_GRD_HEAR/2);
			LAi_group_SetSayRadius(GetCurrentSoldierGroup(), LAI_GROUP_GRD_SAY);
			LAi_group_SetRelation(GetCurrentSoldierGroup(), LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			attr = PChar.quest.agentquest.original_island;
			i=sti(Locations[0].IslandsList.(attr).begin);
			PChar.quest.agentquest.return_port = "";
			while (i<sti(Locations[0].IslandsList.(attr).end) && PChar.quest.agentquest.return_port == "")
			{
				if(CheckAttribute(&locations[i],"townsack") && locations[i].townsack==PChar.quest.agentquest.original_town)
				{
					if(CheckAttribute(&locations[i],"id") && HasSubStr(locations[i].id,"port"))
					{
						PChar.quest.agentquest.return_port = locations[i].id;
						PChar.quest.agentquest.return_port_name = FindTownName(PChar.quest.agentquest.original_town) + " " + TranslateString("", "SeaPort");
					}
				}
				i++;
			}
			iForceDetectionFalseFlag = 1;	// Should make shopkeeper and shipyard owner refuse to do business.  Also means that if you do buy a ship and sail away, the fort will attack.
			PChar.quest.agentquest = "find_smuggler";

			PChar.quest.AgentQuest_escape_to_sea.win_condition.l1 = "MapEnter";
			PChar.quest.AgentQuest_escape_to_sea.win_condition = "AgentQuest_escape_to_sea";

			PChar.quest.AgentQuest_reset_soldiers_and_governor.win_condition.l1 = "ExitFromLocation";
			PChar.quest.AgentQuest_reset_soldiers_and_governor.win_condition.l1.location = PChar.location;
			PChar.quest.AgentQuest_reset_soldiers_and_governor.win_condition = "AgentQuest_reset_soldiers_and_governor";
		break;

		case "AgentQuest_reset_soldiers_and_governor":
			DisableFastTravel(false);
			LAi_group_SetLookRadius(GetCurrentSoldierGroup(), LAI_GROUP_GRD_LOOK);
			LAi_group_SetHearRadius(GetCurrentSoldierGroup(), LAI_GROUP_GRD_HEAR);
			LAi_group_SetSayRadius(GetCurrentSoldierGroup(), LAI_GROUP_GRD_SAY);
			NPChar = CharacterFromID(GetTownGovernorID(GetCurrentTownID()));
			NPChar.location = PChar.quest.agentquest.residence.inside;
			if (PChar.quest.agentquest.residence.inside == "PoPrince_townhall") LAi_RemoveLoginTime(CharacterFromID("Contre-Amirale"));
			if (PChar.quest.agentquest.residence.inside == "Muelle_Residence") LAi_SetLoginTime(CharacterFromID("Joaquin Da Saldanha"), 0.0, 24.0);
			for(i=1; i<=4; i++)
			{
				if (CheckAttribute(PChar, "quest.agentquest.soldier" + i))
				{
					sld = CharacterFromID(GetAttribute(PChar, "quest.agentquest.soldier"+i+".id"));
					ChangeCharacterAddressGroup(sld, GetAttribute(PChar, "quest.agentquest.soldier"+i+".location"), GetAttribute(PChar, "quest.agentquest.soldier"+i+".group"), GetAttribute(PChar, "quest.agentquest.soldier"+i+".locator"));
				}
			}
		break;

		case "AgentQuest_escape_to_sea":
			PChar.quest.agentquest = "escaped_to_sea";
			HoistFlag(GetServedNation());
			iForceDetectionFalseFlag = 0;
			if (!CheckQuestAttribute("agentquest", "smuggler_ship"))	// You escaped to sea without the help of the smugglers
			{
				DeleteAttribute(PChar, "isnotcaptain");			// so now you're a captain again
			}
		break;

		case "AgentQuest_Met_Smuggler_Agent":		// Triggered by dialog with smuggler agent
			PChar.quest.agentquest = "found_smuggler";
			Preprocessor_AddQuestData("town", FindTownName(PChar.quest.agentquest.original_town));
			Preprocessor_AddQuestData("shore", Locations[FindLocation(PChar.quest.agentquest.smuggler_beach)].name));
			AddQuestRecord("Agent_Quest", 10);
			Preprocessor_Remove("shore");
			Preprocessor_Remove("town");

			PChar.quest.AgentQuest_smuggler_beach_early.win_condition.l1 = "location";
			PChar.quest.AgentQuest_smuggler_beach_early.win_condition.l1.location = PChar.quest.agentquest.smuggler_beach;
			PChar.quest.AgentQuest_smuggler_beach_early.win_condition.l2 = "Time";
			PChar.quest.AgentQuest_smuggler_beach_early.win_condition.l2.time = DAY_TIME_NIGHT;
			PChar.quest.AgentQuest_smuggler_beach_early.win_condition = "AgentQuest_smuggler_beach_early";

			PChar.quest.AgentQuest_smuggler_goto_beach.win_condition.l1 = "Timer";
			PChar.quest.AgentQuest_smuggler_goto_beach.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
			PChar.quest.AgentQuest_smuggler_goto_beach.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.AgentQuest_smuggler_goto_beach.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.AgentQuest_smuggler_goto_beach.win_condition.l2 = "Time";
			PChar.quest.AgentQuest_smuggler_goto_beach.win_condition.l2.time = DAY_TIME_NIGHT;
			PChar.quest.AgentQuest_smuggler_goto_beach.win_condition = "AgentQuest_smuggler_goto_beach";

			PChar.quest.AgentQuest_smuggler_too_late.win_condition.l1 = "Timer";
			PChar.quest.AgentQuest_smuggler_too_late.win_condition.l1.date.day = GetAddingDataDay(0, 0, 3);
			PChar.quest.AgentQuest_smuggler_too_late.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 3);
			PChar.quest.AgentQuest_smuggler_too_late.win_condition.l1.date.year = GetAddingDataYear(0, 0, 3);
			PChar.quest.AgentQuest_smuggler_too_late.win_condition = "AgentQuest_smuggler_too_late";
		break;

		case "AgentQuest_smuggler_beach_early":
			LAi_SetActorType(PChar);
			PChar.dialog.CurrentNode = "Agent_early_for_smuggler";
			LAi_ActorSelfDialog(PChar, "player_back");
		break;

		case "AgentQuest_smuggler_goto_beach":
			PChar.quest.AgentQuest_smuggler_beach_early.over = "yes";
			bQuestDisableSeaEnter = true;
			Preprocessor_AddQuestData("shore", Locations[FindLocation(PChar.quest.agentquest.smuggler_beach)].name));
			AddQuestRecord("Agent_Quest", 11);
			Preprocessor_Remove("shore");
			NPChar = CharacterFromID("TQ_Char2");
			NPChar.nation = PIRATE;
			SetModelFromID(NPChar, GetRandomModelForTypeExSubCheck(1, "Smugglers", "", PIRATE));
			SetRandomNameToCharacter(NPChar);
			if (NPChar.sex == "woman") NPChar.greeting = "Gr_f_officer";
			else NPChar.greeting = "Gr_Smuggler_OnShore";
			GiveShip2Character(NPChar,"Sloop4","Little Gem",-1,PIRATE,true,true);
			SetCharacterShipLocation(NPChar, PChar.quest.agentquest.smuggler_beach);
			LAi_SetStayType(NPChar);
			NPChar.Dialog.Filename = "Agent_crewman_dialog.c";
			NPChar.Dialog.Currentnode = "smuggler_meet";
			switch(PChar.quest.agentquest.smuggler_beach)
			{
				case "QC_Shore1": ChangeCharacterAddressGroup(NPChar, PChar.quest.agentquest.smuggler_beach, "goto", "citizen05"); break;
				case "Muelle_shore": ChangeCharacterAddressGroup(NPChar, PChar.quest.agentquest.smuggler_beach, "goto", "goto17"); break;
				case "Redmond_shore_02": ChangeCharacterAddressGroup(NPChar, PChar.quest.agentquest.smuggler_beach, "goto", "goto7"); break;
				case "Hispaniola_shore_02": ChangeCharacterAddressGroup(NPChar, PChar.quest.agentquest.smuggler_beach, "goto", "locator10"); break;
				case "Douwesen_shore_02": ChangeCharacterAddressGroup(NPChar, PChar.quest.agentquest.smuggler_beach, "goto", "goto1"); break;
				case "Conceicao_shore_01": ChangeCharacterAddressGroup(NPChar, PChar.quest.agentquest.smuggler_beach, "goto", "locator10"); break;
				case "Eleuthera_shore": ChangeCharacterAddressGroup(NPChar, PChar.quest.agentquest.smuggler_beach, "goto", "goto17"); break;
			}
		break;

		case "AgentQuest_smuggler_too_late":
			Preprocessor_AddQuestData("island", FindIslandName(FindIslandByLocation(PChar.location)));
			AddQuestRecord("Agent_Quest", 14);
			Preprocessor_Remove("island");
			ChangeSmugglerLiking(PChar, -10);
			ChangeCharacterAddress(CharacterFromID("TQ_Char2"), "None", "");
			SetCharacterShipLocation(CharacterFromID("TQ_Char2"), "None");
			bQuestDisableSeaEnter = false;
		break;

		case "AgentQuest_smuggler_depart":	// Triggered by dialog with smuggler on shore
			PChar.quest.AgentQuest_smuggler_too_late.over = "yes";
			PChar.quest.AgentQuest_got_ship.over = "yes";
			bQuestDisableSeaEnter = false;
			PChar.quest.agentquest = "smuggler_ship";
			GiveShip2Character(PChar,"Sloop4","Little Gem",-1,PIRATE,true,true);
			HoistFlag(GetServedNation());
			SafePortLeave(sti(PChar.quest.agentquest.enemy_nation), false);
			iForceDetectionFalseFlag = 0;
			SetCharacterShipLocation(PChar, PChar.quest.agentquest.smuggler_beach);
			if (sti(PChar.quest.agentquest.smuggler_fare) != 0)
			{
				NPChar = CharacterFromID("TQ_Char2");
				LAi_SetActorType(NPChar);
				LAi_ActorFollowEverywhere(NPChar, "", 10.0);
				LAi_SetImmortal(NPChar, true);
			}

			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID(PChar.quest.agentquest.governor)));
			Preprocessor_AddQuestData("port", PChar.quest.agentquest.return_port_name);
			AddQuestRecord("Agent_Quest", 12);
			Preprocessor_Remove("port");
			Preprocessor_Remove("governor");

			PChar.quest.Agentquest_smuggler_arrived.win_condition.l1 = "location";
			PChar.quest.Agentquest_smuggler_arrived.win_condition.l1.location = PChar.quest.agentquest.return_port;
			PChar.quest.Agentquest_smuggler_arrived.win_condition = "Agentquest_smuggler_arrived";
			LAi_QuestDelay("AgentQuest_smuggler_depart2", 0.0);
		break;

		case "AgentQuest_smuggler_depart2":
			switch(PChar.quest.agentquest.smuggler_beach)
			{
				case "QC_Shore1":
					PChar.Ship.Pos.save.x = -1344.263;	// Needed by "WhrWeather.c" otherwise it generates error messages
					PChar.Ship.Pos.save.z = 108;		// Probably harmless, but better not to cause errors!
					QuestToSeaLogin_PrepareLoc("QuebradasCostillas", "reload", "reload_3", false);
				break;
				case "Muelle_shore":
					PChar.Ship.Pos.save.x = -117.897;
					PChar.Ship.Pos.save.z = 652.173;
					QuestToSeaLogin_PrepareLoc("IslaMuelle", "reload", "reload_3", false);
				break;
				case "Redmond_shore_02":
					PChar.Ship.Pos.save.x = -910.59;
					PChar.Ship.Pos.save.z = -1058.522;
					QuestToSeaLogin_PrepareLoc("Redmond", "reload", "reload_3", false);
				break;
				case "Hispaniola_shore_02":
					PChar.Ship.Pos.save.x = -1317.39;
					PChar.Ship.Pos.save.z = -835.661;
					QuestToSeaLogin_PrepareLoc("Hispaniola", "reload", "reload_4", false);
				break;
				case "Douwesen_shore_02":
					PChar.Ship.Pos.save.x = 246.265;
					PChar.Ship.Pos.save.z = 633.757;
					QuestToSeaLogin_PrepareLoc("Douwesen", "reload", "reload_3", false);
				break;
				case "Conceicao_shore_01":
					PChar.Ship.Pos.save.x = -1383.991;
					PChar.Ship.Pos.save.z = -1079.602;
					QuestToSeaLogin_PrepareLoc("Conceicao", "reload", "reload_2", false);
				break;
				case "Eleuthera_shore":
					PChar.Ship.Pos.save.x = 1234.656;
					PChar.Ship.Pos.save.z = -1621.9;
					QuestToSeaLogin_PrepareLoc("QuebradasCostillas", "reload", "reload_4", false);
				break;
			}
			QuestToSeaLogin_Launch();
			SetCharacterShipLocation(CharacterFromID("TQ_Char2"), "None");
		break;

		case "Agentquest_smuggler_arrived":
			bQuestDisableSeaEnter = true;
			if (sti(PChar.quest.agentquest.smuggler_fare) != 0)
			{
				NPChar = CharacterFromID("TQ_Char2");
				if (NPChar.location != PChar.location) PlaceCharacter(NPChar, "goto");
				LAi_SetActorType(PChar);
				LAi_ActorTurnToCharacter(PChar, NPChar);
				LAi_SetActorType(NPChar);
				NPChar.dialog.currentnode = "smuggler_pay_up";
				LAi_ActorWaitDialog(PChar, NPChar);
				LAi_ActorDialog(NPChar, PChar, "Agentquest_smuggler_arrived2", 10.0, 10.0);
			}
			else ChangeSmugglerLiking(PChar, 15);
		break;

		case "Agentquest_smuggler_arrived2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("TQ_Char2"));
			LAi_ActorFollowEverywhere(CharacterFromID("TQ_Char2"), "", 10.0);
		break;

		case "Agentquest_prepare_pay_smuggler":
			DisableFastTravel(true);
			PChar.quest.AgentQuest_pay_smuggler.win_condition.l1 = "ExitFromLocation";
			PChar.quest.AgentQuest_pay_smuggler.win_condition.l1.location = PChar.location;
			PChar.quest.AgentQuest_pay_smuggler.win_condition = "AgentQuest_pay_smuggler";
		break;

		case "AgentQuest_pay_smuggler":
			NPChar = CharacterFromID("TQ_Char2");
			if (NPChar.location != PChar.location) PlaceCharacter(NPChar, "goto");
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, NPChar);
			LAi_SetActorType(NPChar);
			NPChar.dialog.currentnode = "smuggler_payoff";
			LAi_ActorWaitDialog(PChar, NPChar);
			LAi_ActorDialog(NPChar, PChar, "AgentQuest_pay_smuggler2", 10.0, 10.0);
		break;

		case "AgentQuest_pay_smuggler2":
			DisableFastTravel(false);
			LAi_SetPlayerType(PChar);
			NPChar = CharacterFromID("TQ_Char2");
			NPChar.location = "none";
			LAi_SetCitizenType(NPChar);
			ChangeSmugglerLiking(PChar, 15);
		break;

		case "Agentquest_return_ships_and_officers":
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID(PChar.quest.agentquest.governor)));
			Preprocessor_AddQuestData("nation", XI_ConvertString(GetNationDescByType(sti(PChar.quest.agentquest.enemy_nation))));
			AddQuestRecord("Agent_Quest", 13);
			Preprocessor_Remove("nation");
			Preprocessor_Remove("governor");
			CloseQuestHeader("Agent_Quest");
			RestorePassengers(PChar.id);
			DeleteAttribute(PChar, "isnotcaptain");
			bQuestDisableSeaEnter = false;
			PChar.quest.AgentQuest_got_ship.over = "yes";

			cc = 0;
			for (i=1; i<COMPANION_MAX; i++)
			{
				attr = "quest.agentquest.companion" + i;
				if (GetAttribute(PChar, attr) != "*NULL*" && GetAttribute(PChar, attr) != "-1") cc++;
			}
			PChar.quest.agentquest.original_companions_number = cc;

			for (i=1; i<COMPANION_MAX; i++)
			{
				attr = "companion" + i;
				if (PChar.quest.AgentQuest.(attr) != "*NULL*")
				{
					cidx = GetCharacterIndex(PChar.quest.AgentQuest.(attr));
					SetCompanionIndex(PChar,-1, cidx)
					if (HasSubStr(PChar.quest.AgentQuest.(attr), "Enc_Officer")) LAi_UnStoreFantom(CharacterFromID(PChar.quest.AgentQuest.(attr))); // Cancel protection
				}
			}

			NPChar = CharacterFromID("TQ_Char1");
			ExchangeCharacterShip(PChar, CharacterFromID("TQ_Char1"));

			if (!CheckQuestAttribute("agentquest", "smuggler_ship") && GetCompanionQuantity(PChar) < COMPANION_MAX)	// You got here without help from the smugglers, which means you acquired a ship of your own.
			{
				iPassenger = -1;
				if (GetPassengersQuantity(PChar) > 0)
				{
					for(i = 0; i < GetPassengersQuantity(PChar); i++)
					{
						cidx = GetPassenger(PChar, i);
						NPChar = GetCharacter(cidx);
						if (CheckAttribute(NPChar, "id") && GetRemovable(NPChar) && !IsPrisoner(NPChar) && !IsCompanion(NPChar) && NPChar.id != PChar.id)
						{
							iPassenger = cidx;
						}
					}
				}
				if (iPassenger > 0)
				{
					NPChar = GetCharacter(iPassenger);
					if (IsOfficer(NPChar)) RemoveOfficersIndex(PChar, iPassenger);
					RemovePassenger(PChar, NPChar);
					ExchangeCharacterShip(NPChar, CharacterFromID("TQ_Char1"));
					SetCompanionIndex(PChar, -1, iPassenger);
				}
			}
		break;

		case "Agentquest_refused":
			PChar.quest.agentquest = "refused";
			if (ENABLE_CHEATMODE) LAi_QuestDelay("Agentquest_refused_reset", 0.0);
			else
			{
				PChar.quest.Agentquest_refused_reset.win_condition.l1 = "Timer";
				PChar.quest.Agentquest_refused_reset.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
				PChar.quest.Agentquest_refused_reset.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
				PChar.quest.Agentquest_refused_reset.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
				PChar.quest.Agentquest_refused_reset.win_condition = "PChar.quest.Agentquest_refused_reset";
			}
		break;

		case "Agentquest_refused_reset":
			DeleteAttribute(PChar, "quest.agentquest");
		break;

		PChar.questnotfound = true; // PB: Testing
	}
}
