void BothQuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld, port;
	PChar = GetMainCharacter();
	float locx;
	float locy;
	float locz;
	string homelocation, homegroup, homelocator;
	string QDeck;
	int KO = 0;

	switch(sQuestName)
	{
//------------------
//Tortuga Atmosphere
//------------------

		case "Tortuga_jack":
			Pchar.quest.Tortuga_restore.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Tortuga_restore.win_condition.l1.location = "Tortuga_port";
			Pchar.quest.Tortuga_restore.win_condition = "Tortuga_restore";
			pchar.quest.Tortuga_restore.skip = "yes";

			port = &locations[FindLocation("Tortuga_port")];
			if(GetAttribute(pchar, "vcskip") < 1 && GetAttribute(port, "vcskip") < 1)
			{
				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur");

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur1");
				LAi_group_FightGroups("bagarreur", "bagarreur1", true);

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur2");

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur3");
				LAi_group_FightGroups("bagarreur2", "bagarreur3", true);

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur4");

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur5");
				LAi_group_FightGroups("bagarreur4", "bagarreur5", true);

				if(rand(100) < 50)
				{
					string SkelLocator = LAi_FindRandomLocator("goto");
					sld = LAi_CreateFantomCharacter(false, 0, true, false, 0.25, GetRandomModelForType(-1,"Monks"), "goto", SkelLocator);
					LAi_SetImmortal(sld, true);
					sld.id = "bagarreur6";
					sld.name = "Scared";
					sld.lastname = "Monk";
					LAi_SetActorType(characterFromID("bagarreur6"));
					LAi_ActorRunToLocation(characterFromID("bagarreur6"), "reload", "reload7_back", "none", "", "", "skeleton_leaves", 0.0);

					sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForType(-1,"Skeletons"), "goto", SkelLocator);
					LAi_SetImmortal(sld, true);
					sld.id = "bagarreur7";
					sld.name = "Cursed";
					sld.lastname = "Skeleton";
					LAi_SetWarriorType(characterFromID("bagarreur7"));
					LAi_warrior_SetCommander(CharacterFromID("bagarreur7"), CharacterFromID("bagarreur6"));
				}
			}
        break;

		case "Tortuga_restore":
			//JRH -->
			if(CheckAttribute(Pchar,"quest.Tortuga_ships") && Pchar.quest.Tortuga_ships == "5")
			{

			}
			else
			{
				if(CheckAttribute(Pchar,"quest.Tortuga_ships") && Pchar.quest.Tortuga_ships == "4")
				{
					Pchar.quest.Tortuga_ships = "5";
		
					GiveShip2Character(characterFromID("Tor_soldier_3"),"MerchantPinnace","Victory",-1,PIRATE,true,true);
					setCharacterShipLocation(characterFromID("Tor_soldier_3"), "Tortuga_port");
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.Tortuga_ships") && Pchar.quest.Tortuga_ships == "2")
					{
						Pchar.quest.Tortuga_ships = "4";

						GiveShip2Character(characterFromID("Tor_patrol_1"),"SchoonerXebec","Victory",-1,PIRATE,true,true);
						GiveShip2Character(characterFromID("Tor_patrol_2"),"FR_Sloop","Victory",-1,PIRATE,true,true);
						setCharacterShipLocation(characterFromID("Tor_patrol_1"), "Tortuga_port");
						setCharacterShipLocation(characterFromID("Tor_patrol_2"), "Tortuga_port");
					}
					else
					{
						Pchar.quest.Tortuga_ships = "2";

						GiveShip2Character(characterFromID("Tor_soldier_1"),"Sloop2","Victory",-1,PIRATE,true,true);
						GiveShip2Character(characterFromID("Tor_soldier_2"),"PiratBrig50","Victory",-1,PIRATE,true,true);
						setCharacterShipLocation(characterFromID("Tor_soldier_1"), "Tortuga_port"); 	
						setCharacterShipLocation(characterFromID("Tor_soldier_2"), "Tortuga_port");	
					}
				}
			}
			//<-- JRH

			PChar.quest.Tortuga_jack.win_condition.l1 = "location";
			PChar.quest.Tortuga_jack.win_condition.l1.character = PChar.id;
			PChar.quest.Tortuga_jack.win_condition.l1.location = "Tortuga_port";
			PChar.quest.Tortuga_jack.win_condition = "Tortuga_jack";
			pchar.quest.Tortuga_jack.skip = "yes";
		break;

//Capitaine Chevalle
		case "Chevalle_search_refused":
			PChar.quest.Chevalle = "refused";
			SetQuestHeader("Chevalle");
			AddQuestRecord("Chevalle", 13);
			DeleteEnterLocationQuest("PoPrince_tavern", "Chevalle_start_check");
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorGoToLocation(CharacterFromID("Captaine Chevalle"), "reload", "reload1", "none", "", "", "adeus", 5.0);
		break;

		case "adeus":
			Characters[GetCharacterIndex("Captaine Chevalle")].Location = "none";
			PChar.quest.Chevalle = "end";
			PChar.quest.Chevalle.over = "yes";
			CloseQuestHeader("Chevalle");
		break;

		case "Chevalle_start_search":
			PChar.quest.Chevalle = "search";

			DeleteEnterLocationQuest("PoPrince_tavern", "Chevalle_start");
//			Locations[FindLocation("Cuba_port")].reload.l1.disable = true;   // TALISMAN - remove locking of Havana Port Gate - not needed
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_SetImmortal(CharacterFromID("Captaine Chevalle"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);
			//DisableFastTravel(true);
			//DisableMenuLaunch(true);
			bSuppressResurrection = true;
			SetQuestHeader("Chevalle");
			AddQuestRecord("Chevalle", 1);
			Pchar.quest.Chevalle.win_condition.l1 = "location";
			Pchar.quest.Chevalle.l1.character = "Captaine Chevalle";
			Pchar.quest.Chevalle.win_condition.l1.location = "Redmond_Shore_01";
			PChar.quest.Chevalle.win_condition = "essai";
		break;

		case "essai":
			SetCurrentTime(12, 0);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "came";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), pchar, "", 0.0, 1.0);
		break;

		case "fight":
			locations[FindLocation("Redmond_Shore_01")].reload.l1.disable = 1;
			locations[FindLocation("Redmond_Shore_01")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_Shore_01")].reload.l3.disable = 1;
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			LAi_group_FightGroups("SHORE_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SHORE_SOLDIERS", "essai_2");
		break;

		case "essai_2":
			AddQuestRecord("Chevalle", 2);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1000);
			}
			else { AddPartyExp(pchar, 2500); }
			LAi_SetStayType(pchar);
			locations[FindLocation("Redmond_Shore_01")].reload.l1.disable = 0;
			locations[FindLocation("Redmond_Shore_01")].reload.l2.disable = 0;
			locations[FindLocation("Redmond_Shore_01")].reload.l3.disable = 0;

			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "in_shore";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), pchar, "", 2.0, 1.0);
		break;

		case "chevallefollow":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_SetImmortal(CharacterFromID("Captaine Chevalle"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);

			ChangeCharacterAddress(characterFromID("Eng_Soldier_7"), "none", "");	// GR: remove permanent soldiers from gate
			ChangeCharacterAddress(characterFromID("Eng_soldier_8"), "none", "");
			ChangeCharacterAddress(characterFromID("Eng_soldier_33"), "none", "");	// GR: remove permanent soldiers from prison
			ChangeCharacterAddress(characterFromID("Eng_soldier_34"), "none", "");

			PChar.quest.Chevalle = "crew";
			Pchar.quest.Chevalle.win_condition.l1 = "location";
			Pchar.quest.Chevalle.l1.character = "Captaine Chevalle";
			Pchar.quest.Chevalle.win_condition.l1.location = "Redmond_town_04";
			PChar.quest.Chevalle.win_condition = "outportroyal";
		break;

		case "outportroyal":
			Locations[FindLocation("Redmond_town_03")].vcskip = true; // PB
			Locations[FindLocation("Redmond_town_04")].reload.l3.disable = true;
			Locations[FindLocation("Redmond_town_04")].reload.l21.disable = true;
			Locations[FindLocation("Redmond_town_04")].reload.l4.disable = true;                  
			Locations[FindLocation("Redmond_town_04")].reload.l22.disable = true;

			LAi_SetPlayerType(pchar);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto_24"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "Captaine Chevalle_dialog.c";
			sld.dialog.currentnode = "guarda";
			sld.id = "soldat";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto_43"); // PB
			LAi_SetHP(sld, 80.0, 80.0); 
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, pchar, "", 10);
			sld.id = "soldat1";
			LAi_group_MoveCharacter(sld, "GATE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "soldier03"); // GR: replace guards near prison with fantom stand-ins
			LAi_SetHP(sld, 80.0, 80.0); 
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, pchar, "", 10);
			sld.id = "soldat2";
			LAi_group_MoveCharacter(sld, "GATE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "soldier04");
			LAi_SetHP(sld, 80.0, 80.0); 
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, pchar, "", 10);
			sld.id = "soldat3";
			LAi_group_MoveCharacter(sld, "GATE_SOLDIERS");
			LAi_SetActorType(characterfromID("soldat"));
			LAi_ActorDialog(characterfromID("soldat"), PChar, "", 0.5, 10);

			PChar.quest.Chevalle_restore_soldiers.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Chevalle_restore_soldiers.win_condition.l1.location = "Redmond_town_04";
			pchar.quest.Chevalle_restore_soldiers.win_condition = "Chevalle_restore_soldiers";
		break;

		case "Chevalle_restore_soldiers":	// GR: put normal guards back near gate and prison
			ChangeCharacterAddressGroup(CharacterFromID("Eng_Soldier_7"), "Redmond_town_04", "goto", "soldier01");
			ChangeCharacterAddressGroup(CharacterFromID("Eng_soldier_8"), "Redmond_town_04", "goto", "soldier02");
			ChangeCharacterAddressGroup(CharacterFromID("Eng_soldier_33"), "Redmond_town_04", "goto", "soldier03");
			ChangeCharacterAddressGroup(CharacterFromID("Eng_soldier_34"), "Redmond_town_04", "goto", "soldier04");
		break;

		case "fight_2":
			LAi_SetWarriorType(characterfromID("soldat"));
			LAi_SetWarriorType(characterfromID("soldat1"));
			LAi_group_MoveCharacter(characterFromID("soldat"), "GATE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("soldat1"), "GATE_SOLDIERS");
			LAi_group_SetCheck("GATE_SOLDIERS", "hurry");
			LAi_group_FightGroups("GATE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
		break;

		case "hurry":
			LAi_SetStayType(pchar); 
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "savecrew";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), pchar, "", 1.0, 1.0);
			AddQuestRecord("Chevalle", 3);
		break;

		case "goverplace":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_SetImmortal(CharacterFromID("Captaine Chevalle"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);

			Locations[FindLocation("Redmond_town_04")].reload.l3.disable = false;
			Locations[FindLocation("Redmond_town_04")].reload.l21.disable = false;
			Locations[FindLocation("Redmond_town_04")].reload.l4.disable = false;
			Locations[FindLocation("Redmond_town_04")].reload.l22.disable = false;

			PChar.quest.Chevalle = "hang";
			Pchar.quest.Chevalle.win_condition.l1 = "location";
			Pchar.quest.Chevalle.l1.character = "Captaine Chevalle";
			Pchar.quest.Chevalle.win_condition.l1.location = "Redmond_town_03";
			PChar.quest.Chevalle.win_condition = "discours";
		break;

		case "discours":
			Locations[FindLocation("Redmond_town_03")].reload.l6.disable = true;
			Locations[FindLocation("Redmond_town_03")].reload.l4.disable = true;
			Locations[FindLocation("Redmond_town_03")].reload.l1.disable = true;
			Locations[FindLocation("Redmond_town_03")].reload.l99.disable = true;
			Locations[FindLocation("Redmond_town_03")].reload.l8.disable = true;
			Locations[FindLocation("Redmond_town_03")].reload.l7.disable = true;
			Locations[FindLocation("Redmond_town_03")].reload.l5.disable = true;
			DeleteAttribute(&Locations[FindLocation("Redmond_town_03")],"vcskip");

			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_01"), "Redmond_town_03", "goto", "goto11");
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_02"), "Redmond_town_03", "goto", "goto12");
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_03"), "Redmond_town_03", "goto", "goto8");
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_04"), "Redmond_town_03", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_05"), "Redmond_town_03", "goto", "goto10");
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_06"), "Redmond_town_03", "goto", "goto13");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto4"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS"); 
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto7"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS"); 
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto29"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS"); 
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "goto31"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS"); 
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "goto", "goto19"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS"); 
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto42"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "animists2", "goto", "goto15");
			LAi_SetHP(sld, 80.0, 80.0);
  			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld.dialog.filename = "Captaine Chevalle_dialog.c";
			sld.dialog.currentnode = "devil";
			sld.id = "bourreau";
			// PB: Hangman should use axe -->
			TakeItemFromCharacter(sld, GetCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));	// Takes hangman's random blade away
			TakeItemFromCharacter(sld, GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE));	// Takes hangman's random gun away
			GiveItem2Character(sld,"bladeaxe1");										// Gives hangman an axe
			EquipCharacterByItem(sld,"bladeaxe1");										// Equips the axe
			// PB: Hangman should use axe <--

            LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto16", "beforevent", 21.0);
		break;

		case "beforevent":
			LAi_ActorTurnToCharacter(pchar, characterFromID("bourreau"));
			LAi_SetStayType(pchar);
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "before";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), pchar, "", 9.0, 1.0);
		break;

		case "commandant":
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_SetImmortal(CharacterFromID("Captaine Chevalle"), 1); 
			LAi_SetActorType(pchar);       
			LAi_ActorGoToLocator(PChar, "goto", "goto18", "talkhangman", 21.0) 
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
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
			LAi_group_FightGroups("SOLDATOS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SOLDATOS", "fuite");
		break;

		case "fuite":
			LAi_KillCharacter(characterFromID("bourreau"));
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_SetImmortal(CharacterFromID("Captaine Chevalle"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);
			LAi_SetActorType(characterFromID("Chevalle_pirate_01"));
			LAi_SetImmortal(CharacterFromID("Chevalle_pirate_01"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Chevalle_pirate_01"), "", 60.0);
			LAi_SetActorType(characterFromID("Chevalle_pirate_02"));
			LAi_SetImmortal(CharacterFromID("Chevalle_pirate_02"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Chevalle_pirate_02"), "", 60.0);
			LAi_SetActorType(characterFromID("Chevalle_pirate_03"));
			LAi_SetImmortal(CharacterFromID("Chevalle_pirate_03"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Chevalle_pirate_03"), "", 60.0);
			LAi_SetActorType(characterFromID("Chevalle_pirate_04"));
			LAi_SetImmortal(CharacterFromID("Chevalle_pirate_04"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Chevalle_pirate_04"), "", 60.0);
			LAi_SetActorType(characterFromID("Chevalle_pirate_05"));
			LAi_SetImmortal(CharacterFromID("Chevalle_pirate_05"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Chevalle_pirate_05"), "", 60.0);	
			LAi_SetActorType(characterFromID("Chevalle_pirate_06"));
			LAi_SetImmortal(CharacterFromID("Chevalle_pirate_06"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Chevalle_pirate_06"), "", 60.0);
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
			PChar.quest.Chevalle = "rencontrer";
			LAi_SetActorType(characterFromID("Chevalle_pirate_06"));
			characters[GetCharacterIndex("Chevalle_pirate_06")].dialog.currentnode = "First time";
			LAi_ActorDialog(characterfromID("Chevalle_pirate_06"), PChar, "", 1.0, 1.0);
			DeleteAttribute(&Locations[FindLocation("Redmond_town_03")],"vcskip"); // PB
		break;

		case "rencontrebc":
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "chevallepirat";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), PChar, "", 1.0, 1.0);
		break;

		case "chevallemoi":
			Locations[FindLocation("Redmond_town_03")].reload.l6.disable = false;
			Locations[FindLocation("Redmond_town_03")].reload.l4.disable = false;
			Locations[FindLocation("Redmond_town_03")].reload.l1.disable = false;
			Locations[FindLocation("Redmond_town_03")].reload.l99.disable = false;
			Locations[FindLocation("Redmond_town_03")].reload.l8.disable = false;
			Locations[FindLocation("Redmond_town_03")].reload.l7.disable = false;
			Locations[FindLocation("Redmond_town_03")].reload.l5.disable = false;
			Locations[FindLocation("Redmond_town_exit_1")].vcskip = true; // PB

			LAi_ActorFollowEverywhere(characterFromID("Chevalle_pirate_06"), "", 60.0);                
			DoReloadCharacterToLocation("Redmond_town_exit_1", "reload", "reload2");
			Locations[FindLocation("Redmond_town_exit_1")].reload.l1.disable = true;
			ChangeCharacterAddressGroup(CharacterFromID("Captaine Chevalle"), "Redmond_town_exit_1", "officers", "reload2_1");
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "outcity";
			LAi_SetActorType(pchar); 
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorWaitDialog(CharacterFromID("Captaine Chevalle"), Pchar); 	                       
			LAi_ActorDialog(pchar, characterFromID("Captaine Chevalle"), "", 10.0, 1.0);
			AddQuestRecord("Chevalle", 4);
		break;

		case "fight_5":
			LAi_SetPlayerType (Pchar);
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "reload", "reload1_back"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ENGLISH");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "reload", "reload1_back"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ENGLISH");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "reload", "reload1_back"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ENGLISH");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "reload", "reload1_back"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ENGLISH");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "reload", "reload1_back"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ENGLISH");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "reload", "reload1_back"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ENGLISH");

			LAi_group_FightGroups("ENGLISH", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("ENGLISH", "evasion_2");
		break;

		case "evasion_2":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Locations[FindLocation("Redmond_town_exit_1")].reload.l1.disable = false;
			DeleteAttribute(&Locations[FindLocation("Redmond_town_exit_1")],"vcskip"); // PB
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "avantplage";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), PChar, "", 0.0, 1.0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1000);
			}
			else { AddPartyExp(pchar, 2500); }
		break;

		case "evasion_3":
			AddQuestRecord("Chevalle", 5);
			PChar.quest.Chevalle = "evas";
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);
			Pchar.quest.Chevalle.win_condition.l1 = "location";
			Pchar.quest.Chevalle.l1.character = "Captaine Chevalle";
			Pchar.quest.Chevalle.win_condition.l1.location = "Redmond_Shore_01";
			PChar.quest.Chevalle.win_condition = "plage";         
		break;

		case "plage":
			Locations[FindLocation("Redmond_Shore_01")].reload.l3.disable = true;
			LAi_SetActorType(pchar);       
			LAi_ActorGoToLocator(PChar, "goto", "locator26", "plage_1", 10.0)
			ChangeCharacterAddressGroup(CharacterFromID("Captaine Chevalle"), "Redmond_Shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_01"), "Redmond_Shore_01", "reload", "reload2");  
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_02"), "Redmond_Shore_01", "reload", "reload2");  
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_03"), "Redmond_Shore_01", "reload", "reload2");  
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_04"), "Redmond_Shore_01", "reload", "reload2");  
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_05"), "Redmond_Shore_01", "reload", "reload2");  
			ChangeCharacterAddressGroup(CharacterFromID("Chevalle_pirate_06"), "Redmond_Shore_01", "reload", "reload2");  
		break;

		case "plage_1":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle")); 
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "second";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), PChar, "", 4.0, 1.0);
			LAi_SetOfficerType(characterFromID("Chevalle_pirate_01"));
			LAi_SetOfficerType(characterFromID("Chevalle_pirate_02"));
			LAi_SetOfficerType(characterFromID("Chevalle_pirate_03"));
			LAi_SetOfficerType(characterFromID("Chevalle_pirate_04"));
			LAi_SetOfficerType(characterFromID("Chevalle_pirate_05"));
			LAi_SetOfficerType(characterFromID("Chevalle_pirate_06"));
		break;

		case "embarquer":
			PChar.quest.Chevalle = "contact";             
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));         
			ChangeCharacterAddressGroup(CharacterFromID("Johan Klaesz"), "Oranjestad_port", "goto", "goto13");
			LAi_SetCitizenType(CharacterFromID("Johan Klaesz"));   
			ChangeCharacterAddress(characterFromID("Chevalle_pirate_01"), "none", "");
			ChangeCharacterAddress(characterFromID("Chevalle_pirate_02"), "none", "");
			ChangeCharacterAddress(characterFromID("Chevalle_pirate_03"), "none", "");
			ChangeCharacterAddress(characterFromID("Chevalle_pirate_04"), "none", "");
			ChangeCharacterAddress(characterFromID("Chevalle_pirate_05"), "none", "");
			ChangeCharacterAddress(characterFromID("Chevalle_pirate_06"), "none", "");
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "crewship";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), PChar, "", 1.0, 1.0);
			AddQuestRecord("Chevalle", 6);
		break;

		case "walkcrew":
			PChar.quest.Chevalle = "frenchcorsair";
			ChangeCharacterAddressGroup(CharacterFromID("Jean-Bart Lafin"), "Oranjestad_exit", "officers", "reload3_2");
			LAi_SetCitizenType(CharacterFromID("Jean-Bart Lafin"));
			AddQuestRecord("Chevalle", 7);
		break;     
 
		case "quitjamaica":
			Locations[FindLocation("Redmond_Shore_01")].reload.l3.disable = false;
			LAi_SetOfficerType(characterFromID("Johan Klaesz"));
			ChangeCharacterAddress(characterFromID("Johan Klaesz"), "none", "");
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "horsjamaica";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), PChar, "", 0.0, 1.0);
		break;

		case "directnevis":
			AddQuestRecord("Chevalle", 8);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);
			LAi_SetActorType(characterFromID("Jean-Bart Lafin"));
			LAi_SetImmortal(characterFromID("Jean-Bart Lafin"), true);
			LAi_ActorFollowEverywhere(characterFromID("Jean-Bart Lafin"), "", 60.0);
			PChar.quest.Chevalle = "dernier";
			Pchar.quest.Chevalle.win_condition.l1 = "location";
			Pchar.quest.Chevalle.l1.character = "Captaine Chevalle";
			Pchar.quest.Chevalle.win_condition.l1.location = "QC_Town";
			PChar.quest.Chevalle.win_condition = "mercenaires";
		break;

		case "mercenaires":
			Locations[FindLocation("QC_town_exit")].reload.l1.disable = true;
			Locations[FindLocation("QC_town_exit")].reload.l2.disable = true;
			Locations[FindLocation("QC_town_exit")].reload.l3.disable = true;
			Locations[FindLocation("QC_town_exit")].reload.l5.disable = true;
			Locations[FindLocation("QC_town_exit")].reload.l4.disable = true;
			Locations[FindLocation("QC_port")].reload.l1.disable = true;

			LAi_SetOfficerType(characterFromID("Jean-Bart Lafin"));
			ChangeCharacterAddress(characterFromID("Jean-Bart Lafin"), "none", "");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "47Blaze_Eitc_cpt", "goto", "character10");
			LAi_SetHP(sld, 120.0, 120.0);
			sld.dialog.filename = "Captaine Chevalle_dialog.c";
			sld.dialog.currentnode = "lafin";
			sld.id = "chef";

			LAi_SetActorType(characterFromID("chef"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Eitc_lt1_47", "officers", "reload12_3");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "mercenary");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "character14");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "mercenary");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "officers", "reload7_1");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "mercenary");

			LAi_SetActorType(pchar); 
			LAi_ActorGoToLocator(PChar, "goto", "character13", "dispute_2", 20.0);
		break;

		case "dispute_2":
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("chef"));   
			LAi_ActorDialog(characterFromID("chef"), PChar, "", 0.0, 1.0);
		break;

		case "dispute_3":
			LAi_ActorAttack(CharacterFromID("chef"), PChar, "");
			LAi_QuestDelay("dispute_4", 2.0);
		break;

		case "dispute_4":
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
			LAi_group_FightGroups("mercenary", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("mercenary", "findefin");
		break;

		case "findefin":
			Locations[FindLocation("QC_town_exit")].reload.l1.disable = false;
			Locations[FindLocation("QC_town_exit")].reload.l2.disable = false;
			Locations[FindLocation("QC_town_exit")].reload.l3.disable = false;
			Locations[FindLocation("QC_town_exit")].reload.l5.disable = false;
			Locations[FindLocation("QC_town_exit")].reload.l4.disable = false;
			Locations[FindLocation("QC_port")].reload.l1.disable = false;
    
			bSuppressResurrection = false;
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_KillCharacter(characterFromID("chef")); 
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "lafin_2";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), PChar, "", 0.0, 1.0);
		break;

		case "chevalleofficer":
			PChar.Quest.Chevalle = "1";
			AddQuestRecord("Chevalle", 9);
			//CloseQuestHeader("Chevalle");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			LAi_SetImmortal(characterFromID("Captaine Chevalle"), false);
			AddPassenger(Pchar, characterFromID("Captaine Chevalle"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Captaine Chevalle"));
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
			SetCrewQuantity(pchar, makeint(GetCrewQuantity(pchar) + 7));
			//Characters[GetCharacterIndex("Captaine Chevalle")].dialog.filename = "Enc_Officer_dialog.c";
			//Characters[GetCharacterIndex("Captaine Chevalle")].dialog.CurrentNode = "hired";
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.CurrentNode = "first time";
			if (GetAttribute(pchar, "Chevalle") == "0")
			{
				Pchar.quest.Eduardo_Villanueva.win_condition.l1 = "location";
				Pchar.quest.Eduardo_Villanueva.win_condition.l1.character = "Captaine Chevalle";
				Pchar.quest.Eduardo_Villanueva.win_condition.l1.location = "Tortuga_port";
				PChar.quest.Eduardo_Villanueva.win_condition = "tortuga_chevalle";
			}
		break;

		case "chevallebye":
			AddQuestRecord("Chevalle", 10); 
			CloseQuestHeader("Chevalle");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			LAi_SetImmortal(characterFromID("Captaine Chevalle"), false);
			LAi_ActorGoToLocator(characterFromID("Captaine Chevalle"), "goto", "goto24", "disparu", 40.0);
		break;

		case "disparu":
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));      
			ChangeCharacterAddress(characterFromID("Captaine Chevalle"), "none", "");
		break;
