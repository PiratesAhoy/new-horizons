void QuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld;
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
			Character_SetAbordageEnable(CharacterFromID("Barbossa"), false);

			LAi_SetImmortal(CharacterFromID("Barbossa"), true);
			LAi_SetCrewImmortal(CharacterFromID("Barbossa"), 2); // KK
			characters[GetCharacterindex("Barbossa")].ship.hp = 100000;

			/* ccc open Oxbay locations
			Locations[FindLocation("Labirint_3")].reload.l28.disable = true;
			Locations[FindLocation("Oxbay_canyon")].reload.l3.disable = true;

			Locations[FindLocation("Oxbay_town")].reload.l2.disable = true;

			Locations[FindLocation("Oxbay_town")].reload.l55.disable = true;
			*/

			Island_SetReloadEnableLocal("KhaelRoa", "reload_1", false);

			LAi_RemoveLoginTime(CharacterFromID("Danielle"));

// KK -->
			if (!CheckQuestAttribute("StartAdventure", "begin")) {
				PChar.quest.Story_LeavingOxbay.win_condition.l1 = "location";
				PChar.quest.Story_LeavingOxbay.win_condition.l1.location = "Oxbay";
				PChar.quest.Story_LeavingOxbay.win_condition = "Story_leavingOxbay";
			}
			DisableTownCapture("Redmond", true);
			DisableTownCapture("Oxbay", true);
// <-- KK
			// NK - LAi_SetImmortal(CharacterFromID("FalaiseDeFleur Commander"), true);

			LAi_LocationMonstersGen(&locations[FindLocation("Oxbay_town_exit")], false);

			if (CheckQuestAttribute("StartAdventure", "begin")) LAi_QuestDelay("Story_leavingOxbay", 0.0); // KK
		break;

		//Персонаж покидает Оксбэй в первый раз - включение первого сюжетного ролика
		case "Story_leavingOxbay":
		//	ChangeCharacterAddress(CharacterFromID("Guy Gilroy"), "none", ""); // NK 05-07-20 - PB: Not necessary

			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen08 = 12.0;
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l3.disable = 0; // NK
			//Установка атрибута для проверки захваченности Оксбэя
			PChar.Quest.Story_OxbayCaptured = "1";
			//Смена национальности форта Оксбэя
			// KK Characters[GetCharacterIndex("Oxbay Commander")].nation = FRANCE;
			// KK Characters[GetCharacterIndex("Oxbay Commander")].model = "Soldier_fra";
			// NK - LAi_SetImmortal(CharacterFromID("Oxbay Commander"), true);
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
			SetCrewQuantity(CharacterFromID("Remy Gatien"), makeint(GetMaxCrewQuantity(CharacterFromID("Remy Gatien"))));
			SetCharacterGoods(CharacterFromID("Remy Gatien"),GOOD_WHEAT,makeint(sti(GetCrewQuantity(CharacterFromID("Remy Gatien"))) * FOOD_PER_CREW * WHEAT_DAYS));
			SetCharacterGoods(CharacterFromID("Remy Gatien"),GOOD_RUM,makeint(GetCrewQuantity(CharacterFromID("Remy Gatien"))) * FOOD_PER_CREW * RUM_DAYS));
			SetCrewQuantity(CharacterFromID("Yves Giner"), makeint(GetMaxCrewQuantity(CharacterFromID("Yves Giner"))));
			SetCharacterGoods(CharacterFromID("Yves Giner"),GOOD_WHEAT,makeint(sti(GetCrewQuantity(CharacterFromID("Yves Giner"))) * FOOD_PER_CREW * WHEAT_DAYS));
			SetCharacterGoods(CharacterFromID("Yves Giner"),GOOD_RUM,makeint(GetCrewQuantity(CharacterFromID("Yves Giner"))) * FOOD_PER_CREW * RUM_DAYS));
			SetCrewQuantity(CharacterFromID("Begon Monchaty"), makeint(GetMaxCrewQuantity(CharacterFromID("Begon Monchaty"))));
			SetCharacterGoods(CharacterFromID("Begon Monchaty"),GOOD_WHEAT,makeint(sti(GetCrewQuantity(CharacterFromID("Begon Monchaty"))) * FOOD_PER_CREW * WHEAT_DAYS));
			SetCharacterGoods(CharacterFromID("Begon Monchaty"),GOOD_RUM,makeint(GetCrewQuantity(CharacterFromID("Begon Monchaty"))) * FOOD_PER_CREW * RUM_DAYS));
			// ADDING GOODS AND CREW TO THEIR SHIPS // changed by MAXIMUS [gunpowder mod] <-- // <-- KK

			// ADDING GUNPOWDER TO THEIR SHIPS // added by MAXIMUS [gunpowder mod] -->
			if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
				canQty = 0;
				crewQty = 0;
				canQty = GetCannonQuantity(CharacterFromID("Remy Gatien"));
				crewQty = GetCrewQuantity(CharacterFromID("Remy Gatien"));
				SetCharacterGoods(CharacterFromID("Remy Gatien"),GOOD_GUNPOWDER,makeint(canQty*5)+makeint(crewQty*3));
				canQty = GetCannonQuantity(CharacterFromID("Yves Giner"));
				crewQty = GetCrewQuantity(CharacterFromID("Yves Giner"));
				SetCharacterGoods(CharacterFromID("Yves Giner"),GOOD_GUNPOWDER,makeint(canQty*5)+makeint(crewQty*3));
				canQty = GetCannonQuantity(CharacterFromID("Begon Monchaty"));
				crewQty = GetCrewQuantity(CharacterFromID("Begon Monchaty"));
				SetCharacterGoods(CharacterFromID("Begon Monchaty"),GOOD_GUNPOWDER,makeint(canQty*5)+makeint(crewQty*3));
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
				ChangeCharacterAddress(CharacterFromID("Raoul Rheims"), "Redmond_residence", "goto1");

				//Заведение квеста на встречу с Реймсом в резиденции губернатора и уход Реймса
				PChar.quest.Story_First_Meeting_with_Rheims.win_condition.l1 = "location";
				PChar.quest.Story_First_Meeting_with_Rheims.win_condition.l1.location = "redmond_residence";
				PChar.quest.Story_First_Meeting_with_Rheims.win_condition = "Story_First_Meeting_with_Rheims";

				//заведение квеста на диалог со стражником
				if(GetServedNation() == ENGLAND || GetServedNation() == PERSONAL_NATION)
				{
					PChar.quest.first_time_to_redmond_townhall.win_condition.l1 = "locator";
					PChar.quest.first_time_to_redmond_townhall.win_condition.l1.location = "Redmond_town_01";
					PChar.quest.first_time_to_redmond_townhall.win_condition.l1.locator_group = "goto";
					PChar.quest.first_time_to_redmond_townhall.win_condition.l1.locator = "goto10";
					PChar.quest.first_time_to_redmond_townhall.win_condition = "first_time_to_redmond_townhall_complete";
				}

				Locations[FindLocation("Redmond_town_01")].locators_radius.goto.goto10 = 2.0;

				DeleteQuestHeader("Tutorial_SpyGlass");
				DeleteQuestHeader("Tutorial_Store");
				DeleteQuestHeader("Tutorial_Shipyard");
				DeleteQuestHeader("Tutorial_Tavern");

				PChar.quest.Tut_SellGoods.over = "yes";
				PChar.quest.Tut_RepairShip.over = "yes";
				PChar.quest.Tut_HireCrew.over = "yes";
			// TIH --> alternative methods for completion finished Sep3'06
				PChar.quest.Tut_BuySpyGlass.over = "yes";
				PChar.quest.Tut_BuySpyGlass3.over = "yes";
				PChar.quest.Tut_BuySpyGlass4.over = "yes";
			// TIH <--
				DeleteAttribute(PChar, "quest.tutorial.Spyglass");

//KK & TIH -->
				SetQuestHeader("Story_OxbayCaptured");
				// do enhanced flag deception and sailing method
				AddQuestRecord("Story_OxbayCaptured", 1);
				PChar.quest.Story_InvasionVideoAfterLeaveOxbay.win_condition.l1 = "MapEnter";
				PChar.quest.Story_InvasionVideoAfterLeaveOxbay.win_condition = "Story_InvasionVideoAfterLeaveOxbay";
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
			LAi_SetActorType(CharacterFromID("Eng_soldier_5"));
			characters[GetCharacterIndex("Eng_soldier_5")].dialog.currentnode = "who_you_blaze";
			LAi_ActorDialogNow(CharacterFromID("Eng_soldier_5"), PChar, "first_time_to_redmond_townhall_complete_2", -1);
		break;

		case "first_time_to_redmond_townhall_complete_2":
			LAi_SetGuardianType(CharacterFromID("Eng_soldier_5"));
			LAi_group_MoveCharacter(CharacterFromID("Eng_soldier_5"), "ENGLAND_SOLDIERS");
		break;

		//При заходе игрока в резиденцию Редмонда Реймс покидает ее
		case "Story_First_Meeting_with_Rheims":
			PChar.quest.first_time_to_redmond_townhall.over = "yes";
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Raoul Rheims"));
			//Выставление Реймсу нужной ноды
			Characters[GetCharacterIndex("Raoul Rheims")].Dialog.CurrentNode = "First_meeting";
			LAi_ActorFollow(PChar, CharacterFromID("Raoul Rheims"), "", 1.0);
			LAi_ActorFollow(CharacterFromID("Raoul Rheims"), PChar, "Story_First_Meeting_with_Rheims_2", 1.0);
		break;

		case "Story_First_Meeting_with_Rheims_2":
			//----------------Реймс подходит и просит его пропустить!
			LAi_ActorWaitDialog(PChar, CharacterFromID("Raoul Rheims"));
			LAi_ActorDialog(CharacterFromID("Raoul Rheims"), PChar, "", 5.0, 0);
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
			ChangeCharacterAddress(CharacterFromID("Raoul Rheims"), "None", "");
			LAi_SetPlayerType(PChar);
			PChar.quest.Silehard_meeting = "thefirst"; // SJG Jan 09
		break;

// KK -->
		case "silehard_Story_Oxbay_Captured_15":
			PChar.Quest.Story_1stTaskReceived = "1";
			CloseQuestHeader("Story_OxbayCaptured");
			SetQuestHeader("Story_1stTaskReceived");
			AddQuestRecord("Story_1stTaskReceived",1);
			PChar.quest.Story_1stTaskPayment = "10000";

			PChar.quest.StartAdventure = "complete";
			PChar.quest.StartAdventure.over = "yes";

			PChar.quest.Silehard_meeting = "done"; // SJG Jan 09
			SetRank(PChar, ENGLAND, GetOldRank(PChar, ENGLAND)); // PB: To prevent gameplay issues

			PChar.quest.silehard_Story_Oxbay_Captured_15_afterExit.win_condition.l1 = "ExitFromLocation";
			PChar.quest.silehard_Story_Oxbay_Captured_15_afterExit.win_condition.l1.location = "Redmond_Residence";
			PChar.quest.silehard_Story_Oxbay_Captured_15_afterExit.win_condition = "silehard_Story_Oxbay_Captured_15_afterExit";

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Sneak", 1500); }
			else { AddPartyExp(PChar, 1500); }
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
			PChar.quest.Story_FraSoldiers_attack_in_jungles.win_condition.l1 = "location";
			PChar.quest.Story_FraSoldiers_attack_in_jungles.win_condition.l1.location = "Oxbay_town_exit";
			PChar.quest.Story_FraSoldiers_attack_in_jungles.win_condition = "Story_FraSoldiers_attack_in_jungles";
			locations[FindLocation("Oxbay_town_exit")].vcskip = true;
			characters[GetCharacterIndex("Ox_Soldier_7")].Dialog.Filename = "Story_French Soldier_dialog.c";
			characters[GetCharacterIndex("Ox_Soldier_8")].Dialog.Filename = "Story_French Soldier_dialog.c";

			ChangeCharacterAddressGroup(CharacterFromID("Valentin Massoni"), "Oxbay_tavern", "Sit", "Sit5");
			Locations[FindLocation("Oxbay_town")].vcskip = true; // NK
			Locations[FindLocation("Oxbay_town_exit")].vcskip = true; // NK
			Locations[FindLocation("Oxbay_tavern")].vcskip = true; // NK
			LAi_SetSitType(CharacterFromID("Valentin Massoni"));
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Sneak", 1500); }
			else { AddPartyExp(PChar, 1500); }
		break;
// <-- KK

		case "Story_SitAndDrinkWithMassoni":
			LAi_Fade("Story_SitAndDrinkWithMassoni_2", "Story_MassoniStartTalkingInTavern");
		break;

		case "Story_SitAndDrinkWithMassoni_2":
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(PChar);
			ChangeCharacterAddressGroup(PChar, "Oxbay_tavern", "sit", "sit4");
		break

		case "Story_MassoniStartTalkingInTavern":
			SetCurrentTime(23, 0);
			LAi_NoRebirthDisable(CharacterFromID("Ox_Soldier_7")); // KK
			LAi_NoRebirthDisable(CharacterFromID("Ox_Soldier_8")); // KK
			//Уничтожаем квест на атаку солдат в джунглях
			PChar.Quest.Story_FraSoldiers_attack_in_jungles.over = "yes";

			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 1;
			LAi_ActorDialogNow(PChar, CharacterFromID("Valentin Massoni"), "", -1);
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
			LAi_SetImmortal(CharacterFromID("Ox_Soldier_5"), true); // KK
			LAi_SetImmortal(CharacterFromID("Ox_Soldier_6"), true); // KK
			LAi_SetImmortal(CharacterFromID("Valentin Massoni"), true);
			LAi_SetStayType(PChar);
			//Смена типа Валентину Массони
			LAi_SetActorType(CharacterFromID("Valentin Massoni"));

			//Перемещение Массони и Блэйза к выходу из Оксбэя
// KK -->
			ChangeCharacterAddress(CharacterFromID("Valentin Massoni"), "Oxbay_suburb", "locator11");
			DoQuestReloadToLocation("Oxbay_suburb", "goto", "locator12", "Story_Check_Blaze_And_Massoni");
// <-- KK
		break;

		case "Story_Check_Blaze_And_Massoni":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = true;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = true;

			LAi_SetActorType(PChar);
// KK -->
			LAi_SetActorType(CharacterFromID("Ox_Soldier_12"));
			LAi_ActorFollow(PChar, CharacterFromID("Ox_Soldier_12"), "Story_Check_Blaze_And_Massoni_2", 2.0);
// <-- KK
		break;

		case "Story_Check_Blaze_And_Massoni_2":
			LAi_type_actor_Reset(PChar);
// KK -->
			LAi_ActorWaitDialog(PChar, CharacterFromID("Ox_Soldier_12"));
			LAi_ActorDialog(CharacterFromID("Ox_Soldier_12"), PChar, "massoni_answer_to_soldier", 3.0, 0);
// <-- KK
		break;

		case "massoni_answer_to_soldier":
			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen08 = 1.0;
			characters[getCharacterIndex("Valentin Massoni")].dialog.currentnode="Talk_to_Soldiers";
			LAi_ActorWaitDialog(PChar, CharacterFromID("valentin massoni"));
			LAi_ActorDialog(CharacterFromID("valentin massoni"), PChar, "prepare_FRANCE_SOLDIERS_return_to_post", 50, 0);
		break;

		case "prepare_FRANCE_SOLDIERS_return_to_post":
			PChar.quest.massoni_died.win_condition.l1 = "NPC_Death";
			PChar.quest.massoni_died.win_condition.l1.character = "Valentin Massoni";
			PChar.quest.massoni_died.win_condition = "massoni_died";

			LAi_SetPlayerType(PChar);
			//Игрок покидает город вслед за Массони
			PChar.quest.Story_Walk_Away_with_Massoni.win_condition.l1 = "location";
			PChar.quest.Story_Walk_Away_with_Massoni.win_condition.l1.location = "Oxbay_town_exit";
			PChar.quest.Story_Walk_Away_with_Massoni.win_condition = "Story_Walk_Away_with_Massoni";

			//Массони уходит в ворота Оксбэя
// KK -->
			LAi_ActorGoToLocation(CharacterFromID("Valentin Massoni"), "reload", "Falaise_de_fleur_location_02_01", "Oxbay_town_exit", "goto", "Citizen08", "", 5.0);
			LAi_SetImmortal(CharacterFromID("Ox_Soldier_11"), false);
			LAi_SetImmortal(CharacterFromID("Ox_Soldier_12"), false);
			//Солдаты возвращаются на свои места
			LAi_ActorGoToLocator(CharacterFromID("Ox_Soldier_12"), "goto", "locator35", "Story_Fra_Occupant_01_ReturnedToPost", 5.0);
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
			sld = CharacterFromID("Ox_Soldier_7")
			sld.Dialog.Filename = "Story_Fra_Occup_common_dialog.c";
			if(GetDifficulty() < DIFFICULTY_SEADOG)
			{
				ChangeHPBonus(sld,175);
				RemoveSkillCharMod(sld, "Fencing","drunk");
				RemoveSkillCharMod(sld, "Accuracy","drunk");
				RemoveSkillCharMod(sld, "Defence","drunk");
			}
			//soldier 2
			sld = CharacterFromID("Ox_Soldier_8")
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
			LAi_ActorTurnByLocator(CharacterFromID("Ox_Soldier_12"), "goto", "locator35");
			LAi_SetGuardianType(CharacterFromID("Ox_Soldier_12"));
			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_12"), "FRANCE_SOLDIERS");
// <-- KK
		break;

		//игрок выходит в джунгли вслед за Массони
		case "Story_Walk_Away_with_Massoni":
			LAi_SetImmortal(CharacterFromID("Ox_Soldier_5"), false); // KK
			LAi_SetImmortal(CharacterFromID("Ox_Soldier_6"), false); // KK
			ChangeCharacterAddress(CharacterFromID("Valentin Massoni"), "Oxbay_town_exit", "Citizen08");

			LAi_SetImmortal(CharacterFromID("Valentin Massoni"), false);
			LAi_SetCheckMinHP(CharacterFromID("Valentin Massoni"), LAi_GetCharacterHP(CharacterFromID("Valentin Massoni"))-0.1, false, "Massoni_doomed"); // KK

			LAi_type_actor_Reset(CharacterFromID("Valentin Massoni"));

//			SafePortLeave(GetCurrentLocationNation(), false); // KK
			SafePortLeave(GetLocationNationFromID(GetCharacterShipLocation(PChar)), false); // PB

			LAi_ActorGoToLocator(CharacterFromID("Valentin Massoni"), "Goto", "citizen018", "Story_Massoni_go_walking", 50.0);
// KK -->
			LAi_SetGuardianType(CharacterFromID("Ox_Soldier_7"));
			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_7"), "FRANCE_SOLDIERS");
			LAi_SetGuardianType(CharacterFromID("Ox_Soldier_8"));
			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_8"), "FRANCE_SOLDIERS");
// <-- KK
			LAi_group_MoveCharacter(CharacterFromID("Valentin Massoni"), "FRANCE_SOLDIERS");
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

			GiveItem2Character(PChar, "Massoni_papers");
			AddQuestRecord("Story_1stTaskReceived", 13);

			PChar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1 = "ExitFromLocation";
			PChar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1.location = "Oxbay_town_exit";
			PChar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition = "Story_Massoni_order_attack_Blaze_denied";
		break;

		//Игрок и пьяный Массони идут в джунглях, и дойдя до локатора, массони начинает диалог
		case "Story_Massoni_go_walking":
			LAi_ActorDialog(CharacterFromID("Valentin Massoni"), PChar, "", 20.0, 1.0);
		break;

		case "Massony_run_to_last_locator":
			LAi_ActorGoToLocator(CharacterFromID("Valentin Massoni"), "goto", "citizen05", "Story_Massoni_found_Cheating", 20.0);
		break;

		//игрок доходит до локатора где Массони отказывается идти дальше
		case "Story_Massoni_found_Cheating":
			Characters[GetCharacterIndex("Valentin Massoni")].Dialog.CurrentNode = "Final_talk";
			PChar.quest.Story_Massoni_go_walking.over = "yes";
			LAi_ActorTurnToCharacter(CharacterFromID("Valentin Massoni"), PChar);
			Locations[FindLocation("Oxbay_town")].reload.l1.disable = 0;
			LAi_ActorDialog(CharacterFromID("Valentin Massoni"), PChar, "", 20.0, 1.0);
		break;

		case "Massoni_spared":
			Locations[FindLocation("Oxbay_town_exit")].reload.l1.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l2.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l3.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l4.disable = false;
			Locations[FindLocation("Oxbay_town_exit")].reload.l5.disable = false;
			//Массони бежит к городу
			PChar.quest.massoni_died.over = "yes";
			LAi_ActorRunToLocator(CharacterFromID("Valentin Massoni"), "reload", "reload3", "Story_Massoni_order_attack_Blaze", 30.0);
			PChar.quest.Story_1stTaskComplete = 1;
			ChangeCharacterAddress(CharacterFromID("Faust Gasquet"), "Falaise_de_fleur_port_01", "goto13");
			SetCharacterShipLocation(CharacterFromID("Virgile boon"), "Falaise_de_Fleur_port_01");
			//Квест на появление Блэйза на Фале де Флер
			PChar.quest.Story_Appear_on_Falaise.win_condition.l1 = "location";
			PChar.quest.Story_Appear_on_Falaise.win_condition.l1.location = "Falaise_de_Fleur_port_01";
			PChar.quest.Story_Appear_on_Falaise.win_condition = "Story_Appear_on_Falaise";

			PChar.quest.Story_Appear_on_Falaise_shore.win_condition.l1 = "location";
			PChar.quest.Story_Appear_on_Falaise_shore.win_condition.l1.location = "Falaise_de_fleur_shore";
			PChar.quest.Story_Appear_on_Falaise_shore.win_condition = "Story_Appear_on_Falaise_shore";
			//Квест на потопление барка "Ойсу"
		// TIH --> alternate method - allows capturing him from boarding, or killing him, to win the quest
			PChar.quest.Story_Sink_Oiseau1.win_condition.l1 = "Ship_HP";
			PChar.quest.Story_Sink_Oiseau1.win_condition.l1.character = "Virgile Boon";
			PChar.quest.Story_Sink_Oiseau1.win_condition.l1.quantity = 1;
			PChar.quest.Story_Sink_Oiseau1.win_condition.l1.operation = "<";
			PChar.quest.Story_Sink_Oiseau1.win_condition = "Story_Sink_Oiseau";// TIH can use same named end action Oct31'06
			PChar.quest.Story_Sink_Oiseau2.win_condition.l1 = "NPC_Death";
			PChar.quest.Story_Sink_Oiseau2.win_condition.l1.character = "Virgile Boon";
			PChar.quest.Story_Sink_Oiseau2.win_condition = "Story_Sink_Oiseau";// TIH can use same named end action Oct31'06
		// TIH <--
			PChar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1 = "ExitFromLocation";
			PChar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1.location = "Oxbay_town_exit";
			PChar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition = "Story_Massoni_order_attack_Blaze_denied";
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

			LAi_RemoveCheckMinHP(CharacterFromID("Valentin Massoni"));
			LAi_type_actor_Reset(CharacterFromID("Valentin Massoni"));

			if (CheckCharacterItem(PChar,"Massoni_papers"))
			{
				PChar.quest.massoni_died.over = "yes";
			}

			LAi_ActorAttack(CharacterFromID("Valentin Massoni"), PChar, "");
			PChar.quest.Story_1stTaskComplete = "1";

			ChangeCharacterAddress(CharacterFromID("Faust Gasquet"), "Falaise_de_fleur_port_01", "goto1");
			SetCharacterShipLocation(CharacterFromID("Virgile boon"), "Falaise_de_Fleur_port_01");
			//Квест на появление Блэйза на Фале де Флер
			PChar.quest.Story_Appear_on_Falaise.win_condition.l1 = "location";
			PChar.quest.Story_Appear_on_Falaise.win_condition.l1.location = "Falaise_de_Fleur_port_01";
			PChar.quest.Story_Appear_on_Falaise.win_condition = "Story_Appear_on_Falaise";

			PChar.quest.Story_Appear_on_Falaise_shore.win_condition.l1 = "location";
			PChar.quest.Story_Appear_on_Falaise_shore.win_condition.l1.location = "Falaise_de_fleur_shore";
			PChar.quest.Story_Appear_on_Falaise_shore.win_condition = "Story_Appear_on_Falaise_shore";
			//Квест на потопление барка "Ойсу"
		// TIH --> alternate method - allows capturing him from boarding, or killing him, to win the quest
			PChar.quest.Story_Sink_Oiseau1.win_condition.l1 = "Ship_HP";
			PChar.quest.Story_Sink_Oiseau1.win_condition.l1.character = "Virgile Boon";
			PChar.quest.Story_Sink_Oiseau1.win_condition.l1.quantity = 1;
			PChar.quest.Story_Sink_Oiseau1.win_condition.l1.operation = "<";
			PChar.quest.Story_Sink_Oiseau1.win_condition = "Story_Sink_Oiseau";// TIH can use same named end action Oct31'06
			PChar.quest.Story_Sink_Oiseau2.win_condition.l1 = "NPC_Death";
			PChar.quest.Story_Sink_Oiseau2.win_condition.l1.character = "Virgile Boon";
			PChar.quest.Story_Sink_Oiseau2.win_condition = "Story_Sink_Oiseau";// TIH can use same named end action Oct31'06
		// TIH <--

			PChar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1 = "ExitFromLocation";
			PChar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition.l1.location = "Oxbay_town_exit";
			PChar.quest.Story_Massoni_order_attack_Blaze_denied.win_condition = "Story_Massoni_order_attack_Blaze_denied";
		break;

		//Массони добегает до ворот и приказывает стражникам, если они еще есть, убить Блэйза
		case "Story_Massoni_order_attack_Blaze":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			ChangeCharacterAddress(CharacterFromID("Valentin Massoni"), "none", "");
		break;

		case "Story_Massoni_order_attack_Blaze_denied":
			ChangeCharacterAddress(CharacterFromID("Valentin Massoni"), "none", "");
		break;

		//Солдаты завязывают с игроком разговором, когда он подходит к Оксбэю с суши.
		case "Story_FraSoldiers_attack_in_jungles":
			LAi_SetCheckMinHP(CharacterFromID("Ox_Soldier_7"), LAi_GetCharacterHP(CharacterFromID("Ox_Soldier_7"))-1.0, false, "fight_before_enter_to_oxbay"); // KK
			LAi_SetCheckMinHP(CharacterFromID("Ox_Soldier_8"), LAi_GetCharacterHP(CharacterFromID("Ox_Soldier_8"))-1.0, false, "fight_before_enter_to_oxbay"); // KK
			PChar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1 = "locator";
			PChar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1.location = "Oxbay_town_exit";
			PChar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1.locator_group = "goto";
			PChar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition.l1.locator = "citizen08";
			PChar.quest.Story_FraSoldiers_attack_in_jungles_2.win_condition = "Story_FraSoldiers_attack_in_jungles_2";
		break;

		case "Story_FraSoldiers_attack_in_jungles_2":
// KK -->
			LAi_SetActorType(CharacterFromID("Ox_Soldier_7"));
			LAi_SetActorType(CharacterFromID("Ox_Soldier_8"));
			LAi_ActorFollow(CharacterFromID("Ox_Soldier_7"), PChar, "Story_FraSoldiers_attack_in_jungles_3", 10.0);
			LAi_ActorFollow(CharacterFromID("Ox_Soldier_8"), PChar, "", 10.0);

			LAi_NoRebirthEnable(CharacterFromID("Ox_Soldier_7"));
			LAi_NoRebirthEnable(CharacterFromID("Ox_Soldier_8"));
			if (LAi_group_GetPlayerAlarm() == 0)
			{
				LAi_SetActorType(PChar);
				LAi_ActorFollow(PChar, CharacterFromID("Ox_Soldier_8"), "", 10.0);
			}
// <-- KK
		break;

		case "Story_FraSoldiers_attack_in_jungles_3":
			LAi_ActorWaitDialog(PChar, CharacterFromID("Ox_Soldier_8")); // KK
			LAi_ActorDialog(CharacterFromID("Ox_Soldier_8"), PChar, "player_back", 1.0, 1.0); // KK
		break;

		case "fight_before_enter_to_oxbay":
			PChar.quest.Story_FraSoldiers_attack_in_jungles_2.over = "yes";
			//soldier 1
			sld = CharacterFromID("Ox_Soldier_7")
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
			sld = CharacterFromID("Ox_Soldier_8")
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
			LAi_ActorGoToLocator(CharacterFromID("Ox_Soldier_7"), "goto", "citizen09", "Fra_occupant_07_return_to_post", -1); // KK
			LAi_ActorGoToLocator(CharacterFromID("Ox_Soldier_8"), "goto", "citizen010", "Fra_occupant_08_return_to_post", -1); // KK
		break;

		case "Fra_occupant_07_return_to_post":
			LAi_SetGuardianType(CharacterFromID("Ox_Soldier_7")); // KK
			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_7"), "FRANCE_SOLDIERS"); // KK
		break;

		case "Fra_occupant_08_return_to_post":
			LAi_SetGuardianType(CharacterFromID("Ox_Soldier_8")); // KK
			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_8"), "FRANCE_SOLDIERS"); // KK
		break;

		//Блэйз в первый раз приплывает на Фале де Флер, чтобы поговорить с Беранжере
		case "Story_Appear_on_Falaise":
			DeleteAttribute(&Locations[FindLocation("Oxbay_town_exit")],"vcskip"); // PB
			PChar.quest.Story_Appear_on_Falaise_shore.over = "yes";
			LAi_group_SetHearRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);

			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen017 = 0.5;
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l3.disable = 1;
			PChar.quest.main_line = "GetAGramotaFromBerangere";
			ChangeCharacterAddress(CharacterFromID("Amiel Berangere"), "Falaise_de_fleur_tavern_upstairs", "goto4");
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Faust Gasquet"));
			LAi_ActorFollow(PChar, CharacterFromID("Faust Gasquet"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("Faust Gasquet"), PChar, "Story_Appear_on_Falaise_2", 2.0);
		break;

		case "Story_Appear_on_Falaise_2":
			LAi_ActorWaitDialog(PChar, CharacterFromID("Faust Gasquet"));
			LAi_ActorDialog(CharacterFromID("Faust Gasquet"), PChar, "return_faust_to_citizen", 2.0, 0);
			LAi_SetImmortal(CharacterFromID("Amiel Berangere"), true);
		break;

		case "Story_Appear_on_Falaise_shore":
			PChar.quest.Story_Appear_on_Falaise.over = "yes";
			LAi_group_SetHearRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_HEAR);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);

			Locations[FindLocation("Oxbay_town_exit")].locators_radius.goto.citizen017 = 0.5;
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l3.disable = 1;
			PChar.quest.main_line = "GetAGramotaFromBerangere";
			PChar.quest.Story_AskAboutBerangere = "3";
			ChangeCharacterAddress(CharacterFromID("Amiel Berangere"), "Falaise_de_fleur_tavern_upstairs", "goto4");
			LAi_SetCitizenType(CharacterFromID("Faust Gasquet"));// PW reset Faust from actor wait dialogue
			LAi_group_MoveCharacter(CharacterFromID("Faust Gasquet"), "FRANCE_CITIZENS");// PW reset Faust from actor wait dialogue

		break;

		case "return_faust_to_citizen":
			LAi_SetPlayerType(PChar);
			LAi_SetCitizenType(CharacterFromID("Faust Gasquet"));
			LAi_group_MoveCharacter(CharacterFromID("Faust Gasquet"), "FRANCE_CITIZENS");
		break;

		// TIH --> no longer need two seperate actions for the same result
		/*
		// TIH --> two different ways to end this quest Aug31'06
		case "Story_Sink_Oiseau1":
			PChar.quest.Story_Sink_Oiseau1.over = "yes";
			PChar.quest.Story_Sink_Oiseau2.over = "yes";
			//LAi_QuestDelay("Story_Sink_Oiseau", 0.0);// TIH this doesnt work while sailing
			QuestComplete("Story_Sink_Oiseau");// TIH do it direct //or: CompleteQuestName("Story_Sink_Oiseau");
		break;
		case "Story_Sink_Oiseau2":
			PChar.quest.Story_Sink_Oiseau1.over = "yes";
			PChar.quest.Story_Sink_Oiseau2.over = "yes";
			//LAi_QuestDelay("Story_Sink_Oiseau", 0.0);// TIH this doesnt work while sailing
			QuestComplete("Story_Sink_Oiseau");// TIH do it direct //or: CompleteQuestName("Story_Sink_Oiseau");
		break;
		// TIH <--
		*/
		// TIH <--
		case "Story_Sink_Oiseau":
			if(GetRMRelation(PChar, ENGLAND) < REL_AMNESTY) RMAmnesty(PChar, ENGLAND); // NK fix 05-03-26 SetRMRelation(PChar, ENGLAND, REL_AMNESTY); // RM - SetNationRelation2MainCharacter(ENGLAND, RELATION_FRIEND);
			SetCharacterShipLocation(CharacterFromID("Virgile boon"), "none");
			PChar.quest.Story_Sink_Oiseau1.over = "yes";// TIH close the alternates Oct31'06
			PChar.quest.Story_Sink_Oiseau2.over = "yes";// TIH close the alternates Oct31'06
			PChar.quest.Convoy_Virgile_Boon.over = "yes";
			PChar.quest.Convoy_Virgile_Boon2.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			PChar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = false;
			// TIH --> have it open up the island it locked before or open where the player currently is Oct31'06
			if (CheckAttribute(PChar, "quest.boonelockedisland"))
				{ Island_SetReloadEnableGlobal(PChar.quest.boonelockedisland, true); DeleteAttribute(PChar,"quest.boonelockedisland"); }
			else
				{ Island_SetReloadEnableGlobal(PChar.location, true); }
			//Island_SetReloadEnableGlobal(PChar.location, true);
			// TIH <--
			AddQuestRecord("Story_1stTaskReceived", 12);
			ChangeCharacterAddress(CharacterFromID("Faust Gasquet"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Amiel Berangere"), "none", "");
			PChar.quest.Story_1stTaskComplete = "Complete";
			if(GetRMRelation(PChar, FRANCE) > REL_WAR) SetRMRelation(PChar, FRANCE, REL_WAR); // RM
			LeaveService(PChar, FRANCE, false); // RM
			PChar.quest.story_askaboutberangere.over = "yes";
		break;

		//Блэйз приплывает с барком Ойсу на любой остров.
		case "Convoy_Virgile_Boon":
			SetCharacterRemovable(CharacterFromID("Virgile Boon"), true);
			PChar.quest.Convoy_Virgile_Boon2.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			PChar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal(PChar.location, false);
			PChar.quest.boonelockedisland = PChar.location;// TIH store what island was locked Oct31'06

			RemoveCharacterCompanion(PChar, CharacterFromID("Virgile Boon"));
			SetCharacterRemovable(CharacterFromID("Virgile Boon"), true); // NK

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
			SetCharacterRemovable(CharacterFromID("Virgile Boon"), true);
			PChar.quest.Convoy_Virgile_Boon.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			PChar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal(PChar.location, false);
			PChar.quest.boonelockedisland = PChar.location;// TIH store what island was locked Oct31'06

			RemoveCharacterCompanion(PChar, CharacterFromID("Virgile Boon"));
			SetCharacterRemovable(CharacterFromID("Virgile Boon"), true); // NK
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
			PChar.quest.main_line = "";
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Amiel Berangere"));
			LAi_ActorFollow(PChar, CharacterFromID("Amiel Berangere"), "", 1.5);
			LAi_ActorFollow(CharacterFromID("Amiel Berangere"), PChar, "Story_BerangereBeginsDialog", 1.5);
		break;

		case "Story_BerangereBeginsDialog":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Amiel Berangere"));
			LAi_ActorDialog(CharacterFromID("Amiel Berangere"), PChar, "player_back", 1.0, 1.0);
		break;

		//Игрок убивает Эмиля Беранжере
		case "Story_BlazeStartsThinkAboutGramota":
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], true);
			PChar.Dialog.CurrentNode = "Story_FindBerangereDocuments";
			LAi_QuestDelay("Story_BlazeStartsThinkAboutGramota_2", 2.0);
		break;

		case "Story_BlazeStartsThinkAboutGramota_2":
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Story_FindBerangereDocuments";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "");
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
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Sneak", 2000); }
			else { AddPartyExp(PChar, 2000); }
		break;

		case "Story_FoundGramotaAndLebrettonAppeared":
			//--------Получение предмета
			GiveItem2Character(PChar,"Story_Gramota");
			//--------Постановка Вирджила Буна в первый порт Фале де Флер
			ChangeCharacterAddress(CharacterFromID("Virgile Boon"), "Falaise_de_Fleur_port_01", "goto1");
			//-------- Появление Антуана Лебреттона
			Characters[GetCharacterIndex("antoine lebretton")].dialog.CurrentNode = "Story_Berangere_killed";
			Locations[FindLocation("Falaise_De_Fleur_tavern_upstairs")].reload.l1.disable = 0;
			ChangeCharacterAddressGroup(CharacterFromID("antoine lebretton"), "Falaise_De_Fleur_tavern_upstairs", "reload","reload1");
			LAi_SetActorType(CharacterFromID("antoine lebretton"));
			//------- Убираем ненужного Фауста Гаске
			ChangeCharacterAddress(CharacterFromID("Faust Gasquet"), "none", "");
			LAi_ActorGoToLocator(PChar, "goto", "goto3", "before_lebretton_talk_with_us_in_upstairs", 4.0);
			LAi_ActorDialog(CharacterFromID("antoine lebretton"), PChar, "", 3.0, 1.0);
		break;

		case "before_lebretton_talk_with_us_in_upstairs":
			LAi_ActorWaitDialog(PChar, CharacterFromID("Antoine lebretton"));
		break;

		case "Story_Lebretton_leaves_upstairs":
			LAi_SetPlayerType(PChar);
			//---------перегрузка Лебреттона обратно за стойку в таверне.
			ChangeCharacterAddressGroup(CharacterFromID("antoine lebretton"), "Falaise_De_Fleur_tavern", "merchant","goto1");
			//---------снимается бессмертие с Антуана Лебреттона
			LAi_SetMerchantType(CharacterFromID("antoine lebretton"));
			LAi_group_MoveCharacter(CharacterFromID("antoine lebretton"), "FRANCE_CITIZENS");
		break;

		case "Story_ReturnToFFPortToFindBoon":
			Characters[GetCharacterIndex("Tancrede Rimbaud")].dialog.filename = "Tancrede Rimbaud_dialog.c";
			LAi_SetActorType(CharacterFromID("Virgile Boon"));
			LAi_group_MoveCharacter(CharacterFromID("Virgile Boon"), "FRANCE_CITIZENS");
			LAi_SetActorType(CharacterFromID("Tancrede Rimbaud"));
			LAi_group_MoveCharacter(CharacterFromID("Tancrede Rimbaud"), "FRANCE_CITIZENS");
			LAi_ActorFollow(CharacterFromID("Virgile Boon"), CharacterFromID("Tancrede Rimbaud"), "Story_ReturnToFFPortToFindBoon_2", 10.0);
			LAi_SetCheckMinHP(CharacterFromID("Virgile Boon"), LAi_GetCharacterHP(CharacterFromID("Virgile Boon"))-1.0, false, "boon_becomes_citizen"); // KK
		break;

		case "boon_becomes_citizen":
			LAi_SetCitizenType(CharacterFromID("Virgile Boon"));
			LAi_group_MoveCharacter(CharacterFromID("Virgile Boon"), "FRANCE_CITIZENS");
		break;

		case "Story_ReturnToFFPortToFindBoon_2":
			LAi_ActorTurnToCharacter(CharacterFromID("Virgile Boon"), CharacterFromID("Tancrede Rimbaud"));
			LAi_ActorTurnToCharacter(CharacterFromID("Tancrede Rimbaud"), CharacterFromID("Virgile Boon"));
			LAi_ActorWaitDialog(CharacterFromID("Virgile Boon"), PChar);
			LAi_ActorWaitDialog(CharacterFromID("Tancrede Rimbaud"), PChar);
		break;

		case "Story_BoonStartTalkToTancredeAgain":
			LAi_ActorTurnToCharacter(CharacterFromID("Virgile Boon"), CharacterFromID("Tancrede Rimbaud"));
			LAi_ActorTurnToCharacter(CharacterFromID("Tancrede Rimbaud"), CharacterFromID("Virgile Boon"));
			LAi_ActorWaitDialog(CharacterFromID("Virgile Boon"), PChar);
			LAi_ActorWaitDialog(CharacterFromID("Tancrede Rimbaud"), PChar);
		break;

		case "Story_Blaze_and_Boon_leaving":
			characters[GetCharacterIndex("Virgile Boon")].location = "none";
			Characters[GetCharacterIndex("Virgile Boon")].nation = FRANCE; // RM
			//------------Выдача Квестов на нападение Буна на игрока
			PChar.quest.Story_Convoy_Virgile_Boon_1.win_condition.l1 = "location";
			PChar.quest.Story_Convoy_Virgile_Boon_1.win_condition.l1.location = "Oxbay";
			PChar.quest.Story_Convoy_Virgile_Boon_1.win_condition = "Convoy_Virgile_Boon";

			PChar.quest.Story_Convoy_Virgile_Boon_2.win_condition.l1 = "location";
			PChar.quest.Story_Convoy_Virgile_Boon_2.win_condition.l1.location = "Redmond";
			PChar.quest.Story_Convoy_Virgile_Boon_2.win_condition = "Convoy_Virgile_Boon";

			PChar.quest.Story_Convoy_Virgile_Boon_3.win_condition.l1 = "location";
			PChar.quest.Story_Convoy_Virgile_Boon_3.win_condition.l1.location = "IslaMuelle";
			PChar.quest.Story_Convoy_Virgile_Boon_3.win_condition = "Convoy_Virgile_Boon";

			PChar.quest.Story_Convoy_Virgile_Boon_4.win_condition.l1 = "location";
			PChar.quest.Story_Convoy_Virgile_Boon_4.win_condition.l1.location = "Conceicao";
			PChar.quest.Story_Convoy_Virgile_Boon_4.win_condition = "Convoy_Virgile_Boon";

			PChar.quest.Story_Convoy_Virgile_Boon_5.win_condition.l1 = "location";
			PChar.quest.Story_Convoy_Virgile_Boon_5.win_condition.l1.location = "Douwesen";
			PChar.quest.Story_Convoy_Virgile_Boon_5.win_condition = "Convoy_Virgile_Boon";

			PChar.quest.Story_Convoy_Virgile_Boon_6.win_condition.l1 = "location";
			PChar.quest.Story_Convoy_Virgile_Boon_6.win_condition.l1.location = "QuebradasCostillas";
			PChar.quest.Story_Convoy_Virgile_Boon_6.win_condition = "Convoy_Virgile_Boon";

			PChar.quest.Story_Convoy_Virgile_Boon_7.win_condition.l1 = "location";
			PChar.quest.Story_Convoy_Virgile_Boon_7.win_condition.l1.location = "KhaelRoa";
			PChar.quest.Story_Convoy_Virgile_Boon_7.win_condition = "Convoy_Virgile_Boon";

			PChar.quest.Story_Convoy_Virgile_Boon_8.win_condition.l1 = "location";
			PChar.quest.Story_Convoy_Virgile_Boon_8.win_condition.l1.location = "";
			PChar.quest.Story_Convoy_Virgile_Boon_8.win_condition = "Convoy_Virgile_Boon2";
			character_SetCompanionEnemyEnable(CharacterFromID("Virgile Boon"), true);

			LAi_SetCitizenType(CharacterFromID("Tancrede Rimbaud"));
			LAi_group_MoveCharacter(CharacterFromID("Tancrede Rimbaud"), "FRANCE_CITIZENS");
			LAi_RemoveCheckMinHP(CharacterFromID("Virgile Boon"));//MAXIMUS
			DeleteAttribute(CharacterFromID("Virgile Boon"), "quest.guard_protection"); // PB
		break;

		case "Story_Meeting_Ewan_Glover":
			//---------Капитан десантного шлюпа Эван Глоувер подходит к игроку знакомитьс
			LAi_SetActorType(CharacterFromID("Ewan Glover"));
			Locations[FindLocation("Greenford_port")].reload.l1.disable = 1;
			LAi_SetImmortal(CharacterFromID("Ewan Glover"), true);
			LAi_ActorDialog(CharacterFromID("Ewan Glover"), PChar, "", 3.0, 1.0);
			Locations[FindLocation("Greenford_port")].vcskip = true; // KK
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // NK
			Locations[FindLocation("Oxbay_town")].vcskip = true; // NK
		break;

		case "Ewan_Once_Again_exit_no_join":
			//---------Отправляем Глоувера к локатору
			LAi_ActorGoToLocator(CharacterFromID("Ewan Glover"), "goto", "goto2", "", -1);
		break;

		case "Ewan_exit_no_join":
			//---------Отправляем Гроувера к локатору
			LAi_ActorGoToLocator(CharacterFromID("Ewan Glover"), "reload", "reload_1_2", "Story_Glover_goes_to_tavern", -1);
		break;

		case "Ewan_Exit_need_some_walk":
			//---------Отправляем Глоувера к локатору
			LAi_ActorRunToLocator(CharacterFromID("Ewan Glover"),"Reload","reload4", "Story_Glover_to_tavern_on_Greenford", 20.0);
			PChar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.win_condition.l1 = "location";
			PChar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.win_condition.l1.location = "Greenford_tavern";
			PChar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.win_condition = "Story_Glover_to_tavern_on_Greenford";
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Are_you_ready_again";

			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1 = "location";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1.location = "Oxbay_shore_02";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2 = "Ship_location";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2.location = "Oxbay_shore_02";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition = "Story_Blaze_and_Glover_Land_troops";

			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1 = "NPC_death";
			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1.character = "Ewan Glover";
			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition = "Story_Blaze_and_Glover_Land_troops_denied";
		break;

		case "ewan_again_gain_quest_for_night":
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1 = "location";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1.location = "Oxbay_shore_02";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2 = "Ship_location";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2.location = "Oxbay_shore_02";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition = "Story_Blaze_and_Glover_Land_troops";

			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1 = "NPC_death";
			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1.character = "Ewan Glover";
			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition = "Story_Blaze_and_Glover_Land_troops_denied";
		break;

		case "Ewan_exit_business":
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 1;

			//---------Возвращаем обоим тип стоящих.
			LAi_SetCitizenType(CharacterFromID("Ewan Glover"));
			//---------Начинаем проверку на попадание игрока и Глоувера в локейшен ночной высадки
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1 = "location";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l1.location = "Oxbay_shore_02";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2 = "Ship_location";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition.l2.location = "Oxbay_shore_02";
			PChar.quest.Story_Blaze_and_Glover_Land_troops.win_condition = "Story_Blaze_and_Glover_Land_troops";

			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1 = "NPC_death";
			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition.l1.character = "Ewan Glover";
			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.win_condition = "Story_Blaze_and_Glover_Land_troops_denied";

			if (PChar.location == "Greenford_tavern")
			{
				//---------Выставляем время на вечер
				SetCurrentTime(23, 0);
				LAi_SetPlayerType(PChar);
				//---------Телепортируем Глоувера в никуда, а игрока на пристань Гринфорда
				ChangeCharacterAddress(CharacterFromID("Ewan Glover"), "none", "");

				DoReloadCharacterToLocation("Greenford_port", "Reload", "Reload4");
			}
			//Отключаем выход в карту
			//bQuestDisableMapEnter = true;
		break;

		case "Ewan_goodbye_exit":
			RemoveCharacterCompanion(PChar, CharacterFromID("Ewan Glover"));
			SetCharacterRemovable(CharacterFromID("Ewan Glover"), true); // NK
			LAi_ActorGoToLocator(CharacterFromID("Ewan Glover"), "Reload", "reload1", "Story_Glover_leaves_on_complete", 60.0);
			AddQuestRecord("Story_2ndTask", 7); // NK
			PChar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(CharacterFromID("CounterSpy"));
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
			SetCompanionIndex(PChar, -1, GetCharacterIndex("Ewan Glover"));
			SetCharacterRemovable(CharacterFromID("Ewan Glover"), false);
			//----------Выставляем квест на потопление корабля Эвана
			PChar.quest.Story_Convoy_Glover_to_Greenford.win_condition.l1 = "NPC_Death";
			PChar.quest.Story_Convoy_Glover_to_Greenford.win_condition.l1.character = "Ewan Glover";
			PChar.quest.Story_Convoy_Glover_to_Greenford.win_condition = "Story_Glover_Sunk2";
			//---------Отправляем Глоувера к локатору
			LAi_ActorRunToLocator(CharacterFromID("Ewan Glover"), "reload", "sea_1", "Story_Glover_leaves_tavern", 75.0);
			//-------перемещаем местного жителя к причалу Гринфорда
			ChangeCharacterAddress(CharacterFromID("Wilfred"), "Greenford_port", "goto20");
			//-------Заводим квест на попадание игрока в порт Гринфорда
			PChar.quest.Story_Blaze_reaches_Greenford.win_condition.l1 = "location";
			PChar.quest.Story_Blaze_reaches_Greenford.win_condition.l1.location = "Greenford_port";
			PChar.quest.Story_Blaze_reaches_Greenford.win_condition = "Story_Blaze_reaches_Greenford";

			PChar.quest.Story_Blaze_reaches_shore1.win_condition.l1 = "location";
			PChar.quest.Story_Blaze_reaches_shore1.win_condition.l1.location = "Oxbay_shore_01";
			PChar.quest.Story_Blaze_reaches_shore1.win_condition = "Story_Blaze_reaches_shore1";

			PChar.quest.Story_Blaze_reaches_shore2.win_condition.l1 = "location";
			PChar.quest.Story_Blaze_reaches_shore2.win_condition.l1.location = "Oxbay_shore_02";
			PChar.quest.Story_Blaze_reaches_shore2.win_condition = "Story_Blaze_reaches_shore1";

			PChar.quest.Story_Blaze_reaches_shore3.win_condition.l1 = "location";
			PChar.quest.Story_Blaze_reaches_shore3.win_condition.l1.location = "Oxbay_lighthouse";
			PChar.quest.Story_Blaze_reaches_shore3.win_condition = "Story_Blaze_reaches_shore1";

			PChar.quest.Story_Glover_leaves_tavern.win_condition.l1 = "location";
			PChar.quest.Story_Glover_leaves_tavern.win_condition.l1.location = "Redmond";
			PChar.quest.Story_Glover_leaves_tavern.win_condition = "Story_Glover_leaves_tavern";
		break;

		case "Story_Blaze_reaches_shore1":
			PChar.quest.Story_Blaze_reaches_shore1.over = "yes";
			PChar.quest.Story_Blaze_reaches_shore2.over = "yes";
			PChar.quest.Story_Blaze_reaches_shore3.over = "yes";

			PlaceCharacter(CharacterFromID("Ewan Glover"), "goto");

			characters[GetCharacterIndex("Ewan Glover")].dialog.currentnode = "CameToOxbay_shore";
			LAi_type_actor_Reset(CharacterFromID("Ewan Glover"));
			LAi_ActorDialog(CharacterFromID("Ewan Glover"), PChar, "", 2.0, 1.0);
		break;

		case "prepare_Story_ReloadedtoGreenfordTavernWithGlover":
			SetCurrentTime(23, 0);
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // GR
			//---------Телепортируем Глоувера и игрока в таверну Гринфорда
			ChangeCharacterAddressGroup(CharacterFromID("Ewan Glover"), "Greenford_tavern", "Sit", "Sit4");
			DoQuestReloadToLocation("Greenford_tavern", "candles", "sit3", "Story_ReloadedtoGreenfordTavernWithGlover");
		break;

		case "prepare_Story_ReloadedtoGreenfordTavernWithGlover_1":
			//---------Телепортируем Глоувера и игрока в таверну Гринфорда
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // GR
			ChangeCharacterAddressGroup(CharacterFromID("Ewan Glover"), "Greenford_tavern", "Sit", "Sit4");
			//DoQuestReloadToLocation("Greenford_tavern", "candles", "sit3", "Story_ReloadedtoGreenfordTavernWithGlover");
			LAi_Fade("prepare_Story_ReloadedtoGreenfordTavernWithGlover_2", "Story_ReloadedtoGreenfordTavernWithGlover");
		break;

		case "prepare_Story_ReloadedtoGreenfordTavernWithGlover_2":
			LAi_SetSitType(CharacterFromID("Ewan Glover"));
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(PChar);

			ChangeCharacterAddressGroup(PChar, "Greenford_tavern", "candles", "sit3");
		break;

		case "Story_Glover_Sunk2":
			SetCharacterShipLocation(CharacterFromID("Ewan Glover"), "none");
			AddQuestRecord("Story_2ndTask", 8);
			PChar.quest.Story_Glover_Sunk = true;

			Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			//bQuestDisableMapEnter = false;
			PChar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(CharacterFromID("Counterspy"));
			ChangeCharacterAddressGroup(CharacterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
			Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Failed_in_last_moment";
		break;

		case "Story_Glover_goes_to_tavern":
			//--------перемещаем Эвана Глоувера в никуда... Предположительно, он в таверне Редмонда
			ChangeCharacterAddress(CharacterFromID("Ewan Glover"), "None", "");
			PChar.Quest.Story_Ask_for_Glover = "1";
		break;

		case "Story_Glover_leaves_tavern":
			//--------перемещаем Эвана Глоувера в никуда... Предположительно, он на своем корабле
			ChangeCharacterAddressGroup(CharacterFromID("Ewan Glover"), "Greenford_port", "Goto", "goto21");
			LAi_SetImmortal(CharacterFromID("Ewan Glover"), false);
			DeleteAttribute(&Locations[FindLocation("Greenford_tavern")],"vcskip"); // NK
			DeleteAttribute(&Locations[FindLocation("Greenford_port")],"vcskip"); // KK
		break;

		case "Story_Glover_goes_to_ship":
			//--------перемещаем Эвана Глоувера в никуда... Предположительно, он на своем корабле
			ChangeCharacterAddress(CharacterFromID("Ewan Glover"), "None", "");
			LAi_SetImmortal(CharacterFromID("Ewan Glover"), false);
		break;

		case "Story_Blaze_reaches_Greenford":
			ChangeCharacterAddress(CharacterFromID("Wilfred"), "Greenford_port", "goto20");

			PChar.quest.Story_Blaze_reaches_shore1.over = "yes";
			PChar.quest.Story_Blaze_reaches_shore2.over = "yes";
			PChar.quest.Story_Blaze_reaches_shore3.over = "yes";

			Lai_SetStayType(PChar);
			//---------ставим рядом с Блэйзом Эвана Глоувера
			if (!LAi_IsDead(CharacterFromID("Ewan Glover")))
			{
				//AddQuestRecord("Story_2ndTask", 8); // NK
				Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "CameToGreenford";
				ChangeCharacterAddress(CharacterFromID("Ewan Glover"), "Greenford_port", "goto21");
				//LAi_type_actor_Reset(CharacterFromID("Ewan Glover"));
				LAi_SetActorType(CharacterFromID("Ewan Glover"));
				LAi_ActorDialog(CharacterFromID("Ewan Glover"), PChar, "Story_Blaze_reaches_Greenford_2", 2.0, 1.0);
			}
			else
			{
				LAi_QuestDelay("Story_Blaze_reaches_Greenford_2", 0.2);
			}
		break;

		case "Story_Blaze_reaches_Greenford_2":
			LAi_SetActorType(CharacterFromID("Wilfred"));
			LAi_ActorDialog(CharacterFromID("Wilfred"), PChar, "", 4.0, 1.0);
			//---------На всякий случай делаем его бессмертным
			LAi_SetImmortal(CharacterFromID("Wilfred"), true);
		break;

		case "Wilfred_exit_failed":
			//--------Отправка Уилфреда в ворота Гринфорда.
			LAi_ActorRunToLocator(CharacterFromID("Wilfred"), "Reload","reload4", "Story_Wilfred_leaves_forever", 15.0);
			LAi_SetPlayerType(PChar);
			PChar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(CharacterFromID("CounterSpy"));
			ChangeCharacterAddressGroup(CharacterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
		break;

		case "Wilfred_Exit_failed_in_last_moment":
			//--------Отправка Уилфреда к локатору релоада.
			LAi_ActorRunToLocator(CharacterFromID("Wilfred"), "Reload","reload2", "Story_Wilfred_leaves_forever", 15.0);
			LAi_SetPlayerType(PChar);
		break;

		case "Story_Wilfred_leaves_forever":
			//---------Отправляем Уилфреда в никуда, считая что он от горя сбежал домой
			ChangeCharacterAddress(CharacterFromID("Wilfred"), "None", "");
		break;

		case "Story_Convoy_Glover_to_Greenford":
			AddQuestRecord("Story_2ndTask", 4);
			//--------Зачисляем игроку проваленный квест
			PChar.quest.Story_Glover_sunk = true;
			//--------Стартуем вторую половину задания
			PChar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(CharacterFromID("CounterSpy"));
			ChangeCharacterAddressGroup(CharacterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
		break;

		case "Story_Wilfred_go_to_shore_prepare":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Sneak", 2500); }
			else { AddPartyExp(PChar, 2500); }
			//---------Установка диалога Эвану Глоуверу
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Are_you_ready";
			LAi_type_actor_Reset(CharacterFromID("Ewan Glover"));
			LAi_ActorDialog(CharacterFromID("Ewan Glover"), PChar, "player_back", 3.0, 5.0);
			//--------Запись в журнал
			AddQuestRecord("Story_2ndTask",6);
			//--------Отправка Уилфреда в ворота Гринфорда.
			LAi_ActorRunToLocator(CharacterFromID("Wilfred"), "Reload", "reload4", "Story_Wilfred_go_to_shore", 60.0);
		break;

		case "Story_Wilfred_go_to_shore":
			//---------Отправляем Уилфреда в никуда, считая что он отправился на берег встречать Блэйза
			ChangeCharacterAddress(CharacterFromID("Wilfred"), "None", "");
		break;

		case "Wilfred_exit_fight":
			LAi_ActorRunToLocator(CharacterFromID("Wilfred"), "goto", "locator8", "Story_Wilfred_scared_run_away", 40.0);
			LAi_SetPlayerType(PChar);

			LAi_group_MoveCharacter(CharacterFromID("Fra_patrolman_01"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Fra_patrolman_02"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Fra_patrolman_03"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Fra_patrolman_04"), "FRANCE_SOLDIERS");
			//--------Появление французских солдат
			ChangeCharacterAddressGroup(CharacterFromID("Fra_patrolman_01"), "Oxbay_shore_02", "reload", "reload2_back");
			ChangeCharacterAddress(CharacterFromID("Fra_patrolman_02"), "Oxbay_shore_02", "locator27");
			ChangeCharacterAddress(CharacterFromID("Fra_patrolman_03"), "Oxbay_shore_02", "locator26");
			ChangeCharacterAddress(CharacterFromID("Fra_patrolman_04"), "Oxbay_shore_02", "locator13");
			//-----------Смена типа английским солдатам
			LAi_group_MoveCharacter(CharacterFromID("Eng_land_soldier_01"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(CharacterFromID("Eng_land_soldier_02"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(CharacterFromID("Eng_land_soldier_03"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(CharacterFromID("Eng_land_soldier_04"), LAI_GROUP_PLAYER);
			//--------нападение их на группу игрока
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_SOLDIERS", "Story_kill_french_patrol");

			//--------Отправка Уилфреда к локатору, где он будет бояться.
			LAi_SetImmortal(CharacterFromID("Wilfred"), true);
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 1;
		break;

		case "Story_Glover_to_tavern_on_Greenford":
			//----------Выставляем Глоуверу сидячую позицию.
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // GR
			LAi_type_actor_Reset(CharacterFromID("Ewan Glover"));
			LAi_SetSitType(CharacterFromID("Ewan Glover"));
			//---------Перегружаем Эвана Глоувера в таверну Гринфорда, где он будет ждать игрока.
			ChangeCharacterAddressGroup(CharacterFromID("Ewan Glover"), "Greenford_tavern", "sit", "sit4");
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Are_you_ready_again";
		break;

		case "Story_ReloadedtoGreenfordTavernWithGlover":
			SetCurrentTime(23, 0);
			LAi_SetSitType(CharacterFromID("Ewan Glover"));
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(PChar);

			Locations[FindLocation("Greenford_port")].reload.l1.disable = 0;
			Characters[GetCharacterIndex("Ewan Glover")].Dialog.CurrentNode = "Talk_in_tavern";

			LAi_ActorDialogNow(PChar, CharacterFromID("Ewan Glover"), "", -1);
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
		break;

		case "Story_Blaze_and_Glover_Land_troops":
			if (GetTime() >= 23.0 || GetTime() <= 6.0)
			{
				PChar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.over = "yes";
				Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
				if (!LAi_IsDead(CharacterFromID("Ewan Glover")))
				{
					//----------Высаживаем Английских солдат вместе с игроком
					ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_01"), "Oxbay_shore_02", "locator7");
					ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_02"), "Oxbay_shore_02", "locator23");
					ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_03"), "Oxbay_shore_02", "locator24");
					ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_04"), "Oxbay_shore_02", "locator25");
					Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Warning";
				}
				//----------Появляем местного жителя.
				LAi_type_actor_Reset(CharacterFromID("Wilfred"));
				LAi_type_actor_Reset(CharacterFromID("Wilfred"));
				ChangeCharacterAddress(CharacterFromID("Wilfred"), "Oxbay_shore_02", "locator8");
				LAi_SetActorType(PChar);
				LAi_ActorFollow(PChar, CharacterFromID("Wilfred"), "", 10.0);
				LAi_ActorFollow(CharacterFromID("Wilfred"), PChar, "Story_Blaze_and_Glover_Land_troops_speak", 10.0);
			}
			else
			{
				PChar.quest.ewan_again_gain_quest_for_night.win_condition.l1 = "ExitFromLocation";
				PChar.quest.ewan_again_gain_quest_for_night.win_condition.l1.location = "Oxbay_shore_02";
				PChar.quest.ewan_again_gain_quest_for_night.win_condition = "ewan_again_gain_quest_for_night";
			}
		break;

		case "Story_Blaze_and_Glover_Land_troops_speak":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Wilfred"));
			LAi_type_actor_Reset(CharacterFromID("Wilfred"));
			LAi_ActorDialog(CharacterFromID("Wilfred"), PChar, "", 20.0, 1.0);
		break;

		case "Story_Blaze_and_Glover_Land_troops_denied":
			PChar.quest.checker_for_greenford_tavern_for_meet_with_evan_glover.over = "yes";
			SetCharacterShipLocation(CharacterFromID("Ewan Glover"), "none");
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 0;
			bQuestDisableMapEnter = false;
			AddQuestRecord("Story_2ndTask", 8);
			//--------Зачисляем игроку проваленный квест
			PChar.quest.Story_Glover_sunk = true;
			//--------Стартуем вторую половину задания
			PChar.quest.Story_2ndTask = "Second_part";
			LAi_SetSitType(CharacterFromID("Counterspy"));
			ChangeCharacterAddressGroup(CharacterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
			Characters[GetCharacterIndex("CounterSpy")].Dialog.CurrentNode = "Met_Blaze";
			Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Failed_in_last_moment";
			//LAi_ActorDialog(CharacterFromID("Wilfred"), PChar, "", 5.0, 1.0);
		break;

		case "Story_Wilfred_scared_run_away":
			LAi_group_MoveCharacter(CharacterFromID("Wilfred"), LAI_GROUP_ACTOR);
		break;

		case "Wilfred_exit_complete":
			//-----------Возвращаем игрока в таверну Гринфорда на след. день
			LAi_SetImmortal(CharacterFromID("Wilfred"), false);
			ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_01"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_02"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_03"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_04"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Wilfred"), "None", "");
			SetCharacterShipLocation(PChar, "Greenford_port");
			SetCharacterShipLocation(CharacterFromID("Ewan Glover"), "None");
			ChangeCharacterAddress(CharacterFromID("Ewan Glover"), "Greenford_Tavern", "Goto1");
			SetCurrentTime(10, 0);
			DoQuestReloadToLocation("Greenford_tavern", "Goto", "goto17", "Story_ReturnedToGreenfordTavern");
		break;

		case "Story_kill_french_patrol":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 2500);
				AddPartyExpChar(PChar, "Sneak", 25);
			}
			else { AddPartyExp(PChar, 2500); }
			LAi_ActorFollow(CharacterFromID("Wilfred"), PChar, "Story_kill_french_patrol_3", 10.0);
			LAi_QuestDelay("Story_kill_french_patrol_2", 3.0);
		break;

		case "Story_kill_french_patrol_2":
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("Wilfred"), "", 10.0);
			AddQuestRecord("Story_2ndTask", 7);
		break;

		case "Story_kill_french_patrol_3":
			LAi_ActorWaitDialog(PChar, CharacterFromID("Wilfred"));
			Characters[GetCharacterIndex("Wilfred")].Dialog.CurrentNode = "Victory";
			LAi_ActorDialog(CharacterFromID("Wilfred"), PChar, "", 10.0, 1.0);
		break;

		case "Story_ReturnedToGreenfordTavern":
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			PChar.quest.Story_Blaze_and_Glover_Land_troops.over = "yes";
			PChar.quest.Story_Blaze_and_Glover_Land_troops_denied.over = "yes";
			PChar.quest.story_glover_to_tavern_on_greenford.over = "yes";
			PChar.quest.story_convoy_glover_to_greenford.over = "yes";

			//-----------Возвращаем возможность выхода в карту
			//bQuestDisableMapEnter = false;
			//-----------Эван Глоувер начинает диалог с игроком.
			LAi_SetActorType(CharacterFromID("Ewan Glover"));
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Ewan Glover"));
			Characters[GetCharacterIndex("Ewan Glover")].dialog.CurrentNode = "GoodBye";

			ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_01"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_02"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_03"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Eng_land_soldier_04"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Wilfred"), "none", "");

			// --> Swindler 050927
			// Here's a syntax error:
			// LAi_ActorDialog(CharacterFromID("Ewan Glover"), PChar, "", 3.0.0, 1.0);
			LAi_ActorDialog(CharacterFromID("Ewan Glover"), PChar, "", 3.0, 1.0);
			// Swindler <--
			LAi_SetSitType(CharacterFromID("CounterSpy"));
			ChangeCharacterAddressGroup(CharacterFromID("CounterSpy"), "Oxbay_tavern", "Sit", "Sit6");
		break;

		case "Story_KillFrenchArresters":
			Locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			PChar.quest.Story_Blaze_reaches_Greenford.over = "yes";
			ChangeCharacterAddress(CharacterFromID("Wilfred"), "none", "");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 1500);
				AddPartyExpChar(PChar, "Sneak", 15);
			}
			else { AddPartyExp(PChar, 1500); }
			LAi_LocationFightDisable(&Locations[FindLocation("Oxbay_tavern")], true);
			ChangeCharacterAddress(CharacterFromID("Fra_arrester_01"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Fra_arrester_02"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Fra_arrester_03"), "none", "");
			LAi_SetFightMode(PChar, false);
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
			LAi_SetImmortal(CharacterFromID("Counterspy"), true);
			LAi_SetActorType(CharacterFromID("Counterspy"));
			LAi_Fade("Story_AMinuteLaterAfterKillingFrenchArresters_2", "");
		break;

		case "Story_AMinuteLaterAfterKillingFrenchArresters_2":
			LAi_SetFightMode(PChar, false);
			LAi_SetPlayerType(PChar);
// KK -->
			if(GetOfficersIndex(PChar, 1) != -1 && GetOfficersIndex(PChar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 1);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorStay(&characters[iPassenger]);
			}
			if(GetOfficersIndex(PChar, 2) != -1 && GetOfficersIndex(PChar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 2);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorStay(&characters[iPassenger]);
			}
			if(GetOfficersIndex(PChar, 3) != -1 && GetOfficersIndex(PChar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorStay(&characters[iPassenger]);
			}
		//	StoreOfficers(pchar.id);	// Leaves passengers in place, allows player to reassign officers
			StorePassengers(PChar.id);	// Removes everybody!
			ChangeCharacterAddress(CharacterFromID("Ox_soldier_3"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Ox_soldier_4"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Ox_soldier_5"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Ox_soldier_6"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Ox_patrol_3"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Ox_patrol_4"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Moses Blinman"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Lavinia Ault"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Peter Dashwood"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Flora Debney"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Oxbay_Street_merchant_2"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Kanhoji Angria"), "none", "");
// <-- KK

			ChangeCharacterAddress(CharacterFromID("Counterspy"), "Oxbay_tavern", "goto2");
			ChangeCharacterAddress(PChar, "oxbay_tavern", "goto3");
			Characters[GetCharacterIndex("Counterspy")].Dialog.CurrentNode = "After_Fight";
			LAi_ActorDialogNow(CharacterFromID("Counterspy"), PChar, "", -1);

			PChar.quest.Story_RunToTheShipyardThroughOxbay.win_condition.l1 = "location";
			PChar.quest.Story_RunToTheShipyardThroughOxbay.win_condition.l1.location = "Oxbay_town";
			PChar.quest.Story_RunToTheShipyardThroughOxbay.win_condition = "Story_RunToTheShipyardThroughOxbay";
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
			LAi_SetActorType(CharacterFromID("Counterspy"));
			LAi_ActorRunToLocator(CharacterFromID("Counterspy"), "Reload", "reload3", "Story_CounterspyWentToShipyardBeforeBlaze", 25.0);

			if(GetOfficersIndex(PChar, 1) != -1 && GetOfficersIndex(PChar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 1);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorRunToLocation(&characters[iPassenger], "reload", "reload3", "none", "", "", "", 25.0);
			}
			if(GetOfficersIndex(PChar, 2) != -1 && GetOfficersIndex(PChar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 2);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorRunToLocation(&characters[iPassenger], "reload", "reload3", "none", "", "", "", 25.0);
			}
			if(GetOfficersIndex(PChar, 3) != -1 && GetOfficersIndex(PChar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorRunToLocation(&characters[iPassenger], "reload", "reload3", "none", "", "", "", 25.0);
			}

// KK -->
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m6, "goto", "goto3"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquiPCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m3, "goto", "goto4"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquiPCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m4, "goto", "goto1"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquiPCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.0, Nations[FRANCE].fantomModel.m2, "goto", "goto2"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquiPCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "reload", "reload12"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquiPCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "reload", "reload1"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquiPCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload1"); // PB
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "bladeC6");
			EquiPCharacterByItem(sld, "bladeC6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
// <-- KK
		break;

		case "Story_CounterspyWentToShipyardBeforeBlaze":
			ChangeCharacterAddress(CharacterFromID("Counterspy"),"Oxbay_Shipyard", "goto11");
		break;

		case "Story_Goto_Oxbay_shipyard_with_Counterspy":
			if(GetOfficersIndex(PChar, 1) != -1 && GetOfficersIndex(PChar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 1);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			if(GetOfficersIndex(PChar, 2) != -1 && GetOfficersIndex(PChar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 2);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			if(GetOfficersIndex(PChar, 3) != -1 && GetOfficersIndex(PChar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 3);
				LAi_SetOfficerType(&characters[iPassenger]);
			}
			LAi_SetActorType(CharacterFromID("Counterspy"));
			LAi_type_actor_Reset(CharacterFromID("Counterspy"));
			LAi_SetImmortal(CharacterFromID("Counterspy"), true);
			LAi_SetImmortal(CharacterFromID("Oweyn McDorey"), true);
			Characters[GetCharacterIndex("Oweyn McDorey")].Dialog.CurrentNode = "Blaze and Counterspy";
			LAi_SetActorType(CharacterFromID("Oweyn MCDorey"));
			LAi_ActorDialog(CharacterFromID("Oweyn MCDorey"), PChar, "", 5.0, 0);
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("Oweyn MCDorey"), "Story_Goto_Oxbay_shipyard_with_Counterspy_2", 1.0);
		break;

		case "Story_Goto_Oxbay_shipyard_with_Counterspy_2":
			LAi_ActorWaitDialog(PChar, CharacterFromID("Oweyn MCDorey"));
		break;

		case "Blaze_and_Counterspy_exit_from_shipyard":
			RemovePassenger(PChar, CharacterFromID("Counterspy"));
			//----------------перегрузить игрока и шпиона наверх верфи
			LAi_Fade("Blaze_and_Counterspy_exit_from_shipyard_2", "Story_HiddenInShipyardWatch");
		break;

		case "Blaze_and_Counterspy_exit_from_shipyard_2":
			if(GetOfficersIndex(PChar, 1) != -1 && GetOfficersIndex(PChar, 1) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 1);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorSetSitMode(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "goto11");
			}
			if(GetOfficersIndex(PChar, 2) != -1 && GetOfficersIndex(PChar, 2) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 2);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorSetSitMode(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "goto11");
			}
			if(GetOfficersIndex(PChar, 3) != -1 && GetOfficersIndex(PChar, 3) != GetCharacterIndex("counterspy"))
			{
				iPassenger = GetOfficersIndex(PChar, 3);
				LAi_SetActorType(&characters[iPassenger]);
				LAi_ActorSetSitMode(&characters[iPassenger]);
				ChangeCharacterAddress(&characters[iPassenger], "none", "goto11");
			}

			LAi_ActorSetSitMode(PChar);
			LAi_ActorSetSitMode(CharacterFromID("CounterSpy"));

			locx = stf(loadedLocation.locators.camera.camera_2.x);
			locy = stf(loadedLocation.locators.camera.camera_2.y);
			locz = stf(loadedLocation.locators.camera.camera_2.z);
			locCameraToPos(locx, locy, locz, false);

			ChangeCharacterAddress(PChar, "Oxbay_shipyard", "goto9");
			ChangeCharacterAddress(CharacterFromID("Counterspy"), "Oxbay_Shipyard", "goto11");
		break;

		case "Story_HiddenInShipyardWatch":
			//----------------Зафиксить камеру в нужном локаторе
			LAi_QuestDelay("Story_HiddenInShipyardWatch_2", 1.0);
		break;

		case "Story_HiddenInShipyardWatch_2":
			//----------------- Явить солдат сквозь дверь.
			ChangeCharacterAddressGroup(CharacterFromID("Fra_arrester_04"),"Oxbay_Shipyard", "Reload","reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Fra_arrester_05"),"Oxbay_Shipyard", "Reload","reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Fra_arrester_06"),"Oxbay_Shipyard", "Reload","reload1");
			//----------------Начать диалог между солдатами и Оуэном
			LAi_SetActorType(CharacterFromID("Fra_arrester_04"));
			LAi_SetActorType(CharacterFromID("Fra_arrester_05"));
			LAi_SetActorType(CharacterFromID("Fra_arrester_06"));

			LAi_ActorGoToLocator(CharacterFromID("Fra_arrester_05"), "Goto", "Goto12", "", 8.4);
			LAi_ActorGoToLocator(CharacterFromID("Fra_arrester_06"), "Goto", "Goto2", "", 8.4);
			LAi_ActorWaitDialog(CharacterFromID("Oweyn McDorey"), CharacterFromID("Fra_arrester_04"));
			LAi_ActorDialog(CharacterFromID("Fra_arrester_04"), CharacterFromID("Oweyn McDorey"), "", 5.0, 5.0);

			LAi_QuestDelay("Story_BlazeHidesInShipyard_FrenchSoldiersFinishTalking", 8.5);
		break;

		case "Story_AfterHiddenInShipyardWatch":
			PChar.quest.Story_RunToTheShipyardThroughOxbay.over = "yes";
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND); // KK
			Characters[getCharacterIndex("Counterspy")].Dialog.CurrentNode = "Officer_Money";
			LAi_ActorDialog(CharacterFromID("Counterspy"), PChar, "", 5.0, 0);
		break;

		case "Story_Glover_leaves_on_complete":
			ChangeCharacterAddress(CharacterFromID("Ewan Glover"), "none", "");
			LAi_SetPlayerType(PChar);
		break;

		case "Story_BlazeHidesInShipyard_FrenchSoldiersFinishTalking":
			LAi_type_actor_Reset(CharacterFromID("Fra_arrester_04"));
			LAi_type_actor_Reset(CharacterFromID("Fra_arrester_05"));
			LAi_type_actor_Reset(CharacterFromID("Fra_arrester_06"));
			LAi_ActorGoToLocation(CharacterFromID("Fra_arrester_04"), "reload", "Reload1", "none", "Reload", "reload1", "", 5.8);
			LAi_ActorGoToLocation(CharacterFromID("Fra_arrester_05"), "reload", "Reload1", "none", "Reload", "reload1", "", 5.8);
			LAi_ActorGoToLocation(CharacterFromID("Fra_arrester_06"), "reload", "Reload1", "none", "Reload", "reload1", "", 5.8);
			LAi_QuestDelay("Story_FrenchSoldiersGoneFromShipyard", 9.5);
		break;

		case "Story_FrenchSoldiersGoneFromShipyard":
			ChangeCharacterAddressGroup(CharacterFromID("Fra_arrester_04"),"none", "Reload","reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Fra_arrester_05"),"none", "Reload","reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Fra_arrester_06"),"none", "Reload","reload1");
			LAi_SetImmortal(CharacterFromID("Oweyn McDorey"), false);
			Characters[GetCharacterIndex("Oweyn McDorey")].Dialog.CurrentNode = "Soldiers left";
			LAi_SetImmortal(CharacterFromID("Counterspy"), true);
			LAi_SetActorType(CharacterFromID("Counterspy"));
			LAi_ActorSetStayMode(CharacterFromID("CounterSpy"));

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

			ChangeCharacterAddress(CharacterFromID("Ox_soldier_3"), "Oxbay_town", "goto3");
			ChangeCharacterAddress(CharacterFromID("Ox_soldier_4"), "Oxbay_town", "goto4");
			ChangeCharacterAddress(CharacterFromID("Ox_soldier_5"), "Oxbay_town", "goto1");
			ChangeCharacterAddress(CharacterFromID("Ox_soldier_6"), "Oxbay_town", "goto2");
			ChangeCharacterAddress(CharacterFromID("Ox_patrol_3"), "Oxbay_town", "goto31");
			ChangeCharacterAddress(CharacterFromID("Ox_patrol_4"), "Oxbay_town", "goto20");
			ChangeCharacterAddress(CharacterFromID("Moses Blinman"), "Oxbay_town", "goto12");
			ChangeCharacterAddress(CharacterFromID("Lavinia Ault"), "Oxbay_town", "goto28");
			ChangeCharacterAddress(CharacterFromID("Peter Dashwood"), "Oxbay_town", "goto8");
			ChangeCharacterAddress(CharacterFromID("Flora Debney"), "Oxbay_town", "goto21");
			ChangeCharacterAddress(CharacterFromID("Oxbay_Street_merchant_2"), "Oxbay_town", "merchant2");
			ChangeCharacterAddress(CharacterFromID("Kanhoji Angria"), "Oxbay_town", "goto1");
// <-- KK

			LAi_Fade("Story_FrenchSoldiersGoneFromShipyard_2", "Story_McDoreyStartTalking");
		break;

		case "Story_FrenchSoldiersGoneFromShipyard_2":
			ChangeCharacterAddress(CharacterFromID("Oweyn MCDorey"), "Oxbay_shipyard", "goto3");
			ChangeCharacterAddress(CharacterFromID("Counterspy"), "Oxbay_shipyard", "Goto7");
			ChangeCharacterAddress(PChar, "Oxbay_shipyard", "Goto8");
			locCameraFollow();
			LAi_SetPlayerType(PChar);
		break;

		case "Story_McDoreyStartTalking":
			LAi_type_actor_Reset(CharacterFromID("Oweyn MCDorey"));
			LAi_ActorDialog(CharacterFromID("Oweyn MCDorey"), PChar, "", 2.0, 1.0);
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
			LAi_ActorDialog(CharacterFromID("Counterspy"),PChar, "", 2.0, 1.0);
		break;

// PB: Rewritten to replace ONLY if original squadron captains were killed -->
		case "Story_French_squadron_restored":
			Group_DeleteGroup("Story_French_Squadron");
			Group_CreateGroup("Story_French_Squadron");

			if (LAi_IsDead(CharacterFromID("Remy Gatien"))) {
				SetCrewQuantity(CharacterFromID("Isaac Razilly"), makeint(GetMaxCrewQuantity(CharacterFromID("Isaac Razilly"))));
				characters[GetCharacterIndex("Isaac Razilly")].Ship.crew.morale = MORALE_NORMAL/3 + rand(MORALE_NORMAL/3*2);
				Group_AddCharacter("Story_French_Squadron", "Isaac Razilly");
			}
			else
			{
				Group_AddCharacter("Story_French_Squadron", "Remy Gatien");
			}

			if (LAi_IsDead(CharacterFromID("Yves Giner"))) {
				SetCrewQuantity(CharacterFromID("Jacques Belmondo"), makeint(GetMaxCrewQuantity(CharacterFromID("Jacques Belmondo"))));
				characters[GetCharacterIndex("Jacques Belmondo")].Ship.crew.morale = MORALE_NORMAL/3 + rand(MORALE_NORMAL/3*2);
				Group_AddCharacter("Story_French_Squadron", "Jacques Belmondo");
			}
			else
			{
				Group_AddCharacter("Story_French_Squadron", "Yves Giner");
			}

			if (LAi_IsDead(CharacterFromID("Begon Monchaty"))) {
				SetCrewQuantity(CharacterFromID("Pierre Leverrier"), makeint(GetMaxCrewQuantity(CharacterFromID("Pierre Leverrier"))));
				characters[GetCharacterIndex("Pierre Leverrier")].Ship.crew.morale = MORALE_NORMAL/3 + rand(MORALE_NORMAL/3*2);
				Group_AddCharacter("Story_French_Squadron", "Pierre Leverrier");
			}
			else
			{
				Group_AddCharacter("Story_French_Squadron", "Begon Monchaty");
			}

			if (LAi_IsDead(CharacterFromID("Remy Gatien"))) {
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
			LAi_SetActorType(CharacterFromID("Rabel Iverneau"));
			LAi_SetImmortal(CharacterFromID("Rabel Iverneau"), true);
			LAi_SetImmortal(CharacterFromID("Counterspy"), true);
			Characters[GetCharacterIndex("Counterspy")].Dialog.CurrentNode = "Talk_AfterTavern";
			ChangeCharacterAddress(CharacterFromID("Rabel Iverneau"), "Oxbay_town", "goto41");
			ChangeCharacterAddress(CharacterFromID("Counterspy"), "Oxbay_town", "goto10");
			LAi_ActorWaitDialog(CharacterFromID("Counterspy"), PChar);
			DoQuestReloadToLocation("Oxbay_town", "Reload", "Reload13", "Story_BlazeAndRabelGoToMeetCounterspy");
// KK -->
			Locations[FindLocation("Oxbay_town")].reload.l13.close_for_night = 1;
			Locations[FindLocation("Oxbay_port")].vcskip = true;
			ChangeCharacterAddress(CharacterFromID("Ox_patrol_1"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Ox_patrol_2"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Bartholomew Pardner"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Olyver Blaxter"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Beatrice Applegate"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Brennan Applegate"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Gregor Samsa"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Flann Vickers"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Oxbay_Street_merchant_1"), "none", "");
// <-- KK
		break;

		case "Story_BlazeAndRabelGoToMeetCounterspy":
			LAi_ActorFollow(CharacterFromID("Rabel Iverneau"), PChar, "", -1);
			//SetShipRemovable(ref _refCharacter, bool bRemovable)
		break;

		case "Story_CounterspyGoesToPort":
			ChangeCharacterAddress(CharacterFromID("Counterspy"), "Oxbay_port", "goto10");
		break;

		case "Story_RabelGoesToPort":
			ChangeCharacterAddress(CharacterFromID("Rabel Iverneau"), "Oxbay_port", "goto8");
		break;

		case "Story_LeaveOxbayWithRabelAndCounterspy":
			Locations[FindLocation("Oxbay_port")].reload.l2.disable = 1;
			Locations[FindLocation("Oxbay_port")].reload.l3.disable = 1;
			//---------На случай, если игрок первым добежит до ворот.
			PlaceCharacter(CharacterFromID("Counterspy"), "officers");
			PlaceCharacter(CharacterFromID("Rabel Iverneau"), "officers");

			LAi_type_actor_Reset(CharacterFromID("counterspy"));
			LAi_type_actor_Reset(CharacterFromID("Rabel Iverneau"));

			LAi_SetActorType(CharacterFromID("Ox_Soldier_1")); // KK
			LAi_SetActorType(PChar);

			LAi_ActorFollow(PChar, CharacterFromID("Ox_Soldier_1"), "", 1.0); // KK
			LAi_ActorFollow(CharacterFromID("Ox_Soldier_1"), PChar, "Story_LeaveOxbayWithRabelAndCounterspy_2", 1.0); // KK
		break;

		case "Story_LeaveOxbayWithRabelAndCounterspy_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Ox_Soldier_1")); // KK
			Characters[GetCharacterIndex("Ox_Soldier_1")].Dialog.Filename = "Leaving_Oxbay_dialog.c"; // KK
			LAi_ActorDialog(CharacterFromID("Ox_Soldier_1"), PChar, "player_back", 1.0, 1.0); // KK
		break;

		case "Story_Follow_Rabel_And_Counterspy":
			if (characters[GetCharacterIndex("Rabel Iverneau")].location == "none" && characters[GetCharacterIndex("counterspy")].location == "none")
			{
				characters[GetCharacterIndex("Oxbay Commander")].skill.Accuracy = 2;
				characters[GetCharacterIndex("Oxbay Commander")].skill.cannons = 2;
				Locations[FindLocation("Oxbay_port")].reload.l2.disable = 0;
				Locations[FindLocation("Oxbay_port")].reload.l3.disable = 0;
				PChar.quest.Story_BlazeEscapedFromOxbay.win_condition.l1 = "Location";
				PChar.quest.Story_BlazeEscapedFromOxbay.win_condition.l1.location = "Redmond";
				PChar.quest.Story_BlazeEscapedFromOxbay.win_condition = "Story_BlazeEscapedFromOxbay";
				PChar.quest.Story_BlazeEscapedFromOxbay_cheat_fix.win_condition.l1 = "MapEnter";
				PChar.quest.Story_BlazeEscapedFromOxbay_cheat_fix.win_condition = "Story_BlazeEscapedFromOxbay_cheat_fix";
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
				SetOfficersIndex(PChar, 3, GetCharacterIndex("Rabel Iverneau"));
			}
			DoQuestCheckDelay("Story_Follow_Rabel_And_Counterspy_2", 20.0);
		break;

		case "Story_BlazeEscapedFromOxbay_cheat_fix":
			RemoveOfficersIndex(PChar, GetCharacterIndex("Rabel Iverneau"));
			RemoveOfficersIndex(PChar, GetCharacterIndex("Counterspy"));
			iForceDetectionFalseFlag = 0; // KK
		break;

		case "Story_Follow_Rabel_And_Counterspy_2":
			Group_SetTaskAttack("Story_French_Squadron", PLAYER_GROUP, true);
			Group_LockTask("Story_French_Squadron");
// KK -->
			characters[GetCharacterIndex("Rabel Iverneau")].AbordageMode = 0;
			if (GetRMRelation(PChar, FRANCE) > REL_WAR) SetRMRelation(PChar, FRANCE, REL_WAR);
			HoistFlag(FRANCE);
			iForceDetectionFalseFlag = 1;
// <-- KK
			AddCharacterGoods(PChar, GOOD_WHEAT, 40);  // Cat
			AddCharacterGoods(PChar, GOOD_RUM, 20);  //  Cat
		break;

		case "Story_RabelSuggestsToRun":
			LAi_type_actor_Reset(CharacterFromID("Rabel Iverneau"));
			LAi_ActorDialogNow(CharacterFromID("Rabel Iverneau"), PChar, "", -1);
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

			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_1"), "FRANCE_SOLDIERS"); // KK
			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_2"), "FRANCE_SOLDIERS"); // KK

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

			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_1"), "FRANCE_SOLDIERS"); // KK

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
			RemovePassenger(PChar, CharacterFromID("Counterspy"));
			RemovePassenger(PChar, CharacterFromID("Rabel Iverneau"));
			LAi_SetActorType(CharacterFromID("Rabel Iverneau"));
			ChangeCharacterAddress(CharacterFromID("Robert Christopher Silehard"), "Redmond_residence", "goto8");
			ChangeCharacterAddress(CharacterFromID("Counterspy"), "Redmond_residence", "goto3");
			ChangeCharacterAddress(CharacterFromID("Rabel Iverneau"), "Redmond_residence", "goto2");
			DoReloadFromSeaToLocation("Redmond_residence","goto", "goto1");
			PChar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1 = "location";
			PChar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition.l1.location = "redmond_residence";
			PChar.quest.Story_BlazeWithRabelAndCounterspyReturn.win_condition = "Story_BlazeWithRabelAndCounterspyReturn";
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l3.disable = 0;
// KK -->
			DeleteAttribute(&Locations[FindLocation("Oxbay_port")], "vcskip");
			ChangeCharacterAddress(CharacterFromID("Ox_patrol_1"), "Oxbay_port", "goto18");
			ChangeCharacterAddress(CharacterFromID("Ox_patrol_2"), "Oxbay_port", "goto12");
			ChangeCharacterAddress(CharacterFromID("Bartholomew Pardner"), "Oxbay_port", "goto9");
			ChangeCharacterAddress(CharacterFromID("Olyver Blaxter"), "Oxbay_port", "goto6");
			ChangeCharacterAddress(CharacterFromID("Beatrice Applegate"), "Oxbay_port", "goto18");
			ChangeCharacterAddress(CharacterFromID("Brennan Applegate"), "Oxbay_port", "goto13");
			ChangeCharacterAddress(CharacterFromID("Gregor Samsa"), "Oxbay_port", "goto13");
			ChangeCharacterAddress(CharacterFromID("Flann Vickers"), "Oxbay_port", "merchant1");
			ChangeCharacterAddress(CharacterFromID("Oxbay_Street_merchant_1"), "Oxbay_port", "merchant2");
// <-- KK
		break;

		case "Story_BlazeWithRabelAndCounterspyReturn":
			if(PChar.ship.type == "FR_Boussole" || PChar.ship.type == "RN_Razee" || PChar.ship.type == "FR_Razee")	// GR: only proceed if you have a flushdeck frigate, possibly repainted
			{
// KK -->
				ref Counterspy = CharacterFromID("Counterspy");

			//	RestoreOfficers(PChar.id);
				RestorePassengers(PChar.id);
				TakeShipCommandFromOfficer(PChar.id);
// <-- KK
				if(GetOfficersIndex(PChar, 1) != -1 && GetOfficersIndex(PChar, 1) != GetCharacterIndex("counterspy"))
				{
					iPassenger = GetOfficersIndex(PChar, 1);
					LAi_SetOfficerType(&characters[iPassenger]);
				}
				if(GetOfficersIndex(PChar, 2) != -1 && GetOfficersIndex(PChar, 2) != GetCharacterIndex("counterspy"))
				{
					iPassenger = GetOfficersIndex(PChar, 2);
					LAi_SetOfficerType(&characters[iPassenger]);
				}
				if(GetOfficersIndex(PChar, 3) != -1 && GetOfficersIndex(PChar, 3) != GetCharacterIndex("counterspy"))
				{
					iPassenger = GetOfficersIndex(PChar, 3);
					LAi_SetOfficerType(&characters[iPassenger]);
				}

				HoistFlag(ENGLAND); // KK
				PChar.quest.Story_BlazeEscapedFromOxbay.over = "yes";
				LAi_SetActorType(PChar);
				LAi_ActorWaitDialog(PChar, CharacterFromID("Robert Christopher Silehard"));
				PChar.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
				ExchangeCharacterShip(PChar, CharacterFromID("Ship Storage"));
				SetCharacterShipLocation(PChar, "Redmond_port");
				LAi_type_actor_Reset(CharacterFromID("Rabel Iverneau"));
				LAi_type_actor_Reset(CharacterFromID("Counterspy"));
				LAi_ActorTurnToCharacter(CharacterFromID("Rabel Iverneau"), CharacterFromID("Robert Christopher Silehard"));
				LAi_QuestDelay("Story_RabelLeavesResidence", 1.0);

				Characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "Story_2ndTask_complete";
			}
			else
			{
				LAi_SetActorType(CharacterFromID("Rabel Iverneau"));
				LAi_type_actor_Reset(CharacterFromID("Rabel Iverneau"));
				LAi_ActorTurnToCharacter(CharacterFromID("Rabel Iverneau"), CharacterFromID("Robert Christopher Silehard"));
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
			LAi_ActorGoToLocation(CharacterFromID("Counterspy"), "reload", "reload1", "none", "reload", "reload1", "", 5.0);
			LAi_SetActorType(CharacterFromID("Robert Christopher Silehard"));
			LAi_ActorDialog(CharacterFromID("Robert Christopher Silehard"), PChar, "back_to_hovernor_type", 5.0, 0);
		break;

		case "Story_RabelLeavesResidence":
			LAi_ActorDialog(CharacterFromID("Counterspy"), CharacterFromID("Robert Christopher Silehard"), "Story_CounterspyLeavesResidence", 2.0, 1.0);
			LAi_type_actor_Reset(CharacterFromID("Rabel Iverneau"));
			LAi_ActorGoToLocation(CharacterFromID("Rabel Iverneau"), "reload", "Reload1", "none", "reload", "reload1", "", 5.0);
			LAi_QuestDelay("Story_SilehardCongratulateWith2ndComplete", 2.0);
		break;

		case "Story_SilehardCongratulateWith2ndComplete":
			PChar.quest.story_playertriestorunfromoxbay.over = "yes";
			LAi_type_actor_Reset(CharacterFromID("Counterspy"));
			LAi_ActorGoToLocation(CharacterFromID("Counterspy"), "reload", "Reload1", "none", "reload", "reload1", "", 4.0);
			SetCharacterShipLocation(PChar, "Redmond_port");
			LAi_SetActorType(CharacterFromID("Robert Christopher Silehard"));
			LAi_ActorDialog(CharacterFromID("Robert Christopher Silehard"), PChar, "back_to_hovernor_type", 5.0, 0);
		break;

		case "Story_DanielleWaitsInMuelleTown":
			//DeleteAttribute(&PChar,"skipfood"); // NK 04-11 // KK
			PChar.quest.Story_AppearOnIslaMuelleonAnacletoShip.over = "yes";
			ChangeCharacterAddress(CharacterFromID("danielle"), "muelle_tavern", "goto6");
			Locations[FindLocation("muelle_tavern")].vcskip = true; // NK
			Characters[GetCharacterIndex("Danielle")].dialog.CurrentNode  = "MetBlazeOnIslaMuelle";
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 5.0, 1.0);
		break;

		case "Story_AppearOnIslaMuelleonAnacletoShip":
			CloseQuestHeader("Where_are_i");				// GR: Catch-all as questbook is not closed by some story sequences
			ChangeCharacterAddress(CharacterFromID("peasant"), "None", "");	// GR: remove character who met you on "Douwesen_shore_01" after storm
			iPassenger = makeint(PChar.Temp.Officer.idx1);

			PlaceCharacter(&Characters[iPassenger], "officers");

			LAi_SetActorType(&Characters[iPassenger]);
			Characters[iPassenger].Dialog.Filename = "Found_Blaze_1_dialog.c";
			Characters[iPassenger].Dialog.currentnode = "First time";
			LAi_ActorDialog(&Characters[iPassenger], PChar, "", 8.0, 1.0);

			iPassenger = makeint(PChar.Temp.Officer.idx2);

			PlaceCharacter(&Characters[iPassenger], "officers");

			LAi_SetActorType(&Characters[iPassenger]);
			Characters[iPassenger].Dialog.Filename = "Found_Blaze_2_dialog.c";
			Characters[iPassenger].Dialog.currentnode = "First time";
			LAi_ActorFollow(&Characters[iPassenger], PChar, "", 8.0);

			iPassenger = makeint(PChar.Temp.Officer.idx3);

			PlaceCharacter(&Characters[iPassenger], "goto");

			LAi_SetActorType(&Characters[iPassenger]);
			Characters[iPassenger].Dialog.Filename = "Found_Blaze_3_dialog.c";
			Characters[iPassenger].Dialog.currentnode = "First time";
			LAi_ActorFollow(&Characters[iPassenger], PChar, "", 8.0);

			ChangeCharacterAddress(CharacterFromID("Danielle"), "Muelle_Tavern", "goto2");
		break;

		case "Story_OfficersShutUpAfterFoundBlaze":
			iPassenger = makeint(PChar.Temp.Officer.idx1);
			Characters[iPassenger].Dialog.CurrentNode = "Explanation";
			LAi_ActorDialogNow(&Characters[iPassenger], PChar, "", -1);

			iPassenger = makeint(PChar.Temp.Officer.idx2);
			LAi_ActorTurnToCharacter(&Characters[iPassenger], PChar);

			iPassenger = makeint(PChar.Temp.Officer.idx3);
			LAi_ActorTurnToCharacter(&Characters[iPassenger], PChar);
		break;

		case "Story_OfficersGoToTavernWithBlaze":
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			SetQuestHeader("Meet_Danielle_on_Muelle");
			AddQuestRecord("Meet_Danielle_on_Muelle", 3);
			Preprocessor_Remove("Danielle");
			ChangeCharacterAddress(CharacterFromID("Danielle"), "None", "");
			PChar.Quest.Story_DanielleWaitsInMuelleTown.over = "yes";
			characters[getCharacterIndex("Tiago Marquina")].location = "none";
			characters[getCharacterIndex("Muelle_officiant")].location = "none";
			Locations[FindLocation("muelle_tavern")].vcskip = true; // NK
			DoQuestReloadToLocation("Muelle_tavern", "sit","sit7", "Story_AppearedinMuelleTavernwithOfficers");
		break;

		case "Story_AppearedinMuelleTavernwithOfficers":
			ChangeCharacterAddress(CharacterFromID("danielle"), "none", "");

			iPassenger = makeint(PChar.Temp.Officer.idx3);
			ChangeCharacterAddressGroup(&Characters[iPassenger], "Muelle_tavern", "sit2", "sit3");
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorSetSitMode(&Characters[iPassenger]);

			iPassenger = makeint(PChar.Temp.Officer.idx2);
			ChangeCharacterAddressGroup(&Characters[iPassenger], "Muelle_tavern", "Sit", "sit4");
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorSetSitMode(&Characters[iPassenger]);

			iPassenger = makeint(PChar.Temp.Officer.idx1);
			ChangeCharacterAddressGroup(&Characters[iPassenger], "Muelle_tavern", "Sit", "sit8");
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorSetSitMode(&Characters[iPassenger]);

			LAi_SetSitType(PChar);

			LAi_QuestDelay("Story_OfficersStartTalkInMuelleTavern", 0.5);
		break;

		case "Story_OfficersStartTalkInMuelleTavern":
			Characters[makeint(PChar.Temp.Officer.idx3)].Dialog.CurrentNode = "Talk_In_Tavern";
			LAi_ActorDialogNow(&Characters[makeint(PChar.Temp.Officer.idx3)], PChar, "", -1);
			DeleteAttribute(&Locations[FindLocation("muelle_tavern")],"vcskip"); // NK
		break;

		case "Story_CameToOgarrioHouse":
			LAi_ActorTurnToCharacter(CharacterFromID("Sidonio Ogarrio"), PChar);
			LAi_QuestDelay("Story_OgarrioTalksToPlayer", 0.5);
		break;

		case "Story_OgarrioTalksToPlayer":
			LAi_ActorDialog(CharacterFromID("Sidonio Ogarrio"), PChar, "", 5.0, 1.0);
		break;

		case "found_blaze_Exit_Danielle":
			LAi_type_actor_Reset(CharacterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].dialog.CurrentNode  = "MetBlazeOnIslaMuelle";
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 10.0, 1.0);
		break;

		case "Story_BlazeMetDanielleOnIslaMuelle":
			ChangeCharacterAddress(CharacterFromID("Danielle"), "Muelle_Tavern_upstairs", "goto3");
			LAi_SetStayType(PChar);
			DoQuestReloadToLocation("Muelle_tavern_upstairs", "Goto", "Goto2", "Story_BlazeAndDanielleStartTalkinMuelleTavern");
			locations[FindLocation("Douwesen_town")].reload.l3.disable = false;
		break;

		case "Story_BlazeAndDanielleStartTalkinMuelleTavern":
			SetCurrentTime(22, 0);
			Characters[getCharacterIndex("Danielle")].Dialog.Filename = "danielle_dialog.c";
			Characters[getCharacterIndex("Danielle")].Dialog.CurrentNode = "Talk_upstairs";
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("danielle"), "Story_BlazeAndDanielleStartTalkinMuelleTavern_2", 2.0);
		break;

		case "Story_BlazeAndDanielleStartTalkinMuelleTavern_2":
			LAi_SetPlayerType(PChar);
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 1.0, 0);
		break;

		case "Story_BlazeLeavesDanielleRoom":
			LAi_SetPlayerType(PChar);
			PChar.location.locator = "";
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

			iPassenger = makeint(PChar.Temp.Officer.idx1);
			if(Characters[iPassenger].id != "Blaze_Crewmember_01" && getOfficersIndex(PChar, 1) != -1)
			{
				Characters[getOfficersIndex(PChar, 1)].Dialog.Filename = PChar.Temp.Officer.idx1.Dialog;
				Characters[getOfficersIndex(PChar, 1)].Dialog.CurrentNode = PChar.Temp.Officer.idx1.CurrentNode;
			}
			iPassenger = makeint(PChar.Temp.Officer.idx2);
			if(Characters[iPassenger].id != "Blaze_Crewmember_02" && getOfficersIndex(PChar, 2) != -1)
			{
				Characters[getOfficersIndex(PChar, 2)].Dialog.Filename = PChar.Temp.Officer.idx2.Dialog;
				Characters[getOfficersIndex(PChar, 2)].Dialog.CurrentNode = PChar.Temp.Officer.idx2.CurrentNode;
			}
			iPassenger = makeint(PChar.Temp.Officer.idx3);
			if(Characters[iPassenger].id != "Blaze_Crewmember_03" && getOfficersIndex(PChar, 3) != -1)
			{
				Characters[getOfficersIndex(PChar, 3)].Dialog.Filename = PChar.Temp.Officer.idx3.Dialog;
				Characters[getOfficersIndex(PChar, 3)].Dialog.CurrentNode = PChar.Temp.Officer.idx3.CurrentNode;
			}

			DeleteAttribute(CharacterFromID("danielle"), "ship");
			DeleteAttribute(PChar, "temp.officer");
			characters[GetCharacterIndex("danielle")].ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
			AddMoneyToCharacter(PChar, 70000); // KK what that money come from?
			/*if (PChar.ship.type != SHIP_TARTANE)
			{
				characters[GetCharacterIndex("danielle")].ship.type = PChar.ship.type;
				SetBaseShipData(CharacterFromID("danielle"));
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
			PChar.ship.hp = GetCharacterShipHP(PChar);
			DeleteAttribute(PChar,"ship.blots");
			PChar.ship.sp = GetCharacterShipSP(PChar);
			DeleteAttribute(PChar,"ship.sails");
			DeleteAttribute(PChar,"ship.masts");
			ResetCannons(PChar)

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

			PChar.location.from_sea = "Muelle_port";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			PChar.money = "" + (sti(PChar.money) + sti(PChar.tempmoney)); // KK
			characters[getCharacterIndex("Tiago Marquina")].location = "Muelle_tavern";
			characters[getCharacterIndex("Muelle_officiant")].location = "Muelle_tavern";
			DoQuestReloadToLocation("Muelle_port", "Goto", "character4", "Story_BlazeMeetDanielleInMuellePort");
		break;

		case "danielle_Talk_upstairs_Exit":
			LAi_SetActorType(PChar);

			LAi_ActorGoToLocator(PChar, "reload", "reload1", "Story_BlazeLeavesDanielleRoom", 3.0);

			Locations[FindLocation("Oxbay_lighthouse")].locators_radius.goto.goto23 = 15.0;
			PChar.quest.Speak_with_lighthouse_guards.win_condition.l1 = "location";
			PChar.quest.Speak_with_lighthouse_guards.win_condition.l1.location = "Lighthouse_Inside";
			PChar.quest.Speak_with_lighthouse_guards.win_condition = "Speak_with_lighthouse_guards";
			DeleteAttribute(&Locations[FindLocation("Oxbay_lighthouse")], "models.night.light");
			//Locations[FindLocation("Oxbay_lighthouse")].models.night.light = "";
		break;

		case "Story_BlazeMeetDanielleInMuellePort":
			//Locations[FindLocation("Muelle_Tavern_upstairs")].reload.l1.disable = 0;
			PlaceCharacter(CharacterFromID("danielle"), "goto");
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "MetInMuellePort";
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("danielle"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("danielle"), PChar, "Story_BlazeMeetDanielleInMuellePort_2", 2.0);
		break;

		case "Story_BlazeMeetDanielleInMuellePort_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "player_back", 1.0, 1.0);
			PChar.location.from_sea = "Muelle_port";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
		break;

		case "danielle_MetInMuellePort_Exit":
			LAi_ActorRunToLocator(CharacterFromID("danielle"), "reload", "reload3", "Story_DanielleGoesToBlazeShip", 5.0);
			PChar.location.from_sea = "muelle_port";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			ChangeCharacterAddress(CharacterFromID("researcher"), "none", "");
		break;

		case "Story_DanielleGoesToBlazeShip":
			Island_SetReloadEnableGlobal("Oxbay", true);
			ChangeCharacterAddress(CharacterFromID("Danielle"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Lighthouse_Guard_01"), "Lighthouse_Inside", "goto3");
			ChangeCharacterAddress(CharacterFromID("Lighthouse_Guard_02"), "Lighthouse_Inside", "goto2");
			ChangeCharacterAddress(CharacterFromID("Lighthouse_Officer"), "Lighthouse_Inside", "goto1");
			Locations[FindLocation("Oxbay_lighthouse")].reload.l4.disable = 0;

			/*if (characters[GetCharacterIndex("danielle")].ship.type != SHIP_NOTUSED)
			{
				SetCompanionIndex(PChar, -1, GetCharacterIndex("danielle"));
			}
			else
			{*/
				SetOfficersIndex(PChar, 1, GetCharacterIndex("Danielle"));
				LAi_SetOfficerType(CharacterFromID("danielle"));
			//}
			SetCharacterRemovable(CharacterFromID("Danielle"), false);
			PChar.quest.danielle_on_ship = "true";

			PChar.quest.Story_KillSoldiersAtLighthouse.win_condition.l1 = "NPC_Death";
			PChar.quest.Story_KillSoldiersAtLighthouse.win_condition.l1.character = "Lighthouse_Guard_01";
			PChar.quest.Story_KillSoldiersAtLighthouse.win_condition.l2 = "NPC_Death";
			PChar.quest.Story_KillSoldiersAtLighthouse.win_condition.l2.character = "Lighthouse_Guard_02";
			PChar.quest.Story_KillSoldiersAtLighthouse.win_condition.l3 = "NPC_Death";
			PChar.quest.Story_KillSoldiersAtLighthouse.win_condition.l3.character = "Lighthouse_Officer";
			PChar.quest.Story_KillSoldiersAtLighthouse.win_condition = "Story_KillSoldiersAtLighthouse";

			PChar.quest.to_lighthouse_after_danielle_join.win_condition.l1 = "location";
			PChar.quest.to_lighthouse_after_danielle_join.win_condition.l1.location = "Oxbay_lighthouse";
			PChar.quest.to_lighthouse_after_danielle_join.win_condition = "to_lighthouse_after_danielle_join";
		break;

		case "to_lighthouse_after_danielle_join":
			PlaceCharacter(CharacterFromID("danielle"), "goto");
			LAi_SetOfficerType(CharacterFromID("danielle"));
		break;

		case "Story_KillSoldiersAtLighthouse":
			characters[GetCharacterIndex("Lighthouse_Guard_01")].location = "none";
			characters[GetCharacterIndex("Lighthouse_Guard_02")].location = "none";
			characters[GetCharacterIndex("Lighthouse_Officer")].location = "none";

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Meet_Danielle_on_Muelle",5);
			Preprocessor_Remove("Danielle");

			PChar.quest.Story_TalkAfterKillingSoldiersatLighthouse.win_condition.l1 = "location";
			PChar.quest.Story_TalkAfterKillingSoldiersatLighthouse.win_condition.l1.location = "Oxbay_Lighthouse";
			PChar.quest.Story_TalkAfterKillingSoldiersatLighthouse.win_condition = "Story_TalkAfterKillingSoldiersatLighthouse";
		break;

		case "Story_TalkAfterKillingSoldiersatLighthouse":
			PlaceCharacter(CharacterFromID("danielle"), "goto");
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("danielle"));
			Lai_ActorFollow(PChar, CharacterFromID("Danielle"), "", 3.0);
			Lai_ActorFollow(CharacterFromID("Danielle"), PChar, "Story_TalkAfterKillingSoldiersatLighthouse_2", 3.0);
		break;

		case "Story_TalkAfterKillingSoldiersatLighthouse_2":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "CaptureGreenford";
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 2.0, 0);
		break;

		case "Story_PrepareToSiegeGreenford":
			LAi_SetOfficerType(CharacterFromID("danielle"));
			PChar.quest.Story_AreYouReadyToCaptureGreenford.win_condition.l1 = "location";
			PChar.quest.Story_AreYouReadyToCaptureGreenford.win_condition.l1.location = "Oxbay_lighthouse";
			PChar.quest.Story_AreYouReadyToCaptureGreenford.win_condition = "Story_AreYouReadyToCaptureGreenford";
		break;

		case "Story_AreYouReadyToCaptureGreenford":
			if (!isofficer(CharacterFromID("Danielle")))	// GR: Make sure Danielle is officer, in case she has been replaced by sidequest character or random hired officer
			{
				PlaceCharacter(CharacterFromID("danielle"), "goto");
				SetOfficersIndex(PChar, 1, GetCharacterIndex("Danielle"));
				LAi_SetOfficerType(CharacterFromID("danielle"));
			}
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Are_we_ready";
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 5.0, 1.0);
		break;

		case "Story_GreenfordAssaultStarted":
			LAi_SetOfficerType(CharacterFromID("danielle")); // GR: If Danielle is to join you in the fort assault, let her fight
			Characters[GetCharacterIndex("Greenford Commander")].Dialog.Filename = "Greenford Commander_dialog.c";
			Characters[GetCharacterIndex("Greenford Commander")].Dialog.BoardingNode = "capture_of_Greenford";

//			QuestToSeaLogin_PrepareLoc("Oxbay", "Quest_Ships", "Quest_ship_23", true);	// GR: teleport to near fort
			QuestToSeaLogin_PrepareLoc("Oxbay", "reload", "reload_4", true);		// GR: put to sea next to lighthouse
			QuestToSeaLogin_Launch();
			//Islands[FindIsland("Oxbay")].reload.l6.go = "Fake_Greenford_fort"; // KK

			/*PChar.quest.Story_CaptureGreenfordFort.win_condition.l1 = "FORT_destroy";
			PChar.quest.Story_CaptureGreenfordFort.win_condition.l1.character = "Greenford Commander";
			PChar.quest.Story_CaptureGreenfordFort.win_condition = "Story_CaptureGreenfordFort";*/
			/*PChar.quest.Story_CaptureGreenford.win_condition.l1 = "Colony_capture";
			PChar.quest.Story_CaptureGreenford.win_condition.l1.town = "Greenford";
			PChar.quest.Story_CaptureGreenford.win_condition = "Story_CaptureGreenford";*/

			LAi_SetImmortal(CharacterFromID("Greenford Commander"), false);

			/*SetNationRelation2MainCharacter(GetTownNation("Greenford"), RELATION_ENEMY);
			SetRMRelation(PChar, GetTownNation("Greenford"), RelationToRMRelation(RELATION_ENEMY));
			UpdateRelations();

			SetCharacterRemovable(CharacterFromID("Danielle"), true);
			RemovePassenger(PChar, CharacterFromID("Danielle"));
			RemoveCharacterCompanion(PChar, CharacterFromID("danielle"));

			iForceDetectionFalseFlag = 1; // KK

			bQuestDisableMapEnter = true;
			//--------------Отключение возможности выгрузиться на остров
			Island_SetReloadEnableGlobal("Oxbay", false);*/

			//Group_SetAddress("Story_English_Squadron", "Oxbay", "Quest_Ships","Quest_ship_23");
			//DoReloadCharactertoLocation("Oxbay", "reload", "reload_fort1");

			/*PChar.quest.Story_FightingInGreenfordPort.win_condition.l1 = "location";
			PChar.quest.Story_FightingInGreenfordPort.win_condition.l1.location = "Fake_Greenford_port";
			PChar.quest.Story_FightingInGreenfordPort.win_condition = "Story_FightingInGreenfordPort";*/
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

			PChar.quest.Story_FightingInGreenfordTown.win_condition.l1 = "location";
			PChar.quest.Story_FightingInGreenfordTown.win_condition.l1.location = "Fake_Greenford_town";
			PChar.quest.Story_FightingInGreenfordTown.win_condition = "Story_FightingInGreenfordTown";

			LAi_group_SetCheck("ENGLAND_PORT_SOLDIERS", "Story_KillEverybodyInGreenfordPort");
		break;

		case "Story_KillEverybodyInGreenfordPort":
			Locations[FindLocation("Fake_Greenford_port")].reload.l2.name = "reload4";
			Locations[FindLocation("Fake_Greenford_port")].reload.l2.go = "Fake_Greenford_town";
			Locations[FindLocation("Fake_Greenford_port")].reload.l2.emerge = "reload1";
		break;


		case "Story_FightingInGreenfordTown":
			ChangeCharacterAddressGroup(CharacterFromID("Danielle"), "Fake_Greenford_town", "reload", "reload26");

			sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "Black_Corsair", "reload", "reload26");
			// NK - LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "fatman", "reload", "reload26");
			// NK - LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "Chameleon", "reload", "reload26");
			// NK - LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);


			LAi_group_MoveCharacter(CharacterFromID("Danielle"), LAI_GROUP_PLAYER);

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

			SetCharacterShipLocation(PChar, "Greenford_port");
			LAi_group_MoveCharacter(CharacterFromID("Researcher"), LAI_GROUP_PLAYER);
			//SetCharacterRelationAsOtherCharacter(GetCharacterIndex("Greenford commander"), GetMainCharacterIndex());
			//SetCharacterRelation(GetCharacterIndex("Greenford commander"),GetMainCharacterIndex(),RELATION_FRIEND);
			//UpdateRelations();
			SetTownFortCommander("Greenford", CharacterFromID("Danielle"));
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

			//ChangeCharacterAddressGroup(CharacterFromID("Danielle"), "Greenford_town", "goto", "goto39");
			//LAi_QuestDelay("Story_DanielleOffersToGoSaveResearcher", 1.0);
			DoQuestReloadToLocation("Greenford_town", "reload", "reload19", "Story_DanielleAndResearcher");
// <-- KK
		break;

		case "Story_DanielleAndResearcher":
			PlaceCharacter(CharacterFromID("Danielle"), "goto");
//			PlaceCharacter(CharacterFromID("Researcher"), "goto");
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("danielle"));
			Lai_ActorFollow(PChar, CharacterFromID("danielle"), "", 2.0);
			Lai_ActorFollow(CharacterFromID("danielle"), PChar, "Story_DanielleAndResearcher_2", 2.0);
		break;

		case "Story_DanielleAndResearcher_2":
			LAi_ActorWaitDialog(PChar, CharacterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Greenford_captured";
//			LAi_SetStayType(CharacterFromID("researcher"));
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "player_back", 10.0, 1.0);
		break;

		case "danielle_Greenford_captured_exit":
			LAi_SetActorType(CharacterFromID("danielle"));
			ChangeCharacterAddress(CharacterFromID("Researcher"), "Greenford_prison", "goto9");

			PChar.quest.Story_AppearedInGreenfordPrison.win_condition.l1 = "location";
			PChar.quest.Story_AppearedInGreenfordPrison.win_condition.l1.location = "Greenford_prison";
			PChar.quest.Story_AppearedInGreenfordPrison.win_condition = "Story_AppearedInGreenfordPrison";
			// KK SetTownCapturedState("Greenford", false); // 04-12-15

			LAi_ActorRunToLocator(CharacterFromID("danielle"), "reload", "reload27", "Story_DanielleWentToGreenfordPrison", 20.0);
/*			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Researcher"));
			Lai_ActorFollow(PChar, CharacterFromID("Researcher"), "", 2.0);
			Lai_ActorFollow(CharacterFromID("Researcher"), PChar, "Story_DanielleAndResearcher_3", 2.0); */
		break;

		case "Story_DanielleAndResearcher_3":
//			LAi_ActorWaitDialog(PChar, CharacterFromID("Researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Translation";
			LAi_SetActorType(CharacterFromID("Researcher"));
			LAi_ActorDialog(CharacterFromID("Researcher"), PChar, "player_back", 10.0, 1.0);
		break;

		case "Story_DanielleWentToGreenfordPrison":
			ChangeCharacterAddress(CharacterFromID("Danielle"), "Greenford_prison", "goto18");
			Locations[FindLocation("Greenford_prison")].vcskip = true;
		break;

		case "Story_AppearedInGreenfordPrison":
			LAi_SetOfficerType(CharacterFromID("danielle"));
			PChar.quest.Story_DanielleWentToGreenfordPrison.over = "yes";
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Translation";

			PChar.quest.story_researcher_in_prison_speaks.win_condition.l1 = "locator";
			PChar.quest.story_researcher_in_prison_speaks.win_condition.l1.location = "Greenford_prison";
			PChar.quest.story_researcher_in_prison_speaks.win_condition.l1.locator_group = "reload";
			PChar.quest.story_researcher_in_prison_speaks.win_condition.l1.locator = "reload12";
			PChar.quest.story_researcher_in_prison_speaks.win_condition = "Story_DanielleAndResearcher_3";
		break;

		case "Story_MovingToLighthouse":
			DeleteAttribute(&Locations[FindLocation("Greenford_prison")],"vcskip");
			RemovePassenger(PChar, CharacterFromID("Danielle"));

			CloseQuestHeader("Meet_Danielle_on_Muelle");
			CloseQuestHeader("Capture_greenford");

			ChangeCharacterAddress(CharacterFromID("Danielle"), "Oxbay_lighthouse", "goto22");
			ChangeCharacterAddress(CharacterFromID("Researcher"), "Oxbay_lighthouse", "goto23");

			DoQuestReloadToLocation("Oxbay_lighthouse", "Goto", "goto24", "Story_TalkWithResearcherAfterSaving");
			//Убираем английских солдат из Гринфорда
			/*ChangeCharacterAddress(CharacterFromID("Eng_soldier_38"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Eng_soldier_39"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Eng_soldier_40"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Eng_soldier_41"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_soldier_1"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_soldier_2"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_soldier_3"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_soldier_4"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_soldier_5"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_soldier_6"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_soldier_7"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_soldier_8"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_1"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_2"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_3"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_4"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_41"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Green_soldier_8"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Mine_soldier_05"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Mine_soldier_06"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Greenford Prison Commendant"), "None", "");*/
			locations[FindLocation("Oxbay_lighthouse")].fastreload = "Oxbay";
		break;

		case "Story_TalkWithResearcherAfterSaving":
			PlaceCharacter(CharacterFromID("researcher"), "goto");
			PlaceCharacter(CharacterFromID("danielle"), "goto");
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "NeedSomeTime";
			LAi_SetActorType(CharacterFromID("researcher"));
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("researcher"), PChar, "Story_TalkWithResearcherAfterSaving_2", 2.0);
		break;

		case "Story_TalkWithResearcherAfterSaving_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("Researcher"), PChar, "player_back", 1.0, 1.0);
		break;

		case "Story_LighthouseSpeakWithDanielle":
			/*ChangeCharacterAddress(CharacterFromID("Danielle"), "Greenford_tavern", "goto7");
			Locations[FindLocation("Greenford_tavern")].vcskip = true; // NK
			DoQuestReloadToLocation("Greenford_tavern", "Goto", "goto17", "Story_DanielleStartsTalkAboutResearcher");*/
			LAi_SetActorType(PChar);
			characters[GetCharacterindex("Danielle")].Dialog.CurrentNode = "WaitInGreenford";
			LAi_SetActorType(CharacterFromID("Danielle"));
			Lai_ActorFollow(PChar, CharacterFromID("Danielle"), "", 2.0);
			Lai_ActorFollow(CharacterFromID("Danielle"), PChar, "Story_LighthouseSpeakWithDanielle_1", 2.0);
		break;

		case "Story_LighthouseSpeakWithDanielle_1":
			LAi_ActorWaitDialog(PChar, CharacterFromID("Danielle"));
			LAi_SetActorType(CharacterFromID("Danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "player_back", 10.0, 1.0);
		break;

// KK -->
		case "Story_WaitInGreenford":
			DoQuestReloadToLocation("Greenford_town", "reload", "reload26", "Story_WaitInGreenford_2");
		break;

		case "Story_WaitInGreenford_2":
			bQuestDisableSeaEnter = true;
			ChangeCharacterAddressGroup(CharacterFromID("Danielle"), "None", "", "");

			PChar.quest.Story_WaitInGreenfordEnd.win_condition.l1 = "location";
			PChar.quest.Story_WaitInGreenfordEnd.win_condition.l1.location = "Greenford_tavern_upstairs";
			PChar.quest.Story_WaitInGreenfordEnd.win_condition = "Story_WaitInGreenfordEnd";

			PChar.quest.Story_WaitInGreenfordEnd.day = GetAddingDataDay(0, 0, 7);
			PChar.quest.Story_WaitInGreenfordEnd.month = GetAddingDataMonth(0, 0, 7);
			PChar.quest.Story_WaitInGreenfordEnd.year = GetAddingDataYear(0, 0, 7);
		break;

		case "Story_WaitInGreenfordEnd":
			DisableFastTravel(true);
			WaitDate("", sti(PChar.quest.Story_WaitInGreenfordEnd.year) - GetDataYear(), sti(PChar.quest.Story_WaitInGreenfordEnd.month) - GetDataMonth(), sti(PChar.quest.Story_WaitInGreenfordEnd.day) - GetDataDay(), 7, 0);
			DeleteAttribute(PChar, "quest.Story_WaitInGreenfordEnd.day");
			DeleteAttribute(PChar, "quest.Story_WaitInGreenfordEnd.month");
			DeleteAttribute(PChar, "quest.Story_WaitInGreenfordEnd.year");
			ChangeCharacterAddressGroup(CharacterFromID("Danielle"), "Greenford_tavern", "goto", "goto7");
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
			LAi_SetActorType(CharacterFromID("Danielle"));
			LAi_SetActorType(PChar);
			Lai_ActorFollow(PChar, CharacterFromID("Danielle"), "", 2.0);
			Lai_ActorFollow(CharacterFromID("Danielle"), PChar, "Story_DanielleStartsTalkAboutResearcher_2", 2.0);
		break;

		case "Story_DanielleStartsTalkAboutResearcher_2":
			DisableFastTravel(false);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Danielle"));
			Locations[FindLocation("Greenford_tavern")].locators_radius.goto.goto17 = Locations[FindLocation("Greenford_tavern")].locators_radius.goto.goto17.old;
			DeleteAttribute(&Locations[FindLocation("Greenford_tavern")], "locators_radius.goto.goto17.old");
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "player_back", 10.0, 1.0);
		break;
 // <-- KK

		case "Story_DanielleOffersToBecomeFortCommander":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "RepelEnglishAssault";
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 5.0, 0);
			LAi_ActorRunToLocation(CharacterFromID("Blaze_Crewmember_01"), "reload", "reload1", "none", "", "", "", 10.0);
		break;

		case "Story_RepelEnglishAssaultOnGreenford":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("Story_RepelEnglishAssaultOnGreenford_2", 5.0);
		break;

		case "Story_RepelEnglishAssaultOnGreenford_2":
			ChangeCharacterAddressGroup(CharacterFromID("Danielle"), "Greenford_port", "reload", "reload4");
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
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 20.0, 1.0);
			PChar.location.from_sea = "Oxbay_lighthouse";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			Locations[FindLocation("Oxbay_lighthouse")].reload.l3.disable = 1;
		break;

		case "Story_VoyageToKhaelRoaBegan":
			// PB: Return Town to England to prevent errors -->
			// GR: Capturing a town for Personal moves all its soldiers into group LAI_GROUP_PLAYER
			// GR: If a character is in LAI_GROUP_PLAYER, 'bAllies(character)' is true
			// GR: If 'bAllies(character)' is true, 'SetTownGarrisonForNation' doesn't change his uniform
			// GR: So put all soldiers back into "ENGLAND_SOLDIERS" before capturing "Greenford" for ENGLAND
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_1"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_2"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_patrol_1"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_patrol_2"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Eng_soldier_40"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Eng_soldier_41"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_3"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_4"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_patrol_3"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_patrol_4"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_patrol_41"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_5"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_6"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_7"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_8"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_9"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_soldier_10"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Greenford Prison Commendant"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Eng_soldier_38"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Eng_soldier_39"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_exit_soldier_01"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Green_exit_soldier_02"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Mine_soldier_05"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Mine_soldier_06"), "ENGLAND_SOLDIERS");
			SetTownFortCommander("Greenford", CharacterFromID("Greenford Commander"));
			SetTownName("Greenford", "Bridgetown");	// In case the player renamed the town while it was Personal
			CaptureTownForNation("Greenford", ENGLAND);
			ChangeCharacterAddressGroup(CharacterFromID("Greenford Commander"), "Oxbay", "reload", "reload_fort1");

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
			ChangeCharacterAddress(CharacterFromID("Robert Christopher Silehard"), "none", "");
			LAi_SetStayType(CharacterFromID("Robert Christopher Silehard"));
			SetRumourState("Silehard_nasty", false);
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = 0;
// NK <--
			characters[GetCharacterIndex("Robert Christopher Silehard")].rank = sti(PChar.rank) - 4;
			ChangeCharacterAddress(CharacterFromID("John Clifford Brin"), "redmond_residence", "goto8"); // NK
			characters[GetCharacterIndex("John Clifford Brin")].dialog = "Robert Christopher Silehard_dialog.c"; // PB
			Towns[GetTownIndex("Redmond")].gov = "John Clifford Brin"; // KK
			// KK Characters[GetCharacterIndex("Redmond Commander")].gov = "John Clifford Brin"; // RM
			SetRumourState("Brin_here", true); // NK

			// PS gen chars and ships-->
			SetUpShip(CharacterFromID("Isenbrandt Jurcksen"), "war", true);
			SetUpShip(CharacterFromID("Brian The Slayer"), "war", true);
			//SetUpShip(CharacterFromID("James Paige"), "war", true);
// KK -->
			SetUpShip(CharacterFromID("Robert Christopher Silehard"), "war", true);
			SetUpShip(CharacterFromID("Thomas Norton"), "war", true);

			GiveItem2Character(CharacterFromID("Robert Christopher Silehard"), "blade51");
			EquiPCharacterByItem(CharacterFromID("Robert Christopher Silehard"), "blade51");
			GiveItem2Character(CharacterFromID("Robert Christopher Silehard"), "pistol5");
			EquiPCharacterByItem(CharacterFromID("Robert Christopher Silehard"), "pistol5");
// <-- KK

			// (superhigh numbers to make sure crew at max)
			SetCrewQuantity(CharacterFromID("Isenbrandt Jurcksen"), 4000);
			SetCrewQuantity(CharacterFromID("Brian The Slayer"), 4500);
			SetCrewQuantity(CharacterFromID("Robert Christopher Silehard"), 9500);
			SetCrewQuantity(CharacterFromID("Thomas Norton"), 1600);
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

			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l1 = "NPC_Death";
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l1.character = "Isenbrandt Jurcksen";
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l2 = "NPC_Death";
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l2.character = "Brian The Slayer";
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l3 = "NPC_Death";
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l3.character = "Thomas Norton";
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l4 = "NPC_Death";
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l4.character = "Robert Christopher Silehard";
// KK -->
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l5 = "location";
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition.l5.location = "KhaelRoa";
// <-- KK
			PChar.quest.Story_SinkPiratesAtKhaelRoa.win_condition = "Story_SinkPiratesAtKhaelRoa";

			PChar.quest.Story_AppearAtKhaelRoa.win_condition.l1 = "location";
			PChar.quest.Story_AppearAtKhaelRoa.win_condition.l1.location = "KhaelRoa";
			PChar.quest.Story_AppearAtKhaelRoa.win_condition = "Story_AppearAtKhaelRoa";

			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "ReadyForKhaelRoa";
		break;

		case "Story_AppearAtKhaelRoa":
			LAi_SetImmortal(CharacterFromID("Robert Christopher Silehard"), false);
			LAi_SetStayType(CharacterFromID("Robert Christopher Silehard"));
			LAi_SetImmortal(CharacterFromID("Isenbrandt Jurcksen"), false);
			Characters[GetCharacterIndex("Robert Christopher Silehard")].recognized = true;
			Characters[GetCharacterIndex("Isenbrandt Jurcksen")].recognized = true;
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableLocal("KhaelRoa", "reload_1", true);
			Island_SetReloadEnableGlobal("KhaelRoa", false);
			if(GetRMRelation(PChar, PIRATE) > REL_WAR) SetRMRelation(PChar, PIRATE, REL_WAR); // RM
			LeaveService(PChar, PIRATE, false); // RM
			ChangeCharacterShipGroup(CharacterFromID("Isenbrandt Jurcksen"), "Pirates");
			ChangeCharacterShipGroup(CharacterFromID("Brian The Slayer"), "Pirates");
			ChangeCharacterShipGroup(CharacterFromID("Robert Christopher Silehard"), "Pirates");
			ChangeCharacterShipGroup(CharacterFromID("Thomas Norton"), "Pirates");
			Group_SetTaskAttack("Pirates", PLAYER_GROUP, true);
			Group_LockTask("Pirates");
			UpdateRelations();
			iForceDetectionFalseFlag = 1; // KK

			PChar.quest.Ways_to_talk.win_condition.l1 = "location";
			PChar.quest.Ways_to_talk.win_condition.l1.character = "Robert Christopher Silehard";
			PChar.quest.Ways_to_talk.win_condition.l1.location = PChar.location;
			PChar.quest.Ways_to_talk.win_condition = "Ways_to_talk";
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

			SetOfficersIndex(PChar, -1,getCharacterIndex("Researcher"));
			SetCharacterRemovable(CharacterFromID("Researcher"), false);
			characters[GetCharacterIndex("Researcher")].AbordageMode = 0;	// KK

			ChangeCharacterAddressGroup(CharacterFromID("Skull"), "QC_residence", "goto", "goto1");			// PB: Replacement for Isenbrandt Jurcksen
			Characters[GetCharacterIndex("Skull")].Dialog.Filename = "Isenbrandt Jurcksen_dialog.c";
			Towns[GetTownIndex("Quebradas Costillas")].gov = "Skull";						// PB: Set this for real
			ChangeCharacterAddress(CharacterFromID("Isenbrandt Jurcksen"), "none", "");				// PB: Just in case

			PChar.quest.Story_LandedOnKhaelRoa.win_condition.l1 = "location";
			PChar.quest.Story_LandedOnKhaelRoa.win_condition.l1.location = "KhaelRoa_port";
			PChar.quest.Story_LandedOnKhaelRoa.win_condition = "Story_LandedOnKhaelRoa";
		break;

		case "Story_LandedOnKhaelRoa":
			StorePassengers(PChar.id);

			locDisableUpdateTime = true;

			ChangeCharacterAddressGroup(CharacterFromID("danielle"), "KhaelRoa_port", "officers", "reload2_1");
			ChangeCharacterAddressGroup(CharacterFromID("Researcher"), "KhaelRoa_port", "officers", "reload2_1");
			LAi_QuestDelay("Story_IntoKhaelRoa", 2.0);

		break;

		case "Story_IntoKhaelRoa":
			LAi_SetActorType(CharacterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Temple";
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "danielle_becomes_officer", 5.0, 1.0);
		break;

		case "danielle_becomes_officer":
			AddPassenger(PChar, CharacterFromID("danielle"), 0);
			AddPassenger(PChar, CharacterFromID("researcher"), 0);
			SetOfficersIndex(PChar, 1, getCharacterIndex("Danielle"));
			SetOfficersIndex(PChar, 2, getCharacterIndex("Researcher"));
			LAi_SetOfficerType(CharacterFromID("danielle"));
			PChar.quest.danielle_on_ship = "true";
		break;

		case "researcher_becomes_officer":
			LAi_SetOfficerType(CharacterFromID("researcher"));
		break;

		case "Story_ResearcherSpeaksonKhaelRoaBeach":
			Characters[GetCharacterIndex("researcher")].dialog.CurrentNode = "Danger";
			LAi_SetActorType(CharacterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("Researcher"), PChar, "researcher_becomes_officer", 5.0, 1.0);

			Locations[FindLocation("Labirint_1")].locators_radius.goto.goto1 = 3.0;

			PChar.quest.Story_SplitInLabyrinth.win_condition.l1 = "locator";
			PChar.quest.Story_SplitInLabyrinth.win_condition.l1.location = "Labirint_1";
			PChar.quest.Story_SplitInLabyrinth.win_condition.l1.locator_group = "goto";
			PChar.quest.Story_SplitInLabyrinth.win_condition.l1.locator = "goto1";
			PChar.quest.Story_SplitInLabyrinth.win_condition = "Story_SplitInLabyrinth";
		break;

		case "Story_SplitInLabyrinth":
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_SetActorType(CharacterFromID("researcher"));
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("danielle"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("researcher"), PChar, "", 2.0);
			LAi_ActorFollow(CharacterFromID("danielle"), PChar, "Story_SplitInLabyrinth_2", 2.0);
		break;

		case "Story_SplitInLabyrinth_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("danielle"));
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Split";
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 2.0, 0);
		break;

		case "Story_DanielleWentIntoLeftPassage":
			Locations[FindLocation("KhaelRoa_port")].reload.l1.disable = 0;
			Locations[FindLocation("Temple")].reload.l3.disable = 0;
			SetCharacterRemovable(CharacterFromID("Danielle"), true);
			RemovePassenger(PChar, CharacterFromID("Danielle"));
			LAi_type_actor_Reset(CharacterFromID("researcher"));
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("researcher"));
			LAi_SetActorType(CharacterFromID("danielle"));
			characters[GetCharacterIndex("danielle")].location = "labirint1";
			LAi_ActorRunToLocator(CharacterFromID("danielle"), "goto", "goto3", "", 25.0);
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "I go to the right";
			LAi_ActorDialog(CharacterFromID("Researcher"), PChar, "player_back", 5.0, 0);
		break;

		case "Danielle_split_exit":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "First time";
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("researcher"));
			LAi_SetActorType(CharacterFromID("researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Split";
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "player_back", 2.0, 1.0);
		break;

		case "danielle_AfterGreenfordSiege_exit":
			SetOfficersIndex(PChar, 1, getCharacterIndex("Danielle"));
			SetCharacterRemovable(CharacterFromID("Danielle"), false);
			PChar.quest.danielle_on_ship = "true";
			ChangeCharacterAddress(CharacterFromID("researcher"),"Oxbay_lighthouse", "goto30");
			Characters[GetCharacterIndex("researcher")].dialog.CurrentNode = "AlreadyTranslated";
			DoQuestReloadToLocation("Oxbay_lighthouse", "Goto", "goto24", "Story_TalkWithResearcherAfterSiegeGreenford");
		break;

		case "Story_TalkWithResearcherAfterSiegeGreenford":
			PlaceCharacter(CharacterFromID("researcher"), "goto");
			LAi_SetActorType(CharacterFromID("researcher"));
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("researcher"), PChar, "Story_TalkWithResearcherAfterSiegeGreenford_2", 2.0);
		break;

		case "Story_TalkWithResearcherAfterSiegeGreenford_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "player_back", 3.0, 1.0);
		break;

		case "danielle_RepelEnglishAssault_again_exit":
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorGoToLocator(CharacterFromID("danielle"), "reload", "reload1", "", 5.0);
		break;

		case "danielle_RepelEnglishAssault_exit":
			// PB: Prevent crashes and enemy personal fort -->
			ChangeCharacterAddressGroup(CharacterFromID("Danielle"), "Oxbay", "reload", "reload_fort1");
			Characters[GetCharacterIndex("Danielle")].nation = PERSONAL_NATION;
			// PB: Prevent crashes and enemy personal fort <--
			// KK LAi_SetPlayerType(PChar);
			// KK Fort_SetCharacter(CharacterFromID("danielle"), "Oxbay", "reload", "reload_fort1");
			LAi_SetActorType(CharacterFromID("danielle"));
			//LAi_ActorRunToLocator(CharacterFromID("danielle"), "reload", "reload1", "Story_DanielleGoesToGreenfordFort", 5.0);
			LAi_ActorRunToLocator(CharacterFromID("danielle"), "reload", "reload1", "", 5.0);
			LAi_SetPlayerType(PChar);

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			SetQuestHeader("Repel_English_Attack");
			AddQuestRecord("Repel_English_Attack", 1);
			Preprocessor_Remove("Danielle");

			/*Locations[FindLocation("Greenford_tavern")].reload.l1.name = "reload1";
			Locations[FindLocation("Greenford_tavern")].reload.l1.go = "Greenford_port";
			Locations[FindLocation("Greenford_tavern")].reload.l1.emerge = "reload4";

			PChar.quest.to_suadron.win_condition.l1 = "location";
			PChar.quest.to_suadron.win_condition.l1.location = "Oxbay";
			PChar.quest.to_suadron.win_condition = "to_suadron";*/
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("oxbay",false);
		/*break;

		case "to_suadron":
			SetCrewQuantity(CharacterFromID("Waulter Tomlison"), 200);
			SetCrewQuantity(CharacterFromID("Malcolm Hart"), 650);
			SetCrewQuantity(CharacterFromID("Henry Banfield"), 650);*/

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

			PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l1 = "NPC_Death";
			PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l1.character = "Waulter Tomlison";
			PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l2 = "NPC_Death";
			PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l2.character = "Malcolm Hart";
			if(GetDifficulty() <= DIFFICULTY_MARINER)
			{
				PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3 = "NPC_Death";
				PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3.character = "Wauter Keech";
			}
			else
			{
				PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3 = "NPC_Death";
				PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l3.character = "Henry Banfield";
				PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l5 = "NPC_Death";
				PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l5.character = "Lewellyn Belt";
			}
// KK -->
			PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l4 = "SeaEnter"; //condition to allow boarding all 3 ships PW
			//PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition.l4.location = "Oxbay";
// <-- KK
			PChar.quest.Story_RepelEnglishAssaultOnGreenford.win_condition = "Story_RepelEnglishAssaultOnGreenford";

// KK -->
			QuestToSeaLogin_PrepareLoc("Oxbay", "reload", "reload_1", false);
			QuestToSeaLogin_AddGroupLoc("Story_English_Squadron", 0, "Quest_Ships", "Quest_ship_23", true);
			QuestToSeaLogin_Launch();
// <-- KK
		break;

		case "danielle_BeforeEnglishSiege_exit":
			LAi_SetHP(CharacterFromID("Blaze_CrewMember_01"), 80.0, 80.0);
			LAi_SetActorType(CharacterFromID("Blaze_CrewMember_01"));
			ChangeCharacterAddressGroup(CharacterFromID("Blaze_Crewmember_01"), "Greenford_tavern", "reload", "reload1");
/* // KK -->
// GR: made translatable, moved to case "Story_leavingOxbay", applied to all three "Blaze_Crewmember" characters
			if (CheckAttribute(PChar,"firstname"))
				Characters[GetCharacterIndex("Blaze_Crewmember_01")].name = PChar.firstname + "'s crewmember";
			else
				Characters[GetCharacterIndex("Blaze_Crewmember_01")].name = PChar.name + "'s crewmember";
// <-- KK */
			Characters[GetCharacterIndex("Blaze_Crewmember_01")].Dialog.Filename = "EnglishAttack_dialog.c";
			Characters[GetCharacterIndex("Blaze_Crewmember_01")].Dialog.CurrentNode = "First time";
			LAi_ActorDialog(CharacterFromID("Blaze_Crewmember_01"), PChar, "player_back", 2.0, 1.0);
		break;

		case "researcher_danger_wait_exit":
			SetCurrentTime(10, 0);
			SetNextWeather("Blue Sky");
			DoReloadCharacterToLocation("KhaelRoa_port", "reload", "reload2");
		break;

		case "Story_TimeToGoIntoCentralPassage":
			ChangeCharacterAddress(CharacterFromID("danielle"), "none", "");
			ChangeCharacterAddress(CharacterFromID("researcher"), "none", "");
			LAi_SetPlayerType(PChar);
			Locations[FindLocation("Treasure_Alcove")].locators_radius.goto.goto3 = 5.0;

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Into_the_temple",2); // NK
			Preprocessor_Remove("Danielle");

			PChar.quest.Story_DanielleAndResearcherAppear.win_condition.l1 = "Location";
			PChar.quest.Story_DanielleAndResearcherAppear.win_condition.l1.location = "Treasure_Alcove";
			PChar.quest.Story_DanielleAndResearcherAppear.win_condition = "Story_DanielleAndResearcherAppear";
		break;

		case "Story_DanielleAndResearcherAppear":
			ChangeCharacterAddressGroup(CharacterFromID("danielle"), "Treasure_Alcove", "officers", "reload1_1");
			ChangeCharacterAddressGroup(CharacterFromID("researcher"), "Treasure_Alcove", "officers", "reload1_2");
			AddPassenger(PChar, CharacterFromID("danielle"), 0);
			AddPassenger(PChar, CharacterFromID("researcher"), 0);

			SetOfficersIndex(PChar, 1, getCharacterIndex("Danielle"));
			SetCharacterRemovable(CharacterFromID("danielle"), false);
			PChar.quest.danielle_on_ship = "true";
			SetOfficersIndex(PChar, 2, getCharacterIndex("Researcher"));
			SetCharacterRemovable(CharacterFromID("researcher"), false);

			PChar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1 = "locator";
			PChar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1.location = "Treasure_Alcove";
			PChar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1.locator_group = "goto";
			PChar.quest.Story_DanielleAndResearcherComeCloser.win_condition.l1.locator = "goto3";
			PChar.quest.Story_DanielleAndResearcherComeCloser.win_condition = "Story_DanielleAndResearcherComeCloser";
		break;

		case "Story_DanielleAndResearcherComeCloser":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Treasure_room";

			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("danielle"), PChar, "", 3.0, 1.0);
		break;

		case "Story_ResearcherTalkInAlcove":
			LAi_SetActorType(CharacterFromID("researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Alcove_talk";
			LAi_ActorDialog(CharacterFromID("Researcher"), PChar, "", 5.0, 1.0);
		break;

		case "Story_ResearcherReadsDanielleTalks":
			LAi_ActorGoToLocator(CharacterFromID("Researcher"), "goto", "goto4", "", 30.0);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "ITakeTheStone";
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 5.0, 1.0);
		break;

		case "Story_ITakeTheStone":
			LAi_ActorRunToLocator(CharacterFromID("danielle"), "goto", "goto5", "Story_PlayTheFirstPartVideo_prepare", 15.0);
		break;

		case "Story_PlayTheFirstPartVideo_prepare":
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("danielle"), "Story_PlayTheFirstPartVideo", 15.0);
		break;

		case "Story_PlayTheFirstPartVideo":
			GiveItem2Character(PChar, "artefact");
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
			ChangeCharacterAddressGroup(CharacterFromID("Danielle"), "KhaelRoa_port", "Officers", "Reload1_1");
			ChangeCharacterAddressGroup(CharacterFromID("Researcher"), "KhaelRoa_port", "Officers", "Reload1_2");
			DoQuestReloadToLocation("KhaelRoa_port", "Reload", "Reload1", "Story_GetOnBoardOnKhaelRoa");
		break;

		case "Story_GetOnBoardOnKhaelRoa":
			RestorePassengers(PChar.id);
			LAi_type_actor_Reset(CharacterFromID("Danielle"));
			LAi_type_actor_Reset(CharacterFromID("Researcher"));

			LAi_SetPlayerType(PChar);
			LAi_SetOfficerType(CharacterFromID("danielle"));
			LAi_type_actor_Reset(CharacterFromID("Researcher"));
			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "TempleWillBlast";
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "to_the_ship_whualya", 2.0, 0);
		break;

		case "to_the_ship_whualya":
			LAi_SetOfficerType(CharacterFromID("researcher"));
			SetOfficersIndex(PChar, 3, GetCharacterIndex("Researcher"));
			Characters[GetCharacterIndex("Researcher")].Dialog.CurrentNode = "Take_Me_Home_Repeat"; // was "Home_again" but that triggers "Story_Take_Clement_Home3"
			Locations[FindLocation("KhaelRoa_port")].reload.l2.disable = 1;
//			ReStorePassengers(PChar.id);
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
//			RemoveOfficersIndex(PChar, GetCharacterIndex("researcher"));
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("blackpearl", 100, "Story_FaceTheBoss");
			Island_SetGotoEnableLocal("KhaelRoa", "reload_1", false);
			iForceDetectionFalseFlag = 1; // KK
		break;

		case "onUseArtefact":
			bMainMenuLaunchAfterVideo = true;
			PostVideoAndQuest("artefact", 100, "post_use_artefact");
			TakeItemFromCharacter(PChar, "artefact");
// KK -->
			LAi_SetCrewImmortal(CharacterFromID("Barbossa"), false);
			Character_SetAbordageEnable(CharacterFromID("Barbossa"), true);
// <-- KK
		break;

		case "post_use_artefact":
			PostEvent("DoInfoShower",100,"s","");
//			CreateEntity(&artifact, "artifact");
			LayerAddObject(SEA_REALIZE, &artifact, -1);

// KK -->
			iHP = GetCharacterShipHP(PChar);
			ipassenger = GetCompanionIndex(PChar, 1);
			if (iPassenger > 0) iHP += GetCharacterShipHP(&Characters[iPassenger]);
			ipassenger = GetCompanionIndex(PChar, 2);
			if (iPassenger > 0) iHP += GetCharacterShipHP(&Characters[iPassenger]);
			ipassenger = GetCompanionIndex(PChar, 3);
			if (iPassenger > 0) iHP += GetCharacterShipHP(&Characters[iPassenger]);
// <-- KK
			// PS -->
			//iPassenger = PChar.ship.type;
			// KK PChar.ship.hp =  GetCharacterShipHP(PChar); //ShipsTypes[iPassenger].HP;
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

			PChar.quest.Story_KillTheFinalBoss.win_condition.l1 = "NPC_Death";
			PChar.quest.Story_KillTheFinalBoss.win_condition.l1.character = "Barbossa";
// KK -->
			PChar.quest.Story_KillTheFinalBoss.win_condition.l2 = "location";
			PChar.quest.Story_KillTheFinalBoss.win_condition.l2.location = "KhaelRoa";
// <-- KK
			PChar.quest.Story_KillTheFinalBoss.win_condition = "Story_KillTheFinalBoss";
		break;

		case "Story_KillTheFinalBoss":
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Into_the_temple",6); // SA
			Preprocessor_Remove("Danielle");
			iForceDetectionFalseFlag = 0; // KK
			if (CheckAttribute(PChar, "HaveArtefact")) DeleteAttribute(PChar, "HaveArtefact"); // KK
			bQuestDisableMapEnter = false;
			SetCharacterRemovable(CharacterFromID("Danielle"), true);
			SetCharacterRemovable(CharacterFromID("researcher"), true);
			// PB: Trigger video only on the worldmap to allow capturing the Black Pearl -->
			// DoQuestCheckDelay("Story_KillTheFinalBoss_2", 5.0);
			PChar.quest.Story_KillTheFinalBoss_2.win_condition.l1 = "SeaEnter"; // Levis
			PChar.quest.Story_KillTheFinalBoss_2.win_condition = "Story_KillTheFinalBoss_2";
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

			PChar.quest.Story_Take_Clement_Home.win_condition.l1 = "location";
			PChar.quest.Story_Take_Clement_Home.win_condition.l1.location = "Oxbay_Lighthouse";
			PChar.quest.Story_Take_Clement_Home.win_condition = "Story_Take_Clement_Home";
			PChar.quest.Story_Take_Clement_Home.fail_condition = "Story_Take_Clement_Home";
//			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "Home_again";
//			Characters[GetCharacterIndex("danielle")].Dialog.CurrentNode = "Clement_home";

			// KK: Swap cursed Pearl with normal Pearl -->
			if (GetCharacterShipID(PChar) == SHIP_CURSED) GiveShip2Character(PChar, "BlackPearl", TranslateString("","Black Pearl"), -1, PIRATE, true, true);
			iPassenger = GetCompanionIndex(PChar, 1);
			if (iPassenger > 0 && GetCharacterShipID(&Characters[iPassenger]) == SHIP_CURSED) GiveShip2Character(&Characters[iPassenger], "BlackPearl", TranslateString("","Black Pearl"), -1, PIRATE, true, true);
			iPassenger = GetCompanionIndex(PChar, 2);
			if (iPassenger > 0 && GetCharacterShipID(&Characters[iPassenger]) == SHIP_CURSED) GiveShip2Character(&Characters[iPassenger], "BlackPearl", TranslateString("","Black Pearl"), -1, PIRATE, true, true);
			iPassenger = GetCompanionIndex(PChar, 3);
			if (iPassenger > 0 && GetCharacterShipID(&Characters[iPassenger]) == SHIP_CURSED) GiveShip2Character(&Characters[iPassenger], "BlackPearl", TranslateString("","Black Pearl"), -1, PIRATE, true, true);
			// KK: Swap cursed Pearl with normal Pearl <--

			Reinit_KhaelRoa();							// Enable Khael Roa as personal base
			LAi_group_SetLookRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_LOOK);	// GR: restore monsters to normal detection radius, increased at "monster_generate_in_alcove"
			LAi_group_SetHearRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_HEAR);
			LAi_group_SetSayRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_SAY);
			LAi_QuestDelay("end_game2", 1.0);					// originally triggered by dialog with Danielle after taking Clement to lighthouse
		break;

		case "end_game2":
// KK -->
			PChar.quest.Story_AfterFinalOnRedmond1.win_condition.l1 = "location";
			PChar.quest.Story_AfterFinalOnRedmond1.win_condition.l1.location = "Redmond_port";
			PChar.quest.Story_AfterFinalOnRedmond1.win_condition = "Story_AfterFinalOnRedmond2";
			PChar.quest.Story_AfterFinalOnRedmond1.fail_condition = "Story_AfterFinalOnRedmond2";
// <-- KK

			PChar.quest.Story_AfterFinalOnRedmond2.win_condition.l1 = "location";
			PChar.quest.Story_AfterFinalOnRedmond2.win_condition.l1.location = "Redmond_shore_02";
			PChar.quest.Story_AfterFinalOnRedmond2.win_condition = "Story_AfterFinalOnRedmond2";
			PChar.quest.Story_AfterFinalOnRedmond2.fail_condition = "Story_AfterFinalOnRedmond2";

			PChar.quest.Story_AfterFinalOnRedmond3.win_condition.l1 = "location";
			PChar.quest.Story_AfterFinalOnRedmond3.win_condition.l1.location = "Redmond_shore_01";
			PChar.quest.Story_AfterFinalOnRedmond3.win_condition = "Story_AfterFinalOnRedmond2";
			PChar.quest.Story_AfterFinalOnRedmond3.fail_condition = "Story_AfterFinalOnRedmond2";
			Characters[GetCharacterIndex("danielle")].Dialog.CurrentNode = "After_Final2";	  // <-- Cat for Danielle fix
		break;

		case "remove_officers_from_blaze_in_redmond_complete":
			characters[GetCharacterIndex("Eng_soldier_5")].dialog.currentnode = "do_not_go";
			LAi_ActorDialogNow(CharacterFromID("Eng_soldier_5"), PChar, "", -1);
		break;

		//Выходим от губернатора
		case "exit_from_silehard_complete":
			PChar.quest.main_line = "talk_in_tavern_begin";
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 7000); }
			else { AddPartyExp(PChar, 7000); }
			LAi_SetImmortal(CharacterFromID("Danielle"), true);
			// KK Group_SetAddress("Story_French_Squadron", "none", "Quest_Ships","Quest_Ship_7");
			Group_SetAddressNone("Story_French_Squadron"); // KK
			Group_DeleteGroup("Story_French_Squadron"); // KK

			LAi_SetStayType(CharacterFromID("danielle"));
			LAi_SetStayType(CharacterFromID("ralph fawn"));
			LAi_group_MoveCharacter(CharacterFromID("danielle"), LAI_GROUP_PLAYER);
			LAi_group_MoveCharacter(CharacterFromID("ralph fawn"), LAI_GROUP_PLAYER);

			locations[FindLocation("Redmond_town_01")].reload.l11.go = "quest_redmond_tavern"; // GR: Moved here from "Story_BlazeEscapedFromOxbay"
			ChangeCharacterAddress(CharacterFromID("Danielle"), "Quest_redmond_tavern", "goto2");
			ChangeCharacterAddress(CharacterFromID("Ralph Fawn"), "Quest_redmond_tavern", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Charles Windem"), "Quest_redmond_tavern", "merchant", "goto1");
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

			PChar.quest.to_quest_redmond_tavern.win_condition.l1 = "location";
			PChar.quest.to_quest_redmond_tavern.win_condition.l1.location = "Quest_Redmond_tavern";
			PChar.quest.to_quest_redmond_tavern.win_condition = "to_quest_redmond_tavern_complete";
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
			LAi_SetActorType(PChar);

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

			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_SetActorType(CharacterFromID("ralph fawn"));

			LAi_group_MoveCharacter(CharacterFromID("soldier2"), "ENGLAND_TAVERN_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("soldier3"), "ENGLAND_TAVERN_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("soldier4"), "ENGLAND_TAVERN_SOLDIERS");


			LAi_ActorTurnToCharacter(PChar, CharacterFromID("soldier1"));
			LAi_ActorTurnToCharacter(CharacterFromID("Danielle"), CharacterFromID("soldier1"));
			LAi_ActorTurnToCharacter(CharacterFromID("Ralph Fawn"), CharacterFromID("soldier1"));

			LAi_ActorDialog(CharacterFromID("soldier1"), PChar, "", 5.0, 0);
			LAi_ActorWaitDialog(PChar, CharacterFromID("soldier1"));
		break;

		//солдат в таверне бьет нас по мордe
		case "kicked_by_soldier_complete":
			LAi_ActorAnimation(CharacterFromID("soldier1"), "attack_fast_2", "kicked_by_soldier_2_complete", 0.5);
		break;

		case "kicked_by_soldier_2_complete":
			LAi_ActorAnimation(PChar, "hit_2", "kicked_by_soldier_3_complete", 1.5);
		break;

		case "kicked_by_soldier_3_complete":
			PChar.quest.main_line = "after_soldier_kick";
			//LAi_SetPlayerType(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("soldier1"));
			LAi_ActorDialogNow(CharacterFromID("soldier1"), PChar, "", -1);
		break;

		case "fighting_in_tavern":
			LAi_SetPlayerType(PChar);
			locCameraFollow();
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_redmond_tavern")], false);
			LAi_SetWarriorType(CharacterFromID("soldier1"));
			LAi_group_MoveCharacter(CharacterFromID("soldier1"), "ENGLAND_TAVERN_SOLDIERS");

			LAi_SetHP(CharacterFromID("Ralph Fawn"), 1.0, 1.0);

			LAi_SetOfficerType(CharacterFromID("danielle"));
			LAi_SetOfficerType(CharacterFromID("ralph fawn"));
			LAi_group_FightGroups("ENGLAND_TAVERN_SOLDIERS", LAI_GROUP_PLAYER, true);
			//трактирщик убегает в обычную (не квестовую таверну)
			LAi_SetActorType(CharacterFromID("Charles Windem"));
			LAi_ActorRunToLocator(CharacterFromID("Charles Windem"), "merchant", "reload2", "Charles_escape_from_quest_redmond_tavern_complete", -1);
			LAi_group_SetCheck("ENGLAND_TAVERN_SOLDIERS", "out_from_quest_tavern_complete");
			LAi_QuestDelay("ralph_fawn_death_complete", 6.0);
		break;

		case "ralph_fawn_death_complete":
			LAi_KillCharacter(CharacterFromID("ralph fawn"));
		break;

		//смерть всех солдат в таверне
		case "out_from_quest_tavern_complete":
			LAi_LocationFightDisable(&Locations[FindLocation("Quest_redmond_tavern")], true);
			PChar.quest.main_line = "fawn_death";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
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
			LAi_setActorType(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("danielle"));
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "player_back", 3.0, 1.0);
		break;

		//Даниель убегает из таверны, оставляя там Блейза
		case "danielle_escape_from_quest_redmond_tavern_complete":
			//убираем Даниель
			ChangeCharacterAddress(CharacterFromID("Danielle"), "none", "none");
			LAi_QuestDelay("danielle_escape_from_quest_redmond_tavern_2_complete", 1.0);
		break;

		case "danielle_escape_from_quest_redmond_tavern_2_complete":
			LAi_SetStayType(PChar);

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
			LAi_ActorDialog(sld, PChar, "player_back", 8.0, 2.0);


			locx = stf(loadedLocation.locators.camera.locator12.x);
			locy = stf(loadedLocation.locators.camera.locator12.y);
			locz = stf(loadedLocation.locators.camera.locator12.z);
			locCameraToPos(locx, locy, locz, false);
		break;

		//трактирщик убегает из квестовой таверны
		case "Charles_escape_from_quest_redmond_tavern_complete":
			//убираем трактирщика
			ChangeCharacterAddressGroup(CharacterFromID("Charles Windem"), "Redmond_Tavern", "merchant", "goto1");
			LAi_SetMerchantType(CharacterFromID("Charles Windem"));
		break;

		case "Blaze_to_prison_complete":
			RemoveCharacterEquip(PChar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(PChar, GUN_ITEM_TYPE);
			EnableEquip(PChar, BLADE_ITEM_TYPE, false);
			EnableEquip(PChar, GUN_ITEM_TYPE, false);
			StorePassengers("Blaze");

			DoQuestReloadToLocation("Redmond_prison", "goto", "goto9", "prepare_Edgar_to_Blaze_complete");
		break;

		case "prepare_Edgar_to_Blaze_complete":
			LAi_SetActorType(CharacterFromID("Edgar Attwood"));

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Blaze_out_from_silehard", 3);
			CloseQuestHeader("Blaze_out_from_silehard");
			Preprocessor_Remove("Danielle");
			SetQuestHeader("Blaze_in_prison");
			AddQuestRecord("Blaze_in_prison", 1);
			//Выключаем выход из тюрьмы
			locations[FindLocation("Redmond_prison")].reload.l1.disable = 1;
			//говорим подойти Эдгару к блейзу и начать разговор
			LAi_ActorGoToLocator(CharacterFromID("Edgar Attwood"), "goto", "goto23", "Edgar_to_Blaze_complete", -1);
			//включаем обычную таверну
			locations[FindLocation("Redmond_town_01")].reload.l11.go = "Redmond_tavern";
			//на всякий случай еще раз передвигаем трактирщика
			ChangeCharacterAddressGroup(CharacterFromID("Charles Windem"), "Redmond_Tavern", "merchant", "goto1");
		break;

		//Эдгар подходит к блейзу
		case "Edgar_to_Blaze_complete":
			locx = stf(loadedLocation.locators.camera.camera13.x);
			locy = stf(loadedLocation.locators.camera.camera13.y);
			locz = stf(loadedLocation.locators.camera.camera13.z);
			locCameraToPos(locx, locy, locz, false);

			PChar.quest.main_line = "prison";
			LAi_ActorDialogNow(CharacterFromID("Edgar Attwood"), PChar, "", -1);
			PChar.quest.edgar_life = "live";

			PChar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1 = "locator";
			PChar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1.location = "Redmond_prison";
			PChar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1.locator_group = "merchant";
			PChar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition.l1.locator = "reload13";
			PChar.quest.to_locator_where_soldiers_in_prison_see_you.win_condition = "to_locator_where_soldiers_in_prison_see_you_complete";
		break;

		//Эдгар отходит от камеры
		case "wait_for_night_in_prison_complete":
			PChar.quest.main_line = "inside_redmond_prison";
			ChangeCharacterAddressGroup(CharacterFromID("Robert Christopher Silehard"), "Redmond_Prison", "merchant", "reload13");
			LAi_SetActorType(CharacterFromID("Robert Christopher Silehard"));
			LAi_ActorGoToLocator(CharacterFromID("Robert Christopher Silehard"), "goto", "goto23", "Silehard_to_blaze_complete", -1);
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "escape_from_prison_node_2";
			LAi_Fade("", "");
		break;

		case "prepare_exit_from_cam":
			LAi_Fade("blaze_exit_from_cam_complete", "second_speak_with_edgar_complete");
		break;

		//Блейз выходит из камеры
		case "blaze_exit_from_cam_complete":
			EnableEquip(PChar, BLADE_ITEM_TYPE, true);
			EnableEquip(PChar, GUN_ITEM_TYPE, true);
			EquiPCharacterByItem(PChar, FindCharacterItemByGroup(PChar, BLADE_ITEM_TYPE));
			EquiPCharacterByItem(PChar, FindCharacterItemByGroup(PChar, GUN_ITEM_TYPE));
			//ставим Эдгара рядом с блейзом
			locCameraFollow();
			ChangeCharacterAddress(PChar, "Redmond_prison", "goto12");
			PChar.quest.main_line = "escape_from_redmond_prison";
			ChangeCharacterAddress(CharacterFromID("Edgar Attwood"), "redmond_prison", "goto23");
			//даем квест на убийство всех стражников в тюрьме
			PChar.quest.kill_all_soldiers_in_prison.win_condition.l1 = "NPC_Death";
			PChar.quest.kill_all_soldiers_in_prison.win_condition.l1.character = "Eng_soldier_35";
			PChar.quest.kill_all_soldiers_in_prison.win_condition.l2 = "NPC_Death";
			PChar.quest.kill_all_soldiers_in_prison.win_condition.l2.character = "Eng_soldier_36";
			PChar.quest.kill_all_soldiers_in_prison.win_condition = "kill_all_soldiers_in_prison_complete";
			//продолжаем разговор, где говорим, что нужно убить солдат на выходе.
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "escape_from_prison_node";
			//временно прячем губернатора
			ChangeCharacterAddress(CharacterFromID("Robert Christopher Silehard"), "none", "none");
			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], false);
		break;

		case "kill_edgard_in_prison_2_complete":
			if (PChar.location == "redmond_prison")
			{
				LAi_SetPlayerType(PChar);
				PChar.quest.edgar_life = "death";
				AddQuestRecord("Blaze_in_prison", 4);
				//солдаты слышат шум и идут воевать игрока.
				LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				OfficersReaction("bad");
			}
		break;

		case "second_speak_with_edgar_complete":
			LAi_ActorDialog(CharacterFromID("Edgar Attwood"), PChar, "", 1.0, 1.0);
		break;

		//сайлхард подходит к блейзу
		case "Silehard_to_Blaze_complete":
			LAi_SetCitizenType(CharacterFromID("Edgar Attwood"));
			LAi_ActorDialogNow(CharacterFromID("Robert Christopher Silehard"), PChar, "", -1);
		break;

		case "exit_from_prison":
			PChar.quest.to_locator_where_soldiers_in_prison_see_you.over = "yes";
			locCameraFollow();
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			ChangeCharacterAddress(CharacterFromID("Robert Christopher Silehard"), "redmond_residence", "goto8");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "main_line_find_rheims_node";
			PChar.quest.main_line = "blaze_talk_with_silehard";
			DoQuestReloadToLocation("redmond_residence", "goto", "goto3", "blaze_from_prison_to_residence_complete");
			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], true);
			EnableEquip(PChar, BLADE_ITEM_TYPE, true);
			EnableEquip(PChar, GUN_ITEM_TYPE, true);
			EquiPCharacterByItem(PChar, FindCharacterItemByGroup(PChar, BLADE_ITEM_TYPE));
			EquiPCharacterByItem(PChar, FindCharacterItemByGroup(PChar, GUN_ITEM_TYPE));
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
			PChar.quest.kill_edgar_attwood_in_prison.over = "yes";
			PChar.quest.to_locator_where_soldiers_in_prison_see_you.over = "yes";
			locations[FindLocation("Redmond_prison")].reload.l1.disable = 0;
			LAi_SetHuberStayType(CharacterFromID("Robert Christopher Silehard"));
			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Robert Christopher Silehard"), "player_back", 2.0, 1.0);
			ChangeCharacterAddress(CharacterFromID("Eng_soldier_35"), "redmond_prison", "goto16");
			ChangeCharacterAddress(CharacterFromID("Eng_soldier_36"), "redmond_prison", "goto14");
			ChangeCharacterAddressGroup(CharacterFromID("Redmond prison commendant"), "redmond_prison", "sit", "sit1");

			DeleteAttribute(PChar, "Quest.Story_OxbayCaptured");
			// KK SetTownNation("Oxbay", ENGLAND);
			CaptureTownForNation("Oxbay", ENGLAND); // KK
		//	DeleteAttribute(CharacterFromID("Oxbay Commander"), "recognized"); // PB: Added to 'CaptureTownForNation' function itself
			//Смена национальности форта Оксбэя
			// KK Characters[GetCharacterIndex("Oxbay Commander")].nation = ENGLAND;
			// KK Characters[GetCharacterIndex("Oxbay Commander")].model = "Soldier_Eng";
			//Смена французских солдат в Оксбэе на английских
			//Удаление французских

			//Убирание из гавани Оксбэя кораблей французской эскадры
			Group_SetAddress("Story_French_Squadron", "none", "Quest_Ships","Quest_Ship_7");
			Group_DeleteGroup("Story_French_Squadron"); // KK
			LAi_SetImmortal(CharacterFromID("FalaiseDeFleur Commander"), false);
			LAi_SetImmortal(CharacterFromID("Oxbay Commander"), false);

			// Why are we doing this??? No reason for France to _like_ you...05-03-26 if(GetRMRelation(PChar, FRANCE) < REL_AMNESTY) RMAmnesty(PChar, FRANCE); // NK fix 05-03-26 SetRMRelation(PChar, FRANCE, REL_AMNESTY); // RM - SetNationRelation2MainCharacter(FRANCE, RELATION_NEUTRAL);
			RestorePassengers("Blaze"); // TIH why was this removed? players never get their passengers back then...
			//ChangeCharacterAddress(CharacterFromID("Guy Gilroy"), "Oxbay_HouseInsideR9", "sit1"); // NK 05-07-20
		break;

		case "back_to_hovernor_type":
// KK -->
			  ChangeCharacterAddress(CharacterFromID("Counterspy"), "Redmond_town_01", "goto54");
			  ChangeCharacterAddress(CharacterFromID("Rabel Iverneau"), "Redmond_town_01", "goto55");
// <-- KK
			characters[GetCharacterIndex("Counterspy")].location = "none";
			characters[GetCharacterIndex("Rabel Iverneau")].location = "none";
			LAi_SetHuberStayType(CharacterFromID("Robert Christopher Silehard"));
		break;

		//убить всех солдат в тюрьме
		case "kill_all_soldiers_in_prison_complete":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			//появления губернатора со стражниками и начало разговора
			LAi_QuestDelay("Silehard_in_prison_complete", 3.0);
		break;

		case "silehard_in_prison_complete":
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Robert Christopher Silehard"));
			LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], true);
			LAi_SetActorType(CharacterFromID("Robert Christopher Silehard"));
			ChangeCharacterAddressGroup(CharacterFromID("Robert Christopher Silehard"), "Redmond_Prison", "reload", "reload1");
			LAi_ActorDialog(CharacterFromID("Robert Christopher Silehard"), PChar, "", 5.0, 0);
		break;

		//блейз достигает локатора в тюрьме, за которым его видят стражники
		case "to_locator_where_soldiers_in_prison_see_you_complete":
			if (PChar.quest.main_line == "escape_from_redmond_prison")
			{
				LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
				//Убираем сидящего солдата
				ChangeCharacterAddress(CharacterFromID("Redmond prison commendant"), "none", "none");
			}
		break;

		case "exit_from_silehard_2_complete":
			ChangeCharacterAddress(CharacterFromID("Edgar Attwood"), "redmond_port", "goto_2");
			LAi_SetActorType(CharacterFromID("Edgar Attwood"));
			LAi_ActorDialog(CharacterFromID("Edgar Attwood"), PChar, "", 3.0, 1.0);
		break;

		//появление мужика, дающего информацию о местонахождении реймса
		case "ines_denied_exit_from_tavern_complete":
			PChar.quest.kill_pirate_for_rheims_lore.win_condition.l1 = "NPC_death";
			PChar.quest.kill_pirate_for_rheims_lore.win_condition.l1.character = "quest_pirate_01";
			PChar.quest.kill_pirate_for_rheims_lore.win_condition = "kill_pirate_for_rheims_lore_complete";
			LAi_SetHP(CharacterFromID("quest_pirate_01"), 80.0, 80.0);
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "QC_town", "goto12");
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("quest_pirate_01"));
			LAi_ActorFollow(PChar, CharacterFromID("quest_pirate_01"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("quest_pirate_01"), PChar, "ines_denied_exit_from_tavern_complete_2", 2.0);
		break;

		case "ines_denied_exit_from_tavern_complete_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("quest_pirate_01"));
			LAi_ActorDialog(CharacterFromID("quest_pirate_01"), PChar, "quest_pirate_01_back_to_player", 1.0, 1.0);
		break;

		case "quest_pirate_ines_info_denied_6":
			PChar.quest.main_line = "blaze_talk_with_innes_diaz_complete";
			AddQuestRecord("Blaze_search_Rheims", 4);
			locations[FindLocation("QC_town")].reload.l3.disable = 0;
			PChar.quest.kill_pirate_for_rheims_lore.over = "yes";
			LAi_SetCitizenType(CharacterFromID("quest_pirate_01"));
		//	DeleteAttribute(&PChar,"vcskip"); // NK 04-08
			DeleteAttribute(&Locations[FindLocation("QC_town")],"vcskip"); // PB
			DisableFastTravel(false); // PB
		break;

		case "quest_pirate_01_back_to_player":
			LAi_SetPlayerType(PChar);
		break;

		case "fight_with_quest_pirate_after_ines_denied":
			LAi_group_MoveCharacter(CharacterFromID("quest_pirate_01"), "QC_BRODYAGA");
			LAi_group_FightGroups("QC_BRODYAGA", LAI_GROUP_PLAYER, true);
			//LAi_ActorAttack(CharacterFromID("quest_pirate_01"), PChar, "");
		break;

		case "kill_pirate_for_rheims_lore_complete":
			AddQuestRecord("Blaze_search_Rheims", 13);
			PChar.quest.main_line = "blaze_talk_with_innes_diaz_complete_21";
			//возраждаем пирата для следующих сценок
			characters[getCharacterIndex("quest_pirate_01")].location = "none";
			LAi_SetCurHP(CharacterFromID("quest_pirate_01"), 80.0);

			Locations[FindLocation("QC_town")].reload.l3.disable = 0;

			OfficersReaction("bad");
			DeleteAttribute(&PChar,"vcskip"); // NK 04-08
		break;

		//говорим контрабандистам отвести блейза к камило мачадо
		case "exit_from_duarte_complete":
			PlaceCharacter(CharacterFromID("quest_smuggler_01"), "goto");

			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("quest_smuggler_01"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("quest_smuggler_01"), PChar, "exit_from_duarte_complete_2", 2.0);
		break;

		case "exit_from_duarte_complete_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("quest_smuggler_01"));
			Locations[FindLocation("Smugglers_residence")].reload.l1.disable = 1;
			LAi_ActorDialog(CharacterFromID("quest_smuggler_01"),  PChar, "player_back", 5.0, 1.0);
		break;

		//первый раз попадаем в дом к Мачадо
		case "blaze_first_speak_with_beltrop_complete":
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 1;
			Locations[FindLocation("Rheims_house_in_smugglers")].vcskip = true; // NK
			Locations[FindLocation("Conceicao_town")].reload.l3.disable = 0;
			PChar.quest.main_line = "blaze_talk_with_beltrop";
			LAi_SetActorType(CharacterFromID("Desmond Ray Beltrop"));
			LAi_ActorDialog(CharacterFromID("Desmond Ray Beltrop"), PChar, "beltrop_back_to_hovernor_type", 50, 0);

		// "Night Craft" quest trigger
			PChar.quest.smuggler_line_begin.win_condition.l1 = "location";
			PChar.quest.smuggler_line_begin.win_condition.l1.location = "redmond_town_01";
			PChar.quest.smuggler_line_begin.win_condition = "smuggler_line_begin";
		break;

		case "beltrop_back_to_hovernor_type":
			if (GetTime() >= 22.0 || GetTime() <= 6.0)
			{
				PChar.quest.main_line = "night_for_rheims_house_complete";
				Locations[FindLocation("Smugglers_Lair")].reload.l6.disable = 0;
			}
			LAi_SetHuberStayType(CharacterFromID("Desmond Ray Beltrop"));
			LAi_group_MoveCharacter(CharacterFromID("Desmond Ray Beltrop"), "SMUGGLERS_CITIZENS");
		break;

		//блейз ждал ночи в таверне
		case "wait_for_night_complete":
			//включаем ночь.
			PChar.quest.main_line = "night_for_rheims_house_complete";
			Locations[FindLocation("Smugglers_Lair")].reload.l6.disable = 0;
			AddQuestrecord("Blaze_search_Rheims", 8);
		break;

		//блейз ждет ночи в комнате
		case "wait_for_night_in_room_complete":
			PChar.quest.main_line = "night_for_rheims_house";
		break;

		//Блейз пробрался в дом Реймса
		case "blaze_to_rheims_house_in_smugglers_complete":
			LAi_QuestDelay("blaze_to_rheims_house_in_smugglers_find_book_complete", 2.0);
		break;

		//Блейз нашел книгу.
		case "blaze_to_rheims_house_in_smugglers_find_book_complete":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto2", "blaze_to_rheims_house_in_smugglers_find_book_complete_2", 2.0);
		break;

		case "blaze_to_rheims_house_in_smugglers_find_book_complete_2":
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "blaze_return_to_silehard_node";
			PChar.quest.main_line = "blaze_found_book_in_rheims_house";
			//Добавляем предмет
			GiveItem2Character(PChar, "rheims_journal");
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "blaze_fight_in_rheims_house_complete":
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
			if (LAi_IsDead(CharacterFromID("Macario Regalo")) && LAi_IsDead(CharacterFromID("Evaristo Filho")))
			{
				//появляем других стражников
				ChangeCharacterAddressGroup(CharacterFromID("Fernam  Barrios"), "Rheims_house_in_smugglers", "reload", "reload1");
				ChangeCharacterAddressGroup(CharacterFromID("Leborio Violate"), "Rheims_house_in_smugglers", "reload", "reload1");
				LAi_SetActorType(CharacterFromID("Leborio Violate"));
				LAi_ActorFollow(PChar, CharacterFromID("Leborio Violate"), "", 1.0);
				LAi_ActorFollow(CharacterFromID("Leborio Violate"), PChar, "blaze_fight_in_rheims_house_complete_2", 1.0);
			}
			else
			{
				//появляем стражников у дома реймса
				ChangeCharacterAddressGroup(CharacterFromID("Macario Regalo"), "Rheims_house_in_smugglers", "reload", "reload1");
				ChangeCharacterAddressGroup(CharacterFromID("Evaristo Filho"), "Rheims_house_in_smugglers", "reload", "reload1");
				LAi_SetActorType(CharacterFromID("Evaristo Filho"));
				LAi_ActorFollow(PChar, CharacterFromID("Evaristo Filho"), "", 1.0);
				LAi_ActorFollow(CharacterFromID("Evaristo Filho"), PChar, "blaze_fight_in_rheims_house_complete_3", 1.0);
			}
		break;

		case "blaze_fight_in_rheims_house_complete_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Leborio Violate"));
			LAi_ActorDialog(CharacterFromID("Leborio Violate"), PChar, "back_to_smuggler_guard", 3.0, 0);
		break;

		case "blaze_fight_in_rheims_house_complete_3":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Evaristo Filho"));
			LAi_ActorDialog(CharacterFromID("Evaristo Filho"), PChar, "back_to_smuggler_guard", 3.0, 0);
		break;

		case "back_to_smuggler_guard":
			Lai_SetPlayerType(PChar);
			LAi_group_MoveCharacter(CharacterFromID("Leborio Violate"), "SMUGGLERS_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Evaristo Filho"), "SMUGGLERS_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Fernam  Barrios"), "SMUGGLERS_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Macario Regalo"), "SMUGGLERS_SOLDIERS");
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SMUGGLERS_SOLDIERS", "kill_guards_in_rheims_house_smugglers_complete");
			DeleteAttribute(&Locations[FindLocation("Rheims_house_in_smugglers")],"vcskip"); // NK
		break;

		//блейз убивает стражников
		case "kill_guards_in_rheims_house_smugglers_complete":
			if (PChar.location == "Rheims_house_in_smugglers")
			{
				LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
				AddQuestrecord("Blaze_search_Rheims", 9);
				PChar.quest.main_line = "blaze_return_to_silehard";
				Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
			}
			else
			{
				AddQuestrecord("Blaze_search_Rheims", 10);
				Locations[FindLocation("Smugglers_Lair")].reload.l5.disable = 0;
			}
			LAi_SetHP(CharacterFromID("quest_pirate_01"), 80.0, 80.0);
		break;

		//блейз убивает стражников
		case "kill_guards_in_rheims_house_smugglers_2_complete":
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			AddQuestrecord("Blaze_search_Rheims", 9);
			PChar.quest.main_line = "blaze_return_to_silehard";
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
		break;

		case "Friedrich_Corleis_go_away":
			LAi_SetActorType(CharacterFromID("Friedrich Corleis"));
			LAi_ActorGoToLocator(CharacterFromID("Friedrich Corleis"), "Merchant", "reload3", "blaze_to_incas_collection_begin_1_complete", -1);
		break;

		//Трактирщик на Дувезене уходит за пиратом
		case "blaze_to_incas_collection_begin_1_complete":
			ChangeCharacterAddress(CharacterFromID("Friedrich Corleis"), "none", "");
			LAi_QuestDelay("wait_for_pirate_in_tavern_complete", 2.0);
		break;

		case "wait_for_pirate_in_tavern_complete":
			RestoreCharacter(CharacterFromID("quest_pirate_01")); // KK
			LAi_SetHP(CharacterFromID("quest_pirate_01"), 80.0, 80.0);
			Lai_SetActorType(CharacterFromID("quest_pirate_01"));
			characters[GetCharacterIndex("quest_pirate_01")].model = "corsair2";
			characters[GetCharacterIndex("quest_pirate_01")].headmodel = "h_corsair2";
			characters[GetCharacterIndex("quest_pirate_01")].dialog.currentnode = "First time"; // CTM
			ChangeCharacterAddressGroup(CharacterFromID("quest_pirate_01"), "Douwesen_tavern", "reload", "reload1");
			LAi_ActorDialog(CharacterFromID("quest_pirate_01"), PChar, "", 2.0, 1.0);
		break;

		case "teleport_to_douwesen_exit":
			LAi_SetCheckMinHP(CharacterFromID("quest_pirate_01"), LAi_GetCharacterHP(CharacterFromID("quest_pirate_01"))-1.0, false, "quest_pirate_01_exit_with_fight"); // KK
			ChangeCharacterAddressGroup(CharacterFromID("Friedrich Corleis"), "Douwesen_tavern", "merchant", "goto1");
			LAi_SetMerchantType(CharacterFromID("Friedrich Corleis"));
			DoQuestReloadToLocation("Douwesen_town_exit", "goto", "goto10", "incas_collection_to_douwesen_town_exit");
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "Douwesen_town_exit", "goto11");
			StorePassengers(PChar.id);
			LAi_SetMerchantType(CharacterFromID("Friedrich Corleis"));
			PChar.quest.return_officers_in_ship_location.win_condition.l1 = "location";
			PChar.quest.return_officers_in_ship_location.win_condition.l1.location = PChar.location.from_sea;
			PChar.quest.return_officers_in_ship_location.win_condition = "return_officers_in_ship_location";
		break;

		case "return_officers_in_ship_location":
			reStorePassengers(PChar.id);
		break;

		//пират объясняет нам как попасть в логово пиратов
		case "incas_collection_to_douwesen_town_exit":
			LAi_ActorDialog(CharacterFromID("quest_pirate_01"), PChar, "", 2.0, 1.0);
		break;

		case "prepare_go_to_pirate_fort_complete":
			PChar.quest.main_line = "blaze_to_incas_collection_begin_3";
			PChar.quest.go_to_pirate_fort.win_condition.l1 = "location";
			PChar.quest.go_to_pirate_fort.win_condition.l1.location = "Douwesen_jungle_03";
			PChar.quest.go_to_pirate_fort.win_condition = "go_to_pirate_fort_complete";
			LAi_ActorRunToLocator(CharacterFromID("quest_pirate_01"), "reload", "reload1_back", "", 90.0);
		break;

		case "go_to_pirate_fort_complete":
			LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "Douwesen_jungle_03", "citizen09");
			LAi_ActorRunToLocator(CharacterFromID("quest_pirate_01"), "reload", "reload3_back", "", 90.0);
			PChar.quest.go_to_pirate_fort1.win_condition.l1 = "location";
			PChar.quest.go_to_pirate_fort1.win_condition.l1.location = "Douwesen_jungle_02";
			PChar.quest.go_to_pirate_fort1.win_condition = "go_to_pirate_fort1_complete";
		break;

		case "go_to_pirate_fort1_complete":
			LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
			ChangeCharacterAddressGroup(CharacterFromID("quest_pirate_01"), "Douwesen_jungle_02", "reload", "reload3");
			LAi_ActorRunToLocator(CharacterFromID("quest_pirate_01"), "reload", "reload2_back", "", 90.0);
			PChar.quest.go_to_pirate_fort2.win_condition.l1 = "location";
			PChar.quest.go_to_pirate_fort2.win_condition.l1.location = "Douwesen_jungle_01";
			PChar.quest.go_to_pirate_fort2.win_condition = "go_to_pirate_fort2_complete";
		break;

		case "go_to_pirate_fort2_complete":
			LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "Douwesen_jungle_01", "citizen08");
			LAi_ActorRunToLocator(CharacterFromID("quest_pirate_01"), "reload", "reload1_back", "", 90.0);
			PChar.quest.go_to_pirate_fort3.win_condition.l1 = "location";
			PChar.quest.go_to_pirate_fort3.win_condition.l1.location = "Pirate_Fort";
			PChar.quest.go_to_pirate_fort3.win_condition = "go_to_pirate_fort3_complete";
		break;

		case "go_to_pirate_fort3_complete":
			PChar.quest.main_line = "blaze_to_incas_collection_begin_4";
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "Pirate_fort", "goto17");
			if (!LAi_isDead(CharacterFromID("quest_pirate_01")))
			{
				LAi_type_actor_Reset(CharacterFromID("quest_pirate_01"));
				LAi_SetActorType(PChar);
				LAi_ActorFollow(PChar, CharacterFromID("quest_pirate_01"), "", 2.0);
				LAi_ActorFollow(CharacterFromID("quest_pirate_01"), PChar, "go_to_pirate_fort4_complete", 2.0);
			}
			else
			{
				if (CalcCharacterSkill(PChar, SKILL_SNEAK) < 3)
				{
					LAi_SetActorType(CharacterFromID("Pieter Nolt"));
					LAi_SetActorType(PChar);
					LAi_ActorFollow(PChar, CharacterFromID("Pieter Nolt"), "", 3.0);
					LAi_ActorFollow(CharacterFromID("Pieter Nolt"), PChar, "speak_with_pieter_nolt", 3.0);
				}
			}
			reStorePassengers(PChar.id);
		break;

		case "speak_with_pieter_nolt":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Pieter Nolt"));
			LAi_ActorDialog(CharacterFromID("Pieter Nolt"), PChar, "pieter_nolt_back_to_soldier", 4.0, 0);
		break;

		case "go_to_pirate_fort4_complete":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("quest_pirate_01"));
			LAi_ActorDialog(CharacterFromID("quest_pirate_01"), PChar, "player_back", 1.0, 1.0);
		break;

		case "pieter_nolt_back_to_soldier":
			LAi_SetPlayerType(PChar);
			LAi_SetCivilianPatrolType(CharacterFromID("Pieter Nolt")); // PB
			LAi_group_MoveCharacter(CharacterFromID("Pieter Nolt"), "DOUWESEN_PIRATE_SOLDIERS");
		break;

		case "pirate_go_to_jungle_complete":
			ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "none", "none");
			PChar.quest.main_line = "blaze_to_incas_collection_begin_5";
		break;

		case "go_to_pirate_fort_fight_complete":
			if (!Lai_IsDead(CharacterFromID("quest_pirate_01")))
			{
				ChangeCharacterAddress(CharacterFromID("quest_pirate_01"), "Douwesen_jungle_03", "citizen01");
				LAi_ActorDialog(CharacterFromID("quest_pirate_01"), PChar, "", 2.0, 0);
				PChar.quest.go_to_pirate_fort3.win_condition.l1 = "location";
				PChar.quest.go_to_pirate_fort3.win_condition.l1.location = "Pirate_Fort";
				PChar.quest.go_to_pirate_fort3.win_condition = "go_to_pirate_fort3_complete";
			}
		break;

		case "garcilaso_fight_1":
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], false);
			AddQuestRecord("blaze_to_incas_collection", 7);
			LAi_QuestDelay("garcilaso_fight_4", 2.0);
			LAi_SetActorType(PChar);
			LAi_ActorAttack(PChar, CharacterFromID("Alistair Garcilaso"), "");
		break;

		case "garcilaso_fight_2":
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], false);
			AddQuestRecord("blaze_to_incas_collection", 15);
			LAi_SetActorType(PChar);
			LAi_ActorAttack(PChar, CharacterFromID("Alistair Garcilaso"), "");
			LAi_QuestDelay("garcilaso_fight_4", 2.0);
		break;

		case "garcilaso_fight_3":
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], false);
			LAi_SetActorType(PChar);
			LAi_ActorAttack(PChar, CharacterFromID("Alistair Garcilaso"), "");
			LAi_QuestDelay("garcilaso_fight_4", 2.0);
			GiveItem2Character(PChar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			PChar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 14);
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle_sailor")], "none", "none");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "garcilaso_fight_4":
			LAi_KillCharacter(CharacterFromID("Alistair Garcilaso"));
			LAi_SetPlayerType(PChar);
			PChar.quest.main_line = "blaze_to_incas_collection_begin_6";
			LAi_LocationFightDisable(&Locations[FindLocation("Douwesen_Pirate_Residence")], true);
		break;

		case "prepare_fighting_on_deck_complete":
			if (PChar.quest.main_line == "blaze_to_incas_collection_begin_6" || PChar.quest.main_line == "blaze_to_incas_collection_begin" || PChar.quest.main_line == "kill_pirate_06" || PChar.quest.main_line == "blaze_to_incas_collection_begin_7" || PChar.quest.main_line == "blaze_to_incas_collection_begin")
			{
				PlaceCharacter(CharacterFromID("danielle_sailor"), "goto");
				LAi_SetActorType(PChar);
				LAi_SetActorType(CharacterFromID("danielle_sailor"));
				LAi_ActorFollow(PChar, CharacterFromID("danielle_sailor"), "", 2.0);
				LAi_ActorFollow(CharacterFromID("danielle_sailor"), PChar, "prepare_fighting_on_deck_complete_2", 2.0);
			}
		break;

		case "prepare_fighting_on_deck_complete_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("danielle_sailor"));
			LAi_ActorDialog(CharacterFromID("danielle_sailor"), PChar, "player_back", 2.0, 1.0);
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
			PChar.quest.abording_pirate_06.over = "yes";
			PChar.quest.kill_pirate_06.over = "yes";
			ChangeCharacterAddress(CharacterFromID("danielle_sailor"), "none", "none");
			LAi_group_MoveCharacter(CharacterFromID("pirate for abordage 01"), "PIRATES_FOR_ABORDAGE");
			LAi_group_MoveCharacter(CharacterFromID("pirate for abordage 02"), "PIRATES_FOR_ABORDAGE");
			LAi_group_MoveCharacter(CharacterFromID("pirate for abordage 03"), "PIRATES_FOR_ABORDAGE");
			LAi_group_SetRelation("PIRATES_FOR_ABORDAGE", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("PIRATES_FOR_ABORDAGE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_FOR_ABORDAGE", "kill_all_fighting_on_deck_complete");
		break;

		case "kill_all_fighting_on_deck_complete":
//			LAi_QuestDelay("kill_all_fighting_on_deck_complete_2", 2.0);
			PChar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 2000); }
			else { AddPartyExp(PChar, 2000); }
			DoQuestReloadToLocation("Douwesen_shore_01", "reload", "reload1", "kill_all_fighting_on_deck_complete_2");
		break;

		case "kill_all_fighting_on_deck_complete_2":
//			DoReloadCharacterToLocation("Douwesen_shore_01", "reload", "reload1");
			PChar.quest.main_line = "blaze_to_incas_collection_begin_6";
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
			setCharacterShipLocation(CharacterFromID("Pirate Captain 04"), "none");
			AddQuestRecord("blaze_to_incas_collection", 8);
			PChar.quest.prepare_fighting_on_deck_complete.over = "yes";
			GiveItem2Character(PChar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
		break;

		//начинается сценка с изобретателем
		case "prepare_for_first_meeting_with_researcher":
			PChar.quest.prepare_fighting_on_deck_complete.over = "yes";		// LDH appears to be an error, part of different quest - 14Apr09
			ChangeCharacterAddress(CharacterFromID("Bernard Gosling"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Garry Ankers"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Susannah Lazar"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Michael Collop"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Edgar Malter"), "none", "none");
			//ChangeCharacterAddress(CharacterFromID("Harold Smith"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Alan Newman"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Audrey Proude"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_3"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_4"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_41"), "none", "none");

			// LDH optimizations 14Apr09
			ref murderer04 = CharacterFromID("murderer_in_greenford_04");
			ref murderer05 = CharacterFromID("murderer_in_greenford_05");
			ref murderer06 = CharacterFromID("murderer_in_greenford_06");

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

			PChar.quest.main_line = "to_oxbay_by_prisoner_escape";
			ChangeCharacterAddress(CharacterFromID("greenford_citizen_01"), "Greenford_town", "goto23");

			PChar.quest.meeting_researcher.win_condition.l1 = "location";
			PChar.quest.meeting_researcher.win_condition.l1.location = "Greenford_town";
			PChar.quest.meeting_researcher.win_condition = "meeting_researcher_complete";

			Locations[FindLocation("Greenford_town")].models.always.koster = "koster";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.group = "goto";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.name = "goto24";
			Locations[FindLocation("Greenford_town")].models.always.koster.tech = "dLightModel";
			ChangeCharacterAddress(CharacterFromID("researcher"), "Greenford_town", "goto45");
			LAi_SetActorType(CharacterFromID("researcher"));
			LAi_ActorAnimation(CharacterFromID("researcher"), "Ground_sitting", "", "");

			Locations[FindLocation("Greenford_town")].reload.l1.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l2.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l3.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l4.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l7.disable = 1;
			Locations[FindLocation("Greenford_town")].reload.l9.disable = 1;
			AddQuestRecord("move_prisoner_from_greenford", 2);
		break;

		case "meeting_researcher_complete":
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("greenford_citizen_01"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("greenford_citizen_01"), PChar, "meeting_researcher_complete_2", 2.0);
			LAi_group_SetCheck("GREENFORD_MURDERERS", "kill_all_murderer_in_greenford_complete");
		break;

		case "meeting_researcher_complete_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("greenford_citizen_01"));
			LAi_ActorDialog(CharacterFromID("greenford_citizen_01"), PChar, "player_back", 1.0, 1.0);
		break;

		case "kicked_by_murderer_complete":
			LAi_ActorAnimation(CharacterFromID("murderer_in_greenford_04"), "attack_fast_2", "kicked_by_murderer_complete_2", 0.3);
		break;

		case "kicked_by_murderer_complete_2":
			LAi_ActorAnimation(PChar, "hit_2", "kicked_by_murderer_2_complete", 2.5);
		break;

		case "kicked_by_murderer_2_complete":
			PChar.quest.main_line = "resque_researcher_bad_kick";
			LAi_SetPlayerType(PChar);
			LAi_ActorDialogNow(CharacterFromID("murderer_in_greenford_04"), PChar, "", -1);
		break;

		case "kick_murderer_complete":
			LAi_SetActorType(PChar);
			LAi_ActorAttack(PChar, CharacterFromID("murderer_in_greenford_04"), "");
			LAi_QuestDelay("kill_murderer_complete", 2.0);
		break;

		case "kill_murderer_complete":
			LAi_KillCharacter(CharacterFromID("murderer_in_greenford_04"));
			LAi_group_FightGroups("GREENFORD_MURDERERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			LAi_SetPlayerType(PChar);
		break;

		case "kill_murderer_2_complete":
			LAi_RemoveCheckMinHP(CharacterFromID("murderer_in_greenford_04"));
			LAi_RemoveCheckMinHP(CharacterFromID("murderer_in_greenford_05"));
			LAi_RemoveCheckMinHP(CharacterFromID("murderer_in_greenford_06"));

			LAi_group_FightGroups("GREENFORD_MURDERERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		break;

		case "kill_all_murderer_in_greenford_complete":
			LAi_Fade("greenford_to_normal", "we_resque_researcher");
		break;

		case "greenford_to_normal":
			ChangeCharacterAddress(CharacterFromID("greenford_citizen_01"), "none", "none");

			ChangeCharacterAddress(CharacterFromID("Bernard Gosling"), "Greenford_town", "goto5");
			ChangeCharacterAddress(CharacterFromID("Garry Ankers"), "Greenford_town", "goto13");
			ChangeCharacterAddress(CharacterFromID("Susannah Lazar"), "Greenford_town", "goto12");
			ChangeCharacterAddress(CharacterFromID("Michael Collop"), "Greenford_town", "goto15");
			ChangeCharacterAddress(CharacterFromID("Edgar Malter"), "Greenford_town", "goto38");
			//ChangeCharacterAddress(CharacterFromID("Harold Smith"), "Greenford_town", "goto11");
			ChangeCharacterAddress(CharacterFromID("Alan Newman"), "Greenford_town", "goto17");
			ChangeCharacterAddress(CharacterFromID("Audrey Proude"), "Greenford_town", "goto33");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_3"), "Greenford_town", "goto4");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_4"), "Greenford_town", "goto27");
			ChangeCharacterAddress(CharacterFromID("Green_patrol_41"), "Greenford_town", "goto17");

			ChangeCharacterAddress(CharacterFromID("murderer_in_greenford_04"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("murderer_in_greenford_05"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("murderer_in_greenford_06"), "none", "none");
		break;

		case "we_resque_researcher":
			LAi_SetStayType(PChar);
			Locations[FindLocation("Greenford_town")].reload.l9.disable = 0;
			PChar.quest.main_line = "resque_researcher_complete";
			//убираем столб.

			Locations[FindLocation("Greenford_town")].models.always.koster = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.group = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.name = "";
			LAi_ActorAnimation(CharacterFromID("researcher"), "Ground_StandUp", "resque_researcher_in_greenford_complete", 1.0);
		break;

		case "soldier_help_us_resque_researher":
			LAi_fade("soldier_help_us_resque_researher_2", "resque_researcher_in_greenford_complete");
		break;

		case "soldier_help_us_resque_researher_2":
			PChar.quest.main_line = "resque_researcher_complete";
			LAi_type_actor_Reset(CharacterFromID("researcher"));
			ChangeCharacterAddressGroup(PChar, "Greenford_town", "reload", "reload1");
			//убираем столб.
			Locations[FindLocation("Greenford_town")].models.always.koster = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.group = "";
			Locations[FindLocation("Greenford_town")].models.always.koster.locator.name = "";
			PlaceCharacter(CharacterFromID("researcher"), "goto");
			ChangeCharacterAddress(&characters[getCharacterIndex("researcher")], "Greenford_town", "goto9");
		break;

		case "resque_researcher_in_greenford_complete":
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 3000); }
			else { AddPartyExp(PChar, 3000); }
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("researcher"), PChar, "resque_researcher_in_greenford_complete_2", 3.0);
		break;

		case "resque_researcher_in_greenford_complete_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "player_back", 2.0, 1.0)
		break;

		case "first_speak_with_danielle_in_lighthouse":
			LAi_ActorGoToLocator(CharacterFromID("researcher"), "reload", "reload2", "researcher_to_stay_type", -1);
			PChar.quest.main_line = "meet_danielle_in_lighthouse";
			LAi_type_actor_Reset(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "first_speak_with_vincent_in_lighthouse", 2.0, 1.0);
		break;

		case "researcher_to_stay_type":
			LAi_SetStayType(CharacterFromID("researcher"));
		break;

		case "first_speak_with_vincent_in_lighthouse":
			LAi_type_actor_Reset(CharacterFromID("Vincent bethune"));
			LAi_ActorDialog(CharacterFromID("Vincent bethune"), PChar, "first_speak_with_danielle_in_lighthouse_2", 2.0, 1.0);
		break;

		case "first_speak_with_danielle_in_lighthouse_2":
			LAi_ActorDialog(CharacterFromID("danielle"), PChar, "first_speak_with_danielle_in_lighthouse_3", 2.0, 1.0);
		break;

		case "first_speak_with_danielle_in_lighthouse_3":
			LAi_SetCitizenType(CharacterFromID("vincent bethune"));
			LAi_SetCitizenType(CharacterFromID("danielle"));
		break;

		case "meet_danielle_in_lighthouse_complete":
			PChar.quest.kill_all_murderer_in_greenford.over = "yes";
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "", 5.0, 1.0);
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
			LAi_SetActorType(CharacterFromID("Vincent Bethune"));
			LAi_SetActorType(CharacterFromID("Danielle"));
			ChangeCharacterAddress(CharacterFromID("Danielle"), "Oxbay_Lighthouse", "goto28");
			ChangeCharacterAddress(CharacterFromID("Vincent Bethune"), "Oxbay_Lighthouse", "goto9");
			ChangeCharacterAddress(CharacterFromID("researcher"), "Oxbay_Lighthouse", "goto7");
			PChar.quest.main_line = "meet_in_lighthouse";
			LAi_ActorFollow(CharacterFromID("Danielle"), PChar, "", -1);
			LAi_ActorFollow(CharacterFromID("Vincent Bethune"), PChar, "", -1);
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("researcher"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("researcher"), PChar, "blaze_with_researcher_to_lighthouse_2", 2.0);
		break;

		case "second_talk_with_Danielle_at_lighthouse":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "player_back", 1.0, 1.0);
			PChar.quest.main_line = "speak_danielle_in_lighthouse_prepare_to_search_rheims";
		break;

		case "blaze_with_researcher_to_lighthouse_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "player_back", 1.0, 1.0);
		break;

		case "kill_edgard_in_prison_complete":
			PChar.quest.kill_edgard_in_prison_2.win_condition.l1 = "NPC_Death";
			PChar.quest.kill_edgard_in_prison_2.win_condition.l1.character = "Edgar Attwood";
			PChar.quest.kill_edgard_in_prison_2.win_condition = "kill_edgard_in_prison_2_complete";
			LAi_SetActorType(PChar);
			LAi_ActorAttack(PChar, CharacterFromID("Edgar Attwood"), "");
			Lai_QuestDelay("kill_edgard_in_prison_complete_2", 2.0);
		break;

		case "kill_edgard_in_prison_complete_2":
			LAi_KillCharacter(CharacterFromID("Edgar Attwood"));
		break;

		case "abording_pirate_06_complete":
			PChar.quest.kill_pirate_06.over = "yes"; // PW
			PChar.quest.prepare_fighting_on_deck.over = "yes"; // GR
			setCharacterShipLocation(CharacterFromID("Pirate Captain 05"), "none");
			SetCharacterIslandLocation(CharacterFromID("Pirate Captain 06"), "none", "quest_ships", "quest_ship_9", "stay", "runaway", "");
			PChar.quest.main_line = "blaze_to_incas_collection_begin_6";
			GiveItem2Character(PChar, "icollection"); // PW
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
			ChangeCharacterAddress(CharacterFromID("danielle_sailor"), "none", "locator12");
			AddQuestRecord("blaze_to_incas_collection", 9);
		break;

		case "kill_pirate_06_complete":
			setCharacterShipLocation(CharacterFromID("Pirate Captain 05"), "none");
			SetCharacterIslandLocation(CharacterFromID("Pirate Captain 06"), "none", "quest_ships", "quest_ship_9", "stay", "runaway", "");
			PChar.quest.main_line = "kill_pirate_06";
			characters[GetCharacterIndex("danielle_sailor")].quest.kill_pirate_06 = "done";
			AddQuestRecord("blaze_to_incas_collection", 10);
			DoQuestCheckDelay("kill_pirate_06_complete_2", 1.0);
		break;

		case "kill_pirate_06_complete_2":
			PChar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			DoReloadFromSeaToLocation("Douwesen_shore_01", "reload", "reload1");
			PChar.quest.back_to_douwesen_shore.win_condition.l1 = "location";
			PChar.quest.back_to_douwesen_shore.win_condition.l1.location = "Douwesen_shore_01";
			PChar.quest.back_to_douwesen_shore.win_condition = "prepare_fighting_on_deck_complete";
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 3000); }
			else { AddPartyExp(PChar, 3000); }
		break;

		case "find_statuets_complete":
			LAi_Fade("find_statuets_2_complete", "");
		break;

		case "find_statuets_2_complete":
			LAi_ActorDialog(CharacterFromID("danielle_sailor"), PChar, "", 5.0, 1.0);
			PChar.quest.main_line = "blaze_to_incas_collection_begin_7";
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
			AddQuestRecord("blaze_to_incas_collection", 11);
			PChar.quest.prepare_fighting_on_deck_complete.over = "yes";
			GiveItem2Character(PChar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
		break;

		case "see_statuetes_complete":
			LAi_Fade("", "see_statuetes_2_complete");
		break;

		case "see_statuetes_2_complete":
			LAi_SetActorType(CharacterFromID("Robert Christopher Silehard"));
			LAi_ActorDialogNow(CharacterFromID("Robert Christopher Silehard"), PChar, "back_to_hovernor_type", -1);
			AddQuestRecord("blaze_to_incas_collection", 12);
			CloseQuestHeader("blaze_to_incas_collection");
		break;

		//возвращаемся на маяк для разговора даниэль и отплытия за реймсом
		case "return_to_lighthouse_search_rheims_complete":
			PlaceCharacter(CharacterFromID("Danielle"), "goto");
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 50, 0);
		break;

		//прибываем в порт дувезена
		case "to_douwesen_port_search_blaze_complete":
			if (PChar.quest.main_line == "blaze_goto_douwesen_with_danielle")
			{
				LAi_SetActorType(CharacterFromID("danielle")); // 04-12-08
				LAi_type_actor_Reset(CharacterFromID("danielle"));
				PChar.quest.to_douwesen_shore_1_search_blaze.over = "yes";
				PChar.quest.to_douwesen_shore_2_search_blaze.over = "yes";
				PlaceCharacter(CharacterFromID("danielle"), "goto");
				ChangeCharacterAddress(CharacterFromID("Vincent Bethune"), "Douwesen_tavern", "goto3");
				Lai_SetSitType(CharacterFromID("Raoul Rheims"));
				ChangeCharacterAddressGroup(CharacterFromID("Raoul Rheims"), "Douwesen_tavern", "sit", "sit5");
				Locations[FindLocation("Douwesen_tavern")].vcskip = true; // NK
				LAi_SetActorType(PChar);
				LAi_ActorFollow(PChar, CharacterFromID("danielle"), "", 3.0);
				LAi_ActorFollow(CharacterFromID("danielle"), PChar, "danielle_speak_with_blaze_in_douwesen_port", 3.0);
			}
		break;

		//прибываем на первый пляж дувезена
		case "to_douwesen_shore_1_search_blaze_complete":
			if (PChar.quest.main_line == "blaze_goto_douwesen_with_danielle")
			{
				LAi_SetActorType(CharacterFromID("danielle")); // 04-12-08
				LAi_type_actor_Reset(CharacterFromID("danielle"));
				PChar.quest.to_douwesen_port_search_blaze.over = "yes";
				PChar.quest.to_douwesen_shore_2_search_blaze.over = "yes";
				PlaceCharacter(CharacterFromID("danielle"), "goto");
				ChangeCharacterAddress(CharacterFromID("Vincent Bethune"), "Douwesen_tavern", "goto3");
				Lai_SetSitType(CharacterFromID("Raoul Rheims"));
				ChangeCharacterAddressGroup(CharacterFromID("Raoul Rheims"), "Douwesen_tavern", "sit", "sit5"); // NK
				LAi_SetActorType(PChar);
				LAi_ActorFollow(PChar, CharacterFromID("danielle"), "", 3.0);
				LAi_ActorFollow(CharacterFromID("danielle"), PChar, "danielle_speak_with_blaze_in_douwesen_port", 3.0);
			}
		break;

		//прибываем на второй пляж дувезена
		case "to_douwesen_shore_2_search_blaze_complete":
			if (PChar.quest.main_line == "blaze_goto_douwesen_with_danielle")
			{
				LAi_SetActorType(CharacterFromID("danielle")); // 04-12-08
				LAi_type_actor_Reset(CharacterFromID("danielle"));
				PChar.quest.to_douwesen_port_search_blaze.over = "yes";
				PChar.quest.to_douwesen_shore_1_search_blaze.over = "yes";
				PlaceCharacter(CharacterFromID("danielle"), "goto");
				ChangeCharacterAddress(CharacterFromID("Vincent Bethune"), "Douwesen_tavern", "goto3");
				Lai_SetSitType(CharacterFromID("Raoul Rheims"));
				ChangeCharacterAddressGroup(CharacterFromID("Raoul Rheims"), "Douwesen_tavern", "sit", "sit5"); // NK
				LAi_SetActorType(PChar);
				LAi_ActorFollow(PChar, CharacterFromID("danielle"), "", 3.0);
				LAi_ActorFollow(CharacterFromID("danielle"), PChar, "danielle_speak_with_blaze_in_douwesen_port", 3.0);
			}
		break;

		case "danielle_speak_with_blaze_in_douwesen_port":
			PChar.quest.main_line = "blaze_goto_douwesen_with_danielle_2";
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("danielle"), PChar, "danielle_becomes_officer_in_douwesen", 1.0, 1.0);
		break;

		case "danielle_becomes_officer_in_douwesen":
			LAi_SetPlayerType(PChar);
			Locations[FindLocation("Douwesen_port")].reload.l2.disable = 1;
			Locations[FindLocation("Douwesen_port")].reload.l3.disable = 1;
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = 1;
			Locations[FindLocation("Douwesen_shore_02")].reload.l2.disable = 1;
			PChar.quest.main_line = "blaze_goto_douwesen_with_danielle_3";
			PChar.quest.goto_with_danielle_to_douwesen_tavern_for_rheims.win_condition.l1 = "location";
			PChar.quest.goto_with_danielle_to_douwesen_tavern_for_rheims.win_condition.l1.location = "Douwesen_tavern";
			PChar.quest.goto_with_danielle_to_douwesen_tavern_for_rheims.win_condition = "goto_with_danielle_to_douwesen_tavern_for_rheims_complete";

			LAi_SetOfficerType(CharacterFromID("danielle"));
			SetOfficersIndex(PChar, 3, GetCharacterIndex("danielle"));
			SetCharacterRemovable(CharacterFromID("danielle"), false);
		break;

		//заходим в таверну за Винсетом, который покажет нам реймса
		case "goto_with_danielle_to_douwesen_tavern_for_rheims_complete":
			LAi_SetActorType(CharacterFromID("vincent bethune"));
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("Vincent Bethune"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("Vincent Bethune"), PChar, "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_2", 2.0);
		break;

		case "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Vincent Bethune"));
			LAi_ActorDialog(CharacterFromID("Vincent Bethune"), PChar, "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_3", 1.0, 1.0);
		break;

		//Винсент идет за своими головорезами
		case "vincent_away_from_tavern_complete":
			ChangeCharacterAddress(CharacterFromID("Vincent Bethune"), "none", "none");
		break;

		case "goto_with_danielle_to_douwesen_tavern_for_rheims_complete_3":
			LAi_ActorWaitDialog(PChar, CharacterFromID("danielle"));
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("danielle"), PChar, "player_back", 1.0, 1.0);
		break;

		case "from_tavern_to_rheims_house_complete":
			LAi_LocationMonstersGen(&locations[FindLocation("Douwesen_town_exit")], false);
			DeleteAttribute(&Locations[FindLocation("Douwesen_tavern")],"vcskip"); // NK
			Locations[FindLocation("Rheims_house_inside")].vcskip = true; // NK
			PChar.quest.main_line = "from_tavern_to_rheims_house";
			LAi_SetActorType(CharacterFromID("Raoul Rheims"));
			RemovePassenger(PChar, CharacterFromID("Danielle"));
			RemoveCharacterCompanion(PChar, CharacterFromID("Danielle"));
			RemoveOfficersIndex(PChar, GetCharacterIndex("Danielle"));
			PChar.quest.danielle_on_ship = "false";
			StorePassengers(PChar.id);
			LAi_SetActorType(CharacterFromID("Danielle"));
			DoQuestReloadToLocation("Douwesen_town_exit", "goto", "goto2", "from_town_to_jungle_to_rheims_house_complete");
			locations[FindLocation("Douwesen_town_exit")].reload.l1.disable = 1;
			locations[FindLocation("Douwesen_town_exit")].reload.l2.disable = 1;

			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestrecord("again_find_rheims", 4);
			Preprocessor_Remove("Danielle");
		break;

		//выходим в город и на нас нападют головорезы
		case "from_town_to_jungle_to_rheims_house_complete":
			PlaceCharacter(CharacterFromID("danielle"), "goto");
			PlaceCharacter(CharacterFromID("Raoul Rheims"), "goto");

			LAi_ActorDialog(CharacterFromID("danielle"), PChar, "", 5.0, 0);
		break;

		case "prepare_danielle_with_rheims_runaway_complete":
			LAi_SetHP(CharacterFromID("murderer_in_douwesen_01"), 60.0, 60.0);
			LAi_SetHP(CharacterFromID("murderer_in_douwesen_02"), 60.0, 60.0);
			LAi_SetHP(CharacterFromID("murderer_in_douwesen_03"), 60.0, 60.0);
			ChangeCharacterAddress(CharacterFromID("murderer_in_douwesen_01"), "douwesen_town_exit", "goto4");
			ChangeCharacterAddress(CharacterFromID("murderer_in_douwesen_02"), "douwesen_town_exit", "goto4");
			ChangeCharacterAddress(CharacterFromID("murderer_in_douwesen_03"), "douwesen_town_exit", "goto4");
			LAi_group_MoveCharacter(CharacterFromID("murderer_in_douwesen_01"), "DOUWESEN_MURDERERS");
			LAi_group_MoveCharacter(CharacterFromID("murderer_in_douwesen_02"), "DOUWESEN_MURDERERS");
			LAi_group_MoveCharacter(CharacterFromID("murderer_in_douwesen_03"), "DOUWESEN_MURDERERS");
			LAi_group_FightGroups("DOUWESEN_MURDERERS", LAI_GROUP_PLAYER, true);
			LAi_ActorRunToLocator(CharacterFromID("danielle"), "reload", "reload1_back", "", 40.0);
			LAi_ActorRunToLocator(CharacterFromID("raoul Rheims"), "reload", "reload1_back", "danielle_with_rheims_runaway_complete", 40.0);
			LAi_group_SetCheck("DOUWESEN_MURDERERS", "kill_murderers_in_douwesen_town_exit_complete");

			PChar.quest.prepare_dagger.win_condition.l1 = "location";
			PChar.quest.prepare_dagger.win_condition.l1.location = "Rheims_house_inside";
			PChar.quest.prepare_dagger.win_condition = "prepare_dagger";
		break;

		//Даниэль с Реймсом убегают
		case "danielle_with_rheims_runaway_complete":
			ChangeCharacterAddressGroup(CharacterFromID("Danielle"), "Rheims_house_inside", "item", "item1");
			LAi_NoRebirthDisable(CharacterFromID("Raoul Rheims")); // PB: Just in case he somehow died
			ChangeCharacterAddress(CharacterFromID("Raoul Rheims"), "Rheims_house_inside", "goto1");
			ChangeCharacterAddress(CharacterFromID("Vincent Bethune"), "Rheims_house_inside", "goto2");
		break;

		case "prepare_dagger":
			locx = stf(loadedLocation.locators.camera.locator4.x);
			locy = stf(loadedLocation.locators.camera.locator4.y);
			locz = stf(loadedLocation.locators.camera.locator4.z);
			locCameraToPos(locx, locy, locz, false);

			LAi_type_actor_Reset(CharacterFromID("danielle"));
			LAi_type_actor_Reset(CharacterFromID("Raoul Rheims"));
			LAi_type_actor_Reset(CharacterFromID("Vincent Bethune"));
			LAi_ActorAnimation(CharacterFromID("Raoul Rheims"), "Lay_1", "", -1);
			LAi_ActorAnimation(CharacterFromID("Vincent Bethune"), "Lay_2", "", -1);

			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, CharacterFromID("danielle"), "", 2.0, 1.0);
			LAi_ActorWaitDialog(CharacterFromID("danielle"), PChar);
			LAi_CharacterDisableDialog(CharacterFromID("Raoul Rheims"));
			LAi_CharacterDisableDialog(CharacterFromID("Vincent Bethune"));
			PChar.quest.main_line = "to_rheims_house";
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
			LAi_SetActorType(CharacterFromID("blaze"));
			LAi_SetImmortal(PChar, true);
			LAi_ActorAttack(CharacterFromID("danielle"), CharacterFromID("blaze"), "");
			LAi_QuestDelay("dagger_2", 2.0);
		break;

		case "dagger_2":
			LAi_ActorAnimation(CharacterFromID("blaze"), "death_1", "dagger_3", 2.0);
		break;

		case "dagger_3":
			LAi_ActorAnimation(CharacterFromID("blaze"), "Lay_1", "", -1);
			LAi_SetPlayerType(CharacterFromID("danielle"));
			SetMainCharacterIndex(GetCharacterIndex("danielle"));
			PChar = GetMainCharacter(); // PB: This is IMPORTANT to update that you are now 'Danielle'!
			ChangeCharacterAddress(CharacterFromID("Blaze"), "Rheims_house_inside", "goto5");

			DoQuestReloadToLocation("Rheims_house_inside", "item", "item1", "start_quest_movie_speak_with_rheims_complete");
			PChar.quest.main_line = "danielle_speak_with_almost_dead_rheims";

			locations[FindLocation("Douwesen_town_exit")].reload.l1.disable = 0;
			locations[FindLocation("Douwesen_town_exit")].reload.l2.disable = 0;
		break;

		//Блэйз слышит диалог Даниель с Реймсом
		case "start_quest_movie_speak_with_rheims_complete":
			locx = stf(loadedLocation.locators.camera.locator4.x);
			locy = stf(loadedLocation.locators.camera.locator4.y);
			locz = stf(loadedLocation.locators.camera.locator4.z);
			locCameraToPos(locx, locy, locz, false);

			LAi_CharacterEnableDialog(CharacterFromID("Raoul Rheims"));
			characters[GetCharacterIndex("Raoul Rheims")].dialog.currentnode = "danielle_speak_with_almost_dead_rheims_node";
			LAi_ActorSetLayMode(CharacterFromID("Raoul Rheims"));
			LAi_ActorWaitDialog(CharacterFromID("Raoul Rheims"), PChar);
			LAi_SetActorType(PChar);
			LAi_ActorDialogNow(PChar, CharacterFromID("Raoul Rheims"), "", -1);
		break;

		case "start_quest_movie_speak_with_rheims_complete_2":
			LAi_ActorGoToLocator(PChar, "reload", "reload1", "exit_after_speak_with_rheims", 5.0);
		break;

		case "kill_ferro_cerezo_complete":
			if (PChar.quest.main_line != "compramat_done")
			{
				PChar.quest.main_line = "compramat_bul_bul";
				AddQuestrecord("search_danielle", 8);
			}
		break;

		case "abording_ferro_cerezo_complete":
			GiveItem2Character(PChar, "domingues_fucked");
			PChar.quest.main_line = "compramat_done";
			AddQuestRecord("search_danielle", 7);
			PChar.quest.kill_ferro_cerezo_complete.over = "yes";
		break;

		//блэйза бьют по башке
		case "to_oxbay_mine_complete":
			if (PChar.location.locator == "reload1")
			{
				LAi_SetHP(CharacterFromID("Stephan Bonser"), 60.0, 60.0);
				LAi_SetHP(CharacterFromID("Oswald Chappel"), 60.0, 60.0);
				LAi_SetHP(CharacterFromID("Gyles Dubois"), 60.0, 60.0);
				ChangeCharacterAddress(CharacterFromID("Stephan Bonser"), "Oxbay_canyon", "goto29");
				ChangeCharacterAddress(CharacterFromID("Oswald Chappel"), "Oxbay_canyon", "goto30");
				ChangeCharacterAddress(CharacterFromID("Gyles Dubois"), "Oxbay_canyon", "goto18");
				LAi_SetActorType(CharacterFromID("Stephan Bonser"));
				LAi_SetActorType(CharacterFromID("Oswald Chappel"));
				LAi_SetActorType(CharacterFromID("Gyles Dubois"));
				LAi_ActorFollow(CharacterFromID("Oswald Chappel"), PChar, "", -1);
				LAi_ActorFollow(CharacterFromID("Gyles Dubois"), PChar, "", -1);
				LAi_SetActorType(PChar);
				LAi_ActorFollow(PChar, CharacterFromID("Stephan Bonser"), "", 2.0);
				LAi_ActorFollow(CharacterFromID("Stephan Bonser"), PChar, "to_oxbay_mine_complete_2", 2.0);

				Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
				Locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 1;
			}
			else
			{
				PChar.quest.main_line = "kick_on_mine_not_exist";
			}
			Locations[FindLocation("Oxbay_canyon")].reload.l3.disable = false;
		break;

		case "to_oxbay_mine_complete_2":
			LAi_ActorWaitDialog(PChar, CharacterFromID("Stephan Bonser"));
			LAi_ActorDialog(CharacterFromID("Stephan Bonser"), PChar, "", 1.0, 0);
		break;

		case "kicked_to_mine_complete":
			LAi_SetActorType(PChar);
			PChar.quest.kill_ferro_cerezo.over = "yes";
			PChar.quest.abording_ferro_cerezo.over = "yes";
			if (characters[GetCharacterIndex("Ferro Cerezo")].location == "Conceicao_tavern") ChangeCharacterAddress(CharacterFromID("Ferro Cerezo"), "None", ""); // GR
			if (CalcCharacterSkill(PChar, SKILL_FENCING) > 7)
			{
				LAi_QuestDelay("after_kicked_2_complete", 0.5);
			}
			else
			{
				LAi_ActorTurnToCharacter(CharacterFromID("Stephan Bonser"), PChar);
				LAi_ActorAnimation(CharacterFromID("Stephan Bonser"), "attack_fast_2", "kicked_to_mine_3_complete", 0.4);
			}
		break;

		case "kicked_to_mine_3_complete":
			LAi_SetActorType(PChar);
			LAi_ActorAnimation(PChar, "death_1", "after_kicked_complete", 3.5);
			LAi_SetImmortal(PChar, true);
			LAi_group_MoveCharacter(CharacterFromID("Stephan Bonser"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(CharacterFromID("Oswald Chappel"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(CharacterFromID("Gyles Dubois"), "MURDERERS_IN_CANYON");
			LAi_group_SetRelation("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, true);
		break;

		case "after_kicked_complete":
			LAi_SetImmortal(PChar, false);
			LAi_SetPlayerType(PChar);
			StorePassengers("Blaze");
			PChar.tempmoney = PChar.money;
			RemoveCharacterEquip(PChar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(PChar, BLADE_ITEM_TYPE);
			EnableEquip(PChar, GUN_ITEM_TYPE, false);
			EnableEquip(PChar, BLADE_ITEM_TYPE, false);

			PChar.quest.main_line = "slave_in_oxbay_mine_begin";
			DoQuestReloadToLocation("Oxbay_mine", "goto", "goto1", "to_mines_complete");
			Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l1.disable = 1;
			Locations[FindLocation("Oxbay_mine")].reload.l2.disable = 1;
			AddQuestRecord("search_danielle", 11);
		break;

		case "after_kicked_2_complete":
			LAi_SetPlayerType(PChar);
			LAi_group_MoveCharacter(CharacterFromID("Stephan Bonser"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(CharacterFromID("Oswald Chappel"), "MURDERERS_IN_CANYON");
			LAi_group_MoveCharacter(CharacterFromID("Gyles Dubois"), "MURDERERS_IN_CANYON");
			LAi_group_SetRelation("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("MURDERERS_IN_CANYON", LAI_GROUP_PLAYER, true);
			PChar.quest.main_line = "kick_on_mine_not_exist";
			AddQuestRecord("search_danielle", 10);
			Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
		break;

		case "to_mines_complete":
			ChangeCharacterAddress(CharacterFromID("Stephan Bonser"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Oswald Chappel"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Gyles Dubois"), "none", "none");
			LAi_SetActorType(CharacterFromID("Leborio Drago"));
			LAi_ActorDialog(CharacterFromID("Leborio Drago"), PChar, "", 2.0, 1.0);
		break;

		case "second_speak_with_leborio_in_mines":
			PChar.quest.main_line = "resque_from_mines_denied";
			LAi_SetActorType(CharacterFromID("leborio drago"));
			LAi_ActorDialog(CharacterFromID("leborio drago"), PChar, "", 2.0, 1.0);
			LAi_ActorGoToLocator(CharacterFromID("mine_soldier_01"), "goto", "goto9", "mine_soldier_back_to_soldier", 5.0);
		break;

		case "mine_soldier_back_to_soldier":
			LAi_SetGuardianType(CharacterFromID("mine_soldier_01"));
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_01"), "ENGLAND_SOLDIERS");
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
			GiveItem2Character(CharacterFromID("danielle"), "blade10");
			EquiPCharacterByItem(CharacterFromID("danielle"), "blade10");

			LAi_SetActorType(CharacterFromID("Danielle"));
			LAi_ActorAnimation(CharacterFromID("Danielle"), "lay_1", "", -1);
			LAi_CharacterDisableDialog(CharacterFromID("Danielle"));
			ChangeCharacterAddress(CharacterFromID("Danielle"), "Quest_Muelle_town_01", "goto21");
			LAi_SetHP(CharacterFromID("pirate for quest muelle 01"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("pirate for quest muelle 03"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("pirate for quest muelle 02"), 80.0, 80.0);
			ChangeCharacterAddress(CharacterFromID("pirate for quest muelle 01"), "Quest_Muelle_town_01", "goto100");
			ChangeCharacterAddress(CharacterFromID("pirate for quest muelle 02"), "Quest_Muelle_town_01", "goto101");
			ChangeCharacterAddress(CharacterFromID("pirate for quest muelle 03"), "Quest_Muelle_town_01", "goto102");
			DoReloadCharacterToLocation("Quest_Muelle_town_01", "goto", "goto23");
			PChar.quest.to_quest_muelle.win_condition.l1 = "location";
			PChar.quest.to_quest_muelle.win_condition.l1.location = "Quest_Muelle_town_01";
			PChar.quest.to_quest_muelle.win_condition = "to_quest_muelle_complete";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromID("Danielle"))));
			AddQuestRecord("search_danielle", 22);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("Danielle");
			Locations[FindLocation("Oxbay_canyon")].reload.l3.disable = true;
		break;

		case "to_quest_muelle_complete":
			LAi_group_MoveCharacter(CharacterFromID("pirate for quest muelle 01"), "QUEST_MUELLE_PIRATES");
			LAi_group_MoveCharacter(CharacterFromID("pirate for quest muelle 02"), "QUEST_MUELLE_PIRATES");
			LAi_group_MoveCharacter(CharacterFromID("pirate for quest muelle 03"), "QUEST_MUELLE_PIRATES");
			LAi_group_SetRelation("QUEST_MUELLE_PIRATES", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("QUEST_MUELLE_PIRATES", LAI_GROUP_PLAYER, true);

			PChar.quest.kill_all_pirate_in_quest_muelle.win_condition.l1 = "NPC_death";
			PChar.quest.kill_all_pirate_in_quest_muelle.win_condition.l1.character = "pirate for quest muelle 01";
			PChar.quest.kill_all_pirate_in_quest_muelle.win_condition.l2 = "NPC_death";
			PChar.quest.kill_all_pirate_in_quest_muelle.win_condition.l2.character = "pirate for quest muelle 02";
			PChar.quest.kill_all_pirate_in_quest_muelle.win_condition.l3 = "NPC_death";
			PChar.quest.kill_all_pirate_in_quest_muelle.win_condition.l3.character = "pirate for quest muelle 03";
			PChar.quest.kill_all_pirate_in_quest_muelle.win_condition = "kill_all_pirate_in_quest_muelle_complete";
		break;

		case "kill_all_pirate_in_quest_muelle_complete":
			LAi_CharacterEnableDialog(CharacterFromID("Danielle"));
			ChangeCharacterAddress(CharacterFromID("pirate for quest muelle 01"), "none", "goto100");
			ChangeCharacterAddress(CharacterFromID("pirate for quest muelle 02"), "none", "goto101");
			ChangeCharacterAddress(CharacterFromID("pirate for quest muelle 03"), "none", "goto102");
			LAi_Fade("prepare_back_to_muelle_complete", "back_to_muelle_complete");
		break;

		case "prepare_back_to_muelle_complete":
			LAi_type_actor_Reset(CharacterFromID("danielle"));
			LAi_SetActorType(PChar);
		break;

		case "back_to_muelle_complete":
			PChar.quest.main_line = "resque_danielle";
			LAi_ActorFollow(PChar, CharacterFromID("danielle"), "", 4.0);
			LAi_ActorFollow(CharacterFromID("danielle"), PChar, "back_to_muelle_complete_2", 4.0);
		break;

		case "back_to_muelle_complete_2":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 10000);
				AddPartyExpChar(PChar, "Sneak", 1000);
			}
			else { AddPartyExp(PChar, 10000); }
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "player_back", 2.0, 1.0);
			PChar.quest.blaze_to_map.win_condition.l1 = "location";
			PChar.quest.blaze_to_map.win_condition.l1.location = "Redmond";
			PChar.quest.blaze_to_map.win_condition = "blaze_to_map_complete";
		break;

		case "danielle_death":
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE1"));
			Lai_KillCharacter(PChar);
		break;

		case "blaze_to_map_complete":
			//задизейблить выход из карты
			PChar.location.from_sea = "Redmond_shore_01";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			DoReloadFromSeaToLocation("Redmond_shore_01", "reload", "reload1");
			PChar.quest.to_secret_oxbay_shore_complete.win_condition.l1 = "location";
			PChar.quest.to_secret_oxbay_shore_complete.win_condition.l1.location = "Redmond_shore_01";
			PChar.quest.to_secret_oxbay_shore_complete.win_condition = "to_secret_oxbay_shore_complete";
			//разрешить выход из карты
		break;

		case "to_secret_oxbay_shore_complete":
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_type_actor_Reset(CharacterFromID("danielle"));
			LAi_LocationFightDisable(&locations[FindLocation("Quest_Residence")], true);

			PlaceCharacter(CharacterFromID("danielle"), "goto");
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 5.0, 0);
		break;

		case "to_secret_oxbay_shore_complete2":
			LAi_type_actor_Reset(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 5.0, 0);
		break;

		case "both_to_residence_complete":
			PChar.quest.main_line = "both_to_redmond_residence";
			StorePassengers(PChar.id);
			LAi_SetOfficerType(CharacterFromID("Danielle"));

			// LDH - 10Apr09
			LAi_SetActorType(CharacterFromID("robert christopher silehard"));				// prevents errors in LAi_ActorDialog()
//			LAi_SetLoginTime(CharacterFromID("robert christopher silehard"), 0.0, 24.0);	// makes Silehard appear in bedroom
//			LAi_RemoveLoginTime(CharacterFromID("robert christopher silehard"));			// suggested by SJG

			ChangeCharacterAddress(CharacterFromID("Robert Christopher Silehard"), "Quest_residence", "goto6");
			DeleteAttribute(CharacterFromID("Robert Christopher Silehard"), "Dialog.Filename.GroupDialog"); // GR

			Locations[FindLocation("Quest_Residence")].reload.l1.disable = 1;
			DoQuestReloadToLocation("Quest_residence", "reload", "reload1", "both_to_residence_complete_2");
			characters[GetCharacterIndex("Robert Christopher Silehard")].Dialog.CurrentNode = "both_talk_with_Silehard_node";
			PChar.quest.main_line = "both_talk_with_Silehard";
			LAi_ActorDialog(CharacterFromID("Robert Christopher Silehard"), PChar, "", 5.0, 0);
			ChangeCharacterAddress(CharacterFromID("Danielle"), "Quest_residence", "goto4");
			Locations[FindLocation("Greenford_town")].reload.l9.close_for_night = 0;
		break;

		case "both_to_residence_complete_2":
			LAi_SetActorType(CharacterFromID("robert christopher silehard"));
			LAi_ActorDialog(CharacterFromID("robert christopher silehard"), PChar, "", 5.0, 1.0);
		break;

		case "both_escape_from_redmond_complete":
			PlaceCharacter(CharacterFromID("danielle"), "goto");
			PChar.quest.main_line = "both_escape_from_redmond";
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 5.0, 0);
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Revenge_for_Silehard", 4);
			Preprocessor_Remove("Danielle");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 5000);
				AddPartyExpChar(PChar, "Sneak", 50);
			}
			else { AddPartyExp(PChar, 5000); }
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = true;
			LAi_RemoveLoginTime(CharacterFromID("robert christopher silehard"));			// suggested by SJG
		break;

		case "to_idol_complete":
			ChangeCharacterAddress(CharacterFromID("Danielle"), "none", "none");
		break;

		case "return_idol_from_frigate_complete":
			PChar.quest.return_idol_from_frigate1.over = "yes";
			PChar.quest.return_idol_from_frigate.over = "yes";
			Island_SetReloadEnableGlobal("Oxbay", true);
			bQuestDisableMapEnter = false;	//CTM
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("Revenge_for_Silehard", "8");
			Preprocessor_Remove("Danielle");
			ChangeCharacterAddress(CharacterFromID("researcher"), "oxbay_lighthouse", "goto24");
			GiveItem2Character(PChar, "idol");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 30000); }
			else { AddPartyExp(PChar, 30000); }

			iForceDetectionFalseFlag = 0; // KK

			PChar.quest.main_line = "blaze_search_danielle_again";

			PChar.quest.to_lighthouse_to_meet_danielle_before_storm.win_condition.l1 = "location";
			PChar.quest.to_lighthouse_to_meet_danielle_before_storm.win_condition.l1.location = "Oxbay_lighthouse";
			PChar.quest.to_lighthouse_to_meet_danielle_before_storm.win_condition = "to_lighthouse_to_meet_danielle_before_storm";
		break;

		case "to_lighthouse_to_meet_danielle_before_storm":
			PlaceCharacter(CharacterFromID("researcher"), "goto");
			LAi_SetActorType(CharacterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "", 20.0, 1.0);
			CloseQuestheader("Revenge_for_Silehard");
		break;

		case "prepare_for_storm":
//			AddQuestrecord("Where_are_i", 1);
			PChar.quest.before_storm.win_condition.l1 = "MapEnter";
			PChar.quest.before_storm.win_condition = "before_storm";
		break;

		case "before_storm":
			characters[getCharacterIndex("Greenford Commander")].skill.accuracy = "9";
			characters[getCharacterIndex("Greenford Commander")].skill.cannons = "5";
			/*worldMap.islands.Douwesen.locations.city.position.x = -195.439728;
			worldMap.islands.Douwesen.locations.city.position.y = 6.049987;
			worldMap.islands.Douwesen.locations.city.position.z = -106.659912;*/
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			if(GetOfficersIndex(PChar, 1) == -1)
			{
				PChar.Temp.Officer.idx1 = GetCharacterIndex("Blaze_Crewmember_01");
			}
			else
			{
				PChar.Temp.Officer.idx1 = getOfficersIndex(PChar, 1);
				PChar.Temp.Officer.idx1.Dialog = Characters[getOfficersIndex(PChar, 1)].Dialog.Filename;
				PChar.Temp.Officer.idx1.CurrentNode = Characters[getOfficersIndex(PChar, 1)].Dialog.CurrentNode;
			}
			if(GetOfficersIndex(PChar, 2) == -1)
			{
				PChar.Temp.Officer.idx2 = GetCharacterIndex("Blaze_Crewmember_02");
			}
			else
			{
				PChar.Temp.Officer.idx2 = getOfficersIndex(PChar, 2);
				PChar.Temp.Officer.idx2.Dialog = Characters[getOfficersIndex(PChar, 2)].Dialog.Filename;
				PChar.Temp.Officer.idx2.CurrentNode = Characters[getOfficersIndex(PChar, 2)].Dialog.CurrentNode;
			}
			if(GetOfficersIndex(PChar, 3) == -1)
			{
				PChar.Temp.Officer.idx3 = GetCharacterIndex("Blaze_Crewmember_03");
			}
			else
			{
				PChar.Temp.Officer.idx3 = getOfficersIndex(PChar, 3);
				PChar.Temp.Officer.idx3.Dialog = Characters[getOfficersIndex(PChar, 3)].Dialog.Filename;
				PChar.Temp.Officer.idx3.CurrentNode = Characters[getOfficersIndex(PChar, 3)].Dialog.CurrentNode;
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
						if (HasSubStr(PChar.quest.before_storm_fleet.(temp), "Enc_Officer")) LAi_StoreFantom(CharacterFromID(PChar.quest.before_storm_fleet.(temp))); // Prevent character from being overwritten by another "Enc_Officer"
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
			ExchangeCharacterShip(PChar, CharacterFromID("Ship Storage"));
			PChar.ship.name = characters[GetCharacterIndex("Ship Storage")].ship.name;
			SetCharacterShipLocation(CharacterFromID("Ship Storage"), "Muelle_port");
			DeleteAttribute(PChar, "ship");
			PChar.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
// KK: I have disabled this feature and simply added food and rum to ships which
//     Nathaniel can use to leave the island. The setting as it was destroyed
//     realism.
			//PChar.skipfood = true; // NK; KK: commented out.
			PChar.tempmoney = PChar.money;
			PChar.money = 0;
			locations[FindLocation("Douwesen_town")].reload.l3.disable = true;
			CloseQuestHeader("Revenge_for_Silehard");
			SetQuestHeader("Where_are_i");
			AddQuestrecord("Where_are_i", 1);
			PChar.quest.main_line = "speak_with_peasant";
			PChar.quest.Story_DanielleWaitsInMuelleTown.win_condition.l1 = "location";
			PChar.quest.Story_DanielleWaitsInMuelleTown.win_condition.l1.location = "Muelle_tavern";
			PChar.quest.Story_DanielleWaitsInMuelleTown.win_condition = "Story_DanielleWaitsInMuelleTown";

			PChar.quest.Story_AppearOnIslaMuelleonAnacletoShip.win_condition.l1 = "location";
			PChar.quest.Story_AppearOnIslaMuelleonAnacletoShip.win_condition.l1.location = "Muelle_port";
			PChar.quest.Story_AppearOnIslaMuelleonAnacletoShip.win_condition = "Story_AppearOnIslaMuelleonAnacletoShip";

			iPassenger = makeint(PChar.Temp.Officer.idx1);
			ChangeCharacterAddress(&Characters[iPassenger], "Muelle_port", "Goto4");
			iPassenger = makeint(PChar.Temp.Officer.idx2);
			ChangeCharacterAddress(&Characters[iPassenger], "Muelle_port", "Goto1");
			iPassenger = makeint(PChar.Temp.Officer.idx3);
			ChangeCharacterAddress(&Characters[iPassenger], "Muelle_port", "Goto2");
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetRelation("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			DoQuestReloadToLocation("Douwesen_shore_01", "reload", "reload1", "to_douwesen_shore_complete");
		break;

		case "to_lighthouse_to_meet_danielle_before_storm":
			PlaceCharacter(CharacterFromID("researcher"), "goto");
			LAi_SetActorType(CharacterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "", 20.0, 1.0);
			CloseQuestheader("Revenge_for_Silehard");
		break;

		case "fight_in_residence_complete":
			Locations[FindLocation("Quest_Residence")].reload.l1.disable = 1;
			LAi_SetActorType(CharacterFromID("Robert Christopher Silehard"));
			LAi_ActorRunToLocator(CharacterFromID("Robert Christopher Silehard"), "reload", "reload1", "silehard_escape_complete", 5.0);
		break;

		case "silehard_escape_complete":
			AddQuestRecord("Revenge_for_Silehard", 3);
			LAi_LocationFightDisable(&locations[FindLocation("Quest_Residence")], false);
			ChangeCharacterAddress(CharacterFromID("Robert Christopher Silehard"), "Redmond_residence", "goto8");
			//Locations[FindLocation("Redmond_town_01")].reload.l6.disable = 1;
			LAi_QuestDelay("soldier_in_residence", 1.5);
			ChangeCharacterAddress(CharacterFromID("researcher"), "oxbay_lighthouse", "goto24");

			LeaveService(PChar, ENGLAND, false); // RM
			if(GetRMRelation(PChar, ENGLAND) > REL_WAR) SetRMRelation(PChar, ENGLAND, REL_WAR); // RM - SetNationRelation2MainCharacter(ENGLAND,RELATION_ENEMY);
		break;

		case "soldier_in_residence":
			LAi_group_MoveCharacter(CharacterFromID("Eng Soldier for residence 01"), "ENGLAND_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Eng Soldier for residence 02"), "ENGLAND_SOLDIERS");
			ChangeCharacterAddressGroup(CharacterFromID("Eng Soldier for residence 01"), "Quest_residence", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Eng Soldier for residence 02"), "Quest_residence", "reload", "reload1");
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ENGLAND_SOLDIERS", "to_redmond_shore_01");
		break;

		case "to_redmond_shore_01":
			Locations[FindLocation("Quest_Residence")].reload.l1.go = "redmond_shore_01";
			Locations[FindLocation("Quest_Residence")].reload.l1.emerge = "reload2";
			Locations[FindLocation("Quest_Residence")].reload.l1.disable = 0;
			//DoQuestReloadToLocation("redmond_shore_01", "reload", "reload2", "both_escape_from_redmond_complete");
			PChar.quest.both_escape_from_redmond_complete.win_condition.l1 = "location";
			PChar.quest.both_escape_from_redmond_complete.win_condition.l1.location = "redmond_shore_01";
			PChar.quest.both_escape_from_redmond_complete.win_condition = "both_escape_from_redmond_complete";
		break;

		case "to_douwesen_shore_complete":
			AddQuestrecord("Where_are_i", 1);
			PlaceCharacter(CharacterFromID("peasant"), "goto");
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("peasant"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("peasant"), PChar, "to_douwesen_shore_complete_2", 2.0);
		break;

		case "to_douwesen_shore_complete_2":
			LAi_ActorWaitDialog(PChar, CharacterFromID("peasant"));
			LAi_ActorDialog(CharacterFromID("peasant"), PChar, "player_back", 2.0, 1.0);
			ChangeCharacterAddressGroup(CharacterFromID("Anacleto Rui Sa Pinto"), "Pirate_tavern", "sit", "sit4");
			bQuestDisableMapEnter = true;
		break;

		case "kill_Serrao_complete":
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], true);
			PChar.quest.main_line = "after_defeat_Serrao";
			LAi_type_actor_Reset(CharacterFromID("Gervasio Serrao"));
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Gervasio Serrao"));
			LAi_ActorDialogNow(CharacterFromID("Gervasio Serrao"), PChar, "player_back", -1);
			LAi_SetImmortal(CharacterFromID("Gervasio Serrao"), false);
		break;

		case "serrao_wait_for_hire":
			if (characters[GetCharacterIndex("Gervasio Serrao")].location.locator != "sit5")
			{
				LAi_Fade("serrao_wait_for_hire_2", "");
			}
		break;

		case "serrao_wait_for_hire_2":
			ChangeCharacterAddressGroup(CharacterFromID("Gervasio Serrao"), "pirate_tavern", "sit", "sit5");
			Lai_SetSitType(CharacterFromID("Gervasio Serrao"));
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
//			PChar.ship.type = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.type;
//			PChar.ship.name = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.name;
//			PChar.ship.nation = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].nation; // KK
//			SetCrewQuantity(PChar, 200);
//			SetBaseShipData(PChar);
			ExchangeCharacterShip(PChar, CharacterFromID("Anacleto Rui Sa Pinto")); // GR: you're taking Anacleto's ship, so take it, don't fake it
// KK -->
			// crew need something to eat
			AddCharacterGoods(PChar, GOOD_WHEAT, 70);
			AddCharacterGoods(PChar, GOOD_RUM, 35);
// <-- KK
			PChar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man1", "reload", "reload1");
			sld.headmodel = "h_man1";
			sld.id  = "temp_id_sld_fucker";
			sld.dialog.filename = "anacleto_dialog.c";
			sld.dialog.currentnode = "first time";
			LAi_SetActorType(sld);
//			LAi_SetStayType(PChar);
//			LAi_SetPlayerType(PChar);
			LAi_SetFightMode(PChar, false); // GR: If player kills Anacleto with one shot, player isn't automatically disarmed, so force it
			LAi_SetActorType(PChar);
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialog(sld, PChar, "sld_exit_from_pirate_tavern", 3.0, 1.0);
		break;

		case "sld_exit_from_pirate_tavern":
			LAi_SetPlayerType(PChar);
			LAi_ActorGoToLocation(CharacterFromID("temp_id_sld_fucker"), "reload", "reload1", "none", "", "", "", 10.0);
		break;

		case "kill_anacleto_complete_2":
// KK -->
			Lai_SetActorType(PChar);
			LAi_type_actor_Reset(PChar);
			Lai_SetPlayerType(PChar);
// <-- KK
			LAi_LocationFightDisable(&locations[Findlocation("pirate_tavern")], true);
//			PChar.ship.type = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.type;
//			PChar.ship.name = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].ship.name;  // KK
//			PChar.ship.nation = characters[GetCharacterIndex("Anacleto Rui Sa Pinto")].nation; // KK
//			SetCrewQuantity(PChar, 200);
//			SetBaseShipData(PChar);
			ExchangeCharacterShip(PChar, CharacterFromID("Anacleto Rui Sa Pinto")); // GR: you're taking Anacleto's ship, so take it, don't fake it
// KK -->
			// crew need something to eat
			AddCharacterGoods(PChar, GOOD_WHEAT, 70);
			AddCharacterGoods(PChar, GOOD_RUM, 35);
// <-- KK
			PChar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
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
			PChar.quest.main_line = "blaze_search_danielle_again_10";
		break;


		case "danielle_MetBlazeOnIslaMuelle_Exit":
			LAi_ActorGoToLocator(CharacterFromID("danielle"), "reload", "reload2", "Story_BlazeMetDanielleOnIslaMuelle", 10.0);
		break;

		case "kill_Ogario_fight":
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			LAi_LocationFightDisable(&Locations[FindLocation("Sidonio Ogarrio House")], false);
			Ambush("Rich_Citizens", 3, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
			Lai_group_MoveCharacter(CharacterFromID("Sidonio Ogarrio"), LAI_DEFAULT_GROUP);
			LAi_ActorAttack(CharacterFromID("Sidonio Ogarrio"), PChar, "");
		break;

		case "kill_Ogario_complete":
			DisableFastTravel(false);
			EndQuestMovie();
			characters[GetCharacterIndex("Wilfred Bythesea")].quest.kill_Ogarrio = "Almost_complete";
			AddQuestRecord("Kill_Ogario", 2);
			CloseQuestHeader("Kill_Ogario");
		break;

		case "kill_Ogario_timeout":
			ChangeCharacterAddress(CharacterFromID("Wilfred Bythesea"), "None", "");
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
			ChangeCharacterAddress(CharacterFromID("Wilfred Bythesea"), "None", "");
		break;

		case "soldier_goto_to_mine_commander":
			ChangeCharacterAddress(CharacterFromID("mine_soldier_01"), "none", "none");
			LAi_QuestDelay("soldier_goto_to_mine_commander_2", 0.5);
		break;

		case "soldier_goto_to_mine_commander_2":
			ChangeCharacterAddressGroup(CharacterFromID("mine_commander"), "Oxbay_mine", "reload", "reload1");
			LAi_setActorType(CharacterFromID("Mine_commander"));
			LAi_ActorDialog(CharacterFromID("mine_commander"), PChar, "", 12.0, 0);
		break;

		case "commendant_exit_from_mines_complete":
			ChangeCharacterAddress(CharacterFromID("mine_commander"), "Mines_commander_house", "goto3");
			LAi_SetGuardianType(CharacterFromID("mine_commander"));
			RestorePassengers("Blaze");
			PChar.money = PChar.tempmoney;
			PChar.tempmoney = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l2.disable = 0;
		break;

		case "commendant_exit_2_from_mines_complete":
			ChangeCharacterAddress(CharacterFromID("mine_commander"), "Mines_commander_house", "goto3");
			LAi_ActorDialog(CharacterFromID("Leborio Drago"), PChar, "", 5.0, 0);
		break;

		case "wait_for_resque_from_mines":
			LAi_Fade("mine_soldier_return_to_post", "wait_for_resque_from_mines_complete");
		break;

		case "mine_soldier_return_to_post":
			ChangeCharacterAddress(CharacterFromID("mine_soldier_01"), "Oxbay_mine", "goto9");
			LAi_SetGuardianType(CharacterFromID("mine_soldier_01"));
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_01"), "ENGLAND_SOLDIERS");
		break;

		case "wait_for_resque_from_mines_complete":
			PChar.quest.main_line = "lets_go_mines";
			LAi_SetActorType(CharacterFromID("Leborio Drago"));
			LAi_ActorDialog(CharacterFromID("Leborio Drago"), PChar, "", 1.0, 1.0);
		break;

		case "lets_go_begin":
			PChar.location.from_sea = "Oxbay_lighthouse";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			LAi_SetImmortal(CharacterFromID("leborio drago"), true);
			GiveItem2Character(CharacterFromID("Leborio Drago"),"blade4");
			GiveItem2Character(CharacterFromID("Miner_01"),"blade4");
			GiveItem2Character(CharacterFromID("Miner_02"),"blade4");
			GiveItem2Character(CharacterFromID("Miner_03"),"blade4");
			GiveItem2Character(CharacterFromID("Miner_05"),"blade4");
			GiveItem2Character(PChar, "blade4");
			EquiPCharacterByItem(PChar, "blade4");
			EquiPCharacterByItem(CharacterFromID("Leborio Drago"), "blade4");
			EquiPCharacterByItem(CharacterFromID("Miner_01"),"blade4");
			EquiPCharacterByItem(CharacterFromID("Miner_02"),"blade4");
			EquiPCharacterByItem(CharacterFromID("Miner_03"),"blade4");
			EquiPCharacterByItem(CharacterFromID("Miner_05"),"blade4");
			LAi_SetHP(CharacterFromID("Leborio Drago"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("Miner_01"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("Miner_02"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("Miner_03"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("Miner_05"), 80.0, 80.0);

			PChar.quest.main_line = "lets_go";
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 1;
			LAi_SetOfficerType(CharacterFromID("Leborio Drago"));
			LAi_SetOfficerType(CharacterFromID("Miner_01"));
			LAi_SetOfficerType(CharacterFromID("Miner_02"));
			LAi_SetOfficerType(CharacterFromID("Miner_03"));
			LAi_SetOfficerType(CharacterFromID("Miner_05"));

			LAi_QuestDelay("lets_go_begin_2", 1.0);
		break;

		case "lets_go_begin_2":
			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
			PChar.quest.to_canyon.win_condition.l1 = "location";
			PChar.quest.to_canyon.win_condition.l1.location = "Oxbay_canyon";
			PChar.quest.to_canyon.win_condition = "to_canyon_complete";

			PChar.quest.mine_soldiers_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.mine_soldiers_dead.win_condition.l1.character = "Mine_soldier_02";
			PChar.quest.mine_soldiers_dead.win_condition.l2 = "NPC_Death";
			PChar.quest.mine_soldiers_dead.win_condition.l2.character = "Mine_soldier_03";
			PChar.quest.mine_soldiers_dead.win_condition.l3 = "NPC_Death";
			PChar.quest.mine_soldiers_dead.win_condition.l3.character = "Mine_soldier_04";
			PChar.quest.mine_soldiers_dead.win_condition = "mine_soldiers_dead_complete";
		break;

		case "mine_soldiers_dead_complete":
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l1.disable = 0;
			Locations[FindLocation("Oxbay_mine")].reload.l2.disable = 0;
			if (!LAi_IsDead(CharacterFromID("Leborio Drago")))
			{
				LAi_SetActorType(CharacterFromID("Leborio Drago"));
				LAi_ActorRunToLocation(CharacterFromID("Leborio Drago"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_1", "", 20.0);
			}
			if (!LAi_IsDead(CharacterFromID("Miner_01")))
			{
				LAi_SetActorType(CharacterFromID("Miner_01"));
				// --> Swindler
				// Here's a syntax error:
				// LAi_ActorRunToLocation(CharacterFromID("Miner_01"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_2", "", 20.0.);
				LAi_ActorRunToLocation(CharacterFromID("Miner_01"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_2", "", 20.0);
				// Swindler <--

			}
			if (!LAi_IsDead(CharacterFromID("Miner_02")))
			{
				LAi_SetActorType(CharacterFromID("Miner_02"));
				LAi_ActorRunToLocation(CharacterFromID("Miner_02"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_2", "", 20.0);
			}
			if (!LAi_IsDead(CharacterFromID("Miner_03")))
			{
				LAi_SetActorType(CharacterFromID("Miner_03"));
				LAi_ActorRunToLocation(CharacterFromID("Miner_03"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_3", "", 20.0);
			}
			if (!LAi_IsDead(CharacterFromID("Miner_05")))
			{
				LAi_SetActorType(CharacterFromID("Miner_05"));
				LAi_ActorRunToLocation(CharacterFromID("Miner_05"), "reload", "reload1", "Oxbay_canyon", "officers", "reload4_4", "", 20.0);
			}
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 1;
		break;

		case "to_canyon_complete":
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			PlaceCharacter(CharacterFromID("Leborio drago"), "officers");
			PlaceCharacter(CharacterFromID("Miner_01"), "officers");
			PlaceCharacter(CharacterFromID("Miner_02"), "officers");
			PlaceCharacter(CharacterFromID("Miner_03"), "goto");
			PlaceCharacter(CharacterFromID("Miner_05"), "goto");
			LAi_SetOfficerType(CharacterFromID("Leborio Drago"));
			LAi_SetOfficerType(CharacterFromID("Miner_01"));
			LAi_SetOfficerType(CharacterFromID("Miner_02"));
			LAi_SetOfficerType(CharacterFromID("Miner_03"));
			LAi_SetOfficerType(CharacterFromID("Miner_05"));

			PChar.quest.to_lighthouse.win_condition.l1 = "location";
			PChar.quest.to_lighthouse.win_condition.l1.location = "Oxbay_lighthouse";
			PChar.quest.to_lighthouse.win_condition = "to_lighthouse_complete";

			PChar.quest.peace_when_we_are_leaving_canyon.win_condition.l1 = "ExitFromLocation";
			PChar.quest.peace_when_we_are_leaving_canyon.win_condition.l1.location = "Oxbay_canyon";
			PChar.quest.peace_when_we_are_leaving_canyon.win_condition = "peace_when_we_are_leaving_canyon";

			LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);

			PChar.quest.canyon_soldiers_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.canyon_soldiers_dead.win_condition.l1.character = "Mine_soldier_05";
			PChar.quest.canyon_soldiers_dead.win_condition.l2 = "NPC_Death";
			PChar.quest.canyon_soldiers_dead.win_condition.l2.character = "Mine_soldier_06";
			PChar.quest.canyon_soldiers_dead.win_condition = "canyon_soldiers_dead_complete";
		break;

		case "peace_when_we_are_leaving_canyon":
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 0;
			LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		break;

		case "canyon_soldiers_dead_complete":
			if (!LAi_IsDead(CharacterFromID("Leborio Drago")))
			{
				LAi_SetActorType(CharacterFromID("Leborio Drago"));
				LAi_ActorRunToLocation(CharacterFromID("Leborio Drago"), "reload", "reload6_back", "Oxbay_lighthouse", "officers", "reload1_1", "", 45.0);
			}
			if (!LAi_IsDead(CharacterFromID("Miner_01")))
			{
				LAi_SetActorType(CharacterFromID("Miner_01"));
				LAi_ActorRunToLocation(CharacterFromID("Miner_01"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
			if (!LAi_IsDead(CharacterFromID("Miner_02")))
			{
				LAi_SetActorType(CharacterFromID("Miner_02"));
				LAi_ActorRunToLocation(CharacterFromID("Miner_02"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
			if (!LAi_IsDead(CharacterFromID("Miner_03")))
			{
				LAi_SetActorType(CharacterFromID("Miner_03"));
				LAi_ActorRunToLocation(CharacterFromID("Miner_03"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
			if (!LAi_IsDead(CharacterFromID("Miner_05")))
			{
				LAi_SetActorType(CharacterFromID("Miner_05"));
				LAi_ActorRunToLocation(CharacterFromID("Miner_05"), "reload", "reload6_back", "none", "reload", "reload1", "", 45.0);
			}
		break;

		case "to_lighthouse_complete":
			LAi_SetImmortal(CharacterFromID("leborio drago"), false);
			EnableEquip(PChar, BLADE_ITEM_TYPE, true);
			EnableEquip(PChar, GUN_ITEM_TYPE, true);
			EquiPCharacterByItem(PChar, FindCharacterItemByGroup(PChar, BLADE_ITEM_TYPE));
			EquiPCharacterByItem(PChar, FindCharacterItemByGroup(PChar, GUN_ITEM_TYPE));
			ChangeCharacterAddress(CharacterFromID("Miner_01"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Miner_02"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Miner_03"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Miner_05"), "none", "none");
			restorepassengers("Blaze");
			PChar.money = PChar.tempmoney;
			RestorePassengers(PChar.id);
			PChar.tempmoney = "0";
			Locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			PChar.quest.main_line = "after_speak_with_leborio";
			LAi_type_actor_Reset(CharacterFromID("Leborio Drago"));
			ChangeCharacterAddressGroup(CharacterFromID("Leborio Drago"), "Oxbay_lighthouse", "officers", "reload1_1");
			characters[GetCharacterIndex("Leborio Drago")].quest.hire = "ask_for_hire";
			LAi_ActorDialog(CharacterFromID("Leborio Drago"), PChar, "", 2.0, 1.0);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 15000); }
			else { AddPartyExp(PChar, 15000); }
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("search_danielle", 16);
			Preprocessor_Remove("Danielle");
		break;

		case "hired_leborio_complete":
			LAi_SetOfficerType(CharacterFromID("leborio drago"));
		break;

		case "resque_danielle":
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.name = "reload1";
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.go = "Muelle_port";
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.emerge = "reload2";
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.autoreload = 0;
			Locations[FindLocation("Quest_Muelle_town_01")].reload.l1.label = "port";

			LAi_ActorRunToLocator(CharacterFromID("danielle"), "reload", "reload1", "danielle_to_muelle_port", 30.0);

			PChar.quest.to_secret_oxbay_shore.win_condition.l1 = "location";
			PChar.quest.to_secret_oxbay_shore.win_condition.l1.location = "Redmond_shore_01";
			PChar.quest.to_secret_oxbay_shore.win_condition = "to_secret_oxbay_shore_complete";
		break;

		case "danielle_to_muelle_port":
			ChangeCharacterAddress(CharacterFromID("danielle"), "none", "");
		break;

		case "wait_for_night_in_shore":
			SetCurrentTime(23, 0);
		//	LAi_Fade("", "to_secret_oxbay_shore_complete2");
			DoQuestReloadToLocation("Redmond_shore_01", "reload", "reload1", "to_secret_oxbay_shore_complete2");
		break;

		case "exit_after_speak_with_rheims":
			LAi_SetActorType(CharacterFromID("danielle"));
			SetMainCharacterIndex(0);
			PChar = GetMainCharacter(); // PB: This is IMPORTANT to update that you are now 'Blaze' again
			LAi_SetImmortal(PChar, false);
			ChangeCharacterAddress(CharacterFromID("Danielle"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Vincent Bethune"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Raoul Rheims"), "none", "none");
			DoQuestReloadToLocation("Rheims_house_inside", "goto", "goto5", "exit_after_speak_with_rheims_2");
			Locations[FindLocation("Douwesen_port")].reload.l2.disable = 0;
			Locations[FindLocation("Douwesen_port")].reload.l3.disable = 0;
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = 0;
			Locations[FindLocation("Douwesen_shore_02")].reload.l2.disable = 0;
			PChar.quest.main_line = "danielle_speak_with_almost_dead_rheims_complete";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromID("Danielle"))));
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
			restorepassengers(PChar.id);

			RemoveCharacterEquip(CharacterFromID("danielle"), BLADE_ITEM_TYPE);
			GiveItem2Character(CharacterFromID("danielle"), "blade6");
			EquiPCharacterByItem(CharacterFromID("danielle"), "blade6");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Sneak", 1000); }
			else { AddPartyExp(PChar, 10000); }
		break;

		case "exit_after_speak_with_rheims_2":
			LAi_SetPlayerType(CharacterFromID("blaze"));
		break;

		case "bad_swimming_in_oxbay":
			LAi_SetActorType(CharacterFromID("Anacleto Rui Sa Pinto"));
			ChangeCharacterAddress(CharacterFromID("Anacleto Rui Sa Pinto"), "ship_deck", "goto2");
			ChangeCharacterAddress(CharacterFromID("pirate for abordage 01"), "ship_deck", "goto1");
			ChangeCharacterAddress(CharacterFromID("pirate for abordage 02"), "ship_deck", "goto3");
			ChangeCharacterAddress(CharacterFromID("pirate for abordage 03"), "ship_deck", "goto4");
			DoQuestReloadToLocation("ship_deck", "reload", "locator2", "bad_swimming_in_oxbay_complete");
		break;

		case "bad_swimming_in_oxbay_complete":
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Anacleto Rui Sa Pinto"));
			LAi_ActorFollow(PChar, CharacterFromID("Anacleto Rui Sa Pinto"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("Anacleto Rui Sa Pinto"), PChar, "bad_swimming_in_oxbay_complete_1", 2.0);
		break

		case "bad_swimming_in_oxbay_complete_1":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Anacleto Rui Sa Pinto"));
// KK -->
			if (PChar.quest.main_line == "Just_before_escape_from_Anacleto_ship")
				LAi_ActorDialog(CharacterFromID("Anacleto Rui Sa Pinto"), PChar, "bad_swimming_in_oxbay_complete_2", 3.0, 0);
			else
				LAi_ActorDialog(CharacterFromID("Anacleto Rui Sa Pinto"), PChar, "player_back", 3.0, 0);
// <-- KK
		break;

// KK -->
		case "bad_swimming_in_oxbay_complete_2":
			LAi_fade("", "bad_swimming_in_oxbay_complete_3");
		break;

		case "bad_swimming_in_oxbay_complete_3":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("Anacleto Rui Sa Pinto"));
			LAi_ActorDialog(CharacterFromID("Anacleto Rui Sa Pinto"), PChar, "player_back", 3.0, 0);
		break;
// <-- KK

		case "swimming_to_lighthouse":
			ChangeCharacterAddressGroup(CharacterFromID("researcher"), "Oxbay_Lighthouse", "officers", "reload3_1");
			DoQuestReloadToLocation("Oxbay_lighthouse", "reload", "reload3", "to_lighthouse_see_tartane_complete");
// KK			worldMap.playerShipX = 176.27;
// KK			worldMap.playerShipZ = 35.34;
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Oxbay.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Oxbay.position.rz);
			PChar.location.from_sea = "Oxbay_lighthouse";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			PChar.ship.type = "Tartane1" // PS - SHIP_TARTANE;
// KK -->
			PChar.ship.name = characters[GetCharacterIndex("researcher")].ship.name;
			SetBaseShipData(PChar);
			PChar.ship.stats.nation = ENGLAND;
			SetCrewQuantity(PChar, 3);
			SetCharacterGoods(PChar, GOOD_BALLS, 0);
			SetCharacterGoods(PChar, GOOD_GRAPES, 0);
			SetCharacterGoods(PChar, GOOD_KNIPPELS, 0);
			AddCharacterGoods(PChar, GOOD_WHEAT, 2);
			AddCharacterGoods(PChar, GOOD_RUM, 2);
// <-- KK
			setCharacterShipLocation(CharacterFromID("researcher"), "none");
			setCharacterShipLocation(PChar, "Oxbay_Lighthouse");
		break;

		case "without_ship_complete":
			LAi_fade("", "to_lighthouse_see_tartane_complete_3");
		break;

		case "to_lighthouse_see_tartane_complete":
			PChar.quest.main_line = "without_ship";
			PlaceCharacter(CharacterFromID("researcher"), "goto");
			LAi_SetActorType(CharacterFromID("researcher"));
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("researcher"), "", 3.0);
			LAi_ActorFollow(CharacterFromID("researcher"), PChar, "to_lighthouse_see_tartane_complete_2", 3.0);
		break;

		case "to_lighthouse_see_tartane_complete_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "player_back", 1.0, 1.0);
		break;

		case "to_lighthouse_see_tartane_complete_3":
			PChar.quest.main_line = "see_yaht";
			LAi_SetActorType(CharacterFromID("researcher"));
			LAi_ActorDialog(CharacterFromID("researcher"), PChar, "", 5.0, 1.0);
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
			PChar.quest.first_portal.win_condition.l1 = "locator";
			PChar.quest.first_portal.win_condition.l1.location = "Treasure_alcove";
			PChar.quest.first_portal.win_condition.l1.locator_group = "teleport";
			PChar.quest.first_portal.win_condition.l1.locator = "teleport1";
			PChar.quest.first_portal.win_condition = "first_portal";

			PChar.quest.second_portal.win_condition.l1 = "locator";
			PChar.quest.second_portal.win_condition.l1.location = "Treasure_alcove";
			PChar.quest.second_portal.win_condition.l1.locator_group = "teleport";
			PChar.quest.second_portal.win_condition.l1.locator = "teleport2";
			PChar.quest.second_portal.win_condition = "second_portal";

			PChar.quest.third_portal.win_condition.l1 = "locator";
			PChar.quest.third_portal.win_condition.l1.location = "Treasure_alcove";
			PChar.quest.third_portal.win_condition.l1.locator_group = "teleport";
			PChar.quest.third_portal.win_condition.l1.locator = "teleport3";
			PChar.quest.third_portal.win_condition = "third_portal";

			PChar.quest.fourth_portal.win_condition.l1 = "locator";
			PChar.quest.fourth_portal.win_condition.l1.location = "Treasure_alcove";
			PChar.quest.fourth_portal.win_condition.l1.locator_group = "teleport";
			PChar.quest.fourth_portal.win_condition.l1.locator = "teleport4";
			PChar.quest.fourth_portal.win_condition = "fourth_portal";

			PChar.quest.fifth_portal.win_condition.l1 = "locator";
			PChar.quest.fifth_portal.win_condition.l1.location = "Treasure_alcove";
			PChar.quest.fifth_portal.win_condition.l1.locator_group = "teleport";
			PChar.quest.fifth_portal.win_condition.l1.locator = "teleport5";
			PChar.quest.fifth_portal.win_condition = "fifth_portal";

			PChar.quest.monster_portal.win_condition.l1 = "locator";
			PChar.quest.monster_portal.win_condition.l1.location = "Treasure_alcove";
			PChar.quest.monster_portal.win_condition.l1.locator_group = "teleport";
			PChar.quest.monster_portal.win_condition.l1.locator = "teleport0";
			PChar.quest.monster_portal.win_condition = "monster_portal";
		break;

		case "empting_portals":
			PChar.quest.first_portal.over = "yes";
			PChar.quest.second_portal.over = "yes";
			PChar.quest.third_portal.over = "yes";
			PChar.quest.fourth_portal.over = "yes";
			PChar.quest.fifth_portal.over = "yes";
			PChar.quest.monster_portal.over = "yes";
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
			ChangeCharacterAddress(CharacterFromID("danielle"), "Treasure_alcove", "teleport2_1");
			ChangeCharacterAddress(CharacterFromID("researcher"), "Treasure_alcove", "teleport2_2");
			ChangeCharacterAddressGroup(PChar, "Treasure_alcove", "teleport", "teleport2");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "teleport_2_1":
			ChangeCharacterAddress(CharacterFromID("danielle"), "Treasure_alcove", "teleport1_1");
			ChangeCharacterAddress(CharacterFromID("researcher"), "Treasure_alcove", "teleport1_2");
			ChangeCharacterAddressGroup(PChar, "Treasure_alcove", "teleport", "teleport1");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "teleport_3_4":
			ChangeCharacterAddress(CharacterFromID("danielle"), "Treasure_alcove", "teleport4_1");
			ChangeCharacterAddress(CharacterFromID("researcher"), "Treasure_alcove", "teleport4_2");
			ChangeCharacterAddressGroup(PChar, "Treasure_alcove", "teleport", "teleport4");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "teleport_4_3":
			ChangeCharacterAddress(CharacterFromID("danielle"), "Treasure_alcove", "teleport3_1");
			ChangeCharacterAddress(CharacterFromID("researcher"), "Treasure_alcove", "teleport3_2");
			ChangeCharacterAddressGroup(PChar, "Treasure_alcove", "teleport", "teleport3");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "teleport_5_treasure":
			ChangeCharacterAddress(CharacterFromID("danielle"), "Treasure_alcove", "teleport6_1");
			ChangeCharacterAddress(CharacterFromID("researcher"), "Treasure_alcove", "teleport6_2");
			ChangeCharacterAddressGroup(PChar, "Treasure_alcove", "teleport", "teleport6");
			//LAi_QuestDelay("recharge_portals", 1.0);
		break;

		case "monster_portal":
			//LAi_QuestDelay("empting_portals", 0.0);
			LAi_fade("", "monster_generate_in_alcove");
			PlayStereoSound("Ambient\INCA TEMPLE\teleporter.wav");
			LAi_QuestDelay("recharge_portals", 2.0);
		break;

		case "monster_generate_in_alcove":
			//ChangeCharacterAddressGroup(PChar, "Treasure_alcove", "teleport", "teleport0");

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
			AddMoneyToCharacter(PChar, -10000);
			GiveItem2Character(PChar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			PChar.quest.prepare_fighting_on_deck_complete.over = "yes";
			PChar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 13);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 4000); }
			else { AddPartyExp(PChar, 4000); }
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "alistar_garcilaso_money_2":
			AddMoneyToCharacter(PChar, -8000);
			GiveItem2Character(PChar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			PChar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 13);
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 5000); }
			else { AddPartyExp(PChar, 5000); }
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "alistar_garcilaso_idols":
			GiveItem2Character(PChar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			PChar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 14);
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle_sailor")], "none", "none");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 6000); }
			else { AddPartyExp(PChar, 6000); }
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

		case "alistar_garcilaso_idols_2":
			GiveItem2Character(PChar, "icollection");
			Group_SetAddress("Pirate Captain 06", "none", "Quest_Ships","Quest_Ship_9");
			PChar.quest.main_line = "blaze_to_incas_collection_begin_8";
			AddQuestRecord("blaze_to_incas_collection", 14);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 6000); }
			else { AddPartyExp(PChar, 6000); }
			SetCharacterShipLocation(&characters[GetCharacterIndex("Pirate Captain 05")], "none");
			ChangeCharacterAddress(&characters[GetCharacterIndex("Danielle_sailor")], "none", "none");
			characters[GetCharacterIndex("Robert Christopher Silehard")].dialog.CurrentNode = "incas_collection_complete_node";
		break;

// NK -->
		case "ReturnCelestin":
			changeCharacterAddress(CharacterFromID("Celestin Fammeree"), "Falaise_de_Fleur_location_03", "sitizen07");
		break;
// NK <--

		case "blaze_fighting_with_amiel_berangere":
			LAi_LocationFightDisable(&Locations[FindLocation("Falaise_de_fleur_tavern_upstairs")], false);
			//---Эмиль нападает на Блэйза
			LAi_SetImmortal(CharacterFromID("Amiel Berangere"), false);
			LAi_ActorAttack(CharacterFromID("Amiel Berangere"), PChar, "");
			locations[FindLocation("Falaise_De_Fleur_tavern_upstairs")].reload.l1.disable = 1;
			//----Отключается локатор выхода из комнаты
			//-------Убимраем ненужного Фауста Гаске
			ChangeCharacterAddress(CharacterFromID("Faust Gasquet"), "None", "");

			PChar.quest.Story_BlazeStartsThinkAboutGramota.win_condition.l1 = "NPC_death";
			PChar.quest.Story_BlazeStartsThinkAboutGramota.win_condition.l1.character = "Amiel Berangere";
			PChar.quest.Story_BlazeStartsThinkAboutGramota.win_condition = "Story_BlazeStartsThinkAboutGramota";
		break;

		case "Glover_exit":
			PChar.Quest.Story_Ask_for_Glover.over = "yes";
			ChangeCharacterAddressGroup(CharacterFromID("Ewan Glover"), "Redmond_tavern", "reload", "reload1");
			LAi_SetActorType(CharacterFromID("Ewan Glover"));
			LAi_ActorDialog(CharacterFromID("Ewan Glover"), PChar, "", 50, 0);
		break;

		case "CounterSpy_Talk_AfterTavern_exit":
			AddQuestRecord("Story_2ndTask",11);
			PChar.quest.Story_LeaveOxbayWithRabelAndCounterspy.win_condition.l1 = "location";
			PChar.quest.Story_LeaveOxbayWithRabelAndCounterspy.win_condition.l1.location = "Oxbay_port";
			PChar.quest.Story_LeaveOxbayWithRabelAndCounterspy.win_condition = "Story_LeaveOxbayWithRabelAndCounterspy";

			/*PChar.quest.Story_RabelGoesToPort.win_condition.l1 = "locator";
			PChar.quest.Story_RabelGoesToPort.win_condition.l1.character = "Rabel Iverneau";
			PChar.quest.Story_RabelGoesToPort.win_condition.l1.location = "Oxbay_town";
			PChar.quest.Story_RabelGoesToPort.win_condition.l1.locator_group = "reload";
			PChar.quest.Story_RabelGoesToPort.win_condition.l1.locator = "reload1";
			PChar.quest.Story_RabelGoesToPort.win_condition = "Story_RabelGoesToPort";

			PChar.quest.Story_CounterspyGoesToPort.win_condition.l1 = "locator";
			PChar.quest.Story_CounterspyGoesToPort.win_condition.l1.character = "Counterspy";
			PChar.quest.Story_CounterspyGoesToPort.win_condition.l1.location = "Oxbay_town";
			PChar.quest.Story_CounterspyGoesToPort.win_condition.l1.locator_group = "reload";
			PChar.quest.Story_CounterspyGoesToPort.win_condition.l1.locator = "reload1";
			PChar.quest.Story_CounterspyGoesToPort.win_condition = "Story_CounterspyGoesToPort";*/
			LAi_ActorRunToLocation(CharacterFromID("counterspy"), "reload", "reload1", "none", "", "", "", 45.0);
			LAi_ActorRunToLocation(CharacterFromID("Rabel Iverneau"), "reload", "reload1", "none", "", "", "", 45.0);

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
						if (HasSubStr(PChar.quest.counterspy_fleet.(temp), "Enc_Officer")) LAi_StoreFantom(CharacterFromID(PChar.quest.counterspy_fleet.(temp))); // Prevent character from being overwritten by another "Enc_Officer"
						RemoveCharacterCompanion(PChar, characters[cc]);
					}
					else PChar.quest.counterspy_fleet.(temp) = "*NULL*";
				}
			}
// <-- GR
			ExchangeCharacterShip(CharacterFromID("Rabel Iverneau"), PChar);
			ExchangeCharacterShip(CharacterFromID("Rabel Iverneau"), CharacterFromID("Ship Storage"));
			SetCharacterShipLocation(PChar, "Oxbay_port");
			//LAi_ActorRunToLocator(CharacterFromID("Rabel Iverneau"), "reload", "reload1", "Story_RabelGoesToPort", 20.0.0);
		break;

		case "Counterspy_Exit_fight":
			//----------Появление солдат в таверне
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, "FRANCE_SOLDIERS", LAI_GROUP_NEUTRAL);
			ChangeCharacterAddressGroup(CharacterFromID("Fra_arrester_01"), "Oxbay_Tavern", "Reload", "Reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Fra_arrester_02"), "Oxbay_Tavern", "Reload", "Reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Fra_arrester_03"), "Oxbay_Tavern", "Reload", "Reload1");

			LAi_SetActorType(CharacterFromID("Fra_arrester_01"));
			LAi_SetActorType(CharacterFromID("Fra_arrester_02"));
			LAi_SetActorType(CharacterFromID("Fra_arrester_03"));

			LAi_ActorFollow(CharacterFromID("Fra_arrester_02"), CharacterFromID("Fra_arrester_01"), "", 15.0);
			LAi_ActorFollow(CharacterFromID("Fra_arrester_03"), CharacterFromID("Fra_arrester_01"), "", 15.0);
			LAi_ActorDialog(CharacterFromID("Fra_arrester_01"), PChar, "", 10.0, 1.0);
			LAi_Fade("Counterspy_Exit_fight_2", "");
		break;

		case "Counterspy_Exit_fight_2":
			PlaceCharacter(CharacterFromID("counterspy"), "goto");
			LAi_SetOfficerType(CharacterFromID("counterspy"));
			LAi_SetImmortal(CharacterFromID("counterspy"), true);
		break;

		case "Counterspy_After_Fight_Exit":
			//-------------Заводится квест на попадание в верфь Оксбэя
			PChar.quest.Story_Goto_Oxbay_shipyard_with_Counterspy.win_condition.l1 = "location";
			PChar.quest.Story_Goto_Oxbay_shipyard_with_Counterspy.win_condition.l1.location = "Oxbay_shipyard";
			PChar.quest.Story_Goto_Oxbay_shipyard_with_Counterspy.win_condition = "Story_Goto_Oxbay_shipyard_with_Counterspy";

			//-------------Заводится квест на Попытку сбежать из города в джунгли
			PChar.quest.Story_PlayerTriesToRunFromOxbay.win_condition.l1 = "location";
			PChar.quest.Story_PlayerTriesToRunFromOxbay.win_condition.l1.location = "Oxbay_town_exit";
			PChar.quest.Story_PlayerTriesToRunFromOxbay.win_condition = "Story_PlayerTriesToRunFromOxbay";

			//-----------Присоединение шпиона в качестве офицера
			SetOfficersIndex(PChar, 3, GetCharacterIndex("CounterSpy"));
			SetCharacterRemovable(CharacterFromID("Counterspy"), false);
			LAi_SetActorType(CharacterFromID("Oweyn McDorey"));
			ChangeCharacterAddress(CharacterFromID("Oweyn McDorey"), "Oxbay_Shipyard", "Goto8");
		break;

		case "CounterSpy_Ready_for_meeting_exit":
			SetCharacterRemovable(CharacterFromID("Counterspy"), true);
//			RemovePassenger(PChar, CharacterFromID("Counterspy"));	// GR: was 'RemovePassenger(PChar, getCharacterIndex("Counterspy"))' which is wrong.  Quest did not break because "Counterspy" has already been removed
// KK -->
			if (GetNotCaptivePassengersQuantity(PChar) > 0) {
				GiveShipCommandToOfficer(PChar.id, GetNotCaptivePassenger(PChar, GetNotCaptivePassengersQuantity(PChar) - 1));
			}
// <-- KK
			LAi_SetSitType(CharacterFromID("Rabel Iverneau"));
			LAi_SetImmortal(CharacterFromID("Rabel Iverneau"), true);
			SetCharacterShipLocation(&Characters[GetCharacterIndex("Rabel Iverneau")], "Oxbay_port");
			ChangeCharacterAddressGroup(CharacterFromID("Rabel Iverneau"), "Oxbay_tavern", "Sit", "Sit4");
		break;

		case "counterspy_Officer_money_exit":
			LAi_Fade("counterspy_Officer_money_exit_2", "Story_WaitingForEveningInTheShipyard");
		break;

		case "counterspy_Officer_money_exit_2":
			SetCurrentTime(22, 0);
			//WaitDate("",0,0,0,0,1);
			LAi_SetSitType(CharacterFromID("Oweyn McDorey"));
			ChangeCharacterAddressGroup(CharacterFromID("Oweyn McDorey"), "Oxbay_shipyard", "Sit", "Sit_1");
		break;

		case "arrest_in_tavern_for_fra_occupants":
			LAi_LocationFightDisable(&Locations[FindLocation("Oxbay_tavern")], false);
			LAi_SetWarriorType(CharacterFromID("Fra_arrester_01"));
			LAi_SetWarriorType(CharacterFromID("Fra_arrester_02"));
			LAi_SetWarriorType(CharacterFromID("Fra_arrester_03"));
			LAi_group_MoveCharacter(CharacterFromID("Fra_arrester_01"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Fra_arrester_02"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("Fra_arrester_03"), "FRANCE_SOLDIERS");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("FRANCE_SOLDIERS", "Story_KillFrenchArresters");
			LAi_SetImmortal(CharacterFromID("Counterspy"), true);
		break;

		case "vincent_exit_from_tavern":
			LAi_ActorGoToLocator(CharacterFromID("Vincent bethune"), "reload", "reload1", "vincent_away_from_tavern_complete", 90.0);
			PChar.quest.main_line = "vincent_away_from_douwesen_tavern";
		break;

		case "turpin_cabanel_story_exit":
//boal -->
			AddQuestRecord("Story_1stTaskReceived", 11);
//boal <--
			PChar.quest.turpin_cabanel_story_exit_2.win_condition.l1 = "location";
			PChar.quest.turpin_cabanel_story_exit_2.win_condition.l1.location = "Falaise_de_fleur_port_01";
			PChar.quest.turpin_cabanel_story_exit_2.win_condition = "turpin_cabanel_story_exit_2";
		break;

		case "turpin_cabanel_story_exit_2":
			LAi_SetCitizenType(CharacterFromID("Tancrede Rimbaud"));
			LAi_type_actor_Reset(CharacterFromID("Virgile Boon"));
			LAi_ActorDialog(CharacterFromID("Virgile Boon"), PChar, "", 25.0, 1.0);
		break;

// GR: -->	case "turpin_cabanel_fight": moved to "quests_side.c"

		case "researcher_I_go_to_the_right_exit":
			LAi_SetActorType(PChar);
			RemovePassenger(PChar, CharacterFromID("Researcher"));
			LAi_SetActorType(CharacterFromID("Researcher"));
			characters[GetCharacterIndex("researcher")].location = "labirint1";
			LAi_ActorRunToLocator(CharacterFromID("researcher"), "goto", "goto2", "", 25.0);
			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "First time";
			LAi_ActorRunToLocator(PChar, "goto", "goto11", "Story_TimeToGoIntoCentralPassage", 15.0);
		break;

		case "researcher_split_exit":
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "I'm going on left";
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 30.0, 5);
		break;

		case "Speak_with_lighthouse_guards":
			LAi_SetActorType(CharacterFromID("lighthouse_officer"));
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("lighthouse_officer"), "", 2.0);
			LAi_ActorFollow(CharacterFromID("lighthouse_officer"), PChar, "Speak_with_lighthouse_guards_2", 2.0);
		break;

		case "Speak_with_lighthouse_guards_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("lighthouse_officer"));
			LAi_ActorDialog(CharacterFromID("lighthouse_officer"), PChar, "player_back", 2.0, 1.0);
		break;

		case "researcher_captured_exit_fight":
			LAi_group_MoveCharacter(CharacterFromID("lighthouse_officer"), "LIGHTHOUSE_SOLDIERS");
			LAi_group_SetHearRadius("LIGHTHOUSE_SOLDIERS", 30.0);
			LAi_group_FightGroups("LIGHTHOUSE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

/*
//		Moved to "quests_side.c" by Grey Roger
		case "raoul_calmes_fight":
			LAi_SetActorType(CharacterFromID("raoul calmes"));
			LAi_ActorAttack(CharacterFromID("raoul calmes"), PChar, "");
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "letters_1";
		break;
*/

		case "rabel_yverneau_exit_run":
			LAi_QuestDelay("rabel_yverneau_exit_run_1", 1.2);
		break;

		case "rabel_yverneau_exit_run_1":
			LAi_SetImmortal(CharacterFromID("counterspy"), true);
			LAi_SetImmortal(CharacterFromID("rabel Iverneau"), true);

			AddPassenger(PChar, CharacterFromID("Rabel Iverneau"), 0);
			AddPassenger(PChar, CharacterFromID("Counterspy"), 0);

			Characters[getCharacterIndex("Ox_Soldier_1")].dialog.Filename = "Story_French Occupant_dialog.c"; // KK
			Characters[getCharacterIndex("Ox_Soldier_2")].dialog.Filename = "Story_French Occupant_dialog.c"; // KK

			LAi_type_actor_Reset(CharacterFromID("Rabel Iverneau"));
			LAi_type_actor_Reset(CharacterFromID("counterspy"));

			LAi_ActorRunToLocation(CharacterFromID("counterspy"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);
			LAi_ActorRunToLocation(CharacterFromID("Rabel Iverneau"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);

			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_1"), "FRANCE_SOLDIERS"); // KK
			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_2"), "FRANCE_SOLDIERS"); // KK

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

			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_1"), "FRANCE_SOLDIERS"); // KK
			LAi_group_MoveCharacter(CharacterFromID("Ox_Soldier_2"), "FRANCE_SOLDIERS"); // KK

			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "blaze_exit_to_beltrop":
			DoQuestReloadToLocation("Smugglers_residence", "reload", "reload1", "blaze_first_speak_with_beltrop_complete");
		break;

		case "quest_pirate_01_exit_go_one":
			AddQuestRecord("blaze_to_incas_collection", 2);
			PChar.quest.main_line = "blaze_to_incas_collection_begin_5";
			PChar.quest.go_to_pirate_fort_fight.win_condition.l1 = "location";
			PChar.quest.go_to_pirate_fort_fight.win_condition.l1.location = "Douwesen_jungle_03";
			PChar.quest.go_to_pirate_fort_fight.win_condition = "go_to_pirate_fort_fight_complete";
		break;

		case "quest_pirate_01_exit_with_fight":
			LAi_ActorAttack(CharacterFromID("quest_pirate_01"), PChar, "");
			AddQuestRecord("blaze_to_incas_collection", 4);
		break;

		case "quest_pirate_01_exit_from_fort":
			LAi_ActorGoToLocator(CharacterFromID("quest_pirate_01"), "reload", "reload1", "pirate_go_to_jungle_complete", 120.0);
		break;

		case "Pieter_nolt_fight":
			LAi_group_FightGroups("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, true);
			PChar.quest.pirates_becomes_neutral.win_condition.l1 = "location";
			PChar.quest.pirates_becomes_neutral.win_condition.l1.location = "Douwesen";
			PChar.quest.pirates_becomes_neutral.win_condition = "pirates_becomes_neutral";
		break;

		case "pirates_becomes_neutral":
			LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		break;

		case "miner_again_kick_exit":
			LAi_SetStayType(CharacterFromID("leborio drago"));
			LAi_setActorType(CharacterFromID("Mine_soldier_01"));
			LAi_ActorDialog(CharacterFromID("Mine_soldier_01"), PChar, "", 3.0, 5);
		break;

		case "mine_soldier_resque_exit":
			PChar.quest.main_line = "resque_from_mine_step_one";
			LAi_SetActorType(CharacterFromID("Mine_soldier_01"));
			LAi_ActorGoToLocator(CharacterFromID("Mine_soldier_01"), "reload", "reload1", "soldier_goto_to_mine_commander", 45.0);
			PChar.quest.main_line = "soldier_to_mine_commander_resque";
		break;

		case "mine_commander_resque_exit":
			LAi_ActorGoToLocator(CharacterFromID("Mine_commander"), "reload", "reload1", "commendant_exit_from_mines_complete", 45.0);
			PChar.quest.main_line = "talk_with_Liborio";
		break;

		case "mine_commander_resque_denied_exit":
			LAi_ActorGoToLocator(CharacterFromID("Mine_commander"), "reload", "reload1", "commendant_exit_2_from_mines_complete", 45.0);

			PChar.quest.main_line = "resque_from_mines_denied";
			AddQuestRecord("search_danielle", 14);
		break;

		case "lucient_bescanceny_fight":
			LAi_setActorType(CharacterFromID("lucien bescanceny"));
			LAi_ActorAttack(CharacterFromID("lucien bescanceny"), PChar, "");
			Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro = "5";// NK thanks to Taghmon
			AddQuestRecord("Patric", 5); // NK
		break;

		case "leborio_drago_passenger_exit":
			AddPassenger(PChar, CharacterFromID("leborio drago"), -1);
			LAi_SetOfficerType(CharacterFromID("leborio drago"));

			PChar.quest.hired_leborio.win_condition.l1 = "location";
			PChar.quest.hired_leborio.win_condition.l1.location = "Oxbay";
			PChar.quest.hired_leborio.win_condition = "hired_leborio_complete";
		break;

		case "leborio_drago_fight_exit":
			LAi_ActorAttack(CharacterFromID("leborio drago"), PChar, "");
		break;

		case "leaving_oxbay_exit_no_run":
			Characters[getCharacterIndex("Ox_Soldier_1")].dialog.Filename = "Story_French Occupant_dialog.c"; // KK
			Characters[getCharacterIndex("Ox_Soldier_2")].dialog.Filename = "Story_French Occupant_dialog.c"; // KK

			LAi_type_actor_Reset(CharacterFromID("Counterspy"));
			LAi_type_actor_Reset(CharacterFromID("Rabel Iverneau"));
			LAi_ActorRunToLocation(CharacterFromID("Counterspy"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);
			LAi_ActorRunToLocation(CharacterFromID("Rabel Iverneau"), "reload", "reload2_back", "none", "", "", "Story_Follow_Rabel_And_Counterspy", 30.0);

			AddPassenger(PChar, CharacterFromID("Rabel Iverneau"), 0);
			AddPassenger(PChar, CharacterFromID("Counterspy"), 0);
			LAi_QuestDelay("Story_CapturedByHotPursuit", 6.0);
		break;

		case "greenford_citizen_01_researcher_good_exit":
			AddQuestRecord("resque_researcher", 1);
			PChar.quest.main_line = "resque_researcher_good";
			LAi_ActorGoToLocator(CharacterFromID("greenford_citizen_01"), "reload", "reload1", "", 90.0);
		break;

		case "greenford_citizen_01_researcher_bad_exit":
			PChar.quest.prepare_fighting_on_deck_complete.over = "yes";
			AddQuestRecord("resque_researcher", 2);
			PChar.quest.main_line = "resque_researcher_bad";
			LAi_SetActorType(CharacterFromID("murderer_in_greenford_04"));
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, CharacterFromID("murderer_in_greenford_04"), "", 3.0);
			LAi_ActorFollow(CharacterFromID("murderer_in_greenford_04"), PChar, "greenford_citizen_01_researcher_bad_exit_2", 3.0);
		break;

		case "greenford_citizen_01_researcher_bad_exit_2":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, CharacterFromID("murderer_in_greenford_04"));
			LAi_ActorDialog(CharacterFromID("murderer_in_greenford_04"), PChar, "", 1.0, 1.0);
			LAi_ActorGoToLocator(CharacterFromID("greenford_citizen_01"), "reload", "reload1", "", 9.0);
			OfficersReaction("bad");
		break;

		case "Greenford_commander_fight_exit":
			LAi_LocationFantomsGen(&locations[FindLocation("Greenford_prison")], false);
			LAi_NoRebirthEnable(CharacterFromID("Greenford Prison Commendant"));
			LAi_NoRebirthEnable(CharacterFromID("Eng_soldier_38"));
			LAi_NoRebirthEnable(CharacterFromID("Eng_soldier_39"));

			iForceDetectionFalseFlag = 1; // KK

			characters[getCharacterIndex("Greenford Commander")].skill.accuracy = "2";
			characters[getCharacterIndex("Greenford Commander")].skill.cannons = "3";
			LAi_SetImmortal(CharacterFromID("Greenford Commander"), true);
			LAi_LocationFightDisable(&Locations[FindLocation("Greenford_prison")], false);
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Oxbay", false);
			PChar.quest.main_line = "return_idol_from_greenford_1";

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

			PChar.quest.escape_from_greenford.win_condition.l1 = "location";
			PChar.quest.escape_from_greenford.win_condition.l1.location = "Oxbay";
			PChar.quest.escape_from_greenford.win_condition = "escape_from_greenford";

			PChar.quest.prepare_escape_from_greenford.win_condition.l1 = "ExitFromLocation";
			PChar.quest.prepare_escape_from_greenford.win_condition.l1.location = "Greenford_prison";
			PChar.quest.prepare_escape_from_greenford.win_condition = "prepare_escape_from_greenford";

			PChar.quest.return_idol_from_frigate.win_condition.l1 = "Character_Capture";
			PChar.quest.return_idol_from_frigate.win_condition.l1.character = "Eng Captain Idol";
			PChar.quest.return_idol_from_frigate.win_condition.l2 = "SeaEnter"; // to allow boarding PW
			PChar.quest.return_idol_from_frigate.win_condition = "return_idol_from_frigate_complete";
			PChar.quest.return_idol_from_frigate1.win_condition.l1 = "NPC_Death";
			PChar.quest.return_idol_from_frigate1.win_condition.l1.character = "Eng Captain Idol";
			PChar.quest.return_idol_from_frigate1.win_condition.l2 = "SeaEnter"; //to allow boarding PW
			PChar.quest.return_idol_from_frigate1.win_condition = "return_idol_from_frigate_complete";
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
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], false);
			LAi_ActorAttack(CharacterFromID("Gervasio Serrao"), PChar, "");
			PChar.quest.killing_gervasio.win_condition.l1 = "NPC_Death";
			PChar.quest.killing_gervasio.win_condition.l1.character = "Gervasio Serrao";
			PChar.quest.killing_gervasio.win_condition = "killing_gervasio";
		break;

		case "killing_gervasio":
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], true);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_FRIEND);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, "DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_FRIEND);
		break;

		case "french_patrol_fight_exit":
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		break;

		case "found_blaze_exit_1":
			Characters[makeint(PChar.Temp.Officer.idx2)].Dialog.CurrentNode = "Miracle";
			LAi_type_actor_Reset(&Characters[makeint(PChar.Temp.Officer.idx2)]);
			LAi_ActorDialog(&Characters[makeint(PChar.Temp.Officer.idx2)], PChar, "", 3.0, 1.0);
		break;

		case "found_blaze_exit_2":
			Characters[makeint(PChar.Temp.Officer.idx3)].Dialog.CurrentNode = "Miracle_1";
			LAi_type_actor_Reset(&Characters[makeint(PChar.Temp.Officer.idx3)]);
			LAi_ActorDialog(&Characters[makeint(PChar.Temp.Officer.idx3)], PChar, "", 3.0, 1.00);
		break;

		case "found_blaze_exit_3":
			iPassenger = makeint(PChar.Temp.Officer.idx1);
			Characters[iPassenger].Dialog.CurrentNode = "Miracle_2";
			LAi_SetActorType(&Characters[iPassenger]);
			LAi_ActorDialog(&Characters[iPassenger], PChar, "", 3.0, 1.0);
		break;

		case "found_blaze_Exit_in_Tavern_1":
			iPassenger = makeint(PChar.Temp.Officer.idx2);
			Characters[iPassenger].Dialog.CurrentNode = "Talk_in_tavern_1";
			LAi_ActorDialogNow(&Characters[iPassenger], PChar, "", 1.0);
		break;

		case "found_blaze_Exit_in_Tavern_2":
			iPassenger = makeint(PChar.Temp.Officer.idx1);
			Characters[iPassenger].Dialog.CurrentNode = "Talk_in_tavern_2";
			LAi_ActorDialogNow(&Characters[iPassenger], PChar, "", 1.0);
			ChangeCharacterAddressGroup(CharacterFromID("Danielle"), "Muelle_tavern", "Reload", "Reload2");
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorRunToLocator(CharacterFromID("danielle"), "goto", "goto6", "found_blaze_Exit_Danielle", 10.0);
		break;

		case "father_bernard_church_help_bad_2":
			AddDialogExitQuest("father_bernard_church_help_bad_2");
			characters[getCharacterIndex("father bernard")].quest.church_help = "done";
			AddQuestRecord("church_help", 14);
			CloseQuestHeader("church_help");
			AddMoneyToCharacter(PChar, 2500);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Sneak", 3000); }
			else { AddPartyExp(PChar, 3000); }
			ChangeCharacterAddress(CharacterFromID("Father Jerald"), "none", "none");
			ChangeCharacterAddress(CharacterFromID("Gilbert Ballester"), "Greenford_Church", "goto11");
			LAi_SetStayType(CharacterFromID("Gilbert Ballester"));
			TakeItemFromCharacter(PChar, "pornushka");
		break;

		case "ewan_glover_Exit_to_port_of_Redmond":
			LAi_ActorRunToLocator(CharacterFromID("Ewan Glover"), "reload", "reload_from_port", "", 45.0);
		break;

		case "edgar_attwood_exit_from_blaze":
			PChar.quest.main_line = "inside_redmond_prison";
			LAi_ActorGoToLocator(CharacterFromID("Edgar Attwood"), "goto", "goto13", "wait_for_night_in_prison_complete", 30.0);
		break;

		case "anacleto_rui_sa_pinto_bad_swimming_in_oxbay_good_2":
			AddQuestrecord("Where_are_i", 9);
			LAi_SetImmortal(CharacterFromID("Anacleto Rui Sa Pinto"), false);
			LAi_SetActorType(CharacterFromID("anacleto rui sa pinto"));
			LAi_ActorAttack(CharacterFromID("anacleto rui sa pinto"), PChar, "");
			PChar.quest.kill_anacleto.win_condition.l1 = "NPC_death";
			PChar.quest.kill_anacleto.win_condition.l1.character = "anacleto rui sa pinto";
			PChar.quest.kill_anacleto.win_condition = "kill_anacleto_complete_2";
		break;

		case "anacleto_rui_sa_pinto_fight_exit":
			LAi_SetImmortal(CharacterFromID("Anacleto Rui Sa Pinto"), false);
			CloseQuestHeader("Where_are_i");
			LAi_Fade("anacleto_rui_sa_pinto_fight_exit_2", "anacleto_rui_sa_pinto_fight_exit_3");
		break;

		case "anacleto_rui_sa_pinto_fight_exit_2":
			LAi_SetImmortal(CharacterFromID("Anacleto Rui Sa Pinto"), false);
			LAi_LocationFightDisable(&locations[Findlocation("pirate_tavern")], false);
			ChangeCharacterAddress(CharacterFromID("anacleto rui sa pinto"), "Pirate_tavern", "goto6");
		break;

		case "anacleto_rui_sa_pinto_fight_exit_3":
			LAi_SetImmortal(CharacterFromID("Anacleto Rui Sa Pinto"), false);
			LAi_SetActorType(CharacterFromID("anacleto rui sa pinto"));
			LAi_ActorAttack(CharacterFromID("anacleto rui sa pinto"), PChar, "");
			PChar.quest.kill_anacleto.win_condition.l1 = "NPC_death";
			PChar.quest.kill_anacleto.win_condition.l1.character = "anacleto rui sa pinto";
			PChar.quest.kill_anacleto.win_condition = "kill_anacleto_complete";
		break;

		case "anacleto_rui_sa_pinto_luck_exit":
			PChar.quest.main_line = "anacleto_luck_exit";
			ChangeCharacterAddressGroup(CharacterFromID("Wilfred Bythesea"), "Pirate_tavern", "reload", "reload1");
			LAi_SetActorType(CharacterFromID("Wilfred Bythesea"));
			LAi_ActorDialog(CharacterFromID("Wilfred Bythesea"), PChar, "", 5.0, 1.0);
			worldMap.playerShipX = -200.27;
			worldMap.playerShipZ = 2.34;
			worldMap.playerShipAY = 3.0;
			worldMap.playerShipActionRadius = 20.0;
			worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Douwesen.position.rx);
			worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Douwesen.position.rz);
		break;

		case "anacleto_rui_sa_pinto_exit_captain":
			LAi_SetImmortal(CharacterFromID("Anacleto Rui Sa Pinto"), true);
			LAi_Fade("anacleto_rui_sa_pinto_exit_captain_1", "anacleto_rui_sa_pinto_exit_captain_2");
		break;

		case "anacleto_rui_sa_pinto_exit_captain_1":
			ChangeCharacterAddress(CharacterFromID("Gervasio Serrao"), "Pirate_tavern", "goto6");
			characters[GetCharacterIndex("Wilfred Bythesea")].quest.kill_ogarrio = "0";
		break;

		case "anacleto_rui_sa_pinto_exit_captain_2":
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], false);
			LAi_SetActorType(CharacterFromID("Gervasio Serrao"));
			LAi_ActorAttack(CharacterFromID("Gervasio Serrao"), PChar, "");
			LAi_SetCheckMinHP(CharacterFromID("Gervasio Serrao"), 15.0, true, "kill_Serrao_complete");
		break;

		case "danielle_exit_from_tavern_danielle":
			LAi_ActorRunToLocator(CharacterFromID("danielle"), "reload", "reload1", "danielle_escape_from_quest_redmond_tavern_complete", 10.0);
		break;

		case "antoine_lebretton_story_exit":
			LAi_ActorRunToLocator(CharacterFromID("antoine lebretton"), "reload", "reload1", "Story_Lebretton_leaves_upstairs", 10.0);
		break;

		case "amiel_go_away":
			LAi_SetActorType(CharacterFromID("Amiel Berangere"));
			LAi_ActorGoToLocation(CharacterFromID("Amiel Berangere"), "reload", "reload1", "none", "", "", "", 10.0);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 1500); }
			else { AddPartyExp(PChar, 1500); }
		break;

		case "danielle_sailor_statuets_exit":
			LAi_Fade("danielle_sailor_statuets_exit_2", "");
		break;

		case "danielle_sailor_statuets_exit_2":
			ChangeCharacterAddress(CharacterFromID("danielle_sailor"), "none", "none");
			Locations[FindLocation("Douwesen_shore_01")].reload.l1.disable = 0;
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = 0;
		break;

		case "danielle_join_to_us_when_we_are_swimm_to_douwesen_fo_search_rheims":
			PChar.quest.main_line = "blaze_goto_douwesen_with_danielle";
			PChar.quest.to_douwesen_port_search_blaze.win_condition.l1 = "location";
			PChar.quest.to_douwesen_port_search_blaze.win_condition.l1.location = "douwesen_port";
			PChar.quest.to_douwesen_port_search_blaze.win_condition = "to_douwesen_port_search_blaze_complete";

			PChar.quest.to_douwesen_shore_1_search_blaze.win_condition.l1 = "location";
			PChar.quest.to_douwesen_shore_1_search_blaze.win_condition.l1.location = "douwesen_shore_01";
			PChar.quest.to_douwesen_shore_1_search_blaze.win_condition = "to_douwesen_shore_1_search_blaze_complete";

			PChar.quest.to_douwesen_shore_2_search_blaze.win_condition.l1 = "location";
			PChar.quest.to_douwesen_shore_2_search_blaze.win_condition.l1.location = "douwesen_shore_02";
			PChar.quest.to_douwesen_shore_2_search_blaze.win_condition = "to_douwesen_shore_2_search_blaze_complete";
			SetCompanionIndex(PChar, -1, GetCharacterIndex("danielle"));
			SetCharacterRemovable(CharacterFromID("danielle"), false);

			PChar.quest.danielle_death.win_condition.l1 = "npc_death";
			PChar.quest.danielle_death.win_condition.l1.character = "danielle";
			PChar.quest.danielle_death.win_condition = "danielle_death";
		break;

		case "prepare_for_meet_ferro":
			AddQuestrecord("search_danielle", 2);
			PChar.quest.main_line = "search_for_Ferro_Cerezo";

			PChar.quest.kill_ferro_cerezo.win_condition.l1 = "NPC_Death";
			PChar.quest.kill_ferro_cerezo.win_condition.l1.character = "ferro cerezo";
			PChar.quest.kill_ferro_cerezo.win_condition.l2 = "SeaEnter";
			PChar.quest.kill_ferro_cerezo.win_condition = "kill_ferro_cerezo_complete";

			PChar.quest.abording_ferro_cerezo.win_condition.l1 = "Character_Capture";
			PChar.quest.abording_ferro_cerezo.win_condition.l1.character = "ferro cerezo";
			PChar.quest.abording_ferro_cerezo.win_condition = "abording_ferro_cerezo_complete";

			ChangeCharacterAddressGroup(CharacterFromID("ferro cerezo"), "Conceicao_tavern", "sit", "sit5"); // NK: now he is ALWAYS in Conceicao
			LAi_SetImmortal(CharacterFromID("ferro cerezo"), true); // PB: Prevent Exploit
		break;

		case "prepare_ferro_to_Sea":
			PChar.quest.main_line = "killing_ferro_cerezo";
			PChar.quest.to_sea_for_capture_cerezo.win_condition.l1 = "location";
			if (PChar.location == "Muelle_tavern")
			{
				PChar.quest.to_sea_for_capture_cerezo.win_condition.l1.location = "IslaMuelle";
			}
			else
			{
				PChar.quest.to_sea_for_capture_cerezo.win_condition.l1.location = "Conceicao";
			}
			PChar.quest.to_sea_for_capture_cerezo.win_condition = "to_sea_for_capture_cerezo";
			AddQuestRecord("search_danielle", 6);
			// GR: Hostile to player, but neutral to fort -->
			Characters[GetCharacterIndex("ferro cerezo")].nation = PORTUGAL;	// Neutral to fort, so must be same nation
			Characters[GetCharacterIndex("ferro cerezo")].recognized = true;	// Forces hostility to player, regardless of nation relations and flags
			Characters[GetCharacterIndex("ferro cerezo")].skipRM = true;		// Avoids any consequences upon sinking/capturing
			// GR: Hostile to player, but neutral to fort <--
		break;

		case "to_sea_for_capture_cerezo":
			LAi_SetImmortal(CharacterFromID("ferro cerezo"), false); // GR: make him vulnerable again so you can sink him or board and kill him
			LAi_SetStayType(CharacterFromID("Ferro Cerezo"));
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
			PChar.quest.main_line = "after_library";
			PChar.quest.to_oxbay_mine_2.win_condition.l1 = "location";
			PChar.quest.to_oxbay_mine_2.win_condition.l1.location = "Oxbay_canyon";
			PChar.quest.to_oxbay_mine_2.win_condition = "to_oxbay_mine_complete";
			PChar.quest.ferro_to_conceicao.over = "yes";
			if (CheckCharacterItem(PChar, "domingues_fucked"))
			{
				TakeItemFromCharacter(PChar, "domingues_fucked");
			}
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestRecord("search_danielle", 9);
			Preprocessor_Remove("Danielle");
		break;

		case "edgar_go_on_the_port":
			LAi_SetCitizenType(CharacterFromID("Edgar Attwood"));
			LAi_group_MoveCharacter(CharacterFromID("Edgar Attwood"), "ENGLAND_CITIZENS");
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
			PChar.location.from_sea = "Douwesen_shore_01";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar"); // NK 05-04-02 WM/IT set fleet.
			//PChar.ship.type = "Brig1_" + HOLLAND; // PS - SHIP_BRIG_HOLLAND;
			PChar.ship.type = "Brig1";
			PChar.ship.name = "Lucky";
			PChar.ship.stats.nation = HOLLAND;
			SetCrewQuantity(PChar, 160);
			SetBaseShipData(PChar);
			AddCharacterGoods(PChar, GOOD_BALLS, 600);
			AddCharacterGoods(PChar, GOOD_GRAPES, 300);
			AddCharacterGoods(PChar, GOOD_KNIPPELS, 470);
// KK -->
			if(!USE_REAL_CANNONS) AddCharacterGoods(PChar, GOOD_BOMBS, 300);// TIH toggle fix 7-7-06
			// crew need something to eat
			AddCharacterGoods(PChar, GOOD_WHEAT, 60);
			AddCharacterGoods(PChar, GOOD_RUM, 30);
// <-- KK

			//PChar.quest.main_line = "blaze_search_danielle_again";
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
			LAi_SetStayType(CharacterFromID("Wilfred Bythesea"));
		break;

		case "God_hit_us":
			PlayStereoSound("NATURE\thunder3.wav");
			GetCharacterPos(PChar, &locx, &locy, &locz);
			CreateParticleSystemX("blast", locx, locy, locz, locx, locy, locz,0);
			LAi_ApplyCharacterDamage(PChar, 20);
		break;

		case "Ewan_sunk_Boon":
			LAi_SetActorType(CharacterFromID("Amiel Berangere"));
			LAi_ActorGoToLocation(CharacterFromID("Amiel Berangere"), "reload", "reload1", "none", "", "", "", 10.0);

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 4500); }
			else { AddPartyExp(PChar, 4500); }
			SetCharacterShipLocation(CharacterFromID("Virgile boon"), "none");
			AddQuestrecord("Story_1stTaskReceived", 10);

			PChar.quest.Convoy_Virgile_Boon.over = "yes";
			PChar.quest.Convoy_Virgile_Boon2.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_1.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_2.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_3.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_4.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_5.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_6.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_7.over = "yes";
			PChar.quest.Story_Convoy_Virgile_Boon_8.over = "yes";
			PChar.quest.Story_Blaze_and_Boon_leaving.over = "yes";

			bQuestDisableMapEnter = false;
			// TIH --> have it open up the island it locked before or open where the player currently is Oct31'06
			if (CheckAttribute(PChar, "quest.boonelockedisland"))
				{ Island_SetReloadEnableGlobal(PChar.quest.boonelockedisland, true); DeleteAttribute(PChar,"quest.boonelockedisland"); }
			else
				{ Island_SetReloadEnableGlobal(PChar.location, true); }
			//Island_SetReloadEnableGlobal(PChar.location, true);
			// TIH <--

			AddQuestRecord("Story_1stTaskReceived", 12);
			ChangeCharacterAddress(CharacterFromID("Faust Gasquet"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Virgile Boon"), "none", "");
			PChar.quest.Story_1stTaskComplete = "Complete";
			PChar.quest.story_askaboutberangere.over = "yes";
		break;

		case "leborio_hire_denied":
			LAi_Fade("", "");
			ChangeCharacterAddressGroup(CharacterFromID("Leborio Drago"), "Falaise_de_fleur_tavern", "sit", "sit5");
			LAi_SetSitType(CharacterFromID("leborio Drago"));
		break;

// --> CatalinaThePirate Fix for Danielle after final

		case "Story_Take_Clement_Home":
			if(!IsOfficer(CharacterFromID("researcher"))) PlaceCharacter(CharacterFromID("researcher"), "goto");
			if(!IsOfficer(CharacterFromID("danielle"))) PlaceCharacter(CharacterFromID("Danielle"), "goto");
			LAi_SetOfficerType(CharacterFromID("Danielle"));
			Characters[GetCharacterIndex("researcher")].Dialog.CurrentNode = "Home_again";
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Clement_home";
			LAi_SetActorType(CharacterFromID("Researcher"));
			LAi_ActorWaitDialog(PChar, CharacterFromID("Researcher"));
			LAi_ActorDialog(CharacterFromID("Researcher"), PChar, "", 8.0, 1.0);
		break;

		case "Story_Take_Clement_Home3":
			LAi_SetActorType(CharacterFromID("Danielle"));
			LAi_ActorWaitDialog(PChar, CharacterFromID("Danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 8.0, 1.0);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "Clement_home";
			RemoveOfficersIndex(PChar, GetCharacterIndex("Researcher"));
			RemovePassenger(PChar, CharacterFromID("Researcher"));
		break;

		case "Story_Danielle_back_to_officer":
			LAi_SetOfficerType(CharacterFromID("Danielle"));
		break;

		case "Story_AfterFinalOnRedmond2":
// KK -->
			PChar.quest.Story_AfterFinalOnRedmond1.over = "yes";
			PChar.quest.Story_AfterFinalOnRedmond2.over = "yes";
			PChar.quest.Story_AfterFinalOnRedmond3.over = "yes";
// <-- KK
			LAi_SetActorType(CharacterFromID("Danielle"));
//			LAi_ActorWaitDialog(PChar, CharacterFromID("Danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 5.0, 1.0);
			Characters[GetCharacterIndex("Danielle")].Dialog.CurrentNode = "After_Final2";
		break;

		case "Story_Reward_For_Silehard":
			Locations[FindLocation("Redmond_town_01")].vcskip = true;
			PChar.quest.Story_Reward_for_Silehard2.win_condition.l1 = "location";
			PChar.quest.Story_Reward_for_Silehard2.win_condition.l1.location = "Redmond_town_01";
			PChar.quest.Story_Reward_for_Silehard2.win_condition = "Story_Reward_for_Silehard2";

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

			LAi_SetActorType(CharacterFromID("Danielle"));
			LAi_ActorWaitDialog(PChar, CharacterFromID("Danielle"));
			LAi_ActorDialog(CharacterFromID("Danielle"), PChar, "", 8.0, 1.0);

			DeleteAttribute(&Locations[FindLocation("Redmond_town_01")],"vcskip");
		//	Locations[FindLocation("Redmond_town_01")].vcskip = false;
		break;

		case "Story_Danielle_Departs_Exit":
			RemoveOfficersIndex(PChar, GetCharacterIndex("Danielle"));
			RemovePassenger(PChar, CharacterFromID("Danielle"));
			LAi_ActorGoToLocation(CharacterFromID("Danielle"), "Redmond_town_01", "goto", "goto16", "", "", "", 25.0);
			LAi_QuestDelay("Story_Danielle_Departs_Exit2", 25.0);
		break;

		case "Story_Danielle_Departs_Exit2":
			ChangeCharacterAddress(CharacterFromID("Danielle"), "", "");
			characters[GetCharacterIndex("John Clifford Brin")].dialog = "John Clifford Brin.c"; // PB
		break;

		case "Story_Danielle_Departs_Exit3":
			RemoveOfficersIndex(PChar, GetCharacterIndex("Danielle"));
			RemovePassenger(PChar, CharacterFromID("Danielle"));
			LAi_QuestDelay("Story_Danielle_Departs_Exit2", 25.0);
		break;

// <-- CatalinaThePirate Fix for Danielle after final

// "Night Craft" quest -->
		case "smuggler_line_begin":
			Locations[FindLocation("Redmond_Town_01")].reload.l5.disable = 1;
			DisableFastTravel(true);
			LAi_SetFightMode(PChar, false);
			PChar.quest.smuggler_line = "begin";
			PlaceCharacter(CharacterFromID("quest_smuggler_02"), "goto");
			LAi_SetActorType(CharacterFromID("quest_smuggler_02"));
			Lai_ActorDialog(CharacterFromID("quest_smuggler_02"), PChar, "", 3.0, 1.0);
		break;

		case "smuggler_line_begin_exit":	// Triggered by dialog with "quest_smuggler_02"
			Locations[FindLocation("Redmond_Town_01")].reload.l5.disable = 0;
			DisableFastTravel(false);
			homelocator = LAi_FindFarLocator("reload", locx, locy, locz);
			LAi_ActorRunToLocation(CharacterFromID("quest_smuggler_02"), "reload", homelocator, "none", "", "", "", 10.0);
			SetQuestHeader("smuggler_line");
			AddQuestRecord("smuggler_line", 1);
			characters[GetCharacterIndex("Desmond Ray Beltrop")].dialog.currentnode = "smuggler_line";
			PChar.quest.smuggler_line = "to_beltrop";
		break;

		case "smuggler_line_not_begin_exit":	// Triggered by dialog with "quest_smuggler_02"
			Locations[FindLocation("Redmond_Town_01")].reload.l5.disable = 0;
			DisableFastTravel(false);
			homelocator = LAi_FindFarLocator("reload", locx, locy, locz);
			LAi_ActorRunToLocation(CharacterFromID("quest_smuggler_02"), "reload", homelocator, "none", "", "", "", 10.0);
			characters[GetCharacterIndex("Desmond Ray Beltrop")].dialog.currentnode = "smuggler_line";
			PChar.quest.smuggler_line = "refused";
		break;

		case "smuggler_line_decline":		// Triggered by dialog with "Desmond Ray Beltrop"
			PChar.quest.smuggler_line = "wait_for_change_mind";
			if (!CheckAttribute(PChar, "QuestInfo.smuggler_line")) SetQuestHeader("smuggler_line");
			AddQuestRecord("smuggler_line", 2);
		break;

		case "smuggler_line_first_mission_free_space_off":
			PChar.quest.smuggler_line = "first_mission_free_space_off";
			if (!CheckAttribute(PChar, "QuestInfo.smuggler_line")) SetQuestHeader("smuggler_line");
			AddQuestRecord("smuggler_line", 3);
			
			PChar.quest.smuggler_line_first_mission_free_space_off_expired.win_condition.l1 = "Timer";
			PChar.quest.smuggler_line_first_mission_free_space_off_expired.win_condition.l1.date.day = GetAddingDataDay(0, 0, 15);
   			PChar.quest.smuggler_line_first_mission_free_space_off_expired.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 15);
			PChar.quest.smuggler_line_first_mission_free_space_off_expired.win_condition.l1.date.year = GetAddingDataYear(0, 0, 15);
			PChar.quest.smuggler_line_first_mission_free_space_off_expired.win_condition = "smuggler_line_first_mission_free_space_off_expired";
		break;

		case "smuggler_line_first_mission_free_space_off_expired":
			PChar.quest.smuggler_line = "first_mission_free_space_off_expired";
		break;

		case "smuggler_line_first_mission_accept":
			PChar.quest.smuggler_line = "smuggler_line_first_mission_accept";
			if (!CheckAttribute(PChar, "QuestInfo.smuggler_line")) SetQuestHeader("smuggler_line");
			AddQuestRecord("smuggler_line", 4);
			AddCharacterGoods(PChar, GOOD_SANDAL, 300);
			PChar.quest.smuggler_line_first_mission_free_space_off_expired.over = "yes";
			NPChar = characterfromID("Jean Maginot");	// was Arnaud Matton but then this quest conflicts with existing "Sabine Matton" quest
			StoreDialog(NPChar);
			NPChar.Dialog.Filename = "France Trader_dialog.c";
			if (NPChar.quest.meeting == "0") NPChar.dialog.CurrentNode = "First time";
			else NPChar.dialog.CurrentNode = "second time";
			Islands[FindIsland("SaintMartin")].Trade.Contraband.id1 = GOOD_SANDAL;	// Saint Martin normally obeys Dutch smuggling in which sandal is not contraband
		break;

		case "smuggler_line_first_mission_wait_night":	// Triggered by dialog with Jean Maginot
			WaitDate("", 0,0,1,0,0);
			PChar.quest.smuggler_line = "smuggler_line_first_mission_before_soldiers";
			RemoveCharacterGoods(PChar,GOOD_SANDAL, 300);
			LAi_Fade("", "smuggler_line_first_mission_before_soldiers");
			AddQuestRecord("smuggler_line", 5);
		break;

		case "smuggler_line_first_mission_wait_night_short_cargo":
			WaitDate("", 0,0,1,0,0);
			PChar.quest.smuggler_line = "smuggler_line_first_mission_get_more_sandal";
			LAi_Fade("", "smuggler_line_first_mission_short_cargo");
		break;

		case "smuggler_line_first_mission_short_cargo":
			Characters[getCharacterIndex("Jean Maginot")].dialog.currentnode = "smuggler_line_first_mission_short_cargo";
			LAi_SetActorType(CharacterFromID("Jean Maginot"));
			LAi_ActorDialogNow(CharacterFromID("Jean Maginot"), PChar, "smuggler_line_reset_maginot", -1);
		break;

		case "smuggler_line_reset_maginot":
			LAi_SetMerchantType(CharacterFromID("Jean Maginot"));
		break;

		case "smuggler_line_first_mission_before_soldiers":
			Characters[getCharacterIndex("Jean Maginot")].dialog.currentnode = "smuggler_line_first_mission_before_soldiers";
			LAi_SetActorType(CharacterFromID("Jean Maginot"));
			LAi_ActorDialogNow(CharacterFromID("Jean Maginot"), PChar, "", -1);
		break;

		case "smuggler_line_first_mission_soldiers":
			PChar.quest.smuggler_line = "smuggler_line_first_mission_meet_soldiers";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "reload", "locator2");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "smuggler_line_soldier_01";
			LAi_setActorType(sld);
			LAi_ActorFollow(sld, PChar, "", 2.0);
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "reload", "locator2");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "smuggler_line_soldier_02";
			LAi_setActorType(sld);
			LAi_ActorFollow(sld, PChar, "", 2.0);
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m0, "reload", "locator2");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "smuggler_line_soldier_03";
			sld.dialog.filename = "quest_soldier_dialog.c";
			LAi_setActorType(sld);
			LAi_ActorFollow(sld, PChar, "smuggler_line_first_mission_speak_with_soldiers", 2.0);
		break;

		case "smuggler_line_first_mission_speak_with_soldiers":
			LAi_ActorDialog(CharacterFromID("smuggler_line_soldier_03"), PChar, "", 3.0, 1.0);
		break;

		case "smuggler_line_first_mission_jean_first_talk_with_soldiers":
			PChar.quest.smuggler_line = "smuggler_line_first_mission_jean_first_talk_with_soldiers";
			characters[GetCharacterIndex("Jean Maginot")].dialog.currentnode = "smuggler_line_first_mission_jean_first_talk_with_soldiers";
			LAi_ActorDialogNow(CharacterFromID("Jean Maginot"), PChar, "", -1.0);
		break;

		case "smuggler_line_first_mission_jean_first_talk_with_soldiers2":
			sld = CharacterFromID("smuggler_line_soldier_03");
			LAi_setActorType(sld);
			LAi_type_actor_Reset(sld);
			sld.dialog.currentnode = "first_mission_arrest_jean";
			LAi_ActorDialog(sld, PChar, "", 3.0, 1.0);
		break;

		case "smuggler_line_first_mission_soldiers_arrest_jean":
			PChar.quest.smuggler_line = "smuggler_line_first_mission_soldiers_arrest_maginot";
			LAi_setActorType(CharacterFromID("smuggler_line_soldier_03"));
			LAi_type_actor_Reset(CharacterFromID("smuggler_line_soldier_01"));
			LAi_type_actor_Reset(CharacterFromID("smuggler_line_soldier_02"));
			LAi_type_actor_Reset(CharacterFromID("smuggler_line_soldier_03"));
			
			LAi_ActorFollow(CharacterFromID("smuggler_line_soldier_01"), CharacterFromID("Jean Maginot"), "", 15.0);
			LAi_ActorFollow(CharacterFromID("smuggler_line_soldier_02"), CharacterFromID("Jean Maginot"), "", 15.0);
			LAi_ActorFollow(CharacterFromID("smuggler_line_soldier_03"), CharacterFromID("Jean Maginot"), "", 15.0);
			
			PChar.quest.smuggler_line_first_mission_soldiers_arrest_maginot_exit.win_condition.l1 = "Location";
			PChar.quest.smuggler_line_first_mission_soldiers_arrest_maginot_exit.win_condition.l1.location = "Marigot_port";
			PChar.quest.smuggler_line_first_mission_soldiers_arrest_maginot_exit.win_condition = "smuggler_line_first_mission_soldiers_arrest_maginot_exit";
		break;

		case "smuggler_line_first_mission_soldiers_arrest_maginot_exit":			
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 1;
			LAi_ActorSelfDialog(PChar, "");
			AddQuestRecord("smuggler_line", 6);
			
			PChar.quest.smuggler_line_first_mission_wait_for_maginot.win_condition.l1 = "Timer";
			PChar.quest.smuggler_line_first_mission_wait_for_maginot.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
   			PChar.quest.smuggler_line_first_mission_wait_for_maginot.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.smuggler_line_first_mission_wait_for_maginot.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.smuggler_line_first_mission_wait_for_maginot.win_condition = "smuggler_line_first_mission_wait_for_maginot";
			
			PChar.quest.smuggler_line_first_mission_wait_for_maginot_decline.win_condition.l1 = "Location";
			PChar.quest.smuggler_line_first_mission_wait_for_maginot_decline.win_condition.l1.location = "SaintMartin";
			PChar.quest.smuggler_line_first_mission_wait_for_maginot_decline.win_condition = "smuggler_line_first_mission_wait_for_maginot_decline";
		break;

		case "smuggler_line_first_mission_wait_for_maginot":
			AddQuestRecord("smuggler_line", 7);
		break;

		case "smuggler_line_first_mission_wait_for_maginot_decline":
			PChar.quest.smuggler_line_first_mission_wait_for_maginot.over = "yes";
		break;

		case "smuggler_line_first_mission_award":
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(PChar, "Leadership", 2500);
			else AddPartyExp(PChar, 2500);
			AddMoneyToCharacter(PChar, 750*makeint(PChar.skill.commerce));
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 0;
		//	RestoreDialog(CharacterFromID("Jean Maginot"));
			LAi_SetMerchantType(CharacterFromID("Jean Maginot"));
			PChar.quest.smuggler_line.first_mission = "completed";
		break;

		case "smuggler_line_second_mission_accept":
			PChar.quest.smuggler_line = "second_mission_accept";
			AddQuestRecord("smuggler_line", 8);
			NPChar = characterfromID("Jean Maginot");
			StoreDialog(NPChar);
			NPChar.Dialog.Filename = "France Trader_dialog.c";
			NPChar.dialog.CurrentNode = "second time";
		break;

		case "second_mission_money_prepare_for_troubles":
			GiveItem2Character(PChar, "Jean_ring");
			PChar.quest.smuggler_line = "second_mission_money_prepare_for_troubles";
			AddQuestRecord("smuggler_line", 9);
			AddMoneyToCharacter(PChar, 10000);
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(PChar, "Sneak", 2000);
			else AddPartyExp(PChar, 2000);
			DisableFastTravel(true);
			Locations[FindLocation("Marigot_port")].vcskip = true;
			LAi_LocationFightDisable(&Locations[FindLocation("Marigot_port")], true);
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 1;
			Locations[FindLocation("Marigot_port")].locators_radius.goto.goto5 = 4;
			Locations[FindLocation("Marigot_port")].locators_radius.goto.goto4 = 9.5;
			
			PChar.quest.second_mission_money_prepare_for_troubles_port.win_condition.l1 = "Location";
			PChar.quest.second_mission_money_prepare_for_troubles_port.win_condition.l1.location = "Marigot_port";
			PChar.quest.second_mission_money_prepare_for_troubles_port.win_condition = "second_mission_money_troubles";

			PChar.quest.second_mission_money_reset_marigot.win_condition.l1 = "Location";
			PChar.quest.second_mission_money_reset_marigot.win_condition.l1.location = PChar.location.from_sea;
			PChar.quest.second_mission_money_reset_marigot.win_condition = "second_mission_reset_marigot";
		break;

		case "second_mission_money_troubles":
			DeleteAttribute(&Locations[FindLocation("Marigot_port")],"vcskip");
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			homelocator = LAi_FindNearestFreeLocator("goto", locx, locy, locz);
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m0, "goto", homelocator);
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "smuggler_line_soldier_03";
			sld.dialog.filename = "quest_soldier_dialog.c";
			LAi_setActorType(sld);
			
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			homelocator = LAi_FindNearestFreeLocator("goto", locx, locy, locz);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "goto", homelocator);
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "smuggler_line_soldier_01";
			LAi_setActorType(sld);
			
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			homelocator = LAi_FindNearestFreeLocator("goto", locx, locy, locz);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "goto", homelocator);
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "smuggler_line_soldier_02";
			LAi_setActorType(sld);

			PChar.quest.second_mission_money_troubles2.win_condition.l1 = "Locator";
			PChar.quest.second_mission_money_troubles2.win_condition.l1.location = "Marigot_port";
			PChar.quest.second_mission_money_troubles2.win_condition.l1.locator_group = "goto";
			PChar.quest.second_mission_money_troubles2.win_condition.l1.locator = "goto5";					// Locator near foot of stairs from store
			PChar.quest.second_mission_money_troubles2.win_condition = "second_mission_money_troubles2";

			PChar.quest.second_mission_money_troubles2a.win_condition.l1 = "Locator";
			PChar.quest.second_mission_money_troubles2a.win_condition.l1.location = "Marigot_port";
			PChar.quest.second_mission_money_troubles2a.win_condition.l1.locator_group = "goto";
			PChar.quest.second_mission_money_troubles2a.win_condition.l1.locator = "goto4";					// Locator to the side in case player sidesteps off stairs
			PChar.quest.second_mission_money_troubles2a.win_condition = "second_mission_money_troubles2";
		break;

		case "second_mission_money_troubles2":
			LAi_LocationFightDisable(&Locations[FindLocation("Marigot_port")], false);
			PChar.quest.second_mission_money_troubles2.over ="yes";
			PChar.quest.second_mission_money_troubles2a.over = "yes";
			LAi_ActorDialog(CharacterFromID("smuggler_line_soldier_03"), PChar, "", 3.0, 1.0);
			LAi_ActorFollow(CharacterFromID("smuggler_line_soldier_01"), PChar, "", 2.0);
			LAi_ActorFollow(CharacterFromID("smuggler_line_soldier_02"), PChar, "", 2.0);
		break;

		case "second_mission_money_troubles_fight":
			LAi_LocationFightDisable(&Locations[FindLocation("Marigot_port")], false);
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);		
			LAi_SetWarriorType(CharacterFromID("smuggler_line_soldier_01"));
			LAi_SetWarriorType(CharacterFromID("smuggler_line_soldier_02"));
			LAi_SetWarriorType(CharacterFromID("smuggler_line_soldier_03"));	
			LAi_group_MoveCharacter(CharacterFromID("smuggler_line_soldier_01"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("smuggler_line_soldier_02"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("smuggler_line_soldier_03"), "FRANCE_SOLDIERS");
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);	
			AddQuestRecord("smuggler_line", 10);	
			AddQuestRecord("smuggler_line", 11);		
			PChar.quest.smuggler_line = "second_mission_to_beltrop_with_money_and_with_ring";
		break;

		case "second_mission_money_to_france_governor":
			AddQuestRecord("smuggler_line", 10);
			AddQuestRecord("smuggler_line", 12);
			DoQuestReloadToLocation("Marigot_mansion_hall", "reload", "reload1", "second_mission_speak_with_france_governor");
			RemoveCharacterEquip(PChar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(PChar, GUN_ITEM_TYPE);
			EnableEquip(PChar, BLADE_ITEM_TYPE, false);
			EnableEquip(PChar, GUN_ITEM_TYPE, false);
			StorePassengers("Blaze");
		break;

		case "second_mission_speak_with_france_governor":
			TakeItemFromCharacter(PChar, "Jean_ring");
			LAi_SetActorType(CharacterFromID("Philippe de Rivarol"));
			LAi_SetActorType(PChar);
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "goto", "goto4");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "smuggler_line_soldier_01";
			LAi_setActorType(sld);
			LAi_ActorFollow(sld, PChar, "", 2.0);
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "goto", "goto6");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "smuggler_line_soldier_02";
			LAi_setActorType(sld);
			LAi_ActorFollow(sld, PChar, "", 2.0);
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m0, "goto", "goto9");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			sld.id = "smuggler_line_soldier_03";
			sld.dialog.filename = "quest_soldier_dialog.c";
			LAi_setActorType(sld);
			LAi_ActorDialog(sld, PChar, "", 3.0, 1.0);
			
			characters[getCharacterIndex("Philippe de Rivarol")].dialog.currentnode = "smuggler_line";
			LAi_ActorWaitDialog(PChar, CharacterFromID("Philippe de Rivarol"));
			LAi_ActorDialog(CharacterFromID("Philippe de Rivarol"), PChar, "", 5.0, 5.0);
		break;

		case "second_mission_money_delivered_to_beltrop":
			AddMoneyToCharacter(PChar, -7000);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 2000);
				AddPartyExpChar(PChar, "Sneak", 2000);
			}
			else AddPartyExp(PChar, 4000);
			AddQuestRecord("smuggler_line", 16);
			PChar.quest.smuggler_line.second_mission = "completed";
			RestoreDialog(CharacterFromID("Jean Maginot"));
			LAi_SetMerchantType(CharacterFromID("Jean Maginot"));
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 0;
		break;

		case "second_mission_to_prison":
			characters[getCharacterIndex("Philippe de Rivarol")].dialog.currentnode = "second time";
			LAi_SetHuberStayType(CharacterFromID("Philippe de Rivarol"));
			SetTownCapturedState("Marigot", true);
			StorePassengers("Blaze");
			Locations[FindLocation("Marigot_prison")].vcskip = true;
			WaitDate("", 0, 0, 3, rand(11), rand(59));
			DoQuestReloadToLocation("Marigot_prison", "goto", "goto9", "second_mission_prison_wait_for_resque");
		break;

		case "second_mission_prison_wait_for_resque":
			PChar.dialog.currentnode = "smuggler_line_second_mission_prison_wait_for_resque";
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "second_mission_prison_prepare_for_resque":
			PChar.quest.smuggler_line = "in_Marigot_prison";
			AddQuestRecord("smuggler_line", 13);
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(CharacterFromID("danielle"), "Marigot_prison", "merchant", "reload13");
			LAi_SetActorType(CharacterFromID("danielle"));
			LAi_ActorRunToLocator(CharacterFromID("danielle"), "goto", "goto23", "second_mission_danielle_speak_with_blaze_in_prison", -1);
		break;

		case "second_mission_danielle_speak_with_blaze_in_prison":
			characters[getCharacterIndex("danielle")].dialog.smgnode = characters[getCharacterIndex("danielle")].dialog.currentnode;
			characters[getCharacterIndex("danielle")].dialog.currentnode = "smuggler_line";
			LAi_ActorDialogNow(CharacterFromID("danielle"), PChar, "", -1);
		break;

		case "second_mission_exit_from_cam":
			LAi_fade("second_mission_exit_from_cam_completed", "")
		break;

		case "second_mission_exit_from_cam_completed":
			EnableEquip(PChar, BLADE_ITEM_TYPE, true);
			EnableEquip(PChar, GUN_ITEM_TYPE, true);
			EquiPCharacterByItem(PChar, FindCharacterItemByGroup(PChar, BLADE_ITEM_TYPE));
			EquiPCharacterByItem(PChar, FindCharacterItemByGroup(PChar, GUN_ITEM_TYPE));
			ChangeCharacterAddress(PChar, "Marigot_prison", "goto12");
			PChar.quest.smuggler_line = "second_mission_exit_from_prison";
			ChangeCharacterAddress(CharacterFromID("danielle"), "Marigot_prison", "goto23");
			if (CheckQuestAttribute("danielle_on_ship", "true"))
			{
				characters[getCharacterIndex("danielle")].dialog.currentnode = characters[getCharacterIndex("danielle")].dialog.smgnode;
				DeleteAttribute(CharacterFromID("danielle"), "dialog.smgnode");
				RestorePassengers("Blaze");
				LAi_SetOfficerType(CharacterFromID("danielle"));
				PChar.quest.smuggler_line = "second_mission_return_to_beltrop_after_prison";
				Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
				Preprocessor_AddQuestData("her", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
				AddQuestRecord("smuggler_line", 14);
				Preprocessor_Remove("she");
				Preprocessor_Remove("Danielle");
			}
			else
			{
				characters[getCharacterIndex("danielle")].dialog.currentnode = "smuggler_line";
				LAi_ActorDialog(CharacterFromID("danielle"), PChar, "", 1.0, 1.0);
			}
			reStorePassengers("Blaze");
			DisableFastTravel(false);
			PChar.quest.smuggler_line_second_mission_uncapture_Marigot.win_condition.l1 = "Timer";
			PChar.quest.smuggler_line_second_mission_uncapture_Marigot.win_condition.l1.date.day = GetAddingDataDay(0, 0, 6);
    			PChar.quest.smuggler_line_second_mission_uncapture_Marigot.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 6);
			PChar.quest.smuggler_line_second_mission_uncapture_Marigot.win_condition.l1.date.year = GetAddingDataYear(0, 0, 6);
			PChar.quest.smuggler_line_second_mission_uncapture_Marigot.win_condition = "smuggler_line_second_mission_uncapture_Marigot";
		break;

		case "second_mission_exit_from_cam_without_danielle":
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("she", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
			Preprocessor_AddQuestData("her", XI_ConvertString(GetMyPronounPossessive(CharacterFromID("Danielle"))));
			AddQuestRecord("smuggler_line", 15);
			Preprocessor_Remove("her");
			Preprocessor_Remove("she");
			Preprocessor_Remove("Danielle");
			LAi_ActorRunToLocation(CharacterFromID("danielle"), "reload", "reload1", "none", "", "", "", 85.0);
			PChar.quest.smuggler_line = "second_mission_return_to_beltrop_after_prison";
			characters[getCharacterIndex("danielle")].dialog.currentnode = characters[getCharacterIndex("danielle")].dialog.smgnode;
			DeleteAttribute(CharacterFromID("danielle"), "dialog.smgnode");
		break;

		case "smuggler_line_second_mission_uncapture_Marigot":
			SetTownCapturedState("Marigot", false);
		break;

		case "second_mission_money_not_delivered_to_beltrop":
			AddQuestRecord("smuggler_line", 17);
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(PChar, "Sneak", 2500);
			else AddPartyExp(PChar, 2500);
			PChar.quest.smuggler_line.second_mission = "completed";
			RestoreDialog(CharacterFromID("Jean Maginot"));
			LAi_SetMerchantType(CharacterFromID("Jean Maginot"));
		break;

		case "second_mission_wait_two_days":
			AddQuestRecord("smuggler_line", 18);
			PChar.quest.second_mission_to_tavern_room.win_condition.l1 = "location";
			PChar.quest.second_mission_to_tavern_room.win_condition.l1.location = "Marigot_tavern_upstairs";
			PChar.quest.second_mission_to_tavern_room.win_condition = "second_mission_to_tavern_room";
			PChar.quest.smuggler_line = "second_mission_to_tavern_room_wait_for_killers";
		break;

		case "second_mission_to_tavern_room":
			LAi_QuestDelay("second_mission_to_tavern_room_wait_for_killers", 1.0);
		break;

		case "second_mission_to_tavern_room_wait_for_killers":
			Lai_setActorType(PChar);
			Lai_ActorGoToLocator(PChar, "goto", "goto4", "second_mission_meet_with_killers", 5.0);
		break;

		case "second_mission_meet_with_killers":
			LAi_SetActorType(PChar);
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "mask_2", "goto", "goto7");
			sld.id = "smuggler_line_killer_01";
			LAi_setActorType(sld);
			LAi_ActorFollow(sld, PChar, "", 2.0);
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "mask_3", "goto", "goto8");
			sld.id = "smuggler_line_killer_02";
			sld.dialog.filename = "quest_soldier_dialog.c";
			LAi_setActorType(sld);
			LAi_ActorDialog(sld, PChar, "", 3.0, 1.0);
			
			LAi_ActorWaitDialog(PChar, CharacterFromID("smuggler_line_killer_02"));
		break;

		case "second_mission_fight_with_killers":
			LAi_SetPlayerType(PChar);
			LAi_SetWarriorType(CharacterFromID("smuggler_line_killer_01"));
			LAi_SetWarriorType(CharacterFromID("smuggler_line_killer_02"));
			LAi_group_MoveCharacter(CharacterFromID("smuggler_line_killer_01"), "SMUGGLER_LINE_KILLERS");
			LAi_group_MoveCharacter(CharacterFromID("smuggler_line_killer_02"), "SMUGGLER_LINE_KILLERS");
			LAi_group_SetRelation("SMUGGLER_LINE_KILLERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SMUGGLER_LINE_KILLERS", LAI_GROUP_PLAYER, true);	
			AddQuestRecord("smuggler_line", 19);	
			
			PChar.quest.smuggler_line = "second_mission_after_fight_with_killers";
			Characters[GetCharacterIndex("Jean Maginot")].dialog.CurrentNode = "second_mission_after_fight_with_killers_return";
		break;

		case "second_mission_after_fight_with_killers_take_money":
			PChar.quest.smuggler_line = "second_mission_after_fight_with_killers_take_money";
			AddQuestRecord("smuggler_line", 23);
			AddMoneyToCharacter(PChar, 10000);
		break;

		case "second_mission_after_fight_with_killers_return_to_beltrop":
			AddQuestRecord("smuggler_line", 20);
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(PChar, "Sneak", 1500);
			else AddPartyExp(PChar, 1500);
			ChangeSmugglerLiking(PChar, 10);
			RestoreDialog(CharacterFromID("Jean Maginot"));
			LAi_SetMerchantType(CharacterFromID("Jean Maginot"));
		break;

		case "second_mission_truth_to_maginot":
			AddQuestRecord("smuggler_line", 21);
			PChar.quest.smuggler_line = "second_mission_truth_to_maginot";
		break;

		case "second_mission_truth_to_maginot_and_say_beltrop":
			AddQuestRecord("smuggler_line", 22);
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(PChar, "Sneak", 750);
			else AddPartyExp(PChar, 750);
			ChangeSmugglerLiking(PChar, 5);
			RestoreDialog(CharacterFromID("Jean Maginot"));
			LAi_SetMerchantType(CharacterFromID("Jean Maginot"));
		break;

		case "second_mission_after_fight_with_killers_return_money":
			AddMoneyToCharacter(PChar, -7000);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 2000);
				AddPartyExpChar(PChar, "Sneak", 2000);
			}
			else AddPartyExp(PChar, 4000);
			ChangeSmugglerLiking(PChar, 10);
			AddQuestRecord("smuggler_line", 16);
			PChar.quest.smuggler_line.second_mission = "completed";
			RestoreDialog(CharacterFromID("Jean Maginot"));
			LAi_SetMerchantType(CharacterFromID("Jean Maginot"));
		break;

		case "second_mission_reset_marigot":
			DisableFastTravel(false);
			Locations[FindLocation("Marigot_port")].locators_radius.goto.goto5 = 1;
			Locations[FindLocation("Marigot_port")].locators_radius.goto.goto4 = 1;
		break;

		case "third_mission_accept":
			AddQuestRecord("smuggler_line", 24);
			GiveShip2Character(CharacterFromID("Desmond Ray Beltrop"), "PO_Warship", TranslateString("","Fearless"), -1, PIRATE, true, true);
			PChar.quest.smuggler_line = "third_mission_accepted";
			PChar.quest.third_mission_to_douwesen_expired.win_condition.l1 = "timer";
			PChar.quest.third_mission_to_douwesen_expired.win_condition.l1.date.day = GetAddingDataDay(0, 0, 14);
    			PChar.quest.third_mission_to_douwesen_expired.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
			PChar.quest.third_mission_to_douwesen_expired.win_condition.l1.date.year = GetAddingDataYear(0, 0, 14);
			PChar.quest.third_mission_to_douwesen_expired.win_condition = "third_mission_to_douwesen_expired";
			
			PChar.quest.third_mission_to_douwesen_shore.win_condition.l1 = "location";
			PChar.quest.third_mission_to_douwesen_shore.win_condition.l1.location = "Douwesen_shore_02";
			PChar.quest.third_mission_to_douwesen_shore.win_condition = "third_mission_to_douwesen_shore";
			
			PChar.quest.third_mission_to_douwesen.win_condition.l1 = "location";
			PChar.quest.third_mission_to_douwesen.win_condition.l1.location = "Douwesen";
			PChar.quest.third_mission_to_douwesen.win_condition = "third_mission_to_douwesen";
			
			PChar.quest.beltrop_death.win_condition.l1 = "Npc_death";
			PChar.quest.beltrop_death.win_condition.l1.character = "Desmond Ray Beltrop";
			PChar.quest.beltrop_death.win_condition = "beltrop_death";
		break;

		case "beltrop_death":
			if (checkQuestAttribute("smuggler_line", "third_mission_accepted"))
			{
				AddQuestRecord("smuggler_line", 27);
				ChangeCharacterReputation (PChar, -10);
				ChangeSmugglerLiking(PChar, -40);
				if(CORPSEMODE < 2)
				{
					if (ENABLE_WEAPONSMOD) GiveItem2Character(PChar, "bladeC13+3");
					else GiveItem2Character(NPChar, "bladeC13");
					Log_SetStringToLog(TranslateString("","From the corpse of Desmond Ray Beltrop you took a blade with a mark on the blade - 'HURRICANE'."));
				}
			}
			if (checkQuestAttribute("smuggler_line", "third_mission_to_douwesen_expired_fire_fight") || checkQuestAttribute("smuggler_line", "fourth_mission_kill_jean_fire_fight"))
			{
				AddQuestRecord("smuggler_line", 29);
				ChangeCharacterReputation (PChar, -10);
				ChangeSmugglerLiking(PChar, -40);
				if (ENABLE_WEAPONSMOD) GiveItem2Character(PChar, "bladeC13+3");
				else GiveItem2Character(NPChar, "bladeC13");
				Log_SetStringToLog(TranslateString("","From the corpse of Desmond Ray Beltrop you took a blade with a mark on the blade - 'HURRICANE'."));
			}
			if (checkQuestAttribute("smuggler_line", "traitor"))
			{
				AddQuestRecord("smuggler_line", 61);
				ChangeCharacterReputation (PChar, -10);
				ChangeSmugglerLiking(PChar, -40);
				if (ENABLE_WEAPONSMOD) GiveItem2Character(PChar, "bladeC13+3");
				else GiveItem2Character(NPChar, "bladeC13");
				Log_SetStringToLog(TranslateString("","From the corpse of Desmond Ray Beltrop you took a blade with a mark on the blade - 'HURRICANE'."));
				
				Group_CreateGroup("Beltrop");
				Group_AddCharacter("Beltrop", "Desmond Ray Beltrop");
				Group_SetGroupCommander("Beltrop", "Desmond Ray Beltrop");
				Group_SetAddress("Beltrop", "Conceiaco", "Quest_Ships","Quest_Ship_7");
				SetCharacterRelationBoth(GetCharacterIndex("Desmond Ray Beltrop"),GetMainCharacterIndex(),RELATION_ENEMY);
				LAi_LocationFightDisable(&locations[FindLocation(PChar.location)], true);
			}
			if (checkQuestAttribute("smuggler_line", "traitor2"))
			{
				AddQuestRecord("smuggler_line", 62);
				ChangeCharacterReputation (PChar, -10);
				ChangeSmugglerLiking(PChar, -40);
				if (ENABLE_WEAPONSMOD) GiveItem2Character(PChar, "bladeC13+3");
				else GiveItem2Character(NPChar, "bladeC13");
				Log_SetStringToLog(TranslateString("","From the corpse of Desmond Ray Beltrop you took a blade with a mark on the blade - 'HURRICANE'."));
				
				Group_CreateGroup("Beltrop");
				Group_AddCharacter("Beltrop", "Desmond Ray Beltrop");
				Group_SetGroupCommander("Beltrop", "Desmond Ray Beltrop");
				Group_SetAddress("Beltrop", "Conceiaco", "Quest_Ships","Quest_Ship_7");
				SetCharacterRelationBoth(GetCharacterIndex("Desmond Ray Beltrop"),GetMainCharacterIndex(),RELATION_ENEMY);
				LAi_LocationFightDisable(&locations[FindLocation(PChar.location)], true);
			}
			
			if (checkQuestAttribute("smuggler_line", "traitor3"))
			{
				AddQuestRecord("smuggler_line", 62);
				ChangeCharacterReputation (PChar, -10);
				ChangeSmugglerLiking(PChar, -40);
				if (ENABLE_WEAPONSMOD) GiveItem2Character(PChar, "bladeC13+3");
				else GiveItem2Character(NPChar, "bladeC13");
				Log_SetStringToLog(TranslateString("","From the corpse of Desmond Ray Beltrop you took a blade with a mark on the blade - 'HURRICANE'."));
				
				Group_CreateGroup("Beltrop");
				Group_AddCharacter("Beltrop", "Desmond Ray Beltrop");
				Group_SetGroupCommander("Beltrop", "Desmond Ray Beltrop");
				Group_SetAddress("Beltrop", "Douwesen", "Quest_Ships","Quest_Ship_7");
				SetCharacterRelationBoth(GetCharacterIndex("Desmond Ray Beltrop"),GetMainCharacterIndex(),RELATION_ENEMY);
				LAi_ActorDialog(CharacterFromID(PChar.quest.smuggler_line.QCGov), PChar, "", 2.0, 1.0);
				PChar.quest.pirate_line = "accepted";
			}
			
			PChar.quest.smuggler_line = "failed";
			CloseQuestHeader("smuggler_line");
		break;

		case "third_mission_to_douwesen":
			NPChar = CharacterFromID("Desmond Ray Beltrop");
			NPChar.skipRM = true;					// Beltrop flies a Portuguese flag but Portugal isn't upset if you kill the smuggler boss
			NPChar.nosurrender = 2;					// Beltrop will not become your officer!
			NPChar.quest.officertype = OFFIC_TYPE_CAPMERCHANT;
			NPChar.Ship.crew.morale = 65;
			NPChar.fantomtype = "trade";				// No naval flag, no military boarders
			if (ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(NPChar, "bladeC13+3");	// 'Hurricane' sword
				EquiPCharacterByItem(NPChar, "bladeC13+3");
			}
			else
			{
				GiveItem2Character(NPChar, "bladeC13");
				EquiPCharacterByItem(NPChar, "bladeC13");
			}

			Group_CreateGroup("Beltrop");
			Group_AddCharacter("Beltrop", "Desmond Ray Beltrop");
			Group_SetGroupCommander("Beltrop", "Desmond Ray Beltrop");
			Group_SetAddress("Beltrop", "Douwesen", "Quest_Ships","Quest_Ship_7");
			SetCharacterRelationBoth(GetCharacterIndex("Desmond Ray Beltrop"),GetMainCharacterIndex(),RELATION_FRIEND);
		break;

		case "third_mission_to_douwesen_expired":
			AddQuestRecord("smuggler_line", 25);
			PChar.quest.smuggler_line = "third_mission_to_douwesen_expired";
			PChar.quest.third_mission_to_douwesen_shore.over = "yes";
		break;

		case "third_mission_to_douwesen_expired_fire_without_fight":
			AddQuestRecord("smuggler_line", 28);
			PChar.quest.smuggler_line = "failed";
			CloseQuestHeader("smuggler_line");
		break;

		case "third_mission_to_douwesen_expired_fire_fight":
			PChar.quest.smuggler_line = "third_mission_to_douwesen_expired_fire_fight";
			LAi_SetWarriorType(CharacterFromID("Desmond Ray Beltrop"));
			LAi_group_MoveCharacter(CharacterFromID("Desmond Ray Beltrop"), "SMUGGLERS_SOLDIERS");
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "third_mission_to_douwesen_shore":
			LAi_LockFightMode(PChar, true);
			PChar.quest.smuggler_line = "third_mission_to_douwesen_shore";
			PChar.quest.third_mission_to_douwesen_expired.over = "yes";
			Locations[FindLocation("Douwesen_shore_02")].reload.l2.disable = 1;
			ChangeCharacterAddress(CharacterFromID("Desmond Ray Beltrop"), "Douwesen_shore_02", "goto7");
			ChangeCharacterAddress(CharacterFromID(PChar.quest.smuggler_line.QCGov), "Douwesen_shore_02", "goto5");
			LAi_SetActorType(CharacterFromID("Desmond Ray Beltrop"));
			LAi_ActorDialog(CharacterFromID("Desmond Ray Beltrop"), PChar, "", 4.0, 1.0);
		break;

		case "third_mission_speak_with_pirate_head":		// triggered by dialog with Desmond Ray Beltrop
			characters[GetCharacterIndex(PChar.quest.smuggler_line.QCGov)].dialog.smgnode = characters[GetCharacterIndex(PChar.quest.smuggler_line.QCGov)].dialog.currentnode;
			characters[GetCharacterIndex(PChar.quest.smuggler_line.QCGov)].dialog.currentnode = "third time two";
			PChar.quest.smuggler_line = "third_mission_speak_with_pirate_head";
			LAi_ActorFollow(CharacterFromID("Desmond Ray Beltrop"), CharacterFromID(PChar.quest.smuggler_line.QCGov), "", 10.0);
			LAi_SetActorType(CharacterFromID(PChar.quest.smuggler_line.QCGov));
			LAi_ActorDialog(CharacterFromID(PChar.quest.smuggler_line.QCGov), PChar, "", 10.0, 1.0);
		break;

		case "third_mission_pirate_head_exit_from_shore":	// triggered by dialog with pirate boss
			PChar.quest.smuggler_line = "third_mission_pirate_head_exit_from_shore";
			LAi_SetActorType(PChar);			// Nail player in place until pirate boss has left
			LAi_ActorTurnToLocator(PChar, "reload", "reload2_back");
			LAi_SetActorType(CharacterFromID(PChar.quest.smuggler_line.QCGov));
			LAi_ActorRunToLocation(CharacterFromID(PChar.quest.smuggler_line.QCGov), "reload", "reload2_back", "QC_residence", "goto", "goto1", "third_mission_pirate_head_exit_from_shore_enter_to_residence", 25.0);
			LAi_type_actor_Reset(CharacterFromID("Desmond Ray Beltrop"));
			LAi_ActorDialog(CharacterFromID("Desmond Ray Beltrop"), PChar, "", 1.0, 1.0);
			Locations[FindLocation("Douwesen_shore_02")].reload.l2.disable = 0;
		break;

		case "third_mission_pirate_head_exit_from_shore_enter_to_residence":
			LAi_SetPlayerType(PChar);
			LAi_SetStayType(CharacterFromID(PChar.quest.smuggler_line.QCGov));
			characters[GetCharacterIndex(PChar.quest.smuggler_line.QCGov)].dialog.currentnode = characters[GetCharacterIndex(PChar.quest.smuggler_line.QCGov)].dialog.smgnode;
			DeleteAttribute(CharacterFromID(PChar.quest.smuggler_line.QCGov), "dialog.smgnode");
		break;

		case "third_mission_award":
			PChar.quest.smuggler_line.third_mission = "completed";
			if(AUTO_SKILL_SYSTEM)AddPartyExpChar(PChar, "Leadership", 1500);
			else AddPartyExp(PChar, 1500);
			AddMoneyToCharacter(PChar, 3000);
			AddQuestRecord("smuggler_line", 30);
		break;

		case "fourth_mission_acepted":
			PChar.quest.smuggler_line = "fourth_mission_acepted";
			AddQuestRecord("smuggler_line", 31);
			PChar.quest.fourth_mission_to_Marigot.win_condition.l1 = "Location";
			PChar.quest.fourth_mission_to_Marigot.win_condition.l1.location = "Marigot_port";
			PChar.quest.fourth_mission_to_Marigot.win_condition = "fourth_mission_to_Marigot";
			characters[GetCharacterIndex("Desmond Ray Beltrop")].location = "Smugglers_Residence";
			characters[GetCharacterIndex("Desmond Ray Beltrop")].location.group = "goto";
			characters[GetCharacterIndex("Desmond Ray Beltrop")].location.locator = "goto1";
			Group_SetAddress("Beltrop", "none", "Quest_Ships","Quest_Ship_7");
			LAi_SetStayType(CharacterFromID("Desmond Ray Beltrop"));
			NPChar = characterfromID("Jean Maginot");
			StoreDialog(NPChar);
			NPChar.Dialog.Filename = "France Trader_dialog.c";
			NPChar.dialog.CurrentNode = "second time";
		break;

		case "fourth_mission_to_Marigot":
			PChar.quest.smuggler_line = "fourth_mission_to_Marigot";
			characters[GetCharacterIndex("Susanne Maginot")].dialog.smgnode = characters[GetCharacterIndex("Susanne Maginot")].dialog.currentnode;
			characters[GetCharacterIndex("Susanne Maginot")].dialog.currentnode = "smuggler_line";
			PlaceCharacter(CharacterFromID("Susanne Maginot"), "goto");
			LAi_SetActorType(CharacterFromID("Susanne Maginot"));
			LAi_ActorDialog(CharacterFromID("Susanne Maginot"), PChar, "", 2.0, 1.0);
		break;

		case "fourth_mission_capture_susanne":
			PChar.quest.smuggler_line = "fourth_mission_capture_susanne";
			LAi_ActorRunToLocation(CharacterFromID("Susanne Maginot"), "reload", "werf", "none", "", "", "", 25.0);
			AddPassenger(PChar, CharacterFromID("Susanne Maginot"), 1);
			AddQuestRecord("smuggler_line", 32);
		break;

		case "fourth_mission_capture_susanne_wait_in_tavern":
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(PChar, "Sneak", 2000);
			else AddPartyExp(PChar, 2000);
			PChar.quest.smuggler_line = "fourth_mission_capture_susanne_wait_in_tavern";
			AddQuestRecord("smuggler_line", 33);
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 1;
			PChar.quest.fourth_mission_to_tavern.win_condition.l1 = "location";
			PChar.quest.fourth_mission_to_tavern.win_condition.l1.location = "Marigot_tavern_upstairs";
			PChar.quest.fourth_mission_to_tavern.win_condition = "fourth_mission_to_tavern";
		break;

		case "fourth_mission_to_tavern":
			LAi_QuestDelay("fourth_mission_to_tavern_wait_jean", 1.0);
		break;

		case "fourth_mission_to_tavern_wait_jean":
			Lai_setActorType(PChar);
			Lai_ActorGoToLocator(PChar, "goto", "goto4", "fourth_mission_meet_with_jean_in_tavern", 5.0);
		break;

		case "fourth_mission_meet_with_jean_in_tavern":
			LAi_RemoveLoginTime(CharacterFromID("Jean Maginot"));
			characters[GetCharacterIndex("Jean Maginot")].dialog.currentnode = "resque_susanne";
			PChar.quest.smuggler_line = "fourth_mission_meet_with_jean_in_tavern";
			ChangeCharacterAddressGroup(CharacterFromID("Jean Maginot"), "Marigot_tavern_upstairs", "reload", "reload1");
			LAi_SetActorType(CharacterFromID("Jean Maginot"));
			LAi_ActorWaitDialog(PChar, CharacterFromID("Jean Maginot"));
			LAi_ActorDialog(CharacterFromID("Jean Maginot"), PChar, "", 3.0, 1.0);
		break;

		case "fourth_mission_meet_with_jean_in_tavern_good":
			LAi_ActorRunToLocation(CharacterFromID("Jean Maginot"), "reload", "reload1", "none", "", "", "", 25.0);
			RemovePassenger(PChar, CharacterFromID("Susanne Maginot"));
			GiveItem2Character(PChar, "shop_papers");
			PChar.quest.smuggler_line = "fourth_mission_meet_with_jean_in_tavern_good";
			AddQuestRecord("smuggler_line", 34);
			LAi_setPlayerType(PChar);
		break;

		case "fourth_mission_meet_with_jean_in_tavern_bad":
			LAi_ActorRunToLocation(CharacterFromID("Jean Maginot"), "reload", "reload1", "none", "", "", "", 25.0);
			GiveItem2Character(PChar, "shop_papers");
			PChar.quest.smuggler_line = "fourth_mission_meet_with_jean_in_tavern_good";
			AddQuestRecord("smuggler_line", 36);
			LAi_setPlayerType(PChar);
			PChar.quest.fourth_mission_soldiers.win_condition.l1 = "location";
			PChar.quest.fourth_mission_soldiers.win_condition.l1.location = "Marigot_Town_02";
			PChar.quest.fourth_mission_soldiers.win_condition = "fourth_mission_soldiers";
		break;

		case "fourth_mission_soldiers":
			AddQuestRecord("smuggler_line", 37);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
			DisableFastTravel(false);
		break;

		case "fourth_mission_fight":
			DisableFastTravel(true);
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], false);
			LAi_SetHp(CharacterFromID("Jean Maginot"), 1.0, 1.0);
			LAi_SetActorType(PChar);
			LAi_ActorAttack(PChar, CharacterFromID("Jean Maginot"), "fourth_mission_kill_jean");
		break;

		case "fourth_mission_kill_jean":
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], true);
			AddQuestRecord("smuggler_line", 38);
			LAi_SetPlayerType(PChar);
			LAi_group_MoveCharacter(CharacterFromID("MarigotPatrol1"), "FRANCE_SOLDIERS");
			LAi_group_MoveCharacter(CharacterFromID("MarigotPatrol2"), "FRANCE_SOLDIERS");
			PChar.quest.fourth_mission_soldiers.win_condition.l1 = "location";
			PChar.quest.fourth_mission_soldiers.win_condition.l1.location = "Marigot_Port";
			PChar.quest.fourth_mission_soldiers.win_condition = "fourth_mission_soldiers";
			PChar.quest.smuggler_line = "fourth_mission_kill_jean";
		break;

		case "fourth_mission_completed":
			PChar.quest.smuggler_line.fourth_mission = "completed";
			AddQuestRecord("smuggler_line", 35);
			TakeItemFromCharacter(PChar, "shop_papers");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 5000);
				AddPartyExpChar(PChar, "Sneak", 1000);
			}
			else AddPartyExp(PChar, 6000);
			AddMoneyToCharacter(PChar, 8000);
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 0;
			NPChar = CharacterFromID("Jean Maginot");
			SetModelFromID(NPChar, "pirat2");
			NPChar.name = TranslateString("Toothless", "Pew");
			NPChar.lastname = "";
			NPChar.location = "Marigot_store";
			NPChar.location.group = "sit";
			NPChar.location.locator = "sit1";
			LAi_SetMerchantType(NPChar);
			RestoreDialog(NPChar);
		break;

		case "fourth_mission_kill_jean_fire_fight":
			PChar.quest.smuggler_line = "fourth_mission_kill_jean_fire_fight";
			LAi_SetWarriorType(CharacterFromID("Desmond Ray Beltrop"));
			LAi_group_MoveCharacter(CharacterFromID("Desmond Ray Beltrop"), "SMUGGLERS_SOLDIERS");
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, true);
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 0;
			NPChar = CharacterFromID("Jean Maginot");
			SetModelFromID(NPChar, "pirat2");
			NPChar.name = TranslateString("Toothless", "Pew");
			NPChar.lastname = "";
			NPChar.location = "Marigot_store";
			NPChar.location.group = "sit";
			NPChar.location.locator = "sit1";
			LAi_SetMerchantType(NPChar);
			RestoreDialog(NPChar);
		break;

		case "fourth_mission_kill_jean_fire_without_fight":
			AddQuestRecord("smuggler_line", 28);
			PChar.quest.smuggler_line = "failed";
			CloseQuestHeader("smuggler_line");
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 0;
			NPChar = CharacterFromID("Jean Maginot");
			SetModelFromID(NPChar, "pirat2");
			NPChar.name = TranslateString("Toothless", "Pew");
			NPChar.lastname = "";
			NPChar.location = "Marigot_store";
			NPChar.location.group = "sit";
			NPChar.location.locator = "sit1";
			LAi_SetMerchantType(NPChar);
			RestoreDialog(NPChar);
		break;

		case "fourth_mission_failed":
			AddQuestRecord("smuggler_line", 39);
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(PChar, "Sneak", 3000);
			else AddPartyExp(PChar, 3000);
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 0;
		//	characters[GetCharacterIndex("Jean Maginot")].model = "pirate2";
		//	characters[GetCharacterIndex("Jean Maginot")].headModel = "h_pirate2";
			NPChar = CharacterFromID("Jean Maginot");
			SetModelFromID(NPChar, "pirat2");
			NPChar.name = TranslateString("Toothless", "Pew");
			NPChar.lastname = "";
			NPChar.location = "Marigot_store";
			NPChar.location.group = "sit";
			NPChar.location.locator = "sit1";
			LAi_SetMerchantType(NPChar);
			LAi_CharacterEnableDialog(NPChar);
			RestoreDialog(NPChar);
			LAi_CharacterEnableDialog(CharacterFromID("MarigotPatrol7"));
			RestoreDialog(CharacterFromID("MarigotPatrol7"));
			ChangeCharacterAddressGroup(CharacterFromID("MarigotPatrol7"), "Marigot_Town_01", "goto", "goto1");
			LAi_SetPatrolType(CharacterFromID("MarigotPatrol7"));
		break;

		case "fourth_mission_to_jean":
			PChar.quest.smuggler_line = "fourth_mission_to_jean";
		break;

		case "fourth_mission_ring":
			PChar.quest.smuggler_line = "fourth_mission_ring";
			AddQuestRecord("smuggler_line", 41);
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(PChar, "Sneak", 1000);
			else AddpartyExp(PChar, 1000);
			NPChar = CharacterFromID("MarigotPatrol7");
			LAi_type_actor_Reset(CharacterFromID("MarigotPatrol7"));
		//	PlaceCharacter(CharacterFromID("MarigotPatrol7"), "goto");
			StoreDialog(NPChar);
			NPChar.Dialog.Filename = "quest_soldier_dialog.c";
			NPChar.dialog.currentnode = "fourth_mission";
		break;	

		case "fourth_mission_ring_france_was_enemy":
			PChar.quest.smuggler_line = "fourth_mission_ring_france_was_enemy";
			AddQuestRecord("smuggler_line", 42);
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "fourth_mission_with_officer_to_shop_wrong":
			AddQuestRecord("smuggler_line", 43);
			PChar.quest.smuggler_line = "fourth_mission_with_officer_to_shop_wrong";
			LAi_SetActorType(CharacterFromID("MarigotPatrol7"));
			LAi_ActorRunToLocation(CharacterFromID("MarigotPatrol7"), "reload", "reload_3_3_back", "none", "", "", "", 95.0);
			PChar.quest.fourth_mission_with_officer_to_shop_complete.win_condition.l1 = "location";
			PChar.quest.fourth_mission_with_officer_to_shop_complete.win_condition.l1.location = "Marigot_store";
			PChar.quest.fourth_mission_with_officer_to_shop_complete.win_condition = "fourth_mission_with_officer_to_shop_complete";
		break;

		case "fourth_mission_with_officer_to_shop_right":
			AddQuestRecord("smuggler_line", 44);
			PChar.quest.smuggler_line = "fourth_mission_with_officer_to_shop_right";
			LAi_SetActorType(CharacterFromID("MarigotPatrol7"));
			LAi_ActorRunToLocation(CharacterFromID("MarigotPatrol7"), "reload", "reload_3_3_back", "none", "", "", "", 95.0);
			PChar.quest.fourth_mission_with_officer_to_shop_complete.win_condition.l1 = "location";
			PChar.quest.fourth_mission_with_officer_to_shop_complete.win_condition.l1.location = "Marigot_store";
			PChar.quest.fourth_mission_with_officer_to_shop_complete.win_condition = "fourth_mission_with_officer_to_shop_complete";
		break;

		case "fourth_mission_with_officer_to_shop_complete":
			NPChar = CharacterFromID("MarigotPatrol7");
			LAi_type_actor_Reset(CharacterFromID("MarigotPatrol7"));
			PlaceCharacter(CharacterFromID("MarigotPatrol7"), "goto");
			NPChar.Dialog.Filename = "quest_soldier_dialog.c";
			NPChar.dialog.currentnode = "fourth_mission";
			Lai_ActorDialog(CharacterFromID("MarigotPatrol7"), PChar, "", 2.0, 1.0);
		break;

		case "fourth_mission_jean_to_soldier1":
			Characters[GetCharacterIndex("Jean Maginot")].dialog.currentnode = "smuggler_line_fourth_mission_jean_first_talk_with_soldiers";
			LAi_SetActorType(CharacterFromID("Jean Maginot"));
			LAi_ActorDialogNow(CharacterFromID("Jean Maginot"), PChar, "", -1.0);
		break;

		case "fourth_mission_soldier_to_player":
			NPChar = CharacterFromID("MarigotPatrol7");
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_with_officer_to_shop_wrong"))
			{
				NPChar.dialog.currentnode = "fourth_mission_with_officer_to_shop_wrong";
			}
			else
			{
				NPChar.dialog.currentnode = "fourth_mission_with_officer_to_shop_right";
			}
			LAi_SetActorType(NPChar);
			LAi_ActorDialogNow(NPChar, PChar, "", -1.0);
		break;

		case "fourth_mission_after_shop_wrong":
			AddQuestRecord("smuggler_line", 45);
			PChar.quest.smuggler_line = "fourth_mission_with_officer_to_shop_wrong";
			Locations[FindLocation("Marigot_port")].reload.l6.disable = 1;
			LAi_CharacterDisableDialog(CharacterFromID("Jean Maginot"));
			LAi_CharacterDisableDialog(CharacterFromID("MarigotPatrol7"));
		break;

		case "fourth_mission_officer_exit_from_shop":
			AddQuestRecord("smuggler_line", 46);
			LAi_SetMerchantType(CharacterFromID("Jean Maginot"));
			PChar.quest.smuggler_line = "fourth_mission_officer_exit_from_shop";
			PChar.quest.fourth_mission_officer_reset.win_condition.l1 = "ExitFromLocation";
			PChar.quest.fourth_mission_officer_reset.win_condition.l1.location = "Marigot_store";
			PChar.quest.fourth_mission_officer_reset.win_condition = "fourth_mission_officer_reset";
		break;

		case "fourth_mission_officer_reset":
			RestoreDialog(CharacterFromID("MarigotPatrol7"));
			ChangeCharacterAddressGroup(CharacterFromID("MarigotPatrol7"), "Marigot_Town_01", "goto", "goto1");
			LAi_SetPatrolType(CharacterFromID("MarigotPatrol7"));
		break;

		case "fourth_mission_ring_completed":
			LAi_SetPatrolType(CharacterFromID("MarigotPatrol7"));
			RestoreDialog(CharacterFromID("MarigotPatrol7"));
			AddQuestRecord("smuggler_line", 47);
			PChar.quest.smuggler_line = "fourth_mission_ring_completed";
			GiveItem2Character(PChar, "shop_papers");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 1000);
				AddPartyExpChar(PChar, "Sneak", 1000);
			}
			else AddPartyExp(PChar, 2000);
		break;

		case "fourth_mission_return_to_beltrop":
			PChar.quest.smuggler_line = "fourth_mission_return_to_beltrop";
			AddQuestRecord("smuggler_line", 40);
		break;

		case "fifth_mission_meet_with_barrakuda":
			PChar.quest.smuggler_line = "fifth_mission_meet_with_barrakuda";
			ChangeCharacterAddressGroup(CharacterFromID("barrakuda"), PChar.location, "reload", "reload1");
			LAi_SetActorType(CharacterFromID("barrakuda"));
			LAi_ActorDialog(CharacterFromID("barrakuda"), PChar, "", 3.0, 1.0);
		break;

		case "fifth_mission_meet_with_barrakuda_2":
			LAi_SetActorType(CharacterFromID("Desmond Ray Beltrop"));
			Characters[GetCharacterIndex("Desmond Ray Beltrop")].dialog.currentnode = "fifth_mission_meet_with_barrakuda_2";
			LAi_ActorDialog(CharacterFromID("Desmond Ray Beltrop"), PChar, "", 3.0, 1.0);
		break;

		case "fifth_mission_wait_for_join_barrakuda":
			LAi_SetMerchantType(CharacterFromID("Desmond Ray Beltrop"));
			LAi_SetStayType(CharacterFromID("barrakuda"));
			PChar.quest.smuggler_line = "fifth_mission_wait_for_join_barrakuda";
			AddQuestRecord("smuggler_line", 48);
		break;

		case "fifth_mission_accept":
			LAi_SetMerchantType(CharacterFromID("Desmond Ray Beltrop"));
			PChar.quest.smuggler_line = "fifth_mission_accepted";
			AddQuestRecord("smuggler_line", 49);
			SetCharacterRemovable(CharacterFromID("Barrakuda"), false);
			PChar.quest.barrakuda_died.win_condition.l1 = "NPC_Death";
			PChar.quest.barrakuda_died.win_condition.l1.character = "Barrakuda";
			PChar.quest.barrakuda_died.win_condition = "barrakuda_died";
			LAi_SetStayType(CharacterFromID("barrakuda"));
			characters[GetCharacterIndex("barrakuda")].location = "none"
		break;

		case "fifth_mission_accept_second":
			PChar.quest.smuggler_line = "fifth_mission_accepted";
			AddQuestRecord("smuggler_line", 50);
			SetCharacterRemovable(CharacterFromID("Virgile Boon"), false);
			PChar.quest.barrakuda_died.win_condition.l1 = "NPC_Death";
			PChar.quest.barrakuda_died.win_condition.l1.character = "Barrakuda";
			PChar.quest.barrakuda_died.win_condition = "barrakuda_died";
		break;

		case "fifth_mission_know_about_betrayer":
			PChar.quest.smuggler_line = "fifth_mission_know_about_betrayer";
			AddQuestRecord("smuggler_line", 51);
			//делаем отвлетвление с тем, что мы узнаем палы барракуды
		break;

		case "fifth_mission_prepare_for_trap":
			PChar.quest.smuggler_line = "fifth_mission_prepare_fro_trap";
			AddQuestRecord("smuggler_line", 53);
			PChar.quest.fifth_mission_trap_charged.win_condition.l1 = "Timer";
			PChar.quest.fifth_mission_trap_charged.win_condition.l1.date.day = GetAddingDataDay(0, 0, 7);
    			PChar.quest.fifth_mission_trap_charged.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 7);
			PChar.quest.fifth_mission_trap_charged.win_condition.l1.date.year = GetAddingDataYear(0, 0, 7);
			PChar.quest.fifth_mission_trap_charged.win_condition = "fifth_mission_trap_charged";			
		break;

		case "fifth_mission_trap_charged":
			//дизейблим проверку на узнавание лпанов Барракуда, делаем проверку на их знание - от этого изменятся диалоги
			PChar.quest.smuggler_line = "fifth_mission_trap_charged";
			AddQuestRecord("smuggler_line", 54);
		break;

		case "fifth_mission_move_fleet":
			PChar.quest.smuggler_line = "fifth_mission_move_fleet";
			AddQuestRecord("smuggler_line", 64);
		break;

		case "fifth_mission_trap":
			PChar.quest.smuggler_line = "fifth_mission_trap";
			AddQuestRecord("smuggler_line", 55);
			PChar.quest.fifth_mission_trap_begin.win_condition.l1 = "location";
			PChar.quest.fifth_mission_trap_begin.win_condition.l1.location = "Conceicao";
			PChar.quest.fifth_mission_trap_begin.win_condition = "fifth_mission_trap_begin";
		break;

		case "fifth_mission_trap_begin":
			PChar.quest.smuggler_line = "fifth_mission_trap_begin";
			
			Characters[GetCharacterIndex("Quest_Smuggler_Line_01")].nation = PERSONAL_NATION;
			Characters[GetCharacterIndex("Quest_Smuggler_Line_02")].nation = PERSONAL_NATION;
			Characters[GetCharacterIndex("Quest_Smuggler_Line_01")].flags.personal = 6;
			Characters[GetCharacterIndex("Quest_Smuggler_Line_01")].flags.personal.texture = 1;
			Characters[GetCharacterIndex("Quest_Smuggler_Line_02")].flags.personal = 6;
			Characters[GetCharacterIndex("Quest_Smuggler_Line_02")].flags.personal.texture = 1;
			Characters[GetCharacterIndex("Quest_Smuggler_Line_01")].Ship.crew.morale = 50 + rand(20);
			Characters[GetCharacterIndex("Quest_Smuggler_Line_02")].Ship.crew.morale = 50 + rand(20);
			Group_CreateGroup("Story_Smuggler_Squadron");
			Group_AddCharacter("Story_Smuggler_Squadron", "Quest_Smuggler_Line_01");
			Group_AddCharacter("Story_Smuggler_Squadron", "Quest_Smuggler_Line_02");
			Group_SetGroupCommander("Story_Smuggler_Squadron", "Quest_Smuggler_Line_01");
			SetCharacterRelationBoth(GetCharacterIndex("Quest_Smuggler_Line_01"),GetMainCharacterIndex(),RELATION_FRIEND);
			Group_SetAddress("Story_Smuggler_Squadron", "Conceicao", "Quest_Ships","Quest_Ship_1");
			Group_SetPursuitGroup("Story_Smuggler_Squadron", PLAYER_GROUP);

			SetNationRelationBoth(ENGLAND, PRIVATEER_NATION, RELATION_NEUTRAL);
			SetNationRelationBoth(FRANCE, PRIVATEER_NATION, RELATION_NEUTRAL);
			SetNationRelationBoth(SPAIN, PRIVATEER_NATION, RELATION_NEUTRAL);
			SetNationRelationBoth(PIRATE, PRIVATEER_NATION, RELATION_NEUTRAL);
			SetNationRelationBoth(HOLLAND, PRIVATEER_NATION, RELATION_NEUTRAL);
			SetNationRelationBoth(PORTUGAL, PRIVATEER_NATION, RELATION_NEUTRAL);
			SetNationRelationBoth(PERSONAL_NATION, PRIVATEER_NATION, RELATION_ENEMY);
			for(n=1; n<=4; n++)
			{
				NPChar = CharacterFromID("Smuggler_quest_pirate_0" + n);
				NPChar.recognized = true;
				NPChar.nation = PRIVATEER_NATION;
				NPChar.flags.personal = 1;
				NPChar.flags.personal.texture = 2;
				NPChar.Ship.crew.morale = 50 + rand(20);
				NPChar.nosurrender = 1;
			}
			Group_CreateGroup("Story_AntiSmuggler_Squadron");
			Group_AddCharacter("Story_AntiSmuggler_Squadron", "Smuggler_quest_pirate_01");
			Group_AddCharacter("Story_AntiSmuggler_Squadron", "Smuggler_quest_pirate_02");

			Group_AddCharacter("Story_AntiSmuggler_Squadron", "Smuggler_quest_pirate_03");	// Was "Story_AntiSmuggler_Squadron2",
			Group_AddCharacter("Story_AntiSmuggler_Squadron", "Smuggler_quest_pirate_04");	// why have two different squadrons?
			Group_SetGroupCommander("Story_AntiSmuggler_Squadron", "Smuggler_quest_pirate_01");
			SetCharacterRelationBoth(GetCharacterIndex("Smuggler_quest_pirate_01"),GetMainCharacterIndex(),RELATION_ENEMY);
		//	Group_SetGroupCommander("Story_AntiSmuggler_Squadron2", "Smuggler_quest_pirate_03");
		//	SetCharacterRelationBoth(GetCharacterIndex("Smuggler_quest_pirate_03"),GetMainCharacterIndex(),RELATION_ENEMY);

			PChar.quest.trap_completed.win_condition.l1 = "NPC_Death";
			PChar.quest.trap_completed.win_condition.l1.character = "Smuggler_quest_pirate_01";
			PChar.quest.trap_completed.win_condition.l2 = "NPC_Death";
			PChar.quest.trap_completed.win_condition.l2.character = "Smuggler_quest_pirate_02";
			PChar.quest.trap_completed.win_condition.l3 = "NPC_Death";
			PChar.quest.trap_completed.win_condition.l3.character = "Smuggler_quest_pirate_03";
			PChar.quest.trap_completed.win_condition.l4 = "NPC_Death";
			PChar.quest.trap_completed.win_condition.l4.character = "Smuggler_quest_pirate_04";
			//PChar.quest.trap_completed.win_condition.l5 = "NPC_Death";
			//PChar.quest.trap_completed.win_condition.l5.character = "Smuggler_quest_pirate_05";

			if (!CheckAttribute(CharacterFromID("Conceicao Commander"), "recognized")) Characters[GetCharacterIndex("Conceicao Commander")].smuggler_line_notrecognized = true;
			Characters[GetCharacterIndex("Conceicao Commander")].recognized = true;
		//	SetCharacterRelationBoth(GetCharacterIndex("Conceicao Commander"),GetMainCharacterIndex(),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Conceicao Commander"),GetCharacterIndex("Smuggler_quest_pirate_01"),RELATION_FRIEND);
		//	SetCharacterRelationBoth(GetCharacterIndex("Conceicao Commander"),GetCharacterIndex("Smuggler_quest_pirate_03"),RELATION_FRIEND);
			if (!CheckQuestAttribute("smuggler_barrakuda", "died"))
			{
				NPChar = CharacterFromID("Barrakuda");
				NPChar.recognized = true;
				NPChar.nation = PRIVATEER_NATION;
				NPChar.flags.personal = 1;
				NPChar.flags.personal.texture = 2;
				NPChar.Ship.crew.morale = 65;
				NPChar.nosurrender = 2;
				NPChar.SkipRM = true;
	
				RemoveCharacterCompanion(PChar, NPChar);
				AddQuestRecord("smuggler_line", 57);
				Log_SetStringToLog(TranslateString("", "Barracuda left you and took part in the battle on the enemy side."));
				
				//Group_CreateGroup("Barrakuda");
				Group_AddCharacter("Story_AntiSmuggler_Squadron", "Barrakuda");
				//Group_SetGroupCommander("Barrakuda", "Barrakuda");
				SetCharacterRelationBoth(GetCharacterIndex("Barrakuda"),GetMainCharacterIndex(),RELATION_ENEMY);
				//Group_SetAddress("Barrakuda", "Conceicao", "Quest_Ships","Quest_Ship_1");

				//Group_SetTaskAttack("Barrakuda", PLAYER_GROUP);
				//Group_LockTask("Barrakuda");
				PChar.quest.smuggler_barrakuda = "betrayer";
				PChar.quest.trap_completed.win_condition.l5 = "NPC_Death";
				PChar.quest.trap_completed.win_condition.l5.character = "Barrakuda";
				SetCharacterRelationBoth(GetCharacterIndex("Conceicao Commander"),GetCharacterIndex("Barrakuda"),RELATION_FRIEND);
			}
			
			Group_SetAddress("Story_AntiSmuggler_Squadron", "Conceicao", "Quest_Ships","Quest_Ship_1");
			Group_SetTaskAttack("Story_AntiSmuggler_Squadron", PLAYER_GROUP, true);
			Group_LockTask("Story_AntiSmuggler_Squadron");
			
		//	Group_SetAddress("Story_AntiSmuggler_Squadron2", "Conceicao", "Quest_Ships","Quest_Ship_1");
			
			Group_SetTaskAttack("Story_AntiSmuggler_Squadron", "Story_Smuggler_Squadron", true);
			Group_LockTask("Story_AntiSmuggler_Squadron");
			
		//	Group_SetTaskAttack("Story_Smuggler_Squadron", "Story_AntiSmuggler_Squadron2", true);
		//	Group_LockTask("Story_Smuggler_Squadron");
			
			PChar.quest.trap_completed.win_condition = "trap_completed";
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal(PChar.location, false);
			SetNationRelation2MainCharacter(PORTUGAL, RELATION_ENEMY);
			
			AddQuestRecord("smuggler_line", 56);
		break;

		case "trap_completed":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal(PChar.location, true);
			Group_SetAddress("Story_Smuggler_Squadron", "none", "Quest_Ships","Quest_Ship_7");
			AddQuestRecord("smuggler_line", 59);
			PChar.quest.smuggler_line = "trap_completed";
		break;

		case "barrakuda_died":
			if (!checkQuestAttribute("smuggler_barrakuda", "betrayer"))
			{
				temp = "Salamander1";	// Copied from Barrakuda's definition in "Sidequest.c", change this if you change his ship
				if (PChar.ship.type == temp || characters[GetCompanionIndex(PChar, 1)] == temp || characters[GetCompanionIndex(PChar, 2)] == temp || characters[GetCompanionIndex(PChar, 3)] == temp)
				{
					PChar.quest.smuggler_barrakuda = "died_bad";
					AddQuestRecord("smuggler_line", 52);
				}
			}
			else
			{
				AddQuestRecord("smuggler_line", 58);
			}
		break;

		case "smuggler_line_completed":
			AddQuestRecord("smuggler_line", 60);
			CloseQuestHeader("smuggler_line");
			PChar.quest.smuggler_line = "completed";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 15000);
				AddPartyExpChar(PChar, "Sneak", 5000);
			}
			else AddPartyExp(PChar, 20000);
			AddMoneyToCharacter(PChar, 20000);
			ChangeSmugglerLiking(PChar, 40);

			if (CheckAttribute(CharacterFromID("Conceicao Commander"), "smuggler_line_notrecognized"))
			{
				DeleteAttribute(CharacterFromID("Conceicao Commander"), "recognized");
				DeleteAttribute(CharacterFromID("Conceicao Commander"), "smuggler_line_notrecognized");
			}
		break;

		case "smuggler_line_final_fight":
			LAi_LocationFightDisable(&locations[FindLocation(PChar.location)], false);
			LAi_SetWarriorType(CharacterFromID("Desmond Ray Beltrop"));
			LAi_group_MoveCharacter(CharacterFromID("Desmond Ray Beltrop"), "SMUGGLERS_SOLDIERS");
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, true);
			PChar.quest.smuggler_line = "traitor";
		break;

		case "smuggler_line_final_fight_2":
			LAi_LocationFightDisable(&locations[FindLocation(PChar.location)], false);
			LAi_SetWarriorType(CharacterFromID("Desmond Ray Beltrop"));
			LAi_group_MoveCharacter(CharacterFromID("Desmond Ray Beltrop"), "SMUGGLERS_SOLDIERS");
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, true);
			PChar.quest.smuggler_line = "traitor2";
		break;

		case "possible_pirate_line":
			LAi_SetWarriorType(CharacterFromID("Desmond Ray Beltrop"));
			LAi_group_MoveCharacter(CharacterFromID("Desmond Ray Beltrop"), "SMUGGLERS_SOLDIERS");
			LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, true);
			PChar.quest.smuggler_line = "traitor3";
			AddQuestRecord("smuggler_line", 63);
		break;
// "Night Craft" quest ><--

		PChar.questnotfound = true; // PB: Testing
	}
}
