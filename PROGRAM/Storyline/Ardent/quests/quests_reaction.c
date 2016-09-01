void QuestComplete(string sQuestName)
{
	ref PChar, sld, ch;
// KK -->
	int iPassenger, cidx, iHP, cc, crew_lost, crew_left, n;
	ref officer1, officer2, romance, villain, arrester, crewid;
	int officer1idx, officer2idx, romanceidx, villainidx, arresteridx, crewidx;
	float locx, locy, locz;
	string speaker, homelocation, homegroup, homelocator, gov_kid, merch_kid, romance_name, villain_name, normal_dialog, romance_pronoun1, romance_pronoun2, villain_pronoun;
	int canQty = 0;
	int crewQty = 0;
	int survivors = 0;
// <-- KK
	aref arship; // PB

	PChar = GetMainCharacter();

	officer1 = characterFromID("Louwe Louwman");
	officer2 = characterFromID("Giraldo Annibal");
	officer1idx = getCharacterIndex("Louwe Louwman");
	officer2idx = getCharacterIndex("Giraldo Annibal");

	Models[GetModelIndex("Ardent_SF")].sex = "woman";

	if (checkquestattribute("alignment", "evil"))
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
//		LAi_SetStayType(characterfromID("Lucia de la Vega"));
		villain = characterFromID("Piers Downing");
		villainidx = getCharacterIndex("Piers Downing");
		LAi_SetStayType(characterfromID("Piers Downing"));
		gov_kid = "daughter";
		merch_kid = "son";
		romance_pronoun1 = "her";
		romance_pronoun2 = "she";
		villain_pronoun = "him";
	}
	else
	{
		romance = characterFromID("Edmundo de la Vega");
		romanceidx = getCharacterIndex("Edmundo de la Vega");
//		LAi_SetStayType(characterfromID("Edmundo de la Vega"));
		villain = characterFromID("Valerie Downing");
		villainidx = getCharacterIndex("Valerie Downing");
		LAi_SetStayType(characterfromID("Valerie Downing"));
		gov_kid = "son";
		merch_kid = "daughter";
		romance_pronoun1 = "him";
		romance_pronoun2 = "he";
		villain_pronoun = "her";
	}
	ChangeCharacterAddressGroup(characterfromID("Gilbert Downing"), "Quest_Merchant_House", "sit", "sit1");
	LAi_SetHuberType(characterfromID("Gilbert Downing"));
	PChar.quest.romance = romance.id;
	PChar.quest.villain = villain.id;
	LAi_SetActorType(villain);
	LAi_ActorTurnToLocator(villain, "reload", "reload1");
	LAi_SetStayType(villain);

	switch(sQuestName)
	{
		case "StartAdventure":
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
			if (CheckAttribute(PChar, "monkey_follow"))
			{
				DeleteQuestAttribute("monkey_follow");
			}
//			PChar.quest.monkey_follow.over = "no";
			LAi_SetActorType(characterFromID("Monkey"));
			LAi_ActorDialog(characterFromID("Monkey"),PChar,"monkey_follow",5.0,5.0);
		break;

		case "monkey_follow":
			LAi_ActorFollowEverywhere(CharacterFromID("Monkey"), "", 1.0);
			Pchar.quest.monkey_follow.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.monkey_follow.win_condition.l1.character = Pchar.id;
			PChar.quest.monkey_follow.win_condition.l1.location = PChar.location;
			Pchar.quest.monkey_follow.win_condition = "get_monkey";
		break;

		case "In_jail":
			PChar.quest.disable_rebirth = true;
			SetQuestHeader("Imprisoned");
			if (PChar.ServedNation == PERSONAL_NATION) AddQuestRecord("Imprisoned", 1);
			else AddQuestRecord("Imprisoned", 2);
			if (!CheckCharacterItem(PChar, "bladeX2")) GiveItem2Character(PChar, "bladeX2");
			EquipCharacterByItem(PChar, "bladeX2");
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_prison")], false);
			LAi_QuestDelay("Still_stuck", 0.0);
			if(GetDifficulty() <= DIFFICULTY_MARINER) logit("HINT: If that warden comes close enough to the bars, you can mug him!");
			Pchar.quest.got_the_key.win_condition.l1 = "item";
			PChar.quest.got_the_key.win_condition.l1.character = Pchar.id;
			Pchar.quest.got_the_key.win_condition.l1.item = "key4";
			Pchar.quest.got_the_key.win_condition = "got_the_key";

			PChar.quest.warden_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.warden_dead.win_condition.l1.character = "Warden";
			PChar.quest.warden_dead.win_condition = "warden_dead";
		break;

		case "warden_dead":
			ChangeCharacterAddressGroup(characterfromID("Warden"), "Havana_prison", "reload", "reload12");
		break;

		case "Still_stuck":
			logit("Crew remaining: " + PChar.quest.crew_left);
			LAi_SetActorType(characterFromID("Warden"));
			LAi_ActorGoToLocator(characterfromID("Warden"), "reload", "reload12", "feeding_time", 30.0);
		break;

		case "feeding_time":
			LAi_ActorTurnToCharacter(characterFromID("Warden"), (Pchar));
			if (!CheckAttribute(characterfromID("Warden"), "stuntime"))
			{
				characters[GetCharacterIndex("Warden")].Dialog.Filename = "Warden_dialog.c";
				Characters[GetCharacterIndex("Warden")].dialog.CurrentNode = "feeding";
				LAi_ActorDialog(characterFromID("Warden"),PChar,"",5.0,5.0);
				LAi_QuestDelay("Warden_leaves", 10.0);
			}
		break;

		case "Warden_leaves":
			if (!CheckAttribute(characterfromID("Warden"), "stuntime"))
			{
				LAi_SetActorType(characterFromID("Warden"));
				LAi_ActorGoToLocator(characterfromID("Warden"), "officers", "reload1_2", "next_day", 30.0);
			}
		break;

		case "next_day":
			LAi_Fade("", "");
			WaitDate("", 0, 0, 1, 0, 0);
			crew_lost = rand(5);
			logit(crew_lost + " crew died of maltreatment");
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

		case "hanging_day":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);

			arrester = characterFromID(PChar.quest.arresterid);
			arresteridx = GetCharacterIndex(PChar.quest.arresterid);
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_prison")], true);
			LAi_SetFightMode(PChar, false);
			LAi_SetActorType(characterFromID("Warden"));
			LAi_ActorGoToLocator(characterfromID("Warden"), "officers", "reload1_2", "", 30.0);
			LAi_SetActorType(arrester);
			ChangeCharacterAddressGroup(arrester, "Havana_prison", "officers", "reload1_1");
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
			pchar.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "mutiny");
		break;

		case "got_the_key":
			ChangeCharacterAddressGroup(PChar, "Havana_prison", "reload", "reload12");
			ChangeCharacterAddressGroup(characterfromID("Havana Prison Commandant"), "Havana_prison", "officers", "reload1_1");
			LAi_SetGuardianType(characterFromID("Havana Prison Commandant"));
			if (!LAi_IsDead(characterFromID("Warden")))
			{
				LAi_SetStunnedTypeNoGroup(characterFromID("Warden"));
				ChangeCharacterAddressGroup(characterFromID("Warden"), "Havana_prison", "goto", "goto24");
			}
			if(GetDifficulty() <= DIFFICULTY_MARINER) logit("HINT: You aren't well armed and your officers aren't armed at all. Take all the help you can get!");

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
			PChar.quest.escaped.win_condition.l1 = "location";
			PChar.quest.escaped.win_condition.l1.character = PChar.id;
			Pchar.quest.escaped.win_condition.l1.location = "Havana_town_05";
			Pchar.quest.escaped.win_condition = "escaped";
		break;

		case "fight_commandant":
			LAi_SetActorType(characterFromID("Havana Prison Commandant"));
			LAi_ActorAttack(characterfromID("Havana Prison Commandant"), PChar, "");
		break;

		case "got_the_big_key":
			Locations[FindLocation("Havana_prison")].reload.l1.disable = 0;
			AddQuestRecord("Imprisoned", 3);
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
//				AddPartyExpChar(pchar, "Leadership", 1500);
//				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			LAi_SetImmortal(characterFromID("Two Dogs"), false);

			if (PChar.quest.alignment == "good" && !LAi_IsDead(characterFromID("Warden")) && isofficer(officer2))
			{
				LAi_SetActorType(officer2);
				characters[officer2idx].Dialog.Filename = "officer2_dialog.c";
				Characters[officer2idx].dialog.CurrentNode = "Nice guy";
				LAi_ActorDialog(officer2,PChar,"escaped2",0.0,0.0);
				ChangeCharacterReputation(pchar, 8);
			}
			if (PChar.quest.alignment == "evil" && LAi_IsDead(characterFromID("Warden")) && isofficer(officer2))
			{
				LAi_SetActorType(officer2);
				characters[officer2idx].Dialog.Filename = "officer2_dialog.c";
				Characters[officer2idx].dialog.CurrentNode = "Nasty guy";
				LAi_ActorDialog(officer2,PChar,"escaped2",0.0,0.0);
				ChangeCharacterReputation(pchar, -5);
			}
			ChangeCharacterAddress(characterFromID("Havana Prison Commandant"), "None", "");
			ChangeCharacterAddress(characterFromID("Spanish_guard1"), "None", "");
			ChangeCharacterAddress(characterFromID("Spanish_guard2"), "None", "");
			ChangeCharacterAddress(characterFromID("Spanish_guard3"), "None", "");
			if (!LAi_IsDead(characterFromID("Warden")))
			{
				LAi_SetCitizenTypeNoGroup(characterFromID("Warden"));
				ChangeCharacterAddressGroup(characterFromID("Warden"), "Havana_prison", "goto", "goto23");
			}

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

			LAi_QuestDelay("Pursuers", 0.0);
		break;

		case "escaped2":
			if (isofficer(officer2)) LAi_SetOfficerType(officer2);
		break;

		case "Pursuers":
			PChar.quest.pursuers = "counting";
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
					LAi_QuestDelay("Pursuers", 0.0);
				break;

				case "idle":
					LAi_QuestDelay("Pursuers", 0.0);
