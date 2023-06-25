void QuestComplete(string sQuestName)
{
	ref PChar, sld;
// KK -->
	int iPassenger, cidx, iHP, cc, n;
	float locx, locy, locz;
	string homelocation, homegroup, homelocator, temp;
	int canQty = 0;
	int crewQty = 0;
// <-- KK
	aref arship; // PB

	PChar = GetMainCharacter();

	switch(sQuestName)
	{
		case "begining":
			Locations[FindLocation("Labirint_3")].models.always.koster = "door";
			Locations[FindLocation("Labirint_3")].models.always.koster.locator.group = "door";
			Locations[FindLocation("Labirint_3")].models.always.koster.locator.name = "door1";
			Locations[FindLocation("Labirint_3")].models.always.koster.tech = "dLightModel";
			Character_SetAbordageEnable(characterFromID("Barbossa"), false);

			LAi_SetImmortal(characterFromID("Barbossa"), true);
			LAi_SetCrewImmortal(characterFromID("Barbossa"), 2); // KK
			characters[GetCharacterindex("Barbossa")].ship.hp = 100000;

			/* ccc open Oxbay locations
			Locations[FindLocation("Labirint_3")].reload.l28.disable = true;
			Locations[FindLocation("Oxbay_canyon")].reload.l3.disable = true;

			Locations[FindLocation("Oxbay_town")].reload.l2.disable = true;

			Locations[FindLocation("Oxbay_town")].reload.l55.disable = true;
			*/

			Island_SetReloadEnableLocal("KhaelRoa", "reload_1", false);

			LAi_RemoveLoginTime(characterFromID("Danielle"));

// KK -->
			if (!CheckQuestAttribute("StartAdventure", "begin")) {
				pchar.quest.Story_LeavingOxbay.win_condition.l1 = "location";
				pchar.quest.Story_LeavingOxbay.win_condition.l1.location = "Oxbay";
				pchar.quest.Story_LeavingOxbay.win_condition = "Story_leavingOxbay";
			}
			DisableTownCapture("Redmond", true);
			DisableTownCapture("Oxbay", true);
// <-- KK
			// NK - LAi_SetImmortal(characterFromID("FalaiseDeFleur Commander"), true);

			LAi_LocationMonstersGen(&locations[FindLocation("Oxbay_town_exit")], false);

			if (CheckQuestAttribute("StartAdventure", "begin")) LAi_QuestDelay("Story_leavingOxbay", 0.0); // KK
		break;

		//Персонаж покидает Оксбэй в первый раз - включение первого сюжетного ролика
		case "Story_leavingOxbay":
		//	ChangeCharacterAddress(characterFromID("Guy Gilroy"), "none", ""); // NK 05-07-20 - PB: Not necessary

			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen08 = 12.0;
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l3.disable = 0; // NK
			//Установка атрибута для проверки захваченности Оксбэя
			PChar.Quest.Story_OxbayCaptured = "1";
			//Смена национальности форта Оксбэя
			// KK Characters[GetCharacterIndex("Oxbay Commander")].nation = FRANCE;
			// KK Characters[GetCharacterIndex("Oxbay Commander")].model = "Soldier_fra";
			// NK - LAi_SetImmortal(characterFromID("Oxbay Commander"), true);
			// KK SetTownNation("Oxbay", FRANCE); // NK
			//Смена английских солдат в Оксбэе на французских
			//Удаление английских
			CaptureTownForNation("Oxbay", FRANCE);	// KK

			// KK: Set French Soldiers for Oxbay -->
			for (n = 0; n < CHARACTERS_QUANTITY; n++)
			{
				if (!CheckAttribute(characters[n], "location")) continue;
				if (FindLocation(characters[n].location) == -1) continue;
				if (GetTownIDFromLocID(characters[n].location) == "Oxbay")
				{
					if (isOfficer(characters[n])) continue;		// LDH fix for our officers becoming French soldiers on leaving Oxbay - 19Jan09
					if (isSoldier(characters[n]) != UNKNOWN_NATION)
					{
						characters[n].Dialog.Filename = "Story_Fra_Occup_common_dialog.c";
						characters[n].greeting = "Gr_Story_French Occupant";
					}
				}
			}
			// KK: Set French Soldiers for Oxbay <--

			// ADDING GOODS AND CREW TO THEIR SHIPS // changed by MAXIMUS [gunpowder mod] --> // KK -->
			SetCrewQuantity(characterFromID("Remy Gatien"), makeint(GetMaxCrewQuantity(characterFromID("Remy Gatien"))));
			SetCharacterGoods(characterFromID("Remy Gatien"),GOOD_WHEAT,makeint(sti(GetCrewQuantity(characterFromID("Remy Gatien"))) * FOOD_PER_CREW * WHEAT_DAYS));
			SetCharacterGoods(characterFromID("Remy Gatien"),GOOD_RUM,makeint(GetCrewQuantity(characterFromID("Remy Gatien"))) * FOOD_PER_CREW * RUM_DAYS));
			SetCrewQuantity(characterFromID("Yves Giner"), makeint(GetMaxCrewQuantity(characterFromID("Yves Giner"))));
			SetCharacterGoods(characterFromID("Yves Giner"),GOOD_WHEAT,makeint(sti(GetCrewQuantity(characterFromID("Yves Giner"))) * FOOD_PER_CREW * WHEAT_DAYS));
			SetCharacterGoods(characterFromID("Yves Giner"),GOOD_RUM,makeint(GetCrewQuantity(characterFromID("Yves Giner"))) * FOOD_PER_CREW * RUM_DAYS));
			SetCrewQuantity(characterFromID("Begon Monchaty"), makeint(GetMaxCrewQuantity(characterFromID("Begon Monchaty"))));
			SetCharacterGoods(characterFromID("Begon Monchaty"),GOOD_WHEAT,makeint(sti(GetCrewQuantity(characterFromID("Begon Monchaty"))) * FOOD_PER_CREW * WHEAT_DAYS));
			SetCharacterGoods(characterFromID("Begon Monchaty"),GOOD_RUM,makeint(GetCrewQuantity(characterFromID("Begon Monchaty"))) * FOOD_PER_CREW * RUM_DAYS));
			// ADDING GOODS AND CREW TO THEIR SHIPS // changed by MAXIMUS [gunpowder mod] <-- // <-- KK

			// ADDING GUNPOWDER TO THEIR SHIPS // added by MAXIMUS [gunpowder mod] -->
			if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
				canQty = 0;
				crewQty = 0;
				canQty = GetCannonQuantity(characterFromID("Remy Gatien"));
				crewQty = GetCrewQuantity(characterFromID("Remy Gatien"));
				SetCharacterGoods(characterFromID("Remy Gatien"),GOOD_GUNPOWDER,makeint(canQty*5)+makeint(crewQty*3));
				canQty = GetCannonQuantity(characterFromID("Yves Giner"));
				crewQty = GetCrewQuantity(characterFromID("Yves Giner"));
				SetCharacterGoods(characterFromID("Yves Giner"),GOOD_GUNPOWDER,makeint(canQty*5)+makeint(crewQty*3));
				canQty = GetCannonQuantity(characterFromID("Begon Monchaty"));
				crewQty = GetCrewQuantity(characterFromID("Begon Monchaty"));
				SetCharacterGoods(characterFromID("Begon Monchaty"),GOOD_GUNPOWDER,makeint(canQty*5)+makeint(crewQty*3));
			}// TIH <-- mod toggle
			// ADDING GUNPOWDER TO THEIR SHIPS // added by MAXIMUS [gunpowder mod] <--

			Group_CreateGroup("Story_French_Squadron");
			Group_AddCharacter("Story_French_Squadron", "Remy Gatien");
			Group_AddCharacter("Story_French_Squadron", "Yves Giner");
			Group_AddCharacter("Story_French_Squadron", "Begon Monchaty");
			Group_SetGroupCommander("Story_French_Squadron", "Remy Gatien");
			Group_SetAddress("Story_French_Squadron", "Oxbay", "Quest_Ships","Quest_Ship_7");

// KK -->
			if (!CheckQuestAttribute("StartAdventure", "begin")) {
				//Перемещение Реймса в резиденцию губернатора
				ChangeCharacterAddress(characterFromID("Raoul Rheims"), "Redmond_residence", "goto1");

				//Заведение квеста на встречу с Реймсом в резиденции губернатора и уход Реймса
				Pchar.quest.Story_First_Meeting_with_Rheims.win_condition.l1 = "location";
				Pchar.quest.Story_First_Meeting_with_Rheims.win_condition.l1.location = "redmond_residence";
				Pchar.quest.Story_First_Meeting_with_Rheims.win_condition = "Story_First_Meeting_with_Rheims";

				//заведение квеста на диалог со стражником
				if(GetServedNation() == ENGLAND || GetServedNation() == PERSONAL_NATION)
				{
					pchar.quest.first_time_to_redmond_townhall.win_condition.l1 = "locator";
					pchar.quest.first_time_to_redmond_townhall.win_condition.l1.location = "Redmond_town_01";
					pchar.quest.first_time_to_redmond_townhall.win_condition.l1.locator_group = "goto";
					pchar.quest.first_time_to_redmond_townhall.win_condition.l1.locator = "goto10";
					pchar.quest.first_time_to_redmond_townhall.win_condition = "first_time_to_redmond_townhall_complete";
				}

				Locations[FindLocation("Redmond_town_01")].locators_radius.goto.goto10 = 2.0;

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

//KK & TIH -->
				SetQuestHeader("Story_OxbayCaptured");
				// do enhanced flag deception and sailing method
				AddQuestRecord("Story_OxbayCaptured", 1);
				Pchar.quest.Story_InvasionVideoAfterLeaveOxbay.win_condition.l1 = "MapEnter";
				Pchar.quest.Story_InvasionVideoAfterLeaveOxbay.win_condition = "Story_InvasionVideoAfterLeaveOxbay";
//KK & TIH <--
				Locations[FindLocation("Oxbay_town")].reload.l2.disable = false;
				Locations[FindLocation("Oxbay_town")].reload.l55.disable = false;
			}
// <-- KK
			switch(LanguageGetLanguage())
			{
				case "SPANISH": temp = TranslateString("","Crewmember of") + " " + GetMyName(PChar); break;
				case "RUSSIAN":
					if(strright(GetMyName(PChar),1) == "ь") temp = strleft(GetMyName(PChar), strlen(GetMyName(PChar))-1);
					else temp = GetMyName(PChar);
					temp = TranslateString("","Crewmember of") + " " + temp + "я";
				break;
				temp = GetMyName(PChar) + TranslateString("","'s crewmember");
			}
			for(n=1; n<=3; n++)
			{
				Characters[GetCharacterIndex("Blaze_Crewmember_0"+n)].name = temp;
			}
		break;

//TIH -->
		// makes the movie occur ONLY after finally leaving oxbay island
		case "Story_InvasionVideoAfterLeaveOxbay":
			// worldmap cancel screwup prevention
			CI_CreateAndSetControls( "WorldMapControls", "WMapCancel", -1, 0, true );
			if(LanguageGetLanguage() == "RUSSIAN") PostVideoAndQuest("standard\RUSSIAN\Invasion",1,"Story_MapLoadAfterleavingOxbay");
			else PostVideoAndQuest("Invasion",1,"Story_MapLoadAfterleavingOxbay");
		break;
//TIH <--

		case "Story_MapLoadAfterleavingOxbay":
//KK & TIH -->
			if(GetServedNation() == ENGLAND || GetServedNation() == PERSONAL_NATION)
				SetRMRelation(PChar, FRANCE, REL_WAR); // TIH moved here as it's not flag specific, and to make sure they are at war, "REL_WAR" was "GetRMRelation(PChar, FRANCE) - 1." Nov2'06
			// return the key settings to the user
			ControlsInit(GetTargetPlatform(), false);
			// Screwface
			SaveGlobalOptions();// TIH return the key settings to the user Sep3'06
			// Screwface : end
			// fix the dead sounds after movie playback
			ResumeAllSounds();
			//SetWeatherScheme("seashore_weather");
		// TIH moved up^	SetRMRelation(PChar, FRANCE, GetRMRelation(PChar, FRANCE) - 1.);
			if(GetServedNation() == ENGLAND || GetServedNation() == PERSONAL_NATION)
				SetRMRelation(PChar, FRANCE, REL_WAR);	// TIH to make sure they are at war, "REL_WAR" was "GetRMRelation(PChar, FRANCE)" Nov2'06
			if(GetServedNation() == ENGLAND)
				HoistFlag(ENGLAND);	// PB: Hoist English flag for continuation of the story
			AddQuestRecord("Story_OxbayCaptured", 2);
//KK & TIH <--
			Locations[FindLocation("Redmond_Residence")].reload.l1.disable = 1;
		break;

		case "first_time_to_redmond_townhall_complete":
			LAi_SetActorType(characterFromID("Eng_soldier_5"));
			characters[GetCharacterIndex("Eng_soldier_5")].dialog.currentnode = "who_you_blaze";
			LAi_ActorDialogNow(characterFromID("Eng_soldier_5"), pchar, "first_time_to_redmond_townhall_complete_2", -1);
		break;

		case "first_time_to_redmond_townhall_complete_2":
			LAi_SetGuardianType(characterFromID("Eng_soldier_5"));
			LAi_group_MoveCharacter(characterFromID("Eng_soldier_5"), "ENGLAND_SOLDIERS");
		break;

		//При заходе игрока в резиденцию Редмонда Реймс покидает ее
		case "Story_First_Meeting_with_Rheims":
			pchar.quest.first_time_to_redmond_townhall.over = "yes";
			LAi_SetActorType(Pchar);
			LAi_SetActorType(characterFromID("Raoul Rheims"));
			//Выставление Реймсу нужной ноды
			Characters[GetCharacterIndex("Raoul Rheims")].Dialog.CurrentNode = "First_meeting";
			LAi_ActorFollow(pchar, characterFromID("Raoul Rheims"), "", 1.0);
			LAi_ActorFollow(characterFromID("Raoul Rheims"), pchar, "Story_First_Meeting_with_Rheims_2", 1.0);
		break;

		case "Story_First_Meeting_with_Rheims_2":
			//----------------Реймс подходит и просит его пропустить!
			LAi_ActorWaitDialog(Pchar, characterFromID("Raoul Rheims"));
			LAi_ActorDialog(characterFromID("Raoul Rheims"), Pchar, "", 5.0, 0);
		break;

		case "Rheims_away_from_residence":
			Locations[FindLocation("Redmond_Residence")].reload.l1.disable = 0;
			//----------------Отправляем игрока в соседний локатор, чтобы он не мешал Реймсу выйти
			LAi_ActorGoToLocator(PChar, "goto", "goto7", "", 4.0);
			//----------------Отправляем Реймса в локатор
			LAi_ActorGoToLocator(CharacterFromID("Raoul Rheims"), "Reload", "reload1", "Story_Rheims_leaves", 2.0);
		break;

		case "Story_Rheims_leaves":
			//------------Реймс телепортируется в никуда
			ChangeCharacterAddress(characterFromID("Raoul Rheims"), "None", "");
			LAi_SetPlayerType(pchar);
			PChar.quest.Silehard_meeting = "thefirst"; // SJG Jan 09
		break;

// KK -->
		case "silehard_Story_Oxbay_Captured_15":
			PChar.Quest.Story_1stTaskReceived = "1";
			CloseQuestHeader("Story_OxbayCaptured");
			SetQuestHeader("Story_1stTaskReceived");
			AddQuestRecord("Story_1stTaskReceived",1);
			Pchar.quest.Story_1stTaskPayment = "10000";

			PChar.quest.StartAdventure = "complete";
			PChar.quest.StartAdventure.over = "yes";

			PChar.quest.Silehard_meeting = "done"; // SJG Jan 09
			SetRank(PChar, ENGLAND, GetOldRank(PChar, ENGLAND)); // PB: To prevent gameplay issues

			Pchar.quest.silehard_Story_Oxbay_Captured_15_afterExit.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.silehard_Story_Oxbay_Captured_15_afterExit.win_condition.l1.location = "Redmond_Residence";
			Pchar.quest.silehard_Story_Oxbay_Captured_15_afterExit.win_condition = "silehard_Story_Oxbay_Captured_15_afterExit";

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 1500); }
			else { AddPartyExp(pchar, 1500); }
		break;

		case "silehard_Story_Oxbay_Captured_15_afterExit":
			CaptureTownForNation("Greenford", ENGLAND);
			CaptureTownForNation("Falaise de Fleur", FRANCE);
			CaptureTownForNation("Isla Muelle", SPAIN);
			CaptureTownForNation("Douwesen", HOLLAND);
			CaptureTownForNation("Conceicao", PORTUGAL);
			CaptureTownForNation("Quebradas Costillas", PIRATE);

			DisableTownCapture("Greenford", true);
			DisableTownCapture("Falaise de Fleur", true);
			DisableTownCapture("Isla Muelle", true);
			DisableTownCapture("Douwesen", true);
			DisableTownCapture("Conceicao", true);
			DisableTownCapture("Quebradas Costillas", true);

			//Заведение квеста на диалог с солдатами у входа в город Оксбэй с острова
			Pchar.quest.Story_FraSoldiers_attack_in_jungles.win_condition.l1 = "location";
			Pchar.quest.Story_FraSoldiers_attack_in_jungles.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_FraSoldiers_attack_in_jungles.win_condition = "Story_FraSoldiers_attack_in_jungles";
			locations[FindLocation("Oxbay_town_exit")].vcskip = true;
			characters[GetCharacterIndex("Ox_Soldier_7")].Dialog.Filename = "Story_French Soldier_dialog.c";
			characters[GetCharacterIndex("Ox_Soldier_8")].Dialog.Filename = "Story_French Soldier_dialog.c";

			ChangeCharacterAddressGroup(characterFromID("Valentin Massoni"), "Oxbay_tavern", "Sit", "Sit5");
			Locations[FindLocation("Oxbay_town")].vcskip = true; // NK
			Locations[FindLocation("Oxbay_town_exit")].vcskip = true; // NK
			Locations[FindLocation("Oxbay_tavern")].vcskip = true; // NK
			LAi_SetSitType(characterFromID("Valentin Massoni"));
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 1500); }
			else { AddPartyExp(pchar, 1500); }
		break;
// <-- KK

		case "Story_SitAndDrinkWithMassoni":
			LAi_Fade("Story_SitAndDrinkWithMassoni_2", "Story_MassoniStartTalkingInTavern");
		break;

		case "Story_SitAndDrinkWithMassoni_2":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Oxbay_tavern", "sit", "sit4");
		break

		case "Story_MassoniStartTalkingInTavern":
			SetCurrentTime(23, 0);
			LAi_NoRebirthDisable(characterFromID("Ox_Soldier_7")); // KK
			LAi_NoRebirthDisable(characterFromID("Ox_Soldier_8")); // KK
			//Уничтожаем квест на атаку солдат в джунглях
			PChar.Quest.Story_FraSoldiers_attack_in_jungles.over = "yes";

			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 1;
			LAi_ActorDialogNow(Pchar, characterFromID("Valentin Massoni"), "", -1);
// KK -->
			characters[getCharacterIndex("Ox_Soldier_11")].Dialog.Filename = "Story_French Occupant_2_dialog.c";
			characters[getCharacterIndex("Ox_Soldier_12")].Dialog.Filename = "Story_French Occupant_2_dialog.c";
// <-- KK
		break;

		case "Story_Massony_Reload_to_Town":
			//Смена Диалога Стражникам на воротах
			Characters[GetCharacterIndex("Ox_Soldier_5")].Dialog.Filename = "Story_French Occupant_2_dialog.c"; // KK
			Characters[GetCharacterIndex("Ox_Soldier_6")].Dialog.Filename = "Story_French Occupant_2_dialog.c"; // KK
			//Установки им всем временного бессмертия
			LAi_SetImmortal(characterFromID("Ox_Soldier_5"), true); // KK
			LAi_SetImmortal(characterFromID("Ox_Soldier_6"), true); // KK
			LAi_SetImmortal(characterFromID("Valentin Massoni"), true);
			LAi_SetStayType(pchar);
			//Смена типа Валентину Массони
			LAi_SetActorType(characterFromID("Valentin Massoni"));

			//Перемещение Массони и Блэйза к выходу из Оксбэя
// KK -->
			ChangeCharacterAddress(characterFromID("Valentin Massoni"), "Oxbay_suburb", "locator11");
			DoQuestReloadToLocation("Oxbay_suburb", "goto", "locator12", "Story_Check_Blaze_And_Massoni");
// <-- KK
		break;

		case "Story_Check_Blaze_And_Massoni":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = true;

			LAi_SetActorType(pchar);
// KK -->
			LAi_SetActorType(characterFromID("Ox_Soldier_12"));
			LAi_ActorFollow(pchar, characterFromID("Ox_Soldier_12"), "Story_Check_Blaze_And_Massoni_2", 2.0);
// <-- KK
		break;

		case "Story_Check_Blaze_And_Massoni_2":
			LAi_type_actor_Reset(pchar);
// KK -->
			LAi_ActorWaitDialog(pchar, characterFromID("Ox_Soldier_12"));
			LAi_ActorDialog(characterFromID("Ox_Soldier_12"), Pchar, "massoni_answer_to_soldier", 3.0, 0);
// <-- KK
		break;

		case "massoni_answer_to_soldier":
			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen08 = 1.0;
			characters[getCharacterIndex("Valentin Massoni")].dialog.currentnode="Talk_to_Soldiers";
			LAi_ActorWaitDialog(pchar, characterFromID("valentin massoni"));
			LAi_ActorDialog(characterFromID("valentin massoni"), Pchar, "prepare_FRANCE_SOLDIERS_return_to_post", 50, 0);
		break;

		case "prepare_FRANCE_SOLDIERS_return_to_post":
			pchar.quest.massoni_died.win_condition.l1 = "NPC_Death";
			pchar.quest.massoni_died.win_condition.l1.character = "Valentin Massoni";
			pchar.quest.massoni_died.win_condition = "massoni_died";

			LAi_SetPlayerType(pchar);
			//Игрок покидает город вслед за Массони
			Pchar.quest.Story_Walk_Away_with_Massoni.win_condition.l1 = "location";
			Pchar.quest.Story_Walk_Away_with_Massoni.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_Walk_Away_with_Massoni.win_condition = "Story_Walk_Away_with_Massoni";

			//Массони уходит в ворота Оксбэя
// KK -->
			LAi_ActorGoToLocation(characterFromID("Valentin Massoni"), "reload", "Falaise_de_fleur_location_02_01", "Oxbay_town_exit", "goto", "Citizen08", "", 5.0);
			LAi_SetImmortal(characterFromID("Ox_Soldier_11"), false);
			LAi_SetImmortal(characterFromID("Ox_Soldier_12"), false);
			//Солдаты возвращаются на свои места
			LAi_ActorGoToLocator(characterFromID("Ox_Soldier_12"), "goto", "locator35", "Story_Fra_Occupant_01_ReturnedToPost", 5.0);
// <-- KK
			//Увеличиваем радуис детекторного локатора
			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen018 = 2.0;
			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen05 = 3.0;
			//Устанавливается диалог для Массони
			Characters[GetCharacterIndex("Valentin Massoni")].Dialog.CurrentNode = "What_are_you_waiting_for";
			//Смена Диалога Стражникам на воротах
// KK -->
			Characters[GetCharacterIndex("Ox_Soldier_11")].Dialog.Filename = "Story_French Occupant_dialog.c";
			Characters[GetCharacterIndex("Ox_Soldier_12")].Dialog.Filename = "Story_French Occupant_dialog.c";
			//Here the soldiers should be reset
			//soldier 1
			sld = characterFromID("Ox_Soldier_7")
			sld.Dialog.Filename = "Story_Fra_Occup_common_dialog.c";
			if(GetDifficulty() < DIFFICULTY_SEADOG)
			{
				ChangeHPBonus(sld,175);
				RemoveSkillCharMod(sld, "Fencing","drunk");
				RemoveSkillCharMod(sld, "Accuracy","drunk");
				RemoveSkillCharMod(sld, "Defence","drunk");
			}
			//soldier 2
			sld = characterFromID("Ox_Soldier_8")
			sld.Dialog.Filename = "Story_Fra_Occup_common_dialog.c";
			if(GetDifficulty() < DIFFICULTY_SEADOG)
			{
				ChangeHPBonus(sld,175);
				RemoveSkillCharMod(sld, "Fencing","drunk");
				RemoveSkillCharMod(sld, "Accuracy","drunk");
				RemoveSkillCharMod(sld, "Defence","drunk");
			}
// <-- KK
		break;

		case "Story_Fra_Occupant_01_ReturnedToPost":
// KK -->
			LAi_ActorTurnByLocator(characterFromID("Ox_Soldier_12"), "goto", "locator35");
			LAi_SetGuardianType(characterFromID("Ox_Soldier_12"));
			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_12"), "FRANCE_SOLDIERS");
// <-- KK
		break;

		//игрок выходит в джунгли вслед за Массони
		case "Story_Walk_Away_with_Massoni":
			LAi_SetImmortal(characterFromID("Ox_Soldier_5"), false); // KK
			LAi_SetImmortal(characterFromID("Ox_Soldier_6"), false); // KK
			ChangeCharacterAddress(characterFromID("Valentin Massoni"), "Oxbay_town_exit", "Citizen08");

			LAi_SetImmortal(characterFromID("Valentin Massoni"), false);
			LAi_SetCheckMinHP(characterFromID("Valentin Massoni"), LAi_GetCharacterHP(characterFromID("Valentin Massoni"))-0.1, false, "Massoni_doomed"); // KK

			LAi_type_actor_Reset(characterFromID("Valentin Massoni"));

//			SafePortLeave(GetCurrentLocationNation(), false); // KK
			SafePortLeave(GetLocationNationFromID(GetCharacterShipLocation(pchar)), false); // PB

			LAi_ActorGoToLocator(characterFromID("Valentin Massoni"), "Goto", "citizen018", "Story_Massoni_go_walking", 50.0);
// KK -->
			LAi_SetGuardianType(characterFromID("Ox_Soldier_7"));
			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_7"), "FRANCE_SOLDIERS");
			LAi_SetGuardianType(characterFromID("Ox_Soldier_8"));
			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_8"), "FRANCE_SOLDIERS");
// <-- KK
			LAi_group_MoveCharacter(characterFromID("Valentin Massoni"), "FRANCE_SOLDIERS");
			LAi_group_SetHearRadius("FRANCE_SOLDIERS", 100.0);
			DeleteAttribute(&Locations[FindLocation("Oxbay_town")],"vcskip"); // NK
			DeleteAttribute(&Locations[FindLocation("Oxbay_town_exit")],"vcskip"); // NK
			DeleteAttribute(&Locations[FindLocation("Oxbay_tavern")],"vcskip"); // NK
		break;

		case "massoni_died":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = false;

			GiveItem2Character(Pchar, "Massoni_papers");
			AddQuestRecord("Story_1stTaskReceived", 13);

			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition = "Story_Massoni_order_attack_Blaze_denied";
		break;

		//Игрок и пьяный Массони идут в джунглях, и дойдя до локатора, массони начинает диалог
		case "Story_Massoni_go_walking":
			LAi_ActorDialog(characterFromID("Valentin Massoni"), Pchar, "", 20.0, 1.0);
		break;

		case "Massony_run_to_last_locator":
			LAi_ActorGoToLocator(characterFromID("Valentin Massoni"), "goto", "citizen05", "Story_Massoni_found_Cheating", 20.0);
		break;

		//игрок доходит до локатора где Массони отказывается идти дальше
		case "Story_Massoni_found_Cheating":
			Characters[GetCharacterIndex("Valentin Massoni")].Dialog.CurrentNode = "Final_talk";
			PChar.quest.Story_Massoni_go_walking.over = "yes";
			LAi_ActorTurnToCharacter(characterFromID("Valentin Massoni"), PChar);
			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 0;
			LAi_ActorDialog(characterFromID("Valentin Massoni"), Pchar, "", 20.0, 1.0);
		break;

		case "Massoni_spared":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = false;
			//Массони бежит к городу
			pchar.quest.massoni_died.over = "yes";
			LAi_ActorRunToLocator(characterFromID("Valentin Massoni"), "reload", "reload3", "Story_Massoni_order_attack_Blaze", 30.0);
			Pchar.quest.Story_1stTaskComplete = 1;
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "Falaise_de_fleur_port_01", "goto13");
			SetCharacterShipLocation(characterFromID("Virgile boon"), "Falaise_de_Fleur_port_01");
			//Квест на появление Блэйза на Фале де Флер
			Pchar.quest.Story_Appear_on_Falaise.win_condition.l1 = "location";
			Pchar.quest.Story_Appear_on_Falaise.win_condition.l1.location = "Falaise_de_Fleur_port_01";
			Pchar.quest.Story_Appear_on_Falaise.win_condition = "Story_Appear_on_Falaise";

			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition.l1 = "location";
			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition.l1.location = "Falaise_de_fleur_shore";
			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition = "Story_Appear_on_Falaise_shore";
			//Квест на потопление барка "Ойсу"
		// TIH --> alternate method - allows capturing him from boarding, or killing him, to win the quest
			Pchar.quest.Story_Sink_Oiseau1.win_condition.l1 = "Ship_HP";
			Pchar.quest.Story_Sink_Oiseau1.win_condition.l1.character = "Virgile Boon";
			Pchar.quest.Story_Sink_Oiseau1.win_condition.l1.quantity = 1;
			Pchar.quest.Story_Sink_Oiseau1.win_condition.l1.operation = "<";
			Pchar.quest.Story_Sink_Oiseau1.win_condition = "Story_Sink_Oiseau";// TIH can use same named end action Oct31'06
			Pchar.quest.Story_Sink_Oiseau2.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_Sink_Oiseau2.win_condition.l1.character = "Virgile Boon";
			Pchar.quest.Story_Sink_Oiseau2.win_condition = "Story_Sink_Oiseau";// TIH can use same named end action Oct31'06
		// TIH <--
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition = "Story_Massoni_order_attack_Blaze_denied";
		break;

		case "France_becomes_neutral":
//			if(GetRMRelation(PChar, FRANCE) < REL_AMNESTY) RMAmnesty(PChar, FRANCE); // NK fix 05-03-26 SetRMRelation(PChar, FRANCE, REL_AFTERATTACK); // RM - SetNationRelation2MainCharacter(FRANCE, RELATION_NEUTRAL);
			// TIH --> well, if they become neutral, we need to set them as such! Aug27'06
			if (GetRMRelation(PChar, FRANCE) < REL_AFTERATTACK) {
				SetRMRelation(PChar, FRANCE, REL_AFTERATTACK);
			}
			// TIH <--
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		break;

		case "Massoni_doomed":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = false;

			LAi_RemoveCheckMinHP(characterFromID("Valentin Massoni"));
			LAi_type_actor_Reset(characterFromID("Valentin Massoni"));

			if (CheckCharacterItem(Pchar,"Massoni_papers"))
			{
				pchar.quest.massoni_died.over = "yes";
			}

			LAi_ActorAttack(characterFromID("Valentin Massoni"), pchar, "");
			Pchar.quest.Story_1stTaskComplete = "1";

			ChangeCharacterAddress(CharacterFromID("Faust Gasquet"), "Falaise_de_fleur_port_01", "goto1");
			SetCharacterShipLocation(characterFromID("Virgile boon"), "Falaise_de_Fleur_port_01");
			//Квест на появление Блэйза на Фале де Флер
			Pchar.quest.Story_Appear_on_Falaise.win_condition.l1 = "location";
			Pchar.quest.Story_Appear_on_Falaise.win_condition.l1.location = "Falaise_de_Fleur_port_01";
			Pchar.quest.Story_Appear_on_Falaise.win_condition = "Story_Appear_on_Falaise";

			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition.l1 = "location";
			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition.l1.location = "Falaise_de_fleur_shore";
			Pchar.quest.Story_Appear_on_Falaise_shore.win_condition = "Story_Appear_on_Falaise_shore";
			//Квест на потопление барка "Ойсу"
		// TIH --> alternate method - allows capturing him from boarding, or killing him, to win the quest
			Pchar.quest.Story_Sink_Oiseau1.win_condition.l1 = "Ship_HP";
			Pchar.quest.Story_Sink_Oiseau1.win_condition.l1.character = "Virgile Boon";
			Pchar.quest.Story_Sink_Oiseau1.win_condition.l1.quantity = 1;
			Pchar.quest.Story_Sink_Oiseau1.win_condition.l1.operation = "<";
			Pchar.quest.Story_Sink_Oiseau1.win_condition = "Story_Sink_Oiseau";// TIH can use same named end action Oct31'06
			Pchar.quest.Story_Sink_Oiseau2.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_Sink_Oiseau2.win_condition.l1.character = "Virgile Boon";
			Pchar.quest.Story_Sink_Oiseau2.win_condition = "Story_Sink_Oiseau";// TIH can use same named end action Oct31'06
		// TIH <--

			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition = "Story_Massoni_order_attack_Blaze_denied";
		break;

		//Массони добегает до ворот и приказывает стражникам, если они еще есть, убить Блэйза
		case "Story_Massoni_order_attack_Blaze":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			ChangeCharacterAddress(characterFromID("Valentin Massoni"), "none", "");
		break;

		case "Story_Massoni_order_attack_Blaze_denied":
			ChangeCharacterAddress(characterFromID("Valentin Massoni"), "none", "");
		break;

		//Солдаты завязывают с игроком разговором, когда он подходит к Оксбэю с суши.
		case "Story_FraSoldiers_attack_in_jungles":
			LAi_SetCheckMinHP(characterFromID("Ox_Soldier_7"), LAi_GetCharacterHP(characterFromID("Ox_Soldier_7"))-1.0, false, "fight_before_enter_to_oxbay"); // KK
			LAi_SetCheckMinHP(characterFromID("Ox_Soldier_8"), LAi_GetCharacterHP(characterFromID("Ox_Soldier_8"))-1.0, false, "fight_before_enter_to_oxbay"); // KK
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1 = "locator";
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1.location = "Oxbay_town_exit";
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1.locator_group = "goto";
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1.locator = "citizen08";
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition = "Story_FraSoldiers_attack_in_jungles_2";
		break;

		case "Story_FraSoldiers_attack_in_jungles_2":
// KK -->
			LAi_SetActorType(characterFromID("Ox_Soldier_7"));
			LAi_SetActorType(characterFromID("Ox_Soldier_8"));
			LAi_ActorFollow(characterFromID("Ox_Soldier_7"), Pchar, "Story_FraSoldiers_attack_in_jungles_3", 10.0);
			LAi_ActorFollow(characterFromID("Ox_Soldier_8"), Pchar, "", 10.0);

			LAi_NoRebirthEnable(characterFromID("Ox_Soldier_7"));
			LAi_NoRebirthEnable(characterFromID("Ox_Soldier_8"));
			if (LAi_group_GetPlayerAlarm() == 0)
			{
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("Ox_Soldier_8"), "", 10.0);
			}
// <-- KK
		break;

		case "Story_FraSoldiers_attack_in_jungles_3":
			LAi_ActorWaitDialog(pchar, characterFromID("Ox_Soldier_8")); // KK
			LAi_ActorDialog(characterFromID("Ox_Soldier_8"), Pchar, "player_back", 1.0, 1.0); // KK
		break;

		case "fight_before_enter_to_oxbay":
			pchar.quest.Story_FraSoldiers_attack_in_jungles_2.over = "yes";
			//soldier 1
			sld = characterFromID("Ox_Soldier_7")
			if(GetDifficulty() < DIFFICULTY_SEADOG)
			{
				ChangeHPBonus(sld,-175);
				SetSkillCharMod(sld, "Fencing", -3,"drunk","");
				SetSkillCharMod(sld, "Accuracy", -3,"drunk","");
				SetSkillCharMod(sld, "Defence", -3,"drunk","");
			}
			LAi_RemoveCheckMinHP(sld); // KK
			LAi_group_MoveCharacter(sld, "FRANCE_PATROL"); // KK
			//soldier 2
			sld = characterFromID("Ox_Soldier_8")
			if(GetDifficulty() < DIFFICULTY_SEADOG)
			{
				ChangeHPBonus(sld,-175);
				SetSkillCharMod(sld, "Fencing", -3,"drunk","");
				SetSkillCharMod(sld, "Accuracy", -3,"drunk","");
				SetSkillCharMod(sld, "Defence", -3,"drunk","");
			}
			LAi_RemoveCheckMinHP(sld); // KK
			LAi_group_MoveCharacter(sld, "FRANCE_PATROL"); // KK
			
			LAi_group_FightGroups("FRANCE_PATROL", LAI_GROUP_PLAYER, true);
		break;

		case "fra_soldiers_in_oxbay_exit_returned_to_post":
			//Отправляем солдат назад на посты
			LAi_ActorGoToLocator(characterFromID("Ox_Soldier_7"), "goto", "citizen09", "Fra_occupant_07_return_to_post", -1); // KK
			LAi_ActorGoToLocator(characterFromID("Ox_Soldier_8"), "goto", "citizen010", "Fra_occupant_08_return_to_post", -1); // KK
		break;

		case "Fra_occupant_07_return_to_post":
			LAi_SetGuardianType(characterFromID("Ox_Soldier_7")); // KK
			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_7"), "FRANCE_SOLDIERS"); // KK
		break;

		case "Fra_occupant_08_return_to_post":
			LAi_SetGuardianType(characterFromID("Ox_Soldier_8")); // KK
			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_8"), "FRANCE_SOLDIERS"); // KK
		break;

		//Блэйз в первый раз приплывает на Фале де Флер, чтобы поговорить с Беранжере
		case "Story_Appear_on_Falaise":
			DeleteAttribute(&Locations[FindLocation("Oxbay_town_exit")],"vcskip"); // PB
			pchar.quest.Story_Appear_on_Falaise_shore.over = "yes";
			LAi_group_SetHearRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);

			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen017 = 0.5;
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l3.disable = 1;
			Pchar.quest.main_line = "GetAGramotaFromBerangere";
			ChangeCharacterAddress(characterFromID("Amiel Berangere"), "Falaise_de_fleur_tavern_upstairs", "goto4");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Faust Gasquet"));
			LAi_ActorFollow(pchar, characterFromID("Faust Gasquet"), "", 2.0);
			LAi_ActorFollow(characterFromID("Faust Gasquet"), pchar, "Story_Appear_on_Falaise_2", 2.0);
		break;

		case "Story_Appear_on_Falaise_2":
			LAi_ActorWaitDialog(pchar, characterFromID("Faust Gasquet"));
			LAi_ActorDialog(characterFromID("Faust Gasquet"), Pchar, "return_faust_to_citizen", 2.0, 0);
			LAi_SetImmortal(characterFromID("Amiel Berangere"), true);
		break;

		case "Story_Appear_on_Falaise_shore":
			pchar.quest.Story_Appear_on_Falaise.over = "yes";
			LAi_group_SetHearRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);

			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen017 = 0.5;
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l3.disable = 1;
			Pchar.quest.main_line = "GetAGramotaFromBerangere";
			PChar.quest.Story_AskAboutBerangere = "3";
			ChangeCharacterAddress(characterFromID("Amiel Berangere"), "Falaise_de_fleur_tavern_upstairs", "goto4");
			LAi_SetCitizenType(characterFromID("Faust Gasquet"));// PW reset Faust from actor wait dialogue
			LAi_group_MoveCharacter(characterFromID("Faust Gasquet"), "FRANCE_CITIZENS");// PW reset Faust from actor wait dialogue

		break;

		case "return_faust_to_citizen":
			LAi_SetPlayerType(pchar);
			LAi_SetCitizenType(characterFromID("Faust Gasquet"));
			LAi_group_MoveCharacter(characterFromID("Faust Gasquet"), "FRANCE_CITIZENS");
		break;

		// TIH --> no longer need two seperate actions for the same result
		/*
		// TIH --> two different ways to end this quest Aug31'06
		case "Story_Sink_Oiseau1":
			Pchar.quest.Story_Sink_Oiseau1.over = "yes";
			Pchar.quest.Story_Sink_Oiseau2.over = "yes";
			//LAi_QuestDelay("Story_Sink_Oiseau", 0.0);// TIH this doesnt work while sailing
			QuestComplete("Story_Sink_Oiseau");// TIH do it direct //or: CompleteQuestName("Story_Sink_Oiseau");
		break;
		case "Story_Sink_Oiseau2":
			Pchar.quest.Story_Sink_Oiseau1.over = "yes";
			Pchar.quest.Story_Sink_Oiseau2.over = "yes";
			//LAi_QuestDelay("Story_Sink_Oiseau", 0.0);// TIH this doesnt work while sailing
			QuestComplete("Story_Sink_Oiseau");// TIH do it direct //or: CompleteQuestName("Story_Sink_Oiseau");
		break;
		// TIH <--
		*/
		// TIH <--
		case "Story_Sink_Oiseau":
			if(GetRMRelation(PChar, ENGLAND) < REL_AMNESTY) RMAmnesty(PChar, ENGLAND); // NK fix 05-03-26 SetRMRelation(PChar, ENGLAND, REL_AMNESTY); // RM - SetNationRelation2MainCharacter(ENGLAND, RELATION_FRIEND);
			SetCharacterShipLocation(characterFromID("Virgile boon"), "none");
			Pchar.quest.Story_Sink_Oiseau1.over = "yes";// TIH close the alternates Oct31'06
			Pchar.quest.Story_Sink_Oiseau2.over = "yes";// TIH close the alternates Oct31'06
			pchar.quest.Convoy_Virgile_Boon.over = "yes";
			pchar.quest.Convoy_Virgile_Boon2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			Pchar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = false;
			// TIH --> have it open up the island it locked before or open where the player currently is Oct31'06
			if (CheckAttribute(PChar, "quest.boonelockedisland"))
				{ Island_SetReloadEnableGlobal(PChar.quest.boonelockedisland, true); DeleteAttribute(PChar,"quest.boonelockedisland"); }
			else
				{ Island_SetReloadEnableGlobal(PChar.location, true); }
			//Island_SetReloadEnableGlobal(PChar.location, true);
			// TIH <--
			AddQuestRecord("Story_1stTaskReceived", 12);
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "none", "");
			ChangeCharacterAddress(characterFromID("Amiel Berangere"), "none", "");
			Pchar.quest.Story_1stTaskComplete = "Complete";
			if(GetRMRelation(PChar, FRANCE) > REL_WAR) SetRMRelation(PChar, FRANCE, REL_WAR); // RM
			LeaveService(PChar, FRANCE, false); // RM
			pchar.quest.story_askaboutberangere.over = "yes";
		break;

		//Блэйз приплывает с барком Ойсу на любой остров.
		case "Convoy_Virgile_Boon":
			SetCharacterRemovable(characterFromID("Virgile Boon"), true);
			pchar.quest.Convoy_Virgile_Boon2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			Pchar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal(PChar.location, false);
			PChar.quest.boonelockedisland = PChar.location;// TIH store what island was locked Oct31'06

			RemoveCharacterCompanion(Pchar, characterFromID("Virgile Boon"));
			SetCharacterRemovable(characterFromID("Virgile Boon"), true); // NK

			SetCharacterRelationBoth(GetCharacterIndex("Redmond Commander"),GetCharacterIndex("Virgile Boon"),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Greenford Commander"),GetCharacterIndex("Virgile Boon"),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("FalaiseDeFleur Commander"),GetCharacterIndex("Virgile Boon"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Virgile Boon"),GetMainCharacterIndex(),RELATION_ENEMY);

			Group_CreateGroup("Virgile Boon");
			Group_AddCharacter("Virgile Boon", "Virgile Boon");
			Group_SetGroupCommander("Virgile Boon", "Virgile Boon");
			Group_SetPursuitGroup("Virgile Boon", PLAYER_GROUP);
			Group_SetTaskAttack("Virgile Boon", PLAYER_GROUP, true);
			Group_LockTask("Virgile Boon");
			Group_SetAddress("Virgile Boon", Characters[GetMainCharacterIndex()].location, "", "");

			UpdateRelations();
		break;

		case "Convoy_Virgile_Boon2":
			SetCharacterRemovable(characterFromID("Virgile Boon"), true);
			pchar.quest.Convoy_Virgile_Boon.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			Pchar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal(PChar.location, false);
			PChar.quest.boonelockedisland = PChar.location;// TIH store what island was locked Oct31'06

			RemoveCharacterCompanion(Pchar, characterFromID("Virgile Boon"));
			SetCharacterRemovable(characterFromID("Virgile Boon"), true); // NK
			LAi_RemoveCheckMinHP(CharacterFromID("Virgile Boon")); // KK

			SetCharacterRelationBoth(GetCharacterIndex("Redmond Commander"),GetCharacterIndex("Virgile Boon"),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Greenford Commander"),GetCharacterIndex("Virgile Boon"),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("FalaiseDeFleur Commander"),GetCharacterIndex("Virgile Boon"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Virgile Boon"),GetMainCharacterIndex(),RELATION_ENEMY);

			Group_CreateGroup("Virgile Boon");
			Group_AddCharacter("Virgile Boon", "Virgile Boon");
			Group_SetGroupCommander("Virgile Boon", "Virgile Boon");
			Group_SetPursuitGroup("Virgile Boon", PLAYER_GROUP);
			Group_SetTaskAttack("Virgile Boon", PLAYER_GROUP, true);
			Group_LockTask("Virgile Boon");
			Group_SetAddress("Virgile Boon", Characters[GetMainCharacterIndex()].location, "", "");

			Sea_LoginGroupNow("Virgile Boon");

			HoistFlag(ENGLAND); // KK
		break;

		case "Story_BerangereStartTalkingToBlaze":
			pchar.quest.main_line = "";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Amiel Berangere"));
			LAi_ActorFollow(pchar, characterFromID("Amiel Berangere"), "", 1.5);
			LAi_ActorFollow(characterFromID("Amiel Berangere"), pchar, "Story_BerangereBeginsDialog", 1.5);
		break;

		case "Story_BerangereBeginsDialog":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Amiel Berangere"));
			LAi_ActorDialog(characterFromID("Amiel Berangere"), Pchar, "player_back", 1.0, 1.0);
		break;

		//Игрок убивает Эмиля Беранжере
		case "Story_BlazeStartsThinkAboutGramota":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			Pchar.Dialog.CurrentNode = "Story_FindBerangereDocuments";
			LAi_QuestDelay("Story_BlazeStartsThinkAboutGramota_2", 2.0);
		break;

		case "Story_BlazeStartsThinkAboutGramota_2":
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Story_FindBerangereDocuments";
			LAi_SetActorType(pchar);
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "Story_BlazeStartLookingForGramota":
			AddQuestRecord("Story_1stTaskReceived",9);

			// PB: Simplify to prevent CTD -->
			Event("QuestSceneCommand", "ssass", "gotopoint", "Story_FoundGramotaAndLebrettonAppeared", PChar, "goto", "goto2");
		/*	Event("QuestSceneCommand", "ssa", "stay", "", PChar);
			Event("QuestSceneCommand", "ssass", "TurnByLocator", "", PChar, "goto", "goto2");
			Event("QuestSceneCommand", "ssass", "gotopoint", "", PChar, "goto", "goto1");
			Event("QuestSceneCommand", "ssass", "gotopoint", "", PChar, "goto", "goto4");
			Event("QuestSceneCommand", "ssass", "gotopoint", "", PChar, "goto", "goto5");
			Event("QuestSceneCommand", "ssa", "stay", "", PChar);
			Event("QuestSceneCommand", "ssass", "turnbylocator", "Story_FoundGramotaAndLebrettonAppeared", PChar, "goto", "goto5");*/
			// PB: Simplify to prevent CTD <--
			//Event("QuestSceneCommand", "ssas", "action", "Story_FoundGramotaAndLebrettonAppeared", PChar, "");
			//------- !!!!!!!! Вставить проигрывание звука открывающейся двери
			PostEvent("startAfterWaitScene",0,"a",PChar);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 2000); }
			else { AddPartyExp(pchar, 2000); }
		break;

		case "Story_FoundGramotaAndLebrettonAppeared":
			//--------Получение предмета
			GiveItem2Character(Pchar,"Story_Gramota");
			//--------Постановка Вирджила Буна в первый порт Фале де Флер
			ChangeCharacterAddress(characterFromID("Virgile Boon"), "Falaise_de_Fleur_port_01", "goto1");
			//-------- Появление Антуана Лебреттона
			Characters[GetCharacterIndex("antoine lebretton")].dialog.CurrentNode = "Story_Berangere_killed";
			Locations[FindLocation("Falaise_De_Fleur_tavern_upstairs")].reload.l1.disable = 0;
			ChangeCharacterAddressGroup(characterFromID("antoine lebretton"), "Falaise_De_Fleur_tavern_upstairs", "reload","reload1");
			LAi_SetActorType(characterFromID("antoine lebretton"));
			//------- Убираем ненужного Фауста Гаске
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "none", "");
			LAi_ActorGoToLocator(pchar, "goto", "goto3", "before_lebretton_talk_with_us_in_upstairs", 4.0);
			LAi_ActorDialog(characterFromID("antoine lebretton"), Pchar, "", 3.0, 1.0);
		break;

		case "before_lebretton_talk_with_us_in_upstairs":
			LAi_ActorWaitDialog(pchar, characterFromID("Antoine lebretton"));
		break;

		case "Story_Lebretton_leaves_upstairs":
			LAi_SetPlayerType(pchar);
			//---------перегрузка Лебреттона обратно за стойку в таверне.
			ChangeCharacterAddressGroup(characterFromID("antoine lebretton"), "Falaise_De_Fleur_tavern", "merchant","goto1");
			//---------снимается бессмертие с Антуана Лебреттона
			LAi_SetMerchantType(characterFromID("antoine lebretton"));
			LAi_group_MoveCharacter(characterFromID("antoine lebretton"), "FRANCE_CITIZENS");
		break;

		case "Story_ReturnToFFPortToFindBoon":
			Characters[GetCharacterIndex("Tancrede Rimbaud")].dialog.filename = "Tancrede Rimbaud_dialog.c";
			LAi_SetActorType(characterFromID("Virgile Boon"));
			LAi_group_MoveCharacter(characterFromID("Virgile Boon"), "FRANCE_CITIZENS");
			LAi_SetActorType(characterFromID("Tancrede Rimbaud"));
			LAi_group_MoveCharacter(characterFromID("Tancrede Rimbaud"), "FRANCE_CITIZENS");
			LAi_ActorFollow(characterFromID("Virgile Boon"), characterFromID("Tancrede Rimbaud"), "Story_ReturnToFFPortToFindBoon_2", 10.0);
			LAi_SetCheckMinHP(characterFromID("Virgile Boon"), LAi_GetCharacterHP(characterFromID("Virgile Boon"))-1.0, false, "boon_becomes_citizen"); // KK
		break;

		case "boon_becomes_citizen":
			LAi_SetCitizenType(characterFromID("Virgile Boon"));
			LAi_group_MoveCharacter(characterFromID("Virgile Boon"), "FRANCE_CITIZENS");
		break;

		case "Story_ReturnToFFPortToFindBoon_2":
			LAi_ActorTurnToCharacter(characterFromID("Virgile Boon"), characterFromID("Tancrede Rimbaud"));
			LAi_ActorTurnToCharacter(characterFromID("Tancrede Rimbaud"), characterFromID("Virgile Boon"));
			LAi_ActorWaitDialog(characterFromID("Virgile Boon"), pchar);
			LAi_ActorWaitDialog(characterFromID("Tancrede Rimbaud"), pchar);
		break;

		case "Story_BoonStartTalkToTancredeAgain":
			LAi_ActorTurnToCharacter(characterFromID("Virgile Boon"), characterFromID("Tancrede Rimbaud"));
			LAi_ActorTurnToCharacter(characterFromID("Tancrede Rimbaud"), characterFromID("Virgile Boon"));
			LAi_ActorWaitDialog(characterFromID("Virgile Boon"), pchar);
			LAi_ActorWaitDialog(characterFromID("Tancrede Rimbaud"), pchar);
		break;

		case "Story_Blaze_and_Boon_leaving":
			characters[GetCharacterIndex("Virgile Boon")].location = "none";
			Characters[GetCharacterIndex("Virgile Boon")].nation = FRANCE; // RM
			//------------Выдача Квестов на нападение Буна на игрока
			Pchar.quest.Story_Convoy_Virgile_Boon_1.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.win_condition.l1.location = "Oxbay";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_2.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.win_condition.l1.location = "Redmond";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_3.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.win_condition.l1.location = "IslaMuelle";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_4.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.win_condition.l1.location = "Conceicao";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_5.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.win_condition.l1.location = "Douwesen";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_6.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.win_condition.l1.location = "QuebradasCostillas";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_7.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.win_condition.l1.location = "KhaelRoa";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.win_condition = "Convoy_Virgile_Boon";

			Pchar.quest.Story_Convoy_Virgile_Boon_8.win_condition.l1 = "location";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.win_condition.l1.location = "";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.win_condition = "Convoy_Virgile_Boon2";
			character_SetCompanionEnemyEnable(characterFromID("Virgile Boon"), true);

			LAi_SetCitizenType(characterFromID("Tancrede Rimbaud"));
			LAi_group_MoveCharacter(characterFromID("Tancrede Rimbaud"), "FRANCE_CITIZENS");
			LAi_RemoveCheckMinHP(characterFromID("Virgile Boon"));//MAXIMUS
			DeleteAttribute(characterFromID("Virgile Boon"), "quest.guard_protection"); // PB
		break;

		case "Story_Meeting_Ewan_Glover":
			//---------Капитан десантного шлюпа Эван Глоувер подходит к игроку знакомитьс
			LAi_SetActorType(characterFromID("Ewan Glover"));
			Locations[FindLocation("Greenford_port")].reload.l1.disable = 1;
			LAi_SetImmortal(characterFromID("Ewan Glover"), true);
			LAi_ActorDialog(characterFromID("Ewan Glover"), PChar, "", 3.0, 1.0);
			Locations[FindLocation("Greenford_port")].vcskip = true; // KK
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // NK
			Locations[FindLocation("Oxbay_town")].vcskip = true; // NK
		break;

		case "Ewan_Once_Again_exit_no_join":
			//---------Отправляем Глоувера к локатору
			LAi_ActorGoToLocator(characterFromID("Ewan Glover"), "goto", "goto2", "", -1);
		break;

		case "Ewan_exit_no_join":
			//---------Отправляем Гроувера к локатору
			LAi_ActorGoToLocator(characterfromID("Ewan Glover"), "reload", "reload_1_2", "Story_Glover_goes_to_tavern", -1);
		break;

		case "Ewan_Exit_need_some_walk":
			//---------Отправляем Глоувера к локатору
			LAi_ActorRunToLocator(characterfromID("Ewan Glover"),"Reload","reload4", "Story_Glover_to_tavern_on_Greenford", 20.0);
			pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.win_condition.l1 = "location";
			pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.win_condition.l1.location = "Greenford_tavern";
			pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.win_condition = "Story_Glover_to_tavern_on_Greenford";
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Are_you_ready_again";

			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2 = "Ship_location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition = "Story_Blaze_and_Glover_Land_troops";

			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1 = "NPC_death";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1.character = "Ewan Glover";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition = "Story_Blaze_and_Glover_Land_troops_denied";
		break;

		case "ewan_again_gain_quest_for_night":
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2 = "Ship_location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition = "Story_Blaze_and_Glover_Land_troops";

			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1 = "NPC_death";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1.character = "Ewan Glover";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition = "Story_Blaze_and_Glover_Land_troops_denied";
		break;

		case "Ewan_exit_business":
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 1;

			//---------Возвращаем обоим тип стоящих.
			LAi_SetCitizenType(characterfromID("Ewan Glover"));
			//---------Начинаем проверку на попадание игрока и Глоувера в локейшен ночной высадки
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2 = "Ship_location";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops.win_condition = "Story_Blaze_and_Glover_Land_troops";

			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1 = "NPC_death";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1.character = "Ewan Glover";
			Pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition = "Story_Blaze_and_Glover_Land_troops_denied";

			if (pchar.location == "Greenford_tavern")
			{
				//---------Выставляем время на вечер
				SetCurrentTime(23, 0);
				LAi_SetPlayerType(pchar);
				//---------Телепортируем Глоувера в никуда, а игрока на пристань Гринфорда
				ChangeCharacterAddress(characterFromID("Ewan Glover"), "none", "");

				DoReloadCharacterToLocation("Greenford_port", "Reload", "Reload4");
			}
			//Отключаем выход в карту
			//bQuestDisableMapEnter = true;
		break;

		case "Ewan_goodbye_exit":
			RemoveCharacterCompanion(Pchar, characterFromID("Ewan Glover"));
			SetCharacterRemovable(characterFromID("Ewan Glover"), true); // NK
			LAi_ActorGoToLocator(characterFromID("Ewan Glover"), "Reload", "reload1", "Story_Glover_leaves_on_complete", 60.0);
			AddQuestRecord("Story_2ndTask", 7); // NK
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("CounterSpy"));
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			ChangeCharacterAddressGroup(&Characters[GetCharacterIndex("CounterSpy")], "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
			DeleteAttribute(&Locations[FindLocation("Greenford_tavern")],"vcskip"); // NK
			DeleteAttribute(&Locations[FindLocation("Greenford_port")],"vcskip"); // KK

			Characters[GetCharacterIndex("Oweyn McDorey")].nation = ENGLAND;	// GR: So that he greets you properly when you go to the shipyard to hide
			Characters[GetCharacterIndex("Oweyn McDorey")].greeting = "Gr_Oweyn McDorey";
		break;

		case "Ewan_Glover_exit_join":
			//----------Присоединяем Эвана Глоувера к игроку
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Ewan Glover"));
			SetCharacterRemovable(characterFromID("Ewan Glover"), false);
			//----------Выставляем квест на потопление корабля Эвана
			Pchar.quest.Story_Convoy_Glover_to_Greenford.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_Convoy_Glover_to_Greenford.win_condition.l1.character = "Ewan Glover";
			Pchar.quest.Story_Convoy_Glover_to_Greenford.win_condition = "Story_Glover_Sunk2";
			//---------Отправляем Глоувера к локатору
			LAi_ActorRunToLocator(characterFromID("Ewan Glover"), "reload", "sea_1", "Story_Glover_leaves_tavern", 75.0);
			//-------перемещаем местного жителя к причалу Гринфорда
			ChangeCharacterAddress(characterFromID("Wilfred"), "Greenford_port", "goto20");
			//-------Заводим квест на попадание игрока в порт Гринфорда
			Pchar.quest.Story_Blaze_reaches_Greenford.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_reaches_Greenford.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Story_Blaze_reaches_Greenford.win_condition = "Story_Blaze_reaches_Greenford";

			Pchar.quest.Story_Blaze_reaches_shore1.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_reaches_shore1.win_condition.l1.location = "Oxbay_shore_01";
			Pchar.quest.Story_Blaze_reaches_shore1.win_condition = "Story_Blaze_reaches_shore1";

			Pchar.quest.Story_Blaze_reaches_shore2.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_reaches_shore2.win_condition.l1.location = "Oxbay_shore_02";
			Pchar.quest.Story_Blaze_reaches_shore2.win_condition = "Story_Blaze_reaches_shore1";

			Pchar.quest.Story_Blaze_reaches_shore3.win_condition.l1 = "location";
			Pchar.quest.Story_Blaze_reaches_shore3.win_condition.l1.location = "Oxbay_lighthouse";
			Pchar.quest.Story_Blaze_reaches_shore3.win_condition = "Story_Blaze_reaches_shore1";

			Pchar.quest.Story_Glover_leaves_tavern.win_condition.l1 = "location";
			Pchar.quest.Story_Glover_leaves_tavern.win_condition.l1.location = "Redmond";
			Pchar.quest.Story_Glover_leaves_tavern.win_condition = "Story_Glover_leaves_tavern";
		break;

		case "Story_Blaze_reaches_shore1":
			Pchar.quest.Story_Blaze_reaches_shore1.over = "yes";
			Pchar.quest.Story_Blaze_reaches_shore2.over = "yes";
			Pchar.quest.Story_Blaze_reaches_shore3.over = "yes";

			PlaceCharacter(characterFromID("Ewan Glover"), "goto");

			characters[GetCharacterIndex("Ewan Glover")].dialog.currentnode = "CameToOxbay_shore";
			LAi_type_actor_Reset(characterFromID("Ewan Glover"));
			LAi_ActorDialog(characterFromID("Ewan Glover"), pchar, "", 2.0, 1.0);
		break;

		case "prepare_Story_ReloadedtoGreenfordTavernWithGlover":
			SetCurrentTime(23, 0);
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // GR
			//---------Телепортируем Глоувера и игрока в таверну Гринфорда
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Greenford_tavern", "Sit", "Sit4");
			DoQuestReloadToLocation("Greenford_tavern", "candles", "sit3", "Story_ReloadedtoGreenfordTavernWithGlover");
		break;

		case "prepare_Story_ReloadedtoGreenfordTavernWithGlover_1":
			//---------Телепортируем Глоувера и игрока в таверну Гринфорда
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // GR
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Greenford_tavern", "Sit", "Sit4");
			//DoQuestReloadToLocation("Greenford_tavern", "candles", "sit3", "Story_ReloadedtoGreenfordTavernWithGlover");
			LAi_Fade("prepare_Story_ReloadedtoGreenfordTavernWithGlover_2", "Story_ReloadedtoGreenfordTavernWithGlover");
		break;

		case "prepare_Story_ReloadedtoGreenfordTavernWithGlover_2":
			LAi_SetSitType(characterFromID("Ewan Glover"));
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);

			ChangeCharacterAddressGroup(pchar, "Greenford_tavern", "candles", "sit3");
		break;

		case "Story_Glover_Sunk2":
			SetCharacterShipLocation(characterFromID("Ewan Glover"), "none");
			AddQuestRecord("Story_2ndTask", 8);
			Pchar.quest.Story_Glover_Sunk = true;

			Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			//bQuestDisableMapEnter = false;
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("Counterspy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
			Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Failed_in_last_moment";
		break;

		case "Story_Glover_goes_to_tavern":
			//--------перемещаем Эвана Глоувера в никуда... Предположительно, он в таверне Редмонда
			ChangeCharacterAddress(characterFromID("Ewan Glover"), "None", "");
			Pchar.Quest.Story_Ask_for_Glover = "1";
		break;

		case "Story_Glover_leaves_tavern":
			//--------перемещаем Эвана Глоувера в никуда... Предположительно, он на своем корабле
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Greenford_port", "Goto", "goto21");
			LAi_SetImmortal(characterFromID("Ewan Glover"), false);
			DeleteAttribute(&Locations[FindLocation("Greenford_tavern")],"vcskip"); // NK
			DeleteAttribute(&Locations[FindLocation("Greenford_port")],"vcskip"); // KK
		break;

		case "Story_Glover_goes_to_ship":
			//--------перемещаем Эвана Глоувера в никуда... Предположительно, он на своем корабле
			ChangeCharacterAddress(characterFromID("Ewan Glover"), "None", "");
			LAi_SetImmortal(characterFromID("Ewan Glover"), false);
		break;

		case "Story_Blaze_reaches_Greenford":
			ChangeCharacterAddress(characterFromID("Wilfred"), "Greenford_port", "goto20");

			Pchar.quest.Story_Blaze_reaches_shore1.over = "yes";
			Pchar.quest.Story_Blaze_reaches_shore2.over = "yes";
			Pchar.quest.Story_Blaze_reaches_shore3.over = "yes";

			Lai_SetStayType(pchar);
			//---------ставим рядом с Блэйзом Эвана Глоувера
			if (!LAi_IsDead(characterFromID("Ewan Glover")))
			{
				//AddQuestRecord("Story_2ndTask", 8); // NK
				Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "CameToGreenford";
				ChangeCharacterAddress(characterFromID("Ewan Glover"), "Greenford_port", "goto21");
				//LAi_type_actor_Reset(characterFromID("Ewan Glover"));
				LAi_SetActorType(characterFromID("Ewan Glover"));
				LAi_ActorDialog(characterFromID("Ewan Glover"), pchar, "Story_Blaze_reaches_Greenford_2", 2.0, 1.0);
			}
			else
			{
				LAi_QuestDelay("Story_Blaze_reaches_Greenford_2", 0.2);
			}
		break;

		case "Story_Blaze_reaches_Greenford_2":
			LAi_SetActorType(characterFromID("Wilfred"));
			LAi_ActorDialog(characterFromID("Wilfred"), Pchar, "", 4.0, 1.0);
			//---------На всякий случай делаем его бессмертным
			LAi_SetImmortal(characterFromID("Wilfred"), true);
		break;

		case "Wilfred_exit_failed":
			//--------Отправка Уилфреда в ворота Гринфорда.
			LAi_ActorRunToLocator(characterFromID("Wilfred"), "Reload","reload4", "Story_Wilfred_leaves_forever", 15.0);
			LAi_SetPlayerType(pchar);
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("CounterSpy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
		break;

		case "Wilfred_Exit_failed_in_last_moment":
			//--------Отправка Уилфреда к локатору релоада.
			LAi_ActorRunToLocator(characterFromID("Wilfred"), "Reload","reload2", "Story_Wilfred_leaves_forever", 15.0);
			LAi_SetPlayerType(pchar);
		break;

		case "Story_Wilfred_leaves_forever":
			//---------Отправляем Уилфреда в никуда, считая что он от горя сбежал домой
			ChangeCharacterAddress(characterFromID("Wilfred"), "None", "");
		break;

		case "Story_Convoy_Glover_to_Greenford":
			AddQuestRecord("Story_2ndTask", 4);
			//--------Зачисляем игроку проваленный квест
			Pchar.quest.Story_Glover_sunk = true;
			//--------Стартуем вторую половину задания
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("CounterSpy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
		break;

		case "Story_Wilfred_go_to_shore_prepare":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 2500); }
			else { AddPartyExp(pchar, 2500); }
			//---------Установка диалога Эвану Глоуверу
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Are_you_ready";
			LAi_type_actor_Reset(characterFromID("Ewan Glover"));
			LAi_ActorDialog(characterFromID("Ewan Glover"), Pchar, "player_back", 3.0, 5.0);
			//--------Запись в журнал
			AddQuestRecord("Story_2ndTask",6);
			//--------Отправка Уилфреда в ворота Гринфорда.
			LAi_ActorRunToLocator(characterFromID("Wilfred"), "Reload", "reload4", "Story_Wilfred_go_to_shore", 60.0);
		break;

		case "Story_Wilfred_go_to_shore":
			//---------Отправляем Уилфреда в никуда, считая что он отправился на берег встречать Блэйза
			ChangeCharacterAddress(characterFromID("Wilfred"), "None", "");
		break;

		case "Wilfred_exit_fight":
			LAi_ActorRunToLocator(characterfromID("Wilfred"), "goto", "locator8", "Story_Wilfred_scared_run_away", 40.0);
			LAi_SetPlayerType(pchar);

			LAi_group_MoveCharacter(characterFromID("Fra_patrolman_01"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Fra_patrolman_02"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Fra_patrolman_03"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Fra_patrolman_04"), "FRANCE_SOLDIERS");
			//--------Появление французских солдат
			ChangeCharacterAddressGroup(characterFromID("Fra_patrolman_01"), "Oxbay_shore_02", "reload", "reload2_back");
			ChangeCharacterAddress(characterFromID("Fra_patrolman_02"), "Oxbay_shore_02", "locator27");
			ChangeCharacterAddress(characterFromID("Fra_patrolman_03"), "Oxbay_shore_02", "locator26");
			ChangeCharacterAddress(characterFromID("Fra_patrolman_04"), "Oxbay_shore_02", "locator13");
			//-----------Смена типа английским солдатам
			LAi_group_MoveCharacter(characterFromID("Eng_land_soldier_01"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Eng_land_soldier_02"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Eng_land_soldier_03"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("Eng_land_soldier_04"), LAI_GROUP_PLAYER);
			//--------нападение их на группу игрока
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Story_kill_french_patrol");

			//--------Отправка Уилфреда к локатору, где он будет бояться.
			LAi_SetImmortal(characterFromID("Wilfred"), true);
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 1;
		break;

		case "Story_Glover_to_tavern_on_Greenford":
			//----------Выставляем Глоуверу сидячую позицию.
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // GR
			LAi_type_actor_Reset(characterFromID("Ewan Glover"));
			LAi_SetSitType(characterFromID("Ewan Glover"));
			//---------Перегружаем Эвана Глоувера в таверну Гринфорда, где он будет ждать игрока.
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Greenford_tavern", "sit", "sit4");
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Are_you_ready_again";
		break;

		case "Story_ReloadedtoGreenfordTavernWithGlover":
			SetCurrentTime(23, 0);
			LAi_SetSitType(characterFromID("Ewan Glover"));
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);

			Locations[FindLocation("Greenford_port")].reload.l1.disable = 0;
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Talk_in_tavern";

			LAi_ActorDialogNow(Pchar, characterFromID("Ewan Glover"), "", -1);
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
		break;

		case "Story_Blaze_and_Glover_Land_troops":
			if (makeint(environment.time) >=23 || makeint(environment.time) <= 6)
			{
				pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.over = "yes";
				Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
				if (!LAi_IsDead(characterFromID("Ewan Glover")))
				{
					//----------Высаживаем Английских солдат вместе с игроком
					ChangeCharacterAddress(characterFromID("Eng_land_soldier_01"), "Oxbay_shore_02", "locator7");
					ChangeCharacterAddress(characterFromID("Eng_land_soldier_02"), "Oxbay_shore_02", "locator23");
					ChangeCharacterAddress(characterFromID("Eng_land_soldier_03"), "Oxbay_shore_02", "locator24");
					ChangeCharacterAddress(characterFromID("Eng_land_soldier_04"), "Oxbay_shore_02", "locator25");
					Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Warning";
				}
				//----------Появляем местного жителя.
				LAi_type_actor_Reset(characterFromID("Wilfred"));
				LAi_type_actor_Reset(characterFromID("Wilfred"));
				ChangeCharacterAddress(characterFromID("Wilfred"), "Oxbay_shore_02", "locator8");
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("Wilfred"), "", 10.0);
				LAi_ActorFollow(characterFromID("Wilfred"), pchar, "Story_Blaze_and_Glover_Land_troops_speak", 10.0);
			}
			else
			{
				pchar.quest.ewan_again_gain_quest_for_night.win_condition.l1 = "ExitFromLocation";
				pchar.quest.ewan_again_gain_quest_for_night.win_condition.l1.location = "Oxbay_shore_02";
				pchar.quest.ewan_again_gain_quest_for_night.win_condition = "ewan_again_gain_quest_for_night";
			}
		break;

		case "Story_Blaze_and_Glover_Land_troops_speak":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Wilfred"));
			LAi_type_actor_Reset(characterFromID("Wilfred"));
			LAi_ActorDialog(characterFromID("Wilfred"), Pchar, "", 20.0, 1.0);
		break;

		case "Story_Blaze_and_Glover_Land_troops_denied":
			pchar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.over = "yes";
			SetCharacterShipLocation(characterFromID("Ewan Glover"), "none");
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
			bQuestDisableMapEnter = false;
			AddQuestRecord("Story_2ndTask", 8);
			//--------Зачисляем игроку проваленный квест
			Pchar.quest.Story_Glover_sunk = true;
			//--------Стартуем вторую половину задания
			Pchar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(characterFromID("Counterspy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
			Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Failed_in_last_moment";
			//LAi_ActorDialog(characterFromID("Wilfred"), Pchar, "", 5.0, 1.0);
		break;

		case "Story_Wilfred_scared_run_away":
			LAi_group_MoveCharacter(characterFromID("Wilfred"), LAI_GROUP_ACTOR);
		break;

		case "Wilfred_exit_complete":
			//-----------Возвращаем игрока в таверну Гринфорда на след. день
			LAi_SetImmortal(characterFromID("Wilfred"), false);
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_01"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_02"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_03"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_04"), "None", "");
			ChangeCharacterAddress(characterFromID("Wilfred"), "None", "");
			SetCharacterShipLocation(Pchar, "Greenford_port");
			SetCharacterShipLocation(characterFromID("Ewan Glover"), "None");
			ChangeCharacterAddress(characterFromID("Ewan Glover"), "Greenford_Tavern", "Goto1");
			SetCurrentTime(10, 0);
			DoQuestReloadToLocation("Greenford_tavern", "Goto", "goto17", "Story_ReturnedToGreenfordTavern");
		break;

		case "Story_kill_french_patrol":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 25);
			}
			else { AddPartyExp(pchar, 2500); }
			LAi_ActorFollow(characterFromID("Wilfred"), pchar, "Story_kill_french_patrol_3", 10.0);
			LAi_QuestDelay("Story_kill_french_patrol_2", 3.0);
		break;

		case "Story_kill_french_patrol_2":
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("Wilfred"), "", 10.0);
			AddQuestRecord("Story_2ndTask", 7);
		break;

		case "Story_kill_french_patrol_3":
			LAi_ActorWaitDialog(pchar, characterFromID("Wilfred"));
			Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Victory";
			LAi_ActorDialog(characterFromID("Wilfred"), Pchar, "", 10.0, 1.0);
		break;

		case "Story_ReturnedToGreenfordTavern":
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			pchar.quest.Story_Blaze_and_Glover_Land_troops.over = "yes";
			pchar.quest.Story_Blaze_and_Glover_Land_troops_denied.over = "yes";
			pchar.quest.story_glover_to_tavern_on_greenford.over = "yes";
			pchar.quest.story_convoy_glover_to_greenford.over = "yes";

			//-----------Возвращаем возможность выхода в карту
			//bQuestDisableMapEnter = false;
			//-----------Эван Глоувер начинает диалог с игроком.
			LAi_SetActorType(characterFromID("Ewan Glover"));
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Ewan Glover"));
			Characters[GetCharacterIndex("Ewan Glover")].dialog.CurrentNode = "GoodBye";

			ChangeCharacterAddress(characterFromID("Eng_land_soldier_01"), "none", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_02"), "none", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_03"), "none", "");
			ChangeCharacterAddress(characterFromID("Eng_land_soldier_04"), "none", "");
			ChangeCharacterAddress(characterFromID("Wilfred"), "none", "");

			// --> Swindler 050927
			// Here's a syntax error:
			// LAi_ActorDialog(characterFromID("Ewan Glover"), Pchar, "", 3.0.0, 1.0);
			LAi_ActorDialog(characterFromID("Ewan Glover"), Pchar, "", 3.0, 1.0);
			// Swindler <--
			LAi_SetSitType(characterFromID("CounterSpy"));
			ChangeCharacterAddressGroup(characterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
		break;

		case "Story_KillFrenchArresters":
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			pchar.quest.Story_Blaze_reaches_Greenford.over = "yes";
			ChangeCharacterAddress(characterfromID("Wilfred"), "none", "");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 15);
			}
			else { AddPartyExp(pchar, 1500); }
			LAi_LocationFightDisable(&Locations[FindLocation("Oxbay_tavern")], true);
			ChangeCharacterAddress(characterFromID("Fra_arrester_01"), "none", "");
			ChangeCharacterAddress(characterFromID("Fra_arrester_02"), "none", "");
			ChangeCharacterAddress(characterFromID("Fra_arrester_03"), "none", "");
			LAi_SetFightMode(pchar, false);
			LAi_QuestDelay("Story_AMinuteLaterAfterKillingFrenchArresters", 2.0);
		break;

		case "Story_AMinuteLaterAfterKillingFrenchArresters":
			/*LAi_group_SetAlarm(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetAlarm("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetAlarm("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, 0.0);*/
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, "FRANCE_SOLDIERS", LAI_GROUP_FRIEND);

			AddQuestRecord("Story_2ndTask", 9);
			LAi_SetImmortal(characterFromID("Counterspy"), true);
			LAi_SetActorType(characterFromID("Counterspy"));
			LAi_Fade("Story_AMinuteLaterAfterKillingFrenchArresters_2", "");
		break;

		case "Story_AMinuteLaterAfterKillingFrenchArresters_2":
			LAi_SetFightMode(pchar, false);
			LAi_SetPlayerType(pchar);
// KK -->
			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(Pchar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 1);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorStay(&characters[iPassenger]);
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(Pchar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 2);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorStay(&characters[iPassenger]);
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(Pchar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorStay(&characters[iPassenger]);
			}
			StoreOfficers(pchar.id);
			ChangeCharacterAddress(characterFromID("Ox_soldier_3"), "none", "");
			ChangeCharacterAddress(characterFromID("Ox_soldier_4"), "none", "");
			ChangeCharacterAddress(characterFromID("Ox_soldier_5"), "none", "");
			ChangeCharacterAddress(characterFromID("Ox_soldier_6"), "none", "");
			ChangeCharacterAddress(characterFromID("Ox_patrol_3"), "none", "");
			ChangeCharacterAddress(characterFromID("Ox_patrol_4"), "none", "");
			ChangeCharacterAddress(characterFromID("Moses Blinman"), "none", "");
			ChangeCharacterAddress(characterFromID("Lavinia Ault"), "none", "");
			ChangeCharacterAddress(characterFromID("Peter Dashwood"), "none", "");
			ChangeCharacterAddress(characterFromID("Flora Debney"), "none", "");
			ChangeCharacterAddress(characterFromID("Oxbay_Street_merchant_2"), "none", "");
			ChangeCharacterAddress(characterFromID("Kanhoji Angria"), "none", "");
// <-- KK

			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_tavern", "goto2");
			ChangeCharacterAddress(pchar, "oxbay_tavern", "goto3");
			Characters[GetCharacterIndex("Counterspy")].Dialog.CurrentNode = "After_Fight";
			LAi_ActorDialogNow(characterFromID("Counterspy"), Pchar, "", -1);

			Pchar.quest.Story_RunToTheShipyardThroughOxbay.win_condition.l1 = "location";
			Pchar.quest.Story_RunToTheShipyardThroughOxbay.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Story_RunToTheShipyardThroughOxbay.win_condition = "Story_RunToTheShipyardThroughOxbay";
		break;

		case "Story_RunToTheShipyardThroughOxbay":
			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l2.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l3.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l4.disable = 1;
// KK -->
			if (CCC_PITFALLS > 0) Locations[FindLocation("Oxbay_town")].reload.l5.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l6.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l7.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l8.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l9.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l10.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l11.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l12.disable = 1;
			Locations[FindLocation("Oxbay_town")].reload.l13.close_for_night = 0;
			Locations[FindLocation("Oxbay_town")].reload.l14.disable = 1;
// <-- KK
			LAi_SetActorType(characterFromID("Counterspy"));
			LAi_ActorRunToLocator(characterFromID("Counterspy"), "Reload", "reload3", "Story_CounterspyWentToShipyardBeforeBlaze", 25.0);

			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(Pchar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 1);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorRunToLocation(&characters[iPassenger], "reload", "reload3", "none", "", "", "", 25.0);
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(Pchar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 2);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorRunToLocation(&characters[iPassenger], "reload", "reload3", "none", "", "", "", 25.0);
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(Pchar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorRunToLocation(&characters[iPassenger], "reload", "reload3", "none", "", "", "", 25.0);
			}

// KK -->
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m6, "goto", "goto3"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquipCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m3, "goto", "goto4"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquipCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m4, "goto", "goto1"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquipCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m2, "goto", "goto2"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquipCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "reload", "reload12"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquipCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "reload", "reload1"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquipCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquipCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
// <-- KK
		break;

		case "Story_CounterspyWentToShipyardBeforeBlaze":
			ChangeCharacterAddress(characterFromID("Counterspy"),"Oxbay_Shipyard", "goto11");
		break;

		case "Story_Goto_Oxbay_shipyard_with_Counterspy":
			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(Pchar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 1);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(Pchar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 2);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(Pchar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			LAi_SetActorType(characterFromID("Counterspy"));
			LAi_type_actor_Reset(characterFromID("Counterspy"));
			LAi_SetImmortal(characterFromID("Counterspy"), true);
			LAi_SetImmortal(characterFromID("Oweyn McDorey"), true);
			Characters[GetCharacterIndex("Oweyn McDorey")].Dialog.CurrentNode = "Blaze and Counterspy";
			LAi_SetActorType(characterFromID("Oweyn MCDorey"));
			LAi_ActorDialog(characterFromID("Oweyn MCDorey"), Pchar, "", 5.0, 0);
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("Oweyn MCDorey"), "Story_Goto_Oxbay_shipyard_with_Counterspy_2", 1.0);
		break;

		case "Story_Goto_Oxbay_shipyard_with_Counterspy_2":
			LAi_ActorWaitDialog(pchar, characterFromID("Oweyn MCDorey"));
		break;

		case "Blaze_and_Counterspy_exit_from_shipyard":
			RemovePassenger(Pchar, characterFromID("Counterspy"));
			//----------------перегрузить игрока и шпиона наверх верфи
			LAi_Fade("Blaze_and_Counterspy_exit_from_shipyard_2", "Story_HiddenInShipyardWatch");
		break;

		case "Blaze_and_Counterspy_exit_from_shipyard_2":
			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(Pchar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 1);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorSetSitMode(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "goto11");
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(Pchar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 2);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorSetSitMode(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "goto11");
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(Pchar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(Pchar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorSetSitMode(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "goto11");
			}

			LAi_ActorSetSitMode(pchar);
			LAi_ActorSetSitMode(characterFromID("CounterSpy"));

			locx = stf(loadedLocation.locators.camera.camera_2.x);
			locy = stf(loadedLocation.locators.camera.camera_2.y);
			locz = stf(loadedLocation.locators.camera.camera_2.z);
			locCameraToPos(locx, locy, locz, false);

			ChangeCharacterAddress(pchar, "Oxbay_shipyard", "goto9");
			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_Shipyard", "goto11");
		break;

		case "Story_HiddenInShipyardWatch":
			//----------------Зафиксить камеру в нужном локаторе
			LAi_QuestDelay("Story_HiddenInShipyardWatch_2", 1.0);
		break;

		case "Story_HiddenInShipyardWatch_2":
			//----------------- Явить солдат сквозь дверь.
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_04"),"Oxbay_Shipyard", "Reload","reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_05"),"Oxbay_Shipyard", "Reload","reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_06"),"Oxbay_Shipyard", "Reload","reload1");
			//----------------Начать диалог между солдатами и Оуэном
			LAi_SetActorType(characterFromID("Fra_arrester_04"));
			LAi_SetActorType(characterFromID("Fra_arrester_05"));
			LAi_SetActorType(characterFromID("Fra_arrester_06"));

			LAi_ActorGoToLocator(characterFromID("Fra_arrester_05"), "Goto", "Goto12", "", 8.4);
			LAi_ActorGoToLocator(characterFromID("Fra_arrester_06"), "Goto", "Goto2", "", 8.4);
			LAi_ActorWaitDialog(characterFromID("Oweyn McDorey"), characterFromID("Fra_arrester_04"));
			LAi_ActorDialog(characterFromID("Fra_arrester_04"), characterFromID("Oweyn McDorey"), "", 5.0, 5.0);

			LAi_QuestDelay("Story_BlazeHidesInShipyard_FrenchSoldiersFinishTalking", 8.5);
		break;

		case "Story_AfterHiddenInShipyardWatch":
			pchar.quest.Story_RunToTheShipyardThroughOxbay.over = "yes";
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND); // KK
			Characters[getCharacterIndex("Counterspy")].Dialog.CurrentNode = "Officer_Money";
			LAi_ActorDialog(characterFromID("Counterspy"), Pchar, "", 5.0, 0);
		break;

		case "Story_Glover_leaves_on_complete":
			ChangeCharacterAddress(characterFromID("Ewan Glover"), "none", "");
			LAi_SetPlayerType(Pchar);
		break;

		case "Story_BlazeHidesInShipyard_FrenchSoldiersFinishTalking":
			LAi_type_actor_Reset(characterFromID("Fra_arrester_04"));
			LAi_type_actor_Reset(characterFromID("Fra_arrester_05"));
			LAi_type_actor_Reset(characterFromID("Fra_arrester_06"));
			LAi_ActorGoToLocation(characterFromID("Fra_arrester_04"), "reload", "Reload1", "none", "Reload", "reload1", "", 5.8);
			LAi_ActorGoToLocation(characterFromID("Fra_arrester_05"), "reload", "Reload1", "none", "Reload", "reload1", "", 5.8);
			LAi_ActorGoToLocation(characterFromID("Fra_arrester_06"), "reload", "Reload1", "none", "Reload", "reload1", "", 5.8);
			LAi_QuestDelay("Story_FrenchSoldiersGoneFromShipyard", 9.5);
		break;

		case "Story_FrenchSoldiersGoneFromShipyard":
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_04"),"none", "Reload","reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_05"),"none", "Reload","reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_06"),"none", "Reload","reload1");
			LAi_SetImmortal(characterFromID("Oweyn McDorey"), false);
			Characters[GetCharacterIndex("Oweyn McDorey")].Dialog.CurrentNode = "Soldiers left";
			LAi_SetImmortal(characterFromID("Counterspy"), true);
			LAi_SetActorType(characterFromID("Counterspy"));
			LAi_ActorSetStayMode(characterFromID("CounterSpy"));

			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l2.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l3.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l4.disable = 0;
// KK -->
			if (CCC_PITFALLS > 0) Locations[FindLocation("Oxbay_town")].reload.l5.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l6.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l7.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l8.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l9.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l10.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l11.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l12.disable = 0;
			Locations[FindLocation("Oxbay_town")].reload.l14.disable = 0;

			ChangeCharacterAddress(characterFromID("Ox_soldier_3"), "Oxbay_town", "goto3");
			ChangeCharacterAddress(characterFromID("Ox_soldier_4"), "Oxbay_town", "goto4");
			ChangeCharacterAddress(characterFromID("Ox_soldier_5"), "Oxbay_town", "goto1");
			ChangeCharacterAddress(characterFromID("Ox_soldier_6"), "Oxbay_town", "goto2");
			ChangeCharacterAddress(characterFromID("Ox_patrol_3"), "Oxbay_town", "goto31");
			ChangeCharacterAddress(characterFromID("Ox_patrol_4"), "Oxbay_town", "goto20");
			ChangeCharacterAddress(characterFromID("Moses Blinman"), "Oxbay_town", "goto12");
			ChangeCharacterAddress(characterFromID("Lavinia Ault"), "Oxbay_town", "goto28");
			ChangeCharacterAddress(characterFromID("Peter Dashwood"), "Oxbay_town", "goto8");
			ChangeCharacterAddress(characterFromID("Flora Debney"), "Oxbay_town", "goto21");
			ChangeCharacterAddress(characterFromID("Oxbay_Street_merchant_2"), "Oxbay_town", "merchant2");
			ChangeCharacterAddress(characterFromID("Kanhoji Angria"), "Oxbay_town", "goto1");
// <-- KK

			LAi_Fade("Story_FrenchSoldiersGoneFromShipyard_2", "Story_McDoreyStartTalking");
		break;

		case "Story_FrenchSoldiersGoneFromShipyard_2":
			ChangeCharacterAddress(characterFromID("Oweyn MCDorey"), "Oxbay_shipyard", "goto3");
			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_shipyard", "Goto7");
			ChangeCharacterAddress(pchar, "Oxbay_shipyard", "Goto8");
			locCameraFollow();
			LAi_SetPlayerType(Pchar);
		break;

		case "Story_McDoreyStartTalking":
			LAi_type_actor_Reset(characterFromID("Oweyn MCDorey"));
			LAi_ActorDialog(characterFromID("Oweyn MCDorey"), Pchar, "", 2.0, 1.0);
		break;

		case "Story_WaitingForEveningInTheShipyard":
			SetNextWind("WNW",30);							// LDH give the player a break on the winds - 17Apr09
//TraceAndLog("Winds set for easy escape");
			LAi_QuestDelay("Story_ReadyToGiveBribe", 1.0);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		break;

		case "Story_ReadyToGiveBribe":
			Characters[GetCharacterIndex("Counterspy")].dialog.CurrentNode = "Ready_for_meeting";
			LAi_ActorDialog(characterFromID("Counterspy"),Pchar, "", 2.0, 1.0);
		break;

// PB: Rewritten to replace ONLY if original squadron captains were killed -->
		case "Story_French_squadron_restored":
			Group_DeleteGroup("Story_French_Squadron");
			Group_CreateGroup("Story_French_Squadron");

			if (LAi_IsDead(characterFromID("Remy Gatien"))) {
				SetCrewQuantity(characterFromID("Isaac Razilly"), makeint(GetMaxCrewQuantity(characterFromID("Isaac Razilly"))));
				characters[GetCharacterIndex("Isaac Razilly")].Ship.crew.morale = MORALE_NORMAL/3 + rand(MORALE_NORMAL/3*2);
				Group_AddCharacter("Story_French_Squadron", "Isaac Razilly");
			}
			else
			{
				Group_AddCharacter("Story_French_Squadron", "Remy Gatien");
			}

			if (LAi_IsDead(characterFromID("Yves Giner"))) {
				SetCrewQuantity(characterFromID("Jacques Belmondo"), makeint(GetMaxCrewQuantity(characterFromID("Jacques Belmondo"))));
				characters[GetCharacterIndex("Jacques Belmondo")].Ship.crew.morale = MORALE_NORMAL/3 + rand(MORALE_NORMAL/3*2);
				Group_AddCharacter("Story_French_Squadron", "Jacques Belmondo");
			}
			else
			{
				Group_AddCharacter("Story_French_Squadron", "Yves Giner");
			}

			if (LAi_IsDead(characterFromID("Begon Monchaty"))) {
				SetCrewQuantity(characterFromID("Pierre Leverrier"), makeint(GetMaxCrewQuantity(characterFromID("Pierre Leverrier"))));
				characters[GetCharacterIndex("Pierre Leverrier")].Ship.crew.morale = MORALE_NORMAL/3 + rand(MORALE_NORMAL/3*2);
				Group_AddCharacter("Story_French_Squadron", "Pierre Leverrier");
			}
			else
			{
				Group_AddCharacter("Story_French_Squadron", "Begon Monchaty");
			}

			if (LAi_IsDead(characterFromID("Remy Gatien"))) {
				Group_SetGroupCommander("Story_French_Squadron", "Isaac Razilly");
			}
			else
			{
				Group_SetGroupCommander("Story_French_Squadron", "Remy Gatien");
			}
			Group_SetAddress("Story_French_Squadron", "Oxbay", "Quest_Ships", "Quest_Ship_7");
		break;
// PB: Rewritten to replace ONLY if original squadron captains were killed <--

		case "Story_Blaze_and_Rabel_Leave_tavern":
			LAi_SetActorType(characterFromID("Rabel Iverneau"));
			LAi_SetImmortal(characterFromID("Rabel Iverneau"), true);
			LAi_SetImmortal(characterFromID("Counterspy"), true);
			Characters[GetCharacterIndex("Counterspy")].Dialog.CurrentNode = "Talk_AfterTavern";
			ChangeCharacterAddress(characterFromID("Rabel Iverneau"), "Oxbay_town", "goto41");
			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_town", "goto10");
			LAi_ActorWaitDialog(characterFromID("Counterspy"), pchar);
			DoQuestReloadToLocation("Oxbay_town", "Reload", "Reload13", "Story_BlazeAndRabelGoToMeetCounterspy");
// KK -->
			Locations[FindLocation("Oxbay_town")].reload.l13.close_for_night = 1;
			Locations[FindLocation("Oxbay_port")].vcskip = true;
			ChangeCharacterAddress(characterFromID("Ox_patrol_1"), "none", "");
			ChangeCharacterAddress(characterFromID("Ox_patrol_2"), "none", "");
			ChangeCharacterAddress(characterFromID("Bartholomew Pardner"), "none", "");
			ChangeCharacterAddress(characterFromID("Olyver Blaxter"), "none", "");
			ChangeCharacterAddress(characterFromID("Beatrice Applegate"), "none", "");
			ChangeCharacterAddress(characterFromID("Brennan Applegate"), "none", "");
			ChangeCharacterAddress(characterFromID("Gregor Samsa"), "none", "");
			ChangeCharacterAddress(characterFromID("Flann Vickers"), "none", "");
			ChangeCharacterAddress(characterFromID("Oxbay_Street_merchant_1"), "none", "");
// <-- KK
		break;

		case "Story_BlazeAndRabelGoToMeetCounterspy":
			LAi_ActorFollow(characterFromID("Rabel Iverneau"), Pchar, "", -1);
			//SetShipRemovable(ref _refCharacter, bool bRemovable)
		break;

		case "Story_CounterspyGoesToPort":
			ChangeCharacterAddress(characterFromID("Counterspy"), "Oxbay_port", "goto10");
		break;

		case "Story_RabelGoesToPort":
			ChangeCharacterAddress(characterFromID("Rabel Iverneau"), "Oxbay_port", "goto8");
		break;

		case "Story_LeaveOxbayWithRabelAndCounterspy":
			Locations[FindLocation("Oxbay_port")].reload.l2.disable = 1;
			Locations[FindLocation("Oxbay_port")].reload.l3.disable = 1;
			//---------На случай, если игрок первым добежит до ворот.
			PlaceCharacter(characterFromID("Counterspy"), "officers");
			PlaceCharacter(characterFromID("Rabel Iverneau"), "officers");

			LAi_type_actor_Reset(characterFromID("counterspy"));
			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));

			LAi_SetActorType(characterFromID("Ox_Soldier_1")); // KK
			LAi_SetActorType(pchar);

			LAi_ActorFollow(pchar, characterFromID("Ox_Soldier_1"), "", 1.0); // KK
			LAi_ActorFollow(characterFromID("Ox_Soldier_1"), pchar, "Story_LeaveOxbayWithRabelAndCounterspy_2", 1.0); // KK
		break;

		case "Story_LeaveOxbayWithRabelAndCounterspy_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Ox_Soldier_1")); // KK
			Characters[GetCharacterIndex("Ox_Soldier_1")].Dialog.Filename = "Leaving_Oxbay_dialog.c"; // KK
			LAi_ActorDialog(characterFromID("Ox_Soldier_1"), Pchar, "player_back", 1.0, 1.0); // KK
		break;

		case "Story_Follow_Rabel_And_Counterspy":
			if (characters[GetCharacterIndex("Rabel Iverneau")].location == "none" && characters[GetCharacterIndex("counterspy")].location == "none")
			{
				characters[GetCharacterIndex("Oxbay Commander")].skill.Accuracy = 2;
				characters[GetCharacterIndex("Oxbay Commander")].skill.cannons = 2;
				Locations[FindLocation("Oxbay_port")].reload.l2.disable = 0;
				Locations[FindLocation("Oxbay_port")].reload.l3.disable = 0;
				Pchar.quest.Story_BlazeEscapedFromOxbay.win_condition.l1 = "Location";
				Pchar.quest.Story_BlazeEscapedFromOxbay.win_condition.l1.location = "Redmond";
				Pchar.quest.Story_BlazeEscapedFromOxbay.win_condition = "Story_BlazeEscapedFromOxbay";
				Pchar.quest.Story_BlazeEscapedFromOxbay_cheat_fix.win_condition.l1 = "MapEnter";
				Pchar.quest.Story_BlazeEscapedFromOxbay_cheat_fix.win_condition = "Story_BlazeEscapedFromOxbay_cheat_fix";
				characters[GetCharacterIndex("Rabel Iverneau")].skill.Sailing = 10;
				characters[GetCharacterIndex("Rabel Iverneau")].skill.Repair = 10;
				characters[GetCharacterIndex("Rabel Iverneau")].rank = 11;
				characters[GetCharacterIndex("Rabel Iverneau")].reputation = 54;
				characters[GetCharacterIndex("Rabel Iverneau")].experience = CalculateExperienceFromRank(11)+ (CalculateExperienceFromRank(11)/10 + rand(11000));
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.BasicDamageControl = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.AdvancedDamageControl = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.ProfessionalDamageControl = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.Rigging = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.RiggingAdvance = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.LightRepair = true;
				characters[GetCharacterIndex("Rabel Iverneau")].perks.list.ShipSpeedUp = true;
				SetOfficersIndex(Pchar, 3, GetCharacterIndex("Rabel Iverneau"));
			}
			DoQuestCheckDelay("Story_Follow_Rabel_And_Counterspy_2", 20.0);
		break;

		case "Story_BlazeEscapedFromOxbay_cheat_fix":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Rabel Iverneau"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Counterspy"));
			iForceDetectionFalseFlag = 0; // KK
		break;

		case "Story_Follow_Rabel_And_Counterspy_2":
			Group_SetTaskAttack("Story_French_Squadron", PLAYER_GROUP, true);
			Group_LockTask("Story_French_Squadron");
// KK -->
			characters[GetCharacterIndex("Rabel Iverneau")].AbordageMode = 0;
			if (GetRMRelation(pchar, FRANCE) > REL_WAR) SetRMRelation(pchar, FRANCE, REL_WAR);
			HoistFlag(FRANCE);
			iForceDetectionFalseFlag = 1;
// <-- KK
			AddCharacterGoods(pchar, GOOD_WHEAT, 40);  // Cat
			AddCharacterGoods(pchar, GOOD_RUM, 20);  //  Cat
		break;

		case "Story_RabelSuggestsToRun":
			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
			LAi_ActorDialogNow(characterFromID("Rabel Iverneau"), pchar, "", -1);
		break;

		case "Story_PlayerTriesToRunFromOxbay":
			LAi_QuestDelay("Story_PlayerTriesToRunFromOxbay_2", 6.0);
		break;

		case "Story_PlayerTriesToRunFromOxbay_2":
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_1"), "FRANCE_SOLDIERS"); // KK
			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_2"), "FRANCE_SOLDIERS"); // KK

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "Story_CapturedByHotPursuit":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_1"), "FRANCE_SOLDIERS"); // KK

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "Story_BlazeEscapedFromOxbay":
			characters[GetCharacterIndex("Oxbay Commander")].skill.Accuracy = 9;
			characters[GetCharacterIndex("Oxbay Commander")].skill.cannons = 5;
//			locations[FindLocation("Redmond_town_01")].reload.l11.go = "quest_redmond_tavern"; // GR: Moved to "exit_from_silehard_complete"
			DeleteAttribute(&Locations[FindLocation("Oxbay_town")],"vcskip"); // NK
			Locations[FindLocation("quest_redmond_tavern")].vcskip = true; // NK
			RecalculateJumpTable();
			RemovePassenger(Pchar, characterFromID("Counterspy"));
			RemovePassenger(Pchar, characterFromID("Rabel Iverneau"));
			LAi_SetActorType(characterFromID("Rabel Iverneau"));
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "Redmond_residence", "goto8");
			ChangeCharacterAddress(characterFromID("Counterspy"), "Redmond_residence", "goto3");
			ChangeCharacterAddress(characterFromID("Rabel Iverneau"), "Redmond_residence", "goto2");
			DoReloadFromSeaToLocation("Redmond_residence","goto", "goto1");
			pchar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1 = "location";
			pchar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1.location = "redmond_residence";
			pchar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition = "Story_BlazeWithRabelAndCounterspyReturn";
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l3.disable = 0;
// KK -->
			DeleteAttribute(&Locations[FindLocation("Oxbay_port")], "vcskip");
			ChangeCharacterAddress(characterFromID("Ox_patrol_1"), "Oxbay_port", "goto18");
			ChangeCharacterAddress(characterFromID("Ox_patrol_2"), "Oxbay_port", "goto12");
			ChangeCharacterAddress(characterFromID("Bartholomew Pardner"), "Oxbay_port", "goto9");
			ChangeCharacterAddress(characterFromID("Olyver Blaxter"), "Oxbay_port", "goto6");
			ChangeCharacterAddress(characterFromID("Beatrice Applegate"), "Oxbay_port", "goto18");
			ChangeCharacterAddress(characterFromID("Brennan Applegate"), "Oxbay_port", "goto13");
			ChangeCharacterAddress(characterFromID("Gregor Samsa"), "Oxbay_port", "goto13");
			ChangeCharacterAddress(characterFromID("Flann Vickers"), "Oxbay_port", "merchant1");
			ChangeCharacterAddress(characterFromID("Oxbay_Street_merchant_1"), "Oxbay_port", "merchant2");
// <-- KK
		break;

		case "Story_BlazeWithRabelAndCounterspyReturn":
			if(PChar.ship.type == "FR_Boussole" || PChar.ship.type == "RN_Razee" || PChar.ship.type == "FR_Razee")	// GR: only proceed if you have a flushdeck frigate, possibly repainted
			{
// KK -->
				ref Counterspy = CharacterFromID("Counterspy");

				RestoreOfficers(pchar.id);
				TakeShipCommandFromOfficer(pchar.id);
// <-- KK
				if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(Pchar, 1) != GetCharacterIndex("counterspy"))
				{
					iPassenger = GetOfficersIndex(Pchar, 1);
					LAi_SetOfficerType(&characters[iPassenger]);
				}
				if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(Pchar, 2) != GetCharacterIndex("counterspy"))
				{
					iPassenger = GetOfficersIndex(Pchar, 2);
					LAi_SetOfficerType(&characters[iPassenger]);
				}
				if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(Pchar, 3) != GetCharacterIndex("counterspy"))
				{
					iPassenger = GetOfficersIndex(Pchar, 3);
					LAi_SetOfficerType(&characters[iPassenger]);
				}

				HoistFlag(ENGLAND); // KK
				Pchar.quest.Story_BlazeEscapedFromOxbay.over = "yes";
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Robert Christopher Silehard"));
				pchar.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
				ExchangeCharacterShip(Pchar, characterFromID("Ship Storage"));
				SetCharacterShipLocation(Pchar, "Redmond_port");
				LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
				LAi_type_actor_Reset(characterFromID("Counterspy"));
				LAi_ActorTurnToCharacter(characterFromID("Rabel Iverneau"), characterFromID("Robert Christopher Silehard"));
				LAi_QuestDelay("Story_RabelLeavesResidence", 1.0);

				Characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "Story_2ndTask_complete";
			}
			else
			{
				LAi_SetActorType(characterFromID("Rabel Iverneau"));
				LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
				LAi_ActorTurnToCharacter(characterFromID("Rabel Iverneau"), characterFromID("Robert Christopher Silehard"));
				Characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "2nd_Task_no_ship";
			}
		break;

		case "Story_restore_ships_after_counterspy": // GR: Restore stored companion ships - triggered by dialog with Robert Christopher Silehard
			if (sti(GetAttribute(PChar, "quest.counterspy_fleet.original_fleet_size")) > 1)
			{
				for (n=1; n<COMPANION_MAX; n++)
				{
					temp = "companion" + n;
					if (PChar.quest.counterspy_fleet.(temp) != "*NULL*")
					{
						cc = getCharacterIndex(PChar.quest.counterspy_fleet.(temp));
						SetCompanionIndex(PChar,-1, cc)
						if (HasSubStr(PChar.quest.counterspy_fleet.(temp), "Enc_Officer")) LAi_UnStoreFantom(CharacterFromID(PChar.quest.counterspy_fleet.(temp))); // Cancel protection
					}
				}
			}
			DeleteQuestAttribute("counterspy_fleet");
		break;

		case "Story_go_get_frigate":		// GR: triggered by dialog with Silehard if you returned with the wrong ship
			if(!CheckQuestAttribute("story_stolen_frigate", "true"))
			{
				PChar.quest.story_stolen_frigate = "true";
				Preprocessor_AddQuestData("ship", XI_ConvertString("FrigateAdv"));
				AddQuestRecord("Story_2ndTask",13);
				Preprocessor_Remove("ship");
			}
			PChar.quest.reset_Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1 = "ExitFromLocation";
			PChar.quest.reset_Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1.location = PChar.location;
			PChar.quest.reset_Story_BlazeWithRabelAndCounterspyReturn.win_condition = "reset_Story_BlazeWithRabelAndCounterspyReturn";
		break;

		case "reset_Story_BlazeWithRabelAndCounterspyReturn":
			PChar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1 = "location";
			PChar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1.location = "redmond_residence";
			PChar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition = "Story_BlazeWithRabelAndCounterspyReturn";
		break;

		case "Story_CounterspyLeavesResidence":
			LAi_ActorGoToLocation(characterFromID("Counterspy"), "reload", "reload1", "none", "reload", "reload1", "", 5.0);
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorDialog(characterFromID("Robert Christopher Silehard"), PChar, "back_to_hovernor_type", 5.0, 0);
		break;

		case "Story_RabelLeavesResidence":
			LAi_ActorDialog(characterFromID("Counterspy"), characterFromID("Robert Christopher Silehard"), "Story_CounterspyLeavesResidence", 2.0, 1.0);
			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
			LAi_ActorGoToLocation(characterFromID("Rabel Iverneau"), "reload", "Reload1", "none", "reload", "reload1", "", 5.0);
			LAi_QuestDelay("Story_SilehardCongratulateWith2ndComplete", 2.0);
		break;

		case "Story_SilehardCongratulateWith2ndComplete":
			pchar.quest.story_playertriestorunfromoxbay.over = "yes";
			LAi_type_actor_Reset(characterFromID("Counterspy"));
			LAi_ActorGoToLocation(characterFromID("Counterspy"), "reload", "Reload1", "none", "reload", "reload1", "", 4.0);
			SetCharacterShipLocation(Pchar, "Redmond_port");
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorDialog(characterFromID("Robert Christopher Silehard"), PChar, "back_to_hovernor_type", 5.0, 0);
		break;

		case "Story_DanielleWaitsInMuelleTown":
			//DeleteAttribute(&PChar,"skipfood"); // NK 04-11 // KK
			pchar.quest.Story_AppearOnIslaMuelleonAnacletoShip.over = "yes";
			ChangeCharacterAddress(characterFromID("danielle"), "muelle_tavern", "goto6");
			Locations[FindLocation("muelle_tavern")].vcskip = true; // NK
			Characters[GetCharacterIndex("Danielle")].dialog.CurrentNode  = "MetBlazeOnIslaMuelle";
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 5.0, 1.0);
		break;

		case "Story_AppearOnIslaMuelleonAnacletoShip":
			CloseQuestHeader("Where_are_i");				// GR: Catch-all as questbook is not closed by some story sequences
			ChangeCharacterAddress(CharacterFromID("peasant"), "None", "");	// GR: remove character who met you on "Douwesen_shore_01" after storm
			iPassenger = makeint(Pchar.Temp.Officer.idx1);

			PlaceCharacter(&Characters[iPassenger], "officers");

			LAi_SetActorType(&Characters[iPassenger]);
			Characters[iPassenger].Dialog.Filename = "Found_Blaze_1_dialog.c";
			Characters[iPassenger].Dialog.currentnode = "First time";
			LAi_ActorDialog(&Characters[iPassenger], Pchar, "", 8.0, 1.0);

			iPassenger = makeint(Pchar.Temp.Officer.idx2);

			PlaceCharacter(&Characters[iPassenger], "officers");

			LAi_SetActorType(&Characters[iPassenger]);
			Characters[iPassenger].Dialog.Filename = "Found_Blaze_2_dialog.c";
			Characters[iPassenger].Dialog.currentnode = "First time";
			LAi_ActorFollow(&Characters[iPassenger], pchar, "", 8.0);

			iPassenger = makeint(Pchar.Temp.Officer.idx3);

			PlaceCharacter(&Characters[iPassenger], "goto");

			LAi_SetActorType(&Characters[iPassenger]);
			Characters[iPassenger].Dialog.Filename = "Found_Blaze_3_dialog.c";
			Characters[iPassenger].Dialog.currentnode = "First time";
			LAi_ActorFollow(&Characters[iPassenger], pchar, "", 8.0);

			ChangeCharacterAddress(characterFromID("Danielle"), "Muelle_Tavern", "goto2");
		break;

		case "Story_OfficersShutUpAfterFoundBlaze":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			Characters[iPassenger].Dialog.CurrentNode = "Explanation";
			LAi_ActorDialogNow(&Characters[iPassenger], Pchar, "", -1);

			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			LAi_ActorTurnToCharacter(&Characters[iPassenger], Pchar);

			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			LAi_ActorTurnToCharacter(&Characters[iPassenger], Pchar);
		break;

		case "Story_OfficersGoToTavernWithBlaze":
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			SetQuestHeader("Meet_Danielle_on_Muelle");
			AddQuestRecord("Meet_Danielle_on_Muelle", 3);
			Preprocessor_Remove("Danielle");
			ChangeCharacterAddress(characterFromID("Danielle"), "None", "");
			Pchar.Quest.Story_DanielleWaitsInMuelleTown.over = "yes";
			characters[getCharacterIndex("Tiago Marquina")].location = "none";
			characters[getCharacterIndex("Muelle_officiant")].location = "none";
			Locations[FindLocation("muelle_tavern")].vcskip = true; // NK
			DoQuestReloadToLocation("Muelle_tavern", "sit","sit7", "Story_AppearedinMuelleTavernwithOfficers");
		break;

		case "Story_AppearedinMuelleTavernwithOfficers":
			ChangeCharacterAddress(characterFromID("danielle"), "none", "");

			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			ChangeCharacterAddressGroup(&Characters[iPassenger], "Muelle_tavern", "sit2", "sit3");
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorSetSitMode(&Characters[iPassenger]);

			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			ChangeCharacterAddressGroup(&Characters[iPassenger], "Muelle_tavern", "Sit", "sit4");
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorSetSitMode(&Characters[iPassenger]);

			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			ChangeCharacterAddressGroup(&Characters[iPassenger], "Muelle_tavern", "Sit", "sit8");
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorSetSitMode(&Characters[iPassenger]);

			LAi_SetSitType(pchar);

			LAi_QuestDelay("Story_OfficersStartTalkInMuelleTavern", 0.5);
		break;

		case "Story_OfficersStartTalkInMuelleTavern":
			Characters[makeint(Pchar.Temp.Officer.idx3)].Dialog.CurrentNode = "Talk_In_Tavern";
			LAi_ActorDialogNow(&Characters[makeint(Pchar.Temp.Officer.idx3)], Pchar, "", -1);
			DeleteAttribute(&Locations[FindLocation("muelle_tavern")],"vcskip"); // NK
		break;

		case "Story_CameToOgarrioHouse":
			LAi_ActorTurnToCharacter(characterFromID("Sidonio Ogarrio"), Pchar);
			LAi_QuestDelay("Story_OgarrioTalksToPlayer", 0.5);
		break;

		case "Story_OgarrioTalksToPlayer":
			LAi_ActorDialog(characterFromID("Sidonio Ogarrio"), Pchar, "", 5.0, 1.0);
		break;

		case "found_blaze_Exit_Danielle":
			LAi_type_actor_Reset(characterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].dialog.CurrentNode  = "MetBlazeOnIslaMuelle";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 10.0, 1.0);
		break;

		case "Story_BlazeMetDanielleOnIslaMuelle":
			ChangeCharacterAddress(characterFromID("Danielle"), "Muelle_Tavern_upstairs", "goto3");
			LAi_SetStayType(pchar);
			DoQuestReloadToLocation("Muelle_tavern_upstairs", "Goto", "Goto2", "Story_BlazeAndDanielleStartTalkinMuelleTavern");
			locations[FindLocation("Douwesen_town")].reload.l3.disable = false;
		break;

		case "Story_BlazeAndDanielleStartTalkinMuelleTavern":
			SetCurrentTime(22, 0);
			Characters[getCharacterIndex("Danielle")].Dialog.Filename = "danielle_dialog.c";
			Characters[getCharacterIndex("Danielle")].Dialog.CurrentNode = "Talk_upstairs";
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("danielle"), "Story_BlazeAndDanielleStartTalkinMuelleTavern_2", 2.0);
		break;

		case "Story_BlazeAndDanielleStartTalkinMuelleTavern_2":
			LAi_SetPlayerType(pchar);
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 1.0, 0);
		break;

		case "Story_BlazeLeavesDanielleRoom":
			LAi_SetPlayerType(pchar);
			pchar.location.locator = "";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
			Preprocessor_AddQuestData("pronoun3", XI_ConvertString(GetMyPronounPossessive(CharacterFromID("Danielle"))));
			Preprocessor_AddQuestData("Pronoun_upper", FirstLetterUp(XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle")))));
			AddQuestRecord("Meet_Danielle_on_Muelle", 4);
			Preprocessor_Remove("Pronoun_upper");
			Preprocessor_Remove("pronoun3");
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("Danielle");
			SetCurrentTime(9, 0);

			RestorePassengers("blaze");

			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			if(Characters[iPassenger].id != "Blaze_Crewmember_01" && getOfficersIndex(Pchar, 1) != -1)
			{
				Characters[getOfficersIndex(Pchar, 1)].Dialog.Filename = Pchar.Temp.Officer.idx1.Dialog;
				Characters[getOfficersIndex(Pchar, 1)].Dialog.CurrentNode = Pchar.Temp.Officer.idx1.CurrentNode;
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			if(Characters[iPassenger].id != "Blaze_Crewmember_02" && getOfficersIndex(Pchar, 2) != -1)
			{
				Characters[getOfficersIndex(Pchar, 2)].Dialog.Filename = Pchar.Temp.Officer.idx2.Dialog;
				Characters[getOfficersIndex(Pchar, 2)].Dialog.CurrentNode = Pchar.Temp.Officer.idx2.CurrentNode;
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			if(Characters[iPassenger].id != "Blaze_Crewmember_03" && getOfficersIndex(Pchar, 3) != -1)
			{
				Characters[getOfficersIndex(Pchar, 3)].Dialog.Filename = Pchar.Temp.Officer.idx3.Dialog;
				Characters[getOfficersIndex(Pchar, 3)].Dialog.CurrentNode = Pchar.Temp.Officer.idx3.CurrentNode;
			}

			DeleteAttribute(characterFromID("danielle"), "ship");
			DeleteAttribute(PChar, "temp.officer");
			characters[GetCharacterIndex("danielle")].ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
			AddMoneyToCharacter(pchar, 70000); // KK what that money come from?
			/*if (pchar.ship.type != SHIP_TARTANE)
			{
				characters[GetCharacterIndex("danielle")].ship.type = pchar.ship.type;
				SetBaseShipData(characterFromID("danielle"));
			}*/

// GR: rewritten code for restoring your fleet -->
			for (n=1; n<COMPANION_MAX; n++)
			{
				temp = "companion" + n;
				if (PChar.quest.before_storm_fleet.(temp) != "*NULL*")
				{
					cc = getCharacterIndex(PChar.quest.before_storm_fleet.(temp));
					SetCompanionIndex(PChar,-1, cc)
					if (HasSubStr(PChar.quest.before_storm_fleet.(temp), "Enc_Officer")) LAi_UnStoreFantom(CharacterFromID(PChar.quest.before_storm_fleet.(temp))); // Cancel protection
				}
			}
			DeleteQuestAttribute("before_storm_fleet");

			ExchangeCharacterShip(PChar, CharacterFromID("Ship Storage"));			// Get your original ship back. The ship which brought you here is now given to dummy character "Ship Storage".
			if (GetPassengersQuantity(PChar) > 0)						// If you have some passengers...
			{
				cidx = -1;
				for(n = 0; n < GetPassengersQuantity(PChar); n++)			// ... search for one who is a valid character and who is not a prisoner, not already a companion
				{
					cc = GetPassenger(PChar, n);
					if (cc < 0) continue;
					sld = GetCharacter(cc);
					if (CheckAttribute(sld, "id") && GetRemovable(sld) && !IsPrisoner(sld) && !IsCompanion(sld) && sld.id != PChar.id)
					{
						cidx = cc;
					}
				}
				if (cidx != -1 && GetCompanionQuantity(PChar) < COMPANION_MAX-1)	// If there's a valid passenger, and if you have a spare ship slot, transfer the ship from "Ship Storage" to this passenger...
				{
					ExchangeCharacterShip(GetCharacter(cidx), CharacterFromID("Ship Storage"));
					SetCompanionIndex(PChar, -1, cidx);
					RemovePassenger(PChar, GetCharacter(cidx));			// ... and remove the ex-passenger from the "Passengers" list. If this is not done, the ship may disappear next time you visit a shipyard.
				}
			}
// <-- GR

			// officers said that Nathaniel's ship was repaired for their last money...
			pchar.ship.hp = GetCharacterShipHP(pchar);
			DeleteAttribute(pchar,"ship.blots");
			pchar.ship.sp = GetCharacterShipSP(pchar);
			DeleteAttribute(pchar,"ship.sails");
			DeleteAttribute(pchar,"ship.masts");
			ResetCannons(pchar)

			HoistFlag(GetCurrentFlag()); // NK so comps' nations update

/*
			// This is only to close quest header for mission which isn't finished yet.
			// If someone wants to write a continuation, please remove this comment
			// and four lines of code below and edit second entry for "Kill_Ogario".
			// quest text.
			if (CheckActiveQuest("Kill_Ogario")) {
				AddQuestRecord("Kill_Ogario", 2);
				CloseQuestHeader("Kill_Ogario");
			}
*/
// <-- KK

			pchar.location.from_sea = "Muelle_port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			pchar.money = "" + (sti(pchar.money) + sti(pchar.tempmoney)); // KK
			characters[getCharacterIndex("Tiago Marquina")].location = "Muelle_tavern";
			characters[getCharacterIndex("Muelle_officiant")].location = "Muelle_tavern";
			DoQuestReloadToLocation("Muelle_port", "Goto", "character4", "Story_BlazeMeetDanielleInMuellePort");
		break;

		case "danielle_Talk_upstairs_Exit":
			LAi_SetActorType(pchar);

			LAi_ActorGoToLocator(pchar, "reload", "reload1", "Story_BlazeLeavesDanielleRoom", 3.0);

			Locations[FindLocation("Oxbay_lighthouse")].locators_radius.goto.goto23 = 15.0;
			Pchar.quest.Speak_with_lighthouse_guards.win_condition.l1 = "location";
			Pchar.quest.Speak_with_lighthouse_guards.win_condition.l1.location = "Lighthouse_Inside";
			Pchar.quest.Speak_with_lighthouse_guards.win_condition = "Speak_with_lighthouse_guards";
			DeleteAttribute(&Locations[FindLocation("Oxbay_lighthouse")], "models.night.light");
			//Locations[FindLocation("Oxbay_lighthouse")].models.night.light = "";
		break;

		case "Story_BlazeMeetDanielleInMuellePort":
			//Locations[FindLocation("Muelle_Tavern_upstairs")].reload.l1.disable = 0;
			PlaceCharacter(characterFromID("danielle"), "goto");
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "MetInMuellePort";
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("danielle"), "", 2.0);
			LAi_ActorFollow(characterFromID("danielle"), pchar, "Story_BlazeMeetDanielleInMuellePort_2", 2.0);
		break;

		case "Story_BlazeMeetDanielleInMuellePort_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "player_back", 1.0, 1.0);
			pchar.location.from_sea = "Muelle_port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
		break;

		case "danielle_MetInMuellePort_Exit":
			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload3", "Story_DanielleGoesToBlazeShip", 5.0);
			pchar.location.from_sea = "muelle_port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			ChangeCharacterAddress(characterFromID("researcher"), "none", "");
		break;

		case "Story_DanielleGoesToBlazeShip":
			Island_SetReloadEnableGlobal("Oxbay", true);
			ChangeCharacterAddress(characterFromID("Danielle"), "None", "");
			ChangeCharacterAddress(characterFromID("Lighthouse_Guard_01"), "Lighthouse_Inside", "goto3");
			ChangeCharacterAddress(characterFromID("Lighthouse_Guard_02"), "Lighthouse_Inside", "goto2");
			ChangeCharacterAddress(characterFromID("Lighthouse_Officer"), "Lighthouse_Inside", "goto1");
			Locations[FindLocation("Oxbay_lighthouse")].reload.l4.disable = 0;

			/*if (characters[GetCharacterIndex("danielle")].ship.type != SHIP_NOTUSED)
			{
				SetCompanionIndex(pchar, -1, GetCharacterIndex("danielle"));
			}
			else
			{*/
				SetOfficersIndex(Pchar, 1, GetCharacterIndex("Danielle"));
				LAi_SetOfficerType(characterFromID("danielle"));
			//}
			SetCharacterRemovable(characterFromID("Danielle"), false);

			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l1.character = "Lighthouse_Guard_01";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l2.character = "Lighthouse_Guard_02";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition.l3.character = "Lighthouse_Officer";
			Pchar.quest.Story_KillSoldiersAtLighthouse.win_condition = "Story_KillSoldiersAtLighthouse";

			pchar.quest.to_lighthouse_after_danielle_join.win_condition.l1 = "location";
			pchar.quest.to_lighthouse_after_danielle_join.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.to_lighthouse_after_danielle_join.win_condition = "to_lighthouse_after_danielle_join";
		break;

		case "to_lighthouse_after_danielle_join":
			PlaceCharacter(characterFromID("danielle"), "goto");
			LAi_SetOfficerType(characterFromID("danielle"));
		break;

		case "Story_KillSoldiersAtLighthouse":
			characters[GetCharacterIndex("Lighthouse_Guard_01")].location = "none";
			characters[GetCharacterIndex("Lighthouse_Guard_02")].location = "none";
			characters[GetCharacterIndex("Lighthouse_Officer")].location = "none";

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Meet_Danielle_on_Muelle",5);
			Preprocessor_Remove("Danielle");

			pchar.quest.Story_TalkAfterKillingSoldiersatLighthouse.win_condition.l1 = "location";
			pchar.quest.Story_TalkAfterKillingSoldiersatLighthouse.win_condition.l1.location = "Oxbay_Lighthouse";
			pchar.quest.Story_TalkAfterKillingSoldiersatLighthouse.win_condition = "Story_TalkAfterKillingSoldiersatLighthouse";
		break;

		case "Story_TalkAfterKillingSoldiersatLighthouse":
			PlaceCharacter(characterFromID("danielle"), "goto");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("danielle"));
			Lai_ActorFollow(pchar, characterFromID("Danielle"), "", 3.0);
			Lai_ActorFollow(characterFromID("Danielle"), pchar, "Story_TalkAfterKillingSoldiersatLighthouse_2", 3.0);
		break;

		case "Story_TalkAfterKillingSoldiersatLighthouse_2":
			LAi_SetPlayerType(pchar);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "CaptureGreenford";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 2.0, 0);
		break;

		case "Story_PrepareToSiegeGreenford":
			LAi_SetOfficerType(characterFromID("danielle"));
			Pchar.quest.Story_AreYouReadyToCaptureGreenford.win_condition.l1 = "location";
			Pchar.quest.Story_AreYouReadyToCaptureGreenford.win_condition.l1.location = "Oxbay_lighthouse";
			Pchar.quest.Story_AreYouReadyToCaptureGreenford.win_condition = "Story_AreYouReadyToCaptureGreenford";
		break;

		case "Story_AreYouReadyToCaptureGreenford":
			if (!isofficer(CharacterFromID("Danielle")))	// GR: Make sure Danielle is officer, in case she has been replaced by sidequest character or random hired officer
			{
				PlaceCharacter(characterFromID("danielle"), "goto");
				SetOfficersIndex(Pchar, 1, GetCharacterIndex("Danielle"));
				LAi_SetOfficerType(characterFromID("danielle"));
			}
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Are_we_ready";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 5.0, 1.0);
		break;

		case "Story_GreenfordAssaultStarted":
			LAi_SetOfficerType(characterFromID("danielle")); // GR: If Danielle is to join you in the fort assault, let her fight
			Characters[GetCharacterIndex("Greenford Commander")].Dialog.Filename = "Greenford Commander_dialog.c";
			Characters[GetCharacterIndex("Greenford Commander")].Dialog.BoardingNode = "capture_of_Greenford";

//			QuestToSeaLogin_PrepareLoc("Oxbay", "Quest_Ships", "Quest_ship_23", true);	// GR: teleport to near fort
			QuestToSeaLogin_PrepareLoc("Oxbay", "reload", "reload_4", true);		// GR: put to sea next to lighthouse
			QuestToSeaLogin_Launch();
			//Islands[FindIsland("Oxbay")].reload.l6.go = "Fake_Greenford_fort"; // KK

			/*Pchar.quest.Story_CaptureGreenfordFort.win_condition.l1 = "FORT_destroy";
			Pchar.quest.Story_CaptureGreenfordFort.win_condition.l1.character = "Greenford Commander";
			Pchar.quest.Story_CaptureGreenfordFort.win_condition = "Story_CaptureGreenfordFort";*/
			/*PChar.quest.Story_CaptureGreenford.win_condition.l1 = "Colony_capture";
			PChar.quest.Story_CaptureGreenford.win_condition.l1.town = "Greenford";
			PChar.quest.Story_CaptureGreenford.win_condition = "Story_CaptureGreenford";*/

			LAi_SetImmortal(characterFromID("Greenford Commander"), false);

			/*SetNationRelation2MainCharacter(GetTownNation("Greenford"), RELATION_ENEMY);
			SetRMRelation(PChar, GetTownNation("Greenford"), RelationToRMRelation(RELATION_ENEMY));
			UpdateRelations();

			SetCharacterRemovable(characterFromID("Danielle"), true);
			RemovePassenger(Pchar, characterFromID("Danielle"));
			RemoveCharacterCompanion(pchar, characterFromID("danielle"));

			iForceDetectionFalseFlag = 1; // KK

			bQuestDisableMapEnter = true;
			//--------------Отключение возможности выгрузиться на остров
			Island_SetReloadEnableGlobal("Oxbay", false);*/

			//Group_SetAddress("Story_English_Squadron", "Oxbay", "Quest_Ships","Quest_ship_23");
			//DoReloadCharactertoLocation("Oxbay", "reload", "reload_fort1");

			/*Pchar.quest.Story_FightingInGreenfordPort.win_condition.l1 = "location";
			Pchar.quest.Story_FightingInGreenfordPort.win_condition.l1.location = "Fake_Greenford_port";
			Pchar.quest.Story_FightingInGreenfordPort.win_condition = "Story_FightingInGreenfordPort";*/
		break;

		/*case "Story_CaptureGreenfordFort":
// KK -->
			Islands[FindIsland("Oxbay")].reload.l6.go = "BOARDING_Fort";

			Islands[FindIsland("Oxbay")].reload.l2.name = "reload_1";
			Islands[FindIsland("Oxbay")].reload.l2.go = "Fake_Greenford_port";
			Islands[FindIsland("Oxbay")].reload.l2.emerge = "reload1";
			Islands[FindIsland("Oxbay")].reload.l2.radius = 200.0;
// <-- KK
			Locations[FindLocation("Fake_Greenford_port")].vcskip = true; // NK
			Locations[FindLocation("Fake_Greenford_town")].vcskip = true; // NK
		break;

		case "Story_FightingInGreenfordPort":
			//-----------------Возвращение состояния Релоадов острова Оксбэй и восстановление выхода в карту
			Island_SetReloadEnableGlobal("Oxbay", true);
			//Восстановление адреса локатора перегрузки в Порт Гринфорда вместо фэйкового Гринфорда
// KK -->
			Islands[FindIsland("Oxbay")].reload.l2.name = "reload_1";
			Islands[FindIsland("Oxbay")].reload.l2.go = "Greenford_port";
			Islands[FindIsland("Oxbay")].reload.l2.emerge = "reload1";
			Islands[FindIsland("Oxbay")].reload.l2.radius = 200.0;
// <-- KK

			// TIH --> we need to set this back once they finish, otherwise flags are messed up for awhile Sep3'06
			iForceDetectionFalseFlag = 1;
			// TIH <--

			bQuestDisableMapEnter = false;

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "reload", "reload4"); // KK
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "reload", "reload4"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "reload", "reload4"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "reload", "reload4"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "reload", "reload4"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "reload", "reload4"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "reload", "reload4"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "reload", "reload4"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_PORT_SOLDIERS");

			LAi_group_SetHearRadius("ENGLAND_PORT_SOLDIERS", 100.0);
			LAi_group_FightGroups("ENGLAND_PORT_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_PORT_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			Pchar.quest.Story_FightingInGreenfordTown.win_condition.l1 = "location";
			Pchar.quest.Story_FightingInGreenfordTown.win_condition.l1.location = "Fake_Greenford_town";
			Pchar.quest.Story_FightingInGreenfordTown.win_condition = "Story_FightingInGreenfordTown";

			LAi_group_SetCheck("ENGLAND_PORT_SOLDIERS", "Story_KillEverybodyInGreenfordPort");
		break;

		case "Story_KillEverybodyInGreenfordPort":
			Locations[FindLocation("Fake_Greenford_port")].reload.l2.name = "reload4";
			Locations[FindLocation("Fake_Greenford_port")].reload.l2.go = "Fake_Greenford_town";
			Locations[FindLocation("Fake_Greenford_port")].reload.l2.emerge = "reload1";
		break;


		case "Story_FightingInGreenfordTown":
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Fake_Greenford_town", "reload", "reload26");

			sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "Black_Corsair", "reload", "reload26");
			// NK - LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "fatman", "reload", "reload26");
			// NK - LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "Chameleon", "reload", "reload26");
			// NK - LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);


			LAi_group_MoveCharacter(characterFromID("Danielle"), LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "reload", "reload19"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "reload", "reload19"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "reload", "reload19"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "reload", "reload19"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "reload", "reload19"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "reload", "reload19"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "reload", "reload19"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "reload", "reload19"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "reload", "reload19"); // PB
			LAi_group_MoveCharacter(sld, "ENGLAND_TOWN_SOLDIERS");

			LAi_group_SetCheck("ENGLAND_TOWN_SOLDIERS", "Story_GreenfordCapturedByBlazeAndDanielle");
			LAi_group_SetHearRadius("ENGLAND_TOWN_SOLDIERS", 100.0);
			LAi_group_FightGroups("ENGLAND_TOWN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_TOWN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		break;*/
// <-- KK

		case "Story_GreenfordCapturedByBlazeAndDanielle":
// KK -->
			/*Locations[FindLocation("BOARDING_Town")].reload.l1.name = "reload27";
			Locations[FindLocation("BOARDING_Town")].reload.l1.go = "Greenford_prison";
			Locations[FindLocation("BOARDING_Town")].reload.l1.emerge = "Reload1";*/
			EndQuestMovie();
			DeleteAttribute(&Characters[GetCharacterIndex("Greenford Commander")], "Dialog.BoardingNode");

			SetCharacterShipLocation(Pchar, "Greenford_port");
			LAi_group_MoveCharacter(characterFromID("Researcher"), LAI_GROUP_PLAYER);
			//SetCharacterRelationAsOtherCharacter(GetCharacterIndex("Greenford commander"), GetMainCharacterIndex());
			//SetCharacterRelation(GetCharacterIndex("Greenford commander"),GetMainCharacterIndex(),RELATION_FRIEND);
			//UpdateRelations();
			SetTownFortCommander("Greenford", characterFromID("Danielle"));
//			CaptureTownForNation("Greenford", PERSONAL_NATION); // GR: Doesn't foul up your relations with everyone else
//			Characters[GetCharacterIndex("Greenford Commander")].skipRM = true;
			Characters[GetTownFortCommanderIndex("Greenford", 0)].skipRM = true;
			CaptureColony("Greenford", PERSONAL_NATION);
			if(GetRMRelation(PChar, ENGLAND) > REL_WAR) SetRMRelation(PChar, ENGLAND, REL_WAR); // GR: In case you improved your relations with Britain since Silehard denounced you

			// PB: Prevent missed attributes -->
			Characters[GetCharacterIndex("Danielle")].Fort.Cannons.Charge.Type = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Charge.Type;
			Characters[GetCharacterIndex("Danielle")].Fort.Cannons.Type.1 = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Type.1;
			Characters[GetCharacterIndex("Danielle")].Fort.Cannons.Type.1.Quantity = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Type.1.Quantity;
			Characters[GetCharacterIndex("Danielle")].Fort.Cannons.Type.2 = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Type.2;
			Characters[GetCharacterIndex("Danielle")].Fort.Cannons.Type.2.Quantity = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Type.2.Quantity;
			Characters[GetCharacterIndex("Danielle")].Ship.Cargo.Goods.Balls = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Balls;
			Characters[GetCharacterIndex("Danielle")].Ship.Cargo.Goods.Grapes = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Grapes;
			Characters[GetCharacterIndex("Danielle")].Ship.Cargo.Goods.Knippels = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Knippels;
			Characters[GetCharacterIndex("Danielle")].Ship.Cargo.Goods.Bombs = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Bombs;
		//	Characters[GetCharacterIndex("Danielle")].Ship.Cargo.Goods.Gunpowder = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Gunpowder; // This crashes the game???
			// PB: Prevent missed attributes <--

			//ChangeCharacterAddressGroup(characterFromID("Danielle"), "Greenford_town", "goto", "goto39");
			//LAi_QuestDelay("Story_DanielleOffersToGoSaveResearcher", 1.0);
			DoQuestReloadToLocation("Greenford_town", "reload", "reload19", "Story_DanielleAndResearcher");
// <-- KK
		break;

		case "Story_DanielleAndResearcher":
			PlaceCharacter(characterFromID("Danielle"), "goto");
//			PlaceCharacter(characterFromID("Researcher"), "goto");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("danielle"));
			Lai_ActorFollow(pchar, characterFromID("danielle"), "", 2.0);
			Lai_ActorFollow(characterFromID("danielle"), pchar, "Story_DanielleAndResearcher_2", 2.0);
		break;

		case "Story_DanielleAndResearcher_2":
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Greenford_captured";
//			LAi_SetStayType(characterFromID("researcher"));
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), PChar, "player_back", 10.0, 1.0);
		break;

		case "danielle_Greenford_captured_exit":
			LAi_SetActorType(characterFromID("danielle"));
			ChangeCharacterAddress(characterFromID("Researcher"), "Greenford_prison", "goto9");

			Pchar.quest.Story_AppearedInGreenfordPrison.win_condition.l1 = "location";
			Pchar.quest.Story_AppearedInGreenfordPrison.win_condition.l1.location = "Greenford_prison";
			Pchar.quest.Story_AppearedInGreenfordPrison.win_condition = "Story_AppearedInGreenfordPrison";
			// KK SetTownCapturedState("Greenford", false); // 04-12-15

			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload27", "Story_DanielleWentToGreenfordPrison", 20.0);
/*			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Researcher"));
			Lai_ActorFollow(pchar, characterFromID("Researcher"), "", 2.0);
			Lai_ActorFollow(characterFromID("Researcher"), pchar, "Story_DanielleAndResearcher_3", 2.0); */
		break;

		case "Story_DanielleAndResearcher_3":
//			LAi_ActorWaitDialog(pchar, characterFromID("Researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Translation";
			LAi_SetActorType(characterFromID("Researcher"));
			LAi_ActorDialog(characterFromID("Researcher"), PChar, "player_back", 10.0, 1.0);
		break;

		case "Story_DanielleWentToGreenfordPrison":
			ChangeCharacterAddress(characterFromID("Danielle"), "Greenford_prison", "goto18");
			Locations[FindLocation("Greenford_prison")].vcskip = true;
		break;

		case "Story_AppearedInGreenfordPrison":
			LAi_SetOfficerType(characterFromID("danielle"));
			Pchar.quest.Story_DanielleWentToGreenfordPrison.over = "yes";
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Translation";

			Pchar.quest.story_researcher_in_prison_speaks.win_condition.l1 = "locator";
			Pchar.quest.story_researcher_in_prison_speaks.win_condition.l1.location = "Greenford_prison";
			Pchar.quest.story_researcher_in_prison_speaks.win_condition.l1.locator_group = "reload";
			Pchar.quest.story_researcher_in_prison_speaks.win_condition.l1.locator = "reload12";
			pchar.quest.story_researcher_in_prison_speaks.win_condition = "Story_DanielleAndResearcher_3";
		break;

		case "Story_MovingToLighthouse":
			DeleteAttribute(&Locations[FindLocation("Greenford_prison")],"vcskip");
			RemovePassenger(Pchar, characterFromID("Danielle"));

			CloseQuestHeader("Meet_Danielle_on_Muelle");
			CloseQuestHeader("Capture_greenford");

			ChangeCharacterAddress(characterFromID("Danielle"), "Oxbay_lighthouse", "goto22");
			ChangeCharacterAddress(characterFromID("Researcher"), "Oxbay_lighthouse", "goto23");

			DoQuestReloadToLocation("Oxbay_lighthouse", "Goto", "goto24", "Story_TalkWithResearcherAfterSaving");
			//Убираем английских солдат из Гринфорда
			/*ChangeCharacterAddress(characterFromID("Eng_soldier_38"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_soldier_39"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_soldier_40"), "None", "");
			ChangeCharacterAddress(characterFromID("Eng_soldier_41"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_1"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_2"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_3"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_4"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_5"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_6"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_7"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_8"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_1"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_2"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_3"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_4"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_patrol_41"), "None", "");
			ChangeCharacterAddress(characterFromID("Green_soldier_8"), "None", "");
			ChangeCharacterAddress(characterFromID("Mine_soldier_05"), "None", "");
			ChangeCharacterAddress(characterFromID("Mine_soldier_06"), "None", "");
			ChangeCharacterAddress(characterFromID("Greenford Prison Commendant"), "None", "");*/
			locations[FindLocation("Oxbay_lighthouse")].fastreload = "Oxbay";
		break;

		case "Story_TalkWithResearcherAfterSaving":
			PlaceCharacter(characterFromID("researcher"), "goto");
			PlaceCharacter(characterFromID("danielle"), "goto");
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "NeedSomeTime";
			LAi_SetActorType(characterFromID("researcher"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "Story_TalkWithResearcherAfterSaving_2", 2.0);
		break;

		case "Story_TalkWithResearcherAfterSaving_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("Researcher"), Pchar, "player_back", 1.0, 1.0);
		break;

		case "Story_LighthouseSpeakWithDanielle":
			/*ChangeCharacterAddress(characterFromID("Danielle"), "Greenford_tavern", "goto7");
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // NK
			DoQuestReloadToLocation("Greenford_tavern", "Goto", "goto17", "Story_DanielleStartsTalkAboutResearcher");*/
			LAi_SetActorType(PChar);
			characters[GetCharacterindex("Danielle")].Dialog.CurrentNode = "WaitInGreenford";
			LAi_SetActorType(characterFromID("Danielle"));
			Lai_ActorFollow(pchar, characterFromID("Danielle"), "", 2.0);
			Lai_ActorFollow(characterFromID("Danielle"), pchar, "Story_LighthouseSpeakWithDanielle_1", 2.0);
		break;

		case "Story_LighthouseSpeakWithDanielle_1":
			LAi_ActorWaitDialog(pchar, characterFromID("Danielle"));
			LAi_SetActorType(characterFromID("Danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), PChar, "player_back", 10.0, 1.0);
		break;

// KK -->
		case "Story_WaitInGreenford":
			DoQuestReloadToLocation("Greenford_town", "reload", "reload26", "Story_WaitInGreenford_2");
		break;

		case "Story_WaitInGreenford_2":
			bQuestDisableSeaEnter = true;
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "None", "", "");

			pchar.quest.Story_WaitInGreenfordEnd.win_condition.l1 = "location";
			pchar.quest.Story_WaitInGreenfordEnd.win_condition.l1.location = "Greenford_tavern_upstairs";
			pchar.quest.Story_WaitInGreenfordEnd.win_condition = "Story_WaitInGreenfordEnd";

			pchar.quest.Story_WaitInGreenfordEnd.day = GetAddingDataDay(0, 0, 7);
			pchar.quest.Story_WaitInGreenfordEnd.month = GetAddingDataMonth(0, 0, 7);
			pchar.quest.Story_WaitInGreenfordEnd.year = GetAddingDataYear(0, 0, 7);
		break;

		case "Story_WaitInGreenfordEnd":
			DisableFastTravel(true);
			WaitDate("", sti(pchar.quest.Story_WaitInGreenfordEnd.year) - GetDataYear(), sti(pchar.quest.Story_WaitInGreenfordEnd.month) - GetDataMonth(), sti(pchar.quest.Story_WaitInGreenfordEnd.day) - GetDataDay(), 7, 0);
			DeleteAttribute(PChar, "quest.Story_WaitInGreenfordEnd.day");
			DeleteAttribute(PChar, "quest.Story_WaitInGreenfordEnd.month");
			DeleteAttribute(PChar, "quest.Story_WaitInGreenfordEnd.year");
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Greenford_tavern", "goto", "goto7");
			Locations[FindLocation("Greenford_tavern")].vcskip = true;
			Locations[FindLocation("Greenford_tavern")].locators_radius.goto.goto17.old = Locations[FindLocation("Greenford_tavern")].locators_radius.goto.goto17;
			Locations[FindLocation("Greenford_tavern")].locators_radius.goto.goto17 = 2.5;

			PChar.quest.Story_DanielleStartsTalkAboutResearcher.win_condition.l1 = "locator";
			PChar.quest.Story_DanielleStartsTalkAboutResearcher.win_condition.l1.location = "Greenford_tavern";
			PChar.quest.Story_DanielleStartsTalkAboutResearcher.win_condition.l1.locator_group = "goto";
			PChar.quest.Story_DanielleStartsTalkAboutResearcher.win_condition.l1.locator = "goto17";
			PChar.quest.Story_DanielleStartsTalkAboutResearcher.win_condition = "Story_DanielleStartsTalkAboutResearcher_1";
		break;

		case "Story_DanielleStartsTalkAboutResearcher_1":
			DeleteAttribute(&Locations[FindLocation("Greenford_tavern")],"vcskip"); // NK
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "BeforeEnglishSiege";
			LAi_SetActorType(characterFromID("Danielle"));
			LAi_SetActorType(PChar);
			Lai_ActorFollow(pchar, characterFromID("Danielle"), "", 2.0);
			Lai_ActorFollow(characterFromID("Danielle"), pchar, "Story_DanielleStartsTalkAboutResearcher_2", 2.0);
		break;

		case "Story_DanielleStartsTalkAboutResearcher_2":
			DisableFastTravel(false);
			LAi_ActorWaitDialog(pchar, characterFromID("Danielle"));
			Locations[FindLocation("Greenford_tavern")].locators_radius.goto.goto17 = Locations[FindLocation("Greenford_tavern")].locators_radius.goto.goto17.old;
			DeleteAttribute(&Locations[FindLocation("Greenford_tavern")], "locators_radius.goto.goto17.old");
			LAi_ActorDialog(characterFromID("Danielle"), PChar, "player_back", 10.0, 1.0);
		break;
 // <-- KK

		case "Story_DanielleOffersToBecomeFortCommander":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "RepelEnglishAssault";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 5.0, 0);
			LAi_ActorRunToLocation(characterFromID("Blaze_Crewmember_01"), "reload", "reload1", "none", "", "", "", 10.0);
		break;

		case "Story_RepelEnglishAssaultOnGreenford":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("Story_RepelEnglishAssaultOnGreenford_2", 5.0);
		break;

		case "Story_RepelEnglishAssaultOnGreenford_2":
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Greenford_port", "reload", "reload4");
			Characters[GetCharacterIndex("Danielle")].ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
			DoQuestReloadToLocation("Greenford_port", "reload", "reload1", "Story_WeMadeThem");
			iForceDetectionFalseFlag = 0; // KK
		break;

		case "Story_WeMadeThem":
			iForceDetectionFalseFlag = 0; // KK
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			CloseQuestHeader("Repel_English_Attack");
			//-----------------Возвращение состояния Релоадов острова Оксбэй и восстановление выхода в карту
			Island_SetReloadEnableGlobal("oxbay",true);

			bQuestDisableSeaEnter = false; // KK
			bQuestDisableMapEnter = false;
			//-----------------Возвращение состояния релоада выхода из гринфордской таверны
			/*Locations[FindLocation("Greenford_tavern")].reload.l1.name = "reload1";
			Locations[FindLocation("Greenford_tavern")].reload.l1.go = "Greenford_Town";
			Locations[FindLocation("Greenford_tavern")].reload.l1.emerge = "reload7";

			Locations[FindLocation("Greenford_port")].reload.l2.name = "reload4";
			Locations[FindLocation("Greenford_port")].reload.l2.go = "Greenford_town";
			Locations[FindLocation("Greenford_port")].reload.l2.emerge = "reload1";*/

			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "AfterGreenfordSiege";
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 20.0, 1.0);
			pchar.location.from_sea = "Oxbay_lighthouse";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			Locations[FindLocation("Oxbay_lighthouse")].reload.l3.disable = 1;
		break;

		case "Story_VoyageToKhaelRoaBegan":
			// PB: Return Town to England to prevent errors -->
			// GR: Capturing a town for Personal moves all its soldiers into group LAI_GROUP_PLAYER
			// GR: If a character is in LAI_GROUP_PLAYER, 'bAllies(character)' is true
			// GR: If 'bAllies(character)' is true, 'SetTownGarrisonForNation' doesn't change his uniform
			// GR: So put all soldiers back into "ENGLAND_SOLDIERS" before capturing "Greenford" for ENGLAND
			LAi_group_MoveCharacter(characterFromID("Green_soldier_1"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_soldier_2"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_patrol_1"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_patrol_2"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Eng_soldier_40"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Eng_soldier_41"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_soldier_3"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_soldier_4"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_patrol_3"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_patrol_4"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_patrol_41"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_soldier_5"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_soldier_6"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_soldier_7"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_soldier_8"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_soldier_9"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_soldier_10"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Greenford Prison Commendant"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Eng_soldier_38"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Eng_soldier_39"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_exit_soldier_01"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Green_exit_soldier_02"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Mine_soldier_05"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Mine_soldier_06"), "ENGLAND_SOLDIERS");
			SetTownFortCommander("Greenford", characterFromID("Greenford Commander"));
			CaptureTownForNation("Greenford", ENGLAND);
			ChangeCharacterAddressGroup(characterFromID("Greenford Commander"), "Oxbay", "reload", "reload_fort1");

			Characters[GetCharacterIndex("Greenford Commander")].rank = Characters[GetCharacterIndex("Greenford Commander")].orig.rank;
			Characters[GetCharacterIndex("Greenford Commander")].Fort.Cannons.Charge.Type = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Charge.Type;
			Characters[GetCharacterIndex("Greenford Commander")].Fort.Cannons.Type.1 = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Type.1;
			Characters[GetCharacterIndex("Greenford Commander")].Fort.Cannons.Type.1.Quantity = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Type.1.Quantity;
			Characters[GetCharacterIndex("Greenford Commander")].Fort.Cannons.Type.2 = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Type.2;
			Characters[GetCharacterIndex("Greenford Commander")].Fort.Cannons.Type.2.Quantity = Characters[GetCharacterIndex("Greenford Commander")].orig.Fort.Cannons.Type.2.Quantity;
			Characters[GetCharacterIndex("Greenford Commander")].Ship.Cargo.Goods.Balls = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Balls;
			Characters[GetCharacterIndex("Greenford Commander")].Ship.Cargo.Goods.Grapes = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Grapes;
			Characters[GetCharacterIndex("Greenford Commander")].Ship.Cargo.Goods.Knippels = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Knippels;
			Characters[GetCharacterIndex("Greenford Commander")].Ship.Cargo.Goods.Bombs = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Bombs;
		//	Characters[GetCharacterIndex("Greenford Commander")].Ship.Cargo.Goods.Gunpowder = Characters[GetCharacterIndex("Greenford Commander")].orig.Ship.Cargo.Goods.Gunpowder; // This crashes the game???

			// Tavern characters sometimes get confused after capture of Bridgetown, so reset them
			sld = CharacterFromID("Simon Hanpool");
			sld.greeting = "Gr_Simon Hanpool";
			LAi_SetBarmanType(sld);

			sld = CharacterFromID("Greenford_officiant");
			LAi_SetWaitressType(sld);

			// PB: Return Town to England to prevent errors <--
			LAi_LocationMonstersGen(&Locations[FindLocation("Labirint_1")], true);
			LAi_LocationMonstersGen(&Locations[FindLocation("Labirint_2")], true);
			LAi_LocationMonstersGen(&Locations[FindLocation("Labirint_3")], true);
			LAi_LocationMonstersGen(&Locations[FindLocation("Treasure_Alcove")], true);

			Islands[FindIsland("KhaelRoa")].model = "KhaelRoa1";
			Islands[FindIsland("KhaelRoa")].filespath.models = "islands\KhaelRoa1";
			Islands[FindIsland("KhaelRoa")].refl_model = "KhaelRoa1_refl";

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			SetQuestHeader("Sail_to_KhaelRoa");
			AddQuestRecord("Sail_to_KhaelRoa", 1);
			Preprocessor_Remove("Danielle");
// NK -->
			//Log_SetStringToLog("done");
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "none", "");
			LAi_SetStayType(characterFromID("Robert Christopher Silehard"));
			SetRumourState("Silehard_nasty", false);
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = 0;
// NK <--
			characters[GetCharacterIndex("Robert Christopher Silehard")].rank = sti(pchar.rank) - 4;
			ChangeCharacterAddress(characterFromID("John Clifford Brin"), "redmond_residence", "goto8"); // NK
			characters[GetCharacterIndex("John Clifford Brin")].dialog = "Robert Christopher Silehard_dialog.c"; // PB
			Towns[GetTownIndex("Redmond")].gov = "John Clifford Brin"; // KK
			// KK Characters[GetCharacterIndex("Redmond Commander")].gov = "John Clifford Brin"; // RM
			SetRumourState("Brin_here", true); // NK

			// PS gen chars and ships-->
			SetUpShip(characterFromID("Isenbrandt Jurcksen"), "war", true);
			SetUpShip(characterFromID("Brian The Slayer"), "war", true);
			//SetUpShip(characterFromID("James Paige"), "war", true);
// KK -->
			SetUpShip(characterFromID("Robert Christopher Silehard"), "war", true);
			SetUpShip(characterFromID("Thomas Norton"), "war", true);

			GiveItem2Character(characterFromID("Robert Christopher Silehard"), "blade51");
			EquipCharacterByItem(characterFromID("Robert Christopher Silehard"), "blade51");
			GiveItem2Character(characterFromID("Robert Christopher Silehard"), "pistol5");
			EquipCharacterByItem(characterFromID("Robert Christopher Silehard"), "pistol5");
// <-- KK

			// (superhigh numbers to make sure crew at max)
			SetCrewQuantity(characterFromID("Isenbrandt Jurcksen"), 4000);
			SetCrewQuantity(characterFromID("Brian The Slayer"), 4500);
			SetCrewQuantity(characterFromID("Robert Christopher Silehard"), 9500);
			SetCrewQuantity(characterFromID("Thomas Norton"), 1600);
			// PS <--

			Group_AddCharacter("Story_Pirate_Squadron", "Isenbrandt Jurcksen");
			Group_AddCharacter("Story_Pirate_Squadron", "Brian The Slayer");
			Group_AddCharacter("Story_Pirate_Squadron", "Robert Christopher Silehard");
			Group_AddCharacter("Story_Pirate_Squadron", "Thomas Norton");

			// PB -->
		/*	SetCharacterRelationBoth(GetCharacterIndex("Brian The Slayer"),GetCharacterIndex("Robert Christopher Silehard"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Isenbrandt Jurcksen"),GetCharacterIndex("Robert Christopher Silehard"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Brian The Slayer"),GetCharacterIndex("Thomas Norton"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Isenbrandt Jurcksen"),GetCharacterIndex("Thomas Norton"),RELATION_FRIEND);
			UpdateRelations(); */
//			characters[GetCharacterIndex("Robert Christopher Silehard")].nation = PIRATE;
			characters[GetCharacterIndex("Isenbrandt Jurcksen")].nation = PIRATE;
			characters[GetCharacterIndex("Thomas Norton")].nation = PIRATE;
			characters[GetCharacterIndex("Brian The Slayer")].nation = PIRATE;
			// PB <--

			Group_SetGroupCommander("Story_Pirate_Squadron", "Isenbrandt Jurcksen");
			Group_SetTaskAttack("Story_Pirate_Squadron", PLAYER_GROUP, true);
			Group_SetAddress("Story_Pirate_Squadron", "KhaelRoa", "Quest_ships", "Quest_Ship_4");

			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l1.character = "Isenbrandt Jurcksen";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l2.character = "Brian The Slayer";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l3.character = "Thomas Norton";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l4 = "NPC_Death";
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l4.character = "Robert Christopher Silehard";
// KK -->
			pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l5 = "location";
			pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l5.location = "KhaelRoa";
// <-- KK
			Pchar.quest.Story_SinkPiratesAtKhaelRoa.win_condition = "Story_SinkPiratesAtKhaelRoa";

			Pchar.quest.Story_AppearAtKhaelRoa.win_condition.l1 = "location";
			Pchar.quest.Story_AppearAtKhaelRoa.win_condition.l1.location = "KhaelRoa";
			Pchar.quest.Story_AppearAtKhaelRoa.win_condition = "Story_AppearAtKhaelRoa";

			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "ReadyForKhaelRoa";
		break;

		case "Story_AppearAtKhaelRoa":
			LAi_SetImmortal(characterFromID("Robert Christopher Silehard"), false);
			LAi_SetStayType(characterFromID("Robert Christopher Silehard"));
			LAi_SetImmortal(characterFromID("Isenbrandt Jurcksen"), false);
			Characters[GetCharacterIndex("Robert Christopher Silehard")].recognized = true;
			Characters[GetCharacterIndex("Isenbrandt Jurcksen")].recognized = true;
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableLocal("KhaelRoa", "reload_1", true);
			Island_SetReloadEnableGlobal("KhaelRoa", false);
			if(GetRMRelation(PChar, PIRATE) > REL_WAR) SetRMRelation(PChar, PIRATE, REL_WAR); // RM
			LeaveService(PChar, PIRATE, false); // RM
			ChangeCharacterShipGroup(characterFromID("Isenbrandt Jurcksen"), "Pirates");
			ChangeCharacterShipGroup(characterFromID("Brian The Slayer"), "Pirates");
			ChangeCharacterShipGroup(characterFromID("Robert Christopher Silehard"), "Pirates");
			ChangeCharacterShipGroup(characterFromID("Thomas Norton"), "Pirates");
			Group_SetTaskAttack("Pirates", PLAYER_GROUP, true);
			Group_LockTask("Pirates");
			UpdateRelations();
			iForceDetectionFalseFlag = 1; // KK

			Pchar.quest.Ways_to_talk.win_condition.l1 = "location";
			PChar.quest.Ways_to_talk.win_condition.l1.character = "Robert Christopher Silehard";
			Pchar.quest.Ways_to_talk.win_condition.l1.location = pchar.location;
			Pchar.quest.Ways_to_talk.win_condition = "Ways_to_talk";
		break;

		case "Ways_to_talk":
			LAi_SetWarriorType(CharacterFromID("Robert Christopher Silehard"));
			LAi_warrior_DialogEnable(CharacterFromID("Robert Christopher Silehard"), true)
		break;

		case "Story_SinkPiratesAtKhaelRoa":
			Island_SetReloadEnableLocal("KhaelRoa", "reload_1", true);
			Island_SetReloadEnableGlobal("KhaelRoa", true);
			Island_SetGotoEnableLocal("KhaelRoa", "reload_1", true);
			bQuestDisableMapEnter = false;// TIH re-enable map enter Sep3'06 EDIT: CTM for some reason the Enable lines DONT WORK :E
			RefreshBattleInterface(true);

			Locations[FindLocation("KhaelRoa_port")].reload.l1.disable = 1;
			Locations[FindLocation("Temple")].reload.l3.disable = 1;
			Locations[FindLocation("Labirint_1")].reload.l1.disable = 1;

			CloseQuestHeader("Sail_to_KhaelRoa");
			SetQuestHeader("Into_the_temple");
			AddQuestRecord("Into_the_temple",1);
			// Sailor Al -->
			if (FindFellowtravellers(PChar, CharacterFromID("Robert Christopher Silehard")) == FELLOWTRAVEL_CAPTIVE)
				AddQuestRecord("Into_the_temple", 3);
			else
				AddQuestRecord("Into_the_temple", 4);
			// Sailor Al <--

			SetOfficersIndex(Pchar, -1,getCharacterIndex("Researcher"));
			SetCharacterRemovable(characterFromID("Researcher"), false);
			characters[GetCharacterIndex("Researcher")].AbordageMode = 0;	// KK

			ChangeCharacterAddressGroup(CharacterFromID("Skull"), "QC_residence", "goto", "goto1");			// PB: Replacement for Isenbrandt Jurcksen
			Characters[GetCharacterIndex("Skull")].Dialog.Filename = "Isenbrandt Jurcksen_dialog.c";
			Towns[GetTownIndex("Quebradas Costillas")].gov = "Skull";						// PB: Set this for real
			ChangeCharacterAddress(characterFromID("Isenbrandt Jurcksen"), "none", "");				// PB: Just in case

			Pchar.quest.Story_LandedOnKhaelRoa.win_condition.l1 = "location";
			Pchar.quest.Story_LandedOnKhaelRoa.win_condition.l1.location = "KhaelRoa_port";
			Pchar.quest.Story_LandedOnKhaelRoa.win_condition = "Story_LandedOnKhaelRoa";
		break;

		case "Story_LandedOnKhaelRoa":
			StorePassengers(pchar.id);

			locDisableUpdateTime = true;

			ChangeCharacterAddressGroup(characterFromID("danielle"), "KhaelRoa_port", "officers", "reload2_1");
			ChangeCharacterAddressGroup(characterFromID("Researcher"), "KhaelRoa_port", "officers", "reload2_1");
			LAi_QuestDelay("Story_IntoKhaelRoa", 2.0);

		break;

		case "Story_IntoKhaelRoa":
			LAi_SetActorType(characterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Temple";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "danielle_becomes_officer", 5.0, 1.0);
		break;

		case "danielle_becomes_officer":
			AddPassenger(Pchar, characterFromID("danielle"), 0);
			AddPassenger(Pchar, characterFromID("researcher"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Danielle"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Researcher"));
			LAi_SetOfficerType(characterFromID("danielle"));
		break;

		case "researcher_becomes_officer":
			LAi_SetOfficerType(characterFromID("researcher"));
		break;

		case "Story_ResearcherSpeaksonKhaelRoaBeach":
			Characters[GetCharacterIndex("researcher")].dialog.CurrentNode = "Danger";
			LAi_SetActorType(characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("Researcher"), Pchar, "researcher_becomes_officer", 5.0, 1.0);

			Locations[FindLocation("Labirint_1")].locators_radius.goto.goto1 = 3.0;

			Pchar.quest.Story_SplitInLabyrinth.win_condition.l1 = "locator";
			Pchar.quest.Story_SplitInLabyrinth.win_condition.l1.location = "Labirint_1";
			Pchar.quest.Story_SplitInLabyrinth.win_condition.l1.locator_group = "goto";
			Pchar.quest.Story_SplitInLabyrinth.win_condition.l1.locator = "goto1";
			Pchar.quest.Story_SplitInLabyrinth.win_condition = "Story_SplitInLabyrinth";
		break;

		case "Story_SplitInLabyrinth":
			LAi_SetActorType(characterFromID("danielle"));
			LAi_SetActorType(characterFromID("researcher"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("danielle"), "", 2.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "", 2.0);
			LAi_ActorFollow(characterFromID("danielle"), pchar, "Story_SplitInLabyrinth_2", 2.0);
		break;

		case "Story_SplitInLabyrinth_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Split";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 2.0, 0);
		break;

		case "Story_DanielleWentIntoLeftPassage":
			Locations[FindLocation("KhaelRoa_port")].reload.l1.disable = 0;
			Locations[FindLocation("Temple")].reload.l3.disable = 0;
			SetCharacterRemovable(characterFromID("Danielle"), true);
			RemovePassenger(Pchar, characterFromID("Danielle"));
			LAi_type_actor_Reset(characterFromID("researcher"));
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_SetActorType(characterFromID("danielle"));
			characters[GetCharacterIndex("danielle")].location = "labirint1";
			LAi_ActorRunToLocator(characterFromID("danielle"), "goto", "goto3", "", 25.0);
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "I go to the right";
			LAi_ActorDialog(characterFromID("Researcher"), Pchar, "player_back", 5.0, 0);
		break;

		case "Danielle_split_exit":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "First time";
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_SetActorType(characterFromID("researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Split";
			LAi_ActorDialog(characterFromID("researcher"), pchar, "player_back", 2.0, 1.0);
		break;

		case "danielle_AfterGreenfordSiege_exit":
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Danielle"));
			SetCharacterRemovable(characterFromID("Danielle"), false);
			ChangeCharacterAddress(characterFromID("researcher"),"Oxbay_lighthouse", "goto30");
			Characters[GetCharacterIndex("researcher")].dialog.CurrentNode = "AlreadyTranslated";
			DoQuestReloadToLocation("Oxbay_lighthouse", "Goto", "goto24", "Story_TalkWithResearcherAfterSiegeGreenford");
		break;

		case "Story_TalkWithResearcherAfterSiegeGreenford":
			PlaceCharacter(characterFromID("researcher"), "goto");
			LAi_SetActorType(characterFromID("researcher"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterfromID("researcher"), "", 2.0);
			LAi_ActorFollow(characterfromID("researcher"), pchar, "Story_TalkWithResearcherAfterSiegeGreenford_2", 2.0);
		break;

		case "Story_TalkWithResearcherAfterSiegeGreenford_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "player_back", 3.0, 1.0);
		break;

		case "danielle_RepelEnglishAssault_again_exit":
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorGoToLocator(characterFromID("danielle"), "reload", "reload1", "", 5.0);
		break;

		case "danielle_RepelEnglishAssault_exit":
			// PB: Prevent crashes and enemy personal fort -->
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Oxbay", "reload", "reload_fort1");
			Characters[GetCharacterIndex("Danielle")].nation = PERSONAL_NATION;
			// PB: Prevent crashes and enemy personal fort <--
			// KK LAi_SetPlayerType(pchar);
			// KK Fort_SetCharacter(characterFromID("danielle"), "Oxbay", "reload", "reload_fort1");
			LAi_SetActorType(characterFromID("danielle"));
			//LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1", "Story_DanielleGoesToGreenfordFort", 5.0);
			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1", "", 5.0);
			LAi_SetPlayerType(pchar);

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			SetQuestHeader("Repel_English_Attack");
			AddQuestRecord("Repel_English_Attack", 1);
			Preprocessor_Remove("Danielle");

			/*Locations[FindLocation("Greenford_tavern")].reload.l1.name = "reload1";
			Locations[FindLocation("Greenford_tavern")].reload.l1.go = "Greenford_port";
			Locations[FindLocation("Greenford_tavern")].reload.l1.emerge = "reload4";

			pchar.quest.to_suadron.win_condition.l1 = "location";
			pchar.quest.to_suadron.win_condition.l1.location = "Oxbay";
			pchar.quest.to_suadron.win_condition = "to_suadron";*/
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("oxbay",false);
		/*break;

		case "to_suadron":
			SetCrewQuantity(characterFromID("Waulter Tomlison"), 200);
			SetCrewQuantity(characterFromID("Malcolm Hart"), 650);
			SetCrewQuantity(characterFromID("Henry Banfield"), 650);*/

			Group_CreateGroup("Story_English_Squadron");
			Group_AddCharacter("Story_English_Squadron", "Waulter Tomlison");	// Battleship4 "Vengeance"
			Group_AddCharacter("Story_English_Squadron", "Malcolm Hart");		// RN_Battleship "Desperate"
			if(GetDifficulty() <= DIFFICULTY_MARINER)
			{
				Group_AddCharacter("Story_English_Squadron", "Wauter Keech");	// RN_Corvette "Black Prince"
			}
			else
			{
				Group_AddCharacter("Story_English_Squadron", "Henry Banfield");	// RN_Battleship "Monarch"
				Group_AddCharacter("Story_English_Squadron", "Lewellyn Belt");	// Frigate1 "Meleager"
			}

			//SetCharacterRelationAsOtherCharacter(GetCharacterIndex("danielle"), GetMainCharacterIndex());
			//SetCharacterRelationBoth(GetCharacterIndex("danielle"),GetMainCharacterIndex(),RELATION_FRIEND);

			//SetCharacterRelationBoth(GetCharacterIndex("Waulter Tomlison"), GetMainCharacterIndex(), RELATION_ENEMY);
			//SetCharacterRelationBoth(GetCharacterIndex("Waulter Tomlison"), GetCharacterIndex("danielle"), RELATION_ENEMY);
			Group_SetGroupCommander("Story_English_Squadron", "Waulter Tomlison");
			Group_SetTaskAttack("Story_English_Squadron", PLAYER_GROUP, true);
			//Group_SetAddress("Story_English_Squadron", "Oxbay", "Quest_Ships", "Quest_ship_23");
			Group_LockTask("Story_English_Squadron");

			iForceDetectionFalseFlag = 1; // KK

			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l1.character = "Waulter Tomlison";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l2.character = "Malcolm Hart";
			if(GetDifficulty() <= DIFFICULTY_MARINER)
			{
				Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3 = "NPC_Death";
				Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3.character = "Wauter Keech";
			}
			else
			{
				Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3 = "NPC_Death";
				Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3.character = "Henry Banfield";
				Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l5 = "NPC_Death";
				Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l5.character = "Lewellyn Belt";
			}
// KK -->
			pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l4 = "SeaEnter"; //condition to allow boarding all 3 ships PW
			//pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l4.location = "Oxbay";
// <-- KK
			Pchar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition = "Story_RepelEnglishAssaultOnGreenford";

// KK -->
			QuestToSeaLogin_PrepareLoc("Oxbay", "reload", "reload_1", false);
			QuestToSeaLogin_AddGroupLoc("Story_English_Squadron", 0, "Quest_Ships", "Quest_ship_23", true);
			QuestToSeaLogin_Launch();
// <-- KK
		break;

		case "danielle_BeforeEnglishSiege_exit":
			LAi_SetHP(characterFromID("Blaze_CrewMember_01"), 80.0, 80.0);
			LAi_SetActorType(characterFromID("Blaze_CrewMember_01"));
			ChangeCharacterAddressGroup(characterFromID("Blaze_Crewmember_01"), "Greenford_tavern", "reload", "reload1");
/* // KK -->
// GR: made translatable, moved to case "Story_leavingOxbay", applied to all three "Blaze_Crewmember" characters
			if (CheckAttribute(PChar,"firstname"))
				Characters[GetCharacterIndex("Blaze_Crewmember_01")].name = pchar.firstname + "'s crewmember";
			else
				Characters[GetCharacterIndex("Blaze_Crewmember_01")].name = pchar.name + "'s crewmember";
// <-- KK */
			Characters[GetCharacterIndex("Blaze_Crewmember_01")].Dialog.Filename = "EnglishAttack_dialog.c";
			Characters[GetCharacterIndex("Blaze_Crewmember_01")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(characterfromID("Blaze_Crewmember_01"), pchar, "player_back", 2.0, 1.0);
		break;

		case "researcher_danger_wait_exit":
			SetCurrentTime(10, 0);
			SetNextWeather("Blue Sky");
			DoReloadCharacterToLocation("KhaelRoa_port", "reload", "reload2");
		break;

		case "Story_TimeToGoIntoCentralPassage":
			ChangeCharacterAddress(characterFromID("danielle"), "none", "");
			ChangeCharacterAddress(characterFromID("researcher"), "none", "");
			LAi_SetPlayerType(pchar);
			Locations[FindLocation("Treasure_Alcove")].locators_radius.goto.goto3 = 5.0;

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Into_the_temple",2); // NK
			Preprocessor_Remove("Danielle");

			Pchar.quest.Story_DanielleAndResearcherAppear.win_condition.l1 = "Location";
			Pchar.quest.Story_DanielleAndResearcherAppear.win_condition.l1.location = "Treasure_Alcove";
			Pchar.quest.Story_DanielleAndResearcherAppear.win_condition = "Story_DanielleAndResearcherAppear";
		break;

		case "Story_DanielleAndResearcherAppear":
			ChangeCharacterAddressGroup(characterfromID("danielle"), "Treasure_Alcove", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterfromID("researcher"), "Treasure_Alcove", "officers", "reload1_2");
			AddPassenger(Pchar, characterFromID("danielle"), 0);
			AddPassenger(Pchar, characterFromID("researcher"), 0);

			SetOfficersIndex(PChar, 1, getCharacterIndex("Danielle"));
			SetCharacterRemovable(characterFromID("danielle"), false);
			SetOfficersIndex(PChar, 2, getCharacterIndex("Researcher"));
			SetCharacterRemovable(characterFromID("researcher"), false);

			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1 = "locator";
			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1.location = "Treasure_Alcove";
			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1.locator_group = "goto";
			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1.locator = "goto3";
			Pchar.quest.Story_DanielleAndResearcherComeCloser.win_condition = "Story_DanielleAndResearcherComeCloser";
		break;

		case "Story_DanielleAndResearcherComeCloser":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Treasure_room";

			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("danielle"), pchar, "", 3.0, 1.0);
		break;

		case "Story_ResearcherTalkInAlcove":
			LAi_SetActorType(characterFromID("researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Alcove_talk";
			LAi_ActorDialog(characterFromID("Researcher"), Pchar, "", 5.0, 1.0);
		break;

		case "Story_ResearcherReadsDanielleTalks":
			LAi_ActorGoToLocator(characterFromID("Researcher"), "goto", "goto4", "", 30.0);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "ITakeTheStone";
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 5.0, 1.0);
		break;

		case "Story_ITakeTheStone":
			LAi_ActorRunToLocator(characterFromID("danielle"), "goto", "goto5", "Story_PlayTheFirstPartVideo_prepare", 15.0);
		break;

		case "Story_PlayTheFirstPartVideo_prepare":
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterfromID("danielle"), "Story_PlayTheFirstPartVideo", 15.0);
		break;

		case "Story_PlayTheFirstPartVideo":
			GiveItem2Character(pchar, "artefact");
			SetNextWeather("Black Pearl Fight");
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("standard\temple", 100, "Story_Escaped_from_temple");
		break;

		case "Story_Escaped_from_temple":
			PostEvent("DoInfoShower",100,"s","");
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
			AddQuestRecord("Into_the_temple",5); // SA
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("Danielle");
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "KhaelRoa_port", "Officers", "Reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Researcher"), "KhaelRoa_port", "Officers", "Reload1_2");
			DoQuestReloadToLocation("KhaelRoa_port", "Reload", "Reload1", "Story_GetOnBoardOnKhaelRoa");
		break;

		case "Story_GetOnBoardOnKhaelRoa":
			RestorePassengers(pchar.id);
			LAi_type_actor_Reset(characterFromID("Danielle"));
			LAi_type_actor_Reset(characterFromID("Researcher"));

			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterfromID("danielle"));
			LAi_type_actor_Reset(characterFromID("Researcher"));
			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "TempleWillBlast";
			LAi_ActorDialog(characterFromID("researcher"), PChar, "to_the_ship_whualya", 2.0, 0);
		break;

		case "to_the_ship_whualya":
			LAi_SetOfficerType(characterFromID("researcher"));
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Take_Me_Home_Repeat"; // was "Home_again" but that triggers "Story_Take_Clement_Home3"
			Locations[FindLocation("KhaelRoa_port")].reload.l2.disable = 1;
//			ReStorePassengers(pchar.id);
		break;

		case "Story_LeavingKhaelRoa":
			LAi_QuestDelay("Story_FinalBattleWithBlackPearl", 5.0); // KK // TIH fixed big typo Oct30'06
		break;

		case "Story_FinalBattleWithBlackPearl": // KK
			SetRumourState("BP_Start", false); // NK
			LAi_Create_Officer(10, CharacterFromID("Barbossa")); // NK
			Lai_SetImmortal(CharacterFromID("Barbossa"), false);
			Group_AddCharacter("Black_Pearl", "Barbossa");
			SetCharacterRelation(GetCharacterIndex("Barbossa"),GetMainCharacterIndex(),RELATION_ENEMY);

			Group_SetGroupCommander("Black_Pearl", "Barbossa");
			Group_SetTaskAttack("Black_Pearl", PLAYER_GROUP, true);
			Group_SetAddress("Black_Pearl", "KhaelRoa", "Quest_Ships","Quest_Ship_2");
			Group_LockTask("Black_Pearl");
			characters[GetCharacterindex("Barbossa")].ship.hp = 100000;
//			RemoveOfficersIndex(pchar, GetCharacterIndex("researcher"));
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("blackpearl", 100, "Story_FaceTheBoss");
			Island_SetGotoEnableLocal("KhaelRoa", "reload_1", false);
			iForceDetectionFalseFlag = 1; // KK
		break;

		case "onUseArtefact":
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("artefact", 100, "post_use_artefact");
			TakeItemFromCharacter(pchar, "artefact");
// KK -->
			LAi_SetCrewImmortal(characterFromID("Barbossa"), false);
			Character_SetAbordageEnable(characterFromID("Barbossa"), true);
// <-- KK
		break;

		case "post_use_artefact":
			PostEvent("DoInfoShower",100,"s","");
			CreateEntity(&artifact, "artifact");
			LayerAddObject(SEA_REALIZE, &artifact, -1);

// KK -->
			iHP = GetCharacterShipHP(PChar);
			ipassenger = GetCompanionIndex(pchar, 1);
			if (iPassenger > 0) iHP += GetCharacterShipHP(&Characters[iPassenger]);
			ipassenger = GetCompanionIndex(pchar, 2);
			if (iPassenger > 0) iHP += GetCharacterShipHP(&Characters[iPassenger]);
			ipassenger = GetCompanionIndex(pchar, 3);
			if (iPassenger > 0) iHP += GetCharacterShipHP(&Characters[iPassenger]);
// <-- KK
			// PS -->
			//iPassenger = pchar.ship.type;
			// KK pchar.ship.hp =  GetCharacterShipHP(PChar); //ShipsTypes[iPassenger].HP;
			// PS <--

			if (GetCharacterShipHP(GetCharacter("Barbossa")) < iHP) characters[GetCharacterindex("Barbossa")].ship.hp = iHP; // KK
			/* NK - characters[GetCharacterindex("Barbossa")].skill.cannons = 7;
			characters[GetCharacterindex("Barbossa")].skill.accuracy = 7;
			characters[GetCharacterIndex("Barbossa")].perks.list.LightRepair = true;*/
			// NK <--
		break;

		case "Story_FaceTheBoss":
			PostEvent("DoInfoShower",100,"s","");
			QuestToSeaLogin_PrepareLoc("KhaelRoa", "Quest_Ships", "Quest_Ship_5", true);
			QuestToSeaLogin_Launch();

			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("KhaelRoa", false);

			pchar.quest.Story_KillTheFinalBoss.win_condition.l1 = "NPC_Death";
			pchar.quest.Story_KillTheFinalBoss.win_condition.l1.character = "Barbossa";
// KK -->
			pchar.quest.Story_KillTheFinalBoss.win_condition.l2 = "location";
			pchar.quest.Story_KillTheFinalBoss.win_condition.l2.location = "KhaelRoa";
// <-- KK
			pchar.quest.Story_KillTheFinalBoss.win_condition = "Story_KillTheFinalBoss";
		break;

		case "Story_KillTheFinalBoss":
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Into_the_temple",6); // SA
			Preprocessor_Remove("Danielle");
			iForceDetectionFalseFlag = 0; // KK
			if (CheckAttribute(Pchar, "HaveArtefact")) DeleteAttribute(Pchar, "HaveArtefact"); // KK
			bQuestDisableMapEnter = false;
			SetCharacterRemovable(characterFromID("Danielle"), true);
			SetCharacterRemovable(characterFromID("researcher"), true);
			// PB: Trigger video only on the worldmap to allow capturing the Black Pearl -->
			// DoQuestCheckDelay("Story_KillTheFinalBoss_2", 5.0);
			Pchar.quest.Story_KillTheFinalBoss_2.win_condition.l1 = "SeaEnter"; // Levis
			Pchar.quest.Story_KillTheFinalBoss_2.win_condition = "Story_KillTheFinalBoss_2";
			// PB: Trigger video only on the worldmap to allow capturing the Black Pearl <--
		break;

		case "Story_KillTheFinalBoss_2":
			DelEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo");
			if(LanguageGetLanguage() == "RUSSIAN") PostVideoAndQuest("standard\RUSSIAN\ending",100, "credits");
			else PostVideoAndQuest("standard\ending",100, "credits");
		break;

		case "credits":
			PostEvent("DoInfoShower",100,"s","");
			PostVideoAndQuest("common\English\credits", 1, "end_game");
		break;

		case "end_game":
			SetQuestHeader("After_Final");  // --> Cat for Danielle fix
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("After_Final", 1);
			Preprocessor_Remove("Danielle");

			Pchar.quest.Story_Take_Clement_Home.win_condition.l1 = "location";
			Pchar.quest.Story_Take_Clement_Home.win_condition.l1.location = "Oxbay_Lighthouse";
			Pchar.quest.Story_Take_Clement_Home.win_condition = "Story_Take_Clement_Home";
			Pchar.quest.Story_Take_Clement_Home.fail_condition = "Story_Take_Clement_Home";
//			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "Home_again";
//			Characters[GetCharacterIndex("danielle")].Dialog.CurrentNode = "Clement_home";

			// KK: Swap cursed Pearl with normal Pearl -->
			if (GetCharacterShipID(PChar) == SHIP_CURSED) GiveShip2Character(pchar, "BlackPearl", "Black Pearl", -1, PIRATE, true, true);
			iPassenger = GetCompanionIndex(PChar, 1);
			if (iPassenger > 0 && GetCharacterShipID(&Characters[iPassenger]) == SHIP_CURSED) GiveShip2Character(&Characters[iPassenger], "BlackPearl", "Black Pearl", -1, PIRATE, true, true);
			iPassenger = GetCompanionIndex(PChar, 2);
			if (iPassenger > 0 && GetCharacterShipID(&Characters[iPassenger]) == SHIP_CURSED) GiveShip2Character(&Characters[iPassenger], "BlackPearl", "Black Pearl", -1, PIRATE, true, true);
			iPassenger = GetCompanionIndex(PChar, 3);
			if (iPassenger > 0 && GetCharacterShipID(&Characters[iPassenger]) == SHIP_CURSED) GiveShip2Character(&Characters[iPassenger], "BlackPearl", "Black Pearl", -1, PIRATE, true, true);
			// KK: Swap cursed Pearl with normal Pearl <--

			Reinit_KhaelRoa();							// Enable Khael Roa as personal base
			LAi_group_SetLookRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_LOOK);	// GR: restore monsters to normal detection radius, increased at "monster_generate_in_alcove"
			LAi_group_SetHearRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_HEAR);
			LAi_group_SetSayRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_SAY);
			LAi_QuestDelay("end_game2", 1.0);					// originally triggered by dialog with Danielle after taking Clement to lighthouse
		break;

		case "end_game2":
// KK -->
			Pchar.quest.Story_AfterFinalOnRedmond1.win_condition.l1 = "location";
			Pchar.quest.Story_AfterFinalOnRedmond1.win_condition.l1.location = "Redmond_port";
			Pchar.quest.Story_AfterFinalOnRedmond1.win_condition = "Story_AfterFinalOnRedmond2";
			Pchar.quest.Story_AfterFinalOnRedmond1.fail_condition = "Story_AfterFinalOnRedmond2";
// <-- KK

			Pchar.quest.Story_AfterFinalOnRedmond2.win_condition.l1 = "location";
			Pchar.quest.Story_AfterFinalOnRedmond2.win_condition.l1.location = "Redmond_shore_02";
			Pchar.quest.Story_AfterFinalOnRedmond2.win_condition = "Story_AfterFinalOnRedmond2";
			Pchar.quest.Story_AfterFinalOnRedmond2.fail_condition = "Story_AfterFinalOnRedmond2";

			Pchar.quest.Story_AfterFinalOnRedmond3.win_condition.l1 = "location";
			Pchar.quest.Story_AfterFinalOnRedmond3.win_condition.l1.location = "Redmond_shore_01";
			Pchar.quest.Story_AfterFinalOnRedmond3.win_condition = "Story_AfterFinalOnRedmond2";
			Pchar.quest.Story_AfterFinalOnRedmond3.fail_condition = "Story_AfterFinalOnRedmond2";
			Characters[GetCharacterIndex("danielle")].Dialog.CurrentNode = "After_Final2";	  // <-- Cat for Danielle fix
		break;

		case "remove_officers_from_blaze_in_redmond_complete":
			characters[GetCharacterIndex("Eng_soldier_5")].dialog.currentnode = "do_not_go";
			LAi_ActorDialogNow(characterFromID("Eng_soldier_5"), pchar, "", -1);
		break;

		//Выходим от губернатора
		case "exit_from_silehard_complete":
			pchar.quest.main_line = "talk_in_tavern_begin";
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 7000); }
			else { AddPartyExp(pchar, 7000); }
			LAi_SetImmortal(characterFromID("Danielle"), true);
			// KK Group_SetAddress("Story_French_Squadron", "none", "Quest_Ships","Quest_Ship_7");
			Group_SetAddressNone("Story_French_Squadron"); // KK
			Group_DeleteGroup("Story_French_Squadron"); // KK

			LAi_SetStayType(characterFromID("danielle"));
			LAi_SetStayType(characterFromID("ralph fawn"));
			LAi_group_MoveCharacter(characterFromID("danielle"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(characterFromID("ralph fawn"), LAI_GROUP_PLAYER);

			locations[FindLocation("Redmond_town_01")].reload.l11.go = "quest_redmond_tavern"; // GR: Moved here from "Story_BlazeEscapedFromOxbay"
			ChangeCharacterAddress(characterFromID("Danielle"), "Quest_redmond_tavern", "goto2");
			ChangeCharacterAddress(characterFromID("Ralph Fawn"), "Quest_redmond_tavern", "goto3");
			ChangeCharacterAddressGroup(characterFromID("Charles Windem"), "Quest_redmond_tavern", "merchant", "goto1");
			//Делаем невозможность уйти из локации
			locations[FindLocation("Redmond_port")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_port")].reload.l3.disable = 1;
			locations[FindLocation("Redmond_Shore_01")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_Shore_02")].reload.l2.disable = 1;
			bQuestDisableSeaEnter = true; // You're not going back to sea until Silehard allows it!

			/*locations[FindLocation("Redmond_town_01")].reload.l1.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l2.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l3.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l4.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l5.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l6.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l7.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l8.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l9.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l10.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l11.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l12.disable = 1;
			locations[FindLocation("Redmond_town_01")].reload.l13.disable = 1;*/

			pchar.quest.to_quest_redmond_tavern.win_condition.l1 = "location";
			pchar.quest.to_quest_redmond_tavern.win_condition.l1.location = "Quest_Redmond_tavern";
			pchar.quest.to_quest_redmond_tavern.win_condition = "to_quest_redmond_tavern_complete";
			//убираем выход из таверны
			locations[FindLocation("quest_redmond_tavern")].reload.l1.disable = 1;
			// KK worldMap.islands.Oxbay.locations.city.label.icon = ENGLAND;
		break;

		// заходим в квестовую таверну.
		case "to_quest_redmond_tavern_complete":
			//восстанавливаем выходы из города
			locations[FindLocation("Redmond_port")].reload.l2.disable = 0;
			locations[FindLocation("Redmond_port")].reload.l3.disable = 0;
			locations[FindLocation("Redmond_Shore_01")].reload.l2.disable = 0;
			locations[FindLocation("Redmond_Shore_02")].reload.l2.disable = 0;
			bQuestDisableSeaEnter = false;	// Now you can go to sea - blocked at "exit_from_silehard_complete"
		break;

		case "prepare_to_battle_in_quest_redmond_tavern":
			LAi_SetActorType(pchar);

			locx = stf(loadedLocation.locators.camera.locator12.x);
			locy = stf(loadedLocation.locators.camera.locator12.y);
			locz = stf(loadedLocation.locators.camera.locator12.z);
			locCameraToPos(locx, locy, locz, false);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m0, "goto", "goto19"); // PB
			// NK - LAi_SetHP(sld, 50.0, 50.0);
			sld.id = "soldier1";
			sld.Dialog.Filename = "soldier_for_fight_in_tavern_01_dialog.c";
			sld.model.head = "h_" + Nations[ENGLAND].fantomModel.m0; // PB
			LAi_SetActorType(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto17"); // PB
			// NK - LAi_SetHP(sld, 50.0, 50.0);
			sld.id = "soldier2";
			LAi_SetWarriorType(sld);
			LAi_warrior_SetStay(sld, true);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto18"); // PB
			// NK - LAi_SetHP(sld, 50.0, 50.0);
			sld.id = "soldier3";
			LAi_SetWarriorType(sld);
			LAi_warrior_SetStay(sld, true);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "reload", "reload1"); // PB
			// NK - LAi_SetHP(sld, 50.0, 50.0);
			sld.id = "soldier4";
			LAi_SetWarriorType(sld);
			LAi_warrior_SetStay(sld, true);

			LAi_SetActorType(characterFromID("danielle"));
			LAi_SetActorType(characterFromID("ralph fawn"));

			LAi_group_MoveCharacter(characterFromID("soldier2"), "ENGLAND_TAVERN_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("soldier3"), "ENGLAND_TAVERN_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("soldier4"), "ENGLAND_TAVERN_SOLDIERS");


			LAi_ActorTurnToCharacter(pchar, characterFromID("soldier1"));
			LAi_ActorTurnToCharacter(characterFromID("Danielle"), characterFromID("soldier1"));
			LAi_ActorTurnToCharacter(characterFromID("Ralph Fawn"), characterFromID("soldier1"));

			LAi_ActorDialog(characterFromID("soldier1"), pchar, "", 5.0, 0);
			LAi_ActorWaitDialog(pchar, characterFromID("soldier1"));
		break;

		//солдат в таверне бьет нас по мордe
		case "kicked_by_soldier_complete":
			LAi_ActorAnimation(characterFromID("soldier1"), "attack_2", "kicked_by_soldier_2_complete", 0.5);
		break;

		case "kicked_by_soldier_2_complete":
			LAi_ActorAnimation(pchar, "hit_2", "kicked_by_soldier_3_complete", 1.5);
		break;

		case "kicked_by_soldier_3_complete":
			pchar.quest.main_line = "after_soldier_kick";
			//LAi_SetPlayerType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("soldier1"));
			LAi_ActorDialogNow(characterFromID("soldier1"), pchar, "", -1);
		break;

		case "fighting_in_tavern":
			LAi_SetPlayerType(pchar);
			locCameraFollow();
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_redmond_tavern")], false);
			LAi_SetWarriorType(characterFromID("soldier1"));
			LAi_group_MoveCharacter(characterFromID("soldier1"), "ENGLAND_TAVERN_SOLDIERS");

			LAi_SetHP(characterFromID("Ralph Fawn"), 1.0, 1.0);

			LAi_SetOfficerType(characterFromID("danielle"));
			LAi_SetOfficerType(characterFromID("ralph fawn"));
			LAi_group_FightGroups("ENGLAND_TAVERN_SOLDIERS", LAI_GROUP_PLAYER, true);
			//трактирщик убегает в обычную (не квестовую таверну)
			LAi_SetActorType(characterFromID("Charles Windem"));
			LAi_ActorRunToLocator(characterFromID("Charles Windem"), "merchant", "reload2", "Charles_escape_from_quest_redmond_tavern_complete", -1);
			LAi_group_SetCheck("ENGLAND_TAVERN_SOLDIERS", "out_from_quest_tavern_complete");
			LAi_QuestDelay("ralph_fawn_death_complete", 6.0);
		break;

		case "ralph_fawn_death_complete":
			LAi_KillCharacter(characterFromID("ralph fawn"));
		break;

		//смерть всех солдат в таверне
		case "out_from_quest_tavern_complete":
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_redmond_tavern")], true);
			pchar.quest.main_line = "fawn_death";
			Preprocessor_AddQuestData("Danielle", GetMyName(characterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(characterFromID("Danielle"))));
			Preprocessor_AddQuestData("pronoun3", XI_ConvertString(GetMyPronounPossessive(CharacterFromID("Danielle"))));
			if (characters[GetCharacterIndex("Danielle")].sex == "woman")
			{
				Preprocessor_AddQuestData("kid", XI_ConvertString("girl"));
			}
			else
			{
				Preprocessor_AddQuestData("kid", XI_ConvertString("lad"));
			}
			AddQuestRecord("Blaze_out_from_silehard", 2);
			LAi_QuestDelay("out_from_quest_tavern_complete_2", 3.0);
			Preprocessor_Remove("kid");
			Preprocessor_Remove("pronoun3");
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("Danielle");
		break;

		case "out_from_quest_tavern_complete_2":
			LAi_setActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "player_back", 3.0, 1.0);
		break;

		//Даниель убегает из таверны, оставляя там Блейза
		case "danielle_escape_from_quest_redmond_tavern_complete":
			//убираем Даниель
			ChangeCharacterAddress(characterFromID("Danielle"), "none", "none");
			LAi_QuestDelay("danielle_escape_from_quest_redmond_tavern_2_complete", 1.0);
		break;

		case "danielle_escape_from_quest_redmond_tavern_2_complete":
			LAi_SetStayType(pchar);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto17"); // PB
			sld.model.head = "h_" + Nations[ENGLAND].fantomModel.m1; // PB

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto18"); // PB
			sld.model.head = "h_" + Nations[ENGLAND].fantomModel.m2; // PB

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "reload", "reload1"); // PB
			sld.model.head = "h_" + Nations[ENGLAND].fantomModel.m1; // PB

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m0, "goto", "goto19"); // PB
			sld.model.head = "h_" + Nations[ENGLAND].fantomModel.m0; // PB
			sld.dialog.filename = "soldier_for_fight_in_tavern_01_dialog.c";

			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "player_back", 8.0, 2.0);


			locx = stf(loadedLocation.locators.camera.locator12.x);
			locy = stf(loadedLocation.locators.camera.locator12.y);
			locz = stf(loadedLocation.locators.camera.locator12.z);
			locCameraToPos(locx, locy, locz, false);
		break;

		//трактирщик убегает из квестовой таверны
		case "Charles_escape_from_quest_redmond_tavern_complete":
			//убираем трактирщика
			ChangeCharacterAddressGroup(characterFromID("Charles Windem"), "Redmond_Tavern", "merchant", "goto1");
			LAi_SetMerchantType(characterFromID("Charles Windem"));
		break;

		case "Blaze_to_prison_complete":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			StorePassengers("Blaze");

			DoQuestReloadToLocation("Redmond_prison", "goto", "goto9", "prepare_Edgar_to_Blaze_complete");
		break;

		case "prepare_Edgar_to_Blaze_complete":
			LAi_SetActorType(characterFromID("Edgar Attwood"));

			Preprocessor_AddQuestData("Danielle", GetMyName(characterFromID("Danielle")));
			AddQuestRecord("Blaze_out_from_silehard", 3);
			CloseQuestHeader("Blaze_out_from_silehard");
			Preprocessor_Remove("Danielle");
			SetQuestHeader("Blaze_in_prison");
			AddQuestRecord("Blaze_in_prison", 1);
			//Выключаем выход из тюрьмы
			locations[FindLocation("Redmond_prison")].reload.l1.disable = 1;
			//говорим подойти Эдгару к блейзу и начать разговор
			LAi_ActorGoToLocator(characterFromID("Edgar Attwood"), "goto", "goto23", "Edgar_to_Blaze_complete", -1);
			//включаем обычную таверну
			locations[FindLocation("Redmond_town_01")].reload.l11.go = "Redmond_tavern";
			//на всякий случай еще раз передвигаем трактирщика
			ChangeCharacterAddressGroup(characterFromID("Charles Windem"), "Redmond_Tavern", "merchant", "goto1");
		break;

		//Эдгар подходит к блейзу
		case "Edgar_to_Blaze_complete":
			locx = stf(loadedLocation.locators.camera.camera13.x);
			locy = stf(loadedLocation.locators.camera.camera13.y);
			locz = stf(loadedLocation.locators.camera.camera13.z);
			locCameraToPos(locx, locy, locz, false);

			pchar.quest.main_line = "prison";
			LAi_ActorDialogNow(characterFromID("Edgar Attwood"), pchar, "", -1);
			pchar.quest.edgar_life = "live";

			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1 = "locator";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1.location = "Redmond_prison";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1.locator_group = "merchant";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1.locator = "reload13";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition = "to_locator_where_soldiers_in_prison_see_you_complete";
		break;

		//Эдгар отходит от камеры
		case "wait_for_night_in_prison_complete":
			pchar.quest.main_line = "inside_redmond_prison";
			ChangeCharacterAddressGroup(characterFromID("Robert Christopher Silehard"), "Redmond_Prison", "merchant", "reload13");
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorGoToLocator(characterFromID("Robert Christopher Silehard"), "goto", "goto23", "Silehard_to_blaze_complete", -1);
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "escape_from_prison_node_2";
			LAi_Fade("", "");
		break;

		case "prepare_exit_from_cam":
			LAi_Fade("blaze_exit_from_cam_complete", "second_speak_with_edgar_complete");
		break;

		//Блейз выходит из камеры
		case "blaze_exit_from_cam_complete":
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			//ставим Эдгара рядом с блейзом
			locCameraFollow();
			ChangeCharacterAddress(pchar, "Redmond_prison", "goto12");
			pchar.quest.main_line = "escape_from_redmond_prison";
			ChangeCharacterAddress(characterFromID("Edgar Attwood"), "redmond_prison", "goto23");
			//даем квест на убийство всех стражников в тюрьме
			pchar.quest.kill_all_soldiers_in_prison.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_all_soldiers_in_prison.win_condition.l1.character = "Eng_soldier_35";
			pchar.quest.kill_all_soldiers_in_prison.win_condition.l2 = "NPC_Death";
			pchar.quest.kill_all_soldiers_in_prison.win_condition.l2.character = "Eng_soldier_36";
			pchar.quest.kill_all_soldiers_in_prison.win_condition = "kill_all_soldiers_in_prison_complete";
			//продолжаем разговор, где говорим, что нужно убить солдат на выходе.
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "escape_from_prison_node";
			//временно прячем губернатора
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "none", "none");
			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], false);
		break;

		case "kill_edgard_in_prison_2_complete":
			if (pchar.location == "redmond_prison")
			{
				LAi_SetPlayerType(pchar);
				pchar.quest.edgar_life = "death";
				AddQuestRecord("Blaze_in_prison", 4);
				//солдаты слышат шум и идут воевать игрока.
				LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				OfficersReaction("bad");
			}
		break;

		case "second_speak_with_edgar_complete":
			LAi_ActorDialog(characterFromID("Edgar Attwood"), pchar, "", 1.0, 1.0);
		break;

		//сайлхард подходит к блейзу
		case "Silehard_to_Blaze_complete":
			LAi_SetCitizenType(characterFromID("Edgar Attwood"));
			LAi_ActorDialogNow(characterFromID("Robert Christopher Silehard"), pchar, "", -1);
		break;

		case "exit_from_prison":
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.over = "yes";
			locCameraFollow();
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "redmond_residence", "goto8");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "main_line_find_rheims_node";
			pchar.quest.main_line = "blaze_talk_with_silehard";
			DoQuestReloadToLocation("redmond_residence", "goto", "goto3", "blaze_from_prison_to_residence_complete");
			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], true);
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			RecalculateJumpTable();
		break;

		//проходим за сайлхардом в его кабинет
		case "blaze_from_prison_to_residence_complete":
			ReStorePassengers(PChar.id); // KK
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);

			LAi_group_SetAlarm("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetAlarm("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetAlarm("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, 0.0);

			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], true);
			pchar.quest.kill_edgar_attwood_in_prison.over = "yes";
			pchar.quest.to_locator_where_soldiers_in_prison_see_you.over = "yes";
			locations[FindLocation("Redmond_prison")].reload.l1.disable = 0;
			LAi_SetHuberStayType(characterFromID("Robert Christopher Silehard"));
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, characterFromID("Robert Christopher Silehard"), "player_back", 2.0, 1.0);
			ChangeCharacterAddress(characterFromID("Eng_soldier_35"), "redmond_prison", "goto16");
			ChangeCharacterAddress(characterFromID("Eng_soldier_36"), "redmond_prison", "goto14");
			ChangeCharacterAddressGroup(characterFromID("Redmond prison commendant"), "redmond_prison", "sit", "sit1");

			DeleteAttribute(Pchar, "Quest.Story_OxbayCaptured");
			// KK SetTownNation("Oxbay", ENGLAND);
			CaptureTownForNation("Oxbay", ENGLAND); // KK
		//	DeleteAttribute(characterFromID("Oxbay Commander"), "recognized"); // PB: Added to 'CaptureTownForNation' function itself
			//Смена национальности форта Оксбэя
			// KK Characters[GetCharacterIndex("Oxbay Commander")].nation = ENGLAND;
			// KK Characters[GetCharacterIndex("Oxbay Commander")].model = "Soldier_Eng";
			//Смена французских солдат в Оксбэе на английских
			//Удаление французских

			//Убирание из гавани Оксбэя кораблей французской эскадры
			Group_SetAddress("Story_French_Squadron", "none", "Quest_Ships","Quest_Ship_7");
			Group_DeleteGroup("Story_French_Squadron"); // KK
			LAi_SetImmortal(characterFromID("FalaiseDeFleur Commander"), false);
			LAi_SetImmortal(characterFromID("Oxbay Commander"), false);

			// Why are we doing this??? No reason for France to _like_ you...05-03-26 if(GetRMRelation(PChar, FRANCE) < REL_AMNESTY) RMAmnesty(PChar, FRANCE); // NK fix 05-03-26 SetRMRelation(PChar, FRANCE, REL_AMNESTY); // RM - SetNationRelation2MainCharacter(FRANCE, RELATION_NEUTRAL);
			RestorePassengers("Blaze"); // TIH why was this removed? players never get their passengers back then...
			//ChangeCharacterAddress(characterFromID("Guy Gilroy"), "Oxbay_HouseInsideR9", "sit1"); // NK 05-07-20
		break;

		case "back_to_hovernor_type":
// KK -->
			  ChangeCharacterAddress(CharacterFromID("Counterspy"), "Redmond_town_01", "goto54");
			  ChangeCharacterAddress(CharacterFromID("Rabel Iverneau"), "Redmond_town_01", "goto55");
// <-- KK
			characters[GetCharacterIndex("Counterspy")].location = "none";
			characters[GetCharacterIndex("Rabel Iverneau")].location = "none";
			LAi_SetHuberStayType(characterFromID("Robert Christopher Silehard"));
		break;

		//убить всех солдат в тюрьме
		case "kill_all_soldiers_in_prison_complete":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			//появления губернатора со стражниками и начало разговора
			LAi_QuestDelay("Silehard_in_prison_complete", 3.0);
		break;

		case "silehard_in_prison_complete":
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Robert Christopher Silehard"));
			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], true);
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			ChangeCharacterAddressGroup(characterFromID("Robert Christopher Silehard"), "Redmond_Prison", "reload", "reload1");
			LAi_ActorDialog(characterFromID("Robert Christopher Silehard"), pchar, "", 5.0, 0);
		break;

		//блейз достигает локатора в тюрьме, за которым его видят стражники
		case "to_locator_where_soldiers_in_prison_see_you_complete":
			if (pchar.quest.main_line == "escape_from_redmond_prison")
			{
				LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
				//Убираем сидящего солдата
				ChangeCharacterAddress(characterFromID("Redmond prison commendant"), "none", "none");
			}
		break;

		case "exit_from_silehard_2_complete":
			ChangeCharacterAddress(characterFromID("Edgar Attwood"), "redmond_port", "goto_2");
			LAi_SetActorType(characterFromID("Edgar Attwood"));
			LAi_ActorDialog(characterFromID("Edgar Attwood"), pchar, "", 3.0, 1.0);
		break;

		//появление мужика, дающего информацию о местонахождении реймса
		case "ines_denied_exit_from_tavern_complete":
			pchar.quest.kill_pirate_for_rheims_lore.win_condition.l1 = "NPC_death";
			pchar.quest.kill_pirate_for_rheims_lore.win_condition.l1.character = "quest_pirate_01";
			pchar.quest.kill_pirate_for_rheims_lore.win_condition = "kill_pirate_for_rheims_lore_complete";
			LAi_SetHP(characterFromID("quest_pirate_01"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "QC_town", "goto12");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("quest_pirate_01"));
			LAi_ActorFollow(pchar, characterFromID("quest_pirate_01"), "", 2.0);
			LAi_ActorFollow(characterFromID("quest_pirate_01"), pchar, "ines_denied_exit_from_tavern_complete_2", 2.0);
		break;

		case "ines_denied_exit_from_tavern_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("quest_pirate_01"));
			LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "quest_pirate_01_back_to_player", 1.0, 1.0);
		break;

		case "quest_pirate_ines_info_denied_6":
			pchar.quest.main_line = "blaze_talk_with_innes_diaz_complete";
			AddQuestRecord("Blaze_search_Rheims", 4);
			locations[FindLocation("QC_town")].reload.l3.disable = 0;
			pchar.quest.kill_pirate_for_rheims_lore.over = "yes";
			LAi_SetCitizenType(characterFromID("quest_pirate_01"));
		//	DeleteAttribute(&PChar,"vcskip"); // NK 04-08
			DeleteAttribute(&Locations[FindLocation("QC_town")],"vcskip"); // PB
			DisableFastTravel(false); // PB
		break;

		case "quest_pirate_01_back_to_player":
			LAi_SetPlayerType(pchar);
		break;

		case "fight_with_quest_pirate_after_ines_denied":
			LAi_group_MoveCharacter(characterFromID("quest_pirate_01"), "QC_BRODYAGA");
			LAi_group_FightGroups("QC_BRODYAGA", LAI_GROUP_PLAYER, true);
			//LAi_ActorAttack(characterFromID("quest_pirate_01"), pchar, "");
		break;

		case "kill_pirate_for_rheims_lore_complete":
			AddQuestRecord("Blaze_search_Rheims", 13);
			pchar.quest.main_line = "blaze_talk_with_innes_diaz_complete_21";
			//возраждаем пирата для следующих сценок
			characters[getCharacterIndex("quest_pirate_01")].location = "none";
			LAi_SetCurHP(characterFromID("quest_pirate_01"), 80.0);

			Locations[FindLocation("QC_town")].reload.l3.disable = 0;

			OfficersReaction("bad");
			DeleteAttribute(&PChar,"vcskip"); // NK 04-08
		break;

		//говорим контрабандистам отвести блейза к камило мачадо
		case "exit_from_duarte_complete":
			PlaceCharacter(characterFromID("quest_smuggler_01"), "goto");

			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("quest_smuggler_01"), "", 2.0);
			LAi_ActorFollow(characterFromID("quest_smuggler_01"), pchar, "exit_from_duarte_complete_2", 2.0);
		break;

		case "exit_from_duarte_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("quest_smuggler_01"));
			Locations[FindLocation("Smugglers_residence")].reload.l1.disable = 1;
			LAi_ActorDialog(characterFromID("quest_smuggler_01"),  pchar, "player_back", 5.0, 1.0);
		break;

		//первый раз попадаем в дом к Мачадо
		case "blaze_first_speak_with_beltrop_complete":
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 1;
			Locations[FindLocation("Rheims_house_in_smugglers")].vcskip = true; // NK
			Locations[FindLocation("Conceicao_town")].reload.l3.disable = 0;
			pchar.quest.main_line = "blaze_talk_with_beltrop";
			LAi_SetActorType(characterFromID("Desmond Ray Beltrop"));
			LAi_ActorDialog(characterFromID("Desmond Ray Beltrop"), pchar, "beltrop_back_to_hovernor_type", 50, 0);
		break;

		case "beltrop_back_to_hovernor_type":
			if (makeint(environment.time) >= 22 || makeint(environment.time) < 6)
			{
				pchar.quest.main_line = "night_for_rheims_house_complete";
				Locations[FindLocation("Smugglers_Lair")].reload.l6.disable = 0;
			}
			LAi_SetHuberStayType(characterFromID("Desmond Ray Beltrop"));
			LAi_group_MoveCharacter(characterFromID("Desmond Ray Beltrop"), "SMUGGLERS_CITIZENS");
		break;

		//блейз ждал ночи в таверне
		case "wait_for_night_complete":
			//включаем ночь.
			pchar.quest.main_line = "night_for_rheims_house_complete";
			Locations[FindLocation("Smugglers_Lair")].reload.l6.disable = 0;
			AddQuestrecord("Blaze_search_Rheims", 8);
		break;

		//блейз ждет ночи в комнате
		case "wait_for_night_in_room_complete":
			pchar.quest.main_line = "night_for_rheims_house";
		break;

		//Блейз пробрался в дом Реймса
		case "blaze_to_rheims_house_in_smugglers_complete":
			LAi_QuestDelay("blaze_to_rheims_house_in_smugglers_find_book_complete", 2.0);
		break;

		//Блейз нашел книгу.
		case "blaze_to_rheims_house_in_smugglers_find_book_complete":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "goto", "goto2", "blaze_to_rheims_house_in_smugglers_find_book_complete_2", 2.0);
		break;

		case "blaze_to_rheims_house_in_smugglers_find_book_complete_2":
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "blaze_return_to_silehard_node";
			pchar.quest.main_line = "blaze_found_book_in_rheims_house";
			//Добавляем предмет
			GiveItem2Character(pchar, "rheims_journal");
			LAi_ActorSelfDialog(pchar, "");
		break;

		case "blaze_fight_in_rheims_house_complete":
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
			if (LAi_IsDead(characterFromID("Macario Regalo")) && LAi_IsDead(characterFromID("Evaristo Filho")))
			{
				//появляем других стражников
				ChangeCharacterAddressGroup(characterFromID("Fernam  Barrios"), "Rheims_house_in_smugglers", "reload", "reload1");
				ChangeCharacterAddressGroup(characterFromID("Leborio Violate"), "Rheims_house_in_smugglers", "reload", "reload1");
				LAi_SetActorType(characterfromID("Leborio Violate"));
				LAi_ActorFollow(pchar, characterfromID("Leborio Violate"), "", 1.0);
				LAi_ActorFollow(characterfromID("Leborio Violate"), pchar, "blaze_fight_in_rheims_house_complete_2", 1.0);
			}
			else
			{
				//появляем стражников у дома реймса
				ChangeCharacterAddressGroup(characterFromID("Macario Regalo"), "Rheims_house_in_smugglers", "reload", "reload1");
				ChangeCharacterAddressGroup(characterFromID("Evaristo Filho"), "Rheims_house_in_smugglers", "reload", "reload1");
				LAi_SetActorType(characterfromID("Evaristo Filho"));
				LAi_ActorFollow(pchar, characterfromID("Evaristo Filho"), "", 1.0);
				LAi_ActorFollow(characterfromID("Evaristo Filho"), pchar, "blaze_fight_in_rheims_house_complete_3", 1.0);
			}
		break;

		case "blaze_fight_in_rheims_house_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Leborio Violate"));
			LAi_ActorDialog(characterFromID("Leborio Violate"), pchar, "back_to_smuggler_guard", 3.0, 0);
		break;

		case "blaze_fight_in_rheims_house_complete_3":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Evaristo Filho"));
			LAi_ActorDialog(characterFromID("Evaristo Filho"), pchar, "back_to_smuggler_guard", 3.0, 0);
		break;

		case "back_to_smuggler_guard":
			Lai_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterfromID("Leborio Violate"), "SMUGGLERS_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("Evaristo Filho"), "SMUGGLERS_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("Fernam  Barrios"), "SMUGGLERS_SOLDIERS");
			LAi_group_MoveCharacter(characterfromID("Macario Regalo"), "SMUGGLERS_SOLDIERS");
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SMUGGLERS_SOLDIERS", "kill_guards_in_rheims_house_smugglers_complete");
			DeleteAttribute(&Locations[FindLocation("Rheims_house_in_smugglers")],"vcskip"); // NK
		break;

		//блейз убивает стражников
		case "kill_guards_in_rheims_house_smugglers_complete":
			if (pchar.location == "Rheims_house_in_smugglers")
			{
				LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
				AddQuestrecord("Blaze_search_Rheims", 9);
				pchar.quest.main_line = "blaze_return_to_silehard";
				Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
			}
			else
			{
				AddQuestrecord("Blaze_search_Rheims", 10);
				Locations[FindLocation("Smugglers_Lair")].reload.l5.disable = 0;
			}
			LAi_SetHP(characterFromID("quest_pirate_01"), 80.0, 80.0);
		break;

		//блейз убивает стражников
		case "kill_guards_in_rheims_house_smugglers_2_complete":
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			AddQuestrecord("Blaze_search_Rheims", 9);
			pchar.quest.main_line = "blaze_return_to_silehard";
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
		break;

		case "Friedrich_Corleis_go_away":
			LAi_SetActorType(characterfromID("Friedrich Corleis"));
			LAi_ActorGoToLocator(characterfromID("Friedrich Corleis"), "Merchant", "reload3", "blaze_to_incas_collection_begin_1_complete", -1);
		break;

		//Трактирщик на Дувезене уходит за пиратом
		case "blaze_to_incas_collection_begin_1_complete":
			ChangeCharacterAddress(characterFromID("Friedrich Corleis"), "none", "");
			LAi_QuestDelay("wait_for_pirate_in_tavern_complete", 2.0);
		break;

		case "wait_for_pirate_in_tavern_complete":
			RestoreCharacter(characterFromID("quest_pirate_01")); // KK
			LAi_SetHP(characterFromID("quest_pirate_01"), 80.0, 80.0);
			Lai_SetActorType(characterFromID("quest_pirate_01"));
			characters[GetCharacterIndex("quest_pirate_01")].model = "corsair2";
			characters[GetCharacterIndex("quest_pirate_01")].headmodel = "h_corsair2";
			characters[GetCharacterIndex("quest_pirate_01")].dialog.currentnode = "First time"; // CTM
			ChangeCharacterAddressGroup(characterFromID("quest_pirate_01"), "Douwesen_tavern", "reload", "reload1");
			LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "", 2.0, 1.0);
		break;

		case "teleport_to_douwesen_exit":
			LAi_SetCheckMinHP(characterFromID("quest_pirate_01"), LAi_GetCharacterHP(characterFromID("quest_pirate_01"))-1.0, false, "quest_pirate_01_exit_with_fight"); // KK
			ChangeCharacterAddressGroup(CharacterFromID("Friedrich Corleis"), "Douwesen_tavern", "merchant", "goto1");
			LAi_SetMerchantType(characterfromID("Friedrich Corleis"));
			DoQuestReloadToLocation("Douwesen_town_exit", "goto", "goto10", "incas_collection_to_douwesen_town_exit");
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "Douwesen_town_exit", "goto11");
			StorePassengers(pchar.id);
			LAi_SetMerchantType(characterfromID("Friedrich Corleis"));
			pchar.quest.return_officers_in_ship_location.win_condition.l1 = "location";
			pchar.quest.return_officers_in_ship_location.win_condition.l1.location = pchar.location.from_sea;
			pchar.quest.return_officers_in_ship_location.win_condition = "return_officers_in_ship_location";
		break;

		case "return_officers_in_ship_location":
			reStorePassengers(pchar.id);
		break;

		//пират объясняет нам как попасть в логово пиратов
		case "incas_collection_to_douwesen_town_exit":
			LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "", 2.0, 1.0);
		break;

		case "prepare_go_to_pirate_fort_complete":
			pchar.quest.main_line = "blaze_to_incas_collection_begin_3";
			pchar.quest.go_to_pirate_fort.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort.win_condition.l1.location = "Douwesen_jungle_03";
			pchar.quest.go_to_pirate_fort.win_condition = "go_to_pirate_fort_complete";
			LAi_ActorRunToLocator(CharacterFromID("quest_pirate_01"), "reload", "reload1_back", "", 90.0);
		break;

		case "go_to_pirate_fort_complete":
			LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "Douwesen_jungle_03", "citizen09");
			LAi_ActorRunToLocator(CharacterFromID("quest_pirate_01"), "reload", "reload3_back", "", 90.0);
			pchar.quest.go_to_pirate_fort1.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort1.win_condition.l1.location = "Douwesen_jungle_02";
			pchar.quest.go_to_pirate_fort1.win_condition = "go_to_pirate_fort1_complete";
		break;

		case "go_to_pirate_fort1_complete":
			LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
			ChangeCharacterAddressGroup(CharacterFromID("quest_pirate_01"), "Douwesen_jungle_02", "reload", "reload3");
			LAi_ActorRunToLocator(characterFromID("quest_pirate_01"), "reload", "reload2_back", "", 90.0);
			pchar.quest.go_to_pirate_fort2.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort2.win_condition.l1.location = "Douwesen_jungle_01";
			pchar.quest.go_to_pirate_fort2.win_condition = "go_to_pirate_fort2_complete";
		break;

		case "go_to_pirate_fort2_complete":
			LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "Douwesen_jungle_01", "citizen08");
			LAi_ActorRunToLocator(characterFromID("quest_pirate_01"), "reload", "reload1_back", "", 90.0);
			pchar.quest.go_to_pirate_fort3.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort3.win_condition.l1.location = "Pirate_Fort";
			pchar.quest.go_to_pirate_fort3.win_condition = "go_to_pirate_fort3_complete";
		break;

		case "go_to_pirate_fort3_complete":
			pchar.quest.main_line = "blaze_to_incas_collection_begin_4";
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "Pirate_fort", "goto17");
			if (!LAi_isDead(characterFromID("quest_pirate_01")))
			{
				LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("quest_pirate_01"), "", 2.0);
				LAi_ActorFollow(characterFromID("quest_pirate_01"), pchar, "go_to_pirate_fort4_complete", 2.0);
			}
			else
			{
				if (CalcCharacterSkill(pchar, SKILL_SNEAK) < 3)
				{
					LAi_SetActorType(characterFromID("Pieter Nolt"));
					LAi_SetActorType(pchar);
					LAi_ActorFollow(pchar, characterfromID("Pieter Nolt"), "", 3.0);
					LAi_ActorFollow(characterfromID("Pieter Nolt"), pchar, "speak_with_pieter_nolt", 3.0);
				}
			}
			reStorePassengers(pchar.id);
		break;

		case "speak_with_pieter_nolt":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Pieter Nolt"));
			LAi_ActorDialog(characterFromID("Pieter Nolt"), pchar, "pieter_nolt_back_to_soldier", 4.0, 0);
		break;

		case "go_to_pirate_fort4_complete":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("quest_pirate_01"));
			LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "player_back", 1.0, 1.0);
		break;

		case "pieter_nolt_back_to_soldier":
			LAi_SetPlayerType(pchar);
			LAi_SetCivilianPatrolType(characterFromID("Pieter Nolt")); // PB
			LAi_group_MoveCharacter(characterFromID("Pieter Nolt"), "DOUWESEN_PIRATE_SOLDIERS");
		break;

		case "pirate_go_to_jungle_complete":
			ChangeCharacterAddress(characterFromID("quest_pirate_01"), "none", "none");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_5";
		break;

		case "go_to_pirate_fort_fight_complete":
			if (!Lai_IsDead(characterFromID("quest_pirate_01")))
			{
				ChangeCharacterAddress(characterFromID("quest_pirate_01"), "Douwesen_jungle_03", "citizen01");
				LAi_ActorDialog(characterFromID("quest_pirate_01"), pchar, "", 2.0, 0);
				pchar.quest.go_to_pirate_fort3.win_condition.l1 = "location";
				pchar.quest.go_to_pirate_fort3.win_condition.l1.location = "Pirate_Fort";
				pchar.quest.go_to_pirate_fort3.win_condition = "go_to_pirate_fort3_complete";
			}
		break;

		case "garcilaso_fight_1":
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], false);
			AddQuestRecord("blaze_to_incas_collection", 7);
			LAi_QuestDelay("garcilaso_fight_4", 2.0);
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("Alistair Garcilaso"), "");
		break;

		case "garcilaso_fight_2":
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], false);
			AddQuestRecord("blaze_to_incas_collection", 15);
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("Alistair Garcilaso"), "");
			LAi_QuestDelay("garcilaso_fight_4", 2.0);
		break;

		case "garcilaso_fight_3":
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], false);
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("Alistair Garcilaso"), "");
			LAi_QuestDelay("garcilaso_fight_4", 2.0);
			GiveItem2Character(pchar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 14);
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle_sailor")], "none", "none");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "garcilaso_fight_4":
			LAi_KillCharacter(characterFromID("Alistair Garcilaso"));
			LAi_SetPlayerType(pchar);
			pchar.quest.main_line = "blaze_to_incas_collection_begin_6";
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], true);
		break;

		case "prepare_fighting_on_deck_complete":
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_6" || pchar.quest.main_line == "blaze_to_incas_collection_begin" || pchar.quest.main_line == "kill_pirate_06" || pchar.quest.main_line == "blaze_to_incas_collection_begin_7" || pchar.quest.main_line == "blaze_to_incas_collection_begin")
			{
				PlaceCharacter(characterFromID("danielle_sailor"), "goto");
				LAi_SetActorType(pchar);
				LAi_SetActorType(characterFromID("danielle_sailor"));
				LAi_ActorFollow(pchar, characterFromID("danielle_sailor"), "", 2.0);
				LAi_ActorFollow(characterFromID("danielle_sailor"), pchar, "prepare_fighting_on_deck_complete_2", 2.0);
			}
		break;

		case "prepare_fighting_on_deck_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle_sailor"));
			LAi_ActorDialog(characterFromID("danielle_sailor"), pchar, "player_back", 2.0, 1.0);
		break;

		case "incas_collection_exit_to_ship":
			DoQuestReloadToLocation("Ship_deck", "reload", "locator2", "fighting_on_deck_complete");
		break;

		case "incas_collection_exit_to_sea":
			if (Group_FindGroup("Pirate Captain 06") < 0) Group_CreateGroup("Pirate Captain 06");
			Group_AddCharacter("Pirate Captain 06", "Pirate Captain 06");
			Group_SetGroupCommander("Pirate Captain 06", "Pirate Captain 06");
			Group_SetAddress("Pirate Captain 06", "Douwesen", "Quest_Ships","Quest_Ship_9");
			sld = CharacterFromID("Pirate Captain 06");
			DeleteAttribute(sld, "surrendered");
			sld.nation = PIRATE;
		break;

		case "fighting_on_deck_complete":
			pchar.quest.abording_pirate_06.over = "yes";
			pchar.quest.kill_pirate_06.over = "yes";
			ChangeCharacterAddress(characterFromID("danielle_sailor"), "none", "none");
			LAi_group_MoveCharacter(characterFromID("pirate for abordage 01"), "PIRATES_FOR_ABORDAGE");
			LAi_group_MoveCharacter(characterFromID("pirate for abordage 02"), "PIRATES_FOR_ABORDAGE");
			LAi_group_MoveCharacter(characterFromID("pirate for abordage 03"), "PIRATES_FOR_ABORDAGE");
			LAi_group_SetRelation("PIRATES_FOR_ABORDAGE", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("PIRATES_FOR_ABORDAGE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_FOR_ABORDAGE", "kill_all_fighting_on_deck_complete");
		break;

		case "kill_all_fighting_on_deck_complete":
//			LAi_QuestDelay("kill_all_fighting_on_deck_complete_2", 2.0);
			pchar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 2000); }
			else { AddPartyExp(pchar, 2000); }
			DoQuestReloadToLocation("Douwesen_shore_01", "reload", "reload1", "kill_all_fighting_on_deck_complete_2");
		break;

		case "kill_all_fighting_on_deck_complete_2":
//			DoReloadCharacterToLocation("Douwesen_shore_01", "reload", "reload1");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_6";
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
			setCharacterShipLocation(characterFromID("Pirate Captain 04"), "none");
			AddQuestRecord("blaze_to_incas_collection", 8);
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";
			GiveItem2Character(pchar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
		break;

		//начинается сценка с изобретателем
		case "prepare_for_first_meeting_with_researcher":
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";		// LDH appears to be an error, part of different quest - 14Apr09
			ChangeCharacterAddress(characterFromID("Bernard Gosling"), "none", "none");
			ChangeCharacterAddress(characterFromID("Garry Ankers"), "none", "none");
			ChangeCharacterAddress(characterFromID("Susannah Lazar"), "none", "none");
			ChangeCharacterAddress(characterFromID("Michael Collop"), "none", "none");
			ChangeCharacterAddress(characterFromID("Edgar Malter"), "none", "none");
			//ChangeCharacterAddress(characterFromID("Harold Smith"), "none", "none");
			ChangeCharacterAddress(characterFromID("Alan Newman"), "none", "none");
			ChangeCharacterAddress(characterFromID("Audrey Proude"), "none", "none");
			ChangeCharacterAddress(characterFromID("Green_patrol_3"), "none", "none");
			ChangeCharacterAddress(characterFromID("Green_patrol_4"), "none", "none");
			ChangeCharacterAddress(characterFromID("Green_patrol_41"), "none", "none");

			// LDH optimizations 14Apr09
			ref murderer04 = characterFromID("murderer_in_greenford_04");
			ref murderer05 = characterFromID("murderer_in_greenford_05");
			ref murderer06 = characterFromID("murderer_in_greenford_06");

			LAi_SetStayType(murderer04);
			LAi_SetStayType(murderer05);
			LAi_SetStayType(murderer06);

			ChangeCharacterAddress(murderer04, "Greenford_town", "goto55");
			ChangeCharacterAddress(murderer05, "Greenford_town", "goto43");
			ChangeCharacterAddress(murderer06, "Greenford_town", "goto44");

			LAi_group_MoveCharacter(murderer04, "GREENFORD_MURDERERS");
			LAi_group_MoveCharacter(murderer05, "GREENFORD_MURDERERS");
			LAi_group_MoveCharacter(murderer06, "GREENFORD_MURDERERS");

			ResetHP(murderer04);	// LDH was hardcoded 50, didn't work for level 1 characters - 14Apr09
			ResetHP(murderer05);
			ResetHP(murderer06);

			LAi_SetCheckMinHP(murderer04, LAi_GetCharacterHP(murderer04)-1.0, false, "kill_murderer_2_complete");
			LAi_SetCheckMinHP(murderer05, LAi_GetCharacterHP(murderer05)-1.0, false, "kill_murderer_2_complete");
			LAi_SetCheckMinHP(murderer06, LAi_GetCharacterHP(murderer06)-1.0, false, "kill_murderer_2_complete");

			pchar.quest.main_line = "to_oxbay_by_prisoner_escape";
			ChangeCharacterAddress(characterFromID("greenford_citizen_01"), "Greenford_town", "goto23");

			pchar.quest.meeting_researcher.win_condition.l1 = "location";
			pchar.quest.meeting_researcher.win_condition.l1.location = "Greenford_town";
			pchar.quest.meeting_researcher.win_condition = "meeting_researcher_complete";

			Locations[FindLocation("Greenford_town")].models.always.koster = "koster";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.group = "goto";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.name = "goto24";
			Locations[FindLocation("Greenford_town")].models.always.koster.tech = "dLightModel";
			ChangeCharacterAddress(characterFromID("researcher"), "Greenford_town", "goto45");
			LAi_SetActorType(characterFromID("researcher"));
			LAi_ActorAnimation(characterFromID("researcher"), "Ground_sitting", "", "");

			Locations[FindLocation("Greenford_town")].reload.l1.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l2.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l3.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l7.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l9.disable = 1;
			AddQuestRecord("move_prisoner_from_greenford", 2);
		break;

		case "meeting_researcher_complete":
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("greenford_citizen_01"), "", 2.0);
			LAi_ActorFollow(characterFromID("greenford_citizen_01"), pchar, "meeting_researcher_complete_2", 2.0);
			LAi_group_SetCheck("GREENFORD_MURDERERS", "kill_all_murderer_in_greenford_complete");
		break;

		case "meeting_researcher_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("greenford_citizen_01"));
			LAi_ActorDialog(characterFromID("greenford_citizen_01"), pchar, "player_back", 1.0, 1.0);
		break;

		case "kicked_by_murderer_complete":
			LAi_ActorAnimation(characterFromID("murderer_in_greenford_04"), "attack_2", "kicked_by_murderer_complete_2", 0.3);
		break;

		case "kicked_by_murderer_complete_2":
			LAi_ActorAnimation(pchar, "hit_2", "kicked_by_murderer_2_complete", 2.5);
		break;

		case "kicked_by_murderer_2_complete":
			pchar.quest.main_line = "resque_researcher_bad_kick";
			LAi_SetPlayerType(pchar);
			LAi_ActorDialogNow(characterFromID("murderer_in_greenford_04"), pchar, "", -1);
		break;

		case "kick_murderer_complete":
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("murderer_in_greenford_04"), "");
			LAi_QuestDelay("kill_murderer_complete", 2.0);
		break;

		case "kill_murderer_complete":
			LAi_KillCharacter(characterFromID("murderer_in_greenford_04"));
			LAi_group_FightGroups("GREENFORD_MURDERERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			LAi_SetPlayerType(pchar);
		break;

		case "kill_murderer_2_complete":
			LAi_RemoveCheckMinHP(characterFromID("murderer_in_greenford_04"));
			LAi_RemoveCheckMinHP(characterFromID("murderer_in_greenford_05"));
			LAi_RemoveCheckMinHP(characterFromID("murderer_in_greenford_06"));

			LAi_group_FightGroups("GREENFORD_MURDERERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		break;

		case "kill_all_murderer_in_greenford_complete":
			LAi_Fade("greenford_to_normal", "we_resque_researcher");
		break;

		case "greenford_to_normal":
			ChangeCharacterAddress(characterFromID("greenford_citizen_01"), "none", "none");

			ChangeCharacterAddress(characterFromID("Bernard Gosling"), "Greenford_town", "goto5");
			ChangeCharacterAddress(characterFromID("Garry Ankers"), "Greenford_town", "goto13");
			ChangeCharacterAddress(characterFromID("Susannah Lazar"), "Greenford_town", "goto12");
			ChangeCharacterAddress(characterFromID("Michael Collop"), "Greenford_town", "goto15");
			ChangeCharacterAddress(characterFromID("Edgar Malter"), "Greenford_town", "goto38");
			//ChangeCharacterAddress(characterFromID("Harold Smith"), "Greenford_town", "goto11");
			ChangeCharacterAddress(characterFromID("Alan Newman"), "Greenford_town", "goto17");
			ChangeCharacterAddress(characterFromID("Audrey Proude"), "Greenford_town", "goto33");
			ChangeCharacterAddress(characterFromID("Green_patrol_3"), "Greenford_town", "goto4");
			ChangeCharacterAddress(characterFromID("Green_patrol_4"), "Greenford_town", "goto27");
			ChangeCharacterAddress(characterFromID("Green_patrol_41"), "Greenford_town", "goto17");

			ChangeCharacterAddress(characterFromID("murderer_in_greenford_04"), "none", "none");
			ChangeCharacterAddress(characterFromID("murderer_in_greenford_05"), "none", "none");
			ChangeCharacterAddress(characterFromID("murderer_in_greenford_06"), "none", "none");
		break;

		case "we_resque_researcher":
			LAi_SetStayType(pchar);
			Locations[FindLocation("Greenford_town")].reload.l9.disable = 0;
			pchar.quest.main_line = "resque_researcher_complete";
			//убираем столб.

			Locations[FindLocation("Greenford_town")].models.always.koster = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.group = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.name = "";
			LAi_ActorAnimation(characterFromID("researcher"), "Ground_StandUp", "resque_researcher_in_greenford_complete", 1.0);
		break;

		case "soldier_help_us_resque_researher":
			LAi_fade("soldier_help_us_resque_researher_2", "resque_researcher_in_greenford_complete");
		break;

		case "soldier_help_us_resque_researher_2":
			pchar.quest.main_line = "resque_researcher_complete";
			LAi_type_actor_Reset(characterFromID("researcher"));
			ChangeCharacterAddressGroup(pchar, "Greenford_town", "reload", "reload1");
			//убираем столб.
			Locations[FindLocation("Greenford_town")].models.always.koster = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.group = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.name = "";
			PlaceCharacter(characterFromID("researcher"), "goto");
			ChangeCharacterAddress(&characters[getCharacterIndex("researcher")], "Greenford_town", "goto9");
		break;

		case "resque_researcher_in_greenford_complete":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 3000); }
			else { AddPartyExp(pchar, 3000); }
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "resque_researcher_in_greenford_complete_2", 3.0);
		break;

		case "resque_researcher_in_greenford_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "player_back", 2.0, 1.0)
		break;

		case "first_speak_with_danielle_in_lighthouse":
			LAi_ActorGoToLocator(characterFromID("researcher"), "reload", "reload2", "researcher_to_stay_type", -1);
			pchar.quest.main_line = "meet_danielle_in_lighthouse";
			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "first_speak_with_vincent_in_lighthouse", 2.0, 1.0);
		break;

		case "researcher_to_stay_type":
			LAi_SetStayType(characterFromID("researcher"));
		break;

		case "first_speak_with_vincent_in_lighthouse":
			LAi_type_actor_Reset(characterFromID("Vincent bethune"));
			LAi_ActorDialog(characterFromID("Vincent bethune"), pchar, "first_speak_with_danielle_in_lighthouse_2", 2.0, 1.0);
		break;

		case "first_speak_with_danielle_in_lighthouse_2":
			LAi_ActorDialog(characterFromID("danielle"), pchar, "first_speak_with_danielle_in_lighthouse_3", 2.0, 1.0);
		break;

		case "first_speak_with_danielle_in_lighthouse_3":
			LAi_SetCitizenType(characterFromID("vincent bethune"));
			LAi_SetCitizenType(characterFromID("danielle"));
		break;

		case "meet_danielle_in_lighthouse_complete":
			pchar.quest.kill_all_murderer_in_greenford.over = "yes";
			LAi_ActorDialog(characterFromID("researcher"), pchar, "", 5.0, 1.0);
			locations[FindLocation("Oxbay_Lighthouse")].reload.l1.disable = 1;
		break;

		case "blaze_with_researcher_to_lighthouse":
			DoQuestReloadToLocation("Oxbay_Lighthouse", "reload", "reload1", "blaze_with_researcher_to_lighthouse_1");
		break;

		case "blaze_with_researcher_to_lighthouse_1":
			Locations[FindLocation("Greenford_town")].reload.l1.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l2.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l3.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l7.disable = 0;
			Locations[FindLocation("Greenford_town")].reload.l9.disable = 0;
			LAi_SetActorType(characterFromID("Vincent Bethune"));
			LAi_SetActorType(characterFromID("Danielle"));
			ChangeCharacterAddress(characterFromID("Danielle"), "Oxbay_Lighthouse", "goto28");
			ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Oxbay_Lighthouse", "goto9");
			ChangeCharacterAddress(characterFromID("researcher"), "Oxbay_Lighthouse", "goto7");
			pchar.quest.main_line = "meet_in_lighthouse";
			LAi_ActorFollow(CharacterFromID("Danielle"), pchar, "", -1);
			LAi_ActorFollow(CharacterFromID("Vincent Bethune"), pchar, "", -1);
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "blaze_with_researcher_to_lighthouse_2", 2.0);
		break;

		case "second_talk_with_Danielle_at_lighthouse":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), pchar, "player_back", 1.0, 1.0);
			pchar.quest.main_line = "speak_danielle_in_lighthouse_prepare_to_search_rheims";
		break;

		case "blaze_with_researcher_to_lighthouse_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("researcher"), pchar, "player_back", 1.0, 1.0);
		break;

		case "kill_edgard_in_prison_complete":
			pchar.quest.kill_edgard_in_prison_2.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_edgard_in_prison_2.win_condition.l1.character = "Edgar Attwood";
			pchar.quest.kill_edgard_in_prison_2.win_condition = "kill_edgard_in_prison_2_complete";
			LAi_SetActorType(pchar);
			LAi_ActorAttack(pchar, characterFromID("Edgar Attwood"), "");
			Lai_QuestDelay("kill_edgard_in_prison_complete_2", 2.0);
		break;

		case "kill_edgard_in_prison_complete_2":
			LAi_KillCharacter(characterFromID("Edgar Attwood"));
		break;

		case "abording_pirate_06_complete":
			pchar.quest.kill_pirate_06.over = "yes"; // PW
			pchar.quest.prepare_fighting_on_deck.over = "yes"; // GR
			setCharacterShipLocation(characterFromID("Pirate Captain 05"), "none");
			SetCharacterIslandLocation(characterFromID("Pirate Captain 06"), "none", "quest_ships", "quest_ship_9", "stay", "runaway", "");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_6";
			GiveItem2Character(pchar, "icollection"); // PW
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
			ChangeCharacterAddress(characterFromID("danielle_sailor"), "none", "locator12");
			AddQuestRecord("blaze_to_incas_collection", 9);
		break;

		case "kill_pirate_06_complete":
			setCharacterShipLocation(characterFromID("Pirate Captain 05"), "none");
			SetCharacterIslandLocation(characterFromID("Pirate Captain 06"), "none", "quest_ships", "quest_ship_9", "stay", "runaway", "");
			pchar.quest.main_line = "kill_pirate_06";
			characters[GetCharacterIndex("danielle_sailor")].quest.kill_pirate_06 = "done";
			AddQuestRecord("blaze_to_incas_collection", 10);
			DoQuestCheckDelay("kill_pirate_06_complete_2", 1.0);
		break;

		case "kill_pirate_06_complete_2":
			pchar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			DoReloadFromSeaToLocation("Douwesen_shore_01", "reload", "reload1");
			pchar.quest.back_to_douwesen_shore.win_condition.l1 = "location";
			pchar.quest.back_to_douwesen_shore.win_condition.l1.location = "Douwesen_shore_01";
			pchar.quest.back_to_douwesen_shore.win_condition = "prepare_fighting_on_deck_complete";
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 3000); }
			else { AddPartyExp(pchar, 3000); }
		break;

		case "find_statuets_complete":
			LAi_Fade("find_statuets_2_complete", "");
		break;

		case "find_statuets_2_complete":
			LAi_ActorDialog(characterFromID("danielle_sailor"), pchar, "", 5.0, 1.0);
			pchar.quest.main_line = "blaze_to_incas_collection_begin_7";
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
			AddQuestRecord("blaze_to_incas_collection", 11);
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";
			GiveItem2Character(pchar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
		break;

		case "see_statuetes_complete":
			LAi_Fade("", "see_statuetes_2_complete");
		break;

		case "see_statuetes_2_complete":
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorDialogNow(characterFromID("Robert Christopher Silehard"), pchar, "back_to_hovernor_type", -1);
			AddQuestRecord("blaze_to_incas_collection", 12);
			CloseQuestHeader("blaze_to_incas_collection");
		break;

		//возвращаемся на маяк для разговора даниэль и отплытия за реймсом
		case "return_to_lighthouse_search_rheims_complete":
			PlaceCharacter(characterFromID("Danielle"), "goto");
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 50, 0);
		break;

		//прибываем в порт дувезена
		case "to_douwesen_port_search_blaze_complete":
			if (pchar.quest.main_line == "blaze_goto_douwesen_with_danielle")
			{
				LAi_SetActorType(characterFromID("danielle")); // 04-12-08
				LAi_type_actor_Reset(characterFromID("danielle"));
				pchar.quest.to_douwesen_shore_1_search_blaze.over = "yes";
				pchar.quest.to_douwesen_shore_2_search_blaze.over = "yes";
				PlaceCharacter(characterFromID("danielle"), "goto");
				ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Douwesen_tavern", "goto3");
				Lai_SetSitType(characterFromID("Raoul Rheims"));
				ChangeCharacterAddressGroup(characterFromID("Raoul Rheims"), "Douwesen_tavern", "sit", "sit5");
				Locations[FindLocation("Douwesen_tavern")].vcskip = true; // NK
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("danielle"), "", 3.0);
				LAi_ActorFollow(characterFromID("danielle"), pchar, "danielle_speak_with_blaze_in_douwesen_port", 3.0);
			}
		break;

		//прибываем на первый пляж дувезена
		case "to_douwesen_shore_1_search_blaze_complete":
			if (pchar.quest.main_line == "blaze_goto_douwesen_with_danielle")
			{
				LAi_SetActorType(characterFromID("danielle")); // 04-12-08
				LAi_type_actor_Reset(characterFromID("danielle"));
				pchar.quest.to_douwesen_port_search_blaze.over = "yes";
				pchar.quest.to_douwesen_shore_2_search_blaze.over = "yes";
				PlaceCharacter(characterFromID("danielle"), "goto");
				ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Douwesen_tavern", "goto3");
				Lai_SetSitType(characterFromID("Raoul Rheims"));
				ChangeCharacterAddressGroup(characterFromID("Raoul Rheims"), "Douwesen_tavern", "sit", "sit5"); // NK
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("danielle"), "", 3.0);
				LAi_ActorFollow(characterFromID("danielle"), pchar, "danielle_speak_with_blaze_in_douwesen_port", 3.0);
			}
		break;

		//прибываем на второй пляж дувезена
		case "to_douwesen_shore_2_search_blaze_complete":
			if (pchar.quest.main_line == "blaze_goto_douwesen_with_danielle")
			{
				LAi_SetActorType(characterFromID("danielle")); // 04-12-08
				LAi_type_actor_Reset(characterFromID("danielle"));
				pchar.quest.to_douwesen_port_search_blaze.over = "yes";
				pchar.quest.to_douwesen_shore_1_search_blaze.over = "yes";
				PlaceCharacter(characterFromID("danielle"), "goto");
				ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Douwesen_tavern", "goto3");
				Lai_SetSitType(characterFromID("Raoul Rheims"));
				ChangeCharacterAddressGroup(characterFromID("Raoul Rheims"), "Douwesen_tavern", "sit", "sit5"); // NK
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("danielle"), "", 3.0);
				LAi_ActorFollow(characterFromID("danielle"), pchar, "danielle_speak_with_blaze_in_douwesen_port", 3.0);
			}
		break;

		case "danielle_speak_with_blaze_in_douwesen_port":
			pchar.quest.main_line = "blaze_goto_douwesen_with_danielle_2";
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("danielle"), pchar, "danielle_becomes_officer_in_douwesen", 1.0, 1.0);
		break;

		case "danielle_becomes_officer_in_douwesen":
			LAi_SetPlayerType(pchar);
			Locations[FindLocation("Douwesen_port")].reload.l2.disable = 1;
			Locations[FindLocation("Douwesen_port")].reload.l3.disable = 1;
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = 1;
			Locations[FindLocation("Douwesen_shore_02")].reload.l2.disable = 1;
			pchar.quest.main_line = "blaze_goto_douwesen_with_danielle_3";
			pchar.quest.goto_with_danielle_to_douwesen_tavern_for_rheims.win_condition.l1 = "location";
			pchar.quest.goto_with_danielle_to_douwesen_tavern_for_rheims.win_condition.l1.location = "Douwesen_tavern";
			pchar.quest.goto_with_danielle_to_douwesen_tavern_for_rheims.win_condition = "goto_with_danielle_to_douwesen_tavern_for_rheims_complete";

			LAi_SetOfficerType(characterFromID("danielle"));
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("danielle"));
			SetCharacterRemovable(characterFromID("danielle"), false);
		break;

		//заходим в таверну за Винсетом, который покажет нам реймса
		case "goto_with_danielle_to_douwesen_tavern_for_rheims_complete":
			LAi_SetActorType(characterFromID("vincent bethune"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("Vincent Bethune"), "", 2.0);
			LAi_ActorFollow(characterFromID("Vincent Bethune"), pchar, "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_2", 2.0);
		break;

		case "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Vincent Bethune"));
			LAi_ActorDialog(characterFromID("Vincent Bethune"), pchar, "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_3", 1.0, 1.0);
		break;

		//Винсент идет за своими головорезами
		case "vincent_away_from_tavern_complete":
			ChangeCharacterAddress(characterFromID("Vincent Bethune"), "none", "none");
		break;

		case "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_3":
			LAi_ActorWaitDialog(pchar, characterFromID("danielle"));
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("danielle"), pchar, "player_back", 1.0, 1.0);
		break;

		case "from_tavern_to_rheims_house_complete":
			LAi_LocationMonstersGen(&locations[FindLocation("Douwesen_town_exit")], false);
			DeleteAttribute(&Locations[FindLocation("Douwesen_tavern")],"vcskip"); // NK
			Locations[FindLocation("Rheims_house_inside")].vcskip = true; // NK
			pchar.quest.main_line = "from_tavern_to_rheims_house";
			LAi_SetActorType(characterFromID("Raoul Rheims"));
			RemovePassenger(pchar, characterFromID("Danielle"));
			RemoveCharacterCompanion(pchar, characterFromID("Danielle"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Danielle"));
			StorePassengers(pchar.id);
			LAi_SetActorType(characterFromID("Danielle"));
			DoQuestReloadToLocation("Douwesen_town_exit", "goto", "goto2", "from_town_to_jungle_to_rheims_house_complete");
			locations[FindLocation("Douwesen_town_exit")].reload.l1.disable = 1;
			locations[FindLocation("Douwesen_town_exit")].reload.l2.disable = 1;

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestrecord("again_find_rheims", 4);
			Preprocessor_Remove("Danielle");
		break;

		//выходим в город и на нас нападют головорезы
		case "from_town_to_jungle_to_rheims_house_complete":
			PlaceCharacter(characterFromID("danielle"), "goto");
			PlaceCharacter(characterFromID("Raoul Rheims"), "goto");

			LAi_ActorDialog(characterFromID("danielle"), pchar, "", 5.0, 0);
		break;

		case "prepare_danielle_with_rheims_runaway_complete":
			LAi_SetHP(characterFromID("murderer_in_douwesen_01"), 60.0, 60.0);
			LAi_SetHP(characterFromID("murderer_in_douwesen_02"), 60.0, 60.0);
			LAi_SetHP(characterFromID("murderer_in_douwesen_03"), 60.0, 60.0);
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_01"), "douwesen_town_exit", "goto4");
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_02"), "douwesen_town_exit", "goto4");
			ChangeCharacterAddress(characterFromID("murderer_in_douwesen_03"), "douwesen_town_exit", "goto4");
			LAi_group_MoveCharacter(characterFromID("murderer_in_douwesen_01"), "DOUWESEN_MURDERERS");
			LAi_group_MoveCharacter(characterFromID("murderer_in_douwesen_02"), "DOUWESEN_MURDERERS");
			LAi_group_MoveCharacter(characterFromID("murderer_in_douwesen_03"), "DOUWESEN_MURDERERS");
			LAi_group_FightGroups("DOUWESEN_MURDERERS", LAI_GROUP_PLAYER, true);
			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1_back", "", 40.0);
			LAi_ActorRunToLocator(characterFromID("raoul Rheims"), "reload", "reload1_back", "danielle_with_rheims_runaway_complete", 40.0);
			LAi_group_SetCheck("DOUWESEN_MURDERERS", "kill_murderers_in_douwesen_town_exit_complete");

			pchar.quest.prepare_dagger.win_condition.l1 = "location";
			pchar.quest.prepare_dagger.win_condition.l1.location = "Rheims_house_inside";
			pchar.quest.prepare_dagger.win_condition = "prepare_dagger";
		break;

		//Даниэль с Реймсом убегают
		case "danielle_with_rheims_runaway_complete":
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Rheims_house_inside", "item", "item1");
			LAi_NoRebirthDisable(characterFromID("Raoul Rheims")); // PB: Just in case he somehow died
			ChangeCharacterAddress(characterFromID("Raoul Rheims"), "Rheims_house_inside", "goto1");
			ChangeCharacterAddress(characterFromID("Vincent Bethune"), "Rheims_house_inside", "goto2");
		break;

		case "prepare_dagger":
			locx = stf(loadedLocation.locators.camera.locator4.x);
			locy = stf(loadedLocation.locators.camera.locator4.y);
			locz = stf(loadedLocation.locators.camera.locator4.z);
			locCameraToPos(locx, locy, locz, false);

			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_type_actor_Reset(characterFromID("Raoul Rheims"));
			LAi_type_actor_Reset(characterFromID("Vincent Bethune"));
			LAi_ActorAnimation(characterFromID("Raoul Rheims"), "Lay_1", "", -1);
			LAi_ActorAnimation(characterFromID("Vincent Bethune"), "Lay_2", "", -1);

			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, characterFromID("danielle"), "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("danielle"), pchar);
			LAi_CharacterDisableDialog(characterFromID("Raoul Rheims"));
			LAi_CharacterDisableDialog(characterFromID("Vincent Bethune"));
			pchar.quest.main_line = "to_rheims_house";
		break;

		case "kill_murderers_in_douwesen_town_exit_complete":
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestrecord("again_find_rheims", 5);
			Preprocessor_Remove("Danielle");
			locations[FindLocation("Douwesen_town_exit")].reload.l1.disable = 0;
			locations[FindLocation("Douwesen_town_exit")].reload.l2.disable = 0;
			characters[GetCharacterIndex("murderer_in_douwesen_01")].location = "none";
			characters[GetCharacterIndex("murderer_in_douwesen_02")].location = "none";
			characters[GetCharacterIndex("murderer_in_douwesen_03")].location = "none";
		break;

		case "dagger":
			locx = stf(loadedLocation.locators.camera.locator4.x);
			locy = stf(loadedLocation.locators.camera.locator4.y);
			locz = stf(loadedLocation.locators.camera.locator4.z);
			locCameraToPos(locx, locy, locz, false);
			LAi_LocationMonstersGen(&locations[FindLocation("Douwesen_town_exit")], true);
			LAi_SetActorType(characterFromID("blaze"));
			LAi_SetImmortal(pchar, true);
			LAi_ActorAttack(characterFromID("danielle"), characterFromID("blaze"), "");
			LAi_QuestDelay("dagger_2", 2.0);
		break;

		case "dagger_2":
			LAi_ActorAnimation(characterFromID("blaze"), "death_1", "dagger_3", 2.0);
		break;

		case "dagger_3":
			LAi_ActorAnimation(characterFromID("blaze"), "Lay_1", "", -1);
			LAi_SetPlayerType(characterFromID("danielle"));
			SetMainCharacterIndex(GetCharacterIndex("danielle"));
			PChar = GetMainCharacter(); // PB: This is IMPORTANT to update that you are now 'Danielle'!
			ChangeCharacterAddress(characterFromID("Blaze"), "Rheims_house_inside", "goto5");

			DoQuestReloadToLocation("Rheims_house_inside", "item", "item1", "start_quest_movie_speak_with_rheims_complete");
			pchar.quest.main_line = "danielle_speak_with_almost_dead_rheims";

			locations[FindLocation("Douwesen_town_exit")].reload.l1.disable = 0;
			locations[FindLocation("Douwesen_town_exit")].reload.l2.disable = 0;
		break;

		//Блэйз слышит диалог Даниель с Реймсом
		case "start_quest_movie_speak_with_rheims_complete":
			locx = stf(loadedLocation.locators.camera.locator4.x);
			locy = stf(loadedLocation.locators.camera.locator4.y);
			locz = stf(loadedLocation.locators.camera.locator4.z);
			locCameraToPos(locx, locy, locz, false);

			LAi_CharacterEnableDialog(characterFromID("Raoul Rheims"));
			characters[GetCharacterIndex("Raoul Rheims")].dialog.currentnode = "danielle_speak_with_almost_dead_rheims_node";
			LAi_ActorSetLayMode(characterFromID("Raoul Rheims"));
			LAi_ActorWaitDialog(characterFromID("Raoul Rheims"), pchar);
			LAi_SetActorType(pchar);
			LAi_ActorDialogNow(pchar, characterFromID("Raoul Rheims"), "", -1);
		break;

		case "start_quest_movie_speak_with_rheims_complete_2":
			LAi_ActorGoToLocator(pchar, "reload", "reload1", "exit_after_speak_with_rheims", 5.0);
		break;

		case "kill_ferro_cerezo_complete":
			pchar.quest.main_line = "compramat_bul_bul";
			AddQuestrecord("search_danielle", 8);
		break;

		case "abording_ferro_cerezo_complete":
			GiveItem2Character(pchar, "domingues_fucked");
			pchar.quest.main_line = "compramat_done";
			AddQuestRecord("search_danielle", 7);
			pchar.quest.kill_ferro_cerezo_complete.over = "yes";
		break;

		//блэйза бьют по башке
		case "to_oxbay_mine_complete":
			if (pchar.location.locator == "reload1")
			{
				LAi_SetHP(characterFromID("Stephan Bonser"), 60.0, 60.0);
				LAi_SetHP(characterFromID("Oswald Chappel"), 60.0, 60.0);
				LAi_SetHP(characterFromID("Gyles Dubois"), 60.0, 60.0);
				ChangeCharacterAddress(characterFromID("Stephan Bonser"), "Oxbay_canyon", "goto29");
				ChangeCharacterAddress(characterFromID("Oswald Chappel"), "Oxbay_canyon", "goto30");
				ChangeCharacterAddress(characterFromID("Gyles Dubois"), "Oxbay_canyon", "goto18");
				LAi_SetActorType(characterFromID("Stephan Bonser"));
				LAi_SetActorType(characterFromID("Oswald Chappel"));
				LAi_SetActorType(characterFromID("Gyles Dubois"));
				LAi_ActorFollow(characterFromID("Oswald Chappel"), pchar, "", -1);
				LAi_ActorFollow(characterFromID("Gyles Dubois"), pchar, "", -1);
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("Stephan Bonser"), "", 2.0);
				LAi_ActorFollow(characterFromID("Stephan Bonser"), pchar, "to_oxbay_mine_complete_2", 2.0);

				Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
				Locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 1;
			}
			else
			{
				pchar.quest.main_line = "kick_on_mine_not_exist";
			}
			Locations[FindLocation("Oxbay_canyon")].reload.l3.disable = false;
		break;

		case "to_oxbay_mine_complete_2":
			LAi_ActorWaitDialog(pchar, characterFromID("Stephan Bonser"));
			LAi_ActorDialog(characterFromID("Stephan Bonser"), pchar, "", 1.0, 0);
		break;

		case "kicked_to_mine_complete":
			LAi_SetActorType(pchar);
			pchar.quest.kill_ferro_cerezo.over = "yes";
			pchar.quest.abording_ferro_cerezo.over = "yes";
			if (characters[GetCharacterIndex("Ferro Cerezo")].location == "Conceicao_tavern") ChangeCharacterAddress(characterFromID("Ferro Cerezo"), "None", ""); // GR
			if (CalcCharacterSkill(pchar, SKILL_FENCING) > 7)
			{
				LAi_QuestDelay("after_kicked_2_complete", 0.5);
			}
			else
			{
				LAi_ActorTurnToCharacter(characterFromID("Stephan Bonser"), pchar);
				LAi_ActorAnimation(characterFromID("Stephan Bonser"), "attack_2", "kicked_to_mine_3_complete", 0.4);
			}
		break;

		case "kicked_to_mine_3_complete":
			LAi_SetActorType(pchar);
			LAi_ActorAnimation(pchar, "death_1", "after_kicked_complete", 3.5);
			LAi_SetImmortal(pchar, true);
			LAi_group_MoveCharacter(characterFromID("Stephan Bonser"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(characterFromID("Oswald Chappel"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(characterFromID("Gyles Dubois"), "MURDERERS_IN_CANYON");
			LAi_group_SetRelation("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, true);
		break;

		case "after_kicked_complete":
			LAi_SetImmortal(pchar, false);
			LAi_SetPlayerType(pchar);
			StorePassengers("Blaze");
			pchar.tempmoney = pchar.money;
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);

			pchar.quest.main_line = "slave_in_oxbay_mine_begin";
			DoQuestReloadToLocation("Oxbay_mine", "goto", "goto1", "to_mines_complete");
			Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_mine")].reload.l2.disable = 1;
			AddQuestRecord("search_danielle", 11);
		break;

		case "after_kicked_2_complete":
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Stephan Bonser"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(characterFromID("Oswald Chappel"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(characterFromID("Gyles Dubois"), "MURDERERS_IN_CANYON");
			LAi_group_SetRelation("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, true);
			pchar.quest.main_line = "kick_on_mine_not_exist";
			AddQuestRecord("search_danielle", 10);
			Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
		break;

		case "to_mines_complete":
			ChangeCharacterAddress(characterFromID("Stephan Bonser"), "none", "none");
			ChangeCharacterAddress(characterFromID("Oswald Chappel"), "none", "none");
			ChangeCharacterAddress(characterFromID("Gyles Dubois"), "none", "none");
			LAi_SetActorType(characterFromID("Leborio Drago"));
			LAi_ActorDialog(characterFromID("Leborio Drago"), pchar, "", 2.0, 1.0);
		break;

		case "second_speak_with_leborio_in_mines":
			pchar.quest.main_line = "resque_from_mines_denied";
			LAi_SetActorType(characterFromID("leborio drago"));
			LAi_ActorDialog(characterFromID("leborio drago"), pchar, "", 2.0, 1.0);
			LAi_ActorGoToLocator(characterFromID("mine_soldier_01"), "goto", "goto9", "mine_soldier_back_to_soldier", 5.0);
		break;

		case "mine_soldier_back_to_soldier":
			LAi_SetGuardianType(characterFromID("mine_soldier_01"));
			LAi_group_MoveCharacter(characterFromID("mine_soldier_01"), "ENGLAND_SOLDIERS");
		break;

		//включаем ролик, расставляем всех персонажей.
		case "movie_with_fight_complete":
			SetCurrentTime(23, 0);
			characters[GetCharacterIndex("danielle")].skill.fencing = "7";
			characters[GetCharacterIndex("danielle")].skill.sailing = "5";
			characters[GetCharacterIndex("danielle")].skill.cannons = "6";
			characters[GetCharacterIndex("danielle")].skill.accuracy = "4";
			characters[GetCharacterIndex("danielle")].rank = "9";
			characters[GetCharacterIndex("danielle")].experience = CalculateExperienceFromRank(9)+ (CalculateExperienceFromRank(9)/10 + rand(9000));
			// PS -->
			characters[GetCharacterIndex("danielle")].ship.type = "Pinnace2"; //SHIP_PINNACE2_SPAIN; fixed 04-10-25 emrep
			makearef(arship, characters[GetCharacterIndex("danielle")].ship); DeleteAttribute(arship,"stats");
//KB - Tuning ships - changed call to SetRandomStatsToShip
			SetRandomStatsToShip(sti(characters[GetCharacterIndex("danielle")].index), GetCharacterShipType(characters[GetCharacterIndex("danielle")]), SPAIN);
//KB - orig  SetRandomStatsToShip(arship, GetCharacterShipType(characters[GetCharacterIndex("danielle")]), SPAIN);
			SetCrewQuantity(characters[GetCharacterIndex("danielle")], GetMaxCrewQuantity(characters[GetCharacterIndex("danielle")]));
			characters[GetCharacterIndex("danielle")].ship.hp = GetCharacterShipHP(&characters[GetCharacterIndex("danielle")]); //4200;
			// PS <--
			// KNB characters[GetCharacterIndex("danielle")].Ship.Cannons.Type =  CANNON_TYPE_CANNON_LBS24;
			characters[GetCharacterIndex("danielle")].perks.list.LongRangeShoot = true;
			characters[GetCharacterIndex("danielle")].perks.list.FastReload = true;
			characters[GetCharacterIndex("danielle")].perks.list.CriticalHit = true;
			characters[GetCharacterIndex("danielle")].perks.list.Gunman = true;
			characters[GetCharacterIndex("danielle")].perks.list.CriticalHit = true;
			characters[GetCharacterIndex("danielle")].perks.list.BasicDamageControl = true;
			characters[GetCharacterIndex("danielle")].perks.list.AdvancedDamageControl = true;
			characters[GetCharacterIndex("danielle")].perks.list.ProfessionalDamageControl = true;
			characters[GetCharacterIndex("danielle")].perks.list.Rigging = true;
			characters[GetCharacterIndex("danielle")].perks.list.RiggingAdvance = true;
			GiveItem2Character(characterFromID("danielle"), "blade10");
			EquipCharacterByItem(characterFromID("danielle"), "blade10");

			LAi_SetActorType(characterFromID("Danielle"));
			LAi_ActorAnimation(characterFromID("Danielle"), "lay_1", "", -1);
			LAi_CharacterDisableDialog(characterFromID("Danielle"));
			ChangeCharacterAddress(characterFromID("Danielle"), "Quest_Muelle_town_01", "goto21");
			LAi_SetHP(characterFromID("pirate for quest muelle 01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("pirate for quest muelle 03"), 80.0, 80.0);
			LAi_SetHP(characterFromID("pirate for quest muelle 02"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 01"), "Quest_Muelle_town_01", "goto100");
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 02"), "Quest_Muelle_town_01", "goto101");
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 03"), "Quest_Muelle_town_01", "goto102");
			DoReloadCharacterToLocation("Quest_Muelle_town_01", "goto", "goto23");
			pchar.quest.to_quest_muelle.win_condition.l1 = "location";
			pchar.quest.to_quest_muelle.win_condition.l1.location = "Quest_Muelle_town_01";
			pchar.quest.to_quest_muelle.win_condition = "to_quest_muelle_complete";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID("Danielle"))));
			AddQuestRecord("search_danielle", 22);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("Danielle");
			Locations[FindLocation("Oxbay_canyon")].reload.l3.disable = true;
		break;

		case "to_quest_muelle_complete":
			LAi_group_MoveCharacter(characterFromID("pirate for quest muelle 01"), "QUEST_MUELLE_PIRATES");
			LAi_group_MoveCharacter(characterFromID("pirate for quest muelle 02"), "QUEST_MUELLE_PIRATES");
			LAi_group_MoveCharacter(characterFromID("pirate for quest muelle 03"), "QUEST_MUELLE_PIRATES");
			LAi_group_SetRelation("QUEST_MUELLE_PIRATES", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("QUEST_MUELLE_PIRATES", LAI_GROUP_PLAYER, true);

			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l1 = "NPC_death";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l1.character = "pirate for quest muelle 01";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l2 = "NPC_death";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l2.character = "pirate for quest muelle 02";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l3 = "NPC_death";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition.l3.character = "pirate for quest muelle 03";
			pchar.quest.kill_all_pirate_in_quest_muelle.win_condition = "kill_all_pirate_in_quest_muelle_complete";
		break;

		case "kill_all_pirate_in_quest_muelle_complete":
			LAi_CharacterEnableDialog(characterFromID("Danielle"));
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 01"), "none", "goto100");
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 02"), "none", "goto101");
			ChangeCharacterAddress(characterFromID("pirate for quest muelle 03"), "none", "goto102");
			LAi_Fade("prepare_back_to_muelle_complete", "back_to_muelle_complete");
		break;

		case "prepare_back_to_muelle_complete":
			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_SetActorType(pchar);
		break;

		case "back_to_muelle_complete":
			pchar.quest.main_line = "resque_danielle";
			LAi_ActorFollow(pchar, characterFromID("danielle"), "", 4.0);
			LAi_ActorFollow(characterFromID("danielle"), pchar, "back_to_muelle_complete_2", 4.0);
		break;

		case "back_to_muelle_complete_2":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 10000);
				AddPartyExpChar(pchar, "Sneak", 1000);
			}
			else { AddPartyExp(pchar, 10000); }
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromId("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "player_back", 2.0, 1.0);
			pchar.quest.blaze_to_map.win_condition.l1 = "location";
			pchar.quest.blaze_to_map.win_condition.l1.location = "Redmond";
			pchar.quest.blaze_to_map.win_condition = "blaze_to_map_complete";
		break;

		case "danielle_death":
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE1"));
			Lai_KillCharacter(pchar);
		break;

		case "blaze_to_map_complete":
			//задизейблить выход из карты
			pchar.location.from_sea = "Redmond_shore_01";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			DoReloadFromSeaToLocation("Redmond_shore_01", "reload", "reload1");
			pchar.quest.to_secret_oxbay_shore_complete.win_condition.l1 = "location";
			pchar.quest.to_secret_oxbay_shore_complete.win_condition.l1.location = "Redmond_shore_01";
			pchar.quest.to_secret_oxbay_shore_complete.win_condition = "to_secret_oxbay_shore_complete";
			//разрешить выход из карты
		break;

		case "to_secret_oxbay_shore_complete":
			LAi_SetActorType(characterFromID("danielle"));
			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_LocationFightDisable(&locations[FindLocation("Quest_Residence")], true);

			PlaceCharacter(characterFromID("danielle"), "goto");
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 5.0, 0);
		break;

		case "to_secret_oxbay_shore_complete2":
			LAi_type_actor_Reset(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 5.0, 0);
		break;

		case "both_to_residence_complete":
			pchar.quest.main_line = "both_to_redmond_residence";
			StorePassengers(pchar.id);
			LAi_SetOfficerType(characterFromID("Danielle"));

			// LDH - 10Apr09
			LAi_SetActorType(characterFromID("robert christopher silehard"));				// prevents errors in LAi_ActorDialog()
//			LAi_SetLoginTime(characterFromID("robert christopher silehard"), 0.0, 24.0);	// makes Silehard appear in bedroom
//			LAi_RemoveLoginTime(characterFromID("robert christopher silehard"));			// suggested by SJG

			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "Quest_residence", "goto6");
			DeleteAttribute(characterFromID("Robert Christopher Silehard"), "Dialog.Filename.GroupDialog"); // GR

			Locations[FindLocation("Quest_Residence")].reload.l1.disable = 1;
			DoQuestReloadToLocation("Quest_residence", "reload", "reload1", "both_to_residence_complete_2");
			characters[GetCharacterIndex("Robert Christopher Silehard")].Dialog.CurrentNode = "both_talk_with_Silehard_node";
			pchar.quest.main_line = "both_talk_with_Silehard";
			LAi_ActorDialog(CharacterFromID("Robert Christopher Silehard"), pchar, "", 5.0, 0);
			ChangeCharacterAddress(CharacterFromID("Danielle"), "Quest_residence", "goto4");
			Locations[FindLocation("Greenford_town")].reload.l9.close_for_night = 0;
		break;

		case "both_to_residence_complete_2":
			LAi_SetActorType(characterFromID("robert christopher silehard"));
			LAi_ActorDialog(characterFromID("robert christopher silehard"), pchar, "", 5.0, 1.0);
		break;

		case "both_escape_from_redmond_complete":
			PlaceCharacter(characterFromID("danielle"), "goto");
			pchar.quest.main_line = "both_escape_from_redmond";
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 5.0, 0);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Revenge_for_Silehard", 4);
			Preprocessor_Remove("Danielle");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 5000); }
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = true;
			LAi_RemoveLoginTime(characterFromID("robert christopher silehard"));			// suggested by SJG
		break;

		case "to_idol_complete":
			ChangeCharacterAddress(characterFromID("Danielle"), "none", "none");
		break;

		case "return_idol_from_frigate_complete":
			pchar.quest.return_idol_from_frigate1.over = "yes";
			pchar.quest.return_idol_from_frigate.over = "yes";
			Island_SetReloadEnableGlobal("Oxbay", true);
			bQuestDisableMapEnter = false;	//CTM
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Revenge_for_Silehard", "8");
			Preprocessor_Remove("Danielle");
			ChangeCharacterAddress(characterFromID("researcher"), "oxbay_lighthouse", "goto24");
			GiveItem2Character(pchar, "idol");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 30000); }
			else { AddPartyExp(pchar, 30000); }

			iForceDetectionFalseFlag = 0; // KK

			pchar.quest.main_line = "blaze_search_danielle_again";

			pchar.quest.to_lighthouse_to_meet_danielle_before_storm.win_condition.l1 = "location";
			pchar.quest.to_lighthouse_to_meet_danielle_before_storm.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.to_lighthouse_to_meet_danielle_before_storm.win_condition = "to_lighthouse_to_meet_danielle_before_storm";
		break;

		case "to_lighthouse_to_meet_danielle_before_storm":
			PlaceCharacter(characterFromID("researcher"), "goto");
			LAi_SetActorType(characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "", 20.0, 1.0);
			CloseQuestheader("Revenge_for_Silehard");
		break;

		case "prepare_for_storm":
//			AddQuestrecord("Where_are_i", 1);
			Pchar.quest.before_storm.win_condition.l1 = "MapEnter";
			Pchar.quest.before_storm.win_condition = "before_storm";
		break;

		case "before_storm":
			characters[getCharacterIndex("Greenford Commander")].skill.accuracy = "9";
			characters[getCharacterIndex("Greenford Commander")].skill.cannons = "5";
			/*worldMap.islands.Douwesen.locations.city.position.x = -195.439728;
			worldMap.islands.Douwesen.locations.city.position.y = 6.049987;
			worldMap.islands.Douwesen.locations.city.position.z = -106.659912;*/
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

// GR: new code, same as at "CounterSpy_Talk_AfterTavern_exit" -->
			PChar.quest.before_storm_fleet.original_fleet_size = GetCompanionQuantity(PChar);
			if(GetCompanionQuantity(PChar) > 1)
			{
				for (n=1; n<COMPANION_MAX; n++)
				{
					cc = GetCompanionIndex(PChar,n);
					temp = "companion" + n;
					if (cc > 0)
					{
						PChar.quest.before_storm_fleet.(temp) = characters[cc].id;
						if (HasSubStr(PChar.quest.before_storm_fleet.(temp), "Enc_Officer")) LAi_StoreFantom(CharacterFromId(PChar.quest.before_storm_fleet.(temp))); // Prevent character from being overwritten by another "Enc_Officer"
						RemoveCharacterCompanion(PChar, characters[cc]);
					}
					else PChar.quest.before_storm_fleet.(temp) = "*NULL*";
				}
			}
// <-- GR

			bMainMenuLaunchAfterVideo = true;

			CI_CreateAndSetControls( "WorldMapControls", "WMapCancel", -1, 0, true );// TIH worldmap cancel screwup prevention Sep3'06

			PostVideoAndQuest("storm",1, "storm_complete");
		break;

		case "storm_complete":
			ControlsInit(GetTargetPlatform(), false);
			// Screwface
			SaveGlobalOptions();// TIH return the key settings to the user Sep3'06
			// Screwface : end

			PostEvent("DoInfoShower",100,"s","");
			StorePassengers("Blaze");
			ExchangeCharacterShip(Pchar, characterFromID("Ship Storage"));
			pchar.ship.name = characters[GetCharacterIndex("Ship Storage")].ship.name;
			SetCharacterShipLocation(characterFromID("Ship Storage"), "Muelle_port");
			DeleteAttribute(pchar, "ship");
			pchar.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
// KK: I have disabled this feature and simply added food and rum to ships which
//     Nathaniel can use to leave the island. The setting as it was destroyed
//     realism.
			//pchar.skipfood = true; // NK; KK: commented out.
			pchar.tempmoney = pchar.money;
			pchar.money = 0;
			locations[FindLocation("Douwesen_town")].reload.l3.disable = true;
			CloseQuestHeader("Revenge_for_Silehard");
			SetQuestHeader("Where_are_i");
			AddQuestrecord("Where_are_i", 1);
			pchar.quest.main_line = "speak_with_peasant";
			Pchar.quest.Story_DanielleWaitsInMuelleTown.win_condition.l1 = "location";
			Pchar.quest.Story_DanielleWaitsInMuelleTown.win_condition.l1.location = "Muelle_tavern";
			Pchar.quest.Story_DanielleWaitsInMuelleTown.win_condition = "Story_DanielleWaitsInMuelleTown";

			Pchar.quest.Story_AppearOnIslaMuelleonAnacletoShip.win_condition.l1 = "location";
			Pchar.quest.Story_AppearOnIslaMuelleonAnacletoShip.win_condition.l1.location = "Muelle_port";
			Pchar.quest.Story_AppearOnIslaMuelleonAnacletoShip.win_condition = "Story_AppearOnIslaMuelleonAnacletoShip";

			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			ChangeCharacterAddress(&Characters[iPassenger], "Muelle_port", "Goto4");
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			ChangeCharacterAddress(&Characters[iPassenger], "Muelle_port", "Goto1");
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			ChangeCharacterAddress(&Characters[iPassenger], "Muelle_port", "Goto2");
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			DoQuestReloadToLocation("Douwesen_shore_01", "reload", "reload1", "to_douwesen_shore_complete");
		break;

		case "to_lighthouse_to_meet_danielle_before_storm":
			PlaceCharacter(characterFromID("researcher"), "goto");
			LAi_SetActorType(characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "", 20.0, 1.0);
			CloseQuestheader("Revenge_for_Silehard");
		break;

		case "fight_in_residence_complete":
			Locations[FindLocation("Quest_Residence")].reload.l1.disable = 1;
			LAi_SetActorType(characterFromID("Robert Christopher Silehard"));
			LAi_ActorRunToLocator(characterFromID("Robert Christopher Silehard"), "reload", "reload1", "silehard_escape_complete", 5.0);
		break;

		case "silehard_escape_complete":
			AddQuestRecord("Revenge_for_Silehard", 3);
			LAi_LocationFightDisable(&locations[FindLocation("Quest_Residence")], false);
			ChangeCharacterAddress(characterFromID("Robert Christopher Silehard"), "Redmond_residence", "goto8");
			//Locations[FindLocation("Redmond_town_01")].reload.l6.disable = 1;
			LAi_QuestDelay("soldier_in_residence", 1.5);
			ChangeCharacterAddress(characterFromID("researcher"), "oxbay_lighthouse", "goto24");

			LeaveService(PChar, ENGLAND, false); // RM
			if(GetRMRelation(PChar, ENGLAND) > REL_WAR) SetRMRelation(PChar, ENGLAND, REL_WAR); // RM - SetNationRelation2MainCharacter(ENGLAND,RELATION_ENEMY);
		break;

		case "soldier_in_residence":
			LAi_group_MoveCharacter(characterFromID("Eng Soldier for residence 01"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Eng Soldier for residence 02"), "ENGLAND_SOLDIERS");
			ChangeCharacterAddressGroup(characterFromID("Eng Soldier for residence 01"), "Quest_residence", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("Eng Soldier for residence 02"), "Quest_residence", "reload", "reload1");
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ENGLAND_SOLDIERS", "to_redmond_shore_01");
		break;

		case "to_redmond_shore_01":
			Locations[FindLocation("Quest_Residence")].reload.l1.go = "redmond_shore_01";
			Locations[FindLocation("Quest_Residence")].reload.l1.emerge = "reload2";
			Locations[FindLocation("Quest_Residence")].reload.l1.disable = 0;
			//DoQuestReloadToLocation("redmond_shore_01", "reload", "reload2", "both_escape_from_redmond_complete");
			pchar.quest.both_escape_from_redmond_complete.win_condition.l1 = "location";
			pchar.quest.both_escape_from_redmond_complete.win_condition.l1.location = "redmond_shore_01";
			pchar.quest.both_escape_from_redmond_complete.win_condition = "both_escape_from_redmond_complete";
		break;

		case "to_douwesen_shore_complete":
			AddQuestrecord("Where_are_i", 1);
			PlaceCharacter(characterFromID("peasant"), "goto");
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("peasant"), "", 2.0);
			LAi_ActorFollow(characterFromID("peasant"), pchar, "to_douwesen_shore_complete_2", 2.0);
		break;

		case "to_douwesen_shore_complete_2":
			LAi_ActorWaitDialog(pchar, characterFromID("peasant"));
			LAi_ActorDialog(characterFromID("peasant"), pchar, "player_back", 2.0, 1.0);
			ChangeCharacterAddressGroup(characterFromID("Anacleto Rui Sa Pinto"), "Pirate_tavern", "sit", "sit4");
			bQuestDisableMapEnter = true;
		break;

		case "kill_Serrao_complete":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			pchar.quest.main_line = "after_defeat_Serrao";
			LAi_type_actor_Reset(characterFromID("Gervasio Serrao"));
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Gervasio Serrao"));
			LAi_ActorDialogNow(characterFromID("Gervasio Serrao"), pchar, "player_back", -1);
			LAi_SetImmortal(characterFromID("Gervasio Serrao"), false);
		break;

		case "serrao_wait_for_hire":
			if (characters[GetCharacterIndex("Gervasio Serrao")].location.locator != "sit5")
			{
				LAi_Fade("serrao_wait_for_hire_2", "");
			}
		break;

		case "serrao_wait_for_hire_2":
			ChangeCharacterAddressGroup(characterFromID("Gervasio Serrao"), "pirate_tavern", "sit", "sit5");
			Lai_SetSitType(characterFromID("Gervasio Serrao"));
		break;

		case "kill_anacleto_complete":
			worldMap.playerShipX = stf(worldMap.islands.Douwesen.position.rx) + 19.0; // KK
			worldMap.playerShipZ = stf(worldMap.islands.Douwesen.position.rz) + 18.0; // KK
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Douwesen.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Douwesen.position.rz);

			bQuestDisableMapEnter = false;
			LAi_LocationFightDisable(&locations[Findlocation("pirate_tavern")], true);
//			pchar.ship.type = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.type;
//			pchar.ship.name = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.name;
//			pchar.ship.nation = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].nation; // KK
//			SetCrewQuantity(pchar, 200);
//			SetBaseShipData(pchar);
			ExchangeCharacterShip(Pchar, characterFromID("Anacleto Rui Sa Pinto")); // GR: you're taking Anacleto's ship, so take it, don't fake it
// KK -->
			// crew need something to eat
			AddCharacterGoods(pchar, GOOD_WHEAT, 70);
			AddCharacterGoods(pchar, GOOD_RUM, 35);
// <-- KK
			pchar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man1", "reload", "reload1");
			sld.headmodel = "h_man1";
			sld.id  = "temp_id_sld_fucker";
			sld.dialog.filename = "anacleto_dialog.c";
			sld.dialog.currentnode = "first time";
			LAi_SetActorType(sld);
//			LAi_SetStayType(pchar);
//			LAi_SetPlayerType(pchar);
			LAi_SetFightMode(PChar, false); // GR: If player kills Anacleto with one shot, player isn't automatically disarmed, so force it
			LAi_SetActorType(PChar);
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialog(sld, pchar, "sld_exit_from_pirate_tavern", 3.0, 1.0);
		break;

		case "sld_exit_from_pirate_tavern":
			LAi_SetPlayerType(pchar);
			LAi_ActorGoToLocation(characterFromID("temp_id_sld_fucker"), "reload", "reload1", "none", "", "", "", 10.0);
		break;

		case "kill_anacleto_complete_2":
// KK -->
			Lai_SetActorType(pchar);
			LAi_type_actor_Reset(pchar);
			Lai_SetPlayerType(pchar);
// <-- KK
			LAi_LocationFightDisable(&locations[Findlocation("pirate_tavern")], true);
//			pchar.ship.type = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.type;
//			pchar.ship.name = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.name;  // KK
//			pchar.ship.nation = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].nation; // KK
//			SetCrewQuantity(pchar, 200);
//			SetBaseShipData(pchar);
			ExchangeCharacterShip(Pchar, characterFromID("Anacleto Rui Sa Pinto")); // GR: you're taking Anacleto's ship, so take it, don't fake it
// KK -->
			// crew need something to eat
			AddCharacterGoods(pchar, GOOD_WHEAT, 70);
			AddCharacterGoods(pchar, GOOD_RUM, 35);
// <-- KK
			pchar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			bQuestDisableMapEnter = false;

// KK -->
			worldMap.playerShipX = stf(worldMap.islands.Douwesen.position.rx) + 0.4*(stf(worldMap.islands.Oxbay.position.rx) - stf(worldMap.islands.Douwesen.position.rx));
			worldMap.playerShipZ = stf(worldMap.islands.Douwesen.position.rz) + 0.2*(stf(worldMap.islands.Oxbay.position.rz) - stf(worldMap.islands.Douwesen.position.rz));
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Douwesen.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Douwesen.position.rz);
//			QuestToSeaLogin_PrepareLoc("Oxbay", "reload", "reload_5", true);
// <-- KK
			Island_SetReloadEnableGlobal("Oxbay", true);
			QuestToSeaLogin_Launch();
			pchar.quest.main_line = "blaze_search_danielle_again_10";
		break;


		case "danielle_MetBlazeOnIslaMuelle_Exit":
			LAi_ActorGoToLocator(characterFromID("danielle"), "reload", "reload2", "Story_BlazeMetDanielleOnIslaMuelle", 10.0);
		break;

		case "kill_Ogario_fight":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			LAi_LocationFightDisable(&Locations[FindLocation("Sidonio Ogarrio House")], false);
			Ambush("Rich_Citizens", 3, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
			Lai_group_MoveCharacter(CharacterFromID("Sidonio Ogarrio"), LAI_DEFAULT_GROUP);
			LAi_ActorAttack(characterfromID("Sidonio Ogarrio"), PChar, "");
		break;

		case "kill_Ogario_complete":
			DisableFastTravel(false);
			EndQuestMovie();
			characters[GetCharacterIndex("Wilfred Bythesea")].quest.kill_Ogarrio = "Almost_complete";
			AddQuestRecord("Kill_Ogario", 2);
			CloseQuestHeader("Kill_Ogario");
		break;

		case "kill_Ogario_timeout":
			ChangeCharacterAddress(characterFromID("Wilfred Bythesea"), "None", "");
			characters[GetCharacterIndex("Wilfred Bythesea")].quest.kill_Ogarrio = "Failed";
			AddQuestRecord("Kill_Ogario", 3);
			CloseQuestHeader("Kill_Ogario");
		break;

		case "remove_Wilfred_Bythesea":
			PChar.quest.remove_Wilfred_Bythesea2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.remove_Wilfred_Bythesea2.win_condition.l1.location = PChar.location;
			PChar.quest.remove_Wilfred_Bythesea2.win_condition = "remove_Wilfred_Bythesea2";
		break;

		case "remove_Wilfred_Bythesea2":
			ChangeCharacterAddress(characterFromID("Wilfred Bythesea"), "None", "");
		break;

		case "soldier_goto_to_mine_commander":
			ChangeCharacterAddress(characterFromID("mine_soldier_01"), "none", "none");
			LAi_QuestDelay("soldier_goto_to_mine_commander_2", 0.5);
		break;

		case "soldier_goto_to_mine_commander_2":
			ChangeCharacterAddressGroup(characterFromID("mine_commander"), "Oxbay_mine", "reload", "reload1");
			LAi_setActorType(characterFromID("Mine_commander"));
			LAi_ActorDialog(characterFromID("mine_commander"), pchar, "", 12.0, 0);
		break;

		case "commendant_exit_from_mines_complete":
			ChangeCharacterAddress(characterFromID("mine_commander"), "Mines_commander_house", "goto3");
			restorepassengers("Blaze");
			pchar.money = pchar.tempmoney;
			pchar.tempmoney = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l2.disable = 0;
		break;

		case "commendant_exit_2_from_mines_complete":
			ChangeCharacterAddress(characterFromID("mine_commander"), "Mines_commander_house", "goto3");
			LAi_ActorDialog(characterFromID("Leborio Drago"), pchar, "", 5.0, 0);
		break;

		case "wait_for_resque_from_mines":
			LAi_Fade("mine_soldier_return_to_post", "wait_for_resque_from_mines_complete");
		break;

		case "mine_soldier_return_to_post":
			ChangeCharacterAddress(characterFromID("mine_soldier_01"), "Oxbay_mine", "goto9");
			LAi_SetGuardianType(characterFromID("mine_soldier_01"));
			LAi_group_MoveCharacter(characterFromID("mine_soldier_01"), "ENGLAND_SOLDIERS");
		break;

		case "wait_for_resque_from_mines_complete":
			pchar.quest.main_line = "lets_go_mines";
			LAi_SetActorType(characterFromID("Leborio Drago"));
			LAi_ActorDialog(characterFromID("Leborio Drago"), pchar, "", 1.0, 1.0);
		break;

		case "lets_go_begin":
			pchar.location.from_sea = "Oxbay_lighthouse";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			LAi_SetImmortal(characterFromID("leborio drago"), true);
			GiveItem2Character(characterFromID("Leborio Drago"),"blade4");
			GiveItem2Character(characterFromID("Miner_01"),"blade4");
			GiveItem2Character(characterFromID("Miner_02"),"blade4");
			GiveItem2Character(characterFromID("Miner_03"),"blade4");
			GiveItem2Character(characterFromID("Miner_05"),"blade4");
			GiveItem2Character(pchar, "blade4");
			EquipCharacterByItem(pchar, "blade4");
			EquipCharacterByItem(characterFromID("Leborio Drago"), "blade4");
			EquipCharacterByItem(characterFromID("Miner_01"),"blade4");
			EquipCharacterByItem(characterFromID("Miner_02"),"blade4");
			EquipCharacterByItem(characterFromID("Miner_03"),"blade4");
			EquipCharacterByItem(characterFromID("Miner_05"),"blade4");
			LAi_SetHP(characterFromID("Leborio Drago"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Miner_01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Miner_02"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Miner_03"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Miner_05"), 80.0, 80.0);

			pchar.quest.main_line = "lets_go";
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 1;
			LAi_SetOfficerType(characterFromID("Leborio Drago"));
			LAi_SetOfficerType(characterFromID("Miner_01"));
			LAi_SetOfficerType(characterFromID("Miner_02"));
			LAi_SetOfficerType(characterFromID("Miner_03"));
			LAi_SetOfficerType(characterFromID("Miner_05"));

			LAi_QuestDelay("lets_go_begin_2", 1.0);
		break;

		case "lets_go_begin_2":
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			pchar.quest.to_canyon.win_condition.l1 = "location";
			pchar.quest.to_canyon.win_condition.l1.location = "Oxbay_canyon";
			pchar.quest.to_canyon.win_condition = "to_canyon_complete";

			pchar.quest.mine_soldiers_dead.win_condition.l1 = "NPC_Death";
			pchar.quest.mine_soldiers_dead.win_condition.l1.character = "Mine_soldier_02";
			pchar.quest.mine_soldiers_dead.win_condition.l2 = "NPC_Death";
			pchar.quest.mine_soldiers_dead.win_condition.l2.character = "Mine_soldier_03";
			pchar.quest.mine_soldiers_dead.win_condition.l3 = "NPC_Death";
			pchar.quest.mine_soldiers_dead.win_condition.l3.character = "Mine_soldier_04";
			pchar.quest.mine_soldiers_dead.win_condition = "mine_soldiers_dead_complete";
		break;

		case "mine_soldiers_dead_complete":
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l2.disable = 0;
			if (!LAi_IsDead(characterFromID("Leborio Drago")))
			{
				LAi_SetActorType(characterFromID("Leborio Drago"));
				LAi_ActorRunToLocation(characterFromID("Leborio Drago"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_1", "", 20.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_01")))
			{
				LAi_SetActorType(characterFromID("Miner_01"));
				// --> Swindler
				// Here's a syntax error:
				// LAi_ActorRunToLocation(characterFromID("Miner_01"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_2", "", 20.0.);
				LAi_ActorRunToLocation(characterFromID("Miner_01"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_2", "", 20.0);
				// Swindler <--

			}
			if (!LAi_IsDead(characterFromID("Miner_02")))
			{
				LAi_SetActorType(characterFromID("Miner_02"));
				LAi_ActorRunToLocation(characterFromID("Miner_02"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_2", "", 20.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_03")))
			{
				LAi_SetActorType(characterFromID("Miner_03"));
				LAi_ActorRunToLocation(characterFromID("Miner_03"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_3", "", 20.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_05")))
			{
				LAi_SetActorType(characterFromID("Miner_05"));
				LAi_ActorRunToLocation(characterFromID("Miner_05"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_4", "", 20.0);
			}
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 1;
		break;

		case "to_canyon_complete":
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			PlaceCharacter(characterFromID("Leborio drago"), "officers");
			PlaceCharacter(characterFromID("Miner_01"), "officers");
			PlaceCharacter(characterFromID("Miner_02"), "officers");
			PlaceCharacter(characterFromID("Miner_03"), "goto");
			PlaceCharacter(characterFromID("Miner_05"), "goto");
			LAi_SetOfficerType(characterFromID("Leborio Drago"));
			LAi_SetOfficerType(characterFromID("Miner_01"));
			LAi_SetOfficerType(characterFromID("Miner_02"));
			LAi_SetOfficerType(characterFromID("Miner_03"));
			LAi_SetOfficerType(characterFromID("Miner_05"));

			pchar.quest.to_lighthouse.win_condition.l1 = "location";
			pchar.quest.to_lighthouse.win_condition.l1.location = "Oxbay_lighthouse";
			pchar.quest.to_lighthouse.win_condition = "to_lighthouse_complete";

			pchar.quest.peace_when_we_are_leaving_canyon.win_condition.l1 = "ExitFromLocation";
			pchar.quest.peace_when_we_are_leaving_canyon.win_condition.l1.location = "Oxbay_canyon";
			pchar.quest.peace_when_we_are_leaving_canyon.win_condition = "peace_when_we_are_leaving_canyon";

			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);

			pchar.quest.canyon_soldiers_dead.win_condition.l1 = "NPC_Death";
			pchar.quest.canyon_soldiers_dead.win_condition.l1.character = "Mine_soldier_05";
			pchar.quest.canyon_soldiers_dead.win_condition.l2 = "NPC_Death";
			pchar.quest.canyon_soldiers_dead.win_condition.l2.character = "Mine_soldier_06";
			pchar.quest.canyon_soldiers_dead.win_condition = "canyon_soldiers_dead_complete";
		break;

		case "peace_when_we_are_leaving_canyon":
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 0;
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		break;

		case "canyon_soldiers_dead_complete":
			if (!LAi_IsDead(characterFromID("Leborio Drago")))
			{
				LAi_SetActorType(characterFromID("Leborio Drago"));
				LAi_ActorRunToLocation(characterFromID("Leborio Drago"), "reload", "reload6_back", "Oxbay_lighthouse", "officers", "reload1_1", "", 45.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_01")))
			{
				LAi_SetActorType(characterFromID("Miner_01"));
				LAi_ActorRunToLocation(characterFromID("Miner_01"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_02")))
			{
				LAi_SetActorType(characterFromID("Miner_02"));
				LAi_ActorRunToLocation(characterFromID("Miner_02"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_03")))
			{
				LAi_SetActorType(characterFromID("Miner_03"));
				LAi_ActorRunToLocation(characterFromID("Miner_03"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
			if (!LAi_IsDead(characterFromID("Miner_05")))
			{
				LAi_SetActorType(characterFromID("Miner_05"));
				LAi_ActorRunToLocation(characterFromID("Miner_05"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
		break;

		case "to_lighthouse_complete":
			LAi_SetImmortal(characterFromID("leborio drago"), false);
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			ChangeCharacterAddress(characterFromID("Miner_01"), "none", "none");
			ChangeCharacterAddress(characterFromID("Miner_02"), "none", "none");
			ChangeCharacterAddress(characterFromID("Miner_03"), "none", "none");
			ChangeCharacterAddress(characterFromID("Miner_05"), "none", "none");
			restorepassengers("Blaze");
			pchar.money = pchar.tempmoney;
			RestorePassengers(pchar.id);
			pchar.tempmoney = "0";
			Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			pchar.quest.main_line = "after_speak_with_leborio";
			LAi_type_actor_Reset(characterFromID("Leborio Drago"));
			ChangeCharacterAddressGroup(characterFromID("Leborio Drago"), "Oxbay_lighthouse", "officers", "reload1_1");
			characters[GetCharacterIndex("Leborio Drago")].quest.hire = "ask_for_hire";
			LAi_ActorDialog(characterFromID("Leborio Drago"), pchar, "", 2.0, 1.0);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 15000); }
			else { AddPartyExp(pchar, 15000); }
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("search_danielle", 16);
			Preprocessor_Remove("Danielle");
		break;

		case "hired_leborio_complete":
			LAi_SetOfficerType(characterFromID("leborio drago"));
		break;

		case "resque_danielle":
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.name = "reload1";
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.go = "Muelle_port";
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.emerge = "reload2";
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.autoreload = 0;
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.label = "port";

			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1", "danielle_to_muelle_port", 30.0);

			pchar.quest.to_secret_oxbay_shore.win_condition.l1 = "location";
			pchar.quest.to_secret_oxbay_shore.win_condition.l1.location = "Redmond_shore_01";
			pchar.quest.to_secret_oxbay_shore.win_condition = "to_secret_oxbay_shore_complete";
		break;

		case "danielle_to_muelle_port":
			ChangeCharacterAddress(characterFromID("danielle"), "none", "");
		break;

		case "wait_for_night_in_shore":
			SetCurrentTime(23, 0);
			LAi_Fade("", "to_secret_oxbay_shore_complete2");
		break;

		case "exit_after_speak_with_rheims":
			LAi_SetActorType(characterFromID("danielle"));
			SetMainCharacterIndex(0);
			PChar = GetMainCharacter(); // PB: This is IMPORTANT to update that you are now 'Blaze' again
			LAi_SetImmortal(pchar, false);
			ChangeCharacterAddress(characterFromID("Danielle"), "none", "none");
			ChangeCharacterAddress(characterFromID("Vincent Bethune"), "none", "none");
			ChangeCharacterAddress(characterFromID("Raoul Rheims"), "none", "none");
			DoQuestReloadToLocation("Rheims_house_inside", "goto", "goto5", "exit_after_speak_with_rheims_2");
			Locations[FindLocation("Douwesen_port")].reload.l2.disable = 0;
			Locations[FindLocation("Douwesen_port")].reload.l3.disable = 0;
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = 0;
			Locations[FindLocation("Douwesen_shore_02")].reload.l2.disable = 0;
			pchar.quest.main_line = "danielle_speak_with_almost_dead_rheims_complete";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID("Danielle"))));
			Preprocessor_AddQuestData("pronoun3", XI_ConvertString(GetMyPronounPossessive(CharacterFromID("Danielle"))));
			if (Characters[GetCharacterIndex("Danielle")].sex == "woman")
			{
				Preprocessor_AddQuestData("kid", XI_ConvertString("girl"));
			}
			else
			{
				Preprocessor_AddQuestData("kid", XI_ConvertString("lad"));
			}
			AddQuestRecord("again_find_rheims", 7);
			CloseQuestHeader("again_find_rheims");
			Preprocessor_Remove("pronoun3");
			Preprocessor_Remove("kid");
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("Danielle");

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			SetQuestHeader("search_danielle");
			AddQuestrecord("search_danielle", 1);
			Preprocessor_Remove("Danielle");
			locCameraFollow();
			restorepassengers(pchar.id);

			RemoveCharacterEquip(characterFromID("danielle"), BLADE_ITEM_TYPE);
			GiveItem2Character(characterFromID("danielle"), "blade6");
			EquipCharacterByItem(characterFromID("danielle"), "blade6");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 1000); }
			else { AddPartyExp(pchar, 10000); }
		break;

		case "exit_after_speak_with_rheims_2":
			LAi_SetPlayerType(characterFromID("blaze"));
		break;

		case "bad_swimming_in_oxbay":
			LAi_SetActorType(characterFromID("Anacleto Rui Sa Pinto"));
			ChangeCharacterAddress(characterFromID("Anacleto Rui Sa Pinto"), "ship_deck", "goto2");
			ChangeCharacterAddress(characterFromID("pirate for abordage 01"), "ship_deck", "goto1");
			ChangeCharacterAddress(characterFromID("pirate for abordage 02"), "ship_deck", "goto3");
			ChangeCharacterAddress(characterFromID("pirate for abordage 03"), "ship_deck", "goto4");
			DoQuestReloadToLocation("ship_deck", "reload", "locator2", "bad_swimming_in_oxbay_complete");
		break;

		case "bad_swimming_in_oxbay_complete":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Anacleto Rui Sa Pinto"));
			LAi_ActorFollow(pchar, characterFromID("Anacleto Rui Sa Pinto"), "", 2.0);
			LAi_ActorFollow(characterFromID("Anacleto Rui Sa Pinto"), pchar, "bad_swimming_in_oxbay_complete_1", 2.0);
		break

		case "bad_swimming_in_oxbay_complete_1":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Anacleto Rui Sa Pinto"));
// KK -->
			if (pchar.quest.main_line == "Just_before_escape_from_Anacleto_ship")
				LAi_ActorDialog(characterFromID("Anacleto Rui Sa Pinto"), pchar, "bad_swimming_in_oxbay_complete_2", 3.0, 0);
			else
				LAi_ActorDialog(characterFromID("Anacleto Rui Sa Pinto"), pchar, "player_back", 3.0, 0);
// <-- KK
		break;

// KK -->
		case "bad_swimming_in_oxbay_complete_2":
			LAi_fade("", "bad_swimming_in_oxbay_complete_3");
		break;

		case "bad_swimming_in_oxbay_complete_3":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Anacleto Rui Sa Pinto"));
			LAi_ActorDialog(characterFromID("Anacleto Rui Sa Pinto"), pchar, "player_back", 3.0, 0);
		break;
// <-- KK

		case "swimming_to_lighthouse":
			ChangeCharacterAddressGroup(characterFromID("researcher"), "Oxbay_Lighthouse", "officers", "reload3_1");
			DoQuestReloadToLocation("Oxbay_lighthouse", "reload", "reload3", "to_lighthouse_see_tartane_complete");
// KK			worldMap.playerShipX = 176.27;
// KK			worldMap.playerShipZ = 35.34;
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Oxbay.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Oxbay.position.rz);
			pchar.location.from_sea = "Oxbay_lighthouse";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			pchar.ship.type = "Tartane1" // PS - SHIP_TARTANE;
// KK -->
			pchar.ship.name = characters[GetCharacterIndex("researcher")].ship.name;
			SetBaseShipData(pchar);
			pchar.ship.stats.nation = ENGLAND;
			SetCrewQuantity(pchar, 3);
			SetCharacterGoods(pchar, GOOD_BALLS, 0);
			SetCharacterGoods(pchar, GOOD_GRAPES, 0);
			SetCharacterGoods(pchar, GOOD_KNIPPELS, 0);
			AddCharacterGoods(pchar, GOOD_WHEAT, 2);
			AddCharacterGoods(pchar, GOOD_RUM, 2);
// <-- KK
			setCharacterShipLocation(characterFromID("researcher"), "none");
			setCharacterShipLocation(pchar, "Oxbay_Lighthouse");
		break;

		case "without_ship_complete":
			LAi_fade("", "to_lighthouse_see_tartane_complete_3");
		break;

		case "to_lighthouse_see_tartane_complete":
			pchar.quest.main_line = "without_ship";
			PlaceCharacter(characterfromID("researcher"), "goto");
			LAi_SetActorType(characterFromID("researcher"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("researcher"), "", 3.0);
			LAi_ActorFollow(characterFromID("researcher"), pchar, "to_lighthouse_see_tartane_complete_2", 3.0);
		break;

		case "to_lighthouse_see_tartane_complete_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "player_back", 1.0, 1.0);
		break;

		case "to_lighthouse_see_tartane_complete_3":
			pchar.quest.main_line = "see_yaht";
			LAi_SetActorType(characterFromID("researcher"));
			LAi_ActorDialog(characterFromID("researcher"), pchar, "", 5.0, 1.0);
			bQuestDisableMapEnter = false;
		break;

		case "OnUse_Idol": //используем статую идольскую.
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("standard\idol", 100, "OnUse_Idol_2");
		break;

		case "OnUse_Idol_2":
			PostEvent("DoInfoShower",100,"s","");
			deleteAttribute(&Locations[FindLocation("Labirint_3")], "models.always.koster");
			DoQuestReloadToLocation("Labirint_3", "item", "button01", "recharge_portals");
			Locations[FindLocation("Labirint_3")].reload.l28.disable = false;
		break;

		case "recharge_portals":
			pchar.quest.first_portal.win_condition.l1 = "locator";
			pchar.quest.first_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.first_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.first_portal.win_condition.l1.locator = "teleport1";
			pchar.quest.first_portal.win_condition = "first_portal";

			pchar.quest.second_portal.win_condition.l1 = "locator";
			pchar.quest.second_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.second_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.second_portal.win_condition.l1.locator = "teleport2";
			pchar.quest.second_portal.win_condition = "second_portal";

			pchar.quest.third_portal.win_condition.l1 = "locator";
			pchar.quest.third_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.third_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.third_portal.win_condition.l1.locator = "teleport3";
			pchar.quest.third_portal.win_condition = "third_portal";

			pchar.quest.fourth_portal.win_condition.l1 = "locator";
			pchar.quest.fourth_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.fourth_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.fourth_portal.win_condition.l1.locator = "teleport4";
			pchar.quest.fourth_portal.win_condition = "fourth_portal";

			pchar.quest.fifth_portal.win_condition.l1 = "locator";
			pchar.quest.fifth_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.fifth_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.fifth_portal.win_condition.l1.locator = "teleport5";
			pchar.quest.fifth_portal.win_condition = "fifth_portal";

			pchar.quest.monster_portal.win_condition.l1 = "locator";
			pchar.quest.monster_portal.win_condition.l1.location = "Treasure_alcove";
			pchar.quest.monster_portal.win_condition.l1.locator_group = "teleport";
			pchar.quest.monster_portal.win_condition.l1.locator = "teleport0";
			pchar.quest.monster_portal.win_condition = "monster_portal";
		break;

		case "empting_portals":
			pchar.quest.first_portal.over = "yes";
			pchar.quest.second_portal.over = "yes";
			pchar.quest.third_portal.over = "yes";
			pchar.quest.fourth_portal.over = "yes";
			pchar.quest.fifth_portal.over = "yes";
			pchar.quest.monster_portal.over = "yes";
		break;

		case "first_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_1_2", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;

		case "second_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_2_1", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;

		case "third_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_3_4", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;

		case "fourth_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_4_3", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;

		case "fifth_portal":
			LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("teleport_5_treasure", "");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
		break;

		case "teleport_1_2":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport2_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport2_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport2");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "teleport_2_1":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport1_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport1_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport1");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "teleport_3_4":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport4_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport4_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport4");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "teleport_4_3":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport3_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport3_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport3");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "teleport_5_treasure":
			ChangeCharacterAddress(characterFromID("danielle"), "Treasure_alcove", "teleport6_1");
			ChangeCharacterAddress(characterFromID("researcher"), "Treasure_alcove", "teleport6_2");
			ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport6");
			//LAi_QuestDelay("recharge_portals", 1.0);
		break;

		case "monster_portal":
			//LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("", "monster_generate_in_alcove");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "monster_generate_in_alcove":
			//ChangeCharacterAddressGroup(pchar, "Treasure_alcove", "teleport", "teleport0");

			LAi_group_SetLookRadius(LAi_monsters_group, 30.0);
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "mummy", "goto", "monster1");
			LAi_group_MoveCharacter(sld, LAi_monsters_group);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "mummy", "goto", "monster2");
			LAi_group_MoveCharacter(sld, LAi_monsters_group);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "mummy", "goto", "monster3");
			//LAi_SetMonkeyType(sld);
			LAi_group_MoveCharacter(sld, LAi_monsters_group);
			LAi_group_FightGroups(LAi_monsters_group, LAI_GROUP_PLAYER, true);
		break;

		case "alistar_garcilaso_money":
			AddMoneyToCharacter(pchar, -10000);
			GiveItem2Character(pchar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 13);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 4000); }
			else { AddPartyExp(pchar, 4000); }
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "alistar_garcilaso_money_2":
			AddMoneyToCharacter(pchar, -8000);
			GiveItem2Character(pchar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 13);
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 5000); }
			else { AddPartyExp(pchar, 5000); }
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "alistar_garcilaso_idols":
			GiveItem2Character(pchar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 14);
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle_sailor")], "none", "none");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 6000); }
			else { AddPartyExp(pchar, 6000); }
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "alistar_garcilaso_idols_2":
			GiveItem2Character(pchar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 14);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 6000); }
			else { AddPartyExp(pchar, 6000); }
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle_sailor")], "none", "none");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

// NK -->
		case "ReturnCelestin":
			changeCharacterAddress(characterFromID("Celestin Fammeree"), "Falaise_de_Fleur_location_03", "sitizen07");
		break;
// NK <--

		case "blaze_fighting_with_amiel_berangere":
			LAi_LocationFightDisable(&Locations[FindLocation("Falaise_de_fleur_tavern_upstairs")], false);
			//---Эмиль нападает на Блэйза
			LAi_SetImmortal(characterFromID("Amiel Berangere"), false);
			LAi_ActorAttack(characterFromID("Amiel Berangere"), PChar, "");
			locations[FindLocation("Falaise_De_Fleur_tavern_upstairs")].reload.l1.disable = 1;
			//----Отключается локатор выхода из комнаты
			//-------Убимраем ненужного Фауста Гаске
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "None", "");

			Pchar.quest.Story_BlazeStartsThinkAboutGramota.win_condition.l1 = "NPC_death";
			Pchar.quest.Story_BlazeStartsThinkAboutGramota.win_condition.l1.character = "Amiel Berangere";
			Pchar.quest.Story_BlazeStartsThinkAboutGramota.win_condition = "Story_BlazeStartsThinkAboutGramota";
		break;

		case "Glover_exit":
			Pchar.Quest.Story_Ask_for_Glover.over = "yes";
			ChangeCharacterAddressGroup(characterFromID("Ewan Glover"), "Redmond_tavern", "reload", "reload1");
			LAi_SetActorType(characterFromID("Ewan Glover"));
			LAi_ActorDialog(characterFromID("Ewan Glover"), pchar, "", 50, 0);
		break;

		case "CounterSpy_Talk_AfterTavern_exit":
			AddQuestRecord("Story_2ndTask",11);
			Pchar.quest.Story_LeaveOxbayWithRabelAndCounterspy.win_condition.l1 = "location";
			Pchar.quest.Story_LeaveOxbayWithRabelAndCounterspy.win_condition.l1.location = "Oxbay_port";
			Pchar.quest.Story_LeaveOxbayWithRabelAndCounterspy.win_condition = "Story_LeaveOxbayWithRabelAndCounterspy";

			/*Pchar.quest.Story_RabelGoesToPort.win_condition.l1 = "locator";
			Pchar.quest.Story_RabelGoesToPort.win_condition.l1.character = "Rabel Iverneau";
			Pchar.quest.Story_RabelGoesToPort.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Story_RabelGoesToPort.win_condition.l1.locator_group = "reload";
			Pchar.quest.Story_RabelGoesToPort.win_condition.l1.locator = "reload1";
			Pchar.quest.Story_RabelGoesToPort.win_condition = "Story_RabelGoesToPort";

			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1 = "locator";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1.character = "Counterspy";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1.location = "Oxbay_town";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1.locator_group = "reload";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition.l1.locator = "reload1";
			Pchar.quest.Story_CounterspyGoesToPort.win_condition = "Story_CounterspyGoesToPort";*/
			LAi_ActorRunToLocation(characterFromID("counterspy"), "reload", "reload1", "none", "", "", "", 45.0);
			LAi_ActorRunToLocation(characterFromID("Rabel Iverneau"), "reload", "reload1", "none", "", "", "", 45.0);

// --> GR: if you have companion ships, store and remove them, or they're likely to be sunk by the fort and blockade fleet - and anyway, how did they get to Speightstown?
			PChar.quest.counterspy_fleet.original_fleet_size = GetCompanionQuantity(PChar);
			if(GetCompanionQuantity(PChar) > 1)
			{
				for (n=1; n<COMPANION_MAX; n++)
				{
					cc = GetCompanionIndex(PChar,n);
					temp = "companion" + n;
					if (cc > 0)
					{
						PChar.quest.counterspy_fleet.(temp) = characters[cc].id;
						if (HasSubStr(PChar.quest.counterspy_fleet.(temp), "Enc_Officer")) LAi_StoreFantom(CharacterFromId(PChar.quest.counterspy_fleet.(temp))); // Prevent character from being overwritten by another "Enc_Officer"
						RemoveCharacterCompanion(PChar, characters[cc]);
					}
					else PChar.quest.counterspy_fleet.(temp) = "*NULL*";
				}
			}
// <-- GR
			ExchangeCharacterShip(characterFromID("Rabel Iverneau"), Pchar);
			ExchangeCharacterShip(characterFromID("Rabel Iverneau"), characterFromID("Ship Storage"));
			SetCharacterShipLocation(Pchar, "Oxbay_port");
			//LAi_ActorRunToLocator(characterFromID("Rabel Iverneau"), "reload", "reload1", "Story_RabelGoesToPort", 20.0.0);
		break;

		case "Counterspy_Exit_fight":
			//----------Появление солдат в таверне
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, "FRANCE_SOLDIERS", LAI_GROUP_NEUTRAL);
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_01"), "Oxbay_Tavern", "Reload", "Reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_02"), "Oxbay_Tavern", "Reload", "Reload1");
			ChangeCharacterAddressGroup(characterFromID("Fra_arrester_03"), "Oxbay_Tavern", "Reload", "Reload1");

			LAi_SetActorType(characterFromID("Fra_arrester_01"));
			LAi_SetActorType(characterFromID("Fra_arrester_02"));
			LAi_SetActorType(characterFromID("Fra_arrester_03"));

			LAi_ActorFollow(characterFromID("Fra_arrester_02"), characterFromID("Fra_arrester_01"), "", 15.0);
			LAi_ActorFollow(characterFromID("Fra_arrester_03"), characterFromID("Fra_arrester_01"), "", 15.0);
			LAi_ActorDialog(characterFromID("Fra_arrester_01"), pchar, "", 10.0, 1.0);
			LAi_Fade("Counterspy_Exit_fight_2", "");
		break;

		case "Counterspy_Exit_fight_2":
			PlaceCharacter(characterFromID("counterspy"), "goto");
			LAi_SetOfficerType(characterFromID("counterspy"));
			LAi_SetImmortal(characterFromID("counterspy"), true);
		break;

		case "Counterspy_After_Fight_Exit":
			//-------------Заводится квест на попадание в верфь Оксбэя
			Pchar.quest.Story_Goto_Oxbay_shipyard_with_Counterspy.win_condition.l1 = "location";
			Pchar.quest.Story_Goto_Oxbay_shipyard_with_Counterspy.win_condition.l1.location = "Oxbay_shipyard";
			Pchar.quest.Story_Goto_Oxbay_shipyard_with_Counterspy.win_condition = "Story_Goto_Oxbay_shipyard_with_Counterspy";

			//-------------Заводится квест на Попытку сбежать из города в джунгли
			Pchar.quest.Story_PlayerTriesToRunFromOxbay.win_condition.l1 = "location";
			Pchar.quest.Story_PlayerTriesToRunFromOxbay.win_condition.l1.location = "Oxbay_town_exit";
			Pchar.quest.Story_PlayerTriesToRunFromOxbay.win_condition = "Story_PlayerTriesToRunFromOxbay";

			//-----------Присоединение шпиона в качестве офицера
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("CounterSpy"));
			SetCharacterRemovable(characterFromID("Counterspy"), false);
			LAi_SetActorType(characterFromID("Oweyn McDorey"));
			ChangeCharacterAddress(characterFromID("Oweyn McDorey"), "Oxbay_Shipyard", "Goto8");
		break;

		case "CounterSpy_Ready_for_meeting_exit":
			SetCharacterRemovable(characterFromID("Counterspy"), true);
//			RemovePassenger(Pchar, characterFromID("Counterspy"));	// GR: was 'RemovePassenger(Pchar, getCharacterIndex("Counterspy"))' which is wrong.  Quest did not break because "Counterspy" has already been removed
// KK -->
			if (GetNotCaptivePassengersQuantity(pchar) > 0) {
				GiveShipCommandToOfficer(pchar.id, GetNotCaptivePassenger(pchar, GetNotCaptivePassengersQuantity(pchar) - 1));
			}
// <-- KK
			LAi_SetSitType(characterFromID("Rabel Iverneau"));
			LAi_SetImmortal(characterFromID("Rabel Iverneau"), true);
			SetCharacterShipLocation(&Characters[GetCharacterIndex("Rabel Iverneau")], "Oxbay_port");
			ChangeCharacterAddressGroup(characterfromID("Rabel Iverneau"), "Oxbay_tavern", "Sit", "Sit4");
		break;

		case "counterspy_Officer_money_exit":
			LAi_Fade("counterspy_Officer_money_exit_2", "Story_WaitingForEveningInTheShipyard");
		break;

		case "counterspy_Officer_money_exit_2":
			SetCurrentTime(22, 0);
			//WaitDate("",0,0,0,0,1);
			LAi_SetSitType(characterfromID("Oweyn McDorey"));
			ChangeCharacterAddressGroup(characterFromID("Oweyn McDorey"), "Oxbay_shipyard", "Sit", "Sit_1");
		break;

		case "arrest_in_tavern_for_fra_occupants":
			LAi_LocationFightDisable(&Locations[FindLocation("Oxbay_tavern")], false);
			LAi_SetWarriorType(characterFromID("Fra_arrester_01"));
			LAi_SetWarriorType(characterFromID("Fra_arrester_02"));
			LAi_SetWarriorType(characterFromID("Fra_arrester_03"));
			LAi_group_MoveCharacter(characterFromID("Fra_arrester_01"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Fra_arrester_02"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Fra_arrester_03"), "FRANCE_SOLDIERS");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("FRANCE_SOLDIERS", "Story_KillFrenchArresters");
			LAi_SetImmortal(characterFromID("Counterspy"), true);
		break;

		case "vincent_exit_from_tavern":
			LAi_ActorGoToLocator(characterFromID("Vincent bethune"), "reload", "reload1", "vincent_away_from_tavern_complete", 90.0);
			pchar.quest.main_line = "vincent_away_from_douwesen_tavern";
		break;

		case "turpin_cabanel_story_exit":
//boal -->
			AddQuestRecord("Story_1stTaskReceived", 11);
//boal <--
			pchar.quest.turpin_cabanel_story_exit_2.win_condition.l1 = "location";
			pchar.quest.turpin_cabanel_story_exit_2.win_condition.l1.location = "Falaise_de_fleur_port_01";
			pchar.quest.turpin_cabanel_story_exit_2.win_condition = "turpin_cabanel_story_exit_2";
		break;

		case "turpin_cabanel_story_exit_2":
			LAi_SetCitizenType(characterFromID("Tancrede Rimbaud"));
			LAi_type_actor_Reset(characterFromID("Virgile Boon"));
			LAi_ActorDialog(characterFromID("Virgile Boon"), Pchar, "", 25.0, 1.0);
		break;

		case "turpin_cabanel_fight":
			LAi_group_MoveCharacter(characterFromID("Turpin Cabanel"), "FRANCE_SOLDIERS");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			if(GetRMRelation(PChar, FRANCE) > REL_WAR) SetRMRelation(PChar, FRANCE, REL_WAR); // RM
			LeaveService(PChar, FRANCE, true); // RM
			ChangeCharacterReputation(pchar, -2);
		break;

		case "researcher_I_go_to_the_right_exit":
			LAi_SetActorType(pchar);
			RemovePassenger(Pchar, characterFromID("Researcher"));
			LAi_SetActorType(characterFromID("Researcher"));
			characters[GetCharacterIndex("researcher")].location = "labirint1";
			LAi_ActorRunToLocator(characterFromID("researcher"), "goto", "goto2", "", 25.0);
			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "First time";
			LAi_ActorRunToLocator(pchar, "goto", "goto11", "Story_TimeToGoIntoCentralPassage", 15.0);
		break;

		case "researcher_split_exit":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "I'm going on left";
			LAi_ActorDialog(characterFromID("Danielle"), pchar, "", 30.0, 5);
		break;

		case "Speak_with_lighthouse_guards":
			LAi_SetActorType(characterFromID("lighthouse_officer"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("lighthouse_officer"), "", 2.0);
			LAi_ActorFollow(characterFromID("lighthouse_officer"), pchar, "Speak_with_lighthouse_guards_2", 2.0);
		break;

		case "Speak_with_lighthouse_guards_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("lighthouse_officer"));
			LAi_ActorDialog(characterFromID("lighthouse_officer"), pchar, "player_back", 2.0, 1.0);
		break;

		case "researcher_captured_exit_fight":
			LAi_group_MoveCharacter(characterFromID("lighthouse_officer"), "LIGHTHOUSE_SOLDIERS");
			LAi_group_SetHearRadius("LIGHTHOUSE_SOLDIERS", 30.0);
			LAi_group_FightGroups("LIGHTHOUSE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

/*
//		Moved to "quests_side.c" by Grey Roger
		case "raoul_calmes_fight":
			LAi_SetActorType(characterFromID("raoul calmes"));
			LAi_ActorAttack(characterfromID("raoul calmes"), pchar, "");
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "letters_1";
		break;
*/

		case "rabel_yverneau_exit_run":
			LAi_QuestDelay("rabel_yverneau_exit_run_1", 1.2);
		break;

		case "rabel_yverneau_exit_run_1":
			LAi_SetImmortal(characterFromID("counterspy"), true);
			LAi_SetImmortal(characterFromID("rabel Iverneau"), true);

			AddPassenger(Pchar, characterFromID("Rabel Iverneau"), 0);
			AddPassenger(Pchar, characterFromID("Counterspy"), 0);

			Characters[getCharacterIndex("Ox_Soldier_1")].dialog.Filename = "Story_French Occupant_dialog.c"; // KK
			Characters[getCharacterIndex("Ox_Soldier_2")].dialog.Filename = "Story_French Occupant_dialog.c"; // KK

			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
			LAi_type_actor_Reset(characterFromID("counterspy"));

			LAi_ActorRunToLocation(characterFromID("counterspy"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);
			LAi_ActorRunToLocation(characterFromID("Rabel Iverneau"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);

			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_1"), "FRANCE_SOLDIERS"); // KK
			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_2"), "FRANCE_SOLDIERS"); // KK

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_QuestDelay("rabel_yverneau_exit_run_2", 7.0);
		break;

		case "rabel_yverneau_exit_run_2":
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload1"); // PB
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_1"), "FRANCE_SOLDIERS"); // KK
			LAi_group_MoveCharacter(characterFromID("Ox_Soldier_2"), "FRANCE_SOLDIERS"); // KK

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "blaze_exit_to_beltrop":
			DoQuestReloadToLocation("Smugglers_residence", "reload", "reload1", "blaze_first_speak_with_beltrop_complete");
		break;

		case "quest_pirate_01_exit_go_one":
			AddQuestRecord("blaze_to_incas_collection", 2);
			pchar.quest.main_line = "blaze_to_incas_collection_begin_5";
			pchar.quest.go_to_pirate_fort_fight.win_condition.l1 = "location";
			pchar.quest.go_to_pirate_fort_fight.win_condition.l1.location = "Douwesen_jungle_03";
			pchar.quest.go_to_pirate_fort_fight.win_condition = "go_to_pirate_fort_fight_complete";
		break;

		case "quest_pirate_01_exit_with_fight":
			LAi_ActorAttack(characterFromID("quest_pirate_01"), pchar, "");
			AddQuestRecord("blaze_to_incas_collection", 4);
		break;

		case "quest_pirate_01_exit_from_fort":
			LAi_ActorGoToLocator(characterFromID("quest_pirate_01"), "reload", "reload1", "pirate_go_to_jungle_complete", 120.0);
		break;

		case "Pieter_nolt_fight":
			LAi_group_FightGroups("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, true);
			pchar.quest.pirates_becomes_neutral.win_condition.l1 = "location";
			pchar.quest.pirates_becomes_neutral.win_condition.l1.location = "Douwesen";
			pchar.quest.pirates_becomes_neutral.win_condition = "pirates_becomes_neutral";
		break;

		case "pirates_becomes_neutral":
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		break;

		case "miner_again_kick_exit":
			LAi_SetStayType(characterFromID("leborio drago"));
			LAi_setActorType(characterFromID("Mine_soldier_01"));
			LAi_ActorDialog(characterFromID("Mine_soldier_01"), pchar, "", 3.0, 5);
		break;

		case "mine_soldier_resque_exit":
			pchar.quest.main_line = "resque_from_mine_step_one";
			LAi_SetActorType(characterFromID("Mine_soldier_01"));
			LAi_ActorGoToLocator(characterFromID("Mine_soldier_01"), "reload", "reload1", "soldier_goto_to_mine_commander", 45.0);
			pchar.quest.main_line = "soldier_to_mine_commander_resque";
		break;

		case "mine_commander_resque_exit":
			LAi_ActorGoToLocator(characterFromID("Mine_commander"), "reload", "reload1", "commendant_exit_from_mines_complete", 45.0);
			pchar.quest.main_line = "talk_with_Liborio";
		break;

		case "mine_commander_resque_denied_exit":
			LAi_ActorGoToLocator(characterFromID("Mine_commander"), "reload", "reload1", "commendant_exit_2_from_mines_complete", 45.0);

			pchar.quest.main_line = "resque_from_mines_denied";
			AddQuestRecord("search_danielle", 14);
		break;

		case "lucient_bescanceny_fight":
			LAi_setActorType(characterFromID("lucien bescanceny"));
			LAi_ActorAttack(characterfromID("lucien bescanceny"), pchar, "");
			Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro = "5";// NK thanks to Taghmon
			AddQuestRecord("Patric", 5); // NK
		break;

		case "leborio_drago_passenger_exit":
			AddPassenger(pchar, characterFromID("leborio drago"), -1);
			LAi_SetOfficerType(characterFromID("leborio drago"));

			pchar.quest.hired_leborio.win_condition.l1 = "location";
			pchar.quest.hired_leborio.win_condition.l1.location = "Oxbay";
			pchar.quest.hired_leborio.win_condition = "hired_leborio_complete";
		break;

		case "leborio_drago_fight_exit":
			LAi_ActorAttack(characterFromID("leborio drago"), pchar, "");
		break;

		case "leaving_oxbay_exit_no_run":
			Characters[getCharacterIndex("Ox_Soldier_1")].dialog.Filename = "Story_French Occupant_dialog.c"; // KK
			Characters[getCharacterIndex("Ox_Soldier_2")].dialog.Filename = "Story_French Occupant_dialog.c"; // KK

			LAi_type_actor_Reset(characterFromID("Counterspy"));
			LAi_type_actor_Reset(characterFromID("Rabel Iverneau"));
			LAi_ActorRunToLocation(characterFromID("Counterspy"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);
			LAi_ActorRunToLocation(characterFromID("Rabel Iverneau"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);

			AddPassenger(Pchar, characterFromID("Rabel Iverneau"), 0);
			AddPassenger(Pchar, characterFromID("Counterspy"), 0);
			LAi_QuestDelay("Story_CapturedByHotPursuit", 6.0);
		break;

		case "greenford_citizen_01_researcher_good_exit":
			AddQuestRecord("resque_researcher", 1);
			pchar.quest.main_line = "resque_researcher_good";
			LAi_ActorGoToLocator(characterFromID("greenford_citizen_01"), "reload", "reload1", "", 90.0);
		break;

		case "greenford_citizen_01_researcher_bad_exit":
			pchar.quest.prepare_fighting_on_deck_complete.over = "yes";
			AddQuestRecord("resque_researcher", 2);
			pchar.quest.main_line = "resque_researcher_bad";
			LAi_SetActorType(characterFromID("murderer_in_greenford_04"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("murderer_in_greenford_04"), "", 3.0);
			LAi_ActorFollow(characterFromID("murderer_in_greenford_04"), pchar, "greenford_citizen_01_researcher_bad_exit_2", 3.0);
		break;

		case "greenford_citizen_01_researcher_bad_exit_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("murderer_in_greenford_04"));
			LAi_ActorDialog(characterFromID("murderer_in_greenford_04"), pchar, "", 1.0, 1.0);
			LAi_ActorGoToLocator(characterFromID("greenford_citizen_01"), "reload", "reload1", "", 9.0);
			OfficersReaction("bad");
		break;

		case "Greenford_commander_fight_exit":
			LAi_LocationFantomsGen(&locations[FindLocation("Greenford_prison")], false);
			LAi_NoRebirthEnable(characterFromID("Greenford Prison Commendant"));
			LAi_NoRebirthEnable(characterFromID("Eng_soldier_38"));
			LAi_NoRebirthEnable(characterFromID("Eng_soldier_39"));

			iForceDetectionFalseFlag = 1; // KK

			characters[getCharacterIndex("Greenford Commander")].skill.accuracy = "2";
			characters[getCharacterIndex("Greenford Commander")].skill.cannons = "3";
			LAi_SetImmortal(characterFromID("Greenford Commander"), true);
			LAi_LocationFightDisable(&Locations[FindLocation("Greenford_prison")], false);
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Oxbay", false);
			pchar.quest.main_line = "return_idol_from_greenford_1";

			AddQuestRecord("Revenge_for_Silehard", 7);
			//выставляем англию враждебной.
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ENGLAND_SOLDIERS", "prepare_escape_from_greenford");

			Group_CreateGroup("Idol_Squadron");
			Group_AddCharacter("Idol_Squadron", "Eng Captain Idol");
			Group_SetGroupCommander("Idol_Squadron", "Eng Captain Idol");
			Group_SetTaskAttack("Idol_Squadron", PLAYER_GROUP, true);
			Group_SetAddress("Idol_Squadron", "Oxbay", "Quest_Ships","Quest_Ship_23");
			Group_LockTask("Idol_Squadron");

			pchar.quest.escape_from_greenford.win_condition.l1 = "location";
			pchar.quest.escape_from_greenford.win_condition.l1.location = "Oxbay";
			pchar.quest.escape_from_greenford.win_condition = "escape_from_greenford";

			pchar.quest.prepare_escape_from_greenford.win_condition.l1 = "ExitFromLocation";
			pchar.quest.prepare_escape_from_greenford.win_condition.l1.location = "Greenford_prison";
			pchar.quest.prepare_escape_from_greenford.win_condition = "prepare_escape_from_greenford";

			pchar.quest.return_idol_from_frigate.win_condition.l1 = "Character_Capture";
			pchar.quest.return_idol_from_frigate.win_condition.l1.character = "Eng Captain Idol";
			pchar.quest.return_idol_from_frigate.win_condition.l2 = "SeaEnter"; // to allow boarding PW
			pchar.quest.return_idol_from_frigate.win_condition = "return_idol_from_frigate_complete";
			pchar.quest.return_idol_from_frigate1.win_condition.l1 = "NPC_Death";
			pchar.quest.return_idol_from_frigate1.win_condition.l1.character = "Eng Captain Idol";
			pchar.quest.return_idol_from_frigate1.win_condition.l2 = "SeaEnter"; //to allow boarding PW
			pchar.quest.return_idol_from_frigate1.win_condition = "return_idol_from_frigate_complete";
		break;

		case "prepare_escape_from_greenford":
			PChar.vcskip = true; // PB
// KK -->
			//LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
// <-- KK
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);

			SetNextWind("SSW",rand(20) + 10);	// GR: have the wind blow the right way for escape from fort
		break;

		case "escape_from_greenford":
			DeleteAttribute(PChar, "vcskip");			// PB
			LAi_SetGuardianType(CharacterFromID("Eng_soldier_40"));	// GR: put soldiers back to normal
			LAi_SetGuardianType(CharacterFromID("Eng_soldier_41"));
			for(n= 3; n<=10; n++)
			{
				LAi_SetGuardianType(CharacterFromID("Green_soldier_"+n));
			}
		break;

		case "Gervasio_Serrao_fight_again":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_ActorAttack(characterFromID("Gervasio Serrao"), pchar, "");
			pchar.quest.killing_gervasio.win_condition.l1 = "NPC_Death";
			pchar.quest.killing_gervasio.win_condition.l1.character = "Gervasio Serrao";
			pchar.quest.killing_gervasio.win_condition = "killing_gervasio";
		break;

		case "killing_gervasio":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_FRIEND);
		break;

		case "french_patrol_fight_exit":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		break;

		case "found_blaze_exit_1":
			Characters[makeint(Pchar.Temp.Officer.idx2)].Dialog.CurrentNode = "Miracle";
			LAi_type_actor_Reset(&Characters[makeint(Pchar.Temp.Officer.idx2)]);
			LAi_ActorDialog(&Characters[makeint(Pchar.Temp.Officer.idx2)], PChar, "", 3.0, 1.0);
		break;

		case "found_blaze_exit_2":
			Characters[makeint(Pchar.Temp.Officer.idx3)].Dialog.CurrentNode = "Miracle_1";
			LAi_type_actor_Reset(&Characters[makeint(Pchar.Temp.Officer.idx3)]);
			LAi_ActorDialog(&Characters[makeint(Pchar.Temp.Officer.idx3)], PChar, "", 3.0, 1.00);
		break;

		case "found_blaze_exit_3":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			Characters[iPassenger].Dialog.CurrentNode = "Miracle_2";
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorDialog(&Characters[iPassenger], PChar, "", 3.0, 1.0);
		break;

		case "found_blaze_Exit_in_Tavern_1":
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			Characters[iPassenger].Dialog.CurrentNode = "Talk_in_tavern_1";
			LAi_ActorDialogNow(&Characters[iPassenger], PChar, "", 1.0);
		break;

		case "found_blaze_Exit_in_Tavern_2":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			Characters[iPassenger].Dialog.CurrentNode = "Talk_in_tavern_2";
			LAi_ActorDialogNow(&Characters[iPassenger], PChar, "", 1.0);
			ChangeCharacterAddressGroup(characterFromID("Danielle"), "Muelle_tavern", "Reload", "Reload2");
			LAi_SetActorType(characterFromID("danielle"));
			LAi_ActorRunToLocator(characterFromID("danielle"), "goto", "goto6", "found_blaze_Exit_Danielle", 10.0);
		break;

		case "father_bernard_church_help_bad_2":
			AddDialogExitQuest("father_bernard_church_help_bad_2");
			characters[getCharacterIndex("father bernard")].quest.church_help = "done";
			AddQuestRecord("church_help", 14);
			CloseQuestHeader("church_help");
			AddMoneyToCharacter(pchar, 2500);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 3000); }
			else { AddPartyExp(pchar, 3000); }
			ChangeCharacterAddress(characterFromID("Father Jerald"), "none", "none");
			ChangeCharacterAddress(characterFromID("Gilbert Ballester"), "Greenford_Church", "goto11");
			LAi_SetStayType(characterFromID("Gilbert Ballester"));
			TakeItemFromCharacter(pchar, "pornushka");
		break;

		case "ewan_glover_Exit_to_port_of_Redmond":
			LAi_ActorRunToLocator(characterFromID("Ewan Glover"), "reload", "reload_from_port", "", 45.0);
		break;

		case "edgar_attwood_exit_from_blaze":
			pchar.quest.main_line = "inside_redmond_prison";
			LAi_ActorGoToLocator(characterFromID("Edgar Attwood"), "goto", "goto13", "wait_for_night_in_prison_complete", 30.0);
		break;

		case "anacleto_rui_sa_pinto_bad_swimming_in_oxbay_good_2":
			AddQuestrecord("Where_are_i", 9);
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), false);
			LAi_SetActorType(characterFromID("anacleto rui sa pinto"));
			LAi_ActorAttack(characterFromID("anacleto rui sa pinto"), pchar, "");
			pchar.quest.kill_anacleto.win_condition.l1 = "NPC_death";
			pchar.quest.kill_anacleto.win_condition.l1.character = "anacleto rui sa pinto";
			pchar.quest.kill_anacleto.win_condition = "kill_anacleto_complete_2";
		break;

		case "anacleto_rui_sa_pinto_fight_exit":
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), false);
			CloseQuestHeader("Where_are_i");
			LAi_Fade("anacleto_rui_sa_pinto_fight_exit_2", "anacleto_rui_sa_pinto_fight_exit_3");
		break;

		case "anacleto_rui_sa_pinto_fight_exit_2":
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), false);
			LAi_LocationFightDisable(&locations[Findlocation("pirate_tavern")], false);
			ChangeCharacterAddress(characterFromID("anacleto rui sa pinto"), "Pirate_tavern", "goto6");
		break;

		case "anacleto_rui_sa_pinto_fight_exit_3":
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), false);
			LAi_SetActorType(characterFromID("anacleto rui sa pinto"));
			LAi_ActorAttack(characterFromID("anacleto rui sa pinto"), pchar, "");
			pchar.quest.kill_anacleto.win_condition.l1 = "NPC_death";
			pchar.quest.kill_anacleto.win_condition.l1.character = "anacleto rui sa pinto";
			pchar.quest.kill_anacleto.win_condition = "kill_anacleto_complete";
		break;

		case "anacleto_rui_sa_pinto_luck_exit":
			pchar.quest.main_line = "anacleto_luck_exit";
			ChangeCharacterAddressGroup(characterFromID("Wilfred Bythesea"), "Pirate_tavern", "reload", "reload1");
			LAi_SetActorType(characterFromID("Wilfred Bythesea"));
			LAi_ActorDialog(characterFromID("Wilfred Bythesea"), pchar, "", 5.0, 1.0);
			worldMap.playerShipX = -200.27;
			worldMap.playerShipZ = 2.34;
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Douwesen.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Douwesen.position.rz);
		break;

		case "anacleto_rui_sa_pinto_exit_captain":
			LAi_SetImmortal(characterFromID("Anacleto Rui Sa Pinto"), true);
			LAi_Fade("anacleto_rui_sa_pinto_exit_captain_1", "anacleto_rui_sa_pinto_exit_captain_2");
		break;

		case "anacleto_rui_sa_pinto_exit_captain_1":
			ChangeCharacterAddress(characterFromID("Gervasio Serrao"), "Pirate_tavern", "goto6");
			characters[GetCharacterIndex("Wilfred Bythesea")].quest.kill_ogarrio = "0";
		break;

		case "anacleto_rui_sa_pinto_exit_captain_2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetActorType(characterFromID("Gervasio Serrao"));
			LAi_ActorAttack(characterFromID("Gervasio Serrao"), pchar, "");
			LAi_SetCheckMinHP(characterFromID("Gervasio Serrao"), 15.0, true, "kill_Serrao_complete");
		break;

		case "danielle_exit_from_tavern_danielle":
			LAi_ActorRunToLocator(characterFromID("danielle"), "reload", "reload1", "danielle_escape_from_quest_redmond_tavern_complete", 10.0);
		break;

		case "antoine_lebretton_story_exit":
			LAi_ActorRunToLocator(characterFromID("antoine lebretton"), "reload", "reload1", "Story_Lebretton_leaves_upstairs", 10.0);
		break;

		case "amiel_go_away":
			LAi_SetActorType(characterFromID("Amiel Berangere"));
			LAi_ActorGoToLocation(characterFromID("Amiel Berangere"), "reload", "reload1", "none", "", "", "", 10.0);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 1500); }
			else { AddPartyExp(pchar, 1500); }
		break;

		case "danielle_sailor_statuets_exit":
			LAi_Fade("danielle_sailor_statuets_exit_2", "");
		break;

		case "danielle_sailor_statuets_exit_2":
			ChangeCharacterAddress(characterFromID("danielle_sailor"), "none", "none");
			Locations[FindLocation("Douwesen_shore_01")].reload.l1.disable = 0;
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = 0;
		break;

		case "danielle_join_to_us_when_we_are_swimm_to_douwesen_fo_search_rheims":
			pchar.quest.main_line = "blaze_goto_douwesen_with_danielle";
			pchar.quest.to_douwesen_port_search_blaze.win_condition.l1 = "location";
			pchar.quest.to_douwesen_port_search_blaze.win_condition.l1.location = "douwesen_port";
			pchar.quest.to_douwesen_port_search_blaze.win_condition = "to_douwesen_port_search_blaze_complete";

			pchar.quest.to_douwesen_shore_1_search_blaze.win_condition.l1 = "location";
			pchar.quest.to_douwesen_shore_1_search_blaze.win_condition.l1.location = "douwesen_shore_01";
			pchar.quest.to_douwesen_shore_1_search_blaze.win_condition = "to_douwesen_shore_1_search_blaze_complete";

			pchar.quest.to_douwesen_shore_2_search_blaze.win_condition.l1 = "location";
			pchar.quest.to_douwesen_shore_2_search_blaze.win_condition.l1.location = "douwesen_shore_02";
			pchar.quest.to_douwesen_shore_2_search_blaze.win_condition = "to_douwesen_shore_2_search_blaze_complete";
			SetCompanionIndex(pchar, -1, GetCharacterIndex("danielle"));
			SetCharacterRemovable(characterFromID("danielle"), false);

			pchar.quest.danielle_death.win_condition.l1 = "npc_death";
			pchar.quest.danielle_death.win_condition.l1.character = "danielle";
			pchar.quest.danielle_death.win_condition = "danielle_death";
		break;

		case "prepare_for_meet_ferro":
			AddQuestrecord("search_danielle", 2);
			pchar.quest.main_line = "search_for_Ferro_Cerezo";

			pchar.quest.kill_ferro_cerezo.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_ferro_cerezo.win_condition.l1.character = "ferro cerezo";
			pchar.quest.kill_ferro_cerezo.win_condition = "kill_ferro_cerezo_complete";

			pchar.quest.abording_ferro_cerezo.win_condition.l1 = "Character_Capture";
			pchar.quest.abording_ferro_cerezo.win_condition.l1.character = "ferro cerezo";
			pchar.quest.abording_ferro_cerezo.win_condition = "abording_ferro_cerezo_complete";

			ChangeCharacterAddressGroup(characterFromID("ferro cerezo"), "Conceicao_tavern", "sit", "sit5"); // NK: now he is ALWAYS in Conceicao
			LAi_SetImmortal(characterFromID("ferro cerezo"), true); // PB: Prevent Exploit
		break;

		case "prepare_ferro_to_Sea":
			pchar.quest.main_line = "killing_ferro_cerezo";
			pchar.quest.to_sea_for_capture_cerezo.win_condition.l1 = "location";
			if (pchar.location == "Muelle_tavern")
			{
				pchar.quest.to_sea_for_capture_cerezo.win_condition.l1.location = "IslaMuelle";
			}
			else
			{
				pchar.quest.to_sea_for_capture_cerezo.win_condition.l1.location = "Conceicao";
			}
			pchar.quest.to_sea_for_capture_cerezo.win_condition = "to_sea_for_capture_cerezo";
			AddQuestRecord("search_danielle", 6);
			// GR: Hostile to player, but neutral to fort -->
			Characters[GetCharacterIndex("ferro cerezo")].nation = PORTUGAL;	// Neutral to fort, so must be same nation
			Characters[GetCharacterIndex("ferro cerezo")].recognized = true;	// Forces hostility to player, regardless of nation relations and flags
			Characters[GetCharacterIndex("ferro cerezo")].skipRM = true;		// Avoids any consequences upon sinking/capturing
			// GR: Hostile to player, but neutral to fort <--
		break;

		case "to_sea_for_capture_cerezo":
			LAi_SetImmortal(characterFromID("ferro cerezo"), false); // GR: make him vulnerable again so you can sink him or board and kill him
			LAi_SetStayType(characterFromID("Ferro Cerezo"));
			Characters[GetCharacterIndex("Ferro Cerezo")].nosurrender = 1;		// Can surrender only after you board his ship, as surrendering at sea means you must be hostile to Portugal to capture him
			Group_AddCharacter("ferro cerezo", "ferro cerezo");
			Group_SetGroupCommander("ferro cerezo", "ferro cerezo");
			Group_SetPursuitGroup("ferro cerezo", PLAYER_GROUP);
			Group_SetTaskAttack("ferro cerezo", PLAYER_GROUP, true);
			Group_LockTask("ferro cerezo");
			Group_SetAddress("ferro cerezo", Characters[GetMainCharacterIndex()].location, "", "");
			SetCharacterRelation(GetCharacterIndex("IslaMuelle Commander"),GetCharacterIndex("Ferro cerezo"),RELATION_FRIEND);
			SetCharacterRelation(GetCharacterIndex("Conceicao Commander"),GetCharacterIndex("Ferro Cerezo"),RELATION_FRIEND);
		break;

		case "come_to_library":
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("sunrise",1,"come_to_library_2");
			WaitDate("", 0,0,1,0,0);
		break;

		case "come_to_library_2":
			PostEvent("DoInfoShower",100,"s","");
			pchar.quest.main_line = "after_library";
			pchar.quest.to_oxbay_mine_2.win_condition.l1 = "location";
			pchar.quest.to_oxbay_mine_2.win_condition.l1.location = "Oxbay_canyon";
			pchar.quest.to_oxbay_mine_2.win_condition = "to_oxbay_mine_complete";
			pchar.quest.ferro_to_conceicao.over = "yes";
			if (CheckCharacterItem(Pchar, "domingues_fucked"))
			{
				TakeItemFromCharacter(pchar, "domingues_fucked");
			}
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("search_danielle", 9);
			Preprocessor_Remove("Danielle");
		break;

		case "edgar_go_on_the_port":
			LAi_SetCitizenType(characterFromID("Edgar Attwood"));
			LAi_group_MoveCharacter(characterFromID("Edgar Attwood"), "ENGLAND_CITIZENS");
		break;

		case "Wifred_give_to_us_ship":
			characters[GetCharacterIndex("Wilfred Bythesea")].quest.kill_Ogarrio = "wait";
// KK -->
			worldMap.playerShipX = stf(worldMap.islands.Douwesen.position.rx) + 19.;
			worldMap.playerShipZ = stf(worldMap.islands.Douwesen.position.rz) + 18.;
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Douwesen.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Douwesen.position.rz);
// <-- KK
			pchar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			//pchar.ship.type = "Brig1_" + HOLLAND; // PS - SHIP_BRIG_HOLLAND;
			pchar.ship.type = "Brig1";
			pchar.ship.name = "Lucky";
			pchar.ship.stats.nation = HOLLAND;
			SetCrewQuantity(pchar, 160);
			SetBaseShipData(pchar);
			AddCharacterGoods(pchar, GOOD_BALLS, 600);
			AddCharacterGoods(pchar, GOOD_GRAPES, 300);
			AddCharacterGoods(pchar, GOOD_KNIPPELS, 470);
// KK -->
			if(!USE_REAL_CANNONS) AddCharacterGoods(pchar, GOOD_BOMBS, 300);// TIH toggle fix 7-7-06
			// crew need something to eat
			AddCharacterGoods(pchar, GOOD_WHEAT, 60);
			AddCharacterGoods(pchar, GOOD_RUM, 30);
// <-- KK

			//pchar.quest.main_line = "blaze_search_danielle_again";
			if(GetAttribute(CharacterFromID("Wilfred Bythesea"), "quest.kill_Ogarrio") == "wait")
			{
				PChar.quest.kill_Ogario.win_condition.l1 = "NPC_death";
				PChar.quest.kill_Ogario.win_condition.l1.character = "Sidonio Ogarrio";
				PChar.quest.kill_Ogario.win_condition = "kill_Ogario_complete";

				PChar.quest.kill_Ogario.fail_condition.l1 = "Timer";
				PChar.quest.kill_Ogario.fail_condition.l1.date.day = GetAddingDataDay(0, 3, 0);
				PChar.quest.kill_Ogario.fail_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
				PChar.quest.kill_Ogario.fail_condition.l1.date.year = GetAddingDataYear(0, 3, 0);
				PChar.quest.kill_Ogario.fail_condition = "kill_Ogario_timeout";

				// NK this was enabling a reload locator inside the house, not in Muelle Town 2. Fixed 05-07-19 -->
				Locations[FindLocation("Muelle_town_02")].reload.l1.name = "reload1";
				Locations[FindLocation("Muelle_town_02")].reload.l1.go = "Sidonio Ogarrio House";
				Locations[FindLocation("Muelle_town_02")].reload.l1.emerge = "reload1";
				Locations[FindLocation("Muelle_town_02")].reload.l1.autoreload = "0";
				Locations[FindLocation("Muelle_town_02")].reload.l1.label = "House of Sidonio Ogarrio."; // NK 05-07-19 add label
				Locations[FindLocation("Muelle_town_02")].reload.l1.disable = 0;
				// NK <--
			}
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Where_are_i", 7);
			Preprocessor_Remove("Danielle");
			CloseQuestHeader("Where_are_i");
			SetQuestHeader("Kill_Ogario");
			AddQuestRecord("Kill_Ogario", 1);
			bQuestDisableMapEnter = false;
			LAi_SetStayType(characterFromID("Wilfred Bythesea"));
		break;

		case "God_hit_us":
			PlayStereoSound("NATURE\thunder3.wav");
			GetCharacterPos(PChar, &locx, &locy, &locz);
			CreateParticleSystemX("blast", locx, locy, locz, locx, locy, locz,0);
			LAi_ApplyCharacterDamage(pchar, 20);
		break;

		case "Ewan_sunk_Boon":
			LAi_SetActorType(characterFromID("Amiel Berangere"));
			LAi_ActorGoToLocation(characterFromID("Amiel Berangere"), "reload", "reload1", "none", "", "", "", 10.0);

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 4500); }
			else { AddPartyExp(pchar, 4500); }
			SetCharacterShipLocation(characterFromID("Virgile boon"), "none");
			AddQuestrecord("Story_1stTaskReceived", 10);

			pchar.quest.Convoy_Virgile_Boon.over = "yes";
			pchar.quest.Convoy_Virgile_Boon2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			Pchar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			Pchar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = false;
			// TIH --> have it open up the island it locked before or open where the player currently is Oct31'06
			if (CheckAttribute(PChar, "quest.boonelockedisland"))
				{ Island_SetReloadEnableGlobal(PChar.quest.boonelockedisland, true); DeleteAttribute(PChar,"quest.boonelockedisland"); }
			else
				{ Island_SetReloadEnableGlobal(PChar.location, true); }
			//Island_SetReloadEnableGlobal(PChar.location, true);
			// TIH <--

			AddQuestRecord("Story_1stTaskReceived", 12);
			ChangeCharacterAddress(characterFromID("Faust Gasquet"), "none", "");
			ChangeCharacterAddress(characterFromID("Virgile Boon"), "none", "");
			Pchar.quest.Story_1stTaskComplete = "Complete";
			pchar.quest.story_askaboutberangere.over = "yes";
		break;

		case "leborio_hire_denied":
			LAi_Fade("", "");
			ChangeCharacterAddressGroup(characterFromID("Leborio Drago"), "Falaise_de_fleur_tavern", "sit", "sit5");
			LAi_SetSitType(characterFromID("leborio Drago"));
		break;

// --> CatalinaThePirate Fix for Danielle after final

		case "Story_Take_Clement_Home":
			if(!IsOfficer(CharacterFromID("researcher"))) PlaceCharacter(characterFromID("researcher"), "goto");
			if(!IsOfficer(CharacterFromID("danielle"))) PlaceCharacter(characterFromID("Danielle"), "goto");
			LAi_SetOfficerType(characterFromID("Danielle"));
			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "Home_again";
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Clement_home";
			LAi_SetActorType(characterFromID("Researcher"));
			LAi_ActorWaitDialog(Pchar, characterFromID("Researcher"));
			LAi_ActorDialog(characterFromID("Researcher"), Pchar, "", 8.0, 1.0);
		break;

		case "Story_Take_Clement_Home3":
			LAi_SetActorType(characterFromID("Danielle"));
			LAi_ActorWaitDialog(Pchar, characterFromID("Danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 8.0, 1.0);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Clement_home";
			RemoveOfficersIndex(pchar, GetCharacterIndex("Researcher"));
			RemovePassenger(pchar, characterFromID("Researcher"));
		break;

		case "Story_Danielle_back_to_officer":
			LAi_SetOfficerType(characterFromID("Danielle"));
		break;

		case "Story_AfterFinalOnRedmond2":
// KK -->
			Pchar.quest.Story_AfterFinalOnRedmond1.over = "yes";
			Pchar.quest.Story_AfterFinalOnRedmond2.over = "yes";
			Pchar.quest.Story_AfterFinalOnRedmond3.over = "yes";
// <-- KK
			LAi_SetActorType(characterFromID("Danielle"));
//			LAi_ActorWaitDialog(Pchar, characterFromID("Danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 5.0, 1.0);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "After_Final2";
		break;

		case "Story_Reward_For_Silehard":
			Locations[FindLocation("Redmond_town_01")].vcskip = true;
			pchar.quest.Story_Reward_for_Silehard2.win_condition.l1 = "location";
			pchar.quest.Story_Reward_for_Silehard2.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.Story_Reward_for_Silehard2.win_condition = "Story_Reward_for_Silehard2";

			Characters[GetCharacterIndex("danielle")].Dialog.CurrentNode = "Reward_for_Silehard";
			CloseQuestHeader("Into_the_temple");
		break;

		case "Story_Reward_for_Silehard2":
// KK -->
			DisableTownCapture("Oxbay", false);
			DisableTownCapture("Redmond", false)
			DisableTownCapture("Greenford", false);
			DisableTownCapture("Falaise de Fleur", false);
			DisableTownCapture("Isla Muelle", false);
			DisableTownCapture("Douwesen", false);
			DisableTownCapture("Conceicao", false);
			DisableTownCapture("Quebradas Costillas", false);
// <-- KK

			LAi_SetActorType(characterFromID("Danielle"));
			LAi_ActorWaitDialog(Pchar, characterFromID("Danielle"));
			LAi_ActorDialog(characterFromID("Danielle"), Pchar, "", 8.0, 1.0);

			DeleteAttribute(&Locations[FindLocation("Redmond_town_01")],"vcskip");
			Locations[FindLocation("Redmond_town_01")].vcskip = false;
		break;

		case "Story_Danielle_Departs_Exit":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Danielle"));
			RemovePassenger(pchar, characterFromID("Danielle"));
			LAi_ActorGoToLocation(characterFromID("Danielle"), "Redmond_town_01", "goto", "goto16", "", "", "", 25.0);
			LAi_QuestDelay("Story_Danielle_Departs_Exit2", 25.0);
		break;

		case "Story_Danielle_Departs_Exit2":
			ChangeCharacterAddress(characterFromID("Danielle"), "", "");
			characters[GetCharacterIndex("John Clifford Brin")].dialog = "John Clifford Brin.c"; // PB
		break;

		case "Story_Danielle_Departs_Exit3":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Danielle"));
			RemovePassenger(pchar, characterFromID("Danielle"));
			LAi_QuestDelay("Story_Danielle_Departs_Exit2", 25.0);
		break;

// <-- CatalinaThePirate Fix for Danielle after final

		PChar.questnotfound = true; // PB: Testing
	}
}
