void QuestComplete(string sQuestName)
{
	ref PChar, sld;
// KK -->
	int iPassenger, cidx, iHP, cc;
	float locx, locy, locz;
	string homelocation, homegroup, homelocator, homeisland;
	int crewQty = 0;
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
			pchar.originalmodel = pchar.model
			SetQuestHeader("Beginning_Rogue");
			AddQuestRecord("Beginning_Rogue", 1);
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
			pchar.quest.disguises.win_condition.l1 = "location";
			pchar.quest.disguises.win_condition.l1 = "location";
			pchar.quest.disguises.win_condition.l1.location = "Cuba_port";
			pchar.quest.disguises.win_condition = "disguises";
		break;

		case "disguises":
			setCharacterShipLocation(characterFromID("Enrique Padilla"), "Cuba_port");
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
			CloseQuestHeader("Beginning_Rogue");
			AddQuestRecord("Beginning_Rogue", 5);

			LAi_SetPlayerType(pchar);
			GiveModel2Player(pchar.originalmodel, true);
            		SetModelfromArray(characterFromID("Crewmember_Havana"), GetModelIndex("Sailor4"));
            		SetModelfromArray(characterFromID("Crewmember_Jean3"), GetModelIndex("Sailor6"));
            		SetModelfromArray(characterFromID("Crewmember_Jean2"), GetModelIndex("Sailor3"));
			SetModelfromArray(characterFromID("Crewmember_Jean1"), GetModelIndex("Sailor5"));
			Locations[FindLocation("Havana_town_05")].reload.l3.disable = false;
			GiveShip2Character(pchar,"PO_Fleut50","Miguel de Cervantes",-1,SPAIN,true,true);
			PlaceFleetNearShore("Cuba_port");

			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_3", false);
			QuestToSeaLogin_Launch();
			DeleteAttribute(&Locations[FindLocation("Cuba_port")],"vcskip");
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
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m2, "goto", "citizen05");
			LAi_group_MoveCharacter(sld, "FRENCH_PATROL");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m3, "goto", "citizen04");
			LAi_group_MoveCharacter(sld, "FRENCH_PATROL");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m4, "goto", "citizen01");
			LAi_group_MoveCharacter(sld, "FRENCH_PATROL");
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
			
			AddQuestRecord("Family_Story","16");
			CloseQuestHeader("Family_Story");
			break;			
			
		PChar.questnotfound = true; // PB: Testing
	}
}