//Capitaine Chevalle

//Captain Eduardo Villanueva
		case "tortuga_chevalle":
			if(IsOfficer(characterFromID("Captaine Chevalle")))
			{
				RemovePassenger(pchar, characterFromID("Captaine Chevalle"));
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

				LAi_SetActorType(Pchar);
				Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
				Pchar.dialog.currentnode = "Where Chevalle";
				LAi_ActorSelfDialog(Pchar, "player_back");

				AddQuestRecord("Chevalle", 11);

				PChar.quest.Jackpot = "search";
			}
			else
			{
				Pchar.quest.Eduardo_Villanueva.win_condition.l1 = "location";
				Pchar.quest.Eduardo_Villanueva.win_condition.l1.character = "Captaine Chevalle";
				Pchar.quest.Eduardo_Villanueva.win_condition.l1.location = "Tortuga_port";
				PChar.quest.Eduardo_Villanueva.win_condition = "tortuga_chevalle";
			}
		break;

		case "MeetVillanueva":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorWaitDialog(CharacterFromID("Eduardo Villanueva"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Eduardo Villanueva"), "", 10.0, 1.0);
		break;

		case "talktoswann":
 			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorWaitDialog(CharacterFromID("Captaine Chevalle"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Captaine Chevalle"), "", 10.0, 1.0);
		break;

		case "leavetortuga":
			PChar.quest.Jackpot = "gobattlerocks";
			bSuppressResurrection = true;
			SetQuestHeader("Villanueva_and_Chevalle");
			AddQuestRecord("Villanueva_and_Chevalle", "1");
			CloseQuestHeader("Chevalle");
			LAi_SetPlayerType(pchar);
			LAi_SetCitizenType(characterFromID("Eduardo Villanueva"));
			LAi_SetCitizenType(characterFromID("Captaine Chevalle"));
			if (GetAttribute(pchar, "Chevalle") == "Mutiny")
			{
				GiveShip2Character(pchar,"SP_Neptunus","Sargento",-1,SPAIN,true,true);
			}
			else
			{
				SetCompanionIndex(Pchar, -1, GetCharacterIndex("Eduardo Villanueva"));
				SetCharacterRemovable(characterFromID("Eduardo Villanueva"), false);
			}

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
			SetQuestHeader("Villanueva_and_Chevalle");
			AddQuestRecord("Villanueva_and_Chevalle", "2");
			CloseQuestHeader("Villanueva_and_Chevalle");
			CloseQuestHeader("Chevalle");
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorGoToLocation(characterFromID("Eduardo Villanueva"), "reload", "reload1", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorGoToLocation(characterFromID("Captaine Chevalle"), "reload", "reload1", "none", "", "", "", 0.0);
		break;

		case "to_Devil_Creek":
			LAi_SetCivilianGuardianType(characterFromID("Eduardo Villanueva"));
			LAi_SetCivilianGuardianType(characterFromID("Captaine Chevalle"));
			ChangeCharacterAddressGroup(CharacterFromID("Eduardo Villanueva"), "Devil_Creek", "goto", "locator10");
			ChangeCharacterAddressGroup(CharacterFromID("Captaine Chevalle"), "Devil_Creek", "goto", "citizen07");
			Characters[GetCharacterIndex("Eduardo Villanueva")].dialog.CurrentNode = "begin_11";
 			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorWaitDialog(CharacterFromID("Eduardo Villanueva"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Eduardo Villanueva"), "", 10.0, 1.0);
		break;

		case "meetindians":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_SetImmortal(CharacterFromID("Eduardo Villanueva"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_SetImmortal(CharacterFromID("Captaine Chevalle"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);
			pchar.quest.meet_indians.win_condition.l1 = "location";
			pchar.quest.meet_indians.win_condition.l1.location = "Battle_Rocks_Jungle_04";
			pchar.quest.meet_indians.win_condition = "fightindians";
		break;

		case "fightindians":
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l3.disable = 1;
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l4.disable = 1;
			LAi_SetOfficerType(characterFromID("Eduardo Villanueva"));
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));

			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Native", "goto", "goto2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");
			sld.name = "Indian";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Native", "goto", "goto2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");
			sld.name = "Indian";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Native", "goto", "goto2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");
			sld.name = "Indian";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Native", "goto", "goto2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");
			sld.name = "Indian";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Native", "goto", "goto2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");
			sld.name = "Indian";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "Native", "goto", "goto2");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");
			sld.name = "Indian";
			sld.lastname = "";

			LAi_group_FightGroups("JUNGLE_INDIANS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("JUNGLE_INDIANS", "leaveindians");
		break;

		case "leaveindians":
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l3.disable = 0;
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "begin2_4";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), pchar, "", 50.0, 10.0);
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);
			AddQuestRecord("Villanueva_and_Chevalle", "3");
		break;

		case "meetprisoner":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);
			LAi_SetImmortal(characterFromID("Francois de Hadoque"), true);
			ChangeCharacterAddress(CharacterFromID("Francois de Hadoque"), "Battle_Rocks_Jungle_02", "goto8");
			LAi_SetPoorType(characterfromID("Francois de Hadoque"));
			locations[FindLocation("Battle_Rocks_Jungle_02")].reload.l4.disable = 1;
		break;

		case "opinionturner":
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			Characters[GetCharacterIndex("Eduardo Villanueva")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Eduardo Villanueva"), pchar, "", 2.0, 1.0);
		break;

		case "gospanishcamp":
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			Characters[GetCharacterIndex("Francois de Hadoque")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Francois de Hadoque"), pchar, "", 2.0, 1.0);
		break;

		case "gospanishcamp2":
			locations[FindLocation("Battle_Rocks_Jungle_02")].reload.l4.disable = 0;
			AddQuestRecord("Villanueva_and_Chevalle", "4");
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			LAi_ActorRunToLocation(characterFromID("Francois de Hadoque"), "reload", "reload1", "none", "", "", "", 0.0);
			pchar.quest.meet_spaniards.win_condition.l1 = "location";
			pchar.quest.meet_spaniards.win_condition.l1.location = "spanish_camp";
			pchar.quest.meet_spaniards.win_condition = "fightspaniards";
		break;

		case "fightspaniards":
			locations[FindLocation("spanish_camp")].reload.l4.disable = 1;
			locations[FindLocation("spanish_camp")].reload.l5.disable = 1;
			locations[FindLocation("spanish_camp")].reload.l6.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Francois de Hadoque"), "spanish_camp", "officers", "reload2_1");
			ChangeCharacterAddressGroup(characterFromID("Eduardo Villanueva"), "spanish_camp", "officers", "reload2_2");
			ChangeCharacterAddressGroup(characterFromID("Captaine Chevalle"), "spanish_camp", "officers", "reload2_3");
			GiveItem2Character(characterFromID("Francois de Hadoque"),"blade15");
			EquipCharacterByItem(characterFromID("Francois de Hadoque"),"blade15");
			GiveItem2Character(CharacterFromId("Francois de Hadoque"),"pistol3");
			EquipCharacterByItem(CharacterFromId("Francois de Hadoque"), "pistol3");
			//JRH ammo mod -->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromId("Francois de Hadoque"), "gunpowder", 6);
				TakenItems(CharacterFromId("Francois de Hadoque"), "pistolgrapes", 6);
			}
			//JRH ammo mod <--

			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Spaniardsattack";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "fightspaniards2":
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Eduardo Villanueva"));
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
			LAi_SetOfficerType(characterFromID("Francois de Hadoque"));
			LAi_QuestDelay("fightspaniards3", 1.5);
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

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
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			Characters[GetCharacterIndex("Francois de Hadoque")].dialog.currentnode = "begin_9";
			LAi_ActorDialog(characterFromID("Francois de Hadoque"), pchar, "", 50.0, 10.0);
		break;

		case "gomine2":
			locations[FindLocation("spanish_camp")].reload.l5.disable = 0;
			locations[FindLocation("spanish_camp")].reload.l6.disable = 0;
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			LAi_ActorRunToLocation(characterFromID("Francois de Hadoque"), "reload", "reload3", "none", "", "", "", 0.0);
			pchar.quest.meet_friends.win_condition.l1 = "location";
			pchar.quest.meet_friends.win_condition.l1.location = "Battle_Rocks_Jungle_01";
			pchar.quest.meet_friends.win_condition = "minefight";
		break;

		case "minefight":
			ChangeCharacterAddressGroup(characterFromID("Francois de Hadoque"), "Battle_Rocks_Jungle_01", "goto", "goto10");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "officers", "reload1_2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_SOLDATOS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "officers", "reload1_3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
  			LAi_group_MoveCharacter(sld, "MINE_SOLDATOS");
			sld.dialog.filename = "Francois de Hadoque_dialog.c";
			sld.dialog.currentnode = "begin_11";
			sld.id = "futurmort";
			sld.name = "Soldier";
			sld.lastname = "";

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
			LAi_SetOfficerType(characterFromID("Eduardo Villanueva"));
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
			LAi_SetOfficerType(characterFromID("Francois de Hadoque"));
  			LAi_group_MoveCharacter(characterFromID("futurmort"), "MINE_SOLDATOS");
			LAi_group_FightGroups("MINE_SOLDATOS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("MINE_SOLDATOS", "entrermine");
		break;

		case "entrermine":
			pchar.quest.meet_friend.win_condition.l1 = "location";
			pchar.quest.meet_friend.win_condition.l1.location = "Battle_Rocks_Mine";
			pchar.quest.meet_friend.win_condition = "talktofriends";
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			LAi_ActorFollowEverywhere(characterFromID("Francois de Hadoque"), "", 60.0);
		break;

		case "talktofriends":
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Brodyag1", "goto", "goto1");
			LAi_SetHP(sld, 80.0, 80.0);
  			LAi_group_MoveCharacter(sld, "MINE_FRIENDS");
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "man4", "goto", "goto10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "mineami";
			sld.dialog.filename = "Francois de Hadoque_dialog.c";
			sld.dialog.currentnode = "begin_12";
			LAi_SetCivilianGuardianType(characterFromID("mineami"));
		break;

		case "allerport":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			Characters[GetCharacterIndex("Francois de Hadoque")].dialog.currentnode = "begin_16";
			LAi_ActorWaitDialog(CharacterFromID("Francois de Hadoque"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Francois de Hadoque"), "", 10.0, 10.0);
		break;

		case "allerport2":
			AddQuestRecord("Villanueva_and_Chevalle", "5");
			setCharacterShipLocation(characterFromID("Francois de Hadoque"), "Battle_Rocks_port"); 
			locations[FindLocation("spanish_camp")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_port")].reload.l3.disable = 1;
			LAi_SetPlayerType(pchar);
			DoReloadCharacterToLocation("Battle_Rocks_port", "goto", "locator10");
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			//LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);
			ChangeCharacterAddressGroup(characterFromID("Eduardo Villanueva"), "Battle_Rocks_port", "goto", "citizen03");
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			LAi_ActorFollowEverywhere(characterFromID("Francois de Hadoque"), "", 60.0);
			ChangeCharacterAddressGroup(characterFromID("Captaine Chevalle"), "Battle_Rocks_port", "officers", "reload1_1");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "begin2_5";
			LAi_ActorWaitDialog(CharacterFromID("Captaine Chevalle"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Captaine Chevalle"), "", 10.0, 10.0);
		break;

		case "argument1_CC_CEV":
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			Characters[GetCharacterIndex("Eduardo Villanueva")].dialog.currentnode = "begin_18";
			LAi_ActorWaitDialog(CharacterFromID("Eduardo Villanueva"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Eduardo Villanueva"), "", 10.0, 10.0);
		break;

		case "argument2_CC_CEV":
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "begin2_2";
			LAi_ActorWaitDialog(CharacterFromID("Captaine Chevalle"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Captaine Chevalle"), "", 10.0, 10.0);
		break;

		case "argument3_CC_CEV":
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			Characters[GetCharacterIndex("Eduardo Villanueva")].dialog.currentnode = "begin_19";
			LAi_ActorWaitDialog(CharacterFromID("Eduardo Villanueva"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Eduardo Villanueva"), "", 10.0, 10.0);
		break;

		case "argument4_CC_CEV":
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "begin2_3";
			LAi_ActorWaitDialog(CharacterFromID("Captaine Chevalle"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Captaine Chevalle"), "", 10.0, 10.0);
		break;

		case "board_spanish_ship_BR":
			QDeck = GetCharacterShipQDeck(Characters[GetCharacterIndex("Francois de Hadoque")]);
			pchar.vcskip = true;

			DoQuestReloadToLocation(QDeck, "reload", "boatl", "board_spanish_ship_BR2");
		break;

		case "board_spanish_ship_BR2":
			LAi_SetPlayerType(pchar);
			SetCharacterToNearLocatorFromMe("Francois de Hadoque", 3);
			changeCharacterAddressGroup(characterfromID("Captaine Chevalle"), "none", "", "");
			changeCharacterAddressGroup(characterfromID("Eduardo Villanueva"), "none", "", "");
			LAi_QuestDelay("board_spanish_ship_BR3", 0.0);
		break;

		case "board_spanish_ship_BR3":
			LAi_SetOfficerType(characterFromID("Francois de Hadoque"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "goto", "goto3"); // CTM
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "SHIP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto3"); // CTM
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "SHIP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "goto", "goto3"); // CTM
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "SHIP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "goto", "goto3"); // CTM
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "SHIP_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			LAi_group_FightGroups("SHIP_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SHIP_SOLDIERS", "captured_spanish_ship_BR");
		break;

		case "captured_spanish_ship_BR":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			Characters[GetCharacterIndex("Francois de Hadoque")].dialog.currentnode = "on_ship";
			LAi_ActorWaitDialog(CharacterFromID("Francois de Hadoque"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Francois de Hadoque"), "", 10.0, 10.0);

			DeleteAttribute(pchar,"vcskip");
		break;

		case "Back_to_BR_port":
			characters[GetCharacterIndex("Francois de Hadoque")].sailaway = true;
			locations[FindLocation("spanish_camp")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_port")].reload.l3.disable = 1;
			LAi_SetPlayerType(pchar);
			DoReloadCharacterToLocation("Battle_Rocks_port", "goto", "locator10");
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			//LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);
			ChangeCharacterAddressGroup(characterFromID("Eduardo Villanueva"), "Battle_Rocks_port", "goto", "citizen03");
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			LAi_ActorFollowEverywhere(characterFromID("Francois de Hadoque"), "", 60.0);
			ChangeCharacterAddressGroup(characterFromID("Captaine Chevalle"), "Battle_Rocks_port", "officers", "reload1_1");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "begin2_8";
			LAi_ActorWaitDialog(CharacterFromID("Captaine Chevalle"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Captaine Chevalle"), "", 10.0, 10.0);
		break;

		case "seesoldier":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "citizen01"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PRAIA_SOLDATOS");
			sld.id = "fuyard";
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("fuyard"));
			LAi_ActorTurnToCharacter(characterFromID("fuyard"), pchar);
			LAi_SetActorType(characterFromID("fuyard"));
			LAi_ActorRunToLocation(characterFromID("fuyard"), "reload", "reload2", "none", "", "", "", 0.0);
			LAi_QuestDelay("attraperfuyard", 2.5);
		break;

		case "attraperfuyard":
			LAi_SetActorType(pchar); 
 			//LAi_ActorGoToLocator(PChar, "goto", "citizen07", "fuyardparti", 20.0);
			LAi_ActorRunToLocator(PChar, "goto", "citizen07", "fuyardparti", 20.0);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);
		break;

		case "fuyardparti": 
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			Characters[GetCharacterIndex("Eduardo Villanueva")].dialog.currentnode = "begin_13";
			LAi_ActorDialog(characterFromID("Eduardo Villanueva"), pchar, "", 20.0, 10.0);
		break;

		case "gosilvertrain":
			locations[FindLocation("Battle_Rocks_port")].reload.l3.disable = 0;

			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);
			pchar.quest.meet_friend.win_condition.l1 = "location";
			pchar.quest.meet_friend.win_condition.l1.location = "Battle_Rocks_Jungle_03";
			pchar.quest.meet_friend.win_condition = "joinsilvertrain";
		break;

		case "joinsilvertrain":
			DeleteAttribute(characterFromID("Francois de Hadoque"), "sailaway"); // CTM: Reset - just in case
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l4.disable = 1;
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l5.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Francois de Hadoque"), "Battle_Rocks_Jungle_03", "officers", "reload1_3");
			ChangeCharacterAddressGroup(characterFromID("Eduardo Villanueva"), "Battle_Rocks_Jungle_03", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Captaine Chevalle"), "Battle_Rocks_Jungle_03", "officers", "reload1_2");

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
			sld.dialog.filename = "Francois de Hadoque_dialog.c";
			sld.dialog.currentnode = "begin_17";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto2"); // PB
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
			LAi_SetOfficerType(characterFromID("Eduardo Villanueva"));
			LAi_SetOfficerType(characterFromID("Captaine Chevalle"));
			LAi_SetOfficerType(characterFromID("Francois de Hadoque"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");
			sld.name = "Soldier";
			sld.lastname = "";

			LAi_group_FightGroups("CONVOY_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("CONVOY_SOLDIERS", "joinsilvertrain3");
		break;

		case "joinsilvertrain3":
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			LAi_ActorFollowEverywhere(characterFromID("Francois de Hadoque"), "", 60.0);
			LAi_SetCivilianGuardianType(characterFromID("convoyami"));
		break;

		case "leavebattle":
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l5.disable = 0;
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			Characters[GetCharacterIndex("Eduardo Villanueva")].dialog.currentnode = "begin_15";
			LAi_ActorDialog(characterFromID("Eduardo Villanueva"), pchar, "", 20.0, 10.0);
		break;

		case "leavedevilcreek":
			LAi_SetCivilianGuardianType(characterFromID("Captaine Chevalle"));
			DoReloadCharacterToLocation("Devil_Creek", "goto", "locator10");
			ChangeCharacterAddressGroup(characterFromID("Captaine Chevalle"), "Devil_Creek", "goto", "citizen02");
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorFollowEverywhere(characterFromID("Eduardo Villanueva"), "", 60.0);

			setCharacterShipLocation(characterFromID("Francois de Hadoque"), "Devil_Creek"); 

			LAi_SetActorType(pchar); 
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "begin2_6";
			LAi_ActorWaitDialog(CharacterFromID("Captaine Chevalle"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Captaine Chevalle"), "", 10.0, 10.0);
		break;

		case "leavedevilcreek2":
			AddQuestRecord("Villanueva_and_Chevalle", "6");
			pchar.quest.sail_tortuga.win_condition.l1 = "location";
			pchar.quest.sail_tortuga.win_condition.l1.location = "Tortuga_port";
			pchar.quest.sail_tortuga.win_condition = "meetshopkeeper";
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorFollowEverywhere(characterFromID("Captaine Chevalle"), "", 60.0);

			if (GetAttribute(pchar, "Chevalle") == "0")
			{
				SetCompanionIndex(Pchar, -1, GetCharacterIndex("Eduardo Villanueva"));
				SetCharacterRemovable(characterFromID("Eduardo Villanueva"), false);
			}
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Francois de Hadoque"));
			SetCharacterRemovable(characterFromID("Francois de Hadoque"), false);
		break;

		case "meetshopkeeper":
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			Characters[GetCharacterIndex("Eduardo Villanueva")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Eduardo Villanueva"), pchar, "", 20.0, 10.0);
		break;

		case "leaveturner":
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			Characters[GetCharacterIndex("Captaine Chevalle")].dialog.currentnode = "begin2_7";
			LAi_ActorDialog(characterFromID("Captaine Chevalle"), pchar, "", 20.0, 10.0);
		break;

		case "leaveturner2":
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			Characters[GetCharacterIndex("Eduardo Villanueva")].dialog.currentnode = "begin_17";
			LAi_ActorDialog(characterFromID("Eduardo Villanueva"), pchar, "", 20.0, 10.0);
		break;

		case "leaveturner3":
			LAi_ActorTurnToCharacter(characterFromID("Eduardo Villanueva"), characterFromID("Captaine Chevalle"));
			LAi_ActorTurnToCharacter(characterFromID("Captaine Chevalle"), characterFromID("Eduardo Villanueva"));

			LAi_QuestDelay("leaveKonradKulczycki", 1.0);
		break;

		case "leaveKonradKulczycki":
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			Characters[GetCharacterIndex("Francois de Hadoque")].dialog.currentnode = "begin_18";	
			LAi_ActorDialog(characterFromID("Francois de Hadoque"), pchar, "", 20.0, 10.0);
		break;

		case "leaveswann":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 25000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 25000); }

			bSuppressResurrection = false;
			AddQuestRecord("Villanueva_and_Chevalle", "7");
			RemoveCharacterCompanion(Pchar, characterFromID("Eduardo Villanueva"));
			setCharacterShipLocation(characterFromID("Eduardo Villanueva"), "none"); 

			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			LAi_ActorFollowEverywhere(characterFromID("Francois de Hadoque"), "", 60.0);

			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorAnimation(characterFromID("Captaine Chevalle"), "attack_2", "/*Eduardo_retail*/", 0.0);	// Nonsensical quest case name
			LAi_ActorAnimation(characterFromID("Captaine Chevalle"), "attack_2", "", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");

			LAi_QuestDelay("Eduardo_retail", 0.2);
			pchar.quest.sail_turks.win_condition.l1 = "location";
			pchar.quest.sail_turks.win_condition.l1.location = "Turks_port";
			pchar.quest.sail_turks.win_condition = "Francois_to_Turks";
		break;

		case "Eduardo_retail":
			LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_ActorAnimation(characterFromID("Eduardo Villanueva"), "shot", "Eduardo_shot", 0.0);
			PlaySound("OBJECTS\duel\pistol_bbus.wav");
		break;

		case "Eduardo_shot":
			//LAi_SetStunnedTypeNoGroup(characterFromID("Eduardo Villanueva"));
			//LAi_SetStunnedTypeNoGroup(characterFromID("Captaine Chevalle"));
			/*LAi_SetActorType(characterFromID("Eduardo Villanueva"));
			LAi_SetActorType(characterFromID("Captaine Chevalle"));
			LAi_ActorAttack(characterfromID("Eduardo Villanueva"), characterFromID("Captaine Chevalle"), "");
			LAi_ActorAttack(characterFromID("Captaine Chevalle"), characterfromID("Eduardo Villanueva"), "");*/
			LAi_group_MoveCharacter(characterFromID("Eduardo Villanueva"), "PLAYER1");
			LAi_group_MoveCharacter(characterFromID("Captaine Chevalle"), "PLAYER2");

			LAi_group_FightGroups("PLAYER1", "PLAYER2", true);

			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "reload", "reload2_back", "", 10.0);
			LAi_ActorGoToLocation(characterFromID("Francois de Hadoque"), "reload", "reload2_back", "Turks_Port", "goto", "P_goto4", "", 10.0);	//JRH: new Turks, was goto4
			LAi_QuestDelay("reset_after_CC_EV", 0.0);
		break;

		case "reset_after_CC_EV":
			LAi_SetPlayerType(pchar);
			LAi_QuestDelay("CC_EV_Disappear", 20.0);
		break;

		case "CC_EV_Disappear":
			changeCharacterAddressGroup(characterfromID("Eduardo Villanueva"), "none", "", "");
			changeCharacterAddressGroup(characterFromID("Captaine Chevalle"), "none", "", "");
		break;

		case "Francois_to_Turks":
			LAi_SetActorType(characterFromID("Francois de Hadoque"));
			Characters[GetCharacterIndex("Francois de Hadoque")].dialog.currentnode = "begin_20";	
			LAi_ActorDialog(characterFromID("Francois de Hadoque"), pchar, "", 20.0, 10.0);
		break;

		case "Francois_to_Turks2":
			if (GetAttribute(pchar, "Chevalle") == "Mutiny")
			{
				LAi_QuestDelay("Gibbs_in_tavern2_1", 3.0);
			}
			LAi_ActorRunToLocation(characterFromID("Francois de Hadoque"), "reload", "gate_back", "none", "", "", "", 0.0);		//JRH: new Turks jungle exit
			RemoveCharacterCompanion(Pchar, characterFromID("Francois de Hadoque"));
			setCharacterShipLocation(characterFromID("Francois de Hadoque"), "none");
			AddQuestRecord("Villanueva_and_Chevalle", "8");
			CloseQuestHeader("Villanueva_and_Chevalle");
		break;
//Captain Eduardo Villanueva

//Sri Sumbhajee Angria
		case "spanish_soldier_alone":
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "Spain1";
			LAi_ActorSelfDialog(pchar, "player_back");

			changeCharacterAddressGroup(characterFromID("random_spain_off"), "Havana_town_02", "goto", "goto13"); 
			LAi_ActorTurnToCharacter(pchar, CharacterFromID("random_spain_off"));
		break;

		case "talk_to_soldier_alone":
			LAi_SetActorType(characterFromID("random_spain_off"));
			LAi_SetPlayerType(pchar);
			LAi_ActorWaitDialog(characterFromID("random_spain_off"), pchar);
			LAi_ActorDialog(characterFromID("random_spain_off"), pchar, "", 2.0, 1.0);
		break;

		case "to_much_rum_I_think":
			Lai_KillCharacter(characterFromID("random_spain_off"));

			LAi_QuestDelay("rum_overload", 4.0);
		break;

		case "rum_overload":
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "Spain2";
			LAi_ActorSelfDialog(pchar, "player_back");
			GiveModel2Player("47_Sparrow_spain", false); // PB
		break;

		case  "talkforSumbhajee":
			LAi_ActorDialog(characterFromID("Sumbhajee Aid1"),PChar,"",10.0,1.0);
			LAi_QuestDelay("talkforSumbhajee2", 0.0);
		break;

		case "talkforSumbhajee2":
			Characters[GetCharacterIndex("Sumbhajee Aid1")].dialog.currentnode = "First time";
			if (GetAttribute(Pchar, "Spain") == "1")
			{
				Pchar.quest.Sumbhajee.win_condition.l1 = "location";
				Pchar.quest.Sumbhajee.win_condition.l1.location = "Havana_Prison";
				PChar.quest.Sumbhajee.win_condition = "spanish_uniform";     
			}
			else
			{
				pchar.quest.spanish_soldier_alone.over = "yes";
			}
			ChangeCharacterAddress(characterFromID("random_spain_off"), "none", "");
		break;

		case "spanish_uniform":
			GiveModel2Player("47_Sparrow_spain", true);
		break;

		case "to_ship_of_Bernardo_Gamboa":
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "to_ship_of_Bernardo_Gamboa";
			LAi_ActorSelfDialog(pchar, "player_back");
		break;

		case "not_to_the_ship":
			LAi_SetPlayerType(pchar);
			pchar.quest.not_to_the_ship_2.win_condition.l1 = "ExitFromLocation";
			pchar.quest.not_to_the_ship_2.win_condition.l1.location = "Cuba_port";
			pchar.quest.not_to_the_ship_2.win_condition = "not_to_the_ship_2";
		break;

		case "not_to_the_ship_2":
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1 = "location";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1.location = "Cuba_port";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition = "to_ship_of_Bernardo_Gamboa";
		break;

		case "to_the_ship":
			DoQuestReloadToLocation("Gamboa_ship", "reload", "locator2", "to_the_ship_2");
		break;

		case "to_the_ship_2":
			LAi_SetActorType(pchar);
// KK -->
			if (!CharacterIsDead(characterFromID("Bernardo Gamboa"))) {
				LAi_SetActorType(characterFromID("Bernardo Gamboa"));
				LAi_ActorFollow(pchar, characterFromID("Bernardo Gamboa"), "", 1.5);
				LAi_ActorFollow(characterFromID("Bernardo Gamboa"), pchar, "to_the_ship_3", 1.5);
			} else {
				LAi_SetActorType(characterFromID("Corentin Lucay"));
				LAi_ActorFollow(pchar, characterFromID("Corentin Lucay"), "", 1.5);
				LAi_ActorFollow(characterFromID("Corentin Lucay"), pchar, "to_the_ship_3", 1.5);
			}
// <-- KK
		break;

		case "to_the_ship_3":
			LAi_type_actor_Reset(pchar);
// KK -->
			if (!CharacterIsDead(characterFromID("Bernardo Gamboa"))) {
				LAi_ActorWaitDialog(pchar, characterFromID("Bernardo Gamboa"));
				LAi_ActorDialog(characterFromID("Bernardo Gamboa"), pchar, "", 2.0, 1.0);
			} else {
				LAi_ActorWaitDialog(pchar, characterFromID("Corentin Lucay"));
				LAi_ActorDialog(characterFromID("Corentin Lucay"), pchar, "", 2.0, 1.0);
			}
// <-- KK
		break;

		case "from_the_ship":
			DoQuestReloadToLocation("Cuba_port", "reload", "Sea_2_back", "not_to_the_ship");
		break;

		case "back_to_the_port":
			DoQuestReloadToLocation("Cuba_port", "reload", "Sea_2_back", "player_back");
			if (characters[getcharacterindex("Sumbhajee Aid1")].quest.Sumbhajee == "good_2_complete")
			{LAi_QuestDelay("guard_at_havana", 0.0);}
		break;

		case "bad_fight_in_ship":
// KK -->
			PChar.quest.BlazeKilledFightingWithGamboa.win_condition.l1 = "NPC_Death";
			PChar.quest.BlazeKilledFightingWithGamboa.win_condition.l1.character = PChar.id;
			PChar.quest.BlazeKilledFightingWithGamboa.win_condition = "BlazeKilledFightingWithGamboa";
// <-- KK
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Bernardo Gamboa"), "PIRATES_ON_GAMBOA_SHIP");
			LAi_group_MoveCharacter(characterFromID("Corentin Lucay"), "PIRATES_ON_GAMBOA_SHIP");
			LAi_group_FightGroups("PIRATES_ON_GAMBOA_SHIP", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_ON_GAMBOA_SHIP", "kill_him_all_in_gamboa_ship_complete");
		break;

// KK -->
		case "BlazeKilledFightingWithGamboa":
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1 = "location";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1.location = "Cuba_port";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition = "to_ship_of_Bernardo_Gamboa";
			LAi_group_RemoveCheck("PIRATES_ON_GAMBOA_SHIP");
			if (CharacterIsDead(characterFromID("Bernardo Gamboa"))) {
				ChangeCharacterAddressGroup(characterFromID("Corentin Lucay"), "Gamboa_ship", "goto", "goto4");
				characters[GetCharacterIndex("Corentin Lucay")].Dialog.Filename = "Bernardo Gamboa_dialog.c";
				characters[GetCharacterIndex("Corentin Lucay")].Dialog.CurrentNode = "you_again";
			} else {
				LAi_group_MoveCharacter(characterFromID("Bernardo Gamboa"), "QC_CITIZENS");
				characters[GetCharacterIndex("Bernardo Gamboa")].Dialog.CurrentNode = "you_again";
			}
			if (!CharacterIsDead(characterFromID("Corentin Lucay"))) LAi_group_MoveCharacter(characterFromID("Corentin Lucay"), "QC_CITIZENS");
			characters[GetCharacterIndex("Sumbhajee Aid1")].quest.Sumbhajee = "help_begin";
		break;
// <-- KK

		case "kill_him_all_in_gamboa_ship_complete":
			LAi_QuestDelay("kill_him_all_in_gamboa_ship_2_complete", 2.0);
		break;

		case "kill_him_all_in_gamboa_ship_2_complete":
			AddQuestRecord("Sumbhajee", 3);
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "Pusasn_in_the_ship";
			LAi_ActorSelfDialog(pchar, "player_back");
		break;

		case "Pusasn_in_the_ship":
			LAi_fade("Pusasn_in_the_ship_2", "");
		break;

		case "Pusasn_in_the_ship_2":
			ChangeCharacterAddress(characterFromID("Sumbhajee Aid2"), "Gamboa_ship", "goto2");
			LAi_SetActorType(characterFromID("Sumbhajee Aid2"));
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Sumbhajee Aid2"));
			LAi_ActorDialog(characterFromID("Sumbhajee Aid2"), pchar, "player_back", 2.0, 1.0);
		break;

		case "talk_in_gamboa_ship":
			LAi_Type_Actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Corentin Lucay"));
			LAi_SetActorType(characterFromID("Corentin Lucay"));
			LAi_ActorDialog(characterFromID("Corentin Lucay"), pchar, "", 2.0, 1.0);
		break;

		case "second_talk_in_gamboa_ship":
			LAi_Type_Actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Bernardo Gamboa"));
			LAi_ActorDialog(characterFromID("Bernardo Gamboa"), pchar, "", 2.0, 1.0);
		break;

		case "gamboa_died":
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Bernardo Gamboa"), "PIRATES_ON_GAMBOA_SHIP");
			LAi_group_MoveCharacter(characterFromID("Corentin Lucay"), LAI_GROUP_PLAYER);
			LAi_group_FightGroups("PIRATES_ON_GAMBOA_SHIP", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_ON_GAMBOA_SHIP", "gamboa_died_complete");
		break;

		case "gamboa_died_complete":
			LAi_QuestDelay("gamboa_died_2_complete", 1.0);
		break;

		case "gamboa_died_2_complete":
			if (!LAi_isDead(characterFromID("Corentin Lucay")))
			{
				characters[GetCharacterIndex("Corentin Lucay")].dialog.currentnode = "three";
				LAi_SetActorType(characterFromID("Corentin Lucay"));
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Corentin Lucay"));
				LAi_ActorDialog(characterFromID("Corentin Lucay"), pchar, "player_back", 2.0, 1.0);
				AddQuestRecord("Sumbhajee", 4);
			}
			else
			{
				LAi_QuestDelay("Pusasn_in_the_ship", 1.0);
			}
		break;

		case "guard_at_havana":
			changeCharacterAddressGroup(characterFromID("Havana Prison Commendant"), "Cuba_port", "goto", "goto_34");
			changeCharacterAddressGroup(characterFromID("Sp_pris_guard1"), "Cuba_port", "goto", "goto_33");
			changeCharacterAddressGroup(characterFromID("Sp_pris_guard2"), "Cuba_port", "goto", "goto_32");
			//LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Havana Prison Commendant"));
			LAi_SetActorType(characterFromID("Sp_pris_guard1"));
			LAi_SetActorType(characterFromID("Sp_pris_guard2"));

			//LAi_ActorDialog(characterFromID("Havana Prison Commendant"), pchar, "player_back", 3.0, 1.0);
			LAi_ActorDialog(characterFromID("Havana Prison Commendant"), pchar, "", 0.0, 0.0);
			LAi_ActorFollow(characterFromID("Sp_pris_guard1"), pchar, "", 3.0);
			LAi_ActorFollow(characterFromID("Sp_pris_guard2"), pchar, "", 3.0);
		break;

		case "kill_Commendant":
			LAi_group_MoveCharacter(characterFromID("Havana Prison Commendant"), "SPANISH_PRISON");
			LAi_group_MoveCharacter(characterFromID("Sp_pris_guard1"), "SPANISH_PRISON");
			LAi_group_MoveCharacter(characterFromID("Sp_pris_guard2"), "SPANISH_PRISON");
			LAi_group_FightGroups("SPANISH_PRISON", LAI_GROUP_PLAYER, true);

			LAi_SetActorType(pchar);
			LAi_ActorAttack(PChar, CharacterFromID("Havana Prison Commendant"), "");

			LAi_QuestDelay("fight_with_Spanish_Guards", 2.0);
		break;

		case "fight_with_Spanish_Guards":
			LAi_QuestDelay("fight_with_Spanish_Guards2", 0.5);
		break;

		case "fight_with_Spanish_Guards2":
			LAi_SetActorType(characterFromID("Havana Prison Commendant"));
			Lai_KillCharacter(characterFromID("Havana Prison Commendant"));
			LAi_SetPlayerType(pchar);
			LAi_group_SetCheck("SPANISH_PRISON", "kill_all_officers_spain");
		break;

		case "kill_all_officers_spain":
			//Locations[FindLocation("Muelle_shore")].reload.l2.disable = 0;
			AddQuestRecord("sumbhajee", 5);
			pchar.quest.sri_reset_prison_commendant.win_condition.l1 = "ExitFromLocation";
			pchar.quest.sri_reset_prison_commendant.win_condition.l1.location = "Cuba_port";
			pchar.quest.sri_reset_prison_commendant.win_condition = "sri_reset_prison_commendant";
		break;

		case "sri_reset_prison_commendant":
			changeCharacterAddressGroup(characterFromID("Havana Prison Commendant"), "Havana_prison", "sit", "sit1");
			LAi_SetSitType(characterFromID("Havana Prison Commendant"));
		break;
//Sri Sumbhajee Angria

//Ammand the Corsair
		case "Church_help":
			SetEnterLocationQuest("redmond_church", "church_start_check", 0);
		break;

		case "church_start_check":
			if(makeint(PChar.rank) >= 1)
			{
				characters[GetCharacterIndex("Father Bernard")].quest.church_help = "";
			}
		break;

		case "Ammand_in_Greenford":
			changeCharacterAddressGroup(characterFromID("Ammand"), "Greenford_town", "goto", "goto9");
			LAi_SetActorType(characterFromID("Ammand"));
			LAi_ActorDialog(characterFromID("Ammand"), pchar, "", 2.0, 1.0);
		break;

		case "Waiting_(Read_questbook)":
			LAi_ActorGoToLocator(characterFromID("Ammand"), "officers", "reload15_3", "Ammand_and_me_to_church", 0);
		break;

		case "Ammand_and_me_to_church":
			Characters[GetCharacterIndex("Ammand")].dialog.currentnode = "Outside_Church";
			LAi_SetActorType(characterFromID("Ammand"));
			LAi_ActorDialog(characterFromID("Ammand"),PChar,"",10.0,1.0);
		break;

		case "Ammand_being_sneaky":
			LAi_ActorGoToLocation(CharacterFromID("Ammand"), "reload", "reload30", "none","","","", 100.0);
			AddQuestRecord("Ammand", 16);
		break;

		case "Yedam_kinne_attack":
			AddQuestRecord("Ammand", 11);
			LAi_group_MoveCharacter(characterFromID("Yedam Kinne"), "YedamKine");
			LAi_SetActorType(characterFromID("Yedam Kinne"));
			LAi_ActorAttack(characterFromID("Yedam Kinne"), pchar, "");
			characters[GetCharacterIndex("Father bernard")].quest.church_help = "bad_dautch";
		break;

		case "Ammand_on_Redmond":
			if(GetAttribute(pchar, "Jack") == "Pirate") {GiveModel2Player("Jack",true);}
			if(GetAttribute(pchar, "Jack") == "Met_Tia") {GiveModel2Player("Depp",true);}
			if(GetAttribute(pchar, "Jack") == "Early_days") {GiveModel2Player("47youngjack",true);}

			changeCharacterAddressGroup(CharacterFromID("Ammand"), "Redmond_port", "goto", "goto_45"); 
			Characters[GetCharacterIndex("Ammand")].dialog.currentnode = "On_Jetty";
			LAi_SetActorType(characterFromID("Ammand"));
			LAi_ActorDialog(characterFromID("Ammand"),PChar,"",10.0,1.0);
		break;

		case "Hit_Ammand_and_run":
			LAi_SetActorType(pchar);
			//LAi_SetActorType(characterFromID("Ammand"));
			LAi_ActorAnimation(pchar, "attack_2", "running_from_Ammand", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
		break;

		case "running_from_Ammand":
			Lai_KillCharacter(characterFromID("Ammand"));
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(pchar, "goto", "goto_17", "got_away_Ammand", 15);
		break;

		case "got_away_Ammand":
			AddQuestRecord("Ammand", 17);

			LAi_SetPlayerType(pchar);
			changeCharacterAddressGroup(CharacterFromID("Ammand"), "none", "", "");
		break;

		case "father_bernard_church_help_bad_2":
			AddDialogExitQuest("father_bernard_church_help_bad_2");
			characters[getCharacterIndex("father bernard")].quest.church_help = "done";
			AddQuestRecord("Ammand", 14);
			CloseQuestHeader("Ammand");
			AddMoneyToCharacter(pchar, 2500);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 3000); }
			else { AddPartyExp(pchar, 3000); }
			ChangeCharacterAddress(characterFromID("Father Jerald"), "none", "none");
			ChangeCharacterAddress(characterFromID("Gilbert Ballester"), "Greenford_Church", "goto11");
			LAi_SetStayType(characterFromID("Gilbert Ballester"));
			TakeItemFromCharacter(pchar, "pornushka");
		break;
//Ammand the Corsair

//Captain Sao Feng
		case "to_muelle_for_letter":
			bQuestDisableAllCommands = true; // KK
			pchar.location.from_sea = "Muelle_shore";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("to_muelle_for_letter_2", 3.0);
		break;

		// --> Swindler 050927
		// Here's a syntax error:
		// case "to_muelle_for_letter_2": 04.06.2003 14:43
		case "to_muelle_for_letter_2":
		// Swindler <--
			DoReloadFromSeaToLocation("Muelle_shore", "reload", "reload2");
			Locations[FindLocation("Muelle_shore")].reload.l2.disable = 1;
			pchar.quest.mystery_men_meeting_us.win_condition.l1 = "location";
			pchar.quest.mystery_men_meeting_us.win_condition.l1.location = "Muelle_shore";
			pchar.quest.mystery_men_meeting_us.win_condition = "mystery_men_meeting_us";
		break;

		case "mystery_men_meeting_us":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			bQuestDisableAllCommands = false; // KK
			LAi_SetHP(characterFromID("Mystery_Man_01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_02"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_03"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("Mystery_Man_01"), "Muelle_shore", "goto12");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_02"), "Muelle_shore", "reload", "reload3");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_03"), "Muelle_shore", "reload", "reload3");
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Mystery_Man_01"));
			LAi_SetActorType(characterFromID("Mystery_Man_02"));
			LAi_SetActorType(characterFromID("Mystery_Man_03"));
			LAi_ActorDialog(characterFromID("Mystery_Man_01"), pchar, "player_back", 3.0, 1.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_02"), pchar, "", 3.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_03"), pchar, "", 3.0);
			AddQuestRecord("Sao Feng", 9);
		break;

		case "fight_with_mystery_mens_in_muelle_shore":
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_01"), "ANIMISTS_IN_SHORE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_02"), "ANIMISTS_IN_SHORE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_03"), "ANIMISTS_IN_SHORE");
			LAi_group_FightGroups("ANIMISTS_IN_SHORE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANIMISTS_IN_SHORE", "kill_all_animists_in_muelle_shore");
		break;

		case "kill_all_animists_in_muelle_shore":
			Locations[FindLocation("Muelle_shore")].reload.l2.disable = 0;
			GiveItem2Character(pchar, "animists_amulet");
			AddQuestRecord("Sao Feng", 10);
		break;

		case "i_give_first_letter_to_animists":
			pchar.quest.animists = "letter_to_domingues_opened";
			AddMoneyToCharacter(pchar, 1000);
			OfficersReaction("bad");
			Locations[FindLocation("Muelle_shore")].reload.l2.disable = 0;
			characters[GetCharacterIndex("Mystery_Man_01")].location = "none";
			characters[GetCharacterIndex("Mystery_Man_02")].location = "none";
			characters[GetCharacterIndex("Mystery_Man_03")].location = "none";
			AddQuestRecord("Sao Feng", 11);
		break;

		case "prepare_for_barkue":
			AddQuestRecord("Sao Feng", 14);
			pchar.quest.to_greenford_for_montanez.win_condition.l1 = "location";
			pchar.quest.to_greenford_for_montanez.win_condition.l1.location = "Cuba";
			pchar.quest.to_greenford_for_montanez.win_condition = "to_greenford_for_montanez_complete";

		//	LAi_SetHP(characterFromID("Mystery_man_01"), 80.0, 80.0);
		//	LAi_SetHP(characterFromID("Mystery_man_02"), 80.0, 80.0);

			//SetCharacterRelation(GetCharacterIndex("Mergildo Hurtado"),GetMainCharacterIndex(), RELATION_FRIEND);
			//SetCharacterRelation(GetCharacterIndex("Mystery_Man_01"),GetMainCharacterIndex(), RELATION_ENEMY);

			Group_CreateGroup("Mergildo Hurtado");
			Group_AddCharacter("Mergildo Hurtado", "Mergildo Hurtado");
			Group_SetGroupCommander("Mergildo Hurtado", "Mergildo Hurtado");
			Group_SetPursuitGroup("Mergildo Hurtado", PLAYER_GROUP);
			// boal -->
			//Group_SetAddress("Mergildo Hurtado", "Oxbay", "", "");
			LAi_SetHP(characterFromID("Mergildo Hurtado"), 80.0, 80.0);
			Group_SetAddress("Mergildo Hurtado", "Cuba", "Quest_ships", "Quest_ship_12");

            // boal <--
			Group_CreateGroup("ANIMISTS");
			Group_AddCharacter("ANIMISTS", "Mystery_Man_04");
			Group_AddCharacter("ANIMISTS", "Mystery_Man_05");
			Characters[GetCharacterIndex("Mystery_Man_04")].recognized = true; // PB: Ensure they're hostile!
			Characters[GetCharacterIndex("Mystery_Man_05")].recognized = true; // PB: Ensure they're hostile!
            // boal -->
            LAi_SetHP(characterFromID("Mystery_man_04"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_man_05"), 80.0, 80.0);
			SetCharacterRelation(GetCharacterIndex("Mergildo Hurtado"),GetMainCharacterIndex(), RELATION_FRIEND);
			SetCharacterRelation(GetCharacterIndex("Mystery_Man_04"),GetMainCharacterIndex(), RELATION_ENEMY);
            // boal <--
			Group_SetGroupCommander("ANIMISTS", "Mystery_man_04");
			Group_SetPursuitGroup("ANIMISTS", PLAYER_GROUP);
			// boal -->
			//Group_SetAddress("ANIMISTS", "Oxbay", "", "");
			Group_SetAddress("ANIMISTS", "Cuba", "Quest_ships", "Quest_ship_12");
			// boal <--

			//Character_SetAbordageEnable(characterFromID("Mystery_Man_04"), false);
			//Character_SetAbordageEnable(characterFromID("Mystery_Man_05"), false);

			Group_LockTask("ANIMISTS");
			Group_LockTask("Mergildo Hurtado");
			Group_SetTaskAttack("ANIMISTS", "Mergildo Hurtado", true);
			Group_SetTaskRunAway("Mergildo Hurtado");
			UpdateRelations();
		break;

		case "to_greenford_for_montanez_complete":
			DoQuestCheckDelay("to_greenford_for_montanez_complete1_5", 1.0);
		break;

		case "to_greenford_for_montanez_complete1_5":
			QDeck = GetCharacterShipQDeck(pchar);
			DoQuestReloadToLocation(QDeck, "rld", "startloc", "To_Do_or_Not_To_Do");
		break;

		case "To_Do_or_Not_To_Do":
			SetCharacterToNearLocatorFromMe("Larry", 3);

			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Spain_Flag";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "To_Do_or_Not_To_Do2":
			LAi_SetActorType(characterFromID("Larry"));
			Characters[GetCharacterIndex("Larry")].dialog.filename = "Mergildo Hurtado_dialog.c";
			Characters[GetCharacterIndex("Larry")].dialog.currentnode = "Aye_Captain";
			LAi_ActorDialog(characterFromID("Larry"), pchar, "player_back", 0.0, 0.0);
		break;

		case "To_Do":
			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_1", true);
			QuestToSeaLogin_Launch();

			HoistFlag(SPAIN);
			DoQuestCheckDelay("to_greenford_for_montanez_complete2", 1.0);
		break;

		case "Not_to_Do":
			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_5", true);
			QuestToSeaLogin_Launch();

			DoQuestCheckDelay("to_greenford_for_montanez_complete2", 1.0);
		break;

		case "to_greenford_for_montanez_complete2":
			ChangeCharacterAddress(CharacterFromID("Larry"), "none", "");			
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Cuba", false);// TIH typo fix Oct31'06

            // boal -->
            LAi_SetHP(characterFromID("Mystery_man_04"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_man_05"), 80.0, 80.0);
            // boal <--

			pchar.quest.saints_barkue_drown.win_condition.l1 = "NPC_Death";
			pchar.quest.saints_barkue_drown.win_condition.l1.character = "Mergildo Hurtado";
			pchar.quest.saints_barkue_drown.win_condition = "saints_barkue_drown_complete";

			//pchar.quest.animists_drown.win_condition.l1 = "NPC_Death";
			//pchar.quest.animists_drown.win_condition.l1.character = "Mystery_Man_04";
			//pchar.quest.animists_drown.win_condition.l2 = "NPC_Death";
			//pchar.quest.animists_drown.win_condition.l2.character = "Mystery_Man_05";
// KK -->
			//pchar.quest.animists_drown.win_condition.l3 = "location";
			//pchar.quest.animists_drown.win_condition.l3.location = "Cuba";
// <-- KK
			//pchar.quest.animists_drown.win_condition = "animists_drown_complete";

			Pchar.quest.animists_drown.win_condition.l1 = "Ship_HP";
			Pchar.quest.animists_drown.win_condition.l1.character = "Mystery_Man_04";
			Pchar.quest.animists_drown.win_condition.l1.quantity = 0;
			Pchar.quest.animists_drown.win_condition.l1.operation = "=";
			Pchar.quest.animists_drown.win_condition.l2 = "Ship_HP";
			Pchar.quest.animists_drown.win_condition.l2.character = "Mystery_Man_05";
			Pchar.quest.animists_drown.win_condition.l2.quantity = 0;
			Pchar.quest.animists_drown.win_condition.l2.operation = "=";
			Pchar.quest.animists_drown.win_condition = "animists_drown_complete";
		break;

		case "saints_barkue_drown_complete":
			pchar.quest.animists_drown.over = "yes";
			Group_LockTask("ANIMISTS");
			Group_SetTaskRunAway("ANIMISTS");
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Cuba", true);
			pchar.quest.animists = "barkue_drown";
			AddQuestRecord("Sao Feng", 15);
		break;

		/*case "prepare_for_barkue":
			pchar.quest.to_greenford_for_montanez.win_condition.l1 = "location";
			pchar.quest.to_greenford_for_montanez.win_condition.l1.location = "Oxbay";
			pchar.quest.to_greenford_for_montanez.win_condition = "animists_drown_complete";
		break;*/

		case "animists_drown_complete":
			bQuestDisableAllCommands = true; // KK
			DoQuestCheckDelay("animists_drown_complete_2", 5.0);
			AddQuestRecord("Sao Feng", 16);
		break;

		case "animists_drown_complete_2":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Cuba", true);
			//if (GetNationRelation2MainCharacter(ENGLAND) == RELATION_ENEMY)
			if (GetAttribute(pchar, "Colours") == "1")
			{
				pchar.location.from_sea = "Santiago_port";
				SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
				PlaceFleetNearShore(pchar.location.from_sea); // KK
			}
			else
			{
				pchar.location.from_sea = "Cuba_Shore_02";
				SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
				PlaceFleetNearShore(pchar.location.from_sea); // KK
			}
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			bQuestDisableAllCommands = false;
			Group_SetAddress("Mergildo Hurtado", "none", "", "");
			DoQuestReloadToLocation("Santiago_tavern", "sit", "sit6", "speak_with_Mergilo"); //Changed place by Levis to prevent error
			ChangeCharacterAddressGroup(characterFromID("Mergildo Hurtado"), "Santiago_tavern", "sit", "sit7"); //Changed place by Levis to prevent error
		break;

		case "speak_with_Mergilo":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			LAi_SetSitType(characterFromID("Mergildo Hurtado"));
			LAi_ActorDialogNow(pchar, characterFromID("Mergildo Hurtado"), "", 1.0);
		break;

		case "to_barkue_complete":
			// boal -->
			//AddQuestRecord("Sao Feng", 18);
			// boal <--
			DoQuestReloadToLocation(pchar.location.from_sea, "reload", "reload1", "_");
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("Mergildo Hurtado")].location = "Santiago_tavern";
			ChangeCharacterAddress(characterFromID("Mergildo Hurtado"), "none", "");
		break;

		case "to_barkue_too_many_ships":		// GR: if you have too many ships, stand up so you can go to shipyard to dispose of one
			ChangeCharacterAddressGroup(PChar, "Santiago_tavern", "tables", "table5");
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Mergildo Hurtado")].dialog.currentnode = "too_many_ships_recheck";
		break;

		case "oops_ANIMISTS_want_letter_again":
			DisableFastTravel(true);
			pchar.quest.animists_again_meeting_us.win_condition.l1 = "location";
			pchar.quest.animists_again_meeting_us.win_condition.l1.location = "Muelle_town_01"; // CTM
			pchar.quest.animists_again_meeting_us.win_condition = "animists_again_meeting_us_complete";
		break;

		case "animists_again_meeting_us_complete":
// CTM -->
			LAi_SetStayType(pchar);
			LAi_SetHP(characterFromID("Mystery_Man_06"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_07"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_08"), 80.0, 80.0);

			changeCharacterAddressGroup(characterFromID("Mystery_Man_06"), "Muelle_town_01", "goto", "goto74");
			changeCharacterAddressGroup(characterFromID("Mystery_Man_07"), "Muelle_town_01", "goto", "goto76");
			changeCharacterAddressGroup(characterFromID("Mystery_Man_08"), "Muelle_town_01", "goto", "goto73");

			Locations[FindLocation("Muelle_town_01")].vcskip = true;		
			//Locations[FindLocation("Muelle_town_04")].vcskip = true;
// CTM <--
			LAi_SetActorType(CharacterFromID("Mystery_Man_06"));
			LAi_SetActorType(CharacterFromID("Mystery_Man_07"));
			LAi_SetActorType(CharacterFromID("Mystery_Man_08"));
			LAi_ActorDialog(characterFromID("Mystery_Man_06"), pchar, "player_back", 2.0, 1.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_07"), pchar, "", 3.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_08"), pchar, "", 3.0);
		break;

		case "second_fight_with_animists":
			LAi_QuestDelay("second_fight_with_animists_begin", 0.0); // KK
		break;

		case "second_fight_with_animists_begin":
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_06"), "ANIMISTS_IN_MUELLE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_07"), "ANIMISTS_IN_MUELLE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_08"), "ANIMISTS_IN_MUELLE");
			LAi_group_MoveCharacter(characterFromID("second_spaniard_priest"), "PRIESTS");
			LAi_group_FightGroups("ANIMISTS_IN_MUELLE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANIMISTS_IN_MUELLE", "kill_all_animists_in_muelle_town");
		break;

		case "kill_all_animists_in_muelle_town":
			LAi_QuestDelay("kill_all_animists_in_muelle_town_complete", 2.0);
		break;

		case "kill_all_animists_in_muelle_town_complete":
			AddQuestRecord("Sao Feng", 21);
			DeleteAttribute(Locations[FindLocation("Muelle_town_01")], "vcskip"); // CTM
			changeCharacterAddress(characterfromID("padre Domingues"), "none", "");
			changeCharacterAddress(characterfromID("second_spaniard_priest"), "Muelle_church", "goto11");
			DoQuestReloadToLocation("Muelle_church", "goto", "goto7", "to_the_muelle_church_with_letter");  // <-- Cat
		break;

		case "to_the_muelle_church_with_letter":
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "letter_to_father_bernard";
			LAi_ActorSelfDialog(pchar, "player_back");
			//LAi_QuestDelay("to_the_muelle_church_with_letter2", 4.0);
		break;

		case "to_the_muelle_church_with_letter2":
			DisableFastTravel(false);
			characters[GetCharacterIndex("second_spaniard_priest")].dialog.currentnode = "First time";
			LAi_SetActorType(characterFromID("second_spaniard_priest"));
			LAi_ActorWaitDialog(Pchar, characterFromID("second_spaniard_priest"));
			LAi_ActorDialog(characterFromID("second_spaniard_priest"), Pchar, "player_back", 2.0, 1.0);
		break;  //  <-- Cat

		case "father_Gareth_stopping_us":
			Locations[FindLocation("Muelle_church")].reload.l1.go = "Muelle_town_01"; //CTM
			Locations[FindLocation("Muelle_church")].reload.l1.emerge = "reload4";
			pchar.quest.animists = "before_knight";
			TakeItemFromCharacter(pchar, "letter_to_bernard");
			GiveItem2Character(characterFromID("father Gareth"), "blade5");
			EquipCharacterByItem(characterFromID("father Gareth"), "blade5");

			LAi_SetImmortal(characterFromID("father Gareth"), false);
			LAi_SetImmortal(characterFromID("father Bernard"), true);

			LAi_SetActorType(characterFromID("father Gareth"));

			if (characters[GetCharacterIndex("father Gareth")].location == "Redmond_church")
			{
				LAi_ActorDialog(characterFromID("father Gareth"), pchar, "", 2.0, 1.0);
			}
			else
			{
				ChangeCharacterAddressGroup(characterfromid("Father Gareth"), "Redmond_church", "reload", "reload1");
				LAi_ActorDialog(characterFromID("father Gareth"), pchar, "", 2.0, 1.0);
			}
		break;

		case "fight_with_animists_in_church":
			AddQuestRecord("Sao Feng", 22);
			LAi_LocationFightDisable(&locations[FindLocation("redmond_church")], false);

			LAi_SetHP(characterFromID("Mystery_Man_09"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_10"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_11"), 80.0, 80.0);
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_09"), "Redmond_Church", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_10"), "Redmond_Church", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_11"), "Redmond_Church", "reload", "reload1");

			LAi_group_MoveCharacter(characterFromID("Mystery_Man_09"), "ANIMISTS_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_10"), "ANIMISTS_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_11"), "ANIMISTS_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("father Gareth"), "ANIMISTS_IN_CHURCH");
			LAi_group_FightGroups("ANIMISTS_IN_CHURCH", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANIMISTS_IN_CHURCH", "kill_all_ANIMISTS_in_church_complete");
		break;

		case "kill_all_ANIMISTS_in_church_complete":
			ChangeCharacterAddress(characterFromID("Mystery_Man_09"), "none", "");
			ChangeCharacterAddress(characterFromID("Mystery_Man_10"), "none", "");
			ChangeCharacterAddress(characterFromID("Mystery_Man_11"), "none", "");
			ChangeCharacterAddress(characterFromID("father Gareth"), "none", "");
			LAi_LocationFightDisable(&locations[FindLocation("redmond_church")], true);
			pchar.quest.ANIMISTS = "kill_all_ANIMISTS_in_church";
			LAi_SetActorType(characterFromID("father Bernard"));
			LAi_ActorDialog(characterFromID("father Bernard"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("father Bernard"));
			characters[GetCharacterIndex("father Bernard")].dialog.currentnode = "kill_all_ANIMISTS_in_churcha";

			if (GetAttribute(PChar, "Colours") == "1")
			{
				pchar.quest.Mercer_False.win_condition.l1 = "location";
				pchar.quest.Mercer_False.win_condition.l1.location = "Redmond_Town_03";
				pchar.quest.Mercer_False.win_condition = "Mercer_False";
			}
		break;

		case "meeting_with_Jaoquin_De_Masse":
			ChangeCharacterAddressGroup(characterFromID("Jaoquin de masse"), "Redmond_church", "reload", "reload1");
			LAi_SetActorType(characterFromID("Jaoquin de masse"));
			LAi_ActorDialog(characterFromID("Jaoquin de masse"), pchar, "", 2.0, 1.0);
		break;

		case "masse_becomes_officer":
			AddQuestRecord("Sao Feng", 24);
			AddPassenger(pchar, characterFromID("Jaoquin de masse"), 0);
			Characters[getCharacterIndex("Jaoquin de masse")].location = "none";
			LAi_SetStayType(characterFromID("father Bernard"));
		break;

		case "Mercer_False":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto18"); // PB
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, CharacterFromID("Mr Mercer"), "", 10);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "goto", "goto17"); // PB
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, CharacterFromID("Mr Mercer"), "", 10);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto14"); // PB
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, CharacterFromID("Mr Mercer"), "", 10);

			ChangeCharacterAddressGroup(CharacterFromID("Mr Mercer"), "Redmond_Town_03", "goto", "goto15");
			LAi_SetActorType(characterFromID("Mr Mercer"));
			Characters[GetCharacterIndex("Mr Mercer")].dialog.currentnode = "False Colours";
			LAi_ActorDialog(characterFromID("Mr Mercer"), pchar, "", 100.0, 100.0);
		break;

		case "Mercer_False_surv":
			DoQuestReloadToLocation("Redmond_Town_04", "goto", "goto_39", "Mercer_False_surv_talk");
		break;

		case "Mercer_False_die":
			DoQuestReloadToLocation("Redmond_Prison", "goto", "goto9", "Mercer_False_die_talk");

			AddQuestRecord("Sao Feng", 5);
		break;

		case "Mercer_False_surv_talk":
			ChangeCharacterAddressGroup(characterFromID("Mr Mercer"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Mergildo Hurtado"), "Redmond_Town_04", "goto", "goto_31");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto_38"); // PB
			LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "Lay_1", "", -1);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "goto", "goto_35"); // PB
			LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "Lay_1", "", -1);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto_33"); // PB
			LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "Lay_1", "", -1);

			LAi_SetActorType(characterFromID("Mergildo Hurtado"));
			Characters[GetCharacterIndex("Mergildo Hurtado")].dialog.currentnode = "False Colours";
			LAi_ActorDialog(characterFromID("Mergildo Hurtado"), pchar, "", 100.0, 100.0);
		break;

		case "Mercer_False_surv_talk2":
			LAi_ActorGoToLocation(characterFromID("Mergildo Hurtado"), "reload", "reload_4_1_back", "none", "", "", "", 0.0);
		break;

		case "Mercer_False_die_talk":
			ChangeCharacterAddressGroup(characterfromID("Cutler Beckett"),"Redmond_prison", "goto", "goto22");
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			LAi_ActorGoToLocator(characterFromID("Cutler Beckett"), "reload", "reload12", "Mercer_False_die_talk2", -1);
			ChangeCharacterAddressGroup(characterfromID("Mr Mercer"),"Redmond_prison", "goto", "goto22");
			LAi_SetActorType(characterFromID("Mr Mercer"));
			LAi_ActorFollow (characterFromID("Mr Mercer"), CharacterFromID("Cutler Beckett"), "", 10);
		break;

		case "Mercer_False_die_talk2":
			LAi_SetActorType(characterFromID("Cutler Beckett"));
			Characters[GetCharacterIndex("Cutler Beckett")].dialog.currentnode = "False Colours";
			LAi_ActorDialog(characterFromID("Cutler Beckett"), pchar, "", 1.0, 1.0);
		break;

		case "Mercer_False_die_talk3":
			pchar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "mutiny");
		break;

		case "speak_with_jordano":
			AddQuestRecord("Sao Feng", 25);
			Locations[FindLocation("Muelle_town_01")].vcskip = true; // NK
			ChangeCharacterAddress(characterFromID("Jordano"), "Muelle_town_01", "goto18");
			LAi_SetActorType(characterFromID("Jordano"));
			LAi_ActorDialog(characterFromID("Jordano"), pchar, "", 5.0, 1.0);
		break;

		case "speak_with_jordano2":  // --> edited by Cat for Animists Quest fix
			DoQuestCheckDelay("speak_with_jordano3", 25.0);
		break;

		case "speak_with_jordano3":
			ChangeCharacterAddress(characterFromID("Jordano"), "none", "");
		break;  // <-- edited by Cat for Animists Quest fix

		case "Story_freedom_letter":
			ChangeCharacterAddress(characterFromID("Teacher"), "", "");
			pchar.quest.with_teacher_to_muelle.win_condition.l1 = "location";
			pchar.quest.with_teacher_to_muelle.win_condition.l1.location = "Turks";
			pchar.quest.with_teacher_to_muelle.win_condition = "with_teacher_to_muelle";
		break;   // <--Cat

		case "wait_in_church_for_letters":
			pchar.quest.ANIMISTS = "to_prison_for_teacher_2";
			LAi_Fade("", "");
			LAi_SetActorType(characterFromID("father Bernard"));
			LAi_ActorDialog(characterFromID("father Bernard"), pchar, "bernard_back_to_stay_type", 2.0, 1.0);
		break;

		case "bernard_back_to_stay_type":
			LAi_SetStayType(characterFromID("father Bernard"));
		break;

		case "to_jail_with_eng_uni":
			GiveModel2Player("47_Ltsparrow", true);
		break

		case "mystery_man_to_prison":
			//RestoreCharacter(characterFromID("Teacher")); // KK
			LAi_SetStayType(characterFromID("Teacher"));
			LAi_SetHP(characterFromID("Teacher"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("Teacher"), "Greenford_prison", "goto9");
		break;

		case "teacher_died":
			//Island_SetReloadEnableLocal("IslaMuelle", "reload_2", true);
			LAi_KillCharacter(characterFromID("Teacher"));
			//ChangeCharacterAddressGroup(characterFromID("Teacher"), "none", "", "");
			//characterFromID("Teacher").location = "none";
			//Locations[FindLocation("muelle_ANIMISTS")].locators_radius.goto.goto37 = 2.2;
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1 = "locator";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.location = "Turks_Cavern_01";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator_group = "goto";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator = "goto37";
			pchar.quest.final_battle_with_dark_teacher.win_condition = "final_battle_with_dark_teacher";
			LAi_group_FightGroups("ANIMISTS_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_QuestDelay("Story_Domingues_to_cave", 0.0); //CTM
		break;

		case "exit_from_prison_with_teacher":
			LeaveService(PChar, ENGLAND, true); // RM
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "prison_commander_captured":
			pchar.quest.ANIMISTS = "force_freedom";
			LAi_SetStayType(characterFromID("Teacher"));
			LAi_SetHP(characterFromID("Teacher"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("Teacher"), "Greenford_prison", "goto9");
		break;

		case "with_teacher_to_muelle":
			GiveModel2Player("Jack", true);

			//ChangeCharacterAddress(characterFromID("Teacher"), "denielle_deck", "goto1");
			DoQuestCheckDelay("with_teacher_to_muelle_2", 1.0);
			DisableFastTravel(true);
			DisableMenuLaunch(true);
		break;

		case "with_teacher_to_muelle_2":
			QDeck = GetCharacterShipQDeck(pchar);
			pchar.quest.ANIMISTS = "with_teacher_on_ship";
			DoQuestReloadToLocation(QDeck, "rld", "startloc", "with_teacher_to_muelle_21");
		break;

		case "with_teacher_to_muelle_21":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			SetCharacterToNearLocatorFromMe("Teacher", 20);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Teacher"));
			//ChangeCharacterAddress(characterFromID("Teacher"), "denielle_deck", "goto6");
			LAi_SetActorType(characterFromID("Teacher"));
			LAi_ActorDialog(characterFromID("Teacher"), pchar, "with_teacher_to_muelle_3", 100.0, 100.0);
		break;

		case "with_teacher_to_muelle_3":
			pchar.quest.ANIMISTS = "with_teacher_in_tavern";
			ChangeCharacterAddress(characterFromID("Teacher"), "Turks_tavern_upstairs", "goto4");
			DoQuestReloadToLocation("Turks_tavern_upstairs", "goto", "goto3", "with_teacher_to_muelle_4");
			if (GetNationRelation2MainCharacter(PIRATE) != RELATION_ENEMY)
			{
				pchar.location.from_sea = "Turks_port";
				SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			}
			else
			{
				pchar.location.from_sea = "Turks_Lighthouse";
				SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			}
		break;

		case "with_teacher_to_muelle_4":
			LAi_ActorDialog(characterFromID("Teacher"), pchar, "with_teacher_to_muelle_5", 2.0, 1.0);
		break;

		case "with_teacher_to_muelle_5":
			LAi_LocationFightDisable("Turks_tavern_upstairs", false);
			LAi_ActorAttack(characterFromID("Teacher"), pchar, "");
			Lai_SetPlayerType(pchar);
			pchar.quest.destroy_ANIMISTS.win_condition.l1 = "NPC_Death";
			pchar.quest.destroy_ANIMISTS.win_condition.l1.character = "Teacher";
			pchar.quest.destroy_ANIMISTS.win_condition = "to_ANIMISTS";
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "ANIMISTS_SOLDIERS", true);
			Locations[FindLocation("Turks_Cavern_01")].locators_radius.goto.goto37 = 2.2;

			LAi_QuestDelay("Story_Domingues_to_cave", 0.0); //CTM
		break;

		case "to_ANIMISTS":
			//Island_SetReloadEnableLocal("IslaMuelle", "reload_2", true);
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1 = "locator";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.location = "Turks_Cavern_01";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator_group = "goto";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator = "goto37";
			pchar.quest.final_battle_with_dark_teacher.win_condition = "final_battle_with_dark_teacher";
			LAi_group_FightGroups("ANIMISTS_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "final_battle_with_dark_teacher":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Dark teacher"));
			LAi_ActorDialogNow(characterFromID("Dark teacher"), pchar, "player_back", 1.0);
			pchar.quest.destroy_ANIMISTS_complete.win_condition.l1 = "NPC_Death";
			pchar.quest.destroy_ANIMISTS_complete.win_condition.l1.character = "Dark Teacher";
			pchar.quest.destroy_ANIMISTS_complete.win_condition = "destroy_ANIMISTS_complete";
		break;

		case "dark_teacher_WANT_kill_YOU":
			LAi_SetWarriorType(characterFromID("Dark teacher"));
			LAi_group_MoveCharacter(characterFromID("Dark teacher"), "LURKING_BOSS");
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "LURKING_BOSS", true);
			//LAi_ActorAttack(characterFromID("Dark teacher"), pchar, "");
		break;

		case "destroy_ANIMISTS_complete":
			//pchar.quest.ANIMISTS = "completed";
			pchar.quest.ANIMISTS = "comp";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 50000);
				AddPartyExpChar(pchar, "Sneak", 5000);
			}
			else { AddPartyExp(pchar, 50000); }
			ChangeCharacterReputation(pchar, 10);
			//pchar.reputation = makeint(pchar.reputation) +10;
			//GiveItem2Character(pchar, "blade20");

			LAi_QuestDelay("destroy_ANIMISTS_complete_2", 6.0);
		break;

		case "destroy_ANIMISTS_complete_2":
			//pchar.quest.ANIMISTS = "domingues_dialog";
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "Animists_killed";
			LAi_ActorSelfDialog(pchar, "player_back");

			pchar.quest.fight_with_mefisto.win_condition.l1 = "location";
			pchar.quest.fight_with_mefisto.win_condition.l1.location = "Turks";
			pchar.quest.fight_with_mefisto.win_condition = "fight_with_mefisto";
			//AddQuestRecord("Sao Feng", 36);
		break;

		case "fight_with_mefisto":
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Turks", false);

			Group_CreateGroup("Mefisto");
			Group_AddCharacter("Mefisto", "Dark Captain");
			Group_SetGroupCommander("Mefisto", "Dark Captain");
			Group_SetPursuitGroup("Mefisto", PLAYER_GROUP);
			Group_SetTaskAttack("Mefisto", PLAYER_GROUP, true);
			Group_SetAddress("Mefisto", Characters[GetMainCharacterIndex()].location, "", "");
			Group_LockTask("Mefisto");

			Characters[GetCharacterIndex("Dark Captain")].recognized = true; // PB: Ensure they're hostile!
		//	SetCharacterRelationBoth(GetCharacterIndex("Dark Captain"),GetMainCharacterIndex(),RELATION_ENEMY);
		//	UpdateRelations();

			pchar.quest.blood_talk.win_condition.l1 = "location";
			pchar.quest.blood_talk.win_condition.l1.character = "Dark Captain";
			pchar.quest.blood_talk.win_condition.l1.location = pchar.location;
			pchar.quest.blood_talk.win_condition = "blood_talk";
			/*pchar.quest.Talk_on_Blood.win_condition.l1 = "NPC_Death";
			pchar.quest.Talk_on_Blood.win_condition.l1.character = "Dark Captain";
			pchar.quest.Talk_on_Blood.win_condition = "Talk_on_Blood";*/

			pchar.quest.resetdark.win_condition.l1 = "ExitFromLocation";
			pchar.quest.resetdark.win_condition.l1.location = "Turks";
			pchar.quest.resetdark.win_condition = "resetdark";

			pchar.quest.destroy_mefisto_complete.win_condition.l1 = "Ship_HP";
			pchar.quest.destroy_mefisto_complete.win_condition.l1.character = "Dark Captain";
			pchar.quest.destroy_mefisto_complete.win_condition.l1.quantity = 0;
			pchar.quest.destroy_mefisto_complete.win_condition.l1.operation = "=";
			pchar.quest.destroy_mefisto_complete.win_condition = "destroy_mefisto_complete";

			AddQuestRecord("Sao Feng", 37);
		break;

		case "destroy_mefisto_complete":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 15000);
				AddPartyExpChar(pchar, "Sailing", 5000);
				AddPartyExpChar(pchar, "Sneak", 500);
			}
			else { AddPartyExp(pchar, 15000); }
			ChangeCharacterReputation(pchar, 10);
			bQuestDisableMapEnter = false
			Island_SetReloadEnableGlobal("Turks", true);
			ItemSetPrice("animists_amulet", 1);	// GR: can now dump Animist amulet into a chest
//			CloseQuestHeader("Sao Feng");

			if (GetAttribute(pchar, "Blood") == "0")
			{
				RestorePassengers("Blaze");
			}

// CTM -->
			pchar.quest.talk_to_girls_Muelle.win_condition.l1 = "location";
			pchar.quest.talk_to_girls_Muelle.win_condition.l1.location = "Muelle_Port";
			pchar.quest.talk_to_girls_Muelle.win_condition = "talk_to_girls_Muelle";
			
			pchar.quest.talk_to_girls_Muelle_shore.win_condition.l1 = "location";
			pchar.quest.talk_to_girls_Muelle_shore.win_condition.l1.location = "Muelle_Shore";
			pchar.quest.talk_to_girls_Muelle_shore.win_condition = "talk_to_girls_Muelle_shore";
// CTM <--
		break;

		case "blood_talk":
			LAi_SetWarriorType(CharacterFromID("Dark Captain"));
			LAi_warrior_DialogEnable(CharacterFromID("Dark Captain"), true)
		break;

		case "Talk_on_Blood":
			LAi_SetFightMode(PChar, false);

			if (LAi_IsDead(characterFromID("Jaoquin de masse")) || LAi_IsDead(characterFromID("Mergildo Hurtado")))
			{
				pchar.quest.Blood_Check.win_condition.l1 = "location";
				pchar.quest.Blood_Check.win_condition.l1.location = "Redmond_church";
				pchar.quest.Blood_Check.win_condition = "Blood_Check";
				LAi_QuestDelay("Abordage_End", 0.0); // PB: To prevent player getting stuck
			}
			else
			{
				RemovePassenger(pchar, characterFromID("Jaoquin de masse"));
				RemoveCharacterCompanion(pchar, characterFromID("Jaoquin de masse"));
				RemoveOfficersIndex(pchar, GetCharacterIndex("Jaoquin de masse"));
				StorePassengers(pchar.id);
				AddPassenger(pchar, characterFromID("Jaoquin de masse"), 0); // PB: Needs to be there so you can assign the ship to him!

				pchar.blood = "0";

				LAi_QuestDelay("Talk_on_Blood2", 2.0);
			}
		break;

		case "Talk_on_Blood2":
			SetCharacterToNearLocatorFromMe("Jaoquin de masse", 3);

			LAi_SetActorType(characterFromID("Jaoquin de masse"));
			LAi_ActorDialog(characterFromID("Jaoquin de masse"), pchar, "", 100.0, 100.0);
			characters[GetCharacterIndex("Jaoquin de masse")].dialog.currentnode = "Which_ship";
		break;

		case "Blood_Check":
			if (GetAttribute(PChar,"ship.type") == "CrimsonBlood")	CrimsonBlood_ModifyShip(); // KK
		break;

		case "resetdark":
			LAi_SetHuberStayType(characterfromID("Dark Captain"));
		break;

		case "Teague_gives_Piece_of_8":
			changeCharacterAddressGroup(characterFromID("Teague Sparrow"), "Turks_port", "goto", "T_character11");	//JRH: new Turks

			LAi_SetActorType(characterFromID("Teague Sparrow"));
			LAi_ActorDialog(characterFromID("Teague Sparrow"), pchar, "", 100.0, 100.0);
			characters[GetCharacterIndex("Teague Sparrow")].dialog.currentnode = "Piece of 8";

			ChangeCharacterAddressGroup(characterFromID("Sao Feng's Body1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Sao Feng's Body2"), "none", "", "");
		break;

		case "Teague_gives_Piece_of_8_1":
			AddQuestRecord("Pirate Lord", 4);

			LAi_ActorGoToLocation(characterFromID("Teague Sparrow"), "reload", "reload1", "none", "", "", "", 0.0);
		break;

		case "Story_Gareth_deception":
			LAi_SetActorType(characterFromID("father Gareth"));
			LAi_ActorDialog(characterFromID("father Gareth"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("father Gareth"));
			characters[GetCharacterIndex("father Gareth")].dialog.currentnode = "letter_to_domingues";
		break;

		case "Story_Gareth_deception2":
			LAi_SetActorType(characterFromID("Father Bernard"));
			LAi_ActorDialog(characterFromID("Father Bernard"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("Father Bernard"));
			characters[GetCharacterIndex("Father Bernard")].dialog.currentnode = "ANIMISTS_letters_5";
		break;

		case "Story_Domingues_to_cave":
			ChangeCharacterAddressGroup(characterFromID("padre Domingues"), "Turks_Cavern_01", "goto", "goto21");
			ChangeCharacterAddressGroup(characterFromID("Sao Feng's Body1"), "Turks_Cavern_01", "goto", "goto22");
			ChangeCharacterAddressGroup(characterFromID("Sao Feng's Body2"), "Turks_Cavern_01", "goto", "goto23");

			Locations[FindLocation("Turks_Cavern_01")].locators_radius.goto.goto21 = 5.0;
			pchar.quest.domingues_in_cell.win_condition.l1 = "locator";
			pchar.quest.domingues_in_cell.win_condition.l1.location = "Turks_Cavern_01";
			pchar.quest.domingues_in_cell.win_condition.l1.locator_group = "goto";
			pchar.quest.domingues_in_cell.win_condition.l1.locator = "goto21";
			pchar.quest.domingues_in_cell.win_condition = "domingues_in_cell";
		break;

		case "domingues_in_cell":
			LAi_SetActorType(characterFromID("padre Domingues"));
			LAi_ActorDialog(characterFromID("padre Domingues"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("padre Domingues"), PChar); //CTM
			characters[GetCharacterIndex("padre Domingues")].dialog.currentnode = "Domingues_in_cave";

			LAi_SetActorType(characterFromID("Sao Feng's Body1"));
			LAi_ActorDialog(characterFromID("Sao Feng's Body1"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("Sao Feng's Body1"), PChar); //CTM
			characters[GetCharacterIndex("Sao Feng's Body1")].dialog.currentnode = "Twins_in_cave";

			LAi_SetActorType(characterFromID("Sao Feng's Body2"));
			LAi_ActorDialog(characterFromID("Sao Feng's Body2"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("Sao Feng's Body2"), PChar); //CTM
			characters[GetCharacterIndex("Sao Feng's Body2")].dialog.currentnode = "Twins_in_cave";
		break;

		case "Domingues_warning":
			pchar.quest.Domingues_warning2.win_condition.l1 = "NPC_Death";
			pchar.quest.Domingues_warning2.win_condition.l1.character = "Dark Teacher";
			pchar.quest.Domingues_warning2.win_condition = "Domingues_warning2";
		break;

		case "Domingues_warning2":
			Locations[FindLocation("Turks_Cavern_01")].locators_radius.goto.goto21 = 5.0;
			pchar.quest.Domingues_warning3.win_condition.l1 = "locator";
			pchar.quest.Domingues_warning3.win_condition.l1.location = "Turks_Cavern_01";
			pchar.quest.Domingues_warning3.win_condition.l1.locator_group = "goto";
			pchar.quest.Domingues_warning3.win_condition.l1.locator = "goto21";
			pchar.quest.Domingues_warning3.win_condition = "Domingues_warning3";
		break;

		case "Domingues_warning3":
			LAi_SetActorType(characterFromID("padre Domingues"));
			LAi_ActorDialog(characterFromID("padre Domingues"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("padre Domingues"), PChar); //CTM
			characters[GetCharacterIndex("padre Domingues")].dialog.currentnode = "Domingues_in_cave2";

			LAi_SetActorType(characterFromID("Sao Feng's Body1"));
			LAi_ActorDialog(characterFromID("Sao Feng's Body1"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("Sao Feng's Body1"), PChar); //CTM
			characters[GetCharacterIndex("Sao Feng's Body1")].dialog.currentnode = "Twins_in_cave2";

			LAi_SetActorType(characterFromID("Sao Feng's Body2"));
			LAi_ActorDialog(characterFromID("Sao Feng's Body2"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("Sao Feng's Body2"), PChar); //CTM
			characters[GetCharacterIndex("Sao Feng's Body2")].dialog.currentnode = "Twins_in_cave2";
		break;

		case "Story_Domingues_released":
			LAi_QuestDelay("Story_Domingues_released2", 20.0);
		break;

		case "Story_Domingues_released2":
			changeCharacterAddress(characterfromID("second_spaniard_priest"), "none", ""); // KK
			changeCharacterAddress(characterfromID("padre Domingues"), "none", "");

			ChangeCharacterAddress(characterFromID("Sao Feng's Body1"), "none", "");
			ChangeCharacterAddress(characterFromID("Sao Feng's Body2"), "none", "");
		break;
		// NK <--

		// CTM -->
		case "talk_to_girls_Muelle":
			SetCharacterToNearLocatorFromMe("Sao Feng's Body1", 3);
			SetCharacterToNearLocatorFromMe("Sao Feng's Body2", 3);
			LAi_ActorFollowEverywhere(characterFromID("Sao Feng's Body1"), "", 60.0);
			LAi_ActorFollowEverywhere(characterFromID("Sao Feng's Body2"), "", 60.0);

			LAi_SetActorType(characterFromID("Sao Feng's Body2"));
			LAi_ActorDialog(characterFromID("Sao Feng's Body2"), pchar, "", 2.0, 1.0);
			characters[GetCharacterIndex("Sao Feng's Body2")].dialog.currentnode = "Twins_in_muelle";
			pchar.quest.talk_to_girls_Muelle_shore.over = "yes";
		break;

		case "talk_to_girls_Muelle_Shore":
			SetCharacterToNearLocatorFromMe("Sao Feng's Body1", 3);
			SetCharacterToNearLocatorFromMe("Sao Feng's Body2", 3);
			LAi_ActorFollowEverywhere(characterFromID("Sao Feng's Body1"), "", 60.0);
			LAi_ActorFollowEverywhere(characterFromID("Sao Feng's Body2"), "", 60.0);

			LAi_SetActorType(characterFromID("Sao Feng's Body2"));
			LAi_ActorDialog(characterFromID("Sao Feng's Body2"), pchar, "", 2.0, 1.0);
			characters[GetCharacterIndex("Sao Feng's Body2")].dialog.currentnode = "Twins_in_muelle_shore";
			pchar.quest.talk_to_girls_Muelle.over = "yes";
		break;

		case "to_tavern_with_girls":
			DoReloadCharacterToLocation("Muelle_Tavern_upstairs", "goto", "goto4");
			changeCharacterAddress(characterfromID("Sao Feng's Body1"), "Muelle_tavern_upstairs", "goto5");
			changeCharacterAddress(characterfromID("Sao Feng's Body2"), "Muelle_tavern_upstairs", "goto8");

			LAi_QuestDelay("to_tavern_with_girls2", 2.0);
		break;

		case "to_tavern_with_girls2":
			LAi_Fade("to_tavern_with_girls3","");
		break;

		case "to_tavern_with_girls3":
			LAi_SetActorType(characterFromID("Sao Feng's Body1"));
			LAi_ActorDialog(characterFromID("Sao Feng's Body1"), pchar, "", 2.0, 1.0);
			characters[GetCharacterIndex("Sao Feng's Body1")].dialog.currentnode = "After_Tavern";
		break;

		case "to_shore_with_girls":
			DoReloadCharacterToLocation("Muelle_shore", "goto", "goto10");
			changeCharacterAddress(characterfromID("Sao Feng's Body1"), "Muelle_shore", "goto16");
			changeCharacterAddress(characterfromID("Sao Feng's Body2"), "Muelle_shore", "goto17");

			LAi_QuestDelay("to_shore_with_girls2", 2.0);
		break;

		case "to_shore_with_girls2":
			LAi_Fade("to_shore_with_girls3","");
		break;

		case "to_shore_with_girls3":
			LAi_SetActorType(characterFromID("Sao Feng's Body1"));
			LAi_ActorDialog(characterFromID("Sao Feng's Body1"), pchar, "", 2.0, 1.0);
			characters[GetCharacterIndex("Sao Feng's Body1")].dialog.currentnode = "After_shore";
		break;

		case "return_priest_complete":
			DoReloadCharacterToLocation("Muelle_Church", "reload", "reload1");
			changeCharacterAddressGroup(characterfromID("padre Domingues"), "Muelle_Church", "goto", "goto1");
			changeCharacterAddress(characterfromID("second_spaniard_priest"), "none", "");
			LAi_SetActorType(characterFromID("padre Domingues"));
			LAi_ActorDialog(characterFromID("padre Domingues"), pchar, "", 2.0, 1.0);
			characters[GetCharacterIndex("padre Domingues")].dialog.currentnode = "Thank_You";

			LAi_ActorFollowEverywhere(characterFromID("Sao Feng's Body1"), "", 60.0);
			LAi_ActorFollowEverywhere(characterFromID("Sao Feng's Body2"), "", 60.0);

			AddQuestRecord("Sao Feng", 41);
			//CloseQuestHeader("Sao Feng");

			Locations[FindLocation("Muelle_church")].reload.l1.go = "Muelle_town_04";							//GR: put church exit back to normal
			Locations[FindLocation("Muelle_church")].reload.l1.emerge = "reload4";
		break;

		case "return_priest_complete3":
			pchar.quest.ANIMISTS = "completed";

			//if (IsPassenger(characterFromID("Jaoquin de masse")) || IsOfficer(characterFromID("Jaoquin de masse")))
			if (!LAi_IsDead(characterFromID("Jaoquin de masse")) || !LAi_IsDead(characterFromID("Mergildo Hurtado")))
			{
				pchar.quest.Jaoquin_back_church.win_condition.l1 = "location";
				pchar.quest.Jaoquin_back_church.win_condition.l1.location = "Redmond_Church";
				pchar.quest.Jaoquin_back_church.win_condition = "Jaoquin_back_church";

				pchar.quest.ship_moor.win_condition.l1 = "location";
				pchar.quest.ship_moor.win_condition.l1.location = "Redmond_port";
				pchar.quest.ship_moor.win_condition = "Ship_moor";

				pchar.quest.ship_moor1.win_condition.l1 = "location";
				pchar.quest.ship_moor1.win_condition.l1.location = "Redmond_Shore_01";
				pchar.quest.ship_moor1.win_condition = "Ship_moor1";

				pchar.quest.ship_moor2.win_condition.l1 = "location";
				pchar.quest.ship_moor2.win_condition.l1.location = "Redmond_Shore_02";
				pchar.quest.ship_moor2.win_condition = "Ship_moor2";
			}

			pchar.quest.return_priest_complete4.win_condition.l1 = "ExitFromLocation";
			pchar.quest.return_priest_complete4.win_condition.l1.location = "Muelle_Church";
			pchar.quest.return_priest_complete4.win_condition = "return_priest_complete4";
		break;

		case "return_priest_complete4":
			changeCharacterAddress(characterfromID("padre Domingues"), "Muelle_church", "goto11");
			LAi_SetStayType(characterFromID("padre Domingues"));
			Characters[GetCharacterIndex("padre Domingues")].dialog.CurrentNode  = "First time";
		break;

		case "Ship_moor":
			pchar.location.from_sea = "Redmond_port";
		break;

		case "Ship_moor1":
			pchar.location.from_sea = "Redmond_Shore_01";
		break;

		case "Ship_moor2":
			pchar.location.from_sea = "Redmond_Shore_02";
		break;

		case "Jaoquin_back_church":
			pchar.quest.ship_moor.over = "yes";
			pchar.quest.ship_moor1.over = "yes";
			pchar.quest.ship_moor2.over = "yes";

			if (GetAttribute(CharacterFromID("Jaoquin de masse"),"ship.type") != "UncursedPearl" && GetAttribute(CharacterFromID("Jaoquin de masse"),"ship.type") != "CrimsonBlood")
			{
				ChangeCharacterAddressGroup(characterFromID("Jaoquin de masse"), "Redmond_Church", "goto", "goto1");
				LAi_SetActorType(characterFromID("Jaoquin de masse"));
				characters[GetCharacterIndex("Jaoquin de masse")].dialog.currentnode = "Leaving";
				LAi_ActorDialog(characterFromID("Jaoquin de masse"), pchar, "", 5.0, 0);
			}
			else
			{
				if (GetAttribute(CharacterFromID("Jaoquin de masse"),"ship.type") != "CrimsonBlood")
				{
					LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
					CrimsonBlood_ModifyShip();				// KK
				}

				characters[GetCharacterIndex("Jaoquin de masse")].Flags.Personal = 6;
				characters[GetCharacterIndex("Jaoquin de masse")].Flags.Personal.texture = 3;
				characters[GetCharacterIndex("Jaoquin de masse")].nation = PERSONAL_NATION;
				characters[GetCharacterIndex("Jaoquin de masse")].sailaway = true;

				if (pchar.location.from_sea == "Redmond_port")
				{
					pchar.quest.Jaoquin_sails.win_condition.l1 = "location";
					pchar.quest.Jaoquin_sails.win_condition.l1.location = "Redmond_port";
					pchar.quest.Jaoquin_sails.win_condition = "Jaoquin_sails";
				}
				if (pchar.location.from_sea == "Redmond_Shore_01")
				{
					pchar.quest.Jaoquin_sails1.win_condition.l1 = "location";
					pchar.quest.Jaoquin_sails1.win_condition.l1.location = "Redmond_Shore_01";
					pchar.quest.Jaoquin_sails1.win_condition = "Jaoquin_sails1";
				}
				if (pchar.location.from_sea == "Redmond_Shore_02")
				{
					pchar.quest.Jaoquin_sails2.win_condition.l1 = "location";
					pchar.quest.Jaoquin_sails2.win_condition.l1.location = "Redmond_Shore_02";
					pchar.quest.Jaoquin_sails2.win_condition = "Jaoquin_sails2";
				}
			}
		break;

		case "Jaoquin_leaves":
			LAi_ActorGoToLocation(characterFromID("Jaoquin de masse"), "reload", "reload2", "none", "", "", "Jaoquin_leaves2", 100.0);
		break;

		case "Jaoquin_leaves2":
			RemovePassenger(pchar, characterFromID("Jaoquin de masse"));
			RemoveCharacterCompanion(pchar, characterFromID("Jaoquin de masse"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Jaoquin de masse"));
			if (CheckAttribute(PChar, "quest.cotbp_done")) CloseQuestHeader("Stolen");
		break;

		case "Jaoquin_sails":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "reload", "sea_1", "Jaoquin_sails_executed",100);
		break;

		case "Jaoquin_sails1":
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator(PChar, "goto", "shipview", "Jaoquin_sails_executed",100);
		break;

		case "Jaoquin_sails2":
			LAi_SetActorType(Pchar);
			LAi_ActorRunToLocator(PChar, "goto", "goto4", "Jaoquin_sails_executed",100);
		break;

		case "Jaoquin_sails_executed":
			if (GetAttribute(pchar, "stolen" != "1"))
			{
				SetQuestHeader("Stolen");
			}
			pchar.stolen = "1";

			AddQuestRecord("Stolen", 1);
			if (CheckAttribute(PChar, "quest.cotbp_done")) CloseQuestHeader("Stolen");

			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "His_stealing_our_ship";
			LAi_ActorSelfDialog(pchar, "player_back");

			RemovePassenger(pchar, characterFromID("Jaoquin de masse"));
			RemoveCharacterCompanion(pchar, characterFromID("Jaoquin de masse"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Jaoquin de masse"));
			ChangeCharacterAddress(characterFromID("Jaoquin de masse"), "None", "");
			SetCharacterShipLocation(CharacterFromID("Jaoquin de masse"), "none");
		break;

		case "guards_in_church":
			LAi_LocationFightDisable(&locations[FindLocation("redmond_church")], false);

			LAi_SetHP(characterFromID("guard_church1"), 80.0, 80.0);
			LAi_SetHP(characterFromID("guard_church2"), 80.0, 80.0);
			LAi_SetHP(characterFromID("guard_church3"), 80.0, 80.0);
			ChangeCharacterAddressGroup(characterFromID("guard_church1"), "Redmond_Church", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("guard_church2"), "Redmond_Church", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("guard_church3"), "Redmond_Church", "reload", "reload1");

			LAi_group_MoveCharacter(characterFromID("guard_church1"), "Guards_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("guard_church2"), "Guards_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("guard_church3"), "Guards_IN_CHURCH");
			LAi_group_FightGroups("Guards_IN_CHURCH", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("Guards_IN_CHURCH", "kill_all_Guards_in_church_complete");
		break;

		case "kill_all_Guards_in_church_complete":
			ChangeCharacterAddress(characterFromID("guard_church1"), "none", "");
			ChangeCharacterAddress(characterFromID("guard_church2"), "none", "");
			ChangeCharacterAddress(characterFromID("guard_church3"), "none", "");
			LAi_LocationFightDisable(&locations[FindLocation("redmond_church")], true);
		break;
		// CTM <--
//Captian Sao Feng

//Misstress Ching
//Misstress Ching

//Gentleman Jocard
// KK -->
		case "Install_Voysey_And_Blythe":
			ChangeCharacterAddressGroup(CharacterFromID("Gentleman Jocard"), "Oranjestad_town", "goto", "character7");
			ChangeCharacterAddressGroup(CharacterFromID("Slaver"), "Oranjestad_town", "goto", "goto7");

			PChar.quest.Install_Voysey_And_Blythe = "1";
			LAi_QuestDelay("Story_Artois", 0.0);
			Locations[FindLocation("Oranjestad_town")].vcskip = true;
		break;
// <-- KK

		case "Story_Artois":
			if (CheckQuestAttribute("main_line", "ines_info_denied"))
			{
				LAi_QuestDelay("Story_Artois", 4.0);
			}
			else
			{
				TakeItemFromCharacter(characterfromID("Gentleman Jocard"), GetCharacterEquipByGroup(characterfromID("Gentleman Jocard"), GUN_ITEM_TYPE));
				pchar.Alantic_PL = "White_Jocard";

				PChar.quest.Install_Voysey_And_Blythe.over = "yes"; // KK
				DeleteAttribute(&Locations[FindLocation("Oranjestad_town")],"vcskip"); // NK
				LAi_SetHP(characterFromID("Gentleman Jocard"), 50.0, 50.0);
				LAi_SetHP(characterFromID("Slaver"), 50.0, 50.0);
				LAi_SetActorType(CharacterFromID("Gentleman Jocard"));
				LAi_SetActorType(CharacterFromID("Slaver"));
				LAi_group_MoveCharacter(CharacterFromID("Gentleman Jocard"), "Jocard");
				LAi_SetImmortal(CharacterFromID("Gentleman Jocard"), true);
				LAi_ActorAnimation(CharacterFromID("Slaver"), "afraid","", 10);
				LAi_ActorAttack(characterFromID("Gentleman Jocard"), characterFromID("Slaver"), "");
				LAi_SetCheckMinHP(characterFromID("Slaver"), 0.4*LAi_GetCharacterHP(characterFromID("Slaver")), true, "Story_Artois_2"); // KK
				StartQuestMovie(true, false, true);TrackQuestMovie("start","Story_Artois");
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("Gentleman Jocard"), "Story_Artois_2", -1);
			}
		break;

		case "Story_Artois_2":
			LAi_SetStayType(pchar);
			LAi_RemoveCheckMinHP(CharacterFromID("Slaver"));
			LAi_type_actor_Reset(characterFromID("Gentleman Jocard"));
			LAi_type_actor_Reset(characterFromID("Slaver"));
			LAi_ActorDialog(characterFromID("Gentleman Jocard"), pchar, "", -1, -1);
		break;

		case "saving_artois":
// KK -->
			PChar.quest.BlazeKilledFightingWithNigel.win_condition.l1 = "NPC_Death";
			PChar.quest.BlazeKilledFightingWithNigel.win_condition.l1.character = PChar.id;
			PChar.quest.BlazeKilledFightingWithNigel.win_condition = "BlazeKilledFightingWithNigel";
// <-- KK
			LAi_SetCheckMinHP(characterFromID("Gentleman Jocard"), 1, true, "Artois_kill_pre"); // CTM
			EndQuestMovie();TrackQuestMovie("end","saving_artois");
			LAi_SetImmortal(characterFromID("Gentleman Jocard"), false);
			LAi_SetPlayerType (Pchar);
			LAi_group_MoveCharacter(CharacterFromID("Gentleman Jocard"), "nigel_2");
			LAi_group_FightGroups("nigel_2", LAI_GROUP_PLAYER, true);
		break;

// KK -->

		case "killing_artois":
			LAi_SetImmortal(characterFromID("Gentleman Jocard"), false);
			LAi_SetImmortal(characterFromID("Slaver"), false);
			LAi_SetActorType(pchar);
			LAi_group_MoveCharacter(CharacterFromID("Gentleman Jocard"), "nigel_2");
			LAi_ActorTurnToCharacter(pchar, characterFromID("Gentleman Jocard"));
			LAi_ActorAnimation(CharacterFromID("Slaver"), "afraid","", 10);
			LAi_ActorAttack(CharacterFromID("Gentleman Jocard"), CharacterFromID("Slaver"), "Artois_saved");
		break;

		case "Artois_kill_pre":
			TakeItemFromCharacter(characterfromID("Gentleman Jocard"), "blade6");
			GiveItem2Character(characterfromID("Slaver"), "blade6");
			GiveItem2Character(characterfromID("Gentleman Jocard"), "bladeX4");
			EquipCharacterByItem(CharacterFromId("Gentleman Jocard"), "bladeX4");

			Lai_KillCharacter(characterFromID("Gentleman Jocard"));
			LAi_QuestDelay("Artois_kill", 0.0);
		break;

		case "Artois_kill":
			pchar.quest.BlazeKilledFightingWithNigel.over = "yes";

			SetQuestHeader("Slaver");
			AddQuestRecord("Slaver", 1);

			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Slaver"));
			LAi_ActorDialog(CharacterFromID("Slaver"), PChar, "", 2.0, 1.0);
			EndQuestMovie();TrackQuestMovie("end","Artois_kill");
		break;

		case "BlazeKilledFightingWithNigel":
			bSuppressResurrection = true;
			LAi_SetActorType(CharacterFromID("Gentleman Jocard"));
			SendMessage(&locCamera, "li", MSG_CAMERA_SETTARGET, CharacterFromID("Gentleman Jocard"));
			locCameraFollow();

			SendMessage(&Characters[GetCharacterIndex("Gentleman Jocard")],"lsl", MSG_CHARACTER_EX_MSG , "SetFightMode", true);
			LAi_SetImmortal(characterFromID("Slaver"), false);
			LAi_SetImmortal(characterFromID("Gentleman Jocard"), false);
			LAi_group_MoveCharacter(CharacterFromID("Gentleman Jocard"), "Jocard");
			LAi_ActorAnimation(CharacterFromID("Slaver"), "afraid","", 10);
			LAi_ActorAttack(CharacterFromID("Gentleman Jocard"), CharacterFromID("Slaver"), "Artois_kill_after_Blaze");
		break;

		case "Artois_kill_after_Blaze":
			LAi_ActorGoToLocation(CharacterFromID("Gentleman Jocard"), "reload", "reload1", "none", "", "", "AfterKillingBlazeAndArtois", 100);
		break;

		case "AfterKillingBlazeAndArtois":
			EndQuestMovie();TrackQuestMovie("end","AfterKillingBlazeAndArtois");
			bSuppressResurrection = false;

			pchar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "land");
		break;
// <-- KK

		case "Artois_saved":
			EndQuestMovie();TrackQuestMovie("end","Artois_saved");
			PChar.quest.BlazeKilledFightingWithNigel.over = "yes"; // KK
			SetQuestHeader("Jocard");
			AddQuestRecord("Jocard", 1);
			LAi_SetActorType(pchar);
			LAi_SetActorType(CharacterFromID("Gentleman Jocard"));
			LAi_ActorWaitDialog(CharacterFromID("Gentleman Jocard"), PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Gentleman Jocard"), "", 2.0, 1.0);
// added by MAXIMUS --> // KK -->
			characters[GetCharacterIndex("Gentleman Jocard")].quest.officerprice = makeint((sti(Pchar.rank) * 2 + 10)*100) - 330 + rand(40)*15 + rand(10);
			LAi_NPC_Equip(characterFromID("Gentleman Jocard"), sti(Pchar.rank), true, 0.5);
// added by MAXIMUS <-- // <-- KK
		break;

		case "Voysey_listed":
			LAi_SetImmortal(characterFromID("Gentleman Jocard"), false);

			Pchar.quest.Artois_Voysey.win_condition.l1 = "location";
			Pchar.quest.Artois_Voysey.win_condition.l1.character = "Gentleman Jocard";
			Pchar.quest.Artois_Voysey.win_condition.l1.location = "Eleuthera_port";
			PChar.quest.Artois_Voysey.win_condition = "Artois_missed";
//NK --> fix for Artois quest repeating	
			pchar.quest.Voysey_lost = "0";
//NK <--

			Pchar.quest.Artois_Voysey1.win_condition.l = "location";
			Pchar.quest.Artois_Voysey1.win_condition.l.character = "Gentleman Jocard";
			Pchar.quest.Artois_Voysey1.win_condition.l.location = "Douwesen_port";
			PChar.quest.Artois_Voysey1.win_condition = "Artois_missed1";
//NK --> fix for Artois quest repeating	
			pchar.quest.Voysey_lost = "0";
//NK <--

			LAi_SetPlayerType(Pchar);
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Gentleman Jocard")); // NK was -1
			LAi_SetOfficerType(characterFromID("Gentleman Jocard"));
			characters[GetCharacterIndex("Gentleman Jocard")].Dialog.Filename = "Enc_Officer_dialog.c"; // KK
			characters[GetCharacterIndex("Gentleman Jocard")].Dialog.CurrentNode = "Hired"; // KK
		break;

		case "Voysey_listed_2":
			LAi_SetImmortal(characterFromID("Gentleman Jocard"), false);

			LAi_SetPlayerType(Pchar);
			SetOfficersIndex(Pchar, -1, GetCharacterIndex("Gentleman Jocard"));
		break;

		case "Artois_missed":
//NK -->
			if(!CheckAttribute(PChar,"quest.Voysey_lost") || PChar.quest.Voysey_lost != "0") break;
//NK <--
			if(FindFellowTravellers(PChar, CharacterFromId("Gentleman Jocard")) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, CharacterFromId("Gentleman Jocard")) == FELLOWTRAVEL_PASSENGER)
			{
				pchar.quest.Artois_missed1.over = "yes";

				LAi_LocationMonstersGen(&locations[FindLocation("EleutheraPlantation")], false);
				pchar.quest.Artois_lost = "1";

				ChangeCharacterAddressGroup(characterFromID("Gentleman Jocard"), "none", "", "");
				RemovePassenger(pchar, characterFromID("Gentleman Jocard"));
				LAi_SetActorType(Pchar);
				Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
				Pchar.dialog.currentnode = "Artois_lost";
				LAi_ActorSelfDialog(Pchar, "player_back");
				AddQuestRecord("Jocard", 4);
			}
		break;

		case "Artois_missed1":
//NK -->
			if(!CheckAttribute(PChar,"quest.Voysey_lost") || PChar.quest.Voysey_lost != "0") break;
//NK <--
			if(FindFellowTravellers(PChar, CharacterFromId("Gentleman Jocard")) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, CharacterFromId("Gentleman Jocard")) == FELLOWTRAVEL_PASSENGER)
			{
				pchar.quest.Artois_missed.over = "yes";

				LAi_SetActorType(Pchar);
				Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
				Pchar.dialog.currentnode = "Artois_lost1";
				LAi_ActorSelfDialog(Pchar, "player_back");

				LAi_LocationMonstersGen(&locations[FindLocation("Douwesen_town_exit")], false);
				pchar.quest.Artois_lost = "2";
				LAi_SetActorType(characterFromID("Gentleman Jocard"));
				LAi_ActorRunToLocation(characterFromID("Gentleman Jocard"), "reload", "reload3", "none", "", "", "Artois_remove", 0.0);
			}
		break;

		case "Artois_remove":
			RemovePassenger(pchar, characterFromID("Gentleman Jocard"));
			AddQuestRecord("Jocard", 13);
		break;

		case "artois_before_room_on_second_floor":
			AddQuestRecord("Jocard", 5);
			Locations[FindLocation("Eleuthera_tavern")].reload.l1.disable = false;
			Pchar.quest.Blaze_arrest.win_condition.l1 = "location";
			Pchar.quest.Blaze_arrest.win_condition.l1.location = "Eleuthera_tavern_upstairs";
			PChar.quest.Blaze_arrest.win_condition = "Blaze_arrest";
			pchar.quest.Artois_lost = "3";
		break;

		case "artois_before_room_on_second_floor2":
			Locations[FindLocation("Douwesen_tavern")].reload.l2.disable = false;
			Pchar.quest.Blaze_arrest2.win_condition.l1 = "location";
			Pchar.quest.Blaze_arrest2.win_condition.l1.location = "Douwesen_tavern_upstairs";
			PChar.quest.Blaze_arrest2.win_condition = "Blaze_arrest2";
			pchar.quest.Artois_lost = "3";
		break;

		case "Blaze_arrest2":
			Pchar.Jocard = "Bonaire";
			AddQuestRecord("Jocard", 14);
			Locations[FindLocation("Douwesen_tavern")].reload.l2.disable = true;
			LAi_SetImmortal(characterFromID("Gentleman Jocard"), true);
			ChangeCharacterAddress(CharacterFromID("Gentleman Jocard"), "Douwesen_tavern_upstairs", "goto4");
			characters[GetCharacterIndex("Gentleman Jocard")].Dialog.Filename = "Gentleman Jocard_dialog.c"; // KK
			characters[GetCharacterIndex("Gentleman Jocard")].dialog.currentnode = "Captured";
			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_ActorSetLayMode(characterfromID("Gentleman Jocard"));
			LAi_ActorWaitDialog(characterfromID("Gentleman Jocard"), pchar);
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, characterfromID("Gentleman Jocard"), "", 4.0, 1.0);
	  	break;

		case "Artois_resque_in_tavern":
			LAi_fade("Artois_resque_in_tavern2", "Artois_resque_in_tavern3");
		break;

		case "Artois_resque_in_tavern2":
			LAi_ActorSetStayMode(characterFromID("Gentleman Jocard"));
		break;

		case "Artois_resque_in_tavern3":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 5000); }
			else { AddPartyExp(pchar, 5000); }
		break;

		case "Blaze_arrest":
			AddQuestRecord("Jocard", 6);
			Locations[FindLocation("Eleuthera_tavern")].reload.l1.disable = true;
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "brodyaga", "goto", "stab");
			sld.dialog.filename = "slave_dialog.c";
			sld.dialog.currentnode = "ask_about_artois";
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_ActorWaitDialog(sld, pchar);
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, sld, "", 4.0, 1.0);
	  	break;

		case "Blaze_cop_dialog":
			Locations[FindLocation("Eleuthera_tavern_upstairs")].reload.l1.disable = true;
			LAi_SetPlayerType(pchar);
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "reload", "reload1_back"); // PB
			sld.Dialog.Filename = "Cops_dialog.c";
			sld.dialog.currentnode = "First time";
			sld.id = "solja";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "reload", "reload1_back"); // PB
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, pchar, "", 10);
			sld.id = "solja1";
			LAi_group_MoveCharacter(sld, "ELEUTHURA_SOLDIERS");

			LAi_SetActorType(characterfromID("solja"));
			LAi_ActorDialog(characterfromID("solja"), PChar, "", 10, 10);
			LAi_SetPlayerType(Pchar);
		break;

		case "artois_fight_in_tavern_upstairs":
			LAi_SetWarriorType(characterfromID("solja"));
			LAi_SetWarriorType(characterfromID("solja1"));
			LAi_group_MoveCharacter(characterFromID("solja"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("solja1"), "ENGLAND_SOLDIERS");
			LAi_group_SetCheck("ENGLAND_SOLDIERS", "Open_Locators");
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);

			LeaveService(PChar, ENGLAND, true); // RM

			AddQuestRecord("Jocard", 7);
		break;

		case "Open_Locators":
			Locations[FindLocation("Eleuthera_tavern_upstairs")].reload.l1.disable = false;

			Pchar.quest.fight.win_condition.l1 = "location";
			Pchar.quest.fight.win_condition.l1.location = "Eleuthera_port";
			PChar.quest.fight.win_condition = "Blaze_fight_the_world";

			Pchar.quest.artois_captured.win_condition.l1 = "location";
			Pchar.quest.artois_captured.win_condition.l1.location = "EleutheraPlantation";
			PChar.quest.artois_captured.win_condition = "artois_captured";
		break;

		case "Blaze_fight_the_world":
			pchar.quest.escape_from_conceicao.win_condition.l1 = "location";
			pchar.quest.escape_from_conceicao.win_condition.l1.location = "Eleuthera";
			pchar.quest.escape_from_conceicao.win_condition = "escape_from_conceicao";

			//Locations[FindLocation("Eleuthera_port")].reload.l3.disable = true;

			if (CalcCharacterSkill(pchar, SKILL_SNEAK) < 3)
			{
				LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			}
		break;

		case "escape_from_conceicao":
			//Locations[FindLocation("Eleuthera_port")].reload.l3.disable = false;

			PChar.quest.possible_for_resque_artois.win_condition.l1 = "Timer";
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.day = GetAddingDataDay(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.month = GetAddingDataMonth(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.year = GetAddingDataYear(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition = "possible_for_resque_artois";
		break;

		case "possible_for_resque_artois":
			pchar.quest.artois_captured.over = "yes";
			ChangeCharacterAddress(CharacterFromID("Gentleman Jocard"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Slaver1"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Slaver2"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Slaver3"), "none", "");
			CloseQuestHeader("Jocard");
		break;

		case "artois_captured":
			LAi_SetImmortal(characterFromID("Gentleman Jocard"), true);
			ChangeCharacterAddressGroup(CharacterFromID("Gentleman Jocard"), "EleutheraPlantation", "goto","goto18");
			characters[GetCharacterIndex("Gentleman Jocard")].Dialog.Filename = "Gentleman Jocard_dialog.c"; // KK
			characters[GetCharacterIndex("Gentleman Jocard")].dialog.currentnode = "Captured";
			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_ActorSetLayMode(characterfromID("Gentleman Jocard"));
			characters[GetCharacterIndex("Slaver1")].dialog.currentnode = "artois_lay";
			characters[GetCharacterIndex("Slaver2")].dialog.currentnode = "artois_lay";
			characters[GetCharacterIndex("Slaver3")].dialog.currentnode = "artois_lay";
			ChangeCharacterAddressGroup(CharacterFromID("Slaver1"), "EleutheraPlantation", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("Slaver2"), "EleutheraPlantation", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("Slaver3"), "EleutheraPlantation", "goto", "goto17");
			LAi_SetWarriorType(CharacterFromID("Slaver1"));
			LAi_SetWarriorType(CharacterFromID("Slaver2"));
			LAi_SetWarriorType(CharacterFromID("Slaver3"));
			LAi_warrior_DialogEnable(CharacterFromID("Slaver1"), true)
			LAi_warrior_DialogEnable(CharacterFromID("Slaver2"), true)
			LAi_warrior_DialogEnable(CharacterFromID("Slaver3"), true)
			LAi_warrior_SetCommander(characterFromID("slaver1"), characterFromID("Gentleman Jocard"));
			LAi_warrior_SetCommander(characterFromID("slaver2"), characterFromID("Gentleman Jocard"));
			LAi_warrior_SetCommander(characterFromID("slaver3"), characterFromID("Gentleman Jocard"));

			DeleteAttribute(pchar, "quest.voysey_lost");
			LAi_QuestDelay("reset_pirates", 15.0);
		break;

		case "reset_pirates":
			LAi_SetStayType(CharacterFromID("Slaver1"));
			LAi_SetStayType(CharacterFromID("Slaver2"));
			LAi_SetStayType(CharacterFromID("Slaver3"));
			AddQuestRecord("Jocard", 10);
		break;

		case "fight_for_artois_with_child_of_giens":
			LAi_SetPlayerType(pchar);

			LAi_SetActorType(CharacterFromID("Slaver1"));
			LAi_SetActorType(CharacterFromID("Slaver2"));
			LAi_SetActorType(CharacterFromID("Slaver3"));

			LAi_QuestDelay("Artois_resque_in_jungles1", 5.0);

			LAi_ActorGoToLocator(characterFromID("Slaver1"), "goto", "goto5", "Artois_resque_in_jungles", 100.0);
			LAi_ActorGoToLocator(characterFromID("Slaver2"), "goto", "goto16", "Artois_resque_in_jungles", 100.0);
			LAi_ActorGoToLocator(characterFromID("Slaver3"), "goto", "goto11", "Artois_resque_in_jungles", 100.0);

			pchar.quest.possible_for_resque_artois.over = "yes";
		break;

		case "portugal_becomes_neutral":
			SetRMRelation(PChar, ENGLAND, REL_AMNESTY);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		break;

		case "Artois_resque_in_jungles":
			Lai_SetCivilianPatrolType(characterFromID("Slaver1"));
			Lai_SetCivilianPatrolType(characterFromID("Slaver2"));
			Lai_SetCivilianPatrolType(characterFromID("Slaver3"));
		break;

		case "Artois_resque_in_jungles1":
			characters[GetCharacterIndex("Slaver1")].dialog.currentnode = "First time";
			characters[GetCharacterIndex("Slaver2")].dialog.currentnode = "First time";
			characters[GetCharacterIndex("Slaver3")].dialog.currentnode = "First time";

			pchar.quest.artois_line = "resqued";
			LAi_fade("Artois_resque_in_jungles_2", "Artois_resque_in_jungles_3");
		break;

		case "Artois_resque_in_jungles_2":
			LAi_ActorSetStayMode(characterFromID("Gentleman Jocard"));
			LAi_ActorWaitDialog(characterFromID("Gentleman Jocard"), pchar);
		break;

		case "Artois_resque_in_jungles_3":
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, characterFromID("Gentleman Jocard"), "player_back", 5.0, 1.0);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 5000); }
			else { AddPartyExp(pchar, 5000); }
		break;

		case "pause":
			AddQuestRecord("Jocard", 8);
			Locations[FindLocation("Eleuthera_townhall")].reload.l1.disable = true;
			DoQuestReloadToLocation ("Eleuthera_townhall", "goto", "goto8", "pause2");
		break;

		case "pause2":
			Locations[FindLocation("Eleuthera_tavern_upstairs")].reload.l1.disable = false;
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "goto", "goto10"); // PB
			LAi_SetActorType(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto9"); // PB
			LAi_SetActorType(sld);
			sld.id = "guard";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man6", "goto", "goto7");
			LAi_SetActorType(sld);
			sld.id = "witness";
			sld.Dialog.Filename = "witness-dialog.c";

			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Cole Arkwright"));
			
			LAi_QuestDelay("pause3", 1.5);
		break;

		case "pause3":
			LAi_SetPlayerType(PChar);

			LAi_SetActorType(CharacterFromID("Cole Arkwright"));
			LAi_ActorSetSitMode(CharacterFromID("Cole Arkwright"));
			characters[GetCharacterIndex("Cole Arkwright")].dialog.currentnode = "j_day";
			LAi_ActorDialog(characterfromID("Cole Arkwright"), PChar, "", 0.0, 0.0);
		break;

		case "ex_dialog":
			LAi_ActorDialog(characterfromID("witness"), PChar, "", 0.5, 0.5);
			LAi_ActorGoToLocator(CharacterFromID("guard"), "goto", "goto9", "ex_dialog2_3", 3.0);
		break;

		case "ex_dialog2_3":
			LAi_ActorWaitDialog(characterfromID("Cole Arkwright"), characterfromID("guard"));
			LAi_ActorDialog(characterfromID("guard"), characterfromID("Cole Arkwright"), "ex_dialog2_4", 5.0, 5.0);
		break;

		case "ex_dialog2_4":
			LAi_ActorGoToLocator(CharacterFromID("guard"), "goto", "goto9", "ex_dialog2_5", 2.0);
		break;

		case "ex_dialog2_5":
			LAi_ActorDialog(characterfromID("Cole Arkwright"), PChar, "acrcibaldo_back_to_hub_type", 0.0, 0.0);
			LAi_SetPlayerType(Pchar);

			Pchar.quest.artois_captured.win_condition.l1 = "location";
			Pchar.quest.artois_captured.win_condition.l1.location = "EleutheraPlantation";
			PChar.quest.artois_captured.win_condition = "artois_captured";

			PChar.quest.possible_for_resque_artois.win_condition.l1 = "Timer";
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.day = GetAddingDataDay(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.month = GetAddingDataMonth(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.year = GetAddingDataYear(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition = "possible_for_resque_artois";
			AddQuestRecord("Jocard", 9);
		break;

		case "acrcibaldo_back_to_hub_type":
			Locations[FindLocation("Eleuthera_tavern_upstairs")].reload.l1.disable = false;
			Locations[FindLocation("Eleuthera_townhall")].reload.l1.disable = 0;
			LAi_SetHuberType(characterfromID("Cole Arkwright"));
		break;

		case "before_shore_ship":
			changeCharacterAddressGroup(characterFromID("Bos'un"), "Douwesen_town_exit", "goto", "goto4");

			LAi_SetActorType(characterfromID("Bos'un"));
			LAi_ActorDialog(characterFromID("Bos'un"),PChar,"",100.0,100.0);
			Characters[GetCharacterIndex("Bos'un")].dialog.currentnode = "Got Away";
		break;

		case "before_shore_ship2":
			AddPassenger(Pchar, characterFromID("Bos'un"), 0);
			if (SetOfficersIndex(Pchar, -1, GetCharacterIndex("Bos'un")) == GetCharacterIndex("Bos'un"))
			{
				if (GetOfficersIndex(PChar, 3) == GetCharacterIndex("Gentleman Jocard")) SetOfficersIndex(Pchar, 2, GetCharacterIndex("Bos'un"));
				else SetOfficersIndex(Pchar, 3, GetCharacterIndex("Bos'un"));
			}
		break;

		case "shore_ship":
			DeleteAttribute(&Locations[FindLocation("Douwesen_shore_ship")],"vcskip"); // PB
			if (IsOfficer(characterFromID("Gentleman Jocard")) && IsOfficer(CharacterFromID("Bos'un")))
			{
				RemovePassenger(pchar, characterFromID("Gentleman Jocard"));
				RemovePassenger(pchar, characterFromID("Bos'un"));
				LAi_SetActorType(characterfromID("Gentleman Jocard"));
				LAi_SetActorType(characterfromID("Bos'un"));
				LAi_ActorFollow(characterFromID("Gentleman Jocard"), pchar, "", 100.0);
				LAi_ActorFollow(characterFromID("Bos'un"), pchar, "", 100.0);

				LAi_SetImmortal(characterFromID("Gentleman Jocard"), true);
				LAi_SetImmortal(characterFromID("Bos'un"), true);

				ChangeCharacterAddressGroup(characterFromID("Gentleman Jocard (White)"), "Douwesen_Shore_ship", "reload", "reload1_cabin");

				LAi_questdelay("shore_ship2", 0.0);
			}
		break;

		case "shore_ship2":
			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "corsair1_2", "reload", "reload1_cabin");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.id = "Slaver4"
			sld.name = "Slaver";
			sld.lastname = "";
			LAi_SetImmortal(characterFromID("Slaver4"), true);

			sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "bocman8", "reload", "reload1_cabin");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.id = "Slaver5"
			sld.name = "Slaver";
			sld.lastname = "";
			LAi_SetImmortal(characterFromID("Slaver5"), true);

			if (GetAttribute(pchar, "Bosun") != "Cursed")
			{
				sld = LAi_CreateFantomCharacter(false, 0, false, true, 0.25, "ancient", "reload", "reload1_cabin");
				LAi_SetHP(sld, 100.0, 100.0);
				sld.Dialog.Filename = "Bos'un_dialog.c";
				sld.id = "Nigel"
				sld.name = TranslateString("","Nigel");
				sld.lastname = TranslateString("","the Slave");
				LAi_SetImmortal(characterFromID("Nigel"), true);
			}

			LAi_SetActorType(characterfromID("Gentleman Jocard (White)"));
			LAi_SetActorType(characterfromID("Slaver4"));
			LAi_SetActorType(characterfromID("Slaver5"));
			LAi_ActorFollow(characterFromID("Slaver4"), characterFromID("Gentleman Jocard (White)"), "", 100.0);
			LAi_ActorFollow(characterFromID("Slaver5"), characterFromID("Gentleman Jocard (White)"), "", 100.0);
			LAi_ActorDialog(characterFromID("Gentleman Jocard (White)"),PChar,"",100.0,100.0);
			Characters[GetCharacterIndex("Gentleman Jocard (White)")].dialog.currentnode = "That's_My_Slave";
		break;

		case "shore_ship3":
			LAi_group_MoveCharacter(characterFromID("Gentleman Jocard (White)"), "SHIP_SLAVERS");
			LAi_group_MoveCharacter(characterFromID("Slaver4"), "SHIP_SLAVERS1");
			LAi_group_MoveCharacter(characterFromID("Slaver5"), "SHIP_SLAVERS2");
			LAi_group_MoveCharacter(characterFromID("Gentleman Jocard"), "PLAYER1");
			LAi_group_MoveCharacter(characterFromID("Bos'un"), "PLAYER2");

			LAi_SetActorType(CharacterfromID("Gentleman Jocard"));
			LAi_SetActorType(CharacterfromID("Bos'un"));
			LAi_ActorAttack(CharacterFromID("Gentleman Jocard"), CharacterFromID("Slaver5"), "");
			LAi_ActorAttack(CharacterFromID("Bos'un"), CharacterFromID("Slaver4"), "");

			LAi_group_FightGroups("SHIP_SLAVERS1", "PLAYER1", true);
			LAi_group_FightGroups("SHIP_SLAVERS2", "PLAYER2", true);
			LAi_group_FightGroups("SHIP_SLAVERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SHIP_SLAVERS", "shore_ship4");
		break;

		case "shore_ship4":
			LAi_QuestDelay("kill_slaver_1", 2.0);

			if (GetAttribute(pchar, "Bosun") != "Cursed")
			{
				LAi_SetActorType(characterfromID("Nigel"));
				LAi_ActorDialog(characterFromID("Nigel"),PChar,"",100.0,100.0);
				Characters[GetCharacterIndex("Nigel")].dialog.currentnode = "Nigel";
			}

			pchar.quest.treasure_found.win_condition.l1 = "locator";
			pchar.quest.treasure_found.win_condition.l1.location = "Douwesen_shore_ship";
			pchar.quest.treasure_found.win_condition.l1.locator_group = "randitem";
			pchar.quest.treasure_found.win_condition.l1.locator = "randitem1";
			pchar.quest.treasure_found.win_condition = "treasure_found";
		break;

		case "kill_slaver_1":
			Lai_KillCharacter(characterFromID("Slaver5"));
			LAi_QuestDelay("kill_slaver_2", 4.0);
		break;

		case "kill_slaver_2":
			Lai_KillCharacter(characterFromID("Slaver4"));
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Bos'un")); 
			SetOfficersIndex(Pchar, 2, GetCharacterIndex("Gentleman Jocard")); 
		break;

		case "Nigel_runs":
			LAi_SetActorType(characterfromID("Nigel"));
			LAi_ActorRunToLocation(characterFromID("Nigel"), "reload", "reload1", "none", "", "", "", 0.0);
		break;

		case "treasure_found":
			AddMoneyToCharacter(PChar, 25000);
			Log_SetStringToLog(QUEST_MESSAGE4);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 15000); }
			else { AddPartyExp(pchar, 15000); }
			if (IsOfficer(characterFromID("Gentleman Jocard")))
			{
				LAi_SetActorType(characterfromID("Gentleman Jocard"));
				LAi_ActorDialog(characterFromID("Gentleman Jocard"),PChar,"",100.0,100.0);
				Characters[GetCharacterIndex("Gentleman Jocard")].dialog.currentnode = "Jocard_Request";
			}
			if (IsOfficer(characterFromID("Slaver")))
			{
				LAi_SetActorType(characterfromID("Slaver"));
				LAi_ActorDialog(characterFromID("Slaver"),PChar,"",100.0,100.0);
				Characters[GetCharacterIndex("Slaver")].dialog.currentnode = "Enough_money";
			}
		break;

		case "Eleuthera_Options":
			DisableFastTravel(true);						// Prevent player from leaving before
			Locations[FindLocation("Douwesen_shore_ship")].reload.l1.disable = 1;	// Bos'un has had his next dialog
			Locations[FindLocation("Douwesen_shore_ship")].reload.l2.disable = 1;
			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_ActorRunToLocation(characterFromID("Gentleman Jocard"), "reload", "reload1", "none", "", "", "Jocard_Ranger", 0.0);
//			Characters[GetCharacterIndex("Gentleman Jocard")].model = "Corsair1_3";
//			Characters[GetCharacterIndex("Gentleman Jocard")].headmodel = "h_Corsair1_3";
		break;

		case "Jocard_Ranger":
			SetModelFromID(CharacterFromID("Gentleman Jocard"), "Corsair1_3");
			ChangeCharacterAddress(characterfromID("Gentleman Jocard"),"none", "");
			RemovePassenger(pchar, characterFromID("Gentleman Jocard"));
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Gentleman Jocard"));
			SetCharacterRemovable(characterFromID("Gentleman Jocard"), false);

			LAi_SetActorType(characterfromID("Bos'un"));
			LAi_ActorDialog(characterFromID("Bos'un"),PChar,"",100.0,100.0);
			Characters[GetCharacterIndex("Bos'un")].dialog.currentnode = "Plan";

			pchar.Alantic_PL = "Black_Jocard";
		break;

		case "To_Eleuthera":								// Triggered by dialog with Bos'un
			DisableFastTravel(false);						// Dialog done, you can leave now
			Locations[FindLocation("Douwesen_shore_ship")].reload.l1.disable = 0;
			Locations[FindLocation("Douwesen_shore_ship")].reload.l2.disable = 0;
			LAi_SetOfficerType(characterFromID("Bos'un"));

			pchar.quest.Jocard_follow.win_condition.l1 = "location";
			pchar.quest.Jocard_follow.win_condition.l1.location = "Eleuthera";
			pchar.quest.Jocard_follow.win_condition = "Jocard_follow";

			pchar.quest.wrong_Eleuthera1.win_condition.l1 = "location";
			pchar.quest.wrong_Eleuthera1.win_condition.l1.location = "Eleuthera_Port";
			pchar.quest.wrong_Eleuthera1.win_condition = "wrong_Eleuthera1";

			pchar.quest.wrong_Eleuthera2.win_condition.l1 = "location";
			pchar.quest.wrong_Eleuthera2.win_condition.l1.location = "EleutheraPlantation";
			pchar.quest.wrong_Eleuthera2.win_condition = "wrong_Eleuthera2";

			pchar.quest.right_Eleuthera.win_condition.l1 = "location";
			pchar.quest.right_Eleuthera.win_condition.l1.location = "Eleuthera_Tavern";
			pchar.quest.right_Eleuthera.win_condition = "right_Eleuthera";
		break;

		case "Jocard_follow":
			LAi_SetActorType(CharacterfromID("Gentleman Jocard"));
			LAi_ActorFollowEverywhere(characterFromID("Gentleman Jocard"), "", 60.0);
		break;

		case "Wrong_Eleuthera1":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto8");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "Gentleman Jocard (White)_dialog.c";
			sld.name = "Soldier";
			sld.lastname = "";
			sld.id = "sol_Slave1";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto8");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.name = "Soldier";
			sld.lastname = "";
			sld.id = "sol_Slave2";

			LAi_SetActorType(characterfromID("sol_Slave1"));
			LAi_SetActorType(characterfromID("sol_Slave2"));
			LAi_ActorFollow(characterFromID("sol_Slave2"), characterFromID("sol_Slave1"), "", 100.0);
			characters[GetCharacterIndex("sol_Slave1")].dialog.currentnode = "hang";
			LAi_ActorDialog(characterFromID("sol_Slave1"),PChar,"",100.0,100.0);
		break;

		case "Blaze_Jocard_Bos'un_Hung":
			pchar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "mutiny");
		break;

		case "Wrong_Eleuthera2":
			pchar.quest.wrong_Eleuthera1.over = "yes";
			pchar.quest.right_Eleuthera.over = "yes";

			RemoveOfficersIndex(pchar, GetCharacterIndex("Bos'un"));
			RemovePassenger(pchar, characterFromID("Bos'un"));
			ChangeCharacterAddressGroup(pchar, "EleutheraPlantation", "goto", "goto18");
			ChangeCharacterAddressGroup(characterFromID("Bos'un"), "EleutheraPlantation", "goto", "goto18");
			ChangeCharacterAddressGroup(characterFromID("Gentleman Jocard"), "EleutheraPlantation", "goto", "goto18");

			ChangeCharacterAddressGroup(characterFromID("Slaver1"), "EleutheraPlantation", "goto", "goto17");
			ChangeCharacterAddressGroup(characterFromID("Slaver2"), "EleutheraPlantation", "goto", "goto17");
			ChangeCharacterAddressGroup(characterFromID("Slaver3"), "EleutheraPlantation", "goto", "goto17");

			//LAi_SetActorType(pchar);
			LAi_QuestDelay("Slaver_chat_before", 0.0);
		break;

		case "Slaver_chat_before":
			characters[GetCharacterIndex("Slaver1")].dialog.currentnode = "knock out";

			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_SetActorType(characterfromID("Bos'un"));
			LAi_ActorFollow(characterFromID("Gentleman Jocard"), pchar, "", 100.0);
			LAi_ActorFollow(characterFromID("Bos'un"), pchar, "", 100.0);

			LAi_SetActorType(characterfromID("Slaver1"));
			LAi_SetActorType(characterfromID("Slaver2"));
			LAi_SetActorType(characterfromID("Slaver3"));
			LAi_ActorFollow(characterFromID("Slaver3"), characterFromID("Slaver3"), "", 100.0);
			LAi_ActorFollow(characterFromID("Slaver2"), characterFromID("Slaver3"), "", 100.0);
			LAi_ActorDialog(characterFromID("Slaver1"),PChar,"",100.0,100.0);
		break;

		case "Slaver_knock":
			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_SetActorType(characterfromID("Bos'un"));
			LAi_SetActorType(characterfromID("Slaver1"));
			LAi_SetActorType(characterfromID("Slaver2"));
			LAi_SetActorType(characterfromID("Slaver3"));

			LAi_group_MoveCharacter(characterFromID("Slaver2"), "SLAVERS1");
			LAi_group_MoveCharacter(characterFromID("Slaver3"), "SLAVERS2");
			LAi_group_MoveCharacter(characterFromID("Gentleman Jocard"), "PLAYER1");
			LAi_group_MoveCharacter(characterFromID("Bos'un"), "PLAYER2");

			LAi_group_FightGroups("SLAVERS1", "PLAYER2", true);
			LAi_group_FightGroups("SLAVERS2", "PLAYER1", true);
			LAi_ActorAttack(CharacterFromID("Slaver1"), PChar, "");

			bSuppressResurrection = true;
			pchar.KO = "0";

			LAi_SetCheckMinHP(characterFromID("Gentleman Jocard"), 0.4*LAi_GetCharacterHP(characterFromID("Gentleman Jocard")), true, "knock1");
			LAi_SetCheckMinHP(characterFromID("Bos'un"), 0.4*LAi_GetCharacterHP(characterFromID("Bos'un")), true, "knock2");
			LAi_SetHP(characterFromID("Bos'un"), 150, 200);
			LAi_SetImmortal(characterFromID("Bos'un"), false);
			LAi_SetImmortal(characterFromID("Gentleman Jocard"), false);
			LAi_SetImmortal(characterFromID("Slaver1"), true);
			LAi_SetImmortal(characterFromID("Slaver2"), true);
			LAi_SetImmortal(characterFromID("Slaver3"), true);
			//LAi_QuestDelay("Slaver_knock2", 4.0);
		break;

		case "knock1":
			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_ActorAnimation(characterFromID("Gentleman Jocard"), "death_1", "lay_mode1", 3.0);
			//KO = KO + 1;

			if (GetAttribute(Pchar, "KO") == "0")
			{
				pchar.KO1 = "1";
				//LAi_group_FightGroups("SLAVERS2", "PLAYER1", false);
				//LAi_group_FightGroups("SLAVERS2", "PLAYER2", true);
			}
			if (GetAttribute(Pchar, "KO1") == "1" && GetAttribute(Pchar, "KO2") == "1")
			{
				LAi_QuestDelay("Slaver_knock2", 4.0);
			}
		break;

		case "knock2":
		LAi_SetActorType(characterfromID("Bos'un"));
		LAi_ActorAnimation(characterFromID("Bos'un"), "death_0", "lay_mode2", 3.0);
			//KO = KO + 1;

			if (GetAttribute(Pchar, "KO") == "0")
			{
				pchar.KO2 = "1";
				//LAi_group_FightGroups("SLAVERS1", "PLAYER2", false);
				//LAi_group_FightGroups("SLAVERS1", "PLAYER1", true);	
			}
			if (GetAttribute(Pchar, "KO1") == "1" && GetAttribute(Pchar, "KO2") == "1")
			{
				LAi_QuestDelay("Slaver_knock2", 4.0);
			}
		break;

		case "lay_mode1":
			LAi_ActorAnimation(characterFromID("Gentleman Jocard"), "Lay_1", "", -1);
		break;

		case "lay_mode2":
			LAi_ActorAnimation(characterFromID("Bos'un"), "Lay_1", "", -1);
		break;

		case "Slaver_knock2":
			Lai_KillCharacter(pchar);
			LAi_QuestDelay("Slaver_knock3", 6.0);
		break;

		case "Slaver_knock3":
			AddMoneyToCharacter(PChar, -5000);

			DoQuestReloadToLocation("Eleuthera_Jungle4", "goto", "goto5", "_");
			ChangeCharacterAddressGroup(characterFromID("Gentleman Jocard"),"Eleuthera_Jungle4", "goto", "goto6");
			ChangeCharacterAddressGroup(characterFromID("Bos'un"),"Eleuthera_Jungle4", "goto", "goto2");
			LAi_SetPlayerType(pchar);
			LAi_SetHP(pchar, LAi_GetCharacterHP(pchar), LAi_GetCharacterHP(pchar));
			LAi_SetActorType(characterFromID("Bos'un"));
			LAi_SetHP(characterFromID("Bos'un"), LAi_GetCharacterHP(characterFromID("Bos'un")), LAi_GetCharacterHP(characterFromID("Bos'un")));
			LAi_SetActorType(characterFromID("Gentleman Jocard"));
			LAi_SetHP(characterFromID("Gentleman Jocard"), LAi_GetCharacterHP(characterFromID("Gentleman Jocard")), LAi_GetCharacterHP(characterFromID("Gentleman Jocard")));

			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_SetActorType(characterfromID("Bos'un"));
			LAi_ActorFollow(characterFromID("Bos'un"), PChar, "", 100.0);
			LAi_ActorDialog(characterFromID("Gentleman Jocard"),PChar,"",100.0,100.0);
			characters[GetCharacterIndex("Gentleman Jocard")].dialog.currentnode = "knock out";

			bSuppressResurrection = false;
		break;

		case "Slaver_knock4":
			LAi_ActorRunToLocation(characterFromID("Gentleman Jocard"), "reload", "reload3_back", "none", "", "", "", 0.0);

			LAi_SetActorType(characterfromID("Bos'un"));
			LAi_ActorDialog(characterFromID("Bos'un"),PChar,"",100.0,100.0);
			characters[GetCharacterIndex("Bos'un")].dialog.currentnode = "crew";
		break;

		case "Slaver_knock5":
			LAi_ActorRunToLocation(characterFromID("Bos'un"), "reload", "reload3_back", "none", "", "", "", 0.0);
			RemoveCharacterCompanion(pchar, characterFromID("Gentleman Jocard"));

			ChangeCharacterAddressGroup(characterFromID("Slave1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slave2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slave3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slave4"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slave5"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slave6"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slave7"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slaver1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slaver2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slaver3"), "none", "", "");

			AddQuestRecord("Jocard", 18);
			CloseQuestHeader("Jocard");
		break;

		case "right_Eleuthera":
			pchar.quest.wrong_Eleuthera1.over = "yes";
			pchar.quest.wrong_Eleuthera2.over = "yes";

			ChangeCharacterAddressGroup(CharacterFromID("Gentleman Jocard"), "Eleuthera_Tavern", "goto", "goto2");
			LAi_SetActorType(CharacterfromID("Gentleman Jocard"));
			LAi_ActorDialog(CharacterFromID("Gentleman Jocard"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Gentleman Jocard")].dialog.currentnode = "In Tavern";

			pchar.quest.right_Eleuthera2.win_condition.l1 = "location";
			pchar.quest.right_Eleuthera2.win_condition.l1.location = "EleutheraPlantation";
			pchar.quest.right_Eleuthera2.win_condition = "right_Eleuthera2";

			AddQuestRecord("Jocard", 16);
		break;

		case "right_Eleuthera2":
			ChangeCharacterAddressGroup(characterFromID("slaver1"), "EleutheraPlantation", "goto", "goto17");

			LAi_SetActorType(characterFromID("slaver1"));
			LAi_SetWarriorType(characterFromID("slaver2"));
			LAi_SetWarriorType(characterFromID("slaver3"));
			LAi_warrior_SetCommander(characterFromID("slaver2"), characterFromID("slaver1"));
			LAi_warrior_SetCommander(characterFromID("slaver3"), characterFromID("slaver1"));
			LAi_ActorDialog(CharacterFromID("Slaver1"), PChar, "", 100.0, 100.0);
			Characters[GetCharacterIndex("Slaver1")].dialog.currentnode = "Halt";
			LAi_ActorWaitDialog(CharacterFromID("slaver1"), PChar);
		break;

		case "Killing_slave_guards":
			LAi_group_MoveCharacter(characterFromID("Slaver1"), "SLAVER_PLANT");
			LAi_group_MoveCharacter(characterFromID("Slaver2"), "SLAVER_PLANT");
			LAi_group_MoveCharacter(characterFromID("Slaver3"), "SLAVER_PLANT");
			LAi_SetOfficerType(characterfromID("Gentleman Jocard"));
			LAi_group_FightGroups("SLAVER_PLANT", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SLAVER_PLANT", "Killing_slave_guards_fin");
		break;

		case "Killing_slave_guards_fin":
			pchar.Slaves = "free";

			LAi_SetActorType(characterFromID("Slave5"));
			LAi_ActorDialog(CharacterFromID("Slave5"), PChar, "", 100.0, 100.0);
		break;

		case "Jocard_Deck":
			QDeck = GetCharacterShipQDeck(characterFromID("Gentleman Jocard"));
			DoQuestReloadToLocation(QDeck, "rld", "startloc", "Jocard_Deck2");
		break;

		case "Jocard_Deck2":
			SetCharacterToNearLocatorFromMe("Gentleman Jocard", 3);
			SetCharacterToNearLocatorFromMe("Bos'un", 20);

			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_ActorDialog(characterFromID("Gentleman Jocard"),PChar,"",10.0,10.0);
			Characters[GetCharacterIndex("Gentleman Jocard")].dialog.currentnode = "On_Deck";
		break;

		case "Jocard_Deck3":
			LAi_SetWarriorType(characterFromID("Bos'un"));
			LAi_warrior_SetCommander(characterFromID("Bos'un"), characterFromID("Gentleman Jocard"))
			LAi_QuestDelay("Jocard_Deck3.5", 10.0);
		break;

		case "Jocard_Deck3.5":
			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_ActorDialog(characterFromID("Gentleman Jocard"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Gentleman Jocard")].dialog.currentnode = "On_Deck2";
		break;

		case "Jocard_Deck4":
			LAi_SetActorType(characterfromID("Bos'un"));
			LAi_ActorDialog(characterFromID("Bos'un"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Bos'un")].dialog.currentnode = "On_Deck";
		break;

		case "Jocard_Deck5":
			LAi_ActorTurnToCharacter(characterfromID("Bos'un"),characterFromID("Gentleman Jocard"));
			LAi_SetActorType(characterfromID("Gentleman Jocard"));
			LAi_ActorDialog(characterFromID("Gentleman Jocard"),PChar,"",1.0,1.0);
			Characters[GetCharacterIndex("Gentleman Jocard")].dialog.currentnode = "On_Deck3";
		break;

		case "Jocard_Deck6":
			LAi_SetActorType(CharacterFromID("Bos'un"));

			LAi_ActorAnimation(CharacterFromID("Bos'un"), "attack_2", "Jocard_Deck7", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
		break;

		case "Jocard_Deck7":
			LAi_SetActorType(characterfromID("Gentleman Jocard"));

			LAi_ActorAnimation(CharacterFromID("Gentleman Jocard"), "death_2", "Leave_Jocard", 4.0);
		break;

		case "Leave_Jocard":
			RemoveCharacterCompanion(pchar, characterFromID("Gentleman Jocard"));
			ChangeCharacterAddressGroup(characterFromID("Gentleman Jocard"), "none", "", "");
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bos'un"));
			RemovePassenger(pchar, characterFromID("Bos'un"));

			Characters[GetCharacterIndex("Gentleman Jocard")].nation = PERSONAL_NATION;
			Group_CreateGroup("Gentleman Jocard");
			Group_AddCharacter("Gentleman Jocard", "Gentleman Jocard");
			Group_SetGroupCommander("Gentleman Jocard", "Gentleman Jocard");
			Group_SetPursuitGroup("Gentleman Jocard", PLAYER_GROUP);
			Group_SetTaskNone("Gentleman Jocard")
			Group_LockTask("Gentleman Jocard");
			Group_SetAddress("Gentleman Jocard", "Eleuthera", "Quest_ships", "Quest_ship_12");
			Ship_SetTaskDrift(1.0, CharacterFromID("Gentleman Jocard")); 
			Character_SetAbordageEnable(characterFromID("Gentleman Jocard"), false);

			QuestToSeaLogin_PrepareLoc("Eleuthera", "reload", "reload_3", false);
			QuestToSeaLogin_Launch();

			AddQuestRecord("Jocard", 17);
			CloseQuestHeader("Jocard");

			pchar.quest.Jocard_goes.win_condition.l1 = "MapEnter";
			pchar.quest.Jocard_goes.win_condition = "Jocard_goes";
		break;

		case "Jocard_goes":
			Group_SetAddressNone("Gentleman Jocard");
		break;
			
		case "voysey_No_Fight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), CharacterFromID("Gentleman Jocard"), "");
		break;

		case "voysey_Fight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_3"), PChar, "");
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1.character = "Pirates_1";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2.character = "Pirates_2";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3.character = "Pirates_3";
			PChar.quest.Story_KillNygelBlythe4.win_condition = "Voysey_death";
		break;

		case "voysey_found_treasure":
			pchar.quest.treasure_found.win_condition.l1 = "locator";
			pchar.quest.treasure_found.win_condition.l1.location = "Douwesen_Shore_ship";
			pchar.quest.treasure_found.win_condition.l1.locator_group = "randitem";
			pchar.quest.treasure_found.win_condition.l1.locator = "randitem1";
			pchar.quest.treasure_found.win_condition = "treasure_found";
		break;

		case "Leave_Voysey":
			LAi_SetPlayerType(PChar);
			LAi_SetCitizenType(CharacterFromID("Gentleman Jocard")); 
		break;

		case "voysey_final_nofight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), CharacterFromID("Gentleman Jocard"), "");
		break;

		case "voysey_final_fight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_3"), PChar, "");
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1.character = "Pirates_1";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2.character = "Pirates_2";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3.character = "Pirates_3";
			PChar.quest.Story_KillNygelBlythe4.win_condition = "Voysey_death";
		break;

		case "Nigel_listed":
			AddQuestRecord("Slaver", 2);
			Pchar.quest.Nigel_Blythe.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe.win_condition.l1.location = "Douwesen_PORT";
			PChar.quest.Nigel_Blythe.win_condition = "Nigel_Adventure";

			AddMoneyToCharacter(PChar, -3000);
			LAi_SetPlayerType(pchar);
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Slaver")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Slaver"));
		break;

		case "Nigel_listed2":
			AddQuestRecord("Slaver", 2);
			Pchar.quest.Nigel_Blythe.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe.win_condition.l1.location = "Douwesen_PORT";
			PChar.quest.Nigel_Blythe.win_condition = "Nigel_Adventure";

			AddMoneyToCharacter(PChar, -300);
			LAi_SetPlayerType(pchar);
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Slaver")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Slaver"));
		break;

		case "Leave_Nigel":
			AddQuestRecord("Slaver", 3);
			LAi_SetPlayerType(PChar);
			LAi_SetCitizenType(CharacterFromID("Slaver")); 
		break;

		case "Artois_Blythe":
			SendMessage(&Characters[GetCharacterIndex("Gentleman Jocard")],"lsl", MSG_CHARACTER_EX_MSG , "SetFightMode", true);
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Gentleman Jocard"), PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Gentleman Jocard"), "", 10, 10);
		break;

		case "Nigel_Adventure":
			//if (!LAi_IsDead(characterFromID("Slaver")))
			//{
				if(FindFellowTravellers(PChar, CharacterFromID("Slaver")) == FELLOWTRAVEL_PASSENGER || FindFellowTravellers(PChar, CharacterFromID("Slaver")) == FELLOWTRAVEL_OFFICER)
				{
					AddQuestRecord("Slaver", 4);
					//pchar.quest.Nigel_lost = "1";

					if (!IsOfficer(CharacterFromID("Slaver")))			// GR: This case can trigger if he is a passenger but not an officer
					{								// GR: "To_Ship_Slaver" relies on him being an officer, so if he is not,
						PlaceCharacter(CharacterFromID("Slaver"), "goto");	// GR: force him to become an officer
						SetOfficersIndex(PChar, 3, GetCharacterIndex("Slaver"));
					}

					//LAi_SetActorType(Pchar);
					//Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
					//Pchar.dialog.currentnode = "nigel_lost";
					//LAi_ActorSelfDialog(Pchar, "player_back");
					//RemoveOfficersIndex(pchar, GetCharacterIndex("Slaver"));
					//RemovePassenger(pchar, characterFromID("Slaver"));
					LAi_SetActorType(CharacterFromID("Slaver"));
					characters[getCharacterIndex("Slaver")].dialog.currentnode = "Treasure_Port";
					LAi_ActorDialog(CharacterFromID("Slaver"), PChar, "", 100.0, 100.0);
					//LAi_SetSitType(CharacterFromID("Slaver"));
					//ChangeCharacterAddressGroup(CharacterFromID("Slaver"), "Redmond_tavern", "sit", "sit8");	// Petros ... was Oxbay_Tavern
				}
			//}
		break;

		case "To_Ship_Slaver":
			if (IsOfficer(characterFromID("Slaver")))
			{
				LAi_SetActorType(characterFromID("Slaver"));
				//LAi_ActorWaitDialog(PChar, CharacterFromID("Slaver"));
				characters[getCharacterIndex("Slaver")].dialog.currentnode = "Treasure_Ship";
				LAi_ActorDialog(CharacterFromID("Slaver"), PChar, "", 100.0, 100.0);
			}
		break;

		case "Jocard_Plantation":
			changeCharacterAddressGroup(characterFromID("Gentleman Jocard (White)"), "Jocard_house", "goto", "locator3");
			LAi_SetActorType(characterFromID("Gentleman Jocard (White)"));
			LAi_ActorDialog(PChar, CharacterFromID("Gentleman Jocard (White)"), "", 10, 10);
			LAi_ActorWaitDialog(CharacterFromID("Gentleman Jocard (White)"), PChar);

			pchar.quest.Jocard_Plantation2.win_condition.l1 = "location";
			pchar.quest.Jocard_Plantation2.win_condition.l1.location = "EleutheraPlantation";
			pchar.quest.Jocard_Plantation2.win_condition = "Jocard_Plantation2";
		break;

		case "Jocard_Plantation2":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "nigel_lost";
			LAi_ActorSelfDialog(Pchar, "player_back");
			Locations[FindLocation("EleutheraPlantation")].reload.l2.disable = false;

			RemovePassenger(Pchar, characterFromID("Slaver"));
			RemoveOfficersIndex(Pchar, GetCharacterIndex("Slaver"));
			ChangeCharacterAddressGroup(characterFromID("Slaver"), "Jocard_house", "goto", "locator2");
			LAi_SetActorType(characterFromID("Slaver"));

			AddQuestRecord("Slaver", 6);
		break;

		case "not_killing_PL":
//			LAi_SetActorType(characterFromID("Gentleman Jocard (White)"));
//			LAi_ActorWaitDialog(CharacterFromID("Gentleman Jocard (White)"), PChar);
			LAi_SetMerchantType(characterFromID("Gentleman Jocard (White)"));

			if (GetAttribute(pchar, "PL_NF") != "1")
			{
				AddQuestRecord("Slaver", 7);
				pchar.PL_NF = "1";
				if (GetAttribute(pchar, "Turks") == "0")
				{
					CloseQuestHeader("Slaver");
					AddQuestRecord("Pirate Lord", 12);
				}
			}
		break;

		case "killing_PL":
			RemovePassenger(Pchar, characterFromID("Slaver"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Slaver"));

			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetImmortal(characterFromID("Slaver"), false);

			LAi_group_MoveCharacter(characterFromID("Gentleman Jocard (White)"), "SLAVER_PLANT");
			LAi_group_MoveCharacter(characterFromID("Slaver"), "SLAVER_PLANT");
			LAi_group_FightGroups("SLAVER_PLANT", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SLAVER_PLANT", "Killing_PL_cont");
		break;

		case "Killing_PL_cont":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);

			pchar.quest.Killing_PL_cont2.win_condition.l1 = "Location";
			pchar.quest.Killing_PL_cont2.win_condition.l1.location = "EleutheraPlantation";
			pchar.quest.Killing_PL_cont2.win_condition = "Killing_PL_cont2";
		break;

		case "Killing_PL_cont2":
			ChangeCharacterAddressGroup(characterFromID("Slaver"), "none", "", "");

			LAi_group_MoveCharacter(characterFromID("Slaver1"), "SLAVER_PLANT");
			LAi_group_MoveCharacter(characterFromID("Slaver2"), "SLAVER_PLANT");
			LAi_group_MoveCharacter(characterFromID("Slaver3"), "SLAVER_PLANT");
			LAi_group_FightGroups("SLAVER_PLANT", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SLAVER_PLANT", "Killing_PL_fin");
		break;

		case "Killing_PL_fin":
			pchar.Alantic_PL = "none";
			pchar.Slaves = "free";
			if (GetAttribute(Pchar, "Turks") == "Brotherhood")
			{
				AddQuestRecord("Slaver", 8);
				StoreDialog(CharacterFromID("Nathan Kell"));
				Characters[GetCharacterIndex("Nathan Kell")].dialog.filename = "Nathan Kell_dialog.c";
				Characters[GetCharacterIndex("Nathan Kell")].dialog.currentnode = "Jocard_dead";
			}
			else
			{
				characters[GetCharacterIndex("Slave5")].dialog.filename = "Gentleman Jocard_dialog.c";
				characters[getCharacterIndex("Slave5")].dialog.currentnode = "guards_dead";
			}

			LAi_SetActorType(characterFromID("Slave5"));
			LAi_ActorDialog(CharacterFromID("Slave5"), PChar, "", 100.0, 100.0);
		break;

		case "Killing_PL_talked_to_Kell":
//			Characters[GetCharacterIndex("Nathan Kell")].dialog.filename = "Nathan Kell (GOV)_dialog.c";
			RestoreDialog(CharacterFromID("Nathan Kell"));
			AddQuestRecord("Slaver", 9);
			PChar.Alantic_PL = "none1";
		break;

		case "reset_slave5":	// Triggered by dialog with "Slave5" if he has just become Gentleman Jocard
			characters[GetCharacterIndex("Slave5")].dialog.filename = "Plantation_Slave.c";
			characters[getCharacterIndex("Slave5")].dialog.currentnode = "First time";
			AddQuestRecord("Slaver", 11);
			CloseQuestHeader("Slaver");
			AddQuestRecord("Pirate Lord", 13);
		break;

		case "slaves_run":	// Triggered by dialog with "Slave5"
			ChangeCharacterAddressGroup(characterFromID("Slaver1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slaver2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Slaver3"), "none", "", "");

			LAi_SetActorType(characterFromID("Slave1"));
			LAi_ActorRunToLocation(characterFromID("Slave1"), "reload", "reload2_back", "none", "", "", "", 100.0);
			LAi_SetActorType(characterFromID("Slave2"));
			LAi_ActorRunToLocation(characterFromID("Slave2"), "reload", "reload2_back", "none", "", "", "", 100.0);
			LAi_SetActorType(characterFromID("Slave3"));
			LAi_ActorRunToLocation(characterFromID("Slave3"), "reload", "reload2_back", "none", "", "", "", 100.0);
			LAi_SetActorType(characterFromID("Slave4"));
			LAi_ActorRunToLocation(characterFromID("Slave4"), "reload", "reload2_back", "none", "", "", "", 100.0);
			LAi_SetActorType(characterFromID("Slave5"));
			LAi_ActorRunToLocation(characterFromID("Slave5"), "reload", "reload2_back", "none", "", "", "", 100.0);
			LAi_SetActorType(characterFromID("Slave6"));
			LAi_ActorRunToLocation(characterFromID("Slave6"), "reload", "reload2_back", "none", "", "", "", 100.0);
			LAi_SetActorType(characterFromID("Slave7"));
			if (GetAttribute(Pchar, "Alantic_PL") == "Black_Jocard")
			{
//				LAi_ActorRunToLocation(characterFromID("Slave7"), "reload", "reload2_back", "none", "", "", "Jocard_deck", 100.0);
				LAi_ActorRunToLocation(characterFromID("Slave7"), "goto", "goto27", "none", "", "", "Jocard_deck", 100.0);
			}
			else
			{
				LAi_ActorRunToLocation(characterFromID("Slave7"), "reload", "reload2_back", "none", "", "", "", 100.0);
			}
		break;

		case "Voysey_death":
			characters[GetCharacterIndex("Gentleman Jocard")].dialog.currentnode = "continue3";
		break;

		case "Kill_Slaver":
			EquipCharacterByItem(CharacterFromId("Slaver"), "blade6");

			PChar.quest.BlazeKilledFightingWithNigel.win_condition.l1 = "NPC_Death";
			PChar.quest.BlazeKilledFightingWithNigel.win_condition.l1.character = PChar.id;
			PChar.quest.BlazeKilledFightingWithNigel.win_condition = "BlazeKilledFightingWithSlaver";

			LAi_SetImmortal(characterFromID("Slaver"), false);
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(CharacterFromID("Slaver"), "Slaver");
			LAi_group_FightGroups("Slaver", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("Slaver", "slaver_killed");
		break;

		case "slaver_killed":
			pchar.quest.BlazeKilledFightingWithSlaver.over = "yes";

			AddQuestRecord("Slaver", 28);
			CloseQuestHeader("Slaver");

			LAi_SetPlayerType(PChar);
		break;

		case "BlazeKilledFightingWithSlaver":
			bSuppressResurrection = true;
			LAi_SetActorType(CharacterFromID("Slaver"));
			SendMessage(&locCamera, "li", MSG_CAMERA_SETTARGET, CharacterFromID("Slaver"));
			locCameraFollow();
			LAi_ActorGoToLocation(CharacterFromID("Slaver"), "reload", "reload1", "none", "", "", "AfterKillingBlazeAsSlaver", 100);
			SendMessage(&Characters[GetCharacterIndex("Slaver")],"lsl", MSG_CHARACTER_EX_MSG , "SetFightMode", true);
		break;

		case "AfterKillingBlazeAsSlaver":
			EndQuestMovie();TrackQuestMovie("end","AfterKillingBlazeAsSlaver");
			bSuppressResurrection = false;

			pchar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "land");
		break;
//Gentleman Jocard

		PChar.questnotfound = true; // PB: Testing
	}
}