//					PChar.quest.pursuers = "counting";
				break;

				case "cancel":
					PChar.quest.pursuers = "idle";
					LAi_QuestDelay("Pursuers", 0.0);
				break;

				Pchar.quest.pursuit_new_location.over = "no";
			}
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

			TakeItemFromCharacter(Pchar, "key3");
			TakeItemFromCharacter(Pchar, "key4");
			RemoveCharacterEquip(PChar, "pistolmket");
			RemoveCharacterEquip(PChar, "pistolmketB");
			TakeItemFromCharacter(Pchar, "pistolmket");
			TakeItemFromCharacter(Pchar, "pistolmketB");
			if (!CheckCharacterItem(pchar, "pistolrock")) GiveItem2Character(pchar, "pistolrock");
			EquipCharacterByItem(pchar, "bladeX4");
			EquipCharacterByItem(pchar, "pistolrock");
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
		break;

		case "Cuba_Jungle_01":
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
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier1";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto15");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier2";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto23");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "soldier3";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto33");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
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
				crewid = characterFromID("Ayol Bacha");
				crewidx = GetCharacterIndex("Ayol Bacha");
			}
			if (!LAi_IsDead(characterFromID("Amtónio Guajira")))
			{
				survivors = survivors + 1;
				crewid = characterFromID("Amtónio Guajira");
				crewidx = GetCharacterIndex("Amtónio Guajira");
			}
			if (!LAi_IsDead(characterFromID("Coper Blumberger")))
			{
				survivors = survivors + 1;
				crewid = characterFromID("Coper Blumberger");
				crewidx = GetCharacterIndex("Coper Blumberger");
			}
			if (!LAi_IsDead(characterFromID("Ralph Partridge")))
			{
				survivors = survivors + 1;
				crewid = characterFromID("Ralph Partridge");
				crewidx = GetCharacterIndex("Ralph Partridge");
			}

			crew_lost = 4 - survivors;
			crew_left = PChar.quest.crew_left;
			crew_left = crew_left - crew_lost;
			if (crew_left < 0) crew_left = 0; // Shouldn't be possible! Take no chances anyway.
			PChar.quest.crew_left = crew_left;
			logit(crew_lost + " crew died in the battle");
			logit("Crew remaining: " + PChar.quest.crew_left);

			if (survivors > 0)
			{
				LAi_SetActorType(crewid);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "Rescued";
				LAi_ActorDialog(crewid, pchar, "move_out", 5.0, 5.0);
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
//			if (PChar.sex == "man")
//			{
//				logit("I'm taking one of the soldier's uniforms. A disguise might be useful later.");
//				GiveModel2Player("Ardent_S", false);
//			}
			logit("I'm taking one of the soldier's uniforms. A disguise might be useful later.");
			if (PChar.sex == "man") GiveModel2Player("Ardent_S", false);
			else GiveModel2Player("Ardent_SF", false);
			if (!LAi_IsDead(characterFromID("Ayol Bacha")))
			{
				LAi_SetActorType(characterFromID("Ayol Bacha"));
				LAi_ActorFollowEverywhere(CharacterFromID("Ayol Bacha"), "", 1.0);
			}
			if (!LAi_IsDead(characterFromID("Amtónio Guajira")))
			{
				LAi_SetActorType(characterFromID("Amtónio Guajira"));
				LAi_ActorFollowEverywhere(CharacterFromID("Amtónio Guajira"), "", 1.0);
			}
			if (!LAi_IsDead(characterFromID("Coper Blumberger")))
			{
				LAi_SetActorType(characterFromID("Coper Blumberger"));
				LAi_ActorFollowEverywhere(CharacterFromID("Coper Blumberger"), "", 1.0);
			}
			if (!LAi_IsDead(characterFromID("Ralph Partridge")))
			{
				LAi_SetActorType(characterFromID("Ralph Partridge"));
				LAi_ActorFollowEverywhere(CharacterFromID("Ralph Partridge"), "", 1.0);
			}
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
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(PChar, "", 100);
				AddPartyExpChar(pchar, "Fencing", 100);
//				AddPartyExpChar(pchar, "Leadership", 1500);
//				AddPartyExpChar(pchar, "Fencing", 50);
			}
			else {AddPartyExp(pchar, 1500);}
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
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				LAi_SetActorType(crewid);
				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "back_in_havana";
				LAi_ActorDialog(crewid, pchar, "back_in_town2", 5.0, 5.0);
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
				crewidx = GetCharacterIndex(speaker);
				characters[crewidx].Dialog.Filename = PChar.quest.normal_dialog;
			}
			if (!LAi_IsDead(officer1))
			{
				SetCharacterRemovable(officer1, true);
				LAi_SetActorType(officer1);
				LAi_ActorGoToLocator(officer1, "officers", "reload_4_1_1", "officers_leave",65.0);
			}
			if (!LAi_IsDead(officer2))
			{
				SetCharacterRemovable(officer2, true);
				LAi_SetActorType(officer2);
				LAi_ActorGoToLocator(officer2, "reload", "reload_4_1_back", "",65.0);
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
			DeleteAttribute(PChar, "isnotcaptain");
			AddCharacterGoods(PChar, GOOD_RUM, 2);
			AddCharacterGoods(PChar, GOOD_WHEAT, 3);
			AddCharacterGoods(PChar, GOOD_SAILCLOTH, 3);
			AddCharacterGoods(PChar, GOOD_PLANKS, 6);
			SetCrewQuantity(PChar, sti(PChar.quest.crew_left));
			setCharacterShipLocation(Pchar, "Cuba_port");
		break;

		case "port_good":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				LAi_SetActorType(crewid);
				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "got_a_ship";
				LAi_ActorDialog(crewid, pchar, "got_a_ship", 5.0, 5.0);
			}
			else LAi_QuestDelay("got_a_ship", 0.0);
		break;

		case "got_a_ship":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				characters[crewidx].Dialog.Filename = PChar.quest.normal_dialog;
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
			if (PChar.sex == "man")
			{
				gov_kid = "daughter";
				merch_kid = "son";
			}
			else
			{
				gov_kid = "son";
				merch_kid = "daughter";
			}
			Preprocessor_AddQuestData("gov_kid", gov_kid);
			Preprocessor_AddQuestData("merch_kid", merch_kid);
			Preprocessor_AddQuestData("name", GetMyName(romance));
			AddQuestRecord("Kidnap", 3);
			Preprocessor_Remove("gov_kid");
			Preprocessor_Remove("merch_kid");
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
			Pchar.quest.board_brig.win_condition.l1 = "locator";
			Pchar.quest.board_brig.win_condition.l1.location = "Santiago_town_01";
			Pchar.quest.board_brig.win_condition.l1.locator_group = "reload";
			Pchar.quest.board_brig.win_condition.l1.locator = "reload6";
			Pchar.quest.board_brig.win_condition.l2 = "Time";
			Pchar.quest.board_brig.win_condition.l2.time = DAY_TIME_NIGHT;
			Pchar.quest.board_brig.win_condition = "rob_store2";
		break;

		case "rob_store2":
			PlaySound("AMBIENT\TOWN\window_dog.wav");
			logit("You broke the window and grabbed the map. Now RUN!");
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
			Locations[FindLocation("Santiago_town_exit1")].reload.l3.emerge = "reload2_back";
			Locations[FindLocation("Santiago_town_exit1")].reload.l3.autoreload = "1";
			Locations[FindLocation("Santiago_town_exit1")].reload.l3.label = "Jungle";

			Locations[FindLocation("Cuba_Jungle_04")].reload.l4.go = "Santiago_town_exit1";
			Locations[FindLocation("Cuba_Jungle_04")].reload.l4.emerge = "reload1_back";
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
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				LAi_SetActorType(crewid);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "follow_him";
				LAi_ActorDialog(crewid, pchar, "scout_leaves2", 5.0, 5.0);
			}
		break;

		case "scout_leaves2":
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_port")], false);
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewidx = GetCharacterIndex(speaker);
				characters[crewidx].Dialog.Filename = PChar.quest.normal_dialog;
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
			for (n=1; n<4; n++)
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
			if (ENABLE_AMMOMOD) {	// LDH change
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
			LAi_SetPlayerType(PChar);
			Locations[FindLocation("Quest_Cabin")].reload.l1.disable = 0;
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;
			GiveShip2Character(PChar,"Shnyava2","Tonina",CANNON_TYPE_CARRONADE_LBS12,SPAIN,false,true);
			setCharacterShipLocation(Pchar, "Santiago_port");
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
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto3");
			GiveItem2Character(sld,"blade4");
			EquipCharacterByItem(sld,"blade4");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "CARGO_SOLDIERS");
			sld.id = "ship_guard1";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto4");
			GiveItem2Character(sld,"blade4");
			EquipCharacterByItem(sld,"blade4");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "CARGO_SOLDIERS");
			sld.id = "ship_guard2";

			LAi_SetActorType(characterFromID("ship_guard1"));
			characters[GetCharacterIndex("ship_guard1")].Dialog.Filename = "guard_dialog.c";
			Characters[GetCharacterIndex("ship_guard1")].dialog.CurrentNode = "snow_brig_check";
			LAi_ActorDialog(characterFromID("ship_guard1"), PChar, "", 10.0, 10.0); // Exits to "back_to_prison" or "ship_is_ours3"

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
//				AddPartyExpChar(pchar, "Leadership", 1500);
//				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else {AddPartyExp(pchar, 1500);}
			if (checkquestattribute("payroll_ship", "active")) AddQuestRecord("Payroll Ship", 6);
			RestoreOfficers(PChar.id);
			DoQuestReloadToLocation("Santiago_port", "reload", "reload2_back", "restore_officers");
		break;

		case "restore_officers":
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
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				LAi_SetActorType(crewid);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "crew_returning";
				LAi_ActorDialog(crewid, pchar, "crew_returning", 5.0, 5.0);
			}
			else logit ("That looks like the original crew returning. Better get aboard and get out of here!");
		break;

		case "crew_returning":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				characters[crewidx].Dialog.Filename = PChar.quest.normal_dialog;
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
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				LAi_SetActorType(crewid);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "ready_for_payroll_ship";
				LAi_ActorDialog(crewid, pchar, "ready_for_payroll_ship2", 5.0, 5.0);
			}
			else
			{
				logit("Now to wait for the 'Siroco'...");
				LAi_QuestDelay("ready_for_payroll_ship3", 0.0);
			}
			PChar.quest.payroll_ship_timer2.over = "yes";
		break;

		case "ready_for_payroll_ship2":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				characters[crewidx].Dialog.Filename = PChar.quest.normal_dialog;
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
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				LAi_SetActorType(crewid);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "payroll_ship_in_sight";
				LAi_ActorDialog(crewid, pchar, "payroll_ship_in_sight", 5.0, 5.0);
			}
		break;

		case "payroll_ship_in_sight":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				characters[crewidx].Dialog.Filename = PChar.quest.normal_dialog;
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
//				AddPartyExpChar(pchar, "Leadership", 2000);
//				AddPartyExpChar(pchar, "Sneak", 100);
			}
			else {AddPartyExp(pchar, 1500);}
			AddMoneyToCharacter(pchar, 10000);
			AddQuestRecord("Payroll Ship", 9);
			CloseQuestHeader("Payroll Ship");
			PChar.quest.payroll_ship = "success";
			ch = characterFromID("Santiago Commander");
			ch.PlayerNation = GetCurrentFlag();
			ch.PlayerShip = GetCharacterShipModel(PChar);
