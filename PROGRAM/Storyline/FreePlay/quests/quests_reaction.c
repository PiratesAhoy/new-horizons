void QuestComplete(string sQuestName)
{
	ref PChar, sld;
// KK -->
	int iPassenger, cidx, iHP, cc;
	float locx, locy, locz;
	string homelocation, homegroup, homelocator;
	int crewQty = 0;
// <-- KK
	aref arship; // PB

	PChar = GetMainCharacter();

	switch(sQuestName)
	{
		case "begining":
// KK -->
			if (!CheckQuestAttribute("StartAdventure", "begin")) {
				pchar.quest.Story_LeavingOxbay.win_condition.l1 = "location";
				pchar.quest.Story_LeavingOxbay.win_condition.l1.location = "Oxbay";
				pchar.quest.Story_LeavingOxbay.win_condition = "Story_leavingOxbay";
			}
// <-- KK

			if (CheckQuestAttribute("StartAdventure", "begin")) LAi_QuestDelay("Story_leavingOxbay", 0.0); // KK
		break;

		case "Story_leavingOxbay":
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

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "reload", "reload2_back");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "reload", "reload2_back");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "reload", "reload2_back");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "reload", "reload2_back");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "reload", "reload2_back");
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
			pchar.vcskip = true; // PB: Avoid unwanted characters in jail
			DoQuestReloadToLocation("Havana_prison", "goto", "goto9","LaCroix_jail2");
			Locations[FindLocation("Cuba_shore_03")].reload.l1.disable = false;
			Locations[FindLocation("Cuba_shore_03")].reload.l2.disable = false;
			LAi_SetPlayerType(pchar);
			WaitDate("", 0,0,3,0,0);
			LAi_SetCurHPMax(pchar);
		break;

		case "LaCroix_jail2":
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
			Locations[FindLocation("Havana_town_05")].reload.l3.disable = false;
			GiveShip2Character(pchar,"PO_Fleut50","Miguel de Cervantes",-1,SPAIN,true,true);
			PlaceFleetNearShore("Cuba_port");

			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_3", false);
			QuestToSeaLogin_Launch();
		break;

		case "seeyou":
			AddQuestRecord("Beginning_Rogue", 2);
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
			AddQuestRecord("Beginning_Rogue", 4);
			CloseQuestHeader("Beginning_Rogue");
			Locations[FindLocation("smuggler_ship")].reload.l1.disable = false;
			GiveShip2Character(pchar,"LuggerVML","Sea Horse",-1,ENGLAND,true,true);
			PlaceFleetNearShore("Cuba_Shore_01");
			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_2", false);
			QuestToSeaLogin_Launch();
		break;

		PChar.questnotfound = true; // PB: Testing
	}
}
