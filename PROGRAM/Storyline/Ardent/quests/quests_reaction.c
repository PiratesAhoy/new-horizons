void QuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld, ch, ImpShip;
// KK -->
	int iPassenger, cidx, iHP, cc, crew_lost, crew_left, i, n;
	ref officer1, officer2, romance, villain, arrester, crewref;
	int officer1idx, officer2idx, romanceidx, villainidx, arresteridx, crewidx;
	float locx, locy, locz;
	string speaker, homelocation, homegroup, homelocator, gov_kid, merch_kid, romance_name, villain_name, normal_dialog, romance_pronoun1, romance_pronoun2, romance_pronoun3, villain_pronoun, temp, attr, cabin;
	int canQty = 0;
	int crewQty = 0;
	int survivors = 0;
// <-- KK
	aref arship; // PB
	aref PChar_land, PChar_quest_land;

	PChar = GetMainCharacter();

	officer1 = characterFromID("Louwe Louwman");
	officer2 = characterFromID("Giraldo Annibal");
	officer1idx = getCharacterIndex("Louwe Louwman");
	officer2idx = getCharacterIndex("Giraldo Annibal");

	if (PChar.old.name == "Charles" && PChar.sex != "man") GiveModel2Player("Ardent", true);
	if (PChar.old.name == "Helen" && PChar.sex != "woman") GiveModel2Player("Ardent_F", true);

	if (CheckQuestAttribute("alignment", "evil"))
	{
		officer1 = characterFromID("Gheerkin Kamalaas");
		officer2 = characterFromID("Morys Badlad");
		officer1idx = getCharacterIndex("Gheerkin Kamalaas");
		officer2idx = getCharacterIndex("Morys Badlad");
	}

	if (PChar.sex == "man")
	{
		romance = characterFromID("Lucia de la Vega");
		romanceidx = getCharacterIndex("Lucia de la Vega");
		villain = characterFromID("Piers Downing");
		villainidx = getCharacterIndex("Piers Downing");
		LAi_SetStayType(characterfromID("Piers Downing"));
		gov_kid = XI_ConvertString("daughter");
		merch_kid = XI_ConvertString("son");
	}
	else
	{
		romance = characterFromID("Edmundo de la Vega");
		romanceidx = getCharacterIndex("Edmundo de la Vega");
		villain = characterFromID("Valerie Downing");
		villainidx = getCharacterIndex("Valerie Downing");
		LAi_SetStayType(characterfromID("Valerie Downing"));
		gov_kid = XI_ConvertString("son");
		merch_kid = XI_ConvertString("daughter");
	}
	romance_pronoun1 = XI_ConvertString(GetMyPronounSubj(romance));
	romance_pronoun2 = XI_ConvertString(GetMyPronounObj(romance));
	romance_pronoun3 = XI_ConvertString(GetMyPronounPossessive(romance));
	villain_pronoun = XI_ConvertString(GetMyPronounObj(villain));
	PChar.quest.romance = romance.id;
	PChar.quest.villain = villain.id;
	LAi_SetActorType(villain);
	LAi_ActorTurnToLocator(villain, "reload", "reload1");
	LAi_SetStayType(villain);

	if (!CheckAttribute(PChar, "quest.background")) PChar.quest.background = "pirate";	// Failsafe in case "background" attribute hasn't been set by Inquisitor
	
	switch(sQuestName)
	{
		case "StartAdventure":
			DisableTownCapture("Redmond", true);
			DisableTownCapture("Santiago", true);
			DisableTownCapture("Port au Prince", true);
			Locations[FindLocation("Quest_Santiago_Bedroom")].vcskip = true;
			if (PChar.sex == "man")
			{
				ChangeCharacterAddress(characterFromID("Edmundo de la Vega"), "None", "");
				ChangeCharacterAddress(characterFromID("Valerie Downing"), "None", "");
				ChangeCharacterAddressGroup(characterfromID("Piers Downing"), "Quest_Merchant_House", "goto", "goto2");
			}
			else
			{
				ChangeCharacterAddress(characterFromID("Lucia de la Vega"), "None", "");
				ChangeCharacterAddress(characterFromID("Piers Downing"), "None", "");
				ChangeCharacterAddressGroup(characterfromID("Valerie Downing"), "Quest_Merchant_House", "goto", "goto2");
			}
			Locations[FindLocation("Havana_prison")].vcskip = true;
			Locations[FindLocation("Havana_prison")].reload.l1.disable = 1;
			Locations[FindLocation("Havana_prison")].locators_radius.reload.reload11 = 3.0;
			Locations[FindLocation("Havana_prison")].locators_radius.reload.reload9 = 2.5;
			Locations[FindLocation("Cuba_Jungle_02")].locators_radius.monsters.monster1 = 2.0;
			DisableFastTravel(true);

			DeleteAttribute(pchar, "Ship");
			pchar.Ship.Type = SHIP_NOTUSED_TYPE_NAME;
			pchar.Ship.Name = "";
			PChar.isnotcaptain = true;

			GiveItem2Character(characterfromID("Warden"), "key4");

			GiveItem2Character(characterfromID("Havana Prison Commandant"), "key3");
			GiveItem2Character(characterfromID("Havana Prison Commandant"), "spyglass2");
			GiveItem2Character(characterfromID("Havana Prison Commandant"), "compass2");
			GiveItem2Character(characterfromID("Havana Prison Commandant"), "clock1");
			GiveItem2Character(characterfromID("Havana Prison Commandant"), "SecurityLetter");

			Characters[GetCharacterIndex("Spanish_guard1")].issoldier = 0;	// So they aren't assigned to the wrong AI group and don't attack prematurely if you murder the warden
			Characters[GetCharacterIndex("Spanish_guard2")].issoldier = 0;
			Characters[GetCharacterIndex("Spanish_guard3")].issoldier = 0;
			Characters[GetCharacterIndex("Warden")].pickgold = 0;		// Give him the pickpocket attribute so you don't lose reputation for stunning and robbing the warden

			Pchar.quest.get_monkey.win_condition.l1 = "locator";
			Pchar.quest.get_monkey.win_condition.l1.location = "Cuba_Jungle_02";
			Pchar.quest.get_monkey.win_condition.l1.locator_group = "monsters";
			Pchar.quest.get_monkey.win_condition.l1.locator = "monster1";
			Pchar.quest.get_monkey.win_condition = "get_monkey";

			Pchar.quest.got_Cuba_map.win_condition.l1 = "item";
			PChar.quest.got_Cuba_map.win_condition.l1.character = Pchar.id;
			Pchar.quest.got_Cuba_map.win_condition.l1.item = "mapCuba";
			Pchar.quest.got_Cuba_map.win_condition = "got_Cuba_map";

			SetNextWeather("Clear");
			DoQuestReloadToLocation("Havana_prison", "goto", "goto24", "In_jail");
		break;

		case "get_monkey":
			if (CheckAttribute(PChar, "quest.monkey_follow"))
			{
				PChar.quest.monkey_follow.over = "yes";
			}

			if (!CheckAttribute(PChar, "quest.monkey_farewell"))
			{
				Locations[FindLocation("Muelle_Cave")].vcskip = true;		// Don't want bandits near Animist cave when monkeys are there
				PChar.quest.monkey_farewell.win_condition.l1 = "location";
				PChar.quest.monkey_farewell.win_condition.l1.location = "Muelle_Cave";
				PChar.quest.monkey_farewell.win_condition = "monkey_farewell";
			}
			LAi_SetActorType(characterFromID("Monkey"));
			LAi_ActorDialog(characterFromID("Monkey"),PChar,"monkey_follow",5.0,5.0);
		break;

		case "monkey_follow":
			if (PChar.location != "Muelle_Cave")
			{
				LAi_ActorFollowEverywhere(CharacterFromID("Monkey"), "", 1.0);
				Pchar.quest.monkey_follow.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.monkey_follow.win_condition.l1.character = Pchar.id;
				PChar.quest.monkey_follow.win_condition.l1.location = PChar.location;
				Pchar.quest.monkey_follow.win_condition = "get_monkey";
			}
		break;

		case "monkey_farewell":
			Pchar.quest.monkey_follow.over = "yes";
			ChangeCharacterAddressGroup(characterfromID("Monkey2"), "Muelle_Cave", "monsters", "monster1");
			ChangeCharacterAddressGroup(characterfromID("Monkey3"), "Muelle_Cave", "monsters", "monster2");
			ChangeCharacterAddressGroup(characterfromID("Monkey4"), "Muelle_Cave", "goto", "goto6");
			ChangeCharacterAddressGroup(characterfromID("Monkey5"), "Muelle_Cave", "goto", "goto7");
			LAi_SetImmortal(characterFromID("Monkey"), true);
			LAi_SetImmortal(characterFromID("Monkey2"), true);
			LAi_SetImmortal(characterFromID("Monkey3"), true);
			LAi_SetImmortal(characterFromID("Monkey4"), true);
			LAi_SetImmortal(characterFromID("Monkey5"), true);
			LAi_SetActorType(characterFromID("Monkey"));
			Characters[GetCharacterIndex("Monkey")].dialog.CurrentNode = "farewell1";
			LAi_ActorDialog(characterFromID("Monkey"),PChar,"",5.0,5.0);
		break;

		case "monkey_farewell2":
			LAi_SetActorType(characterFromID("Monkey"));
			LAi_ActorFollow(characterFromID("Monkey"), characterFromID("Monkey2"), "", 30.0);
			Islands[FindIsland("IslaMuelle")].reload.l2.label = "Monkey Island";
		break;

		case "In_jail":
			locations[FindLocation("Tutorial_Deck")].type = "own_deck";
			PChar.quest.disable_rebirth = true;
			SetQuestHeader("Imprisoned");
			if (PChar.ServedNation == PERSONAL_NATION) AddQuestRecord("Imprisoned", 1);
			else AddQuestRecord("Imprisoned", 2);
			if (!CheckCharacterItem(PChar, "bladeX2")) GiveItem2Character(PChar, "bladeX2");
			EquipCharacterByItem(PChar, "bladeX2");
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_prison")], false);
			LAi_QuestDelay("Still_stuck", 0.0);
			if(GetDifficulty() <= DIFFICULTY_MARINER) logit(TranslateString("","HINT: If that warden comes close enough to the bars, you can mug him!"));
			PChar.quest.got_the_key.win_condition.l1 = "item";
			PChar.quest.got_the_key.win_condition.l1.character = Pchar.id;
			Pchar.quest.got_the_key.win_condition.l1.item = "key4";
			Pchar.quest.got_the_key.win_condition = "got_the_key";

			PChar.quest.warden_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.warden_dead.win_condition.l1.character = "Warden";
			PChar.quest.warden_dead.win_condition = "warden_dead";
		break;

		case "warden_dead":
			ChangeCharacterAddressGroup(CharacterfromID("Warden"), "Havana_prison", "reload", "reload12");
			if(CORPSEMODE < 2)					// If corpse looting is disabled, give the equipment to the player
			{
				GiveItem2Character(PChar, "key4");
				GiveItem2Character(PChar, "blade4");
				GiveItem2Character(PChar, "jerkin");

				PChar.quest.got_the_key.over = "yes";
				LAi_QuestDelay("warden_dead2", 0.5);
			}
		break;

		case "warden_dead2":
			LAi_SetActorType(PChar);
			PChar.dialog.CurrentNode = "get_wardens_stuff";
			LAi_ActorSelfDialog(PChar, "got_the_key");
		break;

		case "Still_stuck":
			logit(TranslateString("","Crew remaining:") + " " + PChar.quest.crew_left);
			LAi_SetActorType(characterFromID("Warden"));
			LAi_ActorGoToLocator(characterfromID("Warden"), "reload", "reload12", "feeding_time", 30.0);
		break;

		case "feeding_time":
			LAi_ActorTurnToCharacter(CharacterFromID("Warden"), (Pchar));
			if (!CheckAttribute(CharacterfromID("Warden"), "stuntime") && !LAi_IsDead(CharacterFromID("Warden")))
			{
				characters[GetCharacterIndex("Warden")].Dialog.Filename = "Warden_dialog.c";
				Characters[GetCharacterIndex("Warden")].dialog.CurrentNode = "feeding";
				LAi_ActorDialog(CharacterFromID("Warden"),PChar,"",5.0,5.0);
				LAi_QuestDelay("Warden_leaves", 10.0);
			}
		break;

		case "Warden_leaves":
			if (!CheckAttribute(CharacterfromID("Warden"), "stuntime") && !LAi_IsDead(CharacterFromID("Warden")))
			{
				LAi_SetActorType(CharacterFromID("Warden"));
				LAi_ActorGoToLocator(CharacterfromID("Warden"), "officers", "reload1_2", "next_day", 30.0);
			}
		break;

		case "next_day":
			LAi_Fade("", "");
			WaitDate("", 0, 0, 1, 0, 0);
			crew_lost = rand(5);
			logit(crew_lost + " " + TranslateString("","crew died of maltreatment"));
			crew_left = PChar.quest.crew_left;
			crew_left = crew_left - crew_lost;
			if (crew_left < 0) crew_left = 0;
			PChar.quest.crew_left = crew_left;
			if (pchar.CrewStatus.explength > 5)
			{
				PChar.quest.arresterid = "Havana Prison Commandant";
				LAi_QuestDelay("hanging_day", 1.0);
			}
			else LAi_QuestDelay("Still_stuck", 5.0);
		break;

		case "hanging_day": // Should work if you're in any prison location
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			arrester = characterFromID(PChar.quest.arresterid);
			arresteridx = GetCharacterIndex(PChar.quest.arresterid);
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], true);
			LAi_SetFightMode(PChar, false);
			if (PChar.location == "Havana_prison" && !LAi_IsDead(CharacterFromID("Warden")))
			{
				LAi_SetActorType(characterFromID("Warden"));
				LAi_ActorGoToLocator(characterfromID("Warden"), "officers", "reload1_2", "", 30.0);
			}
			LAi_SetActorType(arrester);
//			ChangeCharacterAddressGroup(arrester, "Havana_prison", "officers", "reload1_1");
			ChangeCharacterAddressGroup(arrester, PChar.location, "officers", "reload1_1");
			LAi_ActorGoToLocator(arrester, "reload", "reload12", "sentenced_to_death", 30.0);
		break;

		case "sentenced_to_death":
			arrester = characterFromID(PChar.quest.arresterid);
			arresteridx = GetCharacterIndex(PChar.quest.arresterid);
			LAi_ActorTurnToCharacter(arrester, (Pchar));
			characters[arresteridx].Dialog.Filename = "commandant_dialog.c";
			Characters[arresteridx].dialog.CurrentNode = "execution";
			LAi_ActorDialog(arrester,PChar,"hung at dawn",5.0,5.0);
		break;

		case "hung at dawn":
			PChar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "mutiny");
		break;

		case "got_the_key":
			LAi_SetPlayerType(PChar);
			LAi_SetFightMode(PChar, false);
			ChangeCharacterAddressGroup(PChar, "Havana_prison", "reload", "reload12");
			ChangeCharacterAddressGroup(CharacterfromID("Havana Prison Commandant"), "Havana_prison", "officers", "reload1_1");
			LAi_SetGuardianType(characterFromID("Havana Prison Commandant"));
			if (!LAi_IsDead(characterFromID("Warden")))
			{
				LAi_SetStunnedTypeNoGroup(characterFromID("Warden"));
				ChangeCharacterAddressGroup(characterFromID("Warden"), "Havana_prison", "goto", "goto24");
			}
			if(GetDifficulty() <= DIFFICULTY_MARINER) logit(TranslateString("","HINT: You aren't well armed and your officers aren't armed at all. Take all the help you can get!"));

			Pchar.quest.release_officer1.win_condition.l1 = "locator";
			Pchar.quest.release_officer1.win_condition.l1.location = "Havana_prison";
			Pchar.quest.release_officer1.win_condition.l1.locator_group = "reload";
			Pchar.quest.release_officer1.win_condition.l1.locator = "reload11";
			Pchar.quest.release_officer1.win_condition = "release_officer1";

			Pchar.quest.release_officer2.win_condition.l1 = "locator";
			Pchar.quest.release_officer2.win_condition.l1.location = "Havana_prison";
			Pchar.quest.release_officer2.win_condition.l1.locator_group = "reload";
			Pchar.quest.release_officer2.win_condition.l1.locator = "reload10";
			Pchar.quest.release_officer2.win_condition = "release_officer2";

			Pchar.quest.release_two_dogs.win_condition.l1 = "locator";
			Pchar.quest.release_two_dogs.win_condition.l1.location = "Havana_prison";
			Pchar.quest.release_two_dogs.win_condition.l1.locator_group = "reload";
			Pchar.quest.release_two_dogs.win_condition.l1.locator = "reload9";
			Pchar.quest.release_two_dogs.win_condition = "release_two_dogs";

			Pchar.quest.fight_commandant.win_condition.l1 = "locator";
			Pchar.quest.fight_commandant.win_condition.l1.location = "Havana_prison";
			Pchar.quest.fight_commandant.win_condition.l1.locator_group = "merchant";
			Pchar.quest.fight_commandant.win_condition.l1.locator = "reload13";
			Pchar.quest.fight_commandant.win_condition = "fight_commandant";

			Pchar.quest.got_the_big_key.win_condition.l1 = "item";
			PChar.quest.got_the_big_key.win_condition.l1.character = Pchar.id;
			Pchar.quest.got_the_big_key.win_condition.l1.item = "key3";
			Pchar.quest.got_the_big_key.win_condition = "got_the_big_key";

			Pchar.quest.got_the_security_letter.win_condition.l1 = "item";
			PChar.quest.got_the_security_letter.win_condition.l1.character = Pchar.id;
			Pchar.quest.got_the_security_letter.win_condition.l1.item = "SecurityLetter";
			Pchar.quest.got_the_security_letter.win_condition = "got_the_security_letter";
		break;

		case "release_officer1":
			LAi_SetActorType(officer1);
			characters[officer1idx].Dialog.Filename = "officer1_dialog.c";
			Characters[officer1idx].dialog.CurrentNode = "you_escaped";
			LAi_ActorDialogNow(officer1,PChar,"release_officer1_2",2.0);
		break;

		case "release_officer1_2":
			ChangeCharacterAddressGroup(officer1, "Havana_prison", "reload", "reload11");
			SetOfficersIndex(Pchar, 1, officer1idx);
			SetCharacterRemovable(officer1, false);
			GiveItem2Character(officer1, "bladeX4");
			officer1.equip.blade = "bladeX4";
			SetQuestHeader("Crew Rescue");
			AddQuestRecord("Crew Rescue", 1);
		break;

		case "release_officer2":
			ChangeCharacterAddressGroup(officer2, "Havana_prison", "reload", "reload10");
			SetOfficersIndex(Pchar, 2, officer2idx);
			SetCharacterRemovable(officer2, false);
			GiveItem2Character(officer2, "bladeX4");
			officer2.equip.blade = "bladeX4";
		break;

		case "release_two_dogs":
			LAi_SetActorType(officer1);
			LAi_SetActorType(officer2);

			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "guards_dead");

			LAi_SetActorType(characterFromID("Two Dogs"));
			characters[GetCharacterIndex("Two Dogs")].Dialog.Filename = "Two Dogs_dialog.c";
			Characters[GetCharacterIndex("Two Dogs")].dialog.CurrentNode = "meet_two_dogs";
			LAi_ActorDialogNow(characterFromID("Two Dogs"),PChar,"",2.0);
		break;

		case "release_two_dogs_2":
			ChangeCharacterAddressGroup(characterfromID("Two Dogs"), "Havana_prison", "reload", "reload9");
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Two Dogs"));
			SetCharacterRemovable(characterFromID("Two Dogs"), false);
			sld = characterfromID("Two Dogs");
			GiveItem2Character(sld, "Guestsknife");
			EquipCharacterByItem(sld, "Guestsknife");
			LAi_SetImmortal(characterFromID("Two Dogs"), true);
			AddQuestRecord("Crew Rescue", 2);
		break;

		case "guards_dead":
			LAi_SetOfficerType(officer1);
			LAi_SetOfficerType(officer2);
/*
			PChar.quest.escaped.win_condition.l1 = "location";
			PChar.quest.escaped.win_condition.l1.character = PChar.id;
			Pchar.quest.escaped.win_condition.l1.location = "Havana_town_05";
			Pchar.quest.escaped.win_condition = "escaped";
*/
		break;

		case "fight_commandant":
			LAi_SetActorType(characterFromID("Havana Prison Commandant"));
			LAi_ActorAttack(characterfromID("Havana Prison Commandant"), PChar, "");
			PChar.quest.commandant_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.commandant_dead.win_condition.l1.character = "Havana Prison Commandant";
			PChar.quest.commandant_dead.win_condition = "commandant_dead";
		break;

		case "commandant_dead":
			if(CORPSEMODE < 2)					// If corpse looting is disabled, give the equipment to the player
			{
				LAi_QuestDelay("take_stuff_from_commandant", 0.0);
			}
		break;

		case "take_stuff_from_commandant":
			GiveItem2Character(PChar, "key3");
			GiveItem2Character(PChar, "spyglass2");
			GiveItem2Character(PChar, "compass2");
			GiveItem2Character(PChar, "clock1");
			GiveItem2Character(PChar, "SecurityLetter");
		break;

		case "got_the_big_key":
			Locations[FindLocation("Havana_prison")].reload.l1.disable = 0;
			AddQuestRecord("Imprisoned", 3);

			PChar.quest.escaped.win_condition.l1 = "location";
			PChar.quest.escaped.win_condition.l1.character = PChar.id;
			PChar.quest.escaped.win_condition.l1.location = "Havana_town_05";
			PChar.quest.escaped.win_condition = "escaped";
		break;

		case "got_the_security_letter":
			SetQuestHeader("Payroll Ship");
			AddQuestRecord("Payroll Ship", 1);
			PChar.quest.payroll_ship = "active";
			PChar.quest.payroll_ship_timer1.win_condition.l1 = "Timer";
			PChar.quest.payroll_ship_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 0, 14);
			PChar.quest.payroll_ship_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
			PChar.quest.payroll_ship_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 0, 14);
			PChar.quest.payroll_ship_timer1.win_condition = "payroll_ship_sails";
		break;

		case "escaped":
			TakeItemFromCharacter(PChar, "key4");	// Don't need cell key any more
			PChar.quest.disable_rebirth = false;
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = 1;
			PChar.quest.warden_dead.over = "yes";
			AddQuestRecord("Imprisoned", 4);
			CloseQuestHeader("Imprisoned");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(PChar, "", 100);
				AddPartyExpChar(pchar, "Sneak", 100);
			}
			else {AddPartyExp(pchar, 1500);}
			LAi_SetImmortal(characterFromID("Two Dogs"), false);

			if (PChar.quest.alignment == "good" && !LAi_IsDead(characterFromID("Warden")) && isofficer(officer2))
			{
				LAi_SetActorType(officer2);
				characters[officer2idx].Dialog.Filename = "officer2_dialog.c";
				Characters[officer2idx].dialog.CurrentNode = "Nice guy";
				LAi_ActorDialog(officer2,PChar,"escaped2",0.0,0.0);
				ChangeCharacterReputation(PChar, 5);
			}
			if (PChar.quest.alignment == "evil" && LAi_IsDead(characterFromID("Warden")) && isofficer(officer2))
			{
				LAi_SetActorType(officer2);
				characters[officer2idx].Dialog.Filename = "officer2_dialog.c";
				Characters[officer2idx].dialog.CurrentNode = "Nasty guy";
				LAi_ActorDialog(officer2,PChar,"escaped2",0.0,0.0);
				ChangeCharacterReputation(PChar, -2);
			}
			ChangeCharacterAddress(CharacterFromID("Havana Prison Commandant"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Spanish_guard1"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Spanish_guard2"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Spanish_guard3"), "None", "");
			Characters[GetCharacterIndex("Spanish_guard1")].issoldier = 1;
			Characters[GetCharacterIndex("Spanish_guard2")].issoldier = 1;
			Characters[GetCharacterIndex("Spanish_guard3")].issoldier = 1;
			if (!LAi_IsDead(CharacterFromID("Warden")))
			{
				LAi_SetCitizenTypeNoGroup(CharacterFromID("Warden"));
				ChangeCharacterAddressGroup(CharacterFromID("Warden"), "Havana_prison", "goto", "goto23");
			}

			Locations[FindLocation("Havana_Outskirts")].vcskip = true; // Prevent random bandits from making Two Dogs look silly when he ignores them
			Locations[FindLocation("Cuba_Jungle_01")].vcskip = true;
			Locations[FindLocation("Cuba_Jungle_02")].vcskip = true;
			Locations[FindLocation("Cuba_Jungle_03")].vcskip = true;

			PChar.quest.left_Havana.win_condition.l1 = "location";
			PChar.quest.left_Havana.win_condition.l1.location = "Havana_Outskirts";
			PChar.quest.left_Havana.win_condition = "left_Havana";

			PChar.quest.port_bad.win_condition.l1 = "location";
			PChar.quest.port_bad.win_condition.l1.location = "Cuba_port";
			PChar.quest.port_bad.win_condition = "port_bad";

			ChangeCharacterAddressGroup(characterfromID("Spanish_Captain1"), "Cuba_port", "goto", "goto_2");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard1"), "Cuba_port", "officers", "Door_1_1");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard2"), "Cuba_port", "officers", "Door_1_2");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard3"), "Cuba_port", "officers", "Door_1_3");

			PChar.quest.pursuers = "counting";
			LAi_QuestDelay("Pursuers", 0.0);
		break;

		case "escaped2":
			if (isofficer(officer2)) LAi_SetOfficerType(officer2);
		break;

		case "Pursuers":
			Pchar.quest.pursuit_new_location.win_condition.l1 = "ExitFromLocation";
			PChar.quest.pursuit_new_location.win_condition.l1.location = PChar.location;
			Pchar.quest.pursuit_new_location.win_condition = "pursuit_new_location";
			LAi_QuestDelay("Pursuers2", 5.0);
			
		break;

		case "pursuit_new_location":
			switch(PChar.quest.pursuers)
			{
				case "counting":
					PChar.quest.pursuers = "cancel";
				break;

				case "active":
					PChar.quest.pursuers = "idle";
				break;

				case "idle":
					PChar.quest.pursuers = "counting";
				break;

				case "cancel":
					PChar.quest.pursuers = "idle";
				break;
			}
			LAi_QuestDelay("Pursuers", 0.0);
		break;

		case "Pursuers2":
			if (PChar.quest.pursuers != "cancel")
			{
				Rapid_Raid("Soldiers", 5, SPAIN, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "Run! They're after you!", "Search party", OFFIC_TYPE_GUARD, 3, true, "blade_mKnife", "pistolmket");
				PChar.quest.pursuers = "active";
				LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			}
		break;

		case "left_Havana":
			PChar.quest.pursuers = "cancel";
			PChar.quest.pursuit_new_location.over = "yes";
			if (isofficer(characterFromID("Two Dogs")))
			{
				LAi_SetActorType(characterFromID("Two Dogs"));
				characters[GetCharacterIndex("Two Dogs")].name = TranslateString("","Two Dogs");
				characters[GetCharacterIndex("Two Dogs")].lastname = TranslateString("","Fighting");
				characters[GetCharacterIndex("Two Dogs")].Dialog.Filename = "Two Dogs_dialog.c";
				Characters[GetCharacterIndex("Two Dogs")].dialog.CurrentNode = "introduction";
				LAi_ActorDialogNow(characterFromID("Two Dogs"),PChar,"",2.0); // Dialog exits to "new_deal_with_Two_Dogs" or "get_lost_Two_Dogs"
			}
			PChar.quest.slave_camp.win_condition.l1 = "location";
			PChar.quest.slave_camp.win_condition.l1.character = PChar.id;
			Pchar.quest.slave_camp.win_condition.l1.location = "Smugglers_Fort";
			Pchar.quest.slave_camp.win_condition = "slave_camp";
		break;

		case "port_bad":
			Locations[FindLocation("Cuba_port")].reload.l1.disable = 1;
			DisableFastTravel(true);
			PChar.quest.pursuers = "cancel";
			PChar.quest.pursuit_new_location.over = "yes";

			LAi_SetActorType(characterFromID("Spanish_Captain1"));
			characters[GetCharacterIndex("Spanish_Captain1")].Dialog.Filename = "Spanish_Captain1_dialog.c";
			Characters[GetCharacterIndex("Spanish_Captain1")].Dialog.CurrentNode = "caught_in_port";
			LAi_ActorDialog(characterfromID("Spanish_Captain1"), pchar, "", 5.0, 5.0); // Dialog exits to "port_fight" or "back_to_prison"
		break;

		case "port_fight":
			LAi_SetImmortal(characterFromID("Two Dogs"), false);
			LAi_group_MoveCharacter(characterfromID("Spanish_Captain1"), "SPAIN_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("Spanish_guard1"), "SPAIN_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("Spanish_guard2"), "SPAIN_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("Spanish_guard3"), "SPAIN_SOLDIERS");
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "port_fight_won");
		break;

		case "port_fight_won":
			Locations[FindLocation("Cuba_port")].reload.l1.disable = 0;
			DisableFastTravel(false);
		break;

		case "back_to_prison":
			PChar.quest.arresterid = "Spanish_Captain1";
			ChangeCharacterAddressGroup(characterfromID("Spanish_Captain1"), "Havana_prison", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard1"), "Havana_prison", "goto", "goto14");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard2"), "Havana_prison", "goto", "goto16");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard3"), "Havana_prison", "goto", "goto17");
			LAi_SetGuardianType(characterfromID("Spanish_guard1"));
			LAi_SetGuardianType(characterfromID("Spanish_guard2"));
			LAi_SetGuardianType(characterfromID("Spanish_guard3"));

			TakeItemFromCharacter(PChar, "key3");
			TakeItemFromCharacter(PChar, "key4");
			RemoveCharacterEquip(PChar, "pistolmket");
			RemoveCharacterEquip(PChar, "pistolmketB");
			TakeItemFromCharacter(PChar, "pistolmket");
			TakeItemFromCharacter(PChar, "pistolmketB");
			if (!CheckCharacterItem(PChar, "pistolrock")) GiveItem2Character(PChar, "pistolrock");
			EquipCharacterByItem(PChar, "bladeX4");
			EquipCharacterByItem(PChar, "pistolrock");
			PChar.quest.got_the_key.over = "no";
			PChar.quest.got_the_big_key.over = "no";
			if (!LAi_IsDead(characterFromID("Warden")))
			{
				LAi_SetCitizenTypeNoGroup(characterFromID("Warden"));
				ChangeCharacterAddressGroup(characterFromID("Warden"), "Havana_prison", "goto", "goto23");
			}
			DoQuestReloadToLocation("Havana_prison", "goto", "goto24", "hanging_day");
		break;

		case "get_lost_Two_Dogs":
			SetCharacterRemovable(characterFromID("Two Dogs"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Two Dogs"));
			RemovePassenger(pchar, characterFromID("Two Dogs"));
			LAi_SetCitizenTypeNoGroup(characterFromID("Two Dogs"));
			ChangeCharacterAddress(characterFromID("Two Dogs"), "None", "");
		break;

		case "new_deal_with_Two_Dogs":
			SetQuestHeader("Take Two Dogs Home");
			AddQuestRecord("Take Two Dogs Home", 1);
			AddQuestRecord("Crew Rescue", 3);
			pchar.quest.take_two_dogs_home = "yes";

			PChar.quest.two_dogs_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.two_dogs_dead.win_condition.l1.character = "Two Dogs";
			PChar.quest.two_dogs_dead.win_condition = "two_dogs_dead";

			pchar.quest.Cuba_Jungle_01.win_condition.l1 = "location";
			PChar.quest.Cuba_Jungle_01.win_condition.l1.character = PChar.id;
			pchar.quest.Cuba_Jungle_01.win_condition.l1.location = "Cuba_Jungle_01";
			pchar.quest.Cuba_Jungle_01.win_condition = "Cuba_Jungle_01";

			pchar.quest.two_dogs_is_home.win_condition.l1 = "location";
			PChar.quest.two_dogs_is_home.win_condition.l1.character = PChar.id;
			pchar.quest.two_dogs_is_home.win_condition.l1.location = "Quest_Indian_house";
			pchar.quest.two_dogs_is_home.win_condition = "two_dogs_is_home";

			LAi_ActorGoToLocator(characterFromID("Two Dogs"), "reload", "reload1_back", "",80.0);
		break;

		case "two_dogs_dead":
			AddQuestRecord("Take Two Dogs Home", 2);
			CloseQuestHeader("Take Two Dogs Home");
			DeleteQuestAttribute("take_two_dogs_home");
			PChar.quest.two_dogs_is_home.over = "yes";
		break;

		case "Cuba_Jungle_01":
			DeleteQuestAttribute("pursuers");
			DeleteQuestAttribute("pursuit_new_location");

			Locations[FindLocation("Cuba_Jungle_01")].reload.l5.disable = 1;
			if (isofficer(characterFromID("Two Dogs")))
			{
				pchar.quest.Cuba_Jungle_02.win_condition.l1 = "location";
				PChar.quest.Cuba_Jungle_02.win_condition.l1.character = PChar.id;
				pchar.quest.Cuba_Jungle_02.win_condition.l1.location = "Cuba_Jungle_02";
				pchar.quest.Cuba_Jungle_02.win_condition = "Cuba_Jungle_02";
				LAi_SetActorType(characterFromID("Two Dogs"));
				LAi_ActorGoToLocator(characterFromID("Two Dogs"), "reload", "reload1_back", "",60.0);
			}
		break;

		case "Cuba_Jungle_02":
			Locations[FindLocation("Cuba_Jungle_01")].reload.l5.disable = 0;
			Locations[FindLocation("Cuba_Jungle_02")].reload.l5.disable = 1;
			if (isofficer(characterFromID("Two Dogs")))
			{
				pchar.quest.Cuba_Jungle_03.win_condition.l1 = "location";
				PChar.quest.Cuba_Jungle_03.win_condition.l1.character = PChar.id;
				pchar.quest.Cuba_Jungle_03.win_condition.l1.location = "Cuba_Jungle_03";
				pchar.quest.Cuba_Jungle_03.win_condition = "Cuba_Jungle_03";
				LAi_SetActorType(characterFromID("Two Dogs"));
				LAi_ActorGoToLocator(characterFromID("Two Dogs"), "reload", "reload2_back", "",65.0);
			}
		break;

		case "Cuba_Jungle_03":
			Locations[FindLocation("Smugglers_Fort")].locators_radius.goto.goto19 = 5.0;
			Locations[FindLocation("Cuba_Jungle_02")].reload.l5.disable = 0;
			Locations[FindLocation("Cuba_Jungle_03")].reload.l2.disable = 1;
			if (isofficer(characterFromID("Two Dogs")))
			{
				LAi_SetActorType(characterFromID("Two Dogs"));
				LAi_ActorGoToLocator(characterFromID("Two Dogs"), "reload", "reload1_back", "",65.0);
			}
		break;

		case "slave_camp":
			PChar.quest.disable_rebirth = true;
			Locations[FindLocation("Smugglers_Fort")].reload.l5.disable = 1;
			Locations[FindLocation("Cuba_Jungle_03")].reload.l2.disable = 0;
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Smugglers_Fort")], true);
			if (isofficer(characterFromID("Two Dogs")))
			{
				LAi_SetOfficerType(characterFromID("Two Dogs"));
				characters[GetCharacterindex("Two Dogs")].nodisarm = 1;
			}
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto7");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto15");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto23");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto33");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier4";
			Pchar.quest.meet_slave_commandant.win_condition.l1 = "locator";
			Pchar.quest.meet_slave_commandant.win_condition.l1.location = "Smugglers_Fort";
			Pchar.quest.meet_slave_commandant.win_condition.l1.locator_group = "goto";
			Pchar.quest.meet_slave_commandant.win_condition.l1.locator = "goto19";
			Pchar.quest.meet_slave_commandant.win_condition = "meet_slave_commandant";
		break;

		case "meet_slave_commandant":
			LAi_SetActorType(characterFromID("Slave Camp Commandant"));
			characters[GetCharacterIndex("Slave Camp Commandant")].Dialog.Filename = "Slave_Commandant_dialog.c";
			Characters[GetCharacterIndex("Slave Camp Commandant")].Dialog.CurrentNode = "Intruder";
			LAi_ActorDialog(characterfromID("Slave Camp Commandant"), pchar, "slave_camp_battle", 5.0, 5.0);
			LAi_group_MoveCharacter(characterfromID("Slave Camp Commandant"), "SPAIN_SOLDIERS");
		break;

		case "slave_camp_battle":
			LAi_LocationFightDisable(&Locations[FindLocation("Smugglers_Fort")], false);
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "slave_camp_fight_won");
			LAi_QuestDelay("crew_join_in", 2.0);
		break;

		case "crew_join_in":
			if (!LAi_IsDead(characterFromID("Ralph Partridge")) && !LAi_IsDead(characterFromID("soldier1")))
			{
				LAi_SetActorType(characterFromID("Ralph Partridge"));
				LAi_ActorAttack(characterFromID("Ralph Partridge"), characterFromID("soldier1"), "");
			}
			if (!LAi_IsDead(characterFromID("Coper Blumberger")) && !LAi_IsDead(characterFromID("soldier2")))
			{
				LAi_SetActorType(characterFromID("Coper Blumberger"));
				LAi_ActorAttack(characterFromID("Coper Blumberger"),characterFromID("soldier2"), "");
			}
			if (!LAi_IsDead(characterFromID("Amtónio Guajira")) && !LAi_IsDead(characterFromID("soldier3")))
			{
				LAi_SetActorType(characterFromID("Amtónio Guajira"));
				LAi_ActorAttack(characterFromID("Amtónio Guajira"),characterFromID("soldier3"), "");
			}
			if (!LAi_IsDead(characterFromID("Ayol Bacha")) && !LAi_IsDead(characterFromID("soldier4")))
			{
				LAi_SetActorType(characterFromID("Ayol Bacha"));
				LAi_ActorAttack(characterFromID("Ayol Bacha"),characterFromID("soldier4"), "");
			}
		break; 

		case "slave_camp_fight_won":
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Smugglers_Fort")], true);
			PlaySound("VOICE\ENGLISH\Dut_m_a_030.wav");
			survivors = 0;
			if (!LAi_IsDead(characterFromID("Ayol Bacha")))
			{
				survivors = survivors + 1;
				crewref = characterFromID("Ayol Bacha");
				crewidx = GetCharacterIndex("Ayol Bacha");
			}
			if (!LAi_IsDead(characterFromID("Amtónio Guajira")))
			{
				survivors = survivors + 1;
				crewref = characterFromID("Amtónio Guajira");
				crewidx = GetCharacterIndex("Amtónio Guajira");
			}
			if (!LAi_IsDead(characterFromID("Coper Blumberger")))
			{
				survivors = survivors + 1;
				crewref = characterFromID("Coper Blumberger");
				crewidx = GetCharacterIndex("Coper Blumberger");
			}
			if (!LAi_IsDead(characterFromID("Ralph Partridge")))
			{
				survivors = survivors + 1;
				crewref = characterFromID("Ralph Partridge");
				crewidx = GetCharacterIndex("Ralph Partridge");
			}

			crew_lost = 4 - survivors;
			crew_left = PChar.quest.crew_left;
			crew_left = crew_left - crew_lost;
			if (crew_left < 0) crew_left = 0; // Shouldn't be possible! Take no chances anyway.
			PChar.quest.crew_left = crew_left;
			logit(crew_lost + " " + TranslateString("","crew died in the battle"));
			logit(TranslateString("","Crew remaining:") + " " + PChar.quest.crew_left);

			if (survivors > 0)
			{
				LAi_SetActorType(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "Rescued";
				LAi_ActorDialog(crewref, pchar, "move_out", 5.0, 5.0);
			}
			else LAi_QuestDelay("move_out", 0.0);
		break;

		case "move_out":
			Locations[FindLocation("Smugglers_Fort")].reload.l5.disable = 0;
			PChar.quest.port_bad.over = "yes";
			LAi_LocationFightDisable(&Locations[FindLocation("Smugglers_Fort")], false);
			ChangeCharacterAddress(characterFromID("Spanish_Captain1"), "None", "");
			ChangeCharacterAddress(characterFromID("Spanish_guard1"), "None", "");
			ChangeCharacterAddress(characterFromID("Spanish_guard2"), "None", "");
			ChangeCharacterAddress(characterFromID("Spanish_guard3"), "None", "");
			logit(TranslateString("","I'm taking one of the soldier's uniforms. A disguise might be useful later."));
			if (PChar.sex == "man") GiveModel2Player("Ardent_S", false);
			else GiveModel2Player("Ardent_SF", false);
			if (!LAi_IsDead(characterFromID("Ayol Bacha")))
			{
				LAi_SetActorType(characterFromID("Ayol Bacha"));
				LAi_ActorFollowEverywhere(CharacterFromID("Ayol Bacha"), "", 1.0);
				LAi_group_MoveCharacter(characterFromID("Ayol Bacha"), LAI_GROUP_PLAYER);
			}
			if (!LAi_IsDead(characterFromID("Amtónio Guajira")))
			{
				LAi_SetActorType(characterFromID("Amtónio Guajira"));
				LAi_ActorFollowEverywhere(CharacterFromID("Amtónio Guajira"), "", 1.0);
				LAi_group_MoveCharacter(characterFromID("Amtónio Guajira"), LAI_GROUP_PLAYER);
			}
			if (!LAi_IsDead(characterFromID("Coper Blumberger")))
			{
				LAi_SetActorType(characterFromID("Coper Blumberger"));
				LAi_ActorFollowEverywhere(CharacterFromID("Coper Blumberger"), "", 1.0);
				LAi_group_MoveCharacter(characterFromID("Coper Blumberger"), LAI_GROUP_PLAYER);
			}
			if (!LAi_IsDead(characterFromID("Ralph Partridge")))
			{
				LAi_SetActorType(characterFromID("Ralph Partridge"));
				LAi_ActorFollowEverywhere(CharacterFromID("Ralph Partridge"), "", 1.0);
				LAi_group_MoveCharacter(characterFromID("Ralph Partridge"), LAI_GROUP_PLAYER);
			}

			DeleteAttribute(&Locations[FindLocation("Havana_Outskirts")],"vcskip"); // Bandits can attack you now
			DeleteAttribute(&Locations[FindLocation("Cuba_Jungle_01")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cuba_Jungle_02")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cuba_Jungle_03")],"vcskip");

			pchar.quest.back_to_jungle.win_condition.l1 = "location";
			PChar.quest.back_to_jungle.win_condition.l1.character = PChar.id;
			pchar.quest.back_to_jungle.win_condition.l1.location = "Cuba_Jungle_03";
			pchar.quest.back_to_jungle.win_condition = "back_to_jungle";

			PChar.quest.back_in_town.win_condition.l1 = "location";
			PChar.quest.back_in_town.win_condition.l1.character = PChar.id;
			Pchar.quest.back_in_town.win_condition.l1.location = "Havana_town_05";
			Pchar.quest.back_in_town.win_condition = "back_in_town";
		break;

		case "back_to_jungle":
			PChar.quest.disable_rebirth = false;
			if (LAi_IsDead(characterFromID("Ralph Partridge"))) ChangeCharacterAddress(characterFromID("Ralph Partridge"), "None", "");
			if (LAi_IsDead(characterFromID("Coper Blumberger"))) ChangeCharacterAddress(characterFromID("Coper Blumberger"), "None", "");
			if (LAi_IsDead(characterFromID("Amtónio Guajira"))) ChangeCharacterAddress(characterFromID("Amtónio Guajira"), "None", "");
			if (LAi_IsDead(characterFromID("Ayol Bacha"))) ChangeCharacterAddress(characterFromID("Ayol Bacha"), "None", "");
			ChangeCharacterAddress(characterFromID("Slave Camp Commandant"), "None", "");
			if (isofficer(characterFromID("Two Dogs")))
			{
				LAi_SetActorType(characterFromID("Two Dogs"));
				characters[GetCharacterIndex("Two Dogs")].Dialog.Filename = "Two Dogs_dialog.c";
				Characters[GetCharacterIndex("Two Dogs")].dialog.CurrentNode = "job_done";
				LAi_ActorDialogNow(characterFromID("Two Dogs"),PChar,"",2.0); // Dialog exits to "take_Two_Dogs_home" or "two_dogs_betrayed"
			}
		break;

		case "take_Two_Dogs_home":
			AddQuestRecord("Take Two Dogs Home", 4);
			LAi_SetOfficerType(characterFromID("Two Dogs"));
			characters[GetCharacterindex("Two Dogs")].nodisarm = 0;
		break;

		case "two_dogs_betrayed":
			PChar.quest.two_dogs_is_home.over = "yes";
			AddQuestRecord("Take Two Dogs Home", 3);
			CloseQuestHeader("Take Two Dogs Home");
			SetCharacterRemovable(characterFromID("Two Dogs"), true);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Two Dogs"));
			RemovePassenger(pchar, characterFromID("Two Dogs"));
			LAi_SetActorType(characterFromID("Two Dogs"));
			LAi_ActorAttack(characterfromID("Two Dogs"), PChar, "");
		break;

		case "back_in_town":
			Locations[FindLocation("Havana_town_05")].reload.l3.disable = 1;
			AddQuestRecord("Crew Rescue", 4);
			CloseQuestHeader("Crew Rescue");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 1000);
				AddPartyExpChar(PChar, "", 100);
				AddPartyExpChar(PChar, "Fencing", 100);
			}
			else {AddPartyExp(PChar, 1500);}
			LAi_SetFightMode(PChar, false);

			speaker = "";
			if (!LAi_IsDead(characterFromID("Ayol Bacha"))) speaker= "Ayol Bacha";
			if (!LAi_IsDead(characterFromID("Amtónio Guajira"))) speaker= "Amtónio Guajira";
			if (!LAi_IsDead(characterFromID("Coper Blumberger"))) speaker= "Coper Blumberger";
			if (!LAi_IsDead(characterFromID("Ralph Partridge"))) speaker= "Ralph Partridge";
			if (!LAi_IsDead(officer2)) speaker= characters[officer2idx].id;
			if (!LAi_IsDead(officer1)) speaker= characters[officer1idx].id;
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				LAi_SetActorType(crewref);
				StoreDialog(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "back_in_havana";
				LAi_ActorDialog(crewref, pchar, "back_in_town2", 5.0, 5.0);
			}
			else LAi_QuestDelay("back_in_town2", 1.0);
			if (checkquestattribute("payroll_ship", "active"))
			{
				if (PChar.sex == "man") AddQuestRecord("Payroll Ship", 2);
				else AddQuestRecord("Payroll Ship", 3);
			}
		break;

		case "back_in_town2":
			Locations[FindLocation("Havana_town_05")].reload.l3.disable = 0;
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = 0;
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				RestoreDialog(crewref);
			}
			if (!LAi_IsDead(officer1))
			{
				SetCharacterRemovable(officer1, true);
				LAi_SetActorType(officer1);
				LAi_ActorGoToLocator(officer1, "officers", "reload_4_1_1", "officers_leave",65.0);
				Characters[officer1idx].dialog.Filename = "Enc_Officer_dialog.c";
				Characters[officer1idx].dialog.CurrentNode = "hired";
			}
			if (!LAi_IsDead(officer2))
			{
				SetCharacterRemovable(officer2, true);
				LAi_SetActorType(officer2);
				LAi_ActorGoToLocator(officer2, "reload", "reload_4_1_back", "",65.0);
				Characters[officer2idx].dialog.Filename = "Enc_Officer_dialog.c";
				Characters[officer2idx].dialog.CurrentNode = "hired";
			}
			if (isofficer(characterFromID("Two Dogs")))
			{
				SetCharacterRemovable(characterFromID("Two Dogs"), true);
				LAi_SetActorType(characterFromID("Two Dogs"));
				LAi_ActorGoToLocator(characterFromID("Two Dogs"), "reload", "reload_4_1_back", "",65.0);
			}
			if (!LAi_IsDead(characterFromID("Ralph Partridge")))
			{
				LAi_SetCitizenTypeNoGroup(characterFromID("Ralph Partridge"));
				LAi_SetActorType(characterFromID("Ralph Partridge"));
				LAi_ActorGoToLocator(characterFromID("Ralph Partridge"), "reload", "reload_4_1_back", "",65.0);
			}
			if (!LAi_IsDead(characterFromID("Coper Blumberger")))
			{
				LAi_SetActorType(characterFromID("Coper Blumberger"));
				LAi_ActorGoToLocator(characterFromID("Coper Blumberger"), "reload", "reload_4_1_back", "",65.0);
			}
			if (!LAi_IsDead(characterFromID("Amtónio Guajira")))
			{
				LAi_SetActorType(characterFromID("Amtónio Guajira"));
				LAi_ActorGoToLocator(characterFromID("Amtónio Guajira"), "reload", "reload_4_1_back", "",65.0);
			}
			if (!LAi_IsDead(characterFromID("Ayol Bacha")))
			{
				LAi_SetActorType(characterFromID("Ayol Bacha"));
				LAi_ActorGoToLocator(characterFromID("Ayol Bacha"), "reload", "reload_4_1_back", "",65.0);
			}
			Pchar.quest.i_leave.win_condition.l1 = "ExitFromLocation";
			PChar.quest.i_leave.win_condition.l1.location = PChar.location;
			Pchar.quest.i_leave.win_condition = "i_leave";

			Pchar.quest.tavern_for_payroll.win_condition.l1 = "location";
			Pchar.quest.tavern_for_payroll.win_condition.l1.location = "Havana_tavern";
			Pchar.quest.tavern_for_payroll.win_condition = "tavern_for_payroll";

			PChar.quest.port_good.win_condition.l1 = "location";
			PChar.quest.port_good.win_condition.l1.location = "Cuba_port";
			PChar.quest.port_good.win_condition = "port_good";

			Pchar.quest.port_gate.win_condition.l1 = "locator";
			Pchar.quest.port_gate.win_condition.l1.location = "Havana_town_01";
			Pchar.quest.port_gate.win_condition.l1.locator_group = "reload";
			Pchar.quest.port_gate.win_condition.l1.locator = "reload_from_port";
			Pchar.quest.port_gate.win_condition = "port_gate";
		break;

		case "i_leave":
			LAi_QuestDelay("officers_leave", 0.0);
		break;

		case "officers_leave":
			if(GetOfficersIndex(Pchar, 1) != -1)
			{
				ChangeCharacterAddressGroup(characters[GetOfficersIndex(Pchar, 1)], "Cuba_port", "officers", "reload_2_city_1");
			}
			if(GetOfficersIndex(Pchar, 2) != -1)
			{
				ChangeCharacterAddressGroup(characters[GetOfficersIndex(Pchar, 2)], "Cuba_port", "officers", "reload_2_city_2");
			}
			if(GetOfficersIndex(Pchar, 3) != -1)
			{
				ChangeCharacterAddressGroup(characters[GetOfficersIndex(Pchar, 3)], "Cuba_port", "officers", "reload_2_city_3");
			}
			ChangeCharacterAddress(characterFromID("Ralph Partridge"), "None", "");
			ChangeCharacterAddress(characterFromID("Coper Blumberger"), "None", "");
			ChangeCharacterAddress(characterFromID("Amtónio Guajira"), "None", "");
			ChangeCharacterAddress(characterFromID("Ayol Bacha"), "None", "");
			StoreOfficers(PChar.id);
		break;

		case "tavern_for_payroll":
			PChar.quest.payroll_ship_known = "no";
			characters[GetCharacterIndex("Spanish_Captain2")].Dialog.Filename = "Spanish_Captain2_dialog.c";
			if (PChar.sex == "man") Characters[GetCharacterIndex("Spanish_Captain2")].dialog.CurrentNode = "soldier";
			if (PChar.sex == "woman") Characters[GetCharacterIndex("Spanish_Captain2")].dialog.CurrentNode = "senorita";
		break;

		case "tavern_for_payroll2":
			if (PChar.quest.payroll_ship_known == "no") LAi_QuestDelay("tavern_for_payroll", 0.0);
			else
			{
				if (!checkquestattribute("payroll_ship", "active"))
				{
					SetQuestHeader("Payroll Ship");
					PChar.quest.payroll_ship_timer1.win_condition.l1 = "Timer";
					PChar.quest.payroll_ship_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 0, 14);
					PChar.quest.payroll_ship_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
					PChar.quest.payroll_ship_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 0, 14);
					PChar.quest.payroll_ship_timer1.win_condition = "payroll_ship_sails";
				}
				AddQuestRecord("Payroll Ship", 4);
			}
		break;

		case "port_gate":
			RestoreOfficers(PChar.id);
			GiveShip2Character(PChar,"TartaneWar","Esme",CANNON_TYPE_NONECANNON,SPAIN,false,false);
//			makearef(arShip, PChar.ship.stats);
//			arship.CannonsQuantity = 0;
//			GiveShip2Character(PChar,"TartaneWar","Esme",CANNON_TYPE_LONG_LBS4,SPAIN,false,true);
			DeleteAttribute(PChar, "isnotcaptain");
			AddCharacterGoods(PChar, GOOD_RUM, 2);
			AddCharacterGoods(PChar, GOOD_WHEAT, 3);
			AddCharacterGoods(PChar, GOOD_SAILCLOTH, 3);
			AddCharacterGoods(PChar, GOOD_PLANKS, 6);
			SetCrewQuantity(PChar, sti(PChar.quest.crew_left));
			setCharacterShipLocation(Pchar, "Cuba_port");

// Disable sea access to Playa de Sierra Maestra so you can only land at Santiago port or Bahia de Moa which leads to Santiago port.
			Island_SetReloadEnableLocal("Cuba", "reload_8", false);
			Islands[FindIsland("Cuba")].reload.l7.goto_enable = false;
		break;

		case "port_good":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				LAi_SetActorType(crewref);
				StoreDialog(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "got_a_ship";
				LAi_ActorDialog(crewref, pchar, "got_a_ship", 5.0, 5.0);
			}
			else LAi_QuestDelay("got_a_ship", 0.0);
		break;

		case "got_a_ship":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				RestoreDialog(crewref);
				LAi_SetOfficerType(CharacterFromId(characters[crewidx].id));
			}
			HoistFlag(SPAIN);
			PChar.quest.arrival_Santiago_port.win_condition.l1 = "location";
			PChar.quest.arrival_Santiago_port.win_condition.l1.location = "Santiago_port";
			PChar.quest.arrival_Santiago_port.win_condition = "arrival_Santiago_port";
		break;

		case "arrival_Santiago_port":
			characters[GetCharacterIndex("Pedro Fructoso")].Dialog.Filename = "Pedro Fructoso_dialog.c";
			Characters[GetCharacterIndex("Pedro Fructoso")].dialog.currentnode = "free_drink";
			GiveItem2Character(characterFromID("Jose Zugarro"),"mapCuba");
			iForceDetectionFalseFlag = -1; // False flags never detected so storekeeper Zugarro never refuses to serve you
			Pchar.dialog.CurrentNode = "nothing_in_Santiago";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "nothing_in_Santiago");

			PChar.quest.in_store.win_condition.l1 = "location";
			PChar.quest.in_store.win_condition.l1.location = "Santiago_store";
			PChar.quest.in_store.win_condition = "in_store";
		break;

		case "initialise_kidnap":
			Locations[FindLocation("Santiago_town_01")].locators_radius.goto.goto10 = 15.0;
			Pchar.quest.seen_window.win_condition.l1 = "locator";
			Pchar.quest.seen_window.win_condition.l1.location = "Santiago_town_01";
			Pchar.quest.seen_window.win_condition.l1.locator_group = "goto";
			Pchar.quest.seen_window.win_condition.l1.locator = "goto10";
			Pchar.quest.seen_window.win_condition = "seen_window";

			Characters[villainidx].dialog.currentnode = "first_letter";
		break;

		case "seen_window":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "goto", "goto22");
			LAi_QuestDelay("seen_window2", 1.0);
		break;

		case "seen_window2":
			LAi_SetPlayerType(PChar);
			AddQuestRecord("Kidnap", 2);
		break;

		case "congratulated_governor":
			Preprocessor_AddQuestData("name", GetMyName(romance));
			if (PChar.sex == "man")
			{
				AddQuestRecord("Kidnap", 3);
			}
			else
			{
				AddQuestRecord("Kidnap", 4);
			}
			Preprocessor_Remove("name");
			PChar.quest.ardent_kidnap = "Met_governor";

			Pchar.quest.kidnap_breakin.win_condition.l1 = "Time";				// To break into the residence requires:
			Pchar.quest.kidnap_breakin.win_condition.l1.time = DAY_TIME_NIGHT;		// night-time,
			PChar.quest.kidnap_breakin.win_condition.l2 = "NPC_Death";			// both guards dead,
			PChar.quest.kidnap_breakin.win_condition.l2.character = "Santiago_soldier_05";
			PChar.quest.kidnap_breakin.win_condition.l3 = "NPC_Death";
			PChar.quest.kidnap_breakin.win_condition.l3.character = "Santiago_soldier_06";
			Pchar.quest.kidnap_breakin.win_condition.l4 = "item";				// you have a lockpick,
			PChar.quest.kidnap_breakin.win_condition.l4.character = Pchar.id;
			Pchar.quest.kidnap_breakin.win_condition.l4.item = "lockpick";
			Pchar.quest.kidnap_breakin.win_condition.l5 = "locator";			// and you're standing at the door.
			Pchar.quest.kidnap_breakin.win_condition.l5.location = "Santiago_town_01";
			Pchar.quest.kidnap_breakin.win_condition.l5.locator_group = "reload";
			Pchar.quest.kidnap_breakin.win_condition.l5.locator = "reload4";
			PChar.quest.kidnap_breakin.win_condition = "kidnap_breakin";
		break;

		case "in_store":
			PChar.quest.out_of_store_no_map.win_condition.l1 = "location";
			PChar.quest.out_of_store_no_map.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.out_of_store_no_map.win_condition = "out_of_store_no_map";
		break;

		case "out_of_store_no_map":
			if (!CheckCharacterItem(PChar, "mapCuba"))
			{
				Pchar.dialog.CurrentNode = "rob_store";
				LAi_SetActorType(PChar);
				LAi_ActorSelfDialog(PChar, "rob_store");
			}
		break;

		case "rob_store":
			LAi_SetPlayerType(PChar);
			Pchar.quest.rob_store2.win_condition.l1 = "locator";
			Pchar.quest.rob_store2.win_condition.l1.location = "Santiago_town_01";
			Pchar.quest.rob_store2.win_condition.l1.locator_group = "reload";
			Pchar.quest.rob_store2.win_condition.l1.locator = "reload6";
			Pchar.quest.rob_store2.win_condition.l2 = "Time";
			Pchar.quest.rob_store2.win_condition.l2.time = DAY_TIME_NIGHT;
			Pchar.quest.rob_store2.win_condition = "rob_store2";
		break;

		case "rob_store2":
			PlaySound("AMBIENT\TOWN\window_dog.wav");
			logit(TranslateString("","You broke the window and grabbed the map. Now RUN!"));
			GiveItem2Character(PChar,"mapCuba");
			LAi_QuestDelay("guards_respond", 12.0);
		break;

		case "guards_respond":
			Rapid_Raid("Soldiers", 6, SPAIN, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "Someone heard that window break!", "Soldier", OFFIC_TYPE_GUARD, 3, true, "blade_mKnife", "pistolmket");
		break;

		case "got_Cuba_map":
			if (checkquestattribute("payroll_ship", "active")) AddQuestRecord("Payroll Ship", 5);
			iForceDetectionFalseFlag = 0; // Restore normal false flag detection chances

// Enable sea access to Playa de Sierra Maestra once you have a map showing you where it is.
			Island_SetReloadEnableLocal("Cuba", "reload_8", true);
			Islands[FindIsland("Cuba")].reload.l7.goto_enable = true;

// Re-route Cuba_Jungle_04 to lead to normal Santiago exit, and open up Santiago exit to Cuba_Jungle_04.
// This allows you to walk between Santiago and Playa de Sierra Maestra.
			Locations[FindLocation("Santiago_town_exit1")].reload.l3.go = "Cuba_Jungle_04";
			Locations[FindLocation("Santiago_town_exit1")].reload.l3.emerge = "reload2";
			Locations[FindLocation("Santiago_town_exit1")].reload.l3.autoreload = "1";
			Locations[FindLocation("Santiago_town_exit1")].reload.l3.label = "Jungle";

			Locations[FindLocation("Cuba_Jungle_04")].reload.l4.go = "Santiago_town_exit1";
			Locations[FindLocation("Cuba_Jungle_04")].reload.l4.emerge = "reload1";
			Locations[FindLocation("Cuba_Jungle_04")].reload.l4.autoreload = "1";
			Locations[FindLocation("Cuba_Jungle_04")].reload.l4.label = "Santiago outskirts";
		break;

		case "nothing_in_Santiago":
			LAi_SetPlayerType(PChar);
			pchar.quest.after_night_Santiago_tavern.win_condition.l1 = "location";
			pchar.quest.after_night_Santiago_tavern.win_condition.l1.location = "Santiago_tavern_upstairs";
			pchar.quest.after_night_Santiago_tavern.win_condition = "after_night_Santiago_tavern";
		break;

		case "after_night_Santiago_tavern":
			if (!CheckCharacterItem(characterFromID("Jose Zugarro"), "mapCuba")) GiveItem2Character(characterFromID("Jose Zugarro"),"mapCuba");
			SetCharacterShipLocation(characterFromID("Spanish_Captain3"), "Santiago_port");
			PChar.quest.next_day_Santiago_port.win_condition.l1 = "location";
			PChar.quest.next_day_Santiago_port.win_condition.l1.location = "Santiago_port";
			PChar.quest.next_day_Santiago_port.win_condition = "next_day_Santiago_port";
		break;

		case "next_day_Santiago_port":
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 1;
			DisableFastTravel(true);
			Pchar.quest.board_brig.win_condition.l1 = "locator";
			Pchar.quest.board_brig.win_condition.l1.location = "Santiago_port";
			Pchar.quest.board_brig.win_condition.l1.locator_group = "reload";
			Pchar.quest.board_brig.win_condition.l1.locator = "reload2_back";
			Pchar.quest.board_brig.win_condition = "board_brig";
			ChangeCharacterAddressGroup(characterFromID("Spanish_Captain3"), "Quest_ShipDeck4", "officers", "reload1_1");
		break;

		case "board_brig":
			DoQuestReloadToLocation("Quest_ShipDeck4", "goto", "goto1", "board_brig2");
		break;

		case "board_brig2":
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_ShipDeck4")], true);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "sailor15", "officers", "reload1_2");
			sld.id = "scout";
			sld.old.name = "Hernan";
			sld.old.lastname = "Coelho";
			sld.name 	= TranslateString("","Hernan");
			sld.lastname 	= TranslateString("","Coelho");
			LAi_SetActorType(characterFromID("Spanish_Captain3"));
			Characters[GetCharacterIndex("Spanish_Captain3")].dialog.currentnode = "on_my_ship";
			LAi_ActorDialog(characterFromID("Spanish_Captain3"), PChar, "leave_brig", 5.0, 5.0);
		break;

		case "leave_brig":
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_port")], true);
			DoQuestReloadToLocation("Santiago_port", "reload", "reload2_back", "scout_leaves");
		break;

		case "scout_leaves":
			ChangeCharacterAddressGroup(characterFromID("Spanish_Captain3"), "Quest_Cabin", "goto", "goto2");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "sailor15", "goto", "goto1");
			sld.id = "scout";
			sld.old.name = "Hernan";
			sld.old.lastname = "Coelho";
			sld.name 	= TranslateString("","Hernan");
			sld.lastname 	= TranslateString("","Coelho");
			LAi_SetActorType(characterFromID("scout"));
			LAi_ActorGoToLocator(characterFromID("scout"), "reload", "reload1", "",65.0);
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				StoreDialog(crewref);
				LAi_SetActorType(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "follow_him";
				LAi_ActorDialog(crewref, pchar, "scout_leaves2", 5.0, 5.0);
			}
		break;

		case "scout_leaves2":
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_port")], false);
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				RestoreDialog(crewref);
			}
			for (n=1; n<4; n++)
			{
				if(GetOfficersIndex(Pchar, n) != -1)
				{
					LAi_SetActorType(CharacterFromId(characters[GetOfficersIndex(Pchar, n)].id));
					LAi_ActorGoToLocator(characters[GetOfficersIndex(Pchar, n)], "reload", "reload1", "",65.0);
				}
			}
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto8", "wait_for_crew", 65.0);
		break;

		case "wait_for_crew":
			for (n=1; n<OFFICER_MAX; n++)
			{
				if(GetOfficersIndex(Pchar, n) != -1)
				{
					ChangeCharacterAddress(characters[GetOfficersIndex(Pchar, n)], "None", "");
				}
			}
			ChangeCharacterAddress(characterFromID("scout"), "None", "");
			StoreOfficers(PChar.id);
			n = rand(44) + 15;
			WaitDate("", 0, 0, 0, 0, n);
			LAi_Fade("turn_to_crew", "watch_crew");
		break;

		case "turn_to_crew":
			LAi_ActorTurnToLocator(PChar, "reload", "reload2_back");
		break;

		case "watch_crew":

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor1", "reload", "reload2_back");
			sld.id = "brig_crew1";
			LAi_SetActorType(characterFromID("brig_crew1"));
			LAi_ActorRunToLocation(characterFromID("brig_crew1"), "reload", "reload1", "none", "", "", "", 30.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor2", "reload", "reload2_back");
			sld.id = "brig_crew2";
			LAi_SetActorType(characterFromID("brig_crew2"));
			LAi_ActorRunToLocation(characterFromID("brig_crew2"), "reload", "reload1", "none", "", "", "", 30.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor3", "reload", "reload2_back");
			sld.id = "brig_crew3";
			LAi_SetActorType(characterFromID("brig_crew3"));
			LAi_ActorRunToLocation(characterFromID("brig_crew3"), "reload", "reload1", "none", "", "", "", 30.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor5", "reload", "reload2_back");
			sld.id = "brig_crew4";
			LAi_SetActorType(characterFromID("brig_crew4"));
			LAi_ActorRunToLocation(characterFromID("brig_crew4"), "reload", "reload1", "none", "", "", "", 30.0);

			Pchar.quest.deck_battle.win_condition.l1 = "locator";
			Pchar.quest.deck_battle.win_condition.l1.location = "Santiago_port";
			Pchar.quest.deck_battle.win_condition.l1.locator_group = "reload";
			Pchar.quest.deck_battle.win_condition.l1.locator = "reload2_back";
			Pchar.quest.deck_battle.win_condition = "attack_brig";
			LAi_QuestDelay("watch_crew2", 1.0);
		break;

		case "watch_crew2":
			LAi_SetPlayerType(PChar);
			LAi_QuestDelay("crew_running", 0.0);
		break;

		case "crew_running":
			Pchar.dialog.CurrentNode = "attack_brig";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "crew_running2");
		break;

		case "crew_running2":
			LAi_SetPlayerType(PChar);
		break;

		case "attack_brig":
			DoQuestReloadToLocation("Quest_ShipDeck4", "goto", "goto1", "deck_battle");
		break;

		case "deck_battle":
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_ShipDeck4")], false);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "sailor6", "officers", "reload1_3");
			GiveItem2Character(sld,"blade4");
			EquipCharacterByItem(sld,"blade4");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "CARGO_SOLDIERS");
			sld.id = "ship_guard1";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "bocman8", "reload", "reload1");
			GiveItem2Character(sld,"blade4");
			EquipCharacterByItem(sld,"blade4");
			GiveItem2Character(sld, "Pistol2");
			EquipCharacterByItem(sld,"Pistol2");
			if (ENABLE_AMMOMOD)
			{	// LDH change
				TakenItems(sld, "gunpowder", 1 + rand(2));
				TakenItems(sld, "pistolbullets", 1 + rand(2));
			}
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "CARGO_SOLDIERS");
			sld.id = "ship_guard2";

			LAi_group_FightGroups("CARGO_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("CARGO_SOLDIERS", "deck_won");
		break;

		case "deck_won":
			Locations[FindLocation("Quest_Cabin")].reload.l1.disable = 1;
			PChar.quest.cabin_duel.win_condition.l1 = "location";
			PChar.quest.cabin_duel.win_condition.l1.location = "Quest_Cabin";
			PChar.quest.cabin_duel.win_condition = "cabin_duel";
		break;

		case "cabin_duel":
			LAi_SetFightMode(PChar, false);
			LAi_SetActorType(characterFromID("Spanish_Captain3"));
			Characters[GetCharacterIndex("Spanish_Captain3")].dialog.currentnode = "First time";
			LAi_ActorDialog(characterFromID("Spanish_Captain3"), PChar, "cabin_duel2", 5.0, 5.0);
		break;

		case "cabin_duel2":
//			LAi_SetFightMode(PChar, true);
			LAi_group_MoveCharacter(characterFromID("Spanish_Captain3"), "CARGO_SOLDIERS");
			LAi_group_FightGroups("CARGO_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("CARGO_SOLDIERS", "find_papers");
		break;

		case "find_papers":
			LAi_SetFightMode(PChar, false);
			Pchar.dialog.CurrentNode = "find_papers";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "ship_is_ours");
		break;

		case "ship_is_ours":
			if (GetCharacterShipType(PChar) == SHIP_NOTUSED) Locations[FindLocation("Santiago_port")].reload.l2.olddisablevalue = 0; // Fix for locked port if you sold the original tartane
			LAi_SetPlayerType(PChar);
			GiveShip2Character(PChar,"Shnyava2","Tonina",CANNON_TYPE_CARRONADE_LBS12,SPAIN,false,true);
			Locations[FindLocation("Quest_Cabin")].reload.l1.disable = 0;
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;
			AddCharacterGoods(PChar, GOOD_RUM, 20);
			AddCharacterGoods(PChar, GOOD_WHEAT, 40);
			AddCharacterGoods(PChar, GOOD_SAILCLOTH, 20);
			AddCharacterGoods(PChar, GOOD_PLANKS, 20);
			SetCharacterShipLocation(PChar, "Santiago_port");
			makearef(arShip, PChar.ship.stats);
			arship.MaxCaliber = 6;
			SetCrewQuantity(PChar, sti(PChar.quest.crew_left));
			DeleteQuestAttribute("crew_left");
			PChar.quest.ship_is_ours2.win_condition.l1 = "location";
			PChar.quest.ship_is_ours2.win_condition.l1.location = "Quest_ShipDeck4";
			PChar.quest.ship_is_ours2.win_condition = "ship_is_ours2";
		break;

		case "ship_is_ours2":
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_ShipDeck4")], true);
			Locations[FindLocation("Quest_ShipDeck4")].reload.l1.disable = 1;

			ChangeCharacterAddressGroup(CharacterfromID("Spanish_soldier1"), "Quest_ShipDeck4", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterfromID("Spanish_soldier2"), "Quest_ShipDeck4", "goto", "goto4");
			LAi_SetActorType(CharacterFromID("Spanish_soldier1"));
			characters[GetCharacterIndex("Spanish_soldier1")].Dialog.Filename = "guard_dialog.c";
			Characters[GetCharacterIndex("Spanish_soldier1")].dialog.CurrentNode = "snow_brig_check";
			LAi_ActorDialog(characterFromID("Spanish_soldier1"), PChar, "", 10.0, 10.0); // Exits to "back_to_prison" or "ship_is_ours3"

		break;

		case "ship_is_ours3":
			iForceDetectionFalseFlag = 0; // Restore normal false flag detection chances - backup in case you never went into store
			DisableFastTravel(false);
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_ShipDeck4")], false);
			Locations[FindLocation("Quest_ShipDeck4")].reload.l1.disable = 0;
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(PChar, "", 100);
				AddPartyExpChar(pchar, "Sneak", 100);
			}
			else {AddPartyExp(pchar, 1500);}
			if (checkquestattribute("payroll_ship", "active")) AddQuestRecord("Payroll Ship", 6);
			RestoreOfficers(PChar.id);
			DoQuestReloadToLocation("Santiago_port", "reload", "reload2_back", "restore_officers");
		break;

		case "restore_officers":
			ChangeCharacterAddress(CharacterfromID("Spanish_soldier1"), "None", "");
			ChangeCharacterAddress(CharacterfromID("Spanish_soldier2"), "None", "");
			characters[GetCharacterIndex("Spanish_soldier1")].Dialog.Filename = "Soldier_dialog.c";
			characters[GetCharacterIndex("Spanish_soldier1")].Dialog.Filename = "Soldier_dialog.c";
			setCharacterShipLocation(Pchar, "Santiago_port");
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor1", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "QC_SOLDIERS");
			sld.id = "sailor1";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor2", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "QC_SOLDIERS");
			sld.id = "sailor2";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor3", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "QC_SOLDIERS");
			sld.id = "sailor3";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor5", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "QC_SOLDIERS");
			sld.id = "sailor4";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "bocman10", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "QC_SOLDIERS");
			sld.id = "sailor5";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "bocman16", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "QC_SOLDIERS");
			sld.id = "sailor6";
			LAi_group_FightGroups("QC_SOLDIERS", LAI_GROUP_PLAYER, true);

			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				StoreDialog(crewref);
				LAi_SetActorType(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "crew_returning";
				LAi_ActorDialog(crewref, pchar, "crew_returning", 5.0, 5.0);
			}
			else logit(TranslateString("","That looks like the original crew returning. Better get aboard and get out of here!"));
		break;

		case "crew_returning":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				RestoreDialog(crewref);
				LAi_SetOfficerType(CharacterFromId(characters[crewidx].id));
			}
		break;

		case "payroll_ship_sails":
			if (CheckCharacterItem(PChar, "mapCuba")) AddQuestRecord("Payroll Ship", 7);
			else AddQuestRecord("Payroll Ship", 10);
			PChar.quest.payroll_ship_timer2.win_condition.l1 = "Timer";
			PChar.quest.payroll_ship_timer2.win_condition.l1.date.day = GetAddingDataDay(0, 0, 14);
			PChar.quest.payroll_ship_timer2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
			PChar.quest.payroll_ship_timer2.win_condition.l1.date.year = GetAddingDataYear(0, 0, 14);
			PChar.quest.payroll_ship_timer2.win_condition = "payroll_ship_arrives";

			PChar.quest.ready_for_payroll_ship.win_condition.l1 = "location";
			PChar.quest.ready_for_payroll_ship.win_condition.l1.location = "Cuba_Shore_05";
			PChar.quest.ready_for_payroll_ship.win_condition = "ready_for_payroll_ship";
		break;

		case "ready_for_payroll_ship":
			GiveShip2Character(characterFromID("Spanish_Captain2"),"SP_CastelF","Siroco",-1,SPAIN,true,true);			
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				StoreDialog(crewref);
				LAi_SetActorType(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "ready_for_payroll_ship";
				LAi_ActorDialog(crewref, pchar, "ready_for_payroll_ship2", 5.0, 5.0);
			}
			else
			{
				logit(TranslateString("","Now to wait for the 'Siroco'..."));
				LAi_QuestDelay("ready_for_payroll_ship3", 0.0);
			}
			PChar.quest.payroll_ship_timer2.over = "yes";
		break;

		case "ready_for_payroll_ship2":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				RestoreDialog(crewref);
				LAi_SetOfficerType(CharacterFromId(characters[crewidx].id));
			}
			WaitDate("", 0, 0, 3 + rand(7), 0, 0);
			SetCurrentTime(rand(23), rand(59));
			LAi_Fade("", "");
			DoQuestReloadToLocation("Cuba_Shore_05", "reload", "reload1", "ready_for_payroll_ship3");
		break;

		case "ready_for_payroll_ship3":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				StoreDialog(crewref);
				LAi_SetActorType(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "payroll_ship_in_sight";
				LAi_ActorDialog(crewref, pchar, "payroll_ship_in_sight", 5.0, 5.0);
			}
		break;

		case "payroll_ship_in_sight":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				RestoreDialog(crewref);
				LAi_SetOfficerType(CharacterFromId(characters[crewidx].id));
			}
			Pchar.quest.payroll_ship_setup.win_condition.l1 = "location";
			Pchar.quest.payroll_ship_setup.win_condition.l1.location = "Cuba";
			Pchar.quest.payroll_ship_setup.win_condition = "payroll_ship_setup";
			if (IsInParty(GetMainCharacterIndex(), GetCharacterIndex("Two Dogs"))) LAi_SetImmortal(characterFromID("Two Dogs"), true);
		break;

		case "payroll_ship_setup":
			Group_CreateGroup("payroll_ship");
			Group_AddCharacter("payroll_ship", "Spanish_Captain2");
			Group_SetGroupCommander("payroll_ship", "Spanish_Captain2");

			Group_SetPursuitGroup("payroll_ship", PLAYER_GROUP);
			Group_SetTaskAttack("payroll_ship",  PLAYER_GROUP, true);
			Group_LockTask("payroll_ship");
			Group_SetAddress("payroll_ship", "Cuba", "Quest_ships", "quest_ship_1");
			Sea_LoginGroupNow("payroll_ship");
			characters[GetCharacterIndex("Spanish_Captain2")].nosurrender = 2;
			SetCharacterRelationBoth(GetCharacterIndex("payroll_ship"),GetMainCharacterIndex(),RELATION_ENEMY);

			pchar.quest.payroll_ship_taken.win_condition.l1 = "Character_Capture";
			pchar.quest.payroll_ship_taken.win_condition.l1.character = "Spanish_Captain2";
			pchar.quest.payroll_ship_taken.win_condition.l2 = "SeaEnter";
			pchar.quest.payroll_ship_taken.win_condition = "payroll_ship_taken";
			pchar.quest.payroll_ship_taken1.win_condition.l1 = "NPC_Death";
			pchar.quest.payroll_ship_taken1.win_condition.l1.character = "Spanish_Captain2";
			pchar.quest.payroll_ship_taken1.win_condition.l2 = "SeaEnter";
			pchar.quest.payroll_ship_taken1.win_condition = "payroll_ship_taken";
		break;

		case "payroll_ship_taken":
			pchar.quest.payroll_ship_taken.over = "yes";
			pchar.quest.payroll_ship_taken1.over = "yes";
			if (IsInParty(GetMainCharacterIndex(), GetCharacterIndex("Two Dogs"))) LAi_SetImmortal(characterFromID("Two Dogs"), false);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1200);
				AddPartyExpChar(PChar, "", 120);
				AddPartyExpChar(pchar, "Sneak", 120);
			}
			else {AddPartyExp(pchar, 1500);}
			AddMoneyToCharacter(pchar, 10000);
			AddQuestRecord("Payroll Ship", 9);
			CloseQuestHeader("Payroll Ship");
			TakeItemFromCharacter(Pchar, "SecurityLetter");
			PChar.quest.payroll_ship = "success";
			ch = characterFromID("Santiago Commander");
			ch.PlayerNation = GetCurrentFlag();
			ch.PlayerShip = GetCharacterShipModel(PChar);
//			Trace("Ardent: The " + GetMyShipNameShow(ch) + " will remember us as " + GetNationDescByType(sti(ch.PlayerNation)) + " in a " + ch.PlayerShip);
		break;

		case "payroll_ship_arrives":
			AddQuestRecord("Payroll Ship", 8);
			CloseQuestHeader("Payroll Ship");
			TakeItemFromCharacter(Pchar, "SecurityLetter");
			PChar.quest.payroll_ship = "failure";
		break;

		case "two_dogs_is_home":
			PChar.quest.two_dogs_dead.over = "yes";
			LAi_SetActorType(characterFromID("Two Dogs"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Two Dogs"));
			RemovePassenger(pchar, characterFromID("Two Dogs"));
			ChangeCharacterAddressGroup(characterFromID("Two Dogs"), "Quest_Indian_house", "goto", "goto4");

			LAi_SetActorType(characterFromID("Quest_Chief_Indian1"));
			Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "two_dogs_home";
			LAi_ActorDialog(characterFromID("Quest_Chief_Indian1"),PChar,"two_dogs_is_home2",5.0,5.0);
		break;

		case "two_dogs_is_home2":
//			DeleteQuestAttribute("take_two_dogs_home");
			PChar.quest.take_two_dogs_home = "complete";
			LAi_SetGuardianTypeNoGroup(characterFromID("Quest_Chief_Indian1"));
			LAi_SetActorType(characterFromID("Two Dogs"));
			Characters[GetCharacterIndex("Two Dogs")].dialog.CurrentNode = "embarrassing_name";
			LAi_ActorDialogNow(characterFromID("Two Dogs"),PChar,"two_dogs_is_home3",2.0);
		break;

		case "two_dogs_is_home3":
			if (PChar.quest.alignment == "good")
			{
				ChangeCharacterReputation(pchar, 5);
				AddQuestRecord("Take Two Dogs Home", 5);
			}
			else
			{
				AddQuestRecord("Take Two Dogs Home", 6);
				characters[GetCharacterIndex("Two Dogs")].lastname = TranslateString("","not-Fighting");
			}
			CloseQuestHeader("Take Two Dogs Home");
			LAi_SetActorType(characterFromID("Two Dogs"));
			LAi_ActorGoToLocator(characterFromID("Two Dogs"), "goto", "goto3", "two_dogs_is_home4", 5.0);
		break;

		case "two_dogs_is_home4":
			LAi_SetGuardianTypeNoGroup(characterFromID("Two Dogs"));
			Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "temple_quest";
		break;

		case "temple_quest_starts":
			SetQuestHeader("Mayan Temple");
			AddQuestRecord("Mayan Temple", 1);
			PChar.quest.mayan_temple = "find_guide";
			Characters[GetCharacterIndex("Mauricio Juradu")].dialog.CurrentNode = "hire_guide";
			pchar.quest.inside_temple.win_condition.l1 = "location";
			PChar.quest.inside_temple.win_condition.l1.character = PChar.id;
			pchar.quest.inside_temple.win_condition.l1.location = "Quest_Hispaniola_Labirint_1";
			pchar.quest.inside_temple.win_condition = "inside_temple";
		break;

		case "hired_guide":
			PChar.quest.mayan_temple = "got_guide";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -500);
			pchar.quest.with_guide_to_cape_francos.win_condition.l1 = "location";
			PChar.quest.with_guide_to_cape_francos.win_condition.l1.location = "Santo_Domingo_port";
			PChar.quest.with_guide_to_cape_francos.win_condition = "with_guide_to_cape_francos";
			pchar.quest.with_guide_to_cape_francos_1.win_condition.l1 = "location";
			PChar.quest.with_guide_to_cape_francos_1.win_condition.l1.location = "Hispaniola_shore_01";
			PChar.quest.with_guide_to_cape_francos_1.win_condition = "with_guide_to_cape_francos";
			LAi_SetActorType(characterFromID("Mauricio Juradu"));
			ChangeCharacterAddressGroup(characterFromID("Mauricio Juradu"), "Santo_Domingo_Tavern", "tables", "table5");
			LAi_ActorFollowEverywhere(CharacterFromID("Mauricio Juradu"), "", 1.0);
		break;

		case "with_guide_to_cape_francos":
			PChar.quest.with_guide_to_cape_francos.over = "yes";
			PChar.quest.with_guide_to_cape_francos_1.over = "yes";
			LAi_SetActorType(characterFromID("Mauricio Juradu"));
			Characters[GetCharacterIndex("Mauricio Juradu")].dialog.CurrentNode = "find_beach";
			LAi_ActorDialog(characterFromID("Mauricio Juradu"),PChar,"with_guide_to_cape_francos2",5.0,5.0);
		break;

		case "with_guide_to_cape_francos2":
			LAi_ActorFollowEverywhere(CharacterFromID("Mauricio Juradu"), "", 1.0);
			pchar.quest.with_guide_to_cape_francos3.win_condition.l1 = "location";
			PChar.quest.with_guide_to_cape_francos3.win_condition.l1.location = "Hispaniola_shore_03";
			PChar.quest.with_guide_to_cape_francos3.win_condition = "with_guide_to_cape_francos3";
		break;

		case "with_guide_to_cape_francos3":
			LAi_SetActorType(characterFromID("Mauricio Juradu"));
			Characters[GetCharacterIndex("Mauricio Juradu")].dialog.CurrentNode = "start_of_trail";
			LAi_ActorDialog(characterFromID("Mauricio Juradu"),PChar,"trek_to_temple",5.0,5.0);
		break;

		case "trek_to_temple":
//			LAi_SetImmortal(characterFromID("Mauricio Juradu"), true);
			LAi_SetActorType(characterFromID("Mauricio Juradu"));
            		LAi_ActorGoToLocation(characterFromID("Mauricio Juradu"), "reload", "locator3_back", "Hispaniola_Jungle_07", "reload", "reload1_back", "", 60.0);
			pchar.quest.with_guide_to_cape_francos3.win_condition.l1 = "location";
			PChar.quest.with_guide_to_cape_francos3.win_condition.l1.location = "Hispaniola_Jungle_07";
			PChar.quest.with_guide_to_cape_francos3.win_condition = "trek_to_temple2";
		break;

		case "trek_to_temple2":
			ChangeCharacterAddressGroup(characterFromID("Mauricio Juradu"), "Hispaniola_Jungle_07", "reload", "reload1_back");
			LAi_ActorStay(characterFromID("Mauricio Juradu"));
			LAi_QuestDelay("trek_to_temple3", 0.0);
		break;

		case "trek_to_temple3":
			Locations[FindLocation("Hispaniola_Jungle_07")].reload.l4.disable = 1;
			pchar.quest.end_of_trek.win_condition.l1 = "location";
			PChar.quest.end_of_trek.win_condition.l1.character = PChar.id;
			pchar.quest.end_of_trek.win_condition.l1.location = "Hispaniola_Temple";
			pchar.quest.end_of_trek.win_condition = "end_of_trek";
			LAi_SetActorType(characterFromID("Mauricio Juradu"));
			LAi_ActorGoToLocator(characterFromID("Mauricio Juradu"), "reload", "reload3_back", "",60.0);
		break;

		case "end_of_trek":
			ChangeCharacterAddressGroup(characterFromID("Mauricio Juradu"), "Hispaniola_Temple", "reload", "reload1_back");
			Locations[FindLocation("Hispaniola_Jungle_07")].reload.l4.disable = 0;
			LAi_SetActorType(characterFromID("Mauricio Juradu"));
			Characters[GetCharacterIndex("Mauricio Juradu")].dialog.CurrentNode = "end_of_trail";
			LAi_ActorDialog(characterFromID("Mauricio Juradu"),PChar,"",5.0,5.0);
		break;

		case "inside_temple":
			PChar.quest.disable_rebirth = true;
			DisableFastTravel(true);
			if (!LAi_IsDead(characterFromID("Mauricio Juradu")))
			{
				if (checkQuestAttribute("mayan_temple", "got_guide"))
				{
					Locations[FindLocation("Hispaniola_shore_03")].reload.l2.disable = 1;
					ChangeCharacterAddressGroup(characterFromID("Mauricio Juradu"), "BC_Tavern", "goto", "goto6");
					LAi_SetImmortal(characterFromID("Mauricio Juradu"), false);
					pchar.quest.mauricio_steals_ship.win_condition.l1 = "location";
					PChar.quest.mauricio_steals_ship.win_condition.l1.location = "Hispaniola_Jungle_07";
					PChar.quest.mauricio_steals_ship.win_condition = "mauricio_steals_ship";
				}
				else Characters[GetCharacterIndex("Mauricio Juradu")].dialog.CurrentNode = "First time";
			}
			pchar.quest.inside_lab3.win_condition.l1 = "location";
			PChar.quest.inside_lab3.win_condition.l1.location = "Quest_Hispaniola_Labirint_3";
			PChar.quest.inside_lab3.win_condition = "inside_lab3";
			Pchar.quest.got_the_rug.win_condition.l1 = "item";
			PChar.quest.got_the_rug.win_condition.l1.character = Pchar.id;
			Pchar.quest.got_the_rug.win_condition.l1.item = "TainoRug";
			Pchar.quest.got_the_rug.win_condition = "got_the_rug";
			PChar.quest.mayan_temple = "been_to_temple";
		break;

		case "inside_lab3":
			AddQuestRecord("Mayan Temple", 2);
			Locations[FindLocation("Quest_Hispaniola_Labirint_3")].locators_radius.goto.goto1 = 2.0;
			Pchar.quest.seen_rug.win_condition.l1 = "locator";
			Pchar.quest.seen_rug.win_condition.l1.location = "Quest_Hispaniola_Labirint_3";
			Pchar.quest.seen_rug.win_condition.l1.locator_group = "goto";
			Pchar.quest.seen_rug.win_condition.l1.locator = "goto1";
			Pchar.quest.seen_rug.win_condition = "seen_rug";
		break;

		case "seen_rug":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem1");
			LAi_QuestDelay("seen_rug2", 3.0);
		break;

		case "seen_rug2":
			LAi_SetPlayerType(PChar);
			logit(TranslateString("","Maybe there's something in that room with the wall markings..."));
		break;

		case "got_the_rug":
			AddQuestRecord("Mayan Temple", 3);
			pchar.quest.rug_to_chief.win_condition.l1 = "location";
			PChar.quest.rug_to_chief.win_condition.l1.character = PChar.id;
			pchar.quest.rug_to_chief.win_condition.l1.location = "Quest_Indian_house";
			pchar.quest.rug_to_chief.win_condition = "rug_to_chief";
		break;

		case "mauricio_steals_ship":
			if(GetAttribute(romance, "location") == "Tutorial_Deck")	// Fix for "romance" disappearing from cabin while you are on Doolin's tartane
			{
				romance.quest.saved_location = GetAttribute(romance, "location");
				romance.quest.saved_group = GetAttribute(romance, "location.group");
				romance.quest.saved_locator = GetAttribute(romance, "location.locator");
			}
			ExchangeCharacterShip(Pchar, characterFromID("Mauricio Juradu"));
			setCharacterShipLocation(characterFromID("Mauricio Juradu"), "Hispaniola_shore_02");
			ChangeCharacterAddressGroup(characterFromID("Doolin Becart"), "Hispaniola_shore_03", "goto", "citizen05");
			Characters[GetCharacterIndex("Doolin Becart")].dialog.CurrentNode = "meet_Doolin";
			pchar.quest.find_mauricio_in_buccaneer_tavern.win_condition.l1 = "location";
			PChar.quest.find_mauricio_in_buccaneer_tavern.win_condition.l1.location = "BC_Tavern";
			PChar.quest.find_mauricio_in_buccaneer_tavern.win_condition = "find_mauricio_in_buccaneer_tavern";
			pchar.quest.missing_ship.win_condition.l1 = "location";
			PChar.quest.missing_ship.win_condition.l1.location = "Hispaniola_shore_03";
			PChar.quest.missing_ship.win_condition = "missing_ship";
		break;

		case "missing_ship":
			AddQuestRecord("Mayan Temple", 4);
		break;

// Doolin Becart should now be standing on Cape Francos waiting for you to talk to him.  His dialog exits to either "sail_with_doolin" or "steal_doolins_boat".
		case "sail_with_doolin":
			Locations[FindLocation("Hispaniola_shore_03")].reload.l2.disable = 0;
			DisableFastTravel(false);
			HoistFlag(FRANCE);
		break;

		case "steal_doolins_boat":
			Locations[FindLocation("Hispaniola_shore_03")].reload.l2.disable = 0;
			DisableFastTravel(false);
			LAi_SetFightMode(PChar, true);
			LAi_SetActorType(characterfromID("Doolin Becart"));
			LAi_ActorAttack(characterfromID("Doolin Becart"), PChar, "");
		break;

		case "find_mauricio_in_buccaneer_tavern":
			LAi_LocationFightDisable(&Locations[FindLocation("BC_Tavern")], false);
			if (!LAi_IsDead(characterFromID("Doolin Becart")))
			{
				ChangeCharacterAddressGroup(characterFromID("Doolin Becart"), "PoPrince_Port", "goto", "goto6");
				Characters[GetCharacterIndex("Doolin Becart")].dialog.CurrentNode = "sell_fish";
				LAi_SetCitizenType(characterFromID("Doolin Becart"));
				GiveShip2Character(characterFromID("Doolin Becart"),"Tartane2","Jacqueline",-1,SPAIN,true,true); // May as well put his ship in port as well
				setCharacterShipLocation(characterFromID("Doolin Becart"), "PoPrince_Port");
			}
			else ChangeCharacterAddress(characterFromID("Doolin Becart"), "None", "");
			Characters[GetCharacterIndex("Mauricio Juradu")].dialog.CurrentNode = "recruiting";
			LAi_ActorDialogNow(characterFromID("Mauricio Juradu"),PChar,"officers_help",1.0);
		break;

		case "bass_joke":
			LAi_SetActorType(characterFromID("Two Dogs"));
			characters[GetCharacterIndex("Two Dogs")].Dialog.Filename = "Two Dogs_dialog.c";
			Characters[GetCharacterIndex("Two Dogs")].dialog.CurrentNode = "bass_joke";
			LAi_ActorDialogNow(characterFromID("Two Dogs"),PChar,"reset_two_dogs",2.0);
		break;

		case "reset_two_dogs":
			LAi_SetOfficerType(characterFromID("Two Dogs"));
		break;
			

		case "officers_help":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				StoreDialog(crewref);
				LAi_SetActorType(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "buccaneer_tavern_duel";
				LAi_ActorDialog(crewref, pchar, "buccaneer_tavern_duel", 5.0, 5.0);
			}
			else LAi_QuestDelay("buccaneer_tavern_duel", 0.5);
		break;

		case "buccaneer_tavern_duel":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				RestoreDialog(crewref);
				LAi_SetOfficerType(CharacterFromId(characters[crewidx].id));
			}
			LAi_QuestDelay("buccaneer_tavern_duel2", 0.5);
		break;

		case "buccaneer_tavern_duel2":
			LAi_SetActorType(characterFromID("Mauricio Juradu"));
			LAi_ActorAttack(characterfromID("Mauricio Juradu"), PChar, "");
			PChar.quest.retake_ship.win_condition.l1 = "NPC_Death";
			PChar.quest.retake_ship.win_condition.l1.character = "Mauricio Juradu";
			PChar.quest.retake_ship.win_condition = "retake_ship";
		break;

		case "retake_ship":
			ExchangeCharacterShip(Pchar, characterFromID("Mauricio Juradu"));
			PChar.quest.disable_rebirth = false;
			AddQuestRecord("Mayan Temple", 5);

			if(CheckAttribute(romance, "quest.saved_location"))	// This was set in "mauricio_steals_ship" if "romance" was in your cabin when you went on Doolin Becart's tartane
			{
				Pchar.quest.romance_back_to_cabin.win_condition.l1 = "ExitFromLocation";
				PChar.quest.romance_back_to_cabin.win_condition.l1.location = PChar.location;
				Pchar.quest.romance_back_to_cabin.win_condition = "romance_back_to_cabin";
			}
		break;

		case "romance_back_to_cabin":
			ChangeCharacterAddressGroup(romance, romance.quest.saved_location, romance.quest.saved_group, romance.quest.saved_locator);
			DeleteAttribute(romance, "quest.saved_location");
			DeleteAttribute(romance, "quest.saved_group");
			DeleteAttribute(romance, "quest.saved_locator");
		break;

		case "rug_to_chief":
			LAi_SetGuardianTypeNoGroup(characterFromID("Two Dogs"));
			Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "is_this_it"; // You will talk to chief, which exits to "get_bow" or "no_rug".
		break;

		case "get_bow":
			AddQuestRecord("Mayan Temple", 6);
			CloseQuestHeader("Mayan Temple");
			if (ENABLE_AMMOMOD)
			{
				GiveItem2Character(PChar,"pistolbow");
				GiveItem2Character(PChar,"quiver");
				GiveItem2Character(PChar,"curare");
				GiveItem2Character(PChar,"tar");
				TakenItems(PChar, "bladearrows", 3);
			}
			else
			{
				GiveItem2Character(PChar,"jewelry16");
				if (!CheckCharacterItem(PChar, "pistolbow")) GiveItem2Character(PChar,"pistolbow");
				GiveItem2Character(PChar,"bladearrows");		// Arrows are not given to Indians if ammo mod is disabled, but they are still defined, and one is needed for bow rescue
			}
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 1200);
				AddPartyExpChar(PChar, "", 120);
				AddPartyExpChar(pchar, "Sneak", 120);
			}
			else {AddPartyExp(pchar, 1500);}
			if (checkquestattribute("take_two_dogs_home", "complete"))
			{
				LAi_SetActorType(characterFromID("Two Dogs"));
				Characters[GetCharacterIndex("Two Dogs")].dialog.CurrentNode = "rejoin";
				LAi_ActorDialog(characterFromID("Two Dogs"),PChar,"",5.0,5.0); // Exits to "two_dogs_rejoins" or "two_dogs_no_rejoin"
				DeleteQuestAttribute("take_two_dogs_home");
			}
		break;

		case "no_rug":
			AddQuestRecord("Mayan Temple", 7);
			CloseQuestHeader("Mayan Temple");
		break;

		case "two_dogs_rejoins":
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Two Dogs"));
			LAi_SetOfficerType(CharacterFromId("Two Dogs"));
			Characters[GetCharacterIndex("Two Dogs")].dialog.Filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Two Dogs")].dialog.CurrentNode = "hired";
		break;

		case "two_dogs_no_rejoin":
			Characters[GetCharacterIndex("Two Dogs")].dialog.CurrentNode = "rejoin";
			LAi_SetGuardianTypeNoGroup(characterFromID("Two Dogs"));
		break;

		case "kidnap_breakin":
			PlaySound("PEOPLE\lockpick2.wav");
			LAi_QuestDelay("kidnap_breakin2", 2.0);
		break;

		case "kidnap_breakin2":
			DoQuestReloadToLocation("Santiago_townhall", "reload", "reload1", "kidnap_breakin3");
		break

		case "kidnap_breakin3":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(romance, "Quest_Santiago_Bedroom", "goto", "goto5");
			LAi_SetActorType(characterFromID("Grigorio Formoselle"));
			Characters[GetCharacterIndex("Grigorio Formoselle")].dialog.CurrentNode = "break-in";
			LAi_ActorDialog(characterFromID("Grigorio Formoselle"),PChar,"kidnap_breakin4",5.0,5.0);
		break;

		case "kidnap_breakin4":
			LAi_SetStayType(characterFromID("Grigorio Formoselle"));
			LAi_SetLoginTime(characterFromID("Javier Balboa"), 0.0, 24.0);
			DoQuestReloadToLocation("Quest_Santiago_Bedroom", "reload", "reload1", "kidnap_breakin5");
		break;

		case "kidnap_breakin5":
			Pchar.quest.seen_window.over = "yes";
			Characters[romanceidx].dialog.CurrentNode = "intruder";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"kidnap_escape",10.0,10.0);
		break;

		case "kidnap_escape":
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
			LAi_SetActorType(characterfromID("Javier Balboa"));
			DoQuestReloadToLocation("Santiago_townhall", "reload", "reload2", "kidnap_escape2");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard1"), "Santiago_townhall", "goto", "goto11");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard2"), "Santiago_townhall", "goto", "goto12");
			LAi_SetGuardianType(characterfromID("Spanish_guard1"));
			LAi_SetGuardianType(characterfromID("Spanish_guard2"));
		break;

		case "kidnap_escape2":
			EndQuestMovie();
			DisableFastTravel(true);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "kidnap_threaten";
			LAi_ActorDialog(characterFromID("Javier Balboa"),PChar,"kidnap_governor_returns_to_standpoint",1.0,1.0);
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			PChar.quest.kidnap_escape3.win_condition.l1 = "location";
			PChar.quest.kidnap_escape3.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.kidnap_escape3.win_condition = "kidnap_escape3";

			Pchar.quest.kidnap_what_next.win_condition.l1 = "locator";
			Pchar.quest.kidnap_what_next.win_condition.l1.location = "Santiago_port";
			Pchar.quest.kidnap_what_next.win_condition.l1.locator_group = "reload";
			Pchar.quest.kidnap_what_next.win_condition.l1.locator = "reload2_back";
			Pchar.quest.kidnap_what_next.win_condition = "kidnap_what_next";
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 1;

			Pchar.quest.kidnap_what_next2.win_condition.l1 = "locator";
			Pchar.quest.kidnap_what_next2.win_condition.l1.location = "Cuba_shore_02";
			Pchar.quest.kidnap_what_next2.win_condition.l1.locator_group = "reload";
			Pchar.quest.kidnap_what_next2.win_condition.l1.locator = "boat";
			Pchar.quest.kidnap_what_next2.win_condition = "kidnap_what_next";
			Locations[FindLocation("Cuba_shore_02")].reload.l2.disable = 1;

			PChar.quest.kidnap_hostage_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.kidnap_hostage_dead.win_condition.l1.character = romance.id;
			PChar.quest.kidnap_hostage_dead.win_condition = "hostage_dead";

			Locations[FindLocation("Redmond_town_03")].reload.l9.disable = 1; // If you have kidnapped Lucía / Edmundo then you won't get to do the courier jobs
		break;

		case "kidnap_governor_returns_to_standpoint":
			LAi_SetActorType(characterfromID("Javier Balboa"));
			LAi_ActorGoToLocator(characterFromID("Javier Balboa"), "goto", "goto3", "kidnap_governor_returns_to_standpoint2",20.0);
		break;

		case "kidnap_governor_returns_to_standpoint2":
			LAi_SetActorType(characterfromID("Javier Balboa"));
			LAi_ActorTurnToLocator(characterFromID("Javier Balboa"), "reload", "reload1");
		break;

		case "kidnap_escape3":
			ch = characterFromID("Javier Balboa");
			ch.skill.Fencing = "10";
			ch.skill.Accuracy = "5";
			ch.skill.Defence = "5";
			ch.perks.list.BasicDefence = true;
			ch.perks.list.AdvancedDefence = true;
			ch.perks.list.SwordplayProfessional = true;
			ch.perks.list.CriticalHit = true;
			Ch.Perks.list.Toughness = true;
			GiveItem2Character(characterfromID("Javier Balboa"), "bladeC23+2");
			GiveItem2Character(characterfromID("Javier Balboa"), "goldarmor");
			EquipCharacterByItem(characterfromID("Javier Balboa"),"bladeC23");
			EquipCharacterByItem(characterfromID("Javier Balboa"),"goldarmor");
			LAi_SetHP(characterfromID("Javier Balboa"), 500.0, 500.0);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "revenge";
			LAi_SetStayType(characterFromID("Javier Balboa"));
			if (PChar.quest.alignment == "evil") ChangeCharacterReputation(PChar, -5);
			else ChangeCharacterReputation(PChar, -10);
			ChangeCharacterAddressGroup(romance, "Santiago_town_01", "reload", "reload4");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			LAi_SetActorType(characterFromID("Santiago_soldier_05"));
			characters[GetCharacterIndex("Santiago_soldier_05")].Dialog.Filename = "guard_dialog.c";
			if (GetDayTime() == DAY_TIME_NIGHT) Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "residence_challenge";
			else Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "residence_challenge_day";
			LAi_ActorDialog(characterFromID("Santiago_soldier_05"),PChar,"hostage_replies",5.0,5.0);
		break;

		case "hostage_replies":
			if (checkquestattribute("ardent_kidnap.status", "cooperate")) Characters[romanceidx].dialog.CurrentNode = "answer_guard";
			else Characters[romanceidx].dialog.CurrentNode = "guard_help";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"",5.0,5.0); // Exits either to "kidnap_battle", "kidnap_cooperate" or "kidnap_cooperate_day"
		break;

		case "kidnap_battle":
			LAi_group_MoveCharacter(characterFromID("Santiago_soldier_05"), "SPAIN_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Santiago_soldier_06"), "SPAIN_SOLDIERS");
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "kidnap_battle_over");
			Pchar.quest.ran_away.win_condition.l1 = "ExitFromLocation";
			PChar.quest.ran_away.win_condition.l1.location = PChar.location;
			Pchar.quest.ran_away.win_condition = "ran_away";
		break;

		case "kidnap_battle_over":
			DisableFastTravel(false);
			PChar.quest.ran_away.over = "yes";
			Characters[romanceidx].dialog.CurrentNode = "apologise";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"continue_with_kidnap",65.0,65.0);
		break;

		case "kidnap_cooperate":
			Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "hostage_cooperated";
			LAi_ActorDialog(characterFromID("Santiago_soldier_05"),PChar,"continue_with_kidnap",5.0,5.0);
		break;

		case "continue_with_kidnap":
			characters[GetCharacterIndex("Santiago_soldier_05")].Dialog.Filename = "Isla Muelle soldier_dialog.c";
			LAi_SetGuardianType(characterFromID("Santiago_soldier_05"));
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 1.0);
		break;

		case "hostage_dead":
			DisableFastTravel(false);
			PChar.quest.kidnap_battle_over.over = "yes";
			PChar.quest.kidnap_what_next.over = "yes";
			Pchar.quest.kidnap_what_next2.over = "yes";
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;
			Locations[FindLocation("Cuba_shore_02")].reload.l2.disable = 0;
			characters[GetCharacterIndex("Santiago_soldier_05")].Dialog.Filename = "Isla Muelle soldier_dialog.c";
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 8);
			Preprocessor_Remove("name");
			CloseQuestHeader("Kidnap");
			DeleteQuestAttribute("ardent_kidnap");
			Pchar.quest.clear_hostage_body.win_condition.l1 = "ExitFromLocation";
			PChar.quest.clear_hostage_body.win_condition.l1.location = PChar.location;
			Pchar.quest.clear_hostage_body.win_condition = "clear_hostage_body";
		break;

		case "clear_hostage_body":
			ChangeCharacterAddress(romance, "None", "");
		break;

		case "ran_away":
			DisableFastTravel(false);
			PChar.quest.kidnap_battle_over.over = "yes";
			PChar.quest.kidnap_what_next.over = "yes";
			Pchar.quest.kidnap_what_next2.over = "yes";
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;
			Locations[FindLocation("Cuba_shore_02")].reload.l2.disable = 0;
			ChangeCharacterAddress(romance, "None", "");
			characters[GetCharacterIndex("Santiago_soldier_05")].Dialog.Filename = "Isla Muelle soldier_dialog.c";
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 5);
			Preprocessor_Remove("name");
			CloseQuestHeader("Kidnap");
			DeleteQuestAttribute("ardent_kidnap");
			PChar.quest.kidnap_hostage_dead.over = "yes";
		break;

		case "kidnap_what_next":
			PChar.quest.kidnap_what_next.over = "yes";
			Pchar.quest.kidnap_what_next2.over = "yes";
			DisableFastTravel(false);
			Characters[romanceidx].dialog.CurrentNode = "what_next";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"",30.0,30.0); // Exits to either "kidnap_prisoner" or "kidnap_guest"
		break;

		case "kidnap_guest":
//			romance.quest.officertype = OFFIC_TYPE_FIRSTMATE; // To put the guest into the captain's cabin so you can talk to her/him later
			AddPassenger(PChar, romance, 0);
			SetCharacterRemovable(romance, false);
			switch (GetCharacterShipCabin(PChar))
			{
				case "Cabin_none":
					ChangeCharacterAddressGroup(romance, "Tutorial_Deck", "goto", "goto2");
				break;
				case "Tutorial_Deck":
					ChangeCharacterAddressGroup(romance, "Tutorial_Deck", "goto", "goto2");
				break;
				// default
				ChangeCharacterAddressGroup(romance, "Tutorial_Deck", "reload", "reload1");
			}
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			Preprocessor_AddQuestData("pronoun", romance_pronoun2);
			AddQuestRecord("Kidnap", 6);
			Preprocessor_Remove("name");
			Preprocessor_Remove("pronoun");
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;
			Locations[FindLocation("Cuba_shore_02")].reload.l2.disable = 0;
			Locations[FindLocation("Cuba_shore_05")].reload.l2.disable = 0;
			Characters[romanceidx].dialog.CurrentNode = "no_escape";
			PChar.quest.ardent_kidnap.voyage_stage = 0;
			PChar.quest.voyage_stage1.win_condition.l1 = "Timer";
			PChar.quest.voyage_stage1.win_condition.l1.date.day = GetAddingDataDay(0, 0, 7);
			PChar.quest.voyage_stage1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 7);
			PChar.quest.voyage_stage1.win_condition.l1.date.year = GetAddingDataYear(0, 0, 7);
			PChar.quest.voyage_stage1.win_condition = "voyage_stage1";
			PChar.quest.voyage_stage2.win_condition.l1 = "Timer";
			PChar.quest.voyage_stage2.win_condition.l1.date.day = GetAddingDataDay(0, 0, 14);
			PChar.quest.voyage_stage2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
			PChar.quest.voyage_stage2.win_condition.l1.date.year = GetAddingDataYear(0, 0, 14);
			PChar.quest.voyage_stage2.win_condition = "voyage_stage2";
			PChar.quest.voyage_stage3.win_condition.l1 = "Timer";
			PChar.quest.voyage_stage3.win_condition.l1.date.day = GetAddingDataDay(0, 0, 21);
			PChar.quest.voyage_stage3.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 21);
			PChar.quest.voyage_stage3.win_condition.l1.date.year = GetAddingDataYear(0, 0, 21);
			PChar.quest.voyage_stage3.win_condition = "voyage_stage3";
		break;

		case "voyage_stage1":
			PChar.quest.ardent_kidnap.voyage_stage = 1;
		break;

		case "voyage_stage2":
			PChar.quest.ardent_kidnap.voyage_stage = 2;
		break;

		case "voyage_stage3":
			PChar.quest.ardent_kidnap.voyage_stage = 3;
		break;

		case "kidnap_prisoner":
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "ransom";
			LAi_SetStayType(characterFromID("Javier Balboa"));
//			LAi_ActorTurnToLocator(characterFromID("Javier Balboa"), "reload", "reload1");  // Governor will now wait until you ask him for ransom
			if (IsPassenger(romance))
			{
				SetCharacterRemovable(romance, true);
				RemovePassenger(PChar, romance);
			}
			AddPassenger(PChar, romance, 1);
			SetCharacterRemovable(romance, false);
			ChangeCharacterAddress(romance, "None", "");
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 7);
			Preprocessor_Remove("name");
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;
			Locations[FindLocation("Cuba_shore_02")].reload.l2.disable = 0;
			Locations[FindLocation("Cuba_shore_05")].reload.l2.disable = 0;
		break;

		case "governors_revenge":	// If you're stupid enough to go back to townhall without a ransom demand or other news, governor avenges his daughter / son.
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);

			LAi_SetHP(characterfromID("Javier Balboa"), 500.0, 500.0);
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 1;
			LAi_QuestDelay("governors_revenge2", 0.0);
		break;

		case "governors_revenge2":
			LAi_SetImmortal(CharacterFromID("Javier Balboa"), false);
			LAi_SetActorType(characterfromID("Javier Balboa"));
			LAi_ActorAttack(characterfromID("Javier Balboa"), PChar, "");
			LAi_group_MoveCharacter(characterFromID("Santiago_soldier_06"), "SPAIN_SOLDIERS");
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			PChar.quest.governor_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.governor_dead.win_condition.l1.character = "Javier Balboa";
			PChar.quest.governor_dead.win_condition = "governor_dead";
		break;

		case "governor_dead":
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_townhall")], true);
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 0;
			PChar.quest.town_battle.win_condition.l1 = "location";
			PChar.quest.town_battle.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.town_battle.win_condition = "raise_alarm";
		break;

		case "governors_revenge_fetch_romance":	// Triggered by dialog with "Javier Balboa" if you ransomed Lucía / Edmundo, rescued them from Downing dungeon, and don't have them as officer
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "revenge_failed_to_fetch";
			PChar.quest.governors_revenge_fetch_romance2.win_condition.l1 = "location";
			PChar.quest.governors_revenge_fetch_romance2.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.governors_revenge_fetch_romance2.win_condition = "governors_revenge_fetch_romance2";
		break;

		case "governors_revenge_fetch_romance2":
			PChar.quest.governors_revenge_fetch_romance3.win_condition.l1 = "location";
			PChar.quest.governors_revenge_fetch_romance3.win_condition.l1.location = "Santiago_townhall";
			PChar.quest.governors_revenge_fetch_romance3.win_condition = "governors_revenge_fetch_romance3";
		break;

		case "governors_revenge_fetch_romance3":
			if (isofficer(romance))
			{
				ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto2");
				if (CheckQuestAttribute("ardent_convoy", "battle_over")) Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "revenge_romance_with_you";
				else Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "kidnap_rescue_return";
				StartQuestMovie(true, true, false);
				DisableFastTravel(true);
				Pchar.quest.kidnap_rescue_reset_townhall_detector.over = "yes";
			}
		break;

		case "governors_revenge_romance_answers":
			Characters[romanceidx].dialog.CurrentNode = "governors_revenge_reply";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"governors_revenge_what_sort_revenge",5.0,5.0);	// Exits to "governors_revenge_what_sort_revenge"
		break;

		case "governors_revenge_what_sort_revenge":
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "revenge_what_sort_revenge";
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"governors_revenge_romance_explains",5.0,5.0);
		break;

		case "governors_revenge_romance_explains":
			Characters[romanceidx].dialog.CurrentNode = "governors_revenge_report_convoy_taken";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"governors_revenge_you_may_go",5.0,5.0);
		break;

		case "governors_revenge_you_may_go":
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "revenge_you_may_go";
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",5.0,5.0);	// Exits to "governors_revenge_leave_romance" or "governors_revenge_keep_romance"
		break;

		case "governors_revenge_leave_romance":
			RemoveOfficersIndex(pchar, romanceidx);
			RemovePassenger(pchar, romance);
			Pchar.quest.governors_revenge_remove_romance.win_condition.l1 = "ExitFromLocation";
			PChar.quest.governors_revenge_remove_romance.win_condition.l1.location = PChar.location;
			Pchar.quest.governors_revenge_remove_romance.win_condition = "governors_revenge_remove_romance";
			LAi_QuestDelay("governors_revenge_all_forgiven", 0.0);
		break;

		case "governors_revenge_remove_romance":
			LAi_SetActorType(romance);
			ChangeCharacterAddress(romance, "None", "");
		break;

		case "governors_revenge_keep_romance":
			Characters[romanceidx].dialog.CurrentNode = "governors_revenge_still_with_you";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"governors_revenge_keep_romance2",5.0,5.0);
		break;

		case "governors_revenge_keep_romance2":
			LAi_SetOfficerType(romance);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "revenge_romance_stays_with_you";
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"governors_revenge_all_forgiven",5.0,5.0);
		break;

		case "governors_revenge_all_forgiven":
			DisableFastTravel(false);
			EndQuestMovie();
			Pchar.quest.governors_revenge_reset_governor.win_condition.l1 = "ExitFromLocation";
			PChar.quest.governors_revenge_reset_governor.win_condition.l1.location = PChar.location;
			Pchar.quest.governors_revenge_reset_governor.win_condition = "reset_governor";
		break;

		case "raise_alarm":
			if (!LAi_IsDead(characterFromID("Grigorio Formoselle"))) LAi_QuestDelay("grigorio_appears", 5.0);
			else
			{
				Locations[FindLocation("Santiago_Town_01")].dangerous = true;
				Locations[FindLocation("Santiago_port")].dangerous = true;
			}
		break;

		case "grigorio_appears":
			ChangeCharacterAddressGroup(characterFromID("Grigorio Formoselle"), "Santiago_town_01", "reload", "reload4");
			LAi_QuestDelay("raise_alarm2", 1.0);
		break;

		case "raise_alarm2":
			LAi_SetActorType(characterFromID("Grigorio Formoselle"));
			Characters[GetCharacterIndex("Grigorio Formoselle")].dialog.CurrentNode = "alarm_governor_dead";
			LAi_ActorDialogNow(characterFromID("Grigorio Formoselle"),PChar,"raise_alarm3",1.0);
		break;

		case "raise_alarm3":
			ChangeCharacterReputation(PChar, -10);
			LAi_ActorRunToLocation(characterFromID("Grigorio Formoselle"), "reload", "reload4", "none", "", "", "grigorio_disappears", 5.0);
			SetRMRelation(PChar, SPAIN, REL_MIN);
			Locations[FindLocation("Santiago_Town_01")].dangerous = true;
			Locations[FindLocation("Santiago_port")].dangerous = true;
			iForceDetectionFalseFlag = 1;
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 1;
			LAi_QuestDelay("town_battle", 1.0);

			Pchar.quest.escape_to_sea.win_condition.l1 = "MapEnter";
			Pchar.quest.escape_to_sea.win_condition = "restore_flag_detection";
		break;

		case "grigorio_disappears":
			ChangeCharacterAddressGroup(characterFromID("Grigorio Formoselle"), "Santiago_townhall", "goto", "goto10");
		break;

		case "town_battle":
			LAi_group_MoveCharacter(characterFromID("Santiago_soldier_05"), "SPAIN_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Santiago_soldier_06"), "SPAIN_SOLDIERS");
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "restore_flag_detection":
			iForceDetectionFalseFlag = 0;
		break;

		case "ransom_rejected":
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_townhall")], false);
			Ambush("Soldiers", 8, "enemy", "friend", "reload1");
			PChar.quest.ransom_reject_escape.win_condition.l1 = "location";
			PChar.quest.ransom_reject_escape.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.ransom_reject_escape.win_condition = "ransom_reject_escape";
		break;

		case "ransom_reject_escape":
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 9);
			Preprocessor_Remove("name");
			CloseQuestHeader("Kidnap");
			DeleteQuestAttribute("ardent_kidnap");
			PChar.quest.kidnap_hostage_dead.over = "yes";
			ch = characterFromID("Javier Balboa");
			ch.skill.Fencing = "10";
			ch.skill.Accuracy = "5";
			ch.skill.Defence = "5";
			ch.perks.list.BasicDefence = true;
			ch.perks.list.AdvancedDefence = true;
			ch.perks.list.SwordplayProfessional = true;
			ch.perks.list.CriticalHit = true;
			Ch.Perks.list.Toughness = true;
			GiveItem2Character(characterfromID("Javier Balboa"), "bladeC23+2");
			GiveItem2Character(characterfromID("Javier Balboa"), "goldarmor");
			EquipCharacterByItem(characterfromID("Javier Balboa"),"bladeC23");
			EquipCharacterByItem(characterfromID("Javier Balboa"),"goldarmor");
			LAi_SetHP(characterfromID("Javier Balboa"), 500.0, 500.0);
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_townhall")], true);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "revenge";
			LAi_SetStayType(characterFromID("Javier Balboa"));
//			LAi_ActorTurnToLocator(characterFromID("Javier Balboa"), "reload", "reload1");
		break;

		case "ransom_accepted":
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 10);
			Preprocessor_Remove("name");
			Pchar.quest.ransom_accept_setup.win_condition.l1 = "Time";
			Pchar.quest.ransom_accept_setup.win_condition.l1.time = DAY_TIME_NIGHT;
			PChar.quest.ransom_accept_setup.win_condition = "ransom_accept_setup";
		break;

		case "ransom_accept_setup":
			ChangeCharacterAddressGroup(characterFromID("Grigorio Formoselle"), "Cuba_Shore_05", "goto", "citizen09");
			ChangeCharacterAddressGroup(characterFromID("Spanish_guard1"), "Cuba_Shore_05", "goto", "citizen05");
			ChangeCharacterAddressGroup(characterFromID("Spanish_guard2"), "Cuba_Shore_05", "goto", "citizen06");
			Characters[GetCharacterIndex("Grigorio Formoselle")].dialog.CurrentNode = "ransom_exchange";	// You will initiate dialog, which exits to "hostage_released"
			PChar.quest.ransom_accept_setup2.win_condition.l1 = "location";
			PChar.quest.ransom_accept_setup2.win_condition.l1.location = "Cuba_Shore_05";
			PChar.quest.ransom_accept_setup2.win_condition = "ransom_accept_setup2";
		break;

		case "ransom_accept_setup2":
			ChangeCharacterAddressGroup(romance, "Cuba_Shore_05", "goto", "locator28");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 5.0);
			LAi_SetActorType(characterfromID("Grigorio Formoselle"));
			LAi_SetActorType(characterfromID("Spanish_guard1"));
			LAi_SetActorType(characterfromID("Spanish_guard2"));
			LAi_ActorTurnToCharacter(characterfromID("Grigorio Formoselle"), Pchar);
			LAi_ActorTurnToCharacter(characterfromID("Spanish_guard1"), Pchar);
			LAi_ActorTurnToCharacter(characterfromID("Spanish_guard2"), Pchar);
			LAi_SetStayType(characterfromID("Grigorio Formoselle"));
			LAi_SetStayType(characterfromID("Spanish_guard1"));
			LAi_SetStayType(characterfromID("Spanish_guard2"));
		break;

		case "hostage_released":
			Characters[romanceidx].dialog.CurrentNode = "not_mistreated";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"hostage_released2",10.0,10.0);
		break;

		case "hostage_released2":
			RemovePassenger(PChar, romance);
			DeleteAttribute(romance, "prisoned");
			LAi_SetActorType(romance);
			LAi_ActorFollow(romance, characterFromID("Grigorio Formoselle"), "", 30.0);
			LAi_SetActorType(characterFromID("Grigorio Formoselle"));
			Characters[GetCharacterIndex("Grigorio Formoselle")].dialog.CurrentNode = "ransom_exchange5";
			LAi_ActorDialogNow(characterFromID("Grigorio Formoselle"),PChar,"kidnap_deal_done",1.0);
		break;

		case "kidnap_deal_done":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, sti(PChar.quest.ardent_kidnap.ransom));
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 11);
			Preprocessor_Remove("name");
			CloseQuestHeader("Kidnap");
//			DeleteQuestAttribute("ardent_kidnap");
			PChar.quest.ardent_kidnap.status = "deal_done";
			PChar.quest.kidnap_hostage_dead.over = "yes";
			LAi_SetActorType(characterFromID("Grigorio Formoselle"));
			LAi_SetActorType(characterFromID("Spanish_guard1"));
			LAi_SetActorType(characterFromID("Spanish_guard2"));
			LAi_SetActorType(romance);
			LAi_ActorGoToLocator(characterFromID("Grigorio Formoselle"), "reload", "reload2_back", "grigorio_leaves",60.0);
			LAi_ActorGoToLocator(characterFromID("Spanish_guard1"), "officers", "reload2_1", "",60.0);
			LAi_ActorGoToLocator(characterFromID("Spanish_guard2"), "officers", "reload2_2", "",60.0);
			LAi_ActorGoToLocator(romance, "officers", "reload2_3", "",60.0);
			ch = characterFromID("Javier Balboa");
			ch.skill.Fencing = "10";
			ch.skill.Accuracy = "5";
			ch.skill.Defence = "5";
			ch.perks.list.BasicDefence = true;
			ch.perks.list.AdvancedDefence = true;
			ch.perks.list.SwordplayProfessional = true;
			ch.perks.list.CriticalHit = true;
			Ch.Perks.list.Toughness = true;
//			GiveItem2Character(characterfromID("Javier Balboa"), "blade33+3");
//			GiveItem2Character(characterfromID("Javier Balboa"), "goldarmor");
//			EquipCharacterByItem(characterfromID("Javier Balboa"),"blade33");
			LAi_SetHP(characterfromID("Javier Balboa"), 500.0, 500.0);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "revenge";
			LAi_ActorTurnToLocator(characterFromID("Javier Balboa"), "reload", "reload1");
			LAi_SetStayType(characterFromID("Javier Balboa"));
			Pchar.quest.grigorio_leaves1.win_condition.l1 = "MapEnter";
			Pchar.quest.grigorio_leaves1.win_condition = "grigorio_leaves";
			Pchar.quest.grigorio_leaves2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.grigorio_leaves2.win_condition.l1.location = PChar.location;
			Pchar.quest.grigorio_leaves2.win_condition = "grigorio_leaves";
		break;

		case "grigorio_leaves":
			ChangeCharacterAddressGroup(characterFromID("Grigorio Formoselle"), "Santiago_townhall", "goto", "goto10");
			ChangeCharacterAddress(characterFromID("Spanish_guard1"), "None", "");
			ChangeCharacterAddress(characterFromID("Spanish_guard2"), "None", "");
			ChangeCharacterAddress(romance, "None", "");
			Pchar.quest.grigorio_leaves1.over = "yes";
			Pchar.quest.grigorio_leaves2.over = "yes";
			LAi_QuestDelay("grigorio_reset", 0.0);
		break;

		case "grigorio_reset":
			LAi_SetGuardianTypeNoGroup(characterFromID("Grigorio Formoselle"));
			Characters[GetCharacterIndex("Grigorio Formoselle")].dialog.CurrentNode = "First time";
		break;

		case "writing_letter":
			PChar.quest.letter_complete.win_condition.l1 = "Timer";
			PChar.quest.letter_complete.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
			PChar.quest.letter_complete.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.letter_complete.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.letter_complete.win_condition = "letter_complete";
		break;

		case "letter_complete":
			if(CheckAttribute(PChar, "quest.romance_model")) SetModelFromID(romance, PChar.quest.romance_model);
			Characters[romanceidx].dialog.CurrentNode = "letter_done";
		break;

		case "deliver_ExplainLetter":
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "hostage_free";
			GiveItem2Character(PChar, "ExplainLetter");
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			Preprocessor_AddQuestData("pronoun", romance_pronoun2);
			AddQuestRecord("Kidnap", 14);
			Preprocessor_Remove("name");
			Preprocessor_Remove("pronoun");
			PChar.quest.in_santiago_for_ExplainLetter.win_condition.l1 = "location";
			PChar.quest.in_santiago_for_ExplainLetter.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.in_santiago_for_ExplainLetter.win_condition = "in_santiago_for_ExplainLetter";
			ChangeCharacterAddress(characterFromID("Spanish_guard1"), "None", "");
			ChangeCharacterAddress(characterFromID("Spanish_guard2"), "None", "");
		break;

		case "in_santiago_for_ExplainLetter":
			if (isofficer(romance))
			{
				Characters[romanceidx].dialog.CurrentNode = "visit_father";
				LAi_SetActorType(romance);
				LAi_ActorDialog(romance,PChar,"in_santiago_for_ExplainLetter2",10.0,10.0);
			}
		break;

		case "in_santiago_for_ExplainLetter2":
			LAi_SetActorType(romance);
			LAi_ActorGoToLocator(romance, "reload", "reload1", "in_santiago_for_ExplainLetter3",10.0);
		break;

		case "in_santiago_for_ExplainLetter3":
			ChangeCharacterAddress(romance, "None", "");
			RemoveOfficersIndex(PChar, romanceidx);
		break;

		case "recruit_first_mate":
			romance.quest.officertype = OFFIC_TYPE_FIRSTMATE;
			LAi_QuestDelay("recruit_complete", 0.0);
		break;

		case "recruit_doctor":
			romance.quest.officertype = OFFIC_TYPE_DOCTOR;
			LAi_QuestDelay("recruit_complete", 0.0);
		break;

		case "recruit_quartermaster":	// was "recruit_carpenter", but excuse about fixing sails doesn't work with new perks
			romance.quest.officertype = OFFIC_TYPE_QMASTER;
			LAi_QuestDelay("recruit_complete", 0.0);
		break;

		case "recruit_complete":
			PChar.quest.abduction_sanjuan.over = "yes";
			DeleteQuestAttribute("bored_in_san_juan");
			SetOfficersIndex(Pchar, 3, romanceidx);
			SetCharacterRemovable(romance, true);
			Characters[romanceidx].officer = true;
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 12);
			Preprocessor_Remove("name");
			CloseQuestHeader("Kidnap");
			DeleteQuestAttribute("ardent_kidnap");
			PChar.quest.kidnap_hostage_dead.over = "yes";
			if (!CheckQuestAttribute("revenge_type", "kidnap_rescue") && (GetRMRelation(Pchar, SPAIN) > REL_WAR))
			{
				PChar.quest.betrayed_spain.win_condition.l1 = "relation";
				PChar.quest.betrayed_spain.win_condition.l1.relation = "Hostile";
				PChar.quest.betrayed_spain.win_condition.l1.nation = "Spain";
				PChar.quest.betrayed_spain.win_condition = "betrayed_spain";
			}
			if (PChar.sex == "man")
			{
				PChar.quest.lucia_new_outfit.win_condition.l1 = "party_goods";
				PChar.quest.lucia_new_outfit.win_condition.l1.goods = GOOD_SILK;
				PChar.quest.lucia_new_outfit.win_condition.l1.quantity = 1;
				PChar.quest.lucia_new_outfit.win_condition.l1.operation = ">=";
				PChar.quest.lucia_new_outfit.win_condition = "lucia_new_outfit";
			}

			if (!checkattribute(PChar, "quest.revenge_type"))
			{
				PChar.quest.abduction_officer_setup.win_condition.l1 = "Timer";
				PChar.quest.abduction_officer_setup.win_condition.l1.date.day = GetAddingDataDay(0, 0, 14);
				PChar.quest.abduction_officer_setup.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
				PChar.quest.abduction_officer_setup.win_condition.l1.date.year = GetAddingDataYear(0, 0, 14);
				PChar.quest.abduction_officer_setup.win_condition = "abduction_officer_setup";
			}
		break;

		case "abduction_officer_setup":
			PChar.quest.abduction_officer_santiago.win_condition.l1 = "location"; // Check for arrival at Santiago and related beaches
			PChar.quest.abduction_officer_santiago.win_condition.l1.location = "Santiago_port";
			PChar.quest.abduction_officer_santiago.win_condition = "abduction_officer_arrived";
			PChar.quest.abduction_officer_santiago_beach1.win_condition.l1 = "location";
			PChar.quest.abduction_officer_santiago_beach1.win_condition.l1.location = "Cuba_shore_02";
			PChar.quest.abduction_officer_santiago_beach1.win_condition = "abduction_officer_arrived";
			PChar.quest.abduction_officer_santiago_beach2.win_condition.l1 = "location";
			PChar.quest.abduction_officer_santiago_beach2.win_condition.l1.location = "Cuba_shore_05";
			PChar.quest.abduction_officer_santiago_beach2.win_condition = "abduction_officer_arrived";

			Locations[FindLocation("Cuba_port")].vcskip = true;	// Otherwise too many random people in Havana means Lucía / Edmundo can't spawn
			Locations[FindLocation("Cuba_shore_02")].vcskip = true;	// Otherwise Lucía / Edmundo strolls past random bandits at Bahia de Moa
			Locations[FindLocation("Muelle_shore")].vcskip = true;	// Ditto for Oyster Beach
			PChar.quest.abduction_officer_havana.win_condition.l1 = "location"; // Check for arrival at Havana and related beaches
			PChar.quest.abduction_officer_havana.win_condition.l1.location = "Cuba_port";
			PChar.quest.abduction_officer_havana.win_condition = "abduction_officer_arrived";
			PChar.quest.abduction_officer_havana_beach1.win_condition.l1 = "location";
			PChar.quest.abduction_officer_havana_beach1.win_condition.l1.location = "Cuba_shore_01";
			PChar.quest.abduction_officer_havana_beach1.win_condition = "abduction_officer_arrived";
			PChar.quest.abduction_officer_havana_beach2.win_condition.l1 = "location";
			PChar.quest.abduction_officer_havana_beach2.win_condition.l1.location = "Cuba_shore_03";
			PChar.quest.abduction_officer_havana_beach2.win_condition = "abduction_officer_arrived";
			PChar.quest.abduction_officer_havana_beach3.win_condition.l1 = "location";
			PChar.quest.abduction_officer_havana_beach3.win_condition.l1.location = "Cuba_shore_04";
			PChar.quest.abduction_officer_havana_beach3.win_condition = "abduction_officer_arrived";

			PChar.quest.abduction_officer_sanjuan.win_condition.l1 = "location"; // Check for arrival at San Juan and related beach
			PChar.quest.abduction_officer_sanjuan.win_condition.l1.location = "Muelle_port";
			PChar.quest.abduction_officer_sanjuan.win_condition = "abduction_officer_arrived";
			PChar.quest.abduction_officer_sanjuan_beach.win_condition.l1 = "location";
			PChar.quest.abduction_officer_sanjuan_beach.win_condition.l1.location = "Muelle_shore";
			PChar.quest.abduction_officer_sanjuan_beach.win_condition = "abduction_officer_arrived";

			PChar.quest.abduction_officer_santodomingo.win_condition.l1 = "location"; // Check for arrival at Santo Domingo and related beach
			PChar.quest.abduction_officer_santodomingo.win_condition.l1.location = "Santo_Domingo_port";
			PChar.quest.abduction_officer_santodomingo.win_condition = "abduction_officer_arrived";
			PChar.quest.abduction_officer_santodomingo_beach.win_condition.l1 = "location";
			PChar.quest.abduction_officer_santodomingo_beach.win_condition.l1.location = "Hispaniola_shore_01";
			PChar.quest.abduction_officer_santodomingo_beach.win_condition = "abduction_officer_arrived";
		break;

		case "release_guest":
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 13);
			Preprocessor_Remove("name");
//			LAi_SetActorType(romance);
//			LAi_ActorFollowEverywhere(romance, "", 1.0);
			PChar.quest.release_guest_port.win_condition.l1 = "location";
			PChar.quest.release_guest_port.win_condition.l1.location = "Muelle_port";
			PChar.quest.release_guest_port.win_condition = "release_guest_in_port";
			PChar.quest.release_guest_town.win_condition.l1 = "location";
			PChar.quest.release_guest_town.win_condition.l1.location = "Muelle_shore";
			PChar.quest.release_guest_town.win_condition = "release_guest_shore";
		break;

		case "release_guest_in_port":
			PChar.quest.release_guest_town.over = "yes";
			ChangeCharacterAddressGroup(romance, "Muelle_port", "goto", "goto8");
			LAi_QuestDelay("release_guest_in_town2", 1.0);
		break;

		case "release_guest_shore":
			PChar.quest.release_guest_port.over = "yes";
			ChangeCharacterAddressGroup(romance, "Muelle_shore", "goto", "goto12");
			LAi_QuestDelay("release_guest_shore2", 1.0);
		break;

		case "release_guest_shore2":
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 5.0);
			LAi_SetImmortal(romance, true);
			PChar.quest.release_guest_town.win_condition.l1 = "location";
			PChar.quest.release_guest_town.win_condition.l1.location = "Muelle_town_03";
			PChar.quest.release_guest_town.win_condition = "release_guest_in_town2";
		break;

		case "release_guest_in_town2":
			LAi_SetImmortal(romance, false);
			LAi_SetFightMode(PChar, false);
			Locations[FindLocation("Muelle_town_03")].reload.l1.disable = 1;
			Pchar.quest.released_back_to_sea.win_condition.l1 = "MapEnter";
			Pchar.quest.released_back_to_sea.win_condition = "released_back_to_sea";
			Characters[romanceidx].dialog.CurrentNode = "just_released";
			LAi_SetActorType(romance);
			LAi_ActorDialogNow(romance,PChar,"released_free1",1.0);
//			LAi_ActorDialog(romance,PChar,"released_free1",5.0,5.0);
		break;

		case "released_free1":
			Locations[FindLocation("Muelle_town_03")].reload.l1.disable = 0;
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 16);
			Preprocessor_Remove("name");
			CloseQuestHeader("Kidnap");
			DeleteQuestAttribute("ardent_kidnap");
			PChar.quest.kidnap_hostage_dead.over = "yes";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(PChar, "", 100);
				AddPartyExpChar(pchar, "Sneak", 100);
//				AddPartyExpChar(pchar, "Leadership", 1500);
//				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			ChangeCharacterReputation(PChar, 5);
			LAi_SetCitizenType(romance);
			Characters[romanceidx].dialog.CurrentNode = "First time";
			RemovePassenger(PChar, romance);
		break;

		case "released_back_to_sea":
			ChangeCharacterAddressGroup(romance, "Muelle_town_04", "goto", "goto11");
			LAi_SetCitizenType(CharacterFromId(characters[romanceidx].id));
			Characters[romanceidx].dialog.CurrentNode = "bored_in_san_juan";
			PChar.quest.abduction_sanjuan.win_condition.l1 = "Timer";
			PChar.quest.abduction_sanjuan.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.abduction_sanjuan.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.abduction_sanjuan.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.abduction_sanjuan.win_condition = "abduction_sanjuan";
		break;

		case "governor_relaxes":
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 15);
			Preprocessor_Remove("name");
			LAi_QuestDelay("reset_governor", 0.0);
		break;

		case "reset_governor":
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "First time";
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_townhall", "sit", "sit1");
			LAi_SetHuberType(characterFromID("Javier Balboa"));
		break;

		case "deliver_first_CourtingLetter":
			GiveItem2Character(PChar, "CourtingLetter");
			Characters[GetCharacterIndex("Grigorio Formoselle")].dialog.CurrentNode = "first_delivery";
			Characters[villainidx].dialog.CurrentNode = "CourtingLetter_not_yet";
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 20);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
		break;

		case "first_CourtingLetter_delivered":
			AddQuestRecord("Kidnap", 21);
			TakeItemFromCharacter(Pchar, "CourtingLetter");
			Characters[villainidx].dialog.CurrentNode = "first_letter_delivered";
		break;

		case "deliver_second_CourtingLetter":
			Locations[FindLocation("Quest_Santiago_Bedroom")].vcskip = true;
			GiveItem2Character(PChar, "CourtingLetter");
			GiveItem2Character(PChar, "SignetRing");
			Characters[GetCharacterIndex("Grigorio Formoselle")].dialog.CurrentNode = "second_delivery";
			Characters[villainidx].dialog.CurrentNode = "CourtingLetter_not_yet";
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(villain)));
			AddQuestRecord("Kidnap", 23);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			PChar.quest.signet_ring_known = "true";
		break;

		case "second_CourtingLetter_delivered":
			Characters[villainidx].dialog.CurrentNode = "First time";
			DoQuestReloadToLocation("Quest_Santiago_Bedroom", "reload", "reload1", "second_CourtingLetter_delivered2");
		break;

		case "second_CourtingLetter_delivered2":
			characters[romanceidx].dialog.CurrentNode = "second_CourtingLetter_delivered";
			Pchar.quest.kidnap_breakin.over = "yes"; // You don't need to break in, you've got into the bedroom with the letter
			Pchar.quest.seen_window.over = "yes";
		break;
// When the second letter is delivered, dialog will exit to "second_CourtingLetter_return_with_answer", "second_CourtingLetter_kidnap", or "second_CourtingLetter_bow_escape"

		case "second_CourtingLetter_return_with_answer":
			DoQuestReloadToLocation("Santiago_townhall", "reload", "reload2", "second_CourtingLetter_return_with_answer2");
		break;

		case "second_CourtingLetter_return_with_answer2":
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			AddQuestRecord("Kidnap", 24);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			Characters[villainidx].dialog.CurrentNode = "second_letter_delivered";
		break;

		case "second_CourtingLetter_kidnap":
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
			LAi_SetActorType(characterfromID("Javier Balboa"));
			if (checkquestattribute("ardent_kidnap.status", "cooperate"))
			{
				Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload1 = 5.0;
				Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload2 = 5.0;
				Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload3 = 5.0;
				Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload5 = 5.0;
			}
			DoQuestReloadToLocation("Santiago_townhall", "reload", "reload2", "kidnap_escape2");
		break;

// Most of the kidnap is identical to the night-time one except that the outside guard will behave differently
		case "kidnap_cooperate_day":
			Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "still_suspicious";
			LAi_ActorDialog(characterFromID("Santiago_soldier_05"),PChar,"shopping_for_ring",5.0,5.0);
		break;

		case "shopping_for_ring":
			LAi_SetActorType(characterFromID("Santiago_soldier_05"));
			LAi_ActorFollowEverywhere(characterFromID("Santiago_soldier_05"), "", 5.0);
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 5.0);

//			PChar.quest.Santiago_soldiers_fight_back.win_condition.l1 = "NPC_Death";
//			PChar.quest.Santiago_soldiers_fight_back.win_condition.l1.character = "Santiago_soldier_05";
//			PChar.quest.Santiago_soldiers_fight_back.win_condition = "soldiers_fight_back";
	       		LAi_SetCheckMinHP(characterFromID("Santiago_soldier_05"), LAi_GetCharacterHP(characterFromID("Santiago_soldier_05"))-1.0, false, "soldiers_fight_back");

			Locations[FindLocation("Santiago_town_01")].reload.l2.disable = 1;			// Guard will react if you go near the town exit,
			Locations[FindLocation("Santiago_town_01")].reload.l7.disable = 1; 			// the tavern,
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 1; 			// the town hall,
			Locations[FindLocation("Santiago_town_01")].reload.l5.disable = 1; 			// the church,
			Locations[FindLocation("Santiago_town_01")].reload.l1.disable = 1; 			// or initially the port.
			Pchar.quest.no_leave_town.win_condition.l1 = "locator";
			Pchar.quest.no_leave_town.win_condition.l1.location = "Santiago_town_01";
			Pchar.quest.no_leave_town.win_condition.l1.locator_group = "reload";
			Pchar.quest.no_leave_town.win_condition.l1.locator = "reload2";
			Pchar.quest.no_leave_town.win_condition = "not_that_way_to_ring";
			Pchar.quest.no_go_tavern.win_condition.l1 = "locator";
			Pchar.quest.no_go_tavern.win_condition.l1.location = "Santiago_town_01";
			Pchar.quest.no_go_tavern.win_condition.l1.locator_group = "reload";
			Pchar.quest.no_go_tavern.win_condition.l1.locator = "reload3";
			Pchar.quest.no_go_tavern.win_condition = "not_that_way_to_ring";
			Pchar.quest.no_go_townhall.win_condition.l1 = "locator";
			Pchar.quest.no_go_townhall.win_condition.l1.location = "Santiago_town_01";
			Pchar.quest.no_go_townhall.win_condition.l1.locator_group = "reload";
			Pchar.quest.no_go_townhall.win_condition.l1.locator = "reload4";
			Pchar.quest.no_go_townhall.win_condition = "not_that_way_to_ring";
			Pchar.quest.no_go_church.win_condition.l1 = "locator";
			Pchar.quest.no_go_church.win_condition.l1.location = "Santiago_town_01";
			Pchar.quest.no_go_church.win_condition.l1.locator_group = "reload";
			Pchar.quest.no_go_church.win_condition.l1.locator = "reload5";
			Pchar.quest.no_go_church.win_condition = "no_church_for_you";
			Pchar.quest.no_escape_to_port.win_condition.l1 = "locator";
			Pchar.quest.no_escape_to_port.win_condition.l1.location = "Santiago_town_01";
			Pchar.quest.no_escape_to_port.win_condition.l1.locator_group = "reload";
			Pchar.quest.no_escape_to_port.win_condition.l1.locator = "reload1";
			Pchar.quest.no_escape_to_port.win_condition = "no_escape_to_port";

			PChar.quest.in_store_for_ring.win_condition.l1 = "location";
			PChar.quest.in_store_for_ring.win_condition.l1.location = "Santiago_store";
			PChar.quest.in_store_for_ring.win_condition = "in_store_for_ring";

			Locations[FindLocation("Santiago_port")].locators_radius.goto.goto28 = 28.0;
			PChar.quest.kidnap_run_for_ship.win_condition.l1 = "locator";
			Pchar.quest.kidnap_run_for_ship.win_condition.l1.location = "Santiago_port";
			Pchar.quest.kidnap_run_for_ship.win_condition.l1.locator_group = "goto";
			Pchar.quest.kidnap_run_for_ship.win_condition.l1.locator = "goto28";
			PChar.quest.kidnap_run_for_ship.win_condition = "kidnap_run_for_ship";

			PChar.quest.santiago_reset.win_condition.l1 = "location";
			PChar.quest.santiago_reset.win_condition.l1.location = "Cuba";
			PChar.quest.santiago_reset.win_condition = "santiago_reset";
		break;

		case "soldiers_fight_back":
			if (!LAi_IsDead(characterFromID("Santiago_soldier_05"))) LAi_group_MoveCharacter(CharacterFromID("Santiago_soldier_05"), "SPAIN_SOLDIERS");
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "reset_after_fight");
			LAi_QuestDelay("santiago_reset2", 0.0);
		break;

		case "reset_after_fight":
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "not_that_way_to_ring":
			Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "wrong_way_to_ring";
			LAi_ActorDialog(characterFromID("Santiago_soldier_05"),PChar,"not_that_way_to_ring2",5.0,5.0);
		break;

		case "not_that_way_to_ring2":
			LAi_SetActorType(characterFromID("Santiago_soldier_05"));
			LAi_ActorFollowEverywhere(characterFromID("Santiago_soldier_05"), "", 5.0);
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "no_church_for_you":
			Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "no_church_for_you";
			LAi_ActorDialog(characterFromID("Santiago_soldier_05"),PChar,"not_that_way_to_ring2",5.0,5.0);
		break;

		case "no_escape_to_port":
			Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "no_escape_to_port";
			LAi_ActorDialog(characterFromID("Santiago_soldier_05"),PChar,"not_that_way_to_ring2",5.0,5.0);
		break;

		case "in_store_for_ring":
			PChar.quest.out_of_store_ring.win_condition.l1 = "location";
			PChar.quest.out_of_store_ring.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.out_of_store_ring.win_condition = "out_of_store_ring";
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload1 = 2.0;
			Locations[FindLocation("Santiago_town_01")].reload.l1.disable = 0;
			Pchar.quest.no_escape_to_port.over = "yes";
		break;

		case "out_of_store_ring":
			ChangeCharacterAddressGroup(romance, "Santiago_town_01", "goto", "goto20");
			Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "did_you_get_ring";
			LAi_ActorDialog(characterFromID("Santiago_soldier_05"),PChar,"out_of_store_ring2",25.0,25.0);
		break;

		case "out_of_store_ring2":
			LAi_SetActorType(characterFromID("Santiago_soldier_05"));
			LAi_ActorFollowEverywhere(characterFromID("Santiago_soldier_05"), "", 5.0);
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "kidnap_run_for_ship":
			Characters[romanceidx].dialog.CurrentNode = "run_for_ship";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"kidnap_run_for_ship2",15.0,15.0);
		break;

		case "kidnap_run_for_ship2":
			LAi_SetActorType(romance);
			if (PChar.location.from_sea == "Cuba_shore_02")
			{
				LAi_ActorRunToLocation(romance, "reload", "reload4", "Santiago_town_exit2", "goto", "citizen04", "", 90.0);
				PChar.quest.kidnap_gate_escape.win_condition.l1 = "location";
				PChar.quest.kidnap_gate_escape.win_condition.l1.location = "Santiago_town_exit2";
				PChar.quest.kidnap_gate_escape.win_condition = "kidnap_gate_escape";
			}
			else LAi_ActorRunToLocation(romance, "reload", "reload2_back", "Santiago_port", "", "", "", 90.0);
			LAi_ActorAttack(characterfromID("Santiago_soldier_05"), PChar, "");
		break;

		case "kidnap_gate_escape":
			if(!LAi_IsDead(romance))
			{
				ChangeCharacterAddressGroup(romance, "Santiago_town_exit2", "goto", "citizen04");
				LAi_SetActorType(romance);
				LAi_ActorFollowEverywhere(romance, "", 5.0);
			}
		break;

		case "santiago_reset":
			PChar.quest.Santiago_soldiers_fight_back.over = "yes";
			LAi_RemoveCheckMinHP(characterFromID("Santiago_soldier_05"));
			ChangeCharacterAddressGroup(characterfromID("Santiago_soldier_05"), "Santiago_town_01", "goto", "locator36");
			LAi_SetGuardianType(characterfromID("Santiago_soldier_05"));
			characters[GetCharacterIndex("Santiago_soldier_05")].Dialog.Filename = "Isla Muelle soldier_dialog.c";
			LAi_QuestDelay("santiago_reset2", 0.0);
		break;

		case "santiago_reset2":
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload2 = 2.0;
			Locations[FindLocation("Santiago_town_01")].reload.l2.disable = 0;
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload3 = 2.0;
			Locations[FindLocation("Santiago_town_01")].reload.l7.disable = 0;
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 0;
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload5 = 2.0;
			Locations[FindLocation("Santiago_town_01")].reload.l5.disable = 0;
			Locations[FindLocation("Santiago_port")].locators_radius.goto.goto28 = 1.0;
			Pchar.quest.no_leave_town.over = "yes";
			Pchar.quest.no_go_tavern.over = "yes";
			Pchar.quest.no_go_townhall.over = "yes";
			Pchar.quest.no_go_church.over = "yes";
			PChar.quest.in_store_for_ring.over = "yes";
		break;

		case "second_CourtingLetter_bow_escape":
			Pchar.quest.bow_escape_shoot_bow.win_condition.l1 = "Time";				// The rescue with bow and arrow requires:
			Pchar.quest.bow_escape_shoot_bow.win_condition.l1.time = DAY_TIME_NIGHT;		// night-time,
			Pchar.quest.bow_escape_shoot_bow.win_condition.l2 = "item";				// you have a bow
			PChar.quest.bow_escape_shoot_bow.win_condition.l2.character = Pchar.id;
			Pchar.quest.bow_escape_shoot_bow.win_condition.l2.item = "pistolbow";
			Pchar.quest.bow_escape_shoot_bow.win_condition.l3 = "item";				// and arrow,
			PChar.quest.bow_escape_shoot_bow.win_condition.l3.character = Pchar.id;
			Pchar.quest.bow_escape_shoot_bow.win_condition.l3.item = "bladearrows";
			Pchar.quest.bow_escape_shoot_bow.win_condition.l4 = "locator";				// and you're standing down the side street.
			Pchar.quest.bow_escape_shoot_bow.win_condition.l4.location = "Santiago_town_01";
			Pchar.quest.bow_escape_shoot_bow.win_condition.l4.locator_group = "goto";
			Pchar.quest.bow_escape_shoot_bow.win_condition.l4.locator = "goto10";
			PChar.quest.bow_escape_shoot_bow.win_condition = "bow_escape_shoot_bow";
			DoQuestReloadToLocation("Santiago_townhall", "reload", "reload2", "second_CourtingLetter_bow_escape2");
		break;

		case "second_CourtingLetter_bow_escape2":
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
/*
			if (PChar.sex == "man")
			{
				Preprocessor_AddQuestData("pronoun1", "she");
				Preprocessor_AddQuestData("pronoun2", "her");
			}
			else
			{
				Preprocessor_AddQuestData("pronoun1", "he");
				Preprocessor_AddQuestData("pronoun2", "him");
			}
*/
			Preprocessor_AddQuestData("pronoun1", romance_pronoun1);
			Preprocessor_AddQuestData("pronoun2", romance_pronoun2);
			AddQuestRecord("Kidnap", 26);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("pronoun1");
			Preprocessor_Remove("pronoun2");
		break;

		case "bow_escape_shoot_bow":
			Locations[FindLocation("Quest_Santiago_Bedroom")].vcskip = true;
			PChar.quest.old_blade = GetCharacterEquipByGroup(PChar, BLADE_ITEM_TYPE);
			PChar.quest.old_gun = GetCharacterEquipByGroup(PChar, GUN_ITEM_TYPE);
			EquipCharacterByItem(PChar,"pistolbow");
			EquipCharacterByItem(PChar,"bladearrows");
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "goto", "goto22");
			LAi_QuestDelay("bow_escape_shoot_bow2", 1.0);
		break;

		case "bow_escape_shoot_bow2":
			LAi_SetPlayerType(PChar);
			LAi_SetFightMode(PChar, true);
			LAi_QuestDelay("bow_escape_shoot_bow3", 1.0);
		break;

		case "bow_escape_shoot_bow3":
			PlaySound("OBJECTS\duel\bow.wav");
			TakeItemFromCharacter(Pchar, "bladearrows");
			Pchar.dialog.CurrentNode = "arrow_through_window";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "bow_escape_shoot_bow4");
		break;

		case "bow_escape_shoot_bow4":
			LAi_SetPlayerType(PChar);
			DoQuestReloadToLocation("Quest_Santiago_Bedroom", "goto", "goto6", "bow_escape_in_bedroom");
		break;

		case "bow_escape_in_bedroom":
			if (PChar.quest.old_blade != "") EquipCharacterByItem(PChar,PChar.quest.old_blade);
			if (PChar.quest.old_gun != "") EquipCharacterByItem(PChar,PChar.quest.old_gun);
			DeleteQuestAttribute("old_blade");
			DeleteQuestAttribute("old_gun");
			Characters[romanceidx].dialog.CurrentNode = "bow_rescue_climbed_in";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"bow_escape_out_of_bedroom",5.0,5.0);
		break;

		case "bow_escape_out_of_bedroom":
			ChangeCharacterAddressGroup(romance, "Santiago_town_01", "goto", "goto10");
			PChar.quest.romance_model = romance.model;
			if (GetAttribute(romance, "sex") == "man") SetModelfromArray(romance, GetModelIndex("AnimistEdmundo"));
			else SetModelfromArray(romance, GetModelIndex("AnimistLucia"));
			DoQuestReloadToLocation("Santiago_town_01", "goto", "goto22", "bow_escape_out_to_town");
		break;

		case "bow_escape_out_to_town":
			Characters[romanceidx].dialog.CurrentNode = "bow_rescue_outside_residence";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"",5.0,5.0);	// Exits to "bow_escape_now_to_port" or "bow_escape_now_to_shore" depending on ship location
		break;

		case "bow_escape_now_to_port":
			Locations[FindLocation("Santiago_port")].locators_radius.goto.goto28 = 28.0;
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			PChar.quest.bow_escape_in_port.win_condition.l1 = "location";
			PChar.quest.bow_escape_in_port.win_condition.l1.location = "Santiago_port";
			PChar.quest.bow_escape_in_port.win_condition = "bow_escape_in_port";
			Pchar.quest.kidnap_what_next.win_condition.l1 = "locator";
			Pchar.quest.kidnap_what_next.win_condition.l1.location = "Santiago_port";
			Pchar.quest.kidnap_what_next.win_condition.l1.locator_group = "reload";
			Pchar.quest.kidnap_what_next.win_condition.l1.locator = "reload2_back";
			Pchar.quest.kidnap_what_next.win_condition = "kidnap_what_next";
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 1;

			Pchar.quest.kidnap_what_next2.win_condition.l1 = "locator";
			Pchar.quest.kidnap_what_next2.win_condition.l1.location = "Cuba_shore_02";
			Pchar.quest.kidnap_what_next2.win_condition.l1.locator_group = "reload";
			Pchar.quest.kidnap_what_next2.win_condition.l1.locator = "boat";
			Pchar.quest.kidnap_what_next2.win_condition = "kidnap_what_next";
			Locations[FindLocation("Cuba_shore_02")].reload.l2.disable = 1;

			PChar.quest.kidnap_hostage_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.kidnap_hostage_dead.win_condition.l1.character = romance.id;
			PChar.quest.kidnap_hostage_dead.win_condition = "hostage_dead";
		break;

		case "bow_escape_in_port":
			Locations[FindLocation("Santiago_port")].reload.l1.disable = 1;
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			characters[GetCharacterIndex("Santiago_soldier_01")].Dialog.Filename = "guard_dialog.c";
			LAi_SetActorType(characterFromID("Santiago_soldier_01"));
			Characters[GetCharacterIndex("Santiago_soldier_01")].dialog.CurrentNode = "port_challenge";
			LAi_ActorDialogNow(characterFromID("Santiago_soldier_01"),PChar,"bow_escape_in_port2",1.0);
		break;

		case "bow_escape_in_port2":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "just_a_cabin_boy";
//			LAi_ActorDialog(romance,PChar,"bow_escape_in_port3",5.0,5.0);
			LAi_ActorDialogNow(romance,PChar,"bow_escape_in_port3",5.0);
		break;

		case "bow_escape_in_port3":
			LAi_SetActorType(characterFromID("Santiago_soldier_01"));
			Characters[GetCharacterIndex("Santiago_soldier_01")].dialog.CurrentNode = "cabin_boy";
			LAi_ActorDialogNow(characterFromID("Santiago_soldier_01"),PChar,"bow_escape_in_port4",1.0);
		break;

		case "bow_escape_in_port4":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "naughty_guard";
//			LAi_ActorDialog(romance,PChar,"bow_escape_in_port5",5.0,5.0);
			LAi_ActorDialogNow(romance,PChar,"bow_escape_in_port5",5.0);
		break;

		case "bow_escape_in_port5":
			LAi_SetActorType(characterFromID("Santiago_soldier_01"));
			Characters[GetCharacterIndex("Santiago_soldier_01")].dialog.CurrentNode = "guard_embarrassed";
			LAi_ActorDialogNow(characterFromID("Santiago_soldier_01"),PChar,"bow_escape_in_port6",1.0);
			Pchar.quest.bow_escape_run_for_ship.win_condition.l1 = "locator";
			Pchar.quest.bow_escape_run_for_ship.win_condition.l1.location = "Santiago_port";
			Pchar.quest.bow_escape_run_for_ship.win_condition.l1.locator_group = "goto";
			Pchar.quest.bow_escape_run_for_ship.win_condition.l1.locator = "goto28";
			PChar.quest.bow_escape_run_for_ship.win_condition = "bow_escape_run_for_ship";
		break;

		case "bow_escape_in_port6":
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			characters[GetCharacterIndex("Santiago_soldier_01")].Dialog.Filename = "Isla Muelle soldier_dialog.c";
			LAi_SetGuardianType(characterFromID("Santiago_soldier_01"));
			Locations[FindLocation("Santiago_port")].reload.l1.disable = 0;
		break;

		case "bow_escape_run_for_ship":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "board_before_he_remembers";
			LAi_ActorDialog(romance,PChar,"bow_escape_run_for_ship2",15.0,15.0);
		break;

		case "bow_escape_run_for_ship2":
			LAi_SetActorType(romance);
			if (PChar.location.from_sea == "Cuba_shore_02")
			{
				LAi_ActorRunToLocation(romance, "reload", "reload4", "Santiago_town_exit2", "goto", "citizen04", "", 90.0);
				PChar.quest.kidnap_gate_escape.win_condition.l1 = "location";
				PChar.quest.kidnap_gate_escape.win_condition.l1.location = "Santiago_town_exit2";
				PChar.quest.kidnap_gate_escape.win_condition = "kidnap_gate_escape";
			}
			else LAi_ActorRunToLocation(romance, "reload", "reload2_back", "Santiago_port", "", "", "", 90.0);
			LAi_SetActorType(characterFromID("Santiago_soldier_01"));
			LAi_ActorAttack(characterfromID("Santiago_soldier_01"), PChar, "");
	       		LAi_SetCheckMinHP(characterFromID("Santiago_soldier_01"), LAi_GetCharacterHP(characterFromID("Santiago_soldier_01"))-1.0, false, "soldiers_fight_back_port");
			PChar.quest.santiago_reset_port.win_condition.l1 = "location";
			PChar.quest.santiago_reset_port.win_condition.l1.location = "Cuba";
			PChar.quest.santiago_reset_port.win_condition = "santiago_reset_port";
		break;

		case "soldiers_fight_back_port":
			if (!LAi_IsDead(characterFromID("Santiago_soldier_01"))) LAi_group_MoveCharacter(CharacterFromID("Santiago_soldier_01"), "SPAIN_SOLDIERS");
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "santiago_reset_port":
			PChar.quest.soldiers_fight_back_port.over = "yes";
			LAi_RemoveCheckMinHP(characterFromID("Santiago_soldier_01"));
			ChangeCharacterAddressGroup(characterfromID("Santiago_soldier_01"), "Santiago_port", "goto", "goto23");
			LAi_SetGuardianType(characterfromID("Santiago_soldier_01"));
			Locations[FindLocation("Santiago_port")].locators_radius.goto.goto28 = 1.0;
			SetModelFromID(romance, PChar.quest.romance_model);
//			DeleteQuestAttribute("romance_model");
		break;

		case "bow_escape_now_to_shore":
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);

			Pchar.quest.kidnap_what_next.win_condition.l1 = "locator";
			Pchar.quest.kidnap_what_next.win_condition.l1.location = "Cuba_shore_05";
			Pchar.quest.kidnap_what_next.win_condition.l1.locator_group = "reload";
			Pchar.quest.kidnap_what_next.win_condition.l1.locator = "boat";
			Pchar.quest.kidnap_what_next.win_condition = "kidnap_what_next";
			Locations[FindLocation("Cuba_shore_05")].reload.l2.disable = 1;

			PChar.quest.kidnap_hostage_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.kidnap_hostage_dead.win_condition.l1.character = romance.id;
			PChar.quest.kidnap_hostage_dead.win_condition = "hostage_dead";
		break;

		case "abduction_move_to_prison":
			LAi_SetActorType(romance);
			ChangeCharacterAddressGroup(romance, "Quest_Cellar_Prison", "goto", "goto24");
			characters[romanceidx].married = MR_MARRIED;
			characters[romanceidx].married.id = characters[villainidx].id;
			characters[villainidx].married = MR_MARRIED;
			characters[villainidx].married.id = characters[romanceidx].id;
			ChangeCharacterAddress(villain, "None", "");
			DeleteQuestAttribute("betrayed_spain");
		break;

		case "abduction_sanjuan":
			LAi_SetLoginTime(characterfromID("Isidro Edinho"), 0.0, 24.0);
			PChar.quest.abduction_sanjuan_witness.win_condition.l1 = "location";
			PChar.quest.abduction_sanjuan_witness.win_condition.l1.location = "Muelle_town_04";
			PChar.quest.abduction_sanjuan_witness.win_condition = "abduction_sanjuan_witness";
			PChar.quest.revenge_type = "san_juan";
			LAi_QuestDelay("abduction_move_to_prison", 0.0);
		break;

		case "abduction_sanjuan_witness":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Muelle_town_04")], true);
			PChar.quest.abduction_status = "taken_from_sanjuan";
			ch = characterfromID("Isidro Edinho");
			StoreDialog(ch);
			ch.Dialog.Filename = "witness_dialog.c";
			ch.dialog.CurrentNode = "saw_sanjuan_abduction";
			LAi_SetActorType(ch);
			LAi_ActorDialog(ch,PChar,"abduction_sanjuan_witness_reset",120.0,120.0);
		break;

		case "abduction_sanjuan_witness_reset":
			LAi_LocationFightDisable(&Locations[FindLocation("Muelle_town_04")], false);
			DisableFastTravel(false);
			EndQuestMovie();
			ch = characterfromID("Isidro Edinho");
			RestoreDialog(ch);
			LAi_SetCitizenType(ch);
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			Preprocessor_AddQuestData("romance2", GetMyName(romance));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(romance)));
			SetQuestHeader("Abduction");
			AddQuestRecord("Abduction", 1);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("romance2");
			Preprocessor_Remove("romance");
		break;

		case "abduction_officer_arrived":
			PChar.quest.abduction_officer_santiago.over = "yes";
			PChar.quest.abduction_officer_santiago_beach1.over = "yes";
			PChar.quest.abduction_officer_santiago_beach2.over = "yes";
			PChar.quest.abduction_officer_havana.over = "yes";
			PChar.quest.abduction_officer_havana_beach1.over = "yes";
			PChar.quest.abduction_officer_havana_beach2.over = "yes";
			PChar.quest.abduction_officer_havana_beach3.over = "yes";
			PChar.quest.abduction_officer_sanjuan.over = "yes";
			PChar.quest.abduction_officer_sanjuan_beach.over = "yes";
			PChar.quest.abduction_officer_santodomingo.over = "yes";
			PChar.quest.abduction_officer_santodomingo_beach.over = "yes";
			PChar.quest.abduction_officer.return_site = GetCharacterShipLocation(PChar);
			bQuestDisableSeaEnter = true; // You're not going back to sea until the abduction has happened and you know about it
			switch(PChar.location)
			{
				case "Santiago_port": // Santiago
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "goto1";
					PChar.quest.abduction_officer.leave_locator = "reload1";
					PChar.quest.abduction_officer.tavernid = "Pedro Fructoso";
				break;

				case "Cuba_shore_02": // Bahia de Moa
					PChar.quest.abduction_officer.sailor_group = "officers";
					PChar.quest.abduction_officer.sailor_locator = "reload2_3";
					PChar.quest.abduction_officer.leave_locator = "reload1_back";
					PChar.quest.abduction_officer.tavernid = "Pedro Fructoso";
				break;

				case "Cuba_shore_05": // Playa de Sierra Maestra
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "locator12";
					PChar.quest.abduction_officer.leave_locator = "reload2_back";
					PChar.quest.abduction_officer.tavernid = "Pedro Fructoso";
				break;

				case "Cuba_port": // Havana
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "goto_34";
					PChar.quest.abduction_officer.leave_locator = "reload_2_city";
					PChar.quest.abduction_officer.tavernid = "Fadrique Castillo";
				break;

				case "Cuba_shore_01": // Bahia de San Antonio
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "locator22";
					PChar.quest.abduction_officer.leave_locator = "reload2_back";
					PChar.quest.abduction_officer.tavernid = "Fadrique Castillo";
				break;

				case "Cuba_shore_03": // Punta de Maisi
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "locator10";
					PChar.quest.abduction_officer.leave_locator = "reload2_back";
					PChar.quest.abduction_officer.tavernid = "Fadrique Castillo";
				break;

				case "Cuba_shore_04": // Playa de Sabana
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "locator11";
					PChar.quest.abduction_officer.leave_locator = "reload2_back";
					PChar.quest.abduction_officer.tavernid = "Fadrique Castillo";
				break;

				case "Muelle_port": // San Juan
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "goto8";
					PChar.quest.abduction_officer.leave_locator = "reload2";
					PChar.quest.abduction_officer.tavernid = "Claudio Burrieza";
				break;

				case "Muelle_shore": // Oyster Beach
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "goto12";
					PChar.quest.abduction_officer.leave_locator = "reload1_back";
					PChar.quest.abduction_officer.tavernid = "Claudio Burrieza";
				break;

				case "Santo_Domingo_port": // Santo Domingo
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "goto21";
					PChar.quest.abduction_officer.leave_locator = "reload4";
					PChar.quest.abduction_officer.tavernid = "Rodrigo Ramos";
				break;

				case "Hispaniola_shore_01": // Boca de Yuman
					PChar.quest.abduction_officer.sailor_group = "goto";
					PChar.quest.abduction_officer.sailor_locator = "goto7";
					PChar.quest.abduction_officer.leave_locator = "reload2_back";
					PChar.quest.abduction_officer.tavernid = "Rodrigo Ramos";
				break;
			}
			if(!isofficer(romance))	ChangeCharacterAddressGroup(romance, PChar.location, PChar.quest.abduction_officer.sailor_group, PChar.quest.abduction_officer.sailor_locator);
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "abduction_officer_request_leave";
			LAi_ActorDialog(romance,PChar,"abduction_officer_romance_leaves",5.0,5.0);
			Pchar.quest.abduction_officer_move_out.win_condition.l1 = "ExitFromLocation";
			PChar.quest.abduction_officer_move_out.win_condition.l1.location = PChar.location;
			Pchar.quest.abduction_officer_move_out.win_condition = "abduction_officer_move_out";
		break;

		case "abduction_officer_romance_leaves":
			DeleteAttribute(&Locations[FindLocation("Cuba_port")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cuba_shore_02")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Muelle_shore")],"vcskip");
			RemoveOfficersIndex(pchar, romanceidx);
			SetCharacterRemovable(romance, false);
			LAi_SetImmortal(romance, true);
            		LAi_ActorGoToLocation(romance, "reload", PChar.quest.abduction_officer.leave_locator, "None", "", "", "", 300.0);
			if(iscompanion(romance))
			{
				speaker = Get_Speaker();
				if(speaker == "")
				{
					PChar.quest.abduction_officer_replacement = "Emmett Dawson";
					LAi_QuestDelay("abduction_officer_replace_captain_romance", 0.0);
				}
				else
				{
					PChar.quest.abduction_officer_replacement = speaker;
					crewref = characterFromID(speaker);
					crewidx = GetCharacterIndex(speaker);
					StoreDialog(crewref);
					LAi_SetActorType(crewref);
					characters[crewidx].Dialog.Filename = "crew_dialog.c";
					Characters[crewidx].Dialog.CurrentNode = "abduction_officer_replace_romance";
					LAi_ActorDialog(crewref, PChar, "abduction_officer_replace_captain_romance", 5.0, 5.0);
				}
			}
		break;

		case "abduction_officer_replace_captain_romance":
			if (PChar.quest.abduction_officer_replacement != "Emmett Dawson")
			{
//				characters[GetCharacterIndex(PChar.quest.abduction_officer_replacement)].Dialog.Filename = PChar.quest.normal_dialog;
				RestoreDialog(characters[GetCharacterIndex(PChar.quest.abduction_officer_replacement)]);
				RemoveOfficersIndex(PChar, GetCharacterIndex(PChar.quest.abduction_officer_replacement));
				RemovePassenger(PChar, characterFromID(PChar.quest.abduction_officer_replacement));
			}
			Pchar.quest.abduction_officer_replace_captain_romance2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.abduction_officer_replace_captain_romance2.win_condition.l1.location = PChar.location;
			Pchar.quest.abduction_officer_replace_captain_romance2.win_condition = "abduction_officer_replace_captain_romance2";
		break;

		case "abduction_officer_replace_captain_romance2":
			RemoveCharacterCompanion(Pchar, romance);
			ExchangeCharacterShip(romance, characterFromID(PChar.quest.abduction_officer_replacement));
			SetCompanionIndex(PChar,-1, GetCharacterIndex(PChar.quest.abduction_officer_replacement));
			DeleteQuestAttribute("abduction_officer_replacement");
		break;

		case "abduction_officer_move_out":
			PChar.quest.abduction_officer_back_to_ship.win_condition.l1 = "location";
			PChar.quest.abduction_officer_back_to_ship.win_condition.l1.location = PChar.quest.abduction_officer.return_site;
			PChar.quest.abduction_officer_back_to_ship.win_condition = "abduction_officer_back_to_ship";
			SetCharacterRemovable(romance, true);
			RemovePassenger(pchar, romance);
			PChar.quest.revenge_type = "officer";
			LAi_QuestDelay("abduction_move_to_prison", 0.0);
		break;

		case "abduction_officer_back_to_ship":
			StartQuestMovie(true, true, false); // You can't leave this area until you've talked to the crewman
			DisableFastTravel(true);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", PChar.quest.abduction_officer.sailor_group, PChar.quest.abduction_officer.sailor_locator);
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_SetImmortal(sld, true);
			LAi_SetStayType(sld);
			sld.id = "temp_crewman";
			sld.Dialog.Filename = "crew_dialog.c";
			sld.dialog.CurrentNode = "abduction_romance_not_back";
		break;

		case "abduction_officer_return_town": // Triggered by dialog with sailor
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			if (PChar.sex == "man") Preprocessor_AddQuestData("pronoun", "she");
			else Preprocessor_AddQuestData("pronoun", "he");
			SetQuestHeader("AWOL");
			AddQuestRecord("AWOL", 1);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("romance");
			ch = characterfromID(PChar.quest.abduction_officer.tavernid);
			StoreDialog(ch);
			ch.Dialog.Filename = "witness_dialog.c";
			ch.dialog.CurrentNode = "abduction_tavern";
			DisableFastTravel(false); // Finished talking to crewman, so now you can leave
			EndQuestMovie();
			bQuestDisableSeaEnter = true;
		break;

		case "abduction_officer_tavern_reset": // Triggered by dialog with relevant tavern keeper
			ch = characterfromID(PChar.quest.abduction_officer.tavernid);
			RestoreDialog(ch);

			PChar.quest.abduction_status = "taken_from_ship";
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			if (PChar.sex == "man") Preprocessor_AddQuestData("pronoun", "she");
			else Preprocessor_AddQuestData("pronoun", "he");
			AddQuestRecord("AWOL", 2);
			CloseQuestHeader("AWOL");
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			if (PChar.sex == "man") Preprocessor_AddQuestData("pronoun", "she");
			else Preprocessor_AddQuestData("pronoun", "he");
			SetQuestHeader("Abduction");
			AddQuestRecord("Abduction", 21);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("romance");
			bQuestDisableSeaEnter = false;
		break;

		case "abduction_seen_governor":	// Triggered by dialog with "Javier Balboa"
			Preprocessor_AddQuestData("governor", GetMySimpleName(characterfromID("Javier Balboa")));
			if (checkquestattribute("background", "pirate"))
			{
				AddQuestRecord("Abduction", 2);
				ChangeCharacterAddressGroup(characterfromID("Garfield Leighton"), "Tortuga_Tavern", "goto", "goto6");
			    	LAi_group_MoveCharacter(characterfromID("Garfield Leighton"), "TORTUGA_CITIZENS");
			}
			else
			{
				AddQuestRecord("Abduction", 3);
				ChangeCharacterAddressGroup(characterfromID("Garfield Leighton"), "Smugglers_Tavern", "goto", "goto5");
			    	LAi_group_MoveCharacter(characterfromID("Garfield Leighton"), "SMUGGLERS_CITIZENS");
			}
			Characters[GetCharacterIndex("Garfield Leighton")].dialog.CurrentNode = "abduction_meeting";
			Preprocessor_Remove("governor");
			PChar.quest.abduction_status = "seen_governor";
			Locations[FindLocation("Redmond_Dungeon_2")].models.always.locators = "d02_l_GR";
			Locations[FindLocation("Redmond_Dungeon_2")].locators_radius.randitem.randitem2 = 0.01;
			Locations[FindLocation("Redmond_Dungeon_2")].items.randitem2 = "door_GR_d2";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.name = "reload2";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.go = "Quest_Cellar_Prison";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.emerge = "reload10";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.autoreload = "0";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.label = "Old Inquisition prison.";
			Locations[FindLocation("Redmond_Dungeon_2")].locators_radius.reload.reload2 = 2.5;
		break;

		case "abduction_guadeloupe_setup": // Triggered by dialog with Garfield Leighton
			ChangeCharacterAddressGroup(characterfromID("Wilfred Roscoe"), "PaP_prison", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("French_guard1"), "Guadeloupe_port", "soldiers", "soldier8");
			ChangeCharacterAddressGroup(characterfromID("French_guard2"), "Guadeloupe_port", "soldiers", "soldier9");
			characters[GetCharacterIndex("French_guard1")].Dialog.Filename = "guard_dialog.c";
			characters[GetCharacterIndex("French_guard2")].Dialog.Filename = "guard_dialog.c";
			Characters[GetCharacterIndex("French_guard1")].dialog.CurrentNode = "French_first_time";
			Characters[GetCharacterIndex("French_guard2")].dialog.CurrentNode = "French_first_time";
			Locations[FindLocation("Guadeloupe_Port")].reload.l14.disable = 1;	// Barracks door locked.

			PChar.quest.abduction_guadeloupe_arrival.win_condition.l1 = "location";
			PChar.quest.abduction_guadeloupe_arrival.win_condition.l1.location = "Guadeloupe_port";
			PChar.quest.abduction_guadeloupe_arrival.win_condition = "abduction_guadeloupe_arrival";

			Pchar.quest.abduction_guard_challenges.win_condition.l1 = "locator";
			Pchar.quest.abduction_guard_challenges.win_condition.l1.location = "Guadeloupe_port";
			Pchar.quest.abduction_guard_challenges.win_condition.l1.locator_group = "reload";
			Pchar.quest.abduction_guard_challenges.win_condition.l1.locator = "barracks";
			Pchar.quest.abduction_guard_challenges.win_condition = "abduction_guard_challenges";
		break;

		case "abduction_guadeloupe_arrival":
			Preprocessor_AddQuestData("pirate", GetMySimpleName(characterfromID("Wilfred Roscoe")));
			AddQuestRecord("Abduction", 7);
			Preprocessor_Remove("pirate");
			if (GetCharacterShipLocation(PChar) == "Guadeloupe_port")
			{
				speaker = Get_Speaker();
				if (speaker != "")
				{
					crewref = characterFromID(speaker);
					crewidx = GetCharacterIndex(speaker);
					StoreDialog(crewref);
					PChar.quest.move_ship_officer = speaker;
					LAi_SetActorType(crewref);
					characters[crewidx].Dialog.Filename = "crew_dialog.c";
					Characters[crewidx].Dialog.CurrentNode = "abduction_move_ship";
					LAi_ActorDialog(crewref, pchar, "abduction_move_ship", 5.0, 5.0);
				}
				else
				{
					Pchar.dialog.CurrentNode = "abduction_move_ship";
					LAi_SetActorType(PChar);
					LAi_ActorSelfDialog(PChar, "");
				}
			}
			PChar.quest.abduction_in_prison.win_condition.l1 = "location";
			PChar.quest.abduction_in_prison.win_condition.l1.location = "PaP_prison";
			PChar.quest.abduction_in_prison.win_condition = "abduction_in_prison";
		break;

		case "abduction_move_ship":
			RemoveOfficersIndex(PChar, GetCharacterIndex(PChar.quest.move_ship_officer));
			SetCharacterRemovable(characterfromID(PChar.quest.move_ship_officer), false);
			LAi_SetActorType(characterFromID(PChar.quest.move_ship_officer));
        		LAi_ActorGoToLocation(characterFromID(PChar.quest.move_ship_officer), "reload", "reload2_back", "none", "", "", "", 120.0);
			bQuestDisableSeaEnter = true;						// Prevent exiting to the sea.
			Locations[FindLocation("Guadeloupe_Port")].reload.l1.disable = 1;	// Lock the pier.
			DisableFastTravel(true);						// No teleporting to ship.
			Pchar.quest.abduction_move_ship2.win_condition.l1 = "ExitFromLocation";	// Actually move the ship when you're not looking.
			PChar.quest.abduction_move_ship2.win_condition.l1.location = PChar.location;
			Pchar.quest.abduction_move_ship2.win_condition = "abduction_move_ship2";
		break;

		case "abduction_move_ship2":
			bQuestDisableSeaEnter = false;
			Locations[FindLocation("Guadeloupe_Port")].reload.l1.disable = 0;
			DisableFastTravel(false);
			RestoreDialog(characterfromID(PChar.quest.move_ship_officer));
			SetCharacterRemovable(characterfromID(PChar.quest.move_ship_officer), true);
			DeleteQuestAttribute("move_ship_officer");
			SetCharacterShipLocation(PChar, "Guadeloupe_shore_01");
			PChar.location.from_sea = "Guadeloupe_shore_01";
		break;

		case "abduction_guard_challenges":
			LAi_SetActorType(characterfromID("French_guard1"));
			Characters[GetCharacterIndex("French_guard1")].dialog.CurrentNode = "abduction_challenge";
			LAi_ActorDialog(characterfromID("French_guard1"),PChar,"",5.0,5.0);
			// Exits to "abduction_fight_guards", "abduction_open_barracks_door" or just exits if you didn't fight, bribe or produce a pass
		break;

		case "abduction_fight_guards":
			StartQuestMovie(true, true, false);
			LAi_group_MoveCharacter(characterfromID("French_guard1"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("French_guard2"), "FRANCE_SOLDIERS");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "abduction_guards_defeated");
		break;

		case "abduction_guards_defeated":
			EndQuestMovie();
			Pchar.quest.abduction_remove_bodies.win_condition.l1 = "ExitFromLocation";
			PChar.quest.abduction_remove_bodies.win_condition.l1.location = PChar.location;
			Pchar.quest.abduction_remove_bodies.win_condition = "abduction_remove_bodies";
			LAi_QuestDelay("abduction_open_barracks_door", 1.0);
		break;

		case "abduction_remove_bodies":
			ChangeCharacterAddress(characterFromID("French_guard1"), "None", "");
			ChangeCharacterAddress(characterFromID("French_guard2"), "None", "");
		break;

		case "abduction_open_barracks_door":
			Locations[FindLocation("Guadeloupe_Port")].reload.l14.disable = 0;
			Locations[FindLocation("PaP_Arsenal")].reload.l1.disable = 0;
		break;

		case "abduction_reset_guards":	// Triggered by dialog with guard if you didn't fight, bribe or produce a pass
			if (!checkAttribute(PChar,"quest.abduction_need_pass"))
			{
				if (checkquestattribute("church_help", "Yedam") && !LAi_IsDead(characterFromID("Yedam Kinne")))
				{
					Characters[GetCharacterIndex("Yedam Kinne")].dialog.CurrentNode = "return_visit";
					AddQuestRecord("Abduction", 9);
				}
				else AddQuestRecord("Abduction", 8);
				PChar.quest.abduction_need_pass = "noted";
			}
			LAi_SetGuardianType(characterfromID("French_guard1"));
			LAi_SetGuardianType(characterfromID("French_guard2"));
			Characters[GetCharacterIndex("French_guard1")].dialog.CurrentNode = "abduction_entry_options";
			Characters[GetCharacterIndex("French_guard2")].dialog.CurrentNode = "abduction_entry_options";
		break;

		case "abduction_in_prison":
			iForceDetectionFalseFlag = 1;
			bQuestDisableSeaEnter = false;
			if (checkquestattribute("abduction_guard_status", "fakepass") || checkquestattribute("abduction_guard_status", "bribed"))
			{
				ChangeCharacterAddressGroup(characterfromID("French_guard1"), "PaP_Arsenal", "goto", "goto3");
				ChangeCharacterAddressGroup(characterfromID("French_guard2"), "PaP_Arsenal", "goto", "goto4");
				LAi_SetActorType(characterfromID("French_guard1"));
				LAi_ActorTurnToLocator(characterfromID("French_guard1"), "reload", "reload2");
				LAi_SetActorType(characterfromID("French_guard2"));
				LAi_ActorTurnToLocator(characterfromID("French_guard2"), "reload", "reload2");
			}
			Pchar.quest.abduction_free_pirate.win_condition.l1 = "locator";
			Pchar.quest.abduction_free_pirate.win_condition.l1.location = "PaP_prison";
			Pchar.quest.abduction_free_pirate.win_condition.l1.locator_group = "reload";
			Pchar.quest.abduction_free_pirate.win_condition.l1.locator = "reload12";
			Pchar.quest.abduction_free_pirate.win_condition = "abduction_free_pirate";

			Pchar.quest.abduction_reset_guadeloupe.win_condition.l1 = "MapEnter";
			Pchar.quest.abduction_reset_guadeloupe.win_condition = "abduction_reset_guadeloupe";
		break;

		case "abduction_free_pirate":
			pchar.quest.abduction_talk_to_pirate1.win_condition.l1 = "locator";
			pchar.quest.abduction_talk_to_pirate1.win_condition.l1.location = "PaP_prison";
			pchar.quest.abduction_talk_to_pirate1.win_condition.l1.locator_group = "reload";
			pchar.quest.abduction_talk_to_pirate1.win_condition.l1.locator = "reload12";
			pchar.quest.abduction_talk_to_pirate1.win_condition = "abduction_talk_to_pirate1";
		break;

		case "abduction_talk_to_pirate1":
			LAi_SetActorType(characterFromID("Wilfred Roscoe"));
			characters[GetCharacterIndex("Wilfred Roscoe")].dialog.filename = "Wilfred Roscoe_dialog.c";
			Characters[GetCharacterIndex("Wilfred Roscoe")].dialog.currentNode = "abduction_visit";
			LAi_ActorDialog(characterFromID("Wilfred Roscoe"),PChar,"abduction_fight_prison_guards",3.0,10.0);
//			LAi_ActorDialogNow(characterFromID("Wilfred Roscoe"),PChar,"abduction_fight_prison_guards",10.0);
		break;

		case "abduction_fight_prison_guards":
			LAi_LocationFightDisable(&Locations[FindLocation("PaP_prison")], false);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "abduction_free_pirate2");
		break;

		case "abduction_free_pirate2":
			Locations[FindLocation("PaP_prison")].vcskip = true;
			ChangeCharacterAddressGroup(characterfromID("Wilfred Roscoe"), "PaP_prison", "reload", "reload12");
			DoQuestReloadToLocation("PaP_prison", "reload", "reload11", "abduction_free_pirate3");
		break;

		case "abduction_free_pirate3":
			LAi_SetFightMode(PChar, false);
			LAi_SetActorType(characterFromID("Wilfred Roscoe"));
			Characters[GetCharacterIndex("Wilfred Roscoe")].dialog.currentNode = "abduction_out";
			LAi_ActorDialog(characterFromID("Wilfred Roscoe"),PChar,"abduction_pirate_changes_clothes",5.0,5.0);
		break;

		case "abduction_pirate_changes_clothes":
			LAi_SetImmortal(characterfromID("Wilfred Roscoe"), true);
			LAi_type_Actor_Reset(characterfromID("Wilfred Roscoe"));
			LAi_ActorFollowEverywhere(characterfromID("Wilfred Roscoe"), "", 5.0);
			AddPassenger(PChar, characterfromID("Wilfred Roscoe"), 0);
			SetCharacterRemovable(characterfromID("Wilfred Roscoe"), false);
			ch = characterfromID("Wilfred Roscoe");
			ch.quest.outfit = ch.model;
			SetModelfromArray(ch, GetModelIndex("Soldier_Fra2_17"));
			ChangeCharacterAddressGroup(characterfromID("Wilfred Roscoe"), "PaP_prison", "reload", "reload12");
			DoQuestReloadToLocation("PaP_prison", "reload", "reload11", "abduction_ready_to_escape");
		break;

		case "abduction_ready_to_escape":
			Preprocessor_AddQuestData("pirate", GetMySimpleName(characterfromID("Wilfred Roscoe")));
			AddQuestRecord("Abduction", 11);
			Preprocessor_Remove("pirate");

			Characters[GetCharacterIndex("Remy Gatien_gov")].dialog.currentNode = "ardent_abduction_return";	// Set trap if you return to governor
			Characters[GetCharacterIndex("Garfield Leighton")].dialog.currentNode = "abduction_rescue_done";	// Set Garfield Leighton to exchange information for Wilfred Roscoe

			PChar.quest.abduction_back_in_guardroom.win_condition.l1 = "location";
			PChar.quest.abduction_back_in_guardroom.win_condition.l1.location = "PaP_Arsenal";
			PChar.quest.abduction_back_in_guardroom.win_condition = "abduction_back_in_guardroom";

			if (PChar.quest.background == "pirate")
			{
				PChar.quest.abduction_arrive_tortuga.win_condition.l1 = "location";
				PChar.quest.abduction_arrive_tortuga.win_condition.l1.location = "Tortuga_port";
				PChar.quest.abduction_arrive_tortuga.win_condition = "abduction_arrive_tortuga";
				Locations[FindLocation("Tortuga_Port")].vcskip = true;
			}
			else
			{
				PChar.quest.abduction_arrive_saojorge.win_condition.l1 = "location";
				PChar.quest.abduction_arrive_saojorge.win_condition.l1.location = "Conceicao_port";
				PChar.quest.abduction_arrive_saojorge.win_condition = "abduction_arrive_saojorge";
				PChar.quest.abduction_arrive_leviathan.win_condition.l1 = "location";
				PChar.quest.abduction_arrive_leviathan.win_condition.l1.location = "Conceicao_shore_02";
				PChar.quest.abduction_arrive_leviathan.win_condition = "abduction_arrive_leviathan";
				PChar.quest.abduction_arrive_sunny.win_condition.l1 = "location";
				PChar.quest.abduction_arrive_sunny.win_condition.l1.location = "Conceicao_shore_01";
				PChar.quest.abduction_arrive_sunny.win_condition = "abduction_arrive_sunny";
			}
		break;

		case "abduction_back_in_guardroom":
			if (checkquestattribute("abduction_guard_status", "fakepass") || checkquestattribute("abduction_guard_status", "bribed"))
			{
				Locations[FindLocation("PaP_Arsenal")].reload.l1.disable = 1;
				if (checkquestattribute("abduction_guard_status", "bribed")) Characters[GetCharacterIndex("French_guard1")].dialog.currentNode = "abduction_demand_second_bribe";
				else Characters[GetCharacterIndex("French_guard1")].dialog.currentNode = "abduction_demand_fine";
				LAi_SetActorType(characterfromID("French_guard1"));
				LAi_ActorDialog(characterfromID("French_guard1"),PChar,"",5.0,5.0); // Exits to "abduction_fight_guards" or "abduction_open_barracks_door"
			}
			else
			{
				LAi_SetGuardianType(characterfromID("French_guard1"));
				PChar.quest.abduction_leave_guardroom.win_condition.l1 = "location";
				PChar.quest.abduction_leave_guardroom.win_condition.l1.location = "Guadeloupe_port";
				PChar.quest.abduction_leave_guardroom.win_condition = "abduction_exit_challenge";
			}
		break;

		case "abduction_exit_challenge":
			Characters[GetCharacterIndex("French_guard1")].dialog.currentNode = "abduction_exit_challenge";
			LAi_SetActorType(characterfromID("French_guard1"));
			LAi_ActorDialog(characterfromID("French_guard1"),PChar,"abduction_exit_challenge2",5.0,5.0);
		break;

		case "abduction_exit_challenge2":
			Characters[GetCharacterIndex("Wilfred Roscoe")].dialog.currentNode = "abduction_stand_straight";
			LAi_SetActorType(characterfromID("Wilfred Roscoe"));
			LAi_ActorDialog(characterfromID("Wilfred Roscoe"),PChar,"abduction_exit_challenge3",5.0,5.0);
		break;

		case "abduction_exit_challenge3":
			Characters[GetCharacterIndex("French_guard1")].dialog.currentNode = "abduction_apology";
			LAi_SetActorType(characterfromID("French_guard1"));
			LAi_ActorDialog(characterfromID("French_guard1"),PChar,"abduction_exit_challenge4",5.0,5.0);
		break;

		case "abduction_exit_challenge4":
			Characters[GetCharacterIndex("Wilfred Roscoe")].dialog.currentNode = "abduction_stay_at_posts";
			LAi_SetActorType(characterfromID("Wilfred Roscoe"));
			LAi_ActorDialog(characterfromID("Wilfred Roscoe"),PChar,"abduction_exit_challenge5",5.0,5.0);
		break;

		case "abduction_exit_challenge5":
			Characters[GetCharacterIndex("French_guard1")].dialog.currentNode = "abduction_check_prisoner";
			LAi_SetActorType(characterfromID("French_guard1"));
			LAi_ActorDialog(characterfromID("French_guard1"),PChar,"abduction_exit_challenge6",5.0,5.0);
		break;

		case "abduction_exit_challenge6":
			Characters[GetCharacterIndex("Wilfred Roscoe")].dialog.currentNode = "abduction_stay_at_posts2";
			LAi_SetActorType(characterfromID("Wilfred Roscoe"));
			LAi_ActorDialog(characterfromID("Wilfred Roscoe"),PChar,"abduction_exit_challenge_end",5.0,5.0);
		break;

		case "abduction_exit_challenge_end":
			LAi_SetGuardianType(characterfromID("French_guard1"));
			LAi_ActorFollowEverywhere(characterfromID("Wilfred Roscoe"), "", 5.0);
			characters[GetCharacterIndex("French_guard1")].Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
			characters[GetCharacterIndex("French_guard2")].Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
			Characters[GetCharacterIndex("French_guard1")].dialog.currentNode = "First time";
			Characters[GetCharacterIndex("French_guard2")].dialog.currentNode = "First time";
		break;

		case "abduction_governor_arrest": // Triggered by dialog with "Remy Gatien_gov" if you go to townhall after releasing prisoner
			LAi_LocationFightDisable(&Locations[FindLocation("PaP_townhall")], false);
			Ambush("Soldiers", 8, "enemy", "friend", "reload1");
			LAi_QuestDelay("abduction_arrested", 10.0);
		break;

		case "abduction_arrested":
			LAi_SetFightMode(PChar, false);
			PChar.quest.arresterid = "Guadeloupe_guard_1";
			ChangeCharacterAddressGroup(characterfromID(PChar.quest.arresterid), "PaP_prison", "officers", "reload1_1");
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
			DoQuestReloadToLocation("PaP_prison", "goto", "goto24", "hanging_day");
		break;

		case "abduction_reset_guadeloupe":
			iForceDetectionFalseFlag = 0;
			LAi_LocationFightDisable(&Locations[FindLocation("PaP_prison")], true);
			DeleteAttribute(&Locations[FindLocation("PaP_prison")],"vcskip");
			Characters[GetCharacterIndex("Remy Gatien_gov")].dialog.currentNode = "First time";
			characters[GetCharacterIndex("French_guard1")].Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
			characters[GetCharacterIndex("French_guard2")].Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
			Characters[GetCharacterIndex("French_guard1")].dialog.currentNode = "First time";
			Characters[GetCharacterIndex("French_guard2")].dialog.currentNode = "First time";

			DisableFastTravel(false);
			ch = characterfromID("Wilfred Roscoe");
			SetModelfromArray(ch, GetModelIndex(ch.quest.outfit));
			DeleteAttribute(ch, "quest.outfit");

			if (CheckCharacterItem(Pchar, "PrisonPass")) TakeItemFromCharacter(Pchar, "PrisonPass");	// We won't need these again, so clean them out of inventory
			if (CheckCharacterItem(Pchar, "FakePrisonPass")) TakeItemFromCharacter(Pchar, "FakePrisonPass");
		break;

		case "abduction_wait_for_pass": // Triggered by dialog with Yedam Kinne, choosing to buy good pass
			PChar.quest.abduction_pass_ready.win_condition.l1 = "Timer";
			PChar.quest.abduction_pass_ready.win_condition.l1.date.day = GetAddingDataDay(0, 0, 3);
			PChar.quest.abduction_pass_ready.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 3);
			PChar.quest.abduction_pass_ready.win_condition.l1.date.year = GetAddingDataYear(0, 0, 3);
			PChar.quest.abduction_pass_ready.win_condition = "abduction_pass_ready";
		break;

		case "abduction_pass_ready":
			logit(TranslateString("","Yedam Kinne should have finished with the pass by now."));
			Characters[GetCharacterIndex("Yedam Kinne")].dialog.CurrentNode = "ardent_abduction_good_pass2";
		break;

		case "abduction_arrive_tortuga":
			PlaceCharacter(characterFromID("Wilfred Roscoe"), "goto");
			LAi_SetActorType(characterFromID("Wilfred Roscoe"));
			LAi_ActorFollowEverywhere(characterfromID("Wilfred Roscoe"), "", 10.0);
			DeleteAttribute(&Locations[FindLocation("Tortuga_port")],"vcskip");
		break;

		case "abduction_arrive_saojorge":
			PChar.quest.abduction_arrive_leviathan.over = "yes";
			PChar.quest.abduction_arrive_sunny.over = "yes";
			PlaceCharacter(characterFromID("Wilfred Roscoe"), "goto");
			LAi_SetActorType(characterFromID("Wilfred Roscoe"));
			LAi_ActorFollowEverywhere(characterfromID("Wilfred Roscoe"), "", 10.0);
		break;

		case "abduction_arrive_leviathan":
			PChar.quest.abduction_arrive_sunny.over = "yes";
			PChar.quest.abduction_arrive_saojorge.over = "yes";
			PlaceCharacter(characterFromID("Wilfred Roscoe"), "goto");
			LAi_SetActorType(characterFromID("Wilfred Roscoe"));
			LAi_ActorFollowEverywhere(characterfromID("Wilfred Roscoe"), "", 10.0);
		break;

		case "abduction_arrive_sunny":
			PChar.quest.abduction_arrive_saojorge.over = "yes";
			PChar.quest.abduction_arrive_leviathan.over = "yes";
			PlaceCharacter(characterFromID("Wilfred Roscoe"), "goto");
			LAi_SetActorType(characterFromID("Wilfred Roscoe"));
			LAi_ActorFollowEverywhere(characterfromID("Wilfred Roscoe"), "", 10.0);
		break;

		case "abduction_roscoe_joins_leighton":	// Triggered by dialog with Garfield Leighton
			RemovePassenger(PChar, characterFromID("Wilfred Roscoe"));
//			LAi_ActorFollow(characterFromID("Wilfred Roscoe"), characterFromID("Garfield Leighton"), "", 5.0);
			LAi_SetCitizenType(characterFromID("Wilfred Roscoe"));
			PChar.quest.abduction_status = "pirate_rescued";
			Pchar.quest.abduction_remove_pirates.win_condition.l1 = "MapEnter";
			Pchar.quest.abduction_remove_pirates.win_condition = "abduction_remove_pirates";
		break;

		case "abduction_remove_pirates":
			ChangeCharacterAddress(characterFromID("Wilfred Roscoe"), "None", "");
			ChangeCharacterAddress(characterFromID("Garfield Leighton"), "None", "");
		break;

		case "abduction_port_royale_witness":	// Triggered by dialog with Gilbert Downing
			DisableFastTravel(true);
			PChar.quest.abduction_status = "in_villain_cell";
			ch = characterfromID("Robert Blewett");
			StoreDialog(ch);
			ch.Dialog.Filename = "witness_dialog.c";
			ch.dialog.CurrentNode = "port_royale_dungeon";
			ChangeCharacterAddressGroup(ch, "Redmond_town_03", "officers", "reload_3_2_3");
			Pchar.quest.abduction_port_royale_witness_speaks.win_condition.l1 = "ExitFromLocation";
			PChar.quest.abduction_port_royale_witness_speaks.win_condition.l1.location = PChar.location;
			Pchar.quest.abduction_port_royale_witness_speaks.win_condition = "abduction_port_royale_witness_speaks";
		break;

		case "abduction_port_royale_witness_speaks":
			LAi_SetActorType(characterfromID("Robert Blewett"));
			Characters[GetCharacterIndex("Robert Blewett")].dialog.CurrentNode = "port_royale_dungeon";
			LAi_ActorDialog(characterfromID("Robert Blewett"),PChar,"abduction_port_royale_witness_reset",60.0,60.0);
		break;

		case "abduction_port_royale_witness_reset":
			DisableFastTravel(false);
			ch = characterfromID("Robert Blewett");
			RestoreDialog(ch);
			LAi_SetCitizenType(ch);
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			SetQuestHeader("Abduction");
			AddQuestRecord("Abduction", 16);
			Preprocessor_Remove("villain");
			Preprocessor_Remove("romance");
			Pchar.quest.abduction_port_royale_witness_reset2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.abduction_port_royale_witness_reset2.win_condition.l1.location = PChar.location;
			Pchar.quest.abduction_port_royale_witness_reset2.win_condition = "abduction_port_royale_witness_reset2";

			pchar.quest.abduction_found_romance.win_condition.l1 = "locator";
			pchar.quest.abduction_found_romance.win_condition.l1.location = "Quest_Cellar_Prison";
			pchar.quest.abduction_found_romance.win_condition.l1.locator_group = "reload";
			pchar.quest.abduction_found_romance.win_condition.l1.locator = "reload12";
			pchar.quest.abduction_found_romance.win_condition = "abduction_found_romance";
		break;

		case "abduction_port_royale_witness_reset2":
			ChangeCharacterAddressGroup(characterfromID("Robert Blewett"), "Redmond_town_03", "goto", "cityzen03");
		break;

		case "abduction_found_romance":
			LAi_SetFightMode(PChar, false);
			DisableFastTravel(true);
			LAi_SetActorType(romance);
			if (CheckQuestAttribute("ardent_kidnap.status", "in_downing_prison")) Characters[romanceidx].dialog.CurrentNode = "kidnap_rescue_found_in_cell";
			else Characters[romanceidx].dialog.CurrentNode = "abduction_found_in_cell";
			LAi_ActorDialog(romance,PChar,"",5.0,5.0); // Exits to "abduction_release_romance" if you have lockpick, otherwise just exits
			Locations[FindLocation("Quest_Merchant_House")].reload.l2.name = "reload3";
			Locations[FindLocation("Quest_Merchant_House")].reload.l2.go = "Quest_Cellar_Prison";
			Locations[FindLocation("Quest_Merchant_House")].reload.l2.emerge = "reload1";
			Locations[FindLocation("Quest_Merchant_House")].reload.l2.autoreload = "0";
			Locations[FindLocation("Quest_Merchant_House")].reload.l2.label = "Old Inquisition prison.";
			locations[FindLocation("Quest_Merchant_House")].reload.l2.disable = 0;
		break;

		case "abduction_got_lockpick":
			pchar.quest.abduction_return_with_lockpick.win_condition.l1 = "locator";
			pchar.quest.abduction_return_with_lockpick.win_condition.l1.location = "Quest_Cellar_Prison";
			pchar.quest.abduction_return_with_lockpick.win_condition.l1.locator_group = "reload";
			pchar.quest.abduction_return_with_lockpick.win_condition.l1.locator = "reload12";
			pchar.quest.abduction_return_with_lockpick.win_condition = "abduction_return_with_lockpick";
		break;

		case "abduction_return_with_lockpick":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "abduction_return_with_lockpick";
			LAi_ActorDialog(romance,PChar,"abduction_release_romance",5.0,5.0);
		break;

		case "abduction_release_romance":
			PlaySound("PEOPLE\lockpick2.wav");
			ChangeCharacterAddressGroup(romance, "Quest_Cellar_Prison", "reload", "reload12");
			DoQuestReloadToLocation("Quest_Cellar_Prison", "reload", "reload11", "abduction_romance_free");
		break;

		case "abduction_romance_free":
			DeleteAttribute(characterFromID(PChar.quest.romance), "prisoned");
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "abduction_romance_free";
			LAi_ActorDialog(romance,PChar,"abduction_romance_free2",5.0,5.0);
		break;

		case "abduction_romance_free2":
			ChangeCharacterAddressGroup(CharacterFromID("Gilbert Downing"), "Quest_Merchant_House", "goto", "goto9");
			LAi_SetHuberStayType(CharacterFromID("Gilbert Downing"));
			LAi_SetActorType(romance);
            		LAi_ActorGoToLocation(romance, "reload", "reload1", "Quest_Merchant_House", "goto", "goto10", "", 30.0);
			Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "abduction_romance_released";
			pchar.quest.abduction_downing_house_with_romance.win_condition.l1 = "locator";
			pchar.quest.abduction_downing_house_with_romance.win_condition.l1.location = "Quest_Cellar_Prison";
			pchar.quest.abduction_downing_house_with_romance.win_condition.l1.locator_group = "reload";
			pchar.quest.abduction_downing_house_with_romance.win_condition.l1.locator = "reload1";
			pchar.quest.abduction_downing_house_with_romance.win_condition = "abduction_downing_house_with_romance";
		break;

		case "abduction_downing_house_with_romance":
			LAi_SetActorType(romance);
			ChangeCharacterAddressGroup(romance, "Quest_Merchant_House", "goto", "goto10");
		break;

		case "abduction_romance_confronts_merchant": // Triggered by dialog with Gilbert Downing
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "abduction_romance_confronts_merchant";
			LAi_ActorDialog(romance,PChar,"abduction_merchant_refuses_to_betray",5.0,5.0);
		break;

		case "abduction_merchant_refuses_to_betray":
			LAi_SetActorType(characterfromID("Gilbert Downing"));
			Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "abduction_merchant_refuses_to_betray";
			if (CheckQuestAttribute("ardent_kidnap.status", "in_downing_prison"))
			{
				Pchar.quest.kidnap_rescue_reset_merchant.win_condition.l1 = "ExitFromLocation";
				PChar.quest.kidnap_rescue_reset_merchant.win_condition.l1.location = PChar.location;
				Pchar.quest.kidnap_rescue_reset_merchant.win_condition = "abduction_reset_merchant";
				LAi_ActorDialog(characterfromID("Gilbert Downing"),PChar,"kidnap_rescue_romance_from_house",5.0,5.0);
			}
			else LAi_ActorDialog(characterfromID("Gilbert Downing"),PChar,"abduction_romance_suggests_church",5.0,5.0);
		break;

		case "abduction_romance_suggests_church":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "abduction_romance_suggests_church";
			LAi_ActorDialog(romance,PChar,"abduction_set_up_church",5.0,5.0);
			Pchar.quest.abduction_reset_merchant.win_condition.l1 = "ExitFromLocation";
			PChar.quest.abduction_reset_merchant.win_condition.l1.location = PChar.location;
			Pchar.quest.abduction_reset_merchant.win_condition = "abduction_reset_merchant";

			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
			LAi_SetStayType(characterfromID("Javier Balboa"));
			Pchar.quest.abduction_back_home.win_condition.l1 = "location";
			PChar.quest.abduction_back_home.win_condition.l1.character = Pchar.id;
			Pchar.quest.abduction_back_home.win_condition.l1.location = "Santiago_townhall";
			Pchar.quest.abduction_back_home.win_condition = "abduction_back_home";
		break;

		case "abduction_reset_merchant":
			ChangeCharacterAddressGroup(CharacterFromID("Gilbert Downing"), "Quest_Merchant_House", "sit", "sit1");
			LAi_SetHuberType(CharacterFromID("Gilbert Downing"));
			Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "hostile";
			DisableFastTravel(false);
		break;

		case "abduction_set_up_church":
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounObj(romance)));
			AddQuestRecord("Abduction", 18);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("villain");
			Preprocessor_Remove("romance");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			LAi_SetImmortal(romance, true);
//			AddPassenger(PChar, romance, 0);
			SetCharacterRemovable(romance, false);
			PChar.quest.abduction_status = "go_to_church";
		break;

		case "abduction_confession_interlude":
			StartQuestMovie(true, true, false);
			LAi_SetActorType(characterfromID("Father Bernard"));
            		LAi_ActorGoToLocation(characterfromID("Father Bernard"), "reload", "reload2", "None", "", "", "abduction_confession_interlude2", 30.0);
			LAi_SetActorType(romance);
            		LAi_ActorGoToLocation(romance, "reload", "reload2", "None", "", "", "", 30.0);
		break;

		case "abduction_confession_interlude2":
			LAi_QuestDelay("abduction_confession_interlude3", 10.0);
		break;

		case "abduction_confession_interlude3":
			ChangeCharacterAddressGroup(characterfromID("Father Bernard"), "Redmond_church", "reload", "reload2");
			ChangeCharacterAddressGroup(romance, "Redmond_church", "reload", "reload2");
			LAi_QuestDelay("abduction_confession_interlude4", 1.0);
		break;

		case "abduction_confession_interlude4":
			LAi_SetActorType(characterfromID("Father Bernard"));
			LAi_SetActorType(romance);
			LAi_ActorGoToLocator(characterfromID("Father Bernard"), "goto", "goto11", "abduction_confession_interlude5",30.0);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "abduction_confession_interlude5":
			ChangeCharacterAddressGroup(characterfromID("Father Bernard"), "Redmond_church", "goto", "goto11");
			LAi_SetPriestType(characterfromID("Father Bernard"));
			Characters[GetCharacterIndex("Father Bernard")].dialog.CurrentNode = "ardent_abduction_story_checks_out";
		break;

		case "abduction_romance_will_pay":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "abduction_romance_will_pay_church";
			LAi_ActorDialog(romance,PChar,"abduction_romance_will_pay2",5.0,5.0);
		break;

		case "abduction_romance_will_pay2":
			LAi_SetActorType(characterfromID("Father Bernard"));
			Characters[GetCharacterIndex("Father Bernard")].dialog.CurrentNode = "ardent_abduction_write_to_rome";
			LAi_ActorDialog(characterfromID("Father Bernard"),PChar,"abduction_finished_with_church",5.0,5.0);
		break;

		case "abduction_finished_with_church":
			LAi_SetPriestType(characterfromID("Father Bernard"));
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			PChar.quest.abduction_status = "been_to_church";
			AddQuestRecord("Abduction", 19);
			EndQuestMovie();
			Characters[romanceidx].married.annulled = "pending";
		break;

		case "abduction_back_home":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto6", "abduction_back_home2", 65.0);
		break;

		case "abduction_back_home2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "abduction_return";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"abduction_romance_accuses",5.0,5.0);
		break;

		case "abduction_romance_accuses":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "abduction_accuse_abductor";
			LAi_ActorDialog(romance,PChar,"abduction_governor_outraged",5.0,5.0);
		break;

		case "abduction_governor_outraged":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "abduction_outrage";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"abduction_romance_revenge",1.0,1.0);
		break;

		case "abduction_romance_revenge":
			Preprocessor_AddQuestData("romance", GetMyFullName(romance));
			Preprocessor_AddQuestData("villain", GetMyFullName(villain));
			AddQuestRecord("Abduction", 20);
			CloseQuestHeader("Abduction");
			DeleteQuestAttribute("abduction_officer");
			DeleteQuestAttribute("abduction_guard_status");
			Preprocessor_Remove("villain");
			Preprocessor_Remove("romance");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(PChar, "", 100);
				AddPartyExpChar(pchar, "Sneak", 100);
			}
			else {AddPartyExp(pchar, 1200);}
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "abduction_revenge_plan";
			LAi_ActorDialog(romance,PChar,"convoy_governor_issues_letter",1.0,1.0);
			Pchar.quest.abduction_reset_governor.win_condition.l1 = "ExitFromLocation";
			PChar.quest.abduction_reset_governor.win_condition.l1.location = PChar.location;
			Pchar.quest.abduction_reset_governor.win_condition = "reset_governor";
		break;

		case "kidnap_rescue_goto_Downing_House": // Triggered by dialog with Charles Windem
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			SetQuestHeader("Dungeon");
			AddQuestRecord("Dungeon", 1);
			Preprocessor_Remove("villain");
			Preprocessor_Remove("romance");
			Locations[FindLocation("Redmond_town_03")].reload.l9.disable = 0; // Re-open house of Gilbert Downing
			Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "kidnap_rescue_buy_wine";
			LAi_QuestDelay("abduction_move_to_prison", 0.0);
		break;

		case "kidnap_rescue_setup_witness": // Triggered by dialog with Gilbert Downing
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			AddQuestRecord("Dungeon", 2);
			Preprocessor_Remove("villain");
			DisableFastTravel(true);
			ch = characterfromID("Robert Blewett");
			StoreDialog(ch);
			ch.Dialog.Filename = "witness_dialog.c";
			ChangeCharacterAddressGroup(ch, "Redmond_town_03", "officers", "reload_3_2_3");
			Pchar.quest.kidnap_rescue_port_royale_witness_speaks.win_condition.l1 = "location";
			PChar.quest.kidnap_rescue_port_royale_witness_speaks.win_condition.l1.location = "Redmond_town_03";
			Pchar.quest.kidnap_rescue_port_royale_witness_speaks.win_condition = "kidnap_rescue_port_royale_witness_speaks";
		break;

		case "kidnap_rescue_port_royale_witness_speaks":
			Locations[FindLocation("Redmond_Dungeon_2")].models.always.locators = "d02_l_GR";
			Locations[FindLocation("Redmond_Dungeon_2")].locators_radius.randitem.randitem2 = 0.01;
			Locations[FindLocation("Redmond_Dungeon_2")].items.randitem2 = "door_GR_d2";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.name = "reload2";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.go = "Quest_Cellar_Prison";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.emerge = "reload10";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.autoreload = "0";
			Locations[FindLocation("Redmond_Dungeon_2")].reload.l2.label = "Old Inquisition prison.";
			Locations[FindLocation("Redmond_Dungeon_2")].locators_radius.reload.reload2 = 2.5;

			LAi_SetActorType(characterfromID("Robert Blewett"));
			Characters[GetCharacterIndex("Robert Blewett")].dialog.CurrentNode = "port_royale_dungeon";
			LAi_ActorDialog(characterfromID("Robert Blewett"),PChar,"kidnap_rescue_port_royale_witness_reset",60.0,60.0);
		break;

		case "kidnap_rescue_port_royale_witness_reset":
			DisableFastTravel(false);
			ch = characterfromID("Robert Blewett");
			RestoreDialog(ch);
			LAi_SetCitizenType(ch);
			Preprocessor_AddQuestData("villain", GetMyLastName(villain));
			AddQuestRecord("Dungeon", 3);
			Preprocessor_Remove("villain");

			PChar.quest.ardent_kidnap.status = "in_downing_prison";
			Pchar.quest.kidnap_rescue_port_royale_witness_reset2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.kidnap_rescue_port_royale_witness_reset2.win_condition.l1.location = PChar.location;
			Pchar.quest.kidnap_rescue_port_royale_witness_reset2.win_condition = "abduction_port_royale_witness_reset2";

			pchar.quest.kidnap_rescue_found_romance.win_condition.l1 = "locator";
			pchar.quest.kidnap_rescue_found_romance.win_condition.l1.location = "Quest_Cellar_Prison";
			pchar.quest.kidnap_rescue_found_romance.win_condition.l1.locator_group = "reload";
			pchar.quest.kidnap_rescue_found_romance.win_condition.l1.locator = "reload12";
			pchar.quest.kidnap_rescue_found_romance.win_condition = "abduction_found_romance";
		break;

		case "kidnap_rescue_romance_from_house":
			DisableFastTravel(true);
			PChar.quest.revenge_type = "kidnap_rescue";
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			Pchar.quest.kidnap_rescue_leave_house.win_condition.l1 = "ExitFromLocation";
			PChar.quest.kidnap_rescue_leave_house.win_condition.l1.location = PChar.location;
			Pchar.quest.kidnap_rescue_leave_house.win_condition = "kidnap_rescue_leave_house";
		break;

		case "kidnap_rescue_leave_house":
			StartQuestMovie(true, true, false);
			LAi_QuestDelay("kidnap_rescue_propose_convoy", 0.0);
		break;

		case "kidnap_rescue_propose_convoy":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "kidnap_rescue_propose_convoy1";
			LAi_ActorDialog(romance,PChar,"kidnap_rescue_propose_convoy_finished",10.0,10.0);
			PChar.quest.kidnap_rescue_return_santiago_townhall.win_condition.l1 = "location";
			PChar.quest.kidnap_rescue_return_santiago_townhall.win_condition.l1.location = "Santiago_townhall";
			PChar.quest.kidnap_rescue_return_santiago_townhall.win_condition = "kidnap_rescue_return_santiago_townhall";
		break;

		case "kidnap_rescue_propose_convoy_finished":
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_QuestDelay("convoy_setup", 0.0);
		break;

		case "kidnap_rescue_return_santiago_townhall":
			if (isofficer(romance))
			{
				ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto2");
			}
			else
			{
				Pchar.quest.kidnap_rescue_reset_townhall_detector.win_condition.l1 = "ExitFromLocation";
				PChar.quest.kidnap_rescue_reset_townhall_detector.win_condition.l1.location = PChar.location;
				Pchar.quest.kidnap_rescue_reset_townhall_detector.win_condition = "kidnap_rescue_reset_townhall_detector";
			}
		break;

		case "kidnap_rescue_reset_townhall_detector":
			DeleteQuestAttribute("kidnap_rescue_return_santiago_townhall");
			PChar.quest.kidnap_rescue_return_santiago_townhall.win_condition.l1 = "location";
			PChar.quest.kidnap_rescue_return_santiago_townhall.win_condition.l1.location = "Santiago_townhall";
			PChar.quest.kidnap_rescue_return_santiago_townhall.win_condition = "kidnap_rescue_return_santiago_townhall";
		break;

		case "kidnap_rescue_romance_to_governor1":	// Triggered by dialog with "Javier Balboa"
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "kidnap_rescue_report1";
			LAi_ActorDialog(romance,PChar,"kidnap_rescue_governor_to_romance1",10.0,10.0);
		break;

		case "kidnap_rescue_governor_to_romance1":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "kidnap_rescue_received_letter";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"kidnap_rescue_romance_to_governor2",1.0,1.0);
		break;

		case "kidnap_rescue_romance_to_governor2":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "kidnap_rescue_who_do_you_believe";
			LAi_ActorDialog(romance,PChar,"kidnap_rescue_governor_to_romance2",5.0,5.0);
		break;

		case "kidnap_rescue_governor_to_romance2":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "kidnap_rescue_believe_you";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"kidnap_rescue_romance_says_convoy",1.0,1.0);
		break;

		case "kidnap_rescue_romance_says_convoy":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "kidnap_rescue_already_in_hand";
			LAi_ActorDialog(romance,PChar,"kidnap_rescue_governor_proposes_deal",5.0,5.0);
		break;

		case "kidnap_rescue_governor_proposes_deal":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "kidnap_rescue_propose_deal";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"kidnap_rescue_deal_agreed",1.0,1.0);
		break;

		case "kidnap_rescue_deal_agreed":
			LAi_SetHuberStayType(CharacterFromID("Javier Balboa"));
			LAi_SetOfficerType(romance);
			SetRank(PChar, SPAIN, GetOldRank(PChar, SPAIN));
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Convoy Strike", 21);
			Preprocessor_Remove("governor");
			Preprocessor_Remove("villain");
//			PChar.quest.kidnap_convoy = "true";
			PChar.quest.revenge_type = "kidnap_rescue_convoy_agreed";

			PChar.quest.convoy_romance_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.convoy_romance_dead.win_condition.l1.character = romance.id;
			PChar.quest.convoy_romance_dead.win_condition = "convoy_romance_dead";

			if(!CheckAttribute(PChar, "quest.betrayed_spain"))
			{
				PChar.quest.betrayed_spain.win_condition.l1 = "relation";
				PChar.quest.betrayed_spain.win_condition.l1.relation = "Hostile";
				PChar.quest.betrayed_spain.win_condition.l1.nation = "Spain";
				PChar.quest.betrayed_spain.win_condition = "betrayed_spain";
			}
		break;

		case "marriage_proposal_accepted":
			PChar.quest.in_santiago_for_ExplainLetter.over = "yes";
			PChar.quest.abduction_sanjuan.over = "yes";
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			AddPassenger(PChar, romance, 0);
			SetCharacterRemovable(romance, false);
			LAi_SetImmortal(romance, true);
			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
			LAi_SetStayType(characterfromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "marriage_request"; // Go to Santiago town hall and talk to the governor to continue.
			PChar.quest.marriage_arrive_port.win_condition.l1 = "location"; 		// LAi_ActorFollowEverywhere doesn't make the actor follow to next island,
			PChar.quest.marriage_arrive_port.win_condition.l1.location = "Santiago_port";	// so these cases check for arrival at all landing points from where you
			PChar.quest.marriage_arrive_port.win_condition = "marriage_arrive_port";	// can walk to Santiago and put your companion on a suitable locator.
			PChar.quest.marriage_arrive_moa.win_condition.l1 = "location";
			PChar.quest.marriage_arrive_moa.win_condition.l1.location = "Cuba_shore_02";
			PChar.quest.marriage_arrive_moa.win_condition = "marriage_arrive_moa";
			PChar.quest.marriage_arrive_maestra.win_condition.l1 = "location";
			PChar.quest.marriage_arrive_maestra.win_condition.l1.location = "Cuba_shore_05";
			PChar.quest.marriage_arrive_maestra.win_condition = "marriage_arrive_maestra";
			PChar.quest.betrayed_spain1.win_condition.l1 = "relation";
			PChar.quest.betrayed_spain1.win_condition.l1.relation = "Hostile";
			PChar.quest.betrayed_spain1.win_condition.l1.nation = "Spain";
			PChar.quest.betrayed_spain1.win_condition = "betrayed_spain";
		break;

		case "marriage_arrive_port":
			PChar.quest.marriage_arrive_moa.over = "yes";
			PChar.quest.marriage_arrive_maestra.over = "yes";
			ChangeCharacterAddressGroup(romance, "Santiago_port", "goto", "goto3");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "marriage_arrive_moa":
			PChar.quest.marriage_arrive_port.over = "yes";
			PChar.quest.marriage_arrive_maestra.over = "yes";
			ChangeCharacterAddressGroup(romance, "Cuba_shore_02", "goto", "goto12");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "marriage_arrive_maestra":
			PChar.quest.marriage_arrive_moa.over = "yes";
			PChar.quest.marriage_arrive_port.over = "yes";
			ChangeCharacterAddressGroup(romance, "Cuba_shore_05", "goto", "locator10");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "marriage_partner_interrupts": // Triggered by dialog with Santiago governor
			LAi_SetImmortal(romance, false);
			RemoveOfficersIndex(pchar, romanceidx);
			RemovePassenger(pchar, romance);
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "explain_absence";
			LAi_ActorDialog(romance,PChar,"marriage_soft_heart",1.0,1.0);
		break;

		case "marriage_soft_heart":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "soft_heart";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"marriage_ask_permission",1.0,1.0);
		break;

		case "marriage_ask_permission":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "marriage_proposed";
			LAi_ActorDialog(romance,PChar,"marriage_not_marry_pirate",1.0,1.0);
		break;

		case "marriage_not_marry_pirate":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "not_marry_pirate";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",1.0,1.0);
// If you accept and pay up, exits to "escort_chosen" (you picked an escort or did not want one).
// Or can exit to "broken_heart" (you refused).
// Or can exit to "marriage_governor_waits" (you need to get more money, then talk again).
		break;

		case "marriage_governor_waits":
			LAi_SetStayType(characterFromID("Javier Balboa"));
		break;

		case "broken_heart":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "broken-hearted";
			LAi_ActorDialog(romance,PChar,"marriage_refused",1.0,1.0);
		break;

		case "marriage_refused":
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			AddQuestRecord("Marriage", 2);
			Preprocessor_Remove("romance");
			CloseQuestHeader("Marriage");
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "be_ashamed";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",1.0,1.0);
			PChar.quest.marriage_reject_leaves.win_condition.l1 = "location";
			PChar.quest.marriage_reject_leaves.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.marriage_reject_leaves.win_condition = "marriage_reject_leaves";
			PChar.quest.marriage_revenge.win_condition.l1 = "location";
			PChar.quest.marriage_revenge.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.marriage_revenge.win_condition = "ransom_reject_escape"; // Re-use revenge code from kidnap ransom refusal
		break;

		case "forget_marriage":
			Pchar.quest.marriage_reject_leaves1.win_condition.l1 = "MapEnter";
			Pchar.quest.marriage_reject_leaves1.win_condition = "marriage_reject_leaves";
		break;

		case "marriage_reject_leaves":
			ChangeCharacterAddress(romance, "None", "");
		break;

		case "escort_chosen":
			if (isofficer(romance))
			{
				PChar.quest.marriage_romance_is_officer = "true";
				RemoveOfficersIndex(pchar, romanceidx);
				SetCharacterRemovable(romance, false);
			}
			PChar.quest.marriage_status = "wait_in_tavern";
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "wait_in_tavern";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",1.0,1.0);
			pchar.quest.marriage_wait_in_tavern.win_condition.l1 = "location";
			pchar.quest.marriage_wait_in_tavern.win_condition.l1.location = "Santiago_tavern_upstairs";
			pchar.quest.marriage_wait_in_tavern.win_condition = "marriage_wait_in_tavern";
		break;

		case "marriage_wait_in_tavern":
			WaitDate("", 0, 0, 6, 0, 0);
			SetCurrentTime(10, 0);
			LAi_Fade("", "");
			Locations[FindLocation("Santiago_town_01")].reload.l2.disable = 1;	// Lock the town exit,
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 1;		// the ship,
			Locations[FindLocation("Santiago_port")].reload.l5.disable = 1;		// and the port exit.
			DisableFastTravel(true);						// And no teleporting to the ship either!
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 1;	// Also lock the town hall because the governor has gone to church.
			bQuestDisableSeaEnter = true;						// No skipping off to sea.
			LAi_QuestDelay("wedding_setup", 0.0);
		break;


		case "wedding_setup":
			PChar.quest.marriage_status = "going_to_church";
			if (PChar.sex == "man")
			{
				PChar.quest.romance_model = romance.model;
				SetModelfromArray(romance, GetModelIndex("Lucia_1"));
			}
			if (CheckAttribute(PChar,"quest.wedding_escort") && PChar.quest.wedding_escort != "")
			{
				crewref = characterFromID(PChar.quest.wedding_escort);
				crewidx = GetCharacterIndex(PChar.quest.wedding_escort);
				RemoveOfficersIndex(pchar, crewidx);
				SetCharacterRemovable(crewref, false);
				ChangeCharacterAddressGroup(crewref, "Santiago_church", "sit", "sit13");
				LAi_SetActorType(crewref);
				LAi_ActorSetSitMode(crewref);
			}

			LAi_SetActorType(characterFromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_church", "sit", "sit3");
			LAi_ActorSetSitMode(characterFromID("Javier Balboa"));
			LAi_SetImmortal(CharacterFromID("Javier Balboa"), true);

			Locations[FindLocation("Santiago_church")].locators_radius.goto.goto11 = 2.0;
			logit(TranslateString("","Time to go to church!"));
			Pchar.quest.Wedding_ceremony.win_condition.l1 = "locator";
			Pchar.quest.Wedding_ceremony.win_condition.l1.location = "Santiago_church";
			Pchar.quest.Wedding_ceremony.win_condition.l1.locator_group = "goto";
			Pchar.quest.Wedding_ceremony.win_condition.l1.locator = "goto11";
			Pchar.quest.Wedding_ceremony.win_condition = "Wedding_ceremony";
		break;

		case "Wedding_ceremony":
			PauseAllSounds();
			PlayStereoOGG("wedding2");
			LAi_SetActorType(PChar);
			LAi_SetActorType(romance);
			ChangeCharacterAddressGroup(romance, "Santiago_church", "reload", "reload1");
			LAi_ActorTurnToCharacter(PChar, romance);
			LAi_SetOfficerType(romance);
			LAi_QuestDelay("Wedding_consent1", 5.0);
		break;

		case "Wedding_consent1":
			romance.father = "Javier Balboa";
			romance.married = MR_SINGLE;
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 5.0);
			if (PChar.sex == "man")
			{
//				PChar.quest.bride = GetMyFullName(romance);
//				PChar.quest.groom = GetMyFullName(PChar);
				PChar.quest.bride = GetMyFormalName(romance);
				PChar.quest.groom = GetMyFormalName(PChar);
			}
			else
			{
//				PChar.quest.bride = GetMyFullName(PChar);
//				PChar.quest.groom = GetMyFullName(romance);
				PChar.quest.bride = GetMyFormalName(PChar);
				PChar.quest.groom = GetMyFormalName(romance);
			}
			LAi_SetActorType(characterFromID("Padre Magarino"));
			characters[GetCharacterIndex("Padre Magarino")].Dialog.Filename = "Padre Magarino_dialog.c";
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "wedding_consent1";
			LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"Wedding_consent1_answer",5.0,5.0);
		break;

		case "Wedding_consent1_answer":
			LAi_SetActorType(romance);
			characters[romanceidx].Dialog.Filename = "Gov MR_dialog.c";
			Characters[romanceidx].dialog.CurrentNode = "consent_answer1";
			LAi_ActorDialog(romance,PChar,"Wedding_consent2",5.0,5.0);
		break;

		case "Wedding_consent2":
			LAi_SetActorType(characterFromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "wedding_consent2";
			LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"Wedding_consent2_answer",5.0,5.0);
		break;

		case "Wedding_consent2_answer":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "consent_answer2";
			LAi_ActorDialog(romance,PChar,"Wedding_consent3",5.0,5.0);
		break;

		case "Wedding_consent3":
			if(!LAi_IsDead(villain) && CheckAttribute(PChar, "quest.finale_marriage"))
			{
				PauseAllSounds();
				ChangeCharacterAddressGroup(villain, "Santiago_church", "reload", "reload1");
				LAi_SetActorType(PChar);
				LAi_ActorTurnToCharacter(PChar, villain);
				LAi_SetActorType(characterFromID("Javier Balboa"));
				LAi_ActorTurnToCharacter(characterFromID("Javier Balboa"), villain);
				LAi_SetActorType(romance);
				LAi_ActorTurnToCharacter(romance, villain);
				if (CheckAttribute(PChar,"quest.wedding_escort") && PChar.quest.wedding_escort != "")
				{
					crewref = characterFromID(PChar.quest.wedding_escort);
					crewidx = GetCharacterIndex(PChar.quest.wedding_escort);
					LAi_SetActorType(crewref);
					LAi_ActorTurnToCharacter(crewref, villain);
				}
				LAi_QuestDelay("finale_marriage_villain_interrupts", 2.0);
			}
			else
			{

				LAi_SetActorType(characterFromID("Padre Magarino"));
				Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "wedding_consent3";
//				LAi_SetActorType(PChar);
//				LAi_ActorDialog(PChar,characterFromID("Padre Magarino"),"Wedding_consent3_answer",5.0,5.0);
				LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"Wedding_consent3_answer",5.0,5.0);
			}
		break;

		case "Wedding_consent3_answer":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "consent_answer3";
			LAi_ActorDialog(romance,PChar,"Wedding_his_vow",5.0,5.0);
		break;

		case "Wedding_his_vow":
			LAi_SetActorType(characterFromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "his_vow";
			LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"",5.0,5.0); // If you are man, exits to "Wedding_vow_her_answer", otherwise exits to "Wedding_vow_his_answer"
		break;

		case "Wedding_vow_her_answer":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "vow_answer";
			LAi_ActorDialog(romance,PChar,"Wedding_bless_rings",5.0,5.0);
		break;

		case "Wedding_vow_his_answer":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "vow_answer";
			LAi_ActorDialog(romance,PChar,"Wedding_her_vow",5.0,5.0);
		break;

		case "Wedding_her_vow":
			LAi_SetActorType(characterFromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "her_vow";
			LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"",5.0,5.0); // If you are man, exits to "Wedding_vow_her_answer", otherwise exits to "Wedding_bless_rings"
		break;

		case "Wedding_bless_rings":
			LAi_SetActorType(characterFromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "bless_rings";
			LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"Wedding_exchange_rings",5.0,5.0);
		break;

		case "Wedding_exchange_rings":
			TakeItemFromCharacter(Pchar, PChar.quest.wedding_ring);
			GiveItem2Character(PChar, "WeddingRing");
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "he_gives_ring";
			LAi_ActorDialog(romance,PChar,"Wedding_final_blessing",5.0,5.0);
		break;

		case "Wedding_final_blessing":
			LAi_SetActorType(CharacterFromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "final_blessing";
			LAi_ActorDialog(CharacterFromID("Padre Magarino"),PChar,"Wedding_done",5.0,5.0);
		break;

		case "Wedding_done":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_church", "goto", "goto6");
			if (CheckAttribute(PChar,"quest.wedding_escort") && PChar.quest.wedding_escort != "")
			{
				crewref = characterFromID(PChar.quest.wedding_escort);
				crewidx = GetCharacterIndex(PChar.quest.wedding_escort);
//				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				StoreDialog(crewref);
				LAi_SetActorType(crewref);
				ChangeCharacterAddressGroup(crewref, "Santiago_church", "goto", "goto7");
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "married_congrats";
// trace("------------------------------");
// if (crewidx >0) dumpattributes(Characters[crewidx]);
// else trace("Invalid crewidx for wedding escort");
// trace("------------------------------");
				LAi_ActorDialog(crewref, pchar, "wedding_done2", 5.0, 5.0);
			}
			else LAi_QuestDelay("Wedding_done2", 1.0);
		break;

		case "Wedding_done2":
			if (CheckAttribute(PChar,"quest.wedding_escort") && PChar.quest.wedding_escort != "")
			{
				crewref = characterFromID(PChar.quest.wedding_escort);
				crewidx = GetCharacterIndex(PChar.quest.wedding_escort);
//				characters[crewidx].Dialog.Filename = PChar.quest.normal_dialog;
				RestoreDialog(crewref);
				SetCharacterRemovable(crewref, true);
			}
			StoreOfficers(PChar.id);
			Locations[FindLocation("Santiago_town_01")].reload.l2.disable = 0;	// Unlock the town exit,
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;		// the ship,
			Locations[FindLocation("Santiago_port")].reload.l5.disable = 0;		// and the port exit.
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 0;	// Also the town hall because you're about to go there.
			DisableFastTravel(false);
			LAi_SetActorType(characterFromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_church", "goto", "goto6");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			LAi_ActorFollowEverywhere(CharacterFromID("Javier Balboa"), "", 10.0);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "now_youre_married";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"Married",1.0,1.0);
		break;

		case "Married":
			PChar.quest.marriage_status = "married";
			characters[romanceidx].married = MR_MARRIED;
			characters[romanceidx].married.id = PChar.id;
			characters[romanceidx].quest.meeting = "1"
			characters[romanceidx].Dialog.Filename = "Gov MR_dialog.c";
			characters[romanceidx].Dialog.CurrentNode = "First time";
			characters[romanceidx].talkpoints = 0;
			characters[romanceidx].marpoints = 1;
			characters[romanceidx].pcounter = 0;
// Advice from Homo Eructus: married women do not adopt their husbands' surnames
//			if (PChar.sex == "man") characters[romanceidx].middlename = TranslateString("","Ardent");
//			else PChar.middlename = TranslateString("","de la Vega");
			PChar.married = MR_MARRIED;
			PChar.married.id = characters[romanceidx].id;

			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			LAi_ActorFollowEverywhere(CharacterFromID("Javier Balboa"), "", 10.0);

			Pchar.quest.return_to_residence.win_condition.l1 = "location";
			PChar.quest.return_to_residence.win_condition.l1.character = Pchar.id;
			Pchar.quest.return_to_residence.win_condition.l1.location = "Santiago_townhall";
			Pchar.quest.return_to_residence.win_condition = "return_to_residence";

			Pchar.quest.leave_church.win_condition.l1 = "location";
			Pchar.quest.leave_church.win_condition.l1.location = "Santiago_town_01";
			Pchar.quest.leave_church.win_condition = "leave_church";
			if (PChar.sex == "man") WriteNewLogEntry("Married my beautiful wife", "On this wonderful day I married my beautiful wife, "+GetMySimpleName(romance)+". We're both very happy, and now I am going to finish this writing, because I have something more important to do...","Personal",true);
			else WriteNewLogEntry("Married my handsome husband", "On this wonderful day I married my handsome husband, "+GetMySimpleName(romance)+". We're both very happy, and now I am going to finish this writing, because I have something more important to do...","Personal",true);
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			AddQuestRecord("Marriage", 11);
			Preprocessor_Remove("romance");
			ChangeCharacterReputation(PChar, 5);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 500);
				AddPartyExpChar(PChar, "", 50);
			}
			else {AddPartyExp(pchar, 550);}
		break;

		case "leave_church":
   			LAi_SetPriestType(CharacterFromID("Padre Magarino"));
			LAi_SetActorType(romance);
			LAi_SetActorType(characterFromID("Javier Balboa"));
            		LAi_ActorGoToLocation(romance, "reload", "reload4", "none", "", "", "", 120.0);
            		LAi_ActorGoToLocation(characterFromID("Javier Balboa"), "reload", "reload4", "none", "", "", "", 120.0);
			if (CheckAttribute(PChar,"quest.wedding_escort") && PChar.quest.wedding_escort != "") ChangeCharacterAddress(CharacterFromID(PChar.quest.wedding_escort), "None", "");
		break;

		case "return_to_residence":
			DisableFastTravel(true);
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 1;
//			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
			ch = LAi_CreateFantomCharacter(true, 0, false, false, 0.0, romance.model, "goto", "goto9");
			ch.id = "fake_romance";
			ch.name = romance.name;
			ch.lastname = romance.lastname;
			if (checkattribute(romance, "middlename")) ch.middlename = romance.middlename;
			LAi_SetActorType(characterFromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto6", "return_to_residence2", 65.0);

			DeleteQuestAttribute("marriage_status");
			DeleteQuestAttribute("marriage_money");
			DeleteQuestAttribute("wedding_escort");
			DeleteQuestAttribute("bride");
			DeleteQuestAttribute("groom");
		break;

		case "return_to_residence2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterfromID("Javier Balboa"));
			LAi_SetActorType(romance);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "enjoy_reception";
			if(LAi_IsDead(villain) || CheckAttribute(PChar, "quest.finale_marriage")) LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"bypass_reception",5.0,5.0);
//			else LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"assassination_attempt",5.0,5.0);
			else LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",5.0,5.0); // Exits to "assassination_attempt"
		break;

		case "bypass_reception":
			SetCurrentTime(21, rand(10));
			ChangeCharacterAddressGroup(romance, "Quest_Santiago_Bedroom", "goto", "goto5");
			DoQuestReloadToLocation("Santiago_townhall", "reload", "reload3", "reception_done");
		break;

		case "reception_done":
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "reception_done";
			LAi_ActorDialog(characterFromID("Javier Balboa"),PChar,"prepare_for_bed",5.0,5.0);
		break;

		case "prepare_for_bed":
			SetCurrentTime(21, 10 + rand(10));
			DoQuestReloadToLocation("Quest_Santiago_Bedroom", "reload", "reload1", "bedtime_chat");
		break;

		case "bedtime_chat":
			LAi_SetStayType(romance);
			characters[romanceidx].Dialog.Filename = "romance_dialog.c";
			characters[romanceidx].Dialog.CurrentNode = "wedding_night"; // You will talk to your partner and the dialog exits to "get_lost_player"
		break;

		case "get_lost_player":
			Pchar.dialog.CurrentNode = "stop_peeking";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "morning_after_wedding");
		break;

		case "morning_after_wedding":
			if (PChar.sex == "man")
			{
				SetModelFromID(romance, PChar.quest.romance_model);
//				DeleteQuestAttribute("romance_model");
			}
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10, 0);
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
//			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
//			LAi_SetStayType(characterfromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_townhall", "sit", "sit1");
			LAi_SetHuberType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "enjoy_reception";
			DoQuestReloadToLocation("Santiago_townhall", "reload", "reload2", "morning_after_wedding2");
		break;

		case "morning_after_wedding2":
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 0;
			DisableFastTravel(false);
			bQuestDisableSeaEnter = false;
			AddQuestRecord("Marriage", 12);
			CloseQuestHeader("Marriage");
			RestoreOfficers(PChar.id);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "wedding_present";
			if(CheckAttribute(romance,"officer") || CheckQuestAttribute("marriage_romance_is_officer", "true"))
			{
				AddPassenger(PChar, romance, 0);
				SetOfficersIndex(Pchar, 3, romanceidx);
				LAi_SetOfficerType(romance);
				SetCharacterRemovable(romance, true);
				if (CheckAttribute(PChar, "quest.marriage_romance_is_officer")) DeleteQuestAttribute("marriage_romance_is_officer");
				characters[romanceidx].Dialog.Filename = "romance_dialog.c";
				characters[romanceidx].Dialog.CurrentNode = "First time";
			}
			else
			{
				characters[romanceidx].Dialog.Filename = "Gov MR_dialog.c";
				characters[romanceidx].Dialog.CurrentNode = "First time";
			}
		break;

		case "betrayed_spain":
			PChar.quest.betrayed_spain.over = "yes";
			PChar.quest.betrayed_spain1.over = "yes";
			PChar.quest.spain_betrayal = "true";
			if(ispassenger(romance) || isofficer(romance))
			{
				RemoveOfficersIndex(pchar, romanceidx);
				RemovePassenger(pchar, romance);
				Preprocessor_Save("romance", GetMySimpleName(romance));
				GiveItem2Character(PChar, "BetrayedLetter");
				ChangeCharacterAddress(romance, "None", "");
				WriteNewLogEntry(GetMySimpleName(romance) + " deserts", GetMySimpleName(romance) + " didn't take too kindly to my actions against Spain, and has left me.", "Personal", true);
			}
			else
			{
				if(GetAttribute(romance, "married") == MR_MARRIED)
				{
					characters[romanceidx].Dialog.Filename = "romance_dialog.c";
					characters[romanceidx].Dialog.CurrentNode = "dont_talk_to_me";
					if (characters[getCharacterIndex(PChar.quest.romance)].married.id == PChar.id)
					{
						WriteNewLogEntry(GetMySimpleName(romance) + " deserts", GetMySimpleName(romance) + " didn't take too kindly to my actions against Spain, and has left me.", "Personal", true);
					}
				}
			}
		break;

		case "lucia_new_outfit":
			for (n=0; n<COMPANION_MAX; n++)
			{
				cidx = GetCompanionIndex(PChar, n);
				ch = GetCharacter(cidx);
				if (GetCargoGoods(ch,GOOD_SILK) > 0)
				{
					AddCharacterGoods(ch, GOOD_SILK, -1);
					break;
				}
			}
			PChar.quest.lucia_new_outfit2.win_condition.l1 = "Timer";
			PChar.quest.lucia_new_outfit2.win_condition.l1.date.day = GetAddingDataDay(0, 0, 2);
			PChar.quest.lucia_new_outfit2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2);
			PChar.quest.lucia_new_outfit2.win_condition.l1.date.year = GetAddingDataYear(0, 0, 2);
			PChar.quest.lucia_new_outfit2.win_condition = "lucia_finishes_outfit";
		break;

		case "lucia_finishes_outfit":
			GiveModel2Player("Lucia_1", false);
			GiveModel2Player("lucia_2", false);
			SetModelfromID(romance, "lucia_2");
			WriteNewLogEntry(GetMyName(romance) + "'s new clothes", GetMySimpleName(romance) + " has taken some silk from our hold without bothering to ask. But after seeing the new clothes she made for herself with it, I'm not complaining!","Personal",true);
		break;

		case "finale_marriage_villain_interrupts":
			PauseAllSounds();
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "wedding_forbid_this";
			LAi_ActorDialogNow(villain, PChar, "finale_marriage_priest_who_are_you",1.0);
		break;

		case "finale_marriage_priest_who_are_you":
			LAi_SetActorType(characterfromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "ardent_interruption1";
			LAi_ActorDialogNow(characterfromID("Padre Magarino"), PChar, "finale_marriage_romance_is_mine",1.0);
		break;

		case "finale_marriage_romance_is_mine":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "wedding_romance_is_mine";
			LAi_ActorDialogNow(villain, PChar, "finale_marriage_priest_recognises_villain",1.0);
		break;

		case "finale_marriage_priest_recognises_villain":
			LAi_SetActorType(characterfromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "ardent_interruption2";
			LAi_ActorDialogNow(characterfromID("Padre Magarino"), PChar, "finale_marriage_over_my_dead_body",1.0);
		break;

		case "finale_marriage_over_my_dead_body":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "wedding_over_my_dead_body";
			LAi_ActorDialogNow(villain, PChar, "finale_marriage_no_fight_here",1.0);
		break;

		case "finale_marriage_no_fight_here":
			LAi_SetActorType(characterfromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "ardent_no_fight_in_church";
			LAi_ActorDialogNow(characterfromID("Padre Magarino"), PChar, "finale_marriage_lets_go_outside",1.0);
		break;

		case "finale_marriage_lets_go_outside":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "wedding_go_outside";
			LAi_ActorDialogNow(villain, PChar, "finale_marriage_about_to_sin",1.0);
		break;

		case "finale_marriage_about_to_sin":
			LAi_SetActorType(characterfromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "ardent_about_to_sin";
			LAi_ActorDialogNow(characterfromID("Padre Magarino"), PChar, "finale_marriage_fight_villain",1.0);
		break;

		case "finale_marriage_fight_villain":
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_church")], false);
			LAi_SetImmortal(romance, true);
			LAi_SetImmortal(villain, false);
			LAi_SetActorType(villain);
			LAi_ActorAttack(villain, PChar, "");
			PChar.quest.finale_marriage_duel_over.win_condition.l1 = "NPC_death";
			Pchar.quest.finale_marriage_duel_over.win_condition.l1.character = Characters[villainidx].id;
			Pchar.quest.finale_marriage_duel_over.win_condition = "finale_marriage_duel_over";
		break;

		case "finale_marriage_duel_over":
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_church")], true);
			LAi_SetImmortal(romance, false);
			LAi_SetActorType(characterfromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "ardent_church_desecrated";
			LAi_ActorDialogNow(characterfromID("Padre Magarino"), PChar, "finale_marriage_governor_supports_you",1.0);
		break;

		case "finale_marriage_governor_supports_you":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_church", "goto", "goto6");
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "finale_villain_was_traitor";
			LAi_ActorDialogNow(characterfromID("Javier Balboa"), PChar, "finale_marriage_priest_loyal_to_church",1.0);
		break;

		case "finale_marriage_priest_loyal_to_church":
			LAi_SetActorType(characterfromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "ardent_loyal_to_church_first";
			LAi_ActorDialogNow(characterfromID("Padre Magarino"), PChar, "finale_marriage_governor_insists",1.0);
		break;

		case "finale_marriage_governor_insists":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "finale_reconsecrate_with_wedding";
//			LAi_ActorDialogNow(characterfromID("Javier Balboa"), PChar, "finale_priest_gives_way",1.0);
			LAi_ActorDialogNow(characterfromID("Javier Balboa"), PChar, "finale_marriage_return_to_priest",1.0);
		break;

		case "finale_priest_gives_way":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_church", "sit", "sit3");
			LAi_ActorSetSitMode(characterFromID("Javier Balboa"));
			LAi_SetActorType(characterfromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "ardent_proceed_with_wedding";
			LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"Wedding_consent3_answer",5.0,5.0);
//			LAi_ActorDialogNow(characterFromID("Padre Magarino"),PChar,"finale_marriage_return_to_priest",5.0);
		break;

		case "finale_marriage_return_to_priest":
			if (CheckAttribute(PChar,"quest.wedding_escort") && PChar.quest.wedding_escort != "")
			{
				crewref = characterFromID(PChar.quest.wedding_escort);
				crewidx = GetCharacterIndex(PChar.quest.wedding_escort);
				ChangeCharacterAddressGroup(crewref, "Santiago_church", "sit", "sit13");
				LAi_SetActorType(crewref);
				LAi_ActorSetSitMode(crewref);
			}

			LAi_SetActorType(characterFromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_church", "sit", "sit3");
			LAi_ActorSetSitMode(characterFromID("Javier Balboa"));
			PauseAllSounds();
			PlayStereoOGG("wedding2");
			LAi_SetActorType(PChar);
//			LAi_ActorFollow(PChar, characterFromID("Padre Magarino"), "Wedding_consent3_answer", 10.0);
			LAi_ActorFollow(PChar, characterFromID("Padre Magarino"), "finale_priest_gives_way", 10.0);
		break;

		case "assassination_attempt":
			ChangeCharacterAddressGroup(characterfromID("Malbert Sangier"), "Santiago_town_01", "goto", "goto9");
			LAi_SetActorType(characterFromID("Grigorio Formoselle"));
			LAi_ActorGoToLocator(characterFromID("Grigorio Formoselle"), "reload", "reload3", "",5.0);
			LAi_QuestDelay("assassination_attempt2", 2.00);
		break;

		case "assassination_attempt2":
			PlaySound("OBJECTS\duel\pistol_medium2.wav");
			PlaySound("AMBIENT\TOWN\window_dog.wav");
			LAi_QuestDelay("assassination_attempt3", 0.02);
		break;

		case "assassination_attempt3":
			LAi_SetActorType(characterFromID("Grigorio Formoselle"));
			LAi_ActorTurnToCharacter(characterFromID("Grigorio Formoselle"), characterfromID("fake_romance"));
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 0;
//			Lai_KillCharacter(romance);
			LAi_KillCharacter(characterfromID("fake_romance"));
			ChangeCharacterAddress(romance, "None", "");
			if(PChar.sex == "man") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom2.wav");
			else PlaySound("OBJECTS\VOICES\DEAD\male\dead5.wav");
			romance.chr_ai.hp = romance.chr_ai.hp_max;
			PChar.quest.assassination = "no_clue";
			PChar.quest.revenge_type = "assassin";
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			AddQuestRecord("Marriage", 13);
			Preprocessor_Remove("romance");
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "assassination";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"assassination_grigorio_moves",1.0,1.0);
			PChar.quest.assassin_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.assassin_dead.win_condition.l1.character = "Malbert Sangier";
			PChar.quest.assassin_dead.win_condition = "assassin_dead";
/*			PChar.quest.assassination_remove_body.win_condition.l1 = "location";
			PChar.quest.assassination_remove_body.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.assassination_remove_body.win_condition = "assassination_remove_body";
		break;

		case "assassination_remove_body": */
			ChangeCharacterAddress(romance, "None", "");
		break;

		case "assassination_grigorio_moves":
			LAi_SetActorType(characterFromID("Grigorio Formoselle"));
			LAi_ActorRunToLocator(characterFromID("Grigorio Formoselle"), "goto", "goto9", "",60.0);
		break;

		case "assassination_malbert_attacks":
			LAi_SetActorType(characterFromID("Malbert Sangier"));
			LAi_ActorAttack(characterfromID("Malbert Sangier"), PChar, "");
		break;

		case "assassin_dead":
			PChar.quest.assassination = "assassin_dead";
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_town_01")], true);
			StartQuestMovie(true, true, false);
			TakeItemFromCharacter(characterfromID("Malbert Sangier"), "SignetRing");
			GiveItem2Character(PChar, "SignetRing");
			characters[GetCharacterIndex("Santiago_soldier_05")].Dialog.Filename = "guard_dialog.c";
			LAi_SetActorType(characterFromID("Santiago_soldier_05"));
			Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "assassination_arrest";
			LAi_ActorDialog(characterFromID("Santiago_soldier_05"),PChar,"assassination_return_to_governor",60.0,60.0);
		break;

		case "assassination_return_to_governor":
			ChangeCharacterAddressGroup(characterfromID("Grigorio Formoselle"), "Santiago_townhall", "goto", "goto10");
			LAi_SetStayType(characterfromID("Grigorio Formoselle"));
			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
			LAi_SetStayType(characterfromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterfromID("Santiago_soldier_05"), "Santiago_townhall", "goto", "goto11");
			DoQuestReloadToLocation("Santiago_townhall", "goto", "goto1", "assassination_return_to_governor2");
		break;

		case "assassination_return_to_governor2":
			ChangeCharacterAddress(characterfromID("Malbert Sangier"), "None", "");
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_town_01")], false);
			LAi_SetActorType(characterfromID("Santiago_soldier_05"));
			Characters[GetCharacterIndex("Santiago_soldier_05")].dialog.CurrentNode = "go_to_governor";
			LAi_ActorDialog(CharacterFromID("Santiago_soldier_05"),PChar,"assassination_return_to_governor3",1.0,1.0);
		break;

		case "assassination_return_to_governor3":
			LAi_SetActorType(characterfromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "will_be_fine";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",1.0,1.0); // Exits to "assassination_fade_to_next_day", possibly via "assassination_grigorio_explains_ring"
		break;

		case "assassination_grigorio_explains_ring":
			LAi_SetActorType(CharacterFromID("Grigorio Formoselle"));
			Characters[GetCharacterIndex("Grigorio Formoselle")].dialog.CurrentNode = "assassination_examine_ring";
			LAi_ActorDialog(CharacterFromID("Grigorio Formoselle"),PChar,"assassination_hired_by_villain",5.0,5.0);
		break;

		case "assassination_hired_by_villain":
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "villain_hired_assassin";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",1.0,1.0); // Exits to "assassination_fade_to_next_day"
		break;

		case "assassination_fade_to_next_day":
			EndQuestMovie();
			ResetHP(romance);
			LAi_SetStayType(characterfromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterfromID("Santiago_soldier_05"), "Santiago_town_01", "goto", "locator36");
			LAi_SetGuardianType(characterfromID("Santiago_soldier_05"));
			characters[GetCharacterIndex("Santiago_soldier_05")].Dialog.Filename = "Isla Muelle soldier_dialog.c";
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
			DoQuestReloadToLocation("Santiago_townhall", "reload", "reload2", "assassination_fade_to_next_day2");
		break;

		case "assassination_fade_to_next_day2":
			WaitDate("", 0, 0, 5, 0, 0);
			SetCurrentTime(10, 0);
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "romance_recovered";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"romance_has_request",1.0,1.0);
		break;

		case "romance_has_request":
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("romance", GetMyName(romance));
			AddQuestRecord("Marriage", 17);
			CloseQuestHeader("Marriage");
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			LAi_SetActorType(romance);
			characters[romanceidx].Dialog.Filename = "romance_dialog.c";
			Characters[romanceidx].dialog.CurrentNode = "ask_favour";
			LAi_ActorDialog(romance,PChar,"convoy_governor_issues_letter",1.0,1.0);
		break;

		case "convoy_governor_issues_letter":
			LAi_SetStayType(romance);
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "convoy_letter_reprisal";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"convoy_officer",1.0,1.0);
		break;

		case "convoy_officer":
			LAi_SetHuberStayType(CharacterFromID("Javier Balboa"));
			if(CheckAttribute(romance,"officer"))
			{
				AddPassenger(PChar, romance, 0);
				SetOfficersIndex(Pchar, 3, romanceidx);
				characters[romanceidx].Dialog.Filename = "romance_dialog.c";
				characters[romanceidx].Dialog.CurrentNode = "First time";
				LAi_QuestDelay("convoy_officer2", 0.0);
			}
			else
			{
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.CurrentNode = "convoy_officer";
				LAi_ActorDialog(romance,PChar,"convoy_officer2",5.0,5.0);
			}

			PChar.quest.convoy_romance_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.convoy_romance_dead.win_condition.l1.character = romance.id;
			PChar.quest.convoy_romance_dead.win_condition = "convoy_romance_dead";

			if(!CheckAttribute(PChar, "quest.betrayed_spain"))
			{
				PChar.quest.betrayed_spain.win_condition.l1 = "relation";
				PChar.quest.betrayed_spain.win_condition.l1.relation = "Hostile";
				PChar.quest.betrayed_spain.win_condition.l1.nation = "Spain";
				PChar.quest.betrayed_spain.win_condition = "betrayed_spain";
			}
		break;

		case "convoy_officer2":
			LAi_SetOfficerType(romance);
			RestoreOfficers(PChar.id);
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("romance", GetMyName(romance));
			AddQuestRecord("Convoy Strike", 2);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			LAi_QuestDelay("convoy_setup", 0.0);
		break;

		case "convoy_setup":
			DisableFastTravel(false);
			bQuestDisableSeaEnter = false;
			PChar.quest.ardent_convoy = "Oxbay";
//			PChar.quest.Abequa_moves.win_condition.l1 = "location";
//			PChar.quest.Abequa_moves.win_condition.l1.location = "Cartagena Hotel";
//			PChar.quest.Abequa_moves.win_condition = "convoy_Abequa_moves";
		break;

/*		case "convoy_Abequa_moves":		// No longer needed if Abequa is already on ground floor
			LAi_SetActorType(characterFromID("Abequa"));
			LAi_ActorGoToLocator(characterFromID("Abequa"), "goto", "goto6", "",30.0);
		break; */

		case "convoy_Abequa_speaks":	// Triggered by dialog with Mary Seacole
//			PChar.quest.normal_dialog = characters[GetCharacterIndex("Abequa")].Dialog.Filename;
			StoreDialog(CharacterFromID("Abequa"));
			characters[GetCharacterIndex("Abequa")].Dialog.Filename = "Abequa_dialog.c";
			LAi_SetActorType(CharacterFromID("Abequa"));
			Characters[GetCharacterIndex("Abequa")].dialog.CurrentNode = "ardent_convoy_was_here";
			LAi_ActorDialog(CharacterFromID("Abequa"),PChar,"",10.0,10.0); // Exits to "convoy_to_curacao" or "convoy_Abequa_waits"
		break;

		case "convoy_Abequa_waits":
			LAi_SetStayType(CharacterFromID("Abequa"));
		break;

		case "convoy_reset_Abequa":
			LAi_SetStayType(CharacterFromID("Abequa"));
			RestoreDialog(CharacterFromID("Abequa"));
//			characters[GetCharacterIndex("Abequa")].Dialog.Filename = PChar.quest.normal_dialog;
//			ChangeCharacterAddressGroup(CharacterFromID("Abequa"), "Cartagena Hotel", "goto", "character2");
//			LAi_SetOfficerType(romance);
		break;

		case "convoy_to_curacao":
			PChar.quest.ardent_convoy = "Curacao";
			AddQuestRecord("Convoy Strike", 4);
			setCharacterShipLocation(characterFromID("Convoy_Captain1"), "Willemstad_port");
			setCharacterShipLocation(characterFromID("Convoy_Captain2"), "Willemstad_port");
			setCharacterShipLocation(characterFromID("Convoy_Captain3"), "Willemstad_port");
			setCharacterShipLocation(characterFromID("Convoy_Captain4"), "Willemstad_port");
			PChar.quest.reset_Abequa.win_condition.l1 = "location";
			PChar.quest.reset_Abequa.win_condition.l1.location = "Cartagena_Center";
			PChar.quest.reset_Abequa.win_condition = "convoy_reset_Abequa";
			PChar.quest.arrival_curacao.win_condition.l1 = "location";
			PChar.quest.arrival_curacao.win_condition.l1.location = "Curacao";
			PChar.quest.arrival_curacao.win_condition = "convoy_arrival_curacao";
		break;

		case "convoy_arrival_curacao":
			if(!LAi_IsDead(romance) && !CheckAttribute(PChar, "quest.spain_betrayal"))
			{
				SetCharacterShipLocation(PChar, "Willemstad_port");
				if(!isofficer(romance)) SetOfficersIndex(Pchar, 3, romanceidx);
				SetCharacterRemovable(romance, false);
				if (CheckAttribute(romance, "AbordageMode")) romance.quest.old_abordagemode = romance.AbordageMode;
				else romance.quest.old_abordagemode = 0;
				romance.AbordageMode = 1;
				ChangeCharacterAddressGroup(romance, GetCharacterShipCabin(PChar), "rld", "startloc");
				StartQuestMovie(true, true, false);
				DoReloadFromSeaToLocation(GetCharacterShipCabin(PChar), "reload", "reload1");
				LAi_QuestDelay("convoy_plan_attack", 1.0);
			}
			else
			{
				AddQuestRecord("Convoy Strike", 15);
				if (PChar.sex == "man") GiveModel2Player("Ardent_S", true);
				else GiveModel2Player("Ardent_SF", true);
				Pchar.quest.Willemstad_residence.win_condition.l1 = "location";
				PChar.quest.Willemstad_residence.win_condition.l1.character = Pchar.id;
				Pchar.quest.Willemstad_residence.win_condition.l1.location = "Willemstad_townhall";
				Pchar.quest.Willemstad_residence.win_condition = "Willemstad_residence";
			}
		break;

		case "convoy_plan_attack":
			LAi_SetActorType(romance);
			characters[romanceidx].Dialog.Filename = "romance_dialog.c";
			Characters[romanceidx].dialog.CurrentNode = "convoy_how_take_convoy";
			LAi_ActorDialog(romance,PChar,"",5.0,5.0); // Exits to "convoy_arrive_port_plan1" or "convoy_arrive_port"
		break;

		case "convoy_arrive_port_plan1":
			LAi_SetOfficerType(romance);
			PChar.location.from_sea = "Willemstad_port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "PChar");
			DoQuestReloadToLocation("Willemstad_port", "reload", "sea_back", "convoy_arrive_port_plan1_2");
		break;

		case "convoy_arrive_port_plan1_2":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_recognised";
			LAi_ActorDialog(romance,PChar,"convoy_plan1_no_good",5.0,5.0);
		break;

		case "convoy_plan1_no_good":
			ChangeCharacterAddressGroup(romance, GetCharacterShipCabin(PChar), "rld", "startloc");
			DoQuestReloadToLocation(GetCharacterShipCabin(PChar), "reload", "reload1", "convoy_plan_attack2");
		break;

		case "convoy_plan_attack2":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_recognised2";
			LAi_ActorDialog(romance,PChar,"",5.0,5.0); // Exits to "convoy_arrive_port"
		break;

		case "convoy_arrive_port":
			EndQuestMovie();
			LAi_SetOfficerType(romance);
			PChar.quest.romance_model = romance.model;
			if (GetAttribute(romance, "sex") == "man") SetModelFromID(romance, "AnimistEdmundo"));
			else SetModelFromID(romance, "AnimistLucia");
			PChar.location.from_sea = "Willemstad_port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "PChar");
			if (PChar.sex == "man") GiveModel2Player("Ardent_S", true);
			else GiveModel2Player("Ardent_SF", true);
			DoQuestReloadToLocation("Willemstad_port", "reload", "sea_back", "convoy_arrive_port2");
		break;

		case "convoy_arrive_port2":
			if(PChar.model == "Ardent_SF") logit(TranslateString("","This uniform is uncomfortable, being made for a man, but I'd better wear it whenever I need to talk to the governor."));
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_sergeant"), "Willemstad_townhall", "goto", "goto2");
			characters[GetCharacterIndex("Dutch_sergeant")].Dialog.Filename = "guard_dialog.c";
			LAi_SetGuardianType(characterfromID("Dutch_sergeant"));
			Pchar.quest.Willemstad_residence.win_condition.l1 = "location";
			PChar.quest.Willemstad_residence.win_condition.l1.character = Pchar.id;
			Pchar.quest.Willemstad_residence.win_condition.l1.location = "Willemstad_townhall";
			Pchar.quest.Willemstad_residence.win_condition = "Willemstad_residence";
			n = 1;
			if(GetCompanionQuantity(PChar) > n)
			{
				Locations[FindLocation("Willemstad_town_3")].reload.l6.disable = 1;
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.CurrentNode = "convoy_dispose_ships";
				LAi_ActorDialog(romance,PChar,"convoy_goto_shipyard",5.0,5.0);
			}
			if(CheckQuestAttribute("revenge_type","kidnap_rescue") && GetCompanionQuantity(PChar) == 1)
			{
				Locations[FindLocation("Willemstad_town_3")].reload.l6.disable = 1;
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.CurrentNode = "convoy_dispose_just_my_ship";
				LAi_ActorDialog(romance,PChar,"convoy_goto_shipyard",5.0,5.0);
			}
		break;

		case "convoy_goto_shipyard":
			LAi_SetOfficerType(romance);
			Pchar.quest.Willemstad_Shipyard.win_condition.l1 = "location";
			Pchar.quest.Willemstad_Shipyard.win_condition.l1.location = "Willemstad_Shipyard";
			Pchar.quest.Willemstad_Shipyard.win_condition = "convoy_Willemstad_Shipyard";
		break;

		case "convoy_Willemstad_Shipyard":
			SetCharacterRemovable(romance, true); // In case you put Lucía / Edmundo in command of a ship
			Pchar.quest.back_in_Willemstad_town.win_condition.l1 = "location";
			Pchar.quest.back_in_Willemstad_town.win_condition.l1.location = "Willemstad_town";
			Pchar.quest.back_in_Willemstad_town.win_condition = "convoy_back_in_Willemstad_town";
		break;

		case "convoy_back_in_Willemstad_town":
			SetCharacterRemovable(romance, false);
			n = 1;
			if (CheckQuestAttribute("revenge_type", "kidnap_rescue") && GetCharacterShipType(PChar) != SHIP_NOTUSED)
			{
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.CurrentNode = "convoy_dispose_just_my_ship2";
				LAi_ActorDialog(romance,PChar,"",5.0,5.0);	// Exits to "convoy_goto_shipyard" or "convoy_dump_ship"
			}
			else
			{
				if(GetCompanionQuantity(PChar) > n)
				{
					LAi_SetActorType(romance);
					Characters[romanceidx].dialog.CurrentNode = "convoy_dispose_ships2";
					LAi_ActorDialog(romance,PChar,"convoy_goto_shipyard",5.0,5.0);
				}
				else
				{
					Locations[FindLocation("Willemstad_town_3")].reload.l6.disable = 0;
					LAi_SetActorType(romance);
					LAi_ActorFollowEverywhere(romance, "", 10.0);
				}
			}
		break;

		case "convoy_dump_ship":
			Locations[FindLocation("Willemstad_town_3")].reload.l6.disable = 0;
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "romance_to_officer_mode":
			LAi_SetOfficerType(romance);
		break;

		case "Willemstad_residence":
			if(!LAi_IsDead(romance) && !CheckAttribute(PChar, "quest.spain_betrayal"))
			{
				Locations[FindLocation("Willemstad_townhall")].reload.l1.disable = 1;
				DisableFastTravel(true);
				ChangeCharacterAddressGroup(romance, "Willemstad_townhall", "goto", "goto1");
				LAi_SetActorType(romance);
				LAi_ActorFollowEverywhere(romance, "", 10.0);
			}
			PChar.quest.original_name = PChar.name;
			if (CheckAttribute(PChar,"middlename") == true && PChar.middlename != "")
			{
				PChar.quest.original_middlename = PChar.middlename;
				PChar.middlename = "";
			}
			PChar.quest.original_lastname = PChar.lastname;
			PChar.name = TranslateString("","Carlos");
			PChar.lastname = TranslateString("","Ardenta");
			characters[GetCharacterIndex("Hans Kloss")].dialog.CurrentNode = "ardent_convoy_fake_intro";
		break;

		case "convoy_partner_intervenes": // Triggered by dialog with "Hans Kloss", governor of Curacao
			LAi_SetActorType(CharacterFromID("Hans Kloss"));
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_be_quiet";
			LAi_ActorDialog(romance,PChar,"convoy_governor_appeased",5.0,5.0);
		break;

		case "convoy_governor_appeased":
			LAi_SetActorType(CharacterFromID("Hans Kloss"));
			Characters[GetCharacterIndex("Hans Kloss")].dialog.CurrentNode = "ardent_convoy_thats_different";
			LAi_ActorDialog(CharacterFromID("Hans Kloss"),PChar,"convoy_partner_shows_letter",1.0,1.0);
		break;

		case "convoy_partner_shows_letter":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_show_letter";
			LAi_ActorDialog(romance,PChar,"convoy_governor_agrees",1.0,1.0);
		break;

		case "convoy_governor_agrees":
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			LAi_SetActorType(CharacterFromID("Hans Kloss"));
			Characters[GetCharacterIndex("Hans Kloss")].dialog.CurrentNode = "ardent_convoy_happy_to_comply";
			LAi_ActorDialog(CharacterFromID("Hans Kloss"),PChar,"convoy_governor_agreed",5.0,5.0);
		break;

		case "convoy_governor_agreed":
			Locations[FindLocation("Willemstad_townhall")].reload.l1.disable = 0;
			DisableFastTravel(false);
			LAi_SetHuberStayType(CharacterFromID("Hans Kloss"));
			LAi_SetActorType(CharacterFromID("Dutch_sergeant"));
            		LAi_ActorGoToLocation(characterFromID("Dutch_sergeant"), "reload", "reload1", "none", "", "", "", 30.0);
			PChar.quest.ardent_convoy = "search_ship";
			Pchar.quest.convoy_leave_residence.win_condition.l1 = "ExitFromLocation";
			PChar.quest.convoy_leave_residence.win_condition.l1.location = PChar.location;
			Pchar.quest.convoy_leave_residence.win_condition = "convoy_leave_residence";
		break;

		case "convoy_leave_residence":
			PChar.name = PChar.quest.original_name;
			PChar.lastname = PChar.quest.original_lastname;
			LAi_SetOfficerType(romance);
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_sergeant"), "Willemstad_port", "goto", "goto12");
			LAi_SetGuardianType(characterFromID("Dutch_sergeant"));
//			Locations[FindLocation("Willemstad_port")].reload.l5.disable = 1;
			Pchar.quest.convoy_back_to_port.win_condition.l1 = "location";
			Pchar.quest.convoy_back_to_port.win_condition.l1.location = "Willemstad_port";
			Pchar.quest.convoy_back_to_port.win_condition = "convoy_back_to_port";
		break;

		case "convoy_back_to_port":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			LAi_SetActorType(CharacterFromID("Dutch_sergeant"));
			characters[GetCharacterIndex("Dutch_sergeant")].Dialog.Filename = "guard_dialog.c";
			Characters[GetCharacterIndex("Dutch_sergeant")].dialog.CurrentNode = "convoy_search";
			LAi_ActorDialog(CharacterFromID("Dutch_sergeant"),PChar,"convoy_searchers_arrive",35.0,35.0);
		break;

		case "convoy_searchers_arrive":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[HOLLAND].fantomModel.m1, "reload", "Falaise_de_fleur_location_01_02");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			LAi_SetActorType(sld);
			sld.id = "search_guard1";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[HOLLAND].fantomModel.m2, "reload", "Falaise_de_fleur_location_01_02");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			LAi_SetActorType(sld);
			sld.id = "search_guard2";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[HOLLAND].fantomModel.m1, "reload", "Falaise_de_fleur_location_01_02");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			LAi_SetActorType(sld);
			sld.id = "search_guard3";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[HOLLAND].fantomModel.m2, "reload", "Falaise_de_fleur_location_01_02");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			LAi_SetActorType(sld);
			sld.id = "search_guard4";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[HOLLAND].fantomModel.m1, "reload", "Falaise_de_fleur_location_01_02");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			LAi_SetActorType(sld);
			sld.id = "search_guard5";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[HOLLAND].fantomModel.m2, "reload", "Falaise_de_fleur_location_01_02");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			LAi_SetActorType(sld);
			sld.id = "search_guard6";

            		LAi_ActorGoToLocation(characterFromID("search_guard1"), "reload", "sea_back", "none", "", "", "", 90.0);
            		LAi_ActorGoToLocation(characterFromID("search_guard2"), "reload", "sea_back", "none", "", "", "", 90.0);
            		LAi_ActorGoToLocation(characterFromID("search_guard3"), "reload", "sea_back", "none", "", "", "", 90.0);
            		LAi_ActorGoToLocation(characterFromID("search_guard4"), "reload", "sea_back", "none", "", "", "", 90.0);
            		LAi_ActorGoToLocation(characterFromID("search_guard5"), "reload", "sea_back", "none", "", "", "", 90.0);
            		LAi_ActorGoToLocation(characterFromID("search_guard6"), "reload", "sea_back", "none", "", "", "", 90.0);
			LAi_SetActorType(CharacterFromID("Dutch_sergeant"));
            		LAi_ActorGoToLocation(characterFromID("Dutch_sergeant"), "reload", "sea_back", "none", "", "", "", 90.0);
//			Locations[FindLocation("Willemstad_port")].reload.l5.disable = 0;
			Locations[FindLocation("Quest_Seadogs")].vcskip = true;

			Pchar.quest.convoy_board_ship.win_condition.l1 = "locator";
			Pchar.quest.convoy_board_ship.win_condition.l1.location = "Willemstad_port";
			Pchar.quest.convoy_board_ship.win_condition.l1.locator_group = "reload";
			Pchar.quest.convoy_board_ship.win_condition.l1.locator = "sea_back";
			Pchar.quest.convoy_board_ship.win_condition = "convoy_board_ship";
		break;

		case "convoy_board_ship":
			StoreOfficers(PChar.id);
			SetOfficersIndex(Pchar, 3, romanceidx);
			LAi_SetStayType(romance);
			ChangeCharacterAddressGroup(romance, "Quest_Seadogs", "rld", "loc2");
			LAi_SetActorType(CharacterFromID("Dutch_sergeant"));
			ChangeCharacterAddress(CharacterFromID("Dutch_sergeant"), "None", "");
			Characters[romanceidx].dialog.CurrentNode = "convoy_aboard_ship";
			DoReloadCharacterToLocation("Quest_Seadogs", "reload", "reload2");
		break;

		case "convoy_romance_removes_cloak":
			if (PChar.sex == "man") SetModelFromID(romance, "Lucia_1");
			else SetModelFromID(romance, PChar.quest.romance_model);
			LAi_SetOfficerType(romance);
			LAi_SetGuardianType(characterFromID("Dutch_sergeant"));
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_sergeant"), "Quest_Seadogs", "reload", "reload1");
			DoQuestReloadToLocation("Quest_Seadogs", "goto", "goto2", "convoy_report_found_romance");
		break;

		case "convoy_report_found_romance":
			romance.quest.equipped_blade = GetCharacterEquipByGroup(romance, BLADE_ITEM_TYPE);
			romance.quest.equipped_gun = GetCharacterEquipByGroup(romance, GUN_ITEM_TYPE);
			RemoveCharacterEquip(romance, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(romance, GUN_ITEM_TYPE);
			LAi_SetActorType(CharacterFromID("Dutch_sergeant"));
			Characters[GetCharacterIndex("Dutch_sergeant")].dialog.CurrentNode = "convoy_found_romance";
			LAi_ActorDialog(CharacterFromID("Dutch_sergeant"),PChar,"convoy_arrest_captain",5.0,5.0);
		break;

		case "convoy_arrest_captain":
			ChangeCharacterAddressGroup(CharacterFromID("Convoy_Captain1"), "Cabin2SJG", "rld", "startloc");
			DoQuestReloadToLocation("Cabin2SJG", "reload", "reload1", "convoy_report_found_romance2");
		break;

		case "convoy_report_found_romance2":
			DisableFastTravel(true);
			LAi_SetActorType(CharacterFromID("Convoy_Captain1"));
			Characters[GetCharacterIndex("Convoy_Captain1")].dialog.CurrentNode = "how_you_got_person_aboard";
			LAi_ActorDialog(CharacterFromID("Convoy_Captain1"),PChar,"convoy_return_to_residence",5.0,5.0);
		break;

		case "convoy_return_to_residence":
			RestoreOfficers(PChar.id);
			LAi_SetOfficerType(romance);
			if (CheckAttribute(romance, "quest.equipped_blade") && romance.quest.equipped_blade != "") EquipCharacterByItem(romance, romance.quest.equipped_blade);
			if (CheckAttribute(romance, "quest.equipped_gun") && romance.quest.equipped_gun != "") EquipCharacterByItem(romance, romance.quest.equipped_gun);
			DeleteAttribute(romance, "quest.equipped_blade");
			DeleteAttribute(romance, "uest.equipped_gun");
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_sergeant"), "Willemstad_townhall", "goto", "goto2");
			if (PChar.sex == "man") GiveModel2Player("Ardent_S", true);
			else GiveModel2Player("Ardent_SF", true);
			PChar.quest.original_name = PChar.name;
			if (CheckAttribute(PChar,"middlename") == true && PChar.middlename != "")
			{
				PChar.quest.original_middlename = PChar.middlename;
				PChar.middlename = "";
			}
			PChar.quest.original_lastname = PChar.lastname;
			PChar.name = "Carlos";
			PChar.lastname = "Ardenta";
			DoQuestReloadToLocation("Willemstad_townhall", "reload", "reload1", "convoy_return_to_residence2");
		break;

		case "convoy_return_to_residence2":
			ChangeCharacterAddress(CharacterFromID("Convoy_Captain1"), "None", "");
			AddPassenger(PChar, CharacterFromID("Convoy_Captain1"), 1);
			Characters[GetCharacterIndex("Hans Kloss")].dialog.CurrentNode = "ardent_convoy_successful";
			EndQuestMovie();
			DisableFastTravel(false);
			Pchar.quest.convoy_final_preparations.win_condition.l1 = "ExitFromLocation";
			PChar.quest.convoy_final_preparations.win_condition.l1.location = "Willemstad_townhall";
			Pchar.quest.convoy_final_preparations.win_condition = "convoy_final_preparations";
		break;

		case "convoy_final_preparations":
			PChar.name = PChar.quest.original_name;
			PChar.lastname = PChar.quest.original_lastname;
			if (CheckAttribute(PChar,"quest.original_middlename"))
			{
				PChar.middlename = PChar.quest.original_middlename;
				DeleteQuestAttribute("original_middlename");
			}
			DeleteQuestAttribute("original_name");
			DeleteQuestAttribute("original_lastname");
			if (CheckQuestAttribute("revenge_type", "kidnap_rescue")) LAi_QuestDelay("convoy_final_preparations2", 1.0);
			else
			{
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.CurrentNode = "convoy_choose_officer_first_time";
				LAi_ActorDialog(romance,PChar,"",5.0,5.0);  // Either exits to "convoy_romance_waits", or sets attribute PChar.quest.convoy_officer and exits to "convoy_final_preparations2"
			}
		break;

		case "convoy_romance_waits":
			LAi_SetStayType(romance);
//			characters[romanceidx].Dialog.Filename = "romance_dialog.c";
//			Characters[romanceidx].dialog.CurrentNode = "convoy_officer_try_again";
		break;

		case "convoy_final_preparations2":
			LAi_SetOfficerType(romance);
			if (CheckQuestAttribute("revenge_type", "kidnap_rescue"))
			{
				GiveShip2Character(PChar, "RN_WarGalleon", "Phaeton", -1, ENGLAND, false, true);
				AddCharacterGoods(PChar, GOOD_WHEAT, 100);
				AddCharacterGoods(PChar, GOOD_RUM, 50);
//				ExchangeCharacterShip(Pchar, characterFromID("Convoy_Captain1"));	// You take the captured convoy ship
				Preprocessor_AddQuestData("ship", PChar.Ship.Name);
				AddQuestRecord("Convoy Strike", 17);
				Preprocessor_Remove("ship");
			}
			else
			{
				ExchangeCharacterShip(Pchar, characterFromID("Javier Balboa"));		// Use Santiago governor as store for your original ship
				GiveShip2Character(PChar, "RN_WarGalleon", "Phaeton", -1, ENGLAND, false, true);
				AddCharacterGoods(PChar, GOOD_WHEAT, 100);
				AddCharacterGoods(PChar, GOOD_RUM, 50);
//				ExchangeCharacterShip(Pchar, characterFromID("Convoy_Captain1"));	// You take the captured convoy ship
				RemoveOfficersIndex(PChar, GetCharacterIndex(PChar.quest.convoy_officer));
				if (HasSubStr(PChar.quest.convoy_officer, "Enc_Officer")) LAi_StoreFantom(CharacterFromId(PChar.quest.convoy_officer)); // Prevent character from being overwritten by another "Enc_Officer"
				RemovePassenger(pchar, characterFromID(PChar.quest.convoy_officer));
				Preprocessor_AddQuestData("ship", PChar.Ship.Name);
				Preprocessor_AddQuestData("officer", GetMyFullName(characterFromID(PChar.quest.convoy_officer)));
				AddQuestRecord("Convoy Strike", 5);
				Preprocessor_Remove("officer");
				Preprocessor_Remove("ship");
				PChar.Ship.crew.quantity = MakeInt(GetMaxCrewQuantity(PChar) / 10);
			}
//			PChar.Ship.crew.quantity = MakeInt(GetMaxCrewQuantity(PChar) / 10);
			SetCompanionIndex(Pchar, 1, GetCharacterIndex("Convoy_Captain2"));
			SetCompanionIndex(Pchar, 2, GetCharacterIndex("Convoy_Captain3"));
			SetCompanionIndex(Pchar, 3, GetCharacterIndex("Convoy_Captain4"));
			SetCharacterRemovable(characterFromID("Convoy_Captain2"), false);
			SetCharacterRemovable(characterFromID("Convoy_Captain3"), false);
			SetCharacterRemovable(characterFromID("Convoy_Captain4"), false);
			AddCharacterGoods(PChar, GOOD_COFFEE, 1500);
			AddCharacterGoods(characterFromID("Convoy_Captain2"), GOOD_COFFEE, 1500);
			AddCharacterGoods(characterFromID("Convoy_Captain3"), GOOD_COFFEE, 2000);
			AddCharacterGoods(characterFromID("Convoy_Captain4"), GOOD_COFFEE, 2000);
			HoistFlag(ENGLAND);
			Pchar.quest.convoy_prepare_to_depart.win_condition.l1 = "location";
			Pchar.quest.convoy_prepare_to_depart.win_condition.l1.location = "Willemstad_port";
			Pchar.quest.convoy_prepare_to_depart.win_condition = "convoy_prepare_to_depart";

			Pchar.quest.convoy_final_briefing.win_condition.l1 = "locator";
			Pchar.quest.convoy_final_briefing.win_condition.l1.location = "Willemstad_port";
			Pchar.quest.convoy_final_briefing.win_condition.l1.locator_group = "reload";
			Pchar.quest.convoy_final_briefing.win_condition.l1.locator = "sea_back";
			Pchar.quest.convoy_final_briefing.win_condition = "convoy_final_briefing";
		break;

		case "convoy_prepare_to_depart":
			Pchar.quest.convoy_battle1.win_condition.l1 = "location";
			Pchar.quest.convoy_battle1.win_condition.l1.location = "";
			Pchar.quest.convoy_battle1.win_condition = "convoy_setup_battle";

			Pchar.quest.convoy_battle2.win_condition.l1 = "location";
			Pchar.quest.convoy_battle2.win_condition.l1.location = "Aruba";
			Pchar.quest.convoy_battle2.win_condition = "convoy_setup_battle";

			Pchar.quest.convoy_battle3.win_condition.l1 = "location";
			Pchar.quest.convoy_battle3.win_condition.l1.location = "Douwesen";
			Pchar.quest.convoy_battle3.win_condition = "convoy_setup_battle";

			Pchar.quest.convoy_battle4.win_condition.l1 = "location";
			Pchar.quest.convoy_battle4.win_condition.l1.location = "Colombia";
			Pchar.quest.convoy_battle4.win_condition = "convoy_setup_battle";

			Pchar.quest.convoy_battle5.win_condition.l1 = "location";
			Pchar.quest.convoy_battle5.win_condition.l1.location = "Oxbay";
			Pchar.quest.convoy_battle5.win_condition = "convoy_setup_battle";

			Pchar.quest.convoy_battle6.win_condition.l1 = "location";
			Pchar.quest.convoy_battle6.win_condition.l1.location = "Redmond";
			Pchar.quest.convoy_battle6.win_condition = "convoy_setup_battle";

			Pchar.quest.convoy_battle7.win_condition.l1 = "location";
			Pchar.quest.convoy_battle7.win_condition.l1.location = "Cuba";
			Pchar.quest.convoy_battle7.win_condition = "convoy_setup_battle";
		break;

		case "convoy_prepare_to_depart_no_infiltrate":
			Pchar.quest.convoy_reset_kloss.win_condition.l1 = "ExitFromLocation";
			PChar.quest.convoy_reset_kloss.win_condition.l1.location = "Willemstad_townhall";
			Pchar.quest.convoy_reset_kloss.win_condition = "convoy_reset_kloss";

			Pchar.quest.convoy_battle1a.win_condition.l1 = "location";
			Pchar.quest.convoy_battle1a.win_condition.l1.location = "Redmond";
			Pchar.quest.convoy_battle1a.win_condition = "convoy_setup_battle_no_infiltrate";

			AddCharacterGoods(characterFromID("Convoy_Captain1"), GOOD_COFFEE, 1500);
			AddCharacterGoods(characterFromID("Convoy_Captain2"), GOOD_COFFEE, 1500);
			AddCharacterGoods(characterFromID("Convoy_Captain3"), GOOD_COFFEE, 2000);
			AddCharacterGoods(characterFromID("Convoy_Captain4"), GOOD_COFFEE, 2000);
		break;

		case "convoy_reset_kloss":
			if (CheckAttribute(PChar,"quest.original_name"))
			{
				PChar.name = PChar.quest.original_name;
				DeleteQuestAttribute("original_name");
			}
			if (CheckAttribute(PChar,"quest.original_lastname"))
			{
				PChar.lastname = PChar.quest.original_lastname;
				DeleteQuestAttribute("original_lastname");
			}
			if (CheckAttribute(PChar,"quest.original_middlename"))
			{
				PChar.middlename = PChar.quest.original_middlename;
				DeleteQuestAttribute("original_middlename");
			}
			Characters[GetCharacterIndex("Hans Kloss")].dialog.CurrentNode = "First time";
		break;

		case "convoy_final_briefing":
			SetModelFromID(romance, PChar.quest.romance_model);
			DeleteQuestAttribute("romance_model");
			if (!isofficer(romance)) SetOfficersIndex(Pchar, 3, romanceidx);	// Just in case you've somehow managed to replace Lucía / Edmundo
			ChangeCharacterAddressGroup(romance, GetCharacterShipCabin(PChar), "rld", "startloc");
			DoQuestReloadToLocation(GetCharacterShipCabin(PChar), "reload", "reload1", "convoy_final_briefing2");
		break;

		case "convoy_final_briefing2":
			if (PChar.sex == "woman")
			{
				GiveModel2Player("Ardent_F", true);
				logit(TranslateString("","Finally! Out of that ill-fitting uniform and back into my proper clothes."));
			}
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_after_governor";
			LAi_ActorDialog(romance,PChar,"convoy_final_briefing3",5.0,5.0);

			setCharacterShipLocation(characterFromID("Javier Balboa"), "Santiago_port");
		break;

		case "convoy_final_briefing3":
			LAi_SetOfficerType(romance);
			QuestToSeaLogin_PrepareLoc("Curacao", "reload", "reload_1", false);
			QuestToSeaLogin_Launch();
//			if(CheckAttribute(PChar, "quest.convoy_officer"))
//			{
//				AddPassenger(PChar, CharacterFromID(PChar.quest.convoy_officer), 0);
//				SetCharacterRemovable(characterFromID(PChar.quest.convoy_officer), false);
//			}
			Characters[GetCharacterIndex("Convoy_Captain2")].fantomtype = "trade";
			character_SetCompanionEnemyEnable(characterFromID("Convoy_Captain2"), true);
			character_SetCompanionEnemyEnable(characterFromID("Convoy_Captain3"), true);
			character_SetCompanionEnemyEnable(characterFromID("Convoy_Captain4"), true);
		break;

		case "convoy_setup_battle":
			ChangeCharacterAddress(CharacterFromID("Dutch_sergeant"), "None", "");
			LAi_SetOfficerType(romance);
			LAi_SetImmortal(romance, true);

			Pchar.quest.convoy_battle1.over = "yes";
			Pchar.quest.convoy_battle2.over = "yes";
			Pchar.quest.convoy_battle3.over = "yes";
			Pchar.quest.convoy_battle4.over = "yes";
			Pchar.quest.convoy_battle5.over = "yes";
			Pchar.quest.convoy_battle6.over = "yes";
			Pchar.quest.convoy_battle7.over = "yes";
			bQuestDisableMapEnter = true;
			PChar.quest.convoy_battle_location = PChar.location;
			Island_SetReloadEnableGlobal(PChar.quest.convoy_battle_location, false);

			RemoveCharacterCompanion(Pchar, characterFromID("Convoy_Captain2"));
			SetCharacterRemovable(characterFromID("Convoy_Captain2"), true);
			RemoveCharacterCompanion(Pchar, characterFromID("Convoy_Captain3"));
			SetCharacterRemovable(characterFromID("Convoy_Captain3"), true);
			RemoveCharacterCompanion(Pchar, characterFromID("Convoy_Captain4"));
			SetCharacterRemovable(characterFromID("Convoy_Captain4"), true);

			SetCharacterRelationBoth(GetCharacterIndex("Convoy_Captain2"),GetMainCharacterIndex(),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Convoy_Captain3"),GetMainCharacterIndex(),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Convoy_Captain4"),GetMainCharacterIndex(),RELATION_ENEMY);

			Group_CreateGroup("Downing Convoy");
			Group_AddCharacter("Downing Convoy", "Convoy_Captain2");
			Group_AddCharacter("Downing Convoy", "Convoy_Captain3");
			Group_AddCharacter("Downing Convoy", "Convoy_Captain4");
			Group_SetGroupCommander("Downing Convoy", "Convoy_Captain2");

			Group_SetAddress("Downing Convoy", Characters[GetMainCharacterIndex()].location, "", "");
			if (Characters[GetMainCharacterIndex()].location == "") Sea_LoginGroupNow("Downing Convoy");

			Group_SetPursuitGroup("Downing Convoy", PLAYER_GROUP);
			Group_SetTaskAttack("Downing Convoy", PLAYER_GROUP, true);
			Group_LockTask("Downing Convoy");
			characters[GetCharacterIndex("Convoy_Captain2")].nosurrender = 2;
//			DeleteAttribute(CharacterFromID("Convoy_Captain3"), "questchar");	// Make the captain a regular character who can be hired, ransomed or released
//			DeleteAttribute(CharacterFromID("Convoy_Captain4"), "questchar");

//			UpdateRelations();
			SetRMRelation(characterFromID("Convoy_Captain2"), SPAIN, REL_WAR);
			SetRMRelation(characterFromID("Convoy_Captain3"), SPAIN, REL_WAR);
			SetRMRelation(characterFromID("Convoy_Captain4"), SPAIN, REL_WAR);
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_ENEMY);
			UpdateRelations();
			HoistFlag(SPAIN);
			Characters[GetCharacterIndex("Convoy_Captain2")].recognized = true;
			Characters[GetCharacterIndex("Convoy_Captain3")].recognized = true;
			Characters[GetCharacterIndex("Convoy_Captain4")].recognized = true;

			Pchar.quest.convoy_battle_over.win_condition.l1 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l1.character = "Convoy_Captain2";
			Pchar.quest.convoy_battle_over.win_condition.l2 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l2.character = "Convoy_Captain3";
			Pchar.quest.convoy_battle_over.win_condition.l3 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l3.character = "Convoy_Captain4";
			Pchar.quest.convoy_battle_over.win_condition = "convoy_battle_over";
			if(!CheckQuestAttribute("revenge_type", "kidnap_rescue"))
			{
				Pchar.quest.convoy_report_to_santiago.win_condition.l1 = "location";
				PChar.quest.convoy_report_to_santiago.win_condition.l1.character = Pchar.id;
				Pchar.quest.convoy_report_to_santiago.win_condition.l1.location = "Santiago_townhall";
				Pchar.quest.convoy_report_to_santiago.win_condition = "convoy_report_to_santiago";
			}
		break;

		case "convoy_setup_battle_no_infiltrate":
			ChangeCharacterAddress(CharacterFromID("Dutch_sergeant"), "None", "");
			if (PChar.sex == "woman" && PChar.model == "Ardent_SF")
			{
				GiveModel2Player("Ardent_F", true);
				logit(TranslateString("","Finally! Out of that ill-fitting uniform and back into my proper clothes."));
			}
			bQuestDisableMapEnter = true;
			PChar.quest.convoy_battle_location = PChar.location;
			Island_SetReloadEnableGlobal(PChar.quest.convoy_battle_location, false);

			Group_CreateGroup("Downing Convoy");
			Group_AddCharacter("Downing Convoy", "Convoy_Captain1");
			Group_AddCharacter("Downing Convoy", "Convoy_Captain2");
			Group_AddCharacter("Downing Convoy", "Convoy_Captain3");
			Group_AddCharacter("Downing Convoy", "Convoy_Captain4");
			Group_SetGroupCommander("Downing Convoy", "Convoy_Captain1");
			Group_SetAddress("Downing Convoy", Characters[GetMainCharacterIndex()].location, "", "");
			Sea_LoginGroupNow("Downing Convoy");
			Group_SetPursuitGroup("Downing Convoy", PLAYER_GROUP);
			Group_SetTaskAttack("Downing Convoy", PLAYER_GROUP, true);
			Group_LockTask("Downing Convoy");
			characters[GetCharacterIndex("Convoy_Captain1")].nosurrender = 2;
			characters[GetCharacterIndex("Convoy_Captain2")].nosurrender = 2;
//			DeleteAttribute(CharacterFromID("Convoy_Captain3"), "questchar");	// Make the captain a regular character who can be hired, ransomed or released
//			DeleteAttribute(CharacterFromID("Convoy_Captain4"), "questchar");

			SetRMRelation(characterFromID("Convoy_Captain1"), SPAIN, REL_WAR);
			SetRMRelation(characterFromID("Convoy_Captain2"), SPAIN, REL_WAR);
			SetRMRelation(characterFromID("Convoy_Captain3"), SPAIN, REL_WAR);
			SetRMRelation(characterFromID("Convoy_Captain4"), SPAIN, REL_WAR);
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_ENEMY);
			HoistFlag(SPAIN);

			Characters[GetCharacterIndex("Convoy_Captain1")].recognized = true;
			Characters[GetCharacterIndex("Convoy_Captain2")].recognized = true;
			Characters[GetCharacterIndex("Convoy_Captain3")].recognized = true;
			Characters[GetCharacterIndex("Convoy_Captain4")].recognized = true;

			Pchar.quest.convoy_battle_over.win_condition.l1 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l1.character = "Convoy_Captain1";
			Pchar.quest.convoy_battle_over.win_condition.l2 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l2.character = "Convoy_Captain2";
			Pchar.quest.convoy_battle_over.win_condition.l3 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l3.character = "Convoy_Captain3";
			Pchar.quest.convoy_battle_over.win_condition.l4 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l4.character = "Convoy_Captain4";
			Pchar.quest.convoy_battle_over.win_condition = "convoy_battle_over";
		break;

		case "convoy_battle_over":
			PChar.quest.ardent_convoy = "battle_over";
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_FRIEND);
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal(PChar.quest.convoy_battle_location, true);
			DeleteQuestAttribute("convoy_battle_location");
			AddMoneyToCharacter(pchar, 400000 + rand(200000));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 5000);
				AddPartyExpChar(PChar, "", 500);
				AddPartyExpChar(PChar, "Sailing", 500);
			}
			else AddPartyExp(PChar, 6000);

			if(!LAi_IsDead(romance) && CheckAttribute(romance, "quest.old_abordagemode"))
			{
				romance.AbordageMode = sti(romance.quest.old_abordagemode);
				DeleteAttribute(romance, "quest.old_abordagemode");
			}

//			if(CheckQuestAttribute("revenge_type", "kidnap_rescue") && !CheckQuestAttribute("kidnap_convoy", "true"))
			if(CheckQuestAttribute("revenge_type", "kidnap_rescue"))
			{
				if (LAi_IsDead(romance))
				{
					Preprocessor_AddQuestData("romance", GetMyName(romance));
					AddQuestRecord("Convoy Strike", 20);
					Preprocessor_Remove("romance");
				}
				else
				{
					AddQuestRecord("Convoy Strike", 18);
					PChar.quest.convoy_romance_dead.over = "yes";
					PChar.quest.romance_dead.win_condition.l1 = "NPC_Death";
					PChar.quest.romance_dead.win_condition.l1.character = romance.id;
					PChar.quest.romance_dead.win_condition = "romance_dead";
				}
				CloseQuestHeader("Convoy Strike");
				SetCharacterRemovable(romance, true);
			}
			else
			{
				if(!LAi_IsDead(romance) && !CheckAttribute(PChar, "quest.spain_betrayal"))
				{
					LAi_SetActorType(romance);
					LAi_ActorFollowEverywhere(romance, "", 10.0);
					LAi_SetImmortal(romance, false);
					AddQuestRecord("Convoy Strike", 6);
					Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "convoy_return"; // Exits to "convoy_get_ship_back" if you are in command of correct type of ship
				}
				else
				{
					Preprocessor_AddQuestData("governor", GetMySimpleName(characterFromID("Javier Balboa")));
					if (LAi_IsDead(romance))
					{
						Preprocessor_AddQuestData("romance", GetMyName(romance));
						AddQuestRecord("Convoy Strike", 13);
					}
					else
					{
						AddQuestRecord("Convoy Strike", 22);
						Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "spain_betrayal";
					}
					CloseQuestHeader("Convoy Strike");
					Preprocessor_Remove("governor");
				}
				ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
				LAi_SetHuberStayType(CharacterFromID("Javier Balboa"));
			}

//			if (!LAi_IsDead(CharacterFromID("Convoy_Captain1")))
//			{
//				DeleteAttribute(CharacterFromID("Convoy_Captain1"), "questchar");	// Make the captain a regular character who can be hired, ransomed or released
//			}

			PChar.quest.mona_attack_triggers.win_condition.l1 = "Timer";
			PChar.quest.mona_attack_triggers.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.mona_attack_triggers.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.mona_attack_triggers.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.mona_attack_triggers.win_condition = "mona_attack_triggers";
		break;

		case "convoy_report_to_santiago":
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto2");
			RemoveOfficersIndex(pchar, romanceidx);
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "convoy_get_ship_back":
			AddQuestRecord("Convoy Strike", 7);
			if(CheckAttribute(PChar, "quest.convoy_officer"))
			{
				AddPassenger(PChar, CharacterFromID(PChar.quest.convoy_officer), 0);
				SetCharacterRemovable(characterFromID(PChar.quest.convoy_officer), true);
			}
//			if (CheckQuestAttribute("kidnap_convoy", "true")) DeleteQuestAttribute("kidnap_convoy");
			ExchangeCharacterShip(Pchar, characterFromID("Javier Balboa")); // Captured ship goes to Santiago governor, you get your own ship
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_propose_trade";
			LAi_ActorDialog(romance,PChar,"convoy_governor_agrees_trade",5.0,5.0);
		break;

		case "convoy_governor_agrees_trade":
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "convoy_interesting_idea";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"convoy_wait_a_day",5.0,5.0);
		break;

		case "convoy_wait_a_day":
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
			DoQuestReloadToLocation("Santiago_townhall", "reload", "reload2", "convoy_next_day_townhall");
		break;

		case "convoy_next_day_townhall":
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10, 0);
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "convoy_next_day";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"convoy_romance_asks_for_ship",1.0,1.0);
		break;

		case "convoy_romance_asks_for_ship":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_ask_to_take_ship";
			LAi_ActorDialog(romance,PChar,"convoy_governor_agrees_ship",5.0,5.0);
		break;

		case "convoy_governor_agrees_ship":
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "convoy_agree_ship";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"convoy_ready_for_trade_deal",1.0,1.0);
		break;

		case "convoy_ready_for_trade_deal":
			LAi_SetHuberStayType(CharacterFromID("Javier Balboa"));
//			if(!isofficer(romance)) SetOfficersIndex(Pchar, 3, romanceidx);
//			LAi_SetOfficerType(romance);
			Preprocessor_AddQuestData("ship", Characters[GetCharacterIndex("Javier Balboa")].Ship.Name);
			Preprocessor_AddQuestData("romance", GetMyName(romance));
			AddQuestRecord("Convoy Strike", 8);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("ship");
			RemoveOfficersIndex(pchar, romanceidx);
			RemovePassenger(pchar, romance);

			ExchangeCharacterShip(characterFromID("Javier Balboa"), romance); // Captured ship goes to "romance"
			setCharacterShipLocation(romance, "Santiago_port");

			if(SetCompanionIndex(PChar,-1, romanceidx) == romanceidx)
			{
				Locations[FindLocation("Santiago_town_01")].reload.l2.disable = 1;	// Lock the town exit,
				Locations[FindLocation("Santiago_port")].reload.l5.disable = 1;		// the port exit,
				bQuestDisableSeaEnter = true;						// and the sea.
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.CurrentNode = "convoy_free_slot";
				LAi_ActorDialog(romance,PChar,"convoy_goto_Santiago_Shipyard",5.0,5.0);
			}
			else
			{
//				ExchangeCharacterShip(characterFromID("Javier Balboa"), romance); // Captured ship goes to "romance"
				if (HasSubStr(PChar.quest.convoy_officer, "Enc_Officer")) LAi_UnStoreFantom(CharacterFromID(PChar.quest.convoy_officer)); // Cancel protection
				DeleteQuestAttribute("convoy_officer");
				LAi_SetActorType(romance);
				LAi_ActorFollowEverywhere(romance, "", 10.0);
			}
			PChar.quest.ardent_convoy = "trade_proposal";
			Pchar.quest.Willemstad_residence2.win_condition.l1 = "location";
			PChar.quest.Willemstad_residence2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Willemstad_residence2.win_condition.l1.location = "Willemstad_townhall";
			Pchar.quest.Willemstad_residence2.win_condition = "convoy_Willemstad_residence2";

			if (PChar.sex == "man")
			{
				PChar.quest.convoy_romance_into_dress.win_condition.l1 = "location";
				PChar.quest.convoy_romance_into_dress.win_condition.l1.location = "Cuba";
				PChar.quest.convoy_romance_into_dress.win_condition = "convoy_romance_into_dress";
			}

			Pchar.quest.convoy_reset_governor.win_condition.l1 = "ExitFromLocation";
			PChar.quest.convoy_reset_governor.win_condition.l1.location = "Santiago_townhall";
			Pchar.quest.convoy_reset_governor.win_condition = "reset_governor";
		break;

		case "convoy_romance_into_dress":
			PChar.quest.romance_model = romance.model;
			SetModelFromID(romance, "Lucia_1");
		break;

		case "convoy_goto_Santiago_Shipyard":
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			Pchar.quest.Santiago_Shipyard.win_condition.l1 = "location";
			Pchar.quest.Santiago_Shipyard.win_condition.l1.location = "Santiago_shipyard";
			Pchar.quest.Santiago_Shipyard.win_condition = "convoy_Santiago_Shipyard2";
		break;

		case "convoy_Santiago_Shipyard2":
			Pchar.quest.back_in_Santiago_port.win_condition.l1 = "location";
			Pchar.quest.back_in_Santiago_port.win_condition.l1.location = "Santiago_port";
			Pchar.quest.back_in_Santiago_port.win_condition = "convoy_back_in_Santiago_port";
		break;

		case "convoy_back_in_Santiago_port":
			if(SetCompanionIndex(PChar,-1, romanceidx) == romanceidx)
			{
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.CurrentNode = "convoy_free_slot2";
				LAi_ActorDialog(romance,PChar,"convoy_goto_Santiago_Shipyard",5.0,5.0);
			}
			else
			{
//				ExchangeCharacterShip(characterFromID("Javier Balboa"), romance); // Captured ship goes to "romance"
				if (HasSubStr(PChar.quest.convoy_officer, "Enc_Officer")) LAi_UnStoreFantom(CharacterFromID(PChar.quest.convoy_officer)); // Cancel protection
				DeleteQuestAttribute("convoy_officer");
				Locations[FindLocation("Santiago_town_01")].reload.l2.disable = 0;	// Unlock the town exit,
				Locations[FindLocation("Santiago_port")].reload.l5.disable = 0;		// the port exit,
				bQuestDisableSeaEnter = false;						// and the sea.
				LAi_SetActorType(romance);
				LAi_ActorFollowEverywhere(romance, "", 10.0);
			}
		break;

		case "convoy_Willemstad_residence2":
			ChangeCharacterAddressGroup(romance, "Willemstad_townhall", "goto", "goto1");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
		break;

		case "convoy_romance_interrupts_recognition":	// Triggered by dialog with Hans Kloss, governor of Curacao
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_interrupt_recognition";
			LAi_ActorDialog(romance,PChar,"convoy_give_ship_to_kloss",5.0,5.0);
		break;

		case "convoy_give_ship_to_kloss":
			LAi_SetActorType(CharacterFromID("Hans Kloss"));
			Characters[GetCharacterIndex("Hans Kloss")].dialog.CurrentNode = "ardent_convoy_receive_ship";
			LAi_ActorDialog(CharacterFromID("Hans Kloss"),PChar,"convoy_give_trade_letter",5.0,5.0);
			RemoveCharacterCompanion(Pchar, romance);
			AddPassenger(PChar, romance, 0);
			SetOfficersIndex(Pchar, 3, romanceidx);
			DeleteAttribute(romance, "ship");
		break;

		case "convoy_give_trade_letter":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_give_trade_letter";
			LAi_ActorDialog(romance,PChar,"convoy_farewell_to_kloss",5.0,5.0);
		break;

		case "convoy_farewell_to_kloss":
			LAi_SetActorType(CharacterFromID("Hans Kloss"));
			Characters[GetCharacterIndex("Hans Kloss")].dialog.CurrentNode = "ardent_convoy_trade_accepted";
			LAi_ActorDialog(CharacterFromID("Hans Kloss"),PChar,"convoy_reset_kloss2",5.0,5.0);
			if (PChar.sex == "man")
			{
				PChar.quest.convoy_reset_romance.win_condition.l1 = "location";
				PChar.quest.convoy_reset_romance.win_condition.l1.location = "Curacao";
				PChar.quest.convoy_reset_romance.win_condition = "convoy_reset_romance";
			}
		break;

		case "convoy_reset_kloss2":
			LAi_SetHuberStayType(CharacterFromID("Hans Kloss"));
			LAi_SetOfficerType(romance);
			AddQuestRecord("Convoy Strike", 9);
			PChar.quest.ardent_convoy = "return_from_trade";
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "convoy_return_from_trade"; // When you talk to governor about trade deal, exits to "convoy_ending" or "convoy_ending_goodbye"
			Pchar.quest.convoy_santiago_residence_finale.win_condition.l1 = "location";
			PChar.quest.convoy_santiago_residence_finale.win_condition.l1.character = Pchar.id;
			Pchar.quest.convoy_santiago_residence_finale.win_condition.l1.location = "Santiago_townhall";
			Pchar.quest.convoy_santiago_residence_finale.win_condition = "convoy_santiago_residence_finale";
		break;

		case "convoy_reset_romance":
			SetModelFromID(romance, PChar.quest.romance_model);
			DeleteQuestAttribute("romance_model");
		break;

		case "convoy_santiago_residence_finale":
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 1;
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto2");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);

			Pchar.quest.convoy_reset_governor2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.convoy_reset_governor2.win_condition.l1.location = "Santiago_townhall";
			Pchar.quest.convoy_reset_governor2.win_condition = "reset_governor";
		break;

		case "convoy_ending":	// Triggered by dialog with "Javier Balboa"
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_flattery";
			LAi_ActorDialog(romance,PChar,"convoy_ending2",5.0,5.0);
		break;

		case "convoy_ending2":
			Preprocessor_AddQuestData("fatherinlaw", GetMySimpleName(CharacterFromID("Javier Balboa")));
			Preprocessor_AddQuestData("romance", GetMyName(romance));
			AddQuestRecord("Convoy Strike", 10);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("fatherinlaw");
			CloseQuestHeader("Convoy Strike");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(PChar, "", 100);
				AddPartyExpChar(pchar, "Commerce", 100);
			}
			else {AddPartyExp(pchar, 1200);}
//			LAi_SetHuberStayType(CharacterFromID("Javier Balboa"));
			LAi_SetOfficerType(romance);
			SetCharacterRemovable(romance, true);
			DeleteAttribute(PChar, "quest.ardent_convoy");
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 0;
			DisableFastTravel(false);
			PChar.quest.convoy_romance_dead.over = "yes";
			PChar.quest.romance_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.romance_dead.win_condition.l1.character = romance.id;
			PChar.quest.romance_dead.win_condition = "romance_dead";
		break;

		case "convoy_ending_goodbye":	// Triggered by dialog with "Javier Balboa"
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_done_wrong";
			LAi_ActorDialog(romance,PChar,"convoy_ending_goodbye2",5.0,5.0);
		break;

		case "convoy_ending_goodbye2":
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 0;
			DisableFastTravel(false);
			SetCharacterRemovable(romance, true);
			RemoveOfficersIndex(PChar, romanceidx);
			RemovePassenger(PChar, romance);
			LAi_SetCitizenType(romance);
			if(CheckAttribute(characterFromID(PChar.quest.romance), "married") && characters[getCharacterIndex(PChar.quest.romance)].married == MR_MARRIED && characters[getCharacterIndex(PChar.quest.romance)].married.id == PChar.id)
			{
				characters[romanceidx].Dialog.Filename = "Gov MR_dialog.c";
				characters[romanceidx].Dialog.CurrentNode = "First time";
			}
			else
			{
//				LAi_SetActorType(romance);
//          			LAi_ActorGoToLocation(romance, "reload", "reload2", "none", "", "", "", 10.0);
				Pchar.quest.convoy_ending_remove_romance.win_condition.l1 = "ExitFromLocation";
				PChar.quest.convoy_ending_remove_romance.win_condition.l1.location = PChar.location;
				Pchar.quest.convoy_ending_remove_romance.win_condition = "convoy_ending_remove_romance";
			}
			Preprocessor_AddQuestData("fatherinlaw", GetMySimpleName(CharacterFromID("Javier Balboa")));
			Preprocessor_AddQuestData("romance", GetMyName(romance));
			AddQuestRecord("Convoy Strike", 16);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("fatherinlaw");
			CloseQuestHeader("Convoy Strike");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(PChar, "", 100);
				AddPartyExpChar(pchar, "Commerce", 100);
			}
			else {AddPartyExp(pchar, 1200);}
//			LAi_SetHuberStayType(CharacterFromID("Javier Balboa"));
			DeleteAttribute(PChar, "quest.ardent_convoy");
			PChar.quest.convoy_romance_dead.over = "yes";
			PChar.quest.romance_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.romance_dead.win_condition.l1.character = romance.id;
			PChar.quest.romance_dead.win_condition = "romance_dead";
		break;

		case "convoy_ending_remove_romance":
			LAi_SetActorType(romance);
			ChangeCharacterAddress(romance, "None", "");
		break;

		case "convoy_romance_dead":
			PChar.quest.betrayed_spain.over = "yes";
			PChar.quest.betrayed_spain1.over = "yes";
			if (CheckQuestAttribute("revenge_type", "kidnap_rescue"))
			{
				Preprocessor_AddQuestData("romance", GetMyName(romance));
				AddQuestRecord("Convoy Strike", 19);
				Preprocessor_Remove("romance");
			}
			else
			{
				Preprocessor_AddQuestData("romance", GetMyName(romance));
				Preprocessor_AddQuestData("governor", GetMySimpleName(CharacterFromID("Javier Balboa")));
				AddQuestRecord("Convoy Strike", 11);
				Preprocessor_Remove("governor");
				Preprocessor_Remove("romance");
				Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "romance_dead";
			}
		break;

		case "romance_dead":
			PChar.quest.betrayed_spain.over = "yes";
			PChar.quest.betrayed_spain1.over = "yes";
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "romance_dead";
		break;

		case "meet_Mary_Wood":
			if (!LAi_IsDead(characterFromID("Mary Wood")) && Characters[GetCharacterIndex("Mary Wood")].location == "Tortuga_Tavern")
			{
				LAi_ActorDialog(CharacterFromID("Mary Wood"),PChar,"",5.0,5.0);
			}
			else traceandlog("Mary Wood is not here");
		break;

		case "mona_attack_triggers":
			PChar.quest.mona_attack_sanjuan.win_condition.l1 = "location"; // Check for arrival at San Juan
			PChar.quest.mona_attack_sanjuan.win_condition.l1.location = "Muelle_port";
			PChar.quest.mona_attack_sanjuan.win_condition = "mona_attack_info_port";

			PChar.quest.mona_attack_santodomingo.win_condition.l1 = "location"; // Check for arrival at Santo Domingo
			PChar.quest.mona_attack_santodomingo.win_condition.l1.location = "Santo_Domingo_port";
			PChar.quest.mona_attack_santodomingo.win_condition = "mona_attack_info_port";

			PChar.quest.mona_attack_tortuga.win_condition.l1 = "location"; // Check for arrival at Tortuga
			PChar.quest.mona_attack_tortuga.win_condition.l1.location = "Tortuga_port";
			PChar.quest.mona_attack_tortuga.win_condition = "mona_attack_info_port";

			PChar.quest.mona_attack_portroyale.win_condition.l1 = "location"; // Check for arrival at Port Royale
			PChar.quest.mona_attack_portroyale.win_condition.l1.location = "Redmond_port";
			PChar.quest.mona_attack_portroyale.win_condition = "mona_attack_info_port";

			PChar.quest.mona_attack_nevis.win_condition.l1 = "location"; // Check for arrival at Nevis Pirate
			PChar.quest.mona_attack_nevis.win_condition.l1.location = "QC_port";
			PChar.quest.mona_attack_nevis.win_condition = "mona_attack_info_port";

			PChar.quest.mona_attack_turks.win_condition.l1 = "location"; // Check for arrival at Turks Island
			PChar.quest.mona_attack_turks.win_condition.l1.location = "Turks_port";
			PChar.quest.mona_attack_turks.win_condition = "mona_attack_info_port";

			Locations[FindLocation("Tortuga_port")].vcskip = true;
		break;

		case "mona_attack_info_port":
			PChar.quest.mona_attack_sanjuan.over = "yes";
			PChar.quest.mona_attack_santodomingo.over = "yes";
			PChar.quest.mona_attack_tortuga.over = "yes";
			PChar.quest.mona_attack_portroyale.over = "yes";
			PChar.quest.mona_attack_nevis.over = "yes";
			PChar.quest.mona_attack_turks.over = "yes";
			switch(PChar.location)
			{
				case "Muelle_port":
					PChar.quest.mona_attack.pirate_locator = "goto9";
					PChar.quest.mona_attack.tavern = "Muelle_Tavern";
					PChar.quest.mona_attack.tavern_seat1_group = "sit2";
					PChar.quest.mona_attack.tavern_seat1_locator = "sit3";
					PChar.quest.mona_attack.tavern_seat2_group = "sit";
					PChar.quest.mona_attack.tavern_seat2_locator = "sit7";
					PChar.quest.mona_attack.tavern_stand_locator = "goto6";
				break;

				case "Santo_Domingo_port":
					PChar.quest.mona_attack.pirate_locator = "goto18";
					PChar.quest.mona_attack.tavern = "Santo_Domingo_Tavern";
					PChar.quest.mona_attack.tavern_seat1_group = "sit";
					PChar.quest.mona_attack.tavern_seat1_locator = "sit12";
					PChar.quest.mona_attack.tavern_seat2_group = "sit";
					PChar.quest.mona_attack.tavern_seat2_locator = "sit13";
					PChar.quest.mona_attack.tavern_stand_locator = "goto20";
				break;

				case "Tortuga_port":
					PChar.quest.mona_attack.pirate_locator = "goto19";
					PChar.quest.mona_attack.tavern = "Tortuga_Tavern";
					PChar.quest.mona_attack.tavern_seat1_group = "sit";
					PChar.quest.mona_attack.tavern_seat1_locator = "sit2";
					PChar.quest.mona_attack.tavern_seat2_group = "sit";
					PChar.quest.mona_attack.tavern_seat2_locator = "sit8";
					PChar.quest.mona_attack.tavern_stand_locator = "goto2";
				break;

				case "Redmond_port":
					PChar.quest.mona_attack.pirate_locator = "goto_17";
					PChar.quest.mona_attack.tavern = "Redmond_Tavern";
					PChar.quest.mona_attack.tavern_seat1_group = "sit";
					PChar.quest.mona_attack.tavern_seat1_locator = "sit12";
					PChar.quest.mona_attack.tavern_seat2_group = "sit";
					PChar.quest.mona_attack.tavern_seat2_locator = "sit13";
					PChar.quest.mona_attack.tavern_stand_locator = "goto20";
				break;

				case "QC_port":
					PChar.quest.mona_attack.pirate_locator = "goto4";
					PChar.quest.mona_attack.tavern = "QC_Tavern";
					PChar.quest.mona_attack.tavern_seat1_group = "sit";
					PChar.quest.mona_attack.tavern_seat1_locator = "sit4";
					PChar.quest.mona_attack.tavern_seat2_group = "sit";
					PChar.quest.mona_attack.tavern_seat2_locator = "sit8";
					PChar.quest.mona_attack.tavern_stand_locator = "goto6";
// Locators standing by bar: goto/goto2, goto/goto3
				break;

				case "Turks_port":
					PChar.quest.mona_attack.pirate_locator = "goto8";
					PChar.quest.mona_attack.tavern = "Turks_Tavern";
					PChar.quest.mona_attack.tavern_seat1_group = "sit";
					PChar.quest.mona_attack.tavern_seat1_locator = "sit5";
					PChar.quest.mona_attack.tavern_seat2_group = "candles";
					PChar.quest.mona_attack.tavern_seat2_locator = "sit6";
					PChar.quest.mona_attack.tavern_stand_locator = "goto1";
				break;
			}

			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			DeleteAttribute(&Locations[FindLocation("Tortuga_port")],"vcskip");
			Locations[FindLocation(PChar.quest.mona_attack.tavern)].vcskip = true;
			ChangeCharacterAddressGroup(characterfromID("Wilfred Roscoe"), PChar.location, "goto", PChar.quest.mona_attack.pirate_locator);
			LAi_SetActorType(PChar);
			LAi_SetActorType(characterfromID("Wilfred Roscoe"));
			LAi_ActorFollow(characterFromID("Wilfred Roscoe"), PChar, "", 5.0);
			LAi_ActorFollow(PChar, characterFromID("Wilfred Roscoe"), "mona_attack_roscoe_meeting", 5.0);
		break;

		case "mona_attack_roscoe_meeting":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterfromID("Wilfred Roscoe"));
			Characters[GetCharacterIndex("Wilfred Roscoe")].dialog.CurrentNode = "mona_attack_meeting_in_port";
			LAi_ActorDialog(characterfromID("Wilfred Roscoe"),PChar,"mona_attack_tavern_chat",30.0,30.0);
		break;

		case "mona_attack_tavern_chat":
			EndQuestMovie();
			DisableFastTravel(false);
			if (PChar.location == "QC_port" && Characters[GetCharacterIndex("Armand Delacroix")].location == "QC_tavern") // If Armand Delacroix is already sitting in the tavern, you and Wilfred Roscoe need to stand by the bar
			{
				ChangeCharacterAddressGroup(characterFromID("Wilfred Roscoe"), "QC_tavern", "goto", "goto2");
				DoQuestReloadToLocation("QC_tavern", "goto", "goto3", "mona_attack_tavern_chat2");
			}
			else
			{
				ChangeCharacterAddressGroup(characterFromID("Wilfred Roscoe"), PChar.quest.mona_attack.tavern, PChar.quest.mona_attack.tavern_seat2_group, PChar.quest.mona_attack.tavern_seat2_locator);
				DoQuestReloadToLocation(PChar.quest.mona_attack.tavern, PChar.quest.mona_attack.tavern_seat1_group, PChar.quest.mona_attack.tavern_seat1_locator, "mona_attack_tavern_chat2");
			}
		break;

		case "mona_attack_tavern_chat2":
			LAi_SetActorType(PChar);
			if (PChar.location != Characters[GetCharacterIndex("Armand Delacroix")].location) // If Armand Delacroix is sitting in the tavern then you and Wilfred Roscoe are not sitting
			{
				LAi_ActorSetSitMode(PChar);
				LAi_SetSitType(characterFromID("Wilfred Roscoe"));
			}
			Characters[GetCharacterIndex("Wilfred Roscoe")].dialog.CurrentNode = "mona_attack_tavern1";
			LAi_ActorDialogNow(PChar, characterFromID("Wilfred Roscoe"), "mona_attack_end_tavern_chat", 1.0);
		break;

		case "mona_attack_end_tavern_chat":
			SetQuestHeader("Isla Mona Attack");
			AddQuestRecord("Isla Mona Attack", 1);
			Islands[FindIsland("IslaMona")].smuggling_nation = FRANCE;
//			CaptureTownForNation("Khael Roa", FRANCE);
			LAi_SetPlayerType(PChar);
			if (PChar.location != Characters[GetCharacterIndex("Armand Delacroix")].location) ChangeCharacterAddressGroup(PChar, PChar.quest.mona_attack.tavern, "goto", PChar.quest.mona_attack.tavern_stand_locator);
			Pchar.quest.mona_attack_roscoe_leaves.win_condition.l1 = "ExitFromLocation";
			PChar.quest.mona_attack_roscoe_leaves.win_condition.l1.location = PChar.location;
			Pchar.quest.mona_attack_roscoe_leaves.win_condition = "mona_attack_roscoe_leaves";
			Pchar.quest.mona_attack_setup.win_condition.l1 = "location";
			Pchar.quest.mona_attack_setup.win_condition.l1.location = "IslaMona";
			Pchar.quest.mona_attack_setup.win_condition = "mona_attack_setup";
		break;

		case "mona_attack_roscoe_leaves":
			LAi_SetActorType(characterFromID("Wilfred Roscoe"));
			ChangeCharacterAddress(characterFromID("Wilfred Roscoe"), "None", "");
			DeleteAttribute(&Locations[FindLocation(PChar.quest.mona_attack.tavern)],"vcskip");
		break;

		case "mona_attack_setup":
			for(n = 1; n <=20; n++)
			{
				ChangeCharacterAddress(characterFromID("Mona_patrol_" + n), "None", "");
			}
			bQuestDisableMapEnter = true;
//			PChar.quest.mona_attack_battle_location = PChar.location;
//			Island_SetReloadEnableGlobal(PChar.quest.mona_attack_battle_location, false);
			Group_CreateGroup("French_frigate");
			Group_AddCharacter("French_frigate", "French_Lieutenant");
			Group_SetGroupCommander("French_frigate", "French_Lieutenant");
			Group_SetPursuitGroup("French_frigate", PLAYER_GROUP);
			Group_SetTaskAttack("French_frigate",  PLAYER_GROUP, true);
			Group_LockTask("French_frigate");
			Group_SetAddress("French_frigate", "IslaMona", "Reload_1", "ship_2"); 
			Sea_LoginGroupNow("French_frigate");
			characters[GetCharacterIndex("French_Lieutenant")].nosurrender = 2;
			SetCharacterRelationBoth(GetCharacterIndex("French_Lieutenant"),GetMainCharacterIndex(),RELATION_ENEMY);
			Pchar.quest.mona_attack_frigate_beaten.win_condition.l1 = "NPC_death";
			Pchar.quest.mona_attack_frigate_beaten.win_condition.l1.character = "French_Lieutenant";
			Pchar.quest.mona_attack_frigate_beaten.win_condition = "mona_attack_frigate_beaten";
		break;

		case "mona_attack_frigate_beaten":
			bQuestDisableMapEnter = false;
//			Island_SetReloadEnableGlobal(PChar.quest.mona_attack_battle_location, true);
//			DeleteQuestAttribute("mona_attack_battle_location");
			AddQuestRecord("Isla Mona Attack", 2);
			PChar.quest.mona_attack_beach_battle.win_condition.l1 = "location";
			PChar.quest.mona_attack_beach_battle.win_condition.l1.location = "IslaMona_port";
			PChar.quest.mona_attack_beach_battle.win_condition = "mona_attack_beach_battle";

			Locations[FindLocation("Quest_Arawak_Village")].locators_radius.goto.goto19 = 5.0;
		break;

		case "mona_attack_beach_battle":
			PChar.quest.disable_rebirth = true;
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			bQuestDisableSeaEnter = true;
			Locations[FindLocation("IslaMona_port")].reload.l2.disable = 1;
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "goto", "goto1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier1";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto5");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier2";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto3");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier3";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "goto", "goto9");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier4";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "mona_attack_beach_fight_won");
		break;

		case "mona_attack_beach_fight_won":
			EndQuestMovie();

			Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "what_have_you_done";
			for(n = 3; n <=7; n++)
			{
				ChangeCharacterAddress(characterFromID("Quest_Indian" + n), "None", "");
			}

			Locations[FindLocation("IslaMona_fort")].models.always.locators = "fort2_l_GR";
			Pchar.quest.mona_attack_village_battle_setup.win_condition.l1 = "location";
			Pchar.quest.mona_attack_village_battle_setup.win_condition.l1.location = "Quest_Arawak_Village";
			PChar.quest.mona_attack_village_battle_setup.win_condition = "mona_attack_village_battle_setup";

			Pchar.quest.mona_attack_fort_battle.win_condition.l1 = "location";
			Pchar.quest.mona_attack_fort_battle.win_condition.l1.location = "IslaMona_fort";
			PChar.quest.mona_attack_fort_battle.win_condition = "mona_attack_fort_battle";
		break;

		case "mona_attack_village_battle_setup":
			StartQuestMovie(true, true, false);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "goto", "goto28");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier1";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto39");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier2";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto37");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier3";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "goto", "goto23");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier4";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			Pchar.quest.mona_attack_village_battle.win_condition.l1 = "locator";
			Pchar.quest.mona_attack_village_battle.win_condition.l1.location = "Quest_Arawak_Village";
			Pchar.quest.mona_attack_village_battle.win_condition.l1.locator_group = "goto";
			Pchar.quest.mona_attack_village_battle.win_condition.l1.locator = "goto19";
			PChar.quest.mona_attack_village_battle.win_condition = "mona_attack_village_battle";
		break;

		case "mona_attack_village_battle":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "mona_attack_village_battle_won");
		break;

		case "mona_attack_village_battle_won":
			for(n = 3; n <=7; n++)
			{
				cc = n-2;
				if(n == 3 || n == 7) cc = 6;
				ChangeCharacterAddressGroup(characterFromID("Quest_Indian" + n), "Quest_Arawak_Village", "reload", "reload" + cc);
			}
			ChangeCharacterAddressGroup(characterFromID("Quest_Chief_Indian1"), "Quest_Arawak_Village", "reload", "reload5");
			LAi_QuestDelay("mona_attack_village_battle_won2", 0.0);
		break;

		case "mona_attack_village_battle_won2":
			LAi_SetFightMode(PChar, false);
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, characterFromID("Quest_Chief_Indian1"));
			LAi_SetActorType(characterFromID("Quest_Chief_Indian1"));
			LAi_ActorDialog(characterFromID("Quest_Chief_Indian1"),PChar,"mona_attack_village_battle_won3",5.0,5.0);
		break;

		case "mona_attack_village_battle_won3":
			LAi_SetPlayerType(PChar);
			EndQuestMovie();
			LAi_SetActorType(characterFromID("Quest_Chief_Indian1"));
            		LAi_ActorGoToLocation(characterFromID("Quest_Chief_Indian1"), "reload", "reload5", "None", "", "", "", 10.0);
			Pchar.quest.mona_attack_reset_village.win_condition.l1 = "ExitFromLocation";
			PChar.quest.mona_attack_reset_village.win_condition.l1.location = PChar.location;
			Pchar.quest.mona_attack_reset_village.win_condition = "mona_attack_reset_village";
		break;

		case "mona_attack_reset_village":
			ChangeCharacterAddressGroup(characterFromID("Quest_Indian3"), "Quest_Arawak_Village", "goto", "goto11");
			ChangeCharacterAddressGroup(characterFromID("Quest_Indian4"), "Quest_Arawak_Village", "goto", "goto37");
			ChangeCharacterAddressGroup(characterFromID("Quest_Indian5"), "Quest_Arawak_Village", "goto", "goto8");
			ChangeCharacterAddressGroup(characterFromID("Quest_Indian6"), "Quest_Arawak_Village", "goto", "goto43");
			ChangeCharacterAddressGroup(characterFromID("Quest_Indian7"), "Quest_Arawak_Village", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Quest_Chief_Indian1"), "Quest_Indian_house", "goto", "goto2");
			LAi_SetStayType(characterFromID("Quest_Chief_Indian1"));
		break;

		case "mona_attack_fort_battle":
			StartQuestMovie(true, true, false);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "rld", "loc4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier1";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "rld", "loc1");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier2";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "rld", "loc5");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier3";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "rld", "aloc0");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier4";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "rld", "aloc3");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier5";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "rld", "aloc4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			GiveSoldierWeapon(sld, FRANCE);
			sld.id = "soldier6";
			sld.nation = FRANCE;
			SetRandomNameToCharacter(sld);
			ChangeCharacterAddressGroup(characterFromID("French_Captain1"), "IslaMona_fort", "rld", "loc7");
			LAi_group_MoveCharacter(characterFromID("French_Captain1"), "SPAIN_SOLDIERS"); // So he doesn't join in the fight
			LAi_SetStayType(characterFromID("French_Captain1"));
			LAi_SetImmortal(CharacterFromID("French_Captain1"), true);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "mona_attack_fort_battle_won");
		break;

		case "mona_attack_fort_battle_won":
			Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "fort_taken";
//			LAi_group_MoveCharacter(characterFromID("French_Captain1"), "FRANCE_SOLDIERS");
			LAi_SetCivilianGuardianType(characterFromID("French_Captain1"));
			Characters[GetCharacterIndex("French_Captain1")].dialog.CurrentNode = "fort_surrender";
		break;

		case "mona_attack_fort_battle_won2": // Triggered by dialog with "French_Captain1"
			EndQuestMovie();
			AddQuestRecord("Isla Mona Attack", 4);

			if (GetCompanionQuantity(PChar) > 1)
			{
				cc = -1;
				for (n=1; n<COMPANION_MAX; n++)
				{
					cc = GetCompanionIndex(PChar, n);
					if(cc != -1 && characters[cc].id != "Imperial_Captain") break;
				}
				if (cc > 0)
				{
					PChar.quest.mona_attack.fleet_commander = characters[cc].id;
					ch = CharacterFromID(PChar.quest.mona_attack.fleet_commander);
					ChangeCharacterAddressGroup(CharacterFromID(PChar.quest.mona_attack.fleet_commander), "IslaMona_port", "goto", "goto2");
					LAi_SetStayType(ch);
					StoreDialog(ch);
//					PChar.quest.normal_dialog = ch.Dialog.Filename;
					ch.Dialog.Filename = "crew_dialog.c";
					ch.dialog.CurrentNode = "mona_attack_detach_fleet";
					AddQuestRecord("Isla Mona Attack", 8);
				}
			}

			Pchar.quest.mona_attack_capture_captain1.win_condition.l1 = "ExitFromLocation";
			PChar.quest.mona_attack_capture_captain1.win_condition.l1.location = PChar.location;
			Pchar.quest.mona_attack_capture_captain1.win_condition = "mona_attack_capture_captain1";
		break;

		case "mona_attack_capture_captain1":
			ChangeCharacterAddress(characterFromID("French_Captain1"), "None", "");
			AddPassenger(PChar, CharacterFromID("French_Captain1"), 1);
			LAi_SetImmortal(CharacterFromID("French_Captain1"), false);

//			DeleteAttribute(CharacterFromID("French_Captain1"), "questchar");	// Make the captain a regular character who can be hired, ransomed or released
		break;

		case "mona_attack_detach_fleet": // Triggered by dialog with a companion officer
//			characters[GetCharacterIndex(PChar.quest.mona_attack.fleet_commander)].Dialog.Filename = PChar.quest.normal_dialog;
			RestoreDialog(CharacterFromID(PChar.quest.mona_attack.fleet_commander));
			LAi_SetCitizenType(CharacterFromID(PChar.quest.mona_attack.fleet_commander));
			AddQuestRecord("Isla Mona Attack", 5);
			PChar.quest.mona_attack_detach_fleet2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.mona_attack_detach_fleet2.win_condition.l1.location = PChar.location;
			PChar.quest.mona_attack_detach_fleet2.win_condition = "mona_attack_detach_fleet2";

			pchar.quest.mona_attack_rejoin_fleet.win_condition.l1 = "location";
			PChar.quest.mona_attack_rejoin_fleet.win_condition.l1.location = "Santo_Domingo_port";
			PChar.quest.mona_attack_rejoin_fleet.win_condition = "mona_attack_rejoin_fleet";
		break;

		case "mona_attack_detach_fleet2":
			PChar.quest.mona_attack.original_fleet_size = GetCompanionQuantity(PChar);
			for (n=1; n<COMPANION_MAX; n++)
			{
				cc = GetCompanionIndex(PChar,n);
				temp = "companion" + n;
				if (cc > 0)
				{
					PChar.quest.mona_attack.(temp) = characters[cc].id;
					if (HasSubStr(PChar.quest.mona_attack.(temp), "Enc_Officer")) LAi_StoreFantom(CharacterFromId(PChar.quest.mona_attack.(temp))); // Prevent character from being overwritten by another "Enc_Officer"
					RemoveCharacterCompanion(PChar, characters[cc]);
					setCharacterShipLocation(CharacterFromId(PChar.quest.mona_attack.(temp)), "Santo_Domingo_port");
				}
				else PChar.quest.mona_attack.(temp) = "*NULL*";
			}
			ChangeCharacterAddressGroup(CharacterFromID(PChar.quest.mona_attack.fleet_commander), "Santo_Domingo_port", "goto", "goto18");
		break;

		case "mona_attack_return_to_fort":
			Pchar.quest.mona_attack_return_to_fort2.win_condition.l1 = "location";
			Pchar.quest.mona_attack_return_to_fort2.win_condition.l1.location = "IslaMona_fort";
			PChar.quest.mona_attack_return_to_fort2.win_condition = "mona_attack_return_to_fort2";
		break;

		case "mona_attack_return_to_fort2":
			LAi_SetActorType(PChar);
			ChangeCharacterAddressGroup(PChar, "IslaMona_fort", "rld", "loc2");
			LAi_Fade("mona_attack_return_to_fort3", "mona_attack_return_to_fort4");
		break;

		case "mona_attack_return_to_fort3":
			LAi_ActorTurnToLocator(PChar, "rld", "loc0");
			n = rand(5) + 1;
			WaitDate("", 0, 0, n, 0, 0);
//			cc = rand(99);
//			SetCurrentTime(11.0 + cc/100.0, 0);
			cc = rand(59);
			SetCurrentTime(11, cc);
		break;

		case "mona_attack_return_to_fort4":
			setCharacterShipLocation(CharacterFromId("French_Captain2"), "IslaMona_port");
			setCharacterShipLocation(CharacterFromId("French_Captain3"), "IslaMona_port");
			setCharacterShipLocation(CharacterFromId("French_Contre-Amiral"), "IslaMona_port");
			LAi_SetPlayerType(PChar);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor16", "rld", "loc0");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_SetImmortal(sld, true);
			sld.id = "temp_crewman";
			sld.Dialog.Filename = "crew_dialog.c";
			sld.dialog.CurrentNode = "mona_attack_french_on_way";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld,PChar,"mona_attack_goto_pass",10.0,10.0);
		break;

		case "mona_attack_goto_pass":
			LAi_ActorGoToLocation(characterFromID("temp_crewman"), "reload", "reloadc1", "None", "", "", "", 30.0);
			setCharacterShipLocation(CharacterFromId("French_Captain2"), "IslaMona_port");
			setCharacterShipLocation(CharacterFromId("French_Captain3"), "IslaMona_port");
			setCharacterShipLocation(CharacterFromId("French_Contre-Amiral"), "IslaMona_port");
			HoistFlag(FRANCE);
			Pchar.quest.mona_pass_battle_setup.win_condition.l1 = "location";
			Pchar.quest.mona_pass_battle_setup.win_condition.l1.location = "IslaMona_passage";
			PChar.quest.mona_pass_battle_setup.win_condition = "mona_attack_pass_battle_setup";
		break;

		case "mona_attack_pass_battle_setup":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			for (n=1; n<7; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.(temp), "reload", "reload2_back");
				LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
				GiveSoldierWeapon(sld, FRANCE);
				sld.id = "soldier" + n;
				sld.nation = FRANCE;
				SetRandomNameToCharacter(sld);
			}
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "mona_attack_pass_battle_won");
			LAi_QuestDelay("mona_attack_pass_battle_second_group", 10.0);
		break;

		case "mona_attack_pass_battle_second_group":
			for (n=7; n<13; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 2, true, true, 0.25, Nations[FRANCE].fantomModel.(temp), "reload", "reload2_back");
				LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
				GiveSoldierWeapon(sld, FRANCE);
				sld.id = "soldier" + n;
				sld.nation = FRANCE;
				SetRandomNameToCharacter(sld);
			}
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_QuestDelay("mona_attack_pass_battle_taino", 12.0);
		break;

		case "mona_attack_pass_battle_taino":
			for (n=1; n<7; n++)
			{
				cc = n-3;
				if (n < 4) temp = "Indian1_" + n;
				else temp = "Indian" + cc;
				sld = LAi_CreateFantomCharacter(false, 3, true, true, 0.25, temp, "reload", "reload2_back");
//				sld = LAi_CreateFantomCharacterExOtAt(true, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Indian" + n, "reload", "reload2_back");
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
				TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
				TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
				RemoveCharacterEquip(sld, BLADE_ITEM_TYPE);
				RemoveCharacterEquip(sld, GUN_ITEM_TYPE);
				TakenItems(sld, "bladearrows", 1 + rand(2));
				GiveItem2Character(sld, "pistolbow");
				GiveItem2Character(sld, "tomahawk");
				EquipCharacterByItem(sld, "pistolbow");
				sld.id = "Indian" + n;
				sld.name = "Indian";
				sld.lastname = n;
			}
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "mona_attack_pass_battle_won":
			EndQuestMovie();
			LAi_SetFightMode(PChar, false);
			AddQuestRecord("Isla Mona Attack", 7);
			speaker = Get_Speaker();

			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				StoreDialog(crewref);
				LAi_SetActorType(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "mona_attack_pass_battle_won";
				LAi_ActorDialog(crewref, pchar, "mona_attack_reset_officer", 5.0, 5.0);
			}

			DisableFastTravel(false);
			bQuestDisableSeaEnter = false;
			Locations[FindLocation("IslaMona_port")].reload.l2.disable = 0;

			Islands[FindIsland("IslaMona")].smuggling_nation = PIRATE;
//			CaptureTownForNation("Khael Roa", PIRATE);

			Pchar.quest.mona_attack_return_to_village.win_condition.l1 = "location";
			Pchar.quest.mona_attack_return_to_village.win_condition.l1.location = "Quest_Arawak_Village";
			PChar.quest.mona_attack_return_to_village.win_condition = "mona_attack_return_to_village";

			Pchar.quest.mona_attack_port_encounter.win_condition.l1 = "location";
			Pchar.quest.mona_attack_port_encounter.win_condition.l1.location = "IslaMona_port";
			PChar.quest.mona_attack_port_encounter.win_condition = "mona_attack_port_encounter";

			PChar.quest.mona_attack_getuniform.win_condition.l1 = "ExitFromLocation";
			PChar.quest.mona_attack_getuniform.win_condition.l1.location = PChar.location;
			PChar.quest.mona_attack_getuniform.win_condition = "mona_attack_getuniform";
		break;

		case "mona_attack_reset_officer":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				RestoreDialog(crewref);
				LAi_SetOfficerType(CharacterFromId(characters[crewidx].id));
				StoreOfficers(PChar.id);
			}
		break;

		case "mona_attack_getuniform":
			if (PChar.sex == "man") GiveModel2Player("Ardent_Fr", true);
			else
			{
				GiveModel2Player("Ardent_FrF", true);
				logit(TranslateString("","Again I have to wear a man's uniform. Better than letting the French see me in my usual outfit, I suppose..."));
			}
		break;

		case "mona_attack_return_to_village":
			ChangeCharacterAddressGroup(characterFromID("Quest_Chief_Indian1"), "Quest_Arawak_Village", "reload", "reload5");
			Pchar.quest.mona_attack_return_to_village2.win_condition.l1 = "locator";
			Pchar.quest.mona_attack_return_to_village2.win_condition.l1.location = "Quest_Arawak_Village";
			Pchar.quest.mona_attack_return_to_village2.win_condition.l1.locator_group = "goto";
			Pchar.quest.mona_attack_return_to_village2.win_condition.l1.locator = "goto19";
			PChar.quest.mona_attack_return_to_village2.win_condition = "mona_attack_return_to_village2";
		break;

		case "mona_attack_return_to_village2":
			if (PChar.model == "Ardent_Fr" || PChar.model == "Ardent_FrF")
			{
				LAi_SetActorType(characterFromID("Quest_Chief_Indian1"));
				Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "dont_attack";
				LAi_ActorDialogNow(characterFromID("Quest_Chief_Indian1"),PChar,"mona_attack_return_to_village3",1.0);
			}
			else LAi_QuestDelay("mona_attack_return_to_village3", 1.0);
		break;

		case "mona_attack_return_to_village3":
			LAi_SetActorType(characterFromID("Quest_Chief_Indian1"));
			if (PChar.model == "Ardent_Fr" || PChar.model == "Ardent_FrF") Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "why_you_in_uniform";
			else Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "after_the_battle";
			LAi_ActorDialog(characterFromID("Quest_Chief_Indian1"),PChar,"mona_attack_chief_goes_home",10.0,10.0);
		break;

		case "mona_attack_chief_goes_home":
            		LAi_ActorGoToLocation(characterFromID("Quest_Chief_Indian1"), "reload", "reload5", "None", "", "", "", 10.0);
			PChar.quest.mona_attack_detach_fleet2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.mona_attack_detach_fleet2.win_condition.l1.location = PChar.location;
			PChar.quest.mona_attack_detach_fleet2.win_condition = "mona_attack_chief_goes_home2";
		break;

		case "mona_attack_chief_goes_home2":
			ChangeCharacterAddressGroup(characterFromID("Quest_Chief_Indian1"), "Quest_Indian_house", "goto", "goto2");
			LAi_SetStayType(characterFromID("Quest_Chief_Indian1"));
			Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "First time";
		break;

		case "mona_attack_port_encounter":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			SetCompanionIndex(Pchar, 1, GetCharacterIndex("French_Contre-Amiral"));
			SetCompanionIndex(Pchar, 2, GetCharacterIndex("French_Captain2"));
			SetCompanionIndex(Pchar, 3, GetCharacterIndex("French_Captain3"));
			SetCharacterRemovable(characterFromID("French_Contre-Amiral"), false);
			SetCharacterRemovable(characterFromID("French_Captain2"), false);
			SetCharacterRemovable(characterFromID("French_Captain3"), false);
			Characters[GetCharacterIndex("French_Contre-Amiral")].Flags.UseNavalFlag = true;
			Characters[GetCharacterIndex("French_Captain2")].Flags.UseNavalFlag = true;
			Characters[GetCharacterIndex("French_Captain3")].Flags.UseNavalFlag = true;
			Characters[GetCharacterIndex("French_Contre-Amiral")].professionalnavy = FRANCE;
			PChar.Flags.UseNavalFlag = true;
			temp = "m" + (rand(5) + 1);
			sld = LAi_CreateFantomCharacter(false, 2, true, true, 0.25, Nations[FRANCE].fantomModel.(temp), "goto", "goto2");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_SetImmortal(sld, true);
			sld.id = "French_fleet_officer";
			LAi_SetActorType(sld);
			sld.Dialog.Filename = "guard_dialog.c";
			sld.dialog.CurrentNode = "mona_attack_are_you_captain";
			if (GetOfficersQuantity(PChar) > 0) sld.dialog.CurrentNode = "mona_attack_who_are_they";
			if (PChar.model != "Ardent_Fr" && PChar.model != "Ardent_FrF") sld.dialog.CurrentNode = "mona_attack_what_no_uniform";
			LAi_ActorDialog(sld,PChar,"mona_attack_ready_for_flagship",30.0,30.0);
		break;

		case "mona_attack_ready_for_flagship":
			EndQuestMovie();
			DisableFastTravel(false);
//			Locations[FindLocation("Cabin1")].models.always.locators = "cap_ld_GR";
			Pchar.quest.mona_attack_go_to_flagship.win_condition.l1 = "locator";
			Pchar.quest.mona_attack_go_to_flagship.win_condition.l1.location = "IslaMona_port";
			Pchar.quest.mona_attack_go_to_flagship.win_condition.l1.locator_group = "reload";
			Pchar.quest.mona_attack_go_to_flagship.win_condition.l1.locator = "boat";
			PChar.quest.mona_attack_go_to_flagship.win_condition = "mona_attack_go_to_flagship";
			GiveItem2Character(villain, "goldarmor");
			EquipCharacterByItem(villain, "goldarmor");
		break;

		case "mona_attack_go_to_flagship":
			ChangeCharacterAddressGroup(characterFromID("French_Captain2"), "Cabin1", "box", "weaponslocker");
			ChangeCharacterAddressGroup(characterFromID("French_Captain3"), "Cabin1", "goto", "goto1");
			ChangeCharacterAddressGroup(characterFromID("French_Contre-Amiral"), "Cabin1", "rld", "aloc1");
			ChangeCharacterAddressGroup(villain, "Cabin1", "rld", "startloc");
			DoQuestReloadToLocation("Cabin1", "reload", "reload1", "mona_attack_go_to_flagship2");
		break;

		case "mona_attack_go_to_flagship2":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "rld", "loc1", "mona_attack_go_to_flagship3", 15.0);
		break;

		case "mona_attack_go_to_flagship3":
			LAi_SetActorType(villain);
			LAi_ActorGoToLocator(villain, "reload", "reload1", "", 15.0);
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, characterFromID("French_Contre-Amiral"));
			LAi_SetActorType(characterFromID("French_Contre-Amiral"));
			Characters[GetCharacterIndex("French_Contre-Amiral")].Dialog.Filename = "French_Contre-Amiral_dialog.c";
			if (PChar.model != "Ardent_Fr" && PChar.model != "Ardent_FrF")
			{
				Characters[GetCharacterIndex("French_Contre-Amiral")].dialog.CurrentNode = "spy_caught";
				LAi_ActorDialog(characterFromID("French_Contre-Amiral"),PChar,"hung at dawn",5.0,5.0);
			}
			else
			{
				Characters[GetCharacterIndex("French_Contre-Amiral")].dialog.CurrentNode = "who_are_you";
				LAi_ActorDialog(characterFromID("French_Contre-Amiral"),PChar,"",5.0,5.0); // Exits to "mona_attack_villain_recognises" or "mona_attack_return_to_ship"
			}
		break;

		case "mona_attack_villain_recognises":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, villain);
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "mona_attack_recognised";
			LAi_ActorDialog(villain,PChar,"mona_attack_villain_pacified",10.0,10.0);
		break;

		case "mona_attack_villain_pacified":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, characterFromID("French_Contre-Amiral"));
			LAi_SetActorType(characterFromID("French_Contre-Amiral"));
			Characters[GetCharacterIndex("French_Contre-Amiral")].dialog.CurrentNode = "on_to_business";
			LAi_ActorDialog(characterFromID("French_Contre-Amiral"),PChar,"",5.0,5.0); // Exits to "mona_attack_return_to_ship"
		break;

		case "mona_attack_return_to_ship":
			PChar.quest.disable_rebirth = false;
			AddQuestRecord("Isla Mona Attack", 11);
			SetQuestHeader("Treachery");
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			AddQuestRecord("Treachery", 1);
			Preprocessor_Remove("villain");

			LAi_SetPlayerType(PChar);
			if (PChar.sex == "woman" && PChar.model == "Ardent_FrF")
			{
				PChar.quest.mona_attack_helen_changes_back.win_condition.l1 = "SeaEnter";
				PChar.quest.mona_attack_helen_changes_back.win_condition = "mona_attack_helen_changes_back";
			}
			QuestToSeaLogin_PrepareLoc("IslaMona", "reload", "reload_1", false);
			QuestToSeaLogin_Launch();
			character_SetCompanionEnemyEnable(characterFromID("French_Captain2"), true);
			character_SetCompanionEnemyEnable(characterFromID("French_Captain3"), true);
			character_SetCompanionEnemyEnable(characterFromID("French_Contre-Amiral"), true);
			characters[GetCharacterIndex("French_Contre-Amiral")].nosurrender = 2;

			ChangeCharacterAddressGroup(characterFromID("Quest_Chief_Indian1"), "Quest_Indian_house", "goto", "goto2");
			LAi_SetStayType(characterFromID("Quest_Chief_Indian1"));
			Characters[GetCharacterIndex("Quest_Chief_Indian1")].dialog.CurrentNode = "First time";
			RestoreOfficers(PChar.id);

			PChar.QuestsCheck = true; // Force quest checks to be made every minute.
			Island_SetReloadEnableLocal("Hispaniola", "reload_2", false); // Disable entry to Boca de Yuman so you can only enter Santo Domingo by sea

//			Pchar.quest.mona_attack_leave_french_fleet.win_condition.l1 = "MapEnter";
			Pchar.quest.mona_attack_leave_french_fleet.win_condition.l1 = "Time";
			Pchar.quest.mona_attack_leave_french_fleet.win_condition.l1.time = DAY_TIME_NIGHT;
			PChar.quest.mona_attack_leave_french_fleet.win_condition = "mona_attack_leave_french_fleet";

			Pchar.quest.mona_attack_defeat_French_fleet.win_condition.l1 = "NPC_Death";
			Pchar.quest.mona_attack_defeat_French_fleet.win_condition.l1.character = "French_Captain2";
			Pchar.quest.mona_attack_defeat_French_fleet.win_condition.l2 = "NPC_Death";
			Pchar.quest.mona_attack_defeat_French_fleet.win_condition.l2.character = "French_Captain3";
			Pchar.quest.mona_attack_defeat_French_fleet.win_condition.l3 = "NPC_Death";
			Pchar.quest.mona_attack_defeat_French_fleet.win_condition.l3.character = "French_Contre-Amiral";
			Pchar.quest.mona_attack_defeat_French_fleet.win_condition = "mona_attack_defeat_French_fleet";


			Pchar.quest.mona_attack_Martinique.win_condition.l1 = "location";
			Pchar.quest.mona_attack_Martinique.win_condition.l1.location = "Falaise_de_fleur_port_01";
			PChar.quest.mona_attack_Martinique.win_condition = "mona_attack_french_port";

			Pchar.quest.mona_attack_Port_au_Prince.win_condition.l1 = "location";
			Pchar.quest.mona_attack_Port_au_Prince.win_condition.l1.location = "PoPrince_Port";
			PChar.quest.mona_attack_Port_au_Prince.win_condition = "mona_attack_french_port";

			Pchar.quest.mona_attack_Tortuga.win_condition.l1 = "location";
			Pchar.quest.mona_attack_Tortuga.win_condition.l1.location = "Tortuga_port";
			PChar.quest.mona_attack_Tortuga.win_condition = "mona_attack_french_port";

			Pchar.quest.mona_attack_Guadeloupe.win_condition.l1 = "location";
			Pchar.quest.mona_attack_Guadeloupe.win_condition.l1.location = "Guadeloupe_Port";
			PChar.quest.mona_attack_Guadeloupe.win_condition = "mona_attack_french_port";

			Pchar.quest.mona_attack_Marigot.win_condition.l1 = "location";
			Pchar.quest.mona_attack_Marigot.win_condition.l1.location = "Marigot_port";
			PChar.quest.mona_attack_Marigot.win_condition = "mona_attack_french_port";

			PChar.quest.ardent_treachery_status = "planned";

			PChar.quest.treachery_invasion_happens.win_condition.l1 = "Timer";
			PChar.quest.treachery_invasion_happens.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.treachery_invasion_happens.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.treachery_invasion_happens.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0); 
/*			PChar.quest.treachery_invasion_happens.win_condition.l1.date.day = GetAddingDataDay(0, 0, 3);		// Trigger Port Royale invasion early for test purposes
			PChar.quest.treachery_invasion_happens.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 3);
			PChar.quest.treachery_invasion_happens.win_condition.l1.date.year = GetAddingDataYear(0, 0, 3); */
			PChar.quest.treachery_invasion_happens.win_condition = "treachery_invasion_happens";

			LAi_QuestDelay("frenchuniform_checks_setup", 0.0);
		break;

		case "mona_attack_helen_changes_back":
			GiveModel2Player("Ardent_F", true);
			logit(TranslateString("","Back to my own ship and back to my own clothes!"));
		break;

		case "mona_attack_leave_french_fleet":
			Pchar.quest.mona_attack_Martinique.over = "yes";
			Pchar.quest.mona_attack_Port_au_Prince.over = "yes";
			Pchar.quest.mona_attack_Tortuga.over = "yes";
			Pchar.quest.mona_attack_Guadeloupe.over = "yes";
			Pchar.quest.mona_attack_Marigot.over = "yes";
			DeleteAttribute(PChar, "QuestsCheck"); // Restore quest checks to being made less often to restore 3D sailing performance
			Island_SetReloadEnableLocal("Hispaniola", "reload_2", true); // Boca de Yuman re-opened
			SetCharacterRemovable(characterFromID("French_Contre-Amiral"), true);
			SetCharacterRemovable(characterFromID("French_Captain2"), true);
			SetCharacterRemovable(characterFromID("French_Captain3"), true);
			RemoveCharacterCompanion(PChar, characterFromID("French_Captain2"));
			RemoveCharacterCompanion(PChar, characterFromID("French_Captain3"));
			RemoveCharacterCompanion(PChar, characterFromID("French_Contre-Amiral"));
			Group_CreateGroup("French Fleet1");
			Group_AddCharacter("French Fleet1", "French_Captain2");
			Group_AddCharacter("French Fleet1", "French_Captain3");
			Group_AddCharacter("French Fleet1", "French_Contre-Amiral");
			Group_SetGroupCommander("French Fleet1", "French_Contre-Amiral");

			Group_SetAddress("French Fleet1", Characters[GetMainCharacterIndex()].location, "", "");
			if (Characters[GetMainCharacterIndex()].location == "") Sea_LoginGroupNow("French Fleet1");
			Group_SetTaskAttack("French Fleet1", PLAYER_GROUP, true);
			Group_LockTask("French Fleet1");
			characters[GetCharacterIndex("French_Contre-Amiral")].recognized = true;
			characters[GetCharacterIndex("French_Captain2")].recognized = true;
			characters[GetCharacterIndex("French_Captain3")].recognized = true;
			UpdateRelations();
			RefreshBattleInterface(true);
			DeleteAttribute(PChar, "Flags.UseNavalFlag");
			if (!CheckAttribute(PChar, "quest.mona_attack.fleet_commander"))
			{
				AddQuestRecord("Isla Mona Attack", 12);
				CloseQuestHeader("Isla Mona Attack");
			}
			else AddQuestRecord("Isla Mona Attack", 13);
		break;

		case "mona_attack_defeat_French_fleet":
			Pchar.quest.mona_attack_Martinique.over = "yes";
			Pchar.quest.mona_attack_Port_au_Prince.over = "yes";
			Pchar.quest.mona_attack_Tortuga.over = "yes";
			Pchar.quest.mona_attack_Guadeloupe.over = "yes";
			Pchar.quest.mona_attack_Marigot.over = "yes";
			PChar.quest.mona_attack_leave_french_fleet.over = "yes";
			DeleteAttribute(PChar, "Flags.UseNavalFlag");
			DeleteAttribute(PChar, "QuestsCheck"); // Restore quest checks to being made less often to restore 3D sailing performance
			Island_SetReloadEnableLocal("Hispaniola", "reload_2", true); // Boca de Yuman re-opened
			if (!CheckAttribute(PChar, "quest.mona_attack.fleet_commander"))
			{
				AddQuestRecord("Isla Mona Attack", 15);
				CloseQuestHeader("Isla Mona Attack");
			}
			else AddQuestRecord("Isla Mona Attack", 16);
		break;

		case "mona_attack_french_port":
			Pchar.quest.mona_attack_Martinique.over = "yes";
			Pchar.quest.mona_attack_Port_au_Prince.over = "yes";
			Pchar.quest.mona_attack_Tortuga.over = "yes";
			Pchar.quest.mona_attack_Guadeloupe.over = "yes";
			Pchar.quest.mona_attack_Marigot.over = "yes";
			PChar.quest.mona_attack_leave_french_fleet.over = "yes";
			PChar.quest.mona_attack_defeat_French_fleet.over = "yes";
			SetCharacterRemovable(characterFromID("French_Contre-Amiral"), true);
			SetCharacterRemovable(characterFromID("French_Captain2"), true);
			SetCharacterRemovable(characterFromID("French_Captain3"), true);
			RemoveCharacterCompanion(PChar, characterFromID("French_Captain2"));
			RemoveCharacterCompanion(PChar, characterFromID("French_Captain3"));
			RemoveCharacterCompanion(PChar, characterFromID("French_Contre-Amiral"));
			DeleteAttribute(PChar, "QuestsCheck"); // Restore quest checks to being made less often to restore 3D sailing performance
			Island_SetReloadEnableLocal("Hispaniola", "reload_2", true); // Boca de Yuman re-opened
			DeleteAttribute(PChar, "Flags.UseNavalFlag");
//			iForceDetectionFalseFlag = 1;
			switch(PChar.location)
			{
				case "Falaise_de_fleur_port_01": ch = characterFromID("FalaiseDeFleur Commander"); break;
				case "PoPrince_Port": ch = characterFromID("Port au Prince Commander"); break;
				case "Tortuga_port": ch = characterFromID("Tortuga Commander"); break;
				case "Guadeloupe_Port": ch = characterFromID("Pointe a Pitre Commander"); break;
				case "Marigot_port": ch = characterFromID("Marigot Commander");	break;				
			}
			ch.PlayerNation = GetCurrentFlag();
			ch.PlayerShip = GetCharacterShipModel(PChar);
			ch.recognized = true;
//			Trace("Ardent: The " + GetMyShipNameShow(ch) + " will remember us as " + GetNationDescByType(sti(ch.PlayerNation)) + " in a " + ch.PlayerShip);
			Pchar.quest.mona_attack_leave_French_port.win_condition.l1 = "MapEnter";
			Pchar.quest.mona_attack_leave_French_port.win_condition = "mona_attack_leave_French_port";
		break;

		case "mona_attack_leave_French_port":
			iForceDetectionFalseFlag = 0;
		break;

		case "mona_attack_rejoin_fleet":
			Pchar.quest.mona_attack_Martinique.over = "yes";
			Pchar.quest.mona_attack_Port_au_Prince.over = "yes";
			Pchar.quest.mona_attack_Tortuga.over = "yes";
			Pchar.quest.mona_attack_Guadeloupe.over = "yes";
			Pchar.quest.mona_attack_Marigot.over = "yes";
			PChar.quest.mona_attack_leave_french_fleet.over = "yes";
			PChar.quest.mona_attack_defeat_French_fleet.over = "yes";
			i = Group_FindGroup("French Fleet1");
			if (i >= 0)
			{
				trace("mona_attack_rejoin_fleet: 'French Fleet1' no longer required, being deleted");
				Group_DeleteGroupIndex(i);
			}
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			ch = CharacterFromID(PChar.quest.mona_attack.fleet_commander);
//			PChar.quest.normal_dialog = ch.Dialog.Filename;
			StoreDialog(ch);
			ch.Dialog.Filename = "crew_dialog.c";
			ch.dialog.CurrentNode = "mona_attack_rejoin_fleet";
			LAi_SetActorType(ch);
			LAi_ActorDialog(ch,PChar,"",30.0,30.0); // Exits to "mona_attack_goto_shipyard" or "mona_attack_rejoin_fleet2"
		break;

		case "mona_attack_rejoin_fleet2":
			EndQuestMovie();
			DisableFastTravel(false);
			for (n=1; n<COMPANION_MAX; n++)
			{
				temp = "companion" + n;
				if (PChar.quest.mona_attack.(temp) != "*NULL*")
				{
					cc = getCharacterIndex(PChar.quest.mona_attack.(temp));
					SetCompanionIndex(PChar,-1, cc)
					if (HasSubStr(PChar.quest.mona_attack.(temp), "Enc_Officer")) LAi_UnStoreFantom(CharacterFromID(PChar.quest.mona_attack.(temp))); // Cancel protection
				}
			}
			LAi_SetActorType(CharacterFromID(PChar.quest.mona_attack.fleet_commander));
//			characters[GetCharacterIndex(PChar.quest.mona_attack.fleet_commander)].Dialog.Filename = PChar.quest.normal_dialog;
			RestoreDialog(CharacterFromID(PChar.quest.mona_attack.fleet_commander));
            		LAi_ActorGoToLocation(characterFromID(PChar.quest.mona_attack.fleet_commander), "reload", "reload1", "None", "", "", "", 30.0);
			AddQuestRecord("Isla Mona Attack", 14);
			CloseQuestHeader("Isla Mona Attack");
			DeleteQuestAttribute("mona_attack");
			DeleteQuestAttribute("mona_attack_prepare_for_battle");

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1200);
				AddPartyExpChar(PChar, "", 120);
				AddPartyExpChar(pchar, "Sneak", 120);
			}
			else {AddPartyExp(pchar, 1500);}
		break;

		case "mona_attack_goto_shipyard":
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_SetActorType(characterFromID(PChar.quest.mona_attack.fleet_commander));
			LAi_ActorFollowEverywhere(characterFromID(PChar.quest.mona_attack.fleet_commander), "", 10.0);
			Pchar.quest.mona_attack_in_shipyard.win_condition.l1 = "location";
			Pchar.quest.mona_attack_in_shipyard.win_condition.l1.location = "Santo_Domingo_Shipyard";
			Pchar.quest.mona_attack_in_shipyard.win_condition = "mona_attack_in_shipyard";
		break;

		case "mona_attack_in_shipyard":
			Pchar.quest.mona_attack_back_in_port.win_condition.l1 = "location";
			Pchar.quest.mona_attack_back_in_port.win_condition.l1.location = "Santo_Domingo_town";
			Pchar.quest.mona_attack_back_in_port.win_condition = "mona_attack_back_in_town";
		break;

		case "mona_attack_back_in_town":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			LAi_SetActorType(characterFromID(PChar.quest.mona_attack.fleet_commander));
			characters[GetCharacterIndex(PChar.quest.mona_attack.fleet_commander)].dialog.CurrentNode = "mona_attack_rejoin_fleet_again";
			LAi_SetActorType(characterFromID(PChar.quest.mona_attack.fleet_commander));
			LAi_ActorDialog(characterFromID(PChar.quest.mona_attack.fleet_commander),PChar,"",5.0,5.0); // Exits to "mona_attack_goto_shipyard" or "mona_attack_rejoin_fleet2"
		break;

		case "frenchuniform_check":
			Pchar.quest.frenchuniform_check1.over = "yes";
			Pchar.quest.frenchuniform_check2.over = "yes";
			Pchar.quest.frenchuniform_check3.over = "yes";
			if (PChar.model == "Ardent_Fr" || PChar.model == "Ardent_FrF")
			{
				LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
				PChar.quest.frenchuniform_check_reset.win_condition.l1 = "ExitFromLocation";
				PChar.quest.frenchuniform_check_reset.win_condition.l1.location = PChar.location;
				PChar.quest.frenchuniform_check_reset.win_condition = "frenchuniform_checks_setup";
			}
		break;

		case "frenchuniform_checks_setup":
			Pchar.quest.frenchuniform_check1.win_condition.l1 = "location";
			Pchar.quest.frenchuniform_check1.win_condition.l1.location = "Redmond_Town_01";
			PChar.quest.frenchuniform_check1.win_condition = "frenchuniform_check";
			Pchar.quest.frenchuniform_check2.win_condition.l1 = "location";
			Pchar.quest.frenchuniform_check2.win_condition.l1.location = "Redmond_town_03";
			PChar.quest.frenchuniform_check2.win_condition = "frenchuniform_check";
			Pchar.quest.frenchuniform_check3.win_condition.l1 = "location";
			Pchar.quest.frenchuniform_check3.win_condition.l1.location = "Redmond_town_04";
			PChar.quest.frenchuniform_check3.win_condition = "frenchuniform_check";
		break;

		case "treachery_invasion_happens":
			Pchar.quest.treachery_gate_battle1.over = "yes";
			PChar.quest.ardent_treachery_status = "successful";
			CaptureTownForNation("Redmond", FRANCE);
			Islands[FindIsland("Redmond")].smuggling_nation = FRANCE;
			ChangeCharacterAddress(CharacterFromID(Towns[GetTownIndex("Redmond")].gov), "none", "");
			ChangeCharacterAddressGroup(villain, "redmond_residence", "goto", "goto8");
			Characters[villainidx].nation = FRANCE;
			Characters[villainidx].dialog.currentnode = "treachery_governor";
			Towns[GetTownIndex("Redmond")].gov = villain.id;
			switch(GetRMRelationType(GetRMRelation(PChar, FRANCE)))
			{
				case RELATION_ENEMY:
					AddQuestRecord("Treachery", 2);
				break;
				case RELATION_NEUTRAL:
					AddQuestRecord("Treachery", 3);
				break;
				case RELATION_FRIEND:
					AddQuestRecord("Treachery", 4);
				break;
			}
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			AddQuestRecord("Treachery", 9);

			Pchar.quest.treachery_visit_townhall.win_condition.l1 = "location";
			Pchar.quest.treachery_visit_townhall.win_condition.l1.location = "Redmond_Residence";
			Pchar.quest.treachery_visit_townhall.win_condition = "treachery_visit_townhall";
		break;

		case "treachery_visit_townhall":
			if (isofficer(romance) && PChar.quest.alignment == "good") ChangeCharacterAddressGroup(romance, "redmond_residence", "goto", "goto4");
		break;

		case "treachery_villain_invites_romance":	// Triggered by dialog with Piers / Valerie Downing if Lucía / Edmundo is with you
			characters[romanceidx].dialog.CurrentNode = "treachery_reject_villain";
			LAi_SetActorType(romance);
//			LAi_ActorDialog(romance,PChar,"treachery_romance_rejects_villain",5.0,5.0); // Doesn't seem to lead to next quest case if 'AddDialogExitQuest' present in dialog
			LAi_ActorDialog(romance,PChar,"",5.0,5.0);
		break;

		case "treachery_romance_rejects_villain":
			LAi_SetOfficerType(romance);
			characters[villainidx].dialog.CurrentNode = "treachery_rejected";
			LAi_SetActorType(villain);
			LAi_ActorDialog(villain,PChar,"",5.0,5.0);
		break;

		case "treachery_villain_calls_guards": // Triggered by dialog with Piers / Valerie Downing
			LAi_SetImmortal(villain, true);
			LAi_SetImmortal(romance, true);
			LAi_SetActorType(villain);
			LAi_ActorRunToLocation(villain, "reload", "reload3", "none", "", "", "", 10.0);
			LAi_LocationFightDisable(&Locations[FindLocation("Redmond_Residence")], false);
			Ambush("Soldiers", 6, "enemy", "friend", "reload1");
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = 1;	// Lock door into townhall, you won't be visiting Piers / Valerie again

			PChar.quest.treachery_reset_villain.win_condition.l1 = "ExitFromLocation";
			PChar.quest.treachery_reset_villain.win_condition.l1.location = PChar.location;
			PChar.quest.treachery_reset_villain.win_condition = "treachery_reset_villain";
		break;

		case "treachery_reset_villain":
			LAi_SetImmortal(villain, false);
			LAi_SetImmortal(romance, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Redmond_Residence")], true);
		break;

		case "threat_goto_santiago": // Triggered by dialog with Lucía / Edmundo if present when you visit townhall
			Pchar.quest.threat_romance_goto_Santiago.win_condition.l1 = "location";
			Pchar.quest.threat_romance_goto_Santiago.win_condition.l1.location = "Redmond_Town_01";
			Pchar.quest.threat_romance_goto_Santiago.win_condition = "threat_romance_goto_Santiago";
		break;

		case "threat_romance_goto_Santiago":
			DisableFastTravel(true);
			StartQuestMovie(true, true, false);
			characters[romanceidx].dialog.CurrentNode = "threat_goto_santiago";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"threat_agree_goto_santiago",5.0,5.0);
		break;

		case "threat_agree_goto_santiago":
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_SetOfficerType(romance);
			CloseQuestHeader("Treachery");
			SetQuestHeader("Santiago Threat");
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			AddQuestRecord("Santiago Threat", 1);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			PChar.quest.ardent_treachery_status = "goto_Santiago";
		break;

		case "threat_alternate_guadeloupe_setup":	// Triggered by dialog with "Javier Balboa"
			Preprocessor_AddQuestData("governor", GetMySimpleName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Santiago Threat", 3);
			Preprocessor_Remove("governor");
			PChar.quest.academy_breakin_name = "threat";
			Locations[FindLocation("PaP_Academy")].models.always.locators = "sh04_locators_GR";
			Locations[FindLocation("PaP_prison")].vcskip = true;
			Locations[FindLocation("PaP_prison")].models.always.locators = "Pri_l_GR";
			Pchar.quest.threat_academy_breakin.win_condition.l1 = "locator";
			Pchar.quest.threat_academy_breakin.win_condition.l1.location = "Guadeloupe_Port";
			Pchar.quest.threat_academy_breakin.win_condition.l1.locator_group = "goto";
			Pchar.quest.threat_academy_breakin.win_condition.l1.locator = "goto25";
			Pchar.quest.threat_academy_breakin.win_condition.l2 = "Time";
			Pchar.quest.threat_academy_breakin.win_condition.l2.time = DAY_TIME_NIGHT;
			PChar.quest.threat_academy_breakin.win_condition = "academy_breakin";
		break;

		case "treachery_setup_gate_battle": // Triggered by dialog with "John Clifford Brin" if you are not hostile to England
			LAi_group_MoveCharacter(characterFromID("Eng_soldier_3"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Eng_Soldier_4"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Red_patrol_7"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Red_patrol_8"), LAI_GROUP_PLAYER);
			Locations[FindLocation("Redmond_town_03")].vcskip = true;
			Pchar.quest.treachery_gate_battle1.win_condition.l1 = "location";
			Pchar.quest.treachery_gate_battle1.win_condition.l1.location = "Redmond_town_03";
			Pchar.quest.treachery_gate_battle1.win_condition.l2 = "Time";
			Pchar.quest.treachery_gate_battle1.win_condition.l2.time = DAY_TIME_NIGHT;
			PChar.quest.treachery_gate_battle1.win_condition = "treachery_gate_battle1";
//			ChangeCharacterAddressGroup(characterFromID("Red_patrol_8"), "Redmond_town_03", "goto", "goto44"); // Should not be needed when new version of "Characters\init\Redmond.c" is in effect
		break;

		case "treachery_gate_battle1":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			for (n=1; n<7; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[PIRATE].fantomModel.(temp), "reload", "Door_12");
				LAi_SetImmortal(sld, true);
				sld.id = "Downing gang " + n;
				sld.nation = PIRATE;
				SetRandomNameToCharacter(sld);
				DeleteAttribute(sld,"Items.gunpowder");
				DeleteAttribute(sld,"Items.pistolbullets");
				DeleteAttribute(sld,"Items.pistolgrapes");
				DeleteAttribute(sld,"Items.musketbullets");
				TakeItemFromCharacter(sld, GetCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
				TakeItemFromCharacter(sld, GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE));
				GiveItem2Character(sld, "blade50");
				EquipCharacterByItem(sld, "blade50");
				GiveItem2Character(sld, "pistolpdart");
				EquipCharacterByItem(sld, "pistolpdart");
			}
			for (n=1; n<4; n++)
			{
				LAi_SetActorType(characterFromID("Downing gang " + n));
				LAi_ActorAttack(characterfromID("Downing gang " + n), characterfromID("Red_patrol_7"), "");
			}
			for (n=4; n<7; n++)
			{
				LAi_SetActorType(characterFromID("Downing gang " + n));
				LAi_ActorAttack(characterfromID("Downing gang " + n), characterfromID("Red_patrol_8"), "");
			}
			LAi_QuestDelay("treachery_gate_battle2", 10.0);
		break;

		case "treachery_gate_battle2":
			for (n=7; n<11; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[PIRATE].fantomModel.(temp), "reload", "Door_12");
				sld.id = "Downing gang " + n;
				sld.nation = PIRATE;
				SetRandomNameToCharacter(sld);
			}
			for (n=1; n<11; n++)
			{
				sld = CharacterFromID("Downing gang " + n);
				LAi_SetImmortal(sld, false);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			}
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "treachery_gate_battle_won");
		break;

		case "treachery_gate_battle_won":
			PChar.quest.treachery_invasion_happens.over = "yes";
			PChar.quest.ardent_treachery_status = "foiled";
			LAi_SetFightMode(PChar, false);
			LAi_SetActorType(PChar);
			LAi_type_actor_Reset(PChar);
			PlaySound("AMBIENT\TOWN\Alarm.wav");
			LAi_group_MoveCharacter(characterFromID("Eng_soldier_3"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Eng_Soldier_4"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Red_patrol_7"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Red_patrol_8"), "ENGLAND_SOLDIERS");
			DeleteAttribute(&Locations[FindLocation("Redmond_town_03")],"vcskip");

			Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "ardent_treachery_reward";

			for (n=1; n<4; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.(temp), "reload", "reload_3_2");
				sld.id = "Reinforcements " + n;
				sld.greeting = "Gr_Patrol";
				sld.nation = ENGLAND;
				SetRandomNameToCharacter(sld);
				LAi_SetActorType(sld);
				LAi_ActorRunToLocation(sld, "reload", "reload_3_3", "none", "", "", "", 30.0);
			}
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m0, "reload", "reload_3_2");
			sld.id = "Reinforcements commander";
			sld.greeting = "Gr_Greenford Commander";
			sld.Dialog.Filename = "guard_dialog.c";
			sld.dialog.CurrentNode = "treachery_reinforcements";
			LAi_ActorWaitDialog(PChar, characterFromID("Reinforcements commander"));
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld,PChar,"treachery_confirmation",30.0,30.0);
		break;

		case "treachery_confirmation":
			LAi_SetPlayerType(PChar);
			speaker = "";
			if (!LAi_IsDead(characterfromID("Red_patrol_7"))) speaker = "Red_patrol_7";
			if (!LAi_IsDead(characterfromID("Eng_soldier_4"))) speaker = "Eng_soldier_4";
			if (!LAi_IsDead(characterfromID("Eng_soldier_3"))) speaker = "Eng_soldier_3";
			if (speaker !="")
			{
//				PChar.quest.normal_dialog = characters[GetCharacterIndex(speaker)].Dialog.Filename;
				StoreDialog(CharacterFromID(speaker));
				PChar.quest.treachery_survivor = speaker;
				LAi_SetActorType(characterFromID(speaker));
				Characters[GetCharacterIndex(speaker)].Dialog.Filename = "guard_dialog.c";
				Characters[GetCharacterIndex(speaker)].dialog.CurrentNode = "treachery_survivor";
				LAi_ActorDialog(CharacterFromID(speaker),PChar,"treachery_confirmation2",30.0,30.0);
			}
			else
			{
				Characters[GetCharacterIndex("Reinforcements commander")].dialog.CurrentNode = "treachery_reinforcements2";
				LAi_SetActorType(characterFromID("Reinforcements commander"));
				LAi_ActorDialog(characterFromID("Reinforcements commander"),PChar,"treachery_in_prison",10.0,10.0);
			}
		break;

		case "treachery_confirmation2":
//			Characters[GetCharacterIndex(PChar.quest.treachery_survivor)].Dialog.Filename = "PChar.quest.normal_dialog";
			RestoreDialog(CharacterFromID(PChar.quest.treachery_survivor));
			DeleteQuestAttribute("treachery_survivor");
			EndQuestMovie();
			DisableFastTravel(false);
			Characters[GetCharacterIndex("Reinforcements commander")].dialog.CurrentNode = "treachery_story_confirmed";
			LAi_SetActorType(characterFromID("Reinforcements commander"));
			LAi_ActorDialog(characterFromID("Reinforcements commander"),PChar,"",10.0,10.0);
		break;

		case "treachery_arrest": // Triggered by dialog with "John Clifford Brin" if you are hostile to England
			PChar.quest.treachery_invasion_happens.over = "yes";
			LAi_SetImmortal(characterFromID("John Clifford Brin"), true);
			LAi_SetActorType(characterFromID("John Clifford Brin"));
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "ardent_treachery_pardon";
			LAi_LocationFightDisable(&Locations[FindLocation("Redmond_Residence")], false);
			Ambush("Soldiers", 8, "enemy", "friend", "reload1");
			LAi_QuestDelay("treachery_in_prison", 10.0);
		break;

		case "treachery_in_prison":
			LAi_LocationFightDisable(&Locations[FindLocation("Redmond_Residence")], true);
			Locations[FindLocation("Redmond_prison")].vcskip = true;
			DoQuestReloadToLocation("Redmond_prison", "goto", "goto24", "_");
			LAi_Fade("treachery_in_prison2", "treachery_in_prison3");
		break;

		case "treachery_in_prison2":
			if (!CheckQuestAttribute("ardent_treachery_status", "foiled"))
			{
				WaitDate("", 0, 0, 1 + rand(3), 0, 0);
				PChar.quest.ardent_treachery_status = "foiled";
			}
			else WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10, 10);
		break;

		case "treachery_in_prison3":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto9", "", 10.0);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m0, "goto", "goto22");
			sld.id = "Temp Prison Commander";
			sld.greeting = "Gr_Redmond Commendant";
			AddQuestRecord("Treachery", 6);
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "reload", "reload12", "treachery_release", 30.0);
		break;

		case "treachery_release":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, characterFromID("Temp Prison Commander"));
			LAi_SetActorType(characterFromID("Temp Prison Commander"));
			Characters[GetCharacterIndex("Temp Prison Commander")].Dialog.Filename = "guard_dialog.c";
			Characters[GetCharacterIndex("Temp Prison Commander")].dialog.CurrentNode = "treachery_goto_governor";
			LAi_ActorDialog(characterFromID("Temp Prison Commander"),PChar,"treachery_back_to_governor",5.0,5.0);
		break;

		case "treachery_back_to_governor":
			DoQuestReloadToLocation("Redmond_Residence", "goto", "goto2", "treachery_back_to_governor2");
		break;

		case "treachery_back_to_governor2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("John Clifford Brin"));
			LAi_ActorDialogNow(characterFromID("John Clifford Brin"),PChar,"",1.0);
		break;

		case "hunt_setup_Gilbert": // Triggered by dialog with "John Clifford Brin" - has to be triggered from dialog because you might have gone there after battle at the gate
			Locations[FindLocation("Redmond_town_03")].reload.l9.disable = 0; // Re-open house of Gilbert Downing in case it was closed earlier
			LAi_SetHuberStayType(characterFromID("John Clifford Brin"));
			DeleteAttribute(&Locations[FindLocation("Redmond_prison")],"vcskip");
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("pronoun", villain.sex);
			Preprocessor_AddQuestData("pronoun2", GetMyPronounObj(villain));
			SetQuestHeader("Villain_Hunt");
			AddQuestRecord("Villain_Hunt", 1);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("villain");
			EndQuestMovie();
			DisableFastTravel(false);
			Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "hunt_ask_gilbert";
		break;

		case "hunt_villain_to_st_martin":
			PChar.quest.ardent_hunt_status = "searching";
			GiveShip2Character(villain, "SwedishIndiaman1", "Entreprenant", -1, ENGLAND, true, true);
			setCharacterShipLocation(CharacterFromId("French_Amiral"), "Marigot_port");
//			if (!LAi_IsDead(characterfromID("French_Captain2"))) setCharacterShipLocation(CharacterFromId("French_Captain2"), "Marigot_port");
//			if (!LAi_IsDead(characterfromID("French_Captain3"))) setCharacterShipLocation(CharacterFromId("French_Captain3"), "Marigot_port");
//			if (!LAi_IsDead(characterfromID("French_Contre-Amiral"))) setCharacterShipLocation(CharacterFromId("French_Contre-Amiral"), "Marigot_port");
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromId(PChar.quest.villain))));
			AddQuestRecord("Villain_Hunt", 2);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("villain");
		break;

		case "hunt_laurence_goes_to_window":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			LAi_SetActorType(characterfromID("Laurence Wellman"));
			LAi_ActorGoToLocator(characterfromID("Laurence Wellman"), "goto", "locator2", "hunt_laurence_goes_to_window2", 10.0);
		break;

		case "hunt_laurence_goes_to_window2":
			LAi_ActorTurnToLocator(characterfromID("Laurence Wellman"), "box", "box1");
			LAi_QuestDelay("hunt_laurence_back_from_window", 3.0);
		break;

		case "hunt_laurence_back_from_window":
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_SetActorType(characterfromID("Laurence Wellman"));
			Characters[GetCharacterIndex("Laurence Wellman")].dialog.CurrentNode = "ardent_hunt_which_ship3";
			LAi_ActorDialog(characterFromID("Laurence Wellman"),PChar,"hunt_reset_laurence",5.0,5.0);

			PChar.quest.ardent_hunt_status = "philipsburg";
			StoreDialog(characterFromID("Adam Groot"));
			StoreDialog(characterFromID("Hubert Decker"));
			characters[GetCharacterIndex("Adam Groot")].Dialog.Filename = "witness_dialog.c";
			characters[GetCharacterIndex("Hubert Decker")].Dialog.Filename = "witness_dialog.c";
			Characters[GetCharacterIndex("Adam Groot")].dialog.CurrentNode = "hunt_philipsburg_citizen";
			Characters[GetCharacterIndex("Hubert Decker")].dialog.CurrentNode = "hunt_philipsburg_citizen";
		break;

		case "hunt_reset_laurence":
			LAi_SetStayType(characterFromID("Laurence Wellman"));
			PChar.quest.hunt_reset_laurence2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.hunt_reset_laurence2.win_condition.l1.location = PChar.location;
			PChar.quest.hunt_reset_laurence2.win_condition = "hunt_reset_laurence2";
		break;

		case "hunt_reset_laurence2":
			ChangeCharacterAddressGroup(characterFromID("Laurence Wellman"), "Redmond_Head_port_house", "goto", "locator1");
		break;

		case "hunt_try_marigot": // Triggered by dialog with Philipsburg port citizen
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromId(PChar.quest.villain))));
			AddQuestRecord("Villain_Hunt", 5);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("villain");
			PChar.quest.ardent_hunt_status = "ship_known_marigot";
			DeleteQuestAttribute("tavern_checked");

			RestoreDialog(characterFromID("Adam Groot"));
			RestoreDialog(characterFromID("Hubert Decker"));

			StoreDialog(characterFromID("Aubert Boogard"));
			StoreDialog(characterFromID("Pierre Dunere"));
			characters[GetCharacterIndex("Aubert Boogard")].Dialog.Filename = "witness_dialog.c";
			characters[GetCharacterIndex("Pierre Dunere")].Dialog.Filename = "witness_dialog.c";
			Characters[GetCharacterIndex("Aubert Boogard")].dialog.CurrentNode = "hunt_marigot_citizen";
			Characters[GetCharacterIndex("Pierre Dunere")].dialog.CurrentNode = "hunt_marigot_citizen";
		break;

		case "hunt_seen_battleship": // triggered by dialog with Marigot port citizen
			RestoreDialog(characterFromID("Aubert Boogard"));
			RestoreDialog(characterFromID("Pierre Dunere"));

			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			Preprocessor_AddQuestData("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			AddQuestRecord("Villain_Hunt", 6);
			Preprocessor_Remove("warship");
			Preprocessor_Remove("villain");
			PChar.quest.ardent_hunt_status = "ship_known_guadeloupe";
			DeleteQuestAttribute("tavern_checked");
			setCharacterShipLocation(villain, "Guadeloupe_Port");
			ChangeCharacterAddressGroup(characterFromID("Felix Prost"), "Pointe_a_pitre_Tavern", "goto", "goto8");

			ch = CharacterFromID("Antigua_Portadmiral");
			StoreDialog(ch);
			ch.Dialog.Filename  = "quest_antigua_portadmiral_dialog.c";
			ch.dialog.CurrentNode = "First time";
		break;

		case "reset_antigua_portadmiral":
			ch = CharacterFromID("Antigua_Portadmiral");
			RestoreDialog(ch);
		break;

		case "hunt_admiral_owes_money": // Triggered by dialog with Antigua admiral using "quest_antigua_portadmiral_dialog.c"
			if (makeint(PChar.quest.hunt_admiral_owes) != 0)
			{
				PChar.quest.hunt_admiral_report_back.win_condition.l1 = "Timer";
				PChar.quest.hunt_admiral_report_back.win_condition.l1.date.day = GetAddingDataDay(0, 0, 14);
				PChar.quest.hunt_admiral_report_back.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
				PChar.quest.hunt_admiral_report_back.win_condition.l1.date.year = GetAddingDataYear(0, 0, 14);
				PChar.quest.hunt_admiral_report_back.win_condition = "hunt_admiral_report_back";
			}
			LAi_QuestDelay("reset_antigua_portadmiral", 0.5);
		break;

		case "sink_dauphin_escort":
			LAi_KillCharacter(characterfromID("French_Contre-Amiral"));	// The above is happening because you reported the Dauphin Royal, so admiral
			LAi_KillCharacter(characterfromID("French_Captain2"));		// sends task force which doesn't sink Dauphin but does sink escorts.
			LAi_KillCharacter(characterfromID("French_Captain3"));
		break;

		case "hunt_admiral_report_back":
			ch = CharacterFromID("Antigua_Portadmiral");
			StoreDialog(ch);
			ch.Dialog.Filename  = "quest_antigua_portadmiral_dialog.c";
			ch.dialog.CurrentNode = "ardent_hunt_pay_balance";
			if (makeint(PChar.quest.hunt_admiral_owes) != 0) PChar.quest.hunt_admiral_ready_to_pay = "true";
		break;

		case "hunt_call_crewman": // Triggered by dialog with Albin Bonaventure
			LAi_SetActorType(characterfromID("Felix Prost"));
			Characters[GetCharacterIndex("Felix Prost")].dialog.CurrentNode = "hunt_what_is_it";
			LAi_ActorDialog(characterFromID("Felix Prost"),PChar,"hunt_reset_crewman",5.0,5.0);
		break;

		case "hunt_reset_crewman":
			LAi_SetStayType(characterfromID("Felix Prost"));
			PChar.quest.hunt_reset_crewman2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.hunt_reset_crewman2.win_condition.l1.location = PChar.location;
			PChar.quest.hunt_reset_crewman2.win_condition = "hunt_reset_crewman2";
			ChangeCharacterAddressGroup(villain, "Guadeloupe_Port", "goto", "goto18");
			LAi_SetStayType(villain);
			Characters[villainidx].dialog.CurrentNode = "hunt_guadeloupe_encounter1";
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("ship", villain.Ship.Name);
			AddQuestRecord("Villain_Hunt", 12);
			Preprocessor_Remove("ship");
			Preprocessor_Remove("villain");
			PChar.quest.ardent_hunt_status = "villain_known_guadeloupe";
		break;

		case "hunt_reset_crewman2":
			ChangeCharacterAddress(characterFromID("Felix Prost"), "None", "");
		break;

		case "hunt_guadeloupe_arrest1": // Triggered by dialog with Piers / Valerie Downing
			PChar.quest.academy_breakin_name = "hunt";
			LAi_SetActorType(PChar);
//			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, characterFromID("Guadeloupe_guard_1"));
			Locations[FindLocation("PaP_prison")].vcskip = true;
			Locations[FindLocation("PaP_prison")].models.always.locators = "Pri_l_GR";
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			LAi_SetActorType(CharacterFromID("Guadeloupe_guard_1"));
			LAi_ActorRunToLocator(CharacterFromID("Guadeloupe_guard_1"), "goto", "goto18", "", 5.0)
			LAi_QuestDelay("hunt_guadeloupe_arrest2", 2.0);
		break;

		case "hunt_guadeloupe_arrest2":
			ch = CharacterFromID("Guadeloupe_guard_1");
//			PChar.quest.normal_dialog = ch.Dialog.Filename;
			StoreDialog(ch);
			ch.Dialog.Filename = "guard_dialog.c";
			ch.dialog.CurrentNode = "hunt_guard_arrest";
			LAi_SetActorType(ch);
			LAi_ActorDialog(ch,PChar,"",10.0,10.0); // Exits to "to_guadeloupe_prison1" or "hunt_resist_arrest"
		break;

		case "hunt_resist_arrest":
			LAi_SetPlayerType(PChar);
			LAi_SetImmortal(villain, true);
			LAi_SetActorType(villain);
			LAi_ActorRunToLocation(villain, "reload", "academy", "none", "", "", "", 30.0);
//			LAi_SetWarriorType(CharacterFromID("Guadeloupe_guard_1"));
			LAi_SetActorType(CharacterFromID("Guadeloupe_guard_1"));
			LAi_ActorAttack(characterfromID("Guadeloupe_guard_1"), PChar, "");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
//	        	LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, LAi_IsImmortal(PChar), "to_guadeloupe_prison1");
			LAi_QuestDelay("to_guadeloupe_prison1", 10.0);
		break;

		case "to_guadeloupe_prison1":
			if (CheckAttribute(PChar, "quest.cancel_SetCheckMinHP")) Pchar.quest.cancel_SetCheckMinHP.over = "yes";
			Locations[FindLocation("PaP_prison")].locators_radius.reload.reload12 = 2.0;
			ch = CharacterFromID("Guadeloupe_guard_1");
//			ch.Dialog.Filename = PChar.quest.normal_dialog;
//			ch.dialog.CurrentNode = "First time";
			RestoreDialog(ch);
			LAi_SetGuardianType(ch);
			DoQuestReloadToLocation("PaP_prison", "goto", "goto24", "to_guadeloupe_prison2");
		break;

		case "to_guadeloupe_prison2":
			SetCurrentTime(22, rand(59));
			ChangeCharacterAddress(villain, "None", "");
			StorePassengers(PChar.id);
			PChar.quest.old_blade = GetCharacterEquipByGroup(PChar, BLADE_ITEM_TYPE);
			PChar.quest.old_gun = GetCharacterEquipByGroup(PChar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(PChar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(PChar, BLADE_ITEM_TYPE);
			EnableEquip(PChar, GUN_ITEM_TYPE, false);
			EnableEquip(PChar, BLADE_ITEM_TYPE, false);
			TempRemoveItems(PChar);
			LAi_LocationFightDisable(&Locations[FindLocation("PaP_prison")], true);
			LAi_SetActorType(PChar);

			ChangeCharacterAddressGroup(characterFromID("Fr_Prison_guard4"), "PaP_prison", "reload", "reload5");
			LAi_SetActorType(characterfromID("Fr_Prison_guard4"));
			LAi_ActorGoToLocator(characterfromID("Fr_Prison_guard4"), "reload", "reload12", "guadeloupe_prison_talk_to_guard", 60.0);
		break;

		case "guadeloupe_prison_talk_to_guard":
//			LAi_type_actor_Reset(PChar);
//			LAi_ActorWaitDialog(PChar, characterFromID("Fr_Prison_guard4"));
			LAi_SetPlayerType(PChar);
			characters[GetCharacterIndex("Fr_Prison_guard4")].Dialog.Filename = "guard_dialog.c";
			if (PChar.sex == "man") Characters[GetCharacterIndex("Fr_Prison_guard4")].dialog.CurrentNode = "hunt_taunt_guard";
			else Characters[GetCharacterIndex("Fr_Prison_guard4")].dialog.CurrentNode = "hunt_flirt_guard";
			LAi_ActorDialogNow(characterFromID("Fr_Prison_guard4"),PChar,"guadeloupe_prison_guard_enters_cell",1.0);
		break;

		case "guadeloupe_prison_guard_enters_cell":
			ChangeCharacterAddressGroup(characterFromID("Fr_Prison_guard4"), "PaP_prison", "goto", "goto25");
			LAi_SetPlayerType(PChar);
			if (!CheckCharacterItem(pchar, "bladeX4")) GiveItem2Character(pchar, "bladeX4");
			EquipCharacterByItem(PChar, "bladeX4");
			LAi_SetActorType(characterfromID("Fr_Prison_guard4"));
			if (PChar.sex == "man") Characters[GetCharacterIndex("Fr_Prison_guard4")].dialog.CurrentNode = "hunt_teach_manners";
			else Characters[GetCharacterIndex("Fr_Prison_guard4")].dialog.CurrentNode = "hunt_get_comfortable";
			LAi_ActorDialogNow(characterFromID("Fr_Prison_guard4"),PChar,"guadeloupe_prison_knockout_guard",1.0);
		break;

		case "guadeloupe_prison_knockout_guard":
			LAi_LocationFightDisable(&Locations[FindLocation("PaP_prison")], false);
			EquipCharacterByItem(PChar, "bladeX4");
			GiveItem2Character(characterfromID("Fr_Prison_guard4"), "bladeX4");
			EquipCharacterByItem(characterfromID("Fr_Prison_guard4"), "bladeX4");
			LAi_ActorAttack(characterfromID("Fr_Prison_guard4"), PChar, "");
	       		LAi_SetCheckMinHP(characterFromID("Fr_Prison_guard4"), LAi_GetCharacterHP(characterFromID("Fr_Prison_guard4"))-2.0, false, "guadeloupe_prison_guard_out_cold");
		break;

		case "guadeloupe_prison_guard_out_cold":
			LAi_SetStunnedTypeNoGroup(characterFromID("Fr_Prison_guard4"));
			GiveItem2Character(PChar, "blade4");
			EquipCharacterByItem(PChar, "blade4");
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto25", "guadeloupe_prison_escape_cell", 5.0);
		break;

		case "guadeloupe_prison_escape_cell":
			PlaySound("PEOPLE\lockpick2.wav");
			LAi_QuestDelay("guadeloupe_prison_escape_cell2", 2.0);
		break;

		case "guadeloupe_prison_escape_cell2":
//			DoReloadCharacterToLocation("PaP_prison", "reload", "reload12");
			ChangeCharacterAddressGroup(PChar, "PaP_prison", "reload", "reload12");
			for (n=1; n<4; n++)
			{
				sld = characterFromID("Fr_Prison_guard" + n);
				ChangeCharacterAddressGroup(sld, "PaP_prison", "goto", "goto" + (17 + n));
			}
			LAi_QuestDelay("guadeloupe_prison_escape_cell3", 0.1);
		break;

		case "guadeloupe_prison_escape_cell3":
			LAi_SetPlayerType(PChar);
			RemoveCharacterEquip(PChar, GUN_ITEM_TYPE);
			EquipCharacterByItem(PChar, "blade4");
//			EquipCharacterByItem(pchar, "pistolrock");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "guadeloupe_prison_escape_prison");
		break;

		case "guadeloupe_prison_escape_prison":
			EndQuestMovie();
			LAi_LocationFightDisable(&Locations[FindLocation("PaP_prison")], true);
			LAi_SetFightMode(PChar, false);
			Locations[FindLocation("PaP_Academy")].models.always.locators = "sh04_locators_GR";
			if (!LAi_IsDead(characterfromID("French_guard1")) || !LAi_IsDead(characterfromID("French_guard2")))
			{
				ChangeCharacterAddressGroup(characterfromID("French_guard1"), "PaP_Arsenal", "goto", "goto3");
				ChangeCharacterAddressGroup(characterfromID("French_guard2"), "PaP_Arsenal", "goto", "goto4");
				LAi_SetActorType(characterfromID("French_guard1"));
				LAi_ActorTurnToLocator(characterfromID("French_guard1"), "reload", "reload2");
				LAi_SetActorType(characterfromID("French_guard2"));
				LAi_ActorTurnToLocator(characterfromID("French_guard2"), "reload", "reload2");
			}

			PChar.quest.guadeloupe_prison_out_of_cells.win_condition.l1 = "location";
			PChar.quest.guadeloupe_prison_out_of_cells.win_condition.l1.location = "PaP_Guardhouse";
			PChar.quest.guadeloupe_prison_out_of_cells.win_condition = "guadeloupe_prison_out_of_cells";

			Pchar.quest.guadeloupe_prison_escape_prison2.win_condition.l1 = "location";
			Pchar.quest.guadeloupe_prison_escape_prison2.win_condition.l1.location = "PaP_Arsenal";
			PChar.quest.guadeloupe_prison_escape_prison2.win_condition = "guadeloupe_prison_escape_prison2";

			PChar.quest.guadeloupe_prison_remove_bodies1.win_condition.l1 = "ExitFromLocation";
			PChar.quest.guadeloupe_prison_remove_bodies1.win_condition.l1.location = PChar.location;
			PChar.quest.guadeloupe_prison_remove_bodies1.win_condition = "guadeloupe_prison_remove_bodies1";
		break;

		case "guadeloupe_prison_remove_bodies1":
			for (n=1; n<5; n++)
			{
				ChangeCharacterAddress(characterFromID("Fr_Prison_guard" + n), "None", "");
			}
		break;

		case "guadeloupe_prison_escape_prison2":
			if (!LAi_IsDead(characterfromID("French_guard1")) || !LAi_IsDead(characterfromID("French_guard2")))
			{
				StartQuestMovie(true, true, false);
				LAi_group_MoveCharacter(characterfromID("French_guard1"), "FRANCE_SOLDIERS");
				LAi_group_MoveCharacter(characterfromID("French_guard2"), "FRANCE_SOLDIERS");
				LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
				LAi_group_SetCheck("FRANCE_SOLDIERS", "guadeloupe_prison_escape_guards_defeated");
			}
			RestorePassengers(PChar.id);
			Pchar.quest.guadeloupe_prison_rejoin_crew.win_condition.l1 = "location";
			Pchar.quest.guadeloupe_prison_rejoin_crew.win_condition.l1.location = "Guadeloupe_Port";
			PChar.quest.guadeloupe_prison_rejoin_crew.win_condition = "guadeloupe_prison_rejoin_crew";

			if (CheckQuestAttribute("academy_breakin_name", "hunt"))
			{
				Pchar.quest.hunt_academy_breakin.win_condition.l1 = "locator";
				Pchar.quest.hunt_academy_breakin.win_condition.l1.location = "Guadeloupe_Port";
				Pchar.quest.hunt_academy_breakin.win_condition.l1.locator_group = "goto";
				Pchar.quest.hunt_academy_breakin.win_condition.l1.locator = "goto25";
				Pchar.quest.hunt_academy_breakin.win_condition.l2 = "Time";
				Pchar.quest.hunt_academy_breakin.win_condition.l2.time = DAY_TIME_NIGHT;
				PChar.quest.hunt_academy_breakin.win_condition = "academy_breakin";

				if (GetCharacterShipLocation(PChar) == "Guadeloupe_Port")
				{
					PChar.quest.hunt_arrested_on_ship.win_condition.l1 = "locator";
					PChar.quest.hunt_arrested_on_ship.win_condition.l1.location = "Guadeloupe_Port";
					PChar.quest.hunt_arrested_on_ship.win_condition.l1.locator_group = "reload";
					PChar.quest.hunt_arrested_on_ship.win_condition.l1.locator = "reload2_back";
					PChar.quest.hunt_arrested_on_ship.win_condition = "hunt_arrested_on_ship";
				}
				else
				{
					PChar.quest.hunt_arrested_on_ship_beach.win_condition.l1 = "locator";
					PChar.quest.hunt_arrested_on_ship_beach.win_condition.l1.location = "Guadeloupe_shore_01";
					PChar.quest.hunt_arrested_on_ship_beach.win_condition.l1.locator_group = "reload";
					PChar.quest.hunt_arrested_on_ship_beach.win_condition.l1.locator = "boat";
					PChar.quest.hunt_arrested_on_ship_beach.win_condition = "hunt_arrested_on_ship";
				}
			}
		break;

		case "guadeloupe_prison_escape_guards_defeated":
			EndQuestMovie();
			PChar.quest.guadeloupe_prison_remove_bodies2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.guadeloupe_prison_remove_bodies2.win_condition.l1.location = PChar.location;
			PChar.quest.guadeloupe_prison_remove_bodies2.win_condition = "abduction_remove_bodies"; // No need for additional code to remove these two, re-use the same code from "Abduction"
		break;

		case "guadeloupe_prison_out_of_cells":
			logit(TranslateString("","You found all your weapons."));
			PlayStereoSound("interface\important_item.wav");
			RemoveCharacterEquip(PChar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(PChar, BLADE_ITEM_TYPE);
			RestoreTempRemovedItems(PChar);
			EnableEquip(PChar, GUN_ITEM_TYPE, true);
			EnableEquip(PChar, BLADE_ITEM_TYPE,true);
			if (PChar.quest.old_blade != "") EquipCharacterByItem(PChar,PChar.quest.old_blade);
			if (PChar.quest.old_gun != "") EquipCharacterByItem(PChar,PChar.quest.old_gun);
			DeleteQuestAttribute("old_blade");
			DeleteQuestAttribute("old_gun");
		break;

		case "guadeloupe_prison_rejoin_crew":
			LAi_SetFightMode(PChar, false);
			if (CheckQuestAttribute("academy_breakin_name", "hunt"))
			{
				bQuestDisableSeaEnter = true;
				Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
				AddQuestRecord("Villain_Hunt", 13);
				Preprocessor_Remove("villain");
			}
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				StoreDialog(crewref);
				LAi_SetActorType(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "hunt_what_we_did";
				LAi_ActorDialog(crewref, pchar, "guadeloupe_prison_reset_officer", 5.0, 5.0);
			}
		break;

		case "guadeloupe_prison_reset_officer":
			if (!CheckQuestAttribute("academy_breakin_name", "hunt")) DisableFastTravel(false);
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewref = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				RestoreDialog(crewref);
				LAi_SetOfficerType(CharacterFromId(characters[crewidx].id));
			}
		break;

		case "academy_breakin":
			DisableFastTravel(true);
			Locations[FindLocation("PaP_Academy")].reload.l1.disable = 1;
			PlaySound("AMBIENT\TOWN\window_dog.wav");
			LAi_QuestDelay("academy_through_window", 0.5);
		break;

		case "academy_through_window":
			DoQuestReloadToLocation("PaP_Academy", "goto", "goto3", "academy_breakin2");
		break;

		case "academy_breakin2":
			Pchar.quest.academy_breakin_foundit.win_condition.l1 = "locator";
			Pchar.quest.academy_breakin_foundit.win_condition.l1.location = "PaP_Academy";
			Pchar.quest.academy_breakin_foundit.win_condition.l1.locator_group = "box";
			Pchar.quest.academy_breakin_foundit.win_condition.l1.locator = "box1";
			PChar.quest.academy_breakin_foundit.win_condition = PChar.quest.academy_breakin_name + "_academy_breakin_foundit";
		break;

		case "hunt_academy_breakin_foundit":
			GiveItem2Character(PChar, "BattleOrders");
			AddQuestRecord("Villain_Hunt", 14);
			Pchar.dialog.CurrentNode = "hunt_found_orders";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "academy_breakin_now_get_out");
			ch = CharacterFromID("Antigua_Portadmiral");
			StoreDialog(ch);
			characters[GetCharacterIndex("Antigua_Portadmiral")].Dialog.Filename = "quest_antigua_portadmiral_dialog.c";
			if (CheckAttribute(PChar, "quest.hunt_admiral_owes"))
			{
				if (makeint(PChar.quest.hunt_admiral_owes) == 0) Characters[GetCharacterIndex("Antigua_Portadmiral")].dialog.CurrentNode = "ardent_hunt_return_visit";
				else
				{
					Characters[GetCharacterIndex("Antigua_Portadmiral")].dialog.CurrentNode = "ardent_hunt_pay_balance";
					PChar.quest.hunt_admiral_report_back.over = "yes";
				}
			}
			else Characters[GetCharacterIndex("Antigua_Portadmiral")].dialog.CurrentNode = "First time";
		break;

		case "threat_academy_breakin_foundit":
			GiveItem2Character(PChar, "BattleOrders2");
			Preprocessor_AddQuestData("governor", GetMySimpleName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Santiago Threat", 4);
			Preprocessor_Remove("governor");
			Pchar.dialog.CurrentNode = "threat_found_orders";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "academy_breakin_now_get_out");
		break;

		case "academy_breakin_now_get_out":
			LAi_SetPlayerType(PChar);
			Pchar.quest.academy_breakin_escape.win_condition.l1 = "locator";
			Pchar.quest.academy_breakin_escape.win_condition.l1.location = "PaP_Academy";
			Pchar.quest.academy_breakin_escape.win_condition.l1.locator_group = "goto";
			Pchar.quest.academy_breakin_escape.win_condition.l1.locator = "goto3";
			PChar.quest.academy_breakin_escape.win_condition = "academy_breakin_escape";
		break;

		case "academy_breakin_escape":
			Locations[FindLocation("PaP_Academy")].reload.l1.disable = 0;
			DoQuestReloadToLocation("Guadeloupe_Port", "goto", "goto25", PChar.quest.academy_breakin_name + "_out_of_academy");
		break;

		case "hunt_out_of_academy":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	        	LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-5.0, false, "hunt_back_in_prison");
			PChar.quest.cancel_SetCheckMinHP.win_condition.l1 = "location";
			PChar.quest.cancel_SetCheckMinHP.win_condition.l1.location = "Guadeloupe";
			PChar.quest.cancel_SetCheckMinHP.win_condition = "cancel_SetCheckMinHP";
		break;

		case "threat_out_of_academy":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	        	LAi_SetCheckMinHP(PChar, LAi_GetCharacterHP(Pchar)-5.0, false, "to_guadeloupe_prison1");
			PChar.quest.cancel_SetCheckMinHP.win_condition.l1 = "location";
			PChar.quest.cancel_SetCheckMinHP.win_condition.l1.location = "Guadeloupe";
			PChar.quest.cancel_SetCheckMinHP.win_condition = "cancel_SetCheckMinHP";
		break;

		case "cancel_SetCheckMinHP":
			LAi_RemoveCheckMinHP(PChar);
			if (!CheckQuestAttribute("academy_breakin_name", "hunt")) DisableFastTravel(false);
		break;

		case "hunt_back_in_prison":
			if (CheckAttribute(PChar, "quest.cancel_SetCheckMinHP")) Pchar.quest.cancel_SetCheckMinHP.over = "yes";
			DoQuestReloadToLocation("PaP_prison", "goto", "goto9", "hunt_back_in_prison2");
			PChar.quest.hunt_arrested_on_ship.over = "yes";
			Pchar.quest.hunt_arrested_on_ship_beach.over = "yes";
		break;

		case "hunt_back_in_prison2":
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10, 10);
			ChangeCharacterAddressGroup(villain, "PaP_prison", "reload", "reload5");
			LAi_SetActorType(villain);
			LAi_ActorGoToLocator(villain, "reload", "reload12", "hunt_villain_taunts_in_prison", 60.0);
		break;

		case "hunt_villain_taunts_in_prison":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "hunt_prison_morning";
			LAi_ActorDialogNow(villain, PChar, "hunt_with_villain_to_governor",1.0);
		break;

		case "hunt_with_villain_to_governor":
			ChangeCharacterAddressGroup(villain, "PaP_townhall", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("French_guard1"), "PaP_townhall", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("French_guard2"), "PaP_townhall", "reload", "reload1");
			DoQuestReloadToLocation("PaP_townhall", "reload", "reload1", "hunt_with_villain_to_governor2");
		break;

		case "hunt_with_villain_to_governor2":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto8", "hunt_with_villain_to_governor3", 10.0);
			LAi_SetActorType(characterFromID("French_guard1"));
			LAi_SetActorType(characterFromID("French_guard2"));
			LAi_ActorFollow(characterFromID("French_guard1"), PChar, "", 20.0);
			LAi_ActorFollow(characterFromID("French_guard2"), PChar, "", 20.0);
		break;

		case "hunt_with_villain_to_governor3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Remy Gatien_gov"));
			Characters[GetCharacterIndex("Remy Gatien_gov")].dialog.CurrentNode = "ardent_hunt_brought_in";
			LAi_ActorDialogNow(characterFromID("Remy Gatien_gov"), PChar, "hunt_villain_to_gov1",1.0);
		break;

		case "hunt_villain_to_gov1":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "hunt_ardent_before_governor";
			LAi_ActorDialogNow(villain, PChar, "hunt_gov_to_villain1",1.0);
		break;

		case "hunt_gov_to_villain1":
			LAi_SetActorType(characterFromID("Remy Gatien_gov"));
			Characters[GetCharacterIndex("Remy Gatien_gov")].dialog.CurrentNode = "ardent_hunt_due_to_hang";
			LAi_ActorDialogNow(characterFromID("Remy Gatien_gov"), PChar, "hunt_villain_to_gov2",1.0);
		break;

		case "hunt_villain_to_gov2":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "hunt_better_idea";
			LAi_ActorDialogNow(villain, PChar, "hunt_gov_to_villain2",1.0);
		break;

		case "hunt_gov_to_villain2":
			LAi_SetActorType(characterFromID("Remy Gatien_gov"));
			Characters[GetCharacterIndex("Remy Gatien_gov")].dialog.CurrentNode = "ardent_hunt_like_idea";
			LAi_ActorDialogNow(characterFromID("Remy Gatien_gov"), PChar, "hunt_villain_to_you",1.0);
		break;

		case "hunt_villain_to_you":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "hunt_to_ship";
			LAi_ActorDialogNow(villain, PChar, "hunt_with_villain_to_own_ship",1.0);
		break;

		case "hunt_with_villain_to_own_ship":
			LAi_SetHuberType(characterFromID("Remy Gatien_gov"));
			DeleteAttribute(&Locations[FindLocation("PaP_prison")],"vcskip");
			ChangeCharacterAddressGroup(villain, "hold1", "reload", "reload1");
			if(ispassenger(romance) || isofficer(romance)) PChar.quest.hunt_romance_on_ship = "true";
			DoQuestReloadToLocation("hold1", "rld", "prison4", "hunt_prisoner_on_ship");
		break;

		case "hunt_arrested_on_ship":
			Pchar.quest.hunt_academy_breakin.over = "yes";
			PChar.quest.hunt_arrested_on_ship.over = "yes";
			Pchar.quest.hunt_arrested_on_ship_beach.over = "yes";
	     		LAi_RemoveCheckMinHP(Pchar);	// In case CheckMinHP is still in force because you burgled the academy and evaded recapture
			DisableFastTravel(true);
//			StartQuestMovie(true, true, false);
			ChangeCharacterAddressGroup(villain, GetCharacterShipQDeck(PChar), "reload", "reload1");
			DoQuestReloadToLocation(GetCharacterShipQDeck(PChar), "rld", "startloc", "hunt_arrested_on_ship2");
		break;

		case "hunt_arrested_on_ship2":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, villain);
			LAi_QuestDelay("hunt_arrested_on_ship3", 0.5);
		break;

		case "hunt_arrested_on_ship3":
			LAi_ActorWaitDialog(PChar, villain);
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "hunt_arrested_on_ship";
			LAi_ActorDialog(villain,PChar,"hunt_with_villain_to_own_ship",15.0,15.0);
		break;

		case "hunt_prisoner_on_ship":
			HoistFlag(FRANCE);
			ChangeCharacterAddress(characterFromID("French_guard1"), "None", "");
			ChangeCharacterAddress(characterFromID("French_guard2"), "None", "");
			for (n=1; n<OFFICER_MAX; n++)
			{
				cc = GetOfficersIndex(PChar,n);
				temp = "officer" + n;
				if (cc > 0) PChar.quest.hunt.(temp) = characters[cc].id;
				else PChar.quest.hunt.(temp) = "*NULL*";
			}
			StorePassengers(PChar.id);
			PChar.isnotcaptain = true; // You're not a captain now, you're a prisoner

			if (CheckQuestAttribute("hunt_romance_on_ship", "true"))
			{
				LAi_SetActorType(romance);
				ChangeCharacterAddressGroup(romance, "hold1", "rld", "loc1");
			}
			RemoveCharacterEquip(PChar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(PChar, BLADE_ITEM_TYPE);
			TempRemoveItems(PChar);
			GiveItem2Character(PChar, "bladeX4");
			EquipCharacterByItem(PChar, "bladeX4");
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(PChar);
//			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, villain);
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "hunt_with_villain_in_hold";
			LAi_ActorDialog(villain,PChar,"",5.0,5.0); // Exits to "hunt_romance_joins_villain" or "hunt_villain_leaves_hold"
		break;

		case "hunt_romance_joins_villain":
			LAi_ActorSetSitMode(PChar);
			LAi_ActorWaitDialog(PChar, romance);
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "hunt_join_villain";
			LAi_ActorDialog(romance,PChar,"hunt_that_how_it_is",5.0,5.0);
		break;

		case "hunt_that_how_it_is":
			LAi_ActorSetSitMode(PChar);
			LAi_ActorWaitDialog(PChar, villain);
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "hunt_that_how_it_is";
			LAi_ActorDialog(villain,PChar,"hunt_villain_leaves_hold",5.0,5.0);
		break;

		case "hunt_villain_leaves_hold":
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			if (CheckQuestAttribute("hunt_romance_on_ship", "true"))
			{
				Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
				Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounObj(characterFromID(PChar.quest.villain))));
				AddQuestRecord("Villain_Hunt", 16);
				Preprocessor_Remove("pronoun");
				Preprocessor_Remove("romance");
			}
			else
			{
				AddQuestRecord("Villain_Hunt", 15);
			}
			Preprocessor_Remove("villain");
			LAi_SetActorType(villain);
            		LAi_ActorGoToLocation(villain, "reload", "reload1", "None", "", "", "hunt_hold_time_passes", 20.0);
			if (Characters[romanceidx].location == PChar.location)
			{
				LAi_SetActorType(romance);
            			LAi_ActorGoToLocation(romance, "reload", "reload1", "None", "", "", "", 20.0);
			}
		break;

		case "hunt_hold_time_passes":
			WaitDate("", 0, 0, 10 + rand(5), 0, 0);
			PChar.location.from_sea = "PoPrince_Port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "PChar");
			LAi_QuestDelay("hunt_still_stuck_in_hold", 2.0);
		break;

		case "hunt_still_stuck_in_hold":
			DoQuestReloadToLocation("hold1", "rld", "prison4", "hunt_setup_hold_escape");
		break;

		case "hunt_setup_hold_escape":
			LAi_ActorSetSitMode(PChar);
			for (n=1; n<3; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[PIRATE].fantomModel.(temp), "reload", "reload" + n);
				sld.id = "Hold guard " + n;
				sld.nation = ENGLAND;
				SetRandomNameToCharacter(sld);
				LAi_SetActorType(sld);
			}
			if (CheckQuestAttribute("hunt_romance_on_ship", "true"))
			{
				LAi_SetActorType(romance);
				ChangeCharacterAddressGroup(romance, "hold1", "rld", "loc1");
				LAi_QuestDelay("hunt_romance_rescue", 0.0);
			}
			else
			{
				LAi_SetActorType(CharacterFromID("Steven Seagull"));
				ChangeCharacterAddressGroup(CharacterFromID("Steven Seagull"), "hold1", "rld", "loc1");
				LAi_QuestDelay("hunt_seagull_rescue", 0.0);
			}
		break;

		case "hunt_romance_rescue":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			Lai_KillCharacter(CharacterFromID("Hold guard 1"));
			LAi_QuestDelay("hunt_romance_rescue2", 1.0);
		break;

		case "hunt_romance_rescue2":
			LAi_ActorSetSitMode(PChar);
			LAi_ActorWaitDialog(PChar, romance);
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "hunt_release_you";
			LAi_ActorDialog(romance,PChar,"hunt_romance_rescue3",5.0,5.0);
		break;

		case "hunt_romance_rescue3":
			LAi_SetPlayerType(PChar);
			Characters[romanceidx].dialog.CurrentNode = "hunt_take_knife";
			LAi_ActorDialog(romance,PChar,"hunt_release_player",5.0,5.0);
		break;

		case "hunt_seagull_rescue":
			PlaySound("OBJECTS\DUEL\chalice.wav");
			Lai_KillCharacter(CharacterFromID("Hold guard 1"));
			LAi_QuestDelay("hunt_seagull_rescue2", 1.0);
		break;

		case "hunt_seagull_rescue2":
			LAi_ActorSetSitMode(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Steven Seagull"));
			LAi_SetActorType(CharacterFromID("Steven Seagull"));
			characters[GetCharacterIndex("Steven Seagull")].Dialog.Filename = "crew_dialog.c";
			characters[GetCharacterIndex("Steven Seagull")].dialog.CurrentNode = "hunt_release_you";
			LAi_ActorDialog(CharacterFromID("Steven Seagull"),PChar,"hunt_seagull_rescue3",5.0,5.0);
		break;

		case "hunt_seagull_rescue3":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Steven Seagull")].dialog.CurrentNode = "hunt_take_knife";
			LAi_ActorDialog(CharacterFromID("Steven Seagull"),PChar,"hunt_release_player",5.0,5.0);
		break;

		case "hunt_release_player":
			if (CheckQuestAttribute("hunt_romance_on_ship", "true")) LAi_SetCitizenType(romance);
			else LAi_SetCitizenType(CharacterFromID("Steven Seagull"));
			LAi_SetActorType(characterFromID("Hold guard 2"));
			LAi_ActorAttack(characterfromID("Hold guard 2"), PChar, "");
			Pchar.quest.hunt_second_guard_beaten.win_condition.l1 = "NPC_death";
			Pchar.quest.hunt_second_guard_beaten.win_condition.l1.character = "Hold guard 2";
			Pchar.quest.hunt_second_guard_beaten.win_condition = "hunt_second_guard_beaten";
		break;

		case "hunt_second_guard_beaten":
			LAi_SetFightMode(PChar, false);
			if (CheckQuestAttribute("hunt_romance_on_ship", "true"))
			{
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.currentNode = "hunt_explain_deceit";
				LAi_ActorDialog(romance,PChar,"hunt_find_equipment",5.0,5.0);
			}
			else
			{
				LAi_SetActorType(CharacterFromID("Steven Seagull"));
				characters[GetCharacterIndex("Steven Seagull")].dialog.CurrentNode = "hunt_well_done";
				LAi_ActorDialog(CharacterFromID("Steven Seagull"),PChar,"hunt_find_equipment",5.0,5.0);
			}
		break;

		case "hunt_find_equipment":
			Pchar.quest.hunt_get_equipment.win_condition.l1 = "locator";
			Pchar.quest.hunt_get_equipment.win_condition.l1.location = PChar.location;
			Pchar.quest.hunt_get_equipment.win_condition.l1.locator_group = "box";
			Pchar.quest.hunt_get_equipment.win_condition.l1.locator = "box1";
			PChar.quest.hunt_get_equipment.win_condition = "hunt_get_equipment";
		break;

		case "hunt_get_equipment":
			RestoreTempRemovedItems(PChar);
			PlayStereoSound("interface\important_item.wav");
			logit(TranslateString("","You found your equipment. Equip some of it!"));
			EndQuestMovie();
			DisableFastTravel(true);
			PChar.vcskip = "true";

			Pchar.quest.hunt_deck_battle_setup.win_condition.l1 = "locator";
			Pchar.quest.hunt_deck_battle_setup.win_condition.l1.location = PChar.location;
			Pchar.quest.hunt_deck_battle_setup.win_condition.l1.locator_group = "reload";
			Pchar.quest.hunt_deck_battle_setup.win_condition.l1.locator = "reload1";
			PChar.quest.hunt_deck_battle_setup.win_condition = "hunt_go_up_to_deck";
		break;

		case "hunt_go_up_to_deck":
			if (CheckQuestAttribute("hunt_romance_on_ship", "true"))
			{
				LAi_SetActorType(romance);
				LAi_ActorFollowEverywhere(romance, "", 10.0);
				ChangeCharacterAddressGroup(romance, GetCharacterShipQDeck(PChar), "rld", "startloc");
			}
			DoQuestReloadToLocation(GetCharacterShipQDeck(PChar), "reload", "reload1", "hunt_deck_battle_setup");
		break;

		case "hunt_deck_battle_setup":
			StartQuestMovie(true, true, false);
			DeleteAttribute(PChar, "vcskip");
			if (CheckQuestAttribute("hunt_romance_on_ship", "true")) SetOfficersIndex(Pchar, 3, romanceidx);
			for (n=1; n<5; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[PIRATE].fantomModel.(temp), "", "");
				sld.id = "Deck crew " + n;
				sld.nation = ENGLAND;
				SetRandomNameToCharacter(sld);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			}
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "hunt_deck_battle_won");
		break;

		case "hunt_deck_battle_won":
			EndQuestMovie();
			DisableFastTravel(true);
			DoQuestReloadToLocation("PoPrince_Port", "reload", "reload2_back", "hunt_port_au_prince_arrival");
		break;

		case "hunt_port_au_prince_arrival":
			LAi_SetFightMode(PChar, false);
			Locations[FindLocation("PoPrince_Port")].reload.l4.disable = 1;		// Lock ship
			bQuestDisableSeaEnter = true;
			Locations[FindLocation("Buccaneers_Camp")].reload.l4.disable = 0;	// Unlock forger's house - not needed if Lucía or Edmundo is with you but allow it anyway
			PChar.quest.ardent_hunt_status = "need_forger";
			if (isofficer(romance))
			{
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.currentNode = "hunt_rescue_crew_how";
				LAi_ActorDialog(romance,PChar,"hunt_port_au_prince_arrival2",5.0,5.0);
			}
			else
			{
				Pchar.dialog.CurrentNode = "hunt_how_to_save_crew";
				LAi_SetActorType(PChar);
				LAi_ActorSelfDialog(PChar, "hunt_port_au_prince_arrival2_no_romance");
			}

		break;

		case "hunt_port_au_prince_arrival2":
			LAi_SetOfficerType(romance);
			SetCharacterRemovable(romance, false);
			LAi_SetImmortal(romance, true);
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(characterFromID(PChar.quest.romance))));
			if (PChar.sex == "man") Preprocessor_AddQuestData("pronoun3", XI_ConvertString("her"));
			else Preprocessor_AddQuestData("pronoun3", XI_ConvertString("his"));
			Preprocessor_AddQuestData("villain_pronoun", XI_ConvertString(GetMyPronounObj(characterFromID(PChar.quest.villain))));
			AddQuestRecord("Villain_Hunt", 18);
			Preprocessor_Remove("villain_pronoun");
			Preprocessor_Remove("pronoun3");
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			LAi_QuestDelay("hunt_port_au_prince_arrival3", 0.0);
		break;

		case "hunt_port_au_prince_arrival2_no_romance":
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			AddQuestRecord("Villain_Hunt", 17);
			Preprocessor_Remove("villain");
			LAi_SetPlayerType(PChar);
			LAi_QuestDelay("hunt_port_au_prince_arrival3", 0.0);
		break;

		case "hunt_port_au_prince_arrival3":
			Locations[FindLocation("PoPrince_town")].locators_radius.officers.reload10_3 = 2.5;
			Pchar.quest.hunt_found_backdoor.win_condition.l1 = "locator";
			Pchar.quest.hunt_found_backdoor.win_condition.l1.location = "PoPrince_town";
			Pchar.quest.hunt_found_backdoor.win_condition.l1.locator_group = "officers";
			Pchar.quest.hunt_found_backdoor.win_condition.l1.locator = "reload10_3";
			Pchar.quest.hunt_found_backdoor.win_condition = "hunt_found_backdoor";

			i = GetRMRelationType(GetRMRelation(PChar,FRANCE));
			if (i != RELATION_FRIEND)
			{
				PChar.quest.hunt_signature_from_governor.win_condition.l1 = "relation";
				if (i == RELATION_ENEMY) PChar.quest.hunt_signature_from_governor.win_condition.l1.relation = "Neutral";
				else PChar.quest.hunt_signature_from_governor.win_condition.l1.relation = "Friendly";
				PChar.quest.hunt_signature_from_governor.win_condition.l1.nation = "FRANCE";
				PChar.quest.hunt_signature_from_governor.win_condition.l2 = "location";
				PChar.quest.hunt_signature_from_governor.win_condition.l2.location = "PoPrince_townhall";
				PChar.quest.hunt_signature_from_governor.win_condition = "hunt_signature_from_governor";
			}

			LAi_QuestDelay("hunt_fort_setup", 0.0);
		break;

		case "hunt_signature_from_governor":
			Pchar.quest.hunt_found_backdoor.over = "yes";
			i = GetRMRelationType(GetRMRelation(PChar,FRANCE));
			if (i == RELATION_NEUTRAL)
			{
				AddQuestRecord("Villain_Hunt", 27);
				PChar.quest.hunt_found_document = "pardon";
			}
			if (i == RELATION_FRIEND)
			{
				AddQuestRecord("Villain_Hunt", 28);
				PChar.quest.hunt_found_document = "Letter or Marque";
			}
			if (i != RELATION_NEUTRAL && i != RELATION_FRIEND) // If this ever happens, I want to know why! - GR
			{
				AddQuestRecord("Villain_Hunt", 29);
				PChar.quest.hunt_found_document = "document";
			}
			if (isofficer(romance)) Characters[romanceidx].dialog.currentNode = "hunt_consider_forgery";
		break;

		case "hunt_found_backdoor":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "reload", "reload20");
			LAi_QuestDelay("hunt_found_backdoor2", 3.0);
		break;

		case "hunt_found_backdoor2":
			if (isofficer(romance))
			{
				LAi_ActorWaitDialog(PChar, romance);
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.currentNode = "hunt_seen_backdoor";
				LAi_ActorDialog(romance,PChar,"hunt_found_backdoor3",25.0,25.0);
			}
			else
			{
				Pchar.dialog.CurrentNode = "hunt_residence_backdoor";
				LAi_SetActorType(PChar);
				LAi_ActorSelfDialog(PChar, "hunt_found_backdoor3");
			}
		break;

		case "hunt_found_backdoor3":
			if (isofficer(romance)) LAi_SetOfficerType(romance);
			LAi_SetPlayerType(PChar);
			Locations[FindLocation("PoPrince_town")].locators_radius.officers.reload10_3 = 1.0;
			Pchar.quest.hunt_unlock_backdoor.win_condition.l1 = "locator";
			Pchar.quest.hunt_unlock_backdoor.win_condition.l1.location = "PoPrince_town";
			Pchar.quest.hunt_unlock_backdoor.win_condition.l1.locator_group = "reload";
			Pchar.quest.hunt_unlock_backdoor.win_condition.l1.locator = "reload20";
			Pchar.quest.hunt_unlock_backdoor.win_condition.l2 = "Time";
			Pchar.quest.hunt_unlock_backdoor.win_condition.l2.time = DAY_TIME_NIGHT;
			Pchar.quest.hunt_unlock_backdoor.win_condition = "hunt_unlock_backdoor";
		break;

		case "hunt_unlock_backdoor":
			logit(TranslateString("","The lock on this door must date back to the time when this town was Spanish."));
			logit(TranslateString("","It opens with the same key that you used to escape from Havana prison!"));
			TakeItemFromCharacter(PChar, "key3");	// Key will not be needed again, so dump it to tidy inventory
			PlaySound("PEOPLE\lockpick2.wav");
			Locations[FindLocation("PoPrince_town")].reload.l40.disable = false;
			Locations[FindLocation("PoPrince_archive")].locators_radius.sit.sit1 = 1.8;
			Pchar.quest.hunt_got_autograph_archive.win_condition.l1 = "locator";
			Pchar.quest.hunt_got_autograph_archive.win_condition.l1.location = "PoPrince_archive";
			Pchar.quest.hunt_got_autograph_archive.win_condition.l1.locator_group = "sit";
			Pchar.quest.hunt_got_autograph_archive.win_condition.l1.locator = "sit1";
			Pchar.quest.hunt_got_autograph_archive.win_condition = "hunt_got_autograph_archive";
		break;

		case "hunt_got_autograph_archive":
//			LAi_Fade("hunt_got_autograph", "hunt_been_to_archive");
			LAi_QuestDelay("hunt_got_autograph", 0.1);
			LAi_QuestDelay("hunt_been_to_archive", 0.1);
		break;

		case "hunt_been_to_archive":
			Pchar.dialog.CurrentNode = "hunt_found_signature";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "player_back");
			AddQuestRecord("Villain_Hunt", 24);
			if (isofficer(romance))
			{
				PChar.quest.hunt_romance_says_goto_tavern.win_condition.l1 = "location";
				PChar.quest.hunt_romance_says_goto_tavern.win_condition.l1.location = "PoPrince_town";
				PChar.quest.hunt_romance_says_goto_tavern.win_condition = "hunt_romance_says_goto_tavern";
			}
			Locations[FindLocation("PoPrince_town")].reload.l40.label = "Archives";
			locations[FindLocation("PoPrince_archive")].id.label = "Archives";
		break;

		case "hunt_got_autograph":
			PChar.quest.hunt_found_document = "document";
			PChar.quest.hunt_signature_from_governor.over = "yes";
		break;

		case "hunt_romance_says_goto_tavern":
			Locations[FindLocation("PoPrince_town")].reload.l40.disable = 1;
			LAi_SetActorType(romance);
			ChangeCharacterAddressGroup(romance, "PoPrince_town", "reload", "reload9");
			LAi_ActorTurnToLocator(romance, "reload", "reload20");
			LAi_QuestDelay("hunt_romance_says_goto_tavern2", 0.1);
		break;

		case "hunt_romance_says_goto_tavern2":
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(PChar, romance);
			Characters[romanceidx].dialog.currentNode = "hunt_did_you_get_it";
			LAi_ActorDialogNow(romance, PChar, "",0.3); // Exits to "hunt_with_romance_to_tavern"
		break;

		case "hunt_with_romance_to_tavern":
			Locations[FindLocation("PoPrince_town")].reload.l40.disable = 0;
			LAi_SetPlayerType(PChar);
//			LAi_SetActorType(romance);
//			LAi_ActorFollowEverywhere(romance, "", 10.0);
			LAi_SetOfficerType(romance);
			PChar.quest.hunt_romance_forges_papers.win_condition.l1 = "location";
			PChar.quest.hunt_romance_forges_papers.win_condition.l1.location = "PoPrince_tavern_upstairs";
			PChar.quest.hunt_romance_forges_papers.win_condition = "hunt_romance_forges_papers";
		break;

		case "hunt_romance_forges_papers":
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(romance, "PoPrince_tavern_upstairs", "goto", "goto2");
			ChangeCharacterAddressGroup(PChar, "PoPrince_tavern_upstairs", "goto", "goto4");
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(PChar, romance);
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.currentNode = "hunt_document_done";
			LAi_ActorDialog(romance,PChar,"hunt_romance_forges_papers_done",5.0,5.0);
		break;

		case "hunt_romance_forges_papers_done":
			GiveItem2Character(PChar, "fake_fort_release");
			AddQuestRecord("Villain_Hunt", 20);
			PChar.quest.hunt_document_type = "transfer";
			PChar.quest.ardent_hunt_status = "got_release_document";
//			DisableFastTravel(false);
			LAi_SetPlayerType(PChar);
			LAi_SetOfficerType(romance);
			SetCharacterRemovable(romance, true);
			LAi_SetImmortal(romance, false);
			PChar.quest.hunt_change_into_uniform.win_condition.l1 = "ExitFromLocation";
			PChar.quest.hunt_change_into_uniform.win_condition.l1.location = PChar.location;
			PChar.quest.hunt_change_into_uniform.win_condition = "hunt_change_into_uniform";
		break;

		case "hunt_change_into_uniform":
			if (PChar.sex == "man") SetModelFromID(PChar, "Ardent_Fr");
			else
			{
				SetModelFromID(PChar, "Ardent_FrF");
				Pchar.quest.hunt_helen_changes_back.win_condition.l1 = "location";
				Pchar.quest.hunt_helen_changes_back.win_condition.l1.location = "Hispaniola";
				PChar.quest.hunt_helen_changes_back.win_condition = "hunt_helen_changes_back";
				Pchar.quest.hunt_helen_changes_back_deck.win_condition.l1 = "location";
				Pchar.quest.hunt_helen_changes_back_deck.win_condition.l1.location = GetCharacterShipQDeck(PChar);
				PChar.quest.hunt_helen_changes_back_deck.win_condition = "hunt_helen_changes_back";
			}
		break;

		case "hunt_helen_changes_back":
			Pchar.quest.hunt_helen_changes_back.over = "yes";
			Pchar.quest.hunt_helen_changes_back_deck.over = "yes";
			if (PChar.sex == "woman" && PChar.model == "Ardent_FrF") SetModelFromID(PChar, "Ardent_F");
		break;

		case "hunt_prepare_forger":		// Triggered by dialog with Florentin Destot, Buccaneer Camp tavernkeeper
			Characters[GetCharacterIndex("Pablo Escriva")].dialog.currentNode = "ask_for_document";
			Locations[FindLocation("Buccaneers_Camp")].reload.l4.disable = 0;
		break;

		case "hunt_forger_come_back_tomorrow":	// Triggered by dialog with Pablo Escriva
			AddQuestRecord("Villain_Hunt", 26);
			PChar.quest.hunt_forger_next_day.win_condition.l1 = "Timer";
			PChar.quest.hunt_forger_next_day.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
			PChar.quest.hunt_forger_next_day.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.hunt_forger_next_day.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.hunt_forger_next_day.win_condition = "hunt_forger_next_day";
		break;

		case "hunt_forger_next_day":
			Characters[GetCharacterIndex("Pablo Escriva")].dialog.currentNode = "hunt_document_done";
		break;

		case "hunt_forger_document_done":
			GiveItem2Character(PChar, "fake_fort_release");
			PChar.quest.ardent_hunt_status = "got_release_document";
			DeleteQuestAttribute("hunt_document_price");
			DeleteQuestAttribute("hunt_found_document");
			if (CheckQuestAttribute("hunt_document_type", "requisition"))
			{
				AddQuestRecord("Villain_Hunt", 25);
			}
			else
			{
				AddQuestRecord("Villain_Hunt", 20);
				PChar.quest.hunt_change_into_uniform.win_condition.l1 = "ExitFromLocation";
				PChar.quest.hunt_change_into_uniform.win_condition.l1.location = PChar.location;
				PChar.quest.hunt_change_into_uniform.win_condition = "hunt_change_into_uniform";
			}
		break;

		case "hunt_fort_setup":
			Locations[FindLocation("PoPrince_fakefort3")].vcskip = true;

			i = 0;
			PChar.quest.speaker = "";
			for (n=1; n<OFFICER_MAX; n++)
			{
				temp = "officer" + n;
				if (PChar.quest.hunt.(temp) != "*NULL*" && PChar.quest.hunt.(temp) != romance.id)
				{
					if (PChar.quest.speaker == "") PChar.quest.speaker = PChar.quest.hunt.(temp);
					i++;
					ChangeCharacterAddressGroup(CharacterFromID(PChar.quest.hunt.(temp)), "PoPrince_fakefort3", "rld", "loc" + i);
					LAi_SetCitizenType(CharacterFromID(PChar.quest.hunt.(temp)));

					ch = CharacterFromID(PChar.quest.hunt.(temp));
					RemoveCharacterEquip(ch, BLADE_ITEM_TYPE);
					RemoveCharacterEquip(ch, GUN_ITEM_TYPE);
					TempRemoveItems(ch);

					if (i > 10) break;
				}
			}
			ChangeCharacterAddressGroup(CharacterFromID("Ralph Partridge"), "PoPrince_fakefort3", "rld", "loc11");
			LAi_SetCitizenType(CharacterFromID("Ralph Partridge"));
			ChangeCharacterAddressGroup(CharacterFromID("Coper Blumberger"), "PoPrince_fakefort3", "rld", "loc12");
			LAi_SetCitizenType(CharacterFromID("Coper Blumberger"));
			ChangeCharacterAddressGroup(CharacterFromID("Amtónio Guajira"), "PoPrince_fakefort3", "rld", "loc13");
			LAi_SetCitizenType(CharacterFromID("Amtónio Guajira"));

			RemoveCharacterEquip(CharacterFromID("Ralph Partridge"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(CharacterFromID("Coper Blumberger"), BLADE_ITEM_TYPE);
			RemoveCharacterEquip(CharacterFromID("Amtónio Guajira"), BLADE_ITEM_TYPE);
			TempRemoveItems(CharacterFromID("Ralph Partridge"));
			TempRemoveItems(CharacterFromID("Coper Blumberger"));
			TempRemoveItems(CharacterFromID("Amtónio Guajira"));

			if (PChar.quest.speaker == "") PChar.quest.speaker = "Ralph Partridge";
			ChangeCharacterAddressGroup(characterFromID("Fort_guard"), "PoPrince_fakefort3", "goto", "goto4");
			characters[GetCharacterIndex("Fort_guard")].Dialog.Filename = "guard_dialog.c";
			characters[GetCharacterIndex("Fort_guard")].dialog.CurrentNode = "hunt_rescue_crew_from_prison";
			
			Pchar.quest.hunt_rescue_crew_from_prison.win_condition.l1 = "location";
			Pchar.quest.hunt_rescue_crew_from_prison.win_condition.l1.location = "PoPrince_fakefort3";
			PChar.quest.hunt_rescue_crew_from_prison.win_condition = "hunt_rescue_crew_from_prison";
		break;

		case "hunt_rescue_crew_from_prison":
			GiveSoldierWeapon(CharacterFromID("Fort_guard"), FRANCE);

			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("PoPrince_fakefort3")], true);
			StartQuestMovie(true, true, false);
			LAi_SetActorType(characterfromID("Fort_guard"));
			LAi_ActorTurnToLocator(characterfromID("Fort_guard"), "reload", "reloadc1");
			LAi_SetStayType(characterfromID("Fort_guard"));

			crewidx = GetCharacterIndex(PChar.quest.speaker);
			crewref = CharacterFromID(PChar.quest.speaker);
//			PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
			StoreDialog(crewref);
			LAi_SetActorType(crewref);
			characters[crewidx].Dialog.Filename = "crew_dialog.c";
			characters[crewidx].dialog.CurrentNode = "hunt_rescue_crew_from_prison";
			LAi_ActorDialog(crewref,PChar,"hunt_rescue_crew_from_prison2",60.0,60.0);
		break;

		case "hunt_rescue_crew_from_prison2":
			LAi_SetCitizenType(CharacterFromID(PChar.quest.speaker));
//			characters[GetCharacterIndex(PChar.quest.speaker)].Dialog.Filename = PChar.quest.normal_dialog;
			RestoreDialog(CharacterFromID(PChar.quest.speaker));
			LAi_SetActorType(characterfromID("Fort_guard"));
			characters[GetCharacterIndex("Fort_guard")].Dialog.Filename = "guard_dialog.c";
			characters[GetCharacterIndex("Fort_guard")].dialog.CurrentNode = "hunt_fort_what_business";
			LAi_ActorDialog(characterfromID("Fort_guard"),PChar,"",60.0,60.0);	// Exits to "hunt_fort_crew_released" or "hunt_fort_fight"
		break;

		case "hunt_fort_fight":
			Pchar.quest.hunt_found_backdoor.over = "yes";		// In case you'd started down the forgery route and then switched to the fight route
			PChar.quest.hunt_signature_from_governor.over = "yes";
			LAi_LocationFightDisable(&Locations[FindLocation("PoPrince_fakefort3")], false);
			LAi_ActorAttack(characterfromID("Fort_guard"), PChar, "");
			Pchar.quest.hunt_fort_violent_escape.win_condition.l1 = "NPC_death";
			Pchar.quest.hunt_fort_violent_escape.win_condition.l1.character = "Fort_guard";
			Pchar.quest.hunt_fort_violent_escape.win_condition = "hunt_fort_violent_escape";
		break;

		case "hunt_fort_violent_escape":
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("PoPrince_fakefort3")], true);
			crewidx = GetCharacterIndex(PChar.quest.speaker);
			crewref = CharacterFromID(PChar.quest.speaker);
//			PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
			StoreDialog(crewref);
			LAi_SetActorType(crewref);
			characters[crewidx].Dialog.Filename = "crew_dialog.c";
			characters[crewidx].dialog.CurrentNode = "hunt_rescue_crew_what_now";
			LAi_ActorDialog(crewref,PChar,"hunt_fort_violent_escape2",60.0,60.0);
		break;

		case "hunt_fort_violent_escape2":
//			characters[GetCharacterIndex(PChar.quest.speaker)].Dialog.Filename = PChar.quest.normal_dialog;
			RestoreDialog(CharacterFromID(PChar.quest.speaker));
			LAi_LocationFightDisable(&Locations[FindLocation("PoPrince_fakefort3")], false);
			EndQuestMovie();
			RestorePassengers(PChar.id);

			PChar.quest.hunt_fort_alarm.win_condition.l1 = "ExitFromLocation";
			PChar.quest.hunt_fort_alarm.win_condition.l1.location = PChar.location;
			PChar.quest.hunt_fort_alarm.win_condition = "hunt_fort_alarm";

			Pchar.quest.hunt_fort_to_town.win_condition.l1 = "location";
			Pchar.quest.hunt_fort_to_town.win_condition.l1.location = "PoPrince_town";
			PChar.quest.hunt_fort_to_town.win_condition = "hunt_out_of_fort";
			Pchar.quest.hunt_fort_to_jungle.win_condition.l1 = "location";
			Pchar.quest.hunt_fort_to_jungle.win_condition.l1.location = "Hispaniola_Jungle_06";
			PChar.quest.hunt_fort_to_jungle.win_condition = "hunt_out_of_fort";
		break;

		case "hunt_fort_alarm":
			if (PChar.location != "PoPrince_town" && PChar.location != "Hispaniola_Jungle_06")
			{
				PlaySound("AMBIENT\TOWN\Alarm.wav");
				LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			}
			LAi_QuestDelay("hunt_fort_alarm2", 0.0);
		break;

		case "hunt_fort_alarm2":
			DeleteQuestAttribute("hunt_fort_alarm");
			if (PChar.location != "PoPrince_town" && PChar.location != "Hispaniola_Jungle_06")
			{
				PChar.quest.hunt_fort_alarm.win_condition.l1 = "ExitFromLocation";
				PChar.quest.hunt_fort_alarm.win_condition.l1.location = PChar.location;
				PChar.quest.hunt_fort_alarm.win_condition = "hunt_fort_alarm";
			}
		break;

		case "hunt_fort_crew_released":
			LAi_LocationFightDisable(&Locations[FindLocation("PoPrince_fakefort3")], false);
			RestorePassengers(PChar.id);
			EndQuestMovie();
			TakeItemFromCharacter(PChar, "fake_fort_release");
			for (n=1; n<OFFICER_MAX; n++)
			{
				temp = "officer" + n;
				if (PChar.quest.hunt.(temp) != "*NULL*" && PChar.quest.hunt.(temp) != romance.id)
				{
					ch = CharacterFromID(PChar.quest.hunt.(temp));
					LAi_SetActorType(ch);
					LAi_ActorFollowEverywhere(ch, "", 10.0);
				}
			}
			LAi_SetActorType(CharacterFromID("Ralph Partridge"));
			LAi_ActorFollowEverywhere(CharacterFromID("Ralph Partridge"), "", 10.0);
			LAi_SetActorType(CharacterFromID("Coper Blumberger"));
			LAi_ActorFollowEverywhere(CharacterFromID("Coper Blumberger"), "", 10.0);
			LAi_SetActorType(CharacterFromID("Amtónio Guajira"));
			LAi_ActorFollowEverywhere(CharacterFromID("Amtónio Guajira"), "", 10.0);
			Pchar.quest.hunt_fort_to_town.win_condition.l1 = "location";
			Pchar.quest.hunt_fort_to_town.win_condition.l1.location = "PoPrince_town";
			PChar.quest.hunt_fort_to_town.win_condition = "hunt_out_of_fort";
			Pchar.quest.hunt_fort_to_jungle.win_condition.l1 = "location";
			Pchar.quest.hunt_fort_to_jungle.win_condition.l1.location = "Hispaniola_Jungle_06";
			PChar.quest.hunt_fort_to_jungle.win_condition = "hunt_out_of_fort";
		break;

		case "hunt_out_of_fort":
			PChar.quest.hunt_romance_forges_papers.over = "yes";	// Clear out any quest checks which may be left if you started
			PChar.quest.hunt_forger_next_day.over = "yes";		// to get forgery and then switched to violent escape
//			Locations[FindLocation("Buccaneers_Camp")].reload.l4.disable = 1;	// Re-lock forger's house
			if (isofficer(romance))					// Also reset "romance" in case Lucía/Edmundo is still in "follow" mode
			{
				LAi_SetOfficerType(romance); 
				SetCharacterRemovable(romance, true);
			}

			for (n=1; n<OFFICER_MAX; n++)
			{
				temp = "officer" + n;
				if (PChar.quest.hunt.(temp) != "*NULL*" && PChar.quest.hunt.(temp) != romance.id)
				{
					ch = CharacterFromID(PChar.quest.hunt.(temp));
					LAi_SetOfficerType(ch);
				}
			}

			LAi_SetFightMode(PChar, false);
			HoistFlag(FRANCE);
			Pchar.quest.hunt_fort_to_town.over = "yes";
			Pchar.quest.hunt_fort_to_jungle.over = "yes";
			DisableFastTravel(false);
			bQuestDisableSeaEnter = false;
			Locations[FindLocation("PoPrince_Port")].reload.l3.disable = 0;
			Locations[FindLocation("PoPrince_Port")].reload.l4.disable = 0;
			DeleteAttribute(&Locations[FindLocation("PoPrince_fakefort3")],"vcskip");
			ChangeCharacterAddress(characterFromID("Fort_guard"), "None", "");

			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			if (CheckCharacterItem(PChar, "BattleOrders"))
			{
				AddQuestRecord("Villain_Hunt", 23);
			}
			else
			{
				if (CheckAttribute(PChar, "quest.hunt_admiral_owes") && makeint(PChar.quest.hunt_admiral_owes) > 0)
				{
					AddQuestRecord("Villain_Hunt", 22);
				}
				else
				{
					AddQuestRecord("Villain_Hunt", 21);
				}
			}
			Preprocessor_Remove("villain");
			if (PChar.quest.speaker != "Ralph Partridge")
			{
				crewidx = GetCharacterIndex(PChar.quest.speaker);
				crewref = CharacterFromID(PChar.quest.speaker);
//				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				StoreDialog(crewref);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				characters[crewidx].dialog.CurrentNode = "hunt_rescue_glad_to_be_out";
				LAi_SetActorType(crewref);
				LAi_ActorDialog(crewref,PChar,"hunt_out_of_fort2",10.0,10.0);
			}
			else DeleteQuestAttribute("speaker");

			DeleteAttribute(PChar, "isnotcaptain");
			DeleteQuestAttribute("hunt_document_type");
			DeleteQuestAttribute("hunt_found_document");
			if (CheckCharacterItem(PChar, "fake_fort_release")) TakeItemFromCharacter(PChar, "fake_fort_release");

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(PChar, "", 150);
				AddPartyExpChar(pchar, "Sneak", 150);
			}
			else {AddPartyExp(pchar, 1800);}

			Pchar.quest.hunt_back_to_sea.win_condition.l1 = "location";
			Pchar.quest.hunt_back_to_sea.win_condition.l1.location = "Hispaniola";
			PChar.quest.hunt_back_to_sea.win_condition = "hunt_back_to_ship";
			Pchar.quest.hunt_back_on_deck.win_condition.l1 = "location";
			Pchar.quest.hunt_back_on_deck.win_condition.l1.location = GetCharacterShipQDeck(PChar);
			PChar.quest.hunt_back_on_deck.win_condition = "hunt_back_to_ship";
		break;

		case "hunt_out_of_fort2":
			LAi_SetOfficerType(CharacterFromId(PChar.quest.speaker));
//			characters[GetCharacterIndex(PChar.quest.speaker)].Dialog.Filename = PChar.quest.normal_dialog;
			RestoreDialog(CharacterFromId(PChar.quest.speaker));
			DeleteQuestAttribute("speaker");
		break;

		case "hunt_back_to_ship":
			Pchar.quest.hunt_back_to_sea.over = "yes";
			Pchar.quest.hunt_back_on_deck.over = "yes";
			CloseQuestHeader("Villain_Hunt");
			for (n=1; n<OFFICER_MAX; n++)
			{
				temp = "officer" + n;
				if (PChar.quest.hunt.(temp) != "*NULL*" && PChar.quest.hunt.(temp) != romance.id)
				{
					ch = CharacterFromID(PChar.quest.hunt.(temp));
					RestoreTempRemovedItems(ch);
				}
				DeleteQuestAttribute("hunt." + temp);
			}
			RestoreTempRemovedItems(CharacterFromID("Ralph Partridge"));
			RestoreTempRemovedItems(CharacterFromID("Coper Blumberger"));
			RestoreTempRemovedItems(CharacterFromID("Amtónio Guajira"));
			LAi_SetCitizenType(CharacterFromID("Ralph Partridge"));
			LAi_SetCitizenType(CharacterFromID("Coper Blumberger"));
			LAi_SetCitizenType(CharacterFromID("Amtónio Guajira"));
			ChangeCharacterAddress(characterFromID("Ralph Partridge"), "None", "");
			ChangeCharacterAddress(characterFromID("Coper Blumberger"), "None", "");
			ChangeCharacterAddress(characterFromID("Amtónio Guajira"), "None", "");

			Pchar.quest.French_fleet_setup.win_condition.l1 = "location";
			Pchar.quest.French_fleet_setup.win_condition.l1.location = "Redmond";
			Pchar.quest.French_fleet_setup.win_condition = "French_fleet_setup";

			PChar.quest.invasion_status = "goto_Redmond";
		break;

		case "French_fleet_setup":
// Try putting French fleet at Redmond:quest_ships/quest_ship_15 (close to fort) or quest_ship_13/16 (bit further away)
//			bQuestDisableMapEnter = true;
			Group_CreateGroup("French_fleet");
			Group_AddCharacter("French_fleet", "French_Amiral");
			if (!LAi_IsDead(characterfromID("French_Contre-Amiral"))) Group_AddCharacter("French_fleet", "French_Contre-Amiral");
			if (!LAi_IsDead(characterfromID("French_Captain2"))) Group_AddCharacter("French_fleet", "French_Captain2");
			if (!LAi_IsDead(characterfromID("French_Captain3"))) Group_AddCharacter("French_fleet", "French_Captain3");
			Group_SetGroupCommander("French_fleet", "French_Amiral");
			Group_SetTaskAttack("French_fleet",  PLAYER_GROUP, true);
			if(ispassenger(characterfromID("John Clifford Brin"))) Group_SetPursuitGroup("French_fleet", PLAYER_GROUP);
			Group_LockTask("French_fleet");
			Group_SetAddress("French_fleet", "Redmond", "quest_ships", "quest_ship_13"); 
//			Sea_LoginGroupNow("French_fleet");
			characters[GetCharacterIndex("French_Amiral")].nosurrender = 2;
			characters[GetCharacterIndex("French_Contre-Amiral")].nosurrender = 2;
			characters[GetCharacterIndex("French_Captain2")].nosurrender = 2;
			characters[GetCharacterIndex("French_Captain3")].nosurrender = 2;
			Characters[GetCharacterIndex("French_Amiral")].recognized = true;
			Characters[GetCharacterIndex("French_Contre-Amiral")].recognized = true;
			Characters[GetCharacterIndex("French_Captain2")].recognized = true;
			Characters[GetCharacterIndex("French_Captain3")].recognized = true;

			PChar.quest.French_flagship.type = GetCharacterShipModel(characterfromID("French_Amiral"));
			PChar.quest.French_flagship.name = Characters[GetCharacterIndex("French_Amiral")].Ship.Name;
			PChar.quest.French_flagship.cabin = GetCharacterShipCabin(CharacterfromID("French_Amiral"));

			PChar.quest.French_flagship_down.win_condition.l1 = "NPC_death";
			Pchar.quest.French_flagship_down.win_condition.l1.character = "French_Amiral";
			Pchar.quest.French_flagship_down.win_condition = "French_flagship_down";

			PChar.quest.Jamaica_battle_over.win_condition.l1 = "NPC_death";
			Pchar.quest.Jamaica_battle_over.win_condition.l1.character = "French_Amiral";
			if (!LAi_IsDead(characterfromID("French_Contre-Amiral")))
			{
				PChar.quest.Jamaica_battle_over.win_condition.l2 = "NPC_death";
				Pchar.quest.Jamaica_battle_over.win_condition.l2.character = "French_Contre-Amiral";
			}
			if (!LAi_IsDead(characterfromID("French_Captain2")))
			{
				PChar.quest.Jamaica_battle_over.win_condition.l3 = "NPC_death";
				Pchar.quest.Jamaica_battle_over.win_condition.l3.character = "French_Captain2";
			}
			if (!LAi_IsDead(characterfromID("French_Captain3")))
			{
				PChar.quest.Jamaica_battle_over.win_condition.l4 = "NPC_death";
				Pchar.quest.Jamaica_battle_over.win_condition.l4.character = "French_Captain3";
			}
			pchar.quest.Jamaica_battle_over.win_condition.l5 = "SeaEnter";
			Pchar.quest.Jamaica_battle_over.win_condition = "Jamaica_battle_over";

			if(iscompanion(CharacterFromID("Spanish_Captain1")) || iscompanion(CharacterFromID("Spanish_Captain4")))	// If extra galleons present, detach them so you can take more prize ships
			{
				pchar.quest.finale_galleons_detach_in_battle.win_condition.l1 = "SeaEnter";
				PChar.quest.finale_galleons_detach_in_battle.win_condition = "finale_galleons_detach_in_battle";
			}
		break;

		case "Jamaica_battle_over":
			PChar.quest.invasion_status = "warship_defeated";
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "finale_after_port_royale_reward";
/*			if(CheckAttribute(PChar, "quest.finale_galleons_leave")) PChar.quest.finale_galleons_leave.over = "yes";
			if(iscompanion(CharacterFromID("Spanish_Captain1")))
			{
				SetCharacterRemovable(characterFromID("Spanish_Captain1"), true);
				RemoveCharacterCompanion(PChar, characterFromID("Spanish_Captain1"));
			}
			if(iscompanion(CharacterFromID("Spanish_Captain4")))
			{
				SetCharacterRemovable(characterFromID("Spanish_Captain4"), true);
				RemoveCharacterCompanion(PChar, characterFromID("Spanish_Captain4"));
			} */
			
			bQuestDisableMapEnter = false;
			PChar.location.from_sea = "REDMOND_PORT";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "PChar");

			if (!HasThisShip(PChar.quest.French_flagship.type))
			{
				Preprocessor_AddQuestData("warship", PChar.quest.French_flagship.name);
				Preprocessor_AddQuestData("villain", GetMyFullName(villain));
				Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(villain)));
				Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(villain)));
				AddQuestRecord("Battle Royale", 9);
				Preprocessor_Remove("pronoun2");
				Preprocessor_Remove("pronoun");
				Preprocessor_Remove("villain");
				Preprocessor_Remove("warship");
				if (!CanMarry(romance)) PChar.quest.governor_hostage = "John Clifford Brin";
				if(ispassenger(characterfromID("John Clifford Brin")))
				{
					ChangeCharacterAddressGroup(characterfromID("John Clifford Brin"), GetCharacterShipCabin(PChar), "rld", "startloc");
					DoReloadFromSeaToLocation(GetCharacterShipCabin(PChar), "reload", "reload1");
					LAi_QuestDelay("finale_port_royale_governor_changes_deal", 1.0);
				}
				else
				{
					AddQuestRecord("Battle Royale", 14);
					DoReloadFromSeaToLocation("REDMOND_PORT", "reload", "sea_1_back");
					LAi_QuestDelay("finale_return_to_port_royale", 1.0);
				}
			}
			else
			{
				if (CanMarry(romance))
				{
					if(ispassenger(characterfromID("John Clifford Brin")))
					{
						ChangeCharacterAddressGroup(characterfromID("John Clifford Brin"), GetCharacterShipCabin(PChar), "rld", "startloc");
						DoReloadFromSeaToLocation(GetCharacterShipCabin(PChar), "reload", "reload1");
						LAi_QuestDelay("finale_port_royale_governor_changes_deal", 1.0);
					}
					else
					{
						AddQuestRecord("Battle Royale", 14);
						DoReloadFromSeaToLocation("REDMOND_PORT", "reload", "sea_1_back");
						LAi_QuestDelay("finale_return_to_port_royale", 1.0);
					}
				}
				else
				{
					ChangeCharacterAddressGroup(villain, PChar.quest.French_flagship.cabin, "rld", "startloc");
					DoReloadFromSeaToLocation(PChar.quest.French_flagship.cabin, "reload", "reload1");
					Characters[villainidx].dialog.CurrentNode = "finale_challenge_to_duel";
					LAi_QuestDelay("finale_duel_on_ship", 1.0);
				}
			}

			if (!LAi_IsDead(romance))
			{
				Pchar.quest.finale_romance_joins_in_santiago.win_condition.l1 = "location";
				Pchar.quest.finale_romance_joins_in_santiago.win_condition.l1.location = "Santiago_port";
				Pchar.quest.finale_romance_joins_in_santiago.win_condition = "romance_joins_in_santiago";
			}

			if(GetRMRelation(PChar, FRANCE) > REL_WAR)	// Shouldn't be needed as "French_Amiral" doesn't have "skipRM" attribute, but someone reported still having French LoM after taking Dauphin Royal so let's not take chances
			{
				SetRMRelation(PChar, FRANCE, REL_WAR);
				LeaveService(PChar, FRANCE, true);
			}
		break;

		case "French_flagship_down":
			if (!LAi_IsDead(characterfromID("French_Contre-Amiral"))) DeleteAttribute(&characters[GetCharacterIndex("French_Contre-Amiral")], "nosurrender");
			if (!LAi_IsDead(characterfromID("French_Captain2"))) DeleteAttribute(&characters[GetCharacterIndex("French_Captain2")], "nosurrender"); 
			if (!LAi_IsDead(characterfromID("French_Captain3"))) DeleteAttribute(&characters[GetCharacterIndex("French_Captain3")], "nosurrender");
		break;

		case "finale_duel_on_ship":
			DisableFastTravel(true);
			StartQuestMovie(true, true, false);
			LAi_SetImmortal(villain, false);
			LAi_SetActorType(villain);
//			Characters[villainidx].dialog.CurrentNode = "finale_challenge_to_duel";
			LAi_ActorDialog(villain,PChar,"finale_duel_on_ship_fight",10.0,10.0);	// Dialog node already set in case "Jamaica_battle_over" or "Santiago_battle_over"
		break;

		case "finale_duel_on_ship_fight":
			LAi_NoRebirthEnable(villain);
			LAi_SetActorType(villain);
			LAi_ActorAttack(villain, PChar, "");
			PChar.quest.finale_duel_on_ship_fight_over.win_condition.l1 = "NPC_death";
			Pchar.quest.finale_duel_on_ship_fight_over.win_condition.l1.character = Characters[villainidx].id;
			Pchar.quest.finale_duel_on_ship_fight_over.win_condition = "finale_duel_on_ship_fight_over";
		break;

		case "finale_duel_on_ship_fight_over":
			Preprocessor_AddQuestData("warship", PChar.quest.French_flagship.name);
			Preprocessor_AddQuestData("villain", GetMyFullName(villain));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(villain)));
//			if (PChar.location == GetCharacterShipCabin(PChar)) AddQuestRecord("Battle Royale", 26);
//			else AddQuestRecord("Battle Royale", 8);
			if (PChar.location == PChar.quest.French_flagship.cabin) AddQuestRecord("Battle Royale", 8);
			else AddQuestRecord("Battle Royale", 26);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("villain");
			Preprocessor_Remove("warship");
			Characters[villainidx].quest.place_of_death = "ship";
//			PChar.location.from_sea = "REDMOND_PORT";
//			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "PChar");
			if (PChar.location.from_sea == "REDMOND_PORT")
			{
				if(ispassenger(characterfromID("John Clifford Brin")))
				{
					ChangeCharacterAddressGroup(characterfromID("John Clifford Brin"), GetCharacterShipCabin(PChar), "rld", "startloc");
					DoQuestReloadToLocation(GetCharacterShipCabin(PChar), "reload", "reload1", "finale_port_royale_governor_changes_deal");
				}
				else
				{
					Preprocessor_AddQuestData("warship", PChar.quest.French_flagship.name);
					AddQuestRecord("Battle Royale", 15);
					Preprocessor_Remove("warship");
					DoQuestReloadToLocation("REDMOND_PORT", "reload", "sea_1_back", "finale_return_to_port_royale");
				}
			}
			if (PChar.location.from_sea == "Santiago_port")
			{
				Preprocessor_AddQuestData("governor", "Governor " + GetMyLastName(CharacterFromID("Javier Balboa")));
				AddQuestRecord("Battle Royale", 25);
				Preprocessor_Remove("governor");
				DoQuestReloadToLocation("Santiago_port", "reload", "reload2_back", "finale_return_to_Santiago");
			}
			if (!LAi_IsDead(romance) && GetAttribute(romance, "married.id") == Characters[villainidx].id) Characters[romanceidx].married = MR_SINGLE;
		break;

		case "finale_port_royale_evacuation_setup":
			DisableTownCapture("Redmond", false);
			DisableTownCapture("Santiago", false);
			DisableTownCapture("Port au Prince", false);
			StoreDialog(CharacterFromID("John Clifford Brin"));
			characters[GetCharacterIndex("John Clifford Brin")].Dialog.Filename = "quest_John Clifford Brin_dialog.c";
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_here_to_evacuate";
		break;

		case "finale_port_royale_evacuation_get_family":	// Triggered by dialog with "John Clifford Brin"
			LAi_SetLoginTime(characterfromID("John Clifford Brin"), 0.0, 24.0);
			LAi_SetLoginTime(characterfromID("Elizabeth O_Brien"), 0.0, 24.0);
			DisableFastTravel(true);
			StartQuestMovie(true, true, false);
			LAi_SetActorType(CharacterFromID("John Clifford Brin"));
            		LAi_ActorGoToLocation(CharacterFromID("John Clifford Brin"), "reload", "reload3", "None", "", "", "finale_port_royale_evacuation_wait_for_family", 20.0);
		break;

		case "finale_port_royale_evacuation_wait_for_family":
			LAi_QuestDelay("finale_port_royale_evacuation_family_appears", 5.0);
		break;

		case "finale_port_royale_evacuation_family_appears":
			ChangeCharacterAddressGroup(characterfromID("John Clifford Brin"), "Redmond_Residence", "reload", "reload3");
			ChangeCharacterAddressGroup(characterfromID("Elizabeth O_Brien"), "Redmond_Residence", "reload", "reload3");
			LAi_QuestDelay("finale_port_royale_evacuation_ready_to_go", 1.0);
		break;

		case "finale_port_royale_evacuation_ready_to_go":
			LAi_SetActorType(CharacterFromID("John Clifford Brin"));
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_evacuate_introduce_family";
			LAi_ActorDialog(CharacterFromID("John Clifford Brin"),PChar,"finale_port_royale_evacuation_ready_to_go2",10.0,10.0);
		break;

		case "finale_port_royale_evacuation_ready_to_go2":
			LAi_SetActorType(CharacterFromID("John Clifford Brin"));
			LAi_ActorFollowEverywhere(CharacterFromID("John Clifford Brin"), "", 10.0);
			LAi_SetActorType(CharacterFromID("Elizabeth O_Brien"));
			Characters[GetCharacterIndex("Elizabeth O_Brien")].dialog.CurrentNode = "introduction";
			LAi_ActorDialog(CharacterFromID("Elizabeth O_Brien"),PChar,"finale_port_royale_evacuation_ready_to_go3",10.0,10.0);
		break;

		case "finale_port_royale_evacuation_ready_to_go3":
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("John Clifford Brin")));
			AddQuestRecord("Battle Royale", 7);
			Preprocessor_Remove("governor");
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_SetActorType(CharacterFromID("Elizabeth O_Brien"));
			LAi_ActorFollowEverywhere(CharacterFromID("Elizabeth O_Brien"), "", 10.0);
			LAi_SetImmortal(CharacterFromID("John Clifford Brin"), true);
			LAi_SetImmortal(CharacterFromID("Elizabeth O_Brien"), true);
			Group_SetPursuitGroup("French_fleet", PLAYER_GROUP);
			Pchar.quest.finale_port_royale_evacuation_board_ship.win_condition.l1 = "location";
			Pchar.quest.finale_port_royale_evacuation_board_ship.win_condition.l1.location = "Redmond";
			Pchar.quest.finale_port_royale_evacuation_board_ship.win_condition = "finale_port_royale_evacuation_board_ship";
//			Pchar.quest.finale_port_royale_evacuation_on_deck.win_condition.l1 = "location";
//			Pchar.quest.finale_port_royale_evacuation_on_deck.win_condition.l1.location = GetCharacterShipQDeck(PChar);
//			PChar.quest.finale_port_royale_evacuation_on_deck.win_condition = "finale_port_royale_evacuation_board_ship";
			Pchar.quest.finale_port_royale_evacuation_bombardment1.win_condition.l1 = "location";
			Pchar.quest.finale_port_royale_evacuation_bombardment1.win_condition.l1.location = "Redmond_Town_01";
			Pchar.quest.finale_port_royale_evacuation_bombardment1.win_condition = "finale_port_royale_evacuation_bombardment1";
			PChar.quest.finale_bombardment_active = true;
		break;

		case "finale_port_royale_evacuation_bombardment1":
			PChar.quest.finale_port_royale_evacuation_end_bombardment.win_condition.l1 = "ExitFromLocation";
			PChar.quest.finale_port_royale_evacuation_end_bombardment.win_condition.l1.location = "Redmond_Town_01";
			PChar.quest.finale_port_royale_evacuation_end_bombardment.win_condition = "finale_port_royale_evacuation_end_bombardment";
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			LAi_QuestDelay("finale_port_royale_evacuation_bombardment2", 1.0);
		break;

		case "finale_port_royale_evacuation_bombardment2":
			PlayStereoSound("OBJECTS\SHIPCHARGE\Cannon_Explosion_02.wav");
			if (CheckAttribute(PChar, "quest.finale_bombardment_active")) LAi_QuestDelay("finale_port_royale_evacuation_bombardment1", rand(100)*0.1);
			else PChar.quest.finale_port_royale_evacuation_end_bombardment.over = "yes";
		break;

		case "finale_port_royale_evacuation_end_bombardment":
			Pchar.quest.finale_port_royale_evacuation_bombardment1.over = "yes";
			Pchar.quest.finale_port_royale_evacuation_bombardment2.over = "yes";
			DeleteQuestAttribute("finale_bombardment_active");
		break;

		case "finale_port_royale_evacuation_board_ship":
//			Pchar.quest.finale_port_royale_evacuation_board_ship.over = "yes";
//			Pchar.quest.finale_port_royale_evacuation_on_deck.over = "yes";
			Pchar.quest.finale_port_royale_evacuation_bombardment1.over = "yes";
			Pchar.quest.finale_port_royale_evacuation_bombardment2.over = "yes";
			AddPassenger(PChar, CharacterFromID("John Clifford Brin"), 0);
			AddPassenger(PChar, CharacterFromID("Elizabeth O_Brien"), 0);
			SetCharacterRemovable(characterFromID("John Clifford Brin"), false);
			SetCharacterRemovable(characterFromID("Elizabeth O_Brien"), false);
			LAi_SetCitizenType(CharacterFromID("Elizabeth O_Brien"));
			ChangeCharacterAddress(characterFromID("Elizabeth O_Brien"), "None", "");
			LAi_SetImmortal(characterFromID("Elizabeth O_Brien"), false);
			LAi_SetHuberStayType(characterfromID("John Clifford Brin"));

			i = Group_FindGroup("French_fleet");
			if (i >= 0) Group_DeleteGroupIndex(i);
			Pchar.quest.French_fleet_setup.win_condition.l1 = "location";
			Pchar.quest.French_fleet_setup.win_condition.l1.location = "Redmond";
			Pchar.quest.French_fleet_setup.win_condition = "French_fleet_setup";
		break;

		case "finale_port_royale_governor_changes_deal":
			LAi_SetFightMode(PChar, false);
//			LAi_SetActorType(PChar);
//			LAi_ActorWaitDialog(PChar, CharacterFromID("John Clifford Brin"));
			LAi_SetActorType(CharacterFromID("John Clifford Brin"));
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_you_defeated_warship";
			LAi_ActorDialog(CharacterFromID("John Clifford Brin"),PChar,"finale_port_royale_goto_fort",10.0,10.0);
		break;

		case "finale_port_royale_goto_fort":
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("John Clifford Brin")));
			AddQuestRecord("Battle Royale", 10);
			Preprocessor_Remove("governor");
			SetCharacterRemovable(characterFromID("John Clifford Brin"), true);
			SetCharacterRemovable(characterFromID("Elizabeth O_Brien"), true);
			RemovePassenger(PChar, characterfromID("John Clifford Brin"));
			RemovePassenger(PChar, characterFromID("Elizabeth O_Brien"));
			LAi_QuestDelay("finale_reset_port_royale_governor", 0.1);
			LAi_SetPlayerType(PChar);
			LAi_SetLoginTime(characterfromID("Redmond Commander"), 0.0, 24.0);
			DoQuestReloadToLocation("Quest_Fort", "reload", "reloadc2", "finale_port_royale_fort_battle");
		break;

		case "finale_port_royale_fort_battle":
			for (n=1; n<9; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.(temp),  "rld", "aloc" + n);
				GiveSoldierWeapon(sld, FRANCE);
				sld.id = "French Soldier " + n;
				sld.nation = FRANCE;
				SetRandomNameToCharacter(sld);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			}

			for (n=1; n<5; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.(temp),  "rld", "loc" + n);
				GiveSoldierWeapon(sld, ENGLAND);
				sld.id = "English Soldier " + n;
				sld.nation = ENGLAND;
				SetRandomNameToCharacter(sld);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "finale_port_royale_fort_battle_over");
		break;

		case "finale_port_royale_fort_battle_over":
			ChangeCharacterAddressGroup(CharacterfromID("Redmond Commander"), "Quest_Fort", "reload", "reloadc1");
			LAi_QuestDelay("finale_port_royale_fort_battle_over2", 0.1);
		break;

		case "finale_port_royale_fort_battle_over2":
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_Fort")], true);
			LAi_SetActorType(CharacterFromID("Redmond Commander"));
			Characters[GetCharacterIndex("Redmond Commander")].Dialog.Filename = "guard_dialog.c";
			Characters[GetCharacterIndex("Redmond Commander")].dialog.CurrentNode = "finale_port_royale_fort_battle_over";
			LAi_ActorDialog(CharacterFromID("Redmond Commander"),PChar,"finale_port_royale_return_to_residence",10.0,10.0);
		break;

		case "finale_port_royale_return_to_residence":
			AddQuestRecord("Battle Royale", 11);
			ChangeCharacterAddressGroup(CharacterFromID("Redmond Commander"), "Redmond", "reload", "reload_fort1");
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_Fort")], false);
			DoQuestReloadToLocation("Redmond_residence", "reload", "reload1", "finale_port_royale_residence_after_fort_battle");
		break;

		case "finale_port_royale_residence_after_fort_battle":
			temp = "m" + (rand(5) + 1);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.(temp), "goto", "goto4");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "English Soldier 5";
			sld.nation = ENGLAND;
			SetRandomNameToCharacter(sld);
			temp = "m" + (rand(5) + 1);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.(temp), "goto", "goto6");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "English Soldier 6";
			sld.nation = ENGLAND;
			SetRandomNameToCharacter(sld);
			LAi_ActorFollow(characterFromID("English Soldier 5"), PChar, "", 20.0);
			LAi_ActorFollow(characterFromID("English Soldier 6"), PChar, "", 20.0);
			characters[GetCharacterIndex("John Clifford Brin")].Dialog.Filename = "quest_John Clifford Brin_dialog.c";
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_return_after_fort";
		break;

		case "finale_port_royale_dismiss_soldiers":	// Triggered by dialog with "John Clifford Brin"
			LAi_SetActorType(CharacterFromID("English Soldier 5"));
//            		LAi_ActorGoToLocation(CharacterFromID("English Soldier 5"), "reload", "reload1", "None", "", "", "finale_port_royale_dismiss_soldiers2", 10.0);
            		LAi_ActorGoToLocation(CharacterFromID("English Soldier 5"), "reload", "reload1", "None", "", "", "", 10.0);
			LAi_SetActorType(CharacterFromID("English Soldier 6"));
            		LAi_ActorGoToLocation(CharacterFromID("English Soldier 6"), "reload", "reload1", "None", "", "", "finale_port_royale_soldiers_gone", 10.0);
//            		LAi_ActorGoToLocation(CharacterFromID("English Soldier 6"), "reload", "reload1", "None", "", "", "", 10.0);
			characters[GetCharacterIndex("John Clifford Brin")].Dialog.Filename = "quest_John Clifford Brin_dialog.c";
			LAi_SetActorType(characterfromID("John Clifford Brin"));
			if (CheckQuestAttribute("governor_hostage", "John Clifford Brin"))
			{
				Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_dont_harm_wife";
			}
			else
			{
				Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_reward_for_warship";
				LAi_ActorDialog(CharacterFromID("John Clifford Brin"),PChar,"",10.0,10.0);
			}
		break;

		case "finale_port_royale_dismiss_soldiers2":
			LAi_SetActorType(CharacterFromID("English Soldier 6"));
            		LAi_ActorGoToLocation(CharacterFromID("English Soldier 6"), "reload", "reload1", "None", "", "", "finale_port_royale_soldiers_gone", 10.0);
		break;

		case "finale_port_royale_soldiers_gone":
			if (CheckQuestAttribute("governor_hostage", "John Clifford Brin"))
			{
				ChangeCharacterAddressGroup(villain, "Redmond_Residence", "reload", "reload3");
				LAi_QuestDelay("finale_port_royale_villain_talks_to_governor", 0.1);
			}
		break;

		case "finale_return_to_port_royale":
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_SetPlayerType(PChar);
			LAi_SetFightMode(PChar, false);
			if(ispassenger(characterfromID("John Clifford Brin")))
			{
				SetCharacterRemovable(CharacterFromID("John Clifford Brin"), true);
				SetCharacterRemovable(CharacterFromID("Elizabeth O_Brien"), true);
				RemovePassenger(PChar, CharacterfromID("John Clifford Brin"));
				RemovePassenger(PChar, CharacterFromID("Elizabeth O_Brien"));
				LAi_QuestDelay("finale_reset_port_royale_governor", 0.1);
			}
			if (CheckQuestAttribute("governor_hostage", "John Clifford Brin"))
			{
				ChangeCharacterAddressGroup(villain, "Redmond_Residence", "reload", "reload3");
				Pchar.quest.finale_port_royale_villain_in_residence.win_condition.l1 = "location";
				Pchar.quest.finale_port_royale_villain_in_residence.win_condition.l1.location = "Redmond_Residence";
				Pchar.quest.finale_port_royale_villain_in_residence.win_condition = "finale_port_royale_villain_in_residence";
			}
			else
			{
				characters[GetCharacterIndex("John Clifford Brin")].Dialog.Filename = "quest_John Clifford Brin_dialog.c";
				Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_what_happened";
			}
		break;

		case "finale_port_royale_villain_in_residence":
			LAi_LocationFightDisable(&Locations[FindLocation("Redmond_Residence")], true);
			LAi_SetActorType(villain);
			LAi_ActorFollow(villain, CharacterFromID("John Clifford Brin"), "finale_port_royale_villain_in_residence2", 30.0);
		break;

		case "finale_port_royale_villain_in_residence2":
			LAi_SetActorType(villain);
			LAi_SetActorType(PChar);
			Characters[villainidx].dialog.CurrentNode = "finale_welcome";	// Exits to "finale_governor_wont_give_word" or "finale_port_royale_hostage_duel_with_villain" depending on PChar.quest.alignment
			LAi_ActorDialog(PChar, villain, "player_back",10.0,10.0);	// "player_back" is in "quests_common.c" and resets you to playertype
		break;

		case "finale_port_royale_villain_moves_to_governor":
			LAi_ActorFollow(villain, CharacterFromID("John Clifford Brin"), "finale_port_royale_villain_talks_to_governor", 30.0);
		break;

		case "finale_port_royale_villain_talks_to_governor":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "finale_governor_cooperated";
			LAi_ActorDialogNow(villain, PChar, "finale_hostage_governor_pleads_with_villain",5.0);
		break;

		case "finale_hostage_governor_pleads_with_villain":
			LAi_SetActorType(characterfromID("John Clifford Brin"));
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_dont_harm_wife";
			LAi_ActorDialog(characterfromID("John Clifford Brin"),PChar,"finale_hostage_villain_turns_to_player",10.0,10.0);
		break;

		case "finale_hostage_villain_turns_to_player":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "finale_now_for_you";
			LAi_ActorDialog(villain,PChar,"",10.0,10.0);			// Exits to "finale_governor_wont_give_word" or "finale_port_royale_hostage_duel_with_villain" depending on PChar.quest.alignment
		break;

		case "finale_governor_wont_give_word":
			LAi_SetActorType(characterfromID("John Clifford Brin"));
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_you_ask_too_much";
			LAi_ActorDialog(characterfromID("John Clifford Brin"),PChar,"finale_hostage_safe_conduct_granted",10.0,10.0);
		break;

		case "finale_hostage_safe_conduct_granted":
			LAi_SetActorType(villain);
			Characters[villainidx].dialog.CurrentNode = "finale_challenge_accepted";
			LAi_ActorDialog(villain,PChar,"finale_port_royale_hostage_duel_with_villain",10.0,10.0);
		break;

		case "finale_port_royale_hostage_duel_with_villain":
			LAi_LocationFightDisable(&Locations[FindLocation("Redmond_Residence")], false);
			LAi_SetImmortal(CharacterFromID("John Clifford Brin"), true);
			LAi_SetCitizenType(CharacterFromID("John Clifford Brin"));
			LAi_SetImmortal(villain, false);
			LAi_NoRebirthEnable(villain);
			LAi_SetActorType(villain);
			LAi_ActorAttack(villain, PChar, "");
			PChar.quest.finale_port_royale_residence_duel_over.win_condition.l1 = "NPC_death";
			Pchar.quest.finale_port_royale_residence_duel_over.win_condition.l1.character = Characters[villainidx].id;
			Pchar.quest.finale_port_royale_residence_duel_over.win_condition = "finale_port_royale_residence_duel_over";
		break;

		case "finale_port_royale_residence_duel_over":
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("John Clifford Brin")));
			Preprocessor_AddQuestData("warship", PChar.quest.French_flagship.name);
			Preprocessor_AddQuestData("villain", GetMyFullName(villain));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(villain)));
			AddQuestRecord("Battle Royale", 13);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("villain");
			Preprocessor_Remove("warship");
			Preprocessor_Remove("governor");
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Redmond_Residence")], true);
			LAi_SetActorType(characterfromID("John Clifford Brin"));
			if (CheckQuestAttribute("alignment", "evil")) Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_you_would_let_villain_kill_me";
			else Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_villain_dead_in_residence";
			LAi_ActorDialog(characterfromID("John Clifford Brin"),PChar,"finale_port_royale_finished_rewards",10.0,10.0);
		break;

		case "finale_soldier_reports_victory":		// Triggered by dialog with "John Clifford Brin"
			temp = "m" + (rand(5) + 1);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.(temp), "reload", "reload1");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "Reporting Soldier";
			sld.nation = ENGLAND;
			SetRandomNameToCharacter(sld);
			sld.Dialog.Filename = "guard_dialog.c";
			sld.Dialog.CurrentNode = "finale_report_victory_at_sea";
			LAi_QuestDelay("finale_soldier_reports_victory2", 0.1);
		break;

		case "finale_soldier_reports_victory2":
			LAi_SetActorType(characterfromID("Reporting Soldier"));
			LAi_ActorDialog(characterfromID("Reporting Soldier"),PChar,"finale_soldier_reports_victory3",10.0,10.0);
		break;

		case "finale_soldier_reports_victory3":
            		LAi_ActorGoToLocation(CharacterFromID("Reporting Soldier"), "reload", "reload1", "None", "", "", "", 10.0);
			LAi_SetActorType(characterfromID("John Clifford Brin"));
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.CurrentNode = "finale_so_it_is_true";
			LAi_ActorDialog(characterfromID("John Clifford Brin"),PChar,"finale_port_royale_finished_rewards",10.0,10.0);
		break;

		case "finale_port_royale_finished_rewards":
			AddQuestRecord("Battle Royale", 12);
			LAi_SetHuberStayType(characterfromID("John Clifford Brin"));
			LAi_SetStayHuberPointWindow(characterfromID("John Clifford Brin"), "goto", "goto10");
			LAi_SetStayHuberPointMap(characterfromID("John Clifford Brin"), "goto", "goto9");
			characters[GetCharacterIndex("John Clifford Brin")].Dialog.Filename.GroupDialog = "governor.c";
			ch = CharacterFromID("John Clifford Brin");
			RestoreDialog(CharacterFromID("John Clifford Brin"));
			EndQuestMovie();
			DisableFastTravel(false);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 4000);
				AddPartyExpChar(PChar, "", 500);
				AddPartyExpChar(PChar, "Sneak", 500);
			}
			else {AddPartyExp(PChar, 5000);}
		break;

		case "finale_reset_port_royale_governor":
			ch = CharacterFromID(GetTownGovernorID("Redmond"));
			ChangeCharacterAddressGroup(ch, "Redmond_Residence", "goto", "goto8");
			LAi_SetHuberStayType(ch);
			LAi_SetStayHuberPointWindow(ch, "goto", "goto10");
			LAi_SetStayHuberPointMap(ch, "goto", "goto9");
			ch.Dialog.Filename.GroupDialog = "governor.c";
			if (!RestoreDialog(ch))
			{
				ch.Dialog.Filename = "John Clifford Brin_dialog.c";
				ch.dialog.CurrentNode = "First time";
			}
			LAi_SetImmortal(ch, false);
			LAi_RemoveLoginTime(ch);
		break;

		case "finale_santiago_evacuation_setup":	// Triggered by dialog with Jusepe Guimaraes
			if (!LAi_IsDead(romance) && !isofficer(romance) && !ispassenger(romance) && !iscompanion(romance))
			{
				ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
				LAi_SetCitizenType(romance);
			}
			if(isofficer(romance) || ispassenger(romance))
			{
				PChar.quest.romance_to_townhall.win_condition.l1 = "location";
				PChar.quest.romance_to_townhall.win_condition.l1.location = "Santiago_townhall";
				PChar.quest.romance_to_townhall.win_condition = "romance_to_townhall";
			}
			PChar.quest.finale_evacuate_santiago = "go_get_him";
		break;

		case "finale_assign_galleons":			// Triggered by dialog with Jusepe Guimaraes or "Javier Balboa"
			SetCompanionIndex(PChar,-1, GetCharacterIndex("Spanish_Captain4"));
			SetCompanionIndex(PChar,-1, GetCharacterIndex("Spanish_Captain1"));
			SetCharacterRemovable(characterFromID("Spanish_Captain4"), false);
			SetCharacterRemovable(characterFromID("Spanish_Captain1"), false);
			SetRank(characterFromID("Spanish_Captain1"), SPAIN, 5);
			characters[GetCharacterIndex("Spanish_Captain1")].dialog.CurrentNode = "sailing_together";
			characters[GetCharacterIndex("Spanish_Captain1")].dialog.TempNode = "sailing_together";
			DeleteAttribute(&characters[GetCharacterIndex("Spanish_Captain1")], "Title");
			PChar.quest.finale_galleons = 3;	// 1 + 2 = both galleons, not three galleons
			PChar.quest.finale_galleons_leave.win_condition.l1 = "Timer";
			PChar.quest.finale_galleons_leave.win_condition.l1.date.day = GetAddingDataDay(0, 0, 20);
			PChar.quest.finale_galleons_leave.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 20);
			PChar.quest.finale_galleons_leave.win_condition.l1.date.year = GetAddingDataYear(0, 0, 20);
			PChar.quest.finale_galleons_leave.win_condition = "finale_galleons_leave";
			Pchar.quest.finale_galleons_leave_antigua.win_condition.l1 = "location";
			Pchar.quest.finale_galleons_leave_antigua.win_condition.l1.location = "Antigua";
			Pchar.quest.finale_galleons_leave_antigua.win_condition = "finale_galleons_leave";
		break;

		case "finale_galleons_leave":
			PChar.quest.finale_galleons_leave.over = "yes";
			Pchar.quest.finale_galleons_leave_antigua.over = "yes";
			if(iscompanion(CharacterFromID("Spanish_Captain1")))
			{
				SetCharacterRemovable(characterFromID("Spanish_Captain1"), true);
				RemoveCharacterCompanion(PChar, characterFromID("Spanish_Captain1"));
			}
			if(iscompanion(CharacterFromID("Spanish_Captain4")))
			{
				SetCharacterRemovable(characterFromID("Spanish_Captain4"), true);
				RemoveCharacterCompanion(PChar, characterFromID("Spanish_Captain4"));
			}
			Preprocessor_AddQuestData("assigner", GetMyFullName(CharacterFromID(PChar.quest.finale_galleons_assigned_by)));
			AddQuestRecord("Battle Royale", 22);
			Preprocessor_Remove("assigner");
			PChar.quest.finale_galleons = 0;
		break;

		case "finale_galleons_detach_in_battle":
			if(CheckAttribute(PChar, "quest.finale_galleons_leave")) PChar.quest.finale_galleons_leave.over = "yes";
			if(iscompanion(CharacterFromID("Spanish_Captain1")))
			{
				SetCharacterRemovable(characterFromID("Spanish_Captain1"), true);
				RemoveCharacterCompanion(PChar, characterFromID("Spanish_Captain1"));
			}
			if(iscompanion(CharacterFromID("Spanish_Captain4")))
			{
				SetCharacterRemovable(characterFromID("Spanish_Captain4"), true);
				RemoveCharacterCompanion(PChar, characterFromID("Spanish_Captain4"));
			}
		break;

		case "finale_port_royale_fallen":	// Triggered by dialog with "Javier Balboa" or "Antigua_Portadmiral"
			Pchar.quest.French_fleet_setup.over = "yes";
			CaptureTownForNation("Redmond", FRANCE);
			Islands[FindIsland("Redmond")].smuggling_nation = FRANCE;
			ChangeCharacterAddress(characterFromID(Towns[GetTownIndex("Redmond")].gov), "none", "");
			ChangeCharacterAddressGroup(villain, "redmond_residence", "goto", "goto8");
			Characters[villainidx].nation = FRANCE;
			Characters[villainidx].dialog.currentnode = "treachery_governor";
			Towns[GetTownIndex("Redmond")].gov = villain.id;
		break;

		case "finale_evacuate_santiago_take_romance":
			Preprocessor_AddQuestData("governor", "Governor " + GetMyLastName(CharacterFromID("Javier Balboa")));
			Preprocessor_AddQuestData("romance", GetMyFullName(romance));
			AddQuestRecord("Battle Royale", 24);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("governor");
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "finale_stay_with_father";
			LAi_ActorDialog(romance,PChar,"finale_evacuate_santiago_take_romance2",5.0,5.0);
		break;

		case "finale_evacuate_santiago_take_romance2":
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "finale_go_kid_go";
			LAi_ActorDialogNow(CharacterFromID("Javier Balboa"), PChar, "finale_evacuate_santiago_take_romance3",1.0);
		break;

		case "finale_evacuate_santiago_take_romance3":
			LAi_SetHuberStayType(CharacterFromID("Javier Balboa"));
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "finale_win_or_avenge";
			LAi_ActorDialog(romance,PChar,"finale_evacuate_santiago_take_romance4",5.0,5.0);
		break;

		case "finale_evacuate_santiago_take_romance4":
			if (isofficer(romance)) LAi_SetOfficerType(romance);
			else
			{
				LAi_SetActorType(romance);
				LAi_ActorFollowEverywhere(romance, "", 10.0);
			}
			if (!ispassenger(romance) && !isofficer(romance) && !iscompanion(romance))
			{
				AddPassenger(PChar, romance, 0);
				SetCharacterRemovable(romance, false);
			}
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_townhall", "sit", "sit1");
			LAi_SetHuberType(characterFromID("Javier Balboa"));
			LAi_QuestDelay("finale_evacuate_santiago_prepare_for_french_fleet", 0.1);
		break;

		case "finale_evacuate_santiago_prepare_for_french_fleet":
			Pchar.quest.French_fleet_setup_Santiago.win_condition.l1 = "location";
			Pchar.quest.French_fleet_setup_Santiago.win_condition.l1.location = "Cuba";
			Pchar.quest.French_fleet_setup_Santiago.win_condition = "French_fleet_setup_Santiago";
		break;

		case "French_fleet_setup_Santiago":

			if(iscompanion(CharacterFromID("Spanish_Captain1")) || iscompanion(CharacterFromID("Spanish_Captain4")))	// If extra galleons present, detach them so you can take more prize ships
			{
				pchar.quest.finale_galleons_detach_in_battle.win_condition.l1 = "SeaEnter";
				PChar.quest.finale_galleons_detach_in_battle.win_condition = "finale_galleons_detach_in_battle";
			}
			bQuestDisableMapEnter = true;
			Group_CreateGroup("French_fleet2");
			Group_AddCharacter("French_fleet2", "French_Amiral");
			if (!LAi_IsDead(characterfromID("French_Contre-Amiral"))) Group_AddCharacter("French_fleet2", "French_Contre-Amiral");
			if (!LAi_IsDead(characterfromID("French_Captain2"))) Group_AddCharacter("French_fleet2", "French_Captain2");
			if (!LAi_IsDead(characterfromID("French_Captain3"))) Group_AddCharacter("French_fleet2", "French_Captain3");
			Group_SetGroupCommander("French_fleet2", "French_Amiral");
			Group_SetPursuitGroup("French_fleet2", PLAYER_GROUP);
			Group_SetTaskAttack("French_fleet2",  PLAYER_GROUP, true);
			Group_LockTask("French_fleet2");
			Group_SetAddress("French_fleet2", "Cuba", "Quest_ships", "quest_ship_1"); 
//			Sea_LoginGroupNow("French_fleet2");
			characters[GetCharacterIndex("French_Amiral")].nosurrender = 2;
			characters[GetCharacterIndex("French_Contre-Amiral")].nosurrender = 2;
			characters[GetCharacterIndex("French_Captain2")].nosurrender = 2;
			characters[GetCharacterIndex("French_Captain3")].nosurrender = 2;
			Characters[GetCharacterIndex("French_Amiral")].recognized = true;
			Characters[GetCharacterIndex("French_Contre-Amiral")].recognized = true;
			Characters[GetCharacterIndex("French_Captain2")].recognized = true;
			Characters[GetCharacterIndex("French_Captain3")].recognized = true;

			characters[GetCharacterIndex("French_Contre-Amiral")].Dialog.Filename = "Cabinfight_dialog.c";
			characters[GetCharacterIndex("French_Captain2")].Dialog.Filename = "Cabinfight_dialog.c";
			characters[GetCharacterIndex("French_Captain3")].Dialog.Filename = "Cabinfight_dialog.c";
			LAi_SetStayType(characterfromID("French_Contre-Amiral"));
			LAi_SetStayType(characterfromID("French_Captain2"));
			LAi_SetStayType(characterfromID("French_Captain3"));

			PChar.quest.French_flagship.type = GetCharacterShipModel(characterfromID("French_Amiral"));
			PChar.quest.French_flagship.name = Characters[GetCharacterIndex("French_Amiral")].Ship.Name;
			PChar.quest.French_flagship.cabin = GetCharacterShipCabin(CharacterfromID("French_Amiral"));

			PChar.quest.French_flagship_down.win_condition.l1 = "NPC_death";
			Pchar.quest.French_flagship_down.win_condition.l1.character = "French_Amiral";
			Pchar.quest.French_flagship_down.win_condition = "French_flagship_down";

			PChar.quest.Santiago_battle_over.win_condition.l1 = "NPC_death";
			Pchar.quest.Santiago_battle_over.win_condition.l1.character = "French_Amiral";
			if (!LAi_IsDead(characterfromID("French_Contre-Amiral")))
			{
				PChar.quest.Santiago_battle_over.win_condition.l2 = "NPC_death";
				Pchar.quest.Santiago_battle_over.win_condition.l2.character = "French_Contre-Amiral";
			}
			if (!LAi_IsDead(characterfromID("French_Captain2")))
			{
				PChar.quest.Santiago_battle_over.win_condition.l3 = "NPC_death";
				Pchar.quest.Santiago_battle_over.win_condition.l3.character = "French_Captain2";
			}
			if (!LAi_IsDead(characterfromID("French_Captain3")))
			{
				PChar.quest.Santiago_battle_over.win_condition.l4 = "NPC_death";
				Pchar.quest.Santiago_battle_over.win_condition.l4.character = "French_Captain3";
			}
			pchar.quest.Santiago_battle_over.win_condition.l5 = "SeaEnter";
			Pchar.quest.Santiago_battle_over.win_condition = "Santiago_battle_over";
		break;

		case "Santiago_battle_over":
			bQuestDisableMapEnter = false;
			PChar.quest.invasion_status = "warship_defeated";
			PChar.quest.finale_evacuate_santiago = "not_needed";
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "finale_after_santiago_reward";
/*			if(CheckAttribute(PChar, "quest.finale_galleons_leave")) PChar.quest.finale_galleons_leave.over = "yes";
			if(iscompanion(CharacterFromID("Spanish_Captain1")))
			{
				SetCharacterRemovable(characterFromID("Spanish_Captain1"), true);
				RemoveCharacterCompanion(PChar, characterFromID("Spanish_Captain1"));
			}
			if(iscompanion(CharacterFromID("Spanish_Captain4")))
			{
				SetCharacterRemovable(characterFromID("Spanish_Captain4"), true);
				RemoveCharacterCompanion(PChar, characterFromID("Spanish_Captain4"));
			} */

			if (!LAi_IsDead(romance))
			{
				Pchar.quest.finale_romance_joins_in_santiago.win_condition.l1 = "location";
				Pchar.quest.finale_romance_joins_in_santiago.win_condition.l1.location = "Santiago_port";
				Pchar.quest.finale_romance_joins_in_santiago.win_condition = "romance_joins_in_santiago";
			}


			if (!CanMarry(romance))
			{
				bQuestDisableMapEnter = false;
				PChar.location.from_sea = "Santiago_port";
				
				if (!HasThisShip(PChar.quest.French_flagship.type))
				{
					ChangeCharacterAddressGroup(villain, GetCharacterShipCabin(PChar), "rld", "startloc");
					DoReloadFromSeaToLocation(GetCharacterShipCabin(PChar), "reload", "reload1");
					Characters[villainidx].dialog.CurrentNode = "finale_challenge_to_duel_own_cabin";
					LAi_QuestDelay("finale_duel_on_ship", 1.0);
				}
				else
				{
					ChangeCharacterAddressGroup(villain, PChar.quest.French_flagship.cabin, "rld", "startloc");
					DoReloadFromSeaToLocation(PChar.quest.French_flagship.cabin, "reload", "reload1");
					Characters[villainidx].dialog.CurrentNode = "finale_challenge_to_duel";
					LAi_QuestDelay("finale_duel_on_ship", 1.0);
				}
			}

			if(GetRMRelation(PChar, FRANCE) > REL_WAR)	// Shouldn't be needed as "French_Amiral" doesn't have "skipRM" attribute, but someone reported still having French LoM after taking Dauphin Royal so let's not take chances
			{
				SetRMRelation(PChar, FRANCE, REL_WAR);
				LeaveService(PChar, FRANCE, true);
			}
		break;

		case "finale_return_to_Santiago":
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_SetPlayerType(PChar);
			LAi_SetFightMode(PChar, false);
		break;

		case "finale_marriage_romance_accepts":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "finale_accept_marriage";
			LAi_ActorDialog(romance,PChar,"finale_marriage_governor_asks_about_ring",5.0,5.0);
		break;

		case "finale_marriage_governor_asks_about_ring":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "finale_marriage_do_you_have_ring";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",1.0,1.0);
		break;

		case "romance_joins_in_santiago":
			if(iscompanion(romance) || ispassenger(romance))
			{
				if (!isofficer(romance))
				{
					ChangeCharacterAddressGroup(romance, "Santiago_port", "goto", "goto3");
					LAi_SetActorType(romance);
					LAi_ActorFollowEverywhere(romance, "", 10.0);
				}
			}
			PChar.quest.romance_to_townhall.win_condition.l1 = "location";
			PChar.quest.romance_to_townhall.win_condition.l1.location = "Santiago_townhall";
			PChar.quest.romance_to_townhall.win_condition = "romance_to_townhall";
		break;

		case "romance_to_townhall":
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto2");
			if (!isofficer(romance))
			{
				ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
				PChar.quest.romance_disappears.win_condition.l1 = "location";
				PChar.quest.romance_disappears.win_condition.l1.location = "Cuba";
				PChar.quest.romance_disappears.win_condition = "romance_disappears";
			}
		break;

		case "romance_disappears":
			ChangeCharacterAddress(romance, "None", "");
			LAi_SetOfficerType(romance);
		break;


		case "finale_end_story":
			SetCharacterRemovable(romance, true);
			CloseQuestHeader("Battle Royale");
			if (CheckQuestAttribute("warship_named", "true"))
			{
				SetQuestHeader("History");
				AddQuestRecord("History", 1);
				DeleteQuestAttribute("warship_named");
				PChar.quest.close_history.win_condition.l1 = "Timer";
				PChar.quest.close_history.win_condition.l1.date.day = GetAddingDataDay(0, 0, 14);
				PChar.quest.close_history.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
				PChar.quest.close_history.win_condition.l1.date.year = GetAddingDataYear(0, 0, 14);
				PChar.quest.close_history.win_condition = "close_history";
			}
			if (GetTownGovernorID("Redmond") == villain.id)
			{
				if (LAi_IsDead(villain))
				{
					Towns[GetTownIndex("Redmond")].gov = "John Clifford Brin";
				}
				else
				{
					DeleteAttribute(villain, "questchar");
				}
			}
			Pchar.quest.finale_reset_governor2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.finale_reset_governor2.win_condition.l1.location = PChar.location;
			Pchar.quest.finale_reset_governor2.win_condition = "finale_reset_port_royale_governor";

			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = 0;		// Make sure residence is unlocked
			Pchar.quest.finale_reset_governor1.win_condition.l1 = "ExitFromLocation";
			PChar.quest.finale_reset_governor1.win_condition.l1.location = PChar.location;
			Pchar.quest.finale_reset_governor1.win_condition = "reset_governor";

//			Pchar.quest.finale_end_theme.win_condition.l1 = "ExitFromLocation";
//			PChar.quest.finale_end_theme.win_condition.l1.location = PChar.location;
			Pchar.quest.finale_end_theme.win_condition.l1 = "location";
			Pchar.quest.finale_end_theme.win_condition.l1.location = "Cuba";
			pchar.quest.finale_end_theme.win_condition.l2 = "SeaEnter";
			Pchar.quest.finale_end_theme.win_condition = "finale_end_theme";
//			DisableFastTravel(true);
			SetNextWeather("Clear");

			Locations[FindLocation("Redmond_town_03")].reload.l9.disable = 0;		// Make sure Gilbert Downing's house is unlocked
			locations[FindLocation("Quest_Merchant_House")].reload.l2.disable = 1;		// Lock door from house to prison
			locations[FindLocation("Quest_Cellar_Prison")].reload.l2.disable = 1;		// Lock door from prison to dungeon
			Locations[FindLocation("Redmond_Dungeon_2")].models.always.locators = "d02_l";	// Reset dungeon to standard locators without prison
			Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "museum_open";

// Tidy up left-over attributes
			DeleteQuestAttribute("normal_dialog");
			DeleteQuestAttribute("abduction_status");
			DeleteQuestAttribute("assassination");
			DeleteQuestAttribute("convoy");
			DeleteQuestAttribute("ardent_treachery_status");
			DeleteQuestAttribute("treachery_peace_england");
			DeleteQuestAttribute("ardent_hunt_status");
			DeleteQuestAttribute("academy_breakin_name");
			DeleteQuestAttribute("hunt_romance_on_ship");
			DeleteQuestAttribute("invasion_status");
			DeleteQuestAttribute("finale_galleons");
			DeleteQuestAttribute("finale_galleons_assigned_by");
//			DeleteQuestAttribute("French_flagship");

			if (CheckCharacterItem(PChar, "BattleOrders"))	ItemSetPrice("BattleOrders", 1); // Can now drop surplus quest items. (Can NOT dump your wedding ring!)
			if (CheckCharacterItem(PChar, "BattleOrders2"))	ItemSetPrice("BattleOrders2", 1);
			if (CheckCharacterItem(PChar, "key3"))		ItemSetPrice("key3", 1);
			if (CheckCharacterItem(PChar, "SignetRing"))	ItemSetPrice("SignetRing", 1);

			DisableTownCapture("Redmond", false);						// Unlock Port Royale and Santiago for player capture
			DisableTownCapture("Santiago", false);
			AddStorylineVar(FindCurrentStoryline(), "CHANGING_RELATIONS", "1");		// International relations can now change randomly

			PChar.quest.imperial_escort_enable = true;					// Unlock "Imperial Escort" extra quest

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 4000);
				AddPartyExpChar(PChar, "", 500);
				AddPartyExpChar(pchar, "Sneak", 500);
			}
			else {AddPartyExp(pchar, 5000);}

			if (!LAi_IsDead(villain) && GetTownGovernorID("Redmond") != villain.id) LAi_QuestDelay("after_finale_hunt_villain", 1.0);
		break;

		case "finale_end_theme":
			PChar.seamusic = "silence";						// Stop normal music from messing up end theme
			PChar.seabattlemusic = "silence";					// Just in case you set sail straight into a battle with coastal raiders

			PauseAllSounds();
                	FadeOutMusic(100);
			PlayStereoOGG("Ardent_end");						// This piece is a bit quiet, so play as effect instead

			Pchar.quest.finale_cancel_end_theme.win_condition.l1 = "MapEnter";
			Pchar.quest.finale_cancel_end_theme.win_condition = "finale_cancel_end_theme";
		break;

		case "finale_cancel_end_theme":
			DeleteAttribute(PChar, "seamusic");
			DeleteAttribute(PChar, "seabattlemusic");
		break;

		case "close_history":
			CloseQuestHeader("History");
		break;

		case "after_finale_hunt_villain":
			Characters[villainidx].nation = FRANCE;
			if (GetTownNation("Redmond") == FRANCE) i = rand(4);
			else i = rand(3);
// i = 2;	// Set this to choose one of the islands for testing
			switch(i)
			{
				case 0:		// Martinique
					Characters[villainidx].at_island = "FalaiseDeFleur";
					Characters[villainidx].hostile_fort = "None";
					Characters[villainidx].spawn_group = "quest_ships";
					Characters[villainidx].spawn_locator = "quest_ship_16";
				break;

				case 1:		// Guadeloupe
					Characters[villainidx].at_island = "Guadeloupe";
					Characters[villainidx].hostile_fort = "None";
					Characters[villainidx].spawn_group = "Quest_ships";
					Characters[villainidx].spawn_locator = "quest_ship_1";
				break;

				case 2:		// St. Martin
					Characters[villainidx].at_island = "SaintMartin";
					Characters[villainidx].hostile_fort = "Philipsburg";
					Characters[villainidx].spawn_group = "Quest_ships";
					Characters[villainidx].spawn_locator = "quest_ship_14";
				break;

				case 3:		// Hispaniola
					Characters[villainidx].at_island = "Hispaniola";
					Characters[villainidx].hostile_fort = "Santo Domingo";
					Characters[villainidx].spawn_group = "Quest_ships";
					Characters[villainidx].spawn_locator = "quest_ship_1";
				break;

				case 4:		// Jamaica - only if Port Royale captured by France
					Characters[villainidx].at_island = "Redmond";
					Characters[villainidx].hostile_fort = "None";
					Characters[villainidx].spawn_group = "quest_ships";
					Characters[villainidx].spawn_locator = "quest_ship_15";
				break;
			}

			PChar.quest.after_finale_found_villain.win_condition.l1 = "location";
			Pchar.quest.after_finale_found_villain.win_condition.l1.location = villain.at_island;
			Pchar.quest.after_finale_found_villain.win_condition = "after_finale_found_villain";
		break;

		case "after_finale_found_villain":
/*			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			if (villain.sex == "woman") Preprocessor_AddQuestData("pronoun", "her");
			else Preprocessor_AddQuestData("pronoun", "his");
			Preprocessor_AddQuestData("island", FindIslandName(villain.at_island));
			Preprocessor_AddQuestData("ship", villain.Ship.Name);
			SetQuestHeader("Find_Villain");
			AddQuestRecord("Find_Villain", 1);
			Preprocessor_Remove("ship");
			Preprocessor_Remove("island");
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("villain"); */
//			bQuestDisableMapEnter = true;
			Group_CreateGroup("villain_ship");
			Group_AddCharacter("villain_ship", villain.id);
			Group_SetGroupCommander("villain_ship", villain.id);
			if (CheckAttribute(villain, "spawn_group") && villain.spawn_group != "")
			{
				Group_SetAddress("villain_ship", villain.at_island, villain.spawn_group, villain.spawn_locator);
			}
			else
			{
				Group_SetPursuitGroup("villain_ship", PLAYER_GROUP);
				Group_SetAddress("villain_ship", villain.at_island, "Quest_ships", "quest_ship_1");
			}
			Group_SetTaskAttack("villain_ship",  PLAYER_GROUP, true);
			Characters[villainidx].recognized = true;
			Group_LockTask("villain_ship"); 
//			Sea_LoginGroupNow("villain_ship");
	
			PChar.quest.after_finale_villain_sunk.win_condition.l1 = "NPC_death";
			Pchar.quest.after_finale_villain_sunk.win_condition.l1.character = villain.id;
			Pchar.quest.after_finale_villain_sunk.win_condition = "after_finale_villain_sunk";
		break;

		case "after_finale_villain_sunk":
			Preprocessor_AddQuestData("villain", GetMySimpleName(villain));
			Preprocessor_AddQuestData("ship", villain.Ship.Name);
			SetQuestHeader("Find_Villain");
			AddQuestRecord("Find_Villain", 2);
			CloseQuestHeader("Find_Villain");
			Preprocessor_Remove("ship");
			Preprocessor_Remove("villain");

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 800);
				AddPartyExpChar(PChar, "", 200);
				AddPartyExpChar(pchar, "Sailing", 200);
			}
			else {AddPartyExp(pchar, 1200);}

			DeleteAttribute(villain, "at_island");
			DeleteAttribute(villain, "hostile_fort");
		break;

		case "museum_gilbert_opens_door":
			ChangeCharacterAddressGroup(CharacterFromID("Gilbert Downing"), "Quest_Merchant_House", "goto", "goto9");
			LAi_SetActorType(CharacterFromID("Gilbert Downing"));
			LAi_QuestDelay("museum_gilbert_opens_door2", 1.0);
		break;

		case "museum_gilbert_opens_door2":
			LAi_SetActorType(CharacterFromID("Gilbert Downing"));
			LAi_ActorGoToLocator(CharacterFromID("Gilbert Downing"), "reload", "reload3", "museum_gilbert_opens_door3",10.0);
		break;

		case "museum_gilbert_opens_door3":
			PlaySound("PEOPLE\lock_open.wav");

			Locations[FindLocation("Quest_Merchant_House")].reload.l2.name = "reload3";	// Duplicated from case "abduction_found_romance" in case you have not already been to the dungeon
			Locations[FindLocation("Quest_Merchant_House")].reload.l2.go = "Quest_Cellar_Prison";
			Locations[FindLocation("Quest_Merchant_House")].reload.l2.emerge = "reload1";
			Locations[FindLocation("Quest_Merchant_House")].reload.l2.autoreload = "0";
			Locations[FindLocation("Quest_Merchant_House")].reload.l2.label = "Old Inquisition prison.";

			locations[FindLocation("Quest_Merchant_House")].reload.l2.disable = 0;
			Locations[FindLocation("Quest_Cellar_Prison")].locators_radius.reload.reload6 = 2.5;
			LAi_QuestDelay("museum_gilbert_sends_you_in", 3.0);
			Pchar.quest.museum_reset_gilbert.win_condition.l1 = "ExitFromLocation";
			PChar.quest.museum_reset_gilbert.win_condition.l1.location = PChar.location;
			Pchar.quest.museum_reset_gilbert.win_condition = "museum_reset_gilbert";

			PChar.quest.museum_setup.win_condition.l1 = "Location";
			PChar.quest.museum_setup.win_condition.l1.location = "Quest_Cellar_Prison";
			PChar.quest.museum_setup.win_condition = "museum_setup";
		break;

		case "museum_gilbert_sends_you_in":
			LAi_SetActorType(CharacterFromID("Gilbert Downing"));
			Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "museum_go_in";
			LAi_ActorDialog(CharacterFromID("Gilbert Downing"),PChar,"",3.0,3.0);
		break;

		case "museum_gilbert_returns_to_seat":
			LAi_SetActorType(CharacterFromID("Gilbert Downing"));
			LAi_ActorGoToLocator(CharacterFromID("Gilbert Downing"), "goto", "goto9", "",10.0);
		break;

		case "museum_reset_gilbert":
			LAi_SetActorType(CharacterFromID("Gilbert Downing"));
			LAi_type_Actor_Reset(CharacterFromID("Gilbert Downing"));
			ChangeCharacterAddressGroup(CharacterFromID("Gilbert Downing"), "Quest_Merchant_House", "sit", "sit1");
			LAi_SetHuberType(CharacterFromID("Gilbert Downing"));
			Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "First time";
			locations[FindLocation("Quest_Merchant_House")].reload.l2.disable = 1;
		break;

		case "museum_setup":
			DisableFastTravel(true);
			StartQuestMovie(true, true, false);

			sld = LAi_CreateFantomCharacter(false, 1, false, false, 0.0, "Animist4B", "reload", "reload6");
			sld.id = "Museum Inquisitor 1";
			sld.nation = SPAIN;
			sld.old.name = "Cardinal";
			sld.name = TranslateString("","Cardinal");
			sld.old.lastname = "Ximinez";
			sld.lastname = TranslateString("","Ximinez");
			sld.Dialog.Filename = "Inquisitor_dialog.c";
			LAi_SetStayType(sld);
			sld.dialog.CurrentNode = "museum_heresy";

			sld = LAi_CreateFantomCharacter(false, 1, false, false, 0.0, "Animist4C", "reload", "reload4");
			sld.id = "Museum Inquisitor 2";
			sld.nation = SPAIN;
			sld.old.name = "Cardinal";
			sld.name = TranslateString("","Cardinal");
			sld.old.lastname = "Fang";
			sld.lastname = TranslateString("","Fang");
			sld.Dialog.Filename = "Inquisitor_dialog.c";
			LAi_SetStayType(sld);
			sld.dialog.CurrentNode = "museum_assistant";
			LAi_SetActorType(sld);
			Pchar.quest.museum_interrogation1.win_condition.l1 = "locator";
			Pchar.quest.museum_interrogation1.win_condition.l1.location = "Quest_Cellar_Prison";
			Pchar.quest.museum_interrogation1.win_condition.l1.locator_group = "reload";
			Pchar.quest.museum_interrogation1.win_condition.l1.locator = "reload6";
			Pchar.quest.museum_interrogation1.win_condition = "museum_interrogation1";
		break;

		case "museum_interrogation1":
			LAi_SetActorType(CharacterFromID("Museum Inquisitor 1"));
			Characters[GetCharacterIndex("Museum Inquisitor 1")].dialog.CurrentNode = "museum_heresy";
			LAi_ActorDialog(CharacterFromID("Museum Inquisitor 1"),PChar,"museum_interrogation2",1.0,1.0);
		break;

		case "museum_interrogation2":		// Triggered by dialog with "Museum Inquisitor 1" (Ximinez)
			LAi_SetActorType(CharacterFromID("Museum Inquisitor 2"));
			Characters[GetCharacterIndex("Museum Inquisitor 2")].dialog.CurrentNode = "museum_no_chair";
			LAi_ActorDialog(CharacterFromID("Museum Inquisitor 2"),PChar,"museum_inquisitor_arrives",1.0,1.0);
		break;

		case "museum_inquisitor_arrives":
			ChangeCharacterAddressGroup(CharacterFromID("Inquisitor"), "Quest_Cellar_Prison", "reload", "reload5");
			LAi_QuestDelay("museum_inquisitor_talks", 1.0);
		break;

		case "museum_inquisitor_talks":
			LAi_SetActorType(CharacterFromID("Inquisitor"));
			Characters[GetCharacterIndex("Inquisitor")].dialog.CurrentNode = "museum_no_trinkets";
			LAi_ActorDialogNow(CharacterFromID("Inquisitor"),PChar,"museum_should_only_be_two",1.0);
		break;

		case "museum_should_only_be_two":
			LAi_SetActorType(CharacterFromID("Museum Inquisitor 1"));
			Characters[GetCharacterIndex("Museum Inquisitor 1")].dialog.CurrentNode = "museum_should only_be_two";
			LAi_ActorDialog(CharacterFromID("Museum Inquisitor 1"),PChar,"museum_can_be_only_one",1.0,1.0);
		break;

		case "museum_can_be_only_one":
			LAi_SetActorType(CharacterFromID("Inquisitor"));
			Characters[GetCharacterIndex("Inquisitor")].dialog.CurrentNode = "museum_begone";
			LAi_ActorDialog(CharacterFromID("Inquisitor"),PChar,"museum_actors_leave",1.0,1.0);
		break;

		case "museum_actors_leave":
			LAi_SetActorType(CharacterFromID("Museum Inquisitor 1"));
			LAi_ActorRunToLocation(CharacterFromID("Museum Inquisitor 1"), "reload", "reload1", "none", "", "", "", 30.0);
			LAi_SetActorType(CharacterFromID("Museum Inquisitor 2"));
			LAi_ActorRunToLocation(CharacterFromID("Museum Inquisitor 2"), "reload", "reload1", "none", "", "", "", 30.0);
			LAi_QuestDelay("museum_inquisitor_ending", 1.0);
		break;

		case "museum_inquisitor_ending":
			LAi_SetActorType(CharacterFromID("Inquisitor"));
			Characters[GetCharacterIndex("Inquisitor")].dialog.CurrentNode = "museum_following_you";
			LAi_ActorDialog(CharacterFromID("Inquisitor"),PChar,"museum_done",1.0,1.0);
		break;

		case "museum_done":
			ChangeCharacterAddress(CharacterFromID("Inquisitor"), "None", "");
			EndQuestMovie();
			DisableFastTravel(false);
		break;

		case "imperial_escort_to_sanjuan":	// Triggered by dialog with Jusepe Guimaraes
			DeleteQuestAttribute("imperial_escort_enable");
			NPChar = CharacterFromID("Imperial_Captain");
			GiveShip2Character(NPChar, "FastGalleon5", "San Lorenzo", -1, SPAIN, true, true);
			NPChar.Ship.EmblemedSails.normalTex = "sail_weathered_common.tga";
			NPChar.Ship.EmblemedSails.nationFileName = "sail_holy_roman_empire.tga";

//			Maximum upgrades to escort ship
			stripUpgradesBerth(GetCharacterIndex("Imperial_Captain"));	// First remove any randomly existing upgrades
			applytunspeed(NPChar,"cplates",CPSPEEDRANGEMAX+1,CPSPEEDRANGEMAX);
			applytunturning(NPChar,"cplates",CPTURNINGRANGEMAX+1,CPTURNINGRANGEMAX);
			applytuninertia(NPChar,"cplates",CPINERTIARANGEMAX,CPINERTIARANGEMAX);

			applytunhullhp(NPChar,"rhull",RHHULLHPRANGEMAX,RHHULLHPRANGEMAX);
			applytuninertia(NPChar,"rhull",RHINERTIARANGEMAX,RHINERTIARANGEMAX);		
			applytunupcaliber(NPChar,"rhull",RHCALIBERADD);

			applytunspeed(NPChar,"nsails",NSSPEEDRANGEMAX+1,NSSPEEDRANGEMAX);
			applytuninertia(NPChar,"nsails",NSINERTIARANGEMAX,NSINERTIARANGEMAX);		
			applytunsailhp(NPChar,"nsails",NSSAILHPRANGEMAX,NSSAILHPRANGEMAX);

//			applytunspeed(NPChar,"ltopmasts",TMSPEEDRANGEMAX+1,TMSPEEDRANGEMAX);
//			applytuninertia(NPChar,"ltopmasts",TMINERTIARANGEMAX,TMINERTIARANGEMAX);		
//			applytunsailcrit(NPChar,"ltopmasts",TMSAILCRIT);

			applytunturning(NPChar,"stays",SSTURNINGRANGEMAX+1,SSTURNINGRANGEMAX);
			applytuntack(NPChar,"stays",SSTACKRANGEMAX,SSTACKRANGEMIN);

			NPChar.ship.tune.bcannons.on = 1;
			NPChar.ship.tune.gchasers.on = 1;
	
			makeref(ImpShip,ShipsTypes[GetShipIndex("FastGalleon5")]);	// Use Holy Roman Empire sails for Imperial ship
			ImpShip.EmblemedSails.normalTex = "sail_weathered_common.tga";
			ImpShip.EmblemedSails.nationFileName = "sail_holy_roman_empire.tga";

			PChar.quest.imperial_escort.ship_name = NPChar.Ship.Name;
			if(!CheckAttribute(PChar, "QuestInfo.Imperial Escort")) SetQuestHeader("Imperial Escort");
			Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			Preprocessor_AddQuestData("captain", GetMyFullName(NPChar));
			Preprocessor_AddQuestData("ship", PChar.quest.imperial_escort.ship_name);
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Imperial Escort", 1);
			Preprocessor_Remove("governor");
			Preprocessor_Remove("ship");
			Preprocessor_Remove("captain");
			Preprocessor_Remove("admiral");
			setCharacterShipLocation(NPChar, "Muelle_port");
			LAi_SetImmortal(NPChar, true);
			ChangeCharacterAddressGroup(NPChar, "Muelle_port", "goto", "goto8");
			LAi_SetStayType(NPChar);
			NPChar.dialog.CurrentNode = "Meeting_in_San_Juan";
		break;

		case "imperial_escort_meeting_in_cabin":
			cabin = GetCharacterShipCabin(CharacterFromID("Imperial_Captain"));
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_Captain"), cabin, "rld", "aloc0");
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_envoy"), cabin, "rld", "aloc1");
			StoreOfficers(PChar.id);
			DoQuestReloadToLocation(cabin, "reload", "reload1", "imperial_escort_meeting_in_cabin2");
		break;

		case "imperial_escort_meeting_in_cabin2":
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			Characters[GetCharacterIndex("Imperial_Captain")].Dialog.CurrentNode = "introduce_envoy";
			LAi_ActorDialog(characterfromID("Imperial_Captain"), PChar, "imperial_escort_envoy_answers", 5.0, 5.0);
		break;

		case "imperial_escort_envoy_answers":
			LAi_SetActorType(characterFromID("Imperial_envoy"));
			Characters[GetCharacterIndex("Imperial_envoy")].Dialog.CurrentNode = "envoy_intro";
			LAi_ActorDialog(characterfromID("Imperial_envoy"), PChar, "imperial_escort_emperors_daughter", 5.0, 5.0);
		break;

		case "imperial_escort_emperors_daughter":
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			Characters[GetCharacterIndex("Imperial_Captain")].Dialog.CurrentNode = "not_just_lady";
			LAi_ActorDialog(characterfromID("Imperial_Captain"), PChar, "imperial_escort_apologise", 5.0, 5.0);
		break;

		case "imperial_escort_apologise":
			LAi_SetActorType(characterFromID("Imperial_envoy"));
			Characters[GetCharacterIndex("Imperial_envoy")].Dialog.CurrentNode = "no_offence";
			LAi_ActorDialog(characterfromID("Imperial_envoy"), PChar, "imperial_escort_meeting_in_cabin_end", 5.0, 5.0);
		break;

		case "imperial_escort_meeting_in_cabin_end":
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			Characters[GetCharacterIndex("Imperial_Captain")].Dialog.CurrentNode = "mission_significance";
			LAi_ActorDialog(characterfromID("Imperial_Captain"), PChar, "", 5.0, 5.0);	// Exits to "imperial_escort_wait_till_morning_San_Juan" or "imperial_escort_to_San_Juan_residence"
		break;

		case "imperial_escort_wait_till_morning_San_Juan":
			LAi_Fade("", "");
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10.00, 0);
			LAi_QuestDelay("imperial_escort_next_day_San_Juan", 2.0);
		break;

		case "imperial_escort_next_day_San_Juan":
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			Characters[GetCharacterIndex("Imperial_Captain")].Dialog.CurrentNode = "escort_to_san_juan_residence";
			LAi_ActorDialog(characterfromID("Imperial_Captain"), PChar, "", 5.0, 5.0);	// Exits to "imperial_escort_to_San_Juan_residence"
		break;

		case "imperial_escort_to_San_Juan_residence":
			RestoreOfficers(PChar.id);
			DoQuestReloadToLocation("Muelle_port", "reload", "reload3_back", "imperial_escort_to_San_Juan_residence2");
		break;

		case "imperial_escort_to_San_Juan_residence2":
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			Preprocessor_AddQuestData("captain", GetMyFullName(CharacterFromID("Imperial_Captain")));
			Preprocessor_AddQuestData("ship", Characters[GetCharacterIndex("Imperial_Captain")].Ship.Name);
			AddQuestRecord("Imperial Escort", 2);
			Preprocessor_Remove("ship");
			Preprocessor_Remove("captain");
			Preprocessor_Remove("envoy");
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_Captain"), "Muelle_port", "goto", "goto10");
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_envoy"), "Muelle_port", "goto", "character4");
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			LAi_ActorFollowEverywhere(characterFromID("Imperial_Captain"), "", 10.0);
			LAi_SetActorType(characterFromID("Imperial_envoy"));
			LAi_ActorFollowEverywhere(characterFromID("Imperial_envoy"), "", 10.0);
			Locations[FindLocation("Muelle_town_04")].locators_radius.reload.reload5 = 5.0;
			Locations[FindLocation("Muelle_town_04")].reload.l5.disable = 1;

			PChar.quest.imperial_escort_close_San_Juan_residence_approach.win_condition.l1 = "location";
			PChar.quest.imperial_escort_close_San_Juan_residence_approach.win_condition.l1.location = "Muelle_town_04";
			PChar.quest.imperial_escort_close_San_Juan_residence_approach.win_condition = "imperial_escort_close_San_Juan_residence_approach";

			PChar.quest.imperial_escort_to_San_Juan_residence3.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_to_San_Juan_residence3.win_condition.l1.location = "Muelle_town_04";
			PChar.quest.imperial_escort_to_San_Juan_residence3.win_condition.l1.locator_group = "reload";
			PChar.quest.imperial_escort_to_San_Juan_residence3.win_condition.l1.locator = "reload5";
			PChar.quest.imperial_escort_to_San_Juan_residence3.win_condition = "imperial_escort_to_San_Juan_residence3";

			PChar.quest.imperial_escort_envoy_dead.win_condition.l1 = "NPC_death";
			Pchar.quest.imperial_escort_envoy_dead.win_condition.l1.character = "Imperial_envoy";
			Pchar.quest.imperial_escort_envoy_dead.win_condition = "imperial_escort_bad_stuff";
		break;

		case "imperial_escort_close_San_Juan_residence_approach":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
		break;

		case "imperial_escort_to_San_Juan_residence3":
			Locations[FindLocation("Muelle_town_04")].locators_radius.reload.reload5 = 1.0;
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			Characters[GetCharacterIndex("Imperial_Captain")].Dialog.CurrentNode = "san_juan_residence_arrived";
			LAi_ActorDialog(characterfromID("Imperial_Captain"), PChar, "imperial_escort_to_San_Juan_residence_arrived", 5.0, 5.0);
		break;

		case "imperial_escort_to_San_Juan_residence_arrived":
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			LAi_SetActorType(characterFromID("Imperial_envoy"));
            		LAi_ActorGoToLocation(characterFromID("Imperial_Captain"), "reload", "reload5", "None", "", "", "", 10.0);
            		LAi_ActorGoToLocation(characterFromID("Imperial_envoy"), "reload", "reload5", "None", "", "", "", 10.0);
			LAi_SetLoginTime(characterFromID("Imperial_Captain"), 6.0, 22.0);
			PChar.quest.imperial_escort_ready_to_sail.win_condition.l1 = "Timer";
			PChar.quest.imperial_escort_ready_to_sail.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
			PChar.quest.imperial_escort_ready_to_sail.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.imperial_escort_ready_to_sail.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.imperial_escort_ready_to_sail.win_condition = "imperial_escort_ready_to_sail";
		break;

		case "imperial_escort_ready_to_sail":
			Locations[FindLocation("Muelle_town_04")].reload.l5.disable = 0;
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_Captain"), "Muelle_port", "goto", "goto8");
			LAi_SetStayType(characterFromID("Imperial_Captain"));
			Characters[GetCharacterIndex("Imperial_Captain")].Dialog.CurrentNode = "sail_to_santo_domingo";
		break;

		case "imperial_escort_sail_to_santo_domingo":	// triggered by dialog with "Imperial_Captain"
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			Preprocessor_AddQuestData("ship", Characters[GetCharacterIndex("Imperial_Captain")].Ship.Name);
			AddQuestRecord("Imperial Escort", 3);
			Preprocessor_Remove("ship");
			Preprocessor_Remove("envoy");
			Locations[FindLocation("Muelle_town_04")].reload.l5.disable = 0;
			SetCompanionIndex(PChar, -1, GetCharacterIndex("Imperial_Captain"));
			SetCharacterRemovable(characterFromID("Imperial_Captain"), false);
			LAi_SetLoginTime(characterFromID("Imperial_Captain"), 0.0, 24.0);
			Characters[GetCharacterIndex("Imperial_Captain")].Dialog.TempNode = "First time";
			Characters[GetCharacterIndex("Imperial_Captain")].location = "none";

			PChar.quest.imperial_escort.French_Ambush_Captain4_assigned = true;
			if(GetDifficulty() >= DIFFICULTY_SEADOG)
			{
				i = 8;
				for (n = COMPANION_MAX - 1; n >= 0; n--)
				{
					cidx = GetCompanionIndex(GetMainCharacter(), n);
					if (cidx >= 0)
					{
						crewref = GetCharacter(cidx);
						if (GetCharacterShipClass(crewref) > 0 ) cc = GetCharacterShipClass(crewref);
						if (cc < i) i = cc;
					}
				}
				if (i <= 2)
				{
					PChar.quest.imperial_escort.French_Ambush_Captain1_assigned = true;
					if (GetCompanionQuantity(PChar) < 4) DeleteQuestAttribute("imperial_escort.French_Ambush_Captain4_assigned");
				}
			}

			PChar.quest.imperial_escort_mona_battle_setup.win_condition.l1 = "location";
			PChar.quest.imperial_escort_mona_battle_setup.win_condition.l1.location = "IslaMona";
			PChar.quest.imperial_escort_mona_battle_setup.win_condition = "imperial_escort_mona_battle_setup";

			PChar.quest.imperial_escort_hisp_battle_setup.win_condition.l1 = "location";
			PChar.quest.imperial_escort_hisp_battle_setup.win_condition.l1.location = "Hispaniola";
			PChar.quest.imperial_escort_hisp_battle_setup.win_condition = "imperial_escort_hisp_battle_setup";

			LAi_SetImmortal(characterFromID("Imperial_Captain"), false);
			PChar.quest.imperial_escort_battle_over.fail_condition.l1 = "NPC_death";
			Pchar.quest.imperial_escort_battle_over.fail_condition.l1.character = "Imperial_Captain";
			Pchar.quest.imperial_escort_battle_over.fail_condition = "imperial_escort_battle_lost";
		break;

		case "imperial_escort_mona_battle_setup":
			PChar.quest.imperial_escort_battle_location = PChar.location;
//			Island_SetReloadEnableGlobal(PChar.quest.imperial_escort_battle_location, false);

			Group_CreateGroup("imperial_escort_ambush");
			Group_AddCharacter("imperial_escort_ambush", "French_Ambush_Captain2");
			Group_AddCharacter("imperial_escort_ambush", "French_Ambush_Captain3");
			if (CheckAttribute(PChar, "quest.imperial_escort.French_Ambush_Captain4_assigned")) Group_AddCharacter("imperial_escort_ambush", "French_Ambush_Captain4");
			if (CheckAttribute(PChar, "quest.imperial_escort.French_Ambush_Captain1_assigned"))
			{
				Group_AddCharacter("imperial_escort_ambush", "French_Ambush_Captain1");
				Group_SetGroupCommander("imperial_escort_ambush", "French_Ambush_Captain1");
			}
			else Group_SetGroupCommander("imperial_escort_ambush", "French_Ambush_Captain2");
			characters[GetCharacterIndex("French_Ambush_Captain1")].nosurrender = 2;
			characters[GetCharacterIndex("French_Ambush_Captain2")].nosurrender = 2;
			Group_SetAddress("imperial_escort_ambush", PChar.quest.imperial_escort_battle_location, "Quest_ships", "Quest_Ship_1");
			Group_SetTaskAttack("imperial_escort_ambush",  PLAYER_GROUP, true);
			Group_SetPursuitGroup("imperial_escort_ambush", PLAYER_GROUP);
			Group_LockTask("imperial_escort_ambush"); 
			Sea_LoginGroupNow("imperial_escort_ambush");
			PChar.quest.imperial_escort_battle.win_condition.l1 = "location";
			PChar.quest.imperial_escort_battle.win_condition.l1.location = PChar.quest.imperial_escort_battle_location;
			PChar.quest.imperial_escort_battle.win_condition = "imperial_escort_battle";
		break;

		case "imperial_escort_hisp_battle_setup":
			PChar.quest.imperial_escort_mona_battle_setup.over = "yes";
			i = Group_FindGroup("imperial_escort_ambush");
			if (i >= 0) Group_DeleteGroupIndex(i);
			PChar.quest.imperial_escort_ambush_commander = "";
			if (CheckAttribute(PChar, "quest.imperial_escort.French_Ambush_Captain4_assigned") && !LAi_IsDead(characterfromID("French_Ambush_Captain4")))
			{
				Group_AddCharacter("imperial_escort_ambush", "French_Ambush_Captain4");
				PChar.quest.imperial_escort_ambush_commander = "French_Ambush_Captain4";
			}
			for (n=3; n>1; n--)
			{
				temp = "French_Ambush_Captain" + n;
				if (!LAi_IsDead(characterfromID(temp)))
				{
					Group_AddCharacter("imperial_escort_ambush", temp);
					PChar.quest.imperial_escort_ambush_commander = temp;
				}
			}
			if (CheckAttribute(PChar, "quest.imperial_escort.French_Ambush_Captain1_assigned") && !LAi_IsDead(characterfromID("French_Ambush_Captain1")))
			{
				Group_AddCharacter("imperial_escort_ambush", "French_Ambush_Captain1");
				PChar.quest.imperial_escort_ambush_commander = "French_Ambush_Captain1";
			}

			if(PChar.quest.imperial_escort_ambush_commander != "")
			{
				bQuestDisableMapEnter = true;
				PChar.quest.imperial_escort_battle_location = PChar.location;
//				Island_SetReloadEnableGlobal(PChar.quest.imperial_escort_battle_location, false);
//				LAi_SetImmortal(characterFromID("Imperial_Captain"), false);
				Group_SetGroupCommander("imperial_escort_ambush", PChar.quest.imperial_escort_ambush_commander);
				Characters[GetCharacterIndex(PChar.quest.imperial_escort_ambush_commander)].nosurrender = 2;
				Group_SetTaskAttack("imperial_escort_ambush",  PLAYER_GROUP, true);
				Group_SetPursuitGroup("imperial_escort_ambush", PLAYER_GROUP);
				Group_LockTask("imperial_escort_ambush");
				Group_SetAddress("imperial_escort_ambush", PChar.quest.imperial_escort_battle_location, "Quest_ships", "Quest_Ship_1"); 
				Sea_LoginGroupNow("imperial_escort_ambush");
				PChar.quest.imperial_escort_battle.win_condition.l1 = "location";
				PChar.quest.imperial_escort_battle.win_condition.l1.location = PChar.quest.imperial_escort_battle_location;
				PChar.quest.imperial_escort_battle.win_condition = "imperial_escort_battle";
			}
			else
			{
				i = Group_FindGroup("imperial_escort_ambush");
				if (i >= 0) Group_DeleteGroupIndex(i);
			}
		break;

		case "imperial_escort_battle":
			characters[GetCharacterIndex("French_Ambush_Captain1")].nosurrender = 2;
			if (CheckAttribute(PChar, "quest.imperial_escort.French_Ambush_Captain1_assigned") && !LAi_IsDead(characterfromID("French_Ambush_Captain1")))
			{
				characters[GetCharacterIndex("French_Ambush_Captain2")].nosurrender = 2;
				characters[GetCharacterIndex("French_Ambush_Captain3")].nosurrender = 2;
				characters[GetCharacterIndex("French_Ambush_Captain4")].nosurrender = 2;

				PChar.quest.imperial_escort_flagship_down.win_condition.l1 = "NPC_death";
				Pchar.quest.imperial_escort_flagship_down.win_condition.l1.character = "French_Ambush_Captain1";
				Pchar.quest.imperial_escort_flagship_down.win_condition = "imperial_escort_flagship_down";
			}
			else
			{
				DeleteAttribute(CharacterFromID("French_Ambush_Captain2"), "nosurrender");
				DeleteAttribute(CharacterFromID("French_Ambush_Captain3"), "nosurrender");
				DeleteAttribute(CharacterFromID("French_Ambush_Captain4"), "nosurrender");
			} 

			Characters[GetCharacterIndex("French_Ambush_Captain1")].recognized = true;
			Characters[GetCharacterIndex("French_Ambush_Captain2")].recognized = true;
			Characters[GetCharacterIndex("French_Ambush_Captain3")].recognized = true;
			Characters[GetCharacterIndex("French_Ambush_Captain4")].recognized = true;

			if (CheckAttribute(PChar, "quest.imperial_escort.French_Ambush_Captain1_assigned") && !LAi_IsDead(characterfromID("French_Ambush_Captain1")))
			{
				PChar.quest.imperial_escort_battle_over.win_condition.l1 = "NPC_death";
				Pchar.quest.imperial_escort_battle_over.win_condition.l1.character = "French_Ambush_Captain1";
			} 
			if (!LAi_IsDead(characterfromID("French_Ambush_Captain2")))
			{
				PChar.quest.imperial_escort_battle_over.win_condition.l2 = "NPC_death";
				Pchar.quest.imperial_escort_battle_over.win_condition.l2.character = "French_Ambush_Captain2";
			}
			if (!LAi_IsDead(characterfromID("French_Ambush_Captain3")))
			{
				PChar.quest.imperial_escort_battle_over.win_condition.l3 = "NPC_death";
				Pchar.quest.imperial_escort_battle_over.win_condition.l3.character = "French_Ambush_Captain3";
			}
			if (CheckAttribute(PChar, "quest.imperial_escort.French_Ambush_Captain4_assigned") && !LAi_IsDead(characterfromID("French_Ambush_Captain4")))
			{
				PChar.quest.imperial_escort_battle_over.win_condition.l4 = "NPC_death";
				Pchar.quest.imperial_escort_battle_over.win_condition.l4.character = "French_Ambush_Captain4";
			} 
			pchar.quest.imperial_escort_battle_over.win_condition.l5 = "SeaEnter";
			Pchar.quest.imperial_escort_battle_over.win_condition = "imperial_escort_battle_over";
		break;

		case "imperial_escort_flagship_down":
			if (!LAi_IsDead(characterfromID("French_Ambush_Captain2"))) DeleteAttribute(&characters[GetCharacterIndex("French_Ambush_Captain2")], "nosurrender");
			if (!LAi_IsDead(characterfromID("French_Ambush_Captain3"))) DeleteAttribute(&characters[GetCharacterIndex("French_Ambush_Captain3")], "nosurrender"); 
			if (!LAi_IsDead(characterfromID("French_Ambush_Captain4"))) DeleteAttribute(&characters[GetCharacterIndex("French_Ambush_Captain4")], "nosurrender");
		break;

		case "imperial_escort_battle_over":
			AddQuestRecord("Imperial Escort", 5);
			bQuestDisableMapEnter = false;
//			Island_SetReloadEnableGlobal("IslaMona", true);
//			Island_SetReloadEnableGlobal("Hispaniola", true);

			PChar.quest.imperial_escort_santo_domingo_arrival.win_condition.l1 = "location";
			PChar.quest.imperial_escort_santo_domingo_arrival.win_condition.l1.location = "Santo_Domingo_port";
			PChar.quest.imperial_escort_santo_domingo_arrival.win_condition = "imperial_escort_Santo_Domingo_arrival";
		break;

		case "imperial_escort_battle_lost":
			Preprocessor_AddQuestData("ship", Characters[GetCharacterIndex("Imperial_Captain")].Ship.Name);
			AddQuestRecord("Imperial Escort", 4);
			Preprocessor_Remove("ship");
			PChar.quest.imperial_escort_mona_battle_setup.over = "yes";	// In case the galleon is sunk in battle before you reach Isla Mona
			PChar.quest.imperial_escort_hisp_battle_setup.over = "yes";	// In case the galleon is sunk in battle before you reach Hispaniola
			bQuestDisableMapEnter = false;
//			Island_SetReloadEnableGlobal("IslaMona", false);
//			Island_SetReloadEnableGlobal("Hispaniola", false);
			LAi_KillCharacter(characterfromID("Imperial_envoy"));
		break; 

		case "imperial_escort_bad_stuff":
			PChar.quest.imperial_escort_close_San_Juan_residence_approach.over = "yes";	// Only necessary in case "Imperial_envoy" manages to be killed by random thugs on the way to San Juan residence
			PChar.quest.imperial_escort_to_San_Juan_residence3.over = "yes";		//
			Locations[FindLocation("Muelle_town_04")].reload.l5.disable = 0;		//

			PChar.quest.imperial_escort_Santo_Domingo_attack.over = "yes"; 			// In case "Imperial_envoy" is killed by random thugs or assassins on the way to Santo Domingo residence
			PChar.quest.imperial_escort_to_Santo_Domingo_residence.over = "yes";		//
			Locations[FindLocation("Santo_Domingo_town")].reload.l4.disable = 0;		//

/*			if (PChar.location == "Isla Mona")
			{
				bQuestDisableMapEnter = false;
				Island_SetReloadEnableGlobal("IslaMona", false);
			}
			if (PChar.location == "Hispaniola")
			{
				bQuestDisableMapEnter = false;
				Island_SetReloadEnableGlobal("Hispaniola", false);
			} */

			if (PChar.location == Characters[GetCharacterIndex("Imperial_Captain")].location && !LAi_IsDead(characterFromID("Imperial_Captain")))
			{
				StartQuestMovie(true, true, false);
				DisableFastTravel(true);
				LAi_SetImmortal(CharacterFromID("Imperial_Captain"), false);
				LAi_SetActorType(characterFromID("Imperial_Captain"));
				LAi_ActorAttack(characterfromID("Imperial_Captain"), PChar, "");
				PChar.quest.imperial_escort_bad_stuff_captain_dead.win_condition.l1 = "NPC_death";
				PChar.quest.imperial_escort_bad_stuff_captain_dead.win_condition.l1.character = "Imperial_Captain";
				PChar.quest.imperial_escort_bad_stuff_captain_dead.win_condition = "imperial_escort_bad_stuff_captain_dead";
			}

			SetRMRelation(PChar, SPAIN, REL_WAR);
			ChangeCharacterReputation(PChar, -10);
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 33);
			Preprocessor_Remove("envoy");

			PChar.quest.imperial_escort_bad_stuff_arrest1.win_condition.l1 = "location";
			PChar.quest.imperial_escort_bad_stuff_arrest1.win_condition.l1.location = "Cuba_port";
			PChar.quest.imperial_escort_bad_stuff_arrest1.win_condition = "imperial_escort_bad_stuff_arrest1";

			PChar.quest.imperial_escort_bad_stuff_arrest2.win_condition.l1 = "location";
			PChar.quest.imperial_escort_bad_stuff_arrest2.win_condition.l1.location = "Santiago_port";
			PChar.quest.imperial_escort_bad_stuff_arrest2.win_condition = "imperial_escort_bad_stuff_arrest2";

			PChar.quest.imperial_escort_bad_stuff_arrest3.win_condition.l1 = "location";
			PChar.quest.imperial_escort_bad_stuff_arrest3.win_condition.l1.location = "Muelle_port";
			PChar.quest.imperial_escort_bad_stuff_arrest3.win_condition = "imperial_escort_bad_stuff_arrest3";

			PChar.quest.imperial_escort_bad_stuff_arrest4.win_condition.l1 = "location";
			PChar.quest.imperial_escort_bad_stuff_arrest4.win_condition.l1.location = "Santo_Domingo_port";
			PChar.quest.imperial_escort_bad_stuff_arrest4.win_condition = "imperial_escort_bad_stuff_arrest4";

			PChar.quest.imperial_escort_bad_stuff_arrest4.win_condition.l1 = "location";
			PChar.quest.imperial_escort_bad_stuff_arrest4.win_condition.l1.location = "Cartagena_port";
			PChar.quest.imperial_escort_bad_stuff_arrest4.win_condition = "imperial_escort_bad_stuff_arrest4";
		break;

		case "imperial_escort_bad_stuff_captain_dead":
			DisableFastTravel(false);
			EndQuestMovie();
		break;

		case "imperial_escort_bad_stuff_arrest1":
			PChar.quest.arresters_location = "Cuba_port";
			PChar.quest.arresters_group = "goto";
			PChar.quest.arresters_locator = "goto_16";
			LAi_QuestDelay("imperial_escort_bad_stuff_arrested", 0.1);
		break;

		case "imperial_escort_bad_stuff_arrest2":
			PChar.quest.arresters_location = "Santiago_port";
			PChar.quest.arresters_group = "goto";
			PChar.quest.arresters_locator = "goto24";
			LAi_QuestDelay("imperial_escort_bad_stuff_arrested", 0.1);
		break;

		case "imperial_escort_bad_stuff_arrest3":
			PChar.quest.arresters_location = "Muelle_port";
			PChar.quest.arresters_group = "reload";
			PChar.quest.arresters_locator = "reload2";
			LAi_QuestDelay("imperial_escort_bad_stuff_arrested", 0.1);
		break;

		case "imperial_escort_bad_stuff_arrest4":
			PChar.quest.arresters_location = "Santo_Domingo_port";
			PChar.quest.arresters_group = "goto";
			PChar.quest.arresters_locator = "goto12";
			LAi_QuestDelay("imperial_escort_bad_stuff_arrested", 0.1);
		break;

		case "imperial_escort_bad_stuff_arrest5":
			PChar.quest.arresters_location = "Cartagena_port";
			PChar.quest.arresters_group = "reload";
			PChar.quest.arresters_locator = "reload2";
			LAi_QuestDelay("imperial_escort_bad_stuff_arrested", 0.1);
		break;

		case "imperial_escort_bad_stuff_arrested":
			PChar.quest.imperial_escort_bad_stuff_arrest1.over = "yes";
			PChar.quest.imperial_escort_bad_stuff_arrest2.over = "yes";
			PChar.quest.imperial_escort_bad_stuff_arrest3.over = "yes";
			PChar.quest.imperial_escort_bad_stuff_arrest4.over = "yes";
			PChar.quest.imperial_escort_bad_stuff_arrest5.over = "yes";
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			for (n=1; n<7; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[SPAIN].fantomModel.(temp), PChar.quest.arresters_group, PChar.quest.arresters_locator);
				LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
				GiveSoldierWeapon(sld, SPAIN);
				sld.id = "soldier" + n;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
				LAi_SetActorType(sld);
				LAi_ActorFollow(sld, PChar, "", 60.0);
			}
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[SPAIN].fantomModel.m0, PChar.quest.arresters_group, PChar.quest.arresters_locator);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			GiveSoldierWeapon(sld, SPAIN);
			sld.id = "soldier" + n;
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
			sld.Dialog.Filename = "guard_dialog.c";
			sld.dialog.CurrentNode = "imperial_escort_arrest";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld,PChar,"imperial_escort_bad_stuff_arrested2",60.0,60.0);
		break;

		case "imperial_escort_bad_stuff_arrested2":
			DisableFastTravel(true);
			Locations[FindLocation("Havana_prison")].vcskip = true;
			Locations[FindLocation("Havana_prison")].models.always.locators = "Pri_l_GR";
			Locations[FindLocation("Havana_prison")].locators_radius.goto.goto26 = 1.5;
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard1"), "Havana_prison", "goto", "goto14");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard2"), "Havana_prison", "goto", "goto16");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard3"), "Havana_prison", "goto", "goto17");
			LAi_SetGuardianType(characterfromID("Spanish_guard1"));
			LAi_SetGuardianType(characterfromID("Spanish_guard2"));
			LAi_SetGuardianType(characterfromID("Spanish_guard3"));
			PChar.quest.old_blade = GetCharacterEquipByGroup(PChar, BLADE_ITEM_TYPE);
			PChar.quest.old_gun = GetCharacterEquipByGroup(PChar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(PChar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(PChar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			TempRemoveItems(PChar);
			DoQuestReloadToLocation("Havana_prison", "goto", "goto24", "imperial_escort_bad_stuff_in_jail");
		break;

		case "imperial_escort_bad_stuff_in_jail":
			if(IsOfficer(romance) || IsCompanion(romance))
			{
				PChar.quest.rescuer = PChar.quest.romance;
				SetCharacterRemovable(romance, false);
				StoreDialog(romance);
				romance.dialog.Filename = "romance_dialog.c";
			}
			else PChar.quest.rescuer = "Grigorio Formoselle";
// PChar.quest.rescuer = "Grigorio Formoselle";	// for testing
			StorePassengers(PChar.id);
			if (LAi_IsDead(characterfromID("Imperial_envoy")))
			{
				ChangeCharacterAddressGroup(characterfromID("Jusepe Guimaraes"), "Havana_prison", "officers", "reload1_1");
				LAi_SetActorType(characterfromID("Jusepe Guimaraes"));
				LAi_ActorGoToLocator(characterfromID("Jusepe Guimaraes"), "reload", "reload12", "imperial_escort_sentenced_to_death", 30.0);
			}
			if (CheckQuestAttribute("imperial_escort.status", "envoy taken") || CheckQuestAttribute("imperial_escort.status", "ship_missing"))
			{
				if (CheckQuestAttribute("imperial_escort.status", "envoy taken"))
				{
					Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
					Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
					AddQuestRecord("Imperial Escort", 10);
					Preprocessor_Remove("admiral");
					Preprocessor_Remove("envoy");
					SetCharacterRemovable(CharacterFromID("Imperial_Captain"), true);
					RemoveCharacterCompanion(PChar, CharacterFromID("Imperial_Captain"));
					ChangeCharacterAddressGroup(CharacterFromID("Imperial_Captain"), "Havana_prison", "goto", "goto10");
					LAi_SetCitizenType(CharacterFromID("Imperial_Captain"));
					SetCharacterShipLocation(CharacterFromID("Imperial_Captain"), "Cuba_port");
				}
				else
				{
					Preprocessor_AddQuestData("ship", PChar.quest.imperial_escort.ship_name);
					Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
					Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
					AddQuestRecord("Imperial Escort", 9);
					Preprocessor_Remove("admiral");
					Preprocessor_Remove("envoy");
					Preprocessor_Remove("ship");
				}
				NPChar = CharacterFromID("Warden");
				if (NPChar.location == "Havana_prison" && !LAi_IsDead(NPChar)) LAi_fade("", "imperial_escort_warden_reunion");
				else LAi_Fade("imperial_escort_time_in_jail", "imperial_escort_admiral_arrives");
			}
		break;

		case "imperial_escort_time_in_jail":
			WaitDate("", 0, 0, 1 + rand(3), 0, 0);
			SetCurrentTime(10, 10);
		break;

		case "imperial_escort_admiral_arrives":
			ChangeCharacterAddressGroup(characterfromID("Jusepe Guimaraes"), "Havana_prison", "officers", "reload1_1");
			LAi_SetActorType(characterfromID("Jusepe Guimaraes"));
			LAi_ActorGoToLocator(characterfromID("Jusepe Guimaraes"), "reload", "reload12", "imperial_escort_new_evidence", 30.0);
		break;

		case "imperial_escort_sentenced_to_death":
			LAi_SetActorType(characterfromID("Jusepe Guimaraes"));
			LAi_ActorTurnToCharacter(CharacterfromID("Jusepe Guimaraes"), (Pchar));
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_execution";
			LAi_ActorDialog(CharacterfromID("Jusepe Guimaraes"),PChar,"hung at dawn",5.0,5.0);
		break;

		case "imperial_escort_Santo_Domingo_arrival":
			bQuestDisableMapEnter = false;
			bQuestDisableSeaEnter = true;
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_Captain"), "Santo_Domingo_port", "goto", "goto20");
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_envoy"), "Santo_Domingo_port", "goto", "goto21");
			LAi_group_MoveCharacter(CharacterFromID("Imperial_Captain"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(CharacterFromID("Imperial_envoy"), LAI_GROUP_PLAYER);
			LAi_SetActorType(CharacterFromID("Imperial_Captain"));
			LAi_ActorFollowEverywhere(CharacterFromID("Imperial_Captain"), "", 10.0);
			LAi_SetActorType(CharacterFromID("Imperial_envoy"));
			LAi_ActorFollowEverywhere(CharacterFromID("Imperial_envoy"), "", 10.0);
			Locations[FindLocation("Santo_Domingo_town")].locators_radius.reload.reload27 = 5.0;
			Locations[FindLocation("Santo_Domingo_town")].reload.l4.disable = 1;
			Locations[FindLocation("Santo_Domingo_town")].locators_radius.goto.goto10 = 9.0;

			PChar.quest.imperial_escort_Santo_Domingo_attack_setup.win_condition.l1 = "location";
			PChar.quest.imperial_escort_Santo_Domingo_attack_setup.win_condition.l1.location = "Santo_Domingo_town";
			PChar.quest.imperial_escort_Santo_Domingo_attack_setup.win_condition = "imperial_escort_Santo_Domingo_attack_setup";
		break;

		case "imperial_escort_Santo_Domingo_attack_setup":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			for (n=1; n<5; n++)
			{
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.5, GetRandomModelForType(true, "Outlaws"), "reload", "reload6");
				LAi_group_MoveCharacter(sld, LAI_GROUP_MONSTERS);
				sld.id = "Assassin" + n;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
			}
			LAi_SetOfficerType(characterFromID("Imperial_Captain"));
			LAi_SetImmortal(characterFromID("Imperial_Captain"), true);
			LAi_SetHP(characterFromID("Imperial_envoy"), 500.0, 500.0);
			Pchar.quest.imperial_escort_Santo_Domingo_attack.win_condition.l1 = "locator";
			Pchar.quest.imperial_escort_Santo_Domingo_attack.win_condition.l1.location = "Santo_Domingo_town";
			Pchar.quest.imperial_escort_Santo_Domingo_attack.win_condition.l1.locator_group = "goto";
			Pchar.quest.imperial_escort_Santo_Domingo_attack.win_condition.l1.locator = "goto10";
			Pchar.quest.imperial_escort_Santo_Domingo_attack.win_condition = "imperial_escort_Santo_Domingo_attack";
		break;

		case "imperial_escort_Santo_Domingo_attack":
			Locations[FindLocation("Santo_Domingo_town")].locators_radius.goto.goto10 = 1.0;
			LAi_group_SetRelation(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_MONSTERS, "imperial_escort_Santo_Domingo_attack_defeated");
			Characters[GetCharacterIndex("Jaime Lezcano")].model.animation = "Rousselet";
			LAi_QuestDelay("imperial_escort_agent_attacks", 5.0);
		break;

		case "imperial_escort_Santo_Domingo_attack_defeated":
			switch(GetAttribute(PChar, "quest.imperial_escort.status"))
			{
				case "envoy taken":
					LAi_SetFightMode(PChar, false);
					LAi_LocationFightDisable(&Locations[FindLocation("Santo_Domingo_town")], true);
					LAi_SetActorType(CharacterFromID("Imperial_Captain"));
					Characters[GetCharacterIndex("Imperial_Captain")].dialog.CurrentNode = "envoy_taken";
					LAi_ActorDialog(CharacterfromID("Imperial_Captain"),PChar,"imperial_escort_captain_follows",5.0,5.0);
				break;

				case "envoy_safe":
					LAi_SetFightMode(PChar, false);
					LAi_LocationFightDisable(&Locations[FindLocation("Santo_Domingo_town")], true);
					LAi_SetActorType(CharacterFromID("Imperial_Captain"));
					Characters[GetCharacterIndex("Imperial_Captain")].dialog.CurrentNode = "envoy_safe";
					LAi_ActorDialog(CharacterfromID("Imperial_Captain"),PChar,"",5.0,5.0);	// Exits to "imperial_escort_Santo_Domingo_residence_approach"
				break;

				if(Characters[GetCharacterIndex("Jaime Lezcano")].location == PChar.location)
				{
					LAi_SetImmortal(characterFromID("Jaime Lezcano"), false);
					LAi_SetImmortal(characterFromID("Imperial_envoy"), false);
					LAi_SetActorType(CharacterFromID("Imperial_Captain"));
					LAi_ActorAttack(characterfromID("Imperial_Captain"), CharacterFromID("Jaime Lezcano"), "");
					LAi_SetCheckMinHP(characterFromID("Jaime Lezcano"), LAi_GetCharacterHP(characterFromID("Jaime Lezcano"))-2, false, "imperial_escort_agent_flees");
				}
				else
				{
					LAi_SetOfficerType(characterFromID("Imperial_Captain"));
//					LAi_SetImmortal(characterFromID("Imperial_Captain"), false);
				}
				PChar.quest.imperial_escort.status = "attack defeated";
			}
		break;

		case "imperial_escort_captain_back":
			LAi_LocationFightDisable(&Locations[FindLocation("Santo_Domingo_town")], false);
			LAi_SetOfficerType(characterFromID("Imperial_Captain"));
			LAi_SetImmortal(characterFromID("Imperial_Captain"), false);
		break;

		case "imperial_escort_captain_follows":
			LAi_LocationFightDisable(&Locations[FindLocation("Santo_Domingo_town")], false);
			LAi_SetActorType(CharacterFromID("Imperial_Captain"));
			LAi_ActorFollowEverywhere(CharacterFromID("Imperial_Captain"), "", 10.0);
		break;

		case "imperial_escort_agent_attacks":
			LAi_SetImmortal(characterFromID("Jaime Lezcano"), true);
			LAi_SetImmortal(characterFromID("Imperial_envoy"), true);
			ChangeCharacterAddressGroup(characterfromID("Jaime Lezcano"), "Santo_Domingo_town", "officers", "reload1_2");
			LAi_SetHP(characterFromID("Jaime Lezcano"), 500.0, 500.0);
			GiveItem2Character(CharacterFromID("Jaime Lezcano"), "bladeclub");
			EquipCharacterByItem(CharacterFromID("Jaime Lezcano"), "bladeclub");
			GiveItem2Character(CharacterFromID("Imperial_envoy"), "blade37");	// or "bladeX4", which is fists, which often stuns the agent
			EquipCharacterByItem(CharacterFromID("Imperial_envoy"), "blade37");
			LAi_SetActorTypeNoGroup(CharacterFromID("Imperial_envoy"));
			LAi_SetActorTypeNoGroup(CharacterFromID("Jaime Lezcano"));
			LAi_ActorFollow(CharacterFromID("Jaime Lezcano"), characterFromID("Imperial_envoy"), "imperial_escort_agent_attacks2", 10.0);
		break;

		case "imperial_escort_agent_attacks2":
			LAi_group_MoveCharacter(characterfromID("Jaime Lezcano"), "Imperial_Escort_Agent");
			LAi_ActorAttack(characterfromID("Jaime Lezcano"), CharacterFromID("Imperial_envoy"), "");
			PlaySound("VOICE\ENGLISH\Dut_f_a_009.wav");
			LAi_QuestDelay("imperial_escort_envoy_defends", 0.0);
		break;

		case "imperial_escort_envoy_defends":
			LAi_SetActorTypeNoGroup(CharacterFromID("Imperial_envoy"));
			LAi_ActorAttack(characterfromID("Imperial_envoy"), CharacterFromID("Jaime Lezcano"), "");
			LAi_QuestDelay("imperial_escort_agent_attack_resolved", 5.0);
		break;

		case "imperial_escort_agent_attack_resolved":
			if(rand(9) == 0) LAi_QuestDelay("imperial_escort_agent_flees", 0.0);
			else LAi_QuestDelay("imperial_escort_envoy_taken", 0.0);
		break;

		case "imperial_escort_envoy_taken":
			LAi_SetImmortal(characterFromID("Jaime Lezcano"), false);
			LAi_SetImmortal(characterFromID("Imperial_envoy"), false);
			LAi_SetActorTypeNoGroup(CharacterFromID("Imperial_envoy"));
			LAi_SetActorTypeNoGroup(CharacterFromID("Jaime Lezcano"));
			LAi_SetCheckMinHP(characterFromID("Jaime Lezcano"), LAi_GetCharacterHP(characterFromID("Jaime Lezcano"))-2, false, "imperial_escort_agent_flees");
			LAi_ActorGoToLocator(characterfromID("Imperial_envoy"), "reload", "reload1", "", 75.0);
            		LAi_ActorGoToLocation(CharacterFromID("Jaime Lezcano"), "reload", "reload1", "None", "", "", "imperial_escort_envoy_taken2", 45.0);
		break;

		case "imperial_escort_envoy_taken2":
			ChangeCharacterAddress(CharacterFromID("Imperial_envoy"), "None", "");
			LAi_SetStayType(CharacterFromID("Imperial_envoy"));
			if(CheckQuestAttribute("imperial_escort.status", "attack defeated"))
			{
				LAi_SetFightMode(PChar, false);
				LAi_LocationFightDisable(&Locations[FindLocation("Santo_Domingo_town")], true);
				LAi_SetActorType(CharacterFromID("Imperial_Captain"));
				Characters[GetCharacterIndex("Imperial_Captain")].dialog.CurrentNode = "envoy_taken";
				LAi_ActorDialog(CharacterfromID("Imperial_Captain"),PChar,"imperial_escort_captain_follows",5.0,5.0);
			}
			PChar.quest.imperial_escort.status = "envoy taken";
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_envoy_taken";
			EndQuestMovie();
			DisableFastTravel(false);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 2500);
				AddPartyExpChar(PChar, "", 1250);
				AddPartyExpChar(PChar, "Sneak", 1250);
			}
			else {AddPartyExp(PChar, 5000);}

			bQuestDisableSeaEnter = false;
			Locations[FindLocation("Santo_Domingo_town")].locators_radius.reload.reload27 = 1.0;
			Locations[FindLocation("Santo_Domingo_town")].reload.l4.disable = 0;
		break;

		case "imperial_escort_agent_flees":
//			LAi_RemoveCheckMinHP(CharacterFromID("Imperial_envoy"));
			LAi_RemoveCheckMinHP(CharacterFromID("Jaime Lezcano"));
			LAi_SetImmortal(characterFromID("Jaime Lezcano"), false);
			LAi_SetImmortal(characterFromID("Imperial_envoy"), false);
			LAi_SetActorTypeNoGroup(CharacterFromID("Imperial_envoy"));
			LAi_ActorFollowEverywhere(CharacterFromID("Imperial_envoy"), "", 10.0);
			if(CheckQuestAttribute("imperial_escort.status", "attack defeated"))
			{
				LAi_SetFightMode(PChar, false);
				LAi_LocationFightDisable(&Locations[FindLocation("Santo_Domingo_town")], true);
				LAi_SetActorType(CharacterFromID("Imperial_Captain"));
				Characters[GetCharacterIndex("Imperial_Captain")].dialog.CurrentNode = "envoy_safe";
				LAi_ActorDialog(CharacterfromID("Imperial_Captain"),PChar,"",5.0,5.0);	// Exits to "imperial_escort_Santo_Domingo_residence_approach"
			}
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			LAi_ActorAnimation(CharacterFromID("Jaime Lezcano"), "run", "imperial_escort_agent_flees2", 0.01);
//			LAi_QuestDelay("imperial_escort_agent_flees2", 0.0);
		break;

		case "imperial_escort_agent_flees2":
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			LAi_SetImmortal(characterFromID("Jaime Lezcano"), true);
            		LAi_ActorRunToLocation(CharacterFromID("Jaime Lezcano"), "reload", "reload1", "None", "", "", "", 60.0);
			PChar.quest.imperial_escort.status = "envoy_safe";
		break;

		case "imperial_escort_Santo_Domingo_residence_approach":
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 7);
			Preprocessor_Remove("envoy");
			LAi_LocationFightDisable(&Locations[FindLocation("Santo_Domingo_town")], false);
			if(!LAi_IsDead(CharacterFromID("Imperial_envoy")))
			{
				LAi_SetActorType(CharacterFromID("Imperial_Captain"));
				LAi_ActorFollowEverywhere(CharacterFromID("Imperial_Captain"), "", 10.0);
				LAi_SetActorType(CharacterFromID("Imperial_envoy"));
				LAi_ActorFollowEverywhere(CharacterFromID("Imperial_envoy"), "", 10.0);

				PChar.quest.imperial_escort_to_Santo_Domingo_residence.win_condition.l1 = "locator";
				PChar.quest.imperial_escort_to_Santo_Domingo_residence.win_condition.l1.location = "Santo_Domingo_town";
				PChar.quest.imperial_escort_to_Santo_Domingo_residence.win_condition.l1.locator_group = "reload";
				PChar.quest.imperial_escort_to_Santo_Domingo_residence.win_condition.l1.locator = "reload27";
				PChar.quest.imperial_escort_to_Santo_Domingo_residence.win_condition = "imperial_escort_to_Santo_Domingo_residence";
			}
			else
			{
				EndQuestMovie();
				DisableFastTravel(false);
			}
		break;

		case "imperial_escort_to_Santo_Domingo_residence":
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Santo_Domingo_town")], true);
			Locations[FindLocation("Santo_Domingo_town")].locators_radius.reload.reload27 = 1.0;
			LAi_SetActorType(characterFromID("Imperial_envoy"));
			Characters[GetCharacterIndex("Imperial_envoy")].Dialog.CurrentNode = "Santo_Domingo_residence_safe";
			LAi_ActorDialog(characterfromID("Imperial_envoy"), PChar, "imperial_escort_to_Santo_Domingo_residence2", 5.0, 5.0);
		break;

		case "imperial_escort_to_Santo_Domingo_residence2":
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			Characters[GetCharacterIndex("Imperial_Captain")].Dialog.CurrentNode = "Santo_Domingo_residence_arrived";
			LAi_ActorDialog(characterfromID("Imperial_Captain"), PChar, "imperial_escort_to_Santo_Domingo_residence3", 5.0, 5.0);
		break;

		case "imperial_escort_to_Santo_Domingo_residence3":
			LAi_SetActorType(characterFromID("Imperial_envoy"));
			Characters[GetCharacterIndex("Imperial_envoy")].Dialog.CurrentNode = "Santo_Domingo_residence_safe2";
			LAi_ActorDialog(characterfromID("Imperial_envoy"), PChar, "imperial_escort_to_Santo_Domingo_residence4", 5.0, 5.0);
		break;

		case "imperial_escort_to_Santo_Domingo_residence4":
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			Characters[GetCharacterIndex("Imperial_Captain")].Dialog.CurrentNode = "Santo_Domingo_residence_arrived2";
			LAi_ActorDialog(characterfromID("Imperial_Captain"), PChar, "imperial_escort_Santo_Domingo_residence_arrived", 5.0, 5.0);
		break;

		case "imperial_escort_Santo_Domingo_residence_arrived":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 5000);
				AddPartyExpChar(PChar, "", 2500);
				AddPartyExpChar(PChar, "Sneak", 2500);
			}
			else {AddPartyExp(PChar, 10000);}
			LAi_LocationFightDisable(&Locations[FindLocation("Santo_Domingo_town")], false);
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_SetActorType(characterFromID("Imperial_Captain"));
			LAi_SetActorType(characterFromID("Imperial_envoy"));
            		LAi_ActorGoToLocation(characterFromID("Imperial_Captain"), "reload", "reload27", "None", "", "", "", 10.0);
            		LAi_ActorGoToLocation(characterFromID("Imperial_envoy"), "reload", "reload27", "None", "", "", "", 10.0);

			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			Preprocessor_AddQuestData("day", GetHumanDate(GetAddingDataYear(0, 0, 2), GetAddingDataMonth(0, 0, 2), GetAddingDataDay(0, 0, 2)));
			AddQuestRecord("Imperial Escort", 51);
			Preprocessor_Remove("day");
			Preprocessor_Remove("envoy");

			PChar.quest.imperial_escort_ship_disappears.win_condition.l1 = "Timer";
			PChar.quest.imperial_escort_ship_disappears.win_condition.l1.date.day = GetAddingDataDay(0, 0, 2);
			PChar.quest.imperial_escort_ship_disappears.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2);
			PChar.quest.imperial_escort_ship_disappears.win_condition.l1.date.year = GetAddingDataYear(0, 0, 2);
			PChar.quest.imperial_escort_ship_disappears.win_condition = "imperial_escort_ship_disappears";
		break;

		case "imperial_escort_ship_disappears":
			Preprocessor_AddQuestData("captain", GetMyLastName(CharacterFromID("Imperial_Captain")));
			AddQuestRecord("Imperial Escort", 52);
			Preprocessor_Remove("captain");
			PChar.quest.imperial_escort.shiptype = GetCharacterShipModel(CharacterfromID("Imperial_Captain"));
			PChar.quest.imperial_escort.shipname = Characters[GetCharacterIndex("Imperial_Captain")].Ship.Name;
			PChar.quest.imperial_escort.shipcabin = GetCharacterShipCabin(CharacterfromID("Imperial_Captain"));
			SetCharacterRemovable(CharacterFromID("Imperial_Captain"), true);
			RemoveCharacterCompanion(PChar, CharacterFromID("Imperial_Captain"));
			ExchangeCharacterShip(CharacterFromID("Imperial_Captain"), CharacterFromID("Pelayo Nunez"));
//			setCharacterShipLocation(CharacterFromID("Pelayo Nunez"), "Cuba_Shore_06");
			LAi_type_actor_Reset(CharacterFromID("Imperial_Captain"));
			LAi_type_actor_Reset(CharacterFromID("Imperial_envoy"));
			ChangeCharacterAddress(CharacterFromID("Imperial_Captain"), "None", "");
			SetCharacterShipLocation(CharacterFromID("Imperial_Captain"), "None");
			ChangeCharacterAddress(CharacterFromID("Imperial_envoy"), "None", "");
			PChar.quest.imperial_escort.status = "ship_missing";
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_ship_missing";
			PChar.quest.imperial_escort_ship_disappears2.win_condition.l1 = "location";
			PChar.quest.imperial_escort_ship_disappears2.win_condition.l1.location = "Santo_Domingo_port";
			PChar.quest.imperial_escort_ship_disappears2.win_condition = "imperial_escort_ship_disappears2";
		break;

		case "imperial_escort_ship_disappears2":
			Pchar.dialog.CurrentNode = "imperial_escort_ship_missing";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "imperial_escort_ship_disappears3");
		break;

		case "imperial_escort_ship_disappears3":
			Preprocessor_AddQuestData("ship", PChar.quest.imperial_escort.ship_name);
			AddQuestRecord("Imperial Escort", 8);
			Preprocessor_Remove("ship");
			Lai_SetPlayerType(PChar);
			bQuestDisableSeaEnter = false;
			Locations[FindLocation("Santo_Domingo_town")].locators_radius.reload.reload27 = 1.0;
			Locations[FindLocation("Santo_Domingo_town")].reload.l4.disable = 0;
		break;

		case "imperial_escort_warden_reunion":	// Triggered by prison sequence if warden is alive, and PChar.quest.imperial_escort.status is either "envoy taken" or "ship_missing"
			if (CheckAttribute(CharacterfromID("Warden"), "stuntime")) DeleteAttribute(CharacterfromID("Warden"), "stuntime");
			LAi_SetActorType(CharacterFromID("Warden"));
			LAi_ActorGoToLocator(CharacterfromID("Warden"), "reload", "reload12", "imperial_escort_warden_reunion2", 30.0);
		break;

		case "imperial_escort_warden_reunion2":
			LAi_ActorTurnToCharacter(CharacterFromID("Warden"), (Pchar));
			Characters[GetCharacterIndex("Warden")].Dialog.Filename = "Warden_dialog.c";
			Characters[GetCharacterIndex("Warden")].dialog.CurrentNode = "not_again";
			LAi_ActorDialogNow(CharacterFromID("Warden"),PChar,"imperial_escort_warden_leaves",1.0);
		break;

		case "imperial_escort_warden_leaves":
			LAi_SetActorType(characterfromID("Warden"));
			LAi_ActorGoToLocator(characterfromID("Warden"), "goto", "goto22", "imperial_escort_warden_leaves2", 10.0);
		break;

		case "imperial_escort_warden_leaves2":
//			LAi_SetCitizenType(CharacterFromID("Warden"));
			LAi_SetStunnedTypeNoGroup(characterFromID("Warden"));
			LAi_Fade("imperial_escort_time_in_jail", "imperial_escort_admiral_arrives");
		break;

		case "imperial_escort_new_evidence":	// Triggered by prison sequence if PChar.quest.imperial_escort.status is either "envoy taken" or "ship_missing"
			LAi_SetActorType(characterfromID("Jusepe Guimaraes"));
			LAi_ActorTurnToCharacter(CharacterfromID("Jusepe Guimaraes"), (Pchar));
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_development";
			LAi_ActorDialogNow(CharacterFromID("Jusepe Guimaraes"), PChar, "imperial_escort_admiral_leaves", 1.0);
		break;

		case "imperial_escort_admiral_leaves":
			LAi_SetActorType(characterfromID("Jusepe Guimaraes"));
			LAi_ActorGoToLocator(characterfromID("Jusepe Guimaraes"), "officers", "reload1_1", "imperial_escort_admiral_leaves2", 10.0);
		break;

		case "imperial_escort_admiral_leaves2":
			if(CheckAttribute(PChar, "land"))
			{
				makearef(PChar_land, PChar.land);
				// PChar.quest.imperial_escort.land = "";
				makearef(PChar_quest_land, PChar.quest.imperial_escort.land);
				CopyAttributes(PChar_quest_land, PChar_land);
			}
			PChar.quest.imperial_escort.old_spain_relation = GetRMRelation(PChar, SPAIN);
			PChar.quest.imperial_escort.old_spain_rank = GetRank(PChar, SPAIN);
			if(CheckAttribute(PChar, "knighted"))
			{
				PChar.quest.imperial_escort.old_knighted = PChar.knighted;
				PChar.quest.imperial_escort.old_title = PChar.title;
			}

			if(CheckAttribute(PChar, "quest.betrayed_spain") || CheckAttribute(PChar, "quest.betrayed_spain1"))
			{
				PChar.quest.betrayed_spain.over = "yes";
				PChar.quest.betrayed_spain1.over = "yes";
			}
			LeaveService(PChar, SPAIN, true);
			if (CheckQuestAttribute("background", "pirate")) HoistFlag(PIRATE);
			ChangeCharacterAddressGroup(characterfromID("Jusepe Guimaraes"), "Havana_House_03", "sit", "sit1");
			LAi_SetHuberType(characterfromID("Jusepe Guimaraes"));

			NPChar = CharacterFromID("Emiliano de Guzmán");
			ChangeCharacterAddress(CharacterFromID(Towns[GetTownIndex("Santiago")].gov), "none", "");
			ChangeCharacterAddressGroup(NPChar, "Santiago_townhall", "sit", "sit1");
			LAi_SetHuberType(NPChar);
			Towns[GetTownIndex("Santiago")].gov = "Emiliano de Guzmán";
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 1;	// Lock Santiago townhall so you can't face Emiliano de Guzmán until the right time

			LAi_Fade("imperial_escort_next_night_in_jail", "imperial_escort_rescuer_arrives");
		break;

		case "imperial_escort_next_night_in_jail":
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(23, rand(59));
		break;

		case "imperial_escort_rescuer_arrives":
			LAi_SetStunnedTypeNoGroup(characterFromID("Spanish_guard1"));
			LAi_SetStunnedTypeNoGroup(characterFromID("Spanish_guard2"));
			LAi_SetStunnedTypeNoGroup(characterFromID("Spanish_guard3"));
//			LAi_SetStunnedTypeNoGroup(characterFromID("Havana Prison Commandant"));
			LAi_SetActorType(characterFromID("Havana Prison Commandant"));
			LAi_ActorAnimation(characterFromID("Havana Prison Commandant"), "Lay_1", "", -1);
			NPChar = CharacterFromID(PChar.quest.rescuer);
			ChangeCharacterAddressGroup(NPChar, PChar.location, "officers", "reload1_1");
			LAi_SetImmortal(NPChar, true);		// Make sure rescuer survives walk through jungle and is available for explanation
			LAi_SetActorType(NPChar);
			LAi_ActorGoToLocator(NPChar, "reload", "reload12", "imperial_escort_rescued", 30.0);
		break;

		case "imperial_escort_rescued":
			NPChar = CharacterFromID(PChar.quest.rescuer);
			LAi_SetActorType(NPChar);
			LAi_ActorTurnToCharacter(NPChar, (PChar));
			NPChar.dialog.CurrentNode = "imperial_escort_jailbreak";
			LAi_ActorDialogNow(NPChar, PChar, "imperial_escort_rescued2", 1.0);
		break;

		case "imperial_escort_rescued2":
			PlaySound("PEOPLE\lockpick2.wav");
//			LAi_Fade("imperial_escort_rescued3", "imperial_escort_rescued4");
			LAi_QuestDelay("imperial_escort_rescued3", 1.0);
		break;

		case "imperial_escort_rescued3":
			ChangeCharacterAddressGroup(CharacterFromID(PChar.quest.rescuer), "Havana_prison", "goto", "goto23");
			DoQuestReloadToLocation("Havana_prison", "reload", "reload12", "imperial_escort_rescued4");
//			ChangeCharacterAddressGroup(PChar, "Havana_prison", "reload", "reload12");
		break;

		case "imperial_escort_rescued4":
			PChar.quest.imperial_escort_get_stuff.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_get_stuff.win_condition.l1.location = "Havana_prison";
			PChar.quest.imperial_escort_get_stuff.win_condition.l1.locator_group = "goto";
			PChar.quest.imperial_escort_get_stuff.win_condition.l1.locator = "goto26";
			PChar.quest.imperial_escort_get_stuff.win_condition = "guadeloupe_prison_out_of_cells";	// Re-use same code as Guadeloupe prison escape to return your equipment

			PChar.quest.imperial_escort_remind_stuff.win_condition.l1 = "location";
			PChar.quest.imperial_escort_remind_stuff.win_condition.l1.location = "Havana_town_05";
			Pchar.quest.imperial_escort_remind_stuff.win_condition = "imperial_escort_remind_stuff";

			LAi_QuestDelay("imperial_escort_reset_rescuer", 1.0);
		break;

		case "imperial_escort_remind_stuff":
			NPChar = CharacterFromID(PChar.quest.rescuer);
			LAi_SetActorType(NPChar);
			LAi_ActorTurnToCharacter(NPChar, (PChar));
			NPChar.dialog.CurrentNode = "imperial_escort_remind_stuff";
			LAi_ActorDialog(NPChar, PChar, "imperial_escort_reset_rescuer", 5.0, 5.0);	// Exits to "imperial_escort_ships_impounded" if you got your stuff or don't want it, otherwise just exits so you can go back and get it

			if(CheckAttribute(PChar, "quest.imperial_escort_get_stuff"))
			{
				PChar.quest.imperial_escort_rescued4.win_condition.l1 = "location";
				PChar.quest.imperial_escort_rescued4.win_condition.l1.location = "Havana_prison";
				Pchar.quest.imperial_escort_rescued4.win_condition = "imperial_escort_rescued4";
			}
		break;

		case "imperial_escort_reset_rescuer":
			NPChar = CharacterFromID(PChar.quest.rescuer);
			if(PChar.quest.rescuer == PChar.quest.romance)
			{
				SetOfficersIndex(PChar, 3, GetCharacterIndex(PChar.quest.rescuer));
				LAi_SetOfficerType(NPChar);
			}
			else
			{
				LAi_type_Actor_Reset(NPChar);
				LAi_ActorFollowEverywhere(NPChar, "", 5.0);
			}
		break;

		case "imperial_escort_ships_impounded":		// Triggered by dialog with rescuer
			PChar.quest.imperial_escort_get_stuff.over = "yes";
			PChar.quest.imperial_escort_rescued4.over = "yes";
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = 1;
			NPChar = CharacterFromID(PChar.quest.rescuer);
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "imperial_escort_ships_impounded";
			LAi_ActorDialog(NPChar, PChar, "imperial_escort_reset_rescuer", 5.0, 5.0);

			DisableFastTravel(true);
			bQuestDisableSeaEnter = true;
			Locations[FindLocation("Cuba_port")].reload.l2.disable = 1;
			Locations[FindLocation("Cuba_port")].reload.l3.disable = 1;
			Locations[FindLocation("Cuba_port")].reload.l4.disable = 1;
			Locations[FindLocation("Cuba_port")].reload.l5.disable = 1;

			PChar.quest.port_bad.win_condition.l1 = "location";
			PChar.quest.port_bad.win_condition.l1.location = "Cuba_port";
			PChar.quest.port_bad.win_condition = "port_bad";

			ChangeCharacterAddressGroup(characterfromID("Spanish_Captain1"), "Cuba_port", "goto", "goto_2");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard1"), "Cuba_port", "officers", "Door_1_1");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard2"), "Cuba_port", "officers", "Door_1_2");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard3"), "Cuba_port", "officers", "Door_1_3");

// Ships storage copied from case "mona_attack_detach_fleet2".  To restore, see case "mona_attack_rejoin_fleet2"
			PChar.quest.imperial_escort.original_fleet_size = GetCompanionQuantity(PChar);
			for (n=1; n<COMPANION_MAX; n++)
			{
				cc = GetCompanionIndex(PChar,n);
				temp = "companion" + n;
				if (cc > 0)
				{
					PChar.quest.imperial_escort.(temp) = characters[cc].id;
					if (HasSubStr(PChar.quest.imperial_escort.(temp), "Enc_Officer")) LAi_StoreFantom(CharacterFromId(PChar.quest.imperial_escort.(temp))); // Prevent character from being overwritten by another "Enc_Officer"
					RemoveCharacterCompanion(PChar, characters[cc]);
				}
				else PChar.quest.imperial_escort.(temp) = "*NULL*";
			}
			ExchangeCharacterShip(PChar, CharacterFromID("Grigorio Formoselle"));
			GiveShip2Character(PChar, "Barque1", "Mayordomo", -1, SPAIN, true, true);
			SetCharacterShipLocation(PChar, "Cuba_Shore_03");

			PChar.quest.imperial_escort_goto_beach.win_condition.l1 = "location";
			PChar.quest.imperial_escort_goto_beach.win_condition.l1.location = "Cuba_Shore_03";
			PChar.quest.imperial_escort_goto_beach.win_condition = "imperial_escort_goto_beach";
		break;

		case "imperial_escort_goto_beach":
			NPChar = CharacterFromID(PChar.quest.rescuer);
			if (NPChar.location != PChar.location) PlaceCharacter(NPChar, "goto");	// Just in case rescuer got lost along the way
			LAi_SetImmortal(NPChar, false);
			LAi_SetFightMode(PChar, false);
			LAi_SetActorType(PChar);
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, NPChar);
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "imperial_escort_explanation";
			LAi_ActorDialog(NPChar, PChar, "imperial_escort_borrow_ship", 5.0, 5.0);
		break;

		case "imperial_escort_borrow_ship":
			Preprocessor_AddQuestData("rescuer", GetMyFullName(CharacterFromID(PChar.quest.rescuer)));
			Preprocessor_AddQuestData("rescuer1", GetMyName(CharacterFromID(PChar.quest.rescuer)));
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 11);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("governor");
			Preprocessor_Remove("rescuer1");
			Preprocessor_Remove("rescuer");
			DisableFastTravel(false);
			bQuestDisableSeaEnter = false;
			LAi_SetPlayerType(PChar);
			NPChar = CharacterFromID(PChar.quest.rescuer);
			if(PChar.quest.rescuer == PChar.quest.romance)
			{
				SetCharacterRemovable(NPChar, true);
				SetOfficersIndex(PChar, 3, GetCharacterIndex(PChar.quest.rescuer));
				LAi_SetOfficerType(NPChar);
				RestoreDialog(NPChar);
			}
			else
			{
				LAi_SetActorType(NPChar);
          			LAi_ActorGoToLocation(NPChar, "reload", "reload2_back", "none", "", "", "", 120.0);
				Pchar.quest.imperial_escort_grigorio_home.win_condition.l1 = "ExitFromLocation";
				PChar.quest.imperial_escort_grigorio_home.win_condition.l1.location = PChar.location;
				Pchar.quest.imperial_escort_grigorio_home.win_condition = "imperial_escort_grigorio_home";
			}

			PChar.quest.port_bad.over = "yes";
			ChangeCharacterAddress(characterFromID("Spanish_Captain1"), "None", "");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard1"), "Havana_prison", "goto", "goto14");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard2"), "Havana_prison", "goto", "goto16");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard3"), "Havana_prison", "goto", "goto17");
			LAi_SetGuardianType(characterfromID("Spanish_guard1"));
			LAi_SetGuardianType(characterfromID("Spanish_guard2"));
			LAi_SetGuardianType(characterfromID("Spanish_guard3"));
			LAi_SetHuberType(characterfromID("Havana Prison Commandant"));
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = 0;
			Locations[FindLocation("Cuba_port")].reload.l2.disable = 0;
			Locations[FindLocation("Cuba_port")].reload.l3.disable = 0;
			Locations[FindLocation("Cuba_port")].reload.l4.disable = 0;
			Locations[FindLocation("Cuba_port")].reload.l5.disable = 0;

			ChangeCharacterAddressGroup(characterfromID("Garfield Leighton"), "Tortuga_Tavern", "goto", "goto6");
			LAi_group_MoveCharacter(characterfromID("Garfield Leighton"), "TORTUGA_CITIZENS");
			Characters[GetCharacterIndex("Garfield Leighton")].dialog.CurrentNode = "imperial_escort_meeting";
		break;

		case "imperial_escort_grigorio_home":
			ChangeCharacterAddressGroup(CharacterFromID("Grigorio Formoselle"), "Santiago_townhall", "goto", "goto10");
			LAi_SetGuardianTypeNoGroup(CharacterFromID("Grigorio Formoselle"));
		break;

		case "imperial_escort_visit_Tortuga_governor":		// Triggered by dialog with Garfield Leighton
			Preprocessor_AddQuestData("pirate", GetMyFullName(CharacterFromID("Garfield Leighton")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 12);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("pirate");
			PChar.quest.imperial_escort.status = "goto_tortuga";
			StoreDialog(CharacterFromID("Bertrand Ogeron"));
			characters[GetCharacterIndex("Bertrand Ogeron")].Dialog.Filename = "quest_Bertrand Ogeron_dialog.c";
			Pchar.quest.imperial_escort_remove_leighton.win_condition.l1 = "MapEnter";
			Pchar.quest.imperial_escort_remove_leighton.win_condition = "imperial_escort_remove_leighton";
		break;

		case "imperial_escort_remove_leighton":
			ChangeCharacterAddress(characterFromID("Garfield Leighton"), "None", "");
		break;

		case "imperial_escort_tortuga_tailor_setup":
			StoreDialog(CharacterFromID("Guy Lafleur"));
			characters[GetCharacterIndex("Guy Lafleur")].Dialog.Filename = "quest_Guy Lafleur_dialog.c";
			Pchar.quest.imperial_escort_restore_tortuga_tailor.win_condition.l1 = "MapEnter";
			Pchar.quest.imperial_escort_restore_tortuga_tailor.win_condition = "imperial_escort_restore_tortuga_tailor";
		break;

		case "imperial_escort_restore_tortuga_tailor":
			Pchar.quest.imperial_escort_restore_tortuga_tailor.over = "yes";	// restore quest not needed if triggered by dialog
			RestoreDialog(CharacterFromID("Guy Lafleur"));
		break;

		case "imperial_escort_visit_Port_au_Prince_governor":	// Triggered by dialog with Bertrand Ogeron
			if(GetRMRelation(PChar, FRANCE) > REL_WAR) AddQuestRecord("Imperial Escort", 13);
			else AddQuestRecord("Imperial Escort", 14);
			RestoreDialog(CharacterFromID("Bertrand Ogeron"));
			PChar.quest.imperial_escort.status = "goto_port_au_prince";
			StoreDialog(CharacterFromID("Isabelle de Cussy"));
			characters[GetCharacterIndex("Isabelle de Cussy")].Dialog.Filename = "quest_Isabelle de Cussy_dialog.c";
			PChar.quest.imperial_escort_PoP_townhall.win_condition.l1 = "location";
			PChar.quest.imperial_escort_PoP_townhall.win_condition.l1.location = "PoPrince_townhall";
			PChar.quest.imperial_escort_PoP_townhall.win_condition = "imperial_escort_PoP_townhall";
		break;

		case "imperial_escort_PoP_townhall":
			DisableFastTravel(true);
		break;

		case "imperial_escort_PoP_townhall_arrest":	// triggered by dialog with Isabelle de Cussy
			LAi_LocationFightDisable(&Locations[FindLocation("PoPrince_townhall")], false);
			Locations[FindLocation("PoPrince_townhall")].reload.l1.disable = 1;
			LAi_SetImmortal(characterFromID("Isabelle de Cussy"), true);
			LAi_SetImmortal(characterFromID("Contre-Amirale"), true);
			for (n=1; n<4; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.(temp), "reload", "reload1");
				LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
				GiveSoldierWeapon(sld, FRANCE);
				sld.id = "soldier" + n;
				sld.nation = FRANCE;
				SetRandomNameToCharacter(sld);
			}
			for (n=4; n<7; n++)
			{
				temp = "m" + (rand(5) + 1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[FRANCE].fantomModel.(temp), "reload", "reload2");
				LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
				GiveSoldierWeapon(sld, FRANCE);
				sld.id = "soldier" + n;
				sld.nation = FRANCE;
				SetRandomNameToCharacter(sld);
			}
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "imperial_escort_PoP_townhall_arrest_battle_won");
		break;

		case "imperial_escort_PoP_townhall_arrest_battle_won":
			Locations[FindLocation("PoPrince_townhall")].reload.l1.disable = 0;
//			PChar.quest.imperial_escort_PoP_townhall_arrest_escaped.over = "yes";
			LAi_LocationFightDisable(&Locations[FindLocation("PoPrince_townhall")], true);
			LAi_SetFightMode(PChar, false);
		break;

		case "imperial_escort_prepare_for_PoP_ambush":		// Triggered by dialog with Isabelle de Cussy
			Locations[FindLocation("PoPrince_town")].vcskip = true;
			DisableFastTravel(true);
			TakeItemFromCharacter(CharacterFromID("Jaime Lezcano"), "bladeclub");
			EquipCharacterByItem(CharacterFromID("Jaime Lezcano"), FindCharacterItemByGroup(CharacterFromID("Jaime Lezcano"), BLADE_ITEM_TYPE));
			EquipCharacterByItem(CharacterFromID("Jaime Lezcano"), FindCharacterItemByGroup(CharacterFromID("Jaime Lezcano"), GUN_ITEM_TYPE));
			PChar.quest.imperial_escort_setup_PoP_ambush.win_condition.l1 = "location";
			PChar.quest.imperial_escort_setup_PoP_ambush.win_condition.l1.location = "PoPrince_town";
			PChar.quest.imperial_escort_setup_PoP_ambush.win_condition = "imperial_escort_setup_PoP_ambush";

			PChar.quest.imperial_escort_reset_PoPrince_townhall.win_condition.l1 = "location";
			PChar.quest.imperial_escort_reset_PoPrince_townhall.win_condition.l1.location = "Hispaniola";
			PChar.quest.imperial_escort_reset_PoPrince_townhall.win_condition = "imperial_escort_reset_PoPrince_townhall";
		break;

		case "imperial_escort_reset_PoPrince_townhall":
//			Locations[FindLocation("PoPrince_town")].reload.l6.disable = 0;
			RestoreDialog(CharacterFromID("Isabelle de Cussy"));
		break;

		case "imperial_escort_setup_PoP_ambush":
			DeleteAttribute(&Locations[FindLocation("PoPrince_town")],"vcskip");
			StartQuestMovie(true, true, false);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.33, "capstan2", "goto", "goto26");
			LAi_group_MoveCharacter(sld, "Imperial_Escort_Agent");
			sld.id = "ie_thug1";
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.33, "bocman1", "goto", "goto5");
			LAi_group_MoveCharacter(sld, "Imperial_Escort_Agent");
			sld.id = "ie_thug2";
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 2, true, true, 0.33, "man1_1", "goto", "goto10");
			LAi_group_MoveCharacter(sld, "Imperial_Escort_Agent");
			sld.id = "ie_thug3";
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
/*			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.33, "50M5", "goto", "goto4");
			LAi_group_MoveCharacter(sld, "Imperial_Escort_Agent");
			sld.id = "ie_thug4";
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.33, "Black_Corsair", "officers", "reload12_3");
			LAi_group_MoveCharacter(sld, "Imperial_Escort_Agent");
			sld.id = "ie_thug5";
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.33, "pirat8", "officers", "reload4_1");
			LAi_group_MoveCharacter(sld, "Imperial_Escort_Agent");
			sld.id = "ie_thug6";
			sld.nation = SPAIN;
			SetRandomNameToCharacter(sld);
*/

			ChangeCharacterAddressGroup(characterfromID("Jaime Lezcano"), "PoPrince_town", "goto", "goto18");
			LAi_SetImmortal(CharacterFromID("Jaime Lezcano"), true);
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			Characters[GetCharacterIndex("Jaime Lezcano")].Dialog.CurrentNode = "imperial_escort_arrest1";
			LAi_ActorDialog(characterfromID("Jaime Lezcano"), PChar, "imperial_escort_PoP_ambush", 5.0, 5.0);
		break;

		case "imperial_escort_PoP_ambush":
//			for(n=1; n<7; n++)
			for(n=1; n<4; n++)
			{
				sld = CharacterFromID("ie_thug" + n);
				LAi_group_MoveCharacter(sld, "Imperial_Escort_Agent");
				attr = "l" + n;
				PChar.quest.imperial_escort_PoP_ambush_battle_won.win_condition.(attr) = "NPC_Death";
				PChar.quest.imperial_escort_PoP_ambush_battle_won.win_condition.(attr).character = "ie_thug" + n;
			}
			LAi_group_MoveCharacter(characterfromID("Jaime Lezcano"), "Imperial_Escort_Agent");
			LAi_group_SetRelation("Imperial_Escort_Agent", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("Imperial_Escort_Agent", LAI_GROUP_PLAYER, true);
//			LAi_group_SetCheck("Imperial_Escort_Agent", "imperial_escort_PoP_ambush_battle_won");
			PChar.quest.imperial_escort_PoP_ambush_battle_won.win_condition = "imperial_escort_PoP_ambush_battle_won";
		break;

		case "imperial_escort_PoP_ambush_battle_won":
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_LocationFightDisable(&Locations[FindLocation("PoPrince_town")], true);
			LAi_SetFightMode(PChar, false);
			LAi_group_SetRelation("Imperial_Escort_Agent", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_QuestDelay("imperial_escort_PoP_ambush_battle_won2", 0.1);
		break;

		case "imperial_escort_PoP_ambush_battle_won2":
			for(n=1; n<OFFICER_MAX; n++)
			{
				cc = GetOfficersIndex(PChar, n);
				if(cc != -1)
				{
					LAi_SetFightMode(Characters[cc], false);
					LAi_SetOfficerType(Characters[cc]);
				}
			}
			Characters[GetCharacterIndex("Jaime Lezcano")].nation = PIRATE;
			LAi_SetActorType(characterFromID("Jaime Lezcano"));
			Characters[GetCharacterIndex("Jaime Lezcano")].Dialog.CurrentNode = "imperial_escort_ambush_surrender";
			LAi_ActorDialog(characterfromID("Jaime Lezcano"), PChar, "imperial_escort_agent_captured", 5.0, 5.0);
		break;

		case "imperial_escort_agent_captured":
			Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
			Preprocessor_AddQuestData("evilgov", GetMyFullName(CharacterFromID("Emiliano de Guzmán")));
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			switch(GetAttribute(PChar, "quest.imperial_escort.disguise"))
			{
				case "failed":
					AddQuestRecord("Imperial Escort", 15);
				break;

				case "soldier":
					AddQuestRecord("Imperial Escort", 16);
				break;
			}
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("governor");
			Preprocessor_Remove("evilgov");
			Preprocessor_Remove("agent");
			SetCharacterRemovable(CharacterFromID("Jaime Lezcano"), false);
			AddPassenger(PChar, CharacterFromID("Jaime Lezcano"), 1);
			Characters[GetCharacterIndex("Jaime Lezcano")].quest.no_escape = true;
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			LAi_ActorFollow(CharacterFromID("Jaime Lezcano"), PChar, "", 5.0);

			PChar.quest.imperial_escort_remove_agent.win_condition.l1 = "ExitFromLocation";
			PChar.quest.imperial_escort_remove_agent.win_condition.l1.location = PChar.location;
			Pchar.quest.imperial_escort_remove_agent.win_condition = "imperial_escort_remove_agent";

			SetCharacterShipLocation(CharacterFromID("Pelayo Nunez"), "Cuba_Shore_06");
			PChar.quest.imperial_escort_ship_setup.win_condition.l1 = "location";
			PChar.quest.imperial_escort_ship_setup.win_condition.l1.location = "Cuba";
			PChar.quest.imperial_escort_ship_setup.win_condition = "imperial_escort_ship_setup";
		break;


		case "imperial_escort_remove_agent":
			LAi_LocationFightDisable(&Locations[FindLocation("PoPrince_town")], false);
			LAi_SetStayType(CharacterFromID("Jaime Lezcano"));
			ChangeCharacterAddress(CharacterFromID("Jaime Lezcano"), "None", "");
		break;

		case "imperial_escort_spy_intro":
			ChangeCharacterAddressGroup(characterfromID("Gilles Clouzot"), "PoPrince_townhall", "reload", "reload2");
			LAi_SetActorType(CharacterFromID("Gilles Clouzot"));
			Characters[GetCharacterIndex("Gilles Clouzot")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterfromID("Gilles Clouzot"), PChar, "imperial_escort_spy_intro2", 5.0, 5.0);
		break;

		case "imperial_escort_spy_intro2":
			LAi_SetActorType(CharacterFromID("Isabelle de Cussy"));
			Characters[GetCharacterIndex("Isabelle de Cussy")].Dialog.CurrentNode = "imperial_escort_what_use_is_he";
			LAi_ActorDialogNow(CharacterfromID("Isabelle de Cussy"), PChar, "imperial_escort_spy_intro3", 2.0);
		break;

		case "imperial_escort_spy_intro3":
			LAi_SetActorType(CharacterFromID("Gilles Clouzot"));
			Characters[GetCharacterIndex("Gilles Clouzot")].Dialog.CurrentNode = "imperial_escort_transport_to_muelle";
			LAi_ActorDialog(characterfromID("Gilles Clouzot"), PChar, "imperial_escort_spy_with_me", 5.0, 5.0);
		break;

		case "imperial_escort_spy_with_me":
			AddPassenger(PChar, CharacterFromID("Gilles Clouzot"), 0);
			LAi_SetActorType(CharacterFromID("Gilles Clouzot"));
			LAi_ActorFollowEverywhere(CharacterFromID("Gilles Clouzot"), "", 10.0);
			LAi_SetStayType(CharacterfromID("Isabelle de Cussy"));

			PChar.quest.imperial_escort_leave_PoP_townhall.win_condition.l1 = "ExitFromLocation";
			PChar.quest.imperial_escort_leave_PoP_townhall.win_condition.l1.location = PChar.location;
			Pchar.quest.imperial_escort_leave_PoP_townhall.win_condition = "imperial_escort_leave_PoP_townhall";
		break;

		case "imperial_escort_leave_PoP_townhall":
			Preprocessor_AddQuestData("PoPgovernor", GetMyFullName(CharacterFromID("Isabelle de Cussy")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 17);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("governor");
			DisableFastTravel(false);

			PChar.quest.imperial_escort_spy_aboard.win_condition.l1 = "location";
			PChar.quest.imperial_escort_spy_aboard.win_condition.l1.location = "Hispaniola";
			PChar.quest.imperial_escort_spy_aboard.win_condition = "imperial_escort_spy_aboard";

			PChar.quest.imperial_escort_find_Uasco.win_condition.l1 = "location";
			PChar.quest.imperial_escort_find_Uasco.win_condition.l1.location = "Muelle_port";
			PChar.quest.imperial_escort_find_Uasco.win_condition = "imperial_escort_find_Uasco";
		break;

		case "imperial_escort_spy_aboard":
			RestoreDialog(CharacterFromID("Isabelle de Cussy"));
			LAi_SetStayType(CharacterFromID("Gilles Clouzot"));
			ChangeCharacterAddress(characterFromID("Gilles Clouzot"), "None", "");
			Preprocessor_AddQuestData("docker", GetMyFullName(CharacterFromID("Uasco Mazinho")));
			Preprocessor_AddQuestData("spy", GetMyFullName(CharacterFromID("Gilles Clouzot")));
			AddQuestRecord("Imperial Escort", 18);
			Preprocessor_Remove("spy");
			Preprocessor_Remove("docker");
		break;

		case "imperial_escort_find_Uasco":
			StoreDialog(CharacterFromID("Uasco Mazinho"));
			characters[GetCharacterIndex("Uasco Mazinho")].Dialog.Filename = "quest_Uasco Mazinho_dialog.c";
			Characters[GetCharacterIndex("Uasco Mazinho")].Dialog.CurrentNode = "imperial_escort_load_my_cargo1";
		break;

		case "imperial_escort_uasco_to_ship":
			Locations[FindLocation("Muelle_port")].reload.l1.disable = 1;
			DisableFastTravel(true);
			bQuestDisableSeaEnter = true;
			LAi_SetActorType(CharacterFromID("Uasco Mazinho"));
			LAi_ActorFollow(CharacterFromID("Uasco Mazinho"), PChar, "", 5.0);
			PChar.quest.imperial_escort_uasco_aboard.win_condition.l1 = "Location";
			PChar.quest.imperial_escort_uasco_aboard.win_condition.l1.location = GetCharacterShipQDeck(PChar);
			Pchar.quest.imperial_escort_uasco_aboard.win_condition = "imperial_escort_uasco_aboard";
		break;

		case "imperial_escort_uasco_aboard":
			DisableFastTravel(false);
			ChangeCharacterAddressGroup(CharacterfromID("Uasco Mazinho"), "Hold1", "rld", "loc1");
			LAi_SetLoginTime(CharacterFromID("Uasco Mazinho"), 0.0, 24.0);
			LAi_SetStayType(CharacterFromID("Uasco Mazinho"));
			Characters[GetCharacterIndex("Uasco Mazinho")].Dialog.CurrentNode = "imperial_escort_where_is_cargo";
		break;

		case "imperial_escort_uasco_prisoner":
			LAi_SetActorType(CharacterfromID("Uasco Mazinho"));
			LAi_ActorAnimation(CharacterfromID("Uasco Mazinho"), "Ground_SitDown", "imperial_escort_uasco_sat", 3.5);
			Locations[FindLocation("Muelle_port")].reload.l1.disable = 0;
			PChar.quest.imperial_escort_uasco_aboard.win_condition.l1 = "Location";
			PChar.quest.imperial_escort_uasco_aboard.win_condition.l1.location = "Muelle_port";
			Pchar.quest.imperial_escort_uasco_aboard.win_condition = "imperial_escort_uasco_prisoner2";
		break;

		case "imperial_escort_uasco_sat":
			LAi_SetActorType(CharacterfromID("Uasco Mazinho"));
			LAi_SetPoorType(CharacterfromID("Uasco Mazinho"));
		break;

		case "imperial_escort_uasco_prisoner2":
//			ChangeCharacterAddress(CharacterFromID("Uasco Mazinho"), "None", "");
//			AddPassenger(PChar, CharacterFromID("Uasco Mazinho"), 1);
//			SetCharacterRemovable(characterFromID("Uasco Mazinho"), false);
			Characters[GetCharacterIndex("Uasco Mazinho")].Dialog.Filename = "quest_Uasco Mazinho_dialog.c";
			Characters[GetCharacterIndex("Uasco Mazinho")].Dialog.CurrentNode = "imperial_escort_prisoner";
			ChangeCharacterAddressGroup(CharacterFromID("Gilles Clouzot"), "Muelle_port", "goto", "goto8");
			LAi_SetActorType(CharacterFromID("Gilles Clouzot"));
			Characters[GetCharacterIndex("Gilles Clouzot")].Dialog.CurrentNode = "imperial_escort_spy_ashore";
			LAi_ActorDialog(characterfromID("Gilles Clouzot"), PChar, "imperial_escort_spy_ashore", 5.0, 5.0);
		break;

		case "imperial_escort_spy_ashore":
			bQuestDisableSeaEnter = false;
			Preprocessor_AddQuestData("docker", GetMyFullName(CharacterFromID("Uasco Mazinho")));
			Preprocessor_AddQuestData("spy", GetMyFullName(CharacterFromID("Gilles Clouzot")));
			if(GetRMRelation(PChar, FRANCE) <= REL_WAR) AddQuestRecord("Imperial Escort", 20);
			else AddQuestRecord("Imperial Escort", 19);
			Preprocessor_Remove("spy");
			Preprocessor_Remove("docker");
			sld = CharacterFromID("Gilles Clouzot");
			sld.name = GetMyName(CharacterFromID("Uasco Mazinho"));
			sld.lastname = GetMyLastName(CharacterFromID("Uasco Mazinho"));
			sld.Dialog.Filename = "Isla Muelle citizen_dialog.c";
			sld.Dialog.CurrentNode = "First time";
			sld.greeting = "Gr_isla muelle citizen";
			LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
			LAi_SetImmortal(sld, true);
			RemovePassenger(PChar, sld);

			StoreDialog(CharacterFromID("Isabelle de Cussy"));
			characters[GetCharacterIndex("Isabelle de Cussy")].Dialog.Filename = "quest_Isabelle de Cussy_dialog.c";
			characters[GetCharacterIndex("Isabelle de Cussy")].Dialog.CurrentNode = "imperial_escort_return_from_muelle";
		break;

		case "imperial_escort_governor_says_cuba":	// Triggered by dialog with Isabelle de Cussy
//			if(CheckQuestAttribute("imperial_escort.status", "ship_missing"))
			if(GetCharacterShipModel(CharacterfromID("Pelayo Nunez")) == GetAttribute(PChar, "quest.imperial_escort.shiptype"))
			{
				Preprocessor_AddQuestData("PoPgovernor", GetMyFullName(CharacterFromID("Isabelle de Cussy")));
				Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
				Preprocessor_AddQuestData("ship", PChar.quest.imperial_escort.ship_name);
				AddQuestRecord("Imperial Escort", 21);
				Preprocessor_Remove("ship");
				Preprocessor_Remove("envoy");
				Preprocessor_Remove("PoPgovernor");
			}
			else
			{
				Preprocessor_AddQuestData("PoPgovernor", GetMyFullName(CharacterFromID("Isabelle de Cussy")));
				Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
				AddQuestRecord("Imperial Escort", 22);
				Preprocessor_Remove("envoy");
				Preprocessor_Remove("PoPgovernor");
			}

			LAi_SetActorType(CharacterFromID("Isabelle de Cussy"));
			PChar.quest.imperial_escort_restore_PoP_governor.win_condition.l1 = "location";
			PChar.quest.imperial_escort_restore_PoP_governor.win_condition.l1.location = "Hispaniola";
			PChar.quest.imperial_escort_restore_PoP_governor.win_condition = "imperial_escort_restore_PoP_governor";

			SetCharacterShipLocation(CharacterFromID("Pelayo Nunez"), "Cuba_Shore_06");
			PChar.quest.imperial_escort_ship_setup.win_condition.l1 = "location";
			PChar.quest.imperial_escort_ship_setup.win_condition.l1.location = "Cuba";
			PChar.quest.imperial_escort_ship_setup.win_condition = "imperial_escort_ship_setup";
		break;

		case "imperial_escort_restore_PoP_governor":
			LAi_SetStayType(CharacterFromID("Isabelle de Cussy"));
			RestoreDialog(CharacterFromID("Isabelle de Cussy"));
		break;

		case "imperial_escort_ship_setup":
			Group_CreateGroup("agent_ship");
			Group_AddCharacter("agent_ship", "Pelayo Nunez");
			Group_SetGroupCommander("agent_ship", "Pelayo Nunez");

			Group_SetTaskNone("agent_ship");
			Group_LockTask("agent_ship");
			Group_SetAddress("agent_ship", "Cuba", "Quest_ships", "Quest_ship_14");
			Sea_LoginGroupNow("agent_ship");

			NPChar = CharacterFromID("Pelayo Nunez");
			NPChar.recognized = true;
			NPChar.nation = PRIVATEER_NATION;
			NPChar.skipRM = true;
//			NPChar.flags.personal = 6;
//			NPChar.flags.personal.texture = 3;
			NPChar.skipRM = true;
			NPChar.nosurrender = 1;
			PChar.quest.imperial_escort.agent_shiptype = GetCharacterShipModel(CharacterfromID("Pelayo Nunez"));

			PChar.quest.imperial_escort_defeat_ship.win_condition.l1 = "Character_Capture";
			PChar.quest.imperial_escort_defeat_ship.win_condition.l1.character = "Pelayo Nunez";
			PChar.quest.imperial_escort_defeat_ship.win_condition.l2 = "SeaEnter";
			PChar.quest.imperial_escort_defeat_ship.win_condition = "imperial_escort_defeat_ship";
			PChar.quest.imperial_escort_defeat_ship1.win_condition.l1 = "NPC_Death";
			PChar.quest.imperial_escort_defeat_ship1.win_condition.l1.character = "Pelayo Nunez";
			PChar.quest.imperial_escort_defeat_ship1.win_condition.l2 = "SeaEnter";
			PChar.quest.imperial_escort_defeat_ship1.win_condition = "imperial_escort_defeat_ship";
		break;

		case "imperial_escort_defeat_ship":
			PChar.quest.imperial_escort_defeat_ship.over = "yes";
			PChar.quest.imperial_escort_defeat_ship1.over = "yes";
//			if(CheckQuestAttribute("imperial_escort.status", "ship_missing"))
			if(GetAttribute(PChar, "quest.imperial_escort.agent_shiptype") == GetAttribute(PChar, "quest.imperial_escort.shiptype"))
			{
				Preprocessor_AddQuestData("ship", PChar.quest.imperial_escort.ship_name);
				Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
				AddQuestRecord("Imperial Escort", 23);
				Preprocessor_Remove("envoy");
				Preprocessor_Remove("ship");
			}
			else
			{
				Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
				AddQuestRecord("Imperial Escort", 24);
				Preprocessor_Remove("envoy");
			}
			Locations[FindLocation("Cuba_exit_grot")].vcskip = true;
			Locations[FindLocation("Cuba_exit_grot")].locators_radius.officers.reload1_1 = 5.0;
			Locations[FindLocation("Cuba_exit_grot")].reload.l3.emerge = "reload1_back";

			Locations[FindLocation("Cuba_exit_grot")].models.always.locators = "Cave_l_GR";
			Locations[FindLocation("Cuba_Grot")].models.always.locators = "Grot_l_GR";

			PChar.quest.imperial_escort_outside_kidnap_cave.win_condition.l1 = "location";
			PChar.quest.imperial_escort_outside_kidnap_cave.win_condition.l1.location = "Cuba_exit_grot";
			PChar.quest.imperial_escort_outside_kidnap_cave.win_condition = "imperial_escort_outside_kidnap_cave";
		break;

		case "imperial_escort_outside_kidnap_cave":
			Locations[FindLocation("Cuba_Grot")].vcskip = true;
			Locations[FindLocation("Cuba_Grot")].locators_radius.officers.reload3_1 = 3.0;
			Locations[FindLocation("Cuba_Grot")].image = "Inside_Kidnap_Cave.tga";

			TakeItemFromCharacter(CharacterFromID("Imperial_envoy"), FindCharacterItemByGroup(CharacterFromID("Imperial_envoy"), BLADE_ITEM_TYPE));
			RemoveCharacterEquip(CharacterFromID("Imperial_envoy"), BLADE_ITEM_TYPE);

			if(IsOfficer(romance) && romance.location == PChar.location)
			{
				LAi_SetActorType(romance);
				romance.Dialog.Filename = "romance_dialog.c";
				romance.dialog.CurrentNode = "imperial_escort_kidnappers_cave";
				LAi_ActorDialog(romance,PChar,"",5.0,5.0);	// Exits to "imperial_escort_havana_for_ether" or "imperial_escort_outside_kidnap_cave2"
			}
			else
			{
				speaker = Get_Speaker();
				if (speaker != "")
				{
					crewref = characterFromID(speaker);
					crewidx = GetCharacterIndex(speaker);
					StoreDialog(crewref);
					LAi_SetActorType(crewref);
					characters[crewidx].Dialog.Filename = "crew_dialog.c";
					Characters[crewidx].Dialog.CurrentNode = "imperial_escort_cave_tactics";
					LAi_ActorDialog(crewref, PChar, "imperial_escort_outside_kidnap_cave2", 5.0, 5.0);
				}
				else
				{
					Pchar.dialog.CurrentNode = "imperial_escort_at_cave";
					LAi_SetActorType(PChar);
					LAi_ActorSelfDialog(PChar, "imperial_escort_outside_kidnap_cave2");
				}
			}
		break;

		case "imperial_escort_outside_kidnap_cave2":
			LAi_SetPlayerType(PChar);
			if(IsOfficer(romance) && romance.location == PChar.location && GetAttribute(PChar, "quest.imperial_escort.cave_climber") != romance.id) LAi_SetOfficerType(romance);
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_envoy"),"Cuba_Grot", "officers", "reload3_2");
			if(CheckCharacterItem(PChar, "pistolgas"))
			{
				NPChar = CharacterFromID("Imperial_envoy");
				LAi_SetActorType(NPChar);
				LAi_ActorAnimation(NPChar, "Lay_2", "", -1);
				NPChar.stunned = true;
				if(IsPrisoner(CharacterFromID("Jaime Lezcano")))
				{
					PChar.quest.imperial_escort_inside_kidnap_cave_case1.win_condition.l1 = "location";
					PChar.quest.imperial_escort_inside_kidnap_cave_case1.win_condition.l1.location = "Cuba_Grot";
					PChar.quest.imperial_escort_inside_kidnap_cave_case1.win_condition = "imperial_escort_inside_kidnap_cave_case1";
				}
				else
				{
					PChar.quest.imperial_escort_inside_kidnap_cave_case2.win_condition.l1 = "location";
					PChar.quest.imperial_escort_inside_kidnap_cave_case2.win_condition.l1.location = "Cuba_Grot";
					PChar.quest.imperial_escort_inside_kidnap_cave_case2.win_condition = "imperial_escort_inside_kidnap_cave_case2";
				}
				PChar.quest.imperial_escort_throw_etherbomb.win_condition.l1 = "locator";
				PChar.quest.imperial_escort_throw_etherbomb.win_condition.l1.location = "Cuba_exit_grot";
				PChar.quest.imperial_escort_throw_etherbomb.win_condition.l1.locator_group = "officers";
				PChar.quest.imperial_escort_throw_etherbomb.win_condition.l1.locator = "reload1_1";
				PChar.quest.imperial_escort_throw_etherbomb.win_condition = "imperial_escort_throw_etherbomb";
			}
			else
			{
				if(IsPrisoner(CharacterFromID("Jaime Lezcano")))
				{
					PChar.quest.imperial_escort_inside_kidnap_cave_case3.win_condition.l1 = "location";
					PChar.quest.imperial_escort_inside_kidnap_cave_case3.win_condition.l1.location = "Cuba_Grot";
					PChar.quest.imperial_escort_inside_kidnap_cave_case3.win_condition = "imperial_escort_inside_kidnap_cave_case3";
				}
				else
				{
					PChar.quest.imperial_escort_inside_kidnap_cave_case4.win_condition.l1 = "location";
					PChar.quest.imperial_escort_inside_kidnap_cave_case4.win_condition.l1.location = "Cuba_Grot";
					PChar.quest.imperial_escort_inside_kidnap_cave_case4.win_condition = "imperial_escort_inside_kidnap_cave_case4";
				}
			}
		break;

		case "imperial_escort_havana_for_ether":
			Locations[FindLocation("Cuba_exit_grot")].reload.l3.disable = 1;
			LAi_SetOfficerType(romance);
			SetCharacterRemovable(romance, false);
			PChar.quest.imperial_escort.romance_slot = -1;
			for(i=1; i<OFFICER_MAX; i++)				// Find which slot Lucía/Edmundo is occupying in case you manage to displace them by recruiting a new officer
			{
				if(GetOfficersIndex(PChar,i) == romanceidx) PChar.quest.imperial_escort.romance_slot = i;
			}

			Preprocessor_AddQuestData("romance", GetMyFullName(romance));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(romance)));
			AddQuestRecord("Imperial Escort", 31);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("romance");

			Locations[FindLocation("Cuba_Port")].locators_radius.goto.cityzen_4 = 5.0;
			PChar.quest.imperial_escort_havana_arrival_for_ether.win_condition.l1 = "location";
			PChar.quest.imperial_escort_havana_arrival_for_ether.win_condition.l1.location = "Cuba_Port";
			PChar.quest.imperial_escort_havana_arrival_for_ether.win_condition = "imperial_escort_havana_arrival_for_ether";

			PChar.quest.imperial_escort_romance_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.imperial_escort_romance_dead.win_condition.l1.character = romance.id;
			PChar.quest.imperial_escort_romance_dead.win_condition = "imperial_escort_romance_dead";
		break;

		case "imperial_escort_romance_dead":
			PChar.quest.imperial_escort_havana_arrival_for_ether.over = "yes";
			PChar.quest.imperial_escort_havana_trader_approach.over = "yes";
			Preprocessor_AddQuestData("romance", GetMyFullName(romance));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 30);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("romance");
			PChar.quest.imperial_escort_outside_kidnap_cave.win_condition.l1 = "location";
			PChar.quest.imperial_escort_outside_kidnap_cave.win_condition.l1.location = "Cuba_exit_grot";
			PChar.quest.imperial_escort_outside_kidnap_cave.win_condition = "imperial_escort_outside_kidnap_cave";
		break;

		case "imperial_escort_havana_arrival_for_ether":
			StartQuestMovie(false, false, false);
			DisableFastTravel(true);
			if(!IsOfficer(romance) || romance.location != PChar.location)	// If Lucía/Edmundo has somehow been displaced, put them back
			{
				SetOfficersIndex(PChar, sti(PChar.quest.imperial_escort.romance_slot), romanceidx);
				ChangeCharacterAddressGroup(romance,"Cuba_Port", "officers", "Sea_2_"+PChar.quest.imperial_escort.romance_slot);
			}
			PChar.quest.imperial_escort_havana_trader_approach.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_havana_trader_approach.win_condition.l1.location = "Cuba_Port";
			PChar.quest.imperial_escort_havana_trader_approach.win_condition.l1.locator_group = "goto";
			PChar.quest.imperial_escort_havana_trader_approach.win_condition.l1.locator = "cityzen_4";
			PChar.quest.imperial_escort_havana_trader_approach.win_condition = "imperial_escort_havana_trader_approach";
		break;

		case "imperial_escort_havana_trader_approach":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, romance);
			LAi_ActorWaitDialog(PChar, romance);
			PChar.quest.imperial_escort_romance_dead.over = "yes";
			LAi_SetActorType(romance);
			romance.Dialog.Filename = "romance_dialog.c";
			romance.dialog.CurrentNode = "imperial_escort_let_me_talk";
			LAi_ActorDialog(romance,PChar,"imperial_escort_romance_to_trader",5.0,5.0);
		break;

		case "imperial_escort_romance_to_trader":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Rosa Zambrano"));
			LAi_SetActorType(romance);
			LAi_ActorGoToLocator(romance, "goto", "goto_61", "imperial_escort_romance_to_trader2", 10.0);
		break;

		case "imperial_escort_romance_to_trader2":
			LAi_SetActorType(romance);
			LAi_SetActorType(CharacterFromID("Rosa Zambrano"));
			LAi_ActorTurnToCharacter(romance, CharacterFromID("Rosa Zambrano"));
			LAi_ActorWaitDialog(CharacterFromID("Rosa Zambrano"), romance);
			LAi_ActorDialogNow(romance, CharacterFromID("Rosa Zambrano"),"",5.0);
			LAi_QuestDelay("imperial_escort_romance_back_from_trader", 7.0);
		break;

		case "imperial_escort_romance_back_from_trader":
			LAi_SetPlayerType(PChar);
			LAi_SetMerchantType(CharacterFromID("Rosa Zambrano"));
			LAi_SetActorType(romance);
			romance.dialog.CurrentNode = "imperial_escort_bought_ether";
			LAi_ActorDialog(romance,PChar,"imperial_escort_finished_with_trader",5.0,5.0);
		break;

		case "imperial_escort_finished_with_trader":
			EndQuestMovie();
			DisableFastTravel(false);
			Locations[FindLocation("Cuba_Port")].locators_radius.goto.cityzen_4 = 1.0;
			LAi_SetOfficerType(romance);
			SetCharacterRemovable(romance, true);
			PlayStereoSound("INTERFACE\important_item.wav");
			GiveItem2Character(PChar, "pistolgas");
			Preprocessor_AddQuestData("romance", GetMyFullName(romance));
			AddQuestRecord("Imperial Escort", 32);
			Preprocessor_Remove("romance");
			Locations[FindLocation("Cuba_exit_grot")].reload.l3.disable = 0;
			PChar.quest.imperial_escort_return_kidnap_cave.win_condition.l1 = "location";
			PChar.quest.imperial_escort_return_kidnap_cave.win_condition.l1.location = "Cuba_exit_grot";
			PChar.quest.imperial_escort_return_kidnap_cave.win_condition = "imperial_escort_return_kidnap_cave";
		break;

		case "imperial_escort_return_kidnap_cave":
			if(IsOfficer(romance) && romance.location == PChar.location)
			{
				LAi_SetActorType(romance);
				romance.dialog.CurrentNode = "imperial_escort_cave_return";
				LAi_ActorDialog(romance,PChar,"imperial_escort_outside_kidnap_cave2",5.0,5.0);
			}
			else
			{
				Pchar.dialog.CurrentNode = "imperial_escort_at_cave";
				LAi_SetActorType(PChar);
				LAi_ActorSelfDialog(PChar, "imperial_escort_outside_kidnap_cave2");
			}
		break;

		case "imperial_escort_throw_etherbomb":
			PChar.quest.old_gun = GetCharacterEquipByGroup(PChar, GUN_ITEM_TYPE);
			EquipCharacterByItem(PChar,"pistolgas");
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "reload", "reload1_back");
			LAi_QuestDelay("imperial_escort_throw_etherbomb2", 1.0);
		break;

		case "imperial_escort_throw_etherbomb2":
//			LAi_SetPlayerType(PChar);
//			LAi_SetFightMode(PChar, true);
//			LAi_QuestDelay("imperial_escort_throw_etherbomb3", 1.0);
			LAi_ActorAnimation(PChar, "shot", "imperial_escort_throw_etherbomb3", -1);
		break;

		case "imperial_escort_throw_etherbomb3":
			LAi_SetPlayerType(PChar);
			PlaySound("OBJECTS\SHIPCHARGE\ship_bow.wav");
			TakeItemFromCharacter(Pchar, "pistolgas");
			CreateParticleSystem("cancloud" , 10.0, -1.25, -15.58, 0.0, 0.0, 0.0, 1);	// Based on "reload1_back"
//			CreateParticleSystem("cancloud" , 9.58, -3.19, -12.24, 0.0, 0.0, 0.0, sti(20) );	// Based on "reload1"
			LAi_QuestDelay("imperial_escort_throw_etherbomb4", 1.0);
		break;

		case "imperial_escort_throw_etherbomb4":
			LAi_SetFightMode(PChar, false);
			if (PChar.quest.old_gun != "") EquipCharacterByItem(PChar,PChar.quest.old_gun);
			DeleteQuestAttribute("old_gun");
			if(IsOfficer(romance) && romance.location == PChar.location)
			{
				LAi_SetActorType(PChar);
				LAi_ActorWaitDialog(PChar, romance);
				LAi_SetActorType(romance);
				romance.Dialog.Filename = "romance_dialog.c";
				romance.dialog.CurrentNode = "imperial_escort_clear_air";
				LAi_ActorDialog(romance,PChar,"imperial_escort_clear_cloud",5.0,5.0);
			}
			else
			{
				PChar.dialog.CurrentNode = "imperial_escort_clear_air";
				LAi_SetActorType(PChar);
				LAi_ActorSelfDialog(PChar, "imperial_escort_clear_cloud");
			}
		break;

		case "imperial_escort_clear_cloud":
			LAi_SetPlayerType(PChar);
			if(IsOfficer(romance)) LAi_SetOfficerType(romance);
			LAi_Fade("", "");
			WaitDate("", 0, 0, 0, 0, 2);
			DeleteParticles();
		break;

		case "imperial_escort_inside_kidnap_cave_case1":
			for (n=1; n<5; n++)
			{
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.5, "pirat"+(rand(8)+1), "monsters", "monster" + n);
				sld.id = "Kidnapper " + n;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
				i = rand(1) + 1;
				LAi_SetActorType(sld);
				LAi_ActorAnimation(sld, "Lay_" + i, "", -1);
			}
			StartQuestMovie(true, false, false);
			DisableFastTravel(true);
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Cuba_Grot")], true);
			PChar.quest.imperial_escort_found_envoy.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_found_envoy.win_condition.l1.location = "Cuba_Grot";
			PChar.quest.imperial_escort_found_envoy.win_condition.l1.locator_group = "officers";
			PChar.quest.imperial_escort_found_envoy.win_condition.l1.locator = "reload3_1";
			PChar.quest.imperial_escort_found_envoy.win_condition = "imperial_escort_found_envoy";
		break;

		case "imperial_escort_found_envoy":
			if(IsOfficer(romance) && romance.location == PChar.location)
			{
				LAi_SetActorType(romance);
				romance.Dialog.Filename = "romance_dialog.c";
				romance.dialog.CurrentNode = "imperial_escort_in_cave_no_agent";
				LAi_ActorDialog(romance,PChar,"imperial_escort_leave_cave",5.0,5.0);
			}
			else
			{
				PChar.dialog.CurrentNode = "imperial_escort_in_cave_no_agent";
				LAi_SetActorType(PChar);
				LAi_ActorSelfDialog(PChar, "imperial_escort_leave_cave");
			}
		break;

		case "imperial_escort_inside_kidnap_cave_case2":
			ChangeCharacterAddressGroup(CharacterFromID("Jaime Lezcano"),"Cuba_Grot", "officers", "reload3_1");
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			LAi_ActorTurnToCharacter(CharacterFromID("Jaime Lezcano"), CharacterFromID("Imperial_envoy"));

			for (n=1; n<5; n++)
			{
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.5, "pirat"+(rand(8)+1), "monsters", "monster" + n);
				sld.id = "Kidnapper " + n;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
				i = rand(1) + 1;
				LAi_SetActorType(sld);
				LAi_ActorAnimation(sld, "Lay_" + i, "", -1);
			}

			StartQuestMovie(true, false, false);
			DisableFastTravel(true);
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Cuba_Grot")], true);
			Characters[GetCharacterIndex("Jaime Lezcano")].Dialog.CurrentNode = "imperial_escort_negotations_in_cave";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition.l1.location = "Cuba_Grot";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition.l1.locator_group = "officers";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition.l1.locator = "reload3_1";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition = "imperial_escort_agent_speaks_in_cave";
		break;

		case "imperial_escort_inside_kidnap_cave_case3":
			Locations[FindLocation("Cuba_Grot")].reload.l1.disable = 1;
			Locations[FindLocation("Cuba_Grot")].reload.l2.disable = 1;
			LAi_SetActorType(CharacterFromID("Imperial_envoy"));
			LAi_ActorTurnToCharacter(characterFromID("Imperial_envoy"), PChar);
			for (n=1; n<5; n++)
			{
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.5, "pirat"+(rand(8)+1), "monsters", "monster" + n);
				sld.id = "Kidnapper " + n;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
			}
			PChar.quest.imperial_escort_negotiate_kidnappers_in_cave.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_negotiate_kidnappers_in_cave.win_condition.l1.location = "Cuba_Grot";
			PChar.quest.imperial_escort_negotiate_kidnappers_in_cave.win_condition.l1.locator_group = "officers";
			PChar.quest.imperial_escort_negotiate_kidnappers_in_cave.win_condition.l1.locator = "reload3_1";
			PChar.quest.imperial_escort_negotiate_kidnappers_in_cave.win_condition = "imperial_escort_negotiate_kidnappers_in_cave";
		break;

		case "imperial_escort_inside_kidnap_cave_case4":
			ChangeCharacterAddressGroup(CharacterFromID("Jaime Lezcano"),"Cuba_Grot", "officers", "reload3_1");
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			LAi_ActorTurnToCharacter(CharacterFromID("Jaime Lezcano"), CharacterFromID("Imperial_envoy"));

			for (n=1; n<5; n++)
			{
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.5, "pirat"+(rand(8)+1), "monsters", "monster" + n);
				sld.id = "Kidnapper " + n;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
				LAi_SetActorType(sld);
			}

			StartQuestMovie(true, false, false);
			DisableFastTravel(true);
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Cuba_Grot")], true);
			Characters[GetCharacterIndex("Jaime Lezcano")].Dialog.CurrentNode = "imperial_escort_deception_in_cave1";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition.l1.location = "Cuba_Grot";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition.l1.locator_group = "officers";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition.l1.locator = "reload3_1";
			PChar.quest.imperial_escort_agent_speaks_in_cave.win_condition = "imperial_escort_agent_speaks_in_cave";
		break;

		case "imperial_escort_agent_speaks_in_cave":
			if(!CheckAttribute(CharacterFromID("Imperial_envoy"), "stunned"))
			{
				LAi_SetActorType(CharacterFromID("Imperial_envoy"));
				LAi_ActorTurnToCharacter(characterFromID("Imperial_envoy"), PChar);
			}
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			LAi_ActorDialogNow(CharacterFromID("Jaime Lezcano"),PChar,"",1.0);	// Dialog.CurrentNode set at case "imperial_escort_inside_kidnap_cave_case2" or "imperial_escort_inside_kidnap_cave_case4"
		break;

		case "imperial_escort_leave_cave_for_negotiation":				// Triggered by dialog with Jaime Lezcano if you had no ether bottle
			ChangeCharacterAddressGroup(CharacterFromID("Jaime Lezcano"),"Cuba_exit_grot", "goto", "goto6");
			Locations[FindLocation("Cuba_exit_grot")].locators_radius.officers.reload1_1 = 1.0;
			Locations[FindLocation("Cuba_exit_grot")].reload.l3.disable = 1;
			DoQuestReloadToLocation("Cuba_exit_grot", "reload", "reload1", "imperial_escort_outside_cave_for_negotiation");
		break;

		case "imperial_escort_leave_cave":						// Triggered by dialog with Jaime Lezcano, with "romance", or with yourself
			EndQuestMovie();
			LAi_SetPlayerType(PChar);
			if(IsPassenger(CharacterFromID("Jaime Lezcano")) && !IsPrisoner(CharacterFromID("Jaime Lezcano")))
			{
				LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
				ChangeCharacterAddressGroup(CharacterFromID("Jaime Lezcano"),"Cuba_exit_grot", "goto", "goto6");
			}
			if(Characters[GetCharacterIndex("Jaime Lezcano")].location == "Cuba_Grot") ChangeCharacterAddress(CharacterFromID("Jaime Lezcano"), "None", "");
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_envoy"),"Cuba_exit_grot", "goto", "goto5");
			Locations[FindLocation("Cuba_exit_grot")].locators_radius.officers.reload1_1 = 1.0;
			Locations[FindLocation("Cuba_exit_grot")].reload.l3.disable = 1;
			DoQuestReloadToLocation("Cuba_exit_grot", "reload", "reload1", "imperial_escort_outside_cave_after_release");
		break;

		case "imperial_escort_outside_cave_after_release":
			if(IsOfficer(romance)) LAi_SetOfficerType(romance);
			if(CheckAttribute(CharacterFromID("Imperial_envoy"), "stunned")) DeleteAttribute(CharacterFromID("Imperial_envoy"), "stunned");
			LAi_SetActorType(CharacterFromID("Imperial_envoy"));
			Characters[GetCharacterIndex("Imperial_envoy")].Dialog.CurrentNode = "outside_cave_after_ether";
			LAi_ActorDialog(CharacterfromID("Imperial_envoy"), PChar, "imperial_escort_walk_to_beach", 1.0, 1.0);
		break;

		case "imperial_escort_walk_to_beach":
			DisableFastTravel(false);
			sld = CharacterFromID("Jaime Lezcano");
			if(sld.location == PChar.location)
			{
				if (isofficer(sld))
				{
					LAi_SetOfficerType(sld);
				}
				else
				{
					LAi_SetActorType(sld);
					LAi_ActorFollowEverywhere(sld, "", 5.0);
				}
			}
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			LAi_ActorFollowEverywhere(NPChar, "", 10.0);
			LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);
			AddPassenger(PChar, NPChar, 0);
			SetCharacterRemovable(NPChar, false);
			NPChar.AbordageMode = 0;
			Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
			Preprocessor_AddQuestData("evilgov", GetMyFullName(CharacterFromID("Emiliano de Guzmán")));
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 28);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("governor");
			Preprocessor_Remove("evilgov");
			Preprocessor_Remove("agent");

			if (CheckAttribute(PChar, "quest.imperial_escort.cave_climber"))
			{
				LAi_QuestDelay("imperial_escort_call_climber_down", 0.3);
			}
			LAi_QuestDelay("imperial_escort_after_rescue", 0.0);
		break;

		case "imperial_escort_outside_cave_for_negotiation":
			if(ENABLE_WEAPONSMOD)
			{
				EquipCharacterByItem(CharacterFromID("Jaime Lezcano"),"pistol25+2");
			}
			else
			{
				EquipCharacterByItem(CharacterFromID("Jaime Lezcano"),"pistol25");
			}
			EquipCharacterByItem(CharacterFromID("Jaime Lezcano"),"commonarmor");
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			Characters[GetCharacterIndex("Jaime Lezcano")].Dialog.CurrentNode = "imperial_escort_negotiations_outside_cave1";
			LAi_ActorDialog(CharacterfromID("Jaime Lezcano"), PChar, "", 5.0, 5.0);	// Exits to "imperial_escort_agent_returns_to_cave" or "imperial_escort_fight_agent"
		break;

		case "imperial_escort_agent_returns_to_cave":
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
          		LAi_ActorGoToLocation(CharacterFromID("Jaime Lezcano"), "reload", "reload1_back", "none", "", "", "imperial_escort_agent_returns_to_cave2", 30.0);
		break;

		case "imperial_escort_agent_returns_to_cave2":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto6", "imperial_escort_agent_returns_to_cave3", 10.0);
		break;

		case "imperial_escort_agent_returns_to_cave3":
			LAi_ActorTurnToLocator(PChar, "reload", "reload1_back");
			LAi_Fade("", "imperial_escort_agent_returns_from_cave");
			WaitDate("", 0, 0, 0, 0, rand(4)+3);
		break;

		case "imperial_escort_agent_returns_from_cave":
			LAi_ActorWaitDialog(PChar, CharacterFromID("Jaime Lezcano"));
			Logit(TranslateString("","A few minutes later..."));
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			ChangeCharacterAddressGroup(CharacterFromID("Jaime Lezcano"),"Cuba_exit_grot", "officers", "reload1_1");
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_envoy"),"Cuba_exit_grot", "reload", "reload1_back");
			LAi_SetActorType(CharacterFromID("Imperial_envoy"));
			LAi_ActorFollow(CharacterFromID("Imperial_envoy"), CharacterFromID("Jaime Lezcano"), "", 5.0);
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			Characters[GetCharacterIndex("Jaime Lezcano")].Dialog.CurrentNode = "imperial_escort_return_from_cave";
			LAi_ActorDialog(CharacterfromID("Jaime Lezcano"), PChar, "imperial_escort_agent_returns_from_cave2", 5.0, 5.0);
		break;

		case "imperial_escort_agent_returns_from_cave2":
			LAi_SetPlayerType(PChar);
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_SetActorType(CharacterFromID("Imperial_envoy"));
			Characters[GetCharacterIndex("Imperial_envoy")].Dialog.CurrentNode = "outside_cave_no_ether";
			LAi_ActorDialog(CharacterfromID("Imperial_envoy"), PChar, "imperial_escort_walk_to_beach", 5.0, 5.0);
		break;

		case "imperial_escort_fight_agent":
			LAi_SetImmortal(CharacterFromID("Jaime Lezcano"), false);
			LAi_NoRebirthEnable(CharacterFromID("Jaime Lezcano"));
			LAi_group_MoveCharacter(CharacterFromID("Jaime Lezcano"), LAI_GROUP_MONSTERS);
			LAi_group_SetRelation(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_MONSTERS, "imperial_escort_agent_defeated_outside_cave");
		break;

		case "imperial_escort_agent_defeated_outside_cave":
			EndQuestMovie();
			Locations[FindLocation("Cuba_exit_grot")].reload.l3.disable = 0;
			PChar.quest.imperial_escort_inside_kidnap_cave_case3.win_condition.l1 = "location";			// Into cave with active kidnappers and no agent, same situation as if agent is your prisoner and you have no ether bottle
			PChar.quest.imperial_escort_inside_kidnap_cave_case3.win_condition.l1.location = "Cuba_Grot";		// So re-use quest case for that situation
			PChar.quest.imperial_escort_inside_kidnap_cave_case3.win_condition = "imperial_escort_inside_kidnap_cave_case3";
		break;

		case "imperial_escort_negotiate_kidnappers_in_cave":
			sld = CharacterFromID("Kidnapper 1");
			LAi_SetActorType(sld);
			sld.Dialog.Filename = "kidnappers_dialog.c";
			sld.dialog.CurrentNode = "negotiate";
			LAi_ActorDialog(sld,PChar,"",5.0,5.0);		// Exits to "imperial_escort_surrender_in_cave" or "imperial_escort_fight_in_cave"
		break;

		case "imperial_escort_surrender_in_cave":
			AddCharacterCrew(PChar, 4);
			Locations[FindLocation("Cuba_exit_grot")].reload.l3.disable = 1;
			Locations[FindLocation("Cuba_Grot")].reload.l1.disable = 0;
			Locations[FindLocation("Cuba_Grot")].reload.l2.disable = 0;
			Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 40);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("agent");
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "inside_cave_what_next1a";
			LAi_ActorDialog(NPChar, PChar, "imperial_escort_envoy_follows_in_cave", 5.0, 5.0);

			if (CheckAttribute(PChar, "quest.imperial_escort.cave_climber"))
			{
				PChar.quest.imperial_escort_prepare_recall_climber.win_condition.l1 = "location";
				PChar.quest.imperial_escort_prepare_recall_climber.win_condition.l1.location = "Cuba_exit_grot";
				PChar.quest.imperial_escort_prepare_recall_climber.win_condition = "imperial_escort_prepare_recall_climber";
			}
		break;

		case "imperial_escort_fight_in_cave":
			if(CheckAttribute(PChar, "quest.imperial_escort.cave_climber"))
			{
				sld = CharacterFromID(PChar.quest.imperial_escort.cave_climber);
				ChangeCharacterAddressGroup(sld, "Cuba_Grot", "goto", "goto1");
				SetOfficersIndex(PChar, sti(PChar.quest.imperial_escort.cave_climber_slot), GetCharacterIndex(PChar.quest.imperial_escort.cave_climber));
				DeleteQuestAttribute("imperial_escort.cave_climber_slot");
				DeleteQuestAttribute("imperial_escort.cave_climber");
			}
			LAi_LocationFightDisable(&Locations[FindLocation("Cuba_Grot")], false);
			for (n=1; n<5; n++)
			{
				sld = CharacterFromID("Kidnapper " + n);
				LAi_group_MoveCharacter(sld, LAI_GROUP_MONSTERS);
			}
			LAi_group_SetRelation(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_MONSTERS, "imperial_escort_cave_battle_over");
			PChar.quest.imperial_escort_envoy_saved_in_cave.win_condition.l1 = "NPC_Death";
			PChar.quest.imperial_escort_envoy_saved_in_cave.win_condition.l1.character = "Kidnapper 2";
			PChar.quest.imperial_escort_envoy_saved_in_cave.win_condition.l2 = "NPC_Death";
			PChar.quest.imperial_escort_envoy_saved_in_cave.win_condition.l2.character = "Kidnapper 4";
			PChar.quest.imperial_escort_envoy_saved_in_cave.win_condition = "imperial_escort_envoy_saved_in_cave";
			LAi_QuestDelay("imperial_escort_envoy_dead_in_cave", 60.0);
		break;

		case "imperial_escort_envoy_dead_in_cave":
			if(!CheckAttribute(PChar, "quest.imperial_escort.envoy_survives_battle") || sti(PChar.quest.imperial_escort.envoy_survives_battle) == false)
			{
				LAi_KillCharacter(characterfromID("Imperial_envoy"));
				PChar.quest.imperial_escort_envoy_saved_in_cave.over = "yes";
			}
		break;

		case "imperial_escort_envoy_saved_in_cave":
			PChar.quest.imperial_escort_envoy_dead_in_cave.over = "yes";
			PChar.quest.imperial_escort.envoy_survives_battle = true;
		break;

		case "imperial_escort_cave_battle_over":
			Locations[FindLocation("Cuba_Grot")].reload.l1.disable = 0;
			Locations[FindLocation("Cuba_Grot")].reload.l2.disable = 0;
			if(!LAi_IsDead(CharacterFromID("Imperial_envoy")))
			{
				LAi_SetActorType(PChar);
				LAi_ActorTurnToCharacter(PChar, CharacterFromID("Imperial_envoy"));
				LAi_ActorWaitDialog(PChar, CharacterFromID("Imperial_envoy"));
				PChar.quest.imperial_escort_envoy_dead_in_cave.over = "yes";
				PChar.quest.imperial_escort.envoy_survives_battle = true;
				Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
				Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
				AddQuestRecord("Imperial Escort", 38);
				Preprocessor_Remove("envoy");
				Preprocessor_Remove("agent");
				NPChar = CharacterFromID("Imperial_envoy");
				LAi_SetActorType(NPChar);
				NPChar.Dialog.CurrentNode = "inside_cave_what_next";
				LAi_ActorDialog(NPChar, PChar, "imperial_escort_envoy_follows_in_cave", 5.0, 5.0);
			}
			else
			{
				Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
				Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
				AddQuestRecord("Imperial Escort", 39);
				Preprocessor_Remove("envoy");
				Preprocessor_Remove("agent");
			}
		break;

		case "imperial_escort_envoy_follows_in_cave":
			LAi_SetPlayerType(PChar);
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			LAi_ActorFollowEverywhere(NPChar, "", 5.0);
			LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);
			AddPassenger(PChar, NPChar, 0);
			SetCharacterRemovable(NPChar, false);
			NPChar.AbordageMode = 0;
			Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
			Preprocessor_AddQuestData("evilgov", GetMyFullName(CharacterFromID("Emiliano de Guzmán")));
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 41);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("governor");
			Preprocessor_Remove("evilgov");
			Preprocessor_Remove("agent");

			LAi_QuestDelay("imperial_escort_after_rescue", 0.0);
		break;

		case "imperial_escort_officer_prepare_climb_cave":			// Intermediate step needed for officers other than 'romance' who got here from
			LAi_QuestDelay("imperial_escort_officer_climbs_cave", 0.1);	// "crew_dialog.c", which also calls "reset_crewmember", which puts them in officer mode
		break;

		case "imperial_escort_officer_climbs_cave":
			if(CheckAttribute(PChar, "quest.imperial_escort.cave_climber"))
			{
				StartQuestMovie(true, false, false);
				DisableFastTravel(true);
				sld = CharacterFromID(PChar.quest.imperial_escort.cave_climber);
				LAi_SetActorType(sld);
				LAi_ActorRunToLocator(sld, "goto", "goto4", "imperial_escort_officer_climbs_cave2", 20.0);
			}
		break;

		case "imperial_escort_officer_climbs_cave2":
			ChangeCharacterAddress(CharacterFromID(PChar.quest.imperial_escort.cave_climber), "None", "");
			LAi_Fade("", "imperial_escort_officer_climbs_cave3");
			WaitDate("", 0, 0, 0, 0, rand(3)+2);
		break;

		case "imperial_escort_officer_climbs_cave3":
			n = 1;
			cidx = GetCharacterIndex(PChar.quest.imperial_escort.cave_climber);
			for(i=0;i<OFFICER_MAX;i++)
			{
				if(GetOfficersIndex(PChar,i) == cidx) n = i;
			}
			PChar.quest.imperial_escort.cave_climber_slot = n;
			RemoveOfficersIndex(PChar, cidx);
			ChangeCharacterAddressGroup(CharacterFromID(PChar.quest.imperial_escort.cave_climber),"Cuba_exit_grot", "goto", "goto12");
			LAi_QuestDelay("imperial_escort_officer_climbs_cave4", 0.5);
		break;

		case "imperial_escort_officer_climbs_cave4":
			sld = CharacterFromID(PChar.quest.imperial_escort.cave_climber);
			LAi_SetActorType(sld);
			LAi_ActorAttack(sld, PChar, "");
			EndQuestMovie();
			DisableFastTravel(false);
		break;

		case "imperial_escort_prepare_recall_climber":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto6", "imperial_escort_call_climber_down", 10.0);
		break;

		case "imperial_escort_call_climber_down":
			LAi_SetPlayerType(PChar);
			sld = CharacterFromID(PChar.quest.imperial_escort.cave_climber);
			StoreDialog(sld);
			sld.Dialog.Filename = "crew_dialog.c";
			sld.Dialog.CurrentNode = "imperial_escort_down_from_cave";
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, PChar,"imperial_escort_officer_back_from_cave",1.0);
		break;

		case "imperial_escort_officer_back_from_cave":
			LAi_Fade("", "imperial_escort_officer_back_from_cave2");
			WaitDate("", 0, 0, 0, 0, 1);
			SetOfficersIndex(PChar, sti(PChar.quest.imperial_escort.cave_climber_slot), GetCharacterIndex(PChar.quest.imperial_escort.cave_climber));
		break;

		case "imperial_escort_officer_back_from_cave2":
			sld = CharacterFromID(PChar.quest.imperial_escort.cave_climber);
			ChangeCharacterAddressGroup(sld,"Cuba_exit_grot", "goto", "goto4");
			RestoreDialog(sld);
			DeleteQuestAttribute("imperial_escort.cave_climber_slot");
			DeleteQuestAttribute("imperial_escort.cave_climber");
		break;

		case "imperial_escort_agent_joins_crew":	// Triggered by dialog with Jaime Lezcano if it leads to him joining as officer
			NPChar = CharacterFromID("Jaime Lezcano");
			if (GetOfficersIndex(PChar, 3) == GetCharacterIndex(romance.id)) SetOfficersIndex(PChar, 2, GetCharacterIndex("Jaime Lezcano"));
			else SetOfficersIndex(PChar, 3, GetCharacterIndex("Jaime Lezcano"));
			LAi_SetOfficerType(NPChar);
			AddPassenger(PChar, NPChar, 0);
			SetCharacterRemovable(NPChar, false);
			LAi_SetImmortal(NPChar, false);
			LAi_NoRebirthEnable(NPChar);
			AddCharacterCrew(PChar, 4);
		break;

		case "imperial_escort_agent_to_tortuga":	// Triggered by dialog with Jaime Lezcano if it leads to promise to take him to Tortuga
			Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 25);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("agent");
			AddPassenger(PChar, CharacterFromID("Jaime Lezcano"), 0);
			SetCharacterRemovable(CharacterFromID("Jaime Lezcano"), false);
			PChar.quest.imperial_escort_agent_aboard.win_condition.l1 = "location";
			PChar.quest.imperial_escort_agent_aboard.win_condition.l1.location = "Cuba";
			PChar.quest.imperial_escort_agent_aboard.win_condition = "imperial_escort_agent_aboard";

			PChar.quest.imperial_escort_agent_at_tortuga.win_condition.l1 = "location";
			PChar.quest.imperial_escort_agent_at_tortuga.win_condition.l1.location = "Tortuga_port";
			PChar.quest.imperial_escort_agent_at_tortuga.win_condition = "imperial_escort_agent_at_tortuga";
			Locations[FindLocation("Tortuga_Port")].vcskip = true;
		break;

		case "imperial_escort_agent_aboard":
			LAi_type_actor_Reset(CharacterFromID("Jaime Lezcano"));
			ChangeCharacterAddress(CharacterFromID("Jaime Lezcano"), "None", "");
		break;

		case "imperial_escort_agent_at_tortuga":
			locations[FindLocation("Tortuga_port")].reload.l1.disable = 1;
			locations[FindLocation("Tortuga_port")].reload.l2.disable = 1;
			SetCharacterRemovable(CharacterFromID("Jaime Lezcano"), true);
			RemovePassenger(PChar, CharacterFromID("Jaime Lezcano"));
			PlaceCharacter(CharacterFromID("Jaime Lezcano"), "goto");
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			LAi_SetActorType(CharacterFromID("Jaime Lezcano"));
			Characters[GetCharacterIndex("Jaime Lezcano")].Dialog.CurrentNode = "imperial_escort_tortuga_arrival";
			LAi_ActorDialog(CharacterfromID("Jaime Lezcano"), PChar, "imperial_escort_agent_at_tortuga2", 20.0, 20.0);
		break;

		case "imperial_escort_agent_at_tortuga2":
			locations[FindLocation("Tortuga_port")].reload.l1.disable = 0;
			locations[FindLocation("Tortuga_port")].reload.l2.disable = 0;
			DeleteAttribute(&Locations[FindLocation("Tortuga_port")],"vcskip");
			Characters[GetCharacterIndex("Jaime Lezcano")].location = "none";
			LAi_SetCitizenType(CharacterFromID("Jaime Lezcano"));
			Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
			AddQuestRecord("Imperial Escort", 29);
			Preprocessor_Remove("agent");
		break;

		case "imperial_escort_after_rescue":
			Locations[FindLocation("Cuba_port")].vcskip = true;
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload4 = 3.0;
			PChar.quest.imperial_escort_reset_cave.win_condition.l1 = "location";
			PChar.quest.imperial_escort_reset_cave.win_condition.l1.location = "Cuba";
			PChar.quest.imperial_escort_reset_cave.win_condition = "imperial_escort_reset_cave";

			PChar.quest.imperial_escort_after_rescue_havana_port.win_condition.l1 = "location";
			PChar.quest.imperial_escort_after_rescue_havana_port.win_condition.l1.location = "Cuba_port";
			PChar.quest.imperial_escort_after_rescue_havana_port.win_condition = "imperial_escort_after_rescue_havana_port";

			PChar.quest.imperial_escort_after_rescue_havana_town.win_condition.l1 = "location";
			PChar.quest.imperial_escort_after_rescue_havana_town.win_condition.l1.location = "Havana_town_05";
			PChar.quest.imperial_escort_after_rescue_havana_town.win_condition = "imperial_escort_after_rescue_havana_town";

			PChar.quest.imperial_escort_after_rescue_santiago_port.win_condition.l1 = "location";
			PChar.quest.imperial_escort_after_rescue_santiago_port.win_condition.l1.location = "Santiago_port";
			PChar.quest.imperial_escort_after_rescue_santiago_port.win_condition = "imperial_escort_after_rescue_santiago_port";

			PChar.quest.imperial_escort_after_rescue_santiago_town.win_condition.l1 = "location";
			PChar.quest.imperial_escort_after_rescue_santiago_town.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.imperial_escort_after_rescue_santiago_town.win_condition = "imperial_escort_after_rescue_santiago_town";
		break;

		case "imperial_escort_reset_cave":
			LAi_LocationFightDisable(&Locations[FindLocation("Cuba_Grot")], false);
			Locations[FindLocation("Cuba_exit_grot")].reload.l3.disable = 0;
			Locations[FindLocation("Cuba_exit_grot")].reload.l3.emerge = "reload1";
			Locations[FindLocation("Cuba_Grot")].image = "Inside_Grot.tga";
			Locations[FindLocation("Cuba_Grot")].models.always.locators = "Grot_l";
			DeleteAttribute(&Locations[FindLocation("Cuba_Grot")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Cuba_exit_grot")],"vcskip");
		break;

		case "imperial_escort_after_rescue_havana_port":
			PChar.quest.imperial_escort_after_rescue_havana_town.over = "yes";
			PChar.quest.imperial_escort_after_rescue_santiago_port.over = "yes";
			PChar.quest.imperial_escort_after_rescue_santiago_town.over = "yes";
			PChar.quest.arresters_location = "Cuba_port";
			PChar.quest.arresters_group = "goto";
			PChar.quest.arresters_locator = "goto_16";
			DeleteAttribute(&Locations[FindLocation("Cuba_port")],"vcskip");
			LAi_QuestDelay("imperial_escort_after_rescue_arrest", 0.1);
		break;

		case "imperial_escort_after_rescue_havana_town":
			PChar.quest.imperial_escort_after_rescue_havana_port.over = "yes";
			PChar.quest.imperial_escort_after_rescue_santiago_port.over = "yes";
			PChar.quest.imperial_escort_after_rescue_santiago_town.over = "yes";
			PChar.quest.arresters_location = "Havana_town_05";
			PChar.quest.arresters_group = "goto";
			PChar.quest.arresters_locator = "goto_18";
			DeleteAttribute(&Locations[FindLocation("Cuba_port")],"vcskip");
			LAi_QuestDelay("imperial_escort_after_rescue_arrest", 0.1);
		break;

		case "imperial_escort_after_rescue_santiago_port":
			PChar.quest.imperial_escort_after_rescue_santiago_town.over = "yes";
			PChar.quest.arresters_location = "Santiago_port";
			PChar.quest.arresters_group = "goto";
			if (PChar.location.from_sea == "Cuba_shore_02") PChar.quest.arresters_locator = "goto27";
			else PChar.quest.arresters_locator = "goto7";
			LAi_QuestDelay("imperial_escort_after_rescue_arrest", 0.1);
		break;

		case "imperial_escort_after_rescue_santiago_town":
			PChar.quest.imperial_escort_after_rescue_santiago_port.over = "yes";
			PChar.quest.arresters_location = "Santiago_town_01";
			PChar.quest.arresters_group = "goto";
			PChar.quest.arresters_locator = "goto49";
			LAi_QuestDelay("imperial_escort_after_rescue_arrest", 0.1);
		break;

		case "imperial_escort_after_rescue_arrest":
			ChangeCharacterAddressGroup(CharacterFromID("Emiliano de Guzmán"), "Santiago_townhall", "goto", "goto3");
			LAi_SetHuberStayType(CharacterFromID("Emiliano de Guzmán"));
			TakeItemFromCharacter(CharacterFromID("Emiliano de Guzmán"), FindCharacterItemByGroup(CharacterFromID("Emiliano de Guzmán"), BLADE_ITEM_TYPE));
			if (ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(CharacterFromID("Emiliano de Guzmán"),"bladeC17+2");
				EquipCharacterByItem(CharacterFromID("Emiliano de Guzmán"),"bladeC17+2");
			}
			else
			{
				GiveItem2Character(CharacterFromID("Emiliano de Guzmán"),"bladeC17");
				EquipCharacterByItem(CharacterFromID("Emiliano de Guzmán"),"bladeC17");
			}
			if (!CheckCharacterItem(CharacterFromID("Emiliano de Guzmán"), "goldarmor"))
			{
				GiveItem2Character(CharacterFromID("Emiliano de Guzmán"), "goldarmor");
				EquipCharacterByItem(CharacterFromID("Emiliano de Guzmán"), "goldarmor");
			}
			Characters[GetCharacterIndex("Emiliano de Guzmán")].perks.list.BasicDefence = true;		// Need to assign abilities here because levelling system fouls them up earlier
			Characters[GetCharacterIndex("Emiliano de Guzmán")].perks.list.AdvancedDefence = true;
			Characters[GetCharacterIndex("Emiliano de Guzmán")].perks.list.SwordplayProfessional = true;
			Characters[GetCharacterIndex("Emiliano de Guzmán")].perks.list.CriticalHit = true;
			NPChar = CharacterFromID("Imperial_envoy");
			if (NPChar.location != PChar.location)
			{
				PlaceCharacter(NPChar, "goto");
				LAi_SetActorType(NPChar);
				LAi_ActorFollowEverywhere(NPChar, "", 5.0);
			}
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], true);

			for (n=1; n<=4; n++)
			{

				sld = CharacterFromID("Spanish_soldier" + n);
				ChangeCharacterAddressGroup(sld, PChar.location, PChar.quest.arresters_group, PChar.quest.arresters_locator);
				if (n == 1) SetModelFromID(sld, Nations[SPAIN].fantomModel.m0);
				else
				{
					temp = "m" + (rand(5) + 1);
					SetModelFromID(sld, Nations[SPAIN].fantomModel.(temp));
				}
				sld.Dialog.Filename = "guard_dialog.c";
				LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
				GiveSoldierWeapon(sld, SPAIN);
				sld.nation = SPAIN;
				DeleteAttribute(sld, "questchar");
				SetRandomNameToCharacter(sld);
				sld.questchar = true;
				LAi_SetActorType(sld);
				LAi_ActorFollow(sld, PChar, "", 60.0);
			}

			sld = CharacterFromID("Spanish_soldier1");
			if(PChar.location == "Santiago_port" || PChar.location == "Santiago_town_01")
			{
				sld.dialog.CurrentNode = "imperial_escort_santiago_arrest";
				LAi_SetActorType(sld);
				LAi_ActorDialog(sld,PChar,"imperial_escort_after_rescue_arrest2",60.0,60.0);
			}
			else
			{
				sld.dialog.CurrentNode = "imperial_escort_havana_arrest";
				LAi_SetActorType(sld);
				LAi_ActorDialog(sld,PChar,"imperial_escort_brought_to_admiral",60.0,60.0);
			}
		break;

		case "imperial_escort_after_rescue_arrest2":
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "santiago_guard";
			LAi_ActorDialog(NPChar, PChar, "imperial_escort_after_rescue_arrest3", 5.0, 5.0);
//			LAi_ActorDialogNow(NPChar, PChar,"imperial_escort_after_rescue_arrest3",1.0);
		break;

		case "imperial_escort_after_rescue_arrest3":
			sld = CharacterFromID("Spanish_soldier1");
			sld.dialog.CurrentNode = "imperial_escort_santiago_arrest2";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld,PChar,"imperial_escort_after_rescue_arrest4",5.0,5.0);
		break;

		case "imperial_escort_after_rescue_arrest4":
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "santiago_guard2";
			LAi_ActorDialogNow(NPChar, PChar,"imperial_escort_after_rescue_arrest5",1.0);
		break;

		case "imperial_escort_after_rescue_arrest5":
			sld = CharacterFromID("Spanish_soldier1");
			sld.dialog.CurrentNode = "imperial_escort_santiago_arrest3";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld,PChar,"imperial_escort_after_rescue_onto_townhall",5.0,5.0);
		break;

		case "imperial_escort_after_rescue_onto_townhall":
			EndQuestMovie();
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], false);
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 1;	// Lock Santiago townhall so you can't go in before talking to Electress Maria Antonia
			for (n=1; n<=4; n++)
			{
				sld = CharacterFromID("Spanish_soldier" + n);
				LAi_SetActorType(sld);
          			LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 120.0);
			}
//			DeleteQuestAttribute("arresterid");
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "santiago_on_to_townhall";
			LAi_ActorDialog(NPChar, PChar, "imperial_escort_after_rescue_onto_townhall2", 5.0, 5.0);
		break;

		case "imperial_escort_after_rescue_onto_townhall2":
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			LAi_ActorFollowEverywhere(NPChar, "", 5.0);
			LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);

			Preprocessor_AddQuestData("evilgov", GetMyFullName(CharacterFromID("Emiliano de Guzmán")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 42);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("evilgov");

			PChar.quest.imperial_escort_after_rescue_onto_townhall3.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_after_rescue_onto_townhall3.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.imperial_escort_after_rescue_onto_townhall3.win_condition.l1.locator_group = "reload";
			PChar.quest.imperial_escort_after_rescue_onto_townhall3.win_condition.l1.locator = "reload4";
			PChar.quest.imperial_escort_after_rescue_onto_townhall3.win_condition = "imperial_escort_after_rescue_onto_townhall3";
		break;

		case "imperial_escort_after_rescue_onto_townhall3":
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload4 = 1.0;
			LAi_SetActorType(PChar);
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_ActorTurnToCharacter(PChar,NPChar);
			LAi_ActorWaitDialog(PChar, NPChar);
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "santiago_townhall_approach";
			LAi_ActorDialog(NPChar, PChar, "imperial_escort_after_rescue_onto_townhall4", 5.0, 5.0);
		break;

		case "imperial_escort_after_rescue_onto_townhall4":
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 0;	// Unlock Santiago townhall so you can confront Emiliano de Guzmán
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload4 = 1.0;
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Imperial_envoy"));

			Characters[GetCharacterIndex("Emiliano de Guzmán")].dialog.CurrentNode = "revenge";
			PChar.quest.imperial_escort_setup_guzman.win_condition.l1 = "location";
			PChar.quest.imperial_escort_setup_guzman.win_condition.l1.location = "Santiago_townhall";
			PChar.quest.imperial_escort_setup_guzman.win_condition = "imperial_escort_setup_guzman";

			PChar.quest.imperial_escort_guzman_defeated_1.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_guzman_defeated_1.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.imperial_escort_guzman_defeated_1.win_condition.l1.locator_group = "reload";
			PChar.quest.imperial_escort_guzman_defeated_1.win_condition.l1.locator = "reload4";
			PChar.quest.imperial_escort_guzman_defeated_1.win_condition.l2 = "NPC_Death";
			PChar.quest.imperial_escort_guzman_defeated_1.win_condition.l2.character = "Emiliano de Guzmán";
			PChar.quest.imperial_escort_guzman_defeated_1.win_condition = "imperial_escort_guzman_defeated_1";
		break;

		case "imperial_escort_brought_to_admiral":
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], false);
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload4 = 1.0;	// Was set to 3.0 in case you went there first with Maria Antonia, not needed now
			if(GetDayTime() == DAY_TIME_NIGHT)
			{
				WaitDate("", 0, 0, 1, 0, 0);
				SetCurrentTime(10, 0);
			}
			DoQuestReloadToLocation("Havana_House_03", "reload", "reload1", "imperial_escort_brought_to_admiral2");
		break;

		case "imperial_escort_brought_to_admiral2":
			NPChar = CharacterFromID("Imperial_envoy");
			ChangeCharacterAddressGroup(NPChar,"Havana_House_03", "goto", "goto1");
			LAi_SetActorType(NPChar);
			LAi_ActorFollowEverywhere(NPChar, "", 5.0);
//			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto4");
//			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto6");
//			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[SPAIN].fantomModel.m0, "goto", "goto7");
//			PChar.quest.arresterid = sld.id;
//			sld.name = PChar.quest.imperial_escort.arrester_name;
//			sld.lastname = PChar.quest.imperial_escort.arrester_lastname;
			ChangeCharacterAddressGroup(CharacterFromID("Spanish_soldier1"), "Havana_House_03", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("Spanish_soldier2"), "Havana_House_03", "goto", "goto4");
			ChangeCharacterAddressGroup(CharacterFromID("Spanish_soldier3"), "Havana_House_03", "goto", "goto6");
			ChangeCharacterAddressGroup(CharacterFromID("Spanish_soldier4"), "Havana_House_03", "goto", "goto7");
			LAi_type_actor_Reset(CharacterFromID("Spanish_soldier2"));
			LAi_type_actor_Reset(CharacterFromID("Spanish_soldier3"));
			LAi_type_actor_Reset(CharacterFromID("Spanish_soldier4"));
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto8", "imperial_escort_brought_to_admiral3", 25.0);
		break;

		case "imperial_escort_brought_to_admiral3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Jusepe Guimaraes"));
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_youre_back";
			LAi_ActorDialogNow(CharacterFromID("Jusepe Guimaraes"), PChar,"imperial_escort_envoy_to_admiral",1.0);
		break;

		case "imperial_escort_envoy_to_admiral":
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "believe_ardent";
			LAi_ActorDialogNow(NPChar, PChar,"imperial_escort_admiral_to_envoy",1.0);
		break;

		case "imperial_escort_admiral_to_envoy":
			LAi_SetActorType(CharacterFromID("Jusepe Guimaraes"));
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_good_case";
			LAi_ActorDialogNow(CharacterFromID("Jusepe Guimaraes"), PChar,"imperial_escort_envoy_demands_justice",1.0);
		break;

		case "imperial_escort_envoy_demands_justice":
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "demand_justice";
			LAi_ActorDialogNow(NPChar, PChar,"imperial_escort_restoration",1.0);
		break;

		case "imperial_escort_restoration":
			SetRank(PChar, SPAIN, sti(PChar.quest.imperial_escort.old_spain_rank));
			SetRMRelation(PChar, SPAIN, stf(PChar.quest.imperial_escort.old_spain_relation));
			if(CheckAttribute(PChar, "quest.imperial_escort.land"))
			{
				makearef(pchar_land, PChar.land);
				makearef(pchar_quest_land, PChar.quest.imperial_escort.land);
				CopyAttributes(pchar_land, pchar_quest_land);
			}

			if(CheckAttribute(PChar, "quest.imperial_escort.old_knighted"))
			{
				PChar.knighted = PChar.quest.imperial_escort.old_knighted;
				SetRankTitle(PChar, TranslateString("", PChar.quest.imperial_escort.old_title));
			}
			RestorePassengers(PChar.id);

			if (isofficer(CharacterFromID("Jaime Lezcano")))
			{
				SetCharacterRemovable(CharacterFromID("Jaime Lezcano"), true);
				Characters[GetCharacterIndex("Jaime Lezcano")].dialog.Filename = "Enc_Officer_dialog.c";
				Characters[GetCharacterIndex("Jaime Lezcano")].dialog.CurrentNode = "hired";
			}

			PChar.quest.imperial_escort.grigorio_ship = "None";
			PChar.quest.imperial_escort.galleon = "None";

			i = 0;
			for (n=1; n<COMPANION_MAX; n++)
			{
				attr = "quest.imperial_escort.companion" + n;
				if (GetAttribute(PChar, attr) != "*NULL*" && GetAttribute(PChar, attr) != "-1") i++;
			}
			PChar.quest.imperial_escort.original_companions_number = i;

			for (n = COMPANION_MAX - 1; n >= 0; n--)
			{
				cidx = GetCompanionIndex(GetMainCharacter(), n);
				if (cidx >= 0)
				{
					crewref = GetCharacter(cidx);
					if (GetCharacterShipID(crewref) == "Barque1" && CheckAttribute(crewref, "id")) PChar.quest.imperial_escort.grigorio_ship = crewref.id;
					if (GetCharacterShipID(crewref) == "FastGalleon5" && CheckAttribute(crewref, "id")) PChar.quest.imperial_escort.galleon = crewref.id;
				}
			}
	
			makeref(ImpShip,ShipsTypes[GetShipIndex("FastGalleon5")]);	// Remove Holy Roman Empire from general "FastGalleon5"
//			DeleteAttribute(ImpShip, "EmblemedSails.normalTex");
//			DeleteAttribute(ImpShip, "EmblemedSails.nationFileName");
			DeleteAttribute(ImpShip, "EmblemedSails");

			LAi_SetActorType(CharacterFromID("Jusepe Guimaraes"));
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_that_seems_fair";
			LAi_ActorDialogNow(CharacterFromID("Jusepe Guimaraes"), PChar,"imperial_escort_envoy_to_admiral_again",1.0);		// Exits, triggers "imperial_escort_go_get_guzman" if Emiliano de Guzmán is still alive

// See cases "imperial_escort_admiral_leaves2" and "imperial_escort_ships_impounded"
		break;

		case "imperial_escort_envoy_to_admiral_again":
			if(PChar.quest.imperial_escort.galleon != "None")
			{
				NPChar = CharacterFromID("Imperial_envoy");
				LAi_SetActorType(NPChar);
				NPChar.Dialog.CurrentNode = "keep_galleon";
				LAi_ActorDialogNow(NPChar, PChar, "", 1.0);	// If you have the 'San Lorenzo', exits to "imperial_escort_keep_galleon" or "imperial_escort_admiral_restores_ships"
			}
			else LAi_QuestDelay("imperial_escort_farewell_envoy", 0.1);
		break;

		case "imperial_escort_go_get_guzman":
			Preprocessor_AddQuestData("evilgov", GetMyFullName(CharacterFromID("Emiliano de Guzmán")));
			Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			AddQuestRecord("Imperial Escort", 47);
			Preprocessor_Remove("admiral");
			Preprocessor_Remove("evilgov");
			PChar.quest.imperial_escort.arrest_guzman = true;
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 0;		// Unlock Santiago townhall so you can confront Emiliano de Guzmán
			Locations[FindLocation("Santiago_town_01")].reload.l4.close_for_night = 0;	// by day or night
			Characters[GetCharacterIndex("Emiliano de Guzmán")].dialog.CurrentNode = "arrest";
			LAi_QuestDelay("imperial_escort_soldiers_join", 0.5);
			PChar.quest.imperial_escort_setup_guzman.win_condition.l1 = "location";
			PChar.quest.imperial_escort_setup_guzman.win_condition.l1.location = "Santiago_townhall";
			PChar.quest.imperial_escort_setup_guzman.win_condition = "imperial_escort_setup_guzman";

//			PChar.quest.imperial_escort_guzman_defeated_2.win_condition.l1 = "NPC_Death";
//			PChar.quest.imperial_escort_guzman_defeated_2.win_condition.l1.character = "Emiliano de Guzmán";
//			PChar.quest.imperial_escort_guzman_defeated_2.win_condition = "imperial_escort_guzman_defeated_2";
		break;

		case "imperial_escort_keep_galleon":
			PChar.quest.imperial_escort.keep_galleon = true;
			LAi_SetActorType(CharacterFromID("Jusepe Guimaraes"));
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_deny_galleon";
			LAi_ActorDialogNow(CharacterFromID("Jusepe Guimaraes"), PChar,"imperial_escort_envoy_insists_galleon",1.0);
		break;

		case "imperial_escort_envoy_insists_galleon":
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "report_admiral_good";
			LAi_ActorDialogNow(NPChar, PChar,"imperial_escort_admiral_flattered",1.0);
		break;

		case "imperial_escort_admiral_flattered":
			LAi_SetActorType(CharacterFromID("Jusepe Guimaraes"));
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_flattered";
			LAi_ActorDialogNow(CharacterFromID("Jusepe Guimaraes"), PChar,"imperial_escort_envoy_insists_galleon2",1.0);
		break;

		case "imperial_escort_envoy_insists_galleon2":
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "report_admiral_bad";
			LAi_ActorDialogNow(NPChar, PChar,"imperial_escort_admiral_allows_galleon",1.0);
		break;

		case "imperial_escort_admiral_allows_galleon":
			LAi_SetActorType(CharacterFromID("Jusepe Guimaraes"));
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_find_new_ship";
			LAi_ActorDialogNow(CharacterFromID("Jusepe Guimaraes"), PChar,"imperial_escort_farewell_envoy",1.0);
		break;

		case "imperial_escort_farewell_envoy":
			NPChar = CharacterFromID("Imperial_envoy");
			RemovePassenger(PChar, NPChar);
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "farewell";
			LAi_ActorDialogNow(NPChar, PChar,"imperial_escort_admiral_restores_ships",1.0);
		break;

		case "imperial_escort_admiral_restores_ships":
			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
          		LAi_ActorGoToLocation(NPChar, "reload", "reload1", "none", "", "", "", 60.0);
			SetCharacterShipLocation(CharacterFromID("Imperial_Captain"), "None");
			ChangeCharacterAddress(CharacterFromID("Imperial_Captain"), "None", "");
			LAi_SetActorType(CharacterFromID("Jusepe Guimaraes"));
			Characters[GetCharacterIndex("Jusepe Guimaraes")].dialog.CurrentNode = "imperial_escort_payment";
			LAi_ActorDialogNow(CharacterFromID("Jusepe Guimaraes"), PChar,"imperial_escort_end",1.0);	// All code for restoring ships is in "Jusepe Guimaraes_dialog.c"
		break;

		case "imperial_escort_end":
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 44);
			Preprocessor_Remove("envoy");
			EndQuestMovie();
			DisableFastTravel(false);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 10000);
				AddPartyExpChar(PChar, "", 5000);
				AddPartyExpChar(PChar, "Sneak", 5000);
			}
			else {AddPartyExp(PChar, 20000);}
			LAi_SetHuberStayType(CharacterFromID("Jusepe Guimaraes"));

			PChar.quest.imperial_escort_end2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.imperial_escort_end2.win_condition.l1.location = PChar.location;
			Pchar.quest.imperial_escort_end2.win_condition = "imperial_escort_end2";
		break;

		case "imperial_escort_end2":
			LAi_SetHuberType(CharacterFromID("Jusepe Guimaraes"));
			if (!CheckAttribute(PChar, "quest.imperial_escort.arrest_guzman") || sti(PChar.quest.imperial_escort.arrest_guzman) != true)
			{
				LAi_QuestDelay("imperial_escort_remove_soldiers", 0.1);
				Preprocessor_AddQuestData("evilgov", GetMyFullName(CharacterFromID("Emiliano de Guzmán")));
				Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
				AddQuestRecord("Imperial Escort", 49);
				Preprocessor_Remove("governor");
				Preprocessor_Remove("evilgov");
				CloseQuestHeader("Imperial Escort");
			}
		break;

		case "imperial_escort_soldiers_join":
			for (n=1; n<=4; n++)
			{

				sld = CharacterFromID("Spanish_soldier" + n);
//				PlaceCharacter(sld, "goto");
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
				LAi_SetActorType(sld);
				LAi_ActorFollowEverywhere(sld, "", 10.0);
			}
			PChar.quest.imperial_escort_soldiers_detach.win_condition.l1 = "location";
			PChar.quest.imperial_escort_soldiers_detach.win_condition.l1.location = "Cuba";
			PChar.quest.imperial_escort_soldiers_detach.win_condition = "imperial_escort_soldiers_detach";
		break;

		case "imperial_escort_soldiers_detach":
			for (n=1; n<=4; n++)
			{

				sld = CharacterFromID("Spanish_soldier" + n);
				LAi_type_actor_Reset(sld);
				ChangeCharacterAddress(sld, "None", "");
			}

			PChar.quest.imperial_escort_soldiers_rejoin1.win_condition.l1 = "location";
			PChar.quest.imperial_escort_soldiers_rejoin1.win_condition.l1.location = "Cuba_shore_02";	// Bahia de Moa
			PChar.quest.imperial_escort_soldiers_rejoin1.win_condition = "imperial_escort_soldiers_rejoin";

			PChar.quest.imperial_escort_soldiers_rejoin2.win_condition.l1 = "location";
			PChar.quest.imperial_escort_soldiers_rejoin2.win_condition.l1.location = "Cuba_shore_05";	// Playa de Sierra Maestra
			PChar.quest.imperial_escort_soldiers_rejoin2.win_condition = "imperial_escort_soldiers_rejoin";

			PChar.quest.imperial_escort_soldiers_rejoin3.win_condition.l1 = "location";
			PChar.quest.imperial_escort_soldiers_rejoin3.win_condition.l1.location = "Santiago_port";
			PChar.quest.imperial_escort_soldiers_rejoin3.win_condition = "imperial_escort_soldiers_rejoin";
		break;

		case "imperial_escort_soldiers_rejoin":
			PChar.quest.imperial_escort_soldiers_rejoin1.over = "yes";
			PChar.quest.imperial_escort_soldiers_rejoin2.over = "yes";
			PChar.quest.imperial_escort_soldiers_rejoin3.over = "yes";

			for (n=1; n<=4; n++)
			{

				sld = CharacterFromID("Spanish_soldier" + n);
				PlaceCharacter(sld, "goto");
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
				LAi_SetActorType(sld);
				LAi_ActorFollowEverywhere(sld, "", 10.0);
			}
			DisableFastTravel(true);
			bQuestDisableSeaEnter = true;
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload4 = 3.0;
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 1;	// Lock Santiago townhall so you can't go in before talking to soldiers

			PChar.quest.imperial_escort_soldiers_outside_townhall.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_soldiers_outside_townhall.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.imperial_escort_soldiers_outside_townhall.win_condition.l1.locator_group = "reload";
			PChar.quest.imperial_escort_soldiers_outside_townhall.win_condition.l1.locator = "reload4";
			PChar.quest.imperial_escort_soldiers_outside_townhall.win_condition = "imperial_escort_soldiers_outside_townhall";
		break;

		case "imperial_escort_soldiers_outside_townhall":
			Locations[FindLocation("Santiago_town_01")].locators_radius.reload.reload4 = 1.0;
			for (n=2; n<=4; n++)
			{

				sld = CharacterFromID("Spanish_soldier" + n);
				LAi_SetActorType(sld);
				LAi_ActorFollow(sld, CharacterFromID("Spanish_soldier1"), "", 10.0);
			}
			LAi_SetActorType(CharacterFromID("Spanish_soldier1"));
			Characters[GetCharacterIndex("Spanish_soldier1")].dialog.CurrentNode = "imperial_escort_outside_santiago_townhall";
			LAi_ActorDialog(CharacterFromID("Spanish_soldier1"), PChar,"imperial_escort_soldiers_outside_townhall2",5.0, 5.0);
		break;

		case "imperial_escort_soldiers_outside_townhall2":
			Locations[FindLocation("Santiago_town_01")].reload.l4.disable = 0;	// Unlock Santiago townhall so you can confront Emiliano de Guzmán
			LAi_type_actor_Reset(CharacterFromID("Spanish_soldier1"));
			LAi_type_actor_Reset(CharacterFromID("Spanish_soldier2"));
			LAi_SetActorType(CharacterFromID("Spanish_soldier3"));
			LAi_SetActorType(CharacterFromID("Spanish_soldier4"));
          		LAi_ActorGoToLocation(CharacterFromID("Spanish_soldier3"), "reload", "reload4", "None", "", "", "", 20.0);
          		LAi_ActorGoToLocation(CharacterFromID("Spanish_soldier4"), "reload", "reload4", "None", "", "", "", 20.0);

			PChar.quest.imperial_escort_guzman_defeated_2.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_guzman_defeated_2.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.imperial_escort_guzman_defeated_2.win_condition.l1.locator_group = "reload";
			PChar.quest.imperial_escort_guzman_defeated_2.win_condition.l1.locator = "reload4";
			PChar.quest.imperial_escort_guzman_defeated_2.win_condition.l2 = "NPC_Death";
			PChar.quest.imperial_escort_guzman_defeated_2.win_condition.l2.character = "Emiliano de Guzmán";
			PChar.quest.imperial_escort_guzman_defeated_2.win_condition = "imperial_escort_guzman_defeated_2";
		break;

		case "imperial_escort_setup_guzman":
			ChangeCharacterAddress(CharacterFromID("Spanish_soldier1"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Spanish_soldier2"), "None", "");
			ChangeCharacterAddressGroup(CharacterFromID("Spanish_soldier3"), "Santiago_townhall", "goto", "goto11");
			ChangeCharacterAddressGroup(CharacterFromID("Spanish_soldier4"), "Santiago_townhall", "goto", "goto12");
			LAi_type_actor_Reset(CharacterFromID("Spanish_soldier3"));
			LAi_type_actor_Reset(CharacterFromID("Spanish_soldier4"));
		break;

		case "imperial_escort_fight_guzman":	// Triggered by dialog with Emiliano de Guzmán
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_townhall")], false);
			LAi_SetActorType(CharacterFromID("Emiliano de Guzmán"));
			LAi_SetImmortal(CharacterFromID("Emiliano de Guzmán"), false);
			LAi_NoRebirthEnable(CharacterFromID("Emiliano de Guzmán"));
			LAi_group_MoveCharacter(CharacterFromID("Emiliano de Guzmán"), LAI_GROUP_MONSTERS);
			if (CheckAttribute(PChar, "quest.imperial_escort.guards_join_guzman") && sti(PChar.quest.imperial_escort.guards_join_guzman) == true)
			{
				LAi_group_MoveCharacter(CharacterFromID("Spanish_soldier3"), LAI_GROUP_MONSTERS);
				LAi_group_MoveCharacter(CharacterFromID("Spanish_soldier4"), LAI_GROUP_MONSTERS);
			}
			LAi_group_SetRelation(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_MONSTERS, "imperial_escort_guzman_fight_over");
		break;

		case "imperial_escort_guzman_fight_over":
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_townhall")], true);
		break;

		case "imperial_escort_guzman_defeated_1":
			NPChar = CharacterFromID("Imperial_envoy");
			PlaceCharacter(NPChar, "goto");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "guzman_dead_goto_havana";
			LAi_ActorDialog(NPChar, PChar, "imperial_escort_guzman_defeated_1a", 5.0, 5.0);
		break;

		case "imperial_escort_guzman_defeated_1a":
			Preprocessor_AddQuestData("evilgov", GetMyFullName(CharacterFromID("Emiliano de Guzmán")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 43);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("evilgov");

			NPChar = CharacterFromID("Imperial_envoy");
			LAi_SetActorType(NPChar);
			LAi_ActorFollowEverywhere(NPChar, "", 5.0);
			LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);
			DisableFastTravel(false);
		break;

		case "imperial_escort_guzman_defeated_2":
			Preprocessor_AddQuestData("evilgov", GetMyFullName(CharacterFromID("Emiliano de Guzmán")));
			Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			AddQuestRecord("Imperial Escort", 48);
			Preprocessor_Remove("admiral");
			Preprocessor_Remove("evilgov");
			DisableFastTravel(false);
			bQuestDisableSeaEnter = false;
			Locations[FindLocation("Santiago_town_01")].reload.l4.close_for_night = 1;	// Townhall back to closing at night

			sld = CharacterFromID("Spanish_soldier1");
			PlaceCharacter(sld, "goto");
			LAi_SetActorType(sld);
			sld.Dialog.CurrentNode = "imperial_escort_after_santiago_townhall";
			LAi_ActorDialog(sld, PChar, "imperial_escort_guzman_defeated_2a", 5.0, 5.0);

			PChar.quest.imperial_escort_remove_soldiers.win_condition.l1 = "ExitFromLocation";
			PChar.quest.imperial_escort_remove_soldiers.win_condition.l1.location = PChar.location;
			Pchar.quest.imperial_escort_remove_soldiers.win_condition = "imperial_escort_remove_soldiers";
		break;

		case "imperial_escort_guzman_defeated_2a":
			LAi_SetActorType(CharacterFromID("Spanish_soldier1"));
          		LAi_ActorGoToLocation(CharacterFromID("Spanish_soldier1"), "reload", "reload4", "None", "", "", "", 20.0);
		break;

		case "imperial_escort_remove_soldiers":
			for (n=1; n<=4; n++)
			{

				sld = CharacterFromID("Spanish_soldier" + n);
				LAi_type_actor_Reset(sld);
				ChangeCharacterAddress(sld, "None", "");
			}
		break;

		case "imperial_escort_restore_santiago_governor":	// Triggered by dialog with Jusepe Guimaraes
			NPChar = CharacterFromID("Javier Balboa");
			ChangeCharacterAddress(CharacterFromID("Emiliano de Guzmán"), "none", "");
			ChangeCharacterAddressGroup(NPChar, "Santiago_townhall", "sit", "sit1");
			LAi_SetHuberType(NPChar);
			Towns[GetTownIndex("Santiago")].gov = "Javier Balboa";
			Preprocessor_AddQuestData("evilgov", GetMyFullName(CharacterFromID("Emiliano de Guzmán")));
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Imperial Escort", 49);
			Preprocessor_Remove("governor");
			Preprocessor_Remove("evilgov");
			CloseQuestHeader("Imperial Escort");
		break;

		case "imperial_escort_go_get_spy":			// Triggered by dialog with Jusepe Guimaraes if Gilles Clouzot is in San Juan port
			PChar.quest.imperial_escort.spy_search = "find_spy";
			Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			Preprocessor_AddQuestData("docker", GetMyFullName(CharacterFromID("Uasco Mazinho")));
			Preprocessor_AddQuestData("spy", "Gilles Clouzot");
			SetQuestHeader("Remove Spy");
			AddQuestRecord("Remove Spy", 1);
			Preprocessor_Remove("spy");
			Preprocessor_Remove("docker");
			Preprocessor_Remove("admiral");
			GiveItem2Character(PChar, "AdmiralLetter");
		break;

		case "imperial_escort_prepare_lure_spy_aboard":		// Triggered by dialog with Christofor Manuel de Alencar
			Preprocessor_AddQuestData("docker", GetMyFullName(CharacterFromID("Uasco Mazinho")));
			Preprocessor_AddQuestData("spy", "Gilles Clouzot");
			AddQuestRecord("Remove Spy", 2);
			Preprocessor_Remove("spy");
			Preprocessor_Remove("docker");
			PChar.quest.imperial_escort.spy_search = "lure_spy_aboard";
			sld = CharacterFromID("Gilles Clouzot");
			sld.Dialog.Filename = "Gilles Clouzot_dialog.c";
			sld.Dialog.CurrentNode = "imperial_escort_fake_uasco";
			sld.greeting = "Gr_isla muelle citizen";
			LAi_SetCitizenType(sld);
			LAi_SetImmortal(sld, true);
			Characters[GetCharacterIndex("Jusepe Guimaraes")].Dialog.CurrentNode = "imperial_escort_spy_result";
			Characters[GetCharacterIndex("Jusepe Guimaraes")].Dialog.TempNode = "imperial_escort_spy_result";
		break;

		case "imperial_escort_spy_follows_to_ship":		// Triggered by dialog with Gilles Clouzot posing as Uasco Mazinho
			bQuestDisableSeaEnter = true;
			locations[FindLocation("Muelle_port")].reload.l1.disable = 1;
			LAi_SetActorType(CharacterFromID("Gilles Clouzot"));
			LAi_ActorFollow(CharacterFromID("Gilles Clouzot"), PChar, "", 10.0);
//			LAi_ActorFollowEverywhere(CharacterFromID("Gilles Clouzot"), "", 5.0);

			PChar.quest.imperial_escort_with_spy_to_deck1.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_with_spy_to_deck1.win_condition.l1.location = "Muelle_port";
			PChar.quest.imperial_escort_with_spy_to_deck1.win_condition.l1.locator_group = "reload";
			PChar.quest.imperial_escort_with_spy_to_deck1.win_condition.l1.locator = "reload1_back";
			PChar.quest.imperial_escort_with_spy_to_deck1.win_condition = "imperial_escort_with_spy_to_deck";

			PChar.quest.imperial_escort_with_spy_to_deck3.win_condition.l1 = "locator";
			PChar.quest.imperial_escort_with_spy_to_deck3.win_condition.l1.location = "Muelle_port";
			PChar.quest.imperial_escort_with_spy_to_deck3.win_condition.l1.locator_group = "reload";
			PChar.quest.imperial_escort_with_spy_to_deck3.win_condition.l1.locator = "reload3_back";
			PChar.quest.imperial_escort_with_spy_to_deck3.win_condition = "imperial_escort_with_spy_to_deck";
		break;

		case "imperial_escort_with_spy_to_deck":
			PChar.quest.imperial_escort_with_spy_to_deck1.over = "yes";
			PChar.quest.imperial_escort_with_spy_to_deck3.over = "yes";
			ChangeCharacterAddressGroup(CharacterFromID("Gilles Clouzot"), GetCharacterShipQDeck(PChar), "reload", "reload1");
			DoQuestReloadToLocation(GetCharacterShipQDeck(PChar), "rld", "startloc", "imperial_escort_with_spy_to_deck2");
		break;

		case "imperial_escort_with_spy_to_deck2":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			sld = CharacterFromID("Gilles Clouzot");
			LAi_SetActorType(sld);
//			PlaceCharacter(sld, "goto");
			if (PChar.model == "ArdentM_2" || PChar.model == "ArdentF_2") sld.Dialog.CurrentNode = "imperial_escort_deck_disguised";
			else sld.Dialog.CurrentNode = "imperial_escort_deck";
			LAi_ActorDialog(sld, PChar, "imperial_escort_spy_fight_deck", 10.0, 10.0);
		break;

		case "imperial_escort_spy_fight_deck":
			sld = CharacterFromID("Gilles Clouzot");
			sld.name = TranslateString("", "Gilles");
			sld.lastname = TranslateString("", "Clouzot");
			sld.Dialog.Filename = "Gilles Clouzot_dialog.c";
			sld.greeting = "Gr_Etienne Dupuis";
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			LAi_SetImmortal(sld, false);
			LAi_NoRebirthEnable(sld);

			if(ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(sld, "pistol1a+3");
				EquipCharacterByItem(sld,"pistol1a+3");
			}
			else
			{
				GiveItem2Character(sld, "pistol1a");
				EquipCharacterByItem(sld,"pistol1a");
			}
			GiveItem2Character(sld, "Piratesdagger");
			EquipCharacterByItem(sld,"Piratesdagger");
			LAi_SetActorType(sld);
			LAi_ActorAttack(sld, PChar, "");
			PChar.quest.imperial_escort_spy_defeated.win_condition.l1 = "NPC_Death";
			PChar.quest.imperial_escort_spy_defeated.win_condition.l1.character = "Gilles Clouzot";
			PChar.quest.imperial_escort_spy_defeated.win_condition = "imperial_escort_spy_defeated";
		break;

		case "imperial_escort_spy_defeated":
			PChar.quest.imperial_escort.spy_search = "spy_dead_aboard";
			DoQuestReloadToLocation("Hold1", "rld", "startloc", "imperial_escort_to_uasco_after_spy_defeated");
		break;

		case "imperial_escort_to_uasco_after_spy_defeated":
			Characters[GetCharacterIndex("Uasco Mazinho")].Dialog.Filename = "quest_Uasco Mazinho_dialog.c";
			Characters[GetCharacterIndex("Uasco Mazinho")].Dialog.CurrentNode = "imperial_escort_release";
			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Uasco Mazinho"), "imperial_escort_release_uasco_after_spy_defeated", 10.0, 10.0);
		break;

		case "imperial_escort_release_uasco_after_spy_defeated":
			Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			Preprocessor_AddQuestData("docker", GetMyFullName(CharacterFromID("Uasco Mazinho")));
			Preprocessor_AddQuestData("spy", GetMyFullName(CharacterFromID("Gilles Clouzot")));
			AddQuestRecord("Remove Spy", 4);
			Preprocessor_Remove("spy");
			Preprocessor_Remove("docker");
			Preprocessor_Remove("admiral");
			LAi_SetPlayerType(PChar);
			EndQuestMovie();
			DisableFastTravel(false);
			locations[FindLocation("Muelle_port")].reload.l1.disable = 0;
			bQuestDisableSeaEnter = false;
			Characters[GetCharacterIndex("Christofor Manuel De Alencar")].Dialog.CurrentNode = "ardent_imperial_escort_after_spy";
			ChangeCharacterAddressGroup(CharacterFromID("Uasco Mazinho"), "Muelle_port", "goto", "goto5");
			DoQuestReloadToLocation("Muelle_port", "reload", "reload3_back", "imperial_escort_uasco_is_going_home");
		break;

		case "imperial_escort_uasco_is_going_home":
			NPChar = CharacterFromID("Uasco Mazinho");
			LAi_SetCitizenType(NPChar);
			LAi_group_MoveCharacter(NPChar, "SPAIN_CITIZENS");
			NPChar.Dialog.Filename = "Isla Muelle citizen_dialog.c";
			NPChar.Dialog.CurrentNode = "First time";
			NPChar.quest.meeting = "1";
			LAi_SetLoginTime(NPChar, 6.0, 22.0);
		break;

		case "imperial_escort_prepare_bring_uasco_ashore":	// Triggered by dialog with Christofor Manuel de Alencar
			Preprocessor_AddQuestData("docker", GetMyFullName(CharacterFromID("Uasco Mazinho")));
			Preprocessor_AddQuestData("spy", "Gilles Clouzot");
			AddQuestRecord("Remove Spy", 3);
			Preprocessor_Remove("spy");
			Preprocessor_Remove("docker");

			bQuestDisableSeaEnter = true;
			PChar.quest.imperial_escort.spy_search = "bring_uasco_ashore";
			Characters[GetCharacterIndex("Uasco Mazinho")].Dialog.Filename = "quest_Uasco Mazinho_dialog.c";
			Characters[GetCharacterIndex("Uasco Mazinho")].Dialog.CurrentNode = "imperial_escort_release";
			Characters[GetCharacterIndex("Jusepe Guimaraes")].Dialog.CurrentNode = "imperial_escort_spy_result";
			Characters[GetCharacterIndex("Jusepe Guimaraes")].Dialog.TempNode = "imperial_escort_spy_result";
		break;

		case "imperial_escort_uasco_follow_ashore":		// Triggered by dialog with Uasco Mazinho
			LAi_SetActorType(CharacterFromID("Uasco Mazinho"));
			LAi_ActorAnimation(CharacterFromID("Uasco Mazinho"), "Ground_StandUp", "imperial_escort_uasco_follow_ashore2", 3.5);
			PChar.quest.imperial_escort_soldiers_ready_for_spy_arrest.win_condition.l1 = "location";
			PChar.quest.imperial_escort_soldiers_ready_for_spy_arrest.win_condition.l1.location = "Muelle_port";
			PChar.quest.imperial_escort_soldiers_ready_for_spy_arrest.win_condition = "imperial_escort_soldiers_ready_for_spy_arrest";
		break;

		case "imperial_escort_uasco_follow_ashore2":
			NPChar = CharacterFromID("Uasco Mazinho");
			LAi_SetActorType(NPChar);
			LAi_ActorFollowEverywhere(NPChar, "", 5.0);
		break;

		case "imperial_escort_soldiers_ready_for_spy_arrest":
			NPChar = CharacterFromID("Uasco Mazinho");
			if (NPChar.location != PChar.location)
			{
				PlaceCharacter(NPChar, "goto");
				LAi_SetActorType(NPChar);
				LAi_ActorFollowEverywhere(NPChar, "", 5.0);
			}
			locations[FindLocation("Muelle_port")].reload.l1.disable = 1;
			for (n=1; n<=2; n++)
			{

				sld = CharacterFromID("spain_soldier_0" + n);
				StoreDialog(sld);
				sld.Dialog.Filename = "guard_dialog.c";
				sld.Dialog.CurrentNode = "imperial_escort_report_crime";
			}
		break;

		case "imperial_escort_guard_arrests_spy":		// Triggered by dialog with either of the San Juan port guards
			DisableFastTravel(true);
			sld = CharacterFromID(PChar.quest.imperial_escort.spy_arrester);
			NPChar = CharacterFromID("Gilles Clouzot");
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, NPChar);
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, NPChar, "imperial_escort_guard_arrests_spy2", 30.0);
		break;

		case "imperial_escort_guard_arrests_spy2":
			NPChar = CharacterFromID("Gilles Clouzot");
			sld = CharacterFromID(PChar.quest.imperial_escort.spy_arrester);
			LAi_SetActorType(NPChar);
			LAi_ActorFollow(NPChar, CharacterFromID("Uasco Mazinho"), "imperial_escort_mix_uascos", 30.0);
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, NPChar, "", 10.0);
		break;

		case "imperial_escort_mix_uascos":
			StartQuestMovie(true, true, false);
			GiveItem2Character(CharacterFromID("Gilles Clouzot"), "bladeX4");
			EquipCharacterByItem(CharacterFromID("Gilles Clouzot"), "bladeX4");
			GiveItem2Character(CharacterFromID("Uasco Mazinho"), "bladeX4");
			EquipCharacterByItem(CharacterFromID("Uasco Mazinho"), "bladeX4");
			LAi_SetActorType(CharacterFromID("Uasco Mazinho"));
			LAi_SetActorType(CharacterFromID("Gilles Clouzot"));
			LAi_ActorAttack(CharacterFromID("Gilles Clouzot"), CharacterFromID("Uasco Mazinho"), "");
			LAi_ActorAttack(CharacterFromID("Uasco Mazinho"), CharacterFromID("Gilles Clouzot"), "");
			LAi_QuestDelay("imperial_escort_sort_uascos_out", 3.0);
		break;

		case "imperial_escort_sort_uascos_out":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Uasco Mazinho"));
			LAi_SetActorType(CharacterFromID("Gilles Clouzot"));
			LAi_SetActorType(CharacterFromID("spain_soldier_01"));
			LAi_SetActorType(CharacterFromID("spain_soldier_02"));
			sld = CharacterFromID(PChar.quest.imperial_escort.spy_arrester);
			sld.Dialog.CurrentNode = "imperial_escort_which_one_is_spy";
			LAi_ActorDialog(sld, PChar, "imperial_escort_sort_uascos_out2", 10.0, 10.0);
		break;

		case "imperial_escort_sort_uascos_out2":
			if (PChar.quest.imperial_escort.spy_arrester == "spain_soldier_01") sld = CharacterFromID("spain_soldier_02");
			else sld = CharacterFromID("spain_soldier_01");
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, sld);
			LAi_ActorWaitDialog(PChar, sld);
			LAi_SetActorType(sld);
			sld.Dialog.CurrentNode = "imperial_escort_which_one_is_spy2";
			LAi_ActorDialog(sld, PChar, "imperial_escort_sort_uascos_out3", 10.0, 10.0);
		break;

		case "imperial_escort_sort_uascos_out3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Uasco Mazinho"));
			LAi_SetActorType(CharacterFromID("Gilles Clouzot"));
			LAi_SetActorType(CharacterFromID("spain_soldier_01"));
			LAi_ActorGoToLocator(CharacterFromID("spain_soldier_01"), "goto", "goto3", "", 10.0);
			LAi_ActorFollow(CharacterFromID("Gilles Clouzot"), CharacterFromID("spain_soldier_01"), "", 5.0);
			LAi_SetActorType(CharacterFromID("spain_soldier_02"));
			LAi_ActorGoToLocator(CharacterFromID("spain_soldier_02"), "goto", "goto2", "", 10.0);
			LAi_ActorFollow(CharacterFromID("Uasco Mazinho"), CharacterFromID("spain_soldier_02"), "", 5.0);
			LAi_QuestDelay("imperial_escort_uasco1_answer", 10.0);
		break;

		case "imperial_escort_uasco1_answer":
			LAi_SetActorType(CharacterFromID("spain_soldier_01"));
			Characters[GetCharacterIndex("spain_soldier_01")].Dialog.CurrentNode = "imperial_escort_spy_answer1";
			LAi_ActorDialog(CharacterFromID("spain_soldier_01"), PChar, "imperial_escort_uasco2_answer", 10.0, 10.0);
			LAi_SetActorType(CharacterFromID("spain_soldier_02"));
			LAi_ActorFollow(CharacterFromID("spain_soldier_02"), PChar, "", 10.0);
		break;

		case "imperial_escort_uasco2_answer":
			LAi_SetActorType(CharacterFromID("spain_soldier_02"));
			Characters[GetCharacterIndex("spain_soldier_02")].Dialog.CurrentNode = "imperial_escort_spy_answer2";
			LAi_ActorDialog(CharacterFromID("spain_soldier_02"), PChar, "imperial_escort_spy_revealed", 10.0, 10.0);
		break;

		case "imperial_escort_spy_revealed":
			sld = CharacterFromID("Gilles Clouzot");
			sld.name = TranslateString("", "Gilles");
			sld.lastname = TranslateString("", "Clouzot");
			sld.Dialog.Filename = "Gilles Clouzot_dialog.c";
			sld.greeting = "Gr_Etienne Dupuis";
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			LAi_SetImmortal(sld, false);
			LAi_NoRebirthEnable(sld);
			LAi_SetImmortal(CharacterFromID("Uasco Mazinho"), false);
			LAi_SetActorType(CharacterFromID("spain_soldier_01"));
			Characters[GetCharacterIndex("spain_soldier_01")].Dialog.CurrentNode = "imperial_escort_spy_revealed";
			LAi_ActorDialog(CharacterFromID("spain_soldier_01"), PChar, "imperial_escort_spy_revealed2", 10.0, 10.0);
		break;

		case "imperial_escort_spy_revealed2":
			NPChar = (CharacterFromID("Gilles Clouzot"));
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = "imperial_escort_spy_rumbled";
			LAi_ActorDialogNow(NPChar, PChar, "imperial_escort_spy_suicide",1.0);
		break;

		case "imperial_escort_spy_suicide":
			if(ENABLE_WEAPONSMOD)								// Give him some concealed weapons for player to loot
			{
				GiveItem2Character(CharacterFromID("Gilles Clouzot"), "pistol1a+3");
			}
			else
			{
				GiveItem2Character(CharacterFromID("Gilles Clouzot"), "pistol1a");
			}
			GiveItem2Character(CharacterFromID("Gilles Clouzot"), "Piratesdagger");
			PChar.quest.imperial_escort.spy_search = "spy_dead_ashore";
			LAi_KillCharacter(characterfromID("Gilles Clouzot"));
			LAi_SetActorType(CharacterFromID("spain_soldier_01"));
			Characters[GetCharacterIndex("spain_soldier_01")].Dialog.CurrentNode = "imperial_escort_spy_poisoned";
			LAi_ActorDialog(CharacterFromID("spain_soldier_01"), PChar, "imperial_escort_reset_muelle_after_spy_dies", 5.0, 5.0);
		break;

		case "imperial_escort_reset_muelle_after_spy_dies":
			Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			Preprocessor_AddQuestData("docker", GetMyFullName(CharacterFromID("Uasco Mazinho")));
			Preprocessor_AddQuestData("spy", GetMyFullName(CharacterFromID("Gilles Clouzot")));
			AddQuestRecord("Remove Spy", 5);
			Preprocessor_Remove("spy");
			Preprocessor_Remove("docker");
			Preprocessor_Remove("admiral");
			for (n=1; n<=2; n++)
			{

				sld = CharacterFromID("spain_soldier_0" + n);
				RestoreDialog(sld);
				LAi_SetGuardianType(sld);
			}
			bQuestDisableSeaEnter = false;
			EndQuestMovie();
			DisableFastTravel(false);
			locations[FindLocation("Muelle_port")].reload.l1.disable = 0;
			LAi_QuestDelay("imperial_escort_uasco_is_going_home", 0.5);
			Characters[GetCharacterIndex("Christofor Manuel De Alencar")].Dialog.CurrentNode = "ardent_imperial_escort_after_spy";

			PChar.quest.imperial_escort_reset_uasco_locator.win_condition.l1 = "ExitFromLocation";
			PChar.quest.imperial_escort_reset_uasco_locator.win_condition.l1.location = PChar.location;
			Pchar.quest.imperial_escort_reset_uasco_locator.win_condition = "imperial_escort_reset_uasco_locator";
		break;

		case "imperial_escort_reset_uasco_locator":
			ChangeCharacterAddressGroup(CharacterFromID("Uasco Mazinho"), "Muelle_port", "goto", "goto5");
			LAi_SetCitizenType(CharacterFromID("Uasco Mazinho"));
		break;

		case "imperial_escort_spy_reward":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, 50000);
			ChangeRMRelation(PChar, SPAIN, 5.0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 2500);
				AddPartyExpChar(PChar, "", 1250);
				AddPartyExpChar(PChar, "Sneak", 1250);
			}
			else {AddPartyExp(PChar, 5000);}
			TakeItemFromCharacter(PChar, "AdmiralLetter");
			Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			Preprocessor_AddQuestData("spy", GetMyFullName(CharacterFromID("Gilles Clouzot")));
			AddQuestRecord("Remove Spy", 6);
			CloseQuestHeader("Remove Spy");
			Preprocessor_Remove("spy");
			Preprocessor_Remove("admiral");
			Characters[GetCharacterIndex("Jusepe Guimaraes")].Dialog.TempNode = "First time";
			Characters[GetCharacterIndex("Jusepe Guimaraes")].Dialog.CurrentNode = "First time";
		break;


		case "reset_crewmember":
			if (CheckAttribute(PChar, "quest.speaker") && PChar.quest.speaker != "")
			{
				crewref = characterFromID(PChar.quest.speaker);
				crewidx = GetCharacterIndex(PChar.quest.speaker);
				RestoreDialog(crewref);
				LAi_SetOfficerType(CharacterFromId(characters[crewidx].id));
				DeleteQuestAttribute("speaker");
			}
		break;


		case "test":
logit("You have been diverted here for test purposes. Normal service will be resumed as soon as possible.");
		break;

		PChar.questnotfound = true; // PB: Testing
	}
}