//			Trace("Ardent: The " + GetMyShipNameShow(ch) + " will remember us as " + GetNationDescByType(sti(ch.PlayerNation)) + " in a " + ch.PlayerShip);
		break;

		case "payroll_ship_arrives":
			AddQuestRecord("Payroll Ship", 8);
			CloseQuestHeader("Payroll Ship");
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
			LAi_ActorGoToLocator(characterFromID("Mauricio Juradu"), "reload", "locator3_back", "",60.0);
			pchar.quest.with_guide_to_cape_francos3.win_condition.l1 = "location";
			PChar.quest.with_guide_to_cape_francos3.win_condition.l1.location = "Hispaniola_Jungle_07";
			PChar.quest.with_guide_to_cape_francos3.win_condition = "trek_to_temple2";
		break;

		case "trek_to_temple2":
			ChangeCharacterAddressGroup(characterFromID("Mauricio Juradu"), "Hispaniola_Jungle_07", "reload", "reload1_back");
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
			logit("Maybe there's something in that room with the wall markings...");
		break;

		case "got_the_rug":
			AddQuestRecord("Mayan Temple", 3);
			pchar.quest.rug_to_chief.win_condition.l1 = "location";
			PChar.quest.rug_to_chief.win_condition.l1.character = PChar.id;
			pchar.quest.rug_to_chief.win_condition.l1.location = "Quest_Indian_house";
			pchar.quest.rug_to_chief.win_condition = "rug_to_chief";
		break;

		case "mauricio_steals_ship":
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
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				LAi_SetActorType(crewid);
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "buccaneer_tavern_duel";
				LAi_ActorDialog(crewid, pchar, "buccaneer_tavern_duel", 5.0, 5.0);
			}
			else LAi_QuestDelay("buccaneer_tavern_duel", 0.5);
		break;

		case "buccaneer_tavern_duel":
			speaker = Get_Speaker();
			if (speaker != "")
			{
				crewid = characterFromID(speaker);
				crewidx = GetCharacterIndex(speaker);
				characters[crewidx].Dialog.Filename = PChar.quest.normal_dialog;
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
			}
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1200);
				AddPartyExpChar(PChar, "", 120);
				AddPartyExpChar(pchar, "Sneak", 120);
//				AddPartyExpChar(pchar, "Leadership", 2000);
//				AddPartyExpChar(pchar, "Sneak", 100);
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
			Characters[romanceidx].dialog.CurrentNode = "intruder";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"kidnap_escape",10.0,10.0);
		break;

		case "kidnap_escape":
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
			LAi_SetActorType(characterfromID("Javier Balboa"));
			DoQuestReloadToLocation("Santiago_townhall", "goto", "goto8", "kidnap_escape2");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard1"), "Santiago_townhall", "goto", "goto11");
			ChangeCharacterAddressGroup(characterfromID("Spanish_guard2"), "Santiago_townhall", "goto", "goto12");
			LAi_SetGuardianType(characterfromID("Spanish_guard1"));
			LAi_SetGuardianType(characterfromID("Spanish_guard2"));
//			LAi_SetActorType(romance);
//			LAi_ActorFollowEverywhere(romance, "", 1.0);
		break;

		case "kidnap_escape2":
			DisableFastTravel(true);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "kidnap_threaten";
			LAi_ActorDialog(characterFromID("Javier Balboa"),PChar,"",5.0,5.0);
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

			PChar.quest.kidnap.hostage_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.kidnap.hostage_dead.win_condition.l1.character = romance.id;
			PChar.quest.kidnap.hostage_dead.win_condition = "hostage_dead";

			Locations[FindLocation("Redmond_town_03")].reload.l9.disable = 1; // If you have kidnapped Lucia / Edmundo then you won't get to do the courier jobs
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
			GiveItem2Character(characterfromID("Javier Balboa"), "blade14+2");
			GiveItem2Character(characterfromID("Javier Balboa"), "goldarmor");
			EquipCharacterByItem(characterfromID("Javier Balboa"),"blade14");
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
			characters[GetCharacterIndex("Santiago_soldier_05")].Dialog.Filename = "Isla Muelle soldier_dialog.c";
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 7);
			Preprocessor_Remove("name");
			CloseQuestHeader("Kidnap");
			DeleteQuestAttribute("ardent_kidnap.status");
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
			ChangeCharacterAddress(romance, "None", "");
			characters[GetCharacterIndex("Santiago_soldier_05")].Dialog.Filename = "Isla Muelle soldier_dialog.c";
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 4);
			Preprocessor_Remove("name");
			CloseQuestHeader("Kidnap");
			DeleteQuestAttribute("ardent_kidnap.status");
		break;

		case "kidnap_what_next":
			DisableFastTravel(false);
			Characters[romanceidx].dialog.CurrentNode = "what_next";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"",30.0,30.0); // Exits to either "kidnap_prisoner" or "kidnap_guest"
		break;

		case "kidnap_guest":
//			romance.quest.officertype = OFFIC_TYPE_FIRSTMATE; // To put the guest into the captain's cabin so you can talk to her/him later
			AddPassenger(PChar, romance, 0);
			SetCharacterRemovable(romance, false);
//			ChangeCharacterAddress(romance, "None", "");
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
			Preprocessor_AddQuestData("pronoun", romance_pronoun1);
			AddQuestRecord("Kidnap", 5);
			Preprocessor_Remove("name");
			Preprocessor_Remove("pronoun");
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;
			Characters[romanceidx].dialog.CurrentNode = "letter";
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
			AddQuestRecord("Kidnap", 6);
			Preprocessor_Remove("name");
			Locations[FindLocation("Santiago_port")].reload.l2.disable = 0;
		break;

		case "governors_revenge":	// If you're stupid enough to go back to townhall without a ransom demand or other news, governor avenges his daughter / son.
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
/*			ch = characterFromID("Javier Balboa");
			ch.skill.Fencing = "10";
			ch.skill.Accuracy = "5";
			ch.skill.Defence = "5";
			ch.perks.list.BasicDefence = true;
			ch.perks.list.AdvancedDefence = true;
			ch.perks.list.SwordplayProfessional = true;
			ch.perks.list.CriticalHit = true;
			Ch.Perks.list.Toughness = true;
			GiveItem2Character(characterfromID("Javier Balboa"), "blade14+2");
			GiveItem2Character(characterfromID("Javier Balboa"), "goldarmor");
			EquipCharacterByItem(characterfromID("Javier Balboa"),"blade14"); */
			LAi_SetHP(characterfromID("Javier Balboa"), 500.0, 500.0);
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 1;
			LAi_QuestDelay("governors_revenge2", 0.0);
		break;

		case "governors_revenge2":
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
			Ambush("guards", 8, "enemy", "friend", "reload1");
			PChar.quest.ransom_reject_escape.win_condition.l1 = "location";
			PChar.quest.ransom_reject_escape.win_condition.l1.location = "Santiago_town_01";
			PChar.quest.ransom_reject_escape.win_condition = "ransom_reject_escape";
		break;

		case "ransom_reject_escape":
			ch = characterFromID("Javier Balboa");
			ch.skill.Fencing = "10";
			ch.skill.Accuracy = "5";
			ch.skill.Defence = "5";
			ch.perks.list.BasicDefence = true;
			ch.perks.list.AdvancedDefence = true;
			ch.perks.list.SwordplayProfessional = true;
			ch.perks.list.CriticalHit = true;
			Ch.Perks.list.Toughness = true;
			GiveItem2Character(characterfromID("Javier Balboa"), "blade14+2");
			GiveItem2Character(characterfromID("Javier Balboa"), "goldarmor");
			EquipCharacterByItem(characterfromID("Javier Balboa"),"blade14");
			LAi_SetHP(characterfromID("Javier Balboa"), 500.0, 500.0);
			LAi_LocationFightDisable(&Locations[FindLocation("Santiago_townhall")], true);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "revenge";
			LAi_SetStayType(characterFromID("Javier Balboa"));
//			LAi_ActorTurnToLocator(characterFromID("Javier Balboa"), "reload", "reload1");
		break;

		case "ransom_accepted":
			Pchar.quest.ransom_accept_setup.win_condition.l1 = "Time";
			Pchar.quest.ransom_accept_setup.win_condition.l1.time = DAY_TIME_NIGHT;
			PChar.quest.ransom_accept_setup.win_condition = "ransom_accept_setup";
		break;

		case "ransom_accept_setup":
			ChangeCharacterAddressGroup(characterFromID("Grigorio Formoselle"), "Cuba_Shore_05", "goto", "citizen09");
			ChangeCharacterAddressGroup(characterFromID("Spanish_guard1"), "Cuba_Shore_05", "goto", "citizen05");
			ChangeCharacterAddressGroup(characterFromID("Spanish_guard2"), "Cuba_Shore_05", "goto", "citizen06");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 5.0);
			Characters[GetCharacterIndex("Grigorio Formoselle")].dialog.CurrentNode = "ransom_exchange";	// You will initiate dialog, which exits to "hostage_released"
			PChar.quest.ransom_accept_setup2.win_condition.l1 = "location";
			PChar.quest.ransom_accept_setup2.win_condition.l1.location = "Cuba_Shore_05";
			PChar.quest.ransom_accept_setup2.win_condition = "ransom_accept_setup2";
		break;

		case "ransom_accept_setup2":
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
			DeleteQuestAttribute("ardent_kidnap");
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
			GiveItem2Character(characterfromID("Javier Balboa"), "blade33+3");
			GiveItem2Character(characterfromID("Javier Balboa"), "goldarmor");
			EquipCharacterByItem(characterfromID("Javier Balboa"),"blade33");
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
		break;

		case "deliver_ExplainLetter":
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "hostage_free";
			GiveItem2Character(PChar, "ExplainLetter");
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			Preprocessor_AddQuestData("pronoun", romance_pronoun1);
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

		case "recruit_carpenter":
			romance.quest.officertype = OFFIC_TYPE_CARPENTER;
			LAi_QuestDelay("recruit_complete", 0.0);
		break;

		case "recruit_complete":
//			PChar.quest.kidnap.hostage_dead.over = "yes";
			SetOfficersIndex(Pchar, 3, romanceidx);
			SetCharacterRemovable(romance, true);
			romance.officer = true;
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 12);
			Preprocessor_Remove("name");
			CloseQuestHeader("Kidnap");
			DeleteQuestAttribute("ardent_kidnap");
			PChar.quest.betrayed_spain.win_condition.l1 = "relation";
			PChar.quest.betrayed_spain.win_condition.l1.relation = "Hostile";
			PChar.quest.betrayed_spain.win_condition.l1.nation = "Spain";
			PChar.quest.betrayed_spain.win_condition = "betrayed_spain";

			if (PChar.sex == "man")
			{
				PChar.quest.lucia_new_outfit.win_condition.l1 = "party_goods";
				PChar.quest.lucia_new_outfit.win_condition.l1.goods = GOOD_SILK;
				PChar.quest.lucia_new_outfit.win_condition.l1.quantity = 1;
				PChar.quest.lucia_new_outfit.win_condition.l1.operation = ">=";
				PChar.quest.lucia_new_outfit.win_condition = "lucia_new_outfit";
			}
		break;

		case "release_guest":
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 13);
			Preprocessor_Remove("name");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 1.0);
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
			LAi_ActorDialog(romance,PChar,"released_free1",5.0,5.0);
		break;

		case "released_free1":
			Locations[FindLocation("Muelle_town_03")].reload.l1.disable = 0;
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 16);
			Preprocessor_Remove("name");
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
//			LAi_SetCitizenType(romance);
			LAi_SetCitizenType(CharacterFromId(characters[romanceidx].id));
			Characters[romanceidx].dialog.CurrentNode = "bored_in_san_juan";
		break;

		case "governor_relaxes":
			Preprocessor_AddQuestData("name", GetMySimpleName(romance));
			AddQuestRecord("Kidnap", 15);
			Preprocessor_Remove("name");
			LAi_QuestDelay("reset_governor", 0.0);
		break;

		case "reset_governor":
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "First time";
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_townhall", "sit", "sit2");
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
			AddQuestRecord("Kidnap", 23);
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
		break;
// When the second letter is delivered, dialog will exit to "second_CourtingLetter_return_with_answer", "second_CourtingLetter_kidnap", or "second_CourtingLetter_bow_escape"

		case "second_CourtingLetter_return_with_answer":
			DoQuestReloadToLocation("Santiago_townhall", "goto", "goto8", "second_CourtingLetter_return_with_answer2");
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
			DoQuestReloadToLocation("Santiago_townhall", "goto", "goto8", "kidnap_escape2");
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

//			Locations[FindLocation("Santiago_port")].locators_radius.merchant.merchant1 = 5.0;
			Locations[FindLocation("Santiago_port")].locators_radius.goto.goto28 = 28.0;
			PChar.quest.kidnap_run_for_ship.win_condition.l1 = "locator";
//			PChar.quest.kidnap_run_for_ship.win_condition.l1 = "location";
			Pchar.quest.kidnap_run_for_ship.win_condition.l1.location = "Santiago_port";
//			Pchar.quest.kidnap_run_for_ship.win_condition.l1.locator_group = "merchant";
//			Pchar.quest.kidnap_run_for_ship.win_condition.l1.locator = "merchant1";
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
			LAi_ActorRunToLocation(romance, "reload", "reload2_back", "Santiago_port", "", "", "", 90.0);
			LAi_ActorAttack(characterfromID("Santiago_soldier_05"), PChar, "");
		break;

		case "santiago_reset":
			PChar.quest.Santiago_soldiers_fight_back.over = "yes";
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
//			Locations[FindLocation("Santiago_port")].locators_radius.merchant.merchant1 = 1.0;
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
			DoQuestReloadToLocation("Santiago_townhall", "goto", "goto8", "second_CourtingLetter_bow_escape2");
		break;

		case "second_CourtingLetter_bow_escape2":
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
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
			PChar.quest.romance_model = romance.model
			SetModelfromArray(romance, GetModelIndex("Animistse"));
			DoQuestReloadToLocation("Santiago_town_01", "goto", "goto22", "bow_escape_out_to_town");
		break;

		case "bow_escape_out_to_town":
			Characters[romanceidx].dialog.CurrentNode = "bow_rescue_outside_residence";
			LAi_SetActorType(romance);
			LAi_ActorDialog(romance,PChar,"bow_escape_now_to_port",5.0,5.0);
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

			PChar.quest.kidnap.hostage_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.kidnap.hostage_dead.win_condition.l1.character = romance.id;
			PChar.quest.kidnap.hostage_dead.win_condition = "hostage_dead";
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
			LAi_ActorDialog(romance,PChar,"bow_escape_in_port3",5.0,5.0);
		break;

		case "bow_escape_in_port3":
			LAi_SetActorType(characterFromID("Santiago_soldier_01"));
			Characters[GetCharacterIndex("Santiago_soldier_01")].dialog.CurrentNode = "cabin_boy";
			LAi_ActorDialogNow(characterFromID("Santiago_soldier_01"),PChar,"bow_escape_in_port4",1.0);
		break;

		case "bow_escape_in_port4":
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "naughty_guard";
			LAi_ActorDialog(romance,PChar,"bow_escape_in_port5",5.0,5.0);
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
			LAi_ActorRunToLocation(romance, "reload", "reload2_back", "Santiago_port", "", "", "", 90.0);
			LAi_SetActorType(characterFromID("Santiago_soldier_01"));
			LAi_ActorAttack(characterfromID("Santiago_soldier_01"), PChar, "");
	       		LAi_SetCheckMinHP(characterFromID("Santiago_soldier_01"), LAi_GetCharacterHP(characterFromID("Santiago_soldier_01"))-1.0, false, "soldiers_fight_back_port");
			PChar.quest.santiago_reset_port.win_condition.l1 = "location";
			PChar.quest.santiago_reset_port.win_condition.l1.location = "Cuba";
			PChar.quest.santiago_reset_port.win_condition = "santiago_reset_port"
		break;

		case "soldiers_fight_back_port":
			if (!LAi_IsDead(characterFromID("Santiago_soldier_01"))) LAi_group_MoveCharacter(CharacterFromID("Santiago_soldier_01"), "SPAIN_SOLDIERS");
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "santiago_reset_port":
			PChar.quest.soldiers_fight_back_port.over = "yes";
			ChangeCharacterAddressGroup(characterfromID("Santiago_soldier_01"), "Santiago_port", "goto", "goto23");
			LAi_SetGuardianType(characterfromID("Santiago_soldier_01"));
			Locations[FindLocation("Santiago_port")].locators_radius.goto.goto28 = 1.0;
			SetModelFromID(romance, PChar.quest.romance_model);
//			DeleteQuestAttribute("romance_model");
		break;

		case "marriage_proposal_accepted":
			PChar.quest.in_santiago_for_ExplainLetter.over = "yes";
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
			SetCurrentTime(10.00, 0);
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
			if (CheckAttribute(PChar,"quest.wedding_escort") && PChar.quest.wedding_escort != "")
			{
				crewid = characterFromID(PChar.quest.wedding_escort);
				crewidx = GetCharacterIndex(PChar.quest.wedding_escort);
				RemoveOfficersIndex(pchar, crewidx);
				SetCharacterRemovable(crewid, false);
				ChangeCharacterAddressGroup(crewid, "Santiago_church", "sit", "sit13");
				LAi_SetActorType(crewid);
				if (characters[crewidx].sex == "man") LAi_ActorSetSitMode(crewid);
			}

			LAi_SetActorType(characterFromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_church", "sit", "sit3");
			LAi_ActorSetSitMode(characterFromID("Javier Balboa"));

			Locations[FindLocation("Santiago_church")].locators_radius.goto.goto11 = 2.0;
			logit("Time to go to church!");
			Pchar.quest.Wedding_ceremony.win_condition.l1 = "locator";
			Pchar.quest.Wedding_ceremony.win_condition.l1.location = "Santiago_church";
			Pchar.quest.Wedding_ceremony.win_condition.l1.locator_group = "goto";
			Pchar.quest.Wedding_ceremony.win_condition.l1.locator = "goto11";
			Pchar.quest.Wedding_ceremony.win_condition = "Wedding_ceremony";
// PChar.quest.wedding_ring = "jewelry10_q"; // Give us a free ring for testing
// GiveItem2Character(PChar, "jewelry10_q");
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
				PChar.quest.bride = GetMyFullName(romance);
				PChar.quest.groom = GetMyFullName(PChar);
			}
			else
			{
				PChar.quest.bride = GetMyFullName(PChar);
				PChar.quest.groom = GetMyFullName(romance);
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
			LAi_SetActorType(characterFromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "wedding_consent3";
			LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"Wedding_consent3_answer",5.0,5.0);
		break;

		case "Wedding_consent3_answer":
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
//			LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"Wedding_bless_rings",5.0,5.0);
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
			LAi_SetActorType(characterFromID("Padre Magarino"));
			Characters[GetCharacterIndex("Padre Magarino")].dialog.CurrentNode = "final_blessing";
			LAi_ActorDialog(characterFromID("Padre Magarino"),PChar,"Wedding_done",5.0,5.0);
		break;

		case "Wedding_done":
			LAi_SetActorType(characterFromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_church", "goto", "goto6");
			if (CheckAttribute(PChar,"quest.wedding_escort") && PChar.quest.wedding_escort != "")
			{
				crewid = characterFromID(PChar.quest.wedding_escort);
				crewidx = GetCharacterIndex(PChar.quest.wedding_escort);
				PChar.quest.normal_dialog = characters[crewidx].Dialog.Filename;
				LAi_SetActorType(crewid);
				ChangeCharacterAddressGroup(crewid, "Santiago_church", "goto", "goto7");
				characters[crewidx].Dialog.Filename = "crew_dialog.c";
				Characters[crewidx].Dialog.CurrentNode = "married_congrats";
				LAi_ActorDialog(crewid, pchar, "wedding_done2", 5.0, 5.0);
			}
			else LAi_QuestDelay("Wedding_done2", 1.0);
		break;

		case "Wedding_done2":
			if (CheckAttribute(PChar,"quest.wedding_escort") && PChar.quest.wedding_escort != "")
			{
				crewid = characterFromID(PChar.quest.wedding_escort);
				crewidx = GetCharacterIndex(PChar.quest.wedding_escort);
				characters[crewidx].Dialog.Filename = PChar.quest.normal_dialog;
				SetCharacterRemovable(crewid, true);
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
			characters[romanceidx].quest.meeting = "1"
			characters[romanceidx].Dialog.Filename = "Gov MR_dialog.c";
			characters[romanceidx].Dialog.CurrentNode = "First time";
			characters[romanceidx].talkpoints = 0;
			characters[romanceidx].marpoints = 1;
			characters[romanceidx].pcounter = 0;
			if (PChar.sex == "man") characters[romanceidx].middlename = TranslateString("","Ardent");
			else PChar.middlename = TranslateString("","de la Vega");
//			LAi_SetStayType(romance);
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
			LAi_SetActorType(romance);
			LAi_SetActorType(characterFromID("Javier Balboa"));
            		LAi_ActorGoToLocation(romance, "reload", "reload4", "none", "", "", "", 120.0);
            		LAi_ActorGoToLocation(characterFromID("Javier Balboa"), "reload", "reload4", "none", "", "", "", 120.0);
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
			LAi_QuestDelay("return_to_residence2", 1.0);
		break;

		case "return_to_residence2":
			LAi_SetActorType(characterfromID("Javier Balboa"));
			LAi_SetActorType(romance);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "enjoy_reception";
			if(LAi_IsDead(villain)) LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"bypass_reception",5.0,5.0);
//			else LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"assassination_attempt",5.0,5.0);
			else LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",5.0,5.0); // Exits to "assassination_attempt"
		break;

		case "bypass_reception":
			ChangeCharacterAddressGroup(romance, "Quest_Santiago_Bedroom", "goto", "goto5");
			DoQuestReloadToLocation("Santiago_townhall", "goto", "goto8", "reception_done");
		break;

		case "reception_done":
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "reception_done";
			LAi_ActorDialog(characterFromID("Javier Balboa"),PChar,"prepare_for_bed",5.0,5.0);
		break;

		case "prepare_for_bed":
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
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10.00, 0);
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
//			ChangeCharacterAddressGroup(characterfromID("Javier Balboa"), "Santiago_townhall", "goto", "goto3");
//			LAi_SetStayType(characterfromID("Javier Balboa"));
			ChangeCharacterAddressGroup(characterFromID("Javier Balboa"), "Santiago_townhall", "sit", "sit2");
			LAi_SetHuberType(characterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "enjoy_reception";
			DoQuestReloadToLocation("Santiago_townhall", "goto", "goto8", "morning_after_wedding2");
		break;

		case "morning_after_wedding2":
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 0;
			DisableFastTravel(false);
			bQuestDisableSeaEnter = false;
			AddQuestRecord("Marriage", 12);
			CloseQuestHeader("Marriage");
			RestoreOfficers(PChar.id);
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "wedding_present";
			if(CheckAttribute(romance,"officer"))
			{
				AddPassenger(PChar, romance, 0);
				SetOfficersIndex(Pchar, 1, romanceidx);
				LAi_SetOfficerType(romance);
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
			if(ispassenger(romance) || isofficer(romance))
			{
				RemoveOfficersIndex(pchar, romanceidx);
				RemovePassenger(pchar, romance);
				Preprocessor_Save("romance", GetMySimpleName(romance));
				GiveItem2Character(PChar, "BetrayedLetter");
				ChangeCharacterAddress(romance, "None", "");
			}
			else
			{
				if(characters[romanceidx].married == MR_MARRIED)
				{
					characters[romanceidx].Dialog.Filename = "romance_dialog.c";
					characters[romanceidx].Dialog.CurrentNode = "dont_talk_to_me";
				}
			}
			WriteNewLogEntry(GetMySimpleName(romance) + "deserts", GetMySimpleName(romance) + "didn't take too kindly to my actions against Spain, and has left me.", "Personal", true);
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
			GiveModel2Player("liz3", false);
			GiveModel2Player("lucia_2", false);
			SetModelfromArray(romance, GetModelIndex("lucia_2"));
			WriteNewLogEntry(GetMyName(romance) + "'s new clothes", GetMySimpleName(romance) + " has taken some silk from our hold without bothering to ask. But after seeing the new clothes she made for herself with it, I'm not complaining!","Personal",true);
		break;

		case "assassination_attempt":

			ChangeCharacterAddressGroup(characterfromID("Malbert Sangier"), "Santiago_town_01", "goto", "goto9");
			LAi_QuestDelay("assassination_attempt2", 2.00);
		break;

		case "assassination_attempt2":
			PlaySound("OBJECTS\duel\pistol_medium2.wav");
			PlaySound("AMBIENT\TOWN\window_dog.wav");
			LAi_QuestDelay("assassination_attempt3", 0.02);
		break;

		case "assassination_attempt3":
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 0;
//			Lai_KillCharacter(romance);
			LAi_KillCharacter(characterfromID("fake_romance"));
			ChangeCharacterAddress(romance, "None", "");
			if(PChar.sex == "man") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom2.wav");
			else PlaySound("OBJECTS\VOICES\DEAD\male\dead5.wav");
			romance.chr_ai.hp = romance.chr_ai.hp_max;
			PChar.quest.assassination = "no_clue";
			Preprocessor_AddQuestData("romance", GetMySimpleName(romance));
			AddQuestRecord("Marriage", 13);
			Preprocessor_Remove("romance");
			LAi_SetActorType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "assassination";
			LAi_ActorDialog(CharacterFromID("Javier Balboa"),PChar,"",1.0,1.0);
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
			DoQuestReloadToLocation("Santiago_townhall", "goto", "goto8", "assassination_fade_to_next_day2");
		break;

		case "assassination_fade_to_next_day2":
			WaitDate("", 0, 0, 5, 0, 0);
			SetCurrentTime(10.00, 0);
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
				SetOfficersIndex(Pchar, 1, romanceidx);
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
			PChar.quest.Abequa_moves.win_condition.l1 = "location";
			PChar.quest.Abequa_moves.win_condition.l1.location = "Cartagena Hotel";
			PChar.quest.Abequa_moves.win_condition = "convoy_Abequa_moves";
		break;

		case "convoy_Abequa_moves":
			LAi_SetActorType(characterFromID("Abequa"));
			LAi_ActorGoToLocator(characterFromID("Abequa"), "goto", "goto6", "",30.0);
		break;

		case "convoy_Abequa_speaks":
			PChar.quest.normal_dialog = characters[GetCharacterIndex("Abequa")].Dialog.Filename;
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
			characters[GetCharacterIndex("Abequa")].Dialog.Filename = PChar.quest.normal_dialog;
			ChangeCharacterAddressGroup(CharacterFromID("Abequa"), "Cartagena Hotel", "goto", "character2");
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
			SetCharacterShipLocation(PChar, "Willemstad_port");
			if(!isofficer(romance)) SetOfficersIndex(Pchar, 1, romanceidx);
			SetCharacterRemovable(romance, false);
			ChangeCharacterAddressGroup(romance, "Tutorial_Deck", "rld", "startloc");
			StartQuestMovie(true, true, false);
			DoReloadFromSeaToLocation("Tutorial_Deck", "reload", "reload1");
			LAi_QuestDelay("convoy_plan_attack", 1.0);
		break;

		case "convoy_plan_attack":
			LAi_SetActorType(romance);
			characters[romanceidx].Dialog.Filename = "romance_dialog.c";
			Characters[romanceidx].dialog.CurrentNode = "convoy_how_take_convoy";
//			LAi_ActorDialog(romance,PChar,"",5.0,5.0); // Exits to "convoy_romance_waits" or "convoy_arrive_port"
			LAi_ActorDialog(romance,PChar,"convoy_arrive_port",5.0,5.0);
		break;

		case "convoy_arrive_port":
			EndQuestMovie();
			LAi_SetOfficerType(romance);
//			ChangeCharacterAddressGroup(romance, "Willemstad_port", "goto", "goto13");
			PChar.quest.romance_model = romance.model;
			SetModelfromArray(romance, GetModelIndex("Animistse"));
			PChar.location.from_sea = "Willemstad_port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "PChar");
			if (PChar.sex == "man") GiveModel2Player("Ardent_S", true);
			else GiveModel2Player("Ardent_SF", true);
			DoQuestReloadToLocation("Willemstad_port", "reload", "sea_back", "convoy_arrive_port2");
		break;

		case "convoy_arrive_port2":
			if(PChar.model == "Ardent_SF") logit("This uniform is uncomfortable, being made for a man, but I'd better wear it whenever I need to talk to the governor.");
//			LAi_SetOfficerType(romance);
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_sergeant"), "Willemstad_townhall", "goto", "goto2");
			characters[GetCharacterIndex("Dutch_sergeant")].Dialog.Filename = "guard_dialog.c";
			LAi_SetGuardianType(characterfromID("Dutch_sergeant"));
			Pchar.quest.Willemstad_residence.win_condition.l1 = "location";
			PChar.quest.Willemstad_residence.win_condition.l1.character = Pchar.id;
			Pchar.quest.Willemstad_residence.win_condition.l1.location = "Willemstad_townhall";
			Pchar.quest.Willemstad_residence.win_condition = "Willemstad_residence";
			if(GetCompanionQuantity(PChar) > 1)
			{
				Locations[FindLocation("Willemstad_town_3")].reload.l6.disable = 1;
				LAi_SetActorType(romance);
				Characters[romanceidx].dialog.CurrentNode = "convoy_dispose_ships";
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
			Pchar.quest.back_in_Willemstad_town.win_condition.l1 = "location";
			Pchar.quest.back_in_Willemstad_town.win_condition.l1.location = "Willemstad_town";
			Pchar.quest.back_in_Willemstad_town.win_condition = "convoy_back_in_Willemstad_town";
		break;

		case "convoy_back_in_Willemstad_town":
			if(GetCompanionQuantity(PChar) > 1)
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
		break;

		case "romance_to_officer_mode":
			LAi_SetOfficerType(romance);
		break;

		case "Willemstad_residence":
			Locations[FindLocation("Willemstad_townhall")].reload.l1.disable = 1;
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(romance, "Willemstad_townhall", "goto", "goto1");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			PChar.quest.original_name = PChar.name;
			if (CheckAttribute(PChar,"middlename") == true && PChar.middlename != "")
			{
				PChar.quest.original_middlename = PChar.middlename;
				PChar.middlename = "";
			}
			PChar.quest.original_lastname = PChar.lastname;
			PChar.name = "Carlos";
			PChar.lastname = "Ardenta";
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
//			LAi_SetOfficerType(romance);
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
//			LAi_SetOfficerType(romance);
			Locations[FindLocation("Quest_Seadogs")].vcskip = true;

			Pchar.quest.convoy_board_ship.win_condition.l1 = "locator";
			Pchar.quest.convoy_board_ship.win_condition.l1.location = "Willemstad_port";
			Pchar.quest.convoy_board_ship.win_condition.l1.locator_group = "reload";
			Pchar.quest.convoy_board_ship.win_condition.l1.locator = "sea_back";
			Pchar.quest.convoy_board_ship.win_condition = "convoy_board_ship";
		break;

		case "convoy_board_ship":
			StoreOfficers(PChar.id);
			SetOfficersIndex(Pchar, 1, romanceidx);
			LAi_SetStayType(romance);
			ChangeCharacterAddressGroup(romance, "Quest_Seadogs", "rld", "loc2");
			LAi_SetActorType(CharacterFromID("Dutch_sergeant"));
			ChangeCharacterAddress(CharacterFromID("Dutch_sergeant"), "None", "");
			Characters[romanceidx].dialog.CurrentNode = "convoy_aboard_ship";
			DoReloadCharacterToLocation("Quest_Seadogs", "reload", "reload2");
		break;

		case "convoy_romance_removes_cloak":
			SetModelFromID(romance, PChar.quest.romance_model);
			LAi_SetOfficerType(romance);
			LAi_SetGuardianType(characterFromID("Dutch_sergeant"));
			ChangeCharacterAddressGroup(CharacterFromID("Dutch_sergeant"), "Quest_Seadogs", "reload", "reload1");
//			DoReloadCharacterToLocation("Quest_Seadogs", "goto", "goto2");
			DoQuestReloadToLocation("Quest_Seadogs", "goto", "goto2", "convoy_report_found_romance");
		break;

		case "convoy_report_found_romance":
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
//			LAi_SetActorType(romance);
//			LAi_ActorFollowEverywhere(romance, "", 5.0);
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
//			LAi_SetActorType(romance);
//			LAi_ActorFollowEverywhere(romance, "", 5.0);
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
			DeleteQuestAttribute("original_firstname");
			DeleteQuestAttribute("original_lastname");
			LAi_SetActorType(romance);
			Characters[romanceidx].dialog.CurrentNode = "convoy_choose_officer_first_time";
			LAi_ActorDialog(romance,PChar,"",5.0,5.0);  // Either exits to "convoy_romance_waits", or sets attribute PChar.quest.convoy_officer and exits to "convoy_final_preparations2"
		break;

		case "convoy_romance_waits":
			LAi_SetStayType(romance);
//			characters[romanceidx].Dialog.Filename = "romance_dialog.c";
//			Characters[romanceidx].dialog.CurrentNode = "convoy_officer_try_again";
		break;

		case "convoy_final_preparations2":
			LAi_SetOfficerType(romance);
			ExchangeCharacterShip(Pchar, characterFromID("Javier Balboa"));		// Use Santiago governor as store for your original ship
			ExchangeCharacterShip(Pchar, characterFromID("Convoy_Captain1"));	// You take the captured convoy ship
			PChar.Ship.crew.quantity = MakeInt(GetMaxCrewQuantity(PChar) / 10);
			RemoveOfficersIndex(PChar, GetCharacterIndex(PChar.quest.convoy_officer));
			RemovePassenger(pchar, characterFromID(PChar.quest.convoy_officer));
			Preprocessor_AddQuestData("ship", PChar.Ship.Name);
			Preprocessor_AddQuestData("officer", GetMyFullName(characterFromID(PChar.quest.convoy_officer)));
			AddQuestRecord("Convoy Strike", 5);
			Preprocessor_Remove("officer");
			Preprocessor_Remove("ship");
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
//			LAi_SetOfficerType(romance);
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

		case "convoy_final_briefing":
			ChangeCharacterAddressGroup(romance, "Tutorial_Deck", "rld", "startloc");
			DoQuestReloadToLocation("Tutorial_Deck", "reload", "reload1", "convoy_final_briefing2");
		break;

		case "convoy_final_briefing2":
			if (PChar.sex == "woman")
			{
				GiveModel2Player("Ardent_F", true);
				logit("Finally! Out of that ill-fitting uniform and back into my proper clothes.");
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
			AddPassenger(PChar, CharacterFromID(PChar.quest.convoy_officer), 0);
			SetCharacterRemovable(characterFromID(PChar.quest.convoy_officer), false);
//			LAi_SetWarriorType(characterFromID("Convoy_Captain2"));
//			GiveItem2Character(characterfromID("Convoy_Captain2"), "blade22+2");
//			EquipCharacterByItem(characterfromID("Convoy_Captain2"),"blade22");
//			ResetHP(characterfromID("Convoy_Captain2"));
			Characters[GetCharacterIndex("Convoy_Captain2")].fantomtype = "trade";
			character_SetCompanionEnemyEnable(characterFromID("Convoy_Captain2"), true);
			character_SetCompanionEnemyEnable(characterFromID("Convoy_Captain3"), true);
			character_SetCompanionEnemyEnable(characterFromID("Convoy_Captain4"), true);
		break;

		case "convoy_setup_battle":
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
			Island_SetReloadEnableGlobal(PChar.location, false);

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

//			UpdateRelations();
			SetRMRelation(GetCharacterIndex("Convoy_Captain2"), SPAIN, REL_WAR);
			SetRMRelation(GetCharacterIndex("Convoy_Captain3"), SPAIN, REL_WAR);
			SetRMRelation(GetCharacterIndex("Convoy_Captain4"), SPAIN, REL_WAR);
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_ENEMY);
			HoistFlag(SPAIN);

			Pchar.quest.convoy_battle_over.win_condition.l1 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l1.character = "Convoy_Captain2";
			Pchar.quest.convoy_battle_over.win_condition.l2 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l2.character = "Convoy_Captain3";
			Pchar.quest.convoy_battle_over.win_condition.l3 = "NPC_Death";
			Pchar.quest.convoy_battle_over.win_condition.l3.character = "Convoy_Captain4";
			Pchar.quest.convoy_battle_over.win_condition = "convoy_battle_over";
			Pchar.quest.convoy_report_to_santiago.win_condition.l1 = "location";
			PChar.quest.convoy_report_to_santiago.win_condition.l1.character = Pchar.id;
			Pchar.quest.convoy_report_to_santiago.win_condition.l1.location = "Santiago_townhall";
			Pchar.quest.convoy_report_to_santiago.win_condition = "convoy_report_to_santiago";
//			LAi_QuestDelay("convoy_setup_battle2", 0.0);
		break;

/*		case "convoy_setup_battle2":
			HoistFlag(ENGLAND);
		break; */

		case "convoy_battle_over":
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_FRIEND);
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			LAi_SetImmortal(romance, false);
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal(PChar.location, true);
			AddMoneyToCharacter(pchar, 400000 + rand(200000));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(PChar, "", 500);
				AddPartyExpChar(pchar, "Sailing", 500);
			}
			else {AddPartyExp(pchar, 6000);}
			AddQuestRecord("Convoy Strike", 6);
			LAi_SetHuberStayType(CharacterFromID("Javier Balboa"));
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "convoy_return"; // Exits to "convoy_get_ship_back" if you are in command of correct type of ship
		break;

		case "convoy_report_to_santiago":
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
			RemoveOfficersIndex(pchar, romanceidx);
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
			ChangeCharacterAddress(CharacterFromID("Dutch_sergeant"), "None", "");
		break;

		case "convoy_get_ship_back":
			AddQuestRecord("Convoy Strike", 7);
//			AddPassenger(PChar, CharacterFromID(PChar.quest.convoy_officer), 0);
			SetCharacterRemovable(characterFromID(PChar.quest.convoy_officer), true);
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
			DoQuestReloadToLocation("Santiago_townhall", "goto", "goto8", "convoy_next_day_townhall");
		break;

		case "convoy_next_day_townhall":
			WaitDate("", 0, 0, 1, 0, 0);
			SetCurrentTime(10.00, 0);
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
			if(!isofficer(romance)) SetOfficersIndex(Pchar, 1, romanceidx);
			LAi_SetOfficerType(romance);
			Preprocessor_AddQuestData("ship", Characters[GetCharacterIndex("Javier Balboa")].Ship.Name);
			Preprocessor_AddQuestData("romance", GetMyName(romance));
			AddQuestRecord("Convoy Strike", 8);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("ship");
			RemoveOfficersIndex(pchar, romanceidx);
			RemovePassenger(pchar, romance);

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
				ExchangeCharacterShip(characterFromID("Javier Balboa"), romance); // Captured ship goes to "romance"
				DeleteQuestAttribute("convoy_officer");
				LAi_SetActorType(romance);
				LAi_ActorFollowEverywhere(romance, "", 10.0);
			}
			PChar.quest.ardent_convoy = "trade_proposal";
			Pchar.quest.Willemstad_residence2.win_condition.l1 = "location";
			PChar.quest.Willemstad_residence2.win_condition.l1.character = Pchar.id;
			Pchar.quest.Willemstad_residence2.win_condition.l1.location = "Willemstad_townhall";
			Pchar.quest.Willemstad_residence2.win_condition = "convoy_Willemstad_residence2";
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
				ExchangeCharacterShip(characterFromID("Javier Balboa"), romance); // Captured ship goes to "romance"
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
			RemoveCharacterCompanion(Pchar, romance));
			AddPassenger(PChar, romance, 0);
			SetOfficersIndex(Pchar, 1, romanceidx);
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
			LAi_ActorDialog(CharacterFromID("Hans Kloss"),PChar,"convoy_reset_kloss",5.0,5.0);
		break;

		case "convoy_reset_kloss":
			LAi_SetHuberStayType(CharacterFromID("Hans Kloss"));
			LAi_SetOfficerType(romance);
			AddQuestRecord("Convoy Strike", 9);
			PChar.quest.ardent_convoy = "return_from_trade";
			Characters[GetCharacterIndex("Javier Balboa")].dialog.CurrentNode = "convoy_return_from_trade"; // When you talk to governor about trade deal, exits to "convoy_ending"
			Pchar.quest.convoy_santiago_residence_finale.win_condition.l1 = "location";
			PChar.quest.convoy_santiago_residence_finale.win_condition.l1.character = Pchar.id;
			Pchar.quest.convoy_santiago_residence_finale.win_condition.l1.location = "Santiago_townhall";
			Pchar.quest.convoy_santiago_residence_finale.win_condition = "convoy_santiago_residence_finale";
		break;

		case "convoy_santiago_residence_finale":
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 1;
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(romance, "Santiago_townhall", "goto", "goto9");
			LAi_SetActorType(romance);
			LAi_ActorFollowEverywhere(romance, "", 10.0);
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
			LAi_SetHuberStayType(CharacterFromID("Javier Balboa"));
			LAi_SetOfficerType(romance);
			SetCharacterRemovable(romance, true);
			DeleteAttribute(PChar, "quest.ardent_convoy");
			Locations[FindLocation("Santiago_townhall")].reload.l1.disable = 0;
			DisableFastTravel(false);
		break;


		case "test":
logit("You have been diverted here for test purposes. Normal service will be resumed as soon as possible.");
		break;

		PChar.questnotfound = true; // PB: Testing
	}
}

string Get_Speaker()
{
	ref PChar = GetMainCharacter();
	string speaker = "";
	int n;
	for (n=1; n<OFFICER_MAX; n++)
	{
		if(GetOfficersIndex(PChar, n) != -1)
		{
			speaker = characters[GetOfficersIndex(Pchar, n)].id;
			break;
		}
	}
	return speaker;
}